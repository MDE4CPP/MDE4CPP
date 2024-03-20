#include "Model.hpp"

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

