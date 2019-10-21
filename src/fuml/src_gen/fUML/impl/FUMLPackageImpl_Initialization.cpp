#include "fUML/impl/FUMLPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

// metametamodel factory
#include "ecore/EcoreFactory.hpp"

//depending model packages
#include "ecore/EcorePackage.hpp"
#include "types/TypesPackage.hpp"
#include "uml/UmlPackage.hpp"

using namespace fUML;

void FUMLPackageImpl::initializePackageContents()
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
	m_acceptEventActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_acceptEventActionEventAccepter_Class->getESuperTypes()->push_back(getEventAccepter_Class());
	m_actionActivation_Class->getESuperTypes()->push_back(getActivityNodeActivation_Class());
	m_activityExecution_Class->getESuperTypes()->push_back(getExecution_Class());
	m_activityFinalNodeActivation_Class->getESuperTypes()->push_back(getControlNodeActivation_Class());
	m_activityNodeActivation_Class->getESuperTypes()->push_back(getSemanticVisitor_Class());
	m_activityParameterNodeActivation_Class->getESuperTypes()->push_back(getObjectNodeActivation_Class());
	m_addStructuralFeatureValueActionActivation_Class->getESuperTypes()->push_back(getWriteStructuralFeatureActionActivation_Class());
	m_booleanValue_Class->getESuperTypes()->push_back(getPrimitiveValue_Class());
	m_callActionActivation_Class->getESuperTypes()->push_back(getInvocationActionActivation_Class());
	m_callBehaviorActionActivation_Class->getESuperTypes()->push_back(getCallActionActivation_Class());
	m_callEventExecution_Class->getESuperTypes()->push_back(getExecution_Class());
	m_callEventOccurrence_Class->getESuperTypes()->push_back(getEventOccurrence_Class());
	m_callOperationActionActivation_Class->getESuperTypes()->push_back(getCallActionActivation_Class());
	m_centralBufferNodeActivation_Class->getESuperTypes()->push_back(getObjectNodeActivation_Class());
	m_choiceStrategy_Class->getESuperTypes()->push_back(getSemanticStrategy_Class());
	m_clearAssociationActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_clearStructuralFeatureActionActivation_Class->getESuperTypes()->push_back(getStructuralFeatureActionActivation_Class());
	m_compoundValue_Class->getESuperTypes()->push_back(getStructuredValue_Class());
	m_conditionalNodeActivation_Class->getESuperTypes()->push_back(getStructuredActivityNodeActivation_Class());
	m_controlNodeActivation_Class->getESuperTypes()->push_back(getActivityNodeActivation_Class());
	m_controlToken_Class->getESuperTypes()->push_back(getToken_Class());
	m_createLinkActionActivation_Class->getESuperTypes()->push_back(getWriteLinkActionActivation_Class());
	m_createObjectActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_dataStoreNodeActivation_Class->getESuperTypes()->push_back(getCentralBufferNodeActivation_Class());
	m_dataValue_Class->getESuperTypes()->push_back(getCompoundValue_Class());
	m_decisionNodeActivation_Class->getESuperTypes()->push_back(getControlNodeActivation_Class());
	m_destroyLinkActionActivation_Class->getESuperTypes()->push_back(getWriteLinkActionActivation_Class());
	m_destroyObjectActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_dispatchStrategy_Class->getESuperTypes()->push_back(getSemanticStrategy_Class());
	m_enumerationValue_Class->getESuperTypes()->push_back(getValue_Class());
	m_evaluation_Class->getESuperTypes()->push_back(getSemanticVisitor_Class());
	m_execution_Class->getESuperTypes()->push_back(getObject_Class());
	m_executionFactoryL1_Class->getESuperTypes()->push_back(getExecutionFactory_Class());
	m_executionFactoryL2_Class->getESuperTypes()->push_back(getExecutionFactoryL1_Class());
	m_executionFactoryL3_Class->getESuperTypes()->push_back(getExecutionFactoryL2_Class());
	m_expansionActivationGroup_Class->getESuperTypes()->push_back(getActivityNodeActivationGroup_Class());
	m_expansionNodeActivation_Class->getESuperTypes()->push_back(getObjectNodeActivation_Class());
	m_expansionRegionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_extensionalValue_Class->getESuperTypes()->push_back(getCompoundValue_Class());
	m_extensionalValueList_Class->getESuperTypes()->push_back(getExtensionalValue_Class());
	m_fIFOGetNextEventStrategy_Class->getESuperTypes()->push_back(getGetNextEventStrategy_Class());
	m_firstChoiceStrategy_Class->getESuperTypes()->push_back(getChoiceStrategy_Class());
	m_flowFinalNodeActivation_Class->getESuperTypes()->push_back(getControlNodeActivation_Class());
	m_forkNodeActivation_Class->getESuperTypes()->push_back(getControlNodeActivation_Class());
	m_forkedToken_Class->getESuperTypes()->push_back(getToken_Class());
	m_getNextEventStrategy_Class->getESuperTypes()->push_back(getSemanticStrategy_Class());
	m_initialNodeActivation_Class->getESuperTypes()->push_back(getControlNodeActivation_Class());
	m_inputPinActivation_Class->getESuperTypes()->push_back(getPinActivation_Class());
	m_instanceValueEvaluation_Class->getESuperTypes()->push_back(getEvaluation_Class());
	m_integerValue_Class->getESuperTypes()->push_back(getPrimitiveValue_Class());
	m_invocationActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_joinNodeActivation_Class->getESuperTypes()->push_back(getControlNodeActivation_Class());
	m_link_Class->getESuperTypes()->push_back(getExtensionalValue_Class());
	m_linkActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_literalBooleanEvaluation_Class->getESuperTypes()->push_back(getLiteralEvaluation_Class());
	m_literalEvaluation_Class->getESuperTypes()->push_back(getEvaluation_Class());
	m_literalIntegerEvaluation_Class->getESuperTypes()->push_back(getLiteralEvaluation_Class());
	m_literalNullEvaluation_Class->getESuperTypes()->push_back(getLiteralEvaluation_Class());
	m_literalRealEvaluation_Class->getESuperTypes()->push_back(getLiteralEvaluation_Class());
	m_literalStringEvaluation_Class->getESuperTypes()->push_back(getLiteralEvaluation_Class());
	m_literalUnlimitedNaturalEvaluation_Class->getESuperTypes()->push_back(getLiteralEvaluation_Class());
	m_loopNodeActivation_Class->getESuperTypes()->push_back(getStructuredActivityNodeActivation_Class());
	m_mergeNodeActivation_Class->getESuperTypes()->push_back(getControlNodeActivation_Class());
	m_object_Class->getESuperTypes()->push_back(getExtensionalValue_Class());
	m_objectNodeActivation_Class->getESuperTypes()->push_back(getActivityNodeActivation_Class());
	m_objectToken_Class->getESuperTypes()->push_back(getToken_Class());
	m_opaqueBehaviorExecution_Class->getESuperTypes()->push_back(getExecution_Class());
	m_outputPinActivation_Class->getESuperTypes()->push_back(getPinActivation_Class());
	m_pinActivation_Class->getESuperTypes()->push_back(getObjectNodeActivation_Class());
	m_primitiveValue_Class->getESuperTypes()->push_back(getValue_Class());
	m_readExtentActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_readIsClassifiedObjectActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_readLinkActionActivation_Class->getESuperTypes()->push_back(getLinkActionActivation_Class());
	m_readSelfActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_readStructuralFeatureActionActivation_Class->getESuperTypes()->push_back(getStructuralFeatureActionActivation_Class());
	m_realValue_Class->getESuperTypes()->push_back(getPrimitiveValue_Class());
	m_reclassifyObjectActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_redefinitionBasedDispatchStrategy_Class->getESuperTypes()->push_back(getDispatchStrategy_Class());
	m_reduceActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_reference_Class->getESuperTypes()->push_back(getStructuredValue_Class());
	m_removeStructuralFeatureValueActivation_Class->getESuperTypes()->push_back(getWriteStructuralFeatureActionActivation_Class());
	m_sendSignalActionActivation_Class->getESuperTypes()->push_back(getInvocationActionActivation_Class());
	m_signalInstance_Class->getESuperTypes()->push_back(getCompoundValue_Class());
	m_startClassifierBehaviorActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_startObjectBehaviorActionActivation_Class->getESuperTypes()->push_back(getInvocationActionActivation_Class());
	m_stringValue_Class->getESuperTypes()->push_back(getPrimitiveValue_Class());
	m_structuralFeatureActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_structuredActivityNodeActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_structuredValue_Class->getESuperTypes()->push_back(getValue_Class());
	m_testIdentityActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_unlimitedNaturalValue_Class->getESuperTypes()->push_back(getPrimitiveValue_Class());
	m_value_Class->getESuperTypes()->push_back(getSemanticVisitor_Class());
	m_valueSpecificationActionActivation_Class->getESuperTypes()->push_back(getActionActivation_Class());
	m_writeLinkActionActivation_Class->getESuperTypes()->push_back(getLinkActionActivation_Class());
	m_writeStructuralFeatureActionActivation_Class->getESuperTypes()->push_back(getStructuralFeatureActionActivation_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeAcceptEventActionActivationContent();
	initializeAcceptEventActionEventAccepterContent();
	initializeActionActivationContent();
	initializeActivityEdgeInstanceContent();
	initializeActivityExecutionContent();
	initializeActivityFinalNodeActivationContent();
	initializeActivityNodeActivationContent();
	initializeActivityNodeActivationGroupContent();
	initializeActivityParameterNodeActivationContent();
	initializeAddStructuralFeatureValueActionActivationContent();
	initializeBooleanValueContent();
	initializeCallActionActivationContent();
	initializeCallBehaviorActionActivationContent();
	initializeCallEventBehaviorContent();
	initializeCallEventExecutionContent();
	initializeCallEventOccurrenceContent();
	initializeCallOperationActionActivationContent();
	initializeCentralBufferNodeActivationContent();
	initializeChoiceStrategyContent();
	initializeClassifierBehaviorExecutionContent();
	initializeClassifierBehaviorExecutionActivityContent();
	initializeClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Content();
	initializeClauseActivationContent();
	initializeClearAssociationActionActivationContent();
	initializeClearStructuralFeatureActionActivationContent();
	initializeCompoundValueContent();
	initializeConditionalNodeActivationContent();
	initializeControlNodeActivationContent();
	initializeControlTokenContent();
	initializeCreateLinkActionActivationContent();
	initializeCreateObjectActionActivationContent();
	initializeDataStoreNodeActivationContent();
	initializeDataValueContent();
	initializeDecisionNodeActivationContent();
	initializeDestroyLinkActionActivationContent();
	initializeDestroyObjectActionActivationContent();
	initializeDispatchStrategyContent();
	initializeEnumerationValueContent();
	initializeEvaluationContent();
	initializeEventAccepterContent();
	initializeEventDispatchLoopContent();
	initializeEventOccurrenceContent();
	initializeExecutionContent();
	initializeExecutionFactoryContent();
	initializeExecutionFactoryL1Content();
	initializeExecutionFactoryL2Content();
	initializeExecutionFactoryL3Content();
	initializeExecutorContent();
	initializeExpansionActivationGroupContent();
	initializeExpansionNodeActivationContent();
	initializeExpansionRegionActivationContent();
	initializeExtensionalValueContent();
	initializeExtensionalValueListContent();
	initializeFIFOGetNextEventStrategyContent();
	initializeFeatureValueContent();
	initializeFirstChoiceStrategyContent();
	initializeFlowFinalNodeActivationContent();
	initializeForkNodeActivationContent();
	initializeForkedTokenContent();
	initializeGetNextEventStrategyContent();
	initializeInitialNodeActivationContent();
	initializeInputPinActivationContent();
	initializeInstanceValueEvaluationContent();
	initializeIntegerValueContent();
	initializeInvocationActionActivationContent();
	initializeJoinNodeActivationContent();
	initializeLinkContent();
	initializeLinkActionActivationContent();
	initializeLiteralBooleanEvaluationContent();
	initializeLiteralEvaluationContent();
	initializeLiteralIntegerEvaluationContent();
	initializeLiteralNullEvaluationContent();
	initializeLiteralRealEvaluationContent();
	initializeLiteralStringEvaluationContent();
	initializeLiteralUnlimitedNaturalEvaluationContent();
	initializeLocusContent();
	initializeLoopNodeActivationContent();
	initializeMergeNodeActivationContent();
	initializeObjectContent();
	initializeObjectActivationContent();
	initializeObjectNodeActivationContent();
	initializeObjectTokenContent();
	initializeOfferContent();
	initializeOpaqueBehaviorExecutionContent();
	initializeOutputPinActivationContent();
	initializeParameterValueContent();
	initializePinActivationContent();
	initializePrimitiveValueContent();
	initializeReadExtentActionActivationContent();
	initializeReadIsClassifiedObjectActionActivationContent();
	initializeReadLinkActionActivationContent();
	initializeReadSelfActionActivationContent();
	initializeReadStructuralFeatureActionActivationContent();
	initializeRealValueContent();
	initializeReclassifyObjectActionActivationContent();
	initializeRedefinitionBasedDispatchStrategyContent();
	initializeReduceActionActivationContent();
	initializeReferenceContent();
	initializeRemoveStructuralFeatureValueActivationContent();
	initializeSemanticStrategyContent();
	initializeSemanticVisitorContent();
	initializeSendSignalActionActivationContent();
	initializeSignalInstanceContent();
	initializeStartClassifierBehaviorActionActivationContent();
	initializeStartObjectBehaviorActionActivationContent();
	initializeStringValueContent();
	initializeStructuralFeatureActionActivationContent();
	initializeStructuredActivityNodeActivationContent();
	initializeStructuredValueContent();
	initializeTestIdentityActionActivationContent();
	initializeTokenContent();
	initializeTokenSetContent();
	initializeUnlimitedNaturalValueContent();
	initializeValueContent();
	initializeValueSpecificationActionActivationContent();
	initializeValuesContent();
	initializeWriteLinkActionActivationContent();
	initializeWriteStructuralFeatureActionActivationContent();

	initializePackageEDataTypes();
}

void FUMLPackageImpl::initializeAcceptEventActionActivationContent()
{
	m_acceptEventActionActivation_Class->setName("AcceptEventActionActivation");
	m_acceptEventActionActivation_Class->setAbstract(false);
	m_acceptEventActionActivation_Class->setInterface(false);
	
	m_acceptEventActionActivation_Attribute_waiting = getAcceptEventActionActivation_Attribute_waiting();
	m_acceptEventActionActivation_Attribute_waiting->setName("waiting");
	m_acceptEventActionActivation_Attribute_waiting->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_acceptEventActionActivation_Attribute_waiting->setLowerBound(1);
	m_acceptEventActionActivation_Attribute_waiting->setUpperBound(1);
	m_acceptEventActionActivation_Attribute_waiting->setTransient(false);
	m_acceptEventActionActivation_Attribute_waiting->setVolatile(false);
	m_acceptEventActionActivation_Attribute_waiting->setChangeable(true);
	m_acceptEventActionActivation_Attribute_waiting->setUnsettable(false);
	m_acceptEventActionActivation_Attribute_waiting->setUnique(true);
	m_acceptEventActionActivation_Attribute_waiting->setDerived(false);
	m_acceptEventActionActivation_Attribute_waiting->setOrdered(false);
	m_acceptEventActionActivation_Attribute_waiting->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_acceptEventActionActivation_Attribute_waiting->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_acceptEventActionActivation_Attribute_eventAccepter->setName("eventAccepter");
	m_acceptEventActionActivation_Attribute_eventAccepter->setEType(getAcceptEventActionEventAccepter_Class());
	m_acceptEventActionActivation_Attribute_eventAccepter->setLowerBound(0);
	m_acceptEventActionActivation_Attribute_eventAccepter->setUpperBound(1);
	m_acceptEventActionActivation_Attribute_eventAccepter->setTransient(false);
	m_acceptEventActionActivation_Attribute_eventAccepter->setVolatile(false);
	m_acceptEventActionActivation_Attribute_eventAccepter->setChangeable(true);
	m_acceptEventActionActivation_Attribute_eventAccepter->setUnsettable(false);
	m_acceptEventActionActivation_Attribute_eventAccepter->setUnique(true);
	m_acceptEventActionActivation_Attribute_eventAccepter->setDerived(false);
	m_acceptEventActionActivation_Attribute_eventAccepter->setOrdered(false);
	m_acceptEventActionActivation_Attribute_eventAccepter->setContainment(false);
	m_acceptEventActionActivation_Attribute_eventAccepter->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_acceptEventActionActivation_Attribute_eventAccepter->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_acceptEventActionActivation_Attribute_eventAccepter->setEOpposite(otherEnd);
	    }
	}
	
	m_acceptEventActionActivation_Operation_accept_SignalInstance->setEType(nullptr);
	m_acceptEventActionActivation_Operation_accept_SignalInstance->setName("accept");
	m_acceptEventActionActivation_Operation_accept_SignalInstance->setLowerBound(1);
	m_acceptEventActionActivation_Operation_accept_SignalInstance->setUpperBound(1);
	m_acceptEventActionActivation_Operation_accept_SignalInstance->setUnique(true);
	m_acceptEventActionActivation_Operation_accept_SignalInstance->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_acceptEventActionActivation_Operation_accept_SignalInstance);
		parameter->setName("signalInstance");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_acceptEventActionActivation_Operation_match_SignalInstance->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_acceptEventActionActivation_Operation_match_SignalInstance->setName("match");
	m_acceptEventActionActivation_Operation_match_SignalInstance->setLowerBound(1);
	m_acceptEventActionActivation_Operation_match_SignalInstance->setUpperBound(1);
	m_acceptEventActionActivation_Operation_match_SignalInstance->setUnique(true);
	m_acceptEventActionActivation_Operation_match_SignalInstance->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_acceptEventActionActivation_Operation_match_SignalInstance);
		parameter->setName("signalInstance");
		parameter->setEType(getSignalInstance_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeAcceptEventActionEventAccepterContent()
{
	m_acceptEventActionEventAccepter_Class->setName("AcceptEventActionEventAccepter");
	m_acceptEventActionEventAccepter_Class->setAbstract(false);
	m_acceptEventActionEventAccepter_Class->setInterface(false);
	
	
	m_acceptEventActionEventAccepter_Attribute_actionActivation->setName("actionActivation");
	m_acceptEventActionEventAccepter_Attribute_actionActivation->setEType(getAcceptEventActionActivation_Class());
	m_acceptEventActionEventAccepter_Attribute_actionActivation->setLowerBound(1);
	m_acceptEventActionEventAccepter_Attribute_actionActivation->setUpperBound(1);
	m_acceptEventActionEventAccepter_Attribute_actionActivation->setTransient(false);
	m_acceptEventActionEventAccepter_Attribute_actionActivation->setVolatile(false);
	m_acceptEventActionEventAccepter_Attribute_actionActivation->setChangeable(true);
	m_acceptEventActionEventAccepter_Attribute_actionActivation->setUnsettable(false);
	m_acceptEventActionEventAccepter_Attribute_actionActivation->setUnique(true);
	m_acceptEventActionEventAccepter_Attribute_actionActivation->setDerived(false);
	m_acceptEventActionEventAccepter_Attribute_actionActivation->setOrdered(false);
	m_acceptEventActionEventAccepter_Attribute_actionActivation->setContainment(false);
	m_acceptEventActionEventAccepter_Attribute_actionActivation->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_acceptEventActionEventAccepter_Attribute_actionActivation->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_acceptEventActionEventAccepter_Attribute_actionActivation->setEOpposite(otherEnd);
	    }
	}
	
	
}

void FUMLPackageImpl::initializeActionActivationContent()
{
	m_actionActivation_Class->setName("ActionActivation");
	m_actionActivation_Class->setAbstract(true);
	m_actionActivation_Class->setInterface(false);
	
	m_actionActivation_Attribute_firing = getActionActivation_Attribute_firing();
	m_actionActivation_Attribute_firing->setName("firing");
	m_actionActivation_Attribute_firing->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_actionActivation_Attribute_firing->setLowerBound(1);
	m_actionActivation_Attribute_firing->setUpperBound(1);
	m_actionActivation_Attribute_firing->setTransient(false);
	m_actionActivation_Attribute_firing->setVolatile(false);
	m_actionActivation_Attribute_firing->setChangeable(true);
	m_actionActivation_Attribute_firing->setUnsettable(false);
	m_actionActivation_Attribute_firing->setUnique(true);
	m_actionActivation_Attribute_firing->setDerived(false);
	m_actionActivation_Attribute_firing->setOrdered(false);
	m_actionActivation_Attribute_firing->setID(false);
	{
		std::string defaultValue = "false";
		if (!defaultValue.empty())
		{
		   m_actionActivation_Attribute_firing->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_actionActivation_Attribute_inputPinActivation->setName("inputPinActivation");
	m_actionActivation_Attribute_inputPinActivation->setEType(getInputPinActivation_Class());
	m_actionActivation_Attribute_inputPinActivation->setLowerBound(0);
	m_actionActivation_Attribute_inputPinActivation->setUpperBound(-1);
	m_actionActivation_Attribute_inputPinActivation->setTransient(false);
	m_actionActivation_Attribute_inputPinActivation->setVolatile(false);
	m_actionActivation_Attribute_inputPinActivation->setChangeable(true);
	m_actionActivation_Attribute_inputPinActivation->setUnsettable(false);
	m_actionActivation_Attribute_inputPinActivation->setUnique(true);
	m_actionActivation_Attribute_inputPinActivation->setDerived(false);
	m_actionActivation_Attribute_inputPinActivation->setOrdered(false);
	m_actionActivation_Attribute_inputPinActivation->setContainment(false);
	m_actionActivation_Attribute_inputPinActivation->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_actionActivation_Attribute_inputPinActivation->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_actionActivation_Attribute_inputPinActivation->setEOpposite(otherEnd);
	    }
	}
	m_actionActivation_Attribute_outputPinActivation->setName("outputPinActivation");
	m_actionActivation_Attribute_outputPinActivation->setEType(getOutputPinActivation_Class());
	m_actionActivation_Attribute_outputPinActivation->setLowerBound(0);
	m_actionActivation_Attribute_outputPinActivation->setUpperBound(-1);
	m_actionActivation_Attribute_outputPinActivation->setTransient(false);
	m_actionActivation_Attribute_outputPinActivation->setVolatile(false);
	m_actionActivation_Attribute_outputPinActivation->setChangeable(true);
	m_actionActivation_Attribute_outputPinActivation->setUnsettable(false);
	m_actionActivation_Attribute_outputPinActivation->setUnique(true);
	m_actionActivation_Attribute_outputPinActivation->setDerived(false);
	m_actionActivation_Attribute_outputPinActivation->setOrdered(false);
	m_actionActivation_Attribute_outputPinActivation->setContainment(false);
	m_actionActivation_Attribute_outputPinActivation->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_actionActivation_Attribute_outputPinActivation->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_actionActivation_Attribute_outputPinActivation->setEOpposite(otherEnd);
	    }
	}
	m_actionActivation_Attribute_pinActivation->setName("pinActivation");
	m_actionActivation_Attribute_pinActivation->setEType(getPinActivation_Class());
	m_actionActivation_Attribute_pinActivation->setLowerBound(0);
	m_actionActivation_Attribute_pinActivation->setUpperBound(-1);
	m_actionActivation_Attribute_pinActivation->setTransient(false);
	m_actionActivation_Attribute_pinActivation->setVolatile(false);
	m_actionActivation_Attribute_pinActivation->setChangeable(true);
	m_actionActivation_Attribute_pinActivation->setUnsettable(false);
	m_actionActivation_Attribute_pinActivation->setUnique(true);
	m_actionActivation_Attribute_pinActivation->setDerived(false);
	m_actionActivation_Attribute_pinActivation->setOrdered(false);
	m_actionActivation_Attribute_pinActivation->setContainment(false);
	m_actionActivation_Attribute_pinActivation->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_actionActivation_Attribute_pinActivation->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getPinActivation_Attribute_actionActivation();
		if (otherEnd != nullptr)
	    {
	   		m_actionActivation_Attribute_pinActivation->setEOpposite(otherEnd);
	    }
	}
	
	m_actionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setEType(nullptr);
	m_actionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setName("addOutgoingEdge");
	m_actionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setLowerBound(1);
	m_actionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setUpperBound(1);
	m_actionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setUnique(true);
	m_actionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_Operation_addOutgoingEdge_ActivityEdgeInstance);
		parameter->setName("edge");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_Operation_addPinActivation_PinActivation->setEType(nullptr);
	m_actionActivation_Operation_addPinActivation_PinActivation->setName("addPinActivation");
	m_actionActivation_Operation_addPinActivation_PinActivation->setLowerBound(1);
	m_actionActivation_Operation_addPinActivation_PinActivation->setUpperBound(1);
	m_actionActivation_Operation_addPinActivation_PinActivation->setUnique(true);
	m_actionActivation_Operation_addPinActivation_PinActivation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_Operation_addPinActivation_PinActivation);
		parameter->setName("pinActivation");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_Operation_completeAction->setEType(getToken_Class());
	m_actionActivation_Operation_completeAction->setName("completeAction");
	m_actionActivation_Operation_completeAction->setLowerBound(0);
	m_actionActivation_Operation_completeAction->setUpperBound(-1);
	m_actionActivation_Operation_completeAction->setUnique(true);
	m_actionActivation_Operation_completeAction->setOrdered(false);
	
	
	m_actionActivation_Operation_createNodeActivations->setEType(nullptr);
	m_actionActivation_Operation_createNodeActivations->setName("createNodeActivations");
	m_actionActivation_Operation_createNodeActivations->setLowerBound(1);
	m_actionActivation_Operation_createNodeActivations->setUpperBound(1);
	m_actionActivation_Operation_createNodeActivations->setUnique(true);
	m_actionActivation_Operation_createNodeActivations->setOrdered(false);
	
	
	m_actionActivation_Operation_doAction->setEType(nullptr);
	m_actionActivation_Operation_doAction->setName("doAction");
	m_actionActivation_Operation_doAction->setLowerBound(1);
	m_actionActivation_Operation_doAction->setUpperBound(1);
	m_actionActivation_Operation_doAction->setUnique(true);
	m_actionActivation_Operation_doAction->setOrdered(false);
	
	
	m_actionActivation_Operation_fire_Token->setEType(nullptr);
	m_actionActivation_Operation_fire_Token->setName("fire");
	m_actionActivation_Operation_fire_Token->setLowerBound(1);
	m_actionActivation_Operation_fire_Token->setUpperBound(1);
	m_actionActivation_Operation_fire_Token->setUnique(true);
	m_actionActivation_Operation_fire_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_Operation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_Operation_getTokens_InputPin->setEType(getValue_Class());
	m_actionActivation_Operation_getTokens_InputPin->setName("getTokens");
	m_actionActivation_Operation_getTokens_InputPin->setLowerBound(0);
	m_actionActivation_Operation_getTokens_InputPin->setUpperBound(-1);
	m_actionActivation_Operation_getTokens_InputPin->setUnique(true);
	m_actionActivation_Operation_getTokens_InputPin->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_Operation_getTokens_InputPin);
		parameter->setName("pin");
		parameter->setEType(uml::UmlPackage::eInstance()->getInputPin_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_Operation_isFirng->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_actionActivation_Operation_isFirng->setName("isFirng");
	m_actionActivation_Operation_isFirng->setLowerBound(1);
	m_actionActivation_Operation_isFirng->setUpperBound(1);
	m_actionActivation_Operation_isFirng->setUnique(true);
	m_actionActivation_Operation_isFirng->setOrdered(false);
	
	
	m_actionActivation_Operation_isReady->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_actionActivation_Operation_isReady->setName("isReady");
	m_actionActivation_Operation_isReady->setLowerBound(1);
	m_actionActivation_Operation_isReady->setUpperBound(1);
	m_actionActivation_Operation_isReady->setUnique(true);
	m_actionActivation_Operation_isReady->setOrdered(false);
	
	
	m_actionActivation_Operation_isSourceFor_ActivityEdgeInstance->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_actionActivation_Operation_isSourceFor_ActivityEdgeInstance->setName("isSourceFor");
	m_actionActivation_Operation_isSourceFor_ActivityEdgeInstance->setLowerBound(1);
	m_actionActivation_Operation_isSourceFor_ActivityEdgeInstance->setUpperBound(1);
	m_actionActivation_Operation_isSourceFor_ActivityEdgeInstance->setUnique(true);
	m_actionActivation_Operation_isSourceFor_ActivityEdgeInstance->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_Operation_isSourceFor_ActivityEdgeInstance);
		parameter->setName("edgeInstance");
		parameter->setEType(getActivityEdgeInstance_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_Operation_makeBooleanValue_EBoolean->setEType(getBooleanValue_Class());
	m_actionActivation_Operation_makeBooleanValue_EBoolean->setName("makeBooleanValue");
	m_actionActivation_Operation_makeBooleanValue_EBoolean->setLowerBound(1);
	m_actionActivation_Operation_makeBooleanValue_EBoolean->setUpperBound(1);
	m_actionActivation_Operation_makeBooleanValue_EBoolean->setUnique(true);
	m_actionActivation_Operation_makeBooleanValue_EBoolean->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_Operation_makeBooleanValue_EBoolean);
		parameter->setName("value");
		parameter->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_Operation_putToken_OutputPin_Value->setEType(nullptr);
	m_actionActivation_Operation_putToken_OutputPin_Value->setName("putToken");
	m_actionActivation_Operation_putToken_OutputPin_Value->setLowerBound(1);
	m_actionActivation_Operation_putToken_OutputPin_Value->setUpperBound(1);
	m_actionActivation_Operation_putToken_OutputPin_Value->setUnique(true);
	m_actionActivation_Operation_putToken_OutputPin_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_Operation_putToken_OutputPin_Value);
		parameter->setName("pin");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_Operation_putToken_OutputPin_Value);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_Operation_putTokens_OutputPin_Value->setEType(nullptr);
	m_actionActivation_Operation_putTokens_OutputPin_Value->setName("putTokens");
	m_actionActivation_Operation_putTokens_OutputPin_Value->setLowerBound(1);
	m_actionActivation_Operation_putTokens_OutputPin_Value->setUpperBound(1);
	m_actionActivation_Operation_putTokens_OutputPin_Value->setUnique(true);
	m_actionActivation_Operation_putTokens_OutputPin_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_Operation_putTokens_OutputPin_Value);
		parameter->setName("pin");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_Operation_putTokens_OutputPin_Value);
		parameter->setName("values");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_Operation_retrievePinActivation_Pin->setEType(getPinActivation_Class());
	m_actionActivation_Operation_retrievePinActivation_Pin->setName("retrievePinActivation");
	m_actionActivation_Operation_retrievePinActivation_Pin->setLowerBound(1);
	m_actionActivation_Operation_retrievePinActivation_Pin->setUpperBound(1);
	m_actionActivation_Operation_retrievePinActivation_Pin->setUnique(true);
	m_actionActivation_Operation_retrievePinActivation_Pin->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_Operation_retrievePinActivation_Pin);
		parameter->setName("pin");
		parameter->setEType(uml::UmlPackage::eInstance()->getPin_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_Operation_run->setEType(nullptr);
	m_actionActivation_Operation_run->setName("run");
	m_actionActivation_Operation_run->setLowerBound(1);
	m_actionActivation_Operation_run->setUpperBound(1);
	m_actionActivation_Operation_run->setUnique(true);
	m_actionActivation_Operation_run->setOrdered(false);
	
	
	m_actionActivation_Operation_sendOffers->setEType(nullptr);
	m_actionActivation_Operation_sendOffers->setName("sendOffers");
	m_actionActivation_Operation_sendOffers->setLowerBound(1);
	m_actionActivation_Operation_sendOffers->setUpperBound(1);
	m_actionActivation_Operation_sendOffers->setUnique(true);
	m_actionActivation_Operation_sendOffers->setOrdered(false);
	
	
	m_actionActivation_Operation_takeOfferedTokens->setEType(getToken_Class());
	m_actionActivation_Operation_takeOfferedTokens->setName("takeOfferedTokens");
	m_actionActivation_Operation_takeOfferedTokens->setLowerBound(0);
	m_actionActivation_Operation_takeOfferedTokens->setUpperBound(-1);
	m_actionActivation_Operation_takeOfferedTokens->setUnique(true);
	m_actionActivation_Operation_takeOfferedTokens->setOrdered(false);
	
	
	m_actionActivation_Operation_takeTokens_InputPin->setEType(getValue_Class());
	m_actionActivation_Operation_takeTokens_InputPin->setName("takeTokens");
	m_actionActivation_Operation_takeTokens_InputPin->setLowerBound(0);
	m_actionActivation_Operation_takeTokens_InputPin->setUpperBound(-1);
	m_actionActivation_Operation_takeTokens_InputPin->setUnique(true);
	m_actionActivation_Operation_takeTokens_InputPin->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_Operation_takeTokens_InputPin);
		parameter->setName("pin");
		parameter->setEType(uml::UmlPackage::eInstance()->getInputPin_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_actionActivation_Operation_terminate->setEType(nullptr);
	m_actionActivation_Operation_terminate->setName("terminate");
	m_actionActivation_Operation_terminate->setLowerBound(1);
	m_actionActivation_Operation_terminate->setUpperBound(1);
	m_actionActivation_Operation_terminate->setUnique(true);
	m_actionActivation_Operation_terminate->setOrdered(false);
	
	
	m_actionActivation_Operation_valueParticipatesInLink_Value_Link->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_actionActivation_Operation_valueParticipatesInLink_Value_Link->setName("valueParticipatesInLink");
	m_actionActivation_Operation_valueParticipatesInLink_Value_Link->setLowerBound(1);
	m_actionActivation_Operation_valueParticipatesInLink_Value_Link->setUpperBound(1);
	m_actionActivation_Operation_valueParticipatesInLink_Value_Link->setUnique(true);
	m_actionActivation_Operation_valueParticipatesInLink_Value_Link->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_Operation_valueParticipatesInLink_Value_Link);
		parameter->setName("value");
		parameter->setEType(getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_actionActivation_Operation_valueParticipatesInLink_Value_Link);
		parameter->setName("link");
		parameter->setEType(getLink_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeActivityEdgeInstanceContent()
{
	m_activityEdgeInstance_Class->setName("ActivityEdgeInstance");
	m_activityEdgeInstance_Class->setAbstract(false);
	m_activityEdgeInstance_Class->setInterface(false);
	
	
	m_activityEdgeInstance_Attribute_edge->setName("edge");
	m_activityEdgeInstance_Attribute_edge->setEType(uml::UmlPackage::eInstance()->getActivityEdge_Class());
	m_activityEdgeInstance_Attribute_edge->setLowerBound(0);
	m_activityEdgeInstance_Attribute_edge->setUpperBound(1);
	m_activityEdgeInstance_Attribute_edge->setTransient(false);
	m_activityEdgeInstance_Attribute_edge->setVolatile(false);
	m_activityEdgeInstance_Attribute_edge->setChangeable(true);
	m_activityEdgeInstance_Attribute_edge->setUnsettable(false);
	m_activityEdgeInstance_Attribute_edge->setUnique(true);
	m_activityEdgeInstance_Attribute_edge->setDerived(false);
	m_activityEdgeInstance_Attribute_edge->setOrdered(false);
	m_activityEdgeInstance_Attribute_edge->setContainment(false);
	m_activityEdgeInstance_Attribute_edge->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityEdgeInstance_Attribute_edge->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_activityEdgeInstance_Attribute_edge->setEOpposite(otherEnd);
	    }
	}
	m_activityEdgeInstance_Attribute_group->setName("group");
	m_activityEdgeInstance_Attribute_group->setEType(getActivityNodeActivationGroup_Class());
	m_activityEdgeInstance_Attribute_group->setLowerBound(1);
	m_activityEdgeInstance_Attribute_group->setUpperBound(1);
	m_activityEdgeInstance_Attribute_group->setTransient(false);
	m_activityEdgeInstance_Attribute_group->setVolatile(false);
	m_activityEdgeInstance_Attribute_group->setChangeable(true);
	m_activityEdgeInstance_Attribute_group->setUnsettable(false);
	m_activityEdgeInstance_Attribute_group->setUnique(true);
	m_activityEdgeInstance_Attribute_group->setDerived(false);
	m_activityEdgeInstance_Attribute_group->setOrdered(false);
	m_activityEdgeInstance_Attribute_group->setContainment(false);
	m_activityEdgeInstance_Attribute_group->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityEdgeInstance_Attribute_group->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getActivityNodeActivationGroup_Attribute_edgeInstances();
		if (otherEnd != nullptr)
	    {
	   		m_activityEdgeInstance_Attribute_group->setEOpposite(otherEnd);
	    }
	}
	m_activityEdgeInstance_Attribute_offers->setName("offers");
	m_activityEdgeInstance_Attribute_offers->setEType(getOffer_Class());
	m_activityEdgeInstance_Attribute_offers->setLowerBound(0);
	m_activityEdgeInstance_Attribute_offers->setUpperBound(-1);
	m_activityEdgeInstance_Attribute_offers->setTransient(false);
	m_activityEdgeInstance_Attribute_offers->setVolatile(false);
	m_activityEdgeInstance_Attribute_offers->setChangeable(true);
	m_activityEdgeInstance_Attribute_offers->setUnsettable(false);
	m_activityEdgeInstance_Attribute_offers->setUnique(true);
	m_activityEdgeInstance_Attribute_offers->setDerived(false);
	m_activityEdgeInstance_Attribute_offers->setOrdered(false);
	m_activityEdgeInstance_Attribute_offers->setContainment(false);
	m_activityEdgeInstance_Attribute_offers->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityEdgeInstance_Attribute_offers->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_activityEdgeInstance_Attribute_offers->setEOpposite(otherEnd);
	    }
	}
	m_activityEdgeInstance_Attribute_source->setName("source");
	m_activityEdgeInstance_Attribute_source->setEType(getActivityNodeActivation_Class());
	m_activityEdgeInstance_Attribute_source->setLowerBound(1);
	m_activityEdgeInstance_Attribute_source->setUpperBound(1);
	m_activityEdgeInstance_Attribute_source->setTransient(false);
	m_activityEdgeInstance_Attribute_source->setVolatile(false);
	m_activityEdgeInstance_Attribute_source->setChangeable(true);
	m_activityEdgeInstance_Attribute_source->setUnsettable(false);
	m_activityEdgeInstance_Attribute_source->setUnique(true);
	m_activityEdgeInstance_Attribute_source->setDerived(false);
	m_activityEdgeInstance_Attribute_source->setOrdered(false);
	m_activityEdgeInstance_Attribute_source->setContainment(false);
	m_activityEdgeInstance_Attribute_source->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityEdgeInstance_Attribute_source->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getActivityNodeActivation_Attribute_outgoingEdges();
		if (otherEnd != nullptr)
	    {
	   		m_activityEdgeInstance_Attribute_source->setEOpposite(otherEnd);
	    }
	}
	m_activityEdgeInstance_Attribute_target->setName("target");
	m_activityEdgeInstance_Attribute_target->setEType(getActivityNodeActivation_Class());
	m_activityEdgeInstance_Attribute_target->setLowerBound(1);
	m_activityEdgeInstance_Attribute_target->setUpperBound(1);
	m_activityEdgeInstance_Attribute_target->setTransient(false);
	m_activityEdgeInstance_Attribute_target->setVolatile(false);
	m_activityEdgeInstance_Attribute_target->setChangeable(true);
	m_activityEdgeInstance_Attribute_target->setUnsettable(false);
	m_activityEdgeInstance_Attribute_target->setUnique(true);
	m_activityEdgeInstance_Attribute_target->setDerived(false);
	m_activityEdgeInstance_Attribute_target->setOrdered(false);
	m_activityEdgeInstance_Attribute_target->setContainment(false);
	m_activityEdgeInstance_Attribute_target->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityEdgeInstance_Attribute_target->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getActivityNodeActivation_Attribute_incomingEdges();
		if (otherEnd != nullptr)
	    {
	   		m_activityEdgeInstance_Attribute_target->setEOpposite(otherEnd);
	    }
	}
	
	m_activityEdgeInstance_Operation_countOfferedValue->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
	m_activityEdgeInstance_Operation_countOfferedValue->setName("countOfferedValue");
	m_activityEdgeInstance_Operation_countOfferedValue->setLowerBound(1);
	m_activityEdgeInstance_Operation_countOfferedValue->setUpperBound(1);
	m_activityEdgeInstance_Operation_countOfferedValue->setUnique(true);
	m_activityEdgeInstance_Operation_countOfferedValue->setOrdered(false);
	
	
	m_activityEdgeInstance_Operation_getOfferedTokens->setEType(getToken_Class());
	m_activityEdgeInstance_Operation_getOfferedTokens->setName("getOfferedTokens");
	m_activityEdgeInstance_Operation_getOfferedTokens->setLowerBound(0);
	m_activityEdgeInstance_Operation_getOfferedTokens->setUpperBound(-1);
	m_activityEdgeInstance_Operation_getOfferedTokens->setUnique(true);
	m_activityEdgeInstance_Operation_getOfferedTokens->setOrdered(false);
	
	
	m_activityEdgeInstance_Operation_hasOffer->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_activityEdgeInstance_Operation_hasOffer->setName("hasOffer");
	m_activityEdgeInstance_Operation_hasOffer->setLowerBound(1);
	m_activityEdgeInstance_Operation_hasOffer->setUpperBound(1);
	m_activityEdgeInstance_Operation_hasOffer->setUnique(true);
	m_activityEdgeInstance_Operation_hasOffer->setOrdered(false);
	
	
	m_activityEdgeInstance_Operation_sendOffer_Token->setEType(nullptr);
	m_activityEdgeInstance_Operation_sendOffer_Token->setName("sendOffer");
	m_activityEdgeInstance_Operation_sendOffer_Token->setLowerBound(1);
	m_activityEdgeInstance_Operation_sendOffer_Token->setUpperBound(1);
	m_activityEdgeInstance_Operation_sendOffer_Token->setUnique(true);
	m_activityEdgeInstance_Operation_sendOffer_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityEdgeInstance_Operation_sendOffer_Token);
		parameter->setName("tokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityEdgeInstance_Operation_takeOfferedTokens->setEType(getToken_Class());
	m_activityEdgeInstance_Operation_takeOfferedTokens->setName("takeOfferedTokens");
	m_activityEdgeInstance_Operation_takeOfferedTokens->setLowerBound(0);
	m_activityEdgeInstance_Operation_takeOfferedTokens->setUpperBound(-1);
	m_activityEdgeInstance_Operation_takeOfferedTokens->setUnique(true);
	m_activityEdgeInstance_Operation_takeOfferedTokens->setOrdered(false);
	
	
	m_activityEdgeInstance_Operation_takeOfferedTokens_EInt->setEType(getToken_Class());
	m_activityEdgeInstance_Operation_takeOfferedTokens_EInt->setName("takeOfferedTokens");
	m_activityEdgeInstance_Operation_takeOfferedTokens_EInt->setLowerBound(0);
	m_activityEdgeInstance_Operation_takeOfferedTokens_EInt->setUpperBound(-1);
	m_activityEdgeInstance_Operation_takeOfferedTokens_EInt->setUnique(true);
	m_activityEdgeInstance_Operation_takeOfferedTokens_EInt->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityEdgeInstance_Operation_takeOfferedTokens_EInt);
		parameter->setName("maxCount");
		parameter->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeActivityExecutionContent()
{
	m_activityExecution_Class->setName("ActivityExecution");
	m_activityExecution_Class->setAbstract(false);
	m_activityExecution_Class->setInterface(false);
	
	
	m_activityExecution_Attribute_activationGroup->setName("activationGroup");
	m_activityExecution_Attribute_activationGroup->setEType(getActivityNodeActivationGroup_Class());
	m_activityExecution_Attribute_activationGroup->setLowerBound(1);
	m_activityExecution_Attribute_activationGroup->setUpperBound(1);
	m_activityExecution_Attribute_activationGroup->setTransient(false);
	m_activityExecution_Attribute_activationGroup->setVolatile(false);
	m_activityExecution_Attribute_activationGroup->setChangeable(true);
	m_activityExecution_Attribute_activationGroup->setUnsettable(false);
	m_activityExecution_Attribute_activationGroup->setUnique(true);
	m_activityExecution_Attribute_activationGroup->setDerived(false);
	m_activityExecution_Attribute_activationGroup->setOrdered(false);
	m_activityExecution_Attribute_activationGroup->setContainment(true);
	m_activityExecution_Attribute_activationGroup->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityExecution_Attribute_activationGroup->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getActivityNodeActivationGroup_Attribute_activityExecution();
		if (otherEnd != nullptr)
	    {
	   		m_activityExecution_Attribute_activationGroup->setEOpposite(otherEnd);
	    }
	}
	
	m_activityExecution_Operation_execute->setEType(nullptr);
	m_activityExecution_Operation_execute->setName("execute");
	m_activityExecution_Operation_execute->setLowerBound(1);
	m_activityExecution_Operation_execute->setUpperBound(1);
	m_activityExecution_Operation_execute->setUnique(true);
	m_activityExecution_Operation_execute->setOrdered(false);
	
	
	m_activityExecution_Operation_new_->setEType(getValue_Class());
	m_activityExecution_Operation_new_->setName("new_");
	m_activityExecution_Operation_new_->setLowerBound(1);
	m_activityExecution_Operation_new_->setUpperBound(1);
	m_activityExecution_Operation_new_->setUnique(true);
	m_activityExecution_Operation_new_->setOrdered(false);
	
	
	m_activityExecution_Operation_terminate->setEType(nullptr);
	m_activityExecution_Operation_terminate->setName("terminate");
	m_activityExecution_Operation_terminate->setLowerBound(1);
	m_activityExecution_Operation_terminate->setUpperBound(1);
	m_activityExecution_Operation_terminate->setUnique(true);
	m_activityExecution_Operation_terminate->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeActivityFinalNodeActivationContent()
{
	m_activityFinalNodeActivation_Class->setName("ActivityFinalNodeActivation");
	m_activityFinalNodeActivation_Class->setAbstract(false);
	m_activityFinalNodeActivation_Class->setInterface(false);
	
	
	
	m_activityFinalNodeActivation_Operation_fire_Token->setEType(nullptr);
	m_activityFinalNodeActivation_Operation_fire_Token->setName("fire");
	m_activityFinalNodeActivation_Operation_fire_Token->setLowerBound(1);
	m_activityFinalNodeActivation_Operation_fire_Token->setUpperBound(1);
	m_activityFinalNodeActivation_Operation_fire_Token->setUnique(true);
	m_activityFinalNodeActivation_Operation_fire_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityFinalNodeActivation_Operation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeActivityNodeActivationContent()
{
	m_activityNodeActivation_Class->setName("ActivityNodeActivation");
	m_activityNodeActivation_Class->setAbstract(true);
	m_activityNodeActivation_Class->setInterface(false);
	
	m_activityNodeActivation_Attribute_running = getActivityNodeActivation_Attribute_running();
	m_activityNodeActivation_Attribute_running->setName("running");
	m_activityNodeActivation_Attribute_running->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_activityNodeActivation_Attribute_running->setLowerBound(1);
	m_activityNodeActivation_Attribute_running->setUpperBound(1);
	m_activityNodeActivation_Attribute_running->setTransient(false);
	m_activityNodeActivation_Attribute_running->setVolatile(false);
	m_activityNodeActivation_Attribute_running->setChangeable(true);
	m_activityNodeActivation_Attribute_running->setUnsettable(false);
	m_activityNodeActivation_Attribute_running->setUnique(true);
	m_activityNodeActivation_Attribute_running->setDerived(false);
	m_activityNodeActivation_Attribute_running->setOrdered(false);
	m_activityNodeActivation_Attribute_running->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_activityNodeActivation_Attribute_running->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_activityNodeActivation_Attribute_group->setName("group");
	m_activityNodeActivation_Attribute_group->setEType(getActivityNodeActivationGroup_Class());
	m_activityNodeActivation_Attribute_group->setLowerBound(1);
	m_activityNodeActivation_Attribute_group->setUpperBound(1);
	m_activityNodeActivation_Attribute_group->setTransient(false);
	m_activityNodeActivation_Attribute_group->setVolatile(false);
	m_activityNodeActivation_Attribute_group->setChangeable(true);
	m_activityNodeActivation_Attribute_group->setUnsettable(false);
	m_activityNodeActivation_Attribute_group->setUnique(true);
	m_activityNodeActivation_Attribute_group->setDerived(false);
	m_activityNodeActivation_Attribute_group->setOrdered(false);
	m_activityNodeActivation_Attribute_group->setContainment(false);
	m_activityNodeActivation_Attribute_group->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityNodeActivation_Attribute_group->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getActivityNodeActivationGroup_Attribute_nodeActivations();
		if (otherEnd != nullptr)
	    {
	   		m_activityNodeActivation_Attribute_group->setEOpposite(otherEnd);
	    }
	}
	m_activityNodeActivation_Attribute_heldTokens->setName("heldTokens");
	m_activityNodeActivation_Attribute_heldTokens->setEType(getToken_Class());
	m_activityNodeActivation_Attribute_heldTokens->setLowerBound(0);
	m_activityNodeActivation_Attribute_heldTokens->setUpperBound(-1);
	m_activityNodeActivation_Attribute_heldTokens->setTransient(false);
	m_activityNodeActivation_Attribute_heldTokens->setVolatile(false);
	m_activityNodeActivation_Attribute_heldTokens->setChangeable(true);
	m_activityNodeActivation_Attribute_heldTokens->setUnsettable(false);
	m_activityNodeActivation_Attribute_heldTokens->setUnique(true);
	m_activityNodeActivation_Attribute_heldTokens->setDerived(false);
	m_activityNodeActivation_Attribute_heldTokens->setOrdered(false);
	m_activityNodeActivation_Attribute_heldTokens->setContainment(true);
	m_activityNodeActivation_Attribute_heldTokens->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityNodeActivation_Attribute_heldTokens->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getToken_Attribute_holder();
		if (otherEnd != nullptr)
	    {
	   		m_activityNodeActivation_Attribute_heldTokens->setEOpposite(otherEnd);
	    }
	}
	m_activityNodeActivation_Attribute_incomingEdges->setName("incomingEdges");
	m_activityNodeActivation_Attribute_incomingEdges->setEType(getActivityEdgeInstance_Class());
	m_activityNodeActivation_Attribute_incomingEdges->setLowerBound(0);
	m_activityNodeActivation_Attribute_incomingEdges->setUpperBound(-1);
	m_activityNodeActivation_Attribute_incomingEdges->setTransient(false);
	m_activityNodeActivation_Attribute_incomingEdges->setVolatile(false);
	m_activityNodeActivation_Attribute_incomingEdges->setChangeable(true);
	m_activityNodeActivation_Attribute_incomingEdges->setUnsettable(false);
	m_activityNodeActivation_Attribute_incomingEdges->setUnique(true);
	m_activityNodeActivation_Attribute_incomingEdges->setDerived(false);
	m_activityNodeActivation_Attribute_incomingEdges->setOrdered(false);
	m_activityNodeActivation_Attribute_incomingEdges->setContainment(false);
	m_activityNodeActivation_Attribute_incomingEdges->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityNodeActivation_Attribute_incomingEdges->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getActivityEdgeInstance_Attribute_target();
		if (otherEnd != nullptr)
	    {
	   		m_activityNodeActivation_Attribute_incomingEdges->setEOpposite(otherEnd);
	    }
	}
	m_activityNodeActivation_Attribute_node->setName("node");
	m_activityNodeActivation_Attribute_node->setEType(uml::UmlPackage::eInstance()->getActivityNode_Class());
	m_activityNodeActivation_Attribute_node->setLowerBound(0);
	m_activityNodeActivation_Attribute_node->setUpperBound(1);
	m_activityNodeActivation_Attribute_node->setTransient(false);
	m_activityNodeActivation_Attribute_node->setVolatile(false);
	m_activityNodeActivation_Attribute_node->setChangeable(true);
	m_activityNodeActivation_Attribute_node->setUnsettable(false);
	m_activityNodeActivation_Attribute_node->setUnique(true);
	m_activityNodeActivation_Attribute_node->setDerived(false);
	m_activityNodeActivation_Attribute_node->setOrdered(false);
	m_activityNodeActivation_Attribute_node->setContainment(false);
	m_activityNodeActivation_Attribute_node->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityNodeActivation_Attribute_node->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_activityNodeActivation_Attribute_node->setEOpposite(otherEnd);
	    }
	}
	m_activityNodeActivation_Attribute_outgoingEdges->setName("outgoingEdges");
	m_activityNodeActivation_Attribute_outgoingEdges->setEType(getActivityEdgeInstance_Class());
	m_activityNodeActivation_Attribute_outgoingEdges->setLowerBound(0);
	m_activityNodeActivation_Attribute_outgoingEdges->setUpperBound(-1);
	m_activityNodeActivation_Attribute_outgoingEdges->setTransient(false);
	m_activityNodeActivation_Attribute_outgoingEdges->setVolatile(false);
	m_activityNodeActivation_Attribute_outgoingEdges->setChangeable(true);
	m_activityNodeActivation_Attribute_outgoingEdges->setUnsettable(false);
	m_activityNodeActivation_Attribute_outgoingEdges->setUnique(true);
	m_activityNodeActivation_Attribute_outgoingEdges->setDerived(false);
	m_activityNodeActivation_Attribute_outgoingEdges->setOrdered(false);
	m_activityNodeActivation_Attribute_outgoingEdges->setContainment(false);
	m_activityNodeActivation_Attribute_outgoingEdges->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityNodeActivation_Attribute_outgoingEdges->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getActivityEdgeInstance_Attribute_source();
		if (otherEnd != nullptr)
	    {
	   		m_activityNodeActivation_Attribute_outgoingEdges->setEOpposite(otherEnd);
	    }
	}
	
	m_activityNodeActivation_Operation_addIncomingEdge_ActivityEdgeInstance->setEType(nullptr);
	m_activityNodeActivation_Operation_addIncomingEdge_ActivityEdgeInstance->setName("addIncomingEdge");
	m_activityNodeActivation_Operation_addIncomingEdge_ActivityEdgeInstance->setLowerBound(1);
	m_activityNodeActivation_Operation_addIncomingEdge_ActivityEdgeInstance->setUpperBound(1);
	m_activityNodeActivation_Operation_addIncomingEdge_ActivityEdgeInstance->setUnique(true);
	m_activityNodeActivation_Operation_addIncomingEdge_ActivityEdgeInstance->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivation_Operation_addIncomingEdge_ActivityEdgeInstance);
		parameter->setName("edge");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setEType(nullptr);
	m_activityNodeActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setName("addOutgoingEdge");
	m_activityNodeActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setLowerBound(1);
	m_activityNodeActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setUpperBound(1);
	m_activityNodeActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setUnique(true);
	m_activityNodeActivation_Operation_addOutgoingEdge_ActivityEdgeInstance->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivation_Operation_addOutgoingEdge_ActivityEdgeInstance);
		parameter->setName("edge");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivation_Operation_addToken_Token->setEType(nullptr);
	m_activityNodeActivation_Operation_addToken_Token->setName("addToken");
	m_activityNodeActivation_Operation_addToken_Token->setLowerBound(1);
	m_activityNodeActivation_Operation_addToken_Token->setUpperBound(1);
	m_activityNodeActivation_Operation_addToken_Token->setUnique(true);
	m_activityNodeActivation_Operation_addToken_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivation_Operation_addToken_Token);
		parameter->setName("token");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivation_Operation_addTokens_Token->setEType(nullptr);
	m_activityNodeActivation_Operation_addTokens_Token->setName("addTokens");
	m_activityNodeActivation_Operation_addTokens_Token->setLowerBound(1);
	m_activityNodeActivation_Operation_addTokens_Token->setUpperBound(1);
	m_activityNodeActivation_Operation_addTokens_Token->setUnique(true);
	m_activityNodeActivation_Operation_addTokens_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivation_Operation_addTokens_Token);
		parameter->setName("tokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivation_Operation_clearTokens->setEType(nullptr);
	m_activityNodeActivation_Operation_clearTokens->setName("clearTokens");
	m_activityNodeActivation_Operation_clearTokens->setLowerBound(1);
	m_activityNodeActivation_Operation_clearTokens->setUpperBound(1);
	m_activityNodeActivation_Operation_clearTokens->setUnique(true);
	m_activityNodeActivation_Operation_clearTokens->setOrdered(false);
	
	
	m_activityNodeActivation_Operation_createEdgeInstances->setEType(nullptr);
	m_activityNodeActivation_Operation_createEdgeInstances->setName("createEdgeInstances");
	m_activityNodeActivation_Operation_createEdgeInstances->setLowerBound(1);
	m_activityNodeActivation_Operation_createEdgeInstances->setUpperBound(1);
	m_activityNodeActivation_Operation_createEdgeInstances->setUnique(true);
	m_activityNodeActivation_Operation_createEdgeInstances->setOrdered(false);
	
	
	m_activityNodeActivation_Operation_createNodeActivations->setEType(nullptr);
	m_activityNodeActivation_Operation_createNodeActivations->setName("createNodeActivations");
	m_activityNodeActivation_Operation_createNodeActivations->setLowerBound(1);
	m_activityNodeActivation_Operation_createNodeActivations->setUpperBound(1);
	m_activityNodeActivation_Operation_createNodeActivations->setUnique(true);
	m_activityNodeActivation_Operation_createNodeActivations->setOrdered(false);
	
	
	m_activityNodeActivation_Operation_fire_Token->setEType(nullptr);
	m_activityNodeActivation_Operation_fire_Token->setName("fire");
	m_activityNodeActivation_Operation_fire_Token->setLowerBound(1);
	m_activityNodeActivation_Operation_fire_Token->setUpperBound(1);
	m_activityNodeActivation_Operation_fire_Token->setUnique(true);
	m_activityNodeActivation_Operation_fire_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivation_Operation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivation_Operation_getActivityExecution->setEType(getActivityExecution_Class());
	m_activityNodeActivation_Operation_getActivityExecution->setName("getActivityExecution");
	m_activityNodeActivation_Operation_getActivityExecution->setLowerBound(1);
	m_activityNodeActivation_Operation_getActivityExecution->setUpperBound(1);
	m_activityNodeActivation_Operation_getActivityExecution->setUnique(true);
	m_activityNodeActivation_Operation_getActivityExecution->setOrdered(false);
	
	
	m_activityNodeActivation_Operation_getExecutionContext->setEType(getObject_Class());
	m_activityNodeActivation_Operation_getExecutionContext->setName("getExecutionContext");
	m_activityNodeActivation_Operation_getExecutionContext->setLowerBound(1);
	m_activityNodeActivation_Operation_getExecutionContext->setUpperBound(1);
	m_activityNodeActivation_Operation_getExecutionContext->setUnique(true);
	m_activityNodeActivation_Operation_getExecutionContext->setOrdered(false);
	
	
	m_activityNodeActivation_Operation_getExecutionLocus->setEType(getLocus_Class());
	m_activityNodeActivation_Operation_getExecutionLocus->setName("getExecutionLocus");
	m_activityNodeActivation_Operation_getExecutionLocus->setLowerBound(1);
	m_activityNodeActivation_Operation_getExecutionLocus->setUpperBound(1);
	m_activityNodeActivation_Operation_getExecutionLocus->setUnique(true);
	m_activityNodeActivation_Operation_getExecutionLocus->setOrdered(false);
	
	
	m_activityNodeActivation_Operation_getNodeActivation_ActivityNode->setEType(getActivityNodeActivation_Class());
	m_activityNodeActivation_Operation_getNodeActivation_ActivityNode->setName("getNodeActivation");
	m_activityNodeActivation_Operation_getNodeActivation_ActivityNode->setLowerBound(1);
	m_activityNodeActivation_Operation_getNodeActivation_ActivityNode->setUpperBound(1);
	m_activityNodeActivation_Operation_getNodeActivation_ActivityNode->setUnique(true);
	m_activityNodeActivation_Operation_getNodeActivation_ActivityNode->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivation_Operation_getNodeActivation_ActivityNode);
		parameter->setName("node");
		parameter->setEType(uml::UmlPackage::eInstance()->getActivityNode_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivation_Operation_getRunning->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_activityNodeActivation_Operation_getRunning->setName("getRunning");
	m_activityNodeActivation_Operation_getRunning->setLowerBound(1);
	m_activityNodeActivation_Operation_getRunning->setUpperBound(1);
	m_activityNodeActivation_Operation_getRunning->setUnique(true);
	m_activityNodeActivation_Operation_getRunning->setOrdered(false);
	
	
	m_activityNodeActivation_Operation_getTokens->setEType(getToken_Class());
	m_activityNodeActivation_Operation_getTokens->setName("getTokens");
	m_activityNodeActivation_Operation_getTokens->setLowerBound(0);
	m_activityNodeActivation_Operation_getTokens->setUpperBound(-1);
	m_activityNodeActivation_Operation_getTokens->setUnique(true);
	m_activityNodeActivation_Operation_getTokens->setOrdered(false);
	
	
	m_activityNodeActivation_Operation_isReady->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_activityNodeActivation_Operation_isReady->setName("isReady");
	m_activityNodeActivation_Operation_isReady->setLowerBound(1);
	m_activityNodeActivation_Operation_isReady->setUpperBound(1);
	m_activityNodeActivation_Operation_isReady->setUnique(true);
	m_activityNodeActivation_Operation_isReady->setOrdered(false);
	
	
	m_activityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_activityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setName("isSourceFor");
	m_activityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setLowerBound(1);
	m_activityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setUpperBound(1);
	m_activityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setUnique(true);
	m_activityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance);
		parameter->setName("edgeInstances");
		parameter->setEType(getActivityEdgeInstance_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivation_Operation_recieveOffer->setEType(nullptr);
	m_activityNodeActivation_Operation_recieveOffer->setName("recieveOffer");
	m_activityNodeActivation_Operation_recieveOffer->setLowerBound(1);
	m_activityNodeActivation_Operation_recieveOffer->setUpperBound(1);
	m_activityNodeActivation_Operation_recieveOffer->setUnique(true);
	m_activityNodeActivation_Operation_recieveOffer->setOrdered(false);
	
	
	m_activityNodeActivation_Operation_removeToken_Token->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
	m_activityNodeActivation_Operation_removeToken_Token->setName("removeToken");
	m_activityNodeActivation_Operation_removeToken_Token->setLowerBound(1);
	m_activityNodeActivation_Operation_removeToken_Token->setUpperBound(1);
	m_activityNodeActivation_Operation_removeToken_Token->setUnique(true);
	m_activityNodeActivation_Operation_removeToken_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivation_Operation_removeToken_Token);
		parameter->setName("token");
		parameter->setEType(getToken_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivation_Operation_resume->setEType(nullptr);
	m_activityNodeActivation_Operation_resume->setName("resume");
	m_activityNodeActivation_Operation_resume->setLowerBound(1);
	m_activityNodeActivation_Operation_resume->setUpperBound(1);
	m_activityNodeActivation_Operation_resume->setUnique(true);
	m_activityNodeActivation_Operation_resume->setOrdered(false);
	
	
	m_activityNodeActivation_Operation_run->setEType(nullptr);
	m_activityNodeActivation_Operation_run->setName("run");
	m_activityNodeActivation_Operation_run->setLowerBound(1);
	m_activityNodeActivation_Operation_run->setUpperBound(1);
	m_activityNodeActivation_Operation_run->setUnique(true);
	m_activityNodeActivation_Operation_run->setOrdered(false);
	
	
	m_activityNodeActivation_Operation_sendOffers_Token->setEType(nullptr);
	m_activityNodeActivation_Operation_sendOffers_Token->setName("sendOffers");
	m_activityNodeActivation_Operation_sendOffers_Token->setLowerBound(0);
	m_activityNodeActivation_Operation_sendOffers_Token->setUpperBound(1);
	m_activityNodeActivation_Operation_sendOffers_Token->setUnique(true);
	m_activityNodeActivation_Operation_sendOffers_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivation_Operation_sendOffers_Token);
		parameter->setName("tokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivation_Operation_suspend->setEType(nullptr);
	m_activityNodeActivation_Operation_suspend->setName("suspend");
	m_activityNodeActivation_Operation_suspend->setLowerBound(1);
	m_activityNodeActivation_Operation_suspend->setUpperBound(1);
	m_activityNodeActivation_Operation_suspend->setUnique(true);
	m_activityNodeActivation_Operation_suspend->setOrdered(false);
	
	
	m_activityNodeActivation_Operation_takeOfferedTokens->setEType(getToken_Class());
	m_activityNodeActivation_Operation_takeOfferedTokens->setName("takeOfferedTokens");
	m_activityNodeActivation_Operation_takeOfferedTokens->setLowerBound(0);
	m_activityNodeActivation_Operation_takeOfferedTokens->setUpperBound(-1);
	m_activityNodeActivation_Operation_takeOfferedTokens->setUnique(true);
	m_activityNodeActivation_Operation_takeOfferedTokens->setOrdered(false);
	
	
	m_activityNodeActivation_Operation_takeTokens->setEType(getToken_Class());
	m_activityNodeActivation_Operation_takeTokens->setName("takeTokens");
	m_activityNodeActivation_Operation_takeTokens->setLowerBound(1);
	m_activityNodeActivation_Operation_takeTokens->setUpperBound(-1);
	m_activityNodeActivation_Operation_takeTokens->setUnique(true);
	m_activityNodeActivation_Operation_takeTokens->setOrdered(false);
	
	
	m_activityNodeActivation_Operation_terminate->setEType(nullptr);
	m_activityNodeActivation_Operation_terminate->setName("terminate");
	m_activityNodeActivation_Operation_terminate->setLowerBound(1);
	m_activityNodeActivation_Operation_terminate->setUpperBound(1);
	m_activityNodeActivation_Operation_terminate->setUnique(true);
	m_activityNodeActivation_Operation_terminate->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeActivityNodeActivationGroupContent()
{
	m_activityNodeActivationGroup_Class->setName("ActivityNodeActivationGroup");
	m_activityNodeActivationGroup_Class->setAbstract(false);
	m_activityNodeActivationGroup_Class->setInterface(false);
	
	
	m_activityNodeActivationGroup_Attribute_activityExecution->setName("activityExecution");
	m_activityNodeActivationGroup_Attribute_activityExecution->setEType(getActivityExecution_Class());
	m_activityNodeActivationGroup_Attribute_activityExecution->setLowerBound(0);
	m_activityNodeActivationGroup_Attribute_activityExecution->setUpperBound(1);
	m_activityNodeActivationGroup_Attribute_activityExecution->setTransient(false);
	m_activityNodeActivationGroup_Attribute_activityExecution->setVolatile(false);
	m_activityNodeActivationGroup_Attribute_activityExecution->setChangeable(true);
	m_activityNodeActivationGroup_Attribute_activityExecution->setUnsettable(false);
	m_activityNodeActivationGroup_Attribute_activityExecution->setUnique(true);
	m_activityNodeActivationGroup_Attribute_activityExecution->setDerived(false);
	m_activityNodeActivationGroup_Attribute_activityExecution->setOrdered(true);
	m_activityNodeActivationGroup_Attribute_activityExecution->setContainment(false);
	m_activityNodeActivationGroup_Attribute_activityExecution->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityNodeActivationGroup_Attribute_activityExecution->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getActivityExecution_Attribute_activationGroup();
		if (otherEnd != nullptr)
	    {
	   		m_activityNodeActivationGroup_Attribute_activityExecution->setEOpposite(otherEnd);
	    }
	}
	m_activityNodeActivationGroup_Attribute_containingNodeActivation->setName("containingNodeActivation");
	m_activityNodeActivationGroup_Attribute_containingNodeActivation->setEType(getStructuredActivityNodeActivation_Class());
	m_activityNodeActivationGroup_Attribute_containingNodeActivation->setLowerBound(0);
	m_activityNodeActivationGroup_Attribute_containingNodeActivation->setUpperBound(1);
	m_activityNodeActivationGroup_Attribute_containingNodeActivation->setTransient(false);
	m_activityNodeActivationGroup_Attribute_containingNodeActivation->setVolatile(false);
	m_activityNodeActivationGroup_Attribute_containingNodeActivation->setChangeable(true);
	m_activityNodeActivationGroup_Attribute_containingNodeActivation->setUnsettable(false);
	m_activityNodeActivationGroup_Attribute_containingNodeActivation->setUnique(true);
	m_activityNodeActivationGroup_Attribute_containingNodeActivation->setDerived(false);
	m_activityNodeActivationGroup_Attribute_containingNodeActivation->setOrdered(false);
	m_activityNodeActivationGroup_Attribute_containingNodeActivation->setContainment(false);
	m_activityNodeActivationGroup_Attribute_containingNodeActivation->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityNodeActivationGroup_Attribute_containingNodeActivation->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getStructuredActivityNodeActivation_Attribute_activationGroup();
		if (otherEnd != nullptr)
	    {
	   		m_activityNodeActivationGroup_Attribute_containingNodeActivation->setEOpposite(otherEnd);
	    }
	}
	m_activityNodeActivationGroup_Attribute_edgeInstances->setName("edgeInstances");
	m_activityNodeActivationGroup_Attribute_edgeInstances->setEType(getActivityEdgeInstance_Class());
	m_activityNodeActivationGroup_Attribute_edgeInstances->setLowerBound(0);
	m_activityNodeActivationGroup_Attribute_edgeInstances->setUpperBound(-1);
	m_activityNodeActivationGroup_Attribute_edgeInstances->setTransient(false);
	m_activityNodeActivationGroup_Attribute_edgeInstances->setVolatile(false);
	m_activityNodeActivationGroup_Attribute_edgeInstances->setChangeable(true);
	m_activityNodeActivationGroup_Attribute_edgeInstances->setUnsettable(false);
	m_activityNodeActivationGroup_Attribute_edgeInstances->setUnique(true);
	m_activityNodeActivationGroup_Attribute_edgeInstances->setDerived(false);
	m_activityNodeActivationGroup_Attribute_edgeInstances->setOrdered(false);
	m_activityNodeActivationGroup_Attribute_edgeInstances->setContainment(true);
	m_activityNodeActivationGroup_Attribute_edgeInstances->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityNodeActivationGroup_Attribute_edgeInstances->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getActivityEdgeInstance_Attribute_group();
		if (otherEnd != nullptr)
	    {
	   		m_activityNodeActivationGroup_Attribute_edgeInstances->setEOpposite(otherEnd);
	    }
	}
	m_activityNodeActivationGroup_Attribute_nodeActivations->setName("nodeActivations");
	m_activityNodeActivationGroup_Attribute_nodeActivations->setEType(getActivityNodeActivation_Class());
	m_activityNodeActivationGroup_Attribute_nodeActivations->setLowerBound(0);
	m_activityNodeActivationGroup_Attribute_nodeActivations->setUpperBound(-1);
	m_activityNodeActivationGroup_Attribute_nodeActivations->setTransient(false);
	m_activityNodeActivationGroup_Attribute_nodeActivations->setVolatile(false);
	m_activityNodeActivationGroup_Attribute_nodeActivations->setChangeable(true);
	m_activityNodeActivationGroup_Attribute_nodeActivations->setUnsettable(false);
	m_activityNodeActivationGroup_Attribute_nodeActivations->setUnique(true);
	m_activityNodeActivationGroup_Attribute_nodeActivations->setDerived(false);
	m_activityNodeActivationGroup_Attribute_nodeActivations->setOrdered(false);
	m_activityNodeActivationGroup_Attribute_nodeActivations->setContainment(true);
	m_activityNodeActivationGroup_Attribute_nodeActivations->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityNodeActivationGroup_Attribute_nodeActivations->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getActivityNodeActivation_Attribute_group();
		if (otherEnd != nullptr)
	    {
	   		m_activityNodeActivationGroup_Attribute_nodeActivations->setEOpposite(otherEnd);
	    }
	}
	m_activityNodeActivationGroup_Attribute_suspendedActivations->setName("suspendedActivations");
	m_activityNodeActivationGroup_Attribute_suspendedActivations->setEType(getActivityNodeActivation_Class());
	m_activityNodeActivationGroup_Attribute_suspendedActivations->setLowerBound(0);
	m_activityNodeActivationGroup_Attribute_suspendedActivations->setUpperBound(-1);
	m_activityNodeActivationGroup_Attribute_suspendedActivations->setTransient(false);
	m_activityNodeActivationGroup_Attribute_suspendedActivations->setVolatile(false);
	m_activityNodeActivationGroup_Attribute_suspendedActivations->setChangeable(true);
	m_activityNodeActivationGroup_Attribute_suspendedActivations->setUnsettable(false);
	m_activityNodeActivationGroup_Attribute_suspendedActivations->setUnique(true);
	m_activityNodeActivationGroup_Attribute_suspendedActivations->setDerived(false);
	m_activityNodeActivationGroup_Attribute_suspendedActivations->setOrdered(false);
	m_activityNodeActivationGroup_Attribute_suspendedActivations->setContainment(false);
	m_activityNodeActivationGroup_Attribute_suspendedActivations->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_activityNodeActivationGroup_Attribute_suspendedActivations->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_activityNodeActivationGroup_Attribute_suspendedActivations->setEOpposite(otherEnd);
	    }
	}
	
	m_activityNodeActivationGroup_Operation_activate_ActivityNode_ActivityEdge->setEType(nullptr);
	m_activityNodeActivationGroup_Operation_activate_ActivityNode_ActivityEdge->setName("activate");
	m_activityNodeActivationGroup_Operation_activate_ActivityNode_ActivityEdge->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_activate_ActivityNode_ActivityEdge->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_activate_ActivityNode_ActivityEdge->setUnique(true);
	m_activityNodeActivationGroup_Operation_activate_ActivityNode_ActivityEdge->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_Operation_activate_ActivityNode_ActivityEdge);
		parameter->setName("nodes");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_Operation_activate_ActivityNode_ActivityEdge);
		parameter->setName("edges");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_Operation_addEdgeInstance_ActivityEdgeInstance->setEType(nullptr);
	m_activityNodeActivationGroup_Operation_addEdgeInstance_ActivityEdgeInstance->setName("addEdgeInstance");
	m_activityNodeActivationGroup_Operation_addEdgeInstance_ActivityEdgeInstance->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_addEdgeInstance_ActivityEdgeInstance->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_addEdgeInstance_ActivityEdgeInstance->setUnique(true);
	m_activityNodeActivationGroup_Operation_addEdgeInstance_ActivityEdgeInstance->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_Operation_addEdgeInstance_ActivityEdgeInstance);
		parameter->setName("instance");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_Operation_addNodeActivation_ActivityNodeActivation->setEType(nullptr);
	m_activityNodeActivationGroup_Operation_addNodeActivation_ActivityNodeActivation->setName("addNodeActivation");
	m_activityNodeActivationGroup_Operation_addNodeActivation_ActivityNodeActivation->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_addNodeActivation_ActivityNodeActivation->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_addNodeActivation_ActivityNodeActivation->setUnique(true);
	m_activityNodeActivationGroup_Operation_addNodeActivation_ActivityNodeActivation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_Operation_addNodeActivation_ActivityNodeActivation);
		parameter->setName("activation");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_Operation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_activityNodeActivationGroup_Operation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation->setName("checkIncomingEdges");
	m_activityNodeActivationGroup_Operation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation->setUnique(true);
	m_activityNodeActivationGroup_Operation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_Operation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation);
		parameter->setName("incomingEdges");
		parameter->setEType(getActivityEdgeInstance_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_Operation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation);
		parameter->setName("activations");
		parameter->setEType(getActivityNodeActivation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_Operation_createEdgeInstance_ActivityEdge->setEType(nullptr);
	m_activityNodeActivationGroup_Operation_createEdgeInstance_ActivityEdge->setName("createEdgeInstance");
	m_activityNodeActivationGroup_Operation_createEdgeInstance_ActivityEdge->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_createEdgeInstance_ActivityEdge->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_createEdgeInstance_ActivityEdge->setUnique(true);
	m_activityNodeActivationGroup_Operation_createEdgeInstance_ActivityEdge->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_Operation_createEdgeInstance_ActivityEdge);
		parameter->setName("edges");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_Operation_createNodeActivation_ActivityNode->setEType(getActivityNodeActivation_Class());
	m_activityNodeActivationGroup_Operation_createNodeActivation_ActivityNode->setName("createNodeActivation");
	m_activityNodeActivationGroup_Operation_createNodeActivation_ActivityNode->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_createNodeActivation_ActivityNode->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_createNodeActivation_ActivityNode->setUnique(true);
	m_activityNodeActivationGroup_Operation_createNodeActivation_ActivityNode->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_Operation_createNodeActivation_ActivityNode);
		parameter->setName("node");
		parameter->setEType(uml::UmlPackage::eInstance()->getActivityNode_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_Operation_createNodeActivations_ActivityNode->setEType(nullptr);
	m_activityNodeActivationGroup_Operation_createNodeActivations_ActivityNode->setName("createNodeActivations");
	m_activityNodeActivationGroup_Operation_createNodeActivations_ActivityNode->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_createNodeActivations_ActivityNode->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_createNodeActivations_ActivityNode->setUnique(true);
	m_activityNodeActivationGroup_Operation_createNodeActivations_ActivityNode->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_Operation_createNodeActivations_ActivityNode);
		parameter->setName("nodes");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_Operation_getNodeActivation_ActivityNode->setEType(getActivityNodeActivation_Class());
	m_activityNodeActivationGroup_Operation_getNodeActivation_ActivityNode->setName("getNodeActivation");
	m_activityNodeActivationGroup_Operation_getNodeActivation_ActivityNode->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_getNodeActivation_ActivityNode->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_getNodeActivation_ActivityNode->setUnique(true);
	m_activityNodeActivationGroup_Operation_getNodeActivation_ActivityNode->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_Operation_getNodeActivation_ActivityNode);
		parameter->setName("node");
		parameter->setEType(uml::UmlPackage::eInstance()->getActivityNode_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_Operation_getOutputParameterNodeActivations->setEType(getActivityParameterNodeActivation_Class());
	m_activityNodeActivationGroup_Operation_getOutputParameterNodeActivations->setName("getOutputParameterNodeActivations");
	m_activityNodeActivationGroup_Operation_getOutputParameterNodeActivations->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_getOutputParameterNodeActivations->setUpperBound(-1);
	m_activityNodeActivationGroup_Operation_getOutputParameterNodeActivations->setUnique(true);
	m_activityNodeActivationGroup_Operation_getOutputParameterNodeActivations->setOrdered(false);
	
	
	m_activityNodeActivationGroup_Operation_hasSourceFor_ActivityEdgeInstance->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_activityNodeActivationGroup_Operation_hasSourceFor_ActivityEdgeInstance->setName("hasSourceFor");
	m_activityNodeActivationGroup_Operation_hasSourceFor_ActivityEdgeInstance->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_hasSourceFor_ActivityEdgeInstance->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_hasSourceFor_ActivityEdgeInstance->setUnique(true);
	m_activityNodeActivationGroup_Operation_hasSourceFor_ActivityEdgeInstance->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_Operation_hasSourceFor_ActivityEdgeInstance);
		parameter->setName("edgeInstance");
		parameter->setEType(getActivityEdgeInstance_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_Operation_isSuspended->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_activityNodeActivationGroup_Operation_isSuspended->setName("isSuspended");
	m_activityNodeActivationGroup_Operation_isSuspended->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_isSuspended->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_isSuspended->setUnique(true);
	m_activityNodeActivationGroup_Operation_isSuspended->setOrdered(false);
	
	
	m_activityNodeActivationGroup_Operation_resume_ActivityNodeActivation->setEType(nullptr);
	m_activityNodeActivationGroup_Operation_resume_ActivityNodeActivation->setName("resume");
	m_activityNodeActivationGroup_Operation_resume_ActivityNodeActivation->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_resume_ActivityNodeActivation->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_resume_ActivityNodeActivation->setUnique(true);
	m_activityNodeActivationGroup_Operation_resume_ActivityNodeActivation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_Operation_resume_ActivityNodeActivation);
		parameter->setName("activation");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_Operation_retrieveActivityExecution->setEType(getActivityExecution_Class());
	m_activityNodeActivationGroup_Operation_retrieveActivityExecution->setName("retrieveActivityExecution");
	m_activityNodeActivationGroup_Operation_retrieveActivityExecution->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_retrieveActivityExecution->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_retrieveActivityExecution->setUnique(true);
	m_activityNodeActivationGroup_Operation_retrieveActivityExecution->setOrdered(false);
	
	
	m_activityNodeActivationGroup_Operation_run_ActivityNodeActivation->setEType(nullptr);
	m_activityNodeActivationGroup_Operation_run_ActivityNodeActivation->setName("run");
	m_activityNodeActivationGroup_Operation_run_ActivityNodeActivation->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_run_ActivityNodeActivation->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_run_ActivityNodeActivation->setUnique(true);
	m_activityNodeActivationGroup_Operation_run_ActivityNodeActivation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_Operation_run_ActivityNodeActivation);
		parameter->setName("activations");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_Operation_runNodes_ActivityNode->setEType(nullptr);
	m_activityNodeActivationGroup_Operation_runNodes_ActivityNode->setName("runNodes");
	m_activityNodeActivationGroup_Operation_runNodes_ActivityNode->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_runNodes_ActivityNode->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_runNodes_ActivityNode->setUnique(true);
	m_activityNodeActivationGroup_Operation_runNodes_ActivityNode->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_Operation_runNodes_ActivityNode);
		parameter->setName("nodes");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_Operation_suspend_ActivityNodeActivation->setEType(nullptr);
	m_activityNodeActivationGroup_Operation_suspend_ActivityNodeActivation->setName("suspend");
	m_activityNodeActivationGroup_Operation_suspend_ActivityNodeActivation->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_suspend_ActivityNodeActivation->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_suspend_ActivityNodeActivation->setUnique(true);
	m_activityNodeActivationGroup_Operation_suspend_ActivityNodeActivation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityNodeActivationGroup_Operation_suspend_ActivityNodeActivation);
		parameter->setName("activation");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_activityNodeActivationGroup_Operation_terminateAll->setEType(nullptr);
	m_activityNodeActivationGroup_Operation_terminateAll->setName("terminateAll");
	m_activityNodeActivationGroup_Operation_terminateAll->setLowerBound(1);
	m_activityNodeActivationGroup_Operation_terminateAll->setUpperBound(1);
	m_activityNodeActivationGroup_Operation_terminateAll->setUnique(true);
	m_activityNodeActivationGroup_Operation_terminateAll->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeActivityParameterNodeActivationContent()
{
	m_activityParameterNodeActivation_Class->setName("ActivityParameterNodeActivation");
	m_activityParameterNodeActivation_Class->setAbstract(false);
	m_activityParameterNodeActivation_Class->setInterface(false);
	
	
	
	m_activityParameterNodeActivation_Operation_clearTokens->setEType(nullptr);
	m_activityParameterNodeActivation_Operation_clearTokens->setName("clearTokens");
	m_activityParameterNodeActivation_Operation_clearTokens->setLowerBound(1);
	m_activityParameterNodeActivation_Operation_clearTokens->setUpperBound(1);
	m_activityParameterNodeActivation_Operation_clearTokens->setUnique(true);
	m_activityParameterNodeActivation_Operation_clearTokens->setOrdered(false);
	
	
	m_activityParameterNodeActivation_Operation_fire_Token->setEType(nullptr);
	m_activityParameterNodeActivation_Operation_fire_Token->setName("fire");
	m_activityParameterNodeActivation_Operation_fire_Token->setLowerBound(1);
	m_activityParameterNodeActivation_Operation_fire_Token->setUpperBound(1);
	m_activityParameterNodeActivation_Operation_fire_Token->setUnique(true);
	m_activityParameterNodeActivation_Operation_fire_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_activityParameterNodeActivation_Operation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeAddStructuralFeatureValueActionActivationContent()
{
	m_addStructuralFeatureValueActionActivation_Class->setName("AddStructuralFeatureValueActionActivation");
	m_addStructuralFeatureValueActionActivation_Class->setAbstract(false);
	m_addStructuralFeatureValueActionActivation_Class->setInterface(false);
	
	
	
	m_addStructuralFeatureValueActionActivation_Operation_doAction->setEType(nullptr);
	m_addStructuralFeatureValueActionActivation_Operation_doAction->setName("doAction");
	m_addStructuralFeatureValueActionActivation_Operation_doAction->setLowerBound(0);
	m_addStructuralFeatureValueActionActivation_Operation_doAction->setUpperBound(1);
	m_addStructuralFeatureValueActionActivation_Operation_doAction->setUnique(true);
	m_addStructuralFeatureValueActionActivation_Operation_doAction->setOrdered(true);
	
	
	
}

void FUMLPackageImpl::initializeBooleanValueContent()
{
	m_booleanValue_Class->setName("BooleanValue");
	m_booleanValue_Class->setAbstract(false);
	m_booleanValue_Class->setInterface(false);
	
	m_booleanValue_Attribute_value = getBooleanValue_Attribute_value();
	m_booleanValue_Attribute_value->setName("value");
	m_booleanValue_Attribute_value->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_booleanValue_Attribute_value->setLowerBound(1);
	m_booleanValue_Attribute_value->setUpperBound(1);
	m_booleanValue_Attribute_value->setTransient(false);
	m_booleanValue_Attribute_value->setVolatile(false);
	m_booleanValue_Attribute_value->setChangeable(true);
	m_booleanValue_Attribute_value->setUnsettable(false);
	m_booleanValue_Attribute_value->setUnique(true);
	m_booleanValue_Attribute_value->setDerived(false);
	m_booleanValue_Attribute_value->setOrdered(false);
	m_booleanValue_Attribute_value->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_booleanValue_Attribute_value->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	m_booleanValue_Operation_equals_Value->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_booleanValue_Operation_equals_Value->setName("equals");
	m_booleanValue_Operation_equals_Value->setLowerBound(1);
	m_booleanValue_Operation_equals_Value->setUpperBound(1);
	m_booleanValue_Operation_equals_Value->setUnique(true);
	m_booleanValue_Operation_equals_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_booleanValue_Operation_equals_Value);
		parameter->setName("otherValue");
		parameter->setEType(getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_booleanValue_Operation_specify->setEType(uml::UmlPackage::eInstance()->getValueSpecification_Class());
	m_booleanValue_Operation_specify->setName("specify");
	m_booleanValue_Operation_specify->setLowerBound(1);
	m_booleanValue_Operation_specify->setUpperBound(1);
	m_booleanValue_Operation_specify->setUnique(true);
	m_booleanValue_Operation_specify->setOrdered(false);
	
	
	m_booleanValue_Operation_toString->setEType(ecore::EcorePackage::eInstance()->getEString_Class());
	m_booleanValue_Operation_toString->setName("toString");
	m_booleanValue_Operation_toString->setLowerBound(1);
	m_booleanValue_Operation_toString->setUpperBound(1);
	m_booleanValue_Operation_toString->setUnique(true);
	m_booleanValue_Operation_toString->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeCallActionActivationContent()
{
	m_callActionActivation_Class->setName("CallActionActivation");
	m_callActionActivation_Class->setAbstract(true);
	m_callActionActivation_Class->setInterface(false);
	
	
	m_callActionActivation_Attribute_callExecutions->setName("callExecutions");
	m_callActionActivation_Attribute_callExecutions->setEType(getExecution_Class());
	m_callActionActivation_Attribute_callExecutions->setLowerBound(0);
	m_callActionActivation_Attribute_callExecutions->setUpperBound(-1);
	m_callActionActivation_Attribute_callExecutions->setTransient(false);
	m_callActionActivation_Attribute_callExecutions->setVolatile(false);
	m_callActionActivation_Attribute_callExecutions->setChangeable(true);
	m_callActionActivation_Attribute_callExecutions->setUnsettable(false);
	m_callActionActivation_Attribute_callExecutions->setUnique(true);
	m_callActionActivation_Attribute_callExecutions->setDerived(false);
	m_callActionActivation_Attribute_callExecutions->setOrdered(false);
	m_callActionActivation_Attribute_callExecutions->setContainment(true);
	m_callActionActivation_Attribute_callExecutions->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_callActionActivation_Attribute_callExecutions->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_callActionActivation_Attribute_callExecutions->setEOpposite(otherEnd);
	    }
	}
	
	m_callActionActivation_Operation_doAction->setEType(nullptr);
	m_callActionActivation_Operation_doAction->setName("doAction");
	m_callActionActivation_Operation_doAction->setLowerBound(1);
	m_callActionActivation_Operation_doAction->setUpperBound(1);
	m_callActionActivation_Operation_doAction->setUnique(true);
	m_callActionActivation_Operation_doAction->setOrdered(false);
	
	
	m_callActionActivation_Operation_getCallExecution->setEType(getExecution_Class());
	m_callActionActivation_Operation_getCallExecution->setName("getCallExecution");
	m_callActionActivation_Operation_getCallExecution->setLowerBound(1);
	m_callActionActivation_Operation_getCallExecution->setUpperBound(1);
	m_callActionActivation_Operation_getCallExecution->setUnique(true);
	m_callActionActivation_Operation_getCallExecution->setOrdered(false);
	
	
	m_callActionActivation_Operation_removeCallExecution_Execution->setEType(nullptr);
	m_callActionActivation_Operation_removeCallExecution_Execution->setName("removeCallExecution");
	m_callActionActivation_Operation_removeCallExecution_Execution->setLowerBound(1);
	m_callActionActivation_Operation_removeCallExecution_Execution->setUpperBound(1);
	m_callActionActivation_Operation_removeCallExecution_Execution->setUnique(true);
	m_callActionActivation_Operation_removeCallExecution_Execution->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_callActionActivation_Operation_removeCallExecution_Execution);
		parameter->setName("execution");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_callActionActivation_Operation_terminate->setEType(nullptr);
	m_callActionActivation_Operation_terminate->setName("terminate");
	m_callActionActivation_Operation_terminate->setLowerBound(1);
	m_callActionActivation_Operation_terminate->setUpperBound(1);
	m_callActionActivation_Operation_terminate->setUnique(true);
	m_callActionActivation_Operation_terminate->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeCallBehaviorActionActivationContent()
{
	m_callBehaviorActionActivation_Class->setName("CallBehaviorActionActivation");
	m_callBehaviorActionActivation_Class->setAbstract(false);
	m_callBehaviorActionActivation_Class->setInterface(false);
	
	
	
	m_callBehaviorActionActivation_Operation_getCallExecution->setEType(getExecution_Class());
	m_callBehaviorActionActivation_Operation_getCallExecution->setName("getCallExecution");
	m_callBehaviorActionActivation_Operation_getCallExecution->setLowerBound(1);
	m_callBehaviorActionActivation_Operation_getCallExecution->setUpperBound(1);
	m_callBehaviorActionActivation_Operation_getCallExecution->setUnique(true);
	m_callBehaviorActionActivation_Operation_getCallExecution->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeCallEventBehaviorContent()
{
	m_callEventBehavior_Class->setName("CallEventBehavior");
	m_callEventBehavior_Class->setAbstract(false);
	m_callEventBehavior_Class->setInterface(false);
	
	
	
	m_callEventBehavior_Operation_operation->setEType(uml::UmlPackage::eInstance()->getOperation_Class());
	m_callEventBehavior_Operation_operation->setName("operation");
	m_callEventBehavior_Operation_operation->setLowerBound(1);
	m_callEventBehavior_Operation_operation->setUpperBound(1);
	m_callEventBehavior_Operation_operation->setUnique(true);
	m_callEventBehavior_Operation_operation->setOrdered(true);
	
	
	
}

void FUMLPackageImpl::initializeCallEventExecutionContent()
{
	m_callEventExecution_Class->setName("CallEventExecution");
	m_callEventExecution_Class->setAbstract(false);
	m_callEventExecution_Class->setInterface(false);
	
	m_callEventExecution_Attribute_callerSuspended = getCallEventExecution_Attribute_callerSuspended();
	m_callEventExecution_Attribute_callerSuspended->setName("callerSuspended");
	m_callEventExecution_Attribute_callerSuspended->setEType(types::TypesPackage::eInstance()->getBoolean_Class());
	m_callEventExecution_Attribute_callerSuspended->setLowerBound(0);
	m_callEventExecution_Attribute_callerSuspended->setUpperBound(1);
	m_callEventExecution_Attribute_callerSuspended->setTransient(false);
	m_callEventExecution_Attribute_callerSuspended->setVolatile(false);
	m_callEventExecution_Attribute_callerSuspended->setChangeable(true);
	m_callEventExecution_Attribute_callerSuspended->setUnsettable(false);
	m_callEventExecution_Attribute_callerSuspended->setUnique(true);
	m_callEventExecution_Attribute_callerSuspended->setDerived(false);
	m_callEventExecution_Attribute_callerSuspended->setOrdered(true);
	m_callEventExecution_Attribute_callerSuspended->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_callEventExecution_Attribute_callerSuspended->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	m_callEventExecution_Operation_copy->setEType(getValue_Class());
	m_callEventExecution_Operation_copy->setName("copy");
	m_callEventExecution_Operation_copy->setLowerBound(1);
	m_callEventExecution_Operation_copy->setUpperBound(1);
	m_callEventExecution_Operation_copy->setUnique(true);
	m_callEventExecution_Operation_copy->setOrdered(true);
	
	
	m_callEventExecution_Operation_createEventOccurrence->setEType(getEventOccurrence_Class());
	m_callEventExecution_Operation_createEventOccurrence->setName("createEventOccurrence");
	m_callEventExecution_Operation_createEventOccurrence->setLowerBound(1);
	m_callEventExecution_Operation_createEventOccurrence->setUpperBound(1);
	m_callEventExecution_Operation_createEventOccurrence->setUnique(true);
	m_callEventExecution_Operation_createEventOccurrence->setOrdered(true);
	
	
	m_callEventExecution_Operation_execute->setEType(nullptr);
	m_callEventExecution_Operation_execute->setName("execute");
	m_callEventExecution_Operation_execute->setLowerBound(0);
	m_callEventExecution_Operation_execute->setUpperBound(1);
	m_callEventExecution_Operation_execute->setUnique(true);
	m_callEventExecution_Operation_execute->setOrdered(true);
	
	
	m_callEventExecution_Operation_getInputParameterValues->setEType(getParameterValue_Class());
	m_callEventExecution_Operation_getInputParameterValues->setName("getInputParameterValues");
	m_callEventExecution_Operation_getInputParameterValues->setLowerBound(0);
	m_callEventExecution_Operation_getInputParameterValues->setUpperBound(-1);
	m_callEventExecution_Operation_getInputParameterValues->setUnique(true);
	m_callEventExecution_Operation_getInputParameterValues->setOrdered(true);
	
	
	m_callEventExecution_Operation_getOperation->setEType(uml::UmlPackage::eInstance()->getOperation_Class());
	m_callEventExecution_Operation_getOperation->setName("getOperation");
	m_callEventExecution_Operation_getOperation->setLowerBound(0);
	m_callEventExecution_Operation_getOperation->setUpperBound(1);
	m_callEventExecution_Operation_getOperation->setUnique(true);
	m_callEventExecution_Operation_getOperation->setOrdered(true);
	
	
	m_callEventExecution_Operation_isCallerSuspended->setEType(types::TypesPackage::eInstance()->getBoolean_Class());
	m_callEventExecution_Operation_isCallerSuspended->setName("isCallerSuspended");
	m_callEventExecution_Operation_isCallerSuspended->setLowerBound(0);
	m_callEventExecution_Operation_isCallerSuspended->setUpperBound(1);
	m_callEventExecution_Operation_isCallerSuspended->setUnique(true);
	m_callEventExecution_Operation_isCallerSuspended->setOrdered(true);
	
	
	m_callEventExecution_Operation_makeCall->setEType(nullptr);
	m_callEventExecution_Operation_makeCall->setName("makeCall");
	m_callEventExecution_Operation_makeCall->setLowerBound(0);
	m_callEventExecution_Operation_makeCall->setUpperBound(1);
	m_callEventExecution_Operation_makeCall->setUnique(true);
	m_callEventExecution_Operation_makeCall->setOrdered(true);
	
	
	m_callEventExecution_Operation_new_->setEType(getValue_Class());
	m_callEventExecution_Operation_new_->setName("new_");
	m_callEventExecution_Operation_new_->setLowerBound(0);
	m_callEventExecution_Operation_new_->setUpperBound(1);
	m_callEventExecution_Operation_new_->setUnique(true);
	m_callEventExecution_Operation_new_->setOrdered(true);
	
	
	m_callEventExecution_Operation_releaseCaller->setEType(nullptr);
	m_callEventExecution_Operation_releaseCaller->setName("releaseCaller");
	m_callEventExecution_Operation_releaseCaller->setLowerBound(0);
	m_callEventExecution_Operation_releaseCaller->setUpperBound(1);
	m_callEventExecution_Operation_releaseCaller->setUnique(true);
	m_callEventExecution_Operation_releaseCaller->setOrdered(true);
	
	
	m_callEventExecution_Operation_setOutputParameterValues_ParameterValue->setEType(nullptr);
	m_callEventExecution_Operation_setOutputParameterValues_ParameterValue->setName("setOutputParameterValues");
	m_callEventExecution_Operation_setOutputParameterValues_ParameterValue->setLowerBound(0);
	m_callEventExecution_Operation_setOutputParameterValues_ParameterValue->setUpperBound(1);
	m_callEventExecution_Operation_setOutputParameterValues_ParameterValue->setUnique(true);
	m_callEventExecution_Operation_setOutputParameterValues_ParameterValue->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_callEventExecution_Operation_setOutputParameterValues_ParameterValue);
		parameter->setName("parameterValues");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_callEventExecution_Operation_suspendCaller->setEType(nullptr);
	m_callEventExecution_Operation_suspendCaller->setName("suspendCaller");
	m_callEventExecution_Operation_suspendCaller->setLowerBound(0);
	m_callEventExecution_Operation_suspendCaller->setUpperBound(1);
	m_callEventExecution_Operation_suspendCaller->setUnique(true);
	m_callEventExecution_Operation_suspendCaller->setOrdered(true);
	
	
	m_callEventExecution_Operation_wait_->setEType(nullptr);
	m_callEventExecution_Operation_wait_->setName("wait_");
	m_callEventExecution_Operation_wait_->setLowerBound(0);
	m_callEventExecution_Operation_wait_->setUpperBound(1);
	m_callEventExecution_Operation_wait_->setUnique(true);
	m_callEventExecution_Operation_wait_->setOrdered(true);
	
	
	
}

void FUMLPackageImpl::initializeCallEventOccurrenceContent()
{
	m_callEventOccurrence_Class->setName("CallEventOccurrence");
	m_callEventOccurrence_Class->setAbstract(false);
	m_callEventOccurrence_Class->setInterface(false);
	
	
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
	m_callEventOccurrence_Attribute_execution->setOrdered(true);
	m_callEventOccurrence_Attribute_execution->setContainment(false);
	m_callEventOccurrence_Attribute_execution->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_callEventOccurrence_Attribute_execution->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_callEventOccurrence_Attribute_execution->setEOpposite(otherEnd);
	    }
	}
	
	m_callEventOccurrence_Operation_getOperation->setEType(uml::UmlPackage::eInstance()->getOperation_Class());
	m_callEventOccurrence_Operation_getOperation->setName("getOperation");
	m_callEventOccurrence_Operation_getOperation->setLowerBound(1);
	m_callEventOccurrence_Operation_getOperation->setUpperBound(1);
	m_callEventOccurrence_Operation_getOperation->setUnique(true);
	m_callEventOccurrence_Operation_getOperation->setOrdered(true);
	
	
	m_callEventOccurrence_Operation_getParameterValues->setEType(getParameterValue_Class());
	m_callEventOccurrence_Operation_getParameterValues->setName("getParameterValues");
	m_callEventOccurrence_Operation_getParameterValues->setLowerBound(0);
	m_callEventOccurrence_Operation_getParameterValues->setUpperBound(-1);
	m_callEventOccurrence_Operation_getParameterValues->setUnique(true);
	m_callEventOccurrence_Operation_getParameterValues->setOrdered(true);
	
	
	m_callEventOccurrence_Operation_match_Trigger->setEType(types::TypesPackage::eInstance()->getBoolean_Class());
	m_callEventOccurrence_Operation_match_Trigger->setName("match");
	m_callEventOccurrence_Operation_match_Trigger->setLowerBound(0);
	m_callEventOccurrence_Operation_match_Trigger->setUpperBound(1);
	m_callEventOccurrence_Operation_match_Trigger->setUnique(true);
	m_callEventOccurrence_Operation_match_Trigger->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_callEventOccurrence_Operation_match_Trigger);
		parameter->setName("trigger");
		parameter->setEType(uml::UmlPackage::eInstance()->getTrigger_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_callEventOccurrence_Operation_releaseCaller->setEType(nullptr);
	m_callEventOccurrence_Operation_releaseCaller->setName("releaseCaller");
	m_callEventOccurrence_Operation_releaseCaller->setLowerBound(0);
	m_callEventOccurrence_Operation_releaseCaller->setUpperBound(1);
	m_callEventOccurrence_Operation_releaseCaller->setUnique(true);
	m_callEventOccurrence_Operation_releaseCaller->setOrdered(true);
	
	
	m_callEventOccurrence_Operation_setOutputParameterValues_ParameterValue->setEType(nullptr);
	m_callEventOccurrence_Operation_setOutputParameterValues_ParameterValue->setName("setOutputParameterValues");
	m_callEventOccurrence_Operation_setOutputParameterValues_ParameterValue->setLowerBound(0);
	m_callEventOccurrence_Operation_setOutputParameterValues_ParameterValue->setUpperBound(1);
	m_callEventOccurrence_Operation_setOutputParameterValues_ParameterValue->setUnique(true);
	m_callEventOccurrence_Operation_setOutputParameterValues_ParameterValue->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_callEventOccurrence_Operation_setOutputParameterValues_ParameterValue);
		parameter->setName("parameterValues");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeCallOperationActionActivationContent()
{
	m_callOperationActionActivation_Class->setName("CallOperationActionActivation");
	m_callOperationActionActivation_Class->setAbstract(false);
	m_callOperationActionActivation_Class->setInterface(false);
	
	
	
	m_callOperationActionActivation_Operation_getCallExecution->setEType(getExecution_Class());
	m_callOperationActionActivation_Operation_getCallExecution->setName("getCallExecution");
	m_callOperationActionActivation_Operation_getCallExecution->setLowerBound(1);
	m_callOperationActionActivation_Operation_getCallExecution->setUpperBound(1);
	m_callOperationActionActivation_Operation_getCallExecution->setUnique(true);
	m_callOperationActionActivation_Operation_getCallExecution->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeCentralBufferNodeActivationContent()
{
	m_centralBufferNodeActivation_Class->setName("CentralBufferNodeActivation");
	m_centralBufferNodeActivation_Class->setAbstract(false);
	m_centralBufferNodeActivation_Class->setInterface(false);
	
	
	
	m_centralBufferNodeActivation_Operation_fire_Token->setEType(nullptr);
	m_centralBufferNodeActivation_Operation_fire_Token->setName("fire");
	m_centralBufferNodeActivation_Operation_fire_Token->setLowerBound(1);
	m_centralBufferNodeActivation_Operation_fire_Token->setUpperBound(1);
	m_centralBufferNodeActivation_Operation_fire_Token->setUnique(true);
	m_centralBufferNodeActivation_Operation_fire_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_centralBufferNodeActivation_Operation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeChoiceStrategyContent()
{
	m_choiceStrategy_Class->setName("ChoiceStrategy");
	m_choiceStrategy_Class->setAbstract(true);
	m_choiceStrategy_Class->setInterface(false);
	
	
	
	m_choiceStrategy_Operation_choose_EInt->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
	m_choiceStrategy_Operation_choose_EInt->setName("choose");
	m_choiceStrategy_Operation_choose_EInt->setLowerBound(1);
	m_choiceStrategy_Operation_choose_EInt->setUpperBound(1);
	m_choiceStrategy_Operation_choose_EInt->setUnique(true);
	m_choiceStrategy_Operation_choose_EInt->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_choiceStrategy_Operation_choose_EInt);
		parameter->setName("size");
		parameter->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_choiceStrategy_Operation_retrieveName->setEType(ecore::EcorePackage::eInstance()->getEString_Class());
	m_choiceStrategy_Operation_retrieveName->setName("retrieveName");
	m_choiceStrategy_Operation_retrieveName->setLowerBound(1);
	m_choiceStrategy_Operation_retrieveName->setUpperBound(1);
	m_choiceStrategy_Operation_retrieveName->setUnique(true);
	m_choiceStrategy_Operation_retrieveName->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeClassifierBehaviorExecutionContent()
{
	m_classifierBehaviorExecution_Class->setName("ClassifierBehaviorExecution");
	m_classifierBehaviorExecution_Class->setAbstract(false);
	m_classifierBehaviorExecution_Class->setInterface(false);
	
	
	m_classifierBehaviorExecution_Attribute_classifier->setName("classifier");
	m_classifierBehaviorExecution_Attribute_classifier->setEType(uml::UmlPackage::eInstance()->getClass_Class());
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_classifierBehaviorExecution_Attribute_classifier->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_classifierBehaviorExecution_Attribute_classifier->setEOpposite(otherEnd);
	    }
	}
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_classifierBehaviorExecution_Attribute_execution->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_classifierBehaviorExecution_Attribute_execution->setEOpposite(otherEnd);
	    }
	}
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_classifierBehaviorExecution_Attribute_objectActivation->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_classifierBehaviorExecution_Attribute_objectActivation->setEOpposite(otherEnd);
	    }
	}
	
	m_classifierBehaviorExecution_Operation__startObjectBehavior->setEType(nullptr);
	m_classifierBehaviorExecution_Operation__startObjectBehavior->setName("_startObjectBehavior");
	m_classifierBehaviorExecution_Operation__startObjectBehavior->setLowerBound(1);
	m_classifierBehaviorExecution_Operation__startObjectBehavior->setUpperBound(1);
	m_classifierBehaviorExecution_Operation__startObjectBehavior->setUnique(true);
	m_classifierBehaviorExecution_Operation__startObjectBehavior->setOrdered(false);
	
	
	m_classifierBehaviorExecution_Operation_execute_Class_ParameterValue->setEType(nullptr);
	m_classifierBehaviorExecution_Operation_execute_Class_ParameterValue->setName("execute");
	m_classifierBehaviorExecution_Operation_execute_Class_ParameterValue->setLowerBound(1);
	m_classifierBehaviorExecution_Operation_execute_Class_ParameterValue->setUpperBound(1);
	m_classifierBehaviorExecution_Operation_execute_Class_ParameterValue->setUnique(true);
	m_classifierBehaviorExecution_Operation_execute_Class_ParameterValue->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_classifierBehaviorExecution_Operation_execute_Class_ParameterValue);
		parameter->setName("classifier");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_classifierBehaviorExecution_Operation_execute_Class_ParameterValue);
		parameter->setName("inputs");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_classifierBehaviorExecution_Operation_terminate->setEType(nullptr);
	m_classifierBehaviorExecution_Operation_terminate->setName("terminate");
	m_classifierBehaviorExecution_Operation_terminate->setLowerBound(1);
	m_classifierBehaviorExecution_Operation_terminate->setUpperBound(1);
	m_classifierBehaviorExecution_Operation_terminate->setUnique(true);
	m_classifierBehaviorExecution_Operation_terminate->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeClassifierBehaviorExecutionActivityContent()
{
	m_classifierBehaviorExecutionActivity_Class->setName("ClassifierBehaviorExecutionActivity");
	m_classifierBehaviorExecutionActivity_Class->setAbstract(false);
	m_classifierBehaviorExecutionActivity_Class->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Content()
{
	m_classifierBehaviorExecutionActivity_OwnedBehaviorActivity1_Class->setName("ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1");
	m_classifierBehaviorExecutionActivity_OwnedBehaviorActivity1_Class->setAbstract(false);
	m_classifierBehaviorExecutionActivity_OwnedBehaviorActivity1_Class->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeClauseActivationContent()
{
	m_clauseActivation_Class->setName("ClauseActivation");
	m_clauseActivation_Class->setAbstract(false);
	m_clauseActivation_Class->setInterface(false);
	
	
	m_clauseActivation_Attribute_clause->setName("clause");
	m_clauseActivation_Attribute_clause->setEType(uml::UmlPackage::eInstance()->getClause_Class());
	m_clauseActivation_Attribute_clause->setLowerBound(1);
	m_clauseActivation_Attribute_clause->setUpperBound(1);
	m_clauseActivation_Attribute_clause->setTransient(false);
	m_clauseActivation_Attribute_clause->setVolatile(false);
	m_clauseActivation_Attribute_clause->setChangeable(true);
	m_clauseActivation_Attribute_clause->setUnsettable(false);
	m_clauseActivation_Attribute_clause->setUnique(true);
	m_clauseActivation_Attribute_clause->setDerived(false);
	m_clauseActivation_Attribute_clause->setOrdered(false);
	m_clauseActivation_Attribute_clause->setContainment(false);
	m_clauseActivation_Attribute_clause->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_clauseActivation_Attribute_clause->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_clauseActivation_Attribute_clause->setEOpposite(otherEnd);
	    }
	}
	m_clauseActivation_Attribute_conditionalNodeActivation->setName("conditionalNodeActivation");
	m_clauseActivation_Attribute_conditionalNodeActivation->setEType(getConditionalNodeActivation_Class());
	m_clauseActivation_Attribute_conditionalNodeActivation->setLowerBound(1);
	m_clauseActivation_Attribute_conditionalNodeActivation->setUpperBound(1);
	m_clauseActivation_Attribute_conditionalNodeActivation->setTransient(false);
	m_clauseActivation_Attribute_conditionalNodeActivation->setVolatile(false);
	m_clauseActivation_Attribute_conditionalNodeActivation->setChangeable(true);
	m_clauseActivation_Attribute_conditionalNodeActivation->setUnsettable(false);
	m_clauseActivation_Attribute_conditionalNodeActivation->setUnique(true);
	m_clauseActivation_Attribute_conditionalNodeActivation->setDerived(false);
	m_clauseActivation_Attribute_conditionalNodeActivation->setOrdered(false);
	m_clauseActivation_Attribute_conditionalNodeActivation->setContainment(false);
	m_clauseActivation_Attribute_conditionalNodeActivation->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_clauseActivation_Attribute_conditionalNodeActivation->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_clauseActivation_Attribute_conditionalNodeActivation->setEOpposite(otherEnd);
	    }
	}
	
	m_clauseActivation_Operation_getDecision->setEType(getBooleanValue_Class());
	m_clauseActivation_Operation_getDecision->setName("getDecision");
	m_clauseActivation_Operation_getDecision->setLowerBound(0);
	m_clauseActivation_Operation_getDecision->setUpperBound(1);
	m_clauseActivation_Operation_getDecision->setUnique(true);
	m_clauseActivation_Operation_getDecision->setOrdered(false);
	
	
	m_clauseActivation_Operation_getPredecessors->setEType(getClauseActivation_Class());
	m_clauseActivation_Operation_getPredecessors->setName("getPredecessors");
	m_clauseActivation_Operation_getPredecessors->setLowerBound(0);
	m_clauseActivation_Operation_getPredecessors->setUpperBound(-1);
	m_clauseActivation_Operation_getPredecessors->setUnique(true);
	m_clauseActivation_Operation_getPredecessors->setOrdered(false);
	
	
	m_clauseActivation_Operation_getSuccessors->setEType(getClauseActivation_Class());
	m_clauseActivation_Operation_getSuccessors->setName("getSuccessors");
	m_clauseActivation_Operation_getSuccessors->setLowerBound(0);
	m_clauseActivation_Operation_getSuccessors->setUpperBound(-1);
	m_clauseActivation_Operation_getSuccessors->setUnique(true);
	m_clauseActivation_Operation_getSuccessors->setOrdered(false);
	
	
	m_clauseActivation_Operation_isReady->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_clauseActivation_Operation_isReady->setName("isReady");
	m_clauseActivation_Operation_isReady->setLowerBound(1);
	m_clauseActivation_Operation_isReady->setUpperBound(1);
	m_clauseActivation_Operation_isReady->setUnique(true);
	m_clauseActivation_Operation_isReady->setOrdered(false);
	
	
	m_clauseActivation_Operation_recieveControl->setEType(nullptr);
	m_clauseActivation_Operation_recieveControl->setName("recieveControl");
	m_clauseActivation_Operation_recieveControl->setLowerBound(1);
	m_clauseActivation_Operation_recieveControl->setUpperBound(1);
	m_clauseActivation_Operation_recieveControl->setUnique(true);
	m_clauseActivation_Operation_recieveControl->setOrdered(false);
	
	
	m_clauseActivation_Operation_runTest->setEType(nullptr);
	m_clauseActivation_Operation_runTest->setName("runTest");
	m_clauseActivation_Operation_runTest->setLowerBound(1);
	m_clauseActivation_Operation_runTest->setUpperBound(1);
	m_clauseActivation_Operation_runTest->setUnique(true);
	m_clauseActivation_Operation_runTest->setOrdered(false);
	
	
	m_clauseActivation_Operation_selectBody->setEType(nullptr);
	m_clauseActivation_Operation_selectBody->setName("selectBody");
	m_clauseActivation_Operation_selectBody->setLowerBound(1);
	m_clauseActivation_Operation_selectBody->setUpperBound(1);
	m_clauseActivation_Operation_selectBody->setUnique(true);
	m_clauseActivation_Operation_selectBody->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeClearAssociationActionActivationContent()
{
	m_clearAssociationActionActivation_Class->setName("ClearAssociationActionActivation");
	m_clearAssociationActionActivation_Class->setAbstract(false);
	m_clearAssociationActionActivation_Class->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeClearStructuralFeatureActionActivationContent()
{
	m_clearStructuralFeatureActionActivation_Class->setName("ClearStructuralFeatureActionActivation");
	m_clearStructuralFeatureActionActivation_Class->setAbstract(false);
	m_clearStructuralFeatureActionActivation_Class->setInterface(false);
	
	
	
	m_clearStructuralFeatureActionActivation_Operation_doAction->setEType(nullptr);
	m_clearStructuralFeatureActionActivation_Operation_doAction->setName("doAction");
	m_clearStructuralFeatureActionActivation_Operation_doAction->setLowerBound(0);
	m_clearStructuralFeatureActionActivation_Operation_doAction->setUpperBound(1);
	m_clearStructuralFeatureActionActivation_Operation_doAction->setUnique(true);
	m_clearStructuralFeatureActionActivation_Operation_doAction->setOrdered(true);
	
	
	
}

void FUMLPackageImpl::initializeCompoundValueContent()
{
	m_compoundValue_Class->setName("CompoundValue");
	m_compoundValue_Class->setAbstract(true);
	m_compoundValue_Class->setInterface(false);
	
	
	m_compoundValue_Attribute_featureValues->setName("featureValues");
	m_compoundValue_Attribute_featureValues->setEType(getFeatureValue_Class());
	m_compoundValue_Attribute_featureValues->setLowerBound(0);
	m_compoundValue_Attribute_featureValues->setUpperBound(-1);
	m_compoundValue_Attribute_featureValues->setTransient(false);
	m_compoundValue_Attribute_featureValues->setVolatile(false);
	m_compoundValue_Attribute_featureValues->setChangeable(true);
	m_compoundValue_Attribute_featureValues->setUnsettable(false);
	m_compoundValue_Attribute_featureValues->setUnique(true);
	m_compoundValue_Attribute_featureValues->setDerived(false);
	m_compoundValue_Attribute_featureValues->setOrdered(false);
	m_compoundValue_Attribute_featureValues->setContainment(true);
	m_compoundValue_Attribute_featureValues->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_compoundValue_Attribute_featureValues->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_compoundValue_Attribute_featureValues->setEOpposite(otherEnd);
	    }
	}
	
	m_compoundValue_Operation_assignFeatureValue_StructuralFeature_EInt->setEType(nullptr);
	m_compoundValue_Operation_assignFeatureValue_StructuralFeature_EInt->setName("assignFeatureValue");
	m_compoundValue_Operation_assignFeatureValue_StructuralFeature_EInt->setLowerBound(1);
	m_compoundValue_Operation_assignFeatureValue_StructuralFeature_EInt->setUpperBound(1);
	m_compoundValue_Operation_assignFeatureValue_StructuralFeature_EInt->setUnique(true);
	m_compoundValue_Operation_assignFeatureValue_StructuralFeature_EInt->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_compoundValue_Operation_assignFeatureValue_StructuralFeature_EInt);
		parameter->setName("feature");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_compoundValue_Operation_assignFeatureValue_StructuralFeature_EInt);
		parameter->setName("values");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_compoundValue_Operation_assignFeatureValue_StructuralFeature_EInt);
		parameter->setName("position");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_compoundValue_Operation_equals_Value->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_compoundValue_Operation_equals_Value->setName("equals");
	m_compoundValue_Operation_equals_Value->setLowerBound(1);
	m_compoundValue_Operation_equals_Value->setUpperBound(1);
	m_compoundValue_Operation_equals_Value->setUnique(true);
	m_compoundValue_Operation_equals_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_compoundValue_Operation_equals_Value);
		parameter->setName("otherValue");
		parameter->setEType(getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_compoundValue_Operation_removeFeatureValues_Classifier->setEType(nullptr);
	m_compoundValue_Operation_removeFeatureValues_Classifier->setName("removeFeatureValues");
	m_compoundValue_Operation_removeFeatureValues_Classifier->setLowerBound(1);
	m_compoundValue_Operation_removeFeatureValues_Classifier->setUpperBound(1);
	m_compoundValue_Operation_removeFeatureValues_Classifier->setUnique(true);
	m_compoundValue_Operation_removeFeatureValues_Classifier->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_compoundValue_Operation_removeFeatureValues_Classifier);
		parameter->setName("classifier");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_compoundValue_Operation_retrieveFeatureValue_StructuralFeature->setEType(getFeatureValue_Class());
	m_compoundValue_Operation_retrieveFeatureValue_StructuralFeature->setName("retrieveFeatureValue");
	m_compoundValue_Operation_retrieveFeatureValue_StructuralFeature->setLowerBound(1);
	m_compoundValue_Operation_retrieveFeatureValue_StructuralFeature->setUpperBound(1);
	m_compoundValue_Operation_retrieveFeatureValue_StructuralFeature->setUnique(true);
	m_compoundValue_Operation_retrieveFeatureValue_StructuralFeature->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_compoundValue_Operation_retrieveFeatureValue_StructuralFeature);
		parameter->setName("feature");
		parameter->setEType(uml::UmlPackage::eInstance()->getStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_compoundValue_Operation_retrieveFeatureValues->setEType(getFeatureValue_Class());
	m_compoundValue_Operation_retrieveFeatureValues->setName("retrieveFeatureValues");
	m_compoundValue_Operation_retrieveFeatureValues->setLowerBound(0);
	m_compoundValue_Operation_retrieveFeatureValues->setUpperBound(-1);
	m_compoundValue_Operation_retrieveFeatureValues->setUnique(true);
	m_compoundValue_Operation_retrieveFeatureValues->setOrdered(false);
	
	
	m_compoundValue_Operation_toString->setEType(ecore::EcorePackage::eInstance()->getEString_Class());
	m_compoundValue_Operation_toString->setName("toString");
	m_compoundValue_Operation_toString->setLowerBound(1);
	m_compoundValue_Operation_toString->setUpperBound(1);
	m_compoundValue_Operation_toString->setUnique(true);
	m_compoundValue_Operation_toString->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeConditionalNodeActivationContent()
{
	m_conditionalNodeActivation_Class->setName("ConditionalNodeActivation");
	m_conditionalNodeActivation_Class->setAbstract(false);
	m_conditionalNodeActivation_Class->setInterface(false);
	
	
	m_conditionalNodeActivation_Attribute_clauseActivations->setName("clauseActivations");
	m_conditionalNodeActivation_Attribute_clauseActivations->setEType(getClauseActivation_Class());
	m_conditionalNodeActivation_Attribute_clauseActivations->setLowerBound(0);
	m_conditionalNodeActivation_Attribute_clauseActivations->setUpperBound(-1);
	m_conditionalNodeActivation_Attribute_clauseActivations->setTransient(false);
	m_conditionalNodeActivation_Attribute_clauseActivations->setVolatile(false);
	m_conditionalNodeActivation_Attribute_clauseActivations->setChangeable(true);
	m_conditionalNodeActivation_Attribute_clauseActivations->setUnsettable(false);
	m_conditionalNodeActivation_Attribute_clauseActivations->setUnique(true);
	m_conditionalNodeActivation_Attribute_clauseActivations->setDerived(false);
	m_conditionalNodeActivation_Attribute_clauseActivations->setOrdered(false);
	m_conditionalNodeActivation_Attribute_clauseActivations->setContainment(true);
	m_conditionalNodeActivation_Attribute_clauseActivations->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_conditionalNodeActivation_Attribute_clauseActivations->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_conditionalNodeActivation_Attribute_clauseActivations->setEOpposite(otherEnd);
	    }
	}
	m_conditionalNodeActivation_Attribute_selectedClauses->setName("selectedClauses");
	m_conditionalNodeActivation_Attribute_selectedClauses->setEType(uml::UmlPackage::eInstance()->getClause_Class());
	m_conditionalNodeActivation_Attribute_selectedClauses->setLowerBound(0);
	m_conditionalNodeActivation_Attribute_selectedClauses->setUpperBound(-1);
	m_conditionalNodeActivation_Attribute_selectedClauses->setTransient(false);
	m_conditionalNodeActivation_Attribute_selectedClauses->setVolatile(false);
	m_conditionalNodeActivation_Attribute_selectedClauses->setChangeable(true);
	m_conditionalNodeActivation_Attribute_selectedClauses->setUnsettable(false);
	m_conditionalNodeActivation_Attribute_selectedClauses->setUnique(true);
	m_conditionalNodeActivation_Attribute_selectedClauses->setDerived(false);
	m_conditionalNodeActivation_Attribute_selectedClauses->setOrdered(false);
	m_conditionalNodeActivation_Attribute_selectedClauses->setContainment(false);
	m_conditionalNodeActivation_Attribute_selectedClauses->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_conditionalNodeActivation_Attribute_selectedClauses->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_conditionalNodeActivation_Attribute_selectedClauses->setEOpposite(otherEnd);
	    }
	}
	
	m_conditionalNodeActivation_Operation_getClauseActivation_Clause->setEType(getClauseActivation_Class());
	m_conditionalNodeActivation_Operation_getClauseActivation_Clause->setName("getClauseActivation");
	m_conditionalNodeActivation_Operation_getClauseActivation_Clause->setLowerBound(1);
	m_conditionalNodeActivation_Operation_getClauseActivation_Clause->setUpperBound(1);
	m_conditionalNodeActivation_Operation_getClauseActivation_Clause->setUnique(true);
	m_conditionalNodeActivation_Operation_getClauseActivation_Clause->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_conditionalNodeActivation_Operation_getClauseActivation_Clause);
		parameter->setName("clause");
		parameter->setEType(uml::UmlPackage::eInstance()->getClause_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_conditionalNodeActivation_Operation_runTest_Clause->setEType(nullptr);
	m_conditionalNodeActivation_Operation_runTest_Clause->setName("runTest");
	m_conditionalNodeActivation_Operation_runTest_Clause->setLowerBound(1);
	m_conditionalNodeActivation_Operation_runTest_Clause->setUpperBound(1);
	m_conditionalNodeActivation_Operation_runTest_Clause->setUnique(true);
	m_conditionalNodeActivation_Operation_runTest_Clause->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_conditionalNodeActivation_Operation_runTest_Clause);
		parameter->setName("clause");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_conditionalNodeActivation_Operation_selectBody_Clause->setEType(nullptr);
	m_conditionalNodeActivation_Operation_selectBody_Clause->setName("selectBody");
	m_conditionalNodeActivation_Operation_selectBody_Clause->setLowerBound(1);
	m_conditionalNodeActivation_Operation_selectBody_Clause->setUpperBound(1);
	m_conditionalNodeActivation_Operation_selectBody_Clause->setUnique(true);
	m_conditionalNodeActivation_Operation_selectBody_Clause->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_conditionalNodeActivation_Operation_selectBody_Clause);
		parameter->setName("clause");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeControlNodeActivationContent()
{
	m_controlNodeActivation_Class->setName("ControlNodeActivation");
	m_controlNodeActivation_Class->setAbstract(true);
	m_controlNodeActivation_Class->setInterface(false);
	
	
	
	m_controlNodeActivation_Operation_fire_Token->setEType(nullptr);
	m_controlNodeActivation_Operation_fire_Token->setName("fire");
	m_controlNodeActivation_Operation_fire_Token->setLowerBound(1);
	m_controlNodeActivation_Operation_fire_Token->setUpperBound(1);
	m_controlNodeActivation_Operation_fire_Token->setUnique(true);
	m_controlNodeActivation_Operation_fire_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_controlNodeActivation_Operation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeControlTokenContent()
{
	m_controlToken_Class->setName("ControlToken");
	m_controlToken_Class->setAbstract(false);
	m_controlToken_Class->setInterface(false);
	
	
	
	m_controlToken_Operation_equals_Token->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_controlToken_Operation_equals_Token->setName("equals");
	m_controlToken_Operation_equals_Token->setLowerBound(1);
	m_controlToken_Operation_equals_Token->setUpperBound(1);
	m_controlToken_Operation_equals_Token->setUnique(true);
	m_controlToken_Operation_equals_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_controlToken_Operation_equals_Token);
		parameter->setName("other");
		parameter->setEType(getToken_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_controlToken_Operation_getValue->setEType(getValue_Class());
	m_controlToken_Operation_getValue->setName("getValue");
	m_controlToken_Operation_getValue->setLowerBound(0);
	m_controlToken_Operation_getValue->setUpperBound(1);
	m_controlToken_Operation_getValue->setUnique(true);
	m_controlToken_Operation_getValue->setOrdered(false);
	
	
	m_controlToken_Operation_isControl->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_controlToken_Operation_isControl->setName("isControl");
	m_controlToken_Operation_isControl->setLowerBound(1);
	m_controlToken_Operation_isControl->setUpperBound(1);
	m_controlToken_Operation_isControl->setUnique(true);
	m_controlToken_Operation_isControl->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeCreateLinkActionActivationContent()
{
	m_createLinkActionActivation_Class->setName("CreateLinkActionActivation");
	m_createLinkActionActivation_Class->setAbstract(false);
	m_createLinkActionActivation_Class->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeCreateObjectActionActivationContent()
{
	m_createObjectActionActivation_Class->setName("CreateObjectActionActivation");
	m_createObjectActionActivation_Class->setAbstract(false);
	m_createObjectActionActivation_Class->setInterface(false);
	
	
	
	m_createObjectActionActivation_Operation_doAction->setEType(nullptr);
	m_createObjectActionActivation_Operation_doAction->setName("doAction");
	m_createObjectActionActivation_Operation_doAction->setLowerBound(0);
	m_createObjectActionActivation_Operation_doAction->setUpperBound(1);
	m_createObjectActionActivation_Operation_doAction->setUnique(true);
	m_createObjectActionActivation_Operation_doAction->setOrdered(true);
	
	
	
}

void FUMLPackageImpl::initializeDataStoreNodeActivationContent()
{
	m_dataStoreNodeActivation_Class->setName("DataStoreNodeActivation");
	m_dataStoreNodeActivation_Class->setAbstract(false);
	m_dataStoreNodeActivation_Class->setInterface(false);
	
	
	
	m_dataStoreNodeActivation_Operation_addToken_Token->setEType(nullptr);
	m_dataStoreNodeActivation_Operation_addToken_Token->setName("addToken");
	m_dataStoreNodeActivation_Operation_addToken_Token->setLowerBound(1);
	m_dataStoreNodeActivation_Operation_addToken_Token->setUpperBound(1);
	m_dataStoreNodeActivation_Operation_addToken_Token->setUnique(true);
	m_dataStoreNodeActivation_Operation_addToken_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_dataStoreNodeActivation_Operation_addToken_Token);
		parameter->setName("token");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_dataStoreNodeActivation_Operation_removeToken_Token->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
	m_dataStoreNodeActivation_Operation_removeToken_Token->setName("removeToken");
	m_dataStoreNodeActivation_Operation_removeToken_Token->setLowerBound(1);
	m_dataStoreNodeActivation_Operation_removeToken_Token->setUpperBound(1);
	m_dataStoreNodeActivation_Operation_removeToken_Token->setUnique(true);
	m_dataStoreNodeActivation_Operation_removeToken_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_dataStoreNodeActivation_Operation_removeToken_Token);
		parameter->setName("token");
		parameter->setEType(getToken_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeDataValueContent()
{
	m_dataValue_Class->setName("DataValue");
	m_dataValue_Class->setAbstract(false);
	m_dataValue_Class->setInterface(false);
	
	
	m_dataValue_Attribute_type->setName("type");
	m_dataValue_Attribute_type->setEType(uml::UmlPackage::eInstance()->getDataType_Class());
	m_dataValue_Attribute_type->setLowerBound(1);
	m_dataValue_Attribute_type->setUpperBound(1);
	m_dataValue_Attribute_type->setTransient(false);
	m_dataValue_Attribute_type->setVolatile(false);
	m_dataValue_Attribute_type->setChangeable(true);
	m_dataValue_Attribute_type->setUnsettable(false);
	m_dataValue_Attribute_type->setUnique(true);
	m_dataValue_Attribute_type->setDerived(false);
	m_dataValue_Attribute_type->setOrdered(false);
	m_dataValue_Attribute_type->setContainment(false);
	m_dataValue_Attribute_type->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_dataValue_Attribute_type->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_dataValue_Attribute_type->setEOpposite(otherEnd);
	    }
	}
	
	m_dataValue_Operation_getTypes->setEType(uml::UmlPackage::eInstance()->getClassifier_Class());
	m_dataValue_Operation_getTypes->setName("getTypes");
	m_dataValue_Operation_getTypes->setLowerBound(0);
	m_dataValue_Operation_getTypes->setUpperBound(-1);
	m_dataValue_Operation_getTypes->setUnique(true);
	m_dataValue_Operation_getTypes->setOrdered(false);
	
	
	m_dataValue_Operation_new_->setEType(getValue_Class());
	m_dataValue_Operation_new_->setName("new_");
	m_dataValue_Operation_new_->setLowerBound(1);
	m_dataValue_Operation_new_->setUpperBound(1);
	m_dataValue_Operation_new_->setUnique(true);
	m_dataValue_Operation_new_->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeDecisionNodeActivationContent()
{
	m_decisionNodeActivation_Class->setName("DecisionNodeActivation");
	m_decisionNodeActivation_Class->setAbstract(false);
	m_decisionNodeActivation_Class->setInterface(false);
	
	
	m_decisionNodeActivation_Attribute_decisionInputExecution->setName("decisionInputExecution");
	m_decisionNodeActivation_Attribute_decisionInputExecution->setEType(getExecution_Class());
	m_decisionNodeActivation_Attribute_decisionInputExecution->setLowerBound(1);
	m_decisionNodeActivation_Attribute_decisionInputExecution->setUpperBound(1);
	m_decisionNodeActivation_Attribute_decisionInputExecution->setTransient(false);
	m_decisionNodeActivation_Attribute_decisionInputExecution->setVolatile(false);
	m_decisionNodeActivation_Attribute_decisionInputExecution->setChangeable(true);
	m_decisionNodeActivation_Attribute_decisionInputExecution->setUnsettable(false);
	m_decisionNodeActivation_Attribute_decisionInputExecution->setUnique(true);
	m_decisionNodeActivation_Attribute_decisionInputExecution->setDerived(false);
	m_decisionNodeActivation_Attribute_decisionInputExecution->setOrdered(false);
	m_decisionNodeActivation_Attribute_decisionInputExecution->setContainment(true);
	m_decisionNodeActivation_Attribute_decisionInputExecution->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_decisionNodeActivation_Attribute_decisionInputExecution->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_decisionNodeActivation_Attribute_decisionInputExecution->setEOpposite(otherEnd);
	    }
	}
	
	m_decisionNodeActivation_Operation_executeDecisionInputBehavior_Value_Value->setEType(getValue_Class());
	m_decisionNodeActivation_Operation_executeDecisionInputBehavior_Value_Value->setName("executeDecisionInputBehavior");
	m_decisionNodeActivation_Operation_executeDecisionInputBehavior_Value_Value->setLowerBound(1);
	m_decisionNodeActivation_Operation_executeDecisionInputBehavior_Value_Value->setUpperBound(1);
	m_decisionNodeActivation_Operation_executeDecisionInputBehavior_Value_Value->setUnique(true);
	m_decisionNodeActivation_Operation_executeDecisionInputBehavior_Value_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_decisionNodeActivation_Operation_executeDecisionInputBehavior_Value_Value);
		parameter->setName("inputValue");
		parameter->setEType(getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_decisionNodeActivation_Operation_executeDecisionInputBehavior_Value_Value);
		parameter->setName("decisionInputValue");
		parameter->setEType(getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_decisionNodeActivation_Operation_fire_Token->setEType(nullptr);
	m_decisionNodeActivation_Operation_fire_Token->setName("fire");
	m_decisionNodeActivation_Operation_fire_Token->setLowerBound(1);
	m_decisionNodeActivation_Operation_fire_Token->setUpperBound(1);
	m_decisionNodeActivation_Operation_fire_Token->setUnique(true);
	m_decisionNodeActivation_Operation_fire_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_decisionNodeActivation_Operation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_decisionNodeActivation_Operation_getDecisionInputFlowInstance->setEType(getActivityEdgeInstance_Class());
	m_decisionNodeActivation_Operation_getDecisionInputFlowInstance->setName("getDecisionInputFlowInstance");
	m_decisionNodeActivation_Operation_getDecisionInputFlowInstance->setLowerBound(0);
	m_decisionNodeActivation_Operation_getDecisionInputFlowInstance->setUpperBound(1);
	m_decisionNodeActivation_Operation_getDecisionInputFlowInstance->setUnique(true);
	m_decisionNodeActivation_Operation_getDecisionInputFlowInstance->setOrdered(false);
	
	
	m_decisionNodeActivation_Operation_getDecisionInputFlowValue->setEType(getValue_Class());
	m_decisionNodeActivation_Operation_getDecisionInputFlowValue->setName("getDecisionInputFlowValue");
	m_decisionNodeActivation_Operation_getDecisionInputFlowValue->setLowerBound(0);
	m_decisionNodeActivation_Operation_getDecisionInputFlowValue->setUpperBound(1);
	m_decisionNodeActivation_Operation_getDecisionInputFlowValue->setUnique(true);
	m_decisionNodeActivation_Operation_getDecisionInputFlowValue->setOrdered(false);
	
	
	m_decisionNodeActivation_Operation_getDecisionValues_Token->setEType(getValue_Class());
	m_decisionNodeActivation_Operation_getDecisionValues_Token->setName("getDecisionValues");
	m_decisionNodeActivation_Operation_getDecisionValues_Token->setLowerBound(0);
	m_decisionNodeActivation_Operation_getDecisionValues_Token->setUpperBound(-1);
	m_decisionNodeActivation_Operation_getDecisionValues_Token->setUnique(true);
	m_decisionNodeActivation_Operation_getDecisionValues_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_decisionNodeActivation_Operation_getDecisionValues_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(getToken_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_decisionNodeActivation_Operation_hasObjectFlowInput->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_decisionNodeActivation_Operation_hasObjectFlowInput->setName("hasObjectFlowInput");
	m_decisionNodeActivation_Operation_hasObjectFlowInput->setLowerBound(1);
	m_decisionNodeActivation_Operation_hasObjectFlowInput->setUpperBound(1);
	m_decisionNodeActivation_Operation_hasObjectFlowInput->setUnique(true);
	m_decisionNodeActivation_Operation_hasObjectFlowInput->setOrdered(false);
	
	
	m_decisionNodeActivation_Operation_isReady->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_decisionNodeActivation_Operation_isReady->setName("isReady");
	m_decisionNodeActivation_Operation_isReady->setLowerBound(1);
	m_decisionNodeActivation_Operation_isReady->setUpperBound(1);
	m_decisionNodeActivation_Operation_isReady->setUnique(true);
	m_decisionNodeActivation_Operation_isReady->setOrdered(false);
	
	
	m_decisionNodeActivation_Operation_removeJoinedControlTokens_Token->setEType(getToken_Class());
	m_decisionNodeActivation_Operation_removeJoinedControlTokens_Token->setName("removeJoinedControlTokens");
	m_decisionNodeActivation_Operation_removeJoinedControlTokens_Token->setLowerBound(0);
	m_decisionNodeActivation_Operation_removeJoinedControlTokens_Token->setUpperBound(-1);
	m_decisionNodeActivation_Operation_removeJoinedControlTokens_Token->setUnique(true);
	m_decisionNodeActivation_Operation_removeJoinedControlTokens_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_decisionNodeActivation_Operation_removeJoinedControlTokens_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(getToken_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_decisionNodeActivation_Operation_takeOfferedTokens->setEType(getToken_Class());
	m_decisionNodeActivation_Operation_takeOfferedTokens->setName("takeOfferedTokens");
	m_decisionNodeActivation_Operation_takeOfferedTokens->setLowerBound(0);
	m_decisionNodeActivation_Operation_takeOfferedTokens->setUpperBound(-1);
	m_decisionNodeActivation_Operation_takeOfferedTokens->setUnique(true);
	m_decisionNodeActivation_Operation_takeOfferedTokens->setOrdered(false);
	
	
	m_decisionNodeActivation_Operation_terminate->setEType(nullptr);
	m_decisionNodeActivation_Operation_terminate->setName("terminate");
	m_decisionNodeActivation_Operation_terminate->setLowerBound(1);
	m_decisionNodeActivation_Operation_terminate->setUpperBound(1);
	m_decisionNodeActivation_Operation_terminate->setUnique(true);
	m_decisionNodeActivation_Operation_terminate->setOrdered(false);
	
	
	m_decisionNodeActivation_Operation_test_ValueSpecification_Value->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_decisionNodeActivation_Operation_test_ValueSpecification_Value->setName("test");
	m_decisionNodeActivation_Operation_test_ValueSpecification_Value->setLowerBound(1);
	m_decisionNodeActivation_Operation_test_ValueSpecification_Value->setUpperBound(1);
	m_decisionNodeActivation_Operation_test_ValueSpecification_Value->setUnique(true);
	m_decisionNodeActivation_Operation_test_ValueSpecification_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_decisionNodeActivation_Operation_test_ValueSpecification_Value);
		parameter->setName("gaurd");
		parameter->setEType(uml::UmlPackage::eInstance()->getValueSpecification_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_decisionNodeActivation_Operation_test_ValueSpecification_Value);
		parameter->setName("value");
		parameter->setEType(getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeDestroyLinkActionActivationContent()
{
	m_destroyLinkActionActivation_Class->setName("DestroyLinkActionActivation");
	m_destroyLinkActionActivation_Class->setAbstract(false);
	m_destroyLinkActionActivation_Class->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeDestroyObjectActionActivationContent()
{
	m_destroyObjectActionActivation_Class->setName("DestroyObjectActionActivation");
	m_destroyObjectActionActivation_Class->setAbstract(false);
	m_destroyObjectActionActivation_Class->setInterface(false);
	
	
	
	m_destroyObjectActionActivation_Operation_destroyObject_Value_EBoolean->setEType(nullptr);
	m_destroyObjectActionActivation_Operation_destroyObject_Value_EBoolean->setName("destroyObject");
	m_destroyObjectActionActivation_Operation_destroyObject_Value_EBoolean->setLowerBound(1);
	m_destroyObjectActionActivation_Operation_destroyObject_Value_EBoolean->setUpperBound(1);
	m_destroyObjectActionActivation_Operation_destroyObject_Value_EBoolean->setUnique(true);
	m_destroyObjectActionActivation_Operation_destroyObject_Value_EBoolean->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_destroyObjectActionActivation_Operation_destroyObject_Value_EBoolean);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_destroyObjectActionActivation_Operation_destroyObject_Value_EBoolean);
		parameter->setName("isDestroyLinks");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_destroyObjectActionActivation_Operation_destroyObject_Value_EBoolean);
		parameter->setName("isDestroyOwnedObjects");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_destroyObjectActionActivation_Operation_doAction->setEType(nullptr);
	m_destroyObjectActionActivation_Operation_doAction->setName("doAction");
	m_destroyObjectActionActivation_Operation_doAction->setLowerBound(0);
	m_destroyObjectActionActivation_Operation_doAction->setUpperBound(1);
	m_destroyObjectActionActivation_Operation_doAction->setUnique(true);
	m_destroyObjectActionActivation_Operation_doAction->setOrdered(true);
	
	
	m_destroyObjectActionActivation_Operation_objectIsComposite_Reference_Link->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_destroyObjectActionActivation_Operation_objectIsComposite_Reference_Link->setName("objectIsComposite");
	m_destroyObjectActionActivation_Operation_objectIsComposite_Reference_Link->setLowerBound(1);
	m_destroyObjectActionActivation_Operation_objectIsComposite_Reference_Link->setUpperBound(1);
	m_destroyObjectActionActivation_Operation_objectIsComposite_Reference_Link->setUnique(true);
	m_destroyObjectActionActivation_Operation_objectIsComposite_Reference_Link->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_destroyObjectActionActivation_Operation_objectIsComposite_Reference_Link);
		parameter->setName("reference");
		parameter->setEType(getReference_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_destroyObjectActionActivation_Operation_objectIsComposite_Reference_Link);
		parameter->setName("link");
		parameter->setEType(getLink_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeDispatchStrategyContent()
{
	m_dispatchStrategy_Class->setName("DispatchStrategy");
	m_dispatchStrategy_Class->setAbstract(false);
	m_dispatchStrategy_Class->setInterface(false);
	
	
	
	m_dispatchStrategy_Operation_dispatch_Object_Operation->setEType(getExecution_Class());
	m_dispatchStrategy_Operation_dispatch_Object_Operation->setName("dispatch");
	m_dispatchStrategy_Operation_dispatch_Object_Operation->setLowerBound(1);
	m_dispatchStrategy_Operation_dispatch_Object_Operation->setUpperBound(1);
	m_dispatchStrategy_Operation_dispatch_Object_Operation->setUnique(true);
	m_dispatchStrategy_Operation_dispatch_Object_Operation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_dispatchStrategy_Operation_dispatch_Object_Operation);
		parameter->setName("object");
		parameter->setEType(getObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_dispatchStrategy_Operation_dispatch_Object_Operation);
		parameter->setName("operation");
		parameter->setEType(uml::UmlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_dispatchStrategy_Operation_retrieveMethod_Object_Operation->setEType(uml::UmlPackage::eInstance()->getBehavior_Class());
	m_dispatchStrategy_Operation_retrieveMethod_Object_Operation->setName("retrieveMethod");
	m_dispatchStrategy_Operation_retrieveMethod_Object_Operation->setLowerBound(1);
	m_dispatchStrategy_Operation_retrieveMethod_Object_Operation->setUpperBound(1);
	m_dispatchStrategy_Operation_retrieveMethod_Object_Operation->setUnique(true);
	m_dispatchStrategy_Operation_retrieveMethod_Object_Operation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_dispatchStrategy_Operation_retrieveMethod_Object_Operation);
		parameter->setName("object");
		parameter->setEType(getObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_dispatchStrategy_Operation_retrieveMethod_Object_Operation);
		parameter->setName("operation");
		parameter->setEType(uml::UmlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_dispatchStrategy_Operation_retrieveName->setEType(ecore::EcorePackage::eInstance()->getEString_Class());
	m_dispatchStrategy_Operation_retrieveName->setName("retrieveName");
	m_dispatchStrategy_Operation_retrieveName->setLowerBound(1);
	m_dispatchStrategy_Operation_retrieveName->setUpperBound(1);
	m_dispatchStrategy_Operation_retrieveName->setUnique(true);
	m_dispatchStrategy_Operation_retrieveName->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeEnumerationValueContent()
{
	m_enumerationValue_Class->setName("EnumerationValue");
	m_enumerationValue_Class->setAbstract(false);
	m_enumerationValue_Class->setInterface(false);
	
	
	m_enumerationValue_Attribute_literal->setName("literal");
	m_enumerationValue_Attribute_literal->setEType(uml::UmlPackage::eInstance()->getEnumerationLiteral_Class());
	m_enumerationValue_Attribute_literal->setLowerBound(1);
	m_enumerationValue_Attribute_literal->setUpperBound(1);
	m_enumerationValue_Attribute_literal->setTransient(false);
	m_enumerationValue_Attribute_literal->setVolatile(false);
	m_enumerationValue_Attribute_literal->setChangeable(true);
	m_enumerationValue_Attribute_literal->setUnsettable(false);
	m_enumerationValue_Attribute_literal->setUnique(true);
	m_enumerationValue_Attribute_literal->setDerived(false);
	m_enumerationValue_Attribute_literal->setOrdered(false);
	m_enumerationValue_Attribute_literal->setContainment(false);
	m_enumerationValue_Attribute_literal->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_enumerationValue_Attribute_literal->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_enumerationValue_Attribute_literal->setEOpposite(otherEnd);
	    }
	}
	m_enumerationValue_Attribute_type->setName("type");
	m_enumerationValue_Attribute_type->setEType(uml::UmlPackage::eInstance()->getEnumeration_Class());
	m_enumerationValue_Attribute_type->setLowerBound(1);
	m_enumerationValue_Attribute_type->setUpperBound(1);
	m_enumerationValue_Attribute_type->setTransient(false);
	m_enumerationValue_Attribute_type->setVolatile(false);
	m_enumerationValue_Attribute_type->setChangeable(true);
	m_enumerationValue_Attribute_type->setUnsettable(false);
	m_enumerationValue_Attribute_type->setUnique(true);
	m_enumerationValue_Attribute_type->setDerived(false);
	m_enumerationValue_Attribute_type->setOrdered(false);
	m_enumerationValue_Attribute_type->setContainment(false);
	m_enumerationValue_Attribute_type->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_enumerationValue_Attribute_type->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_enumerationValue_Attribute_type->setEOpposite(otherEnd);
	    }
	}
	
	m_enumerationValue_Operation_equals_Value->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_enumerationValue_Operation_equals_Value->setName("equals");
	m_enumerationValue_Operation_equals_Value->setLowerBound(1);
	m_enumerationValue_Operation_equals_Value->setUpperBound(1);
	m_enumerationValue_Operation_equals_Value->setUnique(true);
	m_enumerationValue_Operation_equals_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_enumerationValue_Operation_equals_Value);
		parameter->setName("otherValue");
		parameter->setEType(getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_enumerationValue_Operation_getTypes->setEType(uml::UmlPackage::eInstance()->getClassifier_Class());
	m_enumerationValue_Operation_getTypes->setName("getTypes");
	m_enumerationValue_Operation_getTypes->setLowerBound(0);
	m_enumerationValue_Operation_getTypes->setUpperBound(-1);
	m_enumerationValue_Operation_getTypes->setUnique(true);
	m_enumerationValue_Operation_getTypes->setOrdered(false);
	
	
	m_enumerationValue_Operation_new_->setEType(getValue_Class());
	m_enumerationValue_Operation_new_->setName("new_");
	m_enumerationValue_Operation_new_->setLowerBound(1);
	m_enumerationValue_Operation_new_->setUpperBound(1);
	m_enumerationValue_Operation_new_->setUnique(true);
	m_enumerationValue_Operation_new_->setOrdered(false);
	
	
	m_enumerationValue_Operation_specify->setEType(uml::UmlPackage::eInstance()->getValueSpecification_Class());
	m_enumerationValue_Operation_specify->setName("specify");
	m_enumerationValue_Operation_specify->setLowerBound(1);
	m_enumerationValue_Operation_specify->setUpperBound(1);
	m_enumerationValue_Operation_specify->setUnique(true);
	m_enumerationValue_Operation_specify->setOrdered(false);
	
	
	m_enumerationValue_Operation_toString->setEType(ecore::EcorePackage::eInstance()->getEString_Class());
	m_enumerationValue_Operation_toString->setName("toString");
	m_enumerationValue_Operation_toString->setLowerBound(1);
	m_enumerationValue_Operation_toString->setUpperBound(1);
	m_enumerationValue_Operation_toString->setUnique(true);
	m_enumerationValue_Operation_toString->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeEvaluationContent()
{
	m_evaluation_Class->setName("Evaluation");
	m_evaluation_Class->setAbstract(true);
	m_evaluation_Class->setInterface(false);
	
	
	m_evaluation_Attribute_locus->setName("locus");
	m_evaluation_Attribute_locus->setEType(getLocus_Class());
	m_evaluation_Attribute_locus->setLowerBound(1);
	m_evaluation_Attribute_locus->setUpperBound(1);
	m_evaluation_Attribute_locus->setTransient(false);
	m_evaluation_Attribute_locus->setVolatile(false);
	m_evaluation_Attribute_locus->setChangeable(true);
	m_evaluation_Attribute_locus->setUnsettable(false);
	m_evaluation_Attribute_locus->setUnique(true);
	m_evaluation_Attribute_locus->setDerived(false);
	m_evaluation_Attribute_locus->setOrdered(false);
	m_evaluation_Attribute_locus->setContainment(false);
	m_evaluation_Attribute_locus->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_evaluation_Attribute_locus->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_evaluation_Attribute_locus->setEOpposite(otherEnd);
	    }
	}
	m_evaluation_Attribute_specification->setName("specification");
	m_evaluation_Attribute_specification->setEType(uml::UmlPackage::eInstance()->getValueSpecification_Class());
	m_evaluation_Attribute_specification->setLowerBound(1);
	m_evaluation_Attribute_specification->setUpperBound(1);
	m_evaluation_Attribute_specification->setTransient(false);
	m_evaluation_Attribute_specification->setVolatile(false);
	m_evaluation_Attribute_specification->setChangeable(true);
	m_evaluation_Attribute_specification->setUnsettable(false);
	m_evaluation_Attribute_specification->setUnique(true);
	m_evaluation_Attribute_specification->setDerived(false);
	m_evaluation_Attribute_specification->setOrdered(false);
	m_evaluation_Attribute_specification->setContainment(false);
	m_evaluation_Attribute_specification->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_evaluation_Attribute_specification->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_evaluation_Attribute_specification->setEOpposite(otherEnd);
	    }
	}
	
	m_evaluation_Operation_evaluate->setEType(getValue_Class());
	m_evaluation_Operation_evaluate->setName("evaluate");
	m_evaluation_Operation_evaluate->setLowerBound(0);
	m_evaluation_Operation_evaluate->setUpperBound(1);
	m_evaluation_Operation_evaluate->setUnique(true);
	m_evaluation_Operation_evaluate->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeEventAccepterContent()
{
	m_eventAccepter_Class->setName("EventAccepter");
	m_eventAccepter_Class->setAbstract(true);
	m_eventAccepter_Class->setInterface(false);
	
	
	
	m_eventAccepter_Operation_accept_SignalInstance->setEType(nullptr);
	m_eventAccepter_Operation_accept_SignalInstance->setName("accept");
	m_eventAccepter_Operation_accept_SignalInstance->setLowerBound(1);
	m_eventAccepter_Operation_accept_SignalInstance->setUpperBound(1);
	m_eventAccepter_Operation_accept_SignalInstance->setUnique(true);
	m_eventAccepter_Operation_accept_SignalInstance->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eventAccepter_Operation_accept_SignalInstance);
		parameter->setName("signalInstance");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_eventAccepter_Operation_match_SignalInstance->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_eventAccepter_Operation_match_SignalInstance->setName("match");
	m_eventAccepter_Operation_match_SignalInstance->setLowerBound(1);
	m_eventAccepter_Operation_match_SignalInstance->setUpperBound(1);
	m_eventAccepter_Operation_match_SignalInstance->setUnique(true);
	m_eventAccepter_Operation_match_SignalInstance->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_eventAccepter_Operation_match_SignalInstance);
		parameter->setName("signalInstance");
		parameter->setEType(getSignalInstance_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeEventDispatchLoopContent()
{
	m_eventDispatchLoop_Class->setName("EventDispatchLoop");
	m_eventDispatchLoop_Class->setAbstract(false);
	m_eventDispatchLoop_Class->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeEventOccurrenceContent()
{
	m_eventOccurrence_Class->setName("EventOccurrence");
	m_eventOccurrence_Class->setAbstract(false);
	m_eventOccurrence_Class->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeExecutionContent()
{
	m_execution_Class->setName("Execution");
	m_execution_Class->setAbstract(true);
	m_execution_Class->setInterface(false);
	
	
	m_execution_Attribute_context->setName("context");
	m_execution_Attribute_context->setEType(getObject_Class());
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_execution_Attribute_context->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_execution_Attribute_context->setEOpposite(otherEnd);
	    }
	}
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_execution_Attribute_parameterValues->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_execution_Attribute_parameterValues->setEOpposite(otherEnd);
	    }
	}
	
	m_execution_Operation_execute->setEType(nullptr);
	m_execution_Operation_execute->setName("execute");
	m_execution_Operation_execute->setLowerBound(1);
	m_execution_Operation_execute->setUpperBound(1);
	m_execution_Operation_execute->setUnique(true);
	m_execution_Operation_execute->setOrdered(false);
	
	
	m_execution_Operation_getBehavior->setEType(uml::UmlPackage::eInstance()->getBehavior_Class());
	m_execution_Operation_getBehavior->setName("getBehavior");
	m_execution_Operation_getBehavior->setLowerBound(1);
	m_execution_Operation_getBehavior->setUpperBound(1);
	m_execution_Operation_getBehavior->setUnique(true);
	m_execution_Operation_getBehavior->setOrdered(false);
	
	
	m_execution_Operation_getOutputParameterValues->setEType(getParameterValue_Class());
	m_execution_Operation_getOutputParameterValues->setName("getOutputParameterValues");
	m_execution_Operation_getOutputParameterValues->setLowerBound(0);
	m_execution_Operation_getOutputParameterValues->setUpperBound(-1);
	m_execution_Operation_getOutputParameterValues->setUnique(true);
	m_execution_Operation_getOutputParameterValues->setOrdered(false);
	
	
	m_execution_Operation_getParameterValue_Parameter->setEType(getParameterValue_Class());
	m_execution_Operation_getParameterValue_Parameter->setName("getParameterValue");
	m_execution_Operation_getParameterValue_Parameter->setLowerBound(1);
	m_execution_Operation_getParameterValue_Parameter->setUpperBound(1);
	m_execution_Operation_getParameterValue_Parameter->setUnique(true);
	m_execution_Operation_getParameterValue_Parameter->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_execution_Operation_getParameterValue_Parameter);
		parameter->setName("parameter");
		parameter->setEType(uml::UmlPackage::eInstance()->getParameter_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_execution_Operation_new_->setEType(getValue_Class());
	m_execution_Operation_new_->setName("new_");
	m_execution_Operation_new_->setLowerBound(1);
	m_execution_Operation_new_->setUpperBound(1);
	m_execution_Operation_new_->setUnique(true);
	m_execution_Operation_new_->setOrdered(false);
	
	
	m_execution_Operation_setParameterValue_ParameterValue->setEType(nullptr);
	m_execution_Operation_setParameterValue_ParameterValue->setName("setParameterValue");
	m_execution_Operation_setParameterValue_ParameterValue->setLowerBound(1);
	m_execution_Operation_setParameterValue_ParameterValue->setUpperBound(1);
	m_execution_Operation_setParameterValue_ParameterValue->setUnique(true);
	m_execution_Operation_setParameterValue_ParameterValue->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_execution_Operation_setParameterValue_ParameterValue);
		parameter->setName("parameterValue");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_execution_Operation_terminate->setEType(nullptr);
	m_execution_Operation_terminate->setName("terminate");
	m_execution_Operation_terminate->setLowerBound(1);
	m_execution_Operation_terminate->setUpperBound(1);
	m_execution_Operation_terminate->setUnique(true);
	m_execution_Operation_terminate->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeExecutionFactoryContent()
{
	m_executionFactory_Class->setName("ExecutionFactory");
	m_executionFactory_Class->setAbstract(true);
	m_executionFactory_Class->setInterface(false);
	
	
	m_executionFactory_Attribute_builtInTypes->setName("builtInTypes");
	m_executionFactory_Attribute_builtInTypes->setEType(uml::UmlPackage::eInstance()->getPrimitiveType_Class());
	m_executionFactory_Attribute_builtInTypes->setLowerBound(0);
	m_executionFactory_Attribute_builtInTypes->setUpperBound(-1);
	m_executionFactory_Attribute_builtInTypes->setTransient(false);
	m_executionFactory_Attribute_builtInTypes->setVolatile(false);
	m_executionFactory_Attribute_builtInTypes->setChangeable(true);
	m_executionFactory_Attribute_builtInTypes->setUnsettable(false);
	m_executionFactory_Attribute_builtInTypes->setUnique(true);
	m_executionFactory_Attribute_builtInTypes->setDerived(false);
	m_executionFactory_Attribute_builtInTypes->setOrdered(false);
	m_executionFactory_Attribute_builtInTypes->setContainment(false);
	m_executionFactory_Attribute_builtInTypes->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_executionFactory_Attribute_builtInTypes->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_executionFactory_Attribute_builtInTypes->setEOpposite(otherEnd);
	    }
	}
	m_executionFactory_Attribute_locus->setName("locus");
	m_executionFactory_Attribute_locus->setEType(getLocus_Class());
	m_executionFactory_Attribute_locus->setLowerBound(0);
	m_executionFactory_Attribute_locus->setUpperBound(1);
	m_executionFactory_Attribute_locus->setTransient(false);
	m_executionFactory_Attribute_locus->setVolatile(false);
	m_executionFactory_Attribute_locus->setChangeable(true);
	m_executionFactory_Attribute_locus->setUnsettable(false);
	m_executionFactory_Attribute_locus->setUnique(true);
	m_executionFactory_Attribute_locus->setDerived(false);
	m_executionFactory_Attribute_locus->setOrdered(false);
	m_executionFactory_Attribute_locus->setContainment(false);
	m_executionFactory_Attribute_locus->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_executionFactory_Attribute_locus->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getLocus_Attribute_factory();
		if (otherEnd != nullptr)
	    {
	   		m_executionFactory_Attribute_locus->setEOpposite(otherEnd);
	    }
	}
	m_executionFactory_Attribute_primitiveBehaviorPrototypes->setName("primitiveBehaviorPrototypes");
	m_executionFactory_Attribute_primitiveBehaviorPrototypes->setEType(getOpaqueBehaviorExecution_Class());
	m_executionFactory_Attribute_primitiveBehaviorPrototypes->setLowerBound(0);
	m_executionFactory_Attribute_primitiveBehaviorPrototypes->setUpperBound(-1);
	m_executionFactory_Attribute_primitiveBehaviorPrototypes->setTransient(false);
	m_executionFactory_Attribute_primitiveBehaviorPrototypes->setVolatile(false);
	m_executionFactory_Attribute_primitiveBehaviorPrototypes->setChangeable(true);
	m_executionFactory_Attribute_primitiveBehaviorPrototypes->setUnsettable(false);
	m_executionFactory_Attribute_primitiveBehaviorPrototypes->setUnique(true);
	m_executionFactory_Attribute_primitiveBehaviorPrototypes->setDerived(false);
	m_executionFactory_Attribute_primitiveBehaviorPrototypes->setOrdered(true);
	m_executionFactory_Attribute_primitiveBehaviorPrototypes->setContainment(false);
	m_executionFactory_Attribute_primitiveBehaviorPrototypes->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_executionFactory_Attribute_primitiveBehaviorPrototypes->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_executionFactory_Attribute_primitiveBehaviorPrototypes->setEOpposite(otherEnd);
	    }
	}
	m_executionFactory_Attribute_strategies->setName("strategies");
	m_executionFactory_Attribute_strategies->setEType(getSemanticStrategy_Class());
	m_executionFactory_Attribute_strategies->setLowerBound(0);
	m_executionFactory_Attribute_strategies->setUpperBound(-1);
	m_executionFactory_Attribute_strategies->setTransient(false);
	m_executionFactory_Attribute_strategies->setVolatile(false);
	m_executionFactory_Attribute_strategies->setChangeable(true);
	m_executionFactory_Attribute_strategies->setUnsettable(false);
	m_executionFactory_Attribute_strategies->setUnique(true);
	m_executionFactory_Attribute_strategies->setDerived(false);
	m_executionFactory_Attribute_strategies->setOrdered(false);
	m_executionFactory_Attribute_strategies->setContainment(false);
	m_executionFactory_Attribute_strategies->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_executionFactory_Attribute_strategies->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_executionFactory_Attribute_strategies->setEOpposite(otherEnd);
	    }
	}
	
	m_executionFactory_Operation_addBuiltInType_PrimitiveType->setEType(nullptr);
	m_executionFactory_Operation_addBuiltInType_PrimitiveType->setName("addBuiltInType");
	m_executionFactory_Operation_addBuiltInType_PrimitiveType->setLowerBound(1);
	m_executionFactory_Operation_addBuiltInType_PrimitiveType->setUpperBound(1);
	m_executionFactory_Operation_addBuiltInType_PrimitiveType->setUnique(true);
	m_executionFactory_Operation_addBuiltInType_PrimitiveType->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executionFactory_Operation_addBuiltInType_PrimitiveType);
		parameter->setName("type");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executionFactory_Operation_addPrimitiveBehaviorPrototype_OpaqueBehaviorExecution->setEType(nullptr);
	m_executionFactory_Operation_addPrimitiveBehaviorPrototype_OpaqueBehaviorExecution->setName("addPrimitiveBehaviorPrototype");
	m_executionFactory_Operation_addPrimitiveBehaviorPrototype_OpaqueBehaviorExecution->setLowerBound(1);
	m_executionFactory_Operation_addPrimitiveBehaviorPrototype_OpaqueBehaviorExecution->setUpperBound(1);
	m_executionFactory_Operation_addPrimitiveBehaviorPrototype_OpaqueBehaviorExecution->setUnique(true);
	m_executionFactory_Operation_addPrimitiveBehaviorPrototype_OpaqueBehaviorExecution->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executionFactory_Operation_addPrimitiveBehaviorPrototype_OpaqueBehaviorExecution);
		parameter->setName("execution");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executionFactory_Operation_assignStrategy_SemanticStrategy->setEType(nullptr);
	m_executionFactory_Operation_assignStrategy_SemanticStrategy->setName("assignStrategy");
	m_executionFactory_Operation_assignStrategy_SemanticStrategy->setLowerBound(1);
	m_executionFactory_Operation_assignStrategy_SemanticStrategy->setUpperBound(1);
	m_executionFactory_Operation_assignStrategy_SemanticStrategy->setUnique(true);
	m_executionFactory_Operation_assignStrategy_SemanticStrategy->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executionFactory_Operation_assignStrategy_SemanticStrategy);
		parameter->setName("strategy");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executionFactory_Operation_createEvaluation_ValueSpecification->setEType(getEvaluation_Class());
	m_executionFactory_Operation_createEvaluation_ValueSpecification->setName("createEvaluation");
	m_executionFactory_Operation_createEvaluation_ValueSpecification->setLowerBound(1);
	m_executionFactory_Operation_createEvaluation_ValueSpecification->setUpperBound(1);
	m_executionFactory_Operation_createEvaluation_ValueSpecification->setUnique(true);
	m_executionFactory_Operation_createEvaluation_ValueSpecification->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executionFactory_Operation_createEvaluation_ValueSpecification);
		parameter->setName("specification");
		parameter->setEType(uml::UmlPackage::eInstance()->getValueSpecification_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executionFactory_Operation_createExecution_Behavior_Object->setEType(getExecution_Class());
	m_executionFactory_Operation_createExecution_Behavior_Object->setName("createExecution");
	m_executionFactory_Operation_createExecution_Behavior_Object->setLowerBound(1);
	m_executionFactory_Operation_createExecution_Behavior_Object->setUpperBound(1);
	m_executionFactory_Operation_createExecution_Behavior_Object->setUnique(true);
	m_executionFactory_Operation_createExecution_Behavior_Object->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executionFactory_Operation_createExecution_Behavior_Object);
		parameter->setName("behavior");
		parameter->setEType(uml::UmlPackage::eInstance()->getBehavior_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executionFactory_Operation_createExecution_Behavior_Object);
		parameter->setName("context");
		parameter->setEType(getObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executionFactory_Operation_getBuiltInType_EString->setEType(uml::UmlPackage::eInstance()->getPrimitiveType_Class());
	m_executionFactory_Operation_getBuiltInType_EString->setName("getBuiltInType");
	m_executionFactory_Operation_getBuiltInType_EString->setLowerBound(0);
	m_executionFactory_Operation_getBuiltInType_EString->setUpperBound(1);
	m_executionFactory_Operation_getBuiltInType_EString->setUnique(true);
	m_executionFactory_Operation_getBuiltInType_EString->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executionFactory_Operation_getBuiltInType_EString);
		parameter->setName("name");
		parameter->setEType(ecore::EcorePackage::eInstance()->getEString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executionFactory_Operation_getStrategy_EString->setEType(getSemanticStrategy_Class());
	m_executionFactory_Operation_getStrategy_EString->setName("getStrategy");
	m_executionFactory_Operation_getStrategy_EString->setLowerBound(0);
	m_executionFactory_Operation_getStrategy_EString->setUpperBound(1);
	m_executionFactory_Operation_getStrategy_EString->setUnique(true);
	m_executionFactory_Operation_getStrategy_EString->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executionFactory_Operation_getStrategy_EString);
		parameter->setName("name");
		parameter->setEType(ecore::EcorePackage::eInstance()->getEString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executionFactory_Operation_getStrategyIndex_EString->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
	m_executionFactory_Operation_getStrategyIndex_EString->setName("getStrategyIndex");
	m_executionFactory_Operation_getStrategyIndex_EString->setLowerBound(1);
	m_executionFactory_Operation_getStrategyIndex_EString->setUpperBound(1);
	m_executionFactory_Operation_getStrategyIndex_EString->setUnique(true);
	m_executionFactory_Operation_getStrategyIndex_EString->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executionFactory_Operation_getStrategyIndex_EString);
		parameter->setName("name");
		parameter->setEType(ecore::EcorePackage::eInstance()->getEString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executionFactory_Operation_instantiateOpaqueBehaviorExecution_OpaqueBehavior->setEType(getOpaqueBehaviorExecution_Class());
	m_executionFactory_Operation_instantiateOpaqueBehaviorExecution_OpaqueBehavior->setName("instantiateOpaqueBehaviorExecution");
	m_executionFactory_Operation_instantiateOpaqueBehaviorExecution_OpaqueBehavior->setLowerBound(1);
	m_executionFactory_Operation_instantiateOpaqueBehaviorExecution_OpaqueBehavior->setUpperBound(1);
	m_executionFactory_Operation_instantiateOpaqueBehaviorExecution_OpaqueBehavior->setUnique(true);
	m_executionFactory_Operation_instantiateOpaqueBehaviorExecution_OpaqueBehavior->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executionFactory_Operation_instantiateOpaqueBehaviorExecution_OpaqueBehavior);
		parameter->setName("behavior");
		parameter->setEType(uml::UmlPackage::eInstance()->getOpaqueBehavior_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executionFactory_Operation_instantiateVisitor_Element->setEType(getSemanticVisitor_Class());
	m_executionFactory_Operation_instantiateVisitor_Element->setName("instantiateVisitor");
	m_executionFactory_Operation_instantiateVisitor_Element->setLowerBound(1);
	m_executionFactory_Operation_instantiateVisitor_Element->setUpperBound(1);
	m_executionFactory_Operation_instantiateVisitor_Element->setUnique(true);
	m_executionFactory_Operation_instantiateVisitor_Element->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executionFactory_Operation_instantiateVisitor_Element);
		parameter->setName("element");
		parameter->setEType(uml::UmlPackage::eInstance()->getElement_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeExecutionFactoryL1Content()
{
	m_executionFactoryL1_Class->setName("ExecutionFactoryL1");
	m_executionFactoryL1_Class->setAbstract(false);
	m_executionFactoryL1_Class->setInterface(false);
	
	
	
	m_executionFactoryL1_Operation_instantiateVisitor_Element->setEType(getSemanticVisitor_Class());
	m_executionFactoryL1_Operation_instantiateVisitor_Element->setName("instantiateVisitor");
	m_executionFactoryL1_Operation_instantiateVisitor_Element->setLowerBound(1);
	m_executionFactoryL1_Operation_instantiateVisitor_Element->setUpperBound(1);
	m_executionFactoryL1_Operation_instantiateVisitor_Element->setUnique(true);
	m_executionFactoryL1_Operation_instantiateVisitor_Element->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executionFactoryL1_Operation_instantiateVisitor_Element);
		parameter->setName("element");
		parameter->setEType(uml::UmlPackage::eInstance()->getElement_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeExecutionFactoryL2Content()
{
	m_executionFactoryL2_Class->setName("ExecutionFactoryL2");
	m_executionFactoryL2_Class->setAbstract(false);
	m_executionFactoryL2_Class->setInterface(false);
	
	
	
	m_executionFactoryL2_Operation_instantiateVisitor_Element->setEType(getSemanticVisitor_Class());
	m_executionFactoryL2_Operation_instantiateVisitor_Element->setName("instantiateVisitor");
	m_executionFactoryL2_Operation_instantiateVisitor_Element->setLowerBound(1);
	m_executionFactoryL2_Operation_instantiateVisitor_Element->setUpperBound(1);
	m_executionFactoryL2_Operation_instantiateVisitor_Element->setUnique(true);
	m_executionFactoryL2_Operation_instantiateVisitor_Element->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executionFactoryL2_Operation_instantiateVisitor_Element);
		parameter->setName("element");
		parameter->setEType(uml::UmlPackage::eInstance()->getElement_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeExecutionFactoryL3Content()
{
	m_executionFactoryL3_Class->setName("ExecutionFactoryL3");
	m_executionFactoryL3_Class->setAbstract(false);
	m_executionFactoryL3_Class->setInterface(false);
	
	
	
	m_executionFactoryL3_Operation_instantiateVisitor_Element->setEType(getSemanticVisitor_Class());
	m_executionFactoryL3_Operation_instantiateVisitor_Element->setName("instantiateVisitor");
	m_executionFactoryL3_Operation_instantiateVisitor_Element->setLowerBound(1);
	m_executionFactoryL3_Operation_instantiateVisitor_Element->setUpperBound(1);
	m_executionFactoryL3_Operation_instantiateVisitor_Element->setUnique(true);
	m_executionFactoryL3_Operation_instantiateVisitor_Element->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executionFactoryL3_Operation_instantiateVisitor_Element);
		parameter->setName("element");
		parameter->setEType(uml::UmlPackage::eInstance()->getElement_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeExecutorContent()
{
	m_executor_Class->setName("Executor");
	m_executor_Class->setAbstract(false);
	m_executor_Class->setInterface(false);
	
	
	m_executor_Attribute_locus->setName("locus");
	m_executor_Attribute_locus->setEType(getLocus_Class());
	m_executor_Attribute_locus->setLowerBound(0);
	m_executor_Attribute_locus->setUpperBound(1);
	m_executor_Attribute_locus->setTransient(false);
	m_executor_Attribute_locus->setVolatile(false);
	m_executor_Attribute_locus->setChangeable(true);
	m_executor_Attribute_locus->setUnsettable(false);
	m_executor_Attribute_locus->setUnique(true);
	m_executor_Attribute_locus->setDerived(false);
	m_executor_Attribute_locus->setOrdered(false);
	m_executor_Attribute_locus->setContainment(false);
	m_executor_Attribute_locus->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_executor_Attribute_locus->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getLocus_Attribute_executor();
		if (otherEnd != nullptr)
	    {
	   		m_executor_Attribute_locus->setEOpposite(otherEnd);
	    }
	}
	
	m_executor_Operation_evaluate_ValueSpecification->setEType(getValue_Class());
	m_executor_Operation_evaluate_ValueSpecification->setName("evaluate");
	m_executor_Operation_evaluate_ValueSpecification->setLowerBound(1);
	m_executor_Operation_evaluate_ValueSpecification->setUpperBound(1);
	m_executor_Operation_evaluate_ValueSpecification->setUnique(true);
	m_executor_Operation_evaluate_ValueSpecification->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executor_Operation_evaluate_ValueSpecification);
		parameter->setName("specification");
		parameter->setEType(uml::UmlPackage::eInstance()->getValueSpecification_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executor_Operation_execute_Behavior_ParameterValue->setEType(getParameterValue_Class());
	m_executor_Operation_execute_Behavior_ParameterValue->setName("execute");
	m_executor_Operation_execute_Behavior_ParameterValue->setLowerBound(0);
	m_executor_Operation_execute_Behavior_ParameterValue->setUpperBound(-1);
	m_executor_Operation_execute_Behavior_ParameterValue->setUnique(true);
	m_executor_Operation_execute_Behavior_ParameterValue->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executor_Operation_execute_Behavior_ParameterValue);
		parameter->setName("behavior");
		parameter->setEType(uml::UmlPackage::eInstance()->getBehavior_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executor_Operation_execute_Behavior_ParameterValue);
		parameter->setName("context");
		parameter->setEType(getObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executor_Operation_execute_Behavior_ParameterValue);
		parameter->setName("inputs");
		parameter->setEType(getParameterValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_executor_Operation_start_Class_ParameterValue->setEType(getReference_Class());
	m_executor_Operation_start_Class_ParameterValue->setName("start");
	m_executor_Operation_start_Class_ParameterValue->setLowerBound(1);
	m_executor_Operation_start_Class_ParameterValue->setUpperBound(1);
	m_executor_Operation_start_Class_ParameterValue->setUnique(true);
	m_executor_Operation_start_Class_ParameterValue->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executor_Operation_start_Class_ParameterValue);
		parameter->setName("type");
		parameter->setEType(uml::UmlPackage::eInstance()->getClass_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_executor_Operation_start_Class_ParameterValue);
		parameter->setName("inputs");
		parameter->setEType(getParameterValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeExpansionActivationGroupContent()
{
	m_expansionActivationGroup_Class->setName("ExpansionActivationGroup");
	m_expansionActivationGroup_Class->setAbstract(false);
	m_expansionActivationGroup_Class->setInterface(false);
	
	
	m_expansionActivationGroup_Attribute_regionActivation->setName("regionActivation");
	m_expansionActivationGroup_Attribute_regionActivation->setEType(getExpansionRegionActivation_Class());
	m_expansionActivationGroup_Attribute_regionActivation->setLowerBound(1);
	m_expansionActivationGroup_Attribute_regionActivation->setUpperBound(1);
	m_expansionActivationGroup_Attribute_regionActivation->setTransient(false);
	m_expansionActivationGroup_Attribute_regionActivation->setVolatile(false);
	m_expansionActivationGroup_Attribute_regionActivation->setChangeable(true);
	m_expansionActivationGroup_Attribute_regionActivation->setUnsettable(false);
	m_expansionActivationGroup_Attribute_regionActivation->setUnique(true);
	m_expansionActivationGroup_Attribute_regionActivation->setDerived(false);
	m_expansionActivationGroup_Attribute_regionActivation->setOrdered(false);
	m_expansionActivationGroup_Attribute_regionActivation->setContainment(false);
	m_expansionActivationGroup_Attribute_regionActivation->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_expansionActivationGroup_Attribute_regionActivation->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_expansionActivationGroup_Attribute_regionActivation->setEOpposite(otherEnd);
	    }
	}
	
	
}

void FUMLPackageImpl::initializeExpansionNodeActivationContent()
{
	m_expansionNodeActivation_Class->setName("ExpansionNodeActivation");
	m_expansionNodeActivation_Class->setAbstract(false);
	m_expansionNodeActivation_Class->setInterface(false);
	
	
	
	m_expansionNodeActivation_Operation_getExpansionRegionActivation->setEType(getExpansionRegionActivation_Class());
	m_expansionNodeActivation_Operation_getExpansionRegionActivation->setName("getExpansionRegionActivation");
	m_expansionNodeActivation_Operation_getExpansionRegionActivation->setLowerBound(1);
	m_expansionNodeActivation_Operation_getExpansionRegionActivation->setUpperBound(1);
	m_expansionNodeActivation_Operation_getExpansionRegionActivation->setUnique(true);
	m_expansionNodeActivation_Operation_getExpansionRegionActivation->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeExpansionRegionActivationContent()
{
	m_expansionRegionActivation_Class->setName("ExpansionRegionActivation");
	m_expansionRegionActivation_Class->setAbstract(false);
	m_expansionRegionActivation_Class->setInterface(false);
	
	
	m_expansionRegionActivation_Attribute_activationGroups->setName("activationGroups");
	m_expansionRegionActivation_Attribute_activationGroups->setEType(getExpansionActivationGroup_Class());
	m_expansionRegionActivation_Attribute_activationGroups->setLowerBound(0);
	m_expansionRegionActivation_Attribute_activationGroups->setUpperBound(-1);
	m_expansionRegionActivation_Attribute_activationGroups->setTransient(false);
	m_expansionRegionActivation_Attribute_activationGroups->setVolatile(false);
	m_expansionRegionActivation_Attribute_activationGroups->setChangeable(true);
	m_expansionRegionActivation_Attribute_activationGroups->setUnsettable(false);
	m_expansionRegionActivation_Attribute_activationGroups->setUnique(true);
	m_expansionRegionActivation_Attribute_activationGroups->setDerived(false);
	m_expansionRegionActivation_Attribute_activationGroups->setOrdered(false);
	m_expansionRegionActivation_Attribute_activationGroups->setContainment(false);
	m_expansionRegionActivation_Attribute_activationGroups->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_expansionRegionActivation_Attribute_activationGroups->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_expansionRegionActivation_Attribute_activationGroups->setEOpposite(otherEnd);
	    }
	}
	m_expansionRegionActivation_Attribute_inputExpansionTokens->setName("inputExpansionTokens");
	m_expansionRegionActivation_Attribute_inputExpansionTokens->setEType(getTokenSet_Class());
	m_expansionRegionActivation_Attribute_inputExpansionTokens->setLowerBound(1);
	m_expansionRegionActivation_Attribute_inputExpansionTokens->setUpperBound(-1);
	m_expansionRegionActivation_Attribute_inputExpansionTokens->setTransient(false);
	m_expansionRegionActivation_Attribute_inputExpansionTokens->setVolatile(false);
	m_expansionRegionActivation_Attribute_inputExpansionTokens->setChangeable(true);
	m_expansionRegionActivation_Attribute_inputExpansionTokens->setUnsettable(false);
	m_expansionRegionActivation_Attribute_inputExpansionTokens->setUnique(true);
	m_expansionRegionActivation_Attribute_inputExpansionTokens->setDerived(false);
	m_expansionRegionActivation_Attribute_inputExpansionTokens->setOrdered(false);
	m_expansionRegionActivation_Attribute_inputExpansionTokens->setContainment(false);
	m_expansionRegionActivation_Attribute_inputExpansionTokens->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_expansionRegionActivation_Attribute_inputExpansionTokens->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_expansionRegionActivation_Attribute_inputExpansionTokens->setEOpposite(otherEnd);
	    }
	}
	m_expansionRegionActivation_Attribute_inputTokens->setName("inputTokens");
	m_expansionRegionActivation_Attribute_inputTokens->setEType(getTokenSet_Class());
	m_expansionRegionActivation_Attribute_inputTokens->setLowerBound(0);
	m_expansionRegionActivation_Attribute_inputTokens->setUpperBound(-1);
	m_expansionRegionActivation_Attribute_inputTokens->setTransient(false);
	m_expansionRegionActivation_Attribute_inputTokens->setVolatile(false);
	m_expansionRegionActivation_Attribute_inputTokens->setChangeable(true);
	m_expansionRegionActivation_Attribute_inputTokens->setUnsettable(false);
	m_expansionRegionActivation_Attribute_inputTokens->setUnique(true);
	m_expansionRegionActivation_Attribute_inputTokens->setDerived(false);
	m_expansionRegionActivation_Attribute_inputTokens->setOrdered(false);
	m_expansionRegionActivation_Attribute_inputTokens->setContainment(false);
	m_expansionRegionActivation_Attribute_inputTokens->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_expansionRegionActivation_Attribute_inputTokens->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_expansionRegionActivation_Attribute_inputTokens->setEOpposite(otherEnd);
	    }
	}
	
	m_expansionRegionActivation_Operation_doStructuredActivity->setEType(nullptr);
	m_expansionRegionActivation_Operation_doStructuredActivity->setName("doStructuredActivity");
	m_expansionRegionActivation_Operation_doStructuredActivity->setLowerBound(1);
	m_expansionRegionActivation_Operation_doStructuredActivity->setUpperBound(1);
	m_expansionRegionActivation_Operation_doStructuredActivity->setUnique(true);
	m_expansionRegionActivation_Operation_doStructuredActivity->setOrdered(false);
	
	
	m_expansionRegionActivation_Operation_getExpansionNodeActivation_ExpansionNode->setEType(getExpansionNodeActivation_Class());
	m_expansionRegionActivation_Operation_getExpansionNodeActivation_ExpansionNode->setName("getExpansionNodeActivation");
	m_expansionRegionActivation_Operation_getExpansionNodeActivation_ExpansionNode->setLowerBound(1);
	m_expansionRegionActivation_Operation_getExpansionNodeActivation_ExpansionNode->setUpperBound(1);
	m_expansionRegionActivation_Operation_getExpansionNodeActivation_ExpansionNode->setUnique(true);
	m_expansionRegionActivation_Operation_getExpansionNodeActivation_ExpansionNode->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_expansionRegionActivation_Operation_getExpansionNodeActivation_ExpansionNode);
		parameter->setName("node");
		parameter->setEType(uml::UmlPackage::eInstance()->getExpansionNode_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_expansionRegionActivation_Operation_numberOfValues->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
	m_expansionRegionActivation_Operation_numberOfValues->setName("numberOfValues");
	m_expansionRegionActivation_Operation_numberOfValues->setLowerBound(1);
	m_expansionRegionActivation_Operation_numberOfValues->setUpperBound(1);
	m_expansionRegionActivation_Operation_numberOfValues->setUnique(true);
	m_expansionRegionActivation_Operation_numberOfValues->setOrdered(false);
	
	
	m_expansionRegionActivation_Operation_runGroup_ExpansionActivationGroup->setEType(nullptr);
	m_expansionRegionActivation_Operation_runGroup_ExpansionActivationGroup->setName("runGroup");
	m_expansionRegionActivation_Operation_runGroup_ExpansionActivationGroup->setLowerBound(1);
	m_expansionRegionActivation_Operation_runGroup_ExpansionActivationGroup->setUpperBound(1);
	m_expansionRegionActivation_Operation_runGroup_ExpansionActivationGroup->setUnique(true);
	m_expansionRegionActivation_Operation_runGroup_ExpansionActivationGroup->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_expansionRegionActivation_Operation_runGroup_ExpansionActivationGroup);
		parameter->setName("activationGroup");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeExtensionalValueContent()
{
	m_extensionalValue_Class->setName("ExtensionalValue");
	m_extensionalValue_Class->setAbstract(true);
	m_extensionalValue_Class->setInterface(false);
	
	
	m_extensionalValue_Attribute_locus->setName("locus");
	m_extensionalValue_Attribute_locus->setEType(getLocus_Class());
	m_extensionalValue_Attribute_locus->setLowerBound(0);
	m_extensionalValue_Attribute_locus->setUpperBound(1);
	m_extensionalValue_Attribute_locus->setTransient(false);
	m_extensionalValue_Attribute_locus->setVolatile(false);
	m_extensionalValue_Attribute_locus->setChangeable(true);
	m_extensionalValue_Attribute_locus->setUnsettable(false);
	m_extensionalValue_Attribute_locus->setUnique(true);
	m_extensionalValue_Attribute_locus->setDerived(false);
	m_extensionalValue_Attribute_locus->setOrdered(false);
	m_extensionalValue_Attribute_locus->setContainment(false);
	m_extensionalValue_Attribute_locus->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_extensionalValue_Attribute_locus->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_extensionalValue_Attribute_locus->setEOpposite(otherEnd);
	    }
	}
	
	m_extensionalValue_Operation_destroy->setEType(nullptr);
	m_extensionalValue_Operation_destroy->setName("destroy");
	m_extensionalValue_Operation_destroy->setLowerBound(1);
	m_extensionalValue_Operation_destroy->setUpperBound(1);
	m_extensionalValue_Operation_destroy->setUnique(true);
	m_extensionalValue_Operation_destroy->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeExtensionalValueListContent()
{
	m_extensionalValueList_Class->setName("ExtensionalValueList");
	m_extensionalValueList_Class->setAbstract(false);
	m_extensionalValueList_Class->setInterface(false);
	
	
	
	m_extensionalValueList_Operation_addValue_ExtensionalValue->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_extensionalValueList_Operation_addValue_ExtensionalValue->setName("addValue");
	m_extensionalValueList_Operation_addValue_ExtensionalValue->setLowerBound(1);
	m_extensionalValueList_Operation_addValue_ExtensionalValue->setUpperBound(1);
	m_extensionalValueList_Operation_addValue_ExtensionalValue->setUnique(true);
	m_extensionalValueList_Operation_addValue_ExtensionalValue->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_extensionalValueList_Operation_addValue_ExtensionalValue);
		parameter->setName("value");
		parameter->setEType(getExtensionalValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_extensionalValueList_Operation_addValue_ExtensionalValue_EInt->setEType(nullptr);
	m_extensionalValueList_Operation_addValue_ExtensionalValue_EInt->setName("addValue");
	m_extensionalValueList_Operation_addValue_ExtensionalValue_EInt->setLowerBound(1);
	m_extensionalValueList_Operation_addValue_ExtensionalValue_EInt->setUpperBound(1);
	m_extensionalValueList_Operation_addValue_ExtensionalValue_EInt->setUnique(true);
	m_extensionalValueList_Operation_addValue_ExtensionalValue_EInt->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_extensionalValueList_Operation_addValue_ExtensionalValue_EInt);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_extensionalValueList_Operation_addValue_ExtensionalValue_EInt);
		parameter->setName("i");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_extensionalValueList_Operation_getValue->setEType(getExtensionalValue_Class());
	m_extensionalValueList_Operation_getValue->setName("getValue");
	m_extensionalValueList_Operation_getValue->setLowerBound(1);
	m_extensionalValueList_Operation_getValue->setUpperBound(1);
	m_extensionalValueList_Operation_getValue->setUnique(true);
	m_extensionalValueList_Operation_getValue->setOrdered(false);
	
	
	m_extensionalValueList_Operation_removeValue_EInt->setEType(ecore::EcorePackage::eInstance()->getEString_Class());
	m_extensionalValueList_Operation_removeValue_EInt->setName("removeValue");
	m_extensionalValueList_Operation_removeValue_EInt->setLowerBound(1);
	m_extensionalValueList_Operation_removeValue_EInt->setUpperBound(1);
	m_extensionalValueList_Operation_removeValue_EInt->setUnique(true);
	m_extensionalValueList_Operation_removeValue_EInt->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_extensionalValueList_Operation_removeValue_EInt);
		parameter->setName("i");
		parameter->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_extensionalValueList_Operation_setValue_ExtensionalValue_EInt->setEType(getValue_Class());
	m_extensionalValueList_Operation_setValue_ExtensionalValue_EInt->setName("setValue");
	m_extensionalValueList_Operation_setValue_ExtensionalValue_EInt->setLowerBound(1);
	m_extensionalValueList_Operation_setValue_ExtensionalValue_EInt->setUpperBound(1);
	m_extensionalValueList_Operation_setValue_ExtensionalValue_EInt->setUnique(true);
	m_extensionalValueList_Operation_setValue_ExtensionalValue_EInt->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_extensionalValueList_Operation_setValue_ExtensionalValue_EInt);
		parameter->setName("value");
		parameter->setEType(getExtensionalValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_extensionalValueList_Operation_setValue_ExtensionalValue_EInt);
		parameter->setName("i");
		parameter->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeFIFOGetNextEventStrategyContent()
{
	m_fIFOGetNextEventStrategy_Class->setName("FIFOGetNextEventStrategy");
	m_fIFOGetNextEventStrategy_Class->setAbstract(false);
	m_fIFOGetNextEventStrategy_Class->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeFeatureValueContent()
{
	m_featureValue_Class->setName("FeatureValue");
	m_featureValue_Class->setAbstract(false);
	m_featureValue_Class->setInterface(false);
	
	m_featureValue_Attribute_position = getFeatureValue_Attribute_position();
	m_featureValue_Attribute_position->setName("position");
	m_featureValue_Attribute_position->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
	m_featureValue_Attribute_position->setLowerBound(0);
	m_featureValue_Attribute_position->setUpperBound(1);
	m_featureValue_Attribute_position->setTransient(false);
	m_featureValue_Attribute_position->setVolatile(false);
	m_featureValue_Attribute_position->setChangeable(true);
	m_featureValue_Attribute_position->setUnsettable(false);
	m_featureValue_Attribute_position->setUnique(true);
	m_featureValue_Attribute_position->setDerived(false);
	m_featureValue_Attribute_position->setOrdered(false);
	m_featureValue_Attribute_position->setID(false);
	{
		std::string defaultValue = "0";
		if (!defaultValue.empty())
		{
		   m_featureValue_Attribute_position->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_featureValue_Attribute_feature->setName("feature");
	m_featureValue_Attribute_feature->setEType(uml::UmlPackage::eInstance()->getStructuralFeature_Class());
	m_featureValue_Attribute_feature->setLowerBound(1);
	m_featureValue_Attribute_feature->setUpperBound(1);
	m_featureValue_Attribute_feature->setTransient(false);
	m_featureValue_Attribute_feature->setVolatile(false);
	m_featureValue_Attribute_feature->setChangeable(true);
	m_featureValue_Attribute_feature->setUnsettable(false);
	m_featureValue_Attribute_feature->setUnique(true);
	m_featureValue_Attribute_feature->setDerived(false);
	m_featureValue_Attribute_feature->setOrdered(false);
	m_featureValue_Attribute_feature->setContainment(false);
	m_featureValue_Attribute_feature->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_featureValue_Attribute_feature->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_featureValue_Attribute_feature->setEOpposite(otherEnd);
	    }
	}
	m_featureValue_Attribute_values->setName("values");
	m_featureValue_Attribute_values->setEType(getValue_Class());
	m_featureValue_Attribute_values->setLowerBound(0);
	m_featureValue_Attribute_values->setUpperBound(-1);
	m_featureValue_Attribute_values->setTransient(false);
	m_featureValue_Attribute_values->setVolatile(false);
	m_featureValue_Attribute_values->setChangeable(true);
	m_featureValue_Attribute_values->setUnsettable(false);
	m_featureValue_Attribute_values->setUnique(true);
	m_featureValue_Attribute_values->setDerived(false);
	m_featureValue_Attribute_values->setOrdered(false);
	m_featureValue_Attribute_values->setContainment(true);
	m_featureValue_Attribute_values->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_featureValue_Attribute_values->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_featureValue_Attribute_values->setEOpposite(otherEnd);
	    }
	}
	
	m_featureValue_Operation_hasEqualValues_FeatureValue->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_featureValue_Operation_hasEqualValues_FeatureValue->setName("hasEqualValues");
	m_featureValue_Operation_hasEqualValues_FeatureValue->setLowerBound(1);
	m_featureValue_Operation_hasEqualValues_FeatureValue->setUpperBound(1);
	m_featureValue_Operation_hasEqualValues_FeatureValue->setUnique(true);
	m_featureValue_Operation_hasEqualValues_FeatureValue->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_featureValue_Operation_hasEqualValues_FeatureValue);
		parameter->setName("other");
		parameter->setEType(getFeatureValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeFirstChoiceStrategyContent()
{
	m_firstChoiceStrategy_Class->setName("FirstChoiceStrategy");
	m_firstChoiceStrategy_Class->setAbstract(false);
	m_firstChoiceStrategy_Class->setInterface(false);
	
	
	
	m_firstChoiceStrategy_Operation_choose_EInt->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
	m_firstChoiceStrategy_Operation_choose_EInt->setName("choose");
	m_firstChoiceStrategy_Operation_choose_EInt->setLowerBound(1);
	m_firstChoiceStrategy_Operation_choose_EInt->setUpperBound(1);
	m_firstChoiceStrategy_Operation_choose_EInt->setUnique(true);
	m_firstChoiceStrategy_Operation_choose_EInt->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_firstChoiceStrategy_Operation_choose_EInt);
		parameter->setName("size");
		parameter->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeFlowFinalNodeActivationContent()
{
	m_flowFinalNodeActivation_Class->setName("FlowFinalNodeActivation");
	m_flowFinalNodeActivation_Class->setAbstract(false);
	m_flowFinalNodeActivation_Class->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeForkNodeActivationContent()
{
	m_forkNodeActivation_Class->setName("ForkNodeActivation");
	m_forkNodeActivation_Class->setAbstract(false);
	m_forkNodeActivation_Class->setInterface(false);
	
	
	
	m_forkNodeActivation_Operation_fire_Token->setEType(nullptr);
	m_forkNodeActivation_Operation_fire_Token->setName("fire");
	m_forkNodeActivation_Operation_fire_Token->setLowerBound(1);
	m_forkNodeActivation_Operation_fire_Token->setUpperBound(1);
	m_forkNodeActivation_Operation_fire_Token->setUnique(true);
	m_forkNodeActivation_Operation_fire_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_forkNodeActivation_Operation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_forkNodeActivation_Operation_terminate->setEType(nullptr);
	m_forkNodeActivation_Operation_terminate->setName("terminate");
	m_forkNodeActivation_Operation_terminate->setLowerBound(1);
	m_forkNodeActivation_Operation_terminate->setUpperBound(1);
	m_forkNodeActivation_Operation_terminate->setUnique(true);
	m_forkNodeActivation_Operation_terminate->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeForkedTokenContent()
{
	m_forkedToken_Class->setName("ForkedToken");
	m_forkedToken_Class->setAbstract(false);
	m_forkedToken_Class->setInterface(false);
	
	m_forkedToken_Attribute_baseTokenIsWithdrawn = getForkedToken_Attribute_baseTokenIsWithdrawn();
	m_forkedToken_Attribute_baseTokenIsWithdrawn->setName("baseTokenIsWithdrawn");
	m_forkedToken_Attribute_baseTokenIsWithdrawn->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_forkedToken_Attribute_baseTokenIsWithdrawn->setLowerBound(1);
	m_forkedToken_Attribute_baseTokenIsWithdrawn->setUpperBound(1);
	m_forkedToken_Attribute_baseTokenIsWithdrawn->setTransient(false);
	m_forkedToken_Attribute_baseTokenIsWithdrawn->setVolatile(false);
	m_forkedToken_Attribute_baseTokenIsWithdrawn->setChangeable(true);
	m_forkedToken_Attribute_baseTokenIsWithdrawn->setUnsettable(false);
	m_forkedToken_Attribute_baseTokenIsWithdrawn->setUnique(true);
	m_forkedToken_Attribute_baseTokenIsWithdrawn->setDerived(false);
	m_forkedToken_Attribute_baseTokenIsWithdrawn->setOrdered(false);
	m_forkedToken_Attribute_baseTokenIsWithdrawn->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_forkedToken_Attribute_baseTokenIsWithdrawn->setDefaultValueLiteral(defaultValue);
		}
	}
	m_forkedToken_Attribute_remainingOffersCount = getForkedToken_Attribute_remainingOffersCount();
	m_forkedToken_Attribute_remainingOffersCount->setName("remainingOffersCount");
	m_forkedToken_Attribute_remainingOffersCount->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
	m_forkedToken_Attribute_remainingOffersCount->setLowerBound(1);
	m_forkedToken_Attribute_remainingOffersCount->setUpperBound(1);
	m_forkedToken_Attribute_remainingOffersCount->setTransient(false);
	m_forkedToken_Attribute_remainingOffersCount->setVolatile(false);
	m_forkedToken_Attribute_remainingOffersCount->setChangeable(true);
	m_forkedToken_Attribute_remainingOffersCount->setUnsettable(false);
	m_forkedToken_Attribute_remainingOffersCount->setUnique(true);
	m_forkedToken_Attribute_remainingOffersCount->setDerived(false);
	m_forkedToken_Attribute_remainingOffersCount->setOrdered(false);
	m_forkedToken_Attribute_remainingOffersCount->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_forkedToken_Attribute_remainingOffersCount->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_forkedToken_Attribute_baseToken->setName("baseToken");
	m_forkedToken_Attribute_baseToken->setEType(getToken_Class());
	m_forkedToken_Attribute_baseToken->setLowerBound(0);
	m_forkedToken_Attribute_baseToken->setUpperBound(1);
	m_forkedToken_Attribute_baseToken->setTransient(false);
	m_forkedToken_Attribute_baseToken->setVolatile(false);
	m_forkedToken_Attribute_baseToken->setChangeable(true);
	m_forkedToken_Attribute_baseToken->setUnsettable(false);
	m_forkedToken_Attribute_baseToken->setUnique(true);
	m_forkedToken_Attribute_baseToken->setDerived(false);
	m_forkedToken_Attribute_baseToken->setOrdered(false);
	m_forkedToken_Attribute_baseToken->setContainment(false);
	m_forkedToken_Attribute_baseToken->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_forkedToken_Attribute_baseToken->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_forkedToken_Attribute_baseToken->setEOpposite(otherEnd);
	    }
	}
	
	m_forkedToken_Operation_equals_Token->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_forkedToken_Operation_equals_Token->setName("equals");
	m_forkedToken_Operation_equals_Token->setLowerBound(1);
	m_forkedToken_Operation_equals_Token->setUpperBound(1);
	m_forkedToken_Operation_equals_Token->setUnique(true);
	m_forkedToken_Operation_equals_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_forkedToken_Operation_equals_Token);
		parameter->setName("otherToken");
		parameter->setEType(getToken_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_forkedToken_Operation_getValue->setEType(getValue_Class());
	m_forkedToken_Operation_getValue->setName("getValue");
	m_forkedToken_Operation_getValue->setLowerBound(0);
	m_forkedToken_Operation_getValue->setUpperBound(1);
	m_forkedToken_Operation_getValue->setUnique(true);
	m_forkedToken_Operation_getValue->setOrdered(false);
	
	
	m_forkedToken_Operation_isControl->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_forkedToken_Operation_isControl->setName("isControl");
	m_forkedToken_Operation_isControl->setLowerBound(1);
	m_forkedToken_Operation_isControl->setUpperBound(1);
	m_forkedToken_Operation_isControl->setUnique(true);
	m_forkedToken_Operation_isControl->setOrdered(false);
	
	
	m_forkedToken_Operation_withdraw->setEType(nullptr);
	m_forkedToken_Operation_withdraw->setName("withdraw");
	m_forkedToken_Operation_withdraw->setLowerBound(1);
	m_forkedToken_Operation_withdraw->setUpperBound(1);
	m_forkedToken_Operation_withdraw->setUnique(true);
	m_forkedToken_Operation_withdraw->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeGetNextEventStrategyContent()
{
	m_getNextEventStrategy_Class->setName("GetNextEventStrategy");
	m_getNextEventStrategy_Class->setAbstract(true);
	m_getNextEventStrategy_Class->setInterface(false);
	
	
	
	m_getNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation->setEType(getSignalInstance_Class());
	m_getNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation->setName("retrieveNextEvent");
	m_getNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation->setLowerBound(1);
	m_getNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation->setUpperBound(1);
	m_getNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation->setUnique(true);
	m_getNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_getNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation);
		parameter->setName("objectActivation");
		parameter->setEType(getObjectActivation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeInitialNodeActivationContent()
{
	m_initialNodeActivation_Class->setName("InitialNodeActivation");
	m_initialNodeActivation_Class->setAbstract(false);
	m_initialNodeActivation_Class->setInterface(false);
	
	
	
	m_initialNodeActivation_Operation_fire_Token->setEType(nullptr);
	m_initialNodeActivation_Operation_fire_Token->setName("fire");
	m_initialNodeActivation_Operation_fire_Token->setLowerBound(1);
	m_initialNodeActivation_Operation_fire_Token->setUpperBound(1);
	m_initialNodeActivation_Operation_fire_Token->setUnique(true);
	m_initialNodeActivation_Operation_fire_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_initialNodeActivation_Operation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeInputPinActivationContent()
{
	m_inputPinActivation_Class->setName("InputPinActivation");
	m_inputPinActivation_Class->setAbstract(false);
	m_inputPinActivation_Class->setInterface(false);
	
	
	
	m_inputPinActivation_Operation_isReady->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_inputPinActivation_Operation_isReady->setName("isReady");
	m_inputPinActivation_Operation_isReady->setLowerBound(1);
	m_inputPinActivation_Operation_isReady->setUpperBound(1);
	m_inputPinActivation_Operation_isReady->setUnique(true);
	m_inputPinActivation_Operation_isReady->setOrdered(false);
	
	
	m_inputPinActivation_Operation_recieveOffer->setEType(nullptr);
	m_inputPinActivation_Operation_recieveOffer->setName("recieveOffer");
	m_inputPinActivation_Operation_recieveOffer->setLowerBound(1);
	m_inputPinActivation_Operation_recieveOffer->setUpperBound(1);
	m_inputPinActivation_Operation_recieveOffer->setUnique(true);
	m_inputPinActivation_Operation_recieveOffer->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeInstanceValueEvaluationContent()
{
	m_instanceValueEvaluation_Class->setName("InstanceValueEvaluation");
	m_instanceValueEvaluation_Class->setAbstract(false);
	m_instanceValueEvaluation_Class->setInterface(false);
	
	
	
	m_instanceValueEvaluation_Operation_evaluate->setEType(getValue_Class());
	m_instanceValueEvaluation_Operation_evaluate->setName("evaluate");
	m_instanceValueEvaluation_Operation_evaluate->setLowerBound(0);
	m_instanceValueEvaluation_Operation_evaluate->setUpperBound(1);
	m_instanceValueEvaluation_Operation_evaluate->setUnique(true);
	m_instanceValueEvaluation_Operation_evaluate->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeIntegerValueContent()
{
	m_integerValue_Class->setName("IntegerValue");
	m_integerValue_Class->setAbstract(false);
	m_integerValue_Class->setInterface(false);
	
	m_integerValue_Attribute_value = getIntegerValue_Attribute_value();
	m_integerValue_Attribute_value->setName("value");
	m_integerValue_Attribute_value->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
	m_integerValue_Attribute_value->setLowerBound(1);
	m_integerValue_Attribute_value->setUpperBound(1);
	m_integerValue_Attribute_value->setTransient(false);
	m_integerValue_Attribute_value->setVolatile(false);
	m_integerValue_Attribute_value->setChangeable(true);
	m_integerValue_Attribute_value->setUnsettable(false);
	m_integerValue_Attribute_value->setUnique(true);
	m_integerValue_Attribute_value->setDerived(false);
	m_integerValue_Attribute_value->setOrdered(false);
	m_integerValue_Attribute_value->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_integerValue_Attribute_value->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	m_integerValue_Operation_equals_Value->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_integerValue_Operation_equals_Value->setName("equals");
	m_integerValue_Operation_equals_Value->setLowerBound(1);
	m_integerValue_Operation_equals_Value->setUpperBound(1);
	m_integerValue_Operation_equals_Value->setUnique(true);
	m_integerValue_Operation_equals_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_integerValue_Operation_equals_Value);
		parameter->setName("otherValue");
		parameter->setEType(getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_integerValue_Operation_specify->setEType(uml::UmlPackage::eInstance()->getValueSpecification_Class());
	m_integerValue_Operation_specify->setName("specify");
	m_integerValue_Operation_specify->setLowerBound(1);
	m_integerValue_Operation_specify->setUpperBound(1);
	m_integerValue_Operation_specify->setUnique(true);
	m_integerValue_Operation_specify->setOrdered(false);
	
	
	m_integerValue_Operation_toString->setEType(ecore::EcorePackage::eInstance()->getEString_Class());
	m_integerValue_Operation_toString->setName("toString");
	m_integerValue_Operation_toString->setLowerBound(1);
	m_integerValue_Operation_toString->setUpperBound(1);
	m_integerValue_Operation_toString->setUnique(true);
	m_integerValue_Operation_toString->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeInvocationActionActivationContent()
{
	m_invocationActionActivation_Class->setName("InvocationActionActivation");
	m_invocationActionActivation_Class->setAbstract(true);
	m_invocationActionActivation_Class->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeJoinNodeActivationContent()
{
	m_joinNodeActivation_Class->setName("JoinNodeActivation");
	m_joinNodeActivation_Class->setAbstract(false);
	m_joinNodeActivation_Class->setInterface(false);
	
	
	
	m_joinNodeActivation_Operation_isReady->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_joinNodeActivation_Operation_isReady->setName("isReady");
	m_joinNodeActivation_Operation_isReady->setLowerBound(1);
	m_joinNodeActivation_Operation_isReady->setUpperBound(1);
	m_joinNodeActivation_Operation_isReady->setUnique(true);
	m_joinNodeActivation_Operation_isReady->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeLinkContent()
{
	m_link_Class->setName("Link");
	m_link_Class->setAbstract(false);
	m_link_Class->setInterface(false);
	
	
	m_link_Attribute_type->setName("type");
	m_link_Attribute_type->setEType(uml::UmlPackage::eInstance()->getAssociation_Class());
	m_link_Attribute_type->setLowerBound(0);
	m_link_Attribute_type->setUpperBound(1);
	m_link_Attribute_type->setTransient(false);
	m_link_Attribute_type->setVolatile(false);
	m_link_Attribute_type->setChangeable(true);
	m_link_Attribute_type->setUnsettable(false);
	m_link_Attribute_type->setUnique(true);
	m_link_Attribute_type->setDerived(false);
	m_link_Attribute_type->setOrdered(false);
	m_link_Attribute_type->setContainment(false);
	m_link_Attribute_type->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_link_Attribute_type->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_link_Attribute_type->setEOpposite(otherEnd);
	    }
	}
	
	m_link_Operation_addTo_Locus->setEType(nullptr);
	m_link_Operation_addTo_Locus->setName("addTo");
	m_link_Operation_addTo_Locus->setLowerBound(0);
	m_link_Operation_addTo_Locus->setUpperBound(1);
	m_link_Operation_addTo_Locus->setUnique(true);
	m_link_Operation_addTo_Locus->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_link_Operation_addTo_Locus);
		parameter->setName("locus");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_link_Operation_getOtherFeatureValues_ExtensionalValue_Property->setEType(getFeatureValue_Class());
	m_link_Operation_getOtherFeatureValues_ExtensionalValue_Property->setName("getOtherFeatureValues");
	m_link_Operation_getOtherFeatureValues_ExtensionalValue_Property->setLowerBound(0);
	m_link_Operation_getOtherFeatureValues_ExtensionalValue_Property->setUpperBound(-1);
	m_link_Operation_getOtherFeatureValues_ExtensionalValue_Property->setUnique(true);
	m_link_Operation_getOtherFeatureValues_ExtensionalValue_Property->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_link_Operation_getOtherFeatureValues_ExtensionalValue_Property);
		parameter->setName("extent");
		parameter->setEType(getExtensionalValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_link_Operation_getOtherFeatureValues_ExtensionalValue_Property);
		parameter->setName("end");
		parameter->setEType(uml::UmlPackage::eInstance()->getProperty_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_link_Operation_getTypes->setEType(uml::UmlPackage::eInstance()->getClassifier_Class());
	m_link_Operation_getTypes->setName("getTypes");
	m_link_Operation_getTypes->setLowerBound(0);
	m_link_Operation_getTypes->setUpperBound(-1);
	m_link_Operation_getTypes->setUnique(true);
	m_link_Operation_getTypes->setOrdered(false);
	
	
	m_link_Operation_isMatchingLink_ExtensionalValue_Property->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_link_Operation_isMatchingLink_ExtensionalValue_Property->setName("isMatchingLink");
	m_link_Operation_isMatchingLink_ExtensionalValue_Property->setLowerBound(0);
	m_link_Operation_isMatchingLink_ExtensionalValue_Property->setUpperBound(1);
	m_link_Operation_isMatchingLink_ExtensionalValue_Property->setUnique(true);
	m_link_Operation_isMatchingLink_ExtensionalValue_Property->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_link_Operation_isMatchingLink_ExtensionalValue_Property);
		parameter->setName("link");
		parameter->setEType(getExtensionalValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_link_Operation_isMatchingLink_ExtensionalValue_Property);
		parameter->setName("end");
		parameter->setEType(uml::UmlPackage::eInstance()->getProperty_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeLinkActionActivationContent()
{
	m_linkActionActivation_Class->setName("LinkActionActivation");
	m_linkActionActivation_Class->setAbstract(true);
	m_linkActionActivation_Class->setInterface(false);
	
	
	
	m_linkActionActivation_Operation_endMatchesEndData_Link_LinkEndData->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_linkActionActivation_Operation_endMatchesEndData_Link_LinkEndData->setName("endMatchesEndData");
	m_linkActionActivation_Operation_endMatchesEndData_Link_LinkEndData->setLowerBound(1);
	m_linkActionActivation_Operation_endMatchesEndData_Link_LinkEndData->setUpperBound(1);
	m_linkActionActivation_Operation_endMatchesEndData_Link_LinkEndData->setUnique(true);
	m_linkActionActivation_Operation_endMatchesEndData_Link_LinkEndData->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_linkActionActivation_Operation_endMatchesEndData_Link_LinkEndData);
		parameter->setName("link");
		parameter->setEType(getLink_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_linkActionActivation_Operation_endMatchesEndData_Link_LinkEndData);
		parameter->setName("endData");
		parameter->setEType(uml::UmlPackage::eInstance()->getLinkEndData_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_linkActionActivation_Operation_getAssociation->setEType(uml::UmlPackage::eInstance()->getAssociation_Class());
	m_linkActionActivation_Operation_getAssociation->setName("getAssociation");
	m_linkActionActivation_Operation_getAssociation->setLowerBound(1);
	m_linkActionActivation_Operation_getAssociation->setUpperBound(1);
	m_linkActionActivation_Operation_getAssociation->setUnique(true);
	m_linkActionActivation_Operation_getAssociation->setOrdered(false);
	
	
	m_linkActionActivation_Operation_linkMatchesEndData_Link_LinkEndData->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_linkActionActivation_Operation_linkMatchesEndData_Link_LinkEndData->setName("linkMatchesEndData");
	m_linkActionActivation_Operation_linkMatchesEndData_Link_LinkEndData->setLowerBound(1);
	m_linkActionActivation_Operation_linkMatchesEndData_Link_LinkEndData->setUpperBound(1);
	m_linkActionActivation_Operation_linkMatchesEndData_Link_LinkEndData->setUnique(true);
	m_linkActionActivation_Operation_linkMatchesEndData_Link_LinkEndData->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_linkActionActivation_Operation_linkMatchesEndData_Link_LinkEndData);
		parameter->setName("link");
		parameter->setEType(getLink_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_linkActionActivation_Operation_linkMatchesEndData_Link_LinkEndData);
		parameter->setName("endDataList");
		parameter->setEType(uml::UmlPackage::eInstance()->getLinkEndData_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeLiteralBooleanEvaluationContent()
{
	m_literalBooleanEvaluation_Class->setName("LiteralBooleanEvaluation");
	m_literalBooleanEvaluation_Class->setAbstract(false);
	m_literalBooleanEvaluation_Class->setInterface(false);
	
	
	
	m_literalBooleanEvaluation_Operation_evaluate->setEType(getValue_Class());
	m_literalBooleanEvaluation_Operation_evaluate->setName("evaluate");
	m_literalBooleanEvaluation_Operation_evaluate->setLowerBound(0);
	m_literalBooleanEvaluation_Operation_evaluate->setUpperBound(1);
	m_literalBooleanEvaluation_Operation_evaluate->setUnique(true);
	m_literalBooleanEvaluation_Operation_evaluate->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeLiteralEvaluationContent()
{
	m_literalEvaluation_Class->setName("LiteralEvaluation");
	m_literalEvaluation_Class->setAbstract(true);
	m_literalEvaluation_Class->setInterface(false);
	
	
	
	m_literalEvaluation_Operation_getType_EString->setEType(uml::UmlPackage::eInstance()->getPrimitiveType_Class());
	m_literalEvaluation_Operation_getType_EString->setName("getType");
	m_literalEvaluation_Operation_getType_EString->setLowerBound(1);
	m_literalEvaluation_Operation_getType_EString->setUpperBound(1);
	m_literalEvaluation_Operation_getType_EString->setUnique(true);
	m_literalEvaluation_Operation_getType_EString->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_literalEvaluation_Operation_getType_EString);
		parameter->setName("builtInTypeName");
		parameter->setEType(ecore::EcorePackage::eInstance()->getEString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeLiteralIntegerEvaluationContent()
{
	m_literalIntegerEvaluation_Class->setName("LiteralIntegerEvaluation");
	m_literalIntegerEvaluation_Class->setAbstract(false);
	m_literalIntegerEvaluation_Class->setInterface(false);
	
	
	
	m_literalIntegerEvaluation_Operation_evaluate->setEType(getValue_Class());
	m_literalIntegerEvaluation_Operation_evaluate->setName("evaluate");
	m_literalIntegerEvaluation_Operation_evaluate->setLowerBound(0);
	m_literalIntegerEvaluation_Operation_evaluate->setUpperBound(1);
	m_literalIntegerEvaluation_Operation_evaluate->setUnique(true);
	m_literalIntegerEvaluation_Operation_evaluate->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeLiteralNullEvaluationContent()
{
	m_literalNullEvaluation_Class->setName("LiteralNullEvaluation");
	m_literalNullEvaluation_Class->setAbstract(false);
	m_literalNullEvaluation_Class->setInterface(false);
	
	
	
	m_literalNullEvaluation_Operation_evaluate->setEType(getValue_Class());
	m_literalNullEvaluation_Operation_evaluate->setName("evaluate");
	m_literalNullEvaluation_Operation_evaluate->setLowerBound(0);
	m_literalNullEvaluation_Operation_evaluate->setUpperBound(1);
	m_literalNullEvaluation_Operation_evaluate->setUnique(true);
	m_literalNullEvaluation_Operation_evaluate->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeLiteralRealEvaluationContent()
{
	m_literalRealEvaluation_Class->setName("LiteralRealEvaluation");
	m_literalRealEvaluation_Class->setAbstract(false);
	m_literalRealEvaluation_Class->setInterface(false);
	
	
	
	m_literalRealEvaluation_Operation_evaluate->setEType(getValue_Class());
	m_literalRealEvaluation_Operation_evaluate->setName("evaluate");
	m_literalRealEvaluation_Operation_evaluate->setLowerBound(0);
	m_literalRealEvaluation_Operation_evaluate->setUpperBound(1);
	m_literalRealEvaluation_Operation_evaluate->setUnique(true);
	m_literalRealEvaluation_Operation_evaluate->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeLiteralStringEvaluationContent()
{
	m_literalStringEvaluation_Class->setName("LiteralStringEvaluation");
	m_literalStringEvaluation_Class->setAbstract(false);
	m_literalStringEvaluation_Class->setInterface(false);
	
	
	
	m_literalStringEvaluation_Operation_evaluate->setEType(getValue_Class());
	m_literalStringEvaluation_Operation_evaluate->setName("evaluate");
	m_literalStringEvaluation_Operation_evaluate->setLowerBound(0);
	m_literalStringEvaluation_Operation_evaluate->setUpperBound(1);
	m_literalStringEvaluation_Operation_evaluate->setUnique(true);
	m_literalStringEvaluation_Operation_evaluate->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeLiteralUnlimitedNaturalEvaluationContent()
{
	m_literalUnlimitedNaturalEvaluation_Class->setName("LiteralUnlimitedNaturalEvaluation");
	m_literalUnlimitedNaturalEvaluation_Class->setAbstract(false);
	m_literalUnlimitedNaturalEvaluation_Class->setInterface(false);
	
	
	
	m_literalUnlimitedNaturalEvaluation_Operation_evaluate->setEType(getValue_Class());
	m_literalUnlimitedNaturalEvaluation_Operation_evaluate->setName("evaluate");
	m_literalUnlimitedNaturalEvaluation_Operation_evaluate->setLowerBound(0);
	m_literalUnlimitedNaturalEvaluation_Operation_evaluate->setUpperBound(1);
	m_literalUnlimitedNaturalEvaluation_Operation_evaluate->setUnique(true);
	m_literalUnlimitedNaturalEvaluation_Operation_evaluate->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeLocusContent()
{
	m_locus_Class->setName("Locus");
	m_locus_Class->setAbstract(false);
	m_locus_Class->setInterface(false);
	
	
	m_locus_Attribute_executor->setName("executor");
	m_locus_Attribute_executor->setEType(getExecutor_Class());
	m_locus_Attribute_executor->setLowerBound(0);
	m_locus_Attribute_executor->setUpperBound(1);
	m_locus_Attribute_executor->setTransient(false);
	m_locus_Attribute_executor->setVolatile(false);
	m_locus_Attribute_executor->setChangeable(true);
	m_locus_Attribute_executor->setUnsettable(false);
	m_locus_Attribute_executor->setUnique(true);
	m_locus_Attribute_executor->setDerived(false);
	m_locus_Attribute_executor->setOrdered(false);
	m_locus_Attribute_executor->setContainment(true);
	m_locus_Attribute_executor->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_locus_Attribute_executor->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getExecutor_Attribute_locus();
		if (otherEnd != nullptr)
	    {
	   		m_locus_Attribute_executor->setEOpposite(otherEnd);
	    }
	}
	m_locus_Attribute_extensionalValues->setName("extensionalValues");
	m_locus_Attribute_extensionalValues->setEType(getExtensionalValue_Class());
	m_locus_Attribute_extensionalValues->setLowerBound(0);
	m_locus_Attribute_extensionalValues->setUpperBound(-1);
	m_locus_Attribute_extensionalValues->setTransient(false);
	m_locus_Attribute_extensionalValues->setVolatile(false);
	m_locus_Attribute_extensionalValues->setChangeable(true);
	m_locus_Attribute_extensionalValues->setUnsettable(false);
	m_locus_Attribute_extensionalValues->setUnique(true);
	m_locus_Attribute_extensionalValues->setDerived(false);
	m_locus_Attribute_extensionalValues->setOrdered(false);
	m_locus_Attribute_extensionalValues->setContainment(true);
	m_locus_Attribute_extensionalValues->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_locus_Attribute_extensionalValues->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_locus_Attribute_extensionalValues->setEOpposite(otherEnd);
	    }
	}
	m_locus_Attribute_factory->setName("factory");
	m_locus_Attribute_factory->setEType(getExecutionFactory_Class());
	m_locus_Attribute_factory->setLowerBound(1);
	m_locus_Attribute_factory->setUpperBound(1);
	m_locus_Attribute_factory->setTransient(false);
	m_locus_Attribute_factory->setVolatile(false);
	m_locus_Attribute_factory->setChangeable(true);
	m_locus_Attribute_factory->setUnsettable(false);
	m_locus_Attribute_factory->setUnique(true);
	m_locus_Attribute_factory->setDerived(false);
	m_locus_Attribute_factory->setOrdered(true);
	m_locus_Attribute_factory->setContainment(true);
	m_locus_Attribute_factory->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_locus_Attribute_factory->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getExecutionFactory_Attribute_locus();
		if (otherEnd != nullptr)
	    {
	   		m_locus_Attribute_factory->setEOpposite(otherEnd);
	    }
	}
	
	m_locus_Operation_add_ExtensionalValue->setEType(nullptr);
	m_locus_Operation_add_ExtensionalValue->setName("add");
	m_locus_Operation_add_ExtensionalValue->setLowerBound(1);
	m_locus_Operation_add_ExtensionalValue->setUpperBound(1);
	m_locus_Operation_add_ExtensionalValue->setUnique(true);
	m_locus_Operation_add_ExtensionalValue->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_locus_Operation_add_ExtensionalValue);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_locus_Operation_assignExecutor_Executor->setEType(nullptr);
	m_locus_Operation_assignExecutor_Executor->setName("assignExecutor");
	m_locus_Operation_assignExecutor_Executor->setLowerBound(1);
	m_locus_Operation_assignExecutor_Executor->setUpperBound(1);
	m_locus_Operation_assignExecutor_Executor->setUnique(true);
	m_locus_Operation_assignExecutor_Executor->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_locus_Operation_assignExecutor_Executor);
		parameter->setName("executor");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_locus_Operation_assignFactory_ExecutionFactory->setEType(nullptr);
	m_locus_Operation_assignFactory_ExecutionFactory->setName("assignFactory");
	m_locus_Operation_assignFactory_ExecutionFactory->setLowerBound(1);
	m_locus_Operation_assignFactory_ExecutionFactory->setUpperBound(1);
	m_locus_Operation_assignFactory_ExecutionFactory->setUnique(true);
	m_locus_Operation_assignFactory_ExecutionFactory->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_locus_Operation_assignFactory_ExecutionFactory);
		parameter->setName("factory");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_locus_Operation_conforms_Classifier_Classifier->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_locus_Operation_conforms_Classifier_Classifier->setName("conforms");
	m_locus_Operation_conforms_Classifier_Classifier->setLowerBound(1);
	m_locus_Operation_conforms_Classifier_Classifier->setUpperBound(1);
	m_locus_Operation_conforms_Classifier_Classifier->setUnique(true);
	m_locus_Operation_conforms_Classifier_Classifier->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_locus_Operation_conforms_Classifier_Classifier);
		parameter->setName("type");
		parameter->setEType(uml::UmlPackage::eInstance()->getClassifier_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_locus_Operation_conforms_Classifier_Classifier);
		parameter->setName("classifier");
		parameter->setEType(uml::UmlPackage::eInstance()->getClassifier_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_locus_Operation_instantiate_Class->setEType(getObject_Class());
	m_locus_Operation_instantiate_Class->setName("instantiate");
	m_locus_Operation_instantiate_Class->setLowerBound(1);
	m_locus_Operation_instantiate_Class->setUpperBound(1);
	m_locus_Operation_instantiate_Class->setUnique(true);
	m_locus_Operation_instantiate_Class->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_locus_Operation_instantiate_Class);
		parameter->setName("type");
		parameter->setEType(uml::UmlPackage::eInstance()->getClass_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_locus_Operation_remove_ExtensionalValue->setEType(nullptr);
	m_locus_Operation_remove_ExtensionalValue->setName("remove");
	m_locus_Operation_remove_ExtensionalValue->setLowerBound(1);
	m_locus_Operation_remove_ExtensionalValue->setUpperBound(1);
	m_locus_Operation_remove_ExtensionalValue->setUnique(true);
	m_locus_Operation_remove_ExtensionalValue->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_locus_Operation_remove_ExtensionalValue);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_locus_Operation_retrieveExtent_Classifier->setEType(getExtensionalValue_Class());
	m_locus_Operation_retrieveExtent_Classifier->setName("retrieveExtent");
	m_locus_Operation_retrieveExtent_Classifier->setLowerBound(0);
	m_locus_Operation_retrieveExtent_Classifier->setUpperBound(-1);
	m_locus_Operation_retrieveExtent_Classifier->setUnique(true);
	m_locus_Operation_retrieveExtent_Classifier->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_locus_Operation_retrieveExtent_Classifier);
		parameter->setName("classifier");
		parameter->setEType(uml::UmlPackage::eInstance()->getClassifier_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeLoopNodeActivationContent()
{
	m_loopNodeActivation_Class->setName("LoopNodeActivation");
	m_loopNodeActivation_Class->setAbstract(false);
	m_loopNodeActivation_Class->setInterface(false);
	
	
	m_loopNodeActivation_Attribute_bodyOutputLists->setName("bodyOutputLists");
	m_loopNodeActivation_Attribute_bodyOutputLists->setEType(getValues_Class());
	m_loopNodeActivation_Attribute_bodyOutputLists->setLowerBound(0);
	m_loopNodeActivation_Attribute_bodyOutputLists->setUpperBound(-1);
	m_loopNodeActivation_Attribute_bodyOutputLists->setTransient(false);
	m_loopNodeActivation_Attribute_bodyOutputLists->setVolatile(false);
	m_loopNodeActivation_Attribute_bodyOutputLists->setChangeable(true);
	m_loopNodeActivation_Attribute_bodyOutputLists->setUnsettable(false);
	m_loopNodeActivation_Attribute_bodyOutputLists->setUnique(true);
	m_loopNodeActivation_Attribute_bodyOutputLists->setDerived(false);
	m_loopNodeActivation_Attribute_bodyOutputLists->setOrdered(false);
	m_loopNodeActivation_Attribute_bodyOutputLists->setContainment(true);
	m_loopNodeActivation_Attribute_bodyOutputLists->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_loopNodeActivation_Attribute_bodyOutputLists->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_loopNodeActivation_Attribute_bodyOutputLists->setEOpposite(otherEnd);
	    }
	}
	
	m_loopNodeActivation_Operation_makeLoopVariableList->setEType(uml::UmlPackage::eInstance()->getActivityNode_Class());
	m_loopNodeActivation_Operation_makeLoopVariableList->setName("makeLoopVariableList");
	m_loopNodeActivation_Operation_makeLoopVariableList->setLowerBound(1);
	m_loopNodeActivation_Operation_makeLoopVariableList->setUpperBound(1);
	m_loopNodeActivation_Operation_makeLoopVariableList->setUnique(true);
	m_loopNodeActivation_Operation_makeLoopVariableList->setOrdered(false);
	
	
	m_loopNodeActivation_Operation_runBody->setEType(nullptr);
	m_loopNodeActivation_Operation_runBody->setName("runBody");
	m_loopNodeActivation_Operation_runBody->setLowerBound(1);
	m_loopNodeActivation_Operation_runBody->setUpperBound(1);
	m_loopNodeActivation_Operation_runBody->setUnique(true);
	m_loopNodeActivation_Operation_runBody->setOrdered(false);
	
	
	m_loopNodeActivation_Operation_runLoopVariables->setEType(nullptr);
	m_loopNodeActivation_Operation_runLoopVariables->setName("runLoopVariables");
	m_loopNodeActivation_Operation_runLoopVariables->setLowerBound(1);
	m_loopNodeActivation_Operation_runLoopVariables->setUpperBound(1);
	m_loopNodeActivation_Operation_runLoopVariables->setUnique(true);
	m_loopNodeActivation_Operation_runLoopVariables->setOrdered(false);
	
	
	m_loopNodeActivation_Operation_runTest->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_loopNodeActivation_Operation_runTest->setName("runTest");
	m_loopNodeActivation_Operation_runTest->setLowerBound(1);
	m_loopNodeActivation_Operation_runTest->setUpperBound(1);
	m_loopNodeActivation_Operation_runTest->setUnique(true);
	m_loopNodeActivation_Operation_runTest->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeMergeNodeActivationContent()
{
	m_mergeNodeActivation_Class->setName("MergeNodeActivation");
	m_mergeNodeActivation_Class->setAbstract(false);
	m_mergeNodeActivation_Class->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeObjectContent()
{
	m_object_Class->setName("Object");
	m_object_Class->setAbstract(false);
	m_object_Class->setInterface(false);
	
	
	m_object_Attribute_objectActivation->setName("objectActivation");
	m_object_Attribute_objectActivation->setEType(getObjectActivation_Class());
	m_object_Attribute_objectActivation->setLowerBound(0);
	m_object_Attribute_objectActivation->setUpperBound(1);
	m_object_Attribute_objectActivation->setTransient(false);
	m_object_Attribute_objectActivation->setVolatile(false);
	m_object_Attribute_objectActivation->setChangeable(true);
	m_object_Attribute_objectActivation->setUnsettable(false);
	m_object_Attribute_objectActivation->setUnique(true);
	m_object_Attribute_objectActivation->setDerived(false);
	m_object_Attribute_objectActivation->setOrdered(false);
	m_object_Attribute_objectActivation->setContainment(true);
	m_object_Attribute_objectActivation->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_object_Attribute_objectActivation->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_object_Attribute_objectActivation->setEOpposite(otherEnd);
	    }
	}
	m_object_Attribute_types->setName("types");
	m_object_Attribute_types->setEType(uml::UmlPackage::eInstance()->getClassifier_Class());
	m_object_Attribute_types->setLowerBound(0);
	m_object_Attribute_types->setUpperBound(-1);
	m_object_Attribute_types->setTransient(false);
	m_object_Attribute_types->setVolatile(false);
	m_object_Attribute_types->setChangeable(true);
	m_object_Attribute_types->setUnsettable(false);
	m_object_Attribute_types->setUnique(true);
	m_object_Attribute_types->setDerived(false);
	m_object_Attribute_types->setOrdered(false);
	m_object_Attribute_types->setContainment(false);
	m_object_Attribute_types->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_object_Attribute_types->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_object_Attribute_types->setEOpposite(otherEnd);
	    }
	}
	
	m_object_Operation__register_EventAccepter->setEType(nullptr);
	m_object_Operation__register_EventAccepter->setName("_register");
	m_object_Operation__register_EventAccepter->setLowerBound(1);
	m_object_Operation__register_EventAccepter->setUpperBound(1);
	m_object_Operation__register_EventAccepter->setUnique(true);
	m_object_Operation__register_EventAccepter->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_object_Operation__register_EventAccepter);
		parameter->setName("accepter");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_object_Operation_destroy->setEType(nullptr);
	m_object_Operation_destroy->setName("destroy");
	m_object_Operation_destroy->setLowerBound(1);
	m_object_Operation_destroy->setUpperBound(1);
	m_object_Operation_destroy->setUnique(true);
	m_object_Operation_destroy->setOrdered(false);
	
	
	m_object_Operation_dispatch_Operation->setEType(getExecution_Class());
	m_object_Operation_dispatch_Operation->setName("dispatch");
	m_object_Operation_dispatch_Operation->setLowerBound(1);
	m_object_Operation_dispatch_Operation->setUpperBound(1);
	m_object_Operation_dispatch_Operation->setUnique(true);
	m_object_Operation_dispatch_Operation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_object_Operation_dispatch_Operation);
		parameter->setName("operation");
		parameter->setEType(uml::UmlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_object_Operation_new_->setEType(getValue_Class());
	m_object_Operation_new_->setName("new_");
	m_object_Operation_new_->setLowerBound(1);
	m_object_Operation_new_->setUpperBound(1);
	m_object_Operation_new_->setUnique(true);
	m_object_Operation_new_->setOrdered(false);
	
	
	m_object_Operation_send_SignalInstance->setEType(nullptr);
	m_object_Operation_send_SignalInstance->setName("send");
	m_object_Operation_send_SignalInstance->setLowerBound(1);
	m_object_Operation_send_SignalInstance->setUpperBound(1);
	m_object_Operation_send_SignalInstance->setUnique(true);
	m_object_Operation_send_SignalInstance->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_object_Operation_send_SignalInstance);
		parameter->setName("signalInstance");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_object_Operation_startBehavior_Class_ParameterValue->setEType(nullptr);
	m_object_Operation_startBehavior_Class_ParameterValue->setName("startBehavior");
	m_object_Operation_startBehavior_Class_ParameterValue->setLowerBound(1);
	m_object_Operation_startBehavior_Class_ParameterValue->setUpperBound(1);
	m_object_Operation_startBehavior_Class_ParameterValue->setUnique(true);
	m_object_Operation_startBehavior_Class_ParameterValue->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_object_Operation_startBehavior_Class_ParameterValue);
		parameter->setName("classifier");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_object_Operation_startBehavior_Class_ParameterValue);
		parameter->setName("inputs");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_object_Operation_unregister_EventAccepter->setEType(nullptr);
	m_object_Operation_unregister_EventAccepter->setName("unregister");
	m_object_Operation_unregister_EventAccepter->setLowerBound(1);
	m_object_Operation_unregister_EventAccepter->setUpperBound(1);
	m_object_Operation_unregister_EventAccepter->setUnique(true);
	m_object_Operation_unregister_EventAccepter->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_object_Operation_unregister_EventAccepter);
		parameter->setName("accepter");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeObjectActivationContent()
{
	m_objectActivation_Class->setName("ObjectActivation");
	m_objectActivation_Class->setAbstract(false);
	m_objectActivation_Class->setInterface(false);
	
	
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_objectActivation_Attribute_classifierBehaviorExecutions->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_objectActivation_Attribute_classifierBehaviorExecutions->setEOpposite(otherEnd);
	    }
	}
	m_objectActivation_Attribute_eventPool->setName("eventPool");
	m_objectActivation_Attribute_eventPool->setEType(getSignalInstance_Class());
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_objectActivation_Attribute_eventPool->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_objectActivation_Attribute_eventPool->setEOpposite(otherEnd);
	    }
	}
	m_objectActivation_Attribute_object->setName("object");
	m_objectActivation_Attribute_object->setEType(getObject_Class());
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_objectActivation_Attribute_object->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_objectActivation_Attribute_object->setEOpposite(otherEnd);
	    }
	}
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_objectActivation_Attribute_waitingEventAccepters->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_objectActivation_Attribute_waitingEventAccepters->setEOpposite(otherEnd);
	    }
	}
	
	m_objectActivation_Operation__register_EventAccepter->setEType(nullptr);
	m_objectActivation_Operation__register_EventAccepter->setName("_register");
	m_objectActivation_Operation__register_EventAccepter->setLowerBound(1);
	m_objectActivation_Operation__register_EventAccepter->setUpperBound(1);
	m_objectActivation_Operation__register_EventAccepter->setUnique(true);
	m_objectActivation_Operation__register_EventAccepter->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_objectActivation_Operation__register_EventAccepter);
		parameter->setName("accepter");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_objectActivation_Operation__send_EJavaObject->setEType(nullptr);
	m_objectActivation_Operation__send_EJavaObject->setName("_send");
	m_objectActivation_Operation__send_EJavaObject->setLowerBound(1);
	m_objectActivation_Operation__send_EJavaObject->setUpperBound(1);
	m_objectActivation_Operation__send_EJavaObject->setUnique(true);
	m_objectActivation_Operation__send_EJavaObject->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_objectActivation_Operation__send_EJavaObject);
		parameter->setName("signal");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_objectActivation_Operation__startObjectBehavior->setEType(nullptr);
	m_objectActivation_Operation__startObjectBehavior->setName("_startObjectBehavior");
	m_objectActivation_Operation__startObjectBehavior->setLowerBound(1);
	m_objectActivation_Operation__startObjectBehavior->setUpperBound(1);
	m_objectActivation_Operation__startObjectBehavior->setUnique(true);
	m_objectActivation_Operation__startObjectBehavior->setOrdered(false);
	
	
	m_objectActivation_Operation_dispatchNextEvent->setEType(nullptr);
	m_objectActivation_Operation_dispatchNextEvent->setName("dispatchNextEvent");
	m_objectActivation_Operation_dispatchNextEvent->setLowerBound(1);
	m_objectActivation_Operation_dispatchNextEvent->setUpperBound(1);
	m_objectActivation_Operation_dispatchNextEvent->setUnique(true);
	m_objectActivation_Operation_dispatchNextEvent->setOrdered(false);
	
	
	m_objectActivation_Operation_retrieveNextEvent->setEType(getSignalInstance_Class());
	m_objectActivation_Operation_retrieveNextEvent->setName("retrieveNextEvent");
	m_objectActivation_Operation_retrieveNextEvent->setLowerBound(1);
	m_objectActivation_Operation_retrieveNextEvent->setUpperBound(1);
	m_objectActivation_Operation_retrieveNextEvent->setUnique(true);
	m_objectActivation_Operation_retrieveNextEvent->setOrdered(false);
	
	
	m_objectActivation_Operation_send_SignalInstance->setEType(nullptr);
	m_objectActivation_Operation_send_SignalInstance->setName("send");
	m_objectActivation_Operation_send_SignalInstance->setLowerBound(1);
	m_objectActivation_Operation_send_SignalInstance->setUpperBound(1);
	m_objectActivation_Operation_send_SignalInstance->setUnique(true);
	m_objectActivation_Operation_send_SignalInstance->setOrdered(true);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_objectActivation_Operation_send_SignalInstance);
		parameter->setName("signalInstance");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_objectActivation_Operation_startBehavior_Class_ParameterValue->setEType(nullptr);
	m_objectActivation_Operation_startBehavior_Class_ParameterValue->setName("startBehavior");
	m_objectActivation_Operation_startBehavior_Class_ParameterValue->setLowerBound(1);
	m_objectActivation_Operation_startBehavior_Class_ParameterValue->setUpperBound(1);
	m_objectActivation_Operation_startBehavior_Class_ParameterValue->setUnique(true);
	m_objectActivation_Operation_startBehavior_Class_ParameterValue->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_objectActivation_Operation_startBehavior_Class_ParameterValue);
		parameter->setName("classifier");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_objectActivation_Operation_startBehavior_Class_ParameterValue);
		parameter->setName("inputs");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_objectActivation_Operation_stop->setEType(nullptr);
	m_objectActivation_Operation_stop->setName("stop");
	m_objectActivation_Operation_stop->setLowerBound(1);
	m_objectActivation_Operation_stop->setUpperBound(1);
	m_objectActivation_Operation_stop->setUnique(true);
	m_objectActivation_Operation_stop->setOrdered(false);
	
	
	m_objectActivation_Operation_unregister_EventAccepter->setEType(nullptr);
	m_objectActivation_Operation_unregister_EventAccepter->setName("unregister");
	m_objectActivation_Operation_unregister_EventAccepter->setLowerBound(1);
	m_objectActivation_Operation_unregister_EventAccepter->setUpperBound(1);
	m_objectActivation_Operation_unregister_EventAccepter->setUnique(true);
	m_objectActivation_Operation_unregister_EventAccepter->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_objectActivation_Operation_unregister_EventAccepter);
		parameter->setName("accepter");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeObjectNodeActivationContent()
{
	m_objectNodeActivation_Class->setName("ObjectNodeActivation");
	m_objectNodeActivation_Class->setAbstract(true);
	m_objectNodeActivation_Class->setInterface(false);
	
	m_objectNodeActivation_Attribute_offeredTokenCount = getObjectNodeActivation_Attribute_offeredTokenCount();
	m_objectNodeActivation_Attribute_offeredTokenCount->setName("offeredTokenCount");
	m_objectNodeActivation_Attribute_offeredTokenCount->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
	m_objectNodeActivation_Attribute_offeredTokenCount->setLowerBound(1);
	m_objectNodeActivation_Attribute_offeredTokenCount->setUpperBound(1);
	m_objectNodeActivation_Attribute_offeredTokenCount->setTransient(false);
	m_objectNodeActivation_Attribute_offeredTokenCount->setVolatile(false);
	m_objectNodeActivation_Attribute_offeredTokenCount->setChangeable(true);
	m_objectNodeActivation_Attribute_offeredTokenCount->setUnsettable(false);
	m_objectNodeActivation_Attribute_offeredTokenCount->setUnique(true);
	m_objectNodeActivation_Attribute_offeredTokenCount->setDerived(false);
	m_objectNodeActivation_Attribute_offeredTokenCount->setOrdered(false);
	m_objectNodeActivation_Attribute_offeredTokenCount->setID(false);
	{
		std::string defaultValue = "0";
		if (!defaultValue.empty())
		{
		   m_objectNodeActivation_Attribute_offeredTokenCount->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	m_objectNodeActivation_Operation_addToken_Token->setEType(nullptr);
	m_objectNodeActivation_Operation_addToken_Token->setName("addToken");
	m_objectNodeActivation_Operation_addToken_Token->setLowerBound(1);
	m_objectNodeActivation_Operation_addToken_Token->setUpperBound(1);
	m_objectNodeActivation_Operation_addToken_Token->setUnique(true);
	m_objectNodeActivation_Operation_addToken_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_objectNodeActivation_Operation_addToken_Token);
		parameter->setName("token");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_objectNodeActivation_Operation_clearTokens->setEType(nullptr);
	m_objectNodeActivation_Operation_clearTokens->setName("clearTokens");
	m_objectNodeActivation_Operation_clearTokens->setLowerBound(1);
	m_objectNodeActivation_Operation_clearTokens->setUpperBound(1);
	m_objectNodeActivation_Operation_clearTokens->setUnique(true);
	m_objectNodeActivation_Operation_clearTokens->setOrdered(false);
	
	
	m_objectNodeActivation_Operation_countOfferedValues->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
	m_objectNodeActivation_Operation_countOfferedValues->setName("countOfferedValues");
	m_objectNodeActivation_Operation_countOfferedValues->setLowerBound(1);
	m_objectNodeActivation_Operation_countOfferedValues->setUpperBound(1);
	m_objectNodeActivation_Operation_countOfferedValues->setUnique(true);
	m_objectNodeActivation_Operation_countOfferedValues->setOrdered(false);
	
	
	m_objectNodeActivation_Operation_countUnofferedTokens->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
	m_objectNodeActivation_Operation_countUnofferedTokens->setName("countUnofferedTokens");
	m_objectNodeActivation_Operation_countUnofferedTokens->setLowerBound(1);
	m_objectNodeActivation_Operation_countUnofferedTokens->setUpperBound(1);
	m_objectNodeActivation_Operation_countUnofferedTokens->setUnique(true);
	m_objectNodeActivation_Operation_countUnofferedTokens->setOrdered(false);
	
	
	m_objectNodeActivation_Operation_getUnofferedTokens->setEType(getToken_Class());
	m_objectNodeActivation_Operation_getUnofferedTokens->setName("getUnofferedTokens");
	m_objectNodeActivation_Operation_getUnofferedTokens->setLowerBound(0);
	m_objectNodeActivation_Operation_getUnofferedTokens->setUpperBound(-1);
	m_objectNodeActivation_Operation_getUnofferedTokens->setUnique(true);
	m_objectNodeActivation_Operation_getUnofferedTokens->setOrdered(false);
	
	
	m_objectNodeActivation_Operation_removeToken_Token->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
	m_objectNodeActivation_Operation_removeToken_Token->setName("removeToken");
	m_objectNodeActivation_Operation_removeToken_Token->setLowerBound(1);
	m_objectNodeActivation_Operation_removeToken_Token->setUpperBound(1);
	m_objectNodeActivation_Operation_removeToken_Token->setUnique(true);
	m_objectNodeActivation_Operation_removeToken_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_objectNodeActivation_Operation_removeToken_Token);
		parameter->setName("token");
		parameter->setEType(getToken_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_objectNodeActivation_Operation_run->setEType(nullptr);
	m_objectNodeActivation_Operation_run->setName("run");
	m_objectNodeActivation_Operation_run->setLowerBound(1);
	m_objectNodeActivation_Operation_run->setUpperBound(1);
	m_objectNodeActivation_Operation_run->setUnique(true);
	m_objectNodeActivation_Operation_run->setOrdered(false);
	
	
	m_objectNodeActivation_Operation_sendOffers_Token->setEType(nullptr);
	m_objectNodeActivation_Operation_sendOffers_Token->setName("sendOffers");
	m_objectNodeActivation_Operation_sendOffers_Token->setLowerBound(0);
	m_objectNodeActivation_Operation_sendOffers_Token->setUpperBound(1);
	m_objectNodeActivation_Operation_sendOffers_Token->setUnique(true);
	m_objectNodeActivation_Operation_sendOffers_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_objectNodeActivation_Operation_sendOffers_Token);
		parameter->setName("tokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_objectNodeActivation_Operation_sendUnofferedTokens->setEType(nullptr);
	m_objectNodeActivation_Operation_sendUnofferedTokens->setName("sendUnofferedTokens");
	m_objectNodeActivation_Operation_sendUnofferedTokens->setLowerBound(1);
	m_objectNodeActivation_Operation_sendUnofferedTokens->setUpperBound(1);
	m_objectNodeActivation_Operation_sendUnofferedTokens->setUnique(true);
	m_objectNodeActivation_Operation_sendUnofferedTokens->setOrdered(false);
	
	
	m_objectNodeActivation_Operation_takeUnofferedTokens->setEType(getToken_Class());
	m_objectNodeActivation_Operation_takeUnofferedTokens->setName("takeUnofferedTokens");
	m_objectNodeActivation_Operation_takeUnofferedTokens->setLowerBound(0);
	m_objectNodeActivation_Operation_takeUnofferedTokens->setUpperBound(-1);
	m_objectNodeActivation_Operation_takeUnofferedTokens->setUnique(true);
	m_objectNodeActivation_Operation_takeUnofferedTokens->setOrdered(false);
	
	
	m_objectNodeActivation_Operation_terminate->setEType(nullptr);
	m_objectNodeActivation_Operation_terminate->setName("terminate");
	m_objectNodeActivation_Operation_terminate->setLowerBound(1);
	m_objectNodeActivation_Operation_terminate->setUpperBound(1);
	m_objectNodeActivation_Operation_terminate->setUnique(true);
	m_objectNodeActivation_Operation_terminate->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeObjectTokenContent()
{
	m_objectToken_Class->setName("ObjectToken");
	m_objectToken_Class->setAbstract(false);
	m_objectToken_Class->setInterface(false);
	
	
	m_objectToken_Attribute_value->setName("value");
	m_objectToken_Attribute_value->setEType(getValue_Class());
	m_objectToken_Attribute_value->setLowerBound(0);
	m_objectToken_Attribute_value->setUpperBound(1);
	m_objectToken_Attribute_value->setTransient(false);
	m_objectToken_Attribute_value->setVolatile(false);
	m_objectToken_Attribute_value->setChangeable(true);
	m_objectToken_Attribute_value->setUnsettable(false);
	m_objectToken_Attribute_value->setUnique(true);
	m_objectToken_Attribute_value->setDerived(false);
	m_objectToken_Attribute_value->setOrdered(false);
	m_objectToken_Attribute_value->setContainment(true);
	m_objectToken_Attribute_value->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_objectToken_Attribute_value->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_objectToken_Attribute_value->setEOpposite(otherEnd);
	    }
	}
	
	m_objectToken_Operation_equals_Token->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_objectToken_Operation_equals_Token->setName("equals");
	m_objectToken_Operation_equals_Token->setLowerBound(1);
	m_objectToken_Operation_equals_Token->setUpperBound(1);
	m_objectToken_Operation_equals_Token->setUnique(true);
	m_objectToken_Operation_equals_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_objectToken_Operation_equals_Token);
		parameter->setName("other");
		parameter->setEType(getToken_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_objectToken_Operation_isControl->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_objectToken_Operation_isControl->setName("isControl");
	m_objectToken_Operation_isControl->setLowerBound(1);
	m_objectToken_Operation_isControl->setUpperBound(1);
	m_objectToken_Operation_isControl->setUnique(true);
	m_objectToken_Operation_isControl->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeOfferContent()
{
	m_offer_Class->setName("Offer");
	m_offer_Class->setAbstract(false);
	m_offer_Class->setInterface(false);
	
	
	m_offer_Attribute_offeredTokens->setName("offeredTokens");
	m_offer_Attribute_offeredTokens->setEType(getToken_Class());
	m_offer_Attribute_offeredTokens->setLowerBound(0);
	m_offer_Attribute_offeredTokens->setUpperBound(-1);
	m_offer_Attribute_offeredTokens->setTransient(false);
	m_offer_Attribute_offeredTokens->setVolatile(false);
	m_offer_Attribute_offeredTokens->setChangeable(true);
	m_offer_Attribute_offeredTokens->setUnsettable(false);
	m_offer_Attribute_offeredTokens->setUnique(true);
	m_offer_Attribute_offeredTokens->setDerived(false);
	m_offer_Attribute_offeredTokens->setOrdered(false);
	m_offer_Attribute_offeredTokens->setContainment(false);
	m_offer_Attribute_offeredTokens->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_offer_Attribute_offeredTokens->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_offer_Attribute_offeredTokens->setEOpposite(otherEnd);
	    }
	}
	
	m_offer_Operation_countOfferedVales->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
	m_offer_Operation_countOfferedVales->setName("countOfferedVales");
	m_offer_Operation_countOfferedVales->setLowerBound(1);
	m_offer_Operation_countOfferedVales->setUpperBound(1);
	m_offer_Operation_countOfferedVales->setUnique(true);
	m_offer_Operation_countOfferedVales->setOrdered(false);
	
	
	m_offer_Operation_hasTokens->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_offer_Operation_hasTokens->setName("hasTokens");
	m_offer_Operation_hasTokens->setLowerBound(1);
	m_offer_Operation_hasTokens->setUpperBound(1);
	m_offer_Operation_hasTokens->setUnique(true);
	m_offer_Operation_hasTokens->setOrdered(false);
	
	
	m_offer_Operation_removeOfferedValues_EInt->setEType(nullptr);
	m_offer_Operation_removeOfferedValues_EInt->setName("removeOfferedValues");
	m_offer_Operation_removeOfferedValues_EInt->setLowerBound(1);
	m_offer_Operation_removeOfferedValues_EInt->setUpperBound(1);
	m_offer_Operation_removeOfferedValues_EInt->setUnique(true);
	m_offer_Operation_removeOfferedValues_EInt->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_offer_Operation_removeOfferedValues_EInt);
		parameter->setName("count");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_offer_Operation_removeWithdrawnTokens->setEType(nullptr);
	m_offer_Operation_removeWithdrawnTokens->setName("removeWithdrawnTokens");
	m_offer_Operation_removeWithdrawnTokens->setLowerBound(1);
	m_offer_Operation_removeWithdrawnTokens->setUpperBound(1);
	m_offer_Operation_removeWithdrawnTokens->setUnique(true);
	m_offer_Operation_removeWithdrawnTokens->setOrdered(false);
	
	
	m_offer_Operation_retrieveOfferedTokens->setEType(getToken_Class());
	m_offer_Operation_retrieveOfferedTokens->setName("retrieveOfferedTokens");
	m_offer_Operation_retrieveOfferedTokens->setLowerBound(0);
	m_offer_Operation_retrieveOfferedTokens->setUpperBound(-1);
	m_offer_Operation_retrieveOfferedTokens->setUnique(true);
	m_offer_Operation_retrieveOfferedTokens->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeOpaqueBehaviorExecutionContent()
{
	m_opaqueBehaviorExecution_Class->setName("OpaqueBehaviorExecution");
	m_opaqueBehaviorExecution_Class->setAbstract(true);
	m_opaqueBehaviorExecution_Class->setInterface(false);
	
	
	
	m_opaqueBehaviorExecution_Operation_doBody_ParameterValue_ParameterValue->setEType(nullptr);
	m_opaqueBehaviorExecution_Operation_doBody_ParameterValue_ParameterValue->setName("doBody");
	m_opaqueBehaviorExecution_Operation_doBody_ParameterValue_ParameterValue->setLowerBound(1);
	m_opaqueBehaviorExecution_Operation_doBody_ParameterValue_ParameterValue->setUpperBound(1);
	m_opaqueBehaviorExecution_Operation_doBody_ParameterValue_ParameterValue->setUnique(true);
	m_opaqueBehaviorExecution_Operation_doBody_ParameterValue_ParameterValue->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_opaqueBehaviorExecution_Operation_doBody_ParameterValue_ParameterValue);
		parameter->setName("inputParameters");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_opaqueBehaviorExecution_Operation_doBody_ParameterValue_ParameterValue);
		parameter->setName("outputParameters");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_opaqueBehaviorExecution_Operation_execute->setEType(nullptr);
	m_opaqueBehaviorExecution_Operation_execute->setName("execute");
	m_opaqueBehaviorExecution_Operation_execute->setLowerBound(1);
	m_opaqueBehaviorExecution_Operation_execute->setUpperBound(1);
	m_opaqueBehaviorExecution_Operation_execute->setUnique(true);
	m_opaqueBehaviorExecution_Operation_execute->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeOutputPinActivationContent()
{
	m_outputPinActivation_Class->setName("OutputPinActivation");
	m_outputPinActivation_Class->setAbstract(false);
	m_outputPinActivation_Class->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeParameterValueContent()
{
	m_parameterValue_Class->setName("ParameterValue");
	m_parameterValue_Class->setAbstract(false);
	m_parameterValue_Class->setInterface(false);
	
	
	m_parameterValue_Attribute_parameter->setName("parameter");
	m_parameterValue_Attribute_parameter->setEType(uml::UmlPackage::eInstance()->getParameter_Class());
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
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_parameterValue_Attribute_parameter->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_parameterValue_Attribute_parameter->setEOpposite(otherEnd);
	    }
	}
	m_parameterValue_Attribute_values->setName("values");
	m_parameterValue_Attribute_values->setEType(getValue_Class());
	m_parameterValue_Attribute_values->setLowerBound(0);
	m_parameterValue_Attribute_values->setUpperBound(-1);
	m_parameterValue_Attribute_values->setTransient(false);
	m_parameterValue_Attribute_values->setVolatile(false);
	m_parameterValue_Attribute_values->setChangeable(true);
	m_parameterValue_Attribute_values->setUnsettable(false);
	m_parameterValue_Attribute_values->setUnique(true);
	m_parameterValue_Attribute_values->setDerived(false);
	m_parameterValue_Attribute_values->setOrdered(false);
	m_parameterValue_Attribute_values->setContainment(true);
	m_parameterValue_Attribute_values->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_parameterValue_Attribute_values->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_parameterValue_Attribute_values->setEOpposite(otherEnd);
	    }
	}
	
	
}

void FUMLPackageImpl::initializePinActivationContent()
{
	m_pinActivation_Class->setName("PinActivation");
	m_pinActivation_Class->setAbstract(true);
	m_pinActivation_Class->setInterface(false);
	
	
	m_pinActivation_Attribute_actionActivation->setName("actionActivation");
	m_pinActivation_Attribute_actionActivation->setEType(getActionActivation_Class());
	m_pinActivation_Attribute_actionActivation->setLowerBound(0);
	m_pinActivation_Attribute_actionActivation->setUpperBound(1);
	m_pinActivation_Attribute_actionActivation->setTransient(false);
	m_pinActivation_Attribute_actionActivation->setVolatile(false);
	m_pinActivation_Attribute_actionActivation->setChangeable(true);
	m_pinActivation_Attribute_actionActivation->setUnsettable(false);
	m_pinActivation_Attribute_actionActivation->setUnique(true);
	m_pinActivation_Attribute_actionActivation->setDerived(false);
	m_pinActivation_Attribute_actionActivation->setOrdered(false);
	m_pinActivation_Attribute_actionActivation->setContainment(false);
	m_pinActivation_Attribute_actionActivation->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_pinActivation_Attribute_actionActivation->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getActionActivation_Attribute_pinActivation();
		if (otherEnd != nullptr)
	    {
	   		m_pinActivation_Attribute_actionActivation->setEOpposite(otherEnd);
	    }
	}
	
	m_pinActivation_Operation_fire_Token->setEType(nullptr);
	m_pinActivation_Operation_fire_Token->setName("fire");
	m_pinActivation_Operation_fire_Token->setLowerBound(1);
	m_pinActivation_Operation_fire_Token->setUpperBound(1);
	m_pinActivation_Operation_fire_Token->setUnique(true);
	m_pinActivation_Operation_fire_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_pinActivation_Operation_fire_Token);
		parameter->setName("incomingTokens");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_pinActivation_Operation_takeOfferedTokens->setEType(getToken_Class());
	m_pinActivation_Operation_takeOfferedTokens->setName("takeOfferedTokens");
	m_pinActivation_Operation_takeOfferedTokens->setLowerBound(0);
	m_pinActivation_Operation_takeOfferedTokens->setUpperBound(-1);
	m_pinActivation_Operation_takeOfferedTokens->setUnique(true);
	m_pinActivation_Operation_takeOfferedTokens->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializePrimitiveValueContent()
{
	m_primitiveValue_Class->setName("PrimitiveValue");
	m_primitiveValue_Class->setAbstract(true);
	m_primitiveValue_Class->setInterface(false);
	
	
	m_primitiveValue_Attribute_type->setName("type");
	m_primitiveValue_Attribute_type->setEType(uml::UmlPackage::eInstance()->getPrimitiveType_Class());
	m_primitiveValue_Attribute_type->setLowerBound(1);
	m_primitiveValue_Attribute_type->setUpperBound(1);
	m_primitiveValue_Attribute_type->setTransient(false);
	m_primitiveValue_Attribute_type->setVolatile(false);
	m_primitiveValue_Attribute_type->setChangeable(true);
	m_primitiveValue_Attribute_type->setUnsettable(false);
	m_primitiveValue_Attribute_type->setUnique(true);
	m_primitiveValue_Attribute_type->setDerived(false);
	m_primitiveValue_Attribute_type->setOrdered(false);
	m_primitiveValue_Attribute_type->setContainment(false);
	m_primitiveValue_Attribute_type->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_primitiveValue_Attribute_type->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_primitiveValue_Attribute_type->setEOpposite(otherEnd);
	    }
	}
	
	m_primitiveValue_Operation_getTypes->setEType(uml::UmlPackage::eInstance()->getClassifier_Class());
	m_primitiveValue_Operation_getTypes->setName("getTypes");
	m_primitiveValue_Operation_getTypes->setLowerBound(0);
	m_primitiveValue_Operation_getTypes->setUpperBound(-1);
	m_primitiveValue_Operation_getTypes->setUnique(true);
	m_primitiveValue_Operation_getTypes->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeReadExtentActionActivationContent()
{
	m_readExtentActionActivation_Class->setName("ReadExtentActionActivation");
	m_readExtentActionActivation_Class->setAbstract(false);
	m_readExtentActionActivation_Class->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeReadIsClassifiedObjectActionActivationContent()
{
	m_readIsClassifiedObjectActionActivation_Class->setName("ReadIsClassifiedObjectActionActivation");
	m_readIsClassifiedObjectActionActivation_Class->setAbstract(false);
	m_readIsClassifiedObjectActionActivation_Class->setInterface(false);
	
	
	
	m_readIsClassifiedObjectActionActivation_Operation_checkAllParents_Classifier_Classifier->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_readIsClassifiedObjectActionActivation_Operation_checkAllParents_Classifier_Classifier->setName("checkAllParents");
	m_readIsClassifiedObjectActionActivation_Operation_checkAllParents_Classifier_Classifier->setLowerBound(0);
	m_readIsClassifiedObjectActionActivation_Operation_checkAllParents_Classifier_Classifier->setUpperBound(1);
	m_readIsClassifiedObjectActionActivation_Operation_checkAllParents_Classifier_Classifier->setUnique(true);
	m_readIsClassifiedObjectActionActivation_Operation_checkAllParents_Classifier_Classifier->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_readIsClassifiedObjectActionActivation_Operation_checkAllParents_Classifier_Classifier);
		parameter->setName("type");
		parameter->setEType(uml::UmlPackage::eInstance()->getClassifier_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_readIsClassifiedObjectActionActivation_Operation_checkAllParents_Classifier_Classifier);
		parameter->setName("classifier");
		parameter->setEType(uml::UmlPackage::eInstance()->getClassifier_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeReadLinkActionActivationContent()
{
	m_readLinkActionActivation_Class->setName("ReadLinkActionActivation");
	m_readLinkActionActivation_Class->setAbstract(false);
	m_readLinkActionActivation_Class->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeReadSelfActionActivationContent()
{
	m_readSelfActionActivation_Class->setName("ReadSelfActionActivation");
	m_readSelfActionActivation_Class->setAbstract(false);
	m_readSelfActionActivation_Class->setInterface(false);
	
	
	
	m_readSelfActionActivation_Operation_doAction->setEType(nullptr);
	m_readSelfActionActivation_Operation_doAction->setName("doAction");
	m_readSelfActionActivation_Operation_doAction->setLowerBound(0);
	m_readSelfActionActivation_Operation_doAction->setUpperBound(1);
	m_readSelfActionActivation_Operation_doAction->setUnique(true);
	m_readSelfActionActivation_Operation_doAction->setOrdered(true);
	
	
	
}

void FUMLPackageImpl::initializeReadStructuralFeatureActionActivationContent()
{
	m_readStructuralFeatureActionActivation_Class->setName("ReadStructuralFeatureActionActivation");
	m_readStructuralFeatureActionActivation_Class->setAbstract(false);
	m_readStructuralFeatureActionActivation_Class->setInterface(false);
	
	
	
	m_readStructuralFeatureActionActivation_Operation_doAction->setEType(nullptr);
	m_readStructuralFeatureActionActivation_Operation_doAction->setName("doAction");
	m_readStructuralFeatureActionActivation_Operation_doAction->setLowerBound(0);
	m_readStructuralFeatureActionActivation_Operation_doAction->setUpperBound(1);
	m_readStructuralFeatureActionActivation_Operation_doAction->setUnique(true);
	m_readStructuralFeatureActionActivation_Operation_doAction->setOrdered(true);
	
	
	
}

void FUMLPackageImpl::initializeRealValueContent()
{
	m_realValue_Class->setName("RealValue");
	m_realValue_Class->setAbstract(false);
	m_realValue_Class->setInterface(false);
	
	m_realValue_Attribute_value = getRealValue_Attribute_value();
	m_realValue_Attribute_value->setName("value");
	m_realValue_Attribute_value->setEType(ecore::EcorePackage::eInstance()->getEFloat_Class());
	m_realValue_Attribute_value->setLowerBound(1);
	m_realValue_Attribute_value->setUpperBound(1);
	m_realValue_Attribute_value->setTransient(false);
	m_realValue_Attribute_value->setVolatile(false);
	m_realValue_Attribute_value->setChangeable(true);
	m_realValue_Attribute_value->setUnsettable(false);
	m_realValue_Attribute_value->setUnique(true);
	m_realValue_Attribute_value->setDerived(false);
	m_realValue_Attribute_value->setOrdered(false);
	m_realValue_Attribute_value->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_realValue_Attribute_value->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	m_realValue_Operation_equals_Value->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_realValue_Operation_equals_Value->setName("equals");
	m_realValue_Operation_equals_Value->setLowerBound(1);
	m_realValue_Operation_equals_Value->setUpperBound(1);
	m_realValue_Operation_equals_Value->setUnique(true);
	m_realValue_Operation_equals_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_realValue_Operation_equals_Value);
		parameter->setName("otherValue");
		parameter->setEType(getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_realValue_Operation_specify->setEType(uml::UmlPackage::eInstance()->getValueSpecification_Class());
	m_realValue_Operation_specify->setName("specify");
	m_realValue_Operation_specify->setLowerBound(1);
	m_realValue_Operation_specify->setUpperBound(1);
	m_realValue_Operation_specify->setUnique(true);
	m_realValue_Operation_specify->setOrdered(false);
	
	
	m_realValue_Operation_toString->setEType(ecore::EcorePackage::eInstance()->getEString_Class());
	m_realValue_Operation_toString->setName("toString");
	m_realValue_Operation_toString->setLowerBound(1);
	m_realValue_Operation_toString->setUpperBound(1);
	m_realValue_Operation_toString->setUnique(true);
	m_realValue_Operation_toString->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeReclassifyObjectActionActivationContent()
{
	m_reclassifyObjectActionActivation_Class->setName("ReclassifyObjectActionActivation");
	m_reclassifyObjectActionActivation_Class->setAbstract(false);
	m_reclassifyObjectActionActivation_Class->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeRedefinitionBasedDispatchStrategyContent()
{
	m_redefinitionBasedDispatchStrategy_Class->setName("RedefinitionBasedDispatchStrategy");
	m_redefinitionBasedDispatchStrategy_Class->setAbstract(false);
	m_redefinitionBasedDispatchStrategy_Class->setInterface(false);
	
	
	
	m_redefinitionBasedDispatchStrategy_Operation_operationsMatch_Operation_Operation->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_redefinitionBasedDispatchStrategy_Operation_operationsMatch_Operation_Operation->setName("operationsMatch");
	m_redefinitionBasedDispatchStrategy_Operation_operationsMatch_Operation_Operation->setLowerBound(1);
	m_redefinitionBasedDispatchStrategy_Operation_operationsMatch_Operation_Operation->setUpperBound(1);
	m_redefinitionBasedDispatchStrategy_Operation_operationsMatch_Operation_Operation->setUnique(true);
	m_redefinitionBasedDispatchStrategy_Operation_operationsMatch_Operation_Operation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_redefinitionBasedDispatchStrategy_Operation_operationsMatch_Operation_Operation);
		parameter->setName("ownedOperation");
		parameter->setEType(uml::UmlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_redefinitionBasedDispatchStrategy_Operation_operationsMatch_Operation_Operation);
		parameter->setName("baseOperation");
		parameter->setEType(uml::UmlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_redefinitionBasedDispatchStrategy_Operation_retrieveMethod_Object_Operation->setEType(uml::UmlPackage::eInstance()->getBehavior_Class());
	m_redefinitionBasedDispatchStrategy_Operation_retrieveMethod_Object_Operation->setName("retrieveMethod");
	m_redefinitionBasedDispatchStrategy_Operation_retrieveMethod_Object_Operation->setLowerBound(1);
	m_redefinitionBasedDispatchStrategy_Operation_retrieveMethod_Object_Operation->setUpperBound(1);
	m_redefinitionBasedDispatchStrategy_Operation_retrieveMethod_Object_Operation->setUnique(true);
	m_redefinitionBasedDispatchStrategy_Operation_retrieveMethod_Object_Operation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_redefinitionBasedDispatchStrategy_Operation_retrieveMethod_Object_Operation);
		parameter->setName("object");
		parameter->setEType(getObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_redefinitionBasedDispatchStrategy_Operation_retrieveMethod_Object_Operation);
		parameter->setName("operation");
		parameter->setEType(uml::UmlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeReduceActionActivationContent()
{
	m_reduceActionActivation_Class->setName("ReduceActionActivation");
	m_reduceActionActivation_Class->setAbstract(false);
	m_reduceActionActivation_Class->setInterface(false);
	
	
	m_reduceActionActivation_Attribute_currentExecution->setName("currentExecution");
	m_reduceActionActivation_Attribute_currentExecution->setEType(getExecution_Class());
	m_reduceActionActivation_Attribute_currentExecution->setLowerBound(0);
	m_reduceActionActivation_Attribute_currentExecution->setUpperBound(1);
	m_reduceActionActivation_Attribute_currentExecution->setTransient(false);
	m_reduceActionActivation_Attribute_currentExecution->setVolatile(false);
	m_reduceActionActivation_Attribute_currentExecution->setChangeable(true);
	m_reduceActionActivation_Attribute_currentExecution->setUnsettable(false);
	m_reduceActionActivation_Attribute_currentExecution->setUnique(true);
	m_reduceActionActivation_Attribute_currentExecution->setDerived(false);
	m_reduceActionActivation_Attribute_currentExecution->setOrdered(false);
	m_reduceActionActivation_Attribute_currentExecution->setContainment(false);
	m_reduceActionActivation_Attribute_currentExecution->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_reduceActionActivation_Attribute_currentExecution->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_reduceActionActivation_Attribute_currentExecution->setEOpposite(otherEnd);
	    }
	}
	
	
}

void FUMLPackageImpl::initializeReferenceContent()
{
	m_reference_Class->setName("Reference");
	m_reference_Class->setAbstract(false);
	m_reference_Class->setInterface(false);
	
	
	m_reference_Attribute_referent->setName("referent");
	m_reference_Attribute_referent->setEType(getObject_Class());
	m_reference_Attribute_referent->setLowerBound(1);
	m_reference_Attribute_referent->setUpperBound(1);
	m_reference_Attribute_referent->setTransient(false);
	m_reference_Attribute_referent->setVolatile(false);
	m_reference_Attribute_referent->setChangeable(true);
	m_reference_Attribute_referent->setUnsettable(false);
	m_reference_Attribute_referent->setUnique(true);
	m_reference_Attribute_referent->setDerived(false);
	m_reference_Attribute_referent->setOrdered(false);
	m_reference_Attribute_referent->setContainment(false);
	m_reference_Attribute_referent->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_reference_Attribute_referent->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_reference_Attribute_referent->setEOpposite(otherEnd);
	    }
	}
	
	m_reference_Operation_assignFeatureValue_StructuralFeature_EInt->setEType(nullptr);
	m_reference_Operation_assignFeatureValue_StructuralFeature_EInt->setName("assignFeatureValue");
	m_reference_Operation_assignFeatureValue_StructuralFeature_EInt->setLowerBound(1);
	m_reference_Operation_assignFeatureValue_StructuralFeature_EInt->setUpperBound(1);
	m_reference_Operation_assignFeatureValue_StructuralFeature_EInt->setUnique(true);
	m_reference_Operation_assignFeatureValue_StructuralFeature_EInt->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_reference_Operation_assignFeatureValue_StructuralFeature_EInt);
		parameter->setName("feature");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_reference_Operation_assignFeatureValue_StructuralFeature_EInt);
		parameter->setName("values");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_reference_Operation_assignFeatureValue_StructuralFeature_EInt);
		parameter->setName("position");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_reference_Operation_destroy->setEType(nullptr);
	m_reference_Operation_destroy->setName("destroy");
	m_reference_Operation_destroy->setLowerBound(1);
	m_reference_Operation_destroy->setUpperBound(1);
	m_reference_Operation_destroy->setUnique(true);
	m_reference_Operation_destroy->setOrdered(false);
	
	
	m_reference_Operation_dispatch_Operation->setEType(getExecution_Class());
	m_reference_Operation_dispatch_Operation->setName("dispatch");
	m_reference_Operation_dispatch_Operation->setLowerBound(1);
	m_reference_Operation_dispatch_Operation->setUpperBound(1);
	m_reference_Operation_dispatch_Operation->setUnique(true);
	m_reference_Operation_dispatch_Operation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_reference_Operation_dispatch_Operation);
		parameter->setName("operation");
		parameter->setEType(uml::UmlPackage::eInstance()->getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_reference_Operation_equals_Value->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_reference_Operation_equals_Value->setName("equals");
	m_reference_Operation_equals_Value->setLowerBound(1);
	m_reference_Operation_equals_Value->setUpperBound(1);
	m_reference_Operation_equals_Value->setUnique(true);
	m_reference_Operation_equals_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_reference_Operation_equals_Value);
		parameter->setName("otherValue");
		parameter->setEType(getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_reference_Operation_getTypes->setEType(uml::UmlPackage::eInstance()->getClassifier_Class());
	m_reference_Operation_getTypes->setName("getTypes");
	m_reference_Operation_getTypes->setLowerBound(0);
	m_reference_Operation_getTypes->setUpperBound(-1);
	m_reference_Operation_getTypes->setUnique(true);
	m_reference_Operation_getTypes->setOrdered(false);
	
	
	m_reference_Operation_getValues_StructuralFeature_FeatureValue->setEType(getValue_Class());
	m_reference_Operation_getValues_StructuralFeature_FeatureValue->setName("getValues");
	m_reference_Operation_getValues_StructuralFeature_FeatureValue->setLowerBound(0);
	m_reference_Operation_getValues_StructuralFeature_FeatureValue->setUpperBound(-1);
	m_reference_Operation_getValues_StructuralFeature_FeatureValue->setUnique(true);
	m_reference_Operation_getValues_StructuralFeature_FeatureValue->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_reference_Operation_getValues_StructuralFeature_FeatureValue);
		parameter->setName("feature");
		parameter->setEType(uml::UmlPackage::eInstance()->getStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_reference_Operation_getValues_StructuralFeature_FeatureValue);
		parameter->setName("featureValues");
		parameter->setEType(getFeatureValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_reference_Operation_new_->setEType(getValue_Class());
	m_reference_Operation_new_->setName("new_");
	m_reference_Operation_new_->setLowerBound(1);
	m_reference_Operation_new_->setUpperBound(1);
	m_reference_Operation_new_->setUnique(true);
	m_reference_Operation_new_->setOrdered(false);
	
	
	m_reference_Operation_removeValue_StructuralFeature_Value->setEType(nullptr);
	m_reference_Operation_removeValue_StructuralFeature_Value->setName("removeValue");
	m_reference_Operation_removeValue_StructuralFeature_Value->setLowerBound(1);
	m_reference_Operation_removeValue_StructuralFeature_Value->setUpperBound(1);
	m_reference_Operation_removeValue_StructuralFeature_Value->setUnique(true);
	m_reference_Operation_removeValue_StructuralFeature_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_reference_Operation_removeValue_StructuralFeature_Value);
		parameter->setName("feature");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_reference_Operation_removeValue_StructuralFeature_Value);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_reference_Operation_retrieveFeatureValue_StructuralFeature->setEType(getFeatureValue_Class());
	m_reference_Operation_retrieveFeatureValue_StructuralFeature->setName("retrieveFeatureValue");
	m_reference_Operation_retrieveFeatureValue_StructuralFeature->setLowerBound(1);
	m_reference_Operation_retrieveFeatureValue_StructuralFeature->setUpperBound(1);
	m_reference_Operation_retrieveFeatureValue_StructuralFeature->setUnique(true);
	m_reference_Operation_retrieveFeatureValue_StructuralFeature->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_reference_Operation_retrieveFeatureValue_StructuralFeature);
		parameter->setName("feature");
		parameter->setEType(uml::UmlPackage::eInstance()->getStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_reference_Operation_retrieveFeatureValues->setEType(getFeatureValue_Class());
	m_reference_Operation_retrieveFeatureValues->setName("retrieveFeatureValues");
	m_reference_Operation_retrieveFeatureValues->setLowerBound(0);
	m_reference_Operation_retrieveFeatureValues->setUpperBound(-1);
	m_reference_Operation_retrieveFeatureValues->setUnique(true);
	m_reference_Operation_retrieveFeatureValues->setOrdered(false);
	
	
	m_reference_Operation_send_SignalInstance->setEType(nullptr);
	m_reference_Operation_send_SignalInstance->setName("send");
	m_reference_Operation_send_SignalInstance->setLowerBound(1);
	m_reference_Operation_send_SignalInstance->setUpperBound(1);
	m_reference_Operation_send_SignalInstance->setUnique(true);
	m_reference_Operation_send_SignalInstance->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_reference_Operation_send_SignalInstance);
		parameter->setName("signalInstance");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_reference_Operation_setFeatureValue_StructuralFeature_EInt->setEType(nullptr);
	m_reference_Operation_setFeatureValue_StructuralFeature_EInt->setName("setFeatureValue");
	m_reference_Operation_setFeatureValue_StructuralFeature_EInt->setLowerBound(1);
	m_reference_Operation_setFeatureValue_StructuralFeature_EInt->setUpperBound(1);
	m_reference_Operation_setFeatureValue_StructuralFeature_EInt->setUnique(true);
	m_reference_Operation_setFeatureValue_StructuralFeature_EInt->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_reference_Operation_setFeatureValue_StructuralFeature_EInt);
		parameter->setName("feature");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_reference_Operation_setFeatureValue_StructuralFeature_EInt);
		parameter->setName("values");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_reference_Operation_setFeatureValue_StructuralFeature_EInt);
		parameter->setName("position");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_reference_Operation_startBehavior_Class_ParameterValue->setEType(nullptr);
	m_reference_Operation_startBehavior_Class_ParameterValue->setName("startBehavior");
	m_reference_Operation_startBehavior_Class_ParameterValue->setLowerBound(1);
	m_reference_Operation_startBehavior_Class_ParameterValue->setUpperBound(1);
	m_reference_Operation_startBehavior_Class_ParameterValue->setUnique(true);
	m_reference_Operation_startBehavior_Class_ParameterValue->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_reference_Operation_startBehavior_Class_ParameterValue);
		parameter->setName("classifier");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_reference_Operation_startBehavior_Class_ParameterValue);
		parameter->setName("inputs");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_reference_Operation_toString->setEType(ecore::EcorePackage::eInstance()->getEString_Class());
	m_reference_Operation_toString->setName("toString");
	m_reference_Operation_toString->setLowerBound(1);
	m_reference_Operation_toString->setUpperBound(1);
	m_reference_Operation_toString->setUnique(true);
	m_reference_Operation_toString->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeRemoveStructuralFeatureValueActivationContent()
{
	m_removeStructuralFeatureValueActivation_Class->setName("RemoveStructuralFeatureValueActivation");
	m_removeStructuralFeatureValueActivation_Class->setAbstract(false);
	m_removeStructuralFeatureValueActivation_Class->setInterface(false);
	
	
	
	m_removeStructuralFeatureValueActivation_Operation_doAction->setEType(nullptr);
	m_removeStructuralFeatureValueActivation_Operation_doAction->setName("doAction");
	m_removeStructuralFeatureValueActivation_Operation_doAction->setLowerBound(0);
	m_removeStructuralFeatureValueActivation_Operation_doAction->setUpperBound(1);
	m_removeStructuralFeatureValueActivation_Operation_doAction->setUnique(true);
	m_removeStructuralFeatureValueActivation_Operation_doAction->setOrdered(true);
	
	
	
}

void FUMLPackageImpl::initializeSemanticStrategyContent()
{
	m_semanticStrategy_Class->setName("SemanticStrategy");
	m_semanticStrategy_Class->setAbstract(true);
	m_semanticStrategy_Class->setInterface(false);
	
	
	
	m_semanticStrategy_Operation_retrieveName->setEType(ecore::EcorePackage::eInstance()->getEString_Class());
	m_semanticStrategy_Operation_retrieveName->setName("retrieveName");
	m_semanticStrategy_Operation_retrieveName->setLowerBound(1);
	m_semanticStrategy_Operation_retrieveName->setUpperBound(1);
	m_semanticStrategy_Operation_retrieveName->setUnique(true);
	m_semanticStrategy_Operation_retrieveName->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeSemanticVisitorContent()
{
	m_semanticVisitor_Class->setName("SemanticVisitor");
	m_semanticVisitor_Class->setAbstract(true);
	m_semanticVisitor_Class->setInterface(false);
	
	
	
	m_semanticVisitor_Operation__beginIsolation->setEType(nullptr);
	m_semanticVisitor_Operation__beginIsolation->setName("_beginIsolation");
	m_semanticVisitor_Operation__beginIsolation->setLowerBound(1);
	m_semanticVisitor_Operation__beginIsolation->setUpperBound(1);
	m_semanticVisitor_Operation__beginIsolation->setUnique(true);
	m_semanticVisitor_Operation__beginIsolation->setOrdered(false);
	
	
	m_semanticVisitor_Operation__endIsolation->setEType(nullptr);
	m_semanticVisitor_Operation__endIsolation->setName("_endIsolation");
	m_semanticVisitor_Operation__endIsolation->setLowerBound(1);
	m_semanticVisitor_Operation__endIsolation->setUpperBound(1);
	m_semanticVisitor_Operation__endIsolation->setUnique(true);
	m_semanticVisitor_Operation__endIsolation->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeSendSignalActionActivationContent()
{
	m_sendSignalActionActivation_Class->setName("SendSignalActionActivation");
	m_sendSignalActionActivation_Class->setAbstract(false);
	m_sendSignalActionActivation_Class->setInterface(false);
	
	
	
	m_sendSignalActionActivation_Operation_doAction->setEType(nullptr);
	m_sendSignalActionActivation_Operation_doAction->setName("doAction");
	m_sendSignalActionActivation_Operation_doAction->setLowerBound(1);
	m_sendSignalActionActivation_Operation_doAction->setUpperBound(1);
	m_sendSignalActionActivation_Operation_doAction->setUnique(true);
	m_sendSignalActionActivation_Operation_doAction->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeSignalInstanceContent()
{
	m_signalInstance_Class->setName("SignalInstance");
	m_signalInstance_Class->setAbstract(false);
	m_signalInstance_Class->setInterface(false);
	
	
	m_signalInstance_Attribute_type->setName("type");
	m_signalInstance_Attribute_type->setEType(uml::UmlPackage::eInstance()->getSignal_Class());
	m_signalInstance_Attribute_type->setLowerBound(1);
	m_signalInstance_Attribute_type->setUpperBound(1);
	m_signalInstance_Attribute_type->setTransient(false);
	m_signalInstance_Attribute_type->setVolatile(false);
	m_signalInstance_Attribute_type->setChangeable(true);
	m_signalInstance_Attribute_type->setUnsettable(false);
	m_signalInstance_Attribute_type->setUnique(true);
	m_signalInstance_Attribute_type->setDerived(false);
	m_signalInstance_Attribute_type->setOrdered(false);
	m_signalInstance_Attribute_type->setContainment(false);
	m_signalInstance_Attribute_type->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_signalInstance_Attribute_type->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_signalInstance_Attribute_type->setEOpposite(otherEnd);
	    }
	}
	
	
}

void FUMLPackageImpl::initializeStartClassifierBehaviorActionActivationContent()
{
	m_startClassifierBehaviorActionActivation_Class->setName("StartClassifierBehaviorActionActivation");
	m_startClassifierBehaviorActionActivation_Class->setAbstract(false);
	m_startClassifierBehaviorActionActivation_Class->setInterface(false);
	
	
	
	m_startClassifierBehaviorActionActivation_Operation_doAction->setEType(nullptr);
	m_startClassifierBehaviorActionActivation_Operation_doAction->setName("doAction");
	m_startClassifierBehaviorActionActivation_Operation_doAction->setLowerBound(0);
	m_startClassifierBehaviorActionActivation_Operation_doAction->setUpperBound(1);
	m_startClassifierBehaviorActionActivation_Operation_doAction->setUnique(true);
	m_startClassifierBehaviorActionActivation_Operation_doAction->setOrdered(true);
	
	
	
}

void FUMLPackageImpl::initializeStartObjectBehaviorActionActivationContent()
{
	m_startObjectBehaviorActionActivation_Class->setName("StartObjectBehaviorActionActivation");
	m_startObjectBehaviorActionActivation_Class->setAbstract(false);
	m_startObjectBehaviorActionActivation_Class->setInterface(false);
	
	
	
	m_startObjectBehaviorActionActivation_Operation_doAction->setEType(nullptr);
	m_startObjectBehaviorActionActivation_Operation_doAction->setName("doAction");
	m_startObjectBehaviorActionActivation_Operation_doAction->setLowerBound(0);
	m_startObjectBehaviorActionActivation_Operation_doAction->setUpperBound(1);
	m_startObjectBehaviorActionActivation_Operation_doAction->setUnique(true);
	m_startObjectBehaviorActionActivation_Operation_doAction->setOrdered(true);
	
	
	
}

void FUMLPackageImpl::initializeStringValueContent()
{
	m_stringValue_Class->setName("StringValue");
	m_stringValue_Class->setAbstract(false);
	m_stringValue_Class->setInterface(false);
	
	m_stringValue_Attribute_value = getStringValue_Attribute_value();
	m_stringValue_Attribute_value->setName("value");
	m_stringValue_Attribute_value->setEType(ecore::EcorePackage::eInstance()->getEString_Class());
	m_stringValue_Attribute_value->setLowerBound(1);
	m_stringValue_Attribute_value->setUpperBound(1);
	m_stringValue_Attribute_value->setTransient(false);
	m_stringValue_Attribute_value->setVolatile(false);
	m_stringValue_Attribute_value->setChangeable(true);
	m_stringValue_Attribute_value->setUnsettable(false);
	m_stringValue_Attribute_value->setUnique(true);
	m_stringValue_Attribute_value->setDerived(false);
	m_stringValue_Attribute_value->setOrdered(false);
	m_stringValue_Attribute_value->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_stringValue_Attribute_value->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	m_stringValue_Operation_equals_Value->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_stringValue_Operation_equals_Value->setName("equals");
	m_stringValue_Operation_equals_Value->setLowerBound(1);
	m_stringValue_Operation_equals_Value->setUpperBound(1);
	m_stringValue_Operation_equals_Value->setUnique(true);
	m_stringValue_Operation_equals_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_stringValue_Operation_equals_Value);
		parameter->setName("otherValue");
		parameter->setEType(getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stringValue_Operation_specify->setEType(uml::UmlPackage::eInstance()->getValueSpecification_Class());
	m_stringValue_Operation_specify->setName("specify");
	m_stringValue_Operation_specify->setLowerBound(1);
	m_stringValue_Operation_specify->setUpperBound(1);
	m_stringValue_Operation_specify->setUnique(true);
	m_stringValue_Operation_specify->setOrdered(false);
	
	
	m_stringValue_Operation_toString->setEType(ecore::EcorePackage::eInstance()->getEString_Class());
	m_stringValue_Operation_toString->setName("toString");
	m_stringValue_Operation_toString->setLowerBound(1);
	m_stringValue_Operation_toString->setUpperBound(1);
	m_stringValue_Operation_toString->setUnique(true);
	m_stringValue_Operation_toString->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeStructuralFeatureActionActivationContent()
{
	m_structuralFeatureActionActivation_Class->setName("StructuralFeatureActionActivation");
	m_structuralFeatureActionActivation_Class->setAbstract(true);
	m_structuralFeatureActionActivation_Class->setInterface(false);
	
	
	
	m_structuralFeatureActionActivation_Operation_getAssociation_StructuralFeature->setEType(uml::UmlPackage::eInstance()->getAssociation_Class());
	m_structuralFeatureActionActivation_Operation_getAssociation_StructuralFeature->setName("getAssociation");
	m_structuralFeatureActionActivation_Operation_getAssociation_StructuralFeature->setLowerBound(0);
	m_structuralFeatureActionActivation_Operation_getAssociation_StructuralFeature->setUpperBound(1);
	m_structuralFeatureActionActivation_Operation_getAssociation_StructuralFeature->setUnique(true);
	m_structuralFeatureActionActivation_Operation_getAssociation_StructuralFeature->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuralFeatureActionActivation_Operation_getAssociation_StructuralFeature);
		parameter->setName("feature");
		parameter->setEType(uml::UmlPackage::eInstance()->getStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_Value->setEType(getLink_Class());
	m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_Value->setName("getMatchingLinks");
	m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_Value->setLowerBound(0);
	m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_Value->setUpperBound(-1);
	m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_Value->setUnique(true);
	m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_Value);
		parameter->setName("association");
		parameter->setEType(uml::UmlPackage::eInstance()->getAssociation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_Value);
		parameter->setName("end");
		parameter->setEType(uml::UmlPackage::eInstance()->getStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuralFeatureActionActivation_Operation_getMatchingLinks_Association_Value);
		parameter->setName("oppositeValue");
		parameter->setEType(getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature->setEType(uml::UmlPackage::eInstance()->getProperty_Class());
	m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature->setName("getOppositeEnd");
	m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature->setLowerBound(1);
	m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature->setUpperBound(1);
	m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature->setUnique(true);
	m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature);
		parameter->setName("association");
		parameter->setEType(uml::UmlPackage::eInstance()->getAssociation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuralFeatureActionActivation_Operation_getOppositeEnd_Association_StructuralFeature);
		parameter->setName("end");
		parameter->setEType(uml::UmlPackage::eInstance()->getStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializeStructuredActivityNodeActivationContent()
{
	m_structuredActivityNodeActivation_Class->setName("StructuredActivityNodeActivation");
	m_structuredActivityNodeActivation_Class->setAbstract(false);
	m_structuredActivityNodeActivation_Class->setInterface(false);
	
	
	m_structuredActivityNodeActivation_Attribute_activationGroup->setName("activationGroup");
	m_structuredActivityNodeActivation_Attribute_activationGroup->setEType(getActivityNodeActivationGroup_Class());
	m_structuredActivityNodeActivation_Attribute_activationGroup->setLowerBound(1);
	m_structuredActivityNodeActivation_Attribute_activationGroup->setUpperBound(1);
	m_structuredActivityNodeActivation_Attribute_activationGroup->setTransient(false);
	m_structuredActivityNodeActivation_Attribute_activationGroup->setVolatile(false);
	m_structuredActivityNodeActivation_Attribute_activationGroup->setChangeable(true);
	m_structuredActivityNodeActivation_Attribute_activationGroup->setUnsettable(false);
	m_structuredActivityNodeActivation_Attribute_activationGroup->setUnique(true);
	m_structuredActivityNodeActivation_Attribute_activationGroup->setDerived(false);
	m_structuredActivityNodeActivation_Attribute_activationGroup->setOrdered(false);
	m_structuredActivityNodeActivation_Attribute_activationGroup->setContainment(true);
	m_structuredActivityNodeActivation_Attribute_activationGroup->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_structuredActivityNodeActivation_Attribute_activationGroup->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getActivityNodeActivationGroup_Attribute_containingNodeActivation();
		if (otherEnd != nullptr)
	    {
	   		m_structuredActivityNodeActivation_Attribute_activationGroup->setEOpposite(otherEnd);
	    }
	}
	
	m_structuredActivityNodeActivation_Operation_completeAction->setEType(getToken_Class());
	m_structuredActivityNodeActivation_Operation_completeAction->setName("completeAction");
	m_structuredActivityNodeActivation_Operation_completeAction->setLowerBound(0);
	m_structuredActivityNodeActivation_Operation_completeAction->setUpperBound(-1);
	m_structuredActivityNodeActivation_Operation_completeAction->setUnique(true);
	m_structuredActivityNodeActivation_Operation_completeAction->setOrdered(false);
	
	
	m_structuredActivityNodeActivation_Operation_createEdgeInstances->setEType(nullptr);
	m_structuredActivityNodeActivation_Operation_createEdgeInstances->setName("createEdgeInstances");
	m_structuredActivityNodeActivation_Operation_createEdgeInstances->setLowerBound(1);
	m_structuredActivityNodeActivation_Operation_createEdgeInstances->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_createEdgeInstances->setUnique(true);
	m_structuredActivityNodeActivation_Operation_createEdgeInstances->setOrdered(false);
	
	
	m_structuredActivityNodeActivation_Operation_createNodeActivations->setEType(nullptr);
	m_structuredActivityNodeActivation_Operation_createNodeActivations->setName("createNodeActivations");
	m_structuredActivityNodeActivation_Operation_createNodeActivations->setLowerBound(1);
	m_structuredActivityNodeActivation_Operation_createNodeActivations->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_createNodeActivations->setUnique(true);
	m_structuredActivityNodeActivation_Operation_createNodeActivations->setOrdered(false);
	
	
	m_structuredActivityNodeActivation_Operation_doAction->setEType(nullptr);
	m_structuredActivityNodeActivation_Operation_doAction->setName("doAction");
	m_structuredActivityNodeActivation_Operation_doAction->setLowerBound(1);
	m_structuredActivityNodeActivation_Operation_doAction->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_doAction->setUnique(true);
	m_structuredActivityNodeActivation_Operation_doAction->setOrdered(false);
	
	
	m_structuredActivityNodeActivation_Operation_doStructuredActivity->setEType(nullptr);
	m_structuredActivityNodeActivation_Operation_doStructuredActivity->setName("doStructuredActivity");
	m_structuredActivityNodeActivation_Operation_doStructuredActivity->setLowerBound(0);
	m_structuredActivityNodeActivation_Operation_doStructuredActivity->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_doStructuredActivity->setUnique(true);
	m_structuredActivityNodeActivation_Operation_doStructuredActivity->setOrdered(false);
	
	
	m_structuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode->setEType(getActivityNodeActivation_Class());
	m_structuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode->setName("getNodeActivation");
	m_structuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode->setLowerBound(1);
	m_structuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode->setUnique(true);
	m_structuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuredActivityNodeActivation_Operation_getNodeActivation_ActivityNode);
		parameter->setName("node");
		parameter->setEType(uml::UmlPackage::eInstance()->getActivityNode_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuredActivityNodeActivation_Operation_getPinValues_OutputPin->setEType(getValue_Class());
	m_structuredActivityNodeActivation_Operation_getPinValues_OutputPin->setName("getPinValues");
	m_structuredActivityNodeActivation_Operation_getPinValues_OutputPin->setLowerBound(0);
	m_structuredActivityNodeActivation_Operation_getPinValues_OutputPin->setUpperBound(-1);
	m_structuredActivityNodeActivation_Operation_getPinValues_OutputPin->setUnique(true);
	m_structuredActivityNodeActivation_Operation_getPinValues_OutputPin->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuredActivityNodeActivation_Operation_getPinValues_OutputPin);
		parameter->setName("pin");
		parameter->setEType(uml::UmlPackage::eInstance()->getOutputPin_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_structuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setName("isSourceFor");
	m_structuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setLowerBound(1);
	m_structuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setUnique(true);
	m_structuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuredActivityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance);
		parameter->setName("edgeInstance");
		parameter->setEType(getActivityEdgeInstance_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuredActivityNodeActivation_Operation_isSuspended->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_structuredActivityNodeActivation_Operation_isSuspended->setName("isSuspended");
	m_structuredActivityNodeActivation_Operation_isSuspended->setLowerBound(1);
	m_structuredActivityNodeActivation_Operation_isSuspended->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_isSuspended->setUnique(true);
	m_structuredActivityNodeActivation_Operation_isSuspended->setOrdered(false);
	
	
	m_structuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode->setEType(uml::UmlPackage::eInstance()->getActivityNode_Class());
	m_structuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode->setName("makeActivityNodeList");
	m_structuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode->setLowerBound(0);
	m_structuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode->setUpperBound(-1);
	m_structuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode->setUnique(true);
	m_structuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuredActivityNodeActivation_Operation_makeActivityNodeList_ExecutableNode);
		parameter->setName("nodes");
		parameter->setEType(uml::UmlPackage::eInstance()->getExecutableNode_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_Value->setEType(nullptr);
	m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_Value->setName("putPinValues");
	m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_Value->setLowerBound(1);
	m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_Value->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_Value->setUnique(true);
	m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_Value);
		parameter->setName("pin");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuredActivityNodeActivation_Operation_putPinValues_OutputPin_Value);
		parameter->setName("values");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuredActivityNodeActivation_Operation_resume->setEType(nullptr);
	m_structuredActivityNodeActivation_Operation_resume->setName("resume");
	m_structuredActivityNodeActivation_Operation_resume->setLowerBound(1);
	m_structuredActivityNodeActivation_Operation_resume->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_resume->setUnique(true);
	m_structuredActivityNodeActivation_Operation_resume->setOrdered(false);
	
	
	m_structuredActivityNodeActivation_Operation_terminate->setEType(nullptr);
	m_structuredActivityNodeActivation_Operation_terminate->setName("terminate");
	m_structuredActivityNodeActivation_Operation_terminate->setLowerBound(1);
	m_structuredActivityNodeActivation_Operation_terminate->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_terminate->setUnique(true);
	m_structuredActivityNodeActivation_Operation_terminate->setOrdered(false);
	
	
	m_structuredActivityNodeActivation_Operation_terminateAll->setEType(nullptr);
	m_structuredActivityNodeActivation_Operation_terminateAll->setName("terminateAll");
	m_structuredActivityNodeActivation_Operation_terminateAll->setLowerBound(1);
	m_structuredActivityNodeActivation_Operation_terminateAll->setUpperBound(1);
	m_structuredActivityNodeActivation_Operation_terminateAll->setUnique(true);
	m_structuredActivityNodeActivation_Operation_terminateAll->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeStructuredValueContent()
{
	m_structuredValue_Class->setName("StructuredValue");
	m_structuredValue_Class->setAbstract(true);
	m_structuredValue_Class->setInterface(false);
	
	
	
	m_structuredValue_Operation_assignFeatureValue_StructuralFeature_EInt->setEType(nullptr);
	m_structuredValue_Operation_assignFeatureValue_StructuralFeature_EInt->setName("assignFeatureValue");
	m_structuredValue_Operation_assignFeatureValue_StructuralFeature_EInt->setLowerBound(1);
	m_structuredValue_Operation_assignFeatureValue_StructuralFeature_EInt->setUpperBound(1);
	m_structuredValue_Operation_assignFeatureValue_StructuralFeature_EInt->setUnique(true);
	m_structuredValue_Operation_assignFeatureValue_StructuralFeature_EInt->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuredValue_Operation_assignFeatureValue_StructuralFeature_EInt);
		parameter->setName("feature");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuredValue_Operation_assignFeatureValue_StructuralFeature_EInt);
		parameter->setName("values");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuredValue_Operation_assignFeatureValue_StructuralFeature_EInt);
		parameter->setName("position");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuredValue_Operation_createFeatureValues->setEType(nullptr);
	m_structuredValue_Operation_createFeatureValues->setName("createFeatureValues");
	m_structuredValue_Operation_createFeatureValues->setLowerBound(0);
	m_structuredValue_Operation_createFeatureValues->setUpperBound(1);
	m_structuredValue_Operation_createFeatureValues->setUnique(true);
	m_structuredValue_Operation_createFeatureValues->setOrdered(true);
	
	
	m_structuredValue_Operation_getValues_StructuralFeature_FeatureValue->setEType(getValue_Class());
	m_structuredValue_Operation_getValues_StructuralFeature_FeatureValue->setName("getValues");
	m_structuredValue_Operation_getValues_StructuralFeature_FeatureValue->setLowerBound(0);
	m_structuredValue_Operation_getValues_StructuralFeature_FeatureValue->setUpperBound(-1);
	m_structuredValue_Operation_getValues_StructuralFeature_FeatureValue->setUnique(true);
	m_structuredValue_Operation_getValues_StructuralFeature_FeatureValue->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuredValue_Operation_getValues_StructuralFeature_FeatureValue);
		parameter->setName("feature");
		parameter->setEType(uml::UmlPackage::eInstance()->getStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuredValue_Operation_getValues_StructuralFeature_FeatureValue);
		parameter->setName("featureValues");
		parameter->setEType(getFeatureValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuredValue_Operation_removeValue_StructuralFeature_Value->setEType(nullptr);
	m_structuredValue_Operation_removeValue_StructuralFeature_Value->setName("removeValue");
	m_structuredValue_Operation_removeValue_StructuralFeature_Value->setLowerBound(1);
	m_structuredValue_Operation_removeValue_StructuralFeature_Value->setUpperBound(1);
	m_structuredValue_Operation_removeValue_StructuralFeature_Value->setUnique(true);
	m_structuredValue_Operation_removeValue_StructuralFeature_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuredValue_Operation_removeValue_StructuralFeature_Value);
		parameter->setName("feature");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuredValue_Operation_removeValue_StructuralFeature_Value);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuredValue_Operation_retrieveFeatureValue_StructuralFeature->setEType(getFeatureValue_Class());
	m_structuredValue_Operation_retrieveFeatureValue_StructuralFeature->setName("retrieveFeatureValue");
	m_structuredValue_Operation_retrieveFeatureValue_StructuralFeature->setLowerBound(1);
	m_structuredValue_Operation_retrieveFeatureValue_StructuralFeature->setUpperBound(1);
	m_structuredValue_Operation_retrieveFeatureValue_StructuralFeature->setUnique(true);
	m_structuredValue_Operation_retrieveFeatureValue_StructuralFeature->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuredValue_Operation_retrieveFeatureValue_StructuralFeature);
		parameter->setName("feature");
		parameter->setEType(uml::UmlPackage::eInstance()->getStructuralFeature_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuredValue_Operation_retrieveFeatureValues->setEType(getFeatureValue_Class());
	m_structuredValue_Operation_retrieveFeatureValues->setName("retrieveFeatureValues");
	m_structuredValue_Operation_retrieveFeatureValues->setLowerBound(0);
	m_structuredValue_Operation_retrieveFeatureValues->setUpperBound(-1);
	m_structuredValue_Operation_retrieveFeatureValues->setUnique(true);
	m_structuredValue_Operation_retrieveFeatureValues->setOrdered(false);
	
	
	m_structuredValue_Operation_setFeatureValue_StructuralFeature_EInt->setEType(nullptr);
	m_structuredValue_Operation_setFeatureValue_StructuralFeature_EInt->setName("setFeatureValue");
	m_structuredValue_Operation_setFeatureValue_StructuralFeature_EInt->setLowerBound(1);
	m_structuredValue_Operation_setFeatureValue_StructuralFeature_EInt->setUpperBound(1);
	m_structuredValue_Operation_setFeatureValue_StructuralFeature_EInt->setUnique(true);
	m_structuredValue_Operation_setFeatureValue_StructuralFeature_EInt->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuredValue_Operation_setFeatureValue_StructuralFeature_EInt);
		parameter->setName("feature");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuredValue_Operation_setFeatureValue_StructuralFeature_EInt);
		parameter->setName("values");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_structuredValue_Operation_setFeatureValue_StructuralFeature_EInt);
		parameter->setName("position");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuredValue_Operation_specify->setEType(uml::UmlPackage::eInstance()->getValueSpecification_Class());
	m_structuredValue_Operation_specify->setName("specify");
	m_structuredValue_Operation_specify->setLowerBound(1);
	m_structuredValue_Operation_specify->setUpperBound(1);
	m_structuredValue_Operation_specify->setUnique(true);
	m_structuredValue_Operation_specify->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeTestIdentityActionActivationContent()
{
	m_testIdentityActionActivation_Class->setName("TestIdentityActionActivation");
	m_testIdentityActionActivation_Class->setAbstract(false);
	m_testIdentityActionActivation_Class->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeTokenContent()
{
	m_token_Class->setName("Token");
	m_token_Class->setAbstract(true);
	m_token_Class->setInterface(false);
	
	m_token_Attribute_withdrawn = getToken_Attribute_withdrawn();
	m_token_Attribute_withdrawn->setName("withdrawn");
	m_token_Attribute_withdrawn->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_token_Attribute_withdrawn->setLowerBound(0);
	m_token_Attribute_withdrawn->setUpperBound(1);
	m_token_Attribute_withdrawn->setTransient(false);
	m_token_Attribute_withdrawn->setVolatile(false);
	m_token_Attribute_withdrawn->setChangeable(true);
	m_token_Attribute_withdrawn->setUnsettable(false);
	m_token_Attribute_withdrawn->setUnique(true);
	m_token_Attribute_withdrawn->setDerived(false);
	m_token_Attribute_withdrawn->setOrdered(true);
	m_token_Attribute_withdrawn->setID(false);
	{
		std::string defaultValue = "true";
		if (!defaultValue.empty())
		{
		   m_token_Attribute_withdrawn->setDefaultValueLiteral(defaultValue);
		}
	}
	
	m_token_Attribute_holder->setName("holder");
	m_token_Attribute_holder->setEType(getActivityNodeActivation_Class());
	m_token_Attribute_holder->setLowerBound(0);
	m_token_Attribute_holder->setUpperBound(1);
	m_token_Attribute_holder->setTransient(false);
	m_token_Attribute_holder->setVolatile(false);
	m_token_Attribute_holder->setChangeable(true);
	m_token_Attribute_holder->setUnsettable(false);
	m_token_Attribute_holder->setUnique(true);
	m_token_Attribute_holder->setDerived(false);
	m_token_Attribute_holder->setOrdered(false);
	m_token_Attribute_holder->setContainment(false);
	m_token_Attribute_holder->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_token_Attribute_holder->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = getActivityNodeActivation_Attribute_heldTokens();
		if (otherEnd != nullptr)
	    {
	   		m_token_Attribute_holder->setEOpposite(otherEnd);
	    }
	}
	
	m_token_Operation_equals_Token->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_token_Operation_equals_Token->setName("equals");
	m_token_Operation_equals_Token->setLowerBound(1);
	m_token_Operation_equals_Token->setUpperBound(1);
	m_token_Operation_equals_Token->setUnique(true);
	m_token_Operation_equals_Token->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_token_Operation_equals_Token);
		parameter->setName("other");
		parameter->setEType(getToken_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_token_Operation_getValue->setEType(getValue_Class());
	m_token_Operation_getValue->setName("getValue");
	m_token_Operation_getValue->setLowerBound(0);
	m_token_Operation_getValue->setUpperBound(1);
	m_token_Operation_getValue->setUnique(true);
	m_token_Operation_getValue->setOrdered(false);
	
	
	m_token_Operation_isControl->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_token_Operation_isControl->setName("isControl");
	m_token_Operation_isControl->setLowerBound(1);
	m_token_Operation_isControl->setUpperBound(1);
	m_token_Operation_isControl->setUnique(true);
	m_token_Operation_isControl->setOrdered(false);
	
	
	m_token_Operation_transfer_ActivityNodeActivation->setEType(getToken_Class());
	m_token_Operation_transfer_ActivityNodeActivation->setName("transfer");
	m_token_Operation_transfer_ActivityNodeActivation->setLowerBound(1);
	m_token_Operation_transfer_ActivityNodeActivation->setUpperBound(1);
	m_token_Operation_transfer_ActivityNodeActivation->setUnique(true);
	m_token_Operation_transfer_ActivityNodeActivation->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_token_Operation_transfer_ActivityNodeActivation);
		parameter->setName("holder");
		parameter->setEType(getActivityNodeActivation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_token_Operation_withdraw->setEType(nullptr);
	m_token_Operation_withdraw->setName("withdraw");
	m_token_Operation_withdraw->setLowerBound(1);
	m_token_Operation_withdraw->setUpperBound(1);
	m_token_Operation_withdraw->setUnique(true);
	m_token_Operation_withdraw->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeTokenSetContent()
{
	m_tokenSet_Class->setName("TokenSet");
	m_tokenSet_Class->setAbstract(false);
	m_tokenSet_Class->setInterface(false);
	
	
	m_tokenSet_Attribute_tokens->setName("tokens");
	m_tokenSet_Attribute_tokens->setEType(getToken_Class());
	m_tokenSet_Attribute_tokens->setLowerBound(0);
	m_tokenSet_Attribute_tokens->setUpperBound(-1);
	m_tokenSet_Attribute_tokens->setTransient(false);
	m_tokenSet_Attribute_tokens->setVolatile(false);
	m_tokenSet_Attribute_tokens->setChangeable(true);
	m_tokenSet_Attribute_tokens->setUnsettable(false);
	m_tokenSet_Attribute_tokens->setUnique(true);
	m_tokenSet_Attribute_tokens->setDerived(false);
	m_tokenSet_Attribute_tokens->setOrdered(false);
	m_tokenSet_Attribute_tokens->setContainment(false);
	m_tokenSet_Attribute_tokens->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_tokenSet_Attribute_tokens->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_tokenSet_Attribute_tokens->setEOpposite(otherEnd);
	    }
	}
	
	
}

void FUMLPackageImpl::initializeUnlimitedNaturalValueContent()
{
	m_unlimitedNaturalValue_Class->setName("UnlimitedNaturalValue");
	m_unlimitedNaturalValue_Class->setAbstract(false);
	m_unlimitedNaturalValue_Class->setInterface(false);
	
	m_unlimitedNaturalValue_Attribute_value = getUnlimitedNaturalValue_Attribute_value();
	m_unlimitedNaturalValue_Attribute_value->setName("value");
	m_unlimitedNaturalValue_Attribute_value->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
	m_unlimitedNaturalValue_Attribute_value->setLowerBound(1);
	m_unlimitedNaturalValue_Attribute_value->setUpperBound(1);
	m_unlimitedNaturalValue_Attribute_value->setTransient(false);
	m_unlimitedNaturalValue_Attribute_value->setVolatile(false);
	m_unlimitedNaturalValue_Attribute_value->setChangeable(true);
	m_unlimitedNaturalValue_Attribute_value->setUnsettable(false);
	m_unlimitedNaturalValue_Attribute_value->setUnique(true);
	m_unlimitedNaturalValue_Attribute_value->setDerived(false);
	m_unlimitedNaturalValue_Attribute_value->setOrdered(false);
	m_unlimitedNaturalValue_Attribute_value->setID(false);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
		   m_unlimitedNaturalValue_Attribute_value->setDefaultValueLiteral(defaultValue);
		}
	}
	
	
	m_unlimitedNaturalValue_Operation_equals_Value->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_unlimitedNaturalValue_Operation_equals_Value->setName("equals");
	m_unlimitedNaturalValue_Operation_equals_Value->setLowerBound(1);
	m_unlimitedNaturalValue_Operation_equals_Value->setUpperBound(1);
	m_unlimitedNaturalValue_Operation_equals_Value->setUnique(true);
	m_unlimitedNaturalValue_Operation_equals_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_unlimitedNaturalValue_Operation_equals_Value);
		parameter->setName("otherValue");
		parameter->setEType(getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_unlimitedNaturalValue_Operation_specify->setEType(uml::UmlPackage::eInstance()->getValueSpecification_Class());
	m_unlimitedNaturalValue_Operation_specify->setName("specify");
	m_unlimitedNaturalValue_Operation_specify->setLowerBound(1);
	m_unlimitedNaturalValue_Operation_specify->setUpperBound(1);
	m_unlimitedNaturalValue_Operation_specify->setUnique(true);
	m_unlimitedNaturalValue_Operation_specify->setOrdered(false);
	
	
	m_unlimitedNaturalValue_Operation_toString->setEType(ecore::EcorePackage::eInstance()->getEString_Class());
	m_unlimitedNaturalValue_Operation_toString->setName("toString");
	m_unlimitedNaturalValue_Operation_toString->setLowerBound(1);
	m_unlimitedNaturalValue_Operation_toString->setUpperBound(1);
	m_unlimitedNaturalValue_Operation_toString->setUnique(true);
	m_unlimitedNaturalValue_Operation_toString->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeValueContent()
{
	m_value_Class->setName("Value");
	m_value_Class->setAbstract(true);
	m_value_Class->setInterface(false);
	
	
	
	m_value_Operation_equals_Value->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_value_Operation_equals_Value->setName("equals");
	m_value_Operation_equals_Value->setLowerBound(1);
	m_value_Operation_equals_Value->setUpperBound(1);
	m_value_Operation_equals_Value->setUnique(true);
	m_value_Operation_equals_Value->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_value_Operation_equals_Value);
		parameter->setName("otherValue");
		parameter->setEType(getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_value_Operation_getTypes->setEType(uml::UmlPackage::eInstance()->getClassifier_Class());
	m_value_Operation_getTypes->setName("getTypes");
	m_value_Operation_getTypes->setLowerBound(0);
	m_value_Operation_getTypes->setUpperBound(-1);
	m_value_Operation_getTypes->setUnique(true);
	m_value_Operation_getTypes->setOrdered(false);
	
	
	m_value_Operation_hasTypes_Classifier->setEType(ecore::EcorePackage::eInstance()->getEBoolean_Class());
	m_value_Operation_hasTypes_Classifier->setName("hasTypes");
	m_value_Operation_hasTypes_Classifier->setLowerBound(1);
	m_value_Operation_hasTypes_Classifier->setUpperBound(1);
	m_value_Operation_hasTypes_Classifier->setUnique(true);
	m_value_Operation_hasTypes_Classifier->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_value_Operation_hasTypes_Classifier);
		parameter->setName("type");
		parameter->setEType(uml::UmlPackage::eInstance()->getClassifier_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_value_Operation_objectId->setEType(ecore::EcorePackage::eInstance()->getEString_Class());
	m_value_Operation_objectId->setName("objectId");
	m_value_Operation_objectId->setLowerBound(1);
	m_value_Operation_objectId->setUpperBound(1);
	m_value_Operation_objectId->setUnique(true);
	m_value_Operation_objectId->setOrdered(false);
	
	
	m_value_Operation_specify->setEType(uml::UmlPackage::eInstance()->getValueSpecification_Class());
	m_value_Operation_specify->setName("specify");
	m_value_Operation_specify->setLowerBound(1);
	m_value_Operation_specify->setUpperBound(1);
	m_value_Operation_specify->setUnique(true);
	m_value_Operation_specify->setOrdered(false);
	
	
	m_value_Operation_toString->setEType(ecore::EcorePackage::eInstance()->getEString_Class());
	m_value_Operation_toString->setName("toString");
	m_value_Operation_toString->setLowerBound(1);
	m_value_Operation_toString->setUpperBound(1);
	m_value_Operation_toString->setUnique(true);
	m_value_Operation_toString->setOrdered(false);
	
	
	
}

void FUMLPackageImpl::initializeValueSpecificationActionActivationContent()
{
	m_valueSpecificationActionActivation_Class->setName("ValueSpecificationActionActivation");
	m_valueSpecificationActionActivation_Class->setAbstract(false);
	m_valueSpecificationActionActivation_Class->setInterface(false);
	
	
	
	m_valueSpecificationActionActivation_Operation_doAction->setEType(nullptr);
	m_valueSpecificationActionActivation_Operation_doAction->setName("doAction");
	m_valueSpecificationActionActivation_Operation_doAction->setLowerBound(0);
	m_valueSpecificationActionActivation_Operation_doAction->setUpperBound(1);
	m_valueSpecificationActionActivation_Operation_doAction->setUnique(true);
	m_valueSpecificationActionActivation_Operation_doAction->setOrdered(true);
	
	
	
}

void FUMLPackageImpl::initializeValuesContent()
{
	m_values_Class->setName("Values");
	m_values_Class->setAbstract(false);
	m_values_Class->setInterface(false);
	
	
	m_values_Attribute_values->setName("values");
	m_values_Attribute_values->setEType(getValue_Class());
	m_values_Attribute_values->setLowerBound(0);
	m_values_Attribute_values->setUpperBound(-1);
	m_values_Attribute_values->setTransient(false);
	m_values_Attribute_values->setVolatile(false);
	m_values_Attribute_values->setChangeable(true);
	m_values_Attribute_values->setUnsettable(false);
	m_values_Attribute_values->setUnique(true);
	m_values_Attribute_values->setDerived(false);
	m_values_Attribute_values->setOrdered(false);
	m_values_Attribute_values->setContainment(false);
	m_values_Attribute_values->setResolveProxies(true);
	{
		std::string defaultValue = "";
		if (!defaultValue.empty())
		{
			m_values_Attribute_values->setDefaultValueLiteral(defaultValue);
		}
		std::shared_ptr<ecore::EReference>  otherEnd = nullptr;
		if (otherEnd != nullptr)
	    {
	   		m_values_Attribute_values->setEOpposite(otherEnd);
	    }
	}
	
	
}

void FUMLPackageImpl::initializeWriteLinkActionActivationContent()
{
	m_writeLinkActionActivation_Class->setName("WriteLinkActionActivation");
	m_writeLinkActionActivation_Class->setAbstract(true);
	m_writeLinkActionActivation_Class->setInterface(false);
	
	
	
	
}

void FUMLPackageImpl::initializeWriteStructuralFeatureActionActivationContent()
{
	m_writeStructuralFeatureActionActivation_Class->setName("WriteStructuralFeatureActionActivation");
	m_writeStructuralFeatureActionActivation_Class->setAbstract(true);
	m_writeStructuralFeatureActionActivation_Class->setInterface(false);
	
	
	
	m_writeStructuralFeatureActionActivation_Operation_position_Value_EInt->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
	m_writeStructuralFeatureActionActivation_Operation_position_Value_EInt->setName("position");
	m_writeStructuralFeatureActionActivation_Operation_position_Value_EInt->setLowerBound(1);
	m_writeStructuralFeatureActionActivation_Operation_position_Value_EInt->setUpperBound(1);
	m_writeStructuralFeatureActionActivation_Operation_position_Value_EInt->setUnique(true);
	m_writeStructuralFeatureActionActivation_Operation_position_Value_EInt->setOrdered(false);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_writeStructuralFeatureActionActivation_Operation_position_Value_EInt);
		parameter->setName("value");
		parameter->setEType(getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_writeStructuralFeatureActionActivation_Operation_position_Value_EInt);
		parameter->setName("list");
		parameter->setEType(getValue_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::EcoreFactory::eInstance()->createEParameter_in_EOperation(m_writeStructuralFeatureActionActivation_Operation_position_Value_EInt);
		parameter->setName("startAt");
		parameter->setEType(ecore::EcorePackage::eInstance()->getEInt_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void FUMLPackageImpl::initializePackageEDataTypes()
{
	
}
