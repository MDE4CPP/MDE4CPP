#include "fUML/Semantics/CommonBehavior/impl/CommonBehaviorPackageImpl.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EParameter.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"
//include subpackages 
 
using namespace fUML::Semantics::CommonBehavior;

void CommonBehaviorPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();

	createClassifierBehaviorExecutionContent(package, factory);
	createEventAccepterContent(package, factory);
	createEventOccurrenceContent(package, factory);
	createExecutionContent(package, factory);
	createFIFOGetNextEventStrategyContent(package, factory);
	createGetNextEventStrategyContent(package, factory);
	createObjectActivationContent(package, factory);
	createParameterValueContent(package, factory);
	createSignalEventOccurrenceContent(package, factory);

	createPackageEDataTypes(package, factory);

}

void CommonBehaviorPackageImpl::createClassifierBehaviorExecutionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_classifierBehaviorExecution_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CLASSIFIERBEHAVIOREXECUTION_CLASS);
	
	m_classifierBehaviorExecution_Attribute_classifier = factory->createEReference_as_eReferences_in_EClass(m_classifierBehaviorExecution_Class, CLASSIFIERBEHAVIOREXECUTION_ATTRIBUTE_CLASSIFIER);
	m_classifierBehaviorExecution_Attribute_execution = factory->createEReference_as_eReferences_in_EClass(m_classifierBehaviorExecution_Class, CLASSIFIERBEHAVIOREXECUTION_ATTRIBUTE_EXECUTION);
	m_classifierBehaviorExecution_Attribute_objectActivation = factory->createEReference_as_eReferences_in_EClass(m_classifierBehaviorExecution_Class, CLASSIFIERBEHAVIOREXECUTION_ATTRIBUTE_OBJECTACTIVATION);
	
	m_classifierBehaviorExecution_Operation__startObjectBehavior = factory->createEOperation_as_eOperations_in_EClass(m_classifierBehaviorExecution_Class, CLASSIFIERBEHAVIOREXECUTION_OPERATION__STARTOBJECTBEHAVIOR);
	m_classifierBehaviorExecution_Operation_execute_Class_ParameterValue = factory->createEOperation_as_eOperations_in_EClass(m_classifierBehaviorExecution_Class, CLASSIFIERBEHAVIOREXECUTION_OPERATION_EXECUTE_CLASS_PARAMETERVALUE);
	m_classifierBehaviorExecution_Operation_terminate = factory->createEOperation_as_eOperations_in_EClass(m_classifierBehaviorExecution_Class, CLASSIFIERBEHAVIOREXECUTION_OPERATION_TERMINATE);
	
}

void CommonBehaviorPackageImpl::createEventAccepterContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_eventAccepter_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EVENTACCEPTER_CLASS);
	
	
	m_eventAccepter_Operation_accept_EventOccurrence = factory->createEOperation_as_eOperations_in_EClass(m_eventAccepter_Class, EVENTACCEPTER_OPERATION_ACCEPT_EVENTOCCURRENCE);
	m_eventAccepter_Operation_match_EventOccurrence = factory->createEOperation_as_eOperations_in_EClass(m_eventAccepter_Class, EVENTACCEPTER_OPERATION_MATCH_EVENTOCCURRENCE);
	
}

void CommonBehaviorPackageImpl::createEventOccurrenceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_eventOccurrence_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EVENTOCCURRENCE_CLASS);
	
	m_eventOccurrence_Attribute_target = factory->createEReference_as_eReferences_in_EClass(m_eventOccurrence_Class, EVENTOCCURRENCE_ATTRIBUTE_TARGET);
	
	m_eventOccurrence_Operation_doSend = factory->createEOperation_as_eOperations_in_EClass(m_eventOccurrence_Class, EVENTOCCURRENCE_OPERATION_DOSEND);
	m_eventOccurrence_Operation_getParameterValues_Event = factory->createEOperation_as_eOperations_in_EClass(m_eventOccurrence_Class, EVENTOCCURRENCE_OPERATION_GETPARAMETERVALUES_EVENT);
	m_eventOccurrence_Operation_match_Trigger = factory->createEOperation_as_eOperations_in_EClass(m_eventOccurrence_Class, EVENTOCCURRENCE_OPERATION_MATCH_TRIGGER);
	m_eventOccurrence_Operation_matchAny_Trigger = factory->createEOperation_as_eOperations_in_EClass(m_eventOccurrence_Class, EVENTOCCURRENCE_OPERATION_MATCHANY_TRIGGER);
	m_eventOccurrence_Operation_sendTo_Element = factory->createEOperation_as_eOperations_in_EClass(m_eventOccurrence_Class, EVENTOCCURRENCE_OPERATION_SENDTO_ELEMENT);
	
}

void CommonBehaviorPackageImpl::createExecutionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_execution_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EXECUTION_CLASS);
	
	m_execution_Attribute_behavior = factory->createEReference_as_eReferences_in_EClass(m_execution_Class, EXECUTION_ATTRIBUTE_BEHAVIOR);
	m_execution_Attribute_context = factory->createEReference_as_eReferences_in_EClass(m_execution_Class, EXECUTION_ATTRIBUTE_CONTEXT);
	m_execution_Attribute_locus = factory->createEReference_as_eReferences_in_EClass(m_execution_Class, EXECUTION_ATTRIBUTE_LOCUS);
	m_execution_Attribute_parameterValues = factory->createEReference_as_eReferences_in_EClass(m_execution_Class, EXECUTION_ATTRIBUTE_PARAMETERVALUES);
	m_execution_Attribute_types = factory->createEReference_as_eReferences_in_EClass(m_execution_Class, EXECUTION_ATTRIBUTE_TYPES);
	
	m_execution_Operation__copy = factory->createEOperation_as_eOperations_in_EClass(m_execution_Class, EXECUTION_OPERATION__COPY);
	m_execution_Operation_destroy = factory->createEOperation_as_eOperations_in_EClass(m_execution_Class, EXECUTION_OPERATION_DESTROY);
	m_execution_Operation_execute = factory->createEOperation_as_eOperations_in_EClass(m_execution_Class, EXECUTION_OPERATION_EXECUTE);
	m_execution_Operation_getOutputParameterValues = factory->createEOperation_as_eOperations_in_EClass(m_execution_Class, EXECUTION_OPERATION_GETOUTPUTPARAMETERVALUES);
	m_execution_Operation_getParameterValue_Parameter = factory->createEOperation_as_eOperations_in_EClass(m_execution_Class, EXECUTION_OPERATION_GETPARAMETERVALUE_PARAMETER);
	m_execution_Operation_new_ = factory->createEOperation_as_eOperations_in_EClass(m_execution_Class, EXECUTION_OPERATION_NEW_);
	m_execution_Operation_setParameterValue_ParameterValue = factory->createEOperation_as_eOperations_in_EClass(m_execution_Class, EXECUTION_OPERATION_SETPARAMETERVALUE_PARAMETERVALUE);
	m_execution_Operation_terminate = factory->createEOperation_as_eOperations_in_EClass(m_execution_Class, EXECUTION_OPERATION_TERMINATE);
	
}

void CommonBehaviorPackageImpl::createFIFOGetNextEventStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_fIFOGetNextEventStrategy_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, FIFOGETNEXTEVENTSTRATEGY_CLASS);
	
	
	m_fIFOGetNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation = factory->createEOperation_as_eOperations_in_EClass(m_fIFOGetNextEventStrategy_Class, FIFOGETNEXTEVENTSTRATEGY_OPERATION_RETRIEVENEXTEVENT_OBJECTACTIVATION);
	
}

void CommonBehaviorPackageImpl::createGetNextEventStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_getNextEventStrategy_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, GETNEXTEVENTSTRATEGY_CLASS);
	
	
	m_getNextEventStrategy_Operation_getName = factory->createEOperation_as_eOperations_in_EClass(m_getNextEventStrategy_Class, GETNEXTEVENTSTRATEGY_OPERATION_GETNAME);
	m_getNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation = factory->createEOperation_as_eOperations_in_EClass(m_getNextEventStrategy_Class, GETNEXTEVENTSTRATEGY_OPERATION_RETRIEVENEXTEVENT_OBJECTACTIVATION);
	
}

void CommonBehaviorPackageImpl::createObjectActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_objectActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, OBJECTACTIVATION_CLASS);
	
	m_objectActivation_Attribute_classifierBehaviorExecutions = factory->createEReference_as_eReferences_in_EClass(m_objectActivation_Class, OBJECTACTIVATION_ATTRIBUTE_CLASSIFIERBEHAVIOREXECUTIONS);
	m_objectActivation_Attribute_eventPool = factory->createEReference_as_eReferences_in_EClass(m_objectActivation_Class, OBJECTACTIVATION_ATTRIBUTE_EVENTPOOL);
	m_objectActivation_Attribute_object = factory->createEReference_as_eReferences_in_EClass(m_objectActivation_Class, OBJECTACTIVATION_ATTRIBUTE_OBJECT);
	m_objectActivation_Attribute_waitingEventAccepters = factory->createEReference_as_eReferences_in_EClass(m_objectActivation_Class, OBJECTACTIVATION_ATTRIBUTE_WAITINGEVENTACCEPTERS);
	
	m_objectActivation_Operation__register_EventAccepter = factory->createEOperation_as_eOperations_in_EClass(m_objectActivation_Class, OBJECTACTIVATION_OPERATION__REGISTER_EVENTACCEPTER);
	m_objectActivation_Operation__startObjectBehavior = factory->createEOperation_as_eOperations_in_EClass(m_objectActivation_Class, OBJECTACTIVATION_OPERATION__STARTOBJECTBEHAVIOR);
	m_objectActivation_Operation_dispatchNextEvent = factory->createEOperation_as_eOperations_in_EClass(m_objectActivation_Class, OBJECTACTIVATION_OPERATION_DISPATCHNEXTEVENT);
	m_objectActivation_Operation_retrieveNextEvent = factory->createEOperation_as_eOperations_in_EClass(m_objectActivation_Class, OBJECTACTIVATION_OPERATION_RETRIEVENEXTEVENT);
	m_objectActivation_Operation_send_EventOccurrence = factory->createEOperation_as_eOperations_in_EClass(m_objectActivation_Class, OBJECTACTIVATION_OPERATION_SEND_EVENTOCCURRENCE);
	m_objectActivation_Operation_startBehavior_Class_ParameterValue = factory->createEOperation_as_eOperations_in_EClass(m_objectActivation_Class, OBJECTACTIVATION_OPERATION_STARTBEHAVIOR_CLASS_PARAMETERVALUE);
	m_objectActivation_Operation_stop = factory->createEOperation_as_eOperations_in_EClass(m_objectActivation_Class, OBJECTACTIVATION_OPERATION_STOP);
	m_objectActivation_Operation_unregister_EventAccepter = factory->createEOperation_as_eOperations_in_EClass(m_objectActivation_Class, OBJECTACTIVATION_OPERATION_UNREGISTER_EVENTACCEPTER);
	
}

void CommonBehaviorPackageImpl::createParameterValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_parameterValue_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PARAMETERVALUE_CLASS);
	m_parameterValue_Attribute_values = factory->createEAttribute_as_eAttributes_in_EClass(m_parameterValue_Class, PARAMETERVALUE_ATTRIBUTE_VALUES);
	
	m_parameterValue_Attribute_parameter = factory->createEReference_as_eReferences_in_EClass(m_parameterValue_Class, PARAMETERVALUE_ATTRIBUTE_PARAMETER);
	
	m_parameterValue_Operation__copy = factory->createEOperation_as_eOperations_in_EClass(m_parameterValue_Class, PARAMETERVALUE_OPERATION__COPY);
	
}

void CommonBehaviorPackageImpl::createSignalEventOccurrenceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_signalEventOccurrence_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, SIGNALEVENTOCCURRENCE_CLASS);
	
	m_signalEventOccurrence_Attribute_signalInstance = factory->createEReference_as_eReferences_in_EClass(m_signalEventOccurrence_Class, SIGNALEVENTOCCURRENCE_ATTRIBUTE_SIGNALINSTANCE);
	
	m_signalEventOccurrence_Operation_getParameterValues_Event = factory->createEOperation_as_eOperations_in_EClass(m_signalEventOccurrence_Class, SIGNALEVENTOCCURRENCE_OPERATION_GETPARAMETERVALUES_EVENT);
	m_signalEventOccurrence_Operation_match_Trigger = factory->createEOperation_as_eOperations_in_EClass(m_signalEventOccurrence_Class, SIGNALEVENTOCCURRENCE_OPERATION_MATCH_TRIGGER);
	
}

void CommonBehaviorPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	
}
