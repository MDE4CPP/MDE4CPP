#include "UML4CPPProfile/impl/ExternalLibraryImpl.hpp"

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
#include "UML4CPPProfile/UML4CPPProfileFactory.hpp"
#include "UML4CPPProfile/impl/UML4CPPProfilePackageImpl.hpp"
#include "uml/Stereotype.hpp"

//Types included from attributes, operation parameters, imports and composite owner classes
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"
#include "uml/Package.hpp"

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
ExternalLibraryImpl::ExternalLibraryImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_INFO("Instance of 'ExternalLibrary' is created.")
	//***********************************
}


ExternalLibraryImpl::~ExternalLibraryImpl()
{
	DEBUG_INFO("Instance of 'ExternalLibrary' is destroyed.")
}

ExternalLibraryImpl::ExternalLibraryImpl(const ExternalLibraryImpl & obj):ExternalLibraryImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  ExternalLibraryImpl::copy() const
{
	std::shared_ptr<ExternalLibraryImpl> element(new ExternalLibraryImpl());
	*element=(*this);
	element->setThisExternalLibraryPtr(element);
	return element;
}

ExternalLibraryImpl& ExternalLibraryImpl::operator=(const ExternalLibraryImpl & obj)
{
	//call overloaded =Operator for each base class
	uml::StereotypeImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExternalLibrary "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();

	//copy attributes with no containment (soft copy)
	m_base_Package = obj.getBase_Package();
	m_includePath = obj.getIncludePath();
	m_libraryName = obj.getLibraryName();
	m_libraryPath = obj.getLibraryPath();

	//clone attributes with containment (deep copy)

	return *this;
}


std::shared_ptr<uml::Class> ExternalLibraryImpl::getMetaClass() const
{
	return UML4CPPProfilePackageImpl::eInstance()->get_UML4CPPProfile_ExternalLibrary();
}

void ExternalLibraryImpl::instantiate()
{   
	
	
	
	
}

void ExternalLibraryImpl::destroy()
{	

	//Erase properties
	//deleting property base_Package
	m_base_Package.reset();
	
	
	
	
	//Erase back reference to owner
}

//*********************************
// Attribute Setter Getter
//*********************************
void ExternalLibraryImpl::setBase_Package(std::weak_ptr<uml::Package> _base_Package)
{
	m_base_Package = _base_Package;
	
}
std::weak_ptr<uml::Package> ExternalLibraryImpl::getBase_Package() const 
{

	return m_base_Package;
}

void ExternalLibraryImpl::setIncludePath(std::string _includePath)
{
	m_includePath = _includePath;
	
}
std::string ExternalLibraryImpl::getIncludePath() const 
{

	return m_includePath;
}

void ExternalLibraryImpl::setLibraryName(std::string _libraryName)
{
	m_libraryName = _libraryName;
	
}
std::string ExternalLibraryImpl::getLibraryName() const 
{

	return m_libraryName;
}

void ExternalLibraryImpl::setLibraryPath(std::string _libraryPath)
{
	m_libraryPath = _libraryPath;
	
}
std::string ExternalLibraryImpl::getLibraryPath() const 
{

	return m_libraryPath;
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
std::shared_ptr<Any> ExternalLibraryImpl::get(std::shared_ptr<uml::Property> _property) const
{
	std::string qualifiedName = _property->getQualifiedName();
	return this->get(qualifiedName);
}

std::shared_ptr<Any> ExternalLibraryImpl::get(std::string _qualifiedName) const
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->get(uID);
}

std::shared_ptr<Any> ExternalLibraryImpl::get(unsigned long _uID) const
{
	switch(_uID)
	{
		case UML4CPPProfile::UML4CPPProfilePackage::EXTERNALLIBRARY_ATTRIBUTE_BASE_PACKAGE:
			return eUMLAny(this->getBase_Package().lock(), uml::umlPackage::PACKAGE_CLASS);
		case UML4CPPProfile::UML4CPPProfilePackage::EXTERNALLIBRARY_ATTRIBUTE_INCLUDEPATH:
			return eAny(this->getIncludePath(), types::typesPackage::STRING_CLASS, false);
		case UML4CPPProfile::UML4CPPProfilePackage::EXTERNALLIBRARY_ATTRIBUTE_LIBRARYNAME:
			return eAny(this->getLibraryName(), types::typesPackage::STRING_CLASS, false);
		case UML4CPPProfile::UML4CPPProfilePackage::EXTERNALLIBRARY_ATTRIBUTE_LIBRARYPATH:
			return eAny(this->getLibraryPath(), types::typesPackage::STRING_CLASS, false);
	}

	return eAny(nullptr, -1, false);
}

//Set
void ExternalLibraryImpl::set(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->set(qualifiedName, value);
}

void ExternalLibraryImpl::set(std::string _qualifiedName, std::shared_ptr<Any> value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->set(uID, value);
}

void ExternalLibraryImpl::set(unsigned long _uID, std::shared_ptr<Any> value)
{
	switch(_uID)
	{
		case UML4CPPProfile::UML4CPPProfilePackage::EXTERNALLIBRARY_ATTRIBUTE_BASE_PACKAGE:
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
		case UML4CPPProfile::UML4CPPProfilePackage::EXTERNALLIBRARY_ATTRIBUTE_INCLUDEPATH:
		{
			try
			{
				std::string _includePath = value->get<std::string>();
				setIncludePath(_includePath);
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for property 'includePath'. Failed to set property!")
				return;
			}
		break;
		}
		case UML4CPPProfile::UML4CPPProfilePackage::EXTERNALLIBRARY_ATTRIBUTE_LIBRARYNAME:
		{
			try
			{
				std::string _libraryName = value->get<std::string>();
				setLibraryName(_libraryName);
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for property 'libraryName'. Failed to set property!")
				return;
			}
		break;
		}
		case UML4CPPProfile::UML4CPPProfilePackage::EXTERNALLIBRARY_ATTRIBUTE_LIBRARYPATH:
		{
			try
			{
				std::string _libraryPath = value->get<std::string>();
				setLibraryPath(_libraryPath);
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for property 'libraryPath'. Failed to set property!")
				return;
			}
		break;
		}
	}
}

//Add
void ExternalLibraryImpl::add(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->add(qualifiedName, value);
}

void ExternalLibraryImpl::add(std::string _qualifiedName, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->add(uID, value);
}

void ExternalLibraryImpl::add(unsigned long _uID, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
}

//Unset
void ExternalLibraryImpl::unset(std::shared_ptr<uml::Property> _property)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->unset(qualifiedName);
}

void ExternalLibraryImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->unset(uID);
}

void ExternalLibraryImpl::unset(unsigned long _uID)
{
	switch(_uID)
	{
		case UML4CPPProfile::UML4CPPProfilePackage::EXTERNALLIBRARY_ATTRIBUTE_BASE_PACKAGE:
		{
			m_base_Package.reset();
			return;
		}
	}

}

//Remove
void ExternalLibraryImpl::remove(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value)
{
	std::string qualifiedName = _property->getQualifiedName();
	this->remove(qualifiedName, value);
}

void ExternalLibraryImpl::remove(std::string _qualifiedName, std::shared_ptr<Any> value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->remove(uID, value);
}

void ExternalLibraryImpl::remove(unsigned long _uID, std::shared_ptr<Any> value)
{
}

//*********************************
// Operation Invoction
//*********************************
//Invoke
std::shared_ptr<Any> ExternalLibraryImpl::invoke(std::shared_ptr<uml::Operation> _operation, std::shared_ptr<Bag<Any>> _arguments)
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

std::shared_ptr<Any> ExternalLibraryImpl::invoke(std::string _qualifiedName, std::shared_ptr<Bag<Any>> _arguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->invoke(uID, _arguments);
}

std::shared_ptr<Any> ExternalLibraryImpl::invoke(unsigned long _uID, std::shared_ptr<Bag<Any>> _arguments)
{
	return eAny(nullptr, -1, false);
}

std::shared_ptr<ExternalLibrary> ExternalLibraryImpl::getThisExternalLibraryPtr()
{
	return m_thisExternalLibraryPtr.lock();
}
void ExternalLibraryImpl::setThisExternalLibraryPtr(std::weak_ptr<ExternalLibrary> thisExternalLibraryPtr)
{
	m_thisExternalLibraryPtr = thisExternalLibraryPtr;
	setThisStereotypePtr(thisExternalLibraryPtr);
}
