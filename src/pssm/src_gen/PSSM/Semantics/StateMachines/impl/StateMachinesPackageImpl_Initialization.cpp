#include "PSSM/Semantics/StateMachines/impl/StateMachinesPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EEnumLiteral.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EEnum.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EReference.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/MDE4CPP_Extensions/MDE4CPP_ExtensionsPackage.hpp"
#include "PSSM/MDE4CPP_Extensions/MDE4CPP_ExtensionsPackage.hpp"
#include "PSSM/PSSMPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"


using namespace PSSM::Semantics::StateMachines;

void StateMachinesPackageImpl::initializePackageContents()
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
	m_completionEventOccurrence_Class->getESuperTypes()->push_back(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventOccurrence_Class());
	m_conditionalPseudostateActivation_Class->getESuperTypes()->push_back(getPseudostateActivation_Class());
	m_connectionPointActivation_Class->getESuperTypes()->push_back(getPseudostateActivation_Class());
	m_deepHistoryPseudostateActivation_Class->getESuperTypes()->push_back(getHistoryPseudostateActivation_Class());
	m_deferredEventOccurrence_Class->getESuperTypes()->push_back(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventOccurrence_Class());
	m_doActivityContextObject_Class->getESuperTypes()->push_back(PSSM::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getPSSM_Object_Class());
	m_doActivityContextObjectActivation_Class->getESuperTypes()->push_back(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getObjectActivation_Class());
	m_doActivityExecutionEventAccepter_Class->getESuperTypes()->push_back(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventAccepter_Class());
	m_entryPointPseudostateActivation_Class->getESuperTypes()->push_back(getConnectionPointActivation_Class());
	m_exitPointPseudostateActivation_Class->getESuperTypes()->push_back(getConnectionPointActivation_Class());
	m_externalTransitionActivation_Class->getESuperTypes()->push_back(getTransitionActivation_Class());
	m_finalStateActivation_Class->getESuperTypes()->push_back(getStateActivation_Class());
	m_forkPseudostateActivation_Class->getESuperTypes()->push_back(getPseudostateActivation_Class());
	m_historyPseudostateActivation_Class->getESuperTypes()->push_back(getPseudostateActivation_Class());
	m_initialPseudostateActivation_Class->getESuperTypes()->push_back(getPseudostateActivation_Class());
	m_internalTransitionActivation_Class->getESuperTypes()->push_back(getTransitionActivation_Class());
	m_joinPseudostateActivation_Class->getESuperTypes()->push_back(getPseudostateActivation_Class());
	m_localTransitionActivation_Class->getESuperTypes()->push_back(getTransitionActivation_Class());
	m_pseudostateActivation_Class->getESuperTypes()->push_back(getVertexActivation_Class());
	m_regionActivation_Class->getESuperTypes()->push_back(getStateMachineSemanticVisitor_Class());
	m_stateActivation_Class->getESuperTypes()->push_back(getVertexActivation_Class());
	m_stateMachineEventAccepter_Class->getESuperTypes()->push_back(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventAccepter_Class());
	m_stateMachineExecution_Class->getESuperTypes()->push_back(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getExecution_Class());
	m_stateMachineSemanticVisitor_Class->getESuperTypes()->push_back(fUML::Semantics::Loci::LociPackage::eInstance()->getSemanticVisitor_Class());
	m_transitionActivation_Class->getESuperTypes()->push_back(getStateMachineSemanticVisitor_Class());
	m_vertexActivation_Class->getESuperTypes()->push_back(getStateMachineSemanticVisitor_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeCompletionEventOccurrenceContent();
	initializeConditionalPseudostateActivationContent();
	initializeConnectionPointActivationContent();
	initializeDeepHistoryPseudostateActivationContent();
	initializeDeferredEventOccurrenceContent();
	initializeDoActivityContextObjectContent();
	initializeDoActivityContextObjectActivationContent();
	initializeDoActivityExecutionEventAccepterContent();
	initializeEntryPointPseudostateActivationContent();
	initializeExitPointPseudostateActivationContent();
	initializeExternalTransitionActivationContent();
	initializeFinalStateActivationContent();
	initializeForkPseudostateActivationContent();
	initializeHistoryPseudostateActivationContent();
	initializeInitialPseudostateActivationContent();
	initializeInternalTransitionActivationContent();
	initializeJoinPseudostateActivationContent();
	initializeLocalTransitionActivationContent();
	initializePseudostateActivationContent();
	initializeRegionActivationContent();
	initializeStateActivationContent();
	initializeStateConfigurationContent();
	initializeStateMachineConfigurationContent();
	initializeStateMachineEventAccepterContent();
	initializeStateMachineExecutionContent();
	initializeStateMachineSemanticVisitorContent();
	initializeTransitionActivationContent();
	initializeVertexActivationContent();

	initializePackageEDataTypes();

}

void StateMachinesPackageImpl::initializeCompletionEventOccurrenceContent()
{
	m_completionEventOccurrence_Class->setName("CompletionEventOccurrence");
	m_completionEventOccurrence_Class->setAbstract(false);
	m_completionEventOccurrence_Class->setInterface(false);
	
	m_completionEventOccurrence_Class->_setID(COMPLETIONEVENTOCCURRENCE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_completionEventOccurrence_Attribute_stateActivation->setName("stateActivation");
	m_completionEventOccurrence_Attribute_stateActivation->setEType(getStateActivation_Class());
	m_completionEventOccurrence_Attribute_stateActivation->setLowerBound(1);
	m_completionEventOccurrence_Attribute_stateActivation->setUpperBound(1);
	m_completionEventOccurrence_Attribute_stateActivation->setTransient(false);
	m_completionEventOccurrence_Attribute_stateActivation->setVolatile(false);
	m_completionEventOccurrence_Attribute_stateActivation->setChangeable(true);
	m_completionEventOccurrence_Attribute_stateActivation->setUnsettable(false);
	m_completionEventOccurrence_Attribute_stateActivation->setUnique(true);
	m_completionEventOccurrence_Attribute_stateActivation->setDerived(false);
	m_completionEventOccurrence_Attribute_stateActivation->setOrdered(false);
	m_completionEventOccurrence_Attribute_stateActivation->setContainment(false);
	m_completionEventOccurrence_Attribute_stateActivation->setResolveProxies(true);
	m_completionEventOccurrence_Attribute_stateActivation->setDefaultValueLiteral("");	
	
	m_completionEventOccurrence_Attribute_stateActivation->_setID(COMPLETIONEVENTOCCURRENCE_ATTRIBUTE_STATEACTIVATION);
	
	/*
	 * EOperations
	 */
	m_completionEventOccurrence_Operation__match_Trigger->setName("_match");
	m_completionEventOccurrence_Operation__match_Trigger->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_completionEventOccurrence_Operation__match_Trigger->setLowerBound(0);
	m_completionEventOccurrence_Operation__match_Trigger->setUpperBound(1);
	m_completionEventOccurrence_Operation__match_Trigger->setUnique(true);
	m_completionEventOccurrence_Operation__match_Trigger->setOrdered(true);
	
	m_completionEventOccurrence_Operation__match_Trigger->_setID(COMPLETIONEVENTOCCURRENCE_OPERATION__MATCH_TRIGGER);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_completionEventOccurrence_Operation__match_Trigger);
		parameter->setName("triggers");
		parameter->setEType(uml::umlPackage::eInstance()->getTrigger_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_completionEventOccurrence_Operation__register_StateActivation->setName("_register");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_completionEventOccurrence_Operation__register_StateActivation->setEType(unknownClass);
	}
	m_completionEventOccurrence_Operation__register_StateActivation->setLowerBound(0);
	m_completionEventOccurrence_Operation__register_StateActivation->setUpperBound(1);
	m_completionEventOccurrence_Operation__register_StateActivation->setUnique(true);
	m_completionEventOccurrence_Operation__register_StateActivation->setOrdered(true);
	
	m_completionEventOccurrence_Operation__register_StateActivation->_setID(COMPLETIONEVENTOCCURRENCE_OPERATION__REGISTER_STATEACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_completionEventOccurrence_Operation__register_StateActivation);
		parameter->setName("stateActivation");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_completionEventOccurrence_Operation_match_Trigger->setName("match");
	m_completionEventOccurrence_Operation_match_Trigger->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_completionEventOccurrence_Operation_match_Trigger->setLowerBound(0);
	m_completionEventOccurrence_Operation_match_Trigger->setUpperBound(1);
	m_completionEventOccurrence_Operation_match_Trigger->setUnique(true);
	m_completionEventOccurrence_Operation_match_Trigger->setOrdered(true);
	
	m_completionEventOccurrence_Operation_match_Trigger->_setID(COMPLETIONEVENTOCCURRENCE_OPERATION_MATCH_TRIGGER);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_completionEventOccurrence_Operation_match_Trigger);
		parameter->setName("trigger");
		parameter->setEType(uml::umlPackage::eInstance()->getTrigger_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void StateMachinesPackageImpl::initializeConditionalPseudostateActivationContent()
{
	m_conditionalPseudostateActivation_Class->setName("ConditionalPseudostateActivation");
	m_conditionalPseudostateActivation_Class->setAbstract(true);
	m_conditionalPseudostateActivation_Class->setInterface(false);
	
	m_conditionalPseudostateActivation_Class->_setID(CONDITIONALPSEUDOSTATEACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_conditionalPseudostateActivation_Operation_isElseTransition_TransitionActivation->setName("isElseTransition");
	m_conditionalPseudostateActivation_Operation_isElseTransition_TransitionActivation->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_conditionalPseudostateActivation_Operation_isElseTransition_TransitionActivation->setLowerBound(1);
	m_conditionalPseudostateActivation_Operation_isElseTransition_TransitionActivation->setUpperBound(1);
	m_conditionalPseudostateActivation_Operation_isElseTransition_TransitionActivation->setUnique(true);
	m_conditionalPseudostateActivation_Operation_isElseTransition_TransitionActivation->setOrdered(false);
	
	m_conditionalPseudostateActivation_Operation_isElseTransition_TransitionActivation->_setID(CONDITIONALPSEUDOSTATEACTIVATION_OPERATION_ISELSETRANSITION_TRANSITIONACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_conditionalPseudostateActivation_Operation_isElseTransition_TransitionActivation);
		parameter->setName("transitionActivation");
		parameter->setEType(getTransitionActivation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void StateMachinesPackageImpl::initializeConnectionPointActivationContent()
{
	m_connectionPointActivation_Class->setName("ConnectionPointActivation");
	m_connectionPointActivation_Class->setAbstract(true);
	m_connectionPointActivation_Class->setInterface(false);
	
	m_connectionPointActivation_Class->_setID(CONNECTIONPOINTACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void StateMachinesPackageImpl::initializeDeepHistoryPseudostateActivationContent()
{
	m_deepHistoryPseudostateActivation_Class->setName("DeepHistoryPseudostateActivation");
	m_deepHistoryPseudostateActivation_Class->setAbstract(false);
	m_deepHistoryPseudostateActivation_Class->setInterface(false);
	
	m_deepHistoryPseudostateActivation_Class->_setID(DEEPHISTORYPSEUDOSTATEACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void StateMachinesPackageImpl::initializeDeferredEventOccurrenceContent()
{
	m_deferredEventOccurrence_Class->setName("DeferredEventOccurrence");
	m_deferredEventOccurrence_Class->setAbstract(false);
	m_deferredEventOccurrence_Class->setInterface(false);
	
	m_deferredEventOccurrence_Class->_setID(DEFERREDEVENTOCCURRENCE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_deferredEventOccurrence_Attribute_constrainingStateActivation->setName("constrainingStateActivation");
	m_deferredEventOccurrence_Attribute_constrainingStateActivation->setEType(getStateActivation_Class());
	m_deferredEventOccurrence_Attribute_constrainingStateActivation->setLowerBound(1);
	m_deferredEventOccurrence_Attribute_constrainingStateActivation->setUpperBound(1);
	m_deferredEventOccurrence_Attribute_constrainingStateActivation->setTransient(false);
	m_deferredEventOccurrence_Attribute_constrainingStateActivation->setVolatile(false);
	m_deferredEventOccurrence_Attribute_constrainingStateActivation->setChangeable(true);
	m_deferredEventOccurrence_Attribute_constrainingStateActivation->setUnsettable(false);
	m_deferredEventOccurrence_Attribute_constrainingStateActivation->setUnique(true);
	m_deferredEventOccurrence_Attribute_constrainingStateActivation->setDerived(false);
	m_deferredEventOccurrence_Attribute_constrainingStateActivation->setOrdered(false);
	m_deferredEventOccurrence_Attribute_constrainingStateActivation->setContainment(false);
	m_deferredEventOccurrence_Attribute_constrainingStateActivation->setResolveProxies(true);
	m_deferredEventOccurrence_Attribute_constrainingStateActivation->setDefaultValueLiteral("");	
	
	m_deferredEventOccurrence_Attribute_constrainingStateActivation->_setID(DEFERREDEVENTOCCURRENCE_ATTRIBUTE_CONSTRAININGSTATEACTIVATION);
	m_deferredEventOccurrence_Attribute_deferredEventOccurrence->setName("deferredEventOccurrence");
	m_deferredEventOccurrence_Attribute_deferredEventOccurrence->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventOccurrence_Class());
	m_deferredEventOccurrence_Attribute_deferredEventOccurrence->setLowerBound(1);
	m_deferredEventOccurrence_Attribute_deferredEventOccurrence->setUpperBound(1);
	m_deferredEventOccurrence_Attribute_deferredEventOccurrence->setTransient(false);
	m_deferredEventOccurrence_Attribute_deferredEventOccurrence->setVolatile(false);
	m_deferredEventOccurrence_Attribute_deferredEventOccurrence->setChangeable(true);
	m_deferredEventOccurrence_Attribute_deferredEventOccurrence->setUnsettable(false);
	m_deferredEventOccurrence_Attribute_deferredEventOccurrence->setUnique(true);
	m_deferredEventOccurrence_Attribute_deferredEventOccurrence->setDerived(false);
	m_deferredEventOccurrence_Attribute_deferredEventOccurrence->setOrdered(false);
	m_deferredEventOccurrence_Attribute_deferredEventOccurrence->setContainment(false);
	m_deferredEventOccurrence_Attribute_deferredEventOccurrence->setResolveProxies(true);
	m_deferredEventOccurrence_Attribute_deferredEventOccurrence->setDefaultValueLiteral("");	
	
	m_deferredEventOccurrence_Attribute_deferredEventOccurrence->_setID(DEFERREDEVENTOCCURRENCE_ATTRIBUTE_DEFERREDEVENTOCCURRENCE);
	
	/*
	 * EOperations
	 */
	
}

void StateMachinesPackageImpl::initializeDoActivityContextObjectContent()
{
	m_doActivityContextObject_Class->setName("DoActivityContextObject");
	m_doActivityContextObject_Class->setAbstract(false);
	m_doActivityContextObject_Class->setInterface(false);
	
	m_doActivityContextObject_Class->_setID(DOACTIVITYCONTEXTOBJECT_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_doActivityContextObject_Attribute_context->setName("context");
	m_doActivityContextObject_Attribute_context->setEType(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_Object_Class());
	m_doActivityContextObject_Attribute_context->setLowerBound(1);
	m_doActivityContextObject_Attribute_context->setUpperBound(1);
	m_doActivityContextObject_Attribute_context->setTransient(false);
	m_doActivityContextObject_Attribute_context->setVolatile(false);
	m_doActivityContextObject_Attribute_context->setChangeable(true);
	m_doActivityContextObject_Attribute_context->setUnsettable(false);
	m_doActivityContextObject_Attribute_context->setUnique(true);
	m_doActivityContextObject_Attribute_context->setDerived(false);
	m_doActivityContextObject_Attribute_context->setOrdered(false);
	m_doActivityContextObject_Attribute_context->setContainment(false);
	m_doActivityContextObject_Attribute_context->setResolveProxies(true);
	m_doActivityContextObject_Attribute_context->setDefaultValueLiteral("");	
	
	m_doActivityContextObject_Attribute_context->_setID(DOACTIVITYCONTEXTOBJECT_ATTRIBUTE_CONTEXT);
	
	/*
	 * EOperations
	 */
	m_doActivityContextObject_Operation__register_EventAccepter->setName("_register");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_doActivityContextObject_Operation__register_EventAccepter->setEType(unknownClass);
	}
	m_doActivityContextObject_Operation__register_EventAccepter->setLowerBound(1);
	m_doActivityContextObject_Operation__register_EventAccepter->setUpperBound(1);
	m_doActivityContextObject_Operation__register_EventAccepter->setUnique(true);
	m_doActivityContextObject_Operation__register_EventAccepter->setOrdered(false);
	
	m_doActivityContextObject_Operation__register_EventAccepter->_setID(DOACTIVITYCONTEXTOBJECT_OPERATION__REGISTER_EVENTACCEPTER);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_doActivityContextObject_Operation__register_EventAccepter);
		parameter->setName("accepter");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_doActivityContextObject_Operation_destroy->setName("destroy");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_doActivityContextObject_Operation_destroy->setEType(unknownClass);
	}
	m_doActivityContextObject_Operation_destroy->setLowerBound(1);
	m_doActivityContextObject_Operation_destroy->setUpperBound(1);
	m_doActivityContextObject_Operation_destroy->setUnique(true);
	m_doActivityContextObject_Operation_destroy->setOrdered(false);
	
	m_doActivityContextObject_Operation_destroy->_setID(DOACTIVITYCONTEXTOBJECT_OPERATION_DESTROY);
	
	
	m_doActivityContextObject_Operation_initialize_FUML_Object->setName("initialize");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_doActivityContextObject_Operation_initialize_FUML_Object->setEType(unknownClass);
	}
	m_doActivityContextObject_Operation_initialize_FUML_Object->setLowerBound(1);
	m_doActivityContextObject_Operation_initialize_FUML_Object->setUpperBound(1);
	m_doActivityContextObject_Operation_initialize_FUML_Object->setUnique(true);
	m_doActivityContextObject_Operation_initialize_FUML_Object->setOrdered(false);
	
	m_doActivityContextObject_Operation_initialize_FUML_Object->_setID(DOACTIVITYCONTEXTOBJECT_OPERATION_INITIALIZE_FUML_OBJECT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_doActivityContextObject_Operation_initialize_FUML_Object);
		parameter->setName("context");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_doActivityContextObject_Operation_send_EventOccurrence->setName("send");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_doActivityContextObject_Operation_send_EventOccurrence->setEType(unknownClass);
	}
	m_doActivityContextObject_Operation_send_EventOccurrence->setLowerBound(1);
	m_doActivityContextObject_Operation_send_EventOccurrence->setUpperBound(1);
	m_doActivityContextObject_Operation_send_EventOccurrence->setUnique(true);
	m_doActivityContextObject_Operation_send_EventOccurrence->setOrdered(false);
	
	m_doActivityContextObject_Operation_send_EventOccurrence->_setID(DOACTIVITYCONTEXTOBJECT_OPERATION_SEND_EVENTOCCURRENCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_doActivityContextObject_Operation_send_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_doActivityContextObject_Operation_startBehavior_Class_ParameterValue->setName("startBehavior");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_doActivityContextObject_Operation_startBehavior_Class_ParameterValue->setEType(unknownClass);
	}
	m_doActivityContextObject_Operation_startBehavior_Class_ParameterValue->setLowerBound(1);
	m_doActivityContextObject_Operation_startBehavior_Class_ParameterValue->setUpperBound(1);
	m_doActivityContextObject_Operation_startBehavior_Class_ParameterValue->setUnique(true);
	m_doActivityContextObject_Operation_startBehavior_Class_ParameterValue->setOrdered(false);
	
	m_doActivityContextObject_Operation_startBehavior_Class_ParameterValue->_setID(DOACTIVITYCONTEXTOBJECT_OPERATION_STARTBEHAVIOR_CLASS_PARAMETERVALUE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_doActivityContextObject_Operation_startBehavior_Class_ParameterValue);
		parameter->setName("classifier");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_doActivityContextObject_Operation_startBehavior_Class_ParameterValue);
		parameter->setName("inputs");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_doActivityContextObject_Operation_unregister_EventAccepter->setName("unregister");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_doActivityContextObject_Operation_unregister_EventAccepter->setEType(unknownClass);
	}
	m_doActivityContextObject_Operation_unregister_EventAccepter->setLowerBound(1);
	m_doActivityContextObject_Operation_unregister_EventAccepter->setUpperBound(1);
	m_doActivityContextObject_Operation_unregister_EventAccepter->setUnique(true);
	m_doActivityContextObject_Operation_unregister_EventAccepter->setOrdered(false);
	
	m_doActivityContextObject_Operation_unregister_EventAccepter->_setID(DOACTIVITYCONTEXTOBJECT_OPERATION_UNREGISTER_EVENTACCEPTER);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_doActivityContextObject_Operation_unregister_EventAccepter);
		parameter->setName("accepter");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_doActivityContextObject_Operation_unregisterFromContext_EventAccepter->setName("unregisterFromContext");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_doActivityContextObject_Operation_unregisterFromContext_EventAccepter->setEType(unknownClass);
	}
	m_doActivityContextObject_Operation_unregisterFromContext_EventAccepter->setLowerBound(1);
	m_doActivityContextObject_Operation_unregisterFromContext_EventAccepter->setUpperBound(1);
	m_doActivityContextObject_Operation_unregisterFromContext_EventAccepter->setUnique(true);
	m_doActivityContextObject_Operation_unregisterFromContext_EventAccepter->setOrdered(false);
	
	m_doActivityContextObject_Operation_unregisterFromContext_EventAccepter->_setID(DOACTIVITYCONTEXTOBJECT_OPERATION_UNREGISTERFROMCONTEXT_EVENTACCEPTER);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_doActivityContextObject_Operation_unregisterFromContext_EventAccepter);
		parameter->setName("encapsulatedAccepter");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void StateMachinesPackageImpl::initializeDoActivityContextObjectActivationContent()
{
	m_doActivityContextObjectActivation_Class->setName("DoActivityContextObjectActivation");
	m_doActivityContextObjectActivation_Class->setAbstract(false);
	m_doActivityContextObjectActivation_Class->setInterface(false);
	
	m_doActivityContextObjectActivation_Class->_setID(DOACTIVITYCONTEXTOBJECTACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_doActivityContextObjectActivation_Operation_dispatchNextEvent->setName("dispatchNextEvent");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_doActivityContextObjectActivation_Operation_dispatchNextEvent->setEType(unknownClass);
	}
	m_doActivityContextObjectActivation_Operation_dispatchNextEvent->setLowerBound(1);
	m_doActivityContextObjectActivation_Operation_dispatchNextEvent->setUpperBound(1);
	m_doActivityContextObjectActivation_Operation_dispatchNextEvent->setUnique(true);
	m_doActivityContextObjectActivation_Operation_dispatchNextEvent->setOrdered(false);
	
	m_doActivityContextObjectActivation_Operation_dispatchNextEvent->_setID(DOACTIVITYCONTEXTOBJECTACTIVATION_OPERATION_DISPATCHNEXTEVENT);
	
	
	m_doActivityContextObjectActivation_Operation_startBehavior_Class_ParameterValue->setName("startBehavior");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_doActivityContextObjectActivation_Operation_startBehavior_Class_ParameterValue->setEType(unknownClass);
	}
	m_doActivityContextObjectActivation_Operation_startBehavior_Class_ParameterValue->setLowerBound(1);
	m_doActivityContextObjectActivation_Operation_startBehavior_Class_ParameterValue->setUpperBound(1);
	m_doActivityContextObjectActivation_Operation_startBehavior_Class_ParameterValue->setUnique(true);
	m_doActivityContextObjectActivation_Operation_startBehavior_Class_ParameterValue->setOrdered(false);
	
	m_doActivityContextObjectActivation_Operation_startBehavior_Class_ParameterValue->_setID(DOACTIVITYCONTEXTOBJECTACTIVATION_OPERATION_STARTBEHAVIOR_CLASS_PARAMETERVALUE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_doActivityContextObjectActivation_Operation_startBehavior_Class_ParameterValue);
		parameter->setName("classifier");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_doActivityContextObjectActivation_Operation_startBehavior_Class_ParameterValue);
		parameter->setName("inputs");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void StateMachinesPackageImpl::initializeDoActivityExecutionEventAccepterContent()
{
	m_doActivityExecutionEventAccepter_Class->setName("DoActivityExecutionEventAccepter");
	m_doActivityExecutionEventAccepter_Class->setAbstract(false);
	m_doActivityExecutionEventAccepter_Class->setInterface(false);
	
	m_doActivityExecutionEventAccepter_Class->_setID(DOACTIVITYEXECUTIONEVENTACCEPTER_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_doActivityExecutionEventAccepter_Attribute_context->setName("context");
	m_doActivityExecutionEventAccepter_Attribute_context->setEType(getDoActivityContextObject_Class());
	m_doActivityExecutionEventAccepter_Attribute_context->setLowerBound(1);
	m_doActivityExecutionEventAccepter_Attribute_context->setUpperBound(1);
	m_doActivityExecutionEventAccepter_Attribute_context->setTransient(false);
	m_doActivityExecutionEventAccepter_Attribute_context->setVolatile(false);
	m_doActivityExecutionEventAccepter_Attribute_context->setChangeable(true);
	m_doActivityExecutionEventAccepter_Attribute_context->setUnsettable(false);
	m_doActivityExecutionEventAccepter_Attribute_context->setUnique(true);
	m_doActivityExecutionEventAccepter_Attribute_context->setDerived(false);
	m_doActivityExecutionEventAccepter_Attribute_context->setOrdered(false);
	m_doActivityExecutionEventAccepter_Attribute_context->setContainment(false);
	m_doActivityExecutionEventAccepter_Attribute_context->setResolveProxies(true);
	m_doActivityExecutionEventAccepter_Attribute_context->setDefaultValueLiteral("");	
	
	m_doActivityExecutionEventAccepter_Attribute_context->_setID(DOACTIVITYEXECUTIONEVENTACCEPTER_ATTRIBUTE_CONTEXT);
	m_doActivityExecutionEventAccepter_Attribute_encapsulatedAccepter->setName("encapsulatedAccepter");
	m_doActivityExecutionEventAccepter_Attribute_encapsulatedAccepter->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventAccepter_Class());
	m_doActivityExecutionEventAccepter_Attribute_encapsulatedAccepter->setLowerBound(1);
	m_doActivityExecutionEventAccepter_Attribute_encapsulatedAccepter->setUpperBound(1);
	m_doActivityExecutionEventAccepter_Attribute_encapsulatedAccepter->setTransient(false);
	m_doActivityExecutionEventAccepter_Attribute_encapsulatedAccepter->setVolatile(false);
	m_doActivityExecutionEventAccepter_Attribute_encapsulatedAccepter->setChangeable(true);
	m_doActivityExecutionEventAccepter_Attribute_encapsulatedAccepter->setUnsettable(false);
	m_doActivityExecutionEventAccepter_Attribute_encapsulatedAccepter->setUnique(true);
	m_doActivityExecutionEventAccepter_Attribute_encapsulatedAccepter->setDerived(false);
	m_doActivityExecutionEventAccepter_Attribute_encapsulatedAccepter->setOrdered(false);
	m_doActivityExecutionEventAccepter_Attribute_encapsulatedAccepter->setContainment(true);
	m_doActivityExecutionEventAccepter_Attribute_encapsulatedAccepter->setResolveProxies(true);
	m_doActivityExecutionEventAccepter_Attribute_encapsulatedAccepter->setDefaultValueLiteral("");	
	
	m_doActivityExecutionEventAccepter_Attribute_encapsulatedAccepter->_setID(DOACTIVITYEXECUTIONEVENTACCEPTER_ATTRIBUTE_ENCAPSULATEDACCEPTER);
	
	/*
	 * EOperations
	 */
	m_doActivityExecutionEventAccepter_Operation_accept_EventOccurrence->setName("accept");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_doActivityExecutionEventAccepter_Operation_accept_EventOccurrence->setEType(unknownClass);
	}
	m_doActivityExecutionEventAccepter_Operation_accept_EventOccurrence->setLowerBound(1);
	m_doActivityExecutionEventAccepter_Operation_accept_EventOccurrence->setUpperBound(1);
	m_doActivityExecutionEventAccepter_Operation_accept_EventOccurrence->setUnique(true);
	m_doActivityExecutionEventAccepter_Operation_accept_EventOccurrence->setOrdered(false);
	
	m_doActivityExecutionEventAccepter_Operation_accept_EventOccurrence->_setID(DOACTIVITYEXECUTIONEVENTACCEPTER_OPERATION_ACCEPT_EVENTOCCURRENCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_doActivityExecutionEventAccepter_Operation_accept_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_doActivityExecutionEventAccepter_Operation_match_EventOccurrence->setName("match");
	m_doActivityExecutionEventAccepter_Operation_match_EventOccurrence->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_doActivityExecutionEventAccepter_Operation_match_EventOccurrence->setLowerBound(1);
	m_doActivityExecutionEventAccepter_Operation_match_EventOccurrence->setUpperBound(1);
	m_doActivityExecutionEventAccepter_Operation_match_EventOccurrence->setUnique(true);
	m_doActivityExecutionEventAccepter_Operation_match_EventOccurrence->setOrdered(false);
	
	m_doActivityExecutionEventAccepter_Operation_match_EventOccurrence->_setID(DOACTIVITYEXECUTIONEVENTACCEPTER_OPERATION_MATCH_EVENTOCCURRENCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_doActivityExecutionEventAccepter_Operation_match_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventOccurrence_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void StateMachinesPackageImpl::initializeEntryPointPseudostateActivationContent()
{
	m_entryPointPseudostateActivation_Class->setName("EntryPointPseudostateActivation");
	m_entryPointPseudostateActivation_Class->setAbstract(false);
	m_entryPointPseudostateActivation_Class->setInterface(false);
	
	m_entryPointPseudostateActivation_Class->_setID(ENTRYPOINTPSEUDOSTATEACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_entryPointPseudostateActivation_Operation__enter_TransitionActivation_RegionActivation->setName("_enter");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_entryPointPseudostateActivation_Operation__enter_TransitionActivation_RegionActivation->setEType(unknownClass);
	}
	m_entryPointPseudostateActivation_Operation__enter_TransitionActivation_RegionActivation->setLowerBound(1);
	m_entryPointPseudostateActivation_Operation__enter_TransitionActivation_RegionActivation->setUpperBound(1);
	m_entryPointPseudostateActivation_Operation__enter_TransitionActivation_RegionActivation->setUnique(true);
	m_entryPointPseudostateActivation_Operation__enter_TransitionActivation_RegionActivation->setOrdered(false);
	
	m_entryPointPseudostateActivation_Operation__enter_TransitionActivation_RegionActivation->_setID(ENTRYPOINTPSEUDOSTATEACTIVATION_OPERATION__ENTER_TRANSITIONACTIVATION_REGIONACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_entryPointPseudostateActivation_Operation__enter_TransitionActivation_RegionActivation);
		parameter->setName("enteringTransition");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_entryPointPseudostateActivation_Operation__enter_TransitionActivation_RegionActivation);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_entryPointPseudostateActivation_Operation__enter_TransitionActivation_RegionActivation);
		parameter->setName("leastCommonAncestor");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void StateMachinesPackageImpl::initializeExitPointPseudostateActivationContent()
{
	m_exitPointPseudostateActivation_Class->setName("ExitPointPseudostateActivation");
	m_exitPointPseudostateActivation_Class->setAbstract(false);
	m_exitPointPseudostateActivation_Class->setInterface(false);
	
	m_exitPointPseudostateActivation_Class->_setID(EXITPOINTPSEUDOSTATEACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void StateMachinesPackageImpl::initializeExternalTransitionActivationContent()
{
	m_externalTransitionActivation_Class->setName("ExternalTransitionActivation");
	m_externalTransitionActivation_Class->setAbstract(false);
	m_externalTransitionActivation_Class->setInterface(false);
	
	m_externalTransitionActivation_Class->_setID(EXTERNALTRANSITIONACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void StateMachinesPackageImpl::initializeFinalStateActivationContent()
{
	m_finalStateActivation_Class->setName("FinalStateActivation");
	m_finalStateActivation_Class->setAbstract(false);
	m_finalStateActivation_Class->setInterface(false);
	
	m_finalStateActivation_Class->_setID(FINALSTATEACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_finalStateActivation_Operation_enter_TransitionActivation_RegionActivation->setName("enter");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_finalStateActivation_Operation_enter_TransitionActivation_RegionActivation->setEType(unknownClass);
	}
	m_finalStateActivation_Operation_enter_TransitionActivation_RegionActivation->setLowerBound(0);
	m_finalStateActivation_Operation_enter_TransitionActivation_RegionActivation->setUpperBound(1);
	m_finalStateActivation_Operation_enter_TransitionActivation_RegionActivation->setUnique(true);
	m_finalStateActivation_Operation_enter_TransitionActivation_RegionActivation->setOrdered(true);
	
	m_finalStateActivation_Operation_enter_TransitionActivation_RegionActivation->_setID(FINALSTATEACTIVATION_OPERATION_ENTER_TRANSITIONACTIVATION_REGIONACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_finalStateActivation_Operation_enter_TransitionActivation_RegionActivation);
		parameter->setName("enteringTransition");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_finalStateActivation_Operation_enter_TransitionActivation_RegionActivation);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_finalStateActivation_Operation_enter_TransitionActivation_RegionActivation);
		parameter->setName("leastCommonAncestor");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void StateMachinesPackageImpl::initializeForkPseudostateActivationContent()
{
	m_forkPseudostateActivation_Class->setName("ForkPseudostateActivation");
	m_forkPseudostateActivation_Class->setAbstract(false);
	m_forkPseudostateActivation_Class->setInterface(false);
	
	m_forkPseudostateActivation_Class->_setID(FORKPSEUDOSTATEACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_forkPseudostateActivation_Operation_canPropagateExecution_TransitionActivation_RegionActivation->setName("canPropagateExecution");
	m_forkPseudostateActivation_Operation_canPropagateExecution_TransitionActivation_RegionActivation->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_forkPseudostateActivation_Operation_canPropagateExecution_TransitionActivation_RegionActivation->setLowerBound(1);
	m_forkPseudostateActivation_Operation_canPropagateExecution_TransitionActivation_RegionActivation->setUpperBound(1);
	m_forkPseudostateActivation_Operation_canPropagateExecution_TransitionActivation_RegionActivation->setUnique(true);
	m_forkPseudostateActivation_Operation_canPropagateExecution_TransitionActivation_RegionActivation->setOrdered(false);
	
	m_forkPseudostateActivation_Operation_canPropagateExecution_TransitionActivation_RegionActivation->_setID(FORKPSEUDOSTATEACTIVATION_OPERATION_CANPROPAGATEEXECUTION_TRANSITIONACTIVATION_REGIONACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_forkPseudostateActivation_Operation_canPropagateExecution_TransitionActivation_RegionActivation);
		parameter->setName("enteringTransition");
		parameter->setEType(getTransitionActivation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_forkPseudostateActivation_Operation_canPropagateExecution_TransitionActivation_RegionActivation);
		parameter->setName("eventOccurrence");
		parameter->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventOccurrence_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_forkPseudostateActivation_Operation_canPropagateExecution_TransitionActivation_RegionActivation);
		parameter->setName("leastCommonAncestor");
		parameter->setEType(getRegionActivation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void StateMachinesPackageImpl::initializeHistoryPseudostateActivationContent()
{
	m_historyPseudostateActivation_Class->setName("HistoryPseudostateActivation");
	m_historyPseudostateActivation_Class->setAbstract(true);
	m_historyPseudostateActivation_Class->setInterface(false);
	
	m_historyPseudostateActivation_Class->_setID(HISTORYPSEUDOSTATEACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void StateMachinesPackageImpl::initializeInitialPseudostateActivationContent()
{
	m_initialPseudostateActivation_Class->setName("InitialPseudostateActivation");
	m_initialPseudostateActivation_Class->setAbstract(false);
	m_initialPseudostateActivation_Class->setInterface(false);
	
	m_initialPseudostateActivation_Class->_setID(INITIALPSEUDOSTATEACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_initialPseudostateActivation_Operation_enter_TransitionActivation_RegionActivation->setName("enter");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_initialPseudostateActivation_Operation_enter_TransitionActivation_RegionActivation->setEType(unknownClass);
	}
	m_initialPseudostateActivation_Operation_enter_TransitionActivation_RegionActivation->setLowerBound(0);
	m_initialPseudostateActivation_Operation_enter_TransitionActivation_RegionActivation->setUpperBound(1);
	m_initialPseudostateActivation_Operation_enter_TransitionActivation_RegionActivation->setUnique(true);
	m_initialPseudostateActivation_Operation_enter_TransitionActivation_RegionActivation->setOrdered(true);
	
	m_initialPseudostateActivation_Operation_enter_TransitionActivation_RegionActivation->_setID(INITIALPSEUDOSTATEACTIVATION_OPERATION_ENTER_TRANSITIONACTIVATION_REGIONACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_initialPseudostateActivation_Operation_enter_TransitionActivation_RegionActivation);
		parameter->setName("enteringTransition");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_initialPseudostateActivation_Operation_enter_TransitionActivation_RegionActivation);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_initialPseudostateActivation_Operation_enter_TransitionActivation_RegionActivation);
		parameter->setName("leastCommonAncestor");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void StateMachinesPackageImpl::initializeInternalTransitionActivationContent()
{
	m_internalTransitionActivation_Class->setName("InternalTransitionActivation");
	m_internalTransitionActivation_Class->setAbstract(false);
	m_internalTransitionActivation_Class->setInterface(false);
	
	m_internalTransitionActivation_Class->_setID(INTERNALTRANSITIONACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void StateMachinesPackageImpl::initializeJoinPseudostateActivationContent()
{
	m_joinPseudostateActivation_Class->setName("JoinPseudostateActivation");
	m_joinPseudostateActivation_Class->setAbstract(false);
	m_joinPseudostateActivation_Class->setInterface(false);
	
	m_joinPseudostateActivation_Class->_setID(JOINPSEUDOSTATEACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_joinPseudostateActivation_Operation_canPropagateExecution_TransitionActivation_RegionActivation->setName("canPropagateExecution");
	m_joinPseudostateActivation_Operation_canPropagateExecution_TransitionActivation_RegionActivation->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_joinPseudostateActivation_Operation_canPropagateExecution_TransitionActivation_RegionActivation->setLowerBound(1);
	m_joinPseudostateActivation_Operation_canPropagateExecution_TransitionActivation_RegionActivation->setUpperBound(1);
	m_joinPseudostateActivation_Operation_canPropagateExecution_TransitionActivation_RegionActivation->setUnique(true);
	m_joinPseudostateActivation_Operation_canPropagateExecution_TransitionActivation_RegionActivation->setOrdered(false);
	
	m_joinPseudostateActivation_Operation_canPropagateExecution_TransitionActivation_RegionActivation->_setID(JOINPSEUDOSTATEACTIVATION_OPERATION_CANPROPAGATEEXECUTION_TRANSITIONACTIVATION_REGIONACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_joinPseudostateActivation_Operation_canPropagateExecution_TransitionActivation_RegionActivation);
		parameter->setName("enteringTransition");
		parameter->setEType(getTransitionActivation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_joinPseudostateActivation_Operation_canPropagateExecution_TransitionActivation_RegionActivation);
		parameter->setName("eventOccurrence");
		parameter->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventOccurrence_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_joinPseudostateActivation_Operation_canPropagateExecution_TransitionActivation_RegionActivation);
		parameter->setName("leastCommonAncestor");
		parameter->setEType(getRegionActivation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void StateMachinesPackageImpl::initializeLocalTransitionActivationContent()
{
	m_localTransitionActivation_Class->setName("LocalTransitionActivation");
	m_localTransitionActivation_Class->setAbstract(false);
	m_localTransitionActivation_Class->setInterface(false);
	
	m_localTransitionActivation_Class->_setID(LOCALTRANSITIONACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_localTransitionActivation_Operation_getContainingState->setName("getContainingState");
	m_localTransitionActivation_Operation_getContainingState->setEType(getStateActivation_Class());
	m_localTransitionActivation_Operation_getContainingState->setLowerBound(1);
	m_localTransitionActivation_Operation_getContainingState->setUpperBound(1);
	m_localTransitionActivation_Operation_getContainingState->setUnique(true);
	m_localTransitionActivation_Operation_getContainingState->setOrdered(false);
	
	m_localTransitionActivation_Operation_getContainingState->_setID(LOCALTRANSITIONACTIVATION_OPERATION_GETCONTAININGSTATE);
	
	
	
}

void StateMachinesPackageImpl::initializePseudostateActivationContent()
{
	m_pseudostateActivation_Class->setName("PseudostateActivation");
	m_pseudostateActivation_Class->setAbstract(true);
	m_pseudostateActivation_Class->setInterface(false);
	
	m_pseudostateActivation_Class->_setID(PSEUDOSTATEACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_pseudostateActivation_Attribute_fireableTransitions->setName("fireableTransitions");
	m_pseudostateActivation_Attribute_fireableTransitions->setEType(getTransitionActivation_Class());
	m_pseudostateActivation_Attribute_fireableTransitions->setLowerBound(0);
	m_pseudostateActivation_Attribute_fireableTransitions->setUpperBound(-1);
	m_pseudostateActivation_Attribute_fireableTransitions->setTransient(false);
	m_pseudostateActivation_Attribute_fireableTransitions->setVolatile(false);
	m_pseudostateActivation_Attribute_fireableTransitions->setChangeable(true);
	m_pseudostateActivation_Attribute_fireableTransitions->setUnsettable(false);
	m_pseudostateActivation_Attribute_fireableTransitions->setUnique(true);
	m_pseudostateActivation_Attribute_fireableTransitions->setDerived(false);
	m_pseudostateActivation_Attribute_fireableTransitions->setOrdered(false);
	m_pseudostateActivation_Attribute_fireableTransitions->setContainment(false);
	m_pseudostateActivation_Attribute_fireableTransitions->setResolveProxies(true);
	m_pseudostateActivation_Attribute_fireableTransitions->setDefaultValueLiteral("");	
	
	m_pseudostateActivation_Attribute_fireableTransitions->_setID(PSEUDOSTATEACTIVATION_ATTRIBUTE_FIREABLETRANSITIONS);
	
	/*
	 * EOperations
	 */
	m_pseudostateActivation_Operation_evaluateAllGuards_EventOccurrence->setName("evaluateAllGuards");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_pseudostateActivation_Operation_evaluateAllGuards_EventOccurrence->setEType(unknownClass);
	}
	m_pseudostateActivation_Operation_evaluateAllGuards_EventOccurrence->setLowerBound(1);
	m_pseudostateActivation_Operation_evaluateAllGuards_EventOccurrence->setUpperBound(1);
	m_pseudostateActivation_Operation_evaluateAllGuards_EventOccurrence->setUnique(true);
	m_pseudostateActivation_Operation_evaluateAllGuards_EventOccurrence->setOrdered(false);
	
	m_pseudostateActivation_Operation_evaluateAllGuards_EventOccurrence->_setID(PSEUDOSTATEACTIVATION_OPERATION_EVALUATEALLGUARDS_EVENTOCCURRENCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_pseudostateActivation_Operation_evaluateAllGuards_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void StateMachinesPackageImpl::initializeRegionActivationContent()
{
	m_regionActivation_Class->setName("RegionActivation");
	m_regionActivation_Class->setAbstract(false);
	m_regionActivation_Class->setInterface(false);
	
	m_regionActivation_Class->_setID(REGIONACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	m_regionActivation_Attribute_isCompleted = getRegionActivation_Attribute_isCompleted();
	m_regionActivation_Attribute_isCompleted->setName("isCompleted");
	m_regionActivation_Attribute_isCompleted->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_regionActivation_Attribute_isCompleted->setLowerBound(1);
	m_regionActivation_Attribute_isCompleted->setUpperBound(1);
	m_regionActivation_Attribute_isCompleted->setTransient(false);
	m_regionActivation_Attribute_isCompleted->setVolatile(false);
	m_regionActivation_Attribute_isCompleted->setChangeable(true);
	m_regionActivation_Attribute_isCompleted->setUnsettable(false);
	m_regionActivation_Attribute_isCompleted->setUnique(true);
	m_regionActivation_Attribute_isCompleted->setDerived(false);
	m_regionActivation_Attribute_isCompleted->setOrdered(false);
	m_regionActivation_Attribute_isCompleted->setID(false);
	m_regionActivation_Attribute_isCompleted->setDefaultValueLiteral("");
	
	m_regionActivation_Attribute_isCompleted->_setID(REGIONACTIVATION_ATTRIBUTE_ISCOMPLETED);
	
	/*
	 * EReferences
	 */
	m_regionActivation_Attribute_history->setName("history");
	m_regionActivation_Attribute_history->setEType(getStateActivation_Class());
	m_regionActivation_Attribute_history->setLowerBound(0);
	m_regionActivation_Attribute_history->setUpperBound(1);
	m_regionActivation_Attribute_history->setTransient(false);
	m_regionActivation_Attribute_history->setVolatile(false);
	m_regionActivation_Attribute_history->setChangeable(true);
	m_regionActivation_Attribute_history->setUnsettable(false);
	m_regionActivation_Attribute_history->setUnique(true);
	m_regionActivation_Attribute_history->setDerived(false);
	m_regionActivation_Attribute_history->setOrdered(false);
	m_regionActivation_Attribute_history->setContainment(false);
	m_regionActivation_Attribute_history->setResolveProxies(true);
	m_regionActivation_Attribute_history->setDefaultValueLiteral("");	
	
	m_regionActivation_Attribute_history->_setID(REGIONACTIVATION_ATTRIBUTE_HISTORY);
	m_regionActivation_Attribute_transitionActivations->setName("transitionActivations");
	m_regionActivation_Attribute_transitionActivations->setEType(getTransitionActivation_Class());
	m_regionActivation_Attribute_transitionActivations->setLowerBound(0);
	m_regionActivation_Attribute_transitionActivations->setUpperBound(-1);
	m_regionActivation_Attribute_transitionActivations->setTransient(false);
	m_regionActivation_Attribute_transitionActivations->setVolatile(false);
	m_regionActivation_Attribute_transitionActivations->setChangeable(true);
	m_regionActivation_Attribute_transitionActivations->setUnsettable(false);
	m_regionActivation_Attribute_transitionActivations->setUnique(true);
	m_regionActivation_Attribute_transitionActivations->setDerived(false);
	m_regionActivation_Attribute_transitionActivations->setOrdered(false);
	m_regionActivation_Attribute_transitionActivations->setContainment(true);
	m_regionActivation_Attribute_transitionActivations->setResolveProxies(true);
	m_regionActivation_Attribute_transitionActivations->setDefaultValueLiteral("");	
	
	m_regionActivation_Attribute_transitionActivations->_setID(REGIONACTIVATION_ATTRIBUTE_TRANSITIONACTIVATIONS);
	m_regionActivation_Attribute_vertexActivations->setName("vertexActivations");
	m_regionActivation_Attribute_vertexActivations->setEType(getVertexActivation_Class());
	m_regionActivation_Attribute_vertexActivations->setLowerBound(0);
	m_regionActivation_Attribute_vertexActivations->setUpperBound(-1);
	m_regionActivation_Attribute_vertexActivations->setTransient(false);
	m_regionActivation_Attribute_vertexActivations->setVolatile(false);
	m_regionActivation_Attribute_vertexActivations->setChangeable(true);
	m_regionActivation_Attribute_vertexActivations->setUnsettable(false);
	m_regionActivation_Attribute_vertexActivations->setUnique(true);
	m_regionActivation_Attribute_vertexActivations->setDerived(false);
	m_regionActivation_Attribute_vertexActivations->setOrdered(false);
	m_regionActivation_Attribute_vertexActivations->setContainment(true);
	m_regionActivation_Attribute_vertexActivations->setResolveProxies(true);
	m_regionActivation_Attribute_vertexActivations->setDefaultValueLiteral("");	
	
	m_regionActivation_Attribute_vertexActivations->_setID(REGIONACTIVATION_ATTRIBUTE_VERTEXACTIVATIONS);
	
	/*
	 * EOperations
	 */
	m_regionActivation_Operation_canPropagateExecution_TransitionActivation_EventOccurrence->setName("canPropagateExecution");
	m_regionActivation_Operation_canPropagateExecution_TransitionActivation_EventOccurrence->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_regionActivation_Operation_canPropagateExecution_TransitionActivation_EventOccurrence->setLowerBound(1);
	m_regionActivation_Operation_canPropagateExecution_TransitionActivation_EventOccurrence->setUpperBound(1);
	m_regionActivation_Operation_canPropagateExecution_TransitionActivation_EventOccurrence->setUnique(true);
	m_regionActivation_Operation_canPropagateExecution_TransitionActivation_EventOccurrence->setOrdered(false);
	
	m_regionActivation_Operation_canPropagateExecution_TransitionActivation_EventOccurrence->_setID(REGIONACTIVATION_OPERATION_CANPROPAGATEEXECUTION_TRANSITIONACTIVATION_EVENTOCCURRENCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_regionActivation_Operation_canPropagateExecution_TransitionActivation_EventOccurrence);
		parameter->setName("enteringTransition");
		parameter->setEType(getTransitionActivation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_regionActivation_Operation_canPropagateExecution_TransitionActivation_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventOccurrence_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_regionActivation_Operation_enter_TransitionActivation_EventOccurrence->setName("enter");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_regionActivation_Operation_enter_TransitionActivation_EventOccurrence->setEType(unknownClass);
	}
	m_regionActivation_Operation_enter_TransitionActivation_EventOccurrence->setLowerBound(1);
	m_regionActivation_Operation_enter_TransitionActivation_EventOccurrence->setUpperBound(1);
	m_regionActivation_Operation_enter_TransitionActivation_EventOccurrence->setUnique(true);
	m_regionActivation_Operation_enter_TransitionActivation_EventOccurrence->setOrdered(false);
	
	m_regionActivation_Operation_enter_TransitionActivation_EventOccurrence->_setID(REGIONACTIVATION_OPERATION_ENTER_TRANSITIONACTIVATION_EVENTOCCURRENCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_regionActivation_Operation_enter_TransitionActivation_EventOccurrence);
		parameter->setName("enteringTransition");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_regionActivation_Operation_enter_TransitionActivation_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_regionActivation_Operation_exit_TransitionActivation_EventOccurrence->setName("exit");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_regionActivation_Operation_exit_TransitionActivation_EventOccurrence->setEType(unknownClass);
	}
	m_regionActivation_Operation_exit_TransitionActivation_EventOccurrence->setLowerBound(1);
	m_regionActivation_Operation_exit_TransitionActivation_EventOccurrence->setUpperBound(1);
	m_regionActivation_Operation_exit_TransitionActivation_EventOccurrence->setUnique(true);
	m_regionActivation_Operation_exit_TransitionActivation_EventOccurrence->setOrdered(false);
	
	m_regionActivation_Operation_exit_TransitionActivation_EventOccurrence->_setID(REGIONACTIVATION_OPERATION_EXIT_TRANSITIONACTIVATION_EVENTOCCURRENCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_regionActivation_Operation_exit_TransitionActivation_EventOccurrence);
		parameter->setName("exitingTransition");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_regionActivation_Operation_exit_TransitionActivation_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_regionActivation_Operation_getOrigin->setName("getOrigin");
	m_regionActivation_Operation_getOrigin->setEType(getInitialPseudostateActivation_Class());
	m_regionActivation_Operation_getOrigin->setLowerBound(1);
	m_regionActivation_Operation_getOrigin->setUpperBound(1);
	m_regionActivation_Operation_getOrigin->setUnique(true);
	m_regionActivation_Operation_getOrigin->setOrdered(false);
	
	m_regionActivation_Operation_getOrigin->_setID(REGIONACTIVATION_OPERATION_GETORIGIN);
	
	
	m_regionActivation_Operation_getVertexActivation_Vertex->setName("getVertexActivation");
	m_regionActivation_Operation_getVertexActivation_Vertex->setEType(getVertexActivation_Class());
	m_regionActivation_Operation_getVertexActivation_Vertex->setLowerBound(1);
	m_regionActivation_Operation_getVertexActivation_Vertex->setUpperBound(1);
	m_regionActivation_Operation_getVertexActivation_Vertex->setUnique(true);
	m_regionActivation_Operation_getVertexActivation_Vertex->setOrdered(false);
	
	m_regionActivation_Operation_getVertexActivation_Vertex->_setID(REGIONACTIVATION_OPERATION_GETVERTEXACTIVATION_VERTEX);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_regionActivation_Operation_getVertexActivation_Vertex);
		parameter->setName("vertex");
		parameter->setEType(uml::umlPackage::eInstance()->getVertex_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_regionActivation_Operation_isRedefined_Vertex_Vertex->setName("isRedefined");
	m_regionActivation_Operation_isRedefined_Vertex_Vertex->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_regionActivation_Operation_isRedefined_Vertex_Vertex->setLowerBound(1);
	m_regionActivation_Operation_isRedefined_Vertex_Vertex->setUpperBound(1);
	m_regionActivation_Operation_isRedefined_Vertex_Vertex->setUnique(true);
	m_regionActivation_Operation_isRedefined_Vertex_Vertex->setOrdered(false);
	
	m_regionActivation_Operation_isRedefined_Vertex_Vertex->_setID(REGIONACTIVATION_OPERATION_ISREDEFINED_VERTEX_VERTEX);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_regionActivation_Operation_isRedefined_Vertex_Vertex);
		parameter->setName("vertices");
		parameter->setEType(uml::umlPackage::eInstance()->getVertex_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_regionActivation_Operation_isRedefined_Vertex_Vertex);
		parameter->setName("vertex");
		parameter->setEType(uml::umlPackage::eInstance()->getVertex_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_regionActivation_Operation_isRedefined_Transition_Transition->setName("isRedefined");
	m_regionActivation_Operation_isRedefined_Transition_Transition->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_regionActivation_Operation_isRedefined_Transition_Transition->setLowerBound(1);
	m_regionActivation_Operation_isRedefined_Transition_Transition->setUpperBound(1);
	m_regionActivation_Operation_isRedefined_Transition_Transition->setUnique(true);
	m_regionActivation_Operation_isRedefined_Transition_Transition->setOrdered(false);
	
	m_regionActivation_Operation_isRedefined_Transition_Transition->_setID(REGIONACTIVATION_OPERATION_ISREDEFINED_TRANSITION_TRANSITION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_regionActivation_Operation_isRedefined_Transition_Transition);
		parameter->setName("transitions");
		parameter->setEType(uml::umlPackage::eInstance()->getTransition_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_regionActivation_Operation_isRedefined_Transition_Transition);
		parameter->setName("transition");
		parameter->setEType(uml::umlPackage::eInstance()->getTransition_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_regionActivation_Operation_terminate->setName("terminate");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_regionActivation_Operation_terminate->setEType(unknownClass);
	}
	m_regionActivation_Operation_terminate->setLowerBound(1);
	m_regionActivation_Operation_terminate->setUpperBound(1);
	m_regionActivation_Operation_terminate->setUnique(true);
	m_regionActivation_Operation_terminate->setOrdered(false);
	
	m_regionActivation_Operation_terminate->_setID(REGIONACTIVATION_OPERATION_TERMINATE);
	
	
	
}

void StateMachinesPackageImpl::initializeStateActivationContent()
{
	m_stateActivation_Class->setName("StateActivation");
	m_stateActivation_Class->setAbstract(false);
	m_stateActivation_Class->setInterface(false);
	
	m_stateActivation_Class->_setID(STATEACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	m_stateActivation_Attribute_isDoActivityCompleted = getStateActivation_Attribute_isDoActivityCompleted();
	m_stateActivation_Attribute_isDoActivityCompleted->setName("isDoActivityCompleted");
	m_stateActivation_Attribute_isDoActivityCompleted->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_stateActivation_Attribute_isDoActivityCompleted->setLowerBound(1);
	m_stateActivation_Attribute_isDoActivityCompleted->setUpperBound(1);
	m_stateActivation_Attribute_isDoActivityCompleted->setTransient(false);
	m_stateActivation_Attribute_isDoActivityCompleted->setVolatile(false);
	m_stateActivation_Attribute_isDoActivityCompleted->setChangeable(true);
	m_stateActivation_Attribute_isDoActivityCompleted->setUnsettable(false);
	m_stateActivation_Attribute_isDoActivityCompleted->setUnique(true);
	m_stateActivation_Attribute_isDoActivityCompleted->setDerived(false);
	m_stateActivation_Attribute_isDoActivityCompleted->setOrdered(false);
	m_stateActivation_Attribute_isDoActivityCompleted->setID(false);
	m_stateActivation_Attribute_isDoActivityCompleted->setDefaultValueLiteral("");
	
	m_stateActivation_Attribute_isDoActivityCompleted->_setID(STATEACTIVATION_ATTRIBUTE_ISDOACTIVITYCOMPLETED);
	m_stateActivation_Attribute_isEntryCompleted = getStateActivation_Attribute_isEntryCompleted();
	m_stateActivation_Attribute_isEntryCompleted->setName("isEntryCompleted");
	m_stateActivation_Attribute_isEntryCompleted->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_stateActivation_Attribute_isEntryCompleted->setLowerBound(1);
	m_stateActivation_Attribute_isEntryCompleted->setUpperBound(1);
	m_stateActivation_Attribute_isEntryCompleted->setTransient(false);
	m_stateActivation_Attribute_isEntryCompleted->setVolatile(false);
	m_stateActivation_Attribute_isEntryCompleted->setChangeable(true);
	m_stateActivation_Attribute_isEntryCompleted->setUnsettable(false);
	m_stateActivation_Attribute_isEntryCompleted->setUnique(true);
	m_stateActivation_Attribute_isEntryCompleted->setDerived(false);
	m_stateActivation_Attribute_isEntryCompleted->setOrdered(false);
	m_stateActivation_Attribute_isEntryCompleted->setID(false);
	m_stateActivation_Attribute_isEntryCompleted->setDefaultValueLiteral("");
	
	m_stateActivation_Attribute_isEntryCompleted->_setID(STATEACTIVATION_ATTRIBUTE_ISENTRYCOMPLETED);
	m_stateActivation_Attribute_isExitCompleted = getStateActivation_Attribute_isExitCompleted();
	m_stateActivation_Attribute_isExitCompleted->setName("isExitCompleted");
	m_stateActivation_Attribute_isExitCompleted->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_stateActivation_Attribute_isExitCompleted->setLowerBound(1);
	m_stateActivation_Attribute_isExitCompleted->setUpperBound(1);
	m_stateActivation_Attribute_isExitCompleted->setTransient(false);
	m_stateActivation_Attribute_isExitCompleted->setVolatile(false);
	m_stateActivation_Attribute_isExitCompleted->setChangeable(true);
	m_stateActivation_Attribute_isExitCompleted->setUnsettable(false);
	m_stateActivation_Attribute_isExitCompleted->setUnique(true);
	m_stateActivation_Attribute_isExitCompleted->setDerived(false);
	m_stateActivation_Attribute_isExitCompleted->setOrdered(false);
	m_stateActivation_Attribute_isExitCompleted->setID(false);
	m_stateActivation_Attribute_isExitCompleted->setDefaultValueLiteral("");
	
	m_stateActivation_Attribute_isExitCompleted->_setID(STATEACTIVATION_ATTRIBUTE_ISEXITCOMPLETED);
	
	/*
	 * EReferences
	 */
	m_stateActivation_Attribute_connectionPointActivations->setName("connectionPointActivations");
	m_stateActivation_Attribute_connectionPointActivations->setEType(getConnectionPointActivation_Class());
	m_stateActivation_Attribute_connectionPointActivations->setLowerBound(0);
	m_stateActivation_Attribute_connectionPointActivations->setUpperBound(-1);
	m_stateActivation_Attribute_connectionPointActivations->setTransient(false);
	m_stateActivation_Attribute_connectionPointActivations->setVolatile(false);
	m_stateActivation_Attribute_connectionPointActivations->setChangeable(true);
	m_stateActivation_Attribute_connectionPointActivations->setUnsettable(false);
	m_stateActivation_Attribute_connectionPointActivations->setUnique(true);
	m_stateActivation_Attribute_connectionPointActivations->setDerived(false);
	m_stateActivation_Attribute_connectionPointActivations->setOrdered(false);
	m_stateActivation_Attribute_connectionPointActivations->setContainment(true);
	m_stateActivation_Attribute_connectionPointActivations->setResolveProxies(true);
	m_stateActivation_Attribute_connectionPointActivations->setDefaultValueLiteral("");	
	
	m_stateActivation_Attribute_connectionPointActivations->_setID(STATEACTIVATION_ATTRIBUTE_CONNECTIONPOINTACTIVATIONS);
	m_stateActivation_Attribute_doActivityContextObject->setName("doActivityContextObject");
	m_stateActivation_Attribute_doActivityContextObject->setEType(getDoActivityContextObject_Class());
	m_stateActivation_Attribute_doActivityContextObject->setLowerBound(0);
	m_stateActivation_Attribute_doActivityContextObject->setUpperBound(1);
	m_stateActivation_Attribute_doActivityContextObject->setTransient(false);
	m_stateActivation_Attribute_doActivityContextObject->setVolatile(false);
	m_stateActivation_Attribute_doActivityContextObject->setChangeable(true);
	m_stateActivation_Attribute_doActivityContextObject->setUnsettable(false);
	m_stateActivation_Attribute_doActivityContextObject->setUnique(true);
	m_stateActivation_Attribute_doActivityContextObject->setDerived(false);
	m_stateActivation_Attribute_doActivityContextObject->setOrdered(false);
	m_stateActivation_Attribute_doActivityContextObject->setContainment(false);
	m_stateActivation_Attribute_doActivityContextObject->setResolveProxies(true);
	m_stateActivation_Attribute_doActivityContextObject->setDefaultValueLiteral("");	
	
	m_stateActivation_Attribute_doActivityContextObject->_setID(STATEACTIVATION_ATTRIBUTE_DOACTIVITYCONTEXTOBJECT);
	m_stateActivation_Attribute_regionActivations->setName("regionActivations");
	m_stateActivation_Attribute_regionActivations->setEType(getRegionActivation_Class());
	m_stateActivation_Attribute_regionActivations->setLowerBound(0);
	m_stateActivation_Attribute_regionActivations->setUpperBound(-1);
	m_stateActivation_Attribute_regionActivations->setTransient(false);
	m_stateActivation_Attribute_regionActivations->setVolatile(false);
	m_stateActivation_Attribute_regionActivations->setChangeable(true);
	m_stateActivation_Attribute_regionActivations->setUnsettable(false);
	m_stateActivation_Attribute_regionActivations->setUnique(true);
	m_stateActivation_Attribute_regionActivations->setDerived(false);
	m_stateActivation_Attribute_regionActivations->setOrdered(false);
	m_stateActivation_Attribute_regionActivations->setContainment(true);
	m_stateActivation_Attribute_regionActivations->setResolveProxies(true);
	m_stateActivation_Attribute_regionActivations->setDefaultValueLiteral("");	
	
	m_stateActivation_Attribute_regionActivations->_setID(STATEACTIVATION_ATTRIBUTE_REGIONACTIVATIONS);
	
	/*
	 * EOperations
	 */
	m_stateActivation_Operation_canDefer_EventOccurrence->setName("canDefer");
	m_stateActivation_Operation_canDefer_EventOccurrence->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_stateActivation_Operation_canDefer_EventOccurrence->setLowerBound(1);
	m_stateActivation_Operation_canDefer_EventOccurrence->setUpperBound(1);
	m_stateActivation_Operation_canDefer_EventOccurrence->setUnique(true);
	m_stateActivation_Operation_canDefer_EventOccurrence->setOrdered(false);
	
	m_stateActivation_Operation_canDefer_EventOccurrence->_setID(STATEACTIVATION_OPERATION_CANDEFER_EVENTOCCURRENCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateActivation_Operation_canDefer_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventOccurrence_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stateActivation_Operation_defer_EventOccurrence->setName("defer");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_stateActivation_Operation_defer_EventOccurrence->setEType(unknownClass);
	}
	m_stateActivation_Operation_defer_EventOccurrence->setLowerBound(1);
	m_stateActivation_Operation_defer_EventOccurrence->setUpperBound(1);
	m_stateActivation_Operation_defer_EventOccurrence->setUnique(true);
	m_stateActivation_Operation_defer_EventOccurrence->setOrdered(false);
	
	m_stateActivation_Operation_defer_EventOccurrence->_setID(STATEACTIVATION_OPERATION_DEFER_EVENTOCCURRENCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateActivation_Operation_defer_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stateActivation_Operation_enter_TransitionActivation_RegionActivation->setName("enter");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_stateActivation_Operation_enter_TransitionActivation_RegionActivation->setEType(unknownClass);
	}
	m_stateActivation_Operation_enter_TransitionActivation_RegionActivation->setLowerBound(0);
	m_stateActivation_Operation_enter_TransitionActivation_RegionActivation->setUpperBound(1);
	m_stateActivation_Operation_enter_TransitionActivation_RegionActivation->setUnique(true);
	m_stateActivation_Operation_enter_TransitionActivation_RegionActivation->setOrdered(true);
	
	m_stateActivation_Operation_enter_TransitionActivation_RegionActivation->_setID(STATEACTIVATION_OPERATION_ENTER_TRANSITIONACTIVATION_REGIONACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateActivation_Operation_enter_TransitionActivation_RegionActivation);
		parameter->setName("enteringTransition");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateActivation_Operation_enter_TransitionActivation_RegionActivation);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateActivation_Operation_enter_TransitionActivation_RegionActivation);
		parameter->setName("leastCommonAncestor");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stateActivation_Operation_enterRegions_TransitionActivation_EventOccurrence->setName("enterRegions");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_stateActivation_Operation_enterRegions_TransitionActivation_EventOccurrence->setEType(unknownClass);
	}
	m_stateActivation_Operation_enterRegions_TransitionActivation_EventOccurrence->setLowerBound(1);
	m_stateActivation_Operation_enterRegions_TransitionActivation_EventOccurrence->setUpperBound(1);
	m_stateActivation_Operation_enterRegions_TransitionActivation_EventOccurrence->setUnique(true);
	m_stateActivation_Operation_enterRegions_TransitionActivation_EventOccurrence->setOrdered(false);
	
	m_stateActivation_Operation_enterRegions_TransitionActivation_EventOccurrence->_setID(STATEACTIVATION_OPERATION_ENTERREGIONS_TRANSITIONACTIVATION_EVENTOCCURRENCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateActivation_Operation_enterRegions_TransitionActivation_EventOccurrence);
		parameter->setName("enteringTransition");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateActivation_Operation_enterRegions_TransitionActivation_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stateActivation_Operation_exit_TransitionActivation_RegionActivation->setName("exit");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_stateActivation_Operation_exit_TransitionActivation_RegionActivation->setEType(unknownClass);
	}
	m_stateActivation_Operation_exit_TransitionActivation_RegionActivation->setLowerBound(0);
	m_stateActivation_Operation_exit_TransitionActivation_RegionActivation->setUpperBound(1);
	m_stateActivation_Operation_exit_TransitionActivation_RegionActivation->setUnique(true);
	m_stateActivation_Operation_exit_TransitionActivation_RegionActivation->setOrdered(true);
	
	m_stateActivation_Operation_exit_TransitionActivation_RegionActivation->_setID(STATEACTIVATION_OPERATION_EXIT_TRANSITIONACTIVATION_REGIONACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateActivation_Operation_exit_TransitionActivation_RegionActivation);
		parameter->setName("exitingTransition");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateActivation_Operation_exit_TransitionActivation_RegionActivation);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateActivation_Operation_exit_TransitionActivation_RegionActivation);
		parameter->setName("leastCommonAncestor");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stateActivation_Operation_getConnectionPointActivation_Vertex->setName("getConnectionPointActivation");
	m_stateActivation_Operation_getConnectionPointActivation_Vertex->setEType(getConnectionPointActivation_Class());
	m_stateActivation_Operation_getConnectionPointActivation_Vertex->setLowerBound(0);
	m_stateActivation_Operation_getConnectionPointActivation_Vertex->setUpperBound(1);
	m_stateActivation_Operation_getConnectionPointActivation_Vertex->setUnique(true);
	m_stateActivation_Operation_getConnectionPointActivation_Vertex->setOrdered(false);
	
	m_stateActivation_Operation_getConnectionPointActivation_Vertex->_setID(STATEACTIVATION_OPERATION_GETCONNECTIONPOINTACTIVATION_VERTEX);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateActivation_Operation_getConnectionPointActivation_Vertex);
		parameter->setName("vertex");
		parameter->setEType(uml::umlPackage::eInstance()->getVertex_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stateActivation_Operation_getDoActivity->setName("getDoActivity");
	m_stateActivation_Operation_getDoActivity->setEType(uml::umlPackage::eInstance()->getBehavior_Class());
	m_stateActivation_Operation_getDoActivity->setLowerBound(1);
	m_stateActivation_Operation_getDoActivity->setUpperBound(1);
	m_stateActivation_Operation_getDoActivity->setUnique(true);
	m_stateActivation_Operation_getDoActivity->setOrdered(false);
	
	m_stateActivation_Operation_getDoActivity->_setID(STATEACTIVATION_OPERATION_GETDOACTIVITY);
	
	
	m_stateActivation_Operation_getEntry->setName("getEntry");
	m_stateActivation_Operation_getEntry->setEType(uml::umlPackage::eInstance()->getBehavior_Class());
	m_stateActivation_Operation_getEntry->setLowerBound(1);
	m_stateActivation_Operation_getEntry->setUpperBound(1);
	m_stateActivation_Operation_getEntry->setUnique(true);
	m_stateActivation_Operation_getEntry->setOrdered(false);
	
	m_stateActivation_Operation_getEntry->_setID(STATEACTIVATION_OPERATION_GETENTRY);
	
	
	m_stateActivation_Operation_getExit->setName("getExit");
	m_stateActivation_Operation_getExit->setEType(uml::umlPackage::eInstance()->getBehavior_Class());
	m_stateActivation_Operation_getExit->setLowerBound(1);
	m_stateActivation_Operation_getExit->setUpperBound(1);
	m_stateActivation_Operation_getExit->setUnique(true);
	m_stateActivation_Operation_getExit->setOrdered(false);
	
	m_stateActivation_Operation_getExit->_setID(STATEACTIVATION_OPERATION_GETEXIT);
	
	
	m_stateActivation_Operation_getFireableTransitions_EventOccurrence->setName("getFireableTransitions");
	m_stateActivation_Operation_getFireableTransitions_EventOccurrence->setEType(getTransitionActivation_Class());
	m_stateActivation_Operation_getFireableTransitions_EventOccurrence->setLowerBound(0);
	m_stateActivation_Operation_getFireableTransitions_EventOccurrence->setUpperBound(-1);
	m_stateActivation_Operation_getFireableTransitions_EventOccurrence->setUnique(true);
	m_stateActivation_Operation_getFireableTransitions_EventOccurrence->setOrdered(false);
	
	m_stateActivation_Operation_getFireableTransitions_EventOccurrence->_setID(STATEACTIVATION_OPERATION_GETFIREABLETRANSITIONS_EVENTOCCURRENCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateActivation_Operation_getFireableTransitions_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventOccurrence_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stateActivation_Operation_getRegionActivation->setName("getRegionActivation");
	m_stateActivation_Operation_getRegionActivation->setEType(getRegionActivation_Class());
	m_stateActivation_Operation_getRegionActivation->setLowerBound(0);
	m_stateActivation_Operation_getRegionActivation->setUpperBound(-1);
	m_stateActivation_Operation_getRegionActivation->setUnique(true);
	m_stateActivation_Operation_getRegionActivation->setOrdered(false);
	
	m_stateActivation_Operation_getRegionActivation->_setID(STATEACTIVATION_OPERATION_GETREGIONACTIVATION);
	
	
	m_stateActivation_Operation_getVertexActivation_Vertex->setName("getVertexActivation");
	m_stateActivation_Operation_getVertexActivation_Vertex->setEType(getVertexActivation_Class());
	m_stateActivation_Operation_getVertexActivation_Vertex->setLowerBound(0);
	m_stateActivation_Operation_getVertexActivation_Vertex->setUpperBound(1);
	m_stateActivation_Operation_getVertexActivation_Vertex->setUnique(true);
	m_stateActivation_Operation_getVertexActivation_Vertex->setOrdered(false);
	
	m_stateActivation_Operation_getVertexActivation_Vertex->_setID(STATEACTIVATION_OPERATION_GETVERTEXACTIVATION_VERTEX);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateActivation_Operation_getVertexActivation_Vertex);
		parameter->setName("vertex");
		parameter->setEType(uml::umlPackage::eInstance()->getVertex_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stateActivation_Operation_hasCompleted->setName("hasCompleted");
	m_stateActivation_Operation_hasCompleted->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_stateActivation_Operation_hasCompleted->setLowerBound(1);
	m_stateActivation_Operation_hasCompleted->setUpperBound(1);
	m_stateActivation_Operation_hasCompleted->setUnique(true);
	m_stateActivation_Operation_hasCompleted->setOrdered(false);
	
	m_stateActivation_Operation_hasCompleted->_setID(STATEACTIVATION_OPERATION_HASCOMPLETED);
	
	
	m_stateActivation_Operation_notifyCompletion->setName("notifyCompletion");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_stateActivation_Operation_notifyCompletion->setEType(unknownClass);
	}
	m_stateActivation_Operation_notifyCompletion->setLowerBound(1);
	m_stateActivation_Operation_notifyCompletion->setUpperBound(1);
	m_stateActivation_Operation_notifyCompletion->setUnique(true);
	m_stateActivation_Operation_notifyCompletion->setOrdered(false);
	
	m_stateActivation_Operation_notifyCompletion->_setID(STATEACTIVATION_OPERATION_NOTIFYCOMPLETION);
	
	
	m_stateActivation_Operation_releaseDeferredEvents->setName("releaseDeferredEvents");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_stateActivation_Operation_releaseDeferredEvents->setEType(unknownClass);
	}
	m_stateActivation_Operation_releaseDeferredEvents->setLowerBound(1);
	m_stateActivation_Operation_releaseDeferredEvents->setUpperBound(1);
	m_stateActivation_Operation_releaseDeferredEvents->setUnique(true);
	m_stateActivation_Operation_releaseDeferredEvents->setOrdered(false);
	
	m_stateActivation_Operation_releaseDeferredEvents->_setID(STATEACTIVATION_OPERATION_RELEASEDEFERREDEVENTS);
	
	
	m_stateActivation_Operation_tryExecuteEntry_EventOccurrence->setName("tryExecuteEntry");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_stateActivation_Operation_tryExecuteEntry_EventOccurrence->setEType(unknownClass);
	}
	m_stateActivation_Operation_tryExecuteEntry_EventOccurrence->setLowerBound(1);
	m_stateActivation_Operation_tryExecuteEntry_EventOccurrence->setUpperBound(1);
	m_stateActivation_Operation_tryExecuteEntry_EventOccurrence->setUnique(true);
	m_stateActivation_Operation_tryExecuteEntry_EventOccurrence->setOrdered(false);
	
	m_stateActivation_Operation_tryExecuteEntry_EventOccurrence->_setID(STATEACTIVATION_OPERATION_TRYEXECUTEENTRY_EVENTOCCURRENCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateActivation_Operation_tryExecuteEntry_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stateActivation_Operation_tryExecuteExit_EventOccurrence->setName("tryExecuteExit");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_stateActivation_Operation_tryExecuteExit_EventOccurrence->setEType(unknownClass);
	}
	m_stateActivation_Operation_tryExecuteExit_EventOccurrence->setLowerBound(1);
	m_stateActivation_Operation_tryExecuteExit_EventOccurrence->setUpperBound(1);
	m_stateActivation_Operation_tryExecuteExit_EventOccurrence->setUnique(true);
	m_stateActivation_Operation_tryExecuteExit_EventOccurrence->setOrdered(false);
	
	m_stateActivation_Operation_tryExecuteExit_EventOccurrence->_setID(STATEACTIVATION_OPERATION_TRYEXECUTEEXIT_EVENTOCCURRENCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateActivation_Operation_tryExecuteExit_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stateActivation_Operation_tryInvokeDoActivity_EventOccurrence->setName("tryInvokeDoActivity");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_stateActivation_Operation_tryInvokeDoActivity_EventOccurrence->setEType(unknownClass);
	}
	m_stateActivation_Operation_tryInvokeDoActivity_EventOccurrence->setLowerBound(1);
	m_stateActivation_Operation_tryInvokeDoActivity_EventOccurrence->setUpperBound(1);
	m_stateActivation_Operation_tryInvokeDoActivity_EventOccurrence->setUnique(true);
	m_stateActivation_Operation_tryInvokeDoActivity_EventOccurrence->setOrdered(false);
	
	m_stateActivation_Operation_tryInvokeDoActivity_EventOccurrence->_setID(STATEACTIVATION_OPERATION_TRYINVOKEDOACTIVITY_EVENTOCCURRENCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateActivation_Operation_tryInvokeDoActivity_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void StateMachinesPackageImpl::initializeStateConfigurationContent()
{
	m_stateConfiguration_Class->setName("StateConfiguration");
	m_stateConfiguration_Class->setAbstract(false);
	m_stateConfiguration_Class->setInterface(false);
	
	m_stateConfiguration_Class->_setID(STATECONFIGURATION_CLASS);
	
	/*
	 * EAttributes
	 */
	m_stateConfiguration_Attribute_level = getStateConfiguration_Attribute_level();
	m_stateConfiguration_Attribute_level->setName("level");
	m_stateConfiguration_Attribute_level->setEType(types::typesPackage::eInstance()->getInteger_Class());
	m_stateConfiguration_Attribute_level->setLowerBound(1);
	m_stateConfiguration_Attribute_level->setUpperBound(1);
	m_stateConfiguration_Attribute_level->setTransient(false);
	m_stateConfiguration_Attribute_level->setVolatile(false);
	m_stateConfiguration_Attribute_level->setChangeable(true);
	m_stateConfiguration_Attribute_level->setUnsettable(false);
	m_stateConfiguration_Attribute_level->setUnique(true);
	m_stateConfiguration_Attribute_level->setDerived(false);
	m_stateConfiguration_Attribute_level->setOrdered(false);
	m_stateConfiguration_Attribute_level->setID(false);
	m_stateConfiguration_Attribute_level->setDefaultValueLiteral("");
	
	m_stateConfiguration_Attribute_level->_setID(STATECONFIGURATION_ATTRIBUTE_LEVEL);
	
	/*
	 * EReferences
	 */
	m_stateConfiguration_Attribute_children->setName("children");
	m_stateConfiguration_Attribute_children->setEType(getStateConfiguration_Class());
	m_stateConfiguration_Attribute_children->setLowerBound(0);
	m_stateConfiguration_Attribute_children->setUpperBound(-1);
	m_stateConfiguration_Attribute_children->setTransient(false);
	m_stateConfiguration_Attribute_children->setVolatile(false);
	m_stateConfiguration_Attribute_children->setChangeable(true);
	m_stateConfiguration_Attribute_children->setUnsettable(false);
	m_stateConfiguration_Attribute_children->setUnique(true);
	m_stateConfiguration_Attribute_children->setDerived(false);
	m_stateConfiguration_Attribute_children->setOrdered(false);
	m_stateConfiguration_Attribute_children->setContainment(true);
	m_stateConfiguration_Attribute_children->setResolveProxies(true);
	m_stateConfiguration_Attribute_children->setDefaultValueLiteral("");	
	
	m_stateConfiguration_Attribute_children->_setID(STATECONFIGURATION_ATTRIBUTE_CHILDREN);
	m_stateConfiguration_Attribute_completeConfiguration->setName("completeConfiguration");
	m_stateConfiguration_Attribute_completeConfiguration->setEType(getStateMachineConfiguration_Class());
	m_stateConfiguration_Attribute_completeConfiguration->setLowerBound(1);
	m_stateConfiguration_Attribute_completeConfiguration->setUpperBound(1);
	m_stateConfiguration_Attribute_completeConfiguration->setTransient(false);
	m_stateConfiguration_Attribute_completeConfiguration->setVolatile(false);
	m_stateConfiguration_Attribute_completeConfiguration->setChangeable(true);
	m_stateConfiguration_Attribute_completeConfiguration->setUnsettable(false);
	m_stateConfiguration_Attribute_completeConfiguration->setUnique(true);
	m_stateConfiguration_Attribute_completeConfiguration->setDerived(false);
	m_stateConfiguration_Attribute_completeConfiguration->setOrdered(false);
	m_stateConfiguration_Attribute_completeConfiguration->setContainment(false);
	m_stateConfiguration_Attribute_completeConfiguration->setResolveProxies(true);
	m_stateConfiguration_Attribute_completeConfiguration->setDefaultValueLiteral("");	
	
	m_stateConfiguration_Attribute_completeConfiguration->_setID(STATECONFIGURATION_ATTRIBUTE_COMPLETECONFIGURATION);
	m_stateConfiguration_Attribute_parent->setName("parent");
	m_stateConfiguration_Attribute_parent->setEType(getStateConfiguration_Class());
	m_stateConfiguration_Attribute_parent->setLowerBound(0);
	m_stateConfiguration_Attribute_parent->setUpperBound(1);
	m_stateConfiguration_Attribute_parent->setTransient(false);
	m_stateConfiguration_Attribute_parent->setVolatile(false);
	m_stateConfiguration_Attribute_parent->setChangeable(true);
	m_stateConfiguration_Attribute_parent->setUnsettable(false);
	m_stateConfiguration_Attribute_parent->setUnique(true);
	m_stateConfiguration_Attribute_parent->setDerived(false);
	m_stateConfiguration_Attribute_parent->setOrdered(false);
	m_stateConfiguration_Attribute_parent->setContainment(false);
	m_stateConfiguration_Attribute_parent->setResolveProxies(true);
	m_stateConfiguration_Attribute_parent->setDefaultValueLiteral("");	
	
	m_stateConfiguration_Attribute_parent->_setID(STATECONFIGURATION_ATTRIBUTE_PARENT);
	m_stateConfiguration_Attribute_vertexActivation->setName("vertexActivation");
	m_stateConfiguration_Attribute_vertexActivation->setEType(getVertexActivation_Class());
	m_stateConfiguration_Attribute_vertexActivation->setLowerBound(1);
	m_stateConfiguration_Attribute_vertexActivation->setUpperBound(1);
	m_stateConfiguration_Attribute_vertexActivation->setTransient(false);
	m_stateConfiguration_Attribute_vertexActivation->setVolatile(false);
	m_stateConfiguration_Attribute_vertexActivation->setChangeable(true);
	m_stateConfiguration_Attribute_vertexActivation->setUnsettable(false);
	m_stateConfiguration_Attribute_vertexActivation->setUnique(true);
	m_stateConfiguration_Attribute_vertexActivation->setDerived(false);
	m_stateConfiguration_Attribute_vertexActivation->setOrdered(false);
	m_stateConfiguration_Attribute_vertexActivation->setContainment(false);
	m_stateConfiguration_Attribute_vertexActivation->setResolveProxies(true);
	m_stateConfiguration_Attribute_vertexActivation->setDefaultValueLiteral("");	
	
	m_stateConfiguration_Attribute_vertexActivation->_setID(STATECONFIGURATION_ATTRIBUTE_VERTEXACTIVATION);
	
	/*
	 * EOperations
	 */
	m_stateConfiguration_Operation_add_VertexActivation_VertexActivation->setName("add");
	m_stateConfiguration_Operation_add_VertexActivation_VertexActivation->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_stateConfiguration_Operation_add_VertexActivation_VertexActivation->setLowerBound(1);
	m_stateConfiguration_Operation_add_VertexActivation_VertexActivation->setUpperBound(1);
	m_stateConfiguration_Operation_add_VertexActivation_VertexActivation->setUnique(true);
	m_stateConfiguration_Operation_add_VertexActivation_VertexActivation->setOrdered(false);
	
	m_stateConfiguration_Operation_add_VertexActivation_VertexActivation->_setID(STATECONFIGURATION_OPERATION_ADD_VERTEXACTIVATION_VERTEXACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateConfiguration_Operation_add_VertexActivation_VertexActivation);
		parameter->setName("activation");
		parameter->setEType(getVertexActivation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateConfiguration_Operation_add_VertexActivation_VertexActivation);
		parameter->setName("context");
		parameter->setEType(getVertexActivation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stateConfiguration_Operation_addChild_VertexActivation->setName("addChild");
	m_stateConfiguration_Operation_addChild_VertexActivation->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_stateConfiguration_Operation_addChild_VertexActivation->setLowerBound(1);
	m_stateConfiguration_Operation_addChild_VertexActivation->setUpperBound(1);
	m_stateConfiguration_Operation_addChild_VertexActivation->setUnique(true);
	m_stateConfiguration_Operation_addChild_VertexActivation->setOrdered(false);
	
	m_stateConfiguration_Operation_addChild_VertexActivation->_setID(STATECONFIGURATION_OPERATION_ADDCHILD_VERTEXACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateConfiguration_Operation_addChild_VertexActivation);
		parameter->setName("activation");
		parameter->setEType(getVertexActivation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stateConfiguration_Operation_getContext_VertexActivation->setName("getContext");
	m_stateConfiguration_Operation_getContext_VertexActivation->setEType(getVertexActivation_Class());
	m_stateConfiguration_Operation_getContext_VertexActivation->setLowerBound(0);
	m_stateConfiguration_Operation_getContext_VertexActivation->setUpperBound(-1);
	m_stateConfiguration_Operation_getContext_VertexActivation->setUnique(true);
	m_stateConfiguration_Operation_getContext_VertexActivation->setOrdered(false);
	
	m_stateConfiguration_Operation_getContext_VertexActivation->_setID(STATECONFIGURATION_OPERATION_GETCONTEXT_VERTEXACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateConfiguration_Operation_getContext_VertexActivation);
		parameter->setName("activation");
		parameter->setEType(getVertexActivation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stateConfiguration_Operation_isActive_VertexActivation->setName("isActive");
	m_stateConfiguration_Operation_isActive_VertexActivation->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_stateConfiguration_Operation_isActive_VertexActivation->setLowerBound(1);
	m_stateConfiguration_Operation_isActive_VertexActivation->setUpperBound(1);
	m_stateConfiguration_Operation_isActive_VertexActivation->setUnique(true);
	m_stateConfiguration_Operation_isActive_VertexActivation->setOrdered(false);
	
	m_stateConfiguration_Operation_isActive_VertexActivation->_setID(STATECONFIGURATION_OPERATION_ISACTIVE_VERTEXACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateConfiguration_Operation_isActive_VertexActivation);
		parameter->setName("activation");
		parameter->setEType(getVertexActivation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stateConfiguration_Operation_remove_VertexActivation_VertexActivation->setName("remove");
	m_stateConfiguration_Operation_remove_VertexActivation_VertexActivation->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_stateConfiguration_Operation_remove_VertexActivation_VertexActivation->setLowerBound(1);
	m_stateConfiguration_Operation_remove_VertexActivation_VertexActivation->setUpperBound(1);
	m_stateConfiguration_Operation_remove_VertexActivation_VertexActivation->setUnique(true);
	m_stateConfiguration_Operation_remove_VertexActivation_VertexActivation->setOrdered(false);
	
	m_stateConfiguration_Operation_remove_VertexActivation_VertexActivation->_setID(STATECONFIGURATION_OPERATION_REMOVE_VERTEXACTIVATION_VERTEXACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateConfiguration_Operation_remove_VertexActivation_VertexActivation);
		parameter->setName("activation");
		parameter->setEType(getVertexActivation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateConfiguration_Operation_remove_VertexActivation_VertexActivation);
		parameter->setName("context");
		parameter->setEType(getVertexActivation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stateConfiguration_Operation_removeChild_VertexActivation->setName("removeChild");
	m_stateConfiguration_Operation_removeChild_VertexActivation->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_stateConfiguration_Operation_removeChild_VertexActivation->setLowerBound(1);
	m_stateConfiguration_Operation_removeChild_VertexActivation->setUpperBound(1);
	m_stateConfiguration_Operation_removeChild_VertexActivation->setUnique(true);
	m_stateConfiguration_Operation_removeChild_VertexActivation->setOrdered(false);
	
	m_stateConfiguration_Operation_removeChild_VertexActivation->_setID(STATECONFIGURATION_OPERATION_REMOVECHILD_VERTEXACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateConfiguration_Operation_removeChild_VertexActivation);
		parameter->setName("activation");
		parameter->setEType(getVertexActivation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void StateMachinesPackageImpl::initializeStateMachineConfigurationContent()
{
	m_stateMachineConfiguration_Class->setName("StateMachineConfiguration");
	m_stateMachineConfiguration_Class->setAbstract(false);
	m_stateMachineConfiguration_Class->setInterface(false);
	
	m_stateMachineConfiguration_Class->_setID(STATEMACHINECONFIGURATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_stateMachineConfiguration_Attribute_execution->setName("execution");
	m_stateMachineConfiguration_Attribute_execution->setEType(getStateMachineExecution_Class());
	m_stateMachineConfiguration_Attribute_execution->setLowerBound(1);
	m_stateMachineConfiguration_Attribute_execution->setUpperBound(1);
	m_stateMachineConfiguration_Attribute_execution->setTransient(false);
	m_stateMachineConfiguration_Attribute_execution->setVolatile(false);
	m_stateMachineConfiguration_Attribute_execution->setChangeable(true);
	m_stateMachineConfiguration_Attribute_execution->setUnsettable(false);
	m_stateMachineConfiguration_Attribute_execution->setUnique(true);
	m_stateMachineConfiguration_Attribute_execution->setDerived(false);
	m_stateMachineConfiguration_Attribute_execution->setOrdered(false);
	m_stateMachineConfiguration_Attribute_execution->setContainment(false);
	m_stateMachineConfiguration_Attribute_execution->setResolveProxies(true);
	m_stateMachineConfiguration_Attribute_execution->setDefaultValueLiteral("");	
	m_stateMachineConfiguration_Attribute_execution->setEOpposite(PSSM::Semantics::StateMachines::StateMachinesPackage::eInstance()->getStateMachineExecution_Attribute_configuration());
	
	m_stateMachineConfiguration_Attribute_execution->_setID(STATEMACHINECONFIGURATION_ATTRIBUTE_EXECUTION);
	m_stateMachineConfiguration_Attribute_rootConfiguration->setName("rootConfiguration");
	m_stateMachineConfiguration_Attribute_rootConfiguration->setEType(getStateConfiguration_Class());
	m_stateMachineConfiguration_Attribute_rootConfiguration->setLowerBound(1);
	m_stateMachineConfiguration_Attribute_rootConfiguration->setUpperBound(1);
	m_stateMachineConfiguration_Attribute_rootConfiguration->setTransient(false);
	m_stateMachineConfiguration_Attribute_rootConfiguration->setVolatile(false);
	m_stateMachineConfiguration_Attribute_rootConfiguration->setChangeable(true);
	m_stateMachineConfiguration_Attribute_rootConfiguration->setUnsettable(false);
	m_stateMachineConfiguration_Attribute_rootConfiguration->setUnique(true);
	m_stateMachineConfiguration_Attribute_rootConfiguration->setDerived(false);
	m_stateMachineConfiguration_Attribute_rootConfiguration->setOrdered(false);
	m_stateMachineConfiguration_Attribute_rootConfiguration->setContainment(false);
	m_stateMachineConfiguration_Attribute_rootConfiguration->setResolveProxies(true);
	m_stateMachineConfiguration_Attribute_rootConfiguration->setDefaultValueLiteral("");	
	
	m_stateMachineConfiguration_Attribute_rootConfiguration->_setID(STATEMACHINECONFIGURATION_ATTRIBUTE_ROOTCONFIGURATION);
	
	/*
	 * EOperations
	 */
	m_stateMachineConfiguration_Operation__register_StateActivation->setName("_register");
	m_stateMachineConfiguration_Operation__register_StateActivation->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_stateMachineConfiguration_Operation__register_StateActivation->setLowerBound(1);
	m_stateMachineConfiguration_Operation__register_StateActivation->setUpperBound(1);
	m_stateMachineConfiguration_Operation__register_StateActivation->setUnique(true);
	m_stateMachineConfiguration_Operation__register_StateActivation->setOrdered(false);
	
	m_stateMachineConfiguration_Operation__register_StateActivation->_setID(STATEMACHINECONFIGURATION_OPERATION__REGISTER_STATEACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateMachineConfiguration_Operation__register_StateActivation);
		parameter->setName("stateActivation");
		parameter->setEType(getStateActivation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stateMachineConfiguration_Operation_add_VertexActivation->setName("add");
	m_stateMachineConfiguration_Operation_add_VertexActivation->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_stateMachineConfiguration_Operation_add_VertexActivation->setLowerBound(1);
	m_stateMachineConfiguration_Operation_add_VertexActivation->setUpperBound(1);
	m_stateMachineConfiguration_Operation_add_VertexActivation->setUnique(true);
	m_stateMachineConfiguration_Operation_add_VertexActivation->setOrdered(false);
	
	m_stateMachineConfiguration_Operation_add_VertexActivation->_setID(STATEMACHINECONFIGURATION_OPERATION_ADD_VERTEXACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateMachineConfiguration_Operation_add_VertexActivation);
		parameter->setName("activation");
		parameter->setEType(getVertexActivation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stateMachineConfiguration_Operation_getVertexActivationsAtLevel_Integer->setName("getVertexActivationsAtLevel");
	m_stateMachineConfiguration_Operation_getVertexActivationsAtLevel_Integer->setEType(getVertexActivation_Class());
	m_stateMachineConfiguration_Operation_getVertexActivationsAtLevel_Integer->setLowerBound(0);
	m_stateMachineConfiguration_Operation_getVertexActivationsAtLevel_Integer->setUpperBound(-1);
	m_stateMachineConfiguration_Operation_getVertexActivationsAtLevel_Integer->setUnique(true);
	m_stateMachineConfiguration_Operation_getVertexActivationsAtLevel_Integer->setOrdered(false);
	
	m_stateMachineConfiguration_Operation_getVertexActivationsAtLevel_Integer->_setID(STATEMACHINECONFIGURATION_OPERATION_GETVERTEXACTIVATIONSATLEVEL_INTEGER);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateMachineConfiguration_Operation_getVertexActivationsAtLevel_Integer);
		parameter->setName("level");
		parameter->setEType(types::typesPackage::eInstance()->getInteger_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stateMachineConfiguration_Operation_isActive_VertexActivation->setName("isActive");
	m_stateMachineConfiguration_Operation_isActive_VertexActivation->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_stateMachineConfiguration_Operation_isActive_VertexActivation->setLowerBound(1);
	m_stateMachineConfiguration_Operation_isActive_VertexActivation->setUpperBound(1);
	m_stateMachineConfiguration_Operation_isActive_VertexActivation->setUnique(true);
	m_stateMachineConfiguration_Operation_isActive_VertexActivation->setOrdered(false);
	
	m_stateMachineConfiguration_Operation_isActive_VertexActivation->_setID(STATEMACHINECONFIGURATION_OPERATION_ISACTIVE_VERTEXACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateMachineConfiguration_Operation_isActive_VertexActivation);
		parameter->setName("activation");
		parameter->setEType(getVertexActivation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stateMachineConfiguration_Operation_isStable->setName("isStable");
	m_stateMachineConfiguration_Operation_isStable->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_stateMachineConfiguration_Operation_isStable->setLowerBound(1);
	m_stateMachineConfiguration_Operation_isStable->setUpperBound(1);
	m_stateMachineConfiguration_Operation_isStable->setUnique(true);
	m_stateMachineConfiguration_Operation_isStable->setOrdered(false);
	
	m_stateMachineConfiguration_Operation_isStable->_setID(STATEMACHINECONFIGURATION_OPERATION_ISSTABLE);
	
	
	m_stateMachineConfiguration_Operation_remove_VertexActivation->setName("remove");
	m_stateMachineConfiguration_Operation_remove_VertexActivation->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_stateMachineConfiguration_Operation_remove_VertexActivation->setLowerBound(1);
	m_stateMachineConfiguration_Operation_remove_VertexActivation->setUpperBound(1);
	m_stateMachineConfiguration_Operation_remove_VertexActivation->setUnique(true);
	m_stateMachineConfiguration_Operation_remove_VertexActivation->setOrdered(false);
	
	m_stateMachineConfiguration_Operation_remove_VertexActivation->_setID(STATEMACHINECONFIGURATION_OPERATION_REMOVE_VERTEXACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateMachineConfiguration_Operation_remove_VertexActivation);
		parameter->setName("vertexActivation");
		parameter->setEType(getVertexActivation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stateMachineConfiguration_Operation_unregister_StateActivation->setName("unregister");
	m_stateMachineConfiguration_Operation_unregister_StateActivation->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_stateMachineConfiguration_Operation_unregister_StateActivation->setLowerBound(1);
	m_stateMachineConfiguration_Operation_unregister_StateActivation->setUpperBound(1);
	m_stateMachineConfiguration_Operation_unregister_StateActivation->setUnique(true);
	m_stateMachineConfiguration_Operation_unregister_StateActivation->setOrdered(false);
	
	m_stateMachineConfiguration_Operation_unregister_StateActivation->_setID(STATEMACHINECONFIGURATION_OPERATION_UNREGISTER_STATEACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateMachineConfiguration_Operation_unregister_StateActivation);
		parameter->setName("stateActivation");
		parameter->setEType(getStateActivation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void StateMachinesPackageImpl::initializeStateMachineEventAccepterContent()
{
	m_stateMachineEventAccepter_Class->setName("StateMachineEventAccepter");
	m_stateMachineEventAccepter_Class->setAbstract(false);
	m_stateMachineEventAccepter_Class->setInterface(false);
	
	m_stateMachineEventAccepter_Class->_setID(STATEMACHINEEVENTACCEPTER_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_stateMachineEventAccepter_Attribute_registrationContext->setName("registrationContext");
	m_stateMachineEventAccepter_Attribute_registrationContext->setEType(getStateMachineExecution_Class());
	m_stateMachineEventAccepter_Attribute_registrationContext->setLowerBound(1);
	m_stateMachineEventAccepter_Attribute_registrationContext->setUpperBound(1);
	m_stateMachineEventAccepter_Attribute_registrationContext->setTransient(false);
	m_stateMachineEventAccepter_Attribute_registrationContext->setVolatile(false);
	m_stateMachineEventAccepter_Attribute_registrationContext->setChangeable(true);
	m_stateMachineEventAccepter_Attribute_registrationContext->setUnsettable(false);
	m_stateMachineEventAccepter_Attribute_registrationContext->setUnique(true);
	m_stateMachineEventAccepter_Attribute_registrationContext->setDerived(false);
	m_stateMachineEventAccepter_Attribute_registrationContext->setOrdered(false);
	m_stateMachineEventAccepter_Attribute_registrationContext->setContainment(false);
	m_stateMachineEventAccepter_Attribute_registrationContext->setResolveProxies(true);
	m_stateMachineEventAccepter_Attribute_registrationContext->setDefaultValueLiteral("");	
	
	m_stateMachineEventAccepter_Attribute_registrationContext->_setID(STATEMACHINEEVENTACCEPTER_ATTRIBUTE_REGISTRATIONCONTEXT);
	
	/*
	 * EOperations
	 */
	m_stateMachineEventAccepter_Operation__defer_EventOccurrence_StateConfiguration->setName("_defer");
	m_stateMachineEventAccepter_Operation__defer_EventOccurrence_StateConfiguration->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_stateMachineEventAccepter_Operation__defer_EventOccurrence_StateConfiguration->setLowerBound(1);
	m_stateMachineEventAccepter_Operation__defer_EventOccurrence_StateConfiguration->setUpperBound(1);
	m_stateMachineEventAccepter_Operation__defer_EventOccurrence_StateConfiguration->setUnique(true);
	m_stateMachineEventAccepter_Operation__defer_EventOccurrence_StateConfiguration->setOrdered(false);
	
	m_stateMachineEventAccepter_Operation__defer_EventOccurrence_StateConfiguration->_setID(STATEMACHINEEVENTACCEPTER_OPERATION__DEFER_EVENTOCCURRENCE_STATECONFIGURATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateMachineEventAccepter_Operation__defer_EventOccurrence_StateConfiguration);
		parameter->setName("eventOccurrence");
		parameter->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventOccurrence_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateMachineEventAccepter_Operation__defer_EventOccurrence_StateConfiguration);
		parameter->setName("stateConfiguration");
		parameter->setEType(getStateConfiguration_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stateMachineEventAccepter_Operation__isDeferred_EventOccurrence_StateConfiguration->setName("_isDeferred");
	m_stateMachineEventAccepter_Operation__isDeferred_EventOccurrence_StateConfiguration->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_stateMachineEventAccepter_Operation__isDeferred_EventOccurrence_StateConfiguration->setLowerBound(1);
	m_stateMachineEventAccepter_Operation__isDeferred_EventOccurrence_StateConfiguration->setUpperBound(1);
	m_stateMachineEventAccepter_Operation__isDeferred_EventOccurrence_StateConfiguration->setUnique(true);
	m_stateMachineEventAccepter_Operation__isDeferred_EventOccurrence_StateConfiguration->setOrdered(false);
	
	m_stateMachineEventAccepter_Operation__isDeferred_EventOccurrence_StateConfiguration->_setID(STATEMACHINEEVENTACCEPTER_OPERATION__ISDEFERRED_EVENTOCCURRENCE_STATECONFIGURATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateMachineEventAccepter_Operation__isDeferred_EventOccurrence_StateConfiguration);
		parameter->setName("eventOccurrence");
		parameter->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventOccurrence_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateMachineEventAccepter_Operation__isDeferred_EventOccurrence_StateConfiguration);
		parameter->setName("stateConfiguration");
		parameter->setEType(getStateConfiguration_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stateMachineEventAccepter_Operation__select_EventOccurrence_StateConfiguration->setName("_select");
	m_stateMachineEventAccepter_Operation__select_EventOccurrence_StateConfiguration->setEType(getTransitionActivation_Class());
	m_stateMachineEventAccepter_Operation__select_EventOccurrence_StateConfiguration->setLowerBound(0);
	m_stateMachineEventAccepter_Operation__select_EventOccurrence_StateConfiguration->setUpperBound(-1);
	m_stateMachineEventAccepter_Operation__select_EventOccurrence_StateConfiguration->setUnique(true);
	m_stateMachineEventAccepter_Operation__select_EventOccurrence_StateConfiguration->setOrdered(false);
	
	m_stateMachineEventAccepter_Operation__select_EventOccurrence_StateConfiguration->_setID(STATEMACHINEEVENTACCEPTER_OPERATION__SELECT_EVENTOCCURRENCE_STATECONFIGURATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateMachineEventAccepter_Operation__select_EventOccurrence_StateConfiguration);
		parameter->setName("eventOccurrence");
		parameter->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventOccurrence_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateMachineEventAccepter_Operation__select_EventOccurrence_StateConfiguration);
		parameter->setName("stateConfiguration");
		parameter->setEType(getStateConfiguration_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stateMachineEventAccepter_Operation_accept_EventOccurrence->setName("accept");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_stateMachineEventAccepter_Operation_accept_EventOccurrence->setEType(unknownClass);
	}
	m_stateMachineEventAccepter_Operation_accept_EventOccurrence->setLowerBound(1);
	m_stateMachineEventAccepter_Operation_accept_EventOccurrence->setUpperBound(1);
	m_stateMachineEventAccepter_Operation_accept_EventOccurrence->setUnique(true);
	m_stateMachineEventAccepter_Operation_accept_EventOccurrence->setOrdered(false);
	
	m_stateMachineEventAccepter_Operation_accept_EventOccurrence->_setID(STATEMACHINEEVENTACCEPTER_OPERATION_ACCEPT_EVENTOCCURRENCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateMachineEventAccepter_Operation_accept_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stateMachineEventAccepter_Operation_defer_EventOccurrence->setName("defer");
	m_stateMachineEventAccepter_Operation_defer_EventOccurrence->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_stateMachineEventAccepter_Operation_defer_EventOccurrence->setLowerBound(1);
	m_stateMachineEventAccepter_Operation_defer_EventOccurrence->setUpperBound(1);
	m_stateMachineEventAccepter_Operation_defer_EventOccurrence->setUnique(true);
	m_stateMachineEventAccepter_Operation_defer_EventOccurrence->setOrdered(false);
	
	m_stateMachineEventAccepter_Operation_defer_EventOccurrence->_setID(STATEMACHINEEVENTACCEPTER_OPERATION_DEFER_EVENTOCCURRENCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateMachineEventAccepter_Operation_defer_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventOccurrence_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stateMachineEventAccepter_Operation_isDeferred_EventOccurrence->setName("isDeferred");
	m_stateMachineEventAccepter_Operation_isDeferred_EventOccurrence->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_stateMachineEventAccepter_Operation_isDeferred_EventOccurrence->setLowerBound(1);
	m_stateMachineEventAccepter_Operation_isDeferred_EventOccurrence->setUpperBound(1);
	m_stateMachineEventAccepter_Operation_isDeferred_EventOccurrence->setUnique(true);
	m_stateMachineEventAccepter_Operation_isDeferred_EventOccurrence->setOrdered(false);
	
	m_stateMachineEventAccepter_Operation_isDeferred_EventOccurrence->_setID(STATEMACHINEEVENTACCEPTER_OPERATION_ISDEFERRED_EVENTOCCURRENCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateMachineEventAccepter_Operation_isDeferred_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventOccurrence_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stateMachineEventAccepter_Operation_isTriggering_EventOccurrence->setName("isTriggering");
	m_stateMachineEventAccepter_Operation_isTriggering_EventOccurrence->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_stateMachineEventAccepter_Operation_isTriggering_EventOccurrence->setLowerBound(1);
	m_stateMachineEventAccepter_Operation_isTriggering_EventOccurrence->setUpperBound(1);
	m_stateMachineEventAccepter_Operation_isTriggering_EventOccurrence->setUnique(true);
	m_stateMachineEventAccepter_Operation_isTriggering_EventOccurrence->setOrdered(false);
	
	m_stateMachineEventAccepter_Operation_isTriggering_EventOccurrence->_setID(STATEMACHINEEVENTACCEPTER_OPERATION_ISTRIGGERING_EVENTOCCURRENCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateMachineEventAccepter_Operation_isTriggering_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventOccurrence_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stateMachineEventAccepter_Operation_match_EventOccurrence->setName("match");
	m_stateMachineEventAccepter_Operation_match_EventOccurrence->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_stateMachineEventAccepter_Operation_match_EventOccurrence->setLowerBound(1);
	m_stateMachineEventAccepter_Operation_match_EventOccurrence->setUpperBound(1);
	m_stateMachineEventAccepter_Operation_match_EventOccurrence->setUnique(true);
	m_stateMachineEventAccepter_Operation_match_EventOccurrence->setOrdered(false);
	
	m_stateMachineEventAccepter_Operation_match_EventOccurrence->_setID(STATEMACHINEEVENTACCEPTER_OPERATION_MATCH_EVENTOCCURRENCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateMachineEventAccepter_Operation_match_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventOccurrence_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stateMachineEventAccepter_Operation_select_EventOccurrence->setName("select");
	m_stateMachineEventAccepter_Operation_select_EventOccurrence->setEType(getTransitionActivation_Class());
	m_stateMachineEventAccepter_Operation_select_EventOccurrence->setLowerBound(0);
	m_stateMachineEventAccepter_Operation_select_EventOccurrence->setUpperBound(-1);
	m_stateMachineEventAccepter_Operation_select_EventOccurrence->setUnique(true);
	m_stateMachineEventAccepter_Operation_select_EventOccurrence->setOrdered(false);
	
	m_stateMachineEventAccepter_Operation_select_EventOccurrence->_setID(STATEMACHINEEVENTACCEPTER_OPERATION_SELECT_EVENTOCCURRENCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateMachineEventAccepter_Operation_select_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventOccurrence_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void StateMachinesPackageImpl::initializeStateMachineExecutionContent()
{
	m_stateMachineExecution_Class->setName("StateMachineExecution");
	m_stateMachineExecution_Class->setAbstract(false);
	m_stateMachineExecution_Class->setInterface(false);
	
	m_stateMachineExecution_Class->_setID(STATEMACHINEEXECUTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_stateMachineExecution_Attribute_conditionVariable->setName("conditionVariable");
	{
		std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_stateMachineExecution_Attribute_conditionVariable->setEType(unknownClass);
	}
	m_stateMachineExecution_Attribute_conditionVariable->setLowerBound(1);
	m_stateMachineExecution_Attribute_conditionVariable->setUpperBound(1);
	m_stateMachineExecution_Attribute_conditionVariable->setTransient(false);
	m_stateMachineExecution_Attribute_conditionVariable->setVolatile(false);
	m_stateMachineExecution_Attribute_conditionVariable->setChangeable(true);
	m_stateMachineExecution_Attribute_conditionVariable->setUnsettable(false);
	m_stateMachineExecution_Attribute_conditionVariable->setUnique(true);
	m_stateMachineExecution_Attribute_conditionVariable->setDerived(false);
	m_stateMachineExecution_Attribute_conditionVariable->setOrdered(true);
	m_stateMachineExecution_Attribute_conditionVariable->setContainment(false);
	m_stateMachineExecution_Attribute_conditionVariable->setResolveProxies(true);
	m_stateMachineExecution_Attribute_conditionVariable->setDefaultValueLiteral("");	
	
	m_stateMachineExecution_Attribute_conditionVariable->_setID(STATEMACHINEEXECUTION_ATTRIBUTE_CONDITIONVARIABLE);
	m_stateMachineExecution_Attribute_configuration->setName("configuration");
	m_stateMachineExecution_Attribute_configuration->setEType(getStateMachineConfiguration_Class());
	m_stateMachineExecution_Attribute_configuration->setLowerBound(1);
	m_stateMachineExecution_Attribute_configuration->setUpperBound(1);
	m_stateMachineExecution_Attribute_configuration->setTransient(false);
	m_stateMachineExecution_Attribute_configuration->setVolatile(false);
	m_stateMachineExecution_Attribute_configuration->setChangeable(true);
	m_stateMachineExecution_Attribute_configuration->setUnsettable(false);
	m_stateMachineExecution_Attribute_configuration->setUnique(true);
	m_stateMachineExecution_Attribute_configuration->setDerived(false);
	m_stateMachineExecution_Attribute_configuration->setOrdered(false);
	m_stateMachineExecution_Attribute_configuration->setContainment(true);
	m_stateMachineExecution_Attribute_configuration->setResolveProxies(true);
	m_stateMachineExecution_Attribute_configuration->setDefaultValueLiteral("");	
	m_stateMachineExecution_Attribute_configuration->setEOpposite(PSSM::Semantics::StateMachines::StateMachinesPackage::eInstance()->getStateMachineConfiguration_Attribute_execution());
	
	m_stateMachineExecution_Attribute_configuration->_setID(STATEMACHINEEXECUTION_ATTRIBUTE_CONFIGURATION);
	m_stateMachineExecution_Attribute_mutex->setName("mutex");
	{
		std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_stateMachineExecution_Attribute_mutex->setEType(unknownClass);
	}
	m_stateMachineExecution_Attribute_mutex->setLowerBound(1);
	m_stateMachineExecution_Attribute_mutex->setUpperBound(1);
	m_stateMachineExecution_Attribute_mutex->setTransient(false);
	m_stateMachineExecution_Attribute_mutex->setVolatile(false);
	m_stateMachineExecution_Attribute_mutex->setChangeable(true);
	m_stateMachineExecution_Attribute_mutex->setUnsettable(false);
	m_stateMachineExecution_Attribute_mutex->setUnique(true);
	m_stateMachineExecution_Attribute_mutex->setDerived(false);
	m_stateMachineExecution_Attribute_mutex->setOrdered(true);
	m_stateMachineExecution_Attribute_mutex->setContainment(false);
	m_stateMachineExecution_Attribute_mutex->setResolveProxies(true);
	m_stateMachineExecution_Attribute_mutex->setDefaultValueLiteral("");	
	
	m_stateMachineExecution_Attribute_mutex->_setID(STATEMACHINEEXECUTION_ATTRIBUTE_MUTEX);
	m_stateMachineExecution_Attribute_regionActivations->setName("regionActivations");
	m_stateMachineExecution_Attribute_regionActivations->setEType(getRegionActivation_Class());
	m_stateMachineExecution_Attribute_regionActivations->setLowerBound(1);
	m_stateMachineExecution_Attribute_regionActivations->setUpperBound(-1);
	m_stateMachineExecution_Attribute_regionActivations->setTransient(false);
	m_stateMachineExecution_Attribute_regionActivations->setVolatile(false);
	m_stateMachineExecution_Attribute_regionActivations->setChangeable(true);
	m_stateMachineExecution_Attribute_regionActivations->setUnsettable(false);
	m_stateMachineExecution_Attribute_regionActivations->setUnique(true);
	m_stateMachineExecution_Attribute_regionActivations->setDerived(false);
	m_stateMachineExecution_Attribute_regionActivations->setOrdered(false);
	m_stateMachineExecution_Attribute_regionActivations->setContainment(true);
	m_stateMachineExecution_Attribute_regionActivations->setResolveProxies(true);
	m_stateMachineExecution_Attribute_regionActivations->setDefaultValueLiteral("");	
	
	m_stateMachineExecution_Attribute_regionActivations->_setID(STATEMACHINEEXECUTION_ATTRIBUTE_REGIONACTIVATIONS);
	
	/*
	 * EOperations
	 */
	m_stateMachineExecution_Operation_execute->setName("execute");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_stateMachineExecution_Operation_execute->setEType(unknownClass);
	}
	m_stateMachineExecution_Operation_execute->setLowerBound(1);
	m_stateMachineExecution_Operation_execute->setUpperBound(1);
	m_stateMachineExecution_Operation_execute->setUnique(true);
	m_stateMachineExecution_Operation_execute->setOrdered(false);
	
	m_stateMachineExecution_Operation_execute->_setID(STATEMACHINEEXECUTION_OPERATION_EXECUTE);
	
	
	m_stateMachineExecution_Operation_getVertexActivation_Vertex->setName("getVertexActivation");
	m_stateMachineExecution_Operation_getVertexActivation_Vertex->setEType(getVertexActivation_Class());
	m_stateMachineExecution_Operation_getVertexActivation_Vertex->setLowerBound(1);
	m_stateMachineExecution_Operation_getVertexActivation_Vertex->setUpperBound(1);
	m_stateMachineExecution_Operation_getVertexActivation_Vertex->setUnique(true);
	m_stateMachineExecution_Operation_getVertexActivation_Vertex->setOrdered(false);
	
	m_stateMachineExecution_Operation_getVertexActivation_Vertex->_setID(STATEMACHINEEXECUTION_OPERATION_GETVERTEXACTIVATION_VERTEX);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateMachineExecution_Operation_getVertexActivation_Vertex);
		parameter->setName("vertex");
		parameter->setEType(uml::umlPackage::eInstance()->getVertex_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stateMachineExecution_Operation_startBehavior_Class_ParameterValue->setName("startBehavior");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_stateMachineExecution_Operation_startBehavior_Class_ParameterValue->setEType(unknownClass);
	}
	m_stateMachineExecution_Operation_startBehavior_Class_ParameterValue->setLowerBound(1);
	m_stateMachineExecution_Operation_startBehavior_Class_ParameterValue->setUpperBound(1);
	m_stateMachineExecution_Operation_startBehavior_Class_ParameterValue->setUnique(true);
	m_stateMachineExecution_Operation_startBehavior_Class_ParameterValue->setOrdered(false);
	
	m_stateMachineExecution_Operation_startBehavior_Class_ParameterValue->_setID(STATEMACHINEEXECUTION_OPERATION_STARTBEHAVIOR_CLASS_PARAMETERVALUE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateMachineExecution_Operation_startBehavior_Class_ParameterValue);
		parameter->setName("classifier");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateMachineExecution_Operation_startBehavior_Class_ParameterValue);
		parameter->setName("inputs");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stateMachineExecution_Operation_terminate->setName("terminate");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_stateMachineExecution_Operation_terminate->setEType(unknownClass);
	}
	m_stateMachineExecution_Operation_terminate->setLowerBound(1);
	m_stateMachineExecution_Operation_terminate->setUpperBound(1);
	m_stateMachineExecution_Operation_terminate->setUnique(true);
	m_stateMachineExecution_Operation_terminate->setOrdered(false);
	
	m_stateMachineExecution_Operation_terminate->_setID(STATEMACHINEEXECUTION_OPERATION_TERMINATE);
	
	
	
}

void StateMachinesPackageImpl::initializeStateMachineSemanticVisitorContent()
{
	m_stateMachineSemanticVisitor_Class->setName("StateMachineSemanticVisitor");
	m_stateMachineSemanticVisitor_Class->setAbstract(true);
	m_stateMachineSemanticVisitor_Class->setInterface(false);
	
	m_stateMachineSemanticVisitor_Class->_setID(STATEMACHINESEMANTICVISITOR_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_stateMachineSemanticVisitor_Attribute_node->setName("node");
	m_stateMachineSemanticVisitor_Attribute_node->setEType(uml::umlPackage::eInstance()->getNamedElement_Class());
	m_stateMachineSemanticVisitor_Attribute_node->setLowerBound(1);
	m_stateMachineSemanticVisitor_Attribute_node->setUpperBound(1);
	m_stateMachineSemanticVisitor_Attribute_node->setTransient(false);
	m_stateMachineSemanticVisitor_Attribute_node->setVolatile(false);
	m_stateMachineSemanticVisitor_Attribute_node->setChangeable(true);
	m_stateMachineSemanticVisitor_Attribute_node->setUnsettable(false);
	m_stateMachineSemanticVisitor_Attribute_node->setUnique(true);
	m_stateMachineSemanticVisitor_Attribute_node->setDerived(false);
	m_stateMachineSemanticVisitor_Attribute_node->setOrdered(false);
	m_stateMachineSemanticVisitor_Attribute_node->setContainment(false);
	m_stateMachineSemanticVisitor_Attribute_node->setResolveProxies(true);
	m_stateMachineSemanticVisitor_Attribute_node->setDefaultValueLiteral("");	
	
	m_stateMachineSemanticVisitor_Attribute_node->_setID(STATEMACHINESEMANTICVISITOR_ATTRIBUTE_NODE);
	m_stateMachineSemanticVisitor_Attribute_parent->setName("parent");
	m_stateMachineSemanticVisitor_Attribute_parent->setEType(fUML::Semantics::Loci::LociPackage::eInstance()->getSemanticVisitor_Class());
	m_stateMachineSemanticVisitor_Attribute_parent->setLowerBound(0);
	m_stateMachineSemanticVisitor_Attribute_parent->setUpperBound(1);
	m_stateMachineSemanticVisitor_Attribute_parent->setTransient(false);
	m_stateMachineSemanticVisitor_Attribute_parent->setVolatile(false);
	m_stateMachineSemanticVisitor_Attribute_parent->setChangeable(true);
	m_stateMachineSemanticVisitor_Attribute_parent->setUnsettable(false);
	m_stateMachineSemanticVisitor_Attribute_parent->setUnique(true);
	m_stateMachineSemanticVisitor_Attribute_parent->setDerived(false);
	m_stateMachineSemanticVisitor_Attribute_parent->setOrdered(false);
	m_stateMachineSemanticVisitor_Attribute_parent->setContainment(false);
	m_stateMachineSemanticVisitor_Attribute_parent->setResolveProxies(true);
	m_stateMachineSemanticVisitor_Attribute_parent->setDefaultValueLiteral("");	
	
	m_stateMachineSemanticVisitor_Attribute_parent->_setID(STATEMACHINESEMANTICVISITOR_ATTRIBUTE_PARENT);
	
	/*
	 * EOperations
	 */
	m_stateMachineSemanticVisitor_Operation_activate->setName("activate");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_stateMachineSemanticVisitor_Operation_activate->setEType(unknownClass);
	}
	m_stateMachineSemanticVisitor_Operation_activate->setLowerBound(1);
	m_stateMachineSemanticVisitor_Operation_activate->setUpperBound(1);
	m_stateMachineSemanticVisitor_Operation_activate->setUnique(true);
	m_stateMachineSemanticVisitor_Operation_activate->setOrdered(false);
	
	m_stateMachineSemanticVisitor_Operation_activate->_setID(STATEMACHINESEMANTICVISITOR_OPERATION_ACTIVATE);
	
	
	m_stateMachineSemanticVisitor_Operation_activateTransitions->setName("activateTransitions");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_stateMachineSemanticVisitor_Operation_activateTransitions->setEType(unknownClass);
	}
	m_stateMachineSemanticVisitor_Operation_activateTransitions->setLowerBound(1);
	m_stateMachineSemanticVisitor_Operation_activateTransitions->setUpperBound(1);
	m_stateMachineSemanticVisitor_Operation_activateTransitions->setUnique(true);
	m_stateMachineSemanticVisitor_Operation_activateTransitions->setOrdered(false);
	
	m_stateMachineSemanticVisitor_Operation_activateTransitions->_setID(STATEMACHINESEMANTICVISITOR_OPERATION_ACTIVATETRANSITIONS);
	
	
	m_stateMachineSemanticVisitor_Operation_getContextChain->setName("getContextChain");
	m_stateMachineSemanticVisitor_Operation_getContextChain->setEType(fUML::Semantics::Loci::LociPackage::eInstance()->getSemanticVisitor_Class());
	m_stateMachineSemanticVisitor_Operation_getContextChain->setLowerBound(0);
	m_stateMachineSemanticVisitor_Operation_getContextChain->setUpperBound(-1);
	m_stateMachineSemanticVisitor_Operation_getContextChain->setUnique(true);
	m_stateMachineSemanticVisitor_Operation_getContextChain->setOrdered(false);
	
	m_stateMachineSemanticVisitor_Operation_getContextChain->_setID(STATEMACHINESEMANTICVISITOR_OPERATION_GETCONTEXTCHAIN);
	
	
	m_stateMachineSemanticVisitor_Operation_getExecutionContext->setName("getExecutionContext");
	m_stateMachineSemanticVisitor_Operation_getExecutionContext->setEType(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_Object_Class());
	m_stateMachineSemanticVisitor_Operation_getExecutionContext->setLowerBound(1);
	m_stateMachineSemanticVisitor_Operation_getExecutionContext->setUpperBound(1);
	m_stateMachineSemanticVisitor_Operation_getExecutionContext->setUnique(true);
	m_stateMachineSemanticVisitor_Operation_getExecutionContext->setOrdered(false);
	
	m_stateMachineSemanticVisitor_Operation_getExecutionContext->_setID(STATEMACHINESEMANTICVISITOR_OPERATION_GETEXECUTIONCONTEXT);
	
	
	m_stateMachineSemanticVisitor_Operation_getExecutionFor_Behavior_FUML_Object->setName("getExecutionFor");
	m_stateMachineSemanticVisitor_Operation_getExecutionFor_Behavior_FUML_Object->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getExecution_Class());
	m_stateMachineSemanticVisitor_Operation_getExecutionFor_Behavior_FUML_Object->setLowerBound(1);
	m_stateMachineSemanticVisitor_Operation_getExecutionFor_Behavior_FUML_Object->setUpperBound(1);
	m_stateMachineSemanticVisitor_Operation_getExecutionFor_Behavior_FUML_Object->setUnique(true);
	m_stateMachineSemanticVisitor_Operation_getExecutionFor_Behavior_FUML_Object->setOrdered(false);
	
	m_stateMachineSemanticVisitor_Operation_getExecutionFor_Behavior_FUML_Object->_setID(STATEMACHINESEMANTICVISITOR_OPERATION_GETEXECUTIONFOR_BEHAVIOR_FUML_OBJECT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateMachineSemanticVisitor_Operation_getExecutionFor_Behavior_FUML_Object);
		parameter->setName("behavior");
		parameter->setEType(uml::umlPackage::eInstance()->getBehavior_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateMachineSemanticVisitor_Operation_getExecutionFor_Behavior_FUML_Object);
		parameter->setName("eventOccurrence");
		parameter->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventOccurrence_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateMachineSemanticVisitor_Operation_getExecutionFor_Behavior_FUML_Object);
		parameter->setName("context");
		parameter->setEType(fUML::MDE4CPP_Extensions::MDE4CPP_ExtensionsPackage::eInstance()->getFUML_Object_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stateMachineSemanticVisitor_Operation_getExecutionLocus->setName("getExecutionLocus");
	m_stateMachineSemanticVisitor_Operation_getExecutionLocus->setEType(fUML::Semantics::Loci::LociPackage::eInstance()->getLocus_Class());
	m_stateMachineSemanticVisitor_Operation_getExecutionLocus->setLowerBound(1);
	m_stateMachineSemanticVisitor_Operation_getExecutionLocus->setUpperBound(1);
	m_stateMachineSemanticVisitor_Operation_getExecutionLocus->setUnique(true);
	m_stateMachineSemanticVisitor_Operation_getExecutionLocus->setOrdered(false);
	
	m_stateMachineSemanticVisitor_Operation_getExecutionLocus->_setID(STATEMACHINESEMANTICVISITOR_OPERATION_GETEXECUTIONLOCUS);
	
	
	m_stateMachineSemanticVisitor_Operation_getStateMachineExecution->setName("getStateMachineExecution");
	m_stateMachineSemanticVisitor_Operation_getStateMachineExecution->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getExecution_Class());
	m_stateMachineSemanticVisitor_Operation_getStateMachineExecution->setLowerBound(1);
	m_stateMachineSemanticVisitor_Operation_getStateMachineExecution->setUpperBound(1);
	m_stateMachineSemanticVisitor_Operation_getStateMachineExecution->setUnique(true);
	m_stateMachineSemanticVisitor_Operation_getStateMachineExecution->setOrdered(false);
	
	m_stateMachineSemanticVisitor_Operation_getStateMachineExecution->_setID(STATEMACHINESEMANTICVISITOR_OPERATION_GETSTATEMACHINEEXECUTION);
	
	
	m_stateMachineSemanticVisitor_Operation_isVisitorFor_NamedElement->setName("isVisitorFor");
	m_stateMachineSemanticVisitor_Operation_isVisitorFor_NamedElement->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_stateMachineSemanticVisitor_Operation_isVisitorFor_NamedElement->setLowerBound(1);
	m_stateMachineSemanticVisitor_Operation_isVisitorFor_NamedElement->setUpperBound(1);
	m_stateMachineSemanticVisitor_Operation_isVisitorFor_NamedElement->setUnique(true);
	m_stateMachineSemanticVisitor_Operation_isVisitorFor_NamedElement->setOrdered(false);
	
	m_stateMachineSemanticVisitor_Operation_isVisitorFor_NamedElement->_setID(STATEMACHINESEMANTICVISITOR_OPERATION_ISVISITORFOR_NAMEDELEMENT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateMachineSemanticVisitor_Operation_isVisitorFor_NamedElement);
		parameter->setName("node");
		parameter->setEType(uml::umlPackage::eInstance()->getNamedElement_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stateMachineSemanticVisitor_Operation_match_EventOccurrence_Trigger->setName("match");
	m_stateMachineSemanticVisitor_Operation_match_EventOccurrence_Trigger->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_stateMachineSemanticVisitor_Operation_match_EventOccurrence_Trigger->setLowerBound(1);
	m_stateMachineSemanticVisitor_Operation_match_EventOccurrence_Trigger->setUpperBound(1);
	m_stateMachineSemanticVisitor_Operation_match_EventOccurrence_Trigger->setUnique(true);
	m_stateMachineSemanticVisitor_Operation_match_EventOccurrence_Trigger->setOrdered(false);
	
	m_stateMachineSemanticVisitor_Operation_match_EventOccurrence_Trigger->_setID(STATEMACHINESEMANTICVISITOR_OPERATION_MATCH_EVENTOCCURRENCE_TRIGGER);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateMachineSemanticVisitor_Operation_match_EventOccurrence_Trigger);
		parameter->setName("eventOccurrence");
		parameter->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventOccurrence_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateMachineSemanticVisitor_Operation_match_EventOccurrence_Trigger);
		parameter->setName("triggers");
		parameter->setEType(uml::umlPackage::eInstance()->getTrigger_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void StateMachinesPackageImpl::initializeTransitionActivationContent()
{
	m_transitionActivation_Class->setName("TransitionActivation");
	m_transitionActivation_Class->setAbstract(true);
	m_transitionActivation_Class->setInterface(false);
	
	m_transitionActivation_Class->_setID(TRANSITIONACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	m_transitionActivation_Attribute_analyticalStatus = getTransitionActivation_Attribute_analyticalStatus();
	m_transitionActivation_Attribute_analyticalStatus->setName("analyticalStatus");
	m_transitionActivation_Attribute_analyticalStatus->setEType(getTransitionMetadata_Class());
	m_transitionActivation_Attribute_analyticalStatus->setLowerBound(1);
	m_transitionActivation_Attribute_analyticalStatus->setUpperBound(1);
	m_transitionActivation_Attribute_analyticalStatus->setTransient(false);
	m_transitionActivation_Attribute_analyticalStatus->setVolatile(false);
	m_transitionActivation_Attribute_analyticalStatus->setChangeable(true);
	m_transitionActivation_Attribute_analyticalStatus->setUnsettable(false);
	m_transitionActivation_Attribute_analyticalStatus->setUnique(true);
	m_transitionActivation_Attribute_analyticalStatus->setDerived(false);
	m_transitionActivation_Attribute_analyticalStatus->setOrdered(false);
	m_transitionActivation_Attribute_analyticalStatus->setID(false);
	m_transitionActivation_Attribute_analyticalStatus->setDefaultValueLiteral("");
	
	m_transitionActivation_Attribute_analyticalStatus->_setID(TRANSITIONACTIVATION_ATTRIBUTE_ANALYTICALSTATUS);
	m_transitionActivation_Attribute_lastPropagation = getTransitionActivation_Attribute_lastPropagation();
	m_transitionActivation_Attribute_lastPropagation->setName("lastPropagation");
	m_transitionActivation_Attribute_lastPropagation->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_transitionActivation_Attribute_lastPropagation->setLowerBound(1);
	m_transitionActivation_Attribute_lastPropagation->setUpperBound(1);
	m_transitionActivation_Attribute_lastPropagation->setTransient(false);
	m_transitionActivation_Attribute_lastPropagation->setVolatile(false);
	m_transitionActivation_Attribute_lastPropagation->setChangeable(true);
	m_transitionActivation_Attribute_lastPropagation->setUnsettable(false);
	m_transitionActivation_Attribute_lastPropagation->setUnique(true);
	m_transitionActivation_Attribute_lastPropagation->setDerived(false);
	m_transitionActivation_Attribute_lastPropagation->setOrdered(false);
	m_transitionActivation_Attribute_lastPropagation->setID(false);
	m_transitionActivation_Attribute_lastPropagation->setDefaultValueLiteral("");
	
	m_transitionActivation_Attribute_lastPropagation->_setID(TRANSITIONACTIVATION_ATTRIBUTE_LASTPROPAGATION);
	m_transitionActivation_Attribute_status = getTransitionActivation_Attribute_status();
	m_transitionActivation_Attribute_status->setName("status");
	m_transitionActivation_Attribute_status->setEType(getTransitionMetadata_Class());
	m_transitionActivation_Attribute_status->setLowerBound(1);
	m_transitionActivation_Attribute_status->setUpperBound(1);
	m_transitionActivation_Attribute_status->setTransient(false);
	m_transitionActivation_Attribute_status->setVolatile(false);
	m_transitionActivation_Attribute_status->setChangeable(true);
	m_transitionActivation_Attribute_status->setUnsettable(false);
	m_transitionActivation_Attribute_status->setUnique(true);
	m_transitionActivation_Attribute_status->setDerived(false);
	m_transitionActivation_Attribute_status->setOrdered(false);
	m_transitionActivation_Attribute_status->setID(false);
	m_transitionActivation_Attribute_status->setDefaultValueLiteral("");
	
	m_transitionActivation_Attribute_status->_setID(TRANSITIONACTIVATION_ATTRIBUTE_STATUS);
	
	/*
	 * EReferences
	 */
	m_transitionActivation_Attribute_lastTriggeringEventOccurrence->setName("lastTriggeringEventOccurrence");
	m_transitionActivation_Attribute_lastTriggeringEventOccurrence->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventOccurrence_Class());
	m_transitionActivation_Attribute_lastTriggeringEventOccurrence->setLowerBound(0);
	m_transitionActivation_Attribute_lastTriggeringEventOccurrence->setUpperBound(1);
	m_transitionActivation_Attribute_lastTriggeringEventOccurrence->setTransient(false);
	m_transitionActivation_Attribute_lastTriggeringEventOccurrence->setVolatile(false);
	m_transitionActivation_Attribute_lastTriggeringEventOccurrence->setChangeable(true);
	m_transitionActivation_Attribute_lastTriggeringEventOccurrence->setUnsettable(false);
	m_transitionActivation_Attribute_lastTriggeringEventOccurrence->setUnique(true);
	m_transitionActivation_Attribute_lastTriggeringEventOccurrence->setDerived(false);
	m_transitionActivation_Attribute_lastTriggeringEventOccurrence->setOrdered(false);
	m_transitionActivation_Attribute_lastTriggeringEventOccurrence->setContainment(false);
	m_transitionActivation_Attribute_lastTriggeringEventOccurrence->setResolveProxies(true);
	m_transitionActivation_Attribute_lastTriggeringEventOccurrence->setDefaultValueLiteral("");	
	
	m_transitionActivation_Attribute_lastTriggeringEventOccurrence->_setID(TRANSITIONACTIVATION_ATTRIBUTE_LASTTRIGGERINGEVENTOCCURRENCE);
	m_transitionActivation_Attribute_leastCommonAncestor->setName("leastCommonAncestor");
	m_transitionActivation_Attribute_leastCommonAncestor->setEType(getRegionActivation_Class());
	m_transitionActivation_Attribute_leastCommonAncestor->setLowerBound(1);
	m_transitionActivation_Attribute_leastCommonAncestor->setUpperBound(1);
	m_transitionActivation_Attribute_leastCommonAncestor->setTransient(false);
	m_transitionActivation_Attribute_leastCommonAncestor->setVolatile(false);
	m_transitionActivation_Attribute_leastCommonAncestor->setChangeable(true);
	m_transitionActivation_Attribute_leastCommonAncestor->setUnsettable(false);
	m_transitionActivation_Attribute_leastCommonAncestor->setUnique(true);
	m_transitionActivation_Attribute_leastCommonAncestor->setDerived(false);
	m_transitionActivation_Attribute_leastCommonAncestor->setOrdered(false);
	m_transitionActivation_Attribute_leastCommonAncestor->setContainment(false);
	m_transitionActivation_Attribute_leastCommonAncestor->setResolveProxies(true);
	m_transitionActivation_Attribute_leastCommonAncestor->setDefaultValueLiteral("");	
	
	m_transitionActivation_Attribute_leastCommonAncestor->_setID(TRANSITIONACTIVATION_ATTRIBUTE_LEASTCOMMONANCESTOR);
	m_transitionActivation_Attribute_sourceVertexActivation->setName("sourceVertexActivation");
	m_transitionActivation_Attribute_sourceVertexActivation->setEType(getVertexActivation_Class());
	m_transitionActivation_Attribute_sourceVertexActivation->setLowerBound(1);
	m_transitionActivation_Attribute_sourceVertexActivation->setUpperBound(1);
	m_transitionActivation_Attribute_sourceVertexActivation->setTransient(false);
	m_transitionActivation_Attribute_sourceVertexActivation->setVolatile(false);
	m_transitionActivation_Attribute_sourceVertexActivation->setChangeable(true);
	m_transitionActivation_Attribute_sourceVertexActivation->setUnsettable(false);
	m_transitionActivation_Attribute_sourceVertexActivation->setUnique(true);
	m_transitionActivation_Attribute_sourceVertexActivation->setDerived(false);
	m_transitionActivation_Attribute_sourceVertexActivation->setOrdered(false);
	m_transitionActivation_Attribute_sourceVertexActivation->setContainment(false);
	m_transitionActivation_Attribute_sourceVertexActivation->setResolveProxies(true);
	m_transitionActivation_Attribute_sourceVertexActivation->setDefaultValueLiteral("");	
	m_transitionActivation_Attribute_sourceVertexActivation->setEOpposite(PSSM::Semantics::StateMachines::StateMachinesPackage::eInstance()->getVertexActivation_Attribute_outgoingTransitionActivations());
	
	m_transitionActivation_Attribute_sourceVertexActivation->_setID(TRANSITIONACTIVATION_ATTRIBUTE_SOURCEVERTEXACTIVATION);
	m_transitionActivation_Attribute_targetVertexActivation->setName("targetVertexActivation");
	m_transitionActivation_Attribute_targetVertexActivation->setEType(getVertexActivation_Class());
	m_transitionActivation_Attribute_targetVertexActivation->setLowerBound(1);
	m_transitionActivation_Attribute_targetVertexActivation->setUpperBound(1);
	m_transitionActivation_Attribute_targetVertexActivation->setTransient(false);
	m_transitionActivation_Attribute_targetVertexActivation->setVolatile(false);
	m_transitionActivation_Attribute_targetVertexActivation->setChangeable(true);
	m_transitionActivation_Attribute_targetVertexActivation->setUnsettable(false);
	m_transitionActivation_Attribute_targetVertexActivation->setUnique(true);
	m_transitionActivation_Attribute_targetVertexActivation->setDerived(false);
	m_transitionActivation_Attribute_targetVertexActivation->setOrdered(false);
	m_transitionActivation_Attribute_targetVertexActivation->setContainment(false);
	m_transitionActivation_Attribute_targetVertexActivation->setResolveProxies(true);
	m_transitionActivation_Attribute_targetVertexActivation->setDefaultValueLiteral("");	
	m_transitionActivation_Attribute_targetVertexActivation->setEOpposite(PSSM::Semantics::StateMachines::StateMachinesPackage::eInstance()->getVertexActivation_Attribute_incomingTransitionActivations());
	
	m_transitionActivation_Attribute_targetVertexActivation->_setID(TRANSITIONACTIVATION_ATTRIBUTE_TARGETVERTEXACTIVATION);
	
	/*
	 * EOperations
	 */
	m_transitionActivation_Operation_canFireOn_EventOccurrence->setName("canFireOn");
	m_transitionActivation_Operation_canFireOn_EventOccurrence->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_transitionActivation_Operation_canFireOn_EventOccurrence->setLowerBound(1);
	m_transitionActivation_Operation_canFireOn_EventOccurrence->setUpperBound(1);
	m_transitionActivation_Operation_canFireOn_EventOccurrence->setUnique(true);
	m_transitionActivation_Operation_canFireOn_EventOccurrence->setOrdered(false);
	
	m_transitionActivation_Operation_canFireOn_EventOccurrence->_setID(TRANSITIONACTIVATION_OPERATION_CANFIREON_EVENTOCCURRENCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_transitionActivation_Operation_canFireOn_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventOccurrence_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_transitionActivation_Operation_canPropagateExecution_EventOccurrence->setName("canPropagateExecution");
	m_transitionActivation_Operation_canPropagateExecution_EventOccurrence->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_transitionActivation_Operation_canPropagateExecution_EventOccurrence->setLowerBound(1);
	m_transitionActivation_Operation_canPropagateExecution_EventOccurrence->setUpperBound(1);
	m_transitionActivation_Operation_canPropagateExecution_EventOccurrence->setUnique(true);
	m_transitionActivation_Operation_canPropagateExecution_EventOccurrence->setOrdered(false);
	
	m_transitionActivation_Operation_canPropagateExecution_EventOccurrence->_setID(TRANSITIONACTIVATION_OPERATION_CANPROPAGATEEXECUTION_EVENTOCCURRENCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_transitionActivation_Operation_canPropagateExecution_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventOccurrence_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_transitionActivation_Operation_enterTarget_EventOccurrence->setName("enterTarget");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_transitionActivation_Operation_enterTarget_EventOccurrence->setEType(unknownClass);
	}
	m_transitionActivation_Operation_enterTarget_EventOccurrence->setLowerBound(1);
	m_transitionActivation_Operation_enterTarget_EventOccurrence->setUpperBound(1);
	m_transitionActivation_Operation_enterTarget_EventOccurrence->setUnique(true);
	m_transitionActivation_Operation_enterTarget_EventOccurrence->setOrdered(false);
	
	m_transitionActivation_Operation_enterTarget_EventOccurrence->_setID(TRANSITIONACTIVATION_OPERATION_ENTERTARGET_EVENTOCCURRENCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_transitionActivation_Operation_enterTarget_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_transitionActivation_Operation_evaluateGuard_EventOccurrence->setName("evaluateGuard");
	m_transitionActivation_Operation_evaluateGuard_EventOccurrence->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_transitionActivation_Operation_evaluateGuard_EventOccurrence->setLowerBound(1);
	m_transitionActivation_Operation_evaluateGuard_EventOccurrence->setUpperBound(1);
	m_transitionActivation_Operation_evaluateGuard_EventOccurrence->setUnique(true);
	m_transitionActivation_Operation_evaluateGuard_EventOccurrence->setOrdered(false);
	
	m_transitionActivation_Operation_evaluateGuard_EventOccurrence->_setID(TRANSITIONACTIVATION_OPERATION_EVALUATEGUARD_EVENTOCCURRENCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_transitionActivation_Operation_evaluateGuard_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventOccurrence_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_transitionActivation_Operation_exitSource_EventOccurrence->setName("exitSource");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_transitionActivation_Operation_exitSource_EventOccurrence->setEType(unknownClass);
	}
	m_transitionActivation_Operation_exitSource_EventOccurrence->setLowerBound(1);
	m_transitionActivation_Operation_exitSource_EventOccurrence->setUpperBound(1);
	m_transitionActivation_Operation_exitSource_EventOccurrence->setUnique(true);
	m_transitionActivation_Operation_exitSource_EventOccurrence->setOrdered(false);
	
	m_transitionActivation_Operation_exitSource_EventOccurrence->_setID(TRANSITIONACTIVATION_OPERATION_EXITSOURCE_EVENTOCCURRENCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_transitionActivation_Operation_exitSource_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_transitionActivation_Operation_fire_EventOccurrence->setName("fire");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_transitionActivation_Operation_fire_EventOccurrence->setEType(unknownClass);
	}
	m_transitionActivation_Operation_fire_EventOccurrence->setLowerBound(1);
	m_transitionActivation_Operation_fire_EventOccurrence->setUpperBound(1);
	m_transitionActivation_Operation_fire_EventOccurrence->setUnique(true);
	m_transitionActivation_Operation_fire_EventOccurrence->setOrdered(false);
	
	m_transitionActivation_Operation_fire_EventOccurrence->_setID(TRANSITIONACTIVATION_OPERATION_FIRE_EVENTOCCURRENCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_transitionActivation_Operation_fire_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_transitionActivation_Operation_getSourceActivation->setName("getSourceActivation");
	m_transitionActivation_Operation_getSourceActivation->setEType(getVertexActivation_Class());
	m_transitionActivation_Operation_getSourceActivation->setLowerBound(1);
	m_transitionActivation_Operation_getSourceActivation->setUpperBound(1);
	m_transitionActivation_Operation_getSourceActivation->setUnique(true);
	m_transitionActivation_Operation_getSourceActivation->setOrdered(false);
	
	m_transitionActivation_Operation_getSourceActivation->_setID(TRANSITIONACTIVATION_OPERATION_GETSOURCEACTIVATION);
	
	
	m_transitionActivation_Operation_getTargetActivation->setName("getTargetActivation");
	m_transitionActivation_Operation_getTargetActivation->setEType(getVertexActivation_Class());
	m_transitionActivation_Operation_getTargetActivation->setLowerBound(1);
	m_transitionActivation_Operation_getTargetActivation->setUpperBound(1);
	m_transitionActivation_Operation_getTargetActivation->setUnique(true);
	m_transitionActivation_Operation_getTargetActivation->setOrdered(false);
	
	m_transitionActivation_Operation_getTargetActivation->_setID(TRANSITIONACTIVATION_OPERATION_GETTARGETACTIVATION);
	
	
	m_transitionActivation_Operation_hasTrigger_EventOccurrence->setName("hasTrigger");
	m_transitionActivation_Operation_hasTrigger_EventOccurrence->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_transitionActivation_Operation_hasTrigger_EventOccurrence->setLowerBound(1);
	m_transitionActivation_Operation_hasTrigger_EventOccurrence->setUpperBound(1);
	m_transitionActivation_Operation_hasTrigger_EventOccurrence->setUnique(true);
	m_transitionActivation_Operation_hasTrigger_EventOccurrence->setOrdered(false);
	
	m_transitionActivation_Operation_hasTrigger_EventOccurrence->_setID(TRANSITIONACTIVATION_OPERATION_HASTRIGGER_EVENTOCCURRENCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_transitionActivation_Operation_hasTrigger_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventOccurrence_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_transitionActivation_Operation_isGuarded->setName("isGuarded");
	m_transitionActivation_Operation_isGuarded->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_transitionActivation_Operation_isGuarded->setLowerBound(1);
	m_transitionActivation_Operation_isGuarded->setUpperBound(1);
	m_transitionActivation_Operation_isGuarded->setUnique(true);
	m_transitionActivation_Operation_isGuarded->setOrdered(false);
	
	m_transitionActivation_Operation_isGuarded->_setID(TRANSITIONACTIVATION_OPERATION_ISGUARDED);
	
	
	m_transitionActivation_Operation_isReached->setName("isReached");
	m_transitionActivation_Operation_isReached->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_transitionActivation_Operation_isReached->setLowerBound(1);
	m_transitionActivation_Operation_isReached->setUpperBound(1);
	m_transitionActivation_Operation_isReached->setUnique(true);
	m_transitionActivation_Operation_isReached->setOrdered(false);
	
	m_transitionActivation_Operation_isReached->_setID(TRANSITIONACTIVATION_OPERATION_ISREACHED);
	
	
	m_transitionActivation_Operation_isTraversed_Boolean->setName("isTraversed");
	m_transitionActivation_Operation_isTraversed_Boolean->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_transitionActivation_Operation_isTraversed_Boolean->setLowerBound(1);
	m_transitionActivation_Operation_isTraversed_Boolean->setUpperBound(1);
	m_transitionActivation_Operation_isTraversed_Boolean->setUnique(true);
	m_transitionActivation_Operation_isTraversed_Boolean->setOrdered(false);
	
	m_transitionActivation_Operation_isTraversed_Boolean->_setID(TRANSITIONACTIVATION_OPERATION_ISTRAVERSED_BOOLEAN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_transitionActivation_Operation_isTraversed_Boolean);
		parameter->setName("staticCheck");
		parameter->setEType(types::typesPackage::eInstance()->getBoolean_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_transitionActivation_Operation_isTriggered_Boolean->setName("isTriggered");
	m_transitionActivation_Operation_isTriggered_Boolean->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_transitionActivation_Operation_isTriggered_Boolean->setLowerBound(1);
	m_transitionActivation_Operation_isTriggered_Boolean->setUpperBound(1);
	m_transitionActivation_Operation_isTriggered_Boolean->setUnique(true);
	m_transitionActivation_Operation_isTriggered_Boolean->setOrdered(false);
	
	m_transitionActivation_Operation_isTriggered_Boolean->_setID(TRANSITIONACTIVATION_OPERATION_ISTRIGGERED_BOOLEAN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_transitionActivation_Operation_isTriggered_Boolean);
		parameter->setName("staticCheck");
		parameter->setEType(types::typesPackage::eInstance()->getBoolean_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_transitionActivation_Operation_setSourceActivation_VertexActivation->setName("setSourceActivation");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_transitionActivation_Operation_setSourceActivation_VertexActivation->setEType(unknownClass);
	}
	m_transitionActivation_Operation_setSourceActivation_VertexActivation->setLowerBound(1);
	m_transitionActivation_Operation_setSourceActivation_VertexActivation->setUpperBound(1);
	m_transitionActivation_Operation_setSourceActivation_VertexActivation->setUnique(true);
	m_transitionActivation_Operation_setSourceActivation_VertexActivation->setOrdered(false);
	
	m_transitionActivation_Operation_setSourceActivation_VertexActivation->_setID(TRANSITIONACTIVATION_OPERATION_SETSOURCEACTIVATION_VERTEXACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_transitionActivation_Operation_setSourceActivation_VertexActivation);
		parameter->setName("sourceActivation");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_transitionActivation_Operation_setTargetActivation_VertexActivation->setName("setTargetActivation");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_transitionActivation_Operation_setTargetActivation_VertexActivation->setEType(unknownClass);
	}
	m_transitionActivation_Operation_setTargetActivation_VertexActivation->setLowerBound(1);
	m_transitionActivation_Operation_setTargetActivation_VertexActivation->setUpperBound(1);
	m_transitionActivation_Operation_setTargetActivation_VertexActivation->setUnique(true);
	m_transitionActivation_Operation_setTargetActivation_VertexActivation->setOrdered(false);
	
	m_transitionActivation_Operation_setTargetActivation_VertexActivation->_setID(TRANSITIONACTIVATION_OPERATION_SETTARGETACTIVATION_VERTEXACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_transitionActivation_Operation_setTargetActivation_VertexActivation);
		parameter->setName("targetActivation");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_transitionActivation_Operation_tryExecuteEffect_EventOccurrence->setName("tryExecuteEffect");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_transitionActivation_Operation_tryExecuteEffect_EventOccurrence->setEType(unknownClass);
	}
	m_transitionActivation_Operation_tryExecuteEffect_EventOccurrence->setLowerBound(1);
	m_transitionActivation_Operation_tryExecuteEffect_EventOccurrence->setUpperBound(1);
	m_transitionActivation_Operation_tryExecuteEffect_EventOccurrence->setUnique(true);
	m_transitionActivation_Operation_tryExecuteEffect_EventOccurrence->setOrdered(false);
	
	m_transitionActivation_Operation_tryExecuteEffect_EventOccurrence->_setID(TRANSITIONACTIVATION_OPERATION_TRYEXECUTEEFFECT_EVENTOCCURRENCE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_transitionActivation_Operation_tryExecuteEffect_EventOccurrence);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void StateMachinesPackageImpl::initializeVertexActivationContent()
{
	m_vertexActivation_Class->setName("VertexActivation");
	m_vertexActivation_Class->setAbstract(true);
	m_vertexActivation_Class->setInterface(false);
	
	m_vertexActivation_Class->_setID(VERTEXACTIVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	m_vertexActivation_Attribute_status = getVertexActivation_Attribute_status();
	m_vertexActivation_Attribute_status->setName("status");
	m_vertexActivation_Attribute_status->setEType(getStateMetadata_Class());
	m_vertexActivation_Attribute_status->setLowerBound(1);
	m_vertexActivation_Attribute_status->setUpperBound(1);
	m_vertexActivation_Attribute_status->setTransient(false);
	m_vertexActivation_Attribute_status->setVolatile(false);
	m_vertexActivation_Attribute_status->setChangeable(true);
	m_vertexActivation_Attribute_status->setUnsettable(false);
	m_vertexActivation_Attribute_status->setUnique(true);
	m_vertexActivation_Attribute_status->setDerived(false);
	m_vertexActivation_Attribute_status->setOrdered(false);
	m_vertexActivation_Attribute_status->setID(false);
	m_vertexActivation_Attribute_status->setDefaultValueLiteral("");
	
	m_vertexActivation_Attribute_status->_setID(VERTEXACTIVATION_ATTRIBUTE_STATUS);
	
	/*
	 * EReferences
	 */
	m_vertexActivation_Attribute_incomingTransitionActivations->setName("incomingTransitionActivations");
	m_vertexActivation_Attribute_incomingTransitionActivations->setEType(getTransitionActivation_Class());
	m_vertexActivation_Attribute_incomingTransitionActivations->setLowerBound(0);
	m_vertexActivation_Attribute_incomingTransitionActivations->setUpperBound(-1);
	m_vertexActivation_Attribute_incomingTransitionActivations->setTransient(false);
	m_vertexActivation_Attribute_incomingTransitionActivations->setVolatile(false);
	m_vertexActivation_Attribute_incomingTransitionActivations->setChangeable(true);
	m_vertexActivation_Attribute_incomingTransitionActivations->setUnsettable(false);
	m_vertexActivation_Attribute_incomingTransitionActivations->setUnique(true);
	m_vertexActivation_Attribute_incomingTransitionActivations->setDerived(false);
	m_vertexActivation_Attribute_incomingTransitionActivations->setOrdered(false);
	m_vertexActivation_Attribute_incomingTransitionActivations->setContainment(false);
	m_vertexActivation_Attribute_incomingTransitionActivations->setResolveProxies(true);
	m_vertexActivation_Attribute_incomingTransitionActivations->setDefaultValueLiteral("");	
	m_vertexActivation_Attribute_incomingTransitionActivations->setEOpposite(PSSM::Semantics::StateMachines::StateMachinesPackage::eInstance()->getTransitionActivation_Attribute_targetVertexActivation());
	
	m_vertexActivation_Attribute_incomingTransitionActivations->_setID(VERTEXACTIVATION_ATTRIBUTE_INCOMINGTRANSITIONACTIVATIONS);
	m_vertexActivation_Attribute_outgoingTransitionActivations->setName("outgoingTransitionActivations");
	m_vertexActivation_Attribute_outgoingTransitionActivations->setEType(getTransitionActivation_Class());
	m_vertexActivation_Attribute_outgoingTransitionActivations->setLowerBound(0);
	m_vertexActivation_Attribute_outgoingTransitionActivations->setUpperBound(-1);
	m_vertexActivation_Attribute_outgoingTransitionActivations->setTransient(false);
	m_vertexActivation_Attribute_outgoingTransitionActivations->setVolatile(false);
	m_vertexActivation_Attribute_outgoingTransitionActivations->setChangeable(true);
	m_vertexActivation_Attribute_outgoingTransitionActivations->setUnsettable(false);
	m_vertexActivation_Attribute_outgoingTransitionActivations->setUnique(true);
	m_vertexActivation_Attribute_outgoingTransitionActivations->setDerived(false);
	m_vertexActivation_Attribute_outgoingTransitionActivations->setOrdered(false);
	m_vertexActivation_Attribute_outgoingTransitionActivations->setContainment(false);
	m_vertexActivation_Attribute_outgoingTransitionActivations->setResolveProxies(true);
	m_vertexActivation_Attribute_outgoingTransitionActivations->setDefaultValueLiteral("");	
	m_vertexActivation_Attribute_outgoingTransitionActivations->setEOpposite(PSSM::Semantics::StateMachines::StateMachinesPackage::eInstance()->getTransitionActivation_Attribute_sourceVertexActivation());
	
	m_vertexActivation_Attribute_outgoingTransitionActivations->_setID(VERTEXACTIVATION_ATTRIBUTE_OUTGOINGTRANSITIONACTIVATIONS);
	
	/*
	 * EOperations
	 */
	m_vertexActivation_Operation_addIncomingTransition_TransitionActivation->setName("addIncomingTransition");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_vertexActivation_Operation_addIncomingTransition_TransitionActivation->setEType(unknownClass);
	}
	m_vertexActivation_Operation_addIncomingTransition_TransitionActivation->setLowerBound(1);
	m_vertexActivation_Operation_addIncomingTransition_TransitionActivation->setUpperBound(1);
	m_vertexActivation_Operation_addIncomingTransition_TransitionActivation->setUnique(true);
	m_vertexActivation_Operation_addIncomingTransition_TransitionActivation->setOrdered(false);
	
	m_vertexActivation_Operation_addIncomingTransition_TransitionActivation->_setID(VERTEXACTIVATION_OPERATION_ADDINCOMINGTRANSITION_TRANSITIONACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_vertexActivation_Operation_addIncomingTransition_TransitionActivation);
		parameter->setName("transitionActivation");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_vertexActivation_Operation_addOutgoingTransition_TransitionActivation->setName("addOutgoingTransition");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_vertexActivation_Operation_addOutgoingTransition_TransitionActivation->setEType(unknownClass);
	}
	m_vertexActivation_Operation_addOutgoingTransition_TransitionActivation->setLowerBound(1);
	m_vertexActivation_Operation_addOutgoingTransition_TransitionActivation->setUpperBound(1);
	m_vertexActivation_Operation_addOutgoingTransition_TransitionActivation->setUnique(true);
	m_vertexActivation_Operation_addOutgoingTransition_TransitionActivation->setOrdered(false);
	
	m_vertexActivation_Operation_addOutgoingTransition_TransitionActivation->_setID(VERTEXACTIVATION_OPERATION_ADDOUTGOINGTRANSITION_TRANSITIONACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_vertexActivation_Operation_addOutgoingTransition_TransitionActivation);
		parameter->setName("transitionActivation");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_vertexActivation_Operation_canPropagateExecution_TransitionActivation_RegionActivation->setName("canPropagateExecution");
	m_vertexActivation_Operation_canPropagateExecution_TransitionActivation_RegionActivation->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_vertexActivation_Operation_canPropagateExecution_TransitionActivation_RegionActivation->setLowerBound(1);
	m_vertexActivation_Operation_canPropagateExecution_TransitionActivation_RegionActivation->setUpperBound(1);
	m_vertexActivation_Operation_canPropagateExecution_TransitionActivation_RegionActivation->setUnique(true);
	m_vertexActivation_Operation_canPropagateExecution_TransitionActivation_RegionActivation->setOrdered(false);
	
	m_vertexActivation_Operation_canPropagateExecution_TransitionActivation_RegionActivation->_setID(VERTEXACTIVATION_OPERATION_CANPROPAGATEEXECUTION_TRANSITIONACTIVATION_REGIONACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_vertexActivation_Operation_canPropagateExecution_TransitionActivation_RegionActivation);
		parameter->setName("enteringTransition");
		parameter->setEType(getTransitionActivation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_vertexActivation_Operation_canPropagateExecution_TransitionActivation_RegionActivation);
		parameter->setName("eventOccurrence");
		parameter->setEType(fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getEventOccurrence_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_vertexActivation_Operation_canPropagateExecution_TransitionActivation_RegionActivation);
		parameter->setName("leastCommonAncestor");
		parameter->setEType(getRegionActivation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_vertexActivation_Operation_enter_TransitionActivation_RegionActivation->setName("enter");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_vertexActivation_Operation_enter_TransitionActivation_RegionActivation->setEType(unknownClass);
	}
	m_vertexActivation_Operation_enter_TransitionActivation_RegionActivation->setLowerBound(1);
	m_vertexActivation_Operation_enter_TransitionActivation_RegionActivation->setUpperBound(1);
	m_vertexActivation_Operation_enter_TransitionActivation_RegionActivation->setUnique(true);
	m_vertexActivation_Operation_enter_TransitionActivation_RegionActivation->setOrdered(false);
	
	m_vertexActivation_Operation_enter_TransitionActivation_RegionActivation->_setID(VERTEXACTIVATION_OPERATION_ENTER_TRANSITIONACTIVATION_REGIONACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_vertexActivation_Operation_enter_TransitionActivation_RegionActivation);
		parameter->setName("enteringTransition");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_vertexActivation_Operation_enter_TransitionActivation_RegionActivation);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_vertexActivation_Operation_enter_TransitionActivation_RegionActivation);
		parameter->setName("leastCommonAncestor");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_vertexActivation_Operation_exit_TransitionActivation_RegionActivation->setName("exit");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_vertexActivation_Operation_exit_TransitionActivation_RegionActivation->setEType(unknownClass);
	}
	m_vertexActivation_Operation_exit_TransitionActivation_RegionActivation->setLowerBound(1);
	m_vertexActivation_Operation_exit_TransitionActivation_RegionActivation->setUpperBound(1);
	m_vertexActivation_Operation_exit_TransitionActivation_RegionActivation->setUnique(true);
	m_vertexActivation_Operation_exit_TransitionActivation_RegionActivation->setOrdered(false);
	
	m_vertexActivation_Operation_exit_TransitionActivation_RegionActivation->_setID(VERTEXACTIVATION_OPERATION_EXIT_TRANSITIONACTIVATION_REGIONACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_vertexActivation_Operation_exit_TransitionActivation_RegionActivation);
		parameter->setName("exitingTransition");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_vertexActivation_Operation_exit_TransitionActivation_RegionActivation);
		parameter->setName("eventOccurrence");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_vertexActivation_Operation_exit_TransitionActivation_RegionActivation);
		parameter->setName("leastCommonAncestor");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_vertexActivation_Operation_getAscendingHierarchy->setName("getAscendingHierarchy");
	m_vertexActivation_Operation_getAscendingHierarchy->setEType(getVertexActivation_Class());
	m_vertexActivation_Operation_getAscendingHierarchy->setLowerBound(0);
	m_vertexActivation_Operation_getAscendingHierarchy->setUpperBound(-1);
	m_vertexActivation_Operation_getAscendingHierarchy->setUnique(true);
	m_vertexActivation_Operation_getAscendingHierarchy->setOrdered(false);
	
	m_vertexActivation_Operation_getAscendingHierarchy->_setID(VERTEXACTIVATION_OPERATION_GETASCENDINGHIERARCHY);
	
	
	m_vertexActivation_Operation_getIncomingTransitions->setName("getIncomingTransitions");
	m_vertexActivation_Operation_getIncomingTransitions->setEType(getTransitionActivation_Class());
	m_vertexActivation_Operation_getIncomingTransitions->setLowerBound(0);
	m_vertexActivation_Operation_getIncomingTransitions->setUpperBound(-1);
	m_vertexActivation_Operation_getIncomingTransitions->setUnique(true);
	m_vertexActivation_Operation_getIncomingTransitions->setOrdered(false);
	
	m_vertexActivation_Operation_getIncomingTransitions->_setID(VERTEXACTIVATION_OPERATION_GETINCOMINGTRANSITIONS);
	
	
	m_vertexActivation_Operation_getLeastCommonAncestor_VertexActivation->setName("getLeastCommonAncestor");
	m_vertexActivation_Operation_getLeastCommonAncestor_VertexActivation->setEType(getRegionActivation_Class());
	m_vertexActivation_Operation_getLeastCommonAncestor_VertexActivation->setLowerBound(1);
	m_vertexActivation_Operation_getLeastCommonAncestor_VertexActivation->setUpperBound(1);
	m_vertexActivation_Operation_getLeastCommonAncestor_VertexActivation->setUnique(true);
	m_vertexActivation_Operation_getLeastCommonAncestor_VertexActivation->setOrdered(false);
	
	m_vertexActivation_Operation_getLeastCommonAncestor_VertexActivation->_setID(VERTEXACTIVATION_OPERATION_GETLEASTCOMMONANCESTOR_VERTEXACTIVATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_vertexActivation_Operation_getLeastCommonAncestor_VertexActivation);
		parameter->setName("vertexActivation");
		parameter->setEType(getVertexActivation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_vertexActivation_Operation_getOutgoingTransitions->setName("getOutgoingTransitions");
	m_vertexActivation_Operation_getOutgoingTransitions->setEType(getTransitionActivation_Class());
	m_vertexActivation_Operation_getOutgoingTransitions->setLowerBound(0);
	m_vertexActivation_Operation_getOutgoingTransitions->setUpperBound(-1);
	m_vertexActivation_Operation_getOutgoingTransitions->setUnique(true);
	m_vertexActivation_Operation_getOutgoingTransitions->setOrdered(false);
	
	m_vertexActivation_Operation_getOutgoingTransitions->_setID(VERTEXACTIVATION_OPERATION_GETOUTGOINGTRANSITIONS);
	
	
	m_vertexActivation_Operation_getOwningRegionActivation->setName("getOwningRegionActivation");
	m_vertexActivation_Operation_getOwningRegionActivation->setEType(getRegionActivation_Class());
	m_vertexActivation_Operation_getOwningRegionActivation->setLowerBound(1);
	m_vertexActivation_Operation_getOwningRegionActivation->setUpperBound(1);
	m_vertexActivation_Operation_getOwningRegionActivation->setUnique(true);
	m_vertexActivation_Operation_getOwningRegionActivation->setOrdered(false);
	
	m_vertexActivation_Operation_getOwningRegionActivation->_setID(VERTEXACTIVATION_OPERATION_GETOWNINGREGIONACTIVATION);
	
	
	m_vertexActivation_Operation_getParentVertexActivation->setName("getParentVertexActivation");
	m_vertexActivation_Operation_getParentVertexActivation->setEType(getVertexActivation_Class());
	m_vertexActivation_Operation_getParentVertexActivation->setLowerBound(1);
	m_vertexActivation_Operation_getParentVertexActivation->setUpperBound(1);
	m_vertexActivation_Operation_getParentVertexActivation->setUnique(true);
	m_vertexActivation_Operation_getParentVertexActivation->setOrdered(false);
	
	m_vertexActivation_Operation_getParentVertexActivation->_setID(VERTEXACTIVATION_OPERATION_GETPARENTVERTEXACTIVATION);
	
	
	m_vertexActivation_Operation_getRegionActivation_SemanticVisitor->setName("getRegionActivation");
	m_vertexActivation_Operation_getRegionActivation_SemanticVisitor->setEType(getRegionActivation_Class());
	m_vertexActivation_Operation_getRegionActivation_SemanticVisitor->setLowerBound(1);
	m_vertexActivation_Operation_getRegionActivation_SemanticVisitor->setUpperBound(1);
	m_vertexActivation_Operation_getRegionActivation_SemanticVisitor->setUnique(true);
	m_vertexActivation_Operation_getRegionActivation_SemanticVisitor->setOrdered(false);
	
	m_vertexActivation_Operation_getRegionActivation_SemanticVisitor->_setID(VERTEXACTIVATION_OPERATION_GETREGIONACTIVATION_SEMANTICVISITOR);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_vertexActivation_Operation_getRegionActivation_SemanticVisitor);
		parameter->setName("semanticVisitor");
		parameter->setEType(fUML::Semantics::Loci::LociPackage::eInstance()->getSemanticVisitor_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_vertexActivation_Operation_getVertexActivation_Vertex->setName("getVertexActivation");
	m_vertexActivation_Operation_getVertexActivation_Vertex->setEType(getVertexActivation_Class());
	m_vertexActivation_Operation_getVertexActivation_Vertex->setLowerBound(1);
	m_vertexActivation_Operation_getVertexActivation_Vertex->setUpperBound(1);
	m_vertexActivation_Operation_getVertexActivation_Vertex->setUnique(true);
	m_vertexActivation_Operation_getVertexActivation_Vertex->setOrdered(false);
	
	m_vertexActivation_Operation_getVertexActivation_Vertex->_setID(VERTEXACTIVATION_OPERATION_GETVERTEXACTIVATION_VERTEX);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_vertexActivation_Operation_getVertexActivation_Vertex);
		parameter->setName("vertex");
		parameter->setEType(uml::umlPackage::eInstance()->getVertex_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_vertexActivation_Operation_isActive->setName("isActive");
	m_vertexActivation_Operation_isActive->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_vertexActivation_Operation_isActive->setLowerBound(1);
	m_vertexActivation_Operation_isActive->setUpperBound(1);
	m_vertexActivation_Operation_isActive->setUnique(true);
	m_vertexActivation_Operation_isActive->setOrdered(false);
	
	m_vertexActivation_Operation_isActive->_setID(VERTEXACTIVATION_OPERATION_ISACTIVE);
	
	
	m_vertexActivation_Operation_isEnterable_TransitionActivation_Boolean->setName("isEnterable");
	m_vertexActivation_Operation_isEnterable_TransitionActivation_Boolean->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_vertexActivation_Operation_isEnterable_TransitionActivation_Boolean->setLowerBound(1);
	m_vertexActivation_Operation_isEnterable_TransitionActivation_Boolean->setUpperBound(1);
	m_vertexActivation_Operation_isEnterable_TransitionActivation_Boolean->setUnique(true);
	m_vertexActivation_Operation_isEnterable_TransitionActivation_Boolean->setOrdered(false);
	
	m_vertexActivation_Operation_isEnterable_TransitionActivation_Boolean->_setID(VERTEXACTIVATION_OPERATION_ISENTERABLE_TRANSITIONACTIVATION_BOOLEAN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_vertexActivation_Operation_isEnterable_TransitionActivation_Boolean);
		parameter->setName("enteringTransition");
		parameter->setEType(getTransitionActivation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_vertexActivation_Operation_isEnterable_TransitionActivation_Boolean);
		parameter->setName("staticCheck");
		parameter->setEType(types::typesPackage::eInstance()->getBoolean_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_vertexActivation_Operation_isExitable_TransitionActivation_Boolean->setName("isExitable");
	m_vertexActivation_Operation_isExitable_TransitionActivation_Boolean->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_vertexActivation_Operation_isExitable_TransitionActivation_Boolean->setLowerBound(1);
	m_vertexActivation_Operation_isExitable_TransitionActivation_Boolean->setUpperBound(1);
	m_vertexActivation_Operation_isExitable_TransitionActivation_Boolean->setUnique(true);
	m_vertexActivation_Operation_isExitable_TransitionActivation_Boolean->setOrdered(false);
	
	m_vertexActivation_Operation_isExitable_TransitionActivation_Boolean->_setID(VERTEXACTIVATION_OPERATION_ISEXITABLE_TRANSITIONACTIVATION_BOOLEAN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_vertexActivation_Operation_isExitable_TransitionActivation_Boolean);
		parameter->setName("exitingTransition");
		parameter->setEType(getTransitionActivation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_vertexActivation_Operation_isExitable_TransitionActivation_Boolean);
		parameter->setName("staticCheck");
		parameter->setEType(types::typesPackage::eInstance()->getBoolean_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_vertexActivation_Operation_tagIncomingTransition_TransitionMetadata_Boolean->setName("tagIncomingTransition");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_vertexActivation_Operation_tagIncomingTransition_TransitionMetadata_Boolean->setEType(unknownClass);
	}
	m_vertexActivation_Operation_tagIncomingTransition_TransitionMetadata_Boolean->setLowerBound(1);
	m_vertexActivation_Operation_tagIncomingTransition_TransitionMetadata_Boolean->setUpperBound(1);
	m_vertexActivation_Operation_tagIncomingTransition_TransitionMetadata_Boolean->setUnique(true);
	m_vertexActivation_Operation_tagIncomingTransition_TransitionMetadata_Boolean->setOrdered(false);
	
	m_vertexActivation_Operation_tagIncomingTransition_TransitionMetadata_Boolean->_setID(VERTEXACTIVATION_OPERATION_TAGINCOMINGTRANSITION_TRANSITIONMETADATA_BOOLEAN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_vertexActivation_Operation_tagIncomingTransition_TransitionMetadata_Boolean);
		parameter->setName("status");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_vertexActivation_Operation_tagIncomingTransition_TransitionMetadata_Boolean);
		parameter->setName("staticCheck");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_vertexActivation_Operation_tagOutgoingTransition_TransitionMetadata_Boolean->setName("tagOutgoingTransition");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_vertexActivation_Operation_tagOutgoingTransition_TransitionMetadata_Boolean->setEType(unknownClass);
	}
	m_vertexActivation_Operation_tagOutgoingTransition_TransitionMetadata_Boolean->setLowerBound(1);
	m_vertexActivation_Operation_tagOutgoingTransition_TransitionMetadata_Boolean->setUpperBound(1);
	m_vertexActivation_Operation_tagOutgoingTransition_TransitionMetadata_Boolean->setUnique(true);
	m_vertexActivation_Operation_tagOutgoingTransition_TransitionMetadata_Boolean->setOrdered(false);
	
	m_vertexActivation_Operation_tagOutgoingTransition_TransitionMetadata_Boolean->_setID(VERTEXACTIVATION_OPERATION_TAGOUTGOINGTRANSITION_TRANSITIONMETADATA_BOOLEAN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_vertexActivation_Operation_tagOutgoingTransition_TransitionMetadata_Boolean);
		parameter->setName("status");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_vertexActivation_Operation_tagOutgoingTransition_TransitionMetadata_Boolean);
		parameter->setName("staticCheck");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_vertexActivation_Operation_terminate->setName("terminate");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_vertexActivation_Operation_terminate->setEType(unknownClass);
	}
	m_vertexActivation_Operation_terminate->setLowerBound(1);
	m_vertexActivation_Operation_terminate->setUpperBound(1);
	m_vertexActivation_Operation_terminate->setUnique(true);
	m_vertexActivation_Operation_terminate->setOrdered(false);
	
	m_vertexActivation_Operation_terminate->_setID(VERTEXACTIVATION_OPERATION_TERMINATE);
	
	
	
}

void StateMachinesPackageImpl::initializePackageEDataTypes()
{
	m_stateMetadata_Class->setName("StateMetadata");
	m_transitionMetadata_Class->setName("TransitionMetadata");
	
}

