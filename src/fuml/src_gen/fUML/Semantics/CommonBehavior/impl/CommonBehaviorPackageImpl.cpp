#include "fUML/Semantics/CommonBehavior/impl/CommonBehaviorPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EClass.hpp"

//metamodel factory
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::CommonBehavior;


//static initialisation
const std::string CommonBehaviorPackage::eNAME ="CommonBehavior";
const std::string CommonBehaviorPackage::eNS_URI ="http:///fUML_Semantics/Semantics/CommonBehavior.ecore";
const std::string CommonBehaviorPackage::eNS_PREFIX ="fUML_Semantics.Semantics.CommonBehavior";

bool CommonBehaviorPackageImpl::isInited = false;

CommonBehaviorPackageImpl::CommonBehaviorPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( CommonBehaviorFactory::eInstance()));
}

CommonBehaviorPackageImpl::~CommonBehaviorPackageImpl()
{
}

CommonBehaviorPackage* CommonBehaviorPackageImpl::create()
{
	if (isInited)
	{
		return CommonBehaviorPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    CommonBehaviorPackageImpl * metaModelPackage = new CommonBehaviorPackageImpl();
    return metaModelPackage;
}

void CommonBehaviorPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}



// Begin Class CallEventBehavior
std::shared_ptr<ecore::EClass> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventBehavior_Class() const
{
	return m_callEventBehavior_Class;
}


std::shared_ptr<ecore::EReference> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventBehavior_Attribute_operation() const
{
	return m_callEventBehavior_Attribute_operation;
}


// End Class CallEventBehavior

// Begin Class CallEventExecution
std::shared_ptr<ecore::EClass> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventExecution_Class() const
{
	return m_callEventExecution_Class;
}

std::shared_ptr<ecore::EAttribute> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventExecution_Attribute_callerSuspended() const
{
	return m_callEventExecution_Attribute_callerSuspended;
}


std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventExecution_Operation__copy() const
{
	return m_callEventExecution_Operation__copy;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventExecution_Operation_createEventOccurrence() const
{
	return m_callEventExecution_Operation_createEventOccurrence;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventExecution_Operation_execute() const
{
	return m_callEventExecution_Operation_execute;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventExecution_Operation_getInputParameterValues() const
{
	return m_callEventExecution_Operation_getInputParameterValues;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventExecution_Operation_getOperation() const
{
	return m_callEventExecution_Operation_getOperation;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventExecution_Operation_isCallerSuspended() const
{
	return m_callEventExecution_Operation_isCallerSuspended;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventExecution_Operation_makeCall() const
{
	return m_callEventExecution_Operation_makeCall;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventExecution_Operation_new_() const
{
	return m_callEventExecution_Operation_new_;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventExecution_Operation_releaseCaller() const
{
	return m_callEventExecution_Operation_releaseCaller;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventExecution_Operation_setOutputParameterValues_ParameterValue() const
{
	return m_callEventExecution_Operation_setOutputParameterValues_ParameterValue;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventExecution_Operation_suspendCaller() const
{
	return m_callEventExecution_Operation_suspendCaller;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventExecution_Operation_wait_() const
{
	return m_callEventExecution_Operation_wait_;
}

// End Class CallEventExecution

// Begin Class CallEventOccurrence
std::shared_ptr<ecore::EClass> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventOccurrence_Class() const
{
	return m_callEventOccurrence_Class;
}


std::shared_ptr<ecore::EReference> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventOccurrence_Attribute_execution() const
{
	return m_callEventOccurrence_Attribute_execution;
}

std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventOccurrence_Operation_getOperation() const
{
	return m_callEventOccurrence_Operation_getOperation;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventOccurrence_Operation_getParameterValues() const
{
	return m_callEventOccurrence_Operation_getParameterValues;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventOccurrence_Operation_match_Trigger() const
{
	return m_callEventOccurrence_Operation_match_Trigger;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventOccurrence_Operation_releaseCaller() const
{
	return m_callEventOccurrence_Operation_releaseCaller;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventOccurrence_Operation_setOutputParameterValues_ParameterValue() const
{
	return m_callEventOccurrence_Operation_setOutputParameterValues_ParameterValue;
}

// End Class CallEventOccurrence

// Begin Class ClassifierBehaviorExecution
std::shared_ptr<ecore::EClass> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getClassifierBehaviorExecution_Class() const
{
	return m_classifierBehaviorExecution_Class;
}


std::shared_ptr<ecore::EReference> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getClassifierBehaviorExecution_Attribute_classifier() const
{
	return m_classifierBehaviorExecution_Attribute_classifier;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getClassifierBehaviorExecution_Attribute_execution() const
{
	return m_classifierBehaviorExecution_Attribute_execution;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getClassifierBehaviorExecution_Attribute_objectActivation() const
{
	return m_classifierBehaviorExecution_Attribute_objectActivation;
}

std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getClassifierBehaviorExecution_Operation__startObjectBehavior() const
{
	return m_classifierBehaviorExecution_Operation__startObjectBehavior;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getClassifierBehaviorExecution_Operation_execute_Class_ParameterValue() const
{
	return m_classifierBehaviorExecution_Operation_execute_Class_ParameterValue;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getClassifierBehaviorExecution_Operation_terminate() const
{
	return m_classifierBehaviorExecution_Operation_terminate;
}

// End Class ClassifierBehaviorExecution

// Begin Class ClassifierBehaviorInvocationEventAccepter
std::shared_ptr<ecore::EClass> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getClassifierBehaviorInvocationEventAccepter_Class() const
{
	return m_classifierBehaviorInvocationEventAccepter_Class;
}


std::shared_ptr<ecore::EReference> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getClassifierBehaviorInvocationEventAccepter_Attribute_classifier() const
{
	return m_classifierBehaviorInvocationEventAccepter_Attribute_classifier;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getClassifierBehaviorInvocationEventAccepter_Attribute_execution() const
{
	return m_classifierBehaviorInvocationEventAccepter_Attribute_execution;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getClassifierBehaviorInvocationEventAccepter_Attribute_objectActivation() const
{
	return m_classifierBehaviorInvocationEventAccepter_Attribute_objectActivation;
}

std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getClassifierBehaviorInvocationEventAccepter_Operation_accept_EventOccurrence() const
{
	return m_classifierBehaviorInvocationEventAccepter_Operation_accept_EventOccurrence;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getClassifierBehaviorInvocationEventAccepter_Operation_match_EventOccurrence() const
{
	return m_classifierBehaviorInvocationEventAccepter_Operation_match_EventOccurrence;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getClassifierBehaviorInvocationEventAccepter_Operation_terminate() const
{
	return m_classifierBehaviorInvocationEventAccepter_Operation_terminate;
}

// End Class ClassifierBehaviorInvocationEventAccepter

// Begin Class EventAccepter
std::shared_ptr<ecore::EClass> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getEventAccepter_Class() const
{
	return m_eventAccepter_Class;
}



std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getEventAccepter_Operation_accept_SignalInstance() const
{
	return m_eventAccepter_Operation_accept_SignalInstance;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getEventAccepter_Operation_match_SignalInstance() const
{
	return m_eventAccepter_Operation_match_SignalInstance;
}

// End Class EventAccepter

// Begin Class EventDispatchLoop
std::shared_ptr<ecore::EClass> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getEventDispatchLoop_Class() const
{
	return m_eventDispatchLoop_Class;
}




// End Class EventDispatchLoop

// Begin Class EventOccurrence
std::shared_ptr<ecore::EClass> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getEventOccurrence_Class() const
{
	return m_eventOccurrence_Class;
}


std::shared_ptr<ecore::EReference> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getEventOccurrence_Attribute_target() const
{
	return m_eventOccurrence_Attribute_target;
}

std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getEventOccurrence_Operation_doSend() const
{
	return m_eventOccurrence_Operation_doSend;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getEventOccurrence_Operation_getParameterValues() const
{
	return m_eventOccurrence_Operation_getParameterValues;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getEventOccurrence_Operation_match_Trigger() const
{
	return m_eventOccurrence_Operation_match_Trigger;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getEventOccurrence_Operation_matchAny_Trigger() const
{
	return m_eventOccurrence_Operation_matchAny_Trigger;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getEventOccurrence_Operation_sendTo_Reference() const
{
	return m_eventOccurrence_Operation_sendTo_Reference;
}

// End Class EventOccurrence

// Begin Class Execution
std::shared_ptr<ecore::EClass> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Class() const
{
	return m_execution_Class;
}


std::shared_ptr<ecore::EReference> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Attribute_behavior() const
{
	return m_execution_Attribute_behavior;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Attribute_context() const
{
	return m_execution_Attribute_context;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Attribute_parameterValues() const
{
	return m_execution_Attribute_parameterValues;
}

std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Operation__copy() const
{
	return m_execution_Operation__copy;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Operation_execute() const
{
	return m_execution_Operation_execute;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Operation_getOutputParameterValues() const
{
	return m_execution_Operation_getOutputParameterValues;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Operation_getParameterValue_Parameter() const
{
	return m_execution_Operation_getParameterValue_Parameter;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Operation_new_() const
{
	return m_execution_Operation_new_;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Operation_setParameterValue_ParameterValue() const
{
	return m_execution_Operation_setParameterValue_ParameterValue;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Operation_terminate() const
{
	return m_execution_Operation_terminate;
}

// End Class Execution

// Begin Class FIFOGetNextEventStrategy
std::shared_ptr<ecore::EClass> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getFIFOGetNextEventStrategy_Class() const
{
	return m_fIFOGetNextEventStrategy_Class;
}




// End Class FIFOGetNextEventStrategy

// Begin Class GetNextEventStrategy
std::shared_ptr<ecore::EClass> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getGetNextEventStrategy_Class() const
{
	return m_getNextEventStrategy_Class;
}



std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getGetNextEventStrategy_Operation_getName() const
{
	return m_getNextEventStrategy_Operation_getName;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getGetNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation() const
{
	return m_getNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation;
}

// End Class GetNextEventStrategy

// Begin Class InvocationEventOccurrence
std::shared_ptr<ecore::EClass> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getInvocationEventOccurrence_Class() const
{
	return m_invocationEventOccurrence_Class;
}


std::shared_ptr<ecore::EReference> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getInvocationEventOccurrence_Attribute_execution() const
{
	return m_invocationEventOccurrence_Attribute_execution;
}

std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getInvocationEventOccurrence_Operation_getParameterValues() const
{
	return m_invocationEventOccurrence_Operation_getParameterValues;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getInvocationEventOccurrence_Operation_match_Trigger() const
{
	return m_invocationEventOccurrence_Operation_match_Trigger;
}

// End Class InvocationEventOccurrence

// Begin Class ObjectActivation
std::shared_ptr<ecore::EClass> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getObjectActivation_Class() const
{
	return m_objectActivation_Class;
}


std::shared_ptr<ecore::EReference> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getObjectActivation_Attribute_classifierBehaviorExecutions() const
{
	return m_objectActivation_Attribute_classifierBehaviorExecutions;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getObjectActivation_Attribute_eventPool() const
{
	return m_objectActivation_Attribute_eventPool;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getObjectActivation_Attribute_object() const
{
	return m_objectActivation_Attribute_object;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getObjectActivation_Attribute_waitingEventAccepters() const
{
	return m_objectActivation_Attribute_waitingEventAccepters;
}

std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getObjectActivation_Operation__register_EventAccepter() const
{
	return m_objectActivation_Operation__register_EventAccepter;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getObjectActivation_Operation__send_EJavaObject() const
{
	return m_objectActivation_Operation__send_EJavaObject;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getObjectActivation_Operation__startObjectBehavior() const
{
	return m_objectActivation_Operation__startObjectBehavior;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getObjectActivation_Operation_dispatchNextEvent() const
{
	return m_objectActivation_Operation_dispatchNextEvent;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getObjectActivation_Operation_retrieveNextEvent() const
{
	return m_objectActivation_Operation_retrieveNextEvent;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getObjectActivation_Operation_send_SignalInstance() const
{
	return m_objectActivation_Operation_send_SignalInstance;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getObjectActivation_Operation_startBehavior_Class_ParameterValue() const
{
	return m_objectActivation_Operation_startBehavior_Class_ParameterValue;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getObjectActivation_Operation_stop() const
{
	return m_objectActivation_Operation_stop;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getObjectActivation_Operation_unregister_EventAccepter() const
{
	return m_objectActivation_Operation_unregister_EventAccepter;
}

// End Class ObjectActivation

// Begin Class OpaqueBehaviorExecution
std::shared_ptr<ecore::EClass> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getOpaqueBehaviorExecution_Class() const
{
	return m_opaqueBehaviorExecution_Class;
}



std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getOpaqueBehaviorExecution_Operation_doBody_ParameterValue_ParameterValue() const
{
	return m_opaqueBehaviorExecution_Operation_doBody_ParameterValue_ParameterValue;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getOpaqueBehaviorExecution_Operation_execute() const
{
	return m_opaqueBehaviorExecution_Operation_execute;
}

// End Class OpaqueBehaviorExecution

// Begin Class ParameterValue
std::shared_ptr<ecore::EClass> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getParameterValue_Class() const
{
	return m_parameterValue_Class;
}


std::shared_ptr<ecore::EReference> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getParameterValue_Attribute_parameter() const
{
	return m_parameterValue_Attribute_parameter;
}
std::shared_ptr<ecore::EReference> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getParameterValue_Attribute_values() const
{
	return m_parameterValue_Attribute_values;
}

std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getParameterValue_Operation__copy() const
{
	return m_parameterValue_Operation__copy;
}

// End Class ParameterValue

// Begin Class SignalEventOccurrence
std::shared_ptr<ecore::EClass> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getSignalEventOccurrence_Class() const
{
	return m_signalEventOccurrence_Class;
}


std::shared_ptr<ecore::EReference> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getSignalEventOccurrence_Attribute_signalInstance() const
{
	return m_signalEventOccurrence_Attribute_signalInstance;
}

std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getSignalEventOccurrence_Operation_getParameterValues() const
{
	return m_signalEventOccurrence_Operation_getParameterValues;
}
std::shared_ptr<ecore::EOperation> fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getSignalEventOccurrence_Operation_match_Trigger() const
{
	return m_signalEventOccurrence_Operation_match_Trigger;
}

// End Class SignalEventOccurrence

