#ifndef MODEL_H
#define MODEL_H

#include "ecore/EObject.hpp"
#include <map>
#include <deque>
#include "helpersFunc.hpp"

using namespace ecore;

class Model{
    public: 
        Model(std::shared_ptr<EObject> root_Object, std::string modelName = "untitled Model"); //rootobj is set during creation of a model
        
        /**
         * allows to retrieve a pointer to the root_object of the model
         * @return shared pointer from m_rootObject
        */
        std::shared_ptr<EObject> getRootObject();

        /**
         * allows to add new aliases into the map
         * @param alias : key of the map; alias of the Object
         *      -will throw a runtime error if alias already exists
         * @param obj : value of the map; shared pointer to the object
        */
        void setAlias(std::string alias, std::shared_ptr<EObject> obj); //TODO should fail if alias is already in the map

        /**
         * allows to retrieve a pointer to the object associated with an aliases
         * @param alias alias as string 
         * @return shared pointer to Object of alias if it exists in the map; nullptr otherwise
        */
        std::shared_ptr<EObject> lookUpAlias(std::string alias); //allows to retrieve a pointer to the object associated with an aliases

        
        /**
         * navigate to the EObject specified in the path and returns a shared_ptr to it; starts at m_rootObject 
         * @param path = deque containg names of StructualFeature as strings; If empty returns start_object
        */
        const std::shared_ptr<EObject>& navigateToObject(std::deque<std::string> path); 

        void renameModel(std::string new_name);
        std::string getModelName();

    private : 
        std::shared_ptr<EObject> m_rootObject; //pointer to the root object
        std::map<std::string, std::shared_ptr<EObject>> m_aliases; //allows to access certain object directly via their aliases; aliases have to be assigned by the user
        //TODO change shared_ptr to weak_ptr as to not hinder deletion
        std::string m_modelName;

};

#endif /*MODEL_H*/