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

    if(object == nullptr){
        throw std::runtime_error("createJson : object parameter was a nullptr!");
    }

    crow::json::wvalue::object json_obj = crow::json::wvalue::object();

    //sets "ObjectClass" key
    std::string objClassName = object->eClass()->getName(); //TODO implement correctly : currently missing namespace of the class
    CROW_LOG_INFO << "started creating json of " << objClassName;
    json_obj["ObjectClass"] = std::move(crow::json::wvalue(objClassName));

    //parsing of all attributes
    std::shared_ptr<Bag<ecore::EAttribute>> attributes = object->eClass()->getEAllAttributes();
    for(const std::shared_ptr<ecore::EAttribute> & attribute : *attributes){
        if(attribute == nullptr){
            CROW_LOG_WARNING << "createJsonOfEObject() : an attribute was a nullptr";
            continue;   //skips nullptr
        }

        auto attributeTypeId = object->eGet(attribute)->getTypeId();
        switch (attributeTypeId) {
            case ecore::ecorePackage::EBOOLEANOBJECT_CLASS:
            case ecore::ecorePackage::EBOOLEAN_CLASS:
            {
                auto value = writeFeature<bool>(object, attribute);
                if(value.t()  != crow::json::type::Null){
                    CROW_LOG_INFO << "setting " << attribute->getName() << " to " << value.dump();
                    json_obj[attribute->getName()] = std::move(writeFeature<bool>(object, attribute));
                }else{
                    CROW_LOG_WARNING << attribute->getName() <<" is null!" ;
                }
                break;
            }
            case ecore::ecorePackage::EBYTE_CLASS:
            case ecore::ecorePackage::EBYTEARRAY_CLASS:
            case ecore::ecorePackage::EBYTEOBJECT_CLASS:
            case ecore::ecorePackage::ECHARACTEROBJECT_CLASS:
            case ecore::ecorePackage::ECHAR_CLASS:
            {
                auto value = writeFeature<char>(object, attribute);
                if(value.t()  != crow::json::type::Null){
                    CROW_LOG_INFO << "setting " << attribute->getName() << " to " << value.dump();
                    json_obj[attribute->getName()] = std::move(writeFeature<char>(object, attribute));
                }else{
                    CROW_LOG_WARNING << attribute->getName() <<" is null!" ;
                }
                break;
            }
            case ecore::ecorePackage::EDATE_CLASS:
            case ecore::ecorePackage::ERESOURCE_CLASS:
            case ecore::ecorePackage::EINTEGEROBJECT_CLASS:
            case ecore::ecorePackage::EBIGINTEGER_CLASS:
            case ecore::ecorePackage::ESHORT_CLASS:
            case ecore::ecorePackage::ESHORTOBJECT_CLASS:
            case ecore::ecorePackage::EINT_CLASS:
             {
                auto value = writeFeature<int>(object, attribute);
                if(value.t()  != crow::json::type::Null){
                    CROW_LOG_INFO << "setting " << attribute->getName() << " to " << value.dump();
                    json_obj[attribute->getName()] = std::move(writeFeature<int>(object, attribute));
                }else{
                    CROW_LOG_WARNING << attribute->getName() <<" is null!" ;
                }
                break;
            }
            case ecore::ecorePackage::ELONGOBJECT_CLASS:
            case ecore::ecorePackage::ELONG_CLASS:
            {
                auto value = writeFeature<int>(object, attribute);
                if(value.t()  != crow::json::type::Null){
                    CROW_LOG_INFO << "setting " << attribute->getName() << " to " << value.dump();
                    json_obj[attribute->getName()] = std::move(writeFeature<int>(object, attribute));
                }else{
                    CROW_LOG_WARNING << attribute->getName() <<" is null!" ;
                }
                break;
            }
            case ecore::ecorePackage::EFLOATOBJECT_CLASS:
            case ecore::ecorePackage::EFLOAT_CLASS:
            {
                auto value = writeFeature<float>(object, attribute);
                if(value.t()  != crow::json::type::Null){
                    CROW_LOG_INFO << "setting " << attribute->getName() << " to " << value.dump();
                    json_obj[attribute->getName()] = std::move(writeFeature<float>(object, attribute));
                }else{
                    CROW_LOG_WARNING << attribute->getName() <<" is null!" ;
                }
                break;
            }
            case ecore::ecorePackage::EBIGDECIMAL_CLASS:
            case ecore::ecorePackage::EDOUBLE_CLASS:
            case ecore::ecorePackage::EDOUBLEOBJECT_CLASS:
            {
                auto value = writeFeature<double>(object, attribute);
                if(value.t()  != crow::json::type::Null){
                    CROW_LOG_INFO << "setting " << attribute->getName() << " to " << value.dump();
                    json_obj[attribute->getName()] = std::move(writeFeature<double>(object, attribute));
                }else{
                    CROW_LOG_WARNING << attribute->getName() <<" is null!" ;
                }
                break;
            }
            case ecore::ecorePackage::ESTRING_CLASS:
             {
                auto value = writeFeature<std::string>(object, attribute);
                if(value.t()  != crow::json::type::Null){
                    CROW_LOG_INFO << "setting " << attribute->getName() << " to " << value.dump();
                    json_obj[attribute->getName()] = std::move(writeFeature<std::string>(object, attribute));
                }else{
                    CROW_LOG_WARNING << attribute->getName() <<" is null!" ;
                }
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
            CROW_LOG_WARNING << "createJsonOfEObject : createJsonOfEObject() : a reference was a nullptr";
            continue;
        }
        if(reference->isContainment()){ //parses containment references
            if(object->eGet(reference)->isContainer()){
                auto list = crow::json::wvalue::list();
                auto bag = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(object->eGet(reference))->getAsEObjectContainer();
                if(bag == nullptr){
                    CROW_LOG_WARNING << "createJsonOfEObject : bag cast failed for Reference "<< reference->getName() << "!" ;
                }
                for(const std::shared_ptr<ecore::EObject> & obj : *bag){
                    if(obj == nullptr){
                    CROW_LOG_WARNING << "createJsonOfEObject : on refernce in "<< reference->getName() << " was a nullptr!" ;
                    continue;
                    }
                    //crow::json::wvalue o = createJsonOfEObject(obj);
                    list.push_back(std::move(createJsonOfEObject(obj)));
                }
                json_obj[reference->getName()] = move(list);
            }else{
                auto refValue = object->eGet(reference)->get<std::shared_ptr<ecore::EObject>>();
                if(refValue == nullptr){
                    CROW_LOG_WARNING << "createJsonOfEObject : the value of "<< reference->getName() << " was a nullptr!" ;
                }
                //auto value = createJsonOfEObject(refValue);
                json_obj[reference->getName()] = std::move(crow::json::wvalue(createJsonOfEObject(refValue)));
            }
        }
        if(!reference->isContainer() && !reference->isContainment()){//parses crossReferences
            //TODO set approriate path for reference!!!!
            //result_json[reference->getName()] =  reinterpret_cast<intptr_t>(object->eGet(reference).get());
        }
    }

    crow::json::wvalue result_json = move(json_obj);
    //std::cout << result_json.dump() << std::endl;
    return result_json;
}


/*template<>
crow::json::wvalue Ecore2Json::writeFeature<bool>(const std::shared_ptr<ecore::EObject> &object, const std::shared_ptr<ecore::EStructuralFeature> &feature) {
    auto isContainer = object->eGet(feature)->isContainer();
    if(isContainer){
        auto list = std::vector<bool>();
        auto bag = object->eGet(feature)->get<std::shared_ptr<Bag<bool>>>();
        for (const auto & value : *bag) {
            list.push_back(*value);
        }
        crow::json::wvalue v = {};
        v = list;
        return v;
    }
    return crow::json::wvalue(object->eGet(feature)->get<bool>());
    return crow::json::wvalue();
}*/


template<typename T>
crow::json::wvalue Ecore2Json::writeFeature(const std::shared_ptr<ecore::EObject> &object, const std::shared_ptr<ecore::EStructuralFeature> &feature) {
    auto isContainer = object->eGet(feature)->isContainer();
    crow::json::wvalue ret_json;
    if(isContainer){
        auto list = crow::json::wvalue::list();
        auto bag = object->eGet(feature)->get<std::shared_ptr<Bag<T>>>();
        for (auto const & val : *bag) {
            auto v = *val;
            auto o = crow::json::wvalue(v);
            list.push_back(std::move(o));
        }
        ret_json =  crow::json::wvalue(move(list));
    }else{
        auto any = object->eGet(feature);
        auto v = any->get<T>();
        ret_json = std::move(crow::json::wvalue(v));
    }
    return ret_json;
}
