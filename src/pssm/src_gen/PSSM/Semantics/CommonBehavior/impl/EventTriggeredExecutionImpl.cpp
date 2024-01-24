
#include "PSSM/Semantics/CommonBehavior/impl/EventTriggeredExecutionImpl.hpp"
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
#include <stdexcept>
#include "abstractDataTypes/Subset.hpp"


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
#include "fUML/FUMLFactory.hpp"
#include "fUML/MDE4CPP_Extensions/FUML_SignalInstance.hpp"
#include "fUML/Semantics/CommonBehavior/SignalEventOccurrence.hpp"
#include "PSSM/Semantics/CommonBehavior/CallEventOccurrence.hpp"
#include "PSSM/Semantics/CommonBehavior/CallEventExecution.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "ecore/ecoreFactory.hpp"
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsFactory.hpp"
#include "uml/Behavior.hpp"
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "ecore/EAnnotation.hpp"
#include "uml/Element.hpp"
#include "fUML/Semantics/CommonBehavior/EventOccurrence.hpp"
#include "fUML/Semantics/CommonBehavior/Execution.hpp"
#include "fUML/MDE4CPP_Extensions/FUML_Object.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/CommonBehavior/ObjectActivation.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
//Factories and Package includes
#include "PSSM/Semantics/SemanticsPackage.hpp"
#include "PSSM/PSSMPackage.hpp"
#include "PSSM/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "uml/umlPackage.hpp"

using namespace PSSM::Semantics::CommonBehavior;

//*********************************
// Constructor / Destructor
//*********************************
EventTriggeredExecutionImpl::EventTriggeredExecutionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

EventTriggeredExecutionImpl::~EventTriggeredExecutionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EventTriggeredExecution "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


EventTriggeredExecutionImpl::EventTriggeredExecutionImpl(const EventTriggeredExecutionImpl & obj): EventTriggeredExecutionImpl()
{
	*this = obj;
}

EventTriggeredExecutionImpl& EventTriggeredExecutionImpl::operator=(const EventTriggeredExecutionImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::CommonBehavior::ExecutionImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of EventTriggeredExecution 
	 * which is generated by the compiler (as EventTriggeredExecution is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//EventTriggeredExecution::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EventTriggeredExecution "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_triggeringEventOccurrence  = obj.getTriggeringEventOccurrence();
	m_wrappedExecution  = obj.getWrappedExecution();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> EventTriggeredExecutionImpl::copy() const
{
	std::shared_ptr<EventTriggeredExecutionImpl> element(new EventTriggeredExecutionImpl());
	*element =(*this);
	element->setThisEventTriggeredExecutionPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************


void EventTriggeredExecutionImpl::execute()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// The Behavior handled by the wrappedExecution is parameterized
	// with the input ParameterValues provided by the triggeringEventOccurrence.
	// The Behavior is then executed and finally, the outputParameterValues are passed to the triggeringEventOccurrence 
	// (only occurs in the case of a CallEventOccurrence).
	if(this->getWrappedExecution() != nullptr && this->getTriggeringEventOccurrence() != nullptr)
	{
		const auto& inputParameterValues = this->initialize(this->getWrappedExecution()->getBehavior());
		for (const auto& inputParameterValue : *inputParameterValues)
		{
			this->getWrappedExecution()->setParameterValue(inputParameterValue);
		}
		this->getWrappedExecution()->execute();
		this->finalize();
	}
	//end of body
}

void EventTriggeredExecutionImpl::finalize()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Transfer output ParameterValues (produced by the wrapped execution) back to
	// the Execution associated to the CallEventOccurrence.
	// If an effect, entry or exit Behavior is not just input-conforming, then the
	// values of its output Parameters are passed out of its Behavior Execution on
	// its completion as potential values for the output Parameters of the called 
	// Operation.
	// Notes: 
	//    If the CallEvent is for a synchronous call, then the call ends at the end
	//    of the triggered run-to-completion (RTC) step. If the called Operation has
	//    output Parameters, then the values returned for those parameters are those
	//    produced by the last effect, entry or exit Behavior to complete its execution
	//    during the RTC step. Since some or all of those Behaviors may execute concurrently,
	//    which one completes last may be only partially determined by the specified semantics.
	//    The values returned may legally be those produced any Behavior that produces potential
	//    output values and is the last to complete in any execution trace for the RTC
	//    step consistent with the specified StateMachine semantics.
	this->_beginIsolation();
	if (const auto& callEventOccurrence = std::dynamic_pointer_cast<PSSM::Semantics::CommonBehavior::CallEventOccurrence>(this->getTriggeringEventOccurrence()))
	{
		const auto& outputParameterValues = this->getWrappedExecution()->getOutputParameterValues();
		if(this->getWrappedExecution()->getBehavior()->outputParameters()->size() == outputParameterValues->size())
		{
			const auto& behaviorOutputParameters = callEventOccurrence->getExecution()->getBehavior()->outputParameters();
			for (unsigned int i = 0; i < behaviorOutputParameters->size(); ++i)
			{
				auto parameterValue = fUML::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createParameterValue();
				parameterValue->setParameter(behaviorOutputParameters->at(i));
				parameterValue->getValues()->insert(*(outputParameterValues->at(i)->getValues()));
				callEventOccurrence->getExecution()->setParameterValue(parameterValue);
			}
		}

	}
	this->_endIsolation();
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> EventTriggeredExecutionImpl::initialize(const std::shared_ptr<uml::Behavior>& behavior)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Transfer input parameter values of the call event execution
	// to the wrapped execution if possible. 
	// Two situations are considered:
	// 1. If the triggering EventOccurrence is for a SignalEvent, then all
	//    executed Behaviors will have either one parameter or no parameters.
	//    If the Behavior has one Parameter, the SignalInstance corresponding to
	//    the SignalEventOccurrence is returned to be passed into the Behavior Execution as
	//    the value of its parameter.
	// 2. If the triggering EventOccurrence is for a CallEvent, then all executed
	//    Behaviors will have either no Parameters or signatures that conform or
	//    input conform to the Operation being called.
	//    If a Behavior has parameters, then the values of the input parameters
	//    for the call are returned to be passed into the Behavior Execution as the values
	//    of the corresponding input parameters of the Behavior.
	this->_beginIsolation();
	auto parameterValues = std::make_shared<Bag<fUML::Semantics::CommonBehavior::ParameterValue>>();
	if (behavior->getOwnedParameter()->size() > 0)
	{
		if (const auto& signalEventOccurrence = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::SignalEventOccurrence>(this->getTriggeringEventOccurrence()))
		{
			if (behavior->inputParameters()->size() == 1)
			{
				auto parameterValue = fUML::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createParameterValue();
				parameterValue->setParameter(behavior->inputParameters()->at(0));
				parameterValue->getValues()->push_back(std::dynamic_pointer_cast<Any>(signalEventOccurrence->getSignalInstance()));
				parameterValues->push_back(parameterValue);
			}
		}
		else if (const auto& callEventOccurrence = std::dynamic_pointer_cast<PSSM::Semantics::CommonBehavior::CallEventOccurrence>(this->getTriggeringEventOccurrence()))
		{
			const auto& behaviorInputParameters = behavior->inputParameters();
			const auto& inputParameterValues = callEventOccurrence->getExecution()->getInputParameterValues();
			if (behaviorInputParameters->size() == inputParameterValues->size())
			{
				for (unsigned int i = 0; i < behaviorInputParameters->size(); ++i)
				{
					auto parameterValue = fUML::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createParameterValue();
					parameterValue->setParameter(behaviorInputParameters->at(i));
					parameterValue->getValues()->insert(*(inputParameterValues->at(i)->getValues()));
					parameterValues->push_back(parameterValue);
				}
			}
		}
	}
	this->_endIsolation();
	return parameterValues;
	//end of body
}



//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference triggeringEventOccurrence */
const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& EventTriggeredExecutionImpl::getTriggeringEventOccurrence() const
{
    return m_triggeringEventOccurrence;
}
void EventTriggeredExecutionImpl::setTriggeringEventOccurrence(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& _triggeringEventOccurrence)
{
    m_triggeringEventOccurrence = _triggeringEventOccurrence;
	
}

/* Getter & Setter for reference wrappedExecution */
const std::shared_ptr<fUML::Semantics::CommonBehavior::Execution>& EventTriggeredExecutionImpl::getWrappedExecution() const
{
    return m_wrappedExecution;
}
void EventTriggeredExecutionImpl::setWrappedExecution(const std::shared_ptr<fUML::Semantics::CommonBehavior::Execution>& _wrappedExecution)
{
    m_wrappedExecution = _wrappedExecution;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> EventTriggeredExecutionImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void EventTriggeredExecutionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get PSSMFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void EventTriggeredExecutionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("triggeringEventOccurrence");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("triggeringEventOccurrence")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("wrappedExecution");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("wrappedExecution")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	fUML::Semantics::CommonBehavior::ExecutionImpl::loadAttributes(loadHandler, attr_list);
}

void EventTriggeredExecutionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::CommonBehavior::ExecutionImpl::loadNode(nodeName, loadHandler);
}

void EventTriggeredExecutionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::EVENTTRIGGEREDEXECUTION_ATTRIBUTE_TRIGGERINGEVENTOCCURRENCE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> _triggeringEventOccurrence = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::EventOccurrence>( references.front() );
				setTriggeringEventOccurrence(_triggeringEventOccurrence);
			}
			
			return;
		}

		case PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::EVENTTRIGGEREDEXECUTION_ATTRIBUTE_WRAPPEDEXECUTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> _wrappedExecution = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::Execution>( references.front() );
				setWrappedExecution(_wrappedExecution);
			}
			
			return;
		}
	}
	fUML::Semantics::CommonBehavior::ExecutionImpl::resolveReferences(featureID, references);
}

void EventTriggeredExecutionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::CommonBehavior::ExecutionImpl::saveContent(saveHandler);
	
	fUML::MDE4CPP_Extensions::FUML_ObjectImpl::saveContent(saveHandler);
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	uml::ElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void EventTriggeredExecutionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSSM::Semantics::CommonBehavior::CommonBehaviorPackage> package = PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance();
	// Add references
	if ( this->eIsSet(package->getEventTriggeredExecution_Attribute_triggeringEventOccurrence()) )
	{
		saveHandler->addReference(this->getTriggeringEventOccurrence(), "triggeringEventOccurrence", getTriggeringEventOccurrence()->eClass() != fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventOccurrence_Class()); 
	}
	if ( this->eIsSet(package->getEventTriggeredExecution_Attribute_wrappedExecution()) )
	{
		saveHandler->addReference(this->getWrappedExecution(), "wrappedExecution", getWrappedExecution()->eClass() != fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getExecution_Class()); 
	}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& EventTriggeredExecutionImpl::eStaticClass() const
{
	return PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventTriggeredExecution_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> EventTriggeredExecutionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::EVENTTRIGGEREDEXECUTION_ATTRIBUTE_TRIGGERINGEVENTOCCURRENCE:
			return eAny(getTriggeringEventOccurrence(),fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EVENTOCCURRENCE_CLASS,false); //1313
		case PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::EVENTTRIGGEREDEXECUTION_ATTRIBUTE_WRAPPEDEXECUTION:
			return eAny(getWrappedExecution(),fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_CLASS,false); //1312
	}
	return fUML::Semantics::CommonBehavior::ExecutionImpl::eGet(featureID, resolve, coreType);
}

bool EventTriggeredExecutionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::EVENTTRIGGEREDEXECUTION_ATTRIBUTE_TRIGGERINGEVENTOCCURRENCE:
			return getTriggeringEventOccurrence() != nullptr; //1313
		case PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::EVENTTRIGGEREDEXECUTION_ATTRIBUTE_WRAPPEDEXECUTION:
			return getWrappedExecution() != nullptr; //1312
	}
	return fUML::Semantics::CommonBehavior::ExecutionImpl::internalEIsSet(featureID);
}

bool EventTriggeredExecutionImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::EVENTTRIGGEREDEXECUTION_ATTRIBUTE_TRIGGERINGEVENTOCCURRENCE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> _triggeringEventOccurrence = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::EventOccurrence>(eObject);
					if(_triggeringEventOccurrence)
					{
						setTriggeringEventOccurrence(_triggeringEventOccurrence); //1313
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'triggeringEventOccurrence'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'triggeringEventOccurrence'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::EVENTTRIGGEREDEXECUTION_ATTRIBUTE_WRAPPEDEXECUTION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> _wrappedExecution = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::Execution>(eObject);
					if(_wrappedExecution)
					{
						setWrappedExecution(_wrappedExecution); //1312
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'wrappedExecution'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'wrappedExecution'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return fUML::Semantics::CommonBehavior::ExecutionImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> EventTriggeredExecutionImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// PSSM::Semantics::CommonBehavior::EventTriggeredExecution::execute(): 3241661790
		case CommonBehaviorPackage::EVENTTRIGGEREDEXECUTION_OPERATION_EXECUTE:
		{
			this->execute();
			break;
		}
		// PSSM::Semantics::CommonBehavior::EventTriggeredExecution::finalize(): 4224883493
		case CommonBehaviorPackage::EVENTTRIGGEREDEXECUTION_OPERATION_FINALIZE:
		{
			this->finalize();
			break;
		}
		// PSSM::Semantics::CommonBehavior::EventTriggeredExecution::initialize(uml::Behavior) : fUML::Semantics::CommonBehavior::ParameterValue[*]: 846647309
		case CommonBehaviorPackage::EVENTTRIGGEREDEXECUTION_OPERATION_INITIALIZE_BEHAVIOR:
		{
			//Retrieve input parameter 'behavior'
			//parameter 0
			std::shared_ptr<uml::Behavior> incoming_param_behavior;
			Bag<Any>::const_iterator incoming_param_behavior_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_behavior_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_behavior = std::dynamic_pointer_cast<uml::Behavior>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'behavior'. Failed to invoke operation 'initialize'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'behavior'. Failed to invoke operation 'initialize'!")
					return nullptr;
				}
			}
		
			std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> resultList = this->initialize(incoming_param_behavior);
			return eEcoreContainerAny(resultList,fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_CLASS);
			break;
		}

		default:
		{
			// call superTypes
			result = fUML::Semantics::CommonBehavior::ExecutionImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<PSSM::Semantics::CommonBehavior::EventTriggeredExecution> EventTriggeredExecutionImpl::getThisEventTriggeredExecutionPtr() const
{
	return m_thisEventTriggeredExecutionPtr.lock();
}
void EventTriggeredExecutionImpl::setThisEventTriggeredExecutionPtr(std::weak_ptr<PSSM::Semantics::CommonBehavior::EventTriggeredExecution> thisEventTriggeredExecutionPtr)
{
	m_thisEventTriggeredExecutionPtr = thisEventTriggeredExecutionPtr;
	setThisExecutionPtr(thisEventTriggeredExecutionPtr);
}

