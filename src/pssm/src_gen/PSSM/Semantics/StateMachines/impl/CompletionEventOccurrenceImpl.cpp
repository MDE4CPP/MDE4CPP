
#include "PSSM/Semantics/StateMachines/impl/CompletionEventOccurrenceImpl.hpp"
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
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "PSSM/Semantics/StateMachines/StateMachinesFactory.hpp"
#include "uml/Element.hpp"
#include "fUML/Semantics/CommonBehavior/EventOccurrence.hpp"
#include "PSSM/Semantics/StateMachines/StateActivation.hpp"
#include "uml/Trigger.hpp"
//Factories and Package includes
#include "PSSM/Semantics/SemanticsPackage.hpp"
#include "PSSM/PSSMPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "PSSM/Semantics/StateMachines/StateMachinesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace PSSM::Semantics::StateMachines;

//*********************************
// Constructor / Destructor
//*********************************
CompletionEventOccurrenceImpl::CompletionEventOccurrenceImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CompletionEventOccurrenceImpl::~CompletionEventOccurrenceImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CompletionEventOccurrence "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


CompletionEventOccurrenceImpl::CompletionEventOccurrenceImpl(const CompletionEventOccurrenceImpl & obj): CompletionEventOccurrenceImpl()
{
	*this = obj;
}

CompletionEventOccurrenceImpl& CompletionEventOccurrenceImpl::operator=(const CompletionEventOccurrenceImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::CommonBehavior::EventOccurrenceImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of CompletionEventOccurrence 
	 * which is generated by the compiler (as CompletionEventOccurrence is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//CompletionEventOccurrence::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CompletionEventOccurrence "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_stateActivation  = obj.getStateActivation();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> CompletionEventOccurrenceImpl::copy() const
{
	std::shared_ptr<CompletionEventOccurrenceImpl> element(new CompletionEventOccurrenceImpl());
	*element =(*this);
	element->setThisCompletionEventOccurrencePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool CompletionEventOccurrenceImpl::_match(const std::shared_ptr<Bag<uml::Trigger>>& triggers)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// A CompletionEvent can only trigger a Transition with no
	// Trigger. Hence, only if the passed list of Triggers is empty,
	// the CompletionEventOccurrence matches
	if(triggers->size() == 0){
		return true;
	}
	return false;
	//end of body
}

void CompletionEventOccurrenceImpl::_register(const std::shared_ptr<PSSM::Semantics::StateMachines::StateActivation>& stateActivation)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	this->setStateActivation(stateActivation);
	//end of body
}

bool CompletionEventOccurrenceImpl::match(const std::shared_ptr<uml::Trigger>& trigger)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// A CompletionEvent can only trigger a Transition with no
	// Trigger. Hence it cannot match any Trigger
	return false;
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference stateActivation */
const std::shared_ptr<PSSM::Semantics::StateMachines::StateActivation>& CompletionEventOccurrenceImpl::getStateActivation() const
{
    return m_stateActivation;
}
void CompletionEventOccurrenceImpl::setStateActivation(const std::shared_ptr<PSSM::Semantics::StateMachines::StateActivation>& _stateActivation)
{
    m_stateActivation = _stateActivation;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> CompletionEventOccurrenceImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void CompletionEventOccurrenceImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CompletionEventOccurrenceImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("stateActivation");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("stateActivation")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	fUML::Semantics::CommonBehavior::EventOccurrenceImpl::loadAttributes(loadHandler, attr_list);
}

void CompletionEventOccurrenceImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::CommonBehavior::EventOccurrenceImpl::loadNode(nodeName, loadHandler);
}

void CompletionEventOccurrenceImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case PSSM::Semantics::StateMachines::StateMachinesPackage::COMPLETIONEVENTOCCURRENCE_ATTRIBUTE_STATEACTIVATION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<PSSM::Semantics::StateMachines::StateActivation> _stateActivation = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::StateActivation>( references.front() );
				setStateActivation(_stateActivation);
			}
			
			return;
		}
	}
	fUML::Semantics::CommonBehavior::EventOccurrenceImpl::resolveReferences(featureID, references);
}

void CompletionEventOccurrenceImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::CommonBehavior::EventOccurrenceImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void CompletionEventOccurrenceImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSSM::Semantics::StateMachines::StateMachinesPackage> package = PSSM::Semantics::StateMachines::StateMachinesPackage::eInstance();
	// Add references
	if ( this->eIsSet(package->getCompletionEventOccurrence_Attribute_stateActivation()) )
	{
		saveHandler->addReference(this->getStateActivation(), "stateActivation", getStateActivation()->eClass() != PSSM::Semantics::StateMachines::StateMachinesPackage::eInstance()->getStateActivation_Class()); 
	}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& CompletionEventOccurrenceImpl::eStaticClass() const
{
	return PSSM::Semantics::StateMachines::StateMachinesPackage::eInstance()->getCompletionEventOccurrence_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> CompletionEventOccurrenceImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case PSSM::Semantics::StateMachines::StateMachinesPackage::COMPLETIONEVENTOCCURRENCE_ATTRIBUTE_STATEACTIVATION:
			return eAny(getStateActivation(),PSSM::Semantics::StateMachines::StateMachinesPackage::STATEACTIVATION_CLASS,false); //41
	}
	return fUML::Semantics::CommonBehavior::EventOccurrenceImpl::eGet(featureID, resolve, coreType);
}

bool CompletionEventOccurrenceImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case PSSM::Semantics::StateMachines::StateMachinesPackage::COMPLETIONEVENTOCCURRENCE_ATTRIBUTE_STATEACTIVATION:
			return getStateActivation() != nullptr; //41
	}
	return fUML::Semantics::CommonBehavior::EventOccurrenceImpl::internalEIsSet(featureID);
}

bool CompletionEventOccurrenceImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case PSSM::Semantics::StateMachines::StateMachinesPackage::COMPLETIONEVENTOCCURRENCE_ATTRIBUTE_STATEACTIVATION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<PSSM::Semantics::StateMachines::StateActivation> _stateActivation = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::StateActivation>(eObject);
					if(_stateActivation)
					{
						setStateActivation(_stateActivation); //41
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'stateActivation'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'stateActivation'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return fUML::Semantics::CommonBehavior::EventOccurrenceImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> CompletionEventOccurrenceImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// PSSM::Semantics::StateMachines::CompletionEventOccurrence::_match(uml::Trigger[*]) : bool: 301723783
		case StateMachinesPackage::COMPLETIONEVENTOCCURRENCE_OPERATION__MATCH_TRIGGER:
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
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreContainerAny' for parameter 'triggers'. Failed to invoke operation '_match'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreContainerAny' for parameter 'triggers'. Failed to invoke operation '_match'!")
					return nullptr;
				}
			}
		
			result = eAny(this->_match(incoming_param_triggers), 0, false);
			break;
		}
		// PSSM::Semantics::StateMachines::CompletionEventOccurrence::_register(PSSM::Semantics::StateMachines::StateActivation): 3594435511
		case StateMachinesPackage::COMPLETIONEVENTOCCURRENCE_OPERATION__REGISTER_STATEACTIVATION:
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
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'stateActivation'. Failed to invoke operation '_register'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'stateActivation'. Failed to invoke operation '_register'!")
					return nullptr;
				}
			}
		
			this->_register(incoming_param_stateActivation);
			break;
		}
		// PSSM::Semantics::StateMachines::CompletionEventOccurrence::match(uml::Trigger) : bool: 2944087030
		case StateMachinesPackage::COMPLETIONEVENTOCCURRENCE_OPERATION_MATCH_TRIGGER:
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
			result = fUML::Semantics::CommonBehavior::EventOccurrenceImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<PSSM::Semantics::StateMachines::CompletionEventOccurrence> CompletionEventOccurrenceImpl::getThisCompletionEventOccurrencePtr() const
{
	return m_thisCompletionEventOccurrencePtr.lock();
}
void CompletionEventOccurrenceImpl::setThisCompletionEventOccurrencePtr(std::weak_ptr<PSSM::Semantics::StateMachines::CompletionEventOccurrence> thisCompletionEventOccurrencePtr)
{
	m_thisCompletionEventOccurrencePtr = thisCompletionEventOccurrencePtr;
	setThisEventOccurrencePtr(thisCompletionEventOccurrencePtr);
}

