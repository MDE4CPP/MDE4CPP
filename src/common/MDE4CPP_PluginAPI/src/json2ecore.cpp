#include "json2Ecore.hpp"
#include "helpersFunc.hpp"
#include <map>

//PluginFramework includes
#include "pluginFramework/MDE4CPPPlugin.hpp"

//Ecore includes
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "ecore/EcoreAny.hpp"

Json2Ecore::Json2Ecore(){
    m_pluginHandler = pluginHandler();
}

std::shared_ptr<ModelInstance> Json2Ecore::createEcoreModelFromJson(const crow::json::rvalue& content){

    //todo check content type
    if(content.t() != crow::json::type::Object){
        CROW_LOG_ERROR << "createEcoreModelFromJson : Json malformed! Must contain a single root object!";
        return nullptr;
    }

    m_crossReferenceBuffer.clear();//makes sure the buffer is empty

    std::shared_ptr<ecore::EObject> root_object = nullptr;
    try{
        root_object = createObjectWithoutCrossRef(content);
    }
    catch(const std::runtime_error& e){
        throw(std::runtime_error("could not create Model : " + std::string(e.what())));
    }
    
    std::shared_ptr<ModelInstance> modelInst = std::make_shared<ModelInstance>(root_object); //create a new model instance with no name
    
    //add crossreferences into the Model 
    resolveCrossreferences(modelInst);

    return modelInst; //return complete model
}

void Json2Ecore::resolveCrossreferences(const std::shared_ptr<ModelInstance>& modelInst){

    if(modelInst == nullptr){//maybe a redundant check
        return;
    }

    for(auto [eObj, eRef, json] : m_crossReferenceBuffer){

        auto referenceTypeID = eObj->eGet(eRef)->getTypeId();
        std::shared_ptr<Any> referenceContent;
        if((eRef->getUpperBound() > 1 || eRef->getUpperBound() == -1)){ //reference is of multiplicity > 1 
            auto bag = std::make_shared<Bag<ecore::EObject>>();
            for(const auto & entry : json){
                std::string s = std::string(entry);
                std::shared_ptr<ecore::EObject> refTarget = getReferencedObject(entry, modelInst);
                bag->add(refTarget);
            }
            referenceContent = eEcoreContainerAny(bag, referenceTypeID);
        }else{//reference is of multiplicity == 1
            std::shared_ptr<ecore::EObject> refTarget = getReferencedObject(json, modelInst);
            referenceContent = eEcoreAny(refTarget, referenceTypeID);
        }
        eObj->eSet(eRef, referenceContent);
    }
}

std::shared_ptr<ecore::EObject> Json2Ecore::getReferencedObject(const crow::json::rvalue& json, const std::shared_ptr<ModelInstance>& modelInst){
    std::shared_ptr<ecore::EObject> refTarget = nullptr;
    switch(json.t()){
        case crow::json::type::String : { //handles references as a path
            std::string path = json.s();
            auto segmented_path = helperFunctions::split_string(path, ':');
            try{
                refTarget = modelInst->getObjectAtPath(segmented_path);
            }
            catch(const std::runtime_error&){ //path was malformed
                CROW_LOG_ERROR << "could not resolve reference with path : " << path;
                }
            break;
        }
        case crow::json::type::Number : { //handles references as an ObjectID
            int64_t objID = json.i();
            if (auto iter = m_objectMap.find(objID); iter != m_objectMap.end())
                refTarget = iter->second;
            else
                CROW_LOG_ERROR << "could not resolve reference with ID : " << objID;
            break;
        }
        default : {
            CROW_LOG_ERROR << "cross-references can either be a string for a path, or a number for an ObjectID";
        }
    }
    return refTarget;
}

//creates an object encoded in a json
std::shared_ptr<ecore::EObject> Json2Ecore::createObjectWithoutCrossRef(const crow::json::rvalue& content){

    if(!content.has("ObjectClass")){
        throw std::runtime_error("ObjectClass key not set!");
    }
    auto ObjClass_KeyVal = content["ObjectClass"];
    if(ObjClass_KeyVal.t() != crow::json::type::String){ //if type of the key value is anything else except for a string (eg. null)
        throw std::runtime_error("ObjectClass key has wrong type! Expected Type : String");
    }
    auto [pluginName , eClass] = helperFunctions::splitObjectClassKey(std::string(ObjClass_KeyVal));

    std::shared_ptr<MDE4CPPPlugin> plugin = m_pluginHandler.getPluginByName(pluginName);
    std::shared_ptr<ecore::EObject> result = plugin->create(pluginName + "::" + eClass);
    if(result == nullptr){
        throw std::runtime_error( "create-methode of the plugin returned nllptr; most likely \""+ eClass + "\"-class not found in Plugin of the Model!");
    }

    //inserts eObject into objectMap with its ObjectID
    if(content.has("ObjectID")){
        crow::json::rvalue ObjID_KeyValue = content["ObjectID"];
        int64_t objID = ObjID_KeyValue.i();
        m_objectMap.insert({objID,result});
        CROW_LOG_INFO << "added " << eClass << " with ID : " << objID << " into objectMap";
    }else{
        CROW_LOG_INFO << "no ObjectID key found in " << eClass << "; will not be added into objectMap!";
    }


    //handeling of all member attibutes of the object
    std::shared_ptr<Bag<ecore::EAttribute>> attributes = result->eClass()->getEAllAttributes();
    for(const auto & attribute : *attributes){

        if(!content.has(attribute->getName())){
            CROW_LOG_INFO << attribute->getName()  << " does not exist in json of the objectClass: " << ObjClass_KeyVal;
            continue;
        }

        auto attrValue = content[attribute->getName()];
        if(attrValue.t() == crow::json::type::Null){
            CROW_LOG_INFO << attribute->getName()  << " is set to null and will be ignored!";
            continue;
        }

        unsigned long attributeTypeId = result->eGet(attribute)->getTypeId();
        bool isContainer = (attribute->getUpperBound() > 1 || attribute->getUpperBound() == -1);
        std::shared_ptr<Any> any = createAnyOfType(attributeTypeId, isContainer, attrValue);

        if(any == nullptr){
            CROW_LOG_ERROR <<"tried to create primitv any with unsupported type : " << attributeTypeId;
            continue;
        }

        result->eSet(attribute, any);
    }
        
    //handeling of all member references of the object
    std::shared_ptr<Bag<ecore::EReference>> references = result->eClass()->getEAllReferences();
    for(const std::shared_ptr<ecore::EReference>& reference : *references){

        if(reference == nullptr){
            CROW_LOG_ERROR << "shared_ptr to reference is nullptr!" ;
        }

        if(!content.has(reference->getName())){
            CROW_LOG_INFO << reference->getName()  << " does not exist in json of the objectClass: " << ObjClass_KeyVal;
            continue;
        }

        crow::json::rvalue refValue = content[reference->getName()];

        if(refValue.t() == crow::json::type::Null){ //no matching key was found in the json 
            CROW_LOG_INFO << reference->getName()  << " has no value in json";
            continue;
        }


        if(reference->isContainment()){ //handles all containment references; container (back-)references will also automaticly be set
            unsigned long referenceTypeID = result->eGet(reference)->getTypeId(); //Gets TypeID of the reference target
            bool isContainer = (reference->getUpperBound() > 1 || reference->getUpperBound() == -1);

            std::shared_ptr<Any> referenceContent = createAnyOfType(referenceTypeID, isContainer, refValue);
            
            result->eSet(reference, referenceContent);
            if (!result->eIsSet(reference)){
                CROW_LOG_ERROR << "failed to set " << reference->getName() <<" to " << referenceContent->toString();
            }
        }

        if(!reference->isContainer() && !reference->isContainment()){ //handles all references other than containment- and container-references
            m_crossReferenceBuffer.push_back({result, reference, refValue});
        }

    }
    return result;
}

std::shared_ptr<Any> Json2Ecore::createAnyOfType(const unsigned long typeId, const bool isContainer, const crow::json::rvalue& content){
    switch (typeId) {
            case ecore::ecorePackage::EBOOLEANOBJECT_CLASS:
            case ecore::ecorePackage::EBOOLEAN_CLASS:
                return writeAnyValue<bool>(typeId, isContainer, content);
                break;
            case ecore::ecorePackage::EBYTE_CLASS:
            case ecore::ecorePackage::EBYTEARRAY_CLASS:
            case ecore::ecorePackage::EBYTEOBJECT_CLASS:
            case ecore::ecorePackage::ECHARACTEROBJECT_CLASS:
            case ecore::ecorePackage::ECHAR_CLASS:
                return writeAnyValue<char>(typeId, isContainer, content);
                break;
            case ecore::ecorePackage::EDATE_CLASS:
            case ecore::ecorePackage::ERESOURCE_CLASS:
            case ecore::ecorePackage::EINTEGEROBJECT_CLASS:
            case ecore::ecorePackage::EBIGINTEGER_CLASS:
            case ecore::ecorePackage::ESHORT_CLASS:
            case ecore::ecorePackage::ESHORTOBJECT_CLASS:
            case ecore::ecorePackage::EINT_CLASS:
                return writeAnyValue<int>(typeId, isContainer, content);
                break;
            case ecore::ecorePackage::ELONGOBJECT_CLASS:
            case ecore::ecorePackage::ELONG_CLASS:
                return writeAnyValue<long>(typeId, isContainer, content);
                break;
            case ecore::ecorePackage::EFLOATOBJECT_CLASS:
            case ecore::ecorePackage::EFLOAT_CLASS:
                return writeAnyValue<float>(typeId, isContainer, content);
                break;
            case ecore::ecorePackage::EBIGDECIMAL_CLASS:
            case ecore::ecorePackage::EDOUBLE_CLASS:
            case ecore::ecorePackage::EDOUBLEOBJECT_CLASS:
                return writeAnyValue<double>(typeId, isContainer, content);
                break;
            case ecore::ecorePackage::ESTRING_CLASS:
                return writeAnyValue<std::string>(typeId, isContainer, content);
                break;
            default : //is a non primitive type -> eObject
                std::shared_ptr<Any> any = nullptr;
                if(isContainer){
                    auto bag = std::make_shared<Bag<ecore::EObject>>();
                    for(const crow::json::rvalue & entry : content){
                        bag->add(createObjectWithoutCrossRef(entry)); //recursive call creates each object that is being referenced 
                    }
                    any = eEcoreContainerAny(bag, typeId);
                }else{
                    auto value = createObjectWithoutCrossRef(content); //recursive call creates the referenced object 
                    any = eEcoreAny(value, typeId);
                }
                return any;
                break;
        }
}

template<typename T>
std::shared_ptr<Any> Json2Ecore::writeAnyValue(const unsigned long attributeTypeId, const bool isContainer, const crow::json::rvalue& content){
    if(isContainer){ //handling of Attributes with multiplicity of > 1
        std::shared_ptr<Bag<T>> bag = std::make_shared<Bag<T>>();
        for(const auto & entry : content){
            auto value = std::make_shared<T>(convert_to<T>(entry));
            bag->add(value);
        }
        return eAny(bag, attributeTypeId, true);
    }
    T val = convert_to<T>(content);
    return eAny(val, attributeTypeId, false);
}

//generic conversion methods for json
template<> bool Json2Ecore::convert_to<bool>(const crow::json::rvalue& value){
    return value.b();
}

template<> std::string Json2Ecore::convert_to<std::string>(const crow::json::rvalue& value){ //needed to preserve whitespaces in string
    return value.s();
}

template <typename T> T Json2Ecore::convert_to(const crow::json::rvalue& value){
    std::stringstream ss;
    ss << std::string(value);
    T num;
    ss >> num;
    return num;
}