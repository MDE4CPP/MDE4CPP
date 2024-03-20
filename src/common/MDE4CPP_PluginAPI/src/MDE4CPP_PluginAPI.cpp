#define CROW_JSON_USE_MAP
#include "MDE4CPP_PluginAPI.hpp"

#include "pluginFramework/MDE4CPPPlugin.hpp"
#include "abstractDataTypes/Bag.hpp"

#include <sstream>
#include <string>

std::shared_ptr<GenericApi> GenericApi::eInstance(std::shared_ptr<PluginFramework> &pluginFramework) {
    static std::shared_ptr<GenericApi> instance = std::make_shared<GenericApi>(GenericApi(pluginFramework));
    return instance;
}

/*
Json example: 
{
    "ObjectId": "pluginName::ClassNamespace::ClassName::ObjectIdentifierName"
    "ObjectData" : {
        StrucuralFeatureName : Value    //StrucuralFeatureName needs to be the name of an EAttribute or EReference of the Class specified in the ObjectId
                                        //Value can be: -a primitive Value for an Attribute
                                                        -a json of an EObject (in the same syntax as this json) for References that are containments 
                                                        -an ObjectIdentifiert of an EObject for References that arent containments
    }
}
*/

GenericApi::GenericApi(std::shared_ptr<PluginFramework>& pluginFramework) {
    m_pluginFramework = pluginFramework;
	mapPlugins(); //makes an inital map of all plugins 
    crow::SimpleApp app;

    //Create function
    //Signature: /pluginName/objects/className/objectIdentifier
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
    //Signature: /pluginName/objects/className/objectIdentifier
    CROW_ROUTE(app, "/<string>/objects/<string>/<string>").methods(crow::HTTPMethod::Get)([this](const std::string& plugin_name, const std::string& className, const std::string& objectName){
        if(m_objects.find(objectName) == m_objects.end()){
            return crow::response(404);
        }
		
		const std::shared_ptr<MDE4CPPPlugin>& plugin = getPlugin(plugin_name);
		if(plugin == nullptr){
			return crow::response(404, "Plugin not found!");
		}
		
        auto result = writeValue(m_objects[objectName]);
        return crow::response(200, result);
    });

    //Update function 
    //Signature: /pluginName/objects/className/objectIdentifier
    CROW_ROUTE(app, "/<string>/objects/<string>/<string>").methods(crow::HTTPMethod::Put)([this](const crow::request& request, const std::string& plugin_name, const std::string& className, const std::string& objectName){
        if(m_objects.find(objectName) == m_objects.end()){
            return crow::response(404);
        }
		
		const std::shared_ptr<MDE4CPPPlugin>& plugin = getPlugin(plugin_name);
		if(plugin == nullptr){
			return crow::response(404, "Plugin not found!");
		}
		
        m_objects.erase(m_objects.find(objectName)); //TODO smarter update function
        auto object = readValue(crow::json::load(request.body), className, plugin);
        m_objects[objectName] = object;
        return crow::response(200);
    });

    //Delete function
    //Signature: /pluginName/objects/className/objectIdentifier
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
    //Signature: /pluginName/objects
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
            auto wvalue = writeValue(object.second);
            wvalue["ecore_identifier"] = object.first;
            wvalue["ecore_type"] = object.second->eClass()->getName();
            result[i] = std::move(wvalue);
            i++;
        }
        return crow::response(200, result);
    });

    //Invoke Operation
    //Signature operation/modelName/operationIdentifier/
    //modelName : name of root object
    //operationIdentifier : Location of 
	CROW_ROUTE(app, "/operation/<string>/<string>/").methods(crow::HTTPMethod::Post)([this](const std::string& plugin_name, const std::string& operationIdentifier){

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

//pares an object of the model and returns a json of it
crow::json::wvalue GenericApi::writeValue(const std::shared_ptr<ecore::EObject>& object){
    auto result = crow::json::wvalue();
    std::shared_ptr<Bag<ecore::EStructuralFeature>> features = object->eClass()->getEAllStructuralFeatures();
    for(const std::shared_ptr<ecore::EStructuralFeature> & feature : *features){
        if(object == nullptr){
            continue;   //skips nullptr
        }
        auto attributeTypeId = object->eGet(feature)->getTypeId();
        auto reference = std::dynamic_pointer_cast<EReference>(feature);
        if(reference != nullptr && reference->getEOpposite() != nullptr && !reference->isContainment()){
            continue; //skips bidirectional references 
            //TODO allow pointeres to objects 
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
                        list[j] = writeValue(bag->at(j));
                    }
                    result[feature->getName()] = std::move(list);
                    break;
                }
                auto value = writeValue(object->eGet(feature)->get<std::shared_ptr<EObject>>());
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

//creates an object encoded in a json 
std::shared_ptr<ecore::EObject> GenericApi::readValue(const crow::json::rvalue& content, const std::string& eClass, const std::shared_ptr<MDE4CPPPlugin>& plugin){
    auto result = plugin->create(eClass); //TODO check for unexpected behavior (e.g unknown ClassName)
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
        if(reference != nullptr && reference->getEOpposite() != nullptr && !reference->isContainment()){ //ignores all references, that aren't containments
            continue; //TODO add all References that arnt containments to a stack and resolve them after parsing the whole json
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
            default: // for non primitiv Datatypes e.g EObject
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

/**
 * getter for single MDE4CPPPlugin from m_plugins
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

const std::shared_ptr<Any>& setStructuralFeature(const std::shared_ptr<EObject>& start_object, std::string path, const std::shared_ptr<Any>& value){

    if (start_object == nullptr){ //check for nullptr start_object
        CROW_LOG_ERROR << "navigate() called nullptr as start_object!";
        return nullptr;
    }

    std::shared_ptr<EObject> current_object = start_object;

    if (path.size()== 0){ //check for empty path
        CROW_LOG_ERROR << "navigate() called with empy path!";
        return nullptr;
    }

    std::deque<std::string> split_path;
    split_string(split_path, path, '/'); //split path into segments that were seperated by "/" -> last will be name of target StructuralFeature; everything before will be path-segments to get there from the start_object
    std::string strucFeature = split_path.back();
    split_path.pop_back();
    auto obj = navigateToObject(start_object, split_path);
    obj->eSet(obj->eClass()->getEStructuralFeature(strucFeature),value);
}

std::shared_ptr<EObject> navigateToObject(const std::shared_ptr<EObject>& start_object, std::deque<std::string> path){
    std::shared_ptr<EObject> current_object = start_object;
    
    while(!path.empty()){
        std::string next_path_segment = path.front();
        path.pop_front();
        switch(next_path_segment[0]){
            case '$':
                //TODO alias handling
                break;
            
            case '@':
                //TODO container handling 
                break;
            
            default :   //handling for next Object
                try {
                    current_object = current_object->eGet(current_object->eClass()->getEStructuralFeature(next_path_segment))->get<std::shared_ptr<EObject>>(); //sets current_object to the Value of the StructualFeature with the same name as next_segment
                } catch (std::runtime_error& error){    //Type cast to EObject failed
                    CROW_LOG_ERROR << "malformed path error: "<< next_path_segment <<" could not be cast to correct type or is primitive";
                    return nullptr;
                }
                break;
        }
    }

    return current_object;
}

void split_string(std::deque<std::string>& buffer, std::string s, char split_char){
    std::stringstream ss;
    ss << s; //initilize stringstream with sting 
    std::string segment; 
    while(std::getline(ss, segment, split_char)) //reads ss into segment until split_char is reached or ss is empty
    {
        buffer.push_back(segment); 
    }
}
