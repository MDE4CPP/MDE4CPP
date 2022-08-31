#include "UML4CPPProfile/impl/NonExecutableImpl.hpp"

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
#include "uml/umlPackage.hpp"
#include "uml/NamedElement.hpp"

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
NonExecutableImpl::NonExecutableImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_MESSAGE(std::cout<<"NonExecutable is created..."<<std::endl;)
	//***********************************
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


std::shared_ptr<uml::Class> NonExecutableImpl::getMetaClass() const
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
std::shared_ptr<Any> NonExecutableImpl::get(std::shared_ptr<uml::Property> _property) const
{
	std::string qualifiedName = _property->getQualifiedName();
	return this->get(qualifiedName);
}

std::shared_ptr<Any> NonExecutableImpl::get(std::string _qualifiedName) const
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->get(uID);
}

std::shared_ptr<Any> NonExecutableImpl::get(unsigned long _uID) const
{
	switch(_uID)
	{
		case UML4CPPProfile::UML4CPPProfilePackage::NONEXECUTABLE_ATTRIBUTE_BASE_NAMEDELEMENT:
			return eUMLAny(this->getBase_NamedElement().lock(), uml::umlPackage::NAMEDELEMENT_CLASS);
	}

	return eAny(nullptr, -1, false);
}

//Set
void NonExecutableImpl::set(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->set(qualifiedName, value);
}

void NonExecutableImpl::set(std::string _qualifiedName, std::shared_ptr<Any> value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->set(uID, value);
}

void NonExecutableImpl::set(unsigned long _uID, std::shared_ptr<Any> value)
{
	switch(_uID)
	{
		case UML4CPPProfile::UML4CPPProfilePackage::NONEXECUTABLE_ATTRIBUTE_BASE_NAMEDELEMENT:
		{
			std::shared_ptr<uml::UMLAny> umlAny = std::dynamic_pointer_cast<uml::UMLAny>(value);
			if(umlAny)
			{
				try
				{
					std::shared_ptr<uml::Element> element = umlAny->getAsElement();
					std::shared_ptr<uml::NamedElement> _base_NamedElement = std::dynamic_pointer_cast<uml::NamedElement>(umlAny);
					if(_base_NamedElement)
					{
						setBase_NamedElement(_base_NamedElement);
					}			
					else
					{
						throw "Invalid argument";
					}		
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'uml::UMLAny' for property 'base_NamedElement'. Failed to set property!"<< std::endl;)
					return;
				}
			}
			else
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid instance of 'uml::UMLAny' for property 'base_NamedElement'. Failed to set property!"<< std::endl;)
				return;
			}
		break;
		}
	}
}

//Add
void NonExecutableImpl::add(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->set(qualifiedName, value);
}

void NonExecutableImpl::add(std::string _qualifiedName, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->set(uID, value);
}

void NonExecutableImpl::add(unsigned long _uID, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
}

//Unset
void NonExecutableImpl::unset(std::shared_ptr<uml::Property> _property)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->unset(qualifiedName);
}

void NonExecutableImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->unset(uID);
}

void NonExecutableImpl::unset(unsigned long _uID)
{
	switch(_uID)
	{
		case UML4CPPProfile::UML4CPPProfilePackage::NONEXECUTABLE_ATTRIBUTE_BASE_NAMEDELEMENT:
		{
			m_base_NamedElement.reset();
			return;
		}
	}

}

//*********************************
// Operation Invoction
//*********************************
//Invoke
std::shared_ptr<Any> NonExecutableImpl::invoke(std::shared_ptr<uml::Operation> _operation, std::shared_ptr<Bag<Any>> _arguments)
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

std::shared_ptr<Any> NonExecutableImpl::invoke(std::string _qualifiedName, std::shared_ptr<Bag<Any>> _arguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->invoke(uID, _arguments);
}

std::shared_ptr<Any> NonExecutableImpl::invoke(unsigned long _uID, std::shared_ptr<Bag<Any>> _arguments)
{
	return eAny(nullptr, -1, false);
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
