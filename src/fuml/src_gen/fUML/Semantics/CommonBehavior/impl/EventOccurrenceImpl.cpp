
#include "fUML/Semantics/CommonBehavior/impl/EventOccurrenceImpl.hpp"
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
#include "fUML/MDE4CPP_Extensions/FUML_Object.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "uml/Element.hpp"
#include "uml/Event.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
#include "uml/Trigger.hpp"
//Factories and Package includes
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::CommonBehavior;

//*********************************
// Constructor / Destructor
//*********************************
EventOccurrenceImpl::EventOccurrenceImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

EventOccurrenceImpl::~EventOccurrenceImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EventOccurrence "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


EventOccurrenceImpl::EventOccurrenceImpl(const EventOccurrenceImpl & obj): EventOccurrenceImpl()
{
	*this = obj;
}

EventOccurrenceImpl& EventOccurrenceImpl::operator=(const EventOccurrenceImpl & obj)
{
	//call overloaded =Operator for each base class
	ecore::EModelElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of EventOccurrence 
	 * which is generated by the compiler (as EventOccurrence is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//EventOccurrence::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EventOccurrence "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_target  = obj.getTarget();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> EventOccurrenceImpl::copy() const
{
	std::shared_ptr<EventOccurrenceImpl> element(new EventOccurrenceImpl());
	*element =(*this);
	element->setThisEventOccurrencePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
void EventOccurrenceImpl::doSend()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Send this event occurrence to the target reference.

	const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object>& target = std::dynamic_pointer_cast<fUML::MDE4CPP_Extensions::FUML_Object>(this->getTarget());
	if(target != nullptr)
	{
		DEBUG_INFO("found target != nullptr, sending...")
		target->send(getThisEventOccurrencePtr());
	}
	else
	{
		DEBUG_INFO(" no target found..")
	}
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> EventOccurrenceImpl::getParameterValues(const std::shared_ptr<uml::Event>& event)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool EventOccurrenceImpl::match(const std::shared_ptr<uml::Trigger>& trigger)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool EventOccurrenceImpl::matchAny(const std::shared_ptr<Bag<uml::Trigger>>& triggers)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Check that at least one of the given triggers is matched by this event occurrence.

	bool matches = false;
	if(triggers != nullptr)
	{
		DEBUG_INFO("Found some Triggers. Matching...")

		for(const std::shared_ptr<uml::Trigger>& trigger : *triggers)
		{
			if(match(trigger))
			{
				DEBUG_INFO("Found a matching Trigger.")

				matches = true;
				break;
			}
		}
	}
	return matches;
	//end of body
}

void EventOccurrenceImpl::sendTo(const std::shared_ptr<uml::Element>& target)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Set the target reference and send this directly to it
	// instead of invoking an extra SendingBehavior for efficiency reasons
	this->setTarget(target);
	DEBUG_INFO("Sending an EventOccurrence...")
	this->doSend(); //this->_startObjectBehavior();
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference target */
const std::shared_ptr<uml::Element>& EventOccurrenceImpl::getTarget() const
{
    return m_target;
}
void EventOccurrenceImpl::setTarget(const std::shared_ptr<uml::Element>& _target)
{
    m_target = _target;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> EventOccurrenceImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void EventOccurrenceImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void EventOccurrenceImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("target");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("target")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ecore::EObjectImpl::loadAttributes(loadHandler, attr_list);
}

void EventOccurrenceImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
}

void EventOccurrenceImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EVENTOCCURRENCE_ATTRIBUTE_TARGET:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Element> _target = std::dynamic_pointer_cast<uml::Element>( references.front() );
				setTarget(_target);
			}
			
			return;
		}
	}
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void EventOccurrenceImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ecore::EObjectImpl::saveContent(saveHandler);
}

void EventOccurrenceImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::CommonBehavior::CommonBehaviorPackage> package = fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance();
	// Add references
	if ( this->eIsSet(package->getEventOccurrence_Attribute_target()) )
	{
		saveHandler->addReference(this->getTarget(), "target", getTarget()->eClass() != uml::umlPackage::eInstance()->getElement_Class()); 
	}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& EventOccurrenceImpl::eStaticClass() const
{
	return fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventOccurrence_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> EventOccurrenceImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EVENTOCCURRENCE_ATTRIBUTE_TARGET:
			return eAny(getTarget(),uml::umlPackage::ELEMENT_CLASS,false); //450
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}

bool EventOccurrenceImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EVENTOCCURRENCE_ATTRIBUTE_TARGET:
			return getTarget() != nullptr; //450
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}

bool EventOccurrenceImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EVENTOCCURRENCE_ATTRIBUTE_TARGET:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Element> _target = std::dynamic_pointer_cast<uml::Element>(eObject);
					if(_target)
					{
						setTarget(_target); //450
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'target'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'target'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> EventOccurrenceImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// fUML::Semantics::CommonBehavior::EventOccurrence::doSend(): 905542773
		case CommonBehaviorPackage::EVENTOCCURRENCE_OPERATION_DOSEND:
		{
			this->doSend();
			break;
		}
		// fUML::Semantics::CommonBehavior::EventOccurrence::getParameterValues(uml::Event) : fUML::Semantics::CommonBehavior::ParameterValue[*]: 3047471155
		case CommonBehaviorPackage::EVENTOCCURRENCE_OPERATION_GETPARAMETERVALUES_EVENT:
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
		// fUML::Semantics::CommonBehavior::EventOccurrence::match(uml::Trigger) : bool: 3505679709
		case CommonBehaviorPackage::EVENTOCCURRENCE_OPERATION_MATCH_TRIGGER:
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
		// fUML::Semantics::CommonBehavior::EventOccurrence::matchAny(uml::Trigger[*]) : bool: 2005940351
		case CommonBehaviorPackage::EVENTOCCURRENCE_OPERATION_MATCHANY_TRIGGER:
		{
			//Retrieve input parameter 'triggers'
			//parameter 0
			std::shared_ptr<Bag<uml::Trigger>> incoming_param_triggers;
			Bag<Any>::const_iterator incoming_param_triggers_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>((*incoming_param_triggers_arguments_citer));
				if(ecoreContainerAny)
				{
					try
					{
						std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
				
						if(eObjectList)
						{
							incoming_param_triggers.reset();
							for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
							{
								std::shared_ptr<uml::Trigger> _temp = std::dynamic_pointer_cast<uml::Trigger>(anEObject);
								incoming_param_triggers->add(_temp);
							}
						}
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreContainerAny' for parameter 'triggers'. Failed to invoke operation 'matchAny'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreContainerAny' for parameter 'triggers'. Failed to invoke operation 'matchAny'!")
					return nullptr;
				}
			}
		
			result = eAny(this->matchAny(incoming_param_triggers), 0, false);
			break;
		}
		// fUML::Semantics::CommonBehavior::EventOccurrence::sendTo(uml::Element): 2881178737
		case CommonBehaviorPackage::EVENTOCCURRENCE_OPERATION_SENDTO_ELEMENT:
		{
			//Retrieve input parameter 'target'
			//parameter 0
			std::shared_ptr<uml::Element> incoming_param_target;
			Bag<Any>::const_iterator incoming_param_target_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_target_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_target = std::dynamic_pointer_cast<uml::Element>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'target'. Failed to invoke operation 'sendTo'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'target'. Failed to invoke operation 'sendTo'!")
					return nullptr;
				}
			}
		
			this->sendTo(incoming_param_target);
			break;
		}

		default:
		{
			// call superTypes
			result = ecore::EModelElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> EventOccurrenceImpl::getThisEventOccurrencePtr() const
{
	return m_thisEventOccurrencePtr.lock();
}
void EventOccurrenceImpl::setThisEventOccurrencePtr(std::weak_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> thisEventOccurrencePtr)
{
	m_thisEventOccurrencePtr = thisEventOccurrencePtr;
}


