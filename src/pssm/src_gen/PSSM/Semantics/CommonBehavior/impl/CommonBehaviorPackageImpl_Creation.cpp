#include "PSSM/Semantics/CommonBehavior/impl/CommonBehaviorPackageImpl.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EClass.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EParameter.hpp"

//depending model packages
#include "PSSM/PSSMPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"
//include subpackages 
 
using namespace PSSM::Semantics::CommonBehavior;

void CommonBehaviorPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();

	createCallEventExecutionContent(package, factory);
	createCallEventOccurrenceContent(package, factory);
	createEventTriggeredExecutionContent(package, factory);
	createSM_ObjectActivationContent(package, factory);

	createPackageEDataTypes(package, factory);

}

void CommonBehaviorPackageImpl::createCallEventExecutionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_callEventExecution_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CALLEVENTEXECUTION_CLASS);
	m_callEventExecution_Attribute_callerSuspended = factory->createEAttribute_as_eAttributes_in_EClass(m_callEventExecution_Class, CALLEVENTEXECUTION_ATTRIBUTE_CALLERSUSPENDED);
	
	m_callEventExecution_Attribute_behavior = factory->createEReference_as_eReferences_in_EClass(m_callEventExecution_Class, CALLEVENTEXECUTION_ATTRIBUTE_BEHAVIOR);
	m_callEventExecution_Attribute_callerContext = factory->createEReference_as_eReferences_in_EClass(m_callEventExecution_Class, CALLEVENTEXECUTION_ATTRIBUTE_CALLERCONTEXT);
	m_callEventExecution_Attribute_operation = factory->createEReference_as_eReferences_in_EClass(m_callEventExecution_Class, CALLEVENTEXECUTION_ATTRIBUTE_OPERATION);
	
	m_callEventExecution_Operation__send_CallEventOccurrence = factory->createEOperation_as_eOperations_in_EClass(m_callEventExecution_Class, CALLEVENTEXECUTION_OPERATION__SEND_CALLEVENTOCCURRENCE);
	m_callEventExecution_Operation__suspend = factory->createEOperation_as_eOperations_in_EClass(m_callEventExecution_Class, CALLEVENTEXECUTION_OPERATION__SUSPEND);
	m_callEventExecution_Operation_execute = factory->createEOperation_as_eOperations_in_EClass(m_callEventExecution_Class, CALLEVENTEXECUTION_OPERATION_EXECUTE);
	m_callEventExecution_Operation_getInputParameterValues = factory->createEOperation_as_eOperations_in_EClass(m_callEventExecution_Class, CALLEVENTEXECUTION_OPERATION_GETINPUTPARAMETERVALUES);
	m_callEventExecution_Operation_releaseCaller = factory->createEOperation_as_eOperations_in_EClass(m_callEventExecution_Class, CALLEVENTEXECUTION_OPERATION_RELEASECALLER);
	
}

void CommonBehaviorPackageImpl::createCallEventOccurrenceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_callEventOccurrence_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CALLEVENTOCCURRENCE_CLASS);
	
	m_callEventOccurrence_Attribute_execution = factory->createEReference_as_eReferences_in_EClass(m_callEventOccurrence_Class, CALLEVENTOCCURRENCE_ATTRIBUTE_EXECUTION);
	
	
}

void CommonBehaviorPackageImpl::createEventTriggeredExecutionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_eventTriggeredExecution_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EVENTTRIGGEREDEXECUTION_CLASS);
	
	m_eventTriggeredExecution_Attribute_triggeringEventOccurrence = factory->createEReference_as_eReferences_in_EClass(m_eventTriggeredExecution_Class, EVENTTRIGGEREDEXECUTION_ATTRIBUTE_TRIGGERINGEVENTOCCURRENCE);
	m_eventTriggeredExecution_Attribute_wrappedExecution = factory->createEReference_as_eReferences_in_EClass(m_eventTriggeredExecution_Class, EVENTTRIGGEREDEXECUTION_ATTRIBUTE_WRAPPEDEXECUTION);
	
	m_eventTriggeredExecution_Operation_execute = factory->createEOperation_as_eOperations_in_EClass(m_eventTriggeredExecution_Class, EVENTTRIGGEREDEXECUTION_OPERATION_EXECUTE);
	m_eventTriggeredExecution_Operation_finalize = factory->createEOperation_as_eOperations_in_EClass(m_eventTriggeredExecution_Class, EVENTTRIGGEREDEXECUTION_OPERATION_FINALIZE);
	m_eventTriggeredExecution_Operation_initialize_Behavior = factory->createEOperation_as_eOperations_in_EClass(m_eventTriggeredExecution_Class, EVENTTRIGGEREDEXECUTION_OPERATION_INITIALIZE_BEHAVIOR);
	
}

void CommonBehaviorPackageImpl::createSM_ObjectActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_sM_ObjectActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, SM_OBJECTACTIVATION_CLASS);
	
	m_sM_ObjectActivation_Attribute_deferredEventPool = factory->createEReference_as_eReferences_in_EClass(m_sM_ObjectActivation_Class, SM_OBJECTACTIVATION_ATTRIBUTE_DEFERREDEVENTPOOL);
	
	m_sM_ObjectActivation_Operation_getDeferredEventInsertionIndex = factory->createEOperation_as_eOperations_in_EClass(m_sM_ObjectActivation_Class, SM_OBJECTACTIVATION_OPERATION_GETDEFERREDEVENTINSERTIONINDEX);
	m_sM_ObjectActivation_Operation_getNextCompletionEvent = factory->createEOperation_as_eOperations_in_EClass(m_sM_ObjectActivation_Class, SM_OBJECTACTIVATION_OPERATION_GETNEXTCOMPLETIONEVENT);
	m_sM_ObjectActivation_Operation_registerCompletionEvent_StateActivation = factory->createEOperation_as_eOperations_in_EClass(m_sM_ObjectActivation_Class, SM_OBJECTACTIVATION_OPERATION_REGISTERCOMPLETIONEVENT_STATEACTIVATION);
	m_sM_ObjectActivation_Operation_registerDeferredEvent_EventOccurrence_StateActivation = factory->createEOperation_as_eOperations_in_EClass(m_sM_ObjectActivation_Class, SM_OBJECTACTIVATION_OPERATION_REGISTERDEFERREDEVENT_EVENTOCCURRENCE_STATEACTIVATION);
	m_sM_ObjectActivation_Operation_releaseDeferredEvents_StateActivation = factory->createEOperation_as_eOperations_in_EClass(m_sM_ObjectActivation_Class, SM_OBJECTACTIVATION_OPERATION_RELEASEDEFERREDEVENTS_STATEACTIVATION);
	m_sM_ObjectActivation_Operation_retrieveNextEvent = factory->createEOperation_as_eOperations_in_EClass(m_sM_ObjectActivation_Class, SM_OBJECTACTIVATION_OPERATION_RETRIEVENEXTEVENT);
	
}

void CommonBehaviorPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	
}
