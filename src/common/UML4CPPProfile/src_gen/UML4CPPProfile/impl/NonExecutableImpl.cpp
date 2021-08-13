#include "UML4CPPProfile/impl/NonExecutableImpl.hpp"

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
#include "UML4CPPProfile/UML4CPPProfileFactory.hpp"
#include "UML4CPPProfile/impl/UML4CPPProfilePackageImpl.hpp"
#include "uml/Stereotype.hpp"

//Types included from attributes, operation parameters, imports and composite owner classes
#include "uml/NamedElement.hpp"

//Packges and Factories included from types of attributes, operation parameters, imports and composite owner classes
#include "uml/umlFactory.hpp"
#include "uml/impl/umlPackageImpl.hpp"

//Packages of included Enumerations

//Includes of PluginFramework (if required)

//Includes of OpaqueBevaiors (if required)

//Includes from InstanceValues (if required)

//Includes from Ports typed by interfaces (if required)

//Includes from roles of ConnectorEnds (if required)

using namespace UML4CPPProfile;

//*********************************
// Constructor / Destructor
//*********************************
NonExecutableImpl::NonExecutableImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_MESSAGE(std::cout<<"NonExecutable is created..."<<std::endl;)
	//***********************************
	// init Get Set
	//getter init
		//Property base_NamedElement
		m_getterMap.insert(std::pair<long long,std::function<Any()>>(488558520,[this](){ return eAny(this->getBase_NamedElement());}));
	
	
	//setter init
	//Property base_NamedElement
		m_setterMap.insert(std::pair<long long,std::function<void(Any)>>(488558520,[this](Any object){this->setBase_NamedElement(object->get<std::shared_ptr<uml::NamedElement>>());}));
	
	
	//unsetter init
		//Property base_NamedElement
		m_unsetterMap.insert(std::pair<long long,std::function<void()>>(488558520,[this](){m_base_NamedElement = std::shared_ptr<uml::NamedElement>(nullptr);}));
	
	
	
}


NonExecutableImpl::~NonExecutableImpl()
{
	DEBUG_MESSAGE(std::cout<<"NonExecutable is destroyed..."<<std::endl;)
}

NonExecutableImpl::NonExecutableImpl(const NonExecutableImpl & obj):NonExecutableImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  NonExecutableImpl::copy() const
{
	std::shared_ptr<NonExecutableImpl> element(new NonExecutableImpl());
	*element=(*this);
	element->setThisNonExecutablePtr(element);
	return element;
}

NonExecutableImpl& NonExecutableImpl::operator=(const NonExecutableImpl & obj)
{
	//call overloaded =Operator for each base class
	uml::StereotypeImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy NonExecutable "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();

	//copy attributes with no containment (soft copy)
	m_base_NamedElement = obj.getBase_NamedElement();

	//clone attributes with containment (deep copy)

	return *this;
}


std::shared_ptr<uml::Class> NonExecutableImpl::getMetaClass()
{
	return UML4CPPProfilePackageImpl::eInstance()->get_UML4CPPProfile_NonExecutable();
}

void NonExecutableImpl::instantiate()
{   
	
}

void NonExecutableImpl::destroy()
{	

	//Erase properties
	//deleting property base_NamedElement
	m_base_NamedElement.reset();
	
	//Erase back reference to owner
}

//*********************************
// Attribute Setter Getter
//*********************************
void NonExecutableImpl::setBase_NamedElement(std::weak_ptr<uml::NamedElement> _base_NamedElement)
{
	m_base_NamedElement = _base_NamedElement;
	
}
std::weak_ptr<uml::NamedElement> NonExecutableImpl::getBase_NamedElement() const 
{
	return m_base_NamedElement;
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
Any NonExecutableImpl::get(std::shared_ptr<uml::Property> _property) const
{
	std::string qualifiedName = _property->getQualifiedName();
    return this->get(qualifiedName);
}

Any NonExecutableImpl::get(std::string _qualifiedName) const
{
	long long uID = util::Util::polynomialRollingHash(_qualifiedName);
    return this->get(uID);
}

Any NonExecutableImpl::get(long long _uID) const
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
void NonExecutableImpl::set(std::shared_ptr<uml::Property> _property, Any value)
{
	std::string qualifiedName = _property->getQualifiedName();
    this->set(qualifiedName, value);
}

void NonExecutableImpl::set(std::string _qualifiedName, Any value)
{
	long long uID = util::Util::polynomialRollingHash(_qualifiedName);
    this->set(uID, value);
}

void NonExecutableImpl::set(long long _uID, Any value)
{
	std::map<long long, std::function<void(Any)>>::const_iterator iter = m_setterMap.find(_uID);
    if(iter != m_setterMap.cend())
    {
        //invoke the setter function
        iter->second(value);
    }
}

//Unset
void NonExecutableImpl::unset(std::shared_ptr<uml::Property> _property)
{
	std::string qualifiedName = _property->getQualifiedName();
    this->unset(qualifiedName);
}

void NonExecutableImpl::unset(std::string _qualifiedName)
{
	long long uID = util::Util::polynomialRollingHash(_qualifiedName);
    this->unset(uID);
}

void NonExecutableImpl::unset(long long _uID)
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
Any NonExecutableImpl::invoke(std::shared_ptr<uml::Operation> _operation, std::shared_ptr<Bag<Any>> _arguments)
{
	std::string qualifiedName = _operation->getQualifiedName();

	for(unsigned int i = 0; i < _operation->getOwnedParameter()->size(); i++)
	{
		qualifiedName += "_" + _operation->getOwnedParameter()->at(i)->getType()->getName();
	}

    return this->invoke(qualifiedName, _arguments);
}

Any NonExecutableImpl::invoke(std::string _qualifiedName, std::shared_ptr<Bag<Any>> _arguments)
{
	long long uID = util::Util::polynomialRollingHash(_qualifiedName);
    return this->invoke(uID, _arguments);
}

Any NonExecutableImpl::invoke(long long _uID, std::shared_ptr<Bag<Any>> _arguments)
{
	std::map<long long, std::function<Any(std::shared_ptr<Bag<Any>>)>>::const_iterator iter = m_invocationMap.find(_uID);
    if(iter != m_invocationMap.cend())
    {
        //invoke the operation
        return iter->second(_arguments);
    }
	
	return eAny(nullptr);
}

std::shared_ptr<NonExecutable> NonExecutableImpl::getThisNonExecutablePtr()
{
	return m_thisNonExecutablePtr.lock();
}
void NonExecutableImpl::setThisNonExecutablePtr(std::weak_ptr<NonExecutable> thisNonExecutablePtr)
{
	m_thisNonExecutablePtr = thisNonExecutablePtr;
	setThisStereotypePtr(thisNonExecutablePtr);
}
