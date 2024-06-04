#include "FoundationalModelLibrary/BasicInputOutput/impl/ChannelImpl.hpp"

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
ChannelImpl::ChannelImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_INFO("Instance of 'Channel' is created.")
	//***********************************
}


ChannelImpl::~ChannelImpl()
{
	DEBUG_INFO("Instance of 'Channel' is destroyed.")
}

ChannelImpl::ChannelImpl(const ChannelImpl & obj):ChannelImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  ChannelImpl::copy() const
{
	std::shared_ptr<ChannelImpl> element(new ChannelImpl());
	*element=(*this);
	element->setThisChannelPtr(element);
	return element;
}

ChannelImpl& ChannelImpl::operator=(const ChannelImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::MDE4CPP_Extensions::FUML_ObjectImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Channel "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();

	//copy attributes with no containment (soft copy)

	//clone attributes with containment (deep copy)

	return *this;
}


const std::shared_ptr<uml::Class>& ChannelImpl::getMetaClass() const
{
	return BasicInputOutputPackageImpl::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_Channel();
}

void ChannelImpl::instantiate()
{   
}

void ChannelImpl::destroy()
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
const std::shared_ptr<Bag<uml::Classifier>>& ChannelImpl::getTypes() const
{
	static std::shared_ptr<Bag<uml::Classifier>> types;

	if(!types)
	{
		types.reset();
		// Add type of self 'Channel' : Class
		types->add(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_Channel());
	}

	return types;
}

void ChannelImpl::destroy(bool isDestroyLinks, bool isDestroyOwnedObjects)
{
	fUML::MDE4CPP_Extensions::FUML_ObjectImpl::destroy(isDestroyLinks, isDestroyOwnedObjects);
}

//**************************************
// StructuralFeature Getter & Setter
//**************************************
//Get
std::shared_ptr<Any> ChannelImpl::get(const std::shared_ptr<uml::Property>& _property) const
{
	return this->get(_property->_getID());
}

std::shared_ptr<Any> ChannelImpl::get(std::string _qualifiedName) const
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->get(uID);
}

std::shared_ptr<Any> ChannelImpl::get(unsigned long _uID) const
{
	return nullptr;
}

//Set
bool ChannelImpl::set(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value)
{
	return this->set(_property->_getID(), value);
}

bool ChannelImpl::set( std::string _qualifiedName, const std::shared_ptr<Any>& value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->set(uID, value);
}

bool ChannelImpl::set(unsigned long _uID, const std::shared_ptr<Any>& value)
{
	return false;
}

//Add
bool ChannelImpl::add(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	return this->add(_property->_getID(), value, insertAt);
}

bool ChannelImpl::add(std::string _qualifiedName, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->add(uID, value, insertAt);
}

bool ChannelImpl::add(unsigned long _uID, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	return false;
}

//Unset
bool ChannelImpl::unset(const std::shared_ptr<uml::Property>& _property)
{
	return this->unset(_property->_getID());
}

bool ChannelImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->unset(uID);
}

bool ChannelImpl::unset(unsigned long _uID)
{
	return false;
}

//Remove
bool ChannelImpl::remove(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	return this->remove(_property->_getID(), value, removeAt, isRemoveDuplicates);
}

bool ChannelImpl::remove(std::string _qualifiedName, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->remove(uID, value, removeAt, isRemoveDuplicates);
}

bool ChannelImpl::remove(unsigned long _uID, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	return false;
}

//**************************************
// Operation & OpaqueBehavior Invocation
//**************************************
//Operation Invocation
std::shared_ptr<Any> ChannelImpl::invoke(const std::shared_ptr<uml::Operation>& _operation, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	return this->invokeOperation(_operation->_getID(), inputArguments, outputArguments);
}

std::shared_ptr<Any> ChannelImpl::invokeOperation(std::string _qualifiedName, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->invokeOperation(uID, inputArguments, outputArguments);
}

std::shared_ptr<Any> ChannelImpl::invokeOperation(unsigned long _uID, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	std::shared_ptr<Any> result = nullptr;
	return result;
}

//OpaqueBehavior Invocation
std::shared_ptr<Any> ChannelImpl::invoke(const std::shared_ptr<uml::OpaqueBehavior>& _opaqueBehavior, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	return this->invokeOpaqueBehavior(_opaqueBehavior->_getID(), inputArguments, outputArguments);
}

std::shared_ptr<Any> ChannelImpl::invokeOpaqueBehavior(std::string _qualifiedName, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->invokeOpaqueBehavior(uID, inputArguments, outputArguments);
}

std::shared_ptr<Any> ChannelImpl::invokeOpaqueBehavior(unsigned long _uID, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	return nullptr;
}

std::shared_ptr<Channel> ChannelImpl::getThisChannelPtr()
{
	return m_thisChannelPtr.lock();
}
void ChannelImpl::setThisChannelPtr(std::weak_ptr<Channel> thisChannelPtr)
{
	m_thisChannelPtr = thisChannelPtr;
	setThisFUML_ObjectPtr(thisChannelPtr);
}
