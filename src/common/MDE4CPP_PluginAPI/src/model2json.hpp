#ifndef MODEL2JSON_HPP
#define MODEL2JSON_HPP
#include "util/crow_all.h"

#include "ecore/EObject.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/EReference.hpp"
#include "ecore/ecorePackage.hpp"

#include "pluginHandler.hpp"

class Model2JSON {
    public:
        //methodes
        static std::shared_ptr<Model2JSON> eInstance(std::shared_ptr<pluginHandler> pluginHandler);
        crow::json::wvalue writeValue(const std::shared_ptr<ecore::EObject>& object);
        
    private:
        //methodes
        Model2JSON(std::shared_ptr<pluginHandler> pluginHandler);
        
        template<typename T> crow::json::wvalue writeFeature(const std::shared_ptr<ecore::EObject>& object, const std::shared_ptr<ecore::EStructuralFeature>& feature);

        template <typename T> T convert_to(const crow::json::rvalue& value);

        /**
         * gets the value of the appropiate key for a sructuralFeature
        */
        crow::json::rvalue getValueOfStrucFeature(std::shared_ptr<ecore::EStructuralFeature> structFeature, const crow::json::rvalue& content);

        //variables
        std::shared_ptr<pluginHandler> m_pluginHandler;
};
#endif /*MODEL2JSON_HPP*/