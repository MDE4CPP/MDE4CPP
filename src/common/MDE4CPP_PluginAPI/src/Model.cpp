#include "Model.hpp"
#include "abstractDataTypes/Any.hpp"
#include "ecore/EClass.hpp"

Model::Model(std::shared_ptr<EObject> root_obj, std::string modelName){
    m_rootObject = root_obj;
    m_modelName = modelName;
}

std::shared_ptr<EObject> Model::getRootObject(){
    return m_rootObject;
}

void Model::setAlias(std::string alias, std::shared_ptr<EObject> obj){
    if(m_aliases.find(alias) != m_aliases.end()){ //check if alias is already used
        throw std::runtime_error("alias: "+ alias +" already in map");
        return;
    } 
    m_aliases[alias] =  obj;
}

std::shared_ptr<EObject> Model::lookUpAlias(std::string alias){
    auto f = m_aliases.find(alias);
    if(f == m_aliases.end()){ //alias is not present in m_aliases
        return nullptr;
    }else{
        return f->second;
    } 
}

const std::shared_ptr<EObject>& Model::navigateToObject(std::deque<std::string> path){
    std::shared_ptr<EObject> current_object = this->m_rootObject;
    
    while(!path.empty()){
        std::string next_path_segment = path.front();
        path.pop_front();
        switch(next_path_segment[0]){
            case '$': { //alias handling
                next_path_segment = next_path_segment.substr(1); //cuts $
                current_object = lookUpAlias(next_path_segment);
                if(current_object == nullptr){
                    throw std::runtime_error("alias $"+ next_path_segment +" used in path was not declared previosly");
                }
                break;
            }

            case '#': { //container handling
                std::deque<std::string> parts;
                helperFunctions::split_string(parts, next_path_segment, '@'); //splits into stings #ContainerName and a pure numeric string representing the index in the container
                if(parts.size() != 2){ //true if there are more than one '@' in next_path_segment
                    throw std::runtime_error("malformed container: \""+ next_path_segment +"\" used in path! Only one \'@\' allowed!");
                }
                parts[0] = parts[0].substr(1); // cuts # of from name of structuralFeature

                std::shared_ptr<Any> container = current_object->eGet(current_object->eClass()->getEStructuralFeature(parts[0]));
                if(!container->isContainer()){ //check if Value of StructuralFeature is a container
                    throw std::runtime_error("\""+ next_path_segment +"\" is not a container!");
                }
                //TODO get EObject out of container 
                break;
            }

            
            default :   //handling for normal StructuralFeatures
                try {
                    current_object = current_object->eGet(current_object->eClass()->getEStructuralFeature(next_path_segment))->get<std::shared_ptr<EObject>>(); //sets current_object to the Value of the StructualFeature with the same name as next_segment
                    //TODO split call for better readability
                    //TODO maybe check for nullptr?  
                } catch (std::runtime_error& error){    //Type cast to EObject failed
                    throw std::runtime_error("malformed path error: "+ next_path_segment +" could not be cast to correct type or is primitive");
                    return nullptr;
                }
                break;
        }
    }
    return current_object;
}


