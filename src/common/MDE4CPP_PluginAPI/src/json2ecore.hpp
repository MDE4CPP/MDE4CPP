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

class Json2Ecore {
    public:
        //methodes
        Json2Ecore();

        /**
         * creates a ModelInstance representing the json
         *  
         */
        std::shared_ptr<ModelInstance>createEcoreModelFromJson(const crow::json::rvalue& content);

        
    private:
        TEST_FRIENDS;

        //methodes
        /**
         * helperfunction that constructs a Model without crossreferences from a json, all found crossreferences will be noted as tuples in the crossReferenceBuffer-vector
         * @param conten : json conti
         * @param crossReferenceBuffer : List of tuples for resolving non-containment references after all Object have been created
         *                                  tuple form : 
         *                                  {   eObject where the reference is part of,
         *                                      eEeference that will be set,
         *                                      target(s) specified in the json for the reference (will be a list for References with multipicity of >1)
         *                                      } 
        */
        std::shared_ptr<ecore::EObject> createModelWithoutCrossRef(const crow::json::rvalue& content, std::vector<std::tuple<std::shared_ptr<EObject> ,std::shared_ptr<ecore::EReference>, crow::json::rvalue>>& crossReferenceBuffer);
       
        template <typename T> T convert_to(const crow::json::rvalue& value);

        template<typename T> std::shared_ptr<Any> readAttributeValue(const std::shared_ptr<ecore::EObject>& object, const std::shared_ptr<ecore::EStructuralFeature>& feature, const crow::json::rvalue& content);
       
        //variables
        pluginHandler m_pluginHandler;

};
#endif /*JSON2ECORE_HPP*/