#include "UML4CPPProfile/impl/SetterNameImpl.hpp"

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
#include "uml/Property.hpp"

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
SetterNameImpl::SetterNameImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_MESSAGE(std::cout<<"SetterName is created..."<<std::endl;)
	//***********************************
	// init Get Set
	//getter init
		//Property base_Property
		m_getterMap.insert(std::pair<long long,std::function<Any()>>(554856804,[this](){ return eAny(this->getBase_Property());}));
		//Property setterName
		m_getterMap.insert(std::pair<long long,std::function<Any()>>(1550049626,[this](){ return eAny(this->getSetterName());}));
	
	
	//setter init
	//Property base_Property
		m_setterMap.insert(std::pair<long long,std::function<void(Any)>>(554856804,[this](Any object){this->setBase_Property(object->get<std::shared_ptr<uml::Property>>());}));
	//Property setterName
		m_setterMap.insert(std::pair<long long,std::function<void(Any)>>(1550049626,[this](Any object){this->setSetterName(object->get<std::string>());}));
	
	
	//unsetter init
		//Property base_Property
		m_unsetterMap.insert(std::pair<long long,std::function<void()>>(554856804,[this](){m_base_Property = std::shared_ptr<uml::Property>(nullptr);}));
	
	
	
}


SetterNameImpl::~SetterNameImpl()
{
	DEBUG_MESSAGE(std::cout<<"SetterName is destroyed..."<<std::endl;)
}

SetterNameImpl::SetterNameImpl(const SetterNameImpl & obj):SetterNameImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  SetterNameImpl::copy() const
{
	std::shared_ptr<SetterNameImpl> element(new SetterNameImpl());
	*element=(*this);
	element->setThisSetterNamePtr(element);
	return element;
}

SetterNameImpl& SetterNameImpl::operator=(const SetterNameImpl & obj)
{
	//call overloaded =Operator for each base class
	uml::StereotypeImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy SetterName "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();

	//copy attributes with no containment (soft copy)
	m_base_Property = obj.getBase_Property();
	m_setterName = obj.getSetterName();

	//clone attributes with containment (deep copy)

	return *this;
}


std::shared_ptr<uml::Class> SetterNameImpl::getMetaClass()
{
	return UML4CPPProfilePackageImpl::eInstance()->get_UML4CPPProfile_SetterName();
}

void SetterNameImpl::instantiate()
{   
	
	
}

void SetterNameImpl::destroy()
{	

	//Erase properties
	//deleting property base_Property
	m_base_Property.reset();
	
	
	//Erase back reference to owner
}

//*********************************
// Attribute Setter Getter
//*********************************
void SetterNameImpl::setBase_Property(std::weak_ptr<uml::Property> _base_Property)
{
	m_base_Property = _base_Property;
	
}
std::weak_ptr<uml::Property> SetterNameImpl::getBase_Property() const 
{

	return m_base_Property;
}

void SetterNameImpl::setSetterName(std::string _setterName)
{
	m_setterName = _setterName;
	
}
std::string SetterNameImpl::getSetterName() const 
{

	return m_setterName;
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
Any SetterNameImpl::get(std::shared_ptr<uml::Property> _property) const
{
	std::string qualifiedName = _property->getQualifiedName();
    return this->get(qualifiedName);
}

Any SetterNameImpl::get(std::string _qualifiedName) const
{
	long long uID = util::Util::polynomialRollingHash(_qualifiedName);
    return this->get(uID);
}

Any SetterNameImpl::get(long long _uID) const
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
void SetterNameImpl::set(std::shared_ptr<uml::Property> _property, Any value)
{
	std::string qualifiedName = _property->getQualifiedName();
    this->set(qualifiedName, value);
}

void SetterNameImpl::set(std::string _qualifiedName, Any value)
{
	long long uID = util::Util::polynomialRollingHash(_qualifiedName);
    this->set(uID, value);
}

void SetterNameImpl::set(long long _uID, Any value)
{
	std::map<long long, std::function<void(Any)>>::const_iterator iter = m_setterMap.find(_uID);
    if(iter != m_setterMap.cend())
    {
        //invoke the setter function
        iter->second(value);
    }
}

//Unset
void SetterNameImpl::unset(std::shared_ptr<uml::Property> _property)
{
	std::string qualifiedName = _property->getQualifiedName();
    this->unset(qualifiedName);
}

void SetterNameImpl::unset(std::string _qualifiedName)
{
	long long uID = util::Util::polynomialRollingHash(_qualifiedName);
    this->unset(uID);
}

void SetterNameImpl::unset(long long _uID)
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
Any SetterNameImpl::invoke(std::shared_ptr<uml::Operation> _operation, std::shared_ptr<Bag<Any>> _arguments)
{
	std::string qualifiedName = _operation->getQualifiedName();

	for(unsigned int i = 0; i < _operation->getOwnedParameter()->size(); i++)
	{
		qualifiedName += "_" + _operation->getOwnedParameter()->at(i)->getType()->getName();
	}

    return this->invoke(qualifiedName, _arguments);
}

Any SetterNameImpl::invoke(std::string _qualifiedName, std::shared_ptr<Bag<Any>> _arguments)
{
	long long uID = util::Util::polynomialRollingHash(_qualifiedName);
    return this->invoke(uID, _arguments);
}

Any SetterNameImpl::invoke(long long _uID, std::shared_ptr<Bag<Any>> _arguments)
{
	std::map<long long, std::function<Any(std::shared_ptr<Bag<Any>>)>>::const_iterator iter = m_invocationMap.find(_uID);
    if(iter != m_invocationMap.cend())
    {
        //invoke the operation
        return iter->second(_arguments);
    }
	
	return eAny(nullptr);
}

std::shared_ptr<SetterName> SetterNameImpl::getThisSetterNamePtr()
{
	return m_thisSetterNamePtr.lock();
}
void SetterNameImpl::setThisSetterNamePtr(std::weak_ptr<SetterName> thisSetterNamePtr)
{
	m_thisSetterNamePtr = thisSetterNamePtr;
	setThisStereotypePtr(thisSetterNamePtr);
}
