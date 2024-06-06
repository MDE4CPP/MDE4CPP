#define CROW_JSON_USE_MAP
#include "MDE4CPP_PluginAPI.hpp"

#include "pluginFramework/MDE4CPPPlugin.hpp"
#include "abstractDataTypes/Bag.hpp"
#include "pluginHandler.hpp"
#include "helpersFunc.hpp"

#include <sstream>
#include <string>

std::shared_ptr<GenericApi> GenericApi::eInstance() {
    static std::shared_ptr<GenericApi> instance = std::make_shared<GenericApi>(GenericApi());
    return instance;
}

GenericApi::GenericApi() {
	m_pluginHandler = pluginHandler::eInstance();
    crow::SimpleApp app;

    /**
     * Create model function : creates a new model from the json provided in the call
     * Signature: POST /modelInstName/
     * @param modelInstName : name the model instance will have afterwards; must be unique for all 
     * @param request : request that contains the json representation of the model instance 
    */
    CROW_ROUTE(app, "/<string>/").methods(crow::HTTPMethod::Post)([this](const crow::request& request, const std::string& modelInstName){
        if(m_modelInsts.find(modelInstName) != m_modelInsts.end()){
            return crow::response(400, "Model already exists!");
        }
        auto root_object = readValue(crow::json::load(request.body)); //TODO repair readValue
        
        ModelInstance* m = new ModelInstance(root_object, modelInstName); //create a new model instance

        m_modelInsts[modelInstName] = std::make_shared<ModelInstance>(m); //insert model instance into modelInsts map
        return crow::response(201);
    });

    /**
     * Return the value of the EObject specified in the path as a json; if path is empty return the whole model
     * Signature: GET /modelInstName/path/
     * @param modelInstName : name the model instance will have afterwards
     * @param path : path to the StructuralFeature in the model instance where the update shall be made
     *      -form of path : - path from root = StucturalFeatureOfRoot:NextStructuralFeature: ... :StructuralFeatureContaingTheTargetEObject
     *                      - path with alias = $alias:StucturalFeatureOfAlias:NextStructuralFeature: ... :targetStructuralFeature
     *      -form of StructuralFeature :    -for containers = NameOfStructFeat@IndexInContainer (e.g: #auhors@0 for first element in authors container; '#' indicates that it is a container; '@' indicates the index in the container)
     *                                      -for normal StructFeatures = NameOfStructFeat                                   
    */
    CROW_ROUTE(app, "/<string>/<string>").methods(crow::HTTPMethod::Get)([this](const std::string& modelInstName, const std::string& path){
        if(m_modelInsts.find(modelInstName) == m_modelInsts.end()){
            return crow::response(404, "Model not found!");
        }

        std::deque<std::string> segmented_path;
        helperFunctions::split_string(segmented_path, path, ':');
    	auto obj = m_modelInsts[modelInstName]->getObjectAtPath(segmented_path);
        
        //TODO: implement parsing of eObject to JSON
        
        return crow::response(200, result);
    });

    /**
     * Initiates an Update on a model instance with the attached json
     * Signature: PUT /modelInstName/path/
     * @param modelInstName : name the model instance will have afterwards
     * @param path : path to the StructuralFeature in the model instance where the update shall be made
     *      -form of path : - path from root = StucturalFeatureOfRoot:NextStructuralFeature: ... :targetStructuralFeature 
     *                      - path with alias = $alias:StucturalFeatureOfAlias:NextStructuralFeature: ... :targetStructuralFeature
     *      -form of StructuralFeature :    -for containers = NameOfStructFeat@IndexInContainer (e.g: auhors@0 for first element in authors container)
     *                                      -for normal StructFeatures = NameOfStructFeat
     * @param request : request that contains the json representation of changes that are to be inserted at the specified path 
    */
    CROW_ROUTE(app, "/<string>/<string>").methods(crow::HTTPMethod::Put)([this](const crow::request& request, const std::string& modelInstName, const std::string path){

        if(m_modelInsts.find(modelInstName) == m_modelInsts.end()){
            return crow::response(404, "Model not found!");
        }
		
        //splits path input into segments seperated by ':'
        std::deque<std::string> segmented_path;
        helperFunctions::split_string(segmented_path, path, ':');
;		auto obj = m_modelInsts[modelInstName]->getObjectAtPath(segmented_path);

        //TODO: implement update function

        return crow::response(200);
    });

    /**
     * Deletes the Model with the corresponding InstanceName
     * Signature: DELETE /modelInstName/
     * @param modelInstName : name the model instance will have afterwards
    */
    CROW_ROUTE(app, "/<string>/").methods(crow::HTTPMethod::Delete)([this](const std::string& modelInstName){
        if(m_modelInsts.find(modelInstName) == m_modelInsts.end()){
            return crow::response(404);
        }

        m_modelInsts.erase(m_modelInsts.find(modelInstName));
        return crow::response(204);
    });

    /**
     * Invokes an Operation of the EObject at the specified path and in the specified ModelInstance
     * Signature: POST invoke/modelInstName/path/operationName
     * @param modelInstName : name the model instance will have afterwards
     * @param path : path to the StructuralFeature in the model instance where the update shall be made
     *      -form of path : - path from root = StucturalFeatureOfRoot:NextStructuralFeature: ... :targetStructuralFeature 
     *                      - path with alias = $alias:StucturalFeatureOfAlias:NextStructuralFeature: ... :targetStructuralFeature
     *      -form of StructuralFeature :    -for containers = NameOfStructFeat@IndexInContainer (e.g: auhors@0 for first element in authors container)
     *                                      -for normal StructFeatures = NameOfStructFeat
     * @param operationName : name of the operation that should be invoked
     * @param request : Json-list of arguemts for the called Operation as strings; for each element of the list a cast into the appropriate type will be performed  
    */
	CROW_ROUTE(app, "/invoke/<string>/<string>/<string>/").methods(crow::HTTPMethod::Post)([this](const std::string& modelInstName, const std::string& path, const std::string& operationName){
        if(m_modelInsts.find(modelInstName) == m_modelInsts.end()){
            return crow::response(404);
        }

        //splits path input into segments seperated by ':'
        std::deque<std::string> segmented_path;
        helperFunctions::split_string(segmented_path, path, ':');
        //retrives a pointer to the EObject whose operation should be invoked
;		auto obj = m_modelInsts[modelInstName]->getObjectAtPath(segmented_path);
        
        //TODO implement call of operation

        //TODO return return-value of the operation
    });

    //TODO better docu
	/**
     * Returns list of all plugin names currently in m_plugins 
     * Signatur : GET /plugins
    */
	CROW_ROUTE(app, "/plugins").methods(crow::HTTPMethod::Get)([this](){
		
       auto list = crow::json::wvalue::list();
	   for(std::string entry : m_pluginHandler->getAllPluginNames()){
		   list.push_back(crow::json::wvalue(entry));
	   }
	   crow::json::wvalue result = crow::json::wvalue(list);
	   return crow::response(200, result);
    });

    //TODO better docu
    /**
     * Initiates a refresh of the plugin list by scanning the current directory 
     * Signatur : GET /plugins
    */
    CROW_ROUTE(app, "/refreshPlugins").methods(crow::HTTPMethod::Get)([this](){
		
        m_pluginHandler->refreshPlugins();

       auto list = crow::json::wvalue::list();
	   for(std::string entry : m_pluginHandler->getAllPluginNames()){
		   list.push_back(crow::json::wvalue(entry));
	   }
	   crow::json::wvalue result = crow::json::wvalue(list);
	   return crow::response(200, result);
    });

    //Swagger specific interfaces
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

/*const std::shared_ptr<Any>& setStructuralFeature(const std::shared_ptr<EObject>& start_object, std::string path, const std::shared_ptr<Any>& value){

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
    helperFunctions::split_string(split_path, path, '/'); //split path into segments that were seperated by "/" -> last will be name of target StructuralFeature; everything before will be path-segments to get there from the start_object
    std::string strucFeature = split_path.back();
    split_path.pop_back();
    auto obj = navigateToObject(start_object, split_path);
    obj->eSet(obj->eClass()->getEStructuralFeature(strucFeature),value);
}*/