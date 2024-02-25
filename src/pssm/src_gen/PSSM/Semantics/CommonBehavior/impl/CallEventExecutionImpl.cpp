
#include "PSSM/Semantics/CommonBehavior/impl/CallEventExecutionImpl.hpp"
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
#include "PSSM/Semantics/CommonBehavior/CallEventOccurrence.hpp"
#include "PSSM/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "fUML/FUMLFactory.hpp"
#include "uml/ParameterDirectionKind.hpp"
#include "uml/Parameter.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsFactory.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "ecore/ecoreFactory.hpp"
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "uml/Behavior.hpp"
#include "PSSM/Semantics/CommonBehavior/CallEventOccurrence.hpp"
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "ecore/EAnnotation.hpp"
#include "uml/Element.hpp"
#include "fUML/Semantics/CommonBehavior/Execution.hpp"
#include "fUML/MDE4CPP_Extensions/FUML_Object.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/CommonBehavior/ObjectActivation.hpp"
#include "uml/Operation.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
//Factories and Package includes
#include "PSSM/Semantics/SemanticsPackage.hpp"
#include "PSSM/PSSMPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "PSSM/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "uml/umlPackage.hpp"

using namespace PSSM::Semantics::CommonBehavior;

//*********************************
// Constructor / Destructor
//*********************************
CallEventExecutionImpl::CallEventExecutionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CallEventExecutionImpl::~CallEventExecutionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CallEventExecution "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


CallEventExecutionImpl::CallEventExecutionImpl(const CallEventExecutionImpl & obj): CallEventExecutionImpl()
{
	*this = obj;
}

CallEventExecutionImpl& CallEventExecutionImpl::operator=(const CallEventExecutionImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::CommonBehavior::ExecutionImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of CallEventExecution 
	 * which is generated by the compiler (as CallEventExecution is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//CallEventExecution::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CallEventExecution "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_callerSuspended = obj.getCallerSuspended();

	//copy references with no containment (soft copy)
	m_behavior  = obj.getBehavior();
	m_callerContext  = obj.getCallerContext();
	m_operation  = obj.getOperation();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> CallEventExecutionImpl::copy() const
{
	std::shared_ptr<CallEventExecutionImpl> element(new CallEventExecutionImpl());
	*element =(*this);
	element->setThisCallEventExecutionPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
void CallEventExecutionImpl::_send(const std::shared_ptr<PSSM::Semantics::CommonBehavior::CallEventOccurrence>& eventOccurrence)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Place the call event occurrence within the event pool of
// the target object
//if(this.context.objectActivation != null){
//	this.context.objectActivation.eventPool.add(eventOccurrence);
//	this.context.objectActivation._send(new ArrivalSignal());
//}
	// empty body because:
	// a) fUML::ObjectActivation::eventPool contains fUML::SignalInstance, not fUML::EventOccurrence (no common parent classes)
	// b) fUML::ObjectActvation::_send has an empty body too
	//end of body
}

void CallEventExecutionImpl::_suspend()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	while(this->m_callerSuspended);
	//end of body
}

void CallEventExecutionImpl::execute()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// The execution consists in placing a new CallEventOccurrence
// within the event pool of the target active object. Not that
// the call will not be executed if the target is not an active
// object. This is due to the fact that the call event could
// not placed anywhere since a passive object has no event pool.
// The caller is expected to be suspended until the RTC step using
// the event occurrence terminates.
//CallEventOccurrence eventOccurrence = new CallEventOccurrence();
//eventOccurrence.execution = this;
//this.callerSuspended = true;
//this._send(eventOccurrence);
//this._suspend();
	std::shared_ptr<PSSM::Semantics::CommonBehavior::CallEventOccurrence> eventOccurrence = PSSM::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createCallEventOccurrence();
	eventOccurrence->setExecution(this->getThisCallEventExecutionPtr());
	this->m_callerSuspended = true;
	this->_send(eventOccurrence);
	this->_suspend();
	//end of body
}



std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> CallEventExecutionImpl::getInputParameterValues()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Return input parameter values for this execution
//List<ParameterValue> parameterValues = new ArrayList<ParameterValue>();
//for(int i=0; i < this.parameterValues.size(); i++){
//	ParameterValue parameterValue = this.parameterValues.get(i);
//	if(parameterValue.parameter.getDirection() == ParameterDirectionKind.IN_LITERAL
//			| parameterValue.parameter.getDirection() == ParameterDirectionKind.INOUT_LITERAL){
//		parameterValues.add(parameterValue);
//	}
//}
//return parameterValues;
	std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> parameterValues(new Bag<fUML::Semantics::CommonBehavior::ParameterValue>());
	for(int i=0; i < int(this->m_parameterValues->size()); i++) {
		std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> parameterValue = this->m_parameterValues->at(i);
		if((parameterValue->getParameter()->getDirection() == uml::ParameterDirectionKind::IN) |
				(parameterValue->getParameter()->getDirection() == uml::ParameterDirectionKind::INOUT)) {
			parameterValues->add(parameterValue);
		}
	}
	return parameterValues;

	//end of body
}



void CallEventExecutionImpl::releaseCaller()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	this->m_callerSuspended = false;
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute callerSuspended */
bool CallEventExecutionImpl::getCallerSuspended() const 
{
	return m_callerSuspended;
}
void CallEventExecutionImpl::setCallerSuspended(bool _callerSuspended)
{
	m_callerSuspended = _callerSuspended;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference behavior */
const std::shared_ptr<uml::Behavior>& CallEventExecutionImpl::getBehavior() const
{
    return m_behavior;
}
void CallEventExecutionImpl::setBehavior(const std::shared_ptr<uml::Behavior>& _behavior)
{
    m_behavior = _behavior;
	
}

/* Getter & Setter for reference callerContext */
const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object>& CallEventExecutionImpl::getCallerContext() const
{
    return m_callerContext;
}
void CallEventExecutionImpl::setCallerContext(const std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object>& _callerContext)
{
    m_callerContext = _callerContext;
	
}

/* Getter & Setter for reference operation */
const std::shared_ptr<uml::Operation>& CallEventExecutionImpl::getOperation() const
{
    return m_operation;
}
void CallEventExecutionImpl::setOperation(const std::shared_ptr<uml::Operation>& _operation)
{
    m_operation = _operation;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> CallEventExecutionImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void CallEventExecutionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CallEventExecutionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("callerSuspended");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setCallerSuspended(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("behavior");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("behavior")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("callerContext");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("callerContext")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("operation");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("operation")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void CallEventExecutionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::CommonBehavior::ExecutionImpl::loadNode(nodeName, loadHandler);
}

void CallEventExecutionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	switch(featureID)
	{
		case PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::CALLEVENTEXECUTION_ATTRIBUTE_BEHAVIOR:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Behavior> _behavior = std::dynamic_pointer_cast<uml::Behavior>( references.front() );
				setBehavior(_behavior);
			}
			
			return;
		}

		case PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::CALLEVENTEXECUTION_ATTRIBUTE_CALLERCONTEXT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object> _callerContext = std::dynamic_pointer_cast<fUML::MDE4CPP_Extensions::FUML_Object>( references.front() );
				setCallerContext(_callerContext);
			}
			
			return;
		}

		case PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::CALLEVENTEXECUTION_ATTRIBUTE_OPERATION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Operation> _operation = std::dynamic_pointer_cast<uml::Operation>( references.front() );
				setOperation(_operation);
			}
			
			return;
		}
	}
	fUML::Semantics::CommonBehavior::ExecutionImpl::resolveReferences(featureID, references);
}

void CallEventExecutionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::CommonBehavior::ExecutionImpl::saveContent(saveHandler);
	
	fUML::MDE4CPP_Extensions::FUML_ObjectImpl::saveContent(saveHandler);
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	uml::ElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void CallEventExecutionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSSM::Semantics::CommonBehavior::CommonBehaviorPackage> package = PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance();
		// Add attributes
          if ( this->eIsSet(package->getCallEventExecution_Attribute_callerSuspended()) )
          {
			saveHandler->addAttribute("callerSuspended", this->getCallerSuspended());
          }
	// Add references
	if ( this->eIsSet(package->getCallEventExecution_Attribute_behavior()) )
	{
		saveHandler->addReference(this->getBehavior(), "behavior", getBehavior()->eClass() != uml::umlPackage::eInstance()->getBehavior_Class()); 
	}
	if ( this->eIsSet(package->getCallEventExecution_Attribute_callerContext()) )
	{
		saveHandler->addReference(this->getCallerContext(), "callerContext", getCallerContext()->eClass() != fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_Object_Class()); 
	}
	if ( this->eIsSet(package->getCallEventExecution_Attribute_operation()) )
	{
		saveHandler->addReference(this->getOperation(), "operation", getOperation()->eClass() != uml::umlPackage::eInstance()->getOperation_Class()); 
	}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& CallEventExecutionImpl::eStaticClass() const
{
	return PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getCallEventExecution_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> CallEventExecutionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::CALLEVENTEXECUTION_ATTRIBUTE_BEHAVIOR:
			return eAny(getBehavior(),uml::umlPackage::BEHAVIOR_CLASS,false); //115
		case PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::CALLEVENTEXECUTION_ATTRIBUTE_CALLERCONTEXT:
			return eAny(getCallerContext(),fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::FUML_OBJECT_CLASS,false); //113
		case PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::CALLEVENTEXECUTION_ATTRIBUTE_CALLERSUSPENDED:
			return eAny(getCallerSuspended(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //112
		case PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::CALLEVENTEXECUTION_ATTRIBUTE_OPERATION:
			return eAny(getOperation(),uml::umlPackage::OPERATION_CLASS,false); //114
	}
	return fUML::Semantics::CommonBehavior::ExecutionImpl::eGet(featureID, resolve, coreType);
}

bool CallEventExecutionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::CALLEVENTEXECUTION_ATTRIBUTE_BEHAVIOR:
			return getBehavior() != nullptr; //115
		case PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::CALLEVENTEXECUTION_ATTRIBUTE_CALLERCONTEXT:
			return getCallerContext() != nullptr; //113
		case PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::CALLEVENTEXECUTION_ATTRIBUTE_CALLERSUSPENDED:
			return getCallerSuspended() != false; //112
		case PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::CALLEVENTEXECUTION_ATTRIBUTE_OPERATION:
			return getOperation() != nullptr; //114
	}
	return fUML::Semantics::CommonBehavior::ExecutionImpl::internalEIsSet(featureID);
}

bool CallEventExecutionImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::CALLEVENTEXECUTION_ATTRIBUTE_BEHAVIOR:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Behavior> _behavior = std::dynamic_pointer_cast<uml::Behavior>(eObject);
					if(_behavior)
					{
						setBehavior(_behavior); //115
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'behavior'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'behavior'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::CALLEVENTEXECUTION_ATTRIBUTE_CALLERCONTEXT:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<fUML::MDE4CPP_Extensions::FUML_Object> _callerContext = std::dynamic_pointer_cast<fUML::MDE4CPP_Extensions::FUML_Object>(eObject);
					if(_callerContext)
					{
						setCallerContext(_callerContext); //113
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'callerContext'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'callerContext'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::CALLEVENTEXECUTION_ATTRIBUTE_CALLERSUSPENDED:
		{
			try
			{
				bool _callerSuspended = newValue->get<bool>();
				setCallerSuspended(_callerSuspended); //112
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'callerSuspended'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case PSSM::Semantics::CommonBehavior::CommonBehaviorPackage::CALLEVENTEXECUTION_ATTRIBUTE_OPERATION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Operation> _operation = std::dynamic_pointer_cast<uml::Operation>(eObject);
					if(_operation)
					{
						setOperation(_operation); //114
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'operation'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'operation'. Failed to set feature!")
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
std::shared_ptr<Any> CallEventExecutionImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// PSSM::Semantics::CommonBehavior::CallEventExecution::_send(PSSM::Semantics::CommonBehavior::CallEventOccurrence): 1678519053
		case CommonBehaviorPackage::CALLEVENTEXECUTION_OPERATION__SEND_CALLEVENTOCCURRENCE:
		{
			//Retrieve input parameter 'eventOccurrence'
			//parameter 0
			std::shared_ptr<PSSM::Semantics::CommonBehavior::CallEventOccurrence> incoming_param_eventOccurrence;
			Bag<Any>::const_iterator incoming_param_eventOccurrence_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_eventOccurrence_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_eventOccurrence = std::dynamic_pointer_cast<PSSM::Semantics::CommonBehavior::CallEventOccurrence>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'eventOccurrence'. Failed to invoke operation '_send'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'eventOccurrence'. Failed to invoke operation '_send'!")
					return nullptr;
				}
			}
		
			this->_send(incoming_param_eventOccurrence);
			break;
		}
		// PSSM::Semantics::CommonBehavior::CallEventExecution::_suspend(): 515841911
		case CommonBehaviorPackage::CALLEVENTEXECUTION_OPERATION__SUSPEND:
		{
			this->_suspend();
			break;
		}
		// PSSM::Semantics::CommonBehavior::CallEventExecution::execute(): 1935366821
		case CommonBehaviorPackage::CALLEVENTEXECUTION_OPERATION_EXECUTE:
		{
			this->execute();
			break;
		}
		// PSSM::Semantics::CommonBehavior::CallEventExecution::getInputParameterValues() : fUML::Semantics::CommonBehavior::ParameterValue[*]: 4255590145
		case CommonBehaviorPackage::CALLEVENTEXECUTION_OPERATION_GETINPUTPARAMETERVALUES:
		{
			std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> resultList = this->getInputParameterValues();
			return eEcoreContainerAny(resultList,fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_CLASS);
			break;
		}
		// PSSM::Semantics::CommonBehavior::CallEventExecution::releaseCaller(): 1070378962
		case CommonBehaviorPackage::CALLEVENTEXECUTION_OPERATION_RELEASECALLER:
		{
			this->releaseCaller();
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

std::shared_ptr<PSSM::Semantics::CommonBehavior::CallEventExecution> CallEventExecutionImpl::getThisCallEventExecutionPtr() const
{
	return m_thisCallEventExecutionPtr.lock();
}
void CallEventExecutionImpl::setThisCallEventExecutionPtr(std::weak_ptr<PSSM::Semantics::CommonBehavior::CallEventExecution> thisCallEventExecutionPtr)
{
	m_thisCallEventExecutionPtr = thisCallEventExecutionPtr;
	setThisExecutionPtr(thisCallEventExecutionPtr);
}


