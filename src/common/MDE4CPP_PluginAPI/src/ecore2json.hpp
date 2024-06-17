#ifndef ECORE2JSON_HPP
#define ECORE2JSON_HPP
#include "util/crow_all.h"

#include "ecore/EObject.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/EReference.hpp"
#include "ecore/ecorePackage.hpp"

#include "pluginHandler.hpp"

class Ecore2Json {
    public:
        //methodes
        static std::shared_ptr<Ecore2Json> eInstance(std::shared_ptr<pluginHandler> pluginHandler);
        crow::json::wvalue writeValue(const std::shared_ptr<ecore::EObject>& object);
        
    private:
        //methodes
        Ecore2Json(std::shared_ptr<pluginHandler> pluginHandler);
        
        template<typename T> crow::json::wvalue writeFeature(const std::shared_ptr<ecore::EObject>& object, const std::shared_ptr<ecore::EStructuralFeature>& feature);

        template <typename T> T convert_to(const crow::json::rvalue& value);

        //variables
        std::shared_ptr<pluginHandler> m_pluginHandler;
};
#endif /*ECORE2JSON_HPP*/