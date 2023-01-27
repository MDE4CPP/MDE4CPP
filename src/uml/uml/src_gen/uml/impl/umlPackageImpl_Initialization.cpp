#include "uml/impl/umlPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EAttribute.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EEnumLiteral.hpp"
#include "ecore/EEnum.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAnnotation.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

//depending model packages

#include "ecore/ecorePackage.hpp"
#include "types/typesPackage.hpp"


using namespace uml;

void umlPackageImpl::initializePackageContents()
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
	m_abstraction_Class->getESuperTypes()->push_back(getDependency_Class());
	m_acceptCallAction_Class->getESuperTypes()->push_back(getAcceptEventAction_Class());
	m_acceptEventAction_Class->getESuperTypes()->push_back(getAction_Class());
	m_action_Class->getESuperTypes()->push_back(getExecutableNode_Class());
	m_actionExecutionSpecification_Class->getESuperTypes()->push_back(getExecutionSpecification_Class());
	m_actionInputPin_Class->getESuperTypes()->push_back(getInputPin_Class());
	m_activity_Class->getESuperTypes()->push_back(getBehavior_Class());
	m_activityEdge_Class->getESuperTypes()->push_back(getRedefinableElement_Class());
	m_activityFinalNode_Class->getESuperTypes()->push_back(getFinalNode_Class());
	m_activityGroup_Class->getESuperTypes()->push_back(getNamedElement_Class());
	m_activityNode_Class->getESuperTypes()->push_back(getRedefinableElement_Class());
	m_activityParameterNode_Class->getESuperTypes()->push_back(getObjectNode_Class());
	m_activityPartition_Class->getESuperTypes()->push_back(getActivityGroup_Class());
	m_actor_Class->getESuperTypes()->push_back(getBehavioredClassifier_Class());
	m_addStructuralFeatureValueAction_Class->getESuperTypes()->push_back(getWriteStructuralFeatureAction_Class());
	m_addVariableValueAction_Class->getESuperTypes()->push_back(getWriteVariableAction_Class());
	m_anyReceiveEvent_Class->getESuperTypes()->push_back(getMessageEvent_Class());
	m_artifact_Class->getESuperTypes()->push_back(getClassifier_Class());
	m_artifact_Class->getESuperTypes()->push_back(getDeployedArtifact_Class());
	m_association_Class->getESuperTypes()->push_back(getClassifier_Class());
	m_association_Class->getESuperTypes()->push_back(getRelationship_Class());
	m_associationClass_Class->getESuperTypes()->push_back(getAssociation_Class());
	m_associationClass_Class->getESuperTypes()->push_back(getClass_Class());
	m_behavior_Class->getESuperTypes()->push_back(getClass_Class());
	m_behaviorExecutionSpecification_Class->getESuperTypes()->push_back(getExecutionSpecification_Class());
	m_behavioralFeature_Class->getESuperTypes()->push_back(getFeature_Class());
	m_behavioralFeature_Class->getESuperTypes()->push_back(getNamespace_Class());
	m_behavioredClassifier_Class->getESuperTypes()->push_back(getClassifier_Class());
	m_broadcastSignalAction_Class->getESuperTypes()->push_back(getInvocationAction_Class());
	m_callAction_Class->getESuperTypes()->push_back(getInvocationAction_Class());
	m_callBehaviorAction_Class->getESuperTypes()->push_back(getCallAction_Class());
	m_callEvent_Class->getESuperTypes()->push_back(getMessageEvent_Class());
	m_callOperationAction_Class->getESuperTypes()->push_back(getCallAction_Class());
	m_centralBufferNode_Class->getESuperTypes()->push_back(getObjectNode_Class());
	m_changeEvent_Class->getESuperTypes()->push_back(getEvent_Class());
	m_class_Class->getESuperTypes()->push_back(getBehavioredClassifier_Class());
	m_class_Class->getESuperTypes()->push_back(getEncapsulatedClassifier_Class());
	m_classifier_Class->getESuperTypes()->push_back(getNamespace_Class());
	m_classifier_Class->getESuperTypes()->push_back(getRedefinableElement_Class());
	m_classifier_Class->getESuperTypes()->push_back(getTemplateableElement_Class());
	m_classifier_Class->getESuperTypes()->push_back(getType_Class());
	m_classifierTemplateParameter_Class->getESuperTypes()->push_back(getTemplateParameter_Class());
	m_clause_Class->getESuperTypes()->push_back(getElement_Class());
	m_clearAssociationAction_Class->getESuperTypes()->push_back(getAction_Class());
	m_clearStructuralFeatureAction_Class->getESuperTypes()->push_back(getStructuralFeatureAction_Class());
	m_clearVariableAction_Class->getESuperTypes()->push_back(getVariableAction_Class());
	m_collaboration_Class->getESuperTypes()->push_back(getBehavioredClassifier_Class());
	m_collaboration_Class->getESuperTypes()->push_back(getStructuredClassifier_Class());
	m_collaborationUse_Class->getESuperTypes()->push_back(getNamedElement_Class());
	m_combinedFragment_Class->getESuperTypes()->push_back(getInteractionFragment_Class());
	m_comment_Class->getESuperTypes()->push_back(getElement_Class());
	m_communicationPath_Class->getESuperTypes()->push_back(getAssociation_Class());
	m_component_Class->getESuperTypes()->push_back(getClass_Class());
	m_componentRealization_Class->getESuperTypes()->push_back(getRealization_Class());
	m_conditionalNode_Class->getESuperTypes()->push_back(getStructuredActivityNode_Class());
	m_connectableElement_Class->getESuperTypes()->push_back(getParameterableElement_Class());
	m_connectableElement_Class->getESuperTypes()->push_back(getTypedElement_Class());
	m_connectableElementTemplateParameter_Class->getESuperTypes()->push_back(getTemplateParameter_Class());
	m_connectionPointReference_Class->getESuperTypes()->push_back(getVertex_Class());
	m_connector_Class->getESuperTypes()->push_back(getFeature_Class());
	m_connectorEnd_Class->getESuperTypes()->push_back(getMultiplicityElement_Class());
	m_considerIgnoreFragment_Class->getESuperTypes()->push_back(getCombinedFragment_Class());
	m_constraint_Class->getESuperTypes()->push_back(getPackageableElement_Class());
	m_continuation_Class->getESuperTypes()->push_back(getInteractionFragment_Class());
	m_controlFlow_Class->getESuperTypes()->push_back(getActivityEdge_Class());
	m_controlNode_Class->getESuperTypes()->push_back(getActivityNode_Class());
	m_createLinkAction_Class->getESuperTypes()->push_back(getWriteLinkAction_Class());
	m_createLinkObjectAction_Class->getESuperTypes()->push_back(getCreateLinkAction_Class());
	m_createObjectAction_Class->getESuperTypes()->push_back(getAction_Class());
	m_dataStoreNode_Class->getESuperTypes()->push_back(getCentralBufferNode_Class());
	m_dataType_Class->getESuperTypes()->push_back(getClassifier_Class());
	m_decisionNode_Class->getESuperTypes()->push_back(getControlNode_Class());
	m_dependency_Class->getESuperTypes()->push_back(getDirectedRelationship_Class());
	m_dependency_Class->getESuperTypes()->push_back(getPackageableElement_Class());
	m_deployedArtifact_Class->getESuperTypes()->push_back(getNamedElement_Class());
	m_deployment_Class->getESuperTypes()->push_back(getDependency_Class());
	m_deploymentSpecification_Class->getESuperTypes()->push_back(getArtifact_Class());
	m_deploymentTarget_Class->getESuperTypes()->push_back(getNamedElement_Class());
	m_destroyLinkAction_Class->getESuperTypes()->push_back(getWriteLinkAction_Class());
	m_destroyObjectAction_Class->getESuperTypes()->push_back(getAction_Class());
	m_destructionOccurrenceSpecification_Class->getESuperTypes()->push_back(getMessageOccurrenceSpecification_Class());
	m_device_Class->getESuperTypes()->push_back(getNode_Class());
	m_directedRelationship_Class->getESuperTypes()->push_back(getRelationship_Class());
	m_duration_Class->getESuperTypes()->push_back(getValueSpecification_Class());
	m_durationConstraint_Class->getESuperTypes()->push_back(getIntervalConstraint_Class());
	m_durationInterval_Class->getESuperTypes()->push_back(getInterval_Class());
	m_durationObservation_Class->getESuperTypes()->push_back(getObservation_Class());
	m_element_Class->getESuperTypes()->push_back(getObject_Class());
	m_elementImport_Class->getESuperTypes()->push_back(getDirectedRelationship_Class());
	m_encapsulatedClassifier_Class->getESuperTypes()->push_back(getStructuredClassifier_Class());
	m_enumeration_Class->getESuperTypes()->push_back(getDataType_Class());
	m_enumerationLiteral_Class->getESuperTypes()->push_back(getInstanceSpecification_Class());
	m_event_Class->getESuperTypes()->push_back(getPackageableElement_Class());
	m_exceptionHandler_Class->getESuperTypes()->push_back(getElement_Class());
	m_executableNode_Class->getESuperTypes()->push_back(getActivityNode_Class());
	m_executionEnvironment_Class->getESuperTypes()->push_back(getNode_Class());
	m_executionOccurrenceSpecification_Class->getESuperTypes()->push_back(getOccurrenceSpecification_Class());
	m_executionSpecification_Class->getESuperTypes()->push_back(getInteractionFragment_Class());
	m_expansionNode_Class->getESuperTypes()->push_back(getObjectNode_Class());
	m_expansionRegion_Class->getESuperTypes()->push_back(getStructuredActivityNode_Class());
	m_expression_Class->getESuperTypes()->push_back(getValueSpecification_Class());
	m_extend_Class->getESuperTypes()->push_back(getDirectedRelationship_Class());
	m_extend_Class->getESuperTypes()->push_back(getNamedElement_Class());
	m_extension_Class->getESuperTypes()->push_back(getAssociation_Class());
	m_extensionEnd_Class->getESuperTypes()->push_back(getProperty_Class());
	m_extensionPoint_Class->getESuperTypes()->push_back(getRedefinableElement_Class());
	m_factory_Class->getESuperTypes()->push_back(getElement_Class());
	m_feature_Class->getESuperTypes()->push_back(getRedefinableElement_Class());
	m_finalNode_Class->getESuperTypes()->push_back(getControlNode_Class());
	m_finalState_Class->getESuperTypes()->push_back(getState_Class());
	m_flowFinalNode_Class->getESuperTypes()->push_back(getFinalNode_Class());
	m_forkNode_Class->getESuperTypes()->push_back(getControlNode_Class());
	m_functionBehavior_Class->getESuperTypes()->push_back(getOpaqueBehavior_Class());
	m_gate_Class->getESuperTypes()->push_back(getMessageEnd_Class());
	m_generalOrdering_Class->getESuperTypes()->push_back(getNamedElement_Class());
	m_generalization_Class->getESuperTypes()->push_back(getDirectedRelationship_Class());
	m_generalizationSet_Class->getESuperTypes()->push_back(getPackageableElement_Class());
	m_image_Class->getESuperTypes()->push_back(getElement_Class());
	m_include_Class->getESuperTypes()->push_back(getDirectedRelationship_Class());
	m_include_Class->getESuperTypes()->push_back(getNamedElement_Class());
	m_informationFlow_Class->getESuperTypes()->push_back(getDirectedRelationship_Class());
	m_informationFlow_Class->getESuperTypes()->push_back(getPackageableElement_Class());
	m_informationItem_Class->getESuperTypes()->push_back(getClassifier_Class());
	m_initialNode_Class->getESuperTypes()->push_back(getControlNode_Class());
	m_inputPin_Class->getESuperTypes()->push_back(getPin_Class());
	m_instanceSpecification_Class->getESuperTypes()->push_back(getDeployedArtifact_Class());
	m_instanceSpecification_Class->getESuperTypes()->push_back(getDeploymentTarget_Class());
	m_instanceSpecification_Class->getESuperTypes()->push_back(getPackageableElement_Class());
	m_instanceValue_Class->getESuperTypes()->push_back(getValueSpecification_Class());
	m_interaction_Class->getESuperTypes()->push_back(getBehavior_Class());
	m_interaction_Class->getESuperTypes()->push_back(getInteractionFragment_Class());
	m_interactionConstraint_Class->getESuperTypes()->push_back(getConstraint_Class());
	m_interactionFragment_Class->getESuperTypes()->push_back(getNamedElement_Class());
	m_interactionOperand_Class->getESuperTypes()->push_back(getInteractionFragment_Class());
	m_interactionOperand_Class->getESuperTypes()->push_back(getNamespace_Class());
	m_interactionUse_Class->getESuperTypes()->push_back(getInteractionFragment_Class());
	m_interface_Class->getESuperTypes()->push_back(getClassifier_Class());
	m_interfaceRealization_Class->getESuperTypes()->push_back(getRealization_Class());
	m_interruptibleActivityRegion_Class->getESuperTypes()->push_back(getActivityGroup_Class());
	m_interval_Class->getESuperTypes()->push_back(getValueSpecification_Class());
	m_intervalConstraint_Class->getESuperTypes()->push_back(getConstraint_Class());
	m_invocationAction_Class->getESuperTypes()->push_back(getAction_Class());
	m_joinNode_Class->getESuperTypes()->push_back(getControlNode_Class());
	m_lifeline_Class->getESuperTypes()->push_back(getNamedElement_Class());
	m_linkAction_Class->getESuperTypes()->push_back(getAction_Class());
	m_linkEndCreationData_Class->getESuperTypes()->push_back(getLinkEndData_Class());
	m_linkEndData_Class->getESuperTypes()->push_back(getElement_Class());
	m_linkEndDestructionData_Class->getESuperTypes()->push_back(getLinkEndData_Class());
	m_literalBoolean_Class->getESuperTypes()->push_back(getLiteralSpecification_Class());
	m_literalInteger_Class->getESuperTypes()->push_back(getLiteralSpecification_Class());
	m_literalNull_Class->getESuperTypes()->push_back(getLiteralSpecification_Class());
	m_literalReal_Class->getESuperTypes()->push_back(getLiteralSpecification_Class());
	m_literalSpecification_Class->getESuperTypes()->push_back(getValueSpecification_Class());
	m_literalString_Class->getESuperTypes()->push_back(getLiteralSpecification_Class());
	m_literalUnlimitedNatural_Class->getESuperTypes()->push_back(getLiteralSpecification_Class());
	m_loopNode_Class->getESuperTypes()->push_back(getStructuredActivityNode_Class());
	m_manifestation_Class->getESuperTypes()->push_back(getAbstraction_Class());
	m_mergeNode_Class->getESuperTypes()->push_back(getControlNode_Class());
	m_message_Class->getESuperTypes()->push_back(getNamedElement_Class());
	m_messageEnd_Class->getESuperTypes()->push_back(getNamedElement_Class());
	m_messageEvent_Class->getESuperTypes()->push_back(getEvent_Class());
	m_messageOccurrenceSpecification_Class->getESuperTypes()->push_back(getMessageEnd_Class());
	m_messageOccurrenceSpecification_Class->getESuperTypes()->push_back(getOccurrenceSpecification_Class());
	m_model_Class->getESuperTypes()->push_back(getPackage_Class());
	m_multiplicityElement_Class->getESuperTypes()->push_back(getElement_Class());
	m_namedElement_Class->getESuperTypes()->push_back(getElement_Class());
	m_namespace_Class->getESuperTypes()->push_back(getNamedElement_Class());
	m_node_Class->getESuperTypes()->push_back(getClass_Class());
	m_node_Class->getESuperTypes()->push_back(getDeploymentTarget_Class());
	m_objectFlow_Class->getESuperTypes()->push_back(getActivityEdge_Class());
	m_objectNode_Class->getESuperTypes()->push_back(getActivityNode_Class());
	m_objectNode_Class->getESuperTypes()->push_back(getTypedElement_Class());
	m_observation_Class->getESuperTypes()->push_back(getPackageableElement_Class());
	m_occurrenceSpecification_Class->getESuperTypes()->push_back(getInteractionFragment_Class());
	m_opaqueAction_Class->getESuperTypes()->push_back(getAction_Class());
	m_opaqueBehavior_Class->getESuperTypes()->push_back(getBehavior_Class());
	m_opaqueExpression_Class->getESuperTypes()->push_back(getValueSpecification_Class());
	m_operation_Class->getESuperTypes()->push_back(getBehavioralFeature_Class());
	m_operation_Class->getESuperTypes()->push_back(getParameterableElement_Class());
	m_operation_Class->getESuperTypes()->push_back(getTemplateableElement_Class());
	m_operationTemplateParameter_Class->getESuperTypes()->push_back(getTemplateParameter_Class());
	m_outputPin_Class->getESuperTypes()->push_back(getPin_Class());
	m_package_Class->getESuperTypes()->push_back(getNamespace_Class());
	m_package_Class->getESuperTypes()->push_back(getPackageableElement_Class());
	m_package_Class->getESuperTypes()->push_back(getTemplateableElement_Class());
	m_packageImport_Class->getESuperTypes()->push_back(getDirectedRelationship_Class());
	m_packageMerge_Class->getESuperTypes()->push_back(getDirectedRelationship_Class());
	m_packageableElement_Class->getESuperTypes()->push_back(getNamedElement_Class());
	m_packageableElement_Class->getESuperTypes()->push_back(getParameterableElement_Class());
	m_parameter_Class->getESuperTypes()->push_back(getConnectableElement_Class());
	m_parameter_Class->getESuperTypes()->push_back(getMultiplicityElement_Class());
	m_parameterSet_Class->getESuperTypes()->push_back(getNamedElement_Class());
	m_parameterableElement_Class->getESuperTypes()->push_back(getElement_Class());
	m_partDecomposition_Class->getESuperTypes()->push_back(getInteractionUse_Class());
	m_pin_Class->getESuperTypes()->push_back(getMultiplicityElement_Class());
	m_pin_Class->getESuperTypes()->push_back(getObjectNode_Class());
	m_port_Class->getESuperTypes()->push_back(getProperty_Class());
	m_primitiveType_Class->getESuperTypes()->push_back(getDataType_Class());
	m_profile_Class->getESuperTypes()->push_back(getPackage_Class());
	m_profileApplication_Class->getESuperTypes()->push_back(getDirectedRelationship_Class());
	m_property_Class->getESuperTypes()->push_back(getConnectableElement_Class());
	m_property_Class->getESuperTypes()->push_back(getDeploymentTarget_Class());
	m_property_Class->getESuperTypes()->push_back(getStructuralFeature_Class());
	m_protocolConformance_Class->getESuperTypes()->push_back(getDirectedRelationship_Class());
	m_protocolStateMachine_Class->getESuperTypes()->push_back(getStateMachine_Class());
	m_protocolTransition_Class->getESuperTypes()->push_back(getTransition_Class());
	m_pseudostate_Class->getESuperTypes()->push_back(getVertex_Class());
	m_qualifierValue_Class->getESuperTypes()->push_back(getElement_Class());
	m_raiseExceptionAction_Class->getESuperTypes()->push_back(getAction_Class());
	m_readExtentAction_Class->getESuperTypes()->push_back(getAction_Class());
	m_readIsClassifiedObjectAction_Class->getESuperTypes()->push_back(getAction_Class());
	m_readLinkAction_Class->getESuperTypes()->push_back(getLinkAction_Class());
	m_readLinkObjectEndAction_Class->getESuperTypes()->push_back(getAction_Class());
	m_readLinkObjectEndQualifierAction_Class->getESuperTypes()->push_back(getAction_Class());
	m_readSelfAction_Class->getESuperTypes()->push_back(getAction_Class());
	m_readStructuralFeatureAction_Class->getESuperTypes()->push_back(getStructuralFeatureAction_Class());
	m_readVariableAction_Class->getESuperTypes()->push_back(getVariableAction_Class());
	m_realization_Class->getESuperTypes()->push_back(getAbstraction_Class());
	m_reception_Class->getESuperTypes()->push_back(getBehavioralFeature_Class());
	m_reclassifyObjectAction_Class->getESuperTypes()->push_back(getAction_Class());
	m_redefinableElement_Class->getESuperTypes()->push_back(getNamedElement_Class());
	m_redefinableTemplateSignature_Class->getESuperTypes()->push_back(getRedefinableElement_Class());
	m_redefinableTemplateSignature_Class->getESuperTypes()->push_back(getTemplateSignature_Class());
	m_reduceAction_Class->getESuperTypes()->push_back(getAction_Class());
	m_region_Class->getESuperTypes()->push_back(getNamespace_Class());
	m_region_Class->getESuperTypes()->push_back(getRedefinableElement_Class());
	m_relationship_Class->getESuperTypes()->push_back(getElement_Class());
	m_removeStructuralFeatureValueAction_Class->getESuperTypes()->push_back(getWriteStructuralFeatureAction_Class());
	m_removeVariableValueAction_Class->getESuperTypes()->push_back(getWriteVariableAction_Class());
	m_replyAction_Class->getESuperTypes()->push_back(getAction_Class());
	m_sendObjectAction_Class->getESuperTypes()->push_back(getInvocationAction_Class());
	m_sendSignalAction_Class->getESuperTypes()->push_back(getInvocationAction_Class());
	m_sequenceNode_Class->getESuperTypes()->push_back(getStructuredActivityNode_Class());
	m_signal_Class->getESuperTypes()->push_back(getClassifier_Class());
	m_signalEvent_Class->getESuperTypes()->push_back(getMessageEvent_Class());
	m_slot_Class->getESuperTypes()->push_back(getElement_Class());
	m_startClassifierBehaviorAction_Class->getESuperTypes()->push_back(getAction_Class());
	m_startObjectBehaviorAction_Class->getESuperTypes()->push_back(getCallAction_Class());
	m_state_Class->getESuperTypes()->push_back(getNamespace_Class());
	m_state_Class->getESuperTypes()->push_back(getRedefinableElement_Class());
	m_state_Class->getESuperTypes()->push_back(getVertex_Class());
	m_stateInvariant_Class->getESuperTypes()->push_back(getInteractionFragment_Class());
	m_stateMachine_Class->getESuperTypes()->push_back(getBehavior_Class());
	m_stereotype_Class->getESuperTypes()->push_back(getClass_Class());
	m_stringExpression_Class->getESuperTypes()->push_back(getExpression_Class());
	m_stringExpression_Class->getESuperTypes()->push_back(getTemplateableElement_Class());
	m_structuralFeature_Class->getESuperTypes()->push_back(getFeature_Class());
	m_structuralFeature_Class->getESuperTypes()->push_back(getMultiplicityElement_Class());
	m_structuralFeature_Class->getESuperTypes()->push_back(getTypedElement_Class());
	m_structuralFeatureAction_Class->getESuperTypes()->push_back(getAction_Class());
	m_structuredActivityNode_Class->getESuperTypes()->push_back(getAction_Class());
	m_structuredActivityNode_Class->getESuperTypes()->push_back(getActivityGroup_Class());
	m_structuredActivityNode_Class->getESuperTypes()->push_back(getNamespace_Class());
	m_structuredClassifier_Class->getESuperTypes()->push_back(getClassifier_Class());
	m_substitution_Class->getESuperTypes()->push_back(getRealization_Class());
	m_templateBinding_Class->getESuperTypes()->push_back(getDirectedRelationship_Class());
	m_templateParameter_Class->getESuperTypes()->push_back(getElement_Class());
	m_templateParameterSubstitution_Class->getESuperTypes()->push_back(getElement_Class());
	m_templateSignature_Class->getESuperTypes()->push_back(getElement_Class());
	m_templateableElement_Class->getESuperTypes()->push_back(getElement_Class());
	m_testIdentityAction_Class->getESuperTypes()->push_back(getAction_Class());
	m_timeConstraint_Class->getESuperTypes()->push_back(getIntervalConstraint_Class());
	m_timeEvent_Class->getESuperTypes()->push_back(getEvent_Class());
	m_timeExpression_Class->getESuperTypes()->push_back(getValueSpecification_Class());
	m_timeInterval_Class->getESuperTypes()->push_back(getInterval_Class());
	m_timeObservation_Class->getESuperTypes()->push_back(getObservation_Class());
	m_transition_Class->getESuperTypes()->push_back(getNamespace_Class());
	m_transition_Class->getESuperTypes()->push_back(getRedefinableElement_Class());
	m_trigger_Class->getESuperTypes()->push_back(getNamedElement_Class());
	m_type_Class->getESuperTypes()->push_back(getPackageableElement_Class());
	m_typedElement_Class->getESuperTypes()->push_back(getNamedElement_Class());
	m_unmarshallAction_Class->getESuperTypes()->push_back(getAction_Class());
	m_usage_Class->getESuperTypes()->push_back(getDependency_Class());
	m_useCase_Class->getESuperTypes()->push_back(getBehavioredClassifier_Class());
	m_valuePin_Class->getESuperTypes()->push_back(getInputPin_Class());
	m_valueSpecification_Class->getESuperTypes()->push_back(getPackageableElement_Class());
	m_valueSpecification_Class->getESuperTypes()->push_back(getTypedElement_Class());
	m_valueSpecificationAction_Class->getESuperTypes()->push_back(getAction_Class());
	m_variable_Class->getESuperTypes()->push_back(getConnectableElement_Class());
	m_variable_Class->getESuperTypes()->push_back(getMultiplicityElement_Class());
	m_variableAction_Class->getESuperTypes()->push_back(getAction_Class());
	m_vertex_Class->getESuperTypes()->push_back(getNamedElement_Class());
	m_writeLinkAction_Class->getESuperTypes()->push_back(getLinkAction_Class());
	m_writeStructuralFeatureAction_Class->getESuperTypes()->push_back(getStructuralFeatureAction_Class());
	m_writeVariableAction_Class->getESuperTypes()->push_back(getVariableAction_Class());
	

 	// Initialize classes and features; add operations and parameters
	initializeAbstractionContent();
	initializeAcceptCallActionContent();
	initializeAcceptEventActionContent();
	initializeActionContent();
	initializeActionExecutionSpecificationContent();
	initializeActionInputPinContent();
	initializeActivityContent();
	initializeActivityEdgeContent();
	initializeActivityFinalNodeContent();
	initializeActivityGroupContent();
	initializeActivityNodeContent();
	initializeActivityParameterNodeContent();
	initializeActivityPartitionContent();
	initializeActorContent();
	initializeAddStructuralFeatureValueActionContent();
	initializeAddVariableValueActionContent();
	initializeAnyReceiveEventContent();
	initializeArgumentContent();
	initializeArtifactContent();
	initializeAssociationContent();
	initializeAssociationClassContent();
	initializeBehaviorContent();
	initializeBehaviorExecutionSpecificationContent();
	initializeBehavioralFeatureContent();
	initializeBehavioredClassifierContent();
	initializeBroadcastSignalActionContent();
	initializeCallActionContent();
	initializeCallBehaviorActionContent();
	initializeCallEventContent();
	initializeCallOperationActionContent();
	initializeCentralBufferNodeContent();
	initializeChangeEventContent();
	initializeClassContent();
	initializeClassifierContent();
	initializeClassifierTemplateParameterContent();
	initializeClauseContent();
	initializeClearAssociationActionContent();
	initializeClearStructuralFeatureActionContent();
	initializeClearVariableActionContent();
	initializeCollaborationContent();
	initializeCollaborationUseContent();
	initializeCombinedFragmentContent();
	initializeCommentContent();
	initializeCommunicationPathContent();
	initializeComponentContent();
	initializeComponentRealizationContent();
	initializeConditionalNodeContent();
	initializeConnectableElementContent();
	initializeConnectableElementTemplateParameterContent();
	initializeConnectionPointReferenceContent();
	initializeConnectorContent();
	initializeConnectorEndContent();
	initializeConsiderIgnoreFragmentContent();
	initializeConstraintContent();
	initializeContinuationContent();
	initializeControlFlowContent();
	initializeControlNodeContent();
	initializeCreateLinkActionContent();
	initializeCreateLinkObjectActionContent();
	initializeCreateObjectActionContent();
	initializeDataStoreNodeContent();
	initializeDataTypeContent();
	initializeDecisionNodeContent();
	initializeDependencyContent();
	initializeDeployedArtifactContent();
	initializeDeploymentContent();
	initializeDeploymentSpecificationContent();
	initializeDeploymentTargetContent();
	initializeDestroyLinkActionContent();
	initializeDestroyObjectActionContent();
	initializeDestructionOccurrenceSpecificationContent();
	initializeDeviceContent();
	initializeDirectedRelationshipContent();
	initializeDurationContent();
	initializeDurationConstraintContent();
	initializeDurationIntervalContent();
	initializeDurationObservationContent();
	initializeElementContent();
	initializeElementImportContent();
	initializeEncapsulatedClassifierContent();
	initializeEnumerationContent();
	initializeEnumerationLiteralContent();
	initializeEventContent();
	initializeExceptionHandlerContent();
	initializeExecutableNodeContent();
	initializeExecutionEnvironmentContent();
	initializeExecutionOccurrenceSpecificationContent();
	initializeExecutionSpecificationContent();
	initializeExpansionNodeContent();
	initializeExpansionRegionContent();
	initializeExpressionContent();
	initializeExtendContent();
	initializeExtensionContent();
	initializeExtensionEndContent();
	initializeExtensionPointContent();
	initializeFactoryContent();
	initializeFeatureContent();
	initializeFinalNodeContent();
	initializeFinalStateContent();
	initializeFlowFinalNodeContent();
	initializeForkNodeContent();
	initializeFunctionBehaviorContent();
	initializeGateContent();
	initializeGeneralOrderingContent();
	initializeGeneralizationContent();
	initializeGeneralizationSetContent();
	initializeImageContent();
	initializeIncludeContent();
	initializeInformationFlowContent();
	initializeInformationItemContent();
	initializeInitialNodeContent();
	initializeInputPinContent();
	initializeInstanceSpecificationContent();
	initializeInstanceValueContent();
	initializeInteractionContent();
	initializeInteractionConstraintContent();
	initializeInteractionFragmentContent();
	initializeInteractionOperandContent();
	initializeInteractionUseContent();
	initializeInterfaceContent();
	initializeInterfaceRealizationContent();
	initializeInterruptibleActivityRegionContent();
	initializeIntervalContent();
	initializeIntervalConstraintContent();
	initializeInvocationActionContent();
	initializeJoinNodeContent();
	initializeLifelineContent();
	initializeLinkActionContent();
	initializeLinkEndCreationDataContent();
	initializeLinkEndDataContent();
	initializeLinkEndDestructionDataContent();
	initializeLiteralBooleanContent();
	initializeLiteralIntegerContent();
	initializeLiteralNullContent();
	initializeLiteralRealContent();
	initializeLiteralSpecificationContent();
	initializeLiteralStringContent();
	initializeLiteralUnlimitedNaturalContent();
	initializeLoopNodeContent();
	initializeManifestationContent();
	initializeMergeNodeContent();
	initializeMessageContent();
	initializeMessageEndContent();
	initializeMessageEventContent();
	initializeMessageOccurrenceSpecificationContent();
	initializeModelContent();
	initializeMultiplicityElementContent();
	initializeNamedElementContent();
	initializeNamespaceContent();
	initializeNodeContent();
	initializeObjectContent();
	initializeObjectFlowContent();
	initializeObjectNodeContent();
	initializeObservationContent();
	initializeOccurrenceSpecificationContent();
	initializeOpaqueActionContent();
	initializeOpaqueBehaviorContent();
	initializeOpaqueExpressionContent();
	initializeOperationContent();
	initializeOperationTemplateParameterContent();
	initializeOutputPinContent();
	initializePackageContent();
	initializePackageImportContent();
	initializePackageMergeContent();
	initializePackageableElementContent();
	initializeParameterContent();
	initializeParameterSetContent();
	initializeParameterableElementContent();
	initializePartDecompositionContent();
	initializePinContent();
	initializePortContent();
	initializePrimitiveTypeContent();
	initializeProfileContent();
	initializeProfileApplicationContent();
	initializePropertyContent();
	initializeProtocolConformanceContent();
	initializeProtocolStateMachineContent();
	initializeProtocolTransitionContent();
	initializePseudostateContent();
	initializeQualifierValueContent();
	initializeRaiseExceptionActionContent();
	initializeReadExtentActionContent();
	initializeReadIsClassifiedObjectActionContent();
	initializeReadLinkActionContent();
	initializeReadLinkObjectEndActionContent();
	initializeReadLinkObjectEndQualifierActionContent();
	initializeReadSelfActionContent();
	initializeReadStructuralFeatureActionContent();
	initializeReadVariableActionContent();
	initializeRealizationContent();
	initializeReceptionContent();
	initializeReclassifyObjectActionContent();
	initializeRedefinableElementContent();
	initializeRedefinableTemplateSignatureContent();
	initializeReduceActionContent();
	initializeRegionContent();
	initializeRelationshipContent();
	initializeRemoveStructuralFeatureValueActionContent();
	initializeRemoveVariableValueActionContent();
	initializeReplyActionContent();
	initializeSendObjectActionContent();
	initializeSendSignalActionContent();
	initializeSequenceNodeContent();
	initializeSignalContent();
	initializeSignalEventContent();
	initializeSlotContent();
	initializeStartClassifierBehaviorActionContent();
	initializeStartObjectBehaviorActionContent();
	initializeStateContent();
	initializeStateInvariantContent();
	initializeStateMachineContent();
	initializeStereotypeContent();
	initializeStringExpressionContent();
	initializeStructuralFeatureContent();
	initializeStructuralFeatureActionContent();
	initializeStructuredActivityNodeContent();
	initializeStructuredClassifierContent();
	initializeSubstitutionContent();
	initializeTemplateBindingContent();
	initializeTemplateParameterContent();
	initializeTemplateParameterSubstitutionContent();
	initializeTemplateSignatureContent();
	initializeTemplateableElementContent();
	initializeTestIdentityActionContent();
	initializeTimeConstraintContent();
	initializeTimeEventContent();
	initializeTimeExpressionContent();
	initializeTimeIntervalContent();
	initializeTimeObservationContent();
	initializeTransitionContent();
	initializeTriggerContent();
	initializeTypeContent();
	initializeTypedElementContent();
	initializeUnmarshallActionContent();
	initializeUsageContent();
	initializeUseCaseContent();
	initializeValuePinContent();
	initializeValueSpecificationContent();
	initializeValueSpecificationActionContent();
	initializeVariableContent();
	initializeVariableActionContent();
	initializeVertexContent();
	initializeWriteLinkActionContent();
	initializeWriteStructuralFeatureActionContent();
	initializeWriteVariableActionContent();

	initializePackageEDataTypes();

}

void umlPackageImpl::initializeAbstractionContent()
{
	m_abstraction_Class->setName("Abstraction");
	m_abstraction_Class->setAbstract(false);
	m_abstraction_Class->setInterface(false);
	
	m_abstraction_Class->_setID(ABSTRACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_abstraction_Attribute_mapping->setName("mapping");
	m_abstraction_Attribute_mapping->setEType(getOpaqueExpression_Class());
	m_abstraction_Attribute_mapping->setLowerBound(0);
	m_abstraction_Attribute_mapping->setUpperBound(1);
	m_abstraction_Attribute_mapping->setTransient(false);
	m_abstraction_Attribute_mapping->setVolatile(false);
	m_abstraction_Attribute_mapping->setChangeable(true);
	m_abstraction_Attribute_mapping->setUnsettable(false);
	m_abstraction_Attribute_mapping->setUnique(true);
	m_abstraction_Attribute_mapping->setDerived(false);
	m_abstraction_Attribute_mapping->setOrdered(false);
	m_abstraction_Attribute_mapping->setContainment(true);
	m_abstraction_Attribute_mapping->setResolveProxies(true);
	m_abstraction_Attribute_mapping->setDefaultValueLiteral("");	
	
	m_abstraction_Attribute_mapping->_setID(ABSTRACTION_ATTRIBUTE_MAPPING);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeAcceptCallActionContent()
{
	m_acceptCallAction_Class->setName("AcceptCallAction");
	m_acceptCallAction_Class->setAbstract(false);
	m_acceptCallAction_Class->setInterface(false);
	
	m_acceptCallAction_Class->_setID(ACCEPTCALLACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_acceptCallAction_Attribute_returnInformation->setName("returnInformation");
	m_acceptCallAction_Attribute_returnInformation->setEType(getOutputPin_Class());
	m_acceptCallAction_Attribute_returnInformation->setLowerBound(1);
	m_acceptCallAction_Attribute_returnInformation->setUpperBound(1);
	m_acceptCallAction_Attribute_returnInformation->setTransient(false);
	m_acceptCallAction_Attribute_returnInformation->setVolatile(false);
	m_acceptCallAction_Attribute_returnInformation->setChangeable(true);
	m_acceptCallAction_Attribute_returnInformation->setUnsettable(false);
	m_acceptCallAction_Attribute_returnInformation->setUnique(true);
	m_acceptCallAction_Attribute_returnInformation->setDerived(false);
	m_acceptCallAction_Attribute_returnInformation->setOrdered(false);
	m_acceptCallAction_Attribute_returnInformation->setContainment(true);
	m_acceptCallAction_Attribute_returnInformation->setResolveProxies(true);
	m_acceptCallAction_Attribute_returnInformation->setDefaultValueLiteral("");	
	
	m_acceptCallAction_Attribute_returnInformation->_setID(ACCEPTCALLACTION_ATTRIBUTE_RETURNINFORMATION);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeAcceptEventActionContent()
{
	m_acceptEventAction_Class->setName("AcceptEventAction");
	m_acceptEventAction_Class->setAbstract(false);
	m_acceptEventAction_Class->setInterface(false);
	
	m_acceptEventAction_Class->_setID(ACCEPTEVENTACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	m_acceptEventAction_Attribute_isUnmarshall = getAcceptEventAction_Attribute_isUnmarshall();
	m_acceptEventAction_Attribute_isUnmarshall->setName("isUnmarshall");
	m_acceptEventAction_Attribute_isUnmarshall->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_acceptEventAction_Attribute_isUnmarshall->setLowerBound(1);
	m_acceptEventAction_Attribute_isUnmarshall->setUpperBound(1);
	m_acceptEventAction_Attribute_isUnmarshall->setTransient(false);
	m_acceptEventAction_Attribute_isUnmarshall->setVolatile(false);
	m_acceptEventAction_Attribute_isUnmarshall->setChangeable(true);
	m_acceptEventAction_Attribute_isUnmarshall->setUnsettable(false);
	m_acceptEventAction_Attribute_isUnmarshall->setUnique(true);
	m_acceptEventAction_Attribute_isUnmarshall->setDerived(false);
	m_acceptEventAction_Attribute_isUnmarshall->setOrdered(false);
	m_acceptEventAction_Attribute_isUnmarshall->setID(false);
	m_acceptEventAction_Attribute_isUnmarshall->setDefaultValueLiteral("false");
	
	m_acceptEventAction_Attribute_isUnmarshall->_setID(ACCEPTEVENTACTION_ATTRIBUTE_ISUNMARSHALL);
	
	/*
	 * EReferences
	 */
	m_acceptEventAction_Attribute_result->setName("result");
	m_acceptEventAction_Attribute_result->setEType(getOutputPin_Class());
	m_acceptEventAction_Attribute_result->setLowerBound(0);
	m_acceptEventAction_Attribute_result->setUpperBound(-1);
	m_acceptEventAction_Attribute_result->setTransient(false);
	m_acceptEventAction_Attribute_result->setVolatile(false);
	m_acceptEventAction_Attribute_result->setChangeable(true);
	m_acceptEventAction_Attribute_result->setUnsettable(false);
	m_acceptEventAction_Attribute_result->setUnique(true);
	m_acceptEventAction_Attribute_result->setDerived(false);
	m_acceptEventAction_Attribute_result->setOrdered(true);
	m_acceptEventAction_Attribute_result->setContainment(true);
	m_acceptEventAction_Attribute_result->setResolveProxies(true);
	m_acceptEventAction_Attribute_result->setDefaultValueLiteral("");	
	
	m_acceptEventAction_Attribute_result->_setID(ACCEPTEVENTACTION_ATTRIBUTE_RESULT);
	m_acceptEventAction_Attribute_trigger->setName("trigger");
	m_acceptEventAction_Attribute_trigger->setEType(getTrigger_Class());
	m_acceptEventAction_Attribute_trigger->setLowerBound(1);
	m_acceptEventAction_Attribute_trigger->setUpperBound(-1);
	m_acceptEventAction_Attribute_trigger->setTransient(false);
	m_acceptEventAction_Attribute_trigger->setVolatile(false);
	m_acceptEventAction_Attribute_trigger->setChangeable(true);
	m_acceptEventAction_Attribute_trigger->setUnsettable(false);
	m_acceptEventAction_Attribute_trigger->setUnique(true);
	m_acceptEventAction_Attribute_trigger->setDerived(false);
	m_acceptEventAction_Attribute_trigger->setOrdered(false);
	m_acceptEventAction_Attribute_trigger->setContainment(true);
	m_acceptEventAction_Attribute_trigger->setResolveProxies(true);
	m_acceptEventAction_Attribute_trigger->setDefaultValueLiteral("");	
	
	m_acceptEventAction_Attribute_trigger->_setID(ACCEPTEVENTACTION_ATTRIBUTE_TRIGGER);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeActionContent()
{
	m_action_Class->setName("Action");
	m_action_Class->setAbstract(true);
	m_action_Class->setInterface(false);
	
	m_action_Class->_setID(ACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	m_action_Attribute_isLocallyReentrant = getAction_Attribute_isLocallyReentrant();
	m_action_Attribute_isLocallyReentrant->setName("isLocallyReentrant");
	m_action_Attribute_isLocallyReentrant->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_action_Attribute_isLocallyReentrant->setLowerBound(1);
	m_action_Attribute_isLocallyReentrant->setUpperBound(1);
	m_action_Attribute_isLocallyReentrant->setTransient(false);
	m_action_Attribute_isLocallyReentrant->setVolatile(false);
	m_action_Attribute_isLocallyReentrant->setChangeable(true);
	m_action_Attribute_isLocallyReentrant->setUnsettable(false);
	m_action_Attribute_isLocallyReentrant->setUnique(true);
	m_action_Attribute_isLocallyReentrant->setDerived(false);
	m_action_Attribute_isLocallyReentrant->setOrdered(false);
	m_action_Attribute_isLocallyReentrant->setID(false);
	m_action_Attribute_isLocallyReentrant->setDefaultValueLiteral("false");
	
	m_action_Attribute_isLocallyReentrant->_setID(ACTION_ATTRIBUTE_ISLOCALLYREENTRANT);
	
	/*
	 * EReferences
	 */
	m_action_Attribute_context->setName("context");
	m_action_Attribute_context->setEType(getClassifier_Class());
	m_action_Attribute_context->setLowerBound(0);
	m_action_Attribute_context->setUpperBound(1);
	m_action_Attribute_context->setTransient(true);
	m_action_Attribute_context->setVolatile(true);
	m_action_Attribute_context->setChangeable(false);
	m_action_Attribute_context->setUnsettable(false);
	m_action_Attribute_context->setUnique(true);
	m_action_Attribute_context->setDerived(true);
	m_action_Attribute_context->setOrdered(false);
	m_action_Attribute_context->setContainment(false);
	m_action_Attribute_context->setResolveProxies(true);
	m_action_Attribute_context->setDefaultValueLiteral("");	
	
	m_action_Attribute_context->_setID(ACTION_ATTRIBUTE_CONTEXT);
	m_action_Attribute_input->setName("input");
	m_action_Attribute_input->setEType(getInputPin_Class());
	m_action_Attribute_input->setLowerBound(0);
	m_action_Attribute_input->setUpperBound(-1);
	m_action_Attribute_input->setTransient(true);
	m_action_Attribute_input->setVolatile(true);
	m_action_Attribute_input->setChangeable(false);
	m_action_Attribute_input->setUnsettable(false);
	m_action_Attribute_input->setUnique(true);
	m_action_Attribute_input->setDerived(true);
	m_action_Attribute_input->setOrdered(true);
	m_action_Attribute_input->setContainment(true);
	m_action_Attribute_input->setResolveProxies(true);
	m_action_Attribute_input->setDefaultValueLiteral("");	
	m_action_Attribute_input->setEOpposite(uml::umlPackage::eInstance()->getInputPin_Attribute_action());
	
	m_action_Attribute_input->_setID(ACTION_ATTRIBUTE_INPUT);
	m_action_Attribute_localPostcondition->setName("localPostcondition");
	m_action_Attribute_localPostcondition->setEType(getConstraint_Class());
	m_action_Attribute_localPostcondition->setLowerBound(0);
	m_action_Attribute_localPostcondition->setUpperBound(-1);
	m_action_Attribute_localPostcondition->setTransient(false);
	m_action_Attribute_localPostcondition->setVolatile(false);
	m_action_Attribute_localPostcondition->setChangeable(true);
	m_action_Attribute_localPostcondition->setUnsettable(false);
	m_action_Attribute_localPostcondition->setUnique(true);
	m_action_Attribute_localPostcondition->setDerived(false);
	m_action_Attribute_localPostcondition->setOrdered(false);
	m_action_Attribute_localPostcondition->setContainment(true);
	m_action_Attribute_localPostcondition->setResolveProxies(true);
	m_action_Attribute_localPostcondition->setDefaultValueLiteral("");	
	
	m_action_Attribute_localPostcondition->_setID(ACTION_ATTRIBUTE_LOCALPOSTCONDITION);
	m_action_Attribute_localPrecondition->setName("localPrecondition");
	m_action_Attribute_localPrecondition->setEType(getConstraint_Class());
	m_action_Attribute_localPrecondition->setLowerBound(0);
	m_action_Attribute_localPrecondition->setUpperBound(-1);
	m_action_Attribute_localPrecondition->setTransient(false);
	m_action_Attribute_localPrecondition->setVolatile(false);
	m_action_Attribute_localPrecondition->setChangeable(true);
	m_action_Attribute_localPrecondition->setUnsettable(false);
	m_action_Attribute_localPrecondition->setUnique(true);
	m_action_Attribute_localPrecondition->setDerived(false);
	m_action_Attribute_localPrecondition->setOrdered(false);
	m_action_Attribute_localPrecondition->setContainment(true);
	m_action_Attribute_localPrecondition->setResolveProxies(true);
	m_action_Attribute_localPrecondition->setDefaultValueLiteral("");	
	
	m_action_Attribute_localPrecondition->_setID(ACTION_ATTRIBUTE_LOCALPRECONDITION);
	m_action_Attribute_output->setName("output");
	m_action_Attribute_output->setEType(getOutputPin_Class());
	m_action_Attribute_output->setLowerBound(0);
	m_action_Attribute_output->setUpperBound(-1);
	m_action_Attribute_output->setTransient(true);
	m_action_Attribute_output->setVolatile(true);
	m_action_Attribute_output->setChangeable(false);
	m_action_Attribute_output->setUnsettable(false);
	m_action_Attribute_output->setUnique(true);
	m_action_Attribute_output->setDerived(true);
	m_action_Attribute_output->setOrdered(true);
	m_action_Attribute_output->setContainment(true);
	m_action_Attribute_output->setResolveProxies(true);
	m_action_Attribute_output->setDefaultValueLiteral("");	
	m_action_Attribute_output->setEOpposite(uml::umlPackage::eInstance()->getOutputPin_Attribute_action());
	
	m_action_Attribute_output->_setID(ACTION_ATTRIBUTE_OUTPUT);
	
	/*
	 * EOperations
	 */
	m_action_Operation_allActions->setName("allActions");
	m_action_Operation_allActions->setEType(getAction_Class());
	m_action_Operation_allActions->setLowerBound(0);
	m_action_Operation_allActions->setUpperBound(-1);
	m_action_Operation_allActions->setUnique(true);
	m_action_Operation_allActions->setOrdered(false);
	
	m_action_Operation_allActions->_setID(ACTION_OPERATION_ALLACTIONS);
	
	
	m_action_Operation_allOwnedNodes->setName("allOwnedNodes");
	m_action_Operation_allOwnedNodes->setEType(getActivityNode_Class());
	m_action_Operation_allOwnedNodes->setLowerBound(0);
	m_action_Operation_allOwnedNodes->setUpperBound(-1);
	m_action_Operation_allOwnedNodes->setUnique(true);
	m_action_Operation_allOwnedNodes->setOrdered(false);
	
	m_action_Operation_allOwnedNodes->_setID(ACTION_OPERATION_ALLOWNEDNODES);
	
	
	m_action_Operation_containingBehavior->setName("containingBehavior");
	m_action_Operation_containingBehavior->setEType(getBehavior_Class());
	m_action_Operation_containingBehavior->setLowerBound(0);
	m_action_Operation_containingBehavior->setUpperBound(1);
	m_action_Operation_containingBehavior->setUnique(true);
	m_action_Operation_containingBehavior->setOrdered(false);
	
	m_action_Operation_containingBehavior->_setID(ACTION_OPERATION_CONTAININGBEHAVIOR);
	
	
	m_action_Operation_getContext->setName("getContext");
	m_action_Operation_getContext->setEType(getClassifier_Class());
	m_action_Operation_getContext->setLowerBound(0);
	m_action_Operation_getContext->setUpperBound(1);
	m_action_Operation_getContext->setUnique(true);
	m_action_Operation_getContext->setOrdered(false);
	
	m_action_Operation_getContext->_setID(ACTION_OPERATION_GETCONTEXT);
	
	
	
}

void umlPackageImpl::initializeActionExecutionSpecificationContent()
{
	m_actionExecutionSpecification_Class->setName("ActionExecutionSpecification");
	m_actionExecutionSpecification_Class->setAbstract(false);
	m_actionExecutionSpecification_Class->setInterface(false);
	
	m_actionExecutionSpecification_Class->_setID(ACTIONEXECUTIONSPECIFICATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_actionExecutionSpecification_Attribute_action->setName("action");
	m_actionExecutionSpecification_Attribute_action->setEType(getAction_Class());
	m_actionExecutionSpecification_Attribute_action->setLowerBound(1);
	m_actionExecutionSpecification_Attribute_action->setUpperBound(1);
	m_actionExecutionSpecification_Attribute_action->setTransient(false);
	m_actionExecutionSpecification_Attribute_action->setVolatile(false);
	m_actionExecutionSpecification_Attribute_action->setChangeable(true);
	m_actionExecutionSpecification_Attribute_action->setUnsettable(false);
	m_actionExecutionSpecification_Attribute_action->setUnique(true);
	m_actionExecutionSpecification_Attribute_action->setDerived(false);
	m_actionExecutionSpecification_Attribute_action->setOrdered(false);
	m_actionExecutionSpecification_Attribute_action->setContainment(false);
	m_actionExecutionSpecification_Attribute_action->setResolveProxies(true);
	m_actionExecutionSpecification_Attribute_action->setDefaultValueLiteral("");	
	
	m_actionExecutionSpecification_Attribute_action->_setID(ACTIONEXECUTIONSPECIFICATION_ATTRIBUTE_ACTION);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeActionInputPinContent()
{
	m_actionInputPin_Class->setName("ActionInputPin");
	m_actionInputPin_Class->setAbstract(false);
	m_actionInputPin_Class->setInterface(false);
	
	m_actionInputPin_Class->_setID(ACTIONINPUTPIN_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_actionInputPin_Attribute_fromAction->setName("fromAction");
	m_actionInputPin_Attribute_fromAction->setEType(getAction_Class());
	m_actionInputPin_Attribute_fromAction->setLowerBound(1);
	m_actionInputPin_Attribute_fromAction->setUpperBound(1);
	m_actionInputPin_Attribute_fromAction->setTransient(false);
	m_actionInputPin_Attribute_fromAction->setVolatile(false);
	m_actionInputPin_Attribute_fromAction->setChangeable(true);
	m_actionInputPin_Attribute_fromAction->setUnsettable(false);
	m_actionInputPin_Attribute_fromAction->setUnique(true);
	m_actionInputPin_Attribute_fromAction->setDerived(false);
	m_actionInputPin_Attribute_fromAction->setOrdered(false);
	m_actionInputPin_Attribute_fromAction->setContainment(true);
	m_actionInputPin_Attribute_fromAction->setResolveProxies(true);
	m_actionInputPin_Attribute_fromAction->setDefaultValueLiteral("");	
	
	m_actionInputPin_Attribute_fromAction->_setID(ACTIONINPUTPIN_ATTRIBUTE_FROMACTION);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeActivityContent()
{
	m_activity_Class->setName("Activity");
	m_activity_Class->setAbstract(false);
	m_activity_Class->setInterface(false);
	
	m_activity_Class->_setID(ACTIVITY_CLASS);
	
	/*
	 * EAttributes
	 */
	m_activity_Attribute_isReadOnly = getActivity_Attribute_isReadOnly();
	m_activity_Attribute_isReadOnly->setName("isReadOnly");
	m_activity_Attribute_isReadOnly->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_activity_Attribute_isReadOnly->setLowerBound(1);
	m_activity_Attribute_isReadOnly->setUpperBound(1);
	m_activity_Attribute_isReadOnly->setTransient(false);
	m_activity_Attribute_isReadOnly->setVolatile(false);
	m_activity_Attribute_isReadOnly->setChangeable(true);
	m_activity_Attribute_isReadOnly->setUnsettable(false);
	m_activity_Attribute_isReadOnly->setUnique(true);
	m_activity_Attribute_isReadOnly->setDerived(false);
	m_activity_Attribute_isReadOnly->setOrdered(false);
	m_activity_Attribute_isReadOnly->setID(false);
	m_activity_Attribute_isReadOnly->setDefaultValueLiteral("false");
	
	m_activity_Attribute_isReadOnly->_setID(ACTIVITY_ATTRIBUTE_ISREADONLY);
	m_activity_Attribute_isSingleExecution = getActivity_Attribute_isSingleExecution();
	m_activity_Attribute_isSingleExecution->setName("isSingleExecution");
	m_activity_Attribute_isSingleExecution->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_activity_Attribute_isSingleExecution->setLowerBound(1);
	m_activity_Attribute_isSingleExecution->setUpperBound(1);
	m_activity_Attribute_isSingleExecution->setTransient(false);
	m_activity_Attribute_isSingleExecution->setVolatile(false);
	m_activity_Attribute_isSingleExecution->setChangeable(true);
	m_activity_Attribute_isSingleExecution->setUnsettable(false);
	m_activity_Attribute_isSingleExecution->setUnique(true);
	m_activity_Attribute_isSingleExecution->setDerived(false);
	m_activity_Attribute_isSingleExecution->setOrdered(false);
	m_activity_Attribute_isSingleExecution->setID(false);
	m_activity_Attribute_isSingleExecution->setDefaultValueLiteral("false");
	
	m_activity_Attribute_isSingleExecution->_setID(ACTIVITY_ATTRIBUTE_ISSINGLEEXECUTION);
	
	/*
	 * EReferences
	 */
	m_activity_Attribute_edge->setName("edge");
	m_activity_Attribute_edge->setEType(getActivityEdge_Class());
	m_activity_Attribute_edge->setLowerBound(0);
	m_activity_Attribute_edge->setUpperBound(-1);
	m_activity_Attribute_edge->setTransient(false);
	m_activity_Attribute_edge->setVolatile(false);
	m_activity_Attribute_edge->setChangeable(true);
	m_activity_Attribute_edge->setUnsettable(false);
	m_activity_Attribute_edge->setUnique(true);
	m_activity_Attribute_edge->setDerived(false);
	m_activity_Attribute_edge->setOrdered(false);
	m_activity_Attribute_edge->setContainment(true);
	m_activity_Attribute_edge->setResolveProxies(true);
	m_activity_Attribute_edge->setDefaultValueLiteral("");	
	m_activity_Attribute_edge->setEOpposite(uml::umlPackage::eInstance()->getActivityEdge_Attribute_activity());
	
	m_activity_Attribute_edge->_setID(ACTIVITY_ATTRIBUTE_EDGE);
	m_activity_Attribute_group->setName("group");
	m_activity_Attribute_group->setEType(getActivityGroup_Class());
	m_activity_Attribute_group->setLowerBound(0);
	m_activity_Attribute_group->setUpperBound(-1);
	m_activity_Attribute_group->setTransient(true);
	m_activity_Attribute_group->setVolatile(true);
	m_activity_Attribute_group->setChangeable(true);
	m_activity_Attribute_group->setUnsettable(false);
	m_activity_Attribute_group->setUnique(true);
	m_activity_Attribute_group->setDerived(true);
	m_activity_Attribute_group->setOrdered(false);
	m_activity_Attribute_group->setContainment(true);
	m_activity_Attribute_group->setResolveProxies(true);
	m_activity_Attribute_group->setDefaultValueLiteral("");	
	m_activity_Attribute_group->setEOpposite(uml::umlPackage::eInstance()->getActivityGroup_Attribute_inActivity());
	
	m_activity_Attribute_group->_setID(ACTIVITY_ATTRIBUTE_GROUP);
	m_activity_Attribute_node->setName("node");
	m_activity_Attribute_node->setEType(getActivityNode_Class());
	m_activity_Attribute_node->setLowerBound(0);
	m_activity_Attribute_node->setUpperBound(-1);
	m_activity_Attribute_node->setTransient(true);
	m_activity_Attribute_node->setVolatile(true);
	m_activity_Attribute_node->setChangeable(true);
	m_activity_Attribute_node->setUnsettable(false);
	m_activity_Attribute_node->setUnique(true);
	m_activity_Attribute_node->setDerived(true);
	m_activity_Attribute_node->setOrdered(false);
	m_activity_Attribute_node->setContainment(true);
	m_activity_Attribute_node->setResolveProxies(true);
	m_activity_Attribute_node->setDefaultValueLiteral("");	
	m_activity_Attribute_node->setEOpposite(uml::umlPackage::eInstance()->getActivityNode_Attribute_activity());
	
	m_activity_Attribute_node->_setID(ACTIVITY_ATTRIBUTE_NODE);
	m_activity_Attribute_ownedGroup->setName("ownedGroup");
	m_activity_Attribute_ownedGroup->setEType(getActivityGroup_Class());
	m_activity_Attribute_ownedGroup->setLowerBound(0);
	m_activity_Attribute_ownedGroup->setUpperBound(-1);
	m_activity_Attribute_ownedGroup->setTransient(false);
	m_activity_Attribute_ownedGroup->setVolatile(false);
	m_activity_Attribute_ownedGroup->setChangeable(true);
	m_activity_Attribute_ownedGroup->setUnsettable(false);
	m_activity_Attribute_ownedGroup->setUnique(true);
	m_activity_Attribute_ownedGroup->setDerived(false);
	m_activity_Attribute_ownedGroup->setOrdered(false);
	m_activity_Attribute_ownedGroup->setContainment(true);
	m_activity_Attribute_ownedGroup->setResolveProxies(true);
	m_activity_Attribute_ownedGroup->setDefaultValueLiteral("");	
	
	m_activity_Attribute_ownedGroup->_setID(ACTIVITY_ATTRIBUTE_OWNEDGROUP);
	m_activity_Attribute_ownedNode->setName("ownedNode");
	m_activity_Attribute_ownedNode->setEType(getActivityNode_Class());
	m_activity_Attribute_ownedNode->setLowerBound(0);
	m_activity_Attribute_ownedNode->setUpperBound(-1);
	m_activity_Attribute_ownedNode->setTransient(false);
	m_activity_Attribute_ownedNode->setVolatile(false);
	m_activity_Attribute_ownedNode->setChangeable(true);
	m_activity_Attribute_ownedNode->setUnsettable(false);
	m_activity_Attribute_ownedNode->setUnique(true);
	m_activity_Attribute_ownedNode->setDerived(false);
	m_activity_Attribute_ownedNode->setOrdered(false);
	m_activity_Attribute_ownedNode->setContainment(true);
	m_activity_Attribute_ownedNode->setResolveProxies(true);
	m_activity_Attribute_ownedNode->setDefaultValueLiteral("");	
	
	m_activity_Attribute_ownedNode->_setID(ACTIVITY_ATTRIBUTE_OWNEDNODE);
	m_activity_Attribute_partition->setName("partition");
	m_activity_Attribute_partition->setEType(getActivityPartition_Class());
	m_activity_Attribute_partition->setLowerBound(0);
	m_activity_Attribute_partition->setUpperBound(-1);
	m_activity_Attribute_partition->setTransient(false);
	m_activity_Attribute_partition->setVolatile(false);
	m_activity_Attribute_partition->setChangeable(true);
	m_activity_Attribute_partition->setUnsettable(false);
	m_activity_Attribute_partition->setUnique(true);
	m_activity_Attribute_partition->setDerived(false);
	m_activity_Attribute_partition->setOrdered(false);
	m_activity_Attribute_partition->setContainment(false);
	m_activity_Attribute_partition->setResolveProxies(true);
	m_activity_Attribute_partition->setDefaultValueLiteral("");	
	
	m_activity_Attribute_partition->_setID(ACTIVITY_ATTRIBUTE_PARTITION);
	m_activity_Attribute_structuredNode->setName("structuredNode");
	m_activity_Attribute_structuredNode->setEType(getStructuredActivityNode_Class());
	m_activity_Attribute_structuredNode->setLowerBound(0);
	m_activity_Attribute_structuredNode->setUpperBound(-1);
	m_activity_Attribute_structuredNode->setTransient(false);
	m_activity_Attribute_structuredNode->setVolatile(false);
	m_activity_Attribute_structuredNode->setChangeable(true);
	m_activity_Attribute_structuredNode->setUnsettable(false);
	m_activity_Attribute_structuredNode->setUnique(true);
	m_activity_Attribute_structuredNode->setDerived(false);
	m_activity_Attribute_structuredNode->setOrdered(false);
	m_activity_Attribute_structuredNode->setContainment(true);
	m_activity_Attribute_structuredNode->setResolveProxies(true);
	m_activity_Attribute_structuredNode->setDefaultValueLiteral("");	
	
	m_activity_Attribute_structuredNode->_setID(ACTIVITY_ATTRIBUTE_STRUCTUREDNODE);
	m_activity_Attribute_variable->setName("variable");
	m_activity_Attribute_variable->setEType(getVariable_Class());
	m_activity_Attribute_variable->setLowerBound(0);
	m_activity_Attribute_variable->setUpperBound(-1);
	m_activity_Attribute_variable->setTransient(false);
	m_activity_Attribute_variable->setVolatile(false);
	m_activity_Attribute_variable->setChangeable(true);
	m_activity_Attribute_variable->setUnsettable(false);
	m_activity_Attribute_variable->setUnique(true);
	m_activity_Attribute_variable->setDerived(false);
	m_activity_Attribute_variable->setOrdered(false);
	m_activity_Attribute_variable->setContainment(true);
	m_activity_Attribute_variable->setResolveProxies(true);
	m_activity_Attribute_variable->setDefaultValueLiteral("");	
	m_activity_Attribute_variable->setEOpposite(uml::umlPackage::eInstance()->getVariable_Attribute_activityScope());
	
	m_activity_Attribute_variable->_setID(ACTIVITY_ATTRIBUTE_VARIABLE);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeActivityEdgeContent()
{
	m_activityEdge_Class->setName("ActivityEdge");
	m_activityEdge_Class->setAbstract(true);
	m_activityEdge_Class->setInterface(false);
	
	m_activityEdge_Class->_setID(ACTIVITYEDGE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_activityEdge_Attribute_activity->setName("activity");
	m_activityEdge_Attribute_activity->setEType(getActivity_Class());
	m_activityEdge_Attribute_activity->setLowerBound(0);
	m_activityEdge_Attribute_activity->setUpperBound(1);
	m_activityEdge_Attribute_activity->setTransient(false);
	m_activityEdge_Attribute_activity->setVolatile(false);
	m_activityEdge_Attribute_activity->setChangeable(true);
	m_activityEdge_Attribute_activity->setUnsettable(false);
	m_activityEdge_Attribute_activity->setUnique(true);
	m_activityEdge_Attribute_activity->setDerived(false);
	m_activityEdge_Attribute_activity->setOrdered(false);
	m_activityEdge_Attribute_activity->setContainment(false);
	m_activityEdge_Attribute_activity->setResolveProxies(true);
	m_activityEdge_Attribute_activity->setDefaultValueLiteral("");	
	m_activityEdge_Attribute_activity->setEOpposite(uml::umlPackage::eInstance()->getActivity_Attribute_edge());
	
	m_activityEdge_Attribute_activity->_setID(ACTIVITYEDGE_ATTRIBUTE_ACTIVITY);
	m_activityEdge_Attribute_guard->setName("guard");
	m_activityEdge_Attribute_guard->setEType(getValueSpecification_Class());
	m_activityEdge_Attribute_guard->setLowerBound(0);
	m_activityEdge_Attribute_guard->setUpperBound(1);
	m_activityEdge_Attribute_guard->setTransient(false);
	m_activityEdge_Attribute_guard->setVolatile(false);
	m_activityEdge_Attribute_guard->setChangeable(true);
	m_activityEdge_Attribute_guard->setUnsettable(false);
	m_activityEdge_Attribute_guard->setUnique(true);
	m_activityEdge_Attribute_guard->setDerived(false);
	m_activityEdge_Attribute_guard->setOrdered(false);
	m_activityEdge_Attribute_guard->setContainment(true);
	m_activityEdge_Attribute_guard->setResolveProxies(true);
	m_activityEdge_Attribute_guard->setDefaultValueLiteral("");	
	
	m_activityEdge_Attribute_guard->_setID(ACTIVITYEDGE_ATTRIBUTE_GUARD);
	m_activityEdge_Attribute_inGroup->setName("inGroup");
	m_activityEdge_Attribute_inGroup->setEType(getActivityGroup_Class());
	m_activityEdge_Attribute_inGroup->setLowerBound(0);
	m_activityEdge_Attribute_inGroup->setUpperBound(-1);
	m_activityEdge_Attribute_inGroup->setTransient(true);
	m_activityEdge_Attribute_inGroup->setVolatile(true);
	m_activityEdge_Attribute_inGroup->setChangeable(false);
	m_activityEdge_Attribute_inGroup->setUnsettable(false);
	m_activityEdge_Attribute_inGroup->setUnique(true);
	m_activityEdge_Attribute_inGroup->setDerived(true);
	m_activityEdge_Attribute_inGroup->setOrdered(false);
	m_activityEdge_Attribute_inGroup->setContainment(false);
	m_activityEdge_Attribute_inGroup->setResolveProxies(true);
	m_activityEdge_Attribute_inGroup->setDefaultValueLiteral("");	
	m_activityEdge_Attribute_inGroup->setEOpposite(uml::umlPackage::eInstance()->getActivityGroup_Attribute_containedEdge());
	
	m_activityEdge_Attribute_inGroup->_setID(ACTIVITYEDGE_ATTRIBUTE_INGROUP);
	m_activityEdge_Attribute_inPartition->setName("inPartition");
	m_activityEdge_Attribute_inPartition->setEType(getActivityPartition_Class());
	m_activityEdge_Attribute_inPartition->setLowerBound(0);
	m_activityEdge_Attribute_inPartition->setUpperBound(-1);
	m_activityEdge_Attribute_inPartition->setTransient(false);
	m_activityEdge_Attribute_inPartition->setVolatile(false);
	m_activityEdge_Attribute_inPartition->setChangeable(true);
	m_activityEdge_Attribute_inPartition->setUnsettable(false);
	m_activityEdge_Attribute_inPartition->setUnique(true);
	m_activityEdge_Attribute_inPartition->setDerived(false);
	m_activityEdge_Attribute_inPartition->setOrdered(false);
	m_activityEdge_Attribute_inPartition->setContainment(false);
	m_activityEdge_Attribute_inPartition->setResolveProxies(true);
	m_activityEdge_Attribute_inPartition->setDefaultValueLiteral("");	
	m_activityEdge_Attribute_inPartition->setEOpposite(uml::umlPackage::eInstance()->getActivityPartition_Attribute_edge());
	
	m_activityEdge_Attribute_inPartition->_setID(ACTIVITYEDGE_ATTRIBUTE_INPARTITION);
	m_activityEdge_Attribute_inStructuredNode->setName("inStructuredNode");
	m_activityEdge_Attribute_inStructuredNode->setEType(getStructuredActivityNode_Class());
	m_activityEdge_Attribute_inStructuredNode->setLowerBound(0);
	m_activityEdge_Attribute_inStructuredNode->setUpperBound(1);
	m_activityEdge_Attribute_inStructuredNode->setTransient(false);
	m_activityEdge_Attribute_inStructuredNode->setVolatile(false);
	m_activityEdge_Attribute_inStructuredNode->setChangeable(true);
	m_activityEdge_Attribute_inStructuredNode->setUnsettable(false);
	m_activityEdge_Attribute_inStructuredNode->setUnique(true);
	m_activityEdge_Attribute_inStructuredNode->setDerived(false);
	m_activityEdge_Attribute_inStructuredNode->setOrdered(false);
	m_activityEdge_Attribute_inStructuredNode->setContainment(false);
	m_activityEdge_Attribute_inStructuredNode->setResolveProxies(true);
	m_activityEdge_Attribute_inStructuredNode->setDefaultValueLiteral("");	
	m_activityEdge_Attribute_inStructuredNode->setEOpposite(uml::umlPackage::eInstance()->getStructuredActivityNode_Attribute_edge());
	
	m_activityEdge_Attribute_inStructuredNode->_setID(ACTIVITYEDGE_ATTRIBUTE_INSTRUCTUREDNODE);
	m_activityEdge_Attribute_interrupts->setName("interrupts");
	m_activityEdge_Attribute_interrupts->setEType(getInterruptibleActivityRegion_Class());
	m_activityEdge_Attribute_interrupts->setLowerBound(0);
	m_activityEdge_Attribute_interrupts->setUpperBound(1);
	m_activityEdge_Attribute_interrupts->setTransient(false);
	m_activityEdge_Attribute_interrupts->setVolatile(false);
	m_activityEdge_Attribute_interrupts->setChangeable(true);
	m_activityEdge_Attribute_interrupts->setUnsettable(false);
	m_activityEdge_Attribute_interrupts->setUnique(true);
	m_activityEdge_Attribute_interrupts->setDerived(false);
	m_activityEdge_Attribute_interrupts->setOrdered(false);
	m_activityEdge_Attribute_interrupts->setContainment(false);
	m_activityEdge_Attribute_interrupts->setResolveProxies(true);
	m_activityEdge_Attribute_interrupts->setDefaultValueLiteral("");	
	m_activityEdge_Attribute_interrupts->setEOpposite(uml::umlPackage::eInstance()->getInterruptibleActivityRegion_Attribute_interruptingEdge());
	
	m_activityEdge_Attribute_interrupts->_setID(ACTIVITYEDGE_ATTRIBUTE_INTERRUPTS);
	m_activityEdge_Attribute_redefinedEdge->setName("redefinedEdge");
	m_activityEdge_Attribute_redefinedEdge->setEType(getActivityEdge_Class());
	m_activityEdge_Attribute_redefinedEdge->setLowerBound(0);
	m_activityEdge_Attribute_redefinedEdge->setUpperBound(-1);
	m_activityEdge_Attribute_redefinedEdge->setTransient(false);
	m_activityEdge_Attribute_redefinedEdge->setVolatile(false);
	m_activityEdge_Attribute_redefinedEdge->setChangeable(true);
	m_activityEdge_Attribute_redefinedEdge->setUnsettable(false);
	m_activityEdge_Attribute_redefinedEdge->setUnique(true);
	m_activityEdge_Attribute_redefinedEdge->setDerived(false);
	m_activityEdge_Attribute_redefinedEdge->setOrdered(false);
	m_activityEdge_Attribute_redefinedEdge->setContainment(false);
	m_activityEdge_Attribute_redefinedEdge->setResolveProxies(true);
	m_activityEdge_Attribute_redefinedEdge->setDefaultValueLiteral("");	
	
	m_activityEdge_Attribute_redefinedEdge->_setID(ACTIVITYEDGE_ATTRIBUTE_REDEFINEDEDGE);
	m_activityEdge_Attribute_source->setName("source");
	m_activityEdge_Attribute_source->setEType(getActivityNode_Class());
	m_activityEdge_Attribute_source->setLowerBound(1);
	m_activityEdge_Attribute_source->setUpperBound(1);
	m_activityEdge_Attribute_source->setTransient(false);
	m_activityEdge_Attribute_source->setVolatile(false);
	m_activityEdge_Attribute_source->setChangeable(true);
	m_activityEdge_Attribute_source->setUnsettable(false);
	m_activityEdge_Attribute_source->setUnique(true);
	m_activityEdge_Attribute_source->setDerived(false);
	m_activityEdge_Attribute_source->setOrdered(false);
	m_activityEdge_Attribute_source->setContainment(false);
	m_activityEdge_Attribute_source->setResolveProxies(true);
	m_activityEdge_Attribute_source->setDefaultValueLiteral("");	
	m_activityEdge_Attribute_source->setEOpposite(uml::umlPackage::eInstance()->getActivityNode_Attribute_outgoing());
	
	m_activityEdge_Attribute_source->_setID(ACTIVITYEDGE_ATTRIBUTE_SOURCE);
	m_activityEdge_Attribute_target->setName("target");
	m_activityEdge_Attribute_target->setEType(getActivityNode_Class());
	m_activityEdge_Attribute_target->setLowerBound(1);
	m_activityEdge_Attribute_target->setUpperBound(1);
	m_activityEdge_Attribute_target->setTransient(false);
	m_activityEdge_Attribute_target->setVolatile(false);
	m_activityEdge_Attribute_target->setChangeable(true);
	m_activityEdge_Attribute_target->setUnsettable(false);
	m_activityEdge_Attribute_target->setUnique(true);
	m_activityEdge_Attribute_target->setDerived(false);
	m_activityEdge_Attribute_target->setOrdered(false);
	m_activityEdge_Attribute_target->setContainment(false);
	m_activityEdge_Attribute_target->setResolveProxies(true);
	m_activityEdge_Attribute_target->setDefaultValueLiteral("");	
	m_activityEdge_Attribute_target->setEOpposite(uml::umlPackage::eInstance()->getActivityNode_Attribute_incoming());
	
	m_activityEdge_Attribute_target->_setID(ACTIVITYEDGE_ATTRIBUTE_TARGET);
	m_activityEdge_Attribute_weight->setName("weight");
	m_activityEdge_Attribute_weight->setEType(getValueSpecification_Class());
	m_activityEdge_Attribute_weight->setLowerBound(0);
	m_activityEdge_Attribute_weight->setUpperBound(1);
	m_activityEdge_Attribute_weight->setTransient(false);
	m_activityEdge_Attribute_weight->setVolatile(false);
	m_activityEdge_Attribute_weight->setChangeable(true);
	m_activityEdge_Attribute_weight->setUnsettable(false);
	m_activityEdge_Attribute_weight->setUnique(true);
	m_activityEdge_Attribute_weight->setDerived(false);
	m_activityEdge_Attribute_weight->setOrdered(false);
	m_activityEdge_Attribute_weight->setContainment(true);
	m_activityEdge_Attribute_weight->setResolveProxies(true);
	m_activityEdge_Attribute_weight->setDefaultValueLiteral("");	
	
	m_activityEdge_Attribute_weight->_setID(ACTIVITYEDGE_ATTRIBUTE_WEIGHT);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeActivityFinalNodeContent()
{
	m_activityFinalNode_Class->setName("ActivityFinalNode");
	m_activityFinalNode_Class->setAbstract(false);
	m_activityFinalNode_Class->setInterface(false);
	
	m_activityFinalNode_Class->_setID(ACTIVITYFINALNODE_CLASS);
	
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

void umlPackageImpl::initializeActivityGroupContent()
{
	m_activityGroup_Class->setName("ActivityGroup");
	m_activityGroup_Class->setAbstract(true);
	m_activityGroup_Class->setInterface(false);
	
	m_activityGroup_Class->_setID(ACTIVITYGROUP_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_activityGroup_Attribute_containedEdge->setName("containedEdge");
	m_activityGroup_Attribute_containedEdge->setEType(getActivityEdge_Class());
	m_activityGroup_Attribute_containedEdge->setLowerBound(0);
	m_activityGroup_Attribute_containedEdge->setUpperBound(-1);
	m_activityGroup_Attribute_containedEdge->setTransient(true);
	m_activityGroup_Attribute_containedEdge->setVolatile(true);
	m_activityGroup_Attribute_containedEdge->setChangeable(false);
	m_activityGroup_Attribute_containedEdge->setUnsettable(false);
	m_activityGroup_Attribute_containedEdge->setUnique(true);
	m_activityGroup_Attribute_containedEdge->setDerived(true);
	m_activityGroup_Attribute_containedEdge->setOrdered(false);
	m_activityGroup_Attribute_containedEdge->setContainment(false);
	m_activityGroup_Attribute_containedEdge->setResolveProxies(true);
	m_activityGroup_Attribute_containedEdge->setDefaultValueLiteral("");	
	m_activityGroup_Attribute_containedEdge->setEOpposite(uml::umlPackage::eInstance()->getActivityEdge_Attribute_inGroup());
	
	m_activityGroup_Attribute_containedEdge->_setID(ACTIVITYGROUP_ATTRIBUTE_CONTAINEDEDGE);
	m_activityGroup_Attribute_containedNode->setName("containedNode");
	m_activityGroup_Attribute_containedNode->setEType(getActivityNode_Class());
	m_activityGroup_Attribute_containedNode->setLowerBound(0);
	m_activityGroup_Attribute_containedNode->setUpperBound(-1);
	m_activityGroup_Attribute_containedNode->setTransient(true);
	m_activityGroup_Attribute_containedNode->setVolatile(true);
	m_activityGroup_Attribute_containedNode->setChangeable(false);
	m_activityGroup_Attribute_containedNode->setUnsettable(false);
	m_activityGroup_Attribute_containedNode->setUnique(true);
	m_activityGroup_Attribute_containedNode->setDerived(true);
	m_activityGroup_Attribute_containedNode->setOrdered(false);
	m_activityGroup_Attribute_containedNode->setContainment(false);
	m_activityGroup_Attribute_containedNode->setResolveProxies(true);
	m_activityGroup_Attribute_containedNode->setDefaultValueLiteral("");	
	m_activityGroup_Attribute_containedNode->setEOpposite(uml::umlPackage::eInstance()->getActivityNode_Attribute_inGroup());
	
	m_activityGroup_Attribute_containedNode->_setID(ACTIVITYGROUP_ATTRIBUTE_CONTAINEDNODE);
	m_activityGroup_Attribute_inActivity->setName("inActivity");
	m_activityGroup_Attribute_inActivity->setEType(getActivity_Class());
	m_activityGroup_Attribute_inActivity->setLowerBound(0);
	m_activityGroup_Attribute_inActivity->setUpperBound(1);
	m_activityGroup_Attribute_inActivity->setTransient(true);
	m_activityGroup_Attribute_inActivity->setVolatile(true);
	m_activityGroup_Attribute_inActivity->setChangeable(true);
	m_activityGroup_Attribute_inActivity->setUnsettable(false);
	m_activityGroup_Attribute_inActivity->setUnique(true);
	m_activityGroup_Attribute_inActivity->setDerived(true);
	m_activityGroup_Attribute_inActivity->setOrdered(false);
	m_activityGroup_Attribute_inActivity->setContainment(false);
	m_activityGroup_Attribute_inActivity->setResolveProxies(true);
	m_activityGroup_Attribute_inActivity->setDefaultValueLiteral("");	
	m_activityGroup_Attribute_inActivity->setEOpposite(uml::umlPackage::eInstance()->getActivity_Attribute_group());
	
	m_activityGroup_Attribute_inActivity->_setID(ACTIVITYGROUP_ATTRIBUTE_INACTIVITY);
	m_activityGroup_Attribute_subgroup->setName("subgroup");
	m_activityGroup_Attribute_subgroup->setEType(getActivityGroup_Class());
	m_activityGroup_Attribute_subgroup->setLowerBound(0);
	m_activityGroup_Attribute_subgroup->setUpperBound(-1);
	m_activityGroup_Attribute_subgroup->setTransient(true);
	m_activityGroup_Attribute_subgroup->setVolatile(true);
	m_activityGroup_Attribute_subgroup->setChangeable(false);
	m_activityGroup_Attribute_subgroup->setUnsettable(false);
	m_activityGroup_Attribute_subgroup->setUnique(true);
	m_activityGroup_Attribute_subgroup->setDerived(true);
	m_activityGroup_Attribute_subgroup->setOrdered(false);
	m_activityGroup_Attribute_subgroup->setContainment(true);
	m_activityGroup_Attribute_subgroup->setResolveProxies(true);
	m_activityGroup_Attribute_subgroup->setDefaultValueLiteral("");	
	m_activityGroup_Attribute_subgroup->setEOpposite(uml::umlPackage::eInstance()->getActivityGroup_Attribute_superGroup());
	
	m_activityGroup_Attribute_subgroup->_setID(ACTIVITYGROUP_ATTRIBUTE_SUBGROUP);
	m_activityGroup_Attribute_superGroup->setName("superGroup");
	m_activityGroup_Attribute_superGroup->setEType(getActivityGroup_Class());
	m_activityGroup_Attribute_superGroup->setLowerBound(0);
	m_activityGroup_Attribute_superGroup->setUpperBound(1);
	m_activityGroup_Attribute_superGroup->setTransient(true);
	m_activityGroup_Attribute_superGroup->setVolatile(true);
	m_activityGroup_Attribute_superGroup->setChangeable(false);
	m_activityGroup_Attribute_superGroup->setUnsettable(false);
	m_activityGroup_Attribute_superGroup->setUnique(true);
	m_activityGroup_Attribute_superGroup->setDerived(true);
	m_activityGroup_Attribute_superGroup->setOrdered(false);
	m_activityGroup_Attribute_superGroup->setContainment(false);
	m_activityGroup_Attribute_superGroup->setResolveProxies(true);
	m_activityGroup_Attribute_superGroup->setDefaultValueLiteral("");	
	m_activityGroup_Attribute_superGroup->setEOpposite(uml::umlPackage::eInstance()->getActivityGroup_Attribute_subgroup());
	
	m_activityGroup_Attribute_superGroup->_setID(ACTIVITYGROUP_ATTRIBUTE_SUPERGROUP);
	
	/*
	 * EOperations
	 */
	m_activityGroup_Operation_containingActivity->setName("containingActivity");
	m_activityGroup_Operation_containingActivity->setEType(getActivity_Class());
	m_activityGroup_Operation_containingActivity->setLowerBound(0);
	m_activityGroup_Operation_containingActivity->setUpperBound(1);
	m_activityGroup_Operation_containingActivity->setUnique(true);
	m_activityGroup_Operation_containingActivity->setOrdered(false);
	
	m_activityGroup_Operation_containingActivity->_setID(ACTIVITYGROUP_OPERATION_CONTAININGACTIVITY);
	
	
	
}

void umlPackageImpl::initializeActivityNodeContent()
{
	m_activityNode_Class->setName("ActivityNode");
	m_activityNode_Class->setAbstract(true);
	m_activityNode_Class->setInterface(false);
	
	m_activityNode_Class->_setID(ACTIVITYNODE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_activityNode_Attribute_activity->setName("activity");
	m_activityNode_Attribute_activity->setEType(getActivity_Class());
	m_activityNode_Attribute_activity->setLowerBound(0);
	m_activityNode_Attribute_activity->setUpperBound(1);
	m_activityNode_Attribute_activity->setTransient(true);
	m_activityNode_Attribute_activity->setVolatile(true);
	m_activityNode_Attribute_activity->setChangeable(true);
	m_activityNode_Attribute_activity->setUnsettable(false);
	m_activityNode_Attribute_activity->setUnique(true);
	m_activityNode_Attribute_activity->setDerived(true);
	m_activityNode_Attribute_activity->setOrdered(false);
	m_activityNode_Attribute_activity->setContainment(false);
	m_activityNode_Attribute_activity->setResolveProxies(true);
	m_activityNode_Attribute_activity->setDefaultValueLiteral("");	
	m_activityNode_Attribute_activity->setEOpposite(uml::umlPackage::eInstance()->getActivity_Attribute_node());
	
	m_activityNode_Attribute_activity->_setID(ACTIVITYNODE_ATTRIBUTE_ACTIVITY);
	m_activityNode_Attribute_inGroup->setName("inGroup");
	m_activityNode_Attribute_inGroup->setEType(getActivityGroup_Class());
	m_activityNode_Attribute_inGroup->setLowerBound(0);
	m_activityNode_Attribute_inGroup->setUpperBound(-1);
	m_activityNode_Attribute_inGroup->setTransient(true);
	m_activityNode_Attribute_inGroup->setVolatile(true);
	m_activityNode_Attribute_inGroup->setChangeable(false);
	m_activityNode_Attribute_inGroup->setUnsettable(false);
	m_activityNode_Attribute_inGroup->setUnique(true);
	m_activityNode_Attribute_inGroup->setDerived(true);
	m_activityNode_Attribute_inGroup->setOrdered(false);
	m_activityNode_Attribute_inGroup->setContainment(false);
	m_activityNode_Attribute_inGroup->setResolveProxies(true);
	m_activityNode_Attribute_inGroup->setDefaultValueLiteral("");	
	m_activityNode_Attribute_inGroup->setEOpposite(uml::umlPackage::eInstance()->getActivityGroup_Attribute_containedNode());
	
	m_activityNode_Attribute_inGroup->_setID(ACTIVITYNODE_ATTRIBUTE_INGROUP);
	m_activityNode_Attribute_inInterruptibleRegion->setName("inInterruptibleRegion");
	m_activityNode_Attribute_inInterruptibleRegion->setEType(getInterruptibleActivityRegion_Class());
	m_activityNode_Attribute_inInterruptibleRegion->setLowerBound(0);
	m_activityNode_Attribute_inInterruptibleRegion->setUpperBound(-1);
	m_activityNode_Attribute_inInterruptibleRegion->setTransient(false);
	m_activityNode_Attribute_inInterruptibleRegion->setVolatile(false);
	m_activityNode_Attribute_inInterruptibleRegion->setChangeable(true);
	m_activityNode_Attribute_inInterruptibleRegion->setUnsettable(false);
	m_activityNode_Attribute_inInterruptibleRegion->setUnique(true);
	m_activityNode_Attribute_inInterruptibleRegion->setDerived(false);
	m_activityNode_Attribute_inInterruptibleRegion->setOrdered(false);
	m_activityNode_Attribute_inInterruptibleRegion->setContainment(false);
	m_activityNode_Attribute_inInterruptibleRegion->setResolveProxies(true);
	m_activityNode_Attribute_inInterruptibleRegion->setDefaultValueLiteral("");	
	m_activityNode_Attribute_inInterruptibleRegion->setEOpposite(uml::umlPackage::eInstance()->getInterruptibleActivityRegion_Attribute_node());
	
	m_activityNode_Attribute_inInterruptibleRegion->_setID(ACTIVITYNODE_ATTRIBUTE_ININTERRUPTIBLEREGION);
	m_activityNode_Attribute_inPartition->setName("inPartition");
	m_activityNode_Attribute_inPartition->setEType(getActivityPartition_Class());
	m_activityNode_Attribute_inPartition->setLowerBound(0);
	m_activityNode_Attribute_inPartition->setUpperBound(-1);
	m_activityNode_Attribute_inPartition->setTransient(false);
	m_activityNode_Attribute_inPartition->setVolatile(false);
	m_activityNode_Attribute_inPartition->setChangeable(true);
	m_activityNode_Attribute_inPartition->setUnsettable(false);
	m_activityNode_Attribute_inPartition->setUnique(true);
	m_activityNode_Attribute_inPartition->setDerived(false);
	m_activityNode_Attribute_inPartition->setOrdered(false);
	m_activityNode_Attribute_inPartition->setContainment(false);
	m_activityNode_Attribute_inPartition->setResolveProxies(true);
	m_activityNode_Attribute_inPartition->setDefaultValueLiteral("");	
	m_activityNode_Attribute_inPartition->setEOpposite(uml::umlPackage::eInstance()->getActivityPartition_Attribute_node());
	
	m_activityNode_Attribute_inPartition->_setID(ACTIVITYNODE_ATTRIBUTE_INPARTITION);
	m_activityNode_Attribute_inStructuredNode->setName("inStructuredNode");
	m_activityNode_Attribute_inStructuredNode->setEType(getStructuredActivityNode_Class());
	m_activityNode_Attribute_inStructuredNode->setLowerBound(0);
	m_activityNode_Attribute_inStructuredNode->setUpperBound(1);
	m_activityNode_Attribute_inStructuredNode->setTransient(false);
	m_activityNode_Attribute_inStructuredNode->setVolatile(false);
	m_activityNode_Attribute_inStructuredNode->setChangeable(true);
	m_activityNode_Attribute_inStructuredNode->setUnsettable(false);
	m_activityNode_Attribute_inStructuredNode->setUnique(true);
	m_activityNode_Attribute_inStructuredNode->setDerived(false);
	m_activityNode_Attribute_inStructuredNode->setOrdered(false);
	m_activityNode_Attribute_inStructuredNode->setContainment(false);
	m_activityNode_Attribute_inStructuredNode->setResolveProxies(true);
	m_activityNode_Attribute_inStructuredNode->setDefaultValueLiteral("");	
	m_activityNode_Attribute_inStructuredNode->setEOpposite(uml::umlPackage::eInstance()->getStructuredActivityNode_Attribute_node());
	
	m_activityNode_Attribute_inStructuredNode->_setID(ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE);
	m_activityNode_Attribute_incoming->setName("incoming");
	m_activityNode_Attribute_incoming->setEType(getActivityEdge_Class());
	m_activityNode_Attribute_incoming->setLowerBound(0);
	m_activityNode_Attribute_incoming->setUpperBound(-1);
	m_activityNode_Attribute_incoming->setTransient(false);
	m_activityNode_Attribute_incoming->setVolatile(false);
	m_activityNode_Attribute_incoming->setChangeable(true);
	m_activityNode_Attribute_incoming->setUnsettable(false);
	m_activityNode_Attribute_incoming->setUnique(true);
	m_activityNode_Attribute_incoming->setDerived(false);
	m_activityNode_Attribute_incoming->setOrdered(false);
	m_activityNode_Attribute_incoming->setContainment(false);
	m_activityNode_Attribute_incoming->setResolveProxies(true);
	m_activityNode_Attribute_incoming->setDefaultValueLiteral("");	
	m_activityNode_Attribute_incoming->setEOpposite(uml::umlPackage::eInstance()->getActivityEdge_Attribute_target());
	
	m_activityNode_Attribute_incoming->_setID(ACTIVITYNODE_ATTRIBUTE_INCOMING);
	m_activityNode_Attribute_outgoing->setName("outgoing");
	m_activityNode_Attribute_outgoing->setEType(getActivityEdge_Class());
	m_activityNode_Attribute_outgoing->setLowerBound(0);
	m_activityNode_Attribute_outgoing->setUpperBound(-1);
	m_activityNode_Attribute_outgoing->setTransient(false);
	m_activityNode_Attribute_outgoing->setVolatile(false);
	m_activityNode_Attribute_outgoing->setChangeable(true);
	m_activityNode_Attribute_outgoing->setUnsettable(false);
	m_activityNode_Attribute_outgoing->setUnique(true);
	m_activityNode_Attribute_outgoing->setDerived(false);
	m_activityNode_Attribute_outgoing->setOrdered(false);
	m_activityNode_Attribute_outgoing->setContainment(false);
	m_activityNode_Attribute_outgoing->setResolveProxies(true);
	m_activityNode_Attribute_outgoing->setDefaultValueLiteral("");	
	m_activityNode_Attribute_outgoing->setEOpposite(uml::umlPackage::eInstance()->getActivityEdge_Attribute_source());
	
	m_activityNode_Attribute_outgoing->_setID(ACTIVITYNODE_ATTRIBUTE_OUTGOING);
	m_activityNode_Attribute_redefinedNode->setName("redefinedNode");
	m_activityNode_Attribute_redefinedNode->setEType(getActivityNode_Class());
	m_activityNode_Attribute_redefinedNode->setLowerBound(0);
	m_activityNode_Attribute_redefinedNode->setUpperBound(-1);
	m_activityNode_Attribute_redefinedNode->setTransient(false);
	m_activityNode_Attribute_redefinedNode->setVolatile(false);
	m_activityNode_Attribute_redefinedNode->setChangeable(true);
	m_activityNode_Attribute_redefinedNode->setUnsettable(false);
	m_activityNode_Attribute_redefinedNode->setUnique(true);
	m_activityNode_Attribute_redefinedNode->setDerived(false);
	m_activityNode_Attribute_redefinedNode->setOrdered(false);
	m_activityNode_Attribute_redefinedNode->setContainment(false);
	m_activityNode_Attribute_redefinedNode->setResolveProxies(true);
	m_activityNode_Attribute_redefinedNode->setDefaultValueLiteral("");	
	
	m_activityNode_Attribute_redefinedNode->_setID(ACTIVITYNODE_ATTRIBUTE_REDEFINEDNODE);
	
	/*
	 * EOperations
	 */
	m_activityNode_Operation_containingActivity->setName("containingActivity");
	m_activityNode_Operation_containingActivity->setEType(getActivity_Class());
	m_activityNode_Operation_containingActivity->setLowerBound(0);
	m_activityNode_Operation_containingActivity->setUpperBound(1);
	m_activityNode_Operation_containingActivity->setUnique(true);
	m_activityNode_Operation_containingActivity->setOrdered(false);
	
	m_activityNode_Operation_containingActivity->_setID(ACTIVITYNODE_OPERATION_CONTAININGACTIVITY);
	
	
	
}

void umlPackageImpl::initializeActivityParameterNodeContent()
{
	m_activityParameterNode_Class->setName("ActivityParameterNode");
	m_activityParameterNode_Class->setAbstract(false);
	m_activityParameterNode_Class->setInterface(false);
	
	m_activityParameterNode_Class->_setID(ACTIVITYPARAMETERNODE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_activityParameterNode_Attribute_parameter->setName("parameter");
	m_activityParameterNode_Attribute_parameter->setEType(getParameter_Class());
	m_activityParameterNode_Attribute_parameter->setLowerBound(1);
	m_activityParameterNode_Attribute_parameter->setUpperBound(1);
	m_activityParameterNode_Attribute_parameter->setTransient(false);
	m_activityParameterNode_Attribute_parameter->setVolatile(false);
	m_activityParameterNode_Attribute_parameter->setChangeable(true);
	m_activityParameterNode_Attribute_parameter->setUnsettable(false);
	m_activityParameterNode_Attribute_parameter->setUnique(true);
	m_activityParameterNode_Attribute_parameter->setDerived(false);
	m_activityParameterNode_Attribute_parameter->setOrdered(false);
	m_activityParameterNode_Attribute_parameter->setContainment(false);
	m_activityParameterNode_Attribute_parameter->setResolveProxies(true);
	m_activityParameterNode_Attribute_parameter->setDefaultValueLiteral("");	
	
	m_activityParameterNode_Attribute_parameter->_setID(ACTIVITYPARAMETERNODE_ATTRIBUTE_PARAMETER);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeActivityPartitionContent()
{
	m_activityPartition_Class->setName("ActivityPartition");
	m_activityPartition_Class->setAbstract(false);
	m_activityPartition_Class->setInterface(false);
	
	m_activityPartition_Class->_setID(ACTIVITYPARTITION_CLASS);
	
	/*
	 * EAttributes
	 */
	m_activityPartition_Attribute_isDimension = getActivityPartition_Attribute_isDimension();
	m_activityPartition_Attribute_isDimension->setName("isDimension");
	m_activityPartition_Attribute_isDimension->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_activityPartition_Attribute_isDimension->setLowerBound(1);
	m_activityPartition_Attribute_isDimension->setUpperBound(1);
	m_activityPartition_Attribute_isDimension->setTransient(false);
	m_activityPartition_Attribute_isDimension->setVolatile(false);
	m_activityPartition_Attribute_isDimension->setChangeable(true);
	m_activityPartition_Attribute_isDimension->setUnsettable(false);
	m_activityPartition_Attribute_isDimension->setUnique(true);
	m_activityPartition_Attribute_isDimension->setDerived(false);
	m_activityPartition_Attribute_isDimension->setOrdered(false);
	m_activityPartition_Attribute_isDimension->setID(false);
	m_activityPartition_Attribute_isDimension->setDefaultValueLiteral("false");
	
	m_activityPartition_Attribute_isDimension->_setID(ACTIVITYPARTITION_ATTRIBUTE_ISDIMENSION);
	m_activityPartition_Attribute_isExternal = getActivityPartition_Attribute_isExternal();
	m_activityPartition_Attribute_isExternal->setName("isExternal");
	m_activityPartition_Attribute_isExternal->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_activityPartition_Attribute_isExternal->setLowerBound(1);
	m_activityPartition_Attribute_isExternal->setUpperBound(1);
	m_activityPartition_Attribute_isExternal->setTransient(false);
	m_activityPartition_Attribute_isExternal->setVolatile(false);
	m_activityPartition_Attribute_isExternal->setChangeable(true);
	m_activityPartition_Attribute_isExternal->setUnsettable(false);
	m_activityPartition_Attribute_isExternal->setUnique(true);
	m_activityPartition_Attribute_isExternal->setDerived(false);
	m_activityPartition_Attribute_isExternal->setOrdered(false);
	m_activityPartition_Attribute_isExternal->setID(false);
	m_activityPartition_Attribute_isExternal->setDefaultValueLiteral("false");
	
	m_activityPartition_Attribute_isExternal->_setID(ACTIVITYPARTITION_ATTRIBUTE_ISEXTERNAL);
	
	/*
	 * EReferences
	 */
	m_activityPartition_Attribute_edge->setName("edge");
	m_activityPartition_Attribute_edge->setEType(getActivityEdge_Class());
	m_activityPartition_Attribute_edge->setLowerBound(0);
	m_activityPartition_Attribute_edge->setUpperBound(-1);
	m_activityPartition_Attribute_edge->setTransient(false);
	m_activityPartition_Attribute_edge->setVolatile(false);
	m_activityPartition_Attribute_edge->setChangeable(true);
	m_activityPartition_Attribute_edge->setUnsettable(false);
	m_activityPartition_Attribute_edge->setUnique(true);
	m_activityPartition_Attribute_edge->setDerived(false);
	m_activityPartition_Attribute_edge->setOrdered(false);
	m_activityPartition_Attribute_edge->setContainment(false);
	m_activityPartition_Attribute_edge->setResolveProxies(true);
	m_activityPartition_Attribute_edge->setDefaultValueLiteral("");	
	m_activityPartition_Attribute_edge->setEOpposite(uml::umlPackage::eInstance()->getActivityEdge_Attribute_inPartition());
	
	m_activityPartition_Attribute_edge->_setID(ACTIVITYPARTITION_ATTRIBUTE_EDGE);
	m_activityPartition_Attribute_node->setName("node");
	m_activityPartition_Attribute_node->setEType(getActivityNode_Class());
	m_activityPartition_Attribute_node->setLowerBound(0);
	m_activityPartition_Attribute_node->setUpperBound(-1);
	m_activityPartition_Attribute_node->setTransient(false);
	m_activityPartition_Attribute_node->setVolatile(false);
	m_activityPartition_Attribute_node->setChangeable(true);
	m_activityPartition_Attribute_node->setUnsettable(false);
	m_activityPartition_Attribute_node->setUnique(true);
	m_activityPartition_Attribute_node->setDerived(false);
	m_activityPartition_Attribute_node->setOrdered(false);
	m_activityPartition_Attribute_node->setContainment(false);
	m_activityPartition_Attribute_node->setResolveProxies(true);
	m_activityPartition_Attribute_node->setDefaultValueLiteral("");	
	m_activityPartition_Attribute_node->setEOpposite(uml::umlPackage::eInstance()->getActivityNode_Attribute_inPartition());
	
	m_activityPartition_Attribute_node->_setID(ACTIVITYPARTITION_ATTRIBUTE_NODE);
	m_activityPartition_Attribute_represents->setName("represents");
	m_activityPartition_Attribute_represents->setEType(getElement_Class());
	m_activityPartition_Attribute_represents->setLowerBound(0);
	m_activityPartition_Attribute_represents->setUpperBound(1);
	m_activityPartition_Attribute_represents->setTransient(false);
	m_activityPartition_Attribute_represents->setVolatile(false);
	m_activityPartition_Attribute_represents->setChangeable(true);
	m_activityPartition_Attribute_represents->setUnsettable(false);
	m_activityPartition_Attribute_represents->setUnique(true);
	m_activityPartition_Attribute_represents->setDerived(false);
	m_activityPartition_Attribute_represents->setOrdered(false);
	m_activityPartition_Attribute_represents->setContainment(false);
	m_activityPartition_Attribute_represents->setResolveProxies(true);
	m_activityPartition_Attribute_represents->setDefaultValueLiteral("");	
	
	m_activityPartition_Attribute_represents->_setID(ACTIVITYPARTITION_ATTRIBUTE_REPRESENTS);
	m_activityPartition_Attribute_subpartition->setName("subpartition");
	m_activityPartition_Attribute_subpartition->setEType(getActivityPartition_Class());
	m_activityPartition_Attribute_subpartition->setLowerBound(0);
	m_activityPartition_Attribute_subpartition->setUpperBound(-1);
	m_activityPartition_Attribute_subpartition->setTransient(false);
	m_activityPartition_Attribute_subpartition->setVolatile(false);
	m_activityPartition_Attribute_subpartition->setChangeable(true);
	m_activityPartition_Attribute_subpartition->setUnsettable(false);
	m_activityPartition_Attribute_subpartition->setUnique(true);
	m_activityPartition_Attribute_subpartition->setDerived(false);
	m_activityPartition_Attribute_subpartition->setOrdered(false);
	m_activityPartition_Attribute_subpartition->setContainment(true);
	m_activityPartition_Attribute_subpartition->setResolveProxies(true);
	m_activityPartition_Attribute_subpartition->setDefaultValueLiteral("");	
	m_activityPartition_Attribute_subpartition->setEOpposite(uml::umlPackage::eInstance()->getActivityPartition_Attribute_superPartition());
	
	m_activityPartition_Attribute_subpartition->_setID(ACTIVITYPARTITION_ATTRIBUTE_SUBPARTITION);
	m_activityPartition_Attribute_superPartition->setName("superPartition");
	m_activityPartition_Attribute_superPartition->setEType(getActivityPartition_Class());
	m_activityPartition_Attribute_superPartition->setLowerBound(0);
	m_activityPartition_Attribute_superPartition->setUpperBound(1);
	m_activityPartition_Attribute_superPartition->setTransient(false);
	m_activityPartition_Attribute_superPartition->setVolatile(false);
	m_activityPartition_Attribute_superPartition->setChangeable(true);
	m_activityPartition_Attribute_superPartition->setUnsettable(false);
	m_activityPartition_Attribute_superPartition->setUnique(true);
	m_activityPartition_Attribute_superPartition->setDerived(false);
	m_activityPartition_Attribute_superPartition->setOrdered(false);
	m_activityPartition_Attribute_superPartition->setContainment(false);
	m_activityPartition_Attribute_superPartition->setResolveProxies(true);
	m_activityPartition_Attribute_superPartition->setDefaultValueLiteral("");	
	m_activityPartition_Attribute_superPartition->setEOpposite(uml::umlPackage::eInstance()->getActivityPartition_Attribute_subpartition());
	
	m_activityPartition_Attribute_superPartition->_setID(ACTIVITYPARTITION_ATTRIBUTE_SUPERPARTITION);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeActorContent()
{
	m_actor_Class->setName("Actor");
	m_actor_Class->setAbstract(false);
	m_actor_Class->setInterface(false);
	
	m_actor_Class->_setID(ACTOR_CLASS);
	
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

void umlPackageImpl::initializeAddStructuralFeatureValueActionContent()
{
	m_addStructuralFeatureValueAction_Class->setName("AddStructuralFeatureValueAction");
	m_addStructuralFeatureValueAction_Class->setAbstract(false);
	m_addStructuralFeatureValueAction_Class->setInterface(false);
	
	m_addStructuralFeatureValueAction_Class->_setID(ADDSTRUCTURALFEATUREVALUEACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	m_addStructuralFeatureValueAction_Attribute_isReplaceAll = getAddStructuralFeatureValueAction_Attribute_isReplaceAll();
	m_addStructuralFeatureValueAction_Attribute_isReplaceAll->setName("isReplaceAll");
	m_addStructuralFeatureValueAction_Attribute_isReplaceAll->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_addStructuralFeatureValueAction_Attribute_isReplaceAll->setLowerBound(1);
	m_addStructuralFeatureValueAction_Attribute_isReplaceAll->setUpperBound(1);
	m_addStructuralFeatureValueAction_Attribute_isReplaceAll->setTransient(false);
	m_addStructuralFeatureValueAction_Attribute_isReplaceAll->setVolatile(false);
	m_addStructuralFeatureValueAction_Attribute_isReplaceAll->setChangeable(true);
	m_addStructuralFeatureValueAction_Attribute_isReplaceAll->setUnsettable(false);
	m_addStructuralFeatureValueAction_Attribute_isReplaceAll->setUnique(true);
	m_addStructuralFeatureValueAction_Attribute_isReplaceAll->setDerived(false);
	m_addStructuralFeatureValueAction_Attribute_isReplaceAll->setOrdered(false);
	m_addStructuralFeatureValueAction_Attribute_isReplaceAll->setID(false);
	m_addStructuralFeatureValueAction_Attribute_isReplaceAll->setDefaultValueLiteral("false");
	
	m_addStructuralFeatureValueAction_Attribute_isReplaceAll->_setID(ADDSTRUCTURALFEATUREVALUEACTION_ATTRIBUTE_ISREPLACEALL);
	
	/*
	 * EReferences
	 */
	m_addStructuralFeatureValueAction_Attribute_insertAt->setName("insertAt");
	m_addStructuralFeatureValueAction_Attribute_insertAt->setEType(getInputPin_Class());
	m_addStructuralFeatureValueAction_Attribute_insertAt->setLowerBound(0);
	m_addStructuralFeatureValueAction_Attribute_insertAt->setUpperBound(1);
	m_addStructuralFeatureValueAction_Attribute_insertAt->setTransient(false);
	m_addStructuralFeatureValueAction_Attribute_insertAt->setVolatile(false);
	m_addStructuralFeatureValueAction_Attribute_insertAt->setChangeable(true);
	m_addStructuralFeatureValueAction_Attribute_insertAt->setUnsettable(false);
	m_addStructuralFeatureValueAction_Attribute_insertAt->setUnique(true);
	m_addStructuralFeatureValueAction_Attribute_insertAt->setDerived(false);
	m_addStructuralFeatureValueAction_Attribute_insertAt->setOrdered(false);
	m_addStructuralFeatureValueAction_Attribute_insertAt->setContainment(true);
	m_addStructuralFeatureValueAction_Attribute_insertAt->setResolveProxies(true);
	m_addStructuralFeatureValueAction_Attribute_insertAt->setDefaultValueLiteral("");	
	m_addStructuralFeatureValueAction_Attribute_insertAt->setEOpposite(uml::umlPackage::eInstance()->getInputPin_Attribute_addStructuralFeatureValueAction());
	
	m_addStructuralFeatureValueAction_Attribute_insertAt->_setID(ADDSTRUCTURALFEATUREVALUEACTION_ATTRIBUTE_INSERTAT);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeAddVariableValueActionContent()
{
	m_addVariableValueAction_Class->setName("AddVariableValueAction");
	m_addVariableValueAction_Class->setAbstract(false);
	m_addVariableValueAction_Class->setInterface(false);
	
	m_addVariableValueAction_Class->_setID(ADDVARIABLEVALUEACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	m_addVariableValueAction_Attribute_isReplaceAll = getAddVariableValueAction_Attribute_isReplaceAll();
	m_addVariableValueAction_Attribute_isReplaceAll->setName("isReplaceAll");
	m_addVariableValueAction_Attribute_isReplaceAll->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_addVariableValueAction_Attribute_isReplaceAll->setLowerBound(1);
	m_addVariableValueAction_Attribute_isReplaceAll->setUpperBound(1);
	m_addVariableValueAction_Attribute_isReplaceAll->setTransient(false);
	m_addVariableValueAction_Attribute_isReplaceAll->setVolatile(false);
	m_addVariableValueAction_Attribute_isReplaceAll->setChangeable(true);
	m_addVariableValueAction_Attribute_isReplaceAll->setUnsettable(false);
	m_addVariableValueAction_Attribute_isReplaceAll->setUnique(true);
	m_addVariableValueAction_Attribute_isReplaceAll->setDerived(false);
	m_addVariableValueAction_Attribute_isReplaceAll->setOrdered(false);
	m_addVariableValueAction_Attribute_isReplaceAll->setID(false);
	m_addVariableValueAction_Attribute_isReplaceAll->setDefaultValueLiteral("false");
	
	m_addVariableValueAction_Attribute_isReplaceAll->_setID(ADDVARIABLEVALUEACTION_ATTRIBUTE_ISREPLACEALL);
	
	/*
	 * EReferences
	 */
	m_addVariableValueAction_Attribute_insertAt->setName("insertAt");
	m_addVariableValueAction_Attribute_insertAt->setEType(getInputPin_Class());
	m_addVariableValueAction_Attribute_insertAt->setLowerBound(0);
	m_addVariableValueAction_Attribute_insertAt->setUpperBound(1);
	m_addVariableValueAction_Attribute_insertAt->setTransient(false);
	m_addVariableValueAction_Attribute_insertAt->setVolatile(false);
	m_addVariableValueAction_Attribute_insertAt->setChangeable(true);
	m_addVariableValueAction_Attribute_insertAt->setUnsettable(false);
	m_addVariableValueAction_Attribute_insertAt->setUnique(true);
	m_addVariableValueAction_Attribute_insertAt->setDerived(false);
	m_addVariableValueAction_Attribute_insertAt->setOrdered(false);
	m_addVariableValueAction_Attribute_insertAt->setContainment(true);
	m_addVariableValueAction_Attribute_insertAt->setResolveProxies(true);
	m_addVariableValueAction_Attribute_insertAt->setDefaultValueLiteral("");	
	
	m_addVariableValueAction_Attribute_insertAt->_setID(ADDVARIABLEVALUEACTION_ATTRIBUTE_INSERTAT);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeAnyReceiveEventContent()
{
	m_anyReceiveEvent_Class->setName("AnyReceiveEvent");
	m_anyReceiveEvent_Class->setAbstract(false);
	m_anyReceiveEvent_Class->setInterface(false);
	
	m_anyReceiveEvent_Class->_setID(ANYRECEIVEEVENT_CLASS);
	
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

void umlPackageImpl::initializeArgumentContent()
{
	m_argument_Class->setName("Argument");
	m_argument_Class->setAbstract(false);
	m_argument_Class->setInterface(false);
	
	m_argument_Class->_setID(ARGUMENT_CLASS);
	
	/*
	 * EAttributes
	 */
	m_argument_Attribute_name = getArgument_Attribute_name();
	m_argument_Attribute_name->setName("name");
	m_argument_Attribute_name->setEType(ecore::ecorePackage::eInstance()->getEString_Class());
	m_argument_Attribute_name->setLowerBound(0);
	m_argument_Attribute_name->setUpperBound(1);
	m_argument_Attribute_name->setTransient(false);
	m_argument_Attribute_name->setVolatile(false);
	m_argument_Attribute_name->setChangeable(true);
	m_argument_Attribute_name->setUnsettable(false);
	m_argument_Attribute_name->setUnique(true);
	m_argument_Attribute_name->setDerived(false);
	m_argument_Attribute_name->setOrdered(true);
	m_argument_Attribute_name->setID(false);
	m_argument_Attribute_name->setDefaultValueLiteral("");
	
	m_argument_Attribute_name->_setID(ARGUMENT_ATTRIBUTE_NAME);
	
	/*
	 * EReferences
	 */
	m_argument_Attribute_value->setName("value");
	m_argument_Attribute_value->setEType(getObject_Class());
	m_argument_Attribute_value->setLowerBound(0);
	m_argument_Attribute_value->setUpperBound(1);
	m_argument_Attribute_value->setTransient(false);
	m_argument_Attribute_value->setVolatile(false);
	m_argument_Attribute_value->setChangeable(true);
	m_argument_Attribute_value->setUnsettable(false);
	m_argument_Attribute_value->setUnique(true);
	m_argument_Attribute_value->setDerived(false);
	m_argument_Attribute_value->setOrdered(true);
	m_argument_Attribute_value->setContainment(false);
	m_argument_Attribute_value->setResolveProxies(true);
	m_argument_Attribute_value->setDefaultValueLiteral("");	
	
	m_argument_Attribute_value->_setID(ARGUMENT_ATTRIBUTE_VALUE);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeArtifactContent()
{
	m_artifact_Class->setName("Artifact");
	m_artifact_Class->setAbstract(false);
	m_artifact_Class->setInterface(false);
	
	m_artifact_Class->_setID(ARTIFACT_CLASS);
	
	/*
	 * EAttributes
	 */
	m_artifact_Attribute_fileName = getArtifact_Attribute_fileName();
	m_artifact_Attribute_fileName->setName("fileName");
	m_artifact_Attribute_fileName->setEType(types::typesPackage::eInstance()->getString_Class());
	m_artifact_Attribute_fileName->setLowerBound(0);
	m_artifact_Attribute_fileName->setUpperBound(1);
	m_artifact_Attribute_fileName->setTransient(false);
	m_artifact_Attribute_fileName->setVolatile(false);
	m_artifact_Attribute_fileName->setChangeable(true);
	m_artifact_Attribute_fileName->setUnsettable(true);
	m_artifact_Attribute_fileName->setUnique(true);
	m_artifact_Attribute_fileName->setDerived(false);
	m_artifact_Attribute_fileName->setOrdered(false);
	m_artifact_Attribute_fileName->setID(false);
	m_artifact_Attribute_fileName->setDefaultValueLiteral("");
	
	m_artifact_Attribute_fileName->_setID(ARTIFACT_ATTRIBUTE_FILENAME);
	
	/*
	 * EReferences
	 */
	m_artifact_Attribute_manifestation->setName("manifestation");
	m_artifact_Attribute_manifestation->setEType(getManifestation_Class());
	m_artifact_Attribute_manifestation->setLowerBound(0);
	m_artifact_Attribute_manifestation->setUpperBound(-1);
	m_artifact_Attribute_manifestation->setTransient(false);
	m_artifact_Attribute_manifestation->setVolatile(false);
	m_artifact_Attribute_manifestation->setChangeable(true);
	m_artifact_Attribute_manifestation->setUnsettable(false);
	m_artifact_Attribute_manifestation->setUnique(true);
	m_artifact_Attribute_manifestation->setDerived(false);
	m_artifact_Attribute_manifestation->setOrdered(false);
	m_artifact_Attribute_manifestation->setContainment(true);
	m_artifact_Attribute_manifestation->setResolveProxies(true);
	m_artifact_Attribute_manifestation->setDefaultValueLiteral("");	
	
	m_artifact_Attribute_manifestation->_setID(ARTIFACT_ATTRIBUTE_MANIFESTATION);
	m_artifact_Attribute_nestedArtifact->setName("nestedArtifact");
	m_artifact_Attribute_nestedArtifact->setEType(getArtifact_Class());
	m_artifact_Attribute_nestedArtifact->setLowerBound(0);
	m_artifact_Attribute_nestedArtifact->setUpperBound(-1);
	m_artifact_Attribute_nestedArtifact->setTransient(false);
	m_artifact_Attribute_nestedArtifact->setVolatile(false);
	m_artifact_Attribute_nestedArtifact->setChangeable(true);
	m_artifact_Attribute_nestedArtifact->setUnsettable(false);
	m_artifact_Attribute_nestedArtifact->setUnique(true);
	m_artifact_Attribute_nestedArtifact->setDerived(false);
	m_artifact_Attribute_nestedArtifact->setOrdered(false);
	m_artifact_Attribute_nestedArtifact->setContainment(true);
	m_artifact_Attribute_nestedArtifact->setResolveProxies(true);
	m_artifact_Attribute_nestedArtifact->setDefaultValueLiteral("");	
	
	m_artifact_Attribute_nestedArtifact->_setID(ARTIFACT_ATTRIBUTE_NESTEDARTIFACT);
	m_artifact_Attribute_ownedAttribute->setName("ownedAttribute");
	m_artifact_Attribute_ownedAttribute->setEType(getProperty_Class());
	m_artifact_Attribute_ownedAttribute->setLowerBound(0);
	m_artifact_Attribute_ownedAttribute->setUpperBound(-1);
	m_artifact_Attribute_ownedAttribute->setTransient(false);
	m_artifact_Attribute_ownedAttribute->setVolatile(false);
	m_artifact_Attribute_ownedAttribute->setChangeable(true);
	m_artifact_Attribute_ownedAttribute->setUnsettable(false);
	m_artifact_Attribute_ownedAttribute->setUnique(true);
	m_artifact_Attribute_ownedAttribute->setDerived(false);
	m_artifact_Attribute_ownedAttribute->setOrdered(true);
	m_artifact_Attribute_ownedAttribute->setContainment(true);
	m_artifact_Attribute_ownedAttribute->setResolveProxies(true);
	m_artifact_Attribute_ownedAttribute->setDefaultValueLiteral("");	
	
	m_artifact_Attribute_ownedAttribute->_setID(ARTIFACT_ATTRIBUTE_OWNEDATTRIBUTE);
	m_artifact_Attribute_ownedOperation->setName("ownedOperation");
	m_artifact_Attribute_ownedOperation->setEType(getOperation_Class());
	m_artifact_Attribute_ownedOperation->setLowerBound(0);
	m_artifact_Attribute_ownedOperation->setUpperBound(-1);
	m_artifact_Attribute_ownedOperation->setTransient(false);
	m_artifact_Attribute_ownedOperation->setVolatile(false);
	m_artifact_Attribute_ownedOperation->setChangeable(true);
	m_artifact_Attribute_ownedOperation->setUnsettable(false);
	m_artifact_Attribute_ownedOperation->setUnique(true);
	m_artifact_Attribute_ownedOperation->setDerived(false);
	m_artifact_Attribute_ownedOperation->setOrdered(true);
	m_artifact_Attribute_ownedOperation->setContainment(true);
	m_artifact_Attribute_ownedOperation->setResolveProxies(true);
	m_artifact_Attribute_ownedOperation->setDefaultValueLiteral("");	
	
	m_artifact_Attribute_ownedOperation->_setID(ARTIFACT_ATTRIBUTE_OWNEDOPERATION);
	
	/*
	 * EOperations
	 */
	m_artifact_Operation_createOwnedAttribute_String_UnlimitedNatural->setName("createOwnedAttribute");
	m_artifact_Operation_createOwnedAttribute_String_UnlimitedNatural->setEType(getProperty_Class());
	m_artifact_Operation_createOwnedAttribute_String_UnlimitedNatural->setLowerBound(1);
	m_artifact_Operation_createOwnedAttribute_String_UnlimitedNatural->setUpperBound(1);
	m_artifact_Operation_createOwnedAttribute_String_UnlimitedNatural->setUnique(true);
	m_artifact_Operation_createOwnedAttribute_String_UnlimitedNatural->setOrdered(false);
	
	m_artifact_Operation_createOwnedAttribute_String_UnlimitedNatural->_setID(ARTIFACT_OPERATION_CREATEOWNEDATTRIBUTE_STRING_UNLIMITEDNATURAL);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_artifact_Operation_createOwnedAttribute_String_UnlimitedNatural);
		parameter->setName("name");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_artifact_Operation_createOwnedAttribute_String_UnlimitedNatural);
		parameter->setName("type");
		parameter->setEType(getType_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_artifact_Operation_createOwnedAttribute_String_UnlimitedNatural);
		parameter->setName("lower");
		parameter->setEType(types::typesPackage::eInstance()->getInteger_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_artifact_Operation_createOwnedAttribute_String_UnlimitedNatural);
		parameter->setName("upper");
		parameter->setEType(types::typesPackage::eInstance()->getUnlimitedNatural_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_artifact_Operation_createOwnedOperation_String_Type->setName("createOwnedOperation");
	m_artifact_Operation_createOwnedOperation_String_Type->setEType(getOperation_Class());
	m_artifact_Operation_createOwnedOperation_String_Type->setLowerBound(1);
	m_artifact_Operation_createOwnedOperation_String_Type->setUpperBound(1);
	m_artifact_Operation_createOwnedOperation_String_Type->setUnique(true);
	m_artifact_Operation_createOwnedOperation_String_Type->setOrdered(false);
	
	m_artifact_Operation_createOwnedOperation_String_Type->_setID(ARTIFACT_OPERATION_CREATEOWNEDOPERATION_STRING_TYPE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_artifact_Operation_createOwnedOperation_String_Type);
		parameter->setName("name");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_artifact_Operation_createOwnedOperation_String_Type);
		parameter->setName("parameterNames");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_artifact_Operation_createOwnedOperation_String_Type);
		parameter->setName("parameterTypes");
		parameter->setEType(getType_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_artifact_Operation_createOwnedOperation_String_Type);
		parameter->setName("returnType");
		parameter->setEType(getType_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void umlPackageImpl::initializeAssociationContent()
{
	m_association_Class->setName("Association");
	m_association_Class->setAbstract(false);
	m_association_Class->setInterface(false);
	
	m_association_Class->_setID(ASSOCIATION_CLASS);
	
	/*
	 * EAttributes
	 */
	m_association_Attribute_isDerived = getAssociation_Attribute_isDerived();
	m_association_Attribute_isDerived->setName("isDerived");
	m_association_Attribute_isDerived->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_association_Attribute_isDerived->setLowerBound(1);
	m_association_Attribute_isDerived->setUpperBound(1);
	m_association_Attribute_isDerived->setTransient(false);
	m_association_Attribute_isDerived->setVolatile(false);
	m_association_Attribute_isDerived->setChangeable(true);
	m_association_Attribute_isDerived->setUnsettable(false);
	m_association_Attribute_isDerived->setUnique(true);
	m_association_Attribute_isDerived->setDerived(false);
	m_association_Attribute_isDerived->setOrdered(false);
	m_association_Attribute_isDerived->setID(false);
	m_association_Attribute_isDerived->setDefaultValueLiteral("false");
	
	m_association_Attribute_isDerived->_setID(ASSOCIATION_ATTRIBUTE_ISDERIVED);
	
	/*
	 * EReferences
	 */
	m_association_Attribute_endType->setName("endType");
	m_association_Attribute_endType->setEType(getType_Class());
	m_association_Attribute_endType->setLowerBound(1);
	m_association_Attribute_endType->setUpperBound(-1);
	m_association_Attribute_endType->setTransient(true);
	m_association_Attribute_endType->setVolatile(true);
	m_association_Attribute_endType->setChangeable(false);
	m_association_Attribute_endType->setUnsettable(false);
	m_association_Attribute_endType->setUnique(true);
	m_association_Attribute_endType->setDerived(true);
	m_association_Attribute_endType->setOrdered(false);
	m_association_Attribute_endType->setContainment(false);
	m_association_Attribute_endType->setResolveProxies(true);
	m_association_Attribute_endType->setDefaultValueLiteral("");	
	
	m_association_Attribute_endType->_setID(ASSOCIATION_ATTRIBUTE_ENDTYPE);
	m_association_Attribute_memberEnd->setName("memberEnd");
	m_association_Attribute_memberEnd->setEType(getProperty_Class());
	m_association_Attribute_memberEnd->setLowerBound(2);
	m_association_Attribute_memberEnd->setUpperBound(-1);
	m_association_Attribute_memberEnd->setTransient(false);
	m_association_Attribute_memberEnd->setVolatile(false);
	m_association_Attribute_memberEnd->setChangeable(true);
	m_association_Attribute_memberEnd->setUnsettable(false);
	m_association_Attribute_memberEnd->setUnique(true);
	m_association_Attribute_memberEnd->setDerived(false);
	m_association_Attribute_memberEnd->setOrdered(true);
	m_association_Attribute_memberEnd->setContainment(false);
	m_association_Attribute_memberEnd->setResolveProxies(true);
	m_association_Attribute_memberEnd->setDefaultValueLiteral("");	
	m_association_Attribute_memberEnd->setEOpposite(uml::umlPackage::eInstance()->getProperty_Attribute_association());
	
	m_association_Attribute_memberEnd->_setID(ASSOCIATION_ATTRIBUTE_MEMBEREND);
	m_association_Attribute_navigableOwnedEnd->setName("navigableOwnedEnd");
	m_association_Attribute_navigableOwnedEnd->setEType(getProperty_Class());
	m_association_Attribute_navigableOwnedEnd->setLowerBound(0);
	m_association_Attribute_navigableOwnedEnd->setUpperBound(-1);
	m_association_Attribute_navigableOwnedEnd->setTransient(false);
	m_association_Attribute_navigableOwnedEnd->setVolatile(false);
	m_association_Attribute_navigableOwnedEnd->setChangeable(true);
	m_association_Attribute_navigableOwnedEnd->setUnsettable(false);
	m_association_Attribute_navigableOwnedEnd->setUnique(true);
	m_association_Attribute_navigableOwnedEnd->setDerived(false);
	m_association_Attribute_navigableOwnedEnd->setOrdered(false);
	m_association_Attribute_navigableOwnedEnd->setContainment(false);
	m_association_Attribute_navigableOwnedEnd->setResolveProxies(true);
	m_association_Attribute_navigableOwnedEnd->setDefaultValueLiteral("");	
	
	m_association_Attribute_navigableOwnedEnd->_setID(ASSOCIATION_ATTRIBUTE_NAVIGABLEOWNEDEND);
	m_association_Attribute_ownedEnd->setName("ownedEnd");
	m_association_Attribute_ownedEnd->setEType(getProperty_Class());
	m_association_Attribute_ownedEnd->setLowerBound(0);
	m_association_Attribute_ownedEnd->setUpperBound(-1);
	m_association_Attribute_ownedEnd->setTransient(false);
	m_association_Attribute_ownedEnd->setVolatile(false);
	m_association_Attribute_ownedEnd->setChangeable(true);
	m_association_Attribute_ownedEnd->setUnsettable(false);
	m_association_Attribute_ownedEnd->setUnique(true);
	m_association_Attribute_ownedEnd->setDerived(false);
	m_association_Attribute_ownedEnd->setOrdered(true);
	m_association_Attribute_ownedEnd->setContainment(true);
	m_association_Attribute_ownedEnd->setResolveProxies(true);
	m_association_Attribute_ownedEnd->setDefaultValueLiteral("");	
	m_association_Attribute_ownedEnd->setEOpposite(uml::umlPackage::eInstance()->getProperty_Attribute_owningAssociation());
	
	m_association_Attribute_ownedEnd->_setID(ASSOCIATION_ATTRIBUTE_OWNEDEND);
	
	/*
	 * EOperations
	 */
	m_association_Operation_getEndTypes->setName("getEndTypes");
	m_association_Operation_getEndTypes->setEType(getType_Class());
	m_association_Operation_getEndTypes->setLowerBound(1);
	m_association_Operation_getEndTypes->setUpperBound(-1);
	m_association_Operation_getEndTypes->setUnique(true);
	m_association_Operation_getEndTypes->setOrdered(false);
	
	m_association_Operation_getEndTypes->_setID(ASSOCIATION_OPERATION_GETENDTYPES);
	
	
	m_association_Operation_isBinary->setName("isBinary");
	m_association_Operation_isBinary->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_association_Operation_isBinary->setLowerBound(1);
	m_association_Operation_isBinary->setUpperBound(1);
	m_association_Operation_isBinary->setUnique(true);
	m_association_Operation_isBinary->setOrdered(false);
	
	m_association_Operation_isBinary->_setID(ASSOCIATION_OPERATION_ISBINARY);
	
	
	
}

void umlPackageImpl::initializeAssociationClassContent()
{
	m_associationClass_Class->setName("AssociationClass");
	m_associationClass_Class->setAbstract(false);
	m_associationClass_Class->setInterface(false);
	
	m_associationClass_Class->_setID(ASSOCIATIONCLASS_CLASS);
	
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

void umlPackageImpl::initializeBehaviorContent()
{
	m_behavior_Class->setName("Behavior");
	m_behavior_Class->setAbstract(true);
	m_behavior_Class->setInterface(false);
	
	m_behavior_Class->_setID(BEHAVIOR_CLASS);
	
	/*
	 * EAttributes
	 */
	m_behavior_Attribute_isReentrant = getBehavior_Attribute_isReentrant();
	m_behavior_Attribute_isReentrant->setName("isReentrant");
	m_behavior_Attribute_isReentrant->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_behavior_Attribute_isReentrant->setLowerBound(0);
	m_behavior_Attribute_isReentrant->setUpperBound(1);
	m_behavior_Attribute_isReentrant->setTransient(false);
	m_behavior_Attribute_isReentrant->setVolatile(false);
	m_behavior_Attribute_isReentrant->setChangeable(true);
	m_behavior_Attribute_isReentrant->setUnsettable(true);
	m_behavior_Attribute_isReentrant->setUnique(true);
	m_behavior_Attribute_isReentrant->setDerived(false);
	m_behavior_Attribute_isReentrant->setOrdered(false);
	m_behavior_Attribute_isReentrant->setID(false);
	m_behavior_Attribute_isReentrant->setDefaultValueLiteral("true");
	
	m_behavior_Attribute_isReentrant->_setID(BEHAVIOR_ATTRIBUTE_ISREENTRANT);
	
	/*
	 * EReferences
	 */
	m_behavior_Attribute_behavioredClassifier->setName("behavioredClassifier");
	m_behavior_Attribute_behavioredClassifier->setEType(getBehavioredClassifier_Class());
	m_behavior_Attribute_behavioredClassifier->setLowerBound(0);
	m_behavior_Attribute_behavioredClassifier->setUpperBound(1);
	m_behavior_Attribute_behavioredClassifier->setTransient(false);
	m_behavior_Attribute_behavioredClassifier->setVolatile(false);
	m_behavior_Attribute_behavioredClassifier->setChangeable(true);
	m_behavior_Attribute_behavioredClassifier->setUnsettable(true);
	m_behavior_Attribute_behavioredClassifier->setUnique(true);
	m_behavior_Attribute_behavioredClassifier->setDerived(false);
	m_behavior_Attribute_behavioredClassifier->setOrdered(true);
	m_behavior_Attribute_behavioredClassifier->setContainment(false);
	m_behavior_Attribute_behavioredClassifier->setResolveProxies(true);
	m_behavior_Attribute_behavioredClassifier->setDefaultValueLiteral("");	
	m_behavior_Attribute_behavioredClassifier->setEOpposite(uml::umlPackage::eInstance()->getBehavioredClassifier_Attribute_ownedBehavior());
	
	m_behavior_Attribute_behavioredClassifier->_setID(BEHAVIOR_ATTRIBUTE_BEHAVIOREDCLASSIFIER);
	m_behavior_Attribute_context->setName("context");
	m_behavior_Attribute_context->setEType(getBehavioredClassifier_Class());
	m_behavior_Attribute_context->setLowerBound(0);
	m_behavior_Attribute_context->setUpperBound(1);
	m_behavior_Attribute_context->setTransient(true);
	m_behavior_Attribute_context->setVolatile(true);
	m_behavior_Attribute_context->setChangeable(true);
	m_behavior_Attribute_context->setUnsettable(false);
	m_behavior_Attribute_context->setUnique(true);
	m_behavior_Attribute_context->setDerived(true);
	m_behavior_Attribute_context->setOrdered(false);
	m_behavior_Attribute_context->setContainment(false);
	m_behavior_Attribute_context->setResolveProxies(true);
	m_behavior_Attribute_context->setDefaultValueLiteral("");	
	
	m_behavior_Attribute_context->_setID(BEHAVIOR_ATTRIBUTE_CONTEXT);
	m_behavior_Attribute_ownedParameter->setName("ownedParameter");
	m_behavior_Attribute_ownedParameter->setEType(getParameter_Class());
	m_behavior_Attribute_ownedParameter->setLowerBound(0);
	m_behavior_Attribute_ownedParameter->setUpperBound(-1);
	m_behavior_Attribute_ownedParameter->setTransient(false);
	m_behavior_Attribute_ownedParameter->setVolatile(false);
	m_behavior_Attribute_ownedParameter->setChangeable(true);
	m_behavior_Attribute_ownedParameter->setUnsettable(false);
	m_behavior_Attribute_ownedParameter->setUnique(true);
	m_behavior_Attribute_ownedParameter->setDerived(false);
	m_behavior_Attribute_ownedParameter->setOrdered(true);
	m_behavior_Attribute_ownedParameter->setContainment(true);
	m_behavior_Attribute_ownedParameter->setResolveProxies(true);
	m_behavior_Attribute_ownedParameter->setDefaultValueLiteral("");	
	m_behavior_Attribute_ownedParameter->setEOpposite(uml::umlPackage::eInstance()->getParameter_Attribute_behavior());
	
	m_behavior_Attribute_ownedParameter->_setID(BEHAVIOR_ATTRIBUTE_OWNEDPARAMETER);
	m_behavior_Attribute_ownedParameterSet->setName("ownedParameterSet");
	m_behavior_Attribute_ownedParameterSet->setEType(getParameterSet_Class());
	m_behavior_Attribute_ownedParameterSet->setLowerBound(0);
	m_behavior_Attribute_ownedParameterSet->setUpperBound(-1);
	m_behavior_Attribute_ownedParameterSet->setTransient(false);
	m_behavior_Attribute_ownedParameterSet->setVolatile(false);
	m_behavior_Attribute_ownedParameterSet->setChangeable(true);
	m_behavior_Attribute_ownedParameterSet->setUnsettable(false);
	m_behavior_Attribute_ownedParameterSet->setUnique(true);
	m_behavior_Attribute_ownedParameterSet->setDerived(false);
	m_behavior_Attribute_ownedParameterSet->setOrdered(false);
	m_behavior_Attribute_ownedParameterSet->setContainment(true);
	m_behavior_Attribute_ownedParameterSet->setResolveProxies(true);
	m_behavior_Attribute_ownedParameterSet->setDefaultValueLiteral("");	
	
	m_behavior_Attribute_ownedParameterSet->_setID(BEHAVIOR_ATTRIBUTE_OWNEDPARAMETERSET);
	m_behavior_Attribute_postcondition->setName("postcondition");
	m_behavior_Attribute_postcondition->setEType(getConstraint_Class());
	m_behavior_Attribute_postcondition->setLowerBound(0);
	m_behavior_Attribute_postcondition->setUpperBound(-1);
	m_behavior_Attribute_postcondition->setTransient(false);
	m_behavior_Attribute_postcondition->setVolatile(false);
	m_behavior_Attribute_postcondition->setChangeable(true);
	m_behavior_Attribute_postcondition->setUnsettable(false);
	m_behavior_Attribute_postcondition->setUnique(true);
	m_behavior_Attribute_postcondition->setDerived(false);
	m_behavior_Attribute_postcondition->setOrdered(false);
	m_behavior_Attribute_postcondition->setContainment(false);
	m_behavior_Attribute_postcondition->setResolveProxies(true);
	m_behavior_Attribute_postcondition->setDefaultValueLiteral("");	
	
	m_behavior_Attribute_postcondition->_setID(BEHAVIOR_ATTRIBUTE_POSTCONDITION);
	m_behavior_Attribute_precondition->setName("precondition");
	m_behavior_Attribute_precondition->setEType(getConstraint_Class());
	m_behavior_Attribute_precondition->setLowerBound(0);
	m_behavior_Attribute_precondition->setUpperBound(-1);
	m_behavior_Attribute_precondition->setTransient(false);
	m_behavior_Attribute_precondition->setVolatile(false);
	m_behavior_Attribute_precondition->setChangeable(true);
	m_behavior_Attribute_precondition->setUnsettable(false);
	m_behavior_Attribute_precondition->setUnique(true);
	m_behavior_Attribute_precondition->setDerived(false);
	m_behavior_Attribute_precondition->setOrdered(false);
	m_behavior_Attribute_precondition->setContainment(false);
	m_behavior_Attribute_precondition->setResolveProxies(true);
	m_behavior_Attribute_precondition->setDefaultValueLiteral("");	
	
	m_behavior_Attribute_precondition->_setID(BEHAVIOR_ATTRIBUTE_PRECONDITION);
	m_behavior_Attribute_redefinedBehavior->setName("redefinedBehavior");
	m_behavior_Attribute_redefinedBehavior->setEType(getBehavior_Class());
	m_behavior_Attribute_redefinedBehavior->setLowerBound(0);
	m_behavior_Attribute_redefinedBehavior->setUpperBound(-1);
	m_behavior_Attribute_redefinedBehavior->setTransient(false);
	m_behavior_Attribute_redefinedBehavior->setVolatile(false);
	m_behavior_Attribute_redefinedBehavior->setChangeable(true);
	m_behavior_Attribute_redefinedBehavior->setUnsettable(false);
	m_behavior_Attribute_redefinedBehavior->setUnique(true);
	m_behavior_Attribute_redefinedBehavior->setDerived(false);
	m_behavior_Attribute_redefinedBehavior->setOrdered(false);
	m_behavior_Attribute_redefinedBehavior->setContainment(false);
	m_behavior_Attribute_redefinedBehavior->setResolveProxies(true);
	m_behavior_Attribute_redefinedBehavior->setDefaultValueLiteral("");	
	
	m_behavior_Attribute_redefinedBehavior->_setID(BEHAVIOR_ATTRIBUTE_REDEFINEDBEHAVIOR);
	m_behavior_Attribute_specification->setName("specification");
	m_behavior_Attribute_specification->setEType(getBehavioralFeature_Class());
	m_behavior_Attribute_specification->setLowerBound(0);
	m_behavior_Attribute_specification->setUpperBound(1);
	m_behavior_Attribute_specification->setTransient(false);
	m_behavior_Attribute_specification->setVolatile(false);
	m_behavior_Attribute_specification->setChangeable(true);
	m_behavior_Attribute_specification->setUnsettable(false);
	m_behavior_Attribute_specification->setUnique(true);
	m_behavior_Attribute_specification->setDerived(false);
	m_behavior_Attribute_specification->setOrdered(false);
	m_behavior_Attribute_specification->setContainment(false);
	m_behavior_Attribute_specification->setResolveProxies(true);
	m_behavior_Attribute_specification->setDefaultValueLiteral("");	
	m_behavior_Attribute_specification->setEOpposite(uml::umlPackage::eInstance()->getBehavioralFeature_Attribute_method());
	
	m_behavior_Attribute_specification->_setID(BEHAVIOR_ATTRIBUTE_SPECIFICATION);
	
	/*
	 * EOperations
	 */
	m_behavior_Operation_behavioredClassifier_Element->setName("behavioredClassifier");
	m_behavior_Operation_behavioredClassifier_Element->setEType(getBehavioredClassifier_Class());
	m_behavior_Operation_behavioredClassifier_Element->setLowerBound(0);
	m_behavior_Operation_behavioredClassifier_Element->setUpperBound(1);
	m_behavior_Operation_behavioredClassifier_Element->setUnique(true);
	m_behavior_Operation_behavioredClassifier_Element->setOrdered(false);
	
	m_behavior_Operation_behavioredClassifier_Element->_setID(BEHAVIOR_OPERATION_BEHAVIOREDCLASSIFIER_ELEMENT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_behavior_Operation_behavioredClassifier_Element);
		parameter->setName("from");
		parameter->setEType(getElement_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_behavior_Operation_getContext->setName("getContext");
	m_behavior_Operation_getContext->setEType(getBehavioredClassifier_Class());
	m_behavior_Operation_getContext->setLowerBound(0);
	m_behavior_Operation_getContext->setUpperBound(1);
	m_behavior_Operation_getContext->setUnique(true);
	m_behavior_Operation_getContext->setOrdered(false);
	
	m_behavior_Operation_getContext->_setID(BEHAVIOR_OPERATION_GETCONTEXT);
	
	
	m_behavior_Operation_inputParameters->setName("inputParameters");
	m_behavior_Operation_inputParameters->setEType(getParameter_Class());
	m_behavior_Operation_inputParameters->setLowerBound(0);
	m_behavior_Operation_inputParameters->setUpperBound(-1);
	m_behavior_Operation_inputParameters->setUnique(true);
	m_behavior_Operation_inputParameters->setOrdered(true);
	
	m_behavior_Operation_inputParameters->_setID(BEHAVIOR_OPERATION_INPUTPARAMETERS);
	
	
	m_behavior_Operation_outputParameters->setName("outputParameters");
	m_behavior_Operation_outputParameters->setEType(getParameter_Class());
	m_behavior_Operation_outputParameters->setLowerBound(0);
	m_behavior_Operation_outputParameters->setUpperBound(-1);
	m_behavior_Operation_outputParameters->setUnique(true);
	m_behavior_Operation_outputParameters->setOrdered(true);
	
	m_behavior_Operation_outputParameters->_setID(BEHAVIOR_OPERATION_OUTPUTPARAMETERS);
	
	
	
}

void umlPackageImpl::initializeBehaviorExecutionSpecificationContent()
{
	m_behaviorExecutionSpecification_Class->setName("BehaviorExecutionSpecification");
	m_behaviorExecutionSpecification_Class->setAbstract(false);
	m_behaviorExecutionSpecification_Class->setInterface(false);
	
	m_behaviorExecutionSpecification_Class->_setID(BEHAVIOREXECUTIONSPECIFICATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_behaviorExecutionSpecification_Attribute_behavior->setName("behavior");
	m_behaviorExecutionSpecification_Attribute_behavior->setEType(getBehavior_Class());
	m_behaviorExecutionSpecification_Attribute_behavior->setLowerBound(0);
	m_behaviorExecutionSpecification_Attribute_behavior->setUpperBound(1);
	m_behaviorExecutionSpecification_Attribute_behavior->setTransient(false);
	m_behaviorExecutionSpecification_Attribute_behavior->setVolatile(false);
	m_behaviorExecutionSpecification_Attribute_behavior->setChangeable(true);
	m_behaviorExecutionSpecification_Attribute_behavior->setUnsettable(false);
	m_behaviorExecutionSpecification_Attribute_behavior->setUnique(true);
	m_behaviorExecutionSpecification_Attribute_behavior->setDerived(false);
	m_behaviorExecutionSpecification_Attribute_behavior->setOrdered(false);
	m_behaviorExecutionSpecification_Attribute_behavior->setContainment(false);
	m_behaviorExecutionSpecification_Attribute_behavior->setResolveProxies(true);
	m_behaviorExecutionSpecification_Attribute_behavior->setDefaultValueLiteral("");	
	
	m_behaviorExecutionSpecification_Attribute_behavior->_setID(BEHAVIOREXECUTIONSPECIFICATION_ATTRIBUTE_BEHAVIOR);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeBehavioralFeatureContent()
{
	m_behavioralFeature_Class->setName("BehavioralFeature");
	m_behavioralFeature_Class->setAbstract(true);
	m_behavioralFeature_Class->setInterface(false);
	
	m_behavioralFeature_Class->_setID(BEHAVIORALFEATURE_CLASS);
	
	/*
	 * EAttributes
	 */
	m_behavioralFeature_Attribute_concurrency = getBehavioralFeature_Attribute_concurrency();
	m_behavioralFeature_Attribute_concurrency->setName("concurrency");
	m_behavioralFeature_Attribute_concurrency->setEType(getCallConcurrencyKind_Class());
	m_behavioralFeature_Attribute_concurrency->setLowerBound(1);
	m_behavioralFeature_Attribute_concurrency->setUpperBound(1);
	m_behavioralFeature_Attribute_concurrency->setTransient(false);
	m_behavioralFeature_Attribute_concurrency->setVolatile(false);
	m_behavioralFeature_Attribute_concurrency->setChangeable(true);
	m_behavioralFeature_Attribute_concurrency->setUnsettable(false);
	m_behavioralFeature_Attribute_concurrency->setUnique(true);
	m_behavioralFeature_Attribute_concurrency->setDerived(false);
	m_behavioralFeature_Attribute_concurrency->setOrdered(false);
	m_behavioralFeature_Attribute_concurrency->setID(false);
	m_behavioralFeature_Attribute_concurrency->setDefaultValueLiteral("sequential");
	
	m_behavioralFeature_Attribute_concurrency->_setID(BEHAVIORALFEATURE_ATTRIBUTE_CONCURRENCY);
	m_behavioralFeature_Attribute_isAbstract = getBehavioralFeature_Attribute_isAbstract();
	m_behavioralFeature_Attribute_isAbstract->setName("isAbstract");
	m_behavioralFeature_Attribute_isAbstract->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_behavioralFeature_Attribute_isAbstract->setLowerBound(1);
	m_behavioralFeature_Attribute_isAbstract->setUpperBound(1);
	m_behavioralFeature_Attribute_isAbstract->setTransient(false);
	m_behavioralFeature_Attribute_isAbstract->setVolatile(false);
	m_behavioralFeature_Attribute_isAbstract->setChangeable(true);
	m_behavioralFeature_Attribute_isAbstract->setUnsettable(false);
	m_behavioralFeature_Attribute_isAbstract->setUnique(true);
	m_behavioralFeature_Attribute_isAbstract->setDerived(false);
	m_behavioralFeature_Attribute_isAbstract->setOrdered(false);
	m_behavioralFeature_Attribute_isAbstract->setID(false);
	m_behavioralFeature_Attribute_isAbstract->setDefaultValueLiteral("false");
	
	m_behavioralFeature_Attribute_isAbstract->_setID(BEHAVIORALFEATURE_ATTRIBUTE_ISABSTRACT);
	
	/*
	 * EReferences
	 */
	m_behavioralFeature_Attribute_method->setName("method");
	m_behavioralFeature_Attribute_method->setEType(getBehavior_Class());
	m_behavioralFeature_Attribute_method->setLowerBound(0);
	m_behavioralFeature_Attribute_method->setUpperBound(-1);
	m_behavioralFeature_Attribute_method->setTransient(false);
	m_behavioralFeature_Attribute_method->setVolatile(false);
	m_behavioralFeature_Attribute_method->setChangeable(true);
	m_behavioralFeature_Attribute_method->setUnsettable(false);
	m_behavioralFeature_Attribute_method->setUnique(true);
	m_behavioralFeature_Attribute_method->setDerived(false);
	m_behavioralFeature_Attribute_method->setOrdered(false);
	m_behavioralFeature_Attribute_method->setContainment(false);
	m_behavioralFeature_Attribute_method->setResolveProxies(true);
	m_behavioralFeature_Attribute_method->setDefaultValueLiteral("");	
	m_behavioralFeature_Attribute_method->setEOpposite(uml::umlPackage::eInstance()->getBehavior_Attribute_specification());
	
	m_behavioralFeature_Attribute_method->_setID(BEHAVIORALFEATURE_ATTRIBUTE_METHOD);
	m_behavioralFeature_Attribute_ownedParameter->setName("ownedParameter");
	m_behavioralFeature_Attribute_ownedParameter->setEType(getParameter_Class());
	m_behavioralFeature_Attribute_ownedParameter->setLowerBound(0);
	m_behavioralFeature_Attribute_ownedParameter->setUpperBound(-1);
	m_behavioralFeature_Attribute_ownedParameter->setTransient(false);
	m_behavioralFeature_Attribute_ownedParameter->setVolatile(false);
	m_behavioralFeature_Attribute_ownedParameter->setChangeable(true);
	m_behavioralFeature_Attribute_ownedParameter->setUnsettable(false);
	m_behavioralFeature_Attribute_ownedParameter->setUnique(true);
	m_behavioralFeature_Attribute_ownedParameter->setDerived(false);
	m_behavioralFeature_Attribute_ownedParameter->setOrdered(true);
	m_behavioralFeature_Attribute_ownedParameter->setContainment(true);
	m_behavioralFeature_Attribute_ownedParameter->setResolveProxies(true);
	m_behavioralFeature_Attribute_ownedParameter->setDefaultValueLiteral("");	
	
	m_behavioralFeature_Attribute_ownedParameter->_setID(BEHAVIORALFEATURE_ATTRIBUTE_OWNEDPARAMETER);
	m_behavioralFeature_Attribute_ownedParameterSet->setName("ownedParameterSet");
	m_behavioralFeature_Attribute_ownedParameterSet->setEType(getParameterSet_Class());
	m_behavioralFeature_Attribute_ownedParameterSet->setLowerBound(0);
	m_behavioralFeature_Attribute_ownedParameterSet->setUpperBound(-1);
	m_behavioralFeature_Attribute_ownedParameterSet->setTransient(false);
	m_behavioralFeature_Attribute_ownedParameterSet->setVolatile(false);
	m_behavioralFeature_Attribute_ownedParameterSet->setChangeable(true);
	m_behavioralFeature_Attribute_ownedParameterSet->setUnsettable(false);
	m_behavioralFeature_Attribute_ownedParameterSet->setUnique(true);
	m_behavioralFeature_Attribute_ownedParameterSet->setDerived(false);
	m_behavioralFeature_Attribute_ownedParameterSet->setOrdered(false);
	m_behavioralFeature_Attribute_ownedParameterSet->setContainment(true);
	m_behavioralFeature_Attribute_ownedParameterSet->setResolveProxies(true);
	m_behavioralFeature_Attribute_ownedParameterSet->setDefaultValueLiteral("");	
	
	m_behavioralFeature_Attribute_ownedParameterSet->_setID(BEHAVIORALFEATURE_ATTRIBUTE_OWNEDPARAMETERSET);
	m_behavioralFeature_Attribute_raisedException->setName("raisedException");
	m_behavioralFeature_Attribute_raisedException->setEType(getType_Class());
	m_behavioralFeature_Attribute_raisedException->setLowerBound(0);
	m_behavioralFeature_Attribute_raisedException->setUpperBound(-1);
	m_behavioralFeature_Attribute_raisedException->setTransient(false);
	m_behavioralFeature_Attribute_raisedException->setVolatile(false);
	m_behavioralFeature_Attribute_raisedException->setChangeable(true);
	m_behavioralFeature_Attribute_raisedException->setUnsettable(false);
	m_behavioralFeature_Attribute_raisedException->setUnique(true);
	m_behavioralFeature_Attribute_raisedException->setDerived(false);
	m_behavioralFeature_Attribute_raisedException->setOrdered(false);
	m_behavioralFeature_Attribute_raisedException->setContainment(false);
	m_behavioralFeature_Attribute_raisedException->setResolveProxies(true);
	m_behavioralFeature_Attribute_raisedException->setDefaultValueLiteral("");	
	
	m_behavioralFeature_Attribute_raisedException->_setID(BEHAVIORALFEATURE_ATTRIBUTE_RAISEDEXCEPTION);
	
	/*
	 * EOperations
	 */
	m_behavioralFeature_Operation_createReturnResult_String_Type->setName("createReturnResult");
	m_behavioralFeature_Operation_createReturnResult_String_Type->setEType(getParameter_Class());
	m_behavioralFeature_Operation_createReturnResult_String_Type->setLowerBound(1);
	m_behavioralFeature_Operation_createReturnResult_String_Type->setUpperBound(1);
	m_behavioralFeature_Operation_createReturnResult_String_Type->setUnique(true);
	m_behavioralFeature_Operation_createReturnResult_String_Type->setOrdered(false);
	
	m_behavioralFeature_Operation_createReturnResult_String_Type->_setID(BEHAVIORALFEATURE_OPERATION_CREATERETURNRESULT_STRING_TYPE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_behavioralFeature_Operation_createReturnResult_String_Type);
		parameter->setName("name");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_behavioralFeature_Operation_createReturnResult_String_Type);
		parameter->setName("type");
		parameter->setEType(getType_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_behavioralFeature_Operation_inputParameters->setName("inputParameters");
	m_behavioralFeature_Operation_inputParameters->setEType(getParameter_Class());
	m_behavioralFeature_Operation_inputParameters->setLowerBound(0);
	m_behavioralFeature_Operation_inputParameters->setUpperBound(-1);
	m_behavioralFeature_Operation_inputParameters->setUnique(true);
	m_behavioralFeature_Operation_inputParameters->setOrdered(true);
	
	m_behavioralFeature_Operation_inputParameters->_setID(BEHAVIORALFEATURE_OPERATION_INPUTPARAMETERS);
	
	
	m_behavioralFeature_Operation_outputParameters->setName("outputParameters");
	m_behavioralFeature_Operation_outputParameters->setEType(getParameter_Class());
	m_behavioralFeature_Operation_outputParameters->setLowerBound(0);
	m_behavioralFeature_Operation_outputParameters->setUpperBound(-1);
	m_behavioralFeature_Operation_outputParameters->setUnique(true);
	m_behavioralFeature_Operation_outputParameters->setOrdered(true);
	
	m_behavioralFeature_Operation_outputParameters->_setID(BEHAVIORALFEATURE_OPERATION_OUTPUTPARAMETERS);
	
	
	
}

void umlPackageImpl::initializeBehavioredClassifierContent()
{
	m_behavioredClassifier_Class->setName("BehavioredClassifier");
	m_behavioredClassifier_Class->setAbstract(true);
	m_behavioredClassifier_Class->setInterface(false);
	
	m_behavioredClassifier_Class->_setID(BEHAVIOREDCLASSIFIER_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_behavioredClassifier_Attribute_classifierBehavior->setName("classifierBehavior");
	m_behavioredClassifier_Attribute_classifierBehavior->setEType(getBehavior_Class());
	m_behavioredClassifier_Attribute_classifierBehavior->setLowerBound(0);
	m_behavioredClassifier_Attribute_classifierBehavior->setUpperBound(1);
	m_behavioredClassifier_Attribute_classifierBehavior->setTransient(false);
	m_behavioredClassifier_Attribute_classifierBehavior->setVolatile(false);
	m_behavioredClassifier_Attribute_classifierBehavior->setChangeable(true);
	m_behavioredClassifier_Attribute_classifierBehavior->setUnsettable(false);
	m_behavioredClassifier_Attribute_classifierBehavior->setUnique(true);
	m_behavioredClassifier_Attribute_classifierBehavior->setDerived(false);
	m_behavioredClassifier_Attribute_classifierBehavior->setOrdered(false);
	m_behavioredClassifier_Attribute_classifierBehavior->setContainment(false);
	m_behavioredClassifier_Attribute_classifierBehavior->setResolveProxies(true);
	m_behavioredClassifier_Attribute_classifierBehavior->setDefaultValueLiteral("");	
	
	m_behavioredClassifier_Attribute_classifierBehavior->_setID(BEHAVIOREDCLASSIFIER_ATTRIBUTE_CLASSIFIERBEHAVIOR);
	m_behavioredClassifier_Attribute_interfaceRealization->setName("interfaceRealization");
	m_behavioredClassifier_Attribute_interfaceRealization->setEType(getInterfaceRealization_Class());
	m_behavioredClassifier_Attribute_interfaceRealization->setLowerBound(0);
	m_behavioredClassifier_Attribute_interfaceRealization->setUpperBound(-1);
	m_behavioredClassifier_Attribute_interfaceRealization->setTransient(false);
	m_behavioredClassifier_Attribute_interfaceRealization->setVolatile(false);
	m_behavioredClassifier_Attribute_interfaceRealization->setChangeable(true);
	m_behavioredClassifier_Attribute_interfaceRealization->setUnsettable(false);
	m_behavioredClassifier_Attribute_interfaceRealization->setUnique(true);
	m_behavioredClassifier_Attribute_interfaceRealization->setDerived(false);
	m_behavioredClassifier_Attribute_interfaceRealization->setOrdered(false);
	m_behavioredClassifier_Attribute_interfaceRealization->setContainment(true);
	m_behavioredClassifier_Attribute_interfaceRealization->setResolveProxies(true);
	m_behavioredClassifier_Attribute_interfaceRealization->setDefaultValueLiteral("");	
	m_behavioredClassifier_Attribute_interfaceRealization->setEOpposite(uml::umlPackage::eInstance()->getInterfaceRealization_Attribute_implementingClassifier());
	
	m_behavioredClassifier_Attribute_interfaceRealization->_setID(BEHAVIOREDCLASSIFIER_ATTRIBUTE_INTERFACEREALIZATION);
	m_behavioredClassifier_Attribute_ownedBehavior->setName("ownedBehavior");
	m_behavioredClassifier_Attribute_ownedBehavior->setEType(getBehavior_Class());
	m_behavioredClassifier_Attribute_ownedBehavior->setLowerBound(0);
	m_behavioredClassifier_Attribute_ownedBehavior->setUpperBound(-1);
	m_behavioredClassifier_Attribute_ownedBehavior->setTransient(false);
	m_behavioredClassifier_Attribute_ownedBehavior->setVolatile(false);
	m_behavioredClassifier_Attribute_ownedBehavior->setChangeable(true);
	m_behavioredClassifier_Attribute_ownedBehavior->setUnsettable(false);
	m_behavioredClassifier_Attribute_ownedBehavior->setUnique(true);
	m_behavioredClassifier_Attribute_ownedBehavior->setDerived(false);
	m_behavioredClassifier_Attribute_ownedBehavior->setOrdered(false);
	m_behavioredClassifier_Attribute_ownedBehavior->setContainment(true);
	m_behavioredClassifier_Attribute_ownedBehavior->setResolveProxies(true);
	m_behavioredClassifier_Attribute_ownedBehavior->setDefaultValueLiteral("");	
	m_behavioredClassifier_Attribute_ownedBehavior->setEOpposite(uml::umlPackage::eInstance()->getBehavior_Attribute_behavioredClassifier());
	
	m_behavioredClassifier_Attribute_ownedBehavior->_setID(BEHAVIOREDCLASSIFIER_ATTRIBUTE_OWNEDBEHAVIOR);
	
	/*
	 * EOperations
	 */
	m_behavioredClassifier_Operation_getAllImplementedInterfaces->setName("getAllImplementedInterfaces");
	m_behavioredClassifier_Operation_getAllImplementedInterfaces->setEType(getInterface_Class());
	m_behavioredClassifier_Operation_getAllImplementedInterfaces->setLowerBound(0);
	m_behavioredClassifier_Operation_getAllImplementedInterfaces->setUpperBound(-1);
	m_behavioredClassifier_Operation_getAllImplementedInterfaces->setUnique(true);
	m_behavioredClassifier_Operation_getAllImplementedInterfaces->setOrdered(false);
	
	m_behavioredClassifier_Operation_getAllImplementedInterfaces->_setID(BEHAVIOREDCLASSIFIER_OPERATION_GETALLIMPLEMENTEDINTERFACES);
	
	
	m_behavioredClassifier_Operation_getImplementedInterfaces->setName("getImplementedInterfaces");
	m_behavioredClassifier_Operation_getImplementedInterfaces->setEType(getInterface_Class());
	m_behavioredClassifier_Operation_getImplementedInterfaces->setLowerBound(0);
	m_behavioredClassifier_Operation_getImplementedInterfaces->setUpperBound(-1);
	m_behavioredClassifier_Operation_getImplementedInterfaces->setUnique(true);
	m_behavioredClassifier_Operation_getImplementedInterfaces->setOrdered(false);
	
	m_behavioredClassifier_Operation_getImplementedInterfaces->_setID(BEHAVIOREDCLASSIFIER_OPERATION_GETIMPLEMENTEDINTERFACES);
	
	
	
}

void umlPackageImpl::initializeBroadcastSignalActionContent()
{
	m_broadcastSignalAction_Class->setName("BroadcastSignalAction");
	m_broadcastSignalAction_Class->setAbstract(false);
	m_broadcastSignalAction_Class->setInterface(false);
	
	m_broadcastSignalAction_Class->_setID(BROADCASTSIGNALACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_broadcastSignalAction_Attribute_signal->setName("signal");
	m_broadcastSignalAction_Attribute_signal->setEType(getSignal_Class());
	m_broadcastSignalAction_Attribute_signal->setLowerBound(1);
	m_broadcastSignalAction_Attribute_signal->setUpperBound(1);
	m_broadcastSignalAction_Attribute_signal->setTransient(false);
	m_broadcastSignalAction_Attribute_signal->setVolatile(false);
	m_broadcastSignalAction_Attribute_signal->setChangeable(true);
	m_broadcastSignalAction_Attribute_signal->setUnsettable(false);
	m_broadcastSignalAction_Attribute_signal->setUnique(true);
	m_broadcastSignalAction_Attribute_signal->setDerived(false);
	m_broadcastSignalAction_Attribute_signal->setOrdered(false);
	m_broadcastSignalAction_Attribute_signal->setContainment(false);
	m_broadcastSignalAction_Attribute_signal->setResolveProxies(true);
	m_broadcastSignalAction_Attribute_signal->setDefaultValueLiteral("");	
	
	m_broadcastSignalAction_Attribute_signal->_setID(BROADCASTSIGNALACTION_ATTRIBUTE_SIGNAL);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeCallActionContent()
{
	m_callAction_Class->setName("CallAction");
	m_callAction_Class->setAbstract(true);
	m_callAction_Class->setInterface(false);
	
	m_callAction_Class->_setID(CALLACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	m_callAction_Attribute_isSynchronous = getCallAction_Attribute_isSynchronous();
	m_callAction_Attribute_isSynchronous->setName("isSynchronous");
	m_callAction_Attribute_isSynchronous->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_callAction_Attribute_isSynchronous->setLowerBound(1);
	m_callAction_Attribute_isSynchronous->setUpperBound(1);
	m_callAction_Attribute_isSynchronous->setTransient(false);
	m_callAction_Attribute_isSynchronous->setVolatile(false);
	m_callAction_Attribute_isSynchronous->setChangeable(true);
	m_callAction_Attribute_isSynchronous->setUnsettable(false);
	m_callAction_Attribute_isSynchronous->setUnique(true);
	m_callAction_Attribute_isSynchronous->setDerived(false);
	m_callAction_Attribute_isSynchronous->setOrdered(false);
	m_callAction_Attribute_isSynchronous->setID(false);
	m_callAction_Attribute_isSynchronous->setDefaultValueLiteral("true");
	
	m_callAction_Attribute_isSynchronous->_setID(CALLACTION_ATTRIBUTE_ISSYNCHRONOUS);
	
	/*
	 * EReferences
	 */
	m_callAction_Attribute_result->setName("result");
	m_callAction_Attribute_result->setEType(getOutputPin_Class());
	m_callAction_Attribute_result->setLowerBound(0);
	m_callAction_Attribute_result->setUpperBound(-1);
	m_callAction_Attribute_result->setTransient(false);
	m_callAction_Attribute_result->setVolatile(false);
	m_callAction_Attribute_result->setChangeable(true);
	m_callAction_Attribute_result->setUnsettable(false);
	m_callAction_Attribute_result->setUnique(true);
	m_callAction_Attribute_result->setDerived(false);
	m_callAction_Attribute_result->setOrdered(true);
	m_callAction_Attribute_result->setContainment(true);
	m_callAction_Attribute_result->setResolveProxies(true);
	m_callAction_Attribute_result->setDefaultValueLiteral("");	
	m_callAction_Attribute_result->setEOpposite(uml::umlPackage::eInstance()->getOutputPin_Attribute_callAction());
	
	m_callAction_Attribute_result->_setID(CALLACTION_ATTRIBUTE_RESULT);
	
	/*
	 * EOperations
	 */
	m_callAction_Operation_inputParameters->setName("inputParameters");
	m_callAction_Operation_inputParameters->setEType(getParameter_Class());
	m_callAction_Operation_inputParameters->setLowerBound(0);
	m_callAction_Operation_inputParameters->setUpperBound(-1);
	m_callAction_Operation_inputParameters->setUnique(true);
	m_callAction_Operation_inputParameters->setOrdered(true);
	
	m_callAction_Operation_inputParameters->_setID(CALLACTION_OPERATION_INPUTPARAMETERS);
	
	
	m_callAction_Operation_outputParameters->setName("outputParameters");
	m_callAction_Operation_outputParameters->setEType(getParameter_Class());
	m_callAction_Operation_outputParameters->setLowerBound(0);
	m_callAction_Operation_outputParameters->setUpperBound(-1);
	m_callAction_Operation_outputParameters->setUnique(true);
	m_callAction_Operation_outputParameters->setOrdered(true);
	
	m_callAction_Operation_outputParameters->_setID(CALLACTION_OPERATION_OUTPUTPARAMETERS);
	
	
	
}

void umlPackageImpl::initializeCallBehaviorActionContent()
{
	m_callBehaviorAction_Class->setName("CallBehaviorAction");
	m_callBehaviorAction_Class->setAbstract(false);
	m_callBehaviorAction_Class->setInterface(false);
	
	m_callBehaviorAction_Class->_setID(CALLBEHAVIORACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_callBehaviorAction_Attribute_behavior->setName("behavior");
	m_callBehaviorAction_Attribute_behavior->setEType(getBehavior_Class());
	m_callBehaviorAction_Attribute_behavior->setLowerBound(1);
	m_callBehaviorAction_Attribute_behavior->setUpperBound(1);
	m_callBehaviorAction_Attribute_behavior->setTransient(false);
	m_callBehaviorAction_Attribute_behavior->setVolatile(false);
	m_callBehaviorAction_Attribute_behavior->setChangeable(true);
	m_callBehaviorAction_Attribute_behavior->setUnsettable(false);
	m_callBehaviorAction_Attribute_behavior->setUnique(true);
	m_callBehaviorAction_Attribute_behavior->setDerived(false);
	m_callBehaviorAction_Attribute_behavior->setOrdered(false);
	m_callBehaviorAction_Attribute_behavior->setContainment(false);
	m_callBehaviorAction_Attribute_behavior->setResolveProxies(true);
	m_callBehaviorAction_Attribute_behavior->setDefaultValueLiteral("");	
	
	m_callBehaviorAction_Attribute_behavior->_setID(CALLBEHAVIORACTION_ATTRIBUTE_BEHAVIOR);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeCallEventContent()
{
	m_callEvent_Class->setName("CallEvent");
	m_callEvent_Class->setAbstract(false);
	m_callEvent_Class->setInterface(false);
	
	m_callEvent_Class->_setID(CALLEVENT_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_callEvent_Attribute_operation->setName("operation");
	m_callEvent_Attribute_operation->setEType(getOperation_Class());
	m_callEvent_Attribute_operation->setLowerBound(1);
	m_callEvent_Attribute_operation->setUpperBound(1);
	m_callEvent_Attribute_operation->setTransient(false);
	m_callEvent_Attribute_operation->setVolatile(false);
	m_callEvent_Attribute_operation->setChangeable(true);
	m_callEvent_Attribute_operation->setUnsettable(false);
	m_callEvent_Attribute_operation->setUnique(true);
	m_callEvent_Attribute_operation->setDerived(false);
	m_callEvent_Attribute_operation->setOrdered(false);
	m_callEvent_Attribute_operation->setContainment(false);
	m_callEvent_Attribute_operation->setResolveProxies(true);
	m_callEvent_Attribute_operation->setDefaultValueLiteral("");	
	
	m_callEvent_Attribute_operation->_setID(CALLEVENT_ATTRIBUTE_OPERATION);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeCallOperationActionContent()
{
	m_callOperationAction_Class->setName("CallOperationAction");
	m_callOperationAction_Class->setAbstract(false);
	m_callOperationAction_Class->setInterface(false);
	
	m_callOperationAction_Class->_setID(CALLOPERATIONACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_callOperationAction_Attribute_operation->setName("operation");
	m_callOperationAction_Attribute_operation->setEType(getOperation_Class());
	m_callOperationAction_Attribute_operation->setLowerBound(1);
	m_callOperationAction_Attribute_operation->setUpperBound(1);
	m_callOperationAction_Attribute_operation->setTransient(false);
	m_callOperationAction_Attribute_operation->setVolatile(false);
	m_callOperationAction_Attribute_operation->setChangeable(true);
	m_callOperationAction_Attribute_operation->setUnsettable(false);
	m_callOperationAction_Attribute_operation->setUnique(true);
	m_callOperationAction_Attribute_operation->setDerived(false);
	m_callOperationAction_Attribute_operation->setOrdered(false);
	m_callOperationAction_Attribute_operation->setContainment(false);
	m_callOperationAction_Attribute_operation->setResolveProxies(true);
	m_callOperationAction_Attribute_operation->setDefaultValueLiteral("");	
	
	m_callOperationAction_Attribute_operation->_setID(CALLOPERATIONACTION_ATTRIBUTE_OPERATION);
	m_callOperationAction_Attribute_target->setName("target");
	m_callOperationAction_Attribute_target->setEType(getInputPin_Class());
	m_callOperationAction_Attribute_target->setLowerBound(1);
	m_callOperationAction_Attribute_target->setUpperBound(1);
	m_callOperationAction_Attribute_target->setTransient(false);
	m_callOperationAction_Attribute_target->setVolatile(false);
	m_callOperationAction_Attribute_target->setChangeable(true);
	m_callOperationAction_Attribute_target->setUnsettable(false);
	m_callOperationAction_Attribute_target->setUnique(true);
	m_callOperationAction_Attribute_target->setDerived(false);
	m_callOperationAction_Attribute_target->setOrdered(false);
	m_callOperationAction_Attribute_target->setContainment(true);
	m_callOperationAction_Attribute_target->setResolveProxies(true);
	m_callOperationAction_Attribute_target->setDefaultValueLiteral("");	
	m_callOperationAction_Attribute_target->setEOpposite(uml::umlPackage::eInstance()->getInputPin_Attribute_callOperationAction());
	
	m_callOperationAction_Attribute_target->_setID(CALLOPERATIONACTION_ATTRIBUTE_TARGET);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeCentralBufferNodeContent()
{
	m_centralBufferNode_Class->setName("CentralBufferNode");
	m_centralBufferNode_Class->setAbstract(false);
	m_centralBufferNode_Class->setInterface(false);
	
	m_centralBufferNode_Class->_setID(CENTRALBUFFERNODE_CLASS);
	
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

void umlPackageImpl::initializeChangeEventContent()
{
	m_changeEvent_Class->setName("ChangeEvent");
	m_changeEvent_Class->setAbstract(false);
	m_changeEvent_Class->setInterface(false);
	
	m_changeEvent_Class->_setID(CHANGEEVENT_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_changeEvent_Attribute_changeExpression->setName("changeExpression");
	m_changeEvent_Attribute_changeExpression->setEType(getValueSpecification_Class());
	m_changeEvent_Attribute_changeExpression->setLowerBound(1);
	m_changeEvent_Attribute_changeExpression->setUpperBound(1);
	m_changeEvent_Attribute_changeExpression->setTransient(false);
	m_changeEvent_Attribute_changeExpression->setVolatile(false);
	m_changeEvent_Attribute_changeExpression->setChangeable(true);
	m_changeEvent_Attribute_changeExpression->setUnsettable(false);
	m_changeEvent_Attribute_changeExpression->setUnique(true);
	m_changeEvent_Attribute_changeExpression->setDerived(false);
	m_changeEvent_Attribute_changeExpression->setOrdered(false);
	m_changeEvent_Attribute_changeExpression->setContainment(true);
	m_changeEvent_Attribute_changeExpression->setResolveProxies(true);
	m_changeEvent_Attribute_changeExpression->setDefaultValueLiteral("");	
	
	m_changeEvent_Attribute_changeExpression->_setID(CHANGEEVENT_ATTRIBUTE_CHANGEEXPRESSION);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeClassContent()
{
	m_class_Class->setName("Class");
	m_class_Class->setAbstract(false);
	m_class_Class->setInterface(false);
	
	m_class_Class->_setID(CLASS_CLASS);
	
	/*
	 * EAttributes
	 */
	m_class_Attribute_isActive = getClass_Attribute_isActive();
	m_class_Attribute_isActive->setName("isActive");
	m_class_Attribute_isActive->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_class_Attribute_isActive->setLowerBound(1);
	m_class_Attribute_isActive->setUpperBound(1);
	m_class_Attribute_isActive->setTransient(false);
	m_class_Attribute_isActive->setVolatile(false);
	m_class_Attribute_isActive->setChangeable(true);
	m_class_Attribute_isActive->setUnsettable(false);
	m_class_Attribute_isActive->setUnique(true);
	m_class_Attribute_isActive->setDerived(false);
	m_class_Attribute_isActive->setOrdered(false);
	m_class_Attribute_isActive->setID(false);
	m_class_Attribute_isActive->setDefaultValueLiteral("false");
	
	m_class_Attribute_isActive->_setID(CLASS_ATTRIBUTE_ISACTIVE);
	
	/*
	 * EReferences
	 */
	m_class_Attribute_extension->setName("extension");
	m_class_Attribute_extension->setEType(getExtension_Class());
	m_class_Attribute_extension->setLowerBound(0);
	m_class_Attribute_extension->setUpperBound(-1);
	m_class_Attribute_extension->setTransient(true);
	m_class_Attribute_extension->setVolatile(true);
	m_class_Attribute_extension->setChangeable(false);
	m_class_Attribute_extension->setUnsettable(false);
	m_class_Attribute_extension->setUnique(true);
	m_class_Attribute_extension->setDerived(true);
	m_class_Attribute_extension->setOrdered(false);
	m_class_Attribute_extension->setContainment(false);
	m_class_Attribute_extension->setResolveProxies(true);
	m_class_Attribute_extension->setDefaultValueLiteral("");	
	m_class_Attribute_extension->setEOpposite(uml::umlPackage::eInstance()->getExtension_Attribute_metaclass());
	
	m_class_Attribute_extension->_setID(CLASS_ATTRIBUTE_EXTENSION);
	m_class_Attribute_nestedClassifier->setName("nestedClassifier");
	m_class_Attribute_nestedClassifier->setEType(getClassifier_Class());
	m_class_Attribute_nestedClassifier->setLowerBound(0);
	m_class_Attribute_nestedClassifier->setUpperBound(-1);
	m_class_Attribute_nestedClassifier->setTransient(false);
	m_class_Attribute_nestedClassifier->setVolatile(false);
	m_class_Attribute_nestedClassifier->setChangeable(true);
	m_class_Attribute_nestedClassifier->setUnsettable(false);
	m_class_Attribute_nestedClassifier->setUnique(true);
	m_class_Attribute_nestedClassifier->setDerived(false);
	m_class_Attribute_nestedClassifier->setOrdered(true);
	m_class_Attribute_nestedClassifier->setContainment(true);
	m_class_Attribute_nestedClassifier->setResolveProxies(true);
	m_class_Attribute_nestedClassifier->setDefaultValueLiteral("");	
	
	m_class_Attribute_nestedClassifier->_setID(CLASS_ATTRIBUTE_NESTEDCLASSIFIER);
	m_class_Attribute_ownedAttribute->setName("ownedAttribute");
	m_class_Attribute_ownedAttribute->setEType(getProperty_Class());
	m_class_Attribute_ownedAttribute->setLowerBound(0);
	m_class_Attribute_ownedAttribute->setUpperBound(-1);
	m_class_Attribute_ownedAttribute->setTransient(false);
	m_class_Attribute_ownedAttribute->setVolatile(false);
	m_class_Attribute_ownedAttribute->setChangeable(true);
	m_class_Attribute_ownedAttribute->setUnsettable(false);
	m_class_Attribute_ownedAttribute->setUnique(true);
	m_class_Attribute_ownedAttribute->setDerived(false);
	m_class_Attribute_ownedAttribute->setOrdered(true);
	m_class_Attribute_ownedAttribute->setContainment(true);
	m_class_Attribute_ownedAttribute->setResolveProxies(true);
	m_class_Attribute_ownedAttribute->setDefaultValueLiteral("");	
	m_class_Attribute_ownedAttribute->setEOpposite(uml::umlPackage::eInstance()->getProperty_Attribute_class());
	
	m_class_Attribute_ownedAttribute->_setID(CLASS_ATTRIBUTE_OWNEDATTRIBUTE);
	m_class_Attribute_ownedOperation->setName("ownedOperation");
	m_class_Attribute_ownedOperation->setEType(getOperation_Class());
	m_class_Attribute_ownedOperation->setLowerBound(0);
	m_class_Attribute_ownedOperation->setUpperBound(-1);
	m_class_Attribute_ownedOperation->setTransient(false);
	m_class_Attribute_ownedOperation->setVolatile(false);
	m_class_Attribute_ownedOperation->setChangeable(true);
	m_class_Attribute_ownedOperation->setUnsettable(false);
	m_class_Attribute_ownedOperation->setUnique(true);
	m_class_Attribute_ownedOperation->setDerived(false);
	m_class_Attribute_ownedOperation->setOrdered(true);
	m_class_Attribute_ownedOperation->setContainment(true);
	m_class_Attribute_ownedOperation->setResolveProxies(true);
	m_class_Attribute_ownedOperation->setDefaultValueLiteral("");	
	m_class_Attribute_ownedOperation->setEOpposite(uml::umlPackage::eInstance()->getOperation_Attribute_class());
	
	m_class_Attribute_ownedOperation->_setID(CLASS_ATTRIBUTE_OWNEDOPERATION);
	m_class_Attribute_ownedReception->setName("ownedReception");
	m_class_Attribute_ownedReception->setEType(getReception_Class());
	m_class_Attribute_ownedReception->setLowerBound(0);
	m_class_Attribute_ownedReception->setUpperBound(-1);
	m_class_Attribute_ownedReception->setTransient(false);
	m_class_Attribute_ownedReception->setVolatile(false);
	m_class_Attribute_ownedReception->setChangeable(true);
	m_class_Attribute_ownedReception->setUnsettable(false);
	m_class_Attribute_ownedReception->setUnique(true);
	m_class_Attribute_ownedReception->setDerived(false);
	m_class_Attribute_ownedReception->setOrdered(false);
	m_class_Attribute_ownedReception->setContainment(true);
	m_class_Attribute_ownedReception->setResolveProxies(true);
	m_class_Attribute_ownedReception->setDefaultValueLiteral("");	
	
	m_class_Attribute_ownedReception->_setID(CLASS_ATTRIBUTE_OWNEDRECEPTION);
	m_class_Attribute_superClass->setName("superClass");
	m_class_Attribute_superClass->setEType(getClass_Class());
	m_class_Attribute_superClass->setLowerBound(0);
	m_class_Attribute_superClass->setUpperBound(-1);
	m_class_Attribute_superClass->setTransient(true);
	m_class_Attribute_superClass->setVolatile(true);
	m_class_Attribute_superClass->setChangeable(true);
	m_class_Attribute_superClass->setUnsettable(false);
	m_class_Attribute_superClass->setUnique(true);
	m_class_Attribute_superClass->setDerived(true);
	m_class_Attribute_superClass->setOrdered(false);
	m_class_Attribute_superClass->setContainment(false);
	m_class_Attribute_superClass->setResolveProxies(true);
	m_class_Attribute_superClass->setDefaultValueLiteral("");	
	
	m_class_Attribute_superClass->_setID(CLASS_ATTRIBUTE_SUPERCLASS);
	
	/*
	 * EOperations
	 */
	m_class_Operation_getAllOperations->setName("getAllOperations");
	m_class_Operation_getAllOperations->setEType(getOperation_Class());
	m_class_Operation_getAllOperations->setLowerBound(0);
	m_class_Operation_getAllOperations->setUpperBound(-1);
	m_class_Operation_getAllOperations->setUnique(true);
	m_class_Operation_getAllOperations->setOrdered(false);
	
	m_class_Operation_getAllOperations->_setID(CLASS_OPERATION_GETALLOPERATIONS);
	
	
	m_class_Operation_getExtensions->setName("getExtensions");
	m_class_Operation_getExtensions->setEType(getExtension_Class());
	m_class_Operation_getExtensions->setLowerBound(0);
	m_class_Operation_getExtensions->setUpperBound(-1);
	m_class_Operation_getExtensions->setUnique(true);
	m_class_Operation_getExtensions->setOrdered(false);
	
	m_class_Operation_getExtensions->_setID(CLASS_OPERATION_GETEXTENSIONS);
	
	
	m_class_Operation_getSuperClasses->setName("getSuperClasses");
	m_class_Operation_getSuperClasses->setEType(getClass_Class());
	m_class_Operation_getSuperClasses->setLowerBound(0);
	m_class_Operation_getSuperClasses->setUpperBound(-1);
	m_class_Operation_getSuperClasses->setUnique(true);
	m_class_Operation_getSuperClasses->setOrdered(false);
	
	m_class_Operation_getSuperClasses->_setID(CLASS_OPERATION_GETSUPERCLASSES);
	
	
	m_class_Operation_isMetaclass->setName("isMetaclass");
	m_class_Operation_isMetaclass->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_class_Operation_isMetaclass->setLowerBound(1);
	m_class_Operation_isMetaclass->setUpperBound(1);
	m_class_Operation_isMetaclass->setUnique(true);
	m_class_Operation_isMetaclass->setOrdered(false);
	
	m_class_Operation_isMetaclass->_setID(CLASS_OPERATION_ISMETACLASS);
	
	
	
}

void umlPackageImpl::initializeClassifierContent()
{
	m_classifier_Class->setName("Classifier");
	m_classifier_Class->setAbstract(true);
	m_classifier_Class->setInterface(false);
	
	m_classifier_Class->_setID(CLASSIFIER_CLASS);
	
	/*
	 * EAttributes
	 */
	m_classifier_Attribute_isAbstract = getClassifier_Attribute_isAbstract();
	m_classifier_Attribute_isAbstract->setName("isAbstract");
	m_classifier_Attribute_isAbstract->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_classifier_Attribute_isAbstract->setLowerBound(1);
	m_classifier_Attribute_isAbstract->setUpperBound(1);
	m_classifier_Attribute_isAbstract->setTransient(false);
	m_classifier_Attribute_isAbstract->setVolatile(false);
	m_classifier_Attribute_isAbstract->setChangeable(true);
	m_classifier_Attribute_isAbstract->setUnsettable(false);
	m_classifier_Attribute_isAbstract->setUnique(true);
	m_classifier_Attribute_isAbstract->setDerived(false);
	m_classifier_Attribute_isAbstract->setOrdered(false);
	m_classifier_Attribute_isAbstract->setID(false);
	m_classifier_Attribute_isAbstract->setDefaultValueLiteral("false");
	
	m_classifier_Attribute_isAbstract->_setID(CLASSIFIER_ATTRIBUTE_ISABSTRACT);
	m_classifier_Attribute_isFinalSpecialization = getClassifier_Attribute_isFinalSpecialization();
	m_classifier_Attribute_isFinalSpecialization->setName("isFinalSpecialization");
	m_classifier_Attribute_isFinalSpecialization->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_classifier_Attribute_isFinalSpecialization->setLowerBound(1);
	m_classifier_Attribute_isFinalSpecialization->setUpperBound(1);
	m_classifier_Attribute_isFinalSpecialization->setTransient(false);
	m_classifier_Attribute_isFinalSpecialization->setVolatile(false);
	m_classifier_Attribute_isFinalSpecialization->setChangeable(true);
	m_classifier_Attribute_isFinalSpecialization->setUnsettable(false);
	m_classifier_Attribute_isFinalSpecialization->setUnique(true);
	m_classifier_Attribute_isFinalSpecialization->setDerived(false);
	m_classifier_Attribute_isFinalSpecialization->setOrdered(false);
	m_classifier_Attribute_isFinalSpecialization->setID(false);
	m_classifier_Attribute_isFinalSpecialization->setDefaultValueLiteral("false");
	
	m_classifier_Attribute_isFinalSpecialization->_setID(CLASSIFIER_ATTRIBUTE_ISFINALSPECIALIZATION);
	
	/*
	 * EReferences
	 */
	m_classifier_Attribute_attribute->setName("attribute");
	m_classifier_Attribute_attribute->setEType(getProperty_Class());
	m_classifier_Attribute_attribute->setLowerBound(0);
	m_classifier_Attribute_attribute->setUpperBound(-1);
	m_classifier_Attribute_attribute->setTransient(true);
	m_classifier_Attribute_attribute->setVolatile(true);
	m_classifier_Attribute_attribute->setChangeable(false);
	m_classifier_Attribute_attribute->setUnsettable(false);
	m_classifier_Attribute_attribute->setUnique(true);
	m_classifier_Attribute_attribute->setDerived(true);
	m_classifier_Attribute_attribute->setOrdered(true);
	m_classifier_Attribute_attribute->setContainment(false);
	m_classifier_Attribute_attribute->setResolveProxies(true);
	m_classifier_Attribute_attribute->setDefaultValueLiteral("");	
	
	m_classifier_Attribute_attribute->_setID(CLASSIFIER_ATTRIBUTE_ATTRIBUTE);
	m_classifier_Attribute_collaborationUse->setName("collaborationUse");
	m_classifier_Attribute_collaborationUse->setEType(getCollaborationUse_Class());
	m_classifier_Attribute_collaborationUse->setLowerBound(0);
	m_classifier_Attribute_collaborationUse->setUpperBound(-1);
	m_classifier_Attribute_collaborationUse->setTransient(false);
	m_classifier_Attribute_collaborationUse->setVolatile(false);
	m_classifier_Attribute_collaborationUse->setChangeable(true);
	m_classifier_Attribute_collaborationUse->setUnsettable(false);
	m_classifier_Attribute_collaborationUse->setUnique(true);
	m_classifier_Attribute_collaborationUse->setDerived(false);
	m_classifier_Attribute_collaborationUse->setOrdered(false);
	m_classifier_Attribute_collaborationUse->setContainment(true);
	m_classifier_Attribute_collaborationUse->setResolveProxies(true);
	m_classifier_Attribute_collaborationUse->setDefaultValueLiteral("");	
	
	m_classifier_Attribute_collaborationUse->_setID(CLASSIFIER_ATTRIBUTE_COLLABORATIONUSE);
	m_classifier_Attribute_feature->setName("feature");
	m_classifier_Attribute_feature->setEType(getFeature_Class());
	m_classifier_Attribute_feature->setLowerBound(0);
	m_classifier_Attribute_feature->setUpperBound(-1);
	m_classifier_Attribute_feature->setTransient(true);
	m_classifier_Attribute_feature->setVolatile(true);
	m_classifier_Attribute_feature->setChangeable(false);
	m_classifier_Attribute_feature->setUnsettable(false);
	m_classifier_Attribute_feature->setUnique(true);
	m_classifier_Attribute_feature->setDerived(true);
	m_classifier_Attribute_feature->setOrdered(false);
	m_classifier_Attribute_feature->setContainment(false);
	m_classifier_Attribute_feature->setResolveProxies(true);
	m_classifier_Attribute_feature->setDefaultValueLiteral("");	
	m_classifier_Attribute_feature->setEOpposite(uml::umlPackage::eInstance()->getFeature_Attribute_featuringClassifier());
	
	m_classifier_Attribute_feature->_setID(CLASSIFIER_ATTRIBUTE_FEATURE);
	m_classifier_Attribute_general->setName("general");
	m_classifier_Attribute_general->setEType(getClassifier_Class());
	m_classifier_Attribute_general->setLowerBound(0);
	m_classifier_Attribute_general->setUpperBound(-1);
	m_classifier_Attribute_general->setTransient(true);
	m_classifier_Attribute_general->setVolatile(true);
	m_classifier_Attribute_general->setChangeable(true);
	m_classifier_Attribute_general->setUnsettable(false);
	m_classifier_Attribute_general->setUnique(true);
	m_classifier_Attribute_general->setDerived(true);
	m_classifier_Attribute_general->setOrdered(false);
	m_classifier_Attribute_general->setContainment(false);
	m_classifier_Attribute_general->setResolveProxies(true);
	m_classifier_Attribute_general->setDefaultValueLiteral("");	
	
	m_classifier_Attribute_general->_setID(CLASSIFIER_ATTRIBUTE_GENERAL);
	m_classifier_Attribute_generalization->setName("generalization");
	m_classifier_Attribute_generalization->setEType(getGeneralization_Class());
	m_classifier_Attribute_generalization->setLowerBound(0);
	m_classifier_Attribute_generalization->setUpperBound(-1);
	m_classifier_Attribute_generalization->setTransient(false);
	m_classifier_Attribute_generalization->setVolatile(false);
	m_classifier_Attribute_generalization->setChangeable(true);
	m_classifier_Attribute_generalization->setUnsettable(false);
	m_classifier_Attribute_generalization->setUnique(true);
	m_classifier_Attribute_generalization->setDerived(false);
	m_classifier_Attribute_generalization->setOrdered(false);
	m_classifier_Attribute_generalization->setContainment(true);
	m_classifier_Attribute_generalization->setResolveProxies(true);
	m_classifier_Attribute_generalization->setDefaultValueLiteral("");	
	m_classifier_Attribute_generalization->setEOpposite(uml::umlPackage::eInstance()->getGeneralization_Attribute_specific());
	
	m_classifier_Attribute_generalization->_setID(CLASSIFIER_ATTRIBUTE_GENERALIZATION);
	m_classifier_Attribute_inheritedMember->setName("inheritedMember");
	m_classifier_Attribute_inheritedMember->setEType(getNamedElement_Class());
	m_classifier_Attribute_inheritedMember->setLowerBound(0);
	m_classifier_Attribute_inheritedMember->setUpperBound(-1);
	m_classifier_Attribute_inheritedMember->setTransient(true);
	m_classifier_Attribute_inheritedMember->setVolatile(true);
	m_classifier_Attribute_inheritedMember->setChangeable(false);
	m_classifier_Attribute_inheritedMember->setUnsettable(false);
	m_classifier_Attribute_inheritedMember->setUnique(true);
	m_classifier_Attribute_inheritedMember->setDerived(true);
	m_classifier_Attribute_inheritedMember->setOrdered(false);
	m_classifier_Attribute_inheritedMember->setContainment(false);
	m_classifier_Attribute_inheritedMember->setResolveProxies(true);
	m_classifier_Attribute_inheritedMember->setDefaultValueLiteral("");	
	
	m_classifier_Attribute_inheritedMember->_setID(CLASSIFIER_ATTRIBUTE_INHERITEDMEMBER);
	m_classifier_Attribute_ownedUseCase->setName("ownedUseCase");
	m_classifier_Attribute_ownedUseCase->setEType(getUseCase_Class());
	m_classifier_Attribute_ownedUseCase->setLowerBound(0);
	m_classifier_Attribute_ownedUseCase->setUpperBound(-1);
	m_classifier_Attribute_ownedUseCase->setTransient(false);
	m_classifier_Attribute_ownedUseCase->setVolatile(false);
	m_classifier_Attribute_ownedUseCase->setChangeable(true);
	m_classifier_Attribute_ownedUseCase->setUnsettable(false);
	m_classifier_Attribute_ownedUseCase->setUnique(true);
	m_classifier_Attribute_ownedUseCase->setDerived(false);
	m_classifier_Attribute_ownedUseCase->setOrdered(false);
	m_classifier_Attribute_ownedUseCase->setContainment(true);
	m_classifier_Attribute_ownedUseCase->setResolveProxies(true);
	m_classifier_Attribute_ownedUseCase->setDefaultValueLiteral("");	
	
	m_classifier_Attribute_ownedUseCase->_setID(CLASSIFIER_ATTRIBUTE_OWNEDUSECASE);
	m_classifier_Attribute_powertypeExtent->setName("powertypeExtent");
	m_classifier_Attribute_powertypeExtent->setEType(getGeneralizationSet_Class());
	m_classifier_Attribute_powertypeExtent->setLowerBound(0);
	m_classifier_Attribute_powertypeExtent->setUpperBound(-1);
	m_classifier_Attribute_powertypeExtent->setTransient(false);
	m_classifier_Attribute_powertypeExtent->setVolatile(false);
	m_classifier_Attribute_powertypeExtent->setChangeable(true);
	m_classifier_Attribute_powertypeExtent->setUnsettable(false);
	m_classifier_Attribute_powertypeExtent->setUnique(true);
	m_classifier_Attribute_powertypeExtent->setDerived(false);
	m_classifier_Attribute_powertypeExtent->setOrdered(false);
	m_classifier_Attribute_powertypeExtent->setContainment(false);
	m_classifier_Attribute_powertypeExtent->setResolveProxies(true);
	m_classifier_Attribute_powertypeExtent->setDefaultValueLiteral("");	
	m_classifier_Attribute_powertypeExtent->setEOpposite(uml::umlPackage::eInstance()->getGeneralizationSet_Attribute_powertype());
	
	m_classifier_Attribute_powertypeExtent->_setID(CLASSIFIER_ATTRIBUTE_POWERTYPEEXTENT);
	m_classifier_Attribute_redefinedClassifier->setName("redefinedClassifier");
	m_classifier_Attribute_redefinedClassifier->setEType(getClassifier_Class());
	m_classifier_Attribute_redefinedClassifier->setLowerBound(0);
	m_classifier_Attribute_redefinedClassifier->setUpperBound(-1);
	m_classifier_Attribute_redefinedClassifier->setTransient(false);
	m_classifier_Attribute_redefinedClassifier->setVolatile(false);
	m_classifier_Attribute_redefinedClassifier->setChangeable(true);
	m_classifier_Attribute_redefinedClassifier->setUnsettable(false);
	m_classifier_Attribute_redefinedClassifier->setUnique(true);
	m_classifier_Attribute_redefinedClassifier->setDerived(false);
	m_classifier_Attribute_redefinedClassifier->setOrdered(false);
	m_classifier_Attribute_redefinedClassifier->setContainment(false);
	m_classifier_Attribute_redefinedClassifier->setResolveProxies(true);
	m_classifier_Attribute_redefinedClassifier->setDefaultValueLiteral("");	
	
	m_classifier_Attribute_redefinedClassifier->_setID(CLASSIFIER_ATTRIBUTE_REDEFINEDCLASSIFIER);
	m_classifier_Attribute_representation->setName("representation");
	m_classifier_Attribute_representation->setEType(getCollaborationUse_Class());
	m_classifier_Attribute_representation->setLowerBound(0);
	m_classifier_Attribute_representation->setUpperBound(1);
	m_classifier_Attribute_representation->setTransient(false);
	m_classifier_Attribute_representation->setVolatile(false);
	m_classifier_Attribute_representation->setChangeable(true);
	m_classifier_Attribute_representation->setUnsettable(false);
	m_classifier_Attribute_representation->setUnique(true);
	m_classifier_Attribute_representation->setDerived(false);
	m_classifier_Attribute_representation->setOrdered(false);
	m_classifier_Attribute_representation->setContainment(false);
	m_classifier_Attribute_representation->setResolveProxies(true);
	m_classifier_Attribute_representation->setDefaultValueLiteral("");	
	
	m_classifier_Attribute_representation->_setID(CLASSIFIER_ATTRIBUTE_REPRESENTATION);
	m_classifier_Attribute_substitution->setName("substitution");
	m_classifier_Attribute_substitution->setEType(getSubstitution_Class());
	m_classifier_Attribute_substitution->setLowerBound(0);
	m_classifier_Attribute_substitution->setUpperBound(-1);
	m_classifier_Attribute_substitution->setTransient(false);
	m_classifier_Attribute_substitution->setVolatile(false);
	m_classifier_Attribute_substitution->setChangeable(true);
	m_classifier_Attribute_substitution->setUnsettable(false);
	m_classifier_Attribute_substitution->setUnique(true);
	m_classifier_Attribute_substitution->setDerived(false);
	m_classifier_Attribute_substitution->setOrdered(false);
	m_classifier_Attribute_substitution->setContainment(true);
	m_classifier_Attribute_substitution->setResolveProxies(true);
	m_classifier_Attribute_substitution->setDefaultValueLiteral("");	
	m_classifier_Attribute_substitution->setEOpposite(uml::umlPackage::eInstance()->getSubstitution_Attribute_substitutingClassifier());
	
	m_classifier_Attribute_substitution->_setID(CLASSIFIER_ATTRIBUTE_SUBSTITUTION);
	m_classifier_Attribute_useCase->setName("useCase");
	m_classifier_Attribute_useCase->setEType(getUseCase_Class());
	m_classifier_Attribute_useCase->setLowerBound(0);
	m_classifier_Attribute_useCase->setUpperBound(-1);
	m_classifier_Attribute_useCase->setTransient(false);
	m_classifier_Attribute_useCase->setVolatile(false);
	m_classifier_Attribute_useCase->setChangeable(true);
	m_classifier_Attribute_useCase->setUnsettable(false);
	m_classifier_Attribute_useCase->setUnique(true);
	m_classifier_Attribute_useCase->setDerived(false);
	m_classifier_Attribute_useCase->setOrdered(false);
	m_classifier_Attribute_useCase->setContainment(false);
	m_classifier_Attribute_useCase->setResolveProxies(true);
	m_classifier_Attribute_useCase->setDefaultValueLiteral("");	
	m_classifier_Attribute_useCase->setEOpposite(uml::umlPackage::eInstance()->getUseCase_Attribute_subject());
	
	m_classifier_Attribute_useCase->_setID(CLASSIFIER_ATTRIBUTE_USECASE);
	
	/*
	 * EOperations
	 */
	m_classifier_Operation_allAttributes->setName("allAttributes");
	m_classifier_Operation_allAttributes->setEType(getProperty_Class());
	m_classifier_Operation_allAttributes->setLowerBound(0);
	m_classifier_Operation_allAttributes->setUpperBound(-1);
	m_classifier_Operation_allAttributes->setUnique(true);
	m_classifier_Operation_allAttributes->setOrdered(true);
	
	m_classifier_Operation_allAttributes->_setID(CLASSIFIER_OPERATION_ALLATTRIBUTES);
	
	
	m_classifier_Operation_allFeatures->setName("allFeatures");
	m_classifier_Operation_allFeatures->setEType(getFeature_Class());
	m_classifier_Operation_allFeatures->setLowerBound(0);
	m_classifier_Operation_allFeatures->setUpperBound(-1);
	m_classifier_Operation_allFeatures->setUnique(true);
	m_classifier_Operation_allFeatures->setOrdered(false);
	
	m_classifier_Operation_allFeatures->_setID(CLASSIFIER_OPERATION_ALLFEATURES);
	
	
	m_classifier_Operation_allParents->setName("allParents");
	m_classifier_Operation_allParents->setEType(getClassifier_Class());
	m_classifier_Operation_allParents->setLowerBound(0);
	m_classifier_Operation_allParents->setUpperBound(-1);
	m_classifier_Operation_allParents->setUnique(true);
	m_classifier_Operation_allParents->setOrdered(false);
	
	m_classifier_Operation_allParents->_setID(CLASSIFIER_OPERATION_ALLPARENTS);
	
	
	m_classifier_Operation_allRealizedInterfaces->setName("allRealizedInterfaces");
	m_classifier_Operation_allRealizedInterfaces->setEType(getInterface_Class());
	m_classifier_Operation_allRealizedInterfaces->setLowerBound(0);
	m_classifier_Operation_allRealizedInterfaces->setUpperBound(-1);
	m_classifier_Operation_allRealizedInterfaces->setUnique(true);
	m_classifier_Operation_allRealizedInterfaces->setOrdered(false);
	
	m_classifier_Operation_allRealizedInterfaces->_setID(CLASSIFIER_OPERATION_ALLREALIZEDINTERFACES);
	
	
	m_classifier_Operation_allSlottableFeatures->setName("allSlottableFeatures");
	m_classifier_Operation_allSlottableFeatures->setEType(getStructuralFeature_Class());
	m_classifier_Operation_allSlottableFeatures->setLowerBound(0);
	m_classifier_Operation_allSlottableFeatures->setUpperBound(-1);
	m_classifier_Operation_allSlottableFeatures->setUnique(true);
	m_classifier_Operation_allSlottableFeatures->setOrdered(false);
	
	m_classifier_Operation_allSlottableFeatures->_setID(CLASSIFIER_OPERATION_ALLSLOTTABLEFEATURES);
	
	
	m_classifier_Operation_allUsedInterfaces->setName("allUsedInterfaces");
	m_classifier_Operation_allUsedInterfaces->setEType(getInterface_Class());
	m_classifier_Operation_allUsedInterfaces->setLowerBound(0);
	m_classifier_Operation_allUsedInterfaces->setUpperBound(-1);
	m_classifier_Operation_allUsedInterfaces->setUnique(true);
	m_classifier_Operation_allUsedInterfaces->setOrdered(false);
	
	m_classifier_Operation_allUsedInterfaces->_setID(CLASSIFIER_OPERATION_ALLUSEDINTERFACES);
	
	
	m_classifier_Operation_directlyRealizedInterfaces->setName("directlyRealizedInterfaces");
	m_classifier_Operation_directlyRealizedInterfaces->setEType(getInterface_Class());
	m_classifier_Operation_directlyRealizedInterfaces->setLowerBound(0);
	m_classifier_Operation_directlyRealizedInterfaces->setUpperBound(-1);
	m_classifier_Operation_directlyRealizedInterfaces->setUnique(true);
	m_classifier_Operation_directlyRealizedInterfaces->setOrdered(false);
	
	m_classifier_Operation_directlyRealizedInterfaces->_setID(CLASSIFIER_OPERATION_DIRECTLYREALIZEDINTERFACES);
	
	
	m_classifier_Operation_directlyUsedInterfaces->setName("directlyUsedInterfaces");
	m_classifier_Operation_directlyUsedInterfaces->setEType(getInterface_Class());
	m_classifier_Operation_directlyUsedInterfaces->setLowerBound(0);
	m_classifier_Operation_directlyUsedInterfaces->setUpperBound(-1);
	m_classifier_Operation_directlyUsedInterfaces->setUnique(true);
	m_classifier_Operation_directlyUsedInterfaces->setOrdered(false);
	
	m_classifier_Operation_directlyUsedInterfaces->_setID(CLASSIFIER_OPERATION_DIRECTLYUSEDINTERFACES);
	
	
	m_classifier_Operation_getAllAttributes->setName("getAllAttributes");
	m_classifier_Operation_getAllAttributes->setEType(getProperty_Class());
	m_classifier_Operation_getAllAttributes->setLowerBound(0);
	m_classifier_Operation_getAllAttributes->setUpperBound(-1);
	m_classifier_Operation_getAllAttributes->setUnique(true);
	m_classifier_Operation_getAllAttributes->setOrdered(false);
	
	m_classifier_Operation_getAllAttributes->_setID(CLASSIFIER_OPERATION_GETALLATTRIBUTES);
	
	
	m_classifier_Operation_getAllOperations->setName("getAllOperations");
	m_classifier_Operation_getAllOperations->setEType(getOperation_Class());
	m_classifier_Operation_getAllOperations->setLowerBound(0);
	m_classifier_Operation_getAllOperations->setUpperBound(-1);
	m_classifier_Operation_getAllOperations->setUnique(true);
	m_classifier_Operation_getAllOperations->setOrdered(false);
	
	m_classifier_Operation_getAllOperations->_setID(CLASSIFIER_OPERATION_GETALLOPERATIONS);
	
	
	m_classifier_Operation_getAllUsedInterfaces->setName("getAllUsedInterfaces");
	m_classifier_Operation_getAllUsedInterfaces->setEType(getInterface_Class());
	m_classifier_Operation_getAllUsedInterfaces->setLowerBound(0);
	m_classifier_Operation_getAllUsedInterfaces->setUpperBound(-1);
	m_classifier_Operation_getAllUsedInterfaces->setUnique(true);
	m_classifier_Operation_getAllUsedInterfaces->setOrdered(false);
	
	m_classifier_Operation_getAllUsedInterfaces->_setID(CLASSIFIER_OPERATION_GETALLUSEDINTERFACES);
	
	
	m_classifier_Operation_getGenerals->setName("getGenerals");
	m_classifier_Operation_getGenerals->setEType(getClassifier_Class());
	m_classifier_Operation_getGenerals->setLowerBound(0);
	m_classifier_Operation_getGenerals->setUpperBound(-1);
	m_classifier_Operation_getGenerals->setUnique(true);
	m_classifier_Operation_getGenerals->setOrdered(false);
	
	m_classifier_Operation_getGenerals->_setID(CLASSIFIER_OPERATION_GETGENERALS);
	
	
	m_classifier_Operation_getInheritedMembers->setName("getInheritedMembers");
	m_classifier_Operation_getInheritedMembers->setEType(getNamedElement_Class());
	m_classifier_Operation_getInheritedMembers->setLowerBound(0);
	m_classifier_Operation_getInheritedMembers->setUpperBound(-1);
	m_classifier_Operation_getInheritedMembers->setUnique(true);
	m_classifier_Operation_getInheritedMembers->setOrdered(false);
	
	m_classifier_Operation_getInheritedMembers->_setID(CLASSIFIER_OPERATION_GETINHERITEDMEMBERS);
	
	
	m_classifier_Operation_getOperation_String_Type->setName("getOperation");
	m_classifier_Operation_getOperation_String_Type->setEType(getOperation_Class());
	m_classifier_Operation_getOperation_String_Type->setLowerBound(0);
	m_classifier_Operation_getOperation_String_Type->setUpperBound(1);
	m_classifier_Operation_getOperation_String_Type->setUnique(true);
	m_classifier_Operation_getOperation_String_Type->setOrdered(false);
	
	m_classifier_Operation_getOperation_String_Type->_setID(CLASSIFIER_OPERATION_GETOPERATION_STRING_TYPE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_classifier_Operation_getOperation_String_Type);
		parameter->setName("name");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_classifier_Operation_getOperation_String_Type);
		parameter->setName("parameterNames");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_classifier_Operation_getOperation_String_Type);
		parameter->setName("parameterTypes");
		parameter->setEType(getType_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_classifier_Operation_getOperation_String_Boolean->setName("getOperation");
	m_classifier_Operation_getOperation_String_Boolean->setEType(getOperation_Class());
	m_classifier_Operation_getOperation_String_Boolean->setLowerBound(0);
	m_classifier_Operation_getOperation_String_Boolean->setUpperBound(1);
	m_classifier_Operation_getOperation_String_Boolean->setUnique(true);
	m_classifier_Operation_getOperation_String_Boolean->setOrdered(false);
	
	m_classifier_Operation_getOperation_String_Boolean->_setID(CLASSIFIER_OPERATION_GETOPERATION_STRING_BOOLEAN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_classifier_Operation_getOperation_String_Boolean);
		parameter->setName("name");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_classifier_Operation_getOperation_String_Boolean);
		parameter->setName("parameterNames");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_classifier_Operation_getOperation_String_Boolean);
		parameter->setName("parameterTypes");
		parameter->setEType(getType_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_classifier_Operation_getOperation_String_Boolean);
		parameter->setName("ignoreCase");
		parameter->setEType(types::typesPackage::eInstance()->getBoolean_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_classifier_Operation_getOperations->setName("getOperations");
	m_classifier_Operation_getOperations->setEType(getOperation_Class());
	m_classifier_Operation_getOperations->setLowerBound(0);
	m_classifier_Operation_getOperations->setUpperBound(-1);
	m_classifier_Operation_getOperations->setUnique(true);
	m_classifier_Operation_getOperations->setOrdered(false);
	
	m_classifier_Operation_getOperations->_setID(CLASSIFIER_OPERATION_GETOPERATIONS);
	
	
	m_classifier_Operation_getPropertyValue_String->setName("getPropertyValue");
	m_classifier_Operation_getPropertyValue_String->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_classifier_Operation_getPropertyValue_String->setLowerBound(0);
	m_classifier_Operation_getPropertyValue_String->setUpperBound(1);
	m_classifier_Operation_getPropertyValue_String->setUnique(true);
	m_classifier_Operation_getPropertyValue_String->setOrdered(false);
	
	m_classifier_Operation_getPropertyValue_String->_setID(CLASSIFIER_OPERATION_GETPROPERTYVALUE_STRING);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_classifier_Operation_getPropertyValue_String);
		parameter->setName("propertyName");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_classifier_Operation_getUsedInterfaces->setName("getUsedInterfaces");
	m_classifier_Operation_getUsedInterfaces->setEType(getInterface_Class());
	m_classifier_Operation_getUsedInterfaces->setLowerBound(0);
	m_classifier_Operation_getUsedInterfaces->setUpperBound(-1);
	m_classifier_Operation_getUsedInterfaces->setUnique(true);
	m_classifier_Operation_getUsedInterfaces->setOrdered(false);
	
	m_classifier_Operation_getUsedInterfaces->_setID(CLASSIFIER_OPERATION_GETUSEDINTERFACES);
	
	
	m_classifier_Operation_hasVisibilityOf_NamedElement->setName("hasVisibilityOf");
	m_classifier_Operation_hasVisibilityOf_NamedElement->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_classifier_Operation_hasVisibilityOf_NamedElement->setLowerBound(1);
	m_classifier_Operation_hasVisibilityOf_NamedElement->setUpperBound(1);
	m_classifier_Operation_hasVisibilityOf_NamedElement->setUnique(true);
	m_classifier_Operation_hasVisibilityOf_NamedElement->setOrdered(false);
	
	m_classifier_Operation_hasVisibilityOf_NamedElement->_setID(CLASSIFIER_OPERATION_HASVISIBILITYOF_NAMEDELEMENT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_classifier_Operation_hasVisibilityOf_NamedElement);
		parameter->setName("n");
		parameter->setEType(getNamedElement_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_classifier_Operation_inherit_NamedElement->setName("inherit");
	m_classifier_Operation_inherit_NamedElement->setEType(getNamedElement_Class());
	m_classifier_Operation_inherit_NamedElement->setLowerBound(0);
	m_classifier_Operation_inherit_NamedElement->setUpperBound(-1);
	m_classifier_Operation_inherit_NamedElement->setUnique(true);
	m_classifier_Operation_inherit_NamedElement->setOrdered(false);
	
	m_classifier_Operation_inherit_NamedElement->_setID(CLASSIFIER_OPERATION_INHERIT_NAMEDELEMENT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_classifier_Operation_inherit_NamedElement);
		parameter->setName("inhs");
		parameter->setEType(getNamedElement_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_classifier_Operation_inheritableMembers_Classifier->setName("inheritableMembers");
	m_classifier_Operation_inheritableMembers_Classifier->setEType(getNamedElement_Class());
	m_classifier_Operation_inheritableMembers_Classifier->setLowerBound(0);
	m_classifier_Operation_inheritableMembers_Classifier->setUpperBound(-1);
	m_classifier_Operation_inheritableMembers_Classifier->setUnique(true);
	m_classifier_Operation_inheritableMembers_Classifier->setOrdered(false);
	
	m_classifier_Operation_inheritableMembers_Classifier->_setID(CLASSIFIER_OPERATION_INHERITABLEMEMBERS_CLASSIFIER);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_classifier_Operation_inheritableMembers_Classifier);
		parameter->setName("c");
		parameter->setEType(getClassifier_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_classifier_Operation_isSubstitutableFor_Classifier->setName("isSubstitutableFor");
	m_classifier_Operation_isSubstitutableFor_Classifier->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_classifier_Operation_isSubstitutableFor_Classifier->setLowerBound(1);
	m_classifier_Operation_isSubstitutableFor_Classifier->setUpperBound(1);
	m_classifier_Operation_isSubstitutableFor_Classifier->setUnique(true);
	m_classifier_Operation_isSubstitutableFor_Classifier->setOrdered(false);
	
	m_classifier_Operation_isSubstitutableFor_Classifier->_setID(CLASSIFIER_OPERATION_ISSUBSTITUTABLEFOR_CLASSIFIER);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_classifier_Operation_isSubstitutableFor_Classifier);
		parameter->setName("contract");
		parameter->setEType(getClassifier_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_classifier_Operation_maySpecializeType_Classifier->setName("maySpecializeType");
	m_classifier_Operation_maySpecializeType_Classifier->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_classifier_Operation_maySpecializeType_Classifier->setLowerBound(1);
	m_classifier_Operation_maySpecializeType_Classifier->setUpperBound(1);
	m_classifier_Operation_maySpecializeType_Classifier->setUnique(true);
	m_classifier_Operation_maySpecializeType_Classifier->setOrdered(false);
	
	m_classifier_Operation_maySpecializeType_Classifier->_setID(CLASSIFIER_OPERATION_MAYSPECIALIZETYPE_CLASSIFIER);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_classifier_Operation_maySpecializeType_Classifier);
		parameter->setName("c");
		parameter->setEType(getClassifier_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_classifier_Operation_parents->setName("parents");
	m_classifier_Operation_parents->setEType(getClassifier_Class());
	m_classifier_Operation_parents->setLowerBound(0);
	m_classifier_Operation_parents->setUpperBound(-1);
	m_classifier_Operation_parents->setUnique(true);
	m_classifier_Operation_parents->setOrdered(false);
	
	m_classifier_Operation_parents->_setID(CLASSIFIER_OPERATION_PARENTS);
	
	
	
}

void umlPackageImpl::initializeClassifierTemplateParameterContent()
{
	m_classifierTemplateParameter_Class->setName("ClassifierTemplateParameter");
	m_classifierTemplateParameter_Class->setAbstract(false);
	m_classifierTemplateParameter_Class->setInterface(false);
	
	m_classifierTemplateParameter_Class->_setID(CLASSIFIERTEMPLATEPARAMETER_CLASS);
	
	/*
	 * EAttributes
	 */
	m_classifierTemplateParameter_Attribute_allowSubstitutable = getClassifierTemplateParameter_Attribute_allowSubstitutable();
	m_classifierTemplateParameter_Attribute_allowSubstitutable->setName("allowSubstitutable");
	m_classifierTemplateParameter_Attribute_allowSubstitutable->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_classifierTemplateParameter_Attribute_allowSubstitutable->setLowerBound(1);
	m_classifierTemplateParameter_Attribute_allowSubstitutable->setUpperBound(1);
	m_classifierTemplateParameter_Attribute_allowSubstitutable->setTransient(false);
	m_classifierTemplateParameter_Attribute_allowSubstitutable->setVolatile(false);
	m_classifierTemplateParameter_Attribute_allowSubstitutable->setChangeable(true);
	m_classifierTemplateParameter_Attribute_allowSubstitutable->setUnsettable(false);
	m_classifierTemplateParameter_Attribute_allowSubstitutable->setUnique(true);
	m_classifierTemplateParameter_Attribute_allowSubstitutable->setDerived(false);
	m_classifierTemplateParameter_Attribute_allowSubstitutable->setOrdered(false);
	m_classifierTemplateParameter_Attribute_allowSubstitutable->setID(false);
	m_classifierTemplateParameter_Attribute_allowSubstitutable->setDefaultValueLiteral("true");
	
	m_classifierTemplateParameter_Attribute_allowSubstitutable->_setID(CLASSIFIERTEMPLATEPARAMETER_ATTRIBUTE_ALLOWSUBSTITUTABLE);
	
	/*
	 * EReferences
	 */
	m_classifierTemplateParameter_Attribute_constrainingClassifier->setName("constrainingClassifier");
	m_classifierTemplateParameter_Attribute_constrainingClassifier->setEType(getClassifier_Class());
	m_classifierTemplateParameter_Attribute_constrainingClassifier->setLowerBound(0);
	m_classifierTemplateParameter_Attribute_constrainingClassifier->setUpperBound(-1);
	m_classifierTemplateParameter_Attribute_constrainingClassifier->setTransient(false);
	m_classifierTemplateParameter_Attribute_constrainingClassifier->setVolatile(false);
	m_classifierTemplateParameter_Attribute_constrainingClassifier->setChangeable(true);
	m_classifierTemplateParameter_Attribute_constrainingClassifier->setUnsettable(false);
	m_classifierTemplateParameter_Attribute_constrainingClassifier->setUnique(true);
	m_classifierTemplateParameter_Attribute_constrainingClassifier->setDerived(false);
	m_classifierTemplateParameter_Attribute_constrainingClassifier->setOrdered(false);
	m_classifierTemplateParameter_Attribute_constrainingClassifier->setContainment(false);
	m_classifierTemplateParameter_Attribute_constrainingClassifier->setResolveProxies(true);
	m_classifierTemplateParameter_Attribute_constrainingClassifier->setDefaultValueLiteral("");	
	
	m_classifierTemplateParameter_Attribute_constrainingClassifier->_setID(CLASSIFIERTEMPLATEPARAMETER_ATTRIBUTE_CONSTRAININGCLASSIFIER);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeClauseContent()
{
	m_clause_Class->setName("Clause");
	m_clause_Class->setAbstract(false);
	m_clause_Class->setInterface(false);
	
	m_clause_Class->_setID(CLAUSE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_clause_Attribute_body->setName("body");
	m_clause_Attribute_body->setEType(getExecutableNode_Class());
	m_clause_Attribute_body->setLowerBound(0);
	m_clause_Attribute_body->setUpperBound(-1);
	m_clause_Attribute_body->setTransient(false);
	m_clause_Attribute_body->setVolatile(false);
	m_clause_Attribute_body->setChangeable(true);
	m_clause_Attribute_body->setUnsettable(false);
	m_clause_Attribute_body->setUnique(true);
	m_clause_Attribute_body->setDerived(false);
	m_clause_Attribute_body->setOrdered(false);
	m_clause_Attribute_body->setContainment(false);
	m_clause_Attribute_body->setResolveProxies(true);
	m_clause_Attribute_body->setDefaultValueLiteral("");	
	
	m_clause_Attribute_body->_setID(CLAUSE_ATTRIBUTE_BODY);
	m_clause_Attribute_bodyOutput->setName("bodyOutput");
	m_clause_Attribute_bodyOutput->setEType(getOutputPin_Class());
	m_clause_Attribute_bodyOutput->setLowerBound(0);
	m_clause_Attribute_bodyOutput->setUpperBound(-1);
	m_clause_Attribute_bodyOutput->setTransient(false);
	m_clause_Attribute_bodyOutput->setVolatile(false);
	m_clause_Attribute_bodyOutput->setChangeable(true);
	m_clause_Attribute_bodyOutput->setUnsettable(false);
	m_clause_Attribute_bodyOutput->setUnique(true);
	m_clause_Attribute_bodyOutput->setDerived(false);
	m_clause_Attribute_bodyOutput->setOrdered(true);
	m_clause_Attribute_bodyOutput->setContainment(false);
	m_clause_Attribute_bodyOutput->setResolveProxies(true);
	m_clause_Attribute_bodyOutput->setDefaultValueLiteral("");	
	
	m_clause_Attribute_bodyOutput->_setID(CLAUSE_ATTRIBUTE_BODYOUTPUT);
	m_clause_Attribute_decider->setName("decider");
	m_clause_Attribute_decider->setEType(getOutputPin_Class());
	m_clause_Attribute_decider->setLowerBound(1);
	m_clause_Attribute_decider->setUpperBound(1);
	m_clause_Attribute_decider->setTransient(false);
	m_clause_Attribute_decider->setVolatile(false);
	m_clause_Attribute_decider->setChangeable(true);
	m_clause_Attribute_decider->setUnsettable(false);
	m_clause_Attribute_decider->setUnique(true);
	m_clause_Attribute_decider->setDerived(false);
	m_clause_Attribute_decider->setOrdered(false);
	m_clause_Attribute_decider->setContainment(false);
	m_clause_Attribute_decider->setResolveProxies(true);
	m_clause_Attribute_decider->setDefaultValueLiteral("");	
	
	m_clause_Attribute_decider->_setID(CLAUSE_ATTRIBUTE_DECIDER);
	m_clause_Attribute_predecessorClause->setName("predecessorClause");
	m_clause_Attribute_predecessorClause->setEType(getClause_Class());
	m_clause_Attribute_predecessorClause->setLowerBound(0);
	m_clause_Attribute_predecessorClause->setUpperBound(-1);
	m_clause_Attribute_predecessorClause->setTransient(false);
	m_clause_Attribute_predecessorClause->setVolatile(false);
	m_clause_Attribute_predecessorClause->setChangeable(true);
	m_clause_Attribute_predecessorClause->setUnsettable(false);
	m_clause_Attribute_predecessorClause->setUnique(true);
	m_clause_Attribute_predecessorClause->setDerived(false);
	m_clause_Attribute_predecessorClause->setOrdered(false);
	m_clause_Attribute_predecessorClause->setContainment(false);
	m_clause_Attribute_predecessorClause->setResolveProxies(true);
	m_clause_Attribute_predecessorClause->setDefaultValueLiteral("");	
	m_clause_Attribute_predecessorClause->setEOpposite(uml::umlPackage::eInstance()->getClause_Attribute_successorClause());
	
	m_clause_Attribute_predecessorClause->_setID(CLAUSE_ATTRIBUTE_PREDECESSORCLAUSE);
	m_clause_Attribute_successorClause->setName("successorClause");
	m_clause_Attribute_successorClause->setEType(getClause_Class());
	m_clause_Attribute_successorClause->setLowerBound(0);
	m_clause_Attribute_successorClause->setUpperBound(-1);
	m_clause_Attribute_successorClause->setTransient(false);
	m_clause_Attribute_successorClause->setVolatile(false);
	m_clause_Attribute_successorClause->setChangeable(true);
	m_clause_Attribute_successorClause->setUnsettable(false);
	m_clause_Attribute_successorClause->setUnique(true);
	m_clause_Attribute_successorClause->setDerived(false);
	m_clause_Attribute_successorClause->setOrdered(false);
	m_clause_Attribute_successorClause->setContainment(false);
	m_clause_Attribute_successorClause->setResolveProxies(true);
	m_clause_Attribute_successorClause->setDefaultValueLiteral("");	
	m_clause_Attribute_successorClause->setEOpposite(uml::umlPackage::eInstance()->getClause_Attribute_predecessorClause());
	
	m_clause_Attribute_successorClause->_setID(CLAUSE_ATTRIBUTE_SUCCESSORCLAUSE);
	m_clause_Attribute_test->setName("test");
	m_clause_Attribute_test->setEType(getExecutableNode_Class());
	m_clause_Attribute_test->setLowerBound(1);
	m_clause_Attribute_test->setUpperBound(-1);
	m_clause_Attribute_test->setTransient(false);
	m_clause_Attribute_test->setVolatile(false);
	m_clause_Attribute_test->setChangeable(true);
	m_clause_Attribute_test->setUnsettable(false);
	m_clause_Attribute_test->setUnique(true);
	m_clause_Attribute_test->setDerived(false);
	m_clause_Attribute_test->setOrdered(false);
	m_clause_Attribute_test->setContainment(false);
	m_clause_Attribute_test->setResolveProxies(true);
	m_clause_Attribute_test->setDefaultValueLiteral("");	
	
	m_clause_Attribute_test->_setID(CLAUSE_ATTRIBUTE_TEST);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeClearAssociationActionContent()
{
	m_clearAssociationAction_Class->setName("ClearAssociationAction");
	m_clearAssociationAction_Class->setAbstract(false);
	m_clearAssociationAction_Class->setInterface(false);
	
	m_clearAssociationAction_Class->_setID(CLEARASSOCIATIONACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_clearAssociationAction_Attribute_association->setName("association");
	m_clearAssociationAction_Attribute_association->setEType(getAssociation_Class());
	m_clearAssociationAction_Attribute_association->setLowerBound(1);
	m_clearAssociationAction_Attribute_association->setUpperBound(1);
	m_clearAssociationAction_Attribute_association->setTransient(false);
	m_clearAssociationAction_Attribute_association->setVolatile(false);
	m_clearAssociationAction_Attribute_association->setChangeable(true);
	m_clearAssociationAction_Attribute_association->setUnsettable(false);
	m_clearAssociationAction_Attribute_association->setUnique(true);
	m_clearAssociationAction_Attribute_association->setDerived(false);
	m_clearAssociationAction_Attribute_association->setOrdered(false);
	m_clearAssociationAction_Attribute_association->setContainment(false);
	m_clearAssociationAction_Attribute_association->setResolveProxies(true);
	m_clearAssociationAction_Attribute_association->setDefaultValueLiteral("");	
	
	m_clearAssociationAction_Attribute_association->_setID(CLEARASSOCIATIONACTION_ATTRIBUTE_ASSOCIATION);
	m_clearAssociationAction_Attribute_object->setName("object");
	m_clearAssociationAction_Attribute_object->setEType(getInputPin_Class());
	m_clearAssociationAction_Attribute_object->setLowerBound(1);
	m_clearAssociationAction_Attribute_object->setUpperBound(1);
	m_clearAssociationAction_Attribute_object->setTransient(false);
	m_clearAssociationAction_Attribute_object->setVolatile(false);
	m_clearAssociationAction_Attribute_object->setChangeable(true);
	m_clearAssociationAction_Attribute_object->setUnsettable(false);
	m_clearAssociationAction_Attribute_object->setUnique(true);
	m_clearAssociationAction_Attribute_object->setDerived(false);
	m_clearAssociationAction_Attribute_object->setOrdered(false);
	m_clearAssociationAction_Attribute_object->setContainment(true);
	m_clearAssociationAction_Attribute_object->setResolveProxies(true);
	m_clearAssociationAction_Attribute_object->setDefaultValueLiteral("");	
	
	m_clearAssociationAction_Attribute_object->_setID(CLEARASSOCIATIONACTION_ATTRIBUTE_OBJECT);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeClearStructuralFeatureActionContent()
{
	m_clearStructuralFeatureAction_Class->setName("ClearStructuralFeatureAction");
	m_clearStructuralFeatureAction_Class->setAbstract(false);
	m_clearStructuralFeatureAction_Class->setInterface(false);
	
	m_clearStructuralFeatureAction_Class->_setID(CLEARSTRUCTURALFEATUREACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_clearStructuralFeatureAction_Attribute_result->setName("result");
	m_clearStructuralFeatureAction_Attribute_result->setEType(getOutputPin_Class());
	m_clearStructuralFeatureAction_Attribute_result->setLowerBound(0);
	m_clearStructuralFeatureAction_Attribute_result->setUpperBound(1);
	m_clearStructuralFeatureAction_Attribute_result->setTransient(false);
	m_clearStructuralFeatureAction_Attribute_result->setVolatile(false);
	m_clearStructuralFeatureAction_Attribute_result->setChangeable(true);
	m_clearStructuralFeatureAction_Attribute_result->setUnsettable(false);
	m_clearStructuralFeatureAction_Attribute_result->setUnique(true);
	m_clearStructuralFeatureAction_Attribute_result->setDerived(false);
	m_clearStructuralFeatureAction_Attribute_result->setOrdered(false);
	m_clearStructuralFeatureAction_Attribute_result->setContainment(true);
	m_clearStructuralFeatureAction_Attribute_result->setResolveProxies(true);
	m_clearStructuralFeatureAction_Attribute_result->setDefaultValueLiteral("");	
	m_clearStructuralFeatureAction_Attribute_result->setEOpposite(uml::umlPackage::eInstance()->getOutputPin_Attribute_clearStructuralFeatureAction());
	
	m_clearStructuralFeatureAction_Attribute_result->_setID(CLEARSTRUCTURALFEATUREACTION_ATTRIBUTE_RESULT);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeClearVariableActionContent()
{
	m_clearVariableAction_Class->setName("ClearVariableAction");
	m_clearVariableAction_Class->setAbstract(false);
	m_clearVariableAction_Class->setInterface(false);
	
	m_clearVariableAction_Class->_setID(CLEARVARIABLEACTION_CLASS);
	
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

void umlPackageImpl::initializeCollaborationContent()
{
	m_collaboration_Class->setName("Collaboration");
	m_collaboration_Class->setAbstract(false);
	m_collaboration_Class->setInterface(false);
	
	m_collaboration_Class->_setID(COLLABORATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_collaboration_Attribute_collaborationRole->setName("collaborationRole");
	m_collaboration_Attribute_collaborationRole->setEType(getConnectableElement_Class());
	m_collaboration_Attribute_collaborationRole->setLowerBound(0);
	m_collaboration_Attribute_collaborationRole->setUpperBound(-1);
	m_collaboration_Attribute_collaborationRole->setTransient(false);
	m_collaboration_Attribute_collaborationRole->setVolatile(false);
	m_collaboration_Attribute_collaborationRole->setChangeable(true);
	m_collaboration_Attribute_collaborationRole->setUnsettable(false);
	m_collaboration_Attribute_collaborationRole->setUnique(true);
	m_collaboration_Attribute_collaborationRole->setDerived(false);
	m_collaboration_Attribute_collaborationRole->setOrdered(false);
	m_collaboration_Attribute_collaborationRole->setContainment(false);
	m_collaboration_Attribute_collaborationRole->setResolveProxies(true);
	m_collaboration_Attribute_collaborationRole->setDefaultValueLiteral("");	
	
	m_collaboration_Attribute_collaborationRole->_setID(COLLABORATION_ATTRIBUTE_COLLABORATIONROLE);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeCollaborationUseContent()
{
	m_collaborationUse_Class->setName("CollaborationUse");
	m_collaborationUse_Class->setAbstract(false);
	m_collaborationUse_Class->setInterface(false);
	
	m_collaborationUse_Class->_setID(COLLABORATIONUSE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_collaborationUse_Attribute_roleBinding->setName("roleBinding");
	m_collaborationUse_Attribute_roleBinding->setEType(getDependency_Class());
	m_collaborationUse_Attribute_roleBinding->setLowerBound(0);
	m_collaborationUse_Attribute_roleBinding->setUpperBound(-1);
	m_collaborationUse_Attribute_roleBinding->setTransient(false);
	m_collaborationUse_Attribute_roleBinding->setVolatile(false);
	m_collaborationUse_Attribute_roleBinding->setChangeable(true);
	m_collaborationUse_Attribute_roleBinding->setUnsettable(false);
	m_collaborationUse_Attribute_roleBinding->setUnique(true);
	m_collaborationUse_Attribute_roleBinding->setDerived(false);
	m_collaborationUse_Attribute_roleBinding->setOrdered(false);
	m_collaborationUse_Attribute_roleBinding->setContainment(true);
	m_collaborationUse_Attribute_roleBinding->setResolveProxies(true);
	m_collaborationUse_Attribute_roleBinding->setDefaultValueLiteral("");	
	
	m_collaborationUse_Attribute_roleBinding->_setID(COLLABORATIONUSE_ATTRIBUTE_ROLEBINDING);
	m_collaborationUse_Attribute_type->setName("type");
	m_collaborationUse_Attribute_type->setEType(getCollaboration_Class());
	m_collaborationUse_Attribute_type->setLowerBound(1);
	m_collaborationUse_Attribute_type->setUpperBound(1);
	m_collaborationUse_Attribute_type->setTransient(false);
	m_collaborationUse_Attribute_type->setVolatile(false);
	m_collaborationUse_Attribute_type->setChangeable(true);
	m_collaborationUse_Attribute_type->setUnsettable(false);
	m_collaborationUse_Attribute_type->setUnique(true);
	m_collaborationUse_Attribute_type->setDerived(false);
	m_collaborationUse_Attribute_type->setOrdered(false);
	m_collaborationUse_Attribute_type->setContainment(false);
	m_collaborationUse_Attribute_type->setResolveProxies(true);
	m_collaborationUse_Attribute_type->setDefaultValueLiteral("");	
	
	m_collaborationUse_Attribute_type->_setID(COLLABORATIONUSE_ATTRIBUTE_TYPE);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeCombinedFragmentContent()
{
	m_combinedFragment_Class->setName("CombinedFragment");
	m_combinedFragment_Class->setAbstract(false);
	m_combinedFragment_Class->setInterface(false);
	
	m_combinedFragment_Class->_setID(COMBINEDFRAGMENT_CLASS);
	
	/*
	 * EAttributes
	 */
	m_combinedFragment_Attribute_interactionOperator = getCombinedFragment_Attribute_interactionOperator();
	m_combinedFragment_Attribute_interactionOperator->setName("interactionOperator");
	m_combinedFragment_Attribute_interactionOperator->setEType(getInteractionOperatorKind_Class());
	m_combinedFragment_Attribute_interactionOperator->setLowerBound(1);
	m_combinedFragment_Attribute_interactionOperator->setUpperBound(1);
	m_combinedFragment_Attribute_interactionOperator->setTransient(false);
	m_combinedFragment_Attribute_interactionOperator->setVolatile(false);
	m_combinedFragment_Attribute_interactionOperator->setChangeable(true);
	m_combinedFragment_Attribute_interactionOperator->setUnsettable(false);
	m_combinedFragment_Attribute_interactionOperator->setUnique(true);
	m_combinedFragment_Attribute_interactionOperator->setDerived(false);
	m_combinedFragment_Attribute_interactionOperator->setOrdered(false);
	m_combinedFragment_Attribute_interactionOperator->setID(false);
	m_combinedFragment_Attribute_interactionOperator->setDefaultValueLiteral("seq");
	
	m_combinedFragment_Attribute_interactionOperator->_setID(COMBINEDFRAGMENT_ATTRIBUTE_INTERACTIONOPERATOR);
	
	/*
	 * EReferences
	 */
	m_combinedFragment_Attribute_cfragmentGate->setName("cfragmentGate");
	m_combinedFragment_Attribute_cfragmentGate->setEType(getGate_Class());
	m_combinedFragment_Attribute_cfragmentGate->setLowerBound(0);
	m_combinedFragment_Attribute_cfragmentGate->setUpperBound(-1);
	m_combinedFragment_Attribute_cfragmentGate->setTransient(false);
	m_combinedFragment_Attribute_cfragmentGate->setVolatile(false);
	m_combinedFragment_Attribute_cfragmentGate->setChangeable(true);
	m_combinedFragment_Attribute_cfragmentGate->setUnsettable(false);
	m_combinedFragment_Attribute_cfragmentGate->setUnique(true);
	m_combinedFragment_Attribute_cfragmentGate->setDerived(false);
	m_combinedFragment_Attribute_cfragmentGate->setOrdered(false);
	m_combinedFragment_Attribute_cfragmentGate->setContainment(true);
	m_combinedFragment_Attribute_cfragmentGate->setResolveProxies(true);
	m_combinedFragment_Attribute_cfragmentGate->setDefaultValueLiteral("");	
	
	m_combinedFragment_Attribute_cfragmentGate->_setID(COMBINEDFRAGMENT_ATTRIBUTE_CFRAGMENTGATE);
	m_combinedFragment_Attribute_operand->setName("operand");
	m_combinedFragment_Attribute_operand->setEType(getInteractionOperand_Class());
	m_combinedFragment_Attribute_operand->setLowerBound(1);
	m_combinedFragment_Attribute_operand->setUpperBound(-1);
	m_combinedFragment_Attribute_operand->setTransient(false);
	m_combinedFragment_Attribute_operand->setVolatile(false);
	m_combinedFragment_Attribute_operand->setChangeable(true);
	m_combinedFragment_Attribute_operand->setUnsettable(false);
	m_combinedFragment_Attribute_operand->setUnique(true);
	m_combinedFragment_Attribute_operand->setDerived(false);
	m_combinedFragment_Attribute_operand->setOrdered(true);
	m_combinedFragment_Attribute_operand->setContainment(true);
	m_combinedFragment_Attribute_operand->setResolveProxies(true);
	m_combinedFragment_Attribute_operand->setDefaultValueLiteral("");	
	
	m_combinedFragment_Attribute_operand->_setID(COMBINEDFRAGMENT_ATTRIBUTE_OPERAND);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeCommentContent()
{
	m_comment_Class->setName("Comment");
	m_comment_Class->setAbstract(false);
	m_comment_Class->setInterface(false);
	
	m_comment_Class->_setID(COMMENT_CLASS);
	
	/*
	 * EAttributes
	 */
	m_comment_Attribute_body = getComment_Attribute_body();
	m_comment_Attribute_body->setName("body");
	m_comment_Attribute_body->setEType(types::typesPackage::eInstance()->getString_Class());
	m_comment_Attribute_body->setLowerBound(0);
	m_comment_Attribute_body->setUpperBound(1);
	m_comment_Attribute_body->setTransient(false);
	m_comment_Attribute_body->setVolatile(false);
	m_comment_Attribute_body->setChangeable(true);
	m_comment_Attribute_body->setUnsettable(true);
	m_comment_Attribute_body->setUnique(true);
	m_comment_Attribute_body->setDerived(false);
	m_comment_Attribute_body->setOrdered(false);
	m_comment_Attribute_body->setID(false);
	m_comment_Attribute_body->setDefaultValueLiteral("");
	
	m_comment_Attribute_body->_setID(COMMENT_ATTRIBUTE_BODY);
	
	/*
	 * EReferences
	 */
	m_comment_Attribute_annotatedElement->setName("annotatedElement");
	m_comment_Attribute_annotatedElement->setEType(getElement_Class());
	m_comment_Attribute_annotatedElement->setLowerBound(0);
	m_comment_Attribute_annotatedElement->setUpperBound(-1);
	m_comment_Attribute_annotatedElement->setTransient(false);
	m_comment_Attribute_annotatedElement->setVolatile(false);
	m_comment_Attribute_annotatedElement->setChangeable(true);
	m_comment_Attribute_annotatedElement->setUnsettable(false);
	m_comment_Attribute_annotatedElement->setUnique(true);
	m_comment_Attribute_annotatedElement->setDerived(false);
	m_comment_Attribute_annotatedElement->setOrdered(false);
	m_comment_Attribute_annotatedElement->setContainment(false);
	m_comment_Attribute_annotatedElement->setResolveProxies(true);
	m_comment_Attribute_annotatedElement->setDefaultValueLiteral("");	
	
	m_comment_Attribute_annotatedElement->_setID(COMMENT_ATTRIBUTE_ANNOTATEDELEMENT);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeCommunicationPathContent()
{
	m_communicationPath_Class->setName("CommunicationPath");
	m_communicationPath_Class->setAbstract(false);
	m_communicationPath_Class->setInterface(false);
	
	m_communicationPath_Class->_setID(COMMUNICATIONPATH_CLASS);
	
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

void umlPackageImpl::initializeComponentContent()
{
	m_component_Class->setName("Component");
	m_component_Class->setAbstract(false);
	m_component_Class->setInterface(false);
	
	m_component_Class->_setID(COMPONENT_CLASS);
	
	/*
	 * EAttributes
	 */
	m_component_Attribute_isIndirectlyInstantiated = getComponent_Attribute_isIndirectlyInstantiated();
	m_component_Attribute_isIndirectlyInstantiated->setName("isIndirectlyInstantiated");
	m_component_Attribute_isIndirectlyInstantiated->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_component_Attribute_isIndirectlyInstantiated->setLowerBound(1);
	m_component_Attribute_isIndirectlyInstantiated->setUpperBound(1);
	m_component_Attribute_isIndirectlyInstantiated->setTransient(false);
	m_component_Attribute_isIndirectlyInstantiated->setVolatile(false);
	m_component_Attribute_isIndirectlyInstantiated->setChangeable(true);
	m_component_Attribute_isIndirectlyInstantiated->setUnsettable(false);
	m_component_Attribute_isIndirectlyInstantiated->setUnique(true);
	m_component_Attribute_isIndirectlyInstantiated->setDerived(false);
	m_component_Attribute_isIndirectlyInstantiated->setOrdered(false);
	m_component_Attribute_isIndirectlyInstantiated->setID(false);
	m_component_Attribute_isIndirectlyInstantiated->setDefaultValueLiteral("true");
	
	m_component_Attribute_isIndirectlyInstantiated->_setID(COMPONENT_ATTRIBUTE_ISINDIRECTLYINSTANTIATED);
	
	/*
	 * EReferences
	 */
	m_component_Attribute_packagedElement->setName("packagedElement");
	m_component_Attribute_packagedElement->setEType(getPackageableElement_Class());
	m_component_Attribute_packagedElement->setLowerBound(0);
	m_component_Attribute_packagedElement->setUpperBound(-1);
	m_component_Attribute_packagedElement->setTransient(false);
	m_component_Attribute_packagedElement->setVolatile(false);
	m_component_Attribute_packagedElement->setChangeable(true);
	m_component_Attribute_packagedElement->setUnsettable(false);
	m_component_Attribute_packagedElement->setUnique(true);
	m_component_Attribute_packagedElement->setDerived(false);
	m_component_Attribute_packagedElement->setOrdered(false);
	m_component_Attribute_packagedElement->setContainment(true);
	m_component_Attribute_packagedElement->setResolveProxies(true);
	m_component_Attribute_packagedElement->setDefaultValueLiteral("");	
	
	m_component_Attribute_packagedElement->_setID(COMPONENT_ATTRIBUTE_PACKAGEDELEMENT);
	m_component_Attribute_provided->setName("provided");
	m_component_Attribute_provided->setEType(getInterface_Class());
	m_component_Attribute_provided->setLowerBound(0);
	m_component_Attribute_provided->setUpperBound(-1);
	m_component_Attribute_provided->setTransient(true);
	m_component_Attribute_provided->setVolatile(true);
	m_component_Attribute_provided->setChangeable(false);
	m_component_Attribute_provided->setUnsettable(false);
	m_component_Attribute_provided->setUnique(true);
	m_component_Attribute_provided->setDerived(true);
	m_component_Attribute_provided->setOrdered(false);
	m_component_Attribute_provided->setContainment(false);
	m_component_Attribute_provided->setResolveProxies(true);
	m_component_Attribute_provided->setDefaultValueLiteral("");	
	
	m_component_Attribute_provided->_setID(COMPONENT_ATTRIBUTE_PROVIDED);
	m_component_Attribute_realization->setName("realization");
	m_component_Attribute_realization->setEType(getComponentRealization_Class());
	m_component_Attribute_realization->setLowerBound(0);
	m_component_Attribute_realization->setUpperBound(-1);
	m_component_Attribute_realization->setTransient(false);
	m_component_Attribute_realization->setVolatile(false);
	m_component_Attribute_realization->setChangeable(true);
	m_component_Attribute_realization->setUnsettable(false);
	m_component_Attribute_realization->setUnique(true);
	m_component_Attribute_realization->setDerived(false);
	m_component_Attribute_realization->setOrdered(false);
	m_component_Attribute_realization->setContainment(true);
	m_component_Attribute_realization->setResolveProxies(true);
	m_component_Attribute_realization->setDefaultValueLiteral("");	
	m_component_Attribute_realization->setEOpposite(uml::umlPackage::eInstance()->getComponentRealization_Attribute_abstraction());
	
	m_component_Attribute_realization->_setID(COMPONENT_ATTRIBUTE_REALIZATION);
	m_component_Attribute_required->setName("required");
	m_component_Attribute_required->setEType(getInterface_Class());
	m_component_Attribute_required->setLowerBound(0);
	m_component_Attribute_required->setUpperBound(-1);
	m_component_Attribute_required->setTransient(true);
	m_component_Attribute_required->setVolatile(true);
	m_component_Attribute_required->setChangeable(false);
	m_component_Attribute_required->setUnsettable(false);
	m_component_Attribute_required->setUnique(true);
	m_component_Attribute_required->setDerived(true);
	m_component_Attribute_required->setOrdered(false);
	m_component_Attribute_required->setContainment(false);
	m_component_Attribute_required->setResolveProxies(true);
	m_component_Attribute_required->setDefaultValueLiteral("");	
	
	m_component_Attribute_required->_setID(COMPONENT_ATTRIBUTE_REQUIRED);
	
	/*
	 * EOperations
	 */
	m_component_Operation_createOwnedClass_String_Boolean->setName("createOwnedClass");
	m_component_Operation_createOwnedClass_String_Boolean->setEType(getClass_Class());
	m_component_Operation_createOwnedClass_String_Boolean->setLowerBound(1);
	m_component_Operation_createOwnedClass_String_Boolean->setUpperBound(1);
	m_component_Operation_createOwnedClass_String_Boolean->setUnique(true);
	m_component_Operation_createOwnedClass_String_Boolean->setOrdered(false);
	
	m_component_Operation_createOwnedClass_String_Boolean->_setID(COMPONENT_OPERATION_CREATEOWNEDCLASS_STRING_BOOLEAN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_component_Operation_createOwnedClass_String_Boolean);
		parameter->setName("name");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_component_Operation_createOwnedClass_String_Boolean);
		parameter->setName("isAbstract");
		parameter->setEType(types::typesPackage::eInstance()->getBoolean_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_component_Operation_createOwnedEnumeration_String->setName("createOwnedEnumeration");
	m_component_Operation_createOwnedEnumeration_String->setEType(getEnumeration_Class());
	m_component_Operation_createOwnedEnumeration_String->setLowerBound(1);
	m_component_Operation_createOwnedEnumeration_String->setUpperBound(1);
	m_component_Operation_createOwnedEnumeration_String->setUnique(true);
	m_component_Operation_createOwnedEnumeration_String->setOrdered(false);
	
	m_component_Operation_createOwnedEnumeration_String->_setID(COMPONENT_OPERATION_CREATEOWNEDENUMERATION_STRING);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_component_Operation_createOwnedEnumeration_String);
		parameter->setName("name");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_component_Operation_createOwnedInterface_String->setName("createOwnedInterface");
	m_component_Operation_createOwnedInterface_String->setEType(getInterface_Class());
	m_component_Operation_createOwnedInterface_String->setLowerBound(1);
	m_component_Operation_createOwnedInterface_String->setUpperBound(1);
	m_component_Operation_createOwnedInterface_String->setUnique(true);
	m_component_Operation_createOwnedInterface_String->setOrdered(false);
	
	m_component_Operation_createOwnedInterface_String->_setID(COMPONENT_OPERATION_CREATEOWNEDINTERFACE_STRING);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_component_Operation_createOwnedInterface_String);
		parameter->setName("name");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_component_Operation_createOwnedPrimitiveType_String->setName("createOwnedPrimitiveType");
	m_component_Operation_createOwnedPrimitiveType_String->setEType(getPrimitiveType_Class());
	m_component_Operation_createOwnedPrimitiveType_String->setLowerBound(1);
	m_component_Operation_createOwnedPrimitiveType_String->setUpperBound(1);
	m_component_Operation_createOwnedPrimitiveType_String->setUnique(true);
	m_component_Operation_createOwnedPrimitiveType_String->setOrdered(false);
	
	m_component_Operation_createOwnedPrimitiveType_String->_setID(COMPONENT_OPERATION_CREATEOWNEDPRIMITIVETYPE_STRING);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_component_Operation_createOwnedPrimitiveType_String);
		parameter->setName("name");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_component_Operation_getProvideds->setName("getProvideds");
	m_component_Operation_getProvideds->setEType(getInterface_Class());
	m_component_Operation_getProvideds->setLowerBound(0);
	m_component_Operation_getProvideds->setUpperBound(-1);
	m_component_Operation_getProvideds->setUnique(true);
	m_component_Operation_getProvideds->setOrdered(false);
	
	m_component_Operation_getProvideds->_setID(COMPONENT_OPERATION_GETPROVIDEDS);
	
	
	m_component_Operation_getRequireds->setName("getRequireds");
	m_component_Operation_getRequireds->setEType(getInterface_Class());
	m_component_Operation_getRequireds->setLowerBound(0);
	m_component_Operation_getRequireds->setUpperBound(-1);
	m_component_Operation_getRequireds->setUnique(true);
	m_component_Operation_getRequireds->setOrdered(false);
	
	m_component_Operation_getRequireds->_setID(COMPONENT_OPERATION_GETREQUIREDS);
	
	
	
}

void umlPackageImpl::initializeComponentRealizationContent()
{
	m_componentRealization_Class->setName("ComponentRealization");
	m_componentRealization_Class->setAbstract(false);
	m_componentRealization_Class->setInterface(false);
	
	m_componentRealization_Class->_setID(COMPONENTREALIZATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_componentRealization_Attribute_abstraction->setName("abstraction");
	m_componentRealization_Attribute_abstraction->setEType(getComponent_Class());
	m_componentRealization_Attribute_abstraction->setLowerBound(0);
	m_componentRealization_Attribute_abstraction->setUpperBound(1);
	m_componentRealization_Attribute_abstraction->setTransient(false);
	m_componentRealization_Attribute_abstraction->setVolatile(false);
	m_componentRealization_Attribute_abstraction->setChangeable(true);
	m_componentRealization_Attribute_abstraction->setUnsettable(false);
	m_componentRealization_Attribute_abstraction->setUnique(true);
	m_componentRealization_Attribute_abstraction->setDerived(false);
	m_componentRealization_Attribute_abstraction->setOrdered(false);
	m_componentRealization_Attribute_abstraction->setContainment(false);
	m_componentRealization_Attribute_abstraction->setResolveProxies(true);
	m_componentRealization_Attribute_abstraction->setDefaultValueLiteral("");	
	m_componentRealization_Attribute_abstraction->setEOpposite(uml::umlPackage::eInstance()->getComponent_Attribute_realization());
	
	m_componentRealization_Attribute_abstraction->_setID(COMPONENTREALIZATION_ATTRIBUTE_ABSTRACTION);
	m_componentRealization_Attribute_realizingClassifier->setName("realizingClassifier");
	m_componentRealization_Attribute_realizingClassifier->setEType(getClassifier_Class());
	m_componentRealization_Attribute_realizingClassifier->setLowerBound(1);
	m_componentRealization_Attribute_realizingClassifier->setUpperBound(-1);
	m_componentRealization_Attribute_realizingClassifier->setTransient(false);
	m_componentRealization_Attribute_realizingClassifier->setVolatile(false);
	m_componentRealization_Attribute_realizingClassifier->setChangeable(true);
	m_componentRealization_Attribute_realizingClassifier->setUnsettable(false);
	m_componentRealization_Attribute_realizingClassifier->setUnique(true);
	m_componentRealization_Attribute_realizingClassifier->setDerived(false);
	m_componentRealization_Attribute_realizingClassifier->setOrdered(false);
	m_componentRealization_Attribute_realizingClassifier->setContainment(false);
	m_componentRealization_Attribute_realizingClassifier->setResolveProxies(true);
	m_componentRealization_Attribute_realizingClassifier->setDefaultValueLiteral("");	
	
	m_componentRealization_Attribute_realizingClassifier->_setID(COMPONENTREALIZATION_ATTRIBUTE_REALIZINGCLASSIFIER);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeConditionalNodeContent()
{
	m_conditionalNode_Class->setName("ConditionalNode");
	m_conditionalNode_Class->setAbstract(false);
	m_conditionalNode_Class->setInterface(false);
	
	m_conditionalNode_Class->_setID(CONDITIONALNODE_CLASS);
	
	/*
	 * EAttributes
	 */
	m_conditionalNode_Attribute_isAssured = getConditionalNode_Attribute_isAssured();
	m_conditionalNode_Attribute_isAssured->setName("isAssured");
	m_conditionalNode_Attribute_isAssured->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_conditionalNode_Attribute_isAssured->setLowerBound(1);
	m_conditionalNode_Attribute_isAssured->setUpperBound(1);
	m_conditionalNode_Attribute_isAssured->setTransient(false);
	m_conditionalNode_Attribute_isAssured->setVolatile(false);
	m_conditionalNode_Attribute_isAssured->setChangeable(true);
	m_conditionalNode_Attribute_isAssured->setUnsettable(false);
	m_conditionalNode_Attribute_isAssured->setUnique(true);
	m_conditionalNode_Attribute_isAssured->setDerived(false);
	m_conditionalNode_Attribute_isAssured->setOrdered(false);
	m_conditionalNode_Attribute_isAssured->setID(false);
	m_conditionalNode_Attribute_isAssured->setDefaultValueLiteral("false");
	
	m_conditionalNode_Attribute_isAssured->_setID(CONDITIONALNODE_ATTRIBUTE_ISASSURED);
	m_conditionalNode_Attribute_isDeterminate = getConditionalNode_Attribute_isDeterminate();
	m_conditionalNode_Attribute_isDeterminate->setName("isDeterminate");
	m_conditionalNode_Attribute_isDeterminate->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_conditionalNode_Attribute_isDeterminate->setLowerBound(1);
	m_conditionalNode_Attribute_isDeterminate->setUpperBound(1);
	m_conditionalNode_Attribute_isDeterminate->setTransient(false);
	m_conditionalNode_Attribute_isDeterminate->setVolatile(false);
	m_conditionalNode_Attribute_isDeterminate->setChangeable(true);
	m_conditionalNode_Attribute_isDeterminate->setUnsettable(false);
	m_conditionalNode_Attribute_isDeterminate->setUnique(true);
	m_conditionalNode_Attribute_isDeterminate->setDerived(false);
	m_conditionalNode_Attribute_isDeterminate->setOrdered(false);
	m_conditionalNode_Attribute_isDeterminate->setID(false);
	m_conditionalNode_Attribute_isDeterminate->setDefaultValueLiteral("false");
	
	m_conditionalNode_Attribute_isDeterminate->_setID(CONDITIONALNODE_ATTRIBUTE_ISDETERMINATE);
	
	/*
	 * EReferences
	 */
	m_conditionalNode_Attribute_clause->setName("clause");
	m_conditionalNode_Attribute_clause->setEType(getClause_Class());
	m_conditionalNode_Attribute_clause->setLowerBound(1);
	m_conditionalNode_Attribute_clause->setUpperBound(-1);
	m_conditionalNode_Attribute_clause->setTransient(false);
	m_conditionalNode_Attribute_clause->setVolatile(false);
	m_conditionalNode_Attribute_clause->setChangeable(true);
	m_conditionalNode_Attribute_clause->setUnsettable(false);
	m_conditionalNode_Attribute_clause->setUnique(true);
	m_conditionalNode_Attribute_clause->setDerived(false);
	m_conditionalNode_Attribute_clause->setOrdered(false);
	m_conditionalNode_Attribute_clause->setContainment(true);
	m_conditionalNode_Attribute_clause->setResolveProxies(true);
	m_conditionalNode_Attribute_clause->setDefaultValueLiteral("");	
	
	m_conditionalNode_Attribute_clause->_setID(CONDITIONALNODE_ATTRIBUTE_CLAUSE);
	m_conditionalNode_Attribute_result->setName("result");
	m_conditionalNode_Attribute_result->setEType(getOutputPin_Class());
	m_conditionalNode_Attribute_result->setLowerBound(0);
	m_conditionalNode_Attribute_result->setUpperBound(-1);
	m_conditionalNode_Attribute_result->setTransient(false);
	m_conditionalNode_Attribute_result->setVolatile(false);
	m_conditionalNode_Attribute_result->setChangeable(true);
	m_conditionalNode_Attribute_result->setUnsettable(false);
	m_conditionalNode_Attribute_result->setUnique(true);
	m_conditionalNode_Attribute_result->setDerived(false);
	m_conditionalNode_Attribute_result->setOrdered(true);
	m_conditionalNode_Attribute_result->setContainment(true);
	m_conditionalNode_Attribute_result->setResolveProxies(true);
	m_conditionalNode_Attribute_result->setDefaultValueLiteral("");	
	
	m_conditionalNode_Attribute_result->_setID(CONDITIONALNODE_ATTRIBUTE_RESULT);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeConnectableElementContent()
{
	m_connectableElement_Class->setName("ConnectableElement");
	m_connectableElement_Class->setAbstract(true);
	m_connectableElement_Class->setInterface(false);
	
	m_connectableElement_Class->_setID(CONNECTABLEELEMENT_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_connectableElement_Attribute_end->setName("end");
	m_connectableElement_Attribute_end->setEType(getConnectorEnd_Class());
	m_connectableElement_Attribute_end->setLowerBound(0);
	m_connectableElement_Attribute_end->setUpperBound(-1);
	m_connectableElement_Attribute_end->setTransient(true);
	m_connectableElement_Attribute_end->setVolatile(true);
	m_connectableElement_Attribute_end->setChangeable(false);
	m_connectableElement_Attribute_end->setUnsettable(false);
	m_connectableElement_Attribute_end->setUnique(true);
	m_connectableElement_Attribute_end->setDerived(true);
	m_connectableElement_Attribute_end->setOrdered(false);
	m_connectableElement_Attribute_end->setContainment(false);
	m_connectableElement_Attribute_end->setResolveProxies(true);
	m_connectableElement_Attribute_end->setDefaultValueLiteral("");	
	
	m_connectableElement_Attribute_end->_setID(CONNECTABLEELEMENT_ATTRIBUTE_END);
	
	/*
	 * EOperations
	 */
	m_connectableElement_Operation_getEnds->setName("getEnds");
	m_connectableElement_Operation_getEnds->setEType(getConnectorEnd_Class());
	m_connectableElement_Operation_getEnds->setLowerBound(0);
	m_connectableElement_Operation_getEnds->setUpperBound(-1);
	m_connectableElement_Operation_getEnds->setUnique(true);
	m_connectableElement_Operation_getEnds->setOrdered(false);
	
	m_connectableElement_Operation_getEnds->_setID(CONNECTABLEELEMENT_OPERATION_GETENDS);
	
	
	
}

void umlPackageImpl::initializeConnectableElementTemplateParameterContent()
{
	m_connectableElementTemplateParameter_Class->setName("ConnectableElementTemplateParameter");
	m_connectableElementTemplateParameter_Class->setAbstract(false);
	m_connectableElementTemplateParameter_Class->setInterface(false);
	
	m_connectableElementTemplateParameter_Class->_setID(CONNECTABLEELEMENTTEMPLATEPARAMETER_CLASS);
	
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

void umlPackageImpl::initializeConnectionPointReferenceContent()
{
	m_connectionPointReference_Class->setName("ConnectionPointReference");
	m_connectionPointReference_Class->setAbstract(false);
	m_connectionPointReference_Class->setInterface(false);
	
	m_connectionPointReference_Class->_setID(CONNECTIONPOINTREFERENCE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_connectionPointReference_Attribute_entry->setName("entry");
	m_connectionPointReference_Attribute_entry->setEType(getPseudostate_Class());
	m_connectionPointReference_Attribute_entry->setLowerBound(0);
	m_connectionPointReference_Attribute_entry->setUpperBound(-1);
	m_connectionPointReference_Attribute_entry->setTransient(false);
	m_connectionPointReference_Attribute_entry->setVolatile(false);
	m_connectionPointReference_Attribute_entry->setChangeable(true);
	m_connectionPointReference_Attribute_entry->setUnsettable(false);
	m_connectionPointReference_Attribute_entry->setUnique(true);
	m_connectionPointReference_Attribute_entry->setDerived(false);
	m_connectionPointReference_Attribute_entry->setOrdered(false);
	m_connectionPointReference_Attribute_entry->setContainment(false);
	m_connectionPointReference_Attribute_entry->setResolveProxies(true);
	m_connectionPointReference_Attribute_entry->setDefaultValueLiteral("");	
	
	m_connectionPointReference_Attribute_entry->_setID(CONNECTIONPOINTREFERENCE_ATTRIBUTE_ENTRY);
	m_connectionPointReference_Attribute_exit->setName("exit");
	m_connectionPointReference_Attribute_exit->setEType(getPseudostate_Class());
	m_connectionPointReference_Attribute_exit->setLowerBound(0);
	m_connectionPointReference_Attribute_exit->setUpperBound(-1);
	m_connectionPointReference_Attribute_exit->setTransient(false);
	m_connectionPointReference_Attribute_exit->setVolatile(false);
	m_connectionPointReference_Attribute_exit->setChangeable(true);
	m_connectionPointReference_Attribute_exit->setUnsettable(false);
	m_connectionPointReference_Attribute_exit->setUnique(true);
	m_connectionPointReference_Attribute_exit->setDerived(false);
	m_connectionPointReference_Attribute_exit->setOrdered(false);
	m_connectionPointReference_Attribute_exit->setContainment(false);
	m_connectionPointReference_Attribute_exit->setResolveProxies(true);
	m_connectionPointReference_Attribute_exit->setDefaultValueLiteral("");	
	
	m_connectionPointReference_Attribute_exit->_setID(CONNECTIONPOINTREFERENCE_ATTRIBUTE_EXIT);
	m_connectionPointReference_Attribute_state->setName("state");
	m_connectionPointReference_Attribute_state->setEType(getState_Class());
	m_connectionPointReference_Attribute_state->setLowerBound(0);
	m_connectionPointReference_Attribute_state->setUpperBound(1);
	m_connectionPointReference_Attribute_state->setTransient(false);
	m_connectionPointReference_Attribute_state->setVolatile(false);
	m_connectionPointReference_Attribute_state->setChangeable(true);
	m_connectionPointReference_Attribute_state->setUnsettable(false);
	m_connectionPointReference_Attribute_state->setUnique(true);
	m_connectionPointReference_Attribute_state->setDerived(false);
	m_connectionPointReference_Attribute_state->setOrdered(false);
	m_connectionPointReference_Attribute_state->setContainment(false);
	m_connectionPointReference_Attribute_state->setResolveProxies(true);
	m_connectionPointReference_Attribute_state->setDefaultValueLiteral("");	
	m_connectionPointReference_Attribute_state->setEOpposite(uml::umlPackage::eInstance()->getState_Attribute_connection());
	
	m_connectionPointReference_Attribute_state->_setID(CONNECTIONPOINTREFERENCE_ATTRIBUTE_STATE);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeConnectorContent()
{
	m_connector_Class->setName("Connector");
	m_connector_Class->setAbstract(false);
	m_connector_Class->setInterface(false);
	
	m_connector_Class->_setID(CONNECTOR_CLASS);
	
	/*
	 * EAttributes
	 */
	m_connector_Attribute_kind = getConnector_Attribute_kind();
	m_connector_Attribute_kind->setName("kind");
	m_connector_Attribute_kind->setEType(getConnectorKind_Class());
	m_connector_Attribute_kind->setLowerBound(1);
	m_connector_Attribute_kind->setUpperBound(1);
	m_connector_Attribute_kind->setTransient(true);
	m_connector_Attribute_kind->setVolatile(true);
	m_connector_Attribute_kind->setChangeable(false);
	m_connector_Attribute_kind->setUnsettable(false);
	m_connector_Attribute_kind->setUnique(true);
	m_connector_Attribute_kind->setDerived(true);
	m_connector_Attribute_kind->setOrdered(false);
	m_connector_Attribute_kind->setID(false);
	m_connector_Attribute_kind->setDefaultValueLiteral("");
	
	m_connector_Attribute_kind->_setID(CONNECTOR_ATTRIBUTE_KIND);
	
	/*
	 * EReferences
	 */
	m_connector_Attribute_contract->setName("contract");
	m_connector_Attribute_contract->setEType(getBehavior_Class());
	m_connector_Attribute_contract->setLowerBound(0);
	m_connector_Attribute_contract->setUpperBound(-1);
	m_connector_Attribute_contract->setTransient(false);
	m_connector_Attribute_contract->setVolatile(false);
	m_connector_Attribute_contract->setChangeable(true);
	m_connector_Attribute_contract->setUnsettable(false);
	m_connector_Attribute_contract->setUnique(true);
	m_connector_Attribute_contract->setDerived(false);
	m_connector_Attribute_contract->setOrdered(false);
	m_connector_Attribute_contract->setContainment(false);
	m_connector_Attribute_contract->setResolveProxies(true);
	m_connector_Attribute_contract->setDefaultValueLiteral("");	
	
	m_connector_Attribute_contract->_setID(CONNECTOR_ATTRIBUTE_CONTRACT);
	m_connector_Attribute_end->setName("end");
	m_connector_Attribute_end->setEType(getConnectorEnd_Class());
	m_connector_Attribute_end->setLowerBound(2);
	m_connector_Attribute_end->setUpperBound(-1);
	m_connector_Attribute_end->setTransient(false);
	m_connector_Attribute_end->setVolatile(false);
	m_connector_Attribute_end->setChangeable(true);
	m_connector_Attribute_end->setUnsettable(false);
	m_connector_Attribute_end->setUnique(true);
	m_connector_Attribute_end->setDerived(false);
	m_connector_Attribute_end->setOrdered(true);
	m_connector_Attribute_end->setContainment(true);
	m_connector_Attribute_end->setResolveProxies(true);
	m_connector_Attribute_end->setDefaultValueLiteral("");	
	m_connector_Attribute_end->setEOpposite(uml::umlPackage::eInstance()->getConnectorEnd_Attribute_connector());
	
	m_connector_Attribute_end->_setID(CONNECTOR_ATTRIBUTE_END);
	m_connector_Attribute_redefinedConnector->setName("redefinedConnector");
	m_connector_Attribute_redefinedConnector->setEType(getConnector_Class());
	m_connector_Attribute_redefinedConnector->setLowerBound(0);
	m_connector_Attribute_redefinedConnector->setUpperBound(-1);
	m_connector_Attribute_redefinedConnector->setTransient(false);
	m_connector_Attribute_redefinedConnector->setVolatile(false);
	m_connector_Attribute_redefinedConnector->setChangeable(true);
	m_connector_Attribute_redefinedConnector->setUnsettable(false);
	m_connector_Attribute_redefinedConnector->setUnique(true);
	m_connector_Attribute_redefinedConnector->setDerived(false);
	m_connector_Attribute_redefinedConnector->setOrdered(false);
	m_connector_Attribute_redefinedConnector->setContainment(false);
	m_connector_Attribute_redefinedConnector->setResolveProxies(true);
	m_connector_Attribute_redefinedConnector->setDefaultValueLiteral("");	
	
	m_connector_Attribute_redefinedConnector->_setID(CONNECTOR_ATTRIBUTE_REDEFINEDCONNECTOR);
	m_connector_Attribute_structuredClassifier->setName("structuredClassifier");
	m_connector_Attribute_structuredClassifier->setEType(getStructuredClassifier_Class());
	m_connector_Attribute_structuredClassifier->setLowerBound(0);
	m_connector_Attribute_structuredClassifier->setUpperBound(1);
	m_connector_Attribute_structuredClassifier->setTransient(false);
	m_connector_Attribute_structuredClassifier->setVolatile(false);
	m_connector_Attribute_structuredClassifier->setChangeable(true);
	m_connector_Attribute_structuredClassifier->setUnsettable(false);
	m_connector_Attribute_structuredClassifier->setUnique(true);
	m_connector_Attribute_structuredClassifier->setDerived(false);
	m_connector_Attribute_structuredClassifier->setOrdered(true);
	m_connector_Attribute_structuredClassifier->setContainment(false);
	m_connector_Attribute_structuredClassifier->setResolveProxies(true);
	m_connector_Attribute_structuredClassifier->setDefaultValueLiteral("");	
	m_connector_Attribute_structuredClassifier->setEOpposite(uml::umlPackage::eInstance()->getStructuredClassifier_Attribute_ownedConnector());
	
	m_connector_Attribute_structuredClassifier->_setID(CONNECTOR_ATTRIBUTE_STRUCTUREDCLASSIFIER);
	m_connector_Attribute_type->setName("type");
	m_connector_Attribute_type->setEType(getAssociation_Class());
	m_connector_Attribute_type->setLowerBound(0);
	m_connector_Attribute_type->setUpperBound(1);
	m_connector_Attribute_type->setTransient(false);
	m_connector_Attribute_type->setVolatile(false);
	m_connector_Attribute_type->setChangeable(true);
	m_connector_Attribute_type->setUnsettable(false);
	m_connector_Attribute_type->setUnique(true);
	m_connector_Attribute_type->setDerived(false);
	m_connector_Attribute_type->setOrdered(false);
	m_connector_Attribute_type->setContainment(false);
	m_connector_Attribute_type->setResolveProxies(true);
	m_connector_Attribute_type->setDefaultValueLiteral("");	
	
	m_connector_Attribute_type->_setID(CONNECTOR_ATTRIBUTE_TYPE);
	
	/*
	 * EOperations
	 */
	m_connector_Operation_getKind->setName("getKind");
	m_connector_Operation_getKind->setEType(getConnectorKind_Class());
	m_connector_Operation_getKind->setLowerBound(1);
	m_connector_Operation_getKind->setUpperBound(1);
	m_connector_Operation_getKind->setUnique(true);
	m_connector_Operation_getKind->setOrdered(false);
	
	m_connector_Operation_getKind->_setID(CONNECTOR_OPERATION_GETKIND);
	
	
	
}

void umlPackageImpl::initializeConnectorEndContent()
{
	m_connectorEnd_Class->setName("ConnectorEnd");
	m_connectorEnd_Class->setAbstract(false);
	m_connectorEnd_Class->setInterface(false);
	
	m_connectorEnd_Class->_setID(CONNECTOREND_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_connectorEnd_Attribute_connector->setName("connector");
	m_connectorEnd_Attribute_connector->setEType(getConnector_Class());
	m_connectorEnd_Attribute_connector->setLowerBound(1);
	m_connectorEnd_Attribute_connector->setUpperBound(1);
	m_connectorEnd_Attribute_connector->setTransient(false);
	m_connectorEnd_Attribute_connector->setVolatile(false);
	m_connectorEnd_Attribute_connector->setChangeable(true);
	m_connectorEnd_Attribute_connector->setUnsettable(false);
	m_connectorEnd_Attribute_connector->setUnique(true);
	m_connectorEnd_Attribute_connector->setDerived(false);
	m_connectorEnd_Attribute_connector->setOrdered(true);
	m_connectorEnd_Attribute_connector->setContainment(false);
	m_connectorEnd_Attribute_connector->setResolveProxies(true);
	m_connectorEnd_Attribute_connector->setDefaultValueLiteral("");	
	m_connectorEnd_Attribute_connector->setEOpposite(uml::umlPackage::eInstance()->getConnector_Attribute_end());
	
	m_connectorEnd_Attribute_connector->_setID(CONNECTOREND_ATTRIBUTE_CONNECTOR);
	m_connectorEnd_Attribute_definingEnd->setName("definingEnd");
	m_connectorEnd_Attribute_definingEnd->setEType(getProperty_Class());
	m_connectorEnd_Attribute_definingEnd->setLowerBound(0);
	m_connectorEnd_Attribute_definingEnd->setUpperBound(1);
	m_connectorEnd_Attribute_definingEnd->setTransient(true);
	m_connectorEnd_Attribute_definingEnd->setVolatile(true);
	m_connectorEnd_Attribute_definingEnd->setChangeable(false);
	m_connectorEnd_Attribute_definingEnd->setUnsettable(false);
	m_connectorEnd_Attribute_definingEnd->setUnique(true);
	m_connectorEnd_Attribute_definingEnd->setDerived(true);
	m_connectorEnd_Attribute_definingEnd->setOrdered(false);
	m_connectorEnd_Attribute_definingEnd->setContainment(false);
	m_connectorEnd_Attribute_definingEnd->setResolveProxies(true);
	m_connectorEnd_Attribute_definingEnd->setDefaultValueLiteral("");	
	
	m_connectorEnd_Attribute_definingEnd->_setID(CONNECTOREND_ATTRIBUTE_DEFININGEND);
	m_connectorEnd_Attribute_partWithPort->setName("partWithPort");
	m_connectorEnd_Attribute_partWithPort->setEType(getProperty_Class());
	m_connectorEnd_Attribute_partWithPort->setLowerBound(0);
	m_connectorEnd_Attribute_partWithPort->setUpperBound(1);
	m_connectorEnd_Attribute_partWithPort->setTransient(false);
	m_connectorEnd_Attribute_partWithPort->setVolatile(false);
	m_connectorEnd_Attribute_partWithPort->setChangeable(true);
	m_connectorEnd_Attribute_partWithPort->setUnsettable(false);
	m_connectorEnd_Attribute_partWithPort->setUnique(true);
	m_connectorEnd_Attribute_partWithPort->setDerived(false);
	m_connectorEnd_Attribute_partWithPort->setOrdered(false);
	m_connectorEnd_Attribute_partWithPort->setContainment(false);
	m_connectorEnd_Attribute_partWithPort->setResolveProxies(true);
	m_connectorEnd_Attribute_partWithPort->setDefaultValueLiteral("");	
	
	m_connectorEnd_Attribute_partWithPort->_setID(CONNECTOREND_ATTRIBUTE_PARTWITHPORT);
	m_connectorEnd_Attribute_role->setName("role");
	m_connectorEnd_Attribute_role->setEType(getConnectableElement_Class());
	m_connectorEnd_Attribute_role->setLowerBound(1);
	m_connectorEnd_Attribute_role->setUpperBound(1);
	m_connectorEnd_Attribute_role->setTransient(false);
	m_connectorEnd_Attribute_role->setVolatile(false);
	m_connectorEnd_Attribute_role->setChangeable(true);
	m_connectorEnd_Attribute_role->setUnsettable(false);
	m_connectorEnd_Attribute_role->setUnique(true);
	m_connectorEnd_Attribute_role->setDerived(false);
	m_connectorEnd_Attribute_role->setOrdered(false);
	m_connectorEnd_Attribute_role->setContainment(false);
	m_connectorEnd_Attribute_role->setResolveProxies(true);
	m_connectorEnd_Attribute_role->setDefaultValueLiteral("");	
	
	m_connectorEnd_Attribute_role->_setID(CONNECTOREND_ATTRIBUTE_ROLE);
	
	/*
	 * EOperations
	 */
	m_connectorEnd_Operation_getDefiningEnd->setName("getDefiningEnd");
	m_connectorEnd_Operation_getDefiningEnd->setEType(getProperty_Class());
	m_connectorEnd_Operation_getDefiningEnd->setLowerBound(0);
	m_connectorEnd_Operation_getDefiningEnd->setUpperBound(1);
	m_connectorEnd_Operation_getDefiningEnd->setUnique(true);
	m_connectorEnd_Operation_getDefiningEnd->setOrdered(false);
	
	m_connectorEnd_Operation_getDefiningEnd->_setID(CONNECTOREND_OPERATION_GETDEFININGEND);
	
	
	
}

void umlPackageImpl::initializeConsiderIgnoreFragmentContent()
{
	m_considerIgnoreFragment_Class->setName("ConsiderIgnoreFragment");
	m_considerIgnoreFragment_Class->setAbstract(false);
	m_considerIgnoreFragment_Class->setInterface(false);
	
	m_considerIgnoreFragment_Class->_setID(CONSIDERIGNOREFRAGMENT_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_considerIgnoreFragment_Attribute_message->setName("message");
	m_considerIgnoreFragment_Attribute_message->setEType(getNamedElement_Class());
	m_considerIgnoreFragment_Attribute_message->setLowerBound(0);
	m_considerIgnoreFragment_Attribute_message->setUpperBound(-1);
	m_considerIgnoreFragment_Attribute_message->setTransient(false);
	m_considerIgnoreFragment_Attribute_message->setVolatile(false);
	m_considerIgnoreFragment_Attribute_message->setChangeable(true);
	m_considerIgnoreFragment_Attribute_message->setUnsettable(false);
	m_considerIgnoreFragment_Attribute_message->setUnique(true);
	m_considerIgnoreFragment_Attribute_message->setDerived(false);
	m_considerIgnoreFragment_Attribute_message->setOrdered(false);
	m_considerIgnoreFragment_Attribute_message->setContainment(false);
	m_considerIgnoreFragment_Attribute_message->setResolveProxies(true);
	m_considerIgnoreFragment_Attribute_message->setDefaultValueLiteral("");	
	
	m_considerIgnoreFragment_Attribute_message->_setID(CONSIDERIGNOREFRAGMENT_ATTRIBUTE_MESSAGE);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeConstraintContent()
{
	m_constraint_Class->setName("Constraint");
	m_constraint_Class->setAbstract(false);
	m_constraint_Class->setInterface(false);
	
	m_constraint_Class->_setID(CONSTRAINT_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_constraint_Attribute_constrainedElement->setName("constrainedElement");
	m_constraint_Attribute_constrainedElement->setEType(getElement_Class());
	m_constraint_Attribute_constrainedElement->setLowerBound(0);
	m_constraint_Attribute_constrainedElement->setUpperBound(-1);
	m_constraint_Attribute_constrainedElement->setTransient(false);
	m_constraint_Attribute_constrainedElement->setVolatile(false);
	m_constraint_Attribute_constrainedElement->setChangeable(true);
	m_constraint_Attribute_constrainedElement->setUnsettable(false);
	m_constraint_Attribute_constrainedElement->setUnique(true);
	m_constraint_Attribute_constrainedElement->setDerived(false);
	m_constraint_Attribute_constrainedElement->setOrdered(true);
	m_constraint_Attribute_constrainedElement->setContainment(false);
	m_constraint_Attribute_constrainedElement->setResolveProxies(true);
	m_constraint_Attribute_constrainedElement->setDefaultValueLiteral("");	
	
	m_constraint_Attribute_constrainedElement->_setID(CONSTRAINT_ATTRIBUTE_CONSTRAINEDELEMENT);
	m_constraint_Attribute_context->setName("context");
	m_constraint_Attribute_context->setEType(getNamespace_Class());
	m_constraint_Attribute_context->setLowerBound(0);
	m_constraint_Attribute_context->setUpperBound(1);
	m_constraint_Attribute_context->setTransient(false);
	m_constraint_Attribute_context->setVolatile(false);
	m_constraint_Attribute_context->setChangeable(true);
	m_constraint_Attribute_context->setUnsettable(false);
	m_constraint_Attribute_context->setUnique(true);
	m_constraint_Attribute_context->setDerived(false);
	m_constraint_Attribute_context->setOrdered(false);
	m_constraint_Attribute_context->setContainment(false);
	m_constraint_Attribute_context->setResolveProxies(true);
	m_constraint_Attribute_context->setDefaultValueLiteral("");	
	m_constraint_Attribute_context->setEOpposite(uml::umlPackage::eInstance()->getNamespace_Attribute_ownedRule());
	
	m_constraint_Attribute_context->_setID(CONSTRAINT_ATTRIBUTE_CONTEXT);
	m_constraint_Attribute_specification->setName("specification");
	m_constraint_Attribute_specification->setEType(getValueSpecification_Class());
	m_constraint_Attribute_specification->setLowerBound(1);
	m_constraint_Attribute_specification->setUpperBound(1);
	m_constraint_Attribute_specification->setTransient(false);
	m_constraint_Attribute_specification->setVolatile(false);
	m_constraint_Attribute_specification->setChangeable(true);
	m_constraint_Attribute_specification->setUnsettable(false);
	m_constraint_Attribute_specification->setUnique(true);
	m_constraint_Attribute_specification->setDerived(false);
	m_constraint_Attribute_specification->setOrdered(false);
	m_constraint_Attribute_specification->setContainment(true);
	m_constraint_Attribute_specification->setResolveProxies(true);
	m_constraint_Attribute_specification->setDefaultValueLiteral("");	
	
	m_constraint_Attribute_specification->_setID(CONSTRAINT_ATTRIBUTE_SPECIFICATION);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeContinuationContent()
{
	m_continuation_Class->setName("Continuation");
	m_continuation_Class->setAbstract(false);
	m_continuation_Class->setInterface(false);
	
	m_continuation_Class->_setID(CONTINUATION_CLASS);
	
	/*
	 * EAttributes
	 */
	m_continuation_Attribute_setting = getContinuation_Attribute_setting();
	m_continuation_Attribute_setting->setName("setting");
	m_continuation_Attribute_setting->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_continuation_Attribute_setting->setLowerBound(1);
	m_continuation_Attribute_setting->setUpperBound(1);
	m_continuation_Attribute_setting->setTransient(false);
	m_continuation_Attribute_setting->setVolatile(false);
	m_continuation_Attribute_setting->setChangeable(true);
	m_continuation_Attribute_setting->setUnsettable(false);
	m_continuation_Attribute_setting->setUnique(true);
	m_continuation_Attribute_setting->setDerived(false);
	m_continuation_Attribute_setting->setOrdered(false);
	m_continuation_Attribute_setting->setID(false);
	m_continuation_Attribute_setting->setDefaultValueLiteral("true");
	
	m_continuation_Attribute_setting->_setID(CONTINUATION_ATTRIBUTE_SETTING);
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeControlFlowContent()
{
	m_controlFlow_Class->setName("ControlFlow");
	m_controlFlow_Class->setAbstract(false);
	m_controlFlow_Class->setInterface(false);
	
	m_controlFlow_Class->_setID(CONTROLFLOW_CLASS);
	
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

void umlPackageImpl::initializeControlNodeContent()
{
	m_controlNode_Class->setName("ControlNode");
	m_controlNode_Class->setAbstract(true);
	m_controlNode_Class->setInterface(false);
	
	m_controlNode_Class->_setID(CONTROLNODE_CLASS);
	
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

void umlPackageImpl::initializeCreateLinkActionContent()
{
	m_createLinkAction_Class->setName("CreateLinkAction");
	m_createLinkAction_Class->setAbstract(false);
	m_createLinkAction_Class->setInterface(false);
	
	m_createLinkAction_Class->_setID(CREATELINKACTION_CLASS);
	
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

void umlPackageImpl::initializeCreateLinkObjectActionContent()
{
	m_createLinkObjectAction_Class->setName("CreateLinkObjectAction");
	m_createLinkObjectAction_Class->setAbstract(false);
	m_createLinkObjectAction_Class->setInterface(false);
	
	m_createLinkObjectAction_Class->_setID(CREATELINKOBJECTACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_createLinkObjectAction_Attribute_result->setName("result");
	m_createLinkObjectAction_Attribute_result->setEType(getOutputPin_Class());
	m_createLinkObjectAction_Attribute_result->setLowerBound(1);
	m_createLinkObjectAction_Attribute_result->setUpperBound(1);
	m_createLinkObjectAction_Attribute_result->setTransient(false);
	m_createLinkObjectAction_Attribute_result->setVolatile(false);
	m_createLinkObjectAction_Attribute_result->setChangeable(true);
	m_createLinkObjectAction_Attribute_result->setUnsettable(false);
	m_createLinkObjectAction_Attribute_result->setUnique(true);
	m_createLinkObjectAction_Attribute_result->setDerived(false);
	m_createLinkObjectAction_Attribute_result->setOrdered(false);
	m_createLinkObjectAction_Attribute_result->setContainment(true);
	m_createLinkObjectAction_Attribute_result->setResolveProxies(true);
	m_createLinkObjectAction_Attribute_result->setDefaultValueLiteral("");	
	
	m_createLinkObjectAction_Attribute_result->_setID(CREATELINKOBJECTACTION_ATTRIBUTE_RESULT);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeCreateObjectActionContent()
{
	m_createObjectAction_Class->setName("CreateObjectAction");
	m_createObjectAction_Class->setAbstract(false);
	m_createObjectAction_Class->setInterface(false);
	
	m_createObjectAction_Class->_setID(CREATEOBJECTACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_createObjectAction_Attribute_classifier->setName("classifier");
	m_createObjectAction_Attribute_classifier->setEType(getClassifier_Class());
	m_createObjectAction_Attribute_classifier->setLowerBound(1);
	m_createObjectAction_Attribute_classifier->setUpperBound(1);
	m_createObjectAction_Attribute_classifier->setTransient(false);
	m_createObjectAction_Attribute_classifier->setVolatile(false);
	m_createObjectAction_Attribute_classifier->setChangeable(true);
	m_createObjectAction_Attribute_classifier->setUnsettable(false);
	m_createObjectAction_Attribute_classifier->setUnique(true);
	m_createObjectAction_Attribute_classifier->setDerived(false);
	m_createObjectAction_Attribute_classifier->setOrdered(false);
	m_createObjectAction_Attribute_classifier->setContainment(false);
	m_createObjectAction_Attribute_classifier->setResolveProxies(true);
	m_createObjectAction_Attribute_classifier->setDefaultValueLiteral("");	
	
	m_createObjectAction_Attribute_classifier->_setID(CREATEOBJECTACTION_ATTRIBUTE_CLASSIFIER);
	m_createObjectAction_Attribute_result->setName("result");
	m_createObjectAction_Attribute_result->setEType(getOutputPin_Class());
	m_createObjectAction_Attribute_result->setLowerBound(1);
	m_createObjectAction_Attribute_result->setUpperBound(1);
	m_createObjectAction_Attribute_result->setTransient(false);
	m_createObjectAction_Attribute_result->setVolatile(false);
	m_createObjectAction_Attribute_result->setChangeable(true);
	m_createObjectAction_Attribute_result->setUnsettable(false);
	m_createObjectAction_Attribute_result->setUnique(true);
	m_createObjectAction_Attribute_result->setDerived(false);
	m_createObjectAction_Attribute_result->setOrdered(false);
	m_createObjectAction_Attribute_result->setContainment(true);
	m_createObjectAction_Attribute_result->setResolveProxies(true);
	m_createObjectAction_Attribute_result->setDefaultValueLiteral("");	
	m_createObjectAction_Attribute_result->setEOpposite(uml::umlPackage::eInstance()->getOutputPin_Attribute_createObjectAction());
	
	m_createObjectAction_Attribute_result->_setID(CREATEOBJECTACTION_ATTRIBUTE_RESULT);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeDataStoreNodeContent()
{
	m_dataStoreNode_Class->setName("DataStoreNode");
	m_dataStoreNode_Class->setAbstract(false);
	m_dataStoreNode_Class->setInterface(false);
	
	m_dataStoreNode_Class->_setID(DATASTORENODE_CLASS);
	
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

void umlPackageImpl::initializeDataTypeContent()
{
	m_dataType_Class->setName("DataType");
	m_dataType_Class->setAbstract(false);
	m_dataType_Class->setInterface(false);
	
	m_dataType_Class->_setID(DATATYPE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_dataType_Attribute_ownedAttribute->setName("ownedAttribute");
	m_dataType_Attribute_ownedAttribute->setEType(getProperty_Class());
	m_dataType_Attribute_ownedAttribute->setLowerBound(0);
	m_dataType_Attribute_ownedAttribute->setUpperBound(-1);
	m_dataType_Attribute_ownedAttribute->setTransient(false);
	m_dataType_Attribute_ownedAttribute->setVolatile(false);
	m_dataType_Attribute_ownedAttribute->setChangeable(true);
	m_dataType_Attribute_ownedAttribute->setUnsettable(false);
	m_dataType_Attribute_ownedAttribute->setUnique(true);
	m_dataType_Attribute_ownedAttribute->setDerived(false);
	m_dataType_Attribute_ownedAttribute->setOrdered(true);
	m_dataType_Attribute_ownedAttribute->setContainment(true);
	m_dataType_Attribute_ownedAttribute->setResolveProxies(true);
	m_dataType_Attribute_ownedAttribute->setDefaultValueLiteral("");	
	m_dataType_Attribute_ownedAttribute->setEOpposite(uml::umlPackage::eInstance()->getProperty_Attribute_datatype());
	
	m_dataType_Attribute_ownedAttribute->_setID(DATATYPE_ATTRIBUTE_OWNEDATTRIBUTE);
	m_dataType_Attribute_ownedOperation->setName("ownedOperation");
	m_dataType_Attribute_ownedOperation->setEType(getOperation_Class());
	m_dataType_Attribute_ownedOperation->setLowerBound(0);
	m_dataType_Attribute_ownedOperation->setUpperBound(-1);
	m_dataType_Attribute_ownedOperation->setTransient(false);
	m_dataType_Attribute_ownedOperation->setVolatile(false);
	m_dataType_Attribute_ownedOperation->setChangeable(true);
	m_dataType_Attribute_ownedOperation->setUnsettable(false);
	m_dataType_Attribute_ownedOperation->setUnique(true);
	m_dataType_Attribute_ownedOperation->setDerived(false);
	m_dataType_Attribute_ownedOperation->setOrdered(true);
	m_dataType_Attribute_ownedOperation->setContainment(true);
	m_dataType_Attribute_ownedOperation->setResolveProxies(true);
	m_dataType_Attribute_ownedOperation->setDefaultValueLiteral("");	
	m_dataType_Attribute_ownedOperation->setEOpposite(uml::umlPackage::eInstance()->getOperation_Attribute_datatype());
	
	m_dataType_Attribute_ownedOperation->_setID(DATATYPE_ATTRIBUTE_OWNEDOPERATION);
	
	/*
	 * EOperations
	 */
	m_dataType_Operation_createOwnedAttribute_String_UnlimitedNatural->setName("createOwnedAttribute");
	m_dataType_Operation_createOwnedAttribute_String_UnlimitedNatural->setEType(getProperty_Class());
	m_dataType_Operation_createOwnedAttribute_String_UnlimitedNatural->setLowerBound(1);
	m_dataType_Operation_createOwnedAttribute_String_UnlimitedNatural->setUpperBound(1);
	m_dataType_Operation_createOwnedAttribute_String_UnlimitedNatural->setUnique(true);
	m_dataType_Operation_createOwnedAttribute_String_UnlimitedNatural->setOrdered(false);
	
	m_dataType_Operation_createOwnedAttribute_String_UnlimitedNatural->_setID(DATATYPE_OPERATION_CREATEOWNEDATTRIBUTE_STRING_UNLIMITEDNATURAL);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_dataType_Operation_createOwnedAttribute_String_UnlimitedNatural);
		parameter->setName("name");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_dataType_Operation_createOwnedAttribute_String_UnlimitedNatural);
		parameter->setName("type");
		parameter->setEType(getType_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_dataType_Operation_createOwnedAttribute_String_UnlimitedNatural);
		parameter->setName("lower");
		parameter->setEType(types::typesPackage::eInstance()->getInteger_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_dataType_Operation_createOwnedAttribute_String_UnlimitedNatural);
		parameter->setName("upper");
		parameter->setEType(types::typesPackage::eInstance()->getUnlimitedNatural_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_dataType_Operation_createOwnedOperation_String_Type->setName("createOwnedOperation");
	m_dataType_Operation_createOwnedOperation_String_Type->setEType(getOperation_Class());
	m_dataType_Operation_createOwnedOperation_String_Type->setLowerBound(1);
	m_dataType_Operation_createOwnedOperation_String_Type->setUpperBound(1);
	m_dataType_Operation_createOwnedOperation_String_Type->setUnique(true);
	m_dataType_Operation_createOwnedOperation_String_Type->setOrdered(false);
	
	m_dataType_Operation_createOwnedOperation_String_Type->_setID(DATATYPE_OPERATION_CREATEOWNEDOPERATION_STRING_TYPE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_dataType_Operation_createOwnedOperation_String_Type);
		parameter->setName("name");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_dataType_Operation_createOwnedOperation_String_Type);
		parameter->setName("parameterNames");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_dataType_Operation_createOwnedOperation_String_Type);
		parameter->setName("parameterTypes");
		parameter->setEType(getType_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_dataType_Operation_createOwnedOperation_String_Type);
		parameter->setName("returnType");
		parameter->setEType(getType_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void umlPackageImpl::initializeDecisionNodeContent()
{
	m_decisionNode_Class->setName("DecisionNode");
	m_decisionNode_Class->setAbstract(false);
	m_decisionNode_Class->setInterface(false);
	
	m_decisionNode_Class->_setID(DECISIONNODE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_decisionNode_Attribute_decisionInput->setName("decisionInput");
	m_decisionNode_Attribute_decisionInput->setEType(getBehavior_Class());
	m_decisionNode_Attribute_decisionInput->setLowerBound(0);
	m_decisionNode_Attribute_decisionInput->setUpperBound(1);
	m_decisionNode_Attribute_decisionInput->setTransient(false);
	m_decisionNode_Attribute_decisionInput->setVolatile(false);
	m_decisionNode_Attribute_decisionInput->setChangeable(true);
	m_decisionNode_Attribute_decisionInput->setUnsettable(false);
	m_decisionNode_Attribute_decisionInput->setUnique(true);
	m_decisionNode_Attribute_decisionInput->setDerived(false);
	m_decisionNode_Attribute_decisionInput->setOrdered(false);
	m_decisionNode_Attribute_decisionInput->setContainment(false);
	m_decisionNode_Attribute_decisionInput->setResolveProxies(true);
	m_decisionNode_Attribute_decisionInput->setDefaultValueLiteral("");	
	
	m_decisionNode_Attribute_decisionInput->_setID(DECISIONNODE_ATTRIBUTE_DECISIONINPUT);
	m_decisionNode_Attribute_decisionInputFlow->setName("decisionInputFlow");
	m_decisionNode_Attribute_decisionInputFlow->setEType(getObjectFlow_Class());
	m_decisionNode_Attribute_decisionInputFlow->setLowerBound(0);
	m_decisionNode_Attribute_decisionInputFlow->setUpperBound(1);
	m_decisionNode_Attribute_decisionInputFlow->setTransient(false);
	m_decisionNode_Attribute_decisionInputFlow->setVolatile(false);
	m_decisionNode_Attribute_decisionInputFlow->setChangeable(true);
	m_decisionNode_Attribute_decisionInputFlow->setUnsettable(false);
	m_decisionNode_Attribute_decisionInputFlow->setUnique(true);
	m_decisionNode_Attribute_decisionInputFlow->setDerived(false);
	m_decisionNode_Attribute_decisionInputFlow->setOrdered(false);
	m_decisionNode_Attribute_decisionInputFlow->setContainment(false);
	m_decisionNode_Attribute_decisionInputFlow->setResolveProxies(true);
	m_decisionNode_Attribute_decisionInputFlow->setDefaultValueLiteral("");	
	
	m_decisionNode_Attribute_decisionInputFlow->_setID(DECISIONNODE_ATTRIBUTE_DECISIONINPUTFLOW);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeDependencyContent()
{
	m_dependency_Class->setName("Dependency");
	m_dependency_Class->setAbstract(false);
	m_dependency_Class->setInterface(false);
	
	m_dependency_Class->_setID(DEPENDENCY_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_dependency_Attribute_client->setName("client");
	m_dependency_Attribute_client->setEType(getNamedElement_Class());
	m_dependency_Attribute_client->setLowerBound(1);
	m_dependency_Attribute_client->setUpperBound(-1);
	m_dependency_Attribute_client->setTransient(false);
	m_dependency_Attribute_client->setVolatile(false);
	m_dependency_Attribute_client->setChangeable(true);
	m_dependency_Attribute_client->setUnsettable(false);
	m_dependency_Attribute_client->setUnique(true);
	m_dependency_Attribute_client->setDerived(false);
	m_dependency_Attribute_client->setOrdered(false);
	m_dependency_Attribute_client->setContainment(false);
	m_dependency_Attribute_client->setResolveProxies(true);
	m_dependency_Attribute_client->setDefaultValueLiteral("");	
	
	m_dependency_Attribute_client->_setID(DEPENDENCY_ATTRIBUTE_CLIENT);
	m_dependency_Attribute_supplier->setName("supplier");
	m_dependency_Attribute_supplier->setEType(getNamedElement_Class());
	m_dependency_Attribute_supplier->setLowerBound(1);
	m_dependency_Attribute_supplier->setUpperBound(-1);
	m_dependency_Attribute_supplier->setTransient(false);
	m_dependency_Attribute_supplier->setVolatile(false);
	m_dependency_Attribute_supplier->setChangeable(true);
	m_dependency_Attribute_supplier->setUnsettable(false);
	m_dependency_Attribute_supplier->setUnique(true);
	m_dependency_Attribute_supplier->setDerived(false);
	m_dependency_Attribute_supplier->setOrdered(false);
	m_dependency_Attribute_supplier->setContainment(false);
	m_dependency_Attribute_supplier->setResolveProxies(true);
	m_dependency_Attribute_supplier->setDefaultValueLiteral("");	
	
	m_dependency_Attribute_supplier->_setID(DEPENDENCY_ATTRIBUTE_SUPPLIER);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeDeployedArtifactContent()
{
	m_deployedArtifact_Class->setName("DeployedArtifact");
	m_deployedArtifact_Class->setAbstract(true);
	m_deployedArtifact_Class->setInterface(false);
	
	m_deployedArtifact_Class->_setID(DEPLOYEDARTIFACT_CLASS);
	
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

void umlPackageImpl::initializeDeploymentContent()
{
	m_deployment_Class->setName("Deployment");
	m_deployment_Class->setAbstract(false);
	m_deployment_Class->setInterface(false);
	
	m_deployment_Class->_setID(DEPLOYMENT_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_deployment_Attribute_configuration->setName("configuration");
	m_deployment_Attribute_configuration->setEType(getDeploymentSpecification_Class());
	m_deployment_Attribute_configuration->setLowerBound(0);
	m_deployment_Attribute_configuration->setUpperBound(-1);
	m_deployment_Attribute_configuration->setTransient(false);
	m_deployment_Attribute_configuration->setVolatile(false);
	m_deployment_Attribute_configuration->setChangeable(true);
	m_deployment_Attribute_configuration->setUnsettable(false);
	m_deployment_Attribute_configuration->setUnique(true);
	m_deployment_Attribute_configuration->setDerived(false);
	m_deployment_Attribute_configuration->setOrdered(false);
	m_deployment_Attribute_configuration->setContainment(true);
	m_deployment_Attribute_configuration->setResolveProxies(true);
	m_deployment_Attribute_configuration->setDefaultValueLiteral("");	
	m_deployment_Attribute_configuration->setEOpposite(uml::umlPackage::eInstance()->getDeploymentSpecification_Attribute_deployment());
	
	m_deployment_Attribute_configuration->_setID(DEPLOYMENT_ATTRIBUTE_CONFIGURATION);
	m_deployment_Attribute_deployedArtifact->setName("deployedArtifact");
	m_deployment_Attribute_deployedArtifact->setEType(getDeployedArtifact_Class());
	m_deployment_Attribute_deployedArtifact->setLowerBound(0);
	m_deployment_Attribute_deployedArtifact->setUpperBound(-1);
	m_deployment_Attribute_deployedArtifact->setTransient(false);
	m_deployment_Attribute_deployedArtifact->setVolatile(false);
	m_deployment_Attribute_deployedArtifact->setChangeable(true);
	m_deployment_Attribute_deployedArtifact->setUnsettable(false);
	m_deployment_Attribute_deployedArtifact->setUnique(true);
	m_deployment_Attribute_deployedArtifact->setDerived(false);
	m_deployment_Attribute_deployedArtifact->setOrdered(false);
	m_deployment_Attribute_deployedArtifact->setContainment(false);
	m_deployment_Attribute_deployedArtifact->setResolveProxies(true);
	m_deployment_Attribute_deployedArtifact->setDefaultValueLiteral("");	
	
	m_deployment_Attribute_deployedArtifact->_setID(DEPLOYMENT_ATTRIBUTE_DEPLOYEDARTIFACT);
	m_deployment_Attribute_location->setName("location");
	m_deployment_Attribute_location->setEType(getDeploymentTarget_Class());
	m_deployment_Attribute_location->setLowerBound(1);
	m_deployment_Attribute_location->setUpperBound(1);
	m_deployment_Attribute_location->setTransient(false);
	m_deployment_Attribute_location->setVolatile(false);
	m_deployment_Attribute_location->setChangeable(true);
	m_deployment_Attribute_location->setUnsettable(false);
	m_deployment_Attribute_location->setUnique(true);
	m_deployment_Attribute_location->setDerived(false);
	m_deployment_Attribute_location->setOrdered(false);
	m_deployment_Attribute_location->setContainment(false);
	m_deployment_Attribute_location->setResolveProxies(true);
	m_deployment_Attribute_location->setDefaultValueLiteral("");	
	m_deployment_Attribute_location->setEOpposite(uml::umlPackage::eInstance()->getDeploymentTarget_Attribute_deployment());
	
	m_deployment_Attribute_location->_setID(DEPLOYMENT_ATTRIBUTE_LOCATION);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeDeploymentSpecificationContent()
{
	m_deploymentSpecification_Class->setName("DeploymentSpecification");
	m_deploymentSpecification_Class->setAbstract(false);
	m_deploymentSpecification_Class->setInterface(false);
	
	m_deploymentSpecification_Class->_setID(DEPLOYMENTSPECIFICATION_CLASS);
	
	/*
	 * EAttributes
	 */
	m_deploymentSpecification_Attribute_deploymentLocation = getDeploymentSpecification_Attribute_deploymentLocation();
	m_deploymentSpecification_Attribute_deploymentLocation->setName("deploymentLocation");
	m_deploymentSpecification_Attribute_deploymentLocation->setEType(types::typesPackage::eInstance()->getString_Class());
	m_deploymentSpecification_Attribute_deploymentLocation->setLowerBound(0);
	m_deploymentSpecification_Attribute_deploymentLocation->setUpperBound(1);
	m_deploymentSpecification_Attribute_deploymentLocation->setTransient(false);
	m_deploymentSpecification_Attribute_deploymentLocation->setVolatile(false);
	m_deploymentSpecification_Attribute_deploymentLocation->setChangeable(true);
	m_deploymentSpecification_Attribute_deploymentLocation->setUnsettable(true);
	m_deploymentSpecification_Attribute_deploymentLocation->setUnique(true);
	m_deploymentSpecification_Attribute_deploymentLocation->setDerived(false);
	m_deploymentSpecification_Attribute_deploymentLocation->setOrdered(false);
	m_deploymentSpecification_Attribute_deploymentLocation->setID(false);
	m_deploymentSpecification_Attribute_deploymentLocation->setDefaultValueLiteral("");
	
	m_deploymentSpecification_Attribute_deploymentLocation->_setID(DEPLOYMENTSPECIFICATION_ATTRIBUTE_DEPLOYMENTLOCATION);
	m_deploymentSpecification_Attribute_executionLocation = getDeploymentSpecification_Attribute_executionLocation();
	m_deploymentSpecification_Attribute_executionLocation->setName("executionLocation");
	m_deploymentSpecification_Attribute_executionLocation->setEType(types::typesPackage::eInstance()->getString_Class());
	m_deploymentSpecification_Attribute_executionLocation->setLowerBound(0);
	m_deploymentSpecification_Attribute_executionLocation->setUpperBound(1);
	m_deploymentSpecification_Attribute_executionLocation->setTransient(false);
	m_deploymentSpecification_Attribute_executionLocation->setVolatile(false);
	m_deploymentSpecification_Attribute_executionLocation->setChangeable(true);
	m_deploymentSpecification_Attribute_executionLocation->setUnsettable(true);
	m_deploymentSpecification_Attribute_executionLocation->setUnique(true);
	m_deploymentSpecification_Attribute_executionLocation->setDerived(false);
	m_deploymentSpecification_Attribute_executionLocation->setOrdered(false);
	m_deploymentSpecification_Attribute_executionLocation->setID(false);
	m_deploymentSpecification_Attribute_executionLocation->setDefaultValueLiteral("");
	
	m_deploymentSpecification_Attribute_executionLocation->_setID(DEPLOYMENTSPECIFICATION_ATTRIBUTE_EXECUTIONLOCATION);
	
	/*
	 * EReferences
	 */
	m_deploymentSpecification_Attribute_deployment->setName("deployment");
	m_deploymentSpecification_Attribute_deployment->setEType(getDeployment_Class());
	m_deploymentSpecification_Attribute_deployment->setLowerBound(0);
	m_deploymentSpecification_Attribute_deployment->setUpperBound(1);
	m_deploymentSpecification_Attribute_deployment->setTransient(false);
	m_deploymentSpecification_Attribute_deployment->setVolatile(false);
	m_deploymentSpecification_Attribute_deployment->setChangeable(true);
	m_deploymentSpecification_Attribute_deployment->setUnsettable(false);
	m_deploymentSpecification_Attribute_deployment->setUnique(true);
	m_deploymentSpecification_Attribute_deployment->setDerived(false);
	m_deploymentSpecification_Attribute_deployment->setOrdered(false);
	m_deploymentSpecification_Attribute_deployment->setContainment(false);
	m_deploymentSpecification_Attribute_deployment->setResolveProxies(true);
	m_deploymentSpecification_Attribute_deployment->setDefaultValueLiteral("");	
	m_deploymentSpecification_Attribute_deployment->setEOpposite(uml::umlPackage::eInstance()->getDeployment_Attribute_configuration());
	
	m_deploymentSpecification_Attribute_deployment->_setID(DEPLOYMENTSPECIFICATION_ATTRIBUTE_DEPLOYMENT);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeDeploymentTargetContent()
{
	m_deploymentTarget_Class->setName("DeploymentTarget");
	m_deploymentTarget_Class->setAbstract(true);
	m_deploymentTarget_Class->setInterface(false);
	
	m_deploymentTarget_Class->_setID(DEPLOYMENTTARGET_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_deploymentTarget_Attribute_deployedElement->setName("deployedElement");
	m_deploymentTarget_Attribute_deployedElement->setEType(getPackageableElement_Class());
	m_deploymentTarget_Attribute_deployedElement->setLowerBound(0);
	m_deploymentTarget_Attribute_deployedElement->setUpperBound(-1);
	m_deploymentTarget_Attribute_deployedElement->setTransient(true);
	m_deploymentTarget_Attribute_deployedElement->setVolatile(true);
	m_deploymentTarget_Attribute_deployedElement->setChangeable(false);
	m_deploymentTarget_Attribute_deployedElement->setUnsettable(false);
	m_deploymentTarget_Attribute_deployedElement->setUnique(true);
	m_deploymentTarget_Attribute_deployedElement->setDerived(true);
	m_deploymentTarget_Attribute_deployedElement->setOrdered(false);
	m_deploymentTarget_Attribute_deployedElement->setContainment(false);
	m_deploymentTarget_Attribute_deployedElement->setResolveProxies(true);
	m_deploymentTarget_Attribute_deployedElement->setDefaultValueLiteral("");	
	
	m_deploymentTarget_Attribute_deployedElement->_setID(DEPLOYMENTTARGET_ATTRIBUTE_DEPLOYEDELEMENT);
	m_deploymentTarget_Attribute_deployment->setName("deployment");
	m_deploymentTarget_Attribute_deployment->setEType(getDeployment_Class());
	m_deploymentTarget_Attribute_deployment->setLowerBound(0);
	m_deploymentTarget_Attribute_deployment->setUpperBound(-1);
	m_deploymentTarget_Attribute_deployment->setTransient(false);
	m_deploymentTarget_Attribute_deployment->setVolatile(false);
	m_deploymentTarget_Attribute_deployment->setChangeable(true);
	m_deploymentTarget_Attribute_deployment->setUnsettable(false);
	m_deploymentTarget_Attribute_deployment->setUnique(true);
	m_deploymentTarget_Attribute_deployment->setDerived(false);
	m_deploymentTarget_Attribute_deployment->setOrdered(false);
	m_deploymentTarget_Attribute_deployment->setContainment(true);
	m_deploymentTarget_Attribute_deployment->setResolveProxies(true);
	m_deploymentTarget_Attribute_deployment->setDefaultValueLiteral("");	
	m_deploymentTarget_Attribute_deployment->setEOpposite(uml::umlPackage::eInstance()->getDeployment_Attribute_location());
	
	m_deploymentTarget_Attribute_deployment->_setID(DEPLOYMENTTARGET_ATTRIBUTE_DEPLOYMENT);
	
	/*
	 * EOperations
	 */
	m_deploymentTarget_Operation_getDeployedElements->setName("getDeployedElements");
	m_deploymentTarget_Operation_getDeployedElements->setEType(getPackageableElement_Class());
	m_deploymentTarget_Operation_getDeployedElements->setLowerBound(0);
	m_deploymentTarget_Operation_getDeployedElements->setUpperBound(-1);
	m_deploymentTarget_Operation_getDeployedElements->setUnique(true);
	m_deploymentTarget_Operation_getDeployedElements->setOrdered(false);
	
	m_deploymentTarget_Operation_getDeployedElements->_setID(DEPLOYMENTTARGET_OPERATION_GETDEPLOYEDELEMENTS);
	
	
	
}

void umlPackageImpl::initializeDestroyLinkActionContent()
{
	m_destroyLinkAction_Class->setName("DestroyLinkAction");
	m_destroyLinkAction_Class->setAbstract(false);
	m_destroyLinkAction_Class->setInterface(false);
	
	m_destroyLinkAction_Class->_setID(DESTROYLINKACTION_CLASS);
	
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

void umlPackageImpl::initializeDestroyObjectActionContent()
{
	m_destroyObjectAction_Class->setName("DestroyObjectAction");
	m_destroyObjectAction_Class->setAbstract(false);
	m_destroyObjectAction_Class->setInterface(false);
	
	m_destroyObjectAction_Class->_setID(DESTROYOBJECTACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	m_destroyObjectAction_Attribute_isDestroyLinks = getDestroyObjectAction_Attribute_isDestroyLinks();
	m_destroyObjectAction_Attribute_isDestroyLinks->setName("isDestroyLinks");
	m_destroyObjectAction_Attribute_isDestroyLinks->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_destroyObjectAction_Attribute_isDestroyLinks->setLowerBound(1);
	m_destroyObjectAction_Attribute_isDestroyLinks->setUpperBound(1);
	m_destroyObjectAction_Attribute_isDestroyLinks->setTransient(false);
	m_destroyObjectAction_Attribute_isDestroyLinks->setVolatile(false);
	m_destroyObjectAction_Attribute_isDestroyLinks->setChangeable(true);
	m_destroyObjectAction_Attribute_isDestroyLinks->setUnsettable(false);
	m_destroyObjectAction_Attribute_isDestroyLinks->setUnique(true);
	m_destroyObjectAction_Attribute_isDestroyLinks->setDerived(false);
	m_destroyObjectAction_Attribute_isDestroyLinks->setOrdered(false);
	m_destroyObjectAction_Attribute_isDestroyLinks->setID(false);
	m_destroyObjectAction_Attribute_isDestroyLinks->setDefaultValueLiteral("false");
	
	m_destroyObjectAction_Attribute_isDestroyLinks->_setID(DESTROYOBJECTACTION_ATTRIBUTE_ISDESTROYLINKS);
	m_destroyObjectAction_Attribute_isDestroyOwnedObjects = getDestroyObjectAction_Attribute_isDestroyOwnedObjects();
	m_destroyObjectAction_Attribute_isDestroyOwnedObjects->setName("isDestroyOwnedObjects");
	m_destroyObjectAction_Attribute_isDestroyOwnedObjects->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_destroyObjectAction_Attribute_isDestroyOwnedObjects->setLowerBound(1);
	m_destroyObjectAction_Attribute_isDestroyOwnedObjects->setUpperBound(1);
	m_destroyObjectAction_Attribute_isDestroyOwnedObjects->setTransient(false);
	m_destroyObjectAction_Attribute_isDestroyOwnedObjects->setVolatile(false);
	m_destroyObjectAction_Attribute_isDestroyOwnedObjects->setChangeable(true);
	m_destroyObjectAction_Attribute_isDestroyOwnedObjects->setUnsettable(false);
	m_destroyObjectAction_Attribute_isDestroyOwnedObjects->setUnique(true);
	m_destroyObjectAction_Attribute_isDestroyOwnedObjects->setDerived(false);
	m_destroyObjectAction_Attribute_isDestroyOwnedObjects->setOrdered(false);
	m_destroyObjectAction_Attribute_isDestroyOwnedObjects->setID(false);
	m_destroyObjectAction_Attribute_isDestroyOwnedObjects->setDefaultValueLiteral("false");
	
	m_destroyObjectAction_Attribute_isDestroyOwnedObjects->_setID(DESTROYOBJECTACTION_ATTRIBUTE_ISDESTROYOWNEDOBJECTS);
	
	/*
	 * EReferences
	 */
	m_destroyObjectAction_Attribute_target->setName("target");
	m_destroyObjectAction_Attribute_target->setEType(getInputPin_Class());
	m_destroyObjectAction_Attribute_target->setLowerBound(1);
	m_destroyObjectAction_Attribute_target->setUpperBound(1);
	m_destroyObjectAction_Attribute_target->setTransient(false);
	m_destroyObjectAction_Attribute_target->setVolatile(false);
	m_destroyObjectAction_Attribute_target->setChangeable(true);
	m_destroyObjectAction_Attribute_target->setUnsettable(false);
	m_destroyObjectAction_Attribute_target->setUnique(true);
	m_destroyObjectAction_Attribute_target->setDerived(false);
	m_destroyObjectAction_Attribute_target->setOrdered(false);
	m_destroyObjectAction_Attribute_target->setContainment(true);
	m_destroyObjectAction_Attribute_target->setResolveProxies(true);
	m_destroyObjectAction_Attribute_target->setDefaultValueLiteral("");	
	m_destroyObjectAction_Attribute_target->setEOpposite(uml::umlPackage::eInstance()->getInputPin_Attribute_destroyObjectAction());
	
	m_destroyObjectAction_Attribute_target->_setID(DESTROYOBJECTACTION_ATTRIBUTE_TARGET);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeDestructionOccurrenceSpecificationContent()
{
	m_destructionOccurrenceSpecification_Class->setName("DestructionOccurrenceSpecification");
	m_destructionOccurrenceSpecification_Class->setAbstract(false);
	m_destructionOccurrenceSpecification_Class->setInterface(false);
	
	m_destructionOccurrenceSpecification_Class->_setID(DESTRUCTIONOCCURRENCESPECIFICATION_CLASS);
	
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

void umlPackageImpl::initializeDeviceContent()
{
	m_device_Class->setName("Device");
	m_device_Class->setAbstract(false);
	m_device_Class->setInterface(false);
	
	m_device_Class->_setID(DEVICE_CLASS);
	
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

void umlPackageImpl::initializeDirectedRelationshipContent()
{
	m_directedRelationship_Class->setName("DirectedRelationship");
	m_directedRelationship_Class->setAbstract(true);
	m_directedRelationship_Class->setInterface(false);
	
	m_directedRelationship_Class->_setID(DIRECTEDRELATIONSHIP_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_directedRelationship_Attribute_source->setName("source");
	m_directedRelationship_Attribute_source->setEType(getElement_Class());
	m_directedRelationship_Attribute_source->setLowerBound(1);
	m_directedRelationship_Attribute_source->setUpperBound(-1);
	m_directedRelationship_Attribute_source->setTransient(true);
	m_directedRelationship_Attribute_source->setVolatile(true);
	m_directedRelationship_Attribute_source->setChangeable(false);
	m_directedRelationship_Attribute_source->setUnsettable(false);
	m_directedRelationship_Attribute_source->setUnique(true);
	m_directedRelationship_Attribute_source->setDerived(true);
	m_directedRelationship_Attribute_source->setOrdered(false);
	m_directedRelationship_Attribute_source->setContainment(false);
	m_directedRelationship_Attribute_source->setResolveProxies(true);
	m_directedRelationship_Attribute_source->setDefaultValueLiteral("");	
	
	m_directedRelationship_Attribute_source->_setID(DIRECTEDRELATIONSHIP_ATTRIBUTE_SOURCE);
	m_directedRelationship_Attribute_target->setName("target");
	m_directedRelationship_Attribute_target->setEType(getElement_Class());
	m_directedRelationship_Attribute_target->setLowerBound(1);
	m_directedRelationship_Attribute_target->setUpperBound(-1);
	m_directedRelationship_Attribute_target->setTransient(true);
	m_directedRelationship_Attribute_target->setVolatile(true);
	m_directedRelationship_Attribute_target->setChangeable(false);
	m_directedRelationship_Attribute_target->setUnsettable(false);
	m_directedRelationship_Attribute_target->setUnique(true);
	m_directedRelationship_Attribute_target->setDerived(true);
	m_directedRelationship_Attribute_target->setOrdered(false);
	m_directedRelationship_Attribute_target->setContainment(false);
	m_directedRelationship_Attribute_target->setResolveProxies(true);
	m_directedRelationship_Attribute_target->setDefaultValueLiteral("");	
	
	m_directedRelationship_Attribute_target->_setID(DIRECTEDRELATIONSHIP_ATTRIBUTE_TARGET);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeDurationContent()
{
	m_duration_Class->setName("Duration");
	m_duration_Class->setAbstract(false);
	m_duration_Class->setInterface(false);
	
	m_duration_Class->_setID(DURATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_duration_Attribute_expr->setName("expr");
	m_duration_Attribute_expr->setEType(getValueSpecification_Class());
	m_duration_Attribute_expr->setLowerBound(0);
	m_duration_Attribute_expr->setUpperBound(1);
	m_duration_Attribute_expr->setTransient(false);
	m_duration_Attribute_expr->setVolatile(false);
	m_duration_Attribute_expr->setChangeable(true);
	m_duration_Attribute_expr->setUnsettable(false);
	m_duration_Attribute_expr->setUnique(true);
	m_duration_Attribute_expr->setDerived(false);
	m_duration_Attribute_expr->setOrdered(false);
	m_duration_Attribute_expr->setContainment(true);
	m_duration_Attribute_expr->setResolveProxies(true);
	m_duration_Attribute_expr->setDefaultValueLiteral("");	
	
	m_duration_Attribute_expr->_setID(DURATION_ATTRIBUTE_EXPR);
	m_duration_Attribute_observation->setName("observation");
	m_duration_Attribute_observation->setEType(getObservation_Class());
	m_duration_Attribute_observation->setLowerBound(0);
	m_duration_Attribute_observation->setUpperBound(-1);
	m_duration_Attribute_observation->setTransient(false);
	m_duration_Attribute_observation->setVolatile(false);
	m_duration_Attribute_observation->setChangeable(true);
	m_duration_Attribute_observation->setUnsettable(false);
	m_duration_Attribute_observation->setUnique(true);
	m_duration_Attribute_observation->setDerived(false);
	m_duration_Attribute_observation->setOrdered(false);
	m_duration_Attribute_observation->setContainment(false);
	m_duration_Attribute_observation->setResolveProxies(true);
	m_duration_Attribute_observation->setDefaultValueLiteral("");	
	
	m_duration_Attribute_observation->_setID(DURATION_ATTRIBUTE_OBSERVATION);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeDurationConstraintContent()
{
	m_durationConstraint_Class->setName("DurationConstraint");
	m_durationConstraint_Class->setAbstract(false);
	m_durationConstraint_Class->setInterface(false);
	
	m_durationConstraint_Class->_setID(DURATIONCONSTRAINT_CLASS);
	
	/*
	 * EAttributes
	 */
	m_durationConstraint_Attribute_firstEvent = getDurationConstraint_Attribute_firstEvent();
	m_durationConstraint_Attribute_firstEvent->setName("firstEvent");
	m_durationConstraint_Attribute_firstEvent->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_durationConstraint_Attribute_firstEvent->setLowerBound(0);
	m_durationConstraint_Attribute_firstEvent->setUpperBound(2);
	m_durationConstraint_Attribute_firstEvent->setTransient(false);
	m_durationConstraint_Attribute_firstEvent->setVolatile(false);
	m_durationConstraint_Attribute_firstEvent->setChangeable(true);
	m_durationConstraint_Attribute_firstEvent->setUnsettable(false);
	m_durationConstraint_Attribute_firstEvent->setUnique(true);
	m_durationConstraint_Attribute_firstEvent->setDerived(false);
	m_durationConstraint_Attribute_firstEvent->setOrdered(false);
	m_durationConstraint_Attribute_firstEvent->setID(false);
	m_durationConstraint_Attribute_firstEvent->setDefaultValueLiteral("");
	
	m_durationConstraint_Attribute_firstEvent->_setID(DURATIONCONSTRAINT_ATTRIBUTE_FIRSTEVENT);
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeDurationIntervalContent()
{
	m_durationInterval_Class->setName("DurationInterval");
	m_durationInterval_Class->setAbstract(false);
	m_durationInterval_Class->setInterface(false);
	
	m_durationInterval_Class->_setID(DURATIONINTERVAL_CLASS);
	
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

void umlPackageImpl::initializeDurationObservationContent()
{
	m_durationObservation_Class->setName("DurationObservation");
	m_durationObservation_Class->setAbstract(false);
	m_durationObservation_Class->setInterface(false);
	
	m_durationObservation_Class->_setID(DURATIONOBSERVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	m_durationObservation_Attribute_firstEvent = getDurationObservation_Attribute_firstEvent();
	m_durationObservation_Attribute_firstEvent->setName("firstEvent");
	m_durationObservation_Attribute_firstEvent->setEType(ecore::ecorePackage::eInstance()->getEBoolean_Class());
	m_durationObservation_Attribute_firstEvent->setLowerBound(0);
	m_durationObservation_Attribute_firstEvent->setUpperBound(2);
	m_durationObservation_Attribute_firstEvent->setTransient(false);
	m_durationObservation_Attribute_firstEvent->setVolatile(false);
	m_durationObservation_Attribute_firstEvent->setChangeable(true);
	m_durationObservation_Attribute_firstEvent->setUnsettable(false);
	m_durationObservation_Attribute_firstEvent->setUnique(true);
	m_durationObservation_Attribute_firstEvent->setDerived(false);
	m_durationObservation_Attribute_firstEvent->setOrdered(false);
	m_durationObservation_Attribute_firstEvent->setID(false);
	m_durationObservation_Attribute_firstEvent->setDefaultValueLiteral("");
	
	m_durationObservation_Attribute_firstEvent->_setID(DURATIONOBSERVATION_ATTRIBUTE_FIRSTEVENT);
	
	/*
	 * EReferences
	 */
	m_durationObservation_Attribute_event->setName("event");
	m_durationObservation_Attribute_event->setEType(getNamedElement_Class());
	m_durationObservation_Attribute_event->setLowerBound(1);
	m_durationObservation_Attribute_event->setUpperBound(2);
	m_durationObservation_Attribute_event->setTransient(false);
	m_durationObservation_Attribute_event->setVolatile(false);
	m_durationObservation_Attribute_event->setChangeable(true);
	m_durationObservation_Attribute_event->setUnsettable(false);
	m_durationObservation_Attribute_event->setUnique(true);
	m_durationObservation_Attribute_event->setDerived(false);
	m_durationObservation_Attribute_event->setOrdered(true);
	m_durationObservation_Attribute_event->setContainment(false);
	m_durationObservation_Attribute_event->setResolveProxies(true);
	m_durationObservation_Attribute_event->setDefaultValueLiteral("");	
	
	m_durationObservation_Attribute_event->_setID(DURATIONOBSERVATION_ATTRIBUTE_EVENT);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeElementContent()
{
	m_element_Class->setName("Element");
	m_element_Class->setAbstract(true);
	m_element_Class->setInterface(false);
	
	m_element_Class->_setID(ELEMENT_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_element_Attribute_ownedComment->setName("ownedComment");
	m_element_Attribute_ownedComment->setEType(getComment_Class());
	m_element_Attribute_ownedComment->setLowerBound(0);
	m_element_Attribute_ownedComment->setUpperBound(-1);
	m_element_Attribute_ownedComment->setTransient(false);
	m_element_Attribute_ownedComment->setVolatile(false);
	m_element_Attribute_ownedComment->setChangeable(true);
	m_element_Attribute_ownedComment->setUnsettable(false);
	m_element_Attribute_ownedComment->setUnique(true);
	m_element_Attribute_ownedComment->setDerived(false);
	m_element_Attribute_ownedComment->setOrdered(false);
	m_element_Attribute_ownedComment->setContainment(true);
	m_element_Attribute_ownedComment->setResolveProxies(true);
	m_element_Attribute_ownedComment->setDefaultValueLiteral("");	
	
	m_element_Attribute_ownedComment->_setID(ELEMENT_ATTRIBUTE_OWNEDCOMMENT);
	m_element_Attribute_ownedElement->setName("ownedElement");
	m_element_Attribute_ownedElement->setEType(getElement_Class());
	m_element_Attribute_ownedElement->setLowerBound(0);
	m_element_Attribute_ownedElement->setUpperBound(-1);
	m_element_Attribute_ownedElement->setTransient(true);
	m_element_Attribute_ownedElement->setVolatile(true);
	m_element_Attribute_ownedElement->setChangeable(false);
	m_element_Attribute_ownedElement->setUnsettable(false);
	m_element_Attribute_ownedElement->setUnique(true);
	m_element_Attribute_ownedElement->setDerived(true);
	m_element_Attribute_ownedElement->setOrdered(false);
	m_element_Attribute_ownedElement->setContainment(true);
	m_element_Attribute_ownedElement->setResolveProxies(true);
	m_element_Attribute_ownedElement->setDefaultValueLiteral("");	
	m_element_Attribute_ownedElement->setEOpposite(uml::umlPackage::eInstance()->getElement_Attribute_owner());
	
	m_element_Attribute_ownedElement->_setID(ELEMENT_ATTRIBUTE_OWNEDELEMENT);
	m_element_Attribute_owner->setName("owner");
	m_element_Attribute_owner->setEType(getElement_Class());
	m_element_Attribute_owner->setLowerBound(0);
	m_element_Attribute_owner->setUpperBound(1);
	m_element_Attribute_owner->setTransient(true);
	m_element_Attribute_owner->setVolatile(true);
	m_element_Attribute_owner->setChangeable(false);
	m_element_Attribute_owner->setUnsettable(false);
	m_element_Attribute_owner->setUnique(true);
	m_element_Attribute_owner->setDerived(true);
	m_element_Attribute_owner->setOrdered(false);
	m_element_Attribute_owner->setContainment(false);
	m_element_Attribute_owner->setResolveProxies(true);
	m_element_Attribute_owner->setDefaultValueLiteral("");	
	m_element_Attribute_owner->setEOpposite(uml::umlPackage::eInstance()->getElement_Attribute_ownedElement());
	
	m_element_Attribute_owner->_setID(ELEMENT_ATTRIBUTE_OWNER);
	
	/*
	 * EOperations
	 */
	m_element_Operation_addKeyword_String->setName("addKeyword");
	m_element_Operation_addKeyword_String->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_element_Operation_addKeyword_String->setLowerBound(1);
	m_element_Operation_addKeyword_String->setUpperBound(1);
	m_element_Operation_addKeyword_String->setUnique(true);
	m_element_Operation_addKeyword_String->setOrdered(false);
	
	m_element_Operation_addKeyword_String->_setID(ELEMENT_OPERATION_ADDKEYWORD_STRING);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_element_Operation_addKeyword_String);
		parameter->setName("keyword");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_element_Operation_allOwnedElements->setName("allOwnedElements");
	m_element_Operation_allOwnedElements->setEType(getElement_Class());
	m_element_Operation_allOwnedElements->setLowerBound(0);
	m_element_Operation_allOwnedElements->setUpperBound(-1);
	m_element_Operation_allOwnedElements->setUnique(true);
	m_element_Operation_allOwnedElements->setOrdered(false);
	
	m_element_Operation_allOwnedElements->_setID(ELEMENT_OPERATION_ALLOWNEDELEMENTS);
	
	
	m_element_Operation_applyStereotype_Stereotype->setName("applyStereotype");
	m_element_Operation_applyStereotype_Stereotype->setEType(ecore::ecorePackage::eInstance()->getEObject_Class());
	m_element_Operation_applyStereotype_Stereotype->setLowerBound(1);
	m_element_Operation_applyStereotype_Stereotype->setUpperBound(1);
	m_element_Operation_applyStereotype_Stereotype->setUnique(true);
	m_element_Operation_applyStereotype_Stereotype->setOrdered(false);
	
	m_element_Operation_applyStereotype_Stereotype->_setID(ELEMENT_OPERATION_APPLYSTEREOTYPE_STEREOTYPE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_element_Operation_applyStereotype_Stereotype);
		parameter->setName("stereotype");
		parameter->setEType(getStereotype_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_element_Operation_container->setName("container");
	m_element_Operation_container->setEType(getElement_Class());
	m_element_Operation_container->setLowerBound(0);
	m_element_Operation_container->setUpperBound(1);
	m_element_Operation_container->setUnique(true);
	m_element_Operation_container->setOrdered(true);
	
	m_element_Operation_container->_setID(ELEMENT_OPERATION_CONTAINER);
	
	
	m_element_Operation_createEAnnotation_String->setName("createEAnnotation");
	m_element_Operation_createEAnnotation_String->setEType(ecore::ecorePackage::eInstance()->getEAnnotation_Class());
	m_element_Operation_createEAnnotation_String->setLowerBound(1);
	m_element_Operation_createEAnnotation_String->setUpperBound(1);
	m_element_Operation_createEAnnotation_String->setUnique(true);
	m_element_Operation_createEAnnotation_String->setOrdered(false);
	
	m_element_Operation_createEAnnotation_String->_setID(ELEMENT_OPERATION_CREATEEANNOTATION_STRING);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_element_Operation_createEAnnotation_String);
		parameter->setName("source");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_element_Operation_destroy->setName("destroy");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_element_Operation_destroy->setEType(unknownClass);
	}
	m_element_Operation_destroy->setLowerBound(1);
	m_element_Operation_destroy->setUpperBound(1);
	m_element_Operation_destroy->setUnique(true);
	m_element_Operation_destroy->setOrdered(false);
	
	m_element_Operation_destroy->_setID(ELEMENT_OPERATION_DESTROY);
	
	
	m_element_Operation_getApplicableStereotype_String->setName("getApplicableStereotype");
	m_element_Operation_getApplicableStereotype_String->setEType(getStereotype_Class());
	m_element_Operation_getApplicableStereotype_String->setLowerBound(0);
	m_element_Operation_getApplicableStereotype_String->setUpperBound(1);
	m_element_Operation_getApplicableStereotype_String->setUnique(true);
	m_element_Operation_getApplicableStereotype_String->setOrdered(false);
	
	m_element_Operation_getApplicableStereotype_String->_setID(ELEMENT_OPERATION_GETAPPLICABLESTEREOTYPE_STRING);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_element_Operation_getApplicableStereotype_String);
		parameter->setName("qualifiedName");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_element_Operation_getApplicableStereotypes->setName("getApplicableStereotypes");
	m_element_Operation_getApplicableStereotypes->setEType(getStereotype_Class());
	m_element_Operation_getApplicableStereotypes->setLowerBound(0);
	m_element_Operation_getApplicableStereotypes->setUpperBound(-1);
	m_element_Operation_getApplicableStereotypes->setUnique(true);
	m_element_Operation_getApplicableStereotypes->setOrdered(false);
	
	m_element_Operation_getApplicableStereotypes->_setID(ELEMENT_OPERATION_GETAPPLICABLESTEREOTYPES);
	
	
	m_element_Operation_getAppliedStereotype_String->setName("getAppliedStereotype");
	m_element_Operation_getAppliedStereotype_String->setEType(getStereotype_Class());
	m_element_Operation_getAppliedStereotype_String->setLowerBound(0);
	m_element_Operation_getAppliedStereotype_String->setUpperBound(1);
	m_element_Operation_getAppliedStereotype_String->setUnique(true);
	m_element_Operation_getAppliedStereotype_String->setOrdered(false);
	
	m_element_Operation_getAppliedStereotype_String->_setID(ELEMENT_OPERATION_GETAPPLIEDSTEREOTYPE_STRING);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_element_Operation_getAppliedStereotype_String);
		parameter->setName("qualifiedName");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_element_Operation_getAppliedStereotypes->setName("getAppliedStereotypes");
	m_element_Operation_getAppliedStereotypes->setEType(getStereotype_Class());
	m_element_Operation_getAppliedStereotypes->setLowerBound(0);
	m_element_Operation_getAppliedStereotypes->setUpperBound(-1);
	m_element_Operation_getAppliedStereotypes->setUnique(true);
	m_element_Operation_getAppliedStereotypes->setOrdered(false);
	
	m_element_Operation_getAppliedStereotypes->_setID(ELEMENT_OPERATION_GETAPPLIEDSTEREOTYPES);
	
	
	m_element_Operation_getAppliedSubstereotype_Stereotype_String->setName("getAppliedSubstereotype");
	m_element_Operation_getAppliedSubstereotype_Stereotype_String->setEType(getStereotype_Class());
	m_element_Operation_getAppliedSubstereotype_Stereotype_String->setLowerBound(0);
	m_element_Operation_getAppliedSubstereotype_Stereotype_String->setUpperBound(1);
	m_element_Operation_getAppliedSubstereotype_Stereotype_String->setUnique(true);
	m_element_Operation_getAppliedSubstereotype_Stereotype_String->setOrdered(false);
	
	m_element_Operation_getAppliedSubstereotype_Stereotype_String->_setID(ELEMENT_OPERATION_GETAPPLIEDSUBSTEREOTYPE_STEREOTYPE_STRING);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_element_Operation_getAppliedSubstereotype_Stereotype_String);
		parameter->setName("stereotype");
		parameter->setEType(getStereotype_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_element_Operation_getAppliedSubstereotype_Stereotype_String);
		parameter->setName("qualifiedName");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_element_Operation_getAppliedSubstereotypes_Stereotype->setName("getAppliedSubstereotypes");
	m_element_Operation_getAppliedSubstereotypes_Stereotype->setEType(getStereotype_Class());
	m_element_Operation_getAppliedSubstereotypes_Stereotype->setLowerBound(0);
	m_element_Operation_getAppliedSubstereotypes_Stereotype->setUpperBound(-1);
	m_element_Operation_getAppliedSubstereotypes_Stereotype->setUnique(true);
	m_element_Operation_getAppliedSubstereotypes_Stereotype->setOrdered(false);
	
	m_element_Operation_getAppliedSubstereotypes_Stereotype->_setID(ELEMENT_OPERATION_GETAPPLIEDSUBSTEREOTYPES_STEREOTYPE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_element_Operation_getAppliedSubstereotypes_Stereotype);
		parameter->setName("stereotype");
		parameter->setEType(getStereotype_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_element_Operation_getKeywords->setName("getKeywords");
	m_element_Operation_getKeywords->setEType(types::typesPackage::eInstance()->getString_Class());
	m_element_Operation_getKeywords->setLowerBound(0);
	m_element_Operation_getKeywords->setUpperBound(-1);
	m_element_Operation_getKeywords->setUnique(true);
	m_element_Operation_getKeywords->setOrdered(false);
	
	m_element_Operation_getKeywords->_setID(ELEMENT_OPERATION_GETKEYWORDS);
	
	
	m_element_Operation_getMetaClass->setName("getMetaClass");
	m_element_Operation_getMetaClass->setEType(getClass_Class());
	m_element_Operation_getMetaClass->setLowerBound(0);
	m_element_Operation_getMetaClass->setUpperBound(1);
	m_element_Operation_getMetaClass->setUnique(true);
	m_element_Operation_getMetaClass->setOrdered(true);
	
	m_element_Operation_getMetaClass->_setID(ELEMENT_OPERATION_GETMETACLASS);
	
	
	m_element_Operation_getModel->setName("getModel");
	m_element_Operation_getModel->setEType(getModel_Class());
	m_element_Operation_getModel->setLowerBound(0);
	m_element_Operation_getModel->setUpperBound(1);
	m_element_Operation_getModel->setUnique(true);
	m_element_Operation_getModel->setOrdered(false);
	
	m_element_Operation_getModel->_setID(ELEMENT_OPERATION_GETMODEL);
	
	
	m_element_Operation_getNearestPackage->setName("getNearestPackage");
	m_element_Operation_getNearestPackage->setEType(getPackage_Class());
	m_element_Operation_getNearestPackage->setLowerBound(0);
	m_element_Operation_getNearestPackage->setUpperBound(1);
	m_element_Operation_getNearestPackage->setUnique(true);
	m_element_Operation_getNearestPackage->setOrdered(false);
	
	m_element_Operation_getNearestPackage->_setID(ELEMENT_OPERATION_GETNEARESTPACKAGE);
	
	
	m_element_Operation_getRelationships->setName("getRelationships");
	m_element_Operation_getRelationships->setEType(getRelationship_Class());
	m_element_Operation_getRelationships->setLowerBound(0);
	m_element_Operation_getRelationships->setUpperBound(-1);
	m_element_Operation_getRelationships->setUnique(true);
	m_element_Operation_getRelationships->setOrdered(false);
	
	m_element_Operation_getRelationships->_setID(ELEMENT_OPERATION_GETRELATIONSHIPS);
	
	
	m_element_Operation_getRelationships_EClass->setName("getRelationships");
	m_element_Operation_getRelationships_EClass->setEType(getRelationship_Class());
	m_element_Operation_getRelationships_EClass->setLowerBound(0);
	m_element_Operation_getRelationships_EClass->setUpperBound(-1);
	m_element_Operation_getRelationships_EClass->setUnique(true);
	m_element_Operation_getRelationships_EClass->setOrdered(false);
	
	m_element_Operation_getRelationships_EClass->_setID(ELEMENT_OPERATION_GETRELATIONSHIPS_ECLASS);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_element_Operation_getRelationships_EClass);
		parameter->setName("eClass");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEClass_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_element_Operation_getRequiredStereotype_String->setName("getRequiredStereotype");
	m_element_Operation_getRequiredStereotype_String->setEType(getStereotype_Class());
	m_element_Operation_getRequiredStereotype_String->setLowerBound(0);
	m_element_Operation_getRequiredStereotype_String->setUpperBound(1);
	m_element_Operation_getRequiredStereotype_String->setUnique(true);
	m_element_Operation_getRequiredStereotype_String->setOrdered(false);
	
	m_element_Operation_getRequiredStereotype_String->_setID(ELEMENT_OPERATION_GETREQUIREDSTEREOTYPE_STRING);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_element_Operation_getRequiredStereotype_String);
		parameter->setName("qualifiedName");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_element_Operation_getRequiredStereotypes->setName("getRequiredStereotypes");
	m_element_Operation_getRequiredStereotypes->setEType(getStereotype_Class());
	m_element_Operation_getRequiredStereotypes->setLowerBound(0);
	m_element_Operation_getRequiredStereotypes->setUpperBound(-1);
	m_element_Operation_getRequiredStereotypes->setUnique(true);
	m_element_Operation_getRequiredStereotypes->setOrdered(false);
	
	m_element_Operation_getRequiredStereotypes->_setID(ELEMENT_OPERATION_GETREQUIREDSTEREOTYPES);
	
	
	m_element_Operation_getSourceDirectedRelationships->setName("getSourceDirectedRelationships");
	m_element_Operation_getSourceDirectedRelationships->setEType(getDirectedRelationship_Class());
	m_element_Operation_getSourceDirectedRelationships->setLowerBound(0);
	m_element_Operation_getSourceDirectedRelationships->setUpperBound(-1);
	m_element_Operation_getSourceDirectedRelationships->setUnique(true);
	m_element_Operation_getSourceDirectedRelationships->setOrdered(false);
	
	m_element_Operation_getSourceDirectedRelationships->_setID(ELEMENT_OPERATION_GETSOURCEDIRECTEDRELATIONSHIPS);
	
	
	m_element_Operation_getSourceDirectedRelationships_EClass->setName("getSourceDirectedRelationships");
	m_element_Operation_getSourceDirectedRelationships_EClass->setEType(getDirectedRelationship_Class());
	m_element_Operation_getSourceDirectedRelationships_EClass->setLowerBound(0);
	m_element_Operation_getSourceDirectedRelationships_EClass->setUpperBound(-1);
	m_element_Operation_getSourceDirectedRelationships_EClass->setUnique(true);
	m_element_Operation_getSourceDirectedRelationships_EClass->setOrdered(false);
	
	m_element_Operation_getSourceDirectedRelationships_EClass->_setID(ELEMENT_OPERATION_GETSOURCEDIRECTEDRELATIONSHIPS_ECLASS);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_element_Operation_getSourceDirectedRelationships_EClass);
		parameter->setName("eClass");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEClass_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_element_Operation_getStereotypeApplication_Stereotype->setName("getStereotypeApplication");
	m_element_Operation_getStereotypeApplication_Stereotype->setEType(ecore::ecorePackage::eInstance()->getEObject_Class());
	m_element_Operation_getStereotypeApplication_Stereotype->setLowerBound(0);
	m_element_Operation_getStereotypeApplication_Stereotype->setUpperBound(1);
	m_element_Operation_getStereotypeApplication_Stereotype->setUnique(true);
	m_element_Operation_getStereotypeApplication_Stereotype->setOrdered(false);
	
	m_element_Operation_getStereotypeApplication_Stereotype->_setID(ELEMENT_OPERATION_GETSTEREOTYPEAPPLICATION_STEREOTYPE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_element_Operation_getStereotypeApplication_Stereotype);
		parameter->setName("stereotype");
		parameter->setEType(getStereotype_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_element_Operation_getStereotypeApplications->setName("getStereotypeApplications");
	m_element_Operation_getStereotypeApplications->setEType(ecore::ecorePackage::eInstance()->getEObject_Class());
	m_element_Operation_getStereotypeApplications->setLowerBound(0);
	m_element_Operation_getStereotypeApplications->setUpperBound(-1);
	m_element_Operation_getStereotypeApplications->setUnique(true);
	m_element_Operation_getStereotypeApplications->setOrdered(false);
	
	m_element_Operation_getStereotypeApplications->_setID(ELEMENT_OPERATION_GETSTEREOTYPEAPPLICATIONS);
	
	
	m_element_Operation_getTargetDirectedRelationships->setName("getTargetDirectedRelationships");
	m_element_Operation_getTargetDirectedRelationships->setEType(getDirectedRelationship_Class());
	m_element_Operation_getTargetDirectedRelationships->setLowerBound(0);
	m_element_Operation_getTargetDirectedRelationships->setUpperBound(-1);
	m_element_Operation_getTargetDirectedRelationships->setUnique(true);
	m_element_Operation_getTargetDirectedRelationships->setOrdered(false);
	
	m_element_Operation_getTargetDirectedRelationships->_setID(ELEMENT_OPERATION_GETTARGETDIRECTEDRELATIONSHIPS);
	
	
	m_element_Operation_getTargetDirectedRelationships_EClass->setName("getTargetDirectedRelationships");
	m_element_Operation_getTargetDirectedRelationships_EClass->setEType(getDirectedRelationship_Class());
	m_element_Operation_getTargetDirectedRelationships_EClass->setLowerBound(0);
	m_element_Operation_getTargetDirectedRelationships_EClass->setUpperBound(-1);
	m_element_Operation_getTargetDirectedRelationships_EClass->setUnique(true);
	m_element_Operation_getTargetDirectedRelationships_EClass->setOrdered(false);
	
	m_element_Operation_getTargetDirectedRelationships_EClass->_setID(ELEMENT_OPERATION_GETTARGETDIRECTEDRELATIONSHIPS_ECLASS);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_element_Operation_getTargetDirectedRelationships_EClass);
		parameter->setName("eClass");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEClass_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_element_Operation_getValue_Stereotype_String->setName("getValue");
	m_element_Operation_getValue_Stereotype_String->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_element_Operation_getValue_Stereotype_String->setLowerBound(0);
	m_element_Operation_getValue_Stereotype_String->setUpperBound(1);
	m_element_Operation_getValue_Stereotype_String->setUnique(true);
	m_element_Operation_getValue_Stereotype_String->setOrdered(false);
	
	m_element_Operation_getValue_Stereotype_String->_setID(ELEMENT_OPERATION_GETVALUE_STEREOTYPE_STRING);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_element_Operation_getValue_Stereotype_String);
		parameter->setName("stereotype");
		parameter->setEType(getStereotype_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_element_Operation_getValue_Stereotype_String);
		parameter->setName("propertyName");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_element_Operation_hasKeyword_String->setName("hasKeyword");
	m_element_Operation_hasKeyword_String->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_element_Operation_hasKeyword_String->setLowerBound(1);
	m_element_Operation_hasKeyword_String->setUpperBound(1);
	m_element_Operation_hasKeyword_String->setUnique(true);
	m_element_Operation_hasKeyword_String->setOrdered(false);
	
	m_element_Operation_hasKeyword_String->_setID(ELEMENT_OPERATION_HASKEYWORD_STRING);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_element_Operation_hasKeyword_String);
		parameter->setName("keyword");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_element_Operation_hasValue_Stereotype_String->setName("hasValue");
	m_element_Operation_hasValue_Stereotype_String->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_element_Operation_hasValue_Stereotype_String->setLowerBound(1);
	m_element_Operation_hasValue_Stereotype_String->setUpperBound(1);
	m_element_Operation_hasValue_Stereotype_String->setUnique(true);
	m_element_Operation_hasValue_Stereotype_String->setOrdered(false);
	
	m_element_Operation_hasValue_Stereotype_String->_setID(ELEMENT_OPERATION_HASVALUE_STEREOTYPE_STRING);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_element_Operation_hasValue_Stereotype_String);
		parameter->setName("stereotype");
		parameter->setEType(getStereotype_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_element_Operation_hasValue_Stereotype_String);
		parameter->setName("propertyName");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_element_Operation_isStereotypeApplicable_Stereotype->setName("isStereotypeApplicable");
	m_element_Operation_isStereotypeApplicable_Stereotype->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_element_Operation_isStereotypeApplicable_Stereotype->setLowerBound(1);
	m_element_Operation_isStereotypeApplicable_Stereotype->setUpperBound(1);
	m_element_Operation_isStereotypeApplicable_Stereotype->setUnique(true);
	m_element_Operation_isStereotypeApplicable_Stereotype->setOrdered(false);
	
	m_element_Operation_isStereotypeApplicable_Stereotype->_setID(ELEMENT_OPERATION_ISSTEREOTYPEAPPLICABLE_STEREOTYPE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_element_Operation_isStereotypeApplicable_Stereotype);
		parameter->setName("stereotype");
		parameter->setEType(getStereotype_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_element_Operation_isStereotypeApplied_Stereotype->setName("isStereotypeApplied");
	m_element_Operation_isStereotypeApplied_Stereotype->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_element_Operation_isStereotypeApplied_Stereotype->setLowerBound(1);
	m_element_Operation_isStereotypeApplied_Stereotype->setUpperBound(1);
	m_element_Operation_isStereotypeApplied_Stereotype->setUnique(true);
	m_element_Operation_isStereotypeApplied_Stereotype->setOrdered(false);
	
	m_element_Operation_isStereotypeApplied_Stereotype->_setID(ELEMENT_OPERATION_ISSTEREOTYPEAPPLIED_STEREOTYPE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_element_Operation_isStereotypeApplied_Stereotype);
		parameter->setName("stereotype");
		parameter->setEType(getStereotype_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_element_Operation_isStereotypeRequired_Stereotype->setName("isStereotypeRequired");
	m_element_Operation_isStereotypeRequired_Stereotype->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_element_Operation_isStereotypeRequired_Stereotype->setLowerBound(1);
	m_element_Operation_isStereotypeRequired_Stereotype->setUpperBound(1);
	m_element_Operation_isStereotypeRequired_Stereotype->setUnique(true);
	m_element_Operation_isStereotypeRequired_Stereotype->setOrdered(false);
	
	m_element_Operation_isStereotypeRequired_Stereotype->_setID(ELEMENT_OPERATION_ISSTEREOTYPEREQUIRED_STEREOTYPE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_element_Operation_isStereotypeRequired_Stereotype);
		parameter->setName("stereotype");
		parameter->setEType(getStereotype_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_element_Operation_mustBeOwned->setName("mustBeOwned");
	m_element_Operation_mustBeOwned->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_element_Operation_mustBeOwned->setLowerBound(1);
	m_element_Operation_mustBeOwned->setUpperBound(1);
	m_element_Operation_mustBeOwned->setUnique(true);
	m_element_Operation_mustBeOwned->setOrdered(false);
	
	m_element_Operation_mustBeOwned->_setID(ELEMENT_OPERATION_MUSTBEOWNED);
	
	
	m_element_Operation_removeKeyword_String->setName("removeKeyword");
	m_element_Operation_removeKeyword_String->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_element_Operation_removeKeyword_String->setLowerBound(1);
	m_element_Operation_removeKeyword_String->setUpperBound(1);
	m_element_Operation_removeKeyword_String->setUnique(true);
	m_element_Operation_removeKeyword_String->setOrdered(false);
	
	m_element_Operation_removeKeyword_String->_setID(ELEMENT_OPERATION_REMOVEKEYWORD_STRING);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_element_Operation_removeKeyword_String);
		parameter->setName("keyword");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_element_Operation_setValue_Stereotype_EJavaObject->setName("setValue");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_element_Operation_setValue_Stereotype_EJavaObject->setEType(unknownClass);
	}
	m_element_Operation_setValue_Stereotype_EJavaObject->setLowerBound(1);
	m_element_Operation_setValue_Stereotype_EJavaObject->setUpperBound(1);
	m_element_Operation_setValue_Stereotype_EJavaObject->setUnique(true);
	m_element_Operation_setValue_Stereotype_EJavaObject->setOrdered(false);
	
	m_element_Operation_setValue_Stereotype_EJavaObject->_setID(ELEMENT_OPERATION_SETVALUE_STEREOTYPE_EJAVAOBJECT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_element_Operation_setValue_Stereotype_EJavaObject);
		parameter->setName("stereotype");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_element_Operation_setValue_Stereotype_EJavaObject);
		parameter->setName("propertyName");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_element_Operation_setValue_Stereotype_EJavaObject);
		parameter->setName("newValue");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_element_Operation_unapplyStereotype_Stereotype->setName("unapplyStereotype");
	m_element_Operation_unapplyStereotype_Stereotype->setEType(ecore::ecorePackage::eInstance()->getEObject_Class());
	m_element_Operation_unapplyStereotype_Stereotype->setLowerBound(1);
	m_element_Operation_unapplyStereotype_Stereotype->setUpperBound(1);
	m_element_Operation_unapplyStereotype_Stereotype->setUnique(true);
	m_element_Operation_unapplyStereotype_Stereotype->setOrdered(false);
	
	m_element_Operation_unapplyStereotype_Stereotype->_setID(ELEMENT_OPERATION_UNAPPLYSTEREOTYPE_STEREOTYPE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_element_Operation_unapplyStereotype_Stereotype);
		parameter->setName("stereotype");
		parameter->setEType(getStereotype_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void umlPackageImpl::initializeElementImportContent()
{
	m_elementImport_Class->setName("ElementImport");
	m_elementImport_Class->setAbstract(false);
	m_elementImport_Class->setInterface(false);
	
	m_elementImport_Class->_setID(ELEMENTIMPORT_CLASS);
	
	/*
	 * EAttributes
	 */
	m_elementImport_Attribute_alias = getElementImport_Attribute_alias();
	m_elementImport_Attribute_alias->setName("alias");
	m_elementImport_Attribute_alias->setEType(types::typesPackage::eInstance()->getString_Class());
	m_elementImport_Attribute_alias->setLowerBound(0);
	m_elementImport_Attribute_alias->setUpperBound(1);
	m_elementImport_Attribute_alias->setTransient(false);
	m_elementImport_Attribute_alias->setVolatile(false);
	m_elementImport_Attribute_alias->setChangeable(true);
	m_elementImport_Attribute_alias->setUnsettable(true);
	m_elementImport_Attribute_alias->setUnique(true);
	m_elementImport_Attribute_alias->setDerived(false);
	m_elementImport_Attribute_alias->setOrdered(false);
	m_elementImport_Attribute_alias->setID(false);
	m_elementImport_Attribute_alias->setDefaultValueLiteral("");
	
	m_elementImport_Attribute_alias->_setID(ELEMENTIMPORT_ATTRIBUTE_ALIAS);
	m_elementImport_Attribute_visibility = getElementImport_Attribute_visibility();
	m_elementImport_Attribute_visibility->setName("visibility");
	m_elementImport_Attribute_visibility->setEType(getVisibilityKind_Class());
	m_elementImport_Attribute_visibility->setLowerBound(1);
	m_elementImport_Attribute_visibility->setUpperBound(1);
	m_elementImport_Attribute_visibility->setTransient(false);
	m_elementImport_Attribute_visibility->setVolatile(false);
	m_elementImport_Attribute_visibility->setChangeable(true);
	m_elementImport_Attribute_visibility->setUnsettable(false);
	m_elementImport_Attribute_visibility->setUnique(true);
	m_elementImport_Attribute_visibility->setDerived(false);
	m_elementImport_Attribute_visibility->setOrdered(false);
	m_elementImport_Attribute_visibility->setID(false);
	m_elementImport_Attribute_visibility->setDefaultValueLiteral("public");
	
	m_elementImport_Attribute_visibility->_setID(ELEMENTIMPORT_ATTRIBUTE_VISIBILITY);
	
	/*
	 * EReferences
	 */
	m_elementImport_Attribute_importedElement->setName("importedElement");
	m_elementImport_Attribute_importedElement->setEType(getPackageableElement_Class());
	m_elementImport_Attribute_importedElement->setLowerBound(1);
	m_elementImport_Attribute_importedElement->setUpperBound(1);
	m_elementImport_Attribute_importedElement->setTransient(false);
	m_elementImport_Attribute_importedElement->setVolatile(false);
	m_elementImport_Attribute_importedElement->setChangeable(true);
	m_elementImport_Attribute_importedElement->setUnsettable(false);
	m_elementImport_Attribute_importedElement->setUnique(true);
	m_elementImport_Attribute_importedElement->setDerived(false);
	m_elementImport_Attribute_importedElement->setOrdered(false);
	m_elementImport_Attribute_importedElement->setContainment(false);
	m_elementImport_Attribute_importedElement->setResolveProxies(true);
	m_elementImport_Attribute_importedElement->setDefaultValueLiteral("");	
	
	m_elementImport_Attribute_importedElement->_setID(ELEMENTIMPORT_ATTRIBUTE_IMPORTEDELEMENT);
	m_elementImport_Attribute_importingNamespace->setName("importingNamespace");
	m_elementImport_Attribute_importingNamespace->setEType(getNamespace_Class());
	m_elementImport_Attribute_importingNamespace->setLowerBound(1);
	m_elementImport_Attribute_importingNamespace->setUpperBound(1);
	m_elementImport_Attribute_importingNamespace->setTransient(false);
	m_elementImport_Attribute_importingNamespace->setVolatile(false);
	m_elementImport_Attribute_importingNamespace->setChangeable(true);
	m_elementImport_Attribute_importingNamespace->setUnsettable(false);
	m_elementImport_Attribute_importingNamespace->setUnique(true);
	m_elementImport_Attribute_importingNamespace->setDerived(false);
	m_elementImport_Attribute_importingNamespace->setOrdered(false);
	m_elementImport_Attribute_importingNamespace->setContainment(false);
	m_elementImport_Attribute_importingNamespace->setResolveProxies(true);
	m_elementImport_Attribute_importingNamespace->setDefaultValueLiteral("");	
	m_elementImport_Attribute_importingNamespace->setEOpposite(uml::umlPackage::eInstance()->getNamespace_Attribute_elementImport());
	
	m_elementImport_Attribute_importingNamespace->_setID(ELEMENTIMPORT_ATTRIBUTE_IMPORTINGNAMESPACE);
	
	/*
	 * EOperations
	 */
	m_elementImport_Operation_getName->setName("getName");
	m_elementImport_Operation_getName->setEType(types::typesPackage::eInstance()->getString_Class());
	m_elementImport_Operation_getName->setLowerBound(1);
	m_elementImport_Operation_getName->setUpperBound(1);
	m_elementImport_Operation_getName->setUnique(true);
	m_elementImport_Operation_getName->setOrdered(false);
	
	m_elementImport_Operation_getName->_setID(ELEMENTIMPORT_OPERATION_GETNAME);
	
	
	
}

void umlPackageImpl::initializeEncapsulatedClassifierContent()
{
	m_encapsulatedClassifier_Class->setName("EncapsulatedClassifier");
	m_encapsulatedClassifier_Class->setAbstract(true);
	m_encapsulatedClassifier_Class->setInterface(false);
	
	m_encapsulatedClassifier_Class->_setID(ENCAPSULATEDCLASSIFIER_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_encapsulatedClassifier_Attribute_ownedPort->setName("ownedPort");
	m_encapsulatedClassifier_Attribute_ownedPort->setEType(getPort_Class());
	m_encapsulatedClassifier_Attribute_ownedPort->setLowerBound(0);
	m_encapsulatedClassifier_Attribute_ownedPort->setUpperBound(-1);
	m_encapsulatedClassifier_Attribute_ownedPort->setTransient(true);
	m_encapsulatedClassifier_Attribute_ownedPort->setVolatile(true);
	m_encapsulatedClassifier_Attribute_ownedPort->setChangeable(false);
	m_encapsulatedClassifier_Attribute_ownedPort->setUnsettable(false);
	m_encapsulatedClassifier_Attribute_ownedPort->setUnique(true);
	m_encapsulatedClassifier_Attribute_ownedPort->setDerived(true);
	m_encapsulatedClassifier_Attribute_ownedPort->setOrdered(false);
	m_encapsulatedClassifier_Attribute_ownedPort->setContainment(true);
	m_encapsulatedClassifier_Attribute_ownedPort->setResolveProxies(true);
	m_encapsulatedClassifier_Attribute_ownedPort->setDefaultValueLiteral("");	
	
	m_encapsulatedClassifier_Attribute_ownedPort->_setID(ENCAPSULATEDCLASSIFIER_ATTRIBUTE_OWNEDPORT);
	
	/*
	 * EOperations
	 */
	m_encapsulatedClassifier_Operation_getOwnedPorts->setName("getOwnedPorts");
	m_encapsulatedClassifier_Operation_getOwnedPorts->setEType(getPort_Class());
	m_encapsulatedClassifier_Operation_getOwnedPorts->setLowerBound(0);
	m_encapsulatedClassifier_Operation_getOwnedPorts->setUpperBound(-1);
	m_encapsulatedClassifier_Operation_getOwnedPorts->setUnique(true);
	m_encapsulatedClassifier_Operation_getOwnedPorts->setOrdered(true);
	
	m_encapsulatedClassifier_Operation_getOwnedPorts->_setID(ENCAPSULATEDCLASSIFIER_OPERATION_GETOWNEDPORTS);
	
	
	
}

void umlPackageImpl::initializeEnumerationContent()
{
	m_enumeration_Class->setName("Enumeration");
	m_enumeration_Class->setAbstract(false);
	m_enumeration_Class->setInterface(false);
	
	m_enumeration_Class->_setID(ENUMERATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_enumeration_Attribute_ownedLiteral->setName("ownedLiteral");
	m_enumeration_Attribute_ownedLiteral->setEType(getEnumerationLiteral_Class());
	m_enumeration_Attribute_ownedLiteral->setLowerBound(0);
	m_enumeration_Attribute_ownedLiteral->setUpperBound(-1);
	m_enumeration_Attribute_ownedLiteral->setTransient(false);
	m_enumeration_Attribute_ownedLiteral->setVolatile(false);
	m_enumeration_Attribute_ownedLiteral->setChangeable(true);
	m_enumeration_Attribute_ownedLiteral->setUnsettable(false);
	m_enumeration_Attribute_ownedLiteral->setUnique(true);
	m_enumeration_Attribute_ownedLiteral->setDerived(false);
	m_enumeration_Attribute_ownedLiteral->setOrdered(true);
	m_enumeration_Attribute_ownedLiteral->setContainment(true);
	m_enumeration_Attribute_ownedLiteral->setResolveProxies(true);
	m_enumeration_Attribute_ownedLiteral->setDefaultValueLiteral("");	
	m_enumeration_Attribute_ownedLiteral->setEOpposite(uml::umlPackage::eInstance()->getEnumerationLiteral_Attribute_enumeration());
	
	m_enumeration_Attribute_ownedLiteral->_setID(ENUMERATION_ATTRIBUTE_OWNEDLITERAL);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeEnumerationLiteralContent()
{
	m_enumerationLiteral_Class->setName("EnumerationLiteral");
	m_enumerationLiteral_Class->setAbstract(false);
	m_enumerationLiteral_Class->setInterface(false);
	
	m_enumerationLiteral_Class->_setID(ENUMERATIONLITERAL_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_enumerationLiteral_Attribute_enumeration->setName("enumeration");
	m_enumerationLiteral_Attribute_enumeration->setEType(getEnumeration_Class());
	m_enumerationLiteral_Attribute_enumeration->setLowerBound(1);
	m_enumerationLiteral_Attribute_enumeration->setUpperBound(1);
	m_enumerationLiteral_Attribute_enumeration->setTransient(false);
	m_enumerationLiteral_Attribute_enumeration->setVolatile(false);
	m_enumerationLiteral_Attribute_enumeration->setChangeable(true);
	m_enumerationLiteral_Attribute_enumeration->setUnsettable(false);
	m_enumerationLiteral_Attribute_enumeration->setUnique(true);
	m_enumerationLiteral_Attribute_enumeration->setDerived(false);
	m_enumerationLiteral_Attribute_enumeration->setOrdered(false);
	m_enumerationLiteral_Attribute_enumeration->setContainment(false);
	m_enumerationLiteral_Attribute_enumeration->setResolveProxies(true);
	m_enumerationLiteral_Attribute_enumeration->setDefaultValueLiteral("");	
	m_enumerationLiteral_Attribute_enumeration->setEOpposite(uml::umlPackage::eInstance()->getEnumeration_Attribute_ownedLiteral());
	
	m_enumerationLiteral_Attribute_enumeration->_setID(ENUMERATIONLITERAL_ATTRIBUTE_ENUMERATION);
	
	/*
	 * EOperations
	 */
	m_enumerationLiteral_Operation_getClassifier->setName("getClassifier");
	m_enumerationLiteral_Operation_getClassifier->setEType(getEnumeration_Class());
	m_enumerationLiteral_Operation_getClassifier->setLowerBound(1);
	m_enumerationLiteral_Operation_getClassifier->setUpperBound(1);
	m_enumerationLiteral_Operation_getClassifier->setUnique(true);
	m_enumerationLiteral_Operation_getClassifier->setOrdered(false);
	
	m_enumerationLiteral_Operation_getClassifier->_setID(ENUMERATIONLITERAL_OPERATION_GETCLASSIFIER);
	
	
	m_enumerationLiteral_Operation_getClassifiers->setName("getClassifiers");
	m_enumerationLiteral_Operation_getClassifiers->setEType(getClassifier_Class());
	m_enumerationLiteral_Operation_getClassifiers->setLowerBound(0);
	m_enumerationLiteral_Operation_getClassifiers->setUpperBound(-1);
	m_enumerationLiteral_Operation_getClassifiers->setUnique(true);
	m_enumerationLiteral_Operation_getClassifiers->setOrdered(false);
	
	m_enumerationLiteral_Operation_getClassifiers->_setID(ENUMERATIONLITERAL_OPERATION_GETCLASSIFIERS);
	
	
	
}

void umlPackageImpl::initializeEventContent()
{
	m_event_Class->setName("Event");
	m_event_Class->setAbstract(true);
	m_event_Class->setInterface(false);
	
	m_event_Class->_setID(EVENT_CLASS);
	
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

void umlPackageImpl::initializeExceptionHandlerContent()
{
	m_exceptionHandler_Class->setName("ExceptionHandler");
	m_exceptionHandler_Class->setAbstract(false);
	m_exceptionHandler_Class->setInterface(false);
	
	m_exceptionHandler_Class->_setID(EXCEPTIONHANDLER_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_exceptionHandler_Attribute_exceptionInput->setName("exceptionInput");
	m_exceptionHandler_Attribute_exceptionInput->setEType(getObjectNode_Class());
	m_exceptionHandler_Attribute_exceptionInput->setLowerBound(1);
	m_exceptionHandler_Attribute_exceptionInput->setUpperBound(1);
	m_exceptionHandler_Attribute_exceptionInput->setTransient(false);
	m_exceptionHandler_Attribute_exceptionInput->setVolatile(false);
	m_exceptionHandler_Attribute_exceptionInput->setChangeable(true);
	m_exceptionHandler_Attribute_exceptionInput->setUnsettable(false);
	m_exceptionHandler_Attribute_exceptionInput->setUnique(true);
	m_exceptionHandler_Attribute_exceptionInput->setDerived(false);
	m_exceptionHandler_Attribute_exceptionInput->setOrdered(false);
	m_exceptionHandler_Attribute_exceptionInput->setContainment(false);
	m_exceptionHandler_Attribute_exceptionInput->setResolveProxies(true);
	m_exceptionHandler_Attribute_exceptionInput->setDefaultValueLiteral("");	
	
	m_exceptionHandler_Attribute_exceptionInput->_setID(EXCEPTIONHANDLER_ATTRIBUTE_EXCEPTIONINPUT);
	m_exceptionHandler_Attribute_exceptionType->setName("exceptionType");
	m_exceptionHandler_Attribute_exceptionType->setEType(getClassifier_Class());
	m_exceptionHandler_Attribute_exceptionType->setLowerBound(1);
	m_exceptionHandler_Attribute_exceptionType->setUpperBound(-1);
	m_exceptionHandler_Attribute_exceptionType->setTransient(false);
	m_exceptionHandler_Attribute_exceptionType->setVolatile(false);
	m_exceptionHandler_Attribute_exceptionType->setChangeable(true);
	m_exceptionHandler_Attribute_exceptionType->setUnsettable(false);
	m_exceptionHandler_Attribute_exceptionType->setUnique(true);
	m_exceptionHandler_Attribute_exceptionType->setDerived(false);
	m_exceptionHandler_Attribute_exceptionType->setOrdered(false);
	m_exceptionHandler_Attribute_exceptionType->setContainment(false);
	m_exceptionHandler_Attribute_exceptionType->setResolveProxies(true);
	m_exceptionHandler_Attribute_exceptionType->setDefaultValueLiteral("");	
	
	m_exceptionHandler_Attribute_exceptionType->_setID(EXCEPTIONHANDLER_ATTRIBUTE_EXCEPTIONTYPE);
	m_exceptionHandler_Attribute_handlerBody->setName("handlerBody");
	m_exceptionHandler_Attribute_handlerBody->setEType(getExecutableNode_Class());
	m_exceptionHandler_Attribute_handlerBody->setLowerBound(1);
	m_exceptionHandler_Attribute_handlerBody->setUpperBound(1);
	m_exceptionHandler_Attribute_handlerBody->setTransient(false);
	m_exceptionHandler_Attribute_handlerBody->setVolatile(false);
	m_exceptionHandler_Attribute_handlerBody->setChangeable(true);
	m_exceptionHandler_Attribute_handlerBody->setUnsettable(false);
	m_exceptionHandler_Attribute_handlerBody->setUnique(true);
	m_exceptionHandler_Attribute_handlerBody->setDerived(false);
	m_exceptionHandler_Attribute_handlerBody->setOrdered(false);
	m_exceptionHandler_Attribute_handlerBody->setContainment(false);
	m_exceptionHandler_Attribute_handlerBody->setResolveProxies(true);
	m_exceptionHandler_Attribute_handlerBody->setDefaultValueLiteral("");	
	
	m_exceptionHandler_Attribute_handlerBody->_setID(EXCEPTIONHANDLER_ATTRIBUTE_HANDLERBODY);
	m_exceptionHandler_Attribute_protectedNode->setName("protectedNode");
	m_exceptionHandler_Attribute_protectedNode->setEType(getExecutableNode_Class());
	m_exceptionHandler_Attribute_protectedNode->setLowerBound(1);
	m_exceptionHandler_Attribute_protectedNode->setUpperBound(1);
	m_exceptionHandler_Attribute_protectedNode->setTransient(false);
	m_exceptionHandler_Attribute_protectedNode->setVolatile(false);
	m_exceptionHandler_Attribute_protectedNode->setChangeable(true);
	m_exceptionHandler_Attribute_protectedNode->setUnsettable(false);
	m_exceptionHandler_Attribute_protectedNode->setUnique(true);
	m_exceptionHandler_Attribute_protectedNode->setDerived(false);
	m_exceptionHandler_Attribute_protectedNode->setOrdered(false);
	m_exceptionHandler_Attribute_protectedNode->setContainment(false);
	m_exceptionHandler_Attribute_protectedNode->setResolveProxies(true);
	m_exceptionHandler_Attribute_protectedNode->setDefaultValueLiteral("");	
	m_exceptionHandler_Attribute_protectedNode->setEOpposite(uml::umlPackage::eInstance()->getExecutableNode_Attribute_handler());
	
	m_exceptionHandler_Attribute_protectedNode->_setID(EXCEPTIONHANDLER_ATTRIBUTE_PROTECTEDNODE);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeExecutableNodeContent()
{
	m_executableNode_Class->setName("ExecutableNode");
	m_executableNode_Class->setAbstract(true);
	m_executableNode_Class->setInterface(false);
	
	m_executableNode_Class->_setID(EXECUTABLENODE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_executableNode_Attribute_handler->setName("handler");
	m_executableNode_Attribute_handler->setEType(getExceptionHandler_Class());
	m_executableNode_Attribute_handler->setLowerBound(0);
	m_executableNode_Attribute_handler->setUpperBound(-1);
	m_executableNode_Attribute_handler->setTransient(false);
	m_executableNode_Attribute_handler->setVolatile(false);
	m_executableNode_Attribute_handler->setChangeable(true);
	m_executableNode_Attribute_handler->setUnsettable(false);
	m_executableNode_Attribute_handler->setUnique(true);
	m_executableNode_Attribute_handler->setDerived(false);
	m_executableNode_Attribute_handler->setOrdered(false);
	m_executableNode_Attribute_handler->setContainment(true);
	m_executableNode_Attribute_handler->setResolveProxies(true);
	m_executableNode_Attribute_handler->setDefaultValueLiteral("");	
	m_executableNode_Attribute_handler->setEOpposite(uml::umlPackage::eInstance()->getExceptionHandler_Attribute_protectedNode());
	
	m_executableNode_Attribute_handler->_setID(EXECUTABLENODE_ATTRIBUTE_HANDLER);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeExecutionEnvironmentContent()
{
	m_executionEnvironment_Class->setName("ExecutionEnvironment");
	m_executionEnvironment_Class->setAbstract(false);
	m_executionEnvironment_Class->setInterface(false);
	
	m_executionEnvironment_Class->_setID(EXECUTIONENVIRONMENT_CLASS);
	
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

void umlPackageImpl::initializeExecutionOccurrenceSpecificationContent()
{
	m_executionOccurrenceSpecification_Class->setName("ExecutionOccurrenceSpecification");
	m_executionOccurrenceSpecification_Class->setAbstract(false);
	m_executionOccurrenceSpecification_Class->setInterface(false);
	
	m_executionOccurrenceSpecification_Class->_setID(EXECUTIONOCCURRENCESPECIFICATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_executionOccurrenceSpecification_Attribute_execution->setName("execution");
	m_executionOccurrenceSpecification_Attribute_execution->setEType(getExecutionSpecification_Class());
	m_executionOccurrenceSpecification_Attribute_execution->setLowerBound(1);
	m_executionOccurrenceSpecification_Attribute_execution->setUpperBound(1);
	m_executionOccurrenceSpecification_Attribute_execution->setTransient(false);
	m_executionOccurrenceSpecification_Attribute_execution->setVolatile(false);
	m_executionOccurrenceSpecification_Attribute_execution->setChangeable(true);
	m_executionOccurrenceSpecification_Attribute_execution->setUnsettable(false);
	m_executionOccurrenceSpecification_Attribute_execution->setUnique(true);
	m_executionOccurrenceSpecification_Attribute_execution->setDerived(false);
	m_executionOccurrenceSpecification_Attribute_execution->setOrdered(false);
	m_executionOccurrenceSpecification_Attribute_execution->setContainment(false);
	m_executionOccurrenceSpecification_Attribute_execution->setResolveProxies(true);
	m_executionOccurrenceSpecification_Attribute_execution->setDefaultValueLiteral("");	
	
	m_executionOccurrenceSpecification_Attribute_execution->_setID(EXECUTIONOCCURRENCESPECIFICATION_ATTRIBUTE_EXECUTION);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeExecutionSpecificationContent()
{
	m_executionSpecification_Class->setName("ExecutionSpecification");
	m_executionSpecification_Class->setAbstract(true);
	m_executionSpecification_Class->setInterface(false);
	
	m_executionSpecification_Class->_setID(EXECUTIONSPECIFICATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_executionSpecification_Attribute_finish->setName("finish");
	m_executionSpecification_Attribute_finish->setEType(getOccurrenceSpecification_Class());
	m_executionSpecification_Attribute_finish->setLowerBound(1);
	m_executionSpecification_Attribute_finish->setUpperBound(1);
	m_executionSpecification_Attribute_finish->setTransient(false);
	m_executionSpecification_Attribute_finish->setVolatile(false);
	m_executionSpecification_Attribute_finish->setChangeable(true);
	m_executionSpecification_Attribute_finish->setUnsettable(false);
	m_executionSpecification_Attribute_finish->setUnique(true);
	m_executionSpecification_Attribute_finish->setDerived(false);
	m_executionSpecification_Attribute_finish->setOrdered(false);
	m_executionSpecification_Attribute_finish->setContainment(false);
	m_executionSpecification_Attribute_finish->setResolveProxies(true);
	m_executionSpecification_Attribute_finish->setDefaultValueLiteral("");	
	
	m_executionSpecification_Attribute_finish->_setID(EXECUTIONSPECIFICATION_ATTRIBUTE_FINISH);
	m_executionSpecification_Attribute_start->setName("start");
	m_executionSpecification_Attribute_start->setEType(getOccurrenceSpecification_Class());
	m_executionSpecification_Attribute_start->setLowerBound(1);
	m_executionSpecification_Attribute_start->setUpperBound(1);
	m_executionSpecification_Attribute_start->setTransient(false);
	m_executionSpecification_Attribute_start->setVolatile(false);
	m_executionSpecification_Attribute_start->setChangeable(true);
	m_executionSpecification_Attribute_start->setUnsettable(false);
	m_executionSpecification_Attribute_start->setUnique(true);
	m_executionSpecification_Attribute_start->setDerived(false);
	m_executionSpecification_Attribute_start->setOrdered(false);
	m_executionSpecification_Attribute_start->setContainment(false);
	m_executionSpecification_Attribute_start->setResolveProxies(true);
	m_executionSpecification_Attribute_start->setDefaultValueLiteral("");	
	
	m_executionSpecification_Attribute_start->_setID(EXECUTIONSPECIFICATION_ATTRIBUTE_START);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeExpansionNodeContent()
{
	m_expansionNode_Class->setName("ExpansionNode");
	m_expansionNode_Class->setAbstract(false);
	m_expansionNode_Class->setInterface(false);
	
	m_expansionNode_Class->_setID(EXPANSIONNODE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_expansionNode_Attribute_regionAsInput->setName("regionAsInput");
	m_expansionNode_Attribute_regionAsInput->setEType(getExpansionRegion_Class());
	m_expansionNode_Attribute_regionAsInput->setLowerBound(0);
	m_expansionNode_Attribute_regionAsInput->setUpperBound(1);
	m_expansionNode_Attribute_regionAsInput->setTransient(false);
	m_expansionNode_Attribute_regionAsInput->setVolatile(false);
	m_expansionNode_Attribute_regionAsInput->setChangeable(true);
	m_expansionNode_Attribute_regionAsInput->setUnsettable(false);
	m_expansionNode_Attribute_regionAsInput->setUnique(true);
	m_expansionNode_Attribute_regionAsInput->setDerived(false);
	m_expansionNode_Attribute_regionAsInput->setOrdered(false);
	m_expansionNode_Attribute_regionAsInput->setContainment(false);
	m_expansionNode_Attribute_regionAsInput->setResolveProxies(true);
	m_expansionNode_Attribute_regionAsInput->setDefaultValueLiteral("");	
	m_expansionNode_Attribute_regionAsInput->setEOpposite(uml::umlPackage::eInstance()->getExpansionRegion_Attribute_inputElement());
	
	m_expansionNode_Attribute_regionAsInput->_setID(EXPANSIONNODE_ATTRIBUTE_REGIONASINPUT);
	m_expansionNode_Attribute_regionAsOutput->setName("regionAsOutput");
	m_expansionNode_Attribute_regionAsOutput->setEType(getExpansionRegion_Class());
	m_expansionNode_Attribute_regionAsOutput->setLowerBound(0);
	m_expansionNode_Attribute_regionAsOutput->setUpperBound(1);
	m_expansionNode_Attribute_regionAsOutput->setTransient(false);
	m_expansionNode_Attribute_regionAsOutput->setVolatile(false);
	m_expansionNode_Attribute_regionAsOutput->setChangeable(true);
	m_expansionNode_Attribute_regionAsOutput->setUnsettable(false);
	m_expansionNode_Attribute_regionAsOutput->setUnique(true);
	m_expansionNode_Attribute_regionAsOutput->setDerived(false);
	m_expansionNode_Attribute_regionAsOutput->setOrdered(false);
	m_expansionNode_Attribute_regionAsOutput->setContainment(false);
	m_expansionNode_Attribute_regionAsOutput->setResolveProxies(true);
	m_expansionNode_Attribute_regionAsOutput->setDefaultValueLiteral("");	
	m_expansionNode_Attribute_regionAsOutput->setEOpposite(uml::umlPackage::eInstance()->getExpansionRegion_Attribute_outputElement());
	
	m_expansionNode_Attribute_regionAsOutput->_setID(EXPANSIONNODE_ATTRIBUTE_REGIONASOUTPUT);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeExpansionRegionContent()
{
	m_expansionRegion_Class->setName("ExpansionRegion");
	m_expansionRegion_Class->setAbstract(false);
	m_expansionRegion_Class->setInterface(false);
	
	m_expansionRegion_Class->_setID(EXPANSIONREGION_CLASS);
	
	/*
	 * EAttributes
	 */
	m_expansionRegion_Attribute_mode = getExpansionRegion_Attribute_mode();
	m_expansionRegion_Attribute_mode->setName("mode");
	m_expansionRegion_Attribute_mode->setEType(getExpansionKind_Class());
	m_expansionRegion_Attribute_mode->setLowerBound(1);
	m_expansionRegion_Attribute_mode->setUpperBound(1);
	m_expansionRegion_Attribute_mode->setTransient(false);
	m_expansionRegion_Attribute_mode->setVolatile(false);
	m_expansionRegion_Attribute_mode->setChangeable(true);
	m_expansionRegion_Attribute_mode->setUnsettable(false);
	m_expansionRegion_Attribute_mode->setUnique(true);
	m_expansionRegion_Attribute_mode->setDerived(false);
	m_expansionRegion_Attribute_mode->setOrdered(false);
	m_expansionRegion_Attribute_mode->setID(false);
	m_expansionRegion_Attribute_mode->setDefaultValueLiteral("iterative");
	
	m_expansionRegion_Attribute_mode->_setID(EXPANSIONREGION_ATTRIBUTE_MODE);
	
	/*
	 * EReferences
	 */
	m_expansionRegion_Attribute_inputElement->setName("inputElement");
	m_expansionRegion_Attribute_inputElement->setEType(getExpansionNode_Class());
	m_expansionRegion_Attribute_inputElement->setLowerBound(1);
	m_expansionRegion_Attribute_inputElement->setUpperBound(-1);
	m_expansionRegion_Attribute_inputElement->setTransient(false);
	m_expansionRegion_Attribute_inputElement->setVolatile(false);
	m_expansionRegion_Attribute_inputElement->setChangeable(true);
	m_expansionRegion_Attribute_inputElement->setUnsettable(false);
	m_expansionRegion_Attribute_inputElement->setUnique(true);
	m_expansionRegion_Attribute_inputElement->setDerived(false);
	m_expansionRegion_Attribute_inputElement->setOrdered(false);
	m_expansionRegion_Attribute_inputElement->setContainment(false);
	m_expansionRegion_Attribute_inputElement->setResolveProxies(true);
	m_expansionRegion_Attribute_inputElement->setDefaultValueLiteral("");	
	m_expansionRegion_Attribute_inputElement->setEOpposite(uml::umlPackage::eInstance()->getExpansionNode_Attribute_regionAsInput());
	
	m_expansionRegion_Attribute_inputElement->_setID(EXPANSIONREGION_ATTRIBUTE_INPUTELEMENT);
	m_expansionRegion_Attribute_outputElement->setName("outputElement");
	m_expansionRegion_Attribute_outputElement->setEType(getExpansionNode_Class());
	m_expansionRegion_Attribute_outputElement->setLowerBound(0);
	m_expansionRegion_Attribute_outputElement->setUpperBound(-1);
	m_expansionRegion_Attribute_outputElement->setTransient(false);
	m_expansionRegion_Attribute_outputElement->setVolatile(false);
	m_expansionRegion_Attribute_outputElement->setChangeable(true);
	m_expansionRegion_Attribute_outputElement->setUnsettable(false);
	m_expansionRegion_Attribute_outputElement->setUnique(true);
	m_expansionRegion_Attribute_outputElement->setDerived(false);
	m_expansionRegion_Attribute_outputElement->setOrdered(false);
	m_expansionRegion_Attribute_outputElement->setContainment(false);
	m_expansionRegion_Attribute_outputElement->setResolveProxies(true);
	m_expansionRegion_Attribute_outputElement->setDefaultValueLiteral("");	
	m_expansionRegion_Attribute_outputElement->setEOpposite(uml::umlPackage::eInstance()->getExpansionNode_Attribute_regionAsOutput());
	
	m_expansionRegion_Attribute_outputElement->_setID(EXPANSIONREGION_ATTRIBUTE_OUTPUTELEMENT);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeExpressionContent()
{
	m_expression_Class->setName("Expression");
	m_expression_Class->setAbstract(false);
	m_expression_Class->setInterface(false);
	
	m_expression_Class->_setID(EXPRESSION_CLASS);
	
	/*
	 * EAttributes
	 */
	m_expression_Attribute_symbol = getExpression_Attribute_symbol();
	m_expression_Attribute_symbol->setName("symbol");
	m_expression_Attribute_symbol->setEType(types::typesPackage::eInstance()->getString_Class());
	m_expression_Attribute_symbol->setLowerBound(0);
	m_expression_Attribute_symbol->setUpperBound(1);
	m_expression_Attribute_symbol->setTransient(false);
	m_expression_Attribute_symbol->setVolatile(false);
	m_expression_Attribute_symbol->setChangeable(true);
	m_expression_Attribute_symbol->setUnsettable(true);
	m_expression_Attribute_symbol->setUnique(true);
	m_expression_Attribute_symbol->setDerived(false);
	m_expression_Attribute_symbol->setOrdered(false);
	m_expression_Attribute_symbol->setID(false);
	m_expression_Attribute_symbol->setDefaultValueLiteral("");
	
	m_expression_Attribute_symbol->_setID(EXPRESSION_ATTRIBUTE_SYMBOL);
	
	/*
	 * EReferences
	 */
	m_expression_Attribute_operand->setName("operand");
	m_expression_Attribute_operand->setEType(getValueSpecification_Class());
	m_expression_Attribute_operand->setLowerBound(0);
	m_expression_Attribute_operand->setUpperBound(-1);
	m_expression_Attribute_operand->setTransient(false);
	m_expression_Attribute_operand->setVolatile(false);
	m_expression_Attribute_operand->setChangeable(true);
	m_expression_Attribute_operand->setUnsettable(false);
	m_expression_Attribute_operand->setUnique(true);
	m_expression_Attribute_operand->setDerived(false);
	m_expression_Attribute_operand->setOrdered(true);
	m_expression_Attribute_operand->setContainment(true);
	m_expression_Attribute_operand->setResolveProxies(true);
	m_expression_Attribute_operand->setDefaultValueLiteral("");	
	
	m_expression_Attribute_operand->_setID(EXPRESSION_ATTRIBUTE_OPERAND);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeExtendContent()
{
	m_extend_Class->setName("Extend");
	m_extend_Class->setAbstract(false);
	m_extend_Class->setInterface(false);
	
	m_extend_Class->_setID(EXTEND_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_extend_Attribute_condition->setName("condition");
	m_extend_Attribute_condition->setEType(getConstraint_Class());
	m_extend_Attribute_condition->setLowerBound(0);
	m_extend_Attribute_condition->setUpperBound(1);
	m_extend_Attribute_condition->setTransient(false);
	m_extend_Attribute_condition->setVolatile(false);
	m_extend_Attribute_condition->setChangeable(true);
	m_extend_Attribute_condition->setUnsettable(false);
	m_extend_Attribute_condition->setUnique(true);
	m_extend_Attribute_condition->setDerived(false);
	m_extend_Attribute_condition->setOrdered(false);
	m_extend_Attribute_condition->setContainment(true);
	m_extend_Attribute_condition->setResolveProxies(true);
	m_extend_Attribute_condition->setDefaultValueLiteral("");	
	
	m_extend_Attribute_condition->_setID(EXTEND_ATTRIBUTE_CONDITION);
	m_extend_Attribute_extendedCase->setName("extendedCase");
	m_extend_Attribute_extendedCase->setEType(getUseCase_Class());
	m_extend_Attribute_extendedCase->setLowerBound(1);
	m_extend_Attribute_extendedCase->setUpperBound(1);
	m_extend_Attribute_extendedCase->setTransient(false);
	m_extend_Attribute_extendedCase->setVolatile(false);
	m_extend_Attribute_extendedCase->setChangeable(true);
	m_extend_Attribute_extendedCase->setUnsettable(false);
	m_extend_Attribute_extendedCase->setUnique(true);
	m_extend_Attribute_extendedCase->setDerived(false);
	m_extend_Attribute_extendedCase->setOrdered(false);
	m_extend_Attribute_extendedCase->setContainment(false);
	m_extend_Attribute_extendedCase->setResolveProxies(true);
	m_extend_Attribute_extendedCase->setDefaultValueLiteral("");	
	
	m_extend_Attribute_extendedCase->_setID(EXTEND_ATTRIBUTE_EXTENDEDCASE);
	m_extend_Attribute_extension->setName("extension");
	m_extend_Attribute_extension->setEType(getUseCase_Class());
	m_extend_Attribute_extension->setLowerBound(1);
	m_extend_Attribute_extension->setUpperBound(1);
	m_extend_Attribute_extension->setTransient(false);
	m_extend_Attribute_extension->setVolatile(false);
	m_extend_Attribute_extension->setChangeable(true);
	m_extend_Attribute_extension->setUnsettable(false);
	m_extend_Attribute_extension->setUnique(true);
	m_extend_Attribute_extension->setDerived(false);
	m_extend_Attribute_extension->setOrdered(false);
	m_extend_Attribute_extension->setContainment(false);
	m_extend_Attribute_extension->setResolveProxies(true);
	m_extend_Attribute_extension->setDefaultValueLiteral("");	
	m_extend_Attribute_extension->setEOpposite(uml::umlPackage::eInstance()->getUseCase_Attribute_extend());
	
	m_extend_Attribute_extension->_setID(EXTEND_ATTRIBUTE_EXTENSION);
	m_extend_Attribute_extensionLocation->setName("extensionLocation");
	m_extend_Attribute_extensionLocation->setEType(getExtensionPoint_Class());
	m_extend_Attribute_extensionLocation->setLowerBound(1);
	m_extend_Attribute_extensionLocation->setUpperBound(-1);
	m_extend_Attribute_extensionLocation->setTransient(false);
	m_extend_Attribute_extensionLocation->setVolatile(false);
	m_extend_Attribute_extensionLocation->setChangeable(true);
	m_extend_Attribute_extensionLocation->setUnsettable(false);
	m_extend_Attribute_extensionLocation->setUnique(true);
	m_extend_Attribute_extensionLocation->setDerived(false);
	m_extend_Attribute_extensionLocation->setOrdered(true);
	m_extend_Attribute_extensionLocation->setContainment(false);
	m_extend_Attribute_extensionLocation->setResolveProxies(true);
	m_extend_Attribute_extensionLocation->setDefaultValueLiteral("");	
	
	m_extend_Attribute_extensionLocation->_setID(EXTEND_ATTRIBUTE_EXTENSIONLOCATION);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeExtensionContent()
{
	m_extension_Class->setName("Extension");
	m_extension_Class->setAbstract(false);
	m_extension_Class->setInterface(false);
	
	m_extension_Class->_setID(EXTENSION_CLASS);
	
	/*
	 * EAttributes
	 */
	m_extension_Attribute_isRequired = getExtension_Attribute_isRequired();
	m_extension_Attribute_isRequired->setName("isRequired");
	m_extension_Attribute_isRequired->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_extension_Attribute_isRequired->setLowerBound(1);
	m_extension_Attribute_isRequired->setUpperBound(1);
	m_extension_Attribute_isRequired->setTransient(true);
	m_extension_Attribute_isRequired->setVolatile(true);
	m_extension_Attribute_isRequired->setChangeable(false);
	m_extension_Attribute_isRequired->setUnsettable(false);
	m_extension_Attribute_isRequired->setUnique(true);
	m_extension_Attribute_isRequired->setDerived(true);
	m_extension_Attribute_isRequired->setOrdered(false);
	m_extension_Attribute_isRequired->setID(false);
	m_extension_Attribute_isRequired->setDefaultValueLiteral("");
	
	m_extension_Attribute_isRequired->_setID(EXTENSION_ATTRIBUTE_ISREQUIRED);
	
	/*
	 * EReferences
	 */
	m_extension_Attribute_metaclass->setName("metaclass");
	m_extension_Attribute_metaclass->setEType(getClass_Class());
	m_extension_Attribute_metaclass->setLowerBound(1);
	m_extension_Attribute_metaclass->setUpperBound(1);
	m_extension_Attribute_metaclass->setTransient(true);
	m_extension_Attribute_metaclass->setVolatile(true);
	m_extension_Attribute_metaclass->setChangeable(false);
	m_extension_Attribute_metaclass->setUnsettable(false);
	m_extension_Attribute_metaclass->setUnique(true);
	m_extension_Attribute_metaclass->setDerived(true);
	m_extension_Attribute_metaclass->setOrdered(false);
	m_extension_Attribute_metaclass->setContainment(false);
	m_extension_Attribute_metaclass->setResolveProxies(true);
	m_extension_Attribute_metaclass->setDefaultValueLiteral("");	
	m_extension_Attribute_metaclass->setEOpposite(uml::umlPackage::eInstance()->getClass_Attribute_extension());
	
	m_extension_Attribute_metaclass->_setID(EXTENSION_ATTRIBUTE_METACLASS);
	
	/*
	 * EOperations
	 */
	m_extension_Operation_getMetaclass->setName("getMetaclass");
	m_extension_Operation_getMetaclass->setEType(getClass_Class());
	m_extension_Operation_getMetaclass->setLowerBound(1);
	m_extension_Operation_getMetaclass->setUpperBound(1);
	m_extension_Operation_getMetaclass->setUnique(true);
	m_extension_Operation_getMetaclass->setOrdered(false);
	
	m_extension_Operation_getMetaclass->_setID(EXTENSION_OPERATION_GETMETACLASS);
	
	
	m_extension_Operation_getStereotype->setName("getStereotype");
	m_extension_Operation_getStereotype->setEType(getStereotype_Class());
	m_extension_Operation_getStereotype->setLowerBound(0);
	m_extension_Operation_getStereotype->setUpperBound(1);
	m_extension_Operation_getStereotype->setUnique(true);
	m_extension_Operation_getStereotype->setOrdered(false);
	
	m_extension_Operation_getStereotype->_setID(EXTENSION_OPERATION_GETSTEREOTYPE);
	
	
	m_extension_Operation_getStereotypeEnd->setName("getStereotypeEnd");
	m_extension_Operation_getStereotypeEnd->setEType(getProperty_Class());
	m_extension_Operation_getStereotypeEnd->setLowerBound(0);
	m_extension_Operation_getStereotypeEnd->setUpperBound(1);
	m_extension_Operation_getStereotypeEnd->setUnique(true);
	m_extension_Operation_getStereotypeEnd->setOrdered(false);
	
	m_extension_Operation_getStereotypeEnd->_setID(EXTENSION_OPERATION_GETSTEREOTYPEEND);
	
	
	m_extension_Operation_isRequired->setName("isRequired");
	m_extension_Operation_isRequired->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_extension_Operation_isRequired->setLowerBound(1);
	m_extension_Operation_isRequired->setUpperBound(1);
	m_extension_Operation_isRequired->setUnique(true);
	m_extension_Operation_isRequired->setOrdered(false);
	
	m_extension_Operation_isRequired->_setID(EXTENSION_OPERATION_ISREQUIRED);
	
	
	m_extension_Operation_metaclassEnd->setName("metaclassEnd");
	m_extension_Operation_metaclassEnd->setEType(getProperty_Class());
	m_extension_Operation_metaclassEnd->setLowerBound(1);
	m_extension_Operation_metaclassEnd->setUpperBound(1);
	m_extension_Operation_metaclassEnd->setUnique(true);
	m_extension_Operation_metaclassEnd->setOrdered(false);
	
	m_extension_Operation_metaclassEnd->_setID(EXTENSION_OPERATION_METACLASSEND);
	
	
	
}

void umlPackageImpl::initializeExtensionEndContent()
{
	m_extensionEnd_Class->setName("ExtensionEnd");
	m_extensionEnd_Class->setAbstract(false);
	m_extensionEnd_Class->setInterface(false);
	
	m_extensionEnd_Class->_setID(EXTENSIONEND_CLASS);
	
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

void umlPackageImpl::initializeExtensionPointContent()
{
	m_extensionPoint_Class->setName("ExtensionPoint");
	m_extensionPoint_Class->setAbstract(false);
	m_extensionPoint_Class->setInterface(false);
	
	m_extensionPoint_Class->_setID(EXTENSIONPOINT_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_extensionPoint_Attribute_useCase->setName("useCase");
	m_extensionPoint_Attribute_useCase->setEType(getUseCase_Class());
	m_extensionPoint_Attribute_useCase->setLowerBound(1);
	m_extensionPoint_Attribute_useCase->setUpperBound(1);
	m_extensionPoint_Attribute_useCase->setTransient(false);
	m_extensionPoint_Attribute_useCase->setVolatile(false);
	m_extensionPoint_Attribute_useCase->setChangeable(true);
	m_extensionPoint_Attribute_useCase->setUnsettable(false);
	m_extensionPoint_Attribute_useCase->setUnique(true);
	m_extensionPoint_Attribute_useCase->setDerived(false);
	m_extensionPoint_Attribute_useCase->setOrdered(false);
	m_extensionPoint_Attribute_useCase->setContainment(false);
	m_extensionPoint_Attribute_useCase->setResolveProxies(true);
	m_extensionPoint_Attribute_useCase->setDefaultValueLiteral("");	
	m_extensionPoint_Attribute_useCase->setEOpposite(uml::umlPackage::eInstance()->getUseCase_Attribute_extensionPoint());
	
	m_extensionPoint_Attribute_useCase->_setID(EXTENSIONPOINT_ATTRIBUTE_USECASE);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeFactoryContent()
{
	m_factory_Class->setName("Factory");
	m_factory_Class->setAbstract(false);
	m_factory_Class->setInterface(false);
	
	m_factory_Class->_setID(FACTORY_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_factory_Operation_create_Class->setName("create");
	m_factory_Operation_create_Class->setEType(getElement_Class());
	m_factory_Operation_create_Class->setLowerBound(0);
	m_factory_Operation_create_Class->setUpperBound(1);
	m_factory_Operation_create_Class->setUnique(true);
	m_factory_Operation_create_Class->setOrdered(true);
	
	m_factory_Operation_create_Class->_setID(FACTORY_OPERATION_CREATE_CLASS);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_factory_Operation_create_Class);
		parameter->setName("metaClass");
		parameter->setEType(getClass_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void umlPackageImpl::initializeFeatureContent()
{
	m_feature_Class->setName("Feature");
	m_feature_Class->setAbstract(true);
	m_feature_Class->setInterface(false);
	
	m_feature_Class->_setID(FEATURE_CLASS);
	
	/*
	 * EAttributes
	 */
	m_feature_Attribute_isStatic = getFeature_Attribute_isStatic();
	m_feature_Attribute_isStatic->setName("isStatic");
	m_feature_Attribute_isStatic->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_feature_Attribute_isStatic->setLowerBound(1);
	m_feature_Attribute_isStatic->setUpperBound(1);
	m_feature_Attribute_isStatic->setTransient(false);
	m_feature_Attribute_isStatic->setVolatile(false);
	m_feature_Attribute_isStatic->setChangeable(true);
	m_feature_Attribute_isStatic->setUnsettable(false);
	m_feature_Attribute_isStatic->setUnique(true);
	m_feature_Attribute_isStatic->setDerived(false);
	m_feature_Attribute_isStatic->setOrdered(false);
	m_feature_Attribute_isStatic->setID(false);
	m_feature_Attribute_isStatic->setDefaultValueLiteral("false");
	
	m_feature_Attribute_isStatic->_setID(FEATURE_ATTRIBUTE_ISSTATIC);
	
	/*
	 * EReferences
	 */
	m_feature_Attribute_featuringClassifier->setName("featuringClassifier");
	m_feature_Attribute_featuringClassifier->setEType(getClassifier_Class());
	m_feature_Attribute_featuringClassifier->setLowerBound(0);
	m_feature_Attribute_featuringClassifier->setUpperBound(-1);
	m_feature_Attribute_featuringClassifier->setTransient(true);
	m_feature_Attribute_featuringClassifier->setVolatile(true);
	m_feature_Attribute_featuringClassifier->setChangeable(false);
	m_feature_Attribute_featuringClassifier->setUnsettable(false);
	m_feature_Attribute_featuringClassifier->setUnique(true);
	m_feature_Attribute_featuringClassifier->setDerived(true);
	m_feature_Attribute_featuringClassifier->setOrdered(false);
	m_feature_Attribute_featuringClassifier->setContainment(false);
	m_feature_Attribute_featuringClassifier->setResolveProxies(true);
	m_feature_Attribute_featuringClassifier->setDefaultValueLiteral("");	
	m_feature_Attribute_featuringClassifier->setEOpposite(uml::umlPackage::eInstance()->getClassifier_Attribute_feature());
	
	m_feature_Attribute_featuringClassifier->_setID(FEATURE_ATTRIBUTE_FEATURINGCLASSIFIER);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeFinalNodeContent()
{
	m_finalNode_Class->setName("FinalNode");
	m_finalNode_Class->setAbstract(true);
	m_finalNode_Class->setInterface(false);
	
	m_finalNode_Class->_setID(FINALNODE_CLASS);
	
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

void umlPackageImpl::initializeFinalStateContent()
{
	m_finalState_Class->setName("FinalState");
	m_finalState_Class->setAbstract(false);
	m_finalState_Class->setInterface(false);
	
	m_finalState_Class->_setID(FINALSTATE_CLASS);
	
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

void umlPackageImpl::initializeFlowFinalNodeContent()
{
	m_flowFinalNode_Class->setName("FlowFinalNode");
	m_flowFinalNode_Class->setAbstract(false);
	m_flowFinalNode_Class->setInterface(false);
	
	m_flowFinalNode_Class->_setID(FLOWFINALNODE_CLASS);
	
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

void umlPackageImpl::initializeForkNodeContent()
{
	m_forkNode_Class->setName("ForkNode");
	m_forkNode_Class->setAbstract(false);
	m_forkNode_Class->setInterface(false);
	
	m_forkNode_Class->_setID(FORKNODE_CLASS);
	
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

void umlPackageImpl::initializeFunctionBehaviorContent()
{
	m_functionBehavior_Class->setName("FunctionBehavior");
	m_functionBehavior_Class->setAbstract(false);
	m_functionBehavior_Class->setInterface(false);
	
	m_functionBehavior_Class->_setID(FUNCTIONBEHAVIOR_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_functionBehavior_Operation_hasAllDataTypeAttributes_DataType->setName("hasAllDataTypeAttributes");
	m_functionBehavior_Operation_hasAllDataTypeAttributes_DataType->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_functionBehavior_Operation_hasAllDataTypeAttributes_DataType->setLowerBound(1);
	m_functionBehavior_Operation_hasAllDataTypeAttributes_DataType->setUpperBound(1);
	m_functionBehavior_Operation_hasAllDataTypeAttributes_DataType->setUnique(true);
	m_functionBehavior_Operation_hasAllDataTypeAttributes_DataType->setOrdered(false);
	
	m_functionBehavior_Operation_hasAllDataTypeAttributes_DataType->_setID(FUNCTIONBEHAVIOR_OPERATION_HASALLDATATYPEATTRIBUTES_DATATYPE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_functionBehavior_Operation_hasAllDataTypeAttributes_DataType);
		parameter->setName("d");
		parameter->setEType(getDataType_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void umlPackageImpl::initializeGateContent()
{
	m_gate_Class->setName("Gate");
	m_gate_Class->setAbstract(false);
	m_gate_Class->setInterface(false);
	
	m_gate_Class->_setID(GATE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_gate_Operation_getName->setName("getName");
	m_gate_Operation_getName->setEType(types::typesPackage::eInstance()->getString_Class());
	m_gate_Operation_getName->setLowerBound(1);
	m_gate_Operation_getName->setUpperBound(1);
	m_gate_Operation_getName->setUnique(true);
	m_gate_Operation_getName->setOrdered(false);
	
	m_gate_Operation_getName->_setID(GATE_OPERATION_GETNAME);
	
	
	m_gate_Operation_getOperand->setName("getOperand");
	m_gate_Operation_getOperand->setEType(getInteractionOperand_Class());
	m_gate_Operation_getOperand->setLowerBound(1);
	m_gate_Operation_getOperand->setUpperBound(1);
	m_gate_Operation_getOperand->setUnique(true);
	m_gate_Operation_getOperand->setOrdered(false);
	
	m_gate_Operation_getOperand->_setID(GATE_OPERATION_GETOPERAND);
	
	
	m_gate_Operation_isActual->setName("isActual");
	m_gate_Operation_isActual->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_gate_Operation_isActual->setLowerBound(1);
	m_gate_Operation_isActual->setUpperBound(1);
	m_gate_Operation_isActual->setUnique(true);
	m_gate_Operation_isActual->setOrdered(false);
	
	m_gate_Operation_isActual->_setID(GATE_OPERATION_ISACTUAL);
	
	
	m_gate_Operation_isFormal->setName("isFormal");
	m_gate_Operation_isFormal->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_gate_Operation_isFormal->setLowerBound(1);
	m_gate_Operation_isFormal->setUpperBound(1);
	m_gate_Operation_isFormal->setUnique(true);
	m_gate_Operation_isFormal->setOrdered(false);
	
	m_gate_Operation_isFormal->_setID(GATE_OPERATION_ISFORMAL);
	
	
	m_gate_Operation_isInsideCF->setName("isInsideCF");
	m_gate_Operation_isInsideCF->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_gate_Operation_isInsideCF->setLowerBound(1);
	m_gate_Operation_isInsideCF->setUpperBound(1);
	m_gate_Operation_isInsideCF->setUnique(true);
	m_gate_Operation_isInsideCF->setOrdered(false);
	
	m_gate_Operation_isInsideCF->_setID(GATE_OPERATION_ISINSIDECF);
	
	
	m_gate_Operation_isOutsideCF->setName("isOutsideCF");
	m_gate_Operation_isOutsideCF->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_gate_Operation_isOutsideCF->setLowerBound(1);
	m_gate_Operation_isOutsideCF->setUpperBound(1);
	m_gate_Operation_isOutsideCF->setUnique(true);
	m_gate_Operation_isOutsideCF->setOrdered(false);
	
	m_gate_Operation_isOutsideCF->_setID(GATE_OPERATION_ISOUTSIDECF);
	
	
	m_gate_Operation_matches_Gate->setName("matches");
	m_gate_Operation_matches_Gate->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_gate_Operation_matches_Gate->setLowerBound(1);
	m_gate_Operation_matches_Gate->setUpperBound(1);
	m_gate_Operation_matches_Gate->setUnique(true);
	m_gate_Operation_matches_Gate->setOrdered(false);
	
	m_gate_Operation_matches_Gate->_setID(GATE_OPERATION_MATCHES_GATE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_gate_Operation_matches_Gate);
		parameter->setName("gateToMatch");
		parameter->setEType(getGate_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void umlPackageImpl::initializeGeneralOrderingContent()
{
	m_generalOrdering_Class->setName("GeneralOrdering");
	m_generalOrdering_Class->setAbstract(false);
	m_generalOrdering_Class->setInterface(false);
	
	m_generalOrdering_Class->_setID(GENERALORDERING_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_generalOrdering_Attribute_after->setName("after");
	m_generalOrdering_Attribute_after->setEType(getOccurrenceSpecification_Class());
	m_generalOrdering_Attribute_after->setLowerBound(1);
	m_generalOrdering_Attribute_after->setUpperBound(1);
	m_generalOrdering_Attribute_after->setTransient(false);
	m_generalOrdering_Attribute_after->setVolatile(false);
	m_generalOrdering_Attribute_after->setChangeable(true);
	m_generalOrdering_Attribute_after->setUnsettable(false);
	m_generalOrdering_Attribute_after->setUnique(true);
	m_generalOrdering_Attribute_after->setDerived(false);
	m_generalOrdering_Attribute_after->setOrdered(false);
	m_generalOrdering_Attribute_after->setContainment(false);
	m_generalOrdering_Attribute_after->setResolveProxies(true);
	m_generalOrdering_Attribute_after->setDefaultValueLiteral("");	
	m_generalOrdering_Attribute_after->setEOpposite(uml::umlPackage::eInstance()->getOccurrenceSpecification_Attribute_toBefore());
	
	m_generalOrdering_Attribute_after->_setID(GENERALORDERING_ATTRIBUTE_AFTER);
	m_generalOrdering_Attribute_before->setName("before");
	m_generalOrdering_Attribute_before->setEType(getOccurrenceSpecification_Class());
	m_generalOrdering_Attribute_before->setLowerBound(1);
	m_generalOrdering_Attribute_before->setUpperBound(1);
	m_generalOrdering_Attribute_before->setTransient(false);
	m_generalOrdering_Attribute_before->setVolatile(false);
	m_generalOrdering_Attribute_before->setChangeable(true);
	m_generalOrdering_Attribute_before->setUnsettable(false);
	m_generalOrdering_Attribute_before->setUnique(true);
	m_generalOrdering_Attribute_before->setDerived(false);
	m_generalOrdering_Attribute_before->setOrdered(false);
	m_generalOrdering_Attribute_before->setContainment(false);
	m_generalOrdering_Attribute_before->setResolveProxies(true);
	m_generalOrdering_Attribute_before->setDefaultValueLiteral("");	
	m_generalOrdering_Attribute_before->setEOpposite(uml::umlPackage::eInstance()->getOccurrenceSpecification_Attribute_toAfter());
	
	m_generalOrdering_Attribute_before->_setID(GENERALORDERING_ATTRIBUTE_BEFORE);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeGeneralizationContent()
{
	m_generalization_Class->setName("Generalization");
	m_generalization_Class->setAbstract(false);
	m_generalization_Class->setInterface(false);
	
	m_generalization_Class->_setID(GENERALIZATION_CLASS);
	
	/*
	 * EAttributes
	 */
	m_generalization_Attribute_isSubstitutable = getGeneralization_Attribute_isSubstitutable();
	m_generalization_Attribute_isSubstitutable->setName("isSubstitutable");
	m_generalization_Attribute_isSubstitutable->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_generalization_Attribute_isSubstitutable->setLowerBound(0);
	m_generalization_Attribute_isSubstitutable->setUpperBound(1);
	m_generalization_Attribute_isSubstitutable->setTransient(false);
	m_generalization_Attribute_isSubstitutable->setVolatile(false);
	m_generalization_Attribute_isSubstitutable->setChangeable(true);
	m_generalization_Attribute_isSubstitutable->setUnsettable(false);
	m_generalization_Attribute_isSubstitutable->setUnique(true);
	m_generalization_Attribute_isSubstitutable->setDerived(false);
	m_generalization_Attribute_isSubstitutable->setOrdered(false);
	m_generalization_Attribute_isSubstitutable->setID(false);
	m_generalization_Attribute_isSubstitutable->setDefaultValueLiteral("true");
	
	m_generalization_Attribute_isSubstitutable->_setID(GENERALIZATION_ATTRIBUTE_ISSUBSTITUTABLE);
	
	/*
	 * EReferences
	 */
	m_generalization_Attribute_general->setName("general");
	m_generalization_Attribute_general->setEType(getClassifier_Class());
	m_generalization_Attribute_general->setLowerBound(1);
	m_generalization_Attribute_general->setUpperBound(1);
	m_generalization_Attribute_general->setTransient(false);
	m_generalization_Attribute_general->setVolatile(false);
	m_generalization_Attribute_general->setChangeable(true);
	m_generalization_Attribute_general->setUnsettable(false);
	m_generalization_Attribute_general->setUnique(true);
	m_generalization_Attribute_general->setDerived(false);
	m_generalization_Attribute_general->setOrdered(false);
	m_generalization_Attribute_general->setContainment(false);
	m_generalization_Attribute_general->setResolveProxies(true);
	m_generalization_Attribute_general->setDefaultValueLiteral("");	
	
	m_generalization_Attribute_general->_setID(GENERALIZATION_ATTRIBUTE_GENERAL);
	m_generalization_Attribute_generalizationSet->setName("generalizationSet");
	m_generalization_Attribute_generalizationSet->setEType(getGeneralizationSet_Class());
	m_generalization_Attribute_generalizationSet->setLowerBound(0);
	m_generalization_Attribute_generalizationSet->setUpperBound(-1);
	m_generalization_Attribute_generalizationSet->setTransient(false);
	m_generalization_Attribute_generalizationSet->setVolatile(false);
	m_generalization_Attribute_generalizationSet->setChangeable(true);
	m_generalization_Attribute_generalizationSet->setUnsettable(false);
	m_generalization_Attribute_generalizationSet->setUnique(true);
	m_generalization_Attribute_generalizationSet->setDerived(false);
	m_generalization_Attribute_generalizationSet->setOrdered(false);
	m_generalization_Attribute_generalizationSet->setContainment(false);
	m_generalization_Attribute_generalizationSet->setResolveProxies(true);
	m_generalization_Attribute_generalizationSet->setDefaultValueLiteral("");	
	m_generalization_Attribute_generalizationSet->setEOpposite(uml::umlPackage::eInstance()->getGeneralizationSet_Attribute_generalization());
	
	m_generalization_Attribute_generalizationSet->_setID(GENERALIZATION_ATTRIBUTE_GENERALIZATIONSET);
	m_generalization_Attribute_specific->setName("specific");
	m_generalization_Attribute_specific->setEType(getClassifier_Class());
	m_generalization_Attribute_specific->setLowerBound(1);
	m_generalization_Attribute_specific->setUpperBound(1);
	m_generalization_Attribute_specific->setTransient(false);
	m_generalization_Attribute_specific->setVolatile(false);
	m_generalization_Attribute_specific->setChangeable(true);
	m_generalization_Attribute_specific->setUnsettable(false);
	m_generalization_Attribute_specific->setUnique(true);
	m_generalization_Attribute_specific->setDerived(false);
	m_generalization_Attribute_specific->setOrdered(false);
	m_generalization_Attribute_specific->setContainment(false);
	m_generalization_Attribute_specific->setResolveProxies(true);
	m_generalization_Attribute_specific->setDefaultValueLiteral("");	
	m_generalization_Attribute_specific->setEOpposite(uml::umlPackage::eInstance()->getClassifier_Attribute_generalization());
	
	m_generalization_Attribute_specific->_setID(GENERALIZATION_ATTRIBUTE_SPECIFIC);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeGeneralizationSetContent()
{
	m_generalizationSet_Class->setName("GeneralizationSet");
	m_generalizationSet_Class->setAbstract(false);
	m_generalizationSet_Class->setInterface(false);
	
	m_generalizationSet_Class->_setID(GENERALIZATIONSET_CLASS);
	
	/*
	 * EAttributes
	 */
	m_generalizationSet_Attribute_isCovering = getGeneralizationSet_Attribute_isCovering();
	m_generalizationSet_Attribute_isCovering->setName("isCovering");
	m_generalizationSet_Attribute_isCovering->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_generalizationSet_Attribute_isCovering->setLowerBound(1);
	m_generalizationSet_Attribute_isCovering->setUpperBound(1);
	m_generalizationSet_Attribute_isCovering->setTransient(false);
	m_generalizationSet_Attribute_isCovering->setVolatile(false);
	m_generalizationSet_Attribute_isCovering->setChangeable(true);
	m_generalizationSet_Attribute_isCovering->setUnsettable(false);
	m_generalizationSet_Attribute_isCovering->setUnique(true);
	m_generalizationSet_Attribute_isCovering->setDerived(false);
	m_generalizationSet_Attribute_isCovering->setOrdered(false);
	m_generalizationSet_Attribute_isCovering->setID(false);
	m_generalizationSet_Attribute_isCovering->setDefaultValueLiteral("false");
	
	m_generalizationSet_Attribute_isCovering->_setID(GENERALIZATIONSET_ATTRIBUTE_ISCOVERING);
	m_generalizationSet_Attribute_isDisjoint = getGeneralizationSet_Attribute_isDisjoint();
	m_generalizationSet_Attribute_isDisjoint->setName("isDisjoint");
	m_generalizationSet_Attribute_isDisjoint->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_generalizationSet_Attribute_isDisjoint->setLowerBound(1);
	m_generalizationSet_Attribute_isDisjoint->setUpperBound(1);
	m_generalizationSet_Attribute_isDisjoint->setTransient(false);
	m_generalizationSet_Attribute_isDisjoint->setVolatile(false);
	m_generalizationSet_Attribute_isDisjoint->setChangeable(true);
	m_generalizationSet_Attribute_isDisjoint->setUnsettable(false);
	m_generalizationSet_Attribute_isDisjoint->setUnique(true);
	m_generalizationSet_Attribute_isDisjoint->setDerived(false);
	m_generalizationSet_Attribute_isDisjoint->setOrdered(false);
	m_generalizationSet_Attribute_isDisjoint->setID(false);
	m_generalizationSet_Attribute_isDisjoint->setDefaultValueLiteral("false");
	
	m_generalizationSet_Attribute_isDisjoint->_setID(GENERALIZATIONSET_ATTRIBUTE_ISDISJOINT);
	
	/*
	 * EReferences
	 */
	m_generalizationSet_Attribute_generalization->setName("generalization");
	m_generalizationSet_Attribute_generalization->setEType(getGeneralization_Class());
	m_generalizationSet_Attribute_generalization->setLowerBound(0);
	m_generalizationSet_Attribute_generalization->setUpperBound(-1);
	m_generalizationSet_Attribute_generalization->setTransient(false);
	m_generalizationSet_Attribute_generalization->setVolatile(false);
	m_generalizationSet_Attribute_generalization->setChangeable(true);
	m_generalizationSet_Attribute_generalization->setUnsettable(false);
	m_generalizationSet_Attribute_generalization->setUnique(true);
	m_generalizationSet_Attribute_generalization->setDerived(false);
	m_generalizationSet_Attribute_generalization->setOrdered(false);
	m_generalizationSet_Attribute_generalization->setContainment(false);
	m_generalizationSet_Attribute_generalization->setResolveProxies(true);
	m_generalizationSet_Attribute_generalization->setDefaultValueLiteral("");	
	m_generalizationSet_Attribute_generalization->setEOpposite(uml::umlPackage::eInstance()->getGeneralization_Attribute_generalizationSet());
	
	m_generalizationSet_Attribute_generalization->_setID(GENERALIZATIONSET_ATTRIBUTE_GENERALIZATION);
	m_generalizationSet_Attribute_powertype->setName("powertype");
	m_generalizationSet_Attribute_powertype->setEType(getClassifier_Class());
	m_generalizationSet_Attribute_powertype->setLowerBound(0);
	m_generalizationSet_Attribute_powertype->setUpperBound(1);
	m_generalizationSet_Attribute_powertype->setTransient(false);
	m_generalizationSet_Attribute_powertype->setVolatile(false);
	m_generalizationSet_Attribute_powertype->setChangeable(true);
	m_generalizationSet_Attribute_powertype->setUnsettable(false);
	m_generalizationSet_Attribute_powertype->setUnique(true);
	m_generalizationSet_Attribute_powertype->setDerived(false);
	m_generalizationSet_Attribute_powertype->setOrdered(false);
	m_generalizationSet_Attribute_powertype->setContainment(false);
	m_generalizationSet_Attribute_powertype->setResolveProxies(true);
	m_generalizationSet_Attribute_powertype->setDefaultValueLiteral("");	
	m_generalizationSet_Attribute_powertype->setEOpposite(uml::umlPackage::eInstance()->getClassifier_Attribute_powertypeExtent());
	
	m_generalizationSet_Attribute_powertype->_setID(GENERALIZATIONSET_ATTRIBUTE_POWERTYPE);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeImageContent()
{
	m_image_Class->setName("Image");
	m_image_Class->setAbstract(false);
	m_image_Class->setInterface(false);
	
	m_image_Class->_setID(IMAGE_CLASS);
	
	/*
	 * EAttributes
	 */
	m_image_Attribute_content = getImage_Attribute_content();
	m_image_Attribute_content->setName("content");
	m_image_Attribute_content->setEType(types::typesPackage::eInstance()->getString_Class());
	m_image_Attribute_content->setLowerBound(0);
	m_image_Attribute_content->setUpperBound(1);
	m_image_Attribute_content->setTransient(false);
	m_image_Attribute_content->setVolatile(false);
	m_image_Attribute_content->setChangeable(true);
	m_image_Attribute_content->setUnsettable(true);
	m_image_Attribute_content->setUnique(true);
	m_image_Attribute_content->setDerived(false);
	m_image_Attribute_content->setOrdered(false);
	m_image_Attribute_content->setID(false);
	m_image_Attribute_content->setDefaultValueLiteral("");
	
	m_image_Attribute_content->_setID(IMAGE_ATTRIBUTE_CONTENT);
	m_image_Attribute_format = getImage_Attribute_format();
	m_image_Attribute_format->setName("format");
	m_image_Attribute_format->setEType(types::typesPackage::eInstance()->getString_Class());
	m_image_Attribute_format->setLowerBound(0);
	m_image_Attribute_format->setUpperBound(1);
	m_image_Attribute_format->setTransient(false);
	m_image_Attribute_format->setVolatile(false);
	m_image_Attribute_format->setChangeable(true);
	m_image_Attribute_format->setUnsettable(true);
	m_image_Attribute_format->setUnique(true);
	m_image_Attribute_format->setDerived(false);
	m_image_Attribute_format->setOrdered(false);
	m_image_Attribute_format->setID(false);
	m_image_Attribute_format->setDefaultValueLiteral("");
	
	m_image_Attribute_format->_setID(IMAGE_ATTRIBUTE_FORMAT);
	m_image_Attribute_location = getImage_Attribute_location();
	m_image_Attribute_location->setName("location");
	m_image_Attribute_location->setEType(types::typesPackage::eInstance()->getString_Class());
	m_image_Attribute_location->setLowerBound(0);
	m_image_Attribute_location->setUpperBound(1);
	m_image_Attribute_location->setTransient(false);
	m_image_Attribute_location->setVolatile(false);
	m_image_Attribute_location->setChangeable(true);
	m_image_Attribute_location->setUnsettable(true);
	m_image_Attribute_location->setUnique(true);
	m_image_Attribute_location->setDerived(false);
	m_image_Attribute_location->setOrdered(false);
	m_image_Attribute_location->setID(false);
	m_image_Attribute_location->setDefaultValueLiteral("");
	
	m_image_Attribute_location->_setID(IMAGE_ATTRIBUTE_LOCATION);
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeIncludeContent()
{
	m_include_Class->setName("Include");
	m_include_Class->setAbstract(false);
	m_include_Class->setInterface(false);
	
	m_include_Class->_setID(INCLUDE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_include_Attribute_addition->setName("addition");
	m_include_Attribute_addition->setEType(getUseCase_Class());
	m_include_Attribute_addition->setLowerBound(1);
	m_include_Attribute_addition->setUpperBound(1);
	m_include_Attribute_addition->setTransient(false);
	m_include_Attribute_addition->setVolatile(false);
	m_include_Attribute_addition->setChangeable(true);
	m_include_Attribute_addition->setUnsettable(false);
	m_include_Attribute_addition->setUnique(true);
	m_include_Attribute_addition->setDerived(false);
	m_include_Attribute_addition->setOrdered(false);
	m_include_Attribute_addition->setContainment(false);
	m_include_Attribute_addition->setResolveProxies(true);
	m_include_Attribute_addition->setDefaultValueLiteral("");	
	
	m_include_Attribute_addition->_setID(INCLUDE_ATTRIBUTE_ADDITION);
	m_include_Attribute_includingCase->setName("includingCase");
	m_include_Attribute_includingCase->setEType(getUseCase_Class());
	m_include_Attribute_includingCase->setLowerBound(1);
	m_include_Attribute_includingCase->setUpperBound(1);
	m_include_Attribute_includingCase->setTransient(false);
	m_include_Attribute_includingCase->setVolatile(false);
	m_include_Attribute_includingCase->setChangeable(true);
	m_include_Attribute_includingCase->setUnsettable(false);
	m_include_Attribute_includingCase->setUnique(true);
	m_include_Attribute_includingCase->setDerived(false);
	m_include_Attribute_includingCase->setOrdered(false);
	m_include_Attribute_includingCase->setContainment(false);
	m_include_Attribute_includingCase->setResolveProxies(true);
	m_include_Attribute_includingCase->setDefaultValueLiteral("");	
	m_include_Attribute_includingCase->setEOpposite(uml::umlPackage::eInstance()->getUseCase_Attribute_include());
	
	m_include_Attribute_includingCase->_setID(INCLUDE_ATTRIBUTE_INCLUDINGCASE);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeInformationFlowContent()
{
	m_informationFlow_Class->setName("InformationFlow");
	m_informationFlow_Class->setAbstract(false);
	m_informationFlow_Class->setInterface(false);
	
	m_informationFlow_Class->_setID(INFORMATIONFLOW_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_informationFlow_Attribute_conveyed->setName("conveyed");
	m_informationFlow_Attribute_conveyed->setEType(getClassifier_Class());
	m_informationFlow_Attribute_conveyed->setLowerBound(1);
	m_informationFlow_Attribute_conveyed->setUpperBound(-1);
	m_informationFlow_Attribute_conveyed->setTransient(false);
	m_informationFlow_Attribute_conveyed->setVolatile(false);
	m_informationFlow_Attribute_conveyed->setChangeable(true);
	m_informationFlow_Attribute_conveyed->setUnsettable(false);
	m_informationFlow_Attribute_conveyed->setUnique(true);
	m_informationFlow_Attribute_conveyed->setDerived(false);
	m_informationFlow_Attribute_conveyed->setOrdered(false);
	m_informationFlow_Attribute_conveyed->setContainment(false);
	m_informationFlow_Attribute_conveyed->setResolveProxies(true);
	m_informationFlow_Attribute_conveyed->setDefaultValueLiteral("");	
	
	m_informationFlow_Attribute_conveyed->_setID(INFORMATIONFLOW_ATTRIBUTE_CONVEYED);
	m_informationFlow_Attribute_informationSource->setName("informationSource");
	m_informationFlow_Attribute_informationSource->setEType(getNamedElement_Class());
	m_informationFlow_Attribute_informationSource->setLowerBound(1);
	m_informationFlow_Attribute_informationSource->setUpperBound(-1);
	m_informationFlow_Attribute_informationSource->setTransient(false);
	m_informationFlow_Attribute_informationSource->setVolatile(false);
	m_informationFlow_Attribute_informationSource->setChangeable(true);
	m_informationFlow_Attribute_informationSource->setUnsettable(false);
	m_informationFlow_Attribute_informationSource->setUnique(true);
	m_informationFlow_Attribute_informationSource->setDerived(false);
	m_informationFlow_Attribute_informationSource->setOrdered(false);
	m_informationFlow_Attribute_informationSource->setContainment(false);
	m_informationFlow_Attribute_informationSource->setResolveProxies(true);
	m_informationFlow_Attribute_informationSource->setDefaultValueLiteral("");	
	
	m_informationFlow_Attribute_informationSource->_setID(INFORMATIONFLOW_ATTRIBUTE_INFORMATIONSOURCE);
	m_informationFlow_Attribute_informationTarget->setName("informationTarget");
	m_informationFlow_Attribute_informationTarget->setEType(getNamedElement_Class());
	m_informationFlow_Attribute_informationTarget->setLowerBound(1);
	m_informationFlow_Attribute_informationTarget->setUpperBound(-1);
	m_informationFlow_Attribute_informationTarget->setTransient(false);
	m_informationFlow_Attribute_informationTarget->setVolatile(false);
	m_informationFlow_Attribute_informationTarget->setChangeable(true);
	m_informationFlow_Attribute_informationTarget->setUnsettable(false);
	m_informationFlow_Attribute_informationTarget->setUnique(true);
	m_informationFlow_Attribute_informationTarget->setDerived(false);
	m_informationFlow_Attribute_informationTarget->setOrdered(false);
	m_informationFlow_Attribute_informationTarget->setContainment(false);
	m_informationFlow_Attribute_informationTarget->setResolveProxies(true);
	m_informationFlow_Attribute_informationTarget->setDefaultValueLiteral("");	
	
	m_informationFlow_Attribute_informationTarget->_setID(INFORMATIONFLOW_ATTRIBUTE_INFORMATIONTARGET);
	m_informationFlow_Attribute_realization->setName("realization");
	m_informationFlow_Attribute_realization->setEType(getRelationship_Class());
	m_informationFlow_Attribute_realization->setLowerBound(0);
	m_informationFlow_Attribute_realization->setUpperBound(-1);
	m_informationFlow_Attribute_realization->setTransient(false);
	m_informationFlow_Attribute_realization->setVolatile(false);
	m_informationFlow_Attribute_realization->setChangeable(true);
	m_informationFlow_Attribute_realization->setUnsettable(false);
	m_informationFlow_Attribute_realization->setUnique(true);
	m_informationFlow_Attribute_realization->setDerived(false);
	m_informationFlow_Attribute_realization->setOrdered(false);
	m_informationFlow_Attribute_realization->setContainment(false);
	m_informationFlow_Attribute_realization->setResolveProxies(true);
	m_informationFlow_Attribute_realization->setDefaultValueLiteral("");	
	
	m_informationFlow_Attribute_realization->_setID(INFORMATIONFLOW_ATTRIBUTE_REALIZATION);
	m_informationFlow_Attribute_realizingActivityEdge->setName("realizingActivityEdge");
	m_informationFlow_Attribute_realizingActivityEdge->setEType(getActivityEdge_Class());
	m_informationFlow_Attribute_realizingActivityEdge->setLowerBound(0);
	m_informationFlow_Attribute_realizingActivityEdge->setUpperBound(-1);
	m_informationFlow_Attribute_realizingActivityEdge->setTransient(false);
	m_informationFlow_Attribute_realizingActivityEdge->setVolatile(false);
	m_informationFlow_Attribute_realizingActivityEdge->setChangeable(true);
	m_informationFlow_Attribute_realizingActivityEdge->setUnsettable(false);
	m_informationFlow_Attribute_realizingActivityEdge->setUnique(true);
	m_informationFlow_Attribute_realizingActivityEdge->setDerived(false);
	m_informationFlow_Attribute_realizingActivityEdge->setOrdered(false);
	m_informationFlow_Attribute_realizingActivityEdge->setContainment(false);
	m_informationFlow_Attribute_realizingActivityEdge->setResolveProxies(true);
	m_informationFlow_Attribute_realizingActivityEdge->setDefaultValueLiteral("");	
	
	m_informationFlow_Attribute_realizingActivityEdge->_setID(INFORMATIONFLOW_ATTRIBUTE_REALIZINGACTIVITYEDGE);
	m_informationFlow_Attribute_realizingConnector->setName("realizingConnector");
	m_informationFlow_Attribute_realizingConnector->setEType(getConnector_Class());
	m_informationFlow_Attribute_realizingConnector->setLowerBound(0);
	m_informationFlow_Attribute_realizingConnector->setUpperBound(-1);
	m_informationFlow_Attribute_realizingConnector->setTransient(false);
	m_informationFlow_Attribute_realizingConnector->setVolatile(false);
	m_informationFlow_Attribute_realizingConnector->setChangeable(true);
	m_informationFlow_Attribute_realizingConnector->setUnsettable(false);
	m_informationFlow_Attribute_realizingConnector->setUnique(true);
	m_informationFlow_Attribute_realizingConnector->setDerived(false);
	m_informationFlow_Attribute_realizingConnector->setOrdered(false);
	m_informationFlow_Attribute_realizingConnector->setContainment(false);
	m_informationFlow_Attribute_realizingConnector->setResolveProxies(true);
	m_informationFlow_Attribute_realizingConnector->setDefaultValueLiteral("");	
	
	m_informationFlow_Attribute_realizingConnector->_setID(INFORMATIONFLOW_ATTRIBUTE_REALIZINGCONNECTOR);
	m_informationFlow_Attribute_realizingMessage->setName("realizingMessage");
	m_informationFlow_Attribute_realizingMessage->setEType(getMessage_Class());
	m_informationFlow_Attribute_realizingMessage->setLowerBound(0);
	m_informationFlow_Attribute_realizingMessage->setUpperBound(-1);
	m_informationFlow_Attribute_realizingMessage->setTransient(false);
	m_informationFlow_Attribute_realizingMessage->setVolatile(false);
	m_informationFlow_Attribute_realizingMessage->setChangeable(true);
	m_informationFlow_Attribute_realizingMessage->setUnsettable(false);
	m_informationFlow_Attribute_realizingMessage->setUnique(true);
	m_informationFlow_Attribute_realizingMessage->setDerived(false);
	m_informationFlow_Attribute_realizingMessage->setOrdered(false);
	m_informationFlow_Attribute_realizingMessage->setContainment(false);
	m_informationFlow_Attribute_realizingMessage->setResolveProxies(true);
	m_informationFlow_Attribute_realizingMessage->setDefaultValueLiteral("");	
	
	m_informationFlow_Attribute_realizingMessage->_setID(INFORMATIONFLOW_ATTRIBUTE_REALIZINGMESSAGE);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeInformationItemContent()
{
	m_informationItem_Class->setName("InformationItem");
	m_informationItem_Class->setAbstract(false);
	m_informationItem_Class->setInterface(false);
	
	m_informationItem_Class->_setID(INFORMATIONITEM_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_informationItem_Attribute_represented->setName("represented");
	m_informationItem_Attribute_represented->setEType(getClassifier_Class());
	m_informationItem_Attribute_represented->setLowerBound(0);
	m_informationItem_Attribute_represented->setUpperBound(-1);
	m_informationItem_Attribute_represented->setTransient(false);
	m_informationItem_Attribute_represented->setVolatile(false);
	m_informationItem_Attribute_represented->setChangeable(true);
	m_informationItem_Attribute_represented->setUnsettable(false);
	m_informationItem_Attribute_represented->setUnique(true);
	m_informationItem_Attribute_represented->setDerived(false);
	m_informationItem_Attribute_represented->setOrdered(false);
	m_informationItem_Attribute_represented->setContainment(false);
	m_informationItem_Attribute_represented->setResolveProxies(true);
	m_informationItem_Attribute_represented->setDefaultValueLiteral("");	
	
	m_informationItem_Attribute_represented->_setID(INFORMATIONITEM_ATTRIBUTE_REPRESENTED);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeInitialNodeContent()
{
	m_initialNode_Class->setName("InitialNode");
	m_initialNode_Class->setAbstract(false);
	m_initialNode_Class->setInterface(false);
	
	m_initialNode_Class->_setID(INITIALNODE_CLASS);
	
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

void umlPackageImpl::initializeInputPinContent()
{
	m_inputPin_Class->setName("InputPin");
	m_inputPin_Class->setAbstract(false);
	m_inputPin_Class->setInterface(false);
	
	m_inputPin_Class->_setID(INPUTPIN_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_inputPin_Attribute_action->setName("action");
	m_inputPin_Attribute_action->setEType(getAction_Class());
	m_inputPin_Attribute_action->setLowerBound(0);
	m_inputPin_Attribute_action->setUpperBound(1);
	m_inputPin_Attribute_action->setTransient(true);
	m_inputPin_Attribute_action->setVolatile(false);
	m_inputPin_Attribute_action->setChangeable(false);
	m_inputPin_Attribute_action->setUnsettable(false);
	m_inputPin_Attribute_action->setUnique(true);
	m_inputPin_Attribute_action->setDerived(true);
	m_inputPin_Attribute_action->setOrdered(true);
	m_inputPin_Attribute_action->setContainment(false);
	m_inputPin_Attribute_action->setResolveProxies(true);
	m_inputPin_Attribute_action->setDefaultValueLiteral("");	
	m_inputPin_Attribute_action->setEOpposite(uml::umlPackage::eInstance()->getAction_Attribute_input());
	
	m_inputPin_Attribute_action->_setID(INPUTPIN_ATTRIBUTE_ACTION);
	m_inputPin_Attribute_addStructuralFeatureValueAction->setName("addStructuralFeatureValueAction");
	m_inputPin_Attribute_addStructuralFeatureValueAction->setEType(getAddStructuralFeatureValueAction_Class());
	m_inputPin_Attribute_addStructuralFeatureValueAction->setLowerBound(0);
	m_inputPin_Attribute_addStructuralFeatureValueAction->setUpperBound(1);
	m_inputPin_Attribute_addStructuralFeatureValueAction->setTransient(false);
	m_inputPin_Attribute_addStructuralFeatureValueAction->setVolatile(false);
	m_inputPin_Attribute_addStructuralFeatureValueAction->setChangeable(true);
	m_inputPin_Attribute_addStructuralFeatureValueAction->setUnsettable(false);
	m_inputPin_Attribute_addStructuralFeatureValueAction->setUnique(true);
	m_inputPin_Attribute_addStructuralFeatureValueAction->setDerived(false);
	m_inputPin_Attribute_addStructuralFeatureValueAction->setOrdered(true);
	m_inputPin_Attribute_addStructuralFeatureValueAction->setContainment(false);
	m_inputPin_Attribute_addStructuralFeatureValueAction->setResolveProxies(true);
	m_inputPin_Attribute_addStructuralFeatureValueAction->setDefaultValueLiteral("");	
	m_inputPin_Attribute_addStructuralFeatureValueAction->setEOpposite(uml::umlPackage::eInstance()->getAddStructuralFeatureValueAction_Attribute_insertAt());
	
	m_inputPin_Attribute_addStructuralFeatureValueAction->_setID(INPUTPIN_ATTRIBUTE_ADDSTRUCTURALFEATUREVALUEACTION);
	m_inputPin_Attribute_callOperationAction->setName("callOperationAction");
	m_inputPin_Attribute_callOperationAction->setEType(getCallOperationAction_Class());
	m_inputPin_Attribute_callOperationAction->setLowerBound(0);
	m_inputPin_Attribute_callOperationAction->setUpperBound(1);
	m_inputPin_Attribute_callOperationAction->setTransient(false);
	m_inputPin_Attribute_callOperationAction->setVolatile(false);
	m_inputPin_Attribute_callOperationAction->setChangeable(true);
	m_inputPin_Attribute_callOperationAction->setUnsettable(false);
	m_inputPin_Attribute_callOperationAction->setUnique(true);
	m_inputPin_Attribute_callOperationAction->setDerived(false);
	m_inputPin_Attribute_callOperationAction->setOrdered(true);
	m_inputPin_Attribute_callOperationAction->setContainment(false);
	m_inputPin_Attribute_callOperationAction->setResolveProxies(true);
	m_inputPin_Attribute_callOperationAction->setDefaultValueLiteral("");	
	m_inputPin_Attribute_callOperationAction->setEOpposite(uml::umlPackage::eInstance()->getCallOperationAction_Attribute_target());
	
	m_inputPin_Attribute_callOperationAction->_setID(INPUTPIN_ATTRIBUTE_CALLOPERATIONACTION);
	m_inputPin_Attribute_destroyObjectAction->setName("destroyObjectAction");
	m_inputPin_Attribute_destroyObjectAction->setEType(getDestroyObjectAction_Class());
	m_inputPin_Attribute_destroyObjectAction->setLowerBound(0);
	m_inputPin_Attribute_destroyObjectAction->setUpperBound(1);
	m_inputPin_Attribute_destroyObjectAction->setTransient(false);
	m_inputPin_Attribute_destroyObjectAction->setVolatile(false);
	m_inputPin_Attribute_destroyObjectAction->setChangeable(true);
	m_inputPin_Attribute_destroyObjectAction->setUnsettable(false);
	m_inputPin_Attribute_destroyObjectAction->setUnique(true);
	m_inputPin_Attribute_destroyObjectAction->setDerived(false);
	m_inputPin_Attribute_destroyObjectAction->setOrdered(true);
	m_inputPin_Attribute_destroyObjectAction->setContainment(false);
	m_inputPin_Attribute_destroyObjectAction->setResolveProxies(true);
	m_inputPin_Attribute_destroyObjectAction->setDefaultValueLiteral("");	
	m_inputPin_Attribute_destroyObjectAction->setEOpposite(uml::umlPackage::eInstance()->getDestroyObjectAction_Attribute_target());
	
	m_inputPin_Attribute_destroyObjectAction->_setID(INPUTPIN_ATTRIBUTE_DESTROYOBJECTACTION);
	m_inputPin_Attribute_invocationAction->setName("invocationAction");
	m_inputPin_Attribute_invocationAction->setEType(getInvocationAction_Class());
	m_inputPin_Attribute_invocationAction->setLowerBound(0);
	m_inputPin_Attribute_invocationAction->setUpperBound(1);
	m_inputPin_Attribute_invocationAction->setTransient(false);
	m_inputPin_Attribute_invocationAction->setVolatile(false);
	m_inputPin_Attribute_invocationAction->setChangeable(true);
	m_inputPin_Attribute_invocationAction->setUnsettable(false);
	m_inputPin_Attribute_invocationAction->setUnique(true);
	m_inputPin_Attribute_invocationAction->setDerived(false);
	m_inputPin_Attribute_invocationAction->setOrdered(true);
	m_inputPin_Attribute_invocationAction->setContainment(false);
	m_inputPin_Attribute_invocationAction->setResolveProxies(true);
	m_inputPin_Attribute_invocationAction->setDefaultValueLiteral("");	
	m_inputPin_Attribute_invocationAction->setEOpposite(uml::umlPackage::eInstance()->getInvocationAction_Attribute_argument());
	
	m_inputPin_Attribute_invocationAction->_setID(INPUTPIN_ATTRIBUTE_INVOCATIONACTION);
	m_inputPin_Attribute_removeStructuralFeatureValueAction->setName("removeStructuralFeatureValueAction");
	m_inputPin_Attribute_removeStructuralFeatureValueAction->setEType(getRemoveStructuralFeatureValueAction_Class());
	m_inputPin_Attribute_removeStructuralFeatureValueAction->setLowerBound(0);
	m_inputPin_Attribute_removeStructuralFeatureValueAction->setUpperBound(1);
	m_inputPin_Attribute_removeStructuralFeatureValueAction->setTransient(false);
	m_inputPin_Attribute_removeStructuralFeatureValueAction->setVolatile(false);
	m_inputPin_Attribute_removeStructuralFeatureValueAction->setChangeable(true);
	m_inputPin_Attribute_removeStructuralFeatureValueAction->setUnsettable(false);
	m_inputPin_Attribute_removeStructuralFeatureValueAction->setUnique(true);
	m_inputPin_Attribute_removeStructuralFeatureValueAction->setDerived(false);
	m_inputPin_Attribute_removeStructuralFeatureValueAction->setOrdered(true);
	m_inputPin_Attribute_removeStructuralFeatureValueAction->setContainment(false);
	m_inputPin_Attribute_removeStructuralFeatureValueAction->setResolveProxies(true);
	m_inputPin_Attribute_removeStructuralFeatureValueAction->setDefaultValueLiteral("");	
	m_inputPin_Attribute_removeStructuralFeatureValueAction->setEOpposite(uml::umlPackage::eInstance()->getRemoveStructuralFeatureValueAction_Attribute_removeAt());
	
	m_inputPin_Attribute_removeStructuralFeatureValueAction->_setID(INPUTPIN_ATTRIBUTE_REMOVESTRUCTURALFEATUREVALUEACTION);
	m_inputPin_Attribute_structuralFeatureAction->setName("structuralFeatureAction");
	m_inputPin_Attribute_structuralFeatureAction->setEType(getStructuralFeatureAction_Class());
	m_inputPin_Attribute_structuralFeatureAction->setLowerBound(0);
	m_inputPin_Attribute_structuralFeatureAction->setUpperBound(1);
	m_inputPin_Attribute_structuralFeatureAction->setTransient(false);
	m_inputPin_Attribute_structuralFeatureAction->setVolatile(false);
	m_inputPin_Attribute_structuralFeatureAction->setChangeable(true);
	m_inputPin_Attribute_structuralFeatureAction->setUnsettable(false);
	m_inputPin_Attribute_structuralFeatureAction->setUnique(true);
	m_inputPin_Attribute_structuralFeatureAction->setDerived(false);
	m_inputPin_Attribute_structuralFeatureAction->setOrdered(true);
	m_inputPin_Attribute_structuralFeatureAction->setContainment(false);
	m_inputPin_Attribute_structuralFeatureAction->setResolveProxies(true);
	m_inputPin_Attribute_structuralFeatureAction->setDefaultValueLiteral("");	
	m_inputPin_Attribute_structuralFeatureAction->setEOpposite(uml::umlPackage::eInstance()->getStructuralFeatureAction_Attribute_object());
	
	m_inputPin_Attribute_structuralFeatureAction->_setID(INPUTPIN_ATTRIBUTE_STRUCTURALFEATUREACTION);
	m_inputPin_Attribute_writeStructuralFeatureAction->setName("writeStructuralFeatureAction");
	m_inputPin_Attribute_writeStructuralFeatureAction->setEType(getWriteStructuralFeatureAction_Class());
	m_inputPin_Attribute_writeStructuralFeatureAction->setLowerBound(0);
	m_inputPin_Attribute_writeStructuralFeatureAction->setUpperBound(1);
	m_inputPin_Attribute_writeStructuralFeatureAction->setTransient(false);
	m_inputPin_Attribute_writeStructuralFeatureAction->setVolatile(false);
	m_inputPin_Attribute_writeStructuralFeatureAction->setChangeable(true);
	m_inputPin_Attribute_writeStructuralFeatureAction->setUnsettable(false);
	m_inputPin_Attribute_writeStructuralFeatureAction->setUnique(true);
	m_inputPin_Attribute_writeStructuralFeatureAction->setDerived(false);
	m_inputPin_Attribute_writeStructuralFeatureAction->setOrdered(true);
	m_inputPin_Attribute_writeStructuralFeatureAction->setContainment(false);
	m_inputPin_Attribute_writeStructuralFeatureAction->setResolveProxies(true);
	m_inputPin_Attribute_writeStructuralFeatureAction->setDefaultValueLiteral("");	
	m_inputPin_Attribute_writeStructuralFeatureAction->setEOpposite(uml::umlPackage::eInstance()->getWriteStructuralFeatureAction_Attribute_value());
	
	m_inputPin_Attribute_writeStructuralFeatureAction->_setID(INPUTPIN_ATTRIBUTE_WRITESTRUCTURALFEATUREACTION);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeInstanceSpecificationContent()
{
	m_instanceSpecification_Class->setName("InstanceSpecification");
	m_instanceSpecification_Class->setAbstract(false);
	m_instanceSpecification_Class->setInterface(false);
	
	m_instanceSpecification_Class->_setID(INSTANCESPECIFICATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_instanceSpecification_Attribute_classifier->setName("classifier");
	m_instanceSpecification_Attribute_classifier->setEType(getClassifier_Class());
	m_instanceSpecification_Attribute_classifier->setLowerBound(0);
	m_instanceSpecification_Attribute_classifier->setUpperBound(-1);
	m_instanceSpecification_Attribute_classifier->setTransient(false);
	m_instanceSpecification_Attribute_classifier->setVolatile(false);
	m_instanceSpecification_Attribute_classifier->setChangeable(true);
	m_instanceSpecification_Attribute_classifier->setUnsettable(false);
	m_instanceSpecification_Attribute_classifier->setUnique(true);
	m_instanceSpecification_Attribute_classifier->setDerived(false);
	m_instanceSpecification_Attribute_classifier->setOrdered(false);
	m_instanceSpecification_Attribute_classifier->setContainment(false);
	m_instanceSpecification_Attribute_classifier->setResolveProxies(true);
	m_instanceSpecification_Attribute_classifier->setDefaultValueLiteral("");	
	
	m_instanceSpecification_Attribute_classifier->_setID(INSTANCESPECIFICATION_ATTRIBUTE_CLASSIFIER);
	m_instanceSpecification_Attribute_slot->setName("slot");
	m_instanceSpecification_Attribute_slot->setEType(getSlot_Class());
	m_instanceSpecification_Attribute_slot->setLowerBound(0);
	m_instanceSpecification_Attribute_slot->setUpperBound(-1);
	m_instanceSpecification_Attribute_slot->setTransient(false);
	m_instanceSpecification_Attribute_slot->setVolatile(false);
	m_instanceSpecification_Attribute_slot->setChangeable(true);
	m_instanceSpecification_Attribute_slot->setUnsettable(false);
	m_instanceSpecification_Attribute_slot->setUnique(true);
	m_instanceSpecification_Attribute_slot->setDerived(false);
	m_instanceSpecification_Attribute_slot->setOrdered(false);
	m_instanceSpecification_Attribute_slot->setContainment(true);
	m_instanceSpecification_Attribute_slot->setResolveProxies(true);
	m_instanceSpecification_Attribute_slot->setDefaultValueLiteral("");	
	m_instanceSpecification_Attribute_slot->setEOpposite(uml::umlPackage::eInstance()->getSlot_Attribute_owningInstance());
	
	m_instanceSpecification_Attribute_slot->_setID(INSTANCESPECIFICATION_ATTRIBUTE_SLOT);
	m_instanceSpecification_Attribute_specification->setName("specification");
	m_instanceSpecification_Attribute_specification->setEType(getValueSpecification_Class());
	m_instanceSpecification_Attribute_specification->setLowerBound(0);
	m_instanceSpecification_Attribute_specification->setUpperBound(1);
	m_instanceSpecification_Attribute_specification->setTransient(false);
	m_instanceSpecification_Attribute_specification->setVolatile(false);
	m_instanceSpecification_Attribute_specification->setChangeable(true);
	m_instanceSpecification_Attribute_specification->setUnsettable(false);
	m_instanceSpecification_Attribute_specification->setUnique(true);
	m_instanceSpecification_Attribute_specification->setDerived(false);
	m_instanceSpecification_Attribute_specification->setOrdered(false);
	m_instanceSpecification_Attribute_specification->setContainment(true);
	m_instanceSpecification_Attribute_specification->setResolveProxies(true);
	m_instanceSpecification_Attribute_specification->setDefaultValueLiteral("");	
	
	m_instanceSpecification_Attribute_specification->_setID(INSTANCESPECIFICATION_ATTRIBUTE_SPECIFICATION);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeInstanceValueContent()
{
	m_instanceValue_Class->setName("InstanceValue");
	m_instanceValue_Class->setAbstract(false);
	m_instanceValue_Class->setInterface(false);
	
	m_instanceValue_Class->_setID(INSTANCEVALUE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_instanceValue_Attribute_instance->setName("instance");
	m_instanceValue_Attribute_instance->setEType(getInstanceSpecification_Class());
	m_instanceValue_Attribute_instance->setLowerBound(1);
	m_instanceValue_Attribute_instance->setUpperBound(1);
	m_instanceValue_Attribute_instance->setTransient(false);
	m_instanceValue_Attribute_instance->setVolatile(false);
	m_instanceValue_Attribute_instance->setChangeable(true);
	m_instanceValue_Attribute_instance->setUnsettable(false);
	m_instanceValue_Attribute_instance->setUnique(true);
	m_instanceValue_Attribute_instance->setDerived(false);
	m_instanceValue_Attribute_instance->setOrdered(false);
	m_instanceValue_Attribute_instance->setContainment(false);
	m_instanceValue_Attribute_instance->setResolveProxies(true);
	m_instanceValue_Attribute_instance->setDefaultValueLiteral("");	
	
	m_instanceValue_Attribute_instance->_setID(INSTANCEVALUE_ATTRIBUTE_INSTANCE);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeInteractionContent()
{
	m_interaction_Class->setName("Interaction");
	m_interaction_Class->setAbstract(false);
	m_interaction_Class->setInterface(false);
	
	m_interaction_Class->_setID(INTERACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_interaction_Attribute_action->setName("action");
	m_interaction_Attribute_action->setEType(getAction_Class());
	m_interaction_Attribute_action->setLowerBound(0);
	m_interaction_Attribute_action->setUpperBound(-1);
	m_interaction_Attribute_action->setTransient(false);
	m_interaction_Attribute_action->setVolatile(false);
	m_interaction_Attribute_action->setChangeable(true);
	m_interaction_Attribute_action->setUnsettable(false);
	m_interaction_Attribute_action->setUnique(true);
	m_interaction_Attribute_action->setDerived(false);
	m_interaction_Attribute_action->setOrdered(false);
	m_interaction_Attribute_action->setContainment(true);
	m_interaction_Attribute_action->setResolveProxies(true);
	m_interaction_Attribute_action->setDefaultValueLiteral("");	
	
	m_interaction_Attribute_action->_setID(INTERACTION_ATTRIBUTE_ACTION);
	m_interaction_Attribute_formalGate->setName("formalGate");
	m_interaction_Attribute_formalGate->setEType(getGate_Class());
	m_interaction_Attribute_formalGate->setLowerBound(0);
	m_interaction_Attribute_formalGate->setUpperBound(-1);
	m_interaction_Attribute_formalGate->setTransient(false);
	m_interaction_Attribute_formalGate->setVolatile(false);
	m_interaction_Attribute_formalGate->setChangeable(true);
	m_interaction_Attribute_formalGate->setUnsettable(false);
	m_interaction_Attribute_formalGate->setUnique(true);
	m_interaction_Attribute_formalGate->setDerived(false);
	m_interaction_Attribute_formalGate->setOrdered(false);
	m_interaction_Attribute_formalGate->setContainment(true);
	m_interaction_Attribute_formalGate->setResolveProxies(true);
	m_interaction_Attribute_formalGate->setDefaultValueLiteral("");	
	
	m_interaction_Attribute_formalGate->_setID(INTERACTION_ATTRIBUTE_FORMALGATE);
	m_interaction_Attribute_fragment->setName("fragment");
	m_interaction_Attribute_fragment->setEType(getInteractionFragment_Class());
	m_interaction_Attribute_fragment->setLowerBound(0);
	m_interaction_Attribute_fragment->setUpperBound(-1);
	m_interaction_Attribute_fragment->setTransient(false);
	m_interaction_Attribute_fragment->setVolatile(false);
	m_interaction_Attribute_fragment->setChangeable(true);
	m_interaction_Attribute_fragment->setUnsettable(false);
	m_interaction_Attribute_fragment->setUnique(true);
	m_interaction_Attribute_fragment->setDerived(false);
	m_interaction_Attribute_fragment->setOrdered(true);
	m_interaction_Attribute_fragment->setContainment(true);
	m_interaction_Attribute_fragment->setResolveProxies(true);
	m_interaction_Attribute_fragment->setDefaultValueLiteral("");	
	m_interaction_Attribute_fragment->setEOpposite(uml::umlPackage::eInstance()->getInteractionFragment_Attribute_enclosingInteraction());
	
	m_interaction_Attribute_fragment->_setID(INTERACTION_ATTRIBUTE_FRAGMENT);
	m_interaction_Attribute_lifeline->setName("lifeline");
	m_interaction_Attribute_lifeline->setEType(getLifeline_Class());
	m_interaction_Attribute_lifeline->setLowerBound(0);
	m_interaction_Attribute_lifeline->setUpperBound(-1);
	m_interaction_Attribute_lifeline->setTransient(false);
	m_interaction_Attribute_lifeline->setVolatile(false);
	m_interaction_Attribute_lifeline->setChangeable(true);
	m_interaction_Attribute_lifeline->setUnsettable(false);
	m_interaction_Attribute_lifeline->setUnique(true);
	m_interaction_Attribute_lifeline->setDerived(false);
	m_interaction_Attribute_lifeline->setOrdered(false);
	m_interaction_Attribute_lifeline->setContainment(true);
	m_interaction_Attribute_lifeline->setResolveProxies(true);
	m_interaction_Attribute_lifeline->setDefaultValueLiteral("");	
	m_interaction_Attribute_lifeline->setEOpposite(uml::umlPackage::eInstance()->getLifeline_Attribute_interaction());
	
	m_interaction_Attribute_lifeline->_setID(INTERACTION_ATTRIBUTE_LIFELINE);
	m_interaction_Attribute_message->setName("message");
	m_interaction_Attribute_message->setEType(getMessage_Class());
	m_interaction_Attribute_message->setLowerBound(0);
	m_interaction_Attribute_message->setUpperBound(-1);
	m_interaction_Attribute_message->setTransient(false);
	m_interaction_Attribute_message->setVolatile(false);
	m_interaction_Attribute_message->setChangeable(true);
	m_interaction_Attribute_message->setUnsettable(false);
	m_interaction_Attribute_message->setUnique(true);
	m_interaction_Attribute_message->setDerived(false);
	m_interaction_Attribute_message->setOrdered(false);
	m_interaction_Attribute_message->setContainment(true);
	m_interaction_Attribute_message->setResolveProxies(true);
	m_interaction_Attribute_message->setDefaultValueLiteral("");	
	m_interaction_Attribute_message->setEOpposite(uml::umlPackage::eInstance()->getMessage_Attribute_interaction());
	
	m_interaction_Attribute_message->_setID(INTERACTION_ATTRIBUTE_MESSAGE);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeInteractionConstraintContent()
{
	m_interactionConstraint_Class->setName("InteractionConstraint");
	m_interactionConstraint_Class->setAbstract(false);
	m_interactionConstraint_Class->setInterface(false);
	
	m_interactionConstraint_Class->_setID(INTERACTIONCONSTRAINT_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_interactionConstraint_Attribute_maxint->setName("maxint");
	m_interactionConstraint_Attribute_maxint->setEType(getValueSpecification_Class());
	m_interactionConstraint_Attribute_maxint->setLowerBound(0);
	m_interactionConstraint_Attribute_maxint->setUpperBound(1);
	m_interactionConstraint_Attribute_maxint->setTransient(false);
	m_interactionConstraint_Attribute_maxint->setVolatile(false);
	m_interactionConstraint_Attribute_maxint->setChangeable(true);
	m_interactionConstraint_Attribute_maxint->setUnsettable(false);
	m_interactionConstraint_Attribute_maxint->setUnique(true);
	m_interactionConstraint_Attribute_maxint->setDerived(false);
	m_interactionConstraint_Attribute_maxint->setOrdered(false);
	m_interactionConstraint_Attribute_maxint->setContainment(true);
	m_interactionConstraint_Attribute_maxint->setResolveProxies(true);
	m_interactionConstraint_Attribute_maxint->setDefaultValueLiteral("");	
	
	m_interactionConstraint_Attribute_maxint->_setID(INTERACTIONCONSTRAINT_ATTRIBUTE_MAXINT);
	m_interactionConstraint_Attribute_minint->setName("minint");
	m_interactionConstraint_Attribute_minint->setEType(getValueSpecification_Class());
	m_interactionConstraint_Attribute_minint->setLowerBound(0);
	m_interactionConstraint_Attribute_minint->setUpperBound(1);
	m_interactionConstraint_Attribute_minint->setTransient(false);
	m_interactionConstraint_Attribute_minint->setVolatile(false);
	m_interactionConstraint_Attribute_minint->setChangeable(true);
	m_interactionConstraint_Attribute_minint->setUnsettable(false);
	m_interactionConstraint_Attribute_minint->setUnique(true);
	m_interactionConstraint_Attribute_minint->setDerived(false);
	m_interactionConstraint_Attribute_minint->setOrdered(false);
	m_interactionConstraint_Attribute_minint->setContainment(true);
	m_interactionConstraint_Attribute_minint->setResolveProxies(true);
	m_interactionConstraint_Attribute_minint->setDefaultValueLiteral("");	
	
	m_interactionConstraint_Attribute_minint->_setID(INTERACTIONCONSTRAINT_ATTRIBUTE_MININT);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeInteractionFragmentContent()
{
	m_interactionFragment_Class->setName("InteractionFragment");
	m_interactionFragment_Class->setAbstract(true);
	m_interactionFragment_Class->setInterface(false);
	
	m_interactionFragment_Class->_setID(INTERACTIONFRAGMENT_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_interactionFragment_Attribute_covered->setName("covered");
	m_interactionFragment_Attribute_covered->setEType(getLifeline_Class());
	m_interactionFragment_Attribute_covered->setLowerBound(0);
	m_interactionFragment_Attribute_covered->setUpperBound(-1);
	m_interactionFragment_Attribute_covered->setTransient(false);
	m_interactionFragment_Attribute_covered->setVolatile(false);
	m_interactionFragment_Attribute_covered->setChangeable(true);
	m_interactionFragment_Attribute_covered->setUnsettable(false);
	m_interactionFragment_Attribute_covered->setUnique(true);
	m_interactionFragment_Attribute_covered->setDerived(false);
	m_interactionFragment_Attribute_covered->setOrdered(false);
	m_interactionFragment_Attribute_covered->setContainment(false);
	m_interactionFragment_Attribute_covered->setResolveProxies(true);
	m_interactionFragment_Attribute_covered->setDefaultValueLiteral("");	
	m_interactionFragment_Attribute_covered->setEOpposite(uml::umlPackage::eInstance()->getLifeline_Attribute_coveredBy());
	
	m_interactionFragment_Attribute_covered->_setID(INTERACTIONFRAGMENT_ATTRIBUTE_COVERED);
	m_interactionFragment_Attribute_enclosingInteraction->setName("enclosingInteraction");
	m_interactionFragment_Attribute_enclosingInteraction->setEType(getInteraction_Class());
	m_interactionFragment_Attribute_enclosingInteraction->setLowerBound(0);
	m_interactionFragment_Attribute_enclosingInteraction->setUpperBound(1);
	m_interactionFragment_Attribute_enclosingInteraction->setTransient(false);
	m_interactionFragment_Attribute_enclosingInteraction->setVolatile(false);
	m_interactionFragment_Attribute_enclosingInteraction->setChangeable(true);
	m_interactionFragment_Attribute_enclosingInteraction->setUnsettable(false);
	m_interactionFragment_Attribute_enclosingInteraction->setUnique(true);
	m_interactionFragment_Attribute_enclosingInteraction->setDerived(false);
	m_interactionFragment_Attribute_enclosingInteraction->setOrdered(false);
	m_interactionFragment_Attribute_enclosingInteraction->setContainment(false);
	m_interactionFragment_Attribute_enclosingInteraction->setResolveProxies(true);
	m_interactionFragment_Attribute_enclosingInteraction->setDefaultValueLiteral("");	
	m_interactionFragment_Attribute_enclosingInteraction->setEOpposite(uml::umlPackage::eInstance()->getInteraction_Attribute_fragment());
	
	m_interactionFragment_Attribute_enclosingInteraction->_setID(INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGINTERACTION);
	m_interactionFragment_Attribute_enclosingOperand->setName("enclosingOperand");
	m_interactionFragment_Attribute_enclosingOperand->setEType(getInteractionOperand_Class());
	m_interactionFragment_Attribute_enclosingOperand->setLowerBound(0);
	m_interactionFragment_Attribute_enclosingOperand->setUpperBound(1);
	m_interactionFragment_Attribute_enclosingOperand->setTransient(false);
	m_interactionFragment_Attribute_enclosingOperand->setVolatile(false);
	m_interactionFragment_Attribute_enclosingOperand->setChangeable(true);
	m_interactionFragment_Attribute_enclosingOperand->setUnsettable(false);
	m_interactionFragment_Attribute_enclosingOperand->setUnique(true);
	m_interactionFragment_Attribute_enclosingOperand->setDerived(false);
	m_interactionFragment_Attribute_enclosingOperand->setOrdered(false);
	m_interactionFragment_Attribute_enclosingOperand->setContainment(false);
	m_interactionFragment_Attribute_enclosingOperand->setResolveProxies(true);
	m_interactionFragment_Attribute_enclosingOperand->setDefaultValueLiteral("");	
	m_interactionFragment_Attribute_enclosingOperand->setEOpposite(uml::umlPackage::eInstance()->getInteractionOperand_Attribute_fragment());
	
	m_interactionFragment_Attribute_enclosingOperand->_setID(INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGOPERAND);
	m_interactionFragment_Attribute_generalOrdering->setName("generalOrdering");
	m_interactionFragment_Attribute_generalOrdering->setEType(getGeneralOrdering_Class());
	m_interactionFragment_Attribute_generalOrdering->setLowerBound(0);
	m_interactionFragment_Attribute_generalOrdering->setUpperBound(-1);
	m_interactionFragment_Attribute_generalOrdering->setTransient(false);
	m_interactionFragment_Attribute_generalOrdering->setVolatile(false);
	m_interactionFragment_Attribute_generalOrdering->setChangeable(true);
	m_interactionFragment_Attribute_generalOrdering->setUnsettable(false);
	m_interactionFragment_Attribute_generalOrdering->setUnique(true);
	m_interactionFragment_Attribute_generalOrdering->setDerived(false);
	m_interactionFragment_Attribute_generalOrdering->setOrdered(false);
	m_interactionFragment_Attribute_generalOrdering->setContainment(true);
	m_interactionFragment_Attribute_generalOrdering->setResolveProxies(true);
	m_interactionFragment_Attribute_generalOrdering->setDefaultValueLiteral("");	
	
	m_interactionFragment_Attribute_generalOrdering->_setID(INTERACTIONFRAGMENT_ATTRIBUTE_GENERALORDERING);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeInteractionOperandContent()
{
	m_interactionOperand_Class->setName("InteractionOperand");
	m_interactionOperand_Class->setAbstract(false);
	m_interactionOperand_Class->setInterface(false);
	
	m_interactionOperand_Class->_setID(INTERACTIONOPERAND_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_interactionOperand_Attribute_fragment->setName("fragment");
	m_interactionOperand_Attribute_fragment->setEType(getInteractionFragment_Class());
	m_interactionOperand_Attribute_fragment->setLowerBound(0);
	m_interactionOperand_Attribute_fragment->setUpperBound(-1);
	m_interactionOperand_Attribute_fragment->setTransient(false);
	m_interactionOperand_Attribute_fragment->setVolatile(false);
	m_interactionOperand_Attribute_fragment->setChangeable(true);
	m_interactionOperand_Attribute_fragment->setUnsettable(false);
	m_interactionOperand_Attribute_fragment->setUnique(true);
	m_interactionOperand_Attribute_fragment->setDerived(false);
	m_interactionOperand_Attribute_fragment->setOrdered(true);
	m_interactionOperand_Attribute_fragment->setContainment(true);
	m_interactionOperand_Attribute_fragment->setResolveProxies(true);
	m_interactionOperand_Attribute_fragment->setDefaultValueLiteral("");	
	m_interactionOperand_Attribute_fragment->setEOpposite(uml::umlPackage::eInstance()->getInteractionFragment_Attribute_enclosingOperand());
	
	m_interactionOperand_Attribute_fragment->_setID(INTERACTIONOPERAND_ATTRIBUTE_FRAGMENT);
	m_interactionOperand_Attribute_guard->setName("guard");
	m_interactionOperand_Attribute_guard->setEType(getInteractionConstraint_Class());
	m_interactionOperand_Attribute_guard->setLowerBound(0);
	m_interactionOperand_Attribute_guard->setUpperBound(1);
	m_interactionOperand_Attribute_guard->setTransient(false);
	m_interactionOperand_Attribute_guard->setVolatile(false);
	m_interactionOperand_Attribute_guard->setChangeable(true);
	m_interactionOperand_Attribute_guard->setUnsettable(false);
	m_interactionOperand_Attribute_guard->setUnique(true);
	m_interactionOperand_Attribute_guard->setDerived(false);
	m_interactionOperand_Attribute_guard->setOrdered(false);
	m_interactionOperand_Attribute_guard->setContainment(true);
	m_interactionOperand_Attribute_guard->setResolveProxies(true);
	m_interactionOperand_Attribute_guard->setDefaultValueLiteral("");	
	
	m_interactionOperand_Attribute_guard->_setID(INTERACTIONOPERAND_ATTRIBUTE_GUARD);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeInteractionUseContent()
{
	m_interactionUse_Class->setName("InteractionUse");
	m_interactionUse_Class->setAbstract(false);
	m_interactionUse_Class->setInterface(false);
	
	m_interactionUse_Class->_setID(INTERACTIONUSE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_interactionUse_Attribute_actualGate->setName("actualGate");
	m_interactionUse_Attribute_actualGate->setEType(getGate_Class());
	m_interactionUse_Attribute_actualGate->setLowerBound(0);
	m_interactionUse_Attribute_actualGate->setUpperBound(-1);
	m_interactionUse_Attribute_actualGate->setTransient(false);
	m_interactionUse_Attribute_actualGate->setVolatile(false);
	m_interactionUse_Attribute_actualGate->setChangeable(true);
	m_interactionUse_Attribute_actualGate->setUnsettable(false);
	m_interactionUse_Attribute_actualGate->setUnique(true);
	m_interactionUse_Attribute_actualGate->setDerived(false);
	m_interactionUse_Attribute_actualGate->setOrdered(false);
	m_interactionUse_Attribute_actualGate->setContainment(true);
	m_interactionUse_Attribute_actualGate->setResolveProxies(true);
	m_interactionUse_Attribute_actualGate->setDefaultValueLiteral("");	
	
	m_interactionUse_Attribute_actualGate->_setID(INTERACTIONUSE_ATTRIBUTE_ACTUALGATE);
	m_interactionUse_Attribute_argument->setName("argument");
	m_interactionUse_Attribute_argument->setEType(getValueSpecification_Class());
	m_interactionUse_Attribute_argument->setLowerBound(0);
	m_interactionUse_Attribute_argument->setUpperBound(-1);
	m_interactionUse_Attribute_argument->setTransient(false);
	m_interactionUse_Attribute_argument->setVolatile(false);
	m_interactionUse_Attribute_argument->setChangeable(true);
	m_interactionUse_Attribute_argument->setUnsettable(false);
	m_interactionUse_Attribute_argument->setUnique(true);
	m_interactionUse_Attribute_argument->setDerived(false);
	m_interactionUse_Attribute_argument->setOrdered(true);
	m_interactionUse_Attribute_argument->setContainment(true);
	m_interactionUse_Attribute_argument->setResolveProxies(true);
	m_interactionUse_Attribute_argument->setDefaultValueLiteral("");	
	
	m_interactionUse_Attribute_argument->_setID(INTERACTIONUSE_ATTRIBUTE_ARGUMENT);
	m_interactionUse_Attribute_refersTo->setName("refersTo");
	m_interactionUse_Attribute_refersTo->setEType(getInteraction_Class());
	m_interactionUse_Attribute_refersTo->setLowerBound(1);
	m_interactionUse_Attribute_refersTo->setUpperBound(1);
	m_interactionUse_Attribute_refersTo->setTransient(false);
	m_interactionUse_Attribute_refersTo->setVolatile(false);
	m_interactionUse_Attribute_refersTo->setChangeable(true);
	m_interactionUse_Attribute_refersTo->setUnsettable(false);
	m_interactionUse_Attribute_refersTo->setUnique(true);
	m_interactionUse_Attribute_refersTo->setDerived(false);
	m_interactionUse_Attribute_refersTo->setOrdered(false);
	m_interactionUse_Attribute_refersTo->setContainment(false);
	m_interactionUse_Attribute_refersTo->setResolveProxies(true);
	m_interactionUse_Attribute_refersTo->setDefaultValueLiteral("");	
	
	m_interactionUse_Attribute_refersTo->_setID(INTERACTIONUSE_ATTRIBUTE_REFERSTO);
	m_interactionUse_Attribute_returnValue->setName("returnValue");
	m_interactionUse_Attribute_returnValue->setEType(getValueSpecification_Class());
	m_interactionUse_Attribute_returnValue->setLowerBound(0);
	m_interactionUse_Attribute_returnValue->setUpperBound(1);
	m_interactionUse_Attribute_returnValue->setTransient(false);
	m_interactionUse_Attribute_returnValue->setVolatile(false);
	m_interactionUse_Attribute_returnValue->setChangeable(true);
	m_interactionUse_Attribute_returnValue->setUnsettable(false);
	m_interactionUse_Attribute_returnValue->setUnique(true);
	m_interactionUse_Attribute_returnValue->setDerived(false);
	m_interactionUse_Attribute_returnValue->setOrdered(false);
	m_interactionUse_Attribute_returnValue->setContainment(true);
	m_interactionUse_Attribute_returnValue->setResolveProxies(true);
	m_interactionUse_Attribute_returnValue->setDefaultValueLiteral("");	
	
	m_interactionUse_Attribute_returnValue->_setID(INTERACTIONUSE_ATTRIBUTE_RETURNVALUE);
	m_interactionUse_Attribute_returnValueRecipient->setName("returnValueRecipient");
	m_interactionUse_Attribute_returnValueRecipient->setEType(getProperty_Class());
	m_interactionUse_Attribute_returnValueRecipient->setLowerBound(0);
	m_interactionUse_Attribute_returnValueRecipient->setUpperBound(1);
	m_interactionUse_Attribute_returnValueRecipient->setTransient(false);
	m_interactionUse_Attribute_returnValueRecipient->setVolatile(false);
	m_interactionUse_Attribute_returnValueRecipient->setChangeable(true);
	m_interactionUse_Attribute_returnValueRecipient->setUnsettable(false);
	m_interactionUse_Attribute_returnValueRecipient->setUnique(true);
	m_interactionUse_Attribute_returnValueRecipient->setDerived(false);
	m_interactionUse_Attribute_returnValueRecipient->setOrdered(false);
	m_interactionUse_Attribute_returnValueRecipient->setContainment(false);
	m_interactionUse_Attribute_returnValueRecipient->setResolveProxies(true);
	m_interactionUse_Attribute_returnValueRecipient->setDefaultValueLiteral("");	
	
	m_interactionUse_Attribute_returnValueRecipient->_setID(INTERACTIONUSE_ATTRIBUTE_RETURNVALUERECIPIENT);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeInterfaceContent()
{
	m_interface_Class->setName("Interface");
	m_interface_Class->setAbstract(false);
	m_interface_Class->setInterface(false);
	
	m_interface_Class->_setID(INTERFACE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_interface_Attribute_nestedClassifier->setName("nestedClassifier");
	m_interface_Attribute_nestedClassifier->setEType(getClassifier_Class());
	m_interface_Attribute_nestedClassifier->setLowerBound(0);
	m_interface_Attribute_nestedClassifier->setUpperBound(-1);
	m_interface_Attribute_nestedClassifier->setTransient(false);
	m_interface_Attribute_nestedClassifier->setVolatile(false);
	m_interface_Attribute_nestedClassifier->setChangeable(true);
	m_interface_Attribute_nestedClassifier->setUnsettable(false);
	m_interface_Attribute_nestedClassifier->setUnique(true);
	m_interface_Attribute_nestedClassifier->setDerived(false);
	m_interface_Attribute_nestedClassifier->setOrdered(true);
	m_interface_Attribute_nestedClassifier->setContainment(true);
	m_interface_Attribute_nestedClassifier->setResolveProxies(true);
	m_interface_Attribute_nestedClassifier->setDefaultValueLiteral("");	
	
	m_interface_Attribute_nestedClassifier->_setID(INTERFACE_ATTRIBUTE_NESTEDCLASSIFIER);
	m_interface_Attribute_ownedAttribute->setName("ownedAttribute");
	m_interface_Attribute_ownedAttribute->setEType(getProperty_Class());
	m_interface_Attribute_ownedAttribute->setLowerBound(0);
	m_interface_Attribute_ownedAttribute->setUpperBound(-1);
	m_interface_Attribute_ownedAttribute->setTransient(false);
	m_interface_Attribute_ownedAttribute->setVolatile(false);
	m_interface_Attribute_ownedAttribute->setChangeable(true);
	m_interface_Attribute_ownedAttribute->setUnsettable(false);
	m_interface_Attribute_ownedAttribute->setUnique(true);
	m_interface_Attribute_ownedAttribute->setDerived(false);
	m_interface_Attribute_ownedAttribute->setOrdered(true);
	m_interface_Attribute_ownedAttribute->setContainment(true);
	m_interface_Attribute_ownedAttribute->setResolveProxies(true);
	m_interface_Attribute_ownedAttribute->setDefaultValueLiteral("");	
	m_interface_Attribute_ownedAttribute->setEOpposite(uml::umlPackage::eInstance()->getProperty_Attribute_interface());
	
	m_interface_Attribute_ownedAttribute->_setID(INTERFACE_ATTRIBUTE_OWNEDATTRIBUTE);
	m_interface_Attribute_ownedOperation->setName("ownedOperation");
	m_interface_Attribute_ownedOperation->setEType(getOperation_Class());
	m_interface_Attribute_ownedOperation->setLowerBound(0);
	m_interface_Attribute_ownedOperation->setUpperBound(-1);
	m_interface_Attribute_ownedOperation->setTransient(false);
	m_interface_Attribute_ownedOperation->setVolatile(false);
	m_interface_Attribute_ownedOperation->setChangeable(true);
	m_interface_Attribute_ownedOperation->setUnsettable(false);
	m_interface_Attribute_ownedOperation->setUnique(true);
	m_interface_Attribute_ownedOperation->setDerived(false);
	m_interface_Attribute_ownedOperation->setOrdered(true);
	m_interface_Attribute_ownedOperation->setContainment(true);
	m_interface_Attribute_ownedOperation->setResolveProxies(true);
	m_interface_Attribute_ownedOperation->setDefaultValueLiteral("");	
	m_interface_Attribute_ownedOperation->setEOpposite(uml::umlPackage::eInstance()->getOperation_Attribute_interface());
	
	m_interface_Attribute_ownedOperation->_setID(INTERFACE_ATTRIBUTE_OWNEDOPERATION);
	m_interface_Attribute_ownedReception->setName("ownedReception");
	m_interface_Attribute_ownedReception->setEType(getReception_Class());
	m_interface_Attribute_ownedReception->setLowerBound(0);
	m_interface_Attribute_ownedReception->setUpperBound(-1);
	m_interface_Attribute_ownedReception->setTransient(false);
	m_interface_Attribute_ownedReception->setVolatile(false);
	m_interface_Attribute_ownedReception->setChangeable(true);
	m_interface_Attribute_ownedReception->setUnsettable(false);
	m_interface_Attribute_ownedReception->setUnique(true);
	m_interface_Attribute_ownedReception->setDerived(false);
	m_interface_Attribute_ownedReception->setOrdered(false);
	m_interface_Attribute_ownedReception->setContainment(true);
	m_interface_Attribute_ownedReception->setResolveProxies(true);
	m_interface_Attribute_ownedReception->setDefaultValueLiteral("");	
	
	m_interface_Attribute_ownedReception->_setID(INTERFACE_ATTRIBUTE_OWNEDRECEPTION);
	m_interface_Attribute_protocol->setName("protocol");
	m_interface_Attribute_protocol->setEType(getProtocolStateMachine_Class());
	m_interface_Attribute_protocol->setLowerBound(0);
	m_interface_Attribute_protocol->setUpperBound(1);
	m_interface_Attribute_protocol->setTransient(false);
	m_interface_Attribute_protocol->setVolatile(false);
	m_interface_Attribute_protocol->setChangeable(true);
	m_interface_Attribute_protocol->setUnsettable(false);
	m_interface_Attribute_protocol->setUnique(true);
	m_interface_Attribute_protocol->setDerived(false);
	m_interface_Attribute_protocol->setOrdered(false);
	m_interface_Attribute_protocol->setContainment(true);
	m_interface_Attribute_protocol->setResolveProxies(true);
	m_interface_Attribute_protocol->setDefaultValueLiteral("");	
	
	m_interface_Attribute_protocol->_setID(INTERFACE_ATTRIBUTE_PROTOCOL);
	m_interface_Attribute_redefinedInterface->setName("redefinedInterface");
	m_interface_Attribute_redefinedInterface->setEType(getInterface_Class());
	m_interface_Attribute_redefinedInterface->setLowerBound(0);
	m_interface_Attribute_redefinedInterface->setUpperBound(-1);
	m_interface_Attribute_redefinedInterface->setTransient(false);
	m_interface_Attribute_redefinedInterface->setVolatile(false);
	m_interface_Attribute_redefinedInterface->setChangeable(true);
	m_interface_Attribute_redefinedInterface->setUnsettable(false);
	m_interface_Attribute_redefinedInterface->setUnique(true);
	m_interface_Attribute_redefinedInterface->setDerived(false);
	m_interface_Attribute_redefinedInterface->setOrdered(false);
	m_interface_Attribute_redefinedInterface->setContainment(false);
	m_interface_Attribute_redefinedInterface->setResolveProxies(true);
	m_interface_Attribute_redefinedInterface->setDefaultValueLiteral("");	
	
	m_interface_Attribute_redefinedInterface->_setID(INTERFACE_ATTRIBUTE_REDEFINEDINTERFACE);
	
	/*
	 * EOperations
	 */
	m_interface_Operation_createOwnedAttribute_String_UnlimitedNatural->setName("createOwnedAttribute");
	m_interface_Operation_createOwnedAttribute_String_UnlimitedNatural->setEType(getProperty_Class());
	m_interface_Operation_createOwnedAttribute_String_UnlimitedNatural->setLowerBound(1);
	m_interface_Operation_createOwnedAttribute_String_UnlimitedNatural->setUpperBound(1);
	m_interface_Operation_createOwnedAttribute_String_UnlimitedNatural->setUnique(true);
	m_interface_Operation_createOwnedAttribute_String_UnlimitedNatural->setOrdered(false);
	
	m_interface_Operation_createOwnedAttribute_String_UnlimitedNatural->_setID(INTERFACE_OPERATION_CREATEOWNEDATTRIBUTE_STRING_UNLIMITEDNATURAL);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_interface_Operation_createOwnedAttribute_String_UnlimitedNatural);
		parameter->setName("name");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_interface_Operation_createOwnedAttribute_String_UnlimitedNatural);
		parameter->setName("type");
		parameter->setEType(getType_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_interface_Operation_createOwnedAttribute_String_UnlimitedNatural);
		parameter->setName("lower");
		parameter->setEType(types::typesPackage::eInstance()->getInteger_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_interface_Operation_createOwnedAttribute_String_UnlimitedNatural);
		parameter->setName("upper");
		parameter->setEType(types::typesPackage::eInstance()->getUnlimitedNatural_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_interface_Operation_createOwnedOperation_String_Type->setName("createOwnedOperation");
	m_interface_Operation_createOwnedOperation_String_Type->setEType(getOperation_Class());
	m_interface_Operation_createOwnedOperation_String_Type->setLowerBound(1);
	m_interface_Operation_createOwnedOperation_String_Type->setUpperBound(1);
	m_interface_Operation_createOwnedOperation_String_Type->setUnique(true);
	m_interface_Operation_createOwnedOperation_String_Type->setOrdered(false);
	
	m_interface_Operation_createOwnedOperation_String_Type->_setID(INTERFACE_OPERATION_CREATEOWNEDOPERATION_STRING_TYPE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_interface_Operation_createOwnedOperation_String_Type);
		parameter->setName("name");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_interface_Operation_createOwnedOperation_String_Type);
		parameter->setName("parameterNames");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_interface_Operation_createOwnedOperation_String_Type);
		parameter->setName("parameterTypes");
		parameter->setEType(getType_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_interface_Operation_createOwnedOperation_String_Type);
		parameter->setName("returnType");
		parameter->setEType(getType_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void umlPackageImpl::initializeInterfaceRealizationContent()
{
	m_interfaceRealization_Class->setName("InterfaceRealization");
	m_interfaceRealization_Class->setAbstract(false);
	m_interfaceRealization_Class->setInterface(false);
	
	m_interfaceRealization_Class->_setID(INTERFACEREALIZATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_interfaceRealization_Attribute_contract->setName("contract");
	m_interfaceRealization_Attribute_contract->setEType(getInterface_Class());
	m_interfaceRealization_Attribute_contract->setLowerBound(1);
	m_interfaceRealization_Attribute_contract->setUpperBound(1);
	m_interfaceRealization_Attribute_contract->setTransient(false);
	m_interfaceRealization_Attribute_contract->setVolatile(false);
	m_interfaceRealization_Attribute_contract->setChangeable(true);
	m_interfaceRealization_Attribute_contract->setUnsettable(false);
	m_interfaceRealization_Attribute_contract->setUnique(true);
	m_interfaceRealization_Attribute_contract->setDerived(false);
	m_interfaceRealization_Attribute_contract->setOrdered(false);
	m_interfaceRealization_Attribute_contract->setContainment(false);
	m_interfaceRealization_Attribute_contract->setResolveProxies(true);
	m_interfaceRealization_Attribute_contract->setDefaultValueLiteral("");	
	
	m_interfaceRealization_Attribute_contract->_setID(INTERFACEREALIZATION_ATTRIBUTE_CONTRACT);
	m_interfaceRealization_Attribute_implementingClassifier->setName("implementingClassifier");
	m_interfaceRealization_Attribute_implementingClassifier->setEType(getBehavioredClassifier_Class());
	m_interfaceRealization_Attribute_implementingClassifier->setLowerBound(1);
	m_interfaceRealization_Attribute_implementingClassifier->setUpperBound(1);
	m_interfaceRealization_Attribute_implementingClassifier->setTransient(false);
	m_interfaceRealization_Attribute_implementingClassifier->setVolatile(false);
	m_interfaceRealization_Attribute_implementingClassifier->setChangeable(true);
	m_interfaceRealization_Attribute_implementingClassifier->setUnsettable(false);
	m_interfaceRealization_Attribute_implementingClassifier->setUnique(true);
	m_interfaceRealization_Attribute_implementingClassifier->setDerived(false);
	m_interfaceRealization_Attribute_implementingClassifier->setOrdered(false);
	m_interfaceRealization_Attribute_implementingClassifier->setContainment(false);
	m_interfaceRealization_Attribute_implementingClassifier->setResolveProxies(true);
	m_interfaceRealization_Attribute_implementingClassifier->setDefaultValueLiteral("");	
	m_interfaceRealization_Attribute_implementingClassifier->setEOpposite(uml::umlPackage::eInstance()->getBehavioredClassifier_Attribute_interfaceRealization());
	
	m_interfaceRealization_Attribute_implementingClassifier->_setID(INTERFACEREALIZATION_ATTRIBUTE_IMPLEMENTINGCLASSIFIER);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeInterruptibleActivityRegionContent()
{
	m_interruptibleActivityRegion_Class->setName("InterruptibleActivityRegion");
	m_interruptibleActivityRegion_Class->setAbstract(false);
	m_interruptibleActivityRegion_Class->setInterface(false);
	
	m_interruptibleActivityRegion_Class->_setID(INTERRUPTIBLEACTIVITYREGION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_interruptibleActivityRegion_Attribute_interruptingEdge->setName("interruptingEdge");
	m_interruptibleActivityRegion_Attribute_interruptingEdge->setEType(getActivityEdge_Class());
	m_interruptibleActivityRegion_Attribute_interruptingEdge->setLowerBound(0);
	m_interruptibleActivityRegion_Attribute_interruptingEdge->setUpperBound(-1);
	m_interruptibleActivityRegion_Attribute_interruptingEdge->setTransient(false);
	m_interruptibleActivityRegion_Attribute_interruptingEdge->setVolatile(false);
	m_interruptibleActivityRegion_Attribute_interruptingEdge->setChangeable(true);
	m_interruptibleActivityRegion_Attribute_interruptingEdge->setUnsettable(false);
	m_interruptibleActivityRegion_Attribute_interruptingEdge->setUnique(true);
	m_interruptibleActivityRegion_Attribute_interruptingEdge->setDerived(false);
	m_interruptibleActivityRegion_Attribute_interruptingEdge->setOrdered(false);
	m_interruptibleActivityRegion_Attribute_interruptingEdge->setContainment(false);
	m_interruptibleActivityRegion_Attribute_interruptingEdge->setResolveProxies(true);
	m_interruptibleActivityRegion_Attribute_interruptingEdge->setDefaultValueLiteral("");	
	m_interruptibleActivityRegion_Attribute_interruptingEdge->setEOpposite(uml::umlPackage::eInstance()->getActivityEdge_Attribute_interrupts());
	
	m_interruptibleActivityRegion_Attribute_interruptingEdge->_setID(INTERRUPTIBLEACTIVITYREGION_ATTRIBUTE_INTERRUPTINGEDGE);
	m_interruptibleActivityRegion_Attribute_node->setName("node");
	m_interruptibleActivityRegion_Attribute_node->setEType(getActivityNode_Class());
	m_interruptibleActivityRegion_Attribute_node->setLowerBound(0);
	m_interruptibleActivityRegion_Attribute_node->setUpperBound(-1);
	m_interruptibleActivityRegion_Attribute_node->setTransient(false);
	m_interruptibleActivityRegion_Attribute_node->setVolatile(false);
	m_interruptibleActivityRegion_Attribute_node->setChangeable(true);
	m_interruptibleActivityRegion_Attribute_node->setUnsettable(false);
	m_interruptibleActivityRegion_Attribute_node->setUnique(true);
	m_interruptibleActivityRegion_Attribute_node->setDerived(false);
	m_interruptibleActivityRegion_Attribute_node->setOrdered(false);
	m_interruptibleActivityRegion_Attribute_node->setContainment(false);
	m_interruptibleActivityRegion_Attribute_node->setResolveProxies(true);
	m_interruptibleActivityRegion_Attribute_node->setDefaultValueLiteral("");	
	m_interruptibleActivityRegion_Attribute_node->setEOpposite(uml::umlPackage::eInstance()->getActivityNode_Attribute_inInterruptibleRegion());
	
	m_interruptibleActivityRegion_Attribute_node->_setID(INTERRUPTIBLEACTIVITYREGION_ATTRIBUTE_NODE);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeIntervalContent()
{
	m_interval_Class->setName("Interval");
	m_interval_Class->setAbstract(false);
	m_interval_Class->setInterface(false);
	
	m_interval_Class->_setID(INTERVAL_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_interval_Attribute_max->setName("max");
	m_interval_Attribute_max->setEType(getValueSpecification_Class());
	m_interval_Attribute_max->setLowerBound(1);
	m_interval_Attribute_max->setUpperBound(1);
	m_interval_Attribute_max->setTransient(false);
	m_interval_Attribute_max->setVolatile(false);
	m_interval_Attribute_max->setChangeable(true);
	m_interval_Attribute_max->setUnsettable(false);
	m_interval_Attribute_max->setUnique(true);
	m_interval_Attribute_max->setDerived(false);
	m_interval_Attribute_max->setOrdered(false);
	m_interval_Attribute_max->setContainment(false);
	m_interval_Attribute_max->setResolveProxies(true);
	m_interval_Attribute_max->setDefaultValueLiteral("");	
	
	m_interval_Attribute_max->_setID(INTERVAL_ATTRIBUTE_MAX);
	m_interval_Attribute_min->setName("min");
	m_interval_Attribute_min->setEType(getValueSpecification_Class());
	m_interval_Attribute_min->setLowerBound(1);
	m_interval_Attribute_min->setUpperBound(1);
	m_interval_Attribute_min->setTransient(false);
	m_interval_Attribute_min->setVolatile(false);
	m_interval_Attribute_min->setChangeable(true);
	m_interval_Attribute_min->setUnsettable(false);
	m_interval_Attribute_min->setUnique(true);
	m_interval_Attribute_min->setDerived(false);
	m_interval_Attribute_min->setOrdered(false);
	m_interval_Attribute_min->setContainment(false);
	m_interval_Attribute_min->setResolveProxies(true);
	m_interval_Attribute_min->setDefaultValueLiteral("");	
	
	m_interval_Attribute_min->_setID(INTERVAL_ATTRIBUTE_MIN);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeIntervalConstraintContent()
{
	m_intervalConstraint_Class->setName("IntervalConstraint");
	m_intervalConstraint_Class->setAbstract(false);
	m_intervalConstraint_Class->setInterface(false);
	
	m_intervalConstraint_Class->_setID(INTERVALCONSTRAINT_CLASS);
	
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

void umlPackageImpl::initializeInvocationActionContent()
{
	m_invocationAction_Class->setName("InvocationAction");
	m_invocationAction_Class->setAbstract(true);
	m_invocationAction_Class->setInterface(false);
	
	m_invocationAction_Class->_setID(INVOCATIONACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_invocationAction_Attribute_argument->setName("argument");
	m_invocationAction_Attribute_argument->setEType(getInputPin_Class());
	m_invocationAction_Attribute_argument->setLowerBound(0);
	m_invocationAction_Attribute_argument->setUpperBound(-1);
	m_invocationAction_Attribute_argument->setTransient(false);
	m_invocationAction_Attribute_argument->setVolatile(false);
	m_invocationAction_Attribute_argument->setChangeable(true);
	m_invocationAction_Attribute_argument->setUnsettable(false);
	m_invocationAction_Attribute_argument->setUnique(true);
	m_invocationAction_Attribute_argument->setDerived(false);
	m_invocationAction_Attribute_argument->setOrdered(true);
	m_invocationAction_Attribute_argument->setContainment(true);
	m_invocationAction_Attribute_argument->setResolveProxies(true);
	m_invocationAction_Attribute_argument->setDefaultValueLiteral("");	
	m_invocationAction_Attribute_argument->setEOpposite(uml::umlPackage::eInstance()->getInputPin_Attribute_invocationAction());
	
	m_invocationAction_Attribute_argument->_setID(INVOCATIONACTION_ATTRIBUTE_ARGUMENT);
	m_invocationAction_Attribute_onPort->setName("onPort");
	m_invocationAction_Attribute_onPort->setEType(getPort_Class());
	m_invocationAction_Attribute_onPort->setLowerBound(0);
	m_invocationAction_Attribute_onPort->setUpperBound(1);
	m_invocationAction_Attribute_onPort->setTransient(false);
	m_invocationAction_Attribute_onPort->setVolatile(false);
	m_invocationAction_Attribute_onPort->setChangeable(true);
	m_invocationAction_Attribute_onPort->setUnsettable(false);
	m_invocationAction_Attribute_onPort->setUnique(true);
	m_invocationAction_Attribute_onPort->setDerived(false);
	m_invocationAction_Attribute_onPort->setOrdered(false);
	m_invocationAction_Attribute_onPort->setContainment(false);
	m_invocationAction_Attribute_onPort->setResolveProxies(true);
	m_invocationAction_Attribute_onPort->setDefaultValueLiteral("");	
	
	m_invocationAction_Attribute_onPort->_setID(INVOCATIONACTION_ATTRIBUTE_ONPORT);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeJoinNodeContent()
{
	m_joinNode_Class->setName("JoinNode");
	m_joinNode_Class->setAbstract(false);
	m_joinNode_Class->setInterface(false);
	
	m_joinNode_Class->_setID(JOINNODE_CLASS);
	
	/*
	 * EAttributes
	 */
	m_joinNode_Attribute_isCombineDuplicate = getJoinNode_Attribute_isCombineDuplicate();
	m_joinNode_Attribute_isCombineDuplicate->setName("isCombineDuplicate");
	m_joinNode_Attribute_isCombineDuplicate->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_joinNode_Attribute_isCombineDuplicate->setLowerBound(1);
	m_joinNode_Attribute_isCombineDuplicate->setUpperBound(1);
	m_joinNode_Attribute_isCombineDuplicate->setTransient(false);
	m_joinNode_Attribute_isCombineDuplicate->setVolatile(false);
	m_joinNode_Attribute_isCombineDuplicate->setChangeable(true);
	m_joinNode_Attribute_isCombineDuplicate->setUnsettable(false);
	m_joinNode_Attribute_isCombineDuplicate->setUnique(true);
	m_joinNode_Attribute_isCombineDuplicate->setDerived(false);
	m_joinNode_Attribute_isCombineDuplicate->setOrdered(false);
	m_joinNode_Attribute_isCombineDuplicate->setID(false);
	m_joinNode_Attribute_isCombineDuplicate->setDefaultValueLiteral("true");
	
	m_joinNode_Attribute_isCombineDuplicate->_setID(JOINNODE_ATTRIBUTE_ISCOMBINEDUPLICATE);
	
	/*
	 * EReferences
	 */
	m_joinNode_Attribute_joinSpec->setName("joinSpec");
	m_joinNode_Attribute_joinSpec->setEType(getValueSpecification_Class());
	m_joinNode_Attribute_joinSpec->setLowerBound(0);
	m_joinNode_Attribute_joinSpec->setUpperBound(1);
	m_joinNode_Attribute_joinSpec->setTransient(false);
	m_joinNode_Attribute_joinSpec->setVolatile(false);
	m_joinNode_Attribute_joinSpec->setChangeable(true);
	m_joinNode_Attribute_joinSpec->setUnsettable(false);
	m_joinNode_Attribute_joinSpec->setUnique(true);
	m_joinNode_Attribute_joinSpec->setDerived(false);
	m_joinNode_Attribute_joinSpec->setOrdered(false);
	m_joinNode_Attribute_joinSpec->setContainment(true);
	m_joinNode_Attribute_joinSpec->setResolveProxies(true);
	m_joinNode_Attribute_joinSpec->setDefaultValueLiteral("");	
	
	m_joinNode_Attribute_joinSpec->_setID(JOINNODE_ATTRIBUTE_JOINSPEC);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeLifelineContent()
{
	m_lifeline_Class->setName("Lifeline");
	m_lifeline_Class->setAbstract(false);
	m_lifeline_Class->setInterface(false);
	
	m_lifeline_Class->_setID(LIFELINE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_lifeline_Attribute_coveredBy->setName("coveredBy");
	m_lifeline_Attribute_coveredBy->setEType(getInteractionFragment_Class());
	m_lifeline_Attribute_coveredBy->setLowerBound(0);
	m_lifeline_Attribute_coveredBy->setUpperBound(-1);
	m_lifeline_Attribute_coveredBy->setTransient(false);
	m_lifeline_Attribute_coveredBy->setVolatile(false);
	m_lifeline_Attribute_coveredBy->setChangeable(true);
	m_lifeline_Attribute_coveredBy->setUnsettable(false);
	m_lifeline_Attribute_coveredBy->setUnique(true);
	m_lifeline_Attribute_coveredBy->setDerived(false);
	m_lifeline_Attribute_coveredBy->setOrdered(false);
	m_lifeline_Attribute_coveredBy->setContainment(false);
	m_lifeline_Attribute_coveredBy->setResolveProxies(true);
	m_lifeline_Attribute_coveredBy->setDefaultValueLiteral("");	
	m_lifeline_Attribute_coveredBy->setEOpposite(uml::umlPackage::eInstance()->getInteractionFragment_Attribute_covered());
	
	m_lifeline_Attribute_coveredBy->_setID(LIFELINE_ATTRIBUTE_COVEREDBY);
	m_lifeline_Attribute_decomposedAs->setName("decomposedAs");
	m_lifeline_Attribute_decomposedAs->setEType(getPartDecomposition_Class());
	m_lifeline_Attribute_decomposedAs->setLowerBound(0);
	m_lifeline_Attribute_decomposedAs->setUpperBound(1);
	m_lifeline_Attribute_decomposedAs->setTransient(false);
	m_lifeline_Attribute_decomposedAs->setVolatile(false);
	m_lifeline_Attribute_decomposedAs->setChangeable(true);
	m_lifeline_Attribute_decomposedAs->setUnsettable(false);
	m_lifeline_Attribute_decomposedAs->setUnique(true);
	m_lifeline_Attribute_decomposedAs->setDerived(false);
	m_lifeline_Attribute_decomposedAs->setOrdered(false);
	m_lifeline_Attribute_decomposedAs->setContainment(false);
	m_lifeline_Attribute_decomposedAs->setResolveProxies(true);
	m_lifeline_Attribute_decomposedAs->setDefaultValueLiteral("");	
	
	m_lifeline_Attribute_decomposedAs->_setID(LIFELINE_ATTRIBUTE_DECOMPOSEDAS);
	m_lifeline_Attribute_interaction->setName("interaction");
	m_lifeline_Attribute_interaction->setEType(getInteraction_Class());
	m_lifeline_Attribute_interaction->setLowerBound(1);
	m_lifeline_Attribute_interaction->setUpperBound(1);
	m_lifeline_Attribute_interaction->setTransient(false);
	m_lifeline_Attribute_interaction->setVolatile(false);
	m_lifeline_Attribute_interaction->setChangeable(true);
	m_lifeline_Attribute_interaction->setUnsettable(false);
	m_lifeline_Attribute_interaction->setUnique(true);
	m_lifeline_Attribute_interaction->setDerived(false);
	m_lifeline_Attribute_interaction->setOrdered(false);
	m_lifeline_Attribute_interaction->setContainment(false);
	m_lifeline_Attribute_interaction->setResolveProxies(true);
	m_lifeline_Attribute_interaction->setDefaultValueLiteral("");	
	m_lifeline_Attribute_interaction->setEOpposite(uml::umlPackage::eInstance()->getInteraction_Attribute_lifeline());
	
	m_lifeline_Attribute_interaction->_setID(LIFELINE_ATTRIBUTE_INTERACTION);
	m_lifeline_Attribute_represents->setName("represents");
	m_lifeline_Attribute_represents->setEType(getConnectableElement_Class());
	m_lifeline_Attribute_represents->setLowerBound(0);
	m_lifeline_Attribute_represents->setUpperBound(1);
	m_lifeline_Attribute_represents->setTransient(false);
	m_lifeline_Attribute_represents->setVolatile(false);
	m_lifeline_Attribute_represents->setChangeable(true);
	m_lifeline_Attribute_represents->setUnsettable(false);
	m_lifeline_Attribute_represents->setUnique(true);
	m_lifeline_Attribute_represents->setDerived(false);
	m_lifeline_Attribute_represents->setOrdered(false);
	m_lifeline_Attribute_represents->setContainment(false);
	m_lifeline_Attribute_represents->setResolveProxies(true);
	m_lifeline_Attribute_represents->setDefaultValueLiteral("");	
	
	m_lifeline_Attribute_represents->_setID(LIFELINE_ATTRIBUTE_REPRESENTS);
	m_lifeline_Attribute_selector->setName("selector");
	m_lifeline_Attribute_selector->setEType(getValueSpecification_Class());
	m_lifeline_Attribute_selector->setLowerBound(0);
	m_lifeline_Attribute_selector->setUpperBound(1);
	m_lifeline_Attribute_selector->setTransient(false);
	m_lifeline_Attribute_selector->setVolatile(false);
	m_lifeline_Attribute_selector->setChangeable(true);
	m_lifeline_Attribute_selector->setUnsettable(false);
	m_lifeline_Attribute_selector->setUnique(true);
	m_lifeline_Attribute_selector->setDerived(false);
	m_lifeline_Attribute_selector->setOrdered(false);
	m_lifeline_Attribute_selector->setContainment(true);
	m_lifeline_Attribute_selector->setResolveProxies(true);
	m_lifeline_Attribute_selector->setDefaultValueLiteral("");	
	
	m_lifeline_Attribute_selector->_setID(LIFELINE_ATTRIBUTE_SELECTOR);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeLinkActionContent()
{
	m_linkAction_Class->setName("LinkAction");
	m_linkAction_Class->setAbstract(true);
	m_linkAction_Class->setInterface(false);
	
	m_linkAction_Class->_setID(LINKACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_linkAction_Attribute_endData->setName("endData");
	m_linkAction_Attribute_endData->setEType(getLinkEndData_Class());
	m_linkAction_Attribute_endData->setLowerBound(2);
	m_linkAction_Attribute_endData->setUpperBound(-1);
	m_linkAction_Attribute_endData->setTransient(false);
	m_linkAction_Attribute_endData->setVolatile(false);
	m_linkAction_Attribute_endData->setChangeable(true);
	m_linkAction_Attribute_endData->setUnsettable(false);
	m_linkAction_Attribute_endData->setUnique(true);
	m_linkAction_Attribute_endData->setDerived(false);
	m_linkAction_Attribute_endData->setOrdered(false);
	m_linkAction_Attribute_endData->setContainment(true);
	m_linkAction_Attribute_endData->setResolveProxies(true);
	m_linkAction_Attribute_endData->setDefaultValueLiteral("");	
	
	m_linkAction_Attribute_endData->_setID(LINKACTION_ATTRIBUTE_ENDDATA);
	m_linkAction_Attribute_inputValue->setName("inputValue");
	m_linkAction_Attribute_inputValue->setEType(getInputPin_Class());
	m_linkAction_Attribute_inputValue->setLowerBound(1);
	m_linkAction_Attribute_inputValue->setUpperBound(-1);
	m_linkAction_Attribute_inputValue->setTransient(false);
	m_linkAction_Attribute_inputValue->setVolatile(false);
	m_linkAction_Attribute_inputValue->setChangeable(true);
	m_linkAction_Attribute_inputValue->setUnsettable(false);
	m_linkAction_Attribute_inputValue->setUnique(true);
	m_linkAction_Attribute_inputValue->setDerived(false);
	m_linkAction_Attribute_inputValue->setOrdered(false);
	m_linkAction_Attribute_inputValue->setContainment(true);
	m_linkAction_Attribute_inputValue->setResolveProxies(true);
	m_linkAction_Attribute_inputValue->setDefaultValueLiteral("");	
	
	m_linkAction_Attribute_inputValue->_setID(LINKACTION_ATTRIBUTE_INPUTVALUE);
	
	/*
	 * EOperations
	 */
	m_linkAction_Operation_association->setName("association");
	m_linkAction_Operation_association->setEType(getAssociation_Class());
	m_linkAction_Operation_association->setLowerBound(1);
	m_linkAction_Operation_association->setUpperBound(1);
	m_linkAction_Operation_association->setUnique(true);
	m_linkAction_Operation_association->setOrdered(false);
	
	m_linkAction_Operation_association->_setID(LINKACTION_OPERATION_ASSOCIATION);
	
	
	
}

void umlPackageImpl::initializeLinkEndCreationDataContent()
{
	m_linkEndCreationData_Class->setName("LinkEndCreationData");
	m_linkEndCreationData_Class->setAbstract(false);
	m_linkEndCreationData_Class->setInterface(false);
	
	m_linkEndCreationData_Class->_setID(LINKENDCREATIONDATA_CLASS);
	
	/*
	 * EAttributes
	 */
	m_linkEndCreationData_Attribute_isReplaceAll = getLinkEndCreationData_Attribute_isReplaceAll();
	m_linkEndCreationData_Attribute_isReplaceAll->setName("isReplaceAll");
	m_linkEndCreationData_Attribute_isReplaceAll->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_linkEndCreationData_Attribute_isReplaceAll->setLowerBound(1);
	m_linkEndCreationData_Attribute_isReplaceAll->setUpperBound(1);
	m_linkEndCreationData_Attribute_isReplaceAll->setTransient(false);
	m_linkEndCreationData_Attribute_isReplaceAll->setVolatile(false);
	m_linkEndCreationData_Attribute_isReplaceAll->setChangeable(true);
	m_linkEndCreationData_Attribute_isReplaceAll->setUnsettable(false);
	m_linkEndCreationData_Attribute_isReplaceAll->setUnique(true);
	m_linkEndCreationData_Attribute_isReplaceAll->setDerived(false);
	m_linkEndCreationData_Attribute_isReplaceAll->setOrdered(false);
	m_linkEndCreationData_Attribute_isReplaceAll->setID(false);
	m_linkEndCreationData_Attribute_isReplaceAll->setDefaultValueLiteral("false");
	
	m_linkEndCreationData_Attribute_isReplaceAll->_setID(LINKENDCREATIONDATA_ATTRIBUTE_ISREPLACEALL);
	
	/*
	 * EReferences
	 */
	m_linkEndCreationData_Attribute_insertAt->setName("insertAt");
	m_linkEndCreationData_Attribute_insertAt->setEType(getInputPin_Class());
	m_linkEndCreationData_Attribute_insertAt->setLowerBound(0);
	m_linkEndCreationData_Attribute_insertAt->setUpperBound(1);
	m_linkEndCreationData_Attribute_insertAt->setTransient(false);
	m_linkEndCreationData_Attribute_insertAt->setVolatile(false);
	m_linkEndCreationData_Attribute_insertAt->setChangeable(true);
	m_linkEndCreationData_Attribute_insertAt->setUnsettable(false);
	m_linkEndCreationData_Attribute_insertAt->setUnique(true);
	m_linkEndCreationData_Attribute_insertAt->setDerived(false);
	m_linkEndCreationData_Attribute_insertAt->setOrdered(false);
	m_linkEndCreationData_Attribute_insertAt->setContainment(false);
	m_linkEndCreationData_Attribute_insertAt->setResolveProxies(true);
	m_linkEndCreationData_Attribute_insertAt->setDefaultValueLiteral("");	
	
	m_linkEndCreationData_Attribute_insertAt->_setID(LINKENDCREATIONDATA_ATTRIBUTE_INSERTAT);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeLinkEndDataContent()
{
	m_linkEndData_Class->setName("LinkEndData");
	m_linkEndData_Class->setAbstract(false);
	m_linkEndData_Class->setInterface(false);
	
	m_linkEndData_Class->_setID(LINKENDDATA_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_linkEndData_Attribute_end->setName("end");
	m_linkEndData_Attribute_end->setEType(getProperty_Class());
	m_linkEndData_Attribute_end->setLowerBound(1);
	m_linkEndData_Attribute_end->setUpperBound(1);
	m_linkEndData_Attribute_end->setTransient(false);
	m_linkEndData_Attribute_end->setVolatile(false);
	m_linkEndData_Attribute_end->setChangeable(true);
	m_linkEndData_Attribute_end->setUnsettable(false);
	m_linkEndData_Attribute_end->setUnique(true);
	m_linkEndData_Attribute_end->setDerived(false);
	m_linkEndData_Attribute_end->setOrdered(false);
	m_linkEndData_Attribute_end->setContainment(false);
	m_linkEndData_Attribute_end->setResolveProxies(true);
	m_linkEndData_Attribute_end->setDefaultValueLiteral("");	
	
	m_linkEndData_Attribute_end->_setID(LINKENDDATA_ATTRIBUTE_END);
	m_linkEndData_Attribute_qualifier->setName("qualifier");
	m_linkEndData_Attribute_qualifier->setEType(getQualifierValue_Class());
	m_linkEndData_Attribute_qualifier->setLowerBound(0);
	m_linkEndData_Attribute_qualifier->setUpperBound(-1);
	m_linkEndData_Attribute_qualifier->setTransient(false);
	m_linkEndData_Attribute_qualifier->setVolatile(false);
	m_linkEndData_Attribute_qualifier->setChangeable(true);
	m_linkEndData_Attribute_qualifier->setUnsettable(false);
	m_linkEndData_Attribute_qualifier->setUnique(true);
	m_linkEndData_Attribute_qualifier->setDerived(false);
	m_linkEndData_Attribute_qualifier->setOrdered(false);
	m_linkEndData_Attribute_qualifier->setContainment(true);
	m_linkEndData_Attribute_qualifier->setResolveProxies(true);
	m_linkEndData_Attribute_qualifier->setDefaultValueLiteral("");	
	
	m_linkEndData_Attribute_qualifier->_setID(LINKENDDATA_ATTRIBUTE_QUALIFIER);
	m_linkEndData_Attribute_value->setName("value");
	m_linkEndData_Attribute_value->setEType(getInputPin_Class());
	m_linkEndData_Attribute_value->setLowerBound(0);
	m_linkEndData_Attribute_value->setUpperBound(1);
	m_linkEndData_Attribute_value->setTransient(false);
	m_linkEndData_Attribute_value->setVolatile(false);
	m_linkEndData_Attribute_value->setChangeable(true);
	m_linkEndData_Attribute_value->setUnsettable(false);
	m_linkEndData_Attribute_value->setUnique(true);
	m_linkEndData_Attribute_value->setDerived(false);
	m_linkEndData_Attribute_value->setOrdered(false);
	m_linkEndData_Attribute_value->setContainment(false);
	m_linkEndData_Attribute_value->setResolveProxies(true);
	m_linkEndData_Attribute_value->setDefaultValueLiteral("");	
	
	m_linkEndData_Attribute_value->_setID(LINKENDDATA_ATTRIBUTE_VALUE);
	
	/*
	 * EOperations
	 */
	m_linkEndData_Operation_allPins->setName("allPins");
	m_linkEndData_Operation_allPins->setEType(getInputPin_Class());
	m_linkEndData_Operation_allPins->setLowerBound(0);
	m_linkEndData_Operation_allPins->setUpperBound(-1);
	m_linkEndData_Operation_allPins->setUnique(false);
	m_linkEndData_Operation_allPins->setOrdered(false);
	
	m_linkEndData_Operation_allPins->_setID(LINKENDDATA_OPERATION_ALLPINS);
	
	
	
}

void umlPackageImpl::initializeLinkEndDestructionDataContent()
{
	m_linkEndDestructionData_Class->setName("LinkEndDestructionData");
	m_linkEndDestructionData_Class->setAbstract(false);
	m_linkEndDestructionData_Class->setInterface(false);
	
	m_linkEndDestructionData_Class->_setID(LINKENDDESTRUCTIONDATA_CLASS);
	
	/*
	 * EAttributes
	 */
	m_linkEndDestructionData_Attribute_isDestroyDuplicates = getLinkEndDestructionData_Attribute_isDestroyDuplicates();
	m_linkEndDestructionData_Attribute_isDestroyDuplicates->setName("isDestroyDuplicates");
	m_linkEndDestructionData_Attribute_isDestroyDuplicates->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_linkEndDestructionData_Attribute_isDestroyDuplicates->setLowerBound(1);
	m_linkEndDestructionData_Attribute_isDestroyDuplicates->setUpperBound(1);
	m_linkEndDestructionData_Attribute_isDestroyDuplicates->setTransient(false);
	m_linkEndDestructionData_Attribute_isDestroyDuplicates->setVolatile(false);
	m_linkEndDestructionData_Attribute_isDestroyDuplicates->setChangeable(true);
	m_linkEndDestructionData_Attribute_isDestroyDuplicates->setUnsettable(false);
	m_linkEndDestructionData_Attribute_isDestroyDuplicates->setUnique(true);
	m_linkEndDestructionData_Attribute_isDestroyDuplicates->setDerived(false);
	m_linkEndDestructionData_Attribute_isDestroyDuplicates->setOrdered(false);
	m_linkEndDestructionData_Attribute_isDestroyDuplicates->setID(false);
	m_linkEndDestructionData_Attribute_isDestroyDuplicates->setDefaultValueLiteral("false");
	
	m_linkEndDestructionData_Attribute_isDestroyDuplicates->_setID(LINKENDDESTRUCTIONDATA_ATTRIBUTE_ISDESTROYDUPLICATES);
	
	/*
	 * EReferences
	 */
	m_linkEndDestructionData_Attribute_destroyAt->setName("destroyAt");
	m_linkEndDestructionData_Attribute_destroyAt->setEType(getInputPin_Class());
	m_linkEndDestructionData_Attribute_destroyAt->setLowerBound(0);
	m_linkEndDestructionData_Attribute_destroyAt->setUpperBound(1);
	m_linkEndDestructionData_Attribute_destroyAt->setTransient(false);
	m_linkEndDestructionData_Attribute_destroyAt->setVolatile(false);
	m_linkEndDestructionData_Attribute_destroyAt->setChangeable(true);
	m_linkEndDestructionData_Attribute_destroyAt->setUnsettable(false);
	m_linkEndDestructionData_Attribute_destroyAt->setUnique(true);
	m_linkEndDestructionData_Attribute_destroyAt->setDerived(false);
	m_linkEndDestructionData_Attribute_destroyAt->setOrdered(false);
	m_linkEndDestructionData_Attribute_destroyAt->setContainment(false);
	m_linkEndDestructionData_Attribute_destroyAt->setResolveProxies(true);
	m_linkEndDestructionData_Attribute_destroyAt->setDefaultValueLiteral("");	
	
	m_linkEndDestructionData_Attribute_destroyAt->_setID(LINKENDDESTRUCTIONDATA_ATTRIBUTE_DESTROYAT);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeLiteralBooleanContent()
{
	m_literalBoolean_Class->setName("LiteralBoolean");
	m_literalBoolean_Class->setAbstract(false);
	m_literalBoolean_Class->setInterface(false);
	
	m_literalBoolean_Class->_setID(LITERALBOOLEAN_CLASS);
	
	/*
	 * EAttributes
	 */
	m_literalBoolean_Attribute_value = getLiteralBoolean_Attribute_value();
	m_literalBoolean_Attribute_value->setName("value");
	m_literalBoolean_Attribute_value->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_literalBoolean_Attribute_value->setLowerBound(1);
	m_literalBoolean_Attribute_value->setUpperBound(1);
	m_literalBoolean_Attribute_value->setTransient(false);
	m_literalBoolean_Attribute_value->setVolatile(false);
	m_literalBoolean_Attribute_value->setChangeable(true);
	m_literalBoolean_Attribute_value->setUnsettable(false);
	m_literalBoolean_Attribute_value->setUnique(true);
	m_literalBoolean_Attribute_value->setDerived(false);
	m_literalBoolean_Attribute_value->setOrdered(false);
	m_literalBoolean_Attribute_value->setID(false);
	m_literalBoolean_Attribute_value->setDefaultValueLiteral("false");
	
	m_literalBoolean_Attribute_value->_setID(LITERALBOOLEAN_ATTRIBUTE_VALUE);
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_literalBoolean_Operation_booleanValue->setName("booleanValue");
	m_literalBoolean_Operation_booleanValue->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_literalBoolean_Operation_booleanValue->setLowerBound(0);
	m_literalBoolean_Operation_booleanValue->setUpperBound(1);
	m_literalBoolean_Operation_booleanValue->setUnique(true);
	m_literalBoolean_Operation_booleanValue->setOrdered(false);
	
	m_literalBoolean_Operation_booleanValue->_setID(LITERALBOOLEAN_OPERATION_BOOLEANVALUE);
	
	
	m_literalBoolean_Operation_isComputable->setName("isComputable");
	m_literalBoolean_Operation_isComputable->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_literalBoolean_Operation_isComputable->setLowerBound(1);
	m_literalBoolean_Operation_isComputable->setUpperBound(1);
	m_literalBoolean_Operation_isComputable->setUnique(true);
	m_literalBoolean_Operation_isComputable->setOrdered(false);
	
	m_literalBoolean_Operation_isComputable->_setID(LITERALBOOLEAN_OPERATION_ISCOMPUTABLE);
	
	
	
}

void umlPackageImpl::initializeLiteralIntegerContent()
{
	m_literalInteger_Class->setName("LiteralInteger");
	m_literalInteger_Class->setAbstract(false);
	m_literalInteger_Class->setInterface(false);
	
	m_literalInteger_Class->_setID(LITERALINTEGER_CLASS);
	
	/*
	 * EAttributes
	 */
	m_literalInteger_Attribute_value = getLiteralInteger_Attribute_value();
	m_literalInteger_Attribute_value->setName("value");
	m_literalInteger_Attribute_value->setEType(types::typesPackage::eInstance()->getInteger_Class());
	m_literalInteger_Attribute_value->setLowerBound(1);
	m_literalInteger_Attribute_value->setUpperBound(1);
	m_literalInteger_Attribute_value->setTransient(false);
	m_literalInteger_Attribute_value->setVolatile(false);
	m_literalInteger_Attribute_value->setChangeable(true);
	m_literalInteger_Attribute_value->setUnsettable(false);
	m_literalInteger_Attribute_value->setUnique(true);
	m_literalInteger_Attribute_value->setDerived(false);
	m_literalInteger_Attribute_value->setOrdered(false);
	m_literalInteger_Attribute_value->setID(false);
	m_literalInteger_Attribute_value->setDefaultValueLiteral("0");
	
	m_literalInteger_Attribute_value->_setID(LITERALINTEGER_ATTRIBUTE_VALUE);
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_literalInteger_Operation_integerValue->setName("integerValue");
	m_literalInteger_Operation_integerValue->setEType(types::typesPackage::eInstance()->getInteger_Class());
	m_literalInteger_Operation_integerValue->setLowerBound(0);
	m_literalInteger_Operation_integerValue->setUpperBound(1);
	m_literalInteger_Operation_integerValue->setUnique(true);
	m_literalInteger_Operation_integerValue->setOrdered(false);
	
	m_literalInteger_Operation_integerValue->_setID(LITERALINTEGER_OPERATION_INTEGERVALUE);
	
	
	m_literalInteger_Operation_isComputable->setName("isComputable");
	m_literalInteger_Operation_isComputable->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_literalInteger_Operation_isComputable->setLowerBound(1);
	m_literalInteger_Operation_isComputable->setUpperBound(1);
	m_literalInteger_Operation_isComputable->setUnique(true);
	m_literalInteger_Operation_isComputable->setOrdered(false);
	
	m_literalInteger_Operation_isComputable->_setID(LITERALINTEGER_OPERATION_ISCOMPUTABLE);
	
	
	
}

void umlPackageImpl::initializeLiteralNullContent()
{
	m_literalNull_Class->setName("LiteralNull");
	m_literalNull_Class->setAbstract(false);
	m_literalNull_Class->setInterface(false);
	
	m_literalNull_Class->_setID(LITERALNULL_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_literalNull_Operation_isComputable->setName("isComputable");
	m_literalNull_Operation_isComputable->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_literalNull_Operation_isComputable->setLowerBound(1);
	m_literalNull_Operation_isComputable->setUpperBound(1);
	m_literalNull_Operation_isComputable->setUnique(true);
	m_literalNull_Operation_isComputable->setOrdered(false);
	
	m_literalNull_Operation_isComputable->_setID(LITERALNULL_OPERATION_ISCOMPUTABLE);
	
	
	m_literalNull_Operation_isNull->setName("isNull");
	m_literalNull_Operation_isNull->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_literalNull_Operation_isNull->setLowerBound(1);
	m_literalNull_Operation_isNull->setUpperBound(1);
	m_literalNull_Operation_isNull->setUnique(true);
	m_literalNull_Operation_isNull->setOrdered(false);
	
	m_literalNull_Operation_isNull->_setID(LITERALNULL_OPERATION_ISNULL);
	
	
	
}

void umlPackageImpl::initializeLiteralRealContent()
{
	m_literalReal_Class->setName("LiteralReal");
	m_literalReal_Class->setAbstract(false);
	m_literalReal_Class->setInterface(false);
	
	m_literalReal_Class->_setID(LITERALREAL_CLASS);
	
	/*
	 * EAttributes
	 */
	m_literalReal_Attribute_value = getLiteralReal_Attribute_value();
	m_literalReal_Attribute_value->setName("value");
	m_literalReal_Attribute_value->setEType(types::typesPackage::eInstance()->getReal_Class());
	m_literalReal_Attribute_value->setLowerBound(1);
	m_literalReal_Attribute_value->setUpperBound(1);
	m_literalReal_Attribute_value->setTransient(false);
	m_literalReal_Attribute_value->setVolatile(false);
	m_literalReal_Attribute_value->setChangeable(true);
	m_literalReal_Attribute_value->setUnsettable(false);
	m_literalReal_Attribute_value->setUnique(true);
	m_literalReal_Attribute_value->setDerived(false);
	m_literalReal_Attribute_value->setOrdered(false);
	m_literalReal_Attribute_value->setID(false);
	m_literalReal_Attribute_value->setDefaultValueLiteral("");
	
	m_literalReal_Attribute_value->_setID(LITERALREAL_ATTRIBUTE_VALUE);
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_literalReal_Operation_isComputable->setName("isComputable");
	m_literalReal_Operation_isComputable->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_literalReal_Operation_isComputable->setLowerBound(1);
	m_literalReal_Operation_isComputable->setUpperBound(1);
	m_literalReal_Operation_isComputable->setUnique(true);
	m_literalReal_Operation_isComputable->setOrdered(false);
	
	m_literalReal_Operation_isComputable->_setID(LITERALREAL_OPERATION_ISCOMPUTABLE);
	
	
	m_literalReal_Operation_realValue->setName("realValue");
	m_literalReal_Operation_realValue->setEType(types::typesPackage::eInstance()->getReal_Class());
	m_literalReal_Operation_realValue->setLowerBound(0);
	m_literalReal_Operation_realValue->setUpperBound(1);
	m_literalReal_Operation_realValue->setUnique(true);
	m_literalReal_Operation_realValue->setOrdered(false);
	
	m_literalReal_Operation_realValue->_setID(LITERALREAL_OPERATION_REALVALUE);
	
	
	
}

void umlPackageImpl::initializeLiteralSpecificationContent()
{
	m_literalSpecification_Class->setName("LiteralSpecification");
	m_literalSpecification_Class->setAbstract(true);
	m_literalSpecification_Class->setInterface(false);
	
	m_literalSpecification_Class->_setID(LITERALSPECIFICATION_CLASS);
	
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

void umlPackageImpl::initializeLiteralStringContent()
{
	m_literalString_Class->setName("LiteralString");
	m_literalString_Class->setAbstract(false);
	m_literalString_Class->setInterface(false);
	
	m_literalString_Class->_setID(LITERALSTRING_CLASS);
	
	/*
	 * EAttributes
	 */
	m_literalString_Attribute_value = getLiteralString_Attribute_value();
	m_literalString_Attribute_value->setName("value");
	m_literalString_Attribute_value->setEType(types::typesPackage::eInstance()->getString_Class());
	m_literalString_Attribute_value->setLowerBound(0);
	m_literalString_Attribute_value->setUpperBound(1);
	m_literalString_Attribute_value->setTransient(false);
	m_literalString_Attribute_value->setVolatile(false);
	m_literalString_Attribute_value->setChangeable(true);
	m_literalString_Attribute_value->setUnsettable(true);
	m_literalString_Attribute_value->setUnique(true);
	m_literalString_Attribute_value->setDerived(false);
	m_literalString_Attribute_value->setOrdered(false);
	m_literalString_Attribute_value->setID(false);
	m_literalString_Attribute_value->setDefaultValueLiteral("");
	
	m_literalString_Attribute_value->_setID(LITERALSTRING_ATTRIBUTE_VALUE);
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_literalString_Operation_isComputable->setName("isComputable");
	m_literalString_Operation_isComputable->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_literalString_Operation_isComputable->setLowerBound(1);
	m_literalString_Operation_isComputable->setUpperBound(1);
	m_literalString_Operation_isComputable->setUnique(true);
	m_literalString_Operation_isComputable->setOrdered(false);
	
	m_literalString_Operation_isComputable->_setID(LITERALSTRING_OPERATION_ISCOMPUTABLE);
	
	
	m_literalString_Operation_stringValue->setName("stringValue");
	m_literalString_Operation_stringValue->setEType(types::typesPackage::eInstance()->getString_Class());
	m_literalString_Operation_stringValue->setLowerBound(0);
	m_literalString_Operation_stringValue->setUpperBound(1);
	m_literalString_Operation_stringValue->setUnique(true);
	m_literalString_Operation_stringValue->setOrdered(false);
	
	m_literalString_Operation_stringValue->_setID(LITERALSTRING_OPERATION_STRINGVALUE);
	
	
	
}

void umlPackageImpl::initializeLiteralUnlimitedNaturalContent()
{
	m_literalUnlimitedNatural_Class->setName("LiteralUnlimitedNatural");
	m_literalUnlimitedNatural_Class->setAbstract(false);
	m_literalUnlimitedNatural_Class->setInterface(false);
	
	m_literalUnlimitedNatural_Class->_setID(LITERALUNLIMITEDNATURAL_CLASS);
	
	/*
	 * EAttributes
	 */
	m_literalUnlimitedNatural_Attribute_value = getLiteralUnlimitedNatural_Attribute_value();
	m_literalUnlimitedNatural_Attribute_value->setName("value");
	m_literalUnlimitedNatural_Attribute_value->setEType(types::typesPackage::eInstance()->getUnlimitedNatural_Class());
	m_literalUnlimitedNatural_Attribute_value->setLowerBound(1);
	m_literalUnlimitedNatural_Attribute_value->setUpperBound(1);
	m_literalUnlimitedNatural_Attribute_value->setTransient(false);
	m_literalUnlimitedNatural_Attribute_value->setVolatile(false);
	m_literalUnlimitedNatural_Attribute_value->setChangeable(true);
	m_literalUnlimitedNatural_Attribute_value->setUnsettable(false);
	m_literalUnlimitedNatural_Attribute_value->setUnique(true);
	m_literalUnlimitedNatural_Attribute_value->setDerived(false);
	m_literalUnlimitedNatural_Attribute_value->setOrdered(false);
	m_literalUnlimitedNatural_Attribute_value->setID(false);
	m_literalUnlimitedNatural_Attribute_value->setDefaultValueLiteral("0");
	
	m_literalUnlimitedNatural_Attribute_value->_setID(LITERALUNLIMITEDNATURAL_ATTRIBUTE_VALUE);
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_literalUnlimitedNatural_Operation_isComputable->setName("isComputable");
	m_literalUnlimitedNatural_Operation_isComputable->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_literalUnlimitedNatural_Operation_isComputable->setLowerBound(1);
	m_literalUnlimitedNatural_Operation_isComputable->setUpperBound(1);
	m_literalUnlimitedNatural_Operation_isComputable->setUnique(true);
	m_literalUnlimitedNatural_Operation_isComputable->setOrdered(false);
	
	m_literalUnlimitedNatural_Operation_isComputable->_setID(LITERALUNLIMITEDNATURAL_OPERATION_ISCOMPUTABLE);
	
	
	m_literalUnlimitedNatural_Operation_unlimitedValue->setName("unlimitedValue");
	m_literalUnlimitedNatural_Operation_unlimitedValue->setEType(types::typesPackage::eInstance()->getUnlimitedNatural_Class());
	m_literalUnlimitedNatural_Operation_unlimitedValue->setLowerBound(0);
	m_literalUnlimitedNatural_Operation_unlimitedValue->setUpperBound(1);
	m_literalUnlimitedNatural_Operation_unlimitedValue->setUnique(true);
	m_literalUnlimitedNatural_Operation_unlimitedValue->setOrdered(false);
	
	m_literalUnlimitedNatural_Operation_unlimitedValue->_setID(LITERALUNLIMITEDNATURAL_OPERATION_UNLIMITEDVALUE);
	
	
	
}

void umlPackageImpl::initializeLoopNodeContent()
{
	m_loopNode_Class->setName("LoopNode");
	m_loopNode_Class->setAbstract(false);
	m_loopNode_Class->setInterface(false);
	
	m_loopNode_Class->_setID(LOOPNODE_CLASS);
	
	/*
	 * EAttributes
	 */
	m_loopNode_Attribute_isTestedFirst = getLoopNode_Attribute_isTestedFirst();
	m_loopNode_Attribute_isTestedFirst->setName("isTestedFirst");
	m_loopNode_Attribute_isTestedFirst->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_loopNode_Attribute_isTestedFirst->setLowerBound(1);
	m_loopNode_Attribute_isTestedFirst->setUpperBound(1);
	m_loopNode_Attribute_isTestedFirst->setTransient(false);
	m_loopNode_Attribute_isTestedFirst->setVolatile(false);
	m_loopNode_Attribute_isTestedFirst->setChangeable(true);
	m_loopNode_Attribute_isTestedFirst->setUnsettable(false);
	m_loopNode_Attribute_isTestedFirst->setUnique(true);
	m_loopNode_Attribute_isTestedFirst->setDerived(false);
	m_loopNode_Attribute_isTestedFirst->setOrdered(false);
	m_loopNode_Attribute_isTestedFirst->setID(false);
	m_loopNode_Attribute_isTestedFirst->setDefaultValueLiteral("false");
	
	m_loopNode_Attribute_isTestedFirst->_setID(LOOPNODE_ATTRIBUTE_ISTESTEDFIRST);
	
	/*
	 * EReferences
	 */
	m_loopNode_Attribute_bodyOutput->setName("bodyOutput");
	m_loopNode_Attribute_bodyOutput->setEType(getOutputPin_Class());
	m_loopNode_Attribute_bodyOutput->setLowerBound(0);
	m_loopNode_Attribute_bodyOutput->setUpperBound(-1);
	m_loopNode_Attribute_bodyOutput->setTransient(false);
	m_loopNode_Attribute_bodyOutput->setVolatile(false);
	m_loopNode_Attribute_bodyOutput->setChangeable(true);
	m_loopNode_Attribute_bodyOutput->setUnsettable(false);
	m_loopNode_Attribute_bodyOutput->setUnique(true);
	m_loopNode_Attribute_bodyOutput->setDerived(false);
	m_loopNode_Attribute_bodyOutput->setOrdered(true);
	m_loopNode_Attribute_bodyOutput->setContainment(false);
	m_loopNode_Attribute_bodyOutput->setResolveProxies(true);
	m_loopNode_Attribute_bodyOutput->setDefaultValueLiteral("");	
	
	m_loopNode_Attribute_bodyOutput->_setID(LOOPNODE_ATTRIBUTE_BODYOUTPUT);
	m_loopNode_Attribute_bodyPart->setName("bodyPart");
	m_loopNode_Attribute_bodyPart->setEType(getExecutableNode_Class());
	m_loopNode_Attribute_bodyPart->setLowerBound(0);
	m_loopNode_Attribute_bodyPart->setUpperBound(-1);
	m_loopNode_Attribute_bodyPart->setTransient(false);
	m_loopNode_Attribute_bodyPart->setVolatile(false);
	m_loopNode_Attribute_bodyPart->setChangeable(true);
	m_loopNode_Attribute_bodyPart->setUnsettable(false);
	m_loopNode_Attribute_bodyPart->setUnique(true);
	m_loopNode_Attribute_bodyPart->setDerived(false);
	m_loopNode_Attribute_bodyPart->setOrdered(false);
	m_loopNode_Attribute_bodyPart->setContainment(false);
	m_loopNode_Attribute_bodyPart->setResolveProxies(true);
	m_loopNode_Attribute_bodyPart->setDefaultValueLiteral("");	
	
	m_loopNode_Attribute_bodyPart->_setID(LOOPNODE_ATTRIBUTE_BODYPART);
	m_loopNode_Attribute_decider->setName("decider");
	m_loopNode_Attribute_decider->setEType(getOutputPin_Class());
	m_loopNode_Attribute_decider->setLowerBound(1);
	m_loopNode_Attribute_decider->setUpperBound(1);
	m_loopNode_Attribute_decider->setTransient(false);
	m_loopNode_Attribute_decider->setVolatile(false);
	m_loopNode_Attribute_decider->setChangeable(true);
	m_loopNode_Attribute_decider->setUnsettable(false);
	m_loopNode_Attribute_decider->setUnique(true);
	m_loopNode_Attribute_decider->setDerived(false);
	m_loopNode_Attribute_decider->setOrdered(false);
	m_loopNode_Attribute_decider->setContainment(false);
	m_loopNode_Attribute_decider->setResolveProxies(true);
	m_loopNode_Attribute_decider->setDefaultValueLiteral("");	
	
	m_loopNode_Attribute_decider->_setID(LOOPNODE_ATTRIBUTE_DECIDER);
	m_loopNode_Attribute_loopVariable->setName("loopVariable");
	m_loopNode_Attribute_loopVariable->setEType(getOutputPin_Class());
	m_loopNode_Attribute_loopVariable->setLowerBound(0);
	m_loopNode_Attribute_loopVariable->setUpperBound(-1);
	m_loopNode_Attribute_loopVariable->setTransient(false);
	m_loopNode_Attribute_loopVariable->setVolatile(false);
	m_loopNode_Attribute_loopVariable->setChangeable(true);
	m_loopNode_Attribute_loopVariable->setUnsettable(false);
	m_loopNode_Attribute_loopVariable->setUnique(true);
	m_loopNode_Attribute_loopVariable->setDerived(false);
	m_loopNode_Attribute_loopVariable->setOrdered(true);
	m_loopNode_Attribute_loopVariable->setContainment(true);
	m_loopNode_Attribute_loopVariable->setResolveProxies(true);
	m_loopNode_Attribute_loopVariable->setDefaultValueLiteral("");	
	
	m_loopNode_Attribute_loopVariable->_setID(LOOPNODE_ATTRIBUTE_LOOPVARIABLE);
	m_loopNode_Attribute_loopVariableInput->setName("loopVariableInput");
	m_loopNode_Attribute_loopVariableInput->setEType(getInputPin_Class());
	m_loopNode_Attribute_loopVariableInput->setLowerBound(0);
	m_loopNode_Attribute_loopVariableInput->setUpperBound(-1);
	m_loopNode_Attribute_loopVariableInput->setTransient(false);
	m_loopNode_Attribute_loopVariableInput->setVolatile(false);
	m_loopNode_Attribute_loopVariableInput->setChangeable(true);
	m_loopNode_Attribute_loopVariableInput->setUnsettable(false);
	m_loopNode_Attribute_loopVariableInput->setUnique(true);
	m_loopNode_Attribute_loopVariableInput->setDerived(false);
	m_loopNode_Attribute_loopVariableInput->setOrdered(true);
	m_loopNode_Attribute_loopVariableInput->setContainment(true);
	m_loopNode_Attribute_loopVariableInput->setResolveProxies(true);
	m_loopNode_Attribute_loopVariableInput->setDefaultValueLiteral("");	
	
	m_loopNode_Attribute_loopVariableInput->_setID(LOOPNODE_ATTRIBUTE_LOOPVARIABLEINPUT);
	m_loopNode_Attribute_result->setName("result");
	m_loopNode_Attribute_result->setEType(getOutputPin_Class());
	m_loopNode_Attribute_result->setLowerBound(0);
	m_loopNode_Attribute_result->setUpperBound(-1);
	m_loopNode_Attribute_result->setTransient(false);
	m_loopNode_Attribute_result->setVolatile(false);
	m_loopNode_Attribute_result->setChangeable(true);
	m_loopNode_Attribute_result->setUnsettable(false);
	m_loopNode_Attribute_result->setUnique(true);
	m_loopNode_Attribute_result->setDerived(false);
	m_loopNode_Attribute_result->setOrdered(true);
	m_loopNode_Attribute_result->setContainment(true);
	m_loopNode_Attribute_result->setResolveProxies(true);
	m_loopNode_Attribute_result->setDefaultValueLiteral("");	
	
	m_loopNode_Attribute_result->_setID(LOOPNODE_ATTRIBUTE_RESULT);
	m_loopNode_Attribute_setupPart->setName("setupPart");
	m_loopNode_Attribute_setupPart->setEType(getExecutableNode_Class());
	m_loopNode_Attribute_setupPart->setLowerBound(0);
	m_loopNode_Attribute_setupPart->setUpperBound(-1);
	m_loopNode_Attribute_setupPart->setTransient(false);
	m_loopNode_Attribute_setupPart->setVolatile(false);
	m_loopNode_Attribute_setupPart->setChangeable(true);
	m_loopNode_Attribute_setupPart->setUnsettable(false);
	m_loopNode_Attribute_setupPart->setUnique(true);
	m_loopNode_Attribute_setupPart->setDerived(false);
	m_loopNode_Attribute_setupPart->setOrdered(false);
	m_loopNode_Attribute_setupPart->setContainment(false);
	m_loopNode_Attribute_setupPart->setResolveProxies(true);
	m_loopNode_Attribute_setupPart->setDefaultValueLiteral("");	
	
	m_loopNode_Attribute_setupPart->_setID(LOOPNODE_ATTRIBUTE_SETUPPART);
	m_loopNode_Attribute_test->setName("test");
	m_loopNode_Attribute_test->setEType(getExecutableNode_Class());
	m_loopNode_Attribute_test->setLowerBound(1);
	m_loopNode_Attribute_test->setUpperBound(-1);
	m_loopNode_Attribute_test->setTransient(false);
	m_loopNode_Attribute_test->setVolatile(false);
	m_loopNode_Attribute_test->setChangeable(true);
	m_loopNode_Attribute_test->setUnsettable(false);
	m_loopNode_Attribute_test->setUnique(true);
	m_loopNode_Attribute_test->setDerived(false);
	m_loopNode_Attribute_test->setOrdered(false);
	m_loopNode_Attribute_test->setContainment(false);
	m_loopNode_Attribute_test->setResolveProxies(true);
	m_loopNode_Attribute_test->setDefaultValueLiteral("");	
	
	m_loopNode_Attribute_test->_setID(LOOPNODE_ATTRIBUTE_TEST);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeManifestationContent()
{
	m_manifestation_Class->setName("Manifestation");
	m_manifestation_Class->setAbstract(false);
	m_manifestation_Class->setInterface(false);
	
	m_manifestation_Class->_setID(MANIFESTATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_manifestation_Attribute_utilizedElement->setName("utilizedElement");
	m_manifestation_Attribute_utilizedElement->setEType(getPackageableElement_Class());
	m_manifestation_Attribute_utilizedElement->setLowerBound(1);
	m_manifestation_Attribute_utilizedElement->setUpperBound(1);
	m_manifestation_Attribute_utilizedElement->setTransient(false);
	m_manifestation_Attribute_utilizedElement->setVolatile(false);
	m_manifestation_Attribute_utilizedElement->setChangeable(true);
	m_manifestation_Attribute_utilizedElement->setUnsettable(false);
	m_manifestation_Attribute_utilizedElement->setUnique(true);
	m_manifestation_Attribute_utilizedElement->setDerived(false);
	m_manifestation_Attribute_utilizedElement->setOrdered(false);
	m_manifestation_Attribute_utilizedElement->setContainment(false);
	m_manifestation_Attribute_utilizedElement->setResolveProxies(true);
	m_manifestation_Attribute_utilizedElement->setDefaultValueLiteral("");	
	
	m_manifestation_Attribute_utilizedElement->_setID(MANIFESTATION_ATTRIBUTE_UTILIZEDELEMENT);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeMergeNodeContent()
{
	m_mergeNode_Class->setName("MergeNode");
	m_mergeNode_Class->setAbstract(false);
	m_mergeNode_Class->setInterface(false);
	
	m_mergeNode_Class->_setID(MERGENODE_CLASS);
	
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

void umlPackageImpl::initializeMessageContent()
{
	m_message_Class->setName("Message");
	m_message_Class->setAbstract(false);
	m_message_Class->setInterface(false);
	
	m_message_Class->_setID(MESSAGE_CLASS);
	
	/*
	 * EAttributes
	 */
	m_message_Attribute_messageKind = getMessage_Attribute_messageKind();
	m_message_Attribute_messageKind->setName("messageKind");
	m_message_Attribute_messageKind->setEType(getMessageKind_Class());
	m_message_Attribute_messageKind->setLowerBound(1);
	m_message_Attribute_messageKind->setUpperBound(1);
	m_message_Attribute_messageKind->setTransient(true);
	m_message_Attribute_messageKind->setVolatile(true);
	m_message_Attribute_messageKind->setChangeable(false);
	m_message_Attribute_messageKind->setUnsettable(false);
	m_message_Attribute_messageKind->setUnique(true);
	m_message_Attribute_messageKind->setDerived(true);
	m_message_Attribute_messageKind->setOrdered(false);
	m_message_Attribute_messageKind->setID(false);
	m_message_Attribute_messageKind->setDefaultValueLiteral("unknown");
	
	m_message_Attribute_messageKind->_setID(MESSAGE_ATTRIBUTE_MESSAGEKIND);
	m_message_Attribute_messageSort = getMessage_Attribute_messageSort();
	m_message_Attribute_messageSort->setName("messageSort");
	m_message_Attribute_messageSort->setEType(getMessageSort_Class());
	m_message_Attribute_messageSort->setLowerBound(1);
	m_message_Attribute_messageSort->setUpperBound(1);
	m_message_Attribute_messageSort->setTransient(false);
	m_message_Attribute_messageSort->setVolatile(false);
	m_message_Attribute_messageSort->setChangeable(true);
	m_message_Attribute_messageSort->setUnsettable(false);
	m_message_Attribute_messageSort->setUnique(true);
	m_message_Attribute_messageSort->setDerived(false);
	m_message_Attribute_messageSort->setOrdered(false);
	m_message_Attribute_messageSort->setID(false);
	m_message_Attribute_messageSort->setDefaultValueLiteral("synchCall");
	
	m_message_Attribute_messageSort->_setID(MESSAGE_ATTRIBUTE_MESSAGESORT);
	
	/*
	 * EReferences
	 */
	m_message_Attribute_argument->setName("argument");
	m_message_Attribute_argument->setEType(getValueSpecification_Class());
	m_message_Attribute_argument->setLowerBound(0);
	m_message_Attribute_argument->setUpperBound(-1);
	m_message_Attribute_argument->setTransient(false);
	m_message_Attribute_argument->setVolatile(false);
	m_message_Attribute_argument->setChangeable(true);
	m_message_Attribute_argument->setUnsettable(false);
	m_message_Attribute_argument->setUnique(true);
	m_message_Attribute_argument->setDerived(false);
	m_message_Attribute_argument->setOrdered(true);
	m_message_Attribute_argument->setContainment(true);
	m_message_Attribute_argument->setResolveProxies(true);
	m_message_Attribute_argument->setDefaultValueLiteral("");	
	
	m_message_Attribute_argument->_setID(MESSAGE_ATTRIBUTE_ARGUMENT);
	m_message_Attribute_connector->setName("connector");
	m_message_Attribute_connector->setEType(getConnector_Class());
	m_message_Attribute_connector->setLowerBound(0);
	m_message_Attribute_connector->setUpperBound(1);
	m_message_Attribute_connector->setTransient(false);
	m_message_Attribute_connector->setVolatile(false);
	m_message_Attribute_connector->setChangeable(true);
	m_message_Attribute_connector->setUnsettable(false);
	m_message_Attribute_connector->setUnique(true);
	m_message_Attribute_connector->setDerived(false);
	m_message_Attribute_connector->setOrdered(false);
	m_message_Attribute_connector->setContainment(false);
	m_message_Attribute_connector->setResolveProxies(true);
	m_message_Attribute_connector->setDefaultValueLiteral("");	
	
	m_message_Attribute_connector->_setID(MESSAGE_ATTRIBUTE_CONNECTOR);
	m_message_Attribute_interaction->setName("interaction");
	m_message_Attribute_interaction->setEType(getInteraction_Class());
	m_message_Attribute_interaction->setLowerBound(1);
	m_message_Attribute_interaction->setUpperBound(1);
	m_message_Attribute_interaction->setTransient(false);
	m_message_Attribute_interaction->setVolatile(false);
	m_message_Attribute_interaction->setChangeable(true);
	m_message_Attribute_interaction->setUnsettable(false);
	m_message_Attribute_interaction->setUnique(true);
	m_message_Attribute_interaction->setDerived(false);
	m_message_Attribute_interaction->setOrdered(false);
	m_message_Attribute_interaction->setContainment(false);
	m_message_Attribute_interaction->setResolveProxies(true);
	m_message_Attribute_interaction->setDefaultValueLiteral("");	
	m_message_Attribute_interaction->setEOpposite(uml::umlPackage::eInstance()->getInteraction_Attribute_message());
	
	m_message_Attribute_interaction->_setID(MESSAGE_ATTRIBUTE_INTERACTION);
	m_message_Attribute_receiveEvent->setName("receiveEvent");
	m_message_Attribute_receiveEvent->setEType(getMessageEnd_Class());
	m_message_Attribute_receiveEvent->setLowerBound(0);
	m_message_Attribute_receiveEvent->setUpperBound(1);
	m_message_Attribute_receiveEvent->setTransient(false);
	m_message_Attribute_receiveEvent->setVolatile(false);
	m_message_Attribute_receiveEvent->setChangeable(true);
	m_message_Attribute_receiveEvent->setUnsettable(false);
	m_message_Attribute_receiveEvent->setUnique(true);
	m_message_Attribute_receiveEvent->setDerived(false);
	m_message_Attribute_receiveEvent->setOrdered(false);
	m_message_Attribute_receiveEvent->setContainment(false);
	m_message_Attribute_receiveEvent->setResolveProxies(true);
	m_message_Attribute_receiveEvent->setDefaultValueLiteral("");	
	
	m_message_Attribute_receiveEvent->_setID(MESSAGE_ATTRIBUTE_RECEIVEEVENT);
	m_message_Attribute_sendEvent->setName("sendEvent");
	m_message_Attribute_sendEvent->setEType(getMessageEnd_Class());
	m_message_Attribute_sendEvent->setLowerBound(0);
	m_message_Attribute_sendEvent->setUpperBound(1);
	m_message_Attribute_sendEvent->setTransient(false);
	m_message_Attribute_sendEvent->setVolatile(false);
	m_message_Attribute_sendEvent->setChangeable(true);
	m_message_Attribute_sendEvent->setUnsettable(false);
	m_message_Attribute_sendEvent->setUnique(true);
	m_message_Attribute_sendEvent->setDerived(false);
	m_message_Attribute_sendEvent->setOrdered(false);
	m_message_Attribute_sendEvent->setContainment(false);
	m_message_Attribute_sendEvent->setResolveProxies(true);
	m_message_Attribute_sendEvent->setDefaultValueLiteral("");	
	
	m_message_Attribute_sendEvent->_setID(MESSAGE_ATTRIBUTE_SENDEVENT);
	m_message_Attribute_signature->setName("signature");
	m_message_Attribute_signature->setEType(getNamedElement_Class());
	m_message_Attribute_signature->setLowerBound(0);
	m_message_Attribute_signature->setUpperBound(1);
	m_message_Attribute_signature->setTransient(false);
	m_message_Attribute_signature->setVolatile(false);
	m_message_Attribute_signature->setChangeable(true);
	m_message_Attribute_signature->setUnsettable(false);
	m_message_Attribute_signature->setUnique(true);
	m_message_Attribute_signature->setDerived(false);
	m_message_Attribute_signature->setOrdered(false);
	m_message_Attribute_signature->setContainment(false);
	m_message_Attribute_signature->setResolveProxies(true);
	m_message_Attribute_signature->setDefaultValueLiteral("");	
	
	m_message_Attribute_signature->_setID(MESSAGE_ATTRIBUTE_SIGNATURE);
	
	/*
	 * EOperations
	 */
	m_message_Operation_getMessageKind->setName("getMessageKind");
	m_message_Operation_getMessageKind->setEType(getMessageKind_Class());
	m_message_Operation_getMessageKind->setLowerBound(1);
	m_message_Operation_getMessageKind->setUpperBound(1);
	m_message_Operation_getMessageKind->setUnique(true);
	m_message_Operation_getMessageKind->setOrdered(false);
	
	m_message_Operation_getMessageKind->_setID(MESSAGE_OPERATION_GETMESSAGEKIND);
	
	
	
}

void umlPackageImpl::initializeMessageEndContent()
{
	m_messageEnd_Class->setName("MessageEnd");
	m_messageEnd_Class->setAbstract(true);
	m_messageEnd_Class->setInterface(false);
	
	m_messageEnd_Class->_setID(MESSAGEEND_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_messageEnd_Attribute_message->setName("message");
	m_messageEnd_Attribute_message->setEType(getMessage_Class());
	m_messageEnd_Attribute_message->setLowerBound(0);
	m_messageEnd_Attribute_message->setUpperBound(1);
	m_messageEnd_Attribute_message->setTransient(false);
	m_messageEnd_Attribute_message->setVolatile(false);
	m_messageEnd_Attribute_message->setChangeable(true);
	m_messageEnd_Attribute_message->setUnsettable(false);
	m_messageEnd_Attribute_message->setUnique(true);
	m_messageEnd_Attribute_message->setDerived(false);
	m_messageEnd_Attribute_message->setOrdered(false);
	m_messageEnd_Attribute_message->setContainment(false);
	m_messageEnd_Attribute_message->setResolveProxies(true);
	m_messageEnd_Attribute_message->setDefaultValueLiteral("");	
	
	m_messageEnd_Attribute_message->_setID(MESSAGEEND_ATTRIBUTE_MESSAGE);
	
	/*
	 * EOperations
	 */
	m_messageEnd_Operation_enclosingFragment->setName("enclosingFragment");
	m_messageEnd_Operation_enclosingFragment->setEType(getInteractionFragment_Class());
	m_messageEnd_Operation_enclosingFragment->setLowerBound(0);
	m_messageEnd_Operation_enclosingFragment->setUpperBound(-1);
	m_messageEnd_Operation_enclosingFragment->setUnique(true);
	m_messageEnd_Operation_enclosingFragment->setOrdered(false);
	
	m_messageEnd_Operation_enclosingFragment->_setID(MESSAGEEND_OPERATION_ENCLOSINGFRAGMENT);
	
	
	m_messageEnd_Operation_isReceive->setName("isReceive");
	m_messageEnd_Operation_isReceive->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_messageEnd_Operation_isReceive->setLowerBound(1);
	m_messageEnd_Operation_isReceive->setUpperBound(1);
	m_messageEnd_Operation_isReceive->setUnique(true);
	m_messageEnd_Operation_isReceive->setOrdered(false);
	
	m_messageEnd_Operation_isReceive->_setID(MESSAGEEND_OPERATION_ISRECEIVE);
	
	
	m_messageEnd_Operation_isSend->setName("isSend");
	m_messageEnd_Operation_isSend->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_messageEnd_Operation_isSend->setLowerBound(1);
	m_messageEnd_Operation_isSend->setUpperBound(1);
	m_messageEnd_Operation_isSend->setUnique(true);
	m_messageEnd_Operation_isSend->setOrdered(false);
	
	m_messageEnd_Operation_isSend->_setID(MESSAGEEND_OPERATION_ISSEND);
	
	
	m_messageEnd_Operation_oppositeEnd->setName("oppositeEnd");
	m_messageEnd_Operation_oppositeEnd->setEType(getMessageEnd_Class());
	m_messageEnd_Operation_oppositeEnd->setLowerBound(0);
	m_messageEnd_Operation_oppositeEnd->setUpperBound(-1);
	m_messageEnd_Operation_oppositeEnd->setUnique(true);
	m_messageEnd_Operation_oppositeEnd->setOrdered(false);
	
	m_messageEnd_Operation_oppositeEnd->_setID(MESSAGEEND_OPERATION_OPPOSITEEND);
	
	
	
}

void umlPackageImpl::initializeMessageEventContent()
{
	m_messageEvent_Class->setName("MessageEvent");
	m_messageEvent_Class->setAbstract(true);
	m_messageEvent_Class->setInterface(false);
	
	m_messageEvent_Class->_setID(MESSAGEEVENT_CLASS);
	
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

void umlPackageImpl::initializeMessageOccurrenceSpecificationContent()
{
	m_messageOccurrenceSpecification_Class->setName("MessageOccurrenceSpecification");
	m_messageOccurrenceSpecification_Class->setAbstract(false);
	m_messageOccurrenceSpecification_Class->setInterface(false);
	
	m_messageOccurrenceSpecification_Class->_setID(MESSAGEOCCURRENCESPECIFICATION_CLASS);
	
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

void umlPackageImpl::initializeModelContent()
{
	m_model_Class->setName("Model");
	m_model_Class->setAbstract(false);
	m_model_Class->setInterface(false);
	
	m_model_Class->_setID(MODEL_CLASS);
	
	/*
	 * EAttributes
	 */
	m_model_Attribute_viewpoint = getModel_Attribute_viewpoint();
	m_model_Attribute_viewpoint->setName("viewpoint");
	m_model_Attribute_viewpoint->setEType(types::typesPackage::eInstance()->getString_Class());
	m_model_Attribute_viewpoint->setLowerBound(0);
	m_model_Attribute_viewpoint->setUpperBound(1);
	m_model_Attribute_viewpoint->setTransient(false);
	m_model_Attribute_viewpoint->setVolatile(false);
	m_model_Attribute_viewpoint->setChangeable(true);
	m_model_Attribute_viewpoint->setUnsettable(true);
	m_model_Attribute_viewpoint->setUnique(true);
	m_model_Attribute_viewpoint->setDerived(false);
	m_model_Attribute_viewpoint->setOrdered(false);
	m_model_Attribute_viewpoint->setID(false);
	m_model_Attribute_viewpoint->setDefaultValueLiteral("");
	
	m_model_Attribute_viewpoint->_setID(MODEL_ATTRIBUTE_VIEWPOINT);
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_model_Operation_isMetamodel->setName("isMetamodel");
	m_model_Operation_isMetamodel->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_model_Operation_isMetamodel->setLowerBound(1);
	m_model_Operation_isMetamodel->setUpperBound(1);
	m_model_Operation_isMetamodel->setUnique(true);
	m_model_Operation_isMetamodel->setOrdered(false);
	
	m_model_Operation_isMetamodel->_setID(MODEL_OPERATION_ISMETAMODEL);
	
	
	
}

void umlPackageImpl::initializeMultiplicityElementContent()
{
	m_multiplicityElement_Class->setName("MultiplicityElement");
	m_multiplicityElement_Class->setAbstract(true);
	m_multiplicityElement_Class->setInterface(false);
	
	m_multiplicityElement_Class->_setID(MULTIPLICITYELEMENT_CLASS);
	
	/*
	 * EAttributes
	 */
	m_multiplicityElement_Attribute_isOrdered = getMultiplicityElement_Attribute_isOrdered();
	m_multiplicityElement_Attribute_isOrdered->setName("isOrdered");
	m_multiplicityElement_Attribute_isOrdered->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_multiplicityElement_Attribute_isOrdered->setLowerBound(1);
	m_multiplicityElement_Attribute_isOrdered->setUpperBound(1);
	m_multiplicityElement_Attribute_isOrdered->setTransient(false);
	m_multiplicityElement_Attribute_isOrdered->setVolatile(false);
	m_multiplicityElement_Attribute_isOrdered->setChangeable(true);
	m_multiplicityElement_Attribute_isOrdered->setUnsettable(false);
	m_multiplicityElement_Attribute_isOrdered->setUnique(true);
	m_multiplicityElement_Attribute_isOrdered->setDerived(false);
	m_multiplicityElement_Attribute_isOrdered->setOrdered(false);
	m_multiplicityElement_Attribute_isOrdered->setID(false);
	m_multiplicityElement_Attribute_isOrdered->setDefaultValueLiteral("false");
	
	m_multiplicityElement_Attribute_isOrdered->_setID(MULTIPLICITYELEMENT_ATTRIBUTE_ISORDERED);
	m_multiplicityElement_Attribute_isUnique = getMultiplicityElement_Attribute_isUnique();
	m_multiplicityElement_Attribute_isUnique->setName("isUnique");
	m_multiplicityElement_Attribute_isUnique->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_multiplicityElement_Attribute_isUnique->setLowerBound(1);
	m_multiplicityElement_Attribute_isUnique->setUpperBound(1);
	m_multiplicityElement_Attribute_isUnique->setTransient(false);
	m_multiplicityElement_Attribute_isUnique->setVolatile(false);
	m_multiplicityElement_Attribute_isUnique->setChangeable(true);
	m_multiplicityElement_Attribute_isUnique->setUnsettable(false);
	m_multiplicityElement_Attribute_isUnique->setUnique(true);
	m_multiplicityElement_Attribute_isUnique->setDerived(false);
	m_multiplicityElement_Attribute_isUnique->setOrdered(false);
	m_multiplicityElement_Attribute_isUnique->setID(false);
	m_multiplicityElement_Attribute_isUnique->setDefaultValueLiteral("true");
	
	m_multiplicityElement_Attribute_isUnique->_setID(MULTIPLICITYELEMENT_ATTRIBUTE_ISUNIQUE);
	m_multiplicityElement_Attribute_lower = getMultiplicityElement_Attribute_lower();
	m_multiplicityElement_Attribute_lower->setName("lower");
	m_multiplicityElement_Attribute_lower->setEType(types::typesPackage::eInstance()->getInteger_Class());
	m_multiplicityElement_Attribute_lower->setLowerBound(0);
	m_multiplicityElement_Attribute_lower->setUpperBound(1);
	m_multiplicityElement_Attribute_lower->setTransient(true);
	m_multiplicityElement_Attribute_lower->setVolatile(true);
	m_multiplicityElement_Attribute_lower->setChangeable(true);
	m_multiplicityElement_Attribute_lower->setUnsettable(false);
	m_multiplicityElement_Attribute_lower->setUnique(true);
	m_multiplicityElement_Attribute_lower->setDerived(true);
	m_multiplicityElement_Attribute_lower->setOrdered(false);
	m_multiplicityElement_Attribute_lower->setID(false);
	m_multiplicityElement_Attribute_lower->setDefaultValueLiteral("1");
	
	m_multiplicityElement_Attribute_lower->_setID(MULTIPLICITYELEMENT_ATTRIBUTE_LOWER);
	m_multiplicityElement_Attribute_upper = getMultiplicityElement_Attribute_upper();
	m_multiplicityElement_Attribute_upper->setName("upper");
	m_multiplicityElement_Attribute_upper->setEType(types::typesPackage::eInstance()->getUnlimitedNatural_Class());
	m_multiplicityElement_Attribute_upper->setLowerBound(1);
	m_multiplicityElement_Attribute_upper->setUpperBound(1);
	m_multiplicityElement_Attribute_upper->setTransient(true);
	m_multiplicityElement_Attribute_upper->setVolatile(true);
	m_multiplicityElement_Attribute_upper->setChangeable(true);
	m_multiplicityElement_Attribute_upper->setUnsettable(false);
	m_multiplicityElement_Attribute_upper->setUnique(true);
	m_multiplicityElement_Attribute_upper->setDerived(true);
	m_multiplicityElement_Attribute_upper->setOrdered(false);
	m_multiplicityElement_Attribute_upper->setID(false);
	m_multiplicityElement_Attribute_upper->setDefaultValueLiteral("1");
	
	m_multiplicityElement_Attribute_upper->_setID(MULTIPLICITYELEMENT_ATTRIBUTE_UPPER);
	
	/*
	 * EReferences
	 */
	m_multiplicityElement_Attribute_lowerValue->setName("lowerValue");
	m_multiplicityElement_Attribute_lowerValue->setEType(getValueSpecification_Class());
	m_multiplicityElement_Attribute_lowerValue->setLowerBound(0);
	m_multiplicityElement_Attribute_lowerValue->setUpperBound(1);
	m_multiplicityElement_Attribute_lowerValue->setTransient(false);
	m_multiplicityElement_Attribute_lowerValue->setVolatile(false);
	m_multiplicityElement_Attribute_lowerValue->setChangeable(true);
	m_multiplicityElement_Attribute_lowerValue->setUnsettable(false);
	m_multiplicityElement_Attribute_lowerValue->setUnique(true);
	m_multiplicityElement_Attribute_lowerValue->setDerived(false);
	m_multiplicityElement_Attribute_lowerValue->setOrdered(false);
	m_multiplicityElement_Attribute_lowerValue->setContainment(true);
	m_multiplicityElement_Attribute_lowerValue->setResolveProxies(true);
	m_multiplicityElement_Attribute_lowerValue->setDefaultValueLiteral("");	
	
	m_multiplicityElement_Attribute_lowerValue->_setID(MULTIPLICITYELEMENT_ATTRIBUTE_LOWERVALUE);
	m_multiplicityElement_Attribute_upperValue->setName("upperValue");
	m_multiplicityElement_Attribute_upperValue->setEType(getValueSpecification_Class());
	m_multiplicityElement_Attribute_upperValue->setLowerBound(0);
	m_multiplicityElement_Attribute_upperValue->setUpperBound(1);
	m_multiplicityElement_Attribute_upperValue->setTransient(false);
	m_multiplicityElement_Attribute_upperValue->setVolatile(false);
	m_multiplicityElement_Attribute_upperValue->setChangeable(true);
	m_multiplicityElement_Attribute_upperValue->setUnsettable(false);
	m_multiplicityElement_Attribute_upperValue->setUnique(true);
	m_multiplicityElement_Attribute_upperValue->setDerived(false);
	m_multiplicityElement_Attribute_upperValue->setOrdered(false);
	m_multiplicityElement_Attribute_upperValue->setContainment(true);
	m_multiplicityElement_Attribute_upperValue->setResolveProxies(true);
	m_multiplicityElement_Attribute_upperValue->setDefaultValueLiteral("");	
	
	m_multiplicityElement_Attribute_upperValue->_setID(MULTIPLICITYELEMENT_ATTRIBUTE_UPPERVALUE);
	
	/*
	 * EOperations
	 */
	m_multiplicityElement_Operation_compatibleWith_MultiplicityElement->setName("compatibleWith");
	m_multiplicityElement_Operation_compatibleWith_MultiplicityElement->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_multiplicityElement_Operation_compatibleWith_MultiplicityElement->setLowerBound(1);
	m_multiplicityElement_Operation_compatibleWith_MultiplicityElement->setUpperBound(1);
	m_multiplicityElement_Operation_compatibleWith_MultiplicityElement->setUnique(true);
	m_multiplicityElement_Operation_compatibleWith_MultiplicityElement->setOrdered(false);
	
	m_multiplicityElement_Operation_compatibleWith_MultiplicityElement->_setID(MULTIPLICITYELEMENT_OPERATION_COMPATIBLEWITH_MULTIPLICITYELEMENT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_multiplicityElement_Operation_compatibleWith_MultiplicityElement);
		parameter->setName("other");
		parameter->setEType(getMultiplicityElement_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_multiplicityElement_Operation_includesMultiplicity_MultiplicityElement->setName("includesMultiplicity");
	m_multiplicityElement_Operation_includesMultiplicity_MultiplicityElement->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_multiplicityElement_Operation_includesMultiplicity_MultiplicityElement->setLowerBound(1);
	m_multiplicityElement_Operation_includesMultiplicity_MultiplicityElement->setUpperBound(1);
	m_multiplicityElement_Operation_includesMultiplicity_MultiplicityElement->setUnique(true);
	m_multiplicityElement_Operation_includesMultiplicity_MultiplicityElement->setOrdered(false);
	
	m_multiplicityElement_Operation_includesMultiplicity_MultiplicityElement->_setID(MULTIPLICITYELEMENT_OPERATION_INCLUDESMULTIPLICITY_MULTIPLICITYELEMENT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_multiplicityElement_Operation_includesMultiplicity_MultiplicityElement);
		parameter->setName("M");
		parameter->setEType(getMultiplicityElement_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_multiplicityElement_Operation_is_Integer_UnlimitedNatural->setName("is");
	m_multiplicityElement_Operation_is_Integer_UnlimitedNatural->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_multiplicityElement_Operation_is_Integer_UnlimitedNatural->setLowerBound(1);
	m_multiplicityElement_Operation_is_Integer_UnlimitedNatural->setUpperBound(1);
	m_multiplicityElement_Operation_is_Integer_UnlimitedNatural->setUnique(true);
	m_multiplicityElement_Operation_is_Integer_UnlimitedNatural->setOrdered(false);
	
	m_multiplicityElement_Operation_is_Integer_UnlimitedNatural->_setID(MULTIPLICITYELEMENT_OPERATION_IS_INTEGER_UNLIMITEDNATURAL);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_multiplicityElement_Operation_is_Integer_UnlimitedNatural);
		parameter->setName("lowerbound");
		parameter->setEType(types::typesPackage::eInstance()->getInteger_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_multiplicityElement_Operation_is_Integer_UnlimitedNatural);
		parameter->setName("upperbound");
		parameter->setEType(types::typesPackage::eInstance()->getUnlimitedNatural_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_multiplicityElement_Operation_isMultivalued->setName("isMultivalued");
	m_multiplicityElement_Operation_isMultivalued->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_multiplicityElement_Operation_isMultivalued->setLowerBound(1);
	m_multiplicityElement_Operation_isMultivalued->setUpperBound(1);
	m_multiplicityElement_Operation_isMultivalued->setUnique(true);
	m_multiplicityElement_Operation_isMultivalued->setOrdered(false);
	
	m_multiplicityElement_Operation_isMultivalued->_setID(MULTIPLICITYELEMENT_OPERATION_ISMULTIVALUED);
	
	
	m_multiplicityElement_Operation_lowerBound->setName("lowerBound");
	m_multiplicityElement_Operation_lowerBound->setEType(types::typesPackage::eInstance()->getInteger_Class());
	m_multiplicityElement_Operation_lowerBound->setLowerBound(0);
	m_multiplicityElement_Operation_lowerBound->setUpperBound(1);
	m_multiplicityElement_Operation_lowerBound->setUnique(true);
	m_multiplicityElement_Operation_lowerBound->setOrdered(false);
	
	m_multiplicityElement_Operation_lowerBound->_setID(MULTIPLICITYELEMENT_OPERATION_LOWERBOUND);
	
	
	m_multiplicityElement_Operation_upperBound->setName("upperBound");
	m_multiplicityElement_Operation_upperBound->setEType(types::typesPackage::eInstance()->getUnlimitedNatural_Class());
	m_multiplicityElement_Operation_upperBound->setLowerBound(1);
	m_multiplicityElement_Operation_upperBound->setUpperBound(1);
	m_multiplicityElement_Operation_upperBound->setUnique(true);
	m_multiplicityElement_Operation_upperBound->setOrdered(false);
	
	m_multiplicityElement_Operation_upperBound->_setID(MULTIPLICITYELEMENT_OPERATION_UPPERBOUND);
	
	
	
}

void umlPackageImpl::initializeNamedElementContent()
{
	m_namedElement_Class->setName("NamedElement");
	m_namedElement_Class->setAbstract(true);
	m_namedElement_Class->setInterface(false);
	
	m_namedElement_Class->_setID(NAMEDELEMENT_CLASS);
	
	/*
	 * EAttributes
	 */
	m_namedElement_Attribute_name = getNamedElement_Attribute_name();
	m_namedElement_Attribute_name->setName("name");
	m_namedElement_Attribute_name->setEType(types::typesPackage::eInstance()->getString_Class());
	m_namedElement_Attribute_name->setLowerBound(0);
	m_namedElement_Attribute_name->setUpperBound(1);
	m_namedElement_Attribute_name->setTransient(false);
	m_namedElement_Attribute_name->setVolatile(false);
	m_namedElement_Attribute_name->setChangeable(true);
	m_namedElement_Attribute_name->setUnsettable(true);
	m_namedElement_Attribute_name->setUnique(true);
	m_namedElement_Attribute_name->setDerived(false);
	m_namedElement_Attribute_name->setOrdered(false);
	m_namedElement_Attribute_name->setID(false);
	m_namedElement_Attribute_name->setDefaultValueLiteral("");
	
	m_namedElement_Attribute_name->_setID(NAMEDELEMENT_ATTRIBUTE_NAME);
	m_namedElement_Attribute_qualifiedName = getNamedElement_Attribute_qualifiedName();
	m_namedElement_Attribute_qualifiedName->setName("qualifiedName");
	m_namedElement_Attribute_qualifiedName->setEType(types::typesPackage::eInstance()->getString_Class());
	m_namedElement_Attribute_qualifiedName->setLowerBound(0);
	m_namedElement_Attribute_qualifiedName->setUpperBound(1);
	m_namedElement_Attribute_qualifiedName->setTransient(true);
	m_namedElement_Attribute_qualifiedName->setVolatile(true);
	m_namedElement_Attribute_qualifiedName->setChangeable(false);
	m_namedElement_Attribute_qualifiedName->setUnsettable(false);
	m_namedElement_Attribute_qualifiedName->setUnique(true);
	m_namedElement_Attribute_qualifiedName->setDerived(true);
	m_namedElement_Attribute_qualifiedName->setOrdered(false);
	m_namedElement_Attribute_qualifiedName->setID(false);
	m_namedElement_Attribute_qualifiedName->setDefaultValueLiteral("");
	
	m_namedElement_Attribute_qualifiedName->_setID(NAMEDELEMENT_ATTRIBUTE_QUALIFIEDNAME);
	m_namedElement_Attribute_visibility = getNamedElement_Attribute_visibility();
	m_namedElement_Attribute_visibility->setName("visibility");
	m_namedElement_Attribute_visibility->setEType(getVisibilityKind_Class());
	m_namedElement_Attribute_visibility->setLowerBound(0);
	m_namedElement_Attribute_visibility->setUpperBound(1);
	m_namedElement_Attribute_visibility->setTransient(false);
	m_namedElement_Attribute_visibility->setVolatile(false);
	m_namedElement_Attribute_visibility->setChangeable(true);
	m_namedElement_Attribute_visibility->setUnsettable(true);
	m_namedElement_Attribute_visibility->setUnique(true);
	m_namedElement_Attribute_visibility->setDerived(false);
	m_namedElement_Attribute_visibility->setOrdered(false);
	m_namedElement_Attribute_visibility->setID(false);
	m_namedElement_Attribute_visibility->setDefaultValueLiteral("");
	
	m_namedElement_Attribute_visibility->_setID(NAMEDELEMENT_ATTRIBUTE_VISIBILITY);
	
	/*
	 * EReferences
	 */
	m_namedElement_Attribute_clientDependency->setName("clientDependency");
	m_namedElement_Attribute_clientDependency->setEType(getDependency_Class());
	m_namedElement_Attribute_clientDependency->setLowerBound(0);
	m_namedElement_Attribute_clientDependency->setUpperBound(-1);
	m_namedElement_Attribute_clientDependency->setTransient(true);
	m_namedElement_Attribute_clientDependency->setVolatile(true);
	m_namedElement_Attribute_clientDependency->setChangeable(false);
	m_namedElement_Attribute_clientDependency->setUnsettable(false);
	m_namedElement_Attribute_clientDependency->setUnique(true);
	m_namedElement_Attribute_clientDependency->setDerived(true);
	m_namedElement_Attribute_clientDependency->setOrdered(false);
	m_namedElement_Attribute_clientDependency->setContainment(false);
	m_namedElement_Attribute_clientDependency->setResolveProxies(true);
	m_namedElement_Attribute_clientDependency->setDefaultValueLiteral("");	
	
	m_namedElement_Attribute_clientDependency->_setID(NAMEDELEMENT_ATTRIBUTE_CLIENTDEPENDENCY);
	m_namedElement_Attribute_nameExpression->setName("nameExpression");
	m_namedElement_Attribute_nameExpression->setEType(getStringExpression_Class());
	m_namedElement_Attribute_nameExpression->setLowerBound(0);
	m_namedElement_Attribute_nameExpression->setUpperBound(1);
	m_namedElement_Attribute_nameExpression->setTransient(false);
	m_namedElement_Attribute_nameExpression->setVolatile(false);
	m_namedElement_Attribute_nameExpression->setChangeable(true);
	m_namedElement_Attribute_nameExpression->setUnsettable(false);
	m_namedElement_Attribute_nameExpression->setUnique(true);
	m_namedElement_Attribute_nameExpression->setDerived(false);
	m_namedElement_Attribute_nameExpression->setOrdered(false);
	m_namedElement_Attribute_nameExpression->setContainment(true);
	m_namedElement_Attribute_nameExpression->setResolveProxies(true);
	m_namedElement_Attribute_nameExpression->setDefaultValueLiteral("");	
	
	m_namedElement_Attribute_nameExpression->_setID(NAMEDELEMENT_ATTRIBUTE_NAMEEXPRESSION);
	m_namedElement_Attribute_namespace->setName("namespace");
	m_namedElement_Attribute_namespace->setEType(getNamespace_Class());
	m_namedElement_Attribute_namespace->setLowerBound(0);
	m_namedElement_Attribute_namespace->setUpperBound(1);
	m_namedElement_Attribute_namespace->setTransient(true);
	m_namedElement_Attribute_namespace->setVolatile(true);
	m_namedElement_Attribute_namespace->setChangeable(false);
	m_namedElement_Attribute_namespace->setUnsettable(false);
	m_namedElement_Attribute_namespace->setUnique(true);
	m_namedElement_Attribute_namespace->setDerived(true);
	m_namedElement_Attribute_namespace->setOrdered(false);
	m_namedElement_Attribute_namespace->setContainment(false);
	m_namedElement_Attribute_namespace->setResolveProxies(true);
	m_namedElement_Attribute_namespace->setDefaultValueLiteral("");	
	m_namedElement_Attribute_namespace->setEOpposite(uml::umlPackage::eInstance()->getNamespace_Attribute_ownedMember());
	
	m_namedElement_Attribute_namespace->_setID(NAMEDELEMENT_ATTRIBUTE_NAMESPACE);
	
	/*
	 * EOperations
	 */
	m_namedElement_Operation_allNamespaces->setName("allNamespaces");
	m_namedElement_Operation_allNamespaces->setEType(getNamespace_Class());
	m_namedElement_Operation_allNamespaces->setLowerBound(0);
	m_namedElement_Operation_allNamespaces->setUpperBound(-1);
	m_namedElement_Operation_allNamespaces->setUnique(true);
	m_namedElement_Operation_allNamespaces->setOrdered(true);
	
	m_namedElement_Operation_allNamespaces->_setID(NAMEDELEMENT_OPERATION_ALLNAMESPACES);
	
	
	m_namedElement_Operation_allOwningPackages->setName("allOwningPackages");
	m_namedElement_Operation_allOwningPackages->setEType(getPackage_Class());
	m_namedElement_Operation_allOwningPackages->setLowerBound(0);
	m_namedElement_Operation_allOwningPackages->setUpperBound(-1);
	m_namedElement_Operation_allOwningPackages->setUnique(true);
	m_namedElement_Operation_allOwningPackages->setOrdered(false);
	
	m_namedElement_Operation_allOwningPackages->_setID(NAMEDELEMENT_OPERATION_ALLOWNINGPACKAGES);
	
	
	m_namedElement_Operation_createDependency_NamedElement->setName("createDependency");
	m_namedElement_Operation_createDependency_NamedElement->setEType(getDependency_Class());
	m_namedElement_Operation_createDependency_NamedElement->setLowerBound(1);
	m_namedElement_Operation_createDependency_NamedElement->setUpperBound(1);
	m_namedElement_Operation_createDependency_NamedElement->setUnique(true);
	m_namedElement_Operation_createDependency_NamedElement->setOrdered(false);
	
	m_namedElement_Operation_createDependency_NamedElement->_setID(NAMEDELEMENT_OPERATION_CREATEDEPENDENCY_NAMEDELEMENT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_namedElement_Operation_createDependency_NamedElement);
		parameter->setName("supplier");
		parameter->setEType(getNamedElement_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_namedElement_Operation_createUsage_NamedElement->setName("createUsage");
	m_namedElement_Operation_createUsage_NamedElement->setEType(getUsage_Class());
	m_namedElement_Operation_createUsage_NamedElement->setLowerBound(1);
	m_namedElement_Operation_createUsage_NamedElement->setUpperBound(1);
	m_namedElement_Operation_createUsage_NamedElement->setUnique(true);
	m_namedElement_Operation_createUsage_NamedElement->setOrdered(false);
	
	m_namedElement_Operation_createUsage_NamedElement->_setID(NAMEDELEMENT_OPERATION_CREATEUSAGE_NAMEDELEMENT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_namedElement_Operation_createUsage_NamedElement);
		parameter->setName("supplier");
		parameter->setEType(getNamedElement_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_namedElement_Operation_getClientDependencies->setName("getClientDependencies");
	m_namedElement_Operation_getClientDependencies->setEType(getDependency_Class());
	m_namedElement_Operation_getClientDependencies->setLowerBound(0);
	m_namedElement_Operation_getClientDependencies->setUpperBound(-1);
	m_namedElement_Operation_getClientDependencies->setUnique(true);
	m_namedElement_Operation_getClientDependencies->setOrdered(false);
	
	m_namedElement_Operation_getClientDependencies->_setID(NAMEDELEMENT_OPERATION_GETCLIENTDEPENDENCIES);
	
	
	m_namedElement_Operation_getLabel->setName("getLabel");
	m_namedElement_Operation_getLabel->setEType(types::typesPackage::eInstance()->getString_Class());
	m_namedElement_Operation_getLabel->setLowerBound(0);
	m_namedElement_Operation_getLabel->setUpperBound(1);
	m_namedElement_Operation_getLabel->setUnique(true);
	m_namedElement_Operation_getLabel->setOrdered(false);
	
	m_namedElement_Operation_getLabel->_setID(NAMEDELEMENT_OPERATION_GETLABEL);
	
	
	m_namedElement_Operation_getLabel_Boolean->setName("getLabel");
	m_namedElement_Operation_getLabel_Boolean->setEType(types::typesPackage::eInstance()->getString_Class());
	m_namedElement_Operation_getLabel_Boolean->setLowerBound(0);
	m_namedElement_Operation_getLabel_Boolean->setUpperBound(1);
	m_namedElement_Operation_getLabel_Boolean->setUnique(true);
	m_namedElement_Operation_getLabel_Boolean->setOrdered(false);
	
	m_namedElement_Operation_getLabel_Boolean->_setID(NAMEDELEMENT_OPERATION_GETLABEL_BOOLEAN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_namedElement_Operation_getLabel_Boolean);
		parameter->setName("localize");
		parameter->setEType(types::typesPackage::eInstance()->getBoolean_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_namedElement_Operation_getNamespace->setName("getNamespace");
	m_namedElement_Operation_getNamespace->setEType(getNamespace_Class());
	m_namedElement_Operation_getNamespace->setLowerBound(0);
	m_namedElement_Operation_getNamespace->setUpperBound(1);
	m_namedElement_Operation_getNamespace->setUnique(true);
	m_namedElement_Operation_getNamespace->setOrdered(false);
	
	m_namedElement_Operation_getNamespace->_setID(NAMEDELEMENT_OPERATION_GETNAMESPACE);
	
	
	m_namedElement_Operation_getQualifiedName->setName("getQualifiedName");
	m_namedElement_Operation_getQualifiedName->setEType(types::typesPackage::eInstance()->getString_Class());
	m_namedElement_Operation_getQualifiedName->setLowerBound(0);
	m_namedElement_Operation_getQualifiedName->setUpperBound(1);
	m_namedElement_Operation_getQualifiedName->setUnique(true);
	m_namedElement_Operation_getQualifiedName->setOrdered(false);
	
	m_namedElement_Operation_getQualifiedName->_setID(NAMEDELEMENT_OPERATION_GETQUALIFIEDNAME);
	
	
	m_namedElement_Operation_isDistinguishableFrom_NamedElement_Namespace->setName("isDistinguishableFrom");
	m_namedElement_Operation_isDistinguishableFrom_NamedElement_Namespace->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_namedElement_Operation_isDistinguishableFrom_NamedElement_Namespace->setLowerBound(1);
	m_namedElement_Operation_isDistinguishableFrom_NamedElement_Namespace->setUpperBound(1);
	m_namedElement_Operation_isDistinguishableFrom_NamedElement_Namespace->setUnique(true);
	m_namedElement_Operation_isDistinguishableFrom_NamedElement_Namespace->setOrdered(false);
	
	m_namedElement_Operation_isDistinguishableFrom_NamedElement_Namespace->_setID(NAMEDELEMENT_OPERATION_ISDISTINGUISHABLEFROM_NAMEDELEMENT_NAMESPACE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_namedElement_Operation_isDistinguishableFrom_NamedElement_Namespace);
		parameter->setName("n");
		parameter->setEType(getNamedElement_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_namedElement_Operation_isDistinguishableFrom_NamedElement_Namespace);
		parameter->setName("ns");
		parameter->setEType(getNamespace_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_namedElement_Operation_separator->setName("separator");
	m_namedElement_Operation_separator->setEType(types::typesPackage::eInstance()->getString_Class());
	m_namedElement_Operation_separator->setLowerBound(1);
	m_namedElement_Operation_separator->setUpperBound(1);
	m_namedElement_Operation_separator->setUnique(true);
	m_namedElement_Operation_separator->setOrdered(false);
	
	m_namedElement_Operation_separator->_setID(NAMEDELEMENT_OPERATION_SEPARATOR);
	
	
	
}

void umlPackageImpl::initializeNamespaceContent()
{
	m_namespace_Class->setName("Namespace");
	m_namespace_Class->setAbstract(true);
	m_namespace_Class->setInterface(false);
	
	m_namespace_Class->_setID(NAMESPACE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_namespace_Attribute_elementImport->setName("elementImport");
	m_namespace_Attribute_elementImport->setEType(getElementImport_Class());
	m_namespace_Attribute_elementImport->setLowerBound(0);
	m_namespace_Attribute_elementImport->setUpperBound(-1);
	m_namespace_Attribute_elementImport->setTransient(false);
	m_namespace_Attribute_elementImport->setVolatile(false);
	m_namespace_Attribute_elementImport->setChangeable(true);
	m_namespace_Attribute_elementImport->setUnsettable(false);
	m_namespace_Attribute_elementImport->setUnique(true);
	m_namespace_Attribute_elementImport->setDerived(false);
	m_namespace_Attribute_elementImport->setOrdered(false);
	m_namespace_Attribute_elementImport->setContainment(true);
	m_namespace_Attribute_elementImport->setResolveProxies(true);
	m_namespace_Attribute_elementImport->setDefaultValueLiteral("");	
	m_namespace_Attribute_elementImport->setEOpposite(uml::umlPackage::eInstance()->getElementImport_Attribute_importingNamespace());
	
	m_namespace_Attribute_elementImport->_setID(NAMESPACE_ATTRIBUTE_ELEMENTIMPORT);
	m_namespace_Attribute_importedMember->setName("importedMember");
	m_namespace_Attribute_importedMember->setEType(getPackageableElement_Class());
	m_namespace_Attribute_importedMember->setLowerBound(0);
	m_namespace_Attribute_importedMember->setUpperBound(-1);
	m_namespace_Attribute_importedMember->setTransient(true);
	m_namespace_Attribute_importedMember->setVolatile(true);
	m_namespace_Attribute_importedMember->setChangeable(false);
	m_namespace_Attribute_importedMember->setUnsettable(false);
	m_namespace_Attribute_importedMember->setUnique(true);
	m_namespace_Attribute_importedMember->setDerived(true);
	m_namespace_Attribute_importedMember->setOrdered(false);
	m_namespace_Attribute_importedMember->setContainment(false);
	m_namespace_Attribute_importedMember->setResolveProxies(true);
	m_namespace_Attribute_importedMember->setDefaultValueLiteral("");	
	
	m_namespace_Attribute_importedMember->_setID(NAMESPACE_ATTRIBUTE_IMPORTEDMEMBER);
	m_namespace_Attribute_member->setName("member");
	m_namespace_Attribute_member->setEType(getNamedElement_Class());
	m_namespace_Attribute_member->setLowerBound(0);
	m_namespace_Attribute_member->setUpperBound(-1);
	m_namespace_Attribute_member->setTransient(true);
	m_namespace_Attribute_member->setVolatile(true);
	m_namespace_Attribute_member->setChangeable(false);
	m_namespace_Attribute_member->setUnsettable(false);
	m_namespace_Attribute_member->setUnique(true);
	m_namespace_Attribute_member->setDerived(true);
	m_namespace_Attribute_member->setOrdered(false);
	m_namespace_Attribute_member->setContainment(false);
	m_namespace_Attribute_member->setResolveProxies(true);
	m_namespace_Attribute_member->setDefaultValueLiteral("");	
	
	m_namespace_Attribute_member->_setID(NAMESPACE_ATTRIBUTE_MEMBER);
	m_namespace_Attribute_ownedMember->setName("ownedMember");
	m_namespace_Attribute_ownedMember->setEType(getNamedElement_Class());
	m_namespace_Attribute_ownedMember->setLowerBound(0);
	m_namespace_Attribute_ownedMember->setUpperBound(-1);
	m_namespace_Attribute_ownedMember->setTransient(true);
	m_namespace_Attribute_ownedMember->setVolatile(true);
	m_namespace_Attribute_ownedMember->setChangeable(false);
	m_namespace_Attribute_ownedMember->setUnsettable(false);
	m_namespace_Attribute_ownedMember->setUnique(true);
	m_namespace_Attribute_ownedMember->setDerived(true);
	m_namespace_Attribute_ownedMember->setOrdered(false);
	m_namespace_Attribute_ownedMember->setContainment(true);
	m_namespace_Attribute_ownedMember->setResolveProxies(true);
	m_namespace_Attribute_ownedMember->setDefaultValueLiteral("");	
	m_namespace_Attribute_ownedMember->setEOpposite(uml::umlPackage::eInstance()->getNamedElement_Attribute_namespace());
	
	m_namespace_Attribute_ownedMember->_setID(NAMESPACE_ATTRIBUTE_OWNEDMEMBER);
	m_namespace_Attribute_ownedRule->setName("ownedRule");
	m_namespace_Attribute_ownedRule->setEType(getConstraint_Class());
	m_namespace_Attribute_ownedRule->setLowerBound(0);
	m_namespace_Attribute_ownedRule->setUpperBound(-1);
	m_namespace_Attribute_ownedRule->setTransient(false);
	m_namespace_Attribute_ownedRule->setVolatile(false);
	m_namespace_Attribute_ownedRule->setChangeable(true);
	m_namespace_Attribute_ownedRule->setUnsettable(false);
	m_namespace_Attribute_ownedRule->setUnique(true);
	m_namespace_Attribute_ownedRule->setDerived(false);
	m_namespace_Attribute_ownedRule->setOrdered(false);
	m_namespace_Attribute_ownedRule->setContainment(true);
	m_namespace_Attribute_ownedRule->setResolveProxies(true);
	m_namespace_Attribute_ownedRule->setDefaultValueLiteral("");	
	m_namespace_Attribute_ownedRule->setEOpposite(uml::umlPackage::eInstance()->getConstraint_Attribute_context());
	
	m_namespace_Attribute_ownedRule->_setID(NAMESPACE_ATTRIBUTE_OWNEDRULE);
	m_namespace_Attribute_packageImport->setName("packageImport");
	m_namespace_Attribute_packageImport->setEType(getPackageImport_Class());
	m_namespace_Attribute_packageImport->setLowerBound(0);
	m_namespace_Attribute_packageImport->setUpperBound(-1);
	m_namespace_Attribute_packageImport->setTransient(false);
	m_namespace_Attribute_packageImport->setVolatile(false);
	m_namespace_Attribute_packageImport->setChangeable(true);
	m_namespace_Attribute_packageImport->setUnsettable(false);
	m_namespace_Attribute_packageImport->setUnique(true);
	m_namespace_Attribute_packageImport->setDerived(false);
	m_namespace_Attribute_packageImport->setOrdered(false);
	m_namespace_Attribute_packageImport->setContainment(true);
	m_namespace_Attribute_packageImport->setResolveProxies(true);
	m_namespace_Attribute_packageImport->setDefaultValueLiteral("");	
	m_namespace_Attribute_packageImport->setEOpposite(uml::umlPackage::eInstance()->getPackageImport_Attribute_importingNamespace());
	
	m_namespace_Attribute_packageImport->_setID(NAMESPACE_ATTRIBUTE_PACKAGEIMPORT);
	
	/*
	 * EOperations
	 */
	m_namespace_Operation_createElementImport_PackageableElement_VisibilityKind->setName("createElementImport");
	m_namespace_Operation_createElementImport_PackageableElement_VisibilityKind->setEType(getElementImport_Class());
	m_namespace_Operation_createElementImport_PackageableElement_VisibilityKind->setLowerBound(1);
	m_namespace_Operation_createElementImport_PackageableElement_VisibilityKind->setUpperBound(1);
	m_namespace_Operation_createElementImport_PackageableElement_VisibilityKind->setUnique(true);
	m_namespace_Operation_createElementImport_PackageableElement_VisibilityKind->setOrdered(false);
	
	m_namespace_Operation_createElementImport_PackageableElement_VisibilityKind->_setID(NAMESPACE_OPERATION_CREATEELEMENTIMPORT_PACKAGEABLEELEMENT_VISIBILITYKIND);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_namespace_Operation_createElementImport_PackageableElement_VisibilityKind);
		parameter->setName("element");
		parameter->setEType(getPackageableElement_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_namespace_Operation_createElementImport_PackageableElement_VisibilityKind);
		parameter->setName("visibility");
		parameter->setEType(getVisibilityKind_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_namespace_Operation_createPackageImport_Package_VisibilityKind->setName("createPackageImport");
	m_namespace_Operation_createPackageImport_Package_VisibilityKind->setEType(getPackageImport_Class());
	m_namespace_Operation_createPackageImport_Package_VisibilityKind->setLowerBound(1);
	m_namespace_Operation_createPackageImport_Package_VisibilityKind->setUpperBound(1);
	m_namespace_Operation_createPackageImport_Package_VisibilityKind->setUnique(true);
	m_namespace_Operation_createPackageImport_Package_VisibilityKind->setOrdered(false);
	
	m_namespace_Operation_createPackageImport_Package_VisibilityKind->_setID(NAMESPACE_OPERATION_CREATEPACKAGEIMPORT_PACKAGE_VISIBILITYKIND);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_namespace_Operation_createPackageImport_Package_VisibilityKind);
		parameter->setName("package_");
		parameter->setEType(getPackage_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_namespace_Operation_createPackageImport_Package_VisibilityKind);
		parameter->setName("visibility");
		parameter->setEType(getVisibilityKind_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_namespace_Operation_excludeCollisions_PackageableElement->setName("excludeCollisions");
	m_namespace_Operation_excludeCollisions_PackageableElement->setEType(getPackageableElement_Class());
	m_namespace_Operation_excludeCollisions_PackageableElement->setLowerBound(0);
	m_namespace_Operation_excludeCollisions_PackageableElement->setUpperBound(-1);
	m_namespace_Operation_excludeCollisions_PackageableElement->setUnique(true);
	m_namespace_Operation_excludeCollisions_PackageableElement->setOrdered(false);
	
	m_namespace_Operation_excludeCollisions_PackageableElement->_setID(NAMESPACE_OPERATION_EXCLUDECOLLISIONS_PACKAGEABLEELEMENT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_namespace_Operation_excludeCollisions_PackageableElement);
		parameter->setName("imps");
		parameter->setEType(getPackageableElement_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_namespace_Operation_getImportedElements->setName("getImportedElements");
	m_namespace_Operation_getImportedElements->setEType(getPackageableElement_Class());
	m_namespace_Operation_getImportedElements->setLowerBound(0);
	m_namespace_Operation_getImportedElements->setUpperBound(-1);
	m_namespace_Operation_getImportedElements->setUnique(true);
	m_namespace_Operation_getImportedElements->setOrdered(false);
	
	m_namespace_Operation_getImportedElements->_setID(NAMESPACE_OPERATION_GETIMPORTEDELEMENTS);
	
	
	m_namespace_Operation_getImportedMembers->setName("getImportedMembers");
	m_namespace_Operation_getImportedMembers->setEType(getPackageableElement_Class());
	m_namespace_Operation_getImportedMembers->setLowerBound(0);
	m_namespace_Operation_getImportedMembers->setUpperBound(-1);
	m_namespace_Operation_getImportedMembers->setUnique(true);
	m_namespace_Operation_getImportedMembers->setOrdered(false);
	
	m_namespace_Operation_getImportedMembers->_setID(NAMESPACE_OPERATION_GETIMPORTEDMEMBERS);
	
	
	m_namespace_Operation_getImportedPackages->setName("getImportedPackages");
	m_namespace_Operation_getImportedPackages->setEType(getPackage_Class());
	m_namespace_Operation_getImportedPackages->setLowerBound(0);
	m_namespace_Operation_getImportedPackages->setUpperBound(-1);
	m_namespace_Operation_getImportedPackages->setUnique(true);
	m_namespace_Operation_getImportedPackages->setOrdered(false);
	
	m_namespace_Operation_getImportedPackages->_setID(NAMESPACE_OPERATION_GETIMPORTEDPACKAGES);
	
	
	m_namespace_Operation_getNamesOfMember_NamedElement->setName("getNamesOfMember");
	m_namespace_Operation_getNamesOfMember_NamedElement->setEType(types::typesPackage::eInstance()->getString_Class());
	m_namespace_Operation_getNamesOfMember_NamedElement->setLowerBound(0);
	m_namespace_Operation_getNamesOfMember_NamedElement->setUpperBound(-1);
	m_namespace_Operation_getNamesOfMember_NamedElement->setUnique(true);
	m_namespace_Operation_getNamesOfMember_NamedElement->setOrdered(false);
	
	m_namespace_Operation_getNamesOfMember_NamedElement->_setID(NAMESPACE_OPERATION_GETNAMESOFMEMBER_NAMEDELEMENT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_namespace_Operation_getNamesOfMember_NamedElement);
		parameter->setName("element");
		parameter->setEType(getNamedElement_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_namespace_Operation_getOwnedMembers->setName("getOwnedMembers");
	m_namespace_Operation_getOwnedMembers->setEType(getNamedElement_Class());
	m_namespace_Operation_getOwnedMembers->setLowerBound(0);
	m_namespace_Operation_getOwnedMembers->setUpperBound(-1);
	m_namespace_Operation_getOwnedMembers->setUnique(true);
	m_namespace_Operation_getOwnedMembers->setOrdered(false);
	
	m_namespace_Operation_getOwnedMembers->_setID(NAMESPACE_OPERATION_GETOWNEDMEMBERS);
	
	
	m_namespace_Operation_importMembers_PackageableElement->setName("importMembers");
	m_namespace_Operation_importMembers_PackageableElement->setEType(getPackageableElement_Class());
	m_namespace_Operation_importMembers_PackageableElement->setLowerBound(0);
	m_namespace_Operation_importMembers_PackageableElement->setUpperBound(-1);
	m_namespace_Operation_importMembers_PackageableElement->setUnique(true);
	m_namespace_Operation_importMembers_PackageableElement->setOrdered(false);
	
	m_namespace_Operation_importMembers_PackageableElement->_setID(NAMESPACE_OPERATION_IMPORTMEMBERS_PACKAGEABLEELEMENT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_namespace_Operation_importMembers_PackageableElement);
		parameter->setName("imps");
		parameter->setEType(getPackageableElement_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_namespace_Operation_membersAreDistinguishable->setName("membersAreDistinguishable");
	m_namespace_Operation_membersAreDistinguishable->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_namespace_Operation_membersAreDistinguishable->setLowerBound(1);
	m_namespace_Operation_membersAreDistinguishable->setUpperBound(1);
	m_namespace_Operation_membersAreDistinguishable->setUnique(true);
	m_namespace_Operation_membersAreDistinguishable->setOrdered(false);
	
	m_namespace_Operation_membersAreDistinguishable->_setID(NAMESPACE_OPERATION_MEMBERSAREDISTINGUISHABLE);
	
	
	
}

void umlPackageImpl::initializeNodeContent()
{
	m_node_Class->setName("Node");
	m_node_Class->setAbstract(false);
	m_node_Class->setInterface(false);
	
	m_node_Class->_setID(NODE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_node_Attribute_nestedNode->setName("nestedNode");
	m_node_Attribute_nestedNode->setEType(getNode_Class());
	m_node_Attribute_nestedNode->setLowerBound(0);
	m_node_Attribute_nestedNode->setUpperBound(-1);
	m_node_Attribute_nestedNode->setTransient(false);
	m_node_Attribute_nestedNode->setVolatile(false);
	m_node_Attribute_nestedNode->setChangeable(true);
	m_node_Attribute_nestedNode->setUnsettable(false);
	m_node_Attribute_nestedNode->setUnique(true);
	m_node_Attribute_nestedNode->setDerived(false);
	m_node_Attribute_nestedNode->setOrdered(false);
	m_node_Attribute_nestedNode->setContainment(true);
	m_node_Attribute_nestedNode->setResolveProxies(true);
	m_node_Attribute_nestedNode->setDefaultValueLiteral("");	
	
	m_node_Attribute_nestedNode->_setID(NODE_ATTRIBUTE_NESTEDNODE);
	
	/*
	 * EOperations
	 */
	m_node_Operation_createCommunicationPath_Boolean_UnlimitedNatural->setName("createCommunicationPath");
	m_node_Operation_createCommunicationPath_Boolean_UnlimitedNatural->setEType(getCommunicationPath_Class());
	m_node_Operation_createCommunicationPath_Boolean_UnlimitedNatural->setLowerBound(1);
	m_node_Operation_createCommunicationPath_Boolean_UnlimitedNatural->setUpperBound(1);
	m_node_Operation_createCommunicationPath_Boolean_UnlimitedNatural->setUnique(true);
	m_node_Operation_createCommunicationPath_Boolean_UnlimitedNatural->setOrdered(false);
	
	m_node_Operation_createCommunicationPath_Boolean_UnlimitedNatural->_setID(NODE_OPERATION_CREATECOMMUNICATIONPATH_BOOLEAN_UNLIMITEDNATURAL);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_node_Operation_createCommunicationPath_Boolean_UnlimitedNatural);
		parameter->setName("end1IsNavigable");
		parameter->setEType(types::typesPackage::eInstance()->getBoolean_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_node_Operation_createCommunicationPath_Boolean_UnlimitedNatural);
		parameter->setName("end1Aggregation");
		parameter->setEType(getAggregationKind_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_node_Operation_createCommunicationPath_Boolean_UnlimitedNatural);
		parameter->setName("end1Name");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_node_Operation_createCommunicationPath_Boolean_UnlimitedNatural);
		parameter->setName("end1Lower");
		parameter->setEType(types::typesPackage::eInstance()->getInteger_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_node_Operation_createCommunicationPath_Boolean_UnlimitedNatural);
		parameter->setName("end1Upper");
		parameter->setEType(types::typesPackage::eInstance()->getUnlimitedNatural_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_node_Operation_createCommunicationPath_Boolean_UnlimitedNatural);
		parameter->setName("end1Node");
		parameter->setEType(getNode_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_node_Operation_createCommunicationPath_Boolean_UnlimitedNatural);
		parameter->setName("end2IsNavigable");
		parameter->setEType(types::typesPackage::eInstance()->getBoolean_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_node_Operation_createCommunicationPath_Boolean_UnlimitedNatural);
		parameter->setName("end2Aggregation");
		parameter->setEType(getAggregationKind_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_node_Operation_createCommunicationPath_Boolean_UnlimitedNatural);
		parameter->setName("end2Name");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_node_Operation_createCommunicationPath_Boolean_UnlimitedNatural);
		parameter->setName("end2Lower");
		parameter->setEType(types::typesPackage::eInstance()->getInteger_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_node_Operation_createCommunicationPath_Boolean_UnlimitedNatural);
		parameter->setName("end2Upper");
		parameter->setEType(types::typesPackage::eInstance()->getUnlimitedNatural_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_node_Operation_getCommunicationPaths->setName("getCommunicationPaths");
	m_node_Operation_getCommunicationPaths->setEType(getCommunicationPath_Class());
	m_node_Operation_getCommunicationPaths->setLowerBound(0);
	m_node_Operation_getCommunicationPaths->setUpperBound(-1);
	m_node_Operation_getCommunicationPaths->setUnique(true);
	m_node_Operation_getCommunicationPaths->setOrdered(false);
	
	m_node_Operation_getCommunicationPaths->_setID(NODE_OPERATION_GETCOMMUNICATIONPATHS);
	
	
	
}

void umlPackageImpl::initializeObjectContent()
{
	m_object_Class->setName("Object");
	m_object_Class->setAbstract(false);
	m_object_Class->setInterface(false);
	
	m_object_Class->_setID(OBJECT_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	m_object_Operation_add_Property_EJavaObject->setName("add");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_object_Operation_add_Property_EJavaObject->setEType(unknownClass);
	}
	m_object_Operation_add_Property_EJavaObject->setLowerBound(0);
	m_object_Operation_add_Property_EJavaObject->setUpperBound(1);
	m_object_Operation_add_Property_EJavaObject->setUnique(true);
	m_object_Operation_add_Property_EJavaObject->setOrdered(true);
	
	m_object_Operation_add_Property_EJavaObject->_setID(OBJECT_OPERATION_ADD_PROPERTY_EJAVAOBJECT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_object_Operation_add_Property_EJavaObject);
		parameter->setName("_property");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_object_Operation_add_Property_EJavaObject);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_object_Operation_add_Property_EInt->setName("add");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_object_Operation_add_Property_EInt->setEType(unknownClass);
	}
	m_object_Operation_add_Property_EInt->setLowerBound(0);
	m_object_Operation_add_Property_EInt->setUpperBound(1);
	m_object_Operation_add_Property_EInt->setUnique(true);
	m_object_Operation_add_Property_EInt->setOrdered(true);
	
	m_object_Operation_add_Property_EInt->_setID(OBJECT_OPERATION_ADD_PROPERTY_EINT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_object_Operation_add_Property_EInt);
		parameter->setName("_property");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_object_Operation_add_Property_EInt);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_object_Operation_add_Property_EInt);
		parameter->setName("insertAt");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_object_Operation_destroy->setName("destroy");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_object_Operation_destroy->setEType(unknownClass);
	}
	m_object_Operation_destroy->setLowerBound(0);
	m_object_Operation_destroy->setUpperBound(1);
	m_object_Operation_destroy->setUnique(true);
	m_object_Operation_destroy->setOrdered(true);
	
	m_object_Operation_destroy->_setID(OBJECT_OPERATION_DESTROY);
	
	
	m_object_Operation_get_Property->setName("get");
	m_object_Operation_get_Property->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_object_Operation_get_Property->setLowerBound(0);
	m_object_Operation_get_Property->setUpperBound(1);
	m_object_Operation_get_Property->setUnique(true);
	m_object_Operation_get_Property->setOrdered(true);
	
	m_object_Operation_get_Property->_setID(OBJECT_OPERATION_GET_PROPERTY);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_object_Operation_get_Property);
		parameter->setName("_property");
		parameter->setEType(getProperty_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_object_Operation_invoke_Operation_EJavaObject->setName("invoke");
	m_object_Operation_invoke_Operation_EJavaObject->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_object_Operation_invoke_Operation_EJavaObject->setLowerBound(0);
	m_object_Operation_invoke_Operation_EJavaObject->setUpperBound(1);
	m_object_Operation_invoke_Operation_EJavaObject->setUnique(true);
	m_object_Operation_invoke_Operation_EJavaObject->setOrdered(true);
	
	m_object_Operation_invoke_Operation_EJavaObject->_setID(OBJECT_OPERATION_INVOKE_OPERATION_EJAVAOBJECT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_object_Operation_invoke_Operation_EJavaObject);
		parameter->setName("_operation");
		parameter->setEType(getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_object_Operation_invoke_Operation_EJavaObject);
		parameter->setName("inputArguments");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_object_Operation_invoke_Operation_EJavaObject);
		parameter->setName("outputArguments");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_object_Operation_invoke_OpaqueBehavior_EJavaObject->setName("invoke");
	m_object_Operation_invoke_OpaqueBehavior_EJavaObject->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
	m_object_Operation_invoke_OpaqueBehavior_EJavaObject->setLowerBound(0);
	m_object_Operation_invoke_OpaqueBehavior_EJavaObject->setUpperBound(1);
	m_object_Operation_invoke_OpaqueBehavior_EJavaObject->setUnique(true);
	m_object_Operation_invoke_OpaqueBehavior_EJavaObject->setOrdered(true);
	
	m_object_Operation_invoke_OpaqueBehavior_EJavaObject->_setID(OBJECT_OPERATION_INVOKE_OPAQUEBEHAVIOR_EJAVAOBJECT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_object_Operation_invoke_OpaqueBehavior_EJavaObject);
		parameter->setName("_opaqueBehavior");
		parameter->setEType(getOpaqueBehavior_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_object_Operation_invoke_OpaqueBehavior_EJavaObject);
		parameter->setName("inputArguments");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_object_Operation_invoke_OpaqueBehavior_EJavaObject);
		parameter->setName("outputArguments");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEJavaObject_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_object_Operation_remove_Property_EJavaObject->setName("remove");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_object_Operation_remove_Property_EJavaObject->setEType(unknownClass);
	}
	m_object_Operation_remove_Property_EJavaObject->setLowerBound(0);
	m_object_Operation_remove_Property_EJavaObject->setUpperBound(1);
	m_object_Operation_remove_Property_EJavaObject->setUnique(true);
	m_object_Operation_remove_Property_EJavaObject->setOrdered(true);
	
	m_object_Operation_remove_Property_EJavaObject->_setID(OBJECT_OPERATION_REMOVE_PROPERTY_EJAVAOBJECT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_object_Operation_remove_Property_EJavaObject);
		parameter->setName("_property");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_object_Operation_remove_Property_EJavaObject);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_object_Operation_set_Property_EJavaObject->setName("set");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_object_Operation_set_Property_EJavaObject->setEType(unknownClass);
	}
	m_object_Operation_set_Property_EJavaObject->setLowerBound(0);
	m_object_Operation_set_Property_EJavaObject->setUpperBound(1);
	m_object_Operation_set_Property_EJavaObject->setUnique(true);
	m_object_Operation_set_Property_EJavaObject->setOrdered(true);
	
	m_object_Operation_set_Property_EJavaObject->_setID(OBJECT_OPERATION_SET_PROPERTY_EJAVAOBJECT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_object_Operation_set_Property_EJavaObject);
		parameter->setName("_property");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_object_Operation_set_Property_EJavaObject);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_object_Operation_unset_Property->setName("unset");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_object_Operation_unset_Property->setEType(unknownClass);
	}
	m_object_Operation_unset_Property->setLowerBound(0);
	m_object_Operation_unset_Property->setUpperBound(1);
	m_object_Operation_unset_Property->setUnique(true);
	m_object_Operation_unset_Property->setOrdered(true);
	
	m_object_Operation_unset_Property->_setID(OBJECT_OPERATION_UNSET_PROPERTY);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_object_Operation_unset_Property);
		parameter->setName("_property");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void umlPackageImpl::initializeObjectFlowContent()
{
	m_objectFlow_Class->setName("ObjectFlow");
	m_objectFlow_Class->setAbstract(false);
	m_objectFlow_Class->setInterface(false);
	
	m_objectFlow_Class->_setID(OBJECTFLOW_CLASS);
	
	/*
	 * EAttributes
	 */
	m_objectFlow_Attribute_isMulticast = getObjectFlow_Attribute_isMulticast();
	m_objectFlow_Attribute_isMulticast->setName("isMulticast");
	m_objectFlow_Attribute_isMulticast->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_objectFlow_Attribute_isMulticast->setLowerBound(1);
	m_objectFlow_Attribute_isMulticast->setUpperBound(1);
	m_objectFlow_Attribute_isMulticast->setTransient(false);
	m_objectFlow_Attribute_isMulticast->setVolatile(false);
	m_objectFlow_Attribute_isMulticast->setChangeable(true);
	m_objectFlow_Attribute_isMulticast->setUnsettable(false);
	m_objectFlow_Attribute_isMulticast->setUnique(true);
	m_objectFlow_Attribute_isMulticast->setDerived(false);
	m_objectFlow_Attribute_isMulticast->setOrdered(false);
	m_objectFlow_Attribute_isMulticast->setID(false);
	m_objectFlow_Attribute_isMulticast->setDefaultValueLiteral("false");
	
	m_objectFlow_Attribute_isMulticast->_setID(OBJECTFLOW_ATTRIBUTE_ISMULTICAST);
	m_objectFlow_Attribute_isMultireceive = getObjectFlow_Attribute_isMultireceive();
	m_objectFlow_Attribute_isMultireceive->setName("isMultireceive");
	m_objectFlow_Attribute_isMultireceive->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_objectFlow_Attribute_isMultireceive->setLowerBound(1);
	m_objectFlow_Attribute_isMultireceive->setUpperBound(1);
	m_objectFlow_Attribute_isMultireceive->setTransient(false);
	m_objectFlow_Attribute_isMultireceive->setVolatile(false);
	m_objectFlow_Attribute_isMultireceive->setChangeable(true);
	m_objectFlow_Attribute_isMultireceive->setUnsettable(false);
	m_objectFlow_Attribute_isMultireceive->setUnique(true);
	m_objectFlow_Attribute_isMultireceive->setDerived(false);
	m_objectFlow_Attribute_isMultireceive->setOrdered(false);
	m_objectFlow_Attribute_isMultireceive->setID(false);
	m_objectFlow_Attribute_isMultireceive->setDefaultValueLiteral("false");
	
	m_objectFlow_Attribute_isMultireceive->_setID(OBJECTFLOW_ATTRIBUTE_ISMULTIRECEIVE);
	
	/*
	 * EReferences
	 */
	m_objectFlow_Attribute_selection->setName("selection");
	m_objectFlow_Attribute_selection->setEType(getBehavior_Class());
	m_objectFlow_Attribute_selection->setLowerBound(0);
	m_objectFlow_Attribute_selection->setUpperBound(1);
	m_objectFlow_Attribute_selection->setTransient(false);
	m_objectFlow_Attribute_selection->setVolatile(false);
	m_objectFlow_Attribute_selection->setChangeable(true);
	m_objectFlow_Attribute_selection->setUnsettable(false);
	m_objectFlow_Attribute_selection->setUnique(true);
	m_objectFlow_Attribute_selection->setDerived(false);
	m_objectFlow_Attribute_selection->setOrdered(false);
	m_objectFlow_Attribute_selection->setContainment(false);
	m_objectFlow_Attribute_selection->setResolveProxies(true);
	m_objectFlow_Attribute_selection->setDefaultValueLiteral("");	
	
	m_objectFlow_Attribute_selection->_setID(OBJECTFLOW_ATTRIBUTE_SELECTION);
	m_objectFlow_Attribute_transformation->setName("transformation");
	m_objectFlow_Attribute_transformation->setEType(getBehavior_Class());
	m_objectFlow_Attribute_transformation->setLowerBound(0);
	m_objectFlow_Attribute_transformation->setUpperBound(1);
	m_objectFlow_Attribute_transformation->setTransient(false);
	m_objectFlow_Attribute_transformation->setVolatile(false);
	m_objectFlow_Attribute_transformation->setChangeable(true);
	m_objectFlow_Attribute_transformation->setUnsettable(false);
	m_objectFlow_Attribute_transformation->setUnique(true);
	m_objectFlow_Attribute_transformation->setDerived(false);
	m_objectFlow_Attribute_transformation->setOrdered(false);
	m_objectFlow_Attribute_transformation->setContainment(false);
	m_objectFlow_Attribute_transformation->setResolveProxies(true);
	m_objectFlow_Attribute_transformation->setDefaultValueLiteral("");	
	
	m_objectFlow_Attribute_transformation->_setID(OBJECTFLOW_ATTRIBUTE_TRANSFORMATION);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeObjectNodeContent()
{
	m_objectNode_Class->setName("ObjectNode");
	m_objectNode_Class->setAbstract(true);
	m_objectNode_Class->setInterface(false);
	
	m_objectNode_Class->_setID(OBJECTNODE_CLASS);
	
	/*
	 * EAttributes
	 */
	m_objectNode_Attribute_isControlType = getObjectNode_Attribute_isControlType();
	m_objectNode_Attribute_isControlType->setName("isControlType");
	m_objectNode_Attribute_isControlType->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_objectNode_Attribute_isControlType->setLowerBound(1);
	m_objectNode_Attribute_isControlType->setUpperBound(1);
	m_objectNode_Attribute_isControlType->setTransient(false);
	m_objectNode_Attribute_isControlType->setVolatile(false);
	m_objectNode_Attribute_isControlType->setChangeable(true);
	m_objectNode_Attribute_isControlType->setUnsettable(false);
	m_objectNode_Attribute_isControlType->setUnique(true);
	m_objectNode_Attribute_isControlType->setDerived(false);
	m_objectNode_Attribute_isControlType->setOrdered(false);
	m_objectNode_Attribute_isControlType->setID(false);
	m_objectNode_Attribute_isControlType->setDefaultValueLiteral("false");
	
	m_objectNode_Attribute_isControlType->_setID(OBJECTNODE_ATTRIBUTE_ISCONTROLTYPE);
	m_objectNode_Attribute_ordering = getObjectNode_Attribute_ordering();
	m_objectNode_Attribute_ordering->setName("ordering");
	m_objectNode_Attribute_ordering->setEType(getObjectNodeOrderingKind_Class());
	m_objectNode_Attribute_ordering->setLowerBound(1);
	m_objectNode_Attribute_ordering->setUpperBound(1);
	m_objectNode_Attribute_ordering->setTransient(false);
	m_objectNode_Attribute_ordering->setVolatile(false);
	m_objectNode_Attribute_ordering->setChangeable(true);
	m_objectNode_Attribute_ordering->setUnsettable(false);
	m_objectNode_Attribute_ordering->setUnique(true);
	m_objectNode_Attribute_ordering->setDerived(false);
	m_objectNode_Attribute_ordering->setOrdered(false);
	m_objectNode_Attribute_ordering->setID(false);
	m_objectNode_Attribute_ordering->setDefaultValueLiteral("FIFO");
	
	m_objectNode_Attribute_ordering->_setID(OBJECTNODE_ATTRIBUTE_ORDERING);
	
	/*
	 * EReferences
	 */
	m_objectNode_Attribute_inState->setName("inState");
	m_objectNode_Attribute_inState->setEType(getState_Class());
	m_objectNode_Attribute_inState->setLowerBound(0);
	m_objectNode_Attribute_inState->setUpperBound(-1);
	m_objectNode_Attribute_inState->setTransient(false);
	m_objectNode_Attribute_inState->setVolatile(false);
	m_objectNode_Attribute_inState->setChangeable(true);
	m_objectNode_Attribute_inState->setUnsettable(false);
	m_objectNode_Attribute_inState->setUnique(true);
	m_objectNode_Attribute_inState->setDerived(false);
	m_objectNode_Attribute_inState->setOrdered(false);
	m_objectNode_Attribute_inState->setContainment(false);
	m_objectNode_Attribute_inState->setResolveProxies(true);
	m_objectNode_Attribute_inState->setDefaultValueLiteral("");	
	
	m_objectNode_Attribute_inState->_setID(OBJECTNODE_ATTRIBUTE_INSTATE);
	m_objectNode_Attribute_selection->setName("selection");
	m_objectNode_Attribute_selection->setEType(getBehavior_Class());
	m_objectNode_Attribute_selection->setLowerBound(0);
	m_objectNode_Attribute_selection->setUpperBound(1);
	m_objectNode_Attribute_selection->setTransient(false);
	m_objectNode_Attribute_selection->setVolatile(false);
	m_objectNode_Attribute_selection->setChangeable(true);
	m_objectNode_Attribute_selection->setUnsettable(false);
	m_objectNode_Attribute_selection->setUnique(true);
	m_objectNode_Attribute_selection->setDerived(false);
	m_objectNode_Attribute_selection->setOrdered(false);
	m_objectNode_Attribute_selection->setContainment(false);
	m_objectNode_Attribute_selection->setResolveProxies(true);
	m_objectNode_Attribute_selection->setDefaultValueLiteral("");	
	
	m_objectNode_Attribute_selection->_setID(OBJECTNODE_ATTRIBUTE_SELECTION);
	m_objectNode_Attribute_upperBound->setName("upperBound");
	m_objectNode_Attribute_upperBound->setEType(getValueSpecification_Class());
	m_objectNode_Attribute_upperBound->setLowerBound(0);
	m_objectNode_Attribute_upperBound->setUpperBound(1);
	m_objectNode_Attribute_upperBound->setTransient(false);
	m_objectNode_Attribute_upperBound->setVolatile(false);
	m_objectNode_Attribute_upperBound->setChangeable(true);
	m_objectNode_Attribute_upperBound->setUnsettable(false);
	m_objectNode_Attribute_upperBound->setUnique(true);
	m_objectNode_Attribute_upperBound->setDerived(false);
	m_objectNode_Attribute_upperBound->setOrdered(false);
	m_objectNode_Attribute_upperBound->setContainment(true);
	m_objectNode_Attribute_upperBound->setResolveProxies(true);
	m_objectNode_Attribute_upperBound->setDefaultValueLiteral("");	
	
	m_objectNode_Attribute_upperBound->_setID(OBJECTNODE_ATTRIBUTE_UPPERBOUND);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeObservationContent()
{
	m_observation_Class->setName("Observation");
	m_observation_Class->setAbstract(true);
	m_observation_Class->setInterface(false);
	
	m_observation_Class->_setID(OBSERVATION_CLASS);
	
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

void umlPackageImpl::initializeOccurrenceSpecificationContent()
{
	m_occurrenceSpecification_Class->setName("OccurrenceSpecification");
	m_occurrenceSpecification_Class->setAbstract(false);
	m_occurrenceSpecification_Class->setInterface(false);
	
	m_occurrenceSpecification_Class->_setID(OCCURRENCESPECIFICATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_occurrenceSpecification_Attribute_toAfter->setName("toAfter");
	m_occurrenceSpecification_Attribute_toAfter->setEType(getGeneralOrdering_Class());
	m_occurrenceSpecification_Attribute_toAfter->setLowerBound(0);
	m_occurrenceSpecification_Attribute_toAfter->setUpperBound(-1);
	m_occurrenceSpecification_Attribute_toAfter->setTransient(false);
	m_occurrenceSpecification_Attribute_toAfter->setVolatile(false);
	m_occurrenceSpecification_Attribute_toAfter->setChangeable(true);
	m_occurrenceSpecification_Attribute_toAfter->setUnsettable(false);
	m_occurrenceSpecification_Attribute_toAfter->setUnique(true);
	m_occurrenceSpecification_Attribute_toAfter->setDerived(false);
	m_occurrenceSpecification_Attribute_toAfter->setOrdered(false);
	m_occurrenceSpecification_Attribute_toAfter->setContainment(false);
	m_occurrenceSpecification_Attribute_toAfter->setResolveProxies(true);
	m_occurrenceSpecification_Attribute_toAfter->setDefaultValueLiteral("");	
	m_occurrenceSpecification_Attribute_toAfter->setEOpposite(uml::umlPackage::eInstance()->getGeneralOrdering_Attribute_before());
	
	m_occurrenceSpecification_Attribute_toAfter->_setID(OCCURRENCESPECIFICATION_ATTRIBUTE_TOAFTER);
	m_occurrenceSpecification_Attribute_toBefore->setName("toBefore");
	m_occurrenceSpecification_Attribute_toBefore->setEType(getGeneralOrdering_Class());
	m_occurrenceSpecification_Attribute_toBefore->setLowerBound(0);
	m_occurrenceSpecification_Attribute_toBefore->setUpperBound(-1);
	m_occurrenceSpecification_Attribute_toBefore->setTransient(false);
	m_occurrenceSpecification_Attribute_toBefore->setVolatile(false);
	m_occurrenceSpecification_Attribute_toBefore->setChangeable(true);
	m_occurrenceSpecification_Attribute_toBefore->setUnsettable(false);
	m_occurrenceSpecification_Attribute_toBefore->setUnique(true);
	m_occurrenceSpecification_Attribute_toBefore->setDerived(false);
	m_occurrenceSpecification_Attribute_toBefore->setOrdered(false);
	m_occurrenceSpecification_Attribute_toBefore->setContainment(false);
	m_occurrenceSpecification_Attribute_toBefore->setResolveProxies(true);
	m_occurrenceSpecification_Attribute_toBefore->setDefaultValueLiteral("");	
	m_occurrenceSpecification_Attribute_toBefore->setEOpposite(uml::umlPackage::eInstance()->getGeneralOrdering_Attribute_after());
	
	m_occurrenceSpecification_Attribute_toBefore->_setID(OCCURRENCESPECIFICATION_ATTRIBUTE_TOBEFORE);
	
	/*
	 * EOperations
	 */
	m_occurrenceSpecification_Operation_getCovered->setName("getCovered");
	m_occurrenceSpecification_Operation_getCovered->setEType(getLifeline_Class());
	m_occurrenceSpecification_Operation_getCovered->setLowerBound(0);
	m_occurrenceSpecification_Operation_getCovered->setUpperBound(1);
	m_occurrenceSpecification_Operation_getCovered->setUnique(true);
	m_occurrenceSpecification_Operation_getCovered->setOrdered(false);
	
	m_occurrenceSpecification_Operation_getCovered->_setID(OCCURRENCESPECIFICATION_OPERATION_GETCOVERED);
	
	
	m_occurrenceSpecification_Operation_setCovered_Lifeline->setName("setCovered");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_occurrenceSpecification_Operation_setCovered_Lifeline->setEType(unknownClass);
	}
	m_occurrenceSpecification_Operation_setCovered_Lifeline->setLowerBound(1);
	m_occurrenceSpecification_Operation_setCovered_Lifeline->setUpperBound(1);
	m_occurrenceSpecification_Operation_setCovered_Lifeline->setUnique(true);
	m_occurrenceSpecification_Operation_setCovered_Lifeline->setOrdered(false);
	
	m_occurrenceSpecification_Operation_setCovered_Lifeline->_setID(OCCURRENCESPECIFICATION_OPERATION_SETCOVERED_LIFELINE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_occurrenceSpecification_Operation_setCovered_Lifeline);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void umlPackageImpl::initializeOpaqueActionContent()
{
	m_opaqueAction_Class->setName("OpaqueAction");
	m_opaqueAction_Class->setAbstract(false);
	m_opaqueAction_Class->setInterface(false);
	
	m_opaqueAction_Class->_setID(OPAQUEACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	m_opaqueAction_Attribute_body = getOpaqueAction_Attribute_body();
	m_opaqueAction_Attribute_body->setName("body");
	m_opaqueAction_Attribute_body->setEType(types::typesPackage::eInstance()->getString_Class());
	m_opaqueAction_Attribute_body->setLowerBound(0);
	m_opaqueAction_Attribute_body->setUpperBound(-1);
	m_opaqueAction_Attribute_body->setTransient(false);
	m_opaqueAction_Attribute_body->setVolatile(false);
	m_opaqueAction_Attribute_body->setChangeable(true);
	m_opaqueAction_Attribute_body->setUnsettable(true);
	m_opaqueAction_Attribute_body->setUnique(false);
	m_opaqueAction_Attribute_body->setDerived(false);
	m_opaqueAction_Attribute_body->setOrdered(true);
	m_opaqueAction_Attribute_body->setID(false);
	m_opaqueAction_Attribute_body->setDefaultValueLiteral("");
	
	m_opaqueAction_Attribute_body->_setID(OPAQUEACTION_ATTRIBUTE_BODY);
	m_opaqueAction_Attribute_language = getOpaqueAction_Attribute_language();
	m_opaqueAction_Attribute_language->setName("language");
	m_opaqueAction_Attribute_language->setEType(types::typesPackage::eInstance()->getString_Class());
	m_opaqueAction_Attribute_language->setLowerBound(0);
	m_opaqueAction_Attribute_language->setUpperBound(-1);
	m_opaqueAction_Attribute_language->setTransient(false);
	m_opaqueAction_Attribute_language->setVolatile(false);
	m_opaqueAction_Attribute_language->setChangeable(true);
	m_opaqueAction_Attribute_language->setUnsettable(true);
	m_opaqueAction_Attribute_language->setUnique(true);
	m_opaqueAction_Attribute_language->setDerived(false);
	m_opaqueAction_Attribute_language->setOrdered(true);
	m_opaqueAction_Attribute_language->setID(false);
	m_opaqueAction_Attribute_language->setDefaultValueLiteral("");
	
	m_opaqueAction_Attribute_language->_setID(OPAQUEACTION_ATTRIBUTE_LANGUAGE);
	
	/*
	 * EReferences
	 */
	m_opaqueAction_Attribute_inputValue->setName("inputValue");
	m_opaqueAction_Attribute_inputValue->setEType(getInputPin_Class());
	m_opaqueAction_Attribute_inputValue->setLowerBound(0);
	m_opaqueAction_Attribute_inputValue->setUpperBound(-1);
	m_opaqueAction_Attribute_inputValue->setTransient(false);
	m_opaqueAction_Attribute_inputValue->setVolatile(false);
	m_opaqueAction_Attribute_inputValue->setChangeable(true);
	m_opaqueAction_Attribute_inputValue->setUnsettable(false);
	m_opaqueAction_Attribute_inputValue->setUnique(true);
	m_opaqueAction_Attribute_inputValue->setDerived(false);
	m_opaqueAction_Attribute_inputValue->setOrdered(false);
	m_opaqueAction_Attribute_inputValue->setContainment(true);
	m_opaqueAction_Attribute_inputValue->setResolveProxies(true);
	m_opaqueAction_Attribute_inputValue->setDefaultValueLiteral("");	
	
	m_opaqueAction_Attribute_inputValue->_setID(OPAQUEACTION_ATTRIBUTE_INPUTVALUE);
	m_opaqueAction_Attribute_outputValue->setName("outputValue");
	m_opaqueAction_Attribute_outputValue->setEType(getOutputPin_Class());
	m_opaqueAction_Attribute_outputValue->setLowerBound(0);
	m_opaqueAction_Attribute_outputValue->setUpperBound(-1);
	m_opaqueAction_Attribute_outputValue->setTransient(false);
	m_opaqueAction_Attribute_outputValue->setVolatile(false);
	m_opaqueAction_Attribute_outputValue->setChangeable(true);
	m_opaqueAction_Attribute_outputValue->setUnsettable(false);
	m_opaqueAction_Attribute_outputValue->setUnique(true);
	m_opaqueAction_Attribute_outputValue->setDerived(false);
	m_opaqueAction_Attribute_outputValue->setOrdered(false);
	m_opaqueAction_Attribute_outputValue->setContainment(true);
	m_opaqueAction_Attribute_outputValue->setResolveProxies(true);
	m_opaqueAction_Attribute_outputValue->setDefaultValueLiteral("");	
	
	m_opaqueAction_Attribute_outputValue->_setID(OPAQUEACTION_ATTRIBUTE_OUTPUTVALUE);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeOpaqueBehaviorContent()
{
	m_opaqueBehavior_Class->setName("OpaqueBehavior");
	m_opaqueBehavior_Class->setAbstract(false);
	m_opaqueBehavior_Class->setInterface(false);
	
	m_opaqueBehavior_Class->_setID(OPAQUEBEHAVIOR_CLASS);
	
	/*
	 * EAttributes
	 */
	m_opaqueBehavior_Attribute_body = getOpaqueBehavior_Attribute_body();
	m_opaqueBehavior_Attribute_body->setName("body");
	m_opaqueBehavior_Attribute_body->setEType(types::typesPackage::eInstance()->getString_Class());
	m_opaqueBehavior_Attribute_body->setLowerBound(0);
	m_opaqueBehavior_Attribute_body->setUpperBound(-1);
	m_opaqueBehavior_Attribute_body->setTransient(false);
	m_opaqueBehavior_Attribute_body->setVolatile(false);
	m_opaqueBehavior_Attribute_body->setChangeable(true);
	m_opaqueBehavior_Attribute_body->setUnsettable(true);
	m_opaqueBehavior_Attribute_body->setUnique(false);
	m_opaqueBehavior_Attribute_body->setDerived(false);
	m_opaqueBehavior_Attribute_body->setOrdered(true);
	m_opaqueBehavior_Attribute_body->setID(false);
	m_opaqueBehavior_Attribute_body->setDefaultValueLiteral("");
	
	m_opaqueBehavior_Attribute_body->_setID(OPAQUEBEHAVIOR_ATTRIBUTE_BODY);
	m_opaqueBehavior_Attribute_language = getOpaqueBehavior_Attribute_language();
	m_opaqueBehavior_Attribute_language->setName("language");
	m_opaqueBehavior_Attribute_language->setEType(types::typesPackage::eInstance()->getString_Class());
	m_opaqueBehavior_Attribute_language->setLowerBound(0);
	m_opaqueBehavior_Attribute_language->setUpperBound(-1);
	m_opaqueBehavior_Attribute_language->setTransient(false);
	m_opaqueBehavior_Attribute_language->setVolatile(false);
	m_opaqueBehavior_Attribute_language->setChangeable(true);
	m_opaqueBehavior_Attribute_language->setUnsettable(true);
	m_opaqueBehavior_Attribute_language->setUnique(true);
	m_opaqueBehavior_Attribute_language->setDerived(false);
	m_opaqueBehavior_Attribute_language->setOrdered(true);
	m_opaqueBehavior_Attribute_language->setID(false);
	m_opaqueBehavior_Attribute_language->setDefaultValueLiteral("");
	
	m_opaqueBehavior_Attribute_language->_setID(OPAQUEBEHAVIOR_ATTRIBUTE_LANGUAGE);
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeOpaqueExpressionContent()
{
	m_opaqueExpression_Class->setName("OpaqueExpression");
	m_opaqueExpression_Class->setAbstract(false);
	m_opaqueExpression_Class->setInterface(false);
	
	m_opaqueExpression_Class->_setID(OPAQUEEXPRESSION_CLASS);
	
	/*
	 * EAttributes
	 */
	m_opaqueExpression_Attribute_body = getOpaqueExpression_Attribute_body();
	m_opaqueExpression_Attribute_body->setName("body");
	m_opaqueExpression_Attribute_body->setEType(types::typesPackage::eInstance()->getString_Class());
	m_opaqueExpression_Attribute_body->setLowerBound(0);
	m_opaqueExpression_Attribute_body->setUpperBound(-1);
	m_opaqueExpression_Attribute_body->setTransient(false);
	m_opaqueExpression_Attribute_body->setVolatile(false);
	m_opaqueExpression_Attribute_body->setChangeable(true);
	m_opaqueExpression_Attribute_body->setUnsettable(true);
	m_opaqueExpression_Attribute_body->setUnique(false);
	m_opaqueExpression_Attribute_body->setDerived(false);
	m_opaqueExpression_Attribute_body->setOrdered(true);
	m_opaqueExpression_Attribute_body->setID(false);
	m_opaqueExpression_Attribute_body->setDefaultValueLiteral("");
	
	m_opaqueExpression_Attribute_body->_setID(OPAQUEEXPRESSION_ATTRIBUTE_BODY);
	m_opaqueExpression_Attribute_language = getOpaqueExpression_Attribute_language();
	m_opaqueExpression_Attribute_language->setName("language");
	m_opaqueExpression_Attribute_language->setEType(types::typesPackage::eInstance()->getString_Class());
	m_opaqueExpression_Attribute_language->setLowerBound(0);
	m_opaqueExpression_Attribute_language->setUpperBound(-1);
	m_opaqueExpression_Attribute_language->setTransient(false);
	m_opaqueExpression_Attribute_language->setVolatile(false);
	m_opaqueExpression_Attribute_language->setChangeable(true);
	m_opaqueExpression_Attribute_language->setUnsettable(true);
	m_opaqueExpression_Attribute_language->setUnique(true);
	m_opaqueExpression_Attribute_language->setDerived(false);
	m_opaqueExpression_Attribute_language->setOrdered(true);
	m_opaqueExpression_Attribute_language->setID(false);
	m_opaqueExpression_Attribute_language->setDefaultValueLiteral("");
	
	m_opaqueExpression_Attribute_language->_setID(OPAQUEEXPRESSION_ATTRIBUTE_LANGUAGE);
	
	/*
	 * EReferences
	 */
	m_opaqueExpression_Attribute_behavior->setName("behavior");
	m_opaqueExpression_Attribute_behavior->setEType(getBehavior_Class());
	m_opaqueExpression_Attribute_behavior->setLowerBound(0);
	m_opaqueExpression_Attribute_behavior->setUpperBound(1);
	m_opaqueExpression_Attribute_behavior->setTransient(false);
	m_opaqueExpression_Attribute_behavior->setVolatile(false);
	m_opaqueExpression_Attribute_behavior->setChangeable(true);
	m_opaqueExpression_Attribute_behavior->setUnsettable(false);
	m_opaqueExpression_Attribute_behavior->setUnique(true);
	m_opaqueExpression_Attribute_behavior->setDerived(false);
	m_opaqueExpression_Attribute_behavior->setOrdered(false);
	m_opaqueExpression_Attribute_behavior->setContainment(false);
	m_opaqueExpression_Attribute_behavior->setResolveProxies(true);
	m_opaqueExpression_Attribute_behavior->setDefaultValueLiteral("");	
	
	m_opaqueExpression_Attribute_behavior->_setID(OPAQUEEXPRESSION_ATTRIBUTE_BEHAVIOR);
	m_opaqueExpression_Attribute_result->setName("result");
	m_opaqueExpression_Attribute_result->setEType(getParameter_Class());
	m_opaqueExpression_Attribute_result->setLowerBound(0);
	m_opaqueExpression_Attribute_result->setUpperBound(1);
	m_opaqueExpression_Attribute_result->setTransient(true);
	m_opaqueExpression_Attribute_result->setVolatile(true);
	m_opaqueExpression_Attribute_result->setChangeable(false);
	m_opaqueExpression_Attribute_result->setUnsettable(false);
	m_opaqueExpression_Attribute_result->setUnique(true);
	m_opaqueExpression_Attribute_result->setDerived(true);
	m_opaqueExpression_Attribute_result->setOrdered(false);
	m_opaqueExpression_Attribute_result->setContainment(false);
	m_opaqueExpression_Attribute_result->setResolveProxies(true);
	m_opaqueExpression_Attribute_result->setDefaultValueLiteral("");	
	
	m_opaqueExpression_Attribute_result->_setID(OPAQUEEXPRESSION_ATTRIBUTE_RESULT);
	
	/*
	 * EOperations
	 */
	m_opaqueExpression_Operation_getResult->setName("getResult");
	m_opaqueExpression_Operation_getResult->setEType(getParameter_Class());
	m_opaqueExpression_Operation_getResult->setLowerBound(0);
	m_opaqueExpression_Operation_getResult->setUpperBound(1);
	m_opaqueExpression_Operation_getResult->setUnique(true);
	m_opaqueExpression_Operation_getResult->setOrdered(false);
	
	m_opaqueExpression_Operation_getResult->_setID(OPAQUEEXPRESSION_OPERATION_GETRESULT);
	
	
	m_opaqueExpression_Operation_isIntegral->setName("isIntegral");
	m_opaqueExpression_Operation_isIntegral->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_opaqueExpression_Operation_isIntegral->setLowerBound(1);
	m_opaqueExpression_Operation_isIntegral->setUpperBound(1);
	m_opaqueExpression_Operation_isIntegral->setUnique(true);
	m_opaqueExpression_Operation_isIntegral->setOrdered(false);
	
	m_opaqueExpression_Operation_isIntegral->_setID(OPAQUEEXPRESSION_OPERATION_ISINTEGRAL);
	
	
	m_opaqueExpression_Operation_isNonNegative->setName("isNonNegative");
	m_opaqueExpression_Operation_isNonNegative->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_opaqueExpression_Operation_isNonNegative->setLowerBound(1);
	m_opaqueExpression_Operation_isNonNegative->setUpperBound(1);
	m_opaqueExpression_Operation_isNonNegative->setUnique(true);
	m_opaqueExpression_Operation_isNonNegative->setOrdered(false);
	
	m_opaqueExpression_Operation_isNonNegative->_setID(OPAQUEEXPRESSION_OPERATION_ISNONNEGATIVE);
	
	
	m_opaqueExpression_Operation_isPositive->setName("isPositive");
	m_opaqueExpression_Operation_isPositive->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_opaqueExpression_Operation_isPositive->setLowerBound(1);
	m_opaqueExpression_Operation_isPositive->setUpperBound(1);
	m_opaqueExpression_Operation_isPositive->setUnique(true);
	m_opaqueExpression_Operation_isPositive->setOrdered(false);
	
	m_opaqueExpression_Operation_isPositive->_setID(OPAQUEEXPRESSION_OPERATION_ISPOSITIVE);
	
	
	m_opaqueExpression_Operation_value->setName("value");
	m_opaqueExpression_Operation_value->setEType(types::typesPackage::eInstance()->getInteger_Class());
	m_opaqueExpression_Operation_value->setLowerBound(1);
	m_opaqueExpression_Operation_value->setUpperBound(1);
	m_opaqueExpression_Operation_value->setUnique(true);
	m_opaqueExpression_Operation_value->setOrdered(false);
	
	m_opaqueExpression_Operation_value->_setID(OPAQUEEXPRESSION_OPERATION_VALUE);
	
	
	
}

void umlPackageImpl::initializeOperationContent()
{
	m_operation_Class->setName("Operation");
	m_operation_Class->setAbstract(false);
	m_operation_Class->setInterface(false);
	
	m_operation_Class->_setID(OPERATION_CLASS);
	
	/*
	 * EAttributes
	 */
	m_operation_Attribute_isOrdered = getOperation_Attribute_isOrdered();
	m_operation_Attribute_isOrdered->setName("isOrdered");
	m_operation_Attribute_isOrdered->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_operation_Attribute_isOrdered->setLowerBound(1);
	m_operation_Attribute_isOrdered->setUpperBound(1);
	m_operation_Attribute_isOrdered->setTransient(true);
	m_operation_Attribute_isOrdered->setVolatile(true);
	m_operation_Attribute_isOrdered->setChangeable(false);
	m_operation_Attribute_isOrdered->setUnsettable(false);
	m_operation_Attribute_isOrdered->setUnique(true);
	m_operation_Attribute_isOrdered->setDerived(true);
	m_operation_Attribute_isOrdered->setOrdered(false);
	m_operation_Attribute_isOrdered->setID(false);
	m_operation_Attribute_isOrdered->setDefaultValueLiteral("");
	
	m_operation_Attribute_isOrdered->_setID(OPERATION_ATTRIBUTE_ISORDERED);
	m_operation_Attribute_isQuery = getOperation_Attribute_isQuery();
	m_operation_Attribute_isQuery->setName("isQuery");
	m_operation_Attribute_isQuery->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_operation_Attribute_isQuery->setLowerBound(1);
	m_operation_Attribute_isQuery->setUpperBound(1);
	m_operation_Attribute_isQuery->setTransient(false);
	m_operation_Attribute_isQuery->setVolatile(false);
	m_operation_Attribute_isQuery->setChangeable(true);
	m_operation_Attribute_isQuery->setUnsettable(false);
	m_operation_Attribute_isQuery->setUnique(true);
	m_operation_Attribute_isQuery->setDerived(false);
	m_operation_Attribute_isQuery->setOrdered(false);
	m_operation_Attribute_isQuery->setID(false);
	m_operation_Attribute_isQuery->setDefaultValueLiteral("false");
	
	m_operation_Attribute_isQuery->_setID(OPERATION_ATTRIBUTE_ISQUERY);
	m_operation_Attribute_isUnique = getOperation_Attribute_isUnique();
	m_operation_Attribute_isUnique->setName("isUnique");
	m_operation_Attribute_isUnique->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_operation_Attribute_isUnique->setLowerBound(1);
	m_operation_Attribute_isUnique->setUpperBound(1);
	m_operation_Attribute_isUnique->setTransient(true);
	m_operation_Attribute_isUnique->setVolatile(true);
	m_operation_Attribute_isUnique->setChangeable(false);
	m_operation_Attribute_isUnique->setUnsettable(false);
	m_operation_Attribute_isUnique->setUnique(true);
	m_operation_Attribute_isUnique->setDerived(true);
	m_operation_Attribute_isUnique->setOrdered(false);
	m_operation_Attribute_isUnique->setID(false);
	m_operation_Attribute_isUnique->setDefaultValueLiteral("true");
	
	m_operation_Attribute_isUnique->_setID(OPERATION_ATTRIBUTE_ISUNIQUE);
	m_operation_Attribute_lower = getOperation_Attribute_lower();
	m_operation_Attribute_lower->setName("lower");
	m_operation_Attribute_lower->setEType(types::typesPackage::eInstance()->getInteger_Class());
	m_operation_Attribute_lower->setLowerBound(0);
	m_operation_Attribute_lower->setUpperBound(1);
	m_operation_Attribute_lower->setTransient(true);
	m_operation_Attribute_lower->setVolatile(true);
	m_operation_Attribute_lower->setChangeable(false);
	m_operation_Attribute_lower->setUnsettable(false);
	m_operation_Attribute_lower->setUnique(true);
	m_operation_Attribute_lower->setDerived(true);
	m_operation_Attribute_lower->setOrdered(false);
	m_operation_Attribute_lower->setID(false);
	m_operation_Attribute_lower->setDefaultValueLiteral("1");
	
	m_operation_Attribute_lower->_setID(OPERATION_ATTRIBUTE_LOWER);
	m_operation_Attribute_upper = getOperation_Attribute_upper();
	m_operation_Attribute_upper->setName("upper");
	m_operation_Attribute_upper->setEType(types::typesPackage::eInstance()->getUnlimitedNatural_Class());
	m_operation_Attribute_upper->setLowerBound(0);
	m_operation_Attribute_upper->setUpperBound(1);
	m_operation_Attribute_upper->setTransient(true);
	m_operation_Attribute_upper->setVolatile(true);
	m_operation_Attribute_upper->setChangeable(false);
	m_operation_Attribute_upper->setUnsettable(false);
	m_operation_Attribute_upper->setUnique(true);
	m_operation_Attribute_upper->setDerived(true);
	m_operation_Attribute_upper->setOrdered(false);
	m_operation_Attribute_upper->setID(false);
	m_operation_Attribute_upper->setDefaultValueLiteral("1");
	
	m_operation_Attribute_upper->_setID(OPERATION_ATTRIBUTE_UPPER);
	
	/*
	 * EReferences
	 */
	m_operation_Attribute_bodyCondition->setName("bodyCondition");
	m_operation_Attribute_bodyCondition->setEType(getConstraint_Class());
	m_operation_Attribute_bodyCondition->setLowerBound(0);
	m_operation_Attribute_bodyCondition->setUpperBound(1);
	m_operation_Attribute_bodyCondition->setTransient(false);
	m_operation_Attribute_bodyCondition->setVolatile(false);
	m_operation_Attribute_bodyCondition->setChangeable(true);
	m_operation_Attribute_bodyCondition->setUnsettable(false);
	m_operation_Attribute_bodyCondition->setUnique(true);
	m_operation_Attribute_bodyCondition->setDerived(false);
	m_operation_Attribute_bodyCondition->setOrdered(false);
	m_operation_Attribute_bodyCondition->setContainment(false);
	m_operation_Attribute_bodyCondition->setResolveProxies(true);
	m_operation_Attribute_bodyCondition->setDefaultValueLiteral("");	
	
	m_operation_Attribute_bodyCondition->_setID(OPERATION_ATTRIBUTE_BODYCONDITION);
	m_operation_Attribute_class->setName("class");
	m_operation_Attribute_class->setEType(getClass_Class());
	m_operation_Attribute_class->setLowerBound(0);
	m_operation_Attribute_class->setUpperBound(1);
	m_operation_Attribute_class->setTransient(false);
	m_operation_Attribute_class->setVolatile(false);
	m_operation_Attribute_class->setChangeable(true);
	m_operation_Attribute_class->setUnsettable(false);
	m_operation_Attribute_class->setUnique(true);
	m_operation_Attribute_class->setDerived(false);
	m_operation_Attribute_class->setOrdered(false);
	m_operation_Attribute_class->setContainment(false);
	m_operation_Attribute_class->setResolveProxies(true);
	m_operation_Attribute_class->setDefaultValueLiteral("");	
	m_operation_Attribute_class->setEOpposite(uml::umlPackage::eInstance()->getClass_Attribute_ownedOperation());
	
	m_operation_Attribute_class->_setID(OPERATION_ATTRIBUTE_CLASS);
	m_operation_Attribute_datatype->setName("datatype");
	m_operation_Attribute_datatype->setEType(getDataType_Class());
	m_operation_Attribute_datatype->setLowerBound(0);
	m_operation_Attribute_datatype->setUpperBound(1);
	m_operation_Attribute_datatype->setTransient(false);
	m_operation_Attribute_datatype->setVolatile(false);
	m_operation_Attribute_datatype->setChangeable(true);
	m_operation_Attribute_datatype->setUnsettable(false);
	m_operation_Attribute_datatype->setUnique(true);
	m_operation_Attribute_datatype->setDerived(false);
	m_operation_Attribute_datatype->setOrdered(false);
	m_operation_Attribute_datatype->setContainment(false);
	m_operation_Attribute_datatype->setResolveProxies(true);
	m_operation_Attribute_datatype->setDefaultValueLiteral("");	
	m_operation_Attribute_datatype->setEOpposite(uml::umlPackage::eInstance()->getDataType_Attribute_ownedOperation());
	
	m_operation_Attribute_datatype->_setID(OPERATION_ATTRIBUTE_DATATYPE);
	m_operation_Attribute_interface->setName("interface");
	m_operation_Attribute_interface->setEType(getInterface_Class());
	m_operation_Attribute_interface->setLowerBound(0);
	m_operation_Attribute_interface->setUpperBound(1);
	m_operation_Attribute_interface->setTransient(false);
	m_operation_Attribute_interface->setVolatile(false);
	m_operation_Attribute_interface->setChangeable(true);
	m_operation_Attribute_interface->setUnsettable(false);
	m_operation_Attribute_interface->setUnique(true);
	m_operation_Attribute_interface->setDerived(false);
	m_operation_Attribute_interface->setOrdered(false);
	m_operation_Attribute_interface->setContainment(false);
	m_operation_Attribute_interface->setResolveProxies(true);
	m_operation_Attribute_interface->setDefaultValueLiteral("");	
	m_operation_Attribute_interface->setEOpposite(uml::umlPackage::eInstance()->getInterface_Attribute_ownedOperation());
	
	m_operation_Attribute_interface->_setID(OPERATION_ATTRIBUTE_INTERFACE);
	m_operation_Attribute_ownedParameter->setName("ownedParameter");
	m_operation_Attribute_ownedParameter->setEType(getParameter_Class());
	m_operation_Attribute_ownedParameter->setLowerBound(0);
	m_operation_Attribute_ownedParameter->setUpperBound(-1);
	m_operation_Attribute_ownedParameter->setTransient(false);
	m_operation_Attribute_ownedParameter->setVolatile(false);
	m_operation_Attribute_ownedParameter->setChangeable(true);
	m_operation_Attribute_ownedParameter->setUnsettable(false);
	m_operation_Attribute_ownedParameter->setUnique(true);
	m_operation_Attribute_ownedParameter->setDerived(false);
	m_operation_Attribute_ownedParameter->setOrdered(true);
	m_operation_Attribute_ownedParameter->setContainment(true);
	m_operation_Attribute_ownedParameter->setResolveProxies(true);
	m_operation_Attribute_ownedParameter->setDefaultValueLiteral("");	
	m_operation_Attribute_ownedParameter->setEOpposite(uml::umlPackage::eInstance()->getParameter_Attribute_operation());
	
	m_operation_Attribute_ownedParameter->_setID(OPERATION_ATTRIBUTE_OWNEDPARAMETER);
	m_operation_Attribute_postcondition->setName("postcondition");
	m_operation_Attribute_postcondition->setEType(getConstraint_Class());
	m_operation_Attribute_postcondition->setLowerBound(0);
	m_operation_Attribute_postcondition->setUpperBound(-1);
	m_operation_Attribute_postcondition->setTransient(false);
	m_operation_Attribute_postcondition->setVolatile(false);
	m_operation_Attribute_postcondition->setChangeable(true);
	m_operation_Attribute_postcondition->setUnsettable(false);
	m_operation_Attribute_postcondition->setUnique(true);
	m_operation_Attribute_postcondition->setDerived(false);
	m_operation_Attribute_postcondition->setOrdered(false);
	m_operation_Attribute_postcondition->setContainment(false);
	m_operation_Attribute_postcondition->setResolveProxies(true);
	m_operation_Attribute_postcondition->setDefaultValueLiteral("");	
	
	m_operation_Attribute_postcondition->_setID(OPERATION_ATTRIBUTE_POSTCONDITION);
	m_operation_Attribute_precondition->setName("precondition");
	m_operation_Attribute_precondition->setEType(getConstraint_Class());
	m_operation_Attribute_precondition->setLowerBound(0);
	m_operation_Attribute_precondition->setUpperBound(-1);
	m_operation_Attribute_precondition->setTransient(false);
	m_operation_Attribute_precondition->setVolatile(false);
	m_operation_Attribute_precondition->setChangeable(true);
	m_operation_Attribute_precondition->setUnsettable(false);
	m_operation_Attribute_precondition->setUnique(true);
	m_operation_Attribute_precondition->setDerived(false);
	m_operation_Attribute_precondition->setOrdered(false);
	m_operation_Attribute_precondition->setContainment(false);
	m_operation_Attribute_precondition->setResolveProxies(true);
	m_operation_Attribute_precondition->setDefaultValueLiteral("");	
	
	m_operation_Attribute_precondition->_setID(OPERATION_ATTRIBUTE_PRECONDITION);
	m_operation_Attribute_redefinedOperation->setName("redefinedOperation");
	m_operation_Attribute_redefinedOperation->setEType(getOperation_Class());
	m_operation_Attribute_redefinedOperation->setLowerBound(0);
	m_operation_Attribute_redefinedOperation->setUpperBound(-1);
	m_operation_Attribute_redefinedOperation->setTransient(false);
	m_operation_Attribute_redefinedOperation->setVolatile(false);
	m_operation_Attribute_redefinedOperation->setChangeable(true);
	m_operation_Attribute_redefinedOperation->setUnsettable(false);
	m_operation_Attribute_redefinedOperation->setUnique(true);
	m_operation_Attribute_redefinedOperation->setDerived(false);
	m_operation_Attribute_redefinedOperation->setOrdered(false);
	m_operation_Attribute_redefinedOperation->setContainment(false);
	m_operation_Attribute_redefinedOperation->setResolveProxies(true);
	m_operation_Attribute_redefinedOperation->setDefaultValueLiteral("");	
	
	m_operation_Attribute_redefinedOperation->_setID(OPERATION_ATTRIBUTE_REDEFINEDOPERATION);
	m_operation_Attribute_type->setName("type");
	m_operation_Attribute_type->setEType(getType_Class());
	m_operation_Attribute_type->setLowerBound(0);
	m_operation_Attribute_type->setUpperBound(1);
	m_operation_Attribute_type->setTransient(true);
	m_operation_Attribute_type->setVolatile(true);
	m_operation_Attribute_type->setChangeable(false);
	m_operation_Attribute_type->setUnsettable(false);
	m_operation_Attribute_type->setUnique(true);
	m_operation_Attribute_type->setDerived(true);
	m_operation_Attribute_type->setOrdered(false);
	m_operation_Attribute_type->setContainment(false);
	m_operation_Attribute_type->setResolveProxies(true);
	m_operation_Attribute_type->setDefaultValueLiteral("");	
	
	m_operation_Attribute_type->_setID(OPERATION_ATTRIBUTE_TYPE);
	
	/*
	 * EOperations
	 */
	m_operation_Operation_getLower->setName("getLower");
	m_operation_Operation_getLower->setEType(types::typesPackage::eInstance()->getInteger_Class());
	m_operation_Operation_getLower->setLowerBound(1);
	m_operation_Operation_getLower->setUpperBound(1);
	m_operation_Operation_getLower->setUnique(true);
	m_operation_Operation_getLower->setOrdered(false);
	
	m_operation_Operation_getLower->_setID(OPERATION_OPERATION_GETLOWER);
	
	
	m_operation_Operation_getReturnResult->setName("getReturnResult");
	m_operation_Operation_getReturnResult->setEType(getParameter_Class());
	m_operation_Operation_getReturnResult->setLowerBound(0);
	m_operation_Operation_getReturnResult->setUpperBound(1);
	m_operation_Operation_getReturnResult->setUnique(true);
	m_operation_Operation_getReturnResult->setOrdered(false);
	
	m_operation_Operation_getReturnResult->_setID(OPERATION_OPERATION_GETRETURNRESULT);
	
	
	m_operation_Operation_getType->setName("getType");
	m_operation_Operation_getType->setEType(getType_Class());
	m_operation_Operation_getType->setLowerBound(1);
	m_operation_Operation_getType->setUpperBound(1);
	m_operation_Operation_getType->setUnique(true);
	m_operation_Operation_getType->setOrdered(false);
	
	m_operation_Operation_getType->_setID(OPERATION_OPERATION_GETTYPE);
	
	
	m_operation_Operation_getUpper->setName("getUpper");
	m_operation_Operation_getUpper->setEType(types::typesPackage::eInstance()->getUnlimitedNatural_Class());
	m_operation_Operation_getUpper->setLowerBound(1);
	m_operation_Operation_getUpper->setUpperBound(1);
	m_operation_Operation_getUpper->setUnique(true);
	m_operation_Operation_getUpper->setOrdered(false);
	
	m_operation_Operation_getUpper->_setID(OPERATION_OPERATION_GETUPPER);
	
	
	m_operation_Operation_isOrdered->setName("isOrdered");
	m_operation_Operation_isOrdered->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_operation_Operation_isOrdered->setLowerBound(1);
	m_operation_Operation_isOrdered->setUpperBound(1);
	m_operation_Operation_isOrdered->setUnique(true);
	m_operation_Operation_isOrdered->setOrdered(false);
	
	m_operation_Operation_isOrdered->_setID(OPERATION_OPERATION_ISORDERED);
	
	
	m_operation_Operation_isUnique->setName("isUnique");
	m_operation_Operation_isUnique->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_operation_Operation_isUnique->setLowerBound(1);
	m_operation_Operation_isUnique->setUpperBound(1);
	m_operation_Operation_isUnique->setUnique(true);
	m_operation_Operation_isUnique->setOrdered(false);
	
	m_operation_Operation_isUnique->_setID(OPERATION_OPERATION_ISUNIQUE);
	
	
	m_operation_Operation_matches_Operation->setName("matches");
	m_operation_Operation_matches_Operation->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_operation_Operation_matches_Operation->setLowerBound(1);
	m_operation_Operation_matches_Operation->setUpperBound(1);
	m_operation_Operation_matches_Operation->setUnique(true);
	m_operation_Operation_matches_Operation->setOrdered(true);
	
	m_operation_Operation_matches_Operation->_setID(OPERATION_OPERATION_MATCHES_OPERATION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_operation_Operation_matches_Operation);
		parameter->setName("comparedOperation");
		parameter->setEType(getOperation_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_operation_Operation_returnResult->setName("returnResult");
	m_operation_Operation_returnResult->setEType(getParameter_Class());
	m_operation_Operation_returnResult->setLowerBound(0);
	m_operation_Operation_returnResult->setUpperBound(1);
	m_operation_Operation_returnResult->setUnique(true);
	m_operation_Operation_returnResult->setOrdered(false);
	
	m_operation_Operation_returnResult->_setID(OPERATION_OPERATION_RETURNRESULT);
	
	
	m_operation_Operation_setIsOrdered_Boolean->setName("setIsOrdered");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_operation_Operation_setIsOrdered_Boolean->setEType(unknownClass);
	}
	m_operation_Operation_setIsOrdered_Boolean->setLowerBound(1);
	m_operation_Operation_setIsOrdered_Boolean->setUpperBound(1);
	m_operation_Operation_setIsOrdered_Boolean->setUnique(true);
	m_operation_Operation_setIsOrdered_Boolean->setOrdered(false);
	
	m_operation_Operation_setIsOrdered_Boolean->_setID(OPERATION_OPERATION_SETISORDERED_BOOLEAN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_operation_Operation_setIsOrdered_Boolean);
		parameter->setName("newIsOrdered");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_operation_Operation_setIsUnique_Boolean->setName("setIsUnique");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_operation_Operation_setIsUnique_Boolean->setEType(unknownClass);
	}
	m_operation_Operation_setIsUnique_Boolean->setLowerBound(1);
	m_operation_Operation_setIsUnique_Boolean->setUpperBound(1);
	m_operation_Operation_setIsUnique_Boolean->setUnique(true);
	m_operation_Operation_setIsUnique_Boolean->setOrdered(false);
	
	m_operation_Operation_setIsUnique_Boolean->_setID(OPERATION_OPERATION_SETISUNIQUE_BOOLEAN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_operation_Operation_setIsUnique_Boolean);
		parameter->setName("newIsUnique");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_operation_Operation_setLower_Integer->setName("setLower");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_operation_Operation_setLower_Integer->setEType(unknownClass);
	}
	m_operation_Operation_setLower_Integer->setLowerBound(1);
	m_operation_Operation_setLower_Integer->setUpperBound(1);
	m_operation_Operation_setLower_Integer->setUnique(true);
	m_operation_Operation_setLower_Integer->setOrdered(false);
	
	m_operation_Operation_setLower_Integer->_setID(OPERATION_OPERATION_SETLOWER_INTEGER);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_operation_Operation_setLower_Integer);
		parameter->setName("newLower");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_operation_Operation_setType_Type->setName("setType");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_operation_Operation_setType_Type->setEType(unknownClass);
	}
	m_operation_Operation_setType_Type->setLowerBound(1);
	m_operation_Operation_setType_Type->setUpperBound(1);
	m_operation_Operation_setType_Type->setUnique(true);
	m_operation_Operation_setType_Type->setOrdered(false);
	
	m_operation_Operation_setType_Type->_setID(OPERATION_OPERATION_SETTYPE_TYPE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_operation_Operation_setType_Type);
		parameter->setName("newType");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_operation_Operation_setUpper_UnlimitedNatural->setName("setUpper");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_operation_Operation_setUpper_UnlimitedNatural->setEType(unknownClass);
	}
	m_operation_Operation_setUpper_UnlimitedNatural->setLowerBound(1);
	m_operation_Operation_setUpper_UnlimitedNatural->setUpperBound(1);
	m_operation_Operation_setUpper_UnlimitedNatural->setUnique(true);
	m_operation_Operation_setUpper_UnlimitedNatural->setOrdered(false);
	
	m_operation_Operation_setUpper_UnlimitedNatural->_setID(OPERATION_OPERATION_SETUPPER_UNLIMITEDNATURAL);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_operation_Operation_setUpper_UnlimitedNatural);
		parameter->setName("newUpper");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void umlPackageImpl::initializeOperationTemplateParameterContent()
{
	m_operationTemplateParameter_Class->setName("OperationTemplateParameter");
	m_operationTemplateParameter_Class->setAbstract(false);
	m_operationTemplateParameter_Class->setInterface(false);
	
	m_operationTemplateParameter_Class->_setID(OPERATIONTEMPLATEPARAMETER_CLASS);
	
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

void umlPackageImpl::initializeOutputPinContent()
{
	m_outputPin_Class->setName("OutputPin");
	m_outputPin_Class->setAbstract(false);
	m_outputPin_Class->setInterface(false);
	
	m_outputPin_Class->_setID(OUTPUTPIN_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_outputPin_Attribute_action->setName("action");
	m_outputPin_Attribute_action->setEType(getAction_Class());
	m_outputPin_Attribute_action->setLowerBound(0);
	m_outputPin_Attribute_action->setUpperBound(1);
	m_outputPin_Attribute_action->setTransient(true);
	m_outputPin_Attribute_action->setVolatile(false);
	m_outputPin_Attribute_action->setChangeable(false);
	m_outputPin_Attribute_action->setUnsettable(false);
	m_outputPin_Attribute_action->setUnique(true);
	m_outputPin_Attribute_action->setDerived(true);
	m_outputPin_Attribute_action->setOrdered(true);
	m_outputPin_Attribute_action->setContainment(false);
	m_outputPin_Attribute_action->setResolveProxies(true);
	m_outputPin_Attribute_action->setDefaultValueLiteral("");	
	m_outputPin_Attribute_action->setEOpposite(uml::umlPackage::eInstance()->getAction_Attribute_output());
	
	m_outputPin_Attribute_action->_setID(OUTPUTPIN_ATTRIBUTE_ACTION);
	m_outputPin_Attribute_callAction->setName("callAction");
	m_outputPin_Attribute_callAction->setEType(getCallAction_Class());
	m_outputPin_Attribute_callAction->setLowerBound(0);
	m_outputPin_Attribute_callAction->setUpperBound(1);
	m_outputPin_Attribute_callAction->setTransient(false);
	m_outputPin_Attribute_callAction->setVolatile(false);
	m_outputPin_Attribute_callAction->setChangeable(true);
	m_outputPin_Attribute_callAction->setUnsettable(false);
	m_outputPin_Attribute_callAction->setUnique(true);
	m_outputPin_Attribute_callAction->setDerived(false);
	m_outputPin_Attribute_callAction->setOrdered(true);
	m_outputPin_Attribute_callAction->setContainment(false);
	m_outputPin_Attribute_callAction->setResolveProxies(true);
	m_outputPin_Attribute_callAction->setDefaultValueLiteral("");	
	m_outputPin_Attribute_callAction->setEOpposite(uml::umlPackage::eInstance()->getCallAction_Attribute_result());
	
	m_outputPin_Attribute_callAction->_setID(OUTPUTPIN_ATTRIBUTE_CALLACTION);
	m_outputPin_Attribute_clearStructuralFeatureAction->setName("clearStructuralFeatureAction");
	m_outputPin_Attribute_clearStructuralFeatureAction->setEType(getClearStructuralFeatureAction_Class());
	m_outputPin_Attribute_clearStructuralFeatureAction->setLowerBound(0);
	m_outputPin_Attribute_clearStructuralFeatureAction->setUpperBound(1);
	m_outputPin_Attribute_clearStructuralFeatureAction->setTransient(false);
	m_outputPin_Attribute_clearStructuralFeatureAction->setVolatile(false);
	m_outputPin_Attribute_clearStructuralFeatureAction->setChangeable(true);
	m_outputPin_Attribute_clearStructuralFeatureAction->setUnsettable(false);
	m_outputPin_Attribute_clearStructuralFeatureAction->setUnique(true);
	m_outputPin_Attribute_clearStructuralFeatureAction->setDerived(false);
	m_outputPin_Attribute_clearStructuralFeatureAction->setOrdered(true);
	m_outputPin_Attribute_clearStructuralFeatureAction->setContainment(false);
	m_outputPin_Attribute_clearStructuralFeatureAction->setResolveProxies(true);
	m_outputPin_Attribute_clearStructuralFeatureAction->setDefaultValueLiteral("");	
	m_outputPin_Attribute_clearStructuralFeatureAction->setEOpposite(uml::umlPackage::eInstance()->getClearStructuralFeatureAction_Attribute_result());
	
	m_outputPin_Attribute_clearStructuralFeatureAction->_setID(OUTPUTPIN_ATTRIBUTE_CLEARSTRUCTURALFEATUREACTION);
	m_outputPin_Attribute_createObjectAction->setName("createObjectAction");
	m_outputPin_Attribute_createObjectAction->setEType(getCreateObjectAction_Class());
	m_outputPin_Attribute_createObjectAction->setLowerBound(0);
	m_outputPin_Attribute_createObjectAction->setUpperBound(1);
	m_outputPin_Attribute_createObjectAction->setTransient(false);
	m_outputPin_Attribute_createObjectAction->setVolatile(false);
	m_outputPin_Attribute_createObjectAction->setChangeable(true);
	m_outputPin_Attribute_createObjectAction->setUnsettable(false);
	m_outputPin_Attribute_createObjectAction->setUnique(true);
	m_outputPin_Attribute_createObjectAction->setDerived(false);
	m_outputPin_Attribute_createObjectAction->setOrdered(true);
	m_outputPin_Attribute_createObjectAction->setContainment(false);
	m_outputPin_Attribute_createObjectAction->setResolveProxies(true);
	m_outputPin_Attribute_createObjectAction->setDefaultValueLiteral("");	
	m_outputPin_Attribute_createObjectAction->setEOpposite(uml::umlPackage::eInstance()->getCreateObjectAction_Attribute_result());
	
	m_outputPin_Attribute_createObjectAction->_setID(OUTPUTPIN_ATTRIBUTE_CREATEOBJECTACTION);
	m_outputPin_Attribute_readSelfAction->setName("readSelfAction");
	m_outputPin_Attribute_readSelfAction->setEType(getReadSelfAction_Class());
	m_outputPin_Attribute_readSelfAction->setLowerBound(0);
	m_outputPin_Attribute_readSelfAction->setUpperBound(1);
	m_outputPin_Attribute_readSelfAction->setTransient(false);
	m_outputPin_Attribute_readSelfAction->setVolatile(false);
	m_outputPin_Attribute_readSelfAction->setChangeable(true);
	m_outputPin_Attribute_readSelfAction->setUnsettable(false);
	m_outputPin_Attribute_readSelfAction->setUnique(true);
	m_outputPin_Attribute_readSelfAction->setDerived(false);
	m_outputPin_Attribute_readSelfAction->setOrdered(true);
	m_outputPin_Attribute_readSelfAction->setContainment(false);
	m_outputPin_Attribute_readSelfAction->setResolveProxies(true);
	m_outputPin_Attribute_readSelfAction->setDefaultValueLiteral("");	
	m_outputPin_Attribute_readSelfAction->setEOpposite(uml::umlPackage::eInstance()->getReadSelfAction_Attribute_result());
	
	m_outputPin_Attribute_readSelfAction->_setID(OUTPUTPIN_ATTRIBUTE_READSELFACTION);
	m_outputPin_Attribute_readStructuralFeatureAction->setName("readStructuralFeatureAction");
	m_outputPin_Attribute_readStructuralFeatureAction->setEType(getReadStructuralFeatureAction_Class());
	m_outputPin_Attribute_readStructuralFeatureAction->setLowerBound(0);
	m_outputPin_Attribute_readStructuralFeatureAction->setUpperBound(1);
	m_outputPin_Attribute_readStructuralFeatureAction->setTransient(false);
	m_outputPin_Attribute_readStructuralFeatureAction->setVolatile(false);
	m_outputPin_Attribute_readStructuralFeatureAction->setChangeable(true);
	m_outputPin_Attribute_readStructuralFeatureAction->setUnsettable(false);
	m_outputPin_Attribute_readStructuralFeatureAction->setUnique(true);
	m_outputPin_Attribute_readStructuralFeatureAction->setDerived(false);
	m_outputPin_Attribute_readStructuralFeatureAction->setOrdered(true);
	m_outputPin_Attribute_readStructuralFeatureAction->setContainment(false);
	m_outputPin_Attribute_readStructuralFeatureAction->setResolveProxies(true);
	m_outputPin_Attribute_readStructuralFeatureAction->setDefaultValueLiteral("");	
	m_outputPin_Attribute_readStructuralFeatureAction->setEOpposite(uml::umlPackage::eInstance()->getReadStructuralFeatureAction_Attribute_result());
	
	m_outputPin_Attribute_readStructuralFeatureAction->_setID(OUTPUTPIN_ATTRIBUTE_READSTRUCTURALFEATUREACTION);
	m_outputPin_Attribute_valueSpecificationAction->setName("valueSpecificationAction");
	m_outputPin_Attribute_valueSpecificationAction->setEType(getValueSpecificationAction_Class());
	m_outputPin_Attribute_valueSpecificationAction->setLowerBound(0);
	m_outputPin_Attribute_valueSpecificationAction->setUpperBound(1);
	m_outputPin_Attribute_valueSpecificationAction->setTransient(false);
	m_outputPin_Attribute_valueSpecificationAction->setVolatile(false);
	m_outputPin_Attribute_valueSpecificationAction->setChangeable(true);
	m_outputPin_Attribute_valueSpecificationAction->setUnsettable(false);
	m_outputPin_Attribute_valueSpecificationAction->setUnique(true);
	m_outputPin_Attribute_valueSpecificationAction->setDerived(false);
	m_outputPin_Attribute_valueSpecificationAction->setOrdered(true);
	m_outputPin_Attribute_valueSpecificationAction->setContainment(false);
	m_outputPin_Attribute_valueSpecificationAction->setResolveProxies(true);
	m_outputPin_Attribute_valueSpecificationAction->setDefaultValueLiteral("");	
	m_outputPin_Attribute_valueSpecificationAction->setEOpposite(uml::umlPackage::eInstance()->getValueSpecificationAction_Attribute_result());
	
	m_outputPin_Attribute_valueSpecificationAction->_setID(OUTPUTPIN_ATTRIBUTE_VALUESPECIFICATIONACTION);
	m_outputPin_Attribute_writeStructuralFeatureAction->setName("writeStructuralFeatureAction");
	m_outputPin_Attribute_writeStructuralFeatureAction->setEType(getWriteStructuralFeatureAction_Class());
	m_outputPin_Attribute_writeStructuralFeatureAction->setLowerBound(0);
	m_outputPin_Attribute_writeStructuralFeatureAction->setUpperBound(1);
	m_outputPin_Attribute_writeStructuralFeatureAction->setTransient(false);
	m_outputPin_Attribute_writeStructuralFeatureAction->setVolatile(false);
	m_outputPin_Attribute_writeStructuralFeatureAction->setChangeable(true);
	m_outputPin_Attribute_writeStructuralFeatureAction->setUnsettable(false);
	m_outputPin_Attribute_writeStructuralFeatureAction->setUnique(true);
	m_outputPin_Attribute_writeStructuralFeatureAction->setDerived(false);
	m_outputPin_Attribute_writeStructuralFeatureAction->setOrdered(true);
	m_outputPin_Attribute_writeStructuralFeatureAction->setContainment(false);
	m_outputPin_Attribute_writeStructuralFeatureAction->setResolveProxies(true);
	m_outputPin_Attribute_writeStructuralFeatureAction->setDefaultValueLiteral("");	
	m_outputPin_Attribute_writeStructuralFeatureAction->setEOpposite(uml::umlPackage::eInstance()->getWriteStructuralFeatureAction_Attribute_result());
	
	m_outputPin_Attribute_writeStructuralFeatureAction->_setID(OUTPUTPIN_ATTRIBUTE_WRITESTRUCTURALFEATUREACTION);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializePackageContent()
{
	m_package_Class->setName("Package");
	m_package_Class->setAbstract(false);
	m_package_Class->setInterface(false);
	
	m_package_Class->_setID(PACKAGE_CLASS);
	
	/*
	 * EAttributes
	 */
	m_package_Attribute_uRI = getPackage_Attribute_uRI();
	m_package_Attribute_uRI->setName("URI");
	m_package_Attribute_uRI->setEType(types::typesPackage::eInstance()->getString_Class());
	m_package_Attribute_uRI->setLowerBound(0);
	m_package_Attribute_uRI->setUpperBound(1);
	m_package_Attribute_uRI->setTransient(false);
	m_package_Attribute_uRI->setVolatile(false);
	m_package_Attribute_uRI->setChangeable(true);
	m_package_Attribute_uRI->setUnsettable(false);
	m_package_Attribute_uRI->setUnique(true);
	m_package_Attribute_uRI->setDerived(false);
	m_package_Attribute_uRI->setOrdered(false);
	m_package_Attribute_uRI->setID(false);
	m_package_Attribute_uRI->setDefaultValueLiteral("");
	
	m_package_Attribute_uRI->_setID(PACKAGE_ATTRIBUTE_URI);
	
	/*
	 * EReferences
	 */
	m_package_Attribute_nestedPackage->setName("nestedPackage");
	m_package_Attribute_nestedPackage->setEType(getPackage_Class());
	m_package_Attribute_nestedPackage->setLowerBound(0);
	m_package_Attribute_nestedPackage->setUpperBound(-1);
	m_package_Attribute_nestedPackage->setTransient(true);
	m_package_Attribute_nestedPackage->setVolatile(true);
	m_package_Attribute_nestedPackage->setChangeable(true);
	m_package_Attribute_nestedPackage->setUnsettable(false);
	m_package_Attribute_nestedPackage->setUnique(true);
	m_package_Attribute_nestedPackage->setDerived(true);
	m_package_Attribute_nestedPackage->setOrdered(false);
	m_package_Attribute_nestedPackage->setContainment(true);
	m_package_Attribute_nestedPackage->setResolveProxies(true);
	m_package_Attribute_nestedPackage->setDefaultValueLiteral("");	
	m_package_Attribute_nestedPackage->setEOpposite(uml::umlPackage::eInstance()->getPackage_Attribute_nestingPackage());
	
	m_package_Attribute_nestedPackage->_setID(PACKAGE_ATTRIBUTE_NESTEDPACKAGE);
	m_package_Attribute_nestingPackage->setName("nestingPackage");
	m_package_Attribute_nestingPackage->setEType(getPackage_Class());
	m_package_Attribute_nestingPackage->setLowerBound(0);
	m_package_Attribute_nestingPackage->setUpperBound(1);
	m_package_Attribute_nestingPackage->setTransient(true);
	m_package_Attribute_nestingPackage->setVolatile(true);
	m_package_Attribute_nestingPackage->setChangeable(true);
	m_package_Attribute_nestingPackage->setUnsettable(false);
	m_package_Attribute_nestingPackage->setUnique(true);
	m_package_Attribute_nestingPackage->setDerived(true);
	m_package_Attribute_nestingPackage->setOrdered(false);
	m_package_Attribute_nestingPackage->setContainment(false);
	m_package_Attribute_nestingPackage->setResolveProxies(true);
	m_package_Attribute_nestingPackage->setDefaultValueLiteral("");	
	m_package_Attribute_nestingPackage->setEOpposite(uml::umlPackage::eInstance()->getPackage_Attribute_nestedPackage());
	
	m_package_Attribute_nestingPackage->_setID(PACKAGE_ATTRIBUTE_NESTINGPACKAGE);
	m_package_Attribute_ownedStereotype->setName("ownedStereotype");
	m_package_Attribute_ownedStereotype->setEType(getStereotype_Class());
	m_package_Attribute_ownedStereotype->setLowerBound(0);
	m_package_Attribute_ownedStereotype->setUpperBound(-1);
	m_package_Attribute_ownedStereotype->setTransient(true);
	m_package_Attribute_ownedStereotype->setVolatile(true);
	m_package_Attribute_ownedStereotype->setChangeable(false);
	m_package_Attribute_ownedStereotype->setUnsettable(false);
	m_package_Attribute_ownedStereotype->setUnique(true);
	m_package_Attribute_ownedStereotype->setDerived(true);
	m_package_Attribute_ownedStereotype->setOrdered(false);
	m_package_Attribute_ownedStereotype->setContainment(true);
	m_package_Attribute_ownedStereotype->setResolveProxies(true);
	m_package_Attribute_ownedStereotype->setDefaultValueLiteral("");	
	
	m_package_Attribute_ownedStereotype->_setID(PACKAGE_ATTRIBUTE_OWNEDSTEREOTYPE);
	m_package_Attribute_ownedType->setName("ownedType");
	m_package_Attribute_ownedType->setEType(getType_Class());
	m_package_Attribute_ownedType->setLowerBound(0);
	m_package_Attribute_ownedType->setUpperBound(-1);
	m_package_Attribute_ownedType->setTransient(true);
	m_package_Attribute_ownedType->setVolatile(true);
	m_package_Attribute_ownedType->setChangeable(true);
	m_package_Attribute_ownedType->setUnsettable(false);
	m_package_Attribute_ownedType->setUnique(true);
	m_package_Attribute_ownedType->setDerived(true);
	m_package_Attribute_ownedType->setOrdered(false);
	m_package_Attribute_ownedType->setContainment(true);
	m_package_Attribute_ownedType->setResolveProxies(true);
	m_package_Attribute_ownedType->setDefaultValueLiteral("");	
	m_package_Attribute_ownedType->setEOpposite(uml::umlPackage::eInstance()->getType_Attribute_package());
	
	m_package_Attribute_ownedType->_setID(PACKAGE_ATTRIBUTE_OWNEDTYPE);
	m_package_Attribute_packageMerge->setName("packageMerge");
	m_package_Attribute_packageMerge->setEType(getPackageMerge_Class());
	m_package_Attribute_packageMerge->setLowerBound(0);
	m_package_Attribute_packageMerge->setUpperBound(-1);
	m_package_Attribute_packageMerge->setTransient(false);
	m_package_Attribute_packageMerge->setVolatile(false);
	m_package_Attribute_packageMerge->setChangeable(true);
	m_package_Attribute_packageMerge->setUnsettable(false);
	m_package_Attribute_packageMerge->setUnique(true);
	m_package_Attribute_packageMerge->setDerived(false);
	m_package_Attribute_packageMerge->setOrdered(false);
	m_package_Attribute_packageMerge->setContainment(true);
	m_package_Attribute_packageMerge->setResolveProxies(true);
	m_package_Attribute_packageMerge->setDefaultValueLiteral("");	
	m_package_Attribute_packageMerge->setEOpposite(uml::umlPackage::eInstance()->getPackageMerge_Attribute_receivingPackage());
	
	m_package_Attribute_packageMerge->_setID(PACKAGE_ATTRIBUTE_PACKAGEMERGE);
	m_package_Attribute_packagedElement->setName("packagedElement");
	m_package_Attribute_packagedElement->setEType(getPackageableElement_Class());
	m_package_Attribute_packagedElement->setLowerBound(0);
	m_package_Attribute_packagedElement->setUpperBound(-1);
	m_package_Attribute_packagedElement->setTransient(false);
	m_package_Attribute_packagedElement->setVolatile(false);
	m_package_Attribute_packagedElement->setChangeable(true);
	m_package_Attribute_packagedElement->setUnsettable(false);
	m_package_Attribute_packagedElement->setUnique(true);
	m_package_Attribute_packagedElement->setDerived(false);
	m_package_Attribute_packagedElement->setOrdered(false);
	m_package_Attribute_packagedElement->setContainment(true);
	m_package_Attribute_packagedElement->setResolveProxies(true);
	m_package_Attribute_packagedElement->setDefaultValueLiteral("");	
	m_package_Attribute_packagedElement->setEOpposite(uml::umlPackage::eInstance()->getPackageableElement_Attribute_owningPackage());
	
	m_package_Attribute_packagedElement->_setID(PACKAGE_ATTRIBUTE_PACKAGEDELEMENT);
	m_package_Attribute_profileApplication->setName("profileApplication");
	m_package_Attribute_profileApplication->setEType(getProfileApplication_Class());
	m_package_Attribute_profileApplication->setLowerBound(0);
	m_package_Attribute_profileApplication->setUpperBound(-1);
	m_package_Attribute_profileApplication->setTransient(false);
	m_package_Attribute_profileApplication->setVolatile(false);
	m_package_Attribute_profileApplication->setChangeable(true);
	m_package_Attribute_profileApplication->setUnsettable(false);
	m_package_Attribute_profileApplication->setUnique(true);
	m_package_Attribute_profileApplication->setDerived(false);
	m_package_Attribute_profileApplication->setOrdered(false);
	m_package_Attribute_profileApplication->setContainment(true);
	m_package_Attribute_profileApplication->setResolveProxies(true);
	m_package_Attribute_profileApplication->setDefaultValueLiteral("");	
	m_package_Attribute_profileApplication->setEOpposite(uml::umlPackage::eInstance()->getProfileApplication_Attribute_applyingPackage());
	
	m_package_Attribute_profileApplication->_setID(PACKAGE_ATTRIBUTE_PROFILEAPPLICATION);
	
	/*
	 * EOperations
	 */
	m_package_Operation_allApplicableStereotypes->setName("allApplicableStereotypes");
	m_package_Operation_allApplicableStereotypes->setEType(getStereotype_Class());
	m_package_Operation_allApplicableStereotypes->setLowerBound(0);
	m_package_Operation_allApplicableStereotypes->setUpperBound(-1);
	m_package_Operation_allApplicableStereotypes->setUnique(true);
	m_package_Operation_allApplicableStereotypes->setOrdered(false);
	
	m_package_Operation_allApplicableStereotypes->_setID(PACKAGE_OPERATION_ALLAPPLICABLESTEREOTYPES);
	
	
	m_package_Operation_applyProfile_Profile->setName("applyProfile");
	m_package_Operation_applyProfile_Profile->setEType(ecore::ecorePackage::eInstance()->getEObject_Class());
	m_package_Operation_applyProfile_Profile->setLowerBound(0);
	m_package_Operation_applyProfile_Profile->setUpperBound(-1);
	m_package_Operation_applyProfile_Profile->setUnique(true);
	m_package_Operation_applyProfile_Profile->setOrdered(false);
	
	m_package_Operation_applyProfile_Profile->_setID(PACKAGE_OPERATION_APPLYPROFILE_PROFILE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_package_Operation_applyProfile_Profile);
		parameter->setName("profile");
		parameter->setEType(getProfile_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_package_Operation_containingProfile->setName("containingProfile");
	m_package_Operation_containingProfile->setEType(getProfile_Class());
	m_package_Operation_containingProfile->setLowerBound(0);
	m_package_Operation_containingProfile->setUpperBound(1);
	m_package_Operation_containingProfile->setUnique(true);
	m_package_Operation_containingProfile->setOrdered(false);
	
	m_package_Operation_containingProfile->_setID(PACKAGE_OPERATION_CONTAININGPROFILE);
	
	
	m_package_Operation_createOwnedClass_String_Boolean->setName("createOwnedClass");
	m_package_Operation_createOwnedClass_String_Boolean->setEType(getClass_Class());
	m_package_Operation_createOwnedClass_String_Boolean->setLowerBound(1);
	m_package_Operation_createOwnedClass_String_Boolean->setUpperBound(1);
	m_package_Operation_createOwnedClass_String_Boolean->setUnique(true);
	m_package_Operation_createOwnedClass_String_Boolean->setOrdered(false);
	
	m_package_Operation_createOwnedClass_String_Boolean->_setID(PACKAGE_OPERATION_CREATEOWNEDCLASS_STRING_BOOLEAN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_package_Operation_createOwnedClass_String_Boolean);
		parameter->setName("name");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_package_Operation_createOwnedClass_String_Boolean);
		parameter->setName("isAbstract");
		parameter->setEType(types::typesPackage::eInstance()->getBoolean_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_package_Operation_createOwnedEnumeration_String->setName("createOwnedEnumeration");
	m_package_Operation_createOwnedEnumeration_String->setEType(getEnumeration_Class());
	m_package_Operation_createOwnedEnumeration_String->setLowerBound(1);
	m_package_Operation_createOwnedEnumeration_String->setUpperBound(1);
	m_package_Operation_createOwnedEnumeration_String->setUnique(true);
	m_package_Operation_createOwnedEnumeration_String->setOrdered(false);
	
	m_package_Operation_createOwnedEnumeration_String->_setID(PACKAGE_OPERATION_CREATEOWNEDENUMERATION_STRING);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_package_Operation_createOwnedEnumeration_String);
		parameter->setName("name");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_package_Operation_createOwnedInterface_String->setName("createOwnedInterface");
	m_package_Operation_createOwnedInterface_String->setEType(getInterface_Class());
	m_package_Operation_createOwnedInterface_String->setLowerBound(1);
	m_package_Operation_createOwnedInterface_String->setUpperBound(1);
	m_package_Operation_createOwnedInterface_String->setUnique(true);
	m_package_Operation_createOwnedInterface_String->setOrdered(false);
	
	m_package_Operation_createOwnedInterface_String->_setID(PACKAGE_OPERATION_CREATEOWNEDINTERFACE_STRING);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_package_Operation_createOwnedInterface_String);
		parameter->setName("name");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_package_Operation_createOwnedPrimitiveType_String->setName("createOwnedPrimitiveType");
	m_package_Operation_createOwnedPrimitiveType_String->setEType(getPrimitiveType_Class());
	m_package_Operation_createOwnedPrimitiveType_String->setLowerBound(1);
	m_package_Operation_createOwnedPrimitiveType_String->setUpperBound(1);
	m_package_Operation_createOwnedPrimitiveType_String->setUnique(true);
	m_package_Operation_createOwnedPrimitiveType_String->setOrdered(false);
	
	m_package_Operation_createOwnedPrimitiveType_String->_setID(PACKAGE_OPERATION_CREATEOWNEDPRIMITIVETYPE_STRING);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_package_Operation_createOwnedPrimitiveType_String);
		parameter->setName("name");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_package_Operation_createOwnedStereotype_String_Boolean->setName("createOwnedStereotype");
	m_package_Operation_createOwnedStereotype_String_Boolean->setEType(getStereotype_Class());
	m_package_Operation_createOwnedStereotype_String_Boolean->setLowerBound(1);
	m_package_Operation_createOwnedStereotype_String_Boolean->setUpperBound(1);
	m_package_Operation_createOwnedStereotype_String_Boolean->setUnique(true);
	m_package_Operation_createOwnedStereotype_String_Boolean->setOrdered(false);
	
	m_package_Operation_createOwnedStereotype_String_Boolean->_setID(PACKAGE_OPERATION_CREATEOWNEDSTEREOTYPE_STRING_BOOLEAN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_package_Operation_createOwnedStereotype_String_Boolean);
		parameter->setName("name");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_package_Operation_createOwnedStereotype_String_Boolean);
		parameter->setName("isAbstract");
		parameter->setEType(types::typesPackage::eInstance()->getBoolean_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_package_Operation_getAllAppliedProfiles->setName("getAllAppliedProfiles");
	m_package_Operation_getAllAppliedProfiles->setEType(getProfile_Class());
	m_package_Operation_getAllAppliedProfiles->setLowerBound(0);
	m_package_Operation_getAllAppliedProfiles->setUpperBound(-1);
	m_package_Operation_getAllAppliedProfiles->setUnique(true);
	m_package_Operation_getAllAppliedProfiles->setOrdered(false);
	
	m_package_Operation_getAllAppliedProfiles->_setID(PACKAGE_OPERATION_GETALLAPPLIEDPROFILES);
	
	
	m_package_Operation_getAllProfileApplications->setName("getAllProfileApplications");
	m_package_Operation_getAllProfileApplications->setEType(getProfileApplication_Class());
	m_package_Operation_getAllProfileApplications->setLowerBound(0);
	m_package_Operation_getAllProfileApplications->setUpperBound(-1);
	m_package_Operation_getAllProfileApplications->setUnique(true);
	m_package_Operation_getAllProfileApplications->setOrdered(false);
	
	m_package_Operation_getAllProfileApplications->_setID(PACKAGE_OPERATION_GETALLPROFILEAPPLICATIONS);
	
	
	m_package_Operation_getAppliedProfile_String->setName("getAppliedProfile");
	m_package_Operation_getAppliedProfile_String->setEType(getProfile_Class());
	m_package_Operation_getAppliedProfile_String->setLowerBound(0);
	m_package_Operation_getAppliedProfile_String->setUpperBound(1);
	m_package_Operation_getAppliedProfile_String->setUnique(true);
	m_package_Operation_getAppliedProfile_String->setOrdered(false);
	
	m_package_Operation_getAppliedProfile_String->_setID(PACKAGE_OPERATION_GETAPPLIEDPROFILE_STRING);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_package_Operation_getAppliedProfile_String);
		parameter->setName("qualifiedName");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_package_Operation_getAppliedProfile_String_Boolean->setName("getAppliedProfile");
	m_package_Operation_getAppliedProfile_String_Boolean->setEType(getProfile_Class());
	m_package_Operation_getAppliedProfile_String_Boolean->setLowerBound(0);
	m_package_Operation_getAppliedProfile_String_Boolean->setUpperBound(1);
	m_package_Operation_getAppliedProfile_String_Boolean->setUnique(true);
	m_package_Operation_getAppliedProfile_String_Boolean->setOrdered(false);
	
	m_package_Operation_getAppliedProfile_String_Boolean->_setID(PACKAGE_OPERATION_GETAPPLIEDPROFILE_STRING_BOOLEAN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_package_Operation_getAppliedProfile_String_Boolean);
		parameter->setName("qualifiedName");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_package_Operation_getAppliedProfile_String_Boolean);
		parameter->setName("recurse");
		parameter->setEType(types::typesPackage::eInstance()->getBoolean_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_package_Operation_getAppliedProfiles->setName("getAppliedProfiles");
	m_package_Operation_getAppliedProfiles->setEType(getProfile_Class());
	m_package_Operation_getAppliedProfiles->setLowerBound(0);
	m_package_Operation_getAppliedProfiles->setUpperBound(-1);
	m_package_Operation_getAppliedProfiles->setUnique(true);
	m_package_Operation_getAppliedProfiles->setOrdered(false);
	
	m_package_Operation_getAppliedProfiles->_setID(PACKAGE_OPERATION_GETAPPLIEDPROFILES);
	
	
	m_package_Operation_getNestedPackages->setName("getNestedPackages");
	m_package_Operation_getNestedPackages->setEType(getPackage_Class());
	m_package_Operation_getNestedPackages->setLowerBound(0);
	m_package_Operation_getNestedPackages->setUpperBound(-1);
	m_package_Operation_getNestedPackages->setUnique(true);
	m_package_Operation_getNestedPackages->setOrdered(false);
	
	m_package_Operation_getNestedPackages->_setID(PACKAGE_OPERATION_GETNESTEDPACKAGES);
	
	
	m_package_Operation_getOwnedStereotypes->setName("getOwnedStereotypes");
	m_package_Operation_getOwnedStereotypes->setEType(getStereotype_Class());
	m_package_Operation_getOwnedStereotypes->setLowerBound(0);
	m_package_Operation_getOwnedStereotypes->setUpperBound(-1);
	m_package_Operation_getOwnedStereotypes->setUnique(true);
	m_package_Operation_getOwnedStereotypes->setOrdered(false);
	
	m_package_Operation_getOwnedStereotypes->_setID(PACKAGE_OPERATION_GETOWNEDSTEREOTYPES);
	
	
	m_package_Operation_getOwnedTypes->setName("getOwnedTypes");
	m_package_Operation_getOwnedTypes->setEType(getType_Class());
	m_package_Operation_getOwnedTypes->setLowerBound(0);
	m_package_Operation_getOwnedTypes->setUpperBound(-1);
	m_package_Operation_getOwnedTypes->setUnique(true);
	m_package_Operation_getOwnedTypes->setOrdered(false);
	
	m_package_Operation_getOwnedTypes->_setID(PACKAGE_OPERATION_GETOWNEDTYPES);
	
	
	m_package_Operation_getProfileApplication_Profile->setName("getProfileApplication");
	m_package_Operation_getProfileApplication_Profile->setEType(getProfileApplication_Class());
	m_package_Operation_getProfileApplication_Profile->setLowerBound(0);
	m_package_Operation_getProfileApplication_Profile->setUpperBound(1);
	m_package_Operation_getProfileApplication_Profile->setUnique(true);
	m_package_Operation_getProfileApplication_Profile->setOrdered(false);
	
	m_package_Operation_getProfileApplication_Profile->_setID(PACKAGE_OPERATION_GETPROFILEAPPLICATION_PROFILE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_package_Operation_getProfileApplication_Profile);
		parameter->setName("profile");
		parameter->setEType(getProfile_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_package_Operation_getProfileApplication_Profile_Boolean->setName("getProfileApplication");
	m_package_Operation_getProfileApplication_Profile_Boolean->setEType(getProfileApplication_Class());
	m_package_Operation_getProfileApplication_Profile_Boolean->setLowerBound(0);
	m_package_Operation_getProfileApplication_Profile_Boolean->setUpperBound(1);
	m_package_Operation_getProfileApplication_Profile_Boolean->setUnique(true);
	m_package_Operation_getProfileApplication_Profile_Boolean->setOrdered(false);
	
	m_package_Operation_getProfileApplication_Profile_Boolean->_setID(PACKAGE_OPERATION_GETPROFILEAPPLICATION_PROFILE_BOOLEAN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_package_Operation_getProfileApplication_Profile_Boolean);
		parameter->setName("profile");
		parameter->setEType(getProfile_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_package_Operation_getProfileApplication_Profile_Boolean);
		parameter->setName("recurse");
		parameter->setEType(types::typesPackage::eInstance()->getBoolean_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_package_Operation_isModelLibrary->setName("isModelLibrary");
	m_package_Operation_isModelLibrary->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_package_Operation_isModelLibrary->setLowerBound(1);
	m_package_Operation_isModelLibrary->setUpperBound(1);
	m_package_Operation_isModelLibrary->setUnique(true);
	m_package_Operation_isModelLibrary->setOrdered(false);
	
	m_package_Operation_isModelLibrary->_setID(PACKAGE_OPERATION_ISMODELLIBRARY);
	
	
	m_package_Operation_isProfileApplied_Profile->setName("isProfileApplied");
	m_package_Operation_isProfileApplied_Profile->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_package_Operation_isProfileApplied_Profile->setLowerBound(1);
	m_package_Operation_isProfileApplied_Profile->setUpperBound(1);
	m_package_Operation_isProfileApplied_Profile->setUnique(true);
	m_package_Operation_isProfileApplied_Profile->setOrdered(false);
	
	m_package_Operation_isProfileApplied_Profile->_setID(PACKAGE_OPERATION_ISPROFILEAPPLIED_PROFILE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_package_Operation_isProfileApplied_Profile);
		parameter->setName("profile");
		parameter->setEType(getProfile_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_package_Operation_makesVisible_NamedElement->setName("makesVisible");
	m_package_Operation_makesVisible_NamedElement->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_package_Operation_makesVisible_NamedElement->setLowerBound(1);
	m_package_Operation_makesVisible_NamedElement->setUpperBound(1);
	m_package_Operation_makesVisible_NamedElement->setUnique(true);
	m_package_Operation_makesVisible_NamedElement->setOrdered(false);
	
	m_package_Operation_makesVisible_NamedElement->_setID(PACKAGE_OPERATION_MAKESVISIBLE_NAMEDELEMENT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_package_Operation_makesVisible_NamedElement);
		parameter->setName("el");
		parameter->setEType(getNamedElement_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_package_Operation_unapplyProfile_Profile->setName("unapplyProfile");
	m_package_Operation_unapplyProfile_Profile->setEType(ecore::ecorePackage::eInstance()->getEObject_Class());
	m_package_Operation_unapplyProfile_Profile->setLowerBound(0);
	m_package_Operation_unapplyProfile_Profile->setUpperBound(-1);
	m_package_Operation_unapplyProfile_Profile->setUnique(true);
	m_package_Operation_unapplyProfile_Profile->setOrdered(false);
	
	m_package_Operation_unapplyProfile_Profile->_setID(PACKAGE_OPERATION_UNAPPLYPROFILE_PROFILE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_package_Operation_unapplyProfile_Profile);
		parameter->setName("profile");
		parameter->setEType(getProfile_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_package_Operation_visibleMembers->setName("visibleMembers");
	m_package_Operation_visibleMembers->setEType(getPackageableElement_Class());
	m_package_Operation_visibleMembers->setLowerBound(0);
	m_package_Operation_visibleMembers->setUpperBound(-1);
	m_package_Operation_visibleMembers->setUnique(true);
	m_package_Operation_visibleMembers->setOrdered(false);
	
	m_package_Operation_visibleMembers->_setID(PACKAGE_OPERATION_VISIBLEMEMBERS);
	
	
	
}

void umlPackageImpl::initializePackageImportContent()
{
	m_packageImport_Class->setName("PackageImport");
	m_packageImport_Class->setAbstract(false);
	m_packageImport_Class->setInterface(false);
	
	m_packageImport_Class->_setID(PACKAGEIMPORT_CLASS);
	
	/*
	 * EAttributes
	 */
	m_packageImport_Attribute_visibility = getPackageImport_Attribute_visibility();
	m_packageImport_Attribute_visibility->setName("visibility");
	m_packageImport_Attribute_visibility->setEType(getVisibilityKind_Class());
	m_packageImport_Attribute_visibility->setLowerBound(1);
	m_packageImport_Attribute_visibility->setUpperBound(1);
	m_packageImport_Attribute_visibility->setTransient(false);
	m_packageImport_Attribute_visibility->setVolatile(false);
	m_packageImport_Attribute_visibility->setChangeable(true);
	m_packageImport_Attribute_visibility->setUnsettable(false);
	m_packageImport_Attribute_visibility->setUnique(true);
	m_packageImport_Attribute_visibility->setDerived(false);
	m_packageImport_Attribute_visibility->setOrdered(false);
	m_packageImport_Attribute_visibility->setID(false);
	m_packageImport_Attribute_visibility->setDefaultValueLiteral("public");
	
	m_packageImport_Attribute_visibility->_setID(PACKAGEIMPORT_ATTRIBUTE_VISIBILITY);
	
	/*
	 * EReferences
	 */
	m_packageImport_Attribute_importedPackage->setName("importedPackage");
	m_packageImport_Attribute_importedPackage->setEType(getPackage_Class());
	m_packageImport_Attribute_importedPackage->setLowerBound(1);
	m_packageImport_Attribute_importedPackage->setUpperBound(1);
	m_packageImport_Attribute_importedPackage->setTransient(false);
	m_packageImport_Attribute_importedPackage->setVolatile(false);
	m_packageImport_Attribute_importedPackage->setChangeable(true);
	m_packageImport_Attribute_importedPackage->setUnsettable(false);
	m_packageImport_Attribute_importedPackage->setUnique(true);
	m_packageImport_Attribute_importedPackage->setDerived(false);
	m_packageImport_Attribute_importedPackage->setOrdered(false);
	m_packageImport_Attribute_importedPackage->setContainment(false);
	m_packageImport_Attribute_importedPackage->setResolveProxies(true);
	m_packageImport_Attribute_importedPackage->setDefaultValueLiteral("");	
	
	m_packageImport_Attribute_importedPackage->_setID(PACKAGEIMPORT_ATTRIBUTE_IMPORTEDPACKAGE);
	m_packageImport_Attribute_importingNamespace->setName("importingNamespace");
	m_packageImport_Attribute_importingNamespace->setEType(getNamespace_Class());
	m_packageImport_Attribute_importingNamespace->setLowerBound(1);
	m_packageImport_Attribute_importingNamespace->setUpperBound(1);
	m_packageImport_Attribute_importingNamespace->setTransient(false);
	m_packageImport_Attribute_importingNamespace->setVolatile(false);
	m_packageImport_Attribute_importingNamespace->setChangeable(true);
	m_packageImport_Attribute_importingNamespace->setUnsettable(false);
	m_packageImport_Attribute_importingNamespace->setUnique(true);
	m_packageImport_Attribute_importingNamespace->setDerived(false);
	m_packageImport_Attribute_importingNamespace->setOrdered(false);
	m_packageImport_Attribute_importingNamespace->setContainment(false);
	m_packageImport_Attribute_importingNamespace->setResolveProxies(true);
	m_packageImport_Attribute_importingNamespace->setDefaultValueLiteral("");	
	m_packageImport_Attribute_importingNamespace->setEOpposite(uml::umlPackage::eInstance()->getNamespace_Attribute_packageImport());
	
	m_packageImport_Attribute_importingNamespace->_setID(PACKAGEIMPORT_ATTRIBUTE_IMPORTINGNAMESPACE);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializePackageMergeContent()
{
	m_packageMerge_Class->setName("PackageMerge");
	m_packageMerge_Class->setAbstract(false);
	m_packageMerge_Class->setInterface(false);
	
	m_packageMerge_Class->_setID(PACKAGEMERGE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_packageMerge_Attribute_mergedPackage->setName("mergedPackage");
	m_packageMerge_Attribute_mergedPackage->setEType(getPackage_Class());
	m_packageMerge_Attribute_mergedPackage->setLowerBound(1);
	m_packageMerge_Attribute_mergedPackage->setUpperBound(1);
	m_packageMerge_Attribute_mergedPackage->setTransient(false);
	m_packageMerge_Attribute_mergedPackage->setVolatile(false);
	m_packageMerge_Attribute_mergedPackage->setChangeable(true);
	m_packageMerge_Attribute_mergedPackage->setUnsettable(false);
	m_packageMerge_Attribute_mergedPackage->setUnique(true);
	m_packageMerge_Attribute_mergedPackage->setDerived(false);
	m_packageMerge_Attribute_mergedPackage->setOrdered(false);
	m_packageMerge_Attribute_mergedPackage->setContainment(false);
	m_packageMerge_Attribute_mergedPackage->setResolveProxies(true);
	m_packageMerge_Attribute_mergedPackage->setDefaultValueLiteral("");	
	
	m_packageMerge_Attribute_mergedPackage->_setID(PACKAGEMERGE_ATTRIBUTE_MERGEDPACKAGE);
	m_packageMerge_Attribute_receivingPackage->setName("receivingPackage");
	m_packageMerge_Attribute_receivingPackage->setEType(getPackage_Class());
	m_packageMerge_Attribute_receivingPackage->setLowerBound(1);
	m_packageMerge_Attribute_receivingPackage->setUpperBound(1);
	m_packageMerge_Attribute_receivingPackage->setTransient(false);
	m_packageMerge_Attribute_receivingPackage->setVolatile(false);
	m_packageMerge_Attribute_receivingPackage->setChangeable(true);
	m_packageMerge_Attribute_receivingPackage->setUnsettable(false);
	m_packageMerge_Attribute_receivingPackage->setUnique(true);
	m_packageMerge_Attribute_receivingPackage->setDerived(false);
	m_packageMerge_Attribute_receivingPackage->setOrdered(false);
	m_packageMerge_Attribute_receivingPackage->setContainment(false);
	m_packageMerge_Attribute_receivingPackage->setResolveProxies(true);
	m_packageMerge_Attribute_receivingPackage->setDefaultValueLiteral("");	
	m_packageMerge_Attribute_receivingPackage->setEOpposite(uml::umlPackage::eInstance()->getPackage_Attribute_packageMerge());
	
	m_packageMerge_Attribute_receivingPackage->_setID(PACKAGEMERGE_ATTRIBUTE_RECEIVINGPACKAGE);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializePackageableElementContent()
{
	m_packageableElement_Class->setName("PackageableElement");
	m_packageableElement_Class->setAbstract(true);
	m_packageableElement_Class->setInterface(false);
	
	m_packageableElement_Class->_setID(PACKAGEABLEELEMENT_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_packageableElement_Attribute_owningPackage->setName("owningPackage");
	m_packageableElement_Attribute_owningPackage->setEType(getPackage_Class());
	m_packageableElement_Attribute_owningPackage->setLowerBound(0);
	m_packageableElement_Attribute_owningPackage->setUpperBound(1);
	m_packageableElement_Attribute_owningPackage->setTransient(false);
	m_packageableElement_Attribute_owningPackage->setVolatile(false);
	m_packageableElement_Attribute_owningPackage->setChangeable(true);
	m_packageableElement_Attribute_owningPackage->setUnsettable(false);
	m_packageableElement_Attribute_owningPackage->setUnique(true);
	m_packageableElement_Attribute_owningPackage->setDerived(false);
	m_packageableElement_Attribute_owningPackage->setOrdered(true);
	m_packageableElement_Attribute_owningPackage->setContainment(false);
	m_packageableElement_Attribute_owningPackage->setResolveProxies(true);
	m_packageableElement_Attribute_owningPackage->setDefaultValueLiteral("");	
	m_packageableElement_Attribute_owningPackage->setEOpposite(uml::umlPackage::eInstance()->getPackage_Attribute_packagedElement());
	
	m_packageableElement_Attribute_owningPackage->_setID(PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeParameterContent()
{
	m_parameter_Class->setName("Parameter");
	m_parameter_Class->setAbstract(false);
	m_parameter_Class->setInterface(false);
	
	m_parameter_Class->_setID(PARAMETER_CLASS);
	
	/*
	 * EAttributes
	 */
	m_parameter_Attribute_default = getParameter_Attribute_default();
	m_parameter_Attribute_default->setName("default");
	m_parameter_Attribute_default->setEType(types::typesPackage::eInstance()->getString_Class());
	m_parameter_Attribute_default->setLowerBound(0);
	m_parameter_Attribute_default->setUpperBound(1);
	m_parameter_Attribute_default->setTransient(true);
	m_parameter_Attribute_default->setVolatile(true);
	m_parameter_Attribute_default->setChangeable(true);
	m_parameter_Attribute_default->setUnsettable(true);
	m_parameter_Attribute_default->setUnique(true);
	m_parameter_Attribute_default->setDerived(true);
	m_parameter_Attribute_default->setOrdered(false);
	m_parameter_Attribute_default->setID(false);
	m_parameter_Attribute_default->setDefaultValueLiteral("");
	
	m_parameter_Attribute_default->_setID(PARAMETER_ATTRIBUTE_DEFAULT);
	m_parameter_Attribute_direction = getParameter_Attribute_direction();
	m_parameter_Attribute_direction->setName("direction");
	m_parameter_Attribute_direction->setEType(getParameterDirectionKind_Class());
	m_parameter_Attribute_direction->setLowerBound(1);
	m_parameter_Attribute_direction->setUpperBound(1);
	m_parameter_Attribute_direction->setTransient(false);
	m_parameter_Attribute_direction->setVolatile(false);
	m_parameter_Attribute_direction->setChangeable(true);
	m_parameter_Attribute_direction->setUnsettable(false);
	m_parameter_Attribute_direction->setUnique(true);
	m_parameter_Attribute_direction->setDerived(false);
	m_parameter_Attribute_direction->setOrdered(false);
	m_parameter_Attribute_direction->setID(false);
	m_parameter_Attribute_direction->setDefaultValueLiteral("in");
	
	m_parameter_Attribute_direction->_setID(PARAMETER_ATTRIBUTE_DIRECTION);
	m_parameter_Attribute_effect = getParameter_Attribute_effect();
	m_parameter_Attribute_effect->setName("effect");
	m_parameter_Attribute_effect->setEType(getParameterEffectKind_Class());
	m_parameter_Attribute_effect->setLowerBound(0);
	m_parameter_Attribute_effect->setUpperBound(1);
	m_parameter_Attribute_effect->setTransient(false);
	m_parameter_Attribute_effect->setVolatile(false);
	m_parameter_Attribute_effect->setChangeable(true);
	m_parameter_Attribute_effect->setUnsettable(true);
	m_parameter_Attribute_effect->setUnique(true);
	m_parameter_Attribute_effect->setDerived(false);
	m_parameter_Attribute_effect->setOrdered(false);
	m_parameter_Attribute_effect->setID(false);
	m_parameter_Attribute_effect->setDefaultValueLiteral("");
	
	m_parameter_Attribute_effect->_setID(PARAMETER_ATTRIBUTE_EFFECT);
	m_parameter_Attribute_isException = getParameter_Attribute_isException();
	m_parameter_Attribute_isException->setName("isException");
	m_parameter_Attribute_isException->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_parameter_Attribute_isException->setLowerBound(1);
	m_parameter_Attribute_isException->setUpperBound(1);
	m_parameter_Attribute_isException->setTransient(false);
	m_parameter_Attribute_isException->setVolatile(false);
	m_parameter_Attribute_isException->setChangeable(true);
	m_parameter_Attribute_isException->setUnsettable(false);
	m_parameter_Attribute_isException->setUnique(true);
	m_parameter_Attribute_isException->setDerived(false);
	m_parameter_Attribute_isException->setOrdered(false);
	m_parameter_Attribute_isException->setID(false);
	m_parameter_Attribute_isException->setDefaultValueLiteral("false");
	
	m_parameter_Attribute_isException->_setID(PARAMETER_ATTRIBUTE_ISEXCEPTION);
	m_parameter_Attribute_isStream = getParameter_Attribute_isStream();
	m_parameter_Attribute_isStream->setName("isStream");
	m_parameter_Attribute_isStream->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_parameter_Attribute_isStream->setLowerBound(1);
	m_parameter_Attribute_isStream->setUpperBound(1);
	m_parameter_Attribute_isStream->setTransient(false);
	m_parameter_Attribute_isStream->setVolatile(false);
	m_parameter_Attribute_isStream->setChangeable(true);
	m_parameter_Attribute_isStream->setUnsettable(false);
	m_parameter_Attribute_isStream->setUnique(true);
	m_parameter_Attribute_isStream->setDerived(false);
	m_parameter_Attribute_isStream->setOrdered(false);
	m_parameter_Attribute_isStream->setID(false);
	m_parameter_Attribute_isStream->setDefaultValueLiteral("false");
	
	m_parameter_Attribute_isStream->_setID(PARAMETER_ATTRIBUTE_ISSTREAM);
	
	/*
	 * EReferences
	 */
	m_parameter_Attribute_behavior->setName("behavior");
	m_parameter_Attribute_behavior->setEType(getBehavior_Class());
	m_parameter_Attribute_behavior->setLowerBound(0);
	m_parameter_Attribute_behavior->setUpperBound(1);
	m_parameter_Attribute_behavior->setTransient(false);
	m_parameter_Attribute_behavior->setVolatile(false);
	m_parameter_Attribute_behavior->setChangeable(true);
	m_parameter_Attribute_behavior->setUnsettable(false);
	m_parameter_Attribute_behavior->setUnique(true);
	m_parameter_Attribute_behavior->setDerived(false);
	m_parameter_Attribute_behavior->setOrdered(true);
	m_parameter_Attribute_behavior->setContainment(false);
	m_parameter_Attribute_behavior->setResolveProxies(true);
	m_parameter_Attribute_behavior->setDefaultValueLiteral("");	
	m_parameter_Attribute_behavior->setEOpposite(uml::umlPackage::eInstance()->getBehavior_Attribute_ownedParameter());
	
	m_parameter_Attribute_behavior->_setID(PARAMETER_ATTRIBUTE_BEHAVIOR);
	m_parameter_Attribute_defaultValue->setName("defaultValue");
	m_parameter_Attribute_defaultValue->setEType(getValueSpecification_Class());
	m_parameter_Attribute_defaultValue->setLowerBound(0);
	m_parameter_Attribute_defaultValue->setUpperBound(1);
	m_parameter_Attribute_defaultValue->setTransient(false);
	m_parameter_Attribute_defaultValue->setVolatile(false);
	m_parameter_Attribute_defaultValue->setChangeable(true);
	m_parameter_Attribute_defaultValue->setUnsettable(false);
	m_parameter_Attribute_defaultValue->setUnique(true);
	m_parameter_Attribute_defaultValue->setDerived(false);
	m_parameter_Attribute_defaultValue->setOrdered(false);
	m_parameter_Attribute_defaultValue->setContainment(true);
	m_parameter_Attribute_defaultValue->setResolveProxies(true);
	m_parameter_Attribute_defaultValue->setDefaultValueLiteral("");	
	
	m_parameter_Attribute_defaultValue->_setID(PARAMETER_ATTRIBUTE_DEFAULTVALUE);
	m_parameter_Attribute_operation->setName("operation");
	m_parameter_Attribute_operation->setEType(getOperation_Class());
	m_parameter_Attribute_operation->setLowerBound(0);
	m_parameter_Attribute_operation->setUpperBound(1);
	m_parameter_Attribute_operation->setTransient(true);
	m_parameter_Attribute_operation->setVolatile(true);
	m_parameter_Attribute_operation->setChangeable(false);
	m_parameter_Attribute_operation->setUnsettable(false);
	m_parameter_Attribute_operation->setUnique(true);
	m_parameter_Attribute_operation->setDerived(false);
	m_parameter_Attribute_operation->setOrdered(false);
	m_parameter_Attribute_operation->setContainment(false);
	m_parameter_Attribute_operation->setResolveProxies(true);
	m_parameter_Attribute_operation->setDefaultValueLiteral("");	
	m_parameter_Attribute_operation->setEOpposite(uml::umlPackage::eInstance()->getOperation_Attribute_ownedParameter());
	
	m_parameter_Attribute_operation->_setID(PARAMETER_ATTRIBUTE_OPERATION);
	m_parameter_Attribute_parameterSet->setName("parameterSet");
	m_parameter_Attribute_parameterSet->setEType(getParameterSet_Class());
	m_parameter_Attribute_parameterSet->setLowerBound(0);
	m_parameter_Attribute_parameterSet->setUpperBound(-1);
	m_parameter_Attribute_parameterSet->setTransient(false);
	m_parameter_Attribute_parameterSet->setVolatile(false);
	m_parameter_Attribute_parameterSet->setChangeable(true);
	m_parameter_Attribute_parameterSet->setUnsettable(false);
	m_parameter_Attribute_parameterSet->setUnique(true);
	m_parameter_Attribute_parameterSet->setDerived(false);
	m_parameter_Attribute_parameterSet->setOrdered(false);
	m_parameter_Attribute_parameterSet->setContainment(false);
	m_parameter_Attribute_parameterSet->setResolveProxies(true);
	m_parameter_Attribute_parameterSet->setDefaultValueLiteral("");	
	m_parameter_Attribute_parameterSet->setEOpposite(uml::umlPackage::eInstance()->getParameterSet_Attribute_parameter());
	
	m_parameter_Attribute_parameterSet->_setID(PARAMETER_ATTRIBUTE_PARAMETERSET);
	
	/*
	 * EOperations
	 */
	m_parameter_Operation_isSetDefault->setName("isSetDefault");
	m_parameter_Operation_isSetDefault->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_parameter_Operation_isSetDefault->setLowerBound(1);
	m_parameter_Operation_isSetDefault->setUpperBound(1);
	m_parameter_Operation_isSetDefault->setUnique(true);
	m_parameter_Operation_isSetDefault->setOrdered(false);
	
	m_parameter_Operation_isSetDefault->_setID(PARAMETER_OPERATION_ISSETDEFAULT);
	
	
	m_parameter_Operation_setBooleanDefaultValue_Boolean->setName("setBooleanDefaultValue");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_parameter_Operation_setBooleanDefaultValue_Boolean->setEType(unknownClass);
	}
	m_parameter_Operation_setBooleanDefaultValue_Boolean->setLowerBound(1);
	m_parameter_Operation_setBooleanDefaultValue_Boolean->setUpperBound(1);
	m_parameter_Operation_setBooleanDefaultValue_Boolean->setUnique(true);
	m_parameter_Operation_setBooleanDefaultValue_Boolean->setOrdered(false);
	
	m_parameter_Operation_setBooleanDefaultValue_Boolean->_setID(PARAMETER_OPERATION_SETBOOLEANDEFAULTVALUE_BOOLEAN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_parameter_Operation_setBooleanDefaultValue_Boolean);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_parameter_Operation_setIntegerDefaultValue_Integer->setName("setIntegerDefaultValue");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_parameter_Operation_setIntegerDefaultValue_Integer->setEType(unknownClass);
	}
	m_parameter_Operation_setIntegerDefaultValue_Integer->setLowerBound(1);
	m_parameter_Operation_setIntegerDefaultValue_Integer->setUpperBound(1);
	m_parameter_Operation_setIntegerDefaultValue_Integer->setUnique(true);
	m_parameter_Operation_setIntegerDefaultValue_Integer->setOrdered(false);
	
	m_parameter_Operation_setIntegerDefaultValue_Integer->_setID(PARAMETER_OPERATION_SETINTEGERDEFAULTVALUE_INTEGER);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_parameter_Operation_setIntegerDefaultValue_Integer);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_parameter_Operation_setNullDefaultValue->setName("setNullDefaultValue");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_parameter_Operation_setNullDefaultValue->setEType(unknownClass);
	}
	m_parameter_Operation_setNullDefaultValue->setLowerBound(1);
	m_parameter_Operation_setNullDefaultValue->setUpperBound(1);
	m_parameter_Operation_setNullDefaultValue->setUnique(true);
	m_parameter_Operation_setNullDefaultValue->setOrdered(false);
	
	m_parameter_Operation_setNullDefaultValue->_setID(PARAMETER_OPERATION_SETNULLDEFAULTVALUE);
	
	
	m_parameter_Operation_setRealDefaultValue_Real->setName("setRealDefaultValue");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_parameter_Operation_setRealDefaultValue_Real->setEType(unknownClass);
	}
	m_parameter_Operation_setRealDefaultValue_Real->setLowerBound(1);
	m_parameter_Operation_setRealDefaultValue_Real->setUpperBound(1);
	m_parameter_Operation_setRealDefaultValue_Real->setUnique(true);
	m_parameter_Operation_setRealDefaultValue_Real->setOrdered(false);
	
	m_parameter_Operation_setRealDefaultValue_Real->_setID(PARAMETER_OPERATION_SETREALDEFAULTVALUE_REAL);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_parameter_Operation_setRealDefaultValue_Real);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_parameter_Operation_setStringDefaultValue_String->setName("setStringDefaultValue");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_parameter_Operation_setStringDefaultValue_String->setEType(unknownClass);
	}
	m_parameter_Operation_setStringDefaultValue_String->setLowerBound(1);
	m_parameter_Operation_setStringDefaultValue_String->setUpperBound(1);
	m_parameter_Operation_setStringDefaultValue_String->setUnique(true);
	m_parameter_Operation_setStringDefaultValue_String->setOrdered(false);
	
	m_parameter_Operation_setStringDefaultValue_String->_setID(PARAMETER_OPERATION_SETSTRINGDEFAULTVALUE_STRING);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_parameter_Operation_setStringDefaultValue_String);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_parameter_Operation_setUnlimitedNaturalDefaultValue_UnlimitedNatural->setName("setUnlimitedNaturalDefaultValue");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_parameter_Operation_setUnlimitedNaturalDefaultValue_UnlimitedNatural->setEType(unknownClass);
	}
	m_parameter_Operation_setUnlimitedNaturalDefaultValue_UnlimitedNatural->setLowerBound(1);
	m_parameter_Operation_setUnlimitedNaturalDefaultValue_UnlimitedNatural->setUpperBound(1);
	m_parameter_Operation_setUnlimitedNaturalDefaultValue_UnlimitedNatural->setUnique(true);
	m_parameter_Operation_setUnlimitedNaturalDefaultValue_UnlimitedNatural->setOrdered(false);
	
	m_parameter_Operation_setUnlimitedNaturalDefaultValue_UnlimitedNatural->_setID(PARAMETER_OPERATION_SETUNLIMITEDNATURALDEFAULTVALUE_UNLIMITEDNATURAL);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_parameter_Operation_setUnlimitedNaturalDefaultValue_UnlimitedNatural);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_parameter_Operation_unsetDefault->setName("unsetDefault");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_parameter_Operation_unsetDefault->setEType(unknownClass);
	}
	m_parameter_Operation_unsetDefault->setLowerBound(1);
	m_parameter_Operation_unsetDefault->setUpperBound(1);
	m_parameter_Operation_unsetDefault->setUnique(true);
	m_parameter_Operation_unsetDefault->setOrdered(false);
	
	m_parameter_Operation_unsetDefault->_setID(PARAMETER_OPERATION_UNSETDEFAULT);
	
	
	
}

void umlPackageImpl::initializeParameterSetContent()
{
	m_parameterSet_Class->setName("ParameterSet");
	m_parameterSet_Class->setAbstract(false);
	m_parameterSet_Class->setInterface(false);
	
	m_parameterSet_Class->_setID(PARAMETERSET_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_parameterSet_Attribute_condition->setName("condition");
	m_parameterSet_Attribute_condition->setEType(getConstraint_Class());
	m_parameterSet_Attribute_condition->setLowerBound(0);
	m_parameterSet_Attribute_condition->setUpperBound(-1);
	m_parameterSet_Attribute_condition->setTransient(false);
	m_parameterSet_Attribute_condition->setVolatile(false);
	m_parameterSet_Attribute_condition->setChangeable(true);
	m_parameterSet_Attribute_condition->setUnsettable(false);
	m_parameterSet_Attribute_condition->setUnique(true);
	m_parameterSet_Attribute_condition->setDerived(false);
	m_parameterSet_Attribute_condition->setOrdered(false);
	m_parameterSet_Attribute_condition->setContainment(true);
	m_parameterSet_Attribute_condition->setResolveProxies(true);
	m_parameterSet_Attribute_condition->setDefaultValueLiteral("");	
	
	m_parameterSet_Attribute_condition->_setID(PARAMETERSET_ATTRIBUTE_CONDITION);
	m_parameterSet_Attribute_parameter->setName("parameter");
	m_parameterSet_Attribute_parameter->setEType(getParameter_Class());
	m_parameterSet_Attribute_parameter->setLowerBound(1);
	m_parameterSet_Attribute_parameter->setUpperBound(-1);
	m_parameterSet_Attribute_parameter->setTransient(false);
	m_parameterSet_Attribute_parameter->setVolatile(false);
	m_parameterSet_Attribute_parameter->setChangeable(true);
	m_parameterSet_Attribute_parameter->setUnsettable(false);
	m_parameterSet_Attribute_parameter->setUnique(true);
	m_parameterSet_Attribute_parameter->setDerived(false);
	m_parameterSet_Attribute_parameter->setOrdered(false);
	m_parameterSet_Attribute_parameter->setContainment(false);
	m_parameterSet_Attribute_parameter->setResolveProxies(true);
	m_parameterSet_Attribute_parameter->setDefaultValueLiteral("");	
	m_parameterSet_Attribute_parameter->setEOpposite(uml::umlPackage::eInstance()->getParameter_Attribute_parameterSet());
	
	m_parameterSet_Attribute_parameter->_setID(PARAMETERSET_ATTRIBUTE_PARAMETER);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeParameterableElementContent()
{
	m_parameterableElement_Class->setName("ParameterableElement");
	m_parameterableElement_Class->setAbstract(true);
	m_parameterableElement_Class->setInterface(false);
	
	m_parameterableElement_Class->_setID(PARAMETERABLEELEMENT_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_parameterableElement_Attribute_owningTemplateParameter->setName("owningTemplateParameter");
	m_parameterableElement_Attribute_owningTemplateParameter->setEType(getTemplateParameter_Class());
	m_parameterableElement_Attribute_owningTemplateParameter->setLowerBound(0);
	m_parameterableElement_Attribute_owningTemplateParameter->setUpperBound(1);
	m_parameterableElement_Attribute_owningTemplateParameter->setTransient(false);
	m_parameterableElement_Attribute_owningTemplateParameter->setVolatile(false);
	m_parameterableElement_Attribute_owningTemplateParameter->setChangeable(true);
	m_parameterableElement_Attribute_owningTemplateParameter->setUnsettable(false);
	m_parameterableElement_Attribute_owningTemplateParameter->setUnique(true);
	m_parameterableElement_Attribute_owningTemplateParameter->setDerived(false);
	m_parameterableElement_Attribute_owningTemplateParameter->setOrdered(false);
	m_parameterableElement_Attribute_owningTemplateParameter->setContainment(false);
	m_parameterableElement_Attribute_owningTemplateParameter->setResolveProxies(true);
	m_parameterableElement_Attribute_owningTemplateParameter->setDefaultValueLiteral("");	
	m_parameterableElement_Attribute_owningTemplateParameter->setEOpposite(uml::umlPackage::eInstance()->getTemplateParameter_Attribute_ownedParameteredElement());
	
	m_parameterableElement_Attribute_owningTemplateParameter->_setID(PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER);
	m_parameterableElement_Attribute_templateParameter->setName("templateParameter");
	m_parameterableElement_Attribute_templateParameter->setEType(getTemplateParameter_Class());
	m_parameterableElement_Attribute_templateParameter->setLowerBound(0);
	m_parameterableElement_Attribute_templateParameter->setUpperBound(1);
	m_parameterableElement_Attribute_templateParameter->setTransient(false);
	m_parameterableElement_Attribute_templateParameter->setVolatile(false);
	m_parameterableElement_Attribute_templateParameter->setChangeable(true);
	m_parameterableElement_Attribute_templateParameter->setUnsettable(false);
	m_parameterableElement_Attribute_templateParameter->setUnique(true);
	m_parameterableElement_Attribute_templateParameter->setDerived(false);
	m_parameterableElement_Attribute_templateParameter->setOrdered(false);
	m_parameterableElement_Attribute_templateParameter->setContainment(false);
	m_parameterableElement_Attribute_templateParameter->setResolveProxies(true);
	m_parameterableElement_Attribute_templateParameter->setDefaultValueLiteral("");	
	m_parameterableElement_Attribute_templateParameter->setEOpposite(uml::umlPackage::eInstance()->getTemplateParameter_Attribute_parameteredElement());
	
	m_parameterableElement_Attribute_templateParameter->_setID(PARAMETERABLEELEMENT_ATTRIBUTE_TEMPLATEPARAMETER);
	
	/*
	 * EOperations
	 */
	m_parameterableElement_Operation_isCompatibleWith_ParameterableElement->setName("isCompatibleWith");
	m_parameterableElement_Operation_isCompatibleWith_ParameterableElement->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_parameterableElement_Operation_isCompatibleWith_ParameterableElement->setLowerBound(1);
	m_parameterableElement_Operation_isCompatibleWith_ParameterableElement->setUpperBound(1);
	m_parameterableElement_Operation_isCompatibleWith_ParameterableElement->setUnique(true);
	m_parameterableElement_Operation_isCompatibleWith_ParameterableElement->setOrdered(false);
	
	m_parameterableElement_Operation_isCompatibleWith_ParameterableElement->_setID(PARAMETERABLEELEMENT_OPERATION_ISCOMPATIBLEWITH_PARAMETERABLEELEMENT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_parameterableElement_Operation_isCompatibleWith_ParameterableElement);
		parameter->setName("p");
		parameter->setEType(getParameterableElement_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_parameterableElement_Operation_isTemplateParameter->setName("isTemplateParameter");
	m_parameterableElement_Operation_isTemplateParameter->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_parameterableElement_Operation_isTemplateParameter->setLowerBound(1);
	m_parameterableElement_Operation_isTemplateParameter->setUpperBound(1);
	m_parameterableElement_Operation_isTemplateParameter->setUnique(true);
	m_parameterableElement_Operation_isTemplateParameter->setOrdered(false);
	
	m_parameterableElement_Operation_isTemplateParameter->_setID(PARAMETERABLEELEMENT_OPERATION_ISTEMPLATEPARAMETER);
	
	
	
}

void umlPackageImpl::initializePartDecompositionContent()
{
	m_partDecomposition_Class->setName("PartDecomposition");
	m_partDecomposition_Class->setAbstract(false);
	m_partDecomposition_Class->setInterface(false);
	
	m_partDecomposition_Class->_setID(PARTDECOMPOSITION_CLASS);
	
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

void umlPackageImpl::initializePinContent()
{
	m_pin_Class->setName("Pin");
	m_pin_Class->setAbstract(true);
	m_pin_Class->setInterface(false);
	
	m_pin_Class->_setID(PIN_CLASS);
	
	/*
	 * EAttributes
	 */
	m_pin_Attribute_isControl = getPin_Attribute_isControl();
	m_pin_Attribute_isControl->setName("isControl");
	m_pin_Attribute_isControl->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_pin_Attribute_isControl->setLowerBound(1);
	m_pin_Attribute_isControl->setUpperBound(1);
	m_pin_Attribute_isControl->setTransient(false);
	m_pin_Attribute_isControl->setVolatile(false);
	m_pin_Attribute_isControl->setChangeable(true);
	m_pin_Attribute_isControl->setUnsettable(false);
	m_pin_Attribute_isControl->setUnique(true);
	m_pin_Attribute_isControl->setDerived(false);
	m_pin_Attribute_isControl->setOrdered(false);
	m_pin_Attribute_isControl->setID(false);
	m_pin_Attribute_isControl->setDefaultValueLiteral("false");
	
	m_pin_Attribute_isControl->_setID(PIN_ATTRIBUTE_ISCONTROL);
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializePortContent()
{
	m_port_Class->setName("Port");
	m_port_Class->setAbstract(false);
	m_port_Class->setInterface(false);
	
	m_port_Class->_setID(PORT_CLASS);
	
	/*
	 * EAttributes
	 */
	m_port_Attribute_isBehavior = getPort_Attribute_isBehavior();
	m_port_Attribute_isBehavior->setName("isBehavior");
	m_port_Attribute_isBehavior->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_port_Attribute_isBehavior->setLowerBound(1);
	m_port_Attribute_isBehavior->setUpperBound(1);
	m_port_Attribute_isBehavior->setTransient(false);
	m_port_Attribute_isBehavior->setVolatile(false);
	m_port_Attribute_isBehavior->setChangeable(true);
	m_port_Attribute_isBehavior->setUnsettable(false);
	m_port_Attribute_isBehavior->setUnique(true);
	m_port_Attribute_isBehavior->setDerived(false);
	m_port_Attribute_isBehavior->setOrdered(false);
	m_port_Attribute_isBehavior->setID(false);
	m_port_Attribute_isBehavior->setDefaultValueLiteral("false");
	
	m_port_Attribute_isBehavior->_setID(PORT_ATTRIBUTE_ISBEHAVIOR);
	m_port_Attribute_isConjugated = getPort_Attribute_isConjugated();
	m_port_Attribute_isConjugated->setName("isConjugated");
	m_port_Attribute_isConjugated->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_port_Attribute_isConjugated->setLowerBound(1);
	m_port_Attribute_isConjugated->setUpperBound(1);
	m_port_Attribute_isConjugated->setTransient(false);
	m_port_Attribute_isConjugated->setVolatile(false);
	m_port_Attribute_isConjugated->setChangeable(true);
	m_port_Attribute_isConjugated->setUnsettable(false);
	m_port_Attribute_isConjugated->setUnique(true);
	m_port_Attribute_isConjugated->setDerived(false);
	m_port_Attribute_isConjugated->setOrdered(false);
	m_port_Attribute_isConjugated->setID(false);
	m_port_Attribute_isConjugated->setDefaultValueLiteral("false");
	
	m_port_Attribute_isConjugated->_setID(PORT_ATTRIBUTE_ISCONJUGATED);
	m_port_Attribute_isService = getPort_Attribute_isService();
	m_port_Attribute_isService->setName("isService");
	m_port_Attribute_isService->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_port_Attribute_isService->setLowerBound(1);
	m_port_Attribute_isService->setUpperBound(1);
	m_port_Attribute_isService->setTransient(false);
	m_port_Attribute_isService->setVolatile(false);
	m_port_Attribute_isService->setChangeable(true);
	m_port_Attribute_isService->setUnsettable(false);
	m_port_Attribute_isService->setUnique(true);
	m_port_Attribute_isService->setDerived(false);
	m_port_Attribute_isService->setOrdered(false);
	m_port_Attribute_isService->setID(false);
	m_port_Attribute_isService->setDefaultValueLiteral("true");
	
	m_port_Attribute_isService->_setID(PORT_ATTRIBUTE_ISSERVICE);
	
	/*
	 * EReferences
	 */
	m_port_Attribute_protocol->setName("protocol");
	m_port_Attribute_protocol->setEType(getProtocolStateMachine_Class());
	m_port_Attribute_protocol->setLowerBound(0);
	m_port_Attribute_protocol->setUpperBound(1);
	m_port_Attribute_protocol->setTransient(false);
	m_port_Attribute_protocol->setVolatile(false);
	m_port_Attribute_protocol->setChangeable(true);
	m_port_Attribute_protocol->setUnsettable(false);
	m_port_Attribute_protocol->setUnique(true);
	m_port_Attribute_protocol->setDerived(false);
	m_port_Attribute_protocol->setOrdered(false);
	m_port_Attribute_protocol->setContainment(false);
	m_port_Attribute_protocol->setResolveProxies(true);
	m_port_Attribute_protocol->setDefaultValueLiteral("");	
	
	m_port_Attribute_protocol->_setID(PORT_ATTRIBUTE_PROTOCOL);
	m_port_Attribute_provided->setName("provided");
	m_port_Attribute_provided->setEType(getInterface_Class());
	m_port_Attribute_provided->setLowerBound(0);
	m_port_Attribute_provided->setUpperBound(-1);
	m_port_Attribute_provided->setTransient(true);
	m_port_Attribute_provided->setVolatile(true);
	m_port_Attribute_provided->setChangeable(false);
	m_port_Attribute_provided->setUnsettable(false);
	m_port_Attribute_provided->setUnique(true);
	m_port_Attribute_provided->setDerived(true);
	m_port_Attribute_provided->setOrdered(false);
	m_port_Attribute_provided->setContainment(false);
	m_port_Attribute_provided->setResolveProxies(true);
	m_port_Attribute_provided->setDefaultValueLiteral("");	
	
	m_port_Attribute_provided->_setID(PORT_ATTRIBUTE_PROVIDED);
	m_port_Attribute_redefinedPort->setName("redefinedPort");
	m_port_Attribute_redefinedPort->setEType(getPort_Class());
	m_port_Attribute_redefinedPort->setLowerBound(0);
	m_port_Attribute_redefinedPort->setUpperBound(-1);
	m_port_Attribute_redefinedPort->setTransient(false);
	m_port_Attribute_redefinedPort->setVolatile(false);
	m_port_Attribute_redefinedPort->setChangeable(true);
	m_port_Attribute_redefinedPort->setUnsettable(false);
	m_port_Attribute_redefinedPort->setUnique(true);
	m_port_Attribute_redefinedPort->setDerived(false);
	m_port_Attribute_redefinedPort->setOrdered(false);
	m_port_Attribute_redefinedPort->setContainment(false);
	m_port_Attribute_redefinedPort->setResolveProxies(true);
	m_port_Attribute_redefinedPort->setDefaultValueLiteral("");	
	
	m_port_Attribute_redefinedPort->_setID(PORT_ATTRIBUTE_REDEFINEDPORT);
	m_port_Attribute_required->setName("required");
	m_port_Attribute_required->setEType(getInterface_Class());
	m_port_Attribute_required->setLowerBound(0);
	m_port_Attribute_required->setUpperBound(-1);
	m_port_Attribute_required->setTransient(true);
	m_port_Attribute_required->setVolatile(true);
	m_port_Attribute_required->setChangeable(false);
	m_port_Attribute_required->setUnsettable(false);
	m_port_Attribute_required->setUnique(true);
	m_port_Attribute_required->setDerived(true);
	m_port_Attribute_required->setOrdered(false);
	m_port_Attribute_required->setContainment(false);
	m_port_Attribute_required->setResolveProxies(true);
	m_port_Attribute_required->setDefaultValueLiteral("");	
	
	m_port_Attribute_required->_setID(PORT_ATTRIBUTE_REQUIRED);
	
	/*
	 * EOperations
	 */
	m_port_Operation_basicProvided->setName("basicProvided");
	m_port_Operation_basicProvided->setEType(getInterface_Class());
	m_port_Operation_basicProvided->setLowerBound(0);
	m_port_Operation_basicProvided->setUpperBound(-1);
	m_port_Operation_basicProvided->setUnique(true);
	m_port_Operation_basicProvided->setOrdered(false);
	
	m_port_Operation_basicProvided->_setID(PORT_OPERATION_BASICPROVIDED);
	
	
	m_port_Operation_basicRequired->setName("basicRequired");
	m_port_Operation_basicRequired->setEType(getInterface_Class());
	m_port_Operation_basicRequired->setLowerBound(0);
	m_port_Operation_basicRequired->setUpperBound(-1);
	m_port_Operation_basicRequired->setUnique(true);
	m_port_Operation_basicRequired->setOrdered(false);
	
	m_port_Operation_basicRequired->_setID(PORT_OPERATION_BASICREQUIRED);
	
	
	m_port_Operation_getProvideds->setName("getProvideds");
	m_port_Operation_getProvideds->setEType(getInterface_Class());
	m_port_Operation_getProvideds->setLowerBound(0);
	m_port_Operation_getProvideds->setUpperBound(-1);
	m_port_Operation_getProvideds->setUnique(true);
	m_port_Operation_getProvideds->setOrdered(false);
	
	m_port_Operation_getProvideds->_setID(PORT_OPERATION_GETPROVIDEDS);
	
	
	m_port_Operation_getRequireds->setName("getRequireds");
	m_port_Operation_getRequireds->setEType(getInterface_Class());
	m_port_Operation_getRequireds->setLowerBound(0);
	m_port_Operation_getRequireds->setUpperBound(-1);
	m_port_Operation_getRequireds->setUnique(true);
	m_port_Operation_getRequireds->setOrdered(false);
	
	m_port_Operation_getRequireds->_setID(PORT_OPERATION_GETREQUIREDS);
	
	
	
}

void umlPackageImpl::initializePrimitiveTypeContent()
{
	m_primitiveType_Class->setName("PrimitiveType");
	m_primitiveType_Class->setAbstract(false);
	m_primitiveType_Class->setInterface(false);
	
	m_primitiveType_Class->_setID(PRIMITIVETYPE_CLASS);
	
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

void umlPackageImpl::initializeProfileContent()
{
	m_profile_Class->setName("Profile");
	m_profile_Class->setAbstract(false);
	m_profile_Class->setInterface(false);
	
	m_profile_Class->_setID(PROFILE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_profile_Attribute_metaclassReference->setName("metaclassReference");
	m_profile_Attribute_metaclassReference->setEType(getElementImport_Class());
	m_profile_Attribute_metaclassReference->setLowerBound(0);
	m_profile_Attribute_metaclassReference->setUpperBound(-1);
	m_profile_Attribute_metaclassReference->setTransient(false);
	m_profile_Attribute_metaclassReference->setVolatile(false);
	m_profile_Attribute_metaclassReference->setChangeable(true);
	m_profile_Attribute_metaclassReference->setUnsettable(false);
	m_profile_Attribute_metaclassReference->setUnique(true);
	m_profile_Attribute_metaclassReference->setDerived(false);
	m_profile_Attribute_metaclassReference->setOrdered(false);
	m_profile_Attribute_metaclassReference->setContainment(false);
	m_profile_Attribute_metaclassReference->setResolveProxies(true);
	m_profile_Attribute_metaclassReference->setDefaultValueLiteral("");	
	
	m_profile_Attribute_metaclassReference->_setID(PROFILE_ATTRIBUTE_METACLASSREFERENCE);
	m_profile_Attribute_metamodelReference->setName("metamodelReference");
	m_profile_Attribute_metamodelReference->setEType(getPackageImport_Class());
	m_profile_Attribute_metamodelReference->setLowerBound(0);
	m_profile_Attribute_metamodelReference->setUpperBound(-1);
	m_profile_Attribute_metamodelReference->setTransient(false);
	m_profile_Attribute_metamodelReference->setVolatile(false);
	m_profile_Attribute_metamodelReference->setChangeable(true);
	m_profile_Attribute_metamodelReference->setUnsettable(false);
	m_profile_Attribute_metamodelReference->setUnique(true);
	m_profile_Attribute_metamodelReference->setDerived(false);
	m_profile_Attribute_metamodelReference->setOrdered(false);
	m_profile_Attribute_metamodelReference->setContainment(false);
	m_profile_Attribute_metamodelReference->setResolveProxies(true);
	m_profile_Attribute_metamodelReference->setDefaultValueLiteral("");	
	
	m_profile_Attribute_metamodelReference->_setID(PROFILE_ATTRIBUTE_METAMODELREFERENCE);
	
	/*
	 * EOperations
	 */
	m_profile_Operation_create_Classifier->setName("create");
	m_profile_Operation_create_Classifier->setEType(ecore::ecorePackage::eInstance()->getEObject_Class());
	m_profile_Operation_create_Classifier->setLowerBound(1);
	m_profile_Operation_create_Classifier->setUpperBound(1);
	m_profile_Operation_create_Classifier->setUnique(true);
	m_profile_Operation_create_Classifier->setOrdered(false);
	
	m_profile_Operation_create_Classifier->_setID(PROFILE_OPERATION_CREATE_CLASSIFIER);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_profile_Operation_create_Classifier);
		parameter->setName("classifier");
		parameter->setEType(getClassifier_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_profile_Operation_define->setName("define");
	m_profile_Operation_define->setEType(ecore::ecorePackage::eInstance()->getEPackage_Class());
	m_profile_Operation_define->setLowerBound(0);
	m_profile_Operation_define->setUpperBound(1);
	m_profile_Operation_define->setUnique(true);
	m_profile_Operation_define->setOrdered(false);
	
	m_profile_Operation_define->_setID(PROFILE_OPERATION_DEFINE);
	
	
	m_profile_Operation_define_EMap_EMap->setName("define");
	m_profile_Operation_define_EMap_EMap->setEType(ecore::ecorePackage::eInstance()->getEPackage_Class());
	m_profile_Operation_define_EMap_EMap->setLowerBound(1);
	m_profile_Operation_define_EMap_EMap->setUpperBound(1);
	m_profile_Operation_define_EMap_EMap->setUnique(true);
	m_profile_Operation_define_EMap_EMap->setOrdered(false);
	
	m_profile_Operation_define_EMap_EMap->_setID(PROFILE_OPERATION_DEFINE_EMAP_EMAP);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_profile_Operation_define_EMap_EMap);
		parameter->setName("options");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEMap_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_profile_Operation_define_EMap_EMap);
		parameter->setName("diagnostics");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEDiagnosticChain_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_profile_Operation_define_EMap_EMap);
		parameter->setName("context");
		parameter->setEType(ecore::ecorePackage::eInstance()->getEMap_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_profile_Operation_getDefinition->setName("getDefinition");
	m_profile_Operation_getDefinition->setEType(ecore::ecorePackage::eInstance()->getEPackage_Class());
	m_profile_Operation_getDefinition->setLowerBound(0);
	m_profile_Operation_getDefinition->setUpperBound(1);
	m_profile_Operation_getDefinition->setUnique(true);
	m_profile_Operation_getDefinition->setOrdered(false);
	
	m_profile_Operation_getDefinition->_setID(PROFILE_OPERATION_GETDEFINITION);
	
	
	m_profile_Operation_getDefinition_NamedElement->setName("getDefinition");
	m_profile_Operation_getDefinition_NamedElement->setEType(ecore::ecorePackage::eInstance()->getENamedElement_Class());
	m_profile_Operation_getDefinition_NamedElement->setLowerBound(0);
	m_profile_Operation_getDefinition_NamedElement->setUpperBound(1);
	m_profile_Operation_getDefinition_NamedElement->setUnique(true);
	m_profile_Operation_getDefinition_NamedElement->setOrdered(false);
	
	m_profile_Operation_getDefinition_NamedElement->_setID(PROFILE_OPERATION_GETDEFINITION_NAMEDELEMENT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_profile_Operation_getDefinition_NamedElement);
		parameter->setName("namedElement");
		parameter->setEType(getNamedElement_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_profile_Operation_getOwnedExtensions_Boolean->setName("getOwnedExtensions");
	m_profile_Operation_getOwnedExtensions_Boolean->setEType(getExtension_Class());
	m_profile_Operation_getOwnedExtensions_Boolean->setLowerBound(0);
	m_profile_Operation_getOwnedExtensions_Boolean->setUpperBound(-1);
	m_profile_Operation_getOwnedExtensions_Boolean->setUnique(true);
	m_profile_Operation_getOwnedExtensions_Boolean->setOrdered(false);
	
	m_profile_Operation_getOwnedExtensions_Boolean->_setID(PROFILE_OPERATION_GETOWNEDEXTENSIONS_BOOLEAN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_profile_Operation_getOwnedExtensions_Boolean);
		parameter->setName("requiredOnly");
		parameter->setEType(types::typesPackage::eInstance()->getBoolean_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_profile_Operation_getReferencedMetaclasses->setName("getReferencedMetaclasses");
	m_profile_Operation_getReferencedMetaclasses->setEType(getClass_Class());
	m_profile_Operation_getReferencedMetaclasses->setLowerBound(0);
	m_profile_Operation_getReferencedMetaclasses->setUpperBound(-1);
	m_profile_Operation_getReferencedMetaclasses->setUnique(true);
	m_profile_Operation_getReferencedMetaclasses->setOrdered(false);
	
	m_profile_Operation_getReferencedMetaclasses->_setID(PROFILE_OPERATION_GETREFERENCEDMETACLASSES);
	
	
	m_profile_Operation_getReferencedMetamodels->setName("getReferencedMetamodels");
	m_profile_Operation_getReferencedMetamodels->setEType(getModel_Class());
	m_profile_Operation_getReferencedMetamodels->setLowerBound(0);
	m_profile_Operation_getReferencedMetamodels->setUpperBound(-1);
	m_profile_Operation_getReferencedMetamodels->setUnique(true);
	m_profile_Operation_getReferencedMetamodels->setOrdered(false);
	
	m_profile_Operation_getReferencedMetamodels->_setID(PROFILE_OPERATION_GETREFERENCEDMETAMODELS);
	
	
	m_profile_Operation_isDefined->setName("isDefined");
	m_profile_Operation_isDefined->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_profile_Operation_isDefined->setLowerBound(1);
	m_profile_Operation_isDefined->setUpperBound(1);
	m_profile_Operation_isDefined->setUnique(true);
	m_profile_Operation_isDefined->setOrdered(false);
	
	m_profile_Operation_isDefined->_setID(PROFILE_OPERATION_ISDEFINED);
	
	
	
}

void umlPackageImpl::initializeProfileApplicationContent()
{
	m_profileApplication_Class->setName("ProfileApplication");
	m_profileApplication_Class->setAbstract(false);
	m_profileApplication_Class->setInterface(false);
	
	m_profileApplication_Class->_setID(PROFILEAPPLICATION_CLASS);
	
	/*
	 * EAttributes
	 */
	m_profileApplication_Attribute_isStrict = getProfileApplication_Attribute_isStrict();
	m_profileApplication_Attribute_isStrict->setName("isStrict");
	m_profileApplication_Attribute_isStrict->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_profileApplication_Attribute_isStrict->setLowerBound(1);
	m_profileApplication_Attribute_isStrict->setUpperBound(1);
	m_profileApplication_Attribute_isStrict->setTransient(false);
	m_profileApplication_Attribute_isStrict->setVolatile(false);
	m_profileApplication_Attribute_isStrict->setChangeable(true);
	m_profileApplication_Attribute_isStrict->setUnsettable(false);
	m_profileApplication_Attribute_isStrict->setUnique(true);
	m_profileApplication_Attribute_isStrict->setDerived(false);
	m_profileApplication_Attribute_isStrict->setOrdered(false);
	m_profileApplication_Attribute_isStrict->setID(false);
	m_profileApplication_Attribute_isStrict->setDefaultValueLiteral("false");
	
	m_profileApplication_Attribute_isStrict->_setID(PROFILEAPPLICATION_ATTRIBUTE_ISSTRICT);
	
	/*
	 * EReferences
	 */
	m_profileApplication_Attribute_appliedProfile->setName("appliedProfile");
	m_profileApplication_Attribute_appliedProfile->setEType(getProfile_Class());
	m_profileApplication_Attribute_appliedProfile->setLowerBound(1);
	m_profileApplication_Attribute_appliedProfile->setUpperBound(1);
	m_profileApplication_Attribute_appliedProfile->setTransient(false);
	m_profileApplication_Attribute_appliedProfile->setVolatile(false);
	m_profileApplication_Attribute_appliedProfile->setChangeable(true);
	m_profileApplication_Attribute_appliedProfile->setUnsettable(false);
	m_profileApplication_Attribute_appliedProfile->setUnique(true);
	m_profileApplication_Attribute_appliedProfile->setDerived(false);
	m_profileApplication_Attribute_appliedProfile->setOrdered(false);
	m_profileApplication_Attribute_appliedProfile->setContainment(false);
	m_profileApplication_Attribute_appliedProfile->setResolveProxies(true);
	m_profileApplication_Attribute_appliedProfile->setDefaultValueLiteral("");	
	
	m_profileApplication_Attribute_appliedProfile->_setID(PROFILEAPPLICATION_ATTRIBUTE_APPLIEDPROFILE);
	m_profileApplication_Attribute_applyingPackage->setName("applyingPackage");
	m_profileApplication_Attribute_applyingPackage->setEType(getPackage_Class());
	m_profileApplication_Attribute_applyingPackage->setLowerBound(1);
	m_profileApplication_Attribute_applyingPackage->setUpperBound(1);
	m_profileApplication_Attribute_applyingPackage->setTransient(false);
	m_profileApplication_Attribute_applyingPackage->setVolatile(false);
	m_profileApplication_Attribute_applyingPackage->setChangeable(true);
	m_profileApplication_Attribute_applyingPackage->setUnsettable(false);
	m_profileApplication_Attribute_applyingPackage->setUnique(true);
	m_profileApplication_Attribute_applyingPackage->setDerived(false);
	m_profileApplication_Attribute_applyingPackage->setOrdered(false);
	m_profileApplication_Attribute_applyingPackage->setContainment(false);
	m_profileApplication_Attribute_applyingPackage->setResolveProxies(true);
	m_profileApplication_Attribute_applyingPackage->setDefaultValueLiteral("");	
	m_profileApplication_Attribute_applyingPackage->setEOpposite(uml::umlPackage::eInstance()->getPackage_Attribute_profileApplication());
	
	m_profileApplication_Attribute_applyingPackage->_setID(PROFILEAPPLICATION_ATTRIBUTE_APPLYINGPACKAGE);
	
	/*
	 * EOperations
	 */
	m_profileApplication_Operation_getAppliedDefinition->setName("getAppliedDefinition");
	m_profileApplication_Operation_getAppliedDefinition->setEType(ecore::ecorePackage::eInstance()->getEPackage_Class());
	m_profileApplication_Operation_getAppliedDefinition->setLowerBound(0);
	m_profileApplication_Operation_getAppliedDefinition->setUpperBound(1);
	m_profileApplication_Operation_getAppliedDefinition->setUnique(true);
	m_profileApplication_Operation_getAppliedDefinition->setOrdered(false);
	
	m_profileApplication_Operation_getAppliedDefinition->_setID(PROFILEAPPLICATION_OPERATION_GETAPPLIEDDEFINITION);
	
	
	m_profileApplication_Operation_getAppliedDefinition_NamedElement->setName("getAppliedDefinition");
	m_profileApplication_Operation_getAppliedDefinition_NamedElement->setEType(ecore::ecorePackage::eInstance()->getENamedElement_Class());
	m_profileApplication_Operation_getAppliedDefinition_NamedElement->setLowerBound(0);
	m_profileApplication_Operation_getAppliedDefinition_NamedElement->setUpperBound(1);
	m_profileApplication_Operation_getAppliedDefinition_NamedElement->setUnique(true);
	m_profileApplication_Operation_getAppliedDefinition_NamedElement->setOrdered(false);
	
	m_profileApplication_Operation_getAppliedDefinition_NamedElement->_setID(PROFILEAPPLICATION_OPERATION_GETAPPLIEDDEFINITION_NAMEDELEMENT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_profileApplication_Operation_getAppliedDefinition_NamedElement);
		parameter->setName("namedElement");
		parameter->setEType(getNamedElement_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void umlPackageImpl::initializePropertyContent()
{
	m_property_Class->setName("Property");
	m_property_Class->setAbstract(false);
	m_property_Class->setInterface(false);
	
	m_property_Class->_setID(PROPERTY_CLASS);
	
	/*
	 * EAttributes
	 */
	m_property_Attribute_aggregation = getProperty_Attribute_aggregation();
	m_property_Attribute_aggregation->setName("aggregation");
	m_property_Attribute_aggregation->setEType(getAggregationKind_Class());
	m_property_Attribute_aggregation->setLowerBound(1);
	m_property_Attribute_aggregation->setUpperBound(1);
	m_property_Attribute_aggregation->setTransient(false);
	m_property_Attribute_aggregation->setVolatile(false);
	m_property_Attribute_aggregation->setChangeable(true);
	m_property_Attribute_aggregation->setUnsettable(false);
	m_property_Attribute_aggregation->setUnique(true);
	m_property_Attribute_aggregation->setDerived(false);
	m_property_Attribute_aggregation->setOrdered(false);
	m_property_Attribute_aggregation->setID(false);
	m_property_Attribute_aggregation->setDefaultValueLiteral("none");
	
	m_property_Attribute_aggregation->_setID(PROPERTY_ATTRIBUTE_AGGREGATION);
	m_property_Attribute_default = getProperty_Attribute_default();
	m_property_Attribute_default->setName("default");
	m_property_Attribute_default->setEType(types::typesPackage::eInstance()->getString_Class());
	m_property_Attribute_default->setLowerBound(0);
	m_property_Attribute_default->setUpperBound(1);
	m_property_Attribute_default->setTransient(true);
	m_property_Attribute_default->setVolatile(true);
	m_property_Attribute_default->setChangeable(true);
	m_property_Attribute_default->setUnsettable(true);
	m_property_Attribute_default->setUnique(true);
	m_property_Attribute_default->setDerived(true);
	m_property_Attribute_default->setOrdered(false);
	m_property_Attribute_default->setID(false);
	m_property_Attribute_default->setDefaultValueLiteral("");
	
	m_property_Attribute_default->_setID(PROPERTY_ATTRIBUTE_DEFAULT);
	m_property_Attribute_isComposite = getProperty_Attribute_isComposite();
	m_property_Attribute_isComposite->setName("isComposite");
	m_property_Attribute_isComposite->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_property_Attribute_isComposite->setLowerBound(1);
	m_property_Attribute_isComposite->setUpperBound(1);
	m_property_Attribute_isComposite->setTransient(true);
	m_property_Attribute_isComposite->setVolatile(true);
	m_property_Attribute_isComposite->setChangeable(true);
	m_property_Attribute_isComposite->setUnsettable(false);
	m_property_Attribute_isComposite->setUnique(true);
	m_property_Attribute_isComposite->setDerived(true);
	m_property_Attribute_isComposite->setOrdered(false);
	m_property_Attribute_isComposite->setID(false);
	m_property_Attribute_isComposite->setDefaultValueLiteral("false");
	
	m_property_Attribute_isComposite->_setID(PROPERTY_ATTRIBUTE_ISCOMPOSITE);
	m_property_Attribute_isDerived = getProperty_Attribute_isDerived();
	m_property_Attribute_isDerived->setName("isDerived");
	m_property_Attribute_isDerived->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_property_Attribute_isDerived->setLowerBound(1);
	m_property_Attribute_isDerived->setUpperBound(1);
	m_property_Attribute_isDerived->setTransient(false);
	m_property_Attribute_isDerived->setVolatile(false);
	m_property_Attribute_isDerived->setChangeable(true);
	m_property_Attribute_isDerived->setUnsettable(false);
	m_property_Attribute_isDerived->setUnique(true);
	m_property_Attribute_isDerived->setDerived(false);
	m_property_Attribute_isDerived->setOrdered(false);
	m_property_Attribute_isDerived->setID(false);
	m_property_Attribute_isDerived->setDefaultValueLiteral("false");
	
	m_property_Attribute_isDerived->_setID(PROPERTY_ATTRIBUTE_ISDERIVED);
	m_property_Attribute_isDerivedUnion = getProperty_Attribute_isDerivedUnion();
	m_property_Attribute_isDerivedUnion->setName("isDerivedUnion");
	m_property_Attribute_isDerivedUnion->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_property_Attribute_isDerivedUnion->setLowerBound(1);
	m_property_Attribute_isDerivedUnion->setUpperBound(1);
	m_property_Attribute_isDerivedUnion->setTransient(false);
	m_property_Attribute_isDerivedUnion->setVolatile(false);
	m_property_Attribute_isDerivedUnion->setChangeable(true);
	m_property_Attribute_isDerivedUnion->setUnsettable(false);
	m_property_Attribute_isDerivedUnion->setUnique(true);
	m_property_Attribute_isDerivedUnion->setDerived(false);
	m_property_Attribute_isDerivedUnion->setOrdered(false);
	m_property_Attribute_isDerivedUnion->setID(false);
	m_property_Attribute_isDerivedUnion->setDefaultValueLiteral("false");
	
	m_property_Attribute_isDerivedUnion->_setID(PROPERTY_ATTRIBUTE_ISDERIVEDUNION);
	m_property_Attribute_isID = getProperty_Attribute_isID();
	m_property_Attribute_isID->setName("isID");
	m_property_Attribute_isID->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_property_Attribute_isID->setLowerBound(1);
	m_property_Attribute_isID->setUpperBound(1);
	m_property_Attribute_isID->setTransient(false);
	m_property_Attribute_isID->setVolatile(false);
	m_property_Attribute_isID->setChangeable(true);
	m_property_Attribute_isID->setUnsettable(false);
	m_property_Attribute_isID->setUnique(true);
	m_property_Attribute_isID->setDerived(false);
	m_property_Attribute_isID->setOrdered(false);
	m_property_Attribute_isID->setID(false);
	m_property_Attribute_isID->setDefaultValueLiteral("false");
	
	m_property_Attribute_isID->_setID(PROPERTY_ATTRIBUTE_ISID);
	
	/*
	 * EReferences
	 */
	m_property_Attribute_association->setName("association");
	m_property_Attribute_association->setEType(getAssociation_Class());
	m_property_Attribute_association->setLowerBound(0);
	m_property_Attribute_association->setUpperBound(1);
	m_property_Attribute_association->setTransient(false);
	m_property_Attribute_association->setVolatile(false);
	m_property_Attribute_association->setChangeable(true);
	m_property_Attribute_association->setUnsettable(false);
	m_property_Attribute_association->setUnique(true);
	m_property_Attribute_association->setDerived(false);
	m_property_Attribute_association->setOrdered(false);
	m_property_Attribute_association->setContainment(false);
	m_property_Attribute_association->setResolveProxies(true);
	m_property_Attribute_association->setDefaultValueLiteral("");	
	m_property_Attribute_association->setEOpposite(uml::umlPackage::eInstance()->getAssociation_Attribute_memberEnd());
	
	m_property_Attribute_association->_setID(PROPERTY_ATTRIBUTE_ASSOCIATION);
	m_property_Attribute_associationEnd->setName("associationEnd");
	m_property_Attribute_associationEnd->setEType(getProperty_Class());
	m_property_Attribute_associationEnd->setLowerBound(0);
	m_property_Attribute_associationEnd->setUpperBound(1);
	m_property_Attribute_associationEnd->setTransient(false);
	m_property_Attribute_associationEnd->setVolatile(false);
	m_property_Attribute_associationEnd->setChangeable(true);
	m_property_Attribute_associationEnd->setUnsettable(false);
	m_property_Attribute_associationEnd->setUnique(true);
	m_property_Attribute_associationEnd->setDerived(false);
	m_property_Attribute_associationEnd->setOrdered(false);
	m_property_Attribute_associationEnd->setContainment(false);
	m_property_Attribute_associationEnd->setResolveProxies(true);
	m_property_Attribute_associationEnd->setDefaultValueLiteral("");	
	m_property_Attribute_associationEnd->setEOpposite(uml::umlPackage::eInstance()->getProperty_Attribute_qualifier());
	
	m_property_Attribute_associationEnd->_setID(PROPERTY_ATTRIBUTE_ASSOCIATIONEND);
	m_property_Attribute_class->setName("class");
	m_property_Attribute_class->setEType(getClass_Class());
	m_property_Attribute_class->setLowerBound(0);
	m_property_Attribute_class->setUpperBound(1);
	m_property_Attribute_class->setTransient(true);
	m_property_Attribute_class->setVolatile(true);
	m_property_Attribute_class->setChangeable(true);
	m_property_Attribute_class->setUnsettable(false);
	m_property_Attribute_class->setUnique(true);
	m_property_Attribute_class->setDerived(false);
	m_property_Attribute_class->setOrdered(false);
	m_property_Attribute_class->setContainment(false);
	m_property_Attribute_class->setResolveProxies(true);
	m_property_Attribute_class->setDefaultValueLiteral("");	
	m_property_Attribute_class->setEOpposite(uml::umlPackage::eInstance()->getClass_Attribute_ownedAttribute());
	
	m_property_Attribute_class->_setID(PROPERTY_ATTRIBUTE_CLASS);
	m_property_Attribute_datatype->setName("datatype");
	m_property_Attribute_datatype->setEType(getDataType_Class());
	m_property_Attribute_datatype->setLowerBound(0);
	m_property_Attribute_datatype->setUpperBound(1);
	m_property_Attribute_datatype->setTransient(false);
	m_property_Attribute_datatype->setVolatile(false);
	m_property_Attribute_datatype->setChangeable(true);
	m_property_Attribute_datatype->setUnsettable(false);
	m_property_Attribute_datatype->setUnique(true);
	m_property_Attribute_datatype->setDerived(false);
	m_property_Attribute_datatype->setOrdered(false);
	m_property_Attribute_datatype->setContainment(false);
	m_property_Attribute_datatype->setResolveProxies(true);
	m_property_Attribute_datatype->setDefaultValueLiteral("");	
	m_property_Attribute_datatype->setEOpposite(uml::umlPackage::eInstance()->getDataType_Attribute_ownedAttribute());
	
	m_property_Attribute_datatype->_setID(PROPERTY_ATTRIBUTE_DATATYPE);
	m_property_Attribute_defaultValue->setName("defaultValue");
	m_property_Attribute_defaultValue->setEType(getValueSpecification_Class());
	m_property_Attribute_defaultValue->setLowerBound(0);
	m_property_Attribute_defaultValue->setUpperBound(1);
	m_property_Attribute_defaultValue->setTransient(false);
	m_property_Attribute_defaultValue->setVolatile(false);
	m_property_Attribute_defaultValue->setChangeable(true);
	m_property_Attribute_defaultValue->setUnsettable(false);
	m_property_Attribute_defaultValue->setUnique(true);
	m_property_Attribute_defaultValue->setDerived(false);
	m_property_Attribute_defaultValue->setOrdered(false);
	m_property_Attribute_defaultValue->setContainment(true);
	m_property_Attribute_defaultValue->setResolveProxies(true);
	m_property_Attribute_defaultValue->setDefaultValueLiteral("");	
	
	m_property_Attribute_defaultValue->_setID(PROPERTY_ATTRIBUTE_DEFAULTVALUE);
	m_property_Attribute_interface->setName("interface");
	m_property_Attribute_interface->setEType(getInterface_Class());
	m_property_Attribute_interface->setLowerBound(0);
	m_property_Attribute_interface->setUpperBound(1);
	m_property_Attribute_interface->setTransient(false);
	m_property_Attribute_interface->setVolatile(false);
	m_property_Attribute_interface->setChangeable(true);
	m_property_Attribute_interface->setUnsettable(false);
	m_property_Attribute_interface->setUnique(true);
	m_property_Attribute_interface->setDerived(false);
	m_property_Attribute_interface->setOrdered(false);
	m_property_Attribute_interface->setContainment(false);
	m_property_Attribute_interface->setResolveProxies(true);
	m_property_Attribute_interface->setDefaultValueLiteral("");	
	m_property_Attribute_interface->setEOpposite(uml::umlPackage::eInstance()->getInterface_Attribute_ownedAttribute());
	
	m_property_Attribute_interface->_setID(PROPERTY_ATTRIBUTE_INTERFACE);
	m_property_Attribute_opposite->setName("opposite");
	m_property_Attribute_opposite->setEType(getProperty_Class());
	m_property_Attribute_opposite->setLowerBound(0);
	m_property_Attribute_opposite->setUpperBound(1);
	m_property_Attribute_opposite->setTransient(true);
	m_property_Attribute_opposite->setVolatile(true);
	m_property_Attribute_opposite->setChangeable(true);
	m_property_Attribute_opposite->setUnsettable(false);
	m_property_Attribute_opposite->setUnique(true);
	m_property_Attribute_opposite->setDerived(true);
	m_property_Attribute_opposite->setOrdered(false);
	m_property_Attribute_opposite->setContainment(false);
	m_property_Attribute_opposite->setResolveProxies(true);
	m_property_Attribute_opposite->setDefaultValueLiteral("");	
	
	m_property_Attribute_opposite->_setID(PROPERTY_ATTRIBUTE_OPPOSITE);
	m_property_Attribute_owningAssociation->setName("owningAssociation");
	m_property_Attribute_owningAssociation->setEType(getAssociation_Class());
	m_property_Attribute_owningAssociation->setLowerBound(0);
	m_property_Attribute_owningAssociation->setUpperBound(1);
	m_property_Attribute_owningAssociation->setTransient(false);
	m_property_Attribute_owningAssociation->setVolatile(false);
	m_property_Attribute_owningAssociation->setChangeable(true);
	m_property_Attribute_owningAssociation->setUnsettable(false);
	m_property_Attribute_owningAssociation->setUnique(true);
	m_property_Attribute_owningAssociation->setDerived(false);
	m_property_Attribute_owningAssociation->setOrdered(false);
	m_property_Attribute_owningAssociation->setContainment(false);
	m_property_Attribute_owningAssociation->setResolveProxies(true);
	m_property_Attribute_owningAssociation->setDefaultValueLiteral("");	
	m_property_Attribute_owningAssociation->setEOpposite(uml::umlPackage::eInstance()->getAssociation_Attribute_ownedEnd());
	
	m_property_Attribute_owningAssociation->_setID(PROPERTY_ATTRIBUTE_OWNINGASSOCIATION);
	m_property_Attribute_qualifier->setName("qualifier");
	m_property_Attribute_qualifier->setEType(getProperty_Class());
	m_property_Attribute_qualifier->setLowerBound(0);
	m_property_Attribute_qualifier->setUpperBound(-1);
	m_property_Attribute_qualifier->setTransient(false);
	m_property_Attribute_qualifier->setVolatile(false);
	m_property_Attribute_qualifier->setChangeable(true);
	m_property_Attribute_qualifier->setUnsettable(false);
	m_property_Attribute_qualifier->setUnique(true);
	m_property_Attribute_qualifier->setDerived(false);
	m_property_Attribute_qualifier->setOrdered(true);
	m_property_Attribute_qualifier->setContainment(true);
	m_property_Attribute_qualifier->setResolveProxies(true);
	m_property_Attribute_qualifier->setDefaultValueLiteral("");	
	m_property_Attribute_qualifier->setEOpposite(uml::umlPackage::eInstance()->getProperty_Attribute_associationEnd());
	
	m_property_Attribute_qualifier->_setID(PROPERTY_ATTRIBUTE_QUALIFIER);
	m_property_Attribute_redefinedProperty->setName("redefinedProperty");
	m_property_Attribute_redefinedProperty->setEType(getProperty_Class());
	m_property_Attribute_redefinedProperty->setLowerBound(0);
	m_property_Attribute_redefinedProperty->setUpperBound(-1);
	m_property_Attribute_redefinedProperty->setTransient(false);
	m_property_Attribute_redefinedProperty->setVolatile(false);
	m_property_Attribute_redefinedProperty->setChangeable(true);
	m_property_Attribute_redefinedProperty->setUnsettable(false);
	m_property_Attribute_redefinedProperty->setUnique(true);
	m_property_Attribute_redefinedProperty->setDerived(false);
	m_property_Attribute_redefinedProperty->setOrdered(false);
	m_property_Attribute_redefinedProperty->setContainment(false);
	m_property_Attribute_redefinedProperty->setResolveProxies(true);
	m_property_Attribute_redefinedProperty->setDefaultValueLiteral("");	
	
	m_property_Attribute_redefinedProperty->_setID(PROPERTY_ATTRIBUTE_REDEFINEDPROPERTY);
	m_property_Attribute_subsettedProperty->setName("subsettedProperty");
	m_property_Attribute_subsettedProperty->setEType(getProperty_Class());
	m_property_Attribute_subsettedProperty->setLowerBound(0);
	m_property_Attribute_subsettedProperty->setUpperBound(-1);
	m_property_Attribute_subsettedProperty->setTransient(false);
	m_property_Attribute_subsettedProperty->setVolatile(false);
	m_property_Attribute_subsettedProperty->setChangeable(true);
	m_property_Attribute_subsettedProperty->setUnsettable(false);
	m_property_Attribute_subsettedProperty->setUnique(true);
	m_property_Attribute_subsettedProperty->setDerived(false);
	m_property_Attribute_subsettedProperty->setOrdered(false);
	m_property_Attribute_subsettedProperty->setContainment(false);
	m_property_Attribute_subsettedProperty->setResolveProxies(true);
	m_property_Attribute_subsettedProperty->setDefaultValueLiteral("");	
	
	m_property_Attribute_subsettedProperty->_setID(PROPERTY_ATTRIBUTE_SUBSETTEDPROPERTY);
	
	/*
	 * EOperations
	 */
	m_property_Operation_getOpposite->setName("getOpposite");
	m_property_Operation_getOpposite->setEType(getProperty_Class());
	m_property_Operation_getOpposite->setLowerBound(0);
	m_property_Operation_getOpposite->setUpperBound(1);
	m_property_Operation_getOpposite->setUnique(true);
	m_property_Operation_getOpposite->setOrdered(false);
	
	m_property_Operation_getOpposite->_setID(PROPERTY_OPERATION_GETOPPOSITE);
	
	
	m_property_Operation_getOtherEnd->setName("getOtherEnd");
	m_property_Operation_getOtherEnd->setEType(getProperty_Class());
	m_property_Operation_getOtherEnd->setLowerBound(0);
	m_property_Operation_getOtherEnd->setUpperBound(1);
	m_property_Operation_getOtherEnd->setUnique(true);
	m_property_Operation_getOtherEnd->setOrdered(false);
	
	m_property_Operation_getOtherEnd->_setID(PROPERTY_OPERATION_GETOTHEREND);
	
	
	m_property_Operation_isAttribute->setName("isAttribute");
	m_property_Operation_isAttribute->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_property_Operation_isAttribute->setLowerBound(1);
	m_property_Operation_isAttribute->setUpperBound(1);
	m_property_Operation_isAttribute->setUnique(true);
	m_property_Operation_isAttribute->setOrdered(false);
	
	m_property_Operation_isAttribute->_setID(PROPERTY_OPERATION_ISATTRIBUTE);
	
	
	m_property_Operation_isComposite->setName("isComposite");
	m_property_Operation_isComposite->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_property_Operation_isComposite->setLowerBound(1);
	m_property_Operation_isComposite->setUpperBound(1);
	m_property_Operation_isComposite->setUnique(true);
	m_property_Operation_isComposite->setOrdered(false);
	
	m_property_Operation_isComposite->_setID(PROPERTY_OPERATION_ISCOMPOSITE);
	
	
	m_property_Operation_isNavigable->setName("isNavigable");
	m_property_Operation_isNavigable->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_property_Operation_isNavigable->setLowerBound(1);
	m_property_Operation_isNavigable->setUpperBound(1);
	m_property_Operation_isNavigable->setUnique(true);
	m_property_Operation_isNavigable->setOrdered(false);
	
	m_property_Operation_isNavigable->_setID(PROPERTY_OPERATION_ISNAVIGABLE);
	
	
	m_property_Operation_isSetDefault->setName("isSetDefault");
	m_property_Operation_isSetDefault->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_property_Operation_isSetDefault->setLowerBound(1);
	m_property_Operation_isSetDefault->setUpperBound(1);
	m_property_Operation_isSetDefault->setUnique(true);
	m_property_Operation_isSetDefault->setOrdered(false);
	
	m_property_Operation_isSetDefault->_setID(PROPERTY_OPERATION_ISSETDEFAULT);
	
	
	m_property_Operation_setBooleanDefaultValue_Boolean->setName("setBooleanDefaultValue");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_property_Operation_setBooleanDefaultValue_Boolean->setEType(unknownClass);
	}
	m_property_Operation_setBooleanDefaultValue_Boolean->setLowerBound(1);
	m_property_Operation_setBooleanDefaultValue_Boolean->setUpperBound(1);
	m_property_Operation_setBooleanDefaultValue_Boolean->setUnique(true);
	m_property_Operation_setBooleanDefaultValue_Boolean->setOrdered(false);
	
	m_property_Operation_setBooleanDefaultValue_Boolean->_setID(PROPERTY_OPERATION_SETBOOLEANDEFAULTVALUE_BOOLEAN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_property_Operation_setBooleanDefaultValue_Boolean);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_property_Operation_setIntegerDefaultValue_Integer->setName("setIntegerDefaultValue");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_property_Operation_setIntegerDefaultValue_Integer->setEType(unknownClass);
	}
	m_property_Operation_setIntegerDefaultValue_Integer->setLowerBound(1);
	m_property_Operation_setIntegerDefaultValue_Integer->setUpperBound(1);
	m_property_Operation_setIntegerDefaultValue_Integer->setUnique(true);
	m_property_Operation_setIntegerDefaultValue_Integer->setOrdered(false);
	
	m_property_Operation_setIntegerDefaultValue_Integer->_setID(PROPERTY_OPERATION_SETINTEGERDEFAULTVALUE_INTEGER);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_property_Operation_setIntegerDefaultValue_Integer);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_property_Operation_setIsNavigable_Boolean->setName("setIsNavigable");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_property_Operation_setIsNavigable_Boolean->setEType(unknownClass);
	}
	m_property_Operation_setIsNavigable_Boolean->setLowerBound(1);
	m_property_Operation_setIsNavigable_Boolean->setUpperBound(1);
	m_property_Operation_setIsNavigable_Boolean->setUnique(true);
	m_property_Operation_setIsNavigable_Boolean->setOrdered(false);
	
	m_property_Operation_setIsNavigable_Boolean->_setID(PROPERTY_OPERATION_SETISNAVIGABLE_BOOLEAN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_property_Operation_setIsNavigable_Boolean);
		parameter->setName("isNavigable");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_property_Operation_setNullDefaultValue->setName("setNullDefaultValue");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_property_Operation_setNullDefaultValue->setEType(unknownClass);
	}
	m_property_Operation_setNullDefaultValue->setLowerBound(1);
	m_property_Operation_setNullDefaultValue->setUpperBound(1);
	m_property_Operation_setNullDefaultValue->setUnique(true);
	m_property_Operation_setNullDefaultValue->setOrdered(false);
	
	m_property_Operation_setNullDefaultValue->_setID(PROPERTY_OPERATION_SETNULLDEFAULTVALUE);
	
	
	m_property_Operation_setRealDefaultValue_Real->setName("setRealDefaultValue");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_property_Operation_setRealDefaultValue_Real->setEType(unknownClass);
	}
	m_property_Operation_setRealDefaultValue_Real->setLowerBound(1);
	m_property_Operation_setRealDefaultValue_Real->setUpperBound(1);
	m_property_Operation_setRealDefaultValue_Real->setUnique(true);
	m_property_Operation_setRealDefaultValue_Real->setOrdered(false);
	
	m_property_Operation_setRealDefaultValue_Real->_setID(PROPERTY_OPERATION_SETREALDEFAULTVALUE_REAL);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_property_Operation_setRealDefaultValue_Real);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_property_Operation_setStringDefaultValue_String->setName("setStringDefaultValue");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_property_Operation_setStringDefaultValue_String->setEType(unknownClass);
	}
	m_property_Operation_setStringDefaultValue_String->setLowerBound(1);
	m_property_Operation_setStringDefaultValue_String->setUpperBound(1);
	m_property_Operation_setStringDefaultValue_String->setUnique(true);
	m_property_Operation_setStringDefaultValue_String->setOrdered(false);
	
	m_property_Operation_setStringDefaultValue_String->_setID(PROPERTY_OPERATION_SETSTRINGDEFAULTVALUE_STRING);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_property_Operation_setStringDefaultValue_String);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_property_Operation_setUnlimitedNaturalDefaultValue_UnlimitedNatural->setName("setUnlimitedNaturalDefaultValue");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_property_Operation_setUnlimitedNaturalDefaultValue_UnlimitedNatural->setEType(unknownClass);
	}
	m_property_Operation_setUnlimitedNaturalDefaultValue_UnlimitedNatural->setLowerBound(1);
	m_property_Operation_setUnlimitedNaturalDefaultValue_UnlimitedNatural->setUpperBound(1);
	m_property_Operation_setUnlimitedNaturalDefaultValue_UnlimitedNatural->setUnique(true);
	m_property_Operation_setUnlimitedNaturalDefaultValue_UnlimitedNatural->setOrdered(false);
	
	m_property_Operation_setUnlimitedNaturalDefaultValue_UnlimitedNatural->_setID(PROPERTY_OPERATION_SETUNLIMITEDNATURALDEFAULTVALUE_UNLIMITEDNATURAL);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_property_Operation_setUnlimitedNaturalDefaultValue_UnlimitedNatural);
		parameter->setName("value");
		parameter->setEType(nullptr);
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_property_Operation_subsettingContext->setName("subsettingContext");
	m_property_Operation_subsettingContext->setEType(getType_Class());
	m_property_Operation_subsettingContext->setLowerBound(0);
	m_property_Operation_subsettingContext->setUpperBound(-1);
	m_property_Operation_subsettingContext->setUnique(true);
	m_property_Operation_subsettingContext->setOrdered(false);
	
	m_property_Operation_subsettingContext->_setID(PROPERTY_OPERATION_SUBSETTINGCONTEXT);
	
	
	m_property_Operation_unsetDefault->setName("unsetDefault");
	{ 	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();
		std::shared_ptr<ecore::EClass> unknownClass = factory ->createEClass(-1);
	   	unknownClass->setName("invalid");
		unknownClass->setAbstract(true);
		unknownClass->setInterface(true);
		m_property_Operation_unsetDefault->setEType(unknownClass);
	}
	m_property_Operation_unsetDefault->setLowerBound(1);
	m_property_Operation_unsetDefault->setUpperBound(1);
	m_property_Operation_unsetDefault->setUnique(true);
	m_property_Operation_unsetDefault->setOrdered(false);
	
	m_property_Operation_unsetDefault->_setID(PROPERTY_OPERATION_UNSETDEFAULT);
	
	
	
}

void umlPackageImpl::initializeProtocolConformanceContent()
{
	m_protocolConformance_Class->setName("ProtocolConformance");
	m_protocolConformance_Class->setAbstract(false);
	m_protocolConformance_Class->setInterface(false);
	
	m_protocolConformance_Class->_setID(PROTOCOLCONFORMANCE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_protocolConformance_Attribute_generalMachine->setName("generalMachine");
	m_protocolConformance_Attribute_generalMachine->setEType(getProtocolStateMachine_Class());
	m_protocolConformance_Attribute_generalMachine->setLowerBound(1);
	m_protocolConformance_Attribute_generalMachine->setUpperBound(1);
	m_protocolConformance_Attribute_generalMachine->setTransient(false);
	m_protocolConformance_Attribute_generalMachine->setVolatile(false);
	m_protocolConformance_Attribute_generalMachine->setChangeable(true);
	m_protocolConformance_Attribute_generalMachine->setUnsettable(false);
	m_protocolConformance_Attribute_generalMachine->setUnique(true);
	m_protocolConformance_Attribute_generalMachine->setDerived(false);
	m_protocolConformance_Attribute_generalMachine->setOrdered(false);
	m_protocolConformance_Attribute_generalMachine->setContainment(false);
	m_protocolConformance_Attribute_generalMachine->setResolveProxies(true);
	m_protocolConformance_Attribute_generalMachine->setDefaultValueLiteral("");	
	
	m_protocolConformance_Attribute_generalMachine->_setID(PROTOCOLCONFORMANCE_ATTRIBUTE_GENERALMACHINE);
	m_protocolConformance_Attribute_specificMachine->setName("specificMachine");
	m_protocolConformance_Attribute_specificMachine->setEType(getProtocolStateMachine_Class());
	m_protocolConformance_Attribute_specificMachine->setLowerBound(1);
	m_protocolConformance_Attribute_specificMachine->setUpperBound(1);
	m_protocolConformance_Attribute_specificMachine->setTransient(false);
	m_protocolConformance_Attribute_specificMachine->setVolatile(false);
	m_protocolConformance_Attribute_specificMachine->setChangeable(true);
	m_protocolConformance_Attribute_specificMachine->setUnsettable(false);
	m_protocolConformance_Attribute_specificMachine->setUnique(true);
	m_protocolConformance_Attribute_specificMachine->setDerived(false);
	m_protocolConformance_Attribute_specificMachine->setOrdered(false);
	m_protocolConformance_Attribute_specificMachine->setContainment(false);
	m_protocolConformance_Attribute_specificMachine->setResolveProxies(true);
	m_protocolConformance_Attribute_specificMachine->setDefaultValueLiteral("");	
	m_protocolConformance_Attribute_specificMachine->setEOpposite(uml::umlPackage::eInstance()->getProtocolStateMachine_Attribute_conformance());
	
	m_protocolConformance_Attribute_specificMachine->_setID(PROTOCOLCONFORMANCE_ATTRIBUTE_SPECIFICMACHINE);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeProtocolStateMachineContent()
{
	m_protocolStateMachine_Class->setName("ProtocolStateMachine");
	m_protocolStateMachine_Class->setAbstract(false);
	m_protocolStateMachine_Class->setInterface(false);
	
	m_protocolStateMachine_Class->_setID(PROTOCOLSTATEMACHINE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_protocolStateMachine_Attribute_conformance->setName("conformance");
	m_protocolStateMachine_Attribute_conformance->setEType(getProtocolConformance_Class());
	m_protocolStateMachine_Attribute_conformance->setLowerBound(0);
	m_protocolStateMachine_Attribute_conformance->setUpperBound(-1);
	m_protocolStateMachine_Attribute_conformance->setTransient(false);
	m_protocolStateMachine_Attribute_conformance->setVolatile(false);
	m_protocolStateMachine_Attribute_conformance->setChangeable(true);
	m_protocolStateMachine_Attribute_conformance->setUnsettable(false);
	m_protocolStateMachine_Attribute_conformance->setUnique(true);
	m_protocolStateMachine_Attribute_conformance->setDerived(false);
	m_protocolStateMachine_Attribute_conformance->setOrdered(false);
	m_protocolStateMachine_Attribute_conformance->setContainment(true);
	m_protocolStateMachine_Attribute_conformance->setResolveProxies(true);
	m_protocolStateMachine_Attribute_conformance->setDefaultValueLiteral("");	
	m_protocolStateMachine_Attribute_conformance->setEOpposite(uml::umlPackage::eInstance()->getProtocolConformance_Attribute_specificMachine());
	
	m_protocolStateMachine_Attribute_conformance->_setID(PROTOCOLSTATEMACHINE_ATTRIBUTE_CONFORMANCE);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeProtocolTransitionContent()
{
	m_protocolTransition_Class->setName("ProtocolTransition");
	m_protocolTransition_Class->setAbstract(false);
	m_protocolTransition_Class->setInterface(false);
	
	m_protocolTransition_Class->_setID(PROTOCOLTRANSITION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_protocolTransition_Attribute_postCondition->setName("postCondition");
	m_protocolTransition_Attribute_postCondition->setEType(getConstraint_Class());
	m_protocolTransition_Attribute_postCondition->setLowerBound(0);
	m_protocolTransition_Attribute_postCondition->setUpperBound(1);
	m_protocolTransition_Attribute_postCondition->setTransient(false);
	m_protocolTransition_Attribute_postCondition->setVolatile(false);
	m_protocolTransition_Attribute_postCondition->setChangeable(true);
	m_protocolTransition_Attribute_postCondition->setUnsettable(false);
	m_protocolTransition_Attribute_postCondition->setUnique(true);
	m_protocolTransition_Attribute_postCondition->setDerived(false);
	m_protocolTransition_Attribute_postCondition->setOrdered(false);
	m_protocolTransition_Attribute_postCondition->setContainment(false);
	m_protocolTransition_Attribute_postCondition->setResolveProxies(true);
	m_protocolTransition_Attribute_postCondition->setDefaultValueLiteral("");	
	
	m_protocolTransition_Attribute_postCondition->_setID(PROTOCOLTRANSITION_ATTRIBUTE_POSTCONDITION);
	m_protocolTransition_Attribute_preCondition->setName("preCondition");
	m_protocolTransition_Attribute_preCondition->setEType(getConstraint_Class());
	m_protocolTransition_Attribute_preCondition->setLowerBound(0);
	m_protocolTransition_Attribute_preCondition->setUpperBound(1);
	m_protocolTransition_Attribute_preCondition->setTransient(false);
	m_protocolTransition_Attribute_preCondition->setVolatile(false);
	m_protocolTransition_Attribute_preCondition->setChangeable(true);
	m_protocolTransition_Attribute_preCondition->setUnsettable(false);
	m_protocolTransition_Attribute_preCondition->setUnique(true);
	m_protocolTransition_Attribute_preCondition->setDerived(false);
	m_protocolTransition_Attribute_preCondition->setOrdered(false);
	m_protocolTransition_Attribute_preCondition->setContainment(false);
	m_protocolTransition_Attribute_preCondition->setResolveProxies(true);
	m_protocolTransition_Attribute_preCondition->setDefaultValueLiteral("");	
	
	m_protocolTransition_Attribute_preCondition->_setID(PROTOCOLTRANSITION_ATTRIBUTE_PRECONDITION);
	m_protocolTransition_Attribute_referred->setName("referred");
	m_protocolTransition_Attribute_referred->setEType(getOperation_Class());
	m_protocolTransition_Attribute_referred->setLowerBound(0);
	m_protocolTransition_Attribute_referred->setUpperBound(-1);
	m_protocolTransition_Attribute_referred->setTransient(true);
	m_protocolTransition_Attribute_referred->setVolatile(true);
	m_protocolTransition_Attribute_referred->setChangeable(false);
	m_protocolTransition_Attribute_referred->setUnsettable(false);
	m_protocolTransition_Attribute_referred->setUnique(true);
	m_protocolTransition_Attribute_referred->setDerived(true);
	m_protocolTransition_Attribute_referred->setOrdered(false);
	m_protocolTransition_Attribute_referred->setContainment(false);
	m_protocolTransition_Attribute_referred->setResolveProxies(true);
	m_protocolTransition_Attribute_referred->setDefaultValueLiteral("");	
	
	m_protocolTransition_Attribute_referred->_setID(PROTOCOLTRANSITION_ATTRIBUTE_REFERRED);
	
	/*
	 * EOperations
	 */
	m_protocolTransition_Operation_getReferreds->setName("getReferreds");
	m_protocolTransition_Operation_getReferreds->setEType(getOperation_Class());
	m_protocolTransition_Operation_getReferreds->setLowerBound(0);
	m_protocolTransition_Operation_getReferreds->setUpperBound(-1);
	m_protocolTransition_Operation_getReferreds->setUnique(true);
	m_protocolTransition_Operation_getReferreds->setOrdered(false);
	
	m_protocolTransition_Operation_getReferreds->_setID(PROTOCOLTRANSITION_OPERATION_GETREFERREDS);
	
	
	
}

void umlPackageImpl::initializePseudostateContent()
{
	m_pseudostate_Class->setName("Pseudostate");
	m_pseudostate_Class->setAbstract(false);
	m_pseudostate_Class->setInterface(false);
	
	m_pseudostate_Class->_setID(PSEUDOSTATE_CLASS);
	
	/*
	 * EAttributes
	 */
	m_pseudostate_Attribute_kind = getPseudostate_Attribute_kind();
	m_pseudostate_Attribute_kind->setName("kind");
	m_pseudostate_Attribute_kind->setEType(getPseudostateKind_Class());
	m_pseudostate_Attribute_kind->setLowerBound(1);
	m_pseudostate_Attribute_kind->setUpperBound(1);
	m_pseudostate_Attribute_kind->setTransient(false);
	m_pseudostate_Attribute_kind->setVolatile(false);
	m_pseudostate_Attribute_kind->setChangeable(true);
	m_pseudostate_Attribute_kind->setUnsettable(false);
	m_pseudostate_Attribute_kind->setUnique(true);
	m_pseudostate_Attribute_kind->setDerived(false);
	m_pseudostate_Attribute_kind->setOrdered(false);
	m_pseudostate_Attribute_kind->setID(false);
	m_pseudostate_Attribute_kind->setDefaultValueLiteral("initial");
	
	m_pseudostate_Attribute_kind->_setID(PSEUDOSTATE_ATTRIBUTE_KIND);
	
	/*
	 * EReferences
	 */
	m_pseudostate_Attribute_state->setName("state");
	m_pseudostate_Attribute_state->setEType(getState_Class());
	m_pseudostate_Attribute_state->setLowerBound(0);
	m_pseudostate_Attribute_state->setUpperBound(1);
	m_pseudostate_Attribute_state->setTransient(false);
	m_pseudostate_Attribute_state->setVolatile(false);
	m_pseudostate_Attribute_state->setChangeable(true);
	m_pseudostate_Attribute_state->setUnsettable(false);
	m_pseudostate_Attribute_state->setUnique(true);
	m_pseudostate_Attribute_state->setDerived(false);
	m_pseudostate_Attribute_state->setOrdered(false);
	m_pseudostate_Attribute_state->setContainment(false);
	m_pseudostate_Attribute_state->setResolveProxies(true);
	m_pseudostate_Attribute_state->setDefaultValueLiteral("");	
	m_pseudostate_Attribute_state->setEOpposite(uml::umlPackage::eInstance()->getState_Attribute_connectionPoint());
	
	m_pseudostate_Attribute_state->_setID(PSEUDOSTATE_ATTRIBUTE_STATE);
	m_pseudostate_Attribute_stateMachine->setName("stateMachine");
	m_pseudostate_Attribute_stateMachine->setEType(getStateMachine_Class());
	m_pseudostate_Attribute_stateMachine->setLowerBound(0);
	m_pseudostate_Attribute_stateMachine->setUpperBound(1);
	m_pseudostate_Attribute_stateMachine->setTransient(false);
	m_pseudostate_Attribute_stateMachine->setVolatile(false);
	m_pseudostate_Attribute_stateMachine->setChangeable(true);
	m_pseudostate_Attribute_stateMachine->setUnsettable(false);
	m_pseudostate_Attribute_stateMachine->setUnique(true);
	m_pseudostate_Attribute_stateMachine->setDerived(false);
	m_pseudostate_Attribute_stateMachine->setOrdered(false);
	m_pseudostate_Attribute_stateMachine->setContainment(false);
	m_pseudostate_Attribute_stateMachine->setResolveProxies(true);
	m_pseudostate_Attribute_stateMachine->setDefaultValueLiteral("");	
	m_pseudostate_Attribute_stateMachine->setEOpposite(uml::umlPackage::eInstance()->getStateMachine_Attribute_connectionPoint());
	
	m_pseudostate_Attribute_stateMachine->_setID(PSEUDOSTATE_ATTRIBUTE_STATEMACHINE);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeQualifierValueContent()
{
	m_qualifierValue_Class->setName("QualifierValue");
	m_qualifierValue_Class->setAbstract(false);
	m_qualifierValue_Class->setInterface(false);
	
	m_qualifierValue_Class->_setID(QUALIFIERVALUE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_qualifierValue_Attribute_qualifier->setName("qualifier");
	m_qualifierValue_Attribute_qualifier->setEType(getProperty_Class());
	m_qualifierValue_Attribute_qualifier->setLowerBound(1);
	m_qualifierValue_Attribute_qualifier->setUpperBound(1);
	m_qualifierValue_Attribute_qualifier->setTransient(false);
	m_qualifierValue_Attribute_qualifier->setVolatile(false);
	m_qualifierValue_Attribute_qualifier->setChangeable(true);
	m_qualifierValue_Attribute_qualifier->setUnsettable(false);
	m_qualifierValue_Attribute_qualifier->setUnique(true);
	m_qualifierValue_Attribute_qualifier->setDerived(false);
	m_qualifierValue_Attribute_qualifier->setOrdered(false);
	m_qualifierValue_Attribute_qualifier->setContainment(false);
	m_qualifierValue_Attribute_qualifier->setResolveProxies(true);
	m_qualifierValue_Attribute_qualifier->setDefaultValueLiteral("");	
	
	m_qualifierValue_Attribute_qualifier->_setID(QUALIFIERVALUE_ATTRIBUTE_QUALIFIER);
	m_qualifierValue_Attribute_value->setName("value");
	m_qualifierValue_Attribute_value->setEType(getInputPin_Class());
	m_qualifierValue_Attribute_value->setLowerBound(1);
	m_qualifierValue_Attribute_value->setUpperBound(1);
	m_qualifierValue_Attribute_value->setTransient(false);
	m_qualifierValue_Attribute_value->setVolatile(false);
	m_qualifierValue_Attribute_value->setChangeable(true);
	m_qualifierValue_Attribute_value->setUnsettable(false);
	m_qualifierValue_Attribute_value->setUnique(true);
	m_qualifierValue_Attribute_value->setDerived(false);
	m_qualifierValue_Attribute_value->setOrdered(false);
	m_qualifierValue_Attribute_value->setContainment(false);
	m_qualifierValue_Attribute_value->setResolveProxies(true);
	m_qualifierValue_Attribute_value->setDefaultValueLiteral("");	
	
	m_qualifierValue_Attribute_value->_setID(QUALIFIERVALUE_ATTRIBUTE_VALUE);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeRaiseExceptionActionContent()
{
	m_raiseExceptionAction_Class->setName("RaiseExceptionAction");
	m_raiseExceptionAction_Class->setAbstract(false);
	m_raiseExceptionAction_Class->setInterface(false);
	
	m_raiseExceptionAction_Class->_setID(RAISEEXCEPTIONACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_raiseExceptionAction_Attribute_exception->setName("exception");
	m_raiseExceptionAction_Attribute_exception->setEType(getInputPin_Class());
	m_raiseExceptionAction_Attribute_exception->setLowerBound(1);
	m_raiseExceptionAction_Attribute_exception->setUpperBound(1);
	m_raiseExceptionAction_Attribute_exception->setTransient(false);
	m_raiseExceptionAction_Attribute_exception->setVolatile(false);
	m_raiseExceptionAction_Attribute_exception->setChangeable(true);
	m_raiseExceptionAction_Attribute_exception->setUnsettable(false);
	m_raiseExceptionAction_Attribute_exception->setUnique(true);
	m_raiseExceptionAction_Attribute_exception->setDerived(false);
	m_raiseExceptionAction_Attribute_exception->setOrdered(false);
	m_raiseExceptionAction_Attribute_exception->setContainment(true);
	m_raiseExceptionAction_Attribute_exception->setResolveProxies(true);
	m_raiseExceptionAction_Attribute_exception->setDefaultValueLiteral("");	
	
	m_raiseExceptionAction_Attribute_exception->_setID(RAISEEXCEPTIONACTION_ATTRIBUTE_EXCEPTION);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeReadExtentActionContent()
{
	m_readExtentAction_Class->setName("ReadExtentAction");
	m_readExtentAction_Class->setAbstract(false);
	m_readExtentAction_Class->setInterface(false);
	
	m_readExtentAction_Class->_setID(READEXTENTACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_readExtentAction_Attribute_classifier->setName("classifier");
	m_readExtentAction_Attribute_classifier->setEType(getClassifier_Class());
	m_readExtentAction_Attribute_classifier->setLowerBound(1);
	m_readExtentAction_Attribute_classifier->setUpperBound(1);
	m_readExtentAction_Attribute_classifier->setTransient(false);
	m_readExtentAction_Attribute_classifier->setVolatile(false);
	m_readExtentAction_Attribute_classifier->setChangeable(true);
	m_readExtentAction_Attribute_classifier->setUnsettable(false);
	m_readExtentAction_Attribute_classifier->setUnique(true);
	m_readExtentAction_Attribute_classifier->setDerived(false);
	m_readExtentAction_Attribute_classifier->setOrdered(false);
	m_readExtentAction_Attribute_classifier->setContainment(false);
	m_readExtentAction_Attribute_classifier->setResolveProxies(true);
	m_readExtentAction_Attribute_classifier->setDefaultValueLiteral("");	
	
	m_readExtentAction_Attribute_classifier->_setID(READEXTENTACTION_ATTRIBUTE_CLASSIFIER);
	m_readExtentAction_Attribute_result->setName("result");
	m_readExtentAction_Attribute_result->setEType(getOutputPin_Class());
	m_readExtentAction_Attribute_result->setLowerBound(1);
	m_readExtentAction_Attribute_result->setUpperBound(1);
	m_readExtentAction_Attribute_result->setTransient(false);
	m_readExtentAction_Attribute_result->setVolatile(false);
	m_readExtentAction_Attribute_result->setChangeable(true);
	m_readExtentAction_Attribute_result->setUnsettable(false);
	m_readExtentAction_Attribute_result->setUnique(true);
	m_readExtentAction_Attribute_result->setDerived(false);
	m_readExtentAction_Attribute_result->setOrdered(false);
	m_readExtentAction_Attribute_result->setContainment(true);
	m_readExtentAction_Attribute_result->setResolveProxies(true);
	m_readExtentAction_Attribute_result->setDefaultValueLiteral("");	
	
	m_readExtentAction_Attribute_result->_setID(READEXTENTACTION_ATTRIBUTE_RESULT);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeReadIsClassifiedObjectActionContent()
{
	m_readIsClassifiedObjectAction_Class->setName("ReadIsClassifiedObjectAction");
	m_readIsClassifiedObjectAction_Class->setAbstract(false);
	m_readIsClassifiedObjectAction_Class->setInterface(false);
	
	m_readIsClassifiedObjectAction_Class->_setID(READISCLASSIFIEDOBJECTACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	m_readIsClassifiedObjectAction_Attribute_isDirect = getReadIsClassifiedObjectAction_Attribute_isDirect();
	m_readIsClassifiedObjectAction_Attribute_isDirect->setName("isDirect");
	m_readIsClassifiedObjectAction_Attribute_isDirect->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_readIsClassifiedObjectAction_Attribute_isDirect->setLowerBound(1);
	m_readIsClassifiedObjectAction_Attribute_isDirect->setUpperBound(1);
	m_readIsClassifiedObjectAction_Attribute_isDirect->setTransient(false);
	m_readIsClassifiedObjectAction_Attribute_isDirect->setVolatile(false);
	m_readIsClassifiedObjectAction_Attribute_isDirect->setChangeable(true);
	m_readIsClassifiedObjectAction_Attribute_isDirect->setUnsettable(false);
	m_readIsClassifiedObjectAction_Attribute_isDirect->setUnique(true);
	m_readIsClassifiedObjectAction_Attribute_isDirect->setDerived(false);
	m_readIsClassifiedObjectAction_Attribute_isDirect->setOrdered(false);
	m_readIsClassifiedObjectAction_Attribute_isDirect->setID(false);
	m_readIsClassifiedObjectAction_Attribute_isDirect->setDefaultValueLiteral("false");
	
	m_readIsClassifiedObjectAction_Attribute_isDirect->_setID(READISCLASSIFIEDOBJECTACTION_ATTRIBUTE_ISDIRECT);
	
	/*
	 * EReferences
	 */
	m_readIsClassifiedObjectAction_Attribute_classifier->setName("classifier");
	m_readIsClassifiedObjectAction_Attribute_classifier->setEType(getClassifier_Class());
	m_readIsClassifiedObjectAction_Attribute_classifier->setLowerBound(1);
	m_readIsClassifiedObjectAction_Attribute_classifier->setUpperBound(1);
	m_readIsClassifiedObjectAction_Attribute_classifier->setTransient(false);
	m_readIsClassifiedObjectAction_Attribute_classifier->setVolatile(false);
	m_readIsClassifiedObjectAction_Attribute_classifier->setChangeable(true);
	m_readIsClassifiedObjectAction_Attribute_classifier->setUnsettable(false);
	m_readIsClassifiedObjectAction_Attribute_classifier->setUnique(true);
	m_readIsClassifiedObjectAction_Attribute_classifier->setDerived(false);
	m_readIsClassifiedObjectAction_Attribute_classifier->setOrdered(false);
	m_readIsClassifiedObjectAction_Attribute_classifier->setContainment(false);
	m_readIsClassifiedObjectAction_Attribute_classifier->setResolveProxies(true);
	m_readIsClassifiedObjectAction_Attribute_classifier->setDefaultValueLiteral("");	
	
	m_readIsClassifiedObjectAction_Attribute_classifier->_setID(READISCLASSIFIEDOBJECTACTION_ATTRIBUTE_CLASSIFIER);
	m_readIsClassifiedObjectAction_Attribute_object->setName("object");
	m_readIsClassifiedObjectAction_Attribute_object->setEType(getInputPin_Class());
	m_readIsClassifiedObjectAction_Attribute_object->setLowerBound(1);
	m_readIsClassifiedObjectAction_Attribute_object->setUpperBound(1);
	m_readIsClassifiedObjectAction_Attribute_object->setTransient(false);
	m_readIsClassifiedObjectAction_Attribute_object->setVolatile(false);
	m_readIsClassifiedObjectAction_Attribute_object->setChangeable(true);
	m_readIsClassifiedObjectAction_Attribute_object->setUnsettable(false);
	m_readIsClassifiedObjectAction_Attribute_object->setUnique(true);
	m_readIsClassifiedObjectAction_Attribute_object->setDerived(false);
	m_readIsClassifiedObjectAction_Attribute_object->setOrdered(false);
	m_readIsClassifiedObjectAction_Attribute_object->setContainment(true);
	m_readIsClassifiedObjectAction_Attribute_object->setResolveProxies(true);
	m_readIsClassifiedObjectAction_Attribute_object->setDefaultValueLiteral("");	
	
	m_readIsClassifiedObjectAction_Attribute_object->_setID(READISCLASSIFIEDOBJECTACTION_ATTRIBUTE_OBJECT);
	m_readIsClassifiedObjectAction_Attribute_result->setName("result");
	m_readIsClassifiedObjectAction_Attribute_result->setEType(getOutputPin_Class());
	m_readIsClassifiedObjectAction_Attribute_result->setLowerBound(1);
	m_readIsClassifiedObjectAction_Attribute_result->setUpperBound(1);
	m_readIsClassifiedObjectAction_Attribute_result->setTransient(false);
	m_readIsClassifiedObjectAction_Attribute_result->setVolatile(false);
	m_readIsClassifiedObjectAction_Attribute_result->setChangeable(true);
	m_readIsClassifiedObjectAction_Attribute_result->setUnsettable(false);
	m_readIsClassifiedObjectAction_Attribute_result->setUnique(true);
	m_readIsClassifiedObjectAction_Attribute_result->setDerived(false);
	m_readIsClassifiedObjectAction_Attribute_result->setOrdered(false);
	m_readIsClassifiedObjectAction_Attribute_result->setContainment(true);
	m_readIsClassifiedObjectAction_Attribute_result->setResolveProxies(true);
	m_readIsClassifiedObjectAction_Attribute_result->setDefaultValueLiteral("");	
	
	m_readIsClassifiedObjectAction_Attribute_result->_setID(READISCLASSIFIEDOBJECTACTION_ATTRIBUTE_RESULT);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeReadLinkActionContent()
{
	m_readLinkAction_Class->setName("ReadLinkAction");
	m_readLinkAction_Class->setAbstract(false);
	m_readLinkAction_Class->setInterface(false);
	
	m_readLinkAction_Class->_setID(READLINKACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_readLinkAction_Attribute_result->setName("result");
	m_readLinkAction_Attribute_result->setEType(getOutputPin_Class());
	m_readLinkAction_Attribute_result->setLowerBound(1);
	m_readLinkAction_Attribute_result->setUpperBound(1);
	m_readLinkAction_Attribute_result->setTransient(false);
	m_readLinkAction_Attribute_result->setVolatile(false);
	m_readLinkAction_Attribute_result->setChangeable(true);
	m_readLinkAction_Attribute_result->setUnsettable(false);
	m_readLinkAction_Attribute_result->setUnique(true);
	m_readLinkAction_Attribute_result->setDerived(false);
	m_readLinkAction_Attribute_result->setOrdered(false);
	m_readLinkAction_Attribute_result->setContainment(true);
	m_readLinkAction_Attribute_result->setResolveProxies(true);
	m_readLinkAction_Attribute_result->setDefaultValueLiteral("");	
	
	m_readLinkAction_Attribute_result->_setID(READLINKACTION_ATTRIBUTE_RESULT);
	
	/*
	 * EOperations
	 */
	m_readLinkAction_Operation_openEnd->setName("openEnd");
	m_readLinkAction_Operation_openEnd->setEType(getProperty_Class());
	m_readLinkAction_Operation_openEnd->setLowerBound(0);
	m_readLinkAction_Operation_openEnd->setUpperBound(-1);
	m_readLinkAction_Operation_openEnd->setUnique(true);
	m_readLinkAction_Operation_openEnd->setOrdered(true);
	
	m_readLinkAction_Operation_openEnd->_setID(READLINKACTION_OPERATION_OPENEND);
	
	
	
}

void umlPackageImpl::initializeReadLinkObjectEndActionContent()
{
	m_readLinkObjectEndAction_Class->setName("ReadLinkObjectEndAction");
	m_readLinkObjectEndAction_Class->setAbstract(false);
	m_readLinkObjectEndAction_Class->setInterface(false);
	
	m_readLinkObjectEndAction_Class->_setID(READLINKOBJECTENDACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_readLinkObjectEndAction_Attribute_end->setName("end");
	m_readLinkObjectEndAction_Attribute_end->setEType(getProperty_Class());
	m_readLinkObjectEndAction_Attribute_end->setLowerBound(1);
	m_readLinkObjectEndAction_Attribute_end->setUpperBound(1);
	m_readLinkObjectEndAction_Attribute_end->setTransient(false);
	m_readLinkObjectEndAction_Attribute_end->setVolatile(false);
	m_readLinkObjectEndAction_Attribute_end->setChangeable(true);
	m_readLinkObjectEndAction_Attribute_end->setUnsettable(false);
	m_readLinkObjectEndAction_Attribute_end->setUnique(true);
	m_readLinkObjectEndAction_Attribute_end->setDerived(false);
	m_readLinkObjectEndAction_Attribute_end->setOrdered(false);
	m_readLinkObjectEndAction_Attribute_end->setContainment(false);
	m_readLinkObjectEndAction_Attribute_end->setResolveProxies(true);
	m_readLinkObjectEndAction_Attribute_end->setDefaultValueLiteral("");	
	
	m_readLinkObjectEndAction_Attribute_end->_setID(READLINKOBJECTENDACTION_ATTRIBUTE_END);
	m_readLinkObjectEndAction_Attribute_object->setName("object");
	m_readLinkObjectEndAction_Attribute_object->setEType(getInputPin_Class());
	m_readLinkObjectEndAction_Attribute_object->setLowerBound(1);
	m_readLinkObjectEndAction_Attribute_object->setUpperBound(1);
	m_readLinkObjectEndAction_Attribute_object->setTransient(false);
	m_readLinkObjectEndAction_Attribute_object->setVolatile(false);
	m_readLinkObjectEndAction_Attribute_object->setChangeable(true);
	m_readLinkObjectEndAction_Attribute_object->setUnsettable(false);
	m_readLinkObjectEndAction_Attribute_object->setUnique(true);
	m_readLinkObjectEndAction_Attribute_object->setDerived(false);
	m_readLinkObjectEndAction_Attribute_object->setOrdered(false);
	m_readLinkObjectEndAction_Attribute_object->setContainment(true);
	m_readLinkObjectEndAction_Attribute_object->setResolveProxies(true);
	m_readLinkObjectEndAction_Attribute_object->setDefaultValueLiteral("");	
	
	m_readLinkObjectEndAction_Attribute_object->_setID(READLINKOBJECTENDACTION_ATTRIBUTE_OBJECT);
	m_readLinkObjectEndAction_Attribute_result->setName("result");
	m_readLinkObjectEndAction_Attribute_result->setEType(getOutputPin_Class());
	m_readLinkObjectEndAction_Attribute_result->setLowerBound(1);
	m_readLinkObjectEndAction_Attribute_result->setUpperBound(1);
	m_readLinkObjectEndAction_Attribute_result->setTransient(false);
	m_readLinkObjectEndAction_Attribute_result->setVolatile(false);
	m_readLinkObjectEndAction_Attribute_result->setChangeable(true);
	m_readLinkObjectEndAction_Attribute_result->setUnsettable(false);
	m_readLinkObjectEndAction_Attribute_result->setUnique(true);
	m_readLinkObjectEndAction_Attribute_result->setDerived(false);
	m_readLinkObjectEndAction_Attribute_result->setOrdered(false);
	m_readLinkObjectEndAction_Attribute_result->setContainment(true);
	m_readLinkObjectEndAction_Attribute_result->setResolveProxies(true);
	m_readLinkObjectEndAction_Attribute_result->setDefaultValueLiteral("");	
	
	m_readLinkObjectEndAction_Attribute_result->_setID(READLINKOBJECTENDACTION_ATTRIBUTE_RESULT);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeReadLinkObjectEndQualifierActionContent()
{
	m_readLinkObjectEndQualifierAction_Class->setName("ReadLinkObjectEndQualifierAction");
	m_readLinkObjectEndQualifierAction_Class->setAbstract(false);
	m_readLinkObjectEndQualifierAction_Class->setInterface(false);
	
	m_readLinkObjectEndQualifierAction_Class->_setID(READLINKOBJECTENDQUALIFIERACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_readLinkObjectEndQualifierAction_Attribute_object->setName("object");
	m_readLinkObjectEndQualifierAction_Attribute_object->setEType(getInputPin_Class());
	m_readLinkObjectEndQualifierAction_Attribute_object->setLowerBound(1);
	m_readLinkObjectEndQualifierAction_Attribute_object->setUpperBound(1);
	m_readLinkObjectEndQualifierAction_Attribute_object->setTransient(false);
	m_readLinkObjectEndQualifierAction_Attribute_object->setVolatile(false);
	m_readLinkObjectEndQualifierAction_Attribute_object->setChangeable(true);
	m_readLinkObjectEndQualifierAction_Attribute_object->setUnsettable(false);
	m_readLinkObjectEndQualifierAction_Attribute_object->setUnique(true);
	m_readLinkObjectEndQualifierAction_Attribute_object->setDerived(false);
	m_readLinkObjectEndQualifierAction_Attribute_object->setOrdered(false);
	m_readLinkObjectEndQualifierAction_Attribute_object->setContainment(true);
	m_readLinkObjectEndQualifierAction_Attribute_object->setResolveProxies(true);
	m_readLinkObjectEndQualifierAction_Attribute_object->setDefaultValueLiteral("");	
	
	m_readLinkObjectEndQualifierAction_Attribute_object->_setID(READLINKOBJECTENDQUALIFIERACTION_ATTRIBUTE_OBJECT);
	m_readLinkObjectEndQualifierAction_Attribute_qualifier->setName("qualifier");
	m_readLinkObjectEndQualifierAction_Attribute_qualifier->setEType(getProperty_Class());
	m_readLinkObjectEndQualifierAction_Attribute_qualifier->setLowerBound(1);
	m_readLinkObjectEndQualifierAction_Attribute_qualifier->setUpperBound(1);
	m_readLinkObjectEndQualifierAction_Attribute_qualifier->setTransient(false);
	m_readLinkObjectEndQualifierAction_Attribute_qualifier->setVolatile(false);
	m_readLinkObjectEndQualifierAction_Attribute_qualifier->setChangeable(true);
	m_readLinkObjectEndQualifierAction_Attribute_qualifier->setUnsettable(false);
	m_readLinkObjectEndQualifierAction_Attribute_qualifier->setUnique(true);
	m_readLinkObjectEndQualifierAction_Attribute_qualifier->setDerived(false);
	m_readLinkObjectEndQualifierAction_Attribute_qualifier->setOrdered(false);
	m_readLinkObjectEndQualifierAction_Attribute_qualifier->setContainment(false);
	m_readLinkObjectEndQualifierAction_Attribute_qualifier->setResolveProxies(true);
	m_readLinkObjectEndQualifierAction_Attribute_qualifier->setDefaultValueLiteral("");	
	
	m_readLinkObjectEndQualifierAction_Attribute_qualifier->_setID(READLINKOBJECTENDQUALIFIERACTION_ATTRIBUTE_QUALIFIER);
	m_readLinkObjectEndQualifierAction_Attribute_result->setName("result");
	m_readLinkObjectEndQualifierAction_Attribute_result->setEType(getOutputPin_Class());
	m_readLinkObjectEndQualifierAction_Attribute_result->setLowerBound(1);
	m_readLinkObjectEndQualifierAction_Attribute_result->setUpperBound(1);
	m_readLinkObjectEndQualifierAction_Attribute_result->setTransient(false);
	m_readLinkObjectEndQualifierAction_Attribute_result->setVolatile(false);
	m_readLinkObjectEndQualifierAction_Attribute_result->setChangeable(true);
	m_readLinkObjectEndQualifierAction_Attribute_result->setUnsettable(false);
	m_readLinkObjectEndQualifierAction_Attribute_result->setUnique(true);
	m_readLinkObjectEndQualifierAction_Attribute_result->setDerived(false);
	m_readLinkObjectEndQualifierAction_Attribute_result->setOrdered(false);
	m_readLinkObjectEndQualifierAction_Attribute_result->setContainment(true);
	m_readLinkObjectEndQualifierAction_Attribute_result->setResolveProxies(true);
	m_readLinkObjectEndQualifierAction_Attribute_result->setDefaultValueLiteral("");	
	
	m_readLinkObjectEndQualifierAction_Attribute_result->_setID(READLINKOBJECTENDQUALIFIERACTION_ATTRIBUTE_RESULT);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeReadSelfActionContent()
{
	m_readSelfAction_Class->setName("ReadSelfAction");
	m_readSelfAction_Class->setAbstract(false);
	m_readSelfAction_Class->setInterface(false);
	
	m_readSelfAction_Class->_setID(READSELFACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_readSelfAction_Attribute_result->setName("result");
	m_readSelfAction_Attribute_result->setEType(getOutputPin_Class());
	m_readSelfAction_Attribute_result->setLowerBound(1);
	m_readSelfAction_Attribute_result->setUpperBound(1);
	m_readSelfAction_Attribute_result->setTransient(false);
	m_readSelfAction_Attribute_result->setVolatile(false);
	m_readSelfAction_Attribute_result->setChangeable(true);
	m_readSelfAction_Attribute_result->setUnsettable(false);
	m_readSelfAction_Attribute_result->setUnique(true);
	m_readSelfAction_Attribute_result->setDerived(false);
	m_readSelfAction_Attribute_result->setOrdered(false);
	m_readSelfAction_Attribute_result->setContainment(true);
	m_readSelfAction_Attribute_result->setResolveProxies(true);
	m_readSelfAction_Attribute_result->setDefaultValueLiteral("");	
	m_readSelfAction_Attribute_result->setEOpposite(uml::umlPackage::eInstance()->getOutputPin_Attribute_readSelfAction());
	
	m_readSelfAction_Attribute_result->_setID(READSELFACTION_ATTRIBUTE_RESULT);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeReadStructuralFeatureActionContent()
{
	m_readStructuralFeatureAction_Class->setName("ReadStructuralFeatureAction");
	m_readStructuralFeatureAction_Class->setAbstract(false);
	m_readStructuralFeatureAction_Class->setInterface(false);
	
	m_readStructuralFeatureAction_Class->_setID(READSTRUCTURALFEATUREACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_readStructuralFeatureAction_Attribute_result->setName("result");
	m_readStructuralFeatureAction_Attribute_result->setEType(getOutputPin_Class());
	m_readStructuralFeatureAction_Attribute_result->setLowerBound(1);
	m_readStructuralFeatureAction_Attribute_result->setUpperBound(1);
	m_readStructuralFeatureAction_Attribute_result->setTransient(false);
	m_readStructuralFeatureAction_Attribute_result->setVolatile(false);
	m_readStructuralFeatureAction_Attribute_result->setChangeable(true);
	m_readStructuralFeatureAction_Attribute_result->setUnsettable(false);
	m_readStructuralFeatureAction_Attribute_result->setUnique(true);
	m_readStructuralFeatureAction_Attribute_result->setDerived(false);
	m_readStructuralFeatureAction_Attribute_result->setOrdered(false);
	m_readStructuralFeatureAction_Attribute_result->setContainment(true);
	m_readStructuralFeatureAction_Attribute_result->setResolveProxies(true);
	m_readStructuralFeatureAction_Attribute_result->setDefaultValueLiteral("");	
	m_readStructuralFeatureAction_Attribute_result->setEOpposite(uml::umlPackage::eInstance()->getOutputPin_Attribute_readStructuralFeatureAction());
	
	m_readStructuralFeatureAction_Attribute_result->_setID(READSTRUCTURALFEATUREACTION_ATTRIBUTE_RESULT);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeReadVariableActionContent()
{
	m_readVariableAction_Class->setName("ReadVariableAction");
	m_readVariableAction_Class->setAbstract(false);
	m_readVariableAction_Class->setInterface(false);
	
	m_readVariableAction_Class->_setID(READVARIABLEACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_readVariableAction_Attribute_result->setName("result");
	m_readVariableAction_Attribute_result->setEType(getOutputPin_Class());
	m_readVariableAction_Attribute_result->setLowerBound(1);
	m_readVariableAction_Attribute_result->setUpperBound(1);
	m_readVariableAction_Attribute_result->setTransient(false);
	m_readVariableAction_Attribute_result->setVolatile(false);
	m_readVariableAction_Attribute_result->setChangeable(true);
	m_readVariableAction_Attribute_result->setUnsettable(false);
	m_readVariableAction_Attribute_result->setUnique(true);
	m_readVariableAction_Attribute_result->setDerived(false);
	m_readVariableAction_Attribute_result->setOrdered(false);
	m_readVariableAction_Attribute_result->setContainment(true);
	m_readVariableAction_Attribute_result->setResolveProxies(true);
	m_readVariableAction_Attribute_result->setDefaultValueLiteral("");	
	
	m_readVariableAction_Attribute_result->_setID(READVARIABLEACTION_ATTRIBUTE_RESULT);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeRealizationContent()
{
	m_realization_Class->setName("Realization");
	m_realization_Class->setAbstract(false);
	m_realization_Class->setInterface(false);
	
	m_realization_Class->_setID(REALIZATION_CLASS);
	
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

void umlPackageImpl::initializeReceptionContent()
{
	m_reception_Class->setName("Reception");
	m_reception_Class->setAbstract(false);
	m_reception_Class->setInterface(false);
	
	m_reception_Class->_setID(RECEPTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_reception_Attribute_signal->setName("signal");
	m_reception_Attribute_signal->setEType(getSignal_Class());
	m_reception_Attribute_signal->setLowerBound(1);
	m_reception_Attribute_signal->setUpperBound(1);
	m_reception_Attribute_signal->setTransient(false);
	m_reception_Attribute_signal->setVolatile(false);
	m_reception_Attribute_signal->setChangeable(true);
	m_reception_Attribute_signal->setUnsettable(false);
	m_reception_Attribute_signal->setUnique(true);
	m_reception_Attribute_signal->setDerived(false);
	m_reception_Attribute_signal->setOrdered(false);
	m_reception_Attribute_signal->setContainment(false);
	m_reception_Attribute_signal->setResolveProxies(true);
	m_reception_Attribute_signal->setDefaultValueLiteral("");	
	
	m_reception_Attribute_signal->_setID(RECEPTION_ATTRIBUTE_SIGNAL);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeReclassifyObjectActionContent()
{
	m_reclassifyObjectAction_Class->setName("ReclassifyObjectAction");
	m_reclassifyObjectAction_Class->setAbstract(false);
	m_reclassifyObjectAction_Class->setInterface(false);
	
	m_reclassifyObjectAction_Class->_setID(RECLASSIFYOBJECTACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	m_reclassifyObjectAction_Attribute_isReplaceAll = getReclassifyObjectAction_Attribute_isReplaceAll();
	m_reclassifyObjectAction_Attribute_isReplaceAll->setName("isReplaceAll");
	m_reclassifyObjectAction_Attribute_isReplaceAll->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_reclassifyObjectAction_Attribute_isReplaceAll->setLowerBound(1);
	m_reclassifyObjectAction_Attribute_isReplaceAll->setUpperBound(1);
	m_reclassifyObjectAction_Attribute_isReplaceAll->setTransient(false);
	m_reclassifyObjectAction_Attribute_isReplaceAll->setVolatile(false);
	m_reclassifyObjectAction_Attribute_isReplaceAll->setChangeable(true);
	m_reclassifyObjectAction_Attribute_isReplaceAll->setUnsettable(false);
	m_reclassifyObjectAction_Attribute_isReplaceAll->setUnique(true);
	m_reclassifyObjectAction_Attribute_isReplaceAll->setDerived(false);
	m_reclassifyObjectAction_Attribute_isReplaceAll->setOrdered(false);
	m_reclassifyObjectAction_Attribute_isReplaceAll->setID(false);
	m_reclassifyObjectAction_Attribute_isReplaceAll->setDefaultValueLiteral("false");
	
	m_reclassifyObjectAction_Attribute_isReplaceAll->_setID(RECLASSIFYOBJECTACTION_ATTRIBUTE_ISREPLACEALL);
	
	/*
	 * EReferences
	 */
	m_reclassifyObjectAction_Attribute_newClassifier->setName("newClassifier");
	m_reclassifyObjectAction_Attribute_newClassifier->setEType(getClassifier_Class());
	m_reclassifyObjectAction_Attribute_newClassifier->setLowerBound(0);
	m_reclassifyObjectAction_Attribute_newClassifier->setUpperBound(-1);
	m_reclassifyObjectAction_Attribute_newClassifier->setTransient(false);
	m_reclassifyObjectAction_Attribute_newClassifier->setVolatile(false);
	m_reclassifyObjectAction_Attribute_newClassifier->setChangeable(true);
	m_reclassifyObjectAction_Attribute_newClassifier->setUnsettable(false);
	m_reclassifyObjectAction_Attribute_newClassifier->setUnique(true);
	m_reclassifyObjectAction_Attribute_newClassifier->setDerived(false);
	m_reclassifyObjectAction_Attribute_newClassifier->setOrdered(false);
	m_reclassifyObjectAction_Attribute_newClassifier->setContainment(false);
	m_reclassifyObjectAction_Attribute_newClassifier->setResolveProxies(true);
	m_reclassifyObjectAction_Attribute_newClassifier->setDefaultValueLiteral("");	
	
	m_reclassifyObjectAction_Attribute_newClassifier->_setID(RECLASSIFYOBJECTACTION_ATTRIBUTE_NEWCLASSIFIER);
	m_reclassifyObjectAction_Attribute_object->setName("object");
	m_reclassifyObjectAction_Attribute_object->setEType(getInputPin_Class());
	m_reclassifyObjectAction_Attribute_object->setLowerBound(1);
	m_reclassifyObjectAction_Attribute_object->setUpperBound(1);
	m_reclassifyObjectAction_Attribute_object->setTransient(false);
	m_reclassifyObjectAction_Attribute_object->setVolatile(false);
	m_reclassifyObjectAction_Attribute_object->setChangeable(true);
	m_reclassifyObjectAction_Attribute_object->setUnsettable(false);
	m_reclassifyObjectAction_Attribute_object->setUnique(true);
	m_reclassifyObjectAction_Attribute_object->setDerived(false);
	m_reclassifyObjectAction_Attribute_object->setOrdered(false);
	m_reclassifyObjectAction_Attribute_object->setContainment(true);
	m_reclassifyObjectAction_Attribute_object->setResolveProxies(true);
	m_reclassifyObjectAction_Attribute_object->setDefaultValueLiteral("");	
	
	m_reclassifyObjectAction_Attribute_object->_setID(RECLASSIFYOBJECTACTION_ATTRIBUTE_OBJECT);
	m_reclassifyObjectAction_Attribute_oldClassifier->setName("oldClassifier");
	m_reclassifyObjectAction_Attribute_oldClassifier->setEType(getClassifier_Class());
	m_reclassifyObjectAction_Attribute_oldClassifier->setLowerBound(0);
	m_reclassifyObjectAction_Attribute_oldClassifier->setUpperBound(-1);
	m_reclassifyObjectAction_Attribute_oldClassifier->setTransient(false);
	m_reclassifyObjectAction_Attribute_oldClassifier->setVolatile(false);
	m_reclassifyObjectAction_Attribute_oldClassifier->setChangeable(true);
	m_reclassifyObjectAction_Attribute_oldClassifier->setUnsettable(false);
	m_reclassifyObjectAction_Attribute_oldClassifier->setUnique(true);
	m_reclassifyObjectAction_Attribute_oldClassifier->setDerived(false);
	m_reclassifyObjectAction_Attribute_oldClassifier->setOrdered(false);
	m_reclassifyObjectAction_Attribute_oldClassifier->setContainment(false);
	m_reclassifyObjectAction_Attribute_oldClassifier->setResolveProxies(true);
	m_reclassifyObjectAction_Attribute_oldClassifier->setDefaultValueLiteral("");	
	
	m_reclassifyObjectAction_Attribute_oldClassifier->_setID(RECLASSIFYOBJECTACTION_ATTRIBUTE_OLDCLASSIFIER);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeRedefinableElementContent()
{
	m_redefinableElement_Class->setName("RedefinableElement");
	m_redefinableElement_Class->setAbstract(true);
	m_redefinableElement_Class->setInterface(false);
	
	m_redefinableElement_Class->_setID(REDEFINABLEELEMENT_CLASS);
	
	/*
	 * EAttributes
	 */
	m_redefinableElement_Attribute_isLeaf = getRedefinableElement_Attribute_isLeaf();
	m_redefinableElement_Attribute_isLeaf->setName("isLeaf");
	m_redefinableElement_Attribute_isLeaf->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_redefinableElement_Attribute_isLeaf->setLowerBound(1);
	m_redefinableElement_Attribute_isLeaf->setUpperBound(1);
	m_redefinableElement_Attribute_isLeaf->setTransient(false);
	m_redefinableElement_Attribute_isLeaf->setVolatile(false);
	m_redefinableElement_Attribute_isLeaf->setChangeable(true);
	m_redefinableElement_Attribute_isLeaf->setUnsettable(false);
	m_redefinableElement_Attribute_isLeaf->setUnique(true);
	m_redefinableElement_Attribute_isLeaf->setDerived(false);
	m_redefinableElement_Attribute_isLeaf->setOrdered(false);
	m_redefinableElement_Attribute_isLeaf->setID(false);
	m_redefinableElement_Attribute_isLeaf->setDefaultValueLiteral("false");
	
	m_redefinableElement_Attribute_isLeaf->_setID(REDEFINABLEELEMENT_ATTRIBUTE_ISLEAF);
	
	/*
	 * EReferences
	 */
	m_redefinableElement_Attribute_redefinedElement->setName("redefinedElement");
	m_redefinableElement_Attribute_redefinedElement->setEType(getRedefinableElement_Class());
	m_redefinableElement_Attribute_redefinedElement->setLowerBound(0);
	m_redefinableElement_Attribute_redefinedElement->setUpperBound(-1);
	m_redefinableElement_Attribute_redefinedElement->setTransient(true);
	m_redefinableElement_Attribute_redefinedElement->setVolatile(true);
	m_redefinableElement_Attribute_redefinedElement->setChangeable(false);
	m_redefinableElement_Attribute_redefinedElement->setUnsettable(false);
	m_redefinableElement_Attribute_redefinedElement->setUnique(true);
	m_redefinableElement_Attribute_redefinedElement->setDerived(true);
	m_redefinableElement_Attribute_redefinedElement->setOrdered(false);
	m_redefinableElement_Attribute_redefinedElement->setContainment(false);
	m_redefinableElement_Attribute_redefinedElement->setResolveProxies(true);
	m_redefinableElement_Attribute_redefinedElement->setDefaultValueLiteral("");	
	
	m_redefinableElement_Attribute_redefinedElement->_setID(REDEFINABLEELEMENT_ATTRIBUTE_REDEFINEDELEMENT);
	m_redefinableElement_Attribute_redefinitionContext->setName("redefinitionContext");
	m_redefinableElement_Attribute_redefinitionContext->setEType(getClassifier_Class());
	m_redefinableElement_Attribute_redefinitionContext->setLowerBound(0);
	m_redefinableElement_Attribute_redefinitionContext->setUpperBound(-1);
	m_redefinableElement_Attribute_redefinitionContext->setTransient(true);
	m_redefinableElement_Attribute_redefinitionContext->setVolatile(true);
	m_redefinableElement_Attribute_redefinitionContext->setChangeable(false);
	m_redefinableElement_Attribute_redefinitionContext->setUnsettable(false);
	m_redefinableElement_Attribute_redefinitionContext->setUnique(true);
	m_redefinableElement_Attribute_redefinitionContext->setDerived(true);
	m_redefinableElement_Attribute_redefinitionContext->setOrdered(false);
	m_redefinableElement_Attribute_redefinitionContext->setContainment(false);
	m_redefinableElement_Attribute_redefinitionContext->setResolveProxies(true);
	m_redefinableElement_Attribute_redefinitionContext->setDefaultValueLiteral("");	
	
	m_redefinableElement_Attribute_redefinitionContext->_setID(REDEFINABLEELEMENT_ATTRIBUTE_REDEFINITIONCONTEXT);
	
	/*
	 * EOperations
	 */
	m_redefinableElement_Operation_isConsistentWith_RedefinableElement->setName("isConsistentWith");
	m_redefinableElement_Operation_isConsistentWith_RedefinableElement->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_redefinableElement_Operation_isConsistentWith_RedefinableElement->setLowerBound(1);
	m_redefinableElement_Operation_isConsistentWith_RedefinableElement->setUpperBound(1);
	m_redefinableElement_Operation_isConsistentWith_RedefinableElement->setUnique(true);
	m_redefinableElement_Operation_isConsistentWith_RedefinableElement->setOrdered(false);
	
	m_redefinableElement_Operation_isConsistentWith_RedefinableElement->_setID(REDEFINABLEELEMENT_OPERATION_ISCONSISTENTWITH_REDEFINABLEELEMENT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_redefinableElement_Operation_isConsistentWith_RedefinableElement);
		parameter->setName("redefiningElement");
		parameter->setEType(getRedefinableElement_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_redefinableElement_Operation_isRedefinitionContextValid_RedefinableElement->setName("isRedefinitionContextValid");
	m_redefinableElement_Operation_isRedefinitionContextValid_RedefinableElement->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_redefinableElement_Operation_isRedefinitionContextValid_RedefinableElement->setLowerBound(1);
	m_redefinableElement_Operation_isRedefinitionContextValid_RedefinableElement->setUpperBound(1);
	m_redefinableElement_Operation_isRedefinitionContextValid_RedefinableElement->setUnique(true);
	m_redefinableElement_Operation_isRedefinitionContextValid_RedefinableElement->setOrdered(false);
	
	m_redefinableElement_Operation_isRedefinitionContextValid_RedefinableElement->_setID(REDEFINABLEELEMENT_OPERATION_ISREDEFINITIONCONTEXTVALID_REDEFINABLEELEMENT);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_redefinableElement_Operation_isRedefinitionContextValid_RedefinableElement);
		parameter->setName("redefinedElement");
		parameter->setEType(getRedefinableElement_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void umlPackageImpl::initializeRedefinableTemplateSignatureContent()
{
	m_redefinableTemplateSignature_Class->setName("RedefinableTemplateSignature");
	m_redefinableTemplateSignature_Class->setAbstract(false);
	m_redefinableTemplateSignature_Class->setInterface(false);
	
	m_redefinableTemplateSignature_Class->_setID(REDEFINABLETEMPLATESIGNATURE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_redefinableTemplateSignature_Attribute_classifier->setName("classifier");
	m_redefinableTemplateSignature_Attribute_classifier->setEType(getClassifier_Class());
	m_redefinableTemplateSignature_Attribute_classifier->setLowerBound(1);
	m_redefinableTemplateSignature_Attribute_classifier->setUpperBound(1);
	m_redefinableTemplateSignature_Attribute_classifier->setTransient(true);
	m_redefinableTemplateSignature_Attribute_classifier->setVolatile(true);
	m_redefinableTemplateSignature_Attribute_classifier->setChangeable(true);
	m_redefinableTemplateSignature_Attribute_classifier->setUnsettable(false);
	m_redefinableTemplateSignature_Attribute_classifier->setUnique(true);
	m_redefinableTemplateSignature_Attribute_classifier->setDerived(false);
	m_redefinableTemplateSignature_Attribute_classifier->setOrdered(false);
	m_redefinableTemplateSignature_Attribute_classifier->setContainment(false);
	m_redefinableTemplateSignature_Attribute_classifier->setResolveProxies(true);
	m_redefinableTemplateSignature_Attribute_classifier->setDefaultValueLiteral("");	
	
	m_redefinableTemplateSignature_Attribute_classifier->_setID(REDEFINABLETEMPLATESIGNATURE_ATTRIBUTE_CLASSIFIER);
	m_redefinableTemplateSignature_Attribute_extendedSignature->setName("extendedSignature");
	m_redefinableTemplateSignature_Attribute_extendedSignature->setEType(getRedefinableTemplateSignature_Class());
	m_redefinableTemplateSignature_Attribute_extendedSignature->setLowerBound(0);
	m_redefinableTemplateSignature_Attribute_extendedSignature->setUpperBound(-1);
	m_redefinableTemplateSignature_Attribute_extendedSignature->setTransient(false);
	m_redefinableTemplateSignature_Attribute_extendedSignature->setVolatile(false);
	m_redefinableTemplateSignature_Attribute_extendedSignature->setChangeable(true);
	m_redefinableTemplateSignature_Attribute_extendedSignature->setUnsettable(false);
	m_redefinableTemplateSignature_Attribute_extendedSignature->setUnique(true);
	m_redefinableTemplateSignature_Attribute_extendedSignature->setDerived(false);
	m_redefinableTemplateSignature_Attribute_extendedSignature->setOrdered(false);
	m_redefinableTemplateSignature_Attribute_extendedSignature->setContainment(false);
	m_redefinableTemplateSignature_Attribute_extendedSignature->setResolveProxies(true);
	m_redefinableTemplateSignature_Attribute_extendedSignature->setDefaultValueLiteral("");	
	
	m_redefinableTemplateSignature_Attribute_extendedSignature->_setID(REDEFINABLETEMPLATESIGNATURE_ATTRIBUTE_EXTENDEDSIGNATURE);
	m_redefinableTemplateSignature_Attribute_inheritedParameter->setName("inheritedParameter");
	m_redefinableTemplateSignature_Attribute_inheritedParameter->setEType(getTemplateParameter_Class());
	m_redefinableTemplateSignature_Attribute_inheritedParameter->setLowerBound(0);
	m_redefinableTemplateSignature_Attribute_inheritedParameter->setUpperBound(-1);
	m_redefinableTemplateSignature_Attribute_inheritedParameter->setTransient(true);
	m_redefinableTemplateSignature_Attribute_inheritedParameter->setVolatile(true);
	m_redefinableTemplateSignature_Attribute_inheritedParameter->setChangeable(false);
	m_redefinableTemplateSignature_Attribute_inheritedParameter->setUnsettable(false);
	m_redefinableTemplateSignature_Attribute_inheritedParameter->setUnique(true);
	m_redefinableTemplateSignature_Attribute_inheritedParameter->setDerived(true);
	m_redefinableTemplateSignature_Attribute_inheritedParameter->setOrdered(false);
	m_redefinableTemplateSignature_Attribute_inheritedParameter->setContainment(false);
	m_redefinableTemplateSignature_Attribute_inheritedParameter->setResolveProxies(true);
	m_redefinableTemplateSignature_Attribute_inheritedParameter->setDefaultValueLiteral("");	
	
	m_redefinableTemplateSignature_Attribute_inheritedParameter->_setID(REDEFINABLETEMPLATESIGNATURE_ATTRIBUTE_INHERITEDPARAMETER);
	
	/*
	 * EOperations
	 */
	m_redefinableTemplateSignature_Operation_getInheritedParameters->setName("getInheritedParameters");
	m_redefinableTemplateSignature_Operation_getInheritedParameters->setEType(getTemplateParameter_Class());
	m_redefinableTemplateSignature_Operation_getInheritedParameters->setLowerBound(0);
	m_redefinableTemplateSignature_Operation_getInheritedParameters->setUpperBound(-1);
	m_redefinableTemplateSignature_Operation_getInheritedParameters->setUnique(true);
	m_redefinableTemplateSignature_Operation_getInheritedParameters->setOrdered(false);
	
	m_redefinableTemplateSignature_Operation_getInheritedParameters->_setID(REDEFINABLETEMPLATESIGNATURE_OPERATION_GETINHERITEDPARAMETERS);
	
	
	
}

void umlPackageImpl::initializeReduceActionContent()
{
	m_reduceAction_Class->setName("ReduceAction");
	m_reduceAction_Class->setAbstract(false);
	m_reduceAction_Class->setInterface(false);
	
	m_reduceAction_Class->_setID(REDUCEACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	m_reduceAction_Attribute_isOrdered = getReduceAction_Attribute_isOrdered();
	m_reduceAction_Attribute_isOrdered->setName("isOrdered");
	m_reduceAction_Attribute_isOrdered->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_reduceAction_Attribute_isOrdered->setLowerBound(1);
	m_reduceAction_Attribute_isOrdered->setUpperBound(1);
	m_reduceAction_Attribute_isOrdered->setTransient(false);
	m_reduceAction_Attribute_isOrdered->setVolatile(false);
	m_reduceAction_Attribute_isOrdered->setChangeable(true);
	m_reduceAction_Attribute_isOrdered->setUnsettable(false);
	m_reduceAction_Attribute_isOrdered->setUnique(true);
	m_reduceAction_Attribute_isOrdered->setDerived(false);
	m_reduceAction_Attribute_isOrdered->setOrdered(false);
	m_reduceAction_Attribute_isOrdered->setID(false);
	m_reduceAction_Attribute_isOrdered->setDefaultValueLiteral("false");
	
	m_reduceAction_Attribute_isOrdered->_setID(REDUCEACTION_ATTRIBUTE_ISORDERED);
	
	/*
	 * EReferences
	 */
	m_reduceAction_Attribute_collection->setName("collection");
	m_reduceAction_Attribute_collection->setEType(getInputPin_Class());
	m_reduceAction_Attribute_collection->setLowerBound(1);
	m_reduceAction_Attribute_collection->setUpperBound(1);
	m_reduceAction_Attribute_collection->setTransient(false);
	m_reduceAction_Attribute_collection->setVolatile(false);
	m_reduceAction_Attribute_collection->setChangeable(true);
	m_reduceAction_Attribute_collection->setUnsettable(false);
	m_reduceAction_Attribute_collection->setUnique(true);
	m_reduceAction_Attribute_collection->setDerived(false);
	m_reduceAction_Attribute_collection->setOrdered(false);
	m_reduceAction_Attribute_collection->setContainment(true);
	m_reduceAction_Attribute_collection->setResolveProxies(true);
	m_reduceAction_Attribute_collection->setDefaultValueLiteral("");	
	
	m_reduceAction_Attribute_collection->_setID(REDUCEACTION_ATTRIBUTE_COLLECTION);
	m_reduceAction_Attribute_reducer->setName("reducer");
	m_reduceAction_Attribute_reducer->setEType(getBehavior_Class());
	m_reduceAction_Attribute_reducer->setLowerBound(1);
	m_reduceAction_Attribute_reducer->setUpperBound(1);
	m_reduceAction_Attribute_reducer->setTransient(false);
	m_reduceAction_Attribute_reducer->setVolatile(false);
	m_reduceAction_Attribute_reducer->setChangeable(true);
	m_reduceAction_Attribute_reducer->setUnsettable(false);
	m_reduceAction_Attribute_reducer->setUnique(true);
	m_reduceAction_Attribute_reducer->setDerived(false);
	m_reduceAction_Attribute_reducer->setOrdered(false);
	m_reduceAction_Attribute_reducer->setContainment(false);
	m_reduceAction_Attribute_reducer->setResolveProxies(true);
	m_reduceAction_Attribute_reducer->setDefaultValueLiteral("");	
	
	m_reduceAction_Attribute_reducer->_setID(REDUCEACTION_ATTRIBUTE_REDUCER);
	m_reduceAction_Attribute_result->setName("result");
	m_reduceAction_Attribute_result->setEType(getOutputPin_Class());
	m_reduceAction_Attribute_result->setLowerBound(1);
	m_reduceAction_Attribute_result->setUpperBound(1);
	m_reduceAction_Attribute_result->setTransient(false);
	m_reduceAction_Attribute_result->setVolatile(false);
	m_reduceAction_Attribute_result->setChangeable(true);
	m_reduceAction_Attribute_result->setUnsettable(false);
	m_reduceAction_Attribute_result->setUnique(true);
	m_reduceAction_Attribute_result->setDerived(false);
	m_reduceAction_Attribute_result->setOrdered(false);
	m_reduceAction_Attribute_result->setContainment(true);
	m_reduceAction_Attribute_result->setResolveProxies(true);
	m_reduceAction_Attribute_result->setDefaultValueLiteral("");	
	
	m_reduceAction_Attribute_result->_setID(REDUCEACTION_ATTRIBUTE_RESULT);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeRegionContent()
{
	m_region_Class->setName("Region");
	m_region_Class->setAbstract(false);
	m_region_Class->setInterface(false);
	
	m_region_Class->_setID(REGION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_region_Attribute_extendedRegion->setName("extendedRegion");
	m_region_Attribute_extendedRegion->setEType(getRegion_Class());
	m_region_Attribute_extendedRegion->setLowerBound(0);
	m_region_Attribute_extendedRegion->setUpperBound(1);
	m_region_Attribute_extendedRegion->setTransient(false);
	m_region_Attribute_extendedRegion->setVolatile(false);
	m_region_Attribute_extendedRegion->setChangeable(true);
	m_region_Attribute_extendedRegion->setUnsettable(false);
	m_region_Attribute_extendedRegion->setUnique(true);
	m_region_Attribute_extendedRegion->setDerived(false);
	m_region_Attribute_extendedRegion->setOrdered(false);
	m_region_Attribute_extendedRegion->setContainment(false);
	m_region_Attribute_extendedRegion->setResolveProxies(true);
	m_region_Attribute_extendedRegion->setDefaultValueLiteral("");	
	
	m_region_Attribute_extendedRegion->_setID(REGION_ATTRIBUTE_EXTENDEDREGION);
	m_region_Attribute_state->setName("state");
	m_region_Attribute_state->setEType(getState_Class());
	m_region_Attribute_state->setLowerBound(0);
	m_region_Attribute_state->setUpperBound(1);
	m_region_Attribute_state->setTransient(false);
	m_region_Attribute_state->setVolatile(false);
	m_region_Attribute_state->setChangeable(true);
	m_region_Attribute_state->setUnsettable(false);
	m_region_Attribute_state->setUnique(true);
	m_region_Attribute_state->setDerived(false);
	m_region_Attribute_state->setOrdered(false);
	m_region_Attribute_state->setContainment(false);
	m_region_Attribute_state->setResolveProxies(true);
	m_region_Attribute_state->setDefaultValueLiteral("");	
	m_region_Attribute_state->setEOpposite(uml::umlPackage::eInstance()->getState_Attribute_region());
	
	m_region_Attribute_state->_setID(REGION_ATTRIBUTE_STATE);
	m_region_Attribute_stateMachine->setName("stateMachine");
	m_region_Attribute_stateMachine->setEType(getStateMachine_Class());
	m_region_Attribute_stateMachine->setLowerBound(0);
	m_region_Attribute_stateMachine->setUpperBound(1);
	m_region_Attribute_stateMachine->setTransient(false);
	m_region_Attribute_stateMachine->setVolatile(false);
	m_region_Attribute_stateMachine->setChangeable(true);
	m_region_Attribute_stateMachine->setUnsettable(false);
	m_region_Attribute_stateMachine->setUnique(true);
	m_region_Attribute_stateMachine->setDerived(false);
	m_region_Attribute_stateMachine->setOrdered(false);
	m_region_Attribute_stateMachine->setContainment(false);
	m_region_Attribute_stateMachine->setResolveProxies(true);
	m_region_Attribute_stateMachine->setDefaultValueLiteral("");	
	m_region_Attribute_stateMachine->setEOpposite(uml::umlPackage::eInstance()->getStateMachine_Attribute_region());
	
	m_region_Attribute_stateMachine->_setID(REGION_ATTRIBUTE_STATEMACHINE);
	m_region_Attribute_subvertex->setName("subvertex");
	m_region_Attribute_subvertex->setEType(getVertex_Class());
	m_region_Attribute_subvertex->setLowerBound(0);
	m_region_Attribute_subvertex->setUpperBound(-1);
	m_region_Attribute_subvertex->setTransient(false);
	m_region_Attribute_subvertex->setVolatile(false);
	m_region_Attribute_subvertex->setChangeable(true);
	m_region_Attribute_subvertex->setUnsettable(false);
	m_region_Attribute_subvertex->setUnique(true);
	m_region_Attribute_subvertex->setDerived(false);
	m_region_Attribute_subvertex->setOrdered(false);
	m_region_Attribute_subvertex->setContainment(true);
	m_region_Attribute_subvertex->setResolveProxies(true);
	m_region_Attribute_subvertex->setDefaultValueLiteral("");	
	m_region_Attribute_subvertex->setEOpposite(uml::umlPackage::eInstance()->getVertex_Attribute_container());
	
	m_region_Attribute_subvertex->_setID(REGION_ATTRIBUTE_SUBVERTEX);
	m_region_Attribute_transition->setName("transition");
	m_region_Attribute_transition->setEType(getTransition_Class());
	m_region_Attribute_transition->setLowerBound(0);
	m_region_Attribute_transition->setUpperBound(-1);
	m_region_Attribute_transition->setTransient(false);
	m_region_Attribute_transition->setVolatile(false);
	m_region_Attribute_transition->setChangeable(true);
	m_region_Attribute_transition->setUnsettable(false);
	m_region_Attribute_transition->setUnique(true);
	m_region_Attribute_transition->setDerived(false);
	m_region_Attribute_transition->setOrdered(false);
	m_region_Attribute_transition->setContainment(true);
	m_region_Attribute_transition->setResolveProxies(true);
	m_region_Attribute_transition->setDefaultValueLiteral("");	
	m_region_Attribute_transition->setEOpposite(uml::umlPackage::eInstance()->getTransition_Attribute_container());
	
	m_region_Attribute_transition->_setID(REGION_ATTRIBUTE_TRANSITION);
	
	/*
	 * EOperations
	 */
	m_region_Operation_belongsToPSM->setName("belongsToPSM");
	m_region_Operation_belongsToPSM->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_region_Operation_belongsToPSM->setLowerBound(1);
	m_region_Operation_belongsToPSM->setUpperBound(1);
	m_region_Operation_belongsToPSM->setUnique(true);
	m_region_Operation_belongsToPSM->setOrdered(false);
	
	m_region_Operation_belongsToPSM->_setID(REGION_OPERATION_BELONGSTOPSM);
	
	
	m_region_Operation_containingStateMachine->setName("containingStateMachine");
	m_region_Operation_containingStateMachine->setEType(getStateMachine_Class());
	m_region_Operation_containingStateMachine->setLowerBound(1);
	m_region_Operation_containingStateMachine->setUpperBound(1);
	m_region_Operation_containingStateMachine->setUnique(true);
	m_region_Operation_containingStateMachine->setOrdered(false);
	
	m_region_Operation_containingStateMachine->_setID(REGION_OPERATION_CONTAININGSTATEMACHINE);
	
	
	m_region_Operation_redefinitionContext->setName("redefinitionContext");
	m_region_Operation_redefinitionContext->setEType(getClassifier_Class());
	m_region_Operation_redefinitionContext->setLowerBound(1);
	m_region_Operation_redefinitionContext->setUpperBound(1);
	m_region_Operation_redefinitionContext->setUnique(true);
	m_region_Operation_redefinitionContext->setOrdered(false);
	
	m_region_Operation_redefinitionContext->_setID(REGION_OPERATION_REDEFINITIONCONTEXT);
	
	
	
}

void umlPackageImpl::initializeRelationshipContent()
{
	m_relationship_Class->setName("Relationship");
	m_relationship_Class->setAbstract(true);
	m_relationship_Class->setInterface(false);
	
	m_relationship_Class->_setID(RELATIONSHIP_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_relationship_Attribute_relatedElement->setName("relatedElement");
	m_relationship_Attribute_relatedElement->setEType(getElement_Class());
	m_relationship_Attribute_relatedElement->setLowerBound(1);
	m_relationship_Attribute_relatedElement->setUpperBound(-1);
	m_relationship_Attribute_relatedElement->setTransient(true);
	m_relationship_Attribute_relatedElement->setVolatile(true);
	m_relationship_Attribute_relatedElement->setChangeable(false);
	m_relationship_Attribute_relatedElement->setUnsettable(false);
	m_relationship_Attribute_relatedElement->setUnique(true);
	m_relationship_Attribute_relatedElement->setDerived(true);
	m_relationship_Attribute_relatedElement->setOrdered(false);
	m_relationship_Attribute_relatedElement->setContainment(false);
	m_relationship_Attribute_relatedElement->setResolveProxies(true);
	m_relationship_Attribute_relatedElement->setDefaultValueLiteral("");	
	
	m_relationship_Attribute_relatedElement->_setID(RELATIONSHIP_ATTRIBUTE_RELATEDELEMENT);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeRemoveStructuralFeatureValueActionContent()
{
	m_removeStructuralFeatureValueAction_Class->setName("RemoveStructuralFeatureValueAction");
	m_removeStructuralFeatureValueAction_Class->setAbstract(false);
	m_removeStructuralFeatureValueAction_Class->setInterface(false);
	
	m_removeStructuralFeatureValueAction_Class->_setID(REMOVESTRUCTURALFEATUREVALUEACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	m_removeStructuralFeatureValueAction_Attribute_isRemoveDuplicates = getRemoveStructuralFeatureValueAction_Attribute_isRemoveDuplicates();
	m_removeStructuralFeatureValueAction_Attribute_isRemoveDuplicates->setName("isRemoveDuplicates");
	m_removeStructuralFeatureValueAction_Attribute_isRemoveDuplicates->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_removeStructuralFeatureValueAction_Attribute_isRemoveDuplicates->setLowerBound(1);
	m_removeStructuralFeatureValueAction_Attribute_isRemoveDuplicates->setUpperBound(1);
	m_removeStructuralFeatureValueAction_Attribute_isRemoveDuplicates->setTransient(false);
	m_removeStructuralFeatureValueAction_Attribute_isRemoveDuplicates->setVolatile(false);
	m_removeStructuralFeatureValueAction_Attribute_isRemoveDuplicates->setChangeable(true);
	m_removeStructuralFeatureValueAction_Attribute_isRemoveDuplicates->setUnsettable(false);
	m_removeStructuralFeatureValueAction_Attribute_isRemoveDuplicates->setUnique(true);
	m_removeStructuralFeatureValueAction_Attribute_isRemoveDuplicates->setDerived(false);
	m_removeStructuralFeatureValueAction_Attribute_isRemoveDuplicates->setOrdered(false);
	m_removeStructuralFeatureValueAction_Attribute_isRemoveDuplicates->setID(false);
	m_removeStructuralFeatureValueAction_Attribute_isRemoveDuplicates->setDefaultValueLiteral("false");
	
	m_removeStructuralFeatureValueAction_Attribute_isRemoveDuplicates->_setID(REMOVESTRUCTURALFEATUREVALUEACTION_ATTRIBUTE_ISREMOVEDUPLICATES);
	
	/*
	 * EReferences
	 */
	m_removeStructuralFeatureValueAction_Attribute_removeAt->setName("removeAt");
	m_removeStructuralFeatureValueAction_Attribute_removeAt->setEType(getInputPin_Class());
	m_removeStructuralFeatureValueAction_Attribute_removeAt->setLowerBound(0);
	m_removeStructuralFeatureValueAction_Attribute_removeAt->setUpperBound(1);
	m_removeStructuralFeatureValueAction_Attribute_removeAt->setTransient(false);
	m_removeStructuralFeatureValueAction_Attribute_removeAt->setVolatile(false);
	m_removeStructuralFeatureValueAction_Attribute_removeAt->setChangeable(true);
	m_removeStructuralFeatureValueAction_Attribute_removeAt->setUnsettable(false);
	m_removeStructuralFeatureValueAction_Attribute_removeAt->setUnique(true);
	m_removeStructuralFeatureValueAction_Attribute_removeAt->setDerived(false);
	m_removeStructuralFeatureValueAction_Attribute_removeAt->setOrdered(false);
	m_removeStructuralFeatureValueAction_Attribute_removeAt->setContainment(true);
	m_removeStructuralFeatureValueAction_Attribute_removeAt->setResolveProxies(true);
	m_removeStructuralFeatureValueAction_Attribute_removeAt->setDefaultValueLiteral("");	
	m_removeStructuralFeatureValueAction_Attribute_removeAt->setEOpposite(uml::umlPackage::eInstance()->getInputPin_Attribute_removeStructuralFeatureValueAction());
	
	m_removeStructuralFeatureValueAction_Attribute_removeAt->_setID(REMOVESTRUCTURALFEATUREVALUEACTION_ATTRIBUTE_REMOVEAT);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeRemoveVariableValueActionContent()
{
	m_removeVariableValueAction_Class->setName("RemoveVariableValueAction");
	m_removeVariableValueAction_Class->setAbstract(false);
	m_removeVariableValueAction_Class->setInterface(false);
	
	m_removeVariableValueAction_Class->_setID(REMOVEVARIABLEVALUEACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	m_removeVariableValueAction_Attribute_isRemoveDuplicates = getRemoveVariableValueAction_Attribute_isRemoveDuplicates();
	m_removeVariableValueAction_Attribute_isRemoveDuplicates->setName("isRemoveDuplicates");
	m_removeVariableValueAction_Attribute_isRemoveDuplicates->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_removeVariableValueAction_Attribute_isRemoveDuplicates->setLowerBound(1);
	m_removeVariableValueAction_Attribute_isRemoveDuplicates->setUpperBound(1);
	m_removeVariableValueAction_Attribute_isRemoveDuplicates->setTransient(false);
	m_removeVariableValueAction_Attribute_isRemoveDuplicates->setVolatile(false);
	m_removeVariableValueAction_Attribute_isRemoveDuplicates->setChangeable(true);
	m_removeVariableValueAction_Attribute_isRemoveDuplicates->setUnsettable(false);
	m_removeVariableValueAction_Attribute_isRemoveDuplicates->setUnique(true);
	m_removeVariableValueAction_Attribute_isRemoveDuplicates->setDerived(false);
	m_removeVariableValueAction_Attribute_isRemoveDuplicates->setOrdered(false);
	m_removeVariableValueAction_Attribute_isRemoveDuplicates->setID(false);
	m_removeVariableValueAction_Attribute_isRemoveDuplicates->setDefaultValueLiteral("false");
	
	m_removeVariableValueAction_Attribute_isRemoveDuplicates->_setID(REMOVEVARIABLEVALUEACTION_ATTRIBUTE_ISREMOVEDUPLICATES);
	
	/*
	 * EReferences
	 */
	m_removeVariableValueAction_Attribute_removeAt->setName("removeAt");
	m_removeVariableValueAction_Attribute_removeAt->setEType(getInputPin_Class());
	m_removeVariableValueAction_Attribute_removeAt->setLowerBound(0);
	m_removeVariableValueAction_Attribute_removeAt->setUpperBound(1);
	m_removeVariableValueAction_Attribute_removeAt->setTransient(false);
	m_removeVariableValueAction_Attribute_removeAt->setVolatile(false);
	m_removeVariableValueAction_Attribute_removeAt->setChangeable(true);
	m_removeVariableValueAction_Attribute_removeAt->setUnsettable(false);
	m_removeVariableValueAction_Attribute_removeAt->setUnique(true);
	m_removeVariableValueAction_Attribute_removeAt->setDerived(false);
	m_removeVariableValueAction_Attribute_removeAt->setOrdered(false);
	m_removeVariableValueAction_Attribute_removeAt->setContainment(true);
	m_removeVariableValueAction_Attribute_removeAt->setResolveProxies(true);
	m_removeVariableValueAction_Attribute_removeAt->setDefaultValueLiteral("");	
	
	m_removeVariableValueAction_Attribute_removeAt->_setID(REMOVEVARIABLEVALUEACTION_ATTRIBUTE_REMOVEAT);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeReplyActionContent()
{
	m_replyAction_Class->setName("ReplyAction");
	m_replyAction_Class->setAbstract(false);
	m_replyAction_Class->setInterface(false);
	
	m_replyAction_Class->_setID(REPLYACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_replyAction_Attribute_replyToCall->setName("replyToCall");
	m_replyAction_Attribute_replyToCall->setEType(getTrigger_Class());
	m_replyAction_Attribute_replyToCall->setLowerBound(1);
	m_replyAction_Attribute_replyToCall->setUpperBound(1);
	m_replyAction_Attribute_replyToCall->setTransient(false);
	m_replyAction_Attribute_replyToCall->setVolatile(false);
	m_replyAction_Attribute_replyToCall->setChangeable(true);
	m_replyAction_Attribute_replyToCall->setUnsettable(false);
	m_replyAction_Attribute_replyToCall->setUnique(true);
	m_replyAction_Attribute_replyToCall->setDerived(false);
	m_replyAction_Attribute_replyToCall->setOrdered(false);
	m_replyAction_Attribute_replyToCall->setContainment(false);
	m_replyAction_Attribute_replyToCall->setResolveProxies(true);
	m_replyAction_Attribute_replyToCall->setDefaultValueLiteral("");	
	
	m_replyAction_Attribute_replyToCall->_setID(REPLYACTION_ATTRIBUTE_REPLYTOCALL);
	m_replyAction_Attribute_replyValue->setName("replyValue");
	m_replyAction_Attribute_replyValue->setEType(getInputPin_Class());
	m_replyAction_Attribute_replyValue->setLowerBound(0);
	m_replyAction_Attribute_replyValue->setUpperBound(-1);
	m_replyAction_Attribute_replyValue->setTransient(false);
	m_replyAction_Attribute_replyValue->setVolatile(false);
	m_replyAction_Attribute_replyValue->setChangeable(true);
	m_replyAction_Attribute_replyValue->setUnsettable(false);
	m_replyAction_Attribute_replyValue->setUnique(true);
	m_replyAction_Attribute_replyValue->setDerived(false);
	m_replyAction_Attribute_replyValue->setOrdered(true);
	m_replyAction_Attribute_replyValue->setContainment(true);
	m_replyAction_Attribute_replyValue->setResolveProxies(true);
	m_replyAction_Attribute_replyValue->setDefaultValueLiteral("");	
	
	m_replyAction_Attribute_replyValue->_setID(REPLYACTION_ATTRIBUTE_REPLYVALUE);
	m_replyAction_Attribute_returnInformation->setName("returnInformation");
	m_replyAction_Attribute_returnInformation->setEType(getInputPin_Class());
	m_replyAction_Attribute_returnInformation->setLowerBound(1);
	m_replyAction_Attribute_returnInformation->setUpperBound(1);
	m_replyAction_Attribute_returnInformation->setTransient(false);
	m_replyAction_Attribute_returnInformation->setVolatile(false);
	m_replyAction_Attribute_returnInformation->setChangeable(true);
	m_replyAction_Attribute_returnInformation->setUnsettable(false);
	m_replyAction_Attribute_returnInformation->setUnique(true);
	m_replyAction_Attribute_returnInformation->setDerived(false);
	m_replyAction_Attribute_returnInformation->setOrdered(false);
	m_replyAction_Attribute_returnInformation->setContainment(true);
	m_replyAction_Attribute_returnInformation->setResolveProxies(true);
	m_replyAction_Attribute_returnInformation->setDefaultValueLiteral("");	
	
	m_replyAction_Attribute_returnInformation->_setID(REPLYACTION_ATTRIBUTE_RETURNINFORMATION);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeSendObjectActionContent()
{
	m_sendObjectAction_Class->setName("SendObjectAction");
	m_sendObjectAction_Class->setAbstract(false);
	m_sendObjectAction_Class->setInterface(false);
	
	m_sendObjectAction_Class->_setID(SENDOBJECTACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_sendObjectAction_Attribute_request->setName("request");
	m_sendObjectAction_Attribute_request->setEType(getInputPin_Class());
	m_sendObjectAction_Attribute_request->setLowerBound(1);
	m_sendObjectAction_Attribute_request->setUpperBound(1);
	m_sendObjectAction_Attribute_request->setTransient(false);
	m_sendObjectAction_Attribute_request->setVolatile(false);
	m_sendObjectAction_Attribute_request->setChangeable(true);
	m_sendObjectAction_Attribute_request->setUnsettable(false);
	m_sendObjectAction_Attribute_request->setUnique(true);
	m_sendObjectAction_Attribute_request->setDerived(false);
	m_sendObjectAction_Attribute_request->setOrdered(false);
	m_sendObjectAction_Attribute_request->setContainment(true);
	m_sendObjectAction_Attribute_request->setResolveProxies(true);
	m_sendObjectAction_Attribute_request->setDefaultValueLiteral("");	
	
	m_sendObjectAction_Attribute_request->_setID(SENDOBJECTACTION_ATTRIBUTE_REQUEST);
	m_sendObjectAction_Attribute_target->setName("target");
	m_sendObjectAction_Attribute_target->setEType(getInputPin_Class());
	m_sendObjectAction_Attribute_target->setLowerBound(1);
	m_sendObjectAction_Attribute_target->setUpperBound(1);
	m_sendObjectAction_Attribute_target->setTransient(false);
	m_sendObjectAction_Attribute_target->setVolatile(false);
	m_sendObjectAction_Attribute_target->setChangeable(true);
	m_sendObjectAction_Attribute_target->setUnsettable(false);
	m_sendObjectAction_Attribute_target->setUnique(true);
	m_sendObjectAction_Attribute_target->setDerived(false);
	m_sendObjectAction_Attribute_target->setOrdered(false);
	m_sendObjectAction_Attribute_target->setContainment(true);
	m_sendObjectAction_Attribute_target->setResolveProxies(true);
	m_sendObjectAction_Attribute_target->setDefaultValueLiteral("");	
	
	m_sendObjectAction_Attribute_target->_setID(SENDOBJECTACTION_ATTRIBUTE_TARGET);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeSendSignalActionContent()
{
	m_sendSignalAction_Class->setName("SendSignalAction");
	m_sendSignalAction_Class->setAbstract(false);
	m_sendSignalAction_Class->setInterface(false);
	
	m_sendSignalAction_Class->_setID(SENDSIGNALACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_sendSignalAction_Attribute_signal->setName("signal");
	m_sendSignalAction_Attribute_signal->setEType(getSignal_Class());
	m_sendSignalAction_Attribute_signal->setLowerBound(1);
	m_sendSignalAction_Attribute_signal->setUpperBound(1);
	m_sendSignalAction_Attribute_signal->setTransient(false);
	m_sendSignalAction_Attribute_signal->setVolatile(false);
	m_sendSignalAction_Attribute_signal->setChangeable(true);
	m_sendSignalAction_Attribute_signal->setUnsettable(false);
	m_sendSignalAction_Attribute_signal->setUnique(true);
	m_sendSignalAction_Attribute_signal->setDerived(false);
	m_sendSignalAction_Attribute_signal->setOrdered(false);
	m_sendSignalAction_Attribute_signal->setContainment(false);
	m_sendSignalAction_Attribute_signal->setResolveProxies(true);
	m_sendSignalAction_Attribute_signal->setDefaultValueLiteral("");	
	
	m_sendSignalAction_Attribute_signal->_setID(SENDSIGNALACTION_ATTRIBUTE_SIGNAL);
	m_sendSignalAction_Attribute_target->setName("target");
	m_sendSignalAction_Attribute_target->setEType(getInputPin_Class());
	m_sendSignalAction_Attribute_target->setLowerBound(1);
	m_sendSignalAction_Attribute_target->setUpperBound(1);
	m_sendSignalAction_Attribute_target->setTransient(false);
	m_sendSignalAction_Attribute_target->setVolatile(false);
	m_sendSignalAction_Attribute_target->setChangeable(true);
	m_sendSignalAction_Attribute_target->setUnsettable(false);
	m_sendSignalAction_Attribute_target->setUnique(true);
	m_sendSignalAction_Attribute_target->setDerived(false);
	m_sendSignalAction_Attribute_target->setOrdered(false);
	m_sendSignalAction_Attribute_target->setContainment(true);
	m_sendSignalAction_Attribute_target->setResolveProxies(true);
	m_sendSignalAction_Attribute_target->setDefaultValueLiteral("");	
	
	m_sendSignalAction_Attribute_target->_setID(SENDSIGNALACTION_ATTRIBUTE_TARGET);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeSequenceNodeContent()
{
	m_sequenceNode_Class->setName("SequenceNode");
	m_sequenceNode_Class->setAbstract(false);
	m_sequenceNode_Class->setInterface(false);
	
	m_sequenceNode_Class->_setID(SEQUENCENODE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_sequenceNode_Attribute_executableNode->setName("executableNode");
	m_sequenceNode_Attribute_executableNode->setEType(getExecutableNode_Class());
	m_sequenceNode_Attribute_executableNode->setLowerBound(0);
	m_sequenceNode_Attribute_executableNode->setUpperBound(-1);
	m_sequenceNode_Attribute_executableNode->setTransient(false);
	m_sequenceNode_Attribute_executableNode->setVolatile(false);
	m_sequenceNode_Attribute_executableNode->setChangeable(true);
	m_sequenceNode_Attribute_executableNode->setUnsettable(false);
	m_sequenceNode_Attribute_executableNode->setUnique(true);
	m_sequenceNode_Attribute_executableNode->setDerived(false);
	m_sequenceNode_Attribute_executableNode->setOrdered(true);
	m_sequenceNode_Attribute_executableNode->setContainment(true);
	m_sequenceNode_Attribute_executableNode->setResolveProxies(true);
	m_sequenceNode_Attribute_executableNode->setDefaultValueLiteral("");	
	
	m_sequenceNode_Attribute_executableNode->_setID(SEQUENCENODE_ATTRIBUTE_EXECUTABLENODE);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeSignalContent()
{
	m_signal_Class->setName("Signal");
	m_signal_Class->setAbstract(false);
	m_signal_Class->setInterface(false);
	
	m_signal_Class->_setID(SIGNAL_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_signal_Attribute_ownedAttribute->setName("ownedAttribute");
	m_signal_Attribute_ownedAttribute->setEType(getProperty_Class());
	m_signal_Attribute_ownedAttribute->setLowerBound(0);
	m_signal_Attribute_ownedAttribute->setUpperBound(-1);
	m_signal_Attribute_ownedAttribute->setTransient(false);
	m_signal_Attribute_ownedAttribute->setVolatile(false);
	m_signal_Attribute_ownedAttribute->setChangeable(true);
	m_signal_Attribute_ownedAttribute->setUnsettable(false);
	m_signal_Attribute_ownedAttribute->setUnique(true);
	m_signal_Attribute_ownedAttribute->setDerived(false);
	m_signal_Attribute_ownedAttribute->setOrdered(true);
	m_signal_Attribute_ownedAttribute->setContainment(true);
	m_signal_Attribute_ownedAttribute->setResolveProxies(true);
	m_signal_Attribute_ownedAttribute->setDefaultValueLiteral("");	
	
	m_signal_Attribute_ownedAttribute->_setID(SIGNAL_ATTRIBUTE_OWNEDATTRIBUTE);
	
	/*
	 * EOperations
	 */
	m_signal_Operation_createOwnedAttribute_String_UnlimitedNatural->setName("createOwnedAttribute");
	m_signal_Operation_createOwnedAttribute_String_UnlimitedNatural->setEType(getProperty_Class());
	m_signal_Operation_createOwnedAttribute_String_UnlimitedNatural->setLowerBound(1);
	m_signal_Operation_createOwnedAttribute_String_UnlimitedNatural->setUpperBound(1);
	m_signal_Operation_createOwnedAttribute_String_UnlimitedNatural->setUnique(true);
	m_signal_Operation_createOwnedAttribute_String_UnlimitedNatural->setOrdered(false);
	
	m_signal_Operation_createOwnedAttribute_String_UnlimitedNatural->_setID(SIGNAL_OPERATION_CREATEOWNEDATTRIBUTE_STRING_UNLIMITEDNATURAL);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_signal_Operation_createOwnedAttribute_String_UnlimitedNatural);
		parameter->setName("name");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_signal_Operation_createOwnedAttribute_String_UnlimitedNatural);
		parameter->setName("type");
		parameter->setEType(getType_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_signal_Operation_createOwnedAttribute_String_UnlimitedNatural);
		parameter->setName("lower");
		parameter->setEType(types::typesPackage::eInstance()->getInteger_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_signal_Operation_createOwnedAttribute_String_UnlimitedNatural);
		parameter->setName("upper");
		parameter->setEType(types::typesPackage::eInstance()->getUnlimitedNatural_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void umlPackageImpl::initializeSignalEventContent()
{
	m_signalEvent_Class->setName("SignalEvent");
	m_signalEvent_Class->setAbstract(false);
	m_signalEvent_Class->setInterface(false);
	
	m_signalEvent_Class->_setID(SIGNALEVENT_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_signalEvent_Attribute_signal->setName("signal");
	m_signalEvent_Attribute_signal->setEType(getSignal_Class());
	m_signalEvent_Attribute_signal->setLowerBound(1);
	m_signalEvent_Attribute_signal->setUpperBound(1);
	m_signalEvent_Attribute_signal->setTransient(false);
	m_signalEvent_Attribute_signal->setVolatile(false);
	m_signalEvent_Attribute_signal->setChangeable(true);
	m_signalEvent_Attribute_signal->setUnsettable(false);
	m_signalEvent_Attribute_signal->setUnique(true);
	m_signalEvent_Attribute_signal->setDerived(false);
	m_signalEvent_Attribute_signal->setOrdered(false);
	m_signalEvent_Attribute_signal->setContainment(false);
	m_signalEvent_Attribute_signal->setResolveProxies(true);
	m_signalEvent_Attribute_signal->setDefaultValueLiteral("");	
	
	m_signalEvent_Attribute_signal->_setID(SIGNALEVENT_ATTRIBUTE_SIGNAL);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeSlotContent()
{
	m_slot_Class->setName("Slot");
	m_slot_Class->setAbstract(false);
	m_slot_Class->setInterface(false);
	
	m_slot_Class->_setID(SLOT_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_slot_Attribute_definingFeature->setName("definingFeature");
	m_slot_Attribute_definingFeature->setEType(getStructuralFeature_Class());
	m_slot_Attribute_definingFeature->setLowerBound(1);
	m_slot_Attribute_definingFeature->setUpperBound(1);
	m_slot_Attribute_definingFeature->setTransient(false);
	m_slot_Attribute_definingFeature->setVolatile(false);
	m_slot_Attribute_definingFeature->setChangeable(true);
	m_slot_Attribute_definingFeature->setUnsettable(false);
	m_slot_Attribute_definingFeature->setUnique(true);
	m_slot_Attribute_definingFeature->setDerived(false);
	m_slot_Attribute_definingFeature->setOrdered(false);
	m_slot_Attribute_definingFeature->setContainment(false);
	m_slot_Attribute_definingFeature->setResolveProxies(true);
	m_slot_Attribute_definingFeature->setDefaultValueLiteral("");	
	
	m_slot_Attribute_definingFeature->_setID(SLOT_ATTRIBUTE_DEFININGFEATURE);
	m_slot_Attribute_owningInstance->setName("owningInstance");
	m_slot_Attribute_owningInstance->setEType(getInstanceSpecification_Class());
	m_slot_Attribute_owningInstance->setLowerBound(1);
	m_slot_Attribute_owningInstance->setUpperBound(1);
	m_slot_Attribute_owningInstance->setTransient(false);
	m_slot_Attribute_owningInstance->setVolatile(false);
	m_slot_Attribute_owningInstance->setChangeable(true);
	m_slot_Attribute_owningInstance->setUnsettable(false);
	m_slot_Attribute_owningInstance->setUnique(true);
	m_slot_Attribute_owningInstance->setDerived(false);
	m_slot_Attribute_owningInstance->setOrdered(false);
	m_slot_Attribute_owningInstance->setContainment(false);
	m_slot_Attribute_owningInstance->setResolveProxies(true);
	m_slot_Attribute_owningInstance->setDefaultValueLiteral("");	
	m_slot_Attribute_owningInstance->setEOpposite(uml::umlPackage::eInstance()->getInstanceSpecification_Attribute_slot());
	
	m_slot_Attribute_owningInstance->_setID(SLOT_ATTRIBUTE_OWNINGINSTANCE);
	m_slot_Attribute_value->setName("value");
	m_slot_Attribute_value->setEType(getValueSpecification_Class());
	m_slot_Attribute_value->setLowerBound(0);
	m_slot_Attribute_value->setUpperBound(-1);
	m_slot_Attribute_value->setTransient(false);
	m_slot_Attribute_value->setVolatile(false);
	m_slot_Attribute_value->setChangeable(true);
	m_slot_Attribute_value->setUnsettable(false);
	m_slot_Attribute_value->setUnique(true);
	m_slot_Attribute_value->setDerived(false);
	m_slot_Attribute_value->setOrdered(true);
	m_slot_Attribute_value->setContainment(true);
	m_slot_Attribute_value->setResolveProxies(true);
	m_slot_Attribute_value->setDefaultValueLiteral("");	
	m_slot_Attribute_value->setEOpposite(uml::umlPackage::eInstance()->getValueSpecification_Attribute_owningSlot());
	
	m_slot_Attribute_value->_setID(SLOT_ATTRIBUTE_VALUE);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeStartClassifierBehaviorActionContent()
{
	m_startClassifierBehaviorAction_Class->setName("StartClassifierBehaviorAction");
	m_startClassifierBehaviorAction_Class->setAbstract(false);
	m_startClassifierBehaviorAction_Class->setInterface(false);
	
	m_startClassifierBehaviorAction_Class->_setID(STARTCLASSIFIERBEHAVIORACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_startClassifierBehaviorAction_Attribute_object->setName("object");
	m_startClassifierBehaviorAction_Attribute_object->setEType(getInputPin_Class());
	m_startClassifierBehaviorAction_Attribute_object->setLowerBound(1);
	m_startClassifierBehaviorAction_Attribute_object->setUpperBound(1);
	m_startClassifierBehaviorAction_Attribute_object->setTransient(false);
	m_startClassifierBehaviorAction_Attribute_object->setVolatile(false);
	m_startClassifierBehaviorAction_Attribute_object->setChangeable(true);
	m_startClassifierBehaviorAction_Attribute_object->setUnsettable(false);
	m_startClassifierBehaviorAction_Attribute_object->setUnique(true);
	m_startClassifierBehaviorAction_Attribute_object->setDerived(false);
	m_startClassifierBehaviorAction_Attribute_object->setOrdered(false);
	m_startClassifierBehaviorAction_Attribute_object->setContainment(true);
	m_startClassifierBehaviorAction_Attribute_object->setResolveProxies(true);
	m_startClassifierBehaviorAction_Attribute_object->setDefaultValueLiteral("");	
	
	m_startClassifierBehaviorAction_Attribute_object->_setID(STARTCLASSIFIERBEHAVIORACTION_ATTRIBUTE_OBJECT);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeStartObjectBehaviorActionContent()
{
	m_startObjectBehaviorAction_Class->setName("StartObjectBehaviorAction");
	m_startObjectBehaviorAction_Class->setAbstract(false);
	m_startObjectBehaviorAction_Class->setInterface(false);
	
	m_startObjectBehaviorAction_Class->_setID(STARTOBJECTBEHAVIORACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_startObjectBehaviorAction_Attribute_object->setName("object");
	m_startObjectBehaviorAction_Attribute_object->setEType(getInputPin_Class());
	m_startObjectBehaviorAction_Attribute_object->setLowerBound(1);
	m_startObjectBehaviorAction_Attribute_object->setUpperBound(1);
	m_startObjectBehaviorAction_Attribute_object->setTransient(false);
	m_startObjectBehaviorAction_Attribute_object->setVolatile(false);
	m_startObjectBehaviorAction_Attribute_object->setChangeable(true);
	m_startObjectBehaviorAction_Attribute_object->setUnsettable(false);
	m_startObjectBehaviorAction_Attribute_object->setUnique(true);
	m_startObjectBehaviorAction_Attribute_object->setDerived(false);
	m_startObjectBehaviorAction_Attribute_object->setOrdered(false);
	m_startObjectBehaviorAction_Attribute_object->setContainment(true);
	m_startObjectBehaviorAction_Attribute_object->setResolveProxies(true);
	m_startObjectBehaviorAction_Attribute_object->setDefaultValueLiteral("");	
	
	m_startObjectBehaviorAction_Attribute_object->_setID(STARTOBJECTBEHAVIORACTION_ATTRIBUTE_OBJECT);
	
	/*
	 * EOperations
	 */
	m_startObjectBehaviorAction_Operation_behavior->setName("behavior");
	m_startObjectBehaviorAction_Operation_behavior->setEType(getBehavior_Class());
	m_startObjectBehaviorAction_Operation_behavior->setLowerBound(0);
	m_startObjectBehaviorAction_Operation_behavior->setUpperBound(1);
	m_startObjectBehaviorAction_Operation_behavior->setUnique(true);
	m_startObjectBehaviorAction_Operation_behavior->setOrdered(false);
	
	m_startObjectBehaviorAction_Operation_behavior->_setID(STARTOBJECTBEHAVIORACTION_OPERATION_BEHAVIOR);
	
	
	
}

void umlPackageImpl::initializeStateContent()
{
	m_state_Class->setName("State");
	m_state_Class->setAbstract(false);
	m_state_Class->setInterface(false);
	
	m_state_Class->_setID(STATE_CLASS);
	
	/*
	 * EAttributes
	 */
	m_state_Attribute_isComposite = getState_Attribute_isComposite();
	m_state_Attribute_isComposite->setName("isComposite");
	m_state_Attribute_isComposite->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_state_Attribute_isComposite->setLowerBound(1);
	m_state_Attribute_isComposite->setUpperBound(1);
	m_state_Attribute_isComposite->setTransient(true);
	m_state_Attribute_isComposite->setVolatile(true);
	m_state_Attribute_isComposite->setChangeable(false);
	m_state_Attribute_isComposite->setUnsettable(false);
	m_state_Attribute_isComposite->setUnique(true);
	m_state_Attribute_isComposite->setDerived(true);
	m_state_Attribute_isComposite->setOrdered(false);
	m_state_Attribute_isComposite->setID(false);
	m_state_Attribute_isComposite->setDefaultValueLiteral("");
	
	m_state_Attribute_isComposite->_setID(STATE_ATTRIBUTE_ISCOMPOSITE);
	m_state_Attribute_isOrthogonal = getState_Attribute_isOrthogonal();
	m_state_Attribute_isOrthogonal->setName("isOrthogonal");
	m_state_Attribute_isOrthogonal->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_state_Attribute_isOrthogonal->setLowerBound(1);
	m_state_Attribute_isOrthogonal->setUpperBound(1);
	m_state_Attribute_isOrthogonal->setTransient(true);
	m_state_Attribute_isOrthogonal->setVolatile(true);
	m_state_Attribute_isOrthogonal->setChangeable(false);
	m_state_Attribute_isOrthogonal->setUnsettable(false);
	m_state_Attribute_isOrthogonal->setUnique(true);
	m_state_Attribute_isOrthogonal->setDerived(true);
	m_state_Attribute_isOrthogonal->setOrdered(false);
	m_state_Attribute_isOrthogonal->setID(false);
	m_state_Attribute_isOrthogonal->setDefaultValueLiteral("");
	
	m_state_Attribute_isOrthogonal->_setID(STATE_ATTRIBUTE_ISORTHOGONAL);
	m_state_Attribute_isSimple = getState_Attribute_isSimple();
	m_state_Attribute_isSimple->setName("isSimple");
	m_state_Attribute_isSimple->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_state_Attribute_isSimple->setLowerBound(1);
	m_state_Attribute_isSimple->setUpperBound(1);
	m_state_Attribute_isSimple->setTransient(true);
	m_state_Attribute_isSimple->setVolatile(true);
	m_state_Attribute_isSimple->setChangeable(false);
	m_state_Attribute_isSimple->setUnsettable(false);
	m_state_Attribute_isSimple->setUnique(true);
	m_state_Attribute_isSimple->setDerived(true);
	m_state_Attribute_isSimple->setOrdered(false);
	m_state_Attribute_isSimple->setID(false);
	m_state_Attribute_isSimple->setDefaultValueLiteral("true");
	
	m_state_Attribute_isSimple->_setID(STATE_ATTRIBUTE_ISSIMPLE);
	m_state_Attribute_isSubmachineState = getState_Attribute_isSubmachineState();
	m_state_Attribute_isSubmachineState->setName("isSubmachineState");
	m_state_Attribute_isSubmachineState->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_state_Attribute_isSubmachineState->setLowerBound(1);
	m_state_Attribute_isSubmachineState->setUpperBound(1);
	m_state_Attribute_isSubmachineState->setTransient(true);
	m_state_Attribute_isSubmachineState->setVolatile(true);
	m_state_Attribute_isSubmachineState->setChangeable(false);
	m_state_Attribute_isSubmachineState->setUnsettable(false);
	m_state_Attribute_isSubmachineState->setUnique(true);
	m_state_Attribute_isSubmachineState->setDerived(true);
	m_state_Attribute_isSubmachineState->setOrdered(false);
	m_state_Attribute_isSubmachineState->setID(false);
	m_state_Attribute_isSubmachineState->setDefaultValueLiteral("");
	
	m_state_Attribute_isSubmachineState->_setID(STATE_ATTRIBUTE_ISSUBMACHINESTATE);
	
	/*
	 * EReferences
	 */
	m_state_Attribute_connection->setName("connection");
	m_state_Attribute_connection->setEType(getConnectionPointReference_Class());
	m_state_Attribute_connection->setLowerBound(0);
	m_state_Attribute_connection->setUpperBound(-1);
	m_state_Attribute_connection->setTransient(false);
	m_state_Attribute_connection->setVolatile(false);
	m_state_Attribute_connection->setChangeable(true);
	m_state_Attribute_connection->setUnsettable(false);
	m_state_Attribute_connection->setUnique(true);
	m_state_Attribute_connection->setDerived(false);
	m_state_Attribute_connection->setOrdered(false);
	m_state_Attribute_connection->setContainment(true);
	m_state_Attribute_connection->setResolveProxies(true);
	m_state_Attribute_connection->setDefaultValueLiteral("");	
	m_state_Attribute_connection->setEOpposite(uml::umlPackage::eInstance()->getConnectionPointReference_Attribute_state());
	
	m_state_Attribute_connection->_setID(STATE_ATTRIBUTE_CONNECTION);
	m_state_Attribute_connectionPoint->setName("connectionPoint");
	m_state_Attribute_connectionPoint->setEType(getPseudostate_Class());
	m_state_Attribute_connectionPoint->setLowerBound(0);
	m_state_Attribute_connectionPoint->setUpperBound(-1);
	m_state_Attribute_connectionPoint->setTransient(false);
	m_state_Attribute_connectionPoint->setVolatile(false);
	m_state_Attribute_connectionPoint->setChangeable(true);
	m_state_Attribute_connectionPoint->setUnsettable(false);
	m_state_Attribute_connectionPoint->setUnique(true);
	m_state_Attribute_connectionPoint->setDerived(false);
	m_state_Attribute_connectionPoint->setOrdered(false);
	m_state_Attribute_connectionPoint->setContainment(true);
	m_state_Attribute_connectionPoint->setResolveProxies(true);
	m_state_Attribute_connectionPoint->setDefaultValueLiteral("");	
	m_state_Attribute_connectionPoint->setEOpposite(uml::umlPackage::eInstance()->getPseudostate_Attribute_state());
	
	m_state_Attribute_connectionPoint->_setID(STATE_ATTRIBUTE_CONNECTIONPOINT);
	m_state_Attribute_deferrableTrigger->setName("deferrableTrigger");
	m_state_Attribute_deferrableTrigger->setEType(getTrigger_Class());
	m_state_Attribute_deferrableTrigger->setLowerBound(0);
	m_state_Attribute_deferrableTrigger->setUpperBound(-1);
	m_state_Attribute_deferrableTrigger->setTransient(false);
	m_state_Attribute_deferrableTrigger->setVolatile(false);
	m_state_Attribute_deferrableTrigger->setChangeable(true);
	m_state_Attribute_deferrableTrigger->setUnsettable(false);
	m_state_Attribute_deferrableTrigger->setUnique(true);
	m_state_Attribute_deferrableTrigger->setDerived(false);
	m_state_Attribute_deferrableTrigger->setOrdered(false);
	m_state_Attribute_deferrableTrigger->setContainment(true);
	m_state_Attribute_deferrableTrigger->setResolveProxies(true);
	m_state_Attribute_deferrableTrigger->setDefaultValueLiteral("");	
	
	m_state_Attribute_deferrableTrigger->_setID(STATE_ATTRIBUTE_DEFERRABLETRIGGER);
	m_state_Attribute_doActivity->setName("doActivity");
	m_state_Attribute_doActivity->setEType(getBehavior_Class());
	m_state_Attribute_doActivity->setLowerBound(0);
	m_state_Attribute_doActivity->setUpperBound(1);
	m_state_Attribute_doActivity->setTransient(false);
	m_state_Attribute_doActivity->setVolatile(false);
	m_state_Attribute_doActivity->setChangeable(true);
	m_state_Attribute_doActivity->setUnsettable(false);
	m_state_Attribute_doActivity->setUnique(true);
	m_state_Attribute_doActivity->setDerived(false);
	m_state_Attribute_doActivity->setOrdered(false);
	m_state_Attribute_doActivity->setContainment(true);
	m_state_Attribute_doActivity->setResolveProxies(true);
	m_state_Attribute_doActivity->setDefaultValueLiteral("");	
	
	m_state_Attribute_doActivity->_setID(STATE_ATTRIBUTE_DOACTIVITY);
	m_state_Attribute_entry->setName("entry");
	m_state_Attribute_entry->setEType(getBehavior_Class());
	m_state_Attribute_entry->setLowerBound(0);
	m_state_Attribute_entry->setUpperBound(1);
	m_state_Attribute_entry->setTransient(false);
	m_state_Attribute_entry->setVolatile(false);
	m_state_Attribute_entry->setChangeable(true);
	m_state_Attribute_entry->setUnsettable(false);
	m_state_Attribute_entry->setUnique(true);
	m_state_Attribute_entry->setDerived(false);
	m_state_Attribute_entry->setOrdered(false);
	m_state_Attribute_entry->setContainment(true);
	m_state_Attribute_entry->setResolveProxies(true);
	m_state_Attribute_entry->setDefaultValueLiteral("");	
	
	m_state_Attribute_entry->_setID(STATE_ATTRIBUTE_ENTRY);
	m_state_Attribute_exit->setName("exit");
	m_state_Attribute_exit->setEType(getBehavior_Class());
	m_state_Attribute_exit->setLowerBound(0);
	m_state_Attribute_exit->setUpperBound(1);
	m_state_Attribute_exit->setTransient(false);
	m_state_Attribute_exit->setVolatile(false);
	m_state_Attribute_exit->setChangeable(true);
	m_state_Attribute_exit->setUnsettable(false);
	m_state_Attribute_exit->setUnique(true);
	m_state_Attribute_exit->setDerived(false);
	m_state_Attribute_exit->setOrdered(false);
	m_state_Attribute_exit->setContainment(true);
	m_state_Attribute_exit->setResolveProxies(true);
	m_state_Attribute_exit->setDefaultValueLiteral("");	
	
	m_state_Attribute_exit->_setID(STATE_ATTRIBUTE_EXIT);
	m_state_Attribute_redefinedState->setName("redefinedState");
	m_state_Attribute_redefinedState->setEType(getState_Class());
	m_state_Attribute_redefinedState->setLowerBound(0);
	m_state_Attribute_redefinedState->setUpperBound(1);
	m_state_Attribute_redefinedState->setTransient(false);
	m_state_Attribute_redefinedState->setVolatile(false);
	m_state_Attribute_redefinedState->setChangeable(true);
	m_state_Attribute_redefinedState->setUnsettable(false);
	m_state_Attribute_redefinedState->setUnique(true);
	m_state_Attribute_redefinedState->setDerived(false);
	m_state_Attribute_redefinedState->setOrdered(false);
	m_state_Attribute_redefinedState->setContainment(false);
	m_state_Attribute_redefinedState->setResolveProxies(true);
	m_state_Attribute_redefinedState->setDefaultValueLiteral("");	
	
	m_state_Attribute_redefinedState->_setID(STATE_ATTRIBUTE_REDEFINEDSTATE);
	m_state_Attribute_region->setName("region");
	m_state_Attribute_region->setEType(getRegion_Class());
	m_state_Attribute_region->setLowerBound(0);
	m_state_Attribute_region->setUpperBound(-1);
	m_state_Attribute_region->setTransient(false);
	m_state_Attribute_region->setVolatile(false);
	m_state_Attribute_region->setChangeable(true);
	m_state_Attribute_region->setUnsettable(false);
	m_state_Attribute_region->setUnique(true);
	m_state_Attribute_region->setDerived(false);
	m_state_Attribute_region->setOrdered(false);
	m_state_Attribute_region->setContainment(true);
	m_state_Attribute_region->setResolveProxies(true);
	m_state_Attribute_region->setDefaultValueLiteral("");	
	m_state_Attribute_region->setEOpposite(uml::umlPackage::eInstance()->getRegion_Attribute_state());
	
	m_state_Attribute_region->_setID(STATE_ATTRIBUTE_REGION);
	m_state_Attribute_stateInvariant->setName("stateInvariant");
	m_state_Attribute_stateInvariant->setEType(getConstraint_Class());
	m_state_Attribute_stateInvariant->setLowerBound(0);
	m_state_Attribute_stateInvariant->setUpperBound(1);
	m_state_Attribute_stateInvariant->setTransient(false);
	m_state_Attribute_stateInvariant->setVolatile(false);
	m_state_Attribute_stateInvariant->setChangeable(true);
	m_state_Attribute_stateInvariant->setUnsettable(false);
	m_state_Attribute_stateInvariant->setUnique(true);
	m_state_Attribute_stateInvariant->setDerived(false);
	m_state_Attribute_stateInvariant->setOrdered(false);
	m_state_Attribute_stateInvariant->setContainment(false);
	m_state_Attribute_stateInvariant->setResolveProxies(true);
	m_state_Attribute_stateInvariant->setDefaultValueLiteral("");	
	
	m_state_Attribute_stateInvariant->_setID(STATE_ATTRIBUTE_STATEINVARIANT);
	m_state_Attribute_submachine->setName("submachine");
	m_state_Attribute_submachine->setEType(getStateMachine_Class());
	m_state_Attribute_submachine->setLowerBound(0);
	m_state_Attribute_submachine->setUpperBound(1);
	m_state_Attribute_submachine->setTransient(false);
	m_state_Attribute_submachine->setVolatile(false);
	m_state_Attribute_submachine->setChangeable(true);
	m_state_Attribute_submachine->setUnsettable(false);
	m_state_Attribute_submachine->setUnique(true);
	m_state_Attribute_submachine->setDerived(false);
	m_state_Attribute_submachine->setOrdered(false);
	m_state_Attribute_submachine->setContainment(false);
	m_state_Attribute_submachine->setResolveProxies(true);
	m_state_Attribute_submachine->setDefaultValueLiteral("");	
	m_state_Attribute_submachine->setEOpposite(uml::umlPackage::eInstance()->getStateMachine_Attribute_submachineState());
	
	m_state_Attribute_submachine->_setID(STATE_ATTRIBUTE_SUBMACHINE);
	
	/*
	 * EOperations
	 */
	m_state_Operation_isComposite->setName("isComposite");
	m_state_Operation_isComposite->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_state_Operation_isComposite->setLowerBound(1);
	m_state_Operation_isComposite->setUpperBound(1);
	m_state_Operation_isComposite->setUnique(true);
	m_state_Operation_isComposite->setOrdered(false);
	
	m_state_Operation_isComposite->_setID(STATE_OPERATION_ISCOMPOSITE);
	
	
	m_state_Operation_isOrthogonal->setName("isOrthogonal");
	m_state_Operation_isOrthogonal->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_state_Operation_isOrthogonal->setLowerBound(1);
	m_state_Operation_isOrthogonal->setUpperBound(1);
	m_state_Operation_isOrthogonal->setUnique(true);
	m_state_Operation_isOrthogonal->setOrdered(false);
	
	m_state_Operation_isOrthogonal->_setID(STATE_OPERATION_ISORTHOGONAL);
	
	
	m_state_Operation_isSimple->setName("isSimple");
	m_state_Operation_isSimple->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_state_Operation_isSimple->setLowerBound(1);
	m_state_Operation_isSimple->setUpperBound(1);
	m_state_Operation_isSimple->setUnique(true);
	m_state_Operation_isSimple->setOrdered(false);
	
	m_state_Operation_isSimple->_setID(STATE_OPERATION_ISSIMPLE);
	
	
	m_state_Operation_isSubmachineState->setName("isSubmachineState");
	m_state_Operation_isSubmachineState->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_state_Operation_isSubmachineState->setLowerBound(1);
	m_state_Operation_isSubmachineState->setUpperBound(1);
	m_state_Operation_isSubmachineState->setUnique(true);
	m_state_Operation_isSubmachineState->setOrdered(false);
	
	m_state_Operation_isSubmachineState->_setID(STATE_OPERATION_ISSUBMACHINESTATE);
	
	
	m_state_Operation_redefinitionContext->setName("redefinitionContext");
	m_state_Operation_redefinitionContext->setEType(getClassifier_Class());
	m_state_Operation_redefinitionContext->setLowerBound(1);
	m_state_Operation_redefinitionContext->setUpperBound(1);
	m_state_Operation_redefinitionContext->setUnique(true);
	m_state_Operation_redefinitionContext->setOrdered(false);
	
	m_state_Operation_redefinitionContext->_setID(STATE_OPERATION_REDEFINITIONCONTEXT);
	
	
	
}

void umlPackageImpl::initializeStateInvariantContent()
{
	m_stateInvariant_Class->setName("StateInvariant");
	m_stateInvariant_Class->setAbstract(false);
	m_stateInvariant_Class->setInterface(false);
	
	m_stateInvariant_Class->_setID(STATEINVARIANT_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_stateInvariant_Attribute_invariant->setName("invariant");
	m_stateInvariant_Attribute_invariant->setEType(getConstraint_Class());
	m_stateInvariant_Attribute_invariant->setLowerBound(1);
	m_stateInvariant_Attribute_invariant->setUpperBound(1);
	m_stateInvariant_Attribute_invariant->setTransient(false);
	m_stateInvariant_Attribute_invariant->setVolatile(false);
	m_stateInvariant_Attribute_invariant->setChangeable(true);
	m_stateInvariant_Attribute_invariant->setUnsettable(false);
	m_stateInvariant_Attribute_invariant->setUnique(true);
	m_stateInvariant_Attribute_invariant->setDerived(false);
	m_stateInvariant_Attribute_invariant->setOrdered(false);
	m_stateInvariant_Attribute_invariant->setContainment(true);
	m_stateInvariant_Attribute_invariant->setResolveProxies(true);
	m_stateInvariant_Attribute_invariant->setDefaultValueLiteral("");	
	
	m_stateInvariant_Attribute_invariant->_setID(STATEINVARIANT_ATTRIBUTE_INVARIANT);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeStateMachineContent()
{
	m_stateMachine_Class->setName("StateMachine");
	m_stateMachine_Class->setAbstract(false);
	m_stateMachine_Class->setInterface(false);
	
	m_stateMachine_Class->_setID(STATEMACHINE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_stateMachine_Attribute_connectionPoint->setName("connectionPoint");
	m_stateMachine_Attribute_connectionPoint->setEType(getPseudostate_Class());
	m_stateMachine_Attribute_connectionPoint->setLowerBound(0);
	m_stateMachine_Attribute_connectionPoint->setUpperBound(-1);
	m_stateMachine_Attribute_connectionPoint->setTransient(false);
	m_stateMachine_Attribute_connectionPoint->setVolatile(false);
	m_stateMachine_Attribute_connectionPoint->setChangeable(true);
	m_stateMachine_Attribute_connectionPoint->setUnsettable(false);
	m_stateMachine_Attribute_connectionPoint->setUnique(true);
	m_stateMachine_Attribute_connectionPoint->setDerived(false);
	m_stateMachine_Attribute_connectionPoint->setOrdered(false);
	m_stateMachine_Attribute_connectionPoint->setContainment(true);
	m_stateMachine_Attribute_connectionPoint->setResolveProxies(true);
	m_stateMachine_Attribute_connectionPoint->setDefaultValueLiteral("");	
	m_stateMachine_Attribute_connectionPoint->setEOpposite(uml::umlPackage::eInstance()->getPseudostate_Attribute_stateMachine());
	
	m_stateMachine_Attribute_connectionPoint->_setID(STATEMACHINE_ATTRIBUTE_CONNECTIONPOINT);
	m_stateMachine_Attribute_extendedStateMachine->setName("extendedStateMachine");
	m_stateMachine_Attribute_extendedStateMachine->setEType(getStateMachine_Class());
	m_stateMachine_Attribute_extendedStateMachine->setLowerBound(0);
	m_stateMachine_Attribute_extendedStateMachine->setUpperBound(-1);
	m_stateMachine_Attribute_extendedStateMachine->setTransient(false);
	m_stateMachine_Attribute_extendedStateMachine->setVolatile(false);
	m_stateMachine_Attribute_extendedStateMachine->setChangeable(true);
	m_stateMachine_Attribute_extendedStateMachine->setUnsettable(false);
	m_stateMachine_Attribute_extendedStateMachine->setUnique(true);
	m_stateMachine_Attribute_extendedStateMachine->setDerived(false);
	m_stateMachine_Attribute_extendedStateMachine->setOrdered(false);
	m_stateMachine_Attribute_extendedStateMachine->setContainment(false);
	m_stateMachine_Attribute_extendedStateMachine->setResolveProxies(true);
	m_stateMachine_Attribute_extendedStateMachine->setDefaultValueLiteral("");	
	
	m_stateMachine_Attribute_extendedStateMachine->_setID(STATEMACHINE_ATTRIBUTE_EXTENDEDSTATEMACHINE);
	m_stateMachine_Attribute_region->setName("region");
	m_stateMachine_Attribute_region->setEType(getRegion_Class());
	m_stateMachine_Attribute_region->setLowerBound(1);
	m_stateMachine_Attribute_region->setUpperBound(-1);
	m_stateMachine_Attribute_region->setTransient(false);
	m_stateMachine_Attribute_region->setVolatile(false);
	m_stateMachine_Attribute_region->setChangeable(true);
	m_stateMachine_Attribute_region->setUnsettable(false);
	m_stateMachine_Attribute_region->setUnique(true);
	m_stateMachine_Attribute_region->setDerived(false);
	m_stateMachine_Attribute_region->setOrdered(false);
	m_stateMachine_Attribute_region->setContainment(true);
	m_stateMachine_Attribute_region->setResolveProxies(true);
	m_stateMachine_Attribute_region->setDefaultValueLiteral("");	
	m_stateMachine_Attribute_region->setEOpposite(uml::umlPackage::eInstance()->getRegion_Attribute_stateMachine());
	
	m_stateMachine_Attribute_region->_setID(STATEMACHINE_ATTRIBUTE_REGION);
	m_stateMachine_Attribute_submachineState->setName("submachineState");
	m_stateMachine_Attribute_submachineState->setEType(getState_Class());
	m_stateMachine_Attribute_submachineState->setLowerBound(0);
	m_stateMachine_Attribute_submachineState->setUpperBound(-1);
	m_stateMachine_Attribute_submachineState->setTransient(false);
	m_stateMachine_Attribute_submachineState->setVolatile(false);
	m_stateMachine_Attribute_submachineState->setChangeable(true);
	m_stateMachine_Attribute_submachineState->setUnsettable(false);
	m_stateMachine_Attribute_submachineState->setUnique(true);
	m_stateMachine_Attribute_submachineState->setDerived(false);
	m_stateMachine_Attribute_submachineState->setOrdered(false);
	m_stateMachine_Attribute_submachineState->setContainment(false);
	m_stateMachine_Attribute_submachineState->setResolveProxies(true);
	m_stateMachine_Attribute_submachineState->setDefaultValueLiteral("");	
	m_stateMachine_Attribute_submachineState->setEOpposite(uml::umlPackage::eInstance()->getState_Attribute_submachine());
	
	m_stateMachine_Attribute_submachineState->_setID(STATEMACHINE_ATTRIBUTE_SUBMACHINESTATE);
	
	/*
	 * EOperations
	 */
	m_stateMachine_Operation_lCA_Vertex_Vertex->setName("LCA");
	m_stateMachine_Operation_lCA_Vertex_Vertex->setEType(getRegion_Class());
	m_stateMachine_Operation_lCA_Vertex_Vertex->setLowerBound(1);
	m_stateMachine_Operation_lCA_Vertex_Vertex->setUpperBound(1);
	m_stateMachine_Operation_lCA_Vertex_Vertex->setUnique(true);
	m_stateMachine_Operation_lCA_Vertex_Vertex->setOrdered(false);
	
	m_stateMachine_Operation_lCA_Vertex_Vertex->_setID(STATEMACHINE_OPERATION_LCA_VERTEX_VERTEX);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateMachine_Operation_lCA_Vertex_Vertex);
		parameter->setName("s1");
		parameter->setEType(getVertex_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateMachine_Operation_lCA_Vertex_Vertex);
		parameter->setName("s2");
		parameter->setEType(getVertex_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stateMachine_Operation_lCAState_Vertex_Vertex->setName("LCAState");
	m_stateMachine_Operation_lCAState_Vertex_Vertex->setEType(getState_Class());
	m_stateMachine_Operation_lCAState_Vertex_Vertex->setLowerBound(1);
	m_stateMachine_Operation_lCAState_Vertex_Vertex->setUpperBound(1);
	m_stateMachine_Operation_lCAState_Vertex_Vertex->setUnique(true);
	m_stateMachine_Operation_lCAState_Vertex_Vertex->setOrdered(false);
	
	m_stateMachine_Operation_lCAState_Vertex_Vertex->_setID(STATEMACHINE_OPERATION_LCASTATE_VERTEX_VERTEX);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateMachine_Operation_lCAState_Vertex_Vertex);
		parameter->setName("v1");
		parameter->setEType(getVertex_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateMachine_Operation_lCAState_Vertex_Vertex);
		parameter->setName("v2");
		parameter->setEType(getVertex_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stateMachine_Operation_ancestor_Vertex_Vertex->setName("ancestor");
	m_stateMachine_Operation_ancestor_Vertex_Vertex->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_stateMachine_Operation_ancestor_Vertex_Vertex->setLowerBound(1);
	m_stateMachine_Operation_ancestor_Vertex_Vertex->setUpperBound(1);
	m_stateMachine_Operation_ancestor_Vertex_Vertex->setUnique(true);
	m_stateMachine_Operation_ancestor_Vertex_Vertex->setOrdered(false);
	
	m_stateMachine_Operation_ancestor_Vertex_Vertex->_setID(STATEMACHINE_OPERATION_ANCESTOR_VERTEX_VERTEX);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateMachine_Operation_ancestor_Vertex_Vertex);
		parameter->setName("s1");
		parameter->setEType(getVertex_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stateMachine_Operation_ancestor_Vertex_Vertex);
		parameter->setName("s2");
		parameter->setEType(getVertex_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void umlPackageImpl::initializeStereotypeContent()
{
	m_stereotype_Class->setName("Stereotype");
	m_stereotype_Class->setAbstract(false);
	m_stereotype_Class->setInterface(false);
	
	m_stereotype_Class->_setID(STEREOTYPE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_stereotype_Attribute_icon->setName("icon");
	m_stereotype_Attribute_icon->setEType(getImage_Class());
	m_stereotype_Attribute_icon->setLowerBound(0);
	m_stereotype_Attribute_icon->setUpperBound(-1);
	m_stereotype_Attribute_icon->setTransient(false);
	m_stereotype_Attribute_icon->setVolatile(false);
	m_stereotype_Attribute_icon->setChangeable(true);
	m_stereotype_Attribute_icon->setUnsettable(false);
	m_stereotype_Attribute_icon->setUnique(true);
	m_stereotype_Attribute_icon->setDerived(false);
	m_stereotype_Attribute_icon->setOrdered(false);
	m_stereotype_Attribute_icon->setContainment(true);
	m_stereotype_Attribute_icon->setResolveProxies(true);
	m_stereotype_Attribute_icon->setDefaultValueLiteral("");	
	
	m_stereotype_Attribute_icon->_setID(STEREOTYPE_ATTRIBUTE_ICON);
	m_stereotype_Attribute_profile->setName("profile");
	m_stereotype_Attribute_profile->setEType(getProfile_Class());
	m_stereotype_Attribute_profile->setLowerBound(1);
	m_stereotype_Attribute_profile->setUpperBound(1);
	m_stereotype_Attribute_profile->setTransient(true);
	m_stereotype_Attribute_profile->setVolatile(true);
	m_stereotype_Attribute_profile->setChangeable(false);
	m_stereotype_Attribute_profile->setUnsettable(false);
	m_stereotype_Attribute_profile->setUnique(true);
	m_stereotype_Attribute_profile->setDerived(true);
	m_stereotype_Attribute_profile->setOrdered(false);
	m_stereotype_Attribute_profile->setContainment(false);
	m_stereotype_Attribute_profile->setResolveProxies(true);
	m_stereotype_Attribute_profile->setDefaultValueLiteral("");	
	
	m_stereotype_Attribute_profile->_setID(STEREOTYPE_ATTRIBUTE_PROFILE);
	
	/*
	 * EOperations
	 */
	m_stereotype_Operation_containingProfile->setName("containingProfile");
	m_stereotype_Operation_containingProfile->setEType(getProfile_Class());
	m_stereotype_Operation_containingProfile->setLowerBound(1);
	m_stereotype_Operation_containingProfile->setUpperBound(1);
	m_stereotype_Operation_containingProfile->setUnique(true);
	m_stereotype_Operation_containingProfile->setOrdered(false);
	
	m_stereotype_Operation_containingProfile->_setID(STEREOTYPE_OPERATION_CONTAININGPROFILE);
	
	
	m_stereotype_Operation_createExtension_Class_Boolean->setName("createExtension");
	m_stereotype_Operation_createExtension_Class_Boolean->setEType(getExtension_Class());
	m_stereotype_Operation_createExtension_Class_Boolean->setLowerBound(1);
	m_stereotype_Operation_createExtension_Class_Boolean->setUpperBound(1);
	m_stereotype_Operation_createExtension_Class_Boolean->setUnique(true);
	m_stereotype_Operation_createExtension_Class_Boolean->setOrdered(false);
	
	m_stereotype_Operation_createExtension_Class_Boolean->_setID(STEREOTYPE_OPERATION_CREATEEXTENSION_CLASS_BOOLEAN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stereotype_Operation_createExtension_Class_Boolean);
		parameter->setName("metaclass");
		parameter->setEType(getClass_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stereotype_Operation_createExtension_Class_Boolean);
		parameter->setName("isRequired");
		parameter->setEType(types::typesPackage::eInstance()->getBoolean_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stereotype_Operation_createIcon_String->setName("createIcon");
	m_stereotype_Operation_createIcon_String->setEType(getImage_Class());
	m_stereotype_Operation_createIcon_String->setLowerBound(1);
	m_stereotype_Operation_createIcon_String->setUpperBound(1);
	m_stereotype_Operation_createIcon_String->setUnique(true);
	m_stereotype_Operation_createIcon_String->setOrdered(false);
	
	m_stereotype_Operation_createIcon_String->_setID(STEREOTYPE_OPERATION_CREATEICON_STRING);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stereotype_Operation_createIcon_String);
		parameter->setName("location");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stereotype_Operation_createIcon_String_String->setName("createIcon");
	m_stereotype_Operation_createIcon_String_String->setEType(getImage_Class());
	m_stereotype_Operation_createIcon_String_String->setLowerBound(1);
	m_stereotype_Operation_createIcon_String_String->setUpperBound(1);
	m_stereotype_Operation_createIcon_String_String->setUnique(true);
	m_stereotype_Operation_createIcon_String_String->setOrdered(false);
	
	m_stereotype_Operation_createIcon_String_String->_setID(STEREOTYPE_OPERATION_CREATEICON_STRING_STRING);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stereotype_Operation_createIcon_String_String);
		parameter->setName("format");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stereotype_Operation_createIcon_String_String);
		parameter->setName("content");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stereotype_Operation_getAllExtendedMetaclasses->setName("getAllExtendedMetaclasses");
	m_stereotype_Operation_getAllExtendedMetaclasses->setEType(getClass_Class());
	m_stereotype_Operation_getAllExtendedMetaclasses->setLowerBound(0);
	m_stereotype_Operation_getAllExtendedMetaclasses->setUpperBound(-1);
	m_stereotype_Operation_getAllExtendedMetaclasses->setUnique(true);
	m_stereotype_Operation_getAllExtendedMetaclasses->setOrdered(false);
	
	m_stereotype_Operation_getAllExtendedMetaclasses->_setID(STEREOTYPE_OPERATION_GETALLEXTENDEDMETACLASSES);
	
	
	m_stereotype_Operation_getDefinition->setName("getDefinition");
	m_stereotype_Operation_getDefinition->setEType(ecore::ecorePackage::eInstance()->getEClass_Class());
	m_stereotype_Operation_getDefinition->setLowerBound(0);
	m_stereotype_Operation_getDefinition->setUpperBound(1);
	m_stereotype_Operation_getDefinition->setUnique(true);
	m_stereotype_Operation_getDefinition->setOrdered(false);
	
	m_stereotype_Operation_getDefinition->_setID(STEREOTYPE_OPERATION_GETDEFINITION);
	
	
	m_stereotype_Operation_getExtendedMetaclasses->setName("getExtendedMetaclasses");
	m_stereotype_Operation_getExtendedMetaclasses->setEType(getClass_Class());
	m_stereotype_Operation_getExtendedMetaclasses->setLowerBound(0);
	m_stereotype_Operation_getExtendedMetaclasses->setUpperBound(-1);
	m_stereotype_Operation_getExtendedMetaclasses->setUnique(true);
	m_stereotype_Operation_getExtendedMetaclasses->setOrdered(false);
	
	m_stereotype_Operation_getExtendedMetaclasses->_setID(STEREOTYPE_OPERATION_GETEXTENDEDMETACLASSES);
	
	
	m_stereotype_Operation_getKeyword->setName("getKeyword");
	m_stereotype_Operation_getKeyword->setEType(types::typesPackage::eInstance()->getString_Class());
	m_stereotype_Operation_getKeyword->setLowerBound(1);
	m_stereotype_Operation_getKeyword->setUpperBound(1);
	m_stereotype_Operation_getKeyword->setUnique(true);
	m_stereotype_Operation_getKeyword->setOrdered(false);
	
	m_stereotype_Operation_getKeyword->_setID(STEREOTYPE_OPERATION_GETKEYWORD);
	
	
	m_stereotype_Operation_getKeyword_Boolean->setName("getKeyword");
	m_stereotype_Operation_getKeyword_Boolean->setEType(types::typesPackage::eInstance()->getString_Class());
	m_stereotype_Operation_getKeyword_Boolean->setLowerBound(1);
	m_stereotype_Operation_getKeyword_Boolean->setUpperBound(1);
	m_stereotype_Operation_getKeyword_Boolean->setUnique(true);
	m_stereotype_Operation_getKeyword_Boolean->setOrdered(false);
	
	m_stereotype_Operation_getKeyword_Boolean->_setID(STEREOTYPE_OPERATION_GETKEYWORD_BOOLEAN);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_stereotype_Operation_getKeyword_Boolean);
		parameter->setName("localize");
		parameter->setEType(types::typesPackage::eInstance()->getBoolean_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_stereotype_Operation_getProfile->setName("getProfile");
	m_stereotype_Operation_getProfile->setEType(getProfile_Class());
	m_stereotype_Operation_getProfile->setLowerBound(1);
	m_stereotype_Operation_getProfile->setUpperBound(1);
	m_stereotype_Operation_getProfile->setUnique(true);
	m_stereotype_Operation_getProfile->setOrdered(false);
	
	m_stereotype_Operation_getProfile->_setID(STEREOTYPE_OPERATION_GETPROFILE);
	
	
	
}

void umlPackageImpl::initializeStringExpressionContent()
{
	m_stringExpression_Class->setName("StringExpression");
	m_stringExpression_Class->setAbstract(false);
	m_stringExpression_Class->setInterface(false);
	
	m_stringExpression_Class->_setID(STRINGEXPRESSION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_stringExpression_Attribute_owningExpression->setName("owningExpression");
	m_stringExpression_Attribute_owningExpression->setEType(getStringExpression_Class());
	m_stringExpression_Attribute_owningExpression->setLowerBound(0);
	m_stringExpression_Attribute_owningExpression->setUpperBound(1);
	m_stringExpression_Attribute_owningExpression->setTransient(false);
	m_stringExpression_Attribute_owningExpression->setVolatile(false);
	m_stringExpression_Attribute_owningExpression->setChangeable(true);
	m_stringExpression_Attribute_owningExpression->setUnsettable(false);
	m_stringExpression_Attribute_owningExpression->setUnique(true);
	m_stringExpression_Attribute_owningExpression->setDerived(false);
	m_stringExpression_Attribute_owningExpression->setOrdered(false);
	m_stringExpression_Attribute_owningExpression->setContainment(false);
	m_stringExpression_Attribute_owningExpression->setResolveProxies(true);
	m_stringExpression_Attribute_owningExpression->setDefaultValueLiteral("");	
	m_stringExpression_Attribute_owningExpression->setEOpposite(uml::umlPackage::eInstance()->getStringExpression_Attribute_subExpression());
	
	m_stringExpression_Attribute_owningExpression->_setID(STRINGEXPRESSION_ATTRIBUTE_OWNINGEXPRESSION);
	m_stringExpression_Attribute_subExpression->setName("subExpression");
	m_stringExpression_Attribute_subExpression->setEType(getStringExpression_Class());
	m_stringExpression_Attribute_subExpression->setLowerBound(0);
	m_stringExpression_Attribute_subExpression->setUpperBound(-1);
	m_stringExpression_Attribute_subExpression->setTransient(false);
	m_stringExpression_Attribute_subExpression->setVolatile(false);
	m_stringExpression_Attribute_subExpression->setChangeable(true);
	m_stringExpression_Attribute_subExpression->setUnsettable(false);
	m_stringExpression_Attribute_subExpression->setUnique(true);
	m_stringExpression_Attribute_subExpression->setDerived(false);
	m_stringExpression_Attribute_subExpression->setOrdered(true);
	m_stringExpression_Attribute_subExpression->setContainment(true);
	m_stringExpression_Attribute_subExpression->setResolveProxies(true);
	m_stringExpression_Attribute_subExpression->setDefaultValueLiteral("");	
	m_stringExpression_Attribute_subExpression->setEOpposite(uml::umlPackage::eInstance()->getStringExpression_Attribute_owningExpression());
	
	m_stringExpression_Attribute_subExpression->_setID(STRINGEXPRESSION_ATTRIBUTE_SUBEXPRESSION);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeStructuralFeatureContent()
{
	m_structuralFeature_Class->setName("StructuralFeature");
	m_structuralFeature_Class->setAbstract(true);
	m_structuralFeature_Class->setInterface(false);
	
	m_structuralFeature_Class->_setID(STRUCTURALFEATURE_CLASS);
	
	/*
	 * EAttributes
	 */
	m_structuralFeature_Attribute_isReadOnly = getStructuralFeature_Attribute_isReadOnly();
	m_structuralFeature_Attribute_isReadOnly->setName("isReadOnly");
	m_structuralFeature_Attribute_isReadOnly->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_structuralFeature_Attribute_isReadOnly->setLowerBound(1);
	m_structuralFeature_Attribute_isReadOnly->setUpperBound(1);
	m_structuralFeature_Attribute_isReadOnly->setTransient(false);
	m_structuralFeature_Attribute_isReadOnly->setVolatile(false);
	m_structuralFeature_Attribute_isReadOnly->setChangeable(true);
	m_structuralFeature_Attribute_isReadOnly->setUnsettable(false);
	m_structuralFeature_Attribute_isReadOnly->setUnique(true);
	m_structuralFeature_Attribute_isReadOnly->setDerived(false);
	m_structuralFeature_Attribute_isReadOnly->setOrdered(false);
	m_structuralFeature_Attribute_isReadOnly->setID(false);
	m_structuralFeature_Attribute_isReadOnly->setDefaultValueLiteral("false");
	
	m_structuralFeature_Attribute_isReadOnly->_setID(STRUCTURALFEATURE_ATTRIBUTE_ISREADONLY);
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeStructuralFeatureActionContent()
{
	m_structuralFeatureAction_Class->setName("StructuralFeatureAction");
	m_structuralFeatureAction_Class->setAbstract(true);
	m_structuralFeatureAction_Class->setInterface(false);
	
	m_structuralFeatureAction_Class->_setID(STRUCTURALFEATUREACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_structuralFeatureAction_Attribute_object->setName("object");
	m_structuralFeatureAction_Attribute_object->setEType(getInputPin_Class());
	m_structuralFeatureAction_Attribute_object->setLowerBound(1);
	m_structuralFeatureAction_Attribute_object->setUpperBound(1);
	m_structuralFeatureAction_Attribute_object->setTransient(false);
	m_structuralFeatureAction_Attribute_object->setVolatile(false);
	m_structuralFeatureAction_Attribute_object->setChangeable(true);
	m_structuralFeatureAction_Attribute_object->setUnsettable(false);
	m_structuralFeatureAction_Attribute_object->setUnique(true);
	m_structuralFeatureAction_Attribute_object->setDerived(false);
	m_structuralFeatureAction_Attribute_object->setOrdered(false);
	m_structuralFeatureAction_Attribute_object->setContainment(true);
	m_structuralFeatureAction_Attribute_object->setResolveProxies(true);
	m_structuralFeatureAction_Attribute_object->setDefaultValueLiteral("");	
	m_structuralFeatureAction_Attribute_object->setEOpposite(uml::umlPackage::eInstance()->getInputPin_Attribute_structuralFeatureAction());
	
	m_structuralFeatureAction_Attribute_object->_setID(STRUCTURALFEATUREACTION_ATTRIBUTE_OBJECT);
	m_structuralFeatureAction_Attribute_structuralFeature->setName("structuralFeature");
	m_structuralFeatureAction_Attribute_structuralFeature->setEType(getStructuralFeature_Class());
	m_structuralFeatureAction_Attribute_structuralFeature->setLowerBound(1);
	m_structuralFeatureAction_Attribute_structuralFeature->setUpperBound(1);
	m_structuralFeatureAction_Attribute_structuralFeature->setTransient(false);
	m_structuralFeatureAction_Attribute_structuralFeature->setVolatile(false);
	m_structuralFeatureAction_Attribute_structuralFeature->setChangeable(true);
	m_structuralFeatureAction_Attribute_structuralFeature->setUnsettable(false);
	m_structuralFeatureAction_Attribute_structuralFeature->setUnique(true);
	m_structuralFeatureAction_Attribute_structuralFeature->setDerived(false);
	m_structuralFeatureAction_Attribute_structuralFeature->setOrdered(false);
	m_structuralFeatureAction_Attribute_structuralFeature->setContainment(false);
	m_structuralFeatureAction_Attribute_structuralFeature->setResolveProxies(true);
	m_structuralFeatureAction_Attribute_structuralFeature->setDefaultValueLiteral("");	
	
	m_structuralFeatureAction_Attribute_structuralFeature->_setID(STRUCTURALFEATUREACTION_ATTRIBUTE_STRUCTURALFEATURE);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeStructuredActivityNodeContent()
{
	m_structuredActivityNode_Class->setName("StructuredActivityNode");
	m_structuredActivityNode_Class->setAbstract(false);
	m_structuredActivityNode_Class->setInterface(false);
	
	m_structuredActivityNode_Class->_setID(STRUCTUREDACTIVITYNODE_CLASS);
	
	/*
	 * EAttributes
	 */
	m_structuredActivityNode_Attribute_mustIsolate = getStructuredActivityNode_Attribute_mustIsolate();
	m_structuredActivityNode_Attribute_mustIsolate->setName("mustIsolate");
	m_structuredActivityNode_Attribute_mustIsolate->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_structuredActivityNode_Attribute_mustIsolate->setLowerBound(1);
	m_structuredActivityNode_Attribute_mustIsolate->setUpperBound(1);
	m_structuredActivityNode_Attribute_mustIsolate->setTransient(false);
	m_structuredActivityNode_Attribute_mustIsolate->setVolatile(false);
	m_structuredActivityNode_Attribute_mustIsolate->setChangeable(true);
	m_structuredActivityNode_Attribute_mustIsolate->setUnsettable(false);
	m_structuredActivityNode_Attribute_mustIsolate->setUnique(true);
	m_structuredActivityNode_Attribute_mustIsolate->setDerived(false);
	m_structuredActivityNode_Attribute_mustIsolate->setOrdered(false);
	m_structuredActivityNode_Attribute_mustIsolate->setID(false);
	m_structuredActivityNode_Attribute_mustIsolate->setDefaultValueLiteral("false");
	
	m_structuredActivityNode_Attribute_mustIsolate->_setID(STRUCTUREDACTIVITYNODE_ATTRIBUTE_MUSTISOLATE);
	
	/*
	 * EReferences
	 */
	m_structuredActivityNode_Attribute_edge->setName("edge");
	m_structuredActivityNode_Attribute_edge->setEType(getActivityEdge_Class());
	m_structuredActivityNode_Attribute_edge->setLowerBound(0);
	m_structuredActivityNode_Attribute_edge->setUpperBound(-1);
	m_structuredActivityNode_Attribute_edge->setTransient(false);
	m_structuredActivityNode_Attribute_edge->setVolatile(false);
	m_structuredActivityNode_Attribute_edge->setChangeable(true);
	m_structuredActivityNode_Attribute_edge->setUnsettable(false);
	m_structuredActivityNode_Attribute_edge->setUnique(true);
	m_structuredActivityNode_Attribute_edge->setDerived(false);
	m_structuredActivityNode_Attribute_edge->setOrdered(false);
	m_structuredActivityNode_Attribute_edge->setContainment(true);
	m_structuredActivityNode_Attribute_edge->setResolveProxies(true);
	m_structuredActivityNode_Attribute_edge->setDefaultValueLiteral("");	
	m_structuredActivityNode_Attribute_edge->setEOpposite(uml::umlPackage::eInstance()->getActivityEdge_Attribute_inStructuredNode());
	
	m_structuredActivityNode_Attribute_edge->_setID(STRUCTUREDACTIVITYNODE_ATTRIBUTE_EDGE);
	m_structuredActivityNode_Attribute_node->setName("node");
	m_structuredActivityNode_Attribute_node->setEType(getActivityNode_Class());
	m_structuredActivityNode_Attribute_node->setLowerBound(0);
	m_structuredActivityNode_Attribute_node->setUpperBound(-1);
	m_structuredActivityNode_Attribute_node->setTransient(false);
	m_structuredActivityNode_Attribute_node->setVolatile(false);
	m_structuredActivityNode_Attribute_node->setChangeable(true);
	m_structuredActivityNode_Attribute_node->setUnsettable(false);
	m_structuredActivityNode_Attribute_node->setUnique(true);
	m_structuredActivityNode_Attribute_node->setDerived(false);
	m_structuredActivityNode_Attribute_node->setOrdered(false);
	m_structuredActivityNode_Attribute_node->setContainment(true);
	m_structuredActivityNode_Attribute_node->setResolveProxies(true);
	m_structuredActivityNode_Attribute_node->setDefaultValueLiteral("");	
	m_structuredActivityNode_Attribute_node->setEOpposite(uml::umlPackage::eInstance()->getActivityNode_Attribute_inStructuredNode());
	
	m_structuredActivityNode_Attribute_node->_setID(STRUCTUREDACTIVITYNODE_ATTRIBUTE_NODE);
	m_structuredActivityNode_Attribute_structuredNodeInput->setName("structuredNodeInput");
	m_structuredActivityNode_Attribute_structuredNodeInput->setEType(getInputPin_Class());
	m_structuredActivityNode_Attribute_structuredNodeInput->setLowerBound(0);
	m_structuredActivityNode_Attribute_structuredNodeInput->setUpperBound(-1);
	m_structuredActivityNode_Attribute_structuredNodeInput->setTransient(false);
	m_structuredActivityNode_Attribute_structuredNodeInput->setVolatile(false);
	m_structuredActivityNode_Attribute_structuredNodeInput->setChangeable(true);
	m_structuredActivityNode_Attribute_structuredNodeInput->setUnsettable(false);
	m_structuredActivityNode_Attribute_structuredNodeInput->setUnique(true);
	m_structuredActivityNode_Attribute_structuredNodeInput->setDerived(false);
	m_structuredActivityNode_Attribute_structuredNodeInput->setOrdered(false);
	m_structuredActivityNode_Attribute_structuredNodeInput->setContainment(true);
	m_structuredActivityNode_Attribute_structuredNodeInput->setResolveProxies(true);
	m_structuredActivityNode_Attribute_structuredNodeInput->setDefaultValueLiteral("");	
	
	m_structuredActivityNode_Attribute_structuredNodeInput->_setID(STRUCTUREDACTIVITYNODE_ATTRIBUTE_STRUCTUREDNODEINPUT);
	m_structuredActivityNode_Attribute_structuredNodeOutput->setName("structuredNodeOutput");
	m_structuredActivityNode_Attribute_structuredNodeOutput->setEType(getOutputPin_Class());
	m_structuredActivityNode_Attribute_structuredNodeOutput->setLowerBound(0);
	m_structuredActivityNode_Attribute_structuredNodeOutput->setUpperBound(-1);
	m_structuredActivityNode_Attribute_structuredNodeOutput->setTransient(false);
	m_structuredActivityNode_Attribute_structuredNodeOutput->setVolatile(false);
	m_structuredActivityNode_Attribute_structuredNodeOutput->setChangeable(true);
	m_structuredActivityNode_Attribute_structuredNodeOutput->setUnsettable(false);
	m_structuredActivityNode_Attribute_structuredNodeOutput->setUnique(true);
	m_structuredActivityNode_Attribute_structuredNodeOutput->setDerived(false);
	m_structuredActivityNode_Attribute_structuredNodeOutput->setOrdered(false);
	m_structuredActivityNode_Attribute_structuredNodeOutput->setContainment(true);
	m_structuredActivityNode_Attribute_structuredNodeOutput->setResolveProxies(true);
	m_structuredActivityNode_Attribute_structuredNodeOutput->setDefaultValueLiteral("");	
	
	m_structuredActivityNode_Attribute_structuredNodeOutput->_setID(STRUCTUREDACTIVITYNODE_ATTRIBUTE_STRUCTUREDNODEOUTPUT);
	m_structuredActivityNode_Attribute_variable->setName("variable");
	m_structuredActivityNode_Attribute_variable->setEType(getVariable_Class());
	m_structuredActivityNode_Attribute_variable->setLowerBound(0);
	m_structuredActivityNode_Attribute_variable->setUpperBound(-1);
	m_structuredActivityNode_Attribute_variable->setTransient(false);
	m_structuredActivityNode_Attribute_variable->setVolatile(false);
	m_structuredActivityNode_Attribute_variable->setChangeable(true);
	m_structuredActivityNode_Attribute_variable->setUnsettable(false);
	m_structuredActivityNode_Attribute_variable->setUnique(true);
	m_structuredActivityNode_Attribute_variable->setDerived(false);
	m_structuredActivityNode_Attribute_variable->setOrdered(false);
	m_structuredActivityNode_Attribute_variable->setContainment(true);
	m_structuredActivityNode_Attribute_variable->setResolveProxies(true);
	m_structuredActivityNode_Attribute_variable->setDefaultValueLiteral("");	
	m_structuredActivityNode_Attribute_variable->setEOpposite(uml::umlPackage::eInstance()->getVariable_Attribute_scope());
	
	m_structuredActivityNode_Attribute_variable->_setID(STRUCTUREDACTIVITYNODE_ATTRIBUTE_VARIABLE);
	
	/*
	 * EOperations
	 */
	m_structuredActivityNode_Operation_sourceNodes->setName("sourceNodes");
	m_structuredActivityNode_Operation_sourceNodes->setEType(getActivityNode_Class());
	m_structuredActivityNode_Operation_sourceNodes->setLowerBound(0);
	m_structuredActivityNode_Operation_sourceNodes->setUpperBound(-1);
	m_structuredActivityNode_Operation_sourceNodes->setUnique(true);
	m_structuredActivityNode_Operation_sourceNodes->setOrdered(false);
	
	m_structuredActivityNode_Operation_sourceNodes->_setID(STRUCTUREDACTIVITYNODE_OPERATION_SOURCENODES);
	
	
	m_structuredActivityNode_Operation_targetNodes->setName("targetNodes");
	m_structuredActivityNode_Operation_targetNodes->setEType(getActivityNode_Class());
	m_structuredActivityNode_Operation_targetNodes->setLowerBound(0);
	m_structuredActivityNode_Operation_targetNodes->setUpperBound(-1);
	m_structuredActivityNode_Operation_targetNodes->setUnique(true);
	m_structuredActivityNode_Operation_targetNodes->setOrdered(false);
	
	m_structuredActivityNode_Operation_targetNodes->_setID(STRUCTUREDACTIVITYNODE_OPERATION_TARGETNODES);
	
	
	
}

void umlPackageImpl::initializeStructuredClassifierContent()
{
	m_structuredClassifier_Class->setName("StructuredClassifier");
	m_structuredClassifier_Class->setAbstract(true);
	m_structuredClassifier_Class->setInterface(false);
	
	m_structuredClassifier_Class->_setID(STRUCTUREDCLASSIFIER_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_structuredClassifier_Attribute_ownedAttribute->setName("ownedAttribute");
	m_structuredClassifier_Attribute_ownedAttribute->setEType(getProperty_Class());
	m_structuredClassifier_Attribute_ownedAttribute->setLowerBound(0);
	m_structuredClassifier_Attribute_ownedAttribute->setUpperBound(-1);
	m_structuredClassifier_Attribute_ownedAttribute->setTransient(false);
	m_structuredClassifier_Attribute_ownedAttribute->setVolatile(false);
	m_structuredClassifier_Attribute_ownedAttribute->setChangeable(true);
	m_structuredClassifier_Attribute_ownedAttribute->setUnsettable(false);
	m_structuredClassifier_Attribute_ownedAttribute->setUnique(true);
	m_structuredClassifier_Attribute_ownedAttribute->setDerived(false);
	m_structuredClassifier_Attribute_ownedAttribute->setOrdered(true);
	m_structuredClassifier_Attribute_ownedAttribute->setContainment(true);
	m_structuredClassifier_Attribute_ownedAttribute->setResolveProxies(true);
	m_structuredClassifier_Attribute_ownedAttribute->setDefaultValueLiteral("");	
	
	m_structuredClassifier_Attribute_ownedAttribute->_setID(STRUCTUREDCLASSIFIER_ATTRIBUTE_OWNEDATTRIBUTE);
	m_structuredClassifier_Attribute_ownedConnector->setName("ownedConnector");
	m_structuredClassifier_Attribute_ownedConnector->setEType(getConnector_Class());
	m_structuredClassifier_Attribute_ownedConnector->setLowerBound(0);
	m_structuredClassifier_Attribute_ownedConnector->setUpperBound(-1);
	m_structuredClassifier_Attribute_ownedConnector->setTransient(false);
	m_structuredClassifier_Attribute_ownedConnector->setVolatile(false);
	m_structuredClassifier_Attribute_ownedConnector->setChangeable(true);
	m_structuredClassifier_Attribute_ownedConnector->setUnsettable(false);
	m_structuredClassifier_Attribute_ownedConnector->setUnique(true);
	m_structuredClassifier_Attribute_ownedConnector->setDerived(false);
	m_structuredClassifier_Attribute_ownedConnector->setOrdered(false);
	m_structuredClassifier_Attribute_ownedConnector->setContainment(true);
	m_structuredClassifier_Attribute_ownedConnector->setResolveProxies(true);
	m_structuredClassifier_Attribute_ownedConnector->setDefaultValueLiteral("");	
	m_structuredClassifier_Attribute_ownedConnector->setEOpposite(uml::umlPackage::eInstance()->getConnector_Attribute_structuredClassifier());
	
	m_structuredClassifier_Attribute_ownedConnector->_setID(STRUCTUREDCLASSIFIER_ATTRIBUTE_OWNEDCONNECTOR);
	m_structuredClassifier_Attribute_part->setName("part");
	m_structuredClassifier_Attribute_part->setEType(getProperty_Class());
	m_structuredClassifier_Attribute_part->setLowerBound(0);
	m_structuredClassifier_Attribute_part->setUpperBound(-1);
	m_structuredClassifier_Attribute_part->setTransient(true);
	m_structuredClassifier_Attribute_part->setVolatile(true);
	m_structuredClassifier_Attribute_part->setChangeable(false);
	m_structuredClassifier_Attribute_part->setUnsettable(false);
	m_structuredClassifier_Attribute_part->setUnique(true);
	m_structuredClassifier_Attribute_part->setDerived(true);
	m_structuredClassifier_Attribute_part->setOrdered(false);
	m_structuredClassifier_Attribute_part->setContainment(false);
	m_structuredClassifier_Attribute_part->setResolveProxies(true);
	m_structuredClassifier_Attribute_part->setDefaultValueLiteral("");	
	
	m_structuredClassifier_Attribute_part->_setID(STRUCTUREDCLASSIFIER_ATTRIBUTE_PART);
	m_structuredClassifier_Attribute_role->setName("role");
	m_structuredClassifier_Attribute_role->setEType(getConnectableElement_Class());
	m_structuredClassifier_Attribute_role->setLowerBound(0);
	m_structuredClassifier_Attribute_role->setUpperBound(-1);
	m_structuredClassifier_Attribute_role->setTransient(true);
	m_structuredClassifier_Attribute_role->setVolatile(true);
	m_structuredClassifier_Attribute_role->setChangeable(false);
	m_structuredClassifier_Attribute_role->setUnsettable(false);
	m_structuredClassifier_Attribute_role->setUnique(true);
	m_structuredClassifier_Attribute_role->setDerived(true);
	m_structuredClassifier_Attribute_role->setOrdered(false);
	m_structuredClassifier_Attribute_role->setContainment(false);
	m_structuredClassifier_Attribute_role->setResolveProxies(true);
	m_structuredClassifier_Attribute_role->setDefaultValueLiteral("");	
	
	m_structuredClassifier_Attribute_role->_setID(STRUCTUREDCLASSIFIER_ATTRIBUTE_ROLE);
	
	/*
	 * EOperations
	 */
	m_structuredClassifier_Operation_allRoles->setName("allRoles");
	m_structuredClassifier_Operation_allRoles->setEType(getConnectableElement_Class());
	m_structuredClassifier_Operation_allRoles->setLowerBound(0);
	m_structuredClassifier_Operation_allRoles->setUpperBound(-1);
	m_structuredClassifier_Operation_allRoles->setUnique(true);
	m_structuredClassifier_Operation_allRoles->setOrdered(false);
	
	m_structuredClassifier_Operation_allRoles->_setID(STRUCTUREDCLASSIFIER_OPERATION_ALLROLES);
	
	
	m_structuredClassifier_Operation_createOwnedAttribute_String_UnlimitedNatural->setName("createOwnedAttribute");
	m_structuredClassifier_Operation_createOwnedAttribute_String_UnlimitedNatural->setEType(getProperty_Class());
	m_structuredClassifier_Operation_createOwnedAttribute_String_UnlimitedNatural->setLowerBound(1);
	m_structuredClassifier_Operation_createOwnedAttribute_String_UnlimitedNatural->setUpperBound(1);
	m_structuredClassifier_Operation_createOwnedAttribute_String_UnlimitedNatural->setUnique(true);
	m_structuredClassifier_Operation_createOwnedAttribute_String_UnlimitedNatural->setOrdered(false);
	
	m_structuredClassifier_Operation_createOwnedAttribute_String_UnlimitedNatural->_setID(STRUCTUREDCLASSIFIER_OPERATION_CREATEOWNEDATTRIBUTE_STRING_UNLIMITEDNATURAL);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuredClassifier_Operation_createOwnedAttribute_String_UnlimitedNatural);
		parameter->setName("name");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuredClassifier_Operation_createOwnedAttribute_String_UnlimitedNatural);
		parameter->setName("type");
		parameter->setEType(getType_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuredClassifier_Operation_createOwnedAttribute_String_UnlimitedNatural);
		parameter->setName("lower");
		parameter->setEType(types::typesPackage::eInstance()->getInteger_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_structuredClassifier_Operation_createOwnedAttribute_String_UnlimitedNatural);
		parameter->setName("upper");
		parameter->setEType(types::typesPackage::eInstance()->getUnlimitedNatural_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_structuredClassifier_Operation_getParts->setName("getParts");
	m_structuredClassifier_Operation_getParts->setEType(getProperty_Class());
	m_structuredClassifier_Operation_getParts->setLowerBound(0);
	m_structuredClassifier_Operation_getParts->setUpperBound(-1);
	m_structuredClassifier_Operation_getParts->setUnique(true);
	m_structuredClassifier_Operation_getParts->setOrdered(false);
	
	m_structuredClassifier_Operation_getParts->_setID(STRUCTUREDCLASSIFIER_OPERATION_GETPARTS);
	
	
	
}

void umlPackageImpl::initializeSubstitutionContent()
{
	m_substitution_Class->setName("Substitution");
	m_substitution_Class->setAbstract(false);
	m_substitution_Class->setInterface(false);
	
	m_substitution_Class->_setID(SUBSTITUTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_substitution_Attribute_contract->setName("contract");
	m_substitution_Attribute_contract->setEType(getClassifier_Class());
	m_substitution_Attribute_contract->setLowerBound(1);
	m_substitution_Attribute_contract->setUpperBound(1);
	m_substitution_Attribute_contract->setTransient(false);
	m_substitution_Attribute_contract->setVolatile(false);
	m_substitution_Attribute_contract->setChangeable(true);
	m_substitution_Attribute_contract->setUnsettable(false);
	m_substitution_Attribute_contract->setUnique(true);
	m_substitution_Attribute_contract->setDerived(false);
	m_substitution_Attribute_contract->setOrdered(false);
	m_substitution_Attribute_contract->setContainment(false);
	m_substitution_Attribute_contract->setResolveProxies(true);
	m_substitution_Attribute_contract->setDefaultValueLiteral("");	
	
	m_substitution_Attribute_contract->_setID(SUBSTITUTION_ATTRIBUTE_CONTRACT);
	m_substitution_Attribute_substitutingClassifier->setName("substitutingClassifier");
	m_substitution_Attribute_substitutingClassifier->setEType(getClassifier_Class());
	m_substitution_Attribute_substitutingClassifier->setLowerBound(1);
	m_substitution_Attribute_substitutingClassifier->setUpperBound(1);
	m_substitution_Attribute_substitutingClassifier->setTransient(false);
	m_substitution_Attribute_substitutingClassifier->setVolatile(false);
	m_substitution_Attribute_substitutingClassifier->setChangeable(true);
	m_substitution_Attribute_substitutingClassifier->setUnsettable(false);
	m_substitution_Attribute_substitutingClassifier->setUnique(true);
	m_substitution_Attribute_substitutingClassifier->setDerived(false);
	m_substitution_Attribute_substitutingClassifier->setOrdered(false);
	m_substitution_Attribute_substitutingClassifier->setContainment(false);
	m_substitution_Attribute_substitutingClassifier->setResolveProxies(true);
	m_substitution_Attribute_substitutingClassifier->setDefaultValueLiteral("");	
	m_substitution_Attribute_substitutingClassifier->setEOpposite(uml::umlPackage::eInstance()->getClassifier_Attribute_substitution());
	
	m_substitution_Attribute_substitutingClassifier->_setID(SUBSTITUTION_ATTRIBUTE_SUBSTITUTINGCLASSIFIER);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeTemplateBindingContent()
{
	m_templateBinding_Class->setName("TemplateBinding");
	m_templateBinding_Class->setAbstract(false);
	m_templateBinding_Class->setInterface(false);
	
	m_templateBinding_Class->_setID(TEMPLATEBINDING_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_templateBinding_Attribute_boundElement->setName("boundElement");
	m_templateBinding_Attribute_boundElement->setEType(getTemplateableElement_Class());
	m_templateBinding_Attribute_boundElement->setLowerBound(1);
	m_templateBinding_Attribute_boundElement->setUpperBound(1);
	m_templateBinding_Attribute_boundElement->setTransient(false);
	m_templateBinding_Attribute_boundElement->setVolatile(false);
	m_templateBinding_Attribute_boundElement->setChangeable(true);
	m_templateBinding_Attribute_boundElement->setUnsettable(false);
	m_templateBinding_Attribute_boundElement->setUnique(true);
	m_templateBinding_Attribute_boundElement->setDerived(false);
	m_templateBinding_Attribute_boundElement->setOrdered(false);
	m_templateBinding_Attribute_boundElement->setContainment(false);
	m_templateBinding_Attribute_boundElement->setResolveProxies(true);
	m_templateBinding_Attribute_boundElement->setDefaultValueLiteral("");	
	m_templateBinding_Attribute_boundElement->setEOpposite(uml::umlPackage::eInstance()->getTemplateableElement_Attribute_templateBinding());
	
	m_templateBinding_Attribute_boundElement->_setID(TEMPLATEBINDING_ATTRIBUTE_BOUNDELEMENT);
	m_templateBinding_Attribute_parameterSubstitution->setName("parameterSubstitution");
	m_templateBinding_Attribute_parameterSubstitution->setEType(getTemplateParameterSubstitution_Class());
	m_templateBinding_Attribute_parameterSubstitution->setLowerBound(0);
	m_templateBinding_Attribute_parameterSubstitution->setUpperBound(-1);
	m_templateBinding_Attribute_parameterSubstitution->setTransient(false);
	m_templateBinding_Attribute_parameterSubstitution->setVolatile(false);
	m_templateBinding_Attribute_parameterSubstitution->setChangeable(true);
	m_templateBinding_Attribute_parameterSubstitution->setUnsettable(false);
	m_templateBinding_Attribute_parameterSubstitution->setUnique(true);
	m_templateBinding_Attribute_parameterSubstitution->setDerived(false);
	m_templateBinding_Attribute_parameterSubstitution->setOrdered(false);
	m_templateBinding_Attribute_parameterSubstitution->setContainment(true);
	m_templateBinding_Attribute_parameterSubstitution->setResolveProxies(true);
	m_templateBinding_Attribute_parameterSubstitution->setDefaultValueLiteral("");	
	m_templateBinding_Attribute_parameterSubstitution->setEOpposite(uml::umlPackage::eInstance()->getTemplateParameterSubstitution_Attribute_templateBinding());
	
	m_templateBinding_Attribute_parameterSubstitution->_setID(TEMPLATEBINDING_ATTRIBUTE_PARAMETERSUBSTITUTION);
	m_templateBinding_Attribute_signature->setName("signature");
	m_templateBinding_Attribute_signature->setEType(getTemplateSignature_Class());
	m_templateBinding_Attribute_signature->setLowerBound(1);
	m_templateBinding_Attribute_signature->setUpperBound(1);
	m_templateBinding_Attribute_signature->setTransient(false);
	m_templateBinding_Attribute_signature->setVolatile(false);
	m_templateBinding_Attribute_signature->setChangeable(true);
	m_templateBinding_Attribute_signature->setUnsettable(false);
	m_templateBinding_Attribute_signature->setUnique(true);
	m_templateBinding_Attribute_signature->setDerived(false);
	m_templateBinding_Attribute_signature->setOrdered(false);
	m_templateBinding_Attribute_signature->setContainment(false);
	m_templateBinding_Attribute_signature->setResolveProxies(true);
	m_templateBinding_Attribute_signature->setDefaultValueLiteral("");	
	
	m_templateBinding_Attribute_signature->_setID(TEMPLATEBINDING_ATTRIBUTE_SIGNATURE);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeTemplateParameterContent()
{
	m_templateParameter_Class->setName("TemplateParameter");
	m_templateParameter_Class->setAbstract(false);
	m_templateParameter_Class->setInterface(false);
	
	m_templateParameter_Class->_setID(TEMPLATEPARAMETER_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_templateParameter_Attribute_default->setName("default");
	m_templateParameter_Attribute_default->setEType(getParameterableElement_Class());
	m_templateParameter_Attribute_default->setLowerBound(0);
	m_templateParameter_Attribute_default->setUpperBound(1);
	m_templateParameter_Attribute_default->setTransient(false);
	m_templateParameter_Attribute_default->setVolatile(false);
	m_templateParameter_Attribute_default->setChangeable(true);
	m_templateParameter_Attribute_default->setUnsettable(false);
	m_templateParameter_Attribute_default->setUnique(true);
	m_templateParameter_Attribute_default->setDerived(false);
	m_templateParameter_Attribute_default->setOrdered(false);
	m_templateParameter_Attribute_default->setContainment(false);
	m_templateParameter_Attribute_default->setResolveProxies(true);
	m_templateParameter_Attribute_default->setDefaultValueLiteral("");	
	
	m_templateParameter_Attribute_default->_setID(TEMPLATEPARAMETER_ATTRIBUTE_DEFAULT);
	m_templateParameter_Attribute_ownedDefault->setName("ownedDefault");
	m_templateParameter_Attribute_ownedDefault->setEType(getParameterableElement_Class());
	m_templateParameter_Attribute_ownedDefault->setLowerBound(0);
	m_templateParameter_Attribute_ownedDefault->setUpperBound(1);
	m_templateParameter_Attribute_ownedDefault->setTransient(false);
	m_templateParameter_Attribute_ownedDefault->setVolatile(false);
	m_templateParameter_Attribute_ownedDefault->setChangeable(true);
	m_templateParameter_Attribute_ownedDefault->setUnsettable(false);
	m_templateParameter_Attribute_ownedDefault->setUnique(true);
	m_templateParameter_Attribute_ownedDefault->setDerived(false);
	m_templateParameter_Attribute_ownedDefault->setOrdered(false);
	m_templateParameter_Attribute_ownedDefault->setContainment(true);
	m_templateParameter_Attribute_ownedDefault->setResolveProxies(true);
	m_templateParameter_Attribute_ownedDefault->setDefaultValueLiteral("");	
	
	m_templateParameter_Attribute_ownedDefault->_setID(TEMPLATEPARAMETER_ATTRIBUTE_OWNEDDEFAULT);
	m_templateParameter_Attribute_ownedParameteredElement->setName("ownedParameteredElement");
	m_templateParameter_Attribute_ownedParameteredElement->setEType(getParameterableElement_Class());
	m_templateParameter_Attribute_ownedParameteredElement->setLowerBound(0);
	m_templateParameter_Attribute_ownedParameteredElement->setUpperBound(1);
	m_templateParameter_Attribute_ownedParameteredElement->setTransient(false);
	m_templateParameter_Attribute_ownedParameteredElement->setVolatile(false);
	m_templateParameter_Attribute_ownedParameteredElement->setChangeable(true);
	m_templateParameter_Attribute_ownedParameteredElement->setUnsettable(false);
	m_templateParameter_Attribute_ownedParameteredElement->setUnique(true);
	m_templateParameter_Attribute_ownedParameteredElement->setDerived(false);
	m_templateParameter_Attribute_ownedParameteredElement->setOrdered(false);
	m_templateParameter_Attribute_ownedParameteredElement->setContainment(true);
	m_templateParameter_Attribute_ownedParameteredElement->setResolveProxies(true);
	m_templateParameter_Attribute_ownedParameteredElement->setDefaultValueLiteral("");	
	m_templateParameter_Attribute_ownedParameteredElement->setEOpposite(uml::umlPackage::eInstance()->getParameterableElement_Attribute_owningTemplateParameter());
	
	m_templateParameter_Attribute_ownedParameteredElement->_setID(TEMPLATEPARAMETER_ATTRIBUTE_OWNEDPARAMETEREDELEMENT);
	m_templateParameter_Attribute_parameteredElement->setName("parameteredElement");
	m_templateParameter_Attribute_parameteredElement->setEType(getParameterableElement_Class());
	m_templateParameter_Attribute_parameteredElement->setLowerBound(1);
	m_templateParameter_Attribute_parameteredElement->setUpperBound(1);
	m_templateParameter_Attribute_parameteredElement->setTransient(false);
	m_templateParameter_Attribute_parameteredElement->setVolatile(false);
	m_templateParameter_Attribute_parameteredElement->setChangeable(true);
	m_templateParameter_Attribute_parameteredElement->setUnsettable(false);
	m_templateParameter_Attribute_parameteredElement->setUnique(true);
	m_templateParameter_Attribute_parameteredElement->setDerived(false);
	m_templateParameter_Attribute_parameteredElement->setOrdered(false);
	m_templateParameter_Attribute_parameteredElement->setContainment(false);
	m_templateParameter_Attribute_parameteredElement->setResolveProxies(true);
	m_templateParameter_Attribute_parameteredElement->setDefaultValueLiteral("");	
	m_templateParameter_Attribute_parameteredElement->setEOpposite(uml::umlPackage::eInstance()->getParameterableElement_Attribute_templateParameter());
	
	m_templateParameter_Attribute_parameteredElement->_setID(TEMPLATEPARAMETER_ATTRIBUTE_PARAMETEREDELEMENT);
	m_templateParameter_Attribute_signature->setName("signature");
	m_templateParameter_Attribute_signature->setEType(getTemplateSignature_Class());
	m_templateParameter_Attribute_signature->setLowerBound(1);
	m_templateParameter_Attribute_signature->setUpperBound(1);
	m_templateParameter_Attribute_signature->setTransient(false);
	m_templateParameter_Attribute_signature->setVolatile(false);
	m_templateParameter_Attribute_signature->setChangeable(true);
	m_templateParameter_Attribute_signature->setUnsettable(false);
	m_templateParameter_Attribute_signature->setUnique(true);
	m_templateParameter_Attribute_signature->setDerived(false);
	m_templateParameter_Attribute_signature->setOrdered(false);
	m_templateParameter_Attribute_signature->setContainment(false);
	m_templateParameter_Attribute_signature->setResolveProxies(true);
	m_templateParameter_Attribute_signature->setDefaultValueLiteral("");	
	m_templateParameter_Attribute_signature->setEOpposite(uml::umlPackage::eInstance()->getTemplateSignature_Attribute_ownedParameter());
	
	m_templateParameter_Attribute_signature->_setID(TEMPLATEPARAMETER_ATTRIBUTE_SIGNATURE);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeTemplateParameterSubstitutionContent()
{
	m_templateParameterSubstitution_Class->setName("TemplateParameterSubstitution");
	m_templateParameterSubstitution_Class->setAbstract(false);
	m_templateParameterSubstitution_Class->setInterface(false);
	
	m_templateParameterSubstitution_Class->_setID(TEMPLATEPARAMETERSUBSTITUTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_templateParameterSubstitution_Attribute_actual->setName("actual");
	m_templateParameterSubstitution_Attribute_actual->setEType(getParameterableElement_Class());
	m_templateParameterSubstitution_Attribute_actual->setLowerBound(1);
	m_templateParameterSubstitution_Attribute_actual->setUpperBound(1);
	m_templateParameterSubstitution_Attribute_actual->setTransient(false);
	m_templateParameterSubstitution_Attribute_actual->setVolatile(false);
	m_templateParameterSubstitution_Attribute_actual->setChangeable(true);
	m_templateParameterSubstitution_Attribute_actual->setUnsettable(false);
	m_templateParameterSubstitution_Attribute_actual->setUnique(true);
	m_templateParameterSubstitution_Attribute_actual->setDerived(false);
	m_templateParameterSubstitution_Attribute_actual->setOrdered(false);
	m_templateParameterSubstitution_Attribute_actual->setContainment(false);
	m_templateParameterSubstitution_Attribute_actual->setResolveProxies(true);
	m_templateParameterSubstitution_Attribute_actual->setDefaultValueLiteral("");	
	
	m_templateParameterSubstitution_Attribute_actual->_setID(TEMPLATEPARAMETERSUBSTITUTION_ATTRIBUTE_ACTUAL);
	m_templateParameterSubstitution_Attribute_formal->setName("formal");
	m_templateParameterSubstitution_Attribute_formal->setEType(getTemplateParameter_Class());
	m_templateParameterSubstitution_Attribute_formal->setLowerBound(1);
	m_templateParameterSubstitution_Attribute_formal->setUpperBound(1);
	m_templateParameterSubstitution_Attribute_formal->setTransient(false);
	m_templateParameterSubstitution_Attribute_formal->setVolatile(false);
	m_templateParameterSubstitution_Attribute_formal->setChangeable(true);
	m_templateParameterSubstitution_Attribute_formal->setUnsettable(false);
	m_templateParameterSubstitution_Attribute_formal->setUnique(true);
	m_templateParameterSubstitution_Attribute_formal->setDerived(false);
	m_templateParameterSubstitution_Attribute_formal->setOrdered(false);
	m_templateParameterSubstitution_Attribute_formal->setContainment(false);
	m_templateParameterSubstitution_Attribute_formal->setResolveProxies(true);
	m_templateParameterSubstitution_Attribute_formal->setDefaultValueLiteral("");	
	
	m_templateParameterSubstitution_Attribute_formal->_setID(TEMPLATEPARAMETERSUBSTITUTION_ATTRIBUTE_FORMAL);
	m_templateParameterSubstitution_Attribute_ownedActual->setName("ownedActual");
	m_templateParameterSubstitution_Attribute_ownedActual->setEType(getParameterableElement_Class());
	m_templateParameterSubstitution_Attribute_ownedActual->setLowerBound(0);
	m_templateParameterSubstitution_Attribute_ownedActual->setUpperBound(1);
	m_templateParameterSubstitution_Attribute_ownedActual->setTransient(false);
	m_templateParameterSubstitution_Attribute_ownedActual->setVolatile(false);
	m_templateParameterSubstitution_Attribute_ownedActual->setChangeable(true);
	m_templateParameterSubstitution_Attribute_ownedActual->setUnsettable(false);
	m_templateParameterSubstitution_Attribute_ownedActual->setUnique(true);
	m_templateParameterSubstitution_Attribute_ownedActual->setDerived(false);
	m_templateParameterSubstitution_Attribute_ownedActual->setOrdered(false);
	m_templateParameterSubstitution_Attribute_ownedActual->setContainment(true);
	m_templateParameterSubstitution_Attribute_ownedActual->setResolveProxies(true);
	m_templateParameterSubstitution_Attribute_ownedActual->setDefaultValueLiteral("");	
	
	m_templateParameterSubstitution_Attribute_ownedActual->_setID(TEMPLATEPARAMETERSUBSTITUTION_ATTRIBUTE_OWNEDACTUAL);
	m_templateParameterSubstitution_Attribute_templateBinding->setName("templateBinding");
	m_templateParameterSubstitution_Attribute_templateBinding->setEType(getTemplateBinding_Class());
	m_templateParameterSubstitution_Attribute_templateBinding->setLowerBound(1);
	m_templateParameterSubstitution_Attribute_templateBinding->setUpperBound(1);
	m_templateParameterSubstitution_Attribute_templateBinding->setTransient(false);
	m_templateParameterSubstitution_Attribute_templateBinding->setVolatile(false);
	m_templateParameterSubstitution_Attribute_templateBinding->setChangeable(true);
	m_templateParameterSubstitution_Attribute_templateBinding->setUnsettable(false);
	m_templateParameterSubstitution_Attribute_templateBinding->setUnique(true);
	m_templateParameterSubstitution_Attribute_templateBinding->setDerived(false);
	m_templateParameterSubstitution_Attribute_templateBinding->setOrdered(false);
	m_templateParameterSubstitution_Attribute_templateBinding->setContainment(false);
	m_templateParameterSubstitution_Attribute_templateBinding->setResolveProxies(true);
	m_templateParameterSubstitution_Attribute_templateBinding->setDefaultValueLiteral("");	
	m_templateParameterSubstitution_Attribute_templateBinding->setEOpposite(uml::umlPackage::eInstance()->getTemplateBinding_Attribute_parameterSubstitution());
	
	m_templateParameterSubstitution_Attribute_templateBinding->_setID(TEMPLATEPARAMETERSUBSTITUTION_ATTRIBUTE_TEMPLATEBINDING);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeTemplateSignatureContent()
{
	m_templateSignature_Class->setName("TemplateSignature");
	m_templateSignature_Class->setAbstract(false);
	m_templateSignature_Class->setInterface(false);
	
	m_templateSignature_Class->_setID(TEMPLATESIGNATURE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_templateSignature_Attribute_ownedParameter->setName("ownedParameter");
	m_templateSignature_Attribute_ownedParameter->setEType(getTemplateParameter_Class());
	m_templateSignature_Attribute_ownedParameter->setLowerBound(0);
	m_templateSignature_Attribute_ownedParameter->setUpperBound(-1);
	m_templateSignature_Attribute_ownedParameter->setTransient(false);
	m_templateSignature_Attribute_ownedParameter->setVolatile(false);
	m_templateSignature_Attribute_ownedParameter->setChangeable(true);
	m_templateSignature_Attribute_ownedParameter->setUnsettable(false);
	m_templateSignature_Attribute_ownedParameter->setUnique(true);
	m_templateSignature_Attribute_ownedParameter->setDerived(false);
	m_templateSignature_Attribute_ownedParameter->setOrdered(true);
	m_templateSignature_Attribute_ownedParameter->setContainment(true);
	m_templateSignature_Attribute_ownedParameter->setResolveProxies(true);
	m_templateSignature_Attribute_ownedParameter->setDefaultValueLiteral("");	
	m_templateSignature_Attribute_ownedParameter->setEOpposite(uml::umlPackage::eInstance()->getTemplateParameter_Attribute_signature());
	
	m_templateSignature_Attribute_ownedParameter->_setID(TEMPLATESIGNATURE_ATTRIBUTE_OWNEDPARAMETER);
	m_templateSignature_Attribute_parameter->setName("parameter");
	m_templateSignature_Attribute_parameter->setEType(getTemplateParameter_Class());
	m_templateSignature_Attribute_parameter->setLowerBound(1);
	m_templateSignature_Attribute_parameter->setUpperBound(-1);
	m_templateSignature_Attribute_parameter->setTransient(false);
	m_templateSignature_Attribute_parameter->setVolatile(false);
	m_templateSignature_Attribute_parameter->setChangeable(true);
	m_templateSignature_Attribute_parameter->setUnsettable(false);
	m_templateSignature_Attribute_parameter->setUnique(true);
	m_templateSignature_Attribute_parameter->setDerived(false);
	m_templateSignature_Attribute_parameter->setOrdered(true);
	m_templateSignature_Attribute_parameter->setContainment(false);
	m_templateSignature_Attribute_parameter->setResolveProxies(true);
	m_templateSignature_Attribute_parameter->setDefaultValueLiteral("");	
	
	m_templateSignature_Attribute_parameter->_setID(TEMPLATESIGNATURE_ATTRIBUTE_PARAMETER);
	m_templateSignature_Attribute_template->setName("template");
	m_templateSignature_Attribute_template->setEType(getTemplateableElement_Class());
	m_templateSignature_Attribute_template->setLowerBound(1);
	m_templateSignature_Attribute_template->setUpperBound(1);
	m_templateSignature_Attribute_template->setTransient(false);
	m_templateSignature_Attribute_template->setVolatile(false);
	m_templateSignature_Attribute_template->setChangeable(true);
	m_templateSignature_Attribute_template->setUnsettable(false);
	m_templateSignature_Attribute_template->setUnique(true);
	m_templateSignature_Attribute_template->setDerived(false);
	m_templateSignature_Attribute_template->setOrdered(false);
	m_templateSignature_Attribute_template->setContainment(false);
	m_templateSignature_Attribute_template->setResolveProxies(true);
	m_templateSignature_Attribute_template->setDefaultValueLiteral("");	
	m_templateSignature_Attribute_template->setEOpposite(uml::umlPackage::eInstance()->getTemplateableElement_Attribute_ownedTemplateSignature());
	
	m_templateSignature_Attribute_template->_setID(TEMPLATESIGNATURE_ATTRIBUTE_TEMPLATE);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeTemplateableElementContent()
{
	m_templateableElement_Class->setName("TemplateableElement");
	m_templateableElement_Class->setAbstract(true);
	m_templateableElement_Class->setInterface(false);
	
	m_templateableElement_Class->_setID(TEMPLATEABLEELEMENT_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_templateableElement_Attribute_ownedTemplateSignature->setName("ownedTemplateSignature");
	m_templateableElement_Attribute_ownedTemplateSignature->setEType(getTemplateSignature_Class());
	m_templateableElement_Attribute_ownedTemplateSignature->setLowerBound(0);
	m_templateableElement_Attribute_ownedTemplateSignature->setUpperBound(1);
	m_templateableElement_Attribute_ownedTemplateSignature->setTransient(false);
	m_templateableElement_Attribute_ownedTemplateSignature->setVolatile(false);
	m_templateableElement_Attribute_ownedTemplateSignature->setChangeable(true);
	m_templateableElement_Attribute_ownedTemplateSignature->setUnsettable(false);
	m_templateableElement_Attribute_ownedTemplateSignature->setUnique(true);
	m_templateableElement_Attribute_ownedTemplateSignature->setDerived(false);
	m_templateableElement_Attribute_ownedTemplateSignature->setOrdered(false);
	m_templateableElement_Attribute_ownedTemplateSignature->setContainment(true);
	m_templateableElement_Attribute_ownedTemplateSignature->setResolveProxies(true);
	m_templateableElement_Attribute_ownedTemplateSignature->setDefaultValueLiteral("");	
	m_templateableElement_Attribute_ownedTemplateSignature->setEOpposite(uml::umlPackage::eInstance()->getTemplateSignature_Attribute_template());
	
	m_templateableElement_Attribute_ownedTemplateSignature->_setID(TEMPLATEABLEELEMENT_ATTRIBUTE_OWNEDTEMPLATESIGNATURE);
	m_templateableElement_Attribute_templateBinding->setName("templateBinding");
	m_templateableElement_Attribute_templateBinding->setEType(getTemplateBinding_Class());
	m_templateableElement_Attribute_templateBinding->setLowerBound(0);
	m_templateableElement_Attribute_templateBinding->setUpperBound(-1);
	m_templateableElement_Attribute_templateBinding->setTransient(false);
	m_templateableElement_Attribute_templateBinding->setVolatile(false);
	m_templateableElement_Attribute_templateBinding->setChangeable(true);
	m_templateableElement_Attribute_templateBinding->setUnsettable(false);
	m_templateableElement_Attribute_templateBinding->setUnique(true);
	m_templateableElement_Attribute_templateBinding->setDerived(false);
	m_templateableElement_Attribute_templateBinding->setOrdered(false);
	m_templateableElement_Attribute_templateBinding->setContainment(true);
	m_templateableElement_Attribute_templateBinding->setResolveProxies(true);
	m_templateableElement_Attribute_templateBinding->setDefaultValueLiteral("");	
	m_templateableElement_Attribute_templateBinding->setEOpposite(uml::umlPackage::eInstance()->getTemplateBinding_Attribute_boundElement());
	
	m_templateableElement_Attribute_templateBinding->_setID(TEMPLATEABLEELEMENT_ATTRIBUTE_TEMPLATEBINDING);
	
	/*
	 * EOperations
	 */
	m_templateableElement_Operation_isTemplate->setName("isTemplate");
	m_templateableElement_Operation_isTemplate->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_templateableElement_Operation_isTemplate->setLowerBound(1);
	m_templateableElement_Operation_isTemplate->setUpperBound(1);
	m_templateableElement_Operation_isTemplate->setUnique(true);
	m_templateableElement_Operation_isTemplate->setOrdered(false);
	
	m_templateableElement_Operation_isTemplate->_setID(TEMPLATEABLEELEMENT_OPERATION_ISTEMPLATE);
	
	
	m_templateableElement_Operation_parameterableElements->setName("parameterableElements");
	m_templateableElement_Operation_parameterableElements->setEType(getParameterableElement_Class());
	m_templateableElement_Operation_parameterableElements->setLowerBound(0);
	m_templateableElement_Operation_parameterableElements->setUpperBound(-1);
	m_templateableElement_Operation_parameterableElements->setUnique(true);
	m_templateableElement_Operation_parameterableElements->setOrdered(false);
	
	m_templateableElement_Operation_parameterableElements->_setID(TEMPLATEABLEELEMENT_OPERATION_PARAMETERABLEELEMENTS);
	
	
	
}

void umlPackageImpl::initializeTestIdentityActionContent()
{
	m_testIdentityAction_Class->setName("TestIdentityAction");
	m_testIdentityAction_Class->setAbstract(false);
	m_testIdentityAction_Class->setInterface(false);
	
	m_testIdentityAction_Class->_setID(TESTIDENTITYACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_testIdentityAction_Attribute_first->setName("first");
	m_testIdentityAction_Attribute_first->setEType(getInputPin_Class());
	m_testIdentityAction_Attribute_first->setLowerBound(1);
	m_testIdentityAction_Attribute_first->setUpperBound(1);
	m_testIdentityAction_Attribute_first->setTransient(false);
	m_testIdentityAction_Attribute_first->setVolatile(false);
	m_testIdentityAction_Attribute_first->setChangeable(true);
	m_testIdentityAction_Attribute_first->setUnsettable(false);
	m_testIdentityAction_Attribute_first->setUnique(true);
	m_testIdentityAction_Attribute_first->setDerived(false);
	m_testIdentityAction_Attribute_first->setOrdered(false);
	m_testIdentityAction_Attribute_first->setContainment(true);
	m_testIdentityAction_Attribute_first->setResolveProxies(true);
	m_testIdentityAction_Attribute_first->setDefaultValueLiteral("");	
	
	m_testIdentityAction_Attribute_first->_setID(TESTIDENTITYACTION_ATTRIBUTE_FIRST);
	m_testIdentityAction_Attribute_result->setName("result");
	m_testIdentityAction_Attribute_result->setEType(getOutputPin_Class());
	m_testIdentityAction_Attribute_result->setLowerBound(1);
	m_testIdentityAction_Attribute_result->setUpperBound(1);
	m_testIdentityAction_Attribute_result->setTransient(false);
	m_testIdentityAction_Attribute_result->setVolatile(false);
	m_testIdentityAction_Attribute_result->setChangeable(true);
	m_testIdentityAction_Attribute_result->setUnsettable(false);
	m_testIdentityAction_Attribute_result->setUnique(true);
	m_testIdentityAction_Attribute_result->setDerived(false);
	m_testIdentityAction_Attribute_result->setOrdered(false);
	m_testIdentityAction_Attribute_result->setContainment(true);
	m_testIdentityAction_Attribute_result->setResolveProxies(true);
	m_testIdentityAction_Attribute_result->setDefaultValueLiteral("");	
	
	m_testIdentityAction_Attribute_result->_setID(TESTIDENTITYACTION_ATTRIBUTE_RESULT);
	m_testIdentityAction_Attribute_second->setName("second");
	m_testIdentityAction_Attribute_second->setEType(getInputPin_Class());
	m_testIdentityAction_Attribute_second->setLowerBound(1);
	m_testIdentityAction_Attribute_second->setUpperBound(1);
	m_testIdentityAction_Attribute_second->setTransient(false);
	m_testIdentityAction_Attribute_second->setVolatile(false);
	m_testIdentityAction_Attribute_second->setChangeable(true);
	m_testIdentityAction_Attribute_second->setUnsettable(false);
	m_testIdentityAction_Attribute_second->setUnique(true);
	m_testIdentityAction_Attribute_second->setDerived(false);
	m_testIdentityAction_Attribute_second->setOrdered(false);
	m_testIdentityAction_Attribute_second->setContainment(true);
	m_testIdentityAction_Attribute_second->setResolveProxies(true);
	m_testIdentityAction_Attribute_second->setDefaultValueLiteral("");	
	
	m_testIdentityAction_Attribute_second->_setID(TESTIDENTITYACTION_ATTRIBUTE_SECOND);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeTimeConstraintContent()
{
	m_timeConstraint_Class->setName("TimeConstraint");
	m_timeConstraint_Class->setAbstract(false);
	m_timeConstraint_Class->setInterface(false);
	
	m_timeConstraint_Class->_setID(TIMECONSTRAINT_CLASS);
	
	/*
	 * EAttributes
	 */
	m_timeConstraint_Attribute_firstEvent = getTimeConstraint_Attribute_firstEvent();
	m_timeConstraint_Attribute_firstEvent->setName("firstEvent");
	m_timeConstraint_Attribute_firstEvent->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_timeConstraint_Attribute_firstEvent->setLowerBound(0);
	m_timeConstraint_Attribute_firstEvent->setUpperBound(1);
	m_timeConstraint_Attribute_firstEvent->setTransient(false);
	m_timeConstraint_Attribute_firstEvent->setVolatile(false);
	m_timeConstraint_Attribute_firstEvent->setChangeable(true);
	m_timeConstraint_Attribute_firstEvent->setUnsettable(false);
	m_timeConstraint_Attribute_firstEvent->setUnique(true);
	m_timeConstraint_Attribute_firstEvent->setDerived(false);
	m_timeConstraint_Attribute_firstEvent->setOrdered(false);
	m_timeConstraint_Attribute_firstEvent->setID(false);
	m_timeConstraint_Attribute_firstEvent->setDefaultValueLiteral("true");
	
	m_timeConstraint_Attribute_firstEvent->_setID(TIMECONSTRAINT_ATTRIBUTE_FIRSTEVENT);
	
	/*
	 * EReferences
	 */
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeTimeEventContent()
{
	m_timeEvent_Class->setName("TimeEvent");
	m_timeEvent_Class->setAbstract(false);
	m_timeEvent_Class->setInterface(false);
	
	m_timeEvent_Class->_setID(TIMEEVENT_CLASS);
	
	/*
	 * EAttributes
	 */
	m_timeEvent_Attribute_isRelative = getTimeEvent_Attribute_isRelative();
	m_timeEvent_Attribute_isRelative->setName("isRelative");
	m_timeEvent_Attribute_isRelative->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_timeEvent_Attribute_isRelative->setLowerBound(1);
	m_timeEvent_Attribute_isRelative->setUpperBound(1);
	m_timeEvent_Attribute_isRelative->setTransient(false);
	m_timeEvent_Attribute_isRelative->setVolatile(false);
	m_timeEvent_Attribute_isRelative->setChangeable(true);
	m_timeEvent_Attribute_isRelative->setUnsettable(false);
	m_timeEvent_Attribute_isRelative->setUnique(true);
	m_timeEvent_Attribute_isRelative->setDerived(false);
	m_timeEvent_Attribute_isRelative->setOrdered(false);
	m_timeEvent_Attribute_isRelative->setID(false);
	m_timeEvent_Attribute_isRelative->setDefaultValueLiteral("false");
	
	m_timeEvent_Attribute_isRelative->_setID(TIMEEVENT_ATTRIBUTE_ISRELATIVE);
	
	/*
	 * EReferences
	 */
	m_timeEvent_Attribute_when->setName("when");
	m_timeEvent_Attribute_when->setEType(getTimeExpression_Class());
	m_timeEvent_Attribute_when->setLowerBound(1);
	m_timeEvent_Attribute_when->setUpperBound(1);
	m_timeEvent_Attribute_when->setTransient(false);
	m_timeEvent_Attribute_when->setVolatile(false);
	m_timeEvent_Attribute_when->setChangeable(true);
	m_timeEvent_Attribute_when->setUnsettable(false);
	m_timeEvent_Attribute_when->setUnique(true);
	m_timeEvent_Attribute_when->setDerived(false);
	m_timeEvent_Attribute_when->setOrdered(false);
	m_timeEvent_Attribute_when->setContainment(true);
	m_timeEvent_Attribute_when->setResolveProxies(true);
	m_timeEvent_Attribute_when->setDefaultValueLiteral("");	
	
	m_timeEvent_Attribute_when->_setID(TIMEEVENT_ATTRIBUTE_WHEN);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeTimeExpressionContent()
{
	m_timeExpression_Class->setName("TimeExpression");
	m_timeExpression_Class->setAbstract(false);
	m_timeExpression_Class->setInterface(false);
	
	m_timeExpression_Class->_setID(TIMEEXPRESSION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_timeExpression_Attribute_expr->setName("expr");
	m_timeExpression_Attribute_expr->setEType(getValueSpecification_Class());
	m_timeExpression_Attribute_expr->setLowerBound(0);
	m_timeExpression_Attribute_expr->setUpperBound(1);
	m_timeExpression_Attribute_expr->setTransient(false);
	m_timeExpression_Attribute_expr->setVolatile(false);
	m_timeExpression_Attribute_expr->setChangeable(true);
	m_timeExpression_Attribute_expr->setUnsettable(false);
	m_timeExpression_Attribute_expr->setUnique(true);
	m_timeExpression_Attribute_expr->setDerived(false);
	m_timeExpression_Attribute_expr->setOrdered(false);
	m_timeExpression_Attribute_expr->setContainment(true);
	m_timeExpression_Attribute_expr->setResolveProxies(true);
	m_timeExpression_Attribute_expr->setDefaultValueLiteral("");	
	
	m_timeExpression_Attribute_expr->_setID(TIMEEXPRESSION_ATTRIBUTE_EXPR);
	m_timeExpression_Attribute_observation->setName("observation");
	m_timeExpression_Attribute_observation->setEType(getObservation_Class());
	m_timeExpression_Attribute_observation->setLowerBound(0);
	m_timeExpression_Attribute_observation->setUpperBound(-1);
	m_timeExpression_Attribute_observation->setTransient(false);
	m_timeExpression_Attribute_observation->setVolatile(false);
	m_timeExpression_Attribute_observation->setChangeable(true);
	m_timeExpression_Attribute_observation->setUnsettable(false);
	m_timeExpression_Attribute_observation->setUnique(true);
	m_timeExpression_Attribute_observation->setDerived(false);
	m_timeExpression_Attribute_observation->setOrdered(false);
	m_timeExpression_Attribute_observation->setContainment(false);
	m_timeExpression_Attribute_observation->setResolveProxies(true);
	m_timeExpression_Attribute_observation->setDefaultValueLiteral("");	
	
	m_timeExpression_Attribute_observation->_setID(TIMEEXPRESSION_ATTRIBUTE_OBSERVATION);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeTimeIntervalContent()
{
	m_timeInterval_Class->setName("TimeInterval");
	m_timeInterval_Class->setAbstract(false);
	m_timeInterval_Class->setInterface(false);
	
	m_timeInterval_Class->_setID(TIMEINTERVAL_CLASS);
	
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

void umlPackageImpl::initializeTimeObservationContent()
{
	m_timeObservation_Class->setName("TimeObservation");
	m_timeObservation_Class->setAbstract(false);
	m_timeObservation_Class->setInterface(false);
	
	m_timeObservation_Class->_setID(TIMEOBSERVATION_CLASS);
	
	/*
	 * EAttributes
	 */
	m_timeObservation_Attribute_firstEvent = getTimeObservation_Attribute_firstEvent();
	m_timeObservation_Attribute_firstEvent->setName("firstEvent");
	m_timeObservation_Attribute_firstEvent->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_timeObservation_Attribute_firstEvent->setLowerBound(1);
	m_timeObservation_Attribute_firstEvent->setUpperBound(1);
	m_timeObservation_Attribute_firstEvent->setTransient(false);
	m_timeObservation_Attribute_firstEvent->setVolatile(false);
	m_timeObservation_Attribute_firstEvent->setChangeable(true);
	m_timeObservation_Attribute_firstEvent->setUnsettable(false);
	m_timeObservation_Attribute_firstEvent->setUnique(true);
	m_timeObservation_Attribute_firstEvent->setDerived(false);
	m_timeObservation_Attribute_firstEvent->setOrdered(false);
	m_timeObservation_Attribute_firstEvent->setID(false);
	m_timeObservation_Attribute_firstEvent->setDefaultValueLiteral("true");
	
	m_timeObservation_Attribute_firstEvent->_setID(TIMEOBSERVATION_ATTRIBUTE_FIRSTEVENT);
	
	/*
	 * EReferences
	 */
	m_timeObservation_Attribute_event->setName("event");
	m_timeObservation_Attribute_event->setEType(getNamedElement_Class());
	m_timeObservation_Attribute_event->setLowerBound(1);
	m_timeObservation_Attribute_event->setUpperBound(1);
	m_timeObservation_Attribute_event->setTransient(false);
	m_timeObservation_Attribute_event->setVolatile(false);
	m_timeObservation_Attribute_event->setChangeable(true);
	m_timeObservation_Attribute_event->setUnsettable(false);
	m_timeObservation_Attribute_event->setUnique(true);
	m_timeObservation_Attribute_event->setDerived(false);
	m_timeObservation_Attribute_event->setOrdered(false);
	m_timeObservation_Attribute_event->setContainment(false);
	m_timeObservation_Attribute_event->setResolveProxies(true);
	m_timeObservation_Attribute_event->setDefaultValueLiteral("");	
	
	m_timeObservation_Attribute_event->_setID(TIMEOBSERVATION_ATTRIBUTE_EVENT);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeTransitionContent()
{
	m_transition_Class->setName("Transition");
	m_transition_Class->setAbstract(false);
	m_transition_Class->setInterface(false);
	
	m_transition_Class->_setID(TRANSITION_CLASS);
	
	/*
	 * EAttributes
	 */
	m_transition_Attribute_kind = getTransition_Attribute_kind();
	m_transition_Attribute_kind->setName("kind");
	m_transition_Attribute_kind->setEType(getTransitionKind_Class());
	m_transition_Attribute_kind->setLowerBound(1);
	m_transition_Attribute_kind->setUpperBound(1);
	m_transition_Attribute_kind->setTransient(false);
	m_transition_Attribute_kind->setVolatile(false);
	m_transition_Attribute_kind->setChangeable(true);
	m_transition_Attribute_kind->setUnsettable(false);
	m_transition_Attribute_kind->setUnique(true);
	m_transition_Attribute_kind->setDerived(false);
	m_transition_Attribute_kind->setOrdered(false);
	m_transition_Attribute_kind->setID(false);
	m_transition_Attribute_kind->setDefaultValueLiteral("external");
	
	m_transition_Attribute_kind->_setID(TRANSITION_ATTRIBUTE_KIND);
	
	/*
	 * EReferences
	 */
	m_transition_Attribute_container->setName("container");
	m_transition_Attribute_container->setEType(getRegion_Class());
	m_transition_Attribute_container->setLowerBound(1);
	m_transition_Attribute_container->setUpperBound(1);
	m_transition_Attribute_container->setTransient(false);
	m_transition_Attribute_container->setVolatile(false);
	m_transition_Attribute_container->setChangeable(true);
	m_transition_Attribute_container->setUnsettable(false);
	m_transition_Attribute_container->setUnique(true);
	m_transition_Attribute_container->setDerived(false);
	m_transition_Attribute_container->setOrdered(false);
	m_transition_Attribute_container->setContainment(false);
	m_transition_Attribute_container->setResolveProxies(true);
	m_transition_Attribute_container->setDefaultValueLiteral("");	
	m_transition_Attribute_container->setEOpposite(uml::umlPackage::eInstance()->getRegion_Attribute_transition());
	
	m_transition_Attribute_container->_setID(TRANSITION_ATTRIBUTE_CONTAINER);
	m_transition_Attribute_effect->setName("effect");
	m_transition_Attribute_effect->setEType(getBehavior_Class());
	m_transition_Attribute_effect->setLowerBound(0);
	m_transition_Attribute_effect->setUpperBound(1);
	m_transition_Attribute_effect->setTransient(false);
	m_transition_Attribute_effect->setVolatile(false);
	m_transition_Attribute_effect->setChangeable(true);
	m_transition_Attribute_effect->setUnsettable(false);
	m_transition_Attribute_effect->setUnique(true);
	m_transition_Attribute_effect->setDerived(false);
	m_transition_Attribute_effect->setOrdered(false);
	m_transition_Attribute_effect->setContainment(true);
	m_transition_Attribute_effect->setResolveProxies(true);
	m_transition_Attribute_effect->setDefaultValueLiteral("");	
	
	m_transition_Attribute_effect->_setID(TRANSITION_ATTRIBUTE_EFFECT);
	m_transition_Attribute_guard->setName("guard");
	m_transition_Attribute_guard->setEType(getConstraint_Class());
	m_transition_Attribute_guard->setLowerBound(0);
	m_transition_Attribute_guard->setUpperBound(1);
	m_transition_Attribute_guard->setTransient(false);
	m_transition_Attribute_guard->setVolatile(false);
	m_transition_Attribute_guard->setChangeable(true);
	m_transition_Attribute_guard->setUnsettable(false);
	m_transition_Attribute_guard->setUnique(true);
	m_transition_Attribute_guard->setDerived(false);
	m_transition_Attribute_guard->setOrdered(false);
	m_transition_Attribute_guard->setContainment(false);
	m_transition_Attribute_guard->setResolveProxies(true);
	m_transition_Attribute_guard->setDefaultValueLiteral("");	
	
	m_transition_Attribute_guard->_setID(TRANSITION_ATTRIBUTE_GUARD);
	m_transition_Attribute_redefinedTransition->setName("redefinedTransition");
	m_transition_Attribute_redefinedTransition->setEType(getTransition_Class());
	m_transition_Attribute_redefinedTransition->setLowerBound(0);
	m_transition_Attribute_redefinedTransition->setUpperBound(1);
	m_transition_Attribute_redefinedTransition->setTransient(false);
	m_transition_Attribute_redefinedTransition->setVolatile(false);
	m_transition_Attribute_redefinedTransition->setChangeable(true);
	m_transition_Attribute_redefinedTransition->setUnsettable(false);
	m_transition_Attribute_redefinedTransition->setUnique(true);
	m_transition_Attribute_redefinedTransition->setDerived(false);
	m_transition_Attribute_redefinedTransition->setOrdered(false);
	m_transition_Attribute_redefinedTransition->setContainment(false);
	m_transition_Attribute_redefinedTransition->setResolveProxies(true);
	m_transition_Attribute_redefinedTransition->setDefaultValueLiteral("");	
	
	m_transition_Attribute_redefinedTransition->_setID(TRANSITION_ATTRIBUTE_REDEFINEDTRANSITION);
	m_transition_Attribute_source->setName("source");
	m_transition_Attribute_source->setEType(getVertex_Class());
	m_transition_Attribute_source->setLowerBound(1);
	m_transition_Attribute_source->setUpperBound(1);
	m_transition_Attribute_source->setTransient(false);
	m_transition_Attribute_source->setVolatile(false);
	m_transition_Attribute_source->setChangeable(true);
	m_transition_Attribute_source->setUnsettable(false);
	m_transition_Attribute_source->setUnique(true);
	m_transition_Attribute_source->setDerived(false);
	m_transition_Attribute_source->setOrdered(false);
	m_transition_Attribute_source->setContainment(false);
	m_transition_Attribute_source->setResolveProxies(true);
	m_transition_Attribute_source->setDefaultValueLiteral("");	
	
	m_transition_Attribute_source->_setID(TRANSITION_ATTRIBUTE_SOURCE);
	m_transition_Attribute_target->setName("target");
	m_transition_Attribute_target->setEType(getVertex_Class());
	m_transition_Attribute_target->setLowerBound(1);
	m_transition_Attribute_target->setUpperBound(1);
	m_transition_Attribute_target->setTransient(false);
	m_transition_Attribute_target->setVolatile(false);
	m_transition_Attribute_target->setChangeable(true);
	m_transition_Attribute_target->setUnsettable(false);
	m_transition_Attribute_target->setUnique(true);
	m_transition_Attribute_target->setDerived(false);
	m_transition_Attribute_target->setOrdered(false);
	m_transition_Attribute_target->setContainment(false);
	m_transition_Attribute_target->setResolveProxies(true);
	m_transition_Attribute_target->setDefaultValueLiteral("");	
	
	m_transition_Attribute_target->_setID(TRANSITION_ATTRIBUTE_TARGET);
	m_transition_Attribute_trigger->setName("trigger");
	m_transition_Attribute_trigger->setEType(getTrigger_Class());
	m_transition_Attribute_trigger->setLowerBound(0);
	m_transition_Attribute_trigger->setUpperBound(-1);
	m_transition_Attribute_trigger->setTransient(false);
	m_transition_Attribute_trigger->setVolatile(false);
	m_transition_Attribute_trigger->setChangeable(true);
	m_transition_Attribute_trigger->setUnsettable(false);
	m_transition_Attribute_trigger->setUnique(true);
	m_transition_Attribute_trigger->setDerived(false);
	m_transition_Attribute_trigger->setOrdered(false);
	m_transition_Attribute_trigger->setContainment(true);
	m_transition_Attribute_trigger->setResolveProxies(true);
	m_transition_Attribute_trigger->setDefaultValueLiteral("");	
	
	m_transition_Attribute_trigger->_setID(TRANSITION_ATTRIBUTE_TRIGGER);
	
	/*
	 * EOperations
	 */
	m_transition_Operation_containingStateMachine->setName("containingStateMachine");
	m_transition_Operation_containingStateMachine->setEType(getStateMachine_Class());
	m_transition_Operation_containingStateMachine->setLowerBound(1);
	m_transition_Operation_containingStateMachine->setUpperBound(1);
	m_transition_Operation_containingStateMachine->setUnique(true);
	m_transition_Operation_containingStateMachine->setOrdered(false);
	
	m_transition_Operation_containingStateMachine->_setID(TRANSITION_OPERATION_CONTAININGSTATEMACHINE);
	
	
	m_transition_Operation_redefinitionContext->setName("redefinitionContext");
	m_transition_Operation_redefinitionContext->setEType(getClassifier_Class());
	m_transition_Operation_redefinitionContext->setLowerBound(1);
	m_transition_Operation_redefinitionContext->setUpperBound(1);
	m_transition_Operation_redefinitionContext->setUnique(true);
	m_transition_Operation_redefinitionContext->setOrdered(false);
	
	m_transition_Operation_redefinitionContext->_setID(TRANSITION_OPERATION_REDEFINITIONCONTEXT);
	
	
	
}

void umlPackageImpl::initializeTriggerContent()
{
	m_trigger_Class->setName("Trigger");
	m_trigger_Class->setAbstract(false);
	m_trigger_Class->setInterface(false);
	
	m_trigger_Class->_setID(TRIGGER_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_trigger_Attribute_event->setName("event");
	m_trigger_Attribute_event->setEType(getEvent_Class());
	m_trigger_Attribute_event->setLowerBound(1);
	m_trigger_Attribute_event->setUpperBound(1);
	m_trigger_Attribute_event->setTransient(false);
	m_trigger_Attribute_event->setVolatile(false);
	m_trigger_Attribute_event->setChangeable(true);
	m_trigger_Attribute_event->setUnsettable(false);
	m_trigger_Attribute_event->setUnique(true);
	m_trigger_Attribute_event->setDerived(false);
	m_trigger_Attribute_event->setOrdered(false);
	m_trigger_Attribute_event->setContainment(false);
	m_trigger_Attribute_event->setResolveProxies(true);
	m_trigger_Attribute_event->setDefaultValueLiteral("");	
	
	m_trigger_Attribute_event->_setID(TRIGGER_ATTRIBUTE_EVENT);
	m_trigger_Attribute_port->setName("port");
	m_trigger_Attribute_port->setEType(getPort_Class());
	m_trigger_Attribute_port->setLowerBound(0);
	m_trigger_Attribute_port->setUpperBound(-1);
	m_trigger_Attribute_port->setTransient(false);
	m_trigger_Attribute_port->setVolatile(false);
	m_trigger_Attribute_port->setChangeable(true);
	m_trigger_Attribute_port->setUnsettable(false);
	m_trigger_Attribute_port->setUnique(true);
	m_trigger_Attribute_port->setDerived(false);
	m_trigger_Attribute_port->setOrdered(false);
	m_trigger_Attribute_port->setContainment(false);
	m_trigger_Attribute_port->setResolveProxies(true);
	m_trigger_Attribute_port->setDefaultValueLiteral("");	
	
	m_trigger_Attribute_port->_setID(TRIGGER_ATTRIBUTE_PORT);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeTypeContent()
{
	m_type_Class->setName("Type");
	m_type_Class->setAbstract(true);
	m_type_Class->setInterface(false);
	
	m_type_Class->_setID(TYPE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_type_Attribute_package->setName("package");
	m_type_Attribute_package->setEType(getPackage_Class());
	m_type_Attribute_package->setLowerBound(0);
	m_type_Attribute_package->setUpperBound(1);
	m_type_Attribute_package->setTransient(true);
	m_type_Attribute_package->setVolatile(true);
	m_type_Attribute_package->setChangeable(true);
	m_type_Attribute_package->setUnsettable(false);
	m_type_Attribute_package->setUnique(true);
	m_type_Attribute_package->setDerived(true);
	m_type_Attribute_package->setOrdered(false);
	m_type_Attribute_package->setContainment(false);
	m_type_Attribute_package->setResolveProxies(true);
	m_type_Attribute_package->setDefaultValueLiteral("");	
	m_type_Attribute_package->setEOpposite(uml::umlPackage::eInstance()->getPackage_Attribute_ownedType());
	
	m_type_Attribute_package->_setID(TYPE_ATTRIBUTE_PACKAGE);
	
	/*
	 * EOperations
	 */
	m_type_Operation_conformsTo_Type->setName("conformsTo");
	m_type_Operation_conformsTo_Type->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_type_Operation_conformsTo_Type->setLowerBound(1);
	m_type_Operation_conformsTo_Type->setUpperBound(1);
	m_type_Operation_conformsTo_Type->setUnique(true);
	m_type_Operation_conformsTo_Type->setOrdered(false);
	
	m_type_Operation_conformsTo_Type->_setID(TYPE_OPERATION_CONFORMSTO_TYPE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_type_Operation_conformsTo_Type);
		parameter->setName("other");
		parameter->setEType(getType_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_type_Operation_createAssociation_Boolean_UnlimitedNatural->setName("createAssociation");
	m_type_Operation_createAssociation_Boolean_UnlimitedNatural->setEType(getAssociation_Class());
	m_type_Operation_createAssociation_Boolean_UnlimitedNatural->setLowerBound(1);
	m_type_Operation_createAssociation_Boolean_UnlimitedNatural->setUpperBound(1);
	m_type_Operation_createAssociation_Boolean_UnlimitedNatural->setUnique(true);
	m_type_Operation_createAssociation_Boolean_UnlimitedNatural->setOrdered(false);
	
	m_type_Operation_createAssociation_Boolean_UnlimitedNatural->_setID(TYPE_OPERATION_CREATEASSOCIATION_BOOLEAN_UNLIMITEDNATURAL);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_type_Operation_createAssociation_Boolean_UnlimitedNatural);
		parameter->setName("end1IsNavigable");
		parameter->setEType(types::typesPackage::eInstance()->getBoolean_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_type_Operation_createAssociation_Boolean_UnlimitedNatural);
		parameter->setName("end1Aggregation");
		parameter->setEType(getAggregationKind_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_type_Operation_createAssociation_Boolean_UnlimitedNatural);
		parameter->setName("end1Name");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_type_Operation_createAssociation_Boolean_UnlimitedNatural);
		parameter->setName("end1Lower");
		parameter->setEType(types::typesPackage::eInstance()->getInteger_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_type_Operation_createAssociation_Boolean_UnlimitedNatural);
		parameter->setName("end1Upper");
		parameter->setEType(types::typesPackage::eInstance()->getUnlimitedNatural_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_type_Operation_createAssociation_Boolean_UnlimitedNatural);
		parameter->setName("end1Type");
		parameter->setEType(getType_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_type_Operation_createAssociation_Boolean_UnlimitedNatural);
		parameter->setName("end2IsNavigable");
		parameter->setEType(types::typesPackage::eInstance()->getBoolean_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_type_Operation_createAssociation_Boolean_UnlimitedNatural);
		parameter->setName("end2Aggregation");
		parameter->setEType(getAggregationKind_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_type_Operation_createAssociation_Boolean_UnlimitedNatural);
		parameter->setName("end2Name");
		parameter->setEType(types::typesPackage::eInstance()->getString_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_type_Operation_createAssociation_Boolean_UnlimitedNatural);
		parameter->setName("end2Lower");
		parameter->setEType(types::typesPackage::eInstance()->getInteger_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_type_Operation_createAssociation_Boolean_UnlimitedNatural);
		parameter->setName("end2Upper");
		parameter->setEType(types::typesPackage::eInstance()->getUnlimitedNatural_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_type_Operation_getAssociations->setName("getAssociations");
	m_type_Operation_getAssociations->setEType(getAssociation_Class());
	m_type_Operation_getAssociations->setLowerBound(0);
	m_type_Operation_getAssociations->setUpperBound(-1);
	m_type_Operation_getAssociations->setUnique(true);
	m_type_Operation_getAssociations->setOrdered(false);
	
	m_type_Operation_getAssociations->_setID(TYPE_OPERATION_GETASSOCIATIONS);
	
	
	
}

void umlPackageImpl::initializeTypedElementContent()
{
	m_typedElement_Class->setName("TypedElement");
	m_typedElement_Class->setAbstract(true);
	m_typedElement_Class->setInterface(false);
	
	m_typedElement_Class->_setID(TYPEDELEMENT_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_typedElement_Attribute_type->setName("type");
	m_typedElement_Attribute_type->setEType(getType_Class());
	m_typedElement_Attribute_type->setLowerBound(0);
	m_typedElement_Attribute_type->setUpperBound(1);
	m_typedElement_Attribute_type->setTransient(false);
	m_typedElement_Attribute_type->setVolatile(false);
	m_typedElement_Attribute_type->setChangeable(true);
	m_typedElement_Attribute_type->setUnsettable(false);
	m_typedElement_Attribute_type->setUnique(true);
	m_typedElement_Attribute_type->setDerived(false);
	m_typedElement_Attribute_type->setOrdered(false);
	m_typedElement_Attribute_type->setContainment(false);
	m_typedElement_Attribute_type->setResolveProxies(true);
	m_typedElement_Attribute_type->setDefaultValueLiteral("");	
	
	m_typedElement_Attribute_type->_setID(TYPEDELEMENT_ATTRIBUTE_TYPE);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeUnmarshallActionContent()
{
	m_unmarshallAction_Class->setName("UnmarshallAction");
	m_unmarshallAction_Class->setAbstract(false);
	m_unmarshallAction_Class->setInterface(false);
	
	m_unmarshallAction_Class->_setID(UNMARSHALLACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_unmarshallAction_Attribute_object->setName("object");
	m_unmarshallAction_Attribute_object->setEType(getInputPin_Class());
	m_unmarshallAction_Attribute_object->setLowerBound(1);
	m_unmarshallAction_Attribute_object->setUpperBound(1);
	m_unmarshallAction_Attribute_object->setTransient(false);
	m_unmarshallAction_Attribute_object->setVolatile(false);
	m_unmarshallAction_Attribute_object->setChangeable(true);
	m_unmarshallAction_Attribute_object->setUnsettable(false);
	m_unmarshallAction_Attribute_object->setUnique(true);
	m_unmarshallAction_Attribute_object->setDerived(false);
	m_unmarshallAction_Attribute_object->setOrdered(false);
	m_unmarshallAction_Attribute_object->setContainment(true);
	m_unmarshallAction_Attribute_object->setResolveProxies(true);
	m_unmarshallAction_Attribute_object->setDefaultValueLiteral("");	
	
	m_unmarshallAction_Attribute_object->_setID(UNMARSHALLACTION_ATTRIBUTE_OBJECT);
	m_unmarshallAction_Attribute_result->setName("result");
	m_unmarshallAction_Attribute_result->setEType(getOutputPin_Class());
	m_unmarshallAction_Attribute_result->setLowerBound(1);
	m_unmarshallAction_Attribute_result->setUpperBound(-1);
	m_unmarshallAction_Attribute_result->setTransient(false);
	m_unmarshallAction_Attribute_result->setVolatile(false);
	m_unmarshallAction_Attribute_result->setChangeable(true);
	m_unmarshallAction_Attribute_result->setUnsettable(false);
	m_unmarshallAction_Attribute_result->setUnique(true);
	m_unmarshallAction_Attribute_result->setDerived(false);
	m_unmarshallAction_Attribute_result->setOrdered(true);
	m_unmarshallAction_Attribute_result->setContainment(true);
	m_unmarshallAction_Attribute_result->setResolveProxies(true);
	m_unmarshallAction_Attribute_result->setDefaultValueLiteral("");	
	
	m_unmarshallAction_Attribute_result->_setID(UNMARSHALLACTION_ATTRIBUTE_RESULT);
	m_unmarshallAction_Attribute_unmarshallType->setName("unmarshallType");
	m_unmarshallAction_Attribute_unmarshallType->setEType(getClassifier_Class());
	m_unmarshallAction_Attribute_unmarshallType->setLowerBound(1);
	m_unmarshallAction_Attribute_unmarshallType->setUpperBound(1);
	m_unmarshallAction_Attribute_unmarshallType->setTransient(false);
	m_unmarshallAction_Attribute_unmarshallType->setVolatile(false);
	m_unmarshallAction_Attribute_unmarshallType->setChangeable(true);
	m_unmarshallAction_Attribute_unmarshallType->setUnsettable(false);
	m_unmarshallAction_Attribute_unmarshallType->setUnique(true);
	m_unmarshallAction_Attribute_unmarshallType->setDerived(false);
	m_unmarshallAction_Attribute_unmarshallType->setOrdered(false);
	m_unmarshallAction_Attribute_unmarshallType->setContainment(false);
	m_unmarshallAction_Attribute_unmarshallType->setResolveProxies(true);
	m_unmarshallAction_Attribute_unmarshallType->setDefaultValueLiteral("");	
	
	m_unmarshallAction_Attribute_unmarshallType->_setID(UNMARSHALLACTION_ATTRIBUTE_UNMARSHALLTYPE);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeUsageContent()
{
	m_usage_Class->setName("Usage");
	m_usage_Class->setAbstract(false);
	m_usage_Class->setInterface(false);
	
	m_usage_Class->_setID(USAGE_CLASS);
	
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

void umlPackageImpl::initializeUseCaseContent()
{
	m_useCase_Class->setName("UseCase");
	m_useCase_Class->setAbstract(false);
	m_useCase_Class->setInterface(false);
	
	m_useCase_Class->_setID(USECASE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_useCase_Attribute_extend->setName("extend");
	m_useCase_Attribute_extend->setEType(getExtend_Class());
	m_useCase_Attribute_extend->setLowerBound(0);
	m_useCase_Attribute_extend->setUpperBound(-1);
	m_useCase_Attribute_extend->setTransient(false);
	m_useCase_Attribute_extend->setVolatile(false);
	m_useCase_Attribute_extend->setChangeable(true);
	m_useCase_Attribute_extend->setUnsettable(false);
	m_useCase_Attribute_extend->setUnique(true);
	m_useCase_Attribute_extend->setDerived(false);
	m_useCase_Attribute_extend->setOrdered(false);
	m_useCase_Attribute_extend->setContainment(true);
	m_useCase_Attribute_extend->setResolveProxies(true);
	m_useCase_Attribute_extend->setDefaultValueLiteral("");	
	m_useCase_Attribute_extend->setEOpposite(uml::umlPackage::eInstance()->getExtend_Attribute_extension());
	
	m_useCase_Attribute_extend->_setID(USECASE_ATTRIBUTE_EXTEND);
	m_useCase_Attribute_extensionPoint->setName("extensionPoint");
	m_useCase_Attribute_extensionPoint->setEType(getExtensionPoint_Class());
	m_useCase_Attribute_extensionPoint->setLowerBound(0);
	m_useCase_Attribute_extensionPoint->setUpperBound(-1);
	m_useCase_Attribute_extensionPoint->setTransient(false);
	m_useCase_Attribute_extensionPoint->setVolatile(false);
	m_useCase_Attribute_extensionPoint->setChangeable(true);
	m_useCase_Attribute_extensionPoint->setUnsettable(false);
	m_useCase_Attribute_extensionPoint->setUnique(true);
	m_useCase_Attribute_extensionPoint->setDerived(false);
	m_useCase_Attribute_extensionPoint->setOrdered(false);
	m_useCase_Attribute_extensionPoint->setContainment(true);
	m_useCase_Attribute_extensionPoint->setResolveProxies(true);
	m_useCase_Attribute_extensionPoint->setDefaultValueLiteral("");	
	m_useCase_Attribute_extensionPoint->setEOpposite(uml::umlPackage::eInstance()->getExtensionPoint_Attribute_useCase());
	
	m_useCase_Attribute_extensionPoint->_setID(USECASE_ATTRIBUTE_EXTENSIONPOINT);
	m_useCase_Attribute_include->setName("include");
	m_useCase_Attribute_include->setEType(getInclude_Class());
	m_useCase_Attribute_include->setLowerBound(0);
	m_useCase_Attribute_include->setUpperBound(-1);
	m_useCase_Attribute_include->setTransient(false);
	m_useCase_Attribute_include->setVolatile(false);
	m_useCase_Attribute_include->setChangeable(true);
	m_useCase_Attribute_include->setUnsettable(false);
	m_useCase_Attribute_include->setUnique(true);
	m_useCase_Attribute_include->setDerived(false);
	m_useCase_Attribute_include->setOrdered(false);
	m_useCase_Attribute_include->setContainment(true);
	m_useCase_Attribute_include->setResolveProxies(true);
	m_useCase_Attribute_include->setDefaultValueLiteral("");	
	m_useCase_Attribute_include->setEOpposite(uml::umlPackage::eInstance()->getInclude_Attribute_includingCase());
	
	m_useCase_Attribute_include->_setID(USECASE_ATTRIBUTE_INCLUDE);
	m_useCase_Attribute_subject->setName("subject");
	m_useCase_Attribute_subject->setEType(getClassifier_Class());
	m_useCase_Attribute_subject->setLowerBound(0);
	m_useCase_Attribute_subject->setUpperBound(-1);
	m_useCase_Attribute_subject->setTransient(false);
	m_useCase_Attribute_subject->setVolatile(false);
	m_useCase_Attribute_subject->setChangeable(true);
	m_useCase_Attribute_subject->setUnsettable(false);
	m_useCase_Attribute_subject->setUnique(true);
	m_useCase_Attribute_subject->setDerived(false);
	m_useCase_Attribute_subject->setOrdered(false);
	m_useCase_Attribute_subject->setContainment(false);
	m_useCase_Attribute_subject->setResolveProxies(true);
	m_useCase_Attribute_subject->setDefaultValueLiteral("");	
	m_useCase_Attribute_subject->setEOpposite(uml::umlPackage::eInstance()->getClassifier_Attribute_useCase());
	
	m_useCase_Attribute_subject->_setID(USECASE_ATTRIBUTE_SUBJECT);
	
	/*
	 * EOperations
	 */
	m_useCase_Operation_allIncludedUseCases->setName("allIncludedUseCases");
	m_useCase_Operation_allIncludedUseCases->setEType(getUseCase_Class());
	m_useCase_Operation_allIncludedUseCases->setLowerBound(0);
	m_useCase_Operation_allIncludedUseCases->setUpperBound(-1);
	m_useCase_Operation_allIncludedUseCases->setUnique(true);
	m_useCase_Operation_allIncludedUseCases->setOrdered(false);
	
	m_useCase_Operation_allIncludedUseCases->_setID(USECASE_OPERATION_ALLINCLUDEDUSECASES);
	
	
	
}

void umlPackageImpl::initializeValuePinContent()
{
	m_valuePin_Class->setName("ValuePin");
	m_valuePin_Class->setAbstract(false);
	m_valuePin_Class->setInterface(false);
	
	m_valuePin_Class->_setID(VALUEPIN_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_valuePin_Attribute_value->setName("value");
	m_valuePin_Attribute_value->setEType(getValueSpecification_Class());
	m_valuePin_Attribute_value->setLowerBound(1);
	m_valuePin_Attribute_value->setUpperBound(1);
	m_valuePin_Attribute_value->setTransient(false);
	m_valuePin_Attribute_value->setVolatile(false);
	m_valuePin_Attribute_value->setChangeable(true);
	m_valuePin_Attribute_value->setUnsettable(false);
	m_valuePin_Attribute_value->setUnique(true);
	m_valuePin_Attribute_value->setDerived(false);
	m_valuePin_Attribute_value->setOrdered(false);
	m_valuePin_Attribute_value->setContainment(true);
	m_valuePin_Attribute_value->setResolveProxies(true);
	m_valuePin_Attribute_value->setDefaultValueLiteral("");	
	
	m_valuePin_Attribute_value->_setID(VALUEPIN_ATTRIBUTE_VALUE);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeValueSpecificationContent()
{
	m_valueSpecification_Class->setName("ValueSpecification");
	m_valueSpecification_Class->setAbstract(true);
	m_valueSpecification_Class->setInterface(false);
	
	m_valueSpecification_Class->_setID(VALUESPECIFICATION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_valueSpecification_Attribute_owningSlot->setName("owningSlot");
	m_valueSpecification_Attribute_owningSlot->setEType(getSlot_Class());
	m_valueSpecification_Attribute_owningSlot->setLowerBound(0);
	m_valueSpecification_Attribute_owningSlot->setUpperBound(1);
	m_valueSpecification_Attribute_owningSlot->setTransient(false);
	m_valueSpecification_Attribute_owningSlot->setVolatile(false);
	m_valueSpecification_Attribute_owningSlot->setChangeable(true);
	m_valueSpecification_Attribute_owningSlot->setUnsettable(false);
	m_valueSpecification_Attribute_owningSlot->setUnique(true);
	m_valueSpecification_Attribute_owningSlot->setDerived(false);
	m_valueSpecification_Attribute_owningSlot->setOrdered(true);
	m_valueSpecification_Attribute_owningSlot->setContainment(false);
	m_valueSpecification_Attribute_owningSlot->setResolveProxies(true);
	m_valueSpecification_Attribute_owningSlot->setDefaultValueLiteral("");	
	m_valueSpecification_Attribute_owningSlot->setEOpposite(uml::umlPackage::eInstance()->getSlot_Attribute_value());
	
	m_valueSpecification_Attribute_owningSlot->_setID(VALUESPECIFICATION_ATTRIBUTE_OWNINGSLOT);
	m_valueSpecification_Attribute_valueSpecificationAction->setName("valueSpecificationAction");
	m_valueSpecification_Attribute_valueSpecificationAction->setEType(getValueSpecificationAction_Class());
	m_valueSpecification_Attribute_valueSpecificationAction->setLowerBound(0);
	m_valueSpecification_Attribute_valueSpecificationAction->setUpperBound(1);
	m_valueSpecification_Attribute_valueSpecificationAction->setTransient(false);
	m_valueSpecification_Attribute_valueSpecificationAction->setVolatile(false);
	m_valueSpecification_Attribute_valueSpecificationAction->setChangeable(true);
	m_valueSpecification_Attribute_valueSpecificationAction->setUnsettable(false);
	m_valueSpecification_Attribute_valueSpecificationAction->setUnique(true);
	m_valueSpecification_Attribute_valueSpecificationAction->setDerived(false);
	m_valueSpecification_Attribute_valueSpecificationAction->setOrdered(true);
	m_valueSpecification_Attribute_valueSpecificationAction->setContainment(false);
	m_valueSpecification_Attribute_valueSpecificationAction->setResolveProxies(true);
	m_valueSpecification_Attribute_valueSpecificationAction->setDefaultValueLiteral("");	
	m_valueSpecification_Attribute_valueSpecificationAction->setEOpposite(uml::umlPackage::eInstance()->getValueSpecificationAction_Attribute_value());
	
	m_valueSpecification_Attribute_valueSpecificationAction->_setID(VALUESPECIFICATION_ATTRIBUTE_VALUESPECIFICATIONACTION);
	
	/*
	 * EOperations
	 */
	m_valueSpecification_Operation_booleanValue->setName("booleanValue");
	m_valueSpecification_Operation_booleanValue->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_valueSpecification_Operation_booleanValue->setLowerBound(0);
	m_valueSpecification_Operation_booleanValue->setUpperBound(1);
	m_valueSpecification_Operation_booleanValue->setUnique(true);
	m_valueSpecification_Operation_booleanValue->setOrdered(false);
	
	m_valueSpecification_Operation_booleanValue->_setID(VALUESPECIFICATION_OPERATION_BOOLEANVALUE);
	
	
	m_valueSpecification_Operation_integerValue->setName("integerValue");
	m_valueSpecification_Operation_integerValue->setEType(types::typesPackage::eInstance()->getInteger_Class());
	m_valueSpecification_Operation_integerValue->setLowerBound(0);
	m_valueSpecification_Operation_integerValue->setUpperBound(1);
	m_valueSpecification_Operation_integerValue->setUnique(true);
	m_valueSpecification_Operation_integerValue->setOrdered(false);
	
	m_valueSpecification_Operation_integerValue->_setID(VALUESPECIFICATION_OPERATION_INTEGERVALUE);
	
	
	m_valueSpecification_Operation_isComputable->setName("isComputable");
	m_valueSpecification_Operation_isComputable->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_valueSpecification_Operation_isComputable->setLowerBound(1);
	m_valueSpecification_Operation_isComputable->setUpperBound(1);
	m_valueSpecification_Operation_isComputable->setUnique(true);
	m_valueSpecification_Operation_isComputable->setOrdered(false);
	
	m_valueSpecification_Operation_isComputable->_setID(VALUESPECIFICATION_OPERATION_ISCOMPUTABLE);
	
	
	m_valueSpecification_Operation_isNull->setName("isNull");
	m_valueSpecification_Operation_isNull->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_valueSpecification_Operation_isNull->setLowerBound(1);
	m_valueSpecification_Operation_isNull->setUpperBound(1);
	m_valueSpecification_Operation_isNull->setUnique(true);
	m_valueSpecification_Operation_isNull->setOrdered(false);
	
	m_valueSpecification_Operation_isNull->_setID(VALUESPECIFICATION_OPERATION_ISNULL);
	
	
	m_valueSpecification_Operation_realValue->setName("realValue");
	m_valueSpecification_Operation_realValue->setEType(types::typesPackage::eInstance()->getReal_Class());
	m_valueSpecification_Operation_realValue->setLowerBound(0);
	m_valueSpecification_Operation_realValue->setUpperBound(1);
	m_valueSpecification_Operation_realValue->setUnique(true);
	m_valueSpecification_Operation_realValue->setOrdered(false);
	
	m_valueSpecification_Operation_realValue->_setID(VALUESPECIFICATION_OPERATION_REALVALUE);
	
	
	m_valueSpecification_Operation_stringValue->setName("stringValue");
	m_valueSpecification_Operation_stringValue->setEType(types::typesPackage::eInstance()->getString_Class());
	m_valueSpecification_Operation_stringValue->setLowerBound(0);
	m_valueSpecification_Operation_stringValue->setUpperBound(1);
	m_valueSpecification_Operation_stringValue->setUnique(true);
	m_valueSpecification_Operation_stringValue->setOrdered(false);
	
	m_valueSpecification_Operation_stringValue->_setID(VALUESPECIFICATION_OPERATION_STRINGVALUE);
	
	
	m_valueSpecification_Operation_unlimitedValue->setName("unlimitedValue");
	m_valueSpecification_Operation_unlimitedValue->setEType(types::typesPackage::eInstance()->getUnlimitedNatural_Class());
	m_valueSpecification_Operation_unlimitedValue->setLowerBound(0);
	m_valueSpecification_Operation_unlimitedValue->setUpperBound(1);
	m_valueSpecification_Operation_unlimitedValue->setUnique(true);
	m_valueSpecification_Operation_unlimitedValue->setOrdered(false);
	
	m_valueSpecification_Operation_unlimitedValue->_setID(VALUESPECIFICATION_OPERATION_UNLIMITEDVALUE);
	
	
	
}

void umlPackageImpl::initializeValueSpecificationActionContent()
{
	m_valueSpecificationAction_Class->setName("ValueSpecificationAction");
	m_valueSpecificationAction_Class->setAbstract(false);
	m_valueSpecificationAction_Class->setInterface(false);
	
	m_valueSpecificationAction_Class->_setID(VALUESPECIFICATIONACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_valueSpecificationAction_Attribute_result->setName("result");
	m_valueSpecificationAction_Attribute_result->setEType(getOutputPin_Class());
	m_valueSpecificationAction_Attribute_result->setLowerBound(1);
	m_valueSpecificationAction_Attribute_result->setUpperBound(1);
	m_valueSpecificationAction_Attribute_result->setTransient(false);
	m_valueSpecificationAction_Attribute_result->setVolatile(false);
	m_valueSpecificationAction_Attribute_result->setChangeable(true);
	m_valueSpecificationAction_Attribute_result->setUnsettable(false);
	m_valueSpecificationAction_Attribute_result->setUnique(true);
	m_valueSpecificationAction_Attribute_result->setDerived(false);
	m_valueSpecificationAction_Attribute_result->setOrdered(false);
	m_valueSpecificationAction_Attribute_result->setContainment(true);
	m_valueSpecificationAction_Attribute_result->setResolveProxies(true);
	m_valueSpecificationAction_Attribute_result->setDefaultValueLiteral("");	
	m_valueSpecificationAction_Attribute_result->setEOpposite(uml::umlPackage::eInstance()->getOutputPin_Attribute_valueSpecificationAction());
	
	m_valueSpecificationAction_Attribute_result->_setID(VALUESPECIFICATIONACTION_ATTRIBUTE_RESULT);
	m_valueSpecificationAction_Attribute_value->setName("value");
	m_valueSpecificationAction_Attribute_value->setEType(getValueSpecification_Class());
	m_valueSpecificationAction_Attribute_value->setLowerBound(1);
	m_valueSpecificationAction_Attribute_value->setUpperBound(1);
	m_valueSpecificationAction_Attribute_value->setTransient(false);
	m_valueSpecificationAction_Attribute_value->setVolatile(false);
	m_valueSpecificationAction_Attribute_value->setChangeable(true);
	m_valueSpecificationAction_Attribute_value->setUnsettable(false);
	m_valueSpecificationAction_Attribute_value->setUnique(true);
	m_valueSpecificationAction_Attribute_value->setDerived(false);
	m_valueSpecificationAction_Attribute_value->setOrdered(false);
	m_valueSpecificationAction_Attribute_value->setContainment(true);
	m_valueSpecificationAction_Attribute_value->setResolveProxies(true);
	m_valueSpecificationAction_Attribute_value->setDefaultValueLiteral("");	
	m_valueSpecificationAction_Attribute_value->setEOpposite(uml::umlPackage::eInstance()->getValueSpecification_Attribute_valueSpecificationAction());
	
	m_valueSpecificationAction_Attribute_value->_setID(VALUESPECIFICATIONACTION_ATTRIBUTE_VALUE);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeVariableContent()
{
	m_variable_Class->setName("Variable");
	m_variable_Class->setAbstract(false);
	m_variable_Class->setInterface(false);
	
	m_variable_Class->_setID(VARIABLE_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_variable_Attribute_activityScope->setName("activityScope");
	m_variable_Attribute_activityScope->setEType(getActivity_Class());
	m_variable_Attribute_activityScope->setLowerBound(0);
	m_variable_Attribute_activityScope->setUpperBound(1);
	m_variable_Attribute_activityScope->setTransient(false);
	m_variable_Attribute_activityScope->setVolatile(false);
	m_variable_Attribute_activityScope->setChangeable(true);
	m_variable_Attribute_activityScope->setUnsettable(false);
	m_variable_Attribute_activityScope->setUnique(true);
	m_variable_Attribute_activityScope->setDerived(false);
	m_variable_Attribute_activityScope->setOrdered(false);
	m_variable_Attribute_activityScope->setContainment(false);
	m_variable_Attribute_activityScope->setResolveProxies(true);
	m_variable_Attribute_activityScope->setDefaultValueLiteral("");	
	m_variable_Attribute_activityScope->setEOpposite(uml::umlPackage::eInstance()->getActivity_Attribute_variable());
	
	m_variable_Attribute_activityScope->_setID(VARIABLE_ATTRIBUTE_ACTIVITYSCOPE);
	m_variable_Attribute_scope->setName("scope");
	m_variable_Attribute_scope->setEType(getStructuredActivityNode_Class());
	m_variable_Attribute_scope->setLowerBound(0);
	m_variable_Attribute_scope->setUpperBound(1);
	m_variable_Attribute_scope->setTransient(false);
	m_variable_Attribute_scope->setVolatile(false);
	m_variable_Attribute_scope->setChangeable(true);
	m_variable_Attribute_scope->setUnsettable(false);
	m_variable_Attribute_scope->setUnique(true);
	m_variable_Attribute_scope->setDerived(false);
	m_variable_Attribute_scope->setOrdered(false);
	m_variable_Attribute_scope->setContainment(false);
	m_variable_Attribute_scope->setResolveProxies(true);
	m_variable_Attribute_scope->setDefaultValueLiteral("");	
	m_variable_Attribute_scope->setEOpposite(uml::umlPackage::eInstance()->getStructuredActivityNode_Attribute_variable());
	
	m_variable_Attribute_scope->_setID(VARIABLE_ATTRIBUTE_SCOPE);
	
	/*
	 * EOperations
	 */
	m_variable_Operation_isAccessibleBy_Action->setName("isAccessibleBy");
	m_variable_Operation_isAccessibleBy_Action->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_variable_Operation_isAccessibleBy_Action->setLowerBound(1);
	m_variable_Operation_isAccessibleBy_Action->setUpperBound(1);
	m_variable_Operation_isAccessibleBy_Action->setUnique(true);
	m_variable_Operation_isAccessibleBy_Action->setOrdered(false);
	
	m_variable_Operation_isAccessibleBy_Action->_setID(VARIABLE_OPERATION_ISACCESSIBLEBY_ACTION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_variable_Operation_isAccessibleBy_Action);
		parameter->setName("a");
		parameter->setEType(getAction_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void umlPackageImpl::initializeVariableActionContent()
{
	m_variableAction_Class->setName("VariableAction");
	m_variableAction_Class->setAbstract(true);
	m_variableAction_Class->setInterface(false);
	
	m_variableAction_Class->_setID(VARIABLEACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_variableAction_Attribute_variable->setName("variable");
	m_variableAction_Attribute_variable->setEType(getVariable_Class());
	m_variableAction_Attribute_variable->setLowerBound(1);
	m_variableAction_Attribute_variable->setUpperBound(1);
	m_variableAction_Attribute_variable->setTransient(false);
	m_variableAction_Attribute_variable->setVolatile(false);
	m_variableAction_Attribute_variable->setChangeable(true);
	m_variableAction_Attribute_variable->setUnsettable(false);
	m_variableAction_Attribute_variable->setUnique(true);
	m_variableAction_Attribute_variable->setDerived(false);
	m_variableAction_Attribute_variable->setOrdered(false);
	m_variableAction_Attribute_variable->setContainment(false);
	m_variableAction_Attribute_variable->setResolveProxies(true);
	m_variableAction_Attribute_variable->setDefaultValueLiteral("");	
	
	m_variableAction_Attribute_variable->_setID(VARIABLEACTION_ATTRIBUTE_VARIABLE);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeVertexContent()
{
	m_vertex_Class->setName("Vertex");
	m_vertex_Class->setAbstract(true);
	m_vertex_Class->setInterface(false);
	
	m_vertex_Class->_setID(VERTEX_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_vertex_Attribute_container->setName("container");
	m_vertex_Attribute_container->setEType(getRegion_Class());
	m_vertex_Attribute_container->setLowerBound(0);
	m_vertex_Attribute_container->setUpperBound(1);
	m_vertex_Attribute_container->setTransient(false);
	m_vertex_Attribute_container->setVolatile(false);
	m_vertex_Attribute_container->setChangeable(true);
	m_vertex_Attribute_container->setUnsettable(false);
	m_vertex_Attribute_container->setUnique(true);
	m_vertex_Attribute_container->setDerived(false);
	m_vertex_Attribute_container->setOrdered(false);
	m_vertex_Attribute_container->setContainment(false);
	m_vertex_Attribute_container->setResolveProxies(true);
	m_vertex_Attribute_container->setDefaultValueLiteral("");	
	m_vertex_Attribute_container->setEOpposite(uml::umlPackage::eInstance()->getRegion_Attribute_subvertex());
	
	m_vertex_Attribute_container->_setID(VERTEX_ATTRIBUTE_CONTAINER);
	m_vertex_Attribute_incoming->setName("incoming");
	m_vertex_Attribute_incoming->setEType(getTransition_Class());
	m_vertex_Attribute_incoming->setLowerBound(0);
	m_vertex_Attribute_incoming->setUpperBound(-1);
	m_vertex_Attribute_incoming->setTransient(true);
	m_vertex_Attribute_incoming->setVolatile(true);
	m_vertex_Attribute_incoming->setChangeable(false);
	m_vertex_Attribute_incoming->setUnsettable(false);
	m_vertex_Attribute_incoming->setUnique(true);
	m_vertex_Attribute_incoming->setDerived(true);
	m_vertex_Attribute_incoming->setOrdered(false);
	m_vertex_Attribute_incoming->setContainment(false);
	m_vertex_Attribute_incoming->setResolveProxies(true);
	m_vertex_Attribute_incoming->setDefaultValueLiteral("");	
	
	m_vertex_Attribute_incoming->_setID(VERTEX_ATTRIBUTE_INCOMING);
	m_vertex_Attribute_outgoing->setName("outgoing");
	m_vertex_Attribute_outgoing->setEType(getTransition_Class());
	m_vertex_Attribute_outgoing->setLowerBound(0);
	m_vertex_Attribute_outgoing->setUpperBound(-1);
	m_vertex_Attribute_outgoing->setTransient(true);
	m_vertex_Attribute_outgoing->setVolatile(true);
	m_vertex_Attribute_outgoing->setChangeable(false);
	m_vertex_Attribute_outgoing->setUnsettable(false);
	m_vertex_Attribute_outgoing->setUnique(true);
	m_vertex_Attribute_outgoing->setDerived(true);
	m_vertex_Attribute_outgoing->setOrdered(false);
	m_vertex_Attribute_outgoing->setContainment(false);
	m_vertex_Attribute_outgoing->setResolveProxies(true);
	m_vertex_Attribute_outgoing->setDefaultValueLiteral("");	
	
	m_vertex_Attribute_outgoing->_setID(VERTEX_ATTRIBUTE_OUTGOING);
	
	/*
	 * EOperations
	 */
	m_vertex_Operation_containingStateMachine->setName("containingStateMachine");
	m_vertex_Operation_containingStateMachine->setEType(getStateMachine_Class());
	m_vertex_Operation_containingStateMachine->setLowerBound(1);
	m_vertex_Operation_containingStateMachine->setUpperBound(1);
	m_vertex_Operation_containingStateMachine->setUnique(true);
	m_vertex_Operation_containingStateMachine->setOrdered(false);
	
	m_vertex_Operation_containingStateMachine->_setID(VERTEX_OPERATION_CONTAININGSTATEMACHINE);
	
	
	m_vertex_Operation_getIncomings->setName("getIncomings");
	m_vertex_Operation_getIncomings->setEType(getTransition_Class());
	m_vertex_Operation_getIncomings->setLowerBound(0);
	m_vertex_Operation_getIncomings->setUpperBound(-1);
	m_vertex_Operation_getIncomings->setUnique(true);
	m_vertex_Operation_getIncomings->setOrdered(false);
	
	m_vertex_Operation_getIncomings->_setID(VERTEX_OPERATION_GETINCOMINGS);
	
	
	m_vertex_Operation_getOutgoings->setName("getOutgoings");
	m_vertex_Operation_getOutgoings->setEType(getTransition_Class());
	m_vertex_Operation_getOutgoings->setLowerBound(0);
	m_vertex_Operation_getOutgoings->setUpperBound(-1);
	m_vertex_Operation_getOutgoings->setUnique(true);
	m_vertex_Operation_getOutgoings->setOrdered(false);
	
	m_vertex_Operation_getOutgoings->_setID(VERTEX_OPERATION_GETOUTGOINGS);
	
	
	m_vertex_Operation_isContainedInRegion_Region->setName("isContainedInRegion");
	m_vertex_Operation_isContainedInRegion_Region->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_vertex_Operation_isContainedInRegion_Region->setLowerBound(1);
	m_vertex_Operation_isContainedInRegion_Region->setUpperBound(1);
	m_vertex_Operation_isContainedInRegion_Region->setUnique(true);
	m_vertex_Operation_isContainedInRegion_Region->setOrdered(false);
	
	m_vertex_Operation_isContainedInRegion_Region->_setID(VERTEX_OPERATION_ISCONTAINEDINREGION_REGION);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_vertex_Operation_isContainedInRegion_Region);
		parameter->setName("r");
		parameter->setEType(getRegion_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	m_vertex_Operation_isContainedInState_State->setName("isContainedInState");
	m_vertex_Operation_isContainedInState_State->setEType(types::typesPackage::eInstance()->getBoolean_Class());
	m_vertex_Operation_isContainedInState_State->setLowerBound(1);
	m_vertex_Operation_isContainedInState_State->setUpperBound(1);
	m_vertex_Operation_isContainedInState_State->setUnique(true);
	m_vertex_Operation_isContainedInState_State->setOrdered(false);
	
	m_vertex_Operation_isContainedInState_State->_setID(VERTEX_OPERATION_ISCONTAINEDINSTATE_STATE);
	
	{
		std::shared_ptr<ecore::EParameter> parameter = ecore::ecoreFactory::eInstance()->createEParameter_as_eParameters_in_EOperation(m_vertex_Operation_isContainedInState_State);
		parameter->setName("s");
		parameter->setEType(getState_Class());
		parameter->setLowerBound(0);
		parameter->setUpperBound(1);
		parameter->setUnique(true);
		parameter->setOrdered(true);
	}
	
	
}

void umlPackageImpl::initializeWriteLinkActionContent()
{
	m_writeLinkAction_Class->setName("WriteLinkAction");
	m_writeLinkAction_Class->setAbstract(true);
	m_writeLinkAction_Class->setInterface(false);
	
	m_writeLinkAction_Class->_setID(WRITELINKACTION_CLASS);
	
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

void umlPackageImpl::initializeWriteStructuralFeatureActionContent()
{
	m_writeStructuralFeatureAction_Class->setName("WriteStructuralFeatureAction");
	m_writeStructuralFeatureAction_Class->setAbstract(true);
	m_writeStructuralFeatureAction_Class->setInterface(false);
	
	m_writeStructuralFeatureAction_Class->_setID(WRITESTRUCTURALFEATUREACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_writeStructuralFeatureAction_Attribute_result->setName("result");
	m_writeStructuralFeatureAction_Attribute_result->setEType(getOutputPin_Class());
	m_writeStructuralFeatureAction_Attribute_result->setLowerBound(0);
	m_writeStructuralFeatureAction_Attribute_result->setUpperBound(1);
	m_writeStructuralFeatureAction_Attribute_result->setTransient(false);
	m_writeStructuralFeatureAction_Attribute_result->setVolatile(false);
	m_writeStructuralFeatureAction_Attribute_result->setChangeable(true);
	m_writeStructuralFeatureAction_Attribute_result->setUnsettable(false);
	m_writeStructuralFeatureAction_Attribute_result->setUnique(true);
	m_writeStructuralFeatureAction_Attribute_result->setDerived(false);
	m_writeStructuralFeatureAction_Attribute_result->setOrdered(false);
	m_writeStructuralFeatureAction_Attribute_result->setContainment(true);
	m_writeStructuralFeatureAction_Attribute_result->setResolveProxies(true);
	m_writeStructuralFeatureAction_Attribute_result->setDefaultValueLiteral("");	
	m_writeStructuralFeatureAction_Attribute_result->setEOpposite(uml::umlPackage::eInstance()->getOutputPin_Attribute_writeStructuralFeatureAction());
	
	m_writeStructuralFeatureAction_Attribute_result->_setID(WRITESTRUCTURALFEATUREACTION_ATTRIBUTE_RESULT);
	m_writeStructuralFeatureAction_Attribute_value->setName("value");
	m_writeStructuralFeatureAction_Attribute_value->setEType(getInputPin_Class());
	m_writeStructuralFeatureAction_Attribute_value->setLowerBound(0);
	m_writeStructuralFeatureAction_Attribute_value->setUpperBound(1);
	m_writeStructuralFeatureAction_Attribute_value->setTransient(false);
	m_writeStructuralFeatureAction_Attribute_value->setVolatile(false);
	m_writeStructuralFeatureAction_Attribute_value->setChangeable(true);
	m_writeStructuralFeatureAction_Attribute_value->setUnsettable(false);
	m_writeStructuralFeatureAction_Attribute_value->setUnique(true);
	m_writeStructuralFeatureAction_Attribute_value->setDerived(false);
	m_writeStructuralFeatureAction_Attribute_value->setOrdered(false);
	m_writeStructuralFeatureAction_Attribute_value->setContainment(true);
	m_writeStructuralFeatureAction_Attribute_value->setResolveProxies(true);
	m_writeStructuralFeatureAction_Attribute_value->setDefaultValueLiteral("");	
	m_writeStructuralFeatureAction_Attribute_value->setEOpposite(uml::umlPackage::eInstance()->getInputPin_Attribute_writeStructuralFeatureAction());
	
	m_writeStructuralFeatureAction_Attribute_value->_setID(WRITESTRUCTURALFEATUREACTION_ATTRIBUTE_VALUE);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializeWriteVariableActionContent()
{
	m_writeVariableAction_Class->setName("WriteVariableAction");
	m_writeVariableAction_Class->setAbstract(true);
	m_writeVariableAction_Class->setInterface(false);
	
	m_writeVariableAction_Class->_setID(WRITEVARIABLEACTION_CLASS);
	
	/*
	 * EAttributes
	 */
	
	/*
	 * EReferences
	 */
	m_writeVariableAction_Attribute_value->setName("value");
	m_writeVariableAction_Attribute_value->setEType(getInputPin_Class());
	m_writeVariableAction_Attribute_value->setLowerBound(0);
	m_writeVariableAction_Attribute_value->setUpperBound(1);
	m_writeVariableAction_Attribute_value->setTransient(false);
	m_writeVariableAction_Attribute_value->setVolatile(false);
	m_writeVariableAction_Attribute_value->setChangeable(true);
	m_writeVariableAction_Attribute_value->setUnsettable(false);
	m_writeVariableAction_Attribute_value->setUnique(true);
	m_writeVariableAction_Attribute_value->setDerived(false);
	m_writeVariableAction_Attribute_value->setOrdered(false);
	m_writeVariableAction_Attribute_value->setContainment(true);
	m_writeVariableAction_Attribute_value->setResolveProxies(true);
	m_writeVariableAction_Attribute_value->setDefaultValueLiteral("");	
	
	m_writeVariableAction_Attribute_value->_setID(WRITEVARIABLEACTION_ATTRIBUTE_VALUE);
	
	/*
	 * EOperations
	 */
	
}

void umlPackageImpl::initializePackageEDataTypes()
{
	m_aggregationKind_Class->setName("AggregationKind");
	m_callConcurrencyKind_Class->setName("CallConcurrencyKind");
	m_connectorKind_Class->setName("ConnectorKind");
	m_expansionKind_Class->setName("ExpansionKind");
	m_interactionOperatorKind_Class->setName("InteractionOperatorKind");
	m_messageKind_Class->setName("MessageKind");
	m_messageSort_Class->setName("MessageSort");
	m_objectNodeOrderingKind_Class->setName("ObjectNodeOrderingKind");
	m_parameterDirectionKind_Class->setName("ParameterDirectionKind");
	m_parameterEffectKind_Class->setName("ParameterEffectKind");
	m_pseudostateKind_Class->setName("PseudostateKind");
	m_transitionKind_Class->setName("TransitionKind");
	m_visibilityKind_Class->setName("VisibilityKind");
	
}

