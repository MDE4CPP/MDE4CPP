#include "StandardProfile/impl/FrameworkImpl.hpp"

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
#include "StandardProfile/StandardProfileFactory.hpp"
#include "StandardProfile/impl/StandardProfilePackageImpl.hpp"
#include "uml/Stereotype.hpp"

//Types included from attributes, operation parameters, imports and composite owner classes
#include "uml/umlPackage.hpp"
#include "uml/Package.hpp"

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
FrameworkImpl::FrameworkImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_INFO("Instance of 'Framework' is created.")
	//***********************************
}


FrameworkImpl::~FrameworkImpl()
{
	DEBUG_INFO("Instance of 'Framework' is destroyed.")
}

FrameworkImpl::FrameworkImpl(const FrameworkImpl & obj):FrameworkImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  FrameworkImpl::copy() const
{
	std::shared_ptr<FrameworkImpl> element(new FrameworkImpl());
	*element=(*this);
	element->setThisFrameworkPtr(element);
	return element;
}

FrameworkImpl& FrameworkImpl::operator=(const FrameworkImpl & obj)
{
	//call overloaded =Operator for each base class
	uml::StereotypeImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Framework "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();

	//copy attributes with no containment (soft copy)
	m_base_Package = obj.getBase_Package();

	//clone attributes with containment (deep copy)

	return *this;
}


std::shared_ptr<uml::Class> FrameworkImpl::getMetaClass() const
{
	return StandardProfilePackageImpl::eInstance()->get_StandardProfile_Framework();
}

void FrameworkImpl::instantiate()
{   
	
}

void FrameworkImpl::destroy()
{	

	//Erase properties
	//deleting property base_Package
	m_base_Package.reset();
	
	//Erase back reference to owner
}

//*********************************
// Attribute Setter Getter
//*********************************
void FrameworkImpl::setBase_Package(std::weak_ptr<uml::Package> _base_Package)
{
	m_base_Package = _base_Package;
	
}
std::weak_ptr<uml::Package> FrameworkImpl::getBase_Package() const 
{

	return m_base_Package;
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
std::shared_ptr<Any> FrameworkImpl::get(std::shared_ptr<uml::Property> _property) const
{
	std::string qualifiedName = _property->getQualifiedName();
	return this->get(qualifiedName);
}

std::shared_ptr<Any> FrameworkImpl::get(std::string _qualifiedName) const
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->get(uID);
}

std::shared_ptr<Any> FrameworkImpl::get(unsigned long _uID) const
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::FRAMEWORK_ATTRIBUTE_BASE_PACKAGE:
			return eUMLAny(this->getBase_Package().lock(), uml::umlPackage::PACKAGE_CLASS);
	}

	return eAny(nullptr, -1, false);
}

//Set
void FrameworkImpl::set(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->set(qualifiedName, value);
}

void FrameworkImpl::set(std::string _qualifiedName, std::shared_ptr<Any> value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->set(uID, value);
}

void FrameworkImpl::set(unsigned long _uID, std::shared_ptr<Any> value)
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::FRAMEWORK_ATTRIBUTE_BASE_PACKAGE:
		{
			std::shared_ptr<uml::UMLAny> umlAny = std::dynamic_pointer_cast<uml::UMLAny>(value);
			if(umlAny)
			{
				try
				{
					std::shared_ptr<uml::Element> element = umlAny->getAsElement();
					std::shared_ptr<uml::Package> _base_Package = std::dynamic_pointer_cast<uml::Package>(umlAny);
					if(_base_Package)
					{
						setBase_Package(_base_Package);
					}			
					else
					{
						throw "Invalid argument";
					}		
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'uml::UMLAny' for property 'base_Package'. Failed to set property!")
					return;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'uml::UMLAny' for property 'base_Package'. Failed to set property!")
				return;
			}
		break;
		}
	}
}

//Add
void FrameworkImpl::add(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->add(qualifiedName, value);
}

void FrameworkImpl::add(std::string _qualifiedName, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->add(uID, value);
}

void FrameworkImpl::add(unsigned long _uID, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
}

//Unset
void FrameworkImpl::unset(std::shared_ptr<uml::Property> _property)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->unset(qualifiedName);
}

void FrameworkImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->unset(uID);
}

void FrameworkImpl::unset(unsigned long _uID)
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::FRAMEWORK_ATTRIBUTE_BASE_PACKAGE:
		{
			m_base_Package.reset();
			return;
		}
	}

}

//Remove
void FrameworkImpl::remove(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->remove(qualifiedName, value);
}

void FrameworkImpl::remove(std::string _qualifiedName, std::shared_ptr<Any> value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->remove(uID, value);
}

void FrameworkImpl::remove(unsigned long _uID, std::shared_ptr<Any> value)
{
}

//*********************************
// Operation Invoction
//*********************************
//Invoke
std::shared_ptr<Any> FrameworkImpl::invoke(std::shared_ptr<uml::Operation> _operation, std::shared_ptr<Bag<Any>> _arguments)
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

std::shared_ptr<Any> FrameworkImpl::invoke(std::string _qualifiedName, std::shared_ptr<Bag<Any>> _arguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->invoke(uID, _arguments);
}

std::shared_ptr<Any> FrameworkImpl::invoke(unsigned long _uID, std::shared_ptr<Bag<Any>> _arguments)
{
	return eAny(nullptr, -1, false);
}

std::shared_ptr<Framework> FrameworkImpl::getThisFrameworkPtr()
{
	return m_thisFrameworkPtr.lock();
}
void FrameworkImpl::setThisFrameworkPtr(std::weak_ptr<Framework> thisFrameworkPtr)
{
	m_thisFrameworkPtr = thisFrameworkPtr;
	setThisStereotypePtr(thisFrameworkPtr);
}
