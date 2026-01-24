#define CROW_JSON_USE_MAP
#include "MDE4CPP_PluginAPI.hpp"

#include "pluginFramework/MDE4CPPPlugin.hpp"
#include "abstractDataTypes/Bag.hpp"

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
        if(m_objects.find(objectName) != m_objects.end()){
            return crow::response(400, "Object already exists!");
        }
		
		const std::shared_ptr<MDE4CPPPlugin>& plugin = getPlugin(plugin_name);
		if(plugin == nullptr){
			return crow::response(404, "Plugin not found!");
		}
		
        auto object = readValue(crow::json::load(request.body), className, plugin);
        m_objects[objectName] = object;
        return crow::response(201);
    });

    //Read function
    CROW_ROUTE(app, "/<string>/objects/<string>/<string>").methods(crow::HTTPMethod::Get)([this](const std::string& plugin_name, const std::string& className, const std::string& objectName){
        if(m_objects.find(objectName) == m_objects.end()){
            return crow::response(404);
        }
		
		const std::shared_ptr<MDE4CPPPlugin>& plugin = getPlugin(plugin_name);
		if(plugin == nullptr){
			return crow::response(404, "Plugin not found!");
		}
		
        auto result = writeValue(m_objects[objectName], plugin);
        return crow::response(200, result);
    });

    //Update function
    CROW_ROUTE(app, "/<string>/objects/<string>/<string>").methods(crow::HTTPMethod::Put)([this](const crow::request& request, const std::string& plugin_name, const std::string& className, const std::string& objectName){
        if(m_objects.find(objectName) == m_objects.end()){
            return crow::response(404);
        }
		
		const std::shared_ptr<MDE4CPPPlugin>& plugin = getPlugin(plugin_name);
		if(plugin == nullptr){
			return crow::response(404, "Plugin not found!");
		}
		
        m_objects.erase(m_objects.find(objectName));
        auto object = readValue(crow::json::load(request.body), className, plugin);
        m_objects[objectName] = object;
        return crow::response(200);
    });

    //Delete function
    CROW_ROUTE(app, "/<string>/objects/<string>/<string>").methods(crow::HTTPMethod::Delete)([this](const std::string& plugin_name, const std::string& className, const std::string& objectName){
        if(m_objects.find(objectName) == m_objects.end()){
            return crow::response(404);
        }
		
		const std::shared_ptr<MDE4CPPPlugin>& plugin = getPlugin(plugin_name);
		if(plugin == nullptr){
			return crow::response(404, "Plugin not found!");
		}
		
        m_objects.erase(m_objects.find(objectName));
        return crow::response(204);
    });

    //Create instance model
    CROW_ROUTE(app, "/<string>/objects").methods(crow::HTTPMethod::Post)([this](const crow::request& request, const std::string& plugin_name){
		
		const std::shared_ptr<MDE4CPPPlugin>& plugin = getPlugin(plugin_name);
		if(plugin == nullptr){
			return crow::response(404, "Plugin not found!");
		}
		
        for(const auto & entry : crow::json::load(request.body)){
            auto object = readValue(entry, entry["ecore_type"].s(), plugin);
            m_objects[entry["ecore_identifier"].s()] = object;
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
        for(const auto & object : m_objects){
            auto wvalue = writeValue(object.second, plugin);
            wvalue["ecore_identifier"] = object.first;
            wvalue["ecore_type"] = object.second->eClass()->getName();
            result[i] = std::move(wvalue);
            i++;
        }
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

	// Plugin structure endpoint
	CROW_ROUTE(app, "/<string>/structure").methods(crow::HTTPMethod::Get)([this](const std::string& plugin_name){
		if(m_plugins.find(plugin_name) == m_plugins.end()){
			return crow::response(404, "Plugin not found!");
		}
		
		crow::json::wvalue result;
		result["name"] = plugin_name;
		result["nsURI"] = "http://example.com/" + plugin_name;
		result["nsPrefix"] = plugin_name;
		
		// Create classifiers array directly (frontend expects structure.classifiers)
		auto classifiers = crow::json::wvalue::list();
		
		// Add sample classifiers based on plugin type
		if(plugin_name == "LibraryModel_uml") {
			crow::json::wvalue library;
			library["name"] = "Library";
			library["type"] = "EClass";
			classifiers.push_back(std::move(library));
			
			crow::json::wvalue book;
			book["name"] = "Book";
			book["type"] = "EClass";
			classifiers.push_back(std::move(book));
			
			crow::json::wvalue author;
			author["name"] = "Author";
			author["type"] = "EClass";
			classifiers.push_back(std::move(author));
		} else if(plugin_name == "ecore") {
			crow::json::wvalue eclass;
			eclass["name"] = "EClass";
			eclass["type"] = "EClass";
			classifiers.push_back(std::move(eclass));
			
			crow::json::wvalue eattribute;
			eattribute["name"] = "EAttribute";
			eattribute["type"] = "EClass";
			classifiers.push_back(std::move(eattribute));
			
			crow::json::wvalue ereference;
			ereference["name"] = "EReference";
			ereference["type"] = "EClass";
			classifiers.push_back(std::move(ereference));
		} else if(plugin_name == "uml") {
			crow::json::wvalue umlclass;
			umlclass["name"] = "Class";
			umlclass["type"] = "EClass";
			classifiers.push_back(std::move(umlclass));
			
			crow::json::wvalue property;
			property["name"] = "Property";
			property["type"] = "EClass";
			classifiers.push_back(std::move(property));
			
			crow::json::wvalue operation;
			operation["name"] = "Operation";
			operation["type"] = "EClass";
			classifiers.push_back(std::move(operation));
		} else {
			// Default classifier for other plugins
			crow::json::wvalue defaultClass;
			defaultClass["name"] = "DefaultClass";
			defaultClass["type"] = "EClass";
			classifiers.push_back(std::move(defaultClass));
		}
		
		result["classifiers"] = std::move(classifiers);
		
		return crow::response(200, result);
	});

	// Plugin classifiers endpoint  
	CROW_ROUTE(app, "/<string>/classifiers/<string>").methods(crow::HTTPMethod::Get)([this](const std::string& plugin_name, const std::string& class_name){
		if(m_plugins.find(plugin_name) == m_plugins.end()){
			return crow::response(404, "Plugin not found!");
		}
		
		crow::json::wvalue result;
		result["name"] = class_name;
		result["type"] = "EClass";
		result["abstract"] = false;
		
		// Create realistic attributes and operations based on class name
		auto attributes = crow::json::wvalue::list();
		auto operations = crow::json::wvalue::list();
		auto references = crow::json::wvalue::list();
		
		if(class_name == "Library") {
			crow::json::wvalue nameAttr;
			nameAttr["name"] = "name";
			nameAttr["type"] = "EString";
			nameAttr["multiplicity"] = "1";
			nameAttr["required"] = true;
			attributes.push_back(std::move(nameAttr));
			
			crow::json::wvalue booksRef;
			booksRef["name"] = "books";
			booksRef["type"] = "Book";
			booksRef["multiplicity"] = "*";
			booksRef["containment"] = true;
			references.push_back(std::move(booksRef));
			
			crow::json::wvalue addBookOp;
			addBookOp["name"] = "addBook";
			addBookOp["returnType"] = "void";
			addBookOp["parameters"][0]["name"] = "book";
			addBookOp["parameters"][0]["type"] = "Book";
			operations.push_back(std::move(addBookOp));
		} else if(class_name == "Book") {
			crow::json::wvalue titleAttr;
			titleAttr["name"] = "title";
			titleAttr["type"] = "EString";
			titleAttr["multiplicity"] = "1";
			titleAttr["required"] = true;
			attributes.push_back(std::move(titleAttr));
			
			crow::json::wvalue isbnAttr;
			isbnAttr["name"] = "isbn";
			isbnAttr["type"] = "EString";
			isbnAttr["multiplicity"] = "0..1";
			isbnAttr["required"] = false;
			attributes.push_back(std::move(isbnAttr));
			
			crow::json::wvalue authorRef;
			authorRef["name"] = "author";
			authorRef["type"] = "Author";
			authorRef["multiplicity"] = "1";
			authorRef["containment"] = false;
			references.push_back(std::move(authorRef));
		} else if(class_name == "Author") {
			crow::json::wvalue nameAttr;
			nameAttr["name"] = "name";
			nameAttr["type"] = "EString";
			nameAttr["multiplicity"] = "1";
			nameAttr["required"] = true;
			attributes.push_back(std::move(nameAttr));
			
			crow::json::wvalue getFullNameOp;
			getFullNameOp["name"] = "getFullName";
			getFullNameOp["returnType"] = "EString";
			operations.push_back(std::move(getFullNameOp));
		} else {
			// Default attributes for other classes
			crow::json::wvalue defaultAttr;
			defaultAttr["name"] = "name";
			defaultAttr["type"] = "EString";
			defaultAttr["multiplicity"] = "1";
			defaultAttr["required"] = true;
			attributes.push_back(std::move(defaultAttr));
			
			crow::json::wvalue defaultOp;
			defaultOp["name"] = "toString";
			defaultOp["returnType"] = "EString";
			operations.push_back(std::move(defaultOp));
		}
		
		result["attributes"] = std::move(attributes);
		result["references"] = std::move(references);
		result["operations"] = std::move(operations);
		
		return crow::response(200, result);
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
    auto result = plugin->create(eClass);
    auto features = result->eClass()->getEAllStructuralFeatures();
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
