#include "StandardProfile/impl/ProcessImpl.hpp"

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif

#include <iostream>


#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "util/util.hpp"
#include "uml/Property.hpp"
#include "uml/Operation.hpp"
#include "uml/Parameter.hpp"
#include "StandardProfile/StandardProfileFactory.hpp"
#include "StandardProfile/impl/StandardProfilePackageImpl.hpp"
#include "uml/Stereotype.hpp"

//Types included from attributes, operation parameters, imports and composite owner classes
#include "uml/Component.hpp"

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
ProcessImpl::ProcessImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_MESSAGE(std::cout<<"Process is created..."<<std::endl;)
	//***********************************
	// init Get Set
	//getter init
		//Property base_Component
		m_getterMap.insert(std::pair<long long,std::function<Any()>>(1144790346,[this](){ return eAny(this->getBase_Component());}));
	
	
	//setter init
	//Property base_Component
		m_setterMap.insert(std::pair<long long,std::function<void(Any)>>(1144790346,[this](Any object){this->setBase_Component(object->get<std::shared_ptr<uml::Component>>());}));
	
	
	//unsetter init
		//Property base_Component
		m_unsetterMap.insert(std::pair<long long,std::function<void()>>(1144790346,[this](){m_base_Component = std::shared_ptr<uml::Component>(nullptr);}));
	
	
	
}


ProcessImpl::~ProcessImpl()
{
	DEBUG_MESSAGE(std::cout<<"Process is destroyed..."<<std::endl;)
}

ProcessImpl::ProcessImpl(const ProcessImpl & obj):ProcessImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  ProcessImpl::copy() const
{
	std::shared_ptr<ProcessImpl> element(new ProcessImpl());
	*element=(*this);
	element->setThisProcessPtr(element);
	return element;
}

ProcessImpl& ProcessImpl::operator=(const ProcessImpl & obj)
{
	//call overloaded =Operator for each base class
	uml::StereotypeImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Process "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();

	//copy attributes with no containment (soft copy)
	m_base_Component = obj.getBase_Component();

	//clone attributes with containment (deep copy)

	return *this;
}


std::shared_ptr<uml::Class> ProcessImpl::getMetaClass()
{
	return StandardProfilePackageImpl::eInstance()->get_StandardProfile_Process();
}

void ProcessImpl::instantiate()
{   
	
}

void ProcessImpl::destroy()
{	

	//Erase properties
	//deleting property base_Component
	m_base_Component.reset();
	
	//Erase back reference to owner
}

//*********************************
// Attribute Setter Getter
//*********************************
void ProcessImpl::setBase_Component(std::weak_ptr<uml::Component> _base_Component)
{
	m_base_Component = _base_Component;
	
}
std::weak_ptr<uml::Component> ProcessImpl::getBase_Component() const 
{

	return m_base_Component;
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
Any ProcessImpl::get(std::shared_ptr<uml::Property> _property) const
{
	std::string qualifiedName = _property->getQualifiedName();
    return this->get(qualifiedName);
}

Any ProcessImpl::get(std::string _qualifiedName) const
{
	long long uID = util::Util::polynomialRollingHash(_qualifiedName);
    return this->get(uID);
}

Any ProcessImpl::get(long long _uID) const
{
	std::map<long long, std::function<Any()>>::const_iterator iter = m_getterMap.find(_uID);
    if(iter != m_getterMap.cend())
    {
        //invoke the getter function
        return iter->second();
    }

	return eAny(nullptr);
}

//Set
void ProcessImpl::set(std::shared_ptr<uml::Property> _property, Any value)
{
	std::string qualifiedName = _property->getQualifiedName();
    this->set(qualifiedName, value);
}

void ProcessImpl::set(std::string _qualifiedName, Any value)
{
	long long uID = util::Util::polynomialRollingHash(_qualifiedName);
    this->set(uID, value);
}

void ProcessImpl::set(long long _uID, Any value)
{
	std::map<long long, std::function<void(Any)>>::const_iterator iter = m_setterMap.find(_uID);
    if(iter != m_setterMap.cend())
    {
        //invoke the setter function
        iter->second(value);
    }
}

//Unset
void ProcessImpl::unset(std::shared_ptr<uml::Property> _property)
{
	std::string qualifiedName = _property->getQualifiedName();
    this->unset(qualifiedName);
}

void ProcessImpl::unset(std::string _qualifiedName)
{
	long long uID = util::Util::polynomialRollingHash(_qualifiedName);
    this->unset(uID);
}

void ProcessImpl::unset(long long _uID)
{
	std::map<long long, std::function<void()>>::const_iterator iter = m_unsetterMap.find(_uID);
    if(iter != m_unsetterMap.cend())
    {
        //invoke the unsetter function
        iter->second();
    }
}


//*********************************
// Operation Invoction
//*********************************
//Invoke
Any ProcessImpl::invoke(std::shared_ptr<uml::Operation> _operation, std::shared_ptr<Bag<Any>> _arguments)
{
	std::string qualifiedName = _operation->getQualifiedName();

	for(unsigned int i = 0; i < _operation->getOwnedParameter()->size(); i++)
	{
		qualifiedName += "_" + _operation->getOwnedParameter()->at(i)->getType()->getName();
	}

    return this->invoke(qualifiedName, _arguments);
}

Any ProcessImpl::invoke(std::string _qualifiedName, std::shared_ptr<Bag<Any>> _arguments)
{
	long long uID = util::Util::polynomialRollingHash(_qualifiedName);
    return this->invoke(uID, _arguments);
}

Any ProcessImpl::invoke(long long _uID, std::shared_ptr<Bag<Any>> _arguments)
{
	std::map<long long, std::function<Any(std::shared_ptr<Bag<Any>>)>>::const_iterator iter = m_invocationMap.find(_uID);
    if(iter != m_invocationMap.cend())
    {
        //invoke the operation
        return iter->second(_arguments);
    }
	
	return eAny(nullptr);
}

std::shared_ptr<Process> ProcessImpl::getThisProcessPtr()
{
	return m_thisProcessPtr.lock();
}
void ProcessImpl::setThisProcessPtr(std::weak_ptr<Process> thisProcessPtr)
{
	m_thisProcessPtr = thisProcessPtr;
	setThisStereotypePtr(thisProcessPtr);
}
