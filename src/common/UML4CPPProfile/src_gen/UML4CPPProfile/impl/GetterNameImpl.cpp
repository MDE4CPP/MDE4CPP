#include "UML4CPPProfile/impl/GetterNameImpl.hpp"

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

//Package for used PrimitiveTypes
#include "types/typesPackage.hpp"

//Packages for used (non-primitive) Types
#include "uml/umlPackage.hpp"

//Used Types
#include "uml/Property.hpp"

//Packges and Factories included from types of attributes, operation parameters, imports and composite owner classes
#include "uml/umlFactory.hpp"
#include "uml/impl/umlPackageImpl.hpp"

using namespace UML4CPPProfile;

//*********************************
// Constructor / Destructor
//*********************************
GetterNameImpl::GetterNameImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_INFO("Instance of 'GetterName' is created.")
	//***********************************
}


GetterNameImpl::~GetterNameImpl()
{
	DEBUG_INFO("Instance of 'GetterName' is destroyed.")
}

GetterNameImpl::GetterNameImpl(const GetterNameImpl & obj):GetterNameImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  GetterNameImpl::copy() const
{
	std::shared_ptr<GetterNameImpl> element(new GetterNameImpl());
	*element=(*this);
	element->setThisGetterNamePtr(element);
	return element;
}

GetterNameImpl& GetterNameImpl::operator=(const GetterNameImpl & obj)
{
	//call overloaded =Operator for each base class
	uml::StereotypeImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy GetterName "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();

	//copy attributes with no containment (soft copy)
	m_base_Property = obj.getBase_Property();
	m_getterName = obj.getGetterName();

	//clone attributes with containment (deep copy)

	return *this;
}


const std::shared_ptr<uml::Class>& GetterNameImpl::getMetaClass() const
{
	static const std::shared_ptr<uml::Class> metaClass = UML4CPPProfilePackageImpl::eInstance()->get_UML4CPPProfile_GetterName();
	return metaClass;
}

void GetterNameImpl::instantiate()
{   
	
	
}

void GetterNameImpl::destroy()
{	

	//Erase properties	//deleting property base_Property
	m_base_Property.reset();
	
	
}

//*********************************
// Attribute Setter Getter
//*********************************
void GetterNameImpl::setBase_Property(std::weak_ptr<uml::Property> _base_Property)
{
	m_base_Property = _base_Property;
	
}
std::weak_ptr<uml::Property> GetterNameImpl::getBase_Property() const 
{

	return m_base_Property;
}

void GetterNameImpl::setGetterName(std::string _getterName)
{
	m_getterName = _getterName;
	
}
std::string GetterNameImpl::getGetterName() const 
{

	return m_getterName;
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
std::shared_ptr<Any> GetterNameImpl::get(const std::shared_ptr<uml::Property>& _property) const
{
	return this->get(_property->_getID());
}

std::shared_ptr<Any> GetterNameImpl::get(std::string _qualifiedName) const
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->get(uID);
}

std::shared_ptr<Any> GetterNameImpl::get(unsigned long _uID) const
{
	switch(_uID)
	{
		case UML4CPPProfile::UML4CPPProfilePackage::GETTERNAME_PROPERTY_BASE_PROPERTY:
			return eUMLAny(this->getBase_Property().lock(), uml::umlPackage::PROPERTY_CLASS);
		case UML4CPPProfile::UML4CPPProfilePackage::GETTERNAME_PROPERTY_GETTERNAME:
			return eAny(this->getGetterName(), types::typesPackage::STRING_CLASS, false);
	}

	return nullptr;
}

//Set
bool GetterNameImpl::set(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value)
{
	return this->set(_property->_getID(), value);
}

bool GetterNameImpl::set( std::string _qualifiedName, const std::shared_ptr<Any>& value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->set(uID, value);
}

bool GetterNameImpl::set(unsigned long _uID, const std::shared_ptr<Any>& value)
{
	switch(_uID)
	{
		case UML4CPPProfile::UML4CPPProfilePackage::GETTERNAME_PROPERTY_BASE_PROPERTY:
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
						return true;
					}			
					else
					{
						throw "Invalid argument";
					}		
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'uml::UMLAny' for property 'base_Property'. Failed to set property!")
					return true;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'uml::UMLAny' for property 'base_Property'. Failed to set property!")
				return true;
			}
		break;
		}
		case UML4CPPProfile::UML4CPPProfilePackage::GETTERNAME_PROPERTY_GETTERNAME:
		{
			try
			{
				std::string _getterName = value->get<std::string>();
				setGetterName(_getterName);
				return true;
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for property 'getterName'. Failed to set property!")
				return true;
			}
		break;
		}
	}
	return false;
}

//Add
bool GetterNameImpl::add(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	return this->add(_property->_getID(), value, insertAt);
}

bool GetterNameImpl::add(std::string _qualifiedName, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->add(uID, value, insertAt);
}

bool GetterNameImpl::add(unsigned long _uID, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	return false;
}

//Unset
bool GetterNameImpl::unset(const std::shared_ptr<uml::Property>& _property)
{
	return this->unset(_property->_getID());
}

bool GetterNameImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->unset(uID);
}

bool GetterNameImpl::unset(unsigned long _uID)
{
	switch(_uID)
	{
		case UML4CPPProfile::UML4CPPProfilePackage::GETTERNAME_PROPERTY_BASE_PROPERTY:
		{
			m_base_Property.reset();
			return true;
		}
		case UML4CPPProfile::UML4CPPProfilePackage::GETTERNAME_PROPERTY_GETTERNAME:
		{
			m_getterName = "";
			return true;
		}
	}

	return false;
}

//Remove
bool GetterNameImpl::remove(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	return this->remove(_property->_getID(), value, removeAt, isRemoveDuplicates);
}

bool GetterNameImpl::remove(std::string _qualifiedName, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->remove(uID, value, removeAt, isRemoveDuplicates);
}

bool GetterNameImpl::remove(unsigned long _uID, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	switch(_uID)
	{
		case UML4CPPProfile::UML4CPPProfilePackage::GETTERNAME_PROPERTY_BASE_PROPERTY:
		{
			std::shared_ptr<uml::Property> valueToRemove = nullptr;
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
						valueToRemove = std::dynamic_pointer_cast<uml::Property>(firstElement);
					}
				}
			}
			else
			{
				std::shared_ptr<uml::UMLAny> umlAny = std::dynamic_pointer_cast<uml::UMLAny>(value);
				if(umlAny)
				{
					std::shared_ptr<uml::Element> element = umlAny->getAsElement();
					valueToRemove = std::dynamic_pointer_cast<uml::Property>(element);
				}
			}

			
			if(removeAt >= 1 && !isRemoveDuplicates) // As per fUML-specification, if isRemoveDuplicates is true, removeAt is ignored
			{
				// If removeAt != -1, the value to remove is not taken into account anymore.
				// Instead, the value at index = removeAt is removed
				// NOTE: removeAt is 1-based rather than 0-based
				if(removeAt == 1)
				{
					m_base_Property.reset();
					return true;
				}
			}
			else
			{
				if(m_base_Property.lock() == valueToRemove)
				{
					m_base_Property.reset();
					return true;
				}
			}
		}
		case UML4CPPProfile::UML4CPPProfilePackage::GETTERNAME_PROPERTY_GETTERNAME:
		{
			std::string valueToRemove = "";
			if(value->isContainer())
			{
				std::shared_ptr<Bag<std::string>> container = value->get<std::shared_ptr<Bag<std::string>>>();
				if(container && !(container->empty()))
				{
						// If a non-empty container is passed, the first value of the container will be removed from the property
						valueToRemove = *(container->at(0));
				}
			}
			else
			{
				valueToRemove = value->get<std::string>();
			}

			
			if(removeAt >= 1 && !isRemoveDuplicates) // As per fUML-specification, if isRemoveDuplicates is true, removeAt is ignored
			{
				// If removeAt != -1, the value to remove is not taken into account anymore.
				// Instead, the value at index = removeAt is removed
				// NOTE: removeAt is 1-based rather than 0-based
				if(removeAt == 1)
				{
					m_getterName = "";
					return true;
				}
			}
			else
			{
				if(m_getterName == valueToRemove)
				{
					m_getterName = "";
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
std::shared_ptr<Any> GetterNameImpl::invoke(const std::shared_ptr<uml::Operation>& _operation, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	return this->invokeOperation(_operation->_getID(), inputArguments, outputArguments);
}

std::shared_ptr<Any> GetterNameImpl::invokeOperation(std::string _qualifiedName, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->invokeOperation(uID, inputArguments, outputArguments);
}

std::shared_ptr<Any> GetterNameImpl::invokeOperation(unsigned long _uID, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	std::shared_ptr<Any> result = nullptr;
	return result;
}

//OpaqueBehavior Invocation
std::shared_ptr<Any> GetterNameImpl::invoke(const std::shared_ptr<uml::OpaqueBehavior>& _opaqueBehavior, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	return this->invokeOpaqueBehavior(_opaqueBehavior->_getID(), inputArguments, outputArguments);
}

std::shared_ptr<Any> GetterNameImpl::invokeOpaqueBehavior(std::string _qualifiedName, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->invokeOpaqueBehavior(uID, inputArguments, outputArguments);
}

std::shared_ptr<Any> GetterNameImpl::invokeOpaqueBehavior(unsigned long _uID, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	return nullptr;
}

std::shared_ptr<GetterName> GetterNameImpl::getThisGetterNamePtr()
{
	return m_thisGetterNamePtr.lock();
}
void GetterNameImpl::setThisGetterNamePtr(std::weak_ptr<GetterName> thisGetterNamePtr)
{
	m_thisGetterNamePtr = thisGetterNamePtr;
	setThisStereotypePtr(thisGetterNamePtr);
}
