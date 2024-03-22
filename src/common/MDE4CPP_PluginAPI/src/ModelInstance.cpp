#include "ModelInstance.hpp"
#include "abstractDataTypes/Any.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/Bag.hpp"
#include <string>

ModelInstance::ModelInstance(std::shared_ptr<EObject> root_obj, std::string modelInstName){
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
        return f->second.lock();
    } 
}



const std::shared_ptr<EObject>& ModelInstance::getObjectAtPath(std::deque<std::string>& path){
    std::shared_ptr<EObject> current_object = this->m_rootObject;
    
    while(!path.empty()){
        std::string next_path_segment = path.front();
        path.pop_front();
        switch(next_path_segment[0]){

            case '$': { //alias handling; path segment is in form: $alias  
                std::string alias = next_path_segment.substr(1); //cuts $
                current_object = lookUpAlias(alias);
                if(current_object == nullptr){
                    throw std::runtime_error("alias "+ next_path_segment +" used in path was not declared previosly");
                    return nullptr; //abort
                }
                break;
            }

            case '#': { //container handling; path_segment is in form: #nameOfStructuralFeature@indexInContainer
                std::deque<std::string> parts;
                helperFunctions::split_string(parts, next_path_segment, '@'); //splits into stings #nameOfStructuralFeature and the indexInContainer which is numeric string
                if(parts.size() != 2){ //true if there are more than one '@' in next_path_segment
                    throw std::runtime_error("malformed container: \""+ next_path_segment +"\" used in path! Only one \'@\' allowed!");
                    return nullptr; //abort
                }
                std::string sFeatureName = parts[0].substr(1); // cuts # of from name of structuralFeature
                std::shared_ptr<Any> any = getValueOfStructFeatureByName(current_object,sFeatureName);

                std::shared_ptr<EcoreContainerAny> container = std::dynamic_pointer_cast<EcoreContainerAny>(any);
                //TODO maybe check if Any is nullptr?
                if(!container->isContainer()){ //check if Value of StructuralFeature is a container
                    throw std::runtime_error("\""+ next_path_segment +"\" is not a container!");
                    return nullptr; //abort
                }
                
                std::shared_ptr<Bag<EObject>> bag = container->getAsEObjectContainer();
                int containerIndex = std::stoi(parts[1]); //convert second string in parts to int
                std::shared_ptr<EObject> obj;
                
                try{
                    obj = bag->at(containerIndex);
                }catch(std::out_of_range){ 
                    throw std::runtime_error("container index \""+ next_path_segment +"\" is out of range!");
                    return nullptr; //abort
                }
                return obj;
                break;
            }

            
            default :   //handling for normal StructuralFeatures; path_segment is in form: nameOfStructuralFeature
                std::string sFeatureName = next_path_segment;
                std::shared_ptr<Any> any = getValueOfStructFeatureByName(current_object,sFeatureName);
                //TODO maybe check if Any is nullptr?  
                try {
                    current_object = any->get<std::shared_ptr<EObject>>(); //sets current_object to the Value of the StructualFeature with the same name as next_segment
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
    std::shared_ptr<EStructuralFeature> sFeature = obj->eClass()->getEStructuralFeature(sFeatureName); //gets sFeature by name from eClass of obj
    if(sFeature == nullptr){ //no strucural Feature with sFeatureName found
        throw std::runtime_error("structuralFeature: \""+sFeatureName+"\" not found in " + obj->eClass()->getName() + "!");
        return nullptr; //abort
    }
    return obj->eGet(sFeature);
}


