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

void Ecore2Json::createJsonOfEObject(const std::shared_ptr<ecore::EObject>& object, crow::json::wvalue& result_json){

    if(object == nullptr){
        throw std::runtime_error("createJson : object parameter was a nullptr!");
    }

    //sets "ObjectClass" key
    std::string objClassName = object->eClass()->getName(); //TODO implement correctly : currently missing namespace of the class
    CROW_LOG_INFO << "started creating json of " << objClassName;
    result_json["ObjectClass"] = objClassName;

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
                if(! object->eGet(attribute)->isEmpty()){
                    writeFeature<bool>(object, attribute,result_json[attribute->getName()]);
                    CROW_LOG_INFO << "setting " << attribute->getName() << " to " << result_json[attribute->getName()].dump();
                }else{
                    CROW_LOG_WARNING << attribute->getName() <<" is not set!" ;
                    result_json[attribute->getName()].clear();
                }
                break;
            }
            case ecore::ecorePackage::EBYTE_CLASS:
            case ecore::ecorePackage::EBYTEARRAY_CLASS:
            case ecore::ecorePackage::EBYTEOBJECT_CLASS:
            case ecore::ecorePackage::ECHARACTEROBJECT_CLASS:
            case ecore::ecorePackage::ECHAR_CLASS:
            {
                if(! object->eGet(attribute)->isEmpty()){
                    writeFeature<char>(object, attribute,result_json[attribute->getName()]);
                    CROW_LOG_INFO << "setting " << attribute->getName() << " to " << result_json[attribute->getName()].dump();
                }else{
                    CROW_LOG_WARNING << attribute->getName() <<" is not set!" ;
                    result_json[attribute->getName()].clear();
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
                if(! object->eGet(attribute)->isEmpty()){
                    writeFeature<int>(object, attribute,result_json[attribute->getName()]);
                    CROW_LOG_INFO << "setting " << attribute->getName() << " to " << result_json[attribute->getName()].dump();
                }else{
                    CROW_LOG_WARNING << attribute->getName() <<" is not set!" ;
                    result_json[attribute->getName()].clear();
                }
                break;
            }
            case ecore::ecorePackage::ELONGOBJECT_CLASS:
            case ecore::ecorePackage::ELONG_CLASS:
            {
                if(! object->eGet(attribute)->isEmpty()){
                    writeFeature<int>(object, attribute,result_json[attribute->getName()]);
                    CROW_LOG_INFO << "setting " << attribute->getName() << " to " << result_json[attribute->getName()].dump();
                }else{
                    CROW_LOG_WARNING << attribute->getName() <<" is not set!" ;
                    result_json[attribute->getName()].clear();
                }
                break;
            }
            case ecore::ecorePackage::EFLOATOBJECT_CLASS:
            case ecore::ecorePackage::EFLOAT_CLASS:
            {
                if(! object->eGet(attribute)->isEmpty()){
                    writeFeature<float>(object, attribute,result_json[attribute->getName()]);
                    CROW_LOG_INFO << "setting " << attribute->getName() << " to " << result_json[attribute->getName()].dump();
                }else{
                    CROW_LOG_WARNING << attribute->getName() <<" is not set!" ;
                    result_json[attribute->getName()].clear();
                }
                break;
            }
            case ecore::ecorePackage::EBIGDECIMAL_CLASS:
            case ecore::ecorePackage::EDOUBLE_CLASS:
            case ecore::ecorePackage::EDOUBLEOBJECT_CLASS:
            {
                if(! object->eGet(attribute)->isEmpty()){
                    writeFeature<double>(object, attribute,result_json[attribute->getName()]);
                    CROW_LOG_INFO << "setting " << attribute->getName() << " to " << result_json[attribute->getName()].dump();
                }else{
                    CROW_LOG_WARNING << attribute->getName() <<" is not set!" ;
                    result_json[attribute->getName()].clear();
                }
                break;
            }
            case ecore::ecorePackage::ESTRING_CLASS:
             {
                std::shared_ptr<Any> any = object->eGet(attribute);
                if(! any->isEmpty()){
                    writeFeature<std::string>(object, attribute,result_json[attribute->getName()]);
                    CROW_LOG_INFO << "setting " << attribute->getName() << " to " << result_json[attribute->getName()].dump();
                }else{
                    CROW_LOG_WARNING << attribute->getName() <<" is not set!" ;
                    result_json[attribute->getName()].clear();
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
                crow::json::wvalue& list = result_json[reference->getName()];
                auto bag = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(object->eGet(reference))->getAsEObjectContainer();
                if(bag == nullptr){
                    CROW_LOG_WARNING << "createJsonOfEObject : bag cast failed for Reference "<< reference->getName() << "!" ;
                }
                int i = 0;
                for(const std::shared_ptr<ecore::EObject> & obj : *bag){
                    if(obj == nullptr){
                    CROW_LOG_WARNING << "createJsonOfEObject : on refernce in "<< reference->getName() << " was a nullptr!" ;
                    continue;
                    }
                    createJsonOfEObject(obj, list[i]);
                    i++;
                }
            }else{
                auto refValue = object->eGet(reference)->get<std::shared_ptr<ecore::EObject>>();
                if(refValue == nullptr){
                    CROW_LOG_WARNING << "createJsonOfEObject : the value of "<< reference->getName() << " was a nullptr!" ;
                }
                createJsonOfEObject(refValue, result_json[reference->getName()]);
            }
        }
        if(!isContainer(reference) && !reference->isContainment()){//parses crossReferences //TODO fix setting of m_container
            //TODO set approriate path for reference!!!!
            result_json[reference->getName()] =  reinterpret_cast<intptr_t>(object->eGet(reference).get());
        }
    }
}

std::string Ecore2Json::getObjectClassName(const std::shared_ptr<ecore::EObject>& obj){
    std::shared_ptr<ecore::EClass> c = obj->eClass();
    std::string return_string = "";
    while(c != nullptr){
        return_string = c->getName();
        //TODO get namespace of a class
    }
    return return_string;
}

bool Ecore2Json::isContainer(const std::shared_ptr<ecore::EReference>& eRef){ //neccesary since isConstainer Function of eReference is not implemented
    bool ret = false;
    try{
        auto eOp = eRef->getEOpposite();
        if(eOp != nullptr && eOp->isContainment()){
            ret = true;
        }
    }catch(...){
        std::cout<< "ecore2json::isContainer : An error rccurred!" << std::endl;
    }
    return ret;
}


template<typename T>
void Ecore2Json::writeFeature(const std::shared_ptr<ecore::EObject> &object, const std::shared_ptr<ecore::EStructuralFeature> &feature, crow::json::wvalue& return_json) {
    bool isContainer = object->eGet(feature)->isContainer();
    if(isContainer){
        std::shared_ptr<Bag<T>> bag = object->eGet(feature)->get<std::shared_ptr<Bag<T>>>();
        int i = 0;
        for (const std::shared_ptr<T>& val : *bag) {
            T v = *val;
            //auto o = crow::json::wvalue(v);
            return_json[i] = v;
            i++;
        }
    }else{
        std::shared_ptr<Any> any = object->eGet(feature);
        T v = any->get<T>();
        return_json = v;
    }
}
