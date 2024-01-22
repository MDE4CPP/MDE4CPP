#include "FoundationalModelLibrary/BasicInputOutput/impl/TextInputChannelImpl.hpp"

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
#include <stdexcept>

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

//Package for used PrimitiveTypes
#include "types/typesPackage.hpp"

//Packages for used (non-primitive) Types
#include "FoundationalModelLibrary/Common/CommonPackage.hpp"

//Used Types
#include "FoundationalModelLibrary/Common/Status.hpp"

//Includes of Operations//Included from operation "peekCharacter"
#include <iostream>
//Included from operation "readBoolean"
#include <iostream>
//Included from operation "readCharacter"
#include <iostream>
//Included from operation "readInteger"
#include <iostream>
//Included from operation "readLine"
#include <iostream>


using namespace FoundationalModelLibrary::BasicInputOutput;

//*********************************
// Constructor / Destructor
//*********************************
TextInputChannelImpl::TextInputChannelImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_INFO("Instance of 'TextInputChannel' is created.")
	//***********************************
}


TextInputChannelImpl::~TextInputChannelImpl()
{
	DEBUG_INFO("Instance of 'TextInputChannel' is destroyed.")
}

TextInputChannelImpl::TextInputChannelImpl(const TextInputChannelImpl & obj):TextInputChannelImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  TextInputChannelImpl::copy() const
{
	std::shared_ptr<TextInputChannelImpl> element(new TextInputChannelImpl());
	*element=(*this);
	element->setThisTextInputChannelPtr(element);
	return element;
}

TextInputChannelImpl& TextInputChannelImpl::operator=(const TextInputChannelImpl & obj)
{
	//call overloaded =Operator for each base class
	InputChannelImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TextInputChannel "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();

	//copy attributes with no containment (soft copy)

	//clone attributes with containment (deep copy)

	return *this;
}


const std::shared_ptr<uml::Class>& TextInputChannelImpl::getMetaClass() const
{
	return BasicInputOutputPackageImpl::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel();
}

void TextInputChannelImpl::instantiate()
{   
	InputChannelImpl::instantiate();
}

void TextInputChannelImpl::destroy()
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
std::string TextInputChannelImpl::peekCharacter(std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus) 
{
	std::string ReturnResult = "";

	//Implemented as OpaqueBehaviour fb_peekCharacter
	char c = std::cin.peek();
	ReturnResult = c;
	

	return ReturnResult;
}

bool TextInputChannelImpl::readBoolean(std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus) 
{
	bool ReturnResult = 0;

	//Implemented as OpaqueBehaviour fb_readBoolean
	std::cin>>ReturnResult;
	

	return ReturnResult;
}

std::string TextInputChannelImpl::readCharacter(std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus) 
{
	std::string ReturnResult = "";

	//Implemented as OpaqueBehaviour fb_readCharacter
	char c;
	std::cin>>c;
	ReturnResult.push_back(c);
	
	

	return ReturnResult;
}

int TextInputChannelImpl::readInteger(std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus) 
{
	int ReturnResult = 0;

	//Implemented as OpaqueBehaviour fb_readInteger
	std::cin>>ReturnResult;
	
	

	return ReturnResult;
}

std::string TextInputChannelImpl::readLine(std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus) 
{
	std::string ReturnResult = "";

	//Implemented as OpaqueBehaviour fb_readLine
	std::getline(std::cin,ReturnResult);
	
	

	return ReturnResult;
}

double TextInputChannelImpl::readReal(std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus) 
{
	double ReturnResult = 0;

	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));

	return ReturnResult;
}

int TextInputChannelImpl::readUnlimitedNatural(std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus) 
{
	int ReturnResult = 0;

	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));

	return ReturnResult;
}

// fUML-specific Operations
const std::shared_ptr<Bag<uml::Classifier>>& TextInputChannelImpl::getTypes() const
{
	static std::shared_ptr<Bag<uml::Classifier>> types;

	if(!types)
	{
		types.reset();
		// Add type of self 'TextInputChannel' : Class
		types->add(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel());
		// Add base type 'Channel' : Class
		types->add(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_Channel());
		// Add base type 'InputChannel' : Class
		types->add(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_InputChannel());
	}

	return types;
}

//**************************************
// StructuralFeature Getter & Setter
//**************************************
//Get
std::shared_ptr<Any> TextInputChannelImpl::get(const std::shared_ptr<uml::Property>& _property) const
{
	return this->get(_property->_getID());
}

std::shared_ptr<Any> TextInputChannelImpl::get(std::string _qualifiedName) const
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->get(uID);
}

std::shared_ptr<Any> TextInputChannelImpl::get(unsigned long _uID) const
{
	std::shared_ptr<Any> result;
	//Call get() for base class InputChannel
	result = FoundationalModelLibrary::BasicInputOutput::InputChannelImpl::get(_uID);
	if (result != nullptr)
	{
		return result;
	}
	return result;
}

//Set
bool TextInputChannelImpl::set(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value)
{
	return this->set(_property->_getID(), value);
}

bool TextInputChannelImpl::set( std::string _qualifiedName, const std::shared_ptr<Any>& value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->set(uID, value);
}

bool TextInputChannelImpl::set(unsigned long _uID, const std::shared_ptr<Any>& value)
{
	//Call set() for base class InputChannel
	if(FoundationalModelLibrary::BasicInputOutput::InputChannelImpl::set(_uID, value)) return true;
	return false;
}

//Add
bool TextInputChannelImpl::add(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	return this->add(_property->_getID(), value, insertAt);
}

bool TextInputChannelImpl::add(std::string _qualifiedName, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->add(uID, value, insertAt);
}

bool TextInputChannelImpl::add(unsigned long _uID, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	//Call add() for base class InputChannel
	if(FoundationalModelLibrary::BasicInputOutput::InputChannelImpl::add(_uID, value, insertAt)) return true;
	return false;
}

//Unset
bool TextInputChannelImpl::unset(const std::shared_ptr<uml::Property>& _property)
{
	return this->unset(_property->_getID());
}

bool TextInputChannelImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->unset(uID);
}

bool TextInputChannelImpl::unset(unsigned long _uID)
{
	//Call unset() for base class InputChannel
	if(FoundationalModelLibrary::BasicInputOutput::InputChannelImpl::unset(_uID)) return true;
	return false;
}

//Remove
bool TextInputChannelImpl::remove(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	return this->remove(_property->_getID(), value, removeAt, isRemoveDuplicates);
}

bool TextInputChannelImpl::remove(std::string _qualifiedName, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->remove(uID, value, removeAt, isRemoveDuplicates);
}

bool TextInputChannelImpl::remove(unsigned long _uID, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	//Call set() for base class InputChannel
	if(FoundationalModelLibrary::BasicInputOutput::InputChannelImpl::remove(_uID, value, removeAt, isRemoveDuplicates)) return true;
	return false;
}

//**************************************
// Operation & OpaqueBehavior Invocation
//**************************************
//Operation Invocation
std::shared_ptr<Any> TextInputChannelImpl::invoke(const std::shared_ptr<uml::Operation>& _operation, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	return this->invokeOperation(_operation->_getID(), inputArguments, outputArguments);
}

std::shared_ptr<Any> TextInputChannelImpl::invokeOperation(std::string _qualifiedName, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->invokeOperation(uID, inputArguments, outputArguments);
}

std::shared_ptr<Any> TextInputChannelImpl::invokeOperation(unsigned long _uID, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	std::shared_ptr<Any> result = nullptr;

	switch(_uID)
	{
		case FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::TEXTINPUTCHANNEL_OPERATION_PEEKCHARACTER_STATUS:
		{
		//Create output parameters
			//Create out parameter 'errorStatus'
			std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus;

			//Invoke method
			std::string ReturnResult = this->peekCharacter(errorStatus);
			std::shared_ptr<Any> returnArgument = eAny(ReturnResult, types::typesPackage::STRING_CLASS, false);

		//Store output parameters
			//Store out parameter 'errorStatus'
			std::shared_ptr<Any> anyErrorStatus = eUMLAny(errorStatus, FoundationalModelLibrary::Common::CommonPackage::STATUS_DATATYPE);
			outputArguments->add(anyErrorStatus);

			return returnArgument;
		}
		case FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::TEXTINPUTCHANNEL_OPERATION_READBOOLEAN_STATUS:
		{
		//Create output parameters
			//Create out parameter 'errorStatus'
			std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus;

			//Invoke method
			bool ReturnResult = this->readBoolean(errorStatus);
			std::shared_ptr<Any> returnArgument = eAny(ReturnResult, types::typesPackage::BOOLEAN_CLASS, false);

		//Store output parameters
			//Store out parameter 'errorStatus'
			std::shared_ptr<Any> anyErrorStatus = eUMLAny(errorStatus, FoundationalModelLibrary::Common::CommonPackage::STATUS_DATATYPE);
			outputArguments->add(anyErrorStatus);

			return returnArgument;
		}
		case FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::TEXTINPUTCHANNEL_OPERATION_READCHARACTER_STATUS:
		{
		//Create output parameters
			//Create out parameter 'errorStatus'
			std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus;

			//Invoke method
			std::string ReturnResult = this->readCharacter(errorStatus);
			std::shared_ptr<Any> returnArgument = eAny(ReturnResult, types::typesPackage::STRING_CLASS, false);

		//Store output parameters
			//Store out parameter 'errorStatus'
			std::shared_ptr<Any> anyErrorStatus = eUMLAny(errorStatus, FoundationalModelLibrary::Common::CommonPackage::STATUS_DATATYPE);
			outputArguments->add(anyErrorStatus);

			return returnArgument;
		}
		case FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::TEXTINPUTCHANNEL_OPERATION_READINTEGER_STATUS:
		{
		//Create output parameters
			//Create out parameter 'errorStatus'
			std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus;

			//Invoke method
			int ReturnResult = this->readInteger(errorStatus);
			std::shared_ptr<Any> returnArgument = eAny(ReturnResult, types::typesPackage::INTEGER_CLASS, false);

		//Store output parameters
			//Store out parameter 'errorStatus'
			std::shared_ptr<Any> anyErrorStatus = eUMLAny(errorStatus, FoundationalModelLibrary::Common::CommonPackage::STATUS_DATATYPE);
			outputArguments->add(anyErrorStatus);

			return returnArgument;
		}
		case FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::TEXTINPUTCHANNEL_OPERATION_READLINE_STATUS:
		{
		//Create output parameters
			//Create out parameter 'errorStatus'
			std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus;

			//Invoke method
			std::string ReturnResult = this->readLine(errorStatus);
			std::shared_ptr<Any> returnArgument = eAny(ReturnResult, types::typesPackage::STRING_CLASS, false);

		//Store output parameters
			//Store out parameter 'errorStatus'
			std::shared_ptr<Any> anyErrorStatus = eUMLAny(errorStatus, FoundationalModelLibrary::Common::CommonPackage::STATUS_DATATYPE);
			outputArguments->add(anyErrorStatus);

			return returnArgument;
		}
		case FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::TEXTINPUTCHANNEL_OPERATION_READREAL_STATUS:
		{
		//Create output parameters
			//Create out parameter 'errorStatus'
			std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus;

			//Invoke method
			double ReturnResult = this->readReal(errorStatus);
			std::shared_ptr<Any> returnArgument = eAny(ReturnResult, types::typesPackage::REAL_CLASS, false);

		//Store output parameters
			//Store out parameter 'errorStatus'
			std::shared_ptr<Any> anyErrorStatus = eUMLAny(errorStatus, FoundationalModelLibrary::Common::CommonPackage::STATUS_DATATYPE);
			outputArguments->add(anyErrorStatus);

			return returnArgument;
		}
		case FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::TEXTINPUTCHANNEL_OPERATION_READUNLIMITEDNATURAL_STATUS:
		{
		//Create output parameters
			//Create out parameter 'errorStatus'
			std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus;

			//Invoke method
			int ReturnResult = this->readUnlimitedNatural(errorStatus);
			std::shared_ptr<Any> returnArgument = eAny(ReturnResult, types::typesPackage::UNLIMITEDNATURAL_CLASS, false);

		//Store output parameters
			//Store out parameter 'errorStatus'
			std::shared_ptr<Any> anyErrorStatus = eUMLAny(errorStatus, FoundationalModelLibrary::Common::CommonPackage::STATUS_DATATYPE);
			outputArguments->add(anyErrorStatus);

			return returnArgument;
		}
	}

	//Call invoke() for base class InputChannel
	result = FoundationalModelLibrary::BasicInputOutput::InputChannelImpl::invokeOperation(_uID, inputArguments, outputArguments);
	if (result != nullptr)
	{
		return result;
	}
	return result;
}

//OpaqueBehavior Invocation
std::shared_ptr<Any> TextInputChannelImpl::invoke(const std::shared_ptr<uml::OpaqueBehavior>& _opaqueBehavior, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	return this->invokeOpaqueBehavior(_opaqueBehavior->_getID(), inputArguments, outputArguments);
}

std::shared_ptr<Any> TextInputChannelImpl::invokeOpaqueBehavior(std::string _qualifiedName, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->invokeOpaqueBehavior(uID, inputArguments, outputArguments);
}

std::shared_ptr<Any> TextInputChannelImpl::invokeOpaqueBehavior(unsigned long _uID, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	std::shared_ptr<Any> result = nullptr;
	//Call invoke() for base class InputChannel
	result = FoundationalModelLibrary::BasicInputOutput::InputChannelImpl::invokeOpaqueBehavior(_uID, inputArguments, outputArguments);
	if (result != nullptr)
	{
		return result;
	}
	return result;
}

std::shared_ptr<TextInputChannel> TextInputChannelImpl::getThisTextInputChannelPtr()
{
	return m_thisTextInputChannelPtr.lock();
}
void TextInputChannelImpl::setThisTextInputChannelPtr(std::weak_ptr<TextInputChannel> thisTextInputChannelPtr)
{
	m_thisTextInputChannelPtr = thisTextInputChannelPtr;
	setThisInputChannelPtr(thisTextInputChannelPtr);
}
