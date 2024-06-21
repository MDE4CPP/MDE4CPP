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
        void createJsonOfEObject(const std::shared_ptr<ecore::EObject>& object, crow::json::wvalue& result_json);
        
    private:
        //methodes
          
        template<typename T> void writeFeature(const std::shared_ptr<ecore::EObject>& object, const std::shared_ptr<ecore::EStructuralFeature>& feature, crow::json::wvalue& return_json);

        //variables
};
#endif /*ECORE2JSON_HPP*/