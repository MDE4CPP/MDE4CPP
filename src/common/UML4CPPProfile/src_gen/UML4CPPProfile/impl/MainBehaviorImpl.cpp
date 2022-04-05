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
std::shared_ptr<Any> MainBehaviorImpl::get(std::shared_ptr<uml::Property> _property) const
{
	std::string qualifiedName = _property->getQualifiedName();
	return this->get(qualifiedName);
}

std::shared_ptr<Any> MainBehaviorImpl::get(std::string _qualifiedName) const
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->get(uID);
}

std::shared_ptr<Any> MainBehaviorImpl::get(unsigned long _uID) const
{
	switch(_uID)
	{
		case UML4CPPProfile::UML4CPPProfilePackage::MAINBEHAVIOR_ATTRIBUTE_BASE_BEHAVIOR:
			return eAny(this->getBase_Behavior(), uml::umlPackage::BEHAVIOR_CLASS, false);
	}

	return eAny(nullptr, -1, false);
}

//Set
void MainBehaviorImpl::set(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->set(qualifiedName, value);
}

void MainBehaviorImpl::set(std::string _qualifiedName, std::shared_ptr<Any> value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->set(uID, value);
}

void MainBehaviorImpl::set(unsigned long _uID, std::shared_ptr<Any> value)
{
	switch(_uID)
	{
		case UML4CPPProfile::UML4CPPProfilePackage::MAINBEHAVIOR_ATTRIBUTE_BASE_BEHAVIOR:
		{
			if(value->isContainer())
			{
				std::shared_ptr<Bag<uml::Behavior>> container = value->get<std::shared_ptr<Bag<uml::Behavior>>>();
				if(container)
				{
					if(!(container->empty()))
					{
						// If a non-empty container is passed, the property will be set to the first value of the container
						this->setBase_Behavior(container->at(0));
					}
				}
			}
			else
			{
				this->setBase_Behavior(value->get<std::shared_ptr<uml::Behavior>>());
			}
			return;
		}
	}

}

//Add
void MainBehaviorImpl::add(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->set(qualifiedName, value);
}

void MainBehaviorImpl::add(std::string _qualifiedName, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->set(uID, value);
}

void MainBehaviorImpl::add(unsigned long _uID, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
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
	switch(_uID)
	{
		case UML4CPPProfile::UML4CPPProfilePackage::MAINBEHAVIOR_ATTRIBUTE_BASE_BEHAVIOR:
		{
			m_base_Behavior.reset();
			return;
		}
	}

}

//*********************************
// Operation Invoction
//*********************************
//Invoke
std::shared_ptr<Any> MainBehaviorImpl::invoke(std::shared_ptr<uml::Operation> _operation, std::shared_ptr<Bag<Any>> _arguments)
{
	std::string qualifiedName = _operation->getQualifiedName();

	for(unsigned int i = 0; i < _operation->getOwnedParameter()->size(); i++)
	{
		qualifiedName += "_" + _operation->getOwnedParameter()->at(i)->getType()->getName();
	}

	return this->invoke(qualifiedName, _arguments);
}

std::shared_ptr<Any> MainBehaviorImpl::invoke(std::string _qualifiedName, std::shared_ptr<Bag<Any>> _arguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->invoke(uID, _arguments);
}

std::shared_ptr<Any> MainBehaviorImpl::invoke(unsigned long _uID, std::shared_ptr<Bag<Any>> _arguments)
{
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
