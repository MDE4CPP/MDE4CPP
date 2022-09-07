#include "UML4CPPProfile/impl/DoNotGenerateImpl.hpp"

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
#include "uml/Element.hpp"

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
DoNotGenerateImpl::DoNotGenerateImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_INFO("Instance of 'DoNotGenerate' is created.")
	//***********************************
}


DoNotGenerateImpl::~DoNotGenerateImpl()
{
	DEBUG_INFO("Instance of 'DoNotGenerate' is destroyed.")
}

DoNotGenerateImpl::DoNotGenerateImpl(const DoNotGenerateImpl & obj):DoNotGenerateImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  DoNotGenerateImpl::copy() const
{
	std::shared_ptr<DoNotGenerateImpl> element(new DoNotGenerateImpl());
	*element=(*this);
	element->setThisDoNotGeneratePtr(element);
	return element;
}

DoNotGenerateImpl& DoNotGenerateImpl::operator=(const DoNotGenerateImpl & obj)
{
	//call overloaded =Operator for each base class
	uml::StereotypeImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy DoNotGenerate "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();

	//copy attributes with no containment (soft copy)
	m_base_Element = obj.getBase_Element();

	//clone attributes with containment (deep copy)

	return *this;
}


std::shared_ptr<uml::Class> DoNotGenerateImpl::getMetaClass() const
{
	return UML4CPPProfilePackageImpl::eInstance()->get_UML4CPPProfile_DoNotGenerate();
}

void DoNotGenerateImpl::instantiate()
{   
	
}

void DoNotGenerateImpl::destroy()
{	

	//Erase properties
	//deleting property base_Element
	m_base_Element.reset();
	
	//Erase back reference to owner
}

//*********************************
// Attribute Setter Getter
//*********************************
void DoNotGenerateImpl::setBase_Element(std::shared_ptr<uml::Element> _base_Element)
{
	m_base_Element = _base_Element;
	
}
std::shared_ptr<uml::Element> DoNotGenerateImpl::getBase_Element() const 
{

	return m_base_Element;
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
std::shared_ptr<Any> DoNotGenerateImpl::get(std::shared_ptr<uml::Property> _property) const
{
	std::string qualifiedName = _property->getQualifiedName();
	return this->get(qualifiedName);
}

std::shared_ptr<Any> DoNotGenerateImpl::get(std::string _qualifiedName) const
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->get(uID);
}

std::shared_ptr<Any> DoNotGenerateImpl::get(unsigned long _uID) const
{
	switch(_uID)
	{
		case UML4CPPProfile::UML4CPPProfilePackage::DONOTGENERATE_ATTRIBUTE_BASE_ELEMENT:
			return eUMLAny(this->getBase_Element(), uml::umlPackage::ELEMENT_CLASS);
	}

	return eAny(nullptr, -1, false);
}

//Set
void DoNotGenerateImpl::set(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->set(qualifiedName, value);
}

void DoNotGenerateImpl::set(std::string _qualifiedName, std::shared_ptr<Any> value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->set(uID, value);
}

void DoNotGenerateImpl::set(unsigned long _uID, std::shared_ptr<Any> value)
{
	switch(_uID)
	{
		case UML4CPPProfile::UML4CPPProfilePackage::DONOTGENERATE_ATTRIBUTE_BASE_ELEMENT:
		{
			std::shared_ptr<uml::UMLAny> umlAny = std::dynamic_pointer_cast<uml::UMLAny>(value);
			if(umlAny)
			{
				try
				{
					std::shared_ptr<uml::Element> element = umlAny->getAsElement();
					std::shared_ptr<uml::Element> _base_Element = std::dynamic_pointer_cast<uml::Element>(umlAny);
					if(_base_Element)
					{
						setBase_Element(_base_Element);
					}			
					else
					{
						throw "Invalid argument";
					}		
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'uml::UMLAny' for property 'base_Element'. Failed to set property!")
					return;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'uml::UMLAny' for property 'base_Element'. Failed to set property!")
				return;
			}
		break;
		}
	}
}

//Add
void DoNotGenerateImpl::add(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->add(qualifiedName, value);
}

void DoNotGenerateImpl::add(std::string _qualifiedName, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->add(uID, value);
}

void DoNotGenerateImpl::add(unsigned long _uID, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
}

//Unset
void DoNotGenerateImpl::unset(std::shared_ptr<uml::Property> _property)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->unset(qualifiedName);
}

void DoNotGenerateImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->unset(uID);
}

void DoNotGenerateImpl::unset(unsigned long _uID)
{
	switch(_uID)
	{
		case UML4CPPProfile::UML4CPPProfilePackage::DONOTGENERATE_ATTRIBUTE_BASE_ELEMENT:
		{
			m_base_Element.reset();
			return;
		}
	}

}

//Remove
void DoNotGenerateImpl::remove(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->remove(qualifiedName, value);
}

void DoNotGenerateImpl::remove(std::string _qualifiedName, std::shared_ptr<Any> value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->remove(uID, value);
}

void DoNotGenerateImpl::remove(unsigned long _uID, std::shared_ptr<Any> value)
{
}

//*********************************
// Operation Invoction
//*********************************
//Invoke
std::shared_ptr<Any> DoNotGenerateImpl::invoke(std::shared_ptr<uml::Operation> _operation, std::shared_ptr<Bag<Any>> _arguments)
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

std::shared_ptr<Any> DoNotGenerateImpl::invoke(std::string _qualifiedName, std::shared_ptr<Bag<Any>> _arguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->invoke(uID, _arguments);
}

std::shared_ptr<Any> DoNotGenerateImpl::invoke(unsigned long _uID, std::shared_ptr<Bag<Any>> _arguments)
{
	return eAny(nullptr, -1, false);
}

std::shared_ptr<DoNotGenerate> DoNotGenerateImpl::getThisDoNotGeneratePtr()
{
	return m_thisDoNotGeneratePtr.lock();
}
void DoNotGenerateImpl::setThisDoNotGeneratePtr(std::weak_ptr<DoNotGenerate> thisDoNotGeneratePtr)
{
	m_thisDoNotGeneratePtr = thisDoNotGeneratePtr;
	setThisStereotypePtr(thisDoNotGeneratePtr);
}
