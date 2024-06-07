#include "Model2JSON.hpp"
#include "helpersFunc.hpp"

//PluginFramework includes
#include "pluginFramework/MDE4CPPPlugin.hpp"

//Ecore includes
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EcoreContainerAny.hpp"

std::shared_ptr<Model2JSON> Model2JSON::eInstance(std::shared_ptr<pluginHandler> pluginHandler){
    static std::shared_ptr<Model2JSON> instance = std::make_shared<Model2JSON>(Model2JSON(pluginHandler));
}

Model2JSON::Model2JSON(std::shared_ptr<pluginHandler> pluginHandler){
    m_pluginHandler = pluginHandler;
}

crow::json::wvalue Model2JSON::writeValue(const std::shared_ptr<ecore::EObject>& object){
    auto result = crow::json::wvalue();
    std::shared_ptr<Bag<ecore::EStructuralFeature>> features = object->eClass()->getEAllStructuralFeatures();
    for(const std::shared_ptr<ecore::EStructuralFeature> & feature : *features){
        if(object == nullptr){
            continue;   //skips nullptr
        }
        auto attributeTypeId = object->eGet(feature)->getTypeId();
        auto reference = std::dynamic_pointer_cast<ecore::EReference>(feature);
        if(reference != nullptr && reference->getEOpposite() != nullptr && !reference->isContainment()){
            continue; //skips bidirectional references 
            //TODO allow pointeres to objects 
        }
        switch (attributeTypeId) {
            case ecore::ecorePackage::EBOOLEANOBJECT_CLASS:
            case ecore::ecorePackage::EBOOLEAN_CLASS:
                result[feature->getName()] = writeFeature<bool>(object, feature);
                break;
            case ecore::ecorePackage::EBYTE_CLASS:
            case ecore::ecorePackage::EBYTEARRAY_CLASS:
            case ecore::ecorePackage::EBYTEOBJECT_CLASS:
            case ecore::ecorePackage::ECHARACTEROBJECT_CLASS:
            case ecore::ecorePackage::ECHAR_CLASS:
                result[feature->getName()] = writeFeature<char>(object, feature);
                break;
            case ecore::ecorePackage::EDATE_CLASS:
            case ecore::ecorePackage::ERESOURCE_CLASS:
            case ecore::ecorePackage::EINTEGEROBJECT_CLASS:
            case ecore::ecorePackage::EBIGINTEGER_CLASS:
            case ecore::ecorePackage::ESHORT_CLASS:
            case ecore::ecorePackage::ESHORTOBJECT_CLASS:
            case ecore::ecorePackage::EINT_CLASS:
                result[feature->getName()] = writeFeature<int>(object, feature);
                break;
            case ecore::ecorePackage::ELONGOBJECT_CLASS:
            case ecore::ecorePackage::ELONG_CLASS:
                result[feature->getName()] = writeFeature<int>(object, feature);
                break;
            case ecore::ecorePackage::EFLOATOBJECT_CLASS:
            case ecore::ecorePackage::EFLOAT_CLASS:
                result[feature->getName()] = writeFeature<float>(object, feature);
                break;
            case ecore::ecorePackage::EBIGDECIMAL_CLASS:
            case ecore::ecorePackage::EDOUBLE_CLASS:
            case ecore::ecorePackage::EDOUBLEOBJECT_CLASS:
                result[feature->getName()] = writeFeature<bool>(object, feature);
                break;
            case ecore::ecorePackage::ESTRING_CLASS:
            {
                result[feature->getName()] = writeFeature<std::string>(object, feature);
                break;
            }
            default:
            {
                if(object->eGet(feature)->isContainer()){
                    auto list = crow::json::wvalue();
                    auto bag = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(object->eGet(feature))->getAsEObjectContainer();
                    for(int j=0;j<bag->size();j++){
                        list[j] = writeValue(bag->at(j));
                    }
                    result[feature->getName()] = std::move(list);
                    break;
                }
                auto value = writeValue(object->eGet(feature)->get<std::shared_ptr<ecore::EObject>>());
                result[feature->getName()] = std::move(value);
                break;
            }
        }
    }
    return result;
}

template<typename T>
crow::json::wvalue Model2JSON::writeFeature(const std::shared_ptr<ecore::EObject> &object, const std::shared_ptr<ecore::EStructuralFeature> &feature) {
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

//creates an object encoded in a json
std::shared_ptr<ecore::EObject> Model2JSON::createObjecFromJson(const crow::json::rvalue& content){

    auto ObjClass_KeyVal = content["ObjectClass"];
    if(ObjClass_KeyVal.t() != crow::json::type::String){ //check if type of the key value is anything else than a string (eg. null)
        throw std::runtime_error("ObjectClass key not set!");
    }
    auto [pluginName , eClass] = helperFunctions::splitObjectClassKey(std::string(ObjClass_KeyVal));

    auto plugin = m_pluginHandler->getPluginByName(pluginName);
    auto result = plugin->create(eClass); //TODO check for unexpected behavior (e.g unknown ClassName)

    //handeling of all memeber attibutes of the object
    std::shared_ptr<Bag<ecore::EAttribute>> attributes = result->eClass()->getEAllAttributes();
    for(const auto & attribute : *attributes){
        try {
            auto value = content[attribute->getName()];
            if(value.t() == crow::json::type::Null){
                CROW_LOG_INFO << attribute->getName()  << " not set in json for object";
                continue;
            }
        } catch (std::runtime_error& error){
            CROW_LOG_WARNING << "an error occured in createOjectFromJSON : "  << error.what() <<" !" ;
            continue;
        }

        auto attributeTypeId = result->eGet(attribute)->getTypeId(); //TODO make less complicated
        switch (attributeTypeId) {
            case ecore::ecorePackage::EBOOLEANOBJECT_CLASS:
            case ecore::ecorePackage::EBOOLEAN_CLASS:
                result->eSet(attribute, readFeature<bool>(result, attribute, content));
                break;
            case ecore::ecorePackage::EBYTE_CLASS:
            case ecore::ecorePackage::EBYTEARRAY_CLASS:
            case ecore::ecorePackage::EBYTEOBJECT_CLASS:
            case ecore::ecorePackage::ECHARACTEROBJECT_CLASS:
            case ecore::ecorePackage::ECHAR_CLASS:
                result->eSet(attribute, readFeature<char>(result, attribute, content));
                break;
            case ecore::ecorePackage::EDATE_CLASS:
            case ecore::ecorePackage::ERESOURCE_CLASS:
            case ecore::ecorePackage::EINTEGEROBJECT_CLASS:
            case ecore::ecorePackage::EBIGINTEGER_CLASS:
            case ecore::ecorePackage::ESHORT_CLASS:
            case ecore::ecorePackage::ESHORTOBJECT_CLASS:
            case ecore::ecorePackage::EINT_CLASS:
                result->eSet(attribute, readFeature<int>(result, attribute, content));
                break;
            case ecore::ecorePackage::ELONGOBJECT_CLASS:
            case ecore::ecorePackage::ELONG_CLASS:
                result->eSet(attribute, readFeature<long>(result, attribute, content));
                break;
            case ecore::ecorePackage::EFLOATOBJECT_CLASS:
            case ecore::ecorePackage::EFLOAT_CLASS:
                result->eSet(attribute, readFeature<float>(result, attribute, content));
                break;
            case ecore::ecorePackage::EBIGDECIMAL_CLASS:
            case ecore::ecorePackage::EDOUBLE_CLASS:
            case ecore::ecorePackage::EDOUBLEOBJECT_CLASS:
                result->eSet(attribute, readFeature<double>(result, attribute, content));
                break;
            case ecore::ecorePackage::ESTRING_CLASS:
                result->eSet(attribute, readFeature<std::string>(result, attribute, content));
                break;
            default :
                CROW_LOG_ERROR <<"encountered attribute of unknown type : " << attributeTypeId;
                break;
        }
    }
        
    //handeling of all memeber references of the object
    std::shared_ptr<Bag<ecore::EReference>> references = result->eClass()->getEAllReferences();
    for(auto reference : *references){

        if(reference == nullptr){
            CROW_LOG_ERROR << "shared_ptr to reference is nullptr!" ;
        }

        try {
            auto value = content[reference->getName()];
            if(value.t() == crow::json::type::Null){ //no matching key was found in the json 
                CROW_LOG_INFO << reference->getName()  << " not set in json for object";
                continue;
            }
        } catch (std::runtime_error& error){
            CROW_LOG_ERROR << "runtime error occured in createOjectFromJSON : "  << error.what() <<" !" ;
            continue;
        }

        if(reference->isContainment()){ //handles all containment references; container (back-)references will also automaticly be set
            auto referenceTypeID = result->eGet(reference)->getTypeId(); //Gets TypeID of the reference target //TODO make less complicated
            std::shared_ptr<Any> referenceContent;

            if(result->eGet(reference)->isContainer()){
                auto bag = std::make_shared<Bag<ecore::EObject>>();
                for(const auto & entry : content[reference->getName()]){
                    bag->add(createObjecFromJson(entry)); //creates each object that is being referenced 
                }
                referenceContent = eEcoreContainerAny(bag, referenceTypeID);
            }else{
                auto value = createObjecFromJson(content[reference->getName()]);
                referenceContent = eAny(value, referenceTypeID, false);
            }
            result->eSet(reference, referenceContent);
        }

        if(!reference->isContainer() && !reference->isContainment()){ //handles all references other than containment- and container-references
            //TODO: handlinf of "normal" references
            auto referenceTypeID = result->eGet(reference)->getTypeId(); //Gets TypeID of the reference target //TODO make less complicated
            std::shared_ptr<Any> referenceContent;

            if(result->eGet(reference)->isContainer()){
                auto bag = std::make_shared<Bag<ecore::EObject>>();
                for(const auto & entry : content[reference->getName()]){
                    if(){

                    }
                    bag->add(createObjecFromJson(entry)); //creates each object that is being referenced 
                }
                referenceContent = eEcoreContainerAny(bag, referenceTypeID);
            }else{
                auto value = createObjecFromJson(content[reference->getName()]);
                referenceContent = eAny(value, referenceTypeID, false);
            }
            result->eSet(reference, referenceContent);
        }

    }
    return result;
}

crow::json::rvalue getValueOfStrucFeature(std::shared_ptr<ecore::EStructuralFeature> structFeature, const crow::json::rvalue& content){

}

//generic conversion methods for json
template<> bool Model2JSON::convert_to<bool>(const crow::json::rvalue& value){
    return value.b();
}

template <typename T> T Model2JSON::convert_to(const crow::json::rvalue& value){
    std::istringstream ss(value.operator std::string());
    T num;
    ss >> num;
    return num;
}

template<typename T>
std::shared_ptr<Any> Model2JSON::readFeature(const std::shared_ptr<EObject>& object, const std::shared_ptr<EStructuralFeature>& feature, const crow::json::rvalue& content){
    auto attributeTypeId = object->eGet(feature)->getTypeId();
    auto isContainer = object->eGet(feature)->isContainer();
    if(isContainer){
        auto bag = object->eGet(feature)->get<std::shared_ptr<Bag<T>>>();
        for(const auto & entry : content[feature->getName()]){
            auto value = std::make_shared<T>(convert_to<T>(entry));
            bag->add(value);
        }
        return eAny(bag, attributeTypeId, true);
    }
    return eAny(convert_to<T>(content[feature->getName()]), attributeTypeId, false);
}