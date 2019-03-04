#include "uml/impl/UmlPackageImpl.hpp"

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

//metamodel factory
#include "uml/UmlFactory.hpp"

//depending model packages
#include "ecore/EcorePackage.hpp"
#include "types/TypesPackage.hpp"

using namespace uml;

bool UmlPackageImpl::isInited = false;

UmlPackageImpl::UmlPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( UmlFactory::eInstance()));
}

UmlPackageImpl::~UmlPackageImpl()
{
}

UmlPackage* UmlPackageImpl::create()
{
	if (isInited)
	{
		return UmlPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    UmlPackageImpl * metaModelPackage = new UmlPackageImpl();
    return metaModelPackage;
}

void UmlPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}

// Begin Class Abstraction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getAbstraction_EClass() const
{
	return m_abstraction_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getAbstraction_EReference_mapping() const
{
	return m_abstraction_EReference_mapping;
}


// End Class Abstraction

// Begin Class AcceptCallAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getAcceptCallAction_EClass() const
{
	return m_acceptCallAction_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getAcceptCallAction_EReference_returnInformation() const
{
	return m_acceptCallAction_EReference_returnInformation;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAcceptCallAction_EOperation_result_pins_EDiagnosticChain_EMap() const
{
	return m_acceptCallAction_EOperation_result_pins_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAcceptCallAction_EOperation_trigger_call_event_EDiagnosticChain_EMap() const
{
	return m_acceptCallAction_EOperation_trigger_call_event_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAcceptCallAction_EOperation_unmarshall_EDiagnosticChain_EMap() const
{
	return m_acceptCallAction_EOperation_unmarshall_EDiagnosticChain_EMap;
}

// End Class AcceptCallAction

// Begin Class AcceptEventAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getAcceptEventAction_EClass() const
{
	return m_acceptEventAction_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getAcceptEventAction_EAttribute_isUnmarshall() const
{
	return m_acceptEventAction_EAttribute_isUnmarshall;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getAcceptEventAction_EReference_result() const
{
	return m_acceptEventAction_EReference_result;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getAcceptEventAction_EReference_trigger() const
{
	return m_acceptEventAction_EReference_trigger;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAcceptEventAction_EOperation_conforming_type_EDiagnosticChain_EMap() const
{
	return m_acceptEventAction_EOperation_conforming_type_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAcceptEventAction_EOperation_no_input_pins_EDiagnosticChain_EMap() const
{
	return m_acceptEventAction_EOperation_no_input_pins_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAcceptEventAction_EOperation_no_output_pins_EDiagnosticChain_EMap() const
{
	return m_acceptEventAction_EOperation_no_output_pins_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAcceptEventAction_EOperation_one_output_pin_EDiagnosticChain_EMap() const
{
	return m_acceptEventAction_EOperation_one_output_pin_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAcceptEventAction_EOperation_unmarshall_signal_events_EDiagnosticChain_EMap() const
{
	return m_acceptEventAction_EOperation_unmarshall_signal_events_EDiagnosticChain_EMap;
}

// End Class AcceptEventAction

// Begin Class Action
std::shared_ptr<ecore::EClass> UmlPackageImpl::getAction_EClass() const
{
	return m_action_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getAction_EAttribute_isLocallyReentrant() const
{
	return m_action_EAttribute_isLocallyReentrant;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getAction_EReference_context() const
{
	return m_action_EReference_context;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getAction_EReference_input() const
{
	return m_action_EReference_input;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getAction_EReference_localPostcondition() const
{
	return m_action_EReference_localPostcondition;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getAction_EReference_localPrecondition() const
{
	return m_action_EReference_localPrecondition;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getAction_EReference_output() const
{
	return m_action_EReference_output;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAction_EOperation_allActions() const
{
	return m_action_EOperation_allActions;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAction_EOperation_allOwnedNodes() const
{
	return m_action_EOperation_allOwnedNodes;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAction_EOperation_containingBehavior() const
{
	return m_action_EOperation_containingBehavior;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAction_EOperation_getContext() const
{
	return m_action_EOperation_getContext;
}

// End Class Action

// Begin Class ActionExecutionSpecification
std::shared_ptr<ecore::EClass> UmlPackageImpl::getActionExecutionSpecification_EClass() const
{
	return m_actionExecutionSpecification_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getActionExecutionSpecification_EReference_action() const
{
	return m_actionExecutionSpecification_EReference_action;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActionExecutionSpecification_EOperation_action_referenced_EDiagnosticChain_EMap() const
{
	return m_actionExecutionSpecification_EOperation_action_referenced_EDiagnosticChain_EMap;
}

// End Class ActionExecutionSpecification

// Begin Class ActionInputPin
std::shared_ptr<ecore::EClass> UmlPackageImpl::getActionInputPin_EClass() const
{
	return m_actionInputPin_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getActionInputPin_EReference_fromAction() const
{
	return m_actionInputPin_EReference_fromAction;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActionInputPin_EOperation_input_pin_EDiagnosticChain_EMap() const
{
	return m_actionInputPin_EOperation_input_pin_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActionInputPin_EOperation_no_control_or_object_flow_EDiagnosticChain_EMap() const
{
	return m_actionInputPin_EOperation_no_control_or_object_flow_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActionInputPin_EOperation_one_output_pin_EDiagnosticChain_EMap() const
{
	return m_actionInputPin_EOperation_one_output_pin_EDiagnosticChain_EMap;
}

// End Class ActionInputPin

// Begin Class Activity
std::shared_ptr<ecore::EClass> UmlPackageImpl::getActivity_EClass() const
{
	return m_activity_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getActivity_EAttribute_isReadOnly() const
{
	return m_activity_EAttribute_isReadOnly;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getActivity_EAttribute_isSingleExecution() const
{
	return m_activity_EAttribute_isSingleExecution;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivity_EReference_edge() const
{
	return m_activity_EReference_edge;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivity_EReference_group() const
{
	return m_activity_EReference_group;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivity_EReference_node() const
{
	return m_activity_EReference_node;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivity_EReference_ownedGroup() const
{
	return m_activity_EReference_ownedGroup;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivity_EReference_ownedNode() const
{
	return m_activity_EReference_ownedNode;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivity_EReference_partition() const
{
	return m_activity_EReference_partition;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivity_EReference_structuredNode() const
{
	return m_activity_EReference_structuredNode;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivity_EReference_variable() const
{
	return m_activity_EReference_variable;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivity_EOperation_maximum_one_parameter_node_EDiagnosticChain_EMap() const
{
	return m_activity_EOperation_maximum_one_parameter_node_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivity_EOperation_maximum_two_parameter_nodes_EDiagnosticChain_EMap() const
{
	return m_activity_EOperation_maximum_two_parameter_nodes_EDiagnosticChain_EMap;
}

// End Class Activity

// Begin Class ActivityContent
std::shared_ptr<ecore::EClass> UmlPackageImpl::getActivityContent_EClass() const
{
	return m_activityContent_EClass;
}



std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivityContent_EOperation_containingActivity() const
{
	return m_activityContent_EOperation_containingActivity;
}

// End Class ActivityContent

// Begin Class ActivityEdge
std::shared_ptr<ecore::EClass> UmlPackageImpl::getActivityEdge_EClass() const
{
	return m_activityEdge_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityEdge_EReference_activity() const
{
	return m_activityEdge_EReference_activity;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityEdge_EReference_guard() const
{
	return m_activityEdge_EReference_guard;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityEdge_EReference_inGroup() const
{
	return m_activityEdge_EReference_inGroup;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityEdge_EReference_inPartition() const
{
	return m_activityEdge_EReference_inPartition;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityEdge_EReference_inStructuredNode() const
{
	return m_activityEdge_EReference_inStructuredNode;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityEdge_EReference_interrupts() const
{
	return m_activityEdge_EReference_interrupts;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityEdge_EReference_redefinedEdge() const
{
	return m_activityEdge_EReference_redefinedEdge;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityEdge_EReference_source() const
{
	return m_activityEdge_EReference_source;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityEdge_EReference_target() const
{
	return m_activityEdge_EReference_target;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityEdge_EReference_weight() const
{
	return m_activityEdge_EReference_weight;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivityEdge_EOperation_source_and_target_EDiagnosticChain_EMap() const
{
	return m_activityEdge_EOperation_source_and_target_EDiagnosticChain_EMap;
}

// End Class ActivityEdge

// Begin Class ActivityFinalNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getActivityFinalNode_EClass() const
{
	return m_activityFinalNode_EClass;
}




// End Class ActivityFinalNode

// Begin Class ActivityGroup
std::shared_ptr<ecore::EClass> UmlPackageImpl::getActivityGroup_EClass() const
{
	return m_activityGroup_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityGroup_EReference_containedEdge() const
{
	return m_activityGroup_EReference_containedEdge;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityGroup_EReference_containedNode() const
{
	return m_activityGroup_EReference_containedNode;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityGroup_EReference_inActivity() const
{
	return m_activityGroup_EReference_inActivity;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityGroup_EReference_subgroup() const
{
	return m_activityGroup_EReference_subgroup;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityGroup_EReference_superGroup() const
{
	return m_activityGroup_EReference_superGroup;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivityGroup_EOperation_nodes_and_edges_EDiagnosticChain_EMap() const
{
	return m_activityGroup_EOperation_nodes_and_edges_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivityGroup_EOperation_not_contained_EDiagnosticChain_EMap() const
{
	return m_activityGroup_EOperation_not_contained_EDiagnosticChain_EMap;
}

// End Class ActivityGroup

// Begin Class ActivityNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getActivityNode_EClass() const
{
	return m_activityNode_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityNode_EReference_activity() const
{
	return m_activityNode_EReference_activity;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityNode_EReference_inGroup() const
{
	return m_activityNode_EReference_inGroup;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityNode_EReference_inInterruptibleRegion() const
{
	return m_activityNode_EReference_inInterruptibleRegion;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityNode_EReference_inPartition() const
{
	return m_activityNode_EReference_inPartition;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityNode_EReference_inStructuredNode() const
{
	return m_activityNode_EReference_inStructuredNode;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityNode_EReference_incoming() const
{
	return m_activityNode_EReference_incoming;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityNode_EReference_outgoing() const
{
	return m_activityNode_EReference_outgoing;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityNode_EReference_redefinedNode() const
{
	return m_activityNode_EReference_redefinedNode;
}


// End Class ActivityNode

// Begin Class ActivityParameterNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getActivityParameterNode_EClass() const
{
	return m_activityParameterNode_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityParameterNode_EReference_parameter() const
{
	return m_activityParameterNode_EReference_parameter;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivityParameterNode_EOperation_has_parameters_EDiagnosticChain_EMap() const
{
	return m_activityParameterNode_EOperation_has_parameters_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivityParameterNode_EOperation_no_edges_EDiagnosticChain_EMap() const
{
	return m_activityParameterNode_EOperation_no_edges_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivityParameterNode_EOperation_no_incoming_edges_EDiagnosticChain_EMap() const
{
	return m_activityParameterNode_EOperation_no_incoming_edges_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivityParameterNode_EOperation_no_outgoing_edges_EDiagnosticChain_EMap() const
{
	return m_activityParameterNode_EOperation_no_outgoing_edges_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivityParameterNode_EOperation_same_type_EDiagnosticChain_EMap() const
{
	return m_activityParameterNode_EOperation_same_type_EDiagnosticChain_EMap;
}

// End Class ActivityParameterNode

// Begin Class ActivityPartition
std::shared_ptr<ecore::EClass> UmlPackageImpl::getActivityPartition_EClass() const
{
	return m_activityPartition_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getActivityPartition_EAttribute_isDimension() const
{
	return m_activityPartition_EAttribute_isDimension;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getActivityPartition_EAttribute_isExternal() const
{
	return m_activityPartition_EAttribute_isExternal;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityPartition_EReference_edge() const
{
	return m_activityPartition_EReference_edge;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityPartition_EReference_node() const
{
	return m_activityPartition_EReference_node;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityPartition_EReference_represents() const
{
	return m_activityPartition_EReference_represents;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityPartition_EReference_subpartition() const
{
	return m_activityPartition_EReference_subpartition;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityPartition_EReference_superPartition() const
{
	return m_activityPartition_EReference_superPartition;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivityPartition_EOperation_dimension_not_contained_EDiagnosticChain_EMap() const
{
	return m_activityPartition_EOperation_dimension_not_contained_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivityPartition_EOperation_represents_classifier_EDiagnosticChain_EMap() const
{
	return m_activityPartition_EOperation_represents_classifier_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivityPartition_EOperation_represents_property_EDiagnosticChain_EMap() const
{
	return m_activityPartition_EOperation_represents_property_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivityPartition_EOperation_represents_property_and_is_contained_EDiagnosticChain_EMap() const
{
	return m_activityPartition_EOperation_represents_property_and_is_contained_EDiagnosticChain_EMap;
}

// End Class ActivityPartition

// Begin Class Actor
std::shared_ptr<ecore::EClass> UmlPackageImpl::getActor_EClass() const
{
	return m_actor_EClass;
}



std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActor_EOperation_associations_EDiagnosticChain_EMap() const
{
	return m_actor_EOperation_associations_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActor_EOperation_must_have_name_EDiagnosticChain_EMap() const
{
	return m_actor_EOperation_must_have_name_EDiagnosticChain_EMap;
}

// End Class Actor

// Begin Class AddStructuralFeatureValueAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getAddStructuralFeatureValueAction_EClass() const
{
	return m_addStructuralFeatureValueAction_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getAddStructuralFeatureValueAction_EAttribute_isReplaceAll() const
{
	return m_addStructuralFeatureValueAction_EAttribute_isReplaceAll;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getAddStructuralFeatureValueAction_EReference_insertAt() const
{
	return m_addStructuralFeatureValueAction_EReference_insertAt;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAddStructuralFeatureValueAction_EOperation_insertAt_pin_EDiagnosticChain_EMap() const
{
	return m_addStructuralFeatureValueAction_EOperation_insertAt_pin_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAddStructuralFeatureValueAction_EOperation_required_value_EDiagnosticChain_EMap() const
{
	return m_addStructuralFeatureValueAction_EOperation_required_value_EDiagnosticChain_EMap;
}

// End Class AddStructuralFeatureValueAction

// Begin Class AddVariableValueAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getAddVariableValueAction_EClass() const
{
	return m_addVariableValueAction_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getAddVariableValueAction_EAttribute_isReplaceAll() const
{
	return m_addVariableValueAction_EAttribute_isReplaceAll;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getAddVariableValueAction_EReference_insertAt() const
{
	return m_addVariableValueAction_EReference_insertAt;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAddVariableValueAction_EOperation_insertAt_pin_EDiagnosticChain_EMap() const
{
	return m_addVariableValueAction_EOperation_insertAt_pin_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAddVariableValueAction_EOperation_required_value_EDiagnosticChain_EMap() const
{
	return m_addVariableValueAction_EOperation_required_value_EDiagnosticChain_EMap;
}

// End Class AddVariableValueAction

// Begin Class AnyReceiveEvent
std::shared_ptr<ecore::EClass> UmlPackageImpl::getAnyReceiveEvent_EClass() const
{
	return m_anyReceiveEvent_EClass;
}




// End Class AnyReceiveEvent

// Begin Class Artifact
std::shared_ptr<ecore::EClass> UmlPackageImpl::getArtifact_EClass() const
{
	return m_artifact_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getArtifact_EAttribute_fileName() const
{
	return m_artifact_EAttribute_fileName;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getArtifact_EReference_manifestation() const
{
	return m_artifact_EReference_manifestation;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getArtifact_EReference_nestedArtifact() const
{
	return m_artifact_EReference_nestedArtifact;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getArtifact_EReference_ownedAttribute() const
{
	return m_artifact_EReference_ownedAttribute;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getArtifact_EReference_ownedOperation() const
{
	return m_artifact_EReference_ownedOperation;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getArtifact_EOperation_createOwnedAttribute_String_UnlimitedNatural() const
{
	return m_artifact_EOperation_createOwnedAttribute_String_UnlimitedNatural;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getArtifact_EOperation_createOwnedOperation_String_Type() const
{
	return m_artifact_EOperation_createOwnedOperation_String_Type;
}

// End Class Artifact

// Begin Class Association
std::shared_ptr<ecore::EClass> UmlPackageImpl::getAssociation_EClass() const
{
	return m_association_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getAssociation_EAttribute_isDerived() const
{
	return m_association_EAttribute_isDerived;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getAssociation_EReference_endType() const
{
	return m_association_EReference_endType;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getAssociation_EReference_memberEnd() const
{
	return m_association_EReference_memberEnd;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getAssociation_EReference_navigableOwnedEnd() const
{
	return m_association_EReference_navigableOwnedEnd;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getAssociation_EReference_ownedEnd() const
{
	return m_association_EReference_ownedEnd;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAssociation_EOperation_association_ends_EDiagnosticChain_EMap() const
{
	return m_association_EOperation_association_ends_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAssociation_EOperation_binary_associations_EDiagnosticChain_EMap() const
{
	return m_association_EOperation_binary_associations_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAssociation_EOperation_ends_must_be_typed_EDiagnosticChain_EMap() const
{
	return m_association_EOperation_ends_must_be_typed_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAssociation_EOperation_getEndTypes() const
{
	return m_association_EOperation_getEndTypes;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAssociation_EOperation_isBinary() const
{
	return m_association_EOperation_isBinary;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAssociation_EOperation_specialized_end_number_EDiagnosticChain_EMap() const
{
	return m_association_EOperation_specialized_end_number_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAssociation_EOperation_specialized_end_types_EDiagnosticChain_EMap() const
{
	return m_association_EOperation_specialized_end_types_EDiagnosticChain_EMap;
}

// End Class Association

// Begin Class AssociationClass
std::shared_ptr<ecore::EClass> UmlPackageImpl::getAssociationClass_EClass() const
{
	return m_associationClass_EClass;
}



std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAssociationClass_EOperation_cannot_be_defined_EDiagnosticChain_EMap() const
{
	return m_associationClass_EOperation_cannot_be_defined_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAssociationClass_EOperation_disjoint_attributes_ends_EDiagnosticChain_EMap() const
{
	return m_associationClass_EOperation_disjoint_attributes_ends_EDiagnosticChain_EMap;
}

// End Class AssociationClass

// Begin Class Behavior
std::shared_ptr<ecore::EClass> UmlPackageImpl::getBehavior_EClass() const
{
	return m_behavior_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getBehavior_EAttribute_isReentrant() const
{
	return m_behavior_EAttribute_isReentrant;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavior_EReference_behavioredClassifier() const
{
	return m_behavior_EReference_behavioredClassifier;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavior_EReference_context() const
{
	return m_behavior_EReference_context;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavior_EReference_ownedParameter() const
{
	return m_behavior_EReference_ownedParameter;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavior_EReference_ownedParameterSet() const
{
	return m_behavior_EReference_ownedParameterSet;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavior_EReference_postcondition() const
{
	return m_behavior_EReference_postcondition;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavior_EReference_precondition() const
{
	return m_behavior_EReference_precondition;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavior_EReference_redefinedBehavior() const
{
	return m_behavior_EReference_redefinedBehavior;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavior_EReference_specification() const
{
	return m_behavior_EReference_specification;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavior_EOperation_behavioredClassifier_Element() const
{
	return m_behavior_EOperation_behavioredClassifier_Element;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavior_EOperation_feature_of_context_classifier_EDiagnosticChain_EMap() const
{
	return m_behavior_EOperation_feature_of_context_classifier_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavior_EOperation_getContext() const
{
	return m_behavior_EOperation_getContext;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavior_EOperation_inputParameters() const
{
	return m_behavior_EOperation_inputParameters;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavior_EOperation_most_one_behavior_EDiagnosticChain_EMap() const
{
	return m_behavior_EOperation_most_one_behavior_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavior_EOperation_outputParameters() const
{
	return m_behavior_EOperation_outputParameters;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavior_EOperation_parameters_match_EDiagnosticChain_EMap() const
{
	return m_behavior_EOperation_parameters_match_EDiagnosticChain_EMap;
}

// End Class Behavior

// Begin Class BehaviorExecutionSpecification
std::shared_ptr<ecore::EClass> UmlPackageImpl::getBehaviorExecutionSpecification_EClass() const
{
	return m_behaviorExecutionSpecification_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehaviorExecutionSpecification_EReference_behavior() const
{
	return m_behaviorExecutionSpecification_EReference_behavior;
}


// End Class BehaviorExecutionSpecification

// Begin Class BehavioralFeature
std::shared_ptr<ecore::EClass> UmlPackageImpl::getBehavioralFeature_EClass() const
{
	return m_behavioralFeature_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getBehavioralFeature_EAttribute_concurrency() const
{
	return m_behavioralFeature_EAttribute_concurrency;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getBehavioralFeature_EAttribute_isAbstract() const
{
	return m_behavioralFeature_EAttribute_isAbstract;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavioralFeature_EReference_method() const
{
	return m_behavioralFeature_EReference_method;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavioralFeature_EReference_ownedParameter() const
{
	return m_behavioralFeature_EReference_ownedParameter;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavioralFeature_EReference_ownedParameterSet() const
{
	return m_behavioralFeature_EReference_ownedParameterSet;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavioralFeature_EReference_raisedException() const
{
	return m_behavioralFeature_EReference_raisedException;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavioralFeature_EOperation_abstract_no_method_EDiagnosticChain_EMap() const
{
	return m_behavioralFeature_EOperation_abstract_no_method_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavioralFeature_EOperation_createReturnResult_String_Type() const
{
	return m_behavioralFeature_EOperation_createReturnResult_String_Type;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavioralFeature_EOperation_inputParameters() const
{
	return m_behavioralFeature_EOperation_inputParameters;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavioralFeature_EOperation_outputParameters() const
{
	return m_behavioralFeature_EOperation_outputParameters;
}

// End Class BehavioralFeature

// Begin Class BehavioredClassifier
std::shared_ptr<ecore::EClass> UmlPackageImpl::getBehavioredClassifier_EClass() const
{
	return m_behavioredClassifier_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavioredClassifier_EReference_classifierBehavior() const
{
	return m_behavioredClassifier_EReference_classifierBehavior;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavioredClassifier_EReference_interfaceRealization() const
{
	return m_behavioredClassifier_EReference_interfaceRealization;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavioredClassifier_EReference_ownedBehavior() const
{
	return m_behavioredClassifier_EReference_ownedBehavior;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavioredClassifier_EOperation_class_behavior_EDiagnosticChain_EMap() const
{
	return m_behavioredClassifier_EOperation_class_behavior_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavioredClassifier_EOperation_getAllImplementedInterfaces() const
{
	return m_behavioredClassifier_EOperation_getAllImplementedInterfaces;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavioredClassifier_EOperation_getImplementedInterfaces() const
{
	return m_behavioredClassifier_EOperation_getImplementedInterfaces;
}

// End Class BehavioredClassifier

// Begin Class BroadcastSignalAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getBroadcastSignalAction_EClass() const
{
	return m_broadcastSignalAction_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getBroadcastSignalAction_EReference_signal() const
{
	return m_broadcastSignalAction_EReference_signal;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBroadcastSignalAction_EOperation_no_onport_EDiagnosticChain_EMap() const
{
	return m_broadcastSignalAction_EOperation_no_onport_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBroadcastSignalAction_EOperation_number_of_arguments_EDiagnosticChain_EMap() const
{
	return m_broadcastSignalAction_EOperation_number_of_arguments_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBroadcastSignalAction_EOperation_type_ordering_multiplicity_EDiagnosticChain_EMap() const
{
	return m_broadcastSignalAction_EOperation_type_ordering_multiplicity_EDiagnosticChain_EMap;
}

// End Class BroadcastSignalAction

// Begin Class CallAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getCallAction_EClass() const
{
	return m_callAction_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getCallAction_EAttribute_isSynchronous() const
{
	return m_callAction_EAttribute_isSynchronous;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getCallAction_EReference_result() const
{
	return m_callAction_EReference_result;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCallAction_EOperation_argument_pins_EDiagnosticChain_EMap() const
{
	return m_callAction_EOperation_argument_pins_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCallAction_EOperation_inputParameters() const
{
	return m_callAction_EOperation_inputParameters;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCallAction_EOperation_outputParameters() const
{
	return m_callAction_EOperation_outputParameters;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCallAction_EOperation_result_pins_EDiagnosticChain_EMap() const
{
	return m_callAction_EOperation_result_pins_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCallAction_EOperation_synchronous_call_EDiagnosticChain_EMap() const
{
	return m_callAction_EOperation_synchronous_call_EDiagnosticChain_EMap;
}

// End Class CallAction

// Begin Class CallBehaviorAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getCallBehaviorAction_EClass() const
{
	return m_callBehaviorAction_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getCallBehaviorAction_EReference_behavior() const
{
	return m_callBehaviorAction_EReference_behavior;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCallBehaviorAction_EOperation_no_onport_EDiagnosticChain_EMap() const
{
	return m_callBehaviorAction_EOperation_no_onport_EDiagnosticChain_EMap;
}

// End Class CallBehaviorAction

// Begin Class CallEvent
std::shared_ptr<ecore::EClass> UmlPackageImpl::getCallEvent_EClass() const
{
	return m_callEvent_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getCallEvent_EReference_operation() const
{
	return m_callEvent_EReference_operation;
}


// End Class CallEvent

// Begin Class CallOperationAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getCallOperationAction_EClass() const
{
	return m_callOperationAction_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getCallOperationAction_EReference_operation() const
{
	return m_callOperationAction_EReference_operation;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getCallOperationAction_EReference_target() const
{
	return m_callOperationAction_EReference_target;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCallOperationAction_EOperation_type_target_pin_EDiagnosticChain_EMap() const
{
	return m_callOperationAction_EOperation_type_target_pin_EDiagnosticChain_EMap;
}

// End Class CallOperationAction

// Begin Class CentralBufferNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getCentralBufferNode_EClass() const
{
	return m_centralBufferNode_EClass;
}




// End Class CentralBufferNode

// Begin Class ChangeEvent
std::shared_ptr<ecore::EClass> UmlPackageImpl::getChangeEvent_EClass() const
{
	return m_changeEvent_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getChangeEvent_EReference_changeExpression() const
{
	return m_changeEvent_EReference_changeExpression;
}


// End Class ChangeEvent

// Begin Class Class
std::shared_ptr<ecore::EClass> UmlPackageImpl::getClass_EClass() const
{
	return m_class_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getClass_EAttribute_isActive() const
{
	return m_class_EAttribute_isActive;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getClass_EReference_extension() const
{
	return m_class_EReference_extension;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClass_EReference_nestedClassifier() const
{
	return m_class_EReference_nestedClassifier;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClass_EReference_ownedOperation() const
{
	return m_class_EReference_ownedOperation;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClass_EReference_ownedReception() const
{
	return m_class_EReference_ownedReception;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClass_EReference_superClass() const
{
	return m_class_EReference_superClass;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClass_EOperation_createOwnedOperation_String_Type() const
{
	return m_class_EOperation_createOwnedOperation_String_Type;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClass_EOperation_getExtensions() const
{
	return m_class_EOperation_getExtensions;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClass_EOperation_getSuperClasses() const
{
	return m_class_EOperation_getSuperClasses;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClass_EOperation_isMetaclass() const
{
	return m_class_EOperation_isMetaclass;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClass_EOperation_passive_class_EDiagnosticChain_EMap() const
{
	return m_class_EOperation_passive_class_EDiagnosticChain_EMap;
}

// End Class Class

// Begin Class Classifier
std::shared_ptr<ecore::EClass> UmlPackageImpl::getClassifier_EClass() const
{
	return m_classifier_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getClassifier_EAttribute_isAbstract() const
{
	return m_classifier_EAttribute_isAbstract;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getClassifier_EAttribute_isFinalSpecialization() const
{
	return m_classifier_EAttribute_isFinalSpecialization;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getClassifier_EReference_attribute() const
{
	return m_classifier_EReference_attribute;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClassifier_EReference_collaborationUse() const
{
	return m_classifier_EReference_collaborationUse;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClassifier_EReference_feature() const
{
	return m_classifier_EReference_feature;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClassifier_EReference_general() const
{
	return m_classifier_EReference_general;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClassifier_EReference_generalization() const
{
	return m_classifier_EReference_generalization;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClassifier_EReference_inheritedMember() const
{
	return m_classifier_EReference_inheritedMember;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClassifier_EReference_ownedUseCase() const
{
	return m_classifier_EReference_ownedUseCase;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClassifier_EReference_powertypeExtent() const
{
	return m_classifier_EReference_powertypeExtent;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClassifier_EReference_redefinedClassifier() const
{
	return m_classifier_EReference_redefinedClassifier;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClassifier_EReference_representation() const
{
	return m_classifier_EReference_representation;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClassifier_EReference_substitution() const
{
	return m_classifier_EReference_substitution;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClassifier_EReference_useCase() const
{
	return m_classifier_EReference_useCase;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_EOperation_allAttributes() const
{
	return m_classifier_EOperation_allAttributes;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_EOperation_allFeatures() const
{
	return m_classifier_EOperation_allFeatures;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_EOperation_allParents() const
{
	return m_classifier_EOperation_allParents;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_EOperation_allRealizedInterfaces() const
{
	return m_classifier_EOperation_allRealizedInterfaces;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_EOperation_allSlottableFeatures() const
{
	return m_classifier_EOperation_allSlottableFeatures;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_EOperation_allUsedInterfaces() const
{
	return m_classifier_EOperation_allUsedInterfaces;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_EOperation_directlyRealizedInterfaces() const
{
	return m_classifier_EOperation_directlyRealizedInterfaces;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_EOperation_directlyUsedInterfaces() const
{
	return m_classifier_EOperation_directlyUsedInterfaces;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_EOperation_getAllAttributes() const
{
	return m_classifier_EOperation_getAllAttributes;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_EOperation_getAllOperations() const
{
	return m_classifier_EOperation_getAllOperations;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_EOperation_getAllUsedInterfaces() const
{
	return m_classifier_EOperation_getAllUsedInterfaces;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_EOperation_getGenerals() const
{
	return m_classifier_EOperation_getGenerals;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_EOperation_getInheritedMembers() const
{
	return m_classifier_EOperation_getInheritedMembers;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_EOperation_getOperation_String_Type() const
{
	return m_classifier_EOperation_getOperation_String_Type;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_EOperation_getOperation_String_Boolean() const
{
	return m_classifier_EOperation_getOperation_String_Boolean;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_EOperation_getOperations() const
{
	return m_classifier_EOperation_getOperations;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_EOperation_getUsedInterfaces() const
{
	return m_classifier_EOperation_getUsedInterfaces;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_EOperation_hasVisibilityOf_NamedElement() const
{
	return m_classifier_EOperation_hasVisibilityOf_NamedElement;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_EOperation_inherit_NamedElement() const
{
	return m_classifier_EOperation_inherit_NamedElement;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_EOperation_inheritableMembers_Classifier() const
{
	return m_classifier_EOperation_inheritableMembers_Classifier;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_EOperation_isSubstitutableFor_Classifier() const
{
	return m_classifier_EOperation_isSubstitutableFor_Classifier;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_EOperation_maps_to_generalization_set_EDiagnosticChain_EMap() const
{
	return m_classifier_EOperation_maps_to_generalization_set_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_EOperation_maySpecializeType_Classifier() const
{
	return m_classifier_EOperation_maySpecializeType_Classifier;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_EOperation_no_cycles_in_generalization_EDiagnosticChain_EMap() const
{
	return m_classifier_EOperation_no_cycles_in_generalization_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_EOperation_non_final_parents_EDiagnosticChain_EMap() const
{
	return m_classifier_EOperation_non_final_parents_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_EOperation_parents() const
{
	return m_classifier_EOperation_parents;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_EOperation_specialize_type_EDiagnosticChain_EMap() const
{
	return m_classifier_EOperation_specialize_type_EDiagnosticChain_EMap;
}

// End Class Classifier

// Begin Class ClassifierTemplateParameter
std::shared_ptr<ecore::EClass> UmlPackageImpl::getClassifierTemplateParameter_EClass() const
{
	return m_classifierTemplateParameter_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getClassifierTemplateParameter_EAttribute_allowSubstitutable() const
{
	return m_classifierTemplateParameter_EAttribute_allowSubstitutable;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getClassifierTemplateParameter_EReference_constrainingClassifier() const
{
	return m_classifierTemplateParameter_EReference_constrainingClassifier;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifierTemplateParameter_EOperation_actual_is_classifier_EDiagnosticChain_EMap() const
{
	return m_classifierTemplateParameter_EOperation_actual_is_classifier_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifierTemplateParameter_EOperation_constraining_classifiers_constrain_args_EDiagnosticChain_EMap() const
{
	return m_classifierTemplateParameter_EOperation_constraining_classifiers_constrain_args_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifierTemplateParameter_EOperation_constraining_classifiers_constrain_parametered_element_EDiagnosticChain_EMap() const
{
	return m_classifierTemplateParameter_EOperation_constraining_classifiers_constrain_parametered_element_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifierTemplateParameter_EOperation_has_constraining_classifier_EDiagnosticChain_EMap() const
{
	return m_classifierTemplateParameter_EOperation_has_constraining_classifier_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifierTemplateParameter_EOperation_matching_abstract_EDiagnosticChain_EMap() const
{
	return m_classifierTemplateParameter_EOperation_matching_abstract_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifierTemplateParameter_EOperation_parametered_element_no_features_EDiagnosticChain_EMap() const
{
	return m_classifierTemplateParameter_EOperation_parametered_element_no_features_EDiagnosticChain_EMap;
}

// End Class ClassifierTemplateParameter

// Begin Class Clause
std::shared_ptr<ecore::EClass> UmlPackageImpl::getClause_EClass() const
{
	return m_clause_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getClause_EReference_body() const
{
	return m_clause_EReference_body;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClause_EReference_bodyOutput() const
{
	return m_clause_EReference_bodyOutput;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClause_EReference_decider() const
{
	return m_clause_EReference_decider;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClause_EReference_predecessorClause() const
{
	return m_clause_EReference_predecessorClause;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClause_EReference_successorClause() const
{
	return m_clause_EReference_successorClause;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClause_EReference_test() const
{
	return m_clause_EReference_test;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClause_EOperation_body_output_pins_EDiagnosticChain_EMap() const
{
	return m_clause_EOperation_body_output_pins_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClause_EOperation_decider_output_EDiagnosticChain_EMap() const
{
	return m_clause_EOperation_decider_output_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClause_EOperation_test_and_body_EDiagnosticChain_EMap() const
{
	return m_clause_EOperation_test_and_body_EDiagnosticChain_EMap;
}

// End Class Clause

// Begin Class ClearAssociationAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getClearAssociationAction_EClass() const
{
	return m_clearAssociationAction_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getClearAssociationAction_EReference_association() const
{
	return m_clearAssociationAction_EReference_association;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClearAssociationAction_EReference_object() const
{
	return m_clearAssociationAction_EReference_object;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClearAssociationAction_EOperation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_clearAssociationAction_EOperation_multiplicity_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClearAssociationAction_EOperation_same_type_EDiagnosticChain_EMap() const
{
	return m_clearAssociationAction_EOperation_same_type_EDiagnosticChain_EMap;
}

// End Class ClearAssociationAction

// Begin Class ClearStructuralFeatureAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getClearStructuralFeatureAction_EClass() const
{
	return m_clearStructuralFeatureAction_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getClearStructuralFeatureAction_EReference_result() const
{
	return m_clearStructuralFeatureAction_EReference_result;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClearStructuralFeatureAction_EOperation_multiplicity_of_result_EDiagnosticChain_EMap() const
{
	return m_clearStructuralFeatureAction_EOperation_multiplicity_of_result_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClearStructuralFeatureAction_EOperation_type_of_result_EDiagnosticChain_EMap() const
{
	return m_clearStructuralFeatureAction_EOperation_type_of_result_EDiagnosticChain_EMap;
}

// End Class ClearStructuralFeatureAction

// Begin Class ClearVariableAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getClearVariableAction_EClass() const
{
	return m_clearVariableAction_EClass;
}




// End Class ClearVariableAction

// Begin Class Collaboration
std::shared_ptr<ecore::EClass> UmlPackageImpl::getCollaboration_EClass() const
{
	return m_collaboration_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getCollaboration_EReference_collaborationRole() const
{
	return m_collaboration_EReference_collaborationRole;
}


// End Class Collaboration

// Begin Class CollaborationUse
std::shared_ptr<ecore::EClass> UmlPackageImpl::getCollaborationUse_EClass() const
{
	return m_collaborationUse_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getCollaborationUse_EReference_roleBinding() const
{
	return m_collaborationUse_EReference_roleBinding;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getCollaborationUse_EReference_type() const
{
	return m_collaborationUse_EReference_type;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCollaborationUse_EOperation_client_elements_EDiagnosticChain_EMap() const
{
	return m_collaborationUse_EOperation_client_elements_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCollaborationUse_EOperation_connectors_EDiagnosticChain_EMap() const
{
	return m_collaborationUse_EOperation_connectors_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCollaborationUse_EOperation_every_role_EDiagnosticChain_EMap() const
{
	return m_collaborationUse_EOperation_every_role_EDiagnosticChain_EMap;
}

// End Class CollaborationUse

// Begin Class CombinedFragment
std::shared_ptr<ecore::EClass> UmlPackageImpl::getCombinedFragment_EClass() const
{
	return m_combinedFragment_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getCombinedFragment_EAttribute_interactionOperator() const
{
	return m_combinedFragment_EAttribute_interactionOperator;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getCombinedFragment_EReference_cfragmentGate() const
{
	return m_combinedFragment_EReference_cfragmentGate;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getCombinedFragment_EReference_operand() const
{
	return m_combinedFragment_EReference_operand;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCombinedFragment_EOperation_break__EDiagnosticChain_EMap() const
{
	return m_combinedFragment_EOperation_break__EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCombinedFragment_EOperation_consider_and_ignore_EDiagnosticChain_EMap() const
{
	return m_combinedFragment_EOperation_consider_and_ignore_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCombinedFragment_EOperation_opt_loop_break_neg_EDiagnosticChain_EMap() const
{
	return m_combinedFragment_EOperation_opt_loop_break_neg_EDiagnosticChain_EMap;
}

// End Class CombinedFragment

// Begin Class Comment
std::shared_ptr<ecore::EClass> UmlPackageImpl::getComment_EClass() const
{
	return m_comment_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getComment_EAttribute_body() const
{
	return m_comment_EAttribute_body;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getComment_EReference_annotatedElement() const
{
	return m_comment_EReference_annotatedElement;
}


// End Class Comment

// Begin Class CommunicationPath
std::shared_ptr<ecore::EClass> UmlPackageImpl::getCommunicationPath_EClass() const
{
	return m_communicationPath_EClass;
}




// End Class CommunicationPath

// Begin Class Component
std::shared_ptr<ecore::EClass> UmlPackageImpl::getComponent_EClass() const
{
	return m_component_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getComponent_EAttribute_isIndirectlyInstantiated() const
{
	return m_component_EAttribute_isIndirectlyInstantiated;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getComponent_EReference_packagedElement() const
{
	return m_component_EReference_packagedElement;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getComponent_EReference_provided() const
{
	return m_component_EReference_provided;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getComponent_EReference_realization() const
{
	return m_component_EReference_realization;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getComponent_EReference_required() const
{
	return m_component_EReference_required;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getComponent_EOperation_createOwnedClass_String_Boolean() const
{
	return m_component_EOperation_createOwnedClass_String_Boolean;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getComponent_EOperation_createOwnedEnumeration_String() const
{
	return m_component_EOperation_createOwnedEnumeration_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getComponent_EOperation_createOwnedInterface_String() const
{
	return m_component_EOperation_createOwnedInterface_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getComponent_EOperation_createOwnedPrimitiveType_String() const
{
	return m_component_EOperation_createOwnedPrimitiveType_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getComponent_EOperation_getProvideds() const
{
	return m_component_EOperation_getProvideds;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getComponent_EOperation_getRequireds() const
{
	return m_component_EOperation_getRequireds;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getComponent_EOperation_no_nested_classifiers_EDiagnosticChain_EMap() const
{
	return m_component_EOperation_no_nested_classifiers_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getComponent_EOperation_no_packaged_elements_EDiagnosticChain_EMap() const
{
	return m_component_EOperation_no_packaged_elements_EDiagnosticChain_EMap;
}

// End Class Component

// Begin Class ComponentRealization
std::shared_ptr<ecore::EClass> UmlPackageImpl::getComponentRealization_EClass() const
{
	return m_componentRealization_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getComponentRealization_EReference_abstraction() const
{
	return m_componentRealization_EReference_abstraction;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getComponentRealization_EReference_realizingClassifier() const
{
	return m_componentRealization_EReference_realizingClassifier;
}


// End Class ComponentRealization

// Begin Class ConditionalNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getConditionalNode_EClass() const
{
	return m_conditionalNode_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getConditionalNode_EAttribute_isAssured() const
{
	return m_conditionalNode_EAttribute_isAssured;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getConditionalNode_EAttribute_isDeterminate() const
{
	return m_conditionalNode_EAttribute_isDeterminate;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getConditionalNode_EReference_clause() const
{
	return m_conditionalNode_EReference_clause;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getConditionalNode_EReference_result() const
{
	return m_conditionalNode_EReference_result;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConditionalNode_EOperation_clause_no_predecessor_EDiagnosticChain_EMap() const
{
	return m_conditionalNode_EOperation_clause_no_predecessor_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConditionalNode_EOperation_executable_nodes_EDiagnosticChain_EMap() const
{
	return m_conditionalNode_EOperation_executable_nodes_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConditionalNode_EOperation_matching_output_pins_EDiagnosticChain_EMap() const
{
	return m_conditionalNode_EOperation_matching_output_pins_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConditionalNode_EOperation_no_input_pins_EDiagnosticChain_EMap() const
{
	return m_conditionalNode_EOperation_no_input_pins_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConditionalNode_EOperation_one_clause_with_executable_node_EDiagnosticChain_EMap() const
{
	return m_conditionalNode_EOperation_one_clause_with_executable_node_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConditionalNode_EOperation_result_no_incoming_EDiagnosticChain_EMap() const
{
	return m_conditionalNode_EOperation_result_no_incoming_EDiagnosticChain_EMap;
}

// End Class ConditionalNode

// Begin Class ConnectableElement
std::shared_ptr<ecore::EClass> UmlPackageImpl::getConnectableElement_EClass() const
{
	return m_connectableElement_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getConnectableElement_EReference_end() const
{
	return m_connectableElement_EReference_end;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConnectableElement_EOperation_getEnds() const
{
	return m_connectableElement_EOperation_getEnds;
}

// End Class ConnectableElement

// Begin Class ConnectableElementTemplateParameter
std::shared_ptr<ecore::EClass> UmlPackageImpl::getConnectableElementTemplateParameter_EClass() const
{
	return m_connectableElementTemplateParameter_EClass;
}




// End Class ConnectableElementTemplateParameter

// Begin Class ConnectionPointReference
std::shared_ptr<ecore::EClass> UmlPackageImpl::getConnectionPointReference_EClass() const
{
	return m_connectionPointReference_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getConnectionPointReference_EReference_entry() const
{
	return m_connectionPointReference_EReference_entry;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getConnectionPointReference_EReference_exit() const
{
	return m_connectionPointReference_EReference_exit;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getConnectionPointReference_EReference_state() const
{
	return m_connectionPointReference_EReference_state;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConnectionPointReference_EOperation_entry_pseudostates_EDiagnosticChain_EMap() const
{
	return m_connectionPointReference_EOperation_entry_pseudostates_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConnectionPointReference_EOperation_exit_pseudostates_EDiagnosticChain_EMap() const
{
	return m_connectionPointReference_EOperation_exit_pseudostates_EDiagnosticChain_EMap;
}

// End Class ConnectionPointReference

// Begin Class Connector
std::shared_ptr<ecore::EClass> UmlPackageImpl::getConnector_EClass() const
{
	return m_connector_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getConnector_EAttribute_kind() const
{
	return m_connector_EAttribute_kind;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getConnector_EReference_contract() const
{
	return m_connector_EReference_contract;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getConnector_EReference_end() const
{
	return m_connector_EReference_end;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getConnector_EReference_redefinedConnector() const
{
	return m_connector_EReference_redefinedConnector;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getConnector_EReference_type() const
{
	return m_connector_EReference_type;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConnector_EOperation_getKind() const
{
	return m_connector_EOperation_getKind;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConnector_EOperation_roles_EDiagnosticChain_EMap() const
{
	return m_connector_EOperation_roles_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConnector_EOperation_types_EDiagnosticChain_EMap() const
{
	return m_connector_EOperation_types_EDiagnosticChain_EMap;
}

// End Class Connector

// Begin Class ConnectorEnd
std::shared_ptr<ecore::EClass> UmlPackageImpl::getConnectorEnd_EClass() const
{
	return m_connectorEnd_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getConnectorEnd_EReference_definingEnd() const
{
	return m_connectorEnd_EReference_definingEnd;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getConnectorEnd_EReference_partWithPort() const
{
	return m_connectorEnd_EReference_partWithPort;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getConnectorEnd_EReference_role() const
{
	return m_connectorEnd_EReference_role;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConnectorEnd_EOperation_getDefiningEnd() const
{
	return m_connectorEnd_EOperation_getDefiningEnd;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConnectorEnd_EOperation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_connectorEnd_EOperation_multiplicity_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConnectorEnd_EOperation_part_with_port_empty_EDiagnosticChain_EMap() const
{
	return m_connectorEnd_EOperation_part_with_port_empty_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConnectorEnd_EOperation_role_and_part_with_port_EDiagnosticChain_EMap() const
{
	return m_connectorEnd_EOperation_role_and_part_with_port_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConnectorEnd_EOperation_self_part_with_port_EDiagnosticChain_EMap() const
{
	return m_connectorEnd_EOperation_self_part_with_port_EDiagnosticChain_EMap;
}

// End Class ConnectorEnd

// Begin Class ConsiderIgnoreFragment
std::shared_ptr<ecore::EClass> UmlPackageImpl::getConsiderIgnoreFragment_EClass() const
{
	return m_considerIgnoreFragment_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getConsiderIgnoreFragment_EReference_message() const
{
	return m_considerIgnoreFragment_EReference_message;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConsiderIgnoreFragment_EOperation_consider_or_ignore_EDiagnosticChain_EMap() const
{
	return m_considerIgnoreFragment_EOperation_consider_or_ignore_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConsiderIgnoreFragment_EOperation_type_EDiagnosticChain_EMap() const
{
	return m_considerIgnoreFragment_EOperation_type_EDiagnosticChain_EMap;
}

// End Class ConsiderIgnoreFragment

// Begin Class Constraint
std::shared_ptr<ecore::EClass> UmlPackageImpl::getConstraint_EClass() const
{
	return m_constraint_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getConstraint_EReference_constrainedElement() const
{
	return m_constraint_EReference_constrainedElement;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getConstraint_EReference_context() const
{
	return m_constraint_EReference_context;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getConstraint_EReference_specification() const
{
	return m_constraint_EReference_specification;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConstraint_EOperation_boolean_value_EDiagnosticChain_EMap() const
{
	return m_constraint_EOperation_boolean_value_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConstraint_EOperation_no_side_effects_EDiagnosticChain_EMap() const
{
	return m_constraint_EOperation_no_side_effects_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConstraint_EOperation_not_apply_to_self_EDiagnosticChain_EMap() const
{
	return m_constraint_EOperation_not_apply_to_self_EDiagnosticChain_EMap;
}

// End Class Constraint

// Begin Class Continuation
std::shared_ptr<ecore::EClass> UmlPackageImpl::getContinuation_EClass() const
{
	return m_continuation_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getContinuation_EAttribute_setting() const
{
	return m_continuation_EAttribute_setting;
}


std::shared_ptr<ecore::EOperation> UmlPackageImpl::getContinuation_EOperation_first_or_last_interaction_fragment_EDiagnosticChain_EMap() const
{
	return m_continuation_EOperation_first_or_last_interaction_fragment_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getContinuation_EOperation_global_EDiagnosticChain_EMap() const
{
	return m_continuation_EOperation_global_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getContinuation_EOperation_same_name_EDiagnosticChain_EMap() const
{
	return m_continuation_EOperation_same_name_EDiagnosticChain_EMap;
}

// End Class Continuation

// Begin Class ControlFlow
std::shared_ptr<ecore::EClass> UmlPackageImpl::getControlFlow_EClass() const
{
	return m_controlFlow_EClass;
}



std::shared_ptr<ecore::EOperation> UmlPackageImpl::getControlFlow_EOperation_object_nodes_EDiagnosticChain_EMap() const
{
	return m_controlFlow_EOperation_object_nodes_EDiagnosticChain_EMap;
}

// End Class ControlFlow

// Begin Class ControlNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getControlNode_EClass() const
{
	return m_controlNode_EClass;
}




// End Class ControlNode

// Begin Class CreateLinkAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getCreateLinkAction_EClass() const
{
	return m_createLinkAction_EClass;
}



std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCreateLinkAction_EOperation_association_not_abstract_EDiagnosticChain_EMap() const
{
	return m_createLinkAction_EOperation_association_not_abstract_EDiagnosticChain_EMap;
}

// End Class CreateLinkAction

// Begin Class CreateLinkObjectAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getCreateLinkObjectAction_EClass() const
{
	return m_createLinkObjectAction_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getCreateLinkObjectAction_EReference_result() const
{
	return m_createLinkObjectAction_EReference_result;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCreateLinkObjectAction_EOperation_association_class_EDiagnosticChain_EMap() const
{
	return m_createLinkObjectAction_EOperation_association_class_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCreateLinkObjectAction_EOperation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_createLinkObjectAction_EOperation_multiplicity_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCreateLinkObjectAction_EOperation_type_of_result_EDiagnosticChain_EMap() const
{
	return m_createLinkObjectAction_EOperation_type_of_result_EDiagnosticChain_EMap;
}

// End Class CreateLinkObjectAction

// Begin Class CreateObjectAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getCreateObjectAction_EClass() const
{
	return m_createObjectAction_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getCreateObjectAction_EReference_classifier() const
{
	return m_createObjectAction_EReference_classifier;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getCreateObjectAction_EReference_result() const
{
	return m_createObjectAction_EReference_result;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCreateObjectAction_EOperation_classifier_not_abstract_EDiagnosticChain_EMap() const
{
	return m_createObjectAction_EOperation_classifier_not_abstract_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCreateObjectAction_EOperation_classifier_not_association_class_EDiagnosticChain_EMap() const
{
	return m_createObjectAction_EOperation_classifier_not_association_class_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCreateObjectAction_EOperation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_createObjectAction_EOperation_multiplicity_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCreateObjectAction_EOperation_same_type_EDiagnosticChain_EMap() const
{
	return m_createObjectAction_EOperation_same_type_EDiagnosticChain_EMap;
}

// End Class CreateObjectAction

// Begin Class DataStoreNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDataStoreNode_EClass() const
{
	return m_dataStoreNode_EClass;
}




// End Class DataStoreNode

// Begin Class DataType
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDataType_EClass() const
{
	return m_dataType_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getDataType_EReference_ownedAttribute() const
{
	return m_dataType_EReference_ownedAttribute;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getDataType_EReference_ownedOperation() const
{
	return m_dataType_EReference_ownedOperation;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDataType_EOperation_createOwnedAttribute_String_UnlimitedNatural() const
{
	return m_dataType_EOperation_createOwnedAttribute_String_UnlimitedNatural;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDataType_EOperation_createOwnedOperation_String_Type() const
{
	return m_dataType_EOperation_createOwnedOperation_String_Type;
}

// End Class DataType

// Begin Class DecisionNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDecisionNode_EClass() const
{
	return m_decisionNode_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getDecisionNode_EReference_decisionInput() const
{
	return m_decisionNode_EReference_decisionInput;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getDecisionNode_EReference_decisionInputFlow() const
{
	return m_decisionNode_EReference_decisionInputFlow;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDecisionNode_EOperation_decision_input_flow_incoming_EDiagnosticChain_EMap() const
{
	return m_decisionNode_EOperation_decision_input_flow_incoming_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDecisionNode_EOperation_edges_EDiagnosticChain_EMap() const
{
	return m_decisionNode_EOperation_edges_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDecisionNode_EOperation_incoming_control_one_input_parameter_EDiagnosticChain_EMap() const
{
	return m_decisionNode_EOperation_incoming_control_one_input_parameter_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDecisionNode_EOperation_incoming_object_one_input_parameter_EDiagnosticChain_EMap() const
{
	return m_decisionNode_EOperation_incoming_object_one_input_parameter_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDecisionNode_EOperation_incoming_outgoing_edges_EDiagnosticChain_EMap() const
{
	return m_decisionNode_EOperation_incoming_outgoing_edges_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDecisionNode_EOperation_parameters_EDiagnosticChain_EMap() const
{
	return m_decisionNode_EOperation_parameters_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDecisionNode_EOperation_two_input_parameters_EDiagnosticChain_EMap() const
{
	return m_decisionNode_EOperation_two_input_parameters_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDecisionNode_EOperation_zero_input_parameters_EDiagnosticChain_EMap() const
{
	return m_decisionNode_EOperation_zero_input_parameters_EDiagnosticChain_EMap;
}

// End Class DecisionNode

// Begin Class Dependency
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDependency_EClass() const
{
	return m_dependency_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getDependency_EReference_client() const
{
	return m_dependency_EReference_client;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getDependency_EReference_supplier() const
{
	return m_dependency_EReference_supplier;
}


// End Class Dependency

// Begin Class DeployedArtifact
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDeployedArtifact_EClass() const
{
	return m_deployedArtifact_EClass;
}




// End Class DeployedArtifact

// Begin Class Deployment
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDeployment_EClass() const
{
	return m_deployment_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getDeployment_EReference_configuration() const
{
	return m_deployment_EReference_configuration;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getDeployment_EReference_deployedArtifact() const
{
	return m_deployment_EReference_deployedArtifact;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getDeployment_EReference_location() const
{
	return m_deployment_EReference_location;
}


// End Class Deployment

// Begin Class DeploymentSpecification
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDeploymentSpecification_EClass() const
{
	return m_deploymentSpecification_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getDeploymentSpecification_EAttribute_deploymentLocation() const
{
	return m_deploymentSpecification_EAttribute_deploymentLocation;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getDeploymentSpecification_EAttribute_executionLocation() const
{
	return m_deploymentSpecification_EAttribute_executionLocation;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getDeploymentSpecification_EReference_deployment() const
{
	return m_deploymentSpecification_EReference_deployment;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDeploymentSpecification_EOperation_deployed_elements_EDiagnosticChain_EMap() const
{
	return m_deploymentSpecification_EOperation_deployed_elements_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDeploymentSpecification_EOperation_deployment_target_EDiagnosticChain_EMap() const
{
	return m_deploymentSpecification_EOperation_deployment_target_EDiagnosticChain_EMap;
}

// End Class DeploymentSpecification

// Begin Class DeploymentTarget
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDeploymentTarget_EClass() const
{
	return m_deploymentTarget_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getDeploymentTarget_EReference_deployedElement() const
{
	return m_deploymentTarget_EReference_deployedElement;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getDeploymentTarget_EReference_deployment() const
{
	return m_deploymentTarget_EReference_deployment;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDeploymentTarget_EOperation_getDeployedElements() const
{
	return m_deploymentTarget_EOperation_getDeployedElements;
}

// End Class DeploymentTarget

// Begin Class DestroyLinkAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDestroyLinkAction_EClass() const
{
	return m_destroyLinkAction_EClass;
}




// End Class DestroyLinkAction

// Begin Class DestroyObjectAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDestroyObjectAction_EClass() const
{
	return m_destroyObjectAction_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getDestroyObjectAction_EAttribute_isDestroyLinks() const
{
	return m_destroyObjectAction_EAttribute_isDestroyLinks;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getDestroyObjectAction_EAttribute_isDestroyOwnedObjects() const
{
	return m_destroyObjectAction_EAttribute_isDestroyOwnedObjects;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getDestroyObjectAction_EReference_target() const
{
	return m_destroyObjectAction_EReference_target;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDestroyObjectAction_EOperation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_destroyObjectAction_EOperation_multiplicity_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDestroyObjectAction_EOperation_no_type_EDiagnosticChain_EMap() const
{
	return m_destroyObjectAction_EOperation_no_type_EDiagnosticChain_EMap;
}

// End Class DestroyObjectAction

// Begin Class DestructionOccurrenceSpecification
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDestructionOccurrenceSpecification_EClass() const
{
	return m_destructionOccurrenceSpecification_EClass;
}



std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDestructionOccurrenceSpecification_EOperation_no_occurrence_specifications_below_EDiagnosticChain_EMap() const
{
	return m_destructionOccurrenceSpecification_EOperation_no_occurrence_specifications_below_EDiagnosticChain_EMap;
}

// End Class DestructionOccurrenceSpecification

// Begin Class Device
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDevice_EClass() const
{
	return m_device_EClass;
}




// End Class Device

// Begin Class DirectedRelationship
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDirectedRelationship_EClass() const
{
	return m_directedRelationship_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getDirectedRelationship_EReference_source() const
{
	return m_directedRelationship_EReference_source;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getDirectedRelationship_EReference_target() const
{
	return m_directedRelationship_EReference_target;
}


// End Class DirectedRelationship

// Begin Class Duration
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDuration_EClass() const
{
	return m_duration_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getDuration_EReference_expr() const
{
	return m_duration_EReference_expr;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getDuration_EReference_observation() const
{
	return m_duration_EReference_observation;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDuration_EOperation_no_expr_requires_observation_EDiagnosticChain_EMap() const
{
	return m_duration_EOperation_no_expr_requires_observation_EDiagnosticChain_EMap;
}

// End Class Duration

// Begin Class DurationConstraint
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDurationConstraint_EClass() const
{
	return m_durationConstraint_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getDurationConstraint_EAttribute_firstEvent() const
{
	return m_durationConstraint_EAttribute_firstEvent;
}


std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDurationConstraint_EOperation_first_event_multiplicity_EDiagnosticChain_EMap() const
{
	return m_durationConstraint_EOperation_first_event_multiplicity_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDurationConstraint_EOperation_has_one_or_two_constrainedElements_EDiagnosticChain_EMap() const
{
	return m_durationConstraint_EOperation_has_one_or_two_constrainedElements_EDiagnosticChain_EMap;
}

// End Class DurationConstraint

// Begin Class DurationInterval
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDurationInterval_EClass() const
{
	return m_durationInterval_EClass;
}




// End Class DurationInterval

// Begin Class DurationObservation
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDurationObservation_EClass() const
{
	return m_durationObservation_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getDurationObservation_EAttribute_firstEvent() const
{
	return m_durationObservation_EAttribute_firstEvent;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getDurationObservation_EReference_event() const
{
	return m_durationObservation_EReference_event;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDurationObservation_EOperation_first_event_multiplicity_EDiagnosticChain_EMap() const
{
	return m_durationObservation_EOperation_first_event_multiplicity_EDiagnosticChain_EMap;
}

// End Class DurationObservation

// Begin Class Element
std::shared_ptr<ecore::EClass> UmlPackageImpl::getElement_EClass() const
{
	return m_element_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getElement_EReference_ownedComment() const
{
	return m_element_EReference_ownedComment;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getElement_EReference_ownedElement() const
{
	return m_element_EReference_ownedElement;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getElement_EReference_owner() const
{
	return m_element_EReference_owner;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_EOperation_addKeyword_String() const
{
	return m_element_EOperation_addKeyword_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_EOperation_allOwnedElements() const
{
	return m_element_EOperation_allOwnedElements;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_EOperation_applyStereotype_Stereotype() const
{
	return m_element_EOperation_applyStereotype_Stereotype;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_EOperation_container() const
{
	return m_element_EOperation_container;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_EOperation_createEAnnotation_String() const
{
	return m_element_EOperation_createEAnnotation_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_EOperation_destroy() const
{
	return m_element_EOperation_destroy;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_EOperation_getApplicableStereotype_String() const
{
	return m_element_EOperation_getApplicableStereotype_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_EOperation_getApplicableStereotypes() const
{
	return m_element_EOperation_getApplicableStereotypes;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_EOperation_getAppliedStereotype_String() const
{
	return m_element_EOperation_getAppliedStereotype_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_EOperation_getAppliedStereotypes() const
{
	return m_element_EOperation_getAppliedStereotypes;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_EOperation_getAppliedSubstereotype_Stereotype_String() const
{
	return m_element_EOperation_getAppliedSubstereotype_Stereotype_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_EOperation_getAppliedSubstereotypes_Stereotype() const
{
	return m_element_EOperation_getAppliedSubstereotypes_Stereotype;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_EOperation_getKeywords() const
{
	return m_element_EOperation_getKeywords;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_EOperation_getMetaClass() const
{
	return m_element_EOperation_getMetaClass;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_EOperation_getModel() const
{
	return m_element_EOperation_getModel;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_EOperation_getNearestPackage() const
{
	return m_element_EOperation_getNearestPackage;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_EOperation_getRelationships() const
{
	return m_element_EOperation_getRelationships;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_EOperation_getRelationships_EClass() const
{
	return m_element_EOperation_getRelationships_EClass;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_EOperation_getRequiredStereotype_String() const
{
	return m_element_EOperation_getRequiredStereotype_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_EOperation_getRequiredStereotypes() const
{
	return m_element_EOperation_getRequiredStereotypes;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_EOperation_getSourceDirectedRelationships() const
{
	return m_element_EOperation_getSourceDirectedRelationships;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_EOperation_getSourceDirectedRelationships_EClass() const
{
	return m_element_EOperation_getSourceDirectedRelationships_EClass;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_EOperation_getStereotypeApplication_Stereotype() const
{
	return m_element_EOperation_getStereotypeApplication_Stereotype;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_EOperation_getStereotypeApplications() const
{
	return m_element_EOperation_getStereotypeApplications;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_EOperation_getTargetDirectedRelationships() const
{
	return m_element_EOperation_getTargetDirectedRelationships;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_EOperation_getTargetDirectedRelationships_EClass() const
{
	return m_element_EOperation_getTargetDirectedRelationships_EClass;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_EOperation_getValue_Stereotype_String() const
{
	return m_element_EOperation_getValue_Stereotype_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_EOperation_hasKeyword_String() const
{
	return m_element_EOperation_hasKeyword_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_EOperation_hasValue_Stereotype_String() const
{
	return m_element_EOperation_hasValue_Stereotype_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_EOperation_has_owner_EDiagnosticChain_EMap() const
{
	return m_element_EOperation_has_owner_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_EOperation_isStereotypeApplicable_Stereotype() const
{
	return m_element_EOperation_isStereotypeApplicable_Stereotype;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_EOperation_isStereotypeApplied_Stereotype() const
{
	return m_element_EOperation_isStereotypeApplied_Stereotype;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_EOperation_isStereotypeRequired_Stereotype() const
{
	return m_element_EOperation_isStereotypeRequired_Stereotype;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_EOperation_mustBeOwned() const
{
	return m_element_EOperation_mustBeOwned;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_EOperation_not_own_self_EDiagnosticChain_EMap() const
{
	return m_element_EOperation_not_own_self_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_EOperation_removeKeyword_String() const
{
	return m_element_EOperation_removeKeyword_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_EOperation_setValue_Stereotype_EJavaObject() const
{
	return m_element_EOperation_setValue_Stereotype_EJavaObject;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_EOperation_unapplyStereotype_Stereotype() const
{
	return m_element_EOperation_unapplyStereotype_Stereotype;
}

// End Class Element

// Begin Class ElementImport
std::shared_ptr<ecore::EClass> UmlPackageImpl::getElementImport_EClass() const
{
	return m_elementImport_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getElementImport_EAttribute_alias() const
{
	return m_elementImport_EAttribute_alias;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getElementImport_EAttribute_visibility() const
{
	return m_elementImport_EAttribute_visibility;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getElementImport_EReference_importedElement() const
{
	return m_elementImport_EReference_importedElement;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getElementImport_EReference_importingNamespace() const
{
	return m_elementImport_EReference_importingNamespace;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElementImport_EOperation_getName() const
{
	return m_elementImport_EOperation_getName;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElementImport_EOperation_imported_element_is_public_EDiagnosticChain_EMap() const
{
	return m_elementImport_EOperation_imported_element_is_public_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElementImport_EOperation_visibility_public_or_private_EDiagnosticChain_EMap() const
{
	return m_elementImport_EOperation_visibility_public_or_private_EDiagnosticChain_EMap;
}

// End Class ElementImport

// Begin Class EncapsulatedClassifier
std::shared_ptr<ecore::EClass> UmlPackageImpl::getEncapsulatedClassifier_EClass() const
{
	return m_encapsulatedClassifier_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getEncapsulatedClassifier_EReference_ownedPort() const
{
	return m_encapsulatedClassifier_EReference_ownedPort;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getEncapsulatedClassifier_EOperation_getOwnedPorts() const
{
	return m_encapsulatedClassifier_EOperation_getOwnedPorts;
}

// End Class EncapsulatedClassifier

// Begin Class Enumeration
std::shared_ptr<ecore::EClass> UmlPackageImpl::getEnumeration_EClass() const
{
	return m_enumeration_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getEnumeration_EReference_ownedLiteral() const
{
	return m_enumeration_EReference_ownedLiteral;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getEnumeration_EOperation_immutable_EDiagnosticChain_EMap() const
{
	return m_enumeration_EOperation_immutable_EDiagnosticChain_EMap;
}

// End Class Enumeration

// Begin Class EnumerationLiteral
std::shared_ptr<ecore::EClass> UmlPackageImpl::getEnumerationLiteral_EClass() const
{
	return m_enumerationLiteral_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getEnumerationLiteral_EReference_enumeration() const
{
	return m_enumerationLiteral_EReference_enumeration;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getEnumerationLiteral_EOperation_getClassifier() const
{
	return m_enumerationLiteral_EOperation_getClassifier;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getEnumerationLiteral_EOperation_getClassifiers() const
{
	return m_enumerationLiteral_EOperation_getClassifiers;
}

// End Class EnumerationLiteral

// Begin Class Event
std::shared_ptr<ecore::EClass> UmlPackageImpl::getEvent_EClass() const
{
	return m_event_EClass;
}




// End Class Event

// Begin Class ExceptionHandler
std::shared_ptr<ecore::EClass> UmlPackageImpl::getExceptionHandler_EClass() const
{
	return m_exceptionHandler_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getExceptionHandler_EReference_exceptionInput() const
{
	return m_exceptionHandler_EReference_exceptionInput;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getExceptionHandler_EReference_exceptionType() const
{
	return m_exceptionHandler_EReference_exceptionType;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getExceptionHandler_EReference_handlerBody() const
{
	return m_exceptionHandler_EReference_handlerBody;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getExceptionHandler_EReference_protectedNode() const
{
	return m_exceptionHandler_EReference_protectedNode;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExceptionHandler_EOperation_edge_source_target_EDiagnosticChain_EMap() const
{
	return m_exceptionHandler_EOperation_edge_source_target_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExceptionHandler_EOperation_exception_input_type_EDiagnosticChain_EMap() const
{
	return m_exceptionHandler_EOperation_exception_input_type_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExceptionHandler_EOperation_handler_body_edges_EDiagnosticChain_EMap() const
{
	return m_exceptionHandler_EOperation_handler_body_edges_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExceptionHandler_EOperation_handler_body_owner_EDiagnosticChain_EMap() const
{
	return m_exceptionHandler_EOperation_handler_body_owner_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExceptionHandler_EOperation_one_input_EDiagnosticChain_EMap() const
{
	return m_exceptionHandler_EOperation_one_input_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExceptionHandler_EOperation_output_pins_EDiagnosticChain_EMap() const
{
	return m_exceptionHandler_EOperation_output_pins_EDiagnosticChain_EMap;
}

// End Class ExceptionHandler

// Begin Class ExecutableNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getExecutableNode_EClass() const
{
	return m_executableNode_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getExecutableNode_EReference_handler() const
{
	return m_executableNode_EReference_handler;
}


// End Class ExecutableNode

// Begin Class ExecutionEnvironment
std::shared_ptr<ecore::EClass> UmlPackageImpl::getExecutionEnvironment_EClass() const
{
	return m_executionEnvironment_EClass;
}




// End Class ExecutionEnvironment

// Begin Class ExecutionOccurrenceSpecification
std::shared_ptr<ecore::EClass> UmlPackageImpl::getExecutionOccurrenceSpecification_EClass() const
{
	return m_executionOccurrenceSpecification_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getExecutionOccurrenceSpecification_EReference_execution() const
{
	return m_executionOccurrenceSpecification_EReference_execution;
}


// End Class ExecutionOccurrenceSpecification

// Begin Class ExecutionSpecification
std::shared_ptr<ecore::EClass> UmlPackageImpl::getExecutionSpecification_EClass() const
{
	return m_executionSpecification_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getExecutionSpecification_EReference_finish() const
{
	return m_executionSpecification_EReference_finish;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getExecutionSpecification_EReference_start() const
{
	return m_executionSpecification_EReference_start;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExecutionSpecification_EOperation_same_lifeline_EDiagnosticChain_EMap() const
{
	return m_executionSpecification_EOperation_same_lifeline_EDiagnosticChain_EMap;
}

// End Class ExecutionSpecification

// Begin Class ExpansionNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getExpansionNode_EClass() const
{
	return m_expansionNode_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getExpansionNode_EReference_regionAsInput() const
{
	return m_expansionNode_EReference_regionAsInput;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getExpansionNode_EReference_regionAsOutput() const
{
	return m_expansionNode_EReference_regionAsOutput;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExpansionNode_EOperation_region_as_input_or_output_EDiagnosticChain_EMap() const
{
	return m_expansionNode_EOperation_region_as_input_or_output_EDiagnosticChain_EMap;
}

// End Class ExpansionNode

// Begin Class ExpansionRegion
std::shared_ptr<ecore::EClass> UmlPackageImpl::getExpansionRegion_EClass() const
{
	return m_expansionRegion_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getExpansionRegion_EAttribute_mode() const
{
	return m_expansionRegion_EAttribute_mode;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getExpansionRegion_EReference_inputElement() const
{
	return m_expansionRegion_EReference_inputElement;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getExpansionRegion_EReference_outputElement() const
{
	return m_expansionRegion_EReference_outputElement;
}


// End Class ExpansionRegion

// Begin Class Expression
std::shared_ptr<ecore::EClass> UmlPackageImpl::getExpression_EClass() const
{
	return m_expression_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getExpression_EAttribute_symbol() const
{
	return m_expression_EAttribute_symbol;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getExpression_EReference_operand() const
{
	return m_expression_EReference_operand;
}


// End Class Expression

// Begin Class Extend
std::shared_ptr<ecore::EClass> UmlPackageImpl::getExtend_EClass() const
{
	return m_extend_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getExtend_EReference_condition() const
{
	return m_extend_EReference_condition;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getExtend_EReference_extendedCase() const
{
	return m_extend_EReference_extendedCase;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getExtend_EReference_extension() const
{
	return m_extend_EReference_extension;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getExtend_EReference_extensionLocation() const
{
	return m_extend_EReference_extensionLocation;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExtend_EOperation_extension_points_EDiagnosticChain_EMap() const
{
	return m_extend_EOperation_extension_points_EDiagnosticChain_EMap;
}

// End Class Extend

// Begin Class Extension
std::shared_ptr<ecore::EClass> UmlPackageImpl::getExtension_EClass() const
{
	return m_extension_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getExtension_EAttribute_isRequired() const
{
	return m_extension_EAttribute_isRequired;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getExtension_EReference_metaclass() const
{
	return m_extension_EReference_metaclass;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExtension_EOperation_getMetaclass() const
{
	return m_extension_EOperation_getMetaclass;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExtension_EOperation_getStereotype() const
{
	return m_extension_EOperation_getStereotype;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExtension_EOperation_getStereotypeEnd() const
{
	return m_extension_EOperation_getStereotypeEnd;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExtension_EOperation_isRequired() const
{
	return m_extension_EOperation_isRequired;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExtension_EOperation_is_binary_EDiagnosticChain_EMap() const
{
	return m_extension_EOperation_is_binary_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExtension_EOperation_metaclassEnd() const
{
	return m_extension_EOperation_metaclassEnd;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExtension_EOperation_non_owned_end_EDiagnosticChain_EMap() const
{
	return m_extension_EOperation_non_owned_end_EDiagnosticChain_EMap;
}

// End Class Extension

// Begin Class ExtensionEnd
std::shared_ptr<ecore::EClass> UmlPackageImpl::getExtensionEnd_EClass() const
{
	return m_extensionEnd_EClass;
}



std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExtensionEnd_EOperation_aggregation_EDiagnosticChain_EMap() const
{
	return m_extensionEnd_EOperation_aggregation_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExtensionEnd_EOperation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_extensionEnd_EOperation_multiplicity_EDiagnosticChain_EMap;
}

// End Class ExtensionEnd

// Begin Class ExtensionPoint
std::shared_ptr<ecore::EClass> UmlPackageImpl::getExtensionPoint_EClass() const
{
	return m_extensionPoint_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getExtensionPoint_EReference_useCase() const
{
	return m_extensionPoint_EReference_useCase;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExtensionPoint_EOperation_must_have_name_EDiagnosticChain_EMap() const
{
	return m_extensionPoint_EOperation_must_have_name_EDiagnosticChain_EMap;
}

// End Class ExtensionPoint

// Begin Class Factory
std::shared_ptr<ecore::EClass> UmlPackageImpl::getFactory_EClass() const
{
	return m_factory_EClass;
}



std::shared_ptr<ecore::EOperation> UmlPackageImpl::getFactory_EOperation_create_Class() const
{
	return m_factory_EOperation_create_Class;
}

// End Class Factory

// Begin Class Feature
std::shared_ptr<ecore::EClass> UmlPackageImpl::getFeature_EClass() const
{
	return m_feature_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getFeature_EAttribute_isStatic() const
{
	return m_feature_EAttribute_isStatic;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getFeature_EReference_featuringClassifier() const
{
	return m_feature_EReference_featuringClassifier;
}


// End Class Feature

// Begin Class FinalNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getFinalNode_EClass() const
{
	return m_finalNode_EClass;
}



std::shared_ptr<ecore::EOperation> UmlPackageImpl::getFinalNode_EOperation_no_outgoing_edges_EDiagnosticChain_EMap() const
{
	return m_finalNode_EOperation_no_outgoing_edges_EDiagnosticChain_EMap;
}

// End Class FinalNode

// Begin Class FinalState
std::shared_ptr<ecore::EClass> UmlPackageImpl::getFinalState_EClass() const
{
	return m_finalState_EClass;
}



std::shared_ptr<ecore::EOperation> UmlPackageImpl::getFinalState_EOperation_cannot_reference_submachine_EDiagnosticChain_EMap() const
{
	return m_finalState_EOperation_cannot_reference_submachine_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getFinalState_EOperation_no_entry_behavior_EDiagnosticChain_EMap() const
{
	return m_finalState_EOperation_no_entry_behavior_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getFinalState_EOperation_no_exit_behavior_EDiagnosticChain_EMap() const
{
	return m_finalState_EOperation_no_exit_behavior_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getFinalState_EOperation_no_outgoing_transitions_EDiagnosticChain_EMap() const
{
	return m_finalState_EOperation_no_outgoing_transitions_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getFinalState_EOperation_no_regions_EDiagnosticChain_EMap() const
{
	return m_finalState_EOperation_no_regions_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getFinalState_EOperation_no_state_behavior_EDiagnosticChain_EMap() const
{
	return m_finalState_EOperation_no_state_behavior_EDiagnosticChain_EMap;
}

// End Class FinalState

// Begin Class FlowFinalNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getFlowFinalNode_EClass() const
{
	return m_flowFinalNode_EClass;
}




// End Class FlowFinalNode

// Begin Class ForkNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getForkNode_EClass() const
{
	return m_forkNode_EClass;
}



std::shared_ptr<ecore::EOperation> UmlPackageImpl::getForkNode_EOperation_edges_EDiagnosticChain_EMap() const
{
	return m_forkNode_EOperation_edges_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getForkNode_EOperation_one_incoming_edge_EDiagnosticChain_EMap() const
{
	return m_forkNode_EOperation_one_incoming_edge_EDiagnosticChain_EMap;
}

// End Class ForkNode

// Begin Class FunctionBehavior
std::shared_ptr<ecore::EClass> UmlPackageImpl::getFunctionBehavior_EClass() const
{
	return m_functionBehavior_EClass;
}



std::shared_ptr<ecore::EOperation> UmlPackageImpl::getFunctionBehavior_EOperation_hasAllDataTypeAttributes_DataType() const
{
	return m_functionBehavior_EOperation_hasAllDataTypeAttributes_DataType;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getFunctionBehavior_EOperation_one_output_parameter_EDiagnosticChain_EMap() const
{
	return m_functionBehavior_EOperation_one_output_parameter_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getFunctionBehavior_EOperation_types_of_parameters_EDiagnosticChain_EMap() const
{
	return m_functionBehavior_EOperation_types_of_parameters_EDiagnosticChain_EMap;
}

// End Class FunctionBehavior

// Begin Class Gate
std::shared_ptr<ecore::EClass> UmlPackageImpl::getGate_EClass() const
{
	return m_gate_EClass;
}



std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate_EOperation_actual_gate_distinguishable_EDiagnosticChain_EMap() const
{
	return m_gate_EOperation_actual_gate_distinguishable_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate_EOperation_actual_gate_matched_EDiagnosticChain_EMap() const
{
	return m_gate_EOperation_actual_gate_matched_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate_EOperation_formal_gate_distinguishable_EDiagnosticChain_EMap() const
{
	return m_gate_EOperation_formal_gate_distinguishable_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate_EOperation_getName() const
{
	return m_gate_EOperation_getName;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate_EOperation_getOperand() const
{
	return m_gate_EOperation_getOperand;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate_EOperation_inside_cf_gate_distinguishable_EDiagnosticChain_EMap() const
{
	return m_gate_EOperation_inside_cf_gate_distinguishable_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate_EOperation_inside_cf_matched_EDiagnosticChain_EMap() const
{
	return m_gate_EOperation_inside_cf_matched_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate_EOperation_isActual() const
{
	return m_gate_EOperation_isActual;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate_EOperation_isFormal() const
{
	return m_gate_EOperation_isFormal;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate_EOperation_isInsideCF() const
{
	return m_gate_EOperation_isInsideCF;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate_EOperation_isOutsideCF() const
{
	return m_gate_EOperation_isOutsideCF;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate_EOperation_matches_Gate() const
{
	return m_gate_EOperation_matches_Gate;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate_EOperation_outside_cf_gate_distinguishable_EDiagnosticChain_EMap() const
{
	return m_gate_EOperation_outside_cf_gate_distinguishable_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate_EOperation_outside_cf_matched_EDiagnosticChain_EMap() const
{
	return m_gate_EOperation_outside_cf_matched_EDiagnosticChain_EMap;
}

// End Class Gate

// Begin Class GeneralOrdering
std::shared_ptr<ecore::EClass> UmlPackageImpl::getGeneralOrdering_EClass() const
{
	return m_generalOrdering_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getGeneralOrdering_EReference_after() const
{
	return m_generalOrdering_EReference_after;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getGeneralOrdering_EReference_before() const
{
	return m_generalOrdering_EReference_before;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGeneralOrdering_EOperation_irreflexive_transitive_closure_EDiagnosticChain_EMap() const
{
	return m_generalOrdering_EOperation_irreflexive_transitive_closure_EDiagnosticChain_EMap;
}

// End Class GeneralOrdering

// Begin Class Generalization
std::shared_ptr<ecore::EClass> UmlPackageImpl::getGeneralization_EClass() const
{
	return m_generalization_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getGeneralization_EAttribute_isSubstitutable() const
{
	return m_generalization_EAttribute_isSubstitutable;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getGeneralization_EReference_general() const
{
	return m_generalization_EReference_general;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getGeneralization_EReference_generalizationSet() const
{
	return m_generalization_EReference_generalizationSet;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getGeneralization_EReference_specific() const
{
	return m_generalization_EReference_specific;
}


// End Class Generalization

// Begin Class GeneralizationSet
std::shared_ptr<ecore::EClass> UmlPackageImpl::getGeneralizationSet_EClass() const
{
	return m_generalizationSet_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getGeneralizationSet_EAttribute_isCovering() const
{
	return m_generalizationSet_EAttribute_isCovering;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getGeneralizationSet_EAttribute_isDisjoint() const
{
	return m_generalizationSet_EAttribute_isDisjoint;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getGeneralizationSet_EReference_generalization() const
{
	return m_generalizationSet_EReference_generalization;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getGeneralizationSet_EReference_powertype() const
{
	return m_generalizationSet_EReference_powertype;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGeneralizationSet_EOperation_generalization_same_classifier_EDiagnosticChain_EMap() const
{
	return m_generalizationSet_EOperation_generalization_same_classifier_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGeneralizationSet_EOperation_maps_to_generalization_set_EDiagnosticChain_EMap() const
{
	return m_generalizationSet_EOperation_maps_to_generalization_set_EDiagnosticChain_EMap;
}

// End Class GeneralizationSet

// Begin Class Image
std::shared_ptr<ecore::EClass> UmlPackageImpl::getImage_EClass() const
{
	return m_image_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getImage_EAttribute_content() const
{
	return m_image_EAttribute_content;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getImage_EAttribute_format() const
{
	return m_image_EAttribute_format;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getImage_EAttribute_location() const
{
	return m_image_EAttribute_location;
}



// End Class Image

// Begin Class Include
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInclude_EClass() const
{
	return m_include_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getInclude_EReference_addition() const
{
	return m_include_EReference_addition;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInclude_EReference_includingCase() const
{
	return m_include_EReference_includingCase;
}


// End Class Include

// Begin Class InformationFlow
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInformationFlow_EClass() const
{
	return m_informationFlow_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getInformationFlow_EReference_conveyed() const
{
	return m_informationFlow_EReference_conveyed;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInformationFlow_EReference_informationSource() const
{
	return m_informationFlow_EReference_informationSource;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInformationFlow_EReference_informationTarget() const
{
	return m_informationFlow_EReference_informationTarget;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInformationFlow_EReference_realization() const
{
	return m_informationFlow_EReference_realization;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInformationFlow_EReference_realizingActivityEdge() const
{
	return m_informationFlow_EReference_realizingActivityEdge;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInformationFlow_EReference_realizingConnector() const
{
	return m_informationFlow_EReference_realizingConnector;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInformationFlow_EReference_realizingMessage() const
{
	return m_informationFlow_EReference_realizingMessage;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInformationFlow_EOperation_convey_classifiers_EDiagnosticChain_EMap() const
{
	return m_informationFlow_EOperation_convey_classifiers_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInformationFlow_EOperation_must_conform_EDiagnosticChain_EMap() const
{
	return m_informationFlow_EOperation_must_conform_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInformationFlow_EOperation_sources_and_targets_kind_EDiagnosticChain_EMap() const
{
	return m_informationFlow_EOperation_sources_and_targets_kind_EDiagnosticChain_EMap;
}

// End Class InformationFlow

// Begin Class InformationItem
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInformationItem_EClass() const
{
	return m_informationItem_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getInformationItem_EReference_represented() const
{
	return m_informationItem_EReference_represented;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInformationItem_EOperation_has_no_EDiagnosticChain_EMap() const
{
	return m_informationItem_EOperation_has_no_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInformationItem_EOperation_not_instantiable_EDiagnosticChain_EMap() const
{
	return m_informationItem_EOperation_not_instantiable_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInformationItem_EOperation_sources_and_targets_EDiagnosticChain_EMap() const
{
	return m_informationItem_EOperation_sources_and_targets_EDiagnosticChain_EMap;
}

// End Class InformationItem

// Begin Class InitialNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInitialNode_EClass() const
{
	return m_initialNode_EClass;
}



std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInitialNode_EOperation_control_edges_EDiagnosticChain_EMap() const
{
	return m_initialNode_EOperation_control_edges_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInitialNode_EOperation_no_incoming_edges_EDiagnosticChain_EMap() const
{
	return m_initialNode_EOperation_no_incoming_edges_EDiagnosticChain_EMap;
}

// End Class InitialNode

// Begin Class InputPin
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInputPin_EClass() const
{
	return m_inputPin_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getInputPin_EReference_action() const
{
	return m_inputPin_EReference_action;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInputPin_EReference_callOperationAction() const
{
	return m_inputPin_EReference_callOperationAction;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInputPin_EReference_invocationAction() const
{
	return m_inputPin_EReference_invocationAction;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInputPin_EReference_structuralFeatureAction() const
{
	return m_inputPin_EReference_structuralFeatureAction;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInputPin_EOperation_outgoing_edges_structured_only_EDiagnosticChain_EMap() const
{
	return m_inputPin_EOperation_outgoing_edges_structured_only_EDiagnosticChain_EMap;
}

// End Class InputPin

// Begin Class InstanceSpecification
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInstanceSpecification_EClass() const
{
	return m_instanceSpecification_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getInstanceSpecification_EReference_classifier() const
{
	return m_instanceSpecification_EReference_classifier;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInstanceSpecification_EReference_slot() const
{
	return m_instanceSpecification_EReference_slot;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInstanceSpecification_EReference_specification() const
{
	return m_instanceSpecification_EReference_specification;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInstanceSpecification_EOperation_defining_feature_EDiagnosticChain_EMap() const
{
	return m_instanceSpecification_EOperation_defining_feature_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInstanceSpecification_EOperation_deployment_artifact_EDiagnosticChain_EMap() const
{
	return m_instanceSpecification_EOperation_deployment_artifact_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInstanceSpecification_EOperation_deployment_target_EDiagnosticChain_EMap() const
{
	return m_instanceSpecification_EOperation_deployment_target_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInstanceSpecification_EOperation_structural_feature_EDiagnosticChain_EMap() const
{
	return m_instanceSpecification_EOperation_structural_feature_EDiagnosticChain_EMap;
}

// End Class InstanceSpecification

// Begin Class InstanceValue
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInstanceValue_EClass() const
{
	return m_instanceValue_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getInstanceValue_EReference_instance() const
{
	return m_instanceValue_EReference_instance;
}


// End Class InstanceValue

// Begin Class Interaction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInteraction_EClass() const
{
	return m_interaction_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteraction_EReference_action() const
{
	return m_interaction_EReference_action;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteraction_EReference_formalGate() const
{
	return m_interaction_EReference_formalGate;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteraction_EReference_fragment() const
{
	return m_interaction_EReference_fragment;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteraction_EReference_lifeline() const
{
	return m_interaction_EReference_lifeline;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteraction_EReference_message() const
{
	return m_interaction_EReference_message;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteraction_EOperation_not_contained_EDiagnosticChain_EMap() const
{
	return m_interaction_EOperation_not_contained_EDiagnosticChain_EMap;
}

// End Class Interaction

// Begin Class InteractionConstraint
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInteractionConstraint_EClass() const
{
	return m_interactionConstraint_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteractionConstraint_EReference_maxint() const
{
	return m_interactionConstraint_EReference_maxint;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteractionConstraint_EReference_minint() const
{
	return m_interactionConstraint_EReference_minint;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionConstraint_EOperation_dynamic_variables_EDiagnosticChain_EMap() const
{
	return m_interactionConstraint_EOperation_dynamic_variables_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionConstraint_EOperation_global_data_EDiagnosticChain_EMap() const
{
	return m_interactionConstraint_EOperation_global_data_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionConstraint_EOperation_maxint_greater_equal_minint_EDiagnosticChain_EMap() const
{
	return m_interactionConstraint_EOperation_maxint_greater_equal_minint_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionConstraint_EOperation_maxint_positive_EDiagnosticChain_EMap() const
{
	return m_interactionConstraint_EOperation_maxint_positive_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionConstraint_EOperation_minint_maxint_EDiagnosticChain_EMap() const
{
	return m_interactionConstraint_EOperation_minint_maxint_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionConstraint_EOperation_minint_non_negative_EDiagnosticChain_EMap() const
{
	return m_interactionConstraint_EOperation_minint_non_negative_EDiagnosticChain_EMap;
}

// End Class InteractionConstraint

// Begin Class InteractionFragment
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInteractionFragment_EClass() const
{
	return m_interactionFragment_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteractionFragment_EReference_covered() const
{
	return m_interactionFragment_EReference_covered;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteractionFragment_EReference_enclosingInteraction() const
{
	return m_interactionFragment_EReference_enclosingInteraction;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteractionFragment_EReference_enclosingOperand() const
{
	return m_interactionFragment_EReference_enclosingOperand;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteractionFragment_EReference_generalOrdering() const
{
	return m_interactionFragment_EReference_generalOrdering;
}


// End Class InteractionFragment

// Begin Class InteractionOperand
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInteractionOperand_EClass() const
{
	return m_interactionOperand_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteractionOperand_EReference_fragment() const
{
	return m_interactionOperand_EReference_fragment;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteractionOperand_EReference_guard() const
{
	return m_interactionOperand_EReference_guard;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionOperand_EOperation_guard_contain_references_EDiagnosticChain_EMap() const
{
	return m_interactionOperand_EOperation_guard_contain_references_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionOperand_EOperation_guard_directly_prior_EDiagnosticChain_EMap() const
{
	return m_interactionOperand_EOperation_guard_directly_prior_EDiagnosticChain_EMap;
}

// End Class InteractionOperand

// Begin Class InteractionUse
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInteractionUse_EClass() const
{
	return m_interactionUse_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteractionUse_EReference_actualGate() const
{
	return m_interactionUse_EReference_actualGate;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteractionUse_EReference_argument() const
{
	return m_interactionUse_EReference_argument;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteractionUse_EReference_refersTo() const
{
	return m_interactionUse_EReference_refersTo;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteractionUse_EReference_returnValue() const
{
	return m_interactionUse_EReference_returnValue;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteractionUse_EReference_returnValueRecipient() const
{
	return m_interactionUse_EReference_returnValueRecipient;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionUse_EOperation_all_lifelines_EDiagnosticChain_EMap() const
{
	return m_interactionUse_EOperation_all_lifelines_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionUse_EOperation_arguments_are_constants_EDiagnosticChain_EMap() const
{
	return m_interactionUse_EOperation_arguments_are_constants_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionUse_EOperation_arguments_correspond_to_parameters_EDiagnosticChain_EMap() const
{
	return m_interactionUse_EOperation_arguments_correspond_to_parameters_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionUse_EOperation_gates_match_EDiagnosticChain_EMap() const
{
	return m_interactionUse_EOperation_gates_match_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionUse_EOperation_returnValueRecipient_coverage_EDiagnosticChain_EMap() const
{
	return m_interactionUse_EOperation_returnValueRecipient_coverage_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionUse_EOperation_returnValue_type_recipient_correspondence_EDiagnosticChain_EMap() const
{
	return m_interactionUse_EOperation_returnValue_type_recipient_correspondence_EDiagnosticChain_EMap;
}

// End Class InteractionUse

// Begin Class Interface
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInterface_EClass() const
{
	return m_interface_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getInterface_EReference_nestedClassifier() const
{
	return m_interface_EReference_nestedClassifier;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInterface_EReference_ownedAttribute() const
{
	return m_interface_EReference_ownedAttribute;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInterface_EReference_ownedOperation() const
{
	return m_interface_EReference_ownedOperation;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInterface_EReference_ownedReception() const
{
	return m_interface_EReference_ownedReception;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInterface_EReference_protocol() const
{
	return m_interface_EReference_protocol;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInterface_EReference_redefinedInterface() const
{
	return m_interface_EReference_redefinedInterface;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInterface_EOperation_createOwnedAttribute_String_UnlimitedNatural() const
{
	return m_interface_EOperation_createOwnedAttribute_String_UnlimitedNatural;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInterface_EOperation_createOwnedOperation_String_Type() const
{
	return m_interface_EOperation_createOwnedOperation_String_Type;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInterface_EOperation_visibility_EDiagnosticChain_EMap() const
{
	return m_interface_EOperation_visibility_EDiagnosticChain_EMap;
}

// End Class Interface

// Begin Class InterfaceRealization
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInterfaceRealization_EClass() const
{
	return m_interfaceRealization_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getInterfaceRealization_EReference_contract() const
{
	return m_interfaceRealization_EReference_contract;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInterfaceRealization_EReference_implementingClassifier() const
{
	return m_interfaceRealization_EReference_implementingClassifier;
}


// End Class InterfaceRealization

// Begin Class InterruptibleActivityRegion
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInterruptibleActivityRegion_EClass() const
{
	return m_interruptibleActivityRegion_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getInterruptibleActivityRegion_EReference_interruptingEdge() const
{
	return m_interruptibleActivityRegion_EReference_interruptingEdge;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInterruptibleActivityRegion_EReference_node() const
{
	return m_interruptibleActivityRegion_EReference_node;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInterruptibleActivityRegion_EOperation_interrupting_edges_EDiagnosticChain_EMap() const
{
	return m_interruptibleActivityRegion_EOperation_interrupting_edges_EDiagnosticChain_EMap;
}

// End Class InterruptibleActivityRegion

// Begin Class Interval
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInterval_EClass() const
{
	return m_interval_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getInterval_EReference_max() const
{
	return m_interval_EReference_max;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInterval_EReference_min() const
{
	return m_interval_EReference_min;
}


// End Class Interval

// Begin Class IntervalConstraint
std::shared_ptr<ecore::EClass> UmlPackageImpl::getIntervalConstraint_EClass() const
{
	return m_intervalConstraint_EClass;
}




// End Class IntervalConstraint

// Begin Class InvocationAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInvocationAction_EClass() const
{
	return m_invocationAction_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getInvocationAction_EReference_argument() const
{
	return m_invocationAction_EReference_argument;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInvocationAction_EReference_onPort() const
{
	return m_invocationAction_EReference_onPort;
}


// End Class InvocationAction

// Begin Class JoinNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getJoinNode_EClass() const
{
	return m_joinNode_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getJoinNode_EAttribute_isCombineDuplicate() const
{
	return m_joinNode_EAttribute_isCombineDuplicate;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getJoinNode_EReference_joinSpec() const
{
	return m_joinNode_EReference_joinSpec;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getJoinNode_EOperation_incoming_object_flow_EDiagnosticChain_EMap() const
{
	return m_joinNode_EOperation_incoming_object_flow_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getJoinNode_EOperation_one_outgoing_edge_EDiagnosticChain_EMap() const
{
	return m_joinNode_EOperation_one_outgoing_edge_EDiagnosticChain_EMap;
}

// End Class JoinNode

// Begin Class Lifeline
std::shared_ptr<ecore::EClass> UmlPackageImpl::getLifeline_EClass() const
{
	return m_lifeline_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getLifeline_EReference_coveredBy() const
{
	return m_lifeline_EReference_coveredBy;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLifeline_EReference_decomposedAs() const
{
	return m_lifeline_EReference_decomposedAs;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLifeline_EReference_interaction() const
{
	return m_lifeline_EReference_interaction;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLifeline_EReference_represents() const
{
	return m_lifeline_EReference_represents;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLifeline_EReference_selector() const
{
	return m_lifeline_EReference_selector;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLifeline_EOperation_interaction_uses_share_lifeline_EDiagnosticChain_EMap() const
{
	return m_lifeline_EOperation_interaction_uses_share_lifeline_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLifeline_EOperation_same_classifier_EDiagnosticChain_EMap() const
{
	return m_lifeline_EOperation_same_classifier_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLifeline_EOperation_selector_int_or_string_EDiagnosticChain_EMap() const
{
	return m_lifeline_EOperation_selector_int_or_string_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLifeline_EOperation_selector_specified_EDiagnosticChain_EMap() const
{
	return m_lifeline_EOperation_selector_specified_EDiagnosticChain_EMap;
}

// End Class Lifeline

// Begin Class LinkAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getLinkAction_EClass() const
{
	return m_linkAction_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getLinkAction_EReference_endData() const
{
	return m_linkAction_EReference_endData;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLinkAction_EReference_inputValue() const
{
	return m_linkAction_EReference_inputValue;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLinkAction_EOperation_association() const
{
	return m_linkAction_EOperation_association;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLinkAction_EOperation_not_static_EDiagnosticChain_EMap() const
{
	return m_linkAction_EOperation_not_static_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLinkAction_EOperation_same_association_EDiagnosticChain_EMap() const
{
	return m_linkAction_EOperation_same_association_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLinkAction_EOperation_same_pins_EDiagnosticChain_EMap() const
{
	return m_linkAction_EOperation_same_pins_EDiagnosticChain_EMap;
}

// End Class LinkAction

// Begin Class LinkEndCreationData
std::shared_ptr<ecore::EClass> UmlPackageImpl::getLinkEndCreationData_EClass() const
{
	return m_linkEndCreationData_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getLinkEndCreationData_EAttribute_isReplaceAll() const
{
	return m_linkEndCreationData_EAttribute_isReplaceAll;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getLinkEndCreationData_EReference_insertAt() const
{
	return m_linkEndCreationData_EReference_insertAt;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLinkEndCreationData_EOperation_insertAt_pin_EDiagnosticChain_EMap() const
{
	return m_linkEndCreationData_EOperation_insertAt_pin_EDiagnosticChain_EMap;
}

// End Class LinkEndCreationData

// Begin Class LinkEndData
std::shared_ptr<ecore::EClass> UmlPackageImpl::getLinkEndData_EClass() const
{
	return m_linkEndData_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getLinkEndData_EReference_end() const
{
	return m_linkEndData_EReference_end;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLinkEndData_EReference_qualifier() const
{
	return m_linkEndData_EReference_qualifier;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLinkEndData_EReference_value() const
{
	return m_linkEndData_EReference_value;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLinkEndData_EOperation_allPins() const
{
	return m_linkEndData_EOperation_allPins;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLinkEndData_EOperation_end_object_input_pin_EDiagnosticChain_EMap() const
{
	return m_linkEndData_EOperation_end_object_input_pin_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLinkEndData_EOperation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_linkEndData_EOperation_multiplicity_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLinkEndData_EOperation_property_is_association_end_EDiagnosticChain_EMap() const
{
	return m_linkEndData_EOperation_property_is_association_end_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLinkEndData_EOperation_qualifiers_EDiagnosticChain_EMap() const
{
	return m_linkEndData_EOperation_qualifiers_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLinkEndData_EOperation_same_type_EDiagnosticChain_EMap() const
{
	return m_linkEndData_EOperation_same_type_EDiagnosticChain_EMap;
}

// End Class LinkEndData

// Begin Class LinkEndDestructionData
std::shared_ptr<ecore::EClass> UmlPackageImpl::getLinkEndDestructionData_EClass() const
{
	return m_linkEndDestructionData_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getLinkEndDestructionData_EAttribute_isDestroyDuplicates() const
{
	return m_linkEndDestructionData_EAttribute_isDestroyDuplicates;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getLinkEndDestructionData_EReference_destroyAt() const
{
	return m_linkEndDestructionData_EReference_destroyAt;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLinkEndDestructionData_EOperation_destroyAt_pin_EDiagnosticChain_EMap() const
{
	return m_linkEndDestructionData_EOperation_destroyAt_pin_EDiagnosticChain_EMap;
}

// End Class LinkEndDestructionData

// Begin Class LiteralBoolean
std::shared_ptr<ecore::EClass> UmlPackageImpl::getLiteralBoolean_EClass() const
{
	return m_literalBoolean_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getLiteralBoolean_EAttribute_value() const
{
	return m_literalBoolean_EAttribute_value;
}



// End Class LiteralBoolean

// Begin Class LiteralInteger
std::shared_ptr<ecore::EClass> UmlPackageImpl::getLiteralInteger_EClass() const
{
	return m_literalInteger_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getLiteralInteger_EAttribute_value() const
{
	return m_literalInteger_EAttribute_value;
}



// End Class LiteralInteger

// Begin Class LiteralNull
std::shared_ptr<ecore::EClass> UmlPackageImpl::getLiteralNull_EClass() const
{
	return m_literalNull_EClass;
}




// End Class LiteralNull

// Begin Class LiteralReal
std::shared_ptr<ecore::EClass> UmlPackageImpl::getLiteralReal_EClass() const
{
	return m_literalReal_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getLiteralReal_EAttribute_value() const
{
	return m_literalReal_EAttribute_value;
}



// End Class LiteralReal

// Begin Class LiteralSpecification
std::shared_ptr<ecore::EClass> UmlPackageImpl::getLiteralSpecification_EClass() const
{
	return m_literalSpecification_EClass;
}




// End Class LiteralSpecification

// Begin Class LiteralString
std::shared_ptr<ecore::EClass> UmlPackageImpl::getLiteralString_EClass() const
{
	return m_literalString_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getLiteralString_EAttribute_value() const
{
	return m_literalString_EAttribute_value;
}



// End Class LiteralString

// Begin Class LiteralUnlimitedNatural
std::shared_ptr<ecore::EClass> UmlPackageImpl::getLiteralUnlimitedNatural_EClass() const
{
	return m_literalUnlimitedNatural_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getLiteralUnlimitedNatural_EAttribute_value() const
{
	return m_literalUnlimitedNatural_EAttribute_value;
}



// End Class LiteralUnlimitedNatural

// Begin Class LoopNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getLoopNode_EClass() const
{
	return m_loopNode_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getLoopNode_EAttribute_isTestedFirst() const
{
	return m_loopNode_EAttribute_isTestedFirst;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getLoopNode_EReference_bodyOutput() const
{
	return m_loopNode_EReference_bodyOutput;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLoopNode_EReference_bodyPart() const
{
	return m_loopNode_EReference_bodyPart;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLoopNode_EReference_decider() const
{
	return m_loopNode_EReference_decider;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLoopNode_EReference_loopVariable() const
{
	return m_loopNode_EReference_loopVariable;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLoopNode_EReference_loopVariableInput() const
{
	return m_loopNode_EReference_loopVariableInput;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLoopNode_EReference_result() const
{
	return m_loopNode_EReference_result;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLoopNode_EReference_setupPart() const
{
	return m_loopNode_EReference_setupPart;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLoopNode_EReference_test() const
{
	return m_loopNode_EReference_test;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLoopNode_EOperation_body_output_pins_EDiagnosticChain_EMap() const
{
	return m_loopNode_EOperation_body_output_pins_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLoopNode_EOperation_executable_nodes_EDiagnosticChain_EMap() const
{
	return m_loopNode_EOperation_executable_nodes_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLoopNode_EOperation_input_edges_EDiagnosticChain_EMap() const
{
	return m_loopNode_EOperation_input_edges_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLoopNode_EOperation_loop_variable_outgoing_EDiagnosticChain_EMap() const
{
	return m_loopNode_EOperation_loop_variable_outgoing_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLoopNode_EOperation_matching_loop_variables_EDiagnosticChain_EMap() const
{
	return m_loopNode_EOperation_matching_loop_variables_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLoopNode_EOperation_matching_output_pins_EDiagnosticChain_EMap() const
{
	return m_loopNode_EOperation_matching_output_pins_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLoopNode_EOperation_matching_result_pins_EDiagnosticChain_EMap() const
{
	return m_loopNode_EOperation_matching_result_pins_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLoopNode_EOperation_result_no_incoming_EDiagnosticChain_EMap() const
{
	return m_loopNode_EOperation_result_no_incoming_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLoopNode_EOperation_setup_test_and_body_EDiagnosticChain_EMap() const
{
	return m_loopNode_EOperation_setup_test_and_body_EDiagnosticChain_EMap;
}

// End Class LoopNode

// Begin Class Manifestation
std::shared_ptr<ecore::EClass> UmlPackageImpl::getManifestation_EClass() const
{
	return m_manifestation_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getManifestation_EReference_utilizedElement() const
{
	return m_manifestation_EReference_utilizedElement;
}


// End Class Manifestation

// Begin Class MergeNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getMergeNode_EClass() const
{
	return m_mergeNode_EClass;
}



std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMergeNode_EOperation_edges_EDiagnosticChain_EMap() const
{
	return m_mergeNode_EOperation_edges_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMergeNode_EOperation_one_outgoing_edge_EDiagnosticChain_EMap() const
{
	return m_mergeNode_EOperation_one_outgoing_edge_EDiagnosticChain_EMap;
}

// End Class MergeNode

// Begin Class Message
std::shared_ptr<ecore::EClass> UmlPackageImpl::getMessage_EClass() const
{
	return m_message_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getMessage_EAttribute_messageKind() const
{
	return m_message_EAttribute_messageKind;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getMessage_EAttribute_messageSort() const
{
	return m_message_EAttribute_messageSort;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getMessage_EReference_argument() const
{
	return m_message_EReference_argument;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getMessage_EReference_connector() const
{
	return m_message_EReference_connector;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getMessage_EReference_interaction() const
{
	return m_message_EReference_interaction;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getMessage_EReference_receiveEvent() const
{
	return m_message_EReference_receiveEvent;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getMessage_EReference_sendEvent() const
{
	return m_message_EReference_sendEvent;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getMessage_EReference_signature() const
{
	return m_message_EReference_signature;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMessage_EOperation_arguments_EDiagnosticChain_EMap() const
{
	return m_message_EOperation_arguments_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMessage_EOperation_cannot_cross_boundaries_EDiagnosticChain_EMap() const
{
	return m_message_EOperation_cannot_cross_boundaries_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMessage_EOperation_getMessageKind() const
{
	return m_message_EOperation_getMessageKind;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMessage_EOperation_occurrence_specifications_EDiagnosticChain_EMap() const
{
	return m_message_EOperation_occurrence_specifications_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMessage_EOperation_sending_receiving_message_event_EDiagnosticChain_EMap() const
{
	return m_message_EOperation_sending_receiving_message_event_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMessage_EOperation_signature_is_operation_reply_EDiagnosticChain_EMap() const
{
	return m_message_EOperation_signature_is_operation_reply_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMessage_EOperation_signature_is_operation_request_EDiagnosticChain_EMap() const
{
	return m_message_EOperation_signature_is_operation_request_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMessage_EOperation_signature_is_signal_EDiagnosticChain_EMap() const
{
	return m_message_EOperation_signature_is_signal_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMessage_EOperation_signature_refer_to_EDiagnosticChain_EMap() const
{
	return m_message_EOperation_signature_refer_to_EDiagnosticChain_EMap;
}

// End Class Message

// Begin Class MessageEnd
std::shared_ptr<ecore::EClass> UmlPackageImpl::getMessageEnd_EClass() const
{
	return m_messageEnd_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getMessageEnd_EReference_message() const
{
	return m_messageEnd_EReference_message;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMessageEnd_EOperation_enclosingFragment() const
{
	return m_messageEnd_EOperation_enclosingFragment;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMessageEnd_EOperation_isReceive() const
{
	return m_messageEnd_EOperation_isReceive;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMessageEnd_EOperation_isSend() const
{
	return m_messageEnd_EOperation_isSend;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMessageEnd_EOperation_oppositeEnd() const
{
	return m_messageEnd_EOperation_oppositeEnd;
}

// End Class MessageEnd

// Begin Class MessageEvent
std::shared_ptr<ecore::EClass> UmlPackageImpl::getMessageEvent_EClass() const
{
	return m_messageEvent_EClass;
}




// End Class MessageEvent

// Begin Class MessageOccurrenceSpecification
std::shared_ptr<ecore::EClass> UmlPackageImpl::getMessageOccurrenceSpecification_EClass() const
{
	return m_messageOccurrenceSpecification_EClass;
}




// End Class MessageOccurrenceSpecification

// Begin Class Model
std::shared_ptr<ecore::EClass> UmlPackageImpl::getModel_EClass() const
{
	return m_model_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getModel_EAttribute_viewpoint() const
{
	return m_model_EAttribute_viewpoint;
}


std::shared_ptr<ecore::EOperation> UmlPackageImpl::getModel_EOperation_isMetamodel() const
{
	return m_model_EOperation_isMetamodel;
}

// End Class Model

// Begin Class MultiplicityElement
std::shared_ptr<ecore::EClass> UmlPackageImpl::getMultiplicityElement_EClass() const
{
	return m_multiplicityElement_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getMultiplicityElement_EAttribute_isOrdered() const
{
	return m_multiplicityElement_EAttribute_isOrdered;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getMultiplicityElement_EAttribute_isUnique() const
{
	return m_multiplicityElement_EAttribute_isUnique;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getMultiplicityElement_EAttribute_lower() const
{
	return m_multiplicityElement_EAttribute_lower;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getMultiplicityElement_EAttribute_upper() const
{
	return m_multiplicityElement_EAttribute_upper;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getMultiplicityElement_EReference_lowerValue() const
{
	return m_multiplicityElement_EReference_lowerValue;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getMultiplicityElement_EReference_upperValue() const
{
	return m_multiplicityElement_EReference_upperValue;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMultiplicityElement_EOperation_compatibleWith_MultiplicityElement() const
{
	return m_multiplicityElement_EOperation_compatibleWith_MultiplicityElement;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMultiplicityElement_EOperation_includesMultiplicity_MultiplicityElement() const
{
	return m_multiplicityElement_EOperation_includesMultiplicity_MultiplicityElement;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMultiplicityElement_EOperation_is_Integer_UnlimitedNatural() const
{
	return m_multiplicityElement_EOperation_is_Integer_UnlimitedNatural;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMultiplicityElement_EOperation_isMultivalued() const
{
	return m_multiplicityElement_EOperation_isMultivalued;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMultiplicityElement_EOperation_lowerBound() const
{
	return m_multiplicityElement_EOperation_lowerBound;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMultiplicityElement_EOperation_lower_ge_0_EDiagnosticChain_EMap() const
{
	return m_multiplicityElement_EOperation_lower_ge_0_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMultiplicityElement_EOperation_lower_is_integer_EDiagnosticChain_EMap() const
{
	return m_multiplicityElement_EOperation_lower_is_integer_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMultiplicityElement_EOperation_upperBound() const
{
	return m_multiplicityElement_EOperation_upperBound;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMultiplicityElement_EOperation_upper_ge_lower_EDiagnosticChain_EMap() const
{
	return m_multiplicityElement_EOperation_upper_ge_lower_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMultiplicityElement_EOperation_upper_is_unlimitedNatural_EDiagnosticChain_EMap() const
{
	return m_multiplicityElement_EOperation_upper_is_unlimitedNatural_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMultiplicityElement_EOperation_value_specification_constant_EDiagnosticChain_EMap() const
{
	return m_multiplicityElement_EOperation_value_specification_constant_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMultiplicityElement_EOperation_value_specification_no_side_effects_EDiagnosticChain_EMap() const
{
	return m_multiplicityElement_EOperation_value_specification_no_side_effects_EDiagnosticChain_EMap;
}

// End Class MultiplicityElement

// Begin Class NamedElement
std::shared_ptr<ecore::EClass> UmlPackageImpl::getNamedElement_EClass() const
{
	return m_namedElement_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getNamedElement_EAttribute_name() const
{
	return m_namedElement_EAttribute_name;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getNamedElement_EAttribute_qualifiedName() const
{
	return m_namedElement_EAttribute_qualifiedName;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getNamedElement_EAttribute_visibility() const
{
	return m_namedElement_EAttribute_visibility;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getNamedElement_EReference_clientDependency() const
{
	return m_namedElement_EReference_clientDependency;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getNamedElement_EReference_nameExpression() const
{
	return m_namedElement_EReference_nameExpression;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getNamedElement_EReference_namespace() const
{
	return m_namedElement_EReference_namespace;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement_EOperation_allNamespaces() const
{
	return m_namedElement_EOperation_allNamespaces;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement_EOperation_allOwningPackages() const
{
	return m_namedElement_EOperation_allOwningPackages;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement_EOperation_createDependency_NamedElement() const
{
	return m_namedElement_EOperation_createDependency_NamedElement;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement_EOperation_createUsage_NamedElement() const
{
	return m_namedElement_EOperation_createUsage_NamedElement;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement_EOperation_getClientDependencies() const
{
	return m_namedElement_EOperation_getClientDependencies;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement_EOperation_getLabel() const
{
	return m_namedElement_EOperation_getLabel;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement_EOperation_getLabel_Boolean() const
{
	return m_namedElement_EOperation_getLabel_Boolean;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement_EOperation_getNamespace() const
{
	return m_namedElement_EOperation_getNamespace;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement_EOperation_getQualifiedName() const
{
	return m_namedElement_EOperation_getQualifiedName;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement_EOperation_has_no_qualified_name_EDiagnosticChain_EMap() const
{
	return m_namedElement_EOperation_has_no_qualified_name_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement_EOperation_has_qualified_name_EDiagnosticChain_EMap() const
{
	return m_namedElement_EOperation_has_qualified_name_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement_EOperation_isDistinguishableFrom_NamedElement_Namespace() const
{
	return m_namedElement_EOperation_isDistinguishableFrom_NamedElement_Namespace;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement_EOperation_separator() const
{
	return m_namedElement_EOperation_separator;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement_EOperation_visibility_needs_ownership_EDiagnosticChain_EMap() const
{
	return m_namedElement_EOperation_visibility_needs_ownership_EDiagnosticChain_EMap;
}

// End Class NamedElement

// Begin Class Namespace
std::shared_ptr<ecore::EClass> UmlPackageImpl::getNamespace_EClass() const
{
	return m_namespace_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getNamespace_EReference_elementImport() const
{
	return m_namespace_EReference_elementImport;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getNamespace_EReference_importedMember() const
{
	return m_namespace_EReference_importedMember;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getNamespace_EReference_member() const
{
	return m_namespace_EReference_member;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getNamespace_EReference_ownedMember() const
{
	return m_namespace_EReference_ownedMember;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getNamespace_EReference_ownedRule() const
{
	return m_namespace_EReference_ownedRule;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getNamespace_EReference_packageImport() const
{
	return m_namespace_EReference_packageImport;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamespace_EOperation_cannot_import_ownedMembers_EDiagnosticChain_EMap() const
{
	return m_namespace_EOperation_cannot_import_ownedMembers_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamespace_EOperation_cannot_import_self_EDiagnosticChain_EMap() const
{
	return m_namespace_EOperation_cannot_import_self_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamespace_EOperation_createElementImport_PackageableElement_VisibilityKind() const
{
	return m_namespace_EOperation_createElementImport_PackageableElement_VisibilityKind;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamespace_EOperation_createPackageImport_Package_VisibilityKind() const
{
	return m_namespace_EOperation_createPackageImport_Package_VisibilityKind;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamespace_EOperation_excludeCollisions_PackageableElement() const
{
	return m_namespace_EOperation_excludeCollisions_PackageableElement;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamespace_EOperation_getImportedElements() const
{
	return m_namespace_EOperation_getImportedElements;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamespace_EOperation_getImportedMembers() const
{
	return m_namespace_EOperation_getImportedMembers;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamespace_EOperation_getImportedPackages() const
{
	return m_namespace_EOperation_getImportedPackages;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamespace_EOperation_getNamesOfMember_NamedElement() const
{
	return m_namespace_EOperation_getNamesOfMember_NamedElement;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamespace_EOperation_getOwnedMembers() const
{
	return m_namespace_EOperation_getOwnedMembers;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamespace_EOperation_importMembers_PackageableElement() const
{
	return m_namespace_EOperation_importMembers_PackageableElement;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamespace_EOperation_membersAreDistinguishable() const
{
	return m_namespace_EOperation_membersAreDistinguishable;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamespace_EOperation_members_distinguishable_EDiagnosticChain_EMap() const
{
	return m_namespace_EOperation_members_distinguishable_EDiagnosticChain_EMap;
}

// End Class Namespace

// Begin Class Node
std::shared_ptr<ecore::EClass> UmlPackageImpl::getNode_EClass() const
{
	return m_node_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getNode_EReference_nestedNode() const
{
	return m_node_EReference_nestedNode;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNode_EOperation_createCommunicationPath_Boolean_UnlimitedNatural() const
{
	return m_node_EOperation_createCommunicationPath_Boolean_UnlimitedNatural;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNode_EOperation_getCommunicationPaths() const
{
	return m_node_EOperation_getCommunicationPaths;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNode_EOperation_internal_structure_EDiagnosticChain_EMap() const
{
	return m_node_EOperation_internal_structure_EDiagnosticChain_EMap;
}

// End Class Node

// Begin Class Object
std::shared_ptr<ecore::EClass> UmlPackageImpl::getObject_EClass() const
{
	return m_object_EClass;
}



std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObject_EOperation_get_Property() const
{
	return m_object_EOperation_get_Property;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObject_EOperation_set_Property_EJavaObject() const
{
	return m_object_EOperation_set_Property_EJavaObject;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObject_EOperation_unset_Property() const
{
	return m_object_EOperation_unset_Property;
}

// End Class Object

// Begin Class ObjectFlow
std::shared_ptr<ecore::EClass> UmlPackageImpl::getObjectFlow_EClass() const
{
	return m_objectFlow_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getObjectFlow_EAttribute_isMulticast() const
{
	return m_objectFlow_EAttribute_isMulticast;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getObjectFlow_EAttribute_isMultireceive() const
{
	return m_objectFlow_EAttribute_isMultireceive;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getObjectFlow_EReference_selection() const
{
	return m_objectFlow_EReference_selection;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getObjectFlow_EReference_transformation() const
{
	return m_objectFlow_EReference_transformation;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObjectFlow_EOperation_compatible_types_EDiagnosticChain_EMap() const
{
	return m_objectFlow_EOperation_compatible_types_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObjectFlow_EOperation_input_and_output_parameter_EDiagnosticChain_EMap() const
{
	return m_objectFlow_EOperation_input_and_output_parameter_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObjectFlow_EOperation_is_multicast_or_is_multireceive_EDiagnosticChain_EMap() const
{
	return m_objectFlow_EOperation_is_multicast_or_is_multireceive_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObjectFlow_EOperation_no_executable_nodes_EDiagnosticChain_EMap() const
{
	return m_objectFlow_EOperation_no_executable_nodes_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObjectFlow_EOperation_same_upper_bounds_EDiagnosticChain_EMap() const
{
	return m_objectFlow_EOperation_same_upper_bounds_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObjectFlow_EOperation_selection_behavior_EDiagnosticChain_EMap() const
{
	return m_objectFlow_EOperation_selection_behavior_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObjectFlow_EOperation_target_EDiagnosticChain_EMap() const
{
	return m_objectFlow_EOperation_target_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObjectFlow_EOperation_transformation_behavior_EDiagnosticChain_EMap() const
{
	return m_objectFlow_EOperation_transformation_behavior_EDiagnosticChain_EMap;
}

// End Class ObjectFlow

// Begin Class ObjectNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getObjectNode_EClass() const
{
	return m_objectNode_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getObjectNode_EAttribute_isControlType() const
{
	return m_objectNode_EAttribute_isControlType;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getObjectNode_EAttribute_ordering() const
{
	return m_objectNode_EAttribute_ordering;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getObjectNode_EReference_inState() const
{
	return m_objectNode_EReference_inState;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getObjectNode_EReference_selection() const
{
	return m_objectNode_EReference_selection;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getObjectNode_EReference_upperBound() const
{
	return m_objectNode_EReference_upperBound;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObjectNode_EOperation_input_output_parameter_EDiagnosticChain_EMap() const
{
	return m_objectNode_EOperation_input_output_parameter_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObjectNode_EOperation_object_flow_edges_EDiagnosticChain_EMap() const
{
	return m_objectNode_EOperation_object_flow_edges_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObjectNode_EOperation_selection_behavior_EDiagnosticChain_EMap() const
{
	return m_objectNode_EOperation_selection_behavior_EDiagnosticChain_EMap;
}

// End Class ObjectNode

// Begin Class Observation
std::shared_ptr<ecore::EClass> UmlPackageImpl::getObservation_EClass() const
{
	return m_observation_EClass;
}




// End Class Observation

// Begin Class OccurrenceSpecification
std::shared_ptr<ecore::EClass> UmlPackageImpl::getOccurrenceSpecification_EClass() const
{
	return m_occurrenceSpecification_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getOccurrenceSpecification_EReference_toAfter() const
{
	return m_occurrenceSpecification_EReference_toAfter;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getOccurrenceSpecification_EReference_toBefore() const
{
	return m_occurrenceSpecification_EReference_toBefore;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOccurrenceSpecification_EOperation_getCovered() const
{
	return m_occurrenceSpecification_EOperation_getCovered;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOccurrenceSpecification_EOperation_setCovered_Lifeline() const
{
	return m_occurrenceSpecification_EOperation_setCovered_Lifeline;
}

// End Class OccurrenceSpecification

// Begin Class OpaqueAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getOpaqueAction_EClass() const
{
	return m_opaqueAction_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getOpaqueAction_EAttribute_body() const
{
	return m_opaqueAction_EAttribute_body;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getOpaqueAction_EAttribute_language() const
{
	return m_opaqueAction_EAttribute_language;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getOpaqueAction_EReference_inputValue() const
{
	return m_opaqueAction_EReference_inputValue;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getOpaqueAction_EReference_outputValue() const
{
	return m_opaqueAction_EReference_outputValue;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOpaqueAction_EOperation_language_body_size_EDiagnosticChain_EMap() const
{
	return m_opaqueAction_EOperation_language_body_size_EDiagnosticChain_EMap;
}

// End Class OpaqueAction

// Begin Class OpaqueBehavior
std::shared_ptr<ecore::EClass> UmlPackageImpl::getOpaqueBehavior_EClass() const
{
	return m_opaqueBehavior_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getOpaqueBehavior_EAttribute_body() const
{
	return m_opaqueBehavior_EAttribute_body;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getOpaqueBehavior_EAttribute_language() const
{
	return m_opaqueBehavior_EAttribute_language;
}



// End Class OpaqueBehavior

// Begin Class OpaqueExpression
std::shared_ptr<ecore::EClass> UmlPackageImpl::getOpaqueExpression_EClass() const
{
	return m_opaqueExpression_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getOpaqueExpression_EAttribute_body() const
{
	return m_opaqueExpression_EAttribute_body;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getOpaqueExpression_EAttribute_language() const
{
	return m_opaqueExpression_EAttribute_language;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getOpaqueExpression_EReference_behavior() const
{
	return m_opaqueExpression_EReference_behavior;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getOpaqueExpression_EReference_result() const
{
	return m_opaqueExpression_EReference_result;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOpaqueExpression_EOperation_getResult() const
{
	return m_opaqueExpression_EOperation_getResult;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOpaqueExpression_EOperation_isIntegral() const
{
	return m_opaqueExpression_EOperation_isIntegral;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOpaqueExpression_EOperation_isNonNegative() const
{
	return m_opaqueExpression_EOperation_isNonNegative;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOpaqueExpression_EOperation_isPositive() const
{
	return m_opaqueExpression_EOperation_isPositive;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOpaqueExpression_EOperation_language_body_size_EDiagnosticChain_EMap() const
{
	return m_opaqueExpression_EOperation_language_body_size_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOpaqueExpression_EOperation_one_return_result_parameter_EDiagnosticChain_EMap() const
{
	return m_opaqueExpression_EOperation_one_return_result_parameter_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOpaqueExpression_EOperation_only_return_result_parameters_EDiagnosticChain_EMap() const
{
	return m_opaqueExpression_EOperation_only_return_result_parameters_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOpaqueExpression_EOperation_value() const
{
	return m_opaqueExpression_EOperation_value;
}

// End Class OpaqueExpression

// Begin Class Operation
std::shared_ptr<ecore::EClass> UmlPackageImpl::getOperation_EClass() const
{
	return m_operation_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getOperation_EAttribute_isOrdered() const
{
	return m_operation_EAttribute_isOrdered;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getOperation_EAttribute_isQuery() const
{
	return m_operation_EAttribute_isQuery;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getOperation_EAttribute_isUnique() const
{
	return m_operation_EAttribute_isUnique;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getOperation_EAttribute_lower() const
{
	return m_operation_EAttribute_lower;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getOperation_EAttribute_upper() const
{
	return m_operation_EAttribute_upper;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getOperation_EReference_bodyCondition() const
{
	return m_operation_EReference_bodyCondition;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getOperation_EReference_class() const
{
	return m_operation_EReference_class;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getOperation_EReference_datatype() const
{
	return m_operation_EReference_datatype;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getOperation_EReference_interface() const
{
	return m_operation_EReference_interface;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getOperation_EReference_postcondition() const
{
	return m_operation_EReference_postcondition;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getOperation_EReference_precondition() const
{
	return m_operation_EReference_precondition;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getOperation_EReference_redefinedOperation() const
{
	return m_operation_EReference_redefinedOperation;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getOperation_EReference_type() const
{
	return m_operation_EReference_type;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation_EOperation_at_most_one_return_EDiagnosticChain_EMap() const
{
	return m_operation_EOperation_at_most_one_return_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation_EOperation_getLower() const
{
	return m_operation_EOperation_getLower;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation_EOperation_getReturnResult() const
{
	return m_operation_EOperation_getReturnResult;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation_EOperation_getType() const
{
	return m_operation_EOperation_getType;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation_EOperation_getUpper() const
{
	return m_operation_EOperation_getUpper;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation_EOperation_isOrdered() const
{
	return m_operation_EOperation_isOrdered;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation_EOperation_isUnique() const
{
	return m_operation_EOperation_isUnique;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation_EOperation_only_body_for_query_EDiagnosticChain_EMap() const
{
	return m_operation_EOperation_only_body_for_query_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation_EOperation_returnResult() const
{
	return m_operation_EOperation_returnResult;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation_EOperation_setIsOrdered_Boolean() const
{
	return m_operation_EOperation_setIsOrdered_Boolean;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation_EOperation_setIsUnique_Boolean() const
{
	return m_operation_EOperation_setIsUnique_Boolean;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation_EOperation_setLower_Integer() const
{
	return m_operation_EOperation_setLower_Integer;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation_EOperation_setType_Type() const
{
	return m_operation_EOperation_setType_Type;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation_EOperation_setUpper_UnlimitedNatural() const
{
	return m_operation_EOperation_setUpper_UnlimitedNatural;
}

// End Class Operation

// Begin Class OperationTemplateParameter
std::shared_ptr<ecore::EClass> UmlPackageImpl::getOperationTemplateParameter_EClass() const
{
	return m_operationTemplateParameter_EClass;
}



std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperationTemplateParameter_EOperation_match_default_signature_EDiagnosticChain_EMap() const
{
	return m_operationTemplateParameter_EOperation_match_default_signature_EDiagnosticChain_EMap;
}

// End Class OperationTemplateParameter

// Begin Class OutputPin
std::shared_ptr<ecore::EClass> UmlPackageImpl::getOutputPin_EClass() const
{
	return m_outputPin_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getOutputPin_EReference_action() const
{
	return m_outputPin_EReference_action;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getOutputPin_EReference_callAction() const
{
	return m_outputPin_EReference_callAction;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOutputPin_EOperation_incoming_edges_structured_only_EDiagnosticChain_EMap() const
{
	return m_outputPin_EOperation_incoming_edges_structured_only_EDiagnosticChain_EMap;
}

// End Class OutputPin

// Begin Class Package
std::shared_ptr<ecore::EClass> UmlPackageImpl::getPackage_EClass() const
{
	return m_package_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getPackage_EAttribute_uRI() const
{
	return m_package_EAttribute_uRI;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getPackage_EReference_nestedPackage() const
{
	return m_package_EReference_nestedPackage;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getPackage_EReference_nestingPackage() const
{
	return m_package_EReference_nestingPackage;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getPackage_EReference_ownedStereotype() const
{
	return m_package_EReference_ownedStereotype;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getPackage_EReference_ownedType() const
{
	return m_package_EReference_ownedType;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getPackage_EReference_packageMerge() const
{
	return m_package_EReference_packageMerge;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getPackage_EReference_packagedElement() const
{
	return m_package_EReference_packagedElement;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getPackage_EReference_profileApplication() const
{
	return m_package_EReference_profileApplication;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_EOperation_allApplicableStereotypes() const
{
	return m_package_EOperation_allApplicableStereotypes;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_EOperation_applyProfile_Profile() const
{
	return m_package_EOperation_applyProfile_Profile;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_EOperation_containingProfile() const
{
	return m_package_EOperation_containingProfile;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_EOperation_createOwnedClass_String_Boolean() const
{
	return m_package_EOperation_createOwnedClass_String_Boolean;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_EOperation_createOwnedEnumeration_String() const
{
	return m_package_EOperation_createOwnedEnumeration_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_EOperation_createOwnedInterface_String() const
{
	return m_package_EOperation_createOwnedInterface_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_EOperation_createOwnedPrimitiveType_String() const
{
	return m_package_EOperation_createOwnedPrimitiveType_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_EOperation_createOwnedStereotype_String_Boolean() const
{
	return m_package_EOperation_createOwnedStereotype_String_Boolean;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_EOperation_elements_public_or_private_EDiagnosticChain_EMap() const
{
	return m_package_EOperation_elements_public_or_private_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_EOperation_getAllAppliedProfiles() const
{
	return m_package_EOperation_getAllAppliedProfiles;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_EOperation_getAllProfileApplications() const
{
	return m_package_EOperation_getAllProfileApplications;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_EOperation_getAppliedProfile_String() const
{
	return m_package_EOperation_getAppliedProfile_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_EOperation_getAppliedProfile_String_Boolean() const
{
	return m_package_EOperation_getAppliedProfile_String_Boolean;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_EOperation_getAppliedProfiles() const
{
	return m_package_EOperation_getAppliedProfiles;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_EOperation_getNestedPackages() const
{
	return m_package_EOperation_getNestedPackages;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_EOperation_getOwnedStereotypes() const
{
	return m_package_EOperation_getOwnedStereotypes;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_EOperation_getOwnedTypes() const
{
	return m_package_EOperation_getOwnedTypes;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_EOperation_getProfileApplication_Profile() const
{
	return m_package_EOperation_getProfileApplication_Profile;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_EOperation_getProfileApplication_Profile_Boolean() const
{
	return m_package_EOperation_getProfileApplication_Profile_Boolean;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_EOperation_isModelLibrary() const
{
	return m_package_EOperation_isModelLibrary;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_EOperation_isProfileApplied_Profile() const
{
	return m_package_EOperation_isProfileApplied_Profile;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_EOperation_makesVisible_NamedElement() const
{
	return m_package_EOperation_makesVisible_NamedElement;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_EOperation_unapplyProfile_Profile() const
{
	return m_package_EOperation_unapplyProfile_Profile;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_EOperation_visibleMembers() const
{
	return m_package_EOperation_visibleMembers;
}

// End Class Package

// Begin Class PackageImport
std::shared_ptr<ecore::EClass> UmlPackageImpl::getPackageImport_EClass() const
{
	return m_packageImport_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getPackageImport_EAttribute_visibility() const
{
	return m_packageImport_EAttribute_visibility;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getPackageImport_EReference_importedPackage() const
{
	return m_packageImport_EReference_importedPackage;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getPackageImport_EReference_importingNamespace() const
{
	return m_packageImport_EReference_importingNamespace;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackageImport_EOperation_public_or_private_EDiagnosticChain_EMap() const
{
	return m_packageImport_EOperation_public_or_private_EDiagnosticChain_EMap;
}

// End Class PackageImport

// Begin Class PackageMerge
std::shared_ptr<ecore::EClass> UmlPackageImpl::getPackageMerge_EClass() const
{
	return m_packageMerge_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getPackageMerge_EReference_mergedPackage() const
{
	return m_packageMerge_EReference_mergedPackage;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getPackageMerge_EReference_receivingPackage() const
{
	return m_packageMerge_EReference_receivingPackage;
}


// End Class PackageMerge

// Begin Class PackageableElement
std::shared_ptr<ecore::EClass> UmlPackageImpl::getPackageableElement_EClass() const
{
	return m_packageableElement_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getPackageableElement_EReference_owningPackage() const
{
	return m_packageableElement_EReference_owningPackage;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackageableElement_EOperation_namespace_needs_visibility_EDiagnosticChain_EMap() const
{
	return m_packageableElement_EOperation_namespace_needs_visibility_EDiagnosticChain_EMap;
}

// End Class PackageableElement

// Begin Class Parameter
std::shared_ptr<ecore::EClass> UmlPackageImpl::getParameter_EClass() const
{
	return m_parameter_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getParameter_EAttribute_default() const
{
	return m_parameter_EAttribute_default;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getParameter_EAttribute_direction() const
{
	return m_parameter_EAttribute_direction;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getParameter_EAttribute_effect() const
{
	return m_parameter_EAttribute_effect;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getParameter_EAttribute_isException() const
{
	return m_parameter_EAttribute_isException;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getParameter_EAttribute_isStream() const
{
	return m_parameter_EAttribute_isStream;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getParameter_EReference_behavior() const
{
	return m_parameter_EReference_behavior;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getParameter_EReference_defaultValue() const
{
	return m_parameter_EReference_defaultValue;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getParameter_EReference_operation() const
{
	return m_parameter_EReference_operation;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getParameter_EReference_parameterSet() const
{
	return m_parameter_EReference_parameterSet;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter_EOperation_connector_end_EDiagnosticChain_EMap() const
{
	return m_parameter_EOperation_connector_end_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter_EOperation_in_and_out_EDiagnosticChain_EMap() const
{
	return m_parameter_EOperation_in_and_out_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter_EOperation_isSetDefault() const
{
	return m_parameter_EOperation_isSetDefault;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter_EOperation_not_exception_EDiagnosticChain_EMap() const
{
	return m_parameter_EOperation_not_exception_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter_EOperation_object_effect_EDiagnosticChain_EMap() const
{
	return m_parameter_EOperation_object_effect_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter_EOperation_reentrant_behaviors_EDiagnosticChain_EMap() const
{
	return m_parameter_EOperation_reentrant_behaviors_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter_EOperation_setBooleanDefaultValue_Boolean() const
{
	return m_parameter_EOperation_setBooleanDefaultValue_Boolean;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter_EOperation_setIntegerDefaultValue_Integer() const
{
	return m_parameter_EOperation_setIntegerDefaultValue_Integer;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter_EOperation_setNullDefaultValue() const
{
	return m_parameter_EOperation_setNullDefaultValue;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter_EOperation_setRealDefaultValue_Real() const
{
	return m_parameter_EOperation_setRealDefaultValue_Real;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter_EOperation_setStringDefaultValue_String() const
{
	return m_parameter_EOperation_setStringDefaultValue_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter_EOperation_setUnlimitedNaturalDefaultValue_UnlimitedNatural() const
{
	return m_parameter_EOperation_setUnlimitedNaturalDefaultValue_UnlimitedNatural;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter_EOperation_stream_and_exception_EDiagnosticChain_EMap() const
{
	return m_parameter_EOperation_stream_and_exception_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter_EOperation_unsetDefault() const
{
	return m_parameter_EOperation_unsetDefault;
}

// End Class Parameter

// Begin Class ParameterSet
std::shared_ptr<ecore::EClass> UmlPackageImpl::getParameterSet_EClass() const
{
	return m_parameterSet_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getParameterSet_EReference_condition() const
{
	return m_parameterSet_EReference_condition;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getParameterSet_EReference_parameter() const
{
	return m_parameterSet_EReference_parameter;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameterSet_EOperation_input_EDiagnosticChain_EMap() const
{
	return m_parameterSet_EOperation_input_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameterSet_EOperation_same_parameterized_entity_EDiagnosticChain_EMap() const
{
	return m_parameterSet_EOperation_same_parameterized_entity_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameterSet_EOperation_two_parameter_sets_EDiagnosticChain_EMap() const
{
	return m_parameterSet_EOperation_two_parameter_sets_EDiagnosticChain_EMap;
}

// End Class ParameterSet

// Begin Class ParameterableElement
std::shared_ptr<ecore::EClass> UmlPackageImpl::getParameterableElement_EClass() const
{
	return m_parameterableElement_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getParameterableElement_EReference_owningTemplateParameter() const
{
	return m_parameterableElement_EReference_owningTemplateParameter;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getParameterableElement_EReference_templateParameter() const
{
	return m_parameterableElement_EReference_templateParameter;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameterableElement_EOperation_isCompatibleWith_ParameterableElement() const
{
	return m_parameterableElement_EOperation_isCompatibleWith_ParameterableElement;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameterableElement_EOperation_isTemplateParameter() const
{
	return m_parameterableElement_EOperation_isTemplateParameter;
}

// End Class ParameterableElement

// Begin Class PartDecomposition
std::shared_ptr<ecore::EClass> UmlPackageImpl::getPartDecomposition_EClass() const
{
	return m_partDecomposition_EClass;
}



std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPartDecomposition_EOperation_assume_EDiagnosticChain_EMap() const
{
	return m_partDecomposition_EOperation_assume_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPartDecomposition_EOperation_commutativity_of_decomposition_EDiagnosticChain_EMap() const
{
	return m_partDecomposition_EOperation_commutativity_of_decomposition_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPartDecomposition_EOperation_parts_of_internal_structures_EDiagnosticChain_EMap() const
{
	return m_partDecomposition_EOperation_parts_of_internal_structures_EDiagnosticChain_EMap;
}

// End Class PartDecomposition

// Begin Class Pin
std::shared_ptr<ecore::EClass> UmlPackageImpl::getPin_EClass() const
{
	return m_pin_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getPin_EAttribute_isControl() const
{
	return m_pin_EAttribute_isControl;
}


std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPin_EOperation_control_pins_EDiagnosticChain_EMap() const
{
	return m_pin_EOperation_control_pins_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPin_EOperation_not_unique_EDiagnosticChain_EMap() const
{
	return m_pin_EOperation_not_unique_EDiagnosticChain_EMap;
}

// End Class Pin

// Begin Class Port
std::shared_ptr<ecore::EClass> UmlPackageImpl::getPort_EClass() const
{
	return m_port_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getPort_EAttribute_isBehavior() const
{
	return m_port_EAttribute_isBehavior;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getPort_EAttribute_isConjugated() const
{
	return m_port_EAttribute_isConjugated;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getPort_EAttribute_isService() const
{
	return m_port_EAttribute_isService;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getPort_EReference_protocol() const
{
	return m_port_EReference_protocol;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getPort_EReference_provided() const
{
	return m_port_EReference_provided;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getPort_EReference_redefinedPort() const
{
	return m_port_EReference_redefinedPort;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getPort_EReference_required() const
{
	return m_port_EReference_required;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPort_EOperation_basicProvided() const
{
	return m_port_EOperation_basicProvided;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPort_EOperation_basicRequired() const
{
	return m_port_EOperation_basicRequired;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPort_EOperation_default_value_EDiagnosticChain_EMap() const
{
	return m_port_EOperation_default_value_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPort_EOperation_encapsulated_owner_EDiagnosticChain_EMap() const
{
	return m_port_EOperation_encapsulated_owner_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPort_EOperation_getProvideds() const
{
	return m_port_EOperation_getProvideds;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPort_EOperation_getRequireds() const
{
	return m_port_EOperation_getRequireds;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPort_EOperation_port_aggregation_EDiagnosticChain_EMap() const
{
	return m_port_EOperation_port_aggregation_EDiagnosticChain_EMap;
}

// End Class Port

// Begin Class PrimitiveType
std::shared_ptr<ecore::EClass> UmlPackageImpl::getPrimitiveType_EClass() const
{
	return m_primitiveType_EClass;
}




// End Class PrimitiveType

// Begin Class Profile
std::shared_ptr<ecore::EClass> UmlPackageImpl::getProfile_EClass() const
{
	return m_profile_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getProfile_EReference_metaclassReference() const
{
	return m_profile_EReference_metaclassReference;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProfile_EReference_metamodelReference() const
{
	return m_profile_EReference_metamodelReference;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProfile_EOperation_create_Classifier() const
{
	return m_profile_EOperation_create_Classifier;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProfile_EOperation_define() const
{
	return m_profile_EOperation_define;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProfile_EOperation_define_EMap_EMap() const
{
	return m_profile_EOperation_define_EMap_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProfile_EOperation_getDefinition() const
{
	return m_profile_EOperation_getDefinition;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProfile_EOperation_getDefinition_NamedElement() const
{
	return m_profile_EOperation_getDefinition_NamedElement;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProfile_EOperation_getOwnedExtensions_Boolean() const
{
	return m_profile_EOperation_getOwnedExtensions_Boolean;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProfile_EOperation_getReferencedMetaclasses() const
{
	return m_profile_EOperation_getReferencedMetaclasses;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProfile_EOperation_getReferencedMetamodels() const
{
	return m_profile_EOperation_getReferencedMetamodels;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProfile_EOperation_isDefined() const
{
	return m_profile_EOperation_isDefined;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProfile_EOperation_metaclass_reference_not_specialized_EDiagnosticChain_EMap() const
{
	return m_profile_EOperation_metaclass_reference_not_specialized_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProfile_EOperation_references_same_metamodel_EDiagnosticChain_EMap() const
{
	return m_profile_EOperation_references_same_metamodel_EDiagnosticChain_EMap;
}

// End Class Profile

// Begin Class ProfileApplication
std::shared_ptr<ecore::EClass> UmlPackageImpl::getProfileApplication_EClass() const
{
	return m_profileApplication_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getProfileApplication_EAttribute_isStrict() const
{
	return m_profileApplication_EAttribute_isStrict;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getProfileApplication_EReference_appliedProfile() const
{
	return m_profileApplication_EReference_appliedProfile;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProfileApplication_EReference_applyingPackage() const
{
	return m_profileApplication_EReference_applyingPackage;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProfileApplication_EOperation_getAppliedDefinition() const
{
	return m_profileApplication_EOperation_getAppliedDefinition;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProfileApplication_EOperation_getAppliedDefinition_NamedElement() const
{
	return m_profileApplication_EOperation_getAppliedDefinition_NamedElement;
}

// End Class ProfileApplication

// Begin Class Property
std::shared_ptr<ecore::EClass> UmlPackageImpl::getProperty_EClass() const
{
	return m_property_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getProperty_EAttribute_aggregation() const
{
	return m_property_EAttribute_aggregation;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getProperty_EAttribute_default() const
{
	return m_property_EAttribute_default;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getProperty_EAttribute_isComposite() const
{
	return m_property_EAttribute_isComposite;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getProperty_EAttribute_isDerived() const
{
	return m_property_EAttribute_isDerived;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getProperty_EAttribute_isDerivedUnion() const
{
	return m_property_EAttribute_isDerivedUnion;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getProperty_EAttribute_isID() const
{
	return m_property_EAttribute_isID;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getProperty_EReference_association() const
{
	return m_property_EReference_association;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProperty_EReference_associationEnd() const
{
	return m_property_EReference_associationEnd;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProperty_EReference_class() const
{
	return m_property_EReference_class;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProperty_EReference_datatype() const
{
	return m_property_EReference_datatype;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProperty_EReference_defaultValue() const
{
	return m_property_EReference_defaultValue;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProperty_EReference_interface() const
{
	return m_property_EReference_interface;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProperty_EReference_opposite() const
{
	return m_property_EReference_opposite;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProperty_EReference_owningAssociation() const
{
	return m_property_EReference_owningAssociation;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProperty_EReference_qualifier() const
{
	return m_property_EReference_qualifier;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProperty_EReference_redefinedProperty() const
{
	return m_property_EReference_redefinedProperty;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProperty_EReference_subsettedProperty() const
{
	return m_property_EReference_subsettedProperty;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_EOperation_binding_to_attribute_EDiagnosticChain_EMap() const
{
	return m_property_EOperation_binding_to_attribute_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_EOperation_deployment_target_EDiagnosticChain_EMap() const
{
	return m_property_EOperation_deployment_target_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_EOperation_derived_union_is_derived_EDiagnosticChain_EMap() const
{
	return m_property_EOperation_derived_union_is_derived_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_EOperation_derived_union_is_read_only_EDiagnosticChain_EMap() const
{
	return m_property_EOperation_derived_union_is_read_only_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_EOperation_getOpposite() const
{
	return m_property_EOperation_getOpposite;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_EOperation_getOtherEnd() const
{
	return m_property_EOperation_getOtherEnd;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_EOperation_isAttribute() const
{
	return m_property_EOperation_isAttribute;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_EOperation_isComposite() const
{
	return m_property_EOperation_isComposite;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_EOperation_isNavigable() const
{
	return m_property_EOperation_isNavigable;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_EOperation_isSetDefault() const
{
	return m_property_EOperation_isSetDefault;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_EOperation_multiplicity_of_composite_EDiagnosticChain_EMap() const
{
	return m_property_EOperation_multiplicity_of_composite_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_EOperation_qualified_is_association_end_EDiagnosticChain_EMap() const
{
	return m_property_EOperation_qualified_is_association_end_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_EOperation_redefined_property_inherited_EDiagnosticChain_EMap() const
{
	return m_property_EOperation_redefined_property_inherited_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_EOperation_setBooleanDefaultValue_Boolean() const
{
	return m_property_EOperation_setBooleanDefaultValue_Boolean;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_EOperation_setIntegerDefaultValue_Integer() const
{
	return m_property_EOperation_setIntegerDefaultValue_Integer;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_EOperation_setIsNavigable_Boolean() const
{
	return m_property_EOperation_setIsNavigable_Boolean;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_EOperation_setNullDefaultValue() const
{
	return m_property_EOperation_setNullDefaultValue;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_EOperation_setRealDefaultValue_Real() const
{
	return m_property_EOperation_setRealDefaultValue_Real;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_EOperation_setStringDefaultValue_String() const
{
	return m_property_EOperation_setStringDefaultValue_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_EOperation_setUnlimitedNaturalDefaultValue_UnlimitedNatural() const
{
	return m_property_EOperation_setUnlimitedNaturalDefaultValue_UnlimitedNatural;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_EOperation_subsetted_property_names_EDiagnosticChain_EMap() const
{
	return m_property_EOperation_subsetted_property_names_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_EOperation_subsettingContext() const
{
	return m_property_EOperation_subsettingContext;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_EOperation_subsetting_context_conforms_EDiagnosticChain_EMap() const
{
	return m_property_EOperation_subsetting_context_conforms_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_EOperation_subsetting_rules_EDiagnosticChain_EMap() const
{
	return m_property_EOperation_subsetting_rules_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_EOperation_type_of_opposite_end_EDiagnosticChain_EMap() const
{
	return m_property_EOperation_type_of_opposite_end_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_EOperation_unsetDefault() const
{
	return m_property_EOperation_unsetDefault;
}

// End Class Property

// Begin Class ProtocolConformance
std::shared_ptr<ecore::EClass> UmlPackageImpl::getProtocolConformance_EClass() const
{
	return m_protocolConformance_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getProtocolConformance_EReference_generalMachine() const
{
	return m_protocolConformance_EReference_generalMachine;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProtocolConformance_EReference_specificMachine() const
{
	return m_protocolConformance_EReference_specificMachine;
}


// End Class ProtocolConformance

// Begin Class ProtocolStateMachine
std::shared_ptr<ecore::EClass> UmlPackageImpl::getProtocolStateMachine_EClass() const
{
	return m_protocolStateMachine_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getProtocolStateMachine_EReference_conformance() const
{
	return m_protocolStateMachine_EReference_conformance;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProtocolStateMachine_EOperation_deep_or_shallow_history_EDiagnosticChain_EMap() const
{
	return m_protocolStateMachine_EOperation_deep_or_shallow_history_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProtocolStateMachine_EOperation_entry_exit_do_EDiagnosticChain_EMap() const
{
	return m_protocolStateMachine_EOperation_entry_exit_do_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProtocolStateMachine_EOperation_protocol_transitions_EDiagnosticChain_EMap() const
{
	return m_protocolStateMachine_EOperation_protocol_transitions_EDiagnosticChain_EMap;
}

// End Class ProtocolStateMachine

// Begin Class ProtocolTransition
std::shared_ptr<ecore::EClass> UmlPackageImpl::getProtocolTransition_EClass() const
{
	return m_protocolTransition_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getProtocolTransition_EReference_postCondition() const
{
	return m_protocolTransition_EReference_postCondition;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProtocolTransition_EReference_preCondition() const
{
	return m_protocolTransition_EReference_preCondition;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProtocolTransition_EReference_referred() const
{
	return m_protocolTransition_EReference_referred;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProtocolTransition_EOperation_associated_actions_EDiagnosticChain_EMap() const
{
	return m_protocolTransition_EOperation_associated_actions_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProtocolTransition_EOperation_belongs_to_psm_EDiagnosticChain_EMap() const
{
	return m_protocolTransition_EOperation_belongs_to_psm_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProtocolTransition_EOperation_getReferreds() const
{
	return m_protocolTransition_EOperation_getReferreds;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProtocolTransition_EOperation_refers_to_operation_EDiagnosticChain_EMap() const
{
	return m_protocolTransition_EOperation_refers_to_operation_EDiagnosticChain_EMap;
}

// End Class ProtocolTransition

// Begin Class Pseudostate
std::shared_ptr<ecore::EClass> UmlPackageImpl::getPseudostate_EClass() const
{
	return m_pseudostate_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getPseudostate_EAttribute_kind() const
{
	return m_pseudostate_EAttribute_kind;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getPseudostate_EReference_state() const
{
	return m_pseudostate_EReference_state;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getPseudostate_EReference_stateMachine() const
{
	return m_pseudostate_EReference_stateMachine;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPseudostate_EOperation_choice_vertex_EDiagnosticChain_EMap() const
{
	return m_pseudostate_EOperation_choice_vertex_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPseudostate_EOperation_fork_vertex_EDiagnosticChain_EMap() const
{
	return m_pseudostate_EOperation_fork_vertex_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPseudostate_EOperation_history_vertices_EDiagnosticChain_EMap() const
{
	return m_pseudostate_EOperation_history_vertices_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPseudostate_EOperation_initial_vertex_EDiagnosticChain_EMap() const
{
	return m_pseudostate_EOperation_initial_vertex_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPseudostate_EOperation_join_vertex_EDiagnosticChain_EMap() const
{
	return m_pseudostate_EOperation_join_vertex_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPseudostate_EOperation_junction_vertex_EDiagnosticChain_EMap() const
{
	return m_pseudostate_EOperation_junction_vertex_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPseudostate_EOperation_outgoing_from_initial_EDiagnosticChain_EMap() const
{
	return m_pseudostate_EOperation_outgoing_from_initial_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPseudostate_EOperation_transitions_incoming_EDiagnosticChain_EMap() const
{
	return m_pseudostate_EOperation_transitions_incoming_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPseudostate_EOperation_transitions_outgoing_EDiagnosticChain_EMap() const
{
	return m_pseudostate_EOperation_transitions_outgoing_EDiagnosticChain_EMap;
}

// End Class Pseudostate

// Begin Class QualifierValue
std::shared_ptr<ecore::EClass> UmlPackageImpl::getQualifierValue_EClass() const
{
	return m_qualifierValue_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getQualifierValue_EReference_qualifier() const
{
	return m_qualifierValue_EReference_qualifier;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getQualifierValue_EReference_value() const
{
	return m_qualifierValue_EReference_value;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getQualifierValue_EOperation_multiplicity_of_qualifier_EDiagnosticChain_EMap() const
{
	return m_qualifierValue_EOperation_multiplicity_of_qualifier_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getQualifierValue_EOperation_qualifier_attribute_EDiagnosticChain_EMap() const
{
	return m_qualifierValue_EOperation_qualifier_attribute_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getQualifierValue_EOperation_type_of_qualifier_EDiagnosticChain_EMap() const
{
	return m_qualifierValue_EOperation_type_of_qualifier_EDiagnosticChain_EMap;
}

// End Class QualifierValue

// Begin Class RaiseExceptionAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getRaiseExceptionAction_EClass() const
{
	return m_raiseExceptionAction_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getRaiseExceptionAction_EReference_exception() const
{
	return m_raiseExceptionAction_EReference_exception;
}


// End Class RaiseExceptionAction

// Begin Class ReadExtentAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getReadExtentAction_EClass() const
{
	return m_readExtentAction_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadExtentAction_EReference_classifier() const
{
	return m_readExtentAction_EReference_classifier;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadExtentAction_EReference_result() const
{
	return m_readExtentAction_EReference_result;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadExtentAction_EOperation_multiplicity_of_result_EDiagnosticChain_EMap() const
{
	return m_readExtentAction_EOperation_multiplicity_of_result_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadExtentAction_EOperation_type_is_classifier_EDiagnosticChain_EMap() const
{
	return m_readExtentAction_EOperation_type_is_classifier_EDiagnosticChain_EMap;
}

// End Class ReadExtentAction

// Begin Class ReadIsClassifiedObjectAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getReadIsClassifiedObjectAction_EClass() const
{
	return m_readIsClassifiedObjectAction_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getReadIsClassifiedObjectAction_EAttribute_isDirect() const
{
	return m_readIsClassifiedObjectAction_EAttribute_isDirect;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadIsClassifiedObjectAction_EReference_classifier() const
{
	return m_readIsClassifiedObjectAction_EReference_classifier;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadIsClassifiedObjectAction_EReference_object() const
{
	return m_readIsClassifiedObjectAction_EReference_object;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadIsClassifiedObjectAction_EReference_result() const
{
	return m_readIsClassifiedObjectAction_EReference_result;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadIsClassifiedObjectAction_EOperation_boolean_result_EDiagnosticChain_EMap() const
{
	return m_readIsClassifiedObjectAction_EOperation_boolean_result_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadIsClassifiedObjectAction_EOperation_multiplicity_of_input_EDiagnosticChain_EMap() const
{
	return m_readIsClassifiedObjectAction_EOperation_multiplicity_of_input_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadIsClassifiedObjectAction_EOperation_multiplicity_of_output_EDiagnosticChain_EMap() const
{
	return m_readIsClassifiedObjectAction_EOperation_multiplicity_of_output_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadIsClassifiedObjectAction_EOperation_no_type_EDiagnosticChain_EMap() const
{
	return m_readIsClassifiedObjectAction_EOperation_no_type_EDiagnosticChain_EMap;
}

// End Class ReadIsClassifiedObjectAction

// Begin Class ReadLinkAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getReadLinkAction_EClass() const
{
	return m_readLinkAction_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadLinkAction_EReference_result() const
{
	return m_readLinkAction_EReference_result;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkAction_EOperation_compatible_multiplicity_EDiagnosticChain_EMap() const
{
	return m_readLinkAction_EOperation_compatible_multiplicity_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkAction_EOperation_navigable_open_end_EDiagnosticChain_EMap() const
{
	return m_readLinkAction_EOperation_navigable_open_end_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkAction_EOperation_one_open_end_EDiagnosticChain_EMap() const
{
	return m_readLinkAction_EOperation_one_open_end_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkAction_EOperation_openEnd() const
{
	return m_readLinkAction_EOperation_openEnd;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkAction_EOperation_type_and_ordering_EDiagnosticChain_EMap() const
{
	return m_readLinkAction_EOperation_type_and_ordering_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkAction_EOperation_visibility_EDiagnosticChain_EMap() const
{
	return m_readLinkAction_EOperation_visibility_EDiagnosticChain_EMap;
}

// End Class ReadLinkAction

// Begin Class ReadLinkObjectEndAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getReadLinkObjectEndAction_EClass() const
{
	return m_readLinkObjectEndAction_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadLinkObjectEndAction_EReference_end() const
{
	return m_readLinkObjectEndAction_EReference_end;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadLinkObjectEndAction_EReference_object() const
{
	return m_readLinkObjectEndAction_EReference_object;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadLinkObjectEndAction_EReference_result() const
{
	return m_readLinkObjectEndAction_EReference_result;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndAction_EOperation_association_of_association_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndAction_EOperation_association_of_association_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndAction_EOperation_ends_of_association_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndAction_EOperation_ends_of_association_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndAction_EOperation_multiplicity_of_object_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndAction_EOperation_multiplicity_of_object_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndAction_EOperation_multiplicity_of_result_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndAction_EOperation_multiplicity_of_result_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndAction_EOperation_property_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndAction_EOperation_property_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndAction_EOperation_type_of_object_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndAction_EOperation_type_of_object_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndAction_EOperation_type_of_result_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndAction_EOperation_type_of_result_EDiagnosticChain_EMap;
}

// End Class ReadLinkObjectEndAction

// Begin Class ReadLinkObjectEndQualifierAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getReadLinkObjectEndQualifierAction_EClass() const
{
	return m_readLinkObjectEndQualifierAction_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadLinkObjectEndQualifierAction_EReference_object() const
{
	return m_readLinkObjectEndQualifierAction_EReference_object;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadLinkObjectEndQualifierAction_EReference_qualifier() const
{
	return m_readLinkObjectEndQualifierAction_EReference_qualifier;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadLinkObjectEndQualifierAction_EReference_result() const
{
	return m_readLinkObjectEndQualifierAction_EReference_result;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndQualifierAction_EOperation_association_of_association_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndQualifierAction_EOperation_association_of_association_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndQualifierAction_EOperation_ends_of_association_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndQualifierAction_EOperation_ends_of_association_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndQualifierAction_EOperation_multiplicity_of_object_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndQualifierAction_EOperation_multiplicity_of_object_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndQualifierAction_EOperation_multiplicity_of_qualifier_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndQualifierAction_EOperation_multiplicity_of_qualifier_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndQualifierAction_EOperation_multiplicity_of_result_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndQualifierAction_EOperation_multiplicity_of_result_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndQualifierAction_EOperation_qualifier_attribute_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndQualifierAction_EOperation_qualifier_attribute_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndQualifierAction_EOperation_same_type_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndQualifierAction_EOperation_same_type_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndQualifierAction_EOperation_type_of_object_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndQualifierAction_EOperation_type_of_object_EDiagnosticChain_EMap;
}

// End Class ReadLinkObjectEndQualifierAction

// Begin Class ReadSelfAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getReadSelfAction_EClass() const
{
	return m_readSelfAction_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadSelfAction_EReference_result() const
{
	return m_readSelfAction_EReference_result;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadSelfAction_EOperation_contained_EDiagnosticChain_EMap() const
{
	return m_readSelfAction_EOperation_contained_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadSelfAction_EOperation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_readSelfAction_EOperation_multiplicity_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadSelfAction_EOperation_not_static_EDiagnosticChain_EMap() const
{
	return m_readSelfAction_EOperation_not_static_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadSelfAction_EOperation_type_EDiagnosticChain_EMap() const
{
	return m_readSelfAction_EOperation_type_EDiagnosticChain_EMap;
}

// End Class ReadSelfAction

// Begin Class ReadStructuralFeatureAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getReadStructuralFeatureAction_EClass() const
{
	return m_readStructuralFeatureAction_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadStructuralFeatureAction_EReference_result() const
{
	return m_readStructuralFeatureAction_EReference_result;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadStructuralFeatureAction_EOperation_type_and_ordering_EDiagnosticChain_EMap() const
{
	return m_readStructuralFeatureAction_EOperation_type_and_ordering_EDiagnosticChain_EMap;
}

// End Class ReadStructuralFeatureAction

// Begin Class ReadVariableAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getReadVariableAction_EClass() const
{
	return m_readVariableAction_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadVariableAction_EReference_result() const
{
	return m_readVariableAction_EReference_result;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadVariableAction_EOperation_compatible_multiplicity_EDiagnosticChain_EMap() const
{
	return m_readVariableAction_EOperation_compatible_multiplicity_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadVariableAction_EOperation_type_and_ordering_EDiagnosticChain_EMap() const
{
	return m_readVariableAction_EOperation_type_and_ordering_EDiagnosticChain_EMap;
}

// End Class ReadVariableAction

// Begin Class Realization
std::shared_ptr<ecore::EClass> UmlPackageImpl::getRealization_EClass() const
{
	return m_realization_EClass;
}




// End Class Realization

// Begin Class Reception
std::shared_ptr<ecore::EClass> UmlPackageImpl::getReception_EClass() const
{
	return m_reception_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getReception_EReference_signal() const
{
	return m_reception_EReference_signal;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReception_EOperation_same_name_as_signal_EDiagnosticChain_EMap() const
{
	return m_reception_EOperation_same_name_as_signal_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReception_EOperation_same_structure_as_signal_EDiagnosticChain_EMap() const
{
	return m_reception_EOperation_same_structure_as_signal_EDiagnosticChain_EMap;
}

// End Class Reception

// Begin Class ReclassifyObjectAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getReclassifyObjectAction_EClass() const
{
	return m_reclassifyObjectAction_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getReclassifyObjectAction_EAttribute_isReplaceAll() const
{
	return m_reclassifyObjectAction_EAttribute_isReplaceAll;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getReclassifyObjectAction_EReference_newClassifier() const
{
	return m_reclassifyObjectAction_EReference_newClassifier;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getReclassifyObjectAction_EReference_object() const
{
	return m_reclassifyObjectAction_EReference_object;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getReclassifyObjectAction_EReference_oldClassifier() const
{
	return m_reclassifyObjectAction_EReference_oldClassifier;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReclassifyObjectAction_EOperation_classifier_not_abstract_EDiagnosticChain_EMap() const
{
	return m_reclassifyObjectAction_EOperation_classifier_not_abstract_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReclassifyObjectAction_EOperation_input_pin_EDiagnosticChain_EMap() const
{
	return m_reclassifyObjectAction_EOperation_input_pin_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReclassifyObjectAction_EOperation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_reclassifyObjectAction_EOperation_multiplicity_EDiagnosticChain_EMap;
}

// End Class ReclassifyObjectAction

// Begin Class RedefinableElement
std::shared_ptr<ecore::EClass> UmlPackageImpl::getRedefinableElement_EClass() const
{
	return m_redefinableElement_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getRedefinableElement_EAttribute_isLeaf() const
{
	return m_redefinableElement_EAttribute_isLeaf;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getRedefinableElement_EReference_redefinedElement() const
{
	return m_redefinableElement_EReference_redefinedElement;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getRedefinableElement_EReference_redefinitionContext() const
{
	return m_redefinableElement_EReference_redefinitionContext;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRedefinableElement_EOperation_isConsistentWith_RedefinableElement() const
{
	return m_redefinableElement_EOperation_isConsistentWith_RedefinableElement;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRedefinableElement_EOperation_isRedefinitionContextValid_RedefinableElement() const
{
	return m_redefinableElement_EOperation_isRedefinitionContextValid_RedefinableElement;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRedefinableElement_EOperation_non_leaf_redefinition_EDiagnosticChain_EMap() const
{
	return m_redefinableElement_EOperation_non_leaf_redefinition_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRedefinableElement_EOperation_redefinition_consistent_EDiagnosticChain_EMap() const
{
	return m_redefinableElement_EOperation_redefinition_consistent_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRedefinableElement_EOperation_redefinition_context_valid_EDiagnosticChain_EMap() const
{
	return m_redefinableElement_EOperation_redefinition_context_valid_EDiagnosticChain_EMap;
}

// End Class RedefinableElement

// Begin Class RedefinableTemplateSignature
std::shared_ptr<ecore::EClass> UmlPackageImpl::getRedefinableTemplateSignature_EClass() const
{
	return m_redefinableTemplateSignature_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getRedefinableTemplateSignature_EReference_classifier() const
{
	return m_redefinableTemplateSignature_EReference_classifier;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getRedefinableTemplateSignature_EReference_extendedSignature() const
{
	return m_redefinableTemplateSignature_EReference_extendedSignature;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getRedefinableTemplateSignature_EReference_inheritedParameter() const
{
	return m_redefinableTemplateSignature_EReference_inheritedParameter;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRedefinableTemplateSignature_EOperation_getInheritedParameters() const
{
	return m_redefinableTemplateSignature_EOperation_getInheritedParameters;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRedefinableTemplateSignature_EOperation_redefines_parents_EDiagnosticChain_EMap() const
{
	return m_redefinableTemplateSignature_EOperation_redefines_parents_EDiagnosticChain_EMap;
}

// End Class RedefinableTemplateSignature

// Begin Class ReduceAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getReduceAction_EClass() const
{
	return m_reduceAction_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getReduceAction_EAttribute_isOrdered() const
{
	return m_reduceAction_EAttribute_isOrdered;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getReduceAction_EReference_collection() const
{
	return m_reduceAction_EReference_collection;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getReduceAction_EReference_reducer() const
{
	return m_reduceAction_EReference_reducer;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getReduceAction_EReference_result() const
{
	return m_reduceAction_EReference_result;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReduceAction_EOperation_input_type_is_collection_EDiagnosticChain_EMap() const
{
	return m_reduceAction_EOperation_input_type_is_collection_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReduceAction_EOperation_output_types_are_compatible_EDiagnosticChain_EMap() const
{
	return m_reduceAction_EOperation_output_types_are_compatible_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReduceAction_EOperation_reducer_inputs_output_EDiagnosticChain_EMap() const
{
	return m_reduceAction_EOperation_reducer_inputs_output_EDiagnosticChain_EMap;
}

// End Class ReduceAction

// Begin Class Region
std::shared_ptr<ecore::EClass> UmlPackageImpl::getRegion_EClass() const
{
	return m_region_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getRegion_EReference_extendedRegion() const
{
	return m_region_EReference_extendedRegion;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getRegion_EReference_state() const
{
	return m_region_EReference_state;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getRegion_EReference_stateMachine() const
{
	return m_region_EReference_stateMachine;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getRegion_EReference_subvertex() const
{
	return m_region_EReference_subvertex;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getRegion_EReference_transition() const
{
	return m_region_EReference_transition;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRegion_EOperation_belongsToPSM() const
{
	return m_region_EOperation_belongsToPSM;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRegion_EOperation_containingStateMachine() const
{
	return m_region_EOperation_containingStateMachine;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRegion_EOperation_deep_history_vertex_EDiagnosticChain_EMap() const
{
	return m_region_EOperation_deep_history_vertex_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRegion_EOperation_initial_vertex_EDiagnosticChain_EMap() const
{
	return m_region_EOperation_initial_vertex_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRegion_EOperation_owned_EDiagnosticChain_EMap() const
{
	return m_region_EOperation_owned_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRegion_EOperation_redefinitionContext() const
{
	return m_region_EOperation_redefinitionContext;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRegion_EOperation_shallow_history_vertex_EDiagnosticChain_EMap() const
{
	return m_region_EOperation_shallow_history_vertex_EDiagnosticChain_EMap;
}

// End Class Region

// Begin Class Relationship
std::shared_ptr<ecore::EClass> UmlPackageImpl::getRelationship_EClass() const
{
	return m_relationship_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getRelationship_EReference_relatedElement() const
{
	return m_relationship_EReference_relatedElement;
}


// End Class Relationship

// Begin Class RemoveStructuralFeatureValueAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getRemoveStructuralFeatureValueAction_EClass() const
{
	return m_removeStructuralFeatureValueAction_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getRemoveStructuralFeatureValueAction_EAttribute_isRemoveDuplicates() const
{
	return m_removeStructuralFeatureValueAction_EAttribute_isRemoveDuplicates;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getRemoveStructuralFeatureValueAction_EReference_removeAt() const
{
	return m_removeStructuralFeatureValueAction_EReference_removeAt;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRemoveStructuralFeatureValueAction_EOperation_removeAt_and_value_EDiagnosticChain_EMap() const
{
	return m_removeStructuralFeatureValueAction_EOperation_removeAt_and_value_EDiagnosticChain_EMap;
}

// End Class RemoveStructuralFeatureValueAction

// Begin Class RemoveVariableValueAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getRemoveVariableValueAction_EClass() const
{
	return m_removeVariableValueAction_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getRemoveVariableValueAction_EAttribute_isRemoveDuplicates() const
{
	return m_removeVariableValueAction_EAttribute_isRemoveDuplicates;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getRemoveVariableValueAction_EReference_removeAt() const
{
	return m_removeVariableValueAction_EReference_removeAt;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRemoveVariableValueAction_EOperation_removeAt_and_value_EDiagnosticChain_EMap() const
{
	return m_removeVariableValueAction_EOperation_removeAt_and_value_EDiagnosticChain_EMap;
}

// End Class RemoveVariableValueAction

// Begin Class ReplyAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getReplyAction_EClass() const
{
	return m_replyAction_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getReplyAction_EReference_replyToCall() const
{
	return m_replyAction_EReference_replyToCall;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getReplyAction_EReference_replyValue() const
{
	return m_replyAction_EReference_replyValue;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getReplyAction_EReference_returnInformation() const
{
	return m_replyAction_EReference_returnInformation;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReplyAction_EOperation_event_on_reply_to_call_trigger_EDiagnosticChain_EMap() const
{
	return m_replyAction_EOperation_event_on_reply_to_call_trigger_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReplyAction_EOperation_pins_match_parameter_EDiagnosticChain_EMap() const
{
	return m_replyAction_EOperation_pins_match_parameter_EDiagnosticChain_EMap;
}

// End Class ReplyAction

// Begin Class SendObjectAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getSendObjectAction_EClass() const
{
	return m_sendObjectAction_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getSendObjectAction_EReference_request() const
{
	return m_sendObjectAction_EReference_request;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getSendObjectAction_EReference_target() const
{
	return m_sendObjectAction_EReference_target;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getSendObjectAction_EOperation_type_target_pin_EDiagnosticChain_EMap() const
{
	return m_sendObjectAction_EOperation_type_target_pin_EDiagnosticChain_EMap;
}

// End Class SendObjectAction

// Begin Class SendSignalAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getSendSignalAction_EClass() const
{
	return m_sendSignalAction_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getSendSignalAction_EReference_signal() const
{
	return m_sendSignalAction_EReference_signal;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getSendSignalAction_EReference_target() const
{
	return m_sendSignalAction_EReference_target;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getSendSignalAction_EOperation_number_order_EDiagnosticChain_EMap() const
{
	return m_sendSignalAction_EOperation_number_order_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getSendSignalAction_EOperation_type_ordering_multiplicity_EDiagnosticChain_EMap() const
{
	return m_sendSignalAction_EOperation_type_ordering_multiplicity_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getSendSignalAction_EOperation_type_target_pin_EDiagnosticChain_EMap() const
{
	return m_sendSignalAction_EOperation_type_target_pin_EDiagnosticChain_EMap;
}

// End Class SendSignalAction

// Begin Class SequenceNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getSequenceNode_EClass() const
{
	return m_sequenceNode_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getSequenceNode_EReference_executableNode() const
{
	return m_sequenceNode_EReference_executableNode;
}


// End Class SequenceNode

// Begin Class Signal
std::shared_ptr<ecore::EClass> UmlPackageImpl::getSignal_EClass() const
{
	return m_signal_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getSignal_EReference_ownedAttribute() const
{
	return m_signal_EReference_ownedAttribute;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getSignal_EOperation_createOwnedAttribute_String_UnlimitedNatural() const
{
	return m_signal_EOperation_createOwnedAttribute_String_UnlimitedNatural;
}

// End Class Signal

// Begin Class SignalEvent
std::shared_ptr<ecore::EClass> UmlPackageImpl::getSignalEvent_EClass() const
{
	return m_signalEvent_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getSignalEvent_EReference_signal() const
{
	return m_signalEvent_EReference_signal;
}


// End Class SignalEvent

// Begin Class Slot
std::shared_ptr<ecore::EClass> UmlPackageImpl::getSlot_EClass() const
{
	return m_slot_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getSlot_EReference_definingFeature() const
{
	return m_slot_EReference_definingFeature;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getSlot_EReference_owningInstance() const
{
	return m_slot_EReference_owningInstance;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getSlot_EReference_value() const
{
	return m_slot_EReference_value;
}


// End Class Slot

// Begin Class StartClassifierBehaviorAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getStartClassifierBehaviorAction_EClass() const
{
	return m_startClassifierBehaviorAction_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getStartClassifierBehaviorAction_EReference_object() const
{
	return m_startClassifierBehaviorAction_EReference_object;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStartClassifierBehaviorAction_EOperation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_startClassifierBehaviorAction_EOperation_multiplicity_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStartClassifierBehaviorAction_EOperation_type_has_classifier_EDiagnosticChain_EMap() const
{
	return m_startClassifierBehaviorAction_EOperation_type_has_classifier_EDiagnosticChain_EMap;
}

// End Class StartClassifierBehaviorAction

// Begin Class StartObjectBehaviorAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getStartObjectBehaviorAction_EClass() const
{
	return m_startObjectBehaviorAction_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getStartObjectBehaviorAction_EReference_object() const
{
	return m_startObjectBehaviorAction_EReference_object;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStartObjectBehaviorAction_EOperation_behavior() const
{
	return m_startObjectBehaviorAction_EOperation_behavior;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStartObjectBehaviorAction_EOperation_multiplicity_of_object_EDiagnosticChain_EMap() const
{
	return m_startObjectBehaviorAction_EOperation_multiplicity_of_object_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStartObjectBehaviorAction_EOperation_no_onport_EDiagnosticChain_EMap() const
{
	return m_startObjectBehaviorAction_EOperation_no_onport_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStartObjectBehaviorAction_EOperation_type_of_object_EDiagnosticChain_EMap() const
{
	return m_startObjectBehaviorAction_EOperation_type_of_object_EDiagnosticChain_EMap;
}

// End Class StartObjectBehaviorAction

// Begin Class State
std::shared_ptr<ecore::EClass> UmlPackageImpl::getState_EClass() const
{
	return m_state_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getState_EAttribute_isComposite() const
{
	return m_state_EAttribute_isComposite;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getState_EAttribute_isOrthogonal() const
{
	return m_state_EAttribute_isOrthogonal;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getState_EAttribute_isSimple() const
{
	return m_state_EAttribute_isSimple;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getState_EAttribute_isSubmachineState() const
{
	return m_state_EAttribute_isSubmachineState;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getState_EReference_connection() const
{
	return m_state_EReference_connection;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getState_EReference_connectionPoint() const
{
	return m_state_EReference_connectionPoint;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getState_EReference_deferrableTrigger() const
{
	return m_state_EReference_deferrableTrigger;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getState_EReference_doActivity() const
{
	return m_state_EReference_doActivity;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getState_EReference_entry() const
{
	return m_state_EReference_entry;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getState_EReference_exit() const
{
	return m_state_EReference_exit;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getState_EReference_redefinedState() const
{
	return m_state_EReference_redefinedState;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getState_EReference_region() const
{
	return m_state_EReference_region;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getState_EReference_stateInvariant() const
{
	return m_state_EReference_stateInvariant;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getState_EReference_submachine() const
{
	return m_state_EReference_submachine;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getState_EOperation_composite_states_EDiagnosticChain_EMap() const
{
	return m_state_EOperation_composite_states_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getState_EOperation_destinations_or_sources_of_transitions_EDiagnosticChain_EMap() const
{
	return m_state_EOperation_destinations_or_sources_of_transitions_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getState_EOperation_entry_or_exit_EDiagnosticChain_EMap() const
{
	return m_state_EOperation_entry_or_exit_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getState_EOperation_isComposite() const
{
	return m_state_EOperation_isComposite;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getState_EOperation_isOrthogonal() const
{
	return m_state_EOperation_isOrthogonal;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getState_EOperation_isSimple() const
{
	return m_state_EOperation_isSimple;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getState_EOperation_isSubmachineState() const
{
	return m_state_EOperation_isSubmachineState;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getState_EOperation_redefinitionContext() const
{
	return m_state_EOperation_redefinitionContext;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getState_EOperation_submachine_or_regions_EDiagnosticChain_EMap() const
{
	return m_state_EOperation_submachine_or_regions_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getState_EOperation_submachine_states_EDiagnosticChain_EMap() const
{
	return m_state_EOperation_submachine_states_EDiagnosticChain_EMap;
}

// End Class State

// Begin Class StateInvariant
std::shared_ptr<ecore::EClass> UmlPackageImpl::getStateInvariant_EClass() const
{
	return m_stateInvariant_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getStateInvariant_EReference_invariant() const
{
	return m_stateInvariant_EReference_invariant;
}


// End Class StateInvariant

// Begin Class StateMachine
std::shared_ptr<ecore::EClass> UmlPackageImpl::getStateMachine_EClass() const
{
	return m_stateMachine_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getStateMachine_EReference_connectionPoint() const
{
	return m_stateMachine_EReference_connectionPoint;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getStateMachine_EReference_extendedStateMachine() const
{
	return m_stateMachine_EReference_extendedStateMachine;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getStateMachine_EReference_region() const
{
	return m_stateMachine_EReference_region;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getStateMachine_EReference_submachineState() const
{
	return m_stateMachine_EReference_submachineState;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStateMachine_EOperation_lCA_Vertex_Vertex() const
{
	return m_stateMachine_EOperation_lCA_Vertex_Vertex;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStateMachine_EOperation_lCAState_Vertex_Vertex() const
{
	return m_stateMachine_EOperation_lCAState_Vertex_Vertex;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStateMachine_EOperation_ancestor_Vertex_Vertex() const
{
	return m_stateMachine_EOperation_ancestor_Vertex_Vertex;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStateMachine_EOperation_classifier_context_EDiagnosticChain_EMap() const
{
	return m_stateMachine_EOperation_classifier_context_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStateMachine_EOperation_connection_points_EDiagnosticChain_EMap() const
{
	return m_stateMachine_EOperation_connection_points_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStateMachine_EOperation_context_classifier_EDiagnosticChain_EMap() const
{
	return m_stateMachine_EOperation_context_classifier_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStateMachine_EOperation_method_EDiagnosticChain_EMap() const
{
	return m_stateMachine_EOperation_method_EDiagnosticChain_EMap;
}

// End Class StateMachine

// Begin Class Stereotype
std::shared_ptr<ecore::EClass> UmlPackageImpl::getStereotype_EClass() const
{
	return m_stereotype_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getStereotype_EReference_icon() const
{
	return m_stereotype_EReference_icon;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getStereotype_EReference_profile() const
{
	return m_stereotype_EReference_profile;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype_EOperation_associationEndOwnership_EDiagnosticChain_EMap() const
{
	return m_stereotype_EOperation_associationEndOwnership_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype_EOperation_base_property_multiplicity_multiple_extension_EDiagnosticChain_EMap() const
{
	return m_stereotype_EOperation_base_property_multiplicity_multiple_extension_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype_EOperation_base_property_multiplicity_single_extension_EDiagnosticChain_EMap() const
{
	return m_stereotype_EOperation_base_property_multiplicity_single_extension_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype_EOperation_base_property_upper_bound_EDiagnosticChain_EMap() const
{
	return m_stereotype_EOperation_base_property_upper_bound_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype_EOperation_binaryAssociationsOnly_EDiagnosticChain_EMap() const
{
	return m_stereotype_EOperation_binaryAssociationsOnly_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype_EOperation_containingProfile() const
{
	return m_stereotype_EOperation_containingProfile;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype_EOperation_createExtension_Class_Boolean() const
{
	return m_stereotype_EOperation_createExtension_Class_Boolean;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype_EOperation_createIcon_String() const
{
	return m_stereotype_EOperation_createIcon_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype_EOperation_createIcon_String_String() const
{
	return m_stereotype_EOperation_createIcon_String_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype_EOperation_generalize_EDiagnosticChain_EMap() const
{
	return m_stereotype_EOperation_generalize_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype_EOperation_getAllExtendedMetaclasses() const
{
	return m_stereotype_EOperation_getAllExtendedMetaclasses;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype_EOperation_getDefinition() const
{
	return m_stereotype_EOperation_getDefinition;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype_EOperation_getExtendedMetaclasses() const
{
	return m_stereotype_EOperation_getExtendedMetaclasses;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype_EOperation_getKeyword() const
{
	return m_stereotype_EOperation_getKeyword;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype_EOperation_getKeyword_Boolean() const
{
	return m_stereotype_EOperation_getKeyword_Boolean;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype_EOperation_getProfile() const
{
	return m_stereotype_EOperation_getProfile;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype_EOperation_name_not_clash_EDiagnosticChain_EMap() const
{
	return m_stereotype_EOperation_name_not_clash_EDiagnosticChain_EMap;
}

// End Class Stereotype

// Begin Class StringExpression
std::shared_ptr<ecore::EClass> UmlPackageImpl::getStringExpression_EClass() const
{
	return m_stringExpression_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getStringExpression_EReference_owningExpression() const
{
	return m_stringExpression_EReference_owningExpression;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getStringExpression_EReference_subExpression() const
{
	return m_stringExpression_EReference_subExpression;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStringExpression_EOperation_operands_EDiagnosticChain_EMap() const
{
	return m_stringExpression_EOperation_operands_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStringExpression_EOperation_subexpressions_EDiagnosticChain_EMap() const
{
	return m_stringExpression_EOperation_subexpressions_EDiagnosticChain_EMap;
}

// End Class StringExpression

// Begin Class StructuralFeature
std::shared_ptr<ecore::EClass> UmlPackageImpl::getStructuralFeature_EClass() const
{
	return m_structuralFeature_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getStructuralFeature_EAttribute_isReadOnly() const
{
	return m_structuralFeature_EAttribute_isReadOnly;
}



// End Class StructuralFeature

// Begin Class StructuralFeatureAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getStructuralFeatureAction_EClass() const
{
	return m_structuralFeatureAction_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getStructuralFeatureAction_EReference_object() const
{
	return m_structuralFeatureAction_EReference_object;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getStructuralFeatureAction_EReference_structuralFeature() const
{
	return m_structuralFeatureAction_EReference_structuralFeature;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStructuralFeatureAction_EOperation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_structuralFeatureAction_EOperation_multiplicity_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStructuralFeatureAction_EOperation_not_static_EDiagnosticChain_EMap() const
{
	return m_structuralFeatureAction_EOperation_not_static_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStructuralFeatureAction_EOperation_object_type_EDiagnosticChain_EMap() const
{
	return m_structuralFeatureAction_EOperation_object_type_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStructuralFeatureAction_EOperation_one_featuring_classifier_EDiagnosticChain_EMap() const
{
	return m_structuralFeatureAction_EOperation_one_featuring_classifier_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStructuralFeatureAction_EOperation_visibility_EDiagnosticChain_EMap() const
{
	return m_structuralFeatureAction_EOperation_visibility_EDiagnosticChain_EMap;
}

// End Class StructuralFeatureAction

// Begin Class StructuredActivityNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getStructuredActivityNode_EClass() const
{
	return m_structuredActivityNode_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getStructuredActivityNode_EAttribute_mustIsolate() const
{
	return m_structuredActivityNode_EAttribute_mustIsolate;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getStructuredActivityNode_EReference_edge() const
{
	return m_structuredActivityNode_EReference_edge;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getStructuredActivityNode_EReference_node() const
{
	return m_structuredActivityNode_EReference_node;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getStructuredActivityNode_EReference_structuredNodeInput() const
{
	return m_structuredActivityNode_EReference_structuredNodeInput;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getStructuredActivityNode_EReference_structuredNodeOutput() const
{
	return m_structuredActivityNode_EReference_structuredNodeOutput;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getStructuredActivityNode_EReference_variable() const
{
	return m_structuredActivityNode_EReference_variable;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStructuredActivityNode_EOperation_edges_EDiagnosticChain_EMap() const
{
	return m_structuredActivityNode_EOperation_edges_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStructuredActivityNode_EOperation_input_pin_edges_EDiagnosticChain_EMap() const
{
	return m_structuredActivityNode_EOperation_input_pin_edges_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStructuredActivityNode_EOperation_output_pin_edges_EDiagnosticChain_EMap() const
{
	return m_structuredActivityNode_EOperation_output_pin_edges_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStructuredActivityNode_EOperation_sourceNodes() const
{
	return m_structuredActivityNode_EOperation_sourceNodes;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStructuredActivityNode_EOperation_targetNodes() const
{
	return m_structuredActivityNode_EOperation_targetNodes;
}

// End Class StructuredActivityNode

// Begin Class StructuredClassifier
std::shared_ptr<ecore::EClass> UmlPackageImpl::getStructuredClassifier_EClass() const
{
	return m_structuredClassifier_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getStructuredClassifier_EReference_ownedAttribute() const
{
	return m_structuredClassifier_EReference_ownedAttribute;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getStructuredClassifier_EReference_ownedConnector() const
{
	return m_structuredClassifier_EReference_ownedConnector;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getStructuredClassifier_EReference_part() const
{
	return m_structuredClassifier_EReference_part;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getStructuredClassifier_EReference_role() const
{
	return m_structuredClassifier_EReference_role;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStructuredClassifier_EOperation_allRoles() const
{
	return m_structuredClassifier_EOperation_allRoles;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStructuredClassifier_EOperation_createOwnedAttribute_String_UnlimitedNatural() const
{
	return m_structuredClassifier_EOperation_createOwnedAttribute_String_UnlimitedNatural;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStructuredClassifier_EOperation_getParts() const
{
	return m_structuredClassifier_EOperation_getParts;
}

// End Class StructuredClassifier

// Begin Class Substitution
std::shared_ptr<ecore::EClass> UmlPackageImpl::getSubstitution_EClass() const
{
	return m_substitution_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getSubstitution_EReference_contract() const
{
	return m_substitution_EReference_contract;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getSubstitution_EReference_substitutingClassifier() const
{
	return m_substitution_EReference_substitutingClassifier;
}


// End Class Substitution

// Begin Class TemplateBinding
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTemplateBinding_EClass() const
{
	return m_templateBinding_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateBinding_EReference_boundElement() const
{
	return m_templateBinding_EReference_boundElement;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateBinding_EReference_parameterSubstitution() const
{
	return m_templateBinding_EReference_parameterSubstitution;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateBinding_EReference_signature() const
{
	return m_templateBinding_EReference_signature;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTemplateBinding_EOperation_one_parameter_substitution_EDiagnosticChain_EMap() const
{
	return m_templateBinding_EOperation_one_parameter_substitution_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTemplateBinding_EOperation_parameter_substitution_formal_EDiagnosticChain_EMap() const
{
	return m_templateBinding_EOperation_parameter_substitution_formal_EDiagnosticChain_EMap;
}

// End Class TemplateBinding

// Begin Class TemplateParameter
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTemplateParameter_EClass() const
{
	return m_templateParameter_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateParameter_EReference_default() const
{
	return m_templateParameter_EReference_default;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateParameter_EReference_ownedDefault() const
{
	return m_templateParameter_EReference_ownedDefault;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateParameter_EReference_ownedParameteredElement() const
{
	return m_templateParameter_EReference_ownedParameteredElement;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateParameter_EReference_parameteredElement() const
{
	return m_templateParameter_EReference_parameteredElement;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateParameter_EReference_signature() const
{
	return m_templateParameter_EReference_signature;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTemplateParameter_EOperation_must_be_compatible_EDiagnosticChain_EMap() const
{
	return m_templateParameter_EOperation_must_be_compatible_EDiagnosticChain_EMap;
}

// End Class TemplateParameter

// Begin Class TemplateParameterSubstitution
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTemplateParameterSubstitution_EClass() const
{
	return m_templateParameterSubstitution_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateParameterSubstitution_EReference_actual() const
{
	return m_templateParameterSubstitution_EReference_actual;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateParameterSubstitution_EReference_formal() const
{
	return m_templateParameterSubstitution_EReference_formal;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateParameterSubstitution_EReference_ownedActual() const
{
	return m_templateParameterSubstitution_EReference_ownedActual;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateParameterSubstitution_EReference_templateBinding() const
{
	return m_templateParameterSubstitution_EReference_templateBinding;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTemplateParameterSubstitution_EOperation_must_be_compatible_EDiagnosticChain_EMap() const
{
	return m_templateParameterSubstitution_EOperation_must_be_compatible_EDiagnosticChain_EMap;
}

// End Class TemplateParameterSubstitution

// Begin Class TemplateSignature
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTemplateSignature_EClass() const
{
	return m_templateSignature_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateSignature_EReference_ownedParameter() const
{
	return m_templateSignature_EReference_ownedParameter;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateSignature_EReference_parameter() const
{
	return m_templateSignature_EReference_parameter;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateSignature_EReference_template() const
{
	return m_templateSignature_EReference_template;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTemplateSignature_EOperation_own_elements_EDiagnosticChain_EMap() const
{
	return m_templateSignature_EOperation_own_elements_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTemplateSignature_EOperation_unique_parameters_EDiagnosticChain_EMap() const
{
	return m_templateSignature_EOperation_unique_parameters_EDiagnosticChain_EMap;
}

// End Class TemplateSignature

// Begin Class TemplateableElement
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTemplateableElement_EClass() const
{
	return m_templateableElement_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateableElement_EReference_ownedTemplateSignature() const
{
	return m_templateableElement_EReference_ownedTemplateSignature;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateableElement_EReference_templateBinding() const
{
	return m_templateableElement_EReference_templateBinding;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTemplateableElement_EOperation_isTemplate() const
{
	return m_templateableElement_EOperation_isTemplate;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTemplateableElement_EOperation_parameterableElements() const
{
	return m_templateableElement_EOperation_parameterableElements;
}

// End Class TemplateableElement

// Begin Class TestIdentityAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTestIdentityAction_EClass() const
{
	return m_testIdentityAction_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getTestIdentityAction_EReference_first() const
{
	return m_testIdentityAction_EReference_first;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTestIdentityAction_EReference_result() const
{
	return m_testIdentityAction_EReference_result;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTestIdentityAction_EReference_second() const
{
	return m_testIdentityAction_EReference_second;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTestIdentityAction_EOperation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_testIdentityAction_EOperation_multiplicity_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTestIdentityAction_EOperation_no_type_EDiagnosticChain_EMap() const
{
	return m_testIdentityAction_EOperation_no_type_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTestIdentityAction_EOperation_result_is_boolean_EDiagnosticChain_EMap() const
{
	return m_testIdentityAction_EOperation_result_is_boolean_EDiagnosticChain_EMap;
}

// End Class TestIdentityAction

// Begin Class TimeConstraint
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTimeConstraint_EClass() const
{
	return m_timeConstraint_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getTimeConstraint_EAttribute_firstEvent() const
{
	return m_timeConstraint_EAttribute_firstEvent;
}


std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTimeConstraint_EOperation_has_one_constrainedElement_EDiagnosticChain_EMap() const
{
	return m_timeConstraint_EOperation_has_one_constrainedElement_EDiagnosticChain_EMap;
}

// End Class TimeConstraint

// Begin Class TimeEvent
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTimeEvent_EClass() const
{
	return m_timeEvent_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getTimeEvent_EAttribute_isRelative() const
{
	return m_timeEvent_EAttribute_isRelative;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getTimeEvent_EReference_when() const
{
	return m_timeEvent_EReference_when;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTimeEvent_EOperation_when_non_negative_EDiagnosticChain_EMap() const
{
	return m_timeEvent_EOperation_when_non_negative_EDiagnosticChain_EMap;
}

// End Class TimeEvent

// Begin Class TimeExpression
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTimeExpression_EClass() const
{
	return m_timeExpression_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getTimeExpression_EReference_expr() const
{
	return m_timeExpression_EReference_expr;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTimeExpression_EReference_observation() const
{
	return m_timeExpression_EReference_observation;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTimeExpression_EOperation_no_expr_requires_observation_EDiagnosticChain_EMap() const
{
	return m_timeExpression_EOperation_no_expr_requires_observation_EDiagnosticChain_EMap;
}

// End Class TimeExpression

// Begin Class TimeInterval
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTimeInterval_EClass() const
{
	return m_timeInterval_EClass;
}




// End Class TimeInterval

// Begin Class TimeObservation
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTimeObservation_EClass() const
{
	return m_timeObservation_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getTimeObservation_EAttribute_firstEvent() const
{
	return m_timeObservation_EAttribute_firstEvent;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getTimeObservation_EReference_event() const
{
	return m_timeObservation_EReference_event;
}


// End Class TimeObservation

// Begin Class Transition
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTransition_EClass() const
{
	return m_transition_EClass;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getTransition_EAttribute_kind() const
{
	return m_transition_EAttribute_kind;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getTransition_EReference_container() const
{
	return m_transition_EReference_container;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTransition_EReference_effect() const
{
	return m_transition_EReference_effect;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTransition_EReference_guard() const
{
	return m_transition_EReference_guard;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTransition_EReference_redefinedTransition() const
{
	return m_transition_EReference_redefinedTransition;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTransition_EReference_source() const
{
	return m_transition_EReference_source;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTransition_EReference_target() const
{
	return m_transition_EReference_target;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTransition_EReference_trigger() const
{
	return m_transition_EReference_trigger;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTransition_EOperation_containingStateMachine() const
{
	return m_transition_EOperation_containingStateMachine;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTransition_EOperation_fork_segment_guards_EDiagnosticChain_EMap() const
{
	return m_transition_EOperation_fork_segment_guards_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTransition_EOperation_fork_segment_state_EDiagnosticChain_EMap() const
{
	return m_transition_EOperation_fork_segment_state_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTransition_EOperation_initial_transition_EDiagnosticChain_EMap() const
{
	return m_transition_EOperation_initial_transition_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTransition_EOperation_join_segment_guards_EDiagnosticChain_EMap() const
{
	return m_transition_EOperation_join_segment_guards_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTransition_EOperation_join_segment_state_EDiagnosticChain_EMap() const
{
	return m_transition_EOperation_join_segment_state_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTransition_EOperation_outgoing_pseudostates_EDiagnosticChain_EMap() const
{
	return m_transition_EOperation_outgoing_pseudostates_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTransition_EOperation_redefinitionContext() const
{
	return m_transition_EOperation_redefinitionContext;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTransition_EOperation_state_is_external_EDiagnosticChain_EMap() const
{
	return m_transition_EOperation_state_is_external_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTransition_EOperation_state_is_internal_EDiagnosticChain_EMap() const
{
	return m_transition_EOperation_state_is_internal_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTransition_EOperation_state_is_local_EDiagnosticChain_EMap() const
{
	return m_transition_EOperation_state_is_local_EDiagnosticChain_EMap;
}

// End Class Transition

// Begin Class Trigger
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTrigger_EClass() const
{
	return m_trigger_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getTrigger_EReference_event() const
{
	return m_trigger_EReference_event;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTrigger_EReference_port() const
{
	return m_trigger_EReference_port;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTrigger_EOperation_trigger_with_ports_EDiagnosticChain_EMap() const
{
	return m_trigger_EOperation_trigger_with_ports_EDiagnosticChain_EMap;
}

// End Class Trigger

// Begin Class Type
std::shared_ptr<ecore::EClass> UmlPackageImpl::getType_EClass() const
{
	return m_type_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getType_EReference_package() const
{
	return m_type_EReference_package;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getType_EOperation_conformsTo_Type() const
{
	return m_type_EOperation_conformsTo_Type;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getType_EOperation_createAssociation_Boolean_UnlimitedNatural() const
{
	return m_type_EOperation_createAssociation_Boolean_UnlimitedNatural;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getType_EOperation_getAssociations() const
{
	return m_type_EOperation_getAssociations;
}

// End Class Type

// Begin Class TypedElement
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTypedElement_EClass() const
{
	return m_typedElement_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getTypedElement_EReference_type() const
{
	return m_typedElement_EReference_type;
}


// End Class TypedElement

// Begin Class UnmarshallAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getUnmarshallAction_EClass() const
{
	return m_unmarshallAction_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getUnmarshallAction_EReference_object() const
{
	return m_unmarshallAction_EReference_object;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getUnmarshallAction_EReference_result() const
{
	return m_unmarshallAction_EReference_result;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getUnmarshallAction_EReference_unmarshallType() const
{
	return m_unmarshallAction_EReference_unmarshallType;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getUnmarshallAction_EOperation_multiplicity_of_object_EDiagnosticChain_EMap() const
{
	return m_unmarshallAction_EOperation_multiplicity_of_object_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getUnmarshallAction_EOperation_number_of_result_EDiagnosticChain_EMap() const
{
	return m_unmarshallAction_EOperation_number_of_result_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getUnmarshallAction_EOperation_object_type_EDiagnosticChain_EMap() const
{
	return m_unmarshallAction_EOperation_object_type_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getUnmarshallAction_EOperation_structural_feature_EDiagnosticChain_EMap() const
{
	return m_unmarshallAction_EOperation_structural_feature_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getUnmarshallAction_EOperation_type_ordering_and_multiplicity_EDiagnosticChain_EMap() const
{
	return m_unmarshallAction_EOperation_type_ordering_and_multiplicity_EDiagnosticChain_EMap;
}

// End Class UnmarshallAction

// Begin Class Usage
std::shared_ptr<ecore::EClass> UmlPackageImpl::getUsage_EClass() const
{
	return m_usage_EClass;
}




// End Class Usage

// Begin Class UseCase
std::shared_ptr<ecore::EClass> UmlPackageImpl::getUseCase_EClass() const
{
	return m_useCase_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getUseCase_EReference_extend() const
{
	return m_useCase_EReference_extend;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getUseCase_EReference_extensionPoint() const
{
	return m_useCase_EReference_extensionPoint;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getUseCase_EReference_include() const
{
	return m_useCase_EReference_include;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getUseCase_EReference_subject() const
{
	return m_useCase_EReference_subject;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getUseCase_EOperation_allIncludedUseCases() const
{
	return m_useCase_EOperation_allIncludedUseCases;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getUseCase_EOperation_binary_associations_EDiagnosticChain_EMap() const
{
	return m_useCase_EOperation_binary_associations_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getUseCase_EOperation_cannot_include_self_EDiagnosticChain_EMap() const
{
	return m_useCase_EOperation_cannot_include_self_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getUseCase_EOperation_must_have_name_EDiagnosticChain_EMap() const
{
	return m_useCase_EOperation_must_have_name_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getUseCase_EOperation_no_association_to_use_case_EDiagnosticChain_EMap() const
{
	return m_useCase_EOperation_no_association_to_use_case_EDiagnosticChain_EMap;
}

// End Class UseCase

// Begin Class ValuePin
std::shared_ptr<ecore::EClass> UmlPackageImpl::getValuePin_EClass() const
{
	return m_valuePin_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getValuePin_EReference_value() const
{
	return m_valuePin_EReference_value;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getValuePin_EOperation_compatible_type_EDiagnosticChain_EMap() const
{
	return m_valuePin_EOperation_compatible_type_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getValuePin_EOperation_no_incoming_edges_EDiagnosticChain_EMap() const
{
	return m_valuePin_EOperation_no_incoming_edges_EDiagnosticChain_EMap;
}

// End Class ValuePin

// Begin Class ValueSpecification
std::shared_ptr<ecore::EClass> UmlPackageImpl::getValueSpecification_EClass() const
{
	return m_valueSpecification_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getValueSpecification_EReference_owningSlot() const
{
	return m_valueSpecification_EReference_owningSlot;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getValueSpecification_EOperation_booleanValue() const
{
	return m_valueSpecification_EOperation_booleanValue;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getValueSpecification_EOperation_integerValue() const
{
	return m_valueSpecification_EOperation_integerValue;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getValueSpecification_EOperation_isComputable() const
{
	return m_valueSpecification_EOperation_isComputable;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getValueSpecification_EOperation_isNull() const
{
	return m_valueSpecification_EOperation_isNull;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getValueSpecification_EOperation_realValue() const
{
	return m_valueSpecification_EOperation_realValue;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getValueSpecification_EOperation_stringValue() const
{
	return m_valueSpecification_EOperation_stringValue;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getValueSpecification_EOperation_unlimitedValue() const
{
	return m_valueSpecification_EOperation_unlimitedValue;
}

// End Class ValueSpecification

// Begin Class ValueSpecificationAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getValueSpecificationAction_EClass() const
{
	return m_valueSpecificationAction_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getValueSpecificationAction_EReference_result() const
{
	return m_valueSpecificationAction_EReference_result;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getValueSpecificationAction_EReference_value() const
{
	return m_valueSpecificationAction_EReference_value;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getValueSpecificationAction_EOperation_compatible_type_EDiagnosticChain_EMap() const
{
	return m_valueSpecificationAction_EOperation_compatible_type_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getValueSpecificationAction_EOperation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_valueSpecificationAction_EOperation_multiplicity_EDiagnosticChain_EMap;
}

// End Class ValueSpecificationAction

// Begin Class Variable
std::shared_ptr<ecore::EClass> UmlPackageImpl::getVariable_EClass() const
{
	return m_variable_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getVariable_EReference_activityScope() const
{
	return m_variable_EReference_activityScope;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getVariable_EReference_scope() const
{
	return m_variable_EReference_scope;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getVariable_EOperation_isAccessibleBy_Action() const
{
	return m_variable_EOperation_isAccessibleBy_Action;
}

// End Class Variable

// Begin Class VariableAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getVariableAction_EClass() const
{
	return m_variableAction_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getVariableAction_EReference_variable() const
{
	return m_variableAction_EReference_variable;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getVariableAction_EOperation_scope_of_variable_EDiagnosticChain_EMap() const
{
	return m_variableAction_EOperation_scope_of_variable_EDiagnosticChain_EMap;
}

// End Class VariableAction

// Begin Class Vertex
std::shared_ptr<ecore::EClass> UmlPackageImpl::getVertex_EClass() const
{
	return m_vertex_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getVertex_EReference_container() const
{
	return m_vertex_EReference_container;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getVertex_EReference_incoming() const
{
	return m_vertex_EReference_incoming;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getVertex_EReference_outgoing() const
{
	return m_vertex_EReference_outgoing;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getVertex_EOperation_containingStateMachine() const
{
	return m_vertex_EOperation_containingStateMachine;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getVertex_EOperation_getIncomings() const
{
	return m_vertex_EOperation_getIncomings;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getVertex_EOperation_getOutgoings() const
{
	return m_vertex_EOperation_getOutgoings;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getVertex_EOperation_isContainedInRegion_Region() const
{
	return m_vertex_EOperation_isContainedInRegion_Region;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getVertex_EOperation_isContainedInState_State() const
{
	return m_vertex_EOperation_isContainedInState_State;
}

// End Class Vertex

// Begin Class WriteLinkAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getWriteLinkAction_EClass() const
{
	return m_writeLinkAction_EClass;
}



std::shared_ptr<ecore::EOperation> UmlPackageImpl::getWriteLinkAction_EOperation_allow_access_EDiagnosticChain_EMap() const
{
	return m_writeLinkAction_EOperation_allow_access_EDiagnosticChain_EMap;
}

// End Class WriteLinkAction

// Begin Class WriteStructuralFeatureAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getWriteStructuralFeatureAction_EClass() const
{
	return m_writeStructuralFeatureAction_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getWriteStructuralFeatureAction_EReference_result() const
{
	return m_writeStructuralFeatureAction_EReference_result;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getWriteStructuralFeatureAction_EReference_value() const
{
	return m_writeStructuralFeatureAction_EReference_value;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getWriteStructuralFeatureAction_EOperation_multiplicity_of_result_EDiagnosticChain_EMap() const
{
	return m_writeStructuralFeatureAction_EOperation_multiplicity_of_result_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getWriteStructuralFeatureAction_EOperation_multiplicity_of_value_EDiagnosticChain_EMap() const
{
	return m_writeStructuralFeatureAction_EOperation_multiplicity_of_value_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getWriteStructuralFeatureAction_EOperation_type_of_result_EDiagnosticChain_EMap() const
{
	return m_writeStructuralFeatureAction_EOperation_type_of_result_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getWriteStructuralFeatureAction_EOperation_type_of_value_EDiagnosticChain_EMap() const
{
	return m_writeStructuralFeatureAction_EOperation_type_of_value_EDiagnosticChain_EMap;
}

// End Class WriteStructuralFeatureAction

// Begin Class WriteVariableAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getWriteVariableAction_EClass() const
{
	return m_writeVariableAction_EClass;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getWriteVariableAction_EReference_value() const
{
	return m_writeVariableAction_EReference_value;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getWriteVariableAction_EOperation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_writeVariableAction_EOperation_multiplicity_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getWriteVariableAction_EOperation_value_type_EDiagnosticChain_EMap() const
{
	return m_writeVariableAction_EOperation_value_type_EDiagnosticChain_EMap;
}

// End Class WriteVariableAction
std::shared_ptr<ecore::EEnum> UmlPackageImpl::getAggregationKind_EEnum() const
{
	return m_aggregationKind_EEnum;
}
std::shared_ptr<ecore::EEnum> UmlPackageImpl::getCallConcurrencyKind_EEnum() const
{
	return m_callConcurrencyKind_EEnum;
}
std::shared_ptr<ecore::EEnum> UmlPackageImpl::getConnectorKind_EEnum() const
{
	return m_connectorKind_EEnum;
}
std::shared_ptr<ecore::EEnum> UmlPackageImpl::getExpansionKind_EEnum() const
{
	return m_expansionKind_EEnum;
}
std::shared_ptr<ecore::EEnum> UmlPackageImpl::getInteractionOperatorKind_EEnum() const
{
	return m_interactionOperatorKind_EEnum;
}
std::shared_ptr<ecore::EEnum> UmlPackageImpl::getMessageKind_EEnum() const
{
	return m_messageKind_EEnum;
}
std::shared_ptr<ecore::EEnum> UmlPackageImpl::getMessageSort_EEnum() const
{
	return m_messageSort_EEnum;
}
std::shared_ptr<ecore::EEnum> UmlPackageImpl::getObjectNodeOrderingKind_EEnum() const
{
	return m_objectNodeOrderingKind_EEnum;
}
std::shared_ptr<ecore::EEnum> UmlPackageImpl::getParameterDirectionKind_EEnum() const
{
	return m_parameterDirectionKind_EEnum;
}
std::shared_ptr<ecore::EEnum> UmlPackageImpl::getParameterEffectKind_EEnum() const
{
	return m_parameterEffectKind_EEnum;
}
std::shared_ptr<ecore::EEnum> UmlPackageImpl::getPseudostateKind_EEnum() const
{
	return m_pseudostateKind_EEnum;
}
std::shared_ptr<ecore::EEnum> UmlPackageImpl::getTransitionKind_EEnum() const
{
	return m_transitionKind_EEnum;
}
std::shared_ptr<ecore::EEnum> UmlPackageImpl::getVisibilityKind_EEnum() const
{
	return m_visibilityKind_EEnum;
}

