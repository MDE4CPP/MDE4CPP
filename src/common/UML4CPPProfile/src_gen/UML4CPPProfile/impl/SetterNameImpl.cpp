#include "UML4CPPProfile/impl/SetterNameImpl.hpp"

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
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
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"
#include "uml/Property.hpp"

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
SetterNameImpl::SetterNameImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_MESSAGE(std::cout<<"SetterName is created..."<<std::endl;)
	//***********************************
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


std::shared_ptr<uml::Class> SetterNameImpl::getMetaClass() const
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
std::shared_ptr<Any> SetterNameImpl::get(std::shared_ptr<uml::Property> _property) const
{
	std::string qualifiedName = _property->getQualifiedName();
	return this->get(qualifiedName);
}

std::shared_ptr<Any> SetterNameImpl::get(std::string _qualifiedName) const
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->get(uID);
}

std::shared_ptr<Any> SetterNameImpl::get(unsigned long _uID) const
{
	switch(_uID)
	{
		case UML4CPPProfile::UML4CPPProfilePackage::SETTERNAME_ATTRIBUTE_BASE_PROPERTY:
			return eUMLAny(this->getBase_Property().lock(), uml::umlPackage::PROPERTY_CLASS);
		case UML4CPPProfile::UML4CPPProfilePackage::SETTERNAME_ATTRIBUTE_SETTERNAME:
			return eAny(this->getSetterName(), types::typesPackage::STRING_CLASS, false);
	}

	return eAny(nullptr, -1, false);
}

//Set
void SetterNameImpl::set(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->set(qualifiedName, value);
}

void SetterNameImpl::set(std::string _qualifiedName, std::shared_ptr<Any> value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->set(uID, value);
}

void SetterNameImpl::set(unsigned long _uID, std::shared_ptr<Any> value)
{
	switch(_uID)
	{
		case UML4CPPProfile::UML4CPPProfilePackage::SETTERNAME_ATTRIBUTE_BASE_PROPERTY:
		{
			std::shared_ptr<uml::UMLAny> umlAny = std::dynamic_pointer_cast<uml::UMLAny>(value);
			if(umlAny)
			{
				try
				{
					std::shared_ptr<uml::Element> element = umlAny->getAsElement();
					std::shared_ptr<uml::Property> _base_Property = std::dynamic_pointer_cast<uml::Property>(umlAny);
					if(_base_Property)
					{
						setBase_Property(_base_Property);
					}			
					else
					{
						throw "Invalid argument";
					}		
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'uml::UMLAny' for property 'base_Property'. Failed to set property!"<< std::endl;)
					return;
				}
			}
			else
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid instance of 'uml::UMLAny' for property 'base_Property'. Failed to set property!"<< std::endl;)
				return;
			}
		break;
		}
		case UML4CPPProfile::UML4CPPProfilePackage::SETTERNAME_ATTRIBUTE_SETTERNAME:
		{
			try
			{
				std::string _setterName = value->get<std::string>();
				setSetterName(_setterName);
			}
			catch(...)
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'Any' for property 'setterName'. Failed to set property!"<< std::endl;)
				return;
			}
		break;
		}
	}
}

//Add
void SetterNameImpl::add(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->set(qualifiedName, value);
}

void SetterNameImpl::add(std::string _qualifiedName, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->set(uID, value);
}

void SetterNameImpl::add(unsigned long _uID, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
}

//Unset
void SetterNameImpl::unset(std::shared_ptr<uml::Property> _property)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->unset(qualifiedName);
}

void SetterNameImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->unset(uID);
}

void SetterNameImpl::unset(unsigned long _uID)
{
	switch(_uID)
	{
		case UML4CPPProfile::UML4CPPProfilePackage::SETTERNAME_ATTRIBUTE_BASE_PROPERTY:
		{
			m_base_Property.reset();
			return;
		}
	}

}

//*********************************
// Operation Invoction
//*********************************
//Invoke
std::shared_ptr<Any> SetterNameImpl::invoke(std::shared_ptr<uml::Operation> _operation, std::shared_ptr<Bag<Any>> _arguments)
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

std::shared_ptr<Any> SetterNameImpl::invoke(std::string _qualifiedName, std::shared_ptr<Bag<Any>> _arguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->invoke(uID, _arguments);
}

std::shared_ptr<Any> SetterNameImpl::invoke(unsigned long _uID, std::shared_ptr<Bag<Any>> _arguments)
{
	return eAny(nullptr, -1, false);
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
