#include "StandardProfile/impl/DestroyImpl.hpp"

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
#include "uml/BehavioralFeature.hpp"

//Packges and Factories included from types of attributes, operation parameters, imports and composite owner classes
#include "uml/umlFactory.hpp"
#include "uml/impl/umlPackageImpl.hpp"

using namespace StandardProfile;

//*********************************
// Constructor / Destructor
//*********************************
DestroyImpl::DestroyImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_INFO("Instance of 'Destroy' is created.")
	//***********************************
}


DestroyImpl::~DestroyImpl()
{
	DEBUG_INFO("Instance of 'Destroy' is destroyed.")
}

DestroyImpl::DestroyImpl(const DestroyImpl & obj):DestroyImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  DestroyImpl::copy() const
{
	std::shared_ptr<DestroyImpl> element(new DestroyImpl());
	*element=(*this);
	element->setThisDestroyPtr(element);
	return element;
}

DestroyImpl& DestroyImpl::operator=(const DestroyImpl & obj)
{
	//call overloaded =Operator for each base class
	uml::StereotypeImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Destroy "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();

	//copy attributes with no containment (soft copy)
	m_base_BehavioralFeature = obj.getBase_BehavioralFeature();

	//clone attributes with containment (deep copy)

	return *this;
}


const std::shared_ptr<uml::Class>& DestroyImpl::getMetaClass() const
{
	static const std::shared_ptr<uml::Class> metaClass = StandardProfilePackageImpl::eInstance()->get_StandardProfile_Destroy();
	return metaClass;
}

void DestroyImpl::instantiate()
{   
	
}

void DestroyImpl::destroy()
{	

	//Erase properties	//deleting property base_BehavioralFeature
	m_base_BehavioralFeature.reset();
	
}

//*********************************
// Attribute Setter Getter
//*********************************
void DestroyImpl::setBase_BehavioralFeature(std::weak_ptr<uml::BehavioralFeature> _base_BehavioralFeature)
{
	m_base_BehavioralFeature = _base_BehavioralFeature;
	
}
std::weak_ptr<uml::BehavioralFeature> DestroyImpl::getBase_BehavioralFeature() const 
{

	return m_base_BehavioralFeature;
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
std::shared_ptr<Any> DestroyImpl::get(const std::shared_ptr<uml::Property>& _property) const
{
	return this->get(_property->_getID());
}

std::shared_ptr<Any> DestroyImpl::get(std::string _qualifiedName) const
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->get(uID);
}

std::shared_ptr<Any> DestroyImpl::get(unsigned long _uID) const
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::DESTROY_PROPERTY_BASE_BEHAVIORALFEATURE:
			return eUMLAny(this->getBase_BehavioralFeature().lock(), uml::umlPackage::BEHAVIORALFEATURE_CLASS);
	}

	return eAny(nullptr, -1, false);
}

//Set
bool DestroyImpl::set(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value)
{
	return this->set(_property->_getID(), value);
}

bool DestroyImpl::set( std::string _qualifiedName, const std::shared_ptr<Any>& value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->set(uID, value);
}

bool DestroyImpl::set(unsigned long _uID, const std::shared_ptr<Any>& value)
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::DESTROY_PROPERTY_BASE_BEHAVIORALFEATURE:
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
						return true;
					}			
					else
					{
						throw "Invalid argument";
					}		
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'uml::UMLAny' for property 'base_BehavioralFeature'. Failed to set property!")
					return true;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'uml::UMLAny' for property 'base_BehavioralFeature'. Failed to set property!")
				return true;
			}
		break;
		}
	}
	return false;
}

//Add
bool DestroyImpl::add(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	return this->add(_property->_getID(), value, insertAt);
}

bool DestroyImpl::add(std::string _qualifiedName, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->add(uID, value, insertAt);
}

bool DestroyImpl::add(unsigned long _uID, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	return false;
}

//Unset
bool DestroyImpl::unset(const std::shared_ptr<uml::Property>& _property)
{
	return this->unset(_property->_getID());
}

bool DestroyImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->unset(uID);
}

bool DestroyImpl::unset(unsigned long _uID)
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::DESTROY_PROPERTY_BASE_BEHAVIORALFEATURE:
		{
			m_base_BehavioralFeature.reset();
			return true;
		}
	}

	return false;
}

//Remove
bool DestroyImpl::remove(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	return this->remove(_property->_getID(), value, removeAt);
}

bool DestroyImpl::remove(std::string _qualifiedName, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->remove(uID, value, removeAt);
}

bool DestroyImpl::remove(unsigned long _uID, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::DESTROY_PROPERTY_BASE_BEHAVIORALFEATURE:
		{
			std::shared_ptr<uml::BehavioralFeature> valueToRemove = nullptr;
			if(value->isContainer())
			{
				std::shared_ptr<uml::UMLContainerAny> umlContainerAny = std::dynamic_pointer_cast<uml::UMLContainerAny>(value);
				if(umlContainerAny)
				{
					std::shared_ptr<Bag<uml::Element>> container = umlContainerAny->getAsElementContainer();
					if(container && !(container->empty()))
					{
						// If a non-empty container is passed, the first value of the container will be removed from the property
						std::shared_ptr<uml::Element> firstElement = container->at(0);
						valueToRemove = std::dynamic_pointer_cast<uml::BehavioralFeature>(firstElement);
					}
				}
			}
			else
			{
				std::shared_ptr<uml::UMLAny> umlAny = std::dynamic_pointer_cast<uml::UMLAny>(value);
				if(umlAny)
				{
					std::shared_ptr<uml::Element> element = umlAny->getAsElement();
					valueToRemove = std::dynamic_pointer_cast<uml::BehavioralFeature>(element);
				}
			}

			
			if(removeAt >= 1 && !isRemoveDuplicates) // As per fUML-specification, if isRemoveDuplicates is true, removeAt is ignored
			{
				// If removeAt != -1, the value to remove is not taken into account anymore.
				// Instead, the value at index = removeAt is removed
				// NOTE: removeAt is 1-based rather than 0-based
				
				if(removeAt == 1)
				{
					m_base_BehavioralFeature.reset();
					return true;
				}
			}
			else
			{
				if(m_base_BehavioralFeature.lock() == valueToRemove)
				{
					m_base_BehavioralFeature.reset();
					return true;
				}
			}
		}
	}

	return false;
}

//**************************************
// Operation & OpaqueBehavior Invocation
//**************************************
//Operation Invocation
std::shared_ptr<Any> DestroyImpl::invoke(const std::shared_ptr<uml::Operation>& _operation, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	return this->invoke(_operation->_getID(), inputArguments, outputArguments);
}

std::shared_ptr<Any> DestroyImpl::invoke(std::string _qualifiedName, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->invoke(uID, inputArguments, outputArguments);
}

std::shared_ptr<Any> DestroyImpl::invoke(unsigned long _uID, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	std::shared_ptr<Any> result = eAny(nullptr, -1, false);
	return result;
}

//OpaqueBehavior Invocation
std::shared_ptr<Any> DestroyImpl::invoke(const std::shared_ptr<uml::OpaqueBehavior>& _opaqueBehavior, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	return eAny(nullptr, -1, false);
}

std::shared_ptr<Destroy> DestroyImpl::getThisDestroyPtr()
{
	return m_thisDestroyPtr.lock();
}
void DestroyImpl::setThisDestroyPtr(std::weak_ptr<Destroy> thisDestroyPtr)
{
	m_thisDestroyPtr = thisDestroyPtr;
	setThisStereotypePtr(thisDestroyPtr);
}
