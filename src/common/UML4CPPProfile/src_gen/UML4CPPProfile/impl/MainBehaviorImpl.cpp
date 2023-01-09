#include "UML4CPPProfile/impl/MainBehaviorImpl.hpp"

#ifdef NDEBUG
	#define DEBUG_INFO(a)		/**/
	#define DEBUG_WARNING(a)	/**/
	#define DEBUG_ERROR(a)		/**/
#else
	#define DEBUG_INFO(a) 		std::cout<<"[\e[0;32mInfo\e[0m]:\t\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_WARNING(a) 	std::cout<<"[\e[0;33mWarning\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_ERROR(a)		std::cout<<"[\e[0;31mError\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
#endif

#include <iostream>


#include "abstractDataTypes/SubsetUnion.hpp"
#include "util/util.hpp"
#include "uml/UMLAny.hpp"
#include "uml/UMLContainerAny.hpp"
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
	DEBUG_INFO("Instance of 'MainBehavior' is created.")
	//***********************************
}


MainBehaviorImpl::~MainBehaviorImpl()
{
	DEBUG_INFO("Instance of 'MainBehavior' is destroyed.")
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
			return eUMLAny(this->getBase_Behavior().lock(), uml::umlPackage::BEHAVIOR_CLASS);
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
			std::shared_ptr<uml::UMLAny> umlAny = std::dynamic_pointer_cast<uml::UMLAny>(value);
			if(umlAny)
			{
				try
				{
					std::shared_ptr<uml::Element> element = umlAny->getAsElement();
					std::shared_ptr<uml::Behavior> _base_Behavior = std::dynamic_pointer_cast<uml::Behavior>(umlAny);
					if(_base_Behavior)
					{
						setBase_Behavior(_base_Behavior);
					}			
					else
					{
						throw "Invalid argument";
					}		
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'uml::UMLAny' for property 'base_Behavior'. Failed to set property!")
					return;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'uml::UMLAny' for property 'base_Behavior'. Failed to set property!")
				return;
			}
		break;
		}
	}
}

//Add
void MainBehaviorImpl::add(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->add(qualifiedName, value);
}

void MainBehaviorImpl::add(std::string _qualifiedName, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->add(uID, value);
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

//Remove
void MainBehaviorImpl::remove(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->remove(qualifiedName, value);
}

void MainBehaviorImpl::remove(std::string _qualifiedName, std::shared_ptr<Any> value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->remove(uID, value);
}

void MainBehaviorImpl::remove(unsigned long _uID, std::shared_ptr<Any> value)
{
}

//*********************************
// Operation Invoction
//*********************************
//Invoke
std::shared_ptr<Any> MainBehaviorImpl::invoke(std::shared_ptr<uml::Operation> _operation, std::shared_ptr<Bag<Any>> _arguments)
{
	return eAny(nullptr, -1, false);

	/* Currently not functioning. TODO: Clarifiy how this should work in the future
	std::string qualifiedName = _operation->getQualifiedName();

	for(unsigned int i = 0; i < _operation->getOwnedParameter()->size(); i++)
	{
		qualifiedName += "_" + _operation->getOwnedParameter()->at(i)->getType()->getName();
	}

	return this->invoke(qualifiedName, _arguments);
	*/
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
