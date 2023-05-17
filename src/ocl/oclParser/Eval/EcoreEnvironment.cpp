#include "EcoreEnvironment.h"
#include "EcoreEval.h"

#include "../Utilities/ConstStrings.h"

#include <ecore/EClass.hpp>
#include <ecore/EAttribute.hpp>
#include <ecore/EOperation.hpp>
#include <ecore/EStructuralFeature.hpp>
#include <ecore/EStringToStringMapEntry.hpp>
#include <ecore/EcoreAny.hpp>
#include <ecore/ecoreFactory.hpp>
#include <ecore/ecorePackage.hpp>

using namespace Eval;

const std::string EcoreEnvironment::SELF_VARIABLE_NAME = Utilities::CONST_SELF;

EcoreEnvironment::~EcoreEnvironment()
{
    m_parent.reset();
	m_evalEnv.reset();
	m_self.reset();
    m_namedElements.clear();
}

/*!
* \brief Find a Object in the current environment, not in its parents, based on a single name.
* \param name
* \return nullptr if the element is not found.
*/
std::shared_ptr<Any> EcoreEnvironment::lookupLocal(const std::string& name)
{
    
    if (name == Utilities::CONST_SELF) {
        return getSelfVariable();
    } else {

        if(m_namedElements.find(name) != m_namedElements.end()) {
            return std::get<1>(m_namedElements.at(name));
        }

        // check if unique in self
        std::shared_ptr<Any> result = lookupPropertyName(name, m_self);
        if (result != nullptr){
            return result;
        }
        // check if unique in the (possible) current context
        if (m_context != m_self){
            return lookupPropertyName(name, m_context);
        }

        return emptyResult();

    }
    
}

/*!
* \brief Find a Object in the current environment or recursively in its parent environment, based on a single name.
* \param name
* \return nullptr if the element is not found.
*/
std::shared_ptr<Any> EcoreEnvironment::lookup(const std::string& name) {

    std::shared_ptr<Any> result = lookupLocal(name);

    if(result == nullptr && m_parent != nullptr) {
        result = m_parent->lookup(name);
    }

    return result;

    // result = lookupExternal(name);
    // if (result != nullptr) {
    //     return result; 
    // } else {
    //     return emptyResult();
    // }


}

/*!
* \brief Find an Object in the given context (self) based on its name
* \param names
* \return nullptr if the element is not found.
*/
// WIP
// std::shared_ptr<Any> EcoreEnvironment::lookupExternal(const std::string& name) {

//     unsigned long long elemId = m_self->getTypeId();

//     switch (elemId)
//     {
//     case ecore::ecorePackage::ECLASS_CLASS:
//         //TODO work with EClass
//         break;
//     case ecore::ecorePackage::EATTRIBUTE_CLASS:
//         //TODO work with EAttribute
//         break;
//     case ecore::ecorePackage::EREFERENCE_CLASS:
//         //TODO work with EReference
//         break;
//     case ecore::ecorePackage::EOPERATION_CLASS:
//         //TODO work with EOperation
//         break;
//     case ecore::ecorePackage::EPACKAGE_CLASS:
//         //TODO work with EPackage
//         break;
//     case ecore::ecorePackage::ECLASSIFIER_CLASS:
//         //TODO work with EClassifier
//         break;
//     case ecore::ecorePackage::EOBJECT_CLASS:
//         //TODO work with EObject
//         break;
//     }

//     return emptyResult();

// }

/*!
* \brief Find a Object in the current environment or recursively in its parent environment, based on a single name and the implicity.
* \param name
* \return nullptr if the element is not found.
*/
std::shared_ptr<Any> EcoreEnvironment::lookupImplicit(const std::string& name)
{

    for(auto &e : m_namedElements) {
        if(e.first == (Utilities::CONST_IMPLICIT+name)) {
            return std::get<1>(e.second);
        }
    }
    return emptyResult();
}

/*!
* \brief This operation results in a new environment that has the current one as its parent.
* \return a new environment.
*/
// TODO this als Parameter
// std::shared_ptr<EcoreEnvironment> EcoreEnvironment::nestedEnvironment()
// {
//     std::shared_ptr<EcoreEnvironment> sharedEnv = std::shared_ptr<EcoreEnvironment>(this);
//     EcoreEnvironment newEnv = EcoreEnvironment(sharedEnv);
//     std::shared_ptr<EcoreEnvironment> input = std::make_shared<EcoreEnvironment>(newEnv);
    
//     return std::make_shared<EcoreEnvironment>(input);
// }

/*!
* \brief Add a new object to the environment. The type can be set to "".
* \return true if the element is added, false if the element is already contained
*/
bool EcoreEnvironment::addElement(const std::string& name, std::shared_ptr<Any> elem, bool isImplicit, std::string type)
{
    //check if implicit
    std::string elemName = (isImplicit) ? (Utilities::CONST_IMPLICIT+name) : name;
    
    //check if name is given
    if(name.empty()) {
        //set a generatedName, this name have to be unique everywhere
        elemName = elemName+generateName();
        //repeat generating process until name is unique
        //in the env and self and (possible) context
        while (lookup(elemName) != nullptr) {
            elemName = (isImplicit) ? (Utilities::CONST_IMPLICIT+name+generateName()) : generateName();
        }
        m_namedElements[elemName] = std::make_tuple(type, elem);
        return true;
    }//END add generate name

    // check if the given name is unique in the local Env
    // the nearest scope will set the variables value -> no need to check above environments
    if(lookupLocal(elemName) != nullptr) {
        return false;
    }

    //elem->setName(elemName);
    m_namedElements[elemName] = std::make_tuple(type, elem);

    return true;
}

/*!
* \brief Allowing changing namedElements. Used in loops for the loop elem.
* \return true if successfull false if not
*/
bool EcoreEnvironment::changeNamedElement(const std::string& name, std::shared_ptr<Any> newElem) {
    
    std::unordered_map<std::string, std::tuple<std::string, std::shared_ptr<Any>>>::iterator it = m_namedElements.find(name);
    if (it != m_namedElements.end()) {
        // add if type is equal or not set
        if (getTypeName(newElem) == std::get<0>(it->second) || std::get<0>(it->second) == "") {
            std::get<1>(it->second) = newElem;
            return true;
        }
        //current exception are Collections, because they are always Bags with no explicit type
        //TODO use of inner type
        if (newElem->isContainer() 
        && (std::get<0>(it->second) == Utilities::CONST_BAG
        || std::get<0>(it->second) == Utilities::CONST_SEQUENCE 
        || std::get<0>(it->second) == Utilities::CONST_SET 
        || std::get<0>(it->second) == Utilities::CONST_ORDEREDSET))
        {
            std::get<1>(it->second) = newElem;
            return true;
        }
    }

    return false;

}

/*!
* \brief Generates a new, unique name for an implicit iterator variable.
* \return the new name.
*/
std::string EcoreEnvironment::generateName()
{
    m_generatorInt++;
    return "temp" + std::to_string(m_generatorInt);
}

// returns an empty any (nullptr)
std::shared_ptr<Any> EcoreEnvironment::emptyResult() {

    //std::shared_ptr<Any> empty;
    
    return nullptr;

}

/*! 
*  \brief returns the first Environment with no parent (including this)
*  \return the first Environment with no parent (including this)
*/
std::shared_ptr<EcoreEnvironment> EcoreEnvironment::getRootEnv()
{
    std::shared_ptr<EcoreEnvironment> env = std::shared_ptr<EcoreEnvironment>(this);

    while (env->m_parent != nullptr) {
        env = env->m_parent;
    }
    return env;
}

// non OCL functions ###

//### lookupVariableName ###

// looks for a VariableName directly in self
// returns nullptr if variable with given name is not found
// only 'self' will be requested here, all other properties will be requested in PropertyCallExp
std::shared_ptr<Any> EcoreEnvironment::lookupVariableName(const std::string& name) {

    // self object is requested
    if (name == Utilities::CONST_SELF) {
        return getSelfVariable();
    } 
    return emptyResult();

}

//looks for the given (property) name in the given (EClass) context
//returns nullptr if property with name is not found
std::shared_ptr<Any> EcoreEnvironment::lookupPropertyName(const std::string& name, std::shared_ptr<Any> context) {

    //try as ecoreAny
    std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(context);

    if (ecoreAny == nullptr) {
        //TODO add error
        //context have to be an ecoreAny
        return emptyResult();
    }

    //get eObject to get eClass
    std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();

    if (eObject == nullptr) {
        //TODO add error can't get eObject out of ecoreAny
        return emptyResult();
    }
    
    //try to get eClass
    std::shared_ptr<ecore::EClass> eClass = eObject->eClass();

    if (eClass == nullptr) {
        //TODO add error
        //eObject have no class
        return emptyResult();
    }

    //find property with given name
    size_t size = eClass->getEAllStructuralFeatures()->size();

    std::shared_ptr<ecore::EStructuralFeature> foundFeat;

    for (size_t i = 0; i < size; i++) {
        const std::shared_ptr<ecore::EStructuralFeature>& elem = eClass->getEAllStructuralFeatures()->at(i);
        if (name == elem->getName()) {
            foundFeat = elem;
            break;
        }
    }

    //check if found
    if (foundFeat == nullptr) {
        //TODO property name 'name' in eClass.getName() not found
        return emptyResult();
    }

    //get actual object
    const std::shared_ptr<Any>& returnObject = eObject->eGet(foundFeat);

    return returnObject;
}

//looks for the given (operation) name in the given (EClass) context
//returns nullptr if operation with name is not found
std::shared_ptr<Any> EcoreEnvironment::lookupOperationName(const std::string& name, std::shared_ptr<Any> context) {

    //try as ecoreAny
    std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(context);

    if (ecoreAny == nullptr) {
        //TODO add error
        //context have to be an ecoreAny
        return emptyResult();
    }

    //get eObject to get eClass
    std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();

    if (eObject == nullptr) {
        //TODO add error can't get eObject out of ecoreAny
        return emptyResult();
    }
    
    //try to get eClass
    std::shared_ptr<ecore::EClass> eClass = eObject->eClass();

    if (eClass == nullptr) {
        //TODO add error
        //eObject have no class
        return emptyResult();
    }

    //find operation with given name
    size_t size = eClass->getEAllOperations()->size();

    std::shared_ptr<ecore::EOperation> foundOp;

    for (size_t i = 0; i < size; i++) {
        const std::shared_ptr<ecore::EOperation>& elem = eClass->getEAllOperations()->at(i);
        if (name == elem->getName()) {
            foundOp = elem;
            break;
        }
    }

    //check if found
    if (foundOp == nullptr) {
        //TODO property name 'name' in eClass.getName() not found
        return emptyResult();
    }

    //get actual object
    const std::shared_ptr<Any>& returnObject = eEcoreAny(foundOp, foundOp->getMetaElementID());

    return returnObject;

}

// look for a Type in the given Any
//return nullptr if no type is found
std::string EcoreEnvironment::getTypeName(const std::shared_ptr<Any>& argument) {

    //try as ecoreAny
    std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(argument);

    if (ecoreAny != nullptr) {

        //get eObject to get eObj
        std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();

        if (eObject != nullptr) {
            //try to get eClass
            std::shared_ptr<ecore::EClass> eClass = eObject->eClass();

            if (eClass != nullptr) {
                return eClass->getName();
            }
        }

    } else
    //check if primitive type
    {

        switch (argument->getTypeId())
        {
        case ecore::ecorePackage::EBOOLEAN_CLASS:
            return Utilities::EBOOLEAN_NAME;
            break;
        case ecore::ecorePackage::EINT_CLASS:
            return Utilities::EINT_NAME;
            break;
        case ecore::ecorePackage::EDOUBLE_CLASS:
            return Utilities::EDOUBLE_NAME;
            break;
        case ecore::ecorePackage::ESTRING_CLASS:
            return Utilities::ESTRING_NAME;
            break;
        
        default:
        // no type could identified
            return "";
            break;
        }

    }

    // no type could identified
    return "";

}

// updates the context with the given name
// if it is not nullptr
bool EcoreEnvironment::updateContext(std::shared_ptr<Any> newContext) {

    if (newContext != nullptr) {
        m_context = newContext;
        return true;
    }
    return false;

}

//searches in all namedElements for the given variable name
std::shared_ptr<Any> EcoreEnvironment::lookupNamedElement(const std::string& name) {

    if(m_namedElements.find(name) != m_namedElements.end()) {
            return std::get<1>(m_namedElements.at(name));
        }

    if (m_parent != nullptr) {
        return m_parent->lookupNamedElement(name);
    }

    return nullptr;

}
