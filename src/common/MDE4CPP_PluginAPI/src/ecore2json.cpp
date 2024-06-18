#include "ecore2json.hpp"
#include "helpersFunc.hpp"

//PluginFramework includes
#include "pluginFramework/MDE4CPPPlugin.hpp"

//Ecore includes
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EcoreContainerAny.hpp"

/*std::shared_ptr<Ecore2Json> Ecore2Json::eInstance(std::shared_ptr<pluginHandler> pluginHandler){
    static std::shared_ptr<Ecore2Json> instance = std::make_shared<Ecore2Json>(Ecore2Json(pluginHandler));
}*/

Ecore2Json::Ecore2Json(){}

crow::json::wvalue Ecore2Json::createJsonOfEObject(const std::shared_ptr<ecore::EObject>& object){
    auto result_json = crow::json::wvalue();

    //parsing of all attributes
    std::shared_ptr<Bag<ecore::EAttribute>> attributes = object->eClass()->getEAllAttributes();
    for(const std::shared_ptr<ecore::EAttribute> & attribute : *attributes){
        if(attribute == nullptr){
            CROW_LOG_INFO << "createJsonOfEObject() : an attribute was a nullptr";
            continue;   //skips nullptr
        }

        auto attributeTypeId = object->eGet(attribute)->getTypeId();
        switch (attributeTypeId) {
            case ecore::ecorePackage::EBOOLEANOBJECT_CLASS:
            case ecore::ecorePackage::EBOOLEAN_CLASS:
                result_json[attribute->getName()] = writeFeature<bool>(object, attribute);
                break;
            case ecore::ecorePackage::EBYTE_CLASS:
            case ecore::ecorePackage::EBYTEARRAY_CLASS:
            case ecore::ecorePackage::EBYTEOBJECT_CLASS:
            case ecore::ecorePackage::ECHARACTEROBJECT_CLASS:
            case ecore::ecorePackage::ECHAR_CLASS:
                result_json[attribute->getName()] = writeFeature<char>(object, attribute);
                break;
            case ecore::ecorePackage::EDATE_CLASS:
            case ecore::ecorePackage::ERESOURCE_CLASS:
            case ecore::ecorePackage::EINTEGEROBJECT_CLASS:
            case ecore::ecorePackage::EBIGINTEGER_CLASS:
            case ecore::ecorePackage::ESHORT_CLASS:
            case ecore::ecorePackage::ESHORTOBJECT_CLASS:
            case ecore::ecorePackage::EINT_CLASS:
                result_json[attribute->getName()] = writeFeature<int>(object, attribute);
                break;
            case ecore::ecorePackage::ELONGOBJECT_CLASS:
            case ecore::ecorePackage::ELONG_CLASS:
                result_json[attribute->getName()] = writeFeature<int>(object, attribute);
                break;
            case ecore::ecorePackage::EFLOATOBJECT_CLASS:
            case ecore::ecorePackage::EFLOAT_CLASS:
                result_json[attribute->getName()] = writeFeature<float>(object, attribute);
                break;
            case ecore::ecorePackage::EBIGDECIMAL_CLASS:
            case ecore::ecorePackage::EDOUBLE_CLASS:
            case ecore::ecorePackage::EDOUBLEOBJECT_CLASS:
                result_json[attribute->getName()] = writeFeature<bool>(object, attribute);
                break;
            case ecore::ecorePackage::ESTRING_CLASS:
            {
                result_json[attribute->getName()] = writeFeature<std::string>(object, attribute);
                break;
            }
            default:{ //should never be reached
                CROW_LOG_ERROR <<"encountered attribute of unknown type : " << attributeTypeId;
                break;
            }
        }
    }

    //parsing of all references
    std::shared_ptr<Bag<ecore::EReference>> references = object->eClass()->getEAllReferences();
    for(const std::shared_ptr<ecore::EReference> & reference : *references){
        if(reference == nullptr){
            CROW_LOG_INFO << "createJsonOfEObject() : a reference was a nullptr";
            continue;
        }
        if(reference->isContainment()){ //handles all containment references
            if(object->eGet(reference)->isContainer()){
                auto list = crow::json::wvalue();
                auto bag = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(object->eGet(reference))->getAsEObjectContainer();
                for(int j=0;j<bag->size();j++){
                    list[j] = createJsonOfEObject(bag->at(j));
                }
                result_json[reference->getName()] = std::move(list);
                break;
            }
            auto value = createJsonOfEObject(object->eGet(reference)->get<std::shared_ptr<ecore::EObject>>());
            result_json[reference->getName()] = std::move(value);
            break;
        }
        if(!reference->isContainer() && !reference->isContainment()){
            //TODO set approriate path for reference
            result_json[reference->getName()] =  reinterpret_cast<intptr_t>(object->eGet(reference).get());
        }
    }
    return result_json;
}

template<typename T>
crow::json::wvalue Ecore2Json::writeFeature(const std::shared_ptr<ecore::EObject> &object, const std::shared_ptr<ecore::EStructuralFeature> &feature) {
    auto isContainer = object->eGet(feature)->isContainer();
    if(isContainer){
        auto list = crow::json::wvalue();
        auto bag = object->eGet(feature)->get<std::shared_ptr<Bag<T>>>();
        for (int j=0;j<bag->size();j++) {
            auto value = bag->at(j).get();
            list[j] = value;
        }
        return list;
    }
    return crow::json::wvalue(object->eGet(feature)->get<T>());
}
