#define CROW_JSON_USE_MAP
#include "MDE4CPP_PluginAPI.hpp"

#include "pluginFramework/MDE4CPPPlugin.hpp"
#include "abstractDataTypes/Bag.hpp"
#include "pluginHandler.hpp"
#include "helpersFunc.hpp"

#include <sstream>
#include <string>

std::shared_ptr<GenericApi> GenericApi::eInstance() {
    static GenericApi instance = GenericApi();
    return std::make_shared<GenericApi>(instance);
}

GenericApi::GenericApi() {
	m_pluginHandler = std::make_shared<pluginHandler>();

    m_Json2Ecore_handler = std::make_shared<Json2Ecore>();

    crow::SimpleApp app;

    /**
     * Create model function : creates a new model from the json provided in the call
     * Signature: POST /modelInstName/
     * @param modelInstName : name the model instance will have afterwards; must be unique for all 
     * @param request : request that contains the json representation of the model instance 
    */
    CROW_ROUTE(app, "/<string>/").methods(crow::HTTPMethod::Post)([this](const crow::request& request, const std::string& modelInstName){
        if(m_modelInsts.find(modelInstName) != m_modelInsts.end()){
            CROW_LOG_INFO<<"modelInst:\""<< modelInstName <<"\" already exists";
            return crow::response(400, "Model already exists!");
        }

        auto m = m_Json2Ecore_handler->createEcoreModelFromJson(crow::json::load(request.body));
        

        m_modelInsts[modelInstName] = m; //insert model instance into modelInsts map
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
        auto segmented_path = helperFunctions::split_string(path, ':');
    	auto obj = m_modelInsts[modelInstName]->getObjectAtPath(segmented_path);
        
        //TODO: implement parsing of eObject to JSON
        
        return crow::response(418, "not  implemented");
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
        auto segmented_path = helperFunctions::split_string(path, ':');
;		auto obj = m_modelInsts[modelInstName]->getObjectAtPath(segmented_path);

        //TODO: implement update function

        return crow::response(418, "not  implemented");
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
        auto segmented_path = helperFunctions::split_string(path, ':');
        //retrives a pointer to the EObject whose operation should be invoked
;		auto obj = m_modelInsts[modelInstName]->getObjectAtPath(segmented_path);
        
        //TODO implement call of operation
        return crow::response(418, "not fully implemented");
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
