#include "fUML/Semantics/CommonBehavior/impl/CommonBehaviorPackageImpl.hpp"

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

#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"


using namespace fUML::Semantics::CommonBehavior;

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
	m_execution_Class->getESuperTypes()->push_back(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_Object_Class());
	m_execution_Class->getESuperTypes()->push_back(fUML::Semantics::Loci::LociPackage::eInstance()->getSemanticVisitor_Class());
	m_fIFOGetNextEventStrategy_Class->getESuperTypes()->push_back(getGetNextEventStrategy_Class());
	m_getNextEventStrategy_Class->getESuperTypes()->push_back(fUML::Semantics::Loci::LociPackage::eInstance()->getSemanticStrategy_Class());
	m_signalEventOccurrence_Class->getESuperTypes()->push_back(getEventOccurrence_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeClassifierBehaviorExecutionContent();
	initializeEventAccepterContent();
	initializeEventOccurrenceContent();
	initializeExecutionContent();
	initializeFIFOGetNextEventStrategyContent();
	initializeGetNextEventStrategyContent();
	initializeObjectActivationContent();
	initializeParameterValueContent();
	initializeSignalEventOccurrenceContent();

	initializePackageEDataTypes();

}

void CommonBehaviorPackageImpl::initializeClassifierBehaviorExecutionContent()
{
	m_classifierBehaviorExecution_Class->setName("ClassifierBehaviorExecution");
	m_classifierBehaviorExecution_Class->setAbstract(false);
	m_classifierBehaviorExecution_Class->setInterface(false);
	
	m_classifierBehaviorExecution_Class->_setID(CLASSIFIERBEHAVIOREXECUTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_classifierBehaviorExecution_Attribute_classifier->setName("classifier");
	m_classifierBehaviorExecution_Attribute_classifier->setEType(uml::umlPackage::eInstance()->getClass_Class());
	m_classifierBehaviorExecution_Attribute_classifier->setLowerBound(1);
	m_classifierBehaviorExecution_Attribute_classifier->setUpperBound(1);
	m_classifierBehaviorExecution_Attribute_classifier->setTransient(false);
	m_classifierBehaviorExecution_Attribute_classifier->setVolatile(false);
	m_classifierBehaviorExecution_Attribute_classifier->setChangeable(true);
	m_classifierBehaviorExecution_Attribute_classifier->setUnsettable(false);
	m_classifierBehaviorExecution_Attribute_classifier->setUnique(true);
	m_classifierBehaviorExecution_Attribute_classifier->setDerived(false);
	m_classifierBehaviorExecution_Attribute_classifier->setOrdered(false);
	m_classifierBehaviorExecution_Attribute_classifier->setContainment(false);
	m_classifierBehaviorExecution_Attribute_classifier->setResolveProxies(true);
	m_classifierBehaviorExecution_Attribute_classifier->setDefaultValueLiteral("");	
	
	m_classifierBehaviorExecution_Attribute_classifier->_setID(CLASSIFIERBEHAVIOREXECUTION_ATTRIBUTE_CLASSIFIER);
	m_classifierBehaviorExecution_Attribute_execution->setName("execution");
	m_classifierBehaviorExecution_Attribute_execution->setEType(getExecution_Class());
	m_classifierBehaviorExecution_Attribute_execution->setLowerBound(1);
	m_classifierBehaviorExecution_Attribute_execution->setUpperBound(1);
	m_classifierBehaviorExecution_Attribute_execution->setTransient(false);
	m_classifierBehaviorExecution_Attribute_execution->setVolatile(false);
	m_classifierBehaviorExecution_Attribute_execution->setChangeable(true);
	m_classifierBehaviorExecution_Attribute_execution->setUnsettable(false);
	m_classifierBehaviorExecution_Attribute_execution->setUnique(true);
	m_classifierBehaviorExecution_Attribute_execution->setDerived(false);
	m_classifierBehaviorExecution_Attribute_execution->setOrdered(false);
	m_classifierBehaviorExecution_Attribute_execution->setContainment(false);
	m_classifierBehaviorExecution_Attribute_execution->setResolveProxies(true);
	m_classifierBehaviorExecution_Attribute_execution->setDefaultValueLiteral("");	
	
	m_classifierBehaviorExecution_Attribute_execution->_setID(CLASSIFIERBEHAVIOREXECUTION_ATTRIBUTE_EXECUTION);
	m_classifierBehaviorExecution_Attribute_objectActivation->setName("objectActivation");
	m_classifierBehaviorExecution_Attribute_objectActivation->setEType(getObjectActivation_Class());
	m_classifierBehaviorExecution_Attribute_objectActivation->setLowerBound(0);
	m_classifierBehaviorExecution_Attribute_objectActivation->setUpperBound(1);
	m_classifierBehaviorExecution_Attribute_objectActivation->setTransient(false);
	m_classifierBehaviorExecution_Attribute_objectActivation->setVolatile(false);
	m_classifierBehaviorExecution_Attribute_objectActivation->setChangeable(true);
	m_classifierBehaviorExecution_Attribute_objectActivation->setUnsettable(false);
	m_classifierBehaviorExecution_Attribute_objectActivation->setUnique(true);
	m_classifierBehaviorExecution_Attribute_objectActivation->setDerived(false);
	m_classifierBehaviorExecution_Attribute_objectActivation->setOrdered(false);
	m_classifierBehaviorExecution_Attribute_objectActivation->setContainment(false);
	m_classifierBehaviorExecution_Attribute_objectActivation->setResolveProxies(true);
	m_classifierBehaviorExecution_Attribute_objectActivation->setDefaultValueLiteral("");	
	
	m_classifierBehaviorExecution_Attribute_objectActivation->_setID(CLASSIFIERBEHAVIOREXECUTION_ATTRIBUTE_OBJECTACTIVATION);
	
	/*
	 * EOperations
	 */
	m_classifierBehaviorExecution_Operation__startObjectBehavior->setName("_startObjectBehavior");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_classifierBehaviorExecution_Operation__startObjectBehavior->setEType(unknownClass);
	}
	m_classifierBehaviorExecution_Operation__startObjectBehavior->setLowerBound(1);
	m_classifierBehaviorExecution_Operation__startObjectBehavior->setUpperBound(1);
	m_classifierBehaviorExecution_Operation__startObjectBehavior->setUnique(true);
	m_classifierBehaviorExecution_Operation__startObjectBehavior->setOrdered(false);
	
	m_classifierBehaviorExecution_Operation__startObjectBehavior->_setID(CLASSIFIERBEHAVIOREXECUTION_OPERATION__STARTOBJECTBEHAVIOR);
	
	
	m_classifierBehaviorExecution_Operation_execute_Class_ParameterValue->setName("execute");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_classifierBehaviorExecution_Operation_execute_Class_ParameterValue->setEType(unknownClass);
	}
	m_classifierBehaviorExecution_Operation_execute_Class_ParameterValue->setLowerBound(1);
	m_classifierBehaviorExecution_Operation_execute_Class_ParameterValue->setUpperBound(1);
	m_classifierBehaviorExecution_Operation_execute_Class_ParameterValue->setUnique(true);
	m_classifierBehaviorExecution_Operation_execute_Class_ParameterValue->setOrdered(false);
	
	m_classifierBehaviorExecution_Operation_execute_Class_ParameterValue->_setID(CLASSIFIERBEHAVIOREXECUTION_OPERATION_EXECUTE_CLASS_PARAMETERVALUE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_classifierBehaviorExecution_Operation_execute_Class_ParameterValue);
		parameter->setName("classifier");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_classifierBehaviorExecution_Operation_execute_Class_ParameterValue);
		parameter->setName("inputs");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_classifierBehaviorExecution_Operation_terminate->setName("terminate");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_classifierBehaviorExecution_Operation_terminate->setEType(unknownClass);
	}
	m_classifierBehaviorExecution_Operation_terminate->setLowerBound(1);
	m_classifierBehaviorExecution_Operation_terminate->setUpperBound(1);
	m_classifierBehaviorExecution_Operation_terminate->setUnique(true);
	m_classifierBehaviorExecution_Operation_terminate->setOrdered(false);
	
	m_classifierBehaviorExecution_Operation_terminate->_setID(CLASSIFIERBEHAVIOREXECUTION_OPERATION_TERMINATE);
	
	
	
}

void CommonBehaviorPackageImpl::initializeEventAccepterContent()
{
	m_eventAccepter_Class->setName("EventAccepter");
	m_eventAccepter_Class->setAbstract(true);
	m_eventAccepter_Class->setInterface(false);
	
	m_eventAccepter_Class->_setID(EVENTACCEPTER_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_eventAccepter_Operation_accept_EventOccurrence->setName("accept");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_eventAccepter_Operation_accept_EventOccurrence->setEType(unknownClass);
	}
	m_eventAccepter_Operation_accept_EventOccurrence->setLowerBound(1);
	m_eventAccepter_Operation_accept_EventOccurrence->setUpperBound(1);
	m_eventAccepter_Operation_accept_EventOccurrence->setUnique(true);
	m_eventAccepter_Operation_accept_EventOccurrence->setOrdered(false);
	
	m_eventAccepter_Operation_accept_EventOccurrence->_setID(EVENTACCEPTER_OPERATION_ACCEPT_EVENTOCCURRENCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_eventAccepter_Operation_accept_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eventAccepter_Operation_match_EventOccurrence->setName("match");
	m_eventAccepter_Operation_match_EventOccurrence->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_eventAccepter_Operation_match_EventOccurrence->setLowerBound(1);
	m_eventAccepter_Operation_match_EventOccurrence->setUpperBound(1);
	m_eventAccepter_Operation_match_EventOccurrence->setUnique(true);
	m_eventAccepter_Operation_match_EventOccurrence->setOrdered(false);
	
	m_eventAccepter_Operation_match_EventOccurrence->_setID(EVENTACCEPTER_OPERATION_MATCH_EVENTOCCURRENCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_eventAccepter_Operation_match_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(getEventOccurrence_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void CommonBehaviorPackageImpl::initializeEventOccurrenceContent()
{
	m_eventOccurrence_Class->setName("EventOccurrence");
	m_eventOccurrence_Class->setAbstract(false);
	m_eventOccurrence_Class->setInterface(false);
	
	m_eventOccurrence_Class->_setID(EVENTOCCURRENCE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_eventOccurrence_Attribute_target->setName("target");
	m_eventOccurrence_Attribute_target->setEType(uml::umlPackage::eInstance()->getElement_Class());
	m_eventOccurrence_Attribute_target->setLowerBound(0);
	m_eventOccurrence_Attribute_target->setUpperBound(1);
	m_eventOccurrence_Attribute_target->setTransient(false);
	m_eventOccurrence_Attribute_target->setVolatile(false);
	m_eventOccurrence_Attribute_target->setChangeable(true);
	m_eventOccurrence_Attribute_target->setUnsettable(false);
	m_eventOccurrence_Attribute_target->setUnique(true);
	m_eventOccurrence_Attribute_target->setDerived(false);
	m_eventOccurrence_Attribute_target->setOrdered(true);
	m_eventOccurrence_Attribute_target->setContainment(false);
	m_eventOccurrence_Attribute_target->setResolveProxies(true);
	m_eventOccurrence_Attribute_target->setDefaultValueLiteral("");	
	
	m_eventOccurrence_Attribute_target->_setID(EVENTOCCURRENCE_ATTRIBUTE_TARGET);
	
	/*
	 * EOperations
	 */
	m_eventOccurrence_Operation_doSend->setName("doSend");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_eventOccurrence_Operation_doSend->setEType(unknownClass);
	}
	m_eventOccurrence_Operation_doSend->setLowerBound(1);
	m_eventOccurrence_Operation_doSend->setUpperBound(1);
	m_eventOccurrence_Operation_doSend->setUnique(true);
	m_eventOccurrence_Operation_doSend->setOrdered(true);
	
	m_eventOccurrence_Operation_doSend->_setID(EVENTOCCURRENCE_OPERATION_DOSEND);
	
	
	m_eventOccurrence_Operation_getParameterValues_Event->setName("getParameterValues");
	m_eventOccurrence_Operation_getParameterValues_Event->setEType(getParameterValue_Class());
	m_eventOccurrence_Operation_getParameterValues_Event->setLowerBound(0);
	m_eventOccurrence_Operation_getParameterValues_Event->setUpperBound(-1);
	m_eventOccurrence_Operation_getParameterValues_Event->setUnique(true);
	m_eventOccurrence_Operation_getParameterValues_Event->setOrdered(true);
	
	m_eventOccurrence_Operation_getParameterValues_Event->_setID(EVENTOCCURRENCE_OPERATION_GETPARAMETERVALUES_EVENT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_eventOccurrence_Operation_getParameterValues_Event);
		parameter->setName("event");
		parameter->setEType(uml::umlPackage::eInstance()->getEvent_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eventOccurrence_Operation_match_Trigger->setName("match");
	m_eventOccurrence_Operation_match_Trigger->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_eventOccurrence_Operation_match_Trigger->setLowerBound(1);
	m_eventOccurrence_Operation_match_Trigger->setUpperBound(1);
	m_eventOccurrence_Operation_match_Trigger->setUnique(true);
	m_eventOccurrence_Operation_match_Trigger->setOrdered(true);
	
	m_eventOccurrence_Operation_match_Trigger->_setID(EVENTOCCURRENCE_OPERATION_MATCH_TRIGGER);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_eventOccurrence_Operation_match_Trigger);
		parameter->setName("trigger");
		parameter->setEType(uml::umlPackage::eInstance()->getTrigger_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eventOccurrence_Operation_matchAny_Trigger->setName("matchAny");
	m_eventOccurrence_Operation_matchAny_Trigger->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_eventOccurrence_Operation_matchAny_Trigger->setLowerBound(1);
	m_eventOccurrence_Operation_matchAny_Trigger->setUpperBound(1);
	m_eventOccurrence_Operation_matchAny_Trigger->setUnique(true);
	m_eventOccurrence_Operation_matchAny_Trigger->setOrdered(true);
	
	m_eventOccurrence_Operation_matchAny_Trigger->_setID(EVENTOCCURRENCE_OPERATION_MATCHANY_TRIGGER);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_eventOccurrence_Operation_matchAny_Trigger);
		parameter->setName("triggers");
		parameter->setEType(uml::umlPackage::eInstance()->getTrigger_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eventOccurrence_Operation_sendTo_Element->setName("sendTo");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_eventOccurrence_Operation_sendTo_Element->setEType(unknownClass);
	}
	m_eventOccurrence_Operation_sendTo_Element->setLowerBound(1);
	m_eventOccurrence_Operation_sendTo_Element->setUpperBound(1);
	m_eventOccurrence_Operation_sendTo_Element->setUnique(true);
	m_eventOccurrence_Operation_sendTo_Element->setOrdered(true);
	
	m_eventOccurrence_Operation_sendTo_Element->_setID(EVENTOCCURRENCE_OPERATION_SENDTO_ELEMENT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_eventOccurrence_Operation_sendTo_Element);
		parameter->setName("target");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void CommonBehaviorPackageImpl::initializeExecutionContent()
{
	m_execution_Class->setName("Execution");
	m_execution_Class->setAbstract(true);
	m_execution_Class->setInterface(false);
	
	m_execution_Class->_setID(EXECUTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_execution_Attribute_behavior->setName("behavior");
	m_execution_Attribute_behavior->setEType(uml::umlPackage::eInstance()->getBehavior_Class());
	m_execution_Attribute_behavior->setLowerBound(1);
	m_execution_Attribute_behavior->setUpperBound(1);
	m_execution_Attribute_behavior->setTransient(false);
	m_execution_Attribute_behavior->setVolatile(false);
	m_execution_Attribute_behavior->setChangeable(true);
	m_execution_Attribute_behavior->setUnsettable(false);
	m_execution_Attribute_behavior->setUnique(true);
	m_execution_Attribute_behavior->setDerived(false);
	m_execution_Attribute_behavior->setOrdered(true);
	m_execution_Attribute_behavior->setContainment(false);
	m_execution_Attribute_behavior->setResolveProxies(true);
	m_execution_Attribute_behavior->setDefaultValueLiteral("");	
	
	m_execution_Attribute_behavior->_setID(EXECUTION_ATTRIBUTE_BEHAVIOR);
	m_execution_Attribute_context->setName("context");
	m_execution_Attribute_context->setEType(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_Object_Class());
	m_execution_Attribute_context->setLowerBound(1);
	m_execution_Attribute_context->setUpperBound(1);
	m_execution_Attribute_context->setTransient(false);
	m_execution_Attribute_context->setVolatile(false);
	m_execution_Attribute_context->setChangeable(true);
	m_execution_Attribute_context->setUnsettable(false);
	m_execution_Attribute_context->setUnique(true);
	m_execution_Attribute_context->setDerived(false);
	m_execution_Attribute_context->setOrdered(false);
	m_execution_Attribute_context->setContainment(false);
	m_execution_Attribute_context->setResolveProxies(true);
	m_execution_Attribute_context->setDefaultValueLiteral("");	
	
	m_execution_Attribute_context->_setID(EXECUTION_ATTRIBUTE_CONTEXT);
	m_execution_Attribute_locus->setName("locus");
	m_execution_Attribute_locus->setEType(fUML::Semantics::Loci::LociPackage::eInstance()->getLocus_Class());
	m_execution_Attribute_locus->setLowerBound(0);
	m_execution_Attribute_locus->setUpperBound(1);
	m_execution_Attribute_locus->setTransient(false);
	m_execution_Attribute_locus->setVolatile(false);
	m_execution_Attribute_locus->setChangeable(true);
	m_execution_Attribute_locus->setUnsettable(false);
	m_execution_Attribute_locus->setUnique(true);
	m_execution_Attribute_locus->setDerived(false);
	m_execution_Attribute_locus->setOrdered(false);
	m_execution_Attribute_locus->setContainment(false);
	m_execution_Attribute_locus->setResolveProxies(true);
	m_execution_Attribute_locus->setDefaultValueLiteral("");	
	
	m_execution_Attribute_locus->_setID(EXECUTION_ATTRIBUTE_LOCUS);
	m_execution_Attribute_parameterValues->setName("parameterValues");
	m_execution_Attribute_parameterValues->setEType(getParameterValue_Class());
	m_execution_Attribute_parameterValues->setLowerBound(0);
	m_execution_Attribute_parameterValues->setUpperBound(-1);
	m_execution_Attribute_parameterValues->setTransient(false);
	m_execution_Attribute_parameterValues->setVolatile(false);
	m_execution_Attribute_parameterValues->setChangeable(true);
	m_execution_Attribute_parameterValues->setUnsettable(false);
	m_execution_Attribute_parameterValues->setUnique(true);
	m_execution_Attribute_parameterValues->setDerived(false);
	m_execution_Attribute_parameterValues->setOrdered(false);
	m_execution_Attribute_parameterValues->setContainment(true);
	m_execution_Attribute_parameterValues->setResolveProxies(true);
	m_execution_Attribute_parameterValues->setDefaultValueLiteral("");	
	
	m_execution_Attribute_parameterValues->_setID(EXECUTION_ATTRIBUTE_PARAMETERVALUES);
	m_execution_Attribute_types->setName("types");
	m_execution_Attribute_types->setEType(uml::umlPackage::eInstance()->getClassifier_Class());
	m_execution_Attribute_types->setLowerBound(0);
	m_execution_Attribute_types->setUpperBound(-1);
	m_execution_Attribute_types->setTransient(false);
	m_execution_Attribute_types->setVolatile(false);
	m_execution_Attribute_types->setChangeable(true);
	m_execution_Attribute_types->setUnsettable(false);
	m_execution_Attribute_types->setUnique(true);
	m_execution_Attribute_types->setDerived(false);
	m_execution_Attribute_types->setOrdered(false);
	m_execution_Attribute_types->setContainment(false);
	m_execution_Attribute_types->setResolveProxies(true);
	m_execution_Attribute_types->setDefaultValueLiteral("");	
	
	m_execution_Attribute_types->_setID(EXECUTION_ATTRIBUTE_TYPES);
	
	/*
	 * EOperations
	 */
	m_execution_Operation__copy->setName("_copy");
	m_execution_Operation__copy->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_execution_Operation__copy->setLowerBound(1);
	m_execution_Operation__copy->setUpperBound(1);
	m_execution_Operation__copy->setUnique(true);
	m_execution_Operation__copy->setOrdered(true);
	
	m_execution_Operation__copy->_setID(EXECUTION_OPERATION__COPY);
	
	
	m_execution_Operation_destroy->setName("destroy");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_execution_Operation_destroy->setEType(unknownClass);
	}
	m_execution_Operation_destroy->setLowerBound(1);
	m_execution_Operation_destroy->setUpperBound(1);
	m_execution_Operation_destroy->setUnique(true);
	m_execution_Operation_destroy->setOrdered(false);
	
	m_execution_Operation_destroy->_setID(EXECUTION_OPERATION_DESTROY);
	
	
	m_execution_Operation_execute->setName("execute");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_execution_Operation_execute->setEType(unknownClass);
	}
	m_execution_Operation_execute->setLowerBound(1);
	m_execution_Operation_execute->setUpperBound(1);
	m_execution_Operation_execute->setUnique(true);
	m_execution_Operation_execute->setOrdered(false);
	
	m_execution_Operation_execute->_setID(EXECUTION_OPERATION_EXECUTE);
	
	
	m_execution_Operation_getOutputParameterValues->setName("getOutputParameterValues");
	m_execution_Operation_getOutputParameterValues->setEType(getParameterValue_Class());
	m_execution_Operation_getOutputParameterValues->setLowerBound(0);
	m_execution_Operation_getOutputParameterValues->setUpperBound(-1);
	m_execution_Operation_getOutputParameterValues->setUnique(true);
	m_execution_Operation_getOutputParameterValues->setOrdered(false);
	
	m_execution_Operation_getOutputParameterValues->_setID(EXECUTION_OPERATION_GETOUTPUTPARAMETERVALUES);
	
	
	m_execution_Operation_getParameterValue_Parameter->setName("getParameterValue");
	m_execution_Operation_getParameterValue_Parameter->setEType(getParameterValue_Class());
	m_execution_Operation_getParameterValue_Parameter->setLowerBound(1);
	m_execution_Operation_getParameterValue_Parameter->setUpperBound(1);
	m_execution_Operation_getParameterValue_Parameter->setUnique(true);
	m_execution_Operation_getParameterValue_Parameter->setOrdered(false);
	
	m_execution_Operation_getParameterValue_Parameter->_setID(EXECUTION_OPERATION_GETPARAMETERVALUE_PARAMETER);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_execution_Operation_getParameterValue_Parameter);
		parameter->setName("parameter");
		parameter->setEType(uml::umlPackage::eInstance()->getParameter_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_execution_Operation_new_->setName("new_");
	m_execution_Operation_new_->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_execution_Operation_new_->setLowerBound(1);
	m_execution_Operation_new_->setUpperBound(1);
	m_execution_Operation_new_->setUnique(true);
	m_execution_Operation_new_->setOrdered(false);
	
	m_execution_Operation_new_->_setID(EXECUTION_OPERATION_NEW_);
	
	
	m_execution_Operation_setParameterValue_ParameterValue->setName("setParameterValue");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_execution_Operation_setParameterValue_ParameterValue->setEType(unknownClass);
	}
	m_execution_Operation_setParameterValue_ParameterValue->setLowerBound(1);
	m_execution_Operation_setParameterValue_ParameterValue->setUpperBound(1);
	m_execution_Operation_setParameterValue_ParameterValue->setUnique(true);
	m_execution_Operation_setParameterValue_ParameterValue->setOrdered(false);
	
	m_execution_Operation_setParameterValue_ParameterValue->_setID(EXECUTION_OPERATION_SETPARAMETERVALUE_PARAMETERVALUE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_execution_Operation_setParameterValue_ParameterValue);
		parameter->setName("parameterValue");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_execution_Operation_terminate->setName("terminate");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_execution_Operation_terminate->setEType(unknownClass);
	}
	m_execution_Operation_terminate->setLowerBound(1);
	m_execution_Operation_terminate->setUpperBound(1);
	m_execution_Operation_terminate->setUnique(true);
	m_execution_Operation_terminate->setOrdered(false);
	
	m_execution_Operation_terminate->_setID(EXECUTION_OPERATION_TERMINATE);
	
	
	
}

void CommonBehaviorPackageImpl::initializeFIFOGetNextEventStrategyContent()
{
	m_fIFOGetNextEventStrategy_Class->setName("FIFOGetNextEventStrategy");
	m_fIFOGetNextEventStrategy_Class->setAbstract(false);
	m_fIFOGetNextEventStrategy_Class->setInterface(false);
	
	m_fIFOGetNextEventStrategy_Class->_setID(FIFOGETNEXTEVENTSTRATEGY_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_fIFOGetNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation->setName("retrieveNextEvent");
	m_fIFOGetNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation->setEType(getEventOccurrence_Class());
	m_fIFOGetNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation->setLowerBound(1);
	m_fIFOGetNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation->setUpperBound(1);
	m_fIFOGetNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation->setUnique(true);
	m_fIFOGetNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation->setOrdered(false);
	
	m_fIFOGetNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation->_setID(FIFOGETNEXTEVENTSTRATEGY_OPERATION_RETRIEVENEXTEVENT_OBJECTACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_fIFOGetNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation);
		parameter->setName("objectActivation");
		parameter->setEType(getObjectActivation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void CommonBehaviorPackageImpl::initializeGetNextEventStrategyContent()
{
	m_getNextEventStrategy_Class->setName("GetNextEventStrategy");
	m_getNextEventStrategy_Class->setAbstract(true);
	m_getNextEventStrategy_Class->setInterface(false);
	
	m_getNextEventStrategy_Class->_setID(GETNEXTEVENTSTRATEGY_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_getNextEventStrategy_Operation_getName->setName("getName");
	m_getNextEventStrategy_Operation_getName->setEType(types::typesPackage::eInstance()->getString_Class());
	m_getNextEventStrategy_Operation_getName->setLowerBound(0);
	m_getNextEventStrategy_Operation_getName->setUpperBound(1);
	m_getNextEventStrategy_Operation_getName->setUnique(true);
	m_getNextEventStrategy_Operation_getName->setOrdered(true);
	
	m_getNextEventStrategy_Operation_getName->_setID(GETNEXTEVENTSTRATEGY_OPERATION_GETNAME);
	
	
	m_getNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation->setName("retrieveNextEvent");
	m_getNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation->setEType(getEventOccurrence_Class());
	m_getNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation->setLowerBound(1);
	m_getNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation->setUpperBound(1);
	m_getNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation->setUnique(true);
	m_getNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation->setOrdered(false);
	
	m_getNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation->_setID(GETNEXTEVENTSTRATEGY_OPERATION_RETRIEVENEXTEVENT_OBJECTACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_getNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation);
		parameter->setName("objectActivation");
		parameter->setEType(getObjectActivation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void CommonBehaviorPackageImpl::initializeObjectActivationContent()
{
	m_objectActivation_Class->setName("ObjectActivation");
	m_objectActivation_Class->setAbstract(false);
	m_objectActivation_Class->setInterface(false);
	
	m_objectActivation_Class->_setID(OBJECTACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_objectActivation_Attribute_classifierBehaviorExecutions->setName("classifierBehaviorExecutions");
	m_objectActivation_Attribute_classifierBehaviorExecutions->setEType(getClassifierBehaviorExecution_Class());
	m_objectActivation_Attribute_classifierBehaviorExecutions->setLowerBound(0);
	m_objectActivation_Attribute_classifierBehaviorExecutions->setUpperBound(-1);
	m_objectActivation_Attribute_classifierBehaviorExecutions->setTransient(false);
	m_objectActivation_Attribute_classifierBehaviorExecutions->setVolatile(false);
	m_objectActivation_Attribute_classifierBehaviorExecutions->setChangeable(true);
	m_objectActivation_Attribute_classifierBehaviorExecutions->setUnsettable(false);
	m_objectActivation_Attribute_classifierBehaviorExecutions->setUnique(true);
	m_objectActivation_Attribute_classifierBehaviorExecutions->setDerived(false);
	m_objectActivation_Attribute_classifierBehaviorExecutions->setOrdered(false);
	m_objectActivation_Attribute_classifierBehaviorExecutions->setContainment(true);
	m_objectActivation_Attribute_classifierBehaviorExecutions->setResolveProxies(true);
	m_objectActivation_Attribute_classifierBehaviorExecutions->setDefaultValueLiteral("");	
	
	m_objectActivation_Attribute_classifierBehaviorExecutions->_setID(OBJECTACTIVATION_ATTRIBUTE_CLASSIFIERBEHAVIOREXECUTIONS);
	m_objectActivation_Attribute_conditionVariable->setName("conditionVariable");
	{
		std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_objectActivation_Attribute_conditionVariable->setEType(unknownClass);
	}
	m_objectActivation_Attribute_conditionVariable->setLowerBound(1);
	m_objectActivation_Attribute_conditionVariable->setUpperBound(1);
	m_objectActivation_Attribute_conditionVariable->setTransient(false);
	m_objectActivation_Attribute_conditionVariable->setVolatile(false);
	m_objectActivation_Attribute_conditionVariable->setChangeable(true);
	m_objectActivation_Attribute_conditionVariable->setUnsettable(false);
	m_objectActivation_Attribute_conditionVariable->setUnique(true);
	m_objectActivation_Attribute_conditionVariable->setDerived(false);
	m_objectActivation_Attribute_conditionVariable->setOrdered(true);
	m_objectActivation_Attribute_conditionVariable->setContainment(false);
	m_objectActivation_Attribute_conditionVariable->setResolveProxies(true);
	m_objectActivation_Attribute_conditionVariable->setDefaultValueLiteral("");	
	
	m_objectActivation_Attribute_conditionVariable->_setID(OBJECTACTIVATION_ATTRIBUTE_CONDITIONVARIABLE);
	m_objectActivation_Attribute_eventPool->setName("eventPool");
	m_objectActivation_Attribute_eventPool->setEType(getEventOccurrence_Class());
	m_objectActivation_Attribute_eventPool->setLowerBound(0);
	m_objectActivation_Attribute_eventPool->setUpperBound(-1);
	m_objectActivation_Attribute_eventPool->setTransient(false);
	m_objectActivation_Attribute_eventPool->setVolatile(false);
	m_objectActivation_Attribute_eventPool->setChangeable(true);
	m_objectActivation_Attribute_eventPool->setUnsettable(false);
	m_objectActivation_Attribute_eventPool->setUnique(true);
	m_objectActivation_Attribute_eventPool->setDerived(false);
	m_objectActivation_Attribute_eventPool->setOrdered(false);
	m_objectActivation_Attribute_eventPool->setContainment(true);
	m_objectActivation_Attribute_eventPool->setResolveProxies(true);
	m_objectActivation_Attribute_eventPool->setDefaultValueLiteral("");	
	
	m_objectActivation_Attribute_eventPool->_setID(OBJECTACTIVATION_ATTRIBUTE_EVENTPOOL);
	m_objectActivation_Attribute_memberThread->setName("memberThread");
	{
		std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_objectActivation_Attribute_memberThread->setEType(unknownClass);
	}
	m_objectActivation_Attribute_memberThread->setLowerBound(1);
	m_objectActivation_Attribute_memberThread->setUpperBound(1);
	m_objectActivation_Attribute_memberThread->setTransient(false);
	m_objectActivation_Attribute_memberThread->setVolatile(false);
	m_objectActivation_Attribute_memberThread->setChangeable(true);
	m_objectActivation_Attribute_memberThread->setUnsettable(false);
	m_objectActivation_Attribute_memberThread->setUnique(true);
	m_objectActivation_Attribute_memberThread->setDerived(false);
	m_objectActivation_Attribute_memberThread->setOrdered(true);
	m_objectActivation_Attribute_memberThread->setContainment(false);
	m_objectActivation_Attribute_memberThread->setResolveProxies(true);
	m_objectActivation_Attribute_memberThread->setDefaultValueLiteral("");	
	
	m_objectActivation_Attribute_memberThread->_setID(OBJECTACTIVATION_ATTRIBUTE_MEMBERTHREAD);
	m_objectActivation_Attribute_mutex->setName("mutex");
	{
		std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_objectActivation_Attribute_mutex->setEType(unknownClass);
	}
	m_objectActivation_Attribute_mutex->setLowerBound(1);
	m_objectActivation_Attribute_mutex->setUpperBound(1);
	m_objectActivation_Attribute_mutex->setTransient(false);
	m_objectActivation_Attribute_mutex->setVolatile(false);
	m_objectActivation_Attribute_mutex->setChangeable(true);
	m_objectActivation_Attribute_mutex->setUnsettable(false);
	m_objectActivation_Attribute_mutex->setUnique(true);
	m_objectActivation_Attribute_mutex->setDerived(false);
	m_objectActivation_Attribute_mutex->setOrdered(true);
	m_objectActivation_Attribute_mutex->setContainment(false);
	m_objectActivation_Attribute_mutex->setResolveProxies(true);
	m_objectActivation_Attribute_mutex->setDefaultValueLiteral("");	
	
	m_objectActivation_Attribute_mutex->_setID(OBJECTACTIVATION_ATTRIBUTE_MUTEX);
	m_objectActivation_Attribute_object->setName("object");
	m_objectActivation_Attribute_object->setEType(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_Object_Class());
	m_objectActivation_Attribute_object->setLowerBound(1);
	m_objectActivation_Attribute_object->setUpperBound(1);
	m_objectActivation_Attribute_object->setTransient(false);
	m_objectActivation_Attribute_object->setVolatile(false);
	m_objectActivation_Attribute_object->setChangeable(true);
	m_objectActivation_Attribute_object->setUnsettable(false);
	m_objectActivation_Attribute_object->setUnique(true);
	m_objectActivation_Attribute_object->setDerived(false);
	m_objectActivation_Attribute_object->setOrdered(false);
	m_objectActivation_Attribute_object->setContainment(false);
	m_objectActivation_Attribute_object->setResolveProxies(true);
	m_objectActivation_Attribute_object->setDefaultValueLiteral("");	
	
	m_objectActivation_Attribute_object->_setID(OBJECTACTIVATION_ATTRIBUTE_OBJECT);
	m_objectActivation_Attribute_waitingEventAccepters->setName("waitingEventAccepters");
	m_objectActivation_Attribute_waitingEventAccepters->setEType(getEventAccepter_Class());
	m_objectActivation_Attribute_waitingEventAccepters->setLowerBound(0);
	m_objectActivation_Attribute_waitingEventAccepters->setUpperBound(-1);
	m_objectActivation_Attribute_waitingEventAccepters->setTransient(false);
	m_objectActivation_Attribute_waitingEventAccepters->setVolatile(false);
	m_objectActivation_Attribute_waitingEventAccepters->setChangeable(true);
	m_objectActivation_Attribute_waitingEventAccepters->setUnsettable(false);
	m_objectActivation_Attribute_waitingEventAccepters->setUnique(true);
	m_objectActivation_Attribute_waitingEventAccepters->setDerived(false);
	m_objectActivation_Attribute_waitingEventAccepters->setOrdered(false);
	m_objectActivation_Attribute_waitingEventAccepters->setContainment(false);
	m_objectActivation_Attribute_waitingEventAccepters->setResolveProxies(true);
	m_objectActivation_Attribute_waitingEventAccepters->setDefaultValueLiteral("");	
	
	m_objectActivation_Attribute_waitingEventAccepters->_setID(OBJECTACTIVATION_ATTRIBUTE_WAITINGEVENTACCEPTERS);
	
	/*
	 * EOperations
	 */
	m_objectActivation_Operation__register_EventAccepter->setName("_register");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_objectActivation_Operation__register_EventAccepter->setEType(unknownClass);
	}
	m_objectActivation_Operation__register_EventAccepter->setLowerBound(1);
	m_objectActivation_Operation__register_EventAccepter->setUpperBound(1);
	m_objectActivation_Operation__register_EventAccepter->setUnique(true);
	m_objectActivation_Operation__register_EventAccepter->setOrdered(false);
	
	m_objectActivation_Operation__register_EventAccepter->_setID(OBJECTACTIVATION_OPERATION__REGISTER_EVENTACCEPTER);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_objectActivation_Operation__register_EventAccepter);
		parameter->setName("accepter");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_objectActivation_Operation__startObjectBehavior->setName("_startObjectBehavior");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_objectActivation_Operation__startObjectBehavior->setEType(unknownClass);
	}
	m_objectActivation_Operation__startObjectBehavior->setLowerBound(1);
	m_objectActivation_Operation__startObjectBehavior->setUpperBound(1);
	m_objectActivation_Operation__startObjectBehavior->setUnique(true);
	m_objectActivation_Operation__startObjectBehavior->setOrdered(false);
	
	m_objectActivation_Operation__startObjectBehavior->_setID(OBJECTACTIVATION_OPERATION__STARTOBJECTBEHAVIOR);
	
	
	m_objectActivation_Operation_dispatchNextEvent->setName("dispatchNextEvent");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_objectActivation_Operation_dispatchNextEvent->setEType(unknownClass);
	}
	m_objectActivation_Operation_dispatchNextEvent->setLowerBound(1);
	m_objectActivation_Operation_dispatchNextEvent->setUpperBound(1);
	m_objectActivation_Operation_dispatchNextEvent->setUnique(true);
	m_objectActivation_Operation_dispatchNextEvent->setOrdered(false);
	
	m_objectActivation_Operation_dispatchNextEvent->_setID(OBJECTACTIVATION_OPERATION_DISPATCHNEXTEVENT);
	
	
	m_objectActivation_Operation_retrieveNextEvent->setName("retrieveNextEvent");
	m_objectActivation_Operation_retrieveNextEvent->setEType(getEventOccurrence_Class());
	m_objectActivation_Operation_retrieveNextEvent->setLowerBound(1);
	m_objectActivation_Operation_retrieveNextEvent->setUpperBound(1);
	m_objectActivation_Operation_retrieveNextEvent->setUnique(true);
	m_objectActivation_Operation_retrieveNextEvent->setOrdered(false);
	
	m_objectActivation_Operation_retrieveNextEvent->_setID(OBJECTACTIVATION_OPERATION_RETRIEVENEXTEVENT);
	
	
	m_objectActivation_Operation_send_EventOccurrence->setName("send");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_objectActivation_Operation_send_EventOccurrence->setEType(unknownClass);
	}
	m_objectActivation_Operation_send_EventOccurrence->setLowerBound(1);
	m_objectActivation_Operation_send_EventOccurrence->setUpperBound(1);
	m_objectActivation_Operation_send_EventOccurrence->setUnique(true);
	m_objectActivation_Operation_send_EventOccurrence->setOrdered(true);
	
	m_objectActivation_Operation_send_EventOccurrence->_setID(OBJECTACTIVATION_OPERATION_SEND_EVENTOCCURRENCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_objectActivation_Operation_send_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_objectActivation_Operation_startBehavior_Class_ParameterValue->setName("startBehavior");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_objectActivation_Operation_startBehavior_Class_ParameterValue->setEType(unknownClass);
	}
	m_objectActivation_Operation_startBehavior_Class_ParameterValue->setLowerBound(1);
	m_objectActivation_Operation_startBehavior_Class_ParameterValue->setUpperBound(1);
	m_objectActivation_Operation_startBehavior_Class_ParameterValue->setUnique(true);
	m_objectActivation_Operation_startBehavior_Class_ParameterValue->setOrdered(false);
	
	m_objectActivation_Operation_startBehavior_Class_ParameterValue->_setID(OBJECTACTIVATION_OPERATION_STARTBEHAVIOR_CLASS_PARAMETERVALUE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_objectActivation_Operation_startBehavior_Class_ParameterValue);
		parameter->setName("classifier");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_objectActivation_Operation_startBehavior_Class_ParameterValue);
		parameter->setName("inputs");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_objectActivation_Operation_stop->setName("stop");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_objectActivation_Operation_stop->setEType(unknownClass);
	}
	m_objectActivation_Operation_stop->setLowerBound(1);
	m_objectActivation_Operation_stop->setUpperBound(1);
	m_objectActivation_Operation_stop->setUnique(true);
	m_objectActivation_Operation_stop->setOrdered(false);
	
	m_objectActivation_Operation_stop->_setID(OBJECTACTIVATION_OPERATION_STOP);
	
	
	m_objectActivation_Operation_unregister_EventAccepter->setName("unregister");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_objectActivation_Operation_unregister_EventAccepter->setEType(unknownClass);
	}
	m_objectActivation_Operation_unregister_EventAccepter->setLowerBound(1);
	m_objectActivation_Operation_unregister_EventAccepter->setUpperBound(1);
	m_objectActivation_Operation_unregister_EventAccepter->setUnique(true);
	m_objectActivation_Operation_unregister_EventAccepter->setOrdered(false);
	
	m_objectActivation_Operation_unregister_EventAccepter->_setID(OBJECTACTIVATION_OPERATION_UNREGISTER_EVENTACCEPTER);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_objectActivation_Operation_unregister_EventAccepter);
		parameter->setName("accepter");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void CommonBehaviorPackageImpl::initializeParameterValueContent()
{
	m_parameterValue_Class->setName("ParameterValue");
	m_parameterValue_Class->setAbstract(false);
	m_parameterValue_Class->setInterface(false);
	
	m_parameterValue_Class->_setID(PARAMETERVALUE_CLASS);
	
	/*
	 * EAttributes
	 */
	m_parameterValue_Attribute_values = getParameterValue_Attribute_values();
	m_parameterValue_Attribute_values->setName("values");
	m_parameterValue_Attribute_values->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_parameterValue_Attribute_values->setLowerBound(0);
	m_parameterValue_Attribute_values->setUpperBound(-1);
	m_parameterValue_Attribute_values->setTransient(false);
	m_parameterValue_Attribute_values->setVolatile(false);
	m_parameterValue_Attribute_values->setChangeable(true);
	m_parameterValue_Attribute_values->setUnsettable(false);
	m_parameterValue_Attribute_values->setUnique(true);
	m_parameterValue_Attribute_values->setDerived(false);
	m_parameterValue_Attribute_values->setOrdered(true);
	m_parameterValue_Attribute_values->setID(false);
	m_parameterValue_Attribute_values->setDefaultValueLiteral("");
	
	m_parameterValue_Attribute_values->_setID(PARAMETERVALUE_ATTRIBUTE_VALUES);
	
	/*
	 * EReferences
	 */
	m_parameterValue_Attribute_parameter->setName("parameter");
	m_parameterValue_Attribute_parameter->setEType(uml::umlPackage::eInstance()->getParameter_Class());
	m_parameterValue_Attribute_parameter->setLowerBound(1);
	m_parameterValue_Attribute_parameter->setUpperBound(1);
	m_parameterValue_Attribute_parameter->setTransient(false);
	m_parameterValue_Attribute_parameter->setVolatile(false);
	m_parameterValue_Attribute_parameter->setChangeable(true);
	m_parameterValue_Attribute_parameter->setUnsettable(false);
	m_parameterValue_Attribute_parameter->setUnique(true);
	m_parameterValue_Attribute_parameter->setDerived(false);
	m_parameterValue_Attribute_parameter->setOrdered(false);
	m_parameterValue_Attribute_parameter->setContainment(false);
	m_parameterValue_Attribute_parameter->setResolveProxies(true);
	m_parameterValue_Attribute_parameter->setDefaultValueLiteral("");	
	
	m_parameterValue_Attribute_parameter->_setID(PARAMETERVALUE_ATTRIBUTE_PARAMETER);
	
	/*
	 * EOperations
	 */
	m_parameterValue_Operation__copy->setName("_copy");
	m_parameterValue_Operation__copy->setEType(getParameterValue_Class());
	m_parameterValue_Operation__copy->setLowerBound(1);
	m_parameterValue_Operation__copy->setUpperBound(1);
	m_parameterValue_Operation__copy->setUnique(true);
	m_parameterValue_Operation__copy->setOrdered(true);
	
	m_parameterValue_Operation__copy->_setID(PARAMETERVALUE_OPERATION__COPY);
	
	
	
}

void CommonBehaviorPackageImpl::initializeSignalEventOccurrenceContent()
{
	m_signalEventOccurrence_Class->setName("SignalEventOccurrence");
	m_signalEventOccurrence_Class->setAbstract(false);
	m_signalEventOccurrence_Class->setInterface(false);
	
	m_signalEventOccurrence_Class->_setID(SIGNALEVENTOCCURRENCE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_signalEventOccurrence_Attribute_signalInstance->setName("signalInstance");
	m_signalEventOccurrence_Attribute_signalInstance->setEType(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_SignalInstance_Class());
	m_signalEventOccurrence_Attribute_signalInstance->setLowerBound(1);
	m_signalEventOccurrence_Attribute_signalInstance->setUpperBound(1);
	m_signalEventOccurrence_Attribute_signalInstance->setTransient(false);
	m_signalEventOccurrence_Attribute_signalInstance->setVolatile(false);
	m_signalEventOccurrence_Attribute_signalInstance->setChangeable(true);
	m_signalEventOccurrence_Attribute_signalInstance->setUnsettable(false);
	m_signalEventOccurrence_Attribute_signalInstance->setUnique(true);
	m_signalEventOccurrence_Attribute_signalInstance->setDerived(false);
	m_signalEventOccurrence_Attribute_signalInstance->setOrdered(true);
	m_signalEventOccurrence_Attribute_signalInstance->setContainment(false);
	m_signalEventOccurrence_Attribute_signalInstance->setResolveProxies(true);
	m_signalEventOccurrence_Attribute_signalInstance->setDefaultValueLiteral("");	
	
	m_signalEventOccurrence_Attribute_signalInstance->_setID(SIGNALEVENTOCCURRENCE_ATTRIBUTE_SIGNALINSTANCE);
	
	/*
	 * EOperations
	 */
	m_signalEventOccurrence_Operation_getParameterValues_Event->setName("getParameterValues");
	m_signalEventOccurrence_Operation_getParameterValues_Event->setEType(getParameterValue_Class());
	m_signalEventOccurrence_Operation_getParameterValues_Event->setLowerBound(0);
	m_signalEventOccurrence_Operation_getParameterValues_Event->setUpperBound(-1);
	m_signalEventOccurrence_Operation_getParameterValues_Event->setUnique(true);
	m_signalEventOccurrence_Operation_getParameterValues_Event->setOrdered(true);
	
	m_signalEventOccurrence_Operation_getParameterValues_Event->_setID(SIGNALEVENTOCCURRENCE_OPERATION_GETPARAMETERVALUES_EVENT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_signalEventOccurrence_Operation_getParameterValues_Event);
		parameter->setName("event");
		parameter->setEType(uml::umlPackage::eInstance()->getEvent_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_signalEventOccurrence_Operation_match_Trigger->setName("match");
	m_signalEventOccurrence_Operation_match_Trigger->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_signalEventOccurrence_Operation_match_Trigger->setLowerBound(0);
	m_signalEventOccurrence_Operation_match_Trigger->setUpperBound(1);
	m_signalEventOccurrence_Operation_match_Trigger->setUnique(true);
	m_signalEventOccurrence_Operation_match_Trigger->setOrdered(true);
	
	m_signalEventOccurrence_Operation_match_Trigger->_setID(SIGNALEVENTOCCURRENCE_OPERATION_MATCH_TRIGGER);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_signalEventOccurrence_Operation_match_Trigger);
		parameter->setName("trigger");
		parameter->setEType(uml::umlPackage::eInstance()->getTrigger_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void CommonBehaviorPackageImpl::initializePackageEDataTypes()
{
	
}

