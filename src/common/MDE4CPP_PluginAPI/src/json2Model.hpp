#ifndef JSON2MODEL_HPP
#define JSON2MODEL_HPP

#include <tuple>
#include <vector>

#include "util/crow_all.h"

#include "ecore/EObject.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/EReference.hpp"
#include "ecore/ecorePackage.hpp"

#include "abstractDataTypes/Bag.hpp"

#include "pluginHandler.hpp"

class JSON2Model {
    public:
        //methodes
        JSON2Model(std::shared_ptr<pluginHandler> pluginHandler);

        /**
         * parses the json supplied in content and constructs a Model, all found crossreferences will be noted as tuples in the crossReferenceBuffer-vector
         * @param conten : json conti
         * @param crossReferenceBuffer : List of tuples for resolving non-containment references after all Object have been created
         *                                  tuple form : 
         *                                  {   Shared pointer to reference needs to be set,
         *                                      target(s) specified in the json for the reference (will be a list for References with multipicity of >1),
         *                                      typeID of the reference type,
         *                                      bool indicating it the reference can have more than one target (is of multipicity of >1)
         *                                      } 
        */
        std::shared_ptr<ecore::EObject> createModelWithoutCrossReferencesFromJson(const crow::json::rvalue& content, std::vector<std::tuple<std::shared_ptr<ecore::EReference>, crow::json::rvalue, long, bool>>& crossReferenceBuffer);
       
    private:
        //methodes
        template <typename T> T convert_to(const crow::json::rvalue& value);

        template<typename T> std::shared_ptr<Any> readAttributeValue(const std::shared_ptr<ecore::EObject>& object, const std::shared_ptr<ecore::EStructuralFeature>& feature, const crow::json::rvalue& content);
       
        //variables
        std::shared_ptr<pluginHandler> m_pluginHandler;

};
#endif /*JSON2MODEL_HPP*/