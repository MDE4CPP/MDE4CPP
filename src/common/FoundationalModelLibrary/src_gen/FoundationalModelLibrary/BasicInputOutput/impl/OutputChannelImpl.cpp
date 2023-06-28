#include "FoundationalModelLibrary/BasicInputOutput/impl/OutputChannelImpl.hpp"

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
OutputChannelImpl::OutputChannelImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_INFO("Instance of 'OutputChannel' is created.")
	//***********************************
}


OutputChannelImpl::~OutputChannelImpl()
{
	DEBUG_INFO("Instance of 'OutputChannel' is destroyed.")
}

OutputChannelImpl::OutputChannelImpl(const OutputChannelImpl & obj):OutputChannelImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  OutputChannelImpl::copy() const
{
	std::shared_ptr<OutputChannelImpl> element(new OutputChannelImpl());
	*element=(*this);
	element->setThisOutputChannelPtr(element);
	return element;
}

OutputChannelImpl& OutputChannelImpl::operator=(const OutputChannelImpl & obj)
{
	//call overloaded =Operator for each base class
	ChannelImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy OutputChannel "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();

	//copy attributes with no containment (soft copy)

	//clone attributes with containment (deep copy)

	return *this;
}


const std::shared_ptr<uml::Class>& OutputChannelImpl::getMetaClass() const
{
	return BasicInputOutputPackageImpl::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_OutputChannel();
}

void OutputChannelImpl::instantiate()
{   
	ChannelImpl::instantiate();
}

void OutputChannelImpl::destroy()
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
const std::shared_ptr<Bag<uml::Classifier>>& OutputChannelImpl::getTypes() const
{
	static std::shared_ptr<Bag<uml::Classifier>> types;

	if(!types)
	{
		types.reset();
		// Add type of self 'OutputChannel' : Class
		types->add(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_OutputChannel());
		// Add base type 'Channel' : Class
		types->add(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_Channel());
	}

	return types;
}

//**************************************
// StructuralFeature Getter & Setter
//**************************************
//Get
std::shared_ptr<Any> OutputChannelImpl::get(const std::shared_ptr<uml::Property>& _property) const
{
	return this->get(_property->_getID());
}

std::shared_ptr<Any> OutputChannelImpl::get(std::string _qualifiedName) const
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->get(uID);
}

std::shared_ptr<Any> OutputChannelImpl::get(unsigned long _uID) const
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
void OutputChannelImpl::set(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value)
{
	this->set(_property->_getID(), value);
}

void OutputChannelImpl::set( std::string _qualifiedName, const std::shared_ptr<Any>& value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->set(uID, value);
}

void OutputChannelImpl::set(unsigned long _uID, const std::shared_ptr<Any>& value)
{
	//Call set() for base class Channel
	FoundationalModelLibrary::BasicInputOutput::ChannelImpl::set(_uID, value);
}

//Add
void OutputChannelImpl::add(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	this->add(_property->_getID(), value);
}

void OutputChannelImpl::add(std::string _qualifiedName, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->add(uID, value);
}

void OutputChannelImpl::add(unsigned long _uID, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	//Call set() for base class Channel
	FoundationalModelLibrary::BasicInputOutput::ChannelImpl::add(_uID, value, insertAt);
}

//Unset
void OutputChannelImpl::unset(const std::shared_ptr<uml::Property>& _property)
{
	this->unset(_property->_getID());
}

void OutputChannelImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->unset(uID);
}

void OutputChannelImpl::unset(unsigned long _uID)
{
	//Call unset() for base class Channel
	FoundationalModelLibrary::BasicInputOutput::ChannelImpl::unset(_uID);
}

//Remove
void OutputChannelImpl::remove(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value)
{
	this->remove(_property->_getID(), value);
}

void OutputChannelImpl::remove(std::string _qualifiedName, const std::shared_ptr<Any>& value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	this->remove(uID, value);
}

void OutputChannelImpl::remove(unsigned long _uID, const std::shared_ptr<Any>& value)
{
	//Call set() for base class Channel
	FoundationalModelLibrary::BasicInputOutput::ChannelImpl::remove(_uID, value);
}

//**************************************
// Operation & OpaqueBehavior Invocation
//**************************************
//Operation Invocation
std::shared_ptr<Any> OutputChannelImpl::invoke(const std::shared_ptr<uml::Operation>& _operation, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	return this->invoke(_operation->_getID(), inputArguments, outputArguments);
}

std::shared_ptr<Any> OutputChannelImpl::invoke(std::string _qualifiedName, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->invoke(uID, inputArguments, outputArguments);
}

std::shared_ptr<Any> OutputChannelImpl::invoke(unsigned long _uID, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
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
std::shared_ptr<Any> OutputChannelImpl::invoke(const std::shared_ptr<uml::OpaqueBehavior>& _opaqueBehavior, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
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

std::shared_ptr<OutputChannel> OutputChannelImpl::getThisOutputChannelPtr()
{
	return m_thisOutputChannelPtr.lock();
}
void OutputChannelImpl::setThisOutputChannelPtr(std::weak_ptr<OutputChannel> thisOutputChannelPtr)
{
	m_thisOutputChannelPtr = thisOutputChannelPtr;
	setThisChannelPtr(thisOutputChannelPtr);
}
