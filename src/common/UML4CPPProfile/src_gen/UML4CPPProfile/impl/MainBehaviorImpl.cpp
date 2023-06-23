#include "UML4CPPProfile/impl/MainBehaviorImpl.hpp"

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
#include "UML4CPPProfile/UML4CPPProfileFactory.hpp"
#include "UML4CPPProfile/impl/UML4CPPProfilePackageImpl.hpp"
#include "uml/Stereotype.hpp"

//Types included from attributes, operation parameters, imports and composite owner classes
#include "uml/umlPackage.hpp"
#include "uml/Behavior.hpp"

//Packges and Factories included from types of attributes, operation parameters, imports and composite owner classes
#include "uml/umlFactory.hpp"
#include "uml/impl/umlPackageImpl.hpp"

//Packages of included Enumerations


//Includes from InstanceValues (if required)

//Includes from Ports typed by interfaces (if required)

//Includes from roles of ConnectorEnds (if required)

using namespace UML4CPPProfile;

//*********************************
// Constructor / Destructor
//*********************************
MainBehaviorImpl::MainBehaviorImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_MESSAGE(std::cout<<"MainBehavior is created..."<<std::endl;)
	//***********************************
	// init Get Set
	//getter init
		//Property base_Behavior
		m_getterMap.insert(std::pair<unsigned long,std::function<Any()>>(1956712138,[this](){ return eAny(this->getBase_Behavior(), uml::umlPackage::BEHAVIOR_CLASS, false);}));
	
	
	//setter init
	//Property base_Behavior
		m_setterMap.insert(std::pair<unsigned long,std::function<void(Any)>>(1956712138,[this](Any object){this->setBase_Behavior(object->get<std::shared_ptr<uml::Behavior>>());}));
	
	
	//unsetter init
		//Property base_Behavior
		m_unsetterMap.insert(std::pair<unsigned long,std::function<void()>>(1956712138,[this](){m_base_Behavior = std::shared_ptr<uml::Behavior>(nullptr);}));
	
	
	
}


MainBehaviorImpl::~MainBehaviorImpl()
{
	DEBUG_MESSAGE(std::cout<<"MainBehavior is destroyed..."<<std::endl;)
}

MainBehaviorImpl::MainBehaviorImpl(const MainBehaviorImpl & obj):MainBehaviorImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  MainBehaviorImpl::copy() const
{
	std::shared_ptr<MainBehaviorImpl> element(new MainBehaviorImpl());
	*element=(*this);
	element->setThisMainBehaviorPtr(element);
	return element;
}

MainBehaviorImpl& MainBehaviorImpl::operator=(const MainBehaviorImpl & obj)
{
	//call overloaded =Operator for each base class
	uml::StereotypeImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy MainBehavior "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();

	//copy attributes with no containment (soft copy)
	m_base_Behavior = obj.getBase_Behavior();

	//clone attributes with containment (deep copy)

	return *this;
}


std::shared_ptr<uml::Class> MainBehaviorImpl::getMetaClass() const
{
	return UML4CPPProfilePackageImpl::eInstance()->get_UML4CPPProfile_MainBehavior();
}

void MainBehaviorImpl::instantiate()
{   
	
}

void MainBehaviorImpl::destroy()
{	

	//Erase properties
	//deleting property base_Behavior
	m_base_Behavior.reset();
	
	//Erase back reference to owner
}

//*********************************
// Attribute Setter Getter
//*********************************
void MainBehaviorImpl::setBase_Behavior(std::weak_ptr<uml::Behavior> _base_Behavior)
{
	m_base_Behavior = _base_Behavior;
	
}
std::weak_ptr<uml::Behavior> MainBehaviorImpl::getBase_Behavior() const 
{

	return m_base_Behavior;
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
Any MainBehaviorImpl::get(std::shared_ptr<uml::Property> _property) const
{
	std::string qualifiedName = _property->getQualifiedName();
    return this->get(qualifiedName);
}

Any MainBehaviorImpl::get(std::string _qualifiedName) const
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
    return this->get(uID);
}

Any MainBehaviorImpl::get(unsigned long _uID) const
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
void MainBehaviorImpl::set(std::shared_ptr<uml::Property> _property, Any value)
{
	std::string qualifiedName = _property->getQualifiedName();
    this->set(qualifiedName, value);
}

void MainBehaviorImpl::set(std::string _qualifiedName, Any value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
    this->set(uID, value);
}

void MainBehaviorImpl::set(unsigned long _uID, Any value)
{
	std::map<unsigned long, std::function<void(Any)>>::const_iterator iter = m_setterMap.find(_uID);
    if(iter != m_setterMap.cend())
    {
        //invoke the setter function
        iter->second(value);
    }
}

//Unset
void MainBehaviorImpl::unset(std::shared_ptr<uml::Property> _property)
{
	std::string qualifiedName = _property->getQualifiedName();
    this->unset(qualifiedName);
}

void MainBehaviorImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
    this->unset(uID);
}

void MainBehaviorImpl::unset(unsigned long _uID)
{
	std::map<unsigned long, std::function<void()>>::const_iterator iter = m_unsetterMap.find(_uID);
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
Any MainBehaviorImpl::invoke(std::shared_ptr<uml::Operation> _operation, std::shared_ptr<Bag<Any>> _arguments)
{
	std::string qualifiedName = _operation->getQualifiedName();

	for(unsigned int i = 0; i < _operation->getOwnedParameter()->size(); i++)
	{
		qualifiedName += "_" + _operation->getOwnedParameter()->at(i)->getType()->getName();
	}

    return this->invoke(qualifiedName, _arguments);
}

Any MainBehaviorImpl::invoke(std::string _qualifiedName, std::shared_ptr<Bag<Any>> _arguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
    return this->invoke(uID, _arguments);
}

Any MainBehaviorImpl::invoke(unsigned long _uID, std::shared_ptr<Bag<Any>> _arguments)
{
	std::map<unsigned long, std::function<Any(std::shared_ptr<Bag<Any>>)>>::const_iterator iter = m_invocationMap.find(_uID);
    if(iter != m_invocationMap.cend())
    {
        //invoke the operation
        return iter->second(_arguments);
    }
	
	return eAny(nullptr, -1, false);
}

std::shared_ptr<MainBehavior> MainBehaviorImpl::getThisMainBehaviorPtr()
{
	return m_thisMainBehaviorPtr.lock();
}
void MainBehaviorImpl::setThisMainBehaviorPtr(std::weak_ptr<MainBehavior> thisMainBehaviorPtr)
{
	m_thisMainBehaviorPtr = thisMainBehaviorPtr;
	setThisStereotypePtr(thisMainBehaviorPtr);
}


//*********************************
// ObjectActivation Forwarder Impl
//*********************************
// Getter for Active Class
bool MainBehaviorImpl::GetIsActive() const
{
		return false;

}


