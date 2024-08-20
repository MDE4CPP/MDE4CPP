#ifndef MODELINSTANCE_H
#define MODELINSTANCE_H

#ifndef TEST_FRIENDS_MODELINSTANCE //macro for testing private members 
#define TEST_FRIENDS_MODELINSTANCE
#endif


#include "ecore/EObject.hpp"
#include "abstractDataTypes/Any.hpp"
#include <map>
#include <deque>
#include "helpersFunc.hpp"

using namespace ecore;

struct ModelInstance{
    public: 
        ModelInstance(const std::shared_ptr<EObject> root_Object = nullptr, const std::string modelName = "untitled modelInstance"); //rootobj is set during creation of a model instance

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
         * navigates through modelInstance starting from m_rootObject along specified path to the target Any and return shared pointer to it.
         * mainly used for accessing StructFeatures
         * @param path = deque containg names of StructualFeature as strings; If empty returns m_rootObject
         *  elements must be in the form:   - "StructFeatureName@Index" -> for structural featues with the type containers (e.g.: "authors@9")
         *                                  - "$aliasNameOfStructFeature" -> for if alias should be used (e.g.: $tolkin)
         *                                  - "nameOfStructFeature" -> for normal structural features (e.g.: "name") 
         * @return = a shared pointer to an Any;    -the Any of a primitve Datatype (int, long, char, string, etc) will contain the value directly; eg. Any<string>
         *                                          -the Any of a non-primitive Datatype (eClass, Bag) will contain a shared_ptr; eg. Any<shared_ptr<eObject>>
        */
        std::shared_ptr<Any> getAnyAtPath(std::deque<std::string> path); 

        //TODO Docu
        void setAnyAtPath(std::deque<std::string> path, std::shared_ptr<Any>);
        
        /**
         * navigates through modelInstance starting from m_rootObject along specified path the an target EObject and return shared pointer to it.
         * mainly used for resolving references
         * @param path = deque containg names of StructualFeature as strings; If empty returns m_rootObject
         *  elements must be in the form:   - "StructFeatureName@Index" -> for structural featues with the type containers (e.g.: "authors@9")
         *                                  - "$aliasNameOfStructFeature" -> for if alias should be used (e.g.: $tolkin)
         *                                  - "nameOfStructFeature" -> for normal structural features (e.g.: "name") 
         * @return = a shared_ptr to an eObject
        */
        std::shared_ptr<EObject> getObjectAtPath(std::deque<std::string> path); 

        /**
         * allows to get the path to a given EObject in the model from the root_obj as a deque of pathsegments as strings
         * @param obj pointer to Object whos path shall be returned
         * @return deque containing names of StructuralFeatures as strings starting at a StructFeature of root
        */
        std::deque<std::string> getAttributesAsString(const std::shared_ptr<EObject>& obj);


        /**
         * sets the Reference at the path to the referenceTarget
         */
        void setReferenceAtPath(const std::string& path, std::shared_ptr<EObject> referenceTarget);

        void setModelInstanceName(std::string new_name);
        std::string getModelInstanceName();

    private :
        TEST_FRIENDS_MODELINSTANCE;
        friend class GenericApi; //temporary while update functionality for references is still missing

        /**
         * helper function to get the Value of the StructuralFeature with a specific name from an object
         * @param obj :  pinter to an EObject
         * @param sFeatureName : name of StructuralFeature that should be retrieved as a string
         * @return : shared_ptr to Value of StructFeature; OR nullptr if no StructFeature with the given name exists in the object -> throws runtime_exeption
         */
        std::shared_ptr<Any> getValueOfStructFeatureByName(const std::shared_ptr<EObject> obj ,const std::string& sFeatureName);

        void setValueOfStructFeatureByName(const std::shared_ptr<EObject> obj ,const std::string& sFeatureName, std::shared_ptr<Any> new_content);

        void updateAttributeAtPath(std::deque<std::string> path, std::shared_ptr<Any> new_content);

        

        std::shared_ptr<EObject> m_rootObject; //pointer to the root object
        std::map<std::string, std::weak_ptr<EObject>> m_aliases; //allows to access certain object directly via their aliases; aliases have to be assigned by the user
        std::string m_modelInstanceName;

};

#endif /*MODELINSTANCE_H*/