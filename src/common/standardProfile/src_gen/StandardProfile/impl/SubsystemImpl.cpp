#include "StandardProfile/impl/SubsystemImpl.hpp"

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
SubsystemImpl::SubsystemImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_MESSAGE(std::cout<<"Subsystem is created..."<<std::endl;)
	//***********************************
	// init Get Set
	//getter init
		//Property base_Component
		m_getterMap.insert(std::pair<unsigned long,std::function<Any()>>(374353570,[this](){ return eAny(this->getBase_Component(), uml::umlPackage::COMPONENT_CLASS, false);}));
	
	
	//setter init
	//Property base_Component
		m_setterMap.insert(std::pair<unsigned long,std::function<void(Any)>>(374353570,[this](Any object){this->setBase_Component(object->get<std::shared_ptr<uml::Component>>());}));
	
	
	//unsetter init
		//Property base_Component
		m_unsetterMap.insert(std::pair<unsigned long,std::function<void()>>(374353570,[this](){m_base_Component = std::shared_ptr<uml::Component>(nullptr);}));
	
	
	
}


SubsystemImpl::~SubsystemImpl()
{
	DEBUG_MESSAGE(std::cout<<"Subsystem is destroyed..."<<std::endl;)
}

SubsystemImpl::SubsystemImpl(const SubsystemImpl & obj):SubsystemImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  SubsystemImpl::copy() const
{
	std::shared_ptr<SubsystemImpl> element(new SubsystemImpl());
	*element=(*this);
	element->setThisSubsystemPtr(element);
	return element;
}

SubsystemImpl& SubsystemImpl::operator=(const SubsystemImpl & obj)
{
	//call overloaded =Operator for each base class
	uml::StereotypeImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Subsystem "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();

	//copy attributes with no containment (soft copy)
	m_base_Component = obj.getBase_Component();

	//clone attributes with containment (deep copy)

	return *this;
}


const std::shared_ptr<uml::Class>& SubsystemImpl::getMetaClass() const
{
	static const std::shared_ptr<uml::Class> metaClass = StandardProfilePackageImpl::eInstance()->get_StandardProfile_Subsystem();
	return metaClass;
}

void SubsystemImpl::instantiate()
{   
	
}

void SubsystemImpl::destroy()
{	

	//Erase properties
	//deleting property base_Component
	m_base_Component.reset();
	
	//Erase back reference to owner
}

//*********************************
// Attribute Setter Getter
//*********************************
void SubsystemImpl::setBase_Component(std::weak_ptr<uml::Component> _base_Component)
{
	m_base_Component = _base_Component;
	
}
std::weak_ptr<uml::Component> SubsystemImpl::getBase_Component() const 
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
Any SubsystemImpl::get(const std::shared_ptr<uml::Property>& _property) const
{
	std::string qualifiedName = _property->getQualifiedName();
    return this->get(qualifiedName);
}

Any SubsystemImpl::get(std::string _qualifiedName) const
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
    return this->get(uID);
}

Any SubsystemImpl::get(unsigned long _uID) const
{
	std::map<unsigned long, std::function<Any()>>::const_iterator iter = m_getterMap.find(_uID);
    if(iter != m_getterMap.cend())
    {
        //invoke the getter function
        return iter->second();
    }

	return eAny(nullptr, -1, false);
}

//Set
void SubsystemImpl::set(const std::shared_ptr<uml::Property>& _property, const Any& value)
{
	std::string qualifiedName = _property->getQualifiedName();
    this->set(qualifiedName, value);
}

void SubsystemImpl::set(std::string _qualifiedName, const Any& value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
    this->set(uID, value);
}

void SubsystemImpl::set(unsigned long _uID, const Any& value)
{
	std::map<unsigned long, std::function<void(Any)>>::const_iterator iter = m_setterMap.find(_uID);
    if(iter != m_setterMap.cend())
    {
        //invoke the setter function
        iter->second(value);
    }
}

//Unset
void SubsystemImpl::unset(const std::shared_ptr<uml::Property>& _property)
{
	std::string qualifiedName = _property->getQualifiedName();
    this->unset(qualifiedName);
}

void SubsystemImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
    this->unset(uID);
}

void SubsystemImpl::unset(unsigned long _uID)
{
	std::map<unsigned long, std::function<void()>>::const_iterator iter = m_unsetterMap.find(_uID);
    if(iter != m_unsetterMap.cend()) //TODO optimize loop
    {
        //invoke the unsetter function
        iter->second();
    }
}


//*********************************
// Operation Invoction
//*********************************
//Invoke
Any SubsystemImpl::invoke(const std::shared_ptr<uml::Operation>& _operation, const std::shared_ptr<Bag<Any>>& _arguments)
{
	std::string qualifiedName = _operation->getQualifiedName();

	int ownedParameterSize = _operation->getOwnedParameter()->size();
	for(int i = 0; i < ownedParameterSize; i++)
	{
		qualifiedName += "_" + _operation->getOwnedParameter()->at(i)->getType()->getName();
	}

    return this->invoke(qualifiedName, _arguments);
}

Any SubsystemImpl::invoke(std::string _qualifiedName, const std::shared_ptr<Bag<Any>>& _arguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
    return this->invoke(uID, _arguments);
}

Any SubsystemImpl::invoke(unsigned long _uID, const std::shared_ptr<Bag<Any>>& _arguments)
{
	std::map<unsigned long, std::function<Any(std::shared_ptr<Bag<Any>>)>>::const_iterator iter = m_invocationMap.find(_uID);
    if(iter != m_invocationMap.cend()) //TODO optimize loop
    {
        //invoke the operation
        return iter->second(_arguments);
    }
	
	return eAny(nullptr, -1, false);
}

std::shared_ptr<Subsystem> SubsystemImpl::getThisSubsystemPtr()
{
	return m_thisSubsystemPtr.lock();
}
void SubsystemImpl::setThisSubsystemPtr(std::weak_ptr<Subsystem> thisSubsystemPtr)
{
	m_thisSubsystemPtr = thisSubsystemPtr;
	setThisStereotypePtr(thisSubsystemPtr);
}


//*********************************
// ObjectActivation Forwarder Impl
//*********************************
// Getter for Active Class
bool SubsystemImpl::GetIsActive() const
{
		return false;

}


