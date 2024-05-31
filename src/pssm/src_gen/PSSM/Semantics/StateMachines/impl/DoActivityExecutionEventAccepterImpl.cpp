
#include "PSSM/Semantics/StateMachines/impl/DoActivityExecutionEventAccepterImpl.hpp"
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
#include "fUML/Semantics/CommonBehavior/ObjectActivation.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "PSSM/Semantics/StateMachines/StateMachinesFactory.hpp"
#include "PSSM/Semantics/StateMachines/DoActivityContextObject.hpp"
#include "fUML/Semantics/CommonBehavior/EventAccepter.hpp"
#include "fUML/Semantics/CommonBehavior/EventOccurrence.hpp"
//Factories and Package includes
#include "PSSM/PSSMPackage.hpp"
#include "PSSM/Semantics/SemanticsPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "PSSM/Semantics/StateMachines/StateMachinesPackage.hpp"

using namespace PSSM::Semantics::StateMachines;

//*********************************
// Constructor / Destructor
//*********************************
DoActivityExecutionEventAccepterImpl::DoActivityExecutionEventAccepterImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

DoActivityExecutionEventAccepterImpl::~DoActivityExecutionEventAccepterImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DoActivityExecutionEventAccepter "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


DoActivityExecutionEventAccepterImpl::DoActivityExecutionEventAccepterImpl(const DoActivityExecutionEventAccepterImpl & obj): DoActivityExecutionEventAccepterImpl()
{
	*this = obj;
}

DoActivityExecutionEventAccepterImpl& DoActivityExecutionEventAccepterImpl::operator=(const DoActivityExecutionEventAccepterImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::CommonBehavior::EventAccepterImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of DoActivityExecutionEventAccepter 
	 * which is generated by the compiler (as DoActivityExecutionEventAccepter is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//DoActivityExecutionEventAccepter::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy DoActivityExecutionEventAccepter "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_context  = obj.getContext();
	//Clone references with containment (deep copy)
	//clone reference 'encapsulatedAccepter'
	if(obj.getEncapsulatedAccepter()!=nullptr)
	{
		m_encapsulatedAccepter = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::EventAccepter>(obj.getEncapsulatedAccepter()->copy());
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> DoActivityExecutionEventAccepterImpl::copy() const
{
	std::shared_ptr<DoActivityExecutionEventAccepterImpl> element(new DoActivityExecutionEventAccepterImpl());
	*element =(*this);
	element->setThisDoActivityExecutionEventAccepterPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
void DoActivityExecutionEventAccepterImpl::accept(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// The EventOccurrence accepted through the StateMachine Event Pool leads
	// to the triggering of a RTC step in the context of the doActivity.
	// To realize this, the EventOccurrence is registered at the Event Pool of the
	// DoActivityContextObjectActivation. This will trigger a new RTC step
	// in the DoActivityContextObject instead of the State Machine context.
	this->m_context->getObjectActivation()->send(eventOccurrence);
	//end of body
}

bool DoActivityExecutionEventAccepterImpl::match(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>& eventOccurrence)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Delegate the operation call to the encapsulated DoActivityExecutionEventAccepter.
	return this->m_encapsulatedAccepter->match(eventOccurrence);
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference context */
const std::shared_ptr<PSSM::Semantics::StateMachines::DoActivityContextObject>& DoActivityExecutionEventAccepterImpl::getContext() const
{
    return m_context;
}
void DoActivityExecutionEventAccepterImpl::setContext(const std::shared_ptr<PSSM::Semantics::StateMachines::DoActivityContextObject>& _context)
{
    m_context = _context;
	
}

/* Getter & Setter for reference encapsulatedAccepter */
const std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter>& DoActivityExecutionEventAccepterImpl::getEncapsulatedAccepter() const
{
    return m_encapsulatedAccepter;
}
void DoActivityExecutionEventAccepterImpl::setEncapsulatedAccepter(const std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter>& _encapsulatedAccepter)
{
    m_encapsulatedAccepter = _encapsulatedAccepter;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> DoActivityExecutionEventAccepterImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void DoActivityExecutionEventAccepterImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void DoActivityExecutionEventAccepterImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("context");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("context")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	fUML::Semantics::CommonBehavior::EventAccepterImpl::loadAttributes(loadHandler, attr_list);
}

void DoActivityExecutionEventAccepterImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("encapsulatedAccepter") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type of an eClassifiers node is empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			else
			{
				if (std::string::npos == typeName.find("fUML::Semantics::CommonBehavior/]"))
				{
					typeName = "fUML::Semantics::CommonBehavior::"+typeName;
				}
			}
			loadHandler->handleChild(this->getEncapsulatedAccepter()); 

			return; 
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
	//load BasePackage Nodes
	fUML::Semantics::CommonBehavior::EventAccepterImpl::loadNode(nodeName, loadHandler);
}

void DoActivityExecutionEventAccepterImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case PSSM::Semantics::StateMachines::StateMachinesPackage::DOACTIVITYEXECUTIONEVENTACCEPTER_ATTRIBUTE_CONTEXT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<PSSM::Semantics::StateMachines::DoActivityContextObject> _context = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::DoActivityContextObject>( references.front() );
				setContext(_context);
			}
			
			return;
		}
	}
	fUML::Semantics::CommonBehavior::EventAccepterImpl::resolveReferences(featureID, references);
}

void DoActivityExecutionEventAccepterImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::CommonBehavior::EventAccepterImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void DoActivityExecutionEventAccepterImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSSM::Semantics::StateMachines::StateMachinesPackage> package = PSSM::Semantics::StateMachines::StateMachinesPackage::eInstance();
	// Add references
	if ( this->eIsSet(package->getDoActivityExecutionEventAccepter_Attribute_context()) )
	{
		saveHandler->addReference(this->getContext(), "context", getContext()->eClass() != PSSM::Semantics::StateMachines::StateMachinesPackage::eInstance()->getDoActivityContextObject_Class()); 
	}
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'encapsulatedAccepter'
	    if ( this->eIsSet(package->getDoActivityExecutionEventAccepter_Attribute_encapsulatedAccepter()) )
	    {
		saveHandler->addReference(this->getEncapsulatedAccepter(), "encapsulatedAccepter", getEncapsulatedAccepter()->eClass() != fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventAccepter_Class());
	    }
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& DoActivityExecutionEventAccepterImpl::eStaticClass() const
{
	return PSSM::Semantics::StateMachines::StateMachinesPackage::eInstance()->getDoActivityExecutionEventAccepter_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> DoActivityExecutionEventAccepterImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case PSSM::Semantics::StateMachines::StateMachinesPackage::DOACTIVITYEXECUTIONEVENTACCEPTER_ATTRIBUTE_CONTEXT:
			return eAny(getContext(),PSSM::Semantics::StateMachines::StateMachinesPackage::DOACTIVITYCONTEXTOBJECT_CLASS,false); //110
		case PSSM::Semantics::StateMachines::StateMachinesPackage::DOACTIVITYEXECUTIONEVENTACCEPTER_ATTRIBUTE_ENCAPSULATEDACCEPTER:
			return eAny(getEncapsulatedAccepter(),fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EVENTACCEPTER_CLASS,false); //111
	}
	return fUML::Semantics::CommonBehavior::EventAccepterImpl::eGet(featureID, resolve, coreType);
}

bool DoActivityExecutionEventAccepterImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case PSSM::Semantics::StateMachines::StateMachinesPackage::DOACTIVITYEXECUTIONEVENTACCEPTER_ATTRIBUTE_CONTEXT:
			return getContext() != nullptr; //110
		case PSSM::Semantics::StateMachines::StateMachinesPackage::DOACTIVITYEXECUTIONEVENTACCEPTER_ATTRIBUTE_ENCAPSULATEDACCEPTER:
			return getEncapsulatedAccepter() != nullptr; //111
	}
	return fUML::Semantics::CommonBehavior::EventAccepterImpl::internalEIsSet(featureID);
}

bool DoActivityExecutionEventAccepterImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case PSSM::Semantics::StateMachines::StateMachinesPackage::DOACTIVITYEXECUTIONEVENTACCEPTER_ATTRIBUTE_CONTEXT:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<PSSM::Semantics::StateMachines::DoActivityContextObject> _context = std::dynamic_pointer_cast<PSSM::Semantics::StateMachines::DoActivityContextObject>(eObject);
					if(_context)
					{
						setContext(_context); //110
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'context'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'context'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case PSSM::Semantics::StateMachines::StateMachinesPackage::DOACTIVITYEXECUTIONEVENTACCEPTER_ATTRIBUTE_ENCAPSULATEDACCEPTER:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter> _encapsulatedAccepter = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::EventAccepter>(eObject);
					if(_encapsulatedAccepter)
					{
						setEncapsulatedAccepter(_encapsulatedAccepter); //111
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'encapsulatedAccepter'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'encapsulatedAccepter'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return fUML::Semantics::CommonBehavior::EventAccepterImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> DoActivityExecutionEventAccepterImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// PSSM::Semantics::StateMachines::DoActivityExecutionEventAccepter::accept(fUML::Semantics::CommonBehavior::EventOccurrence): 2344912028
		case StateMachinesPackage::DOACTIVITYEXECUTIONEVENTACCEPTER_OPERATION_ACCEPT_EVENTOCCURRENCE:
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
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'eventOccurrence'. Failed to invoke operation 'accept'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'eventOccurrence'. Failed to invoke operation 'accept'!")
					return nullptr;
				}
			}
		
			this->accept(incoming_param_eventOccurrence);
			break;
		}
		// PSSM::Semantics::StateMachines::DoActivityExecutionEventAccepter::match(fUML::Semantics::CommonBehavior::EventOccurrence) : bool: 3771787187
		case StateMachinesPackage::DOACTIVITYEXECUTIONEVENTACCEPTER_OPERATION_MATCH_EVENTOCCURRENCE:
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
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'eventOccurrence'. Failed to invoke operation 'match'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'eventOccurrence'. Failed to invoke operation 'match'!")
					return nullptr;
				}
			}
		
			result = eAny(this->match(incoming_param_eventOccurrence), 0, false);
			break;
		}

		default:
		{
			// call superTypes
			result = fUML::Semantics::CommonBehavior::EventAccepterImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<PSSM::Semantics::StateMachines::DoActivityExecutionEventAccepter> DoActivityExecutionEventAccepterImpl::getThisDoActivityExecutionEventAccepterPtr() const
{
	return m_thisDoActivityExecutionEventAccepterPtr.lock();
}
void DoActivityExecutionEventAccepterImpl::setThisDoActivityExecutionEventAccepterPtr(std::weak_ptr<PSSM::Semantics::StateMachines::DoActivityExecutionEventAccepter> thisDoActivityExecutionEventAccepterPtr)
{
	m_thisDoActivityExecutionEventAccepterPtr = thisDoActivityExecutionEventAccepterPtr;
	setThisEventAccepterPtr(thisDoActivityExecutionEventAccepterPtr);
}


