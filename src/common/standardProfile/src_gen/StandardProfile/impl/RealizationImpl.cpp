#include "StandardProfile/impl/RealizationImpl.hpp"

#ifdef NDEBUG
	#define DEBUG_INFO(a)		/**/
	#define DEBUG_WARNING(a)	/**/
	#define DEBUG_ERROR(a)		/**/
#else
	#define DEBUG_INFO(a) 		std::cout<<"[\e[0;32mInfo\e[0m]:\t\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_WARNING(a) 	std::cout<<"[\e[0;33mWarning\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_ERROR(a)		std::cout<<"[\e[0;31mError\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
#endif

//General includes
#include <iostream>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "util/util.hpp"
#include "uml/UMLAny.hpp"
#include "uml/UMLContainerAny.hpp"
#include "uml/Property.hpp"
#include "uml/Operation.hpp"
#include "uml/OpaqueBehavior.hpp"
#include "uml/FunctionBehavior.hpp"
#include "uml/Parameter.hpp"
#include "StandardProfile/StandardProfileFactory.hpp"
#include "StandardProfile/impl/StandardProfilePackageImpl.hpp"
#include "uml/Stereotype.hpp"

//Packages for used (non-primitive) Types
#include "uml/umlPackage.hpp"

//Used Types
#include "uml/Classifier.hpp"

//Packges and Factories included from types of attributes, operation parameters, imports and composite owner classes
#include "uml/umlFactory.hpp"
#include "uml/impl/umlPackageImpl.hpp"

using namespace StandardProfile;

//*********************************
// Constructor / Destructor
//*********************************
RealizationImpl::RealizationImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_INFO("Instance of 'Realization' is created.")
	//***********************************
}


RealizationImpl::~RealizationImpl()
{
	DEBUG_INFO("Instance of 'Realization' is destroyed.")
}

RealizationImpl::RealizationImpl(const RealizationImpl & obj):RealizationImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  RealizationImpl::copy() const
{
	std::shared_ptr<RealizationImpl> element(new RealizationImpl());
	*element=(*this);
	element->setThisRealizationPtr(element);
	return element;
}

RealizationImpl& RealizationImpl::operator=(const RealizationImpl & obj)
{
	//call overloaded =Operator for each base class
	uml::StereotypeImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Realization "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();

	//copy attributes with no containment (soft copy)
	m_base_Classifier = obj.getBase_Classifier();

	//clone attributes with containment (deep copy)

	return *this;
}


std::shared_ptr<uml::Class> RealizationImpl::getMetaClass() const
{
	return StandardProfilePackageImpl::eInstance()->get_StandardProfile_Realization();
}

void RealizationImpl::instantiate()
{   
	
}

void RealizationImpl::destroy()
{	

	//Erase properties
	//deleting property base_Classifier
	m_base_Classifier.reset();
	
	//Erase back reference to owner
}

//*********************************
// Attribute Setter Getter
//*********************************
void RealizationImpl::setBase_Classifier(std::weak_ptr<uml::Classifier> _base_Classifier)
{
	m_base_Classifier = _base_Classifier;
	
}
std::weak_ptr<uml::Classifier> RealizationImpl::getBase_Classifier() const 
{

	return m_base_Classifier;
}

//*********************************
// Union Getter
//*********************************



//*********************************
// Operations
//*********************************
//**************************************
// StructuralFeature Getter & Setter
//**************************************
//Get
std::shared_ptr<Any> RealizationImpl::get(std::shared_ptr<uml::Property> _property) const
{
	return this->get(_property->_getID());
}

std::shared_ptr<Any> RealizationImpl::get(std::string _qualifiedName) const
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->get(uID);
}

std::shared_ptr<Any> RealizationImpl::get(unsigned long _uID) const
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::REALIZATION_PROPERTY_BASE_CLASSIFIER:
			return eUMLAny(this->getBase_Classifier().lock(), uml::umlPackage::CLASSIFIER_CLASS);
	}

	return eAny(nullptr, -1, false);
}

//Set
void RealizationImpl::set(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value)
{
	this->set(_property->_getID(), value);
}

void RealizationImpl::set(std::string _qualifiedName, std::shared_ptr<Any> value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->set(uID, value);
}

void RealizationImpl::set(unsigned long _uID, std::shared_ptr<Any> value)
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::REALIZATION_PROPERTY_BASE_CLASSIFIER:
		{
			std::shared_ptr<uml::UMLAny> umlAny = std::dynamic_pointer_cast<uml::UMLAny>(value);
			if(umlAny)
			{
				try
				{
					std::shared_ptr<uml::Element> element = umlAny->getAsElement();
					std::shared_ptr<uml::Classifier> _base_Classifier = std::dynamic_pointer_cast<uml::Classifier>(umlAny);
					if(_base_Classifier)
					{
						setBase_Classifier(_base_Classifier);
					}			
					else
					{
						throw "Invalid argument";
					}		
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'uml::UMLAny' for property 'base_Classifier'. Failed to set property!")
					return;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'uml::UMLAny' for property 'base_Classifier'. Failed to set property!")
				return;
			}
		break;
		}
	}
}

//Add
void RealizationImpl::add(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
	this->add(_property->_getID(), value);
}

void RealizationImpl::add(std::string _qualifiedName, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->add(uID, value);
}

void RealizationImpl::add(unsigned long _uID, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
}

//Unset
void RealizationImpl::unset(std::shared_ptr<uml::Property> _property)
{
	this->unset(_property->_getID());
}

void RealizationImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->unset(uID);
}

void RealizationImpl::unset(unsigned long _uID)
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::REALIZATION_PROPERTY_BASE_CLASSIFIER:
		{
			m_base_Classifier.reset();
			return;
		}
	}

}

//Remove
void RealizationImpl::remove(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value)
{
	this->remove(_property->_getID(), value);
}

void RealizationImpl::remove(std::string _qualifiedName, std::shared_ptr<Any> value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->remove(uID, value);
}

void RealizationImpl::remove(unsigned long _uID, std::shared_ptr<Any> value)
{
}

//**************************************
// Operation & OpaqueBehavior Invocation
//**************************************
//Operation Invocation
std::shared_ptr<Any> RealizationImpl::invoke(std::shared_ptr<uml::Operation> _operation, std::shared_ptr<Bag<Any>> inputArguments, std::shared_ptr<Bag<Any>> outputArguments)
{
	return this->invoke(_operation->_getID(), inputArguments, outputArguments);
}

std::shared_ptr<Any> RealizationImpl::invoke(std::string _qualifiedName, std::shared_ptr<Bag<Any>> inputArguments, std::shared_ptr<Bag<Any>> outputArguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->invoke(uID, inputArguments, outputArguments);
}

std::shared_ptr<Any> RealizationImpl::invoke(unsigned long _uID, std::shared_ptr<Bag<Any>> inputArguments, std::shared_ptr<Bag<Any>> outputArguments)
{
	std::shared_ptr<Any> result = eAny(nullptr, -1, false);
	return result;
}

//OpaqueBehavior Invocation
std::shared_ptr<Any> RealizationImpl::invoke(std::shared_ptr<uml::OpaqueBehavior> _opaqueBehavior, std::shared_ptr<Bag<Any>> inputArguments, std::shared_ptr<Bag<Any>> outputArguments)
{
	return eAny(nullptr, -1, false);
}

std::shared_ptr<Realization> RealizationImpl::getThisRealizationPtr()
{
	return m_thisRealizationPtr.lock();
}
void RealizationImpl::setThisRealizationPtr(std::weak_ptr<Realization> thisRealizationPtr)
{
	m_thisRealizationPtr = thisRealizationPtr;
	setThisStereotypePtr(thisRealizationPtr);
}
