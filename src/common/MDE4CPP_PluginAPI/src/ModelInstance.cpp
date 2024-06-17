#include "ModelInstance.hpp"
#include "abstractDataTypes/Any.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/Bag.hpp"
#include <string>

ModelInstance::ModelInstance(const std::shared_ptr<EObject> root_obj /* = nullptr*/, const std::string modelInstName /* = untitled modelInstance*/){
    m_rootObject = root_obj;
    m_modelInstanceName = modelInstName;
}

std::shared_ptr<EObject> ModelInstance::getRootObject(){
    return m_rootObject;
}

void ModelInstance::setAlias(std::string alias, std::shared_ptr<EObject> obj){
    if(m_aliases.find(alias) != m_aliases.end()){ //check if alias is already used
        throw std::runtime_error("alias: "+ alias +" already in map");
        return;
    } 
    std::weak_ptr<EObject> wptr = obj;
    m_aliases[alias] =  wptr;
}

std::shared_ptr<EObject> ModelInstance::lookUpAlias(std::string alias){
    auto f = m_aliases.find(alias);
    if(f == m_aliases.end()){ //alias is not present in m_aliases
        return nullptr;
    }else{
        return f->second.lock(); //TODO handle deleted EObjects
    } 
}

std::shared_ptr<Any> ModelInstance::getAnyAtPath(std::shared_ptr<std::deque<std::string>>& path){
    std::string last_segment = path->back();
    path->pop_back();
    std::shared_ptr<EObject> obj = getObjectAtPath(path);
    std::shared_ptr<Any> ret_obj = getValueOfStructFeatureByName(obj,last_segment);
    return ret_obj;
}

std::shared_ptr<EObject> ModelInstance::getObjectAtPath(std::shared_ptr<std::deque<std::string>>& path){
    std::shared_ptr<EObject> current_object = this->m_rootObject;
    
    while(!path->empty()){
        std::string next_path_segment = path->front();
        path->pop_front();
        switch(next_path_segment[0]){ //check first char in next_path_segment

            case '$': { //alias handling; path segment is in form: $alias  
                std::string alias = next_path_segment.substr(1); //cuts $
                current_object = lookUpAlias(alias);
                if(current_object == nullptr){
                    throw std::runtime_error("alias "+ next_path_segment +" used in path was not declared previosly");
                    return nullptr; //abort
                }
                break;
            }
            default :   //handling for normal StructuralFeatures; path_segment is in form: nameOfStructuralFeature
                std::string sFeatureName = next_path_segment;
                std::shared_ptr<Any> any = getValueOfStructFeatureByName(current_object,sFeatureName);
                //TODO maybe check if Any is nullptr?  
                try {
                    current_object = any->get<std::shared_ptr<EObject>>(); //advances current_object to the Value of the StructualFeature with the same name as next_segment
                } catch (std::runtime_error& error){    //Type cast to EObject failed
                    throw std::runtime_error("malformed path error: "+ next_path_segment +" could not be cast to correct type or is primitive");
                    return nullptr; //abort
                }
                break;
        }
    }
    return current_object;
}

std::shared_ptr<Any> ModelInstance::getValueOfStructFeatureByName(const std::shared_ptr<EObject> obj ,const std::string& sFeatureName){

    auto segmentedString = helperFunctions::split_string(sFeatureName,'@'); 
    switch (segmentedString->size())//first enty in sFeatureName_segments will be name of the StructuralFeature, if a second entry exists it will be an index for the container as an int
    {
    case 1:{ //handling sFeatureName without container index 
        std::shared_ptr<EStructuralFeature> sFeature = obj->eClass()->getEStructuralFeature(segmentedString->at(0)); //gets sFeature by name from eClass of obj
        if(sFeature == nullptr){ //no strucural Feature with sFeatureName found
            throw std::runtime_error("structuralFeature: " + segmentedString->at(0) + " not found in " + obj->eClass()->getName() + "!");
            return nullptr; //abort
        }
        return obj->eGet(sFeature);
        break;}

    case 2:{ //handling sFeatureName with container index 

        int containerIndex = std::stoi(segmentedString->at(1)); //convert second string in parts to int

        std::shared_ptr<EStructuralFeature> sFeature = obj->eClass()->getEStructuralFeature(segmentedString->at(0)); //gets sFeature by name from eClass of obj
        if(sFeature == nullptr){ //no strucural Feature with sFeatureName found
            throw std::runtime_error("structuralFeature: " + segmentedString->at(0) + " not found in " + obj->eClass()->getName() + "!");
            return nullptr; //abort
        }
        
        std::shared_ptr<Any> any = obj->eGet(sFeature); //get any container
        if(!any->isContainer()){ //check if Value of StructuralFeature is a container as it should be
            throw std::runtime_error("\""+ segmentedString->at(0) +"\" is not a container!");
            return nullptr; //abort
        }

        std::shared_ptr<EcoreContainerAny> ecore_container = std::dynamic_pointer_cast<EcoreContainerAny>(any);//cast into ECoreContainer
        if (ecore_container){ //true if type of StruxtFeature is a Class
            std::shared_ptr<Bag<EObject>> bag = ecore_container->getAsEObjectContainer();
            try{
                std::shared_ptr<EObject> content = bag->at(containerIndex);
                return eAny(content, content->eClass()->getClassifierID(), false);
            }catch(std::out_of_range&){ 
                throw std::runtime_error("container index \""+ sFeatureName +"\" is out of range!");
                return nullptr; //abort
            }
        }else{ //type must be primitive (BOOLEAN, INTEGER, FLOAT, DOUBLE, LONG, CHAR, STRING)
            switch (any->getTypeId()) {
                case ecore::ecorePackage::EBOOLEAN_CLASS:{
                    auto bag = any->get<std::shared_ptr<Bag<bool>>>();
                    return eAny(*(bag->at(containerIndex)), any->getTypeId(), false); //dereferencing of "bag->at()" as to not insert a shared_ptr but the value of the bool  
                    break;
                }
                case ecore::ecorePackage::ECHAR_CLASS:{
                    auto bag = any->get<std::shared_ptr<Bag<char>>>();
                    return eAny(*(bag->at(containerIndex)), any->getTypeId(), false);
                    break;
                }
                case ecore::ecorePackage::EINT_CLASS:{
                    auto bag = any->get<std::shared_ptr<Bag<int>>>();
                    return eAny(*(bag->at(containerIndex)), any->getTypeId(), false);
                    break;
                }
                case ecore::ecorePackage::ELONG_CLASS:{
                    auto bag = any->get<std::shared_ptr<Bag<long>>>();
                    return eAny(*(bag->at(containerIndex)), any->getTypeId(), false);
                    break;
                }
                case ecore::ecorePackage::EFLOAT_CLASS:{
                    auto bag = any->get<std::shared_ptr<Bag<float>>>();
                    return eAny(*(bag->at(containerIndex)), any->getTypeId(), false);
                    break;
                }
                case ecore::ecorePackage::EDOUBLEOBJECT_CLASS:{
                    auto bag = any->get<std::shared_ptr<Bag<double>>>();
                    return eAny(*(bag->at(containerIndex)), any->getTypeId(), false);
                    break;
                }
                case ecore::ecorePackage::ESTRING_CLASS:{
                    auto bag = any->get<std::shared_ptr<Bag<std::string>>>();
                    return eAny(*(bag->at(containerIndex)), any->getTypeId(), false);
                    break;
                }
                default: //should not get here -> unsupported DataType
                    throw std::runtime_error("unsupported type: " + any->getTypeId());
                    return nullptr; //abort
                    break;
            }
        }
        break;
    }
    default: //should not get here; eighter empty sFeatureName or more than one '@' in sFeatureName
        throw std::runtime_error("malformed sFeatureName:" + sFeatureName + "!");
        return nullptr; //abort
        break;
    }
}

/*std::deque<std::string> ModelInstance::getPathAsString(const std::shared_ptr<EObject>& obj){
    std::shared_ptr<EObject> currentObj = obj;
    std::string returnString;
    while(currentObj->eContainer() != nullptr){ //if nullptr -> root_obj

        auto prevStructFeature = currentObj->eContainer();
    }

}*/
