#define CROW_JSON_USE_MAP
#include "MDE4CPP_PluginAPI.hpp"

#include <functional>

#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"

#include "pluginFramework/MDE4CPPPlugin.hpp"
#include "abstractDataTypes/Bag.hpp"

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
    static std::shared_ptr<GenericApi> instance = std::make_shared<GenericApi>(GenericApi(pluginFramework));
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
			if(m_objects.find(objectName) != m_objects.end()){
				return crow::response(400, "Object already exists!");
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
			m_objects[objectName] = StoredObject{plugin_name, className, object};
			return crow::response(201);
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

    //Read function
    CROW_ROUTE(app, "/<string>/objects/<string>/<string>").methods(crow::HTTPMethod::Get)([this](const std::string& plugin_name, const std::string& className, const std::string& objectName){
        auto it = m_objects.find(objectName);
        if(it == m_objects.end()){
            return crow::response(404);
        }
		if(it->second.pluginName != plugin_name){
			return crow::response(404);
		}
		
		const std::shared_ptr<MDE4CPPPlugin>& plugin = getPlugin(plugin_name);
		if(plugin == nullptr){
			return crow::response(404, "Plugin not found!");
		}
		
        auto result = writeValue(it->second.object, plugin);
        return crow::response(200, result);
    });

    //Update function
    CROW_ROUTE(app, "/<string>/objects/<string>/<string>").methods(crow::HTTPMethod::Put)([this](const crow::request& request, const std::string& plugin_name, const std::string& className, const std::string& objectName){
		try
		{
			auto it = m_objects.find(objectName);
			if(it == m_objects.end()){
				return crow::response(404);
			}
			if(it->second.pluginName != plugin_name){
				return crow::response(404);
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
			m_objects[objectName] = StoredObject{plugin_name, className, object};
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
        auto it = m_objects.find(objectName);
        if(it == m_objects.end()){
            return crow::response(404);
        }
		if(it->second.pluginName != plugin_name){
			return crow::response(404);
		}
		
		const std::shared_ptr<MDE4CPPPlugin>& plugin = getPlugin(plugin_name);
		if(plugin == nullptr){
			return crow::response(404, "Plugin not found!");
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
		
        for(const auto & entry : crow::json::load(request.body)){
			const auto id = entry["ecore_identifier"].s();
			const auto type = entry["ecore_type"].s();
            auto object = readValue(entry, type, plugin);
            m_objects[id] = StoredObject{plugin_name, type, object};
        }
        return crow::response(201);
    });

    //Get instance model
    CROW_ROUTE(app, "/<string>/objects/").methods(crow::HTTPMethod::Get)([this](const std::string& plugin_name){
		
		const std::shared_ptr<MDE4CPPPlugin>& plugin = getPlugin(plugin_name);
		if(plugin == nullptr){
			return crow::response(404, "Plugin not found!");
		}
		
        crow::json::wvalue result;
        int i = 0;
        for(const auto & entry : m_objects){
			if(entry.second.pluginName != plugin_name){
				continue;
			}
            auto wvalue = writeValue(entry.second.object, plugin);
            wvalue["ecore_identifier"] = entry.first;
            wvalue["ecore_type"] = entry.second.object->eClass()->getName();
            result[i] = std::move(wvalue);
            i++;
        }
        return crow::response(200, result);
    });

	// Global object list (for backend aggregation)
	// Returns: [{ "name": "<objectName>", "plugin": "<pluginName>", "type": "<className>" }, ...]
	CROW_ROUTE(app, "/objects").methods(crow::HTTPMethod::Get)([this](){
		auto list = crow::json::wvalue::list();
		for(const auto& entry : m_objects)
		{
			crow::json::wvalue item;
			item["name"] = entry.first;
			item["plugin"] = entry.second.pluginName;
			item["type"] = entry.second.className;
			list.push_back(std::move(item));
		}
		crow::json::wvalue result = crow::json::wvalue(list);
		return crow::response(200, result);
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

    app.bindaddr("127.0.0.1").port(8080).multithreaded().run(); //sets address and port  //TODO let user assign adress and port 
}

crow::json::wvalue GenericApi::writeValue(const std::shared_ptr<ecore::EObject>& object, const std::shared_ptr<MDE4CPPPlugin>& plugin){
    auto result = crow::json::wvalue();
    auto features = object->eClass()->getEAllStructuralFeatures();
    for(const auto & feature : *features){
        if(object == nullptr){
            continue;
        }
        auto attributeTypeId = object->eGet(feature)->getTypeId();
        auto reference = std::dynamic_pointer_cast<EReference>(feature);
        if(reference != nullptr && reference->getEOpposite() != nullptr && !reference->isContainment()){
            continue;
        }
        switch (attributeTypeId) {
            case ecore::ecorePackage::EBOOLEANOBJECT_CLASS:
            case ecore::ecorePackage::EBOOLEAN_CLASS:
                result[feature->getName()] = writeFeature<bool>(object, feature);
                break;
            case ecore::ecorePackage::EBYTE_CLASS:
            case ecore::ecorePackage::EBYTEARRAY_CLASS:
            case ecore::ecorePackage::EBYTEOBJECT_CLASS:
            case ecore::ecorePackage::ECHARACTEROBJECT_CLASS:
            case ecore::ecorePackage::ECHAR_CLASS:
                result[feature->getName()] = writeFeature<char>(object, feature);
                break;
            case ecore::ecorePackage::EDATE_CLASS:
            case ecore::ecorePackage::ERESOURCE_CLASS:
            case ecore::ecorePackage::EINTEGEROBJECT_CLASS:
            case ecore::ecorePackage::EBIGINTEGER_CLASS:
            case ecore::ecorePackage::ESHORT_CLASS:
            case ecore::ecorePackage::ESHORTOBJECT_CLASS:
            case ecore::ecorePackage::EINT_CLASS:
                result[feature->getName()] = writeFeature<int>(object, feature);
                break;
            case ecore::ecorePackage::ELONGOBJECT_CLASS:
            case ecore::ecorePackage::ELONG_CLASS:
                result[feature->getName()] = writeFeature<int>(object, feature);
                break;
            case ecore::ecorePackage::EFLOATOBJECT_CLASS:
            case ecore::ecorePackage::EFLOAT_CLASS:
                result[feature->getName()] = writeFeature<float>(object, feature);
                break;
            case ecore::ecorePackage::EBIGDECIMAL_CLASS:
            case ecore::ecorePackage::EDOUBLE_CLASS:
            case ecore::ecorePackage::EDOUBLEOBJECT_CLASS:
                result[feature->getName()] = writeFeature<bool>(object, feature);
                break;
            case ecore::ecorePackage::ESTRING_CLASS:
            {
                result[feature->getName()] = writeFeature<std::string>(object, feature);
                break;
            }
            default:
            {
                if(object->eGet(feature)->isContainer()){
                    auto list = crow::json::wvalue();
                    auto bag = std::dynamic_pointer_cast<EcoreContainerAny>(object->eGet(feature))->getAsEObjectContainer();
                    for(int j=0;j<bag->size();j++){
                        list[j] = writeValue(bag->at(j),plugin);
                    }
                    result[feature->getName()] = std::move(list);
                    break;
                }
                auto value = writeValue(object->eGet(feature)->get<std::shared_ptr<EObject>>(),plugin);
                result[feature->getName()] = std::move(value);
                break;
            }
        }
    }
    return result;
}

template<typename T>
crow::json::wvalue GenericApi::writeFeature(const std::shared_ptr<EObject> &object, const std::shared_ptr<EStructuralFeature> &feature) {
    auto isContainer = object->eGet(feature)->isContainer();
    if(isContainer){
        auto list = crow::json::wvalue();
        auto bag = object->eGet(feature)->get<std::shared_ptr<Bag<T>>>();
        for (int j=0;j<bag->size();j++) {
            auto value = bag->at(j).get();
            list[j] = value;
        }
        return list;
    }
    return crow::json::wvalue(object->eGet(feature)->get<T>());
}

std::shared_ptr<ecore::EObject> GenericApi::readValue(const crow::json::rvalue& content, const std::string& eClass, const std::shared_ptr<MDE4CPPPlugin>& plugin){
	std::shared_ptr<ecore::EObject> result = nullptr;

	// Prefer Ecore factory creation (plugin->create() appears to return nullptr for some plugins)
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
						if(c->getName() != eClass) continue;
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

	if(!result)
	{
		result = plugin->create(eClass);
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
        auto attributeTypeId = result->eGet(feature)->getTypeId();
        auto reference = std::dynamic_pointer_cast<EReference>(feature);
        if(reference != nullptr && reference->getEOpposite() != nullptr && !reference->isContainment()){
            continue;
        }
        switch (attributeTypeId) {
            case ecore::ecorePackage::EBOOLEANOBJECT_CLASS:
            case ecore::ecorePackage::EBOOLEAN_CLASS:
                result->eSet(feature, readFeature<bool>(result, feature, content));
                break;
            case ecore::ecorePackage::EBYTE_CLASS:
            case ecore::ecorePackage::EBYTEARRAY_CLASS:
            case ecore::ecorePackage::EBYTEOBJECT_CLASS:
            case ecore::ecorePackage::ECHARACTEROBJECT_CLASS:
            case ecore::ecorePackage::ECHAR_CLASS:
                result->eSet(feature, readFeature<char>(result, feature, content));
                break;
            case ecore::ecorePackage::EDATE_CLASS:
            case ecore::ecorePackage::ERESOURCE_CLASS:
            case ecore::ecorePackage::EINTEGEROBJECT_CLASS:
            case ecore::ecorePackage::EBIGINTEGER_CLASS:
            case ecore::ecorePackage::ESHORT_CLASS:
            case ecore::ecorePackage::ESHORTOBJECT_CLASS:
            case ecore::ecorePackage::EINT_CLASS:
                result->eSet(feature, readFeature<int>(result, feature, content));
                break;
            case ecore::ecorePackage::ELONGOBJECT_CLASS:
            case ecore::ecorePackage::ELONG_CLASS:
                result->eSet(feature, readFeature<long>(result, feature, content));
                break;
            case ecore::ecorePackage::EFLOATOBJECT_CLASS:
            case ecore::ecorePackage::EFLOAT_CLASS:
                result->eSet(feature, readFeature<float>(result, feature, content));
                break;
            case ecore::ecorePackage::EBIGDECIMAL_CLASS:
            case ecore::ecorePackage::EDOUBLE_CLASS:
            case ecore::ecorePackage::EDOUBLEOBJECT_CLASS:
                result->eSet(feature, readFeature<double>(result, feature, content));
                break;
            case ecore::ecorePackage::ESTRING_CLASS:
                result->eSet(feature, readFeature<std::string>(result, feature, content));
                break;
            default:
            {
                if(result->eGet(feature)->isContainer()){
                    auto bag = std::make_shared<Bag<EObject>>();
                    for(const auto & entry : content[feature->getName()]){
                        bag->add(readValue(entry, feature->getEType()->getName(), plugin));
                    }
                    result->eSet(feature, eEcoreContainerAny(bag, attributeTypeId));
                    break;
                }
                auto value = readValue(content[feature->getName()], feature->getEType()->getName(), plugin);
                result->eSet(feature, eAny(value, attributeTypeId, false));
                break;
            }
        }
    }
    return result;
}

//generic conversion methods for json
template<> bool GenericApi::convert_to<bool>(const crow::json::rvalue& value){
    return value.b();
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
    if(isContainer){
        auto bag = object->eGet(feature)->get<std::shared_ptr<Bag<T>>>();
        for(const auto & entry : content[feature->getName()]){
            auto value = std::make_shared<T>(convert_to<T>(entry));
            bag->add(value);
        }
        return eAny(bag, attributeTypeId, true);
    }
    return eAny(convert_to<T>(content[feature->getName()]), attributeTypeId, false);
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
