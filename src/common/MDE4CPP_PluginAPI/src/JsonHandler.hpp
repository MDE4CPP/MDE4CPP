#ifndef JSON_HANDLER_HPP
#define JSON_HANDLER_HPP

#include "util/crow_all.h"

#include "ecore/EObject.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/EReference.hpp"
#include "ecore/ecorePackage.hpp"

#include "abstractDataTypes/Bag.hpp"

class json_handler {
    public:
        crow::json::wvalue writeValue(const std::shared_ptr<ecore::EObject>& object);
        template<typename T> crow::json::wvalue writeFeature(const std::shared_ptr<ecore::EObject>& object, const std::shared_ptr<ecore::EStructuralFeature>& feature);

    private:
        std::shared_ptr<ecore::EObject> readValue(const crow::json::rvalue& content);
        template<typename T> std::shared_ptr<Any> readFeature(const std::shared_ptr<ecore::EObject>& object, const std::shared_ptr<ecore::EStructuralFeature>& feature, const crow::json::rvalue& content);
        template <typename T> T convert_to(const crow::json::rvalue& value);
}
#endif /*JSON_HANDLER_HPP*/