#include "StandardProfile/impl/UtilityImpl.hpp"

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
#include "uml/Class.hpp"

//Packges and Factories included from types of attributes, operation parameters, imports and composite owner classes
#include "uml/umlFactory.hpp"
#include "uml/impl/umlPackageImpl.hpp"

//Packages of included Enumerations

//Includes of PluginFramework (if required)

//Includes of OpaqueBevaiors (if required)

//Includes from InstanceValues (if required)

//Includes from Ports typed by interfaces (if required)

//Includes from roles of ConnectorEnds (if required)

using namespace StandardProfile;

//*********************************
// Constructor / Destructor
//*********************************
UtilityImpl::UtilityImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_MESSAGE(std::cout<<"Utility is created..."<<std::endl;)
	//***********************************
	// init Get Set
	//getter init
		//Property base_Class
		m_getterMap.insert(std::pair<long long,std::function<Any()>>(605150396,[this](){ return eAny(this->getBase_Class());}));
	
	
	//setter init
	//Property base_Class
		m_setterMap.insert(std::pair<long long,std::function<void(Any)>>(605150396,[this](Any object){this->setBase_Class(object->get<std::shared_ptr<uml::Class>>());}));
	
	
	//unsetter init
		//Property base_Class
		m_unsetterMap.insert(std::pair<long long,std::function<void()>>(605150396,[this](){m_base_Class = std::shared_ptr<uml::Class>(nullptr);}));
	
	
	
}


UtilityImpl::~UtilityImpl()
{
	DEBUG_MESSAGE(std::cout<<"Utility is destroyed..."<<std::endl;)
}

UtilityImpl::UtilityImpl(const UtilityImpl & obj):UtilityImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  UtilityImpl::copy() const
{
	std::shared_ptr<UtilityImpl> element(new UtilityImpl());
	*element=(*this);
	element->setThisUtilityPtr(element);
	return element;
}

UtilityImpl& UtilityImpl::operator=(const UtilityImpl & obj)
{
	//call overloaded =Operator for each base class
	uml::StereotypeImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Utility "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();

	//copy attributes with no containment (soft copy)
	m_base_Class = obj.getBase_Class();

	//clone attributes with containment (deep copy)

	return *this;
}


std::shared_ptr<uml::Class> UtilityImpl::getMetaClass()
{
	return StandardProfilePackageImpl::eInstance()->get_StandardProfile_Utility();
}

void UtilityImpl::instantiate()
{   
	
}

void UtilityImpl::destroy()
{	

	//Erase properties
	//deleting property base_Class
	m_base_Class.reset();
	
	//Erase back reference to owner
}

//*********************************
// Attribute Setter Getter
//*********************************
void UtilityImpl::setBase_Class(std::weak_ptr<uml::Class> _base_Class)
{
	m_base_Class = _base_Class;
	
}
std::weak_ptr<uml::Class> UtilityImpl::getBase_Class() const 
{
	return m_base_Class;
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
Any UtilityImpl::get(std::shared_ptr<uml::Property> _property) const
{
	std::string qualifiedName = _property->getQualifiedName();
    return this->get(qualifiedName);
}

Any UtilityImpl::get(std::string _qualifiedName) const
{
	long long uID = util::Util::polynomialRollingHash(_qualifiedName);
    return this->get(uID);
}

Any UtilityImpl::get(long long _uID) const
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
void UtilityImpl::set(std::shared_ptr<uml::Property> _property, Any value)
{
	std::string qualifiedName = _property->getQualifiedName();
    this->set(qualifiedName, value);
}

void UtilityImpl::set(std::string _qualifiedName, Any value)
{
	long long uID = util::Util::polynomialRollingHash(_qualifiedName);
    this->set(uID, value);
}

void UtilityImpl::set(long long _uID, Any value)
{
	std::map<long long, std::function<void(Any)>>::const_iterator iter = m_setterMap.find(_uID);
    if(iter != m_setterMap.cend())
    {
        //invoke the setter function
        iter->second(value);
    }
}

//Unset
void UtilityImpl::unset(std::shared_ptr<uml::Property> _property)
{
	std::string qualifiedName = _property->getQualifiedName();
    this->unset(qualifiedName);
}

void UtilityImpl::unset(std::string _qualifiedName)
{
	long long uID = util::Util::polynomialRollingHash(_qualifiedName);
    this->unset(uID);
}

void UtilityImpl::unset(long long _uID)
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
Any UtilityImpl::invoke(std::shared_ptr<uml::Operation> _operation, std::shared_ptr<Bag<Any>> _arguments)
{
	std::string qualifiedName = _operation->getQualifiedName();

	for(unsigned int i = 0; i < _operation->getOwnedParameter()->size(); i++)
	{
		qualifiedName += "_" + _operation->getOwnedParameter()->at(i)->getType()->getName();
	}

    return this->invoke(qualifiedName, _arguments);
}

Any UtilityImpl::invoke(std::string _qualifiedName, std::shared_ptr<Bag<Any>> _arguments)
{
	long long uID = util::Util::polynomialRollingHash(_qualifiedName);
    return this->invoke(uID, _arguments);
}

Any UtilityImpl::invoke(long long _uID, std::shared_ptr<Bag<Any>> _arguments)
{
	std::map<long long, std::function<Any(std::shared_ptr<Bag<Any>>)>>::const_iterator iter = m_invocationMap.find(_uID);
    if(iter != m_invocationMap.cend())
    {
        //invoke the operation
        return iter->second(_arguments);
    }
	
	return eAny(nullptr);
}

std::shared_ptr<Utility> UtilityImpl::getThisUtilityPtr()
{
	return m_thisUtilityPtr.lock();
}
void UtilityImpl::setThisUtilityPtr(std::weak_ptr<Utility> thisUtilityPtr)
{
	m_thisUtilityPtr = thisUtilityPtr;
	setThisStereotypePtr(thisUtilityPtr);
}
