#include "StandardProfile/impl/DeriveImpl.hpp"

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
#include "StandardProfile/StandardProfileFactory.hpp"
#include "StandardProfile/impl/StandardProfilePackageImpl.hpp"
#include "uml/Stereotype.hpp"

//Types included from attributes, operation parameters, imports and composite owner classes
#include "uml/umlPackage.hpp"
#include "uml/Abstraction.hpp"

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
DeriveImpl::DeriveImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_MESSAGE(std::cout<<"Derive is created..."<<std::endl;)
	//***********************************
}


DeriveImpl::~DeriveImpl()
{
	DEBUG_MESSAGE(std::cout<<"Derive is destroyed..."<<std::endl;)
}

DeriveImpl::DeriveImpl(const DeriveImpl & obj):DeriveImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  DeriveImpl::copy() const
{
	std::shared_ptr<DeriveImpl> element(new DeriveImpl());
	*element=(*this);
	element->setThisDerivePtr(element);
	return element;
}

DeriveImpl& DeriveImpl::operator=(const DeriveImpl & obj)
{
	//call overloaded =Operator for each base class
	uml::StereotypeImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Derive "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();

	//copy attributes with no containment (soft copy)
	m_base_Abstraction = obj.getBase_Abstraction();

	//clone attributes with containment (deep copy)

	return *this;
}


std::shared_ptr<uml::Class> DeriveImpl::getMetaClass() const
{
	return StandardProfilePackageImpl::eInstance()->get_StandardProfile_Derive();
}

void DeriveImpl::instantiate()
{   
	
}

void DeriveImpl::destroy()
{	

	//Erase properties
	//deleting property base_Abstraction
	m_base_Abstraction.reset();
	
	//Erase back reference to owner
}

//*********************************
// Attribute Setter Getter
//*********************************
void DeriveImpl::setBase_Abstraction(std::weak_ptr<uml::Abstraction> _base_Abstraction)
{
	m_base_Abstraction = _base_Abstraction;
	
}
std::weak_ptr<uml::Abstraction> DeriveImpl::getBase_Abstraction() const 
{

	return m_base_Abstraction;
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
std::shared_ptr<Any> DeriveImpl::get(std::shared_ptr<uml::Property> _property) const
{
	std::string qualifiedName = _property->getQualifiedName();
	return this->get(qualifiedName);
}

std::shared_ptr<Any> DeriveImpl::get(std::string _qualifiedName) const
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->get(uID);
}

std::shared_ptr<Any> DeriveImpl::get(unsigned long _uID) const
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::DERIVE_ATTRIBUTE_BASE_ABSTRACTION:
			return eUMLAny(this->getBase_Abstraction().lock(), uml::umlPackage::ABSTRACTION_CLASS);
	}

	return eAny(nullptr, -1, false);
}

//Set
void DeriveImpl::set(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->set(qualifiedName, value);
}

void DeriveImpl::set(std::string _qualifiedName, std::shared_ptr<Any> value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->set(uID, value);
}

void DeriveImpl::set(unsigned long _uID, std::shared_ptr<Any> value)
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::DERIVE_ATTRIBUTE_BASE_ABSTRACTION:
		{
			std::shared_ptr<uml::UMLAny> umlAny = std::dynamic_pointer_cast<uml::UMLAny>(value);
			if(umlAny)
			{
				try
				{
					std::shared_ptr<uml::Element> element = umlAny->getAsElement();
					std::shared_ptr<uml::Abstraction> _base_Abstraction = std::dynamic_pointer_cast<uml::Abstraction>(umlAny);
					if(_base_Abstraction)
					{
						setBase_Abstraction(_base_Abstraction);
					}			
					else
					{
						throw "Invalid argument";
					}		
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'uml::UMLAny' for property 'base_Abstraction'. Failed to set property!"<< std::endl;)
					return;
				}
			}
			else
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid instance of 'uml::UMLAny' for property 'base_Abstraction'. Failed to set property!"<< std::endl;)
				return;
			}
		break;
		}
	}
}

//Add
void DeriveImpl::add(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->set(qualifiedName, value);
}

void DeriveImpl::add(std::string _qualifiedName, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->set(uID, value);
}

void DeriveImpl::add(unsigned long _uID, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
}

//Unset
void DeriveImpl::unset(std::shared_ptr<uml::Property> _property)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->unset(qualifiedName);
}

void DeriveImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->unset(uID);
}

void DeriveImpl::unset(unsigned long _uID)
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::DERIVE_ATTRIBUTE_BASE_ABSTRACTION:
		{
			m_base_Abstraction.reset();
			return;
		}
	}

}

//*********************************
// Operation Invoction
//*********************************
//Invoke
std::shared_ptr<Any> DeriveImpl::invoke(std::shared_ptr<uml::Operation> _operation, std::shared_ptr<Bag<Any>> _arguments)
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

std::shared_ptr<Any> DeriveImpl::invoke(std::string _qualifiedName, std::shared_ptr<Bag<Any>> _arguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->invoke(uID, _arguments);
}

std::shared_ptr<Any> DeriveImpl::invoke(unsigned long _uID, std::shared_ptr<Bag<Any>> _arguments)
{
	return eAny(nullptr, -1, false);
}

std::shared_ptr<Derive> DeriveImpl::getThisDerivePtr()
{
	return m_thisDerivePtr.lock();
}
void DeriveImpl::setThisDerivePtr(std::weak_ptr<Derive> thisDerivePtr)
{
	m_thisDerivePtr = thisDerivePtr;
	setThisStereotypePtr(thisDerivePtr);
}
