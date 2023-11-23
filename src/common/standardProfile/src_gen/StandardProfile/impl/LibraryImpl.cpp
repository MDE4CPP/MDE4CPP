#include "StandardProfile/impl/LibraryImpl.hpp"

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
#include "uml/Artifact.hpp"

//Packges and Factories included from types of attributes, operation parameters, imports and composite owner classes
#include "uml/umlFactory.hpp"
#include "uml/impl/umlPackageImpl.hpp"

using namespace StandardProfile;

//*********************************
// Constructor / Destructor
//*********************************
LibraryImpl::LibraryImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_INFO("Instance of 'Library' is created.")
	//***********************************
}


LibraryImpl::~LibraryImpl()
{
	DEBUG_INFO("Instance of 'Library' is destroyed.")
}

LibraryImpl::LibraryImpl(const LibraryImpl & obj):LibraryImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  LibraryImpl::copy() const
{
	std::shared_ptr<LibraryImpl> element(new LibraryImpl());
	*element=(*this);
	element->setThisLibraryPtr(element);
	return element;
}

LibraryImpl& LibraryImpl::operator=(const LibraryImpl & obj)
{
	//call overloaded =Operator for each base class
	FileImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Library "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();

	//copy attributes with no containment (soft copy)
	m_base_Artifact = obj.getBase_Artifact();

	//clone attributes with containment (deep copy)

	return *this;
}


const std::shared_ptr<uml::Class>& LibraryImpl::getMetaClass() const
{
	static const std::shared_ptr<uml::Class> metaClass = StandardProfilePackageImpl::eInstance()->get_StandardProfile_Library();
	return metaClass;
}

void LibraryImpl::instantiate()
{   
	FileImpl::instantiate();
	
}

void LibraryImpl::destroy()
{	

	//Erase properties	//deleting property base_Artifact
	m_base_Artifact.reset();
	
}

//*********************************
// Attribute Setter Getter
//*********************************
void LibraryImpl::setBase_Artifact(std::weak_ptr<uml::Artifact> _base_Artifact)
{
	m_base_Artifact = _base_Artifact;
	
}
std::weak_ptr<uml::Artifact> LibraryImpl::getBase_Artifact() const 
{

	return m_base_Artifact;
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
std::shared_ptr<Any> LibraryImpl::get(const std::shared_ptr<uml::Property>& _property) const
{
	return this->get(_property->_getID());
}

std::shared_ptr<Any> LibraryImpl::get(std::string _qualifiedName) const
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->get(uID);
}

std::shared_ptr<Any> LibraryImpl::get(unsigned long _uID) const
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::LIBRARY_PROPERTY_BASE_ARTIFACT:
			return eUMLAny(this->getBase_Artifact().lock(), uml::umlPackage::ARTIFACT_CLASS);
	}

	std::shared_ptr<Any> result;
	//Call get() for base class File
	result = StandardProfile::FileImpl::get(_uID);
	if (result != nullptr)
	{
		return result;
	}
	return result;
}

//Set
bool LibraryImpl::set(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value)
{
	return this->set(_property->_getID(), value);
}

bool LibraryImpl::set( std::string _qualifiedName, const std::shared_ptr<Any>& value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->set(uID, value);
}

bool LibraryImpl::set(unsigned long _uID, const std::shared_ptr<Any>& value)
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::LIBRARY_PROPERTY_BASE_ARTIFACT:
		{
			std::shared_ptr<uml::UMLAny> umlAny = std::dynamic_pointer_cast<uml::UMLAny>(value);
			if(umlAny)
			{
				try
				{
					std::shared_ptr<uml::Element> element = umlAny->getAsElement();
					std::shared_ptr<uml::Artifact> _base_Artifact = std::dynamic_pointer_cast<uml::Artifact>(umlAny);
					if(_base_Artifact)
					{
						setBase_Artifact(_base_Artifact);
						return true;
					}			
					else
					{
						throw "Invalid argument";
					}		
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'uml::UMLAny' for property 'base_Artifact'. Failed to set property!")
					return true;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'uml::UMLAny' for property 'base_Artifact'. Failed to set property!")
				return true;
			}
		break;
		}
	}
	//Call set() for base class File
	if(StandardProfile::FileImpl::set(_uID, value)) return true;
	return false;
}

//Add
bool LibraryImpl::add(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	return this->add(_property->_getID(), value, insertAt);
}

bool LibraryImpl::add(std::string _qualifiedName, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->add(uID, value, insertAt);
}

bool LibraryImpl::add(unsigned long _uID, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	//Call add() for base class File
	if(StandardProfile::FileImpl::add(_uID, value, insertAt)) return true;
	return false;
}

//Unset
bool LibraryImpl::unset(const std::shared_ptr<uml::Property>& _property)
{
	return this->unset(_property->_getID());
}

bool LibraryImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->unset(uID);
}

bool LibraryImpl::unset(unsigned long _uID)
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::LIBRARY_PROPERTY_BASE_ARTIFACT:
		{
			m_base_Artifact.reset();
			return true;
		}
	}

	//Call unset() for base class File
	if(StandardProfile::FileImpl::unset(_uID)) return true;
	return false;
}

//Remove
bool LibraryImpl::remove(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	return this->remove(_property->_getID(), value, removeAt);
}

bool LibraryImpl::remove(std::string _qualifiedName, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->remove(uID, value, removeAt);
}

bool LibraryImpl::remove(unsigned long _uID, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::LIBRARY_PROPERTY_BASE_ARTIFACT:
		{
			std::shared_ptr<uml::Artifact> valueToRemove = nullptr;
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
						valueToRemove = std::dynamic_pointer_cast<uml::Artifact>(firstElement);
					}
				}
			}
			else
			{
				std::shared_ptr<uml::UMLAny> umlAny = std::dynamic_pointer_cast<uml::UMLAny>(value);
				if(umlAny)
				{
					std::shared_ptr<uml::Element> element = umlAny->getAsElement();
					valueToRemove = std::dynamic_pointer_cast<uml::Artifact>(element);
				}
			}

			
			if(removeAt >= 1 && !isRemoveDuplicates) // As per fUML-specification, if isRemoveDuplicates is true, removeAt is ignored
			{
				// If removeAt != -1, the value to remove is not taken into account anymore.
				// Instead, the value at index = removeAt is removed
				// NOTE: removeAt is 1-based rather than 0-based
				
				if(removeAt == 1)
				{
					m_base_Artifact.reset();
					return true;
				}
			}
			else
			{
				if(m_base_Artifact.lock() == valueToRemove)
				{
					m_base_Artifact.reset();
					return true;
				}
			}
		}
	}

	//Call set() for base class File
	if(StandardProfile::FileImpl::remove(_uID, value)) return true;
	return false;
}

//**************************************
// Operation & OpaqueBehavior Invocation
//**************************************
//Operation Invocation
std::shared_ptr<Any> LibraryImpl::invoke(const std::shared_ptr<uml::Operation>& _operation, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	return this->invoke(_operation->_getID(), inputArguments, outputArguments);
}

std::shared_ptr<Any> LibraryImpl::invoke(std::string _qualifiedName, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->invoke(uID, inputArguments, outputArguments);
}

std::shared_ptr<Any> LibraryImpl::invoke(unsigned long _uID, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	std::shared_ptr<Any> result = eAny(nullptr, -1, false);
	//Call invoke() for base class File
	result = StandardProfile::FileImpl::invoke(_uID, inputArguments, outputArguments);
	if (result != nullptr)
	{
		return result;
	}
	return result;
}

//OpaqueBehavior Invocation
std::shared_ptr<Any> LibraryImpl::invoke(const std::shared_ptr<uml::OpaqueBehavior>& _opaqueBehavior, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	std::shared_ptr<Any> result;
	//Call invoke() for base class File
	result = StandardProfile::FileImpl::invoke(_opaqueBehavior, inputArguments, outputArguments);
	if (result != nullptr)
	{
		return result;
	}
	return result;
}

std::shared_ptr<Library> LibraryImpl::getThisLibraryPtr()
{
	return m_thisLibraryPtr.lock();
}
void LibraryImpl::setThisLibraryPtr(std::weak_ptr<Library> thisLibraryPtr)
{
	m_thisLibraryPtr = thisLibraryPtr;
	setThisFilePtr(thisLibraryPtr);
}
