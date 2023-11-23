#include "UML4CPPProfile/impl/NonExecutableImpl.hpp"

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
#include "UML4CPPProfile/UML4CPPProfileFactory.hpp"
#include "UML4CPPProfile/impl/UML4CPPProfilePackageImpl.hpp"
#include "uml/Stereotype.hpp"

//Packages for used (non-primitive) Types
#include "uml/umlPackage.hpp"

//Used Types
#include "uml/NamedElement.hpp"

//Packges and Factories included from types of attributes, operation parameters, imports and composite owner classes
#include "uml/umlFactory.hpp"
#include "uml/impl/umlPackageImpl.hpp"

using namespace UML4CPPProfile;

//*********************************
// Constructor / Destructor
//*********************************
NonExecutableImpl::NonExecutableImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_INFO("Instance of 'NonExecutable' is created.")
	//***********************************
}


NonExecutableImpl::~NonExecutableImpl()
{
	DEBUG_INFO("Instance of 'NonExecutable' is destroyed.")
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


const std::shared_ptr<uml::Class>& NonExecutableImpl::getMetaClass() const
{
	static const std::shared_ptr<uml::Class> metaClass = UML4CPPProfilePackageImpl::eInstance()->get_UML4CPPProfile_NonExecutable();
	return metaClass;
}

void NonExecutableImpl::instantiate()
{   
	
}

void NonExecutableImpl::destroy()
{	

	//Erase properties	//deleting property base_NamedElement
	m_base_NamedElement.reset();
	
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
//**************************************
// StructuralFeature Getter & Setter
//**************************************
//Get
std::shared_ptr<Any> NonExecutableImpl::get(const std::shared_ptr<uml::Property>& _property) const
{
	return this->get(_property->_getID());
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
		case UML4CPPProfile::UML4CPPProfilePackage::NONEXECUTABLE_PROPERTY_BASE_NAMEDELEMENT:
			return eUMLAny(this->getBase_NamedElement().lock(), uml::umlPackage::NAMEDELEMENT_CLASS);
	}

	return eAny(nullptr, -1, false);
}

//Set
bool NonExecutableImpl::set(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value)
{
	return this->set(_property->_getID(), value);
}

bool NonExecutableImpl::set( std::string _qualifiedName, const std::shared_ptr<Any>& value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->set(uID, value);
}

bool NonExecutableImpl::set(unsigned long _uID, const std::shared_ptr<Any>& value)
{
	switch(_uID)
	{
		case UML4CPPProfile::UML4CPPProfilePackage::NONEXECUTABLE_PROPERTY_BASE_NAMEDELEMENT:
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
						return true;
					}			
					else
					{
						throw "Invalid argument";
					}		
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'uml::UMLAny' for property 'base_NamedElement'. Failed to set property!")
					return true;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'uml::UMLAny' for property 'base_NamedElement'. Failed to set property!")
				return true;
			}
		break;
		}
	}
	return false;
}

//Add
bool NonExecutableImpl::add(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	return this->add(_property->_getID(), value, insertAt);
}

bool NonExecutableImpl::add(std::string _qualifiedName, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->add(uID, value, insertAt);
}

bool NonExecutableImpl::add(unsigned long _uID, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	return false;
}

//Unset
bool NonExecutableImpl::unset(const std::shared_ptr<uml::Property>& _property)
{
	return this->unset(_property->_getID());
}

bool NonExecutableImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->unset(uID);
}

bool NonExecutableImpl::unset(unsigned long _uID)
{
	switch(_uID)
	{
		case UML4CPPProfile::UML4CPPProfilePackage::NONEXECUTABLE_PROPERTY_BASE_NAMEDELEMENT:
		{
			m_base_NamedElement.reset();
			return true;
		}
	}

	return false;
}

//Remove
bool NonExecutableImpl::remove(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	return this->remove(_property->_getID(), value, removeAt);
}

bool NonExecutableImpl::remove(std::string _qualifiedName, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->remove(uID, value, removeAt);
}

bool NonExecutableImpl::remove(unsigned long _uID, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	switch(_uID)
	{
		case UML4CPPProfile::UML4CPPProfilePackage::NONEXECUTABLE_PROPERTY_BASE_NAMEDELEMENT:
		{
			std::shared_ptr<uml::NamedElement> valueToRemove = nullptr;
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
						valueToRemove = std::dynamic_pointer_cast<uml::NamedElement>(firstElement);
					}
				}
			}
			else
			{
				std::shared_ptr<uml::UMLAny> umlAny = std::dynamic_pointer_cast<uml::UMLAny>(value);
				if(umlAny)
				{
					std::shared_ptr<uml::Element> element = umlAny->getAsElement();
					valueToRemove = std::dynamic_pointer_cast<uml::NamedElement>(element);
				}
			}

			
			if(removeAt >= 1 && !isRemoveDuplicates) // As per fUML-specification, if isRemoveDuplicates is true, removeAt is ignored
			{
				// If removeAt != -1, the value to remove is not taken into account anymore.
				// Instead, the value at index = removeAt is removed
				// NOTE: removeAt is 1-based rather than 0-based
				
				if(removeAt == 1)
				{
					m_base_NamedElement.reset();
					return true;
				}
			}
			else
			{
				if(m_base_NamedElement.lock() == valueToRemove)
				{
					m_base_NamedElement.reset();
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
std::shared_ptr<Any> NonExecutableImpl::invoke(const std::shared_ptr<uml::Operation>& _operation, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	return this->invoke(_operation->_getID(), inputArguments, outputArguments);
}

std::shared_ptr<Any> NonExecutableImpl::invoke(std::string _qualifiedName, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->invoke(uID, inputArguments, outputArguments);
}

std::shared_ptr<Any> NonExecutableImpl::invoke(unsigned long _uID, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	std::shared_ptr<Any> result = eAny(nullptr, -1, false);
	return result;
}

//OpaqueBehavior Invocation
std::shared_ptr<Any> NonExecutableImpl::invoke(const std::shared_ptr<uml::OpaqueBehavior>& _opaqueBehavior, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
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
