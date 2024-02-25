
#include "PSSM/Semantics/CommonBehavior/impl/CallEventOccurrenceImpl.hpp"
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
#include "uml/umlFactory.hpp"
#include "PSSM/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "PSSM/Semantics/CommonBehavior/CallEventExecution.hpp"
#include "uml/Element.hpp"
#include "fUML/Semantics/CommonBehavior/EventOccurrence.hpp"
//Factories and Package includes
#include "PSSM/Semantics/SemanticsPackage.hpp"
#include "PSSM/PSSMPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "PSSM/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace PSSM::Semantics::CommonBehavior;

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
	fUML::Semantics::CommonBehavior::EventOccurrenceImpl::operator=(obj);
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

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference execution */
const std::shared_ptr<PSSM::Semantics::CommonBehavior::CallEventExecution>& CallEventOccurrenceImpl::getExecution() const
{
    return m_execution;
}
void CallEventOccurrenceImpl::setExecution(const std::shared_ptr<PSSM::Semantics::CommonBehavior::CallEventExecution>& _execution)
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
	// get PSSMFactory
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

	fUML::Semantics::CommonBehavior::EventOccurrenceImpl::loadAttributes(loadHandler, attr_list);
}

void CallEventOccurrenceImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::CommonBehavior::EventOccurrenceImpl::loadNode(nodeName, loadHandler);
}

void CallEventOccurrenceImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::CALLEVENTOCCURRENCE_ATTRIBUTE_EXECUTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<PSSM::Semantics::CommonBehavior::CallEventExecution> _execution = std::dynamic_pointer_cast<PSSM::Semantics::CommonBehavior::CallEventExecution>( references.front() );
				setExecution(_execution);
			}
			
			return;
		}
	}
	fUML::Semantics::CommonBehavior::EventOccurrenceImpl::resolveReferences(featureID, references);
}

void CallEventOccurrenceImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::CommonBehavior::EventOccurrenceImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void CallEventOccurrenceImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSSM::Semantics::CommonBehavior::CommonBehaviorPackage> package = PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance();
	// Add references
	if ( this->eIsSet(package->getCallEventOccurrence_Attribute_execution()) )
	{
		saveHandler->addReference(this->getExecution(), "execution", getExecution()->eClass() != PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getCallEventExecution_Class()); 
	}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& CallEventOccurrenceImpl::eStaticClass() const
{
	return PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getCallEventOccurrence_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> CallEventOccurrenceImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::CALLEVENTOCCURRENCE_ATTRIBUTE_EXECUTION:
			return eAny(getExecution(),PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::CALLEVENTEXECUTION_CLASS,false); //21
	}
	return fUML::Semantics::CommonBehavior::EventOccurrenceImpl::eGet(featureID, resolve, coreType);
}

bool CallEventOccurrenceImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::CALLEVENTOCCURRENCE_ATTRIBUTE_EXECUTION:
			return getExecution() != nullptr; //21
	}
	return fUML::Semantics::CommonBehavior::EventOccurrenceImpl::internalEIsSet(featureID);
}

bool CallEventOccurrenceImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::CALLEVENTOCCURRENCE_ATTRIBUTE_EXECUTION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<PSSM::Semantics::CommonBehavior::CallEventExecution> _execution = std::dynamic_pointer_cast<PSSM::Semantics::CommonBehavior::CallEventExecution>(eObject);
					if(_execution)
					{
						setExecution(_execution); //21
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'execution'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'execution'. Failed to set feature!")
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
std::shared_ptr<Any> CallEventOccurrenceImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

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

std::shared_ptr<PSSM::Semantics::CommonBehavior::CallEventOccurrence> CallEventOccurrenceImpl::getThisCallEventOccurrencePtr() const
{
	return m_thisCallEventOccurrencePtr.lock();
}
void CallEventOccurrenceImpl::setThisCallEventOccurrencePtr(std::weak_ptr<PSSM::Semantics::CommonBehavior::CallEventOccurrence> thisCallEventOccurrencePtr)
{
	m_thisCallEventOccurrencePtr = thisCallEventOccurrencePtr;
	setThisEventOccurrencePtr(thisCallEventOccurrencePtr);
}


