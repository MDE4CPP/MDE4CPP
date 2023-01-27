#include "FoundationalModelLibrary/BasicInputOutput/impl/StandardOutputChannelImpl.hpp"

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
StandardOutputChannelImpl::StandardOutputChannelImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_INFO("Instance of 'StandardOutputChannel' is created.")
	//***********************************
}


StandardOutputChannelImpl::~StandardOutputChannelImpl()
{
	DEBUG_INFO("Instance of 'StandardOutputChannel' is destroyed.")
}

StandardOutputChannelImpl::StandardOutputChannelImpl(const StandardOutputChannelImpl & obj):StandardOutputChannelImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  StandardOutputChannelImpl::copy() const
{
	std::shared_ptr<StandardOutputChannelImpl> element(new StandardOutputChannelImpl());
	*element=(*this);
	element->setThisStandardOutputChannelPtr(element);
	return element;
}

StandardOutputChannelImpl& StandardOutputChannelImpl::operator=(const StandardOutputChannelImpl & obj)
{
	//call overloaded =Operator for each base class
	TextOutputChannelImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy StandardOutputChannel "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();

	//copy attributes with no containment (soft copy)

	//clone attributes with containment (deep copy)

	return *this;
}


std::shared_ptr<uml::Class> StandardOutputChannelImpl::getMetaClass() const
{
	return BasicInputOutputPackageImpl::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_StandardOutputChannel();
}

void StandardOutputChannelImpl::instantiate()
{   
	TextOutputChannelImpl::instantiate();
}

void StandardOutputChannelImpl::destroy()
{	

	//Erase properties
	//Erase back reference to owner
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
//**************************************
// StructuralFeature Getter & Setter
//**************************************
//Get
std::shared_ptr<Any> StandardOutputChannelImpl::get(std::shared_ptr<uml::Property> _property) const
{
	return this->get(_property->_getID());
}

std::shared_ptr<Any> StandardOutputChannelImpl::get(std::string _qualifiedName) const
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->get(uID);
}

std::shared_ptr<Any> StandardOutputChannelImpl::get(unsigned long _uID) const
{
	std::shared_ptr<Any> result;
	//Call get() for base class TextOutputChannel
	result = FoundationalModelLibrary::BasicInputOutput::TextOutputChannelImpl::get(_uID);
	if (result != nullptr)
	{
		return result;
	}
	return result;
}

//Set
void StandardOutputChannelImpl::set(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value)
{
	this->set(_property->_getID(), value);
}

void StandardOutputChannelImpl::set(std::string _qualifiedName, std::shared_ptr<Any> value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->set(uID, value);
}

void StandardOutputChannelImpl::set(unsigned long _uID, std::shared_ptr<Any> value)
{
	//Call set() for base class TextOutputChannel
	FoundationalModelLibrary::BasicInputOutput::TextOutputChannelImpl::set(_uID, value);
}

//Add
void StandardOutputChannelImpl::add(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
	this->add(_property->_getID(), value);
}

void StandardOutputChannelImpl::add(std::string _qualifiedName, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->add(uID, value);
}

void StandardOutputChannelImpl::add(unsigned long _uID, std::shared_ptr<Any> value, int insertAt /*= -1*/)
{
	//Call set() for base class TextOutputChannel
	FoundationalModelLibrary::BasicInputOutput::TextOutputChannelImpl::add(_uID, value, insertAt);
}

//Unset
void StandardOutputChannelImpl::unset(std::shared_ptr<uml::Property> _property)
{
	this->unset(_property->_getID());
}

void StandardOutputChannelImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->unset(uID);
}

void StandardOutputChannelImpl::unset(unsigned long _uID)
{
	//Call unset() for base class TextOutputChannel
	FoundationalModelLibrary::BasicInputOutput::TextOutputChannelImpl::unset(_uID);
}

//Remove
void StandardOutputChannelImpl::remove(std::shared_ptr<uml::Property> _property, std::shared_ptr<Any> value)
{
	this->remove(_property->_getID(), value);
}

void StandardOutputChannelImpl::remove(std::string _qualifiedName, std::shared_ptr<Any> value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->remove(uID, value);
}

void StandardOutputChannelImpl::remove(unsigned long _uID, std::shared_ptr<Any> value)
{
	//Call set() for base class TextOutputChannel
	FoundationalModelLibrary::BasicInputOutput::TextOutputChannelImpl::remove(_uID, value);
}

//**************************************
// Operation & OpaqueBehavior Invocation
//**************************************
//Operation Invocation
std::shared_ptr<Any> StandardOutputChannelImpl::invoke(std::shared_ptr<uml::Operation> _operation, std::shared_ptr<Bag<Any>> inputArguments, std::shared_ptr<Bag<Any>> outputArguments)
{
	return this->invoke(_operation->_getID(), inputArguments, outputArguments);
}

std::shared_ptr<Any> StandardOutputChannelImpl::invoke(std::string _qualifiedName, std::shared_ptr<Bag<Any>> inputArguments, std::shared_ptr<Bag<Any>> outputArguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->invoke(uID, inputArguments, outputArguments);
}

std::shared_ptr<Any> StandardOutputChannelImpl::invoke(unsigned long _uID, std::shared_ptr<Bag<Any>> inputArguments, std::shared_ptr<Bag<Any>> outputArguments)
{
	std::shared_ptr<Any> result = eAny(nullptr, -1, false);
	//Call invoke() for base class TextOutputChannel
	result = FoundationalModelLibrary::BasicInputOutput::TextOutputChannelImpl::invoke(_uID, inputArguments, outputArguments);
	if (result != nullptr)
	{
		return result;
	}
	return result;
}

//OpaqueBehavior Invocation
std::shared_ptr<Any> StandardOutputChannelImpl::invoke(std::shared_ptr<uml::OpaqueBehavior> _opaqueBehavior, std::shared_ptr<Bag<Any>> inputArguments, std::shared_ptr<Bag<Any>> outputArguments)
{
	std::shared_ptr<Any> result;
	//Call invoke() for base class TextOutputChannel
	result = FoundationalModelLibrary::BasicInputOutput::TextOutputChannelImpl::invoke(_opaqueBehavior, inputArguments, outputArguments);
	if (result != nullptr)
	{
		return result;
	}
	return result;
}

std::shared_ptr<StandardOutputChannel> StandardOutputChannelImpl::getThisStandardOutputChannelPtr()
{
	return m_thisStandardOutputChannelPtr.lock();
}
void StandardOutputChannelImpl::setThisStandardOutputChannelPtr(std::weak_ptr<StandardOutputChannel> thisStandardOutputChannelPtr)
{
	m_thisStandardOutputChannelPtr = thisStandardOutputChannelPtr;
	setThisTextOutputChannelPtr(thisStandardOutputChannelPtr);
}
