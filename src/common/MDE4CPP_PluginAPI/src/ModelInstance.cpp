#include "ModelInstance.hpp"

#include "ecore/EClass.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EObject.hpp"

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
                case ecore::ecorePackage::EBOOLEANOBJECT_CLASS:
                case ecorePackage::EBOOLEAN_CLASS:{
                    auto bag = any->get<std::shared_ptr<Bag<bool>>>();
                    return eAny(*(bag->at(containerIndex)), any->getTypeId(), false); //dereferencing of "bag->at()" as to not insert a shared_ptr but the value of the bool  
                    break;
                }
                case ecore::ecorePackage::EBYTE_CLASS:
                case ecore::ecorePackage::EBYTEARRAY_CLASS:
                case ecore::ecorePackage::EBYTEOBJECT_CLASS:
                case ecore::ecorePackage::ECHARACTEROBJECT_CLASS:
                case ecorePackage::ECHAR_CLASS:{
                    auto bag = any->get<std::shared_ptr<Bag<char>>>();
                    return eAny(*(bag->at(containerIndex)), any->getTypeId(), false);
                    break;
                }
                case ecore::ecorePackage::EDATE_CLASS:
                case ecore::ecorePackage::ERESOURCE_CLASS:
                case ecore::ecorePackage::EINTEGEROBJECT_CLASS:
                case ecore::ecorePackage::EBIGINTEGER_CLASS:
                case ecore::ecorePackage::ESHORT_CLASS:
                case ecore::ecorePackage::ESHORTOBJECT_CLASS:
                case ecorePackage::EINT_CLASS:{
                    auto bag = any->get<std::shared_ptr<Bag<int>>>();
                    return eAny(*(bag->at(containerIndex)), any->getTypeId(), false);
                    break;
                }
                case ecore::ecorePackage::ELONGOBJECT_CLASS:
                case ecorePackage::ELONG_CLASS:{
                    auto bag = any->get<std::shared_ptr<Bag<long>>>();
                    return eAny(*(bag->at(containerIndex)), any->getTypeId(), false);
                    break;
                }
                case ecore::ecorePackage::EFLOATOBJECT_CLASS:
                case ecorePackage::EFLOAT_CLASS:{
                    auto bag = any->get<std::shared_ptr<Bag<float>>>();
                    return eAny(*(bag->at(containerIndex)), any->getTypeId(), false);
                    break;
                }
                case ecore::ecorePackage::EBIGDECIMAL_CLASS:
                case ecore::ecorePackage::EDOUBLE_CLASS:
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

std::vector<std::shared_ptr<EObject>> ModelInstance::collectAllObjectsInSubtreeOfAnObject(std::shared_ptr<EObject> obj_ptr){
    std::vector<std::shared_ptr<EObject>> resultVector;
    _collectAllObjectsInSubtreeOfAnObject(obj_ptr, resultVector);
    return resultVector;
}

void ModelInstance::_collectAllObjectsInSubtreeOfAnObject(std::shared_ptr<EObject> obj_ptr, std::vector<std::shared_ptr<EObject>> &resultVectorRef){
    resultVectorRef.push_back(obj_ptr); //insert current obj (obj_ptr)
    std::shared_ptr<Bag<ecore::EReference>> eRefs = obj_ptr->eClass()->getEAllReferences();
    for(std::shared_ptr<ecore::EReference> eRef : *eRefs){ //iterate over all references of current object (obj_ptr)
        if(eRef->isContainment()){//only collect objects contained by the current obj; skip cross-references
            std::shared_ptr<Any> ref_any = obj_ptr->eGet(eRef);
            if (ref_any->isContainer()){ //handle references with multilicity of > 1
                std::shared_ptr<EcoreContainerAny> ref_eContainerAny = std::dynamic_pointer_cast<EcoreContainerAny>(ref_any);
                std::shared_ptr<Bag<EObject>> ref_objBag = ref_eContainerAny->getAsEObjectContainer(); 
                for(std::shared_ptr<ecore::EObject> refEObj : *ref_objBag){
                    _collectAllObjectsInSubtreeOfAnObject(refEObj, resultVectorRef);//recursive call with each eObj in Reference
                }
            }else{ //handle references with multilicity of = 1
                std::shared_ptr<EcoreAny> ref_eAny = std::dynamic_pointer_cast<EcoreAny>(ref_any);
                _collectAllObjectsInSubtreeOfAnObject(ref_eAny->getAsEObject(), resultVectorRef);//recursive call
            }
        }
    }
}

void ModelInstance::removeCrossRefsToObject(const std::shared_ptr<EObject> obj_to_remove){
    _removeCrossRefsToObject(this->m_rootObject, obj_to_remove);
}

void ModelInstance::_removeCrossRefsToObject(const std::shared_ptr<EObject> current_object ,  const std::shared_ptr<EObject> obj_to_remove){

    std::cout<<"for an object of class: "<< current_object->eClass()->getName()<<std::endl;
    auto anObjRefs = current_object->eClass()->getEAllReferences();
    for (auto aRef : *anObjRefs)
    {
        if (!aRef->isContainment() && !aRef->isContainer())
        { //handle all cross-References
            auto ref_any = current_object->eGet(aRef);
            if (ref_any->isContainer())//multiplicity > 1
            {
                std::shared_ptr<EcoreContainerAny> ref_eContainerAny = std::dynamic_pointer_cast<EcoreContainerAny>(ref_any);
                std::shared_ptr<Bag<EObject>> ref_objBag = ref_eContainerAny->getAsEObjectContainer();
                auto it = ref_objBag->find(obj_to_remove);
                if(it != ref_objBag->end()){    
                    ref_objBag->erase(it);// TODO is this enough to delete it? Or does the new Bag has to be written back with an eSet? 
                    std::cout<<"erased reference to " << obj_to_remove->eClass()->getName() << " in bag of: "<< current_object->eClass()->getName() << "/" << aRef->getName() <<std::endl;
                }else{
                    //std::cout<<" did not find reference to " << obj->eClass()->getName() << " in : "<< anObj->eClass()->getName() << "/" << aRef->getName() <<std::endl;
                }
                current_object->eSet(aRef,eEcoreContainerAny(ref_objBag, ref_eContainerAny->getTypeId()));
            }else{//multiplicity == 1
                std::shared_ptr<EcoreAny> ref_eAny = std::dynamic_pointer_cast<EcoreAny>(ref_any);
                if( ref_eAny->getAsEObject() == obj_to_remove){
                    unsigned long typeID = current_object->eGet(aRef)->getTypeId(); // TODO simplify
                    current_object->eSet(aRef, eEcoreAny(aRef->getDefaultValue(), typeID)); //TODO how to unset a reference? Replace content with EcoreAny containing a nullptr?
                    std::cout<<"erased reference to " << obj_to_remove->eClass()->getName() << " of: "<< current_object->eClass()->getName() << "/" << aRef->getName() <<std::endl;
                }else
                {
                    //std::cout<<"did not find reference to " << obj->eClass()->getName() << " in : "<< anObj->eClass()->getName() << "/" << aRef->getName() <<std::endl;
                }
            }        
        }else
        {
            if(aRef->isContainment()){ //recursively call this for all contained objects
                auto ref_any = current_object->eGet(aRef);
                if (ref_any->isContainer())
                {//multiplicity > 1
                    std::shared_ptr<EcoreContainerAny> ref_eContainerAny = std::dynamic_pointer_cast<EcoreContainerAny>(ref_any);
                    std::shared_ptr<Bag<EObject>> ref_objBag = ref_eContainerAny->getAsEObjectContainer();
                    for (std::shared_ptr<EObject> next_obj: *ref_objBag)
                    {
                        _removeCrossRefsToObject(next_obj, obj_to_remove);
                    }      
                }else
                {//multiplicity == 1
                    std::shared_ptr<EcoreAny> ref_eAny = std::dynamic_pointer_cast<EcoreAny>(ref_any);
                    std::shared_ptr<EObject> next_obj = ref_eAny->getAsEObject();
                    _removeCrossRefsToObject(next_obj, obj_to_remove);
                }               
            }
        }
    }
}
