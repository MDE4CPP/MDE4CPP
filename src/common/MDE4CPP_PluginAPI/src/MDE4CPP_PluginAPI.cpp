#define CROW_JSON_USE_MAP
#include "MDE4CPP_PluginAPI.hpp"

#include <cstdint>
#include <cstdlib>
#include <functional>
#include <mutex>
#include <set>
#include <vector>
#include <fstream>
#include <chrono>

#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"

#include "pluginFramework/MDE4CPPPlugin.hpp"
#include "pluginFramework/OperationInvokerPlugin.hpp"
#include "abstractDataTypes/Bag.hpp"

#include "ecore/EAnnotation.hpp"

// Windows headers (pulled in via crow/boost) define macros like IN / DELETE
// which break some generated UML enum names. Undef them before including UML headers.
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif
#ifdef INOUT
#undef INOUT
#endif
#ifdef RETURN
#undef RETURN
#endif
#ifdef DELETE
#undef DELETE
#endif

#include "uml/Package.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Class.hpp"
#include "uml/Enumeration.hpp"
#include "uml/EnumerationLiteral.hpp"
#include "uml/DataType.hpp"
#include "uml/Operation.hpp"
#include "uml/Property.hpp"
#include "uml/Parameter.hpp"

std::shared_ptr<GenericApi> GenericApi::eInstance(std::shared_ptr<PluginFramework> &pluginFramework) {
    static std::shared_ptr<GenericApi> instance(new GenericApi(pluginFramework));
    return instance;
}

GenericApi::GenericApi(std::shared_ptr<PluginFramework>& pluginFramework) {
    m_pluginFramework = pluginFramework;
	mapPlugins(); //makes an inital map of all plugins 
    crow::SimpleApp app;

    //Create function
    CROW_ROUTE(app, "/<string>/objects/<string>/<string>").methods(crow::HTTPMethod::Post)([this](const crow::request& request, const std::string& plugin_name, const std::string& className, const std::string& objectName){
		try
		{
			{
				std::lock_guard<std::mutex> lock(m_objectsMutex);
				if(m_objects.find(objectName) != m_objects.end()){
					return crow::response(400, "Object already exists!");
				}
			}
			const std::shared_ptr<MDE4CPPPlugin>& plugin = getPlugin(plugin_name);
			if(plugin == nullptr){
				return crow::response(404, "Plugin not found!");
			}

			auto body = crow::json::load(request.body);
			if(!body) {
				// Treat invalid/empty JSON as empty object
				body = crow::json::load("{}");
			}

			auto object = std::shared_ptr<ecore::EObject>(nullptr);
			try
			{
				object = readValue(body, className, plugin);
			}
			catch(...)
			{
				// Many plugins require fully-qualified names like "plugin::Class"
				if(className.find("::") == std::string::npos)
				{
					const std::string qualified = plugin->eNAME() + "::" + className;
					object = readValue(body, qualified, plugin);
				}
				else
				{
					throw;
				}
			}
			if(!object){
				return crow::response(400, "Failed to create object (unknown class?)");
			}
			{
				std::lock_guard<std::mutex> lock(m_objectsMutex);
				try {
					m_objects[objectName] = StoredObject{plugin_name, className, object, ""};
				} catch(const std::exception& e) {
					std::cerr << "ERROR: Failed to store object '" << objectName << "': " << e.what() << std::endl;
					std::cerr.flush();
					return crow::response(500, std::string("Failed to store object: ") + e.what());
				} catch(...) {
					std::cerr << "ERROR: Failed to store object '" << objectName << "': unknown error" << std::endl;
					std::cerr.flush();
					return crow::response(500, "Failed to store object: unknown error");
				}
			}
			try {
				return crow::response(201);
			} catch(const std::exception& e) {
				std::cerr << "ERROR: Failed to create response: " << e.what() << std::endl;
				std::cerr.flush();
				return crow::response(500, "Internal server error");
			} catch(...) {
				std::cerr << "ERROR: Failed to create response: unknown error" << std::endl;
				std::cerr.flush();
				return crow::response(500, "Internal server error");
			}
		}
		catch(const std::exception& e)
		{
			CROW_LOG_ERROR << "Create object failed: " << e.what();
			return crow::response(500, std::string("Create object failed: ") + e.what());
		}
		catch(...)
		{
			CROW_LOG_ERROR << "Create object failed: unknown error";
			return crow::response(500, "Create object failed: unknown error");
		}
    });

	// Get containment tree for a plugin - use /{plugin}/tree to avoid any route conflict with objects/...
	// Uses parent map (no Ecore eContainer/eContents) to avoid crashes.
	CROW_ROUTE(app, "/<string>/tree").methods(crow::HTTPMethod::Get)([this](const std::string& plugin_name){
		try {
			const std::shared_ptr<MDE4CPPPlugin>& plugin = getPlugin(plugin_name);
			if(plugin == nullptr){
				return crow::response(404, "Plugin not found!");
			}

			// Build name->{className,parentName} and parent->[children] under lock
			std::map<std::string, std::pair<std::string, std::string>> nameToInfo;
			std::map<std::string, std::vector<std::string>> parentToChildren;
			std::vector<std::string> rootNames;
			{
				std::lock_guard<std::mutex> lock(m_objectsMutex);
				std::set<std::string> pluginObjectNames;
				for(const auto& entry : m_objects){
					if(entry.second.pluginName != plugin_name) continue;
					const std::string& name = entry.first;
					const std::string& className = entry.second.className;
					const std::string& parentName = entry.second.parentName;
					pluginObjectNames.insert(name);
					nameToInfo[name] = {className, parentName};
				}
				for(const auto& entry : nameToInfo){
					const std::string& name = entry.first;
					const std::string& parentName = entry.second.second;
					if(parentName.empty() || pluginObjectNames.count(parentName) == 0){
						rootNames.push_back(name);
						if(rootNames.size() >= 1000) break;
					} else {
						parentToChildren[parentName].push_back(name);
					}
				}
			}

			// Build tree from name (no Ecore calls)
			std::set<std::string> visited;
			const size_t maxDepth = 100;
			size_t nodeCount = 0;
			std::function<crow::json::wvalue(const std::string&, size_t)> buildNode =
				[&](const std::string& objName, size_t depth) -> crow::json::wvalue {
				crow::json::wvalue node;
				if(depth >= maxDepth || nodeCount >= 10000) {
					node["name"] = objName;
					node["type"] = "unknown";
					return node;
				}
				if(visited.count(objName)) {
					node["name"] = objName;
					node["type"] = "cycle";
					return node;
				}
				visited.insert(objName);
				nodeCount++;

				auto it = nameToInfo.find(objName);
				if(it != nameToInfo.end()){
					node["name"] = objName;
					node["type"] = it->second.first;
				} else {
					node["name"] = objName;
					node["type"] = "unknown";
				}

				auto cit = parentToChildren.find(objName);
				if(cit != parentToChildren.end() && !cit->second.empty()){
					auto children = crow::json::wvalue::list();
					int idx = 0;
					for(const auto& cname : cit->second){
						if(idx >= 500) break;
						children[idx] = buildNode(cname, depth + 1);
						idx++;
					}
					node["children"] = std::move(children);
				}

				return node;
			};

			auto roots = crow::json::wvalue::list();
			int rootIdx = 0;
			for(const auto& rname : rootNames){
				try {
					roots[rootIdx] = buildNode(rname, 0);
					rootIdx++;
					if(rootIdx >= 1000) break;
				} catch(const std::exception& e) {
					CROW_LOG_WARNING << "Tree buildNode failed for root " << rname << ": " << e.what();
				} catch(...) {}
			}

			crow::json::wvalue result;
			result["roots"] = std::move(roots);
			return crow::response(200, result);
		} catch(const std::exception& e) {
			CROW_LOG_ERROR << "Tree handler exception: " << e.what();
			return crow::response(500, std::string("Tree error: ") + e.what());
		} catch(...) {
			CROW_LOG_ERROR << "Tree handler unknown exception";
			return crow::response(500, "Tree error: unknown");
		}
	});

    //Read function
    CROW_ROUTE(app, "/<string>/objects/<string>/<string>").methods(crow::HTTPMethod::Get)([this](const std::string& plugin_name, const std::string& className, const std::string& objectName){
        try {
            std::shared_ptr<ecore::EObject> objCopy;
            {
                std::lock_guard<std::mutex> lock(m_objectsMutex);
                auto it = m_objects.find(objectName);
                if(it == m_objects.end()){
                    return crow::response(404);
                }
                if(it->second.pluginName != plugin_name){
                    return crow::response(404);
                }
                if(!it->second.object){
                    return crow::response(404, "Object is null");
                }
                objCopy = it->second.object;
            }
            const std::shared_ptr<MDE4CPPPlugin>& plugin = getPlugin(plugin_name);
            if(plugin == nullptr){
                return crow::response(404, "Plugin not found!");
            }
            crow::json::wvalue result;
            try { result = writeValue(objCopy, plugin); } catch(const std::exception& e) {
                CROW_LOG_ERROR << "Get object serialization failed: " << e.what();
                // #region agent log
                { std::ofstream log("d:\\DEV\\test2\\MDE4CPP\\.cursor\\debug.log", std::ios::app); log << "{\"sessionId\":\"debug-session\",\"runId\":\"run1\",\"hypothesisId\":\"D\",\"location\":\"GET:writeValue_exception\",\"message\":\"Exception from writeValue\",\"data\":{\"error\":\"" << e.what() << "\"},\"timestamp\":" << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() << "}\n"; }
                // #endregion
                return crow::response(500, std::string("Serialization failed: ") + e.what());
            } catch(...) {
                // #region agent log
                { std::ofstream log("d:\\DEV\\test2\\MDE4CPP\\.cursor\\debug.log", std::ios::app); log << "{\"sessionId\":\"debug-session\",\"runId\":\"run1\",\"hypothesisId\":\"D\",\"location\":\"GET:writeValue_unknown\",\"message\":\"Unknown exception from writeValue\",\"timestamp\":" << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() << "}\n"; }
                // #endregion
                return crow::response(500, "Serialization failed: unknown error");
            }
            // Wrap response return in try-catch - Crow's JSON serialization might crash
            try {
                // #region agent log
                { std::ofstream log("d:\\DEV\\test2\\MDE4CPP\\.cursor\\debug.log", std::ios::app); log << "{\"sessionId\":\"debug-session\",\"runId\":\"run1\",\"hypothesisId\":\"E\",\"location\":\"GET:before_crow_response\",\"message\":\"Before Crow response creation\",\"timestamp\":" << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() << "}\n"; }
                // #endregion
                return crow::response(200, result);
            } catch(const std::exception& e) {
                CROW_LOG_ERROR << "Crow response serialization failed: " << e.what();
                std::cerr << "Crow response serialization failed: " << e.what() << std::endl;
                std::cerr.flush();
                return crow::response(500, std::string("Response serialization failed: ") + e.what());
            } catch(...) {
                CROW_LOG_ERROR << "Crow response serialization failed: unknown error";
                std::cerr << "Crow response serialization failed: unknown error" << std::endl;
                std::cerr.flush();
                return crow::response(500, "Response serialization failed: unknown error");
            }
        } catch(const std::exception& e) {
            CROW_LOG_ERROR << "Get object failed: " << e.what();
            return crow::response(500, std::string("Get object failed: ") + e.what());
        } catch(...) {
            CROW_LOG_ERROR << "Get object failed: unknown error";
            return crow::response(500, "Get object failed: unknown error");
        }
    });

	// List operations available on an object instance (generic for all plugins)
	// GET /{plugin}/objects/{class}/{objectName}/operations
	CROW_ROUTE(app, "/<string>/objects/<string>/<string>/operations").methods(crow::HTTPMethod::Get)(
		[this](const std::string& plugin_name, const std::string& className, const std::string& objectName){
			std::shared_ptr<ecore::EObject> obj;
			{
				std::lock_guard<std::mutex> lock(m_objectsMutex);
				auto it = m_objects.find(objectName);
				if(it == m_objects.end() || it->second.pluginName != plugin_name){
					return crow::response(404);
				}
				obj = it->second.object;
			}
			if(!obj){
				return crow::response(404);
			}

			auto ops = crow::json::wvalue::list();
			try
			{
				// Prefer metamodel-declared operations for the classifier (matches what UI shows in classifier details).
				const std::shared_ptr<MDE4CPPPlugin>& plugin = getPlugin(plugin_name);
				const auto invoker = plugin ? std::dynamic_pointer_cast<OperationInvokerPlugin>(plugin) : nullptr;
				if(plugin)
				{
					if(const auto ecorePlugin = std::dynamic_pointer_cast<EcoreModelPlugin>(plugin))
					{
						const auto pkg = ecorePlugin->getEPackage();
						if(pkg)
						{
							std::shared_ptr<ecore::EClass> meta = nullptr;
							const auto eClassifiers = pkg->getEClassifiers();
							if(eClassifiers)
							{
								for(auto cit = eClassifiers->cbegin(); cit != eClassifiers->cend(); ++cit)
								{
									const auto c = *cit;
									if(!c) continue;
									if(c->getName() != className) continue;
									meta = std::dynamic_pointer_cast<ecore::EClass>(c);
									break;
								}
							}
							if(meta)
							{
								const auto opList = meta->getEOperations();
								if(opList)
								{
									for(auto oit = opList->cbegin(); oit != opList->cend(); ++oit)
									{
										const auto op = *oit;
										if(!op) continue;
										crow::json::wvalue oitem;
										oitem["name"] = op->getName();
										const auto rt = op->getEType();
										oitem["returnType"] = rt ? rt->getName() : "";

										auto params = crow::json::wvalue::list();
										const auto ps = op->getEParameters();
										if(ps)
										{
											for(auto pit = ps->cbegin(); pit != ps->cend(); ++pit)
											{
												const auto p = *pit;
												if(!p) continue;
												crow::json::wvalue pitem;
												pitem["name"] = p->getName();
												pitem["lower"] = p->getLowerBound();
												pitem["upper"] = p->getUpperBound();
												const auto pt = p->getEType();
												pitem["type"] = pt ? pt->getName() : "";
												params.push_back(std::move(pitem));
											}
										}
										oitem["parameters"] = crow::json::wvalue(std::move(params));
										bool invokable = invoker ? invoker->canInvoke(obj, op->getName()) : false;
										if(!invokable)
										{
											try
											{
												const auto ann = op->getEAnnotation("http://tu-ilmenau.de/see/codegen");
												const auto details = ann ? ann->getDetails() : nullptr;
												if(details && details->find("doNotGenerate") == details->end())
												{
													const auto itBody = details->find("body");
													if(itBody != details->end() && !itBody->second.empty()) invokable = true;
												}
											}
											catch(...)
											{
												// ignore
											}
										}
										oitem["invokable"] = invokable;
										oitem["invocationVia"] = invoker ? "native_plugin" : (invokable ? "ecore_codegen" : "none");
										ops.push_back(std::move(oitem));
									}
									crow::json::wvalue result = crow::json::wvalue(ops);
									return crow::response(200, result);
								}
							}
						}
					}
					else if(const auto umlPlugin = std::dynamic_pointer_cast<UMLModelPlugin>(plugin))
					{
						const auto rootPkg = umlPlugin->getPackage();
						if(rootPkg)
						{
							std::shared_ptr<uml::NamedElement> found;
							std::function<void(const std::shared_ptr<uml::Namespace>&)> findInNamespace;
							findInNamespace = [&](const std::shared_ptr<uml::Namespace>& ns){
								if(found || !ns) return;
								const auto owned = ns->getOwnedMember();
								if(!owned) return;
								for(auto it2 = owned->cbegin(); it2 != owned->cend(); ++it2)
								{
									const auto member = *it2;
									if(!member) continue;
									if(member->getName() == className){ found = member; return; }
									if(const auto pkg2 = std::dynamic_pointer_cast<uml::Package>(member))
									{
										findInNamespace(pkg2);
										if(found) return;
									}
								}
							};
							findInNamespace(rootPkg);

							if(const auto cls2 = std::dynamic_pointer_cast<uml::Class>(found))
							{
								auto outOps = crow::json::wvalue::list();
								const auto ownedOps = cls2->getOwnedOperation();
								if(ownedOps)
								{
									for(auto oit = ownedOps->cbegin(); oit != ownedOps->cend(); ++oit)
									{
										const auto op = *oit;
										if(!op) continue;
										crow::json::wvalue oitem;
										oitem["name"] = op->getName();
										const auto ret = op->returnResult();
										oitem["returnType"] = (ret && ret->getType()) ? ret->getType()->getName() : "";

										auto params = crow::json::wvalue::list();
										const auto ps = op->getProperty_OwnedParameter();
										if(ps)
										{
											for(auto pit = ps->cbegin(); pit != ps->cend(); ++pit)
											{
												const auto p = *pit;
												if(!p) continue;
												crow::json::wvalue pitem;
												pitem["name"] = p->getName();
												pitem["lower"] = p->getLower();
												pitem["upper"] = p->getUpper();
												pitem["type"] = p->getType() ? p->getType()->getName() : "";
												params.push_back(std::move(pitem));
											}
										}
										oitem["parameters"] = crow::json::wvalue(std::move(params));
										const bool invokable = invoker ? invoker->canInvoke(obj, op->getName()) : false;
										oitem["invokable"] = invokable;
										oitem["invocationVia"] = invoker ? "native_plugin" : "none";
										outOps.push_back(std::move(oitem));
									}
								}
								crow::json::wvalue result = crow::json::wvalue(outOps);
								return crow::response(200, result);
							}
						}
					}
				}

				// Fallback: reflect on instance EClass
				const auto cls = obj->eClass();
				if(cls)
				{
					// Prefer declared operations first (less noisy, and some plugins don't populate EAllOperations correctly).
					const auto directOps = cls->getEOperations();
					const auto allOps = cls->getEAllOperations();
					const auto opList = (directOps && directOps->size() > 0) ? directOps : allOps;

					if(opList)
					{
						for(auto oit = opList->cbegin(); oit != opList->cend(); ++oit)
						{
							const auto op = *oit;
							if(!op) continue;

							crow::json::wvalue oitem;
							oitem["name"] = op->getName();
							const auto rt = op->getEType();
							oitem["returnType"] = rt ? rt->getName() : "";

							auto params = crow::json::wvalue::list();
							const auto ps = op->getEParameters();
							if(ps)
							{
								for(auto pit = ps->cbegin(); pit != ps->cend(); ++pit)
								{
									const auto p = *pit;
									if(!p) continue;
									crow::json::wvalue pitem;
									pitem["name"] = p->getName();
									pitem["lower"] = p->getLowerBound();
									pitem["upper"] = p->getUpperBound();
									const auto pt = p->getEType();
									pitem["type"] = pt ? pt->getName() : "";
									params.push_back(std::move(pitem));
								}
							}
							oitem["parameters"] = crow::json::wvalue(std::move(params));
							bool invokable = invoker ? invoker->canInvoke(obj, op->getName()) : false;
							if(!invokable)
							{
								try
								{
									const auto ann = op->getEAnnotation("http://tu-ilmenau.de/see/codegen");
									const auto details = ann ? ann->getDetails() : nullptr;
									if(details && details->find("doNotGenerate") == details->end())
									{
										const auto itBody = details->find("body");
										if(itBody != details->end() && !itBody->second.empty()) invokable = true;
									}
								}
								catch(...)
								{
									// ignore
								}
							}
							oitem["invokable"] = invokable;
							oitem["invocationVia"] = invoker ? "native_plugin" : (invokable ? "ecore_codegen" : "none");
							ops.push_back(std::move(oitem));
						}
					}
				}
			}
			catch(...)
			{
				// If reflection fails, return empty list rather than crashing.
			}

			crow::json::wvalue result = crow::json::wvalue(ops);
			return crow::response(200, result);
		}
	);

	// Invoke operation on an object instance (generic for all plugins)
	// POST /{plugin}/objects/{class}/{objectName}/invoke/{operationName}
	// Body: { "arguments": [ ... ] }
	CROW_ROUTE(app, "/<string>/objects/<string>/<string>/invoke/<string>").methods(crow::HTTPMethod::Post)(
		[this](const crow::request& request, const std::string& plugin_name, const std::string& className, const std::string& objectName, const std::string& operationName){
			std::shared_ptr<ecore::EObject> obj;
			{
				std::lock_guard<std::mutex> lock(m_objectsMutex);
				auto it = m_objects.find(objectName);
				if(it == m_objects.end() || it->second.pluginName != plugin_name){
					return crow::response(404);
				}
				obj = it->second.object;
			}
			if(!obj){
				return crow::response(404);
			}

			const std::shared_ptr<MDE4CPPPlugin>& plugin = getPlugin(plugin_name);
			if(!plugin){
				return crow::response(404, "Plugin not found!");
			}

			const auto body = crow::json::load(request.body);
			auto argsJson = body ? body["arguments"] : crow::json::rvalue();

			std::shared_ptr<ecore::EOperation> targetOp = nullptr;
			try
			{
				// Prefer metamodel classifier operation (works across plugins and matches UI)
				if(const auto ecorePlugin = std::dynamic_pointer_cast<EcoreModelPlugin>(plugin))
				{
						const auto pkg = ecorePlugin->getEPackage();
						if(pkg)
						{
							std::shared_ptr<ecore::EClass> meta = nullptr;
							const auto eClassifiers = pkg->getEClassifiers();
							if(eClassifiers)
							{
								for(auto cit = eClassifiers->cbegin(); cit != eClassifiers->cend(); ++cit)
								{
									const auto c = *cit;
									if(!c) continue;
									if(c->getName() != className) continue;
									meta = std::dynamic_pointer_cast<ecore::EClass>(c);
									break;
								}
							}
							if(meta)
							{
								const auto opList = meta->getEOperations();
								if(opList)
								{
									for(auto oit = opList->cbegin(); oit != opList->cend(); ++oit)
									{
										const auto op = *oit;
										if(!op) continue;
										if(op->getName() != operationName) continue;

										if(body && argsJson.t() == crow::json::type::List)
										{
											const auto ps = op->getEParameters();
											const size_t pCount = ps ? static_cast<size_t>(ps->size()) : 0;
											const size_t aCount = static_cast<size_t>(argsJson.size());
											if(pCount == aCount) { targetOp = op; break; }
										}
										if(!targetOp) targetOp = op;
									}
								}
							}
						}
				}

				// Fallback: look on instance EClass
				if(!targetOp)
				{
					const auto cls = obj->eClass();
					if(cls)
					{
						const auto directOps = cls->getEOperations();
						const auto allOps = cls->getEAllOperations();
						const auto opList = (directOps && directOps->size() > 0) ? directOps : allOps;

						if(opList)
						{
							for(auto oit = opList->cbegin(); oit != opList->cend(); ++oit)
							{
								const auto op = *oit;
								if(!op) continue;
								if(op->getName() != operationName) continue;
								targetOp = op;
								break;
							}
						}
					}
				}
			}
			catch(...)
			{
				// ignored
			}

			if(!targetOp){
				// If this is a UML model plugin, we can list operations but cannot generically execute them via eInvoke.
				if(std::dynamic_pointer_cast<UMLModelPlugin>(plugin))
				{
					return crow::response(501, "Invoke not supported for UML-only plugins via eInvoke()");
				}
				return crow::response(404, "Operation not found!");
			}

			// IMPORTANT: eInvoke() typically expects an operation instance from the object's own EClass,
			// not the metamodel operation pointer (mixing those can crash). Try to map by signature.
			std::shared_ptr<ecore::EOperation> invokeOp = nullptr;
			try
			{
				const auto cls = obj->eClass();
				if(cls)
				{
					const auto directOps = cls->getEOperations();
					const auto allOps = cls->getEAllOperations();
					const auto opList = (directOps && directOps->size() > 0) ? directOps : allOps;
					if(opList)
					{
						const auto wantedParams = targetOp->getEParameters();
						const size_t wantedCount = wantedParams ? static_cast<size_t>(wantedParams->size()) : 0;

						for(auto oit = opList->cbegin(); oit != opList->cend(); ++oit)
						{
							const auto op = *oit;
							if(!op) continue;
							if(op->getName() != targetOp->getName()) continue;

							const auto ps = op->getEParameters();
							const size_t pCount = ps ? static_cast<size_t>(ps->size()) : 0;
							if(pCount != wantedCount) continue;

							// Best-effort type match by parameter type name
							bool typeMatch = true;
							if(wantedParams && ps)
							{
								auto wp = wantedParams->cbegin();
								auto cp = ps->cbegin();
								for(; wp != wantedParams->cend() && cp != ps->cend(); ++wp, ++cp)
								{
									const auto a = *wp;
									const auto b = *cp;
									if(!a || !b) continue;
									const auto at = a->getEType();
									const auto bt = b->getEType();
									const std::string an = at ? at->getName() : "";
									const std::string bn = bt ? bt->getName() : "";
									if(!an.empty() && !bn.empty() && an != bn)
									{
										typeMatch = false;
										break;
									}
								}
							}

							if(typeMatch)
							{
								invokeOp = op;
								break;
							}
						}
					}
				}
			}
			catch(...)
			{
				// ignore; handled below
			}

			if(!invokeOp)
			{
				// Don't attempt to call eInvoke with an incompatible operation pointer.
				return crow::response(501, "Operation found, but not invokable via EObject::eInvoke() for this object.");
			}

			// Build arguments bag (best-effort conversions)
			auto argsBag = std::make_shared<Bag<Any>>();
			try
			{
				const auto ps = targetOp->getEParameters();
				if(ps && body && argsJson.t() == crow::json::type::List)
				{
					size_t idx = 0;
					for(auto pit = ps->cbegin(); pit != ps->cend() && idx < static_cast<size_t>(argsJson.size()); ++pit, ++idx)
					{
						const auto p = *pit;
						const auto v = argsJson[idx];
						if(!p) { argsBag->push_back(eAny(std::string(""), 0, false)); continue; }

						std::string typeName;
						try { typeName = p->getEType() ? p->getEType()->getName() : ""; } catch(...) { typeName = ""; }

						// Primitive conversions by JSON type + expected type name.
						if(v.t() == crow::json::type::True || v.t() == crow::json::type::False)
						{
							argsBag->push_back(eAny(v.b(), ecore::ecorePackage::EBOOLEAN_CLASS, false));
							continue;
						}
						if(v.t() == crow::json::type::Number)
						{
							// Crow stores numbers as double.
							const double d = v.d();
							if(typeName == "Integer" || typeName == "EInt" || typeName == "int")
								argsBag->push_back(eAny(static_cast<int>(d), ecore::ecorePackage::EINT_CLASS, false));
							else if(typeName == "Long" || typeName == "ELong" || typeName == "long")
								argsBag->push_back(eAny(static_cast<long>(d), ecore::ecorePackage::ELONG_CLASS, false));
							else if(typeName == "Boolean" || typeName == "EBoolean")
								argsBag->push_back(eAny(d != 0.0, ecore::ecorePackage::EBOOLEAN_CLASS, false));
							else
								argsBag->push_back(eAny(d, ecore::ecorePackage::EDOUBLE_CLASS, false));
							continue;
						}
						if(v.t() == crow::json::type::String)
						{
							const std::string s = v.s();
							if(typeName == "Boolean" || typeName == "EBoolean")
							{
								const bool b = (s == "true" || s == "True" || s == "1");
								argsBag->push_back(eAny(b, ecore::ecorePackage::EBOOLEAN_CLASS, false));
							}
							else if(typeName == "Integer" || typeName == "EInt" || typeName == "int")
							{
								argsBag->push_back(eAny(std::stoi(s), ecore::ecorePackage::EINT_CLASS, false));
							}
							else
							{
								// If this looks like an object reference, pass EObject pointer when available
								std::shared_ptr<ecore::EObject> refObj;
								{
									std::lock_guard<std::mutex> lock(m_objectsMutex);
									auto itObjRef = m_objects.find(s);
									if(itObjRef != m_objects.end())
										refObj = itObjRef->second.object;
								}
								if(refObj)
									argsBag->push_back(eAny(refObj, 0, false));
								else
									argsBag->push_back(eAny(s, ecore::ecorePackage::ESTRING_CLASS, false));
							}
							continue;
						}

						// Default: null/unknown
						argsBag->push_back(eAny(std::string(""), 0, false));
					}
				}
			}
			catch(...)
			{
				// best-effort only
			}

			// Preferred long-term path: let the plugin execute with real semantics.
			if(const auto invoker = std::dynamic_pointer_cast<OperationInvokerPlugin>(plugin))
			{
				if(!invoker->canInvoke(obj, operationName))
				{
					return crow::response(501, "Operation not invokable by this plugin (no execution semantics available).");
				}

				OperationInvokerPlugin::InvokeRequest invReq;
				invReq.operationName = operationName;
				invReq.operation = invokeOp;
				invReq.arguments = argsBag;

				OperationInvokerPlugin::InvokeResult invRes;
				try
				{
					invRes = invoker->invoke(obj, invReq);
				}
				catch(const std::exception& e)
				{
					return crow::response(500, std::string("Invoke failed: ") + e.what());
				}
				catch(...)
				{
					return crow::response(500, "Invoke failed: unknown error");
				}

				if(!invRes.success)
				{
					return crow::response(500, invRes.error.empty() ? "Invoke failed" : invRes.error);
				}

				crow::json::wvalue out;
				out["success"] = true;
				out["via"] = "native_plugin";

				const auto ret = invRes.result;
				if(!ret || ret->isEmpty())
				{
					out["result"] = nullptr;
				}
				else
				{
					// Best-effort serialization
					try { out["result"] = ret->get<std::string>(); }
					catch(...) {
						try { out["result"] = ret->get<int>(); }
						catch(...) {
							try { out["result"] = ret->get<double>(); }
							catch(...) {
								try { out["result"] = ret->get<bool>(); }
								catch(...) {
									// EObject result
									try {
										const std::shared_ptr<ecore::EObject> robj = ret->get<std::shared_ptr<ecore::EObject>>();
										if(robj)
										{
											out["result"] = writeValue(robj, plugin);
										}
										else out["result"] = nullptr;
									} catch(...) {
										out["result"] = ret->toString();
									}
								}
							}
						}
					}
				}

				return crow::response(200, out);
			}

			// Back-compat fallback: avoid invoking model-defined operations unless explicitly supported.
			if(operationName.empty() || operationName[0] != 'e')
			{
				bool codegen = false;
				try
				{
					// IMPORTANT: the "codegen body" annotation lives on the metamodel operation,
					// not necessarily on the instance EOperation used for eInvoke.
					const auto ann = targetOp ? targetOp->getEAnnotation("http://tu-ilmenau.de/see/codegen") : nullptr;
					const auto details = ann ? ann->getDetails() : nullptr;
					if(details && details->find("doNotGenerate") == details->end())
					{
						const auto itBody = details->find("body");
						if(itBody != details->end() && !itBody->second.empty()) codegen = true;
					}
				}
				catch(...)
				{
					// ignore
				}

				if(!codegen)
				{
					return crow::response(501, "Invoke not supported: operation has no executable semantics (no plugin invoker, no codegen body).");
				}
			}

			try
			{
				const auto ret = obj->eInvoke(invokeOp, argsBag);
				crow::json::wvalue out;
				out["success"] = true;
				if(!ret || ret->isEmpty())
				{
					out["result"] = nullptr;
				}
				else
				{
					// Best-effort serialization
					try { out["result"] = ret->get<std::string>(); }
					catch(...) {
						try { out["result"] = ret->get<int>(); }
						catch(...) {
							try { out["result"] = ret->get<double>(); }
							catch(...) {
								try { out["result"] = ret->get<bool>(); }
								catch(...) {
									// EObject result
									try {
										const std::shared_ptr<ecore::EObject> robj = ret->get<std::shared_ptr<ecore::EObject>>();
										if(robj)
										{
											out["result"] = writeValue(robj, plugin);
										}
										else out["result"] = nullptr;
									} catch(...) {
										out["result"] = ret->toString();
									}
								}
							}
						}
					}
				}
				return crow::response(200, out);
			}
			catch(const std::exception& e)
			{
				return crow::response(500, std::string("Invoke failed: ") + e.what());
			}
			catch(...)
			{
				return crow::response(500, "Invoke failed: unknown error");
			}
		}
	);

    //Update function
    CROW_ROUTE(app, "/<string>/objects/<string>/<string>").methods(crow::HTTPMethod::Put)([this](const crow::request& request, const std::string& plugin_name, const std::string& className, const std::string& objectName){
		try
		{
			std::string existingParent;
			{
				std::lock_guard<std::mutex> lock(m_objectsMutex);
				auto it = m_objects.find(objectName);
				if(it == m_objects.end()){
					return crow::response(404);
				}
				if(it->second.pluginName != plugin_name){
					return crow::response(404);
				}
				existingParent = it->second.parentName;
			}
			const std::shared_ptr<MDE4CPPPlugin>& plugin = getPlugin(plugin_name);
			if(plugin == nullptr){
				return crow::response(404, "Plugin not found!");
			}

			auto body = crow::json::load(request.body);
			if(!body) {
				body = crow::json::load("{}");
			}
			auto object = std::shared_ptr<ecore::EObject>(nullptr);
			try
			{
				object = readValue(body, className, plugin);
			}
			catch(...)
			{
				if(className.find("::") == std::string::npos)
				{
					const std::string qualified = plugin->eNAME() + "::" + className;
					object = readValue(body, qualified, plugin);
				}
				else
				{
					throw;
				}
			}
			if(!object){
				return crow::response(400, "Failed to update object (unknown class?)");
			}
			{
				std::lock_guard<std::mutex> lock(m_objectsMutex);
				m_objects[objectName] = StoredObject{plugin_name, className, object, existingParent};
			}
			return crow::response(200);
		}
		catch(const std::exception& e)
		{
			CROW_LOG_ERROR << "Update object failed: " << e.what();
			return crow::response(500, std::string("Update object failed: ") + e.what());
		}
		catch(...)
		{
			CROW_LOG_ERROR << "Update object failed: unknown error";
			return crow::response(500, "Update object failed: unknown error");
		}
    });

    //Delete function
    CROW_ROUTE(app, "/<string>/objects/<string>/<string>").methods(crow::HTTPMethod::Delete)([this](const std::string& plugin_name, const std::string& className, const std::string& objectName){
        std::lock_guard<std::mutex> lock(m_objectsMutex);
        auto it = m_objects.find(objectName);
        if(it == m_objects.end()){
            return crow::response(404);
        }
		if(it->second.pluginName != plugin_name){
			return crow::response(404);
		}
        m_objects.erase(it);
        return crow::response(204);
    });

    //Create instance model
    CROW_ROUTE(app, "/<string>/objects").methods(crow::HTTPMethod::Post)([this](const crow::request& request, const std::string& plugin_name){
		const std::shared_ptr<MDE4CPPPlugin>& plugin = getPlugin(plugin_name);
		if(plugin == nullptr){
			return crow::response(404, "Plugin not found!");
		}
		auto body = crow::json::load(request.body);
		if(!body) return crow::response(400, "Invalid JSON body");
		for(const auto & entry : body){
			try {
				const auto id = entry["ecore_identifier"].s();
				const auto type = entry["ecore_type"].s();
				auto object = readValue(entry, type, plugin);
				if(object){
					std::lock_guard<std::mutex> lock(m_objectsMutex);
					m_objects[id] = StoredObject{plugin_name, type, object, ""};
				}
			} catch(...) { /* skip bad entry */ }
		}
		return crow::response(201);
    });

    //Get instance model
    CROW_ROUTE(app, "/<string>/objects/").methods(crow::HTTPMethod::Get)([this](const std::string& plugin_name){
		const std::shared_ptr<MDE4CPPPlugin>& plugin = getPlugin(plugin_name);
		if(plugin == nullptr){
			return crow::response(404, "Plugin not found!");
		}
		std::vector<std::pair<std::string, StoredObject>> snapshot;
		{
			std::lock_guard<std::mutex> lock(m_objectsMutex);
			for(const auto & entry : m_objects){
				if(entry.second.pluginName != plugin_name) continue;
				snapshot.push_back(entry);
			}
		}
        crow::json::wvalue result;
        int i = 0;
        for(const auto & entry : snapshot){
            auto wvalue = writeValue(entry.second.object, plugin);
            wvalue["ecore_identifier"] = entry.first;
            try { wvalue["ecore_type"] = entry.second.object && entry.second.object->eClass() ? entry.second.object->eClass()->getName() : entry.second.className; } catch(...) { wvalue["ecore_type"] = entry.second.className; }
            result[i] = std::move(wvalue);
            i++;
        }
        return crow::response(200, result);
    });

	// Global object list (for backend aggregation)
	// Returns: [{ "name": "<objectName>", "plugin": "<pluginName>", "type": "<className>" }, ...]
	CROW_ROUTE(app, "/objects").methods(crow::HTTPMethod::Get)([this](){
		std::vector<std::pair<std::string, StoredObject>> snapshot;
		{
			std::lock_guard<std::mutex> lock(m_objectsMutex);
			snapshot.assign(m_objects.begin(), m_objects.end());
		}
		auto list = crow::json::wvalue::list();
		for(const auto& entry : snapshot){
			crow::json::wvalue item;
			item["name"] = entry.first;
			item["plugin"] = entry.second.pluginName;
			item["type"] = entry.second.className;
			list.push_back(std::move(item));
		}
		crow::json::wvalue result = crow::json::wvalue(list);
		return crow::response(200, result);
	});

	// Create child object within a parent via containment reference
	// POST /{plugin}/objects/{parentName}/children/{className}/{childName}
	// Body: { "referenceID": <int> }
	CROW_ROUTE(app, "/<string>/objects/<string>/children/<string>/<string>").methods(crow::HTTPMethod::Post)(
		[this](
			const crow::request& request,
			const std::string& plugin_name,
			const std::string& parentName,
			const std::string& className,
			const std::string& childName){
			try
			{
				std::shared_ptr<ecore::EObject> parentObj;
				{
					std::lock_guard<std::mutex> lock(m_objectsMutex);
					if(m_objects.find(childName) != m_objects.end()){
						return crow::response(400, "Object already exists!");
					}
					auto parentIt = m_objects.find(parentName);
					if(parentIt == m_objects.end() || parentIt->second.pluginName != plugin_name){
						return crow::response(404, "Parent object not found!");
					}
					parentObj = parentIt->second.object;
				}
				if(!parentObj){
					return crow::response(404, "Parent object not found!");
				}

				const std::shared_ptr<MDE4CPPPlugin>& plugin = getPlugin(plugin_name);
				if(!plugin){
					return crow::response(404, "Plugin not found!");
				}

				// Read referenceID from body
				auto body = crow::json::load(request.body);
				if(!body){
					return crow::response(400, "Missing JSON body (expected referenceID)");
				}

				int referenceID = -1;
				try {
					auto refVal = body["referenceID"];
					if(refVal.t() == crow::json::type::Number){
						referenceID = static_cast<int>(refVal.i());
					}
				} catch(...) {
					// fall through
				}
				if(referenceID < 0){
					return crow::response(400, "referenceID is required and must be a non-negative integer");
				}

				// Create child via plugin API with containment
				std::shared_ptr<ecore::EObject> child;
				try
				{
					child = plugin->create(className, parentObj, static_cast<unsigned int>(referenceID));
					// Fallback: qualified name "plugin::Class"
					if(!child && className.find("::") == std::string::npos){
						const std::string qualified = plugin->eNAME() + "::" + className;
						child = plugin->create(qualified, parentObj, static_cast<unsigned int>(referenceID));
					}
				}
				catch(...)
				{
					// fall through; handled below
				}

				if(!child){
					// For UML-only plugins, container-based create is intentionally not implemented
					if(std::dynamic_pointer_cast<UMLModelPlugin>(plugin)){
						return crow::response(501, "Containment-based create is not supported for UML plugins via this endpoint.");
					}
					return crow::response(400, "Failed to create child object (unknown class or invalid referenceID?)");
				}

				// Apply optional properties (title, copies, available, etc.)
				try {
					auto propsJson = body["properties"];
					if(propsJson && propsJson.t() == crow::json::type::Object){
						applyPropertiesToObject(child, propsJson, plugin);
					}
				} catch(...) { /* best-effort; ignore property apply errors */ }

				// Register new child object with parent link for tree hierarchy
				{
					std::lock_guard<std::mutex> lock(m_objectsMutex);
					m_objects[childName] = StoredObject{plugin_name, className, child, parentName};
				}
				return crow::response(201);
			}
			catch(const std::exception& e)
			{
				CROW_LOG_ERROR << "Create child object failed: " << e.what();
				return crow::response(500, std::string("Create child object failed: ") + e.what());
			}
			catch(...)
			{
				CROW_LOG_ERROR << "Create child object failed: unknown error";
				return crow::response(500, "Create child object failed: unknown error");
			}
		});

	//Get name of all plugins found and currently in m_plugins 
	CROW_ROUTE(app, "/plugins").methods(crow::HTTPMethod::Get)([this](){
		
       auto list = crow::json::wvalue::list();
	   for(const std::pair<std::string,std::shared_ptr<MDE4CPPPlugin>>& entry : m_plugins){
		   list.push_back(crow::json::wvalue(entry.first));
	   }
	   crow::json::wvalue result = crow::json::wvalue(list);
	   return crow::response(200, result);
    });

	// Plugin capabilities endpoint (for UI decision-making)
	// GET /{plugin}/capabilities
	CROW_ROUTE(app, "/<string>/capabilities").methods(crow::HTTPMethod::Get)(
		[this](const std::string& plugin_name){
			const std::shared_ptr<MDE4CPPPlugin>& plugin = getPlugin(plugin_name);
			if(plugin == nullptr){
				return crow::response(404, "Plugin not found!");
			}

			crow::json::wvalue caps;
			caps["name"] = plugin_name;
			caps["eNAME"] = plugin->eNAME();
			caps["nsURI"] = plugin->eNS_URI();
			caps["nsPrefix"] = plugin->eNS_PREFIX();

			const bool hasNativeInvoker = (std::dynamic_pointer_cast<OperationInvokerPlugin>(plugin) != nullptr);
			caps["invoke"] = crow::json::wvalue();
			caps["invoke"]["supported"] = hasNativeInvoker;
			caps["invoke"]["via"] = hasNativeInvoker ? "native_plugin" : "none";

			caps["kind"] = "unknown";
			if(std::dynamic_pointer_cast<EcoreModelPlugin>(plugin)) caps["kind"] = "ecore";
			else if(std::dynamic_pointer_cast<UMLModelPlugin>(plugin)) caps["kind"] = "uml";

			return crow::response(200, caps);
		}
	);

	// Plugin structure endpoint (real reflection)
	CROW_ROUTE(app, "/<string>/structure").methods(crow::HTTPMethod::Get)([this](const std::string& plugin_name){
		const std::shared_ptr<MDE4CPPPlugin>& plugin = getPlugin(plugin_name);
		if(plugin == nullptr){
			return crow::response(404, "Plugin not found!");
		}

		crow::json::wvalue result;
		result["name"] = plugin_name;
		result["nsURI"] = plugin->eNS_URI();
		result["nsPrefix"] = plugin->eNS_PREFIX();

		auto classifiers = crow::json::wvalue::list();

		// Ecore-based plugins (ecore, uml, fUML, ...)
		if(const auto ecorePlugin = std::dynamic_pointer_cast<EcoreModelPlugin>(plugin))
		{
			const auto pkg = ecorePlugin->getEPackage();
			if(pkg != nullptr)
			{
				result["name"] = pkg->getName();
				result["nsURI"] = pkg->getNsURI();
				result["nsPrefix"] = pkg->getNsPrefix();

				const auto eClassifiers = pkg->getEClassifiers();
				if(eClassifiers != nullptr)
				{
					for(auto it = eClassifiers->cbegin(); it != eClassifiers->cend(); ++it)
					{
						const auto c = *it;
						if(!c) continue;
						crow::json::wvalue item;
						item["name"] = c->getName();
						if(std::dynamic_pointer_cast<ecore::EClass>(c)) item["type"] = "EClass";
						else if(std::dynamic_pointer_cast<ecore::EEnum>(c)) item["type"] = "EEnum";
						else if(std::dynamic_pointer_cast<ecore::EDataType>(c)) item["type"] = "EDataType";
						else item["type"] = "EClassifier";
						classifiers.push_back(std::move(item));
					}
				}
			}
		}
		// UML-model plugins (UML4CPP generator output)
		else if(const auto umlPlugin = std::dynamic_pointer_cast<UMLModelPlugin>(plugin))
		{
			const auto rootPkg = umlPlugin->getPackage();
			if(rootPkg != nullptr)
			{
				result["name"] = rootPkg->getName();
				// nsURI/nsPrefix are still provided by the plugin itself

				std::function<void(const std::shared_ptr<uml::Namespace>&)> visitNamespace;
				visitNamespace = [&](const std::shared_ptr<uml::Namespace>& ns){
					if(!ns) return;
					const auto owned = ns->getOwnedMember();
					if(!owned) return;
					for(auto it = owned->cbegin(); it != owned->cend(); ++it)
					{
						const auto member = *it;
						if(!member) continue;

						if(const auto pkg = std::dynamic_pointer_cast<uml::Package>(member))
						{
							visitNamespace(pkg);
							continue;
						}
						if(const auto cls = std::dynamic_pointer_cast<uml::Class>(member))
						{
							crow::json::wvalue item;
							item["name"] = cls->getName();
							item["type"] = "EClass";
							classifiers.push_back(std::move(item));
							continue;
						}
						if(const auto en = std::dynamic_pointer_cast<uml::Enumeration>(member))
						{
							crow::json::wvalue item;
							item["name"] = en->getName();
							item["type"] = "EEnum";
							classifiers.push_back(std::move(item));
							continue;
						}
						if(const auto dt = std::dynamic_pointer_cast<uml::DataType>(member))
						{
							crow::json::wvalue item;
							item["name"] = dt->getName();
							item["type"] = "EDataType";
							classifiers.push_back(std::move(item));
							continue;
						}
					}
				};

				visitNamespace(rootPkg);
			}
		}

		result["classifiers"] = std::move(classifiers);
		return crow::response(200, result);
	});

	// Optional: classifier list endpoint
	CROW_ROUTE(app, "/<string>/classifiers").methods(crow::HTTPMethod::Get)([this](const std::string& plugin_name){
		const std::shared_ptr<MDE4CPPPlugin>& plugin = getPlugin(plugin_name);
		if(plugin == nullptr){
			return crow::response(404, "Plugin not found!");
		}

		auto list = crow::json::wvalue::list();
		// Keep simple: reuse /structure implementation by recomputing
		if(const auto ecorePlugin = std::dynamic_pointer_cast<EcoreModelPlugin>(plugin))
		{
			const auto pkg = ecorePlugin->getEPackage();
			if(pkg != nullptr)
			{
				const auto eClassifiers = pkg->getEClassifiers();
				if(eClassifiers != nullptr)
				{
					for(auto it = eClassifiers->cbegin(); it != eClassifiers->cend(); ++it)
					{
						const auto c = *it;
						if(!c) continue;
						list.push_back(crow::json::wvalue(c->getName()));
					}
				}
			}
		}
		else if(const auto umlPlugin = std::dynamic_pointer_cast<UMLModelPlugin>(plugin))
		{
			const auto rootPkg = umlPlugin->getPackage();
			if(rootPkg != nullptr)
			{
				std::function<void(const std::shared_ptr<uml::Namespace>&)> visitNamespace;
				visitNamespace = [&](const std::shared_ptr<uml::Namespace>& ns){
					if(!ns) return;
					const auto owned = ns->getOwnedMember();
					if(!owned) return;
					for(auto it = owned->cbegin(); it != owned->cend(); ++it)
					{
						const auto member = *it;
						if(!member) continue;
						if(const auto pkg = std::dynamic_pointer_cast<uml::Package>(member)) { visitNamespace(pkg); continue; }
						if(const auto cls = std::dynamic_pointer_cast<uml::Class>(member)) { list.push_back(crow::json::wvalue(cls->getName())); continue; }
						if(const auto en = std::dynamic_pointer_cast<uml::Enumeration>(member)) { list.push_back(crow::json::wvalue(en->getName())); continue; }
						if(const auto dt = std::dynamic_pointer_cast<uml::DataType>(member)) { list.push_back(crow::json::wvalue(dt->getName())); continue; }
					}
				};
				visitNamespace(rootPkg);
			}
		}

		crow::json::wvalue result = crow::json::wvalue(list);
		return crow::response(200, result);
	});

	// Plugin classifier details endpoint (real reflection)
	CROW_ROUTE(app, "/<string>/classifiers/<string>").methods(crow::HTTPMethod::Get)([this](const std::string& plugin_name, const std::string& class_name){
		try {
			const std::shared_ptr<MDE4CPPPlugin>& plugin = getPlugin(plugin_name);
			if(plugin == nullptr){
				return crow::response(404, "Plugin not found!");
			}

			crow::json::wvalue result;
			result["name"] = class_name;
			result["attributes"] = crow::json::wvalue::list();
			result["references"] = crow::json::wvalue::list();
			result["operations"] = crow::json::wvalue::list();

			// Ecore-based plugins
			if(const auto ecorePlugin = std::dynamic_pointer_cast<EcoreModelPlugin>(plugin))
			{
				const auto pkg = ecorePlugin->getEPackage();
				if(pkg == nullptr){
					return crow::response(500, "Plugin has no EPackage");
				}
				std::shared_ptr<ecore::EClassifier> classifier = nullptr;
				const auto eClassifiers = pkg->getEClassifiers();
				if(eClassifiers != nullptr)
				{
					for(auto it = eClassifiers->cbegin(); it != eClassifiers->cend(); ++it)
					{
						const auto c = *it;
						if(c && c->getName() == class_name)
						{
							classifier = c;
							break;
						}
					}
				}
				if(classifier == nullptr){
					return crow::response(404, "Classifier not found!");
				}

			if(const auto eCls = std::dynamic_pointer_cast<ecore::EClass>(classifier))
			{
				result["type"] = "EClass";
				result["abstract"] = eCls->isAbstract();
				result["interface"] = eCls->isInterface();

				// EClass details (safe, non-crashing traversal)
				auto attrs = crow::json::wvalue::list();
				auto refs = crow::json::wvalue::list();
				const auto features = eCls->getEAllStructuralFeatures();
				if(features)
				{
					for(auto it = features->cbegin(); it != features->cend(); ++it)
					{
						const auto f = *it;
						if(!f) continue;
						try
						{
							if(const auto a = std::dynamic_pointer_cast<ecore::EAttribute>(f))
							{
								crow::json::wvalue aitem;
								aitem["name"] = a->getName();
								aitem["lower"] = a->getLowerBound();
								aitem["upper"] = a->getUpperBound();
								aitem["required"] = a->isRequired();
								aitem["id"] = a->isID();
								// Prefer ETypedElement::getEType() (more reliable than getEAttributeType() here)
								const auto t = a->getEType();
								aitem["type"] = t ? t->getName() : "";
								// Add featureID for attribute (used for eGet/eSet operations)
								try {
									const int featureID = eCls->getFeatureID(a);
									if(featureID >= 0) {
										aitem["featureID"] = featureID;
									}
								} catch(...) {
									// If getFeatureID fails, leave featureID unset (frontend can use index fallback)
								}
								attrs.push_back(std::move(aitem));
								continue;
							}
							if(const auto r = std::dynamic_pointer_cast<ecore::EReference>(f))
							{
								crow::json::wvalue ritem;
								ritem["name"] = r->getName();
								ritem["lower"] = r->getLowerBound();
								ritem["upper"] = r->getUpperBound();
								ritem["required"] = r->isRequired();
								ritem["containment"] = r->isContainment();
								ritem["resolveProxies"] = r->isResolveProxies();
								const auto rt = r->getEType();
								ritem["type"] = rt ? rt->getName() : "";
								const auto opp = r->getEOpposite();
								ritem["opposite"] = opp ? opp->getName() : "";
								// Add featureID for reference (critical for child creation via containment)
								// This is the ID used in plugin->create(className, parent, featureID)
								try {
									const int featureID = eCls->getFeatureID(r);
									if(featureID >= 0) {
										ritem["featureID"] = featureID;
									}
								} catch(...) {
									// If getFeatureID fails, leave featureID unset (frontend can use index fallback)
								}
								refs.push_back(std::move(ritem));
								continue;
							}
						}
						catch(...)
						{
							// Skip unsafe feature; keep endpoint stable.
							continue;
						}
					}
				}
				result["attributes"] = crow::json::wvalue(std::move(attrs));
				result["references"] = crow::json::wvalue(std::move(refs));

				// Operations (prefer list iteration; getEOperation(i) uses operationID, not index)
				auto ops = crow::json::wvalue::list();
				auto addOp = [&](const std::shared_ptr<ecore::EOperation>& op){
					if(!op) return;
					crow::json::wvalue oitem;
					try { oitem["name"] = op->getName(); } catch(...) { oitem["name"] = ""; }
					try {
						const auto retT = op->getEType();
						oitem["returnType"] = retT ? retT->getName() : "";
					} catch(...) { oitem["returnType"] = ""; }

					auto params = crow::json::wvalue::list();
					try
					{
						const auto ps = op->getEParameters();
						if(ps)
						{
							for(auto pit = ps->cbegin(); pit != ps->cend(); ++pit)
							{
								const auto p = *pit;
								if(!p) continue;
								crow::json::wvalue pitem;
								try { pitem["name"] = p->getName(); } catch(...) { pitem["name"] = ""; }
								try { pitem["lower"] = p->getLowerBound(); } catch(...) { pitem["lower"] = 0; }
								try { pitem["upper"] = p->getUpperBound(); } catch(...) { pitem["upper"] = 1; }
								try {
									const auto pt = p->getEType();
									pitem["type"] = pt ? pt->getName() : "";
								} catch(...) { pitem["type"] = ""; }
								params.push_back(std::move(pitem));
							}
						}
					}
					catch(...)
					{
						// leave params empty if unsafe
					}
					oitem["parameters"] = crow::json::wvalue(std::move(params));
					ops.push_back(std::move(oitem));
				};

				try
				{
					const auto allOps = eCls->getEAllOperations();
					if(allOps)
					{
						for(auto it = allOps->cbegin(); it != allOps->cend(); ++it)
						{
							addOp(*it);
						}
					}
					else
					{
						const auto directOps = eCls->getEOperations();
						if(directOps)
						{
							for(auto it = directOps->cbegin(); it != directOps->cend(); ++it)
							{
								addOp(*it);
							}
						}
					}
				}
				catch(...)
				{
					// keep operations empty if unsafe
				}
				result["operations"] = crow::json::wvalue(std::move(ops));

				result["featureCount"] = eCls->getFeatureCount();
				result["operationCount"] = eCls->getOperationCount();
				return crow::response(200, result);
				}
				if(const auto eEnum = std::dynamic_pointer_cast<ecore::EEnum>(classifier))
				{
					result["type"] = "EEnum";
					auto lits = crow::json::wvalue::list();
					try
					{
						const auto elits = eEnum->getELiterals();
						if(elits)
						{
							for(auto it = elits->cbegin(); it != elits->cend(); ++it)
							{
								const auto lit = *it;
								if(!lit) continue;
								crow::json::wvalue litem;
								try { litem["name"] = lit->getName(); } catch(...) { litem["name"] = ""; }
								try { litem["literal"] = lit->getLiteral(); } catch(...) { litem["literal"] = ""; }
								try { litem["value"] = lit->getValue(); } catch(...) { litem["value"] = 0; }
								lits.push_back(std::move(litem));
							}
						}
					}
					catch(...)
					{
						// keep empty if unsafe
					}
					result["literals"] = crow::json::wvalue(std::move(lits));
					return crow::response(200, result);
				}
				if(const auto dt = std::dynamic_pointer_cast<ecore::EDataType>(classifier))
				{
					result["type"] = "EDataType";
					try { result["serializable"] = dt->isSerializable(); } catch(...) { result["serializable"] = true; }
					try { result["instanceClassName"] = dt->getInstanceClassName(); } catch(...) { result["instanceClassName"] = ""; }
					try { result["instanceTypeName"] = dt->getInstanceTypeName(); } catch(...) { result["instanceTypeName"] = ""; }
					return crow::response(200, result);
				}

				result["type"] = "EClassifier";
				return crow::response(200, result);
			}

			// UML-model plugins
			if(const auto umlPlugin = std::dynamic_pointer_cast<UMLModelPlugin>(plugin))
			{
				const auto rootPkg = umlPlugin->getPackage();
				if(rootPkg == nullptr){
					return crow::response(500, "Plugin has no UML Package");
				}

			std::shared_ptr<uml::NamedElement> found;
			std::function<void(const std::shared_ptr<uml::Namespace>&)> findInNamespace;
			findInNamespace = [&](const std::shared_ptr<uml::Namespace>& ns){
				if(found || !ns) return;
				const auto owned = ns->getOwnedMember();
				if(!owned) return;
				for(auto it = owned->cbegin(); it != owned->cend(); ++it){
					const auto member = *it;
					if(!member) continue;
					if(member->getName() == class_name){
						found = member;
						return;
					}
					if(const auto pkg = std::dynamic_pointer_cast<uml::Package>(member)){
						findInNamespace(pkg);
						if(found) return;
					}
				}
			};
			findInNamespace(rootPkg);

			if(!found){
				return crow::response(404, "Classifier not found!");
			}

			if(const auto cls = std::dynamic_pointer_cast<uml::Class>(found))
			{
				result["type"] = "EClass";
				result["abstract"] = false;

				auto attrs = crow::json::wvalue::list();
				const auto ownedAttr = cls->getClass_OwnedAttribute();
				if(ownedAttr){
					for(auto it = ownedAttr->cbegin(); it != ownedAttr->cend(); ++it){
						const auto p = *it;
						if(!p) continue;
						crow::json::wvalue item;
						item["name"] = p->getName();
						item["lower"] = p->getLower();
						item["upper"] = p->getUpper();
						const auto t = p->getType();
						item["type"] = t ? t->getName() : "";
						attrs.push_back(std::move(item));
					}
				}
				result["attributes"] = crow::json::wvalue(std::move(attrs));

				auto ops = crow::json::wvalue::list();
				const auto ownedOps = cls->getOwnedOperation();
				if(ownedOps){
					for(auto it = ownedOps->cbegin(); it != ownedOps->cend(); ++it){
						const auto op = *it;
						if(!op) continue;
						crow::json::wvalue item;
						item["name"] = op->getName();
						const auto ret = op->returnResult();
						item["returnType"] = (ret && ret->getType()) ? ret->getType()->getName() : "";

						auto params = crow::json::wvalue::list();
						const auto ps = op->getProperty_OwnedParameter();
						if(ps){
							for(auto pit = ps->cbegin(); pit != ps->cend(); ++pit){
								const auto p = *pit;
								if(!p) continue;
								crow::json::wvalue pitem;
								pitem["name"] = p->getName();
								pitem["lower"] = p->getLower();
								pitem["upper"] = p->getUpper();
								pitem["type"] = p->getType() ? p->getType()->getName() : "";
								params.push_back(std::move(pitem));
							}
						}
						item["parameters"] = crow::json::wvalue(std::move(params));
						ops.push_back(std::move(item));
					}
				}
				result["operations"] = crow::json::wvalue(std::move(ops));

				return crow::response(200, result);
			}

			if(const auto en = std::dynamic_pointer_cast<uml::Enumeration>(found))
			{
				result["type"] = "EEnum";
				auto lits = crow::json::wvalue::list();
				const auto owned = en->getOwnedLiteral();
				if(owned)
				{
					for(auto it = owned->cbegin(); it != owned->cend(); ++it)
					{
						const auto lit = *it;
						if(!lit) continue;
						crow::json::wvalue litem;
						litem["name"] = lit->getName();
						lits.push_back(std::move(litem));
					}
				}
				result["literals"] = crow::json::wvalue(std::move(lits));
				return crow::response(200, result);
			}

				result["type"] = "EClassifier";
				return crow::response(200, result);
			}

			return crow::response(200, result);
		} catch(const std::exception& e) {
			return crow::response(500, std::string("Exception: ") + e.what());
		} catch(...) {
			return crow::response(500, "Unknown exception");
		}
	});

    //Swagger
    CROW_ROUTE(app, "/")([](){
        auto page = crow::mustache::load_text("index.html");
        return crow::response(page);
    });

    CROW_ROUTE(app, "/<string>")([](const std::string& path){
        auto page = crow::mustache::load_text(path);
        return crow::response(page);
    });

    // Use minimum concurrency; Crow enforces min 2 threads - m_objects protected by mutex
    try {
        const char* bindEnv = std::getenv("MDE4CPP_PLUGINAPI_BIND");
        std::string bindAddr = (bindEnv && bindEnv[0]) ? std::string(bindEnv) : std::string("127.0.0.1");
        int port = 9080;
        const char* portEnv = std::getenv("MDE4CPP_PLUGINAPI_PORT");
        if (portEnv && portEnv[0]) {
            char* end = nullptr;
            long p = std::strtol(portEnv, &end, 10);
            if (end != portEnv && p > 0 && p <= 65535) {
                port = static_cast<int>(p);
            }
        }
        std::cerr << "Starting Crow HTTP server on " << bindAddr << ":" << port << "..." << std::endl;
        std::cerr << "(Set MDE4CPP_PLUGINAPI_BIND / MDE4CPP_PLUGINAPI_PORT to override; use another port if bind fails with 10013 on Windows.)" << std::endl;
        std::cerr.flush();
        app.bindaddr(bindAddr).port(port).concurrency(1).run();
    } catch(const std::exception& e) {
        std::cerr << "FATAL: Crow server crashed with exception: " << e.what() << std::endl;
        std::cerr.flush();
        throw;
    } catch(...) {
        std::cerr << "FATAL: Crow server crashed with unknown exception" << std::endl;
        std::cerr.flush();
        throw;
    }
}

crow::json::wvalue GenericApi::writeValue(const std::shared_ptr<ecore::EObject>& object, const std::shared_ptr<MDE4CPPPlugin>& plugin){
    // #region agent log
    { std::ofstream log("d:\\DEV\\test2\\MDE4CPP\\.cursor\\debug.log", std::ios::app); log << "{\"sessionId\":\"debug-session\",\"runId\":\"run1\",\"hypothesisId\":\"A\",\"location\":\"writeValue:entry\",\"message\":\"writeValue entry\",\"data\":{\"object\":\"" << (object ? "valid" : "null") << "\",\"plugin\":\"" << (plugin ? "valid" : "null") << "\"},\"timestamp\":" << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() << "}\n"; }
    // #endregion
    auto result = crow::json::wvalue();
    if(!object || !plugin) return result;
    std::shared_ptr<ecore::EClass> eCls;
    try { 
        eCls = object->eClass(); 
    } catch(const std::exception& e) {
        std::cerr << "writeValue: Failed to get eClass: " << e.what() << std::endl;
        std::cerr.flush();
        return result; 
    } catch(...) { 
        std::cerr << "writeValue: Failed to get eClass: unknown error" << std::endl;
        std::cerr.flush();
        return result; 
    }
    if(!eCls) return result;
    std::shared_ptr<Bag<ecore::EStructuralFeature>> features;
    try {
        features = eCls->getEAllStructuralFeatures();
    } catch(const std::exception& e) {
        std::cerr << "writeValue: Failed to get features: " << e.what() << std::endl;
        std::cerr.flush();
        return result;
    } catch(...) {
        std::cerr << "writeValue: Failed to get features: unknown error" << std::endl;
        std::cerr.flush();
        return result;
    }
    if(!features) return result;
    try {
        for(const auto & feature : *features){
            if(object == nullptr){
                continue;
            }
            std::string featureName; // Declare outside try so catch can access it
            try
            {
            if(!feature) continue;
            try {
                featureName = feature->getName();
            } catch(...) {
                continue; // Skip if we can't get feature name
            }
            if(featureName.empty()) continue;
            
            std::shared_ptr<Any> anyVal;
            try { anyVal = object->eGet(feature); } catch(...) { continue; }
            if(!anyVal) continue;
            auto attributeTypeId = anyVal->getTypeId();
            auto reference = std::dynamic_pointer_cast<EReference>(feature);
            if(reference != nullptr && reference->getEOpposite() != nullptr && !reference->isContainment()){
                continue;
            }
            switch (attributeTypeId) {
                case ecore::ecorePackage::EBOOLEANOBJECT_CLASS:
                case ecore::ecorePackage::EBOOLEAN_CLASS:
                    try { result[featureName] = writeFeature<bool>(object, feature); } catch(...) { result[featureName] = nullptr; }
                    break;
                case ecore::ecorePackage::EBYTE_CLASS:
                case ecore::ecorePackage::EBYTEARRAY_CLASS:
                case ecore::ecorePackage::EBYTEOBJECT_CLASS:
                case ecore::ecorePackage::ECHARACTEROBJECT_CLASS:
                case ecore::ecorePackage::ECHAR_CLASS:
                    try { result[featureName] = writeFeature<char>(object, feature); } catch(...) { result[featureName] = nullptr; }
                    break;
                case ecore::ecorePackage::EDATE_CLASS:
                case ecore::ecorePackage::ERESOURCE_CLASS:
                case ecore::ecorePackage::EINTEGEROBJECT_CLASS:
                case ecore::ecorePackage::EBIGINTEGER_CLASS:
                case ecore::ecorePackage::ESHORT_CLASS:
                case ecore::ecorePackage::ESHORTOBJECT_CLASS:
                case ecore::ecorePackage::EINT_CLASS:
                    try { result[featureName] = writeFeature<int>(object, feature); } catch(...) { result[featureName] = nullptr; }
                    break;
                case ecore::ecorePackage::ELONGOBJECT_CLASS:
                case ecore::ecorePackage::ELONG_CLASS:
                    try { result[featureName] = writeFeature<std::int64_t>(object, feature); } catch(...) { result[featureName] = nullptr; }
                    break;
                case ecore::ecorePackage::EFLOATOBJECT_CLASS:
                case ecore::ecorePackage::EFLOAT_CLASS:
                    try { result[featureName] = writeFeature<float>(object, feature); } catch(...) { result[featureName] = nullptr; }
                    break;
                case ecore::ecorePackage::EBIGDECIMAL_CLASS:
                case ecore::ecorePackage::EDOUBLE_CLASS:
                case ecore::ecorePackage::EDOUBLEOBJECT_CLASS:
                    try { result[featureName] = writeFeature<double>(object, feature); } catch(...) { result[featureName] = nullptr; }
                    break;
                case ecore::ecorePackage::ESTRING_CLASS:
                {
                    try { result[featureName] = writeFeature<std::string>(object, feature); } catch(...) { result[featureName] = nullptr; }
                    break;
                }
                default:
                {
                    // Wrap entire default case in try-catch to prevent any crash
                    try {
                    std::shared_ptr<Any> anyValDefault;
                    try {
                        anyValDefault = object->eGet(feature);
                    } catch(...) {
                        // Skip this feature entirely
                        break;
                    }
                    if(!anyValDefault) { break; }
                    try {
                        if(anyValDefault->isContainer()){
                            try {
                                auto bagPtr = std::dynamic_pointer_cast<EcoreContainerAny>(anyValDefault);
                                if(!bagPtr) { result[featureName] = nullptr; break; }
                                auto bag = bagPtr->getAsEObjectContainer();
                                if(!bag) { result[featureName] = crow::json::wvalue::list(); break; }
                                auto list = crow::json::wvalue::list();
                                size_t bagSize = 0;
                                try {
                                    bagSize = static_cast<size_t>(bag->size());
                                } catch(...) {
                                    bagSize = 0;
                                }
                                for(size_t j=0; j<bagSize && j<500; j++){
                                    try {
                                        if(j < bagSize) {
                                            auto childObj = bag->at(j);
                                            if(childObj) {
                                                list[j] = writeValue(childObj, plugin);
                                            }
                                        }
                                    } catch(const std::exception& e) {
                                        std::cerr << "writeValue: Error serializing container item " << j << ": " << e.what() << std::endl;
                                        std::cerr.flush();
                                        // Continue with next item
                                    } catch(...) {
                                        std::cerr << "writeValue: Unknown error serializing container item " << j << std::endl;
                                        std::cerr.flush();
                                        // Continue with next item
                                    }
                                }
                                if(!featureName.empty()) {
                                    try {
                                        result[featureName] = std::move(list);
                                    } catch(...) {
                                        // Ignore errors setting result
                                    }
                                }
                            } catch(const std::exception& e) {
                                std::cerr << "writeValue: Error processing container feature '" << featureName << "': " << e.what() << std::endl;
                                std::cerr.flush();
                                if(!featureName.empty()) {
                                    try { result[featureName] = crow::json::wvalue::list(); } catch(...) {}
                                }
                            } catch(...) {
                                std::cerr << "writeValue: Unknown error processing container feature '" << featureName << "'" << std::endl;
                                std::cerr.flush();
                                if(!featureName.empty()) {
                                    try { result[featureName] = crow::json::wvalue::list(); } catch(...) {}
                                }
                            }
                            break;
                        }
                    } catch(...) {
                        // If isContainer() itself throws, treat as non-container
                        result[featureName] = nullptr;
                        break;
                    }
                    // Handle primitive types from external packages (e.g. Types.ecore Boolean, Integer)
                    std::string typeName;
                    try {
                        const auto eType = feature->getEType();
                        typeName = (eType && eType->getName().size() > 0) ? eType->getName() : "";
                    } catch(...) {}
                    try {
                        if(!typeName.empty() && (typeName.find("Boolean") != std::string::npos || typeName == "EBoolean"))
                            { try { result[featureName] = writeFeature<bool>(object, feature); } catch(...) { result[featureName] = nullptr; } break; }
                        if(!typeName.empty() && (typeName.find("Int") != std::string::npos || typeName == "Integer" || typeName == "EInt"))
                            { try { result[featureName] = writeFeature<int>(object, feature); } catch(...) { result[featureName] = nullptr; } break; }
                        if(!typeName.empty() && (typeName.find("Long") != std::string::npos || typeName == "ELong"))
                            { try { result[featureName] = writeFeature<std::int64_t>(object, feature); } catch(...) { result[featureName] = nullptr; } break; }
                        if(!typeName.empty() && (typeName.find("Float") != std::string::npos || typeName == "Double" || typeName == "EFloat" || typeName == "EDouble"))
                            { try { result[featureName] = writeFeature<double>(object, feature); } catch(...) { result[featureName] = nullptr; } break; }
                        if(!typeName.empty() && (typeName.find("String") != std::string::npos || typeName == "EString"))
                            { try { result[featureName] = writeFeature<std::string>(object, feature); } catch(...) { result[featureName] = nullptr; } break; }
                    } catch(...) {}
                    // EObject reference - check if feature is actually an EObject reference before casting
                    bool refHandled = false;
                    try {
                        // Check if this is an EReference and if its type is EObject or EObject subclass
                        auto ref = std::dynamic_pointer_cast<EReference>(feature);
                        if(ref && ref->getEType()) {
                            auto eType = ref->getEType();
                            std::string refTypeName;
                            try {
                                refTypeName = eType->getName();
                            } catch(...) {}
                            // Only try to get as EObject if it's actually an EObject type (not enum/primitive)
                            if(!refTypeName.empty() && (refTypeName == "EObject" || refTypeName.find("::") != std::string::npos)) {
                                // #region agent log
                                { std::ofstream log("d:\\DEV\\test2\\MDE4CPP\\.cursor\\debug.log", std::ios::app); log << "{\"sessionId\":\"debug-session\",\"runId\":\"run1\",\"hypothesisId\":\"B\",\"location\":\"writeValue:before_cast\",\"message\":\"Before bad cast attempt\",\"data\":{\"featureName\":\"" << featureName << "\",\"refTypeName\":\"" << refTypeName << "\"},\"timestamp\":" << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() << "}\n"; }
                                // #endregion
                                auto refObj = anyValDefault->get<std::shared_ptr<EObject>>();
                                // #region agent log
                                { std::ofstream log("d:\\DEV\\test2\\MDE4CPP\\.cursor\\debug.log", std::ios::app); log << "{\"sessionId\":\"debug-session\",\"runId\":\"run1\",\"hypothesisId\":\"B\",\"location\":\"writeValue:after_cast\",\"message\":\"After cast attempt\",\"data\":{\"featureName\":\"" << featureName << "\",\"refObj\":\"" << (refObj ? "valid" : "null") << "\"},\"timestamp\":" << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() << "}\n"; }
                                // #endregion
                                if(refObj) { 
                                    try {
                                        if(!featureName.empty()) {
                                            // #region agent log
                                            { std::ofstream log("d:\\DEV\\test2\\MDE4CPP\\.cursor\\debug.log", std::ios::app); log << "{\"sessionId\":\"debug-session\",\"runId\":\"run1\",\"hypothesisId\":\"C\",\"location\":\"writeValue:before_recursive\",\"message\":\"Before recursive writeValue\",\"data\":{\"featureName\":\"" << featureName << "\"},\"timestamp\":" << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() << "}\n"; }
                                            // #endregion
                                            result[featureName] = writeValue(refObj, plugin); 
                                            // #region agent log
                                            { std::ofstream log("d:\\DEV\\test2\\MDE4CPP\\.cursor\\debug.log", std::ios::app); log << "{\"sessionId\":\"debug-session\",\"runId\":\"run1\",\"hypothesisId\":\"C\",\"location\":\"writeValue:after_recursive\",\"message\":\"After recursive writeValue\",\"data\":{\"featureName\":\"" << featureName << "\"},\"timestamp\":" << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() << "}\n"; }
                                            // #endregion
                                            refHandled = true;
                                        }
                                    } catch(...) {
                                        // #region agent log
                                        { std::ofstream log("d:\\DEV\\test2\\MDE4CPP\\.cursor\\debug.log", std::ios::app); log << "{\"sessionId\":\"debug-session\",\"runId\":\"run1\",\"hypothesisId\":\"D\",\"location\":\"writeValue:recursive_exception\",\"message\":\"Exception in recursive writeValue\",\"data\":{\"featureName\":\"" << featureName << "\"},\"timestamp\":" << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() << "}\n"; }
                                        // #endregion
                                        // Skip this feature - serialization failed
                                    }
                                }
                            }
                        }
                    } catch(...) {
                        // #region agent log
                        { std::ofstream log("d:\\DEV\\test2\\MDE4CPP\\.cursor\\debug.log", std::ios::app); log << "{\"sessionId\":\"debug-session\",\"runId\":\"run1\",\"hypothesisId\":\"B\",\"location\":\"writeValue:cast_exception\",\"message\":\"Bad cast exception caught\",\"data\":{\"featureName\":\"" << featureName << "\"},\"timestamp\":" << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() << "}\n"; }
                        // #endregion
                        // Not an EObject reference or cast failed - skip this feature entirely
                    }
                    if(!refHandled) {
                        // Feature was not an EObject reference or failed to serialize - skip it
                        break;
                    }
                    break;
                    } catch(...) {
                        // If anything fails in default case, skip the feature entirely
                        break;
                    }
                }
            }
        }
            catch(...)
            {
                // Never crash the whole request because of one bad feature cast.
                if(!featureName.empty()) {
                    try { result[featureName] = nullptr; } catch(...) {}
                }
                continue;
            }
        }
    } catch(const std::exception& e) {
        std::cerr << "writeValue: Exception during feature iteration: " << e.what() << std::endl;
        std::cerr.flush();
        // Return partial result rather than crashing
    } catch(...) {
        std::cerr << "writeValue: Unknown exception during feature iteration" << std::endl;
        std::cerr.flush();
        // #region agent log
        { std::ofstream log("d:\\DEV\\test2\\MDE4CPP\\.cursor\\debug.log", std::ios::app); log << "{\"sessionId\":\"debug-session\",\"runId\":\"run1\",\"hypothesisId\":\"D\",\"location\":\"writeValue:outer_exception\",\"message\":\"Outer exception caught\",\"timestamp\":" << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() << "}\n"; }
        // #endregion
        // Return partial result rather than crashing
    }
    // #region agent log
    { std::ofstream log("d:\\DEV\\test2\\MDE4CPP\\.cursor\\debug.log", std::ios::app); log << "{\"sessionId\":\"debug-session\",\"runId\":\"run1\",\"hypothesisId\":\"E\",\"location\":\"writeValue:exit\",\"message\":\"writeValue exit\",\"timestamp\":" << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() << "}\n"; }
    // #endregion
    return result;
}

template<typename T>
crow::json::wvalue GenericApi::writeFeature(const std::shared_ptr<EObject> &object, const std::shared_ptr<EStructuralFeature> &feature) {
    if(!object || !feature) return crow::json::wvalue();
    std::shared_ptr<Any> anyVal;
    try { anyVal = object->eGet(feature); } catch(...) { return crow::json::wvalue(); }
    if(!anyVal) return crow::json::wvalue();
    auto isContainer = anyVal->isContainer();
    if(isContainer){
        try {
            auto bag = anyVal->get<std::shared_ptr<Bag<T>>>();
            if(!bag) return crow::json::wvalue::list();
            auto list = crow::json::wvalue::list();
            for (size_t j=0; j<static_cast<size_t>(bag->size()) && j<500; j++) {
                try { list[j] = bag->at(j).get(); } catch(...) {}
            }
            return list;
        } catch(...) { return crow::json::wvalue::list(); }
    }
	// Scalar: be defensive about Any's stored type.
	const auto any = anyVal;
	if(!any || any->isEmpty())
	{
		return crow::json::wvalue();
	}
	try
	{
		return crow::json::wvalue(any->get<T>());
	}
	catch(...)
	{
		// Try common numeric fallbacks
		try { return crow::json::wvalue(static_cast<std::int64_t>(any->get<std::int64_t>())); } catch(...) {}
		try { return crow::json::wvalue(static_cast<std::int64_t>(any->get<int>())); } catch(...) {}
		try { return crow::json::wvalue(static_cast<double>(any->get<double>())); } catch(...) {}
		try { return crow::json::wvalue(static_cast<double>(any->get<float>())); } catch(...) {}
		try { return crow::json::wvalue(static_cast<bool>(any->get<bool>())); } catch(...) {}
		try { return crow::json::wvalue(any->get<std::string>()); } catch(...) {}
		return crow::json::wvalue(any->toString());
	}
}

std::shared_ptr<ecore::EObject> GenericApi::readValue(const crow::json::rvalue& content, const std::string& eClass, const std::shared_ptr<MDE4CPPPlugin>& plugin){
	std::shared_ptr<ecore::EObject> result = nullptr;

	// Prefer plugin-provided creation (often returns generated class with real behavior).
	// Some plugins return nullptr here, so we fall back to Ecore factory creation.
	result = plugin->create(eClass);

	if(!result)
	{
		// Fallback: Ecore factory creation
		const std::string simpleClassName = (eClass.find("::") == std::string::npos)
			? eClass
			: eClass.substr(eClass.rfind("::") + 2);

		if(const auto ecorePlugin = std::dynamic_pointer_cast<EcoreModelPlugin>(plugin))
	{
		try
		{
			const auto pkg = ecorePlugin->getEPackage();
			const auto factory = (pkg ? pkg->getEFactoryInstance() : nullptr);
			const auto fallbackFactory = ecorePlugin->getEFactory();
			const auto effectiveFactory = factory ? factory : fallbackFactory;
			if(effectiveFactory && pkg)
			{
				std::shared_ptr<ecore::EClass> metaClass = nullptr;
				const auto eClassifiers = pkg->getEClassifiers();
				if(eClassifiers)
				{
					for(auto it = eClassifiers->cbegin(); it != eClassifiers->cend(); ++it)
					{
						const auto c = *it;
						if(!c) continue;
						if(c->getName() != simpleClassName) continue;
						metaClass = std::dynamic_pointer_cast<ecore::EClass>(c);
						break;
					}
				}
				if(metaClass)
				{
					result = effectiveFactory->create(metaClass);
				}
			}
		}
		catch(...)
		{
			// fall back below
		}
	}
	}
	if(!result){
		throw std::runtime_error(std::string("create failed for class: ") + eClass);
	}

	const auto resultClass = result->eClass();
	if(!resultClass){
		throw std::runtime_error(std::string("created object has no eClass for: ") + eClass);
	}
    const auto features = resultClass->getEAllStructuralFeatures();
	if(!features){
		return result;
	}
    for(const auto & feature : *features){
        try {
            auto value = content[feature->getName()];
            if(value.t() == crow::json::type::Null){
                continue;
            }
        } catch (std::runtime_error& error){
            continue;
        }
        std::shared_ptr<Any> featureValue;
        try {
            featureValue = result->eGet(feature);
        } catch(...) {
            continue;
        }
        if(!featureValue) {
            continue;
        }
        auto attributeTypeId = featureValue->getTypeId();
        auto reference = std::dynamic_pointer_cast<EReference>(feature);
        if(reference != nullptr && reference->getEOpposite() != nullptr && !reference->isContainment()){
            continue;
        }
        switch (attributeTypeId) {
            case ecore::ecorePackage::EBOOLEANOBJECT_CLASS:
            case ecore::ecorePackage::EBOOLEAN_CLASS:
                try { result->eSet(feature, readFeature<bool>(result, feature, content)); } catch(...) {}
                break;
            case ecore::ecorePackage::EBYTE_CLASS:
            case ecore::ecorePackage::EBYTEARRAY_CLASS:
            case ecore::ecorePackage::EBYTEOBJECT_CLASS:
            case ecore::ecorePackage::ECHARACTEROBJECT_CLASS:
            case ecore::ecorePackage::ECHAR_CLASS:
                try { result->eSet(feature, readFeature<char>(result, feature, content)); } catch(...) {}
                break;
            case ecore::ecorePackage::EDATE_CLASS:
            case ecore::ecorePackage::ERESOURCE_CLASS:
            case ecore::ecorePackage::EINTEGEROBJECT_CLASS:
            case ecore::ecorePackage::EBIGINTEGER_CLASS:
            case ecore::ecorePackage::ESHORT_CLASS:
            case ecore::ecorePackage::ESHORTOBJECT_CLASS:
            case ecore::ecorePackage::EINT_CLASS:
                try { result->eSet(feature, readFeature<int>(result, feature, content)); } catch(...) {}
                break;
            case ecore::ecorePackage::ELONGOBJECT_CLASS:
            case ecore::ecorePackage::ELONG_CLASS:
                try { result->eSet(feature, readFeature<std::int64_t>(result, feature, content)); } catch(...) {}
                break;
            case ecore::ecorePackage::EFLOATOBJECT_CLASS:
            case ecore::ecorePackage::EFLOAT_CLASS:
                try { result->eSet(feature, readFeature<float>(result, feature, content)); } catch(...) {}
                break;
            case ecore::ecorePackage::EBIGDECIMAL_CLASS:
            case ecore::ecorePackage::EDOUBLE_CLASS:
            case ecore::ecorePackage::EDOUBLEOBJECT_CLASS:
                try { result->eSet(feature, readFeature<double>(result, feature, content)); } catch(...) {}
                break;
            case ecore::ecorePackage::ESTRING_CLASS:
                try { result->eSet(feature, readFeature<std::string>(result, feature, content)); } catch(...) {}
                break;
            default:
            {
                if(featureValue->isContainer()){
                    auto bag = std::make_shared<Bag<EObject>>();
                    try {
                        for(const auto & entry : content[feature->getName()]){
                            try {
                                auto eType = feature->getEType();
                                if(eType) {
                                    bag->add(readValue(entry, eType->getName(), plugin));
                                }
                            } catch(...) {}
                        }
                    } catch(...) {}
                    try {
                        result->eSet(feature, eEcoreContainerAny(bag, attributeTypeId));
                    } catch(...) {}
                    break;
                }
                try {
                    auto eType = feature->getEType();
                    if(eType) {
                        auto value = readValue(content[feature->getName()], eType->getName(), plugin);
                        if(value) {
                            result->eSet(feature, eAny(value, attributeTypeId, false));
                        }
                    }
                } catch(...) {}
                break;
            }
        }
    }
    return result;
}

void GenericApi::applyPropertiesToObject(const std::shared_ptr<ecore::EObject>& object, const crow::json::rvalue& content, const std::shared_ptr<MDE4CPPPlugin>& plugin){
    if(!object || !plugin || !content || content.t() != crow::json::type::Object) return;
    std::shared_ptr<ecore::EClass> eCls;
    try { eCls = object->eClass(); } catch(...) { return; }
    if(!eCls) return;
    auto features = eCls->getEAllStructuralFeatures();
    if(!features) return;
    for(const auto& feature : *features){
        try {
            auto value = content[feature->getName()];
            if(value.t() == crow::json::type::Null) continue;
        } catch(...) { continue; }
        std::shared_ptr<Any> featureValue;
        try {
            featureValue = object->eGet(feature);
        } catch(...) { continue; }
        if(!featureValue) continue;
        auto attributeTypeId = featureValue->getTypeId();
        auto reference = std::dynamic_pointer_cast<EReference>(feature);
        if(reference && reference->getEOpposite() && !reference->isContainment()) continue;
        try {
            switch(attributeTypeId){
                case ecore::ecorePackage::EBOOLEANOBJECT_CLASS:
                case ecore::ecorePackage::EBOOLEAN_CLASS:
                    object->eSet(feature, readFeature<bool>(object, feature, content)); break;
                case ecore::ecorePackage::EINTEGEROBJECT_CLASS:
                case ecore::ecorePackage::EBIGINTEGER_CLASS:
                case ecore::ecorePackage::ESHORT_CLASS:
                case ecore::ecorePackage::ESHORTOBJECT_CLASS:
                case ecore::ecorePackage::EINT_CLASS:
                    object->eSet(feature, readFeature<int>(object, feature, content)); break;
                case ecore::ecorePackage::ELONGOBJECT_CLASS:
                case ecore::ecorePackage::ELONG_CLASS:
                    object->eSet(feature, readFeature<std::int64_t>(object, feature, content)); break;
                case ecore::ecorePackage::EFLOATOBJECT_CLASS:
                case ecore::ecorePackage::EFLOAT_CLASS:
                    object->eSet(feature, readFeature<float>(object, feature, content)); break;
                case ecore::ecorePackage::EDOUBLE_CLASS:
                case ecore::ecorePackage::EDOUBLEOBJECT_CLASS:
                    object->eSet(feature, readFeature<double>(object, feature, content)); break;
                case ecore::ecorePackage::ESTRING_CLASS:
                    object->eSet(feature, readFeature<std::string>(object, feature, content)); break;
                default:{
                    std::string typeName;
                    try {
                        auto eType = feature->getEType();
                        typeName = (eType && !eType->getName().empty()) ? eType->getName() : "";
                    } catch(...) {}
                    if(!typeName.empty()){
                        if(typeName.find("Boolean") != std::string::npos || typeName == "EBoolean"){
                            object->eSet(feature, readFeature<bool>(object, feature, content)); break;
                        }
                        if(typeName.find("Int") != std::string::npos || typeName == "Integer" || typeName == "EInt"){
                            object->eSet(feature, readFeature<int>(object, feature, content)); break;
                        }
                        if(typeName.find("Long") != std::string::npos || typeName == "ELong"){
                            object->eSet(feature, readFeature<std::int64_t>(object, feature, content)); break;
                        }
                        if(typeName.find("Float") != std::string::npos || typeName.find("Double") != std::string::npos){
                            object->eSet(feature, readFeature<double>(object, feature, content)); break;
                        }
                        if(typeName.find("String") != std::string::npos || typeName == "EString"){
                            object->eSet(feature, readFeature<std::string>(object, feature, content)); break;
                        }
                    }
                    if(object->eGet(feature)->isContainer()){
                        try {
                            auto bag = std::make_shared<Bag<EObject>>();
                            for(const auto& entry : content[feature->getName()]){
                                bag->add(readValue(entry, feature->getEType()->getName(), plugin));
                            }
                            object->eSet(feature, eEcoreContainerAny(bag, attributeTypeId));
                        } catch(...) {}
                    } else {
                        try {
                            auto val = content[feature->getName()];
                            if(val.t() == crow::json::type::String){
                                std::string s = val.s();
                                std::shared_ptr<ecore::EObject> refObj;
                                { std::lock_guard<std::mutex> lock(m_objectsMutex);
                                    auto it = m_objects.find(s);
                                    if(it != m_objects.end()) refObj = it->second.object;
                                }
                                if(refObj) object->eSet(feature, eAny(refObj, attributeTypeId, false));
                            } else {
                                auto v = readValue(content[feature->getName()], feature->getEType()->getName(), plugin);
                                if(v) object->eSet(feature, eAny(v, attributeTypeId, false));
                            }
                        } catch(...) {}
                    }
                    break;
                }
            }
        } catch(...) {}
    }
}

//generic conversion methods for json
template<> bool GenericApi::convert_to<bool>(const crow::json::rvalue& value){
    switch(value.t()){
        case crow::json::type::True:  return true;
        case crow::json::type::False: return false;
        case crow::json::type::Null:  return false;
        case crow::json::type::Number: return value.d() != 0.0;
        case crow::json::type::String: {
            const std::string s = value.s();
            return (s == "true" || s == "True" || s == "1");
        }
        default: return false;
    }
}
template <typename T> T GenericApi::convert_to(const crow::json::rvalue& value){
    std::istringstream ss(value.operator std::string());
    T num;
    ss >> num;
    return num;
}

template<typename T>
std::shared_ptr<Any> GenericApi::readFeature(const std::shared_ptr<EObject>& object, const std::shared_ptr<EStructuralFeature>& feature, const crow::json::rvalue& content){
    auto attributeTypeId = object->eGet(feature)->getTypeId();
    auto isContainer = object->eGet(feature)->isContainer();
    try {
        auto val = content[feature->getName()];
        if(val.t() == crow::json::type::Null) {
            return object->eGet(feature);
        }
        if(isContainer){
            auto bag = object->eGet(feature)->get<std::shared_ptr<Bag<T>>>();
            for(const auto & entry : val){
                auto value = std::make_shared<T>(convert_to<T>(entry));
                bag->add(value);
            }
            return eAny(bag, attributeTypeId, true);
        }
        return eAny(convert_to<T>(val), attributeTypeId, false);
    } catch(...) {
        return object->eGet(feature);
    }
}

/*getter for single MDE4CPPPlugin from m_plugins
* @name string : name of the plugin (usualy name of model)
* @return shared_ptr<MDE4CPPPlugin> : nullptr if plugin with name was not found 
*/
std::shared_ptr<MDE4CPPPlugin> GenericApi::getPlugin(std::string name){
	if(m_plugins.find(name) != m_plugins.end()){
		return m_plugins.find(name)->second; //plugin found
	}
	return nullptr; //plugin not found
}

/*populates m_plugin with shared_ptr to MDE4CPPPlugins found in the current directory 
*/
void GenericApi::mapPlugins(){
	m_plugins.clear(); //clears map before inserting -> can be used for refreshing m_plugins without restarting application
    std::shared_ptr<Bag<MDE4CPPPlugin>> plugins = m_pluginFramework->getAllPlugins();
	for(std::shared_ptr<MDE4CPPPlugin>& plugin : *plugins){
		m_plugins.insert({plugin->eNAME(),plugin});
		CROW_LOG_INFO << "found plugin " << plugin->eNAME(); //outputs found plugins as INFO msg
	}
}
