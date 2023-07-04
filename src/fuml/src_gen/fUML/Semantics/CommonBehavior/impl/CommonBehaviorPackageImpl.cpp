#include "fUML/Semantics/CommonBehavior/impl/CommonBehaviorPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EReference.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"

//metamodel factory
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"

//depending model packages
#include "fUML/fUMLPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::CommonBehavior;

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
const std::shared_ptr<ecore::EClass>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventBehavior_Class() const
{
	return m_callEventBehavior_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventBehavior_Attribute_operation() const
{
	return m_callEventBehavior_Attribute_operation;
}


// End Class CallEventBehavior

// Begin Class CallEventExecution
const std::shared_ptr<ecore::EClass>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventExecution_Class() const
{
	return m_callEventExecution_Class;
}

const std::shared_ptr<ecore::EAttribute>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventExecution_Attribute_callerSuspended() const
{
	return m_callEventExecution_Attribute_callerSuspended;
}


const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventExecution_Operation__copy() const
{
	return m_callEventExecution_Operation__copy;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventExecution_Operation_createEventOccurrence() const
{
	return m_callEventExecution_Operation_createEventOccurrence;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventExecution_Operation_execute() const
{
	return m_callEventExecution_Operation_execute;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventExecution_Operation_getInputParameterValues() const
{
	return m_callEventExecution_Operation_getInputParameterValues;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventExecution_Operation_getOperation() const
{
	return m_callEventExecution_Operation_getOperation;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventExecution_Operation_isCallerSuspended() const
{
	return m_callEventExecution_Operation_isCallerSuspended;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventExecution_Operation_makeCall() const
{
	return m_callEventExecution_Operation_makeCall;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventExecution_Operation_new_() const
{
	return m_callEventExecution_Operation_new_;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventExecution_Operation_releaseCaller() const
{
	return m_callEventExecution_Operation_releaseCaller;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventExecution_Operation_setOutputParameterValues_ParameterValue() const
{
	return m_callEventExecution_Operation_setOutputParameterValues_ParameterValue;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventExecution_Operation_suspendCaller() const
{
	return m_callEventExecution_Operation_suspendCaller;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventExecution_Operation_wait_() const
{
	return m_callEventExecution_Operation_wait_;
}

// End Class CallEventExecution

// Begin Class CallEventOccurrence
const std::shared_ptr<ecore::EClass>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventOccurrence_Class() const
{
	return m_callEventOccurrence_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventOccurrence_Attribute_execution() const
{
	return m_callEventOccurrence_Attribute_execution;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventOccurrence_Operation_getOperation() const
{
	return m_callEventOccurrence_Operation_getOperation;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventOccurrence_Operation_getParameterValues() const
{
	return m_callEventOccurrence_Operation_getParameterValues;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventOccurrence_Operation_match_Trigger() const
{
	return m_callEventOccurrence_Operation_match_Trigger;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventOccurrence_Operation_releaseCaller() const
{
	return m_callEventOccurrence_Operation_releaseCaller;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getCallEventOccurrence_Operation_setOutputParameterValues_ParameterValue() const
{
	return m_callEventOccurrence_Operation_setOutputParameterValues_ParameterValue;
}

// End Class CallEventOccurrence

// Begin Class ClassifierBehaviorExecution
const std::shared_ptr<ecore::EClass>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getClassifierBehaviorExecution_Class() const
{
	return m_classifierBehaviorExecution_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getClassifierBehaviorExecution_Attribute_classifier() const
{
	return m_classifierBehaviorExecution_Attribute_classifier;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getClassifierBehaviorExecution_Attribute_execution() const
{
	return m_classifierBehaviorExecution_Attribute_execution;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getClassifierBehaviorExecution_Attribute_objectActivation() const
{
	return m_classifierBehaviorExecution_Attribute_objectActivation;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getClassifierBehaviorExecution_Operation__startObjectBehavior() const
{
	return m_classifierBehaviorExecution_Operation__startObjectBehavior;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getClassifierBehaviorExecution_Operation_execute_Class_ParameterValue() const
{
	return m_classifierBehaviorExecution_Operation_execute_Class_ParameterValue;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getClassifierBehaviorExecution_Operation_terminate() const
{
	return m_classifierBehaviorExecution_Operation_terminate;
}

// End Class ClassifierBehaviorExecution

// Begin Class ClassifierBehaviorInvocationEventAccepter
const std::shared_ptr<ecore::EClass>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getClassifierBehaviorInvocationEventAccepter_Class() const
{
	return m_classifierBehaviorInvocationEventAccepter_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getClassifierBehaviorInvocationEventAccepter_Attribute_classifier() const
{
	return m_classifierBehaviorInvocationEventAccepter_Attribute_classifier;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getClassifierBehaviorInvocationEventAccepter_Attribute_execution() const
{
	return m_classifierBehaviorInvocationEventAccepter_Attribute_execution;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getClassifierBehaviorInvocationEventAccepter_Attribute_objectActivation() const
{
	return m_classifierBehaviorInvocationEventAccepter_Attribute_objectActivation;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getClassifierBehaviorInvocationEventAccepter_Operation_accept_EventOccurrence() const
{
	return m_classifierBehaviorInvocationEventAccepter_Operation_accept_EventOccurrence;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getClassifierBehaviorInvocationEventAccepter_Operation_match_EventOccurrence() const
{
	return m_classifierBehaviorInvocationEventAccepter_Operation_match_EventOccurrence;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getClassifierBehaviorInvocationEventAccepter_Operation_terminate() const
{
	return m_classifierBehaviorInvocationEventAccepter_Operation_terminate;
}

// End Class ClassifierBehaviorInvocationEventAccepter

// Begin Class EventAccepter
const std::shared_ptr<ecore::EClass>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getEventAccepter_Class() const
{
	return m_eventAccepter_Class;
}



const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getEventAccepter_Operation_accept_EventOccurrence() const
{
	return m_eventAccepter_Operation_accept_EventOccurrence;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getEventAccepter_Operation_match_EventOccurrence() const
{
	return m_eventAccepter_Operation_match_EventOccurrence;
}

// End Class EventAccepter

// Begin Class EventDispatchLoop
const std::shared_ptr<ecore::EClass>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getEventDispatchLoop_Class() const
{
	return m_eventDispatchLoop_Class;
}




// End Class EventDispatchLoop

// Begin Class EventOccurrence
const std::shared_ptr<ecore::EClass>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getEventOccurrence_Class() const
{
	return m_eventOccurrence_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getEventOccurrence_Attribute_target() const
{
	return m_eventOccurrence_Attribute_target;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getEventOccurrence_Operation_doSend() const
{
	return m_eventOccurrence_Operation_doSend;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getEventOccurrence_Operation_getParameterValues_Event() const
{
	return m_eventOccurrence_Operation_getParameterValues_Event;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getEventOccurrence_Operation_getParameterValues() const
{
	return m_eventOccurrence_Operation_getParameterValues;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getEventOccurrence_Operation_match_Trigger() const
{
	return m_eventOccurrence_Operation_match_Trigger;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getEventOccurrence_Operation_matchAny_Trigger() const
{
	return m_eventOccurrence_Operation_matchAny_Trigger;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getEventOccurrence_Operation_sendTo_Reference() const
{
	return m_eventOccurrence_Operation_sendTo_Reference;
}

// End Class EventOccurrence

// Begin Class Execution
const std::shared_ptr<ecore::EClass>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Class() const
{
	return m_execution_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Attribute_behavior() const
{
	return m_execution_Attribute_behavior;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Attribute_context() const
{
	return m_execution_Attribute_context;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Attribute_parameterValues() const
{
	return m_execution_Attribute_parameterValues;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Operation__copy() const
{
	return m_execution_Operation__copy;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Operation_execute() const
{
	return m_execution_Operation_execute;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Operation_getOutputParameterValues() const
{
	return m_execution_Operation_getOutputParameterValues;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Operation_getParameterValue_Parameter() const
{
	return m_execution_Operation_getParameterValue_Parameter;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Operation_new_() const
{
	return m_execution_Operation_new_;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Operation_setParameterValue_ParameterValue() const
{
	return m_execution_Operation_setParameterValue_ParameterValue;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getExecution_Operation_terminate() const
{
	return m_execution_Operation_terminate;
}

// End Class Execution

// Begin Class FIFOGetNextEventStrategy
const std::shared_ptr<ecore::EClass>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getFIFOGetNextEventStrategy_Class() const
{
	return m_fIFOGetNextEventStrategy_Class;
}



const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getFIFOGetNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation() const
{
	return m_fIFOGetNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation;
}

// End Class FIFOGetNextEventStrategy

// Begin Class GetNextEventStrategy
const std::shared_ptr<ecore::EClass>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getGetNextEventStrategy_Class() const
{
	return m_getNextEventStrategy_Class;
}



const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getGetNextEventStrategy_Operation_getName() const
{
	return m_getNextEventStrategy_Operation_getName;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getGetNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation() const
{
	return m_getNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation;
}

// End Class GetNextEventStrategy

// Begin Class InvocationEventOccurrence
const std::shared_ptr<ecore::EClass>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getInvocationEventOccurrence_Class() const
{
	return m_invocationEventOccurrence_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getInvocationEventOccurrence_Attribute_execution() const
{
	return m_invocationEventOccurrence_Attribute_execution;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getInvocationEventOccurrence_Operation_getParameterValues() const
{
	return m_invocationEventOccurrence_Operation_getParameterValues;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getInvocationEventOccurrence_Operation_match_Trigger() const
{
	return m_invocationEventOccurrence_Operation_match_Trigger;
}

// End Class InvocationEventOccurrence

// Begin Class ObjectActivation
const std::shared_ptr<ecore::EClass>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getObjectActivation_Class() const
{
	return m_objectActivation_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getObjectActivation_Attribute_classifierBehaviorExecutions() const
{
	return m_objectActivation_Attribute_classifierBehaviorExecutions;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getObjectActivation_Attribute_eventPool() const
{
	return m_objectActivation_Attribute_eventPool;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getObjectActivation_Attribute_object() const
{
	return m_objectActivation_Attribute_object;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getObjectActivation_Attribute_waitingEventAccepters() const
{
	return m_objectActivation_Attribute_waitingEventAccepters;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getObjectActivation_Operation__register_EventAccepter() const
{
	return m_objectActivation_Operation__register_EventAccepter;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getObjectActivation_Operation__send_EventOccurrence() const
{
	return m_objectActivation_Operation__send_EventOccurrence;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getObjectActivation_Operation__startObjectBehavior() const
{
	return m_objectActivation_Operation__startObjectBehavior;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getObjectActivation_Operation_dispatchNextEvent() const
{
	return m_objectActivation_Operation_dispatchNextEvent;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getObjectActivation_Operation_retrieveNextEvent() const
{
	return m_objectActivation_Operation_retrieveNextEvent;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getObjectActivation_Operation_send_EventOccurrence() const
{
	return m_objectActivation_Operation_send_EventOccurrence;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getObjectActivation_Operation_startBehavior_Class_ParameterValue() const
{
	return m_objectActivation_Operation_startBehavior_Class_ParameterValue;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getObjectActivation_Operation_stop() const
{
	return m_objectActivation_Operation_stop;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getObjectActivation_Operation_unregister_EventAccepter() const
{
	return m_objectActivation_Operation_unregister_EventAccepter;
}

// End Class ObjectActivation

// Begin Class OpaqueBehaviorExecution
const std::shared_ptr<ecore::EClass>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getOpaqueBehaviorExecution_Class() const
{
	return m_opaqueBehaviorExecution_Class;
}



const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getOpaqueBehaviorExecution_Operation_doBody_ParameterValue_ParameterValue() const
{
	return m_opaqueBehaviorExecution_Operation_doBody_ParameterValue_ParameterValue;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getOpaqueBehaviorExecution_Operation_execute() const
{
	return m_opaqueBehaviorExecution_Operation_execute;
}

// End Class OpaqueBehaviorExecution

// Begin Class ParameterValue
const std::shared_ptr<ecore::EClass>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getParameterValue_Class() const
{
	return m_parameterValue_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getParameterValue_Attribute_parameter() const
{
	return m_parameterValue_Attribute_parameter;
}
const std::shared_ptr<ecore::EReference>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getParameterValue_Attribute_values() const
{
	return m_parameterValue_Attribute_values;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getParameterValue_Operation__copy() const
{
	return m_parameterValue_Operation__copy;
}

// End Class ParameterValue

// Begin Class SignalEventOccurrence
const std::shared_ptr<ecore::EClass>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getSignalEventOccurrence_Class() const
{
	return m_signalEventOccurrence_Class;
}


const std::shared_ptr<ecore::EReference>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getSignalEventOccurrence_Attribute_signalInstance() const
{
	return m_signalEventOccurrence_Attribute_signalInstance;
}

const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getSignalEventOccurrence_Operation_getParameterValues_Event() const
{
	return m_signalEventOccurrence_Operation_getParameterValues_Event;
}
const std::shared_ptr<ecore::EOperation>& fUML::Semantics::CommonBehavior::CommonBehaviorPackageImpl::getSignalEventOccurrence_Operation_match_Trigger() const
{
	return m_signalEventOccurrence_Operation_match_Trigger;
}

// End Class SignalEventOccurrence

