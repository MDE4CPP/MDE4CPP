#include "FoundationalModelLibrary/BasicInputOutput/impl/ActiveChannelImpl.hpp"

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
#include "FoundationalModelLibrary/BasicInputOutput/BasicInputOutputFactory.hpp"
#include "FoundationalModelLibrary/BasicInputOutput/impl/BasicInputOutputPackageImpl.hpp"
#include "uml/Class.hpp"
//PSCS-specific includes
#include "fUML/Semantics/Loci/Locus.hpp"
#include "PSCS/MDE4CPP_Extensions/MDE4CPP_ExtensionsFactory.hpp"
#include "PSCS/MDE4CPP_Extensions/PSCS_Link.hpp"
#include "uml/Port.hpp"

using namespace FoundationalModelLibrary::BasicInputOutput;

//*********************************
// Constructor / Destructor
//*********************************
ActiveChannelImpl::ActiveChannelImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_INFO("Instance of 'ActiveChannel' is created.")
	//***********************************
}

ActiveChannelImpl::~ActiveChannelImpl()
{
	DEBUG_INFO("Instance of 'ActiveChannel' is destroyed.")
}

ActiveChannelImpl::ActiveChannelImpl(const ActiveChannelImpl & obj):ActiveChannelImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  ActiveChannelImpl::copy() const
{
	std::shared_ptr<ActiveChannelImpl> element(new ActiveChannelImpl());
	*element=(*this);
	element->setThisActiveChannelPtr(element);
	return element;
}

ActiveChannelImpl& ActiveChannelImpl::operator=(const ActiveChannelImpl & obj)
{
	//call overloaded =Operator for each base class
	ChannelImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ActiveChannel "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy attributes with no containment (soft copy)

	//clone attributes with containment (deep copy)

	return *this;
}

const std::shared_ptr<uml::Class>& ActiveChannelImpl::getMetaClass() const
{
	return BasicInputOutputPackageImpl::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_ActiveChannel();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Union Getter
//*********************************



//*********************************
// Operations
//*********************************

// fUML-specific Method Overrides
const std::shared_ptr<Bag<uml::Classifier>>& ActiveChannelImpl::getTypes() const
{
	static std::shared_ptr<Bag<uml::Classifier>> types;

	if(!types)
	{
		types.reset(new Bag<uml::Classifier>());
		// Add type of self 'ActiveChannel' : Class
		types->add(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_ActiveChannel());
		// Add base type 'Channel' : Class
		types->add(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_Channel());
	}

	return types;
}

void ActiveChannelImpl::destroy(bool isDestroyLinks, bool isDestroyOwnedObjects)
{
	fUML::MDE4CPP_Extensions::FUML_ObjectImpl::destroy(isDestroyLinks, isDestroyOwnedObjects);
}

// PSCS-specific Method Overrides
void ActiveChannelImpl::construct()
{
	ChannelImpl::construct();

}

void ActiveChannelImpl::constructObject(const std::shared_ptr<uml::Class>& type)
{
	switch(type->_getID())
	{
		case FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::ACTIVECHANNEL_CLASS:
		{
			this->construct();
			break;
		}
		case FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::CHANNEL_CLASS:
		{
			ChannelImpl::construct();
			break;
		}
		default:
		{
			return;
		}
	}
}

bool ActiveChannelImpl::contains(const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object>& object)
{
	/*
	 * TODO Avoid cycles here
	 */ 
	if(ChannelImpl::contains(object)) return true;

	return false;
}

bool ActiveChannelImpl::directlyContains(const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object>& object)
{
	if(ChannelImpl::directlyContains(object)) return true;

	return false;
}

std::shared_ptr<Any> ActiveChannelImpl::dispatchCallIn(const std::shared_ptr<uml::Operation>& _operation, const std::shared_ptr<uml::Port>& onPort, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Any> ActiveChannelImpl::dispatchCallOut(const std::shared_ptr<uml::Operation>& _operation, const std::shared_ptr<uml::Port>& onPort, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}
//**************************************
// StructuralFeature Getter & Setter
//**************************************
//Get
std::shared_ptr<Any> ActiveChannelImpl::get(const std::shared_ptr<uml::Property>& _property) const
{
	return this->get(_property->_getID());
}

std::shared_ptr<Any> ActiveChannelImpl::get(std::string _qualifiedName) const
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->get(uID);
}

std::shared_ptr<Any> ActiveChannelImpl::get(unsigned long _uID) const
{
	std::shared_ptr<Any> result;
	//Call get() for base class Channel
	result = FoundationalModelLibrary::BasicInputOutput::ChannelImpl::get(_uID);
	if (result != nullptr)
	{
		return result;
	}
	return result;
}

//Set
bool ActiveChannelImpl::set(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value)
{
	return this->set(_property->_getID(), value);
}

bool ActiveChannelImpl::set( std::string _qualifiedName, const std::shared_ptr<Any>& value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->set(uID, value);
}

bool ActiveChannelImpl::set(unsigned long _uID, const std::shared_ptr<Any>& value)
{
	//Call set() for base class Channel
	if(FoundationalModelLibrary::BasicInputOutput::ChannelImpl::set(_uID, value)) return true;
	return false;
}

//Add
bool ActiveChannelImpl::add(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	return this->add(_property->_getID(), value, insertAt);
}

bool ActiveChannelImpl::add(std::string _qualifiedName, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->add(uID, value, insertAt);
}

bool ActiveChannelImpl::add(unsigned long _uID, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	//Call add() for base class Channel
	if(FoundationalModelLibrary::BasicInputOutput::ChannelImpl::add(_uID, value, insertAt)) return true;
	return false;
}

//Unset
bool ActiveChannelImpl::unset(const std::shared_ptr<uml::Property>& _property)
{
	return this->unset(_property->_getID());
}

bool ActiveChannelImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->unset(uID);
}

bool ActiveChannelImpl::unset(unsigned long _uID)
{
	//Call unset() for base class Channel
	if(FoundationalModelLibrary::BasicInputOutput::ChannelImpl::unset(_uID)) return true;
	return false;
}

//Remove
std::shared_ptr<Any> ActiveChannelImpl::remove(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	return this->remove(_property->_getID(), value, removeAt, isRemoveDuplicates);
}

std::shared_ptr<Any> ActiveChannelImpl::remove(std::string _qualifiedName, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->remove(uID, value, removeAt, isRemoveDuplicates);
}

std::shared_ptr<Any> ActiveChannelImpl::remove(unsigned long _uID, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	std::shared_ptr<Any> removedValue = nullptr;
	//Call set() for base class Channel
	removedValue = FoundationalModelLibrary::BasicInputOutput::ChannelImpl::remove(_uID, value, removeAt, isRemoveDuplicates);
	if(removedValue) return removedValue;
	return removedValue;
}

//**************************************
// Operation & OpaqueBehavior Invocation
//**************************************
//Operation Invocation
std::shared_ptr<Any> ActiveChannelImpl::invoke(const std::shared_ptr<uml::Operation>& _operation, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	return this->invokeOperation(_operation->_getID(), inputArguments, outputArguments);
}

std::shared_ptr<Any> ActiveChannelImpl::invokeOperation(std::string _qualifiedName, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->invokeOperation(uID, inputArguments, outputArguments);
}

std::shared_ptr<Any> ActiveChannelImpl::invokeOperation(unsigned long _uID, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	std::shared_ptr<Any> result = nullptr;
	//Call invoke() for base class Channel
	result = FoundationalModelLibrary::BasicInputOutput::ChannelImpl::invokeOperation(_uID, inputArguments, outputArguments);
	if (result != nullptr)
	{
		return result;
	}
	return result;
}

//OpaqueBehavior Invocation
std::shared_ptr<Any> ActiveChannelImpl::invoke(const std::shared_ptr<uml::OpaqueBehavior>& _opaqueBehavior, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	return this->invokeOpaqueBehavior(_opaqueBehavior->_getID(), inputArguments, outputArguments);
}

std::shared_ptr<Any> ActiveChannelImpl::invokeOpaqueBehavior(std::string _qualifiedName, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->invokeOpaqueBehavior(uID, inputArguments, outputArguments);
}

std::shared_ptr<Any> ActiveChannelImpl::invokeOpaqueBehavior(unsigned long _uID, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	std::shared_ptr<Any> result = nullptr;
	//Call invoke() for base class Channel
	result = FoundationalModelLibrary::BasicInputOutput::ChannelImpl::invokeOpaqueBehavior(_uID, inputArguments, outputArguments);
	if (result != nullptr)
	{
		return result;
	}
	return result;
}

std::shared_ptr<ActiveChannel> ActiveChannelImpl::getThisActiveChannelPtr()
{
	return m_thisActiveChannelPtr.lock();
}
void ActiveChannelImpl::setThisActiveChannelPtr(std::weak_ptr<ActiveChannel> thisActiveChannelPtr)
{
	m_thisActiveChannelPtr = thisActiveChannelPtr;
	setThisChannelPtr(thisActiveChannelPtr);
}
