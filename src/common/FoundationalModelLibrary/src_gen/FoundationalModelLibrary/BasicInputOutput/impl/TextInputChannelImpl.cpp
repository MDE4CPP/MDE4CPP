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

//PSCS-specific includes
#include "fUML/Semantics/Loci/Locus.hpp"
#include "PSCS/MDE4CPP_Extensions/MDE4CPP_ExtensionsFactory.hpp"
#include "PSCS/MDE4CPP_Extensions/PSCS_Link.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_LinkKind.hpp"
#include "uml/Port.hpp"

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

	//copy attributes with no containment (soft copy)

	//clone attributes with containment (deep copy)

	return *this;
}

const std::shared_ptr<uml::Class>& TextInputChannelImpl::getMetaClass() const
{
	return BasicInputOutputPackageImpl::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel();
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


// fUML-specific Method Overrides
const std::shared_ptr<Bag<uml::Classifier>>& TextInputChannelImpl::getTypes() const
{
	static std::shared_ptr<Bag<uml::Classifier>> types;

	if(!types)
	{
		types.reset(new Bag<uml::Classifier>());
		// Add type of self 'TextInputChannel' : Class
		types->add(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_TextInputChannel());
		// Add base type 'InputChannel' : Class
		types->add(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_InputChannel());
		// Add base type 'Channel' : Class
		types->add(FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::eInstance()->get_FoundationalModelLibrary_BasicInputOutput_Channel());
	}

	return types;
}

void TextInputChannelImpl::destroy(bool isDestroyLinks, bool isDestroyOwnedObjects)
{
	fUML::MDE4CPP_Extensions::FUML_ObjectImpl::destroy(isDestroyLinks, isDestroyOwnedObjects);
}

// PSCS-specific Method Overrides
void TextInputChannelImpl::construct()
{
	InputChannelImpl::construct();

}

void TextInputChannelImpl::constructObject(const std::shared_ptr<uml::Class>& type)
{
	switch(type->_getID())
	{
		case FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::TEXTINPUTCHANNEL_CLASS:
		{
			this->construct();
			break;
		}
		case FoundationalModelLibrary::BasicInputOutput::BasicInputOutputPackage::INPUTCHANNEL_CLASS:
		{
			InputChannelImpl::construct();
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

bool TextInputChannelImpl::contains(const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object>& object)
{
	/*
	 * TODO Avoid cycles here
	 */ 
	if(InputChannelImpl::contains(object)) return true;

	return false;
}

bool TextInputChannelImpl::directlyContains(const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object>& object)
{
	if(InputChannelImpl::directlyContains(object)) return true;

	return false;
}

std::shared_ptr<Any> TextInputChannelImpl::dispatchCallInByPort(const std::shared_ptr<uml::Operation>& _operation, const std::shared_ptr<uml::Port>& onPort, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	std::shared_ptr<Any> result;
	//Call dispatchCallIn() for base class InputChannel
	result = FoundationalModelLibrary::BasicInputOutput::InputChannelImpl::dispatchCallInByPort(_operation, onPort, inputArguments, outputArguments);
	if (result != nullptr)
	{
		return result;
	}
	return result;
}

std::shared_ptr<Any> TextInputChannelImpl::dispatchCallInOnInteractionPoint(const std::shared_ptr<uml::Operation>& _operation, const std::shared_ptr<PSCS::MDE4CPP_Extensions::PSCS_Object>& interactionPoint, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	if(interactionPoint->getDefiningPort()->getIsBehavior())
	{
		return this->dispatchCall(_operation, inputArguments, outputArguments);
	}
	else
	{
		std::shared_ptr<Bag<fUML::MDE4CPP_Extensions::FUML_Object>> potentialTargets(new Bag<fUML::MDE4CPP_Extensions::FUML_Object>);
		const std::shared_ptr<Bag<fUML::MDE4CPP_Extensions::FUML_Link>>& allLinks = interactionPoint->getLinks();
		
		for(const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Link>& link : *allLinks)
		{
			std::shared_ptr<PSCS::MDE4CPP_Extensions::PSCS_Link> cS_Link = std::dynamic_pointer_cast<PSCS::MDE4CPP_Extensions::PSCS_Link>(link);
			PSCS::Semantics::StructuredClassifiers::CS_LinkKind linkKind = cS_Link->retrieveLinkKind(interactionPoint);
			if(linkKind == PSCS::Semantics::StructuredClassifiers::CS_LinkKind::UNKNOWN)
			{
				// LinkKind has to be calculated
				linkKind = this->retrieveLinkKind(cS_Link, interactionPoint);
				cS_Link->assignLinkKind(interactionPoint, linkKind);
			}
			if(linkKind == PSCS::Semantics::StructuredClassifiers::CS_LinkKind::TOINTERNAL)
			{
				potentialTargets->add(cS_Link->retrieveOtherLinkEndValue(interactionPoint->getDefiningPort()));
			}
		}
		if(!(potentialTargets->size() == 0))
		{
			const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object>& target = potentialTargets->at(0); // TODO RequestPropagationStrategy should be invoked here
			return target->dispatchCall(_operation, inputArguments, outputArguments);
		}
		
		return nullptr;
	}
}

std::shared_ptr<Any> TextInputChannelImpl::dispatchCallOutByPort(const std::shared_ptr<uml::Operation>& _operation, const std::shared_ptr<uml::Port>& onPort, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	std::shared_ptr<Any> result;
	//Call dispatchCallOut() for base class InputChannel
	result = FoundationalModelLibrary::BasicInputOutput::InputChannelImpl::dispatchCallOutByPort(_operation, onPort, inputArguments, outputArguments);
	if (result != nullptr)
	{
		return result;
	}
	return result;
}

std::shared_ptr<Any> TextInputChannelImpl::dispatchCallOutOnInteractionPoint(const std::shared_ptr<uml::Operation>& _operation, const std::shared_ptr<PSCS::MDE4CPP_Extensions::PSCS_Object>& interactionPoint, const std::shared_ptr<Bag<Any>>& inputArguments, const std::shared_ptr<Bag<Any>>& outputArguments)
{
	std::shared_ptr<Bag<fUML::MDE4CPP_Extensions::FUML_Object>> targetsForDispatchingIn(new Bag<fUML::MDE4CPP_Extensions::FUML_Object>());
	std::shared_ptr<Bag<fUML::MDE4CPP_Extensions::FUML_Object>> targetsForDispatchingOut(new Bag<fUML::MDE4CPP_Extensions::FUML_Object>());
	
	const std::shared_ptr<Bag<fUML::MDE4CPP_Extensions::FUML_Link>>& allLinks = interactionPoint->getLinks();
	for(const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Link>& link : *allLinks)
	{
		std::shared_ptr<PSCS::MDE4CPP_Extensions::PSCS_Link> cS_Link = std::dynamic_pointer_cast<PSCS::MDE4CPP_Extensions::PSCS_Link>(link);
		PSCS::Semantics::StructuredClassifiers::CS_LinkKind linkKind = cS_Link->retrieveLinkKind(interactionPoint);
		if(linkKind == PSCS::Semantics::StructuredClassifiers::CS_LinkKind::UNKNOWN)
		{
			// LinkKind has to be calculated
			linkKind = this->retrieveLinkKind(cS_Link, interactionPoint);
			cS_Link->assignLinkKind(interactionPoint, linkKind);
		}
		if(linkKind == PSCS::Semantics::StructuredClassifiers::CS_LinkKind::TOENVIRONMENT)
		{
			std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object> otherEndValue = cS_Link->retrieveOtherLinkEndValue(interactionPoint->getDefiningPort());
			std::shared_ptr<PSCS::MDE4CPP_Extensions::PSCS_Object> cS_Object = std::dynamic_pointer_cast<PSCS::MDE4CPP_Extensions::PSCS_Object>(otherEndValue);

			if(!(cS_Object->isInteractionPoint()))
			{
				if(PSCS::MDE4CPP_Extensions::PSCS_ObjectImpl::isOperationProvided(cS_Object, _operation))
				{
					targetsForDispatchingIn->add(cS_Object);
				}
			}
			else
			{
				bool isAssembly = true, isDelegation = false;
				
				switch(cS_Object->getDefiningPort()->_getID())
				{
				}
				
				if(isAssembly)
				{
					if(PSCS::MDE4CPP_Extensions::PSCS_ObjectImpl::isOperationProvided(cS_Object, _operation))
					{
						targetsForDispatchingIn->add(cS_Object);
					}
				}
				if(isDelegation)
				{
					if(PSCS::MDE4CPP_Extensions::PSCS_ObjectImpl::isOperationRequired(cS_Object, _operation))
					{
						targetsForDispatchingOut->add(cS_Object);
					}
				}
			}
		}
	}

	unsigned int numOfTargetsToDispatchInTo = targetsForDispatchingIn->size();
	unsigned int numOfTargetsToDispatchOutTo = targetsForDispatchingOut->size();

	std::shared_ptr<Any> result = nullptr;
	
	for(unsigned int i = 0; i < numOfTargetsToDispatchInTo && result == nullptr; i++)
	{
		result = targetsForDispatchingIn->at(i)->dispatchCall(_operation, inputArguments, outputArguments);
	}
	for(unsigned int i = 0; i < numOfTargetsToDispatchOutTo && result == nullptr; i++)
	{
		std::shared_ptr<PSCS::MDE4CPP_Extensions::PSCS_Object> cS_Object = std::dynamic_pointer_cast<PSCS::MDE4CPP_Extensions::PSCS_Object>(targetsForDispatchingOut->at(i));
		if(cS_Object->isInteractionPoint())
		{
			std::shared_ptr<PSCS::MDE4CPP_Extensions::PSCS_Object> compositeOwner = cS_Object->getCompositeOwner();
			result = compositeOwner->dispatchCallOutOnInteractionPoint(_operation, cS_Object, inputArguments, outputArguments);
		}
	}
	
	return result;
}

std::shared_ptr<PSCS::MDE4CPP_Extensions::PSCS_Object> TextInputChannelImpl::getCompositeOwner()
{
	std::shared_ptr<PSCS::MDE4CPP_Extensions::PSCS_Object> compositeOwner = nullptr;

	return nullptr;
}

bool TextInputChannelImpl::isOperationProvided(const std::shared_ptr<uml::Operation>& operation)
{
	bool isProvided = false;
	if(this->isInteractionPoint()) // For interaction points, only realized interfaces are taken into account
	{
	}
	else
	{
		throw std::runtime_error("Now we are here...: " + std::string(__PRETTY_FUNCTION__));
	}
	if(!isProvided)
	{
		//Call isOperationProvided() for base class InputChannel
		isProvided = FoundationalModelLibrary::BasicInputOutput::InputChannelImpl::isOperationProvided(operation);
	}
	return isProvided;
}

bool TextInputChannelImpl::isOperationRequired(const std::shared_ptr<uml::Operation>& operation)
{
	bool isRequired = false;
	if(!isRequired)
	{
		//Call isOperationRequired() for base class InputChannel
		isRequired = FoundationalModelLibrary::BasicInputOutput::InputChannelImpl::isOperationRequired(operation);
	}
	return isRequired;
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
std::shared_ptr<Any> TextInputChannelImpl::remove(const std::shared_ptr<uml::Property>& _property, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	return this->remove(_property->_getID(), value, removeAt, isRemoveDuplicates);
}

std::shared_ptr<Any> TextInputChannelImpl::remove(std::string _qualifiedName, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	unsigned long uID = util::Util::polynomialRollingHash(_qualifiedName);
	return this->remove(uID, value, removeAt, isRemoveDuplicates);
}

std::shared_ptr<Any> TextInputChannelImpl::remove(unsigned long _uID, const std::shared_ptr<Any>& value, int removeAt /*= -1*/, bool isRemoveDuplicates /*= false*/)
{
	std::shared_ptr<Any> removedValue = nullptr;
	//Call set() for base class InputChannel
	removedValue = FoundationalModelLibrary::BasicInputOutput::InputChannelImpl::remove(_uID, value, removeAt, isRemoveDuplicates);
	if(removedValue) return removedValue;
	return removedValue;
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
