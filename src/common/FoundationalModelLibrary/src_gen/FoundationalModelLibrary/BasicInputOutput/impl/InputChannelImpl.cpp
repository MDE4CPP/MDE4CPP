#include "FoundationalModelLibrary/BasicInputOutput/impl/InputChannelImpl.hpp"

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

using namespace FoundationalModelLibrary::BasicInputOutput;

//*********************************
// Constructor / Destructor
//*********************************
InputChannelImpl::InputChannelImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_INFO("Instance of 'InputChannel' is created.")
	//***********************************
}


InputChannelImpl::~InputChannelImpl()
{
	DEBUG_INFO("Instance of 'InputChannel' is destroyed.")
}

InputChannelImpl::InputChannelImpl(const InputChannelImpl & obj):InputChannelImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  InputChannelImpl::copy() const
{
	std::shared_ptr<InputChannelImpl> element(new InputChannelImpl());
	*element=(*this);
	element->setThisInputChannelPtr(element);
	return element;
}

InputChannelImpl& InputChannelImpl::operator=(const InputChannelImpl & obj)
{
	//call overloaded =Operator for each base class
	ChannelImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InputChannel "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();

	//copy attributes with no containment (soft copy)

	//clone attributes with containment (deep copy)

	return *this;
}


const std::shared_ptr<uml::Class>& InputChannelImpl::getMetaClass() const
{
	return BasicInputOutputPackageImpl::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_InputChannel();
}

void InputChannelImpl::instantiate()
{   
	ChannelImpl::instantiate();
}

void InputChannelImpl::destroy()
{	
	fUML::MDE4CPP_Extensions::FUML_ObjectImpl::destroy();
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
// fUML-specific Operations
const std::shared_ptr<Bag<uml::Classifier>>& InputChannelImpl::getTypes() const
{
	static std::shared_ptr<Bag<uml::Classifier>> types;

	if(!types)
	{
		types.reset();
		// Add type of self 'InputChannel' : Class
		types->add(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_InputChannel());
		// Add base type 'Channel' : Class
		types->add(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_Channel());
	}

	return types;
}

//**************************************
// StructuralFeature Getter & Setter
//**************************************
//Get
std::shared_ptr<Any> InputChannelImpl::get(const std::shared_ptr<uml::Property>& _property) const
{
	return this->get(_property->_getID());
}

std::shared_ptr<Any> InputChannelImpl::get(std::string _qualifiedName) const
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->get(uID);
}

std::shared_ptr<Any> InputChannelImpl::get(unsigned long _uID) const
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
void InputChannelImpl::set(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value)
{
	this->set(_property->_getID(), value);
}

void InputChannelImpl::set( std::string _qualifiedName, const std::shared_ptr<Any>& value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->set(uID, value);
}

void InputChannelImpl::set(unsigned long _uID, const std::shared_ptr<Any>& value)
{
	//Call set() for base class Channel
	FoundationalModelLibrary::BasicInputOutput::ChannelImpl::set(_uID, value);
}

//Add
void InputChannelImpl::add(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	this->add(_property->_getID(), value);
}

void InputChannelImpl::add(std::string _qualifiedName, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->add(uID, value);
}

void InputChannelImpl::add(unsigned long _uID, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	//Call set() for base class Channel
	FoundationalModelLibrary::BasicInputOutput::ChannelImpl::add(_uID, value, insertAt);
}

//Unset
void InputChannelImpl::unset(const std::shared_ptr<uml::Property>& _property)
{
	this->unset(_property->_getID());
}

void InputChannelImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->unset(uID);
}

void InputChannelImpl::unset(unsigned long _uID)
{
	//Call unset() for base class Channel
	FoundationalModelLibrary::BasicInputOutput::ChannelImpl::unset(_uID);
}

//Remove
void InputChannelImpl::remove(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value)
{
	this->remove(_property->_getID(), value);
}

void InputChannelImpl::remove(std::string _qualifiedName, const std::shared_ptr<Any>& value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->remove(uID, value);
}

void InputChannelImpl::remove(unsigned long _uID, const std::shared_ptr<Any>& value)
{
	//Call set() for base class Channel
	FoundationalModelLibrary::BasicInputOutput::ChannelImpl::remove(_uID, value);
}

//**************************************
// Operation & OpaqueBehavior Invocation
//**************************************
//Operation Invocation
std::shared_ptr<Any> InputChannelImpl::invoke(const std::shared_ptr<uml::Operation>& _operation, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	return this->invoke(_operation->_getID(), inputArguments, outputArguments);
}

std::shared_ptr<Any> InputChannelImpl::invoke(std::string _qualifiedName, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->invoke(uID, inputArguments, outputArguments);
}

std::shared_ptr<Any> InputChannelImpl::invoke(unsigned long _uID, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	std::shared_ptr<Any> result = eAny(nullptr, -1, false);
	//Call invoke() for base class Channel
	result = FoundationalModelLibrary::BasicInputOutput::ChannelImpl::invoke(_uID, inputArguments, outputArguments);
	if (result != nullptr)
	{
		return result;
	}
	return result;
}

//OpaqueBehavior Invocation
std::shared_ptr<Any> InputChannelImpl::invoke(const std::shared_ptr<uml::OpaqueBehavior>& _opaqueBehavior, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	std::shared_ptr<Any> result;
	//Call invoke() for base class Channel
	result = FoundationalModelLibrary::BasicInputOutput::ChannelImpl::invoke(_opaqueBehavior, inputArguments, outputArguments);
	if (result != nullptr)
	{
		return result;
	}
	return result;
}

std::shared_ptr<InputChannel> InputChannelImpl::getThisInputChannelPtr()
{
	return m_thisInputChannelPtr.lock();
}
void InputChannelImpl::setThisInputChannelPtr(std::weak_ptr<InputChannel> thisInputChannelPtr)
{
	m_thisInputChannelPtr = thisInputChannelPtr;
	setThisChannelPtr(thisInputChannelPtr);
}
