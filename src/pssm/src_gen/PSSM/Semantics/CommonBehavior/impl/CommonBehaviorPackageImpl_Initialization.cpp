#include "PSSM/Semantics/CommonBehavior/impl/CommonBehaviorPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAttribute.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EReference.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsPackage.hpp"
#include "PSSM/PSSMPackage.hpp"
#include "PSSM/Semantics/StateMachines/StateMachinesPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"


using namespace PSSM::Semantics::CommonBehavior;

void CommonBehaviorPackageImpl::initializePackageContents()
{
	if (isInitialized)
	{
		return;
	}
	isInitialized = true;

	// Initialize package
	setName(eNAME);
	setNsPrefix(eNS_PREFIX);
	setNsURI(eNS_URI);
	
	// Add supertypes to classes
	m_callEventExecution_Class->getESuperTypes()->push_back(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getExecution_Class());
	m_callEventOccurrence_Class->getESuperTypes()->push_back(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventOccurrence_Class());
	m_eventTriggeredExecution_Class->getESuperTypes()->push_back(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getExecution_Class());
	m_sM_ObjectActivation_Class->getESuperTypes()->push_back(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getObjectActivation_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeCallEventExecutionContent();
	initializeCallEventOccurrenceContent();
	initializeEventTriggeredExecutionContent();
	initializeSM_ObjectActivationContent();

	initializePackageEDataTypes();

}

void CommonBehaviorPackageImpl::initializeCallEventExecutionContent()
{
	m_callEventExecution_Class->setName("CallEventExecution");
	m_callEventExecution_Class->setAbstract(false);
	m_callEventExecution_Class->setInterface(false);
	
	m_callEventExecution_Class->_setID(CALLEVENTEXECUTION_CLASS);
	
	/*
	 * EAttributes
	 */
	m_callEventExecution_Attribute_callerSuspended = getCallEventExecution_Attribute_callerSuspended();
	m_callEventExecution_Attribute_callerSuspended->setName("callerSuspended");
	m_callEventExecution_Attribute_callerSuspended->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_callEventExecution_Attribute_callerSuspended->setLowerBound(1);
	m_callEventExecution_Attribute_callerSuspended->setUpperBound(1);
	m_callEventExecution_Attribute_callerSuspended->setTransient(false);
	m_callEventExecution_Attribute_callerSuspended->setVolatile(false);
	m_callEventExecution_Attribute_callerSuspended->setChangeable(true);
	m_callEventExecution_Attribute_callerSuspended->setUnsettable(false);
	m_callEventExecution_Attribute_callerSuspended->setUnique(true);
	m_callEventExecution_Attribute_callerSuspended->setDerived(false);
	m_callEventExecution_Attribute_callerSuspended->setOrdered(false);
	m_callEventExecution_Attribute_callerSuspended->setID(false);
	m_callEventExecution_Attribute_callerSuspended->setDefaultValueLiteral("");
	
	m_callEventExecution_Attribute_callerSuspended->_setID(CALLEVENTEXECUTION_ATTRIBUTE_CALLERSUSPENDED);
	
	/*
	 * EReferences
	 */
	m_callEventExecution_Attribute_behavior->setName("behavior");
	m_callEventExecution_Attribute_behavior->setEType(uml::umlPackage::eInstance()->getBehavior_Class());
	m_callEventExecution_Attribute_behavior->setLowerBound(1);
	m_callEventExecution_Attribute_behavior->setUpperBound(1);
	m_callEventExecution_Attribute_behavior->setTransient(false);
	m_callEventExecution_Attribute_behavior->setVolatile(false);
	m_callEventExecution_Attribute_behavior->setChangeable(true);
	m_callEventExecution_Attribute_behavior->setUnsettable(false);
	m_callEventExecution_Attribute_behavior->setUnique(true);
	m_callEventExecution_Attribute_behavior->setDerived(false);
	m_callEventExecution_Attribute_behavior->setOrdered(false);
	m_callEventExecution_Attribute_behavior->setContainment(false);
	m_callEventExecution_Attribute_behavior->setResolveProxies(true);
	m_callEventExecution_Attribute_behavior->setDefaultValueLiteral("");	
	
	m_callEventExecution_Attribute_behavior->_setID(CALLEVENTEXECUTION_ATTRIBUTE_BEHAVIOR);
	m_callEventExecution_Attribute_callerContext->setName("callerContext");
	m_callEventExecution_Attribute_callerContext->setEType(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_Object_Class());
	m_callEventExecution_Attribute_callerContext->setLowerBound(1);
	m_callEventExecution_Attribute_callerContext->setUpperBound(1);
	m_callEventExecution_Attribute_callerContext->setTransient(false);
	m_callEventExecution_Attribute_callerContext->setVolatile(false);
	m_callEventExecution_Attribute_callerContext->setChangeable(true);
	m_callEventExecution_Attribute_callerContext->setUnsettable(false);
	m_callEventExecution_Attribute_callerContext->setUnique(true);
	m_callEventExecution_Attribute_callerContext->setDerived(false);
	m_callEventExecution_Attribute_callerContext->setOrdered(false);
	m_callEventExecution_Attribute_callerContext->setContainment(false);
	m_callEventExecution_Attribute_callerContext->setResolveProxies(true);
	m_callEventExecution_Attribute_callerContext->setDefaultValueLiteral("");	
	
	m_callEventExecution_Attribute_callerContext->_setID(CALLEVENTEXECUTION_ATTRIBUTE_CALLERCONTEXT);
	m_callEventExecution_Attribute_operation->setName("operation");
	m_callEventExecution_Attribute_operation->setEType(uml::umlPackage::eInstance()->getOperation_Class());
	m_callEventExecution_Attribute_operation->setLowerBound(1);
	m_callEventExecution_Attribute_operation->setUpperBound(1);
	m_callEventExecution_Attribute_operation->setTransient(false);
	m_callEventExecution_Attribute_operation->setVolatile(false);
	m_callEventExecution_Attribute_operation->setChangeable(true);
	m_callEventExecution_Attribute_operation->setUnsettable(false);
	m_callEventExecution_Attribute_operation->setUnique(true);
	m_callEventExecution_Attribute_operation->setDerived(false);
	m_callEventExecution_Attribute_operation->setOrdered(false);
	m_callEventExecution_Attribute_operation->setContainment(false);
	m_callEventExecution_Attribute_operation->setResolveProxies(true);
	m_callEventExecution_Attribute_operation->setDefaultValueLiteral("");	
	
	m_callEventExecution_Attribute_operation->_setID(CALLEVENTEXECUTION_ATTRIBUTE_OPERATION);
	
	/*
	 * EOperations
	 */
	m_callEventExecution_Operation__send_CallEventOccurrence->setName("_send");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_callEventExecution_Operation__send_CallEventOccurrence->setEType(unknownClass);
	}
	m_callEventExecution_Operation__send_CallEventOccurrence->setLowerBound(1);
	m_callEventExecution_Operation__send_CallEventOccurrence->setUpperBound(1);
	m_callEventExecution_Operation__send_CallEventOccurrence->setUnique(true);
	m_callEventExecution_Operation__send_CallEventOccurrence->setOrdered(false);
	
	m_callEventExecution_Operation__send_CallEventOccurrence->_setID(CALLEVENTEXECUTION_OPERATION__SEND_CALLEVENTOCCURRENCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_callEventExecution_Operation__send_CallEventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_callEventExecution_Operation__suspend->setName("_suspend");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_callEventExecution_Operation__suspend->setEType(unknownClass);
	}
	m_callEventExecution_Operation__suspend->setLowerBound(1);
	m_callEventExecution_Operation__suspend->setUpperBound(1);
	m_callEventExecution_Operation__suspend->setUnique(true);
	m_callEventExecution_Operation__suspend->setOrdered(false);
	
	m_callEventExecution_Operation__suspend->_setID(CALLEVENTEXECUTION_OPERATION__SUSPEND);
	
	
	m_callEventExecution_Operation_execute->setName("execute");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_callEventExecution_Operation_execute->setEType(unknownClass);
	}
	m_callEventExecution_Operation_execute->setLowerBound(1);
	m_callEventExecution_Operation_execute->setUpperBound(1);
	m_callEventExecution_Operation_execute->setUnique(true);
	m_callEventExecution_Operation_execute->setOrdered(false);
	
	m_callEventExecution_Operation_execute->_setID(CALLEVENTEXECUTION_OPERATION_EXECUTE);
	
	
	m_callEventExecution_Operation_getInputParameterValues->setName("getInputParameterValues");
	m_callEventExecution_Operation_getInputParameterValues->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getParameterValue_Class());
	m_callEventExecution_Operation_getInputParameterValues->setLowerBound(0);
	m_callEventExecution_Operation_getInputParameterValues->setUpperBound(-1);
	m_callEventExecution_Operation_getInputParameterValues->setUnique(true);
	m_callEventExecution_Operation_getInputParameterValues->setOrdered(false);
	
	m_callEventExecution_Operation_getInputParameterValues->_setID(CALLEVENTEXECUTION_OPERATION_GETINPUTPARAMETERVALUES);
	
	
	m_callEventExecution_Operation_releaseCaller->setName("releaseCaller");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_callEventExecution_Operation_releaseCaller->setEType(unknownClass);
	}
	m_callEventExecution_Operation_releaseCaller->setLowerBound(1);
	m_callEventExecution_Operation_releaseCaller->setUpperBound(1);
	m_callEventExecution_Operation_releaseCaller->setUnique(true);
	m_callEventExecution_Operation_releaseCaller->setOrdered(false);
	
	m_callEventExecution_Operation_releaseCaller->_setID(CALLEVENTEXECUTION_OPERATION_RELEASECALLER);
	
	
	
}

void CommonBehaviorPackageImpl::initializeCallEventOccurrenceContent()
{
	m_callEventOccurrence_Class->setName("CallEventOccurrence");
	m_callEventOccurrence_Class->setAbstract(false);
	m_callEventOccurrence_Class->setInterface(false);
	
	m_callEventOccurrence_Class->_setID(CALLEVENTOCCURRENCE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_callEventOccurrence_Attribute_execution->setName("execution");
	m_callEventOccurrence_Attribute_execution->setEType(getCallEventExecution_Class());
	m_callEventOccurrence_Attribute_execution->setLowerBound(1);
	m_callEventOccurrence_Attribute_execution->setUpperBound(1);
	m_callEventOccurrence_Attribute_execution->setTransient(false);
	m_callEventOccurrence_Attribute_execution->setVolatile(false);
	m_callEventOccurrence_Attribute_execution->setChangeable(true);
	m_callEventOccurrence_Attribute_execution->setUnsettable(false);
	m_callEventOccurrence_Attribute_execution->setUnique(true);
	m_callEventOccurrence_Attribute_execution->setDerived(false);
	m_callEventOccurrence_Attribute_execution->setOrdered(false);
	m_callEventOccurrence_Attribute_execution->setContainment(false);
	m_callEventOccurrence_Attribute_execution->setResolveProxies(true);
	m_callEventOccurrence_Attribute_execution->setDefaultValueLiteral("");	
	
	m_callEventOccurrence_Attribute_execution->_setID(CALLEVENTOCCURRENCE_ATTRIBUTE_EXECUTION);
	
	/*
	 * EOperations
	 */
	
}

void CommonBehaviorPackageImpl::initializeEventTriggeredExecutionContent()
{
	m_eventTriggeredExecution_Class->setName("EventTriggeredExecution");
	m_eventTriggeredExecution_Class->setAbstract(false);
	m_eventTriggeredExecution_Class->setInterface(false);
	
	m_eventTriggeredExecution_Class->_setID(EVENTTRIGGEREDEXECUTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_eventTriggeredExecution_Attribute_triggeringEventOccurrence->setName("triggeringEventOccurrence");
	m_eventTriggeredExecution_Attribute_triggeringEventOccurrence->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventOccurrence_Class());
	m_eventTriggeredExecution_Attribute_triggeringEventOccurrence->setLowerBound(1);
	m_eventTriggeredExecution_Attribute_triggeringEventOccurrence->setUpperBound(1);
	m_eventTriggeredExecution_Attribute_triggeringEventOccurrence->setTransient(false);
	m_eventTriggeredExecution_Attribute_triggeringEventOccurrence->setVolatile(false);
	m_eventTriggeredExecution_Attribute_triggeringEventOccurrence->setChangeable(true);
	m_eventTriggeredExecution_Attribute_triggeringEventOccurrence->setUnsettable(false);
	m_eventTriggeredExecution_Attribute_triggeringEventOccurrence->setUnique(true);
	m_eventTriggeredExecution_Attribute_triggeringEventOccurrence->setDerived(false);
	m_eventTriggeredExecution_Attribute_triggeringEventOccurrence->setOrdered(false);
	m_eventTriggeredExecution_Attribute_triggeringEventOccurrence->setContainment(false);
	m_eventTriggeredExecution_Attribute_triggeringEventOccurrence->setResolveProxies(true);
	m_eventTriggeredExecution_Attribute_triggeringEventOccurrence->setDefaultValueLiteral("");	
	
	m_eventTriggeredExecution_Attribute_triggeringEventOccurrence->_setID(EVENTTRIGGEREDEXECUTION_ATTRIBUTE_TRIGGERINGEVENTOCCURRENCE);
	m_eventTriggeredExecution_Attribute_wrappedExecution->setName("wrappedExecution");
	m_eventTriggeredExecution_Attribute_wrappedExecution->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getExecution_Class());
	m_eventTriggeredExecution_Attribute_wrappedExecution->setLowerBound(1);
	m_eventTriggeredExecution_Attribute_wrappedExecution->setUpperBound(1);
	m_eventTriggeredExecution_Attribute_wrappedExecution->setTransient(false);
	m_eventTriggeredExecution_Attribute_wrappedExecution->setVolatile(false);
	m_eventTriggeredExecution_Attribute_wrappedExecution->setChangeable(true);
	m_eventTriggeredExecution_Attribute_wrappedExecution->setUnsettable(false);
	m_eventTriggeredExecution_Attribute_wrappedExecution->setUnique(true);
	m_eventTriggeredExecution_Attribute_wrappedExecution->setDerived(false);
	m_eventTriggeredExecution_Attribute_wrappedExecution->setOrdered(false);
	m_eventTriggeredExecution_Attribute_wrappedExecution->setContainment(false);
	m_eventTriggeredExecution_Attribute_wrappedExecution->setResolveProxies(true);
	m_eventTriggeredExecution_Attribute_wrappedExecution->setDefaultValueLiteral("");	
	
	m_eventTriggeredExecution_Attribute_wrappedExecution->_setID(EVENTTRIGGEREDEXECUTION_ATTRIBUTE_WRAPPEDEXECUTION);
	
	/*
	 * EOperations
	 */
	m_eventTriggeredExecution_Operation_execute->setName("execute");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_eventTriggeredExecution_Operation_execute->setEType(unknownClass);
	}
	m_eventTriggeredExecution_Operation_execute->setLowerBound(1);
	m_eventTriggeredExecution_Operation_execute->setUpperBound(1);
	m_eventTriggeredExecution_Operation_execute->setUnique(true);
	m_eventTriggeredExecution_Operation_execute->setOrdered(false);
	
	m_eventTriggeredExecution_Operation_execute->_setID(EVENTTRIGGEREDEXECUTION_OPERATION_EXECUTE);
	
	
	m_eventTriggeredExecution_Operation_finalize->setName("finalize");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_eventTriggeredExecution_Operation_finalize->setEType(unknownClass);
	}
	m_eventTriggeredExecution_Operation_finalize->setLowerBound(0);
	m_eventTriggeredExecution_Operation_finalize->setUpperBound(1);
	m_eventTriggeredExecution_Operation_finalize->setUnique(true);
	m_eventTriggeredExecution_Operation_finalize->setOrdered(false);
	
	m_eventTriggeredExecution_Operation_finalize->_setID(EVENTTRIGGEREDEXECUTION_OPERATION_FINALIZE);
	
	
	m_eventTriggeredExecution_Operation_initialize_Behavior->setName("initialize");
	m_eventTriggeredExecution_Operation_initialize_Behavior->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getParameterValue_Class());
	m_eventTriggeredExecution_Operation_initialize_Behavior->setLowerBound(0);
	m_eventTriggeredExecution_Operation_initialize_Behavior->setUpperBound(-1);
	m_eventTriggeredExecution_Operation_initialize_Behavior->setUnique(true);
	m_eventTriggeredExecution_Operation_initialize_Behavior->setOrdered(false);
	
	m_eventTriggeredExecution_Operation_initialize_Behavior->_setID(EVENTTRIGGEREDEXECUTION_OPERATION_INITIALIZE_BEHAVIOR);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_eventTriggeredExecution_Operation_initialize_Behavior);
		parameter->setName("behavior");
		parameter->setEType(uml::umlPackage::eInstance()->getBehavior_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void CommonBehaviorPackageImpl::initializeSM_ObjectActivationContent()
{
	m_sM_ObjectActivation_Class->setName("SM_ObjectActivation");
	m_sM_ObjectActivation_Class->setAbstract(false);
	m_sM_ObjectActivation_Class->setInterface(false);
	
	m_sM_ObjectActivation_Class->_setID(SM_OBJECTACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_sM_ObjectActivation_Attribute_deferredEventPool->setName("deferredEventPool");
	m_sM_ObjectActivation_Attribute_deferredEventPool->setEType(PSSM::Semantics::StateMachines::StateMachinesPackage::eInstance()->getDeferredEventOccurrence_Class());
	m_sM_ObjectActivation_Attribute_deferredEventPool->setLowerBound(0);
	m_sM_ObjectActivation_Attribute_deferredEventPool->setUpperBound(-1);
	m_sM_ObjectActivation_Attribute_deferredEventPool->setTransient(false);
	m_sM_ObjectActivation_Attribute_deferredEventPool->setVolatile(false);
	m_sM_ObjectActivation_Attribute_deferredEventPool->setChangeable(true);
	m_sM_ObjectActivation_Attribute_deferredEventPool->setUnsettable(false);
	m_sM_ObjectActivation_Attribute_deferredEventPool->setUnique(true);
	m_sM_ObjectActivation_Attribute_deferredEventPool->setDerived(false);
	m_sM_ObjectActivation_Attribute_deferredEventPool->setOrdered(false);
	m_sM_ObjectActivation_Attribute_deferredEventPool->setContainment(false);
	m_sM_ObjectActivation_Attribute_deferredEventPool->setResolveProxies(true);
	m_sM_ObjectActivation_Attribute_deferredEventPool->setDefaultValueLiteral("");	
	
	m_sM_ObjectActivation_Attribute_deferredEventPool->_setID(SM_OBJECTACTIVATION_ATTRIBUTE_DEFERREDEVENTPOOL);
	
	/*
	 * EOperations
	 */
	m_sM_ObjectActivation_Operation_getDeferredEventInsertionIndex->setName("getDeferredEventInsertionIndex");
	m_sM_ObjectActivation_Operation_getDeferredEventInsertionIndex->setEType(types::typesPackage::eInstance()->getInteger_Class());
	m_sM_ObjectActivation_Operation_getDeferredEventInsertionIndex->setLowerBound(1);
	m_sM_ObjectActivation_Operation_getDeferredEventInsertionIndex->setUpperBound(1);
	m_sM_ObjectActivation_Operation_getDeferredEventInsertionIndex->setUnique(true);
	m_sM_ObjectActivation_Operation_getDeferredEventInsertionIndex->setOrdered(false);
	
	m_sM_ObjectActivation_Operation_getDeferredEventInsertionIndex->_setID(SM_OBJECTACTIVATION_OPERATION_GETDEFERREDEVENTINSERTIONINDEX);
	
	
	m_sM_ObjectActivation_Operation_getNextCompletionEvent->setName("getNextCompletionEvent");
	m_sM_ObjectActivation_Operation_getNextCompletionEvent->setEType(PSSM::Semantics::StateMachines::StateMachinesPackage::eInstance()->getCompletionEventOccurrence_Class());
	m_sM_ObjectActivation_Operation_getNextCompletionEvent->setLowerBound(1);
	m_sM_ObjectActivation_Operation_getNextCompletionEvent->setUpperBound(1);
	m_sM_ObjectActivation_Operation_getNextCompletionEvent->setUnique(true);
	m_sM_ObjectActivation_Operation_getNextCompletionEvent->setOrdered(false);
	
	m_sM_ObjectActivation_Operation_getNextCompletionEvent->_setID(SM_OBJECTACTIVATION_OPERATION_GETNEXTCOMPLETIONEVENT);
	
	
	m_sM_ObjectActivation_Operation_registerCompletionEvent_StateActivation->setName("registerCompletionEvent");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_sM_ObjectActivation_Operation_registerCompletionEvent_StateActivation->setEType(unknownClass);
	}
	m_sM_ObjectActivation_Operation_registerCompletionEvent_StateActivation->setLowerBound(1);
	m_sM_ObjectActivation_Operation_registerCompletionEvent_StateActivation->setUpperBound(1);
	m_sM_ObjectActivation_Operation_registerCompletionEvent_StateActivation->setUnique(true);
	m_sM_ObjectActivation_Operation_registerCompletionEvent_StateActivation->setOrdered(false);
	
	m_sM_ObjectActivation_Operation_registerCompletionEvent_StateActivation->_setID(SM_OBJECTACTIVATION_OPERATION_REGISTERCOMPLETIONEVENT_STATEACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_sM_ObjectActivation_Operation_registerCompletionEvent_StateActivation);
		parameter->setName("stateActivation");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_sM_ObjectActivation_Operation_registerDeferredEvent_EventOccurrence_StateActivation->setName("registerDeferredEvent");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_sM_ObjectActivation_Operation_registerDeferredEvent_EventOccurrence_StateActivation->setEType(unknownClass);
	}
	m_sM_ObjectActivation_Operation_registerDeferredEvent_EventOccurrence_StateActivation->setLowerBound(1);
	m_sM_ObjectActivation_Operation_registerDeferredEvent_EventOccurrence_StateActivation->setUpperBound(1);
	m_sM_ObjectActivation_Operation_registerDeferredEvent_EventOccurrence_StateActivation->setUnique(true);
	m_sM_ObjectActivation_Operation_registerDeferredEvent_EventOccurrence_StateActivation->setOrdered(false);
	
	m_sM_ObjectActivation_Operation_registerDeferredEvent_EventOccurrence_StateActivation->_setID(SM_OBJECTACTIVATION_OPERATION_REGISTERDEFERREDEVENT_EVENTOCCURRENCE_STATEACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_sM_ObjectActivation_Operation_registerDeferredEvent_EventOccurrence_StateActivation);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_sM_ObjectActivation_Operation_registerDeferredEvent_EventOccurrence_StateActivation);
		parameter->setName("stateActivation");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_sM_ObjectActivation_Operation_releaseDeferredEvents_StateActivation->setName("releaseDeferredEvents");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_sM_ObjectActivation_Operation_releaseDeferredEvents_StateActivation->setEType(unknownClass);
	}
	m_sM_ObjectActivation_Operation_releaseDeferredEvents_StateActivation->setLowerBound(1);
	m_sM_ObjectActivation_Operation_releaseDeferredEvents_StateActivation->setUpperBound(1);
	m_sM_ObjectActivation_Operation_releaseDeferredEvents_StateActivation->setUnique(true);
	m_sM_ObjectActivation_Operation_releaseDeferredEvents_StateActivation->setOrdered(false);
	
	m_sM_ObjectActivation_Operation_releaseDeferredEvents_StateActivation->_setID(SM_OBJECTACTIVATION_OPERATION_RELEASEDEFERREDEVENTS_STATEACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_sM_ObjectActivation_Operation_releaseDeferredEvents_StateActivation);
		parameter->setName("deferringState");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_sM_ObjectActivation_Operation_retrieveNextEvent->setName("retrieveNextEvent");
	m_sM_ObjectActivation_Operation_retrieveNextEvent->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventOccurrence_Class());
	m_sM_ObjectActivation_Operation_retrieveNextEvent->setLowerBound(1);
	m_sM_ObjectActivation_Operation_retrieveNextEvent->setUpperBound(1);
	m_sM_ObjectActivation_Operation_retrieveNextEvent->setUnique(true);
	m_sM_ObjectActivation_Operation_retrieveNextEvent->setOrdered(false);
	
	m_sM_ObjectActivation_Operation_retrieveNextEvent->_setID(SM_OBJECTACTIVATION_OPERATION_RETRIEVENEXTEVENT);
	
	
	
}

void CommonBehaviorPackageImpl::initializePackageEDataTypes()
{
	
}

