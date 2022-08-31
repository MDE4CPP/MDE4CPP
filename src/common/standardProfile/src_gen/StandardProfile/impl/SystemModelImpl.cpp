#include "StandardProfile/impl/SystemModelImpl.hpp"

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
#include "uml/Model.hpp"

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
SystemModelImpl::SystemModelImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_MESSAGE(std::cout<<"SystemModel is created..."<<std::endl;)
	//***********************************
}


SystemModelImpl::~SystemModelImpl()
{
	DEBUG_MESSAGE(std::cout<<"SystemModel is destroyed..."<<std::endl;)
}

SystemModelImpl::SystemModelImpl(const SystemModelImpl & obj):SystemModelImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  SystemModelImpl::copy() const
{
	std::shared_ptr<SystemModelImpl> element(new SystemModelImpl());
	*element=(*this);
	element->setThisSystemModelPtr(element);
	return element;
}

SystemModelImpl& SystemModelImpl::operator=(const SystemModelImpl & obj)
{
	//call overloaded =Operator for each base class
	uml::StereotypeImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy SystemModel "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();

	//copy attributes with no containment (soft copy)
	m_base_Model = obj.getBase_Model();

	//clone attributes with containment (deep copy)

	return *this;
}


std::shared_ptr<uml::Class> SystemModelImpl::getMetaClass() const
{
	return StandardProfilePackageImpl::eInstance()->get_StandardProfile_SystemModel();
}

void SystemModelImpl::instantiate()
{   
	
}

void SystemModelImpl::destroy()
{	

	//Erase properties
	//deleting property base_Model
	m_base_Model.reset();
	
	//Erase back reference to owner
}

//*********************************
// Attribute Setter Getter
//*********************************
void SystemModelImpl::setBase_Model(std::weak_ptr<uml::Model> _base_Model)
{
	m_base_Model = _base_Model;
	
}
std::weak_ptr<uml::Model> SystemModelImpl::getBase_Model() const 
{

	return m_base_Model;
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
std::shared_ptr<Any> SystemModelImpl::get(std::shared_ptr<uml::Property> _property) const
{
	std::string qualifiedName = _property->getQualifiedName();
	return this->get(qualifiedName);
}

std::shared_ptr<Any> SystemModelImpl::get(std::string _qualifiedName) const
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->get(uID);
}

std::shared_ptr<Any> SystemModelImpl::get(unsigned long _uID) const
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::SYSTEMMODEL_ATTRIBUTE_BASE_MODEL:
			return eUMLAny(this->getBase_Model().lock(), uml::umlPackage::MODEL_CLASS);
	}

	return eAny(nullptr, -1, false);
}

//Set
void SystemModelImpl::set(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->set(qualifiedName, value);
}

void SystemModelImpl::set(std::string _qualifiedName, std::shared_ptr<Any> value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->set(uID, value);
}

void SystemModelImpl::set(unsigned long _uID, std::shared_ptr<Any> value)
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::SYSTEMMODEL_ATTRIBUTE_BASE_MODEL:
		{
			std::shared_ptr<uml::UMLAny> umlAny = std::dynamic_pointer_cast<uml::UMLAny>(value);
			if(umlAny)
			{
				try
				{
					std::shared_ptr<uml::Element> element = umlAny->getAsElement();
					std::shared_ptr<uml::Model> _base_Model = std::dynamic_pointer_cast<uml::Model>(umlAny);
					if(_base_Model)
					{
						setBase_Model(_base_Model);
					}			
					else
					{
						throw "Invalid argument";
					}		
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'uml::UMLAny' for property 'base_Model'. Failed to set property!"<< std::endl;)
					return;
				}
			}
			else
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid instance of 'uml::UMLAny' for property 'base_Model'. Failed to set property!"<< std::endl;)
				return;
			}
		break;
		}
	}
}

//Add
void SystemModelImpl::add(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->set(qualifiedName, value);
}

void SystemModelImpl::add(std::string _qualifiedName, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->set(uID, value);
}

void SystemModelImpl::add(unsigned long _uID, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
}

//Unset
void SystemModelImpl::unset(std::shared_ptr<uml::Property> _property)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->unset(qualifiedName);
}

void SystemModelImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->unset(uID);
}

void SystemModelImpl::unset(unsigned long _uID)
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::SYSTEMMODEL_ATTRIBUTE_BASE_MODEL:
		{
			m_base_Model.reset();
			return;
		}
	}

}

//*********************************
// Operation Invoction
//*********************************
//Invoke
std::shared_ptr<Any> SystemModelImpl::invoke(std::shared_ptr<uml::Operation> _operation, std::shared_ptr<Bag<Any>> _arguments)
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

std::shared_ptr<Any> SystemModelImpl::invoke(std::string _qualifiedName, std::shared_ptr<Bag<Any>> _arguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->invoke(uID, _arguments);
}

std::shared_ptr<Any> SystemModelImpl::invoke(unsigned long _uID, std::shared_ptr<Bag<Any>> _arguments)
{
	return eAny(nullptr, -1, false);
}

std::shared_ptr<SystemModel> SystemModelImpl::getThisSystemModelPtr()
{
	return m_thisSystemModelPtr.lock();
}
void SystemModelImpl::setThisSystemModelPtr(std::weak_ptr<SystemModel> thisSystemModelPtr)
{
	m_thisSystemModelPtr = thisSystemModelPtr;
	setThisStereotypePtr(thisSystemModelPtr);
}
