
#include "fUML/Semantics/CommonBehavior/impl/SignalEventOccurrenceImpl.hpp"
#ifdef NDEBUG
	#define DEBUG_INFO(a)		/**/
	#define DEBUG_WARNING(a)	/**/
	#define DEBUG_ERROR(a)		/**/
#else
	#define DEBUG_INFO(a) 		std::cout<<"[\e[0;32mInfo\e[0m]:\t\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_WARNING(a) 	std::cout<<"[\e[0;33mWarning\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_ERROR(a)		std::cout<<"[\e[0;31mError\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

//#include "util/ProfileCallCount.hpp"

#include <cassert>
#include <iostream>
#include <sstream>

#include "abstractDataTypes/Bag.hpp"


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
#include "ecore/ecoreFactory.hpp"
//Includes from codegen annotation
#include "uml/Class.hpp"
#include "uml/Signal.hpp"
#include "uml/SignalEvent.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsFactory.hpp"
#include "uml/Element.hpp"
#include "uml/Event.hpp"
#include "fUML/Semantics/CommonBehavior/EventOccurrence.hpp"
#include "fUML/MDE4CPP_Extensions/FUML_SignalInstance.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
#include "uml/Trigger.hpp"
//Factories and Package includes
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::CommonBehavior;

//*********************************
// Constructor / Destructor
//*********************************
SignalEventOccurrenceImpl::SignalEventOccurrenceImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

SignalEventOccurrenceImpl::~SignalEventOccurrenceImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete SignalEventOccurrence "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


SignalEventOccurrenceImpl::SignalEventOccurrenceImpl(const SignalEventOccurrenceImpl & obj): SignalEventOccurrenceImpl()
{
	*this = obj;
}

SignalEventOccurrenceImpl& SignalEventOccurrenceImpl::operator=(const SignalEventOccurrenceImpl & obj)
{
	//call overloaded =Operator for each base class
	EventOccurrenceImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of SignalEventOccurrence 
	 * which is generated by the compiler (as SignalEventOccurrence is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//SignalEventOccurrence::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy SignalEventOccurrence "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_signalInstance  = obj.getSignalInstance();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> SignalEventOccurrenceImpl::copy() const
{
	std::shared_ptr<SignalEventOccurrenceImpl> element(new SignalEventOccurrenceImpl());
	*element =(*this);
	element->setThisSignalEventOccurrencePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> SignalEventOccurrenceImpl::getParameterValues(const std::shared_ptr<uml::Event>& event)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Return parameter values for the features of the signal instance, in order, corresponding to the attributes of the declared signal of the given event
	// These are intended to be treated as if they are the values of effective parameters of the direction "in".
	// (Note that the given event must be a signal event, and the signal instance of this signal event occurence must be a direct or indirect instance of the event signal.)

	std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> parameterValues(new Bag<fUML::Semantics::CommonBehavior::ParameterValue>());
	const std::shared_ptr<uml::SignalEvent>& signalEvent = std::dynamic_pointer_cast<uml::SignalEvent>(event);
	if(signalEvent)
	{
		DEBUG_INFO("Found Signal Event, passing ParameterValues on.")

		const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_SignalInstance>& signalInstance = this->getSignalInstance();
		std::shared_ptr<Bag<uml::Property>> memberFeatures = signalInstance->getType()->getAllAttributes();

		for(const std::shared_ptr<uml::Property>& feature : *memberFeatures)
		{
			std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> parameterValue(fUML::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createParameterValue());
			std::shared_ptr<Any> value = signalInstance->get(feature);
			
			parameterValue->getValues()->add(value);
			parameterValues->add(parameterValue);
		}
	}
	return parameterValues;
	//end of body
}

bool SignalEventOccurrenceImpl::match(const std::shared_ptr<uml::Trigger>& trigger)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Match a trigger if it references a signal event whose signal is the type of the signal instance or one of its supertypes.

	bool matches = false;
	std::shared_ptr<uml::SignalEvent> signalEvent = std::dynamic_pointer_cast<uml::SignalEvent>(trigger->getEvent());
	if(signalEvent)
	{
		DEBUG_INFO("Found a SignalEvent, trying to match.")

		const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_SignalInstance>& signalInstance = this->getSignalInstance();

		matches = (signalInstance->getType()->_getID() == signalEvent->getSignal()->_getID());
	}
	return matches;
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference signalInstance */
const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_SignalInstance>& SignalEventOccurrenceImpl::getSignalInstance() const
{
    return m_signalInstance;
}
void SignalEventOccurrenceImpl::setSignalInstance(const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_SignalInstance>& _signalInstance)
{
    m_signalInstance = _signalInstance;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> SignalEventOccurrenceImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void SignalEventOccurrenceImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get fUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void SignalEventOccurrenceImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("signalInstance");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("signalInstance")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}

	EventOccurrenceImpl::loadAttributes(loadHandler, attr_list);
}

void SignalEventOccurrenceImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	EventOccurrenceImpl::loadNode(nodeName, loadHandler);
}

void SignalEventOccurrenceImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::SIGNALEVENTOCCURRENCE_ATTRIBUTE_SIGNALINSTANCE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_SignalInstance> _signalInstance = std::dynamic_pointer_cast<fUML::MDE4CPP_Extensions::FUML_SignalInstance>( references.front() );
				setSignalInstance(_signalInstance);
			}
			
			return;
		}
	}
	EventOccurrenceImpl::resolveReferences(featureID, references);
}

void SignalEventOccurrenceImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	EventOccurrenceImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void SignalEventOccurrenceImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::CommonBehavior::CommonBehaviorPackage> package = fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance();
	// Add references
	if ( this->eIsSet(package->getSignalEventOccurrence_Attribute_signalInstance()) )
	{
		saveHandler->addReference(this->getSignalInstance(), "signalInstance", getSignalInstance()->eClass() != fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_SignalInstance_Class()); 
	}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& SignalEventOccurrenceImpl::eStaticClass() const
{
	return fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getSignalEventOccurrence_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> SignalEventOccurrenceImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::SIGNALEVENTOCCURRENCE_ATTRIBUTE_SIGNALINSTANCE:
			return eAny(getSignalInstance(),fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::FUML_SIGNALINSTANCE_CLASS,false); //1091
	}
	return EventOccurrenceImpl::eGet(featureID, resolve, coreType);
}

bool SignalEventOccurrenceImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::SIGNALEVENTOCCURRENCE_ATTRIBUTE_SIGNALINSTANCE:
			return getSignalInstance() != nullptr; //1091
	}
	return EventOccurrenceImpl::internalEIsSet(featureID);
}

bool SignalEventOccurrenceImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::SIGNALEVENTOCCURRENCE_ATTRIBUTE_SIGNALINSTANCE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_SignalInstance> _signalInstance = std::dynamic_pointer_cast<fUML::MDE4CPP_Extensions::FUML_SignalInstance>(eObject);
					if(_signalInstance)
					{
						setSignalInstance(_signalInstance); //1091
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'signalInstance'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'signalInstance'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return EventOccurrenceImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> SignalEventOccurrenceImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// fUML::Semantics::CommonBehavior::SignalEventOccurrence::getParameterValues(uml::Event) : fUML::Semantics::CommonBehavior::ParameterValue[*]: 1942312597
		case CommonBehaviorPackage::SIGNALEVENTOCCURRENCE_OPERATION_GETPARAMETERVALUES_EVENT:
		{
			//Retrieve input parameter 'event'
			//parameter 0
			std::shared_ptr<uml::Event> incoming_param_event;
			Bag<Any>::const_iterator incoming_param_event_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_event_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_event = std::dynamic_pointer_cast<uml::Event>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'event'. Failed to invoke operation 'getParameterValues'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'event'. Failed to invoke operation 'getParameterValues'!")
					return nullptr;
				}
			}
		
			std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> resultList = this->getParameterValues(incoming_param_event);
			return eEcoreContainerAny(resultList,fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_CLASS);
			break;
		}
		// fUML::Semantics::CommonBehavior::SignalEventOccurrence::match(uml::Trigger) : bool: 2137384271
		case CommonBehaviorPackage::SIGNALEVENTOCCURRENCE_OPERATION_MATCH_TRIGGER:
		{
			//Retrieve input parameter 'trigger'
			//parameter 0
			std::shared_ptr<uml::Trigger> incoming_param_trigger;
			Bag<Any>::const_iterator incoming_param_trigger_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_trigger_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_trigger = std::dynamic_pointer_cast<uml::Trigger>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'trigger'. Failed to invoke operation 'match'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'trigger'. Failed to invoke operation 'match'!")
					return nullptr;
				}
			}
		
			result = eAny(this->match(incoming_param_trigger), 0, false);
			break;
		}

		default:
		{
			// call superTypes
			result = EventOccurrenceImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::CommonBehavior::SignalEventOccurrence> SignalEventOccurrenceImpl::getThisSignalEventOccurrencePtr() const
{
	return m_thisSignalEventOccurrencePtr.lock();
}
void SignalEventOccurrenceImpl::setThisSignalEventOccurrencePtr(std::weak_ptr<fUML::Semantics::CommonBehavior::SignalEventOccurrence> thisSignalEventOccurrencePtr)
{
	m_thisSignalEventOccurrencePtr = thisSignalEventOccurrencePtr;
	setThisEventOccurrencePtr(thisSignalEventOccurrencePtr);
}


