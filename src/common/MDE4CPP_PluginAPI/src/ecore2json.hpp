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
        Ecore2Json();
        //static std::shared_ptr<Ecore2Json> eInstance(std::shared_ptr<pluginHandler> pluginHandler);
        crow::json::wvalue createJsonOfEObject(const std::shared_ptr<ecore::EObject>& object);
        
    private:
        //methodes
          
        template<typename T> crow::json::wvalue writeFeature(const std::shared_ptr<ecore::EObject>& object, const std::shared_ptr<ecore::EStructuralFeature>& feature);

        //variables
};
#endif /*ECORE2JSON_HPP*/