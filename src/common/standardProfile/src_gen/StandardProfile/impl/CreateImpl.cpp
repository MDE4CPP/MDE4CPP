#include "StandardProfile/impl/CreateImpl.hpp"

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
#include "uml/umlPackage.hpp"
#include "uml/BehavioralFeature.hpp"
#include "uml/Usage.hpp"

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
CreateImpl::CreateImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_INFO("Instance of 'Create' is created.")
	//***********************************
}


CreateImpl::~CreateImpl()
{
	DEBUG_INFO("Instance of 'Create' is destroyed.")
}

CreateImpl::CreateImpl(const CreateImpl & obj):CreateImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  CreateImpl::copy() const
{
	std::shared_ptr<CreateImpl> element(new CreateImpl());
	*element=(*this);
	element->setThisCreatePtr(element);
	return element;
}

CreateImpl& CreateImpl::operator=(const CreateImpl & obj)
{
	//call overloaded =Operator for each base class
	uml::StereotypeImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Create "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();

	//copy attributes with no containment (soft copy)
	m_base_BehavioralFeature = obj.getBase_BehavioralFeature();
	m_base_Usage = obj.getBase_Usage();

	//clone attributes with containment (deep copy)

	return *this;
}


std::shared_ptr<uml::Class> CreateImpl::getMetaClass() const
{
	return StandardProfilePackageImpl::eInstance()->get_StandardProfile_Create();
}

void CreateImpl::instantiate()
{   
	
	
}

void CreateImpl::destroy()
{	

	//Erase properties
	//deleting property base_BehavioralFeature
	m_base_BehavioralFeature.reset();
	
	//deleting property base_Usage
	m_base_Usage.reset();
	
	//Erase back reference to owner
}

//*********************************
// Attribute Setter Getter
//*********************************
void CreateImpl::setBase_BehavioralFeature(std::weak_ptr<uml::BehavioralFeature> _base_BehavioralFeature)
{
	m_base_BehavioralFeature = _base_BehavioralFeature;
	
}
std::weak_ptr<uml::BehavioralFeature> CreateImpl::getBase_BehavioralFeature() const 
{

	return m_base_BehavioralFeature;
}

void CreateImpl::setBase_Usage(std::weak_ptr<uml::Usage> _base_Usage)
{
	m_base_Usage = _base_Usage;
	
}
std::weak_ptr<uml::Usage> CreateImpl::getBase_Usage() const 
{

	return m_base_Usage;
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
std::shared_ptr<Any> CreateImpl::get(std::shared_ptr<uml::Property> _property) const
{
	std::string qualifiedName = _property->getQualifiedName();
	return this->get(qualifiedName);
}

std::shared_ptr<Any> CreateImpl::get(std::string _qualifiedName) const
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->get(uID);
}

std::shared_ptr<Any> CreateImpl::get(unsigned long _uID) const
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::CREATE_ATTRIBUTE_BASE_BEHAVIORALFEATURE:
			return eUMLAny(this->getBase_BehavioralFeature().lock(), uml::umlPackage::BEHAVIORALFEATURE_CLASS);
		case StandardProfile::StandardProfilePackage::CREATE_ATTRIBUTE_BASE_USAGE:
			return eUMLAny(this->getBase_Usage().lock(), uml::umlPackage::USAGE_CLASS);
	}

	return eAny(nullptr, -1, false);
}

//Set
void CreateImpl::set(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->set(qualifiedName, value);
}

void CreateImpl::set(std::string _qualifiedName, std::shared_ptr<Any> value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->set(uID, value);
}

void CreateImpl::set(unsigned long _uID, std::shared_ptr<Any> value)
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::CREATE_ATTRIBUTE_BASE_BEHAVIORALFEATURE:
		{
			std::shared_ptr<uml::UMLAny> umlAny = std::dynamic_pointer_cast<uml::UMLAny>(value);
			if(umlAny)
			{
				try
				{
					std::shared_ptr<uml::Element> element = umlAny->getAsElement();
					std::shared_ptr<uml::BehavioralFeature> _base_BehavioralFeature = std::dynamic_pointer_cast<uml::BehavioralFeature>(umlAny);
					if(_base_BehavioralFeature)
					{
						setBase_BehavioralFeature(_base_BehavioralFeature);
					}			
					else
					{
						throw "Invalid argument";
					}		
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'uml::UMLAny' for property 'base_BehavioralFeature'. Failed to set property!")
					return;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'uml::UMLAny' for property 'base_BehavioralFeature'. Failed to set property!")
				return;
			}
		break;
		}
		case StandardProfile::StandardProfilePackage::CREATE_ATTRIBUTE_BASE_USAGE:
		{
			std::shared_ptr<uml::UMLAny> umlAny = std::dynamic_pointer_cast<uml::UMLAny>(value);
			if(umlAny)
			{
				try
				{
					std::shared_ptr<uml::Element> element = umlAny->getAsElement();
					std::shared_ptr<uml::Usage> _base_Usage = std::dynamic_pointer_cast<uml::Usage>(umlAny);
					if(_base_Usage)
					{
						setBase_Usage(_base_Usage);
					}			
					else
					{
						throw "Invalid argument";
					}		
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'uml::UMLAny' for property 'base_Usage'. Failed to set property!")
					return;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'uml::UMLAny' for property 'base_Usage'. Failed to set property!")
				return;
			}
		break;
		}
	}
}

//Add
void CreateImpl::add(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->add(qualifiedName, value);
}

void CreateImpl::add(std::string _qualifiedName, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->add(uID, value);
}

void CreateImpl::add(unsigned long _uID, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
}

//Unset
void CreateImpl::unset(std::shared_ptr<uml::Property> _property)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->unset(qualifiedName);
}

void CreateImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->unset(uID);
}

void CreateImpl::unset(unsigned long _uID)
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::CREATE_ATTRIBUTE_BASE_BEHAVIORALFEATURE:
		{
			m_base_BehavioralFeature.reset();
			return;
		}
		case StandardProfile::StandardProfilePackage::CREATE_ATTRIBUTE_BASE_USAGE:
		{
			m_base_Usage.reset();
			return;
		}
	}

}

//Remove
void CreateImpl::remove(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->remove(qualifiedName, value);
}

void CreateImpl::remove(std::string _qualifiedName, std::shared_ptr<Any> value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->remove(uID, value);
}

void CreateImpl::remove(unsigned long _uID, std::shared_ptr<Any> value)
{
}

//*********************************
// Operation Invoction
//*********************************
//Invoke
std::shared_ptr<Any> CreateImpl::invoke(std::shared_ptr<uml::Operation> _operation, std::shared_ptr<Bag<Any>> _arguments)
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

std::shared_ptr<Any> CreateImpl::invoke(std::string _qualifiedName, std::shared_ptr<Bag<Any>> _arguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->invoke(uID, _arguments);
}

std::shared_ptr<Any> CreateImpl::invoke(unsigned long _uID, std::shared_ptr<Bag<Any>> _arguments)
{
	return eAny(nullptr, -1, false);
}

std::shared_ptr<Create> CreateImpl::getThisCreatePtr()
{
	return m_thisCreatePtr.lock();
}
void CreateImpl::setThisCreatePtr(std::weak_ptr<Create> thisCreatePtr)
{
	m_thisCreatePtr = thisCreatePtr;
	setThisStereotypePtr(thisCreatePtr);
}
