#ifndef MODEL_H
#define MODEL_H

#include "ecore/EObject.hpp"
#include "abstractDataTypes/Any.hpp"
#include <map>
#include <deque>
#include "helpersFunc.hpp"

using namespace ecore;

class ModelInstance{
    public: 
        ModelInstance(std::shared_ptr<EObject> root_Object, std::string modelName = "untitled modelInstance"); //rootobj is set during creation of a model instance
        
        /**
         * allows to retrieve a pointer to the root_object of the model instance
         * @return shared pointer from m_rootObject
        */
        std::shared_ptr<EObject> getRootObject();

        /**
         * allows to add new aliases into the map
         * @param alias : key of the map; alias of the Object
         *      -will throw a runtime error if alias already exists
         * @param obj : value of the map; shared pointer to the object
        */
        void setAlias(std::string alias, std::shared_ptr<EObject> obj); 

        /**
         * allows to retrieve a pointer to the object associated with an aliases
         * @param alias alias as string 
         * @return shared pointer to Object of alias if it exists in the map; nullptr otherwise
        */
        std::shared_ptr<EObject> lookUpAlias(std::string alias); //allows to retrieve a pointer to the object associated with an aliases

        
        /**
         * navigates through modelInstance starting from m_rootObject along specified path the an target EObject and return shared pointer to it.
         * mainly used for resolving references
         * @param path = deque containg names of StructualFeature as strings; If empty returns m_rootObject
         *  elements must be in the form:   - "#StructFeatureName@Index" -> for structural featues with the type containers (e.g.: "#authors@9")
         *                                  - "$aliasNameOfStructFeature" -> for if alias should be used (e.g.: $tolkin)
         *                                  - "nameOfStructFeature" -> for normal structural features (e.g.: "name") 
        */
        const std::shared_ptr<EObject>& getObjectAtPath(std::deque<std::string>& path); 

        /**
         * navigate to the EObject specified in the path and returns a shared_ptr to it; starts at m_rootObject 
         * @param path = deque containg names of StructualFeature as strings; If empty returns m_rootObject
         *  elements must be in the form:   - "#StructFeatureName@Index" -> for structural featues with the type containers (e.g.: "#authors@9")
         *                                  - "$aliasNameOfStructFeature" -> for if alias should be used (e.g.: $tolkin)
         *                                  - "nameOfStructFeature" -> for normal structural features (e.g.: "name") 
        */
        std::shared_ptr<Any> getValueOfStructFeatureAtPath(std::deque<std::string>& path);

        void renameModelInstance(std::string new_name);
        std::string getModelInstanceName();

    private : 
        /**
         * helper function to get the Value of the StructuralFeature with a specific name from an object
         * @param obj :  pinter to an EObject
         * @param sFeatureName : name of StructuralFeature that should be retrieved as a string
         * @return : shared_ptr to Value of StructFeature; OR nullptr if no StructFeature with the given name exists in the object -> throws runtime_exeption
         */
        std::shared_ptr<Any> getValueOfStructFeatureByName(const std::shared_ptr<EObject> obj ,const std::string& sFeatureName);

        std::shared_ptr<EObject> m_rootObject; //pointer to the root object
        std::map<std::string, std::weak_ptr<EObject>> m_aliases; //allows to access certain object directly via their aliases; aliases have to be assigned by the user
        std::string m_modelInstanceName;

};

#endif /*MODEL_H*/