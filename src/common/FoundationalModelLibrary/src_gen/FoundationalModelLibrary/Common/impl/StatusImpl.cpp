#include "FoundationalModelLibrary/Common/impl/StatusImpl.hpp"

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
#include "FoundationalModelLibrary/Common/CommonFactory.hpp"
#include "FoundationalModelLibrary/Common/impl/CommonPackageImpl.hpp"
#include "uml/DataType.hpp"

//Package for used PrimitiveTypes
#include "types/typesPackage.hpp"

using namespace FoundationalModelLibrary::Common;

//*********************************
// Constructor / Destructor
//*********************************
StatusImpl::StatusImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_INFO("Instance of 'Status' is created.")
	//***********************************
}

StatusImpl::~StatusImpl()
{
	DEBUG_INFO("Instance of 'Status' is destroyed.")
}

StatusImpl::StatusImpl(const StatusImpl & obj):StatusImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  StatusImpl::copy() const
{
	std::shared_ptr<StatusImpl> element(new StatusImpl());
	*element=(*this);
	return element;
}

StatusImpl& StatusImpl::operator=(const StatusImpl & obj)
{
	//call overloaded =Operator for each base class
	uml::ElementImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Status "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy attributes with no containment (soft copy)
	m_code = obj.getCode();
	m_context = obj.getContext();
	m_description = obj.getDescription();

	//clone attributes with containment (deep copy)

	return *this;
}


//*********************************
// Attribute Setter Getter
//*********************************
void StatusImpl::setCode(int _code)
{
	m_code = _code;
	
}
int StatusImpl::getCode() const 
{

	return m_code;
}

void StatusImpl::setContext(std::string _context)
{
	m_context = _context;
	
}
std::string StatusImpl::getContext() const 
{

	return m_context;
}

void StatusImpl::setDescription(std::string _description)
{
	m_description = _description;
	
}
std::string StatusImpl::getDescription() const 
{

	return m_description;
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
std::shared_ptr<Any> StatusImpl::get(std::shared_ptr<uml::Property> _property) const
{
	return this->get(_property->_getID());
}

std::shared_ptr<Any> StatusImpl::get(std::string _qualifiedName) const
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->get(uID);
}

std::shared_ptr<Any> StatusImpl::get(unsigned long _uID) const
{
	switch(_uID)
	{
		case FoundationalModelLibrary::Common::CommonPackage::STATUS_PROPERTY_CODE:
			return eAny(this->getCode(), types::typesPackage::INTEGER_CLASS, false);
		case FoundationalModelLibrary::Common::CommonPackage::STATUS_PROPERTY_CONTEXT:
			return eAny(this->getContext(), types::typesPackage::STRING_CLASS, false);
		case FoundationalModelLibrary::Common::CommonPackage::STATUS_PROPERTY_DESCRIPTION:
			return eAny(this->getDescription(), types::typesPackage::STRING_CLASS, false);
	}

	return eAny(nullptr, -1, false);
}

//Set
void StatusImpl::set(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value)
{
	this->set(_property->_getID(), value);
}

void StatusImpl::set(std::string _qualifiedName,const std::shared_ptr<Any>& value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->set(uID, value);
}

void StatusImpl::set(unsigned long _uID, const std::shared_ptr<Any>& value)
{
	switch(_uID)
	{
		case FoundationalModelLibrary::Common::CommonPackage::STATUS_PROPERTY_CODE:
		{
			try
			{
				int _code = value->get<int>();
				setCode(_code);
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for property 'code'. Failed to set property!")
				return;
			}
		break;
		}
		case FoundationalModelLibrary::Common::CommonPackage::STATUS_PROPERTY_CONTEXT:
		{
			try
			{
				std::string _context = value->get<std::string>();
				setContext(_context);
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for property 'context'. Failed to set property!")
				return;
			}
		break;
		}
		case FoundationalModelLibrary::Common::CommonPackage::STATUS_PROPERTY_DESCRIPTION:
		{
			try
			{
				std::string _description = value->get<std::string>();
				setDescription(_description);
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for property 'description'. Failed to set property!")
				return;
			}
		break;
		}
	}
}

//Add
void StatusImpl::add(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	this->add(_property->_getID(), value);
}

void StatusImpl::add(std::string _qualifiedName, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->add(uID, value);
}

void StatusImpl::add(unsigned long _uID, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
}

//Unset
void StatusImpl::unset(std::shared_ptr<uml::Property> _property)
{
	this->unset(_property->_getID());
}

void StatusImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->unset(uID);
}

void StatusImpl::unset(unsigned long _uID)
{
}

//Remove
void StatusImpl::remove(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value)
{
	this->remove(_property->_getID(), value);
}

void StatusImpl::remove(std::string _qualifiedName, const std::shared_ptr<Any>& value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->remove(uID, value);
}

void StatusImpl::remove(unsigned long _uID, const std::shared_ptr<Any>& value)
{
}

//**************************************
// Operation Invocation
//**************************************
//Operation Invocation
std::shared_ptr<Any> StatusImpl::invoke(const std::shared_ptr<uml::Operation>& _operation, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	return this->invoke(_operation->_getID(), inputArguments, outputArguments);
}

std::shared_ptr<Any> StatusImpl::invoke(std::string _qualifiedName, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->invoke(uID, inputArguments, outputArguments);
}

std::shared_ptr<Any> StatusImpl::invoke(unsigned long _uID, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	std::shared_ptr<Any> result = eAny(nullptr, -1, false);
	return result;
}

