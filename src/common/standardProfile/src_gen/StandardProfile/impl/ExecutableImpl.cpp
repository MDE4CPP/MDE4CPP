#include "StandardProfile/impl/ExecutableImpl.hpp"

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
ExecutableImpl::ExecutableImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_INFO("Instance of 'Executable' is created.")
	//***********************************
}


ExecutableImpl::~ExecutableImpl()
{
	DEBUG_INFO("Instance of 'Executable' is destroyed.")
}

ExecutableImpl::ExecutableImpl(const ExecutableImpl & obj):ExecutableImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  ExecutableImpl::copy() const
{
	std::shared_ptr<ExecutableImpl> element(new ExecutableImpl());
	*element=(*this);
	element->setThisExecutablePtr(element);
	return element;
}

ExecutableImpl& ExecutableImpl::operator=(const ExecutableImpl & obj)
{
	//call overloaded =Operator for each base class
	FileImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Executable "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();

	//copy attributes with no containment (soft copy)
	m_base_Artifact = obj.getBase_Artifact();

	//clone attributes with containment (deep copy)

	return *this;
}


const std::shared_ptr<uml::Class>& ExecutableImpl::getMetaClass() const
{
	static const std::shared_ptr<uml::Class> metaClass = StandardProfilePackageImpl::eInstance()->get_StandardProfile_Executable();
	return metaClass;
}

void ExecutableImpl::instantiate()
{   
	FileImpl::instantiate();
	
}

void ExecutableImpl::destroy()
{	

	//Erase properties	//deleting property base_Artifact
	m_base_Artifact.reset();
	
}

//*********************************
// Attribute Setter Getter
//*********************************
void ExecutableImpl::setBase_Artifact(std::weak_ptr<uml::Artifact> _base_Artifact)
{
	m_base_Artifact = _base_Artifact;
	
}
std::weak_ptr<uml::Artifact> ExecutableImpl::getBase_Artifact() const 
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
std::shared_ptr<Any> ExecutableImpl::get(const std::shared_ptr<uml::Property>& _property) const
{
	return this->get(_property->_getID());
}

std::shared_ptr<Any> ExecutableImpl::get(std::string _qualifiedName) const
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->get(uID);
}

std::shared_ptr<Any> ExecutableImpl::get(unsigned long _uID) const
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::EXECUTABLE_PROPERTY_BASE_ARTIFACT:
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
void ExecutableImpl::set(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value)
{
	this->set(_property->_getID(), value);
}

void ExecutableImpl::set( std::string _qualifiedName, const std::shared_ptr<Any>& value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->set(uID, value);
}

void ExecutableImpl::set(unsigned long _uID, const std::shared_ptr<Any>& value)
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::EXECUTABLE_PROPERTY_BASE_ARTIFACT:
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
					}			
					else
					{
						throw "Invalid argument";
					}		
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'uml::UMLAny' for property 'base_Artifact'. Failed to set property!")
					return;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'uml::UMLAny' for property 'base_Artifact'. Failed to set property!")
				return;
			}
		break;
		}
	}
	//Call set() for base class File
	StandardProfile::FileImpl::set(_uID, value);
}

//Add
void ExecutableImpl::add(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	this->add(_property->_getID(), value);
}

void ExecutableImpl::add(std::string _qualifiedName, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->add(uID, value);
}

void ExecutableImpl::add(unsigned long _uID, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	//Call set() for base class File
	StandardProfile::FileImpl::add(_uID, value, insertAt);
}

//Unset
void ExecutableImpl::unset(const std::shared_ptr<uml::Property>& _property)
{
	this->unset(_property->_getID());
}

void ExecutableImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->unset(uID);
}

void ExecutableImpl::unset(unsigned long _uID)
{
	switch(_uID)
	{
		case StandardProfile::StandardProfilePackage::EXECUTABLE_PROPERTY_BASE_ARTIFACT:
		{
			m_base_Artifact.reset();
			return;
		}
	}

	//Call unset() for base class File
	StandardProfile::FileImpl::unset(_uID);
}

//Remove
void ExecutableImpl::remove(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value)
{
	this->remove(_property->_getID(), value);
}

void ExecutableImpl::remove(std::string _qualifiedName, const std::shared_ptr<Any>& value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->remove(uID, value);
}

void ExecutableImpl::remove(unsigned long _uID, const std::shared_ptr<Any>& value)
{
	//Call set() for base class File
	StandardProfile::FileImpl::remove(_uID, value);
}

//**************************************
// Operation & OpaqueBehavior Invocation
//**************************************
//Operation Invocation
std::shared_ptr<Any> ExecutableImpl::invoke(const std::shared_ptr<uml::Operation>& _operation, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	return this->invoke(_operation->_getID(), inputArguments, outputArguments);
}

std::shared_ptr<Any> ExecutableImpl::invoke(std::string _qualifiedName, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->invoke(uID, inputArguments, outputArguments);
}

std::shared_ptr<Any> ExecutableImpl::invoke(unsigned long _uID, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
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
std::shared_ptr<Any> ExecutableImpl::invoke(const std::shared_ptr<uml::OpaqueBehavior>& _opaqueBehavior, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
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

std::shared_ptr<Executable> ExecutableImpl::getThisExecutablePtr()
{
	return m_thisExecutablePtr.lock();
}
void ExecutableImpl::setThisExecutablePtr(std::weak_ptr<Executable> thisExecutablePtr)
{
	m_thisExecutablePtr = thisExecutablePtr;
	setThisFilePtr(thisExecutablePtr);
}
