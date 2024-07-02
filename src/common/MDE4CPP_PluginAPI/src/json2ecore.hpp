#ifndef JSON2ECORE_HPP
#define JSON2ECORE_HPP

#ifndef TEST_FRIENDS //macro for testing private members 
#define TEST_FRIENDS
#endif

#include <tuple>
#include <vector>

#include "util/crow_all.h"

#include "ecore/EObject.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/EReference.hpp"
#include "ecore/ecorePackage.hpp"

#include "abstractDataTypes/Bag.hpp"

#include "pluginHandler.hpp"
#include "ModelInstance.hpp"

struct Json2Ecore {
    public:
        //methodes
        Json2Ecore();

        /**
         * creates a ModelInstance representing the json
         * @param json : a json representation of a model (see MDE4CPP_PluginAPI docu for expected layout)
         * @return : shared_ptr to a model instance; or nullptr if json was malformed
         */
        std::shared_ptr<ModelInstance> createEcoreModelFromJson(const crow::json::rvalue& json);

        //TODO documentation
        std::shared_ptr<Any> createAnyFromJSON(const crow::json::rvalue& json, const unsigned long typeID,  const bool isContainer);

        
    private:
        TEST_FRIENDS;
        //methodes
        //TODO docu
        void resolveCrossreferences(const std::shared_ptr<ModelInstance>& modelInst);

        /**
         * returns the referenced eObject
         * @param json : json containing the reference target 
         *  depending on its type it is either interpreted as : -a path to the reference target in the modelInstance (type == string)
         *                                                      -an objectID of the reference target (type == number) 
         * @param modelInst : modelInstance for resolving paths
         * @return : referenced eObject or nullptr if reference could not be resolved                              
         */
        std::shared_ptr<ecore::EObject> getReferencedObject(const crow::json::rvalue& json, const std::shared_ptr<ModelInstance>& modelInst);

        /**
         * helperfunction that recursivly constructs an eObject and its contents from a json, all found crossreferences will be noted as tuples in the crossReferenceBuffer-vector
         * @param content : json containing the model
        */
        std::shared_ptr<ecore::EObject> createObjectWithoutCrossRef(const crow::json::rvalue& content);

        //TODO Docu           
        std::shared_ptr<Any> createAnyOfType(const unsigned long attributeTypeId, const bool isContainer, const crow::json::rvalue& content);

        /**
         * constructs an Any of the spectified Type
         * if isConatiner then the Any will contain a Bag
         * //TODO docu
         */
        template<typename T> std::shared_ptr<Any> writeAnyValue(
            const unsigned long attributeTypeId,
            const bool isContainer,
            const crow::json::rvalue& content);
    
        //TODO docu
        template <typename T> T convert_to(const crow::json::rvalue& value);

        //variables
        /**
         * instance of a plugin_Handler;
         */
        pluginHandler m_pluginHandler;

        /**
         * map of all objects that have an ObjecID in the json 
         */
        std::map<long long, std::shared_ptr<ecore::EObject>> m_objectMap;

        /**
         * List of tuples for resolving non-containment references after all Object have been created
         *      tuple form : 
         *          {   eObject where the reference is part of,
         *              eEeference that will be set,
         *              target(s) specified in the json for the reference (will be a list for References with multipicity of >1)
         *              } 
         */
        std::vector<std::tuple<std::shared_ptr<EObject>,std::shared_ptr<ecore::EReference>,crow::json::rvalue>> m_crossReferenceBuffer;


};
#endif /*JSON2ECORE_HPP*/