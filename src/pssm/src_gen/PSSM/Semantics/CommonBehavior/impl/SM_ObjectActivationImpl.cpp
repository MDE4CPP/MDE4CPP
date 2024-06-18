
#include "PSSM/Semantics/CommonBehavior/impl/SM_ObjectActivationImpl.hpp"
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
#include "fUML/FUMLFactory.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsFactory.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
#include "PSSM/Semantics/StateMachines/StateMachinesFactory.hpp"
#include "fUML/Semantics/CommonBehavior/ClassifierBehaviorExecution.hpp"
#include "PSSM/Semantics/StateMachines/CompletionEventOccurrence.hpp"
#include "PSSM/Semantics/StateMachines/DeferredEventOccurrence.hpp"
#include "fUML/Semantics/CommonBehavior/EventAccepter.hpp"
#include "fUML/Semantics/CommonBehavior/EventOccurrence.hpp"
#include "fUML/MDE4CPP_Extensions/FUML_Object.hpp"
#include "fUML/Semantics/CommonBehavior/ObjectActivation.hpp"
#include "PSSM/Semantics/StateMachines/StateActivation.hpp"
//Factories and Package includes
#include "PSSM/PSSMPackage.hpp"
#include "PSSM/Semantics/SemanticsPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "PSSM/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsPackage.hpp"
#include "PSSM/Semantics/StateMachines/StateMachinesPackage.hpp"

using namespace PSSM::Semantics::CommonBehavior;

//*********************************
// Constructor / Destructor
//*********************************
SM_ObjectActivationImpl::SM_ObjectActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

SM_ObjectActivationImpl::~SM_ObjectActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete SM_ObjectActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


SM_ObjectActivationImpl::SM_ObjectActivationImpl(const SM_ObjectActivationImpl & obj): SM_ObjectActivationImpl()
{
	*this = obj;
}

SM_ObjectActivationImpl& SM_ObjectActivationImpl::operator=(const SM_ObjectActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::CommonBehavior::ObjectActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of SM_ObjectActivation 
	 * which is generated by the compiler (as SM_ObjectActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//SM_ObjectActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy SM_ObjectActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_deferredEventPool  = obj.getDeferredEventPool();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> SM_ObjectActivationImpl::copy() const
{
	std::shared_ptr<SM_ObjectActivationImpl> element(new SM_ObjectActivationImpl());
	*element =(*this);
	element->setThisSM_ObjectActivationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
int SM_ObjectActivationImpl::getDeferredEventInsertionIndex()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Deferred events are always registered after completion events if any.
	// Return the insertion point for deferred events.
	for (const auto& event : *(m_eventPool))
	{
		if (const auto& deferredEvent = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::DeferredEventOccurrence>(event)) 
		{
			return m_eventPool->index_of(event);
		}
	}
	return -1;
	//end of body
}

std::shared_ptr<PSSM::Semantics::StateMachines::CompletionEventOccurrence> SM_ObjectActivationImpl::getNextCompletionEvent()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	for (const auto& eventOccurrence : *(this->m_eventPool))
	{
		if (const auto& completionEventOccurence = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::CompletionEventOccurrence>(eventOccurrence))
		{
			// Delete EventOccurrence from the Event Pool here as fUML::ObjectActivation::retrieveNextEvent is not called for CompletionEventOccurrences.
			this->m_eventPool->erase(completionEventOccurence);
			return completionEventOccurence;
		}
	}
	return nullptr;
	//end of body
}

void SM_ObjectActivationImpl::registerCompletionEvent(const std::shared_ptr<PSSM::Semantics::StateMachines::StateActivation>& stateActivation)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Create a CompletionEvent for the given StateActivation
	const auto& completionEventOccurrence(PSSM::Semantics::StateMachines::StateMachinesFactory::eInstance()->createCompletionEventOccurrence());
	completionEventOccurrence->setStateActivation(stateActivation);
	
	// Place it in the Event Pool
	std::unique_lock lock(*m_mutex);
	this->m_eventPool->push_back(completionEventOccurrence);
	lock.unlock();	

	DEBUG_INFO("StateActivation " << stateActivation << " registered an CompletionEventOccurrence!")
	this->m_conditionVariable->notify_one();
	//end of body
}

void SM_ObjectActivationImpl::registerDeferredEvent(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence, const std::shared_ptr<PSSM::Semantics::StateMachines::StateActivation>& stateActivation)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// An event occurrence registered as being deferred is registered within the deferred event pool.
//DeferredEventOccurrence deferredEventOccurrence = new DeferredEventOccurrence();
//deferredEventOccurrence.constrainingStateActivation = deferringState;
//deferredEventOccurrence.deferredEventOccurrence = eventOccurrence;
//this.deferredEventPool.add(deferredEventOccurrence);

//std::shared_ptr<PSSM::Semantics::StateMachines::DeferredEventOccurrence> deferredEventOccurrence = new PSSM::Semantics::StateMachines::DeferredEventOccurrence();
//deferredEventOccurrence->setDeferredEventOccurrence(eventOccurrence);
//this->m_deferredEventPool->add(deferredEventOccurrence);
	//end of body
}

void SM_ObjectActivationImpl::releaseDeferredEvents(const std::shared_ptr<PSSM::Semantics::StateMachines::StateActivation>& deferringState)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// The release of event occurrence(s) deferred by the deferring state implIncludes the following step:...
	//end of body
}

std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> SM_ObjectActivationImpl::retrieveNextEvent()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// REPLACES GETNEXTEVENT()
	// Redefinition of fUML::ObjectActivation to accommodate to priorities of PSSM-specific EventOccurrences:
	// All CompletionEventOccurrences are dispatched first. They are dispatched according to their order of arrival in the pool. 
	// Only if no CompletionEventOccurrences are in the pool, then regular EventOccurrences are dispatched according to the set dispatching policy. 
	// Note that if the currently dispatched EventOccurrence was previously deferred, 
	// then it is unwrapped and its encapsulated 'deferredEventOccurrence' is actually dispatched.
	auto nextEvent = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::EventOccurrence>(this->getNextCompletionEvent());
	if(nextEvent == nullptr)
	{
		nextEvent = this->getThisObjectActivationPtr()->retrieveNextEvent();

		auto deferredEvent = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::DeferredEventOccurrence>(nextEvent);

		if( deferredEvent != nullptr)
		{
			nextEvent =  deferredEvent->getDeferredEventOccurrence();
		}
	}

	return nextEvent;
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference deferredEventPool */
const std::shared_ptr<Bag<PSSM::Semantics::StateMachines::DeferredEventOccurrence>>& SM_ObjectActivationImpl::getDeferredEventPool() const
{
	if(m_deferredEventPool == nullptr)
	{
		m_deferredEventPool.reset(new Bag<PSSM::Semantics::StateMachines::DeferredEventOccurrence>());
		
		
	}
    return m_deferredEventPool;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> SM_ObjectActivationImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void SM_ObjectActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void SM_ObjectActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("deferredEventPool");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("deferredEventPool")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	fUML::Semantics::CommonBehavior::ObjectActivationImpl::loadAttributes(loadHandler, attr_list);
}

void SM_ObjectActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::CommonBehavior::ObjectActivationImpl::loadNode(nodeName, loadHandler);
}

void SM_ObjectActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::SM_OBJECTACTIVATION_ATTRIBUTE_DEFERREDEVENTPOOL:
		{
			const std::shared_ptr<Bag<PSSM::Semantics::StateMachines::DeferredEventOccurrence>>& _deferredEventPool = getDeferredEventPool();
			for(const std::shared_ptr<ecore::EObject>& ref : references)
			{
				std::shared_ptr<PSSM::Semantics::StateMachines::DeferredEventOccurrence>  _r = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::DeferredEventOccurrence>(ref);
				if (_r != nullptr)
				{
					_deferredEventPool->push_back(_r);
				}
			}
			return;
		}
	}
	fUML::Semantics::CommonBehavior::ObjectActivationImpl::resolveReferences(featureID, references);
}

void SM_ObjectActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::CommonBehavior::ObjectActivationImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void SM_ObjectActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSSM::Semantics::CommonBehavior::CommonBehaviorPackage> package = PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance();
	// Add references
	if ( this->eIsSet(package->getSM_ObjectActivation_Attribute_deferredEventPool()) )
	{
		saveHandler->addReferences<PSSM::Semantics::StateMachines::DeferredEventOccurrence>("deferredEventPool", this->getDeferredEventPool());
	}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& SM_ObjectActivationImpl::eStaticClass() const
{
	return PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getSM_ObjectActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> SM_ObjectActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::SM_OBJECTACTIVATION_ATTRIBUTE_DEFERREDEVENTPOOL:
			return eEcoreContainerAny(getDeferredEventPool(),PSSM::Semantics::StateMachines::StateMachinesPackage::DEFERREDEVENTOCCURRENCE_CLASS); //307
	}
	return fUML::Semantics::CommonBehavior::ObjectActivationImpl::eGet(featureID, resolve, coreType);
}

bool SM_ObjectActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::SM_OBJECTACTIVATION_ATTRIBUTE_DEFERREDEVENTPOOL:
			return getDeferredEventPool() != nullptr; //307
	}
	return fUML::Semantics::CommonBehavior::ObjectActivationImpl::internalEIsSet(featureID);
}

bool SM_ObjectActivationImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::SM_OBJECTACTIVATION_ATTRIBUTE_DEFERREDEVENTPOOL:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<PSSM::Semantics::StateMachines::DeferredEventOccurrence>>& _deferredEventPool = getDeferredEventPool();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<PSSM::Semantics::StateMachines::DeferredEventOccurrence> valueToAdd = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::DeferredEventOccurrence>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_deferredEventPool->includes(valueToAdd)))
								{
									_deferredEventPool->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'deferredEventPool'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'deferredEventPool'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return fUML::Semantics::CommonBehavior::ObjectActivationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> SM_ObjectActivationImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// PSSM::Semantics::CommonBehavior::SM_ObjectActivation::getDeferredEventInsertionIndex() : int: 2452174763
		case CommonBehaviorPackage::SM_OBJECTACTIVATION_OPERATION_GETDEFERREDEVENTINSERTIONINDEX:
		{
			result = eAny(this->getDeferredEventInsertionIndex(), 0, false);
			break;
		}
		// PSSM::Semantics::CommonBehavior::SM_ObjectActivation::getNextCompletionEvent() : PSSM::Semantics::StateMachines::CompletionEventOccurrence: 1073996637
		case CommonBehaviorPackage::SM_OBJECTACTIVATION_OPERATION_GETNEXTCOMPLETIONEVENT:
		{
			result = eEcoreAny(this->getNextCompletionEvent(), PSSM::Semantics::StateMachines::StateMachinesPackage::COMPLETIONEVENTOCCURRENCE_CLASS);
			break;
		}
		// PSSM::Semantics::CommonBehavior::SM_ObjectActivation::registerCompletionEvent(PSSM::Semantics::StateMachines::StateActivation): 4147294447
		case CommonBehaviorPackage::SM_OBJECTACTIVATION_OPERATION_REGISTERCOMPLETIONEVENT_STATEACTIVATION:
		{
			//Retrieve input parameter 'stateActivation'
			//parameter 0
			std::shared_ptr<PSSM::Semantics::StateMachines::StateActivation> incoming_param_stateActivation;
			Bag<Any>::const_iterator incoming_param_stateActivation_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_stateActivation_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_stateActivation = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::StateActivation>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'stateActivation'. Failed to invoke operation 'registerCompletionEvent'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'stateActivation'. Failed to invoke operation 'registerCompletionEvent'!")
					return nullptr;
				}
			}
		
			this->registerCompletionEvent(incoming_param_stateActivation);
			break;
		}
		// PSSM::Semantics::CommonBehavior::SM_ObjectActivation::registerDeferredEvent(fUML::Semantics::CommonBehavior::EventOccurrence, PSSM::Semantics::StateMachines::StateActivation): 376833885
		case CommonBehaviorPackage::SM_OBJECTACTIVATION_OPERATION_REGISTERDEFERREDEVENT_EVENTOCCURRENCE_STATEACTIVATION:
		{
			//Retrieve input parameter 'eventOccurrence'
			//parameter 0
			std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> incoming_param_eventOccurrence;
			Bag<Any>::const_iterator incoming_param_eventOccurrence_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_eventOccurrence_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_eventOccurrence = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::EventOccurrence>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'eventOccurrence'. Failed to invoke operation 'registerDeferredEvent'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'eventOccurrence'. Failed to invoke operation 'registerDeferredEvent'!")
					return nullptr;
				}
			}
		
			//Retrieve input parameter 'stateActivation'
			//parameter 1
			std::shared_ptr<PSSM::Semantics::StateMachines::StateActivation> incoming_param_stateActivation;
			Bag<Any>::const_iterator incoming_param_stateActivation_arguments_citer = std::next(arguments->begin(), 1);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_stateActivation_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_stateActivation = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::StateActivation>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'stateActivation'. Failed to invoke operation 'registerDeferredEvent'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'stateActivation'. Failed to invoke operation 'registerDeferredEvent'!")
					return nullptr;
				}
			}
		
			this->registerDeferredEvent(incoming_param_eventOccurrence,incoming_param_stateActivation);
			break;
		}
		// PSSM::Semantics::CommonBehavior::SM_ObjectActivation::releaseDeferredEvents(PSSM::Semantics::StateMachines::StateActivation): 1259910129
		case CommonBehaviorPackage::SM_OBJECTACTIVATION_OPERATION_RELEASEDEFERREDEVENTS_STATEACTIVATION:
		{
			//Retrieve input parameter 'deferringState'
			//parameter 0
			std::shared_ptr<PSSM::Semantics::StateMachines::StateActivation> incoming_param_deferringState;
			Bag<Any>::const_iterator incoming_param_deferringState_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_deferringState_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_deferringState = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::StateActivation>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'deferringState'. Failed to invoke operation 'releaseDeferredEvents'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'deferringState'. Failed to invoke operation 'releaseDeferredEvents'!")
					return nullptr;
				}
			}
		
			this->releaseDeferredEvents(incoming_param_deferringState);
			break;
		}
		// PSSM::Semantics::CommonBehavior::SM_ObjectActivation::retrieveNextEvent() : fUML::Semantics::CommonBehavior::EventOccurrence: 2170540068
		case CommonBehaviorPackage::SM_OBJECTACTIVATION_OPERATION_RETRIEVENEXTEVENT:
		{
			result = eEcoreAny(this->retrieveNextEvent(), fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EVENTOCCURRENCE_CLASS);
			break;
		}

		default:
		{
			// call superTypes
			result = fUML::Semantics::CommonBehavior::ObjectActivationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<PSSM::Semantics::CommonBehavior::SM_ObjectActivation> SM_ObjectActivationImpl::getThisSM_ObjectActivationPtr() const
{
	return m_thisSM_ObjectActivationPtr.lock();
}
void SM_ObjectActivationImpl::setThisSM_ObjectActivationPtr(std::weak_ptr<PSSM::Semantics::CommonBehavior::SM_ObjectActivation> thisSM_ObjectActivationPtr)
{
	m_thisSM_ObjectActivationPtr = thisSM_ObjectActivationPtr;
	setThisObjectActivationPtr(thisSM_ObjectActivationPtr);
}


