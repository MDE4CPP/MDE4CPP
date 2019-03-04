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
	m_abstraction_EClass = factory->createEClass_in_EPackage(package, ABSTRACTION_ECLASS);
	
	m_abstraction_EReference_mapping = factory->createEReference_in_EContainingClass(m_abstraction_EClass, ABSTRACTION_EREFERENCE_MAPPING);
	
	
}

void UmlPackageImpl::createAcceptCallActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_acceptCallAction_EClass = factory->createEClass_in_EPackage(package, ACCEPTCALLACTION_ECLASS);
	
	m_acceptCallAction_EReference_returnInformation = factory->createEReference_in_EContainingClass(m_acceptCallAction_EClass, ACCEPTCALLACTION_EREFERENCE_RETURNINFORMATION);
	
	m_acceptCallAction_EOperation_result_pins_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_acceptCallAction_EClass, ACCEPTCALLACTION_EOPERATION_RESULT_PINS_EDIAGNOSTICCHAIN_EMAP);
	m_acceptCallAction_EOperation_trigger_call_event_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_acceptCallAction_EClass, ACCEPTCALLACTION_EOPERATION_TRIGGER_CALL_EVENT_EDIAGNOSTICCHAIN_EMAP);
	m_acceptCallAction_EOperation_unmarshall_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_acceptCallAction_EClass, ACCEPTCALLACTION_EOPERATION_UNMARSHALL_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createAcceptEventActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_acceptEventAction_EClass = factory->createEClass_in_EPackage(package, ACCEPTEVENTACTION_ECLASS);
	m_acceptEventAction_EAttribute_isUnmarshall = factory->createEAttribute_in_EContainingClass(m_acceptEventAction_EClass, ACCEPTEVENTACTION_EATTRIBUTE_ISUNMARSHALL);
	
	m_acceptEventAction_EReference_result = factory->createEReference_in_EContainingClass(m_acceptEventAction_EClass, ACCEPTEVENTACTION_EREFERENCE_RESULT);
	m_acceptEventAction_EReference_trigger = factory->createEReference_in_EContainingClass(m_acceptEventAction_EClass, ACCEPTEVENTACTION_EREFERENCE_TRIGGER);
	
	m_acceptEventAction_EOperation_conforming_type_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_acceptEventAction_EClass, ACCEPTEVENTACTION_EOPERATION_CONFORMING_TYPE_EDIAGNOSTICCHAIN_EMAP);
	m_acceptEventAction_EOperation_no_input_pins_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_acceptEventAction_EClass, ACCEPTEVENTACTION_EOPERATION_NO_INPUT_PINS_EDIAGNOSTICCHAIN_EMAP);
	m_acceptEventAction_EOperation_no_output_pins_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_acceptEventAction_EClass, ACCEPTEVENTACTION_EOPERATION_NO_OUTPUT_PINS_EDIAGNOSTICCHAIN_EMAP);
	m_acceptEventAction_EOperation_one_output_pin_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_acceptEventAction_EClass, ACCEPTEVENTACTION_EOPERATION_ONE_OUTPUT_PIN_EDIAGNOSTICCHAIN_EMAP);
	m_acceptEventAction_EOperation_unmarshall_signal_events_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_acceptEventAction_EClass, ACCEPTEVENTACTION_EOPERATION_UNMARSHALL_SIGNAL_EVENTS_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_action_EClass = factory->createEClass_in_EPackage(package, ACTION_ECLASS);
	m_action_EAttribute_isLocallyReentrant = factory->createEAttribute_in_EContainingClass(m_action_EClass, ACTION_EATTRIBUTE_ISLOCALLYREENTRANT);
	
	m_action_EReference_context = factory->createEReference_in_EContainingClass(m_action_EClass, ACTION_EREFERENCE_CONTEXT);
	m_action_EReference_input = factory->createEReference_in_EContainingClass(m_action_EClass, ACTION_EREFERENCE_INPUT);
	m_action_EReference_localPostcondition = factory->createEReference_in_EContainingClass(m_action_EClass, ACTION_EREFERENCE_LOCALPOSTCONDITION);
	m_action_EReference_localPrecondition = factory->createEReference_in_EContainingClass(m_action_EClass, ACTION_EREFERENCE_LOCALPRECONDITION);
	m_action_EReference_output = factory->createEReference_in_EContainingClass(m_action_EClass, ACTION_EREFERENCE_OUTPUT);
	
	m_action_EOperation_allActions = factory->createEOperation_in_EContainingClass(m_action_EClass, ACTION_EOPERATION_ALLACTIONS);
	m_action_EOperation_allOwnedNodes = factory->createEOperation_in_EContainingClass(m_action_EClass, ACTION_EOPERATION_ALLOWNEDNODES);
	m_action_EOperation_containingBehavior = factory->createEOperation_in_EContainingClass(m_action_EClass, ACTION_EOPERATION_CONTAININGBEHAVIOR);
	m_action_EOperation_getContext = factory->createEOperation_in_EContainingClass(m_action_EClass, ACTION_EOPERATION_GETCONTEXT);
	
}

void UmlPackageImpl::createActionExecutionSpecificationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_actionExecutionSpecification_EClass = factory->createEClass_in_EPackage(package, ACTIONEXECUTIONSPECIFICATION_ECLASS);
	
	m_actionExecutionSpecification_EReference_action = factory->createEReference_in_EContainingClass(m_actionExecutionSpecification_EClass, ACTIONEXECUTIONSPECIFICATION_EREFERENCE_ACTION);
	
	m_actionExecutionSpecification_EOperation_action_referenced_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_actionExecutionSpecification_EClass, ACTIONEXECUTIONSPECIFICATION_EOPERATION_ACTION_REFERENCED_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createActionInputPinContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_actionInputPin_EClass = factory->createEClass_in_EPackage(package, ACTIONINPUTPIN_ECLASS);
	
	m_actionInputPin_EReference_fromAction = factory->createEReference_in_EContainingClass(m_actionInputPin_EClass, ACTIONINPUTPIN_EREFERENCE_FROMACTION);
	
	m_actionInputPin_EOperation_input_pin_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_actionInputPin_EClass, ACTIONINPUTPIN_EOPERATION_INPUT_PIN_EDIAGNOSTICCHAIN_EMAP);
	m_actionInputPin_EOperation_no_control_or_object_flow_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_actionInputPin_EClass, ACTIONINPUTPIN_EOPERATION_NO_CONTROL_OR_OBJECT_FLOW_EDIAGNOSTICCHAIN_EMAP);
	m_actionInputPin_EOperation_one_output_pin_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_actionInputPin_EClass, ACTIONINPUTPIN_EOPERATION_ONE_OUTPUT_PIN_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createActivityContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_activity_EClass = factory->createEClass_in_EPackage(package, ACTIVITY_ECLASS);
	m_activity_EAttribute_isReadOnly = factory->createEAttribute_in_EContainingClass(m_activity_EClass, ACTIVITY_EATTRIBUTE_ISREADONLY);
	m_activity_EAttribute_isSingleExecution = factory->createEAttribute_in_EContainingClass(m_activity_EClass, ACTIVITY_EATTRIBUTE_ISSINGLEEXECUTION);
	
	m_activity_EReference_edge = factory->createEReference_in_EContainingClass(m_activity_EClass, ACTIVITY_EREFERENCE_EDGE);
	m_activity_EReference_group = factory->createEReference_in_EContainingClass(m_activity_EClass, ACTIVITY_EREFERENCE_GROUP);
	m_activity_EReference_node = factory->createEReference_in_EContainingClass(m_activity_EClass, ACTIVITY_EREFERENCE_NODE);
	m_activity_EReference_ownedGroup = factory->createEReference_in_EContainingClass(m_activity_EClass, ACTIVITY_EREFERENCE_OWNEDGROUP);
	m_activity_EReference_ownedNode = factory->createEReference_in_EContainingClass(m_activity_EClass, ACTIVITY_EREFERENCE_OWNEDNODE);
	m_activity_EReference_partition = factory->createEReference_in_EContainingClass(m_activity_EClass, ACTIVITY_EREFERENCE_PARTITION);
	m_activity_EReference_structuredNode = factory->createEReference_in_EContainingClass(m_activity_EClass, ACTIVITY_EREFERENCE_STRUCTUREDNODE);
	m_activity_EReference_variable = factory->createEReference_in_EContainingClass(m_activity_EClass, ACTIVITY_EREFERENCE_VARIABLE);
	
	m_activity_EOperation_maximum_one_parameter_node_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_activity_EClass, ACTIVITY_EOPERATION_MAXIMUM_ONE_PARAMETER_NODE_EDIAGNOSTICCHAIN_EMAP);
	m_activity_EOperation_maximum_two_parameter_nodes_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_activity_EClass, ACTIVITY_EOPERATION_MAXIMUM_TWO_PARAMETER_NODES_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createActivityContentContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_activityContent_EClass = factory->createEClass_in_EPackage(package, ACTIVITYCONTENT_ECLASS);
	
	
	m_activityContent_EOperation_containingActivity = factory->createEOperation_in_EContainingClass(m_activityContent_EClass, ACTIVITYCONTENT_EOPERATION_CONTAININGACTIVITY);
	
}

void UmlPackageImpl::createActivityEdgeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_activityEdge_EClass = factory->createEClass_in_EPackage(package, ACTIVITYEDGE_ECLASS);
	
	m_activityEdge_EReference_activity = factory->createEReference_in_EContainingClass(m_activityEdge_EClass, ACTIVITYEDGE_EREFERENCE_ACTIVITY);
	m_activityEdge_EReference_guard = factory->createEReference_in_EContainingClass(m_activityEdge_EClass, ACTIVITYEDGE_EREFERENCE_GUARD);
	m_activityEdge_EReference_inGroup = factory->createEReference_in_EContainingClass(m_activityEdge_EClass, ACTIVITYEDGE_EREFERENCE_INGROUP);
	m_activityEdge_EReference_inPartition = factory->createEReference_in_EContainingClass(m_activityEdge_EClass, ACTIVITYEDGE_EREFERENCE_INPARTITION);
	m_activityEdge_EReference_inStructuredNode = factory->createEReference_in_EContainingClass(m_activityEdge_EClass, ACTIVITYEDGE_EREFERENCE_INSTRUCTUREDNODE);
	m_activityEdge_EReference_interrupts = factory->createEReference_in_EContainingClass(m_activityEdge_EClass, ACTIVITYEDGE_EREFERENCE_INTERRUPTS);
	m_activityEdge_EReference_redefinedEdge = factory->createEReference_in_EContainingClass(m_activityEdge_EClass, ACTIVITYEDGE_EREFERENCE_REDEFINEDEDGE);
	m_activityEdge_EReference_source = factory->createEReference_in_EContainingClass(m_activityEdge_EClass, ACTIVITYEDGE_EREFERENCE_SOURCE);
	m_activityEdge_EReference_target = factory->createEReference_in_EContainingClass(m_activityEdge_EClass, ACTIVITYEDGE_EREFERENCE_TARGET);
	m_activityEdge_EReference_weight = factory->createEReference_in_EContainingClass(m_activityEdge_EClass, ACTIVITYEDGE_EREFERENCE_WEIGHT);
	
	m_activityEdge_EOperation_source_and_target_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_activityEdge_EClass, ACTIVITYEDGE_EOPERATION_SOURCE_AND_TARGET_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createActivityFinalNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_activityFinalNode_EClass = factory->createEClass_in_EPackage(package, ACTIVITYFINALNODE_ECLASS);
	
	
	
}

void UmlPackageImpl::createActivityGroupContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_activityGroup_EClass = factory->createEClass_in_EPackage(package, ACTIVITYGROUP_ECLASS);
	
	m_activityGroup_EReference_containedEdge = factory->createEReference_in_EContainingClass(m_activityGroup_EClass, ACTIVITYGROUP_EREFERENCE_CONTAINEDEDGE);
	m_activityGroup_EReference_containedNode = factory->createEReference_in_EContainingClass(m_activityGroup_EClass, ACTIVITYGROUP_EREFERENCE_CONTAINEDNODE);
	m_activityGroup_EReference_inActivity = factory->createEReference_in_EContainingClass(m_activityGroup_EClass, ACTIVITYGROUP_EREFERENCE_INACTIVITY);
	m_activityGroup_EReference_subgroup = factory->createEReference_in_EContainingClass(m_activityGroup_EClass, ACTIVITYGROUP_EREFERENCE_SUBGROUP);
	m_activityGroup_EReference_superGroup = factory->createEReference_in_EContainingClass(m_activityGroup_EClass, ACTIVITYGROUP_EREFERENCE_SUPERGROUP);
	
	m_activityGroup_EOperation_nodes_and_edges_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_activityGroup_EClass, ACTIVITYGROUP_EOPERATION_NODES_AND_EDGES_EDIAGNOSTICCHAIN_EMAP);
	m_activityGroup_EOperation_not_contained_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_activityGroup_EClass, ACTIVITYGROUP_EOPERATION_NOT_CONTAINED_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createActivityNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_activityNode_EClass = factory->createEClass_in_EPackage(package, ACTIVITYNODE_ECLASS);
	
	m_activityNode_EReference_activity = factory->createEReference_in_EContainingClass(m_activityNode_EClass, ACTIVITYNODE_EREFERENCE_ACTIVITY);
	m_activityNode_EReference_inGroup = factory->createEReference_in_EContainingClass(m_activityNode_EClass, ACTIVITYNODE_EREFERENCE_INGROUP);
	m_activityNode_EReference_inInterruptibleRegion = factory->createEReference_in_EContainingClass(m_activityNode_EClass, ACTIVITYNODE_EREFERENCE_ININTERRUPTIBLEREGION);
	m_activityNode_EReference_inPartition = factory->createEReference_in_EContainingClass(m_activityNode_EClass, ACTIVITYNODE_EREFERENCE_INPARTITION);
	m_activityNode_EReference_inStructuredNode = factory->createEReference_in_EContainingClass(m_activityNode_EClass, ACTIVITYNODE_EREFERENCE_INSTRUCTUREDNODE);
	m_activityNode_EReference_incoming = factory->createEReference_in_EContainingClass(m_activityNode_EClass, ACTIVITYNODE_EREFERENCE_INCOMING);
	m_activityNode_EReference_outgoing = factory->createEReference_in_EContainingClass(m_activityNode_EClass, ACTIVITYNODE_EREFERENCE_OUTGOING);
	m_activityNode_EReference_redefinedNode = factory->createEReference_in_EContainingClass(m_activityNode_EClass, ACTIVITYNODE_EREFERENCE_REDEFINEDNODE);
	
	
}

void UmlPackageImpl::createActivityParameterNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_activityParameterNode_EClass = factory->createEClass_in_EPackage(package, ACTIVITYPARAMETERNODE_ECLASS);
	
	m_activityParameterNode_EReference_parameter = factory->createEReference_in_EContainingClass(m_activityParameterNode_EClass, ACTIVITYPARAMETERNODE_EREFERENCE_PARAMETER);
	
	m_activityParameterNode_EOperation_has_parameters_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_activityParameterNode_EClass, ACTIVITYPARAMETERNODE_EOPERATION_HAS_PARAMETERS_EDIAGNOSTICCHAIN_EMAP);
	m_activityParameterNode_EOperation_no_edges_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_activityParameterNode_EClass, ACTIVITYPARAMETERNODE_EOPERATION_NO_EDGES_EDIAGNOSTICCHAIN_EMAP);
	m_activityParameterNode_EOperation_no_incoming_edges_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_activityParameterNode_EClass, ACTIVITYPARAMETERNODE_EOPERATION_NO_INCOMING_EDGES_EDIAGNOSTICCHAIN_EMAP);
	m_activityParameterNode_EOperation_no_outgoing_edges_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_activityParameterNode_EClass, ACTIVITYPARAMETERNODE_EOPERATION_NO_OUTGOING_EDGES_EDIAGNOSTICCHAIN_EMAP);
	m_activityParameterNode_EOperation_same_type_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_activityParameterNode_EClass, ACTIVITYPARAMETERNODE_EOPERATION_SAME_TYPE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createActivityPartitionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_activityPartition_EClass = factory->createEClass_in_EPackage(package, ACTIVITYPARTITION_ECLASS);
	m_activityPartition_EAttribute_isDimension = factory->createEAttribute_in_EContainingClass(m_activityPartition_EClass, ACTIVITYPARTITION_EATTRIBUTE_ISDIMENSION);
	m_activityPartition_EAttribute_isExternal = factory->createEAttribute_in_EContainingClass(m_activityPartition_EClass, ACTIVITYPARTITION_EATTRIBUTE_ISEXTERNAL);
	
	m_activityPartition_EReference_edge = factory->createEReference_in_EContainingClass(m_activityPartition_EClass, ACTIVITYPARTITION_EREFERENCE_EDGE);
	m_activityPartition_EReference_node = factory->createEReference_in_EContainingClass(m_activityPartition_EClass, ACTIVITYPARTITION_EREFERENCE_NODE);
	m_activityPartition_EReference_represents = factory->createEReference_in_EContainingClass(m_activityPartition_EClass, ACTIVITYPARTITION_EREFERENCE_REPRESENTS);
	m_activityPartition_EReference_subpartition = factory->createEReference_in_EContainingClass(m_activityPartition_EClass, ACTIVITYPARTITION_EREFERENCE_SUBPARTITION);
	m_activityPartition_EReference_superPartition = factory->createEReference_in_EContainingClass(m_activityPartition_EClass, ACTIVITYPARTITION_EREFERENCE_SUPERPARTITION);
	
	m_activityPartition_EOperation_dimension_not_contained_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_activityPartition_EClass, ACTIVITYPARTITION_EOPERATION_DIMENSION_NOT_CONTAINED_EDIAGNOSTICCHAIN_EMAP);
	m_activityPartition_EOperation_represents_classifier_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_activityPartition_EClass, ACTIVITYPARTITION_EOPERATION_REPRESENTS_CLASSIFIER_EDIAGNOSTICCHAIN_EMAP);
	m_activityPartition_EOperation_represents_property_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_activityPartition_EClass, ACTIVITYPARTITION_EOPERATION_REPRESENTS_PROPERTY_EDIAGNOSTICCHAIN_EMAP);
	m_activityPartition_EOperation_represents_property_and_is_contained_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_activityPartition_EClass, ACTIVITYPARTITION_EOPERATION_REPRESENTS_PROPERTY_AND_IS_CONTAINED_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createActorContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_actor_EClass = factory->createEClass_in_EPackage(package, ACTOR_ECLASS);
	
	
	m_actor_EOperation_associations_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_actor_EClass, ACTOR_EOPERATION_ASSOCIATIONS_EDIAGNOSTICCHAIN_EMAP);
	m_actor_EOperation_must_have_name_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_actor_EClass, ACTOR_EOPERATION_MUST_HAVE_NAME_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createAddStructuralFeatureValueActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_addStructuralFeatureValueAction_EClass = factory->createEClass_in_EPackage(package, ADDSTRUCTURALFEATUREVALUEACTION_ECLASS);
	m_addStructuralFeatureValueAction_EAttribute_isReplaceAll = factory->createEAttribute_in_EContainingClass(m_addStructuralFeatureValueAction_EClass, ADDSTRUCTURALFEATUREVALUEACTION_EATTRIBUTE_ISREPLACEALL);
	
	m_addStructuralFeatureValueAction_EReference_insertAt = factory->createEReference_in_EContainingClass(m_addStructuralFeatureValueAction_EClass, ADDSTRUCTURALFEATUREVALUEACTION_EREFERENCE_INSERTAT);
	
	m_addStructuralFeatureValueAction_EOperation_insertAt_pin_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_addStructuralFeatureValueAction_EClass, ADDSTRUCTURALFEATUREVALUEACTION_EOPERATION_INSERTAT_PIN_EDIAGNOSTICCHAIN_EMAP);
	m_addStructuralFeatureValueAction_EOperation_required_value_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_addStructuralFeatureValueAction_EClass, ADDSTRUCTURALFEATUREVALUEACTION_EOPERATION_REQUIRED_VALUE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createAddVariableValueActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_addVariableValueAction_EClass = factory->createEClass_in_EPackage(package, ADDVARIABLEVALUEACTION_ECLASS);
	m_addVariableValueAction_EAttribute_isReplaceAll = factory->createEAttribute_in_EContainingClass(m_addVariableValueAction_EClass, ADDVARIABLEVALUEACTION_EATTRIBUTE_ISREPLACEALL);
	
	m_addVariableValueAction_EReference_insertAt = factory->createEReference_in_EContainingClass(m_addVariableValueAction_EClass, ADDVARIABLEVALUEACTION_EREFERENCE_INSERTAT);
	
	m_addVariableValueAction_EOperation_insertAt_pin_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_addVariableValueAction_EClass, ADDVARIABLEVALUEACTION_EOPERATION_INSERTAT_PIN_EDIAGNOSTICCHAIN_EMAP);
	m_addVariableValueAction_EOperation_required_value_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_addVariableValueAction_EClass, ADDVARIABLEVALUEACTION_EOPERATION_REQUIRED_VALUE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createAnyReceiveEventContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_anyReceiveEvent_EClass = factory->createEClass_in_EPackage(package, ANYRECEIVEEVENT_ECLASS);
	
	
	
}

void UmlPackageImpl::createArtifactContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_artifact_EClass = factory->createEClass_in_EPackage(package, ARTIFACT_ECLASS);
	m_artifact_EAttribute_fileName = factory->createEAttribute_in_EContainingClass(m_artifact_EClass, ARTIFACT_EATTRIBUTE_FILENAME);
	
	m_artifact_EReference_manifestation = factory->createEReference_in_EContainingClass(m_artifact_EClass, ARTIFACT_EREFERENCE_MANIFESTATION);
	m_artifact_EReference_nestedArtifact = factory->createEReference_in_EContainingClass(m_artifact_EClass, ARTIFACT_EREFERENCE_NESTEDARTIFACT);
	m_artifact_EReference_ownedAttribute = factory->createEReference_in_EContainingClass(m_artifact_EClass, ARTIFACT_EREFERENCE_OWNEDATTRIBUTE);
	m_artifact_EReference_ownedOperation = factory->createEReference_in_EContainingClass(m_artifact_EClass, ARTIFACT_EREFERENCE_OWNEDOPERATION);
	
	m_artifact_EOperation_createOwnedAttribute_String_UnlimitedNatural = factory->createEOperation_in_EContainingClass(m_artifact_EClass, ARTIFACT_EOPERATION_CREATEOWNEDATTRIBUTE_STRING_UNLIMITEDNATURAL);
	m_artifact_EOperation_createOwnedOperation_String_Type = factory->createEOperation_in_EContainingClass(m_artifact_EClass, ARTIFACT_EOPERATION_CREATEOWNEDOPERATION_STRING_TYPE);
	
}

void UmlPackageImpl::createAssociationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_association_EClass = factory->createEClass_in_EPackage(package, ASSOCIATION_ECLASS);
	m_association_EAttribute_isDerived = factory->createEAttribute_in_EContainingClass(m_association_EClass, ASSOCIATION_EATTRIBUTE_ISDERIVED);
	
	m_association_EReference_endType = factory->createEReference_in_EContainingClass(m_association_EClass, ASSOCIATION_EREFERENCE_ENDTYPE);
	m_association_EReference_memberEnd = factory->createEReference_in_EContainingClass(m_association_EClass, ASSOCIATION_EREFERENCE_MEMBEREND);
	m_association_EReference_navigableOwnedEnd = factory->createEReference_in_EContainingClass(m_association_EClass, ASSOCIATION_EREFERENCE_NAVIGABLEOWNEDEND);
	m_association_EReference_ownedEnd = factory->createEReference_in_EContainingClass(m_association_EClass, ASSOCIATION_EREFERENCE_OWNEDEND);
	
	m_association_EOperation_association_ends_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_association_EClass, ASSOCIATION_EOPERATION_ASSOCIATION_ENDS_EDIAGNOSTICCHAIN_EMAP);
	m_association_EOperation_binary_associations_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_association_EClass, ASSOCIATION_EOPERATION_BINARY_ASSOCIATIONS_EDIAGNOSTICCHAIN_EMAP);
	m_association_EOperation_ends_must_be_typed_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_association_EClass, ASSOCIATION_EOPERATION_ENDS_MUST_BE_TYPED_EDIAGNOSTICCHAIN_EMAP);
	m_association_EOperation_getEndTypes = factory->createEOperation_in_EContainingClass(m_association_EClass, ASSOCIATION_EOPERATION_GETENDTYPES);
	m_association_EOperation_isBinary = factory->createEOperation_in_EContainingClass(m_association_EClass, ASSOCIATION_EOPERATION_ISBINARY);
	m_association_EOperation_specialized_end_number_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_association_EClass, ASSOCIATION_EOPERATION_SPECIALIZED_END_NUMBER_EDIAGNOSTICCHAIN_EMAP);
	m_association_EOperation_specialized_end_types_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_association_EClass, ASSOCIATION_EOPERATION_SPECIALIZED_END_TYPES_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createAssociationClassContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_associationClass_EClass = factory->createEClass_in_EPackage(package, ASSOCIATIONCLASS_ECLASS);
	
	
	m_associationClass_EOperation_cannot_be_defined_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_associationClass_EClass, ASSOCIATIONCLASS_EOPERATION_CANNOT_BE_DEFINED_EDIAGNOSTICCHAIN_EMAP);
	m_associationClass_EOperation_disjoint_attributes_ends_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_associationClass_EClass, ASSOCIATIONCLASS_EOPERATION_DISJOINT_ATTRIBUTES_ENDS_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createBehaviorContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_behavior_EClass = factory->createEClass_in_EPackage(package, BEHAVIOR_ECLASS);
	m_behavior_EAttribute_isReentrant = factory->createEAttribute_in_EContainingClass(m_behavior_EClass, BEHAVIOR_EATTRIBUTE_ISREENTRANT);
	
	m_behavior_EReference_behavioredClassifier = factory->createEReference_in_EContainingClass(m_behavior_EClass, BEHAVIOR_EREFERENCE_BEHAVIOREDCLASSIFIER);
	m_behavior_EReference_context = factory->createEReference_in_EContainingClass(m_behavior_EClass, BEHAVIOR_EREFERENCE_CONTEXT);
	m_behavior_EReference_ownedParameter = factory->createEReference_in_EContainingClass(m_behavior_EClass, BEHAVIOR_EREFERENCE_OWNEDPARAMETER);
	m_behavior_EReference_ownedParameterSet = factory->createEReference_in_EContainingClass(m_behavior_EClass, BEHAVIOR_EREFERENCE_OWNEDPARAMETERSET);
	m_behavior_EReference_postcondition = factory->createEReference_in_EContainingClass(m_behavior_EClass, BEHAVIOR_EREFERENCE_POSTCONDITION);
	m_behavior_EReference_precondition = factory->createEReference_in_EContainingClass(m_behavior_EClass, BEHAVIOR_EREFERENCE_PRECONDITION);
	m_behavior_EReference_redefinedBehavior = factory->createEReference_in_EContainingClass(m_behavior_EClass, BEHAVIOR_EREFERENCE_REDEFINEDBEHAVIOR);
	m_behavior_EReference_specification = factory->createEReference_in_EContainingClass(m_behavior_EClass, BEHAVIOR_EREFERENCE_SPECIFICATION);
	
	m_behavior_EOperation_behavioredClassifier_Element = factory->createEOperation_in_EContainingClass(m_behavior_EClass, BEHAVIOR_EOPERATION_BEHAVIOREDCLASSIFIER_ELEMENT);
	m_behavior_EOperation_feature_of_context_classifier_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_behavior_EClass, BEHAVIOR_EOPERATION_FEATURE_OF_CONTEXT_CLASSIFIER_EDIAGNOSTICCHAIN_EMAP);
	m_behavior_EOperation_getContext = factory->createEOperation_in_EContainingClass(m_behavior_EClass, BEHAVIOR_EOPERATION_GETCONTEXT);
	m_behavior_EOperation_inputParameters = factory->createEOperation_in_EContainingClass(m_behavior_EClass, BEHAVIOR_EOPERATION_INPUTPARAMETERS);
	m_behavior_EOperation_most_one_behavior_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_behavior_EClass, BEHAVIOR_EOPERATION_MOST_ONE_BEHAVIOR_EDIAGNOSTICCHAIN_EMAP);
	m_behavior_EOperation_outputParameters = factory->createEOperation_in_EContainingClass(m_behavior_EClass, BEHAVIOR_EOPERATION_OUTPUTPARAMETERS);
	m_behavior_EOperation_parameters_match_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_behavior_EClass, BEHAVIOR_EOPERATION_PARAMETERS_MATCH_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createBehaviorExecutionSpecificationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_behaviorExecutionSpecification_EClass = factory->createEClass_in_EPackage(package, BEHAVIOREXECUTIONSPECIFICATION_ECLASS);
	
	m_behaviorExecutionSpecification_EReference_behavior = factory->createEReference_in_EContainingClass(m_behaviorExecutionSpecification_EClass, BEHAVIOREXECUTIONSPECIFICATION_EREFERENCE_BEHAVIOR);
	
	
}

void UmlPackageImpl::createBehavioralFeatureContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_behavioralFeature_EClass = factory->createEClass_in_EPackage(package, BEHAVIORALFEATURE_ECLASS);
	m_behavioralFeature_EAttribute_concurrency = factory->createEAttribute_in_EContainingClass(m_behavioralFeature_EClass, BEHAVIORALFEATURE_EATTRIBUTE_CONCURRENCY);
	m_behavioralFeature_EAttribute_isAbstract = factory->createEAttribute_in_EContainingClass(m_behavioralFeature_EClass, BEHAVIORALFEATURE_EATTRIBUTE_ISABSTRACT);
	
	m_behavioralFeature_EReference_method = factory->createEReference_in_EContainingClass(m_behavioralFeature_EClass, BEHAVIORALFEATURE_EREFERENCE_METHOD);
	m_behavioralFeature_EReference_ownedParameter = factory->createEReference_in_EContainingClass(m_behavioralFeature_EClass, BEHAVIORALFEATURE_EREFERENCE_OWNEDPARAMETER);
	m_behavioralFeature_EReference_ownedParameterSet = factory->createEReference_in_EContainingClass(m_behavioralFeature_EClass, BEHAVIORALFEATURE_EREFERENCE_OWNEDPARAMETERSET);
	m_behavioralFeature_EReference_raisedException = factory->createEReference_in_EContainingClass(m_behavioralFeature_EClass, BEHAVIORALFEATURE_EREFERENCE_RAISEDEXCEPTION);
	
	m_behavioralFeature_EOperation_abstract_no_method_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_behavioralFeature_EClass, BEHAVIORALFEATURE_EOPERATION_ABSTRACT_NO_METHOD_EDIAGNOSTICCHAIN_EMAP);
	m_behavioralFeature_EOperation_createReturnResult_String_Type = factory->createEOperation_in_EContainingClass(m_behavioralFeature_EClass, BEHAVIORALFEATURE_EOPERATION_CREATERETURNRESULT_STRING_TYPE);
	m_behavioralFeature_EOperation_inputParameters = factory->createEOperation_in_EContainingClass(m_behavioralFeature_EClass, BEHAVIORALFEATURE_EOPERATION_INPUTPARAMETERS);
	m_behavioralFeature_EOperation_outputParameters = factory->createEOperation_in_EContainingClass(m_behavioralFeature_EClass, BEHAVIORALFEATURE_EOPERATION_OUTPUTPARAMETERS);
	
}

void UmlPackageImpl::createBehavioredClassifierContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_behavioredClassifier_EClass = factory->createEClass_in_EPackage(package, BEHAVIOREDCLASSIFIER_ECLASS);
	
	m_behavioredClassifier_EReference_classifierBehavior = factory->createEReference_in_EContainingClass(m_behavioredClassifier_EClass, BEHAVIOREDCLASSIFIER_EREFERENCE_CLASSIFIERBEHAVIOR);
	m_behavioredClassifier_EReference_interfaceRealization = factory->createEReference_in_EContainingClass(m_behavioredClassifier_EClass, BEHAVIOREDCLASSIFIER_EREFERENCE_INTERFACEREALIZATION);
	m_behavioredClassifier_EReference_ownedBehavior = factory->createEReference_in_EContainingClass(m_behavioredClassifier_EClass, BEHAVIOREDCLASSIFIER_EREFERENCE_OWNEDBEHAVIOR);
	
	m_behavioredClassifier_EOperation_class_behavior_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_behavioredClassifier_EClass, BEHAVIOREDCLASSIFIER_EOPERATION_CLASS_BEHAVIOR_EDIAGNOSTICCHAIN_EMAP);
	m_behavioredClassifier_EOperation_getAllImplementedInterfaces = factory->createEOperation_in_EContainingClass(m_behavioredClassifier_EClass, BEHAVIOREDCLASSIFIER_EOPERATION_GETALLIMPLEMENTEDINTERFACES);
	m_behavioredClassifier_EOperation_getImplementedInterfaces = factory->createEOperation_in_EContainingClass(m_behavioredClassifier_EClass, BEHAVIOREDCLASSIFIER_EOPERATION_GETIMPLEMENTEDINTERFACES);
	
}

void UmlPackageImpl::createBroadcastSignalActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_broadcastSignalAction_EClass = factory->createEClass_in_EPackage(package, BROADCASTSIGNALACTION_ECLASS);
	
	m_broadcastSignalAction_EReference_signal = factory->createEReference_in_EContainingClass(m_broadcastSignalAction_EClass, BROADCASTSIGNALACTION_EREFERENCE_SIGNAL);
	
	m_broadcastSignalAction_EOperation_no_onport_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_broadcastSignalAction_EClass, BROADCASTSIGNALACTION_EOPERATION_NO_ONPORT_EDIAGNOSTICCHAIN_EMAP);
	m_broadcastSignalAction_EOperation_number_of_arguments_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_broadcastSignalAction_EClass, BROADCASTSIGNALACTION_EOPERATION_NUMBER_OF_ARGUMENTS_EDIAGNOSTICCHAIN_EMAP);
	m_broadcastSignalAction_EOperation_type_ordering_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_broadcastSignalAction_EClass, BROADCASTSIGNALACTION_EOPERATION_TYPE_ORDERING_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createCallActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_callAction_EClass = factory->createEClass_in_EPackage(package, CALLACTION_ECLASS);
	m_callAction_EAttribute_isSynchronous = factory->createEAttribute_in_EContainingClass(m_callAction_EClass, CALLACTION_EATTRIBUTE_ISSYNCHRONOUS);
	
	m_callAction_EReference_result = factory->createEReference_in_EContainingClass(m_callAction_EClass, CALLACTION_EREFERENCE_RESULT);
	
	m_callAction_EOperation_argument_pins_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_callAction_EClass, CALLACTION_EOPERATION_ARGUMENT_PINS_EDIAGNOSTICCHAIN_EMAP);
	m_callAction_EOperation_inputParameters = factory->createEOperation_in_EContainingClass(m_callAction_EClass, CALLACTION_EOPERATION_INPUTPARAMETERS);
	m_callAction_EOperation_outputParameters = factory->createEOperation_in_EContainingClass(m_callAction_EClass, CALLACTION_EOPERATION_OUTPUTPARAMETERS);
	m_callAction_EOperation_result_pins_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_callAction_EClass, CALLACTION_EOPERATION_RESULT_PINS_EDIAGNOSTICCHAIN_EMAP);
	m_callAction_EOperation_synchronous_call_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_callAction_EClass, CALLACTION_EOPERATION_SYNCHRONOUS_CALL_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createCallBehaviorActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_callBehaviorAction_EClass = factory->createEClass_in_EPackage(package, CALLBEHAVIORACTION_ECLASS);
	
	m_callBehaviorAction_EReference_behavior = factory->createEReference_in_EContainingClass(m_callBehaviorAction_EClass, CALLBEHAVIORACTION_EREFERENCE_BEHAVIOR);
	
	m_callBehaviorAction_EOperation_no_onport_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_callBehaviorAction_EClass, CALLBEHAVIORACTION_EOPERATION_NO_ONPORT_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createCallEventContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_callEvent_EClass = factory->createEClass_in_EPackage(package, CALLEVENT_ECLASS);
	
	m_callEvent_EReference_operation = factory->createEReference_in_EContainingClass(m_callEvent_EClass, CALLEVENT_EREFERENCE_OPERATION);
	
	
}

void UmlPackageImpl::createCallOperationActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_callOperationAction_EClass = factory->createEClass_in_EPackage(package, CALLOPERATIONACTION_ECLASS);
	
	m_callOperationAction_EReference_operation = factory->createEReference_in_EContainingClass(m_callOperationAction_EClass, CALLOPERATIONACTION_EREFERENCE_OPERATION);
	m_callOperationAction_EReference_target = factory->createEReference_in_EContainingClass(m_callOperationAction_EClass, CALLOPERATIONACTION_EREFERENCE_TARGET);
	
	m_callOperationAction_EOperation_type_target_pin_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_callOperationAction_EClass, CALLOPERATIONACTION_EOPERATION_TYPE_TARGET_PIN_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createCentralBufferNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_centralBufferNode_EClass = factory->createEClass_in_EPackage(package, CENTRALBUFFERNODE_ECLASS);
	
	
	
}

void UmlPackageImpl::createChangeEventContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_changeEvent_EClass = factory->createEClass_in_EPackage(package, CHANGEEVENT_ECLASS);
	
	m_changeEvent_EReference_changeExpression = factory->createEReference_in_EContainingClass(m_changeEvent_EClass, CHANGEEVENT_EREFERENCE_CHANGEEXPRESSION);
	
	
}

void UmlPackageImpl::createClassContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_class_EClass = factory->createEClass_in_EPackage(package, CLASS_ECLASS);
	m_class_EAttribute_isActive = factory->createEAttribute_in_EContainingClass(m_class_EClass, CLASS_EATTRIBUTE_ISACTIVE);
	
	m_class_EReference_extension = factory->createEReference_in_EContainingClass(m_class_EClass, CLASS_EREFERENCE_EXTENSION);
	m_class_EReference_nestedClassifier = factory->createEReference_in_EContainingClass(m_class_EClass, CLASS_EREFERENCE_NESTEDCLASSIFIER);
	m_class_EReference_ownedOperation = factory->createEReference_in_EContainingClass(m_class_EClass, CLASS_EREFERENCE_OWNEDOPERATION);
	m_class_EReference_ownedReception = factory->createEReference_in_EContainingClass(m_class_EClass, CLASS_EREFERENCE_OWNEDRECEPTION);
	m_class_EReference_superClass = factory->createEReference_in_EContainingClass(m_class_EClass, CLASS_EREFERENCE_SUPERCLASS);
	
	m_class_EOperation_createOwnedOperation_String_Type = factory->createEOperation_in_EContainingClass(m_class_EClass, CLASS_EOPERATION_CREATEOWNEDOPERATION_STRING_TYPE);
	m_class_EOperation_getExtensions = factory->createEOperation_in_EContainingClass(m_class_EClass, CLASS_EOPERATION_GETEXTENSIONS);
	m_class_EOperation_getSuperClasses = factory->createEOperation_in_EContainingClass(m_class_EClass, CLASS_EOPERATION_GETSUPERCLASSES);
	m_class_EOperation_isMetaclass = factory->createEOperation_in_EContainingClass(m_class_EClass, CLASS_EOPERATION_ISMETACLASS);
	m_class_EOperation_passive_class_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_class_EClass, CLASS_EOPERATION_PASSIVE_CLASS_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createClassifierContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_classifier_EClass = factory->createEClass_in_EPackage(package, CLASSIFIER_ECLASS);
	m_classifier_EAttribute_isAbstract = factory->createEAttribute_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EATTRIBUTE_ISABSTRACT);
	m_classifier_EAttribute_isFinalSpecialization = factory->createEAttribute_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EATTRIBUTE_ISFINALSPECIALIZATION);
	
	m_classifier_EReference_attribute = factory->createEReference_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EREFERENCE_ATTRIBUTE);
	m_classifier_EReference_collaborationUse = factory->createEReference_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EREFERENCE_COLLABORATIONUSE);
	m_classifier_EReference_feature = factory->createEReference_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EREFERENCE_FEATURE);
	m_classifier_EReference_general = factory->createEReference_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EREFERENCE_GENERAL);
	m_classifier_EReference_generalization = factory->createEReference_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EREFERENCE_GENERALIZATION);
	m_classifier_EReference_inheritedMember = factory->createEReference_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EREFERENCE_INHERITEDMEMBER);
	m_classifier_EReference_ownedUseCase = factory->createEReference_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EREFERENCE_OWNEDUSECASE);
	m_classifier_EReference_powertypeExtent = factory->createEReference_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EREFERENCE_POWERTYPEEXTENT);
	m_classifier_EReference_redefinedClassifier = factory->createEReference_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EREFERENCE_REDEFINEDCLASSIFIER);
	m_classifier_EReference_representation = factory->createEReference_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EREFERENCE_REPRESENTATION);
	m_classifier_EReference_substitution = factory->createEReference_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EREFERENCE_SUBSTITUTION);
	m_classifier_EReference_useCase = factory->createEReference_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EREFERENCE_USECASE);
	
	m_classifier_EOperation_allAttributes = factory->createEOperation_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EOPERATION_ALLATTRIBUTES);
	m_classifier_EOperation_allFeatures = factory->createEOperation_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EOPERATION_ALLFEATURES);
	m_classifier_EOperation_allParents = factory->createEOperation_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EOPERATION_ALLPARENTS);
	m_classifier_EOperation_allRealizedInterfaces = factory->createEOperation_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EOPERATION_ALLREALIZEDINTERFACES);
	m_classifier_EOperation_allSlottableFeatures = factory->createEOperation_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EOPERATION_ALLSLOTTABLEFEATURES);
	m_classifier_EOperation_allUsedInterfaces = factory->createEOperation_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EOPERATION_ALLUSEDINTERFACES);
	m_classifier_EOperation_directlyRealizedInterfaces = factory->createEOperation_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EOPERATION_DIRECTLYREALIZEDINTERFACES);
	m_classifier_EOperation_directlyUsedInterfaces = factory->createEOperation_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EOPERATION_DIRECTLYUSEDINTERFACES);
	m_classifier_EOperation_getAllAttributes = factory->createEOperation_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EOPERATION_GETALLATTRIBUTES);
	m_classifier_EOperation_getAllOperations = factory->createEOperation_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EOPERATION_GETALLOPERATIONS);
	m_classifier_EOperation_getAllUsedInterfaces = factory->createEOperation_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EOPERATION_GETALLUSEDINTERFACES);
	m_classifier_EOperation_getGenerals = factory->createEOperation_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EOPERATION_GETGENERALS);
	m_classifier_EOperation_getInheritedMembers = factory->createEOperation_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EOPERATION_GETINHERITEDMEMBERS);
	m_classifier_EOperation_getOperation_String_Type = factory->createEOperation_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EOPERATION_GETOPERATION_STRING_TYPE);
	m_classifier_EOperation_getOperation_String_Boolean = factory->createEOperation_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EOPERATION_GETOPERATION_STRING_BOOLEAN);
	m_classifier_EOperation_getOperations = factory->createEOperation_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EOPERATION_GETOPERATIONS);
	m_classifier_EOperation_getUsedInterfaces = factory->createEOperation_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EOPERATION_GETUSEDINTERFACES);
	m_classifier_EOperation_hasVisibilityOf_NamedElement = factory->createEOperation_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EOPERATION_HASVISIBILITYOF_NAMEDELEMENT);
	m_classifier_EOperation_inherit_NamedElement = factory->createEOperation_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EOPERATION_INHERIT_NAMEDELEMENT);
	m_classifier_EOperation_inheritableMembers_Classifier = factory->createEOperation_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EOPERATION_INHERITABLEMEMBERS_CLASSIFIER);
	m_classifier_EOperation_isSubstitutableFor_Classifier = factory->createEOperation_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EOPERATION_ISSUBSTITUTABLEFOR_CLASSIFIER);
	m_classifier_EOperation_maps_to_generalization_set_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EOPERATION_MAPS_TO_GENERALIZATION_SET_EDIAGNOSTICCHAIN_EMAP);
	m_classifier_EOperation_maySpecializeType_Classifier = factory->createEOperation_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EOPERATION_MAYSPECIALIZETYPE_CLASSIFIER);
	m_classifier_EOperation_no_cycles_in_generalization_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EOPERATION_NO_CYCLES_IN_GENERALIZATION_EDIAGNOSTICCHAIN_EMAP);
	m_classifier_EOperation_non_final_parents_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EOPERATION_NON_FINAL_PARENTS_EDIAGNOSTICCHAIN_EMAP);
	m_classifier_EOperation_parents = factory->createEOperation_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EOPERATION_PARENTS);
	m_classifier_EOperation_specialize_type_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_classifier_EClass, CLASSIFIER_EOPERATION_SPECIALIZE_TYPE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createClassifierTemplateParameterContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_classifierTemplateParameter_EClass = factory->createEClass_in_EPackage(package, CLASSIFIERTEMPLATEPARAMETER_ECLASS);
	m_classifierTemplateParameter_EAttribute_allowSubstitutable = factory->createEAttribute_in_EContainingClass(m_classifierTemplateParameter_EClass, CLASSIFIERTEMPLATEPARAMETER_EATTRIBUTE_ALLOWSUBSTITUTABLE);
	
	m_classifierTemplateParameter_EReference_constrainingClassifier = factory->createEReference_in_EContainingClass(m_classifierTemplateParameter_EClass, CLASSIFIERTEMPLATEPARAMETER_EREFERENCE_CONSTRAININGCLASSIFIER);
	
	m_classifierTemplateParameter_EOperation_actual_is_classifier_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_classifierTemplateParameter_EClass, CLASSIFIERTEMPLATEPARAMETER_EOPERATION_ACTUAL_IS_CLASSIFIER_EDIAGNOSTICCHAIN_EMAP);
	m_classifierTemplateParameter_EOperation_constraining_classifiers_constrain_args_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_classifierTemplateParameter_EClass, CLASSIFIERTEMPLATEPARAMETER_EOPERATION_CONSTRAINING_CLASSIFIERS_CONSTRAIN_ARGS_EDIAGNOSTICCHAIN_EMAP);
	m_classifierTemplateParameter_EOperation_constraining_classifiers_constrain_parametered_element_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_classifierTemplateParameter_EClass, CLASSIFIERTEMPLATEPARAMETER_EOPERATION_CONSTRAINING_CLASSIFIERS_CONSTRAIN_PARAMETERED_ELEMENT_EDIAGNOSTICCHAIN_EMAP);
	m_classifierTemplateParameter_EOperation_has_constraining_classifier_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_classifierTemplateParameter_EClass, CLASSIFIERTEMPLATEPARAMETER_EOPERATION_HAS_CONSTRAINING_CLASSIFIER_EDIAGNOSTICCHAIN_EMAP);
	m_classifierTemplateParameter_EOperation_matching_abstract_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_classifierTemplateParameter_EClass, CLASSIFIERTEMPLATEPARAMETER_EOPERATION_MATCHING_ABSTRACT_EDIAGNOSTICCHAIN_EMAP);
	m_classifierTemplateParameter_EOperation_parametered_element_no_features_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_classifierTemplateParameter_EClass, CLASSIFIERTEMPLATEPARAMETER_EOPERATION_PARAMETERED_ELEMENT_NO_FEATURES_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createClauseContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_clause_EClass = factory->createEClass_in_EPackage(package, CLAUSE_ECLASS);
	
	m_clause_EReference_body = factory->createEReference_in_EContainingClass(m_clause_EClass, CLAUSE_EREFERENCE_BODY);
	m_clause_EReference_bodyOutput = factory->createEReference_in_EContainingClass(m_clause_EClass, CLAUSE_EREFERENCE_BODYOUTPUT);
	m_clause_EReference_decider = factory->createEReference_in_EContainingClass(m_clause_EClass, CLAUSE_EREFERENCE_DECIDER);
	m_clause_EReference_predecessorClause = factory->createEReference_in_EContainingClass(m_clause_EClass, CLAUSE_EREFERENCE_PREDECESSORCLAUSE);
	m_clause_EReference_successorClause = factory->createEReference_in_EContainingClass(m_clause_EClass, CLAUSE_EREFERENCE_SUCCESSORCLAUSE);
	m_clause_EReference_test = factory->createEReference_in_EContainingClass(m_clause_EClass, CLAUSE_EREFERENCE_TEST);
	
	m_clause_EOperation_body_output_pins_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_clause_EClass, CLAUSE_EOPERATION_BODY_OUTPUT_PINS_EDIAGNOSTICCHAIN_EMAP);
	m_clause_EOperation_decider_output_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_clause_EClass, CLAUSE_EOPERATION_DECIDER_OUTPUT_EDIAGNOSTICCHAIN_EMAP);
	m_clause_EOperation_test_and_body_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_clause_EClass, CLAUSE_EOPERATION_TEST_AND_BODY_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createClearAssociationActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_clearAssociationAction_EClass = factory->createEClass_in_EPackage(package, CLEARASSOCIATIONACTION_ECLASS);
	
	m_clearAssociationAction_EReference_association = factory->createEReference_in_EContainingClass(m_clearAssociationAction_EClass, CLEARASSOCIATIONACTION_EREFERENCE_ASSOCIATION);
	m_clearAssociationAction_EReference_object = factory->createEReference_in_EContainingClass(m_clearAssociationAction_EClass, CLEARASSOCIATIONACTION_EREFERENCE_OBJECT);
	
	m_clearAssociationAction_EOperation_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_clearAssociationAction_EClass, CLEARASSOCIATIONACTION_EOPERATION_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	m_clearAssociationAction_EOperation_same_type_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_clearAssociationAction_EClass, CLEARASSOCIATIONACTION_EOPERATION_SAME_TYPE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createClearStructuralFeatureActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_clearStructuralFeatureAction_EClass = factory->createEClass_in_EPackage(package, CLEARSTRUCTURALFEATUREACTION_ECLASS);
	
	m_clearStructuralFeatureAction_EReference_result = factory->createEReference_in_EContainingClass(m_clearStructuralFeatureAction_EClass, CLEARSTRUCTURALFEATUREACTION_EREFERENCE_RESULT);
	
	m_clearStructuralFeatureAction_EOperation_multiplicity_of_result_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_clearStructuralFeatureAction_EClass, CLEARSTRUCTURALFEATUREACTION_EOPERATION_MULTIPLICITY_OF_RESULT_EDIAGNOSTICCHAIN_EMAP);
	m_clearStructuralFeatureAction_EOperation_type_of_result_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_clearStructuralFeatureAction_EClass, CLEARSTRUCTURALFEATUREACTION_EOPERATION_TYPE_OF_RESULT_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createClearVariableActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_clearVariableAction_EClass = factory->createEClass_in_EPackage(package, CLEARVARIABLEACTION_ECLASS);
	
	
	
}

void UmlPackageImpl::createCollaborationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_collaboration_EClass = factory->createEClass_in_EPackage(package, COLLABORATION_ECLASS);
	
	m_collaboration_EReference_collaborationRole = factory->createEReference_in_EContainingClass(m_collaboration_EClass, COLLABORATION_EREFERENCE_COLLABORATIONROLE);
	
	
}

void UmlPackageImpl::createCollaborationUseContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_collaborationUse_EClass = factory->createEClass_in_EPackage(package, COLLABORATIONUSE_ECLASS);
	
	m_collaborationUse_EReference_roleBinding = factory->createEReference_in_EContainingClass(m_collaborationUse_EClass, COLLABORATIONUSE_EREFERENCE_ROLEBINDING);
	m_collaborationUse_EReference_type = factory->createEReference_in_EContainingClass(m_collaborationUse_EClass, COLLABORATIONUSE_EREFERENCE_TYPE);
	
	m_collaborationUse_EOperation_client_elements_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_collaborationUse_EClass, COLLABORATIONUSE_EOPERATION_CLIENT_ELEMENTS_EDIAGNOSTICCHAIN_EMAP);
	m_collaborationUse_EOperation_connectors_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_collaborationUse_EClass, COLLABORATIONUSE_EOPERATION_CONNECTORS_EDIAGNOSTICCHAIN_EMAP);
	m_collaborationUse_EOperation_every_role_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_collaborationUse_EClass, COLLABORATIONUSE_EOPERATION_EVERY_ROLE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createCombinedFragmentContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_combinedFragment_EClass = factory->createEClass_in_EPackage(package, COMBINEDFRAGMENT_ECLASS);
	m_combinedFragment_EAttribute_interactionOperator = factory->createEAttribute_in_EContainingClass(m_combinedFragment_EClass, COMBINEDFRAGMENT_EATTRIBUTE_INTERACTIONOPERATOR);
	
	m_combinedFragment_EReference_cfragmentGate = factory->createEReference_in_EContainingClass(m_combinedFragment_EClass, COMBINEDFRAGMENT_EREFERENCE_CFRAGMENTGATE);
	m_combinedFragment_EReference_operand = factory->createEReference_in_EContainingClass(m_combinedFragment_EClass, COMBINEDFRAGMENT_EREFERENCE_OPERAND);
	
	m_combinedFragment_EOperation_break__EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_combinedFragment_EClass, COMBINEDFRAGMENT_EOPERATION_BREAK__EDIAGNOSTICCHAIN_EMAP);
	m_combinedFragment_EOperation_consider_and_ignore_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_combinedFragment_EClass, COMBINEDFRAGMENT_EOPERATION_CONSIDER_AND_IGNORE_EDIAGNOSTICCHAIN_EMAP);
	m_combinedFragment_EOperation_opt_loop_break_neg_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_combinedFragment_EClass, COMBINEDFRAGMENT_EOPERATION_OPT_LOOP_BREAK_NEG_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createCommentContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_comment_EClass = factory->createEClass_in_EPackage(package, COMMENT_ECLASS);
	m_comment_EAttribute_body = factory->createEAttribute_in_EContainingClass(m_comment_EClass, COMMENT_EATTRIBUTE_BODY);
	
	m_comment_EReference_annotatedElement = factory->createEReference_in_EContainingClass(m_comment_EClass, COMMENT_EREFERENCE_ANNOTATEDELEMENT);
	
	
}

void UmlPackageImpl::createCommunicationPathContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_communicationPath_EClass = factory->createEClass_in_EPackage(package, COMMUNICATIONPATH_ECLASS);
	
	
	
}

void UmlPackageImpl::createComponentContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_component_EClass = factory->createEClass_in_EPackage(package, COMPONENT_ECLASS);
	m_component_EAttribute_isIndirectlyInstantiated = factory->createEAttribute_in_EContainingClass(m_component_EClass, COMPONENT_EATTRIBUTE_ISINDIRECTLYINSTANTIATED);
	
	m_component_EReference_packagedElement = factory->createEReference_in_EContainingClass(m_component_EClass, COMPONENT_EREFERENCE_PACKAGEDELEMENT);
	m_component_EReference_provided = factory->createEReference_in_EContainingClass(m_component_EClass, COMPONENT_EREFERENCE_PROVIDED);
	m_component_EReference_realization = factory->createEReference_in_EContainingClass(m_component_EClass, COMPONENT_EREFERENCE_REALIZATION);
	m_component_EReference_required = factory->createEReference_in_EContainingClass(m_component_EClass, COMPONENT_EREFERENCE_REQUIRED);
	
	m_component_EOperation_createOwnedClass_String_Boolean = factory->createEOperation_in_EContainingClass(m_component_EClass, COMPONENT_EOPERATION_CREATEOWNEDCLASS_STRING_BOOLEAN);
	m_component_EOperation_createOwnedEnumeration_String = factory->createEOperation_in_EContainingClass(m_component_EClass, COMPONENT_EOPERATION_CREATEOWNEDENUMERATION_STRING);
	m_component_EOperation_createOwnedInterface_String = factory->createEOperation_in_EContainingClass(m_component_EClass, COMPONENT_EOPERATION_CREATEOWNEDINTERFACE_STRING);
	m_component_EOperation_createOwnedPrimitiveType_String = factory->createEOperation_in_EContainingClass(m_component_EClass, COMPONENT_EOPERATION_CREATEOWNEDPRIMITIVETYPE_STRING);
	m_component_EOperation_getProvideds = factory->createEOperation_in_EContainingClass(m_component_EClass, COMPONENT_EOPERATION_GETPROVIDEDS);
	m_component_EOperation_getRequireds = factory->createEOperation_in_EContainingClass(m_component_EClass, COMPONENT_EOPERATION_GETREQUIREDS);
	m_component_EOperation_no_nested_classifiers_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_component_EClass, COMPONENT_EOPERATION_NO_NESTED_CLASSIFIERS_EDIAGNOSTICCHAIN_EMAP);
	m_component_EOperation_no_packaged_elements_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_component_EClass, COMPONENT_EOPERATION_NO_PACKAGED_ELEMENTS_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createComponentRealizationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_componentRealization_EClass = factory->createEClass_in_EPackage(package, COMPONENTREALIZATION_ECLASS);
	
	m_componentRealization_EReference_abstraction = factory->createEReference_in_EContainingClass(m_componentRealization_EClass, COMPONENTREALIZATION_EREFERENCE_ABSTRACTION);
	m_componentRealization_EReference_realizingClassifier = factory->createEReference_in_EContainingClass(m_componentRealization_EClass, COMPONENTREALIZATION_EREFERENCE_REALIZINGCLASSIFIER);
	
	
}

void UmlPackageImpl::createConditionalNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_conditionalNode_EClass = factory->createEClass_in_EPackage(package, CONDITIONALNODE_ECLASS);
	m_conditionalNode_EAttribute_isAssured = factory->createEAttribute_in_EContainingClass(m_conditionalNode_EClass, CONDITIONALNODE_EATTRIBUTE_ISASSURED);
	m_conditionalNode_EAttribute_isDeterminate = factory->createEAttribute_in_EContainingClass(m_conditionalNode_EClass, CONDITIONALNODE_EATTRIBUTE_ISDETERMINATE);
	
	m_conditionalNode_EReference_clause = factory->createEReference_in_EContainingClass(m_conditionalNode_EClass, CONDITIONALNODE_EREFERENCE_CLAUSE);
	m_conditionalNode_EReference_result = factory->createEReference_in_EContainingClass(m_conditionalNode_EClass, CONDITIONALNODE_EREFERENCE_RESULT);
	
	m_conditionalNode_EOperation_clause_no_predecessor_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_conditionalNode_EClass, CONDITIONALNODE_EOPERATION_CLAUSE_NO_PREDECESSOR_EDIAGNOSTICCHAIN_EMAP);
	m_conditionalNode_EOperation_executable_nodes_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_conditionalNode_EClass, CONDITIONALNODE_EOPERATION_EXECUTABLE_NODES_EDIAGNOSTICCHAIN_EMAP);
	m_conditionalNode_EOperation_matching_output_pins_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_conditionalNode_EClass, CONDITIONALNODE_EOPERATION_MATCHING_OUTPUT_PINS_EDIAGNOSTICCHAIN_EMAP);
	m_conditionalNode_EOperation_no_input_pins_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_conditionalNode_EClass, CONDITIONALNODE_EOPERATION_NO_INPUT_PINS_EDIAGNOSTICCHAIN_EMAP);
	m_conditionalNode_EOperation_one_clause_with_executable_node_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_conditionalNode_EClass, CONDITIONALNODE_EOPERATION_ONE_CLAUSE_WITH_EXECUTABLE_NODE_EDIAGNOSTICCHAIN_EMAP);
	m_conditionalNode_EOperation_result_no_incoming_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_conditionalNode_EClass, CONDITIONALNODE_EOPERATION_RESULT_NO_INCOMING_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createConnectableElementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_connectableElement_EClass = factory->createEClass_in_EPackage(package, CONNECTABLEELEMENT_ECLASS);
	
	m_connectableElement_EReference_end = factory->createEReference_in_EContainingClass(m_connectableElement_EClass, CONNECTABLEELEMENT_EREFERENCE_END);
	
	m_connectableElement_EOperation_getEnds = factory->createEOperation_in_EContainingClass(m_connectableElement_EClass, CONNECTABLEELEMENT_EOPERATION_GETENDS);
	
}

void UmlPackageImpl::createConnectableElementTemplateParameterContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_connectableElementTemplateParameter_EClass = factory->createEClass_in_EPackage(package, CONNECTABLEELEMENTTEMPLATEPARAMETER_ECLASS);
	
	
	
}

void UmlPackageImpl::createConnectionPointReferenceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_connectionPointReference_EClass = factory->createEClass_in_EPackage(package, CONNECTIONPOINTREFERENCE_ECLASS);
	
	m_connectionPointReference_EReference_entry = factory->createEReference_in_EContainingClass(m_connectionPointReference_EClass, CONNECTIONPOINTREFERENCE_EREFERENCE_ENTRY);
	m_connectionPointReference_EReference_exit = factory->createEReference_in_EContainingClass(m_connectionPointReference_EClass, CONNECTIONPOINTREFERENCE_EREFERENCE_EXIT);
	m_connectionPointReference_EReference_state = factory->createEReference_in_EContainingClass(m_connectionPointReference_EClass, CONNECTIONPOINTREFERENCE_EREFERENCE_STATE);
	
	m_connectionPointReference_EOperation_entry_pseudostates_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_connectionPointReference_EClass, CONNECTIONPOINTREFERENCE_EOPERATION_ENTRY_PSEUDOSTATES_EDIAGNOSTICCHAIN_EMAP);
	m_connectionPointReference_EOperation_exit_pseudostates_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_connectionPointReference_EClass, CONNECTIONPOINTREFERENCE_EOPERATION_EXIT_PSEUDOSTATES_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createConnectorContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_connector_EClass = factory->createEClass_in_EPackage(package, CONNECTOR_ECLASS);
	m_connector_EAttribute_kind = factory->createEAttribute_in_EContainingClass(m_connector_EClass, CONNECTOR_EATTRIBUTE_KIND);
	
	m_connector_EReference_contract = factory->createEReference_in_EContainingClass(m_connector_EClass, CONNECTOR_EREFERENCE_CONTRACT);
	m_connector_EReference_end = factory->createEReference_in_EContainingClass(m_connector_EClass, CONNECTOR_EREFERENCE_END);
	m_connector_EReference_redefinedConnector = factory->createEReference_in_EContainingClass(m_connector_EClass, CONNECTOR_EREFERENCE_REDEFINEDCONNECTOR);
	m_connector_EReference_type = factory->createEReference_in_EContainingClass(m_connector_EClass, CONNECTOR_EREFERENCE_TYPE);
	
	m_connector_EOperation_getKind = factory->createEOperation_in_EContainingClass(m_connector_EClass, CONNECTOR_EOPERATION_GETKIND);
	m_connector_EOperation_roles_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_connector_EClass, CONNECTOR_EOPERATION_ROLES_EDIAGNOSTICCHAIN_EMAP);
	m_connector_EOperation_types_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_connector_EClass, CONNECTOR_EOPERATION_TYPES_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createConnectorEndContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_connectorEnd_EClass = factory->createEClass_in_EPackage(package, CONNECTOREND_ECLASS);
	
	m_connectorEnd_EReference_definingEnd = factory->createEReference_in_EContainingClass(m_connectorEnd_EClass, CONNECTOREND_EREFERENCE_DEFININGEND);
	m_connectorEnd_EReference_partWithPort = factory->createEReference_in_EContainingClass(m_connectorEnd_EClass, CONNECTOREND_EREFERENCE_PARTWITHPORT);
	m_connectorEnd_EReference_role = factory->createEReference_in_EContainingClass(m_connectorEnd_EClass, CONNECTOREND_EREFERENCE_ROLE);
	
	m_connectorEnd_EOperation_getDefiningEnd = factory->createEOperation_in_EContainingClass(m_connectorEnd_EClass, CONNECTOREND_EOPERATION_GETDEFININGEND);
	m_connectorEnd_EOperation_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_connectorEnd_EClass, CONNECTOREND_EOPERATION_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	m_connectorEnd_EOperation_part_with_port_empty_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_connectorEnd_EClass, CONNECTOREND_EOPERATION_PART_WITH_PORT_EMPTY_EDIAGNOSTICCHAIN_EMAP);
	m_connectorEnd_EOperation_role_and_part_with_port_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_connectorEnd_EClass, CONNECTOREND_EOPERATION_ROLE_AND_PART_WITH_PORT_EDIAGNOSTICCHAIN_EMAP);
	m_connectorEnd_EOperation_self_part_with_port_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_connectorEnd_EClass, CONNECTOREND_EOPERATION_SELF_PART_WITH_PORT_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createConsiderIgnoreFragmentContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_considerIgnoreFragment_EClass = factory->createEClass_in_EPackage(package, CONSIDERIGNOREFRAGMENT_ECLASS);
	
	m_considerIgnoreFragment_EReference_message = factory->createEReference_in_EContainingClass(m_considerIgnoreFragment_EClass, CONSIDERIGNOREFRAGMENT_EREFERENCE_MESSAGE);
	
	m_considerIgnoreFragment_EOperation_consider_or_ignore_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_considerIgnoreFragment_EClass, CONSIDERIGNOREFRAGMENT_EOPERATION_CONSIDER_OR_IGNORE_EDIAGNOSTICCHAIN_EMAP);
	m_considerIgnoreFragment_EOperation_type_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_considerIgnoreFragment_EClass, CONSIDERIGNOREFRAGMENT_EOPERATION_TYPE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createConstraintContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_constraint_EClass = factory->createEClass_in_EPackage(package, CONSTRAINT_ECLASS);
	
	m_constraint_EReference_constrainedElement = factory->createEReference_in_EContainingClass(m_constraint_EClass, CONSTRAINT_EREFERENCE_CONSTRAINEDELEMENT);
	m_constraint_EReference_context = factory->createEReference_in_EContainingClass(m_constraint_EClass, CONSTRAINT_EREFERENCE_CONTEXT);
	m_constraint_EReference_specification = factory->createEReference_in_EContainingClass(m_constraint_EClass, CONSTRAINT_EREFERENCE_SPECIFICATION);
	
	m_constraint_EOperation_boolean_value_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_constraint_EClass, CONSTRAINT_EOPERATION_BOOLEAN_VALUE_EDIAGNOSTICCHAIN_EMAP);
	m_constraint_EOperation_no_side_effects_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_constraint_EClass, CONSTRAINT_EOPERATION_NO_SIDE_EFFECTS_EDIAGNOSTICCHAIN_EMAP);
	m_constraint_EOperation_not_apply_to_self_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_constraint_EClass, CONSTRAINT_EOPERATION_NOT_APPLY_TO_SELF_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createContinuationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_continuation_EClass = factory->createEClass_in_EPackage(package, CONTINUATION_ECLASS);
	m_continuation_EAttribute_setting = factory->createEAttribute_in_EContainingClass(m_continuation_EClass, CONTINUATION_EATTRIBUTE_SETTING);
	
	
	m_continuation_EOperation_first_or_last_interaction_fragment_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_continuation_EClass, CONTINUATION_EOPERATION_FIRST_OR_LAST_INTERACTION_FRAGMENT_EDIAGNOSTICCHAIN_EMAP);
	m_continuation_EOperation_global_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_continuation_EClass, CONTINUATION_EOPERATION_GLOBAL_EDIAGNOSTICCHAIN_EMAP);
	m_continuation_EOperation_same_name_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_continuation_EClass, CONTINUATION_EOPERATION_SAME_NAME_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createControlFlowContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_controlFlow_EClass = factory->createEClass_in_EPackage(package, CONTROLFLOW_ECLASS);
	
	
	m_controlFlow_EOperation_object_nodes_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_controlFlow_EClass, CONTROLFLOW_EOPERATION_OBJECT_NODES_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createControlNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_controlNode_EClass = factory->createEClass_in_EPackage(package, CONTROLNODE_ECLASS);
	
	
	
}

void UmlPackageImpl::createCreateLinkActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_createLinkAction_EClass = factory->createEClass_in_EPackage(package, CREATELINKACTION_ECLASS);
	
	
	m_createLinkAction_EOperation_association_not_abstract_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_createLinkAction_EClass, CREATELINKACTION_EOPERATION_ASSOCIATION_NOT_ABSTRACT_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createCreateLinkObjectActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_createLinkObjectAction_EClass = factory->createEClass_in_EPackage(package, CREATELINKOBJECTACTION_ECLASS);
	
	m_createLinkObjectAction_EReference_result = factory->createEReference_in_EContainingClass(m_createLinkObjectAction_EClass, CREATELINKOBJECTACTION_EREFERENCE_RESULT);
	
	m_createLinkObjectAction_EOperation_association_class_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_createLinkObjectAction_EClass, CREATELINKOBJECTACTION_EOPERATION_ASSOCIATION_CLASS_EDIAGNOSTICCHAIN_EMAP);
	m_createLinkObjectAction_EOperation_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_createLinkObjectAction_EClass, CREATELINKOBJECTACTION_EOPERATION_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	m_createLinkObjectAction_EOperation_type_of_result_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_createLinkObjectAction_EClass, CREATELINKOBJECTACTION_EOPERATION_TYPE_OF_RESULT_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createCreateObjectActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_createObjectAction_EClass = factory->createEClass_in_EPackage(package, CREATEOBJECTACTION_ECLASS);
	
	m_createObjectAction_EReference_classifier = factory->createEReference_in_EContainingClass(m_createObjectAction_EClass, CREATEOBJECTACTION_EREFERENCE_CLASSIFIER);
	m_createObjectAction_EReference_result = factory->createEReference_in_EContainingClass(m_createObjectAction_EClass, CREATEOBJECTACTION_EREFERENCE_RESULT);
	
	m_createObjectAction_EOperation_classifier_not_abstract_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_createObjectAction_EClass, CREATEOBJECTACTION_EOPERATION_CLASSIFIER_NOT_ABSTRACT_EDIAGNOSTICCHAIN_EMAP);
	m_createObjectAction_EOperation_classifier_not_association_class_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_createObjectAction_EClass, CREATEOBJECTACTION_EOPERATION_CLASSIFIER_NOT_ASSOCIATION_CLASS_EDIAGNOSTICCHAIN_EMAP);
	m_createObjectAction_EOperation_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_createObjectAction_EClass, CREATEOBJECTACTION_EOPERATION_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	m_createObjectAction_EOperation_same_type_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_createObjectAction_EClass, CREATEOBJECTACTION_EOPERATION_SAME_TYPE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createDataStoreNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_dataStoreNode_EClass = factory->createEClass_in_EPackage(package, DATASTORENODE_ECLASS);
	
	
	
}

void UmlPackageImpl::createDataTypeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_dataType_EClass = factory->createEClass_in_EPackage(package, DATATYPE_ECLASS);
	
	m_dataType_EReference_ownedAttribute = factory->createEReference_in_EContainingClass(m_dataType_EClass, DATATYPE_EREFERENCE_OWNEDATTRIBUTE);
	m_dataType_EReference_ownedOperation = factory->createEReference_in_EContainingClass(m_dataType_EClass, DATATYPE_EREFERENCE_OWNEDOPERATION);
	
	m_dataType_EOperation_createOwnedAttribute_String_UnlimitedNatural = factory->createEOperation_in_EContainingClass(m_dataType_EClass, DATATYPE_EOPERATION_CREATEOWNEDATTRIBUTE_STRING_UNLIMITEDNATURAL);
	m_dataType_EOperation_createOwnedOperation_String_Type = factory->createEOperation_in_EContainingClass(m_dataType_EClass, DATATYPE_EOPERATION_CREATEOWNEDOPERATION_STRING_TYPE);
	
}

void UmlPackageImpl::createDecisionNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_decisionNode_EClass = factory->createEClass_in_EPackage(package, DECISIONNODE_ECLASS);
	
	m_decisionNode_EReference_decisionInput = factory->createEReference_in_EContainingClass(m_decisionNode_EClass, DECISIONNODE_EREFERENCE_DECISIONINPUT);
	m_decisionNode_EReference_decisionInputFlow = factory->createEReference_in_EContainingClass(m_decisionNode_EClass, DECISIONNODE_EREFERENCE_DECISIONINPUTFLOW);
	
	m_decisionNode_EOperation_decision_input_flow_incoming_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_decisionNode_EClass, DECISIONNODE_EOPERATION_DECISION_INPUT_FLOW_INCOMING_EDIAGNOSTICCHAIN_EMAP);
	m_decisionNode_EOperation_edges_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_decisionNode_EClass, DECISIONNODE_EOPERATION_EDGES_EDIAGNOSTICCHAIN_EMAP);
	m_decisionNode_EOperation_incoming_control_one_input_parameter_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_decisionNode_EClass, DECISIONNODE_EOPERATION_INCOMING_CONTROL_ONE_INPUT_PARAMETER_EDIAGNOSTICCHAIN_EMAP);
	m_decisionNode_EOperation_incoming_object_one_input_parameter_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_decisionNode_EClass, DECISIONNODE_EOPERATION_INCOMING_OBJECT_ONE_INPUT_PARAMETER_EDIAGNOSTICCHAIN_EMAP);
	m_decisionNode_EOperation_incoming_outgoing_edges_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_decisionNode_EClass, DECISIONNODE_EOPERATION_INCOMING_OUTGOING_EDGES_EDIAGNOSTICCHAIN_EMAP);
	m_decisionNode_EOperation_parameters_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_decisionNode_EClass, DECISIONNODE_EOPERATION_PARAMETERS_EDIAGNOSTICCHAIN_EMAP);
	m_decisionNode_EOperation_two_input_parameters_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_decisionNode_EClass, DECISIONNODE_EOPERATION_TWO_INPUT_PARAMETERS_EDIAGNOSTICCHAIN_EMAP);
	m_decisionNode_EOperation_zero_input_parameters_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_decisionNode_EClass, DECISIONNODE_EOPERATION_ZERO_INPUT_PARAMETERS_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createDependencyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_dependency_EClass = factory->createEClass_in_EPackage(package, DEPENDENCY_ECLASS);
	
	m_dependency_EReference_client = factory->createEReference_in_EContainingClass(m_dependency_EClass, DEPENDENCY_EREFERENCE_CLIENT);
	m_dependency_EReference_supplier = factory->createEReference_in_EContainingClass(m_dependency_EClass, DEPENDENCY_EREFERENCE_SUPPLIER);
	
	
}

void UmlPackageImpl::createDeployedArtifactContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_deployedArtifact_EClass = factory->createEClass_in_EPackage(package, DEPLOYEDARTIFACT_ECLASS);
	
	
	
}

void UmlPackageImpl::createDeploymentContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_deployment_EClass = factory->createEClass_in_EPackage(package, DEPLOYMENT_ECLASS);
	
	m_deployment_EReference_configuration = factory->createEReference_in_EContainingClass(m_deployment_EClass, DEPLOYMENT_EREFERENCE_CONFIGURATION);
	m_deployment_EReference_deployedArtifact = factory->createEReference_in_EContainingClass(m_deployment_EClass, DEPLOYMENT_EREFERENCE_DEPLOYEDARTIFACT);
	m_deployment_EReference_location = factory->createEReference_in_EContainingClass(m_deployment_EClass, DEPLOYMENT_EREFERENCE_LOCATION);
	
	
}

void UmlPackageImpl::createDeploymentSpecificationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_deploymentSpecification_EClass = factory->createEClass_in_EPackage(package, DEPLOYMENTSPECIFICATION_ECLASS);
	m_deploymentSpecification_EAttribute_deploymentLocation = factory->createEAttribute_in_EContainingClass(m_deploymentSpecification_EClass, DEPLOYMENTSPECIFICATION_EATTRIBUTE_DEPLOYMENTLOCATION);
	m_deploymentSpecification_EAttribute_executionLocation = factory->createEAttribute_in_EContainingClass(m_deploymentSpecification_EClass, DEPLOYMENTSPECIFICATION_EATTRIBUTE_EXECUTIONLOCATION);
	
	m_deploymentSpecification_EReference_deployment = factory->createEReference_in_EContainingClass(m_deploymentSpecification_EClass, DEPLOYMENTSPECIFICATION_EREFERENCE_DEPLOYMENT);
	
	m_deploymentSpecification_EOperation_deployed_elements_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_deploymentSpecification_EClass, DEPLOYMENTSPECIFICATION_EOPERATION_DEPLOYED_ELEMENTS_EDIAGNOSTICCHAIN_EMAP);
	m_deploymentSpecification_EOperation_deployment_target_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_deploymentSpecification_EClass, DEPLOYMENTSPECIFICATION_EOPERATION_DEPLOYMENT_TARGET_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createDeploymentTargetContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_deploymentTarget_EClass = factory->createEClass_in_EPackage(package, DEPLOYMENTTARGET_ECLASS);
	
	m_deploymentTarget_EReference_deployedElement = factory->createEReference_in_EContainingClass(m_deploymentTarget_EClass, DEPLOYMENTTARGET_EREFERENCE_DEPLOYEDELEMENT);
	m_deploymentTarget_EReference_deployment = factory->createEReference_in_EContainingClass(m_deploymentTarget_EClass, DEPLOYMENTTARGET_EREFERENCE_DEPLOYMENT);
	
	m_deploymentTarget_EOperation_getDeployedElements = factory->createEOperation_in_EContainingClass(m_deploymentTarget_EClass, DEPLOYMENTTARGET_EOPERATION_GETDEPLOYEDELEMENTS);
	
}

void UmlPackageImpl::createDestroyLinkActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_destroyLinkAction_EClass = factory->createEClass_in_EPackage(package, DESTROYLINKACTION_ECLASS);
	
	
	
}

void UmlPackageImpl::createDestroyObjectActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_destroyObjectAction_EClass = factory->createEClass_in_EPackage(package, DESTROYOBJECTACTION_ECLASS);
	m_destroyObjectAction_EAttribute_isDestroyLinks = factory->createEAttribute_in_EContainingClass(m_destroyObjectAction_EClass, DESTROYOBJECTACTION_EATTRIBUTE_ISDESTROYLINKS);
	m_destroyObjectAction_EAttribute_isDestroyOwnedObjects = factory->createEAttribute_in_EContainingClass(m_destroyObjectAction_EClass, DESTROYOBJECTACTION_EATTRIBUTE_ISDESTROYOWNEDOBJECTS);
	
	m_destroyObjectAction_EReference_target = factory->createEReference_in_EContainingClass(m_destroyObjectAction_EClass, DESTROYOBJECTACTION_EREFERENCE_TARGET);
	
	m_destroyObjectAction_EOperation_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_destroyObjectAction_EClass, DESTROYOBJECTACTION_EOPERATION_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	m_destroyObjectAction_EOperation_no_type_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_destroyObjectAction_EClass, DESTROYOBJECTACTION_EOPERATION_NO_TYPE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createDestructionOccurrenceSpecificationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_destructionOccurrenceSpecification_EClass = factory->createEClass_in_EPackage(package, DESTRUCTIONOCCURRENCESPECIFICATION_ECLASS);
	
	
	m_destructionOccurrenceSpecification_EOperation_no_occurrence_specifications_below_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_destructionOccurrenceSpecification_EClass, DESTRUCTIONOCCURRENCESPECIFICATION_EOPERATION_NO_OCCURRENCE_SPECIFICATIONS_BELOW_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createDeviceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_device_EClass = factory->createEClass_in_EPackage(package, DEVICE_ECLASS);
	
	
	
}

void UmlPackageImpl::createDirectedRelationshipContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_directedRelationship_EClass = factory->createEClass_in_EPackage(package, DIRECTEDRELATIONSHIP_ECLASS);
	
	m_directedRelationship_EReference_source = factory->createEReference_in_EContainingClass(m_directedRelationship_EClass, DIRECTEDRELATIONSHIP_EREFERENCE_SOURCE);
	m_directedRelationship_EReference_target = factory->createEReference_in_EContainingClass(m_directedRelationship_EClass, DIRECTEDRELATIONSHIP_EREFERENCE_TARGET);
	
	
}

void UmlPackageImpl::createDurationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_duration_EClass = factory->createEClass_in_EPackage(package, DURATION_ECLASS);
	
	m_duration_EReference_expr = factory->createEReference_in_EContainingClass(m_duration_EClass, DURATION_EREFERENCE_EXPR);
	m_duration_EReference_observation = factory->createEReference_in_EContainingClass(m_duration_EClass, DURATION_EREFERENCE_OBSERVATION);
	
	m_duration_EOperation_no_expr_requires_observation_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_duration_EClass, DURATION_EOPERATION_NO_EXPR_REQUIRES_OBSERVATION_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createDurationConstraintContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_durationConstraint_EClass = factory->createEClass_in_EPackage(package, DURATIONCONSTRAINT_ECLASS);
	m_durationConstraint_EAttribute_firstEvent = factory->createEAttribute_in_EContainingClass(m_durationConstraint_EClass, DURATIONCONSTRAINT_EATTRIBUTE_FIRSTEVENT);
	
	
	m_durationConstraint_EOperation_first_event_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_durationConstraint_EClass, DURATIONCONSTRAINT_EOPERATION_FIRST_EVENT_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	m_durationConstraint_EOperation_has_one_or_two_constrainedElements_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_durationConstraint_EClass, DURATIONCONSTRAINT_EOPERATION_HAS_ONE_OR_TWO_CONSTRAINEDELEMENTS_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createDurationIntervalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_durationInterval_EClass = factory->createEClass_in_EPackage(package, DURATIONINTERVAL_ECLASS);
	
	
	
}

void UmlPackageImpl::createDurationObservationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_durationObservation_EClass = factory->createEClass_in_EPackage(package, DURATIONOBSERVATION_ECLASS);
	m_durationObservation_EAttribute_firstEvent = factory->createEAttribute_in_EContainingClass(m_durationObservation_EClass, DURATIONOBSERVATION_EATTRIBUTE_FIRSTEVENT);
	
	m_durationObservation_EReference_event = factory->createEReference_in_EContainingClass(m_durationObservation_EClass, DURATIONOBSERVATION_EREFERENCE_EVENT);
	
	m_durationObservation_EOperation_first_event_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_durationObservation_EClass, DURATIONOBSERVATION_EOPERATION_FIRST_EVENT_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createElementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_element_EClass = factory->createEClass_in_EPackage(package, ELEMENT_ECLASS);
	
	m_element_EReference_ownedComment = factory->createEReference_in_EContainingClass(m_element_EClass, ELEMENT_EREFERENCE_OWNEDCOMMENT);
	m_element_EReference_ownedElement = factory->createEReference_in_EContainingClass(m_element_EClass, ELEMENT_EREFERENCE_OWNEDELEMENT);
	m_element_EReference_owner = factory->createEReference_in_EContainingClass(m_element_EClass, ELEMENT_EREFERENCE_OWNER);
	
	m_element_EOperation_addKeyword_String = factory->createEOperation_in_EContainingClass(m_element_EClass, ELEMENT_EOPERATION_ADDKEYWORD_STRING);
	m_element_EOperation_allOwnedElements = factory->createEOperation_in_EContainingClass(m_element_EClass, ELEMENT_EOPERATION_ALLOWNEDELEMENTS);
	m_element_EOperation_applyStereotype_Stereotype = factory->createEOperation_in_EContainingClass(m_element_EClass, ELEMENT_EOPERATION_APPLYSTEREOTYPE_STEREOTYPE);
	m_element_EOperation_container = factory->createEOperation_in_EContainingClass(m_element_EClass, ELEMENT_EOPERATION_CONTAINER);
	m_element_EOperation_createEAnnotation_String = factory->createEOperation_in_EContainingClass(m_element_EClass, ELEMENT_EOPERATION_CREATEEANNOTATION_STRING);
	m_element_EOperation_destroy = factory->createEOperation_in_EContainingClass(m_element_EClass, ELEMENT_EOPERATION_DESTROY);
	m_element_EOperation_getApplicableStereotype_String = factory->createEOperation_in_EContainingClass(m_element_EClass, ELEMENT_EOPERATION_GETAPPLICABLESTEREOTYPE_STRING);
	m_element_EOperation_getApplicableStereotypes = factory->createEOperation_in_EContainingClass(m_element_EClass, ELEMENT_EOPERATION_GETAPPLICABLESTEREOTYPES);
	m_element_EOperation_getAppliedStereotype_String = factory->createEOperation_in_EContainingClass(m_element_EClass, ELEMENT_EOPERATION_GETAPPLIEDSTEREOTYPE_STRING);
	m_element_EOperation_getAppliedStereotypes = factory->createEOperation_in_EContainingClass(m_element_EClass, ELEMENT_EOPERATION_GETAPPLIEDSTEREOTYPES);
	m_element_EOperation_getAppliedSubstereotype_Stereotype_String = factory->createEOperation_in_EContainingClass(m_element_EClass, ELEMENT_EOPERATION_GETAPPLIEDSUBSTEREOTYPE_STEREOTYPE_STRING);
	m_element_EOperation_getAppliedSubstereotypes_Stereotype = factory->createEOperation_in_EContainingClass(m_element_EClass, ELEMENT_EOPERATION_GETAPPLIEDSUBSTEREOTYPES_STEREOTYPE);
	m_element_EOperation_getKeywords = factory->createEOperation_in_EContainingClass(m_element_EClass, ELEMENT_EOPERATION_GETKEYWORDS);
	m_element_EOperation_getMetaClass = factory->createEOperation_in_EContainingClass(m_element_EClass, ELEMENT_EOPERATION_GETMETACLASS);
	m_element_EOperation_getModel = factory->createEOperation_in_EContainingClass(m_element_EClass, ELEMENT_EOPERATION_GETMODEL);
	m_element_EOperation_getNearestPackage = factory->createEOperation_in_EContainingClass(m_element_EClass, ELEMENT_EOPERATION_GETNEARESTPACKAGE);
	m_element_EOperation_getRelationships = factory->createEOperation_in_EContainingClass(m_element_EClass, ELEMENT_EOPERATION_GETRELATIONSHIPS);
	m_element_EOperation_getRelationships_EClass = factory->createEOperation_in_EContainingClass(m_element_EClass, ELEMENT_EOPERATION_GETRELATIONSHIPS_ECLASS);
	m_element_EOperation_getRequiredStereotype_String = factory->createEOperation_in_EContainingClass(m_element_EClass, ELEMENT_EOPERATION_GETREQUIREDSTEREOTYPE_STRING);
	m_element_EOperation_getRequiredStereotypes = factory->createEOperation_in_EContainingClass(m_element_EClass, ELEMENT_EOPERATION_GETREQUIREDSTEREOTYPES);
	m_element_EOperation_getSourceDirectedRelationships = factory->createEOperation_in_EContainingClass(m_element_EClass, ELEMENT_EOPERATION_GETSOURCEDIRECTEDRELATIONSHIPS);
	m_element_EOperation_getSourceDirectedRelationships_EClass = factory->createEOperation_in_EContainingClass(m_element_EClass, ELEMENT_EOPERATION_GETSOURCEDIRECTEDRELATIONSHIPS_ECLASS);
	m_element_EOperation_getStereotypeApplication_Stereotype = factory->createEOperation_in_EContainingClass(m_element_EClass, ELEMENT_EOPERATION_GETSTEREOTYPEAPPLICATION_STEREOTYPE);
	m_element_EOperation_getStereotypeApplications = factory->createEOperation_in_EContainingClass(m_element_EClass, ELEMENT_EOPERATION_GETSTEREOTYPEAPPLICATIONS);
	m_element_EOperation_getTargetDirectedRelationships = factory->createEOperation_in_EContainingClass(m_element_EClass, ELEMENT_EOPERATION_GETTARGETDIRECTEDRELATIONSHIPS);
	m_element_EOperation_getTargetDirectedRelationships_EClass = factory->createEOperation_in_EContainingClass(m_element_EClass, ELEMENT_EOPERATION_GETTARGETDIRECTEDRELATIONSHIPS_ECLASS);
	m_element_EOperation_getValue_Stereotype_String = factory->createEOperation_in_EContainingClass(m_element_EClass, ELEMENT_EOPERATION_GETVALUE_STEREOTYPE_STRING);
	m_element_EOperation_hasKeyword_String = factory->createEOperation_in_EContainingClass(m_element_EClass, ELEMENT_EOPERATION_HASKEYWORD_STRING);
	m_element_EOperation_hasValue_Stereotype_String = factory->createEOperation_in_EContainingClass(m_element_EClass, ELEMENT_EOPERATION_HASVALUE_STEREOTYPE_STRING);
	m_element_EOperation_has_owner_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_element_EClass, ELEMENT_EOPERATION_HAS_OWNER_EDIAGNOSTICCHAIN_EMAP);
	m_element_EOperation_isStereotypeApplicable_Stereotype = factory->createEOperation_in_EContainingClass(m_element_EClass, ELEMENT_EOPERATION_ISSTEREOTYPEAPPLICABLE_STEREOTYPE);
	m_element_EOperation_isStereotypeApplied_Stereotype = factory->createEOperation_in_EContainingClass(m_element_EClass, ELEMENT_EOPERATION_ISSTEREOTYPEAPPLIED_STEREOTYPE);
	m_element_EOperation_isStereotypeRequired_Stereotype = factory->createEOperation_in_EContainingClass(m_element_EClass, ELEMENT_EOPERATION_ISSTEREOTYPEREQUIRED_STEREOTYPE);
	m_element_EOperation_mustBeOwned = factory->createEOperation_in_EContainingClass(m_element_EClass, ELEMENT_EOPERATION_MUSTBEOWNED);
	m_element_EOperation_not_own_self_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_element_EClass, ELEMENT_EOPERATION_NOT_OWN_SELF_EDIAGNOSTICCHAIN_EMAP);
	m_element_EOperation_removeKeyword_String = factory->createEOperation_in_EContainingClass(m_element_EClass, ELEMENT_EOPERATION_REMOVEKEYWORD_STRING);
	m_element_EOperation_setValue_Stereotype_EJavaObject = factory->createEOperation_in_EContainingClass(m_element_EClass, ELEMENT_EOPERATION_SETVALUE_STEREOTYPE_EJAVAOBJECT);
	m_element_EOperation_unapplyStereotype_Stereotype = factory->createEOperation_in_EContainingClass(m_element_EClass, ELEMENT_EOPERATION_UNAPPLYSTEREOTYPE_STEREOTYPE);
	
}

void UmlPackageImpl::createElementImportContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_elementImport_EClass = factory->createEClass_in_EPackage(package, ELEMENTIMPORT_ECLASS);
	m_elementImport_EAttribute_alias = factory->createEAttribute_in_EContainingClass(m_elementImport_EClass, ELEMENTIMPORT_EATTRIBUTE_ALIAS);
	m_elementImport_EAttribute_visibility = factory->createEAttribute_in_EContainingClass(m_elementImport_EClass, ELEMENTIMPORT_EATTRIBUTE_VISIBILITY);
	
	m_elementImport_EReference_importedElement = factory->createEReference_in_EContainingClass(m_elementImport_EClass, ELEMENTIMPORT_EREFERENCE_IMPORTEDELEMENT);
	m_elementImport_EReference_importingNamespace = factory->createEReference_in_EContainingClass(m_elementImport_EClass, ELEMENTIMPORT_EREFERENCE_IMPORTINGNAMESPACE);
	
	m_elementImport_EOperation_getName = factory->createEOperation_in_EContainingClass(m_elementImport_EClass, ELEMENTIMPORT_EOPERATION_GETNAME);
	m_elementImport_EOperation_imported_element_is_public_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_elementImport_EClass, ELEMENTIMPORT_EOPERATION_IMPORTED_ELEMENT_IS_PUBLIC_EDIAGNOSTICCHAIN_EMAP);
	m_elementImport_EOperation_visibility_public_or_private_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_elementImport_EClass, ELEMENTIMPORT_EOPERATION_VISIBILITY_PUBLIC_OR_PRIVATE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createEncapsulatedClassifierContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_encapsulatedClassifier_EClass = factory->createEClass_in_EPackage(package, ENCAPSULATEDCLASSIFIER_ECLASS);
	
	m_encapsulatedClassifier_EReference_ownedPort = factory->createEReference_in_EContainingClass(m_encapsulatedClassifier_EClass, ENCAPSULATEDCLASSIFIER_EREFERENCE_OWNEDPORT);
	
	m_encapsulatedClassifier_EOperation_getOwnedPorts = factory->createEOperation_in_EContainingClass(m_encapsulatedClassifier_EClass, ENCAPSULATEDCLASSIFIER_EOPERATION_GETOWNEDPORTS);
	
}

void UmlPackageImpl::createEnumerationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_enumeration_EClass = factory->createEClass_in_EPackage(package, ENUMERATION_ECLASS);
	
	m_enumeration_EReference_ownedLiteral = factory->createEReference_in_EContainingClass(m_enumeration_EClass, ENUMERATION_EREFERENCE_OWNEDLITERAL);
	
	m_enumeration_EOperation_immutable_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_enumeration_EClass, ENUMERATION_EOPERATION_IMMUTABLE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createEnumerationLiteralContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_enumerationLiteral_EClass = factory->createEClass_in_EPackage(package, ENUMERATIONLITERAL_ECLASS);
	
	m_enumerationLiteral_EReference_enumeration = factory->createEReference_in_EContainingClass(m_enumerationLiteral_EClass, ENUMERATIONLITERAL_EREFERENCE_ENUMERATION);
	
	m_enumerationLiteral_EOperation_getClassifier = factory->createEOperation_in_EContainingClass(m_enumerationLiteral_EClass, ENUMERATIONLITERAL_EOPERATION_GETCLASSIFIER);
	m_enumerationLiteral_EOperation_getClassifiers = factory->createEOperation_in_EContainingClass(m_enumerationLiteral_EClass, ENUMERATIONLITERAL_EOPERATION_GETCLASSIFIERS);
	
}

void UmlPackageImpl::createEventContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_event_EClass = factory->createEClass_in_EPackage(package, EVENT_ECLASS);
	
	
	
}

void UmlPackageImpl::createExceptionHandlerContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_exceptionHandler_EClass = factory->createEClass_in_EPackage(package, EXCEPTIONHANDLER_ECLASS);
	
	m_exceptionHandler_EReference_exceptionInput = factory->createEReference_in_EContainingClass(m_exceptionHandler_EClass, EXCEPTIONHANDLER_EREFERENCE_EXCEPTIONINPUT);
	m_exceptionHandler_EReference_exceptionType = factory->createEReference_in_EContainingClass(m_exceptionHandler_EClass, EXCEPTIONHANDLER_EREFERENCE_EXCEPTIONTYPE);
	m_exceptionHandler_EReference_handlerBody = factory->createEReference_in_EContainingClass(m_exceptionHandler_EClass, EXCEPTIONHANDLER_EREFERENCE_HANDLERBODY);
	m_exceptionHandler_EReference_protectedNode = factory->createEReference_in_EContainingClass(m_exceptionHandler_EClass, EXCEPTIONHANDLER_EREFERENCE_PROTECTEDNODE);
	
	m_exceptionHandler_EOperation_edge_source_target_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_exceptionHandler_EClass, EXCEPTIONHANDLER_EOPERATION_EDGE_SOURCE_TARGET_EDIAGNOSTICCHAIN_EMAP);
	m_exceptionHandler_EOperation_exception_input_type_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_exceptionHandler_EClass, EXCEPTIONHANDLER_EOPERATION_EXCEPTION_INPUT_TYPE_EDIAGNOSTICCHAIN_EMAP);
	m_exceptionHandler_EOperation_handler_body_edges_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_exceptionHandler_EClass, EXCEPTIONHANDLER_EOPERATION_HANDLER_BODY_EDGES_EDIAGNOSTICCHAIN_EMAP);
	m_exceptionHandler_EOperation_handler_body_owner_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_exceptionHandler_EClass, EXCEPTIONHANDLER_EOPERATION_HANDLER_BODY_OWNER_EDIAGNOSTICCHAIN_EMAP);
	m_exceptionHandler_EOperation_one_input_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_exceptionHandler_EClass, EXCEPTIONHANDLER_EOPERATION_ONE_INPUT_EDIAGNOSTICCHAIN_EMAP);
	m_exceptionHandler_EOperation_output_pins_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_exceptionHandler_EClass, EXCEPTIONHANDLER_EOPERATION_OUTPUT_PINS_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createExecutableNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_executableNode_EClass = factory->createEClass_in_EPackage(package, EXECUTABLENODE_ECLASS);
	
	m_executableNode_EReference_handler = factory->createEReference_in_EContainingClass(m_executableNode_EClass, EXECUTABLENODE_EREFERENCE_HANDLER);
	
	
}

void UmlPackageImpl::createExecutionEnvironmentContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_executionEnvironment_EClass = factory->createEClass_in_EPackage(package, EXECUTIONENVIRONMENT_ECLASS);
	
	
	
}

void UmlPackageImpl::createExecutionOccurrenceSpecificationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_executionOccurrenceSpecification_EClass = factory->createEClass_in_EPackage(package, EXECUTIONOCCURRENCESPECIFICATION_ECLASS);
	
	m_executionOccurrenceSpecification_EReference_execution = factory->createEReference_in_EContainingClass(m_executionOccurrenceSpecification_EClass, EXECUTIONOCCURRENCESPECIFICATION_EREFERENCE_EXECUTION);
	
	
}

void UmlPackageImpl::createExecutionSpecificationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_executionSpecification_EClass = factory->createEClass_in_EPackage(package, EXECUTIONSPECIFICATION_ECLASS);
	
	m_executionSpecification_EReference_finish = factory->createEReference_in_EContainingClass(m_executionSpecification_EClass, EXECUTIONSPECIFICATION_EREFERENCE_FINISH);
	m_executionSpecification_EReference_start = factory->createEReference_in_EContainingClass(m_executionSpecification_EClass, EXECUTIONSPECIFICATION_EREFERENCE_START);
	
	m_executionSpecification_EOperation_same_lifeline_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_executionSpecification_EClass, EXECUTIONSPECIFICATION_EOPERATION_SAME_LIFELINE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createExpansionNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_expansionNode_EClass = factory->createEClass_in_EPackage(package, EXPANSIONNODE_ECLASS);
	
	m_expansionNode_EReference_regionAsInput = factory->createEReference_in_EContainingClass(m_expansionNode_EClass, EXPANSIONNODE_EREFERENCE_REGIONASINPUT);
	m_expansionNode_EReference_regionAsOutput = factory->createEReference_in_EContainingClass(m_expansionNode_EClass, EXPANSIONNODE_EREFERENCE_REGIONASOUTPUT);
	
	m_expansionNode_EOperation_region_as_input_or_output_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_expansionNode_EClass, EXPANSIONNODE_EOPERATION_REGION_AS_INPUT_OR_OUTPUT_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createExpansionRegionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_expansionRegion_EClass = factory->createEClass_in_EPackage(package, EXPANSIONREGION_ECLASS);
	m_expansionRegion_EAttribute_mode = factory->createEAttribute_in_EContainingClass(m_expansionRegion_EClass, EXPANSIONREGION_EATTRIBUTE_MODE);
	
	m_expansionRegion_EReference_inputElement = factory->createEReference_in_EContainingClass(m_expansionRegion_EClass, EXPANSIONREGION_EREFERENCE_INPUTELEMENT);
	m_expansionRegion_EReference_outputElement = factory->createEReference_in_EContainingClass(m_expansionRegion_EClass, EXPANSIONREGION_EREFERENCE_OUTPUTELEMENT);
	
	
}

void UmlPackageImpl::createExpressionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_expression_EClass = factory->createEClass_in_EPackage(package, EXPRESSION_ECLASS);
	m_expression_EAttribute_symbol = factory->createEAttribute_in_EContainingClass(m_expression_EClass, EXPRESSION_EATTRIBUTE_SYMBOL);
	
	m_expression_EReference_operand = factory->createEReference_in_EContainingClass(m_expression_EClass, EXPRESSION_EREFERENCE_OPERAND);
	
	
}

void UmlPackageImpl::createExtendContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_extend_EClass = factory->createEClass_in_EPackage(package, EXTEND_ECLASS);
	
	m_extend_EReference_condition = factory->createEReference_in_EContainingClass(m_extend_EClass, EXTEND_EREFERENCE_CONDITION);
	m_extend_EReference_extendedCase = factory->createEReference_in_EContainingClass(m_extend_EClass, EXTEND_EREFERENCE_EXTENDEDCASE);
	m_extend_EReference_extension = factory->createEReference_in_EContainingClass(m_extend_EClass, EXTEND_EREFERENCE_EXTENSION);
	m_extend_EReference_extensionLocation = factory->createEReference_in_EContainingClass(m_extend_EClass, EXTEND_EREFERENCE_EXTENSIONLOCATION);
	
	m_extend_EOperation_extension_points_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_extend_EClass, EXTEND_EOPERATION_EXTENSION_POINTS_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createExtensionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_extension_EClass = factory->createEClass_in_EPackage(package, EXTENSION_ECLASS);
	m_extension_EAttribute_isRequired = factory->createEAttribute_in_EContainingClass(m_extension_EClass, EXTENSION_EATTRIBUTE_ISREQUIRED);
	
	m_extension_EReference_metaclass = factory->createEReference_in_EContainingClass(m_extension_EClass, EXTENSION_EREFERENCE_METACLASS);
	
	m_extension_EOperation_getMetaclass = factory->createEOperation_in_EContainingClass(m_extension_EClass, EXTENSION_EOPERATION_GETMETACLASS);
	m_extension_EOperation_getStereotype = factory->createEOperation_in_EContainingClass(m_extension_EClass, EXTENSION_EOPERATION_GETSTEREOTYPE);
	m_extension_EOperation_getStereotypeEnd = factory->createEOperation_in_EContainingClass(m_extension_EClass, EXTENSION_EOPERATION_GETSTEREOTYPEEND);
	m_extension_EOperation_isRequired = factory->createEOperation_in_EContainingClass(m_extension_EClass, EXTENSION_EOPERATION_ISREQUIRED);
	m_extension_EOperation_is_binary_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_extension_EClass, EXTENSION_EOPERATION_IS_BINARY_EDIAGNOSTICCHAIN_EMAP);
	m_extension_EOperation_metaclassEnd = factory->createEOperation_in_EContainingClass(m_extension_EClass, EXTENSION_EOPERATION_METACLASSEND);
	m_extension_EOperation_non_owned_end_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_extension_EClass, EXTENSION_EOPERATION_NON_OWNED_END_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createExtensionEndContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_extensionEnd_EClass = factory->createEClass_in_EPackage(package, EXTENSIONEND_ECLASS);
	
	
	m_extensionEnd_EOperation_aggregation_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_extensionEnd_EClass, EXTENSIONEND_EOPERATION_AGGREGATION_EDIAGNOSTICCHAIN_EMAP);
	m_extensionEnd_EOperation_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_extensionEnd_EClass, EXTENSIONEND_EOPERATION_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createExtensionPointContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_extensionPoint_EClass = factory->createEClass_in_EPackage(package, EXTENSIONPOINT_ECLASS);
	
	m_extensionPoint_EReference_useCase = factory->createEReference_in_EContainingClass(m_extensionPoint_EClass, EXTENSIONPOINT_EREFERENCE_USECASE);
	
	m_extensionPoint_EOperation_must_have_name_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_extensionPoint_EClass, EXTENSIONPOINT_EOPERATION_MUST_HAVE_NAME_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createFactoryContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_factory_EClass = factory->createEClass_in_EPackage(package, FACTORY_ECLASS);
	
	
	m_factory_EOperation_create_Class = factory->createEOperation_in_EContainingClass(m_factory_EClass, FACTORY_EOPERATION_CREATE_CLASS);
	
}

void UmlPackageImpl::createFeatureContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_feature_EClass = factory->createEClass_in_EPackage(package, FEATURE_ECLASS);
	m_feature_EAttribute_isStatic = factory->createEAttribute_in_EContainingClass(m_feature_EClass, FEATURE_EATTRIBUTE_ISSTATIC);
	
	m_feature_EReference_featuringClassifier = factory->createEReference_in_EContainingClass(m_feature_EClass, FEATURE_EREFERENCE_FEATURINGCLASSIFIER);
	
	
}

void UmlPackageImpl::createFinalNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_finalNode_EClass = factory->createEClass_in_EPackage(package, FINALNODE_ECLASS);
	
	
	m_finalNode_EOperation_no_outgoing_edges_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_finalNode_EClass, FINALNODE_EOPERATION_NO_OUTGOING_EDGES_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createFinalStateContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_finalState_EClass = factory->createEClass_in_EPackage(package, FINALSTATE_ECLASS);
	
	
	m_finalState_EOperation_cannot_reference_submachine_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_finalState_EClass, FINALSTATE_EOPERATION_CANNOT_REFERENCE_SUBMACHINE_EDIAGNOSTICCHAIN_EMAP);
	m_finalState_EOperation_no_entry_behavior_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_finalState_EClass, FINALSTATE_EOPERATION_NO_ENTRY_BEHAVIOR_EDIAGNOSTICCHAIN_EMAP);
	m_finalState_EOperation_no_exit_behavior_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_finalState_EClass, FINALSTATE_EOPERATION_NO_EXIT_BEHAVIOR_EDIAGNOSTICCHAIN_EMAP);
	m_finalState_EOperation_no_outgoing_transitions_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_finalState_EClass, FINALSTATE_EOPERATION_NO_OUTGOING_TRANSITIONS_EDIAGNOSTICCHAIN_EMAP);
	m_finalState_EOperation_no_regions_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_finalState_EClass, FINALSTATE_EOPERATION_NO_REGIONS_EDIAGNOSTICCHAIN_EMAP);
	m_finalState_EOperation_no_state_behavior_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_finalState_EClass, FINALSTATE_EOPERATION_NO_STATE_BEHAVIOR_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createFlowFinalNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_flowFinalNode_EClass = factory->createEClass_in_EPackage(package, FLOWFINALNODE_ECLASS);
	
	
	
}

void UmlPackageImpl::createForkNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_forkNode_EClass = factory->createEClass_in_EPackage(package, FORKNODE_ECLASS);
	
	
	m_forkNode_EOperation_edges_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_forkNode_EClass, FORKNODE_EOPERATION_EDGES_EDIAGNOSTICCHAIN_EMAP);
	m_forkNode_EOperation_one_incoming_edge_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_forkNode_EClass, FORKNODE_EOPERATION_ONE_INCOMING_EDGE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createFunctionBehaviorContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_functionBehavior_EClass = factory->createEClass_in_EPackage(package, FUNCTIONBEHAVIOR_ECLASS);
	
	
	m_functionBehavior_EOperation_hasAllDataTypeAttributes_DataType = factory->createEOperation_in_EContainingClass(m_functionBehavior_EClass, FUNCTIONBEHAVIOR_EOPERATION_HASALLDATATYPEATTRIBUTES_DATATYPE);
	m_functionBehavior_EOperation_one_output_parameter_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_functionBehavior_EClass, FUNCTIONBEHAVIOR_EOPERATION_ONE_OUTPUT_PARAMETER_EDIAGNOSTICCHAIN_EMAP);
	m_functionBehavior_EOperation_types_of_parameters_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_functionBehavior_EClass, FUNCTIONBEHAVIOR_EOPERATION_TYPES_OF_PARAMETERS_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createGateContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_gate_EClass = factory->createEClass_in_EPackage(package, GATE_ECLASS);
	
	
	m_gate_EOperation_actual_gate_distinguishable_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_gate_EClass, GATE_EOPERATION_ACTUAL_GATE_DISTINGUISHABLE_EDIAGNOSTICCHAIN_EMAP);
	m_gate_EOperation_actual_gate_matched_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_gate_EClass, GATE_EOPERATION_ACTUAL_GATE_MATCHED_EDIAGNOSTICCHAIN_EMAP);
	m_gate_EOperation_formal_gate_distinguishable_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_gate_EClass, GATE_EOPERATION_FORMAL_GATE_DISTINGUISHABLE_EDIAGNOSTICCHAIN_EMAP);
	m_gate_EOperation_getName = factory->createEOperation_in_EContainingClass(m_gate_EClass, GATE_EOPERATION_GETNAME);
	m_gate_EOperation_getOperand = factory->createEOperation_in_EContainingClass(m_gate_EClass, GATE_EOPERATION_GETOPERAND);
	m_gate_EOperation_inside_cf_gate_distinguishable_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_gate_EClass, GATE_EOPERATION_INSIDE_CF_GATE_DISTINGUISHABLE_EDIAGNOSTICCHAIN_EMAP);
	m_gate_EOperation_inside_cf_matched_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_gate_EClass, GATE_EOPERATION_INSIDE_CF_MATCHED_EDIAGNOSTICCHAIN_EMAP);
	m_gate_EOperation_isActual = factory->createEOperation_in_EContainingClass(m_gate_EClass, GATE_EOPERATION_ISACTUAL);
	m_gate_EOperation_isFormal = factory->createEOperation_in_EContainingClass(m_gate_EClass, GATE_EOPERATION_ISFORMAL);
	m_gate_EOperation_isInsideCF = factory->createEOperation_in_EContainingClass(m_gate_EClass, GATE_EOPERATION_ISINSIDECF);
	m_gate_EOperation_isOutsideCF = factory->createEOperation_in_EContainingClass(m_gate_EClass, GATE_EOPERATION_ISOUTSIDECF);
	m_gate_EOperation_matches_Gate = factory->createEOperation_in_EContainingClass(m_gate_EClass, GATE_EOPERATION_MATCHES_GATE);
	m_gate_EOperation_outside_cf_gate_distinguishable_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_gate_EClass, GATE_EOPERATION_OUTSIDE_CF_GATE_DISTINGUISHABLE_EDIAGNOSTICCHAIN_EMAP);
	m_gate_EOperation_outside_cf_matched_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_gate_EClass, GATE_EOPERATION_OUTSIDE_CF_MATCHED_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createGeneralOrderingContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_generalOrdering_EClass = factory->createEClass_in_EPackage(package, GENERALORDERING_ECLASS);
	
	m_generalOrdering_EReference_after = factory->createEReference_in_EContainingClass(m_generalOrdering_EClass, GENERALORDERING_EREFERENCE_AFTER);
	m_generalOrdering_EReference_before = factory->createEReference_in_EContainingClass(m_generalOrdering_EClass, GENERALORDERING_EREFERENCE_BEFORE);
	
	m_generalOrdering_EOperation_irreflexive_transitive_closure_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_generalOrdering_EClass, GENERALORDERING_EOPERATION_IRREFLEXIVE_TRANSITIVE_CLOSURE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createGeneralizationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_generalization_EClass = factory->createEClass_in_EPackage(package, GENERALIZATION_ECLASS);
	m_generalization_EAttribute_isSubstitutable = factory->createEAttribute_in_EContainingClass(m_generalization_EClass, GENERALIZATION_EATTRIBUTE_ISSUBSTITUTABLE);
	
	m_generalization_EReference_general = factory->createEReference_in_EContainingClass(m_generalization_EClass, GENERALIZATION_EREFERENCE_GENERAL);
	m_generalization_EReference_generalizationSet = factory->createEReference_in_EContainingClass(m_generalization_EClass, GENERALIZATION_EREFERENCE_GENERALIZATIONSET);
	m_generalization_EReference_specific = factory->createEReference_in_EContainingClass(m_generalization_EClass, GENERALIZATION_EREFERENCE_SPECIFIC);
	
	
}

void UmlPackageImpl::createGeneralizationSetContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_generalizationSet_EClass = factory->createEClass_in_EPackage(package, GENERALIZATIONSET_ECLASS);
	m_generalizationSet_EAttribute_isCovering = factory->createEAttribute_in_EContainingClass(m_generalizationSet_EClass, GENERALIZATIONSET_EATTRIBUTE_ISCOVERING);
	m_generalizationSet_EAttribute_isDisjoint = factory->createEAttribute_in_EContainingClass(m_generalizationSet_EClass, GENERALIZATIONSET_EATTRIBUTE_ISDISJOINT);
	
	m_generalizationSet_EReference_generalization = factory->createEReference_in_EContainingClass(m_generalizationSet_EClass, GENERALIZATIONSET_EREFERENCE_GENERALIZATION);
	m_generalizationSet_EReference_powertype = factory->createEReference_in_EContainingClass(m_generalizationSet_EClass, GENERALIZATIONSET_EREFERENCE_POWERTYPE);
	
	m_generalizationSet_EOperation_generalization_same_classifier_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_generalizationSet_EClass, GENERALIZATIONSET_EOPERATION_GENERALIZATION_SAME_CLASSIFIER_EDIAGNOSTICCHAIN_EMAP);
	m_generalizationSet_EOperation_maps_to_generalization_set_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_generalizationSet_EClass, GENERALIZATIONSET_EOPERATION_MAPS_TO_GENERALIZATION_SET_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createImageContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_image_EClass = factory->createEClass_in_EPackage(package, IMAGE_ECLASS);
	m_image_EAttribute_content = factory->createEAttribute_in_EContainingClass(m_image_EClass, IMAGE_EATTRIBUTE_CONTENT);
	m_image_EAttribute_format = factory->createEAttribute_in_EContainingClass(m_image_EClass, IMAGE_EATTRIBUTE_FORMAT);
	m_image_EAttribute_location = factory->createEAttribute_in_EContainingClass(m_image_EClass, IMAGE_EATTRIBUTE_LOCATION);
	
	
	
}

void UmlPackageImpl::createIncludeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_include_EClass = factory->createEClass_in_EPackage(package, INCLUDE_ECLASS);
	
	m_include_EReference_addition = factory->createEReference_in_EContainingClass(m_include_EClass, INCLUDE_EREFERENCE_ADDITION);
	m_include_EReference_includingCase = factory->createEReference_in_EContainingClass(m_include_EClass, INCLUDE_EREFERENCE_INCLUDINGCASE);
	
	
}

void UmlPackageImpl::createInformationFlowContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_informationFlow_EClass = factory->createEClass_in_EPackage(package, INFORMATIONFLOW_ECLASS);
	
	m_informationFlow_EReference_conveyed = factory->createEReference_in_EContainingClass(m_informationFlow_EClass, INFORMATIONFLOW_EREFERENCE_CONVEYED);
	m_informationFlow_EReference_informationSource = factory->createEReference_in_EContainingClass(m_informationFlow_EClass, INFORMATIONFLOW_EREFERENCE_INFORMATIONSOURCE);
	m_informationFlow_EReference_informationTarget = factory->createEReference_in_EContainingClass(m_informationFlow_EClass, INFORMATIONFLOW_EREFERENCE_INFORMATIONTARGET);
	m_informationFlow_EReference_realization = factory->createEReference_in_EContainingClass(m_informationFlow_EClass, INFORMATIONFLOW_EREFERENCE_REALIZATION);
	m_informationFlow_EReference_realizingActivityEdge = factory->createEReference_in_EContainingClass(m_informationFlow_EClass, INFORMATIONFLOW_EREFERENCE_REALIZINGACTIVITYEDGE);
	m_informationFlow_EReference_realizingConnector = factory->createEReference_in_EContainingClass(m_informationFlow_EClass, INFORMATIONFLOW_EREFERENCE_REALIZINGCONNECTOR);
	m_informationFlow_EReference_realizingMessage = factory->createEReference_in_EContainingClass(m_informationFlow_EClass, INFORMATIONFLOW_EREFERENCE_REALIZINGMESSAGE);
	
	m_informationFlow_EOperation_convey_classifiers_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_informationFlow_EClass, INFORMATIONFLOW_EOPERATION_CONVEY_CLASSIFIERS_EDIAGNOSTICCHAIN_EMAP);
	m_informationFlow_EOperation_must_conform_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_informationFlow_EClass, INFORMATIONFLOW_EOPERATION_MUST_CONFORM_EDIAGNOSTICCHAIN_EMAP);
	m_informationFlow_EOperation_sources_and_targets_kind_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_informationFlow_EClass, INFORMATIONFLOW_EOPERATION_SOURCES_AND_TARGETS_KIND_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createInformationItemContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_informationItem_EClass = factory->createEClass_in_EPackage(package, INFORMATIONITEM_ECLASS);
	
	m_informationItem_EReference_represented = factory->createEReference_in_EContainingClass(m_informationItem_EClass, INFORMATIONITEM_EREFERENCE_REPRESENTED);
	
	m_informationItem_EOperation_has_no_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_informationItem_EClass, INFORMATIONITEM_EOPERATION_HAS_NO_EDIAGNOSTICCHAIN_EMAP);
	m_informationItem_EOperation_not_instantiable_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_informationItem_EClass, INFORMATIONITEM_EOPERATION_NOT_INSTANTIABLE_EDIAGNOSTICCHAIN_EMAP);
	m_informationItem_EOperation_sources_and_targets_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_informationItem_EClass, INFORMATIONITEM_EOPERATION_SOURCES_AND_TARGETS_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createInitialNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_initialNode_EClass = factory->createEClass_in_EPackage(package, INITIALNODE_ECLASS);
	
	
	m_initialNode_EOperation_control_edges_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_initialNode_EClass, INITIALNODE_EOPERATION_CONTROL_EDGES_EDIAGNOSTICCHAIN_EMAP);
	m_initialNode_EOperation_no_incoming_edges_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_initialNode_EClass, INITIALNODE_EOPERATION_NO_INCOMING_EDGES_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createInputPinContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_inputPin_EClass = factory->createEClass_in_EPackage(package, INPUTPIN_ECLASS);
	
	m_inputPin_EReference_action = factory->createEReference_in_EContainingClass(m_inputPin_EClass, INPUTPIN_EREFERENCE_ACTION);
	m_inputPin_EReference_callOperationAction = factory->createEReference_in_EContainingClass(m_inputPin_EClass, INPUTPIN_EREFERENCE_CALLOPERATIONACTION);
	m_inputPin_EReference_invocationAction = factory->createEReference_in_EContainingClass(m_inputPin_EClass, INPUTPIN_EREFERENCE_INVOCATIONACTION);
	m_inputPin_EReference_structuralFeatureAction = factory->createEReference_in_EContainingClass(m_inputPin_EClass, INPUTPIN_EREFERENCE_STRUCTURALFEATUREACTION);
	
	m_inputPin_EOperation_outgoing_edges_structured_only_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_inputPin_EClass, INPUTPIN_EOPERATION_OUTGOING_EDGES_STRUCTURED_ONLY_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createInstanceSpecificationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_instanceSpecification_EClass = factory->createEClass_in_EPackage(package, INSTANCESPECIFICATION_ECLASS);
	
	m_instanceSpecification_EReference_classifier = factory->createEReference_in_EContainingClass(m_instanceSpecification_EClass, INSTANCESPECIFICATION_EREFERENCE_CLASSIFIER);
	m_instanceSpecification_EReference_slot = factory->createEReference_in_EContainingClass(m_instanceSpecification_EClass, INSTANCESPECIFICATION_EREFERENCE_SLOT);
	m_instanceSpecification_EReference_specification = factory->createEReference_in_EContainingClass(m_instanceSpecification_EClass, INSTANCESPECIFICATION_EREFERENCE_SPECIFICATION);
	
	m_instanceSpecification_EOperation_defining_feature_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_instanceSpecification_EClass, INSTANCESPECIFICATION_EOPERATION_DEFINING_FEATURE_EDIAGNOSTICCHAIN_EMAP);
	m_instanceSpecification_EOperation_deployment_artifact_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_instanceSpecification_EClass, INSTANCESPECIFICATION_EOPERATION_DEPLOYMENT_ARTIFACT_EDIAGNOSTICCHAIN_EMAP);
	m_instanceSpecification_EOperation_deployment_target_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_instanceSpecification_EClass, INSTANCESPECIFICATION_EOPERATION_DEPLOYMENT_TARGET_EDIAGNOSTICCHAIN_EMAP);
	m_instanceSpecification_EOperation_structural_feature_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_instanceSpecification_EClass, INSTANCESPECIFICATION_EOPERATION_STRUCTURAL_FEATURE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createInstanceValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_instanceValue_EClass = factory->createEClass_in_EPackage(package, INSTANCEVALUE_ECLASS);
	
	m_instanceValue_EReference_instance = factory->createEReference_in_EContainingClass(m_instanceValue_EClass, INSTANCEVALUE_EREFERENCE_INSTANCE);
	
	
}

void UmlPackageImpl::createInteractionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_interaction_EClass = factory->createEClass_in_EPackage(package, INTERACTION_ECLASS);
	
	m_interaction_EReference_action = factory->createEReference_in_EContainingClass(m_interaction_EClass, INTERACTION_EREFERENCE_ACTION);
	m_interaction_EReference_formalGate = factory->createEReference_in_EContainingClass(m_interaction_EClass, INTERACTION_EREFERENCE_FORMALGATE);
	m_interaction_EReference_fragment = factory->createEReference_in_EContainingClass(m_interaction_EClass, INTERACTION_EREFERENCE_FRAGMENT);
	m_interaction_EReference_lifeline = factory->createEReference_in_EContainingClass(m_interaction_EClass, INTERACTION_EREFERENCE_LIFELINE);
	m_interaction_EReference_message = factory->createEReference_in_EContainingClass(m_interaction_EClass, INTERACTION_EREFERENCE_MESSAGE);
	
	m_interaction_EOperation_not_contained_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_interaction_EClass, INTERACTION_EOPERATION_NOT_CONTAINED_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createInteractionConstraintContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_interactionConstraint_EClass = factory->createEClass_in_EPackage(package, INTERACTIONCONSTRAINT_ECLASS);
	
	m_interactionConstraint_EReference_maxint = factory->createEReference_in_EContainingClass(m_interactionConstraint_EClass, INTERACTIONCONSTRAINT_EREFERENCE_MAXINT);
	m_interactionConstraint_EReference_minint = factory->createEReference_in_EContainingClass(m_interactionConstraint_EClass, INTERACTIONCONSTRAINT_EREFERENCE_MININT);
	
	m_interactionConstraint_EOperation_dynamic_variables_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_interactionConstraint_EClass, INTERACTIONCONSTRAINT_EOPERATION_DYNAMIC_VARIABLES_EDIAGNOSTICCHAIN_EMAP);
	m_interactionConstraint_EOperation_global_data_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_interactionConstraint_EClass, INTERACTIONCONSTRAINT_EOPERATION_GLOBAL_DATA_EDIAGNOSTICCHAIN_EMAP);
	m_interactionConstraint_EOperation_maxint_greater_equal_minint_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_interactionConstraint_EClass, INTERACTIONCONSTRAINT_EOPERATION_MAXINT_GREATER_EQUAL_MININT_EDIAGNOSTICCHAIN_EMAP);
	m_interactionConstraint_EOperation_maxint_positive_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_interactionConstraint_EClass, INTERACTIONCONSTRAINT_EOPERATION_MAXINT_POSITIVE_EDIAGNOSTICCHAIN_EMAP);
	m_interactionConstraint_EOperation_minint_maxint_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_interactionConstraint_EClass, INTERACTIONCONSTRAINT_EOPERATION_MININT_MAXINT_EDIAGNOSTICCHAIN_EMAP);
	m_interactionConstraint_EOperation_minint_non_negative_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_interactionConstraint_EClass, INTERACTIONCONSTRAINT_EOPERATION_MININT_NON_NEGATIVE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createInteractionFragmentContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_interactionFragment_EClass = factory->createEClass_in_EPackage(package, INTERACTIONFRAGMENT_ECLASS);
	
	m_interactionFragment_EReference_covered = factory->createEReference_in_EContainingClass(m_interactionFragment_EClass, INTERACTIONFRAGMENT_EREFERENCE_COVERED);
	m_interactionFragment_EReference_enclosingInteraction = factory->createEReference_in_EContainingClass(m_interactionFragment_EClass, INTERACTIONFRAGMENT_EREFERENCE_ENCLOSINGINTERACTION);
	m_interactionFragment_EReference_enclosingOperand = factory->createEReference_in_EContainingClass(m_interactionFragment_EClass, INTERACTIONFRAGMENT_EREFERENCE_ENCLOSINGOPERAND);
	m_interactionFragment_EReference_generalOrdering = factory->createEReference_in_EContainingClass(m_interactionFragment_EClass, INTERACTIONFRAGMENT_EREFERENCE_GENERALORDERING);
	
	
}

void UmlPackageImpl::createInteractionOperandContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_interactionOperand_EClass = factory->createEClass_in_EPackage(package, INTERACTIONOPERAND_ECLASS);
	
	m_interactionOperand_EReference_fragment = factory->createEReference_in_EContainingClass(m_interactionOperand_EClass, INTERACTIONOPERAND_EREFERENCE_FRAGMENT);
	m_interactionOperand_EReference_guard = factory->createEReference_in_EContainingClass(m_interactionOperand_EClass, INTERACTIONOPERAND_EREFERENCE_GUARD);
	
	m_interactionOperand_EOperation_guard_contain_references_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_interactionOperand_EClass, INTERACTIONOPERAND_EOPERATION_GUARD_CONTAIN_REFERENCES_EDIAGNOSTICCHAIN_EMAP);
	m_interactionOperand_EOperation_guard_directly_prior_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_interactionOperand_EClass, INTERACTIONOPERAND_EOPERATION_GUARD_DIRECTLY_PRIOR_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createInteractionUseContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_interactionUse_EClass = factory->createEClass_in_EPackage(package, INTERACTIONUSE_ECLASS);
	
	m_interactionUse_EReference_actualGate = factory->createEReference_in_EContainingClass(m_interactionUse_EClass, INTERACTIONUSE_EREFERENCE_ACTUALGATE);
	m_interactionUse_EReference_argument = factory->createEReference_in_EContainingClass(m_interactionUse_EClass, INTERACTIONUSE_EREFERENCE_ARGUMENT);
	m_interactionUse_EReference_refersTo = factory->createEReference_in_EContainingClass(m_interactionUse_EClass, INTERACTIONUSE_EREFERENCE_REFERSTO);
	m_interactionUse_EReference_returnValue = factory->createEReference_in_EContainingClass(m_interactionUse_EClass, INTERACTIONUSE_EREFERENCE_RETURNVALUE);
	m_interactionUse_EReference_returnValueRecipient = factory->createEReference_in_EContainingClass(m_interactionUse_EClass, INTERACTIONUSE_EREFERENCE_RETURNVALUERECIPIENT);
	
	m_interactionUse_EOperation_all_lifelines_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_interactionUse_EClass, INTERACTIONUSE_EOPERATION_ALL_LIFELINES_EDIAGNOSTICCHAIN_EMAP);
	m_interactionUse_EOperation_arguments_are_constants_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_interactionUse_EClass, INTERACTIONUSE_EOPERATION_ARGUMENTS_ARE_CONSTANTS_EDIAGNOSTICCHAIN_EMAP);
	m_interactionUse_EOperation_arguments_correspond_to_parameters_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_interactionUse_EClass, INTERACTIONUSE_EOPERATION_ARGUMENTS_CORRESPOND_TO_PARAMETERS_EDIAGNOSTICCHAIN_EMAP);
	m_interactionUse_EOperation_gates_match_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_interactionUse_EClass, INTERACTIONUSE_EOPERATION_GATES_MATCH_EDIAGNOSTICCHAIN_EMAP);
	m_interactionUse_EOperation_returnValueRecipient_coverage_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_interactionUse_EClass, INTERACTIONUSE_EOPERATION_RETURNVALUERECIPIENT_COVERAGE_EDIAGNOSTICCHAIN_EMAP);
	m_interactionUse_EOperation_returnValue_type_recipient_correspondence_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_interactionUse_EClass, INTERACTIONUSE_EOPERATION_RETURNVALUE_TYPE_RECIPIENT_CORRESPONDENCE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createInterfaceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_interface_EClass = factory->createEClass_in_EPackage(package, INTERFACE_ECLASS);
	
	m_interface_EReference_nestedClassifier = factory->createEReference_in_EContainingClass(m_interface_EClass, INTERFACE_EREFERENCE_NESTEDCLASSIFIER);
	m_interface_EReference_ownedAttribute = factory->createEReference_in_EContainingClass(m_interface_EClass, INTERFACE_EREFERENCE_OWNEDATTRIBUTE);
	m_interface_EReference_ownedOperation = factory->createEReference_in_EContainingClass(m_interface_EClass, INTERFACE_EREFERENCE_OWNEDOPERATION);
	m_interface_EReference_ownedReception = factory->createEReference_in_EContainingClass(m_interface_EClass, INTERFACE_EREFERENCE_OWNEDRECEPTION);
	m_interface_EReference_protocol = factory->createEReference_in_EContainingClass(m_interface_EClass, INTERFACE_EREFERENCE_PROTOCOL);
	m_interface_EReference_redefinedInterface = factory->createEReference_in_EContainingClass(m_interface_EClass, INTERFACE_EREFERENCE_REDEFINEDINTERFACE);
	
	m_interface_EOperation_createOwnedAttribute_String_UnlimitedNatural = factory->createEOperation_in_EContainingClass(m_interface_EClass, INTERFACE_EOPERATION_CREATEOWNEDATTRIBUTE_STRING_UNLIMITEDNATURAL);
	m_interface_EOperation_createOwnedOperation_String_Type = factory->createEOperation_in_EContainingClass(m_interface_EClass, INTERFACE_EOPERATION_CREATEOWNEDOPERATION_STRING_TYPE);
	m_interface_EOperation_visibility_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_interface_EClass, INTERFACE_EOPERATION_VISIBILITY_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createInterfaceRealizationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_interfaceRealization_EClass = factory->createEClass_in_EPackage(package, INTERFACEREALIZATION_ECLASS);
	
	m_interfaceRealization_EReference_contract = factory->createEReference_in_EContainingClass(m_interfaceRealization_EClass, INTERFACEREALIZATION_EREFERENCE_CONTRACT);
	m_interfaceRealization_EReference_implementingClassifier = factory->createEReference_in_EContainingClass(m_interfaceRealization_EClass, INTERFACEREALIZATION_EREFERENCE_IMPLEMENTINGCLASSIFIER);
	
	
}

void UmlPackageImpl::createInterruptibleActivityRegionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_interruptibleActivityRegion_EClass = factory->createEClass_in_EPackage(package, INTERRUPTIBLEACTIVITYREGION_ECLASS);
	
	m_interruptibleActivityRegion_EReference_interruptingEdge = factory->createEReference_in_EContainingClass(m_interruptibleActivityRegion_EClass, INTERRUPTIBLEACTIVITYREGION_EREFERENCE_INTERRUPTINGEDGE);
	m_interruptibleActivityRegion_EReference_node = factory->createEReference_in_EContainingClass(m_interruptibleActivityRegion_EClass, INTERRUPTIBLEACTIVITYREGION_EREFERENCE_NODE);
	
	m_interruptibleActivityRegion_EOperation_interrupting_edges_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_interruptibleActivityRegion_EClass, INTERRUPTIBLEACTIVITYREGION_EOPERATION_INTERRUPTING_EDGES_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createIntervalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_interval_EClass = factory->createEClass_in_EPackage(package, INTERVAL_ECLASS);
	
	m_interval_EReference_max = factory->createEReference_in_EContainingClass(m_interval_EClass, INTERVAL_EREFERENCE_MAX);
	m_interval_EReference_min = factory->createEReference_in_EContainingClass(m_interval_EClass, INTERVAL_EREFERENCE_MIN);
	
	
}

void UmlPackageImpl::createIntervalConstraintContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_intervalConstraint_EClass = factory->createEClass_in_EPackage(package, INTERVALCONSTRAINT_ECLASS);
	
	
	
}

void UmlPackageImpl::createInvocationActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_invocationAction_EClass = factory->createEClass_in_EPackage(package, INVOCATIONACTION_ECLASS);
	
	m_invocationAction_EReference_argument = factory->createEReference_in_EContainingClass(m_invocationAction_EClass, INVOCATIONACTION_EREFERENCE_ARGUMENT);
	m_invocationAction_EReference_onPort = factory->createEReference_in_EContainingClass(m_invocationAction_EClass, INVOCATIONACTION_EREFERENCE_ONPORT);
	
	
}

void UmlPackageImpl::createJoinNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_joinNode_EClass = factory->createEClass_in_EPackage(package, JOINNODE_ECLASS);
	m_joinNode_EAttribute_isCombineDuplicate = factory->createEAttribute_in_EContainingClass(m_joinNode_EClass, JOINNODE_EATTRIBUTE_ISCOMBINEDUPLICATE);
	
	m_joinNode_EReference_joinSpec = factory->createEReference_in_EContainingClass(m_joinNode_EClass, JOINNODE_EREFERENCE_JOINSPEC);
	
	m_joinNode_EOperation_incoming_object_flow_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_joinNode_EClass, JOINNODE_EOPERATION_INCOMING_OBJECT_FLOW_EDIAGNOSTICCHAIN_EMAP);
	m_joinNode_EOperation_one_outgoing_edge_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_joinNode_EClass, JOINNODE_EOPERATION_ONE_OUTGOING_EDGE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createLifelineContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_lifeline_EClass = factory->createEClass_in_EPackage(package, LIFELINE_ECLASS);
	
	m_lifeline_EReference_coveredBy = factory->createEReference_in_EContainingClass(m_lifeline_EClass, LIFELINE_EREFERENCE_COVEREDBY);
	m_lifeline_EReference_decomposedAs = factory->createEReference_in_EContainingClass(m_lifeline_EClass, LIFELINE_EREFERENCE_DECOMPOSEDAS);
	m_lifeline_EReference_interaction = factory->createEReference_in_EContainingClass(m_lifeline_EClass, LIFELINE_EREFERENCE_INTERACTION);
	m_lifeline_EReference_represents = factory->createEReference_in_EContainingClass(m_lifeline_EClass, LIFELINE_EREFERENCE_REPRESENTS);
	m_lifeline_EReference_selector = factory->createEReference_in_EContainingClass(m_lifeline_EClass, LIFELINE_EREFERENCE_SELECTOR);
	
	m_lifeline_EOperation_interaction_uses_share_lifeline_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_lifeline_EClass, LIFELINE_EOPERATION_INTERACTION_USES_SHARE_LIFELINE_EDIAGNOSTICCHAIN_EMAP);
	m_lifeline_EOperation_same_classifier_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_lifeline_EClass, LIFELINE_EOPERATION_SAME_CLASSIFIER_EDIAGNOSTICCHAIN_EMAP);
	m_lifeline_EOperation_selector_int_or_string_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_lifeline_EClass, LIFELINE_EOPERATION_SELECTOR_INT_OR_STRING_EDIAGNOSTICCHAIN_EMAP);
	m_lifeline_EOperation_selector_specified_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_lifeline_EClass, LIFELINE_EOPERATION_SELECTOR_SPECIFIED_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createLinkActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_linkAction_EClass = factory->createEClass_in_EPackage(package, LINKACTION_ECLASS);
	
	m_linkAction_EReference_endData = factory->createEReference_in_EContainingClass(m_linkAction_EClass, LINKACTION_EREFERENCE_ENDDATA);
	m_linkAction_EReference_inputValue = factory->createEReference_in_EContainingClass(m_linkAction_EClass, LINKACTION_EREFERENCE_INPUTVALUE);
	
	m_linkAction_EOperation_association = factory->createEOperation_in_EContainingClass(m_linkAction_EClass, LINKACTION_EOPERATION_ASSOCIATION);
	m_linkAction_EOperation_not_static_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_linkAction_EClass, LINKACTION_EOPERATION_NOT_STATIC_EDIAGNOSTICCHAIN_EMAP);
	m_linkAction_EOperation_same_association_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_linkAction_EClass, LINKACTION_EOPERATION_SAME_ASSOCIATION_EDIAGNOSTICCHAIN_EMAP);
	m_linkAction_EOperation_same_pins_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_linkAction_EClass, LINKACTION_EOPERATION_SAME_PINS_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createLinkEndCreationDataContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_linkEndCreationData_EClass = factory->createEClass_in_EPackage(package, LINKENDCREATIONDATA_ECLASS);
	m_linkEndCreationData_EAttribute_isReplaceAll = factory->createEAttribute_in_EContainingClass(m_linkEndCreationData_EClass, LINKENDCREATIONDATA_EATTRIBUTE_ISREPLACEALL);
	
	m_linkEndCreationData_EReference_insertAt = factory->createEReference_in_EContainingClass(m_linkEndCreationData_EClass, LINKENDCREATIONDATA_EREFERENCE_INSERTAT);
	
	m_linkEndCreationData_EOperation_insertAt_pin_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_linkEndCreationData_EClass, LINKENDCREATIONDATA_EOPERATION_INSERTAT_PIN_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createLinkEndDataContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_linkEndData_EClass = factory->createEClass_in_EPackage(package, LINKENDDATA_ECLASS);
	
	m_linkEndData_EReference_end = factory->createEReference_in_EContainingClass(m_linkEndData_EClass, LINKENDDATA_EREFERENCE_END);
	m_linkEndData_EReference_qualifier = factory->createEReference_in_EContainingClass(m_linkEndData_EClass, LINKENDDATA_EREFERENCE_QUALIFIER);
	m_linkEndData_EReference_value = factory->createEReference_in_EContainingClass(m_linkEndData_EClass, LINKENDDATA_EREFERENCE_VALUE);
	
	m_linkEndData_EOperation_allPins = factory->createEOperation_in_EContainingClass(m_linkEndData_EClass, LINKENDDATA_EOPERATION_ALLPINS);
	m_linkEndData_EOperation_end_object_input_pin_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_linkEndData_EClass, LINKENDDATA_EOPERATION_END_OBJECT_INPUT_PIN_EDIAGNOSTICCHAIN_EMAP);
	m_linkEndData_EOperation_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_linkEndData_EClass, LINKENDDATA_EOPERATION_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	m_linkEndData_EOperation_property_is_association_end_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_linkEndData_EClass, LINKENDDATA_EOPERATION_PROPERTY_IS_ASSOCIATION_END_EDIAGNOSTICCHAIN_EMAP);
	m_linkEndData_EOperation_qualifiers_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_linkEndData_EClass, LINKENDDATA_EOPERATION_QUALIFIERS_EDIAGNOSTICCHAIN_EMAP);
	m_linkEndData_EOperation_same_type_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_linkEndData_EClass, LINKENDDATA_EOPERATION_SAME_TYPE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createLinkEndDestructionDataContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_linkEndDestructionData_EClass = factory->createEClass_in_EPackage(package, LINKENDDESTRUCTIONDATA_ECLASS);
	m_linkEndDestructionData_EAttribute_isDestroyDuplicates = factory->createEAttribute_in_EContainingClass(m_linkEndDestructionData_EClass, LINKENDDESTRUCTIONDATA_EATTRIBUTE_ISDESTROYDUPLICATES);
	
	m_linkEndDestructionData_EReference_destroyAt = factory->createEReference_in_EContainingClass(m_linkEndDestructionData_EClass, LINKENDDESTRUCTIONDATA_EREFERENCE_DESTROYAT);
	
	m_linkEndDestructionData_EOperation_destroyAt_pin_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_linkEndDestructionData_EClass, LINKENDDESTRUCTIONDATA_EOPERATION_DESTROYAT_PIN_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createLiteralBooleanContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_literalBoolean_EClass = factory->createEClass_in_EPackage(package, LITERALBOOLEAN_ECLASS);
	m_literalBoolean_EAttribute_value = factory->createEAttribute_in_EContainingClass(m_literalBoolean_EClass, LITERALBOOLEAN_EATTRIBUTE_VALUE);
	
	
	
}

void UmlPackageImpl::createLiteralIntegerContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_literalInteger_EClass = factory->createEClass_in_EPackage(package, LITERALINTEGER_ECLASS);
	m_literalInteger_EAttribute_value = factory->createEAttribute_in_EContainingClass(m_literalInteger_EClass, LITERALINTEGER_EATTRIBUTE_VALUE);
	
	
	
}

void UmlPackageImpl::createLiteralNullContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_literalNull_EClass = factory->createEClass_in_EPackage(package, LITERALNULL_ECLASS);
	
	
	
}

void UmlPackageImpl::createLiteralRealContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_literalReal_EClass = factory->createEClass_in_EPackage(package, LITERALREAL_ECLASS);
	m_literalReal_EAttribute_value = factory->createEAttribute_in_EContainingClass(m_literalReal_EClass, LITERALREAL_EATTRIBUTE_VALUE);
	
	
	
}

void UmlPackageImpl::createLiteralSpecificationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_literalSpecification_EClass = factory->createEClass_in_EPackage(package, LITERALSPECIFICATION_ECLASS);
	
	
	
}

void UmlPackageImpl::createLiteralStringContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_literalString_EClass = factory->createEClass_in_EPackage(package, LITERALSTRING_ECLASS);
	m_literalString_EAttribute_value = factory->createEAttribute_in_EContainingClass(m_literalString_EClass, LITERALSTRING_EATTRIBUTE_VALUE);
	
	
	
}

void UmlPackageImpl::createLiteralUnlimitedNaturalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_literalUnlimitedNatural_EClass = factory->createEClass_in_EPackage(package, LITERALUNLIMITEDNATURAL_ECLASS);
	m_literalUnlimitedNatural_EAttribute_value = factory->createEAttribute_in_EContainingClass(m_literalUnlimitedNatural_EClass, LITERALUNLIMITEDNATURAL_EATTRIBUTE_VALUE);
	
	
	
}

void UmlPackageImpl::createLoopNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_loopNode_EClass = factory->createEClass_in_EPackage(package, LOOPNODE_ECLASS);
	m_loopNode_EAttribute_isTestedFirst = factory->createEAttribute_in_EContainingClass(m_loopNode_EClass, LOOPNODE_EATTRIBUTE_ISTESTEDFIRST);
	
	m_loopNode_EReference_bodyOutput = factory->createEReference_in_EContainingClass(m_loopNode_EClass, LOOPNODE_EREFERENCE_BODYOUTPUT);
	m_loopNode_EReference_bodyPart = factory->createEReference_in_EContainingClass(m_loopNode_EClass, LOOPNODE_EREFERENCE_BODYPART);
	m_loopNode_EReference_decider = factory->createEReference_in_EContainingClass(m_loopNode_EClass, LOOPNODE_EREFERENCE_DECIDER);
	m_loopNode_EReference_loopVariable = factory->createEReference_in_EContainingClass(m_loopNode_EClass, LOOPNODE_EREFERENCE_LOOPVARIABLE);
	m_loopNode_EReference_loopVariableInput = factory->createEReference_in_EContainingClass(m_loopNode_EClass, LOOPNODE_EREFERENCE_LOOPVARIABLEINPUT);
	m_loopNode_EReference_result = factory->createEReference_in_EContainingClass(m_loopNode_EClass, LOOPNODE_EREFERENCE_RESULT);
	m_loopNode_EReference_setupPart = factory->createEReference_in_EContainingClass(m_loopNode_EClass, LOOPNODE_EREFERENCE_SETUPPART);
	m_loopNode_EReference_test = factory->createEReference_in_EContainingClass(m_loopNode_EClass, LOOPNODE_EREFERENCE_TEST);
	
	m_loopNode_EOperation_body_output_pins_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_loopNode_EClass, LOOPNODE_EOPERATION_BODY_OUTPUT_PINS_EDIAGNOSTICCHAIN_EMAP);
	m_loopNode_EOperation_executable_nodes_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_loopNode_EClass, LOOPNODE_EOPERATION_EXECUTABLE_NODES_EDIAGNOSTICCHAIN_EMAP);
	m_loopNode_EOperation_input_edges_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_loopNode_EClass, LOOPNODE_EOPERATION_INPUT_EDGES_EDIAGNOSTICCHAIN_EMAP);
	m_loopNode_EOperation_loop_variable_outgoing_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_loopNode_EClass, LOOPNODE_EOPERATION_LOOP_VARIABLE_OUTGOING_EDIAGNOSTICCHAIN_EMAP);
	m_loopNode_EOperation_matching_loop_variables_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_loopNode_EClass, LOOPNODE_EOPERATION_MATCHING_LOOP_VARIABLES_EDIAGNOSTICCHAIN_EMAP);
	m_loopNode_EOperation_matching_output_pins_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_loopNode_EClass, LOOPNODE_EOPERATION_MATCHING_OUTPUT_PINS_EDIAGNOSTICCHAIN_EMAP);
	m_loopNode_EOperation_matching_result_pins_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_loopNode_EClass, LOOPNODE_EOPERATION_MATCHING_RESULT_PINS_EDIAGNOSTICCHAIN_EMAP);
	m_loopNode_EOperation_result_no_incoming_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_loopNode_EClass, LOOPNODE_EOPERATION_RESULT_NO_INCOMING_EDIAGNOSTICCHAIN_EMAP);
	m_loopNode_EOperation_setup_test_and_body_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_loopNode_EClass, LOOPNODE_EOPERATION_SETUP_TEST_AND_BODY_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createManifestationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_manifestation_EClass = factory->createEClass_in_EPackage(package, MANIFESTATION_ECLASS);
	
	m_manifestation_EReference_utilizedElement = factory->createEReference_in_EContainingClass(m_manifestation_EClass, MANIFESTATION_EREFERENCE_UTILIZEDELEMENT);
	
	
}

void UmlPackageImpl::createMergeNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_mergeNode_EClass = factory->createEClass_in_EPackage(package, MERGENODE_ECLASS);
	
	
	m_mergeNode_EOperation_edges_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_mergeNode_EClass, MERGENODE_EOPERATION_EDGES_EDIAGNOSTICCHAIN_EMAP);
	m_mergeNode_EOperation_one_outgoing_edge_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_mergeNode_EClass, MERGENODE_EOPERATION_ONE_OUTGOING_EDGE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createMessageContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_message_EClass = factory->createEClass_in_EPackage(package, MESSAGE_ECLASS);
	m_message_EAttribute_messageKind = factory->createEAttribute_in_EContainingClass(m_message_EClass, MESSAGE_EATTRIBUTE_MESSAGEKIND);
	m_message_EAttribute_messageSort = factory->createEAttribute_in_EContainingClass(m_message_EClass, MESSAGE_EATTRIBUTE_MESSAGESORT);
	
	m_message_EReference_argument = factory->createEReference_in_EContainingClass(m_message_EClass, MESSAGE_EREFERENCE_ARGUMENT);
	m_message_EReference_connector = factory->createEReference_in_EContainingClass(m_message_EClass, MESSAGE_EREFERENCE_CONNECTOR);
	m_message_EReference_interaction = factory->createEReference_in_EContainingClass(m_message_EClass, MESSAGE_EREFERENCE_INTERACTION);
	m_message_EReference_receiveEvent = factory->createEReference_in_EContainingClass(m_message_EClass, MESSAGE_EREFERENCE_RECEIVEEVENT);
	m_message_EReference_sendEvent = factory->createEReference_in_EContainingClass(m_message_EClass, MESSAGE_EREFERENCE_SENDEVENT);
	m_message_EReference_signature = factory->createEReference_in_EContainingClass(m_message_EClass, MESSAGE_EREFERENCE_SIGNATURE);
	
	m_message_EOperation_arguments_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_message_EClass, MESSAGE_EOPERATION_ARGUMENTS_EDIAGNOSTICCHAIN_EMAP);
	m_message_EOperation_cannot_cross_boundaries_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_message_EClass, MESSAGE_EOPERATION_CANNOT_CROSS_BOUNDARIES_EDIAGNOSTICCHAIN_EMAP);
	m_message_EOperation_getMessageKind = factory->createEOperation_in_EContainingClass(m_message_EClass, MESSAGE_EOPERATION_GETMESSAGEKIND);
	m_message_EOperation_occurrence_specifications_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_message_EClass, MESSAGE_EOPERATION_OCCURRENCE_SPECIFICATIONS_EDIAGNOSTICCHAIN_EMAP);
	m_message_EOperation_sending_receiving_message_event_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_message_EClass, MESSAGE_EOPERATION_SENDING_RECEIVING_MESSAGE_EVENT_EDIAGNOSTICCHAIN_EMAP);
	m_message_EOperation_signature_is_operation_reply_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_message_EClass, MESSAGE_EOPERATION_SIGNATURE_IS_OPERATION_REPLY_EDIAGNOSTICCHAIN_EMAP);
	m_message_EOperation_signature_is_operation_request_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_message_EClass, MESSAGE_EOPERATION_SIGNATURE_IS_OPERATION_REQUEST_EDIAGNOSTICCHAIN_EMAP);
	m_message_EOperation_signature_is_signal_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_message_EClass, MESSAGE_EOPERATION_SIGNATURE_IS_SIGNAL_EDIAGNOSTICCHAIN_EMAP);
	m_message_EOperation_signature_refer_to_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_message_EClass, MESSAGE_EOPERATION_SIGNATURE_REFER_TO_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createMessageEndContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_messageEnd_EClass = factory->createEClass_in_EPackage(package, MESSAGEEND_ECLASS);
	
	m_messageEnd_EReference_message = factory->createEReference_in_EContainingClass(m_messageEnd_EClass, MESSAGEEND_EREFERENCE_MESSAGE);
	
	m_messageEnd_EOperation_enclosingFragment = factory->createEOperation_in_EContainingClass(m_messageEnd_EClass, MESSAGEEND_EOPERATION_ENCLOSINGFRAGMENT);
	m_messageEnd_EOperation_isReceive = factory->createEOperation_in_EContainingClass(m_messageEnd_EClass, MESSAGEEND_EOPERATION_ISRECEIVE);
	m_messageEnd_EOperation_isSend = factory->createEOperation_in_EContainingClass(m_messageEnd_EClass, MESSAGEEND_EOPERATION_ISSEND);
	m_messageEnd_EOperation_oppositeEnd = factory->createEOperation_in_EContainingClass(m_messageEnd_EClass, MESSAGEEND_EOPERATION_OPPOSITEEND);
	
}

void UmlPackageImpl::createMessageEventContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_messageEvent_EClass = factory->createEClass_in_EPackage(package, MESSAGEEVENT_ECLASS);
	
	
	
}

void UmlPackageImpl::createMessageOccurrenceSpecificationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_messageOccurrenceSpecification_EClass = factory->createEClass_in_EPackage(package, MESSAGEOCCURRENCESPECIFICATION_ECLASS);
	
	
	
}

void UmlPackageImpl::createModelContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_model_EClass = factory->createEClass_in_EPackage(package, MODEL_ECLASS);
	m_model_EAttribute_viewpoint = factory->createEAttribute_in_EContainingClass(m_model_EClass, MODEL_EATTRIBUTE_VIEWPOINT);
	
	
	m_model_EOperation_isMetamodel = factory->createEOperation_in_EContainingClass(m_model_EClass, MODEL_EOPERATION_ISMETAMODEL);
	
}

void UmlPackageImpl::createMultiplicityElementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_multiplicityElement_EClass = factory->createEClass_in_EPackage(package, MULTIPLICITYELEMENT_ECLASS);
	m_multiplicityElement_EAttribute_isOrdered = factory->createEAttribute_in_EContainingClass(m_multiplicityElement_EClass, MULTIPLICITYELEMENT_EATTRIBUTE_ISORDERED);
	m_multiplicityElement_EAttribute_isUnique = factory->createEAttribute_in_EContainingClass(m_multiplicityElement_EClass, MULTIPLICITYELEMENT_EATTRIBUTE_ISUNIQUE);
	m_multiplicityElement_EAttribute_lower = factory->createEAttribute_in_EContainingClass(m_multiplicityElement_EClass, MULTIPLICITYELEMENT_EATTRIBUTE_LOWER);
	m_multiplicityElement_EAttribute_upper = factory->createEAttribute_in_EContainingClass(m_multiplicityElement_EClass, MULTIPLICITYELEMENT_EATTRIBUTE_UPPER);
	
	m_multiplicityElement_EReference_lowerValue = factory->createEReference_in_EContainingClass(m_multiplicityElement_EClass, MULTIPLICITYELEMENT_EREFERENCE_LOWERVALUE);
	m_multiplicityElement_EReference_upperValue = factory->createEReference_in_EContainingClass(m_multiplicityElement_EClass, MULTIPLICITYELEMENT_EREFERENCE_UPPERVALUE);
	
	m_multiplicityElement_EOperation_compatibleWith_MultiplicityElement = factory->createEOperation_in_EContainingClass(m_multiplicityElement_EClass, MULTIPLICITYELEMENT_EOPERATION_COMPATIBLEWITH_MULTIPLICITYELEMENT);
	m_multiplicityElement_EOperation_includesMultiplicity_MultiplicityElement = factory->createEOperation_in_EContainingClass(m_multiplicityElement_EClass, MULTIPLICITYELEMENT_EOPERATION_INCLUDESMULTIPLICITY_MULTIPLICITYELEMENT);
	m_multiplicityElement_EOperation_is_Integer_UnlimitedNatural = factory->createEOperation_in_EContainingClass(m_multiplicityElement_EClass, MULTIPLICITYELEMENT_EOPERATION_IS_INTEGER_UNLIMITEDNATURAL);
	m_multiplicityElement_EOperation_isMultivalued = factory->createEOperation_in_EContainingClass(m_multiplicityElement_EClass, MULTIPLICITYELEMENT_EOPERATION_ISMULTIVALUED);
	m_multiplicityElement_EOperation_lowerBound = factory->createEOperation_in_EContainingClass(m_multiplicityElement_EClass, MULTIPLICITYELEMENT_EOPERATION_LOWERBOUND);
	m_multiplicityElement_EOperation_lower_ge_0_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_multiplicityElement_EClass, MULTIPLICITYELEMENT_EOPERATION_LOWER_GE_0_EDIAGNOSTICCHAIN_EMAP);
	m_multiplicityElement_EOperation_lower_is_integer_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_multiplicityElement_EClass, MULTIPLICITYELEMENT_EOPERATION_LOWER_IS_INTEGER_EDIAGNOSTICCHAIN_EMAP);
	m_multiplicityElement_EOperation_upperBound = factory->createEOperation_in_EContainingClass(m_multiplicityElement_EClass, MULTIPLICITYELEMENT_EOPERATION_UPPERBOUND);
	m_multiplicityElement_EOperation_upper_ge_lower_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_multiplicityElement_EClass, MULTIPLICITYELEMENT_EOPERATION_UPPER_GE_LOWER_EDIAGNOSTICCHAIN_EMAP);
	m_multiplicityElement_EOperation_upper_is_unlimitedNatural_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_multiplicityElement_EClass, MULTIPLICITYELEMENT_EOPERATION_UPPER_IS_UNLIMITEDNATURAL_EDIAGNOSTICCHAIN_EMAP);
	m_multiplicityElement_EOperation_value_specification_constant_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_multiplicityElement_EClass, MULTIPLICITYELEMENT_EOPERATION_VALUE_SPECIFICATION_CONSTANT_EDIAGNOSTICCHAIN_EMAP);
	m_multiplicityElement_EOperation_value_specification_no_side_effects_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_multiplicityElement_EClass, MULTIPLICITYELEMENT_EOPERATION_VALUE_SPECIFICATION_NO_SIDE_EFFECTS_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createNamedElementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_namedElement_EClass = factory->createEClass_in_EPackage(package, NAMEDELEMENT_ECLASS);
	m_namedElement_EAttribute_name = factory->createEAttribute_in_EContainingClass(m_namedElement_EClass, NAMEDELEMENT_EATTRIBUTE_NAME);
	m_namedElement_EAttribute_qualifiedName = factory->createEAttribute_in_EContainingClass(m_namedElement_EClass, NAMEDELEMENT_EATTRIBUTE_QUALIFIEDNAME);
	m_namedElement_EAttribute_visibility = factory->createEAttribute_in_EContainingClass(m_namedElement_EClass, NAMEDELEMENT_EATTRIBUTE_VISIBILITY);
	
	m_namedElement_EReference_clientDependency = factory->createEReference_in_EContainingClass(m_namedElement_EClass, NAMEDELEMENT_EREFERENCE_CLIENTDEPENDENCY);
	m_namedElement_EReference_nameExpression = factory->createEReference_in_EContainingClass(m_namedElement_EClass, NAMEDELEMENT_EREFERENCE_NAMEEXPRESSION);
	m_namedElement_EReference_namespace = factory->createEReference_in_EContainingClass(m_namedElement_EClass, NAMEDELEMENT_EREFERENCE_NAMESPACE);
	
	m_namedElement_EOperation_allNamespaces = factory->createEOperation_in_EContainingClass(m_namedElement_EClass, NAMEDELEMENT_EOPERATION_ALLNAMESPACES);
	m_namedElement_EOperation_allOwningPackages = factory->createEOperation_in_EContainingClass(m_namedElement_EClass, NAMEDELEMENT_EOPERATION_ALLOWNINGPACKAGES);
	m_namedElement_EOperation_createDependency_NamedElement = factory->createEOperation_in_EContainingClass(m_namedElement_EClass, NAMEDELEMENT_EOPERATION_CREATEDEPENDENCY_NAMEDELEMENT);
	m_namedElement_EOperation_createUsage_NamedElement = factory->createEOperation_in_EContainingClass(m_namedElement_EClass, NAMEDELEMENT_EOPERATION_CREATEUSAGE_NAMEDELEMENT);
	m_namedElement_EOperation_getClientDependencies = factory->createEOperation_in_EContainingClass(m_namedElement_EClass, NAMEDELEMENT_EOPERATION_GETCLIENTDEPENDENCIES);
	m_namedElement_EOperation_getLabel = factory->createEOperation_in_EContainingClass(m_namedElement_EClass, NAMEDELEMENT_EOPERATION_GETLABEL);
	m_namedElement_EOperation_getLabel_Boolean = factory->createEOperation_in_EContainingClass(m_namedElement_EClass, NAMEDELEMENT_EOPERATION_GETLABEL_BOOLEAN);
	m_namedElement_EOperation_getNamespace = factory->createEOperation_in_EContainingClass(m_namedElement_EClass, NAMEDELEMENT_EOPERATION_GETNAMESPACE);
	m_namedElement_EOperation_getQualifiedName = factory->createEOperation_in_EContainingClass(m_namedElement_EClass, NAMEDELEMENT_EOPERATION_GETQUALIFIEDNAME);
	m_namedElement_EOperation_has_no_qualified_name_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_namedElement_EClass, NAMEDELEMENT_EOPERATION_HAS_NO_QUALIFIED_NAME_EDIAGNOSTICCHAIN_EMAP);
	m_namedElement_EOperation_has_qualified_name_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_namedElement_EClass, NAMEDELEMENT_EOPERATION_HAS_QUALIFIED_NAME_EDIAGNOSTICCHAIN_EMAP);
	m_namedElement_EOperation_isDistinguishableFrom_NamedElement_Namespace = factory->createEOperation_in_EContainingClass(m_namedElement_EClass, NAMEDELEMENT_EOPERATION_ISDISTINGUISHABLEFROM_NAMEDELEMENT_NAMESPACE);
	m_namedElement_EOperation_separator = factory->createEOperation_in_EContainingClass(m_namedElement_EClass, NAMEDELEMENT_EOPERATION_SEPARATOR);
	m_namedElement_EOperation_visibility_needs_ownership_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_namedElement_EClass, NAMEDELEMENT_EOPERATION_VISIBILITY_NEEDS_OWNERSHIP_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createNamespaceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_namespace_EClass = factory->createEClass_in_EPackage(package, NAMESPACE_ECLASS);
	
	m_namespace_EReference_elementImport = factory->createEReference_in_EContainingClass(m_namespace_EClass, NAMESPACE_EREFERENCE_ELEMENTIMPORT);
	m_namespace_EReference_importedMember = factory->createEReference_in_EContainingClass(m_namespace_EClass, NAMESPACE_EREFERENCE_IMPORTEDMEMBER);
	m_namespace_EReference_member = factory->createEReference_in_EContainingClass(m_namespace_EClass, NAMESPACE_EREFERENCE_MEMBER);
	m_namespace_EReference_ownedMember = factory->createEReference_in_EContainingClass(m_namespace_EClass, NAMESPACE_EREFERENCE_OWNEDMEMBER);
	m_namespace_EReference_ownedRule = factory->createEReference_in_EContainingClass(m_namespace_EClass, NAMESPACE_EREFERENCE_OWNEDRULE);
	m_namespace_EReference_packageImport = factory->createEReference_in_EContainingClass(m_namespace_EClass, NAMESPACE_EREFERENCE_PACKAGEIMPORT);
	
	m_namespace_EOperation_cannot_import_ownedMembers_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_namespace_EClass, NAMESPACE_EOPERATION_CANNOT_IMPORT_OWNEDMEMBERS_EDIAGNOSTICCHAIN_EMAP);
	m_namespace_EOperation_cannot_import_self_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_namespace_EClass, NAMESPACE_EOPERATION_CANNOT_IMPORT_SELF_EDIAGNOSTICCHAIN_EMAP);
	m_namespace_EOperation_createElementImport_PackageableElement_VisibilityKind = factory->createEOperation_in_EContainingClass(m_namespace_EClass, NAMESPACE_EOPERATION_CREATEELEMENTIMPORT_PACKAGEABLEELEMENT_VISIBILITYKIND);
	m_namespace_EOperation_createPackageImport_Package_VisibilityKind = factory->createEOperation_in_EContainingClass(m_namespace_EClass, NAMESPACE_EOPERATION_CREATEPACKAGEIMPORT_PACKAGE_VISIBILITYKIND);
	m_namespace_EOperation_excludeCollisions_PackageableElement = factory->createEOperation_in_EContainingClass(m_namespace_EClass, NAMESPACE_EOPERATION_EXCLUDECOLLISIONS_PACKAGEABLEELEMENT);
	m_namespace_EOperation_getImportedElements = factory->createEOperation_in_EContainingClass(m_namespace_EClass, NAMESPACE_EOPERATION_GETIMPORTEDELEMENTS);
	m_namespace_EOperation_getImportedMembers = factory->createEOperation_in_EContainingClass(m_namespace_EClass, NAMESPACE_EOPERATION_GETIMPORTEDMEMBERS);
	m_namespace_EOperation_getImportedPackages = factory->createEOperation_in_EContainingClass(m_namespace_EClass, NAMESPACE_EOPERATION_GETIMPORTEDPACKAGES);
	m_namespace_EOperation_getNamesOfMember_NamedElement = factory->createEOperation_in_EContainingClass(m_namespace_EClass, NAMESPACE_EOPERATION_GETNAMESOFMEMBER_NAMEDELEMENT);
	m_namespace_EOperation_getOwnedMembers = factory->createEOperation_in_EContainingClass(m_namespace_EClass, NAMESPACE_EOPERATION_GETOWNEDMEMBERS);
	m_namespace_EOperation_importMembers_PackageableElement = factory->createEOperation_in_EContainingClass(m_namespace_EClass, NAMESPACE_EOPERATION_IMPORTMEMBERS_PACKAGEABLEELEMENT);
	m_namespace_EOperation_membersAreDistinguishable = factory->createEOperation_in_EContainingClass(m_namespace_EClass, NAMESPACE_EOPERATION_MEMBERSAREDISTINGUISHABLE);
	m_namespace_EOperation_members_distinguishable_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_namespace_EClass, NAMESPACE_EOPERATION_MEMBERS_DISTINGUISHABLE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_node_EClass = factory->createEClass_in_EPackage(package, NODE_ECLASS);
	
	m_node_EReference_nestedNode = factory->createEReference_in_EContainingClass(m_node_EClass, NODE_EREFERENCE_NESTEDNODE);
	
	m_node_EOperation_createCommunicationPath_Boolean_UnlimitedNatural = factory->createEOperation_in_EContainingClass(m_node_EClass, NODE_EOPERATION_CREATECOMMUNICATIONPATH_BOOLEAN_UNLIMITEDNATURAL);
	m_node_EOperation_getCommunicationPaths = factory->createEOperation_in_EContainingClass(m_node_EClass, NODE_EOPERATION_GETCOMMUNICATIONPATHS);
	m_node_EOperation_internal_structure_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_node_EClass, NODE_EOPERATION_INTERNAL_STRUCTURE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createObjectContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_object_EClass = factory->createEClass_in_EPackage(package, OBJECT_ECLASS);
	
	
	m_object_EOperation_get_Property = factory->createEOperation_in_EContainingClass(m_object_EClass, OBJECT_EOPERATION_GET_PROPERTY);
	m_object_EOperation_set_Property_EJavaObject = factory->createEOperation_in_EContainingClass(m_object_EClass, OBJECT_EOPERATION_SET_PROPERTY_EJAVAOBJECT);
	m_object_EOperation_unset_Property = factory->createEOperation_in_EContainingClass(m_object_EClass, OBJECT_EOPERATION_UNSET_PROPERTY);
	
}

void UmlPackageImpl::createObjectFlowContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_objectFlow_EClass = factory->createEClass_in_EPackage(package, OBJECTFLOW_ECLASS);
	m_objectFlow_EAttribute_isMulticast = factory->createEAttribute_in_EContainingClass(m_objectFlow_EClass, OBJECTFLOW_EATTRIBUTE_ISMULTICAST);
	m_objectFlow_EAttribute_isMultireceive = factory->createEAttribute_in_EContainingClass(m_objectFlow_EClass, OBJECTFLOW_EATTRIBUTE_ISMULTIRECEIVE);
	
	m_objectFlow_EReference_selection = factory->createEReference_in_EContainingClass(m_objectFlow_EClass, OBJECTFLOW_EREFERENCE_SELECTION);
	m_objectFlow_EReference_transformation = factory->createEReference_in_EContainingClass(m_objectFlow_EClass, OBJECTFLOW_EREFERENCE_TRANSFORMATION);
	
	m_objectFlow_EOperation_compatible_types_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_objectFlow_EClass, OBJECTFLOW_EOPERATION_COMPATIBLE_TYPES_EDIAGNOSTICCHAIN_EMAP);
	m_objectFlow_EOperation_input_and_output_parameter_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_objectFlow_EClass, OBJECTFLOW_EOPERATION_INPUT_AND_OUTPUT_PARAMETER_EDIAGNOSTICCHAIN_EMAP);
	m_objectFlow_EOperation_is_multicast_or_is_multireceive_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_objectFlow_EClass, OBJECTFLOW_EOPERATION_IS_MULTICAST_OR_IS_MULTIRECEIVE_EDIAGNOSTICCHAIN_EMAP);
	m_objectFlow_EOperation_no_executable_nodes_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_objectFlow_EClass, OBJECTFLOW_EOPERATION_NO_EXECUTABLE_NODES_EDIAGNOSTICCHAIN_EMAP);
	m_objectFlow_EOperation_same_upper_bounds_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_objectFlow_EClass, OBJECTFLOW_EOPERATION_SAME_UPPER_BOUNDS_EDIAGNOSTICCHAIN_EMAP);
	m_objectFlow_EOperation_selection_behavior_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_objectFlow_EClass, OBJECTFLOW_EOPERATION_SELECTION_BEHAVIOR_EDIAGNOSTICCHAIN_EMAP);
	m_objectFlow_EOperation_target_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_objectFlow_EClass, OBJECTFLOW_EOPERATION_TARGET_EDIAGNOSTICCHAIN_EMAP);
	m_objectFlow_EOperation_transformation_behavior_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_objectFlow_EClass, OBJECTFLOW_EOPERATION_TRANSFORMATION_BEHAVIOR_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createObjectNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_objectNode_EClass = factory->createEClass_in_EPackage(package, OBJECTNODE_ECLASS);
	m_objectNode_EAttribute_isControlType = factory->createEAttribute_in_EContainingClass(m_objectNode_EClass, OBJECTNODE_EATTRIBUTE_ISCONTROLTYPE);
	m_objectNode_EAttribute_ordering = factory->createEAttribute_in_EContainingClass(m_objectNode_EClass, OBJECTNODE_EATTRIBUTE_ORDERING);
	
	m_objectNode_EReference_inState = factory->createEReference_in_EContainingClass(m_objectNode_EClass, OBJECTNODE_EREFERENCE_INSTATE);
	m_objectNode_EReference_selection = factory->createEReference_in_EContainingClass(m_objectNode_EClass, OBJECTNODE_EREFERENCE_SELECTION);
	m_objectNode_EReference_upperBound = factory->createEReference_in_EContainingClass(m_objectNode_EClass, OBJECTNODE_EREFERENCE_UPPERBOUND);
	
	m_objectNode_EOperation_input_output_parameter_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_objectNode_EClass, OBJECTNODE_EOPERATION_INPUT_OUTPUT_PARAMETER_EDIAGNOSTICCHAIN_EMAP);
	m_objectNode_EOperation_object_flow_edges_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_objectNode_EClass, OBJECTNODE_EOPERATION_OBJECT_FLOW_EDGES_EDIAGNOSTICCHAIN_EMAP);
	m_objectNode_EOperation_selection_behavior_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_objectNode_EClass, OBJECTNODE_EOPERATION_SELECTION_BEHAVIOR_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createObservationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_observation_EClass = factory->createEClass_in_EPackage(package, OBSERVATION_ECLASS);
	
	
	
}

void UmlPackageImpl::createOccurrenceSpecificationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_occurrenceSpecification_EClass = factory->createEClass_in_EPackage(package, OCCURRENCESPECIFICATION_ECLASS);
	
	m_occurrenceSpecification_EReference_toAfter = factory->createEReference_in_EContainingClass(m_occurrenceSpecification_EClass, OCCURRENCESPECIFICATION_EREFERENCE_TOAFTER);
	m_occurrenceSpecification_EReference_toBefore = factory->createEReference_in_EContainingClass(m_occurrenceSpecification_EClass, OCCURRENCESPECIFICATION_EREFERENCE_TOBEFORE);
	
	m_occurrenceSpecification_EOperation_getCovered = factory->createEOperation_in_EContainingClass(m_occurrenceSpecification_EClass, OCCURRENCESPECIFICATION_EOPERATION_GETCOVERED);
	m_occurrenceSpecification_EOperation_setCovered_Lifeline = factory->createEOperation_in_EContainingClass(m_occurrenceSpecification_EClass, OCCURRENCESPECIFICATION_EOPERATION_SETCOVERED_LIFELINE);
	
}

void UmlPackageImpl::createOpaqueActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_opaqueAction_EClass = factory->createEClass_in_EPackage(package, OPAQUEACTION_ECLASS);
	m_opaqueAction_EAttribute_body = factory->createEAttribute_in_EContainingClass(m_opaqueAction_EClass, OPAQUEACTION_EATTRIBUTE_BODY);
	m_opaqueAction_EAttribute_language = factory->createEAttribute_in_EContainingClass(m_opaqueAction_EClass, OPAQUEACTION_EATTRIBUTE_LANGUAGE);
	
	m_opaqueAction_EReference_inputValue = factory->createEReference_in_EContainingClass(m_opaqueAction_EClass, OPAQUEACTION_EREFERENCE_INPUTVALUE);
	m_opaqueAction_EReference_outputValue = factory->createEReference_in_EContainingClass(m_opaqueAction_EClass, OPAQUEACTION_EREFERENCE_OUTPUTVALUE);
	
	m_opaqueAction_EOperation_language_body_size_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_opaqueAction_EClass, OPAQUEACTION_EOPERATION_LANGUAGE_BODY_SIZE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createOpaqueBehaviorContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_opaqueBehavior_EClass = factory->createEClass_in_EPackage(package, OPAQUEBEHAVIOR_ECLASS);
	m_opaqueBehavior_EAttribute_body = factory->createEAttribute_in_EContainingClass(m_opaqueBehavior_EClass, OPAQUEBEHAVIOR_EATTRIBUTE_BODY);
	m_opaqueBehavior_EAttribute_language = factory->createEAttribute_in_EContainingClass(m_opaqueBehavior_EClass, OPAQUEBEHAVIOR_EATTRIBUTE_LANGUAGE);
	
	
	
}

void UmlPackageImpl::createOpaqueExpressionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_opaqueExpression_EClass = factory->createEClass_in_EPackage(package, OPAQUEEXPRESSION_ECLASS);
	m_opaqueExpression_EAttribute_body = factory->createEAttribute_in_EContainingClass(m_opaqueExpression_EClass, OPAQUEEXPRESSION_EATTRIBUTE_BODY);
	m_opaqueExpression_EAttribute_language = factory->createEAttribute_in_EContainingClass(m_opaqueExpression_EClass, OPAQUEEXPRESSION_EATTRIBUTE_LANGUAGE);
	
	m_opaqueExpression_EReference_behavior = factory->createEReference_in_EContainingClass(m_opaqueExpression_EClass, OPAQUEEXPRESSION_EREFERENCE_BEHAVIOR);
	m_opaqueExpression_EReference_result = factory->createEReference_in_EContainingClass(m_opaqueExpression_EClass, OPAQUEEXPRESSION_EREFERENCE_RESULT);
	
	m_opaqueExpression_EOperation_getResult = factory->createEOperation_in_EContainingClass(m_opaqueExpression_EClass, OPAQUEEXPRESSION_EOPERATION_GETRESULT);
	m_opaqueExpression_EOperation_isIntegral = factory->createEOperation_in_EContainingClass(m_opaqueExpression_EClass, OPAQUEEXPRESSION_EOPERATION_ISINTEGRAL);
	m_opaqueExpression_EOperation_isNonNegative = factory->createEOperation_in_EContainingClass(m_opaqueExpression_EClass, OPAQUEEXPRESSION_EOPERATION_ISNONNEGATIVE);
	m_opaqueExpression_EOperation_isPositive = factory->createEOperation_in_EContainingClass(m_opaqueExpression_EClass, OPAQUEEXPRESSION_EOPERATION_ISPOSITIVE);
	m_opaqueExpression_EOperation_language_body_size_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_opaqueExpression_EClass, OPAQUEEXPRESSION_EOPERATION_LANGUAGE_BODY_SIZE_EDIAGNOSTICCHAIN_EMAP);
	m_opaqueExpression_EOperation_one_return_result_parameter_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_opaqueExpression_EClass, OPAQUEEXPRESSION_EOPERATION_ONE_RETURN_RESULT_PARAMETER_EDIAGNOSTICCHAIN_EMAP);
	m_opaqueExpression_EOperation_only_return_result_parameters_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_opaqueExpression_EClass, OPAQUEEXPRESSION_EOPERATION_ONLY_RETURN_RESULT_PARAMETERS_EDIAGNOSTICCHAIN_EMAP);
	m_opaqueExpression_EOperation_value = factory->createEOperation_in_EContainingClass(m_opaqueExpression_EClass, OPAQUEEXPRESSION_EOPERATION_VALUE);
	
}

void UmlPackageImpl::createOperationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_operation_EClass = factory->createEClass_in_EPackage(package, OPERATION_ECLASS);
	m_operation_EAttribute_isOrdered = factory->createEAttribute_in_EContainingClass(m_operation_EClass, OPERATION_EATTRIBUTE_ISORDERED);
	m_operation_EAttribute_isQuery = factory->createEAttribute_in_EContainingClass(m_operation_EClass, OPERATION_EATTRIBUTE_ISQUERY);
	m_operation_EAttribute_isUnique = factory->createEAttribute_in_EContainingClass(m_operation_EClass, OPERATION_EATTRIBUTE_ISUNIQUE);
	m_operation_EAttribute_lower = factory->createEAttribute_in_EContainingClass(m_operation_EClass, OPERATION_EATTRIBUTE_LOWER);
	m_operation_EAttribute_upper = factory->createEAttribute_in_EContainingClass(m_operation_EClass, OPERATION_EATTRIBUTE_UPPER);
	
	m_operation_EReference_bodyCondition = factory->createEReference_in_EContainingClass(m_operation_EClass, OPERATION_EREFERENCE_BODYCONDITION);
	m_operation_EReference_class = factory->createEReference_in_EContainingClass(m_operation_EClass, OPERATION_EREFERENCE_CLASS);
	m_operation_EReference_datatype = factory->createEReference_in_EContainingClass(m_operation_EClass, OPERATION_EREFERENCE_DATATYPE);
	m_operation_EReference_interface = factory->createEReference_in_EContainingClass(m_operation_EClass, OPERATION_EREFERENCE_INTERFACE);
	m_operation_EReference_postcondition = factory->createEReference_in_EContainingClass(m_operation_EClass, OPERATION_EREFERENCE_POSTCONDITION);
	m_operation_EReference_precondition = factory->createEReference_in_EContainingClass(m_operation_EClass, OPERATION_EREFERENCE_PRECONDITION);
	m_operation_EReference_redefinedOperation = factory->createEReference_in_EContainingClass(m_operation_EClass, OPERATION_EREFERENCE_REDEFINEDOPERATION);
	m_operation_EReference_type = factory->createEReference_in_EContainingClass(m_operation_EClass, OPERATION_EREFERENCE_TYPE);
	
	m_operation_EOperation_at_most_one_return_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_operation_EClass, OPERATION_EOPERATION_AT_MOST_ONE_RETURN_EDIAGNOSTICCHAIN_EMAP);
	m_operation_EOperation_getLower = factory->createEOperation_in_EContainingClass(m_operation_EClass, OPERATION_EOPERATION_GETLOWER);
	m_operation_EOperation_getReturnResult = factory->createEOperation_in_EContainingClass(m_operation_EClass, OPERATION_EOPERATION_GETRETURNRESULT);
	m_operation_EOperation_getType = factory->createEOperation_in_EContainingClass(m_operation_EClass, OPERATION_EOPERATION_GETTYPE);
	m_operation_EOperation_getUpper = factory->createEOperation_in_EContainingClass(m_operation_EClass, OPERATION_EOPERATION_GETUPPER);
	m_operation_EOperation_isOrdered = factory->createEOperation_in_EContainingClass(m_operation_EClass, OPERATION_EOPERATION_ISORDERED);
	m_operation_EOperation_isUnique = factory->createEOperation_in_EContainingClass(m_operation_EClass, OPERATION_EOPERATION_ISUNIQUE);
	m_operation_EOperation_only_body_for_query_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_operation_EClass, OPERATION_EOPERATION_ONLY_BODY_FOR_QUERY_EDIAGNOSTICCHAIN_EMAP);
	m_operation_EOperation_returnResult = factory->createEOperation_in_EContainingClass(m_operation_EClass, OPERATION_EOPERATION_RETURNRESULT);
	m_operation_EOperation_setIsOrdered_Boolean = factory->createEOperation_in_EContainingClass(m_operation_EClass, OPERATION_EOPERATION_SETISORDERED_BOOLEAN);
	m_operation_EOperation_setIsUnique_Boolean = factory->createEOperation_in_EContainingClass(m_operation_EClass, OPERATION_EOPERATION_SETISUNIQUE_BOOLEAN);
	m_operation_EOperation_setLower_Integer = factory->createEOperation_in_EContainingClass(m_operation_EClass, OPERATION_EOPERATION_SETLOWER_INTEGER);
	m_operation_EOperation_setType_Type = factory->createEOperation_in_EContainingClass(m_operation_EClass, OPERATION_EOPERATION_SETTYPE_TYPE);
	m_operation_EOperation_setUpper_UnlimitedNatural = factory->createEOperation_in_EContainingClass(m_operation_EClass, OPERATION_EOPERATION_SETUPPER_UNLIMITEDNATURAL);
	
}

void UmlPackageImpl::createOperationTemplateParameterContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_operationTemplateParameter_EClass = factory->createEClass_in_EPackage(package, OPERATIONTEMPLATEPARAMETER_ECLASS);
	
	
	m_operationTemplateParameter_EOperation_match_default_signature_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_operationTemplateParameter_EClass, OPERATIONTEMPLATEPARAMETER_EOPERATION_MATCH_DEFAULT_SIGNATURE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createOutputPinContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_outputPin_EClass = factory->createEClass_in_EPackage(package, OUTPUTPIN_ECLASS);
	
	m_outputPin_EReference_action = factory->createEReference_in_EContainingClass(m_outputPin_EClass, OUTPUTPIN_EREFERENCE_ACTION);
	m_outputPin_EReference_callAction = factory->createEReference_in_EContainingClass(m_outputPin_EClass, OUTPUTPIN_EREFERENCE_CALLACTION);
	
	m_outputPin_EOperation_incoming_edges_structured_only_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_outputPin_EClass, OUTPUTPIN_EOPERATION_INCOMING_EDGES_STRUCTURED_ONLY_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createPackageContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_package_EClass = factory->createEClass_in_EPackage(package, PACKAGE_ECLASS);
	m_package_EAttribute_uRI = factory->createEAttribute_in_EContainingClass(m_package_EClass, PACKAGE_EATTRIBUTE_URI);
	
	m_package_EReference_nestedPackage = factory->createEReference_in_EContainingClass(m_package_EClass, PACKAGE_EREFERENCE_NESTEDPACKAGE);
	m_package_EReference_nestingPackage = factory->createEReference_in_EContainingClass(m_package_EClass, PACKAGE_EREFERENCE_NESTINGPACKAGE);
	m_package_EReference_ownedStereotype = factory->createEReference_in_EContainingClass(m_package_EClass, PACKAGE_EREFERENCE_OWNEDSTEREOTYPE);
	m_package_EReference_ownedType = factory->createEReference_in_EContainingClass(m_package_EClass, PACKAGE_EREFERENCE_OWNEDTYPE);
	m_package_EReference_packageMerge = factory->createEReference_in_EContainingClass(m_package_EClass, PACKAGE_EREFERENCE_PACKAGEMERGE);
	m_package_EReference_packagedElement = factory->createEReference_in_EContainingClass(m_package_EClass, PACKAGE_EREFERENCE_PACKAGEDELEMENT);
	m_package_EReference_profileApplication = factory->createEReference_in_EContainingClass(m_package_EClass, PACKAGE_EREFERENCE_PROFILEAPPLICATION);
	
	m_package_EOperation_allApplicableStereotypes = factory->createEOperation_in_EContainingClass(m_package_EClass, PACKAGE_EOPERATION_ALLAPPLICABLESTEREOTYPES);
	m_package_EOperation_applyProfile_Profile = factory->createEOperation_in_EContainingClass(m_package_EClass, PACKAGE_EOPERATION_APPLYPROFILE_PROFILE);
	m_package_EOperation_containingProfile = factory->createEOperation_in_EContainingClass(m_package_EClass, PACKAGE_EOPERATION_CONTAININGPROFILE);
	m_package_EOperation_createOwnedClass_String_Boolean = factory->createEOperation_in_EContainingClass(m_package_EClass, PACKAGE_EOPERATION_CREATEOWNEDCLASS_STRING_BOOLEAN);
	m_package_EOperation_createOwnedEnumeration_String = factory->createEOperation_in_EContainingClass(m_package_EClass, PACKAGE_EOPERATION_CREATEOWNEDENUMERATION_STRING);
	m_package_EOperation_createOwnedInterface_String = factory->createEOperation_in_EContainingClass(m_package_EClass, PACKAGE_EOPERATION_CREATEOWNEDINTERFACE_STRING);
	m_package_EOperation_createOwnedPrimitiveType_String = factory->createEOperation_in_EContainingClass(m_package_EClass, PACKAGE_EOPERATION_CREATEOWNEDPRIMITIVETYPE_STRING);
	m_package_EOperation_createOwnedStereotype_String_Boolean = factory->createEOperation_in_EContainingClass(m_package_EClass, PACKAGE_EOPERATION_CREATEOWNEDSTEREOTYPE_STRING_BOOLEAN);
	m_package_EOperation_elements_public_or_private_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_package_EClass, PACKAGE_EOPERATION_ELEMENTS_PUBLIC_OR_PRIVATE_EDIAGNOSTICCHAIN_EMAP);
	m_package_EOperation_getAllAppliedProfiles = factory->createEOperation_in_EContainingClass(m_package_EClass, PACKAGE_EOPERATION_GETALLAPPLIEDPROFILES);
	m_package_EOperation_getAllProfileApplications = factory->createEOperation_in_EContainingClass(m_package_EClass, PACKAGE_EOPERATION_GETALLPROFILEAPPLICATIONS);
	m_package_EOperation_getAppliedProfile_String = factory->createEOperation_in_EContainingClass(m_package_EClass, PACKAGE_EOPERATION_GETAPPLIEDPROFILE_STRING);
	m_package_EOperation_getAppliedProfile_String_Boolean = factory->createEOperation_in_EContainingClass(m_package_EClass, PACKAGE_EOPERATION_GETAPPLIEDPROFILE_STRING_BOOLEAN);
	m_package_EOperation_getAppliedProfiles = factory->createEOperation_in_EContainingClass(m_package_EClass, PACKAGE_EOPERATION_GETAPPLIEDPROFILES);
	m_package_EOperation_getNestedPackages = factory->createEOperation_in_EContainingClass(m_package_EClass, PACKAGE_EOPERATION_GETNESTEDPACKAGES);
	m_package_EOperation_getOwnedStereotypes = factory->createEOperation_in_EContainingClass(m_package_EClass, PACKAGE_EOPERATION_GETOWNEDSTEREOTYPES);
	m_package_EOperation_getOwnedTypes = factory->createEOperation_in_EContainingClass(m_package_EClass, PACKAGE_EOPERATION_GETOWNEDTYPES);
	m_package_EOperation_getProfileApplication_Profile = factory->createEOperation_in_EContainingClass(m_package_EClass, PACKAGE_EOPERATION_GETPROFILEAPPLICATION_PROFILE);
	m_package_EOperation_getProfileApplication_Profile_Boolean = factory->createEOperation_in_EContainingClass(m_package_EClass, PACKAGE_EOPERATION_GETPROFILEAPPLICATION_PROFILE_BOOLEAN);
	m_package_EOperation_isModelLibrary = factory->createEOperation_in_EContainingClass(m_package_EClass, PACKAGE_EOPERATION_ISMODELLIBRARY);
	m_package_EOperation_isProfileApplied_Profile = factory->createEOperation_in_EContainingClass(m_package_EClass, PACKAGE_EOPERATION_ISPROFILEAPPLIED_PROFILE);
	m_package_EOperation_makesVisible_NamedElement = factory->createEOperation_in_EContainingClass(m_package_EClass, PACKAGE_EOPERATION_MAKESVISIBLE_NAMEDELEMENT);
	m_package_EOperation_unapplyProfile_Profile = factory->createEOperation_in_EContainingClass(m_package_EClass, PACKAGE_EOPERATION_UNAPPLYPROFILE_PROFILE);
	m_package_EOperation_visibleMembers = factory->createEOperation_in_EContainingClass(m_package_EClass, PACKAGE_EOPERATION_VISIBLEMEMBERS);
	
}

void UmlPackageImpl::createPackageImportContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_packageImport_EClass = factory->createEClass_in_EPackage(package, PACKAGEIMPORT_ECLASS);
	m_packageImport_EAttribute_visibility = factory->createEAttribute_in_EContainingClass(m_packageImport_EClass, PACKAGEIMPORT_EATTRIBUTE_VISIBILITY);
	
	m_packageImport_EReference_importedPackage = factory->createEReference_in_EContainingClass(m_packageImport_EClass, PACKAGEIMPORT_EREFERENCE_IMPORTEDPACKAGE);
	m_packageImport_EReference_importingNamespace = factory->createEReference_in_EContainingClass(m_packageImport_EClass, PACKAGEIMPORT_EREFERENCE_IMPORTINGNAMESPACE);
	
	m_packageImport_EOperation_public_or_private_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_packageImport_EClass, PACKAGEIMPORT_EOPERATION_PUBLIC_OR_PRIVATE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createPackageMergeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_packageMerge_EClass = factory->createEClass_in_EPackage(package, PACKAGEMERGE_ECLASS);
	
	m_packageMerge_EReference_mergedPackage = factory->createEReference_in_EContainingClass(m_packageMerge_EClass, PACKAGEMERGE_EREFERENCE_MERGEDPACKAGE);
	m_packageMerge_EReference_receivingPackage = factory->createEReference_in_EContainingClass(m_packageMerge_EClass, PACKAGEMERGE_EREFERENCE_RECEIVINGPACKAGE);
	
	
}

void UmlPackageImpl::createPackageableElementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_packageableElement_EClass = factory->createEClass_in_EPackage(package, PACKAGEABLEELEMENT_ECLASS);
	
	m_packageableElement_EReference_owningPackage = factory->createEReference_in_EContainingClass(m_packageableElement_EClass, PACKAGEABLEELEMENT_EREFERENCE_OWNINGPACKAGE);
	
	m_packageableElement_EOperation_namespace_needs_visibility_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_packageableElement_EClass, PACKAGEABLEELEMENT_EOPERATION_NAMESPACE_NEEDS_VISIBILITY_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createParameterContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_parameter_EClass = factory->createEClass_in_EPackage(package, PARAMETER_ECLASS);
	m_parameter_EAttribute_default = factory->createEAttribute_in_EContainingClass(m_parameter_EClass, PARAMETER_EATTRIBUTE_DEFAULT);
	m_parameter_EAttribute_direction = factory->createEAttribute_in_EContainingClass(m_parameter_EClass, PARAMETER_EATTRIBUTE_DIRECTION);
	m_parameter_EAttribute_effect = factory->createEAttribute_in_EContainingClass(m_parameter_EClass, PARAMETER_EATTRIBUTE_EFFECT);
	m_parameter_EAttribute_isException = factory->createEAttribute_in_EContainingClass(m_parameter_EClass, PARAMETER_EATTRIBUTE_ISEXCEPTION);
	m_parameter_EAttribute_isStream = factory->createEAttribute_in_EContainingClass(m_parameter_EClass, PARAMETER_EATTRIBUTE_ISSTREAM);
	
	m_parameter_EReference_behavior = factory->createEReference_in_EContainingClass(m_parameter_EClass, PARAMETER_EREFERENCE_BEHAVIOR);
	m_parameter_EReference_defaultValue = factory->createEReference_in_EContainingClass(m_parameter_EClass, PARAMETER_EREFERENCE_DEFAULTVALUE);
	m_parameter_EReference_operation = factory->createEReference_in_EContainingClass(m_parameter_EClass, PARAMETER_EREFERENCE_OPERATION);
	m_parameter_EReference_parameterSet = factory->createEReference_in_EContainingClass(m_parameter_EClass, PARAMETER_EREFERENCE_PARAMETERSET);
	
	m_parameter_EOperation_connector_end_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_parameter_EClass, PARAMETER_EOPERATION_CONNECTOR_END_EDIAGNOSTICCHAIN_EMAP);
	m_parameter_EOperation_in_and_out_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_parameter_EClass, PARAMETER_EOPERATION_IN_AND_OUT_EDIAGNOSTICCHAIN_EMAP);
	m_parameter_EOperation_isSetDefault = factory->createEOperation_in_EContainingClass(m_parameter_EClass, PARAMETER_EOPERATION_ISSETDEFAULT);
	m_parameter_EOperation_not_exception_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_parameter_EClass, PARAMETER_EOPERATION_NOT_EXCEPTION_EDIAGNOSTICCHAIN_EMAP);
	m_parameter_EOperation_object_effect_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_parameter_EClass, PARAMETER_EOPERATION_OBJECT_EFFECT_EDIAGNOSTICCHAIN_EMAP);
	m_parameter_EOperation_reentrant_behaviors_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_parameter_EClass, PARAMETER_EOPERATION_REENTRANT_BEHAVIORS_EDIAGNOSTICCHAIN_EMAP);
	m_parameter_EOperation_setBooleanDefaultValue_Boolean = factory->createEOperation_in_EContainingClass(m_parameter_EClass, PARAMETER_EOPERATION_SETBOOLEANDEFAULTVALUE_BOOLEAN);
	m_parameter_EOperation_setIntegerDefaultValue_Integer = factory->createEOperation_in_EContainingClass(m_parameter_EClass, PARAMETER_EOPERATION_SETINTEGERDEFAULTVALUE_INTEGER);
	m_parameter_EOperation_setNullDefaultValue = factory->createEOperation_in_EContainingClass(m_parameter_EClass, PARAMETER_EOPERATION_SETNULLDEFAULTVALUE);
	m_parameter_EOperation_setRealDefaultValue_Real = factory->createEOperation_in_EContainingClass(m_parameter_EClass, PARAMETER_EOPERATION_SETREALDEFAULTVALUE_REAL);
	m_parameter_EOperation_setStringDefaultValue_String = factory->createEOperation_in_EContainingClass(m_parameter_EClass, PARAMETER_EOPERATION_SETSTRINGDEFAULTVALUE_STRING);
	m_parameter_EOperation_setUnlimitedNaturalDefaultValue_UnlimitedNatural = factory->createEOperation_in_EContainingClass(m_parameter_EClass, PARAMETER_EOPERATION_SETUNLIMITEDNATURALDEFAULTVALUE_UNLIMITEDNATURAL);
	m_parameter_EOperation_stream_and_exception_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_parameter_EClass, PARAMETER_EOPERATION_STREAM_AND_EXCEPTION_EDIAGNOSTICCHAIN_EMAP);
	m_parameter_EOperation_unsetDefault = factory->createEOperation_in_EContainingClass(m_parameter_EClass, PARAMETER_EOPERATION_UNSETDEFAULT);
	
}

void UmlPackageImpl::createParameterSetContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_parameterSet_EClass = factory->createEClass_in_EPackage(package, PARAMETERSET_ECLASS);
	
	m_parameterSet_EReference_condition = factory->createEReference_in_EContainingClass(m_parameterSet_EClass, PARAMETERSET_EREFERENCE_CONDITION);
	m_parameterSet_EReference_parameter = factory->createEReference_in_EContainingClass(m_parameterSet_EClass, PARAMETERSET_EREFERENCE_PARAMETER);
	
	m_parameterSet_EOperation_input_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_parameterSet_EClass, PARAMETERSET_EOPERATION_INPUT_EDIAGNOSTICCHAIN_EMAP);
	m_parameterSet_EOperation_same_parameterized_entity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_parameterSet_EClass, PARAMETERSET_EOPERATION_SAME_PARAMETERIZED_ENTITY_EDIAGNOSTICCHAIN_EMAP);
	m_parameterSet_EOperation_two_parameter_sets_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_parameterSet_EClass, PARAMETERSET_EOPERATION_TWO_PARAMETER_SETS_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createParameterableElementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_parameterableElement_EClass = factory->createEClass_in_EPackage(package, PARAMETERABLEELEMENT_ECLASS);
	
	m_parameterableElement_EReference_owningTemplateParameter = factory->createEReference_in_EContainingClass(m_parameterableElement_EClass, PARAMETERABLEELEMENT_EREFERENCE_OWNINGTEMPLATEPARAMETER);
	m_parameterableElement_EReference_templateParameter = factory->createEReference_in_EContainingClass(m_parameterableElement_EClass, PARAMETERABLEELEMENT_EREFERENCE_TEMPLATEPARAMETER);
	
	m_parameterableElement_EOperation_isCompatibleWith_ParameterableElement = factory->createEOperation_in_EContainingClass(m_parameterableElement_EClass, PARAMETERABLEELEMENT_EOPERATION_ISCOMPATIBLEWITH_PARAMETERABLEELEMENT);
	m_parameterableElement_EOperation_isTemplateParameter = factory->createEOperation_in_EContainingClass(m_parameterableElement_EClass, PARAMETERABLEELEMENT_EOPERATION_ISTEMPLATEPARAMETER);
	
}

void UmlPackageImpl::createPartDecompositionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_partDecomposition_EClass = factory->createEClass_in_EPackage(package, PARTDECOMPOSITION_ECLASS);
	
	
	m_partDecomposition_EOperation_assume_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_partDecomposition_EClass, PARTDECOMPOSITION_EOPERATION_ASSUME_EDIAGNOSTICCHAIN_EMAP);
	m_partDecomposition_EOperation_commutativity_of_decomposition_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_partDecomposition_EClass, PARTDECOMPOSITION_EOPERATION_COMMUTATIVITY_OF_DECOMPOSITION_EDIAGNOSTICCHAIN_EMAP);
	m_partDecomposition_EOperation_parts_of_internal_structures_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_partDecomposition_EClass, PARTDECOMPOSITION_EOPERATION_PARTS_OF_INTERNAL_STRUCTURES_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createPinContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_pin_EClass = factory->createEClass_in_EPackage(package, PIN_ECLASS);
	m_pin_EAttribute_isControl = factory->createEAttribute_in_EContainingClass(m_pin_EClass, PIN_EATTRIBUTE_ISCONTROL);
	
	
	m_pin_EOperation_control_pins_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_pin_EClass, PIN_EOPERATION_CONTROL_PINS_EDIAGNOSTICCHAIN_EMAP);
	m_pin_EOperation_not_unique_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_pin_EClass, PIN_EOPERATION_NOT_UNIQUE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createPortContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_port_EClass = factory->createEClass_in_EPackage(package, PORT_ECLASS);
	m_port_EAttribute_isBehavior = factory->createEAttribute_in_EContainingClass(m_port_EClass, PORT_EATTRIBUTE_ISBEHAVIOR);
	m_port_EAttribute_isConjugated = factory->createEAttribute_in_EContainingClass(m_port_EClass, PORT_EATTRIBUTE_ISCONJUGATED);
	m_port_EAttribute_isService = factory->createEAttribute_in_EContainingClass(m_port_EClass, PORT_EATTRIBUTE_ISSERVICE);
	
	m_port_EReference_protocol = factory->createEReference_in_EContainingClass(m_port_EClass, PORT_EREFERENCE_PROTOCOL);
	m_port_EReference_provided = factory->createEReference_in_EContainingClass(m_port_EClass, PORT_EREFERENCE_PROVIDED);
	m_port_EReference_redefinedPort = factory->createEReference_in_EContainingClass(m_port_EClass, PORT_EREFERENCE_REDEFINEDPORT);
	m_port_EReference_required = factory->createEReference_in_EContainingClass(m_port_EClass, PORT_EREFERENCE_REQUIRED);
	
	m_port_EOperation_basicProvided = factory->createEOperation_in_EContainingClass(m_port_EClass, PORT_EOPERATION_BASICPROVIDED);
	m_port_EOperation_basicRequired = factory->createEOperation_in_EContainingClass(m_port_EClass, PORT_EOPERATION_BASICREQUIRED);
	m_port_EOperation_default_value_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_port_EClass, PORT_EOPERATION_DEFAULT_VALUE_EDIAGNOSTICCHAIN_EMAP);
	m_port_EOperation_encapsulated_owner_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_port_EClass, PORT_EOPERATION_ENCAPSULATED_OWNER_EDIAGNOSTICCHAIN_EMAP);
	m_port_EOperation_getProvideds = factory->createEOperation_in_EContainingClass(m_port_EClass, PORT_EOPERATION_GETPROVIDEDS);
	m_port_EOperation_getRequireds = factory->createEOperation_in_EContainingClass(m_port_EClass, PORT_EOPERATION_GETREQUIREDS);
	m_port_EOperation_port_aggregation_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_port_EClass, PORT_EOPERATION_PORT_AGGREGATION_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createPrimitiveTypeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_primitiveType_EClass = factory->createEClass_in_EPackage(package, PRIMITIVETYPE_ECLASS);
	
	
	
}

void UmlPackageImpl::createProfileContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_profile_EClass = factory->createEClass_in_EPackage(package, PROFILE_ECLASS);
	
	m_profile_EReference_metaclassReference = factory->createEReference_in_EContainingClass(m_profile_EClass, PROFILE_EREFERENCE_METACLASSREFERENCE);
	m_profile_EReference_metamodelReference = factory->createEReference_in_EContainingClass(m_profile_EClass, PROFILE_EREFERENCE_METAMODELREFERENCE);
	
	m_profile_EOperation_create_Classifier = factory->createEOperation_in_EContainingClass(m_profile_EClass, PROFILE_EOPERATION_CREATE_CLASSIFIER);
	m_profile_EOperation_define = factory->createEOperation_in_EContainingClass(m_profile_EClass, PROFILE_EOPERATION_DEFINE);
	m_profile_EOperation_define_EMap_EMap = factory->createEOperation_in_EContainingClass(m_profile_EClass, PROFILE_EOPERATION_DEFINE_EMAP_EMAP);
	m_profile_EOperation_getDefinition = factory->createEOperation_in_EContainingClass(m_profile_EClass, PROFILE_EOPERATION_GETDEFINITION);
	m_profile_EOperation_getDefinition_NamedElement = factory->createEOperation_in_EContainingClass(m_profile_EClass, PROFILE_EOPERATION_GETDEFINITION_NAMEDELEMENT);
	m_profile_EOperation_getOwnedExtensions_Boolean = factory->createEOperation_in_EContainingClass(m_profile_EClass, PROFILE_EOPERATION_GETOWNEDEXTENSIONS_BOOLEAN);
	m_profile_EOperation_getReferencedMetaclasses = factory->createEOperation_in_EContainingClass(m_profile_EClass, PROFILE_EOPERATION_GETREFERENCEDMETACLASSES);
	m_profile_EOperation_getReferencedMetamodels = factory->createEOperation_in_EContainingClass(m_profile_EClass, PROFILE_EOPERATION_GETREFERENCEDMETAMODELS);
	m_profile_EOperation_isDefined = factory->createEOperation_in_EContainingClass(m_profile_EClass, PROFILE_EOPERATION_ISDEFINED);
	m_profile_EOperation_metaclass_reference_not_specialized_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_profile_EClass, PROFILE_EOPERATION_METACLASS_REFERENCE_NOT_SPECIALIZED_EDIAGNOSTICCHAIN_EMAP);
	m_profile_EOperation_references_same_metamodel_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_profile_EClass, PROFILE_EOPERATION_REFERENCES_SAME_METAMODEL_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createProfileApplicationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_profileApplication_EClass = factory->createEClass_in_EPackage(package, PROFILEAPPLICATION_ECLASS);
	m_profileApplication_EAttribute_isStrict = factory->createEAttribute_in_EContainingClass(m_profileApplication_EClass, PROFILEAPPLICATION_EATTRIBUTE_ISSTRICT);
	
	m_profileApplication_EReference_appliedProfile = factory->createEReference_in_EContainingClass(m_profileApplication_EClass, PROFILEAPPLICATION_EREFERENCE_APPLIEDPROFILE);
	m_profileApplication_EReference_applyingPackage = factory->createEReference_in_EContainingClass(m_profileApplication_EClass, PROFILEAPPLICATION_EREFERENCE_APPLYINGPACKAGE);
	
	m_profileApplication_EOperation_getAppliedDefinition = factory->createEOperation_in_EContainingClass(m_profileApplication_EClass, PROFILEAPPLICATION_EOPERATION_GETAPPLIEDDEFINITION);
	m_profileApplication_EOperation_getAppliedDefinition_NamedElement = factory->createEOperation_in_EContainingClass(m_profileApplication_EClass, PROFILEAPPLICATION_EOPERATION_GETAPPLIEDDEFINITION_NAMEDELEMENT);
	
}

void UmlPackageImpl::createPropertyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_property_EClass = factory->createEClass_in_EPackage(package, PROPERTY_ECLASS);
	m_property_EAttribute_aggregation = factory->createEAttribute_in_EContainingClass(m_property_EClass, PROPERTY_EATTRIBUTE_AGGREGATION);
	m_property_EAttribute_default = factory->createEAttribute_in_EContainingClass(m_property_EClass, PROPERTY_EATTRIBUTE_DEFAULT);
	m_property_EAttribute_isComposite = factory->createEAttribute_in_EContainingClass(m_property_EClass, PROPERTY_EATTRIBUTE_ISCOMPOSITE);
	m_property_EAttribute_isDerived = factory->createEAttribute_in_EContainingClass(m_property_EClass, PROPERTY_EATTRIBUTE_ISDERIVED);
	m_property_EAttribute_isDerivedUnion = factory->createEAttribute_in_EContainingClass(m_property_EClass, PROPERTY_EATTRIBUTE_ISDERIVEDUNION);
	m_property_EAttribute_isID = factory->createEAttribute_in_EContainingClass(m_property_EClass, PROPERTY_EATTRIBUTE_ISID);
	
	m_property_EReference_association = factory->createEReference_in_EContainingClass(m_property_EClass, PROPERTY_EREFERENCE_ASSOCIATION);
	m_property_EReference_associationEnd = factory->createEReference_in_EContainingClass(m_property_EClass, PROPERTY_EREFERENCE_ASSOCIATIONEND);
	m_property_EReference_class = factory->createEReference_in_EContainingClass(m_property_EClass, PROPERTY_EREFERENCE_CLASS);
	m_property_EReference_datatype = factory->createEReference_in_EContainingClass(m_property_EClass, PROPERTY_EREFERENCE_DATATYPE);
	m_property_EReference_defaultValue = factory->createEReference_in_EContainingClass(m_property_EClass, PROPERTY_EREFERENCE_DEFAULTVALUE);
	m_property_EReference_interface = factory->createEReference_in_EContainingClass(m_property_EClass, PROPERTY_EREFERENCE_INTERFACE);
	m_property_EReference_opposite = factory->createEReference_in_EContainingClass(m_property_EClass, PROPERTY_EREFERENCE_OPPOSITE);
	m_property_EReference_owningAssociation = factory->createEReference_in_EContainingClass(m_property_EClass, PROPERTY_EREFERENCE_OWNINGASSOCIATION);
	m_property_EReference_qualifier = factory->createEReference_in_EContainingClass(m_property_EClass, PROPERTY_EREFERENCE_QUALIFIER);
	m_property_EReference_redefinedProperty = factory->createEReference_in_EContainingClass(m_property_EClass, PROPERTY_EREFERENCE_REDEFINEDPROPERTY);
	m_property_EReference_subsettedProperty = factory->createEReference_in_EContainingClass(m_property_EClass, PROPERTY_EREFERENCE_SUBSETTEDPROPERTY);
	
	m_property_EOperation_binding_to_attribute_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_property_EClass, PROPERTY_EOPERATION_BINDING_TO_ATTRIBUTE_EDIAGNOSTICCHAIN_EMAP);
	m_property_EOperation_deployment_target_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_property_EClass, PROPERTY_EOPERATION_DEPLOYMENT_TARGET_EDIAGNOSTICCHAIN_EMAP);
	m_property_EOperation_derived_union_is_derived_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_property_EClass, PROPERTY_EOPERATION_DERIVED_UNION_IS_DERIVED_EDIAGNOSTICCHAIN_EMAP);
	m_property_EOperation_derived_union_is_read_only_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_property_EClass, PROPERTY_EOPERATION_DERIVED_UNION_IS_READ_ONLY_EDIAGNOSTICCHAIN_EMAP);
	m_property_EOperation_getOpposite = factory->createEOperation_in_EContainingClass(m_property_EClass, PROPERTY_EOPERATION_GETOPPOSITE);
	m_property_EOperation_getOtherEnd = factory->createEOperation_in_EContainingClass(m_property_EClass, PROPERTY_EOPERATION_GETOTHEREND);
	m_property_EOperation_isAttribute = factory->createEOperation_in_EContainingClass(m_property_EClass, PROPERTY_EOPERATION_ISATTRIBUTE);
	m_property_EOperation_isComposite = factory->createEOperation_in_EContainingClass(m_property_EClass, PROPERTY_EOPERATION_ISCOMPOSITE);
	m_property_EOperation_isNavigable = factory->createEOperation_in_EContainingClass(m_property_EClass, PROPERTY_EOPERATION_ISNAVIGABLE);
	m_property_EOperation_isSetDefault = factory->createEOperation_in_EContainingClass(m_property_EClass, PROPERTY_EOPERATION_ISSETDEFAULT);
	m_property_EOperation_multiplicity_of_composite_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_property_EClass, PROPERTY_EOPERATION_MULTIPLICITY_OF_COMPOSITE_EDIAGNOSTICCHAIN_EMAP);
	m_property_EOperation_qualified_is_association_end_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_property_EClass, PROPERTY_EOPERATION_QUALIFIED_IS_ASSOCIATION_END_EDIAGNOSTICCHAIN_EMAP);
	m_property_EOperation_redefined_property_inherited_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_property_EClass, PROPERTY_EOPERATION_REDEFINED_PROPERTY_INHERITED_EDIAGNOSTICCHAIN_EMAP);
	m_property_EOperation_setBooleanDefaultValue_Boolean = factory->createEOperation_in_EContainingClass(m_property_EClass, PROPERTY_EOPERATION_SETBOOLEANDEFAULTVALUE_BOOLEAN);
	m_property_EOperation_setIntegerDefaultValue_Integer = factory->createEOperation_in_EContainingClass(m_property_EClass, PROPERTY_EOPERATION_SETINTEGERDEFAULTVALUE_INTEGER);
	m_property_EOperation_setIsNavigable_Boolean = factory->createEOperation_in_EContainingClass(m_property_EClass, PROPERTY_EOPERATION_SETISNAVIGABLE_BOOLEAN);
	m_property_EOperation_setNullDefaultValue = factory->createEOperation_in_EContainingClass(m_property_EClass, PROPERTY_EOPERATION_SETNULLDEFAULTVALUE);
	m_property_EOperation_setRealDefaultValue_Real = factory->createEOperation_in_EContainingClass(m_property_EClass, PROPERTY_EOPERATION_SETREALDEFAULTVALUE_REAL);
	m_property_EOperation_setStringDefaultValue_String = factory->createEOperation_in_EContainingClass(m_property_EClass, PROPERTY_EOPERATION_SETSTRINGDEFAULTVALUE_STRING);
	m_property_EOperation_setUnlimitedNaturalDefaultValue_UnlimitedNatural = factory->createEOperation_in_EContainingClass(m_property_EClass, PROPERTY_EOPERATION_SETUNLIMITEDNATURALDEFAULTVALUE_UNLIMITEDNATURAL);
	m_property_EOperation_subsetted_property_names_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_property_EClass, PROPERTY_EOPERATION_SUBSETTED_PROPERTY_NAMES_EDIAGNOSTICCHAIN_EMAP);
	m_property_EOperation_subsettingContext = factory->createEOperation_in_EContainingClass(m_property_EClass, PROPERTY_EOPERATION_SUBSETTINGCONTEXT);
	m_property_EOperation_subsetting_context_conforms_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_property_EClass, PROPERTY_EOPERATION_SUBSETTING_CONTEXT_CONFORMS_EDIAGNOSTICCHAIN_EMAP);
	m_property_EOperation_subsetting_rules_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_property_EClass, PROPERTY_EOPERATION_SUBSETTING_RULES_EDIAGNOSTICCHAIN_EMAP);
	m_property_EOperation_type_of_opposite_end_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_property_EClass, PROPERTY_EOPERATION_TYPE_OF_OPPOSITE_END_EDIAGNOSTICCHAIN_EMAP);
	m_property_EOperation_unsetDefault = factory->createEOperation_in_EContainingClass(m_property_EClass, PROPERTY_EOPERATION_UNSETDEFAULT);
	
}

void UmlPackageImpl::createProtocolConformanceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_protocolConformance_EClass = factory->createEClass_in_EPackage(package, PROTOCOLCONFORMANCE_ECLASS);
	
	m_protocolConformance_EReference_generalMachine = factory->createEReference_in_EContainingClass(m_protocolConformance_EClass, PROTOCOLCONFORMANCE_EREFERENCE_GENERALMACHINE);
	m_protocolConformance_EReference_specificMachine = factory->createEReference_in_EContainingClass(m_protocolConformance_EClass, PROTOCOLCONFORMANCE_EREFERENCE_SPECIFICMACHINE);
	
	
}

void UmlPackageImpl::createProtocolStateMachineContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_protocolStateMachine_EClass = factory->createEClass_in_EPackage(package, PROTOCOLSTATEMACHINE_ECLASS);
	
	m_protocolStateMachine_EReference_conformance = factory->createEReference_in_EContainingClass(m_protocolStateMachine_EClass, PROTOCOLSTATEMACHINE_EREFERENCE_CONFORMANCE);
	
	m_protocolStateMachine_EOperation_deep_or_shallow_history_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_protocolStateMachine_EClass, PROTOCOLSTATEMACHINE_EOPERATION_DEEP_OR_SHALLOW_HISTORY_EDIAGNOSTICCHAIN_EMAP);
	m_protocolStateMachine_EOperation_entry_exit_do_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_protocolStateMachine_EClass, PROTOCOLSTATEMACHINE_EOPERATION_ENTRY_EXIT_DO_EDIAGNOSTICCHAIN_EMAP);
	m_protocolStateMachine_EOperation_protocol_transitions_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_protocolStateMachine_EClass, PROTOCOLSTATEMACHINE_EOPERATION_PROTOCOL_TRANSITIONS_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createProtocolTransitionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_protocolTransition_EClass = factory->createEClass_in_EPackage(package, PROTOCOLTRANSITION_ECLASS);
	
	m_protocolTransition_EReference_postCondition = factory->createEReference_in_EContainingClass(m_protocolTransition_EClass, PROTOCOLTRANSITION_EREFERENCE_POSTCONDITION);
	m_protocolTransition_EReference_preCondition = factory->createEReference_in_EContainingClass(m_protocolTransition_EClass, PROTOCOLTRANSITION_EREFERENCE_PRECONDITION);
	m_protocolTransition_EReference_referred = factory->createEReference_in_EContainingClass(m_protocolTransition_EClass, PROTOCOLTRANSITION_EREFERENCE_REFERRED);
	
	m_protocolTransition_EOperation_associated_actions_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_protocolTransition_EClass, PROTOCOLTRANSITION_EOPERATION_ASSOCIATED_ACTIONS_EDIAGNOSTICCHAIN_EMAP);
	m_protocolTransition_EOperation_belongs_to_psm_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_protocolTransition_EClass, PROTOCOLTRANSITION_EOPERATION_BELONGS_TO_PSM_EDIAGNOSTICCHAIN_EMAP);
	m_protocolTransition_EOperation_getReferreds = factory->createEOperation_in_EContainingClass(m_protocolTransition_EClass, PROTOCOLTRANSITION_EOPERATION_GETREFERREDS);
	m_protocolTransition_EOperation_refers_to_operation_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_protocolTransition_EClass, PROTOCOLTRANSITION_EOPERATION_REFERS_TO_OPERATION_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createPseudostateContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_pseudostate_EClass = factory->createEClass_in_EPackage(package, PSEUDOSTATE_ECLASS);
	m_pseudostate_EAttribute_kind = factory->createEAttribute_in_EContainingClass(m_pseudostate_EClass, PSEUDOSTATE_EATTRIBUTE_KIND);
	
	m_pseudostate_EReference_state = factory->createEReference_in_EContainingClass(m_pseudostate_EClass, PSEUDOSTATE_EREFERENCE_STATE);
	m_pseudostate_EReference_stateMachine = factory->createEReference_in_EContainingClass(m_pseudostate_EClass, PSEUDOSTATE_EREFERENCE_STATEMACHINE);
	
	m_pseudostate_EOperation_choice_vertex_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_pseudostate_EClass, PSEUDOSTATE_EOPERATION_CHOICE_VERTEX_EDIAGNOSTICCHAIN_EMAP);
	m_pseudostate_EOperation_fork_vertex_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_pseudostate_EClass, PSEUDOSTATE_EOPERATION_FORK_VERTEX_EDIAGNOSTICCHAIN_EMAP);
	m_pseudostate_EOperation_history_vertices_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_pseudostate_EClass, PSEUDOSTATE_EOPERATION_HISTORY_VERTICES_EDIAGNOSTICCHAIN_EMAP);
	m_pseudostate_EOperation_initial_vertex_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_pseudostate_EClass, PSEUDOSTATE_EOPERATION_INITIAL_VERTEX_EDIAGNOSTICCHAIN_EMAP);
	m_pseudostate_EOperation_join_vertex_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_pseudostate_EClass, PSEUDOSTATE_EOPERATION_JOIN_VERTEX_EDIAGNOSTICCHAIN_EMAP);
	m_pseudostate_EOperation_junction_vertex_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_pseudostate_EClass, PSEUDOSTATE_EOPERATION_JUNCTION_VERTEX_EDIAGNOSTICCHAIN_EMAP);
	m_pseudostate_EOperation_outgoing_from_initial_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_pseudostate_EClass, PSEUDOSTATE_EOPERATION_OUTGOING_FROM_INITIAL_EDIAGNOSTICCHAIN_EMAP);
	m_pseudostate_EOperation_transitions_incoming_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_pseudostate_EClass, PSEUDOSTATE_EOPERATION_TRANSITIONS_INCOMING_EDIAGNOSTICCHAIN_EMAP);
	m_pseudostate_EOperation_transitions_outgoing_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_pseudostate_EClass, PSEUDOSTATE_EOPERATION_TRANSITIONS_OUTGOING_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createQualifierValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_qualifierValue_EClass = factory->createEClass_in_EPackage(package, QUALIFIERVALUE_ECLASS);
	
	m_qualifierValue_EReference_qualifier = factory->createEReference_in_EContainingClass(m_qualifierValue_EClass, QUALIFIERVALUE_EREFERENCE_QUALIFIER);
	m_qualifierValue_EReference_value = factory->createEReference_in_EContainingClass(m_qualifierValue_EClass, QUALIFIERVALUE_EREFERENCE_VALUE);
	
	m_qualifierValue_EOperation_multiplicity_of_qualifier_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_qualifierValue_EClass, QUALIFIERVALUE_EOPERATION_MULTIPLICITY_OF_QUALIFIER_EDIAGNOSTICCHAIN_EMAP);
	m_qualifierValue_EOperation_qualifier_attribute_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_qualifierValue_EClass, QUALIFIERVALUE_EOPERATION_QUALIFIER_ATTRIBUTE_EDIAGNOSTICCHAIN_EMAP);
	m_qualifierValue_EOperation_type_of_qualifier_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_qualifierValue_EClass, QUALIFIERVALUE_EOPERATION_TYPE_OF_QUALIFIER_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createRaiseExceptionActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_raiseExceptionAction_EClass = factory->createEClass_in_EPackage(package, RAISEEXCEPTIONACTION_ECLASS);
	
	m_raiseExceptionAction_EReference_exception = factory->createEReference_in_EContainingClass(m_raiseExceptionAction_EClass, RAISEEXCEPTIONACTION_EREFERENCE_EXCEPTION);
	
	
}

void UmlPackageImpl::createReadExtentActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_readExtentAction_EClass = factory->createEClass_in_EPackage(package, READEXTENTACTION_ECLASS);
	
	m_readExtentAction_EReference_classifier = factory->createEReference_in_EContainingClass(m_readExtentAction_EClass, READEXTENTACTION_EREFERENCE_CLASSIFIER);
	m_readExtentAction_EReference_result = factory->createEReference_in_EContainingClass(m_readExtentAction_EClass, READEXTENTACTION_EREFERENCE_RESULT);
	
	m_readExtentAction_EOperation_multiplicity_of_result_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readExtentAction_EClass, READEXTENTACTION_EOPERATION_MULTIPLICITY_OF_RESULT_EDIAGNOSTICCHAIN_EMAP);
	m_readExtentAction_EOperation_type_is_classifier_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readExtentAction_EClass, READEXTENTACTION_EOPERATION_TYPE_IS_CLASSIFIER_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createReadIsClassifiedObjectActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_readIsClassifiedObjectAction_EClass = factory->createEClass_in_EPackage(package, READISCLASSIFIEDOBJECTACTION_ECLASS);
	m_readIsClassifiedObjectAction_EAttribute_isDirect = factory->createEAttribute_in_EContainingClass(m_readIsClassifiedObjectAction_EClass, READISCLASSIFIEDOBJECTACTION_EATTRIBUTE_ISDIRECT);
	
	m_readIsClassifiedObjectAction_EReference_classifier = factory->createEReference_in_EContainingClass(m_readIsClassifiedObjectAction_EClass, READISCLASSIFIEDOBJECTACTION_EREFERENCE_CLASSIFIER);
	m_readIsClassifiedObjectAction_EReference_object = factory->createEReference_in_EContainingClass(m_readIsClassifiedObjectAction_EClass, READISCLASSIFIEDOBJECTACTION_EREFERENCE_OBJECT);
	m_readIsClassifiedObjectAction_EReference_result = factory->createEReference_in_EContainingClass(m_readIsClassifiedObjectAction_EClass, READISCLASSIFIEDOBJECTACTION_EREFERENCE_RESULT);
	
	m_readIsClassifiedObjectAction_EOperation_boolean_result_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readIsClassifiedObjectAction_EClass, READISCLASSIFIEDOBJECTACTION_EOPERATION_BOOLEAN_RESULT_EDIAGNOSTICCHAIN_EMAP);
	m_readIsClassifiedObjectAction_EOperation_multiplicity_of_input_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readIsClassifiedObjectAction_EClass, READISCLASSIFIEDOBJECTACTION_EOPERATION_MULTIPLICITY_OF_INPUT_EDIAGNOSTICCHAIN_EMAP);
	m_readIsClassifiedObjectAction_EOperation_multiplicity_of_output_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readIsClassifiedObjectAction_EClass, READISCLASSIFIEDOBJECTACTION_EOPERATION_MULTIPLICITY_OF_OUTPUT_EDIAGNOSTICCHAIN_EMAP);
	m_readIsClassifiedObjectAction_EOperation_no_type_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readIsClassifiedObjectAction_EClass, READISCLASSIFIEDOBJECTACTION_EOPERATION_NO_TYPE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createReadLinkActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_readLinkAction_EClass = factory->createEClass_in_EPackage(package, READLINKACTION_ECLASS);
	
	m_readLinkAction_EReference_result = factory->createEReference_in_EContainingClass(m_readLinkAction_EClass, READLINKACTION_EREFERENCE_RESULT);
	
	m_readLinkAction_EOperation_compatible_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readLinkAction_EClass, READLINKACTION_EOPERATION_COMPATIBLE_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	m_readLinkAction_EOperation_navigable_open_end_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readLinkAction_EClass, READLINKACTION_EOPERATION_NAVIGABLE_OPEN_END_EDIAGNOSTICCHAIN_EMAP);
	m_readLinkAction_EOperation_one_open_end_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readLinkAction_EClass, READLINKACTION_EOPERATION_ONE_OPEN_END_EDIAGNOSTICCHAIN_EMAP);
	m_readLinkAction_EOperation_openEnd = factory->createEOperation_in_EContainingClass(m_readLinkAction_EClass, READLINKACTION_EOPERATION_OPENEND);
	m_readLinkAction_EOperation_type_and_ordering_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readLinkAction_EClass, READLINKACTION_EOPERATION_TYPE_AND_ORDERING_EDIAGNOSTICCHAIN_EMAP);
	m_readLinkAction_EOperation_visibility_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readLinkAction_EClass, READLINKACTION_EOPERATION_VISIBILITY_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createReadLinkObjectEndActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_readLinkObjectEndAction_EClass = factory->createEClass_in_EPackage(package, READLINKOBJECTENDACTION_ECLASS);
	
	m_readLinkObjectEndAction_EReference_end = factory->createEReference_in_EContainingClass(m_readLinkObjectEndAction_EClass, READLINKOBJECTENDACTION_EREFERENCE_END);
	m_readLinkObjectEndAction_EReference_object = factory->createEReference_in_EContainingClass(m_readLinkObjectEndAction_EClass, READLINKOBJECTENDACTION_EREFERENCE_OBJECT);
	m_readLinkObjectEndAction_EReference_result = factory->createEReference_in_EContainingClass(m_readLinkObjectEndAction_EClass, READLINKOBJECTENDACTION_EREFERENCE_RESULT);
	
	m_readLinkObjectEndAction_EOperation_association_of_association_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readLinkObjectEndAction_EClass, READLINKOBJECTENDACTION_EOPERATION_ASSOCIATION_OF_ASSOCIATION_EDIAGNOSTICCHAIN_EMAP);
	m_readLinkObjectEndAction_EOperation_ends_of_association_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readLinkObjectEndAction_EClass, READLINKOBJECTENDACTION_EOPERATION_ENDS_OF_ASSOCIATION_EDIAGNOSTICCHAIN_EMAP);
	m_readLinkObjectEndAction_EOperation_multiplicity_of_object_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readLinkObjectEndAction_EClass, READLINKOBJECTENDACTION_EOPERATION_MULTIPLICITY_OF_OBJECT_EDIAGNOSTICCHAIN_EMAP);
	m_readLinkObjectEndAction_EOperation_multiplicity_of_result_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readLinkObjectEndAction_EClass, READLINKOBJECTENDACTION_EOPERATION_MULTIPLICITY_OF_RESULT_EDIAGNOSTICCHAIN_EMAP);
	m_readLinkObjectEndAction_EOperation_property_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readLinkObjectEndAction_EClass, READLINKOBJECTENDACTION_EOPERATION_PROPERTY_EDIAGNOSTICCHAIN_EMAP);
	m_readLinkObjectEndAction_EOperation_type_of_object_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readLinkObjectEndAction_EClass, READLINKOBJECTENDACTION_EOPERATION_TYPE_OF_OBJECT_EDIAGNOSTICCHAIN_EMAP);
	m_readLinkObjectEndAction_EOperation_type_of_result_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readLinkObjectEndAction_EClass, READLINKOBJECTENDACTION_EOPERATION_TYPE_OF_RESULT_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createReadLinkObjectEndQualifierActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_readLinkObjectEndQualifierAction_EClass = factory->createEClass_in_EPackage(package, READLINKOBJECTENDQUALIFIERACTION_ECLASS);
	
	m_readLinkObjectEndQualifierAction_EReference_object = factory->createEReference_in_EContainingClass(m_readLinkObjectEndQualifierAction_EClass, READLINKOBJECTENDQUALIFIERACTION_EREFERENCE_OBJECT);
	m_readLinkObjectEndQualifierAction_EReference_qualifier = factory->createEReference_in_EContainingClass(m_readLinkObjectEndQualifierAction_EClass, READLINKOBJECTENDQUALIFIERACTION_EREFERENCE_QUALIFIER);
	m_readLinkObjectEndQualifierAction_EReference_result = factory->createEReference_in_EContainingClass(m_readLinkObjectEndQualifierAction_EClass, READLINKOBJECTENDQUALIFIERACTION_EREFERENCE_RESULT);
	
	m_readLinkObjectEndQualifierAction_EOperation_association_of_association_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readLinkObjectEndQualifierAction_EClass, READLINKOBJECTENDQUALIFIERACTION_EOPERATION_ASSOCIATION_OF_ASSOCIATION_EDIAGNOSTICCHAIN_EMAP);
	m_readLinkObjectEndQualifierAction_EOperation_ends_of_association_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readLinkObjectEndQualifierAction_EClass, READLINKOBJECTENDQUALIFIERACTION_EOPERATION_ENDS_OF_ASSOCIATION_EDIAGNOSTICCHAIN_EMAP);
	m_readLinkObjectEndQualifierAction_EOperation_multiplicity_of_object_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readLinkObjectEndQualifierAction_EClass, READLINKOBJECTENDQUALIFIERACTION_EOPERATION_MULTIPLICITY_OF_OBJECT_EDIAGNOSTICCHAIN_EMAP);
	m_readLinkObjectEndQualifierAction_EOperation_multiplicity_of_qualifier_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readLinkObjectEndQualifierAction_EClass, READLINKOBJECTENDQUALIFIERACTION_EOPERATION_MULTIPLICITY_OF_QUALIFIER_EDIAGNOSTICCHAIN_EMAP);
	m_readLinkObjectEndQualifierAction_EOperation_multiplicity_of_result_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readLinkObjectEndQualifierAction_EClass, READLINKOBJECTENDQUALIFIERACTION_EOPERATION_MULTIPLICITY_OF_RESULT_EDIAGNOSTICCHAIN_EMAP);
	m_readLinkObjectEndQualifierAction_EOperation_qualifier_attribute_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readLinkObjectEndQualifierAction_EClass, READLINKOBJECTENDQUALIFIERACTION_EOPERATION_QUALIFIER_ATTRIBUTE_EDIAGNOSTICCHAIN_EMAP);
	m_readLinkObjectEndQualifierAction_EOperation_same_type_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readLinkObjectEndQualifierAction_EClass, READLINKOBJECTENDQUALIFIERACTION_EOPERATION_SAME_TYPE_EDIAGNOSTICCHAIN_EMAP);
	m_readLinkObjectEndQualifierAction_EOperation_type_of_object_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readLinkObjectEndQualifierAction_EClass, READLINKOBJECTENDQUALIFIERACTION_EOPERATION_TYPE_OF_OBJECT_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createReadSelfActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_readSelfAction_EClass = factory->createEClass_in_EPackage(package, READSELFACTION_ECLASS);
	
	m_readSelfAction_EReference_result = factory->createEReference_in_EContainingClass(m_readSelfAction_EClass, READSELFACTION_EREFERENCE_RESULT);
	
	m_readSelfAction_EOperation_contained_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readSelfAction_EClass, READSELFACTION_EOPERATION_CONTAINED_EDIAGNOSTICCHAIN_EMAP);
	m_readSelfAction_EOperation_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readSelfAction_EClass, READSELFACTION_EOPERATION_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	m_readSelfAction_EOperation_not_static_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readSelfAction_EClass, READSELFACTION_EOPERATION_NOT_STATIC_EDIAGNOSTICCHAIN_EMAP);
	m_readSelfAction_EOperation_type_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readSelfAction_EClass, READSELFACTION_EOPERATION_TYPE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createReadStructuralFeatureActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_readStructuralFeatureAction_EClass = factory->createEClass_in_EPackage(package, READSTRUCTURALFEATUREACTION_ECLASS);
	
	m_readStructuralFeatureAction_EReference_result = factory->createEReference_in_EContainingClass(m_readStructuralFeatureAction_EClass, READSTRUCTURALFEATUREACTION_EREFERENCE_RESULT);
	
	m_readStructuralFeatureAction_EOperation_type_and_ordering_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readStructuralFeatureAction_EClass, READSTRUCTURALFEATUREACTION_EOPERATION_TYPE_AND_ORDERING_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createReadVariableActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_readVariableAction_EClass = factory->createEClass_in_EPackage(package, READVARIABLEACTION_ECLASS);
	
	m_readVariableAction_EReference_result = factory->createEReference_in_EContainingClass(m_readVariableAction_EClass, READVARIABLEACTION_EREFERENCE_RESULT);
	
	m_readVariableAction_EOperation_compatible_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readVariableAction_EClass, READVARIABLEACTION_EOPERATION_COMPATIBLE_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	m_readVariableAction_EOperation_type_and_ordering_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_readVariableAction_EClass, READVARIABLEACTION_EOPERATION_TYPE_AND_ORDERING_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createRealizationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_realization_EClass = factory->createEClass_in_EPackage(package, REALIZATION_ECLASS);
	
	
	
}

void UmlPackageImpl::createReceptionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_reception_EClass = factory->createEClass_in_EPackage(package, RECEPTION_ECLASS);
	
	m_reception_EReference_signal = factory->createEReference_in_EContainingClass(m_reception_EClass, RECEPTION_EREFERENCE_SIGNAL);
	
	m_reception_EOperation_same_name_as_signal_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_reception_EClass, RECEPTION_EOPERATION_SAME_NAME_AS_SIGNAL_EDIAGNOSTICCHAIN_EMAP);
	m_reception_EOperation_same_structure_as_signal_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_reception_EClass, RECEPTION_EOPERATION_SAME_STRUCTURE_AS_SIGNAL_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createReclassifyObjectActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_reclassifyObjectAction_EClass = factory->createEClass_in_EPackage(package, RECLASSIFYOBJECTACTION_ECLASS);
	m_reclassifyObjectAction_EAttribute_isReplaceAll = factory->createEAttribute_in_EContainingClass(m_reclassifyObjectAction_EClass, RECLASSIFYOBJECTACTION_EATTRIBUTE_ISREPLACEALL);
	
	m_reclassifyObjectAction_EReference_newClassifier = factory->createEReference_in_EContainingClass(m_reclassifyObjectAction_EClass, RECLASSIFYOBJECTACTION_EREFERENCE_NEWCLASSIFIER);
	m_reclassifyObjectAction_EReference_object = factory->createEReference_in_EContainingClass(m_reclassifyObjectAction_EClass, RECLASSIFYOBJECTACTION_EREFERENCE_OBJECT);
	m_reclassifyObjectAction_EReference_oldClassifier = factory->createEReference_in_EContainingClass(m_reclassifyObjectAction_EClass, RECLASSIFYOBJECTACTION_EREFERENCE_OLDCLASSIFIER);
	
	m_reclassifyObjectAction_EOperation_classifier_not_abstract_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_reclassifyObjectAction_EClass, RECLASSIFYOBJECTACTION_EOPERATION_CLASSIFIER_NOT_ABSTRACT_EDIAGNOSTICCHAIN_EMAP);
	m_reclassifyObjectAction_EOperation_input_pin_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_reclassifyObjectAction_EClass, RECLASSIFYOBJECTACTION_EOPERATION_INPUT_PIN_EDIAGNOSTICCHAIN_EMAP);
	m_reclassifyObjectAction_EOperation_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_reclassifyObjectAction_EClass, RECLASSIFYOBJECTACTION_EOPERATION_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createRedefinableElementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_redefinableElement_EClass = factory->createEClass_in_EPackage(package, REDEFINABLEELEMENT_ECLASS);
	m_redefinableElement_EAttribute_isLeaf = factory->createEAttribute_in_EContainingClass(m_redefinableElement_EClass, REDEFINABLEELEMENT_EATTRIBUTE_ISLEAF);
	
	m_redefinableElement_EReference_redefinedElement = factory->createEReference_in_EContainingClass(m_redefinableElement_EClass, REDEFINABLEELEMENT_EREFERENCE_REDEFINEDELEMENT);
	m_redefinableElement_EReference_redefinitionContext = factory->createEReference_in_EContainingClass(m_redefinableElement_EClass, REDEFINABLEELEMENT_EREFERENCE_REDEFINITIONCONTEXT);
	
	m_redefinableElement_EOperation_isConsistentWith_RedefinableElement = factory->createEOperation_in_EContainingClass(m_redefinableElement_EClass, REDEFINABLEELEMENT_EOPERATION_ISCONSISTENTWITH_REDEFINABLEELEMENT);
	m_redefinableElement_EOperation_isRedefinitionContextValid_RedefinableElement = factory->createEOperation_in_EContainingClass(m_redefinableElement_EClass, REDEFINABLEELEMENT_EOPERATION_ISREDEFINITIONCONTEXTVALID_REDEFINABLEELEMENT);
	m_redefinableElement_EOperation_non_leaf_redefinition_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_redefinableElement_EClass, REDEFINABLEELEMENT_EOPERATION_NON_LEAF_REDEFINITION_EDIAGNOSTICCHAIN_EMAP);
	m_redefinableElement_EOperation_redefinition_consistent_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_redefinableElement_EClass, REDEFINABLEELEMENT_EOPERATION_REDEFINITION_CONSISTENT_EDIAGNOSTICCHAIN_EMAP);
	m_redefinableElement_EOperation_redefinition_context_valid_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_redefinableElement_EClass, REDEFINABLEELEMENT_EOPERATION_REDEFINITION_CONTEXT_VALID_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createRedefinableTemplateSignatureContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_redefinableTemplateSignature_EClass = factory->createEClass_in_EPackage(package, REDEFINABLETEMPLATESIGNATURE_ECLASS);
	
	m_redefinableTemplateSignature_EReference_classifier = factory->createEReference_in_EContainingClass(m_redefinableTemplateSignature_EClass, REDEFINABLETEMPLATESIGNATURE_EREFERENCE_CLASSIFIER);
	m_redefinableTemplateSignature_EReference_extendedSignature = factory->createEReference_in_EContainingClass(m_redefinableTemplateSignature_EClass, REDEFINABLETEMPLATESIGNATURE_EREFERENCE_EXTENDEDSIGNATURE);
	m_redefinableTemplateSignature_EReference_inheritedParameter = factory->createEReference_in_EContainingClass(m_redefinableTemplateSignature_EClass, REDEFINABLETEMPLATESIGNATURE_EREFERENCE_INHERITEDPARAMETER);
	
	m_redefinableTemplateSignature_EOperation_getInheritedParameters = factory->createEOperation_in_EContainingClass(m_redefinableTemplateSignature_EClass, REDEFINABLETEMPLATESIGNATURE_EOPERATION_GETINHERITEDPARAMETERS);
	m_redefinableTemplateSignature_EOperation_redefines_parents_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_redefinableTemplateSignature_EClass, REDEFINABLETEMPLATESIGNATURE_EOPERATION_REDEFINES_PARENTS_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createReduceActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_reduceAction_EClass = factory->createEClass_in_EPackage(package, REDUCEACTION_ECLASS);
	m_reduceAction_EAttribute_isOrdered = factory->createEAttribute_in_EContainingClass(m_reduceAction_EClass, REDUCEACTION_EATTRIBUTE_ISORDERED);
	
	m_reduceAction_EReference_collection = factory->createEReference_in_EContainingClass(m_reduceAction_EClass, REDUCEACTION_EREFERENCE_COLLECTION);
	m_reduceAction_EReference_reducer = factory->createEReference_in_EContainingClass(m_reduceAction_EClass, REDUCEACTION_EREFERENCE_REDUCER);
	m_reduceAction_EReference_result = factory->createEReference_in_EContainingClass(m_reduceAction_EClass, REDUCEACTION_EREFERENCE_RESULT);
	
	m_reduceAction_EOperation_input_type_is_collection_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_reduceAction_EClass, REDUCEACTION_EOPERATION_INPUT_TYPE_IS_COLLECTION_EDIAGNOSTICCHAIN_EMAP);
	m_reduceAction_EOperation_output_types_are_compatible_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_reduceAction_EClass, REDUCEACTION_EOPERATION_OUTPUT_TYPES_ARE_COMPATIBLE_EDIAGNOSTICCHAIN_EMAP);
	m_reduceAction_EOperation_reducer_inputs_output_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_reduceAction_EClass, REDUCEACTION_EOPERATION_REDUCER_INPUTS_OUTPUT_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createRegionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_region_EClass = factory->createEClass_in_EPackage(package, REGION_ECLASS);
	
	m_region_EReference_extendedRegion = factory->createEReference_in_EContainingClass(m_region_EClass, REGION_EREFERENCE_EXTENDEDREGION);
	m_region_EReference_state = factory->createEReference_in_EContainingClass(m_region_EClass, REGION_EREFERENCE_STATE);
	m_region_EReference_stateMachine = factory->createEReference_in_EContainingClass(m_region_EClass, REGION_EREFERENCE_STATEMACHINE);
	m_region_EReference_subvertex = factory->createEReference_in_EContainingClass(m_region_EClass, REGION_EREFERENCE_SUBVERTEX);
	m_region_EReference_transition = factory->createEReference_in_EContainingClass(m_region_EClass, REGION_EREFERENCE_TRANSITION);
	
	m_region_EOperation_belongsToPSM = factory->createEOperation_in_EContainingClass(m_region_EClass, REGION_EOPERATION_BELONGSTOPSM);
	m_region_EOperation_containingStateMachine = factory->createEOperation_in_EContainingClass(m_region_EClass, REGION_EOPERATION_CONTAININGSTATEMACHINE);
	m_region_EOperation_deep_history_vertex_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_region_EClass, REGION_EOPERATION_DEEP_HISTORY_VERTEX_EDIAGNOSTICCHAIN_EMAP);
	m_region_EOperation_initial_vertex_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_region_EClass, REGION_EOPERATION_INITIAL_VERTEX_EDIAGNOSTICCHAIN_EMAP);
	m_region_EOperation_owned_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_region_EClass, REGION_EOPERATION_OWNED_EDIAGNOSTICCHAIN_EMAP);
	m_region_EOperation_redefinitionContext = factory->createEOperation_in_EContainingClass(m_region_EClass, REGION_EOPERATION_REDEFINITIONCONTEXT);
	m_region_EOperation_shallow_history_vertex_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_region_EClass, REGION_EOPERATION_SHALLOW_HISTORY_VERTEX_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createRelationshipContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_relationship_EClass = factory->createEClass_in_EPackage(package, RELATIONSHIP_ECLASS);
	
	m_relationship_EReference_relatedElement = factory->createEReference_in_EContainingClass(m_relationship_EClass, RELATIONSHIP_EREFERENCE_RELATEDELEMENT);
	
	
}

void UmlPackageImpl::createRemoveStructuralFeatureValueActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_removeStructuralFeatureValueAction_EClass = factory->createEClass_in_EPackage(package, REMOVESTRUCTURALFEATUREVALUEACTION_ECLASS);
	m_removeStructuralFeatureValueAction_EAttribute_isRemoveDuplicates = factory->createEAttribute_in_EContainingClass(m_removeStructuralFeatureValueAction_EClass, REMOVESTRUCTURALFEATUREVALUEACTION_EATTRIBUTE_ISREMOVEDUPLICATES);
	
	m_removeStructuralFeatureValueAction_EReference_removeAt = factory->createEReference_in_EContainingClass(m_removeStructuralFeatureValueAction_EClass, REMOVESTRUCTURALFEATUREVALUEACTION_EREFERENCE_REMOVEAT);
	
	m_removeStructuralFeatureValueAction_EOperation_removeAt_and_value_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_removeStructuralFeatureValueAction_EClass, REMOVESTRUCTURALFEATUREVALUEACTION_EOPERATION_REMOVEAT_AND_VALUE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createRemoveVariableValueActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_removeVariableValueAction_EClass = factory->createEClass_in_EPackage(package, REMOVEVARIABLEVALUEACTION_ECLASS);
	m_removeVariableValueAction_EAttribute_isRemoveDuplicates = factory->createEAttribute_in_EContainingClass(m_removeVariableValueAction_EClass, REMOVEVARIABLEVALUEACTION_EATTRIBUTE_ISREMOVEDUPLICATES);
	
	m_removeVariableValueAction_EReference_removeAt = factory->createEReference_in_EContainingClass(m_removeVariableValueAction_EClass, REMOVEVARIABLEVALUEACTION_EREFERENCE_REMOVEAT);
	
	m_removeVariableValueAction_EOperation_removeAt_and_value_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_removeVariableValueAction_EClass, REMOVEVARIABLEVALUEACTION_EOPERATION_REMOVEAT_AND_VALUE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createReplyActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_replyAction_EClass = factory->createEClass_in_EPackage(package, REPLYACTION_ECLASS);
	
	m_replyAction_EReference_replyToCall = factory->createEReference_in_EContainingClass(m_replyAction_EClass, REPLYACTION_EREFERENCE_REPLYTOCALL);
	m_replyAction_EReference_replyValue = factory->createEReference_in_EContainingClass(m_replyAction_EClass, REPLYACTION_EREFERENCE_REPLYVALUE);
	m_replyAction_EReference_returnInformation = factory->createEReference_in_EContainingClass(m_replyAction_EClass, REPLYACTION_EREFERENCE_RETURNINFORMATION);
	
	m_replyAction_EOperation_event_on_reply_to_call_trigger_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_replyAction_EClass, REPLYACTION_EOPERATION_EVENT_ON_REPLY_TO_CALL_TRIGGER_EDIAGNOSTICCHAIN_EMAP);
	m_replyAction_EOperation_pins_match_parameter_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_replyAction_EClass, REPLYACTION_EOPERATION_PINS_MATCH_PARAMETER_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createSendObjectActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_sendObjectAction_EClass = factory->createEClass_in_EPackage(package, SENDOBJECTACTION_ECLASS);
	
	m_sendObjectAction_EReference_request = factory->createEReference_in_EContainingClass(m_sendObjectAction_EClass, SENDOBJECTACTION_EREFERENCE_REQUEST);
	m_sendObjectAction_EReference_target = factory->createEReference_in_EContainingClass(m_sendObjectAction_EClass, SENDOBJECTACTION_EREFERENCE_TARGET);
	
	m_sendObjectAction_EOperation_type_target_pin_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_sendObjectAction_EClass, SENDOBJECTACTION_EOPERATION_TYPE_TARGET_PIN_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createSendSignalActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_sendSignalAction_EClass = factory->createEClass_in_EPackage(package, SENDSIGNALACTION_ECLASS);
	
	m_sendSignalAction_EReference_signal = factory->createEReference_in_EContainingClass(m_sendSignalAction_EClass, SENDSIGNALACTION_EREFERENCE_SIGNAL);
	m_sendSignalAction_EReference_target = factory->createEReference_in_EContainingClass(m_sendSignalAction_EClass, SENDSIGNALACTION_EREFERENCE_TARGET);
	
	m_sendSignalAction_EOperation_number_order_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_sendSignalAction_EClass, SENDSIGNALACTION_EOPERATION_NUMBER_ORDER_EDIAGNOSTICCHAIN_EMAP);
	m_sendSignalAction_EOperation_type_ordering_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_sendSignalAction_EClass, SENDSIGNALACTION_EOPERATION_TYPE_ORDERING_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	m_sendSignalAction_EOperation_type_target_pin_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_sendSignalAction_EClass, SENDSIGNALACTION_EOPERATION_TYPE_TARGET_PIN_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createSequenceNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_sequenceNode_EClass = factory->createEClass_in_EPackage(package, SEQUENCENODE_ECLASS);
	
	m_sequenceNode_EReference_executableNode = factory->createEReference_in_EContainingClass(m_sequenceNode_EClass, SEQUENCENODE_EREFERENCE_EXECUTABLENODE);
	
	
}

void UmlPackageImpl::createSignalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_signal_EClass = factory->createEClass_in_EPackage(package, SIGNAL_ECLASS);
	
	m_signal_EReference_ownedAttribute = factory->createEReference_in_EContainingClass(m_signal_EClass, SIGNAL_EREFERENCE_OWNEDATTRIBUTE);
	
	m_signal_EOperation_createOwnedAttribute_String_UnlimitedNatural = factory->createEOperation_in_EContainingClass(m_signal_EClass, SIGNAL_EOPERATION_CREATEOWNEDATTRIBUTE_STRING_UNLIMITEDNATURAL);
	
}

void UmlPackageImpl::createSignalEventContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_signalEvent_EClass = factory->createEClass_in_EPackage(package, SIGNALEVENT_ECLASS);
	
	m_signalEvent_EReference_signal = factory->createEReference_in_EContainingClass(m_signalEvent_EClass, SIGNALEVENT_EREFERENCE_SIGNAL);
	
	
}

void UmlPackageImpl::createSlotContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_slot_EClass = factory->createEClass_in_EPackage(package, SLOT_ECLASS);
	
	m_slot_EReference_definingFeature = factory->createEReference_in_EContainingClass(m_slot_EClass, SLOT_EREFERENCE_DEFININGFEATURE);
	m_slot_EReference_owningInstance = factory->createEReference_in_EContainingClass(m_slot_EClass, SLOT_EREFERENCE_OWNINGINSTANCE);
	m_slot_EReference_value = factory->createEReference_in_EContainingClass(m_slot_EClass, SLOT_EREFERENCE_VALUE);
	
	
}

void UmlPackageImpl::createStartClassifierBehaviorActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_startClassifierBehaviorAction_EClass = factory->createEClass_in_EPackage(package, STARTCLASSIFIERBEHAVIORACTION_ECLASS);
	
	m_startClassifierBehaviorAction_EReference_object = factory->createEReference_in_EContainingClass(m_startClassifierBehaviorAction_EClass, STARTCLASSIFIERBEHAVIORACTION_EREFERENCE_OBJECT);
	
	m_startClassifierBehaviorAction_EOperation_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_startClassifierBehaviorAction_EClass, STARTCLASSIFIERBEHAVIORACTION_EOPERATION_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	m_startClassifierBehaviorAction_EOperation_type_has_classifier_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_startClassifierBehaviorAction_EClass, STARTCLASSIFIERBEHAVIORACTION_EOPERATION_TYPE_HAS_CLASSIFIER_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createStartObjectBehaviorActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_startObjectBehaviorAction_EClass = factory->createEClass_in_EPackage(package, STARTOBJECTBEHAVIORACTION_ECLASS);
	
	m_startObjectBehaviorAction_EReference_object = factory->createEReference_in_EContainingClass(m_startObjectBehaviorAction_EClass, STARTOBJECTBEHAVIORACTION_EREFERENCE_OBJECT);
	
	m_startObjectBehaviorAction_EOperation_behavior = factory->createEOperation_in_EContainingClass(m_startObjectBehaviorAction_EClass, STARTOBJECTBEHAVIORACTION_EOPERATION_BEHAVIOR);
	m_startObjectBehaviorAction_EOperation_multiplicity_of_object_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_startObjectBehaviorAction_EClass, STARTOBJECTBEHAVIORACTION_EOPERATION_MULTIPLICITY_OF_OBJECT_EDIAGNOSTICCHAIN_EMAP);
	m_startObjectBehaviorAction_EOperation_no_onport_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_startObjectBehaviorAction_EClass, STARTOBJECTBEHAVIORACTION_EOPERATION_NO_ONPORT_EDIAGNOSTICCHAIN_EMAP);
	m_startObjectBehaviorAction_EOperation_type_of_object_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_startObjectBehaviorAction_EClass, STARTOBJECTBEHAVIORACTION_EOPERATION_TYPE_OF_OBJECT_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createStateContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_state_EClass = factory->createEClass_in_EPackage(package, STATE_ECLASS);
	m_state_EAttribute_isComposite = factory->createEAttribute_in_EContainingClass(m_state_EClass, STATE_EATTRIBUTE_ISCOMPOSITE);
	m_state_EAttribute_isOrthogonal = factory->createEAttribute_in_EContainingClass(m_state_EClass, STATE_EATTRIBUTE_ISORTHOGONAL);
	m_state_EAttribute_isSimple = factory->createEAttribute_in_EContainingClass(m_state_EClass, STATE_EATTRIBUTE_ISSIMPLE);
	m_state_EAttribute_isSubmachineState = factory->createEAttribute_in_EContainingClass(m_state_EClass, STATE_EATTRIBUTE_ISSUBMACHINESTATE);
	
	m_state_EReference_connection = factory->createEReference_in_EContainingClass(m_state_EClass, STATE_EREFERENCE_CONNECTION);
	m_state_EReference_connectionPoint = factory->createEReference_in_EContainingClass(m_state_EClass, STATE_EREFERENCE_CONNECTIONPOINT);
	m_state_EReference_deferrableTrigger = factory->createEReference_in_EContainingClass(m_state_EClass, STATE_EREFERENCE_DEFERRABLETRIGGER);
	m_state_EReference_doActivity = factory->createEReference_in_EContainingClass(m_state_EClass, STATE_EREFERENCE_DOACTIVITY);
	m_state_EReference_entry = factory->createEReference_in_EContainingClass(m_state_EClass, STATE_EREFERENCE_ENTRY);
	m_state_EReference_exit = factory->createEReference_in_EContainingClass(m_state_EClass, STATE_EREFERENCE_EXIT);
	m_state_EReference_redefinedState = factory->createEReference_in_EContainingClass(m_state_EClass, STATE_EREFERENCE_REDEFINEDSTATE);
	m_state_EReference_region = factory->createEReference_in_EContainingClass(m_state_EClass, STATE_EREFERENCE_REGION);
	m_state_EReference_stateInvariant = factory->createEReference_in_EContainingClass(m_state_EClass, STATE_EREFERENCE_STATEINVARIANT);
	m_state_EReference_submachine = factory->createEReference_in_EContainingClass(m_state_EClass, STATE_EREFERENCE_SUBMACHINE);
	
	m_state_EOperation_composite_states_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_state_EClass, STATE_EOPERATION_COMPOSITE_STATES_EDIAGNOSTICCHAIN_EMAP);
	m_state_EOperation_destinations_or_sources_of_transitions_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_state_EClass, STATE_EOPERATION_DESTINATIONS_OR_SOURCES_OF_TRANSITIONS_EDIAGNOSTICCHAIN_EMAP);
	m_state_EOperation_entry_or_exit_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_state_EClass, STATE_EOPERATION_ENTRY_OR_EXIT_EDIAGNOSTICCHAIN_EMAP);
	m_state_EOperation_isComposite = factory->createEOperation_in_EContainingClass(m_state_EClass, STATE_EOPERATION_ISCOMPOSITE);
	m_state_EOperation_isOrthogonal = factory->createEOperation_in_EContainingClass(m_state_EClass, STATE_EOPERATION_ISORTHOGONAL);
	m_state_EOperation_isSimple = factory->createEOperation_in_EContainingClass(m_state_EClass, STATE_EOPERATION_ISSIMPLE);
	m_state_EOperation_isSubmachineState = factory->createEOperation_in_EContainingClass(m_state_EClass, STATE_EOPERATION_ISSUBMACHINESTATE);
	m_state_EOperation_redefinitionContext = factory->createEOperation_in_EContainingClass(m_state_EClass, STATE_EOPERATION_REDEFINITIONCONTEXT);
	m_state_EOperation_submachine_or_regions_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_state_EClass, STATE_EOPERATION_SUBMACHINE_OR_REGIONS_EDIAGNOSTICCHAIN_EMAP);
	m_state_EOperation_submachine_states_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_state_EClass, STATE_EOPERATION_SUBMACHINE_STATES_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createStateInvariantContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_stateInvariant_EClass = factory->createEClass_in_EPackage(package, STATEINVARIANT_ECLASS);
	
	m_stateInvariant_EReference_invariant = factory->createEReference_in_EContainingClass(m_stateInvariant_EClass, STATEINVARIANT_EREFERENCE_INVARIANT);
	
	
}

void UmlPackageImpl::createStateMachineContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_stateMachine_EClass = factory->createEClass_in_EPackage(package, STATEMACHINE_ECLASS);
	
	m_stateMachine_EReference_connectionPoint = factory->createEReference_in_EContainingClass(m_stateMachine_EClass, STATEMACHINE_EREFERENCE_CONNECTIONPOINT);
	m_stateMachine_EReference_extendedStateMachine = factory->createEReference_in_EContainingClass(m_stateMachine_EClass, STATEMACHINE_EREFERENCE_EXTENDEDSTATEMACHINE);
	m_stateMachine_EReference_region = factory->createEReference_in_EContainingClass(m_stateMachine_EClass, STATEMACHINE_EREFERENCE_REGION);
	m_stateMachine_EReference_submachineState = factory->createEReference_in_EContainingClass(m_stateMachine_EClass, STATEMACHINE_EREFERENCE_SUBMACHINESTATE);
	
	m_stateMachine_EOperation_lCA_Vertex_Vertex = factory->createEOperation_in_EContainingClass(m_stateMachine_EClass, STATEMACHINE_EOPERATION_LCA_VERTEX_VERTEX);
	m_stateMachine_EOperation_lCAState_Vertex_Vertex = factory->createEOperation_in_EContainingClass(m_stateMachine_EClass, STATEMACHINE_EOPERATION_LCASTATE_VERTEX_VERTEX);
	m_stateMachine_EOperation_ancestor_Vertex_Vertex = factory->createEOperation_in_EContainingClass(m_stateMachine_EClass, STATEMACHINE_EOPERATION_ANCESTOR_VERTEX_VERTEX);
	m_stateMachine_EOperation_classifier_context_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_stateMachine_EClass, STATEMACHINE_EOPERATION_CLASSIFIER_CONTEXT_EDIAGNOSTICCHAIN_EMAP);
	m_stateMachine_EOperation_connection_points_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_stateMachine_EClass, STATEMACHINE_EOPERATION_CONNECTION_POINTS_EDIAGNOSTICCHAIN_EMAP);
	m_stateMachine_EOperation_context_classifier_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_stateMachine_EClass, STATEMACHINE_EOPERATION_CONTEXT_CLASSIFIER_EDIAGNOSTICCHAIN_EMAP);
	m_stateMachine_EOperation_method_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_stateMachine_EClass, STATEMACHINE_EOPERATION_METHOD_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createStereotypeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_stereotype_EClass = factory->createEClass_in_EPackage(package, STEREOTYPE_ECLASS);
	
	m_stereotype_EReference_icon = factory->createEReference_in_EContainingClass(m_stereotype_EClass, STEREOTYPE_EREFERENCE_ICON);
	m_stereotype_EReference_profile = factory->createEReference_in_EContainingClass(m_stereotype_EClass, STEREOTYPE_EREFERENCE_PROFILE);
	
	m_stereotype_EOperation_associationEndOwnership_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_stereotype_EClass, STEREOTYPE_EOPERATION_ASSOCIATIONENDOWNERSHIP_EDIAGNOSTICCHAIN_EMAP);
	m_stereotype_EOperation_base_property_multiplicity_multiple_extension_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_stereotype_EClass, STEREOTYPE_EOPERATION_BASE_PROPERTY_MULTIPLICITY_MULTIPLE_EXTENSION_EDIAGNOSTICCHAIN_EMAP);
	m_stereotype_EOperation_base_property_multiplicity_single_extension_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_stereotype_EClass, STEREOTYPE_EOPERATION_BASE_PROPERTY_MULTIPLICITY_SINGLE_EXTENSION_EDIAGNOSTICCHAIN_EMAP);
	m_stereotype_EOperation_base_property_upper_bound_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_stereotype_EClass, STEREOTYPE_EOPERATION_BASE_PROPERTY_UPPER_BOUND_EDIAGNOSTICCHAIN_EMAP);
	m_stereotype_EOperation_binaryAssociationsOnly_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_stereotype_EClass, STEREOTYPE_EOPERATION_BINARYASSOCIATIONSONLY_EDIAGNOSTICCHAIN_EMAP);
	m_stereotype_EOperation_containingProfile = factory->createEOperation_in_EContainingClass(m_stereotype_EClass, STEREOTYPE_EOPERATION_CONTAININGPROFILE);
	m_stereotype_EOperation_createExtension_Class_Boolean = factory->createEOperation_in_EContainingClass(m_stereotype_EClass, STEREOTYPE_EOPERATION_CREATEEXTENSION_CLASS_BOOLEAN);
	m_stereotype_EOperation_createIcon_String = factory->createEOperation_in_EContainingClass(m_stereotype_EClass, STEREOTYPE_EOPERATION_CREATEICON_STRING);
	m_stereotype_EOperation_createIcon_String_String = factory->createEOperation_in_EContainingClass(m_stereotype_EClass, STEREOTYPE_EOPERATION_CREATEICON_STRING_STRING);
	m_stereotype_EOperation_generalize_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_stereotype_EClass, STEREOTYPE_EOPERATION_GENERALIZE_EDIAGNOSTICCHAIN_EMAP);
	m_stereotype_EOperation_getAllExtendedMetaclasses = factory->createEOperation_in_EContainingClass(m_stereotype_EClass, STEREOTYPE_EOPERATION_GETALLEXTENDEDMETACLASSES);
	m_stereotype_EOperation_getDefinition = factory->createEOperation_in_EContainingClass(m_stereotype_EClass, STEREOTYPE_EOPERATION_GETDEFINITION);
	m_stereotype_EOperation_getExtendedMetaclasses = factory->createEOperation_in_EContainingClass(m_stereotype_EClass, STEREOTYPE_EOPERATION_GETEXTENDEDMETACLASSES);
	m_stereotype_EOperation_getKeyword = factory->createEOperation_in_EContainingClass(m_stereotype_EClass, STEREOTYPE_EOPERATION_GETKEYWORD);
	m_stereotype_EOperation_getKeyword_Boolean = factory->createEOperation_in_EContainingClass(m_stereotype_EClass, STEREOTYPE_EOPERATION_GETKEYWORD_BOOLEAN);
	m_stereotype_EOperation_getProfile = factory->createEOperation_in_EContainingClass(m_stereotype_EClass, STEREOTYPE_EOPERATION_GETPROFILE);
	m_stereotype_EOperation_name_not_clash_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_stereotype_EClass, STEREOTYPE_EOPERATION_NAME_NOT_CLASH_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createStringExpressionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_stringExpression_EClass = factory->createEClass_in_EPackage(package, STRINGEXPRESSION_ECLASS);
	
	m_stringExpression_EReference_owningExpression = factory->createEReference_in_EContainingClass(m_stringExpression_EClass, STRINGEXPRESSION_EREFERENCE_OWNINGEXPRESSION);
	m_stringExpression_EReference_subExpression = factory->createEReference_in_EContainingClass(m_stringExpression_EClass, STRINGEXPRESSION_EREFERENCE_SUBEXPRESSION);
	
	m_stringExpression_EOperation_operands_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_stringExpression_EClass, STRINGEXPRESSION_EOPERATION_OPERANDS_EDIAGNOSTICCHAIN_EMAP);
	m_stringExpression_EOperation_subexpressions_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_stringExpression_EClass, STRINGEXPRESSION_EOPERATION_SUBEXPRESSIONS_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createStructuralFeatureContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_structuralFeature_EClass = factory->createEClass_in_EPackage(package, STRUCTURALFEATURE_ECLASS);
	m_structuralFeature_EAttribute_isReadOnly = factory->createEAttribute_in_EContainingClass(m_structuralFeature_EClass, STRUCTURALFEATURE_EATTRIBUTE_ISREADONLY);
	
	
	
}

void UmlPackageImpl::createStructuralFeatureActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_structuralFeatureAction_EClass = factory->createEClass_in_EPackage(package, STRUCTURALFEATUREACTION_ECLASS);
	
	m_structuralFeatureAction_EReference_object = factory->createEReference_in_EContainingClass(m_structuralFeatureAction_EClass, STRUCTURALFEATUREACTION_EREFERENCE_OBJECT);
	m_structuralFeatureAction_EReference_structuralFeature = factory->createEReference_in_EContainingClass(m_structuralFeatureAction_EClass, STRUCTURALFEATUREACTION_EREFERENCE_STRUCTURALFEATURE);
	
	m_structuralFeatureAction_EOperation_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_structuralFeatureAction_EClass, STRUCTURALFEATUREACTION_EOPERATION_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	m_structuralFeatureAction_EOperation_not_static_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_structuralFeatureAction_EClass, STRUCTURALFEATUREACTION_EOPERATION_NOT_STATIC_EDIAGNOSTICCHAIN_EMAP);
	m_structuralFeatureAction_EOperation_object_type_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_structuralFeatureAction_EClass, STRUCTURALFEATUREACTION_EOPERATION_OBJECT_TYPE_EDIAGNOSTICCHAIN_EMAP);
	m_structuralFeatureAction_EOperation_one_featuring_classifier_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_structuralFeatureAction_EClass, STRUCTURALFEATUREACTION_EOPERATION_ONE_FEATURING_CLASSIFIER_EDIAGNOSTICCHAIN_EMAP);
	m_structuralFeatureAction_EOperation_visibility_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_structuralFeatureAction_EClass, STRUCTURALFEATUREACTION_EOPERATION_VISIBILITY_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createStructuredActivityNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_structuredActivityNode_EClass = factory->createEClass_in_EPackage(package, STRUCTUREDACTIVITYNODE_ECLASS);
	m_structuredActivityNode_EAttribute_mustIsolate = factory->createEAttribute_in_EContainingClass(m_structuredActivityNode_EClass, STRUCTUREDACTIVITYNODE_EATTRIBUTE_MUSTISOLATE);
	
	m_structuredActivityNode_EReference_edge = factory->createEReference_in_EContainingClass(m_structuredActivityNode_EClass, STRUCTUREDACTIVITYNODE_EREFERENCE_EDGE);
	m_structuredActivityNode_EReference_node = factory->createEReference_in_EContainingClass(m_structuredActivityNode_EClass, STRUCTUREDACTIVITYNODE_EREFERENCE_NODE);
	m_structuredActivityNode_EReference_structuredNodeInput = factory->createEReference_in_EContainingClass(m_structuredActivityNode_EClass, STRUCTUREDACTIVITYNODE_EREFERENCE_STRUCTUREDNODEINPUT);
	m_structuredActivityNode_EReference_structuredNodeOutput = factory->createEReference_in_EContainingClass(m_structuredActivityNode_EClass, STRUCTUREDACTIVITYNODE_EREFERENCE_STRUCTUREDNODEOUTPUT);
	m_structuredActivityNode_EReference_variable = factory->createEReference_in_EContainingClass(m_structuredActivityNode_EClass, STRUCTUREDACTIVITYNODE_EREFERENCE_VARIABLE);
	
	m_structuredActivityNode_EOperation_edges_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_structuredActivityNode_EClass, STRUCTUREDACTIVITYNODE_EOPERATION_EDGES_EDIAGNOSTICCHAIN_EMAP);
	m_structuredActivityNode_EOperation_input_pin_edges_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_structuredActivityNode_EClass, STRUCTUREDACTIVITYNODE_EOPERATION_INPUT_PIN_EDGES_EDIAGNOSTICCHAIN_EMAP);
	m_structuredActivityNode_EOperation_output_pin_edges_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_structuredActivityNode_EClass, STRUCTUREDACTIVITYNODE_EOPERATION_OUTPUT_PIN_EDGES_EDIAGNOSTICCHAIN_EMAP);
	m_structuredActivityNode_EOperation_sourceNodes = factory->createEOperation_in_EContainingClass(m_structuredActivityNode_EClass, STRUCTUREDACTIVITYNODE_EOPERATION_SOURCENODES);
	m_structuredActivityNode_EOperation_targetNodes = factory->createEOperation_in_EContainingClass(m_structuredActivityNode_EClass, STRUCTUREDACTIVITYNODE_EOPERATION_TARGETNODES);
	
}

void UmlPackageImpl::createStructuredClassifierContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_structuredClassifier_EClass = factory->createEClass_in_EPackage(package, STRUCTUREDCLASSIFIER_ECLASS);
	
	m_structuredClassifier_EReference_ownedAttribute = factory->createEReference_in_EContainingClass(m_structuredClassifier_EClass, STRUCTUREDCLASSIFIER_EREFERENCE_OWNEDATTRIBUTE);
	m_structuredClassifier_EReference_ownedConnector = factory->createEReference_in_EContainingClass(m_structuredClassifier_EClass, STRUCTUREDCLASSIFIER_EREFERENCE_OWNEDCONNECTOR);
	m_structuredClassifier_EReference_part = factory->createEReference_in_EContainingClass(m_structuredClassifier_EClass, STRUCTUREDCLASSIFIER_EREFERENCE_PART);
	m_structuredClassifier_EReference_role = factory->createEReference_in_EContainingClass(m_structuredClassifier_EClass, STRUCTUREDCLASSIFIER_EREFERENCE_ROLE);
	
	m_structuredClassifier_EOperation_allRoles = factory->createEOperation_in_EContainingClass(m_structuredClassifier_EClass, STRUCTUREDCLASSIFIER_EOPERATION_ALLROLES);
	m_structuredClassifier_EOperation_createOwnedAttribute_String_UnlimitedNatural = factory->createEOperation_in_EContainingClass(m_structuredClassifier_EClass, STRUCTUREDCLASSIFIER_EOPERATION_CREATEOWNEDATTRIBUTE_STRING_UNLIMITEDNATURAL);
	m_structuredClassifier_EOperation_getParts = factory->createEOperation_in_EContainingClass(m_structuredClassifier_EClass, STRUCTUREDCLASSIFIER_EOPERATION_GETPARTS);
	
}

void UmlPackageImpl::createSubstitutionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_substitution_EClass = factory->createEClass_in_EPackage(package, SUBSTITUTION_ECLASS);
	
	m_substitution_EReference_contract = factory->createEReference_in_EContainingClass(m_substitution_EClass, SUBSTITUTION_EREFERENCE_CONTRACT);
	m_substitution_EReference_substitutingClassifier = factory->createEReference_in_EContainingClass(m_substitution_EClass, SUBSTITUTION_EREFERENCE_SUBSTITUTINGCLASSIFIER);
	
	
}

void UmlPackageImpl::createTemplateBindingContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_templateBinding_EClass = factory->createEClass_in_EPackage(package, TEMPLATEBINDING_ECLASS);
	
	m_templateBinding_EReference_boundElement = factory->createEReference_in_EContainingClass(m_templateBinding_EClass, TEMPLATEBINDING_EREFERENCE_BOUNDELEMENT);
	m_templateBinding_EReference_parameterSubstitution = factory->createEReference_in_EContainingClass(m_templateBinding_EClass, TEMPLATEBINDING_EREFERENCE_PARAMETERSUBSTITUTION);
	m_templateBinding_EReference_signature = factory->createEReference_in_EContainingClass(m_templateBinding_EClass, TEMPLATEBINDING_EREFERENCE_SIGNATURE);
	
	m_templateBinding_EOperation_one_parameter_substitution_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_templateBinding_EClass, TEMPLATEBINDING_EOPERATION_ONE_PARAMETER_SUBSTITUTION_EDIAGNOSTICCHAIN_EMAP);
	m_templateBinding_EOperation_parameter_substitution_formal_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_templateBinding_EClass, TEMPLATEBINDING_EOPERATION_PARAMETER_SUBSTITUTION_FORMAL_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createTemplateParameterContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_templateParameter_EClass = factory->createEClass_in_EPackage(package, TEMPLATEPARAMETER_ECLASS);
	
	m_templateParameter_EReference_default = factory->createEReference_in_EContainingClass(m_templateParameter_EClass, TEMPLATEPARAMETER_EREFERENCE_DEFAULT);
	m_templateParameter_EReference_ownedDefault = factory->createEReference_in_EContainingClass(m_templateParameter_EClass, TEMPLATEPARAMETER_EREFERENCE_OWNEDDEFAULT);
	m_templateParameter_EReference_ownedParameteredElement = factory->createEReference_in_EContainingClass(m_templateParameter_EClass, TEMPLATEPARAMETER_EREFERENCE_OWNEDPARAMETEREDELEMENT);
	m_templateParameter_EReference_parameteredElement = factory->createEReference_in_EContainingClass(m_templateParameter_EClass, TEMPLATEPARAMETER_EREFERENCE_PARAMETEREDELEMENT);
	m_templateParameter_EReference_signature = factory->createEReference_in_EContainingClass(m_templateParameter_EClass, TEMPLATEPARAMETER_EREFERENCE_SIGNATURE);
	
	m_templateParameter_EOperation_must_be_compatible_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_templateParameter_EClass, TEMPLATEPARAMETER_EOPERATION_MUST_BE_COMPATIBLE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createTemplateParameterSubstitutionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_templateParameterSubstitution_EClass = factory->createEClass_in_EPackage(package, TEMPLATEPARAMETERSUBSTITUTION_ECLASS);
	
	m_templateParameterSubstitution_EReference_actual = factory->createEReference_in_EContainingClass(m_templateParameterSubstitution_EClass, TEMPLATEPARAMETERSUBSTITUTION_EREFERENCE_ACTUAL);
	m_templateParameterSubstitution_EReference_formal = factory->createEReference_in_EContainingClass(m_templateParameterSubstitution_EClass, TEMPLATEPARAMETERSUBSTITUTION_EREFERENCE_FORMAL);
	m_templateParameterSubstitution_EReference_ownedActual = factory->createEReference_in_EContainingClass(m_templateParameterSubstitution_EClass, TEMPLATEPARAMETERSUBSTITUTION_EREFERENCE_OWNEDACTUAL);
	m_templateParameterSubstitution_EReference_templateBinding = factory->createEReference_in_EContainingClass(m_templateParameterSubstitution_EClass, TEMPLATEPARAMETERSUBSTITUTION_EREFERENCE_TEMPLATEBINDING);
	
	m_templateParameterSubstitution_EOperation_must_be_compatible_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_templateParameterSubstitution_EClass, TEMPLATEPARAMETERSUBSTITUTION_EOPERATION_MUST_BE_COMPATIBLE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createTemplateSignatureContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_templateSignature_EClass = factory->createEClass_in_EPackage(package, TEMPLATESIGNATURE_ECLASS);
	
	m_templateSignature_EReference_ownedParameter = factory->createEReference_in_EContainingClass(m_templateSignature_EClass, TEMPLATESIGNATURE_EREFERENCE_OWNEDPARAMETER);
	m_templateSignature_EReference_parameter = factory->createEReference_in_EContainingClass(m_templateSignature_EClass, TEMPLATESIGNATURE_EREFERENCE_PARAMETER);
	m_templateSignature_EReference_template = factory->createEReference_in_EContainingClass(m_templateSignature_EClass, TEMPLATESIGNATURE_EREFERENCE_TEMPLATE);
	
	m_templateSignature_EOperation_own_elements_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_templateSignature_EClass, TEMPLATESIGNATURE_EOPERATION_OWN_ELEMENTS_EDIAGNOSTICCHAIN_EMAP);
	m_templateSignature_EOperation_unique_parameters_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_templateSignature_EClass, TEMPLATESIGNATURE_EOPERATION_UNIQUE_PARAMETERS_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createTemplateableElementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_templateableElement_EClass = factory->createEClass_in_EPackage(package, TEMPLATEABLEELEMENT_ECLASS);
	
	m_templateableElement_EReference_ownedTemplateSignature = factory->createEReference_in_EContainingClass(m_templateableElement_EClass, TEMPLATEABLEELEMENT_EREFERENCE_OWNEDTEMPLATESIGNATURE);
	m_templateableElement_EReference_templateBinding = factory->createEReference_in_EContainingClass(m_templateableElement_EClass, TEMPLATEABLEELEMENT_EREFERENCE_TEMPLATEBINDING);
	
	m_templateableElement_EOperation_isTemplate = factory->createEOperation_in_EContainingClass(m_templateableElement_EClass, TEMPLATEABLEELEMENT_EOPERATION_ISTEMPLATE);
	m_templateableElement_EOperation_parameterableElements = factory->createEOperation_in_EContainingClass(m_templateableElement_EClass, TEMPLATEABLEELEMENT_EOPERATION_PARAMETERABLEELEMENTS);
	
}

void UmlPackageImpl::createTestIdentityActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_testIdentityAction_EClass = factory->createEClass_in_EPackage(package, TESTIDENTITYACTION_ECLASS);
	
	m_testIdentityAction_EReference_first = factory->createEReference_in_EContainingClass(m_testIdentityAction_EClass, TESTIDENTITYACTION_EREFERENCE_FIRST);
	m_testIdentityAction_EReference_result = factory->createEReference_in_EContainingClass(m_testIdentityAction_EClass, TESTIDENTITYACTION_EREFERENCE_RESULT);
	m_testIdentityAction_EReference_second = factory->createEReference_in_EContainingClass(m_testIdentityAction_EClass, TESTIDENTITYACTION_EREFERENCE_SECOND);
	
	m_testIdentityAction_EOperation_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_testIdentityAction_EClass, TESTIDENTITYACTION_EOPERATION_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	m_testIdentityAction_EOperation_no_type_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_testIdentityAction_EClass, TESTIDENTITYACTION_EOPERATION_NO_TYPE_EDIAGNOSTICCHAIN_EMAP);
	m_testIdentityAction_EOperation_result_is_boolean_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_testIdentityAction_EClass, TESTIDENTITYACTION_EOPERATION_RESULT_IS_BOOLEAN_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createTimeConstraintContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_timeConstraint_EClass = factory->createEClass_in_EPackage(package, TIMECONSTRAINT_ECLASS);
	m_timeConstraint_EAttribute_firstEvent = factory->createEAttribute_in_EContainingClass(m_timeConstraint_EClass, TIMECONSTRAINT_EATTRIBUTE_FIRSTEVENT);
	
	
	m_timeConstraint_EOperation_has_one_constrainedElement_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_timeConstraint_EClass, TIMECONSTRAINT_EOPERATION_HAS_ONE_CONSTRAINEDELEMENT_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createTimeEventContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_timeEvent_EClass = factory->createEClass_in_EPackage(package, TIMEEVENT_ECLASS);
	m_timeEvent_EAttribute_isRelative = factory->createEAttribute_in_EContainingClass(m_timeEvent_EClass, TIMEEVENT_EATTRIBUTE_ISRELATIVE);
	
	m_timeEvent_EReference_when = factory->createEReference_in_EContainingClass(m_timeEvent_EClass, TIMEEVENT_EREFERENCE_WHEN);
	
	m_timeEvent_EOperation_when_non_negative_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_timeEvent_EClass, TIMEEVENT_EOPERATION_WHEN_NON_NEGATIVE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createTimeExpressionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_timeExpression_EClass = factory->createEClass_in_EPackage(package, TIMEEXPRESSION_ECLASS);
	
	m_timeExpression_EReference_expr = factory->createEReference_in_EContainingClass(m_timeExpression_EClass, TIMEEXPRESSION_EREFERENCE_EXPR);
	m_timeExpression_EReference_observation = factory->createEReference_in_EContainingClass(m_timeExpression_EClass, TIMEEXPRESSION_EREFERENCE_OBSERVATION);
	
	m_timeExpression_EOperation_no_expr_requires_observation_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_timeExpression_EClass, TIMEEXPRESSION_EOPERATION_NO_EXPR_REQUIRES_OBSERVATION_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createTimeIntervalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_timeInterval_EClass = factory->createEClass_in_EPackage(package, TIMEINTERVAL_ECLASS);
	
	
	
}

void UmlPackageImpl::createTimeObservationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_timeObservation_EClass = factory->createEClass_in_EPackage(package, TIMEOBSERVATION_ECLASS);
	m_timeObservation_EAttribute_firstEvent = factory->createEAttribute_in_EContainingClass(m_timeObservation_EClass, TIMEOBSERVATION_EATTRIBUTE_FIRSTEVENT);
	
	m_timeObservation_EReference_event = factory->createEReference_in_EContainingClass(m_timeObservation_EClass, TIMEOBSERVATION_EREFERENCE_EVENT);
	
	
}

void UmlPackageImpl::createTransitionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_transition_EClass = factory->createEClass_in_EPackage(package, TRANSITION_ECLASS);
	m_transition_EAttribute_kind = factory->createEAttribute_in_EContainingClass(m_transition_EClass, TRANSITION_EATTRIBUTE_KIND);
	
	m_transition_EReference_container = factory->createEReference_in_EContainingClass(m_transition_EClass, TRANSITION_EREFERENCE_CONTAINER);
	m_transition_EReference_effect = factory->createEReference_in_EContainingClass(m_transition_EClass, TRANSITION_EREFERENCE_EFFECT);
	m_transition_EReference_guard = factory->createEReference_in_EContainingClass(m_transition_EClass, TRANSITION_EREFERENCE_GUARD);
	m_transition_EReference_redefinedTransition = factory->createEReference_in_EContainingClass(m_transition_EClass, TRANSITION_EREFERENCE_REDEFINEDTRANSITION);
	m_transition_EReference_source = factory->createEReference_in_EContainingClass(m_transition_EClass, TRANSITION_EREFERENCE_SOURCE);
	m_transition_EReference_target = factory->createEReference_in_EContainingClass(m_transition_EClass, TRANSITION_EREFERENCE_TARGET);
	m_transition_EReference_trigger = factory->createEReference_in_EContainingClass(m_transition_EClass, TRANSITION_EREFERENCE_TRIGGER);
	
	m_transition_EOperation_containingStateMachine = factory->createEOperation_in_EContainingClass(m_transition_EClass, TRANSITION_EOPERATION_CONTAININGSTATEMACHINE);
	m_transition_EOperation_fork_segment_guards_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_transition_EClass, TRANSITION_EOPERATION_FORK_SEGMENT_GUARDS_EDIAGNOSTICCHAIN_EMAP);
	m_transition_EOperation_fork_segment_state_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_transition_EClass, TRANSITION_EOPERATION_FORK_SEGMENT_STATE_EDIAGNOSTICCHAIN_EMAP);
	m_transition_EOperation_initial_transition_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_transition_EClass, TRANSITION_EOPERATION_INITIAL_TRANSITION_EDIAGNOSTICCHAIN_EMAP);
	m_transition_EOperation_join_segment_guards_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_transition_EClass, TRANSITION_EOPERATION_JOIN_SEGMENT_GUARDS_EDIAGNOSTICCHAIN_EMAP);
	m_transition_EOperation_join_segment_state_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_transition_EClass, TRANSITION_EOPERATION_JOIN_SEGMENT_STATE_EDIAGNOSTICCHAIN_EMAP);
	m_transition_EOperation_outgoing_pseudostates_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_transition_EClass, TRANSITION_EOPERATION_OUTGOING_PSEUDOSTATES_EDIAGNOSTICCHAIN_EMAP);
	m_transition_EOperation_redefinitionContext = factory->createEOperation_in_EContainingClass(m_transition_EClass, TRANSITION_EOPERATION_REDEFINITIONCONTEXT);
	m_transition_EOperation_state_is_external_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_transition_EClass, TRANSITION_EOPERATION_STATE_IS_EXTERNAL_EDIAGNOSTICCHAIN_EMAP);
	m_transition_EOperation_state_is_internal_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_transition_EClass, TRANSITION_EOPERATION_STATE_IS_INTERNAL_EDIAGNOSTICCHAIN_EMAP);
	m_transition_EOperation_state_is_local_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_transition_EClass, TRANSITION_EOPERATION_STATE_IS_LOCAL_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createTriggerContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_trigger_EClass = factory->createEClass_in_EPackage(package, TRIGGER_ECLASS);
	
	m_trigger_EReference_event = factory->createEReference_in_EContainingClass(m_trigger_EClass, TRIGGER_EREFERENCE_EVENT);
	m_trigger_EReference_port = factory->createEReference_in_EContainingClass(m_trigger_EClass, TRIGGER_EREFERENCE_PORT);
	
	m_trigger_EOperation_trigger_with_ports_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_trigger_EClass, TRIGGER_EOPERATION_TRIGGER_WITH_PORTS_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createTypeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_type_EClass = factory->createEClass_in_EPackage(package, TYPE_ECLASS);
	
	m_type_EReference_package = factory->createEReference_in_EContainingClass(m_type_EClass, TYPE_EREFERENCE_PACKAGE);
	
	m_type_EOperation_conformsTo_Type = factory->createEOperation_in_EContainingClass(m_type_EClass, TYPE_EOPERATION_CONFORMSTO_TYPE);
	m_type_EOperation_createAssociation_Boolean_UnlimitedNatural = factory->createEOperation_in_EContainingClass(m_type_EClass, TYPE_EOPERATION_CREATEASSOCIATION_BOOLEAN_UNLIMITEDNATURAL);
	m_type_EOperation_getAssociations = factory->createEOperation_in_EContainingClass(m_type_EClass, TYPE_EOPERATION_GETASSOCIATIONS);
	
}

void UmlPackageImpl::createTypedElementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_typedElement_EClass = factory->createEClass_in_EPackage(package, TYPEDELEMENT_ECLASS);
	
	m_typedElement_EReference_type = factory->createEReference_in_EContainingClass(m_typedElement_EClass, TYPEDELEMENT_EREFERENCE_TYPE);
	
	
}

void UmlPackageImpl::createUnmarshallActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_unmarshallAction_EClass = factory->createEClass_in_EPackage(package, UNMARSHALLACTION_ECLASS);
	
	m_unmarshallAction_EReference_object = factory->createEReference_in_EContainingClass(m_unmarshallAction_EClass, UNMARSHALLACTION_EREFERENCE_OBJECT);
	m_unmarshallAction_EReference_result = factory->createEReference_in_EContainingClass(m_unmarshallAction_EClass, UNMARSHALLACTION_EREFERENCE_RESULT);
	m_unmarshallAction_EReference_unmarshallType = factory->createEReference_in_EContainingClass(m_unmarshallAction_EClass, UNMARSHALLACTION_EREFERENCE_UNMARSHALLTYPE);
	
	m_unmarshallAction_EOperation_multiplicity_of_object_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_unmarshallAction_EClass, UNMARSHALLACTION_EOPERATION_MULTIPLICITY_OF_OBJECT_EDIAGNOSTICCHAIN_EMAP);
	m_unmarshallAction_EOperation_number_of_result_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_unmarshallAction_EClass, UNMARSHALLACTION_EOPERATION_NUMBER_OF_RESULT_EDIAGNOSTICCHAIN_EMAP);
	m_unmarshallAction_EOperation_object_type_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_unmarshallAction_EClass, UNMARSHALLACTION_EOPERATION_OBJECT_TYPE_EDIAGNOSTICCHAIN_EMAP);
	m_unmarshallAction_EOperation_structural_feature_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_unmarshallAction_EClass, UNMARSHALLACTION_EOPERATION_STRUCTURAL_FEATURE_EDIAGNOSTICCHAIN_EMAP);
	m_unmarshallAction_EOperation_type_ordering_and_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_unmarshallAction_EClass, UNMARSHALLACTION_EOPERATION_TYPE_ORDERING_AND_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createUsageContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_usage_EClass = factory->createEClass_in_EPackage(package, USAGE_ECLASS);
	
	
	
}

void UmlPackageImpl::createUseCaseContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_useCase_EClass = factory->createEClass_in_EPackage(package, USECASE_ECLASS);
	
	m_useCase_EReference_extend = factory->createEReference_in_EContainingClass(m_useCase_EClass, USECASE_EREFERENCE_EXTEND);
	m_useCase_EReference_extensionPoint = factory->createEReference_in_EContainingClass(m_useCase_EClass, USECASE_EREFERENCE_EXTENSIONPOINT);
	m_useCase_EReference_include = factory->createEReference_in_EContainingClass(m_useCase_EClass, USECASE_EREFERENCE_INCLUDE);
	m_useCase_EReference_subject = factory->createEReference_in_EContainingClass(m_useCase_EClass, USECASE_EREFERENCE_SUBJECT);
	
	m_useCase_EOperation_allIncludedUseCases = factory->createEOperation_in_EContainingClass(m_useCase_EClass, USECASE_EOPERATION_ALLINCLUDEDUSECASES);
	m_useCase_EOperation_binary_associations_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_useCase_EClass, USECASE_EOPERATION_BINARY_ASSOCIATIONS_EDIAGNOSTICCHAIN_EMAP);
	m_useCase_EOperation_cannot_include_self_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_useCase_EClass, USECASE_EOPERATION_CANNOT_INCLUDE_SELF_EDIAGNOSTICCHAIN_EMAP);
	m_useCase_EOperation_must_have_name_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_useCase_EClass, USECASE_EOPERATION_MUST_HAVE_NAME_EDIAGNOSTICCHAIN_EMAP);
	m_useCase_EOperation_no_association_to_use_case_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_useCase_EClass, USECASE_EOPERATION_NO_ASSOCIATION_TO_USE_CASE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createValuePinContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_valuePin_EClass = factory->createEClass_in_EPackage(package, VALUEPIN_ECLASS);
	
	m_valuePin_EReference_value = factory->createEReference_in_EContainingClass(m_valuePin_EClass, VALUEPIN_EREFERENCE_VALUE);
	
	m_valuePin_EOperation_compatible_type_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_valuePin_EClass, VALUEPIN_EOPERATION_COMPATIBLE_TYPE_EDIAGNOSTICCHAIN_EMAP);
	m_valuePin_EOperation_no_incoming_edges_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_valuePin_EClass, VALUEPIN_EOPERATION_NO_INCOMING_EDGES_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createValueSpecificationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_valueSpecification_EClass = factory->createEClass_in_EPackage(package, VALUESPECIFICATION_ECLASS);
	
	m_valueSpecification_EReference_owningSlot = factory->createEReference_in_EContainingClass(m_valueSpecification_EClass, VALUESPECIFICATION_EREFERENCE_OWNINGSLOT);
	
	m_valueSpecification_EOperation_booleanValue = factory->createEOperation_in_EContainingClass(m_valueSpecification_EClass, VALUESPECIFICATION_EOPERATION_BOOLEANVALUE);
	m_valueSpecification_EOperation_integerValue = factory->createEOperation_in_EContainingClass(m_valueSpecification_EClass, VALUESPECIFICATION_EOPERATION_INTEGERVALUE);
	m_valueSpecification_EOperation_isComputable = factory->createEOperation_in_EContainingClass(m_valueSpecification_EClass, VALUESPECIFICATION_EOPERATION_ISCOMPUTABLE);
	m_valueSpecification_EOperation_isNull = factory->createEOperation_in_EContainingClass(m_valueSpecification_EClass, VALUESPECIFICATION_EOPERATION_ISNULL);
	m_valueSpecification_EOperation_realValue = factory->createEOperation_in_EContainingClass(m_valueSpecification_EClass, VALUESPECIFICATION_EOPERATION_REALVALUE);
	m_valueSpecification_EOperation_stringValue = factory->createEOperation_in_EContainingClass(m_valueSpecification_EClass, VALUESPECIFICATION_EOPERATION_STRINGVALUE);
	m_valueSpecification_EOperation_unlimitedValue = factory->createEOperation_in_EContainingClass(m_valueSpecification_EClass, VALUESPECIFICATION_EOPERATION_UNLIMITEDVALUE);
	
}

void UmlPackageImpl::createValueSpecificationActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_valueSpecificationAction_EClass = factory->createEClass_in_EPackage(package, VALUESPECIFICATIONACTION_ECLASS);
	
	m_valueSpecificationAction_EReference_result = factory->createEReference_in_EContainingClass(m_valueSpecificationAction_EClass, VALUESPECIFICATIONACTION_EREFERENCE_RESULT);
	m_valueSpecificationAction_EReference_value = factory->createEReference_in_EContainingClass(m_valueSpecificationAction_EClass, VALUESPECIFICATIONACTION_EREFERENCE_VALUE);
	
	m_valueSpecificationAction_EOperation_compatible_type_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_valueSpecificationAction_EClass, VALUESPECIFICATIONACTION_EOPERATION_COMPATIBLE_TYPE_EDIAGNOSTICCHAIN_EMAP);
	m_valueSpecificationAction_EOperation_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_valueSpecificationAction_EClass, VALUESPECIFICATIONACTION_EOPERATION_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createVariableContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_variable_EClass = factory->createEClass_in_EPackage(package, VARIABLE_ECLASS);
	
	m_variable_EReference_activityScope = factory->createEReference_in_EContainingClass(m_variable_EClass, VARIABLE_EREFERENCE_ACTIVITYSCOPE);
	m_variable_EReference_scope = factory->createEReference_in_EContainingClass(m_variable_EClass, VARIABLE_EREFERENCE_SCOPE);
	
	m_variable_EOperation_isAccessibleBy_Action = factory->createEOperation_in_EContainingClass(m_variable_EClass, VARIABLE_EOPERATION_ISACCESSIBLEBY_ACTION);
	
}

void UmlPackageImpl::createVariableActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_variableAction_EClass = factory->createEClass_in_EPackage(package, VARIABLEACTION_ECLASS);
	
	m_variableAction_EReference_variable = factory->createEReference_in_EContainingClass(m_variableAction_EClass, VARIABLEACTION_EREFERENCE_VARIABLE);
	
	m_variableAction_EOperation_scope_of_variable_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_variableAction_EClass, VARIABLEACTION_EOPERATION_SCOPE_OF_VARIABLE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createVertexContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_vertex_EClass = factory->createEClass_in_EPackage(package, VERTEX_ECLASS);
	
	m_vertex_EReference_container = factory->createEReference_in_EContainingClass(m_vertex_EClass, VERTEX_EREFERENCE_CONTAINER);
	m_vertex_EReference_incoming = factory->createEReference_in_EContainingClass(m_vertex_EClass, VERTEX_EREFERENCE_INCOMING);
	m_vertex_EReference_outgoing = factory->createEReference_in_EContainingClass(m_vertex_EClass, VERTEX_EREFERENCE_OUTGOING);
	
	m_vertex_EOperation_containingStateMachine = factory->createEOperation_in_EContainingClass(m_vertex_EClass, VERTEX_EOPERATION_CONTAININGSTATEMACHINE);
	m_vertex_EOperation_getIncomings = factory->createEOperation_in_EContainingClass(m_vertex_EClass, VERTEX_EOPERATION_GETINCOMINGS);
	m_vertex_EOperation_getOutgoings = factory->createEOperation_in_EContainingClass(m_vertex_EClass, VERTEX_EOPERATION_GETOUTGOINGS);
	m_vertex_EOperation_isContainedInRegion_Region = factory->createEOperation_in_EContainingClass(m_vertex_EClass, VERTEX_EOPERATION_ISCONTAINEDINREGION_REGION);
	m_vertex_EOperation_isContainedInState_State = factory->createEOperation_in_EContainingClass(m_vertex_EClass, VERTEX_EOPERATION_ISCONTAINEDINSTATE_STATE);
	
}

void UmlPackageImpl::createWriteLinkActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_writeLinkAction_EClass = factory->createEClass_in_EPackage(package, WRITELINKACTION_ECLASS);
	
	
	m_writeLinkAction_EOperation_allow_access_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_writeLinkAction_EClass, WRITELINKACTION_EOPERATION_ALLOW_ACCESS_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createWriteStructuralFeatureActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_writeStructuralFeatureAction_EClass = factory->createEClass_in_EPackage(package, WRITESTRUCTURALFEATUREACTION_ECLASS);
	
	m_writeStructuralFeatureAction_EReference_result = factory->createEReference_in_EContainingClass(m_writeStructuralFeatureAction_EClass, WRITESTRUCTURALFEATUREACTION_EREFERENCE_RESULT);
	m_writeStructuralFeatureAction_EReference_value = factory->createEReference_in_EContainingClass(m_writeStructuralFeatureAction_EClass, WRITESTRUCTURALFEATUREACTION_EREFERENCE_VALUE);
	
	m_writeStructuralFeatureAction_EOperation_multiplicity_of_result_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_writeStructuralFeatureAction_EClass, WRITESTRUCTURALFEATUREACTION_EOPERATION_MULTIPLICITY_OF_RESULT_EDIAGNOSTICCHAIN_EMAP);
	m_writeStructuralFeatureAction_EOperation_multiplicity_of_value_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_writeStructuralFeatureAction_EClass, WRITESTRUCTURALFEATUREACTION_EOPERATION_MULTIPLICITY_OF_VALUE_EDIAGNOSTICCHAIN_EMAP);
	m_writeStructuralFeatureAction_EOperation_type_of_result_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_writeStructuralFeatureAction_EClass, WRITESTRUCTURALFEATUREACTION_EOPERATION_TYPE_OF_RESULT_EDIAGNOSTICCHAIN_EMAP);
	m_writeStructuralFeatureAction_EOperation_type_of_value_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_writeStructuralFeatureAction_EClass, WRITESTRUCTURALFEATUREACTION_EOPERATION_TYPE_OF_VALUE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createWriteVariableActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_writeVariableAction_EClass = factory->createEClass_in_EPackage(package, WRITEVARIABLEACTION_ECLASS);
	
	m_writeVariableAction_EReference_value = factory->createEReference_in_EContainingClass(m_writeVariableAction_EClass, WRITEVARIABLEACTION_EREFERENCE_VALUE);
	
	m_writeVariableAction_EOperation_multiplicity_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_writeVariableAction_EClass, WRITEVARIABLEACTION_EOPERATION_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP);
	m_writeVariableAction_EOperation_value_type_EDiagnosticChain_EMap = factory->createEOperation_in_EContainingClass(m_writeVariableAction_EClass, WRITEVARIABLEACTION_EOPERATION_VALUE_TYPE_EDIAGNOSTICCHAIN_EMAP);
	
}

void UmlPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory)
{
	m_aggregationKind_EEnum = factory->createEEnum_in_EPackage(package, AGGREGATIONKIND_EENUM);
	m_callConcurrencyKind_EEnum = factory->createEEnum_in_EPackage(package, CALLCONCURRENCYKIND_EENUM);
	m_connectorKind_EEnum = factory->createEEnum_in_EPackage(package, CONNECTORKIND_EENUM);
	m_expansionKind_EEnum = factory->createEEnum_in_EPackage(package, EXPANSIONKIND_EENUM);
	m_interactionOperatorKind_EEnum = factory->createEEnum_in_EPackage(package, INTERACTIONOPERATORKIND_EENUM);
	m_messageKind_EEnum = factory->createEEnum_in_EPackage(package, MESSAGEKIND_EENUM);
	m_messageSort_EEnum = factory->createEEnum_in_EPackage(package, MESSAGESORT_EENUM);
	m_objectNodeOrderingKind_EEnum = factory->createEEnum_in_EPackage(package, OBJECTNODEORDERINGKIND_EENUM);
	m_parameterDirectionKind_EEnum = factory->createEEnum_in_EPackage(package, PARAMETERDIRECTIONKIND_EENUM);
	m_parameterEffectKind_EEnum = factory->createEEnum_in_EPackage(package, PARAMETEREFFECTKIND_EENUM);
	m_pseudostateKind_EEnum = factory->createEEnum_in_EPackage(package, PSEUDOSTATEKIND_EENUM);
	m_transitionKind_EEnum = factory->createEEnum_in_EPackage(package, TRANSITIONKIND_EENUM);
	m_visibilityKind_EEnum = factory->createEEnum_in_EPackage(package, VISIBILITYKIND_EENUM);
	
}
