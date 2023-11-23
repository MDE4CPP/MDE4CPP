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
#include "uml/Package.hpp"

//Packges and Factories included from types of attributes, operation parameters, imports and composite owner classes
#include "uml/umlFactory.hpp"
#include "uml/impl/umlPackageImpl.hpp"

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


const std::shared_ptr<uml::Class>& ExternalLibraryImpl::getMetaClass() const
{
	static const std::shared_ptr<uml::Class> metaClass = UML4CPPProfilePackageImpl::eInstance()->get_UML4CPPProfile_ExternalLibrary();
	return metaClass;
}

void ExternalLibraryImpl::instantiate()
{   
	
	
	
	
}

void ExternalLibraryImpl::destroy()
{	

	//Erase properties	//deleting property base_Package
	m_base_Package.reset();
	
	
	
	
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
//**************************************
// StructuralFeature Getter & Setter
//**************************************
//Get
std::shared_ptr<Any> ExternalLibraryImpl::get(const std::shared_ptr<uml::Property>& _property) const
{
	return this->get(_property->_getID());
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
		case UML4CPPProfile::UML4CPPProfilePackage::EXTERNALLIBRARY_PROPERTY_BASE_PACKAGE:
			return eUMLAny(this->getBase_Package().lock(), uml::umlPackage::PACKAGE_CLASS);
		case UML4CPPProfile::UML4CPPProfilePackage::EXTERNALLIBRARY_PROPERTY_INCLUDEPATH:
			return eAny(this->getIncludePath(), types::typesPackage::STRING_CLASS, false);
		case UML4CPPProfile::UML4CPPProfilePackage::EXTERNALLIBRARY_PROPERTY_LIBRARYNAME:
			return eAny(this->getLibraryName(), types::typesPackage::STRING_CLASS, false);
		case UML4CPPProfile::UML4CPPProfilePackage::EXTERNALLIBRARY_PROPERTY_LIBRARYPATH:
			return eAny(this->getLibraryPath(), types::typesPackage::STRING_CLASS, false);
	}

	return eAny(nullptr, -1, false);
}

//Set
bool ExternalLibraryImpl::set(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value)
{
	return this->set(_property->_getID(), value);
}

bool ExternalLibraryImpl::set( std::string _qualifiedName, const std::shared_ptr<Any>& value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->set(uID, value);
}

bool ExternalLibraryImpl::set(unsigned long _uID, const std::shared_ptr<Any>& value)
{
	switch(_uID)
	{
		case UML4CPPProfile::UML4CPPProfilePackage::EXTERNALLIBRARY_PROPERTY_BASE_PACKAGE:
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
						return true;
					}			
					else
					{
						throw "Invalid argument";
					}		
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'uml::UMLAny' for property 'base_Package'. Failed to set property!")
					return true;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'uml::UMLAny' for property 'base_Package'. Failed to set property!")
				return true;
			}
		break;
		}
		case UML4CPPProfile::UML4CPPProfilePackage::EXTERNALLIBRARY_PROPERTY_INCLUDEPATH:
		{
			try
			{
				std::string _includePath = value->get<std::string>();
				setIncludePath(_includePath);
				return true;
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for property 'includePath'. Failed to set property!")
				return true;
			}
		break;
		}
		case UML4CPPProfile::UML4CPPProfilePackage::EXTERNALLIBRARY_PROPERTY_LIBRARYNAME:
		{
			try
			{
				std::string _libraryName = value->get<std::string>();
				setLibraryName(_libraryName);
				return true;
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for property 'libraryName'. Failed to set property!")
				return true;
			}
		break;
		}
		case UML4CPPProfile::UML4CPPProfilePackage::EXTERNALLIBRARY_PROPERTY_LIBRARYPATH:
		{
			try
			{
				std::string _libraryPath = value->get<std::string>();
				setLibraryPath(_libraryPath);
				return true;
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for property 'libraryPath'. Failed to set property!")
				return true;
			}
		break;
		}
	}
	return false;
}

//Add
bool ExternalLibraryImpl::add(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	return this->add(_property->_getID(), value, insertAt);
}

bool ExternalLibraryImpl::add(std::string _qualifiedName, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->add(uID, value, insertAt);
}

bool ExternalLibraryImpl::add(unsigned long _uID, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	return false;
}

//Unset
bool ExternalLibraryImpl::unset(const std::shared_ptr<uml::Property>& _property)
{
	return this->unset(_property->_getID());
}

bool ExternalLibraryImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->unset(uID);
}

bool ExternalLibraryImpl::unset(unsigned long _uID)
{
	switch(_uID)
	{
		case UML4CPPProfile::UML4CPPProfilePackage::EXTERNALLIBRARY_PROPERTY_BASE_PACKAGE:
		{
			m_base_Package.reset();
			return true;
		}
		case UML4CPPProfile::UML4CPPProfilePackage::EXTERNALLIBRARY_PROPERTY_INCLUDEPATH:
		{
			m_includePath = "";
			return true;
		}
		case UML4CPPProfile::UML4CPPProfilePackage::EXTERNALLIBRARY_PROPERTY_LIBRARYNAME:
		{
			m_libraryName = "";
			return true;
		}
		case UML4CPPProfile::UML4CPPProfilePackage::EXTERNALLIBRARY_PROPERTY_LIBRARYPATH:
		{
			m_libraryPath = "";
			return true;
		}
	}

	return false;
}

//Remove
bool ExternalLibraryImpl::remove(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	return this->remove(_property->_getID(), value, removeAt);
}

bool ExternalLibraryImpl::remove(std::string _qualifiedName, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->remove(uID, value, removeAt);
}

bool ExternalLibraryImpl::remove(unsigned long _uID, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	switch(_uID)
	{
		case UML4CPPProfile::UML4CPPProfilePackage::EXTERNALLIBRARY_PROPERTY_BASE_PACKAGE:
		{
			std::shared_ptr<uml::Package> valueToRemove = nullptr;
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
						valueToRemove = std::dynamic_pointer_cast<uml::Package>(firstElement);
					}
				}
			}
			else
			{
				std::shared_ptr<uml::UMLAny> umlAny = std::dynamic_pointer_cast<uml::UMLAny>(value);
				if(umlAny)
				{
					std::shared_ptr<uml::Element> element = umlAny->getAsElement();
					valueToRemove = std::dynamic_pointer_cast<uml::Package>(element);
				}
			}

			
			if(removeAt >= 1 && !isRemoveDuplicates) // As per fUML-specification, if isRemoveDuplicates is true, removeAt is ignored
			{
				// If removeAt != -1, the value to remove is not taken into account anymore.
				// Instead, the value at index = removeAt is removed
				// NOTE: removeAt is 1-based rather than 0-based
				
				if(removeAt == 1)
				{
					m_base_Package.reset();
					return true;
				}
			}
			else
			{
				if(m_base_Package.lock() == valueToRemove)
				{
					m_base_Package.reset();
					return true;
				}
			}
		}
		case UML4CPPProfile::UML4CPPProfilePackage::EXTERNALLIBRARY_PROPERTY_INCLUDEPATH:
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
					m_includePath = "";
					return true;
				}
			}
			else
			{
				if(m_includePath == valueToRemove)
				{
					m_includePath = "";
					return true;
				}
			}
		}
		case UML4CPPProfile::UML4CPPProfilePackage::EXTERNALLIBRARY_PROPERTY_LIBRARYNAME:
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
					m_libraryName = "";
					return true;
				}
			}
			else
			{
				if(m_libraryName == valueToRemove)
				{
					m_libraryName = "";
					return true;
				}
			}
		}
		case UML4CPPProfile::UML4CPPProfilePackage::EXTERNALLIBRARY_PROPERTY_LIBRARYPATH:
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
					m_libraryPath = "";
					return true;
				}
			}
			else
			{
				if(m_libraryPath == valueToRemove)
				{
					m_libraryPath = "";
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
std::shared_ptr<Any> ExternalLibraryImpl::invoke(const std::shared_ptr<uml::Operation>& _operation, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	return this->invoke(_operation->_getID(), inputArguments, outputArguments);
}

std::shared_ptr<Any> ExternalLibraryImpl::invoke(std::string _qualifiedName, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->invoke(uID, inputArguments, outputArguments);
}

std::shared_ptr<Any> ExternalLibraryImpl::invoke(unsigned long _uID, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	std::shared_ptr<Any> result = eAny(nullptr, -1, false);
	return result;
}

//OpaqueBehavior Invocation
std::shared_ptr<Any> ExternalLibraryImpl::invoke(const std::shared_ptr<uml::OpaqueBehavior>& _opaqueBehavior, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
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
