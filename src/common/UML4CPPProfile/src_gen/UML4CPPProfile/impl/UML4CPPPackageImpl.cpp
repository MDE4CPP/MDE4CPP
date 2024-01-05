#include "UML4CPPProfile/impl/UML4CPPPackageImpl.hpp"

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
UML4CPPPackageImpl::UML4CPPPackageImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_INFO("Instance of 'UML4CPPPackage' is created.")
	//***********************************
}


UML4CPPPackageImpl::~UML4CPPPackageImpl()
{
	DEBUG_INFO("Instance of 'UML4CPPPackage' is destroyed.")
}

UML4CPPPackageImpl::UML4CPPPackageImpl(const UML4CPPPackageImpl & obj):UML4CPPPackageImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  UML4CPPPackageImpl::copy() const
{
	std::shared_ptr<UML4CPPPackageImpl> element(new UML4CPPPackageImpl());
	*element=(*this);
	element->setThisUML4CPPPackagePtr(element);
	return element;
}

UML4CPPPackageImpl& UML4CPPPackageImpl::operator=(const UML4CPPPackageImpl & obj)
{
	//call overloaded =Operator for each base class
	uml::StereotypeImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy UML4CPPPackage "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();

	//copy attributes with no containment (soft copy)
	m_base_Package = obj.getBase_Package();
	m_eclipseURI = obj.getEclipseURI();
	m_ignoreNamespace = obj.isIgnoreNamespace();
	m_packageOnly = obj.isPackageOnly();

	//clone attributes with containment (deep copy)

	return *this;
}


const std::shared_ptr<uml::Class>& UML4CPPPackageImpl::getMetaClass() const
{
	static const std::shared_ptr<uml::Class> metaClass = UML4CPPProfilePackageImpl::eInstance()->get_UML4CPPProfile_UML4CPPPackage();
	return metaClass;
}

void UML4CPPPackageImpl::instantiate()
{   
	
	
}

void UML4CPPPackageImpl::destroy()
{	

	//Erase properties	//deleting property base_Package
	m_base_Package.reset();
	
	
	
	
}

//*********************************
// Attribute Setter Getter
//*********************************
void UML4CPPPackageImpl::setBase_Package(std::weak_ptr<uml::Package> _base_Package)
{
	m_base_Package = _base_Package;
	
}
std::weak_ptr<uml::Package> UML4CPPPackageImpl::getBase_Package() const 
{

	return m_base_Package;
}

void UML4CPPPackageImpl::setEclipseURI(std::string _eclipseURI)
{
	m_eclipseURI = _eclipseURI;
	
}
std::string UML4CPPPackageImpl::getEclipseURI() const 
{

	return m_eclipseURI;
}

void UML4CPPPackageImpl::setIgnoreNamespace(bool _ignoreNamespace)
{
	m_ignoreNamespace = _ignoreNamespace;
	
}
bool UML4CPPPackageImpl::isIgnoreNamespace() const 
{

	return m_ignoreNamespace;
}

void UML4CPPPackageImpl::setPackageOnly(bool _packageOnly)
{
	m_packageOnly = _packageOnly;
	
}
bool UML4CPPPackageImpl::isPackageOnly() const 
{

	return m_packageOnly;
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
std::shared_ptr<Any> UML4CPPPackageImpl::get(const std::shared_ptr<uml::Property>& _property) const
{
	return this->get(_property->_getID());
}

std::shared_ptr<Any> UML4CPPPackageImpl::get(std::string _qualifiedName) const
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->get(uID);
}

std::shared_ptr<Any> UML4CPPPackageImpl::get(unsigned long _uID) const
{
	switch(_uID)
	{
		case UML4CPPProfile::UML4CPPProfilePackage::UML4CPPPACKAGE_PROPERTY_BASE_PACKAGE:
			return eUMLAny(this->getBase_Package().lock(), uml::umlPackage::PACKAGE_CLASS);
		case UML4CPPProfile::UML4CPPProfilePackage::UML4CPPPACKAGE_PROPERTY_ECLIPSEURI:
			return eAny(this->getEclipseURI(), types::typesPackage::STRING_CLASS, false);
		case UML4CPPProfile::UML4CPPProfilePackage::UML4CPPPACKAGE_PROPERTY_IGNORENAMESPACE:
			return eAny(this->isIgnoreNamespace(), types::typesPackage::BOOLEAN_CLASS, false);
		case UML4CPPProfile::UML4CPPProfilePackage::UML4CPPPACKAGE_PROPERTY_PACKAGEONLY:
			return eAny(this->isPackageOnly(), types::typesPackage::BOOLEAN_CLASS, false);
	}

	return nullptr;
}

//Set
bool UML4CPPPackageImpl::set(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value)
{
	return this->set(_property->_getID(), value);
}

bool UML4CPPPackageImpl::set( std::string _qualifiedName, const std::shared_ptr<Any>& value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->set(uID, value);
}

bool UML4CPPPackageImpl::set(unsigned long _uID, const std::shared_ptr<Any>& value)
{
	switch(_uID)
	{
		case UML4CPPProfile::UML4CPPProfilePackage::UML4CPPPACKAGE_PROPERTY_BASE_PACKAGE:
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
		case UML4CPPProfile::UML4CPPProfilePackage::UML4CPPPACKAGE_PROPERTY_ECLIPSEURI:
		{
			try
			{
				std::string _eclipseURI = value->get<std::string>();
				setEclipseURI(_eclipseURI);
				return true;
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for property 'eclipseURI'. Failed to set property!")
				return true;
			}
		break;
		}
		case UML4CPPProfile::UML4CPPProfilePackage::UML4CPPPACKAGE_PROPERTY_IGNORENAMESPACE:
		{
			try
			{
				bool _ignoreNamespace = value->get<bool>();
				setIgnoreNamespace(_ignoreNamespace);
				return true;
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for property 'ignoreNamespace'. Failed to set property!")
				return true;
			}
		break;
		}
		case UML4CPPProfile::UML4CPPProfilePackage::UML4CPPPACKAGE_PROPERTY_PACKAGEONLY:
		{
			try
			{
				bool _packageOnly = value->get<bool>();
				setPackageOnly(_packageOnly);
				return true;
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for property 'packageOnly'. Failed to set property!")
				return true;
			}
		break;
		}
	}
	return false;
}

//Add
bool UML4CPPPackageImpl::add(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	return this->add(_property->_getID(), value, insertAt);
}

bool UML4CPPPackageImpl::add(std::string _qualifiedName, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->add(uID, value, insertAt);
}

bool UML4CPPPackageImpl::add(unsigned long _uID, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	return false;
}

//Unset
bool UML4CPPPackageImpl::unset(const std::shared_ptr<uml::Property>& _property)
{
	return this->unset(_property->_getID());
}

bool UML4CPPPackageImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->unset(uID);
}

bool UML4CPPPackageImpl::unset(unsigned long _uID)
{
	switch(_uID)
	{
		case UML4CPPProfile::UML4CPPProfilePackage::UML4CPPPACKAGE_PROPERTY_BASE_PACKAGE:
		{
			m_base_Package.reset();
			return true;
		}
		case UML4CPPProfile::UML4CPPProfilePackage::UML4CPPPACKAGE_PROPERTY_ECLIPSEURI:
		{
			m_eclipseURI = "";
			return true;
		}
		case UML4CPPProfile::UML4CPPProfilePackage::UML4CPPPACKAGE_PROPERTY_IGNORENAMESPACE:
		{
			m_ignoreNamespace = false;
			return true;
		}
		case UML4CPPProfile::UML4CPPProfilePackage::UML4CPPPACKAGE_PROPERTY_PACKAGEONLY:
		{
			m_packageOnly = false;
			return true;
		}
	}

	return false;
}

//Remove
bool UML4CPPPackageImpl::remove(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	return this->remove(_property->_getID(), value, removeAt, isRemoveDuplicates);
}

bool UML4CPPPackageImpl::remove(std::string _qualifiedName, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->remove(uID, value, removeAt, isRemoveDuplicates);
}

bool UML4CPPPackageImpl::remove(unsigned long _uID, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	switch(_uID)
	{
		case UML4CPPProfile::UML4CPPProfilePackage::UML4CPPPACKAGE_PROPERTY_BASE_PACKAGE:
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
		case UML4CPPProfile::UML4CPPProfilePackage::UML4CPPPACKAGE_PROPERTY_ECLIPSEURI:
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
					m_eclipseURI = "";
					return true;
				}
			}
			else
			{
				if(m_eclipseURI == valueToRemove)
				{
					m_eclipseURI = "";
					return true;
				}
			}
		}
		case UML4CPPProfile::UML4CPPProfilePackage::UML4CPPPACKAGE_PROPERTY_IGNORENAMESPACE:
		{
			bool valueToRemove = false;
			if(value->isContainer())
			{
				std::shared_ptr<Bag<bool>> container = value->get<std::shared_ptr<Bag<bool>>>();
				if(container && !(container->empty()))
				{
						// If a non-empty container is passed, the first value of the container will be removed from the property
						valueToRemove = *(container->at(0));
				}
			}
			else
			{
				valueToRemove = value->get<bool>();
			}

			
			if(removeAt >= 1 && !isRemoveDuplicates) // As per fUML-specification, if isRemoveDuplicates is true, removeAt is ignored
			{
				// If removeAt != -1, the value to remove is not taken into account anymore.
				// Instead, the value at index = removeAt is removed
				// NOTE: removeAt is 1-based rather than 0-based
				if(removeAt == 1)
				{
					m_ignoreNamespace = false;
					return true;
				}
			}
			else
			{
				if(m_ignoreNamespace == valueToRemove)
				{
					m_ignoreNamespace = false;
					return true;
				}
			}
		}
		case UML4CPPProfile::UML4CPPProfilePackage::UML4CPPPACKAGE_PROPERTY_PACKAGEONLY:
		{
			bool valueToRemove = false;
			if(value->isContainer())
			{
				std::shared_ptr<Bag<bool>> container = value->get<std::shared_ptr<Bag<bool>>>();
				if(container && !(container->empty()))
				{
						// If a non-empty container is passed, the first value of the container will be removed from the property
						valueToRemove = *(container->at(0));
				}
			}
			else
			{
				valueToRemove = value->get<bool>();
			}

			
			if(removeAt >= 1 && !isRemoveDuplicates) // As per fUML-specification, if isRemoveDuplicates is true, removeAt is ignored
			{
				// If removeAt != -1, the value to remove is not taken into account anymore.
				// Instead, the value at index = removeAt is removed
				// NOTE: removeAt is 1-based rather than 0-based
				if(removeAt == 1)
				{
					m_packageOnly = false;
					return true;
				}
			}
			else
			{
				if(m_packageOnly == valueToRemove)
				{
					m_packageOnly = false;
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
std::shared_ptr<Any> UML4CPPPackageImpl::invoke(const std::shared_ptr<uml::Operation>& _operation, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	return this->invokeOperation(_operation->_getID(), inputArguments, outputArguments);
}

std::shared_ptr<Any> UML4CPPPackageImpl::invokeOperation(std::string _qualifiedName, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->invokeOperation(uID, inputArguments, outputArguments);
}

std::shared_ptr<Any> UML4CPPPackageImpl::invokeOperation(unsigned long _uID, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	std::shared_ptr<Any> result = nullptr;
	return result;
}

//OpaqueBehavior Invocation
std::shared_ptr<Any> UML4CPPPackageImpl::invoke(const std::shared_ptr<uml::OpaqueBehavior>& _opaqueBehavior, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	return this->invokeOpaqueBehavior(_opaqueBehavior->_getID(), inputArguments, outputArguments);
}

std::shared_ptr<Any> UML4CPPPackageImpl::invokeOpaqueBehavior(std::string _qualifiedName, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->invokeOpaqueBehavior(uID, inputArguments, outputArguments);
}

std::shared_ptr<Any> UML4CPPPackageImpl::invokeOpaqueBehavior(unsigned long _uID, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	return nullptr;
}

std::shared_ptr<UML4CPPPackage> UML4CPPPackageImpl::getThisUML4CPPPackagePtr()
{
	return m_thisUML4CPPPackagePtr.lock();
}
void UML4CPPPackageImpl::setThisUML4CPPPackagePtr(std::weak_ptr<UML4CPPPackage> thisUML4CPPPackagePtr)
{
	m_thisUML4CPPPackagePtr = thisUML4CPPPackagePtr;
	setThisStereotypePtr(thisUML4CPPPackagePtr);
}
