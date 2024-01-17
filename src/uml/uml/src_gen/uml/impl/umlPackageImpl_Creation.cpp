#include "uml/impl/umlPackageImpl.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

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

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "types/typesPackage.hpp"
//include subpackages 
 
using namespace uml;

void umlPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();

	createAbstractionContent(package, factory);
	createAcceptCallActionContent(package, factory);
	createAcceptEventActionContent(package, factory);
	createActionContent(package, factory);
	createActionExecutionSpecificationContent(package, factory);
	createActionInputPinContent(package, factory);
	createActivityContent(package, factory);
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

void umlPackageImpl::createAbstractionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_abstraction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ABSTRACTION_CLASS);
	
	m_abstraction_Attribute_mapping = factory->createEReference_as_eReferences_in_EClass(m_abstraction_Class, ABSTRACTION_ATTRIBUTE_MAPPING);
	
	
}

void umlPackageImpl::createAcceptCallActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_acceptCallAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ACCEPTCALLACTION_CLASS);
	
	m_acceptCallAction_Attribute_returnInformation = factory->createEReference_as_eReferences_in_EClass(m_acceptCallAction_Class, ACCEPTCALLACTION_ATTRIBUTE_RETURNINFORMATION);
	
	
}

void umlPackageImpl::createAcceptEventActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_acceptEventAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ACCEPTEVENTACTION_CLASS);
	m_acceptEventAction_Attribute_isUnmarshall = factory->createEAttribute_as_eAttributes_in_EClass(m_acceptEventAction_Class, ACCEPTEVENTACTION_ATTRIBUTE_ISUNMARSHALL);
	
	m_acceptEventAction_Attribute_result = factory->createEReference_as_eReferences_in_EClass(m_acceptEventAction_Class, ACCEPTEVENTACTION_ATTRIBUTE_RESULT);
	m_acceptEventAction_Attribute_trigger = factory->createEReference_as_eReferences_in_EClass(m_acceptEventAction_Class, ACCEPTEVENTACTION_ATTRIBUTE_TRIGGER);
	
	
}

void umlPackageImpl::createActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_action_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ACTION_CLASS);
	m_action_Attribute_isLocallyReentrant = factory->createEAttribute_as_eAttributes_in_EClass(m_action_Class, ACTION_ATTRIBUTE_ISLOCALLYREENTRANT);
	
	m_action_Attribute_context = factory->createEReference_as_eReferences_in_EClass(m_action_Class, ACTION_ATTRIBUTE_CONTEXT);
	m_action_Attribute_input = factory->createEReference_as_eReferences_in_EClass(m_action_Class, ACTION_ATTRIBUTE_INPUT);
	m_action_Attribute_localPostcondition = factory->createEReference_as_eReferences_in_EClass(m_action_Class, ACTION_ATTRIBUTE_LOCALPOSTCONDITION);
	m_action_Attribute_localPrecondition = factory->createEReference_as_eReferences_in_EClass(m_action_Class, ACTION_ATTRIBUTE_LOCALPRECONDITION);
	m_action_Attribute_output = factory->createEReference_as_eReferences_in_EClass(m_action_Class, ACTION_ATTRIBUTE_OUTPUT);
	
	m_action_Operation_allActions = factory->createEOperation_as_eOperations_in_EClass(m_action_Class, ACTION_OPERATION_ALLACTIONS);
	m_action_Operation_allOwnedNodes = factory->createEOperation_as_eOperations_in_EClass(m_action_Class, ACTION_OPERATION_ALLOWNEDNODES);
	m_action_Operation_containingBehavior = factory->createEOperation_as_eOperations_in_EClass(m_action_Class, ACTION_OPERATION_CONTAININGBEHAVIOR);
	m_action_Operation_getContext = factory->createEOperation_as_eOperations_in_EClass(m_action_Class, ACTION_OPERATION_GETCONTEXT);
	
}

void umlPackageImpl::createActionExecutionSpecificationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_actionExecutionSpecification_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ACTIONEXECUTIONSPECIFICATION_CLASS);
	
	m_actionExecutionSpecification_Attribute_action = factory->createEReference_as_eReferences_in_EClass(m_actionExecutionSpecification_Class, ACTIONEXECUTIONSPECIFICATION_ATTRIBUTE_ACTION);
	
	
}

void umlPackageImpl::createActionInputPinContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_actionInputPin_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ACTIONINPUTPIN_CLASS);
	
	m_actionInputPin_Attribute_fromAction = factory->createEReference_as_eReferences_in_EClass(m_actionInputPin_Class, ACTIONINPUTPIN_ATTRIBUTE_FROMACTION);
	
	
}

void umlPackageImpl::createActivityContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_activity_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ACTIVITY_CLASS);
	m_activity_Attribute_isReadOnly = factory->createEAttribute_as_eAttributes_in_EClass(m_activity_Class, ACTIVITY_ATTRIBUTE_ISREADONLY);
	m_activity_Attribute_isSingleExecution = factory->createEAttribute_as_eAttributes_in_EClass(m_activity_Class, ACTIVITY_ATTRIBUTE_ISSINGLEEXECUTION);
	
	m_activity_Attribute_edge = factory->createEReference_as_eReferences_in_EClass(m_activity_Class, ACTIVITY_ATTRIBUTE_EDGE);
	m_activity_Attribute_group = factory->createEReference_as_eReferences_in_EClass(m_activity_Class, ACTIVITY_ATTRIBUTE_GROUP);
	m_activity_Attribute_node = factory->createEReference_as_eReferences_in_EClass(m_activity_Class, ACTIVITY_ATTRIBUTE_NODE);
	m_activity_Attribute_ownedGroup = factory->createEReference_as_eReferences_in_EClass(m_activity_Class, ACTIVITY_ATTRIBUTE_OWNEDGROUP);
	m_activity_Attribute_ownedNode = factory->createEReference_as_eReferences_in_EClass(m_activity_Class, ACTIVITY_ATTRIBUTE_OWNEDNODE);
	m_activity_Attribute_partition = factory->createEReference_as_eReferences_in_EClass(m_activity_Class, ACTIVITY_ATTRIBUTE_PARTITION);
	m_activity_Attribute_structuredNode = factory->createEReference_as_eReferences_in_EClass(m_activity_Class, ACTIVITY_ATTRIBUTE_STRUCTUREDNODE);
	m_activity_Attribute_variable = factory->createEReference_as_eReferences_in_EClass(m_activity_Class, ACTIVITY_ATTRIBUTE_VARIABLE);
	
	
}

void umlPackageImpl::createActivityEdgeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_activityEdge_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ACTIVITYEDGE_CLASS);
	
	m_activityEdge_Attribute_activity = factory->createEReference_as_eReferences_in_EClass(m_activityEdge_Class, ACTIVITYEDGE_ATTRIBUTE_ACTIVITY);
	m_activityEdge_Attribute_guard = factory->createEReference_as_eReferences_in_EClass(m_activityEdge_Class, ACTIVITYEDGE_ATTRIBUTE_GUARD);
	m_activityEdge_Attribute_inGroup = factory->createEReference_as_eReferences_in_EClass(m_activityEdge_Class, ACTIVITYEDGE_ATTRIBUTE_INGROUP);
	m_activityEdge_Attribute_inPartition = factory->createEReference_as_eReferences_in_EClass(m_activityEdge_Class, ACTIVITYEDGE_ATTRIBUTE_INPARTITION);
	m_activityEdge_Attribute_inStructuredNode = factory->createEReference_as_eReferences_in_EClass(m_activityEdge_Class, ACTIVITYEDGE_ATTRIBUTE_INSTRUCTUREDNODE);
	m_activityEdge_Attribute_interrupts = factory->createEReference_as_eReferences_in_EClass(m_activityEdge_Class, ACTIVITYEDGE_ATTRIBUTE_INTERRUPTS);
	m_activityEdge_Attribute_redefinedEdge = factory->createEReference_as_eReferences_in_EClass(m_activityEdge_Class, ACTIVITYEDGE_ATTRIBUTE_REDEFINEDEDGE);
	m_activityEdge_Attribute_source = factory->createEReference_as_eReferences_in_EClass(m_activityEdge_Class, ACTIVITYEDGE_ATTRIBUTE_SOURCE);
	m_activityEdge_Attribute_target = factory->createEReference_as_eReferences_in_EClass(m_activityEdge_Class, ACTIVITYEDGE_ATTRIBUTE_TARGET);
	m_activityEdge_Attribute_weight = factory->createEReference_as_eReferences_in_EClass(m_activityEdge_Class, ACTIVITYEDGE_ATTRIBUTE_WEIGHT);
	
	
}

void umlPackageImpl::createActivityFinalNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_activityFinalNode_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ACTIVITYFINALNODE_CLASS);
	
	
	
}

void umlPackageImpl::createActivityGroupContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_activityGroup_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ACTIVITYGROUP_CLASS);
	
	m_activityGroup_Attribute_containedEdge = factory->createEReference_as_eReferences_in_EClass(m_activityGroup_Class, ACTIVITYGROUP_ATTRIBUTE_CONTAINEDEDGE);
	m_activityGroup_Attribute_containedNode = factory->createEReference_as_eReferences_in_EClass(m_activityGroup_Class, ACTIVITYGROUP_ATTRIBUTE_CONTAINEDNODE);
	m_activityGroup_Attribute_inActivity = factory->createEReference_as_eReferences_in_EClass(m_activityGroup_Class, ACTIVITYGROUP_ATTRIBUTE_INACTIVITY);
	m_activityGroup_Attribute_subgroup = factory->createEReference_as_eReferences_in_EClass(m_activityGroup_Class, ACTIVITYGROUP_ATTRIBUTE_SUBGROUP);
	m_activityGroup_Attribute_superGroup = factory->createEReference_as_eReferences_in_EClass(m_activityGroup_Class, ACTIVITYGROUP_ATTRIBUTE_SUPERGROUP);
	
	m_activityGroup_Operation_containingActivity = factory->createEOperation_as_eOperations_in_EClass(m_activityGroup_Class, ACTIVITYGROUP_OPERATION_CONTAININGACTIVITY);
	
}

void umlPackageImpl::createActivityNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_activityNode_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ACTIVITYNODE_CLASS);
	
	m_activityNode_Attribute_activity = factory->createEReference_as_eReferences_in_EClass(m_activityNode_Class, ACTIVITYNODE_ATTRIBUTE_ACTIVITY);
	m_activityNode_Attribute_inGroup = factory->createEReference_as_eReferences_in_EClass(m_activityNode_Class, ACTIVITYNODE_ATTRIBUTE_INGROUP);
	m_activityNode_Attribute_inInterruptibleRegion = factory->createEReference_as_eReferences_in_EClass(m_activityNode_Class, ACTIVITYNODE_ATTRIBUTE_ININTERRUPTIBLEREGION);
	m_activityNode_Attribute_inPartition = factory->createEReference_as_eReferences_in_EClass(m_activityNode_Class, ACTIVITYNODE_ATTRIBUTE_INPARTITION);
	m_activityNode_Attribute_inStructuredNode = factory->createEReference_as_eReferences_in_EClass(m_activityNode_Class, ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE);
	m_activityNode_Attribute_incoming = factory->createEReference_as_eReferences_in_EClass(m_activityNode_Class, ACTIVITYNODE_ATTRIBUTE_INCOMING);
	m_activityNode_Attribute_outgoing = factory->createEReference_as_eReferences_in_EClass(m_activityNode_Class, ACTIVITYNODE_ATTRIBUTE_OUTGOING);
	m_activityNode_Attribute_redefinedNode = factory->createEReference_as_eReferences_in_EClass(m_activityNode_Class, ACTIVITYNODE_ATTRIBUTE_REDEFINEDNODE);
	
	m_activityNode_Operation_containingActivity = factory->createEOperation_as_eOperations_in_EClass(m_activityNode_Class, ACTIVITYNODE_OPERATION_CONTAININGACTIVITY);
	
}

void umlPackageImpl::createActivityParameterNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_activityParameterNode_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ACTIVITYPARAMETERNODE_CLASS);
	
	m_activityParameterNode_Attribute_parameter = factory->createEReference_as_eReferences_in_EClass(m_activityParameterNode_Class, ACTIVITYPARAMETERNODE_ATTRIBUTE_PARAMETER);
	
	
}

void umlPackageImpl::createActivityPartitionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_activityPartition_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ACTIVITYPARTITION_CLASS);
	m_activityPartition_Attribute_isDimension = factory->createEAttribute_as_eAttributes_in_EClass(m_activityPartition_Class, ACTIVITYPARTITION_ATTRIBUTE_ISDIMENSION);
	m_activityPartition_Attribute_isExternal = factory->createEAttribute_as_eAttributes_in_EClass(m_activityPartition_Class, ACTIVITYPARTITION_ATTRIBUTE_ISEXTERNAL);
	
	m_activityPartition_Attribute_edge = factory->createEReference_as_eReferences_in_EClass(m_activityPartition_Class, ACTIVITYPARTITION_ATTRIBUTE_EDGE);
	m_activityPartition_Attribute_node = factory->createEReference_as_eReferences_in_EClass(m_activityPartition_Class, ACTIVITYPARTITION_ATTRIBUTE_NODE);
	m_activityPartition_Attribute_represents = factory->createEReference_as_eReferences_in_EClass(m_activityPartition_Class, ACTIVITYPARTITION_ATTRIBUTE_REPRESENTS);
	m_activityPartition_Attribute_subpartition = factory->createEReference_as_eReferences_in_EClass(m_activityPartition_Class, ACTIVITYPARTITION_ATTRIBUTE_SUBPARTITION);
	m_activityPartition_Attribute_superPartition = factory->createEReference_as_eReferences_in_EClass(m_activityPartition_Class, ACTIVITYPARTITION_ATTRIBUTE_SUPERPARTITION);
	
	
}

void umlPackageImpl::createActorContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_actor_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ACTOR_CLASS);
	
	
	
}

void umlPackageImpl::createAddStructuralFeatureValueActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_addStructuralFeatureValueAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ADDSTRUCTURALFEATUREVALUEACTION_CLASS);
	m_addStructuralFeatureValueAction_Attribute_isReplaceAll = factory->createEAttribute_as_eAttributes_in_EClass(m_addStructuralFeatureValueAction_Class, ADDSTRUCTURALFEATUREVALUEACTION_ATTRIBUTE_ISREPLACEALL);
	
	m_addStructuralFeatureValueAction_Attribute_insertAt = factory->createEReference_as_eReferences_in_EClass(m_addStructuralFeatureValueAction_Class, ADDSTRUCTURALFEATUREVALUEACTION_ATTRIBUTE_INSERTAT);
	
	
}

void umlPackageImpl::createAddVariableValueActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_addVariableValueAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ADDVARIABLEVALUEACTION_CLASS);
	m_addVariableValueAction_Attribute_isReplaceAll = factory->createEAttribute_as_eAttributes_in_EClass(m_addVariableValueAction_Class, ADDVARIABLEVALUEACTION_ATTRIBUTE_ISREPLACEALL);
	
	m_addVariableValueAction_Attribute_insertAt = factory->createEReference_as_eReferences_in_EClass(m_addVariableValueAction_Class, ADDVARIABLEVALUEACTION_ATTRIBUTE_INSERTAT);
	
	
}

void umlPackageImpl::createAnyReceiveEventContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_anyReceiveEvent_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ANYRECEIVEEVENT_CLASS);
	
	
	
}

void umlPackageImpl::createArgumentContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_argument_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ARGUMENT_CLASS);
	m_argument_Attribute_name = factory->createEAttribute_as_eAttributes_in_EClass(m_argument_Class, ARGUMENT_ATTRIBUTE_NAME);
	
	m_argument_Attribute_value = factory->createEReference_as_eReferences_in_EClass(m_argument_Class, ARGUMENT_ATTRIBUTE_VALUE);
	
	
}

void umlPackageImpl::createArtifactContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_artifact_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ARTIFACT_CLASS);
	m_artifact_Attribute_fileName = factory->createEAttribute_as_eAttributes_in_EClass(m_artifact_Class, ARTIFACT_ATTRIBUTE_FILENAME);
	
	m_artifact_Attribute_manifestation = factory->createEReference_as_eReferences_in_EClass(m_artifact_Class, ARTIFACT_ATTRIBUTE_MANIFESTATION);
	m_artifact_Attribute_nestedArtifact = factory->createEReference_as_eReferences_in_EClass(m_artifact_Class, ARTIFACT_ATTRIBUTE_NESTEDARTIFACT);
	m_artifact_Attribute_ownedAttribute = factory->createEReference_as_eReferences_in_EClass(m_artifact_Class, ARTIFACT_ATTRIBUTE_OWNEDATTRIBUTE);
	m_artifact_Attribute_ownedOperation = factory->createEReference_as_eReferences_in_EClass(m_artifact_Class, ARTIFACT_ATTRIBUTE_OWNEDOPERATION);
	
	m_artifact_Operation_createOwnedAttribute_String_UnlimitedNatural = factory->createEOperation_as_eOperations_in_EClass(m_artifact_Class, ARTIFACT_OPERATION_CREATEOWNEDATTRIBUTE_STRING_UNLIMITEDNATURAL);
	m_artifact_Operation_createOwnedOperation_String_Type = factory->createEOperation_as_eOperations_in_EClass(m_artifact_Class, ARTIFACT_OPERATION_CREATEOWNEDOPERATION_STRING_TYPE);
	
}

void umlPackageImpl::createAssociationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_association_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ASSOCIATION_CLASS);
	m_association_Attribute_isDerived = factory->createEAttribute_as_eAttributes_in_EClass(m_association_Class, ASSOCIATION_ATTRIBUTE_ISDERIVED);
	
	m_association_Attribute_endType = factory->createEReference_as_eReferences_in_EClass(m_association_Class, ASSOCIATION_ATTRIBUTE_ENDTYPE);
	m_association_Attribute_memberEnd = factory->createEReference_as_eReferences_in_EClass(m_association_Class, ASSOCIATION_ATTRIBUTE_MEMBEREND);
	m_association_Attribute_navigableOwnedEnd = factory->createEReference_as_eReferences_in_EClass(m_association_Class, ASSOCIATION_ATTRIBUTE_NAVIGABLEOWNEDEND);
	m_association_Attribute_ownedEnd = factory->createEReference_as_eReferences_in_EClass(m_association_Class, ASSOCIATION_ATTRIBUTE_OWNEDEND);
	
	m_association_Operation_getEndTypes = factory->createEOperation_as_eOperations_in_EClass(m_association_Class, ASSOCIATION_OPERATION_GETENDTYPES);
	m_association_Operation_isBinary = factory->createEOperation_as_eOperations_in_EClass(m_association_Class, ASSOCIATION_OPERATION_ISBINARY);
	
}

void umlPackageImpl::createAssociationClassContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_associationClass_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ASSOCIATIONCLASS_CLASS);
	
	
	
}

void umlPackageImpl::createBehaviorContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_behavior_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, BEHAVIOR_CLASS);
	m_behavior_Attribute_isReentrant = factory->createEAttribute_as_eAttributes_in_EClass(m_behavior_Class, BEHAVIOR_ATTRIBUTE_ISREENTRANT);
	
	m_behavior_Attribute_behavioredClassifier = factory->createEReference_as_eReferences_in_EClass(m_behavior_Class, BEHAVIOR_ATTRIBUTE_BEHAVIOREDCLASSIFIER);
	m_behavior_Attribute_context = factory->createEReference_as_eReferences_in_EClass(m_behavior_Class, BEHAVIOR_ATTRIBUTE_CONTEXT);
	m_behavior_Attribute_ownedParameter = factory->createEReference_as_eReferences_in_EClass(m_behavior_Class, BEHAVIOR_ATTRIBUTE_OWNEDPARAMETER);
	m_behavior_Attribute_ownedParameterSet = factory->createEReference_as_eReferences_in_EClass(m_behavior_Class, BEHAVIOR_ATTRIBUTE_OWNEDPARAMETERSET);
	m_behavior_Attribute_postcondition = factory->createEReference_as_eReferences_in_EClass(m_behavior_Class, BEHAVIOR_ATTRIBUTE_POSTCONDITION);
	m_behavior_Attribute_precondition = factory->createEReference_as_eReferences_in_EClass(m_behavior_Class, BEHAVIOR_ATTRIBUTE_PRECONDITION);
	m_behavior_Attribute_redefinedBehavior = factory->createEReference_as_eReferences_in_EClass(m_behavior_Class, BEHAVIOR_ATTRIBUTE_REDEFINEDBEHAVIOR);
	m_behavior_Attribute_specification = factory->createEReference_as_eReferences_in_EClass(m_behavior_Class, BEHAVIOR_ATTRIBUTE_SPECIFICATION);
	
	m_behavior_Operation_behavioredClassifier_Element = factory->createEOperation_as_eOperations_in_EClass(m_behavior_Class, BEHAVIOR_OPERATION_BEHAVIOREDCLASSIFIER_ELEMENT);
	m_behavior_Operation_getContext = factory->createEOperation_as_eOperations_in_EClass(m_behavior_Class, BEHAVIOR_OPERATION_GETCONTEXT);
	m_behavior_Operation_inputParameters = factory->createEOperation_as_eOperations_in_EClass(m_behavior_Class, BEHAVIOR_OPERATION_INPUTPARAMETERS);
	m_behavior_Operation_outputParameters = factory->createEOperation_as_eOperations_in_EClass(m_behavior_Class, BEHAVIOR_OPERATION_OUTPUTPARAMETERS);
	
}

void umlPackageImpl::createBehaviorExecutionSpecificationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_behaviorExecutionSpecification_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, BEHAVIOREXECUTIONSPECIFICATION_CLASS);
	
	m_behaviorExecutionSpecification_Attribute_behavior = factory->createEReference_as_eReferences_in_EClass(m_behaviorExecutionSpecification_Class, BEHAVIOREXECUTIONSPECIFICATION_ATTRIBUTE_BEHAVIOR);
	
	
}

void umlPackageImpl::createBehavioralFeatureContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_behavioralFeature_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, BEHAVIORALFEATURE_CLASS);
	m_behavioralFeature_Attribute_concurrency = factory->createEAttribute_as_eAttributes_in_EClass(m_behavioralFeature_Class, BEHAVIORALFEATURE_ATTRIBUTE_CONCURRENCY);
	m_behavioralFeature_Attribute_isAbstract = factory->createEAttribute_as_eAttributes_in_EClass(m_behavioralFeature_Class, BEHAVIORALFEATURE_ATTRIBUTE_ISABSTRACT);
	
	m_behavioralFeature_Attribute_method = factory->createEReference_as_eReferences_in_EClass(m_behavioralFeature_Class, BEHAVIORALFEATURE_ATTRIBUTE_METHOD);
	m_behavioralFeature_Attribute_ownedParameter = factory->createEReference_as_eReferences_in_EClass(m_behavioralFeature_Class, BEHAVIORALFEATURE_ATTRIBUTE_OWNEDPARAMETER);
	m_behavioralFeature_Attribute_ownedParameterSet = factory->createEReference_as_eReferences_in_EClass(m_behavioralFeature_Class, BEHAVIORALFEATURE_ATTRIBUTE_OWNEDPARAMETERSET);
	m_behavioralFeature_Attribute_raisedException = factory->createEReference_as_eReferences_in_EClass(m_behavioralFeature_Class, BEHAVIORALFEATURE_ATTRIBUTE_RAISEDEXCEPTION);
	
	m_behavioralFeature_Operation_createReturnResult_String_Type = factory->createEOperation_as_eOperations_in_EClass(m_behavioralFeature_Class, BEHAVIORALFEATURE_OPERATION_CREATERETURNRESULT_STRING_TYPE);
	m_behavioralFeature_Operation_inputParameters = factory->createEOperation_as_eOperations_in_EClass(m_behavioralFeature_Class, BEHAVIORALFEATURE_OPERATION_INPUTPARAMETERS);
	m_behavioralFeature_Operation_outputParameters = factory->createEOperation_as_eOperations_in_EClass(m_behavioralFeature_Class, BEHAVIORALFEATURE_OPERATION_OUTPUTPARAMETERS);
	
}

void umlPackageImpl::createBehavioredClassifierContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_behavioredClassifier_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, BEHAVIOREDCLASSIFIER_CLASS);
	
	m_behavioredClassifier_Attribute_classifierBehavior = factory->createEReference_as_eReferences_in_EClass(m_behavioredClassifier_Class, BEHAVIOREDCLASSIFIER_ATTRIBUTE_CLASSIFIERBEHAVIOR);
	m_behavioredClassifier_Attribute_interfaceRealization = factory->createEReference_as_eReferences_in_EClass(m_behavioredClassifier_Class, BEHAVIOREDCLASSIFIER_ATTRIBUTE_INTERFACEREALIZATION);
	m_behavioredClassifier_Attribute_ownedBehavior = factory->createEReference_as_eReferences_in_EClass(m_behavioredClassifier_Class, BEHAVIOREDCLASSIFIER_ATTRIBUTE_OWNEDBEHAVIOR);
	
	m_behavioredClassifier_Operation_getAllImplementedInterfaces = factory->createEOperation_as_eOperations_in_EClass(m_behavioredClassifier_Class, BEHAVIOREDCLASSIFIER_OPERATION_GETALLIMPLEMENTEDINTERFACES);
	m_behavioredClassifier_Operation_getImplementedInterfaces = factory->createEOperation_as_eOperations_in_EClass(m_behavioredClassifier_Class, BEHAVIOREDCLASSIFIER_OPERATION_GETIMPLEMENTEDINTERFACES);
	
}

void umlPackageImpl::createBroadcastSignalActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_broadcastSignalAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, BROADCASTSIGNALACTION_CLASS);
	
	m_broadcastSignalAction_Attribute_signal = factory->createEReference_as_eReferences_in_EClass(m_broadcastSignalAction_Class, BROADCASTSIGNALACTION_ATTRIBUTE_SIGNAL);
	
	
}

void umlPackageImpl::createCallActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_callAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CALLACTION_CLASS);
	m_callAction_Attribute_isSynchronous = factory->createEAttribute_as_eAttributes_in_EClass(m_callAction_Class, CALLACTION_ATTRIBUTE_ISSYNCHRONOUS);
	
	m_callAction_Attribute_result = factory->createEReference_as_eReferences_in_EClass(m_callAction_Class, CALLACTION_ATTRIBUTE_RESULT);
	
	m_callAction_Operation_inputParameters = factory->createEOperation_as_eOperations_in_EClass(m_callAction_Class, CALLACTION_OPERATION_INPUTPARAMETERS);
	m_callAction_Operation_outputParameters = factory->createEOperation_as_eOperations_in_EClass(m_callAction_Class, CALLACTION_OPERATION_OUTPUTPARAMETERS);
	
}

void umlPackageImpl::createCallBehaviorActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_callBehaviorAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CALLBEHAVIORACTION_CLASS);
	
	m_callBehaviorAction_Attribute_behavior = factory->createEReference_as_eReferences_in_EClass(m_callBehaviorAction_Class, CALLBEHAVIORACTION_ATTRIBUTE_BEHAVIOR);
	
	
}

void umlPackageImpl::createCallEventContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_callEvent_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CALLEVENT_CLASS);
	
	m_callEvent_Attribute_operation = factory->createEReference_as_eReferences_in_EClass(m_callEvent_Class, CALLEVENT_ATTRIBUTE_OPERATION);
	
	
}

void umlPackageImpl::createCallOperationActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_callOperationAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CALLOPERATIONACTION_CLASS);
	
	m_callOperationAction_Attribute_operation = factory->createEReference_as_eReferences_in_EClass(m_callOperationAction_Class, CALLOPERATIONACTION_ATTRIBUTE_OPERATION);
	m_callOperationAction_Attribute_target = factory->createEReference_as_eReferences_in_EClass(m_callOperationAction_Class, CALLOPERATIONACTION_ATTRIBUTE_TARGET);
	
	
}

void umlPackageImpl::createCentralBufferNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_centralBufferNode_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CENTRALBUFFERNODE_CLASS);
	
	
	
}

void umlPackageImpl::createChangeEventContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_changeEvent_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CHANGEEVENT_CLASS);
	
	m_changeEvent_Attribute_changeExpression = factory->createEReference_as_eReferences_in_EClass(m_changeEvent_Class, CHANGEEVENT_ATTRIBUTE_CHANGEEXPRESSION);
	
	
}

void umlPackageImpl::createClassContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_class_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CLASS_CLASS);
	m_class_Attribute_isActive = factory->createEAttribute_as_eAttributes_in_EClass(m_class_Class, CLASS_ATTRIBUTE_ISACTIVE);
	
	m_class_Attribute_extension = factory->createEReference_as_eReferences_in_EClass(m_class_Class, CLASS_ATTRIBUTE_EXTENSION);
	m_class_Attribute_nestedClassifier = factory->createEReference_as_eReferences_in_EClass(m_class_Class, CLASS_ATTRIBUTE_NESTEDCLASSIFIER);
	m_class_Attribute_ownedAttribute = factory->createEReference_as_eReferences_in_EClass(m_class_Class, CLASS_ATTRIBUTE_OWNEDATTRIBUTE);
	m_class_Attribute_ownedOperation = factory->createEReference_as_eReferences_in_EClass(m_class_Class, CLASS_ATTRIBUTE_OWNEDOPERATION);
	m_class_Attribute_ownedReception = factory->createEReference_as_eReferences_in_EClass(m_class_Class, CLASS_ATTRIBUTE_OWNEDRECEPTION);
	m_class_Attribute_superClass = factory->createEReference_as_eReferences_in_EClass(m_class_Class, CLASS_ATTRIBUTE_SUPERCLASS);
	
	m_class_Operation_getAllOperations = factory->createEOperation_as_eOperations_in_EClass(m_class_Class, CLASS_OPERATION_GETALLOPERATIONS);
	m_class_Operation_getExtensions = factory->createEOperation_as_eOperations_in_EClass(m_class_Class, CLASS_OPERATION_GETEXTENSIONS);
	m_class_Operation_getSuperClasses = factory->createEOperation_as_eOperations_in_EClass(m_class_Class, CLASS_OPERATION_GETSUPERCLASSES);
	m_class_Operation_isMetaclass = factory->createEOperation_as_eOperations_in_EClass(m_class_Class, CLASS_OPERATION_ISMETACLASS);
	
}

void umlPackageImpl::createClassifierContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_classifier_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CLASSIFIER_CLASS);
	m_classifier_Attribute_isAbstract = factory->createEAttribute_as_eAttributes_in_EClass(m_classifier_Class, CLASSIFIER_ATTRIBUTE_ISABSTRACT);
	m_classifier_Attribute_isFinalSpecialization = factory->createEAttribute_as_eAttributes_in_EClass(m_classifier_Class, CLASSIFIER_ATTRIBUTE_ISFINALSPECIALIZATION);
	
	m_classifier_Attribute_attribute = factory->createEReference_as_eReferences_in_EClass(m_classifier_Class, CLASSIFIER_ATTRIBUTE_ATTRIBUTE);
	m_classifier_Attribute_collaborationUse = factory->createEReference_as_eReferences_in_EClass(m_classifier_Class, CLASSIFIER_ATTRIBUTE_COLLABORATIONUSE);
	m_classifier_Attribute_feature = factory->createEReference_as_eReferences_in_EClass(m_classifier_Class, CLASSIFIER_ATTRIBUTE_FEATURE);
	m_classifier_Attribute_general = factory->createEReference_as_eReferences_in_EClass(m_classifier_Class, CLASSIFIER_ATTRIBUTE_GENERAL);
	m_classifier_Attribute_generalization = factory->createEReference_as_eReferences_in_EClass(m_classifier_Class, CLASSIFIER_ATTRIBUTE_GENERALIZATION);
	m_classifier_Attribute_inheritedMember = factory->createEReference_as_eReferences_in_EClass(m_classifier_Class, CLASSIFIER_ATTRIBUTE_INHERITEDMEMBER);
	m_classifier_Attribute_ownedUseCase = factory->createEReference_as_eReferences_in_EClass(m_classifier_Class, CLASSIFIER_ATTRIBUTE_OWNEDUSECASE);
	m_classifier_Attribute_powertypeExtent = factory->createEReference_as_eReferences_in_EClass(m_classifier_Class, CLASSIFIER_ATTRIBUTE_POWERTYPEEXTENT);
	m_classifier_Attribute_redefinedClassifier = factory->createEReference_as_eReferences_in_EClass(m_classifier_Class, CLASSIFIER_ATTRIBUTE_REDEFINEDCLASSIFIER);
	m_classifier_Attribute_representation = factory->createEReference_as_eReferences_in_EClass(m_classifier_Class, CLASSIFIER_ATTRIBUTE_REPRESENTATION);
	m_classifier_Attribute_substitution = factory->createEReference_as_eReferences_in_EClass(m_classifier_Class, CLASSIFIER_ATTRIBUTE_SUBSTITUTION);
	m_classifier_Attribute_useCase = factory->createEReference_as_eReferences_in_EClass(m_classifier_Class, CLASSIFIER_ATTRIBUTE_USECASE);
	
	m_classifier_Operation_allAttributes = factory->createEOperation_as_eOperations_in_EClass(m_classifier_Class, CLASSIFIER_OPERATION_ALLATTRIBUTES);
	m_classifier_Operation_allFeatures = factory->createEOperation_as_eOperations_in_EClass(m_classifier_Class, CLASSIFIER_OPERATION_ALLFEATURES);
	m_classifier_Operation_allParents = factory->createEOperation_as_eOperations_in_EClass(m_classifier_Class, CLASSIFIER_OPERATION_ALLPARENTS);
	m_classifier_Operation_allRealizedInterfaces = factory->createEOperation_as_eOperations_in_EClass(m_classifier_Class, CLASSIFIER_OPERATION_ALLREALIZEDINTERFACES);
	m_classifier_Operation_allSlottableFeatures = factory->createEOperation_as_eOperations_in_EClass(m_classifier_Class, CLASSIFIER_OPERATION_ALLSLOTTABLEFEATURES);
	m_classifier_Operation_allUsedInterfaces = factory->createEOperation_as_eOperations_in_EClass(m_classifier_Class, CLASSIFIER_OPERATION_ALLUSEDINTERFACES);
	m_classifier_Operation_directlyRealizedInterfaces = factory->createEOperation_as_eOperations_in_EClass(m_classifier_Class, CLASSIFIER_OPERATION_DIRECTLYREALIZEDINTERFACES);
	m_classifier_Operation_directlyUsedInterfaces = factory->createEOperation_as_eOperations_in_EClass(m_classifier_Class, CLASSIFIER_OPERATION_DIRECTLYUSEDINTERFACES);
	m_classifier_Operation_getAllAttributes = factory->createEOperation_as_eOperations_in_EClass(m_classifier_Class, CLASSIFIER_OPERATION_GETALLATTRIBUTES);
	m_classifier_Operation_getAllOperations = factory->createEOperation_as_eOperations_in_EClass(m_classifier_Class, CLASSIFIER_OPERATION_GETALLOPERATIONS);
	m_classifier_Operation_getAllUsedInterfaces = factory->createEOperation_as_eOperations_in_EClass(m_classifier_Class, CLASSIFIER_OPERATION_GETALLUSEDINTERFACES);
	m_classifier_Operation_getGenerals = factory->createEOperation_as_eOperations_in_EClass(m_classifier_Class, CLASSIFIER_OPERATION_GETGENERALS);
	m_classifier_Operation_getInheritedMembers = factory->createEOperation_as_eOperations_in_EClass(m_classifier_Class, CLASSIFIER_OPERATION_GETINHERITEDMEMBERS);
	m_classifier_Operation_getOperation_String_Type = factory->createEOperation_as_eOperations_in_EClass(m_classifier_Class, CLASSIFIER_OPERATION_GETOPERATION_STRING_TYPE);
	m_classifier_Operation_getOperation_String_Boolean = factory->createEOperation_as_eOperations_in_EClass(m_classifier_Class, CLASSIFIER_OPERATION_GETOPERATION_STRING_BOOLEAN);
	m_classifier_Operation_getOperations = factory->createEOperation_as_eOperations_in_EClass(m_classifier_Class, CLASSIFIER_OPERATION_GETOPERATIONS);
	m_classifier_Operation_getPropertyValue_String = factory->createEOperation_as_eOperations_in_EClass(m_classifier_Class, CLASSIFIER_OPERATION_GETPROPERTYVALUE_STRING);
	m_classifier_Operation_getUsedInterfaces = factory->createEOperation_as_eOperations_in_EClass(m_classifier_Class, CLASSIFIER_OPERATION_GETUSEDINTERFACES);
	m_classifier_Operation_hasVisibilityOf_NamedElement = factory->createEOperation_as_eOperations_in_EClass(m_classifier_Class, CLASSIFIER_OPERATION_HASVISIBILITYOF_NAMEDELEMENT);
	m_classifier_Operation_inherit_NamedElement = factory->createEOperation_as_eOperations_in_EClass(m_classifier_Class, CLASSIFIER_OPERATION_INHERIT_NAMEDELEMENT);
	m_classifier_Operation_inheritableMembers_Classifier = factory->createEOperation_as_eOperations_in_EClass(m_classifier_Class, CLASSIFIER_OPERATION_INHERITABLEMEMBERS_CLASSIFIER);
	m_classifier_Operation_isSubstitutableFor_Classifier = factory->createEOperation_as_eOperations_in_EClass(m_classifier_Class, CLASSIFIER_OPERATION_ISSUBSTITUTABLEFOR_CLASSIFIER);
	m_classifier_Operation_maySpecializeType_Classifier = factory->createEOperation_as_eOperations_in_EClass(m_classifier_Class, CLASSIFIER_OPERATION_MAYSPECIALIZETYPE_CLASSIFIER);
	m_classifier_Operation_parents = factory->createEOperation_as_eOperations_in_EClass(m_classifier_Class, CLASSIFIER_OPERATION_PARENTS);
	
}

void umlPackageImpl::createClassifierTemplateParameterContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_classifierTemplateParameter_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CLASSIFIERTEMPLATEPARAMETER_CLASS);
	m_classifierTemplateParameter_Attribute_allowSubstitutable = factory->createEAttribute_as_eAttributes_in_EClass(m_classifierTemplateParameter_Class, CLASSIFIERTEMPLATEPARAMETER_ATTRIBUTE_ALLOWSUBSTITUTABLE);
	
	m_classifierTemplateParameter_Attribute_constrainingClassifier = factory->createEReference_as_eReferences_in_EClass(m_classifierTemplateParameter_Class, CLASSIFIERTEMPLATEPARAMETER_ATTRIBUTE_CONSTRAININGCLASSIFIER);
	
	
}

void umlPackageImpl::createClauseContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_clause_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CLAUSE_CLASS);
	
	m_clause_Attribute_body = factory->createEReference_as_eReferences_in_EClass(m_clause_Class, CLAUSE_ATTRIBUTE_BODY);
	m_clause_Attribute_bodyOutput = factory->createEReference_as_eReferences_in_EClass(m_clause_Class, CLAUSE_ATTRIBUTE_BODYOUTPUT);
	m_clause_Attribute_decider = factory->createEReference_as_eReferences_in_EClass(m_clause_Class, CLAUSE_ATTRIBUTE_DECIDER);
	m_clause_Attribute_predecessorClause = factory->createEReference_as_eReferences_in_EClass(m_clause_Class, CLAUSE_ATTRIBUTE_PREDECESSORCLAUSE);
	m_clause_Attribute_successorClause = factory->createEReference_as_eReferences_in_EClass(m_clause_Class, CLAUSE_ATTRIBUTE_SUCCESSORCLAUSE);
	m_clause_Attribute_test = factory->createEReference_as_eReferences_in_EClass(m_clause_Class, CLAUSE_ATTRIBUTE_TEST);
	
	
}

void umlPackageImpl::createClearAssociationActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_clearAssociationAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CLEARASSOCIATIONACTION_CLASS);
	
	m_clearAssociationAction_Attribute_association = factory->createEReference_as_eReferences_in_EClass(m_clearAssociationAction_Class, CLEARASSOCIATIONACTION_ATTRIBUTE_ASSOCIATION);
	m_clearAssociationAction_Attribute_object = factory->createEReference_as_eReferences_in_EClass(m_clearAssociationAction_Class, CLEARASSOCIATIONACTION_ATTRIBUTE_OBJECT);
	
	
}

void umlPackageImpl::createClearStructuralFeatureActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_clearStructuralFeatureAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CLEARSTRUCTURALFEATUREACTION_CLASS);
	
	m_clearStructuralFeatureAction_Attribute_result = factory->createEReference_as_eReferences_in_EClass(m_clearStructuralFeatureAction_Class, CLEARSTRUCTURALFEATUREACTION_ATTRIBUTE_RESULT);
	
	
}

void umlPackageImpl::createClearVariableActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_clearVariableAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CLEARVARIABLEACTION_CLASS);
	
	
	
}

void umlPackageImpl::createCollaborationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_collaboration_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, COLLABORATION_CLASS);
	
	m_collaboration_Attribute_collaborationRole = factory->createEReference_as_eReferences_in_EClass(m_collaboration_Class, COLLABORATION_ATTRIBUTE_COLLABORATIONROLE);
	
	
}

void umlPackageImpl::createCollaborationUseContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_collaborationUse_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, COLLABORATIONUSE_CLASS);
	
	m_collaborationUse_Attribute_roleBinding = factory->createEReference_as_eReferences_in_EClass(m_collaborationUse_Class, COLLABORATIONUSE_ATTRIBUTE_ROLEBINDING);
	m_collaborationUse_Attribute_type = factory->createEReference_as_eReferences_in_EClass(m_collaborationUse_Class, COLLABORATIONUSE_ATTRIBUTE_TYPE);
	
	
}

void umlPackageImpl::createCombinedFragmentContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_combinedFragment_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, COMBINEDFRAGMENT_CLASS);
	m_combinedFragment_Attribute_interactionOperator = factory->createEAttribute_as_eAttributes_in_EClass(m_combinedFragment_Class, COMBINEDFRAGMENT_ATTRIBUTE_INTERACTIONOPERATOR);
	
	m_combinedFragment_Attribute_cfragmentGate = factory->createEReference_as_eReferences_in_EClass(m_combinedFragment_Class, COMBINEDFRAGMENT_ATTRIBUTE_CFRAGMENTGATE);
	m_combinedFragment_Attribute_operand = factory->createEReference_as_eReferences_in_EClass(m_combinedFragment_Class, COMBINEDFRAGMENT_ATTRIBUTE_OPERAND);
	
	
}

void umlPackageImpl::createCommentContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_comment_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, COMMENT_CLASS);
	m_comment_Attribute_body = factory->createEAttribute_as_eAttributes_in_EClass(m_comment_Class, COMMENT_ATTRIBUTE_BODY);
	
	m_comment_Attribute_annotatedElement = factory->createEReference_as_eReferences_in_EClass(m_comment_Class, COMMENT_ATTRIBUTE_ANNOTATEDELEMENT);
	
	
}

void umlPackageImpl::createCommunicationPathContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_communicationPath_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, COMMUNICATIONPATH_CLASS);
	
	
	
}

void umlPackageImpl::createComponentContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_component_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, COMPONENT_CLASS);
	m_component_Attribute_isIndirectlyInstantiated = factory->createEAttribute_as_eAttributes_in_EClass(m_component_Class, COMPONENT_ATTRIBUTE_ISINDIRECTLYINSTANTIATED);
	
	m_component_Attribute_packagedElement = factory->createEReference_as_eReferences_in_EClass(m_component_Class, COMPONENT_ATTRIBUTE_PACKAGEDELEMENT);
	m_component_Attribute_provided = factory->createEReference_as_eReferences_in_EClass(m_component_Class, COMPONENT_ATTRIBUTE_PROVIDED);
	m_component_Attribute_realization = factory->createEReference_as_eReferences_in_EClass(m_component_Class, COMPONENT_ATTRIBUTE_REALIZATION);
	m_component_Attribute_required = factory->createEReference_as_eReferences_in_EClass(m_component_Class, COMPONENT_ATTRIBUTE_REQUIRED);
	
	m_component_Operation_createOwnedClass_String_Boolean = factory->createEOperation_as_eOperations_in_EClass(m_component_Class, COMPONENT_OPERATION_CREATEOWNEDCLASS_STRING_BOOLEAN);
	m_component_Operation_createOwnedEnumeration_String = factory->createEOperation_as_eOperations_in_EClass(m_component_Class, COMPONENT_OPERATION_CREATEOWNEDENUMERATION_STRING);
	m_component_Operation_createOwnedInterface_String = factory->createEOperation_as_eOperations_in_EClass(m_component_Class, COMPONENT_OPERATION_CREATEOWNEDINTERFACE_STRING);
	m_component_Operation_createOwnedPrimitiveType_String = factory->createEOperation_as_eOperations_in_EClass(m_component_Class, COMPONENT_OPERATION_CREATEOWNEDPRIMITIVETYPE_STRING);
	m_component_Operation_getProvideds = factory->createEOperation_as_eOperations_in_EClass(m_component_Class, COMPONENT_OPERATION_GETPROVIDEDS);
	m_component_Operation_getRequireds = factory->createEOperation_as_eOperations_in_EClass(m_component_Class, COMPONENT_OPERATION_GETREQUIREDS);
	
}

void umlPackageImpl::createComponentRealizationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_componentRealization_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, COMPONENTREALIZATION_CLASS);
	
	m_componentRealization_Attribute_abstraction = factory->createEReference_as_eReferences_in_EClass(m_componentRealization_Class, COMPONENTREALIZATION_ATTRIBUTE_ABSTRACTION);
	m_componentRealization_Attribute_realizingClassifier = factory->createEReference_as_eReferences_in_EClass(m_componentRealization_Class, COMPONENTREALIZATION_ATTRIBUTE_REALIZINGCLASSIFIER);
	
	
}

void umlPackageImpl::createConditionalNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_conditionalNode_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CONDITIONALNODE_CLASS);
	m_conditionalNode_Attribute_isAssured = factory->createEAttribute_as_eAttributes_in_EClass(m_conditionalNode_Class, CONDITIONALNODE_ATTRIBUTE_ISASSURED);
	m_conditionalNode_Attribute_isDeterminate = factory->createEAttribute_as_eAttributes_in_EClass(m_conditionalNode_Class, CONDITIONALNODE_ATTRIBUTE_ISDETERMINATE);
	
	m_conditionalNode_Attribute_clause = factory->createEReference_as_eReferences_in_EClass(m_conditionalNode_Class, CONDITIONALNODE_ATTRIBUTE_CLAUSE);
	m_conditionalNode_Attribute_result = factory->createEReference_as_eReferences_in_EClass(m_conditionalNode_Class, CONDITIONALNODE_ATTRIBUTE_RESULT);
	
	
}

void umlPackageImpl::createConnectableElementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_connectableElement_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CONNECTABLEELEMENT_CLASS);
	
	m_connectableElement_Attribute_end = factory->createEReference_as_eReferences_in_EClass(m_connectableElement_Class, CONNECTABLEELEMENT_ATTRIBUTE_END);
	
	m_connectableElement_Operation_getEnds = factory->createEOperation_as_eOperations_in_EClass(m_connectableElement_Class, CONNECTABLEELEMENT_OPERATION_GETENDS);
	
}

void umlPackageImpl::createConnectableElementTemplateParameterContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_connectableElementTemplateParameter_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CONNECTABLEELEMENTTEMPLATEPARAMETER_CLASS);
	
	
	
}

void umlPackageImpl::createConnectionPointReferenceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_connectionPointReference_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CONNECTIONPOINTREFERENCE_CLASS);
	
	m_connectionPointReference_Attribute_entry = factory->createEReference_as_eReferences_in_EClass(m_connectionPointReference_Class, CONNECTIONPOINTREFERENCE_ATTRIBUTE_ENTRY);
	m_connectionPointReference_Attribute_exit = factory->createEReference_as_eReferences_in_EClass(m_connectionPointReference_Class, CONNECTIONPOINTREFERENCE_ATTRIBUTE_EXIT);
	m_connectionPointReference_Attribute_state = factory->createEReference_as_eReferences_in_EClass(m_connectionPointReference_Class, CONNECTIONPOINTREFERENCE_ATTRIBUTE_STATE);
	
	
}

void umlPackageImpl::createConnectorContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_connector_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CONNECTOR_CLASS);
	m_connector_Attribute_kind = factory->createEAttribute_as_eAttributes_in_EClass(m_connector_Class, CONNECTOR_ATTRIBUTE_KIND);
	
	m_connector_Attribute_contract = factory->createEReference_as_eReferences_in_EClass(m_connector_Class, CONNECTOR_ATTRIBUTE_CONTRACT);
	m_connector_Attribute_end = factory->createEReference_as_eReferences_in_EClass(m_connector_Class, CONNECTOR_ATTRIBUTE_END);
	m_connector_Attribute_redefinedConnector = factory->createEReference_as_eReferences_in_EClass(m_connector_Class, CONNECTOR_ATTRIBUTE_REDEFINEDCONNECTOR);
	m_connector_Attribute_structuredClassifier = factory->createEReference_as_eReferences_in_EClass(m_connector_Class, CONNECTOR_ATTRIBUTE_STRUCTUREDCLASSIFIER);
	m_connector_Attribute_type = factory->createEReference_as_eReferences_in_EClass(m_connector_Class, CONNECTOR_ATTRIBUTE_TYPE);
	
	m_connector_Operation_getKind = factory->createEOperation_as_eOperations_in_EClass(m_connector_Class, CONNECTOR_OPERATION_GETKIND);
	
}

void umlPackageImpl::createConnectorEndContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_connectorEnd_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CONNECTOREND_CLASS);
	
	m_connectorEnd_Attribute_connector = factory->createEReference_as_eReferences_in_EClass(m_connectorEnd_Class, CONNECTOREND_ATTRIBUTE_CONNECTOR);
	m_connectorEnd_Attribute_definingEnd = factory->createEReference_as_eReferences_in_EClass(m_connectorEnd_Class, CONNECTOREND_ATTRIBUTE_DEFININGEND);
	m_connectorEnd_Attribute_partWithPort = factory->createEReference_as_eReferences_in_EClass(m_connectorEnd_Class, CONNECTOREND_ATTRIBUTE_PARTWITHPORT);
	m_connectorEnd_Attribute_role = factory->createEReference_as_eReferences_in_EClass(m_connectorEnd_Class, CONNECTOREND_ATTRIBUTE_ROLE);
	
	m_connectorEnd_Operation_getDefiningEnd = factory->createEOperation_as_eOperations_in_EClass(m_connectorEnd_Class, CONNECTOREND_OPERATION_GETDEFININGEND);
	
}

void umlPackageImpl::createConsiderIgnoreFragmentContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_considerIgnoreFragment_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CONSIDERIGNOREFRAGMENT_CLASS);
	
	m_considerIgnoreFragment_Attribute_message = factory->createEReference_as_eReferences_in_EClass(m_considerIgnoreFragment_Class, CONSIDERIGNOREFRAGMENT_ATTRIBUTE_MESSAGE);
	
	
}

void umlPackageImpl::createConstraintContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_constraint_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CONSTRAINT_CLASS);
	
	m_constraint_Attribute_constrainedElement = factory->createEReference_as_eReferences_in_EClass(m_constraint_Class, CONSTRAINT_ATTRIBUTE_CONSTRAINEDELEMENT);
	m_constraint_Attribute_context = factory->createEReference_as_eReferences_in_EClass(m_constraint_Class, CONSTRAINT_ATTRIBUTE_CONTEXT);
	m_constraint_Attribute_specification = factory->createEReference_as_eReferences_in_EClass(m_constraint_Class, CONSTRAINT_ATTRIBUTE_SPECIFICATION);
	
	
}

void umlPackageImpl::createContinuationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_continuation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CONTINUATION_CLASS);
	m_continuation_Attribute_setting = factory->createEAttribute_as_eAttributes_in_EClass(m_continuation_Class, CONTINUATION_ATTRIBUTE_SETTING);
	
	
	
}

void umlPackageImpl::createControlFlowContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_controlFlow_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CONTROLFLOW_CLASS);
	
	
	
}

void umlPackageImpl::createControlNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_controlNode_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CONTROLNODE_CLASS);
	
	
	
}

void umlPackageImpl::createCreateLinkActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_createLinkAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CREATELINKACTION_CLASS);
	
	
	
}

void umlPackageImpl::createCreateLinkObjectActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_createLinkObjectAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CREATELINKOBJECTACTION_CLASS);
	
	m_createLinkObjectAction_Attribute_result = factory->createEReference_as_eReferences_in_EClass(m_createLinkObjectAction_Class, CREATELINKOBJECTACTION_ATTRIBUTE_RESULT);
	
	
}

void umlPackageImpl::createCreateObjectActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_createObjectAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CREATEOBJECTACTION_CLASS);
	
	m_createObjectAction_Attribute_classifier = factory->createEReference_as_eReferences_in_EClass(m_createObjectAction_Class, CREATEOBJECTACTION_ATTRIBUTE_CLASSIFIER);
	m_createObjectAction_Attribute_result = factory->createEReference_as_eReferences_in_EClass(m_createObjectAction_Class, CREATEOBJECTACTION_ATTRIBUTE_RESULT);
	
	
}

void umlPackageImpl::createDataStoreNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_dataStoreNode_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, DATASTORENODE_CLASS);
	
	
	
}

void umlPackageImpl::createDataTypeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_dataType_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, DATATYPE_CLASS);
	
	m_dataType_Attribute_ownedAttribute = factory->createEReference_as_eReferences_in_EClass(m_dataType_Class, DATATYPE_ATTRIBUTE_OWNEDATTRIBUTE);
	m_dataType_Attribute_ownedOperation = factory->createEReference_as_eReferences_in_EClass(m_dataType_Class, DATATYPE_ATTRIBUTE_OWNEDOPERATION);
	
	m_dataType_Operation_createOwnedAttribute_String_UnlimitedNatural = factory->createEOperation_as_eOperations_in_EClass(m_dataType_Class, DATATYPE_OPERATION_CREATEOWNEDATTRIBUTE_STRING_UNLIMITEDNATURAL);
	m_dataType_Operation_createOwnedOperation_String_Type = factory->createEOperation_as_eOperations_in_EClass(m_dataType_Class, DATATYPE_OPERATION_CREATEOWNEDOPERATION_STRING_TYPE);
	
}

void umlPackageImpl::createDecisionNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_decisionNode_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, DECISIONNODE_CLASS);
	
	m_decisionNode_Attribute_decisionInput = factory->createEReference_as_eReferences_in_EClass(m_decisionNode_Class, DECISIONNODE_ATTRIBUTE_DECISIONINPUT);
	m_decisionNode_Attribute_decisionInputFlow = factory->createEReference_as_eReferences_in_EClass(m_decisionNode_Class, DECISIONNODE_ATTRIBUTE_DECISIONINPUTFLOW);
	
	
}

void umlPackageImpl::createDependencyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_dependency_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, DEPENDENCY_CLASS);
	
	m_dependency_Attribute_client = factory->createEReference_as_eReferences_in_EClass(m_dependency_Class, DEPENDENCY_ATTRIBUTE_CLIENT);
	m_dependency_Attribute_supplier = factory->createEReference_as_eReferences_in_EClass(m_dependency_Class, DEPENDENCY_ATTRIBUTE_SUPPLIER);
	
	
}

void umlPackageImpl::createDeployedArtifactContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_deployedArtifact_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, DEPLOYEDARTIFACT_CLASS);
	
	
	
}

void umlPackageImpl::createDeploymentContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_deployment_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, DEPLOYMENT_CLASS);
	
	m_deployment_Attribute_configuration = factory->createEReference_as_eReferences_in_EClass(m_deployment_Class, DEPLOYMENT_ATTRIBUTE_CONFIGURATION);
	m_deployment_Attribute_deployedArtifact = factory->createEReference_as_eReferences_in_EClass(m_deployment_Class, DEPLOYMENT_ATTRIBUTE_DEPLOYEDARTIFACT);
	m_deployment_Attribute_location = factory->createEReference_as_eReferences_in_EClass(m_deployment_Class, DEPLOYMENT_ATTRIBUTE_LOCATION);
	
	
}

void umlPackageImpl::createDeploymentSpecificationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_deploymentSpecification_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, DEPLOYMENTSPECIFICATION_CLASS);
	m_deploymentSpecification_Attribute_deploymentLocation = factory->createEAttribute_as_eAttributes_in_EClass(m_deploymentSpecification_Class, DEPLOYMENTSPECIFICATION_ATTRIBUTE_DEPLOYMENTLOCATION);
	m_deploymentSpecification_Attribute_executionLocation = factory->createEAttribute_as_eAttributes_in_EClass(m_deploymentSpecification_Class, DEPLOYMENTSPECIFICATION_ATTRIBUTE_EXECUTIONLOCATION);
	
	m_deploymentSpecification_Attribute_deployment = factory->createEReference_as_eReferences_in_EClass(m_deploymentSpecification_Class, DEPLOYMENTSPECIFICATION_ATTRIBUTE_DEPLOYMENT);
	
	
}

void umlPackageImpl::createDeploymentTargetContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_deploymentTarget_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, DEPLOYMENTTARGET_CLASS);
	
	m_deploymentTarget_Attribute_deployedElement = factory->createEReference_as_eReferences_in_EClass(m_deploymentTarget_Class, DEPLOYMENTTARGET_ATTRIBUTE_DEPLOYEDELEMENT);
	m_deploymentTarget_Attribute_deployment = factory->createEReference_as_eReferences_in_EClass(m_deploymentTarget_Class, DEPLOYMENTTARGET_ATTRIBUTE_DEPLOYMENT);
	
	m_deploymentTarget_Operation_getDeployedElements = factory->createEOperation_as_eOperations_in_EClass(m_deploymentTarget_Class, DEPLOYMENTTARGET_OPERATION_GETDEPLOYEDELEMENTS);
	
}

void umlPackageImpl::createDestroyLinkActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_destroyLinkAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, DESTROYLINKACTION_CLASS);
	
	
	
}

void umlPackageImpl::createDestroyObjectActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_destroyObjectAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, DESTROYOBJECTACTION_CLASS);
	m_destroyObjectAction_Attribute_isDestroyLinks = factory->createEAttribute_as_eAttributes_in_EClass(m_destroyObjectAction_Class, DESTROYOBJECTACTION_ATTRIBUTE_ISDESTROYLINKS);
	m_destroyObjectAction_Attribute_isDestroyOwnedObjects = factory->createEAttribute_as_eAttributes_in_EClass(m_destroyObjectAction_Class, DESTROYOBJECTACTION_ATTRIBUTE_ISDESTROYOWNEDOBJECTS);
	
	m_destroyObjectAction_Attribute_target = factory->createEReference_as_eReferences_in_EClass(m_destroyObjectAction_Class, DESTROYOBJECTACTION_ATTRIBUTE_TARGET);
	
	
}

void umlPackageImpl::createDestructionOccurrenceSpecificationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_destructionOccurrenceSpecification_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, DESTRUCTIONOCCURRENCESPECIFICATION_CLASS);
	
	
	
}

void umlPackageImpl::createDeviceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_device_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, DEVICE_CLASS);
	
	
	
}

void umlPackageImpl::createDirectedRelationshipContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_directedRelationship_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, DIRECTEDRELATIONSHIP_CLASS);
	
	m_directedRelationship_Attribute_source = factory->createEReference_as_eReferences_in_EClass(m_directedRelationship_Class, DIRECTEDRELATIONSHIP_ATTRIBUTE_SOURCE);
	m_directedRelationship_Attribute_target = factory->createEReference_as_eReferences_in_EClass(m_directedRelationship_Class, DIRECTEDRELATIONSHIP_ATTRIBUTE_TARGET);
	
	
}

void umlPackageImpl::createDurationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_duration_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, DURATION_CLASS);
	
	m_duration_Attribute_expr = factory->createEReference_as_eReferences_in_EClass(m_duration_Class, DURATION_ATTRIBUTE_EXPR);
	m_duration_Attribute_observation = factory->createEReference_as_eReferences_in_EClass(m_duration_Class, DURATION_ATTRIBUTE_OBSERVATION);
	
	
}

void umlPackageImpl::createDurationConstraintContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_durationConstraint_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, DURATIONCONSTRAINT_CLASS);
	m_durationConstraint_Attribute_firstEvent = factory->createEAttribute_as_eAttributes_in_EClass(m_durationConstraint_Class, DURATIONCONSTRAINT_ATTRIBUTE_FIRSTEVENT);
	
	
	
}

void umlPackageImpl::createDurationIntervalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_durationInterval_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, DURATIONINTERVAL_CLASS);
	
	
	
}

void umlPackageImpl::createDurationObservationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_durationObservation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, DURATIONOBSERVATION_CLASS);
	m_durationObservation_Attribute_firstEvent = factory->createEAttribute_as_eAttributes_in_EClass(m_durationObservation_Class, DURATIONOBSERVATION_ATTRIBUTE_FIRSTEVENT);
	
	m_durationObservation_Attribute_event = factory->createEReference_as_eReferences_in_EClass(m_durationObservation_Class, DURATIONOBSERVATION_ATTRIBUTE_EVENT);
	
	
}

void umlPackageImpl::createElementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_element_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ELEMENT_CLASS);
	
	m_element_Attribute_ownedComment = factory->createEReference_as_eReferences_in_EClass(m_element_Class, ELEMENT_ATTRIBUTE_OWNEDCOMMENT);
	m_element_Attribute_ownedElement = factory->createEReference_as_eReferences_in_EClass(m_element_Class, ELEMENT_ATTRIBUTE_OWNEDELEMENT);
	m_element_Attribute_owner = factory->createEReference_as_eReferences_in_EClass(m_element_Class, ELEMENT_ATTRIBUTE_OWNER);
	
	m_element_Operation_addKeyword_String = factory->createEOperation_as_eOperations_in_EClass(m_element_Class, ELEMENT_OPERATION_ADDKEYWORD_STRING);
	m_element_Operation_allOwnedElements = factory->createEOperation_as_eOperations_in_EClass(m_element_Class, ELEMENT_OPERATION_ALLOWNEDELEMENTS);
	m_element_Operation_applyStereotype_Stereotype = factory->createEOperation_as_eOperations_in_EClass(m_element_Class, ELEMENT_OPERATION_APPLYSTEREOTYPE_STEREOTYPE);
	m_element_Operation_container = factory->createEOperation_as_eOperations_in_EClass(m_element_Class, ELEMENT_OPERATION_CONTAINER);
	m_element_Operation_createEAnnotation_String = factory->createEOperation_as_eOperations_in_EClass(m_element_Class, ELEMENT_OPERATION_CREATEEANNOTATION_STRING);
	m_element_Operation_destroy = factory->createEOperation_as_eOperations_in_EClass(m_element_Class, ELEMENT_OPERATION_DESTROY);
	m_element_Operation_getApplicableStereotype_String = factory->createEOperation_as_eOperations_in_EClass(m_element_Class, ELEMENT_OPERATION_GETAPPLICABLESTEREOTYPE_STRING);
	m_element_Operation_getApplicableStereotypes = factory->createEOperation_as_eOperations_in_EClass(m_element_Class, ELEMENT_OPERATION_GETAPPLICABLESTEREOTYPES);
	m_element_Operation_getAppliedStereotype_String = factory->createEOperation_as_eOperations_in_EClass(m_element_Class, ELEMENT_OPERATION_GETAPPLIEDSTEREOTYPE_STRING);
	m_element_Operation_getAppliedStereotypes = factory->createEOperation_as_eOperations_in_EClass(m_element_Class, ELEMENT_OPERATION_GETAPPLIEDSTEREOTYPES);
	m_element_Operation_getAppliedSubstereotype_Stereotype_String = factory->createEOperation_as_eOperations_in_EClass(m_element_Class, ELEMENT_OPERATION_GETAPPLIEDSUBSTEREOTYPE_STEREOTYPE_STRING);
	m_element_Operation_getAppliedSubstereotypes_Stereotype = factory->createEOperation_as_eOperations_in_EClass(m_element_Class, ELEMENT_OPERATION_GETAPPLIEDSUBSTEREOTYPES_STEREOTYPE);
	m_element_Operation_getKeywords = factory->createEOperation_as_eOperations_in_EClass(m_element_Class, ELEMENT_OPERATION_GETKEYWORDS);
	m_element_Operation_getMetaClass = factory->createEOperation_as_eOperations_in_EClass(m_element_Class, ELEMENT_OPERATION_GETMETACLASS);
	m_element_Operation_getModel = factory->createEOperation_as_eOperations_in_EClass(m_element_Class, ELEMENT_OPERATION_GETMODEL);
	m_element_Operation_getNearestPackage = factory->createEOperation_as_eOperations_in_EClass(m_element_Class, ELEMENT_OPERATION_GETNEARESTPACKAGE);
	m_element_Operation_getRelationships = factory->createEOperation_as_eOperations_in_EClass(m_element_Class, ELEMENT_OPERATION_GETRELATIONSHIPS);
	m_element_Operation_getRelationships_EClass = factory->createEOperation_as_eOperations_in_EClass(m_element_Class, ELEMENT_OPERATION_GETRELATIONSHIPS_ECLASS);
	m_element_Operation_getRequiredStereotype_String = factory->createEOperation_as_eOperations_in_EClass(m_element_Class, ELEMENT_OPERATION_GETREQUIREDSTEREOTYPE_STRING);
	m_element_Operation_getRequiredStereotypes = factory->createEOperation_as_eOperations_in_EClass(m_element_Class, ELEMENT_OPERATION_GETREQUIREDSTEREOTYPES);
	m_element_Operation_getSourceDirectedRelationships = factory->createEOperation_as_eOperations_in_EClass(m_element_Class, ELEMENT_OPERATION_GETSOURCEDIRECTEDRELATIONSHIPS);
	m_element_Operation_getSourceDirectedRelationships_EClass = factory->createEOperation_as_eOperations_in_EClass(m_element_Class, ELEMENT_OPERATION_GETSOURCEDIRECTEDRELATIONSHIPS_ECLASS);
	m_element_Operation_getStereotypeApplication_Stereotype = factory->createEOperation_as_eOperations_in_EClass(m_element_Class, ELEMENT_OPERATION_GETSTEREOTYPEAPPLICATION_STEREOTYPE);
	m_element_Operation_getStereotypeApplications = factory->createEOperation_as_eOperations_in_EClass(m_element_Class, ELEMENT_OPERATION_GETSTEREOTYPEAPPLICATIONS);
	m_element_Operation_getTargetDirectedRelationships = factory->createEOperation_as_eOperations_in_EClass(m_element_Class, ELEMENT_OPERATION_GETTARGETDIRECTEDRELATIONSHIPS);
	m_element_Operation_getTargetDirectedRelationships_EClass = factory->createEOperation_as_eOperations_in_EClass(m_element_Class, ELEMENT_OPERATION_GETTARGETDIRECTEDRELATIONSHIPS_ECLASS);
	m_element_Operation_getValue_Stereotype_String = factory->createEOperation_as_eOperations_in_EClass(m_element_Class, ELEMENT_OPERATION_GETVALUE_STEREOTYPE_STRING);
	m_element_Operation_hasKeyword_String = factory->createEOperation_as_eOperations_in_EClass(m_element_Class, ELEMENT_OPERATION_HASKEYWORD_STRING);
	m_element_Operation_hasValue_Stereotype_String = factory->createEOperation_as_eOperations_in_EClass(m_element_Class, ELEMENT_OPERATION_HASVALUE_STEREOTYPE_STRING);
	m_element_Operation_isStereotypeApplicable_Stereotype = factory->createEOperation_as_eOperations_in_EClass(m_element_Class, ELEMENT_OPERATION_ISSTEREOTYPEAPPLICABLE_STEREOTYPE);
	m_element_Operation_isStereotypeApplied_Stereotype = factory->createEOperation_as_eOperations_in_EClass(m_element_Class, ELEMENT_OPERATION_ISSTEREOTYPEAPPLIED_STEREOTYPE);
	m_element_Operation_isStereotypeRequired_Stereotype = factory->createEOperation_as_eOperations_in_EClass(m_element_Class, ELEMENT_OPERATION_ISSTEREOTYPEREQUIRED_STEREOTYPE);
	m_element_Operation_mustBeOwned = factory->createEOperation_as_eOperations_in_EClass(m_element_Class, ELEMENT_OPERATION_MUSTBEOWNED);
	m_element_Operation_removeKeyword_String = factory->createEOperation_as_eOperations_in_EClass(m_element_Class, ELEMENT_OPERATION_REMOVEKEYWORD_STRING);
	m_element_Operation_setValue_Stereotype_EJavaObject = factory->createEOperation_as_eOperations_in_EClass(m_element_Class, ELEMENT_OPERATION_SETVALUE_STEREOTYPE_EJAVAOBJECT);
	m_element_Operation_unapplyStereotype_Stereotype = factory->createEOperation_as_eOperations_in_EClass(m_element_Class, ELEMENT_OPERATION_UNAPPLYSTEREOTYPE_STEREOTYPE);
	
}

void umlPackageImpl::createElementImportContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_elementImport_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ELEMENTIMPORT_CLASS);
	m_elementImport_Attribute_alias = factory->createEAttribute_as_eAttributes_in_EClass(m_elementImport_Class, ELEMENTIMPORT_ATTRIBUTE_ALIAS);
	m_elementImport_Attribute_visibility = factory->createEAttribute_as_eAttributes_in_EClass(m_elementImport_Class, ELEMENTIMPORT_ATTRIBUTE_VISIBILITY);
	
	m_elementImport_Attribute_importedElement = factory->createEReference_as_eReferences_in_EClass(m_elementImport_Class, ELEMENTIMPORT_ATTRIBUTE_IMPORTEDELEMENT);
	m_elementImport_Attribute_importingNamespace = factory->createEReference_as_eReferences_in_EClass(m_elementImport_Class, ELEMENTIMPORT_ATTRIBUTE_IMPORTINGNAMESPACE);
	
	m_elementImport_Operation_getName = factory->createEOperation_as_eOperations_in_EClass(m_elementImport_Class, ELEMENTIMPORT_OPERATION_GETNAME);
	
}

void umlPackageImpl::createEncapsulatedClassifierContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_encapsulatedClassifier_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ENCAPSULATEDCLASSIFIER_CLASS);
	
	m_encapsulatedClassifier_Attribute_ownedPort = factory->createEReference_as_eReferences_in_EClass(m_encapsulatedClassifier_Class, ENCAPSULATEDCLASSIFIER_ATTRIBUTE_OWNEDPORT);
	
	m_encapsulatedClassifier_Operation_getOwnedPorts = factory->createEOperation_as_eOperations_in_EClass(m_encapsulatedClassifier_Class, ENCAPSULATEDCLASSIFIER_OPERATION_GETOWNEDPORTS);
	
}

void umlPackageImpl::createEnumerationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_enumeration_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ENUMERATION_CLASS);
	
	m_enumeration_Attribute_ownedLiteral = factory->createEReference_as_eReferences_in_EClass(m_enumeration_Class, ENUMERATION_ATTRIBUTE_OWNEDLITERAL);
	
	
}

void umlPackageImpl::createEnumerationLiteralContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_enumerationLiteral_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ENUMERATIONLITERAL_CLASS);
	
	m_enumerationLiteral_Attribute_enumeration = factory->createEReference_as_eReferences_in_EClass(m_enumerationLiteral_Class, ENUMERATIONLITERAL_ATTRIBUTE_ENUMERATION);
	
	m_enumerationLiteral_Operation_getClassifier = factory->createEOperation_as_eOperations_in_EClass(m_enumerationLiteral_Class, ENUMERATIONLITERAL_OPERATION_GETCLASSIFIER);
	m_enumerationLiteral_Operation_getClassifiers = factory->createEOperation_as_eOperations_in_EClass(m_enumerationLiteral_Class, ENUMERATIONLITERAL_OPERATION_GETCLASSIFIERS);
	
}

void umlPackageImpl::createEventContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_event_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EVENT_CLASS);
	
	
	
}

void umlPackageImpl::createExceptionHandlerContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_exceptionHandler_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EXCEPTIONHANDLER_CLASS);
	
	m_exceptionHandler_Attribute_exceptionInput = factory->createEReference_as_eReferences_in_EClass(m_exceptionHandler_Class, EXCEPTIONHANDLER_ATTRIBUTE_EXCEPTIONINPUT);
	m_exceptionHandler_Attribute_exceptionType = factory->createEReference_as_eReferences_in_EClass(m_exceptionHandler_Class, EXCEPTIONHANDLER_ATTRIBUTE_EXCEPTIONTYPE);
	m_exceptionHandler_Attribute_handlerBody = factory->createEReference_as_eReferences_in_EClass(m_exceptionHandler_Class, EXCEPTIONHANDLER_ATTRIBUTE_HANDLERBODY);
	m_exceptionHandler_Attribute_protectedNode = factory->createEReference_as_eReferences_in_EClass(m_exceptionHandler_Class, EXCEPTIONHANDLER_ATTRIBUTE_PROTECTEDNODE);
	
	
}

void umlPackageImpl::createExecutableNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_executableNode_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EXECUTABLENODE_CLASS);
	
	m_executableNode_Attribute_handler = factory->createEReference_as_eReferences_in_EClass(m_executableNode_Class, EXECUTABLENODE_ATTRIBUTE_HANDLER);
	
	
}

void umlPackageImpl::createExecutionEnvironmentContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_executionEnvironment_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EXECUTIONENVIRONMENT_CLASS);
	
	
	
}

void umlPackageImpl::createExecutionOccurrenceSpecificationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_executionOccurrenceSpecification_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EXECUTIONOCCURRENCESPECIFICATION_CLASS);
	
	m_executionOccurrenceSpecification_Attribute_execution = factory->createEReference_as_eReferences_in_EClass(m_executionOccurrenceSpecification_Class, EXECUTIONOCCURRENCESPECIFICATION_ATTRIBUTE_EXECUTION);
	
	
}

void umlPackageImpl::createExecutionSpecificationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_executionSpecification_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EXECUTIONSPECIFICATION_CLASS);
	
	m_executionSpecification_Attribute_finish = factory->createEReference_as_eReferences_in_EClass(m_executionSpecification_Class, EXECUTIONSPECIFICATION_ATTRIBUTE_FINISH);
	m_executionSpecification_Attribute_start = factory->createEReference_as_eReferences_in_EClass(m_executionSpecification_Class, EXECUTIONSPECIFICATION_ATTRIBUTE_START);
	
	
}

void umlPackageImpl::createExpansionNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_expansionNode_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EXPANSIONNODE_CLASS);
	
	m_expansionNode_Attribute_regionAsInput = factory->createEReference_as_eReferences_in_EClass(m_expansionNode_Class, EXPANSIONNODE_ATTRIBUTE_REGIONASINPUT);
	m_expansionNode_Attribute_regionAsOutput = factory->createEReference_as_eReferences_in_EClass(m_expansionNode_Class, EXPANSIONNODE_ATTRIBUTE_REGIONASOUTPUT);
	
	
}

void umlPackageImpl::createExpansionRegionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_expansionRegion_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EXPANSIONREGION_CLASS);
	m_expansionRegion_Attribute_mode = factory->createEAttribute_as_eAttributes_in_EClass(m_expansionRegion_Class, EXPANSIONREGION_ATTRIBUTE_MODE);
	
	m_expansionRegion_Attribute_inputElement = factory->createEReference_as_eReferences_in_EClass(m_expansionRegion_Class, EXPANSIONREGION_ATTRIBUTE_INPUTELEMENT);
	m_expansionRegion_Attribute_outputElement = factory->createEReference_as_eReferences_in_EClass(m_expansionRegion_Class, EXPANSIONREGION_ATTRIBUTE_OUTPUTELEMENT);
	
	
}

void umlPackageImpl::createExpressionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_expression_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EXPRESSION_CLASS);
	m_expression_Attribute_symbol = factory->createEAttribute_as_eAttributes_in_EClass(m_expression_Class, EXPRESSION_ATTRIBUTE_SYMBOL);
	
	m_expression_Attribute_operand = factory->createEReference_as_eReferences_in_EClass(m_expression_Class, EXPRESSION_ATTRIBUTE_OPERAND);
	
	
}

void umlPackageImpl::createExtendContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_extend_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EXTEND_CLASS);
	
	m_extend_Attribute_condition = factory->createEReference_as_eReferences_in_EClass(m_extend_Class, EXTEND_ATTRIBUTE_CONDITION);
	m_extend_Attribute_extendedCase = factory->createEReference_as_eReferences_in_EClass(m_extend_Class, EXTEND_ATTRIBUTE_EXTENDEDCASE);
	m_extend_Attribute_extension = factory->createEReference_as_eReferences_in_EClass(m_extend_Class, EXTEND_ATTRIBUTE_EXTENSION);
	m_extend_Attribute_extensionLocation = factory->createEReference_as_eReferences_in_EClass(m_extend_Class, EXTEND_ATTRIBUTE_EXTENSIONLOCATION);
	
	
}

void umlPackageImpl::createExtensionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_extension_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EXTENSION_CLASS);
	m_extension_Attribute_isRequired = factory->createEAttribute_as_eAttributes_in_EClass(m_extension_Class, EXTENSION_ATTRIBUTE_ISREQUIRED);
	
	m_extension_Attribute_metaclass = factory->createEReference_as_eReferences_in_EClass(m_extension_Class, EXTENSION_ATTRIBUTE_METACLASS);
	
	m_extension_Operation_getMetaclass = factory->createEOperation_as_eOperations_in_EClass(m_extension_Class, EXTENSION_OPERATION_GETMETACLASS);
	m_extension_Operation_getStereotype = factory->createEOperation_as_eOperations_in_EClass(m_extension_Class, EXTENSION_OPERATION_GETSTEREOTYPE);
	m_extension_Operation_getStereotypeEnd = factory->createEOperation_as_eOperations_in_EClass(m_extension_Class, EXTENSION_OPERATION_GETSTEREOTYPEEND);
	m_extension_Operation_isRequired = factory->createEOperation_as_eOperations_in_EClass(m_extension_Class, EXTENSION_OPERATION_ISREQUIRED);
	m_extension_Operation_metaclassEnd = factory->createEOperation_as_eOperations_in_EClass(m_extension_Class, EXTENSION_OPERATION_METACLASSEND);
	
}

void umlPackageImpl::createExtensionEndContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_extensionEnd_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EXTENSIONEND_CLASS);
	
	
	
}

void umlPackageImpl::createExtensionPointContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_extensionPoint_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EXTENSIONPOINT_CLASS);
	
	m_extensionPoint_Attribute_useCase = factory->createEReference_as_eReferences_in_EClass(m_extensionPoint_Class, EXTENSIONPOINT_ATTRIBUTE_USECASE);
	
	
}

void umlPackageImpl::createFactoryContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_factory_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, FACTORY_CLASS);
	
	
	m_factory_Operation_create_Class = factory->createEOperation_as_eOperations_in_EClass(m_factory_Class, FACTORY_OPERATION_CREATE_CLASS);
	
}

void umlPackageImpl::createFeatureContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_feature_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, FEATURE_CLASS);
	m_feature_Attribute_isStatic = factory->createEAttribute_as_eAttributes_in_EClass(m_feature_Class, FEATURE_ATTRIBUTE_ISSTATIC);
	
	m_feature_Attribute_featuringClassifier = factory->createEReference_as_eReferences_in_EClass(m_feature_Class, FEATURE_ATTRIBUTE_FEATURINGCLASSIFIER);
	
	
}

void umlPackageImpl::createFinalNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_finalNode_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, FINALNODE_CLASS);
	
	
	
}

void umlPackageImpl::createFinalStateContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_finalState_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, FINALSTATE_CLASS);
	
	
	
}

void umlPackageImpl::createFlowFinalNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_flowFinalNode_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, FLOWFINALNODE_CLASS);
	
	
	
}

void umlPackageImpl::createForkNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_forkNode_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, FORKNODE_CLASS);
	
	
	
}

void umlPackageImpl::createFunctionBehaviorContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_functionBehavior_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, FUNCTIONBEHAVIOR_CLASS);
	
	
	m_functionBehavior_Operation_hasAllDataTypeAttributes_DataType = factory->createEOperation_as_eOperations_in_EClass(m_functionBehavior_Class, FUNCTIONBEHAVIOR_OPERATION_HASALLDATATYPEATTRIBUTES_DATATYPE);
	
}

void umlPackageImpl::createGateContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_gate_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, GATE_CLASS);
	
	
	m_gate_Operation_getName = factory->createEOperation_as_eOperations_in_EClass(m_gate_Class, GATE_OPERATION_GETNAME);
	m_gate_Operation_getOperand = factory->createEOperation_as_eOperations_in_EClass(m_gate_Class, GATE_OPERATION_GETOPERAND);
	m_gate_Operation_isActual = factory->createEOperation_as_eOperations_in_EClass(m_gate_Class, GATE_OPERATION_ISACTUAL);
	m_gate_Operation_isFormal = factory->createEOperation_as_eOperations_in_EClass(m_gate_Class, GATE_OPERATION_ISFORMAL);
	m_gate_Operation_isInsideCF = factory->createEOperation_as_eOperations_in_EClass(m_gate_Class, GATE_OPERATION_ISINSIDECF);
	m_gate_Operation_isOutsideCF = factory->createEOperation_as_eOperations_in_EClass(m_gate_Class, GATE_OPERATION_ISOUTSIDECF);
	m_gate_Operation_matches_Gate = factory->createEOperation_as_eOperations_in_EClass(m_gate_Class, GATE_OPERATION_MATCHES_GATE);
	
}

void umlPackageImpl::createGeneralOrderingContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_generalOrdering_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, GENERALORDERING_CLASS);
	
	m_generalOrdering_Attribute_after = factory->createEReference_as_eReferences_in_EClass(m_generalOrdering_Class, GENERALORDERING_ATTRIBUTE_AFTER);
	m_generalOrdering_Attribute_before = factory->createEReference_as_eReferences_in_EClass(m_generalOrdering_Class, GENERALORDERING_ATTRIBUTE_BEFORE);
	
	
}

void umlPackageImpl::createGeneralizationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_generalization_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, GENERALIZATION_CLASS);
	m_generalization_Attribute_isSubstitutable = factory->createEAttribute_as_eAttributes_in_EClass(m_generalization_Class, GENERALIZATION_ATTRIBUTE_ISSUBSTITUTABLE);
	
	m_generalization_Attribute_general = factory->createEReference_as_eReferences_in_EClass(m_generalization_Class, GENERALIZATION_ATTRIBUTE_GENERAL);
	m_generalization_Attribute_generalizationSet = factory->createEReference_as_eReferences_in_EClass(m_generalization_Class, GENERALIZATION_ATTRIBUTE_GENERALIZATIONSET);
	m_generalization_Attribute_specific = factory->createEReference_as_eReferences_in_EClass(m_generalization_Class, GENERALIZATION_ATTRIBUTE_SPECIFIC);
	
	
}

void umlPackageImpl::createGeneralizationSetContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_generalizationSet_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, GENERALIZATIONSET_CLASS);
	m_generalizationSet_Attribute_isCovering = factory->createEAttribute_as_eAttributes_in_EClass(m_generalizationSet_Class, GENERALIZATIONSET_ATTRIBUTE_ISCOVERING);
	m_generalizationSet_Attribute_isDisjoint = factory->createEAttribute_as_eAttributes_in_EClass(m_generalizationSet_Class, GENERALIZATIONSET_ATTRIBUTE_ISDISJOINT);
	
	m_generalizationSet_Attribute_generalization = factory->createEReference_as_eReferences_in_EClass(m_generalizationSet_Class, GENERALIZATIONSET_ATTRIBUTE_GENERALIZATION);
	m_generalizationSet_Attribute_powertype = factory->createEReference_as_eReferences_in_EClass(m_generalizationSet_Class, GENERALIZATIONSET_ATTRIBUTE_POWERTYPE);
	
	
}

void umlPackageImpl::createImageContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_image_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, IMAGE_CLASS);
	m_image_Attribute_content = factory->createEAttribute_as_eAttributes_in_EClass(m_image_Class, IMAGE_ATTRIBUTE_CONTENT);
	m_image_Attribute_format = factory->createEAttribute_as_eAttributes_in_EClass(m_image_Class, IMAGE_ATTRIBUTE_FORMAT);
	m_image_Attribute_location = factory->createEAttribute_as_eAttributes_in_EClass(m_image_Class, IMAGE_ATTRIBUTE_LOCATION);
	
	
	
}

void umlPackageImpl::createIncludeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_include_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, INCLUDE_CLASS);
	
	m_include_Attribute_addition = factory->createEReference_as_eReferences_in_EClass(m_include_Class, INCLUDE_ATTRIBUTE_ADDITION);
	m_include_Attribute_includingCase = factory->createEReference_as_eReferences_in_EClass(m_include_Class, INCLUDE_ATTRIBUTE_INCLUDINGCASE);
	
	
}

void umlPackageImpl::createInformationFlowContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_informationFlow_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, INFORMATIONFLOW_CLASS);
	
	m_informationFlow_Attribute_conveyed = factory->createEReference_as_eReferences_in_EClass(m_informationFlow_Class, INFORMATIONFLOW_ATTRIBUTE_CONVEYED);
	m_informationFlow_Attribute_informationSource = factory->createEReference_as_eReferences_in_EClass(m_informationFlow_Class, INFORMATIONFLOW_ATTRIBUTE_INFORMATIONSOURCE);
	m_informationFlow_Attribute_informationTarget = factory->createEReference_as_eReferences_in_EClass(m_informationFlow_Class, INFORMATIONFLOW_ATTRIBUTE_INFORMATIONTARGET);
	m_informationFlow_Attribute_realization = factory->createEReference_as_eReferences_in_EClass(m_informationFlow_Class, INFORMATIONFLOW_ATTRIBUTE_REALIZATION);
	m_informationFlow_Attribute_realizingActivityEdge = factory->createEReference_as_eReferences_in_EClass(m_informationFlow_Class, INFORMATIONFLOW_ATTRIBUTE_REALIZINGACTIVITYEDGE);
	m_informationFlow_Attribute_realizingConnector = factory->createEReference_as_eReferences_in_EClass(m_informationFlow_Class, INFORMATIONFLOW_ATTRIBUTE_REALIZINGCONNECTOR);
	m_informationFlow_Attribute_realizingMessage = factory->createEReference_as_eReferences_in_EClass(m_informationFlow_Class, INFORMATIONFLOW_ATTRIBUTE_REALIZINGMESSAGE);
	
	
}

void umlPackageImpl::createInformationItemContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_informationItem_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, INFORMATIONITEM_CLASS);
	
	m_informationItem_Attribute_represented = factory->createEReference_as_eReferences_in_EClass(m_informationItem_Class, INFORMATIONITEM_ATTRIBUTE_REPRESENTED);
	
	
}

void umlPackageImpl::createInitialNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_initialNode_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, INITIALNODE_CLASS);
	
	
	
}

void umlPackageImpl::createInputPinContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_inputPin_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, INPUTPIN_CLASS);
	
	m_inputPin_Attribute_action = factory->createEReference_as_eReferences_in_EClass(m_inputPin_Class, INPUTPIN_ATTRIBUTE_ACTION);
	m_inputPin_Attribute_addStructuralFeatureValueAction = factory->createEReference_as_eReferences_in_EClass(m_inputPin_Class, INPUTPIN_ATTRIBUTE_ADDSTRUCTURALFEATUREVALUEACTION);
	m_inputPin_Attribute_callOperationAction = factory->createEReference_as_eReferences_in_EClass(m_inputPin_Class, INPUTPIN_ATTRIBUTE_CALLOPERATIONACTION);
	m_inputPin_Attribute_destroyObjectAction = factory->createEReference_as_eReferences_in_EClass(m_inputPin_Class, INPUTPIN_ATTRIBUTE_DESTROYOBJECTACTION);
	m_inputPin_Attribute_invocationAction = factory->createEReference_as_eReferences_in_EClass(m_inputPin_Class, INPUTPIN_ATTRIBUTE_INVOCATIONACTION);
	m_inputPin_Attribute_removeStructuralFeatureValueAction = factory->createEReference_as_eReferences_in_EClass(m_inputPin_Class, INPUTPIN_ATTRIBUTE_REMOVESTRUCTURALFEATUREVALUEACTION);
	m_inputPin_Attribute_structuralFeatureAction = factory->createEReference_as_eReferences_in_EClass(m_inputPin_Class, INPUTPIN_ATTRIBUTE_STRUCTURALFEATUREACTION);
	m_inputPin_Attribute_writeStructuralFeatureAction = factory->createEReference_as_eReferences_in_EClass(m_inputPin_Class, INPUTPIN_ATTRIBUTE_WRITESTRUCTURALFEATUREACTION);
	
	
}

void umlPackageImpl::createInstanceSpecificationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_instanceSpecification_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, INSTANCESPECIFICATION_CLASS);
	
	m_instanceSpecification_Attribute_classifier = factory->createEReference_as_eReferences_in_EClass(m_instanceSpecification_Class, INSTANCESPECIFICATION_ATTRIBUTE_CLASSIFIER);
	m_instanceSpecification_Attribute_slot = factory->createEReference_as_eReferences_in_EClass(m_instanceSpecification_Class, INSTANCESPECIFICATION_ATTRIBUTE_SLOT);
	m_instanceSpecification_Attribute_specification = factory->createEReference_as_eReferences_in_EClass(m_instanceSpecification_Class, INSTANCESPECIFICATION_ATTRIBUTE_SPECIFICATION);
	
	
}

void umlPackageImpl::createInstanceValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_instanceValue_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, INSTANCEVALUE_CLASS);
	
	m_instanceValue_Attribute_instance = factory->createEReference_as_eReferences_in_EClass(m_instanceValue_Class, INSTANCEVALUE_ATTRIBUTE_INSTANCE);
	
	
}

void umlPackageImpl::createInteractionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_interaction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, INTERACTION_CLASS);
	
	m_interaction_Attribute_action = factory->createEReference_as_eReferences_in_EClass(m_interaction_Class, INTERACTION_ATTRIBUTE_ACTION);
	m_interaction_Attribute_formalGate = factory->createEReference_as_eReferences_in_EClass(m_interaction_Class, INTERACTION_ATTRIBUTE_FORMALGATE);
	m_interaction_Attribute_fragment = factory->createEReference_as_eReferences_in_EClass(m_interaction_Class, INTERACTION_ATTRIBUTE_FRAGMENT);
	m_interaction_Attribute_lifeline = factory->createEReference_as_eReferences_in_EClass(m_interaction_Class, INTERACTION_ATTRIBUTE_LIFELINE);
	m_interaction_Attribute_message = factory->createEReference_as_eReferences_in_EClass(m_interaction_Class, INTERACTION_ATTRIBUTE_MESSAGE);
	
	
}

void umlPackageImpl::createInteractionConstraintContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_interactionConstraint_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, INTERACTIONCONSTRAINT_CLASS);
	
	m_interactionConstraint_Attribute_maxint = factory->createEReference_as_eReferences_in_EClass(m_interactionConstraint_Class, INTERACTIONCONSTRAINT_ATTRIBUTE_MAXINT);
	m_interactionConstraint_Attribute_minint = factory->createEReference_as_eReferences_in_EClass(m_interactionConstraint_Class, INTERACTIONCONSTRAINT_ATTRIBUTE_MININT);
	
	
}

void umlPackageImpl::createInteractionFragmentContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_interactionFragment_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, INTERACTIONFRAGMENT_CLASS);
	
	m_interactionFragment_Attribute_covered = factory->createEReference_as_eReferences_in_EClass(m_interactionFragment_Class, INTERACTIONFRAGMENT_ATTRIBUTE_COVERED);
	m_interactionFragment_Attribute_enclosingInteraction = factory->createEReference_as_eReferences_in_EClass(m_interactionFragment_Class, INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGINTERACTION);
	m_interactionFragment_Attribute_enclosingOperand = factory->createEReference_as_eReferences_in_EClass(m_interactionFragment_Class, INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGOPERAND);
	m_interactionFragment_Attribute_generalOrdering = factory->createEReference_as_eReferences_in_EClass(m_interactionFragment_Class, INTERACTIONFRAGMENT_ATTRIBUTE_GENERALORDERING);
	
	
}

void umlPackageImpl::createInteractionOperandContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_interactionOperand_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, INTERACTIONOPERAND_CLASS);
	
	m_interactionOperand_Attribute_fragment = factory->createEReference_as_eReferences_in_EClass(m_interactionOperand_Class, INTERACTIONOPERAND_ATTRIBUTE_FRAGMENT);
	m_interactionOperand_Attribute_guard = factory->createEReference_as_eReferences_in_EClass(m_interactionOperand_Class, INTERACTIONOPERAND_ATTRIBUTE_GUARD);
	
	
}

void umlPackageImpl::createInteractionUseContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_interactionUse_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, INTERACTIONUSE_CLASS);
	
	m_interactionUse_Attribute_actualGate = factory->createEReference_as_eReferences_in_EClass(m_interactionUse_Class, INTERACTIONUSE_ATTRIBUTE_ACTUALGATE);
	m_interactionUse_Attribute_argument = factory->createEReference_as_eReferences_in_EClass(m_interactionUse_Class, INTERACTIONUSE_ATTRIBUTE_ARGUMENT);
	m_interactionUse_Attribute_refersTo = factory->createEReference_as_eReferences_in_EClass(m_interactionUse_Class, INTERACTIONUSE_ATTRIBUTE_REFERSTO);
	m_interactionUse_Attribute_returnValue = factory->createEReference_as_eReferences_in_EClass(m_interactionUse_Class, INTERACTIONUSE_ATTRIBUTE_RETURNVALUE);
	m_interactionUse_Attribute_returnValueRecipient = factory->createEReference_as_eReferences_in_EClass(m_interactionUse_Class, INTERACTIONUSE_ATTRIBUTE_RETURNVALUERECIPIENT);
	
	
}

void umlPackageImpl::createInterfaceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_interface_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, INTERFACE_CLASS);
	
	m_interface_Attribute_nestedClassifier = factory->createEReference_as_eReferences_in_EClass(m_interface_Class, INTERFACE_ATTRIBUTE_NESTEDCLASSIFIER);
	m_interface_Attribute_ownedAttribute = factory->createEReference_as_eReferences_in_EClass(m_interface_Class, INTERFACE_ATTRIBUTE_OWNEDATTRIBUTE);
	m_interface_Attribute_ownedOperation = factory->createEReference_as_eReferences_in_EClass(m_interface_Class, INTERFACE_ATTRIBUTE_OWNEDOPERATION);
	m_interface_Attribute_ownedReception = factory->createEReference_as_eReferences_in_EClass(m_interface_Class, INTERFACE_ATTRIBUTE_OWNEDRECEPTION);
	m_interface_Attribute_protocol = factory->createEReference_as_eReferences_in_EClass(m_interface_Class, INTERFACE_ATTRIBUTE_PROTOCOL);
	m_interface_Attribute_redefinedInterface = factory->createEReference_as_eReferences_in_EClass(m_interface_Class, INTERFACE_ATTRIBUTE_REDEFINEDINTERFACE);
	
	m_interface_Operation_createOwnedAttribute_String_UnlimitedNatural = factory->createEOperation_as_eOperations_in_EClass(m_interface_Class, INTERFACE_OPERATION_CREATEOWNEDATTRIBUTE_STRING_UNLIMITEDNATURAL);
	m_interface_Operation_createOwnedOperation_String_Type = factory->createEOperation_as_eOperations_in_EClass(m_interface_Class, INTERFACE_OPERATION_CREATEOWNEDOPERATION_STRING_TYPE);
	
}

void umlPackageImpl::createInterfaceRealizationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_interfaceRealization_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, INTERFACEREALIZATION_CLASS);
	
	m_interfaceRealization_Attribute_contract = factory->createEReference_as_eReferences_in_EClass(m_interfaceRealization_Class, INTERFACEREALIZATION_ATTRIBUTE_CONTRACT);
	m_interfaceRealization_Attribute_implementingClassifier = factory->createEReference_as_eReferences_in_EClass(m_interfaceRealization_Class, INTERFACEREALIZATION_ATTRIBUTE_IMPLEMENTINGCLASSIFIER);
	
	
}

void umlPackageImpl::createInterruptibleActivityRegionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_interruptibleActivityRegion_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, INTERRUPTIBLEACTIVITYREGION_CLASS);
	
	m_interruptibleActivityRegion_Attribute_interruptingEdge = factory->createEReference_as_eReferences_in_EClass(m_interruptibleActivityRegion_Class, INTERRUPTIBLEACTIVITYREGION_ATTRIBUTE_INTERRUPTINGEDGE);
	m_interruptibleActivityRegion_Attribute_node = factory->createEReference_as_eReferences_in_EClass(m_interruptibleActivityRegion_Class, INTERRUPTIBLEACTIVITYREGION_ATTRIBUTE_NODE);
	
	
}

void umlPackageImpl::createIntervalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_interval_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, INTERVAL_CLASS);
	
	m_interval_Attribute_max = factory->createEReference_as_eReferences_in_EClass(m_interval_Class, INTERVAL_ATTRIBUTE_MAX);
	m_interval_Attribute_min = factory->createEReference_as_eReferences_in_EClass(m_interval_Class, INTERVAL_ATTRIBUTE_MIN);
	
	
}

void umlPackageImpl::createIntervalConstraintContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_intervalConstraint_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, INTERVALCONSTRAINT_CLASS);
	
	
	
}

void umlPackageImpl::createInvocationActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_invocationAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, INVOCATIONACTION_CLASS);
	
	m_invocationAction_Attribute_argument = factory->createEReference_as_eReferences_in_EClass(m_invocationAction_Class, INVOCATIONACTION_ATTRIBUTE_ARGUMENT);
	m_invocationAction_Attribute_onPort = factory->createEReference_as_eReferences_in_EClass(m_invocationAction_Class, INVOCATIONACTION_ATTRIBUTE_ONPORT);
	
	
}

void umlPackageImpl::createJoinNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_joinNode_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, JOINNODE_CLASS);
	m_joinNode_Attribute_isCombineDuplicate = factory->createEAttribute_as_eAttributes_in_EClass(m_joinNode_Class, JOINNODE_ATTRIBUTE_ISCOMBINEDUPLICATE);
	
	m_joinNode_Attribute_joinSpec = factory->createEReference_as_eReferences_in_EClass(m_joinNode_Class, JOINNODE_ATTRIBUTE_JOINSPEC);
	
	
}

void umlPackageImpl::createLifelineContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_lifeline_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, LIFELINE_CLASS);
	
	m_lifeline_Attribute_coveredBy = factory->createEReference_as_eReferences_in_EClass(m_lifeline_Class, LIFELINE_ATTRIBUTE_COVEREDBY);
	m_lifeline_Attribute_decomposedAs = factory->createEReference_as_eReferences_in_EClass(m_lifeline_Class, LIFELINE_ATTRIBUTE_DECOMPOSEDAS);
	m_lifeline_Attribute_interaction = factory->createEReference_as_eReferences_in_EClass(m_lifeline_Class, LIFELINE_ATTRIBUTE_INTERACTION);
	m_lifeline_Attribute_represents = factory->createEReference_as_eReferences_in_EClass(m_lifeline_Class, LIFELINE_ATTRIBUTE_REPRESENTS);
	m_lifeline_Attribute_selector = factory->createEReference_as_eReferences_in_EClass(m_lifeline_Class, LIFELINE_ATTRIBUTE_SELECTOR);
	
	
}

void umlPackageImpl::createLinkActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_linkAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, LINKACTION_CLASS);
	
	m_linkAction_Attribute_endData = factory->createEReference_as_eReferences_in_EClass(m_linkAction_Class, LINKACTION_ATTRIBUTE_ENDDATA);
	m_linkAction_Attribute_inputValue = factory->createEReference_as_eReferences_in_EClass(m_linkAction_Class, LINKACTION_ATTRIBUTE_INPUTVALUE);
	
	m_linkAction_Operation_association = factory->createEOperation_as_eOperations_in_EClass(m_linkAction_Class, LINKACTION_OPERATION_ASSOCIATION);
	
}

void umlPackageImpl::createLinkEndCreationDataContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_linkEndCreationData_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, LINKENDCREATIONDATA_CLASS);
	m_linkEndCreationData_Attribute_isReplaceAll = factory->createEAttribute_as_eAttributes_in_EClass(m_linkEndCreationData_Class, LINKENDCREATIONDATA_ATTRIBUTE_ISREPLACEALL);
	
	m_linkEndCreationData_Attribute_insertAt = factory->createEReference_as_eReferences_in_EClass(m_linkEndCreationData_Class, LINKENDCREATIONDATA_ATTRIBUTE_INSERTAT);
	
	
}

void umlPackageImpl::createLinkEndDataContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_linkEndData_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, LINKENDDATA_CLASS);
	
	m_linkEndData_Attribute_end = factory->createEReference_as_eReferences_in_EClass(m_linkEndData_Class, LINKENDDATA_ATTRIBUTE_END);
	m_linkEndData_Attribute_qualifier = factory->createEReference_as_eReferences_in_EClass(m_linkEndData_Class, LINKENDDATA_ATTRIBUTE_QUALIFIER);
	m_linkEndData_Attribute_value = factory->createEReference_as_eReferences_in_EClass(m_linkEndData_Class, LINKENDDATA_ATTRIBUTE_VALUE);
	
	m_linkEndData_Operation_allPins = factory->createEOperation_as_eOperations_in_EClass(m_linkEndData_Class, LINKENDDATA_OPERATION_ALLPINS);
	
}

void umlPackageImpl::createLinkEndDestructionDataContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_linkEndDestructionData_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, LINKENDDESTRUCTIONDATA_CLASS);
	m_linkEndDestructionData_Attribute_isDestroyDuplicates = factory->createEAttribute_as_eAttributes_in_EClass(m_linkEndDestructionData_Class, LINKENDDESTRUCTIONDATA_ATTRIBUTE_ISDESTROYDUPLICATES);
	
	m_linkEndDestructionData_Attribute_destroyAt = factory->createEReference_as_eReferences_in_EClass(m_linkEndDestructionData_Class, LINKENDDESTRUCTIONDATA_ATTRIBUTE_DESTROYAT);
	
	
}

void umlPackageImpl::createLiteralBooleanContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_literalBoolean_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, LITERALBOOLEAN_CLASS);
	m_literalBoolean_Attribute_value = factory->createEAttribute_as_eAttributes_in_EClass(m_literalBoolean_Class, LITERALBOOLEAN_ATTRIBUTE_VALUE);
	
	
	m_literalBoolean_Operation_booleanValue = factory->createEOperation_as_eOperations_in_EClass(m_literalBoolean_Class, LITERALBOOLEAN_OPERATION_BOOLEANVALUE);
	m_literalBoolean_Operation_isComputable = factory->createEOperation_as_eOperations_in_EClass(m_literalBoolean_Class, LITERALBOOLEAN_OPERATION_ISCOMPUTABLE);
	
}

void umlPackageImpl::createLiteralIntegerContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_literalInteger_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, LITERALINTEGER_CLASS);
	m_literalInteger_Attribute_value = factory->createEAttribute_as_eAttributes_in_EClass(m_literalInteger_Class, LITERALINTEGER_ATTRIBUTE_VALUE);
	
	
	m_literalInteger_Operation_integerValue = factory->createEOperation_as_eOperations_in_EClass(m_literalInteger_Class, LITERALINTEGER_OPERATION_INTEGERVALUE);
	m_literalInteger_Operation_isComputable = factory->createEOperation_as_eOperations_in_EClass(m_literalInteger_Class, LITERALINTEGER_OPERATION_ISCOMPUTABLE);
	
}

void umlPackageImpl::createLiteralNullContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_literalNull_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, LITERALNULL_CLASS);
	
	
	m_literalNull_Operation_isComputable = factory->createEOperation_as_eOperations_in_EClass(m_literalNull_Class, LITERALNULL_OPERATION_ISCOMPUTABLE);
	m_literalNull_Operation_isNull = factory->createEOperation_as_eOperations_in_EClass(m_literalNull_Class, LITERALNULL_OPERATION_ISNULL);
	
}

void umlPackageImpl::createLiteralRealContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_literalReal_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, LITERALREAL_CLASS);
	m_literalReal_Attribute_value = factory->createEAttribute_as_eAttributes_in_EClass(m_literalReal_Class, LITERALREAL_ATTRIBUTE_VALUE);
	
	
	m_literalReal_Operation_isComputable = factory->createEOperation_as_eOperations_in_EClass(m_literalReal_Class, LITERALREAL_OPERATION_ISCOMPUTABLE);
	m_literalReal_Operation_realValue = factory->createEOperation_as_eOperations_in_EClass(m_literalReal_Class, LITERALREAL_OPERATION_REALVALUE);
	
}

void umlPackageImpl::createLiteralSpecificationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_literalSpecification_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, LITERALSPECIFICATION_CLASS);
	
	
	
}

void umlPackageImpl::createLiteralStringContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_literalString_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, LITERALSTRING_CLASS);
	m_literalString_Attribute_value = factory->createEAttribute_as_eAttributes_in_EClass(m_literalString_Class, LITERALSTRING_ATTRIBUTE_VALUE);
	
	
	m_literalString_Operation_isComputable = factory->createEOperation_as_eOperations_in_EClass(m_literalString_Class, LITERALSTRING_OPERATION_ISCOMPUTABLE);
	m_literalString_Operation_stringValue = factory->createEOperation_as_eOperations_in_EClass(m_literalString_Class, LITERALSTRING_OPERATION_STRINGVALUE);
	
}

void umlPackageImpl::createLiteralUnlimitedNaturalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_literalUnlimitedNatural_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, LITERALUNLIMITEDNATURAL_CLASS);
	m_literalUnlimitedNatural_Attribute_value = factory->createEAttribute_as_eAttributes_in_EClass(m_literalUnlimitedNatural_Class, LITERALUNLIMITEDNATURAL_ATTRIBUTE_VALUE);
	
	
	m_literalUnlimitedNatural_Operation_isComputable = factory->createEOperation_as_eOperations_in_EClass(m_literalUnlimitedNatural_Class, LITERALUNLIMITEDNATURAL_OPERATION_ISCOMPUTABLE);
	m_literalUnlimitedNatural_Operation_unlimitedValue = factory->createEOperation_as_eOperations_in_EClass(m_literalUnlimitedNatural_Class, LITERALUNLIMITEDNATURAL_OPERATION_UNLIMITEDVALUE);
	
}

void umlPackageImpl::createLoopNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_loopNode_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, LOOPNODE_CLASS);
	m_loopNode_Attribute_isTestedFirst = factory->createEAttribute_as_eAttributes_in_EClass(m_loopNode_Class, LOOPNODE_ATTRIBUTE_ISTESTEDFIRST);
	
	m_loopNode_Attribute_bodyOutput = factory->createEReference_as_eReferences_in_EClass(m_loopNode_Class, LOOPNODE_ATTRIBUTE_BODYOUTPUT);
	m_loopNode_Attribute_bodyPart = factory->createEReference_as_eReferences_in_EClass(m_loopNode_Class, LOOPNODE_ATTRIBUTE_BODYPART);
	m_loopNode_Attribute_decider = factory->createEReference_as_eReferences_in_EClass(m_loopNode_Class, LOOPNODE_ATTRIBUTE_DECIDER);
	m_loopNode_Attribute_loopVariable = factory->createEReference_as_eReferences_in_EClass(m_loopNode_Class, LOOPNODE_ATTRIBUTE_LOOPVARIABLE);
	m_loopNode_Attribute_loopVariableInput = factory->createEReference_as_eReferences_in_EClass(m_loopNode_Class, LOOPNODE_ATTRIBUTE_LOOPVARIABLEINPUT);
	m_loopNode_Attribute_result = factory->createEReference_as_eReferences_in_EClass(m_loopNode_Class, LOOPNODE_ATTRIBUTE_RESULT);
	m_loopNode_Attribute_setupPart = factory->createEReference_as_eReferences_in_EClass(m_loopNode_Class, LOOPNODE_ATTRIBUTE_SETUPPART);
	m_loopNode_Attribute_test = factory->createEReference_as_eReferences_in_EClass(m_loopNode_Class, LOOPNODE_ATTRIBUTE_TEST);
	
	
}

void umlPackageImpl::createManifestationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_manifestation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, MANIFESTATION_CLASS);
	
	m_manifestation_Attribute_utilizedElement = factory->createEReference_as_eReferences_in_EClass(m_manifestation_Class, MANIFESTATION_ATTRIBUTE_UTILIZEDELEMENT);
	
	
}

void umlPackageImpl::createMergeNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_mergeNode_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, MERGENODE_CLASS);
	
	
	
}

void umlPackageImpl::createMessageContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_message_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, MESSAGE_CLASS);
	m_message_Attribute_messageKind = factory->createEAttribute_as_eAttributes_in_EClass(m_message_Class, MESSAGE_ATTRIBUTE_MESSAGEKIND);
	m_message_Attribute_messageSort = factory->createEAttribute_as_eAttributes_in_EClass(m_message_Class, MESSAGE_ATTRIBUTE_MESSAGESORT);
	
	m_message_Attribute_argument = factory->createEReference_as_eReferences_in_EClass(m_message_Class, MESSAGE_ATTRIBUTE_ARGUMENT);
	m_message_Attribute_connector = factory->createEReference_as_eReferences_in_EClass(m_message_Class, MESSAGE_ATTRIBUTE_CONNECTOR);
	m_message_Attribute_interaction = factory->createEReference_as_eReferences_in_EClass(m_message_Class, MESSAGE_ATTRIBUTE_INTERACTION);
	m_message_Attribute_receiveEvent = factory->createEReference_as_eReferences_in_EClass(m_message_Class, MESSAGE_ATTRIBUTE_RECEIVEEVENT);
	m_message_Attribute_sendEvent = factory->createEReference_as_eReferences_in_EClass(m_message_Class, MESSAGE_ATTRIBUTE_SENDEVENT);
	m_message_Attribute_signature = factory->createEReference_as_eReferences_in_EClass(m_message_Class, MESSAGE_ATTRIBUTE_SIGNATURE);
	
	m_message_Operation_getMessageKind = factory->createEOperation_as_eOperations_in_EClass(m_message_Class, MESSAGE_OPERATION_GETMESSAGEKIND);
	
}

void umlPackageImpl::createMessageEndContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_messageEnd_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, MESSAGEEND_CLASS);
	
	m_messageEnd_Attribute_message = factory->createEReference_as_eReferences_in_EClass(m_messageEnd_Class, MESSAGEEND_ATTRIBUTE_MESSAGE);
	
	m_messageEnd_Operation_enclosingFragment = factory->createEOperation_as_eOperations_in_EClass(m_messageEnd_Class, MESSAGEEND_OPERATION_ENCLOSINGFRAGMENT);
	m_messageEnd_Operation_isReceive = factory->createEOperation_as_eOperations_in_EClass(m_messageEnd_Class, MESSAGEEND_OPERATION_ISRECEIVE);
	m_messageEnd_Operation_isSend = factory->createEOperation_as_eOperations_in_EClass(m_messageEnd_Class, MESSAGEEND_OPERATION_ISSEND);
	m_messageEnd_Operation_oppositeEnd = factory->createEOperation_as_eOperations_in_EClass(m_messageEnd_Class, MESSAGEEND_OPERATION_OPPOSITEEND);
	
}

void umlPackageImpl::createMessageEventContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_messageEvent_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, MESSAGEEVENT_CLASS);
	
	
	
}

void umlPackageImpl::createMessageOccurrenceSpecificationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_messageOccurrenceSpecification_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, MESSAGEOCCURRENCESPECIFICATION_CLASS);
	
	
	
}

void umlPackageImpl::createModelContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_model_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, MODEL_CLASS);
	m_model_Attribute_viewpoint = factory->createEAttribute_as_eAttributes_in_EClass(m_model_Class, MODEL_ATTRIBUTE_VIEWPOINT);
	
	
	m_model_Operation_isMetamodel = factory->createEOperation_as_eOperations_in_EClass(m_model_Class, MODEL_OPERATION_ISMETAMODEL);
	
}

void umlPackageImpl::createMultiplicityElementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_multiplicityElement_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, MULTIPLICITYELEMENT_CLASS);
	m_multiplicityElement_Attribute_isOrdered = factory->createEAttribute_as_eAttributes_in_EClass(m_multiplicityElement_Class, MULTIPLICITYELEMENT_ATTRIBUTE_ISORDERED);
	m_multiplicityElement_Attribute_isUnique = factory->createEAttribute_as_eAttributes_in_EClass(m_multiplicityElement_Class, MULTIPLICITYELEMENT_ATTRIBUTE_ISUNIQUE);
	m_multiplicityElement_Attribute_lower = factory->createEAttribute_as_eAttributes_in_EClass(m_multiplicityElement_Class, MULTIPLICITYELEMENT_ATTRIBUTE_LOWER);
	m_multiplicityElement_Attribute_upper = factory->createEAttribute_as_eAttributes_in_EClass(m_multiplicityElement_Class, MULTIPLICITYELEMENT_ATTRIBUTE_UPPER);
	
	m_multiplicityElement_Attribute_lowerValue = factory->createEReference_as_eReferences_in_EClass(m_multiplicityElement_Class, MULTIPLICITYELEMENT_ATTRIBUTE_LOWERVALUE);
	m_multiplicityElement_Attribute_upperValue = factory->createEReference_as_eReferences_in_EClass(m_multiplicityElement_Class, MULTIPLICITYELEMENT_ATTRIBUTE_UPPERVALUE);
	
	m_multiplicityElement_Operation_compatibleWith_MultiplicityElement = factory->createEOperation_as_eOperations_in_EClass(m_multiplicityElement_Class, MULTIPLICITYELEMENT_OPERATION_COMPATIBLEWITH_MULTIPLICITYELEMENT);
	m_multiplicityElement_Operation_includesMultiplicity_MultiplicityElement = factory->createEOperation_as_eOperations_in_EClass(m_multiplicityElement_Class, MULTIPLICITYELEMENT_OPERATION_INCLUDESMULTIPLICITY_MULTIPLICITYELEMENT);
	m_multiplicityElement_Operation_is_Integer_UnlimitedNatural = factory->createEOperation_as_eOperations_in_EClass(m_multiplicityElement_Class, MULTIPLICITYELEMENT_OPERATION_IS_INTEGER_UNLIMITEDNATURAL);
	m_multiplicityElement_Operation_isMultivalued = factory->createEOperation_as_eOperations_in_EClass(m_multiplicityElement_Class, MULTIPLICITYELEMENT_OPERATION_ISMULTIVALUED);
	m_multiplicityElement_Operation_lowerBound = factory->createEOperation_as_eOperations_in_EClass(m_multiplicityElement_Class, MULTIPLICITYELEMENT_OPERATION_LOWERBOUND);
	m_multiplicityElement_Operation_upperBound = factory->createEOperation_as_eOperations_in_EClass(m_multiplicityElement_Class, MULTIPLICITYELEMENT_OPERATION_UPPERBOUND);
	
}

void umlPackageImpl::createNamedElementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_namedElement_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, NAMEDELEMENT_CLASS);
	m_namedElement_Attribute_name = factory->createEAttribute_as_eAttributes_in_EClass(m_namedElement_Class, NAMEDELEMENT_ATTRIBUTE_NAME);
	m_namedElement_Attribute_qualifiedName = factory->createEAttribute_as_eAttributes_in_EClass(m_namedElement_Class, NAMEDELEMENT_ATTRIBUTE_QUALIFIEDNAME);
	m_namedElement_Attribute_visibility = factory->createEAttribute_as_eAttributes_in_EClass(m_namedElement_Class, NAMEDELEMENT_ATTRIBUTE_VISIBILITY);
	
	m_namedElement_Attribute_clientDependency = factory->createEReference_as_eReferences_in_EClass(m_namedElement_Class, NAMEDELEMENT_ATTRIBUTE_CLIENTDEPENDENCY);
	m_namedElement_Attribute_nameExpression = factory->createEReference_as_eReferences_in_EClass(m_namedElement_Class, NAMEDELEMENT_ATTRIBUTE_NAMEEXPRESSION);
	m_namedElement_Attribute_namespace = factory->createEReference_as_eReferences_in_EClass(m_namedElement_Class, NAMEDELEMENT_ATTRIBUTE_NAMESPACE);
	
	m_namedElement_Operation_allNamespaces = factory->createEOperation_as_eOperations_in_EClass(m_namedElement_Class, NAMEDELEMENT_OPERATION_ALLNAMESPACES);
	m_namedElement_Operation_allOwningPackages = factory->createEOperation_as_eOperations_in_EClass(m_namedElement_Class, NAMEDELEMENT_OPERATION_ALLOWNINGPACKAGES);
	m_namedElement_Operation_createDependency_NamedElement = factory->createEOperation_as_eOperations_in_EClass(m_namedElement_Class, NAMEDELEMENT_OPERATION_CREATEDEPENDENCY_NAMEDELEMENT);
	m_namedElement_Operation_createUsage_NamedElement = factory->createEOperation_as_eOperations_in_EClass(m_namedElement_Class, NAMEDELEMENT_OPERATION_CREATEUSAGE_NAMEDELEMENT);
	m_namedElement_Operation_getClientDependencies = factory->createEOperation_as_eOperations_in_EClass(m_namedElement_Class, NAMEDELEMENT_OPERATION_GETCLIENTDEPENDENCIES);
	m_namedElement_Operation_getLabel = factory->createEOperation_as_eOperations_in_EClass(m_namedElement_Class, NAMEDELEMENT_OPERATION_GETLABEL);
	m_namedElement_Operation_getLabel_Boolean = factory->createEOperation_as_eOperations_in_EClass(m_namedElement_Class, NAMEDELEMENT_OPERATION_GETLABEL_BOOLEAN);
	m_namedElement_Operation_getNamespace = factory->createEOperation_as_eOperations_in_EClass(m_namedElement_Class, NAMEDELEMENT_OPERATION_GETNAMESPACE);
	m_namedElement_Operation_getQualifiedName = factory->createEOperation_as_eOperations_in_EClass(m_namedElement_Class, NAMEDELEMENT_OPERATION_GETQUALIFIEDNAME);
	m_namedElement_Operation_isDistinguishableFrom_NamedElement_Namespace = factory->createEOperation_as_eOperations_in_EClass(m_namedElement_Class, NAMEDELEMENT_OPERATION_ISDISTINGUISHABLEFROM_NAMEDELEMENT_NAMESPACE);
	m_namedElement_Operation_separator = factory->createEOperation_as_eOperations_in_EClass(m_namedElement_Class, NAMEDELEMENT_OPERATION_SEPARATOR);
	
}

void umlPackageImpl::createNamespaceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_namespace_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, NAMESPACE_CLASS);
	
	m_namespace_Attribute_elementImport = factory->createEReference_as_eReferences_in_EClass(m_namespace_Class, NAMESPACE_ATTRIBUTE_ELEMENTIMPORT);
	m_namespace_Attribute_importedMember = factory->createEReference_as_eReferences_in_EClass(m_namespace_Class, NAMESPACE_ATTRIBUTE_IMPORTEDMEMBER);
	m_namespace_Attribute_member = factory->createEReference_as_eReferences_in_EClass(m_namespace_Class, NAMESPACE_ATTRIBUTE_MEMBER);
	m_namespace_Attribute_ownedMember = factory->createEReference_as_eReferences_in_EClass(m_namespace_Class, NAMESPACE_ATTRIBUTE_OWNEDMEMBER);
	m_namespace_Attribute_ownedRule = factory->createEReference_as_eReferences_in_EClass(m_namespace_Class, NAMESPACE_ATTRIBUTE_OWNEDRULE);
	m_namespace_Attribute_packageImport = factory->createEReference_as_eReferences_in_EClass(m_namespace_Class, NAMESPACE_ATTRIBUTE_PACKAGEIMPORT);
	
	m_namespace_Operation_createElementImport_PackageableElement_VisibilityKind = factory->createEOperation_as_eOperations_in_EClass(m_namespace_Class, NAMESPACE_OPERATION_CREATEELEMENTIMPORT_PACKAGEABLEELEMENT_VISIBILITYKIND);
	m_namespace_Operation_createPackageImport_Package_VisibilityKind = factory->createEOperation_as_eOperations_in_EClass(m_namespace_Class, NAMESPACE_OPERATION_CREATEPACKAGEIMPORT_PACKAGE_VISIBILITYKIND);
	m_namespace_Operation_excludeCollisions_PackageableElement = factory->createEOperation_as_eOperations_in_EClass(m_namespace_Class, NAMESPACE_OPERATION_EXCLUDECOLLISIONS_PACKAGEABLEELEMENT);
	m_namespace_Operation_getImportedElements = factory->createEOperation_as_eOperations_in_EClass(m_namespace_Class, NAMESPACE_OPERATION_GETIMPORTEDELEMENTS);
	m_namespace_Operation_getImportedMembers = factory->createEOperation_as_eOperations_in_EClass(m_namespace_Class, NAMESPACE_OPERATION_GETIMPORTEDMEMBERS);
	m_namespace_Operation_getImportedPackages = factory->createEOperation_as_eOperations_in_EClass(m_namespace_Class, NAMESPACE_OPERATION_GETIMPORTEDPACKAGES);
	m_namespace_Operation_getNamesOfMember_NamedElement = factory->createEOperation_as_eOperations_in_EClass(m_namespace_Class, NAMESPACE_OPERATION_GETNAMESOFMEMBER_NAMEDELEMENT);
	m_namespace_Operation_getOwnedMembers = factory->createEOperation_as_eOperations_in_EClass(m_namespace_Class, NAMESPACE_OPERATION_GETOWNEDMEMBERS);
	m_namespace_Operation_importMembers_PackageableElement = factory->createEOperation_as_eOperations_in_EClass(m_namespace_Class, NAMESPACE_OPERATION_IMPORTMEMBERS_PACKAGEABLEELEMENT);
	m_namespace_Operation_membersAreDistinguishable = factory->createEOperation_as_eOperations_in_EClass(m_namespace_Class, NAMESPACE_OPERATION_MEMBERSAREDISTINGUISHABLE);
	
}

void umlPackageImpl::createNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_node_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, NODE_CLASS);
	
	m_node_Attribute_nestedNode = factory->createEReference_as_eReferences_in_EClass(m_node_Class, NODE_ATTRIBUTE_NESTEDNODE);
	
	m_node_Operation_createCommunicationPath_Boolean_UnlimitedNatural = factory->createEOperation_as_eOperations_in_EClass(m_node_Class, NODE_OPERATION_CREATECOMMUNICATIONPATH_BOOLEAN_UNLIMITEDNATURAL);
	m_node_Operation_getCommunicationPaths = factory->createEOperation_as_eOperations_in_EClass(m_node_Class, NODE_OPERATION_GETCOMMUNICATIONPATHS);
	
}

void umlPackageImpl::createObjectContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_object_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, OBJECT_CLASS);
	
	
	m_object_Operation_add_Property_EJavaObject = factory->createEOperation_as_eOperations_in_EClass(m_object_Class, OBJECT_OPERATION_ADD_PROPERTY_EJAVAOBJECT);
	m_object_Operation_add_Property_EInt = factory->createEOperation_as_eOperations_in_EClass(m_object_Class, OBJECT_OPERATION_ADD_PROPERTY_EINT);
	m_object_Operation_destroy = factory->createEOperation_as_eOperations_in_EClass(m_object_Class, OBJECT_OPERATION_DESTROY);
	m_object_Operation_get_Property = factory->createEOperation_as_eOperations_in_EClass(m_object_Class, OBJECT_OPERATION_GET_PROPERTY);
	m_object_Operation_invoke_Operation_EJavaObject = factory->createEOperation_as_eOperations_in_EClass(m_object_Class, OBJECT_OPERATION_INVOKE_OPERATION_EJAVAOBJECT);
	m_object_Operation_invoke_OpaqueBehavior_EJavaObject = factory->createEOperation_as_eOperations_in_EClass(m_object_Class, OBJECT_OPERATION_INVOKE_OPAQUEBEHAVIOR_EJAVAOBJECT);
	m_object_Operation_remove_Property_EBoolean = factory->createEOperation_as_eOperations_in_EClass(m_object_Class, OBJECT_OPERATION_REMOVE_PROPERTY_EBOOLEAN);
	m_object_Operation_set_Property_EJavaObject = factory->createEOperation_as_eOperations_in_EClass(m_object_Class, OBJECT_OPERATION_SET_PROPERTY_EJAVAOBJECT);
	m_object_Operation_unset_Property = factory->createEOperation_as_eOperations_in_EClass(m_object_Class, OBJECT_OPERATION_UNSET_PROPERTY);
	
}

void umlPackageImpl::createObjectFlowContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_objectFlow_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, OBJECTFLOW_CLASS);
	m_objectFlow_Attribute_isMulticast = factory->createEAttribute_as_eAttributes_in_EClass(m_objectFlow_Class, OBJECTFLOW_ATTRIBUTE_ISMULTICAST);
	m_objectFlow_Attribute_isMultireceive = factory->createEAttribute_as_eAttributes_in_EClass(m_objectFlow_Class, OBJECTFLOW_ATTRIBUTE_ISMULTIRECEIVE);
	
	m_objectFlow_Attribute_selection = factory->createEReference_as_eReferences_in_EClass(m_objectFlow_Class, OBJECTFLOW_ATTRIBUTE_SELECTION);
	m_objectFlow_Attribute_transformation = factory->createEReference_as_eReferences_in_EClass(m_objectFlow_Class, OBJECTFLOW_ATTRIBUTE_TRANSFORMATION);
	
	
}

void umlPackageImpl::createObjectNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_objectNode_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, OBJECTNODE_CLASS);
	m_objectNode_Attribute_isControlType = factory->createEAttribute_as_eAttributes_in_EClass(m_objectNode_Class, OBJECTNODE_ATTRIBUTE_ISCONTROLTYPE);
	m_objectNode_Attribute_ordering = factory->createEAttribute_as_eAttributes_in_EClass(m_objectNode_Class, OBJECTNODE_ATTRIBUTE_ORDERING);
	
	m_objectNode_Attribute_inState = factory->createEReference_as_eReferences_in_EClass(m_objectNode_Class, OBJECTNODE_ATTRIBUTE_INSTATE);
	m_objectNode_Attribute_selection = factory->createEReference_as_eReferences_in_EClass(m_objectNode_Class, OBJECTNODE_ATTRIBUTE_SELECTION);
	m_objectNode_Attribute_upperBound = factory->createEReference_as_eReferences_in_EClass(m_objectNode_Class, OBJECTNODE_ATTRIBUTE_UPPERBOUND);
	
	
}

void umlPackageImpl::createObservationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_observation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, OBSERVATION_CLASS);
	
	
	
}

void umlPackageImpl::createOccurrenceSpecificationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_occurrenceSpecification_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, OCCURRENCESPECIFICATION_CLASS);
	
	m_occurrenceSpecification_Attribute_toAfter = factory->createEReference_as_eReferences_in_EClass(m_occurrenceSpecification_Class, OCCURRENCESPECIFICATION_ATTRIBUTE_TOAFTER);
	m_occurrenceSpecification_Attribute_toBefore = factory->createEReference_as_eReferences_in_EClass(m_occurrenceSpecification_Class, OCCURRENCESPECIFICATION_ATTRIBUTE_TOBEFORE);
	
	m_occurrenceSpecification_Operation_getCovered = factory->createEOperation_as_eOperations_in_EClass(m_occurrenceSpecification_Class, OCCURRENCESPECIFICATION_OPERATION_GETCOVERED);
	m_occurrenceSpecification_Operation_setCovered_Lifeline = factory->createEOperation_as_eOperations_in_EClass(m_occurrenceSpecification_Class, OCCURRENCESPECIFICATION_OPERATION_SETCOVERED_LIFELINE);
	
}

void umlPackageImpl::createOpaqueActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_opaqueAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, OPAQUEACTION_CLASS);
	m_opaqueAction_Attribute_body = factory->createEAttribute_as_eAttributes_in_EClass(m_opaqueAction_Class, OPAQUEACTION_ATTRIBUTE_BODY);
	m_opaqueAction_Attribute_language = factory->createEAttribute_as_eAttributes_in_EClass(m_opaqueAction_Class, OPAQUEACTION_ATTRIBUTE_LANGUAGE);
	
	m_opaqueAction_Attribute_inputValue = factory->createEReference_as_eReferences_in_EClass(m_opaqueAction_Class, OPAQUEACTION_ATTRIBUTE_INPUTVALUE);
	m_opaqueAction_Attribute_outputValue = factory->createEReference_as_eReferences_in_EClass(m_opaqueAction_Class, OPAQUEACTION_ATTRIBUTE_OUTPUTVALUE);
	
	
}

void umlPackageImpl::createOpaqueBehaviorContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_opaqueBehavior_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, OPAQUEBEHAVIOR_CLASS);
	m_opaqueBehavior_Attribute_body = factory->createEAttribute_as_eAttributes_in_EClass(m_opaqueBehavior_Class, OPAQUEBEHAVIOR_ATTRIBUTE_BODY);
	m_opaqueBehavior_Attribute_language = factory->createEAttribute_as_eAttributes_in_EClass(m_opaqueBehavior_Class, OPAQUEBEHAVIOR_ATTRIBUTE_LANGUAGE);
	
	
	
}

void umlPackageImpl::createOpaqueExpressionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_opaqueExpression_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, OPAQUEEXPRESSION_CLASS);
	m_opaqueExpression_Attribute_body = factory->createEAttribute_as_eAttributes_in_EClass(m_opaqueExpression_Class, OPAQUEEXPRESSION_ATTRIBUTE_BODY);
	m_opaqueExpression_Attribute_language = factory->createEAttribute_as_eAttributes_in_EClass(m_opaqueExpression_Class, OPAQUEEXPRESSION_ATTRIBUTE_LANGUAGE);
	
	m_opaqueExpression_Attribute_behavior = factory->createEReference_as_eReferences_in_EClass(m_opaqueExpression_Class, OPAQUEEXPRESSION_ATTRIBUTE_BEHAVIOR);
	m_opaqueExpression_Attribute_result = factory->createEReference_as_eReferences_in_EClass(m_opaqueExpression_Class, OPAQUEEXPRESSION_ATTRIBUTE_RESULT);
	
	m_opaqueExpression_Operation_getResult = factory->createEOperation_as_eOperations_in_EClass(m_opaqueExpression_Class, OPAQUEEXPRESSION_OPERATION_GETRESULT);
	m_opaqueExpression_Operation_isIntegral = factory->createEOperation_as_eOperations_in_EClass(m_opaqueExpression_Class, OPAQUEEXPRESSION_OPERATION_ISINTEGRAL);
	m_opaqueExpression_Operation_isNonNegative = factory->createEOperation_as_eOperations_in_EClass(m_opaqueExpression_Class, OPAQUEEXPRESSION_OPERATION_ISNONNEGATIVE);
	m_opaqueExpression_Operation_isPositive = factory->createEOperation_as_eOperations_in_EClass(m_opaqueExpression_Class, OPAQUEEXPRESSION_OPERATION_ISPOSITIVE);
	m_opaqueExpression_Operation_value = factory->createEOperation_as_eOperations_in_EClass(m_opaqueExpression_Class, OPAQUEEXPRESSION_OPERATION_VALUE);
	
}

void umlPackageImpl::createOperationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_operation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, OPERATION_CLASS);
	m_operation_Attribute_isOrdered = factory->createEAttribute_as_eAttributes_in_EClass(m_operation_Class, OPERATION_ATTRIBUTE_ISORDERED);
	m_operation_Attribute_isQuery = factory->createEAttribute_as_eAttributes_in_EClass(m_operation_Class, OPERATION_ATTRIBUTE_ISQUERY);
	m_operation_Attribute_isUnique = factory->createEAttribute_as_eAttributes_in_EClass(m_operation_Class, OPERATION_ATTRIBUTE_ISUNIQUE);
	m_operation_Attribute_lower = factory->createEAttribute_as_eAttributes_in_EClass(m_operation_Class, OPERATION_ATTRIBUTE_LOWER);
	m_operation_Attribute_upper = factory->createEAttribute_as_eAttributes_in_EClass(m_operation_Class, OPERATION_ATTRIBUTE_UPPER);
	
	m_operation_Attribute_bodyCondition = factory->createEReference_as_eReferences_in_EClass(m_operation_Class, OPERATION_ATTRIBUTE_BODYCONDITION);
	m_operation_Attribute_class = factory->createEReference_as_eReferences_in_EClass(m_operation_Class, OPERATION_ATTRIBUTE_CLASS);
	m_operation_Attribute_datatype = factory->createEReference_as_eReferences_in_EClass(m_operation_Class, OPERATION_ATTRIBUTE_DATATYPE);
	m_operation_Attribute_interface = factory->createEReference_as_eReferences_in_EClass(m_operation_Class, OPERATION_ATTRIBUTE_INTERFACE);
	m_operation_Attribute_ownedParameter = factory->createEReference_as_eReferences_in_EClass(m_operation_Class, OPERATION_ATTRIBUTE_OWNEDPARAMETER);
	m_operation_Attribute_postcondition = factory->createEReference_as_eReferences_in_EClass(m_operation_Class, OPERATION_ATTRIBUTE_POSTCONDITION);
	m_operation_Attribute_precondition = factory->createEReference_as_eReferences_in_EClass(m_operation_Class, OPERATION_ATTRIBUTE_PRECONDITION);
	m_operation_Attribute_redefinedOperation = factory->createEReference_as_eReferences_in_EClass(m_operation_Class, OPERATION_ATTRIBUTE_REDEFINEDOPERATION);
	m_operation_Attribute_type = factory->createEReference_as_eReferences_in_EClass(m_operation_Class, OPERATION_ATTRIBUTE_TYPE);
	
	m_operation_Operation_getLower = factory->createEOperation_as_eOperations_in_EClass(m_operation_Class, OPERATION_OPERATION_GETLOWER);
	m_operation_Operation_getReturnResult = factory->createEOperation_as_eOperations_in_EClass(m_operation_Class, OPERATION_OPERATION_GETRETURNRESULT);
	m_operation_Operation_getType = factory->createEOperation_as_eOperations_in_EClass(m_operation_Class, OPERATION_OPERATION_GETTYPE);
	m_operation_Operation_getUpper = factory->createEOperation_as_eOperations_in_EClass(m_operation_Class, OPERATION_OPERATION_GETUPPER);
	m_operation_Operation_isOrdered = factory->createEOperation_as_eOperations_in_EClass(m_operation_Class, OPERATION_OPERATION_ISORDERED);
	m_operation_Operation_isUnique = factory->createEOperation_as_eOperations_in_EClass(m_operation_Class, OPERATION_OPERATION_ISUNIQUE);
	m_operation_Operation_matches_Operation = factory->createEOperation_as_eOperations_in_EClass(m_operation_Class, OPERATION_OPERATION_MATCHES_OPERATION);
	m_operation_Operation_returnResult = factory->createEOperation_as_eOperations_in_EClass(m_operation_Class, OPERATION_OPERATION_RETURNRESULT);
	m_operation_Operation_setIsOrdered_Boolean = factory->createEOperation_as_eOperations_in_EClass(m_operation_Class, OPERATION_OPERATION_SETISORDERED_BOOLEAN);
	m_operation_Operation_setIsUnique_Boolean = factory->createEOperation_as_eOperations_in_EClass(m_operation_Class, OPERATION_OPERATION_SETISUNIQUE_BOOLEAN);
	m_operation_Operation_setLower_Integer = factory->createEOperation_as_eOperations_in_EClass(m_operation_Class, OPERATION_OPERATION_SETLOWER_INTEGER);
	m_operation_Operation_setType_Type = factory->createEOperation_as_eOperations_in_EClass(m_operation_Class, OPERATION_OPERATION_SETTYPE_TYPE);
	m_operation_Operation_setUpper_UnlimitedNatural = factory->createEOperation_as_eOperations_in_EClass(m_operation_Class, OPERATION_OPERATION_SETUPPER_UNLIMITEDNATURAL);
	
}

void umlPackageImpl::createOperationTemplateParameterContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_operationTemplateParameter_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, OPERATIONTEMPLATEPARAMETER_CLASS);
	
	
	
}

void umlPackageImpl::createOutputPinContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_outputPin_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, OUTPUTPIN_CLASS);
	
	m_outputPin_Attribute_action = factory->createEReference_as_eReferences_in_EClass(m_outputPin_Class, OUTPUTPIN_ATTRIBUTE_ACTION);
	m_outputPin_Attribute_callAction = factory->createEReference_as_eReferences_in_EClass(m_outputPin_Class, OUTPUTPIN_ATTRIBUTE_CALLACTION);
	m_outputPin_Attribute_clearStructuralFeatureAction = factory->createEReference_as_eReferences_in_EClass(m_outputPin_Class, OUTPUTPIN_ATTRIBUTE_CLEARSTRUCTURALFEATUREACTION);
	m_outputPin_Attribute_createObjectAction = factory->createEReference_as_eReferences_in_EClass(m_outputPin_Class, OUTPUTPIN_ATTRIBUTE_CREATEOBJECTACTION);
	m_outputPin_Attribute_readSelfAction = factory->createEReference_as_eReferences_in_EClass(m_outputPin_Class, OUTPUTPIN_ATTRIBUTE_READSELFACTION);
	m_outputPin_Attribute_readStructuralFeatureAction = factory->createEReference_as_eReferences_in_EClass(m_outputPin_Class, OUTPUTPIN_ATTRIBUTE_READSTRUCTURALFEATUREACTION);
	m_outputPin_Attribute_valueSpecificationAction = factory->createEReference_as_eReferences_in_EClass(m_outputPin_Class, OUTPUTPIN_ATTRIBUTE_VALUESPECIFICATIONACTION);
	m_outputPin_Attribute_writeStructuralFeatureAction = factory->createEReference_as_eReferences_in_EClass(m_outputPin_Class, OUTPUTPIN_ATTRIBUTE_WRITESTRUCTURALFEATUREACTION);
	
	
}

void umlPackageImpl::createPackageContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_package_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PACKAGE_CLASS);
	m_package_Attribute_uRI = factory->createEAttribute_as_eAttributes_in_EClass(m_package_Class, PACKAGE_ATTRIBUTE_URI);
	
	m_package_Attribute_nestedPackage = factory->createEReference_as_eReferences_in_EClass(m_package_Class, PACKAGE_ATTRIBUTE_NESTEDPACKAGE);
	m_package_Attribute_nestingPackage = factory->createEReference_as_eReferences_in_EClass(m_package_Class, PACKAGE_ATTRIBUTE_NESTINGPACKAGE);
	m_package_Attribute_ownedStereotype = factory->createEReference_as_eReferences_in_EClass(m_package_Class, PACKAGE_ATTRIBUTE_OWNEDSTEREOTYPE);
	m_package_Attribute_ownedType = factory->createEReference_as_eReferences_in_EClass(m_package_Class, PACKAGE_ATTRIBUTE_OWNEDTYPE);
	m_package_Attribute_packageMerge = factory->createEReference_as_eReferences_in_EClass(m_package_Class, PACKAGE_ATTRIBUTE_PACKAGEMERGE);
	m_package_Attribute_packagedElement = factory->createEReference_as_eReferences_in_EClass(m_package_Class, PACKAGE_ATTRIBUTE_PACKAGEDELEMENT);
	m_package_Attribute_profileApplication = factory->createEReference_as_eReferences_in_EClass(m_package_Class, PACKAGE_ATTRIBUTE_PROFILEAPPLICATION);
	
	m_package_Operation_allApplicableStereotypes = factory->createEOperation_as_eOperations_in_EClass(m_package_Class, PACKAGE_OPERATION_ALLAPPLICABLESTEREOTYPES);
	m_package_Operation_applyProfile_Profile = factory->createEOperation_as_eOperations_in_EClass(m_package_Class, PACKAGE_OPERATION_APPLYPROFILE_PROFILE);
	m_package_Operation_containingProfile = factory->createEOperation_as_eOperations_in_EClass(m_package_Class, PACKAGE_OPERATION_CONTAININGPROFILE);
	m_package_Operation_createOwnedClass_String_Boolean = factory->createEOperation_as_eOperations_in_EClass(m_package_Class, PACKAGE_OPERATION_CREATEOWNEDCLASS_STRING_BOOLEAN);
	m_package_Operation_createOwnedEnumeration_String = factory->createEOperation_as_eOperations_in_EClass(m_package_Class, PACKAGE_OPERATION_CREATEOWNEDENUMERATION_STRING);
	m_package_Operation_createOwnedInterface_String = factory->createEOperation_as_eOperations_in_EClass(m_package_Class, PACKAGE_OPERATION_CREATEOWNEDINTERFACE_STRING);
	m_package_Operation_createOwnedPrimitiveType_String = factory->createEOperation_as_eOperations_in_EClass(m_package_Class, PACKAGE_OPERATION_CREATEOWNEDPRIMITIVETYPE_STRING);
	m_package_Operation_createOwnedStereotype_String_Boolean = factory->createEOperation_as_eOperations_in_EClass(m_package_Class, PACKAGE_OPERATION_CREATEOWNEDSTEREOTYPE_STRING_BOOLEAN);
	m_package_Operation_getAllAppliedProfiles = factory->createEOperation_as_eOperations_in_EClass(m_package_Class, PACKAGE_OPERATION_GETALLAPPLIEDPROFILES);
	m_package_Operation_getAllProfileApplications = factory->createEOperation_as_eOperations_in_EClass(m_package_Class, PACKAGE_OPERATION_GETALLPROFILEAPPLICATIONS);
	m_package_Operation_getAppliedProfile_String = factory->createEOperation_as_eOperations_in_EClass(m_package_Class, PACKAGE_OPERATION_GETAPPLIEDPROFILE_STRING);
	m_package_Operation_getAppliedProfile_String_Boolean = factory->createEOperation_as_eOperations_in_EClass(m_package_Class, PACKAGE_OPERATION_GETAPPLIEDPROFILE_STRING_BOOLEAN);
	m_package_Operation_getAppliedProfiles = factory->createEOperation_as_eOperations_in_EClass(m_package_Class, PACKAGE_OPERATION_GETAPPLIEDPROFILES);
	m_package_Operation_getNestedPackages = factory->createEOperation_as_eOperations_in_EClass(m_package_Class, PACKAGE_OPERATION_GETNESTEDPACKAGES);
	m_package_Operation_getOwnedStereotypes = factory->createEOperation_as_eOperations_in_EClass(m_package_Class, PACKAGE_OPERATION_GETOWNEDSTEREOTYPES);
	m_package_Operation_getOwnedTypes = factory->createEOperation_as_eOperations_in_EClass(m_package_Class, PACKAGE_OPERATION_GETOWNEDTYPES);
	m_package_Operation_getProfileApplication_Profile = factory->createEOperation_as_eOperations_in_EClass(m_package_Class, PACKAGE_OPERATION_GETPROFILEAPPLICATION_PROFILE);
	m_package_Operation_getProfileApplication_Profile_Boolean = factory->createEOperation_as_eOperations_in_EClass(m_package_Class, PACKAGE_OPERATION_GETPROFILEAPPLICATION_PROFILE_BOOLEAN);
	m_package_Operation_isModelLibrary = factory->createEOperation_as_eOperations_in_EClass(m_package_Class, PACKAGE_OPERATION_ISMODELLIBRARY);
	m_package_Operation_isProfileApplied_Profile = factory->createEOperation_as_eOperations_in_EClass(m_package_Class, PACKAGE_OPERATION_ISPROFILEAPPLIED_PROFILE);
	m_package_Operation_makesVisible_NamedElement = factory->createEOperation_as_eOperations_in_EClass(m_package_Class, PACKAGE_OPERATION_MAKESVISIBLE_NAMEDELEMENT);
	m_package_Operation_unapplyProfile_Profile = factory->createEOperation_as_eOperations_in_EClass(m_package_Class, PACKAGE_OPERATION_UNAPPLYPROFILE_PROFILE);
	m_package_Operation_visibleMembers = factory->createEOperation_as_eOperations_in_EClass(m_package_Class, PACKAGE_OPERATION_VISIBLEMEMBERS);
	
}

void umlPackageImpl::createPackageImportContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_packageImport_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PACKAGEIMPORT_CLASS);
	m_packageImport_Attribute_visibility = factory->createEAttribute_as_eAttributes_in_EClass(m_packageImport_Class, PACKAGEIMPORT_ATTRIBUTE_VISIBILITY);
	
	m_packageImport_Attribute_importedPackage = factory->createEReference_as_eReferences_in_EClass(m_packageImport_Class, PACKAGEIMPORT_ATTRIBUTE_IMPORTEDPACKAGE);
	m_packageImport_Attribute_importingNamespace = factory->createEReference_as_eReferences_in_EClass(m_packageImport_Class, PACKAGEIMPORT_ATTRIBUTE_IMPORTINGNAMESPACE);
	
	
}

void umlPackageImpl::createPackageMergeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_packageMerge_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PACKAGEMERGE_CLASS);
	
	m_packageMerge_Attribute_mergedPackage = factory->createEReference_as_eReferences_in_EClass(m_packageMerge_Class, PACKAGEMERGE_ATTRIBUTE_MERGEDPACKAGE);
	m_packageMerge_Attribute_receivingPackage = factory->createEReference_as_eReferences_in_EClass(m_packageMerge_Class, PACKAGEMERGE_ATTRIBUTE_RECEIVINGPACKAGE);
	
	
}

void umlPackageImpl::createPackageableElementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_packageableElement_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PACKAGEABLEELEMENT_CLASS);
	
	m_packageableElement_Attribute_owningPackage = factory->createEReference_as_eReferences_in_EClass(m_packageableElement_Class, PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE);
	
	
}

void umlPackageImpl::createParameterContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_parameter_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PARAMETER_CLASS);
	m_parameter_Attribute_default = factory->createEAttribute_as_eAttributes_in_EClass(m_parameter_Class, PARAMETER_ATTRIBUTE_DEFAULT);
	m_parameter_Attribute_direction = factory->createEAttribute_as_eAttributes_in_EClass(m_parameter_Class, PARAMETER_ATTRIBUTE_DIRECTION);
	m_parameter_Attribute_effect = factory->createEAttribute_as_eAttributes_in_EClass(m_parameter_Class, PARAMETER_ATTRIBUTE_EFFECT);
	m_parameter_Attribute_isException = factory->createEAttribute_as_eAttributes_in_EClass(m_parameter_Class, PARAMETER_ATTRIBUTE_ISEXCEPTION);
	m_parameter_Attribute_isStream = factory->createEAttribute_as_eAttributes_in_EClass(m_parameter_Class, PARAMETER_ATTRIBUTE_ISSTREAM);
	
	m_parameter_Attribute_behavior = factory->createEReference_as_eReferences_in_EClass(m_parameter_Class, PARAMETER_ATTRIBUTE_BEHAVIOR);
	m_parameter_Attribute_defaultValue = factory->createEReference_as_eReferences_in_EClass(m_parameter_Class, PARAMETER_ATTRIBUTE_DEFAULTVALUE);
	m_parameter_Attribute_operation = factory->createEReference_as_eReferences_in_EClass(m_parameter_Class, PARAMETER_ATTRIBUTE_OPERATION);
	m_parameter_Attribute_parameterSet = factory->createEReference_as_eReferences_in_EClass(m_parameter_Class, PARAMETER_ATTRIBUTE_PARAMETERSET);
	
	m_parameter_Operation_isSetDefault = factory->createEOperation_as_eOperations_in_EClass(m_parameter_Class, PARAMETER_OPERATION_ISSETDEFAULT);
	m_parameter_Operation_setBooleanDefaultValue_Boolean = factory->createEOperation_as_eOperations_in_EClass(m_parameter_Class, PARAMETER_OPERATION_SETBOOLEANDEFAULTVALUE_BOOLEAN);
	m_parameter_Operation_setIntegerDefaultValue_Integer = factory->createEOperation_as_eOperations_in_EClass(m_parameter_Class, PARAMETER_OPERATION_SETINTEGERDEFAULTVALUE_INTEGER);
	m_parameter_Operation_setNullDefaultValue = factory->createEOperation_as_eOperations_in_EClass(m_parameter_Class, PARAMETER_OPERATION_SETNULLDEFAULTVALUE);
	m_parameter_Operation_setRealDefaultValue_Real = factory->createEOperation_as_eOperations_in_EClass(m_parameter_Class, PARAMETER_OPERATION_SETREALDEFAULTVALUE_REAL);
	m_parameter_Operation_setStringDefaultValue_String = factory->createEOperation_as_eOperations_in_EClass(m_parameter_Class, PARAMETER_OPERATION_SETSTRINGDEFAULTVALUE_STRING);
	m_parameter_Operation_setUnlimitedNaturalDefaultValue_UnlimitedNatural = factory->createEOperation_as_eOperations_in_EClass(m_parameter_Class, PARAMETER_OPERATION_SETUNLIMITEDNATURALDEFAULTVALUE_UNLIMITEDNATURAL);
	m_parameter_Operation_unsetDefault = factory->createEOperation_as_eOperations_in_EClass(m_parameter_Class, PARAMETER_OPERATION_UNSETDEFAULT);
	
}

void umlPackageImpl::createParameterSetContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_parameterSet_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PARAMETERSET_CLASS);
	
	m_parameterSet_Attribute_condition = factory->createEReference_as_eReferences_in_EClass(m_parameterSet_Class, PARAMETERSET_ATTRIBUTE_CONDITION);
	m_parameterSet_Attribute_parameter = factory->createEReference_as_eReferences_in_EClass(m_parameterSet_Class, PARAMETERSET_ATTRIBUTE_PARAMETER);
	
	
}

void umlPackageImpl::createParameterableElementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_parameterableElement_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PARAMETERABLEELEMENT_CLASS);
	
	m_parameterableElement_Attribute_owningTemplateParameter = factory->createEReference_as_eReferences_in_EClass(m_parameterableElement_Class, PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER);
	m_parameterableElement_Attribute_templateParameter = factory->createEReference_as_eReferences_in_EClass(m_parameterableElement_Class, PARAMETERABLEELEMENT_ATTRIBUTE_TEMPLATEPARAMETER);
	
	m_parameterableElement_Operation_isCompatibleWith_ParameterableElement = factory->createEOperation_as_eOperations_in_EClass(m_parameterableElement_Class, PARAMETERABLEELEMENT_OPERATION_ISCOMPATIBLEWITH_PARAMETERABLEELEMENT);
	m_parameterableElement_Operation_isTemplateParameter = factory->createEOperation_as_eOperations_in_EClass(m_parameterableElement_Class, PARAMETERABLEELEMENT_OPERATION_ISTEMPLATEPARAMETER);
	
}

void umlPackageImpl::createPartDecompositionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_partDecomposition_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PARTDECOMPOSITION_CLASS);
	
	
	
}

void umlPackageImpl::createPinContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_pin_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PIN_CLASS);
	m_pin_Attribute_isControl = factory->createEAttribute_as_eAttributes_in_EClass(m_pin_Class, PIN_ATTRIBUTE_ISCONTROL);
	
	
	
}

void umlPackageImpl::createPortContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_port_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PORT_CLASS);
	m_port_Attribute_isBehavior = factory->createEAttribute_as_eAttributes_in_EClass(m_port_Class, PORT_ATTRIBUTE_ISBEHAVIOR);
	m_port_Attribute_isConjugated = factory->createEAttribute_as_eAttributes_in_EClass(m_port_Class, PORT_ATTRIBUTE_ISCONJUGATED);
	m_port_Attribute_isService = factory->createEAttribute_as_eAttributes_in_EClass(m_port_Class, PORT_ATTRIBUTE_ISSERVICE);
	
	m_port_Attribute_protocol = factory->createEReference_as_eReferences_in_EClass(m_port_Class, PORT_ATTRIBUTE_PROTOCOL);
	m_port_Attribute_provided = factory->createEReference_as_eReferences_in_EClass(m_port_Class, PORT_ATTRIBUTE_PROVIDED);
	m_port_Attribute_redefinedPort = factory->createEReference_as_eReferences_in_EClass(m_port_Class, PORT_ATTRIBUTE_REDEFINEDPORT);
	m_port_Attribute_required = factory->createEReference_as_eReferences_in_EClass(m_port_Class, PORT_ATTRIBUTE_REQUIRED);
	
	m_port_Operation_basicProvided = factory->createEOperation_as_eOperations_in_EClass(m_port_Class, PORT_OPERATION_BASICPROVIDED);
	m_port_Operation_basicRequired = factory->createEOperation_as_eOperations_in_EClass(m_port_Class, PORT_OPERATION_BASICREQUIRED);
	m_port_Operation_getProvideds = factory->createEOperation_as_eOperations_in_EClass(m_port_Class, PORT_OPERATION_GETPROVIDEDS);
	m_port_Operation_getRequireds = factory->createEOperation_as_eOperations_in_EClass(m_port_Class, PORT_OPERATION_GETREQUIREDS);
	
}

void umlPackageImpl::createPrimitiveTypeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_primitiveType_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PRIMITIVETYPE_CLASS);
	
	
	
}

void umlPackageImpl::createProfileContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_profile_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PROFILE_CLASS);
	
	m_profile_Attribute_metaclassReference = factory->createEReference_as_eReferences_in_EClass(m_profile_Class, PROFILE_ATTRIBUTE_METACLASSREFERENCE);
	m_profile_Attribute_metamodelReference = factory->createEReference_as_eReferences_in_EClass(m_profile_Class, PROFILE_ATTRIBUTE_METAMODELREFERENCE);
	
	m_profile_Operation_create_Classifier = factory->createEOperation_as_eOperations_in_EClass(m_profile_Class, PROFILE_OPERATION_CREATE_CLASSIFIER);
	m_profile_Operation_define = factory->createEOperation_as_eOperations_in_EClass(m_profile_Class, PROFILE_OPERATION_DEFINE);
	m_profile_Operation_define_EMap_EMap = factory->createEOperation_as_eOperations_in_EClass(m_profile_Class, PROFILE_OPERATION_DEFINE_EMAP_EMAP);
	m_profile_Operation_getDefinition = factory->createEOperation_as_eOperations_in_EClass(m_profile_Class, PROFILE_OPERATION_GETDEFINITION);
	m_profile_Operation_getDefinition_NamedElement = factory->createEOperation_as_eOperations_in_EClass(m_profile_Class, PROFILE_OPERATION_GETDEFINITION_NAMEDELEMENT);
	m_profile_Operation_getOwnedExtensions_Boolean = factory->createEOperation_as_eOperations_in_EClass(m_profile_Class, PROFILE_OPERATION_GETOWNEDEXTENSIONS_BOOLEAN);
	m_profile_Operation_getReferencedMetaclasses = factory->createEOperation_as_eOperations_in_EClass(m_profile_Class, PROFILE_OPERATION_GETREFERENCEDMETACLASSES);
	m_profile_Operation_getReferencedMetamodels = factory->createEOperation_as_eOperations_in_EClass(m_profile_Class, PROFILE_OPERATION_GETREFERENCEDMETAMODELS);
	m_profile_Operation_isDefined = factory->createEOperation_as_eOperations_in_EClass(m_profile_Class, PROFILE_OPERATION_ISDEFINED);
	
}

void umlPackageImpl::createProfileApplicationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_profileApplication_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PROFILEAPPLICATION_CLASS);
	m_profileApplication_Attribute_isStrict = factory->createEAttribute_as_eAttributes_in_EClass(m_profileApplication_Class, PROFILEAPPLICATION_ATTRIBUTE_ISSTRICT);
	
	m_profileApplication_Attribute_appliedProfile = factory->createEReference_as_eReferences_in_EClass(m_profileApplication_Class, PROFILEAPPLICATION_ATTRIBUTE_APPLIEDPROFILE);
	m_profileApplication_Attribute_applyingPackage = factory->createEReference_as_eReferences_in_EClass(m_profileApplication_Class, PROFILEAPPLICATION_ATTRIBUTE_APPLYINGPACKAGE);
	
	m_profileApplication_Operation_getAppliedDefinition = factory->createEOperation_as_eOperations_in_EClass(m_profileApplication_Class, PROFILEAPPLICATION_OPERATION_GETAPPLIEDDEFINITION);
	m_profileApplication_Operation_getAppliedDefinition_NamedElement = factory->createEOperation_as_eOperations_in_EClass(m_profileApplication_Class, PROFILEAPPLICATION_OPERATION_GETAPPLIEDDEFINITION_NAMEDELEMENT);
	
}

void umlPackageImpl::createPropertyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_property_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PROPERTY_CLASS);
	m_property_Attribute_aggregation = factory->createEAttribute_as_eAttributes_in_EClass(m_property_Class, PROPERTY_ATTRIBUTE_AGGREGATION);
	m_property_Attribute_default = factory->createEAttribute_as_eAttributes_in_EClass(m_property_Class, PROPERTY_ATTRIBUTE_DEFAULT);
	m_property_Attribute_isComposite = factory->createEAttribute_as_eAttributes_in_EClass(m_property_Class, PROPERTY_ATTRIBUTE_ISCOMPOSITE);
	m_property_Attribute_isDerived = factory->createEAttribute_as_eAttributes_in_EClass(m_property_Class, PROPERTY_ATTRIBUTE_ISDERIVED);
	m_property_Attribute_isDerivedUnion = factory->createEAttribute_as_eAttributes_in_EClass(m_property_Class, PROPERTY_ATTRIBUTE_ISDERIVEDUNION);
	m_property_Attribute_isID = factory->createEAttribute_as_eAttributes_in_EClass(m_property_Class, PROPERTY_ATTRIBUTE_ISID);
	
	m_property_Attribute_association = factory->createEReference_as_eReferences_in_EClass(m_property_Class, PROPERTY_ATTRIBUTE_ASSOCIATION);
	m_property_Attribute_associationEnd = factory->createEReference_as_eReferences_in_EClass(m_property_Class, PROPERTY_ATTRIBUTE_ASSOCIATIONEND);
	m_property_Attribute_class = factory->createEReference_as_eReferences_in_EClass(m_property_Class, PROPERTY_ATTRIBUTE_CLASS);
	m_property_Attribute_datatype = factory->createEReference_as_eReferences_in_EClass(m_property_Class, PROPERTY_ATTRIBUTE_DATATYPE);
	m_property_Attribute_defaultValue = factory->createEReference_as_eReferences_in_EClass(m_property_Class, PROPERTY_ATTRIBUTE_DEFAULTVALUE);
	m_property_Attribute_interface = factory->createEReference_as_eReferences_in_EClass(m_property_Class, PROPERTY_ATTRIBUTE_INTERFACE);
	m_property_Attribute_opposite = factory->createEReference_as_eReferences_in_EClass(m_property_Class, PROPERTY_ATTRIBUTE_OPPOSITE);
	m_property_Attribute_owningAssociation = factory->createEReference_as_eReferences_in_EClass(m_property_Class, PROPERTY_ATTRIBUTE_OWNINGASSOCIATION);
	m_property_Attribute_qualifier = factory->createEReference_as_eReferences_in_EClass(m_property_Class, PROPERTY_ATTRIBUTE_QUALIFIER);
	m_property_Attribute_redefinedProperty = factory->createEReference_as_eReferences_in_EClass(m_property_Class, PROPERTY_ATTRIBUTE_REDEFINEDPROPERTY);
	m_property_Attribute_subsettedProperty = factory->createEReference_as_eReferences_in_EClass(m_property_Class, PROPERTY_ATTRIBUTE_SUBSETTEDPROPERTY);
	
	m_property_Operation_getOpposite = factory->createEOperation_as_eOperations_in_EClass(m_property_Class, PROPERTY_OPERATION_GETOPPOSITE);
	m_property_Operation_getOtherEnd = factory->createEOperation_as_eOperations_in_EClass(m_property_Class, PROPERTY_OPERATION_GETOTHEREND);
	m_property_Operation_isAttribute = factory->createEOperation_as_eOperations_in_EClass(m_property_Class, PROPERTY_OPERATION_ISATTRIBUTE);
	m_property_Operation_isComposite = factory->createEOperation_as_eOperations_in_EClass(m_property_Class, PROPERTY_OPERATION_ISCOMPOSITE);
	m_property_Operation_isNavigable = factory->createEOperation_as_eOperations_in_EClass(m_property_Class, PROPERTY_OPERATION_ISNAVIGABLE);
	m_property_Operation_isSetDefault = factory->createEOperation_as_eOperations_in_EClass(m_property_Class, PROPERTY_OPERATION_ISSETDEFAULT);
	m_property_Operation_setBooleanDefaultValue_Boolean = factory->createEOperation_as_eOperations_in_EClass(m_property_Class, PROPERTY_OPERATION_SETBOOLEANDEFAULTVALUE_BOOLEAN);
	m_property_Operation_setIntegerDefaultValue_Integer = factory->createEOperation_as_eOperations_in_EClass(m_property_Class, PROPERTY_OPERATION_SETINTEGERDEFAULTVALUE_INTEGER);
	m_property_Operation_setIsNavigable_Boolean = factory->createEOperation_as_eOperations_in_EClass(m_property_Class, PROPERTY_OPERATION_SETISNAVIGABLE_BOOLEAN);
	m_property_Operation_setNullDefaultValue = factory->createEOperation_as_eOperations_in_EClass(m_property_Class, PROPERTY_OPERATION_SETNULLDEFAULTVALUE);
	m_property_Operation_setRealDefaultValue_Real = factory->createEOperation_as_eOperations_in_EClass(m_property_Class, PROPERTY_OPERATION_SETREALDEFAULTVALUE_REAL);
	m_property_Operation_setStringDefaultValue_String = factory->createEOperation_as_eOperations_in_EClass(m_property_Class, PROPERTY_OPERATION_SETSTRINGDEFAULTVALUE_STRING);
	m_property_Operation_setUnlimitedNaturalDefaultValue_UnlimitedNatural = factory->createEOperation_as_eOperations_in_EClass(m_property_Class, PROPERTY_OPERATION_SETUNLIMITEDNATURALDEFAULTVALUE_UNLIMITEDNATURAL);
	m_property_Operation_subsettingContext = factory->createEOperation_as_eOperations_in_EClass(m_property_Class, PROPERTY_OPERATION_SUBSETTINGCONTEXT);
	m_property_Operation_unsetDefault = factory->createEOperation_as_eOperations_in_EClass(m_property_Class, PROPERTY_OPERATION_UNSETDEFAULT);
	
}

void umlPackageImpl::createProtocolConformanceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_protocolConformance_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PROTOCOLCONFORMANCE_CLASS);
	
	m_protocolConformance_Attribute_generalMachine = factory->createEReference_as_eReferences_in_EClass(m_protocolConformance_Class, PROTOCOLCONFORMANCE_ATTRIBUTE_GENERALMACHINE);
	m_protocolConformance_Attribute_specificMachine = factory->createEReference_as_eReferences_in_EClass(m_protocolConformance_Class, PROTOCOLCONFORMANCE_ATTRIBUTE_SPECIFICMACHINE);
	
	
}

void umlPackageImpl::createProtocolStateMachineContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_protocolStateMachine_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PROTOCOLSTATEMACHINE_CLASS);
	
	m_protocolStateMachine_Attribute_conformance = factory->createEReference_as_eReferences_in_EClass(m_protocolStateMachine_Class, PROTOCOLSTATEMACHINE_ATTRIBUTE_CONFORMANCE);
	
	
}

void umlPackageImpl::createProtocolTransitionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_protocolTransition_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PROTOCOLTRANSITION_CLASS);
	
	m_protocolTransition_Attribute_postCondition = factory->createEReference_as_eReferences_in_EClass(m_protocolTransition_Class, PROTOCOLTRANSITION_ATTRIBUTE_POSTCONDITION);
	m_protocolTransition_Attribute_preCondition = factory->createEReference_as_eReferences_in_EClass(m_protocolTransition_Class, PROTOCOLTRANSITION_ATTRIBUTE_PRECONDITION);
	m_protocolTransition_Attribute_referred = factory->createEReference_as_eReferences_in_EClass(m_protocolTransition_Class, PROTOCOLTRANSITION_ATTRIBUTE_REFERRED);
	
	m_protocolTransition_Operation_getReferreds = factory->createEOperation_as_eOperations_in_EClass(m_protocolTransition_Class, PROTOCOLTRANSITION_OPERATION_GETREFERREDS);
	
}

void umlPackageImpl::createPseudostateContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_pseudostate_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PSEUDOSTATE_CLASS);
	m_pseudostate_Attribute_kind = factory->createEAttribute_as_eAttributes_in_EClass(m_pseudostate_Class, PSEUDOSTATE_ATTRIBUTE_KIND);
	
	m_pseudostate_Attribute_state = factory->createEReference_as_eReferences_in_EClass(m_pseudostate_Class, PSEUDOSTATE_ATTRIBUTE_STATE);
	m_pseudostate_Attribute_stateMachine = factory->createEReference_as_eReferences_in_EClass(m_pseudostate_Class, PSEUDOSTATE_ATTRIBUTE_STATEMACHINE);
	
	
}

void umlPackageImpl::createQualifierValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_qualifierValue_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, QUALIFIERVALUE_CLASS);
	
	m_qualifierValue_Attribute_qualifier = factory->createEReference_as_eReferences_in_EClass(m_qualifierValue_Class, QUALIFIERVALUE_ATTRIBUTE_QUALIFIER);
	m_qualifierValue_Attribute_value = factory->createEReference_as_eReferences_in_EClass(m_qualifierValue_Class, QUALIFIERVALUE_ATTRIBUTE_VALUE);
	
	
}

void umlPackageImpl::createRaiseExceptionActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_raiseExceptionAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, RAISEEXCEPTIONACTION_CLASS);
	
	m_raiseExceptionAction_Attribute_exception = factory->createEReference_as_eReferences_in_EClass(m_raiseExceptionAction_Class, RAISEEXCEPTIONACTION_ATTRIBUTE_EXCEPTION);
	
	
}

void umlPackageImpl::createReadExtentActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_readExtentAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, READEXTENTACTION_CLASS);
	
	m_readExtentAction_Attribute_classifier = factory->createEReference_as_eReferences_in_EClass(m_readExtentAction_Class, READEXTENTACTION_ATTRIBUTE_CLASSIFIER);
	m_readExtentAction_Attribute_result = factory->createEReference_as_eReferences_in_EClass(m_readExtentAction_Class, READEXTENTACTION_ATTRIBUTE_RESULT);
	
	
}

void umlPackageImpl::createReadIsClassifiedObjectActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_readIsClassifiedObjectAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, READISCLASSIFIEDOBJECTACTION_CLASS);
	m_readIsClassifiedObjectAction_Attribute_isDirect = factory->createEAttribute_as_eAttributes_in_EClass(m_readIsClassifiedObjectAction_Class, READISCLASSIFIEDOBJECTACTION_ATTRIBUTE_ISDIRECT);
	
	m_readIsClassifiedObjectAction_Attribute_classifier = factory->createEReference_as_eReferences_in_EClass(m_readIsClassifiedObjectAction_Class, READISCLASSIFIEDOBJECTACTION_ATTRIBUTE_CLASSIFIER);
	m_readIsClassifiedObjectAction_Attribute_object = factory->createEReference_as_eReferences_in_EClass(m_readIsClassifiedObjectAction_Class, READISCLASSIFIEDOBJECTACTION_ATTRIBUTE_OBJECT);
	m_readIsClassifiedObjectAction_Attribute_result = factory->createEReference_as_eReferences_in_EClass(m_readIsClassifiedObjectAction_Class, READISCLASSIFIEDOBJECTACTION_ATTRIBUTE_RESULT);
	
	
}

void umlPackageImpl::createReadLinkActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_readLinkAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, READLINKACTION_CLASS);
	
	m_readLinkAction_Attribute_result = factory->createEReference_as_eReferences_in_EClass(m_readLinkAction_Class, READLINKACTION_ATTRIBUTE_RESULT);
	
	m_readLinkAction_Operation_openEnd = factory->createEOperation_as_eOperations_in_EClass(m_readLinkAction_Class, READLINKACTION_OPERATION_OPENEND);
	
}

void umlPackageImpl::createReadLinkObjectEndActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_readLinkObjectEndAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, READLINKOBJECTENDACTION_CLASS);
	
	m_readLinkObjectEndAction_Attribute_end = factory->createEReference_as_eReferences_in_EClass(m_readLinkObjectEndAction_Class, READLINKOBJECTENDACTION_ATTRIBUTE_END);
	m_readLinkObjectEndAction_Attribute_object = factory->createEReference_as_eReferences_in_EClass(m_readLinkObjectEndAction_Class, READLINKOBJECTENDACTION_ATTRIBUTE_OBJECT);
	m_readLinkObjectEndAction_Attribute_result = factory->createEReference_as_eReferences_in_EClass(m_readLinkObjectEndAction_Class, READLINKOBJECTENDACTION_ATTRIBUTE_RESULT);
	
	
}

void umlPackageImpl::createReadLinkObjectEndQualifierActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_readLinkObjectEndQualifierAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, READLINKOBJECTENDQUALIFIERACTION_CLASS);
	
	m_readLinkObjectEndQualifierAction_Attribute_object = factory->createEReference_as_eReferences_in_EClass(m_readLinkObjectEndQualifierAction_Class, READLINKOBJECTENDQUALIFIERACTION_ATTRIBUTE_OBJECT);
	m_readLinkObjectEndQualifierAction_Attribute_qualifier = factory->createEReference_as_eReferences_in_EClass(m_readLinkObjectEndQualifierAction_Class, READLINKOBJECTENDQUALIFIERACTION_ATTRIBUTE_QUALIFIER);
	m_readLinkObjectEndQualifierAction_Attribute_result = factory->createEReference_as_eReferences_in_EClass(m_readLinkObjectEndQualifierAction_Class, READLINKOBJECTENDQUALIFIERACTION_ATTRIBUTE_RESULT);
	
	
}

void umlPackageImpl::createReadSelfActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_readSelfAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, READSELFACTION_CLASS);
	
	m_readSelfAction_Attribute_result = factory->createEReference_as_eReferences_in_EClass(m_readSelfAction_Class, READSELFACTION_ATTRIBUTE_RESULT);
	
	
}

void umlPackageImpl::createReadStructuralFeatureActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_readStructuralFeatureAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, READSTRUCTURALFEATUREACTION_CLASS);
	
	m_readStructuralFeatureAction_Attribute_result = factory->createEReference_as_eReferences_in_EClass(m_readStructuralFeatureAction_Class, READSTRUCTURALFEATUREACTION_ATTRIBUTE_RESULT);
	
	
}

void umlPackageImpl::createReadVariableActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_readVariableAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, READVARIABLEACTION_CLASS);
	
	m_readVariableAction_Attribute_result = factory->createEReference_as_eReferences_in_EClass(m_readVariableAction_Class, READVARIABLEACTION_ATTRIBUTE_RESULT);
	
	
}

void umlPackageImpl::createRealizationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_realization_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, REALIZATION_CLASS);
	
	
	
}

void umlPackageImpl::createReceptionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_reception_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, RECEPTION_CLASS);
	
	m_reception_Attribute_signal = factory->createEReference_as_eReferences_in_EClass(m_reception_Class, RECEPTION_ATTRIBUTE_SIGNAL);
	
	
}

void umlPackageImpl::createReclassifyObjectActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_reclassifyObjectAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, RECLASSIFYOBJECTACTION_CLASS);
	m_reclassifyObjectAction_Attribute_isReplaceAll = factory->createEAttribute_as_eAttributes_in_EClass(m_reclassifyObjectAction_Class, RECLASSIFYOBJECTACTION_ATTRIBUTE_ISREPLACEALL);
	
	m_reclassifyObjectAction_Attribute_newClassifier = factory->createEReference_as_eReferences_in_EClass(m_reclassifyObjectAction_Class, RECLASSIFYOBJECTACTION_ATTRIBUTE_NEWCLASSIFIER);
	m_reclassifyObjectAction_Attribute_object = factory->createEReference_as_eReferences_in_EClass(m_reclassifyObjectAction_Class, RECLASSIFYOBJECTACTION_ATTRIBUTE_OBJECT);
	m_reclassifyObjectAction_Attribute_oldClassifier = factory->createEReference_as_eReferences_in_EClass(m_reclassifyObjectAction_Class, RECLASSIFYOBJECTACTION_ATTRIBUTE_OLDCLASSIFIER);
	
	
}

void umlPackageImpl::createRedefinableElementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_redefinableElement_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, REDEFINABLEELEMENT_CLASS);
	m_redefinableElement_Attribute_isLeaf = factory->createEAttribute_as_eAttributes_in_EClass(m_redefinableElement_Class, REDEFINABLEELEMENT_ATTRIBUTE_ISLEAF);
	
	m_redefinableElement_Attribute_redefinedElement = factory->createEReference_as_eReferences_in_EClass(m_redefinableElement_Class, REDEFINABLEELEMENT_ATTRIBUTE_REDEFINEDELEMENT);
	m_redefinableElement_Attribute_redefinitionContext = factory->createEReference_as_eReferences_in_EClass(m_redefinableElement_Class, REDEFINABLEELEMENT_ATTRIBUTE_REDEFINITIONCONTEXT);
	
	m_redefinableElement_Operation_isConsistentWith_RedefinableElement = factory->createEOperation_as_eOperations_in_EClass(m_redefinableElement_Class, REDEFINABLEELEMENT_OPERATION_ISCONSISTENTWITH_REDEFINABLEELEMENT);
	m_redefinableElement_Operation_isRedefinitionContextValid_RedefinableElement = factory->createEOperation_as_eOperations_in_EClass(m_redefinableElement_Class, REDEFINABLEELEMENT_OPERATION_ISREDEFINITIONCONTEXTVALID_REDEFINABLEELEMENT);
	
}

void umlPackageImpl::createRedefinableTemplateSignatureContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_redefinableTemplateSignature_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, REDEFINABLETEMPLATESIGNATURE_CLASS);
	
	m_redefinableTemplateSignature_Attribute_classifier = factory->createEReference_as_eReferences_in_EClass(m_redefinableTemplateSignature_Class, REDEFINABLETEMPLATESIGNATURE_ATTRIBUTE_CLASSIFIER);
	m_redefinableTemplateSignature_Attribute_extendedSignature = factory->createEReference_as_eReferences_in_EClass(m_redefinableTemplateSignature_Class, REDEFINABLETEMPLATESIGNATURE_ATTRIBUTE_EXTENDEDSIGNATURE);
	m_redefinableTemplateSignature_Attribute_inheritedParameter = factory->createEReference_as_eReferences_in_EClass(m_redefinableTemplateSignature_Class, REDEFINABLETEMPLATESIGNATURE_ATTRIBUTE_INHERITEDPARAMETER);
	
	m_redefinableTemplateSignature_Operation_getInheritedParameters = factory->createEOperation_as_eOperations_in_EClass(m_redefinableTemplateSignature_Class, REDEFINABLETEMPLATESIGNATURE_OPERATION_GETINHERITEDPARAMETERS);
	
}

void umlPackageImpl::createReduceActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_reduceAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, REDUCEACTION_CLASS);
	m_reduceAction_Attribute_isOrdered = factory->createEAttribute_as_eAttributes_in_EClass(m_reduceAction_Class, REDUCEACTION_ATTRIBUTE_ISORDERED);
	
	m_reduceAction_Attribute_collection = factory->createEReference_as_eReferences_in_EClass(m_reduceAction_Class, REDUCEACTION_ATTRIBUTE_COLLECTION);
	m_reduceAction_Attribute_reducer = factory->createEReference_as_eReferences_in_EClass(m_reduceAction_Class, REDUCEACTION_ATTRIBUTE_REDUCER);
	m_reduceAction_Attribute_result = factory->createEReference_as_eReferences_in_EClass(m_reduceAction_Class, REDUCEACTION_ATTRIBUTE_RESULT);
	
	
}

void umlPackageImpl::createRegionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_region_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, REGION_CLASS);
	
	m_region_Attribute_extendedRegion = factory->createEReference_as_eReferences_in_EClass(m_region_Class, REGION_ATTRIBUTE_EXTENDEDREGION);
	m_region_Attribute_state = factory->createEReference_as_eReferences_in_EClass(m_region_Class, REGION_ATTRIBUTE_STATE);
	m_region_Attribute_stateMachine = factory->createEReference_as_eReferences_in_EClass(m_region_Class, REGION_ATTRIBUTE_STATEMACHINE);
	m_region_Attribute_subvertex = factory->createEReference_as_eReferences_in_EClass(m_region_Class, REGION_ATTRIBUTE_SUBVERTEX);
	m_region_Attribute_transition = factory->createEReference_as_eReferences_in_EClass(m_region_Class, REGION_ATTRIBUTE_TRANSITION);
	
	m_region_Operation_belongsToPSM = factory->createEOperation_as_eOperations_in_EClass(m_region_Class, REGION_OPERATION_BELONGSTOPSM);
	m_region_Operation_containingStateMachine = factory->createEOperation_as_eOperations_in_EClass(m_region_Class, REGION_OPERATION_CONTAININGSTATEMACHINE);
	m_region_Operation_redefinitionContext = factory->createEOperation_as_eOperations_in_EClass(m_region_Class, REGION_OPERATION_REDEFINITIONCONTEXT);
	
}

void umlPackageImpl::createRelationshipContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_relationship_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, RELATIONSHIP_CLASS);
	
	m_relationship_Attribute_relatedElement = factory->createEReference_as_eReferences_in_EClass(m_relationship_Class, RELATIONSHIP_ATTRIBUTE_RELATEDELEMENT);
	
	
}

void umlPackageImpl::createRemoveStructuralFeatureValueActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_removeStructuralFeatureValueAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, REMOVESTRUCTURALFEATUREVALUEACTION_CLASS);
	m_removeStructuralFeatureValueAction_Attribute_isRemoveDuplicates = factory->createEAttribute_as_eAttributes_in_EClass(m_removeStructuralFeatureValueAction_Class, REMOVESTRUCTURALFEATUREVALUEACTION_ATTRIBUTE_ISREMOVEDUPLICATES);
	
	m_removeStructuralFeatureValueAction_Attribute_removeAt = factory->createEReference_as_eReferences_in_EClass(m_removeStructuralFeatureValueAction_Class, REMOVESTRUCTURALFEATUREVALUEACTION_ATTRIBUTE_REMOVEAT);
	
	
}

void umlPackageImpl::createRemoveVariableValueActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_removeVariableValueAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, REMOVEVARIABLEVALUEACTION_CLASS);
	m_removeVariableValueAction_Attribute_isRemoveDuplicates = factory->createEAttribute_as_eAttributes_in_EClass(m_removeVariableValueAction_Class, REMOVEVARIABLEVALUEACTION_ATTRIBUTE_ISREMOVEDUPLICATES);
	
	m_removeVariableValueAction_Attribute_removeAt = factory->createEReference_as_eReferences_in_EClass(m_removeVariableValueAction_Class, REMOVEVARIABLEVALUEACTION_ATTRIBUTE_REMOVEAT);
	
	
}

void umlPackageImpl::createReplyActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_replyAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, REPLYACTION_CLASS);
	
	m_replyAction_Attribute_replyToCall = factory->createEReference_as_eReferences_in_EClass(m_replyAction_Class, REPLYACTION_ATTRIBUTE_REPLYTOCALL);
	m_replyAction_Attribute_replyValue = factory->createEReference_as_eReferences_in_EClass(m_replyAction_Class, REPLYACTION_ATTRIBUTE_REPLYVALUE);
	m_replyAction_Attribute_returnInformation = factory->createEReference_as_eReferences_in_EClass(m_replyAction_Class, REPLYACTION_ATTRIBUTE_RETURNINFORMATION);
	
	
}

void umlPackageImpl::createSendObjectActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_sendObjectAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, SENDOBJECTACTION_CLASS);
	
	m_sendObjectAction_Attribute_request = factory->createEReference_as_eReferences_in_EClass(m_sendObjectAction_Class, SENDOBJECTACTION_ATTRIBUTE_REQUEST);
	m_sendObjectAction_Attribute_target = factory->createEReference_as_eReferences_in_EClass(m_sendObjectAction_Class, SENDOBJECTACTION_ATTRIBUTE_TARGET);
	
	
}

void umlPackageImpl::createSendSignalActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_sendSignalAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, SENDSIGNALACTION_CLASS);
	
	m_sendSignalAction_Attribute_signal = factory->createEReference_as_eReferences_in_EClass(m_sendSignalAction_Class, SENDSIGNALACTION_ATTRIBUTE_SIGNAL);
	m_sendSignalAction_Attribute_target = factory->createEReference_as_eReferences_in_EClass(m_sendSignalAction_Class, SENDSIGNALACTION_ATTRIBUTE_TARGET);
	
	
}

void umlPackageImpl::createSequenceNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_sequenceNode_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, SEQUENCENODE_CLASS);
	
	m_sequenceNode_Attribute_executableNode = factory->createEReference_as_eReferences_in_EClass(m_sequenceNode_Class, SEQUENCENODE_ATTRIBUTE_EXECUTABLENODE);
	
	
}

void umlPackageImpl::createSignalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_signal_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, SIGNAL_CLASS);
	
	m_signal_Attribute_ownedAttribute = factory->createEReference_as_eReferences_in_EClass(m_signal_Class, SIGNAL_ATTRIBUTE_OWNEDATTRIBUTE);
	
	m_signal_Operation_createOwnedAttribute_String_UnlimitedNatural = factory->createEOperation_as_eOperations_in_EClass(m_signal_Class, SIGNAL_OPERATION_CREATEOWNEDATTRIBUTE_STRING_UNLIMITEDNATURAL);
	
}

void umlPackageImpl::createSignalEventContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_signalEvent_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, SIGNALEVENT_CLASS);
	
	m_signalEvent_Attribute_signal = factory->createEReference_as_eReferences_in_EClass(m_signalEvent_Class, SIGNALEVENT_ATTRIBUTE_SIGNAL);
	
	
}

void umlPackageImpl::createSlotContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_slot_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, SLOT_CLASS);
	
	m_slot_Attribute_definingFeature = factory->createEReference_as_eReferences_in_EClass(m_slot_Class, SLOT_ATTRIBUTE_DEFININGFEATURE);
	m_slot_Attribute_owningInstance = factory->createEReference_as_eReferences_in_EClass(m_slot_Class, SLOT_ATTRIBUTE_OWNINGINSTANCE);
	m_slot_Attribute_value = factory->createEReference_as_eReferences_in_EClass(m_slot_Class, SLOT_ATTRIBUTE_VALUE);
	
	
}

void umlPackageImpl::createStartClassifierBehaviorActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_startClassifierBehaviorAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, STARTCLASSIFIERBEHAVIORACTION_CLASS);
	
	m_startClassifierBehaviorAction_Attribute_object = factory->createEReference_as_eReferences_in_EClass(m_startClassifierBehaviorAction_Class, STARTCLASSIFIERBEHAVIORACTION_ATTRIBUTE_OBJECT);
	
	
}

void umlPackageImpl::createStartObjectBehaviorActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_startObjectBehaviorAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, STARTOBJECTBEHAVIORACTION_CLASS);
	
	m_startObjectBehaviorAction_Attribute_object = factory->createEReference_as_eReferences_in_EClass(m_startObjectBehaviorAction_Class, STARTOBJECTBEHAVIORACTION_ATTRIBUTE_OBJECT);
	
	m_startObjectBehaviorAction_Operation_behavior = factory->createEOperation_as_eOperations_in_EClass(m_startObjectBehaviorAction_Class, STARTOBJECTBEHAVIORACTION_OPERATION_BEHAVIOR);
	
}

void umlPackageImpl::createStateContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_state_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, STATE_CLASS);
	
	m_state_Attribute_connection = factory->createEReference_as_eReferences_in_EClass(m_state_Class, STATE_ATTRIBUTE_CONNECTION);
	m_state_Attribute_connectionPoint = factory->createEReference_as_eReferences_in_EClass(m_state_Class, STATE_ATTRIBUTE_CONNECTIONPOINT);
	m_state_Attribute_deferrableTrigger = factory->createEReference_as_eReferences_in_EClass(m_state_Class, STATE_ATTRIBUTE_DEFERRABLETRIGGER);
	m_state_Attribute_doActivity = factory->createEReference_as_eReferences_in_EClass(m_state_Class, STATE_ATTRIBUTE_DOACTIVITY);
	m_state_Attribute_entry = factory->createEReference_as_eReferences_in_EClass(m_state_Class, STATE_ATTRIBUTE_ENTRY);
	m_state_Attribute_exit = factory->createEReference_as_eReferences_in_EClass(m_state_Class, STATE_ATTRIBUTE_EXIT);
	m_state_Attribute_redefinedState = factory->createEReference_as_eReferences_in_EClass(m_state_Class, STATE_ATTRIBUTE_REDEFINEDSTATE);
	m_state_Attribute_region = factory->createEReference_as_eReferences_in_EClass(m_state_Class, STATE_ATTRIBUTE_REGION);
	m_state_Attribute_stateInvariant = factory->createEReference_as_eReferences_in_EClass(m_state_Class, STATE_ATTRIBUTE_STATEINVARIANT);
	m_state_Attribute_submachine = factory->createEReference_as_eReferences_in_EClass(m_state_Class, STATE_ATTRIBUTE_SUBMACHINE);
	
	m_state_Operation_isComposite = factory->createEOperation_as_eOperations_in_EClass(m_state_Class, STATE_OPERATION_ISCOMPOSITE);
	m_state_Operation_isOrthogonal = factory->createEOperation_as_eOperations_in_EClass(m_state_Class, STATE_OPERATION_ISORTHOGONAL);
	m_state_Operation_isSimple = factory->createEOperation_as_eOperations_in_EClass(m_state_Class, STATE_OPERATION_ISSIMPLE);
	m_state_Operation_isSubmachineState = factory->createEOperation_as_eOperations_in_EClass(m_state_Class, STATE_OPERATION_ISSUBMACHINESTATE);
	m_state_Operation_redefinitionContext = factory->createEOperation_as_eOperations_in_EClass(m_state_Class, STATE_OPERATION_REDEFINITIONCONTEXT);
	
}

void umlPackageImpl::createStateInvariantContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_stateInvariant_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, STATEINVARIANT_CLASS);
	
	m_stateInvariant_Attribute_invariant = factory->createEReference_as_eReferences_in_EClass(m_stateInvariant_Class, STATEINVARIANT_ATTRIBUTE_INVARIANT);
	
	
}

void umlPackageImpl::createStateMachineContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_stateMachine_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, STATEMACHINE_CLASS);
	
	m_stateMachine_Attribute_connectionPoint = factory->createEReference_as_eReferences_in_EClass(m_stateMachine_Class, STATEMACHINE_ATTRIBUTE_CONNECTIONPOINT);
	m_stateMachine_Attribute_extendedStateMachine = factory->createEReference_as_eReferences_in_EClass(m_stateMachine_Class, STATEMACHINE_ATTRIBUTE_EXTENDEDSTATEMACHINE);
	m_stateMachine_Attribute_region = factory->createEReference_as_eReferences_in_EClass(m_stateMachine_Class, STATEMACHINE_ATTRIBUTE_REGION);
	m_stateMachine_Attribute_submachineState = factory->createEReference_as_eReferences_in_EClass(m_stateMachine_Class, STATEMACHINE_ATTRIBUTE_SUBMACHINESTATE);
	
	m_stateMachine_Operation_lCA_Vertex_Vertex = factory->createEOperation_as_eOperations_in_EClass(m_stateMachine_Class, STATEMACHINE_OPERATION_LCA_VERTEX_VERTEX);
	m_stateMachine_Operation_lCAState_Vertex_Vertex = factory->createEOperation_as_eOperations_in_EClass(m_stateMachine_Class, STATEMACHINE_OPERATION_LCASTATE_VERTEX_VERTEX);
	m_stateMachine_Operation_ancestor_Vertex_Vertex = factory->createEOperation_as_eOperations_in_EClass(m_stateMachine_Class, STATEMACHINE_OPERATION_ANCESTOR_VERTEX_VERTEX);
	
}

void umlPackageImpl::createStereotypeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_stereotype_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, STEREOTYPE_CLASS);
	
	m_stereotype_Attribute_icon = factory->createEReference_as_eReferences_in_EClass(m_stereotype_Class, STEREOTYPE_ATTRIBUTE_ICON);
	m_stereotype_Attribute_profile = factory->createEReference_as_eReferences_in_EClass(m_stereotype_Class, STEREOTYPE_ATTRIBUTE_PROFILE);
	
	m_stereotype_Operation_containingProfile = factory->createEOperation_as_eOperations_in_EClass(m_stereotype_Class, STEREOTYPE_OPERATION_CONTAININGPROFILE);
	m_stereotype_Operation_createExtension_Class_Boolean = factory->createEOperation_as_eOperations_in_EClass(m_stereotype_Class, STEREOTYPE_OPERATION_CREATEEXTENSION_CLASS_BOOLEAN);
	m_stereotype_Operation_createIcon_String = factory->createEOperation_as_eOperations_in_EClass(m_stereotype_Class, STEREOTYPE_OPERATION_CREATEICON_STRING);
	m_stereotype_Operation_createIcon_String_String = factory->createEOperation_as_eOperations_in_EClass(m_stereotype_Class, STEREOTYPE_OPERATION_CREATEICON_STRING_STRING);
	m_stereotype_Operation_getAllExtendedMetaclasses = factory->createEOperation_as_eOperations_in_EClass(m_stereotype_Class, STEREOTYPE_OPERATION_GETALLEXTENDEDMETACLASSES);
	m_stereotype_Operation_getDefinition = factory->createEOperation_as_eOperations_in_EClass(m_stereotype_Class, STEREOTYPE_OPERATION_GETDEFINITION);
	m_stereotype_Operation_getExtendedMetaclasses = factory->createEOperation_as_eOperations_in_EClass(m_stereotype_Class, STEREOTYPE_OPERATION_GETEXTENDEDMETACLASSES);
	m_stereotype_Operation_getKeyword = factory->createEOperation_as_eOperations_in_EClass(m_stereotype_Class, STEREOTYPE_OPERATION_GETKEYWORD);
	m_stereotype_Operation_getKeyword_Boolean = factory->createEOperation_as_eOperations_in_EClass(m_stereotype_Class, STEREOTYPE_OPERATION_GETKEYWORD_BOOLEAN);
	m_stereotype_Operation_getProfile = factory->createEOperation_as_eOperations_in_EClass(m_stereotype_Class, STEREOTYPE_OPERATION_GETPROFILE);
	
}

void umlPackageImpl::createStringExpressionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_stringExpression_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, STRINGEXPRESSION_CLASS);
	
	m_stringExpression_Attribute_owningExpression = factory->createEReference_as_eReferences_in_EClass(m_stringExpression_Class, STRINGEXPRESSION_ATTRIBUTE_OWNINGEXPRESSION);
	m_stringExpression_Attribute_subExpression = factory->createEReference_as_eReferences_in_EClass(m_stringExpression_Class, STRINGEXPRESSION_ATTRIBUTE_SUBEXPRESSION);
	
	
}

void umlPackageImpl::createStructuralFeatureContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_structuralFeature_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, STRUCTURALFEATURE_CLASS);
	m_structuralFeature_Attribute_isReadOnly = factory->createEAttribute_as_eAttributes_in_EClass(m_structuralFeature_Class, STRUCTURALFEATURE_ATTRIBUTE_ISREADONLY);
	
	
	
}

void umlPackageImpl::createStructuralFeatureActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_structuralFeatureAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, STRUCTURALFEATUREACTION_CLASS);
	
	m_structuralFeatureAction_Attribute_object = factory->createEReference_as_eReferences_in_EClass(m_structuralFeatureAction_Class, STRUCTURALFEATUREACTION_ATTRIBUTE_OBJECT);
	m_structuralFeatureAction_Attribute_structuralFeature = factory->createEReference_as_eReferences_in_EClass(m_structuralFeatureAction_Class, STRUCTURALFEATUREACTION_ATTRIBUTE_STRUCTURALFEATURE);
	
	
}

void umlPackageImpl::createStructuredActivityNodeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_structuredActivityNode_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, STRUCTUREDACTIVITYNODE_CLASS);
	m_structuredActivityNode_Attribute_mustIsolate = factory->createEAttribute_as_eAttributes_in_EClass(m_structuredActivityNode_Class, STRUCTUREDACTIVITYNODE_ATTRIBUTE_MUSTISOLATE);
	
	m_structuredActivityNode_Attribute_edge = factory->createEReference_as_eReferences_in_EClass(m_structuredActivityNode_Class, STRUCTUREDACTIVITYNODE_ATTRIBUTE_EDGE);
	m_structuredActivityNode_Attribute_node = factory->createEReference_as_eReferences_in_EClass(m_structuredActivityNode_Class, STRUCTUREDACTIVITYNODE_ATTRIBUTE_NODE);
	m_structuredActivityNode_Attribute_structuredNodeInput = factory->createEReference_as_eReferences_in_EClass(m_structuredActivityNode_Class, STRUCTUREDACTIVITYNODE_ATTRIBUTE_STRUCTUREDNODEINPUT);
	m_structuredActivityNode_Attribute_structuredNodeOutput = factory->createEReference_as_eReferences_in_EClass(m_structuredActivityNode_Class, STRUCTUREDACTIVITYNODE_ATTRIBUTE_STRUCTUREDNODEOUTPUT);
	m_structuredActivityNode_Attribute_variable = factory->createEReference_as_eReferences_in_EClass(m_structuredActivityNode_Class, STRUCTUREDACTIVITYNODE_ATTRIBUTE_VARIABLE);
	
	m_structuredActivityNode_Operation_sourceNodes = factory->createEOperation_as_eOperations_in_EClass(m_structuredActivityNode_Class, STRUCTUREDACTIVITYNODE_OPERATION_SOURCENODES);
	m_structuredActivityNode_Operation_targetNodes = factory->createEOperation_as_eOperations_in_EClass(m_structuredActivityNode_Class, STRUCTUREDACTIVITYNODE_OPERATION_TARGETNODES);
	
}

void umlPackageImpl::createStructuredClassifierContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_structuredClassifier_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, STRUCTUREDCLASSIFIER_CLASS);
	
	m_structuredClassifier_Attribute_ownedAttribute = factory->createEReference_as_eReferences_in_EClass(m_structuredClassifier_Class, STRUCTUREDCLASSIFIER_ATTRIBUTE_OWNEDATTRIBUTE);
	m_structuredClassifier_Attribute_ownedConnector = factory->createEReference_as_eReferences_in_EClass(m_structuredClassifier_Class, STRUCTUREDCLASSIFIER_ATTRIBUTE_OWNEDCONNECTOR);
	m_structuredClassifier_Attribute_part = factory->createEReference_as_eReferences_in_EClass(m_structuredClassifier_Class, STRUCTUREDCLASSIFIER_ATTRIBUTE_PART);
	m_structuredClassifier_Attribute_role = factory->createEReference_as_eReferences_in_EClass(m_structuredClassifier_Class, STRUCTUREDCLASSIFIER_ATTRIBUTE_ROLE);
	
	m_structuredClassifier_Operation_allRoles = factory->createEOperation_as_eOperations_in_EClass(m_structuredClassifier_Class, STRUCTUREDCLASSIFIER_OPERATION_ALLROLES);
	m_structuredClassifier_Operation_createOwnedAttribute_String_UnlimitedNatural = factory->createEOperation_as_eOperations_in_EClass(m_structuredClassifier_Class, STRUCTUREDCLASSIFIER_OPERATION_CREATEOWNEDATTRIBUTE_STRING_UNLIMITEDNATURAL);
	m_structuredClassifier_Operation_getParts = factory->createEOperation_as_eOperations_in_EClass(m_structuredClassifier_Class, STRUCTUREDCLASSIFIER_OPERATION_GETPARTS);
	
}

void umlPackageImpl::createSubstitutionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_substitution_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, SUBSTITUTION_CLASS);
	
	m_substitution_Attribute_contract = factory->createEReference_as_eReferences_in_EClass(m_substitution_Class, SUBSTITUTION_ATTRIBUTE_CONTRACT);
	m_substitution_Attribute_substitutingClassifier = factory->createEReference_as_eReferences_in_EClass(m_substitution_Class, SUBSTITUTION_ATTRIBUTE_SUBSTITUTINGCLASSIFIER);
	
	
}

void umlPackageImpl::createTemplateBindingContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_templateBinding_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, TEMPLATEBINDING_CLASS);
	
	m_templateBinding_Attribute_boundElement = factory->createEReference_as_eReferences_in_EClass(m_templateBinding_Class, TEMPLATEBINDING_ATTRIBUTE_BOUNDELEMENT);
	m_templateBinding_Attribute_parameterSubstitution = factory->createEReference_as_eReferences_in_EClass(m_templateBinding_Class, TEMPLATEBINDING_ATTRIBUTE_PARAMETERSUBSTITUTION);
	m_templateBinding_Attribute_signature = factory->createEReference_as_eReferences_in_EClass(m_templateBinding_Class, TEMPLATEBINDING_ATTRIBUTE_SIGNATURE);
	
	
}

void umlPackageImpl::createTemplateParameterContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_templateParameter_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, TEMPLATEPARAMETER_CLASS);
	
	m_templateParameter_Attribute_default = factory->createEReference_as_eReferences_in_EClass(m_templateParameter_Class, TEMPLATEPARAMETER_ATTRIBUTE_DEFAULT);
	m_templateParameter_Attribute_ownedDefault = factory->createEReference_as_eReferences_in_EClass(m_templateParameter_Class, TEMPLATEPARAMETER_ATTRIBUTE_OWNEDDEFAULT);
	m_templateParameter_Attribute_ownedParameteredElement = factory->createEReference_as_eReferences_in_EClass(m_templateParameter_Class, TEMPLATEPARAMETER_ATTRIBUTE_OWNEDPARAMETEREDELEMENT);
	m_templateParameter_Attribute_parameteredElement = factory->createEReference_as_eReferences_in_EClass(m_templateParameter_Class, TEMPLATEPARAMETER_ATTRIBUTE_PARAMETEREDELEMENT);
	m_templateParameter_Attribute_signature = factory->createEReference_as_eReferences_in_EClass(m_templateParameter_Class, TEMPLATEPARAMETER_ATTRIBUTE_SIGNATURE);
	
	
}

void umlPackageImpl::createTemplateParameterSubstitutionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_templateParameterSubstitution_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, TEMPLATEPARAMETERSUBSTITUTION_CLASS);
	
	m_templateParameterSubstitution_Attribute_actual = factory->createEReference_as_eReferences_in_EClass(m_templateParameterSubstitution_Class, TEMPLATEPARAMETERSUBSTITUTION_ATTRIBUTE_ACTUAL);
	m_templateParameterSubstitution_Attribute_formal = factory->createEReference_as_eReferences_in_EClass(m_templateParameterSubstitution_Class, TEMPLATEPARAMETERSUBSTITUTION_ATTRIBUTE_FORMAL);
	m_templateParameterSubstitution_Attribute_ownedActual = factory->createEReference_as_eReferences_in_EClass(m_templateParameterSubstitution_Class, TEMPLATEPARAMETERSUBSTITUTION_ATTRIBUTE_OWNEDACTUAL);
	m_templateParameterSubstitution_Attribute_templateBinding = factory->createEReference_as_eReferences_in_EClass(m_templateParameterSubstitution_Class, TEMPLATEPARAMETERSUBSTITUTION_ATTRIBUTE_TEMPLATEBINDING);
	
	
}

void umlPackageImpl::createTemplateSignatureContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_templateSignature_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, TEMPLATESIGNATURE_CLASS);
	
	m_templateSignature_Attribute_ownedParameter = factory->createEReference_as_eReferences_in_EClass(m_templateSignature_Class, TEMPLATESIGNATURE_ATTRIBUTE_OWNEDPARAMETER);
	m_templateSignature_Attribute_parameter = factory->createEReference_as_eReferences_in_EClass(m_templateSignature_Class, TEMPLATESIGNATURE_ATTRIBUTE_PARAMETER);
	m_templateSignature_Attribute_template = factory->createEReference_as_eReferences_in_EClass(m_templateSignature_Class, TEMPLATESIGNATURE_ATTRIBUTE_TEMPLATE);
	
	
}

void umlPackageImpl::createTemplateableElementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_templateableElement_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, TEMPLATEABLEELEMENT_CLASS);
	
	m_templateableElement_Attribute_ownedTemplateSignature = factory->createEReference_as_eReferences_in_EClass(m_templateableElement_Class, TEMPLATEABLEELEMENT_ATTRIBUTE_OWNEDTEMPLATESIGNATURE);
	m_templateableElement_Attribute_templateBinding = factory->createEReference_as_eReferences_in_EClass(m_templateableElement_Class, TEMPLATEABLEELEMENT_ATTRIBUTE_TEMPLATEBINDING);
	
	m_templateableElement_Operation_isTemplate = factory->createEOperation_as_eOperations_in_EClass(m_templateableElement_Class, TEMPLATEABLEELEMENT_OPERATION_ISTEMPLATE);
	m_templateableElement_Operation_parameterableElements = factory->createEOperation_as_eOperations_in_EClass(m_templateableElement_Class, TEMPLATEABLEELEMENT_OPERATION_PARAMETERABLEELEMENTS);
	
}

void umlPackageImpl::createTestIdentityActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_testIdentityAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, TESTIDENTITYACTION_CLASS);
	
	m_testIdentityAction_Attribute_first = factory->createEReference_as_eReferences_in_EClass(m_testIdentityAction_Class, TESTIDENTITYACTION_ATTRIBUTE_FIRST);
	m_testIdentityAction_Attribute_result = factory->createEReference_as_eReferences_in_EClass(m_testIdentityAction_Class, TESTIDENTITYACTION_ATTRIBUTE_RESULT);
	m_testIdentityAction_Attribute_second = factory->createEReference_as_eReferences_in_EClass(m_testIdentityAction_Class, TESTIDENTITYACTION_ATTRIBUTE_SECOND);
	
	
}

void umlPackageImpl::createTimeConstraintContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_timeConstraint_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, TIMECONSTRAINT_CLASS);
	m_timeConstraint_Attribute_firstEvent = factory->createEAttribute_as_eAttributes_in_EClass(m_timeConstraint_Class, TIMECONSTRAINT_ATTRIBUTE_FIRSTEVENT);
	
	
	
}

void umlPackageImpl::createTimeEventContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_timeEvent_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, TIMEEVENT_CLASS);
	m_timeEvent_Attribute_isRelative = factory->createEAttribute_as_eAttributes_in_EClass(m_timeEvent_Class, TIMEEVENT_ATTRIBUTE_ISRELATIVE);
	
	m_timeEvent_Attribute_when = factory->createEReference_as_eReferences_in_EClass(m_timeEvent_Class, TIMEEVENT_ATTRIBUTE_WHEN);
	
	
}

void umlPackageImpl::createTimeExpressionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_timeExpression_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, TIMEEXPRESSION_CLASS);
	
	m_timeExpression_Attribute_expr = factory->createEReference_as_eReferences_in_EClass(m_timeExpression_Class, TIMEEXPRESSION_ATTRIBUTE_EXPR);
	m_timeExpression_Attribute_observation = factory->createEReference_as_eReferences_in_EClass(m_timeExpression_Class, TIMEEXPRESSION_ATTRIBUTE_OBSERVATION);
	
	
}

void umlPackageImpl::createTimeIntervalContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_timeInterval_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, TIMEINTERVAL_CLASS);
	
	
	
}

void umlPackageImpl::createTimeObservationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_timeObservation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, TIMEOBSERVATION_CLASS);
	m_timeObservation_Attribute_firstEvent = factory->createEAttribute_as_eAttributes_in_EClass(m_timeObservation_Class, TIMEOBSERVATION_ATTRIBUTE_FIRSTEVENT);
	
	m_timeObservation_Attribute_event = factory->createEReference_as_eReferences_in_EClass(m_timeObservation_Class, TIMEOBSERVATION_ATTRIBUTE_EVENT);
	
	
}

void umlPackageImpl::createTransitionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_transition_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, TRANSITION_CLASS);
	m_transition_Attribute_kind = factory->createEAttribute_as_eAttributes_in_EClass(m_transition_Class, TRANSITION_ATTRIBUTE_KIND);
	
	m_transition_Attribute_container = factory->createEReference_as_eReferences_in_EClass(m_transition_Class, TRANSITION_ATTRIBUTE_CONTAINER);
	m_transition_Attribute_effect = factory->createEReference_as_eReferences_in_EClass(m_transition_Class, TRANSITION_ATTRIBUTE_EFFECT);
	m_transition_Attribute_guard = factory->createEReference_as_eReferences_in_EClass(m_transition_Class, TRANSITION_ATTRIBUTE_GUARD);
	m_transition_Attribute_redefinedTransition = factory->createEReference_as_eReferences_in_EClass(m_transition_Class, TRANSITION_ATTRIBUTE_REDEFINEDTRANSITION);
	m_transition_Attribute_source = factory->createEReference_as_eReferences_in_EClass(m_transition_Class, TRANSITION_ATTRIBUTE_SOURCE);
	m_transition_Attribute_target = factory->createEReference_as_eReferences_in_EClass(m_transition_Class, TRANSITION_ATTRIBUTE_TARGET);
	m_transition_Attribute_trigger = factory->createEReference_as_eReferences_in_EClass(m_transition_Class, TRANSITION_ATTRIBUTE_TRIGGER);
	
	m_transition_Operation_containingStateMachine = factory->createEOperation_as_eOperations_in_EClass(m_transition_Class, TRANSITION_OPERATION_CONTAININGSTATEMACHINE);
	m_transition_Operation_redefinitionContext = factory->createEOperation_as_eOperations_in_EClass(m_transition_Class, TRANSITION_OPERATION_REDEFINITIONCONTEXT);
	
}

void umlPackageImpl::createTriggerContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_trigger_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, TRIGGER_CLASS);
	
	m_trigger_Attribute_event = factory->createEReference_as_eReferences_in_EClass(m_trigger_Class, TRIGGER_ATTRIBUTE_EVENT);
	m_trigger_Attribute_port = factory->createEReference_as_eReferences_in_EClass(m_trigger_Class, TRIGGER_ATTRIBUTE_PORT);
	
	
}

void umlPackageImpl::createTypeContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_type_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, TYPE_CLASS);
	
	m_type_Attribute_package = factory->createEReference_as_eReferences_in_EClass(m_type_Class, TYPE_ATTRIBUTE_PACKAGE);
	
	m_type_Operation_conformsTo_Type = factory->createEOperation_as_eOperations_in_EClass(m_type_Class, TYPE_OPERATION_CONFORMSTO_TYPE);
	m_type_Operation_createAssociation_Boolean_UnlimitedNatural = factory->createEOperation_as_eOperations_in_EClass(m_type_Class, TYPE_OPERATION_CREATEASSOCIATION_BOOLEAN_UNLIMITEDNATURAL);
	m_type_Operation_getAssociations = factory->createEOperation_as_eOperations_in_EClass(m_type_Class, TYPE_OPERATION_GETASSOCIATIONS);
	
}

void umlPackageImpl::createTypedElementContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_typedElement_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, TYPEDELEMENT_CLASS);
	
	m_typedElement_Attribute_type = factory->createEReference_as_eReferences_in_EClass(m_typedElement_Class, TYPEDELEMENT_ATTRIBUTE_TYPE);
	
	
}

void umlPackageImpl::createUnmarshallActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_unmarshallAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, UNMARSHALLACTION_CLASS);
	
	m_unmarshallAction_Attribute_object = factory->createEReference_as_eReferences_in_EClass(m_unmarshallAction_Class, UNMARSHALLACTION_ATTRIBUTE_OBJECT);
	m_unmarshallAction_Attribute_result = factory->createEReference_as_eReferences_in_EClass(m_unmarshallAction_Class, UNMARSHALLACTION_ATTRIBUTE_RESULT);
	m_unmarshallAction_Attribute_unmarshallType = factory->createEReference_as_eReferences_in_EClass(m_unmarshallAction_Class, UNMARSHALLACTION_ATTRIBUTE_UNMARSHALLTYPE);
	
	
}

void umlPackageImpl::createUsageContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_usage_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, USAGE_CLASS);
	
	
	
}

void umlPackageImpl::createUseCaseContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_useCase_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, USECASE_CLASS);
	
	m_useCase_Attribute_extend = factory->createEReference_as_eReferences_in_EClass(m_useCase_Class, USECASE_ATTRIBUTE_EXTEND);
	m_useCase_Attribute_extensionPoint = factory->createEReference_as_eReferences_in_EClass(m_useCase_Class, USECASE_ATTRIBUTE_EXTENSIONPOINT);
	m_useCase_Attribute_include = factory->createEReference_as_eReferences_in_EClass(m_useCase_Class, USECASE_ATTRIBUTE_INCLUDE);
	m_useCase_Attribute_subject = factory->createEReference_as_eReferences_in_EClass(m_useCase_Class, USECASE_ATTRIBUTE_SUBJECT);
	
	m_useCase_Operation_allIncludedUseCases = factory->createEOperation_as_eOperations_in_EClass(m_useCase_Class, USECASE_OPERATION_ALLINCLUDEDUSECASES);
	
}

void umlPackageImpl::createValuePinContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_valuePin_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, VALUEPIN_CLASS);
	
	m_valuePin_Attribute_value = factory->createEReference_as_eReferences_in_EClass(m_valuePin_Class, VALUEPIN_ATTRIBUTE_VALUE);
	
	
}

void umlPackageImpl::createValueSpecificationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_valueSpecification_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, VALUESPECIFICATION_CLASS);
	
	m_valueSpecification_Attribute_owningSlot = factory->createEReference_as_eReferences_in_EClass(m_valueSpecification_Class, VALUESPECIFICATION_ATTRIBUTE_OWNINGSLOT);
	m_valueSpecification_Attribute_valueSpecificationAction = factory->createEReference_as_eReferences_in_EClass(m_valueSpecification_Class, VALUESPECIFICATION_ATTRIBUTE_VALUESPECIFICATIONACTION);
	
	m_valueSpecification_Operation_booleanValue = factory->createEOperation_as_eOperations_in_EClass(m_valueSpecification_Class, VALUESPECIFICATION_OPERATION_BOOLEANVALUE);
	m_valueSpecification_Operation_integerValue = factory->createEOperation_as_eOperations_in_EClass(m_valueSpecification_Class, VALUESPECIFICATION_OPERATION_INTEGERVALUE);
	m_valueSpecification_Operation_isComputable = factory->createEOperation_as_eOperations_in_EClass(m_valueSpecification_Class, VALUESPECIFICATION_OPERATION_ISCOMPUTABLE);
	m_valueSpecification_Operation_isNull = factory->createEOperation_as_eOperations_in_EClass(m_valueSpecification_Class, VALUESPECIFICATION_OPERATION_ISNULL);
	m_valueSpecification_Operation_realValue = factory->createEOperation_as_eOperations_in_EClass(m_valueSpecification_Class, VALUESPECIFICATION_OPERATION_REALVALUE);
	m_valueSpecification_Operation_stringValue = factory->createEOperation_as_eOperations_in_EClass(m_valueSpecification_Class, VALUESPECIFICATION_OPERATION_STRINGVALUE);
	m_valueSpecification_Operation_unlimitedValue = factory->createEOperation_as_eOperations_in_EClass(m_valueSpecification_Class, VALUESPECIFICATION_OPERATION_UNLIMITEDVALUE);
	
}

void umlPackageImpl::createValueSpecificationActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_valueSpecificationAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, VALUESPECIFICATIONACTION_CLASS);
	
	m_valueSpecificationAction_Attribute_result = factory->createEReference_as_eReferences_in_EClass(m_valueSpecificationAction_Class, VALUESPECIFICATIONACTION_ATTRIBUTE_RESULT);
	m_valueSpecificationAction_Attribute_value = factory->createEReference_as_eReferences_in_EClass(m_valueSpecificationAction_Class, VALUESPECIFICATIONACTION_ATTRIBUTE_VALUE);
	
	
}

void umlPackageImpl::createVariableContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_variable_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, VARIABLE_CLASS);
	
	m_variable_Attribute_activityScope = factory->createEReference_as_eReferences_in_EClass(m_variable_Class, VARIABLE_ATTRIBUTE_ACTIVITYSCOPE);
	m_variable_Attribute_scope = factory->createEReference_as_eReferences_in_EClass(m_variable_Class, VARIABLE_ATTRIBUTE_SCOPE);
	
	m_variable_Operation_isAccessibleBy_Action = factory->createEOperation_as_eOperations_in_EClass(m_variable_Class, VARIABLE_OPERATION_ISACCESSIBLEBY_ACTION);
	
}

void umlPackageImpl::createVariableActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_variableAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, VARIABLEACTION_CLASS);
	
	m_variableAction_Attribute_variable = factory->createEReference_as_eReferences_in_EClass(m_variableAction_Class, VARIABLEACTION_ATTRIBUTE_VARIABLE);
	
	
}

void umlPackageImpl::createVertexContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_vertex_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, VERTEX_CLASS);
	
	m_vertex_Attribute_container = factory->createEReference_as_eReferences_in_EClass(m_vertex_Class, VERTEX_ATTRIBUTE_CONTAINER);
	m_vertex_Attribute_incoming = factory->createEReference_as_eReferences_in_EClass(m_vertex_Class, VERTEX_ATTRIBUTE_INCOMING);
	m_vertex_Attribute_outgoing = factory->createEReference_as_eReferences_in_EClass(m_vertex_Class, VERTEX_ATTRIBUTE_OUTGOING);
	
	m_vertex_Operation_containingStateMachine = factory->createEOperation_as_eOperations_in_EClass(m_vertex_Class, VERTEX_OPERATION_CONTAININGSTATEMACHINE);
	m_vertex_Operation_getIncomings = factory->createEOperation_as_eOperations_in_EClass(m_vertex_Class, VERTEX_OPERATION_GETINCOMINGS);
	m_vertex_Operation_getOutgoings = factory->createEOperation_as_eOperations_in_EClass(m_vertex_Class, VERTEX_OPERATION_GETOUTGOINGS);
	m_vertex_Operation_isContainedInRegion_Region = factory->createEOperation_as_eOperations_in_EClass(m_vertex_Class, VERTEX_OPERATION_ISCONTAINEDINREGION_REGION);
	m_vertex_Operation_isContainedInState_State = factory->createEOperation_as_eOperations_in_EClass(m_vertex_Class, VERTEX_OPERATION_ISCONTAINEDINSTATE_STATE);
	
}

void umlPackageImpl::createWriteLinkActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_writeLinkAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, WRITELINKACTION_CLASS);
	
	
	
}

void umlPackageImpl::createWriteStructuralFeatureActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_writeStructuralFeatureAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, WRITESTRUCTURALFEATUREACTION_CLASS);
	
	m_writeStructuralFeatureAction_Attribute_result = factory->createEReference_as_eReferences_in_EClass(m_writeStructuralFeatureAction_Class, WRITESTRUCTURALFEATUREACTION_ATTRIBUTE_RESULT);
	m_writeStructuralFeatureAction_Attribute_value = factory->createEReference_as_eReferences_in_EClass(m_writeStructuralFeatureAction_Class, WRITESTRUCTURALFEATUREACTION_ATTRIBUTE_VALUE);
	
	
}

void umlPackageImpl::createWriteVariableActionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_writeVariableAction_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, WRITEVARIABLEACTION_CLASS);
	
	m_writeVariableAction_Attribute_value = factory->createEReference_as_eReferences_in_EClass(m_writeVariableAction_Class, WRITEVARIABLEACTION_ATTRIBUTE_VALUE);
	
	
}

void umlPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_aggregationKind_Class = factory->createEEnum_as_eClassifiers_in_EPackage(package, AGGREGATIONKIND_CLASS);
	m_callConcurrencyKind_Class = factory->createEEnum_as_eClassifiers_in_EPackage(package, CALLCONCURRENCYKIND_CLASS);
	m_connectorKind_Class = factory->createEEnum_as_eClassifiers_in_EPackage(package, CONNECTORKIND_CLASS);
	m_expansionKind_Class = factory->createEEnum_as_eClassifiers_in_EPackage(package, EXPANSIONKIND_CLASS);
	m_interactionOperatorKind_Class = factory->createEEnum_as_eClassifiers_in_EPackage(package, INTERACTIONOPERATORKIND_CLASS);
	m_messageKind_Class = factory->createEEnum_as_eClassifiers_in_EPackage(package, MESSAGEKIND_CLASS);
	m_messageSort_Class = factory->createEEnum_as_eClassifiers_in_EPackage(package, MESSAGESORT_CLASS);
	m_objectNodeOrderingKind_Class = factory->createEEnum_as_eClassifiers_in_EPackage(package, OBJECTNODEORDERINGKIND_CLASS);
	m_parameterDirectionKind_Class = factory->createEEnum_as_eClassifiers_in_EPackage(package, PARAMETERDIRECTIONKIND_CLASS);
	m_parameterEffectKind_Class = factory->createEEnum_as_eClassifiers_in_EPackage(package, PARAMETEREFFECTKIND_CLASS);
	m_pseudostateKind_Class = factory->createEEnum_as_eClassifiers_in_EPackage(package, PSEUDOSTATEKIND_CLASS);
	m_transitionKind_Class = factory->createEEnum_as_eClassifiers_in_EPackage(package, TRANSITIONKIND_CLASS);
	m_visibilityKind_Class = factory->createEEnum_as_eClassifiers_in_EPackage(package, VISIBILITYKIND_CLASS);
	
}
