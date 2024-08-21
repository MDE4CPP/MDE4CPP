#include "MDE4CPP_PluginAPI.hpp"

#include "pluginFramework/MDE4CPPPlugin.hpp"
#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Any.hpp"

#include "ecore/EAttribute.hpp"

#include "pluginHandler.hpp"
#include "helpersFunc.hpp"

#include <sstream>
#include <string>

std::shared_ptr<GenericApi> GenericApi::getInstance() {
    static GenericApi instance = GenericApi();
    return std::make_shared<GenericApi>(instance);
}

GenericApi::GenericApi() {
	m_pluginHandler = std::make_shared<pluginHandler>();

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
        Json2Ecore json2ecore_handler = Json2Ecore();

        crow::json::rvalue json;
        try{
            json = crow::json::load(request.body);
        }catch(const std::exception& e){
            CROW_LOG_ERROR << "Error while loading json: " << e.what();
        }

        try
        {
            m_modelInsts[modelInstName] = json2ecore_handler.createEcoreModelFromJson(json);
        }
        catch(const std::runtime_error& e)
        {
            CROW_LOG_ERROR << e.what();
            return crow::response(400 , e.what());
        }
        
        return crow::response(201);
    });

    /**
     * Return the value of the EObject specified in the path as a json; if path is empty return the whole model
     * Signature: GET /modelInstName/path/
     * @param modelInstName : name the model instance will have afterwards
     * @param path : path to the StructuralFeature in the model instance that shall be returned as a json; or '*' for the whole model;
     *      -form of path :     - "*" means no path;
     *                          - path from root = "StucturalFeatureOfRoot:NextStructuralFeature: ... :StructuralFeatureContaingTheTargetEObject";
     *      -form of StructuralFeature :    -for containers = NameOfStructFeat@IndexInContainer (e.g: auhors@0 for first element in authors container; '@' indicates the index in the container);
     *                                      -for normal StructFeatures = NameOfStructFeat;
    */
    CROW_ROUTE(app, "/<string>/<string>").methods(crow::HTTPMethod::Get)([this](const std::string& modelInstName, const std::string& path){
        if(m_modelInsts.find(modelInstName) == m_modelInsts.end()){
            CROW_LOG_INFO << modelInstName <<" not found in modelInst map!";
            return crow::response(400, "Model not found!");
        }
        std::shared_ptr<ecore::EObject> obj = nullptr;
        crow::json::wvalue responds_json = crow::json::wvalue();

        Ecore2Json ecore2Json_handler; 

        if(path == "*"){//get whole model
            std::shared_ptr<ecore::EObject> obj = m_modelInsts[modelInstName]->getRootObject();
            ecore2Json_handler.createJsonOfEObject(obj, responds_json);
        }else{//get part of the model
            auto segmented_path = helperFunctions::split_string(path, ':');
            std::shared_ptr<Any> any = nullptr;
            try{
                any =  m_modelInsts[modelInstName]->getAnyAtPath(segmented_path);
            }
            catch(const std::runtime_error& e){
                return crow::response(400, e.what());
            }
                      
            ecore2Json_handler.createJsonOfAny(any, responds_json);
        }

        return crow::response(200, responds_json);
    });

    /**
     * Initiates an Update on a model instance with the attached json
     * Signature: PUT /modelInstName/path/
     * @param modelInstName : name the model instance will have afterwards
     * @param path : path to the StructuralFeature in the model instance where the update shall be made
     *      -form of path : path from root = StucturalFeatureOfRoot:NextStructuralFeature: ... :targetStructuralFeature 
     *      -form of StructuralFeature :    -for containers = NameOfStructFeat@IndexInContainer (e.g: auhors@0 for first element in authors container)
     *                                      -for normal StructFeatures = NameOfStructFeat
     * @param request : request that contains the json representation of changes that are to be inserted at the specified path 
    */
    CROW_ROUTE(app, "/<string>/<string>").methods(crow::HTTPMethod::Put)([this](const crow::request& request, const std::string& modelInstName, const std::string path){

        if(m_modelInsts.find(modelInstName) == m_modelInsts.end()){
            return crow::response(404, "Model not found!");
        }
		
        //splits path input into segments seperated by ':'
        std::deque<std::string> segmented_path = helperFunctions::split_string(path, ':');
        std::deque<std::string> segmented_object_path = segmented_path;
        auto [stuctFeatureName, isContainer, index] = helperFunctions::splitStructuralFeaturePathSegment(segmented_object_path.back());
        segmented_object_path.pop_back();
        std::shared_ptr<ecore::EStructuralFeature> structFeature = m_modelInsts[modelInstName]->getObjectAtPath(segmented_object_path)->eClass()->getEStructuralFeature(stuctFeatureName);
        
        std::shared_ptr<ecore::EAttribute> attibute = std::dynamic_pointer_cast<ecore::EAttribute>(structFeature);
        if(attibute == nullptr){
            return crow::response(400, "updates currently not supported for references!");
        }
        
        std::shared_ptr<Any> any =  m_modelInsts[modelInstName]->getObjectAtPath(segmented_object_path)->eGet(structFeature);

        Json2Ecore json2Ecore_handler;

        crow::json::rvalue json;
        try{
            json = crow::json::load(request.body);
        }catch(const std::exception& e){
            CROW_LOG_ERROR << "Error while loading json: " << e.what();
            return crow::response(400, "json malformed!");
        }

        std::shared_ptr<Any> new_any;
        if(isContainer && any->isContainer()){ //replace only one element in the container
            new_any = json2Ecore_handler.createAnyOfType(any->getTypeId(), false, json);
        }else{
            new_any = json2Ecore_handler.createAnyOfType(any->getTypeId(), any->isContainer(), json);
        }
        
        m_modelInsts[modelInstName]->updateAttributeAtPath(segmented_path,new_any);

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
