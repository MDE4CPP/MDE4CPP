
#include "fUML/Semantics/CommonBehavior/impl/InvocationEventOccurrenceImpl.hpp"
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
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "fUML/Semantics/CommonBehavior/EventOccurrence.hpp"
#include "fUML/Semantics/CommonBehavior/Execution.hpp"
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
InvocationEventOccurrenceImpl::InvocationEventOccurrenceImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

InvocationEventOccurrenceImpl::~InvocationEventOccurrenceImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InvocationEventOccurrence "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


InvocationEventOccurrenceImpl::InvocationEventOccurrenceImpl(const InvocationEventOccurrenceImpl & obj): InvocationEventOccurrenceImpl()
{
	*this = obj;
}

InvocationEventOccurrenceImpl& InvocationEventOccurrenceImpl::operator=(const InvocationEventOccurrenceImpl & obj)
{
	//call overloaded =Operator for each base class
	EventOccurrenceImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of InvocationEventOccurrence 
	 * which is generated by the compiler (as InvocationEventOccurrence is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//InvocationEventOccurrence::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InvocationEventOccurrence "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_execution  = obj.getExecution();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> InvocationEventOccurrenceImpl::copy() const
{
	std::shared_ptr<InvocationEventOccurrenceImpl> element(new InvocationEventOccurrenceImpl());
	*element =(*this);
	element->setThisInvocationEventOccurrencePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> > InvocationEventOccurrenceImpl::getParameterValues()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// An invocation event occurrence does not have any associated data.

std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> parameterValueList(new Bag<fUML::Semantics::CommonBehavior::ParameterValue>());

return parameterValueList;
	//end of body
}

bool InvocationEventOccurrenceImpl::match(const std::shared_ptr<uml::Trigger>& trigger)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// An invocation event occurrence does not match any triggers.

return false;
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference execution */
const std::shared_ptr<fUML::Semantics::CommonBehavior::Execution>& InvocationEventOccurrenceImpl::getExecution() const
{
    return m_execution;
}
void InvocationEventOccurrenceImpl::setExecution(const std::shared_ptr<fUML::Semantics::CommonBehavior::Execution>& _execution)
{
    m_execution = _execution;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> InvocationEventOccurrenceImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void InvocationEventOccurrenceImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void InvocationEventOccurrenceImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
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

void InvocationEventOccurrenceImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	EventOccurrenceImpl::loadNode(nodeName, loadHandler);
}

void InvocationEventOccurrenceImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::INVOCATIONEVENTOCCURRENCE_ATTRIBUTE_EXECUTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> _execution = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::Execution>( references.front() );
				setExecution(_execution);
			}
			
			return;
		}
	}
	EventOccurrenceImpl::resolveReferences(featureID, references);
}

void InvocationEventOccurrenceImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	EventOccurrenceImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void InvocationEventOccurrenceImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::CommonBehavior::CommonBehaviorPackage> package = fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getExecution(), "execution", getExecution()->eClass() != fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getExecution_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& InvocationEventOccurrenceImpl::eStaticClass() const
{
	return fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getInvocationEventOccurrence_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any InvocationEventOccurrenceImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::INVOCATIONEVENTOCCURRENCE_ATTRIBUTE_EXECUTION:
			return eAny(getExecution(),fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EXECUTION_CLASS,false); //661
	}
	return EventOccurrenceImpl::eGet(featureID, resolve, coreType);
}

bool InvocationEventOccurrenceImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::INVOCATIONEVENTOCCURRENCE_ATTRIBUTE_EXECUTION:
			return getExecution() != nullptr; //661
	}
	return EventOccurrenceImpl::internalEIsSet(featureID);
}

bool InvocationEventOccurrenceImpl::eSet(int featureID, const Any& newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::INVOCATIONEVENTOCCURRENCE_ATTRIBUTE_EXECUTION:
		{
			// CAST Any to fUML::Semantics::CommonBehavior::Execution
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> _execution = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::Execution>(_temp);
			setExecution(_execution); //661
			return true;
		}
	}

	return EventOccurrenceImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any InvocationEventOccurrenceImpl::eInvoke(int operationID, const std::shared_ptr<std::list<Any>>& arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// fUML::Semantics::CommonBehavior::InvocationEventOccurrence::getParameterValues() : fUML::Semantics::CommonBehavior::ParameterValue[*]: 264852969
		case CommonBehaviorPackage::INVOCATIONEVENTOCCURRENCE_OPERATION_GETPARAMETERVALUES:
		{
			std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> > resultList = this->getParameterValues();
			return eAnyBag(resultList,fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_CLASS);
			break;
		}
		// fUML::Semantics::CommonBehavior::InvocationEventOccurrence::match(uml::Trigger) : bool: 1234869067
		case CommonBehaviorPackage::INVOCATIONEVENTOCCURRENCE_OPERATION_MATCH_TRIGGER:
		{
			//Retrieve input parameter 'trigger'
			//parameter 0
			std::shared_ptr<uml::Trigger> incoming_param_trigger;
			std::list<Any>::const_iterator incoming_param_trigger_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_trigger = (*incoming_param_trigger_arguments_citer)->get<std::shared_ptr<uml::Trigger> >();
			result = eAny(this->match(incoming_param_trigger),0,false);
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

std::shared_ptr<fUML::Semantics::CommonBehavior::InvocationEventOccurrence> InvocationEventOccurrenceImpl::getThisInvocationEventOccurrencePtr() const
{
	return m_thisInvocationEventOccurrencePtr.lock();
}
void InvocationEventOccurrenceImpl::setThisInvocationEventOccurrencePtr(std::weak_ptr<fUML::Semantics::CommonBehavior::InvocationEventOccurrence> thisInvocationEventOccurrencePtr)
{
	m_thisInvocationEventOccurrencePtr = thisInvocationEventOccurrencePtr;
	setThisEventOccurrencePtr(thisInvocationEventOccurrencePtr);
}


