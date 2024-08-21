#include "ModelInstance.hpp"

#include "ecore/EClass.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/EAttribute.hpp"

#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "ecore/EReference.hpp"

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

std::shared_ptr<Any> ModelInstance::getAnyAtPath(std::deque<std::string> path){
    std::string last_segment = path.back();
    path.pop_back();
    std::shared_ptr<EObject> obj = getObjectAtPath(path);
    std::shared_ptr<Any> ret_obj = getValueOfStructFeatureByName(obj,last_segment);
    return ret_obj;
}

std::shared_ptr<EObject> ModelInstance::getObjectAtPath(std::deque<std::string> path){
    std::shared_ptr<EObject> current_object = this->m_rootObject;
    
    while(!path.empty()){
        std::string next_path_segment = path.front();
        path.pop_front();
        //handling for normal StructuralFeatures; path_segment is in form: nameOfStructuralFeature
        std::string sFeatureName = next_path_segment;
        std::shared_ptr<Any> any = getValueOfStructFeatureByName(current_object,sFeatureName);
        //TODO maybe check if Any is nullptr?  
        try {
            std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(any);
            current_object = ecoreAny->getAsEObject(); //advances current_object to the Value of the StructualFeature with the same name as next_segment
        } catch (std::runtime_error& error){//Type cast to EObject failed
            throw std::runtime_error("malformed path error: "+ next_path_segment +" could not be cast to correct type or is primitive");
            return nullptr; //abort
        }
        
    }
    return current_object;
}

std::shared_ptr<Any> ModelInstance::getValueOfStructFeatureByName(const std::shared_ptr<EObject> obj ,const std::string& sFeatureIdentifier){

    const auto [stuctFeatureName, hasIndex, containerIndex] = helperFunctions::splitStructuralFeaturePathSegment(sFeatureIdentifier);
    if(!hasIndex){ //handling sFeatureName without container index 

        std::shared_ptr<EStructuralFeature> sFeature = obj->eClass()->getEStructuralFeature(stuctFeatureName); //gets sFeature by name from eClass of obj
        if(sFeature == nullptr){ //no strucural Feature with sFeatureName found
            throw std::runtime_error("structuralFeature: " + stuctFeatureName + " not found in " + obj->eClass()->getName() + "!");
            return nullptr; //abort
        }
        return obj->eGet(sFeature);
    }else{ //handling sFeatureName with container index 

        std::shared_ptr<EStructuralFeature> sFeature = obj->eClass()->getEStructuralFeature(stuctFeatureName); //gets sFeature by name from eClass of obj
        if(sFeature == nullptr){ //no strucural Feature with sFeatureName found
            throw std::runtime_error("structuralFeature: " + stuctFeatureName + " not found in " + obj->eClass()->getName() + "!");
            return nullptr; //abort
        }
        
        std::shared_ptr<Any> any = obj->eGet(sFeature); //get any container
        if(!any->isContainer()){ //check if Value of StructuralFeature is a container as it should be
            throw std::runtime_error("\""+ stuctFeatureName +"\" is not a container!");
            return nullptr; //abort
        }

        std::shared_ptr<EcoreContainerAny> ecore_container = std::dynamic_pointer_cast<EcoreContainerAny>(any);//cast into ECoreContainer
        if (ecore_container){ //true if type of StructFeature is a Class
            std::shared_ptr<Bag<EObject>> bag = ecore_container->getAsEObjectContainer();
            try{
                std::shared_ptr<EObject> content = bag->at(containerIndex);
                return eEcoreAny(content, content->eClass()->getClassifierID());
            }catch(std::out_of_range&){ 
                throw std::runtime_error("container index \""+ sFeatureIdentifier +"\" is out of range!");
                return nullptr; //abort
            }
        }else{ //type must be primitive (BOOLEAN, INTEGER, FLOAT, DOUBLE, LONG, CHAR, STRING)
            switch (any->getTypeId()) {
                case ecorePackage::EBOOLEAN_CLASS:{
                    auto bag = any->get<std::shared_ptr<Bag<bool>>>();
                    return eAny(*(bag->at(containerIndex)), any->getTypeId(), false); //dereferencing of "bag->at()" as to not insert a shared_ptr but the value of the bool  
                    break;
                }
                case ecorePackage::ECHAR_CLASS:{
                    auto bag = any->get<std::shared_ptr<Bag<char>>>();
                    return eAny(*(bag->at(containerIndex)), any->getTypeId(), false);
                    break;
                }
                case ecorePackage::EINT_CLASS:{
                    auto bag = any->get<std::shared_ptr<Bag<int>>>();
                    return eAny(*(bag->at(containerIndex)), any->getTypeId(), false);
                    break;
                }
                case ecorePackage::ELONG_CLASS:{
                    auto bag = any->get<std::shared_ptr<Bag<long>>>();
                    return eAny(*(bag->at(containerIndex)), any->getTypeId(), false);
                    break;
                }
                case ecorePackage::EFLOAT_CLASS:{
                    auto bag = any->get<std::shared_ptr<Bag<float>>>();
                    return eAny(*(bag->at(containerIndex)), any->getTypeId(), false);
                    break;
                }
                case ecorePackage::EDOUBLEOBJECT_CLASS:{
                    auto bag = any->get<std::shared_ptr<Bag<double>>>();
                    return eAny(*(bag->at(containerIndex)), any->getTypeId(), false);
                    break;
                }
                case ecorePackage::ESTRING_CLASS:{
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
    }
}

void ModelInstance::updateAttributeAtPath(std::deque<std::string> path, std::shared_ptr<Any> new_content){
    std::string structFeatureIdentifier = path.back();

    path.pop_back();
    std::shared_ptr<EObject> obj = getObjectAtPath(path);
    const auto [stuctFeatureName, hasIndex, containerIndex] = helperFunctions::splitStructuralFeaturePathSegment(structFeatureIdentifier);
    std::shared_ptr<EStructuralFeature> structFeature = obj->eClass()->getEStructuralFeature(stuctFeatureName);

    std::shared_ptr<EAttribute> attibute = std::dynamic_pointer_cast<EAttribute>(structFeature);
    if(attibute == nullptr){
        throw std::runtime_error("updateAttributeAtPath : " + stuctFeatureName + " is not an attribute!" );
    }

    if(structFeature->getUpperBound() == 1){
        if(hasIndex){
            throw std::runtime_error("updateAttributeAtPath : index used while updating a structFeature with multiplicity of 1!");
        }else{
            if(!new_content->isContainer()){
                obj->eSet(structFeature,new_content);
            }else{
                throw std::invalid_argument("updateAttributeAtPath : any has wrong container-flag");
            }
        }
    }else{ //attributes with multiplicty of > 1 or -1 
        if(hasIndex){//replace specified element in the bag 
            if(!new_content->isContainer()){
                std::shared_ptr<Any> any = obj->eGet(structFeature);
                helperFunctions::replaceElementInAnyBag(any, containerIndex, new_content);
            }else{
                throw std::invalid_argument("updateAttributeAtPath : any has wrong container-flag");
            }
        }else{//replace entire bag
            if(new_content->isContainer()){
                std::shared_ptr<Any> bag_ptr = obj->eGet(structFeature);
                helperFunctions::replaceCompleteAnyBag(bag_ptr, new_content);
            }else{
                throw std::invalid_argument("updateAttributeAtPath : any has wrong container-flag");
            }
        }
    } 
}

