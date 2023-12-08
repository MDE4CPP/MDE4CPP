#include "FoundationalModelLibrary/BasicInputOutput/impl/TextOutputChannelImpl.hpp"

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

//Includes of Operations//Included from operation "writeBoolean"
#include <iostream>
//Included from operation "writeInteger"
#include <iostream>
//Included from operation "writeLine"
#include <iostream>
//Included from operation "writeNewLine"
#include <iostream>
//Included from operation "writeString"
#include <iostream>


using namespace FoundationalModelLibrary::BasicInputOutput;

//*********************************
// Constructor / Destructor
//*********************************
TextOutputChannelImpl::TextOutputChannelImpl()
{
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
	DEBUG_INFO("Instance of 'TextOutputChannel' is created.")
	//***********************************
}


TextOutputChannelImpl::~TextOutputChannelImpl()
{
	DEBUG_INFO("Instance of 'TextOutputChannel' is destroyed.")
}

TextOutputChannelImpl::TextOutputChannelImpl(const TextOutputChannelImpl & obj):TextOutputChannelImpl()
{
	*this = obj;
}

std::shared_ptr<ecore::EObject>  TextOutputChannelImpl::copy() const
{
	std::shared_ptr<TextOutputChannelImpl> element(new TextOutputChannelImpl());
	*element=(*this);
	element->setThisTextOutputChannelPtr(element);
	return element;
}

TextOutputChannelImpl& TextOutputChannelImpl::operator=(const TextOutputChannelImpl & obj)
{
	//call overloaded =Operator for each base class
	OutputChannelImpl::operator=(obj);
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TextOutputChannel "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	instantiate();

	//copy attributes with no containment (soft copy)

	//clone attributes with containment (deep copy)

	return *this;
}


const std::shared_ptr<uml::Class>& TextOutputChannelImpl::getMetaClass() const
{
	return BasicInputOutputPackageImpl::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel();
}

void TextOutputChannelImpl::instantiate()
{   
	OutputChannelImpl::instantiate();
}

void TextOutputChannelImpl::destroy()
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
void TextOutputChannelImpl::writeBoolean(bool value,std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus) 
{

	//Implemented as OpaqueBehaviour fb_writeBoolean
	std::cout<<std::boolalpha<<value<<std::noboolalpha;
	
	

}

void TextOutputChannelImpl::writeInteger(int value,std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus) 
{

	//Implemented as OpaqueBehaviour fb_writeInteger
	std::cout<<value;
	

}

void TextOutputChannelImpl::writeLine(std::string value,std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus) 
{

	//Implemented as OpaqueBehaviour fb_writeLine
	std::cout<<value<< std::endl;
	

}

void TextOutputChannelImpl::writeNewLine(std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus) 
{

	//Implemented as OpaqueBehaviour fb_writeNewLine
	std::cout<<std::endl;
	

}

void TextOutputChannelImpl::writeReal(double value,std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus) 
{

	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));

}

void TextOutputChannelImpl::writeString(std::string value,std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus) 
{

	//Implemented as OpaqueBehaviour fb_writeString
	std::cout<<value;
	

}

void TextOutputChannelImpl::writeUnlimitedNatural(int value,std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus) 
{

	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));

}

// fUML-specific Operations
const std::shared_ptr<Bag<uml::Classifier>>& TextOutputChannelImpl::getTypes() const
{
	static std::shared_ptr<Bag<uml::Classifier>> types;

	if(!types)
	{
		types.reset();
		// Add type of self 'TextOutputChannel' : Class
		types->add(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_TextOutputChannel());
		// Add base type 'Channel' : Class
		types->add(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_Channel());
		// Add base type 'OutputChannel' : Class
		types->add(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_OutputChannel());
	}

	return types;
}

//**************************************
// StructuralFeature Getter & Setter
//**************************************
//Get
std::shared_ptr<Any> TextOutputChannelImpl::get(const std::shared_ptr<uml::Property>& _property) const
{
	return this->get(_property->_getID());
}

std::shared_ptr<Any> TextOutputChannelImpl::get(std::string _qualifiedName) const
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->get(uID);
}

std::shared_ptr<Any> TextOutputChannelImpl::get(unsigned long _uID) const
{
	std::shared_ptr<Any> result;
	//Call get() for base class OutputChannel
	result = FoundationalModelLibrary::BasicInputOutput::OutputChannelImpl::get(_uID);
	if (result != nullptr)
	{
		return result;
	}
	return result;
}

//Set
bool TextOutputChannelImpl::set(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value)
{
	return this->set(_property->_getID(), value);
}

bool TextOutputChannelImpl::set( std::string _qualifiedName, const std::shared_ptr<Any>& value)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->set(uID, value);
}

bool TextOutputChannelImpl::set(unsigned long _uID, const std::shared_ptr<Any>& value)
{
	//Call set() for base class OutputChannel
	if(FoundationalModelLibrary::BasicInputOutput::OutputChannelImpl::set(_uID, value)) return true;
	return false;
}

//Add
bool TextOutputChannelImpl::add(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	return this->add(_property->_getID(), value, insertAt);
}

bool TextOutputChannelImpl::add(std::string _qualifiedName, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->add(uID, value, insertAt);
}

bool TextOutputChannelImpl::add(unsigned long _uID, const std::shared_ptr<Any>& value, int insertAt /*= -1*/)
{
	//Call add() for base class OutputChannel
	if(FoundationalModelLibrary::BasicInputOutput::OutputChannelImpl::add(_uID, value, insertAt)) return true;
	return false;
}

//Unset
bool TextOutputChannelImpl::unset(const std::shared_ptr<uml::Property>& _property)
{
	return this->unset(_property->_getID());
}

bool TextOutputChannelImpl::unset(std::string _qualifiedName)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->unset(uID);
}

bool TextOutputChannelImpl::unset(unsigned long _uID)
{
	//Call unset() for base class OutputChannel
	if(FoundationalModelLibrary::BasicInputOutput::OutputChannelImpl::unset(_uID)) return true;
	return false;
}

//Remove
bool TextOutputChannelImpl::remove(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	return this->remove(_property->_getID(), value, removeAt, isRemoveDuplicates);
}

bool TextOutputChannelImpl::remove(std::string _qualifiedName, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->remove(uID, value, removeAt, isRemoveDuplicates);
}

bool TextOutputChannelImpl::remove(unsigned long _uID, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	//Call set() for base class OutputChannel
	if(FoundationalModelLibrary::BasicInputOutput::OutputChannelImpl::remove(_uID, value, removeAt, isRemoveDuplicates)) return true;
	return false;
}

//**************************************
// Operation & OpaqueBehavior Invocation
//**************************************
//Operation Invocation
std::shared_ptr<Any> TextOutputChannelImpl::invoke(const std::shared_ptr<uml::Operation>& _operation, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	return this->invoke(_operation->_getID(), inputArguments, outputArguments);
}

std::shared_ptr<Any> TextOutputChannelImpl::invoke(std::string _qualifiedName, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->invoke(uID, inputArguments, outputArguments);
}

std::shared_ptr<Any> TextOutputChannelImpl::invoke(unsigned long _uID, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	std::shared_ptr<Any> result = eAny(nullptr, -1, false);

	switch(_uID)
	{
		case FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::TEXTOUTPUTCHANNEL_OPERATION_WRITEBOOLEAN_BOOLEAN_STATUS:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'value'
			std::shared_ptr<Any> anyValue =  inputArguments->at(0);
			bool value;
			try
			{
				value = anyValue->get<bool>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'value'. Failed to invoke operation 'writeBoolean'!")
				return nullptr;
			}

		//Create output parameters
			//Create out parameter 'errorStatus'
			std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus;

			//Invoke method
			this->writeBoolean(value, errorStatus);
			std::shared_ptr<Any> returnArgument = eAny(nullptr, -1, false);

		//Store output parameters
			//Store out parameter 'errorStatus'
			std::shared_ptr<Any> anyErrorStatus = eUMLAny(errorStatus, FoundationalModelLibrary::Common::CommonPackage::STATUS_DATATYPE);
			outputArguments->add(anyErrorStatus);

			return returnArgument;
		}
		case FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::TEXTOUTPUTCHANNEL_OPERATION_WRITEINTEGER_INTEGER_STATUS:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'value'
			std::shared_ptr<Any> anyValue =  inputArguments->at(0);
			int value;
			try
			{
				value = anyValue->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'value'. Failed to invoke operation 'writeInteger'!")
				return nullptr;
			}

		//Create output parameters
			//Create out parameter 'errorStatus'
			std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus;

			//Invoke method
			this->writeInteger(value, errorStatus);
			std::shared_ptr<Any> returnArgument = eAny(nullptr, -1, false);

		//Store output parameters
			//Store out parameter 'errorStatus'
			std::shared_ptr<Any> anyErrorStatus = eUMLAny(errorStatus, FoundationalModelLibrary::Common::CommonPackage::STATUS_DATATYPE);
			outputArguments->add(anyErrorStatus);

			return returnArgument;
		}
		case FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::TEXTOUTPUTCHANNEL_OPERATION_WRITELINE_STRING_STATUS:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'value'
			std::shared_ptr<Any> anyValue =  inputArguments->at(0);
			std::string value;
			try
			{
				value = anyValue->get<std::string>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'value'. Failed to invoke operation 'writeLine'!")
				return nullptr;
			}

		//Create output parameters
			//Create out parameter 'errorStatus'
			std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus;

			//Invoke method
			this->writeLine(value, errorStatus);
			std::shared_ptr<Any> returnArgument = eAny(nullptr, -1, false);

		//Store output parameters
			//Store out parameter 'errorStatus'
			std::shared_ptr<Any> anyErrorStatus = eUMLAny(errorStatus, FoundationalModelLibrary::Common::CommonPackage::STATUS_DATATYPE);
			outputArguments->add(anyErrorStatus);

			return returnArgument;
		}
		case FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::TEXTOUTPUTCHANNEL_OPERATION_WRITENEWLINE_STATUS:
		{
		//Create output parameters
			//Create out parameter 'errorStatus'
			std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus;

			//Invoke method
			this->writeNewLine(errorStatus);
			std::shared_ptr<Any> returnArgument = eAny(nullptr, -1, false);

		//Store output parameters
			//Store out parameter 'errorStatus'
			std::shared_ptr<Any> anyErrorStatus = eUMLAny(errorStatus, FoundationalModelLibrary::Common::CommonPackage::STATUS_DATATYPE);
			outputArguments->add(anyErrorStatus);

			return returnArgument;
		}
		case FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::TEXTOUTPUTCHANNEL_OPERATION_WRITEREAL_REAL_STATUS:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'value'
			std::shared_ptr<Any> anyValue =  inputArguments->at(0);
			double value;
			try
			{
				value = anyValue->get<double>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'value'. Failed to invoke operation 'writeReal'!")
				return nullptr;
			}

		//Create output parameters
			//Create out parameter 'errorStatus'
			std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus;

			//Invoke method
			this->writeReal(value, errorStatus);
			std::shared_ptr<Any> returnArgument = eAny(nullptr, -1, false);

		//Store output parameters
			//Store out parameter 'errorStatus'
			std::shared_ptr<Any> anyErrorStatus = eUMLAny(errorStatus, FoundationalModelLibrary::Common::CommonPackage::STATUS_DATATYPE);
			outputArguments->add(anyErrorStatus);

			return returnArgument;
		}
		case FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::TEXTOUTPUTCHANNEL_OPERATION_WRITESTRING_STRING_STATUS:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'value'
			std::shared_ptr<Any> anyValue =  inputArguments->at(0);
			std::string value;
			try
			{
				value = anyValue->get<std::string>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'value'. Failed to invoke operation 'writeString'!")
				return nullptr;
			}

		//Create output parameters
			//Create out parameter 'errorStatus'
			std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus;

			//Invoke method
			this->writeString(value, errorStatus);
			std::shared_ptr<Any> returnArgument = eAny(nullptr, -1, false);

		//Store output parameters
			//Store out parameter 'errorStatus'
			std::shared_ptr<Any> anyErrorStatus = eUMLAny(errorStatus, FoundationalModelLibrary::Common::CommonPackage::STATUS_DATATYPE);
			outputArguments->add(anyErrorStatus);

			return returnArgument;
		}
		case FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::TEXTOUTPUTCHANNEL_OPERATION_WRITEUNLIMITEDNATURAL_UNLIMITEDNATURAL_STATUS:
		{
		//Retrieve input parameters
			//Retrieve in parameter 'value'
			std::shared_ptr<Any> anyValue =  inputArguments->at(0);
			int value;
			try
			{
				value = anyValue->get<int>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'value'. Failed to invoke operation 'writeUnlimitedNatural'!")
				return nullptr;
			}

		//Create output parameters
			//Create out parameter 'errorStatus'
			std::shared_ptr<FoundationalModelLibrary::Common::Status> errorStatus;

			//Invoke method
			this->writeUnlimitedNatural(value, errorStatus);
			std::shared_ptr<Any> returnArgument = eAny(nullptr, -1, false);

		//Store output parameters
			//Store out parameter 'errorStatus'
			std::shared_ptr<Any> anyErrorStatus = eUMLAny(errorStatus, FoundationalModelLibrary::Common::CommonPackage::STATUS_DATATYPE);
			outputArguments->add(anyErrorStatus);

			return returnArgument;
		}
	}

	//Call invoke() for base class OutputChannel
	result = FoundationalModelLibrary::BasicInputOutput::OutputChannelImpl::invoke(_uID, inputArguments, outputArguments);
	if (result != nullptr)
	{
		return result;
	}
	return result;
}

//OpaqueBehavior Invocation
std::shared_ptr<Any> TextOutputChannelImpl::invoke(const std::shared_ptr<uml::OpaqueBehavior>& _opaqueBehavior, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	std::shared_ptr<Any> result;
	//Call invoke() for base class OutputChannel
	result = FoundationalModelLibrary::BasicInputOutput::OutputChannelImpl::invoke(_opaqueBehavior, inputArguments, outputArguments);
	if (result != nullptr)
	{
		return result;
	}
	return result;
}

std::shared_ptr<TextOutputChannel> TextOutputChannelImpl::getThisTextOutputChannelPtr()
{
	return m_thisTextOutputChannelPtr.lock();
}
void TextOutputChannelImpl::setThisTextOutputChannelPtr(std::weak_ptr<TextOutputChannel> thisTextOutputChannelPtr)
{
	m_thisTextOutputChannelPtr = thisTextOutputChannelPtr;
	setThisOutputChannelPtr(thisTextOutputChannelPtr);
}
