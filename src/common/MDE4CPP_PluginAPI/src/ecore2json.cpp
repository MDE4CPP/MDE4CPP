#include "ecore2json.hpp"
#include "helpersFunc.hpp"

//PluginFramework includes
#include "pluginFramework/MDE4CPPPlugin.hpp"

//Ecore includes
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EcoreContainerAny.hpp"


Ecore2Json::Ecore2Json(){}

void Ecore2Json::createJsonOfEObject(const std::shared_ptr<ecore::EObject>& object, crow::json::wvalue& result_json){

    if(object == nullptr){
        throw std::runtime_error("createJson : object parameter was a nullptr!");
    }

    //sets "ObjectClass" and "ObjectID" keys
    std::string objClassName = getObjectClassName(object);
    auto objectID = reinterpret_cast<intptr_t>(object.get());
    CROW_LOG_INFO << "started creating json of " << objClassName << " with id: " << objectID;
    result_json["ObjectClass"] = objClassName;
    result_json["ObjectID"] = objectID;

    //parsing of all attributes
    std::shared_ptr<Bag<ecore::EAttribute>> attributes = object->eClass()->getEAllAttributes();
    for(const std::shared_ptr<ecore::EAttribute> & attribute : *attributes){
        if(attribute == nullptr){
            CROW_LOG_WARNING << "createJsonOfEObject() : an attribute was a nullptr";
            continue;   //skips nullptr
        }

        std::shared_ptr<Any> attributeValue = object->eGet(attribute);

        if(attributeValue->isEmpty()){ //skips attributes with no content
            CROW_LOG_WARNING << attribute->getName() <<" is not set!";
            continue;
        }

        unsigned long attributeTypeId = attributeValue->getTypeId();
        switch (attributeTypeId) {
            case ecore::ecorePackage::EBOOLEANOBJECT_CLASS:
            case ecore::ecorePackage::EBOOLEAN_CLASS:
            {
                writeAttributeValue<bool>(attributeValue, result_json[attribute->getName()]);
                CROW_LOG_INFO << "setting " << attribute->getName() << " to " << result_json[attribute->getName()].dump(); 
                break;
            }
            case ecore::ecorePackage::EBYTE_CLASS:
            case ecore::ecorePackage::EBYTEARRAY_CLASS:
            case ecore::ecorePackage::EBYTEOBJECT_CLASS:
            case ecore::ecorePackage::ECHARACTEROBJECT_CLASS:
            case ecore::ecorePackage::ECHAR_CLASS:
            {
                writeAttributeValue<char>(attributeValue, result_json[attribute->getName()]);
                CROW_LOG_INFO << "setting " << attribute->getName() << " to " << result_json[attribute->getName()].dump(); 
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
                writeAttributeValue<int>(attributeValue, result_json[attribute->getName()]);
                CROW_LOG_INFO << "setting " << attribute->getName() << " to " << result_json[attribute->getName()].dump(); 
                break;
            }
            case ecore::ecorePackage::ELONGOBJECT_CLASS:
            case ecore::ecorePackage::ELONG_CLASS:
            {
                writeAttributeValue<int>(attributeValue, result_json[attribute->getName()]);
                CROW_LOG_INFO << "setting " << attribute->getName() << " to " << result_json[attribute->getName()].dump(); 
                break;
            }
            case ecore::ecorePackage::EFLOATOBJECT_CLASS:
            case ecore::ecorePackage::EFLOAT_CLASS:
            {
                writeAttributeValue<float>(attributeValue, result_json[attribute->getName()]);
                CROW_LOG_INFO << "setting " << attribute->getName() << " to " << result_json[attribute->getName()].dump(); 
                break;
            }
            case ecore::ecorePackage::EBIGDECIMAL_CLASS:
            case ecore::ecorePackage::EDOUBLE_CLASS:
            case ecore::ecorePackage::EDOUBLEOBJECT_CLASS:
            {
                writeAttributeValue<double>(attributeValue, result_json[attribute->getName()]);
                CROW_LOG_INFO << "setting " << attribute->getName() << " to " << result_json[attribute->getName()].dump(); 
                break;
            }
            case ecore::ecorePackage::ESTRING_CLASS:
             {
                writeAttributeValue<std::string>(attributeValue, result_json[attribute->getName()]);
                CROW_LOG_INFO << "setting " << attribute->getName() << " to " << result_json[attribute->getName()].dump(); 
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

        Ecore2Json::referenceType refType = getRefType(reference);

        if(refType == Ecore2Json::BACK_REFERENCE){
            continue; //ignores all backreferences
        }

        if(object->eGet(reference)->isContainer()){ //muliplicy of reference > 1
            std::shared_ptr<Bag<ecore::EObject>> bag = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(object->eGet(reference))->getAsEObjectContainer();
            if(bag == nullptr){
                CROW_LOG_ERROR << "createJsonOfEObject : bag cast failed for Reference "<< reference->getName() << "!" ;
                continue;
            }

            if(bag->empty()){
                CROW_LOG_WARNING << "createJsonOfEObject : bag of Reference "<< reference->getName() << " was empty; skipping reference!";
                continue;
            }

            int i = 0;
            crow::json::wvalue& list = result_json[reference->getName()];
            for(const std::shared_ptr<ecore::EObject> & obj : *bag){
                if(obj == nullptr){
                    CROW_LOG_WARNING << "createJsonOfEObject : on refernce in "<< reference->getName() << " was a nullptr!" ;
                    continue;
                }

                switch (refType){
                case Ecore2Json::CONTAINMENT_REFERENCE :
                    createJsonOfEObject(obj, list[i]);
                    break;
                
                case Ecore2Json::CROSS_REFERENCE: 
                    list[i] = reinterpret_cast<intptr_t>(obj.get());
                    break;
                default:
                    throw std::runtime_error("unexpected referenceType encountered");
                    break;
                }

                i++;
            }
        }else{ //muliplicy of reference = 1

            std::shared_ptr<Any> any = object->eGet(reference);
            if(any->isEmpty()){
                CROW_LOG_WARNING << "createJsonOfEObject : any of Reference "<< reference->getName() << " was empty; skipping reference!";
                continue;
            }

            std::shared_ptr<ecore::EObject> refValue = object->eGet(reference)->get<std::shared_ptr<ecore::EObject>>();
            if(refValue == nullptr){//skipps reference if it points to null
                CROW_LOG_WARNING << "createJsonOfEObject : the value of "<< reference->getName() << " was a nullptr!" ;
                continue;
            }
            switch (refType){
                case Ecore2Json::CONTAINMENT_REFERENCE :
                    createJsonOfEObject(refValue, result_json[reference->getName()]);
                    break;

                case Ecore2Json::CROSS_REFERENCE: 
                    result_json[reference->getName()] =  reinterpret_cast<intptr_t>(refValue.get());
                    break;
                default:
                    throw std::runtime_error("unexpected referenceType encountered");
                    break;
            }
        }
    }
}

void Ecore2Json::createJsonOfAny(const std::shared_ptr<Any>& any, crow::json::wvalue& result_json){
    auto typeID = any->getTypeId();
    switch (typeID) {
        case ecore::ecorePackage::EBOOLEANOBJECT_CLASS:
        case ecore::ecorePackage::EBOOLEAN_CLASS:
        {
            writeAttributeValue<bool>(any, result_json);
            break;
        }
        case ecore::ecorePackage::EBYTE_CLASS:
        case ecore::ecorePackage::EBYTEARRAY_CLASS:
        case ecore::ecorePackage::EBYTEOBJECT_CLASS:
        case ecore::ecorePackage::ECHARACTEROBJECT_CLASS:
        case ecore::ecorePackage::ECHAR_CLASS:
        {
            writeAttributeValue<char>(any, result_json);
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
            writeAttributeValue<int>(any, result_json);
            break;
        }
        case ecore::ecorePackage::ELONGOBJECT_CLASS:
        case ecore::ecorePackage::ELONG_CLASS:
        {
            writeAttributeValue<int>(any, result_json);
            break;
        }
        case ecore::ecorePackage::EFLOATOBJECT_CLASS:
        case ecore::ecorePackage::EFLOAT_CLASS:
        {
            writeAttributeValue<float>(any, result_json);
            break;
        }
        case ecore::ecorePackage::EBIGDECIMAL_CLASS:
        case ecore::ecorePackage::EDOUBLE_CLASS:
        case ecore::ecorePackage::EDOUBLEOBJECT_CLASS:
        {
            writeAttributeValue<double>(any, result_json);
            break;
        }
        case ecore::ecorePackage::ESTRING_CLASS:
            {
            writeAttributeValue<std::string>(any, result_json);
            break;
        }
        default:{ //any contains an eObject
            if(any->isContainer()){//any can contain more than one EObject -> is a EcoreContainerAny
            
                std::shared_ptr<ecore::EcoreContainerAny> eConAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(any);
                if(eConAny == nullptr){//cast failed
                    CROW_LOG_ERROR <<"createJsonOfAny : any with type : \"" << typeID << "\" could not be cast into a EcoreContainerAny!";
                    break;
                }
                std::shared_ptr<Bag<ecore::EObject>> eObjBag = eConAny->getAsEObjectContainer();
                int index = 0;
                for(std::shared_ptr<ecore::EObject> obj : *eObjBag){
                    createJsonOfEObject(obj,result_json[index]);
                }
            }else{//any can only contain one EObject -> is a normal Any
                std::shared_ptr<ecore::EObject> obj = nullptr;
                try{
                    obj = any->get<std::shared_ptr<ecore::EObject>>();
                }
                catch(const std::runtime_error& e){
                    CROW_LOG_ERROR <<"createJsonOfAny : any with type : \"" << typeID << "\" could not be cast into an EObject!";
                    break;
                }
                createJsonOfEObject(obj,result_json);
            }
            break;
        }
    }
}

std::string Ecore2Json::getObjectClassName(const std::shared_ptr<ecore::EObject>& obj){
    std::string return_string = obj->eClass()->getName();
    std::shared_ptr<ecore::EPackage> package = obj->eClass()->getEPackage().lock();
    while(package != nullptr){
        return_string = package->getName() + "::" + return_string;
        package = package->getESuperPackage().lock();
    }
    return return_string;
}

Ecore2Json::referenceType Ecore2Json::getRefType(const std::shared_ptr<ecore::EReference>& eRef){
    if(eRef == nullptr){
        throw std::runtime_error("getRefType : Reference was a nullptr");
    }
    if(eRef->isContainment()){
        return Ecore2Json::CONTAINMENT_REFERENCE;
    }else if (eRef->isContainer())
    {
        return Ecore2Json::BACK_REFERENCE;
    }else{ //equal to (!eRef->isContainer() && !eRef->isContainment())
        return Ecore2Json::CROSS_REFERENCE;
    }
};

template<typename T>
void Ecore2Json::writeAttributeValue(const std::shared_ptr<Any>& any, crow::json::wvalue& return_json) {
    if( any->isContainer()){//attributes with multiplicity > 1 
        std::shared_ptr<Bag<T>> bag = any->get<std::shared_ptr<Bag<T>>>();
        int i = 0;
        for (const std::shared_ptr<T>& val : *bag) {
            T v = *val;
            return_json[i] = v;
            i++;
        }
    }else{//attributes with multiplicity = 1
        T v = any->get<T>();
        return_json = v;
    }
}
