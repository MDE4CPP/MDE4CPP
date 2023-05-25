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


std::shared_ptr<uml::Class> GetterNameImpl::getMetaClass() const
{
	return UML4CPPProfilePackageImpl::eInstance()->get_UML4CPPProfile_GetterName();
}

void GetterNameImpl::instantiate()
{   
	
	
}

void GetterNameImpl::destroy()
{	

	//Erase properties
	//deleting property base_Property
	m_base_Property.reset();
	
	
	//Erase back reference to owner
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

	return eAny(nullptr, -1, false);
}

//Set
void GetterNameImpl::set(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value)
{
	this->set(_property->_getID(), value);
}

void GetterNameImpl::set( std::string _qualifiedName, const std::shared_ptr<Any>& value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->set(uID, value);
}

void GetterNameImpl::set(unsigned long _uID, const std::shared_ptr<Any>& value)
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
					}			
					else
					{
						throw "Invalid argument";
					}		
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'uml::UMLAny' for property 'base_Property'. Failed to set property!")
					return;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'uml::UMLAny' for property 'base_Property'. Failed to set property!")
				return;
			}
		break;
		}
		case UML4CPPProfile::UML4CPPProfilePackage::GETTERNAME_PROPERTY_GETTERNAME:
		{
			try
			{
				std::string _getterName = value->get<std::string>();
				setGetterName(_getterName);
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for property 'getterName'. Failed to set property!")
				return;
			}
		break;
		}
	}
}

//Add
void GetterNameImpl::add(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	this->add(_property->_getID(), value);
}

void GetterNameImpl::add(std::string _qualifiedName, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->add(uID, value);
}

void GetterNameImpl::add(unsigned long _uID, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
}

//Unset
void GetterNameImpl::unset(const std::shared_ptr<uml::Property>& _property)
{
	this->unset(_property->_getID());
}

void GetterNameImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->unset(uID);
}

void GetterNameImpl::unset(unsigned long _uID)
{
	switch(_uID)
	{
		case UML4CPPProfile::UML4CPPProfilePackage::GETTERNAME_PROPERTY_BASE_PROPERTY:
		{
			m_base_Property.reset();
			return;
		}
	}

}

//Remove
void GetterNameImpl::remove(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value)
{
	this->remove(_property->_getID(), value);
}

void GetterNameImpl::remove(std::string _qualifiedName, const std::shared_ptr<Any>& value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->remove(uID, value);
}

void GetterNameImpl::remove(unsigned long _uID, const std::shared_ptr<Any>& value)
{
}

//**************************************
// Operation & OpaqueBehavior Invocation
//**************************************
//Operation Invocation
std::shared_ptr<Any> GetterNameImpl::invoke(const std::shared_ptr<uml::Operation>& _operation, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	return this->invoke(_operation->_getID(), inputArguments, outputArguments);
}

std::shared_ptr<Any> GetterNameImpl::invoke(std::string _qualifiedName, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->invoke(uID, inputArguments, outputArguments);
}

std::shared_ptr<Any> GetterNameImpl::invoke(unsigned long _uID, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	std::shared_ptr<Any> result = eAny(nullptr, -1, false);
	return result;
}

//OpaqueBehavior Invocation
std::shared_ptr<Any> GetterNameImpl::invoke(const std::shared_ptr<uml::OpaqueBehavior>& _opaqueBehavior, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	return eAny(nullptr, -1, false);
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
