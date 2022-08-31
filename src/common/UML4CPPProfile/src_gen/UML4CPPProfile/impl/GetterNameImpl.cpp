#include "UML4CPPProfile/impl/GetterNameImpl.hpp"

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
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"
#include "uml/Property.hpp"

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
GetterNameImpl::GetterNameImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_MESSAGE(std::cout<<"GetterName is created..."<<std::endl;)
	//***********************************
}


GetterNameImpl::~GetterNameImpl()
{
	DEBUG_MESSAGE(std::cout<<"GetterName is destroyed..."<<std::endl;)
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

//*********************************
// Structural Feature Getter/Setter
//*********************************
//Get
std::shared_ptr<Any> GetterNameImpl::get(std::shared_ptr<uml::Property> _property) const
{
	std::string qualifiedName = _property->getQualifiedName();
	return this->get(qualifiedName);
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
		case UML4CPPProfile::UML4CPPProfilePackage::GETTERNAME_ATTRIBUTE_BASE_PROPERTY:
			return eUMLAny(this->getBase_Property().lock(), uml::umlPackage::PROPERTY_CLASS);
		case UML4CPPProfile::UML4CPPProfilePackage::GETTERNAME_ATTRIBUTE_GETTERNAME:
			return eAny(this->getGetterName(), types::typesPackage::STRING_CLASS, false);
	}

	return eAny(nullptr, -1, false);
}

//Set
void GetterNameImpl::set(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->set(qualifiedName, value);
}

void GetterNameImpl::set(std::string _qualifiedName, std::shared_ptr<Any> value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->set(uID, value);
}

void GetterNameImpl::set(unsigned long _uID, std::shared_ptr<Any> value)
{
	switch(_uID)
	{
		case UML4CPPProfile::UML4CPPProfilePackage::GETTERNAME_ATTRIBUTE_BASE_PROPERTY:
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
					DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'uml::UMLAny' for property 'base_Property'. Failed to set property!"<< std::endl;)
					return;
				}
			}
			else
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid instance of 'uml::UMLAny' for property 'base_Property'. Failed to set property!"<< std::endl;)
				return;
			}
		break;
		}
		case UML4CPPProfile::UML4CPPProfilePackage::GETTERNAME_ATTRIBUTE_GETTERNAME:
		{
			try
			{
				std::string _getterName = value->get<std::string>();
				setGetterName(_getterName);
			}
			catch(...)
			{
				DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << " : Invalid type stored in 'Any' for property 'getterName'. Failed to set property!"<< std::endl;)
				return;
			}
		break;
		}
	}
}

//Add
void GetterNameImpl::add(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->set(qualifiedName, value);
}

void GetterNameImpl::add(std::string _qualifiedName, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->set(uID, value);
}

void GetterNameImpl::add(unsigned long _uID, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
}

//Unset
void GetterNameImpl::unset(std::shared_ptr<uml::Property> _property)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->unset(qualifiedName);
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
		case UML4CPPProfile::UML4CPPProfilePackage::GETTERNAME_ATTRIBUTE_BASE_PROPERTY:
		{
			m_base_Property.reset();
			return;
		}
	}

}

//*********************************
// Operation Invoction
//*********************************
//Invoke
std::shared_ptr<Any> GetterNameImpl::invoke(std::shared_ptr<uml::Operation> _operation, std::shared_ptr<Bag<Any>> _arguments)
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

std::shared_ptr<Any> GetterNameImpl::invoke(std::string _qualifiedName, std::shared_ptr<Bag<Any>> _arguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->invoke(uID, _arguments);
}

std::shared_ptr<Any> GetterNameImpl::invoke(unsigned long _uID, std::shared_ptr<Bag<Any>> _arguments)
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
