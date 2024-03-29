
#include "fUML/Semantics/CommonBehavior/impl/CallEventOccurrenceImpl.hpp"
#ifdef NDEBUG
	#define DEBUG_MESSAGE(a) /**/
#else
	#define DEBUG_MESSAGE(a) a
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


#include "abstractDataTypes/AnyEObject.hpp"
#include "abstractDataTypes/AnyEObjectBag.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Includes from codegen annotation
#include <memory>
#include "uml/Trigger.hpp"
#include "uml/CallEvent.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "fUML/Semantics/CommonBehavior/CallEventExecution.hpp"
#include "fUML/Semantics/CommonBehavior/EventOccurrence.hpp"
#include "uml/Operation.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"
#include "uml/Trigger.hpp"
//Factories and Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::CommonBehavior;

//*********************************
// Constructor / Destructor
//*********************************
CallEventOccurrenceImpl::CallEventOccurrenceImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CallEventOccurrenceImpl::~CallEventOccurrenceImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CallEventOccurrence "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


CallEventOccurrenceImpl::CallEventOccurrenceImpl(const CallEventOccurrenceImpl & obj): CallEventOccurrenceImpl()
{
	*this = obj;
}

CallEventOccurrenceImpl& CallEventOccurrenceImpl::operator=(const CallEventOccurrenceImpl & obj)
{
	//call overloaded =Operator for each base class
	EventOccurrenceImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of CallEventOccurrence 
	 * which is generated by the compiler (as CallEventOccurrence is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//CallEventOccurrence::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CallEventOccurrence "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_execution  = obj.getExecution();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> CallEventOccurrenceImpl::copy() const
{
	std::shared_ptr<CallEventOccurrenceImpl> element(new CallEventOccurrenceImpl());
	*element =(*this);
	element->setThisCallEventOccurrencePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<uml::Operation> CallEventOccurrenceImpl::getOperation()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return m_execution->getOperation();
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> > CallEventOccurrenceImpl::getParameterValues()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return m_execution->getInputParameterValues();
	//end of body
}

bool CallEventOccurrenceImpl::match(std::shared_ptr<uml::Trigger> trigger)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		bool matches = false;
	std::shared_ptr<uml::CallEvent> callEvent = std::dynamic_pointer_cast<uml::CallEvent>(trigger->getEvent());
	if (callEvent != nullptr)
	{
		matches = callEvent->getOperation() == getOperation();
	}
	return matches;
	//end of body
}

void CallEventOccurrenceImpl::releaseCaller()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	m_execution->releaseCaller();
	//end of body
}

void CallEventOccurrenceImpl::setOutputParameterValues(std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> parameterValues)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	m_execution->setOutputParameterValues(parameterValues);
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference execution */
std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventExecution> CallEventOccurrenceImpl::getExecution() const
{
    return m_execution;
}
void CallEventOccurrenceImpl::setExecution(std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventExecution> _execution)
{
    m_execution = _execution;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> CallEventOccurrenceImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void CallEventOccurrenceImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CallEventOccurrenceImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("execution");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("execution")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void CallEventOccurrenceImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	EventOccurrenceImpl::loadNode(nodeName, loadHandler);
}

void CallEventOccurrenceImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::CALLEVENTOCCURRENCE_ATTRIBUTE_EXECUTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventExecution> _execution = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::CallEventExecution>( references.front() );
				setExecution(_execution);
			}
			
			return;
		}
	}
	EventOccurrenceImpl::resolveReferences(featureID, references);
}

void CallEventOccurrenceImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	EventOccurrenceImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void CallEventOccurrenceImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::CommonBehavior::CommonBehaviorPackage> package = fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getExecution(), "execution", getExecution()->eClass() != fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getCallEventExecution_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> CallEventOccurrenceImpl::eStaticClass() const
{
	return fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getCallEventOccurrence_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any CallEventOccurrenceImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::CALLEVENTOCCURRENCE_ATTRIBUTE_EXECUTION:
			return eAny(getExecution(),fUML::Semantics::CommonBehavior::CommonBehaviorPackage::CALLEVENTEXECUTION_CLASS,false); //181
	}
	return EventOccurrenceImpl::eGet(featureID, resolve, coreType);
}

bool CallEventOccurrenceImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::CALLEVENTOCCURRENCE_ATTRIBUTE_EXECUTION:
			return getExecution() != nullptr; //181
	}
	return EventOccurrenceImpl::internalEIsSet(featureID);
}

bool CallEventOccurrenceImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::CALLEVENTOCCURRENCE_ATTRIBUTE_EXECUTION:
		{
			// CAST Any to fUML::Semantics::CommonBehavior::CallEventExecution
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventExecution> _execution = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::CallEventExecution>(_temp);
			setExecution(_execution); //181
			return true;
		}
	}

	return EventOccurrenceImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any CallEventOccurrenceImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// fUML::Semantics::CommonBehavior::CallEventOccurrence::getOperation() : uml::Operation: 1750182594
		case CommonBehaviorPackage::CALLEVENTOCCURRENCE_OPERATION_GETOPERATION:
		{
			result = eAnyObject(this->getOperation(), uml::umlPackage::OPERATION_CLASS);
			break;
		}
		// fUML::Semantics::CommonBehavior::CallEventOccurrence::getParameterValues() : fUML::Semantics::CommonBehavior::ParameterValue[*]: 2035047579
		case CommonBehaviorPackage::CALLEVENTOCCURRENCE_OPERATION_GETPARAMETERVALUES:
		{
			std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> > resultList = this->getParameterValues();
			return eAnyBag(resultList,fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_CLASS);
			break;
		}
		// fUML::Semantics::CommonBehavior::CallEventOccurrence::match(uml::Trigger) : bool: 3680623661
		case CommonBehaviorPackage::CALLEVENTOCCURRENCE_OPERATION_MATCH_TRIGGER:
		{
			//Retrieve input parameter 'trigger'
			//parameter 0
			std::shared_ptr<uml::Trigger> incoming_param_trigger;
			std::list<Any>::const_iterator incoming_param_trigger_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_trigger = (*incoming_param_trigger_arguments_citer)->get<std::shared_ptr<uml::Trigger> >();
			result = eAny(this->match(incoming_param_trigger),0,false);
			break;
		}
		// fUML::Semantics::CommonBehavior::CallEventOccurrence::releaseCaller(): 4220461060
		case CommonBehaviorPackage::CALLEVENTOCCURRENCE_OPERATION_RELEASECALLER:
		{
			this->releaseCaller();
			break;
		}
		// fUML::Semantics::CommonBehavior::CallEventOccurrence::setOutputParameterValues(fUML::Semantics::CommonBehavior::ParameterValue[*]): 2726106774
		case CommonBehaviorPackage::CALLEVENTOCCURRENCE_OPERATION_SETOUTPUTPARAMETERVALUES_PARAMETERVALUE:
		{
			//Retrieve input parameter 'parameterValues'
			//parameter 0
			std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> incoming_param_parameterValues;
			std::list<Any>::const_iterator incoming_param_parameterValues_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_parameterValues = (*incoming_param_parameterValues_arguments_citer)->get<std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> >();
			this->setOutputParameterValues(incoming_param_parameterValues);
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

std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventOccurrence> CallEventOccurrenceImpl::getThisCallEventOccurrencePtr() const
{
	return m_thisCallEventOccurrencePtr.lock();
}
void CallEventOccurrenceImpl::setThisCallEventOccurrencePtr(std::weak_ptr<fUML::Semantics::CommonBehavior::CallEventOccurrence> thisCallEventOccurrencePtr)
{
	m_thisCallEventOccurrencePtr = thisCallEventOccurrencePtr;
	setThisEventOccurrencePtr(thisCallEventOccurrencePtr);
}


