#include "StandardProfile/impl/ScriptImpl.hpp"

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif

#include <iostream>


#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/AnyEObjectBag.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "util/util.hpp"
#include "uml/Property.hpp"
#include "uml/Operation.hpp"
#include "uml/Parameter.hpp"
#include "StandardProfile/StandardProfileFactory.hpp"
#include "StandardProfile/impl/StandardProfilePackageImpl.hpp"
#include "uml/Stereotype.hpp"

//Types included from attributes, operation parameters, imports and composite owner classes
#include "uml/umlPackage.hpp"
#include "uml/Artifact.hpp"

//Packges and Factories included from types of attributes, operation parameters, imports and composite owner classes
#include "uml/umlFactory.hpp"
#include "uml/impl/umlPackageImpl.hpp"

//Packages of included Enumerations


//Includes from InstanceValues (if required)

//Includes from Ports typed by interfaces (if required)

//Includes from roles of ConnectorEnds (if required)

using namespace StandardProfile;

//*********************************
// Constructor / Destructor
//*********************************
ScriptImpl::ScriptImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_MESSAGE(std::cout<<"Script is created..."<<std::endl;)
	//***********************************
	// init Get Set
	//getter init
		//Property base_Artifact
		m_getterMap.insert(std::pair<unsigned long,std::function<Any()>>(1334320141,[this](){ return eAny(this->getBase_Artifact(), uml::umlPackage::ARTIFACT_CLASS, false);}));
	
	
	//setter init
	//Property base_Artifact
		m_setterMap.insert(std::pair<unsigned long,std::function<void(Any)>>(1334320141,[this](Any object){this->setBase_Artifact(object->get<std::shared_ptr<uml::Artifact>>());}));
	
	
	//unsetter init
		//Property base_Artifact
		m_unsetterMap.insert(std::pair<unsigned long,std::function<void()>>(1334320141,[this](){m_base_Artifact = std::shared_ptr<uml::Artifact>(nullptr);}));
	
	
	
}


ScriptImpl::~ScriptImpl()
{
	DEBUG_MESSAGE(std::cout<<"Script is destroyed..."<<std::endl;)
}

ScriptImpl::ScriptImpl(const ScriptImpl & obj):ScriptImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  ScriptImpl::copy() const
{
	std::shared_ptr<ScriptImpl> element(new ScriptImpl());
	*element=(*this);
	element->setThisScriptPtr(element);
	return element;
}

ScriptImpl& ScriptImpl::operator=(const ScriptImpl & obj)
{
	//call overloaded =Operator for each base class
	FileImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Script "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();

	//copy attributes with no containment (soft copy)
	m_base_Artifact = obj.getBase_Artifact();

	//clone attributes with containment (deep copy)

	return *this;
}


std::shared_ptr<uml::Class> ScriptImpl::getMetaClass() const
{
	return StandardProfilePackageImpl::eInstance()->get_StandardProfile_Script();
}

void ScriptImpl::instantiate()
{   
	FileImpl::instantiate();
	
}

void ScriptImpl::destroy()
{	

	//Erase properties
	//deleting property base_Artifact
	m_base_Artifact.reset();
	
	//Erase back reference to owner
}

//*********************************
// Attribute Setter Getter
//*********************************
void ScriptImpl::setBase_Artifact(std::weak_ptr<uml::Artifact> _base_Artifact)
{
	m_base_Artifact = _base_Artifact;
	
}
std::weak_ptr<uml::Artifact> ScriptImpl::getBase_Artifact() const 
{

	return m_base_Artifact;
}

//*********************************
// Union Getter
//*********************************



//*********************************
// Operations
//*********************************

//*********************************
// Structural Feature Getter/Setter
//*********************************
//Get
Any ScriptImpl::get(std::shared_ptr<uml::Property> _property) const
{
	std::string qualifiedName = _property->getQualifiedName();
    return this->get(qualifiedName);
}

Any ScriptImpl::get(std::string _qualifiedName) const
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
    return this->get(uID);
}

Any ScriptImpl::get(unsigned long _uID) const
{
	std::map<unsigned long, std::function<Any()>>::const_iterator iter = m_getterMap.find(_uID);
    if(iter != m_getterMap.cend())
    {
        //invoke the getter function
        return iter->second();
    }

	Any result;
	result = StandardProfile::FileImpl::get(_uID);
	if (result != nullptr)
	{
		return result;
	}
	return result;
}

//Set
void ScriptImpl::set(std::shared_ptr<uml::Property> _property, Any value)
{
	std::string qualifiedName = _property->getQualifiedName();
    this->set(qualifiedName, value);
}

void ScriptImpl::set(std::string _qualifiedName, Any value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
    this->set(uID, value);
}

void ScriptImpl::set(unsigned long _uID, Any value)
{
	std::map<unsigned long, std::function<void(Any)>>::const_iterator iter = m_setterMap.find(_uID);
    if(iter != m_setterMap.cend())
    {
        //invoke the setter function
        iter->second(value);
    }
	StandardProfile::FileImpl::set(_uID, value);
}

//Unset
void ScriptImpl::unset(std::shared_ptr<uml::Property> _property)
{
	std::string qualifiedName = _property->getQualifiedName();
    this->unset(qualifiedName);
}

void ScriptImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
    this->unset(uID);
}

void ScriptImpl::unset(unsigned long _uID)
{
	std::map<unsigned long, std::function<void()>>::const_iterator iter = m_unsetterMap.find(_uID);
    if(iter != m_unsetterMap.cend())
    {
        //invoke the unsetter function
        iter->second();
    }
	StandardProfile::FileImpl::unset(_uID);
}


//*********************************
// Operation Invoction
//*********************************
//Invoke
Any ScriptImpl::invoke(std::shared_ptr<uml::Operation> _operation, std::shared_ptr<Bag<Any>> _arguments)
{
	std::string qualifiedName = _operation->getQualifiedName();

	for(unsigned int i = 0; i < _operation->getOwnedParameter()->size(); i++)
	{
		qualifiedName += "_" + _operation->getOwnedParameter()->at(i)->getType()->getName();
	}

    return this->invoke(qualifiedName, _arguments);
}

Any ScriptImpl::invoke(std::string _qualifiedName, std::shared_ptr<Bag<Any>> _arguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
    return this->invoke(uID, _arguments);
}

Any ScriptImpl::invoke(unsigned long _uID, std::shared_ptr<Bag<Any>> _arguments)
{
	std::map<unsigned long, std::function<Any(std::shared_ptr<Bag<Any>>)>>::const_iterator iter = m_invocationMap.find(_uID);
    if(iter != m_invocationMap.cend())
    {
        //invoke the operation
        return iter->second(_arguments);
    }
	
	Any result;
	result = StandardProfile::FileImpl::invoke(_uID, _arguments);
	if (result != nullptr)
	{
		return result;
	}
	return result;
}

std::shared_ptr<Script> ScriptImpl::getThisScriptPtr()
{
	return m_thisScriptPtr.lock();
}
void ScriptImpl::setThisScriptPtr(std::weak_ptr<Script> thisScriptPtr)
{
	m_thisScriptPtr = thisScriptPtr;
	setThisFilePtr(thisScriptPtr);
}
