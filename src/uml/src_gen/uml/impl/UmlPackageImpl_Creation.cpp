#include "uml/impl/UmlPackageImpl.hpp"

// metametamodel factory
#include "ecore/EcoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAnnotation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EEnum.hpp"
#include "ecore/EEnumLiteral.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EStringToStringMapEntry.hpp"

//depending model packages
#include "ecore/EcorePackage.hpp"
#include "types/TypesPackage.hpp"

using namespace uml;

void UmlPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::EcoreFactory> factory = ecore::EcoreFactory::eInstance();

	createAbstractionContent(package, factory);
	createAcceptCallActionContent(package, factory);
	createAcceptEventActionContent(package, factory);
	createActionContent(package, factory);
	createActionExecutionSpecificationContent(package, factory);
	createActionInputPinContent(package, factory);
	createActivityContent(package, factory);
	createActivityContentContent(package, factory);
	createActivityEdgeContent(package, factory);
	createActivityFinalNodeContent(package, factory);
	createActivityGroupContent(package, factory);
	createActivityNodeContent(package, factory);
	createActivityParameterNodeContent(package, factory);
	createActivityPartitionContent(package, factory);
	createActorContent(package, factory);
	createAddStructuralFeatureValueActionContent(package, factory);
	createAddVariableValueActionContent(package, factory);
	createAnyReceiveEventContent(package, factory);
	createArgumentContent(package, factory);
	createArtifactContent(package, factory);
	createAssociationContent(package, factory);
	createAssociationClassContent(package, factory);
	createBehaviorContent(package, factory);
	createBehaviorExecutionSpecificationContent(package, factory);
	createBehavioralFeatureContent(package, factory);
	createBehavioredClassifierContent(package, factory);
	createBroadcastSignalActionContent(package, factory);
	createCallActionContent(package, factory);
	createCallBehaviorActionContent(package, factory);
	createCallEventContent(package, factory);
	createCallOperationActionContent(package, factory);
	createCentralBufferNodeContent(package, factory);
	createChangeEventContent(package, factory);
	createClassContent(package, factory);
	createClassifierContent(package, factory);
	createClassifierTemplateParameterContent(package, factory);
	createClauseContent(package, factory);
	createClearAssociationActionContent(package, factory);
	createClearStructuralFeatureActionContent(package, factory);
	createClearVariableActionContent(package, factory);
	createCollaborationContent(package, factory);
	createCollaborationUseContent(package, factory);
	createCombinedFragmentContent(package, factory);
	createCommentContent(package, factory);
	createCommunicationPathContent(package, factory);
	createComponentContent(package, factory);
	createComponentRealizationContent(package, factory);
	createConditionalNodeContent(package, factory);
	createConnectableElementContent(package, factory);
	createConnectableElementTemplateParameterContent(package, factory);
	createConnectionPointReferenceContent(package, factory);
	createConnectorContent(package, factory);
	createConnectorEndContent(package, factory);
	createConsiderIgnoreFragmentContent(package, factory);
	createConstraintContent(package, factory);
	createContinuationContent(package, factory);
	createControlFlowContent(package, factory);
	createControlNodeContent(package, factory);
	createCreateLinkActionContent(package, factory);
	createCreateLinkObjectActionContent(package, factory);
	createCreateObjectActionContent(package, factory);
	createDataStoreNodeContent(package, factory);
	createDataTypeContent(package, factory);
	createDecisionNodeContent(package, factory);
	createDependencyContent(package, factory);
	createDeployedArtifactContent(package, factory);
	createDeploymentContent(package, factory);
	createDeploymentSpecificationContent(package, factory);
	createDeploymentTargetContent(package, factory);
	createDestroyLinkActionContent(package, factory);
	createDestroyObjectActionContent(package, factory);
	createDestructionOccurrenceSpecificationContent(package, factory);
	createDeviceContent(package, factory);
	createDirectedRelationshipContent(package, factory);
	createDurationContent(package, factory);
	createDurationConstraintContent(package, factory);
	createDurationIntervalContent(package, factory);
	createDurationObservationContent(package, factory);
	createElementContent(package, factory);
	createElementImportContent(package, factory);
	createEncapsulatedClassifierContent(package, factory);
	createEnumerationContent(package, factory);
	createEnumerationLiteralContent(package, factory);
	createEventContent(package, factory);
	createExceptionHandlerContent(package, factory);
	createExecutableNodeContent(package, factory);
	createExecutionEnvironmentContent(package, factory);
	createExecutionOccurrenceSpecificationContent(package, factory);
	createExecutionSpecificationContent(package, factory);
	createExpansionNodeContent(package, factory);
	createExpansionRegionContent(package, factory);
	createExpressionContent(package, factory);
	createExtendContent(package, factory);
	createExtensionContent(package, factory);
	createExtensionEndContent(package, factory);
	createExtensionPointContent(package, factory);
	createFactoryContent(package, factory);
	createFeatureContent(package, factory);
	createFinalNodeContent(package, factory);
	createFinalStateContent(package, factory);
	createFlowFinalNodeContent(package, factory);
	createForkNodeContent(package, factory);
	createFunctionBehaviorContent(package, factory);
	createGateContent(package, factory);
	createGeneralOrderingContent(package, factory);
	createGeneralizationContent(package, factory);
	createGeneralizationSetContent(package, factory);
	createImageContent(package, factory);
	createIncludeContent(package, factory);
	createInformationFlowContent(package, factory);
	createInformationItemContent(package, factory);
	createInitialNodeContent(package, factory);
	createInputPinContent(package, factory);
	createInstanceSpecificationContent(package, factory);
	createInstanceValueContent(package, factory);
	createInteractionContent(package, factory);
	createInteractionConstraintContent(package, factory);
	createInteractionFragmentContent(package, factory);
	createInteractionOperandContent(package, factory);
	createInteractionUseContent(package, factory);
	createInterfaceContent(package, factory);
	createInterfaceRealizationContent(package, factory);
	createInterruptibleActivityRegionContent(package, factory);
	createIntervalContent(package, factory);
	createIntervalConstraintContent(package, factory);
	createInvocationActionContent(package, factory);
	createJoinNodeContent(package, factory);
	createLifelineContent(package, factory);
	createLinkActionContent(package, factory);
	createLinkEndCreationDataContent(package, factory);
	createLinkEndDataContent(package, factory);
	createLinkEndDestructionDataContent(package, factory);
	createLiteralBooleanContent(package, factory);
	createLiteralIntegerContent(package, factory);
	createLiteralNullContent(package, factory);
	createLiteralRealContent(package, factory);
	createLiteralSpecificationContent(package, factory);
	createLiteralStringContent(package, factory);
	createLiteralUnlimitedNaturalContent(package, factory);
	createLoopNodeContent(package, factory);
	createManifestationContent(package, factory);
	createMergeNodeContent(package, factory);
	createMessageContent(package, factory);
	createMessageEndContent(package, factory);
	createMessageEventContent(package, factory);
	createMessageOccurrenceSpecificationContent(package, factory);
	createModelContent(package, factory);
	createMultiplicityElementContent(package, factory);
	createNamedElementContent(package, factory);
	createNamespaceContent(package, factory);
	createNodeContent(package, factory);
	createObjectContent(package, factory);
	createObjectFlowContent(package, factory);
	createObjectNodeContent(package, factory);
	createObservationContent(package, factory);
	createOccurrenceSpecificationContent(package, factory);
	createOpaqueActionContent(package, factory);
	createOpaqueBehaviorContent(package, factory);
	createOpaqueExpressionContent(package, factory);
	createOperationContent(package, factory);
	createOperationTemplateParameterContent(package, factory);
	createOutputPinContent(package, factory);
	createPackageContent(package, factory);
	createPackageImportContent(package, factory);
	createPackageMergeContent(package, factory);
	createPackageableElementContent(package, factory);
	createParameterContent(package, factory);
	createParameterSetContent(package, factory);
	createParameterableElementContent(package, factory);
	createPartDecompositionContent(package, factory);
	createPinContent(package, factory);
	createPortContent(package, factory);
	createPrimitiveTypeContent(package, factory);
	createProfileContent(package, factory);
	createProfileApplicationContent(package, factory);
	createPropertyContent(package, factory);
	createProtocolConformanceContent(package, factory);
	createProtocolStateMachineContent(package, factory);
	createProtocolTransitionContent(package, factory);
	createPseudostateContent(package, factory);
	createQualifierValueContent(package, factory);
	createRaiseExceptionActionContent(package, factory);
	createReadExtentActionContent(package, factory);
	createReadIsClassifiedObjectActionContent(package, factory);
	createReadLinkActionContent(package, factory);
	createReadLinkObjectEndActionContent(package, factory);
	createReadLinkObjectEndQualifierActionContent(package, factory);
	createReadSelfActionContent(package, factory);
	createReadStructuralFeatureActionContent(package, factory);
	createReadVariableActionContent(package, factory);
	createRealizationContent(package, factory);
	createReceptionContent(package, factory);
	createReclassifyObjectActionContent(package, factory);
	createRedefinableElementContent(package, factory);
	createRedefinableTemplateSignatureContent(package, factory);
	createReduceActionContent(package, factory);
	createRegionContent(package, factory);
	createRelationshipContent(package, factory);
	createRemoveStructuralFeatureValueActionContent(package, factory);
	createRemoveVariableValueActionContent(package, factory);
	createReplyActionContent(package, factory);
	createSendObjectActionContent(package, factory);
	createSendSignalActionContent(package, factory);
	createSequenceNodeContent(package, factory);
	createSignalContent(package, factory);
	createSignalEventContent(package, factory);
	createSlotContent(package, factory);
	createStartClassifierBehaviorActionContent(package, factory);
	createStartObjectBehaviorActionContent(package, factory);
	createStateContent(package, factory);
	createStateInvariantContent(package, factory);
	createStateMachineContent(package, factory);
	createStereotypeContent(package, factory);
	createStringExpressionContent(package, factory);
	createStructuralFeatureContent(package, factory);
	createStructuralFeatureActionContent(package, factory);
	createStructuredActivityNodeContent(package, factory);
	createStructuredClassifierContent(package, factory);
	createSubstitutionContent(package, factory);
	createTemplateBindingContent(package, factory);
	createTemplateParameterContent(package, factory);
	createTemplateParameterSubstitutionContent(package, factory);
	createTemplateSignatureContent(package, factory);
	createTemplateableElementContent(package, factory);
	createTestIdentityActionContent(package, factory);
	createTimeConstraintContent(package, factory);
	createTimeEventContent(package, factory);
	createTimeExpressionContent(package, factory);
	createTimeIntervalContent(package, factory);
	createTimeObservationContent(package, factory);
	createTransitionContent(package, factory);
	createTriggerContent(package, factory);
	createTypeContent(package, factory);
	createTypedElementContent(package, factory);
	createUnmarshallActionContent(package, factory);
	createUsageContent(package, factory);
	createUseCaseContent(package, factory);
	createValuePinContent(package, factory);
	createValueSpecificationContent(package, factory);
	createValueSpecificationActionContent(package, factory);
	createVariableContent(package, factory);
	createVariableActionContent(package, factory);
	createVertexContent(package, factory);
	createWriteLinkActionContent(package, factory);
	createWriteStructuralFeatureActionContent(package, factory);
	createWriteVariableActionContent(package, factory);

	createPackageEDataTypes(package, factory);
}

void UmlPackageImpl::createAbstractionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_abstraction_Class = factory->createEClass_in_EPackage(package, ABSTRACTION_CLASS);
	
	m_abstraction_Attribute_mapping = factory->createEReference_in_EContainingClass(m_abstraction_Class, ABSTRACTION_ATTRIBUTE_MAPPING);
	
	
}

void UmlPackageImpl::createAcceptCallActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_acceptCallAction_Class = factory->createEClass_in_EPackage(package, ACCEPTCALLACTION_CLASS);
	
	m_acceptCallAction_Attribute_returnInformation = factory->createEReference_in_EContainingClass(m_acceptCallAction_Class, ACCEPTCALLACTION_ATTRIBUTE_RETURNINFORMATION);
	
	m_acceptCallAction_Operation_result_pins_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_acceptCallAction_Class, ACCEPTCALLACTION_OPERATION_RESULT_PINS_EDIAGNOSTICCHAIN_EMAP);
	m_acceptCallAction_Operation_trigger_call_event_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_acceptCallAction_Class, ACCEPTCALLACTION_OPERATION_TRIGGER_CALL_EVENT_EDIAGNOSTICCHAIN_EMAP);
	m_acceptCallAction_Operation_unmarshall_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_acceptCallAction_Class, ACCEPTCALLACTION_OPERATION_UNMARSHALL_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createAcceptEventActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_acceptEventAction_Class = factory->createEClass_in_EPackage(package, ACCEPTEVENTACTION_CLASS);
	m_acceptEventAction_Attribute_isUnmarshall = factory->createEAttribute_in_EContainingClass(m_acceptEventAction_Class, ACCEPTEVENTACTION_ATTRIBUTE_ISUNMARSHALL);
	
	m_acceptEventAction_Attribute_result = factory->createEReference_in_EContainingClass(m_acceptEventAction_Class, ACCEPTEVENTACTION_ATTRIBUTE_RESULT);
	m_acceptEventAction_Attribute_trigger = factory->createEReference_in_EContainingClass(m_acceptEventAction_Class, ACCEPTEVENTACTION_ATTRIBUTE_TRIGGER);
	
	m_acceptEventAction_Operation_conforming_type_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_acceptEventAction_Class, ACCEPTEVENTACTION_OPERATION_CONFORMING_TYPE_EDIAGNOSTICCHAIN_EMAP);
	m_acceptEventAction_Operation_no_input_pins_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_acceptEventAction_Class, ACCEPTEVENTACTION_OPERATION_NO_INPUT_PINS_EDIAGNOSTICCHAIN_EMAP);
	m_acceptEventAction_Operation_no_output_pins_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_acceptEventAction_Class, ACCEPTEVENTACTION_OPERATION_NO_OUTPUT_PINS_EDIAGNOSTICCHAIN_EMAP);
	m_acceptEventAction_Operation_one_output_pin_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_acceptEventAction_Class, ACCEPTEVENTACTION_OPERATION_ONE_OUTPUT_PIN_EDIAGNOSTICCHAIN_EMAP);
	m_acceptEventAction_Operation_unmarshall_signal_events_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_acceptEventAction_Class, ACCEPTEVENTACTION_OPERATION_UNMARSHALL_SIGNAL_EVENTS_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_action_Class = factory->createEClass_in_EPackage(package, ACTION_CLASS);
	m_action_Attribute_isLocallyReentrant = factory->createEAttribute_in_EContainingClass(m_action_Class, ACTION_ATTRIBUTE_ISLOCALLYREENTRANT);
	
	m_action_Attribute_context = factory->createEReference_in_EContainingClass(m_action_Class, ACTION_ATTRIBUTE_CONTEXT);
	m_action_Attribute_input = factory->createEReference_in_EContainingClass(m_action_Class, ACTION_ATTRIBUTE_INPUT);
	m_action_Attribute_localPostcondition = factory->createEReference_in_EContainingClass(m_action_Class, ACTION_ATTRIBUTE_LOCALPOSTCONDITION);
	m_action_Attribute_localPrecondition = factory->createEReference_in_EContainingClass(m_action_Class, ACTION_ATTRIBUTE_LOCALPRECONDITION);
	m_action_Attribute_output = factory->createEReference_in_EContainingClass(m_action_Class, ACTION_ATTRIBUTE_OUTPUT);
	
	m_action_Operation_allActions = factory->createEOperation_in_EContainingClass(m_action_Class, ACTION_OPERATION_ALLACTIONS);
	m_action_Operation_allOwnedNodes = factory->createEOperation_in_EContainingClass(m_action_Class, ACTION_OPERATION_ALLOWNEDNODES);
	m_action_Operation_containingBehavior = factory->createEOperation_in_EContainingClass(m_action_Class, ACTION_OPERATION_CONTAININGBEHAVIOR);
	m_action_Operation_getContext = factory->createEOperation_in_EContainingClass(m_action_Class, ACTION_OPERATION_GETCONTEXT);
	
}

void UmlPackageImpl::createActionExecutionSpecificationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_actionExecutionSpecification_Class = factory->createEClass_in_EPackage(package, ACTIONEXECUTIONSPECIFICATION_CLASS);
	
	m_actionExecutionSpecification_Attribute_action = factory->createEReference_in_EContainingClass(m_actionExecutionSpecification_Class, ACTIONEXECUTIONSPECIFICATION_ATTRIBUTE_ACTION);
	
	m_actionExecutionSpecification_Operation_action_referenced_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_actionExecutionSpecification_Class, ACTIONEXECUTIONSPECIFICATION_OPERATION_ACTION_REFERENCED_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createActionInputPinContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_actionInputPin_Class = factory->createEClass_in_EPackage(package, ACTIONINPUTPIN_CLASS);
	
	m_actionInputPin_Attribute_fromAction = factory->createEReference_in_EContainingClass(m_actionInputPin_Class, ACTIONINPUTPIN_ATTRIBUTE_FROMACTION);
	
	m_actionInputPin_Operation_input_pin_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_actionInputPin_Class, ACTIONINPUTPIN_OPERATION_INPUT_PIN_EDIAGNOSTICCHAIN_EMAP);
	m_actionInputPin_Operation_no_control_or_object_flow_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_actionInputPin_Class, ACTIONINPUTPIN_OPERATION_NO_CONTROL_OR_OBJECT_FLOW_EDIAGNOSTICCHAIN_EMAP);
	m_actionInputPin_Operation_one_output_pin_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_actionInputPin_Class, ACTIONINPUTPIN_OPERATION_ONE_OUTPUT_PIN_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createActivityContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_activity_Class = factory->createEClass_in_EPackage(package, ACTIVITY_CLASS);
	m_activity_Attribute_isReadOnly = factory->createEAttribute_in_EContainingClass(m_activity_Class, ACTIVITY_ATTRIBUTE_ISREADONLY);
	m_activity_Attribute_isSingleExecution = factory->createEAttribute_in_EContainingClass(m_activity_Class, ACTIVITY_ATTRIBUTE_ISSINGLEEXECUTION);
	
	m_activity_Attribute_edge = factory->createEReference_in_EContainingClass(m_activity_Class, ACTIVITY_ATTRIBUTE_EDGE);
	m_activity_Attribute_group = factory->createEReference_in_EContainingClass(m_activity_Class, ACTIVITY_ATTRIBUTE_GROUP);
	m_activity_Attribute_node = factory->createEReference_in_EContainingClass(m_activity_Class, ACTIVITY_ATTRIBUTE_NODE);
	m_activity_Attribute_ownedGroup = factory->createEReference_in_EContainingClass(m_activity_Class, ACTIVITY_ATTRIBUTE_OWNEDGROUP);
	m_activity_Attribute_ownedNode = factory->createEReference_in_EContainingClass(m_activity_Class, ACTIVITY_ATTRIBUTE_OWNEDNODE);
	m_activity_Attribute_partition = factory->createEReference_in_EContainingClass(m_activity_Class, ACTIVITY_ATTRIBUTE_PARTITION);
	m_activity_Attribute_structuredNode = factory->createEReference_in_EContainingClass(m_activity_Class, ACTIVITY_ATTRIBUTE_STRUCTUREDNODE);
	m_activity_Attribute_variable = factory->createEReference_in_EContainingClass(m_activity_Class, ACTIVITY_ATTRIBUTE_VARIABLE);
	
	m_activity_Operation_maximum_one_parameter_node_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_activity_Class, ACTIVITY_OPERATION_MAXIMUM_ONE_PARAMETER_NODE_EDIAGNOSTICCHAIN_EMAP);
	m_activity_Operation_maximum_two_parameter_nodes_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_activity_Class, ACTIVITY_OPERATION_MAXIMUM_TWO_PARAMETER_NODES_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createActivityContentContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_activityContent_Class = factory->createEClass_in_EPackage(package, ACTIVITYCONTENT_CLASS);
	
	
	m_activityContent_Operation_containingActivity = factory->createEOperation_in_EContainingClass(m_activityContent_Class, ACTIVITYCONTENT_OPERATION_CONTAININGACTIVITY);
	
}

void UmlPackageImpl::createActivityEdgeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_activityEdge_Class = factory->createEClass_in_EPackage(package, ACTIVITYEDGE_CLASS);
	
	m_activityEdge_Attribute_activity = factory->createEReference_in_EContainingClass(m_activityEdge_Class, ACTIVITYEDGE_ATTRIBUTE_ACTIVITY);
	m_activityEdge_Attribute_guard = factory->createEReference_in_EContainingClass(m_activityEdge_Class, ACTIVITYEDGE_ATTRIBUTE_GUARD);
	m_activityEdge_Attribute_inGroup = factory->createEReference_in_EContainingClass(m_activityEdge_Class, ACTIVITYEDGE_ATTRIBUTE_INGROUP);
	m_activityEdge_Attribute_inPartition = factory->createEReference_in_EContainingClass(m_activityEdge_Class, ACTIVITYEDGE_ATTRIBUTE_INPARTITION);
	m_activityEdge_Attribute_inStructuredNode = factory->createEReference_in_EContainingClass(m_activityEdge_Class, ACTIVITYEDGE_ATTRIBUTE_INSTRUCTUREDNODE);
	m_activityEdge_Attribute_interrupts = factory->createEReference_in_EContainingClass(m_activityEdge_Class, ACTIVITYEDGE_ATTRIBUTE_INTERRUPTS);
	m_activityEdge_Attribute_redefinedEdge = factory->createEReference_in_EContainingClass(m_activityEdge_Class, ACTIVITYEDGE_ATTRIBUTE_REDEFINEDEDGE);
	m_activityEdge_Attribute_source = factory->createEReference_in_EContainingClass(m_activityEdge_Class, ACTIVITYEDGE_ATTRIBUTE_SOURCE);
	m_activityEdge_Attribute_target = factory->createEReference_in_EContainingClass(m_activityEdge_Class, ACTIVITYEDGE_ATTRIBUTE_TARGET);
	m_activityEdge_Attribute_weight = factory->createEReference_in_EContainingClass(m_activityEdge_Class, ACTIVITYEDGE_ATTRIBUTE_WEIGHT);
	
	m_activityEdge_Operation_source_and_target_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_activityEdge_Class, ACTIVITYEDGE_OPERATION_SOURCE_AND_TARGET_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createActivityFinalNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_activityFinalNode_Class = factory->createEClass_in_EPackage(package, ACTIVITYFINALNODE_CLASS);
	
	
	
}

void UmlPackageImpl::createActivityGroupContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_activityGroup_Class = factory->createEClass_in_EPackage(package, ACTIVITYGROUP_CLASS);
	
	m_activityGroup_Attribute_containedEdge = factory->createEReference_in_EContainingClass(m_activityGroup_Class, ACTIVITYGROUP_ATTRIBUTE_CONTAINEDEDGE);
	m_activityGroup_Attribute_containedNode = factory->createEReference_in_EContainingClass(m_activityGroup_Class, ACTIVITYGROUP_ATTRIBUTE_CONTAINEDNODE);
	m_activityGroup_Attribute_inActivity = factory->createEReference_in_EContainingClass(m_activityGroup_Class, ACTIVITYGROUP_ATTRIBUTE_INACTIVITY);
	m_activityGroup_Attribute_subgroup = factory->createEReference_in_EContainingClass(m_activityGroup_Class, ACTIVITYGROUP_ATTRIBUTE_SUBGROUP);
	m_activityGroup_Attribute_superGroup = factory->createEReference_in_EContainingClass(m_activityGroup_Class, ACTIVITYGROUP_ATTRIBUTE_SUPERGROUP);
	
	m_activityGroup_Operation_nodes_and_edges_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_activityGroup_Class, ACTIVITYGROUP_OPERATION_NODES_AND_EDGES_EDIAGNOSTICCHAIN_EMAP);
	m_activityGroup_Operation_not_contained_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_activityGroup_Class, ACTIVITYGROUP_OPERATION_NOT_CONTAINED_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createActivityNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_activityNode_Class = factory->createEClass_in_EPackage(package, ACTIVITYNODE_CLASS);
	
	m_activityNode_Attribute_activity = factory->createEReference_in_EContainingClass(m_activityNode_Class, ACTIVITYNODE_ATTRIBUTE_ACTIVITY);
	m_activityNode_Attribute_inGroup = factory->createEReference_in_EContainingClass(m_activityNode_Class, ACTIVITYNODE_ATTRIBUTE_INGROUP);
	m_activityNode_Attribute_inInterruptibleRegion = factory->createEReference_in_EContainingClass(m_activityNode_Class, ACTIVITYNODE_ATTRIBUTE_ININTERRUPTIBLEREGION);
	m_activityNode_Attribute_inPartition = factory->createEReference_in_EContainingClass(m_activityNode_Class, ACTIVITYNODE_ATTRIBUTE_INPARTITION);
	m_activityNode_Attribute_inStructuredNode = factory->createEReference_in_EContainingClass(m_activityNode_Class, ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE);
	m_activityNode_Attribute_incoming = factory->createEReference_in_EContainingClass(m_activityNode_Class, ACTIVITYNODE_ATTRIBUTE_INCOMING);
	m_activityNode_Attribute_outgoing = factory->createEReference_in_EContainingClass(m_activityNode_Class, ACTIVITYNODE_ATTRIBUTE_OUTGOING);
	m_activityNode_Attribute_redefinedNode = factory->createEReference_in_EContainingClass(m_activityNode_Class, ACTIVITYNODE_ATTRIBUTE_REDEFINEDNODE);
	
	
}

void UmlPackageImpl::createActivityParameterNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_activityParameterNode_Class = factory->createEClass_in_EPackage(package, ACTIVITYPARAMETERNODE_CLASS);
	
	m_activityParameterNode_Attribute_parameter = factory->createEReference_in_EContainingClass(m_activityParameterNode_Class, ACTIVITYPARAMETERNODE_ATTRIBUTE_PARAMETER);
	
	m_activityParameterNode_Operation_has_parameters_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_activityParameterNode_Class, ACTIVITYPARAMETERNODE_OPERATION_HAS_PARAMETERS_EDIAGNOSTICCHAIN_EMAP);
	m_activityParameterNode_Operation_no_edges_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_activityParameterNode_Class, ACTIVITYPARAMETERNODE_OPERATION_NO_EDGES_EDIAGNOSTICCHAIN_EMAP);
	m_activityParameterNode_Operation_no_incoming_edges_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_activityParameterNode_Class, ACTIVITYPARAMETERNODE_OPERATION_NO_INCOMING_EDGES_EDIAGNOSTICCHAIN_EMAP);
	m_activityParameterNode_Operation_no_outgoing_edges_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_activityParameterNode_Class, ACTIVITYPARAMETERNODE_OPERATION_NO_OUTGOING_EDGES_EDIAGNOSTICCHAIN_EMAP);
	m_activityParameterNode_Operation_same_type_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_activityParameterNode_Class, ACTIVITYPARAMETERNODE_OPERATION_SAME_TYPE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createActivityPartitionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_activityPartition_Class = factory->createEClass_in_EPackage(package, ACTIVITYPARTITION_CLASS);
	m_activityPartition_Attribute_isDimension = factory->createEAttribute_in_EContainingClass(m_activityPartition_Class, ACTIVITYPARTITION_ATTRIBUTE_ISDIMENSION);
	m_activityPartition_Attribute_isExternal = factory->createEAttribute_in_EContainingClass(m_activityPartition_Class, ACTIVITYPARTITION_ATTRIBUTE_ISEXTERNAL);
	
	m_activityPartition_Attribute_edge = factory->createEReference_in_EContainingClass(m_activityPartition_Class, ACTIVITYPARTITION_ATTRIBUTE_EDGE);
	m_activityPartition_Attribute_node = factory->createEReference_in_EContainingClass(m_activityPartition_Class, ACTIVITYPARTITION_ATTRIBUTE_NODE);
	m_activityPartition_Attribute_represents = factory->createEReference_in_EContainingClass(m_activityPartition_Class, ACTIVITYPARTITION_ATTRIBUTE_REPRESENTS);
	m_activityPartition_Attribute_subpartition = factory->createEReference_in_EContainingClass(m_activityPartition_Class, ACTIVITYPARTITION_ATTRIBUTE_SUBPARTITION);
	m_activityPartition_Attribute_superPartition = factory->createEReference_in_EContainingClass(m_activityPartition_Class, ACTIVITYPARTITION_ATTRIBUTE_SUPERPARTITION);
	
	m_activityPartition_Operation_dimension_not_contained_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_activityPartition_Class, ACTIVITYPARTITION_OPERATION_DIMENSION_NOT_CONTAINED_EDIAGNOSTICCHAIN_EMAP);
	m_activityPartition_Operation_represents_classifier_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_activityPartition_Class, ACTIVITYPARTITION_OPERATION_REPRESENTS_CLASSIFIER_EDIAGNOSTICCHAIN_EMAP);
	m_activityPartition_Operation_represents_property_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_activityPartition_Class, ACTIVITYPARTITION_OPERATION_REPRESENTS_PROPERTY_EDIAGNOSTICCHAIN_EMAP);
	m_activityPartition_Operation_represents_property_and_is_contained_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_activityPartition_Class, ACTIVITYPARTITION_OPERATION_REPRESENTS_PROPERTY_AND_IS_CONTAINED_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createActorContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_actor_Class = factory->createEClass_in_EPackage(package, ACTOR_CLASS);
	
	
	m_actor_Operation_associations_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_actor_Class, ACTOR_OPERATION_ASSOCIATIONS_EDIAGNOSTICCHAIN_EMAP);
	m_actor_Operation_must_have_name_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_actor_Class, ACTOR_OPERATION_MUST_HAVE_NAME_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createAddStructuralFeatureValueActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_addStructuralFeatureValueAction_Class = factory->createEClass_in_EPackage(package, ADDSTRUCTURALFEATUREVALUEACTION_CLASS);
	m_addStructuralFeatureValueAction_Attribute_isReplaceAll = factory->createEAttribute_in_EContainingClass(m_addStructuralFeatureValueAction_Class, ADDSTRUCTURALFEATUREVALUEACTION_ATTRIBUTE_ISREPLACEALL);
	
	m_addStructuralFeatureValueAction_Attribute_insertAt = factory->createEReference_in_EContainingClass(m_addStructuralFeatureValueAction_Class, ADDSTRUCTURALFEATUREVALUEACTION_ATTRIBUTE_INSERTAT);
	
	m_addStructuralFeatureValueAction_Operation_insertAt_pin_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_addStructuralFeatureValueAction_Class, ADDSTRUCTURALFEATUREVALUEACTION_OPERATION_INSERTAT_PIN_EDIAGNOSTICCHAIN_EMAP);
	m_addStructuralFeatureValueAction_Operation_required_value_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_addStructuralFeatureValueAction_Class, ADDSTRUCTURALFEATUREVALUEACTION_OPERATION_REQUIRED_VALUE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createAddVariableValueActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_addVariableValueAction_Class = factory->createEClass_in_EPackage(package, ADDVARIABLEVALUEACTION_CLASS);
	m_addVariableValueAction_Attribute_isReplaceAll = factory->createEAttribute_in_EContainingClass(m_addVariableValueAction_Class, ADDVARIABLEVALUEACTION_ATTRIBUTE_ISREPLACEALL);
	
	m_addVariableValueAction_Attribute_insertAt = factory->createEReference_in_EContainingClass(m_addVariableValueAction_Class, ADDVARIABLEVALUEACTION_ATTRIBUTE_INSERTAT);
	
	m_addVariableValueAction_Operation_insertAt_pin_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_addVariableValueAction_Class, ADDVARIABLEVALUEACTION_OPERATION_INSERTAT_PIN_EDIAGNOSTICCHAIN_EMAP);
	m_addVariableValueAction_Operation_required_value_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_addVariableValueAction_Class, ADDVARIABLEVALUEACTION_OPERATION_REQUIRED_VALUE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createAnyReceiveEventContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_anyReceiveEvent_Class = factory->createEClass_in_EPackage(package, ANYRECEIVEEVENT_CLASS);
	
	
	
}

void UmlPackageImpl::createArgumentContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_argument_Class = factory->createEClass_in_EPackage(package, ARGUMENT_CLASS);
	m_argument_Attribute_name = factory->createEAttribute_in_EContainingClass(m_argument_Class, ARGUMENT_ATTRIBUTE_NAME);
	
	m_argument_Attribute_value = factory->createEReference_in_EContainingClass(m_argument_Class, ARGUMENT_ATTRIBUTE_VALUE);
	
	
}

void UmlPackageImpl::createArtifactContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_artifact_Class = factory->createEClass_in_EPackage(package, ARTIFACT_CLASS);
	m_artifact_Attribute_fileName = factory->createEAttribute_in_EContainingClass(m_artifact_Class, ARTIFACT_ATTRIBUTE_FILENAME);
	
	m_artifact_Attribute_manifestation = factory->createEReference_in_EContainingClass(m_artifact_Class, ARTIFACT_ATTRIBUTE_MANIFESTATION);
	m_artifact_Attribute_nestedArtifact = factory->createEReference_in_EContainingClass(m_artifact_Class, ARTIFACT_ATTRIBUTE_NESTEDARTIFACT);
	m_artifact_Attribute_ownedAttribute = factory->createEReference_in_EContainingClass(m_artifact_Class, ARTIFACT_ATTRIBUTE_OWNEDATTRIBUTE);
	m_artifact_Attribute_ownedOperation = factory->createEReference_in_EContainingClass(m_artifact_Class, ARTIFACT_ATTRIBUTE_OWNEDOPERATION);
	
	m_artifact_Operation_createOwnedAttribute_String_UnlimitedNatural = factory->createEOperation_in_EContainingClass(m_artifact_Class, ARTIFACT_OPERATION_CREATEOWNEDATTRIBUTE_STRING_UNLIMITEDNATURAL);
	m_artifact_Operation_createOwnedOperation_String_Type = factory->createEOperation_in_EContainingClass(m_artifact_Class, ARTIFACT_OPERATION_CREATEOWNEDOPERATION_STRING_TYPE);
	
}

void UmlPackageImpl::createAssociationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_association_Class = factory->createEClass_in_EPackage(package, ASSOCIATION_CLASS);
	m_association_Attribute_isDerived = factory->createEAttribute_in_EContainingClass(m_association_Class, ASSOCIATION_ATTRIBUTE_ISDERIVED);
	
	m_association_Attribute_endType = factory->createEReference_in_EContainingClass(m_association_Class, ASSOCIATION_ATTRIBUTE_ENDTYPE);
	m_association_Attribute_memberEnd = factory->createEReference_in_EContainingClass(m_association_Class, ASSOCIATION_ATTRIBUTE_MEMBEREND);
	m_association_Attribute_navigableOwnedEnd = factory->createEReference_in_EContainingClass(m_association_Class, ASSOCIATION_ATTRIBUTE_NAVIGABLEOWNEDEND);
	m_association_Attribute_ownedEnd = factory->createEReference_in_EContainingClass(m_association_Class, ASSOCIATION_ATTRIBUTE_OWNEDEND);
	
	m_association_Operation_association_ends_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_association_Class, ASSOCIATION_OPERATION_ASSOCIATION_ENDS_EDIAGNOSTICCHAIN_EMAP);
	m_association_Operation_binary_associations_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_association_Class, ASSOCIATION_OPERATION_BINARY_ASSOCIATIONS_EDIAGNOSTICCHAIN_EMAP);
	m_association_Operation_ends_must_be_typed_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_association_Class, ASSOCIATION_OPERATION_ENDS_MUST_BE_TYPED_EDIAGNOSTICCHAIN_EMAP);
	m_association_Operation_getEndTypes = factory->createEOperation_in_EContainingClass(m_association_Class, ASSOCIATION_OPERATION_GETENDTYPES);
	m_association_Operation_isBinary = factory->createEOperation_in_EContainingClass(m_association_Class, ASSOCIATION_OPERATION_ISBINARY);
	m_association_Operation_specialized_end_number_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_association_Class, ASSOCIATION_OPERATION_SPECIALIZED_END_NUMBER_EDIAGNOSTICCHAIN_EMAP);
	m_association_Operation_specialized_end_types_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_association_Class, ASSOCIATION_OPERATION_SPECIALIZED_END_TYPES_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createAssociationClassContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_associationClass_Class = factory->createEClass_in_EPackage(package, ASSOCIATIONCLASS_CLASS);
	
	
	m_associationClass_Operation_cannot_be_defined_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_associationClass_Class, ASSOCIATIONCLASS_OPERATION_CANNOT_BE_DEFINED_EDIAGNOSTICCHAIN_EMAP);
	m_associationClass_Operation_disjoint_attributes_ends_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_associationClass_Class, ASSOCIATIONCLASS_OPERATION_DISJOINT_ATTRIBUTES_ENDS_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createBehaviorContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_behavior_Class = factory->createEClass_in_EPackage(package, BEHAVIOR_CLASS);
	m_behavior_Attribute_isReentrant = factory->createEAttribute_in_EContainingClass(m_behavior_Class, BEHAVIOR_ATTRIBUTE_ISREENTRANT);
	
	m_behavior_Attribute_behavioredClassifier = factory->createEReference_in_EContainingClass(m_behavior_Class, BEHAVIOR_ATTRIBUTE_BEHAVIOREDCLASSIFIER);
	m_behavior_Attribute_context = factory->createEReference_in_EContainingClass(m_behavior_Class, BEHAVIOR_ATTRIBUTE_CONTEXT);
	m_behavior_Attribute_ownedParameter = factory->createEReference_in_EContainingClass(m_behavior_Class, BEHAVIOR_ATTRIBUTE_OWNEDPARAMETER);
	m_behavior_Attribute_ownedParameterSet = factory->createEReference_in_EContainingClass(m_behavior_Class, BEHAVIOR_ATTRIBUTE_OWNEDPARAMETERSET);
	m_behavior_Attribute_postcondition = factory->createEReference_in_EContainingClass(m_behavior_Class, BEHAVIOR_ATTRIBUTE_POSTCONDITION);
	m_behavior_Attribute_precondition = factory->createEReference_in_EContainingClass(m_behavior_Class, BEHAVIOR_ATTRIBUTE_PRECONDITION);
	m_behavior_Attribute_redefinedBehavior = factory->createEReference_in_EContainingClass(m_behavior_Class, BEHAVIOR_ATTRIBUTE_REDEFINEDBEHAVIOR);
	m_behavior_Attribute_specification = factory->createEReference_in_EContainingClass(m_behavior_Class, BEHAVIOR_ATTRIBUTE_SPECIFICATION);
	
	m_behavior_Operation_behavioredClassifier_Element = factory->createEOperation_in_EContainingClass(m_behavior_Class, BEHAVIOR_OPERATION_BEHAVIOREDCLASSIFIER_ELEMENT);
	m_behavior_Operation_feature_of_context_classifier_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_behavior_Class, BEHAVIOR_OPERATION_FEATURE_OF_CONTEXT_CLASSIFIER_EDIAGNOSTICCHAIN_EMAP);
	m_behavior_Operation_getContext = factory->createEOperation_in_EContainingClass(m_behavior_Class, BEHAVIOR_OPERATION_GETCONTEXT);
	m_behavior_Operation_inputParameters = factory->createEOperation_in_EContainingClass(m_behavior_Class, BEHAVIOR_OPERATION_INPUTPARAMETERS);
	m_behavior_Operation_most_one_behavior_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_behavior_Class, BEHAVIOR_OPERATION_MOST_ONE_BEHAVIOR_EDIAGNOSTICCHAIN_EMAP);
	m_behavior_Operation_outputParameters = factory->createEOperation_in_EContainingClass(m_behavior_Class, BEHAVIOR_OPERATION_OUTPUTPARAMETERS);
	m_behavior_Operation_parameters_match_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_behavior_Class, BEHAVIOR_OPERATION_PARAMETERS_MATCH_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createBehaviorExecutionSpecificationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_behaviorExecutionSpecification_Class = factory->createEClass_in_EPackage(package, BEHAVIOREXECUTIONSPECIFICATION_CLASS);
	
	m_behaviorExecutionSpecification_Attribute_behavior = factory->createEReference_in_EContainingClass(m_behaviorExecutionSpecification_Class, BEHAVIOREXECUTIONSPECIFICATION_ATTRIBUTE_BEHAVIOR);
	
	
}

void UmlPackageImpl::createBehavioralFeatureContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_behavioralFeature_Class = factory->createEClass_in_EPackage(package, BEHAVIORALFEATURE_CLASS);
	m_behavioralFeature_Attribute_concurrency = factory->createEAttribute_in_EContainingClass(m_behavioralFeature_Class, BEHAVIORALFEATURE_ATTRIBUTE_CONCURRENCY);
	m_behavioralFeature_Attribute_isAbstract = factory->createEAttribute_in_EContainingClass(m_behavioralFeature_Class, BEHAVIORALFEATURE_ATTRIBUTE_ISABSTRACT);
	
	m_behavioralFeature_Attribute_method = factory->createEReference_in_EContainingClass(m_behavioralFeature_Class, BEHAVIORALFEATURE_ATTRIBUTE_METHOD);
	m_behavioralFeature_Attribute_ownedParameter = factory->createEReference_in_EContainingClass(m_behavioralFeature_Class, BEHAVIORALFEATURE_ATTRIBUTE_OWNEDPARAMETER);
	m_behavioralFeature_Attribute_ownedParameterSet = factory->createEReference_in_EContainingClass(m_behavioralFeature_Class, BEHAVIORALFEATURE_ATTRIBUTE_OWNEDPARAMETERSET);
	m_behavioralFeature_Attribute_raisedException = factory->createEReference_in_EContainingClass(m_behavioralFeature_Class, BEHAVIORALFEATURE_ATTRIBUTE_RAISEDEXCEPTION);
	
	m_behavioralFeature_Operation_abstract_no_method_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_behavioralFeature_Class, BEHAVIORALFEATURE_OPERATION_ABSTRACT_NO_METHOD_EDIAGNOSTICCHAIN_EMAP);
	m_behavioralFeature_Operation_createReturnResult_String_Type = factory->createEOperation_in_EContainingClass(m_behavioralFeature_Class, BEHAVIORALFEATURE_OPERATION_CREATERETURNRESULT_STRING_TYPE);
	m_behavioralFeature_Operation_inputParameters = factory->createEOperation_in_EContainingClass(m_behavioralFeature_Class, BEHAVIORALFEATURE_OPERATION_INPUTPARAMETERS);
	m_behavioralFeature_Operation_outputParameters = factory->createEOperation_in_EContainingClass(m_behavioralFeature_Class, BEHAVIORALFEATURE_OPERATION_OUTPUTPARAMETERS);
	
}

void UmlPackageImpl::createBehavioredClassifierContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_behavioredClassifier_Class = factory->createEClass_in_EPackage(package, BEHAVIOREDCLASSIFIER_CLASS);
	
	m_behavioredClassifier_Attribute_classifierBehavior = factory->createEReference_in_EContainingClass(m_behavioredClassifier_Class, BEHAVIOREDCLASSIFIER_ATTRIBUTE_CLASSIFIERBEHAVIOR);
	m_behavioredClassifier_Attribute_interfaceRealization = factory->createEReference_in_EContainingClass(m_behavioredClassifier_Class, BEHAVIOREDCLASSIFIER_ATTRIBUTE_INTERFACEREALIZATION);
	m_behavioredClassifier_Attribute_ownedBehavior = factory->createEReference_in_EContainingClass(m_behavioredClassifier_Class, BEHAVIOREDCLASSIFIER_ATTRIBUTE_OWNEDBEHAVIOR);
	
	m_behavioredClassifier_Operation_class_behavior_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_behavioredClassifier_Class, BEHAVIOREDCLASSIFIER_OPERATION_CLASS_BEHAVIOR_EDIAGNOSTICCHAIN_EMAP);
	m_behavioredClassifier_Operation_getAllImplementedInterfaces = factory->createEOperation_in_EContainingClass(m_behavioredClassifier_Class, BEHAVIOREDCLASSIFIER_OPERATION_GETALLIMPLEMENTEDINTERFACES);
	m_behavioredClassifier_Operation_getImplementedInterfaces = factory->createEOperation_in_EContainingClass(m_behavioredClassifier_Class, BEHAVIOREDCLASSIFIER_OPERATION_GETIMPLEMENTEDINTERFACES);
	
}

void UmlPackageImpl::createBroadcastSignalActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_broadcastSignalAction_Class = factory->createEClass_in_EPackage(package, BROADCASTSIGNALACTION_CLASS);
	
	m_broadcastSignalAction_Attribute_signal = factory->createEReference_in_EContainingClass(m_broadcastSignalAction_Class, BROADCASTSIGNALACTION_ATTRIBUTE_SIGNAL);
	
	m_broadcastSignalAction_Operation_no_onport_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_broadcastSignalAction_Class, BROADCASTSIGNALACTION_OPERATION_NO_ONPORT_EDIAGNOSTICCHAIN_EMAP);
	m_broadcastSignalAction_Operation_number_of_arguments_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_broadcastSignalAction_Class, BROADCASTSIGNALACTION_OPERATION_NUMBER_OF_ARGUMENTS_EDIAGNOSTICCHAIN_EMAP);
	m_broadcastSignalAction_Operation_type_ordering_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_broadcastSignalAction_Class, BROADCASTSIGNALACTION_OPERATION_TYPE_ORDERING_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createCallActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_callAction_Class = factory->createEClass_in_EPackage(package, CALLACTION_CLASS);
	m_callAction_Attribute_isSynchronous = factory->createEAttribute_in_EContainingClass(m_callAction_Class, CALLACTION_ATTRIBUTE_ISSYNCHRONOUS);
	
	m_callAction_Attribute_result = factory->createEReference_in_EContainingClass(m_callAction_Class, CALLACTION_ATTRIBUTE_RESULT);
	
	m_callAction_Operation_argument_pins_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_callAction_Class, CALLACTION_OPERATION_ARGUMENT_PINS_EDIAGNOSTICCHAIN_EMAP);
	m_callAction_Operation_inputParameters = factory->createEOperation_in_EContainingClass(m_callAction_Class, CALLACTION_OPERATION_INPUTPARAMETERS);
	m_callAction_Operation_outputParameters = factory->createEOperation_in_EContainingClass(m_callAction_Class, CALLACTION_OPERATION_OUTPUTPARAMETERS);
	m_callAction_Operation_result_pins_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_callAction_Class, CALLACTION_OPERATION_RESULT_PINS_EDIAGNOSTICCHAIN_EMAP);
	m_callAction_Operation_synchronous_call_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_callAction_Class, CALLACTION_OPERATION_SYNCHRONOUS_CALL_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createCallBehaviorActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_callBehaviorAction_Class = factory->createEClass_in_EPackage(package, CALLBEHAVIORACTION_CLASS);
	
	m_callBehaviorAction_Attribute_behavior = factory->createEReference_in_EContainingClass(m_callBehaviorAction_Class, CALLBEHAVIORACTION_ATTRIBUTE_BEHAVIOR);
	
	m_callBehaviorAction_Operation_no_onport_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_callBehaviorAction_Class, CALLBEHAVIORACTION_OPERATION_NO_ONPORT_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createCallEventContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_callEvent_Class = factory->createEClass_in_EPackage(package, CALLEVENT_CLASS);
	
	m_callEvent_Attribute_operation = factory->createEReference_in_EContainingClass(m_callEvent_Class, CALLEVENT_ATTRIBUTE_OPERATION);
	
	
}

void UmlPackageImpl::createCallOperationActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_callOperationAction_Class = factory->createEClass_in_EPackage(package, CALLOPERATIONACTION_CLASS);
	
	m_callOperationAction_Attribute_operation = factory->createEReference_in_EContainingClass(m_callOperationAction_Class, CALLOPERATIONACTION_ATTRIBUTE_OPERATION);
	m_callOperationAction_Attribute_target = factory->createEReference_in_EContainingClass(m_callOperationAction_Class, CALLOPERATIONACTION_ATTRIBUTE_TARGET);
	
	m_callOperationAction_Operation_type_target_pin_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_callOperationAction_Class, CALLOPERATIONACTION_OPERATION_TYPE_TARGET_PIN_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createCentralBufferNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_centralBufferNode_Class = factory->createEClass_in_EPackage(package, CENTRALBUFFERNODE_CLASS);
	
	
	
}

void UmlPackageImpl::createChangeEventContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_changeEvent_Class = factory->createEClass_in_EPackage(package, CHANGEEVENT_CLASS);
	
	m_changeEvent_Attribute_changeExpression = factory->createEReference_in_EContainingClass(m_changeEvent_Class, CHANGEEVENT_ATTRIBUTE_CHANGEEXPRESSION);
	
	
}

void UmlPackageImpl::createClassContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_class_Class = factory->createEClass_in_EPackage(package, CLASS_CLASS);
	m_class_Attribute_isActive = factory->createEAttribute_in_EContainingClass(m_class_Class, CLASS_ATTRIBUTE_ISACTIVE);
	
	m_class_Attribute_extension = factory->createEReference_in_EContainingClass(m_class_Class, CLASS_ATTRIBUTE_EXTENSION);
	m_class_Attribute_nestedClassifier = factory->createEReference_in_EContainingClass(m_class_Class, CLASS_ATTRIBUTE_NESTEDCLASSIFIER);
	m_class_Attribute_ownedOperation = factory->createEReference_in_EContainingClass(m_class_Class, CLASS_ATTRIBUTE_OWNEDOPERATION);
	m_class_Attribute_ownedReception = factory->createEReference_in_EContainingClass(m_class_Class, CLASS_ATTRIBUTE_OWNEDRECEPTION);
	m_class_Attribute_superClass = factory->createEReference_in_EContainingClass(m_class_Class, CLASS_ATTRIBUTE_SUPERCLASS);
	
	m_class_Operation_createOwnedOperation_String_Type = factory->createEOperation_in_EContainingClass(m_class_Class, CLASS_OPERATION_CREATEOWNEDOPERATION_STRING_TYPE);
	m_class_Operation_getExtensions = factory->createEOperation_in_EContainingClass(m_class_Class, CLASS_OPERATION_GETEXTENSIONS);
	m_class_Operation_getSuperClasses = factory->createEOperation_in_EContainingClass(m_class_Class, CLASS_OPERATION_GETSUPERCLASSES);
	m_class_Operation_isMetaclass = factory->createEOperation_in_EContainingClass(m_class_Class, CLASS_OPERATION_ISMETACLASS);
	m_class_Operation_passive_class_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_class_Class, CLASS_OPERATION_PASSIVE_CLASS_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createClassifierContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_classifier_Class = factory->createEClass_in_EPackage(package, CLASSIFIER_CLASS);
	m_classifier_Attribute_isAbstract = factory->createEAttribute_in_EContainingClass(m_classifier_Class, CLASSIFIER_ATTRIBUTE_ISABSTRACT);
	m_classifier_Attribute_isFinalSpecialization = factory->createEAttribute_in_EContainingClass(m_classifier_Class, CLASSIFIER_ATTRIBUTE_ISFINALSPECIALIZATION);
	
	m_classifier_Attribute_attribute = factory->createEReference_in_EContainingClass(m_classifier_Class, CLASSIFIER_ATTRIBUTE_ATTRIBUTE);
	m_classifier_Attribute_collaborationUse = factory->createEReference_in_EContainingClass(m_classifier_Class, CLASSIFIER_ATTRIBUTE_COLLABORATIONUSE);
	m_classifier_Attribute_feature = factory->createEReference_in_EContainingClass(m_classifier_Class, CLASSIFIER_ATTRIBUTE_FEATURE);
	m_classifier_Attribute_general = factory->createEReference_in_EContainingClass(m_classifier_Class, CLASSIFIER_ATTRIBUTE_GENERAL);
	m_classifier_Attribute_generalization = factory->createEReference_in_EContainingClass(m_classifier_Class, CLASSIFIER_ATTRIBUTE_GENERALIZATION);
	m_classifier_Attribute_inheritedMember = factory->createEReference_in_EContainingClass(m_classifier_Class, CLASSIFIER_ATTRIBUTE_INHERITEDMEMBER);
	m_classifier_Attribute_ownedUseCase = factory->createEReference_in_EContainingClass(m_classifier_Class, CLASSIFIER_ATTRIBUTE_OWNEDUSECASE);
	m_classifier_Attribute_powertypeExtent = factory->createEReference_in_EContainingClass(m_classifier_Class, CLASSIFIER_ATTRIBUTE_POWERTYPEEXTENT);
	m_classifier_Attribute_redefinedClassifier = factory->createEReference_in_EContainingClass(m_classifier_Class, CLASSIFIER_ATTRIBUTE_REDEFINEDCLASSIFIER);
	m_classifier_Attribute_representation = factory->createEReference_in_EContainingClass(m_classifier_Class, CLASSIFIER_ATTRIBUTE_REPRESENTATION);
	m_classifier_Attribute_substitution = factory->createEReference_in_EContainingClass(m_classifier_Class, CLASSIFIER_ATTRIBUTE_SUBSTITUTION);
	m_classifier_Attribute_useCase = factory->createEReference_in_EContainingClass(m_classifier_Class, CLASSIFIER_ATTRIBUTE_USECASE);
	
	m_classifier_Operation_allAttributes = factory->createEOperation_in_EContainingClass(m_classifier_Class, CLASSIFIER_OPERATION_ALLATTRIBUTES);
	m_classifier_Operation_allFeatures = factory->createEOperation_in_EContainingClass(m_classifier_Class, CLASSIFIER_OPERATION_ALLFEATURES);
	m_classifier_Operation_allParents = factory->createEOperation_in_EContainingClass(m_classifier_Class, CLASSIFIER_OPERATION_ALLPARENTS);
	m_classifier_Operation_allRealizedInterfaces = factory->createEOperation_in_EContainingClass(m_classifier_Class, CLASSIFIER_OPERATION_ALLREALIZEDINTERFACES);
	m_classifier_Operation_allSlottableFeatures = factory->createEOperation_in_EContainingClass(m_classifier_Class, CLASSIFIER_OPERATION_ALLSLOTTABLEFEATURES);
	m_classifier_Operation_allUsedInterfaces = factory->createEOperation_in_EContainingClass(m_classifier_Class, CLASSIFIER_OPERATION_ALLUSEDINTERFACES);
	m_classifier_Operation_directlyRealizedInterfaces = factory->createEOperation_in_EContainingClass(m_classifier_Class, CLASSIFIER_OPERATION_DIRECTLYREALIZEDINTERFACES);
	m_classifier_Operation_directlyUsedInterfaces = factory->createEOperation_in_EContainingClass(m_classifier_Class, CLASSIFIER_OPERATION_DIRECTLYUSEDINTERFACES);
	m_classifier_Operation_getAllAttributes = factory->createEOperation_in_EContainingClass(m_classifier_Class, CLASSIFIER_OPERATION_GETALLATTRIBUTES);
	m_classifier_Operation_getAllOperations = factory->createEOperation_in_EContainingClass(m_classifier_Class, CLASSIFIER_OPERATION_GETALLOPERATIONS);
	m_classifier_Operation_getAllUsedInterfaces = factory->createEOperation_in_EContainingClass(m_classifier_Class, CLASSIFIER_OPERATION_GETALLUSEDINTERFACES);
	m_classifier_Operation_getGenerals = factory->createEOperation_in_EContainingClass(m_classifier_Class, CLASSIFIER_OPERATION_GETGENERALS);
	m_classifier_Operation_getInheritedMembers = factory->createEOperation_in_EContainingClass(m_classifier_Class, CLASSIFIER_OPERATION_GETINHERITEDMEMBERS);
	m_classifier_Operation_getOperation_String_Type = factory->createEOperation_in_EContainingClass(m_classifier_Class, CLASSIFIER_OPERATION_GETOPERATION_STRING_TYPE);
	m_classifier_Operation_getOperation_String_Boolean = factory->createEOperation_in_EContainingClass(m_classifier_Class, CLASSIFIER_OPERATION_GETOPERATION_STRING_BOOLEAN);
	m_classifier_Operation_getOperations = factory->createEOperation_in_EContainingClass(m_classifier_Class, CLASSIFIER_OPERATION_GETOPERATIONS);
	m_classifier_Operation_getUsedInterfaces = factory->createEOperation_in_EContainingClass(m_classifier_Class, CLASSIFIER_OPERATION_GETUSEDINTERFACES);
	m_classifier_Operation_hasVisibilityOf_NamedElement = factory->createEOperation_in_EContainingClass(m_classifier_Class, CLASSIFIER_OPERATION_HASVISIBILITYOF_NAMEDELEMENT);
	m_classifier_Operation_inherit_NamedElement = factory->createEOperation_in_EContainingClass(m_classifier_Class, CLASSIFIER_OPERATION_INHERIT_NAMEDELEMENT);
	m_classifier_Operation_inheritableMembers_Classifier = factory->createEOperation_in_EContainingClass(m_classifier_Class, CLASSIFIER_OPERATION_INHERITABLEMEMBERS_CLASSIFIER);
	m_classifier_Operation_isSubstitutableFor_Classifier = factory->createEOperation_in_EContainingClass(m_classifier_Class, CLASSIFIER_OPERATION_ISSUBSTITUTABLEFOR_CLASSIFIER);
	m_classifier_Operation_maps_to_generalization_set_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_classifier_Class, CLASSIFIER_OPERATION_MAPS_TO_GENERALIZATION_SET_EDIAGNOSTICCHAIN_EMAP);
	m_classifier_Operation_maySpecializeType_Classifier = factory->createEOperation_in_EContainingClass(m_classifier_Class, CLASSIFIER_OPERATION_MAYSPECIALIZETYPE_CLASSIFIER);
	m_classifier_Operation_no_cycles_in_generalization_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_classifier_Class, CLASSIFIER_OPERATION_NO_CYCLES_IN_GENERALIZATION_EDIAGNOSTICCHAIN_EMAP);
	m_classifier_Operation_non_final_parents_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_classifier_Class, CLASSIFIER_OPERATION_NON_FINAL_PARENTS_EDIAGNOSTICCHAIN_EMAP);
	m_classifier_Operation_parents = factory->createEOperation_in_EContainingClass(m_classifier_Class, CLASSIFIER_OPERATION_PARENTS);
	m_classifier_Operation_specialize_type_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_classifier_Class, CLASSIFIER_OPERATION_SPECIALIZE_TYPE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createClassifierTemplateParameterContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_classifierTemplateParameter_Class = factory->createEClass_in_EPackage(package, CLASSIFIERTEMPLATEPARAMETER_CLASS);
	m_classifierTemplateParameter_Attribute_allowSubstitutable = factory->createEAttribute_in_EContainingClass(m_classifierTemplateParameter_Class, CLASSIFIERTEMPLATEPARAMETER_ATTRIBUTE_ALLOWSUBSTITUTABLE);
	
	m_classifierTemplateParameter_Attribute_constrainingClassifier = factory->createEReference_in_EContainingClass(m_classifierTemplateParameter_Class, CLASSIFIERTEMPLATEPARAMETER_ATTRIBUTE_CONSTRAININGCLASSIFIER);
	
	m_classifierTemplateParameter_Operation_actual_is_classifier_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_classifierTemplateParameter_Class, CLASSIFIERTEMPLATEPARAMETER_OPERATION_ACTUAL_IS_CLASSIFIER_EDIAGNOSTICCHAIN_EMAP);
	m_classifierTemplateParameter_Operation_constraining_classifiers_constrain_args_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_classifierTemplateParameter_Class, CLASSIFIERTEMPLATEPARAMETER_OPERATION_CONSTRAINING_CLASSIFIERS_CONSTRAIN_ARGS_EDIAGNOSTICCHAIN_EMAP);
	m_classifierTemplateParameter_Operation_constraining_classifiers_constrain_parametered_element_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_classifierTemplateParameter_Class, CLASSIFIERTEMPLATEPARAMETER_OPERATION_CONSTRAINING_CLASSIFIERS_CONSTRAIN_PARAMETERED_ELEMENT_EDIAGNOSTICCHAIN_EMAP);
	m_classifierTemplateParameter_Operation_has_constraining_classifier_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_classifierTemplateParameter_Class, CLASSIFIERTEMPLATEPARAMETER_OPERATION_HAS_CONSTRAINING_CLASSIFIER_EDIAGNOSTICCHAIN_EMAP);
	m_classifierTemplateParameter_Operation_matching_abstract_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_classifierTemplateParameter_Class, CLASSIFIERTEMPLATEPARAMETER_OPERATION_MATCHING_ABSTRACT_EDIAGNOSTICCHAIN_EMAP);
	m_classifierTemplateParameter_Operation_parametered_element_no_features_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_classifierTemplateParameter_Class, CLASSIFIERTEMPLATEPARAMETER_OPERATION_PARAMETERED_ELEMENT_NO_FEATURES_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createClauseContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_clause_Class = factory->createEClass_in_EPackage(package, CLAUSE_CLASS);
	
	m_clause_Attribute_body = factory->createEReference_in_EContainingClass(m_clause_Class, CLAUSE_ATTRIBUTE_BODY);
	m_clause_Attribute_bodyOutput = factory->createEReference_in_EContainingClass(m_clause_Class, CLAUSE_ATTRIBUTE_BODYOUTPUT);
	m_clause_Attribute_decider = factory->createEReference_in_EContainingClass(m_clause_Class, CLAUSE_ATTRIBUTE_DECIDER);
	m_clause_Attribute_predecessorClause = factory->createEReference_in_EContainingClass(m_clause_Class, CLAUSE_ATTRIBUTE_PREDECESSORCLAUSE);
	m_clause_Attribute_successorClause = factory->createEReference_in_EContainingClass(m_clause_Class, CLAUSE_ATTRIBUTE_SUCCESSORCLAUSE);
	m_clause_Attribute_test = factory->createEReference_in_EContainingClass(m_clause_Class, CLAUSE_ATTRIBUTE_TEST);
	
	m_clause_Operation_body_output_pins_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_clause_Class, CLAUSE_OPERATION_BODY_OUTPUT_PINS_EDIAGNOSTICCHAIN_EMAP);
	m_clause_Operation_decider_output_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_clause_Class, CLAUSE_OPERATION_DECIDER_OUTPUT_EDIAGNOSTICCHAIN_EMAP);
	m_clause_Operation_test_and_body_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_clause_Class, CLAUSE_OPERATION_TEST_AND_BODY_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createClearAssociationActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_clearAssociationAction_Class = factory->createEClass_in_EPackage(package, CLEARASSOCIATIONACTION_CLASS);
	
	m_clearAssociationAction_Attribute_association = factory->createEReference_in_EContainingClass(m_clearAssociationAction_Class, CLEARASSOCIATIONACTION_ATTRIBUTE_ASSOCIATION);
	m_clearAssociationAction_Attribute_object = factory->createEReference_in_EContainingClass(m_clearAssociationAction_Class, CLEARASSOCIATIONACTION_ATTRIBUTE_OBJECT);
	
	m_clearAssociationAction_Operation_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_clearAssociationAction_Class, CLEARASSOCIATIONACTION_OPERATION_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	m_clearAssociationAction_Operation_same_type_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_clearAssociationAction_Class, CLEARASSOCIATIONACTION_OPERATION_SAME_TYPE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createClearStructuralFeatureActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_clearStructuralFeatureAction_Class = factory->createEClass_in_EPackage(package, CLEARSTRUCTURALFEATUREACTION_CLASS);
	
	m_clearStructuralFeatureAction_Attribute_result = factory->createEReference_in_EContainingClass(m_clearStructuralFeatureAction_Class, CLEARSTRUCTURALFEATUREACTION_ATTRIBUTE_RESULT);
	
	m_clearStructuralFeatureAction_Operation_multiplicity_of_result_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_clearStructuralFeatureAction_Class, CLEARSTRUCTURALFEATUREACTION_OPERATION_MULTIPLICITY_OF_RESULT_EDIAGNOSTICCHAIN_EMAP);
	m_clearStructuralFeatureAction_Operation_type_of_result_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_clearStructuralFeatureAction_Class, CLEARSTRUCTURALFEATUREACTION_OPERATION_TYPE_OF_RESULT_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createClearVariableActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_clearVariableAction_Class = factory->createEClass_in_EPackage(package, CLEARVARIABLEACTION_CLASS);
	
	
	
}

void UmlPackageImpl::createCollaborationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_collaboration_Class = factory->createEClass_in_EPackage(package, COLLABORATION_CLASS);
	
	m_collaboration_Attribute_collaborationRole = factory->createEReference_in_EContainingClass(m_collaboration_Class, COLLABORATION_ATTRIBUTE_COLLABORATIONROLE);
	
	
}

void UmlPackageImpl::createCollaborationUseContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_collaborationUse_Class = factory->createEClass_in_EPackage(package, COLLABORATIONUSE_CLASS);
	
	m_collaborationUse_Attribute_roleBinding = factory->createEReference_in_EContainingClass(m_collaborationUse_Class, COLLABORATIONUSE_ATTRIBUTE_ROLEBINDING);
	m_collaborationUse_Attribute_type = factory->createEReference_in_EContainingClass(m_collaborationUse_Class, COLLABORATIONUSE_ATTRIBUTE_TYPE);
	
	m_collaborationUse_Operation_client_elements_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_collaborationUse_Class, COLLABORATIONUSE_OPERATION_CLIENT_ELEMENTS_EDIAGNOSTICCHAIN_EMAP);
	m_collaborationUse_Operation_connectors_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_collaborationUse_Class, COLLABORATIONUSE_OPERATION_CONNECTORS_EDIAGNOSTICCHAIN_EMAP);
	m_collaborationUse_Operation_every_role_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_collaborationUse_Class, COLLABORATIONUSE_OPERATION_EVERY_ROLE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createCombinedFragmentContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_combinedFragment_Class = factory->createEClass_in_EPackage(package, COMBINEDFRAGMENT_CLASS);
	m_combinedFragment_Attribute_interactionOperator = factory->createEAttribute_in_EContainingClass(m_combinedFragment_Class, COMBINEDFRAGMENT_ATTRIBUTE_INTERACTIONOPERATOR);
	
	m_combinedFragment_Attribute_cfragmentGate = factory->createEReference_in_EContainingClass(m_combinedFragment_Class, COMBINEDFRAGMENT_ATTRIBUTE_CFRAGMENTGATE);
	m_combinedFragment_Attribute_operand = factory->createEReference_in_EContainingClass(m_combinedFragment_Class, COMBINEDFRAGMENT_ATTRIBUTE_OPERAND);
	
	m_combinedFragment_Operation_break__EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_combinedFragment_Class, COMBINEDFRAGMENT_OPERATION_BREAK__EDIAGNOSTICCHAIN_EMAP);
	m_combinedFragment_Operation_consider_and_ignore_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_combinedFragment_Class, COMBINEDFRAGMENT_OPERATION_CONSIDER_AND_IGNORE_EDIAGNOSTICCHAIN_EMAP);
	m_combinedFragment_Operation_opt_loop_break_neg_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_combinedFragment_Class, COMBINEDFRAGMENT_OPERATION_OPT_LOOP_BREAK_NEG_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createCommentContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_comment_Class = factory->createEClass_in_EPackage(package, COMMENT_CLASS);
	m_comment_Attribute_body = factory->createEAttribute_in_EContainingClass(m_comment_Class, COMMENT_ATTRIBUTE_BODY);
	
	m_comment_Attribute_annotatedElement = factory->createEReference_in_EContainingClass(m_comment_Class, COMMENT_ATTRIBUTE_ANNOTATEDELEMENT);
	
	
}

void UmlPackageImpl::createCommunicationPathContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_communicationPath_Class = factory->createEClass_in_EPackage(package, COMMUNICATIONPATH_CLASS);
	
	
	
}

void UmlPackageImpl::createComponentContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_component_Class = factory->createEClass_in_EPackage(package, COMPONENT_CLASS);
	m_component_Attribute_isIndirectlyInstantiated = factory->createEAttribute_in_EContainingClass(m_component_Class, COMPONENT_ATTRIBUTE_ISINDIRECTLYINSTANTIATED);
	
	m_component_Attribute_packagedElement = factory->createEReference_in_EContainingClass(m_component_Class, COMPONENT_ATTRIBUTE_PACKAGEDELEMENT);
	m_component_Attribute_provided = factory->createEReference_in_EContainingClass(m_component_Class, COMPONENT_ATTRIBUTE_PROVIDED);
	m_component_Attribute_realization = factory->createEReference_in_EContainingClass(m_component_Class, COMPONENT_ATTRIBUTE_REALIZATION);
	m_component_Attribute_required = factory->createEReference_in_EContainingClass(m_component_Class, COMPONENT_ATTRIBUTE_REQUIRED);
	
	m_component_Operation_createOwnedClass_String_Boolean = factory->createEOperation_in_EContainingClass(m_component_Class, COMPONENT_OPERATION_CREATEOWNEDCLASS_STRING_BOOLEAN);
	m_component_Operation_createOwnedEnumeration_String = factory->createEOperation_in_EContainingClass(m_component_Class, COMPONENT_OPERATION_CREATEOWNEDENUMERATION_STRING);
	m_component_Operation_createOwnedInterface_String = factory->createEOperation_in_EContainingClass(m_component_Class, COMPONENT_OPERATION_CREATEOWNEDINTERFACE_STRING);
	m_component_Operation_createOwnedPrimitiveType_String = factory->createEOperation_in_EContainingClass(m_component_Class, COMPONENT_OPERATION_CREATEOWNEDPRIMITIVETYPE_STRING);
	m_component_Operation_getProvideds = factory->createEOperation_in_EContainingClass(m_component_Class, COMPONENT_OPERATION_GETPROVIDEDS);
	m_component_Operation_getRequireds = factory->createEOperation_in_EContainingClass(m_component_Class, COMPONENT_OPERATION_GETREQUIREDS);
	m_component_Operation_no_nested_classifiers_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_component_Class, COMPONENT_OPERATION_NO_NESTED_CLASSIFIERS_EDIAGNOSTICCHAIN_EMAP);
	m_component_Operation_no_packaged_elements_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_component_Class, COMPONENT_OPERATION_NO_PACKAGED_ELEMENTS_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createComponentRealizationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_componentRealization_Class = factory->createEClass_in_EPackage(package, COMPONENTREALIZATION_CLASS);
	
	m_componentRealization_Attribute_abstraction = factory->createEReference_in_EContainingClass(m_componentRealization_Class, COMPONENTREALIZATION_ATTRIBUTE_ABSTRACTION);
	m_componentRealization_Attribute_realizingClassifier = factory->createEReference_in_EContainingClass(m_componentRealization_Class, COMPONENTREALIZATION_ATTRIBUTE_REALIZINGCLASSIFIER);
	
	
}

void UmlPackageImpl::createConditionalNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_conditionalNode_Class = factory->createEClass_in_EPackage(package, CONDITIONALNODE_CLASS);
	m_conditionalNode_Attribute_isAssured = factory->createEAttribute_in_EContainingClass(m_conditionalNode_Class, CONDITIONALNODE_ATTRIBUTE_ISASSURED);
	m_conditionalNode_Attribute_isDeterminate = factory->createEAttribute_in_EContainingClass(m_conditionalNode_Class, CONDITIONALNODE_ATTRIBUTE_ISDETERMINATE);
	
	m_conditionalNode_Attribute_clause = factory->createEReference_in_EContainingClass(m_conditionalNode_Class, CONDITIONALNODE_ATTRIBUTE_CLAUSE);
	m_conditionalNode_Attribute_result = factory->createEReference_in_EContainingClass(m_conditionalNode_Class, CONDITIONALNODE_ATTRIBUTE_RESULT);
	
	m_conditionalNode_Operation_clause_no_predecessor_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_conditionalNode_Class, CONDITIONALNODE_OPERATION_CLAUSE_NO_PREDECESSOR_EDIAGNOSTICCHAIN_EMAP);
	m_conditionalNode_Operation_executable_nodes_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_conditionalNode_Class, CONDITIONALNODE_OPERATION_EXECUTABLE_NODES_EDIAGNOSTICCHAIN_EMAP);
	m_conditionalNode_Operation_matching_output_pins_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_conditionalNode_Class, CONDITIONALNODE_OPERATION_MATCHING_OUTPUT_PINS_EDIAGNOSTICCHAIN_EMAP);
	m_conditionalNode_Operation_no_input_pins_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_conditionalNode_Class, CONDITIONALNODE_OPERATION_NO_INPUT_PINS_EDIAGNOSTICCHAIN_EMAP);
	m_conditionalNode_Operation_one_clause_with_executable_node_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_conditionalNode_Class, CONDITIONALNODE_OPERATION_ONE_CLAUSE_WITH_EXECUTABLE_NODE_EDIAGNOSTICCHAIN_EMAP);
	m_conditionalNode_Operation_result_no_incoming_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_conditionalNode_Class, CONDITIONALNODE_OPERATION_RESULT_NO_INCOMING_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createConnectableElementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_connectableElement_Class = factory->createEClass_in_EPackage(package, CONNECTABLEELEMENT_CLASS);
	
	m_connectableElement_Attribute_end = factory->createEReference_in_EContainingClass(m_connectableElement_Class, CONNECTABLEELEMENT_ATTRIBUTE_END);
	
	m_connectableElement_Operation_getEnds = factory->createEOperation_in_EContainingClass(m_connectableElement_Class, CONNECTABLEELEMENT_OPERATION_GETENDS);
	
}

void UmlPackageImpl::createConnectableElementTemplateParameterContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_connectableElementTemplateParameter_Class = factory->createEClass_in_EPackage(package, CONNECTABLEELEMENTTEMPLATEPARAMETER_CLASS);
	
	
	
}

void UmlPackageImpl::createConnectionPointReferenceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_connectionPointReference_Class = factory->createEClass_in_EPackage(package, CONNECTIONPOINTREFERENCE_CLASS);
	
	m_connectionPointReference_Attribute_entry = factory->createEReference_in_EContainingClass(m_connectionPointReference_Class, CONNECTIONPOINTREFERENCE_ATTRIBUTE_ENTRY);
	m_connectionPointReference_Attribute_exit = factory->createEReference_in_EContainingClass(m_connectionPointReference_Class, CONNECTIONPOINTREFERENCE_ATTRIBUTE_EXIT);
	m_connectionPointReference_Attribute_state = factory->createEReference_in_EContainingClass(m_connectionPointReference_Class, CONNECTIONPOINTREFERENCE_ATTRIBUTE_STATE);
	
	m_connectionPointReference_Operation_entry_pseudostates_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_connectionPointReference_Class, CONNECTIONPOINTREFERENCE_OPERATION_ENTRY_PSEUDOSTATES_EDIAGNOSTICCHAIN_EMAP);
	m_connectionPointReference_Operation_exit_pseudostates_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_connectionPointReference_Class, CONNECTIONPOINTREFERENCE_OPERATION_EXIT_PSEUDOSTATES_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createConnectorContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_connector_Class = factory->createEClass_in_EPackage(package, CONNECTOR_CLASS);
	m_connector_Attribute_kind = factory->createEAttribute_in_EContainingClass(m_connector_Class, CONNECTOR_ATTRIBUTE_KIND);
	
	m_connector_Attribute_contract = factory->createEReference_in_EContainingClass(m_connector_Class, CONNECTOR_ATTRIBUTE_CONTRACT);
	m_connector_Attribute_end = factory->createEReference_in_EContainingClass(m_connector_Class, CONNECTOR_ATTRIBUTE_END);
	m_connector_Attribute_redefinedConnector = factory->createEReference_in_EContainingClass(m_connector_Class, CONNECTOR_ATTRIBUTE_REDEFINEDCONNECTOR);
	m_connector_Attribute_type = factory->createEReference_in_EContainingClass(m_connector_Class, CONNECTOR_ATTRIBUTE_TYPE);
	
	m_connector_Operation_getKind = factory->createEOperation_in_EContainingClass(m_connector_Class, CONNECTOR_OPERATION_GETKIND);
	m_connector_Operation_roles_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_connector_Class, CONNECTOR_OPERATION_ROLES_EDIAGNOSTICCHAIN_EMAP);
	m_connector_Operation_types_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_connector_Class, CONNECTOR_OPERATION_TYPES_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createConnectorEndContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_connectorEnd_Class = factory->createEClass_in_EPackage(package, CONNECTOREND_CLASS);
	
	m_connectorEnd_Attribute_definingEnd = factory->createEReference_in_EContainingClass(m_connectorEnd_Class, CONNECTOREND_ATTRIBUTE_DEFININGEND);
	m_connectorEnd_Attribute_partWithPort = factory->createEReference_in_EContainingClass(m_connectorEnd_Class, CONNECTOREND_ATTRIBUTE_PARTWITHPORT);
	m_connectorEnd_Attribute_role = factory->createEReference_in_EContainingClass(m_connectorEnd_Class, CONNECTOREND_ATTRIBUTE_ROLE);
	
	m_connectorEnd_Operation_getDefiningEnd = factory->createEOperation_in_EContainingClass(m_connectorEnd_Class, CONNECTOREND_OPERATION_GETDEFININGEND);
	m_connectorEnd_Operation_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_connectorEnd_Class, CONNECTOREND_OPERATION_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	m_connectorEnd_Operation_part_with_port_empty_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_connectorEnd_Class, CONNECTOREND_OPERATION_PART_WITH_PORT_EMPTY_EDIAGNOSTICCHAIN_EMAP);
	m_connectorEnd_Operation_role_and_part_with_port_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_connectorEnd_Class, CONNECTOREND_OPERATION_ROLE_AND_PART_WITH_PORT_EDIAGNOSTICCHAIN_EMAP);
	m_connectorEnd_Operation_self_part_with_port_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_connectorEnd_Class, CONNECTOREND_OPERATION_SELF_PART_WITH_PORT_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createConsiderIgnoreFragmentContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_considerIgnoreFragment_Class = factory->createEClass_in_EPackage(package, CONSIDERIGNOREFRAGMENT_CLASS);
	
	m_considerIgnoreFragment_Attribute_message = factory->createEReference_in_EContainingClass(m_considerIgnoreFragment_Class, CONSIDERIGNOREFRAGMENT_ATTRIBUTE_MESSAGE);
	
	m_considerIgnoreFragment_Operation_consider_or_ignore_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_considerIgnoreFragment_Class, CONSIDERIGNOREFRAGMENT_OPERATION_CONSIDER_OR_IGNORE_EDIAGNOSTICCHAIN_EMAP);
	m_considerIgnoreFragment_Operation_type_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_considerIgnoreFragment_Class, CONSIDERIGNOREFRAGMENT_OPERATION_TYPE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createConstraintContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_constraint_Class = factory->createEClass_in_EPackage(package, CONSTRAINT_CLASS);
	
	m_constraint_Attribute_constrainedElement = factory->createEReference_in_EContainingClass(m_constraint_Class, CONSTRAINT_ATTRIBUTE_CONSTRAINEDELEMENT);
	m_constraint_Attribute_context = factory->createEReference_in_EContainingClass(m_constraint_Class, CONSTRAINT_ATTRIBUTE_CONTEXT);
	m_constraint_Attribute_specification = factory->createEReference_in_EContainingClass(m_constraint_Class, CONSTRAINT_ATTRIBUTE_SPECIFICATION);
	
	m_constraint_Operation_boolean_value_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_constraint_Class, CONSTRAINT_OPERATION_BOOLEAN_VALUE_EDIAGNOSTICCHAIN_EMAP);
	m_constraint_Operation_no_side_effects_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_constraint_Class, CONSTRAINT_OPERATION_NO_SIDE_EFFECTS_EDIAGNOSTICCHAIN_EMAP);
	m_constraint_Operation_not_apply_to_self_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_constraint_Class, CONSTRAINT_OPERATION_NOT_APPLY_TO_SELF_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createContinuationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_continuation_Class = factory->createEClass_in_EPackage(package, CONTINUATION_CLASS);
	m_continuation_Attribute_setting = factory->createEAttribute_in_EContainingClass(m_continuation_Class, CONTINUATION_ATTRIBUTE_SETTING);
	
	
	m_continuation_Operation_first_or_last_interaction_fragment_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_continuation_Class, CONTINUATION_OPERATION_FIRST_OR_LAST_INTERACTION_FRAGMENT_EDIAGNOSTICCHAIN_EMAP);
	m_continuation_Operation_global_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_continuation_Class, CONTINUATION_OPERATION_GLOBAL_EDIAGNOSTICCHAIN_EMAP);
	m_continuation_Operation_same_name_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_continuation_Class, CONTINUATION_OPERATION_SAME_NAME_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createControlFlowContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_controlFlow_Class = factory->createEClass_in_EPackage(package, CONTROLFLOW_CLASS);
	
	
	m_controlFlow_Operation_object_nodes_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_controlFlow_Class, CONTROLFLOW_OPERATION_OBJECT_NODES_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createControlNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_controlNode_Class = factory->createEClass_in_EPackage(package, CONTROLNODE_CLASS);
	
	
	
}

void UmlPackageImpl::createCreateLinkActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_createLinkAction_Class = factory->createEClass_in_EPackage(package, CREATELINKACTION_CLASS);
	
	
	m_createLinkAction_Operation_association_not_abstract_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_createLinkAction_Class, CREATELINKACTION_OPERATION_ASSOCIATION_NOT_ABSTRACT_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createCreateLinkObjectActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_createLinkObjectAction_Class = factory->createEClass_in_EPackage(package, CREATELINKOBJECTACTION_CLASS);
	
	m_createLinkObjectAction_Attribute_result = factory->createEReference_in_EContainingClass(m_createLinkObjectAction_Class, CREATELINKOBJECTACTION_ATTRIBUTE_RESULT);
	
	m_createLinkObjectAction_Operation_association_class_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_createLinkObjectAction_Class, CREATELINKOBJECTACTION_OPERATION_ASSOCIATION_CLASS_EDIAGNOSTICCHAIN_EMAP);
	m_createLinkObjectAction_Operation_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_createLinkObjectAction_Class, CREATELINKOBJECTACTION_OPERATION_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	m_createLinkObjectAction_Operation_type_of_result_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_createLinkObjectAction_Class, CREATELINKOBJECTACTION_OPERATION_TYPE_OF_RESULT_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createCreateObjectActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_createObjectAction_Class = factory->createEClass_in_EPackage(package, CREATEOBJECTACTION_CLASS);
	
	m_createObjectAction_Attribute_classifier = factory->createEReference_in_EContainingClass(m_createObjectAction_Class, CREATEOBJECTACTION_ATTRIBUTE_CLASSIFIER);
	m_createObjectAction_Attribute_result = factory->createEReference_in_EContainingClass(m_createObjectAction_Class, CREATEOBJECTACTION_ATTRIBUTE_RESULT);
	
	m_createObjectAction_Operation_classifier_not_abstract_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_createObjectAction_Class, CREATEOBJECTACTION_OPERATION_CLASSIFIER_NOT_ABSTRACT_EDIAGNOSTICCHAIN_EMAP);
	m_createObjectAction_Operation_classifier_not_association_class_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_createObjectAction_Class, CREATEOBJECTACTION_OPERATION_CLASSIFIER_NOT_ASSOCIATION_CLASS_EDIAGNOSTICCHAIN_EMAP);
	m_createObjectAction_Operation_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_createObjectAction_Class, CREATEOBJECTACTION_OPERATION_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	m_createObjectAction_Operation_same_type_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_createObjectAction_Class, CREATEOBJECTACTION_OPERATION_SAME_TYPE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createDataStoreNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_dataStoreNode_Class = factory->createEClass_in_EPackage(package, DATASTORENODE_CLASS);
	
	
	
}

void UmlPackageImpl::createDataTypeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_dataType_Class = factory->createEClass_in_EPackage(package, DATATYPE_CLASS);
	
	m_dataType_Attribute_ownedAttribute = factory->createEReference_in_EContainingClass(m_dataType_Class, DATATYPE_ATTRIBUTE_OWNEDATTRIBUTE);
	m_dataType_Attribute_ownedOperation = factory->createEReference_in_EContainingClass(m_dataType_Class, DATATYPE_ATTRIBUTE_OWNEDOPERATION);
	
	m_dataType_Operation_createOwnedAttribute_String_UnlimitedNatural = factory->createEOperation_in_EContainingClass(m_dataType_Class, DATATYPE_OPERATION_CREATEOWNEDATTRIBUTE_STRING_UNLIMITEDNATURAL);
	m_dataType_Operation_createOwnedOperation_String_Type = factory->createEOperation_in_EContainingClass(m_dataType_Class, DATATYPE_OPERATION_CREATEOWNEDOPERATION_STRING_TYPE);
	
}

void UmlPackageImpl::createDecisionNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_decisionNode_Class = factory->createEClass_in_EPackage(package, DECISIONNODE_CLASS);
	
	m_decisionNode_Attribute_decisionInput = factory->createEReference_in_EContainingClass(m_decisionNode_Class, DECISIONNODE_ATTRIBUTE_DECISIONINPUT);
	m_decisionNode_Attribute_decisionInputFlow = factory->createEReference_in_EContainingClass(m_decisionNode_Class, DECISIONNODE_ATTRIBUTE_DECISIONINPUTFLOW);
	
	m_decisionNode_Operation_decision_input_flow_incoming_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_decisionNode_Class, DECISIONNODE_OPERATION_DECISION_INPUT_FLOW_INCOMING_EDIAGNOSTICCHAIN_EMAP);
	m_decisionNode_Operation_edges_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_decisionNode_Class, DECISIONNODE_OPERATION_EDGES_EDIAGNOSTICCHAIN_EMAP);
	m_decisionNode_Operation_incoming_control_one_input_parameter_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_decisionNode_Class, DECISIONNODE_OPERATION_INCOMING_CONTROL_ONE_INPUT_PARAMETER_EDIAGNOSTICCHAIN_EMAP);
	m_decisionNode_Operation_incoming_object_one_input_parameter_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_decisionNode_Class, DECISIONNODE_OPERATION_INCOMING_OBJECT_ONE_INPUT_PARAMETER_EDIAGNOSTICCHAIN_EMAP);
	m_decisionNode_Operation_incoming_outgoing_edges_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_decisionNode_Class, DECISIONNODE_OPERATION_INCOMING_OUTGOING_EDGES_EDIAGNOSTICCHAIN_EMAP);
	m_decisionNode_Operation_parameters_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_decisionNode_Class, DECISIONNODE_OPERATION_PARAMETERS_EDIAGNOSTICCHAIN_EMAP);
	m_decisionNode_Operation_two_input_parameters_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_decisionNode_Class, DECISIONNODE_OPERATION_TWO_INPUT_PARAMETERS_EDIAGNOSTICCHAIN_EMAP);
	m_decisionNode_Operation_zero_input_parameters_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_decisionNode_Class, DECISIONNODE_OPERATION_ZERO_INPUT_PARAMETERS_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createDependencyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_dependency_Class = factory->createEClass_in_EPackage(package, DEPENDENCY_CLASS);
	
	m_dependency_Attribute_client = factory->createEReference_in_EContainingClass(m_dependency_Class, DEPENDENCY_ATTRIBUTE_CLIENT);
	m_dependency_Attribute_supplier = factory->createEReference_in_EContainingClass(m_dependency_Class, DEPENDENCY_ATTRIBUTE_SUPPLIER);
	
	
}

void UmlPackageImpl::createDeployedArtifactContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_deployedArtifact_Class = factory->createEClass_in_EPackage(package, DEPLOYEDARTIFACT_CLASS);
	
	
	
}

void UmlPackageImpl::createDeploymentContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_deployment_Class = factory->createEClass_in_EPackage(package, DEPLOYMENT_CLASS);
	
	m_deployment_Attribute_configuration = factory->createEReference_in_EContainingClass(m_deployment_Class, DEPLOYMENT_ATTRIBUTE_CONFIGURATION);
	m_deployment_Attribute_deployedArtifact = factory->createEReference_in_EContainingClass(m_deployment_Class, DEPLOYMENT_ATTRIBUTE_DEPLOYEDARTIFACT);
	m_deployment_Attribute_location = factory->createEReference_in_EContainingClass(m_deployment_Class, DEPLOYMENT_ATTRIBUTE_LOCATION);
	
	
}

void UmlPackageImpl::createDeploymentSpecificationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_deploymentSpecification_Class = factory->createEClass_in_EPackage(package, DEPLOYMENTSPECIFICATION_CLASS);
	m_deploymentSpecification_Attribute_deploymentLocation = factory->createEAttribute_in_EContainingClass(m_deploymentSpecification_Class, DEPLOYMENTSPECIFICATION_ATTRIBUTE_DEPLOYMENTLOCATION);
	m_deploymentSpecification_Attribute_executionLocation = factory->createEAttribute_in_EContainingClass(m_deploymentSpecification_Class, DEPLOYMENTSPECIFICATION_ATTRIBUTE_EXECUTIONLOCATION);
	
	m_deploymentSpecification_Attribute_deployment = factory->createEReference_in_EContainingClass(m_deploymentSpecification_Class, DEPLOYMENTSPECIFICATION_ATTRIBUTE_DEPLOYMENT);
	
	m_deploymentSpecification_Operation_deployed_elements_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_deploymentSpecification_Class, DEPLOYMENTSPECIFICATION_OPERATION_DEPLOYED_ELEMENTS_EDIAGNOSTICCHAIN_EMAP);
	m_deploymentSpecification_Operation_deployment_target_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_deploymentSpecification_Class, DEPLOYMENTSPECIFICATION_OPERATION_DEPLOYMENT_TARGET_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createDeploymentTargetContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_deploymentTarget_Class = factory->createEClass_in_EPackage(package, DEPLOYMENTTARGET_CLASS);
	
	m_deploymentTarget_Attribute_deployedElement = factory->createEReference_in_EContainingClass(m_deploymentTarget_Class, DEPLOYMENTTARGET_ATTRIBUTE_DEPLOYEDELEMENT);
	m_deploymentTarget_Attribute_deployment = factory->createEReference_in_EContainingClass(m_deploymentTarget_Class, DEPLOYMENTTARGET_ATTRIBUTE_DEPLOYMENT);
	
	m_deploymentTarget_Operation_getDeployedElements = factory->createEOperation_in_EContainingClass(m_deploymentTarget_Class, DEPLOYMENTTARGET_OPERATION_GETDEPLOYEDELEMENTS);
	
}

void UmlPackageImpl::createDestroyLinkActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_destroyLinkAction_Class = factory->createEClass_in_EPackage(package, DESTROYLINKACTION_CLASS);
	
	
	
}

void UmlPackageImpl::createDestroyObjectActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_destroyObjectAction_Class = factory->createEClass_in_EPackage(package, DESTROYOBJECTACTION_CLASS);
	m_destroyObjectAction_Attribute_isDestroyLinks = factory->createEAttribute_in_EContainingClass(m_destroyObjectAction_Class, DESTROYOBJECTACTION_ATTRIBUTE_ISDESTROYLINKS);
	m_destroyObjectAction_Attribute_isDestroyOwnedObjects = factory->createEAttribute_in_EContainingClass(m_destroyObjectAction_Class, DESTROYOBJECTACTION_ATTRIBUTE_ISDESTROYOWNEDOBJECTS);
	
	m_destroyObjectAction_Attribute_target = factory->createEReference_in_EContainingClass(m_destroyObjectAction_Class, DESTROYOBJECTACTION_ATTRIBUTE_TARGET);
	
	m_destroyObjectAction_Operation_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_destroyObjectAction_Class, DESTROYOBJECTACTION_OPERATION_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	m_destroyObjectAction_Operation_no_type_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_destroyObjectAction_Class, DESTROYOBJECTACTION_OPERATION_NO_TYPE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createDestructionOccurrenceSpecificationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_destructionOccurrenceSpecification_Class = factory->createEClass_in_EPackage(package, DESTRUCTIONOCCURRENCESPECIFICATION_CLASS);
	
	
	m_destructionOccurrenceSpecification_Operation_no_occurrence_specifications_below_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_destructionOccurrenceSpecification_Class, DESTRUCTIONOCCURRENCESPECIFICATION_OPERATION_NO_OCCURRENCE_SPECIFICATIONS_BELOW_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createDeviceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_device_Class = factory->createEClass_in_EPackage(package, DEVICE_CLASS);
	
	
	
}

void UmlPackageImpl::createDirectedRelationshipContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_directedRelationship_Class = factory->createEClass_in_EPackage(package, DIRECTEDRELATIONSHIP_CLASS);
	
	m_directedRelationship_Attribute_source = factory->createEReference_in_EContainingClass(m_directedRelationship_Class, DIRECTEDRELATIONSHIP_ATTRIBUTE_SOURCE);
	m_directedRelationship_Attribute_target = factory->createEReference_in_EContainingClass(m_directedRelationship_Class, DIRECTEDRELATIONSHIP_ATTRIBUTE_TARGET);
	
	
}

void UmlPackageImpl::createDurationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_duration_Class = factory->createEClass_in_EPackage(package, DURATION_CLASS);
	
	m_duration_Attribute_expr = factory->createEReference_in_EContainingClass(m_duration_Class, DURATION_ATTRIBUTE_EXPR);
	m_duration_Attribute_observation = factory->createEReference_in_EContainingClass(m_duration_Class, DURATION_ATTRIBUTE_OBSERVATION);
	
	m_duration_Operation_no_expr_requires_observation_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_duration_Class, DURATION_OPERATION_NO_EXPR_REQUIRES_OBSERVATION_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createDurationConstraintContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_durationConstraint_Class = factory->createEClass_in_EPackage(package, DURATIONCONSTRAINT_CLASS);
	m_durationConstraint_Attribute_firstEvent = factory->createEAttribute_in_EContainingClass(m_durationConstraint_Class, DURATIONCONSTRAINT_ATTRIBUTE_FIRSTEVENT);
	
	
	m_durationConstraint_Operation_first_event_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_durationConstraint_Class, DURATIONCONSTRAINT_OPERATION_FIRST_EVENT_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	m_durationConstraint_Operation_has_one_or_two_constrainedElements_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_durationConstraint_Class, DURATIONCONSTRAINT_OPERATION_HAS_ONE_OR_TWO_CONSTRAINEDELEMENTS_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createDurationIntervalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_durationInterval_Class = factory->createEClass_in_EPackage(package, DURATIONINTERVAL_CLASS);
	
	
	
}

void UmlPackageImpl::createDurationObservationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_durationObservation_Class = factory->createEClass_in_EPackage(package, DURATIONOBSERVATION_CLASS);
	m_durationObservation_Attribute_firstEvent = factory->createEAttribute_in_EContainingClass(m_durationObservation_Class, DURATIONOBSERVATION_ATTRIBUTE_FIRSTEVENT);
	
	m_durationObservation_Attribute_event = factory->createEReference_in_EContainingClass(m_durationObservation_Class, DURATIONOBSERVATION_ATTRIBUTE_EVENT);
	
	m_durationObservation_Operation_first_event_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_durationObservation_Class, DURATIONOBSERVATION_OPERATION_FIRST_EVENT_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createElementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_element_Class = factory->createEClass_in_EPackage(package, ELEMENT_CLASS);
	
	m_element_Attribute_ownedComment = factory->createEReference_in_EContainingClass(m_element_Class, ELEMENT_ATTRIBUTE_OWNEDCOMMENT);
	m_element_Attribute_ownedElement = factory->createEReference_in_EContainingClass(m_element_Class, ELEMENT_ATTRIBUTE_OWNEDELEMENT);
	m_element_Attribute_owner = factory->createEReference_in_EContainingClass(m_element_Class, ELEMENT_ATTRIBUTE_OWNER);
	
	m_element_Operation_addKeyword_String = factory->createEOperation_in_EContainingClass(m_element_Class, ELEMENT_OPERATION_ADDKEYWORD_STRING);
	m_element_Operation_allOwnedElements = factory->createEOperation_in_EContainingClass(m_element_Class, ELEMENT_OPERATION_ALLOWNEDELEMENTS);
	m_element_Operation_applyStereotype_Stereotype = factory->createEOperation_in_EContainingClass(m_element_Class, ELEMENT_OPERATION_APPLYSTEREOTYPE_STEREOTYPE);
	m_element_Operation_container = factory->createEOperation_in_EContainingClass(m_element_Class, ELEMENT_OPERATION_CONTAINER);
	m_element_Operation_createEAnnotation_String = factory->createEOperation_in_EContainingClass(m_element_Class, ELEMENT_OPERATION_CREATEEANNOTATION_STRING);
	m_element_Operation_destroy = factory->createEOperation_in_EContainingClass(m_element_Class, ELEMENT_OPERATION_DESTROY);
	m_element_Operation_getApplicableStereotype_String = factory->createEOperation_in_EContainingClass(m_element_Class, ELEMENT_OPERATION_GETAPPLICABLESTEREOTYPE_STRING);
	m_element_Operation_getApplicableStereotypes = factory->createEOperation_in_EContainingClass(m_element_Class, ELEMENT_OPERATION_GETAPPLICABLESTEREOTYPES);
	m_element_Operation_getAppliedStereotype_String = factory->createEOperation_in_EContainingClass(m_element_Class, ELEMENT_OPERATION_GETAPPLIEDSTEREOTYPE_STRING);
	m_element_Operation_getAppliedStereotypes = factory->createEOperation_in_EContainingClass(m_element_Class, ELEMENT_OPERATION_GETAPPLIEDSTEREOTYPES);
	m_element_Operation_getAppliedSubstereotype_Stereotype_String = factory->createEOperation_in_EContainingClass(m_element_Class, ELEMENT_OPERATION_GETAPPLIEDSUBSTEREOTYPE_STEREOTYPE_STRING);
	m_element_Operation_getAppliedSubstereotypes_Stereotype = factory->createEOperation_in_EContainingClass(m_element_Class, ELEMENT_OPERATION_GETAPPLIEDSUBSTEREOTYPES_STEREOTYPE);
	m_element_Operation_getKeywords = factory->createEOperation_in_EContainingClass(m_element_Class, ELEMENT_OPERATION_GETKEYWORDS);
	m_element_Operation_getMetaClass = factory->createEOperation_in_EContainingClass(m_element_Class, ELEMENT_OPERATION_GETMETACLASS);
	m_element_Operation_getModel = factory->createEOperation_in_EContainingClass(m_element_Class, ELEMENT_OPERATION_GETMODEL);
	m_element_Operation_getNearestPackage = factory->createEOperation_in_EContainingClass(m_element_Class, ELEMENT_OPERATION_GETNEARESTPACKAGE);
	m_element_Operation_getRelationships = factory->createEOperation_in_EContainingClass(m_element_Class, ELEMENT_OPERATION_GETRELATIONSHIPS);
	m_element_Operation_getRelationships_EClass = factory->createEOperation_in_EContainingClass(m_element_Class, ELEMENT_OPERATION_GETRELATIONSHIPS_ECLASS);
	m_element_Operation_getRequiredStereotype_String = factory->createEOperation_in_EContainingClass(m_element_Class, ELEMENT_OPERATION_GETREQUIREDSTEREOTYPE_STRING);
	m_element_Operation_getRequiredStereotypes = factory->createEOperation_in_EContainingClass(m_element_Class, ELEMENT_OPERATION_GETREQUIREDSTEREOTYPES);
	m_element_Operation_getSourceDirectedRelationships = factory->createEOperation_in_EContainingClass(m_element_Class, ELEMENT_OPERATION_GETSOURCEDIRECTEDRELATIONSHIPS);
	m_element_Operation_getSourceDirectedRelationships_EClass = factory->createEOperation_in_EContainingClass(m_element_Class, ELEMENT_OPERATION_GETSOURCEDIRECTEDRELATIONSHIPS_ECLASS);
	m_element_Operation_getStereotypeApplication_Stereotype = factory->createEOperation_in_EContainingClass(m_element_Class, ELEMENT_OPERATION_GETSTEREOTYPEAPPLICATION_STEREOTYPE);
	m_element_Operation_getStereotypeApplications = factory->createEOperation_in_EContainingClass(m_element_Class, ELEMENT_OPERATION_GETSTEREOTYPEAPPLICATIONS);
	m_element_Operation_getTargetDirectedRelationships = factory->createEOperation_in_EContainingClass(m_element_Class, ELEMENT_OPERATION_GETTARGETDIRECTEDRELATIONSHIPS);
	m_element_Operation_getTargetDirectedRelationships_EClass = factory->createEOperation_in_EContainingClass(m_element_Class, ELEMENT_OPERATION_GETTARGETDIRECTEDRELATIONSHIPS_ECLASS);
	m_element_Operation_getValue_Stereotype_String = factory->createEOperation_in_EContainingClass(m_element_Class, ELEMENT_OPERATION_GETVALUE_STEREOTYPE_STRING);
	m_element_Operation_hasKeyword_String = factory->createEOperation_in_EContainingClass(m_element_Class, ELEMENT_OPERATION_HASKEYWORD_STRING);
	m_element_Operation_hasValue_Stereotype_String = factory->createEOperation_in_EContainingClass(m_element_Class, ELEMENT_OPERATION_HASVALUE_STEREOTYPE_STRING);
	m_element_Operation_has_owner_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_element_Class, ELEMENT_OPERATION_HAS_OWNER_EDIAGNOSTICCHAIN_EMAP);
	m_element_Operation_isStereotypeApplicable_Stereotype = factory->createEOperation_in_EContainingClass(m_element_Class, ELEMENT_OPERATION_ISSTEREOTYPEAPPLICABLE_STEREOTYPE);
	m_element_Operation_isStereotypeApplied_Stereotype = factory->createEOperation_in_EContainingClass(m_element_Class, ELEMENT_OPERATION_ISSTEREOTYPEAPPLIED_STEREOTYPE);
	m_element_Operation_isStereotypeRequired_Stereotype = factory->createEOperation_in_EContainingClass(m_element_Class, ELEMENT_OPERATION_ISSTEREOTYPEREQUIRED_STEREOTYPE);
	m_element_Operation_mustBeOwned = factory->createEOperation_in_EContainingClass(m_element_Class, ELEMENT_OPERATION_MUSTBEOWNED);
	m_element_Operation_not_own_self_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_element_Class, ELEMENT_OPERATION_NOT_OWN_SELF_EDIAGNOSTICCHAIN_EMAP);
	m_element_Operation_removeKeyword_String = factory->createEOperation_in_EContainingClass(m_element_Class, ELEMENT_OPERATION_REMOVEKEYWORD_STRING);
	m_element_Operation_setValue_Stereotype_EJavaObject = factory->createEOperation_in_EContainingClass(m_element_Class, ELEMENT_OPERATION_SETVALUE_STEREOTYPE_EJAVAOBJECT);
	m_element_Operation_unapplyStereotype_Stereotype = factory->createEOperation_in_EContainingClass(m_element_Class, ELEMENT_OPERATION_UNAPPLYSTEREOTYPE_STEREOTYPE);
	
}

void UmlPackageImpl::createElementImportContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_elementImport_Class = factory->createEClass_in_EPackage(package, ELEMENTIMPORT_CLASS);
	m_elementImport_Attribute_alias = factory->createEAttribute_in_EContainingClass(m_elementImport_Class, ELEMENTIMPORT_ATTRIBUTE_ALIAS);
	m_elementImport_Attribute_visibility = factory->createEAttribute_in_EContainingClass(m_elementImport_Class, ELEMENTIMPORT_ATTRIBUTE_VISIBILITY);
	
	m_elementImport_Attribute_importedElement = factory->createEReference_in_EContainingClass(m_elementImport_Class, ELEMENTIMPORT_ATTRIBUTE_IMPORTEDELEMENT);
	m_elementImport_Attribute_importingNamespace = factory->createEReference_in_EContainingClass(m_elementImport_Class, ELEMENTIMPORT_ATTRIBUTE_IMPORTINGNAMESPACE);
	
	m_elementImport_Operation_getName = factory->createEOperation_in_EContainingClass(m_elementImport_Class, ELEMENTIMPORT_OPERATION_GETNAME);
	m_elementImport_Operation_imported_element_is_public_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_elementImport_Class, ELEMENTIMPORT_OPERATION_IMPORTED_ELEMENT_IS_PUBLIC_EDIAGNOSTICCHAIN_EMAP);
	m_elementImport_Operation_visibility_public_or_private_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_elementImport_Class, ELEMENTIMPORT_OPERATION_VISIBILITY_PUBLIC_OR_PRIVATE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createEncapsulatedClassifierContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_encapsulatedClassifier_Class = factory->createEClass_in_EPackage(package, ENCAPSULATEDCLASSIFIER_CLASS);
	
	m_encapsulatedClassifier_Attribute_ownedPort = factory->createEReference_in_EContainingClass(m_encapsulatedClassifier_Class, ENCAPSULATEDCLASSIFIER_ATTRIBUTE_OWNEDPORT);
	
	m_encapsulatedClassifier_Operation_getOwnedPorts = factory->createEOperation_in_EContainingClass(m_encapsulatedClassifier_Class, ENCAPSULATEDCLASSIFIER_OPERATION_GETOWNEDPORTS);
	
}

void UmlPackageImpl::createEnumerationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_enumeration_Class = factory->createEClass_in_EPackage(package, ENUMERATION_CLASS);
	
	m_enumeration_Attribute_ownedLiteral = factory->createEReference_in_EContainingClass(m_enumeration_Class, ENUMERATION_ATTRIBUTE_OWNEDLITERAL);
	
	m_enumeration_Operation_immutable_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_enumeration_Class, ENUMERATION_OPERATION_IMMUTABLE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createEnumerationLiteralContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_enumerationLiteral_Class = factory->createEClass_in_EPackage(package, ENUMERATIONLITERAL_CLASS);
	
	m_enumerationLiteral_Attribute_enumeration = factory->createEReference_in_EContainingClass(m_enumerationLiteral_Class, ENUMERATIONLITERAL_ATTRIBUTE_ENUMERATION);
	
	m_enumerationLiteral_Operation_getClassifier = factory->createEOperation_in_EContainingClass(m_enumerationLiteral_Class, ENUMERATIONLITERAL_OPERATION_GETCLASSIFIER);
	m_enumerationLiteral_Operation_getClassifiers = factory->createEOperation_in_EContainingClass(m_enumerationLiteral_Class, ENUMERATIONLITERAL_OPERATION_GETCLASSIFIERS);
	
}

void UmlPackageImpl::createEventContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_event_Class = factory->createEClass_in_EPackage(package, EVENT_CLASS);
	
	
	
}

void UmlPackageImpl::createExceptionHandlerContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_exceptionHandler_Class = factory->createEClass_in_EPackage(package, EXCEPTIONHANDLER_CLASS);
	
	m_exceptionHandler_Attribute_exceptionInput = factory->createEReference_in_EContainingClass(m_exceptionHandler_Class, EXCEPTIONHANDLER_ATTRIBUTE_EXCEPTIONINPUT);
	m_exceptionHandler_Attribute_exceptionType = factory->createEReference_in_EContainingClass(m_exceptionHandler_Class, EXCEPTIONHANDLER_ATTRIBUTE_EXCEPTIONTYPE);
	m_exceptionHandler_Attribute_handlerBody = factory->createEReference_in_EContainingClass(m_exceptionHandler_Class, EXCEPTIONHANDLER_ATTRIBUTE_HANDLERBODY);
	m_exceptionHandler_Attribute_protectedNode = factory->createEReference_in_EContainingClass(m_exceptionHandler_Class, EXCEPTIONHANDLER_ATTRIBUTE_PROTECTEDNODE);
	
	m_exceptionHandler_Operation_edge_source_target_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_exceptionHandler_Class, EXCEPTIONHANDLER_OPERATION_EDGE_SOURCE_TARGET_EDIAGNOSTICCHAIN_EMAP);
	m_exceptionHandler_Operation_exception_input_type_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_exceptionHandler_Class, EXCEPTIONHANDLER_OPERATION_EXCEPTION_INPUT_TYPE_EDIAGNOSTICCHAIN_EMAP);
	m_exceptionHandler_Operation_handler_body_edges_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_exceptionHandler_Class, EXCEPTIONHANDLER_OPERATION_HANDLER_BODY_EDGES_EDIAGNOSTICCHAIN_EMAP);
	m_exceptionHandler_Operation_handler_body_owner_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_exceptionHandler_Class, EXCEPTIONHANDLER_OPERATION_HANDLER_BODY_OWNER_EDIAGNOSTICCHAIN_EMAP);
	m_exceptionHandler_Operation_one_input_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_exceptionHandler_Class, EXCEPTIONHANDLER_OPERATION_ONE_INPUT_EDIAGNOSTICCHAIN_EMAP);
	m_exceptionHandler_Operation_output_pins_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_exceptionHandler_Class, EXCEPTIONHANDLER_OPERATION_OUTPUT_PINS_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createExecutableNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_executableNode_Class = factory->createEClass_in_EPackage(package, EXECUTABLENODE_CLASS);
	
	m_executableNode_Attribute_handler = factory->createEReference_in_EContainingClass(m_executableNode_Class, EXECUTABLENODE_ATTRIBUTE_HANDLER);
	
	
}

void UmlPackageImpl::createExecutionEnvironmentContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_executionEnvironment_Class = factory->createEClass_in_EPackage(package, EXECUTIONENVIRONMENT_CLASS);
	
	
	
}

void UmlPackageImpl::createExecutionOccurrenceSpecificationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_executionOccurrenceSpecification_Class = factory->createEClass_in_EPackage(package, EXECUTIONOCCURRENCESPECIFICATION_CLASS);
	
	m_executionOccurrenceSpecification_Attribute_execution = factory->createEReference_in_EContainingClass(m_executionOccurrenceSpecification_Class, EXECUTIONOCCURRENCESPECIFICATION_ATTRIBUTE_EXECUTION);
	
	
}

void UmlPackageImpl::createExecutionSpecificationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_executionSpecification_Class = factory->createEClass_in_EPackage(package, EXECUTIONSPECIFICATION_CLASS);
	
	m_executionSpecification_Attribute_finish = factory->createEReference_in_EContainingClass(m_executionSpecification_Class, EXECUTIONSPECIFICATION_ATTRIBUTE_FINISH);
	m_executionSpecification_Attribute_start = factory->createEReference_in_EContainingClass(m_executionSpecification_Class, EXECUTIONSPECIFICATION_ATTRIBUTE_START);
	
	m_executionSpecification_Operation_same_lifeline_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_executionSpecification_Class, EXECUTIONSPECIFICATION_OPERATION_SAME_LIFELINE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createExpansionNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_expansionNode_Class = factory->createEClass_in_EPackage(package, EXPANSIONNODE_CLASS);
	
	m_expansionNode_Attribute_regionAsInput = factory->createEReference_in_EContainingClass(m_expansionNode_Class, EXPANSIONNODE_ATTRIBUTE_REGIONASINPUT);
	m_expansionNode_Attribute_regionAsOutput = factory->createEReference_in_EContainingClass(m_expansionNode_Class, EXPANSIONNODE_ATTRIBUTE_REGIONASOUTPUT);
	
	m_expansionNode_Operation_region_as_input_or_output_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_expansionNode_Class, EXPANSIONNODE_OPERATION_REGION_AS_INPUT_OR_OUTPUT_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createExpansionRegionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_expansionRegion_Class = factory->createEClass_in_EPackage(package, EXPANSIONREGION_CLASS);
	m_expansionRegion_Attribute_mode = factory->createEAttribute_in_EContainingClass(m_expansionRegion_Class, EXPANSIONREGION_ATTRIBUTE_MODE);
	
	m_expansionRegion_Attribute_inputElement = factory->createEReference_in_EContainingClass(m_expansionRegion_Class, EXPANSIONREGION_ATTRIBUTE_INPUTELEMENT);
	m_expansionRegion_Attribute_outputElement = factory->createEReference_in_EContainingClass(m_expansionRegion_Class, EXPANSIONREGION_ATTRIBUTE_OUTPUTELEMENT);
	
	
}

void UmlPackageImpl::createExpressionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_expression_Class = factory->createEClass_in_EPackage(package, EXPRESSION_CLASS);
	m_expression_Attribute_symbol = factory->createEAttribute_in_EContainingClass(m_expression_Class, EXPRESSION_ATTRIBUTE_SYMBOL);
	
	m_expression_Attribute_operand = factory->createEReference_in_EContainingClass(m_expression_Class, EXPRESSION_ATTRIBUTE_OPERAND);
	
	
}

void UmlPackageImpl::createExtendContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_extend_Class = factory->createEClass_in_EPackage(package, EXTEND_CLASS);
	
	m_extend_Attribute_condition = factory->createEReference_in_EContainingClass(m_extend_Class, EXTEND_ATTRIBUTE_CONDITION);
	m_extend_Attribute_extendedCase = factory->createEReference_in_EContainingClass(m_extend_Class, EXTEND_ATTRIBUTE_EXTENDEDCASE);
	m_extend_Attribute_extension = factory->createEReference_in_EContainingClass(m_extend_Class, EXTEND_ATTRIBUTE_EXTENSION);
	m_extend_Attribute_extensionLocation = factory->createEReference_in_EContainingClass(m_extend_Class, EXTEND_ATTRIBUTE_EXTENSIONLOCATION);
	
	m_extend_Operation_extension_points_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_extend_Class, EXTEND_OPERATION_EXTENSION_POINTS_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createExtensionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_extension_Class = factory->createEClass_in_EPackage(package, EXTENSION_CLASS);
	m_extension_Attribute_isRequired = factory->createEAttribute_in_EContainingClass(m_extension_Class, EXTENSION_ATTRIBUTE_ISREQUIRED);
	
	m_extension_Attribute_metaclass = factory->createEReference_in_EContainingClass(m_extension_Class, EXTENSION_ATTRIBUTE_METACLASS);
	
	m_extension_Operation_getMetaclass = factory->createEOperation_in_EContainingClass(m_extension_Class, EXTENSION_OPERATION_GETMETACLASS);
	m_extension_Operation_getStereotype = factory->createEOperation_in_EContainingClass(m_extension_Class, EXTENSION_OPERATION_GETSTEREOTYPE);
	m_extension_Operation_getStereotypeEnd = factory->createEOperation_in_EContainingClass(m_extension_Class, EXTENSION_OPERATION_GETSTEREOTYPEEND);
	m_extension_Operation_isRequired = factory->createEOperation_in_EContainingClass(m_extension_Class, EXTENSION_OPERATION_ISREQUIRED);
	m_extension_Operation_is_binary_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_extension_Class, EXTENSION_OPERATION_IS_BINARY_EDIAGNOSTICCHAIN_EMAP);
	m_extension_Operation_metaclassEnd = factory->createEOperation_in_EContainingClass(m_extension_Class, EXTENSION_OPERATION_METACLASSEND);
	m_extension_Operation_non_owned_end_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_extension_Class, EXTENSION_OPERATION_NON_OWNED_END_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createExtensionEndContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_extensionEnd_Class = factory->createEClass_in_EPackage(package, EXTENSIONEND_CLASS);
	
	
	m_extensionEnd_Operation_aggregation_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_extensionEnd_Class, EXTENSIONEND_OPERATION_AGGREGATION_EDIAGNOSTICCHAIN_EMAP);
	m_extensionEnd_Operation_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_extensionEnd_Class, EXTENSIONEND_OPERATION_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createExtensionPointContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_extensionPoint_Class = factory->createEClass_in_EPackage(package, EXTENSIONPOINT_CLASS);
	
	m_extensionPoint_Attribute_useCase = factory->createEReference_in_EContainingClass(m_extensionPoint_Class, EXTENSIONPOINT_ATTRIBUTE_USECASE);
	
	m_extensionPoint_Operation_must_have_name_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_extensionPoint_Class, EXTENSIONPOINT_OPERATION_MUST_HAVE_NAME_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createFactoryContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_factory_Class = factory->createEClass_in_EPackage(package, FACTORY_CLASS);
	
	
	m_factory_Operation_create_Class = factory->createEOperation_in_EContainingClass(m_factory_Class, FACTORY_OPERATION_CREATE_CLASS);
	
}

void UmlPackageImpl::createFeatureContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_feature_Class = factory->createEClass_in_EPackage(package, FEATURE_CLASS);
	m_feature_Attribute_isStatic = factory->createEAttribute_in_EContainingClass(m_feature_Class, FEATURE_ATTRIBUTE_ISSTATIC);
	
	m_feature_Attribute_featuringClassifier = factory->createEReference_in_EContainingClass(m_feature_Class, FEATURE_ATTRIBUTE_FEATURINGCLASSIFIER);
	
	
}

void UmlPackageImpl::createFinalNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_finalNode_Class = factory->createEClass_in_EPackage(package, FINALNODE_CLASS);
	
	
	m_finalNode_Operation_no_outgoing_edges_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_finalNode_Class, FINALNODE_OPERATION_NO_OUTGOING_EDGES_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createFinalStateContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_finalState_Class = factory->createEClass_in_EPackage(package, FINALSTATE_CLASS);
	
	
	m_finalState_Operation_cannot_reference_submachine_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_finalState_Class, FINALSTATE_OPERATION_CANNOT_REFERENCE_SUBMACHINE_EDIAGNOSTICCHAIN_EMAP);
	m_finalState_Operation_no_entry_behavior_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_finalState_Class, FINALSTATE_OPERATION_NO_ENTRY_BEHAVIOR_EDIAGNOSTICCHAIN_EMAP);
	m_finalState_Operation_no_exit_behavior_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_finalState_Class, FINALSTATE_OPERATION_NO_EXIT_BEHAVIOR_EDIAGNOSTICCHAIN_EMAP);
	m_finalState_Operation_no_outgoing_transitions_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_finalState_Class, FINALSTATE_OPERATION_NO_OUTGOING_TRANSITIONS_EDIAGNOSTICCHAIN_EMAP);
	m_finalState_Operation_no_regions_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_finalState_Class, FINALSTATE_OPERATION_NO_REGIONS_EDIAGNOSTICCHAIN_EMAP);
	m_finalState_Operation_no_state_behavior_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_finalState_Class, FINALSTATE_OPERATION_NO_STATE_BEHAVIOR_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createFlowFinalNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_flowFinalNode_Class = factory->createEClass_in_EPackage(package, FLOWFINALNODE_CLASS);
	
	
	
}

void UmlPackageImpl::createForkNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_forkNode_Class = factory->createEClass_in_EPackage(package, FORKNODE_CLASS);
	
	
	m_forkNode_Operation_edges_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_forkNode_Class, FORKNODE_OPERATION_EDGES_EDIAGNOSTICCHAIN_EMAP);
	m_forkNode_Operation_one_incoming_edge_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_forkNode_Class, FORKNODE_OPERATION_ONE_INCOMING_EDGE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createFunctionBehaviorContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_functionBehavior_Class = factory->createEClass_in_EPackage(package, FUNCTIONBEHAVIOR_CLASS);
	
	
	m_functionBehavior_Operation_hasAllDataTypeAttributes_DataType = factory->createEOperation_in_EContainingClass(m_functionBehavior_Class, FUNCTIONBEHAVIOR_OPERATION_HASALLDATATYPEATTRIBUTES_DATATYPE);
	m_functionBehavior_Operation_one_output_parameter_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_functionBehavior_Class, FUNCTIONBEHAVIOR_OPERATION_ONE_OUTPUT_PARAMETER_EDIAGNOSTICCHAIN_EMAP);
	m_functionBehavior_Operation_types_of_parameters_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_functionBehavior_Class, FUNCTIONBEHAVIOR_OPERATION_TYPES_OF_PARAMETERS_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createGateContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_gate_Class = factory->createEClass_in_EPackage(package, GATE_CLASS);
	
	
	m_gate_Operation_actual_gate_distinguishable_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_gate_Class, GATE_OPERATION_ACTUAL_GATE_DISTINGUISHABLE_EDIAGNOSTICCHAIN_EMAP);
	m_gate_Operation_actual_gate_matched_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_gate_Class, GATE_OPERATION_ACTUAL_GATE_MATCHED_EDIAGNOSTICCHAIN_EMAP);
	m_gate_Operation_formal_gate_distinguishable_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_gate_Class, GATE_OPERATION_FORMAL_GATE_DISTINGUISHABLE_EDIAGNOSTICCHAIN_EMAP);
	m_gate_Operation_getName = factory->createEOperation_in_EContainingClass(m_gate_Class, GATE_OPERATION_GETNAME);
	m_gate_Operation_getOperand = factory->createEOperation_in_EContainingClass(m_gate_Class, GATE_OPERATION_GETOPERAND);
	m_gate_Operation_inside_cf_gate_distinguishable_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_gate_Class, GATE_OPERATION_INSIDE_CF_GATE_DISTINGUISHABLE_EDIAGNOSTICCHAIN_EMAP);
	m_gate_Operation_inside_cf_matched_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_gate_Class, GATE_OPERATION_INSIDE_CF_MATCHED_EDIAGNOSTICCHAIN_EMAP);
	m_gate_Operation_isActual = factory->createEOperation_in_EContainingClass(m_gate_Class, GATE_OPERATION_ISACTUAL);
	m_gate_Operation_isFormal = factory->createEOperation_in_EContainingClass(m_gate_Class, GATE_OPERATION_ISFORMAL);
	m_gate_Operation_isInsideCF = factory->createEOperation_in_EContainingClass(m_gate_Class, GATE_OPERATION_ISINSIDECF);
	m_gate_Operation_isOutsideCF = factory->createEOperation_in_EContainingClass(m_gate_Class, GATE_OPERATION_ISOUTSIDECF);
	m_gate_Operation_matches_Gate = factory->createEOperation_in_EContainingClass(m_gate_Class, GATE_OPERATION_MATCHES_GATE);
	m_gate_Operation_outside_cf_gate_distinguishable_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_gate_Class, GATE_OPERATION_OUTSIDE_CF_GATE_DISTINGUISHABLE_EDIAGNOSTICCHAIN_EMAP);
	m_gate_Operation_outside_cf_matched_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_gate_Class, GATE_OPERATION_OUTSIDE_CF_MATCHED_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createGeneralOrderingContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_generalOrdering_Class = factory->createEClass_in_EPackage(package, GENERALORDERING_CLASS);
	
	m_generalOrdering_Attribute_after = factory->createEReference_in_EContainingClass(m_generalOrdering_Class, GENERALORDERING_ATTRIBUTE_AFTER);
	m_generalOrdering_Attribute_before = factory->createEReference_in_EContainingClass(m_generalOrdering_Class, GENERALORDERING_ATTRIBUTE_BEFORE);
	
	m_generalOrdering_Operation_irreflexive_transitive_closure_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_generalOrdering_Class, GENERALORDERING_OPERATION_IRREFLEXIVE_TRANSITIVE_CLOSURE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createGeneralizationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_generalization_Class = factory->createEClass_in_EPackage(package, GENERALIZATION_CLASS);
	m_generalization_Attribute_isSubstitutable = factory->createEAttribute_in_EContainingClass(m_generalization_Class, GENERALIZATION_ATTRIBUTE_ISSUBSTITUTABLE);
	
	m_generalization_Attribute_general = factory->createEReference_in_EContainingClass(m_generalization_Class, GENERALIZATION_ATTRIBUTE_GENERAL);
	m_generalization_Attribute_generalizationSet = factory->createEReference_in_EContainingClass(m_generalization_Class, GENERALIZATION_ATTRIBUTE_GENERALIZATIONSET);
	m_generalization_Attribute_specific = factory->createEReference_in_EContainingClass(m_generalization_Class, GENERALIZATION_ATTRIBUTE_SPECIFIC);
	
	
}

void UmlPackageImpl::createGeneralizationSetContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_generalizationSet_Class = factory->createEClass_in_EPackage(package, GENERALIZATIONSET_CLASS);
	m_generalizationSet_Attribute_isCovering = factory->createEAttribute_in_EContainingClass(m_generalizationSet_Class, GENERALIZATIONSET_ATTRIBUTE_ISCOVERING);
	m_generalizationSet_Attribute_isDisjoint = factory->createEAttribute_in_EContainingClass(m_generalizationSet_Class, GENERALIZATIONSET_ATTRIBUTE_ISDISJOINT);
	
	m_generalizationSet_Attribute_generalization = factory->createEReference_in_EContainingClass(m_generalizationSet_Class, GENERALIZATIONSET_ATTRIBUTE_GENERALIZATION);
	m_generalizationSet_Attribute_powertype = factory->createEReference_in_EContainingClass(m_generalizationSet_Class, GENERALIZATIONSET_ATTRIBUTE_POWERTYPE);
	
	m_generalizationSet_Operation_generalization_same_classifier_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_generalizationSet_Class, GENERALIZATIONSET_OPERATION_GENERALIZATION_SAME_CLASSIFIER_EDIAGNOSTICCHAIN_EMAP);
	m_generalizationSet_Operation_maps_to_generalization_set_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_generalizationSet_Class, GENERALIZATIONSET_OPERATION_MAPS_TO_GENERALIZATION_SET_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createImageContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_image_Class = factory->createEClass_in_EPackage(package, IMAGE_CLASS);
	m_image_Attribute_content = factory->createEAttribute_in_EContainingClass(m_image_Class, IMAGE_ATTRIBUTE_CONTENT);
	m_image_Attribute_format = factory->createEAttribute_in_EContainingClass(m_image_Class, IMAGE_ATTRIBUTE_FORMAT);
	m_image_Attribute_location = factory->createEAttribute_in_EContainingClass(m_image_Class, IMAGE_ATTRIBUTE_LOCATION);
	
	
	
}

void UmlPackageImpl::createIncludeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_include_Class = factory->createEClass_in_EPackage(package, INCLUDE_CLASS);
	
	m_include_Attribute_addition = factory->createEReference_in_EContainingClass(m_include_Class, INCLUDE_ATTRIBUTE_ADDITION);
	m_include_Attribute_includingCase = factory->createEReference_in_EContainingClass(m_include_Class, INCLUDE_ATTRIBUTE_INCLUDINGCASE);
	
	
}

void UmlPackageImpl::createInformationFlowContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_informationFlow_Class = factory->createEClass_in_EPackage(package, INFORMATIONFLOW_CLASS);
	
	m_informationFlow_Attribute_conveyed = factory->createEReference_in_EContainingClass(m_informationFlow_Class, INFORMATIONFLOW_ATTRIBUTE_CONVEYED);
	m_informationFlow_Attribute_informationSource = factory->createEReference_in_EContainingClass(m_informationFlow_Class, INFORMATIONFLOW_ATTRIBUTE_INFORMATIONSOURCE);
	m_informationFlow_Attribute_informationTarget = factory->createEReference_in_EContainingClass(m_informationFlow_Class, INFORMATIONFLOW_ATTRIBUTE_INFORMATIONTARGET);
	m_informationFlow_Attribute_realization = factory->createEReference_in_EContainingClass(m_informationFlow_Class, INFORMATIONFLOW_ATTRIBUTE_REALIZATION);
	m_informationFlow_Attribute_realizingActivityEdge = factory->createEReference_in_EContainingClass(m_informationFlow_Class, INFORMATIONFLOW_ATTRIBUTE_REALIZINGACTIVITYEDGE);
	m_informationFlow_Attribute_realizingConnector = factory->createEReference_in_EContainingClass(m_informationFlow_Class, INFORMATIONFLOW_ATTRIBUTE_REALIZINGCONNECTOR);
	m_informationFlow_Attribute_realizingMessage = factory->createEReference_in_EContainingClass(m_informationFlow_Class, INFORMATIONFLOW_ATTRIBUTE_REALIZINGMESSAGE);
	
	m_informationFlow_Operation_convey_classifiers_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_informationFlow_Class, INFORMATIONFLOW_OPERATION_CONVEY_CLASSIFIERS_EDIAGNOSTICCHAIN_EMAP);
	m_informationFlow_Operation_must_conform_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_informationFlow_Class, INFORMATIONFLOW_OPERATION_MUST_CONFORM_EDIAGNOSTICCHAIN_EMAP);
	m_informationFlow_Operation_sources_and_targets_kind_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_informationFlow_Class, INFORMATIONFLOW_OPERATION_SOURCES_AND_TARGETS_KIND_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createInformationItemContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_informationItem_Class = factory->createEClass_in_EPackage(package, INFORMATIONITEM_CLASS);
	
	m_informationItem_Attribute_represented = factory->createEReference_in_EContainingClass(m_informationItem_Class, INFORMATIONITEM_ATTRIBUTE_REPRESENTED);
	
	m_informationItem_Operation_has_no_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_informationItem_Class, INFORMATIONITEM_OPERATION_HAS_NO_EDIAGNOSTICCHAIN_EMAP);
	m_informationItem_Operation_not_instantiable_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_informationItem_Class, INFORMATIONITEM_OPERATION_NOT_INSTANTIABLE_EDIAGNOSTICCHAIN_EMAP);
	m_informationItem_Operation_sources_and_targets_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_informationItem_Class, INFORMATIONITEM_OPERATION_SOURCES_AND_TARGETS_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createInitialNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_initialNode_Class = factory->createEClass_in_EPackage(package, INITIALNODE_CLASS);
	
	
	m_initialNode_Operation_control_edges_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_initialNode_Class, INITIALNODE_OPERATION_CONTROL_EDGES_EDIAGNOSTICCHAIN_EMAP);
	m_initialNode_Operation_no_incoming_edges_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_initialNode_Class, INITIALNODE_OPERATION_NO_INCOMING_EDGES_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createInputPinContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_inputPin_Class = factory->createEClass_in_EPackage(package, INPUTPIN_CLASS);
	
	m_inputPin_Attribute_action = factory->createEReference_in_EContainingClass(m_inputPin_Class, INPUTPIN_ATTRIBUTE_ACTION);
	m_inputPin_Attribute_callOperationAction = factory->createEReference_in_EContainingClass(m_inputPin_Class, INPUTPIN_ATTRIBUTE_CALLOPERATIONACTION);
	m_inputPin_Attribute_invocationAction = factory->createEReference_in_EContainingClass(m_inputPin_Class, INPUTPIN_ATTRIBUTE_INVOCATIONACTION);
	m_inputPin_Attribute_structuralFeatureAction = factory->createEReference_in_EContainingClass(m_inputPin_Class, INPUTPIN_ATTRIBUTE_STRUCTURALFEATUREACTION);
	
	m_inputPin_Operation_outgoing_edges_structured_only_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_inputPin_Class, INPUTPIN_OPERATION_OUTGOING_EDGES_STRUCTURED_ONLY_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createInstanceSpecificationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_instanceSpecification_Class = factory->createEClass_in_EPackage(package, INSTANCESPECIFICATION_CLASS);
	
	m_instanceSpecification_Attribute_classifier = factory->createEReference_in_EContainingClass(m_instanceSpecification_Class, INSTANCESPECIFICATION_ATTRIBUTE_CLASSIFIER);
	m_instanceSpecification_Attribute_slot = factory->createEReference_in_EContainingClass(m_instanceSpecification_Class, INSTANCESPECIFICATION_ATTRIBUTE_SLOT);
	m_instanceSpecification_Attribute_specification = factory->createEReference_in_EContainingClass(m_instanceSpecification_Class, INSTANCESPECIFICATION_ATTRIBUTE_SPECIFICATION);
	
	m_instanceSpecification_Operation_defining_feature_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_instanceSpecification_Class, INSTANCESPECIFICATION_OPERATION_DEFINING_FEATURE_EDIAGNOSTICCHAIN_EMAP);
	m_instanceSpecification_Operation_deployment_artifact_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_instanceSpecification_Class, INSTANCESPECIFICATION_OPERATION_DEPLOYMENT_ARTIFACT_EDIAGNOSTICCHAIN_EMAP);
	m_instanceSpecification_Operation_deployment_target_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_instanceSpecification_Class, INSTANCESPECIFICATION_OPERATION_DEPLOYMENT_TARGET_EDIAGNOSTICCHAIN_EMAP);
	m_instanceSpecification_Operation_structural_feature_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_instanceSpecification_Class, INSTANCESPECIFICATION_OPERATION_STRUCTURAL_FEATURE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createInstanceValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_instanceValue_Class = factory->createEClass_in_EPackage(package, INSTANCEVALUE_CLASS);
	
	m_instanceValue_Attribute_instance = factory->createEReference_in_EContainingClass(m_instanceValue_Class, INSTANCEVALUE_ATTRIBUTE_INSTANCE);
	
	
}

void UmlPackageImpl::createInteractionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_interaction_Class = factory->createEClass_in_EPackage(package, INTERACTION_CLASS);
	
	m_interaction_Attribute_action = factory->createEReference_in_EContainingClass(m_interaction_Class, INTERACTION_ATTRIBUTE_ACTION);
	m_interaction_Attribute_formalGate = factory->createEReference_in_EContainingClass(m_interaction_Class, INTERACTION_ATTRIBUTE_FORMALGATE);
	m_interaction_Attribute_fragment = factory->createEReference_in_EContainingClass(m_interaction_Class, INTERACTION_ATTRIBUTE_FRAGMENT);
	m_interaction_Attribute_lifeline = factory->createEReference_in_EContainingClass(m_interaction_Class, INTERACTION_ATTRIBUTE_LIFELINE);
	m_interaction_Attribute_message = factory->createEReference_in_EContainingClass(m_interaction_Class, INTERACTION_ATTRIBUTE_MESSAGE);
	
	m_interaction_Operation_not_contained_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_interaction_Class, INTERACTION_OPERATION_NOT_CONTAINED_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createInteractionConstraintContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_interactionConstraint_Class = factory->createEClass_in_EPackage(package, INTERACTIONCONSTRAINT_CLASS);
	
	m_interactionConstraint_Attribute_maxint = factory->createEReference_in_EContainingClass(m_interactionConstraint_Class, INTERACTIONCONSTRAINT_ATTRIBUTE_MAXINT);
	m_interactionConstraint_Attribute_minint = factory->createEReference_in_EContainingClass(m_interactionConstraint_Class, INTERACTIONCONSTRAINT_ATTRIBUTE_MININT);
	
	m_interactionConstraint_Operation_dynamic_variables_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_interactionConstraint_Class, INTERACTIONCONSTRAINT_OPERATION_DYNAMIC_VARIABLES_EDIAGNOSTICCHAIN_EMAP);
	m_interactionConstraint_Operation_global_data_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_interactionConstraint_Class, INTERACTIONCONSTRAINT_OPERATION_GLOBAL_DATA_EDIAGNOSTICCHAIN_EMAP);
	m_interactionConstraint_Operation_maxint_greater_equal_minint_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_interactionConstraint_Class, INTERACTIONCONSTRAINT_OPERATION_MAXINT_GREATER_EQUAL_MININT_EDIAGNOSTICCHAIN_EMAP);
	m_interactionConstraint_Operation_maxint_positive_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_interactionConstraint_Class, INTERACTIONCONSTRAINT_OPERATION_MAXINT_POSITIVE_EDIAGNOSTICCHAIN_EMAP);
	m_interactionConstraint_Operation_minint_maxint_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_interactionConstraint_Class, INTERACTIONCONSTRAINT_OPERATION_MININT_MAXINT_EDIAGNOSTICCHAIN_EMAP);
	m_interactionConstraint_Operation_minint_non_negative_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_interactionConstraint_Class, INTERACTIONCONSTRAINT_OPERATION_MININT_NON_NEGATIVE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createInteractionFragmentContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_interactionFragment_Class = factory->createEClass_in_EPackage(package, INTERACTIONFRAGMENT_CLASS);
	
	m_interactionFragment_Attribute_covered = factory->createEReference_in_EContainingClass(m_interactionFragment_Class, INTERACTIONFRAGMENT_ATTRIBUTE_COVERED);
	m_interactionFragment_Attribute_enclosingInteraction = factory->createEReference_in_EContainingClass(m_interactionFragment_Class, INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGINTERACTION);
	m_interactionFragment_Attribute_enclosingOperand = factory->createEReference_in_EContainingClass(m_interactionFragment_Class, INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGOPERAND);
	m_interactionFragment_Attribute_generalOrdering = factory->createEReference_in_EContainingClass(m_interactionFragment_Class, INTERACTIONFRAGMENT_ATTRIBUTE_GENERALORDERING);
	
	
}

void UmlPackageImpl::createInteractionOperandContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_interactionOperand_Class = factory->createEClass_in_EPackage(package, INTERACTIONOPERAND_CLASS);
	
	m_interactionOperand_Attribute_fragment = factory->createEReference_in_EContainingClass(m_interactionOperand_Class, INTERACTIONOPERAND_ATTRIBUTE_FRAGMENT);
	m_interactionOperand_Attribute_guard = factory->createEReference_in_EContainingClass(m_interactionOperand_Class, INTERACTIONOPERAND_ATTRIBUTE_GUARD);
	
	m_interactionOperand_Operation_guard_contain_references_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_interactionOperand_Class, INTERACTIONOPERAND_OPERATION_GUARD_CONTAIN_REFERENCES_EDIAGNOSTICCHAIN_EMAP);
	m_interactionOperand_Operation_guard_directly_prior_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_interactionOperand_Class, INTERACTIONOPERAND_OPERATION_GUARD_DIRECTLY_PRIOR_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createInteractionUseContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_interactionUse_Class = factory->createEClass_in_EPackage(package, INTERACTIONUSE_CLASS);
	
	m_interactionUse_Attribute_actualGate = factory->createEReference_in_EContainingClass(m_interactionUse_Class, INTERACTIONUSE_ATTRIBUTE_ACTUALGATE);
	m_interactionUse_Attribute_argument = factory->createEReference_in_EContainingClass(m_interactionUse_Class, INTERACTIONUSE_ATTRIBUTE_ARGUMENT);
	m_interactionUse_Attribute_refersTo = factory->createEReference_in_EContainingClass(m_interactionUse_Class, INTERACTIONUSE_ATTRIBUTE_REFERSTO);
	m_interactionUse_Attribute_returnValue = factory->createEReference_in_EContainingClass(m_interactionUse_Class, INTERACTIONUSE_ATTRIBUTE_RETURNVALUE);
	m_interactionUse_Attribute_returnValueRecipient = factory->createEReference_in_EContainingClass(m_interactionUse_Class, INTERACTIONUSE_ATTRIBUTE_RETURNVALUERECIPIENT);
	
	m_interactionUse_Operation_all_lifelines_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_interactionUse_Class, INTERACTIONUSE_OPERATION_ALL_LIFELINES_EDIAGNOSTICCHAIN_EMAP);
	m_interactionUse_Operation_arguments_are_constants_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_interactionUse_Class, INTERACTIONUSE_OPERATION_ARGUMENTS_ARE_CONSTANTS_EDIAGNOSTICCHAIN_EMAP);
	m_interactionUse_Operation_arguments_correspond_to_parameters_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_interactionUse_Class, INTERACTIONUSE_OPERATION_ARGUMENTS_CORRESPOND_TO_PARAMETERS_EDIAGNOSTICCHAIN_EMAP);
	m_interactionUse_Operation_gates_match_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_interactionUse_Class, INTERACTIONUSE_OPERATION_GATES_MATCH_EDIAGNOSTICCHAIN_EMAP);
	m_interactionUse_Operation_returnValueRecipient_coverage_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_interactionUse_Class, INTERACTIONUSE_OPERATION_RETURNVALUERECIPIENT_COVERAGE_EDIAGNOSTICCHAIN_EMAP);
	m_interactionUse_Operation_returnValue_type_recipient_correspondence_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_interactionUse_Class, INTERACTIONUSE_OPERATION_RETURNVALUE_TYPE_RECIPIENT_CORRESPONDENCE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createInterfaceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_interface_Class = factory->createEClass_in_EPackage(package, INTERFACE_CLASS);
	
	m_interface_Attribute_nestedClassifier = factory->createEReference_in_EContainingClass(m_interface_Class, INTERFACE_ATTRIBUTE_NESTEDCLASSIFIER);
	m_interface_Attribute_ownedAttribute = factory->createEReference_in_EContainingClass(m_interface_Class, INTERFACE_ATTRIBUTE_OWNEDATTRIBUTE);
	m_interface_Attribute_ownedOperation = factory->createEReference_in_EContainingClass(m_interface_Class, INTERFACE_ATTRIBUTE_OWNEDOPERATION);
	m_interface_Attribute_ownedReception = factory->createEReference_in_EContainingClass(m_interface_Class, INTERFACE_ATTRIBUTE_OWNEDRECEPTION);
	m_interface_Attribute_protocol = factory->createEReference_in_EContainingClass(m_interface_Class, INTERFACE_ATTRIBUTE_PROTOCOL);
	m_interface_Attribute_redefinedInterface = factory->createEReference_in_EContainingClass(m_interface_Class, INTERFACE_ATTRIBUTE_REDEFINEDINTERFACE);
	
	m_interface_Operation_createOwnedAttribute_String_UnlimitedNatural = factory->createEOperation_in_EContainingClass(m_interface_Class, INTERFACE_OPERATION_CREATEOWNEDATTRIBUTE_STRING_UNLIMITEDNATURAL);
	m_interface_Operation_createOwnedOperation_String_Type = factory->createEOperation_in_EContainingClass(m_interface_Class, INTERFACE_OPERATION_CREATEOWNEDOPERATION_STRING_TYPE);
	m_interface_Operation_visibility_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_interface_Class, INTERFACE_OPERATION_VISIBILITY_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createInterfaceRealizationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_interfaceRealization_Class = factory->createEClass_in_EPackage(package, INTERFACEREALIZATION_CLASS);
	
	m_interfaceRealization_Attribute_contract = factory->createEReference_in_EContainingClass(m_interfaceRealization_Class, INTERFACEREALIZATION_ATTRIBUTE_CONTRACT);
	m_interfaceRealization_Attribute_implementingClassifier = factory->createEReference_in_EContainingClass(m_interfaceRealization_Class, INTERFACEREALIZATION_ATTRIBUTE_IMPLEMENTINGCLASSIFIER);
	
	
}

void UmlPackageImpl::createInterruptibleActivityRegionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_interruptibleActivityRegion_Class = factory->createEClass_in_EPackage(package, INTERRUPTIBLEACTIVITYREGION_CLASS);
	
	m_interruptibleActivityRegion_Attribute_interruptingEdge = factory->createEReference_in_EContainingClass(m_interruptibleActivityRegion_Class, INTERRUPTIBLEACTIVITYREGION_ATTRIBUTE_INTERRUPTINGEDGE);
	m_interruptibleActivityRegion_Attribute_node = factory->createEReference_in_EContainingClass(m_interruptibleActivityRegion_Class, INTERRUPTIBLEACTIVITYREGION_ATTRIBUTE_NODE);
	
	m_interruptibleActivityRegion_Operation_interrupting_edges_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_interruptibleActivityRegion_Class, INTERRUPTIBLEACTIVITYREGION_OPERATION_INTERRUPTING_EDGES_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createIntervalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_interval_Class = factory->createEClass_in_EPackage(package, INTERVAL_CLASS);
	
	m_interval_Attribute_max = factory->createEReference_in_EContainingClass(m_interval_Class, INTERVAL_ATTRIBUTE_MAX);
	m_interval_Attribute_min = factory->createEReference_in_EContainingClass(m_interval_Class, INTERVAL_ATTRIBUTE_MIN);
	
	
}

void UmlPackageImpl::createIntervalConstraintContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_intervalConstraint_Class = factory->createEClass_in_EPackage(package, INTERVALCONSTRAINT_CLASS);
	
	
	
}

void UmlPackageImpl::createInvocationActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_invocationAction_Class = factory->createEClass_in_EPackage(package, INVOCATIONACTION_CLASS);
	
	m_invocationAction_Attribute_argument = factory->createEReference_in_EContainingClass(m_invocationAction_Class, INVOCATIONACTION_ATTRIBUTE_ARGUMENT);
	m_invocationAction_Attribute_onPort = factory->createEReference_in_EContainingClass(m_invocationAction_Class, INVOCATIONACTION_ATTRIBUTE_ONPORT);
	
	
}

void UmlPackageImpl::createJoinNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_joinNode_Class = factory->createEClass_in_EPackage(package, JOINNODE_CLASS);
	m_joinNode_Attribute_isCombineDuplicate = factory->createEAttribute_in_EContainingClass(m_joinNode_Class, JOINNODE_ATTRIBUTE_ISCOMBINEDUPLICATE);
	
	m_joinNode_Attribute_joinSpec = factory->createEReference_in_EContainingClass(m_joinNode_Class, JOINNODE_ATTRIBUTE_JOINSPEC);
	
	m_joinNode_Operation_incoming_object_flow_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_joinNode_Class, JOINNODE_OPERATION_INCOMING_OBJECT_FLOW_EDIAGNOSTICCHAIN_EMAP);
	m_joinNode_Operation_one_outgoing_edge_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_joinNode_Class, JOINNODE_OPERATION_ONE_OUTGOING_EDGE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createLifelineContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_lifeline_Class = factory->createEClass_in_EPackage(package, LIFELINE_CLASS);
	
	m_lifeline_Attribute_coveredBy = factory->createEReference_in_EContainingClass(m_lifeline_Class, LIFELINE_ATTRIBUTE_COVEREDBY);
	m_lifeline_Attribute_decomposedAs = factory->createEReference_in_EContainingClass(m_lifeline_Class, LIFELINE_ATTRIBUTE_DECOMPOSEDAS);
	m_lifeline_Attribute_interaction = factory->createEReference_in_EContainingClass(m_lifeline_Class, LIFELINE_ATTRIBUTE_INTERACTION);
	m_lifeline_Attribute_represents = factory->createEReference_in_EContainingClass(m_lifeline_Class, LIFELINE_ATTRIBUTE_REPRESENTS);
	m_lifeline_Attribute_selector = factory->createEReference_in_EContainingClass(m_lifeline_Class, LIFELINE_ATTRIBUTE_SELECTOR);
	
	m_lifeline_Operation_interaction_uses_share_lifeline_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_lifeline_Class, LIFELINE_OPERATION_INTERACTION_USES_SHARE_LIFELINE_EDIAGNOSTICCHAIN_EMAP);
	m_lifeline_Operation_same_classifier_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_lifeline_Class, LIFELINE_OPERATION_SAME_CLASSIFIER_EDIAGNOSTICCHAIN_EMAP);
	m_lifeline_Operation_selector_int_or_string_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_lifeline_Class, LIFELINE_OPERATION_SELECTOR_INT_OR_STRING_EDIAGNOSTICCHAIN_EMAP);
	m_lifeline_Operation_selector_specified_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_lifeline_Class, LIFELINE_OPERATION_SELECTOR_SPECIFIED_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createLinkActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_linkAction_Class = factory->createEClass_in_EPackage(package, LINKACTION_CLASS);
	
	m_linkAction_Attribute_endData = factory->createEReference_in_EContainingClass(m_linkAction_Class, LINKACTION_ATTRIBUTE_ENDDATA);
	m_linkAction_Attribute_inputValue = factory->createEReference_in_EContainingClass(m_linkAction_Class, LINKACTION_ATTRIBUTE_INPUTVALUE);
	
	m_linkAction_Operation_association = factory->createEOperation_in_EContainingClass(m_linkAction_Class, LINKACTION_OPERATION_ASSOCIATION);
	m_linkAction_Operation_not_static_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_linkAction_Class, LINKACTION_OPERATION_NOT_STATIC_EDIAGNOSTICCHAIN_EMAP);
	m_linkAction_Operation_same_association_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_linkAction_Class, LINKACTION_OPERATION_SAME_ASSOCIATION_EDIAGNOSTICCHAIN_EMAP);
	m_linkAction_Operation_same_pins_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_linkAction_Class, LINKACTION_OPERATION_SAME_PINS_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createLinkEndCreationDataContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_linkEndCreationData_Class = factory->createEClass_in_EPackage(package, LINKENDCREATIONDATA_CLASS);
	m_linkEndCreationData_Attribute_isReplaceAll = factory->createEAttribute_in_EContainingClass(m_linkEndCreationData_Class, LINKENDCREATIONDATA_ATTRIBUTE_ISREPLACEALL);
	
	m_linkEndCreationData_Attribute_insertAt = factory->createEReference_in_EContainingClass(m_linkEndCreationData_Class, LINKENDCREATIONDATA_ATTRIBUTE_INSERTAT);
	
	m_linkEndCreationData_Operation_insertAt_pin_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_linkEndCreationData_Class, LINKENDCREATIONDATA_OPERATION_INSERTAT_PIN_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createLinkEndDataContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_linkEndData_Class = factory->createEClass_in_EPackage(package, LINKENDDATA_CLASS);
	
	m_linkEndData_Attribute_end = factory->createEReference_in_EContainingClass(m_linkEndData_Class, LINKENDDATA_ATTRIBUTE_END);
	m_linkEndData_Attribute_qualifier = factory->createEReference_in_EContainingClass(m_linkEndData_Class, LINKENDDATA_ATTRIBUTE_QUALIFIER);
	m_linkEndData_Attribute_value = factory->createEReference_in_EContainingClass(m_linkEndData_Class, LINKENDDATA_ATTRIBUTE_VALUE);
	
	m_linkEndData_Operation_allPins = factory->createEOperation_in_EContainingClass(m_linkEndData_Class, LINKENDDATA_OPERATION_ALLPINS);
	m_linkEndData_Operation_end_object_input_pin_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_linkEndData_Class, LINKENDDATA_OPERATION_END_OBJECT_INPUT_PIN_EDIAGNOSTICCHAIN_EMAP);
	m_linkEndData_Operation_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_linkEndData_Class, LINKENDDATA_OPERATION_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	m_linkEndData_Operation_property_is_association_end_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_linkEndData_Class, LINKENDDATA_OPERATION_PROPERTY_IS_ASSOCIATION_END_EDIAGNOSTICCHAIN_EMAP);
	m_linkEndData_Operation_qualifiers_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_linkEndData_Class, LINKENDDATA_OPERATION_QUALIFIERS_EDIAGNOSTICCHAIN_EMAP);
	m_linkEndData_Operation_same_type_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_linkEndData_Class, LINKENDDATA_OPERATION_SAME_TYPE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createLinkEndDestructionDataContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_linkEndDestructionData_Class = factory->createEClass_in_EPackage(package, LINKENDDESTRUCTIONDATA_CLASS);
	m_linkEndDestructionData_Attribute_isDestroyDuplicates = factory->createEAttribute_in_EContainingClass(m_linkEndDestructionData_Class, LINKENDDESTRUCTIONDATA_ATTRIBUTE_ISDESTROYDUPLICATES);
	
	m_linkEndDestructionData_Attribute_destroyAt = factory->createEReference_in_EContainingClass(m_linkEndDestructionData_Class, LINKENDDESTRUCTIONDATA_ATTRIBUTE_DESTROYAT);
	
	m_linkEndDestructionData_Operation_destroyAt_pin_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_linkEndDestructionData_Class, LINKENDDESTRUCTIONDATA_OPERATION_DESTROYAT_PIN_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createLiteralBooleanContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_literalBoolean_Class = factory->createEClass_in_EPackage(package, LITERALBOOLEAN_CLASS);
	m_literalBoolean_Attribute_value = factory->createEAttribute_in_EContainingClass(m_literalBoolean_Class, LITERALBOOLEAN_ATTRIBUTE_VALUE);
	
	
	
}

void UmlPackageImpl::createLiteralIntegerContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_literalInteger_Class = factory->createEClass_in_EPackage(package, LITERALINTEGER_CLASS);
	m_literalInteger_Attribute_value = factory->createEAttribute_in_EContainingClass(m_literalInteger_Class, LITERALINTEGER_ATTRIBUTE_VALUE);
	
	
	
}

void UmlPackageImpl::createLiteralNullContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_literalNull_Class = factory->createEClass_in_EPackage(package, LITERALNULL_CLASS);
	
	
	
}

void UmlPackageImpl::createLiteralRealContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_literalReal_Class = factory->createEClass_in_EPackage(package, LITERALREAL_CLASS);
	m_literalReal_Attribute_value = factory->createEAttribute_in_EContainingClass(m_literalReal_Class, LITERALREAL_ATTRIBUTE_VALUE);
	
	
	
}

void UmlPackageImpl::createLiteralSpecificationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_literalSpecification_Class = factory->createEClass_in_EPackage(package, LITERALSPECIFICATION_CLASS);
	
	
	
}

void UmlPackageImpl::createLiteralStringContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_literalString_Class = factory->createEClass_in_EPackage(package, LITERALSTRING_CLASS);
	m_literalString_Attribute_value = factory->createEAttribute_in_EContainingClass(m_literalString_Class, LITERALSTRING_ATTRIBUTE_VALUE);
	
	
	
}

void UmlPackageImpl::createLiteralUnlimitedNaturalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_literalUnlimitedNatural_Class = factory->createEClass_in_EPackage(package, LITERALUNLIMITEDNATURAL_CLASS);
	m_literalUnlimitedNatural_Attribute_value = factory->createEAttribute_in_EContainingClass(m_literalUnlimitedNatural_Class, LITERALUNLIMITEDNATURAL_ATTRIBUTE_VALUE);
	
	
	
}

void UmlPackageImpl::createLoopNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_loopNode_Class = factory->createEClass_in_EPackage(package, LOOPNODE_CLASS);
	m_loopNode_Attribute_isTestedFirst = factory->createEAttribute_in_EContainingClass(m_loopNode_Class, LOOPNODE_ATTRIBUTE_ISTESTEDFIRST);
	
	m_loopNode_Attribute_bodyOutput = factory->createEReference_in_EContainingClass(m_loopNode_Class, LOOPNODE_ATTRIBUTE_BODYOUTPUT);
	m_loopNode_Attribute_bodyPart = factory->createEReference_in_EContainingClass(m_loopNode_Class, LOOPNODE_ATTRIBUTE_BODYPART);
	m_loopNode_Attribute_decider = factory->createEReference_in_EContainingClass(m_loopNode_Class, LOOPNODE_ATTRIBUTE_DECIDER);
	m_loopNode_Attribute_loopVariable = factory->createEReference_in_EContainingClass(m_loopNode_Class, LOOPNODE_ATTRIBUTE_LOOPVARIABLE);
	m_loopNode_Attribute_loopVariableInput = factory->createEReference_in_EContainingClass(m_loopNode_Class, LOOPNODE_ATTRIBUTE_LOOPVARIABLEINPUT);
	m_loopNode_Attribute_result = factory->createEReference_in_EContainingClass(m_loopNode_Class, LOOPNODE_ATTRIBUTE_RESULT);
	m_loopNode_Attribute_setupPart = factory->createEReference_in_EContainingClass(m_loopNode_Class, LOOPNODE_ATTRIBUTE_SETUPPART);
	m_loopNode_Attribute_test = factory->createEReference_in_EContainingClass(m_loopNode_Class, LOOPNODE_ATTRIBUTE_TEST);
	
	m_loopNode_Operation_body_output_pins_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_loopNode_Class, LOOPNODE_OPERATION_BODY_OUTPUT_PINS_EDIAGNOSTICCHAIN_EMAP);
	m_loopNode_Operation_executable_nodes_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_loopNode_Class, LOOPNODE_OPERATION_EXECUTABLE_NODES_EDIAGNOSTICCHAIN_EMAP);
	m_loopNode_Operation_input_edges_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_loopNode_Class, LOOPNODE_OPERATION_INPUT_EDGES_EDIAGNOSTICCHAIN_EMAP);
	m_loopNode_Operation_loop_variable_outgoing_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_loopNode_Class, LOOPNODE_OPERATION_LOOP_VARIABLE_OUTGOING_EDIAGNOSTICCHAIN_EMAP);
	m_loopNode_Operation_matching_loop_variables_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_loopNode_Class, LOOPNODE_OPERATION_MATCHING_LOOP_VARIABLES_EDIAGNOSTICCHAIN_EMAP);
	m_loopNode_Operation_matching_output_pins_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_loopNode_Class, LOOPNODE_OPERATION_MATCHING_OUTPUT_PINS_EDIAGNOSTICCHAIN_EMAP);
	m_loopNode_Operation_matching_result_pins_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_loopNode_Class, LOOPNODE_OPERATION_MATCHING_RESULT_PINS_EDIAGNOSTICCHAIN_EMAP);
	m_loopNode_Operation_result_no_incoming_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_loopNode_Class, LOOPNODE_OPERATION_RESULT_NO_INCOMING_EDIAGNOSTICCHAIN_EMAP);
	m_loopNode_Operation_setup_test_and_body_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_loopNode_Class, LOOPNODE_OPERATION_SETUP_TEST_AND_BODY_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createManifestationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_manifestation_Class = factory->createEClass_in_EPackage(package, MANIFESTATION_CLASS);
	
	m_manifestation_Attribute_utilizedElement = factory->createEReference_in_EContainingClass(m_manifestation_Class, MANIFESTATION_ATTRIBUTE_UTILIZEDELEMENT);
	
	
}

void UmlPackageImpl::createMergeNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_mergeNode_Class = factory->createEClass_in_EPackage(package, MERGENODE_CLASS);
	
	
	m_mergeNode_Operation_edges_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_mergeNode_Class, MERGENODE_OPERATION_EDGES_EDIAGNOSTICCHAIN_EMAP);
	m_mergeNode_Operation_one_outgoing_edge_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_mergeNode_Class, MERGENODE_OPERATION_ONE_OUTGOING_EDGE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createMessageContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_message_Class = factory->createEClass_in_EPackage(package, MESSAGE_CLASS);
	m_message_Attribute_messageKind = factory->createEAttribute_in_EContainingClass(m_message_Class, MESSAGE_ATTRIBUTE_MESSAGEKIND);
	m_message_Attribute_messageSort = factory->createEAttribute_in_EContainingClass(m_message_Class, MESSAGE_ATTRIBUTE_MESSAGESORT);
	
	m_message_Attribute_argument = factory->createEReference_in_EContainingClass(m_message_Class, MESSAGE_ATTRIBUTE_ARGUMENT);
	m_message_Attribute_connector = factory->createEReference_in_EContainingClass(m_message_Class, MESSAGE_ATTRIBUTE_CONNECTOR);
	m_message_Attribute_interaction = factory->createEReference_in_EContainingClass(m_message_Class, MESSAGE_ATTRIBUTE_INTERACTION);
	m_message_Attribute_receiveEvent = factory->createEReference_in_EContainingClass(m_message_Class, MESSAGE_ATTRIBUTE_RECEIVEEVENT);
	m_message_Attribute_sendEvent = factory->createEReference_in_EContainingClass(m_message_Class, MESSAGE_ATTRIBUTE_SENDEVENT);
	m_message_Attribute_signature = factory->createEReference_in_EContainingClass(m_message_Class, MESSAGE_ATTRIBUTE_SIGNATURE);
	
	m_message_Operation_arguments_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_message_Class, MESSAGE_OPERATION_ARGUMENTS_EDIAGNOSTICCHAIN_EMAP);
	m_message_Operation_cannot_cross_boundaries_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_message_Class, MESSAGE_OPERATION_CANNOT_CROSS_BOUNDARIES_EDIAGNOSTICCHAIN_EMAP);
	m_message_Operation_getMessageKind = factory->createEOperation_in_EContainingClass(m_message_Class, MESSAGE_OPERATION_GETMESSAGEKIND);
	m_message_Operation_occurrence_specifications_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_message_Class, MESSAGE_OPERATION_OCCURRENCE_SPECIFICATIONS_EDIAGNOSTICCHAIN_EMAP);
	m_message_Operation_sending_receiving_message_event_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_message_Class, MESSAGE_OPERATION_SENDING_RECEIVING_MESSAGE_EVENT_EDIAGNOSTICCHAIN_EMAP);
	m_message_Operation_signature_is_operation_reply_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_message_Class, MESSAGE_OPERATION_SIGNATURE_IS_OPERATION_REPLY_EDIAGNOSTICCHAIN_EMAP);
	m_message_Operation_signature_is_operation_request_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_message_Class, MESSAGE_OPERATION_SIGNATURE_IS_OPERATION_REQUEST_EDIAGNOSTICCHAIN_EMAP);
	m_message_Operation_signature_is_signal_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_message_Class, MESSAGE_OPERATION_SIGNATURE_IS_SIGNAL_EDIAGNOSTICCHAIN_EMAP);
	m_message_Operation_signature_refer_to_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_message_Class, MESSAGE_OPERATION_SIGNATURE_REFER_TO_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createMessageEndContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_messageEnd_Class = factory->createEClass_in_EPackage(package, MESSAGEEND_CLASS);
	
	m_messageEnd_Attribute_message = factory->createEReference_in_EContainingClass(m_messageEnd_Class, MESSAGEEND_ATTRIBUTE_MESSAGE);
	
	m_messageEnd_Operation_enclosingFragment = factory->createEOperation_in_EContainingClass(m_messageEnd_Class, MESSAGEEND_OPERATION_ENCLOSINGFRAGMENT);
	m_messageEnd_Operation_isReceive = factory->createEOperation_in_EContainingClass(m_messageEnd_Class, MESSAGEEND_OPERATION_ISRECEIVE);
	m_messageEnd_Operation_isSend = factory->createEOperation_in_EContainingClass(m_messageEnd_Class, MESSAGEEND_OPERATION_ISSEND);
	m_messageEnd_Operation_oppositeEnd = factory->createEOperation_in_EContainingClass(m_messageEnd_Class, MESSAGEEND_OPERATION_OPPOSITEEND);
	
}

void UmlPackageImpl::createMessageEventContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_messageEvent_Class = factory->createEClass_in_EPackage(package, MESSAGEEVENT_CLASS);
	
	
	
}

void UmlPackageImpl::createMessageOccurrenceSpecificationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_messageOccurrenceSpecification_Class = factory->createEClass_in_EPackage(package, MESSAGEOCCURRENCESPECIFICATION_CLASS);
	
	
	
}

void UmlPackageImpl::createModelContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_model_Class = factory->createEClass_in_EPackage(package, MODEL_CLASS);
	m_model_Attribute_viewpoint = factory->createEAttribute_in_EContainingClass(m_model_Class, MODEL_ATTRIBUTE_VIEWPOINT);
	
	
	m_model_Operation_isMetamodel = factory->createEOperation_in_EContainingClass(m_model_Class, MODEL_OPERATION_ISMETAMODEL);
	
}

void UmlPackageImpl::createMultiplicityElementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_multiplicityElement_Class = factory->createEClass_in_EPackage(package, MULTIPLICITYELEMENT_CLASS);
	m_multiplicityElement_Attribute_isOrdered = factory->createEAttribute_in_EContainingClass(m_multiplicityElement_Class, MULTIPLICITYELEMENT_ATTRIBUTE_ISORDERED);
	m_multiplicityElement_Attribute_isUnique = factory->createEAttribute_in_EContainingClass(m_multiplicityElement_Class, MULTIPLICITYELEMENT_ATTRIBUTE_ISUNIQUE);
	m_multiplicityElement_Attribute_lower = factory->createEAttribute_in_EContainingClass(m_multiplicityElement_Class, MULTIPLICITYELEMENT_ATTRIBUTE_LOWER);
	m_multiplicityElement_Attribute_upper = factory->createEAttribute_in_EContainingClass(m_multiplicityElement_Class, MULTIPLICITYELEMENT_ATTRIBUTE_UPPER);
	
	m_multiplicityElement_Attribute_lowerValue = factory->createEReference_in_EContainingClass(m_multiplicityElement_Class, MULTIPLICITYELEMENT_ATTRIBUTE_LOWERVALUE);
	m_multiplicityElement_Attribute_upperValue = factory->createEReference_in_EContainingClass(m_multiplicityElement_Class, MULTIPLICITYELEMENT_ATTRIBUTE_UPPERVALUE);
	
	m_multiplicityElement_Operation_compatibleWith_MultiplicityElement = factory->createEOperation_in_EContainingClass(m_multiplicityElement_Class, MULTIPLICITYELEMENT_OPERATION_COMPATIBLEWITH_MULTIPLICITYELEMENT);
	m_multiplicityElement_Operation_includesMultiplicity_MultiplicityElement = factory->createEOperation_in_EContainingClass(m_multiplicityElement_Class, MULTIPLICITYELEMENT_OPERATION_INCLUDESMULTIPLICITY_MULTIPLICITYELEMENT);
	m_multiplicityElement_Operation_is_Integer_UnlimitedNatural = factory->createEOperation_in_EContainingClass(m_multiplicityElement_Class, MULTIPLICITYELEMENT_OPERATION_IS_INTEGER_UNLIMITEDNATURAL);
	m_multiplicityElement_Operation_isMultivalued = factory->createEOperation_in_EContainingClass(m_multiplicityElement_Class, MULTIPLICITYELEMENT_OPERATION_ISMULTIVALUED);
	m_multiplicityElement_Operation_lowerBound = factory->createEOperation_in_EContainingClass(m_multiplicityElement_Class, MULTIPLICITYELEMENT_OPERATION_LOWERBOUND);
	m_multiplicityElement_Operation_lower_ge_0_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_multiplicityElement_Class, MULTIPLICITYELEMENT_OPERATION_LOWER_GE_0_EDIAGNOSTICCHAIN_EMAP);
	m_multiplicityElement_Operation_lower_is_integer_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_multiplicityElement_Class, MULTIPLICITYELEMENT_OPERATION_LOWER_IS_INTEGER_EDIAGNOSTICCHAIN_EMAP);
	m_multiplicityElement_Operation_upperBound = factory->createEOperation_in_EContainingClass(m_multiplicityElement_Class, MULTIPLICITYELEMENT_OPERATION_UPPERBOUND);
	m_multiplicityElement_Operation_upper_ge_lower_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_multiplicityElement_Class, MULTIPLICITYELEMENT_OPERATION_UPPER_GE_LOWER_EDIAGNOSTICCHAIN_EMAP);
	m_multiplicityElement_Operation_upper_is_unlimitedNatural_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_multiplicityElement_Class, MULTIPLICITYELEMENT_OPERATION_UPPER_IS_UNLIMITEDNATURAL_EDIAGNOSTICCHAIN_EMAP);
	m_multiplicityElement_Operation_value_specification_constant_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_multiplicityElement_Class, MULTIPLICITYELEMENT_OPERATION_VALUE_SPECIFICATION_CONSTANT_EDIAGNOSTICCHAIN_EMAP);
	m_multiplicityElement_Operation_value_specification_no_side_effects_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_multiplicityElement_Class, MULTIPLICITYELEMENT_OPERATION_VALUE_SPECIFICATION_NO_SIDE_EFFECTS_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createNamedElementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_namedElement_Class = factory->createEClass_in_EPackage(package, NAMEDELEMENT_CLASS);
	m_namedElement_Attribute_name = factory->createEAttribute_in_EContainingClass(m_namedElement_Class, NAMEDELEMENT_ATTRIBUTE_NAME);
	m_namedElement_Attribute_qualifiedName = factory->createEAttribute_in_EContainingClass(m_namedElement_Class, NAMEDELEMENT_ATTRIBUTE_QUALIFIEDNAME);
	m_namedElement_Attribute_visibility = factory->createEAttribute_in_EContainingClass(m_namedElement_Class, NAMEDELEMENT_ATTRIBUTE_VISIBILITY);
	
	m_namedElement_Attribute_clientDependency = factory->createEReference_in_EContainingClass(m_namedElement_Class, NAMEDELEMENT_ATTRIBUTE_CLIENTDEPENDENCY);
	m_namedElement_Attribute_nameExpression = factory->createEReference_in_EContainingClass(m_namedElement_Class, NAMEDELEMENT_ATTRIBUTE_NAMEEXPRESSION);
	m_namedElement_Attribute_namespace = factory->createEReference_in_EContainingClass(m_namedElement_Class, NAMEDELEMENT_ATTRIBUTE_NAMESPACE);
	
	m_namedElement_Operation_allNamespaces = factory->createEOperation_in_EContainingClass(m_namedElement_Class, NAMEDELEMENT_OPERATION_ALLNAMESPACES);
	m_namedElement_Operation_allOwningPackages = factory->createEOperation_in_EContainingClass(m_namedElement_Class, NAMEDELEMENT_OPERATION_ALLOWNINGPACKAGES);
	m_namedElement_Operation_createDependency_NamedElement = factory->createEOperation_in_EContainingClass(m_namedElement_Class, NAMEDELEMENT_OPERATION_CREATEDEPENDENCY_NAMEDELEMENT);
	m_namedElement_Operation_createUsage_NamedElement = factory->createEOperation_in_EContainingClass(m_namedElement_Class, NAMEDELEMENT_OPERATION_CREATEUSAGE_NAMEDELEMENT);
	m_namedElement_Operation_getClientDependencies = factory->createEOperation_in_EContainingClass(m_namedElement_Class, NAMEDELEMENT_OPERATION_GETCLIENTDEPENDENCIES);
	m_namedElement_Operation_getLabel = factory->createEOperation_in_EContainingClass(m_namedElement_Class, NAMEDELEMENT_OPERATION_GETLABEL);
	m_namedElement_Operation_getLabel_Boolean = factory->createEOperation_in_EContainingClass(m_namedElement_Class, NAMEDELEMENT_OPERATION_GETLABEL_BOOLEAN);
	m_namedElement_Operation_getNamespace = factory->createEOperation_in_EContainingClass(m_namedElement_Class, NAMEDELEMENT_OPERATION_GETNAMESPACE);
	m_namedElement_Operation_getQualifiedName = factory->createEOperation_in_EContainingClass(m_namedElement_Class, NAMEDELEMENT_OPERATION_GETQUALIFIEDNAME);
	m_namedElement_Operation_has_no_qualified_name_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_namedElement_Class, NAMEDELEMENT_OPERATION_HAS_NO_QUALIFIED_NAME_EDIAGNOSTICCHAIN_EMAP);
	m_namedElement_Operation_has_qualified_name_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_namedElement_Class, NAMEDELEMENT_OPERATION_HAS_QUALIFIED_NAME_EDIAGNOSTICCHAIN_EMAP);
	m_namedElement_Operation_isDistinguishableFrom_NamedElement_Namespace = factory->createEOperation_in_EContainingClass(m_namedElement_Class, NAMEDELEMENT_OPERATION_ISDISTINGUISHABLEFROM_NAMEDELEMENT_NAMESPACE);
	m_namedElement_Operation_separator = factory->createEOperation_in_EContainingClass(m_namedElement_Class, NAMEDELEMENT_OPERATION_SEPARATOR);
	m_namedElement_Operation_visibility_needs_ownership_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_namedElement_Class, NAMEDELEMENT_OPERATION_VISIBILITY_NEEDS_OWNERSHIP_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createNamespaceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_namespace_Class = factory->createEClass_in_EPackage(package, NAMESPACE_CLASS);
	
	m_namespace_Attribute_elementImport = factory->createEReference_in_EContainingClass(m_namespace_Class, NAMESPACE_ATTRIBUTE_ELEMENTIMPORT);
	m_namespace_Attribute_importedMember = factory->createEReference_in_EContainingClass(m_namespace_Class, NAMESPACE_ATTRIBUTE_IMPORTEDMEMBER);
	m_namespace_Attribute_member = factory->createEReference_in_EContainingClass(m_namespace_Class, NAMESPACE_ATTRIBUTE_MEMBER);
	m_namespace_Attribute_ownedMember = factory->createEReference_in_EContainingClass(m_namespace_Class, NAMESPACE_ATTRIBUTE_OWNEDMEMBER);
	m_namespace_Attribute_ownedRule = factory->createEReference_in_EContainingClass(m_namespace_Class, NAMESPACE_ATTRIBUTE_OWNEDRULE);
	m_namespace_Attribute_packageImport = factory->createEReference_in_EContainingClass(m_namespace_Class, NAMESPACE_ATTRIBUTE_PACKAGEIMPORT);
	
	m_namespace_Operation_cannot_import_ownedMembers_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_namespace_Class, NAMESPACE_OPERATION_CANNOT_IMPORT_OWNEDMEMBERS_EDIAGNOSTICCHAIN_EMAP);
	m_namespace_Operation_cannot_import_self_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_namespace_Class, NAMESPACE_OPERATION_CANNOT_IMPORT_SELF_EDIAGNOSTICCHAIN_EMAP);
	m_namespace_Operation_createElementImport_PackageableElement_VisibilityKind = factory->createEOperation_in_EContainingClass(m_namespace_Class, NAMESPACE_OPERATION_CREATEELEMENTIMPORT_PACKAGEABLEELEMENT_VISIBILITYKIND);
	m_namespace_Operation_createPackageImport_Package_VisibilityKind = factory->createEOperation_in_EContainingClass(m_namespace_Class, NAMESPACE_OPERATION_CREATEPACKAGEIMPORT_PACKAGE_VISIBILITYKIND);
	m_namespace_Operation_excludeCollisions_PackageableElement = factory->createEOperation_in_EContainingClass(m_namespace_Class, NAMESPACE_OPERATION_EXCLUDECOLLISIONS_PACKAGEABLEELEMENT);
	m_namespace_Operation_getImportedElements = factory->createEOperation_in_EContainingClass(m_namespace_Class, NAMESPACE_OPERATION_GETIMPORTEDELEMENTS);
	m_namespace_Operation_getImportedMembers = factory->createEOperation_in_EContainingClass(m_namespace_Class, NAMESPACE_OPERATION_GETIMPORTEDMEMBERS);
	m_namespace_Operation_getImportedPackages = factory->createEOperation_in_EContainingClass(m_namespace_Class, NAMESPACE_OPERATION_GETIMPORTEDPACKAGES);
	m_namespace_Operation_getNamesOfMember_NamedElement = factory->createEOperation_in_EContainingClass(m_namespace_Class, NAMESPACE_OPERATION_GETNAMESOFMEMBER_NAMEDELEMENT);
	m_namespace_Operation_getOwnedMembers = factory->createEOperation_in_EContainingClass(m_namespace_Class, NAMESPACE_OPERATION_GETOWNEDMEMBERS);
	m_namespace_Operation_importMembers_PackageableElement = factory->createEOperation_in_EContainingClass(m_namespace_Class, NAMESPACE_OPERATION_IMPORTMEMBERS_PACKAGEABLEELEMENT);
	m_namespace_Operation_membersAreDistinguishable = factory->createEOperation_in_EContainingClass(m_namespace_Class, NAMESPACE_OPERATION_MEMBERSAREDISTINGUISHABLE);
	m_namespace_Operation_members_distinguishable_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_namespace_Class, NAMESPACE_OPERATION_MEMBERS_DISTINGUISHABLE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_node_Class = factory->createEClass_in_EPackage(package, NODE_CLASS);
	
	m_node_Attribute_nestedNode = factory->createEReference_in_EContainingClass(m_node_Class, NODE_ATTRIBUTE_NESTEDNODE);
	
	m_node_Operation_createCommunicationPath_Boolean_UnlimitedNatural = factory->createEOperation_in_EContainingClass(m_node_Class, NODE_OPERATION_CREATECOMMUNICATIONPATH_BOOLEAN_UNLIMITEDNATURAL);
	m_node_Operation_getCommunicationPaths = factory->createEOperation_in_EContainingClass(m_node_Class, NODE_OPERATION_GETCOMMUNICATIONPATHS);
	m_node_Operation_internal_structure_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_node_Class, NODE_OPERATION_INTERNAL_STRUCTURE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createObjectContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_object_Class = factory->createEClass_in_EPackage(package, OBJECT_CLASS);
	
	
	m_object_Operation_get_Property = factory->createEOperation_in_EContainingClass(m_object_Class, OBJECT_OPERATION_GET_PROPERTY);
	m_object_Operation_invoke_Operation_Argument = factory->createEOperation_in_EContainingClass(m_object_Class, OBJECT_OPERATION_INVOKE_OPERATION_ARGUMENT);
	m_object_Operation_set_Property_EJavaObject = factory->createEOperation_in_EContainingClass(m_object_Class, OBJECT_OPERATION_SET_PROPERTY_EJAVAOBJECT);
	m_object_Operation_unset_Property = factory->createEOperation_in_EContainingClass(m_object_Class, OBJECT_OPERATION_UNSET_PROPERTY);
	
}

void UmlPackageImpl::createObjectFlowContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_objectFlow_Class = factory->createEClass_in_EPackage(package, OBJECTFLOW_CLASS);
	m_objectFlow_Attribute_isMulticast = factory->createEAttribute_in_EContainingClass(m_objectFlow_Class, OBJECTFLOW_ATTRIBUTE_ISMULTICAST);
	m_objectFlow_Attribute_isMultireceive = factory->createEAttribute_in_EContainingClass(m_objectFlow_Class, OBJECTFLOW_ATTRIBUTE_ISMULTIRECEIVE);
	
	m_objectFlow_Attribute_selection = factory->createEReference_in_EContainingClass(m_objectFlow_Class, OBJECTFLOW_ATTRIBUTE_SELECTION);
	m_objectFlow_Attribute_transformation = factory->createEReference_in_EContainingClass(m_objectFlow_Class, OBJECTFLOW_ATTRIBUTE_TRANSFORMATION);
	
	m_objectFlow_Operation_compatible_types_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_objectFlow_Class, OBJECTFLOW_OPERATION_COMPATIBLE_TYPES_EDIAGNOSTICCHAIN_EMAP);
	m_objectFlow_Operation_input_and_output_parameter_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_objectFlow_Class, OBJECTFLOW_OPERATION_INPUT_AND_OUTPUT_PARAMETER_EDIAGNOSTICCHAIN_EMAP);
	m_objectFlow_Operation_is_multicast_or_is_multireceive_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_objectFlow_Class, OBJECTFLOW_OPERATION_IS_MULTICAST_OR_IS_MULTIRECEIVE_EDIAGNOSTICCHAIN_EMAP);
	m_objectFlow_Operation_no_executable_nodes_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_objectFlow_Class, OBJECTFLOW_OPERATION_NO_EXECUTABLE_NODES_EDIAGNOSTICCHAIN_EMAP);
	m_objectFlow_Operation_same_upper_bounds_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_objectFlow_Class, OBJECTFLOW_OPERATION_SAME_UPPER_BOUNDS_EDIAGNOSTICCHAIN_EMAP);
	m_objectFlow_Operation_selection_behavior_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_objectFlow_Class, OBJECTFLOW_OPERATION_SELECTION_BEHAVIOR_EDIAGNOSTICCHAIN_EMAP);
	m_objectFlow_Operation_target_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_objectFlow_Class, OBJECTFLOW_OPERATION_TARGET_EDIAGNOSTICCHAIN_EMAP);
	m_objectFlow_Operation_transformation_behavior_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_objectFlow_Class, OBJECTFLOW_OPERATION_TRANSFORMATION_BEHAVIOR_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createObjectNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_objectNode_Class = factory->createEClass_in_EPackage(package, OBJECTNODE_CLASS);
	m_objectNode_Attribute_isControlType = factory->createEAttribute_in_EContainingClass(m_objectNode_Class, OBJECTNODE_ATTRIBUTE_ISCONTROLTYPE);
	m_objectNode_Attribute_ordering = factory->createEAttribute_in_EContainingClass(m_objectNode_Class, OBJECTNODE_ATTRIBUTE_ORDERING);
	
	m_objectNode_Attribute_inState = factory->createEReference_in_EContainingClass(m_objectNode_Class, OBJECTNODE_ATTRIBUTE_INSTATE);
	m_objectNode_Attribute_selection = factory->createEReference_in_EContainingClass(m_objectNode_Class, OBJECTNODE_ATTRIBUTE_SELECTION);
	m_objectNode_Attribute_upperBound = factory->createEReference_in_EContainingClass(m_objectNode_Class, OBJECTNODE_ATTRIBUTE_UPPERBOUND);
	
	m_objectNode_Operation_input_output_parameter_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_objectNode_Class, OBJECTNODE_OPERATION_INPUT_OUTPUT_PARAMETER_EDIAGNOSTICCHAIN_EMAP);
	m_objectNode_Operation_object_flow_edges_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_objectNode_Class, OBJECTNODE_OPERATION_OBJECT_FLOW_EDGES_EDIAGNOSTICCHAIN_EMAP);
	m_objectNode_Operation_selection_behavior_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_objectNode_Class, OBJECTNODE_OPERATION_SELECTION_BEHAVIOR_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createObservationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_observation_Class = factory->createEClass_in_EPackage(package, OBSERVATION_CLASS);
	
	
	
}

void UmlPackageImpl::createOccurrenceSpecificationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_occurrenceSpecification_Class = factory->createEClass_in_EPackage(package, OCCURRENCESPECIFICATION_CLASS);
	
	m_occurrenceSpecification_Attribute_toAfter = factory->createEReference_in_EContainingClass(m_occurrenceSpecification_Class, OCCURRENCESPECIFICATION_ATTRIBUTE_TOAFTER);
	m_occurrenceSpecification_Attribute_toBefore = factory->createEReference_in_EContainingClass(m_occurrenceSpecification_Class, OCCURRENCESPECIFICATION_ATTRIBUTE_TOBEFORE);
	
	m_occurrenceSpecification_Operation_getCovered = factory->createEOperation_in_EContainingClass(m_occurrenceSpecification_Class, OCCURRENCESPECIFICATION_OPERATION_GETCOVERED);
	m_occurrenceSpecification_Operation_setCovered_Lifeline = factory->createEOperation_in_EContainingClass(m_occurrenceSpecification_Class, OCCURRENCESPECIFICATION_OPERATION_SETCOVERED_LIFELINE);
	
}

void UmlPackageImpl::createOpaqueActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_opaqueAction_Class = factory->createEClass_in_EPackage(package, OPAQUEACTION_CLASS);
	m_opaqueAction_Attribute_body = factory->createEAttribute_in_EContainingClass(m_opaqueAction_Class, OPAQUEACTION_ATTRIBUTE_BODY);
	m_opaqueAction_Attribute_language = factory->createEAttribute_in_EContainingClass(m_opaqueAction_Class, OPAQUEACTION_ATTRIBUTE_LANGUAGE);
	
	m_opaqueAction_Attribute_inputValue = factory->createEReference_in_EContainingClass(m_opaqueAction_Class, OPAQUEACTION_ATTRIBUTE_INPUTVALUE);
	m_opaqueAction_Attribute_outputValue = factory->createEReference_in_EContainingClass(m_opaqueAction_Class, OPAQUEACTION_ATTRIBUTE_OUTPUTVALUE);
	
	m_opaqueAction_Operation_language_body_size_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_opaqueAction_Class, OPAQUEACTION_OPERATION_LANGUAGE_BODY_SIZE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createOpaqueBehaviorContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_opaqueBehavior_Class = factory->createEClass_in_EPackage(package, OPAQUEBEHAVIOR_CLASS);
	m_opaqueBehavior_Attribute_body = factory->createEAttribute_in_EContainingClass(m_opaqueBehavior_Class, OPAQUEBEHAVIOR_ATTRIBUTE_BODY);
	m_opaqueBehavior_Attribute_language = factory->createEAttribute_in_EContainingClass(m_opaqueBehavior_Class, OPAQUEBEHAVIOR_ATTRIBUTE_LANGUAGE);
	
	
	
}

void UmlPackageImpl::createOpaqueExpressionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_opaqueExpression_Class = factory->createEClass_in_EPackage(package, OPAQUEEXPRESSION_CLASS);
	m_opaqueExpression_Attribute_body = factory->createEAttribute_in_EContainingClass(m_opaqueExpression_Class, OPAQUEEXPRESSION_ATTRIBUTE_BODY);
	m_opaqueExpression_Attribute_language = factory->createEAttribute_in_EContainingClass(m_opaqueExpression_Class, OPAQUEEXPRESSION_ATTRIBUTE_LANGUAGE);
	
	m_opaqueExpression_Attribute_behavior = factory->createEReference_in_EContainingClass(m_opaqueExpression_Class, OPAQUEEXPRESSION_ATTRIBUTE_BEHAVIOR);
	m_opaqueExpression_Attribute_result = factory->createEReference_in_EContainingClass(m_opaqueExpression_Class, OPAQUEEXPRESSION_ATTRIBUTE_RESULT);
	
	m_opaqueExpression_Operation_getResult = factory->createEOperation_in_EContainingClass(m_opaqueExpression_Class, OPAQUEEXPRESSION_OPERATION_GETRESULT);
	m_opaqueExpression_Operation_isIntegral = factory->createEOperation_in_EContainingClass(m_opaqueExpression_Class, OPAQUEEXPRESSION_OPERATION_ISINTEGRAL);
	m_opaqueExpression_Operation_isNonNegative = factory->createEOperation_in_EContainingClass(m_opaqueExpression_Class, OPAQUEEXPRESSION_OPERATION_ISNONNEGATIVE);
	m_opaqueExpression_Operation_isPositive = factory->createEOperation_in_EContainingClass(m_opaqueExpression_Class, OPAQUEEXPRESSION_OPERATION_ISPOSITIVE);
	m_opaqueExpression_Operation_language_body_size_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_opaqueExpression_Class, OPAQUEEXPRESSION_OPERATION_LANGUAGE_BODY_SIZE_EDIAGNOSTICCHAIN_EMAP);
	m_opaqueExpression_Operation_one_return_result_parameter_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_opaqueExpression_Class, OPAQUEEXPRESSION_OPERATION_ONE_RETURN_RESULT_PARAMETER_EDIAGNOSTICCHAIN_EMAP);
	m_opaqueExpression_Operation_only_return_result_parameters_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_opaqueExpression_Class, OPAQUEEXPRESSION_OPERATION_ONLY_RETURN_RESULT_PARAMETERS_EDIAGNOSTICCHAIN_EMAP);
	m_opaqueExpression_Operation_value = factory->createEOperation_in_EContainingClass(m_opaqueExpression_Class, OPAQUEEXPRESSION_OPERATION_VALUE);
	
}

void UmlPackageImpl::createOperationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_operation_Class = factory->createEClass_in_EPackage(package, OPERATION_CLASS);
	m_operation_Attribute_isOrdered = factory->createEAttribute_in_EContainingClass(m_operation_Class, OPERATION_ATTRIBUTE_ISORDERED);
	m_operation_Attribute_isQuery = factory->createEAttribute_in_EContainingClass(m_operation_Class, OPERATION_ATTRIBUTE_ISQUERY);
	m_operation_Attribute_isUnique = factory->createEAttribute_in_EContainingClass(m_operation_Class, OPERATION_ATTRIBUTE_ISUNIQUE);
	m_operation_Attribute_lower = factory->createEAttribute_in_EContainingClass(m_operation_Class, OPERATION_ATTRIBUTE_LOWER);
	m_operation_Attribute_upper = factory->createEAttribute_in_EContainingClass(m_operation_Class, OPERATION_ATTRIBUTE_UPPER);
	
	m_operation_Attribute_bodyCondition = factory->createEReference_in_EContainingClass(m_operation_Class, OPERATION_ATTRIBUTE_BODYCONDITION);
	m_operation_Attribute_class = factory->createEReference_in_EContainingClass(m_operation_Class, OPERATION_ATTRIBUTE_CLASS);
	m_operation_Attribute_datatype = factory->createEReference_in_EContainingClass(m_operation_Class, OPERATION_ATTRIBUTE_DATATYPE);
	m_operation_Attribute_interface = factory->createEReference_in_EContainingClass(m_operation_Class, OPERATION_ATTRIBUTE_INTERFACE);
	m_operation_Attribute_postcondition = factory->createEReference_in_EContainingClass(m_operation_Class, OPERATION_ATTRIBUTE_POSTCONDITION);
	m_operation_Attribute_precondition = factory->createEReference_in_EContainingClass(m_operation_Class, OPERATION_ATTRIBUTE_PRECONDITION);
	m_operation_Attribute_redefinedOperation = factory->createEReference_in_EContainingClass(m_operation_Class, OPERATION_ATTRIBUTE_REDEFINEDOPERATION);
	m_operation_Attribute_type = factory->createEReference_in_EContainingClass(m_operation_Class, OPERATION_ATTRIBUTE_TYPE);
	
	m_operation_Operation_at_most_one_return_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_operation_Class, OPERATION_OPERATION_AT_MOST_ONE_RETURN_EDIAGNOSTICCHAIN_EMAP);
	m_operation_Operation_getLower = factory->createEOperation_in_EContainingClass(m_operation_Class, OPERATION_OPERATION_GETLOWER);
	m_operation_Operation_getReturnResult = factory->createEOperation_in_EContainingClass(m_operation_Class, OPERATION_OPERATION_GETRETURNRESULT);
	m_operation_Operation_getType = factory->createEOperation_in_EContainingClass(m_operation_Class, OPERATION_OPERATION_GETTYPE);
	m_operation_Operation_getUpper = factory->createEOperation_in_EContainingClass(m_operation_Class, OPERATION_OPERATION_GETUPPER);
	m_operation_Operation_isOrdered = factory->createEOperation_in_EContainingClass(m_operation_Class, OPERATION_OPERATION_ISORDERED);
	m_operation_Operation_isUnique = factory->createEOperation_in_EContainingClass(m_operation_Class, OPERATION_OPERATION_ISUNIQUE);
	m_operation_Operation_only_body_for_query_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_operation_Class, OPERATION_OPERATION_ONLY_BODY_FOR_QUERY_EDIAGNOSTICCHAIN_EMAP);
	m_operation_Operation_returnResult = factory->createEOperation_in_EContainingClass(m_operation_Class, OPERATION_OPERATION_RETURNRESULT);
	m_operation_Operation_setIsOrdered_Boolean = factory->createEOperation_in_EContainingClass(m_operation_Class, OPERATION_OPERATION_SETISORDERED_BOOLEAN);
	m_operation_Operation_setIsUnique_Boolean = factory->createEOperation_in_EContainingClass(m_operation_Class, OPERATION_OPERATION_SETISUNIQUE_BOOLEAN);
	m_operation_Operation_setLower_Integer = factory->createEOperation_in_EContainingClass(m_operation_Class, OPERATION_OPERATION_SETLOWER_INTEGER);
	m_operation_Operation_setType_Type = factory->createEOperation_in_EContainingClass(m_operation_Class, OPERATION_OPERATION_SETTYPE_TYPE);
	m_operation_Operation_setUpper_UnlimitedNatural = factory->createEOperation_in_EContainingClass(m_operation_Class, OPERATION_OPERATION_SETUPPER_UNLIMITEDNATURAL);
	
}

void UmlPackageImpl::createOperationTemplateParameterContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_operationTemplateParameter_Class = factory->createEClass_in_EPackage(package, OPERATIONTEMPLATEPARAMETER_CLASS);
	
	
	m_operationTemplateParameter_Operation_match_default_signature_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_operationTemplateParameter_Class, OPERATIONTEMPLATEPARAMETER_OPERATION_MATCH_DEFAULT_SIGNATURE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createOutputPinContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_outputPin_Class = factory->createEClass_in_EPackage(package, OUTPUTPIN_CLASS);
	
	m_outputPin_Attribute_action = factory->createEReference_in_EContainingClass(m_outputPin_Class, OUTPUTPIN_ATTRIBUTE_ACTION);
	m_outputPin_Attribute_callAction = factory->createEReference_in_EContainingClass(m_outputPin_Class, OUTPUTPIN_ATTRIBUTE_CALLACTION);
	
	m_outputPin_Operation_incoming_edges_structured_only_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_outputPin_Class, OUTPUTPIN_OPERATION_INCOMING_EDGES_STRUCTURED_ONLY_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createPackageContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_package_Class = factory->createEClass_in_EPackage(package, PACKAGE_CLASS);
	m_package_Attribute_uRI = factory->createEAttribute_in_EContainingClass(m_package_Class, PACKAGE_ATTRIBUTE_URI);
	
	m_package_Attribute_nestedPackage = factory->createEReference_in_EContainingClass(m_package_Class, PACKAGE_ATTRIBUTE_NESTEDPACKAGE);
	m_package_Attribute_nestingPackage = factory->createEReference_in_EContainingClass(m_package_Class, PACKAGE_ATTRIBUTE_NESTINGPACKAGE);
	m_package_Attribute_ownedStereotype = factory->createEReference_in_EContainingClass(m_package_Class, PACKAGE_ATTRIBUTE_OWNEDSTEREOTYPE);
	m_package_Attribute_ownedType = factory->createEReference_in_EContainingClass(m_package_Class, PACKAGE_ATTRIBUTE_OWNEDTYPE);
	m_package_Attribute_packageMerge = factory->createEReference_in_EContainingClass(m_package_Class, PACKAGE_ATTRIBUTE_PACKAGEMERGE);
	m_package_Attribute_packagedElement = factory->createEReference_in_EContainingClass(m_package_Class, PACKAGE_ATTRIBUTE_PACKAGEDELEMENT);
	m_package_Attribute_profileApplication = factory->createEReference_in_EContainingClass(m_package_Class, PACKAGE_ATTRIBUTE_PROFILEAPPLICATION);
	
	m_package_Operation_allApplicableStereotypes = factory->createEOperation_in_EContainingClass(m_package_Class, PACKAGE_OPERATION_ALLAPPLICABLESTEREOTYPES);
	m_package_Operation_applyProfile_Profile = factory->createEOperation_in_EContainingClass(m_package_Class, PACKAGE_OPERATION_APPLYPROFILE_PROFILE);
	m_package_Operation_containingProfile = factory->createEOperation_in_EContainingClass(m_package_Class, PACKAGE_OPERATION_CONTAININGPROFILE);
	m_package_Operation_createOwnedClass_String_Boolean = factory->createEOperation_in_EContainingClass(m_package_Class, PACKAGE_OPERATION_CREATEOWNEDCLASS_STRING_BOOLEAN);
	m_package_Operation_createOwnedEnumeration_String = factory->createEOperation_in_EContainingClass(m_package_Class, PACKAGE_OPERATION_CREATEOWNEDENUMERATION_STRING);
	m_package_Operation_createOwnedInterface_String = factory->createEOperation_in_EContainingClass(m_package_Class, PACKAGE_OPERATION_CREATEOWNEDINTERFACE_STRING);
	m_package_Operation_createOwnedPrimitiveType_String = factory->createEOperation_in_EContainingClass(m_package_Class, PACKAGE_OPERATION_CREATEOWNEDPRIMITIVETYPE_STRING);
	m_package_Operation_createOwnedStereotype_String_Boolean = factory->createEOperation_in_EContainingClass(m_package_Class, PACKAGE_OPERATION_CREATEOWNEDSTEREOTYPE_STRING_BOOLEAN);
	m_package_Operation_elements_public_or_private_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_package_Class, PACKAGE_OPERATION_ELEMENTS_PUBLIC_OR_PRIVATE_EDIAGNOSTICCHAIN_EMAP);
	m_package_Operation_getAllAppliedProfiles = factory->createEOperation_in_EContainingClass(m_package_Class, PACKAGE_OPERATION_GETALLAPPLIEDPROFILES);
	m_package_Operation_getAllProfileApplications = factory->createEOperation_in_EContainingClass(m_package_Class, PACKAGE_OPERATION_GETALLPROFILEAPPLICATIONS);
	m_package_Operation_getAppliedProfile_String = factory->createEOperation_in_EContainingClass(m_package_Class, PACKAGE_OPERATION_GETAPPLIEDPROFILE_STRING);
	m_package_Operation_getAppliedProfile_String_Boolean = factory->createEOperation_in_EContainingClass(m_package_Class, PACKAGE_OPERATION_GETAPPLIEDPROFILE_STRING_BOOLEAN);
	m_package_Operation_getAppliedProfiles = factory->createEOperation_in_EContainingClass(m_package_Class, PACKAGE_OPERATION_GETAPPLIEDPROFILES);
	m_package_Operation_getNestedPackages = factory->createEOperation_in_EContainingClass(m_package_Class, PACKAGE_OPERATION_GETNESTEDPACKAGES);
	m_package_Operation_getOwnedStereotypes = factory->createEOperation_in_EContainingClass(m_package_Class, PACKAGE_OPERATION_GETOWNEDSTEREOTYPES);
	m_package_Operation_getOwnedTypes = factory->createEOperation_in_EContainingClass(m_package_Class, PACKAGE_OPERATION_GETOWNEDTYPES);
	m_package_Operation_getProfileApplication_Profile = factory->createEOperation_in_EContainingClass(m_package_Class, PACKAGE_OPERATION_GETPROFILEAPPLICATION_PROFILE);
	m_package_Operation_getProfileApplication_Profile_Boolean = factory->createEOperation_in_EContainingClass(m_package_Class, PACKAGE_OPERATION_GETPROFILEAPPLICATION_PROFILE_BOOLEAN);
	m_package_Operation_isModelLibrary = factory->createEOperation_in_EContainingClass(m_package_Class, PACKAGE_OPERATION_ISMODELLIBRARY);
	m_package_Operation_isProfileApplied_Profile = factory->createEOperation_in_EContainingClass(m_package_Class, PACKAGE_OPERATION_ISPROFILEAPPLIED_PROFILE);
	m_package_Operation_makesVisible_NamedElement = factory->createEOperation_in_EContainingClass(m_package_Class, PACKAGE_OPERATION_MAKESVISIBLE_NAMEDELEMENT);
	m_package_Operation_unapplyProfile_Profile = factory->createEOperation_in_EContainingClass(m_package_Class, PACKAGE_OPERATION_UNAPPLYPROFILE_PROFILE);
	m_package_Operation_visibleMembers = factory->createEOperation_in_EContainingClass(m_package_Class, PACKAGE_OPERATION_VISIBLEMEMBERS);
	
}

void UmlPackageImpl::createPackageImportContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_packageImport_Class = factory->createEClass_in_EPackage(package, PACKAGEIMPORT_CLASS);
	m_packageImport_Attribute_visibility = factory->createEAttribute_in_EContainingClass(m_packageImport_Class, PACKAGEIMPORT_ATTRIBUTE_VISIBILITY);
	
	m_packageImport_Attribute_importedPackage = factory->createEReference_in_EContainingClass(m_packageImport_Class, PACKAGEIMPORT_ATTRIBUTE_IMPORTEDPACKAGE);
	m_packageImport_Attribute_importingNamespace = factory->createEReference_in_EContainingClass(m_packageImport_Class, PACKAGEIMPORT_ATTRIBUTE_IMPORTINGNAMESPACE);
	
	m_packageImport_Operation_public_or_private_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_packageImport_Class, PACKAGEIMPORT_OPERATION_PUBLIC_OR_PRIVATE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createPackageMergeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_packageMerge_Class = factory->createEClass_in_EPackage(package, PACKAGEMERGE_CLASS);
	
	m_packageMerge_Attribute_mergedPackage = factory->createEReference_in_EContainingClass(m_packageMerge_Class, PACKAGEMERGE_ATTRIBUTE_MERGEDPACKAGE);
	m_packageMerge_Attribute_receivingPackage = factory->createEReference_in_EContainingClass(m_packageMerge_Class, PACKAGEMERGE_ATTRIBUTE_RECEIVINGPACKAGE);
	
	
}

void UmlPackageImpl::createPackageableElementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_packageableElement_Class = factory->createEClass_in_EPackage(package, PACKAGEABLEELEMENT_CLASS);
	
	m_packageableElement_Attribute_owningPackage = factory->createEReference_in_EContainingClass(m_packageableElement_Class, PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE);
	
	m_packageableElement_Operation_namespace_needs_visibility_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_packageableElement_Class, PACKAGEABLEELEMENT_OPERATION_NAMESPACE_NEEDS_VISIBILITY_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createParameterContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_parameter_Class = factory->createEClass_in_EPackage(package, PARAMETER_CLASS);
	m_parameter_Attribute_default = factory->createEAttribute_in_EContainingClass(m_parameter_Class, PARAMETER_ATTRIBUTE_DEFAULT);
	m_parameter_Attribute_direction = factory->createEAttribute_in_EContainingClass(m_parameter_Class, PARAMETER_ATTRIBUTE_DIRECTION);
	m_parameter_Attribute_effect = factory->createEAttribute_in_EContainingClass(m_parameter_Class, PARAMETER_ATTRIBUTE_EFFECT);
	m_parameter_Attribute_isException = factory->createEAttribute_in_EContainingClass(m_parameter_Class, PARAMETER_ATTRIBUTE_ISEXCEPTION);
	m_parameter_Attribute_isStream = factory->createEAttribute_in_EContainingClass(m_parameter_Class, PARAMETER_ATTRIBUTE_ISSTREAM);
	
	m_parameter_Attribute_behavior = factory->createEReference_in_EContainingClass(m_parameter_Class, PARAMETER_ATTRIBUTE_BEHAVIOR);
	m_parameter_Attribute_defaultValue = factory->createEReference_in_EContainingClass(m_parameter_Class, PARAMETER_ATTRIBUTE_DEFAULTVALUE);
	m_parameter_Attribute_operation = factory->createEReference_in_EContainingClass(m_parameter_Class, PARAMETER_ATTRIBUTE_OPERATION);
	m_parameter_Attribute_parameterSet = factory->createEReference_in_EContainingClass(m_parameter_Class, PARAMETER_ATTRIBUTE_PARAMETERSET);
	
	m_parameter_Operation_connector_end_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_parameter_Class, PARAMETER_OPERATION_CONNECTOR_END_EDIAGNOSTICCHAIN_EMAP);
	m_parameter_Operation_in_and_out_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_parameter_Class, PARAMETER_OPERATION_IN_AND_OUT_EDIAGNOSTICCHAIN_EMAP);
	m_parameter_Operation_isSetDefault = factory->createEOperation_in_EContainingClass(m_parameter_Class, PARAMETER_OPERATION_ISSETDEFAULT);
	m_parameter_Operation_not_exception_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_parameter_Class, PARAMETER_OPERATION_NOT_EXCEPTION_EDIAGNOSTICCHAIN_EMAP);
	m_parameter_Operation_object_effect_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_parameter_Class, PARAMETER_OPERATION_OBJECT_EFFECT_EDIAGNOSTICCHAIN_EMAP);
	m_parameter_Operation_reentrant_behaviors_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_parameter_Class, PARAMETER_OPERATION_REENTRANT_BEHAVIORS_EDIAGNOSTICCHAIN_EMAP);
	m_parameter_Operation_setBooleanDefaultValue_Boolean = factory->createEOperation_in_EContainingClass(m_parameter_Class, PARAMETER_OPERATION_SETBOOLEANDEFAULTVALUE_BOOLEAN);
	m_parameter_Operation_setIntegerDefaultValue_Integer = factory->createEOperation_in_EContainingClass(m_parameter_Class, PARAMETER_OPERATION_SETINTEGERDEFAULTVALUE_INTEGER);
	m_parameter_Operation_setNullDefaultValue = factory->createEOperation_in_EContainingClass(m_parameter_Class, PARAMETER_OPERATION_SETNULLDEFAULTVALUE);
	m_parameter_Operation_setRealDefaultValue_Real = factory->createEOperation_in_EContainingClass(m_parameter_Class, PARAMETER_OPERATION_SETREALDEFAULTVALUE_REAL);
	m_parameter_Operation_setStringDefaultValue_String = factory->createEOperation_in_EContainingClass(m_parameter_Class, PARAMETER_OPERATION_SETSTRINGDEFAULTVALUE_STRING);
	m_parameter_Operation_setUnlimitedNaturalDefaultValue_UnlimitedNatural = factory->createEOperation_in_EContainingClass(m_parameter_Class, PARAMETER_OPERATION_SETUNLIMITEDNATURALDEFAULTVALUE_UNLIMITEDNATURAL);
	m_parameter_Operation_stream_and_exception_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_parameter_Class, PARAMETER_OPERATION_STREAM_AND_EXCEPTION_EDIAGNOSTICCHAIN_EMAP);
	m_parameter_Operation_unsetDefault = factory->createEOperation_in_EContainingClass(m_parameter_Class, PARAMETER_OPERATION_UNSETDEFAULT);
	
}

void UmlPackageImpl::createParameterSetContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_parameterSet_Class = factory->createEClass_in_EPackage(package, PARAMETERSET_CLASS);
	
	m_parameterSet_Attribute_condition = factory->createEReference_in_EContainingClass(m_parameterSet_Class, PARAMETERSET_ATTRIBUTE_CONDITION);
	m_parameterSet_Attribute_parameter = factory->createEReference_in_EContainingClass(m_parameterSet_Class, PARAMETERSET_ATTRIBUTE_PARAMETER);
	
	m_parameterSet_Operation_input_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_parameterSet_Class, PARAMETERSET_OPERATION_INPUT_EDIAGNOSTICCHAIN_EMAP);
	m_parameterSet_Operation_same_parameterized_entity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_parameterSet_Class, PARAMETERSET_OPERATION_SAME_PARAMETERIZED_ENTITY_EDIAGNOSTICCHAIN_EMAP);
	m_parameterSet_Operation_two_parameter_sets_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_parameterSet_Class, PARAMETERSET_OPERATION_TWO_PARAMETER_SETS_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createParameterableElementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_parameterableElement_Class = factory->createEClass_in_EPackage(package, PARAMETERABLEELEMENT_CLASS);
	
	m_parameterableElement_Attribute_owningTemplateParameter = factory->createEReference_in_EContainingClass(m_parameterableElement_Class, PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER);
	m_parameterableElement_Attribute_templateParameter = factory->createEReference_in_EContainingClass(m_parameterableElement_Class, PARAMETERABLEELEMENT_ATTRIBUTE_TEMPLATEPARAMETER);
	
	m_parameterableElement_Operation_isCompatibleWith_ParameterableElement = factory->createEOperation_in_EContainingClass(m_parameterableElement_Class, PARAMETERABLEELEMENT_OPERATION_ISCOMPATIBLEWITH_PARAMETERABLEELEMENT);
	m_parameterableElement_Operation_isTemplateParameter = factory->createEOperation_in_EContainingClass(m_parameterableElement_Class, PARAMETERABLEELEMENT_OPERATION_ISTEMPLATEPARAMETER);
	
}

void UmlPackageImpl::createPartDecompositionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_partDecomposition_Class = factory->createEClass_in_EPackage(package, PARTDECOMPOSITION_CLASS);
	
	
	m_partDecomposition_Operation_assume_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_partDecomposition_Class, PARTDECOMPOSITION_OPERATION_ASSUME_EDIAGNOSTICCHAIN_EMAP);
	m_partDecomposition_Operation_commutativity_of_decomposition_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_partDecomposition_Class, PARTDECOMPOSITION_OPERATION_COMMUTATIVITY_OF_DECOMPOSITION_EDIAGNOSTICCHAIN_EMAP);
	m_partDecomposition_Operation_parts_of_internal_structures_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_partDecomposition_Class, PARTDECOMPOSITION_OPERATION_PARTS_OF_INTERNAL_STRUCTURES_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createPinContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_pin_Class = factory->createEClass_in_EPackage(package, PIN_CLASS);
	m_pin_Attribute_isControl = factory->createEAttribute_in_EContainingClass(m_pin_Class, PIN_ATTRIBUTE_ISCONTROL);
	
	
	m_pin_Operation_control_pins_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_pin_Class, PIN_OPERATION_CONTROL_PINS_EDIAGNOSTICCHAIN_EMAP);
	m_pin_Operation_not_unique_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_pin_Class, PIN_OPERATION_NOT_UNIQUE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createPortContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_port_Class = factory->createEClass_in_EPackage(package, PORT_CLASS);
	m_port_Attribute_isBehavior = factory->createEAttribute_in_EContainingClass(m_port_Class, PORT_ATTRIBUTE_ISBEHAVIOR);
	m_port_Attribute_isConjugated = factory->createEAttribute_in_EContainingClass(m_port_Class, PORT_ATTRIBUTE_ISCONJUGATED);
	m_port_Attribute_isService = factory->createEAttribute_in_EContainingClass(m_port_Class, PORT_ATTRIBUTE_ISSERVICE);
	
	m_port_Attribute_protocol = factory->createEReference_in_EContainingClass(m_port_Class, PORT_ATTRIBUTE_PROTOCOL);
	m_port_Attribute_provided = factory->createEReference_in_EContainingClass(m_port_Class, PORT_ATTRIBUTE_PROVIDED);
	m_port_Attribute_redefinedPort = factory->createEReference_in_EContainingClass(m_port_Class, PORT_ATTRIBUTE_REDEFINEDPORT);
	m_port_Attribute_required = factory->createEReference_in_EContainingClass(m_port_Class, PORT_ATTRIBUTE_REQUIRED);
	
	m_port_Operation_basicProvided = factory->createEOperation_in_EContainingClass(m_port_Class, PORT_OPERATION_BASICPROVIDED);
	m_port_Operation_basicRequired = factory->createEOperation_in_EContainingClass(m_port_Class, PORT_OPERATION_BASICREQUIRED);
	m_port_Operation_default_value_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_port_Class, PORT_OPERATION_DEFAULT_VALUE_EDIAGNOSTICCHAIN_EMAP);
	m_port_Operation_encapsulated_owner_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_port_Class, PORT_OPERATION_ENCAPSULATED_OWNER_EDIAGNOSTICCHAIN_EMAP);
	m_port_Operation_getProvideds = factory->createEOperation_in_EContainingClass(m_port_Class, PORT_OPERATION_GETPROVIDEDS);
	m_port_Operation_getRequireds = factory->createEOperation_in_EContainingClass(m_port_Class, PORT_OPERATION_GETREQUIREDS);
	m_port_Operation_port_aggregation_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_port_Class, PORT_OPERATION_PORT_AGGREGATION_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createPrimitiveTypeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_primitiveType_Class = factory->createEClass_in_EPackage(package, PRIMITIVETYPE_CLASS);
	
	
	
}

void UmlPackageImpl::createProfileContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_profile_Class = factory->createEClass_in_EPackage(package, PROFILE_CLASS);
	
	m_profile_Attribute_metaclassReference = factory->createEReference_in_EContainingClass(m_profile_Class, PROFILE_ATTRIBUTE_METACLASSREFERENCE);
	m_profile_Attribute_metamodelReference = factory->createEReference_in_EContainingClass(m_profile_Class, PROFILE_ATTRIBUTE_METAMODELREFERENCE);
	
	m_profile_Operation_create_Classifier = factory->createEOperation_in_EContainingClass(m_profile_Class, PROFILE_OPERATION_CREATE_CLASSIFIER);
	m_profile_Operation_define = factory->createEOperation_in_EContainingClass(m_profile_Class, PROFILE_OPERATION_DEFINE);
	m_profile_Operation_define_EMap_EMap = factory->createEOperation_in_EContainingClass(m_profile_Class, PROFILE_OPERATION_DEFINE_EMAP_EMAP);
	m_profile_Operation_getDefinition = factory->createEOperation_in_EContainingClass(m_profile_Class, PROFILE_OPERATION_GETDEFINITION);
	m_profile_Operation_getDefinition_NamedElement = factory->createEOperation_in_EContainingClass(m_profile_Class, PROFILE_OPERATION_GETDEFINITION_NAMEDELEMENT);
	m_profile_Operation_getOwnedExtensions_Boolean = factory->createEOperation_in_EContainingClass(m_profile_Class, PROFILE_OPERATION_GETOWNEDEXTENSIONS_BOOLEAN);
	m_profile_Operation_getReferencedMetaclasses = factory->createEOperation_in_EContainingClass(m_profile_Class, PROFILE_OPERATION_GETREFERENCEDMETACLASSES);
	m_profile_Operation_getReferencedMetamodels = factory->createEOperation_in_EContainingClass(m_profile_Class, PROFILE_OPERATION_GETREFERENCEDMETAMODELS);
	m_profile_Operation_isDefined = factory->createEOperation_in_EContainingClass(m_profile_Class, PROFILE_OPERATION_ISDEFINED);
	m_profile_Operation_metaclass_reference_not_specialized_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_profile_Class, PROFILE_OPERATION_METACLASS_REFERENCE_NOT_SPECIALIZED_EDIAGNOSTICCHAIN_EMAP);
	m_profile_Operation_references_same_metamodel_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_profile_Class, PROFILE_OPERATION_REFERENCES_SAME_METAMODEL_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createProfileApplicationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_profileApplication_Class = factory->createEClass_in_EPackage(package, PROFILEAPPLICATION_CLASS);
	m_profileApplication_Attribute_isStrict = factory->createEAttribute_in_EContainingClass(m_profileApplication_Class, PROFILEAPPLICATION_ATTRIBUTE_ISSTRICT);
	
	m_profileApplication_Attribute_appliedProfile = factory->createEReference_in_EContainingClass(m_profileApplication_Class, PROFILEAPPLICATION_ATTRIBUTE_APPLIEDPROFILE);
	m_profileApplication_Attribute_applyingPackage = factory->createEReference_in_EContainingClass(m_profileApplication_Class, PROFILEAPPLICATION_ATTRIBUTE_APPLYINGPACKAGE);
	
	m_profileApplication_Operation_getAppliedDefinition = factory->createEOperation_in_EContainingClass(m_profileApplication_Class, PROFILEAPPLICATION_OPERATION_GETAPPLIEDDEFINITION);
	m_profileApplication_Operation_getAppliedDefinition_NamedElement = factory->createEOperation_in_EContainingClass(m_profileApplication_Class, PROFILEAPPLICATION_OPERATION_GETAPPLIEDDEFINITION_NAMEDELEMENT);
	
}

void UmlPackageImpl::createPropertyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_property_Class = factory->createEClass_in_EPackage(package, PROPERTY_CLASS);
	m_property_Attribute_aggregation = factory->createEAttribute_in_EContainingClass(m_property_Class, PROPERTY_ATTRIBUTE_AGGREGATION);
	m_property_Attribute_default = factory->createEAttribute_in_EContainingClass(m_property_Class, PROPERTY_ATTRIBUTE_DEFAULT);
	m_property_Attribute_isComposite = factory->createEAttribute_in_EContainingClass(m_property_Class, PROPERTY_ATTRIBUTE_ISCOMPOSITE);
	m_property_Attribute_isDerived = factory->createEAttribute_in_EContainingClass(m_property_Class, PROPERTY_ATTRIBUTE_ISDERIVED);
	m_property_Attribute_isDerivedUnion = factory->createEAttribute_in_EContainingClass(m_property_Class, PROPERTY_ATTRIBUTE_ISDERIVEDUNION);
	m_property_Attribute_isID = factory->createEAttribute_in_EContainingClass(m_property_Class, PROPERTY_ATTRIBUTE_ISID);
	
	m_property_Attribute_association = factory->createEReference_in_EContainingClass(m_property_Class, PROPERTY_ATTRIBUTE_ASSOCIATION);
	m_property_Attribute_associationEnd = factory->createEReference_in_EContainingClass(m_property_Class, PROPERTY_ATTRIBUTE_ASSOCIATIONEND);
	m_property_Attribute_class = factory->createEReference_in_EContainingClass(m_property_Class, PROPERTY_ATTRIBUTE_CLASS);
	m_property_Attribute_datatype = factory->createEReference_in_EContainingClass(m_property_Class, PROPERTY_ATTRIBUTE_DATATYPE);
	m_property_Attribute_defaultValue = factory->createEReference_in_EContainingClass(m_property_Class, PROPERTY_ATTRIBUTE_DEFAULTVALUE);
	m_property_Attribute_interface = factory->createEReference_in_EContainingClass(m_property_Class, PROPERTY_ATTRIBUTE_INTERFACE);
	m_property_Attribute_opposite = factory->createEReference_in_EContainingClass(m_property_Class, PROPERTY_ATTRIBUTE_OPPOSITE);
	m_property_Attribute_owningAssociation = factory->createEReference_in_EContainingClass(m_property_Class, PROPERTY_ATTRIBUTE_OWNINGASSOCIATION);
	m_property_Attribute_qualifier = factory->createEReference_in_EContainingClass(m_property_Class, PROPERTY_ATTRIBUTE_QUALIFIER);
	m_property_Attribute_redefinedProperty = factory->createEReference_in_EContainingClass(m_property_Class, PROPERTY_ATTRIBUTE_REDEFINEDPROPERTY);
	m_property_Attribute_subsettedProperty = factory->createEReference_in_EContainingClass(m_property_Class, PROPERTY_ATTRIBUTE_SUBSETTEDPROPERTY);
	
	m_property_Operation_binding_to_attribute_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_property_Class, PROPERTY_OPERATION_BINDING_TO_ATTRIBUTE_EDIAGNOSTICCHAIN_EMAP);
	m_property_Operation_deployment_target_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_property_Class, PROPERTY_OPERATION_DEPLOYMENT_TARGET_EDIAGNOSTICCHAIN_EMAP);
	m_property_Operation_derived_union_is_derived_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_property_Class, PROPERTY_OPERATION_DERIVED_UNION_IS_DERIVED_EDIAGNOSTICCHAIN_EMAP);
	m_property_Operation_derived_union_is_read_only_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_property_Class, PROPERTY_OPERATION_DERIVED_UNION_IS_READ_ONLY_EDIAGNOSTICCHAIN_EMAP);
	m_property_Operation_getOpposite = factory->createEOperation_in_EContainingClass(m_property_Class, PROPERTY_OPERATION_GETOPPOSITE);
	m_property_Operation_getOtherEnd = factory->createEOperation_in_EContainingClass(m_property_Class, PROPERTY_OPERATION_GETOTHEREND);
	m_property_Operation_isAttribute = factory->createEOperation_in_EContainingClass(m_property_Class, PROPERTY_OPERATION_ISATTRIBUTE);
	m_property_Operation_isComposite = factory->createEOperation_in_EContainingClass(m_property_Class, PROPERTY_OPERATION_ISCOMPOSITE);
	m_property_Operation_isNavigable = factory->createEOperation_in_EContainingClass(m_property_Class, PROPERTY_OPERATION_ISNAVIGABLE);
	m_property_Operation_isSetDefault = factory->createEOperation_in_EContainingClass(m_property_Class, PROPERTY_OPERATION_ISSETDEFAULT);
	m_property_Operation_multiplicity_of_composite_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_property_Class, PROPERTY_OPERATION_MULTIPLICITY_OF_COMPOSITE_EDIAGNOSTICCHAIN_EMAP);
	m_property_Operation_qualified_is_association_end_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_property_Class, PROPERTY_OPERATION_QUALIFIED_IS_ASSOCIATION_END_EDIAGNOSTICCHAIN_EMAP);
	m_property_Operation_redefined_property_inherited_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_property_Class, PROPERTY_OPERATION_REDEFINED_PROPERTY_INHERITED_EDIAGNOSTICCHAIN_EMAP);
	m_property_Operation_setBooleanDefaultValue_Boolean = factory->createEOperation_in_EContainingClass(m_property_Class, PROPERTY_OPERATION_SETBOOLEANDEFAULTVALUE_BOOLEAN);
	m_property_Operation_setIntegerDefaultValue_Integer = factory->createEOperation_in_EContainingClass(m_property_Class, PROPERTY_OPERATION_SETINTEGERDEFAULTVALUE_INTEGER);
	m_property_Operation_setIsNavigable_Boolean = factory->createEOperation_in_EContainingClass(m_property_Class, PROPERTY_OPERATION_SETISNAVIGABLE_BOOLEAN);
	m_property_Operation_setNullDefaultValue = factory->createEOperation_in_EContainingClass(m_property_Class, PROPERTY_OPERATION_SETNULLDEFAULTVALUE);
	m_property_Operation_setRealDefaultValue_Real = factory->createEOperation_in_EContainingClass(m_property_Class, PROPERTY_OPERATION_SETREALDEFAULTVALUE_REAL);
	m_property_Operation_setStringDefaultValue_String = factory->createEOperation_in_EContainingClass(m_property_Class, PROPERTY_OPERATION_SETSTRINGDEFAULTVALUE_STRING);
	m_property_Operation_setUnlimitedNaturalDefaultValue_UnlimitedNatural = factory->createEOperation_in_EContainingClass(m_property_Class, PROPERTY_OPERATION_SETUNLIMITEDNATURALDEFAULTVALUE_UNLIMITEDNATURAL);
	m_property_Operation_subsetted_property_names_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_property_Class, PROPERTY_OPERATION_SUBSETTED_PROPERTY_NAMES_EDIAGNOSTICCHAIN_EMAP);
	m_property_Operation_subsettingContext = factory->createEOperation_in_EContainingClass(m_property_Class, PROPERTY_OPERATION_SUBSETTINGCONTEXT);
	m_property_Operation_subsetting_context_conforms_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_property_Class, PROPERTY_OPERATION_SUBSETTING_CONTEXT_CONFORMS_EDIAGNOSTICCHAIN_EMAP);
	m_property_Operation_subsetting_rules_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_property_Class, PROPERTY_OPERATION_SUBSETTING_RULES_EDIAGNOSTICCHAIN_EMAP);
	m_property_Operation_type_of_opposite_end_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_property_Class, PROPERTY_OPERATION_TYPE_OF_OPPOSITE_END_EDIAGNOSTICCHAIN_EMAP);
	m_property_Operation_unsetDefault = factory->createEOperation_in_EContainingClass(m_property_Class, PROPERTY_OPERATION_UNSETDEFAULT);
	
}

void UmlPackageImpl::createProtocolConformanceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_protocolConformance_Class = factory->createEClass_in_EPackage(package, PROTOCOLCONFORMANCE_CLASS);
	
	m_protocolConformance_Attribute_generalMachine = factory->createEReference_in_EContainingClass(m_protocolConformance_Class, PROTOCOLCONFORMANCE_ATTRIBUTE_GENERALMACHINE);
	m_protocolConformance_Attribute_specificMachine = factory->createEReference_in_EContainingClass(m_protocolConformance_Class, PROTOCOLCONFORMANCE_ATTRIBUTE_SPECIFICMACHINE);
	
	
}

void UmlPackageImpl::createProtocolStateMachineContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_protocolStateMachine_Class = factory->createEClass_in_EPackage(package, PROTOCOLSTATEMACHINE_CLASS);
	
	m_protocolStateMachine_Attribute_conformance = factory->createEReference_in_EContainingClass(m_protocolStateMachine_Class, PROTOCOLSTATEMACHINE_ATTRIBUTE_CONFORMANCE);
	
	m_protocolStateMachine_Operation_deep_or_shallow_history_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_protocolStateMachine_Class, PROTOCOLSTATEMACHINE_OPERATION_DEEP_OR_SHALLOW_HISTORY_EDIAGNOSTICCHAIN_EMAP);
	m_protocolStateMachine_Operation_entry_exit_do_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_protocolStateMachine_Class, PROTOCOLSTATEMACHINE_OPERATION_ENTRY_EXIT_DO_EDIAGNOSTICCHAIN_EMAP);
	m_protocolStateMachine_Operation_protocol_transitions_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_protocolStateMachine_Class, PROTOCOLSTATEMACHINE_OPERATION_PROTOCOL_TRANSITIONS_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createProtocolTransitionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_protocolTransition_Class = factory->createEClass_in_EPackage(package, PROTOCOLTRANSITION_CLASS);
	
	m_protocolTransition_Attribute_postCondition = factory->createEReference_in_EContainingClass(m_protocolTransition_Class, PROTOCOLTRANSITION_ATTRIBUTE_POSTCONDITION);
	m_protocolTransition_Attribute_preCondition = factory->createEReference_in_EContainingClass(m_protocolTransition_Class, PROTOCOLTRANSITION_ATTRIBUTE_PRECONDITION);
	m_protocolTransition_Attribute_referred = factory->createEReference_in_EContainingClass(m_protocolTransition_Class, PROTOCOLTRANSITION_ATTRIBUTE_REFERRED);
	
	m_protocolTransition_Operation_associated_actions_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_protocolTransition_Class, PROTOCOLTRANSITION_OPERATION_ASSOCIATED_ACTIONS_EDIAGNOSTICCHAIN_EMAP);
	m_protocolTransition_Operation_belongs_to_psm_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_protocolTransition_Class, PROTOCOLTRANSITION_OPERATION_BELONGS_TO_PSM_EDIAGNOSTICCHAIN_EMAP);
	m_protocolTransition_Operation_getReferreds = factory->createEOperation_in_EContainingClass(m_protocolTransition_Class, PROTOCOLTRANSITION_OPERATION_GETREFERREDS);
	m_protocolTransition_Operation_refers_to_operation_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_protocolTransition_Class, PROTOCOLTRANSITION_OPERATION_REFERS_TO_OPERATION_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createPseudostateContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_pseudostate_Class = factory->createEClass_in_EPackage(package, PSEUDOSTATE_CLASS);
	m_pseudostate_Attribute_kind = factory->createEAttribute_in_EContainingClass(m_pseudostate_Class, PSEUDOSTATE_ATTRIBUTE_KIND);
	
	m_pseudostate_Attribute_state = factory->createEReference_in_EContainingClass(m_pseudostate_Class, PSEUDOSTATE_ATTRIBUTE_STATE);
	m_pseudostate_Attribute_stateMachine = factory->createEReference_in_EContainingClass(m_pseudostate_Class, PSEUDOSTATE_ATTRIBUTE_STATEMACHINE);
	
	m_pseudostate_Operation_choice_vertex_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_pseudostate_Class, PSEUDOSTATE_OPERATION_CHOICE_VERTEX_EDIAGNOSTICCHAIN_EMAP);
	m_pseudostate_Operation_fork_vertex_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_pseudostate_Class, PSEUDOSTATE_OPERATION_FORK_VERTEX_EDIAGNOSTICCHAIN_EMAP);
	m_pseudostate_Operation_history_vertices_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_pseudostate_Class, PSEUDOSTATE_OPERATION_HISTORY_VERTICES_EDIAGNOSTICCHAIN_EMAP);
	m_pseudostate_Operation_initial_vertex_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_pseudostate_Class, PSEUDOSTATE_OPERATION_INITIAL_VERTEX_EDIAGNOSTICCHAIN_EMAP);
	m_pseudostate_Operation_join_vertex_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_pseudostate_Class, PSEUDOSTATE_OPERATION_JOIN_VERTEX_EDIAGNOSTICCHAIN_EMAP);
	m_pseudostate_Operation_junction_vertex_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_pseudostate_Class, PSEUDOSTATE_OPERATION_JUNCTION_VERTEX_EDIAGNOSTICCHAIN_EMAP);
	m_pseudostate_Operation_outgoing_from_initial_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_pseudostate_Class, PSEUDOSTATE_OPERATION_OUTGOING_FROM_INITIAL_EDIAGNOSTICCHAIN_EMAP);
	m_pseudostate_Operation_transitions_incoming_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_pseudostate_Class, PSEUDOSTATE_OPERATION_TRANSITIONS_INCOMING_EDIAGNOSTICCHAIN_EMAP);
	m_pseudostate_Operation_transitions_outgoing_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_pseudostate_Class, PSEUDOSTATE_OPERATION_TRANSITIONS_OUTGOING_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createQualifierValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_qualifierValue_Class = factory->createEClass_in_EPackage(package, QUALIFIERVALUE_CLASS);
	
	m_qualifierValue_Attribute_qualifier = factory->createEReference_in_EContainingClass(m_qualifierValue_Class, QUALIFIERVALUE_ATTRIBUTE_QUALIFIER);
	m_qualifierValue_Attribute_value = factory->createEReference_in_EContainingClass(m_qualifierValue_Class, QUALIFIERVALUE_ATTRIBUTE_VALUE);
	
	m_qualifierValue_Operation_multiplicity_of_qualifier_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_qualifierValue_Class, QUALIFIERVALUE_OPERATION_MULTIPLICITY_OF_QUALIFIER_EDIAGNOSTICCHAIN_EMAP);
	m_qualifierValue_Operation_qualifier_attribute_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_qualifierValue_Class, QUALIFIERVALUE_OPERATION_QUALIFIER_ATTRIBUTE_EDIAGNOSTICCHAIN_EMAP);
	m_qualifierValue_Operation_type_of_qualifier_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_qualifierValue_Class, QUALIFIERVALUE_OPERATION_TYPE_OF_QUALIFIER_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createRaiseExceptionActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_raiseExceptionAction_Class = factory->createEClass_in_EPackage(package, RAISEEXCEPTIONACTION_CLASS);
	
	m_raiseExceptionAction_Attribute_exception = factory->createEReference_in_EContainingClass(m_raiseExceptionAction_Class, RAISEEXCEPTIONACTION_ATTRIBUTE_EXCEPTION);
	
	
}

void UmlPackageImpl::createReadExtentActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_readExtentAction_Class = factory->createEClass_in_EPackage(package, READEXTENTACTION_CLASS);
	
	m_readExtentAction_Attribute_classifier = factory->createEReference_in_EContainingClass(m_readExtentAction_Class, READEXTENTACTION_ATTRIBUTE_CLASSIFIER);
	m_readExtentAction_Attribute_result = factory->createEReference_in_EContainingClass(m_readExtentAction_Class, READEXTENTACTION_ATTRIBUTE_RESULT);
	
	m_readExtentAction_Operation_multiplicity_of_result_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readExtentAction_Class, READEXTENTACTION_OPERATION_MULTIPLICITY_OF_RESULT_EDIAGNOSTICCHAIN_EMAP);
	m_readExtentAction_Operation_type_is_classifier_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readExtentAction_Class, READEXTENTACTION_OPERATION_TYPE_IS_CLASSIFIER_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createReadIsClassifiedObjectActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_readIsClassifiedObjectAction_Class = factory->createEClass_in_EPackage(package, READISCLASSIFIEDOBJECTACTION_CLASS);
	m_readIsClassifiedObjectAction_Attribute_isDirect = factory->createEAttribute_in_EContainingClass(m_readIsClassifiedObjectAction_Class, READISCLASSIFIEDOBJECTACTION_ATTRIBUTE_ISDIRECT);
	
	m_readIsClassifiedObjectAction_Attribute_classifier = factory->createEReference_in_EContainingClass(m_readIsClassifiedObjectAction_Class, READISCLASSIFIEDOBJECTACTION_ATTRIBUTE_CLASSIFIER);
	m_readIsClassifiedObjectAction_Attribute_object = factory->createEReference_in_EContainingClass(m_readIsClassifiedObjectAction_Class, READISCLASSIFIEDOBJECTACTION_ATTRIBUTE_OBJECT);
	m_readIsClassifiedObjectAction_Attribute_result = factory->createEReference_in_EContainingClass(m_readIsClassifiedObjectAction_Class, READISCLASSIFIEDOBJECTACTION_ATTRIBUTE_RESULT);
	
	m_readIsClassifiedObjectAction_Operation_boolean_result_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readIsClassifiedObjectAction_Class, READISCLASSIFIEDOBJECTACTION_OPERATION_BOOLEAN_RESULT_EDIAGNOSTICCHAIN_EMAP);
	m_readIsClassifiedObjectAction_Operation_multiplicity_of_input_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readIsClassifiedObjectAction_Class, READISCLASSIFIEDOBJECTACTION_OPERATION_MULTIPLICITY_OF_INPUT_EDIAGNOSTICCHAIN_EMAP);
	m_readIsClassifiedObjectAction_Operation_multiplicity_of_output_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readIsClassifiedObjectAction_Class, READISCLASSIFIEDOBJECTACTION_OPERATION_MULTIPLICITY_OF_OUTPUT_EDIAGNOSTICCHAIN_EMAP);
	m_readIsClassifiedObjectAction_Operation_no_type_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readIsClassifiedObjectAction_Class, READISCLASSIFIEDOBJECTACTION_OPERATION_NO_TYPE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createReadLinkActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_readLinkAction_Class = factory->createEClass_in_EPackage(package, READLINKACTION_CLASS);
	
	m_readLinkAction_Attribute_result = factory->createEReference_in_EContainingClass(m_readLinkAction_Class, READLINKACTION_ATTRIBUTE_RESULT);
	
	m_readLinkAction_Operation_compatible_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readLinkAction_Class, READLINKACTION_OPERATION_COMPATIBLE_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	m_readLinkAction_Operation_navigable_open_end_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readLinkAction_Class, READLINKACTION_OPERATION_NAVIGABLE_OPEN_END_EDIAGNOSTICCHAIN_EMAP);
	m_readLinkAction_Operation_one_open_end_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readLinkAction_Class, READLINKACTION_OPERATION_ONE_OPEN_END_EDIAGNOSTICCHAIN_EMAP);
	m_readLinkAction_Operation_openEnd = factory->createEOperation_in_EContainingClass(m_readLinkAction_Class, READLINKACTION_OPERATION_OPENEND);
	m_readLinkAction_Operation_type_and_ordering_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readLinkAction_Class, READLINKACTION_OPERATION_TYPE_AND_ORDERING_EDIAGNOSTICCHAIN_EMAP);
	m_readLinkAction_Operation_visibility_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readLinkAction_Class, READLINKACTION_OPERATION_VISIBILITY_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createReadLinkObjectEndActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_readLinkObjectEndAction_Class = factory->createEClass_in_EPackage(package, READLINKOBJECTENDACTION_CLASS);
	
	m_readLinkObjectEndAction_Attribute_end = factory->createEReference_in_EContainingClass(m_readLinkObjectEndAction_Class, READLINKOBJECTENDACTION_ATTRIBUTE_END);
	m_readLinkObjectEndAction_Attribute_object = factory->createEReference_in_EContainingClass(m_readLinkObjectEndAction_Class, READLINKOBJECTENDACTION_ATTRIBUTE_OBJECT);
	m_readLinkObjectEndAction_Attribute_result = factory->createEReference_in_EContainingClass(m_readLinkObjectEndAction_Class, READLINKOBJECTENDACTION_ATTRIBUTE_RESULT);
	
	m_readLinkObjectEndAction_Operation_association_of_association_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readLinkObjectEndAction_Class, READLINKOBJECTENDACTION_OPERATION_ASSOCIATION_OF_ASSOCIATION_EDIAGNOSTICCHAIN_EMAP);
	m_readLinkObjectEndAction_Operation_ends_of_association_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readLinkObjectEndAction_Class, READLINKOBJECTENDACTION_OPERATION_ENDS_OF_ASSOCIATION_EDIAGNOSTICCHAIN_EMAP);
	m_readLinkObjectEndAction_Operation_multiplicity_of_object_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readLinkObjectEndAction_Class, READLINKOBJECTENDACTION_OPERATION_MULTIPLICITY_OF_OBJECT_EDIAGNOSTICCHAIN_EMAP);
	m_readLinkObjectEndAction_Operation_multiplicity_of_result_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readLinkObjectEndAction_Class, READLINKOBJECTENDACTION_OPERATION_MULTIPLICITY_OF_RESULT_EDIAGNOSTICCHAIN_EMAP);
	m_readLinkObjectEndAction_Operation_property_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readLinkObjectEndAction_Class, READLINKOBJECTENDACTION_OPERATION_PROPERTY_EDIAGNOSTICCHAIN_EMAP);
	m_readLinkObjectEndAction_Operation_type_of_object_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readLinkObjectEndAction_Class, READLINKOBJECTENDACTION_OPERATION_TYPE_OF_OBJECT_EDIAGNOSTICCHAIN_EMAP);
	m_readLinkObjectEndAction_Operation_type_of_result_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readLinkObjectEndAction_Class, READLINKOBJECTENDACTION_OPERATION_TYPE_OF_RESULT_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createReadLinkObjectEndQualifierActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_readLinkObjectEndQualifierAction_Class = factory->createEClass_in_EPackage(package, READLINKOBJECTENDQUALIFIERACTION_CLASS);
	
	m_readLinkObjectEndQualifierAction_Attribute_object = factory->createEReference_in_EContainingClass(m_readLinkObjectEndQualifierAction_Class, READLINKOBJECTENDQUALIFIERACTION_ATTRIBUTE_OBJECT);
	m_readLinkObjectEndQualifierAction_Attribute_qualifier = factory->createEReference_in_EContainingClass(m_readLinkObjectEndQualifierAction_Class, READLINKOBJECTENDQUALIFIERACTION_ATTRIBUTE_QUALIFIER);
	m_readLinkObjectEndQualifierAction_Attribute_result = factory->createEReference_in_EContainingClass(m_readLinkObjectEndQualifierAction_Class, READLINKOBJECTENDQUALIFIERACTION_ATTRIBUTE_RESULT);
	
	m_readLinkObjectEndQualifierAction_Operation_association_of_association_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readLinkObjectEndQualifierAction_Class, READLINKOBJECTENDQUALIFIERACTION_OPERATION_ASSOCIATION_OF_ASSOCIATION_EDIAGNOSTICCHAIN_EMAP);
	m_readLinkObjectEndQualifierAction_Operation_ends_of_association_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readLinkObjectEndQualifierAction_Class, READLINKOBJECTENDQUALIFIERACTION_OPERATION_ENDS_OF_ASSOCIATION_EDIAGNOSTICCHAIN_EMAP);
	m_readLinkObjectEndQualifierAction_Operation_multiplicity_of_object_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readLinkObjectEndQualifierAction_Class, READLINKOBJECTENDQUALIFIERACTION_OPERATION_MULTIPLICITY_OF_OBJECT_EDIAGNOSTICCHAIN_EMAP);
	m_readLinkObjectEndQualifierAction_Operation_multiplicity_of_qualifier_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readLinkObjectEndQualifierAction_Class, READLINKOBJECTENDQUALIFIERACTION_OPERATION_MULTIPLICITY_OF_QUALIFIER_EDIAGNOSTICCHAIN_EMAP);
	m_readLinkObjectEndQualifierAction_Operation_multiplicity_of_result_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readLinkObjectEndQualifierAction_Class, READLINKOBJECTENDQUALIFIERACTION_OPERATION_MULTIPLICITY_OF_RESULT_EDIAGNOSTICCHAIN_EMAP);
	m_readLinkObjectEndQualifierAction_Operation_qualifier_attribute_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readLinkObjectEndQualifierAction_Class, READLINKOBJECTENDQUALIFIERACTION_OPERATION_QUALIFIER_ATTRIBUTE_EDIAGNOSTICCHAIN_EMAP);
	m_readLinkObjectEndQualifierAction_Operation_same_type_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readLinkObjectEndQualifierAction_Class, READLINKOBJECTENDQUALIFIERACTION_OPERATION_SAME_TYPE_EDIAGNOSTICCHAIN_EMAP);
	m_readLinkObjectEndQualifierAction_Operation_type_of_object_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readLinkObjectEndQualifierAction_Class, READLINKOBJECTENDQUALIFIERACTION_OPERATION_TYPE_OF_OBJECT_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createReadSelfActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_readSelfAction_Class = factory->createEClass_in_EPackage(package, READSELFACTION_CLASS);
	
	m_readSelfAction_Attribute_result = factory->createEReference_in_EContainingClass(m_readSelfAction_Class, READSELFACTION_ATTRIBUTE_RESULT);
	
	m_readSelfAction_Operation_contained_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readSelfAction_Class, READSELFACTION_OPERATION_CONTAINED_EDIAGNOSTICCHAIN_EMAP);
	m_readSelfAction_Operation_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readSelfAction_Class, READSELFACTION_OPERATION_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	m_readSelfAction_Operation_not_static_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readSelfAction_Class, READSELFACTION_OPERATION_NOT_STATIC_EDIAGNOSTICCHAIN_EMAP);
	m_readSelfAction_Operation_type_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readSelfAction_Class, READSELFACTION_OPERATION_TYPE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createReadStructuralFeatureActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_readStructuralFeatureAction_Class = factory->createEClass_in_EPackage(package, READSTRUCTURALFEATUREACTION_CLASS);
	
	m_readStructuralFeatureAction_Attribute_result = factory->createEReference_in_EContainingClass(m_readStructuralFeatureAction_Class, READSTRUCTURALFEATUREACTION_ATTRIBUTE_RESULT);
	
	m_readStructuralFeatureAction_Operation_type_and_ordering_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readStructuralFeatureAction_Class, READSTRUCTURALFEATUREACTION_OPERATION_TYPE_AND_ORDERING_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createReadVariableActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_readVariableAction_Class = factory->createEClass_in_EPackage(package, READVARIABLEACTION_CLASS);
	
	m_readVariableAction_Attribute_result = factory->createEReference_in_EContainingClass(m_readVariableAction_Class, READVARIABLEACTION_ATTRIBUTE_RESULT);
	
	m_readVariableAction_Operation_compatible_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readVariableAction_Class, READVARIABLEACTION_OPERATION_COMPATIBLE_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	m_readVariableAction_Operation_type_and_ordering_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readVariableAction_Class, READVARIABLEACTION_OPERATION_TYPE_AND_ORDERING_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createRealizationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_realization_Class = factory->createEClass_in_EPackage(package, REALIZATION_CLASS);
	
	
	
}

void UmlPackageImpl::createReceptionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_reception_Class = factory->createEClass_in_EPackage(package, RECEPTION_CLASS);
	
	m_reception_Attribute_signal = factory->createEReference_in_EContainingClass(m_reception_Class, RECEPTION_ATTRIBUTE_SIGNAL);
	
	m_reception_Operation_same_name_as_signal_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_reception_Class, RECEPTION_OPERATION_SAME_NAME_AS_SIGNAL_EDIAGNOSTICCHAIN_EMAP);
	m_reception_Operation_same_structure_as_signal_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_reception_Class, RECEPTION_OPERATION_SAME_STRUCTURE_AS_SIGNAL_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createReclassifyObjectActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_reclassifyObjectAction_Class = factory->createEClass_in_EPackage(package, RECLASSIFYOBJECTACTION_CLASS);
	m_reclassifyObjectAction_Attribute_isReplaceAll = factory->createEAttribute_in_EContainingClass(m_reclassifyObjectAction_Class, RECLASSIFYOBJECTACTION_ATTRIBUTE_ISREPLACEALL);
	
	m_reclassifyObjectAction_Attribute_newClassifier = factory->createEReference_in_EContainingClass(m_reclassifyObjectAction_Class, RECLASSIFYOBJECTACTION_ATTRIBUTE_NEWCLASSIFIER);
	m_reclassifyObjectAction_Attribute_object = factory->createEReference_in_EContainingClass(m_reclassifyObjectAction_Class, RECLASSIFYOBJECTACTION_ATTRIBUTE_OBJECT);
	m_reclassifyObjectAction_Attribute_oldClassifier = factory->createEReference_in_EContainingClass(m_reclassifyObjectAction_Class, RECLASSIFYOBJECTACTION_ATTRIBUTE_OLDCLASSIFIER);
	
	m_reclassifyObjectAction_Operation_classifier_not_abstract_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_reclassifyObjectAction_Class, RECLASSIFYOBJECTACTION_OPERATION_CLASSIFIER_NOT_ABSTRACT_EDIAGNOSTICCHAIN_EMAP);
	m_reclassifyObjectAction_Operation_input_pin_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_reclassifyObjectAction_Class, RECLASSIFYOBJECTACTION_OPERATION_INPUT_PIN_EDIAGNOSTICCHAIN_EMAP);
	m_reclassifyObjectAction_Operation_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_reclassifyObjectAction_Class, RECLASSIFYOBJECTACTION_OPERATION_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createRedefinableElementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_redefinableElement_Class = factory->createEClass_in_EPackage(package, REDEFINABLEELEMENT_CLASS);
	m_redefinableElement_Attribute_isLeaf = factory->createEAttribute_in_EContainingClass(m_redefinableElement_Class, REDEFINABLEELEMENT_ATTRIBUTE_ISLEAF);
	
	m_redefinableElement_Attribute_redefinedElement = factory->createEReference_in_EContainingClass(m_redefinableElement_Class, REDEFINABLEELEMENT_ATTRIBUTE_REDEFINEDELEMENT);
	m_redefinableElement_Attribute_redefinitionContext = factory->createEReference_in_EContainingClass(m_redefinableElement_Class, REDEFINABLEELEMENT_ATTRIBUTE_REDEFINITIONCONTEXT);
	
	m_redefinableElement_Operation_isConsistentWith_RedefinableElement = factory->createEOperation_in_EContainingClass(m_redefinableElement_Class, REDEFINABLEELEMENT_OPERATION_ISCONSISTENTWITH_REDEFINABLEELEMENT);
	m_redefinableElement_Operation_isRedefinitionContextValid_RedefinableElement = factory->createEOperation_in_EContainingClass(m_redefinableElement_Class, REDEFINABLEELEMENT_OPERATION_ISREDEFINITIONCONTEXTVALID_REDEFINABLEELEMENT);
	m_redefinableElement_Operation_non_leaf_redefinition_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_redefinableElement_Class, REDEFINABLEELEMENT_OPERATION_NON_LEAF_REDEFINITION_EDIAGNOSTICCHAIN_EMAP);
	m_redefinableElement_Operation_redefinition_consistent_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_redefinableElement_Class, REDEFINABLEELEMENT_OPERATION_REDEFINITION_CONSISTENT_EDIAGNOSTICCHAIN_EMAP);
	m_redefinableElement_Operation_redefinition_context_valid_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_redefinableElement_Class, REDEFINABLEELEMENT_OPERATION_REDEFINITION_CONTEXT_VALID_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createRedefinableTemplateSignatureContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_redefinableTemplateSignature_Class = factory->createEClass_in_EPackage(package, REDEFINABLETEMPLATESIGNATURE_CLASS);
	
	m_redefinableTemplateSignature_Attribute_classifier = factory->createEReference_in_EContainingClass(m_redefinableTemplateSignature_Class, REDEFINABLETEMPLATESIGNATURE_ATTRIBUTE_CLASSIFIER);
	m_redefinableTemplateSignature_Attribute_extendedSignature = factory->createEReference_in_EContainingClass(m_redefinableTemplateSignature_Class, REDEFINABLETEMPLATESIGNATURE_ATTRIBUTE_EXTENDEDSIGNATURE);
	m_redefinableTemplateSignature_Attribute_inheritedParameter = factory->createEReference_in_EContainingClass(m_redefinableTemplateSignature_Class, REDEFINABLETEMPLATESIGNATURE_ATTRIBUTE_INHERITEDPARAMETER);
	
	m_redefinableTemplateSignature_Operation_getInheritedParameters = factory->createEOperation_in_EContainingClass(m_redefinableTemplateSignature_Class, REDEFINABLETEMPLATESIGNATURE_OPERATION_GETINHERITEDPARAMETERS);
	m_redefinableTemplateSignature_Operation_redefines_parents_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_redefinableTemplateSignature_Class, REDEFINABLETEMPLATESIGNATURE_OPERATION_REDEFINES_PARENTS_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createReduceActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_reduceAction_Class = factory->createEClass_in_EPackage(package, REDUCEACTION_CLASS);
	m_reduceAction_Attribute_isOrdered = factory->createEAttribute_in_EContainingClass(m_reduceAction_Class, REDUCEACTION_ATTRIBUTE_ISORDERED);
	
	m_reduceAction_Attribute_collection = factory->createEReference_in_EContainingClass(m_reduceAction_Class, REDUCEACTION_ATTRIBUTE_COLLECTION);
	m_reduceAction_Attribute_reducer = factory->createEReference_in_EContainingClass(m_reduceAction_Class, REDUCEACTION_ATTRIBUTE_REDUCER);
	m_reduceAction_Attribute_result = factory->createEReference_in_EContainingClass(m_reduceAction_Class, REDUCEACTION_ATTRIBUTE_RESULT);
	
	m_reduceAction_Operation_input_type_is_collection_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_reduceAction_Class, REDUCEACTION_OPERATION_INPUT_TYPE_IS_COLLECTION_EDIAGNOSTICCHAIN_EMAP);
	m_reduceAction_Operation_output_types_are_compatible_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_reduceAction_Class, REDUCEACTION_OPERATION_OUTPUT_TYPES_ARE_COMPATIBLE_EDIAGNOSTICCHAIN_EMAP);
	m_reduceAction_Operation_reducer_inputs_output_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_reduceAction_Class, REDUCEACTION_OPERATION_REDUCER_INPUTS_OUTPUT_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createRegionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_region_Class = factory->createEClass_in_EPackage(package, REGION_CLASS);
	
	m_region_Attribute_extendedRegion = factory->createEReference_in_EContainingClass(m_region_Class, REGION_ATTRIBUTE_EXTENDEDREGION);
	m_region_Attribute_state = factory->createEReference_in_EContainingClass(m_region_Class, REGION_ATTRIBUTE_STATE);
	m_region_Attribute_stateMachine = factory->createEReference_in_EContainingClass(m_region_Class, REGION_ATTRIBUTE_STATEMACHINE);
	m_region_Attribute_subvertex = factory->createEReference_in_EContainingClass(m_region_Class, REGION_ATTRIBUTE_SUBVERTEX);
	m_region_Attribute_transition = factory->createEReference_in_EContainingClass(m_region_Class, REGION_ATTRIBUTE_TRANSITION);
	
	m_region_Operation_belongsToPSM = factory->createEOperation_in_EContainingClass(m_region_Class, REGION_OPERATION_BELONGSTOPSM);
	m_region_Operation_containingStateMachine = factory->createEOperation_in_EContainingClass(m_region_Class, REGION_OPERATION_CONTAININGSTATEMACHINE);
	m_region_Operation_deep_history_vertex_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_region_Class, REGION_OPERATION_DEEP_HISTORY_VERTEX_EDIAGNOSTICCHAIN_EMAP);
	m_region_Operation_initial_vertex_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_region_Class, REGION_OPERATION_INITIAL_VERTEX_EDIAGNOSTICCHAIN_EMAP);
	m_region_Operation_owned_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_region_Class, REGION_OPERATION_OWNED_EDIAGNOSTICCHAIN_EMAP);
	m_region_Operation_redefinitionContext = factory->createEOperation_in_EContainingClass(m_region_Class, REGION_OPERATION_REDEFINITIONCONTEXT);
	m_region_Operation_shallow_history_vertex_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_region_Class, REGION_OPERATION_SHALLOW_HISTORY_VERTEX_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createRelationshipContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_relationship_Class = factory->createEClass_in_EPackage(package, RELATIONSHIP_CLASS);
	
	m_relationship_Attribute_relatedElement = factory->createEReference_in_EContainingClass(m_relationship_Class, RELATIONSHIP_ATTRIBUTE_RELATEDELEMENT);
	
	
}

void UmlPackageImpl::createRemoveStructuralFeatureValueActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_removeStructuralFeatureValueAction_Class = factory->createEClass_in_EPackage(package, REMOVESTRUCTURALFEATUREVALUEACTION_CLASS);
	m_removeStructuralFeatureValueAction_Attribute_isRemoveDuplicates = factory->createEAttribute_in_EContainingClass(m_removeStructuralFeatureValueAction_Class, REMOVESTRUCTURALFEATUREVALUEACTION_ATTRIBUTE_ISREMOVEDUPLICATES);
	
	m_removeStructuralFeatureValueAction_Attribute_removeAt = factory->createEReference_in_EContainingClass(m_removeStructuralFeatureValueAction_Class, REMOVESTRUCTURALFEATUREVALUEACTION_ATTRIBUTE_REMOVEAT);
	
	m_removeStructuralFeatureValueAction_Operation_removeAt_and_value_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_removeStructuralFeatureValueAction_Class, REMOVESTRUCTURALFEATUREVALUEACTION_OPERATION_REMOVEAT_AND_VALUE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createRemoveVariableValueActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_removeVariableValueAction_Class = factory->createEClass_in_EPackage(package, REMOVEVARIABLEVALUEACTION_CLASS);
	m_removeVariableValueAction_Attribute_isRemoveDuplicates = factory->createEAttribute_in_EContainingClass(m_removeVariableValueAction_Class, REMOVEVARIABLEVALUEACTION_ATTRIBUTE_ISREMOVEDUPLICATES);
	
	m_removeVariableValueAction_Attribute_removeAt = factory->createEReference_in_EContainingClass(m_removeVariableValueAction_Class, REMOVEVARIABLEVALUEACTION_ATTRIBUTE_REMOVEAT);
	
	m_removeVariableValueAction_Operation_removeAt_and_value_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_removeVariableValueAction_Class, REMOVEVARIABLEVALUEACTION_OPERATION_REMOVEAT_AND_VALUE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createReplyActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_replyAction_Class = factory->createEClass_in_EPackage(package, REPLYACTION_CLASS);
	
	m_replyAction_Attribute_replyToCall = factory->createEReference_in_EContainingClass(m_replyAction_Class, REPLYACTION_ATTRIBUTE_REPLYTOCALL);
	m_replyAction_Attribute_replyValue = factory->createEReference_in_EContainingClass(m_replyAction_Class, REPLYACTION_ATTRIBUTE_REPLYVALUE);
	m_replyAction_Attribute_returnInformation = factory->createEReference_in_EContainingClass(m_replyAction_Class, REPLYACTION_ATTRIBUTE_RETURNINFORMATION);
	
	m_replyAction_Operation_event_on_reply_to_call_trigger_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_replyAction_Class, REPLYACTION_OPERATION_EVENT_ON_REPLY_TO_CALL_TRIGGER_EDIAGNOSTICCHAIN_EMAP);
	m_replyAction_Operation_pins_match_parameter_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_replyAction_Class, REPLYACTION_OPERATION_PINS_MATCH_PARAMETER_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createSendObjectActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_sendObjectAction_Class = factory->createEClass_in_EPackage(package, SENDOBJECTACTION_CLASS);
	
	m_sendObjectAction_Attribute_request = factory->createEReference_in_EContainingClass(m_sendObjectAction_Class, SENDOBJECTACTION_ATTRIBUTE_REQUEST);
	m_sendObjectAction_Attribute_target = factory->createEReference_in_EContainingClass(m_sendObjectAction_Class, SENDOBJECTACTION_ATTRIBUTE_TARGET);
	
	m_sendObjectAction_Operation_type_target_pin_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_sendObjectAction_Class, SENDOBJECTACTION_OPERATION_TYPE_TARGET_PIN_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createSendSignalActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_sendSignalAction_Class = factory->createEClass_in_EPackage(package, SENDSIGNALACTION_CLASS);
	
	m_sendSignalAction_Attribute_signal = factory->createEReference_in_EContainingClass(m_sendSignalAction_Class, SENDSIGNALACTION_ATTRIBUTE_SIGNAL);
	m_sendSignalAction_Attribute_target = factory->createEReference_in_EContainingClass(m_sendSignalAction_Class, SENDSIGNALACTION_ATTRIBUTE_TARGET);
	
	m_sendSignalAction_Operation_number_order_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_sendSignalAction_Class, SENDSIGNALACTION_OPERATION_NUMBER_ORDER_EDIAGNOSTICCHAIN_EMAP);
	m_sendSignalAction_Operation_type_ordering_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_sendSignalAction_Class, SENDSIGNALACTION_OPERATION_TYPE_ORDERING_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	m_sendSignalAction_Operation_type_target_pin_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_sendSignalAction_Class, SENDSIGNALACTION_OPERATION_TYPE_TARGET_PIN_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createSequenceNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_sequenceNode_Class = factory->createEClass_in_EPackage(package, SEQUENCENODE_CLASS);
	
	m_sequenceNode_Attribute_executableNode = factory->createEReference_in_EContainingClass(m_sequenceNode_Class, SEQUENCENODE_ATTRIBUTE_EXECUTABLENODE);
	
	
}

void UmlPackageImpl::createSignalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_signal_Class = factory->createEClass_in_EPackage(package, SIGNAL_CLASS);
	
	m_signal_Attribute_ownedAttribute = factory->createEReference_in_EContainingClass(m_signal_Class, SIGNAL_ATTRIBUTE_OWNEDATTRIBUTE);
	
	m_signal_Operation_createOwnedAttribute_String_UnlimitedNatural = factory->createEOperation_in_EContainingClass(m_signal_Class, SIGNAL_OPERATION_CREATEOWNEDATTRIBUTE_STRING_UNLIMITEDNATURAL);
	
}

void UmlPackageImpl::createSignalEventContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_signalEvent_Class = factory->createEClass_in_EPackage(package, SIGNALEVENT_CLASS);
	
	m_signalEvent_Attribute_signal = factory->createEReference_in_EContainingClass(m_signalEvent_Class, SIGNALEVENT_ATTRIBUTE_SIGNAL);
	
	
}

void UmlPackageImpl::createSlotContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_slot_Class = factory->createEClass_in_EPackage(package, SLOT_CLASS);
	
	m_slot_Attribute_definingFeature = factory->createEReference_in_EContainingClass(m_slot_Class, SLOT_ATTRIBUTE_DEFININGFEATURE);
	m_slot_Attribute_owningInstance = factory->createEReference_in_EContainingClass(m_slot_Class, SLOT_ATTRIBUTE_OWNINGINSTANCE);
	m_slot_Attribute_value = factory->createEReference_in_EContainingClass(m_slot_Class, SLOT_ATTRIBUTE_VALUE);
	
	
}

void UmlPackageImpl::createStartClassifierBehaviorActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_startClassifierBehaviorAction_Class = factory->createEClass_in_EPackage(package, STARTCLASSIFIERBEHAVIORACTION_CLASS);
	
	m_startClassifierBehaviorAction_Attribute_object = factory->createEReference_in_EContainingClass(m_startClassifierBehaviorAction_Class, STARTCLASSIFIERBEHAVIORACTION_ATTRIBUTE_OBJECT);
	
	m_startClassifierBehaviorAction_Operation_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_startClassifierBehaviorAction_Class, STARTCLASSIFIERBEHAVIORACTION_OPERATION_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	m_startClassifierBehaviorAction_Operation_type_has_classifier_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_startClassifierBehaviorAction_Class, STARTCLASSIFIERBEHAVIORACTION_OPERATION_TYPE_HAS_CLASSIFIER_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createStartObjectBehaviorActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_startObjectBehaviorAction_Class = factory->createEClass_in_EPackage(package, STARTOBJECTBEHAVIORACTION_CLASS);
	
	m_startObjectBehaviorAction_Attribute_object = factory->createEReference_in_EContainingClass(m_startObjectBehaviorAction_Class, STARTOBJECTBEHAVIORACTION_ATTRIBUTE_OBJECT);
	
	m_startObjectBehaviorAction_Operation_behavior = factory->createEOperation_in_EContainingClass(m_startObjectBehaviorAction_Class, STARTOBJECTBEHAVIORACTION_OPERATION_BEHAVIOR);
	m_startObjectBehaviorAction_Operation_multiplicity_of_object_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_startObjectBehaviorAction_Class, STARTOBJECTBEHAVIORACTION_OPERATION_MULTIPLICITY_OF_OBJECT_EDIAGNOSTICCHAIN_EMAP);
	m_startObjectBehaviorAction_Operation_no_onport_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_startObjectBehaviorAction_Class, STARTOBJECTBEHAVIORACTION_OPERATION_NO_ONPORT_EDIAGNOSTICCHAIN_EMAP);
	m_startObjectBehaviorAction_Operation_type_of_object_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_startObjectBehaviorAction_Class, STARTOBJECTBEHAVIORACTION_OPERATION_TYPE_OF_OBJECT_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createStateContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_state_Class = factory->createEClass_in_EPackage(package, STATE_CLASS);
	m_state_Attribute_isComposite = factory->createEAttribute_in_EContainingClass(m_state_Class, STATE_ATTRIBUTE_ISCOMPOSITE);
	m_state_Attribute_isOrthogonal = factory->createEAttribute_in_EContainingClass(m_state_Class, STATE_ATTRIBUTE_ISORTHOGONAL);
	m_state_Attribute_isSimple = factory->createEAttribute_in_EContainingClass(m_state_Class, STATE_ATTRIBUTE_ISSIMPLE);
	m_state_Attribute_isSubmachineState = factory->createEAttribute_in_EContainingClass(m_state_Class, STATE_ATTRIBUTE_ISSUBMACHINESTATE);
	
	m_state_Attribute_connection = factory->createEReference_in_EContainingClass(m_state_Class, STATE_ATTRIBUTE_CONNECTION);
	m_state_Attribute_connectionPoint = factory->createEReference_in_EContainingClass(m_state_Class, STATE_ATTRIBUTE_CONNECTIONPOINT);
	m_state_Attribute_deferrableTrigger = factory->createEReference_in_EContainingClass(m_state_Class, STATE_ATTRIBUTE_DEFERRABLETRIGGER);
	m_state_Attribute_doActivity = factory->createEReference_in_EContainingClass(m_state_Class, STATE_ATTRIBUTE_DOACTIVITY);
	m_state_Attribute_entry = factory->createEReference_in_EContainingClass(m_state_Class, STATE_ATTRIBUTE_ENTRY);
	m_state_Attribute_exit = factory->createEReference_in_EContainingClass(m_state_Class, STATE_ATTRIBUTE_EXIT);
	m_state_Attribute_redefinedState = factory->createEReference_in_EContainingClass(m_state_Class, STATE_ATTRIBUTE_REDEFINEDSTATE);
	m_state_Attribute_region = factory->createEReference_in_EContainingClass(m_state_Class, STATE_ATTRIBUTE_REGION);
	m_state_Attribute_stateInvariant = factory->createEReference_in_EContainingClass(m_state_Class, STATE_ATTRIBUTE_STATEINVARIANT);
	m_state_Attribute_submachine = factory->createEReference_in_EContainingClass(m_state_Class, STATE_ATTRIBUTE_SUBMACHINE);
	
	m_state_Operation_composite_states_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_state_Class, STATE_OPERATION_COMPOSITE_STATES_EDIAGNOSTICCHAIN_EMAP);
	m_state_Operation_destinations_or_sources_of_transitions_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_state_Class, STATE_OPERATION_DESTINATIONS_OR_SOURCES_OF_TRANSITIONS_EDIAGNOSTICCHAIN_EMAP);
	m_state_Operation_entry_or_exit_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_state_Class, STATE_OPERATION_ENTRY_OR_EXIT_EDIAGNOSTICCHAIN_EMAP);
	m_state_Operation_isComposite = factory->createEOperation_in_EContainingClass(m_state_Class, STATE_OPERATION_ISCOMPOSITE);
	m_state_Operation_isOrthogonal = factory->createEOperation_in_EContainingClass(m_state_Class, STATE_OPERATION_ISORTHOGONAL);
	m_state_Operation_isSimple = factory->createEOperation_in_EContainingClass(m_state_Class, STATE_OPERATION_ISSIMPLE);
	m_state_Operation_isSubmachineState = factory->createEOperation_in_EContainingClass(m_state_Class, STATE_OPERATION_ISSUBMACHINESTATE);
	m_state_Operation_redefinitionContext = factory->createEOperation_in_EContainingClass(m_state_Class, STATE_OPERATION_REDEFINITIONCONTEXT);
	m_state_Operation_submachine_or_regions_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_state_Class, STATE_OPERATION_SUBMACHINE_OR_REGIONS_EDIAGNOSTICCHAIN_EMAP);
	m_state_Operation_submachine_states_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_state_Class, STATE_OPERATION_SUBMACHINE_STATES_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createStateInvariantContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_stateInvariant_Class = factory->createEClass_in_EPackage(package, STATEINVARIANT_CLASS);
	
	m_stateInvariant_Attribute_invariant = factory->createEReference_in_EContainingClass(m_stateInvariant_Class, STATEINVARIANT_ATTRIBUTE_INVARIANT);
	
	
}

void UmlPackageImpl::createStateMachineContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_stateMachine_Class = factory->createEClass_in_EPackage(package, STATEMACHINE_CLASS);
	
	m_stateMachine_Attribute_connectionPoint = factory->createEReference_in_EContainingClass(m_stateMachine_Class, STATEMACHINE_ATTRIBUTE_CONNECTIONPOINT);
	m_stateMachine_Attribute_extendedStateMachine = factory->createEReference_in_EContainingClass(m_stateMachine_Class, STATEMACHINE_ATTRIBUTE_EXTENDEDSTATEMACHINE);
	m_stateMachine_Attribute_region = factory->createEReference_in_EContainingClass(m_stateMachine_Class, STATEMACHINE_ATTRIBUTE_REGION);
	m_stateMachine_Attribute_submachineState = factory->createEReference_in_EContainingClass(m_stateMachine_Class, STATEMACHINE_ATTRIBUTE_SUBMACHINESTATE);
	
	m_stateMachine_Operation_lCA_Vertex_Vertex = factory->createEOperation_in_EContainingClass(m_stateMachine_Class, STATEMACHINE_OPERATION_LCA_VERTEX_VERTEX);
	m_stateMachine_Operation_lCAState_Vertex_Vertex = factory->createEOperation_in_EContainingClass(m_stateMachine_Class, STATEMACHINE_OPERATION_LCASTATE_VERTEX_VERTEX);
	m_stateMachine_Operation_ancestor_Vertex_Vertex = factory->createEOperation_in_EContainingClass(m_stateMachine_Class, STATEMACHINE_OPERATION_ANCESTOR_VERTEX_VERTEX);
	m_stateMachine_Operation_classifier_context_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_stateMachine_Class, STATEMACHINE_OPERATION_CLASSIFIER_CONTEXT_EDIAGNOSTICCHAIN_EMAP);
	m_stateMachine_Operation_connection_points_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_stateMachine_Class, STATEMACHINE_OPERATION_CONNECTION_POINTS_EDIAGNOSTICCHAIN_EMAP);
	m_stateMachine_Operation_context_classifier_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_stateMachine_Class, STATEMACHINE_OPERATION_CONTEXT_CLASSIFIER_EDIAGNOSTICCHAIN_EMAP);
	m_stateMachine_Operation_method_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_stateMachine_Class, STATEMACHINE_OPERATION_METHOD_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createStereotypeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_stereotype_Class = factory->createEClass_in_EPackage(package, STEREOTYPE_CLASS);
	
	m_stereotype_Attribute_icon = factory->createEReference_in_EContainingClass(m_stereotype_Class, STEREOTYPE_ATTRIBUTE_ICON);
	m_stereotype_Attribute_profile = factory->createEReference_in_EContainingClass(m_stereotype_Class, STEREOTYPE_ATTRIBUTE_PROFILE);
	
	m_stereotype_Operation_associationEndOwnership_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_stereotype_Class, STEREOTYPE_OPERATION_ASSOCIATIONENDOWNERSHIP_EDIAGNOSTICCHAIN_EMAP);
	m_stereotype_Operation_base_property_multiplicity_multiple_extension_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_stereotype_Class, STEREOTYPE_OPERATION_BASE_PROPERTY_MULTIPLICITY_MULTIPLE_EXTENSION_EDIAGNOSTICCHAIN_EMAP);
	m_stereotype_Operation_base_property_multiplicity_single_extension_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_stereotype_Class, STEREOTYPE_OPERATION_BASE_PROPERTY_MULTIPLICITY_SINGLE_EXTENSION_EDIAGNOSTICCHAIN_EMAP);
	m_stereotype_Operation_base_property_upper_bound_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_stereotype_Class, STEREOTYPE_OPERATION_BASE_PROPERTY_UPPER_BOUND_EDIAGNOSTICCHAIN_EMAP);
	m_stereotype_Operation_binaryAssociationsOnly_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_stereotype_Class, STEREOTYPE_OPERATION_BINARYASSOCIATIONSONLY_EDIAGNOSTICCHAIN_EMAP);
	m_stereotype_Operation_containingProfile = factory->createEOperation_in_EContainingClass(m_stereotype_Class, STEREOTYPE_OPERATION_CONTAININGPROFILE);
	m_stereotype_Operation_createExtension_Class_Boolean = factory->createEOperation_in_EContainingClass(m_stereotype_Class, STEREOTYPE_OPERATION_CREATEEXTENSION_CLASS_BOOLEAN);
	m_stereotype_Operation_createIcon_String = factory->createEOperation_in_EContainingClass(m_stereotype_Class, STEREOTYPE_OPERATION_CREATEICON_STRING);
	m_stereotype_Operation_createIcon_String_String = factory->createEOperation_in_EContainingClass(m_stereotype_Class, STEREOTYPE_OPERATION_CREATEICON_STRING_STRING);
	m_stereotype_Operation_generalize_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_stereotype_Class, STEREOTYPE_OPERATION_GENERALIZE_EDIAGNOSTICCHAIN_EMAP);
	m_stereotype_Operation_getAllExtendedMetaclasses = factory->createEOperation_in_EContainingClass(m_stereotype_Class, STEREOTYPE_OPERATION_GETALLEXTENDEDMETACLASSES);
	m_stereotype_Operation_getDefinition = factory->createEOperation_in_EContainingClass(m_stereotype_Class, STEREOTYPE_OPERATION_GETDEFINITION);
	m_stereotype_Operation_getExtendedMetaclasses = factory->createEOperation_in_EContainingClass(m_stereotype_Class, STEREOTYPE_OPERATION_GETEXTENDEDMETACLASSES);
	m_stereotype_Operation_getKeyword = factory->createEOperation_in_EContainingClass(m_stereotype_Class, STEREOTYPE_OPERATION_GETKEYWORD);
	m_stereotype_Operation_getKeyword_Boolean = factory->createEOperation_in_EContainingClass(m_stereotype_Class, STEREOTYPE_OPERATION_GETKEYWORD_BOOLEAN);
	m_stereotype_Operation_getProfile = factory->createEOperation_in_EContainingClass(m_stereotype_Class, STEREOTYPE_OPERATION_GETPROFILE);
	m_stereotype_Operation_name_not_clash_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_stereotype_Class, STEREOTYPE_OPERATION_NAME_NOT_CLASH_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createStringExpressionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_stringExpression_Class = factory->createEClass_in_EPackage(package, STRINGEXPRESSION_CLASS);
	
	m_stringExpression_Attribute_owningExpression = factory->createEReference_in_EContainingClass(m_stringExpression_Class, STRINGEXPRESSION_ATTRIBUTE_OWNINGEXPRESSION);
	m_stringExpression_Attribute_subExpression = factory->createEReference_in_EContainingClass(m_stringExpression_Class, STRINGEXPRESSION_ATTRIBUTE_SUBEXPRESSION);
	
	m_stringExpression_Operation_operands_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_stringExpression_Class, STRINGEXPRESSION_OPERATION_OPERANDS_EDIAGNOSTICCHAIN_EMAP);
	m_stringExpression_Operation_subexpressions_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_stringExpression_Class, STRINGEXPRESSION_OPERATION_SUBEXPRESSIONS_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createStructuralFeatureContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_structuralFeature_Class = factory->createEClass_in_EPackage(package, STRUCTURALFEATURE_CLASS);
	m_structuralFeature_Attribute_isReadOnly = factory->createEAttribute_in_EContainingClass(m_structuralFeature_Class, STRUCTURALFEATURE_ATTRIBUTE_ISREADONLY);
	
	
	
}

void UmlPackageImpl::createStructuralFeatureActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_structuralFeatureAction_Class = factory->createEClass_in_EPackage(package, STRUCTURALFEATUREACTION_CLASS);
	
	m_structuralFeatureAction_Attribute_object = factory->createEReference_in_EContainingClass(m_structuralFeatureAction_Class, STRUCTURALFEATUREACTION_ATTRIBUTE_OBJECT);
	m_structuralFeatureAction_Attribute_structuralFeature = factory->createEReference_in_EContainingClass(m_structuralFeatureAction_Class, STRUCTURALFEATUREACTION_ATTRIBUTE_STRUCTURALFEATURE);
	
	m_structuralFeatureAction_Operation_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_structuralFeatureAction_Class, STRUCTURALFEATUREACTION_OPERATION_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	m_structuralFeatureAction_Operation_not_static_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_structuralFeatureAction_Class, STRUCTURALFEATUREACTION_OPERATION_NOT_STATIC_EDIAGNOSTICCHAIN_EMAP);
	m_structuralFeatureAction_Operation_object_type_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_structuralFeatureAction_Class, STRUCTURALFEATUREACTION_OPERATION_OBJECT_TYPE_EDIAGNOSTICCHAIN_EMAP);
	m_structuralFeatureAction_Operation_one_featuring_classifier_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_structuralFeatureAction_Class, STRUCTURALFEATUREACTION_OPERATION_ONE_FEATURING_CLASSIFIER_EDIAGNOSTICCHAIN_EMAP);
	m_structuralFeatureAction_Operation_visibility_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_structuralFeatureAction_Class, STRUCTURALFEATUREACTION_OPERATION_VISIBILITY_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createStructuredActivityNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_structuredActivityNode_Class = factory->createEClass_in_EPackage(package, STRUCTUREDACTIVITYNODE_CLASS);
	m_structuredActivityNode_Attribute_mustIsolate = factory->createEAttribute_in_EContainingClass(m_structuredActivityNode_Class, STRUCTUREDACTIVITYNODE_ATTRIBUTE_MUSTISOLATE);
	
	m_structuredActivityNode_Attribute_edge = factory->createEReference_in_EContainingClass(m_structuredActivityNode_Class, STRUCTUREDACTIVITYNODE_ATTRIBUTE_EDGE);
	m_structuredActivityNode_Attribute_node = factory->createEReference_in_EContainingClass(m_structuredActivityNode_Class, STRUCTUREDACTIVITYNODE_ATTRIBUTE_NODE);
	m_structuredActivityNode_Attribute_structuredNodeInput = factory->createEReference_in_EContainingClass(m_structuredActivityNode_Class, STRUCTUREDACTIVITYNODE_ATTRIBUTE_STRUCTUREDNODEINPUT);
	m_structuredActivityNode_Attribute_structuredNodeOutput = factory->createEReference_in_EContainingClass(m_structuredActivityNode_Class, STRUCTUREDACTIVITYNODE_ATTRIBUTE_STRUCTUREDNODEOUTPUT);
	m_structuredActivityNode_Attribute_variable = factory->createEReference_in_EContainingClass(m_structuredActivityNode_Class, STRUCTUREDACTIVITYNODE_ATTRIBUTE_VARIABLE);
	
	m_structuredActivityNode_Operation_edges_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_structuredActivityNode_Class, STRUCTUREDACTIVITYNODE_OPERATION_EDGES_EDIAGNOSTICCHAIN_EMAP);
	m_structuredActivityNode_Operation_input_pin_edges_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_structuredActivityNode_Class, STRUCTUREDACTIVITYNODE_OPERATION_INPUT_PIN_EDGES_EDIAGNOSTICCHAIN_EMAP);
	m_structuredActivityNode_Operation_output_pin_edges_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_structuredActivityNode_Class, STRUCTUREDACTIVITYNODE_OPERATION_OUTPUT_PIN_EDGES_EDIAGNOSTICCHAIN_EMAP);
	m_structuredActivityNode_Operation_sourceNodes = factory->createEOperation_in_EContainingClass(m_structuredActivityNode_Class, STRUCTUREDACTIVITYNODE_OPERATION_SOURCENODES);
	m_structuredActivityNode_Operation_targetNodes = factory->createEOperation_in_EContainingClass(m_structuredActivityNode_Class, STRUCTUREDACTIVITYNODE_OPERATION_TARGETNODES);
	
}

void UmlPackageImpl::createStructuredClassifierContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_structuredClassifier_Class = factory->createEClass_in_EPackage(package, STRUCTUREDCLASSIFIER_CLASS);
	
	m_structuredClassifier_Attribute_ownedAttribute = factory->createEReference_in_EContainingClass(m_structuredClassifier_Class, STRUCTUREDCLASSIFIER_ATTRIBUTE_OWNEDATTRIBUTE);
	m_structuredClassifier_Attribute_ownedConnector = factory->createEReference_in_EContainingClass(m_structuredClassifier_Class, STRUCTUREDCLASSIFIER_ATTRIBUTE_OWNEDCONNECTOR);
	m_structuredClassifier_Attribute_part = factory->createEReference_in_EContainingClass(m_structuredClassifier_Class, STRUCTUREDCLASSIFIER_ATTRIBUTE_PART);
	m_structuredClassifier_Attribute_role = factory->createEReference_in_EContainingClass(m_structuredClassifier_Class, STRUCTUREDCLASSIFIER_ATTRIBUTE_ROLE);
	
	m_structuredClassifier_Operation_allRoles = factory->createEOperation_in_EContainingClass(m_structuredClassifier_Class, STRUCTUREDCLASSIFIER_OPERATION_ALLROLES);
	m_structuredClassifier_Operation_createOwnedAttribute_String_UnlimitedNatural = factory->createEOperation_in_EContainingClass(m_structuredClassifier_Class, STRUCTUREDCLASSIFIER_OPERATION_CREATEOWNEDATTRIBUTE_STRING_UNLIMITEDNATURAL);
	m_structuredClassifier_Operation_getParts = factory->createEOperation_in_EContainingClass(m_structuredClassifier_Class, STRUCTUREDCLASSIFIER_OPERATION_GETPARTS);
	
}

void UmlPackageImpl::createSubstitutionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_substitution_Class = factory->createEClass_in_EPackage(package, SUBSTITUTION_CLASS);
	
	m_substitution_Attribute_contract = factory->createEReference_in_EContainingClass(m_substitution_Class, SUBSTITUTION_ATTRIBUTE_CONTRACT);
	m_substitution_Attribute_substitutingClassifier = factory->createEReference_in_EContainingClass(m_substitution_Class, SUBSTITUTION_ATTRIBUTE_SUBSTITUTINGCLASSIFIER);
	
	
}

void UmlPackageImpl::createTemplateBindingContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_templateBinding_Class = factory->createEClass_in_EPackage(package, TEMPLATEBINDING_CLASS);
	
	m_templateBinding_Attribute_boundElement = factory->createEReference_in_EContainingClass(m_templateBinding_Class, TEMPLATEBINDING_ATTRIBUTE_BOUNDELEMENT);
	m_templateBinding_Attribute_parameterSubstitution = factory->createEReference_in_EContainingClass(m_templateBinding_Class, TEMPLATEBINDING_ATTRIBUTE_PARAMETERSUBSTITUTION);
	m_templateBinding_Attribute_signature = factory->createEReference_in_EContainingClass(m_templateBinding_Class, TEMPLATEBINDING_ATTRIBUTE_SIGNATURE);
	
	m_templateBinding_Operation_one_parameter_substitution_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_templateBinding_Class, TEMPLATEBINDING_OPERATION_ONE_PARAMETER_SUBSTITUTION_EDIAGNOSTICCHAIN_EMAP);
	m_templateBinding_Operation_parameter_substitution_formal_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_templateBinding_Class, TEMPLATEBINDING_OPERATION_PARAMETER_SUBSTITUTION_FORMAL_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createTemplateParameterContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_templateParameter_Class = factory->createEClass_in_EPackage(package, TEMPLATEPARAMETER_CLASS);
	
	m_templateParameter_Attribute_default = factory->createEReference_in_EContainingClass(m_templateParameter_Class, TEMPLATEPARAMETER_ATTRIBUTE_DEFAULT);
	m_templateParameter_Attribute_ownedDefault = factory->createEReference_in_EContainingClass(m_templateParameter_Class, TEMPLATEPARAMETER_ATTRIBUTE_OWNEDDEFAULT);
	m_templateParameter_Attribute_ownedParameteredElement = factory->createEReference_in_EContainingClass(m_templateParameter_Class, TEMPLATEPARAMETER_ATTRIBUTE_OWNEDPARAMETEREDELEMENT);
	m_templateParameter_Attribute_parameteredElement = factory->createEReference_in_EContainingClass(m_templateParameter_Class, TEMPLATEPARAMETER_ATTRIBUTE_PARAMETEREDELEMENT);
	m_templateParameter_Attribute_signature = factory->createEReference_in_EContainingClass(m_templateParameter_Class, TEMPLATEPARAMETER_ATTRIBUTE_SIGNATURE);
	
	m_templateParameter_Operation_must_be_compatible_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_templateParameter_Class, TEMPLATEPARAMETER_OPERATION_MUST_BE_COMPATIBLE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createTemplateParameterSubstitutionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_templateParameterSubstitution_Class = factory->createEClass_in_EPackage(package, TEMPLATEPARAMETERSUBSTITUTION_CLASS);
	
	m_templateParameterSubstitution_Attribute_actual = factory->createEReference_in_EContainingClass(m_templateParameterSubstitution_Class, TEMPLATEPARAMETERSUBSTITUTION_ATTRIBUTE_ACTUAL);
	m_templateParameterSubstitution_Attribute_formal = factory->createEReference_in_EContainingClass(m_templateParameterSubstitution_Class, TEMPLATEPARAMETERSUBSTITUTION_ATTRIBUTE_FORMAL);
	m_templateParameterSubstitution_Attribute_ownedActual = factory->createEReference_in_EContainingClass(m_templateParameterSubstitution_Class, TEMPLATEPARAMETERSUBSTITUTION_ATTRIBUTE_OWNEDACTUAL);
	m_templateParameterSubstitution_Attribute_templateBinding = factory->createEReference_in_EContainingClass(m_templateParameterSubstitution_Class, TEMPLATEPARAMETERSUBSTITUTION_ATTRIBUTE_TEMPLATEBINDING);
	
	m_templateParameterSubstitution_Operation_must_be_compatible_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_templateParameterSubstitution_Class, TEMPLATEPARAMETERSUBSTITUTION_OPERATION_MUST_BE_COMPATIBLE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createTemplateSignatureContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_templateSignature_Class = factory->createEClass_in_EPackage(package, TEMPLATESIGNATURE_CLASS);
	
	m_templateSignature_Attribute_ownedParameter = factory->createEReference_in_EContainingClass(m_templateSignature_Class, TEMPLATESIGNATURE_ATTRIBUTE_OWNEDPARAMETER);
	m_templateSignature_Attribute_parameter = factory->createEReference_in_EContainingClass(m_templateSignature_Class, TEMPLATESIGNATURE_ATTRIBUTE_PARAMETER);
	m_templateSignature_Attribute_template = factory->createEReference_in_EContainingClass(m_templateSignature_Class, TEMPLATESIGNATURE_ATTRIBUTE_TEMPLATE);
	
	m_templateSignature_Operation_own_elements_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_templateSignature_Class, TEMPLATESIGNATURE_OPERATION_OWN_ELEMENTS_EDIAGNOSTICCHAIN_EMAP);
	m_templateSignature_Operation_unique_parameters_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_templateSignature_Class, TEMPLATESIGNATURE_OPERATION_UNIQUE_PARAMETERS_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createTemplateableElementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_templateableElement_Class = factory->createEClass_in_EPackage(package, TEMPLATEABLEELEMENT_CLASS);
	
	m_templateableElement_Attribute_ownedTemplateSignature = factory->createEReference_in_EContainingClass(m_templateableElement_Class, TEMPLATEABLEELEMENT_ATTRIBUTE_OWNEDTEMPLATESIGNATURE);
	m_templateableElement_Attribute_templateBinding = factory->createEReference_in_EContainingClass(m_templateableElement_Class, TEMPLATEABLEELEMENT_ATTRIBUTE_TEMPLATEBINDING);
	
	m_templateableElement_Operation_isTemplate = factory->createEOperation_in_EContainingClass(m_templateableElement_Class, TEMPLATEABLEELEMENT_OPERATION_ISTEMPLATE);
	m_templateableElement_Operation_parameterableElements = factory->createEOperation_in_EContainingClass(m_templateableElement_Class, TEMPLATEABLEELEMENT_OPERATION_PARAMETERABLEELEMENTS);
	
}

void UmlPackageImpl::createTestIdentityActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_testIdentityAction_Class = factory->createEClass_in_EPackage(package, TESTIDENTITYACTION_CLASS);
	
	m_testIdentityAction_Attribute_first = factory->createEReference_in_EContainingClass(m_testIdentityAction_Class, TESTIDENTITYACTION_ATTRIBUTE_FIRST);
	m_testIdentityAction_Attribute_result = factory->createEReference_in_EContainingClass(m_testIdentityAction_Class, TESTIDENTITYACTION_ATTRIBUTE_RESULT);
	m_testIdentityAction_Attribute_second = factory->createEReference_in_EContainingClass(m_testIdentityAction_Class, TESTIDENTITYACTION_ATTRIBUTE_SECOND);
	
	m_testIdentityAction_Operation_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_testIdentityAction_Class, TESTIDENTITYACTION_OPERATION_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	m_testIdentityAction_Operation_no_type_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_testIdentityAction_Class, TESTIDENTITYACTION_OPERATION_NO_TYPE_EDIAGNOSTICCHAIN_EMAP);
	m_testIdentityAction_Operation_result_is_boolean_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_testIdentityAction_Class, TESTIDENTITYACTION_OPERATION_RESULT_IS_BOOLEAN_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createTimeConstraintContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_timeConstraint_Class = factory->createEClass_in_EPackage(package, TIMECONSTRAINT_CLASS);
	m_timeConstraint_Attribute_firstEvent = factory->createEAttribute_in_EContainingClass(m_timeConstraint_Class, TIMECONSTRAINT_ATTRIBUTE_FIRSTEVENT);
	
	
	m_timeConstraint_Operation_has_one_constrainedElement_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_timeConstraint_Class, TIMECONSTRAINT_OPERATION_HAS_ONE_CONSTRAINEDELEMENT_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createTimeEventContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_timeEvent_Class = factory->createEClass_in_EPackage(package, TIMEEVENT_CLASS);
	m_timeEvent_Attribute_isRelative = factory->createEAttribute_in_EContainingClass(m_timeEvent_Class, TIMEEVENT_ATTRIBUTE_ISRELATIVE);
	
	m_timeEvent_Attribute_when = factory->createEReference_in_EContainingClass(m_timeEvent_Class, TIMEEVENT_ATTRIBUTE_WHEN);
	
	m_timeEvent_Operation_when_non_negative_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_timeEvent_Class, TIMEEVENT_OPERATION_WHEN_NON_NEGATIVE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createTimeExpressionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_timeExpression_Class = factory->createEClass_in_EPackage(package, TIMEEXPRESSION_CLASS);
	
	m_timeExpression_Attribute_expr = factory->createEReference_in_EContainingClass(m_timeExpression_Class, TIMEEXPRESSION_ATTRIBUTE_EXPR);
	m_timeExpression_Attribute_observation = factory->createEReference_in_EContainingClass(m_timeExpression_Class, TIMEEXPRESSION_ATTRIBUTE_OBSERVATION);
	
	m_timeExpression_Operation_no_expr_requires_observation_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_timeExpression_Class, TIMEEXPRESSION_OPERATION_NO_EXPR_REQUIRES_OBSERVATION_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createTimeIntervalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_timeInterval_Class = factory->createEClass_in_EPackage(package, TIMEINTERVAL_CLASS);
	
	
	
}

void UmlPackageImpl::createTimeObservationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_timeObservation_Class = factory->createEClass_in_EPackage(package, TIMEOBSERVATION_CLASS);
	m_timeObservation_Attribute_firstEvent = factory->createEAttribute_in_EContainingClass(m_timeObservation_Class, TIMEOBSERVATION_ATTRIBUTE_FIRSTEVENT);
	
	m_timeObservation_Attribute_event = factory->createEReference_in_EContainingClass(m_timeObservation_Class, TIMEOBSERVATION_ATTRIBUTE_EVENT);
	
	
}

void UmlPackageImpl::createTransitionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_transition_Class = factory->createEClass_in_EPackage(package, TRANSITION_CLASS);
	m_transition_Attribute_kind = factory->createEAttribute_in_EContainingClass(m_transition_Class, TRANSITION_ATTRIBUTE_KIND);
	
	m_transition_Attribute_container = factory->createEReference_in_EContainingClass(m_transition_Class, TRANSITION_ATTRIBUTE_CONTAINER);
	m_transition_Attribute_effect = factory->createEReference_in_EContainingClass(m_transition_Class, TRANSITION_ATTRIBUTE_EFFECT);
	m_transition_Attribute_guard = factory->createEReference_in_EContainingClass(m_transition_Class, TRANSITION_ATTRIBUTE_GUARD);
	m_transition_Attribute_redefinedTransition = factory->createEReference_in_EContainingClass(m_transition_Class, TRANSITION_ATTRIBUTE_REDEFINEDTRANSITION);
	m_transition_Attribute_source = factory->createEReference_in_EContainingClass(m_transition_Class, TRANSITION_ATTRIBUTE_SOURCE);
	m_transition_Attribute_target = factory->createEReference_in_EContainingClass(m_transition_Class, TRANSITION_ATTRIBUTE_TARGET);
	m_transition_Attribute_trigger = factory->createEReference_in_EContainingClass(m_transition_Class, TRANSITION_ATTRIBUTE_TRIGGER);
	
	m_transition_Operation_containingStateMachine = factory->createEOperation_in_EContainingClass(m_transition_Class, TRANSITION_OPERATION_CONTAININGSTATEMACHINE);
	m_transition_Operation_fork_segment_guards_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_transition_Class, TRANSITION_OPERATION_FORK_SEGMENT_GUARDS_EDIAGNOSTICCHAIN_EMAP);
	m_transition_Operation_fork_segment_state_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_transition_Class, TRANSITION_OPERATION_FORK_SEGMENT_STATE_EDIAGNOSTICCHAIN_EMAP);
	m_transition_Operation_initial_transition_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_transition_Class, TRANSITION_OPERATION_INITIAL_TRANSITION_EDIAGNOSTICCHAIN_EMAP);
	m_transition_Operation_join_segment_guards_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_transition_Class, TRANSITION_OPERATION_JOIN_SEGMENT_GUARDS_EDIAGNOSTICCHAIN_EMAP);
	m_transition_Operation_join_segment_state_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_transition_Class, TRANSITION_OPERATION_JOIN_SEGMENT_STATE_EDIAGNOSTICCHAIN_EMAP);
	m_transition_Operation_outgoing_pseudostates_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_transition_Class, TRANSITION_OPERATION_OUTGOING_PSEUDOSTATES_EDIAGNOSTICCHAIN_EMAP);
	m_transition_Operation_redefinitionContext = factory->createEOperation_in_EContainingClass(m_transition_Class, TRANSITION_OPERATION_REDEFINITIONCONTEXT);
	m_transition_Operation_state_is_external_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_transition_Class, TRANSITION_OPERATION_STATE_IS_EXTERNAL_EDIAGNOSTICCHAIN_EMAP);
	m_transition_Operation_state_is_internal_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_transition_Class, TRANSITION_OPERATION_STATE_IS_INTERNAL_EDIAGNOSTICCHAIN_EMAP);
	m_transition_Operation_state_is_local_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_transition_Class, TRANSITION_OPERATION_STATE_IS_LOCAL_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createTriggerContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_trigger_Class = factory->createEClass_in_EPackage(package, TRIGGER_CLASS);
	
	m_trigger_Attribute_event = factory->createEReference_in_EContainingClass(m_trigger_Class, TRIGGER_ATTRIBUTE_EVENT);
	m_trigger_Attribute_port = factory->createEReference_in_EContainingClass(m_trigger_Class, TRIGGER_ATTRIBUTE_PORT);
	
	m_trigger_Operation_trigger_with_ports_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_trigger_Class, TRIGGER_OPERATION_TRIGGER_WITH_PORTS_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createTypeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_type_Class = factory->createEClass_in_EPackage(package, TYPE_CLASS);
	
	m_type_Attribute_package = factory->createEReference_in_EContainingClass(m_type_Class, TYPE_ATTRIBUTE_PACKAGE);
	
	m_type_Operation_conformsTo_Type = factory->createEOperation_in_EContainingClass(m_type_Class, TYPE_OPERATION_CONFORMSTO_TYPE);
	m_type_Operation_createAssociation_Boolean_UnlimitedNatural = factory->createEOperation_in_EContainingClass(m_type_Class, TYPE_OPERATION_CREATEASSOCIATION_BOOLEAN_UNLIMITEDNATURAL);
	m_type_Operation_getAssociations = factory->createEOperation_in_EContainingClass(m_type_Class, TYPE_OPERATION_GETASSOCIATIONS);
	
}

void UmlPackageImpl::createTypedElementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_typedElement_Class = factory->createEClass_in_EPackage(package, TYPEDELEMENT_CLASS);
	
	m_typedElement_Attribute_type = factory->createEReference_in_EContainingClass(m_typedElement_Class, TYPEDELEMENT_ATTRIBUTE_TYPE);
	
	
}

void UmlPackageImpl::createUnmarshallActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_unmarshallAction_Class = factory->createEClass_in_EPackage(package, UNMARSHALLACTION_CLASS);
	
	m_unmarshallAction_Attribute_object = factory->createEReference_in_EContainingClass(m_unmarshallAction_Class, UNMARSHALLACTION_ATTRIBUTE_OBJECT);
	m_unmarshallAction_Attribute_result = factory->createEReference_in_EContainingClass(m_unmarshallAction_Class, UNMARSHALLACTION_ATTRIBUTE_RESULT);
	m_unmarshallAction_Attribute_unmarshallType = factory->createEReference_in_EContainingClass(m_unmarshallAction_Class, UNMARSHALLACTION_ATTRIBUTE_UNMARSHALLTYPE);
	
	m_unmarshallAction_Operation_multiplicity_of_object_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_unmarshallAction_Class, UNMARSHALLACTION_OPERATION_MULTIPLICITY_OF_OBJECT_EDIAGNOSTICCHAIN_EMAP);
	m_unmarshallAction_Operation_number_of_result_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_unmarshallAction_Class, UNMARSHALLACTION_OPERATION_NUMBER_OF_RESULT_EDIAGNOSTICCHAIN_EMAP);
	m_unmarshallAction_Operation_object_type_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_unmarshallAction_Class, UNMARSHALLACTION_OPERATION_OBJECT_TYPE_EDIAGNOSTICCHAIN_EMAP);
	m_unmarshallAction_Operation_structural_feature_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_unmarshallAction_Class, UNMARSHALLACTION_OPERATION_STRUCTURAL_FEATURE_EDIAGNOSTICCHAIN_EMAP);
	m_unmarshallAction_Operation_type_ordering_and_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_unmarshallAction_Class, UNMARSHALLACTION_OPERATION_TYPE_ORDERING_AND_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createUsageContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_usage_Class = factory->createEClass_in_EPackage(package, USAGE_CLASS);
	
	
	
}

void UmlPackageImpl::createUseCaseContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_useCase_Class = factory->createEClass_in_EPackage(package, USECASE_CLASS);
	
	m_useCase_Attribute_extend = factory->createEReference_in_EContainingClass(m_useCase_Class, USECASE_ATTRIBUTE_EXTEND);
	m_useCase_Attribute_extensionPoint = factory->createEReference_in_EContainingClass(m_useCase_Class, USECASE_ATTRIBUTE_EXTENSIONPOINT);
	m_useCase_Attribute_include = factory->createEReference_in_EContainingClass(m_useCase_Class, USECASE_ATTRIBUTE_INCLUDE);
	m_useCase_Attribute_subject = factory->createEReference_in_EContainingClass(m_useCase_Class, USECASE_ATTRIBUTE_SUBJECT);
	
	m_useCase_Operation_allIncludedUseCases = factory->createEOperation_in_EContainingClass(m_useCase_Class, USECASE_OPERATION_ALLINCLUDEDUSECASES);
	m_useCase_Operation_binary_associations_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_useCase_Class, USECASE_OPERATION_BINARY_ASSOCIATIONS_EDIAGNOSTICCHAIN_EMAP);
	m_useCase_Operation_cannot_include_self_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_useCase_Class, USECASE_OPERATION_CANNOT_INCLUDE_SELF_EDIAGNOSTICCHAIN_EMAP);
	m_useCase_Operation_must_have_name_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_useCase_Class, USECASE_OPERATION_MUST_HAVE_NAME_EDIAGNOSTICCHAIN_EMAP);
	m_useCase_Operation_no_association_to_use_case_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_useCase_Class, USECASE_OPERATION_NO_ASSOCIATION_TO_USE_CASE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createValuePinContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_valuePin_Class = factory->createEClass_in_EPackage(package, VALUEPIN_CLASS);
	
	m_valuePin_Attribute_value = factory->createEReference_in_EContainingClass(m_valuePin_Class, VALUEPIN_ATTRIBUTE_VALUE);
	
	m_valuePin_Operation_compatible_type_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_valuePin_Class, VALUEPIN_OPERATION_COMPATIBLE_TYPE_EDIAGNOSTICCHAIN_EMAP);
	m_valuePin_Operation_no_incoming_edges_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_valuePin_Class, VALUEPIN_OPERATION_NO_INCOMING_EDGES_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createValueSpecificationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_valueSpecification_Class = factory->createEClass_in_EPackage(package, VALUESPECIFICATION_CLASS);
	
	m_valueSpecification_Attribute_owningSlot = factory->createEReference_in_EContainingClass(m_valueSpecification_Class, VALUESPECIFICATION_ATTRIBUTE_OWNINGSLOT);
	
	m_valueSpecification_Operation_booleanValue = factory->createEOperation_in_EContainingClass(m_valueSpecification_Class, VALUESPECIFICATION_OPERATION_BOOLEANVALUE);
	m_valueSpecification_Operation_integerValue = factory->createEOperation_in_EContainingClass(m_valueSpecification_Class, VALUESPECIFICATION_OPERATION_INTEGERVALUE);
	m_valueSpecification_Operation_isComputable = factory->createEOperation_in_EContainingClass(m_valueSpecification_Class, VALUESPECIFICATION_OPERATION_ISCOMPUTABLE);
	m_valueSpecification_Operation_isNull = factory->createEOperation_in_EContainingClass(m_valueSpecification_Class, VALUESPECIFICATION_OPERATION_ISNULL);
	m_valueSpecification_Operation_realValue = factory->createEOperation_in_EContainingClass(m_valueSpecification_Class, VALUESPECIFICATION_OPERATION_REALVALUE);
	m_valueSpecification_Operation_stringValue = factory->createEOperation_in_EContainingClass(m_valueSpecification_Class, VALUESPECIFICATION_OPERATION_STRINGVALUE);
	m_valueSpecification_Operation_unlimitedValue = factory->createEOperation_in_EContainingClass(m_valueSpecification_Class, VALUESPECIFICATION_OPERATION_UNLIMITEDVALUE);
	
}

void UmlPackageImpl::createValueSpecificationActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_valueSpecificationAction_Class = factory->createEClass_in_EPackage(package, VALUESPECIFICATIONACTION_CLASS);
	
	m_valueSpecificationAction_Attribute_result = factory->createEReference_in_EContainingClass(m_valueSpecificationAction_Class, VALUESPECIFICATIONACTION_ATTRIBUTE_RESULT);
	m_valueSpecificationAction_Attribute_value = factory->createEReference_in_EContainingClass(m_valueSpecificationAction_Class, VALUESPECIFICATIONACTION_ATTRIBUTE_VALUE);
	
	m_valueSpecificationAction_Operation_compatible_type_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_valueSpecificationAction_Class, VALUESPECIFICATIONACTION_OPERATION_COMPATIBLE_TYPE_EDIAGNOSTICCHAIN_EMAP);
	m_valueSpecificationAction_Operation_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_valueSpecificationAction_Class, VALUESPECIFICATIONACTION_OPERATION_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createVariableContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_variable_Class = factory->createEClass_in_EPackage(package, VARIABLE_CLASS);
	
	m_variable_Attribute_activityScope = factory->createEReference_in_EContainingClass(m_variable_Class, VARIABLE_ATTRIBUTE_ACTIVITYSCOPE);
	m_variable_Attribute_scope = factory->createEReference_in_EContainingClass(m_variable_Class, VARIABLE_ATTRIBUTE_SCOPE);
	
	m_variable_Operation_isAccessibleBy_Action = factory->createEOperation_in_EContainingClass(m_variable_Class, VARIABLE_OPERATION_ISACCESSIBLEBY_ACTION);
	
}

void UmlPackageImpl::createVariableActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_variableAction_Class = factory->createEClass_in_EPackage(package, VARIABLEACTION_CLASS);
	
	m_variableAction_Attribute_variable = factory->createEReference_in_EContainingClass(m_variableAction_Class, VARIABLEACTION_ATTRIBUTE_VARIABLE);
	
	m_variableAction_Operation_scope_of_variable_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_variableAction_Class, VARIABLEACTION_OPERATION_SCOPE_OF_VARIABLE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createVertexContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_vertex_Class = factory->createEClass_in_EPackage(package, VERTEX_CLASS);
	
	m_vertex_Attribute_container = factory->createEReference_in_EContainingClass(m_vertex_Class, VERTEX_ATTRIBUTE_CONTAINER);
	m_vertex_Attribute_incoming = factory->createEReference_in_EContainingClass(m_vertex_Class, VERTEX_ATTRIBUTE_INCOMING);
	m_vertex_Attribute_outgoing = factory->createEReference_in_EContainingClass(m_vertex_Class, VERTEX_ATTRIBUTE_OUTGOING);
	
	m_vertex_Operation_containingStateMachine = factory->createEOperation_in_EContainingClass(m_vertex_Class, VERTEX_OPERATION_CONTAININGSTATEMACHINE);
	m_vertex_Operation_getIncomings = factory->createEOperation_in_EContainingClass(m_vertex_Class, VERTEX_OPERATION_GETINCOMINGS);
	m_vertex_Operation_getOutgoings = factory->createEOperation_in_EContainingClass(m_vertex_Class, VERTEX_OPERATION_GETOUTGOINGS);
	m_vertex_Operation_isContainedInRegion_Region = factory->createEOperation_in_EContainingClass(m_vertex_Class, VERTEX_OPERATION_ISCONTAINEDINREGION_REGION);
	m_vertex_Operation_isContainedInState_State = factory->createEOperation_in_EContainingClass(m_vertex_Class, VERTEX_OPERATION_ISCONTAINEDINSTATE_STATE);
	
}

void UmlPackageImpl::createWriteLinkActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_writeLinkAction_Class = factory->createEClass_in_EPackage(package, WRITELINKACTION_CLASS);
	
	
	m_writeLinkAction_Operation_allow_access_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_writeLinkAction_Class, WRITELINKACTION_OPERATION_ALLOW_ACCESS_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createWriteStructuralFeatureActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_writeStructuralFeatureAction_Class = factory->createEClass_in_EPackage(package, WRITESTRUCTURALFEATUREACTION_CLASS);
	
	m_writeStructuralFeatureAction_Attribute_result = factory->createEReference_in_EContainingClass(m_writeStructuralFeatureAction_Class, WRITESTRUCTURALFEATUREACTION_ATTRIBUTE_RESULT);
	m_writeStructuralFeatureAction_Attribute_value = factory->createEReference_in_EContainingClass(m_writeStructuralFeatureAction_Class, WRITESTRUCTURALFEATUREACTION_ATTRIBUTE_VALUE);
	
	m_writeStructuralFeatureAction_Operation_multiplicity_of_result_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_writeStructuralFeatureAction_Class, WRITESTRUCTURALFEATUREACTION_OPERATION_MULTIPLICITY_OF_RESULT_EDIAGNOSTICCHAIN_EMAP);
	m_writeStructuralFeatureAction_Operation_multiplicity_of_value_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_writeStructuralFeatureAction_Class, WRITESTRUCTURALFEATUREACTION_OPERATION_MULTIPLICITY_OF_VALUE_EDIAGNOSTICCHAIN_EMAP);
	m_writeStructuralFeatureAction_Operation_type_of_result_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_writeStructuralFeatureAction_Class, WRITESTRUCTURALFEATUREACTION_OPERATION_TYPE_OF_RESULT_EDIAGNOSTICCHAIN_EMAP);
	m_writeStructuralFeatureAction_Operation_type_of_value_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_writeStructuralFeatureAction_Class, WRITESTRUCTURALFEATUREACTION_OPERATION_TYPE_OF_VALUE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createWriteVariableActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_writeVariableAction_Class = factory->createEClass_in_EPackage(package, WRITEVARIABLEACTION_CLASS);
	
	m_writeVariableAction_Attribute_value = factory->createEReference_in_EContainingClass(m_writeVariableAction_Class, WRITEVARIABLEACTION_ATTRIBUTE_VALUE);
	
	m_writeVariableAction_Operation_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_writeVariableAction_Class, WRITEVARIABLEACTION_OPERATION_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	m_writeVariableAction_Operation_value_type_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_writeVariableAction_Class, WRITEVARIABLEACTION_OPERATION_VALUE_TYPE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_aggregationKind_Class = factory->createEEnum_in_EPackage(package, AGGREGATIONKIND_CLASS);
	m_callConcurrencyKind_Class = factory->createEEnum_in_EPackage(package, CALLCONCURRENCYKIND_CLASS);
	m_connectorKind_Class = factory->createEEnum_in_EPackage(package, CONNECTORKIND_CLASS);
	m_expansionKind_Class = factory->createEEnum_in_EPackage(package, EXPANSIONKIND_CLASS);
	m_interactionOperatorKind_Class = factory->createEEnum_in_EPackage(package, INTERACTIONOPERATORKIND_CLASS);
	m_messageKind_Class = factory->createEEnum_in_EPackage(package, MESSAGEKIND_CLASS);
	m_messageSort_Class = factory->createEEnum_in_EPackage(package, MESSAGESORT_CLASS);
	m_objectNodeOrderingKind_Class = factory->createEEnum_in_EPackage(package, OBJECTNODEORDERINGKIND_CLASS);
	m_parameterDirectionKind_Class = factory->createEEnum_in_EPackage(package, PARAMETERDIRECTIONKIND_CLASS);
	m_parameterEffectKind_Class = factory->createEEnum_in_EPackage(package, PARAMETEREFFECTKIND_CLASS);
	m_pseudostateKind_Class = factory->createEEnum_in_EPackage(package, PSEUDOSTATEKIND_CLASS);
	m_transitionKind_Class = factory->createEEnum_in_EPackage(package, TRANSITIONKIND_CLASS);
	m_visibilityKind_Class = factory->createEEnum_in_EPackage(package, VISIBILITYKIND_CLASS);
	
}
