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
std::shared_ptr<Any> StatusImpl::get(const std::shared_ptr<uml::Property>& _property) const
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

	return nullptr;
}

//Set
bool StatusImpl::set(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value)
{
	return this->set(_property->_getID(), value);
}

bool StatusImpl::set(std::string _qualifiedName,const std::shared_ptr<Any>& value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->set(uID, value);
}

bool StatusImpl::set(unsigned long _uID, const std::shared_ptr<Any>& value)
{
	switch(_uID)
	{
		case FoundationalModelLibrary::Common::CommonPackage::STATUS_PROPERTY_CODE:
		{
			try
			{
				int _code = value->get<int>();
				setCode(_code);
				return true;
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for property 'code'. Failed to set property!")
				return true;
			}
		break;
		}
		case FoundationalModelLibrary::Common::CommonPackage::STATUS_PROPERTY_CONTEXT:
		{
			try
			{
				std::string _context = value->get<std::string>();
				setContext(_context);
				return true;
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for property 'context'. Failed to set property!")
				return true;
			}
		break;
		}
		case FoundationalModelLibrary::Common::CommonPackage::STATUS_PROPERTY_DESCRIPTION:
		{
			try
			{
				std::string _description = value->get<std::string>();
				setDescription(_description);
				return true;
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for property 'description'. Failed to set property!")
				return true;
			}
		break;
		}
	}
	return false;
}

//Add
bool StatusImpl::add(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	return this->add(_property->_getID(), value);
}

bool StatusImpl::add(std::string _qualifiedName, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->add(uID, value);
}

bool StatusImpl::add(unsigned long _uID, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	return false;
}

//Unset
bool StatusImpl::unset(const std::shared_ptr<uml::Property>& _property)
{
	return this->unset(_property->_getID());
}

bool StatusImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->unset(uID);
}

bool StatusImpl::unset(unsigned long _uID)
{
	switch(_uID)
	{
		case FoundationalModelLibrary::Common::CommonPackage::STATUS_PROPERTY_CODE:
		{
			m_code = 0;
			return true;
		}
		case FoundationalModelLibrary::Common::CommonPackage::STATUS_PROPERTY_CONTEXT:
		{
			m_context = "";
			return true;
		}
		case FoundationalModelLibrary::Common::CommonPackage::STATUS_PROPERTY_DESCRIPTION:
		{
			m_description = "";
			return true;
		}
	}

	return false;
}

//Remove
bool StatusImpl::remove(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	return this->remove(_property->_getID(), value, removeAt, isRemoveDuplicates);
}

bool StatusImpl::remove(std::string _qualifiedName, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->remove(uID, value, removeAt, isRemoveDuplicates);
}

bool StatusImpl::remove(unsigned long _uID, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	switch(_uID)
	{
		case FoundationalModelLibrary::Common::CommonPackage::STATUS_PROPERTY_CODE:
		{
			int valueToRemove = 0;
			if(value->isContainer())
			{
				std::shared_ptr<Bag<int>> container = value->get<std::shared_ptr<Bag<int>>>();
				if(container && !(container->empty()))
				{
						// If a non-empty container is passed, the first value of the container will be removed from the property
						valueToRemove = *(container->at(0));
				}
			}
			else
			{
				valueToRemove = value->get<int>();
			}


			if(removeAt >= 1 && !isRemoveDuplicates) // As per fUML-specification, if isRemoveDuplicates is true, removeAt is ignored
			{
				// If removeAt != -1, the value to remove is not taken into account anymore.
				// Instead, the value at index = removeAt is removed
				// NOTE: removeAt is 1-based rather than 0-based
				if(removeAt == 1)
				{
					m_code = 0;
					return true;
				}
			}
			else
			{
				if(m_code == valueToRemove)
				{
					m_code = 0;
					return true;
				}
			}
		}
		case FoundationalModelLibrary::Common::CommonPackage::STATUS_PROPERTY_CONTEXT:
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
					m_context = "";
					return true;
				}
			}
			else
			{
				if(m_context == valueToRemove)
				{
					m_context = "";
					return true;
				}
			}
		}
		case FoundationalModelLibrary::Common::CommonPackage::STATUS_PROPERTY_DESCRIPTION:
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
					m_description = "";
					return true;
				}
			}
			else
			{
				if(m_description == valueToRemove)
				{
					m_description = "";
					return true;
				}
			}
		}
	}

	return false;
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

