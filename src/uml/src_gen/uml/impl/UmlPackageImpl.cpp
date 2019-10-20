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
std::shared_ptr<ecore::EClass> UmlPackageImpl::getAbstraction_Class() const
{
	return m_abstraction_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getAbstraction_Attribute_mapping() const
{
	return m_abstraction_Attribute_mapping;
}


// End Class Abstraction

// Begin Class AcceptCallAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getAcceptCallAction_Class() const
{
	return m_acceptCallAction_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getAcceptCallAction_Attribute_returnInformation() const
{
	return m_acceptCallAction_Attribute_returnInformation;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAcceptCallAction_Operation_result_pins_EDiagnosticChain_EMap() const
{
	return m_acceptCallAction_Operation_result_pins_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAcceptCallAction_Operation_trigger_call_event_EDiagnosticChain_EMap() const
{
	return m_acceptCallAction_Operation_trigger_call_event_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAcceptCallAction_Operation_unmarshall_EDiagnosticChain_EMap() const
{
	return m_acceptCallAction_Operation_unmarshall_EDiagnosticChain_EMap;
}

// End Class AcceptCallAction

// Begin Class AcceptEventAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getAcceptEventAction_Class() const
{
	return m_acceptEventAction_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getAcceptEventAction_Attribute_isUnmarshall() const
{
	return m_acceptEventAction_Attribute_isUnmarshall;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getAcceptEventAction_Attribute_result() const
{
	return m_acceptEventAction_Attribute_result;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getAcceptEventAction_Attribute_trigger() const
{
	return m_acceptEventAction_Attribute_trigger;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAcceptEventAction_Operation_conforming_type_EDiagnosticChain_EMap() const
{
	return m_acceptEventAction_Operation_conforming_type_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAcceptEventAction_Operation_no_input_pins_EDiagnosticChain_EMap() const
{
	return m_acceptEventAction_Operation_no_input_pins_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAcceptEventAction_Operation_no_output_pins_EDiagnosticChain_EMap() const
{
	return m_acceptEventAction_Operation_no_output_pins_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAcceptEventAction_Operation_one_output_pin_EDiagnosticChain_EMap() const
{
	return m_acceptEventAction_Operation_one_output_pin_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAcceptEventAction_Operation_unmarshall_signal_events_EDiagnosticChain_EMap() const
{
	return m_acceptEventAction_Operation_unmarshall_signal_events_EDiagnosticChain_EMap;
}

// End Class AcceptEventAction

// Begin Class Action
std::shared_ptr<ecore::EClass> UmlPackageImpl::getAction_Class() const
{
	return m_action_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getAction_Attribute_isLocallyReentrant() const
{
	return m_action_Attribute_isLocallyReentrant;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getAction_Attribute_context() const
{
	return m_action_Attribute_context;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getAction_Attribute_input() const
{
	return m_action_Attribute_input;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getAction_Attribute_localPostcondition() const
{
	return m_action_Attribute_localPostcondition;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getAction_Attribute_localPrecondition() const
{
	return m_action_Attribute_localPrecondition;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getAction_Attribute_output() const
{
	return m_action_Attribute_output;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAction_Operation_allActions() const
{
	return m_action_Operation_allActions;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAction_Operation_allOwnedNodes() const
{
	return m_action_Operation_allOwnedNodes;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAction_Operation_containingBehavior() const
{
	return m_action_Operation_containingBehavior;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAction_Operation_getContext() const
{
	return m_action_Operation_getContext;
}

// End Class Action

// Begin Class ActionExecutionSpecification
std::shared_ptr<ecore::EClass> UmlPackageImpl::getActionExecutionSpecification_Class() const
{
	return m_actionExecutionSpecification_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getActionExecutionSpecification_Attribute_action() const
{
	return m_actionExecutionSpecification_Attribute_action;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActionExecutionSpecification_Operation_action_referenced_EDiagnosticChain_EMap() const
{
	return m_actionExecutionSpecification_Operation_action_referenced_EDiagnosticChain_EMap;
}

// End Class ActionExecutionSpecification

// Begin Class ActionInputPin
std::shared_ptr<ecore::EClass> UmlPackageImpl::getActionInputPin_Class() const
{
	return m_actionInputPin_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getActionInputPin_Attribute_fromAction() const
{
	return m_actionInputPin_Attribute_fromAction;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActionInputPin_Operation_input_pin_EDiagnosticChain_EMap() const
{
	return m_actionInputPin_Operation_input_pin_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActionInputPin_Operation_no_control_or_object_flow_EDiagnosticChain_EMap() const
{
	return m_actionInputPin_Operation_no_control_or_object_flow_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActionInputPin_Operation_one_output_pin_EDiagnosticChain_EMap() const
{
	return m_actionInputPin_Operation_one_output_pin_EDiagnosticChain_EMap;
}

// End Class ActionInputPin

// Begin Class Activity
std::shared_ptr<ecore::EClass> UmlPackageImpl::getActivity_Class() const
{
	return m_activity_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getActivity_Attribute_isReadOnly() const
{
	return m_activity_Attribute_isReadOnly;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getActivity_Attribute_isSingleExecution() const
{
	return m_activity_Attribute_isSingleExecution;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivity_Attribute_edge() const
{
	return m_activity_Attribute_edge;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivity_Attribute_group() const
{
	return m_activity_Attribute_group;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivity_Attribute_node() const
{
	return m_activity_Attribute_node;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivity_Attribute_ownedGroup() const
{
	return m_activity_Attribute_ownedGroup;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivity_Attribute_ownedNode() const
{
	return m_activity_Attribute_ownedNode;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivity_Attribute_partition() const
{
	return m_activity_Attribute_partition;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivity_Attribute_structuredNode() const
{
	return m_activity_Attribute_structuredNode;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivity_Attribute_variable() const
{
	return m_activity_Attribute_variable;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivity_Operation_maximum_one_parameter_node_EDiagnosticChain_EMap() const
{
	return m_activity_Operation_maximum_one_parameter_node_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivity_Operation_maximum_two_parameter_nodes_EDiagnosticChain_EMap() const
{
	return m_activity_Operation_maximum_two_parameter_nodes_EDiagnosticChain_EMap;
}

// End Class Activity

// Begin Class ActivityContent
std::shared_ptr<ecore::EClass> UmlPackageImpl::getActivityContent_Class() const
{
	return m_activityContent_Class;
}



std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivityContent_Operation_containingActivity() const
{
	return m_activityContent_Operation_containingActivity;
}

// End Class ActivityContent

// Begin Class ActivityEdge
std::shared_ptr<ecore::EClass> UmlPackageImpl::getActivityEdge_Class() const
{
	return m_activityEdge_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityEdge_Attribute_activity() const
{
	return m_activityEdge_Attribute_activity;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityEdge_Attribute_guard() const
{
	return m_activityEdge_Attribute_guard;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityEdge_Attribute_inGroup() const
{
	return m_activityEdge_Attribute_inGroup;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityEdge_Attribute_inPartition() const
{
	return m_activityEdge_Attribute_inPartition;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityEdge_Attribute_inStructuredNode() const
{
	return m_activityEdge_Attribute_inStructuredNode;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityEdge_Attribute_interrupts() const
{
	return m_activityEdge_Attribute_interrupts;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityEdge_Attribute_redefinedEdge() const
{
	return m_activityEdge_Attribute_redefinedEdge;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityEdge_Attribute_source() const
{
	return m_activityEdge_Attribute_source;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityEdge_Attribute_target() const
{
	return m_activityEdge_Attribute_target;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityEdge_Attribute_weight() const
{
	return m_activityEdge_Attribute_weight;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivityEdge_Operation_source_and_target_EDiagnosticChain_EMap() const
{
	return m_activityEdge_Operation_source_and_target_EDiagnosticChain_EMap;
}

// End Class ActivityEdge

// Begin Class ActivityFinalNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getActivityFinalNode_Class() const
{
	return m_activityFinalNode_Class;
}




// End Class ActivityFinalNode

// Begin Class ActivityGroup
std::shared_ptr<ecore::EClass> UmlPackageImpl::getActivityGroup_Class() const
{
	return m_activityGroup_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityGroup_Attribute_containedEdge() const
{
	return m_activityGroup_Attribute_containedEdge;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityGroup_Attribute_containedNode() const
{
	return m_activityGroup_Attribute_containedNode;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityGroup_Attribute_inActivity() const
{
	return m_activityGroup_Attribute_inActivity;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityGroup_Attribute_subgroup() const
{
	return m_activityGroup_Attribute_subgroup;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityGroup_Attribute_superGroup() const
{
	return m_activityGroup_Attribute_superGroup;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivityGroup_Operation_nodes_and_edges_EDiagnosticChain_EMap() const
{
	return m_activityGroup_Operation_nodes_and_edges_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivityGroup_Operation_not_contained_EDiagnosticChain_EMap() const
{
	return m_activityGroup_Operation_not_contained_EDiagnosticChain_EMap;
}

// End Class ActivityGroup

// Begin Class ActivityNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getActivityNode_Class() const
{
	return m_activityNode_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityNode_Attribute_activity() const
{
	return m_activityNode_Attribute_activity;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityNode_Attribute_inGroup() const
{
	return m_activityNode_Attribute_inGroup;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityNode_Attribute_inInterruptibleRegion() const
{
	return m_activityNode_Attribute_inInterruptibleRegion;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityNode_Attribute_inPartition() const
{
	return m_activityNode_Attribute_inPartition;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityNode_Attribute_inStructuredNode() const
{
	return m_activityNode_Attribute_inStructuredNode;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityNode_Attribute_incoming() const
{
	return m_activityNode_Attribute_incoming;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityNode_Attribute_outgoing() const
{
	return m_activityNode_Attribute_outgoing;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityNode_Attribute_redefinedNode() const
{
	return m_activityNode_Attribute_redefinedNode;
}


// End Class ActivityNode

// Begin Class ActivityParameterNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getActivityParameterNode_Class() const
{
	return m_activityParameterNode_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityParameterNode_Attribute_parameter() const
{
	return m_activityParameterNode_Attribute_parameter;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivityParameterNode_Operation_has_parameters_EDiagnosticChain_EMap() const
{
	return m_activityParameterNode_Operation_has_parameters_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivityParameterNode_Operation_no_edges_EDiagnosticChain_EMap() const
{
	return m_activityParameterNode_Operation_no_edges_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivityParameterNode_Operation_no_incoming_edges_EDiagnosticChain_EMap() const
{
	return m_activityParameterNode_Operation_no_incoming_edges_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivityParameterNode_Operation_no_outgoing_edges_EDiagnosticChain_EMap() const
{
	return m_activityParameterNode_Operation_no_outgoing_edges_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivityParameterNode_Operation_same_type_EDiagnosticChain_EMap() const
{
	return m_activityParameterNode_Operation_same_type_EDiagnosticChain_EMap;
}

// End Class ActivityParameterNode

// Begin Class ActivityPartition
std::shared_ptr<ecore::EClass> UmlPackageImpl::getActivityPartition_Class() const
{
	return m_activityPartition_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getActivityPartition_Attribute_isDimension() const
{
	return m_activityPartition_Attribute_isDimension;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getActivityPartition_Attribute_isExternal() const
{
	return m_activityPartition_Attribute_isExternal;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityPartition_Attribute_edge() const
{
	return m_activityPartition_Attribute_edge;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityPartition_Attribute_node() const
{
	return m_activityPartition_Attribute_node;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityPartition_Attribute_represents() const
{
	return m_activityPartition_Attribute_represents;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityPartition_Attribute_subpartition() const
{
	return m_activityPartition_Attribute_subpartition;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getActivityPartition_Attribute_superPartition() const
{
	return m_activityPartition_Attribute_superPartition;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivityPartition_Operation_dimension_not_contained_EDiagnosticChain_EMap() const
{
	return m_activityPartition_Operation_dimension_not_contained_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivityPartition_Operation_represents_classifier_EDiagnosticChain_EMap() const
{
	return m_activityPartition_Operation_represents_classifier_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivityPartition_Operation_represents_property_EDiagnosticChain_EMap() const
{
	return m_activityPartition_Operation_represents_property_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActivityPartition_Operation_represents_property_and_is_contained_EDiagnosticChain_EMap() const
{
	return m_activityPartition_Operation_represents_property_and_is_contained_EDiagnosticChain_EMap;
}

// End Class ActivityPartition

// Begin Class Actor
std::shared_ptr<ecore::EClass> UmlPackageImpl::getActor_Class() const
{
	return m_actor_Class;
}



std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActor_Operation_associations_EDiagnosticChain_EMap() const
{
	return m_actor_Operation_associations_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getActor_Operation_must_have_name_EDiagnosticChain_EMap() const
{
	return m_actor_Operation_must_have_name_EDiagnosticChain_EMap;
}

// End Class Actor

// Begin Class AddStructuralFeatureValueAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getAddStructuralFeatureValueAction_Class() const
{
	return m_addStructuralFeatureValueAction_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getAddStructuralFeatureValueAction_Attribute_isReplaceAll() const
{
	return m_addStructuralFeatureValueAction_Attribute_isReplaceAll;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getAddStructuralFeatureValueAction_Attribute_insertAt() const
{
	return m_addStructuralFeatureValueAction_Attribute_insertAt;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAddStructuralFeatureValueAction_Operation_insertAt_pin_EDiagnosticChain_EMap() const
{
	return m_addStructuralFeatureValueAction_Operation_insertAt_pin_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAddStructuralFeatureValueAction_Operation_required_value_EDiagnosticChain_EMap() const
{
	return m_addStructuralFeatureValueAction_Operation_required_value_EDiagnosticChain_EMap;
}

// End Class AddStructuralFeatureValueAction

// Begin Class AddVariableValueAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getAddVariableValueAction_Class() const
{
	return m_addVariableValueAction_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getAddVariableValueAction_Attribute_isReplaceAll() const
{
	return m_addVariableValueAction_Attribute_isReplaceAll;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getAddVariableValueAction_Attribute_insertAt() const
{
	return m_addVariableValueAction_Attribute_insertAt;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAddVariableValueAction_Operation_insertAt_pin_EDiagnosticChain_EMap() const
{
	return m_addVariableValueAction_Operation_insertAt_pin_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAddVariableValueAction_Operation_required_value_EDiagnosticChain_EMap() const
{
	return m_addVariableValueAction_Operation_required_value_EDiagnosticChain_EMap;
}

// End Class AddVariableValueAction

// Begin Class AnyReceiveEvent
std::shared_ptr<ecore::EClass> UmlPackageImpl::getAnyReceiveEvent_Class() const
{
	return m_anyReceiveEvent_Class;
}




// End Class AnyReceiveEvent

// Begin Class Argument
std::shared_ptr<ecore::EClass> UmlPackageImpl::getArgument_Class() const
{
	return m_argument_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getArgument_Attribute_name() const
{
	return m_argument_Attribute_name;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getArgument_Attribute_value() const
{
	return m_argument_Attribute_value;
}


// End Class Argument

// Begin Class Artifact
std::shared_ptr<ecore::EClass> UmlPackageImpl::getArtifact_Class() const
{
	return m_artifact_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getArtifact_Attribute_fileName() const
{
	return m_artifact_Attribute_fileName;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getArtifact_Attribute_manifestation() const
{
	return m_artifact_Attribute_manifestation;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getArtifact_Attribute_nestedArtifact() const
{
	return m_artifact_Attribute_nestedArtifact;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getArtifact_Attribute_ownedAttribute() const
{
	return m_artifact_Attribute_ownedAttribute;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getArtifact_Attribute_ownedOperation() const
{
	return m_artifact_Attribute_ownedOperation;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getArtifact_Operation_createOwnedAttribute_String_UnlimitedNatural() const
{
	return m_artifact_Operation_createOwnedAttribute_String_UnlimitedNatural;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getArtifact_Operation_createOwnedOperation_String_Type() const
{
	return m_artifact_Operation_createOwnedOperation_String_Type;
}

// End Class Artifact

// Begin Class Association
std::shared_ptr<ecore::EClass> UmlPackageImpl::getAssociation_Class() const
{
	return m_association_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getAssociation_Attribute_isDerived() const
{
	return m_association_Attribute_isDerived;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getAssociation_Attribute_endType() const
{
	return m_association_Attribute_endType;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getAssociation_Attribute_memberEnd() const
{
	return m_association_Attribute_memberEnd;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getAssociation_Attribute_navigableOwnedEnd() const
{
	return m_association_Attribute_navigableOwnedEnd;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getAssociation_Attribute_ownedEnd() const
{
	return m_association_Attribute_ownedEnd;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAssociation_Operation_association_ends_EDiagnosticChain_EMap() const
{
	return m_association_Operation_association_ends_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAssociation_Operation_binary_associations_EDiagnosticChain_EMap() const
{
	return m_association_Operation_binary_associations_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAssociation_Operation_ends_must_be_typed_EDiagnosticChain_EMap() const
{
	return m_association_Operation_ends_must_be_typed_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAssociation_Operation_getEndTypes() const
{
	return m_association_Operation_getEndTypes;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAssociation_Operation_isBinary() const
{
	return m_association_Operation_isBinary;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAssociation_Operation_specialized_end_number_EDiagnosticChain_EMap() const
{
	return m_association_Operation_specialized_end_number_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAssociation_Operation_specialized_end_types_EDiagnosticChain_EMap() const
{
	return m_association_Operation_specialized_end_types_EDiagnosticChain_EMap;
}

// End Class Association

// Begin Class AssociationClass
std::shared_ptr<ecore::EClass> UmlPackageImpl::getAssociationClass_Class() const
{
	return m_associationClass_Class;
}



std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAssociationClass_Operation_cannot_be_defined_EDiagnosticChain_EMap() const
{
	return m_associationClass_Operation_cannot_be_defined_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getAssociationClass_Operation_disjoint_attributes_ends_EDiagnosticChain_EMap() const
{
	return m_associationClass_Operation_disjoint_attributes_ends_EDiagnosticChain_EMap;
}

// End Class AssociationClass

// Begin Class Behavior
std::shared_ptr<ecore::EClass> UmlPackageImpl::getBehavior_Class() const
{
	return m_behavior_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getBehavior_Attribute_isReentrant() const
{
	return m_behavior_Attribute_isReentrant;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavior_Attribute_behavioredClassifier() const
{
	return m_behavior_Attribute_behavioredClassifier;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavior_Attribute_context() const
{
	return m_behavior_Attribute_context;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavior_Attribute_ownedParameter() const
{
	return m_behavior_Attribute_ownedParameter;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavior_Attribute_ownedParameterSet() const
{
	return m_behavior_Attribute_ownedParameterSet;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavior_Attribute_postcondition() const
{
	return m_behavior_Attribute_postcondition;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavior_Attribute_precondition() const
{
	return m_behavior_Attribute_precondition;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavior_Attribute_redefinedBehavior() const
{
	return m_behavior_Attribute_redefinedBehavior;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavior_Attribute_specification() const
{
	return m_behavior_Attribute_specification;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavior_Operation_behavioredClassifier_Element() const
{
	return m_behavior_Operation_behavioredClassifier_Element;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavior_Operation_feature_of_context_classifier_EDiagnosticChain_EMap() const
{
	return m_behavior_Operation_feature_of_context_classifier_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavior_Operation_getContext() const
{
	return m_behavior_Operation_getContext;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavior_Operation_inputParameters() const
{
	return m_behavior_Operation_inputParameters;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavior_Operation_most_one_behavior_EDiagnosticChain_EMap() const
{
	return m_behavior_Operation_most_one_behavior_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavior_Operation_outputParameters() const
{
	return m_behavior_Operation_outputParameters;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavior_Operation_parameters_match_EDiagnosticChain_EMap() const
{
	return m_behavior_Operation_parameters_match_EDiagnosticChain_EMap;
}

// End Class Behavior

// Begin Class BehaviorExecutionSpecification
std::shared_ptr<ecore::EClass> UmlPackageImpl::getBehaviorExecutionSpecification_Class() const
{
	return m_behaviorExecutionSpecification_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehaviorExecutionSpecification_Attribute_behavior() const
{
	return m_behaviorExecutionSpecification_Attribute_behavior;
}


// End Class BehaviorExecutionSpecification

// Begin Class BehavioralFeature
std::shared_ptr<ecore::EClass> UmlPackageImpl::getBehavioralFeature_Class() const
{
	return m_behavioralFeature_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getBehavioralFeature_Attribute_concurrency() const
{
	return m_behavioralFeature_Attribute_concurrency;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getBehavioralFeature_Attribute_isAbstract() const
{
	return m_behavioralFeature_Attribute_isAbstract;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavioralFeature_Attribute_method() const
{
	return m_behavioralFeature_Attribute_method;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavioralFeature_Attribute_ownedParameter() const
{
	return m_behavioralFeature_Attribute_ownedParameter;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavioralFeature_Attribute_ownedParameterSet() const
{
	return m_behavioralFeature_Attribute_ownedParameterSet;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavioralFeature_Attribute_raisedException() const
{
	return m_behavioralFeature_Attribute_raisedException;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavioralFeature_Operation_abstract_no_method_EDiagnosticChain_EMap() const
{
	return m_behavioralFeature_Operation_abstract_no_method_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavioralFeature_Operation_createReturnResult_String_Type() const
{
	return m_behavioralFeature_Operation_createReturnResult_String_Type;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavioralFeature_Operation_inputParameters() const
{
	return m_behavioralFeature_Operation_inputParameters;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavioralFeature_Operation_outputParameters() const
{
	return m_behavioralFeature_Operation_outputParameters;
}

// End Class BehavioralFeature

// Begin Class BehavioredClassifier
std::shared_ptr<ecore::EClass> UmlPackageImpl::getBehavioredClassifier_Class() const
{
	return m_behavioredClassifier_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavioredClassifier_Attribute_classifierBehavior() const
{
	return m_behavioredClassifier_Attribute_classifierBehavior;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavioredClassifier_Attribute_interfaceRealization() const
{
	return m_behavioredClassifier_Attribute_interfaceRealization;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getBehavioredClassifier_Attribute_ownedBehavior() const
{
	return m_behavioredClassifier_Attribute_ownedBehavior;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavioredClassifier_Operation_class_behavior_EDiagnosticChain_EMap() const
{
	return m_behavioredClassifier_Operation_class_behavior_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavioredClassifier_Operation_getAllImplementedInterfaces() const
{
	return m_behavioredClassifier_Operation_getAllImplementedInterfaces;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBehavioredClassifier_Operation_getImplementedInterfaces() const
{
	return m_behavioredClassifier_Operation_getImplementedInterfaces;
}

// End Class BehavioredClassifier

// Begin Class BroadcastSignalAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getBroadcastSignalAction_Class() const
{
	return m_broadcastSignalAction_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getBroadcastSignalAction_Attribute_signal() const
{
	return m_broadcastSignalAction_Attribute_signal;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBroadcastSignalAction_Operation_no_onport_EDiagnosticChain_EMap() const
{
	return m_broadcastSignalAction_Operation_no_onport_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBroadcastSignalAction_Operation_number_of_arguments_EDiagnosticChain_EMap() const
{
	return m_broadcastSignalAction_Operation_number_of_arguments_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getBroadcastSignalAction_Operation_type_ordering_multiplicity_EDiagnosticChain_EMap() const
{
	return m_broadcastSignalAction_Operation_type_ordering_multiplicity_EDiagnosticChain_EMap;
}

// End Class BroadcastSignalAction

// Begin Class CallAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getCallAction_Class() const
{
	return m_callAction_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getCallAction_Attribute_isSynchronous() const
{
	return m_callAction_Attribute_isSynchronous;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getCallAction_Attribute_result() const
{
	return m_callAction_Attribute_result;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCallAction_Operation_argument_pins_EDiagnosticChain_EMap() const
{
	return m_callAction_Operation_argument_pins_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCallAction_Operation_inputParameters() const
{
	return m_callAction_Operation_inputParameters;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCallAction_Operation_outputParameters() const
{
	return m_callAction_Operation_outputParameters;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCallAction_Operation_result_pins_EDiagnosticChain_EMap() const
{
	return m_callAction_Operation_result_pins_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCallAction_Operation_synchronous_call_EDiagnosticChain_EMap() const
{
	return m_callAction_Operation_synchronous_call_EDiagnosticChain_EMap;
}

// End Class CallAction

// Begin Class CallBehaviorAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getCallBehaviorAction_Class() const
{
	return m_callBehaviorAction_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getCallBehaviorAction_Attribute_behavior() const
{
	return m_callBehaviorAction_Attribute_behavior;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCallBehaviorAction_Operation_no_onport_EDiagnosticChain_EMap() const
{
	return m_callBehaviorAction_Operation_no_onport_EDiagnosticChain_EMap;
}

// End Class CallBehaviorAction

// Begin Class CallEvent
std::shared_ptr<ecore::EClass> UmlPackageImpl::getCallEvent_Class() const
{
	return m_callEvent_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getCallEvent_Attribute_operation() const
{
	return m_callEvent_Attribute_operation;
}


// End Class CallEvent

// Begin Class CallOperationAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getCallOperationAction_Class() const
{
	return m_callOperationAction_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getCallOperationAction_Attribute_operation() const
{
	return m_callOperationAction_Attribute_operation;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getCallOperationAction_Attribute_target() const
{
	return m_callOperationAction_Attribute_target;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCallOperationAction_Operation_type_target_pin_EDiagnosticChain_EMap() const
{
	return m_callOperationAction_Operation_type_target_pin_EDiagnosticChain_EMap;
}

// End Class CallOperationAction

// Begin Class CentralBufferNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getCentralBufferNode_Class() const
{
	return m_centralBufferNode_Class;
}




// End Class CentralBufferNode

// Begin Class ChangeEvent
std::shared_ptr<ecore::EClass> UmlPackageImpl::getChangeEvent_Class() const
{
	return m_changeEvent_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getChangeEvent_Attribute_changeExpression() const
{
	return m_changeEvent_Attribute_changeExpression;
}


// End Class ChangeEvent

// Begin Class Class
std::shared_ptr<ecore::EClass> UmlPackageImpl::getClass_Class() const
{
	return m_class_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getClass_Attribute_isActive() const
{
	return m_class_Attribute_isActive;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getClass_Attribute_extension() const
{
	return m_class_Attribute_extension;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClass_Attribute_nestedClassifier() const
{
	return m_class_Attribute_nestedClassifier;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClass_Attribute_ownedOperation() const
{
	return m_class_Attribute_ownedOperation;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClass_Attribute_ownedReception() const
{
	return m_class_Attribute_ownedReception;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClass_Attribute_superClass() const
{
	return m_class_Attribute_superClass;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClass_Operation_createOwnedOperation_String_Type() const
{
	return m_class_Operation_createOwnedOperation_String_Type;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClass_Operation_getExtensions() const
{
	return m_class_Operation_getExtensions;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClass_Operation_getSuperClasses() const
{
	return m_class_Operation_getSuperClasses;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClass_Operation_isMetaclass() const
{
	return m_class_Operation_isMetaclass;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClass_Operation_passive_class_EDiagnosticChain_EMap() const
{
	return m_class_Operation_passive_class_EDiagnosticChain_EMap;
}

// End Class Class

// Begin Class Classifier
std::shared_ptr<ecore::EClass> UmlPackageImpl::getClassifier_Class() const
{
	return m_classifier_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getClassifier_Attribute_isAbstract() const
{
	return m_classifier_Attribute_isAbstract;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getClassifier_Attribute_isFinalSpecialization() const
{
	return m_classifier_Attribute_isFinalSpecialization;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getClassifier_Attribute_attribute() const
{
	return m_classifier_Attribute_attribute;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClassifier_Attribute_collaborationUse() const
{
	return m_classifier_Attribute_collaborationUse;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClassifier_Attribute_feature() const
{
	return m_classifier_Attribute_feature;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClassifier_Attribute_general() const
{
	return m_classifier_Attribute_general;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClassifier_Attribute_generalization() const
{
	return m_classifier_Attribute_generalization;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClassifier_Attribute_inheritedMember() const
{
	return m_classifier_Attribute_inheritedMember;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClassifier_Attribute_ownedUseCase() const
{
	return m_classifier_Attribute_ownedUseCase;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClassifier_Attribute_powertypeExtent() const
{
	return m_classifier_Attribute_powertypeExtent;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClassifier_Attribute_redefinedClassifier() const
{
	return m_classifier_Attribute_redefinedClassifier;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClassifier_Attribute_representation() const
{
	return m_classifier_Attribute_representation;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClassifier_Attribute_substitution() const
{
	return m_classifier_Attribute_substitution;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClassifier_Attribute_useCase() const
{
	return m_classifier_Attribute_useCase;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_Operation_allAttributes() const
{
	return m_classifier_Operation_allAttributes;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_Operation_allFeatures() const
{
	return m_classifier_Operation_allFeatures;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_Operation_allParents() const
{
	return m_classifier_Operation_allParents;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_Operation_allRealizedInterfaces() const
{
	return m_classifier_Operation_allRealizedInterfaces;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_Operation_allSlottableFeatures() const
{
	return m_classifier_Operation_allSlottableFeatures;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_Operation_allUsedInterfaces() const
{
	return m_classifier_Operation_allUsedInterfaces;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_Operation_directlyRealizedInterfaces() const
{
	return m_classifier_Operation_directlyRealizedInterfaces;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_Operation_directlyUsedInterfaces() const
{
	return m_classifier_Operation_directlyUsedInterfaces;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_Operation_getAllAttributes() const
{
	return m_classifier_Operation_getAllAttributes;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_Operation_getAllOperations() const
{
	return m_classifier_Operation_getAllOperations;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_Operation_getAllUsedInterfaces() const
{
	return m_classifier_Operation_getAllUsedInterfaces;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_Operation_getGenerals() const
{
	return m_classifier_Operation_getGenerals;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_Operation_getInheritedMembers() const
{
	return m_classifier_Operation_getInheritedMembers;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_Operation_getOperation_String_Type() const
{
	return m_classifier_Operation_getOperation_String_Type;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_Operation_getOperation_String_Boolean() const
{
	return m_classifier_Operation_getOperation_String_Boolean;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_Operation_getOperations() const
{
	return m_classifier_Operation_getOperations;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_Operation_getUsedInterfaces() const
{
	return m_classifier_Operation_getUsedInterfaces;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_Operation_hasVisibilityOf_NamedElement() const
{
	return m_classifier_Operation_hasVisibilityOf_NamedElement;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_Operation_inherit_NamedElement() const
{
	return m_classifier_Operation_inherit_NamedElement;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_Operation_inheritableMembers_Classifier() const
{
	return m_classifier_Operation_inheritableMembers_Classifier;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_Operation_isSubstitutableFor_Classifier() const
{
	return m_classifier_Operation_isSubstitutableFor_Classifier;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_Operation_maps_to_generalization_set_EDiagnosticChain_EMap() const
{
	return m_classifier_Operation_maps_to_generalization_set_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_Operation_maySpecializeType_Classifier() const
{
	return m_classifier_Operation_maySpecializeType_Classifier;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_Operation_no_cycles_in_generalization_EDiagnosticChain_EMap() const
{
	return m_classifier_Operation_no_cycles_in_generalization_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_Operation_non_final_parents_EDiagnosticChain_EMap() const
{
	return m_classifier_Operation_non_final_parents_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_Operation_parents() const
{
	return m_classifier_Operation_parents;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifier_Operation_specialize_type_EDiagnosticChain_EMap() const
{
	return m_classifier_Operation_specialize_type_EDiagnosticChain_EMap;
}

// End Class Classifier

// Begin Class ClassifierTemplateParameter
std::shared_ptr<ecore::EClass> UmlPackageImpl::getClassifierTemplateParameter_Class() const
{
	return m_classifierTemplateParameter_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getClassifierTemplateParameter_Attribute_allowSubstitutable() const
{
	return m_classifierTemplateParameter_Attribute_allowSubstitutable;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getClassifierTemplateParameter_Attribute_constrainingClassifier() const
{
	return m_classifierTemplateParameter_Attribute_constrainingClassifier;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifierTemplateParameter_Operation_actual_is_classifier_EDiagnosticChain_EMap() const
{
	return m_classifierTemplateParameter_Operation_actual_is_classifier_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifierTemplateParameter_Operation_constraining_classifiers_constrain_args_EDiagnosticChain_EMap() const
{
	return m_classifierTemplateParameter_Operation_constraining_classifiers_constrain_args_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifierTemplateParameter_Operation_constraining_classifiers_constrain_parametered_element_EDiagnosticChain_EMap() const
{
	return m_classifierTemplateParameter_Operation_constraining_classifiers_constrain_parametered_element_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifierTemplateParameter_Operation_has_constraining_classifier_EDiagnosticChain_EMap() const
{
	return m_classifierTemplateParameter_Operation_has_constraining_classifier_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifierTemplateParameter_Operation_matching_abstract_EDiagnosticChain_EMap() const
{
	return m_classifierTemplateParameter_Operation_matching_abstract_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClassifierTemplateParameter_Operation_parametered_element_no_features_EDiagnosticChain_EMap() const
{
	return m_classifierTemplateParameter_Operation_parametered_element_no_features_EDiagnosticChain_EMap;
}

// End Class ClassifierTemplateParameter

// Begin Class Clause
std::shared_ptr<ecore::EClass> UmlPackageImpl::getClause_Class() const
{
	return m_clause_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getClause_Attribute_body() const
{
	return m_clause_Attribute_body;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClause_Attribute_bodyOutput() const
{
	return m_clause_Attribute_bodyOutput;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClause_Attribute_decider() const
{
	return m_clause_Attribute_decider;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClause_Attribute_predecessorClause() const
{
	return m_clause_Attribute_predecessorClause;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClause_Attribute_successorClause() const
{
	return m_clause_Attribute_successorClause;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClause_Attribute_test() const
{
	return m_clause_Attribute_test;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClause_Operation_body_output_pins_EDiagnosticChain_EMap() const
{
	return m_clause_Operation_body_output_pins_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClause_Operation_decider_output_EDiagnosticChain_EMap() const
{
	return m_clause_Operation_decider_output_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClause_Operation_test_and_body_EDiagnosticChain_EMap() const
{
	return m_clause_Operation_test_and_body_EDiagnosticChain_EMap;
}

// End Class Clause

// Begin Class ClearAssociationAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getClearAssociationAction_Class() const
{
	return m_clearAssociationAction_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getClearAssociationAction_Attribute_association() const
{
	return m_clearAssociationAction_Attribute_association;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getClearAssociationAction_Attribute_object() const
{
	return m_clearAssociationAction_Attribute_object;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClearAssociationAction_Operation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_clearAssociationAction_Operation_multiplicity_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClearAssociationAction_Operation_same_type_EDiagnosticChain_EMap() const
{
	return m_clearAssociationAction_Operation_same_type_EDiagnosticChain_EMap;
}

// End Class ClearAssociationAction

// Begin Class ClearStructuralFeatureAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getClearStructuralFeatureAction_Class() const
{
	return m_clearStructuralFeatureAction_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getClearStructuralFeatureAction_Attribute_result() const
{
	return m_clearStructuralFeatureAction_Attribute_result;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClearStructuralFeatureAction_Operation_multiplicity_of_result_EDiagnosticChain_EMap() const
{
	return m_clearStructuralFeatureAction_Operation_multiplicity_of_result_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getClearStructuralFeatureAction_Operation_type_of_result_EDiagnosticChain_EMap() const
{
	return m_clearStructuralFeatureAction_Operation_type_of_result_EDiagnosticChain_EMap;
}

// End Class ClearStructuralFeatureAction

// Begin Class ClearVariableAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getClearVariableAction_Class() const
{
	return m_clearVariableAction_Class;
}




// End Class ClearVariableAction

// Begin Class Collaboration
std::shared_ptr<ecore::EClass> UmlPackageImpl::getCollaboration_Class() const
{
	return m_collaboration_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getCollaboration_Attribute_collaborationRole() const
{
	return m_collaboration_Attribute_collaborationRole;
}


// End Class Collaboration

// Begin Class CollaborationUse
std::shared_ptr<ecore::EClass> UmlPackageImpl::getCollaborationUse_Class() const
{
	return m_collaborationUse_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getCollaborationUse_Attribute_roleBinding() const
{
	return m_collaborationUse_Attribute_roleBinding;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getCollaborationUse_Attribute_type() const
{
	return m_collaborationUse_Attribute_type;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCollaborationUse_Operation_client_elements_EDiagnosticChain_EMap() const
{
	return m_collaborationUse_Operation_client_elements_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCollaborationUse_Operation_connectors_EDiagnosticChain_EMap() const
{
	return m_collaborationUse_Operation_connectors_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCollaborationUse_Operation_every_role_EDiagnosticChain_EMap() const
{
	return m_collaborationUse_Operation_every_role_EDiagnosticChain_EMap;
}

// End Class CollaborationUse

// Begin Class CombinedFragment
std::shared_ptr<ecore::EClass> UmlPackageImpl::getCombinedFragment_Class() const
{
	return m_combinedFragment_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getCombinedFragment_Attribute_interactionOperator() const
{
	return m_combinedFragment_Attribute_interactionOperator;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getCombinedFragment_Attribute_cfragmentGate() const
{
	return m_combinedFragment_Attribute_cfragmentGate;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getCombinedFragment_Attribute_operand() const
{
	return m_combinedFragment_Attribute_operand;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCombinedFragment_Operation_break__EDiagnosticChain_EMap() const
{
	return m_combinedFragment_Operation_break__EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCombinedFragment_Operation_consider_and_ignore_EDiagnosticChain_EMap() const
{
	return m_combinedFragment_Operation_consider_and_ignore_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCombinedFragment_Operation_opt_loop_break_neg_EDiagnosticChain_EMap() const
{
	return m_combinedFragment_Operation_opt_loop_break_neg_EDiagnosticChain_EMap;
}

// End Class CombinedFragment

// Begin Class Comment
std::shared_ptr<ecore::EClass> UmlPackageImpl::getComment_Class() const
{
	return m_comment_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getComment_Attribute_body() const
{
	return m_comment_Attribute_body;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getComment_Attribute_annotatedElement() const
{
	return m_comment_Attribute_annotatedElement;
}


// End Class Comment

// Begin Class CommunicationPath
std::shared_ptr<ecore::EClass> UmlPackageImpl::getCommunicationPath_Class() const
{
	return m_communicationPath_Class;
}




// End Class CommunicationPath

// Begin Class Component
std::shared_ptr<ecore::EClass> UmlPackageImpl::getComponent_Class() const
{
	return m_component_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getComponent_Attribute_isIndirectlyInstantiated() const
{
	return m_component_Attribute_isIndirectlyInstantiated;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getComponent_Attribute_packagedElement() const
{
	return m_component_Attribute_packagedElement;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getComponent_Attribute_provided() const
{
	return m_component_Attribute_provided;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getComponent_Attribute_realization() const
{
	return m_component_Attribute_realization;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getComponent_Attribute_required() const
{
	return m_component_Attribute_required;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getComponent_Operation_createOwnedClass_String_Boolean() const
{
	return m_component_Operation_createOwnedClass_String_Boolean;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getComponent_Operation_createOwnedEnumeration_String() const
{
	return m_component_Operation_createOwnedEnumeration_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getComponent_Operation_createOwnedInterface_String() const
{
	return m_component_Operation_createOwnedInterface_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getComponent_Operation_createOwnedPrimitiveType_String() const
{
	return m_component_Operation_createOwnedPrimitiveType_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getComponent_Operation_getProvideds() const
{
	return m_component_Operation_getProvideds;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getComponent_Operation_getRequireds() const
{
	return m_component_Operation_getRequireds;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getComponent_Operation_no_nested_classifiers_EDiagnosticChain_EMap() const
{
	return m_component_Operation_no_nested_classifiers_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getComponent_Operation_no_packaged_elements_EDiagnosticChain_EMap() const
{
	return m_component_Operation_no_packaged_elements_EDiagnosticChain_EMap;
}

// End Class Component

// Begin Class ComponentRealization
std::shared_ptr<ecore::EClass> UmlPackageImpl::getComponentRealization_Class() const
{
	return m_componentRealization_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getComponentRealization_Attribute_abstraction() const
{
	return m_componentRealization_Attribute_abstraction;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getComponentRealization_Attribute_realizingClassifier() const
{
	return m_componentRealization_Attribute_realizingClassifier;
}


// End Class ComponentRealization

// Begin Class ConditionalNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getConditionalNode_Class() const
{
	return m_conditionalNode_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getConditionalNode_Attribute_isAssured() const
{
	return m_conditionalNode_Attribute_isAssured;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getConditionalNode_Attribute_isDeterminate() const
{
	return m_conditionalNode_Attribute_isDeterminate;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getConditionalNode_Attribute_clause() const
{
	return m_conditionalNode_Attribute_clause;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getConditionalNode_Attribute_result() const
{
	return m_conditionalNode_Attribute_result;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConditionalNode_Operation_clause_no_predecessor_EDiagnosticChain_EMap() const
{
	return m_conditionalNode_Operation_clause_no_predecessor_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConditionalNode_Operation_executable_nodes_EDiagnosticChain_EMap() const
{
	return m_conditionalNode_Operation_executable_nodes_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConditionalNode_Operation_matching_output_pins_EDiagnosticChain_EMap() const
{
	return m_conditionalNode_Operation_matching_output_pins_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConditionalNode_Operation_no_input_pins_EDiagnosticChain_EMap() const
{
	return m_conditionalNode_Operation_no_input_pins_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConditionalNode_Operation_one_clause_with_executable_node_EDiagnosticChain_EMap() const
{
	return m_conditionalNode_Operation_one_clause_with_executable_node_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConditionalNode_Operation_result_no_incoming_EDiagnosticChain_EMap() const
{
	return m_conditionalNode_Operation_result_no_incoming_EDiagnosticChain_EMap;
}

// End Class ConditionalNode

// Begin Class ConnectableElement
std::shared_ptr<ecore::EClass> UmlPackageImpl::getConnectableElement_Class() const
{
	return m_connectableElement_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getConnectableElement_Attribute_end() const
{
	return m_connectableElement_Attribute_end;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConnectableElement_Operation_getEnds() const
{
	return m_connectableElement_Operation_getEnds;
}

// End Class ConnectableElement

// Begin Class ConnectableElementTemplateParameter
std::shared_ptr<ecore::EClass> UmlPackageImpl::getConnectableElementTemplateParameter_Class() const
{
	return m_connectableElementTemplateParameter_Class;
}




// End Class ConnectableElementTemplateParameter

// Begin Class ConnectionPointReference
std::shared_ptr<ecore::EClass> UmlPackageImpl::getConnectionPointReference_Class() const
{
	return m_connectionPointReference_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getConnectionPointReference_Attribute_entry() const
{
	return m_connectionPointReference_Attribute_entry;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getConnectionPointReference_Attribute_exit() const
{
	return m_connectionPointReference_Attribute_exit;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getConnectionPointReference_Attribute_state() const
{
	return m_connectionPointReference_Attribute_state;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConnectionPointReference_Operation_entry_pseudostates_EDiagnosticChain_EMap() const
{
	return m_connectionPointReference_Operation_entry_pseudostates_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConnectionPointReference_Operation_exit_pseudostates_EDiagnosticChain_EMap() const
{
	return m_connectionPointReference_Operation_exit_pseudostates_EDiagnosticChain_EMap;
}

// End Class ConnectionPointReference

// Begin Class Connector
std::shared_ptr<ecore::EClass> UmlPackageImpl::getConnector_Class() const
{
	return m_connector_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getConnector_Attribute_kind() const
{
	return m_connector_Attribute_kind;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getConnector_Attribute_contract() const
{
	return m_connector_Attribute_contract;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getConnector_Attribute_end() const
{
	return m_connector_Attribute_end;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getConnector_Attribute_redefinedConnector() const
{
	return m_connector_Attribute_redefinedConnector;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getConnector_Attribute_type() const
{
	return m_connector_Attribute_type;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConnector_Operation_getKind() const
{
	return m_connector_Operation_getKind;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConnector_Operation_roles_EDiagnosticChain_EMap() const
{
	return m_connector_Operation_roles_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConnector_Operation_types_EDiagnosticChain_EMap() const
{
	return m_connector_Operation_types_EDiagnosticChain_EMap;
}

// End Class Connector

// Begin Class ConnectorEnd
std::shared_ptr<ecore::EClass> UmlPackageImpl::getConnectorEnd_Class() const
{
	return m_connectorEnd_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getConnectorEnd_Attribute_definingEnd() const
{
	return m_connectorEnd_Attribute_definingEnd;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getConnectorEnd_Attribute_partWithPort() const
{
	return m_connectorEnd_Attribute_partWithPort;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getConnectorEnd_Attribute_role() const
{
	return m_connectorEnd_Attribute_role;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConnectorEnd_Operation_getDefiningEnd() const
{
	return m_connectorEnd_Operation_getDefiningEnd;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConnectorEnd_Operation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_connectorEnd_Operation_multiplicity_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConnectorEnd_Operation_part_with_port_empty_EDiagnosticChain_EMap() const
{
	return m_connectorEnd_Operation_part_with_port_empty_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConnectorEnd_Operation_role_and_part_with_port_EDiagnosticChain_EMap() const
{
	return m_connectorEnd_Operation_role_and_part_with_port_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConnectorEnd_Operation_self_part_with_port_EDiagnosticChain_EMap() const
{
	return m_connectorEnd_Operation_self_part_with_port_EDiagnosticChain_EMap;
}

// End Class ConnectorEnd

// Begin Class ConsiderIgnoreFragment
std::shared_ptr<ecore::EClass> UmlPackageImpl::getConsiderIgnoreFragment_Class() const
{
	return m_considerIgnoreFragment_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getConsiderIgnoreFragment_Attribute_message() const
{
	return m_considerIgnoreFragment_Attribute_message;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConsiderIgnoreFragment_Operation_consider_or_ignore_EDiagnosticChain_EMap() const
{
	return m_considerIgnoreFragment_Operation_consider_or_ignore_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConsiderIgnoreFragment_Operation_type_EDiagnosticChain_EMap() const
{
	return m_considerIgnoreFragment_Operation_type_EDiagnosticChain_EMap;
}

// End Class ConsiderIgnoreFragment

// Begin Class Constraint
std::shared_ptr<ecore::EClass> UmlPackageImpl::getConstraint_Class() const
{
	return m_constraint_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getConstraint_Attribute_constrainedElement() const
{
	return m_constraint_Attribute_constrainedElement;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getConstraint_Attribute_context() const
{
	return m_constraint_Attribute_context;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getConstraint_Attribute_specification() const
{
	return m_constraint_Attribute_specification;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConstraint_Operation_boolean_value_EDiagnosticChain_EMap() const
{
	return m_constraint_Operation_boolean_value_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConstraint_Operation_no_side_effects_EDiagnosticChain_EMap() const
{
	return m_constraint_Operation_no_side_effects_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getConstraint_Operation_not_apply_to_self_EDiagnosticChain_EMap() const
{
	return m_constraint_Operation_not_apply_to_self_EDiagnosticChain_EMap;
}

// End Class Constraint

// Begin Class Continuation
std::shared_ptr<ecore::EClass> UmlPackageImpl::getContinuation_Class() const
{
	return m_continuation_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getContinuation_Attribute_setting() const
{
	return m_continuation_Attribute_setting;
}


std::shared_ptr<ecore::EOperation> UmlPackageImpl::getContinuation_Operation_first_or_last_interaction_fragment_EDiagnosticChain_EMap() const
{
	return m_continuation_Operation_first_or_last_interaction_fragment_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getContinuation_Operation_global_EDiagnosticChain_EMap() const
{
	return m_continuation_Operation_global_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getContinuation_Operation_same_name_EDiagnosticChain_EMap() const
{
	return m_continuation_Operation_same_name_EDiagnosticChain_EMap;
}

// End Class Continuation

// Begin Class ControlFlow
std::shared_ptr<ecore::EClass> UmlPackageImpl::getControlFlow_Class() const
{
	return m_controlFlow_Class;
}



std::shared_ptr<ecore::EOperation> UmlPackageImpl::getControlFlow_Operation_object_nodes_EDiagnosticChain_EMap() const
{
	return m_controlFlow_Operation_object_nodes_EDiagnosticChain_EMap;
}

// End Class ControlFlow

// Begin Class ControlNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getControlNode_Class() const
{
	return m_controlNode_Class;
}




// End Class ControlNode

// Begin Class CreateLinkAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getCreateLinkAction_Class() const
{
	return m_createLinkAction_Class;
}



std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCreateLinkAction_Operation_association_not_abstract_EDiagnosticChain_EMap() const
{
	return m_createLinkAction_Operation_association_not_abstract_EDiagnosticChain_EMap;
}

// End Class CreateLinkAction

// Begin Class CreateLinkObjectAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getCreateLinkObjectAction_Class() const
{
	return m_createLinkObjectAction_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getCreateLinkObjectAction_Attribute_result() const
{
	return m_createLinkObjectAction_Attribute_result;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCreateLinkObjectAction_Operation_association_class_EDiagnosticChain_EMap() const
{
	return m_createLinkObjectAction_Operation_association_class_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCreateLinkObjectAction_Operation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_createLinkObjectAction_Operation_multiplicity_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCreateLinkObjectAction_Operation_type_of_result_EDiagnosticChain_EMap() const
{
	return m_createLinkObjectAction_Operation_type_of_result_EDiagnosticChain_EMap;
}

// End Class CreateLinkObjectAction

// Begin Class CreateObjectAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getCreateObjectAction_Class() const
{
	return m_createObjectAction_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getCreateObjectAction_Attribute_classifier() const
{
	return m_createObjectAction_Attribute_classifier;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getCreateObjectAction_Attribute_result() const
{
	return m_createObjectAction_Attribute_result;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCreateObjectAction_Operation_classifier_not_abstract_EDiagnosticChain_EMap() const
{
	return m_createObjectAction_Operation_classifier_not_abstract_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCreateObjectAction_Operation_classifier_not_association_class_EDiagnosticChain_EMap() const
{
	return m_createObjectAction_Operation_classifier_not_association_class_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCreateObjectAction_Operation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_createObjectAction_Operation_multiplicity_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getCreateObjectAction_Operation_same_type_EDiagnosticChain_EMap() const
{
	return m_createObjectAction_Operation_same_type_EDiagnosticChain_EMap;
}

// End Class CreateObjectAction

// Begin Class DataStoreNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDataStoreNode_Class() const
{
	return m_dataStoreNode_Class;
}




// End Class DataStoreNode

// Begin Class DataType
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDataType_Class() const
{
	return m_dataType_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getDataType_Attribute_ownedAttribute() const
{
	return m_dataType_Attribute_ownedAttribute;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getDataType_Attribute_ownedOperation() const
{
	return m_dataType_Attribute_ownedOperation;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDataType_Operation_createOwnedAttribute_String_UnlimitedNatural() const
{
	return m_dataType_Operation_createOwnedAttribute_String_UnlimitedNatural;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDataType_Operation_createOwnedOperation_String_Type() const
{
	return m_dataType_Operation_createOwnedOperation_String_Type;
}

// End Class DataType

// Begin Class DecisionNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDecisionNode_Class() const
{
	return m_decisionNode_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getDecisionNode_Attribute_decisionInput() const
{
	return m_decisionNode_Attribute_decisionInput;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getDecisionNode_Attribute_decisionInputFlow() const
{
	return m_decisionNode_Attribute_decisionInputFlow;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDecisionNode_Operation_decision_input_flow_incoming_EDiagnosticChain_EMap() const
{
	return m_decisionNode_Operation_decision_input_flow_incoming_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDecisionNode_Operation_edges_EDiagnosticChain_EMap() const
{
	return m_decisionNode_Operation_edges_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDecisionNode_Operation_incoming_control_one_input_parameter_EDiagnosticChain_EMap() const
{
	return m_decisionNode_Operation_incoming_control_one_input_parameter_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDecisionNode_Operation_incoming_object_one_input_parameter_EDiagnosticChain_EMap() const
{
	return m_decisionNode_Operation_incoming_object_one_input_parameter_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDecisionNode_Operation_incoming_outgoing_edges_EDiagnosticChain_EMap() const
{
	return m_decisionNode_Operation_incoming_outgoing_edges_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDecisionNode_Operation_parameters_EDiagnosticChain_EMap() const
{
	return m_decisionNode_Operation_parameters_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDecisionNode_Operation_two_input_parameters_EDiagnosticChain_EMap() const
{
	return m_decisionNode_Operation_two_input_parameters_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDecisionNode_Operation_zero_input_parameters_EDiagnosticChain_EMap() const
{
	return m_decisionNode_Operation_zero_input_parameters_EDiagnosticChain_EMap;
}

// End Class DecisionNode

// Begin Class Dependency
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDependency_Class() const
{
	return m_dependency_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getDependency_Attribute_client() const
{
	return m_dependency_Attribute_client;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getDependency_Attribute_supplier() const
{
	return m_dependency_Attribute_supplier;
}


// End Class Dependency

// Begin Class DeployedArtifact
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDeployedArtifact_Class() const
{
	return m_deployedArtifact_Class;
}




// End Class DeployedArtifact

// Begin Class Deployment
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDeployment_Class() const
{
	return m_deployment_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getDeployment_Attribute_configuration() const
{
	return m_deployment_Attribute_configuration;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getDeployment_Attribute_deployedArtifact() const
{
	return m_deployment_Attribute_deployedArtifact;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getDeployment_Attribute_location() const
{
	return m_deployment_Attribute_location;
}


// End Class Deployment

// Begin Class DeploymentSpecification
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDeploymentSpecification_Class() const
{
	return m_deploymentSpecification_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getDeploymentSpecification_Attribute_deploymentLocation() const
{
	return m_deploymentSpecification_Attribute_deploymentLocation;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getDeploymentSpecification_Attribute_executionLocation() const
{
	return m_deploymentSpecification_Attribute_executionLocation;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getDeploymentSpecification_Attribute_deployment() const
{
	return m_deploymentSpecification_Attribute_deployment;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDeploymentSpecification_Operation_deployed_elements_EDiagnosticChain_EMap() const
{
	return m_deploymentSpecification_Operation_deployed_elements_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDeploymentSpecification_Operation_deployment_target_EDiagnosticChain_EMap() const
{
	return m_deploymentSpecification_Operation_deployment_target_EDiagnosticChain_EMap;
}

// End Class DeploymentSpecification

// Begin Class DeploymentTarget
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDeploymentTarget_Class() const
{
	return m_deploymentTarget_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getDeploymentTarget_Attribute_deployedElement() const
{
	return m_deploymentTarget_Attribute_deployedElement;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getDeploymentTarget_Attribute_deployment() const
{
	return m_deploymentTarget_Attribute_deployment;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDeploymentTarget_Operation_getDeployedElements() const
{
	return m_deploymentTarget_Operation_getDeployedElements;
}

// End Class DeploymentTarget

// Begin Class DestroyLinkAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDestroyLinkAction_Class() const
{
	return m_destroyLinkAction_Class;
}




// End Class DestroyLinkAction

// Begin Class DestroyObjectAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDestroyObjectAction_Class() const
{
	return m_destroyObjectAction_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getDestroyObjectAction_Attribute_isDestroyLinks() const
{
	return m_destroyObjectAction_Attribute_isDestroyLinks;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getDestroyObjectAction_Attribute_isDestroyOwnedObjects() const
{
	return m_destroyObjectAction_Attribute_isDestroyOwnedObjects;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getDestroyObjectAction_Attribute_target() const
{
	return m_destroyObjectAction_Attribute_target;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDestroyObjectAction_Operation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_destroyObjectAction_Operation_multiplicity_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDestroyObjectAction_Operation_no_type_EDiagnosticChain_EMap() const
{
	return m_destroyObjectAction_Operation_no_type_EDiagnosticChain_EMap;
}

// End Class DestroyObjectAction

// Begin Class DestructionOccurrenceSpecification
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDestructionOccurrenceSpecification_Class() const
{
	return m_destructionOccurrenceSpecification_Class;
}



std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDestructionOccurrenceSpecification_Operation_no_occurrence_specifications_below_EDiagnosticChain_EMap() const
{
	return m_destructionOccurrenceSpecification_Operation_no_occurrence_specifications_below_EDiagnosticChain_EMap;
}

// End Class DestructionOccurrenceSpecification

// Begin Class Device
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDevice_Class() const
{
	return m_device_Class;
}




// End Class Device

// Begin Class DirectedRelationship
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDirectedRelationship_Class() const
{
	return m_directedRelationship_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getDirectedRelationship_Attribute_source() const
{
	return m_directedRelationship_Attribute_source;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getDirectedRelationship_Attribute_target() const
{
	return m_directedRelationship_Attribute_target;
}


// End Class DirectedRelationship

// Begin Class Duration
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDuration_Class() const
{
	return m_duration_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getDuration_Attribute_expr() const
{
	return m_duration_Attribute_expr;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getDuration_Attribute_observation() const
{
	return m_duration_Attribute_observation;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDuration_Operation_no_expr_requires_observation_EDiagnosticChain_EMap() const
{
	return m_duration_Operation_no_expr_requires_observation_EDiagnosticChain_EMap;
}

// End Class Duration

// Begin Class DurationConstraint
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDurationConstraint_Class() const
{
	return m_durationConstraint_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getDurationConstraint_Attribute_firstEvent() const
{
	return m_durationConstraint_Attribute_firstEvent;
}


std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDurationConstraint_Operation_first_event_multiplicity_EDiagnosticChain_EMap() const
{
	return m_durationConstraint_Operation_first_event_multiplicity_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDurationConstraint_Operation_has_one_or_two_constrainedElements_EDiagnosticChain_EMap() const
{
	return m_durationConstraint_Operation_has_one_or_two_constrainedElements_EDiagnosticChain_EMap;
}

// End Class DurationConstraint

// Begin Class DurationInterval
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDurationInterval_Class() const
{
	return m_durationInterval_Class;
}




// End Class DurationInterval

// Begin Class DurationObservation
std::shared_ptr<ecore::EClass> UmlPackageImpl::getDurationObservation_Class() const
{
	return m_durationObservation_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getDurationObservation_Attribute_firstEvent() const
{
	return m_durationObservation_Attribute_firstEvent;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getDurationObservation_Attribute_event() const
{
	return m_durationObservation_Attribute_event;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getDurationObservation_Operation_first_event_multiplicity_EDiagnosticChain_EMap() const
{
	return m_durationObservation_Operation_first_event_multiplicity_EDiagnosticChain_EMap;
}

// End Class DurationObservation

// Begin Class Element
std::shared_ptr<ecore::EClass> UmlPackageImpl::getElement_Class() const
{
	return m_element_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getElement_Attribute_ownedComment() const
{
	return m_element_Attribute_ownedComment;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getElement_Attribute_ownedElement() const
{
	return m_element_Attribute_ownedElement;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getElement_Attribute_owner() const
{
	return m_element_Attribute_owner;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_Operation_addKeyword_String() const
{
	return m_element_Operation_addKeyword_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_Operation_allOwnedElements() const
{
	return m_element_Operation_allOwnedElements;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_Operation_applyStereotype_Stereotype() const
{
	return m_element_Operation_applyStereotype_Stereotype;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_Operation_container() const
{
	return m_element_Operation_container;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_Operation_createEAnnotation_String() const
{
	return m_element_Operation_createEAnnotation_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_Operation_destroy() const
{
	return m_element_Operation_destroy;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_Operation_getApplicableStereotype_String() const
{
	return m_element_Operation_getApplicableStereotype_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_Operation_getApplicableStereotypes() const
{
	return m_element_Operation_getApplicableStereotypes;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_Operation_getAppliedStereotype_String() const
{
	return m_element_Operation_getAppliedStereotype_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_Operation_getAppliedStereotypes() const
{
	return m_element_Operation_getAppliedStereotypes;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_Operation_getAppliedSubstereotype_Stereotype_String() const
{
	return m_element_Operation_getAppliedSubstereotype_Stereotype_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_Operation_getAppliedSubstereotypes_Stereotype() const
{
	return m_element_Operation_getAppliedSubstereotypes_Stereotype;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_Operation_getKeywords() const
{
	return m_element_Operation_getKeywords;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_Operation_getMetaClass() const
{
	return m_element_Operation_getMetaClass;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_Operation_getModel() const
{
	return m_element_Operation_getModel;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_Operation_getNearestPackage() const
{
	return m_element_Operation_getNearestPackage;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_Operation_getRelationships() const
{
	return m_element_Operation_getRelationships;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_Operation_getRelationships_EClass() const
{
	return m_element_Operation_getRelationships_EClass;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_Operation_getRequiredStereotype_String() const
{
	return m_element_Operation_getRequiredStereotype_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_Operation_getRequiredStereotypes() const
{
	return m_element_Operation_getRequiredStereotypes;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_Operation_getSourceDirectedRelationships() const
{
	return m_element_Operation_getSourceDirectedRelationships;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_Operation_getSourceDirectedRelationships_EClass() const
{
	return m_element_Operation_getSourceDirectedRelationships_EClass;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_Operation_getStereotypeApplication_Stereotype() const
{
	return m_element_Operation_getStereotypeApplication_Stereotype;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_Operation_getStereotypeApplications() const
{
	return m_element_Operation_getStereotypeApplications;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_Operation_getTargetDirectedRelationships() const
{
	return m_element_Operation_getTargetDirectedRelationships;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_Operation_getTargetDirectedRelationships_EClass() const
{
	return m_element_Operation_getTargetDirectedRelationships_EClass;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_Operation_getValue_Stereotype_String() const
{
	return m_element_Operation_getValue_Stereotype_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_Operation_hasKeyword_String() const
{
	return m_element_Operation_hasKeyword_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_Operation_hasValue_Stereotype_String() const
{
	return m_element_Operation_hasValue_Stereotype_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_Operation_has_owner_EDiagnosticChain_EMap() const
{
	return m_element_Operation_has_owner_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_Operation_isStereotypeApplicable_Stereotype() const
{
	return m_element_Operation_isStereotypeApplicable_Stereotype;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_Operation_isStereotypeApplied_Stereotype() const
{
	return m_element_Operation_isStereotypeApplied_Stereotype;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_Operation_isStereotypeRequired_Stereotype() const
{
	return m_element_Operation_isStereotypeRequired_Stereotype;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_Operation_mustBeOwned() const
{
	return m_element_Operation_mustBeOwned;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_Operation_not_own_self_EDiagnosticChain_EMap() const
{
	return m_element_Operation_not_own_self_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_Operation_removeKeyword_String() const
{
	return m_element_Operation_removeKeyword_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_Operation_setValue_Stereotype_EJavaObject() const
{
	return m_element_Operation_setValue_Stereotype_EJavaObject;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElement_Operation_unapplyStereotype_Stereotype() const
{
	return m_element_Operation_unapplyStereotype_Stereotype;
}

// End Class Element

// Begin Class ElementImport
std::shared_ptr<ecore::EClass> UmlPackageImpl::getElementImport_Class() const
{
	return m_elementImport_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getElementImport_Attribute_alias() const
{
	return m_elementImport_Attribute_alias;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getElementImport_Attribute_visibility() const
{
	return m_elementImport_Attribute_visibility;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getElementImport_Attribute_importedElement() const
{
	return m_elementImport_Attribute_importedElement;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getElementImport_Attribute_importingNamespace() const
{
	return m_elementImport_Attribute_importingNamespace;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElementImport_Operation_getName() const
{
	return m_elementImport_Operation_getName;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElementImport_Operation_imported_element_is_public_EDiagnosticChain_EMap() const
{
	return m_elementImport_Operation_imported_element_is_public_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getElementImport_Operation_visibility_public_or_private_EDiagnosticChain_EMap() const
{
	return m_elementImport_Operation_visibility_public_or_private_EDiagnosticChain_EMap;
}

// End Class ElementImport

// Begin Class EncapsulatedClassifier
std::shared_ptr<ecore::EClass> UmlPackageImpl::getEncapsulatedClassifier_Class() const
{
	return m_encapsulatedClassifier_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getEncapsulatedClassifier_Attribute_ownedPort() const
{
	return m_encapsulatedClassifier_Attribute_ownedPort;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getEncapsulatedClassifier_Operation_getOwnedPorts() const
{
	return m_encapsulatedClassifier_Operation_getOwnedPorts;
}

// End Class EncapsulatedClassifier

// Begin Class Enumeration
std::shared_ptr<ecore::EClass> UmlPackageImpl::getEnumeration_Class() const
{
	return m_enumeration_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getEnumeration_Attribute_ownedLiteral() const
{
	return m_enumeration_Attribute_ownedLiteral;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getEnumeration_Operation_immutable_EDiagnosticChain_EMap() const
{
	return m_enumeration_Operation_immutable_EDiagnosticChain_EMap;
}

// End Class Enumeration

// Begin Class EnumerationLiteral
std::shared_ptr<ecore::EClass> UmlPackageImpl::getEnumerationLiteral_Class() const
{
	return m_enumerationLiteral_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getEnumerationLiteral_Attribute_enumeration() const
{
	return m_enumerationLiteral_Attribute_enumeration;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getEnumerationLiteral_Operation_getClassifier() const
{
	return m_enumerationLiteral_Operation_getClassifier;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getEnumerationLiteral_Operation_getClassifiers() const
{
	return m_enumerationLiteral_Operation_getClassifiers;
}

// End Class EnumerationLiteral

// Begin Class Event
std::shared_ptr<ecore::EClass> UmlPackageImpl::getEvent_Class() const
{
	return m_event_Class;
}




// End Class Event

// Begin Class ExceptionHandler
std::shared_ptr<ecore::EClass> UmlPackageImpl::getExceptionHandler_Class() const
{
	return m_exceptionHandler_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getExceptionHandler_Attribute_exceptionInput() const
{
	return m_exceptionHandler_Attribute_exceptionInput;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getExceptionHandler_Attribute_exceptionType() const
{
	return m_exceptionHandler_Attribute_exceptionType;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getExceptionHandler_Attribute_handlerBody() const
{
	return m_exceptionHandler_Attribute_handlerBody;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getExceptionHandler_Attribute_protectedNode() const
{
	return m_exceptionHandler_Attribute_protectedNode;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExceptionHandler_Operation_edge_source_target_EDiagnosticChain_EMap() const
{
	return m_exceptionHandler_Operation_edge_source_target_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExceptionHandler_Operation_exception_input_type_EDiagnosticChain_EMap() const
{
	return m_exceptionHandler_Operation_exception_input_type_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExceptionHandler_Operation_handler_body_edges_EDiagnosticChain_EMap() const
{
	return m_exceptionHandler_Operation_handler_body_edges_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExceptionHandler_Operation_handler_body_owner_EDiagnosticChain_EMap() const
{
	return m_exceptionHandler_Operation_handler_body_owner_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExceptionHandler_Operation_one_input_EDiagnosticChain_EMap() const
{
	return m_exceptionHandler_Operation_one_input_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExceptionHandler_Operation_output_pins_EDiagnosticChain_EMap() const
{
	return m_exceptionHandler_Operation_output_pins_EDiagnosticChain_EMap;
}

// End Class ExceptionHandler

// Begin Class ExecutableNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getExecutableNode_Class() const
{
	return m_executableNode_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getExecutableNode_Attribute_handler() const
{
	return m_executableNode_Attribute_handler;
}


// End Class ExecutableNode

// Begin Class ExecutionEnvironment
std::shared_ptr<ecore::EClass> UmlPackageImpl::getExecutionEnvironment_Class() const
{
	return m_executionEnvironment_Class;
}




// End Class ExecutionEnvironment

// Begin Class ExecutionOccurrenceSpecification
std::shared_ptr<ecore::EClass> UmlPackageImpl::getExecutionOccurrenceSpecification_Class() const
{
	return m_executionOccurrenceSpecification_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getExecutionOccurrenceSpecification_Attribute_execution() const
{
	return m_executionOccurrenceSpecification_Attribute_execution;
}


// End Class ExecutionOccurrenceSpecification

// Begin Class ExecutionSpecification
std::shared_ptr<ecore::EClass> UmlPackageImpl::getExecutionSpecification_Class() const
{
	return m_executionSpecification_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getExecutionSpecification_Attribute_finish() const
{
	return m_executionSpecification_Attribute_finish;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getExecutionSpecification_Attribute_start() const
{
	return m_executionSpecification_Attribute_start;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExecutionSpecification_Operation_same_lifeline_EDiagnosticChain_EMap() const
{
	return m_executionSpecification_Operation_same_lifeline_EDiagnosticChain_EMap;
}

// End Class ExecutionSpecification

// Begin Class ExpansionNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getExpansionNode_Class() const
{
	return m_expansionNode_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getExpansionNode_Attribute_regionAsInput() const
{
	return m_expansionNode_Attribute_regionAsInput;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getExpansionNode_Attribute_regionAsOutput() const
{
	return m_expansionNode_Attribute_regionAsOutput;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExpansionNode_Operation_region_as_input_or_output_EDiagnosticChain_EMap() const
{
	return m_expansionNode_Operation_region_as_input_or_output_EDiagnosticChain_EMap;
}

// End Class ExpansionNode

// Begin Class ExpansionRegion
std::shared_ptr<ecore::EClass> UmlPackageImpl::getExpansionRegion_Class() const
{
	return m_expansionRegion_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getExpansionRegion_Attribute_mode() const
{
	return m_expansionRegion_Attribute_mode;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getExpansionRegion_Attribute_inputElement() const
{
	return m_expansionRegion_Attribute_inputElement;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getExpansionRegion_Attribute_outputElement() const
{
	return m_expansionRegion_Attribute_outputElement;
}


// End Class ExpansionRegion

// Begin Class Expression
std::shared_ptr<ecore::EClass> UmlPackageImpl::getExpression_Class() const
{
	return m_expression_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getExpression_Attribute_symbol() const
{
	return m_expression_Attribute_symbol;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getExpression_Attribute_operand() const
{
	return m_expression_Attribute_operand;
}


// End Class Expression

// Begin Class Extend
std::shared_ptr<ecore::EClass> UmlPackageImpl::getExtend_Class() const
{
	return m_extend_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getExtend_Attribute_condition() const
{
	return m_extend_Attribute_condition;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getExtend_Attribute_extendedCase() const
{
	return m_extend_Attribute_extendedCase;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getExtend_Attribute_extension() const
{
	return m_extend_Attribute_extension;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getExtend_Attribute_extensionLocation() const
{
	return m_extend_Attribute_extensionLocation;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExtend_Operation_extension_points_EDiagnosticChain_EMap() const
{
	return m_extend_Operation_extension_points_EDiagnosticChain_EMap;
}

// End Class Extend

// Begin Class Extension
std::shared_ptr<ecore::EClass> UmlPackageImpl::getExtension_Class() const
{
	return m_extension_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getExtension_Attribute_isRequired() const
{
	return m_extension_Attribute_isRequired;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getExtension_Attribute_metaclass() const
{
	return m_extension_Attribute_metaclass;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExtension_Operation_getMetaclass() const
{
	return m_extension_Operation_getMetaclass;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExtension_Operation_getStereotype() const
{
	return m_extension_Operation_getStereotype;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExtension_Operation_getStereotypeEnd() const
{
	return m_extension_Operation_getStereotypeEnd;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExtension_Operation_isRequired() const
{
	return m_extension_Operation_isRequired;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExtension_Operation_is_binary_EDiagnosticChain_EMap() const
{
	return m_extension_Operation_is_binary_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExtension_Operation_metaclassEnd() const
{
	return m_extension_Operation_metaclassEnd;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExtension_Operation_non_owned_end_EDiagnosticChain_EMap() const
{
	return m_extension_Operation_non_owned_end_EDiagnosticChain_EMap;
}

// End Class Extension

// Begin Class ExtensionEnd
std::shared_ptr<ecore::EClass> UmlPackageImpl::getExtensionEnd_Class() const
{
	return m_extensionEnd_Class;
}



std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExtensionEnd_Operation_aggregation_EDiagnosticChain_EMap() const
{
	return m_extensionEnd_Operation_aggregation_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExtensionEnd_Operation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_extensionEnd_Operation_multiplicity_EDiagnosticChain_EMap;
}

// End Class ExtensionEnd

// Begin Class ExtensionPoint
std::shared_ptr<ecore::EClass> UmlPackageImpl::getExtensionPoint_Class() const
{
	return m_extensionPoint_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getExtensionPoint_Attribute_useCase() const
{
	return m_extensionPoint_Attribute_useCase;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getExtensionPoint_Operation_must_have_name_EDiagnosticChain_EMap() const
{
	return m_extensionPoint_Operation_must_have_name_EDiagnosticChain_EMap;
}

// End Class ExtensionPoint

// Begin Class Factory
std::shared_ptr<ecore::EClass> UmlPackageImpl::getFactory_Class() const
{
	return m_factory_Class;
}



std::shared_ptr<ecore::EOperation> UmlPackageImpl::getFactory_Operation_create_Class() const
{
	return m_factory_Operation_create_Class;
}

// End Class Factory

// Begin Class Feature
std::shared_ptr<ecore::EClass> UmlPackageImpl::getFeature_Class() const
{
	return m_feature_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getFeature_Attribute_isStatic() const
{
	return m_feature_Attribute_isStatic;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getFeature_Attribute_featuringClassifier() const
{
	return m_feature_Attribute_featuringClassifier;
}


// End Class Feature

// Begin Class FinalNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getFinalNode_Class() const
{
	return m_finalNode_Class;
}



std::shared_ptr<ecore::EOperation> UmlPackageImpl::getFinalNode_Operation_no_outgoing_edges_EDiagnosticChain_EMap() const
{
	return m_finalNode_Operation_no_outgoing_edges_EDiagnosticChain_EMap;
}

// End Class FinalNode

// Begin Class FinalState
std::shared_ptr<ecore::EClass> UmlPackageImpl::getFinalState_Class() const
{
	return m_finalState_Class;
}



std::shared_ptr<ecore::EOperation> UmlPackageImpl::getFinalState_Operation_cannot_reference_submachine_EDiagnosticChain_EMap() const
{
	return m_finalState_Operation_cannot_reference_submachine_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getFinalState_Operation_no_entry_behavior_EDiagnosticChain_EMap() const
{
	return m_finalState_Operation_no_entry_behavior_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getFinalState_Operation_no_exit_behavior_EDiagnosticChain_EMap() const
{
	return m_finalState_Operation_no_exit_behavior_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getFinalState_Operation_no_outgoing_transitions_EDiagnosticChain_EMap() const
{
	return m_finalState_Operation_no_outgoing_transitions_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getFinalState_Operation_no_regions_EDiagnosticChain_EMap() const
{
	return m_finalState_Operation_no_regions_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getFinalState_Operation_no_state_behavior_EDiagnosticChain_EMap() const
{
	return m_finalState_Operation_no_state_behavior_EDiagnosticChain_EMap;
}

// End Class FinalState

// Begin Class FlowFinalNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getFlowFinalNode_Class() const
{
	return m_flowFinalNode_Class;
}




// End Class FlowFinalNode

// Begin Class ForkNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getForkNode_Class() const
{
	return m_forkNode_Class;
}



std::shared_ptr<ecore::EOperation> UmlPackageImpl::getForkNode_Operation_edges_EDiagnosticChain_EMap() const
{
	return m_forkNode_Operation_edges_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getForkNode_Operation_one_incoming_edge_EDiagnosticChain_EMap() const
{
	return m_forkNode_Operation_one_incoming_edge_EDiagnosticChain_EMap;
}

// End Class ForkNode

// Begin Class FunctionBehavior
std::shared_ptr<ecore::EClass> UmlPackageImpl::getFunctionBehavior_Class() const
{
	return m_functionBehavior_Class;
}



std::shared_ptr<ecore::EOperation> UmlPackageImpl::getFunctionBehavior_Operation_hasAllDataTypeAttributes_DataType() const
{
	return m_functionBehavior_Operation_hasAllDataTypeAttributes_DataType;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getFunctionBehavior_Operation_one_output_parameter_EDiagnosticChain_EMap() const
{
	return m_functionBehavior_Operation_one_output_parameter_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getFunctionBehavior_Operation_types_of_parameters_EDiagnosticChain_EMap() const
{
	return m_functionBehavior_Operation_types_of_parameters_EDiagnosticChain_EMap;
}

// End Class FunctionBehavior

// Begin Class Gate
std::shared_ptr<ecore::EClass> UmlPackageImpl::getGate_Class() const
{
	return m_gate_Class;
}



std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate_Operation_actual_gate_distinguishable_EDiagnosticChain_EMap() const
{
	return m_gate_Operation_actual_gate_distinguishable_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate_Operation_actual_gate_matched_EDiagnosticChain_EMap() const
{
	return m_gate_Operation_actual_gate_matched_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate_Operation_formal_gate_distinguishable_EDiagnosticChain_EMap() const
{
	return m_gate_Operation_formal_gate_distinguishable_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate_Operation_getName() const
{
	return m_gate_Operation_getName;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate_Operation_getOperand() const
{
	return m_gate_Operation_getOperand;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate_Operation_inside_cf_gate_distinguishable_EDiagnosticChain_EMap() const
{
	return m_gate_Operation_inside_cf_gate_distinguishable_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate_Operation_inside_cf_matched_EDiagnosticChain_EMap() const
{
	return m_gate_Operation_inside_cf_matched_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate_Operation_isActual() const
{
	return m_gate_Operation_isActual;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate_Operation_isFormal() const
{
	return m_gate_Operation_isFormal;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate_Operation_isInsideCF() const
{
	return m_gate_Operation_isInsideCF;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate_Operation_isOutsideCF() const
{
	return m_gate_Operation_isOutsideCF;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate_Operation_matches_Gate() const
{
	return m_gate_Operation_matches_Gate;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate_Operation_outside_cf_gate_distinguishable_EDiagnosticChain_EMap() const
{
	return m_gate_Operation_outside_cf_gate_distinguishable_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGate_Operation_outside_cf_matched_EDiagnosticChain_EMap() const
{
	return m_gate_Operation_outside_cf_matched_EDiagnosticChain_EMap;
}

// End Class Gate

// Begin Class GeneralOrdering
std::shared_ptr<ecore::EClass> UmlPackageImpl::getGeneralOrdering_Class() const
{
	return m_generalOrdering_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getGeneralOrdering_Attribute_after() const
{
	return m_generalOrdering_Attribute_after;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getGeneralOrdering_Attribute_before() const
{
	return m_generalOrdering_Attribute_before;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGeneralOrdering_Operation_irreflexive_transitive_closure_EDiagnosticChain_EMap() const
{
	return m_generalOrdering_Operation_irreflexive_transitive_closure_EDiagnosticChain_EMap;
}

// End Class GeneralOrdering

// Begin Class Generalization
std::shared_ptr<ecore::EClass> UmlPackageImpl::getGeneralization_Class() const
{
	return m_generalization_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getGeneralization_Attribute_isSubstitutable() const
{
	return m_generalization_Attribute_isSubstitutable;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getGeneralization_Attribute_general() const
{
	return m_generalization_Attribute_general;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getGeneralization_Attribute_generalizationSet() const
{
	return m_generalization_Attribute_generalizationSet;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getGeneralization_Attribute_specific() const
{
	return m_generalization_Attribute_specific;
}


// End Class Generalization

// Begin Class GeneralizationSet
std::shared_ptr<ecore::EClass> UmlPackageImpl::getGeneralizationSet_Class() const
{
	return m_generalizationSet_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getGeneralizationSet_Attribute_isCovering() const
{
	return m_generalizationSet_Attribute_isCovering;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getGeneralizationSet_Attribute_isDisjoint() const
{
	return m_generalizationSet_Attribute_isDisjoint;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getGeneralizationSet_Attribute_generalization() const
{
	return m_generalizationSet_Attribute_generalization;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getGeneralizationSet_Attribute_powertype() const
{
	return m_generalizationSet_Attribute_powertype;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGeneralizationSet_Operation_generalization_same_classifier_EDiagnosticChain_EMap() const
{
	return m_generalizationSet_Operation_generalization_same_classifier_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getGeneralizationSet_Operation_maps_to_generalization_set_EDiagnosticChain_EMap() const
{
	return m_generalizationSet_Operation_maps_to_generalization_set_EDiagnosticChain_EMap;
}

// End Class GeneralizationSet

// Begin Class Image
std::shared_ptr<ecore::EClass> UmlPackageImpl::getImage_Class() const
{
	return m_image_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getImage_Attribute_content() const
{
	return m_image_Attribute_content;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getImage_Attribute_format() const
{
	return m_image_Attribute_format;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getImage_Attribute_location() const
{
	return m_image_Attribute_location;
}



// End Class Image

// Begin Class Include
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInclude_Class() const
{
	return m_include_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getInclude_Attribute_addition() const
{
	return m_include_Attribute_addition;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInclude_Attribute_includingCase() const
{
	return m_include_Attribute_includingCase;
}


// End Class Include

// Begin Class InformationFlow
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInformationFlow_Class() const
{
	return m_informationFlow_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getInformationFlow_Attribute_conveyed() const
{
	return m_informationFlow_Attribute_conveyed;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInformationFlow_Attribute_informationSource() const
{
	return m_informationFlow_Attribute_informationSource;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInformationFlow_Attribute_informationTarget() const
{
	return m_informationFlow_Attribute_informationTarget;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInformationFlow_Attribute_realization() const
{
	return m_informationFlow_Attribute_realization;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInformationFlow_Attribute_realizingActivityEdge() const
{
	return m_informationFlow_Attribute_realizingActivityEdge;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInformationFlow_Attribute_realizingConnector() const
{
	return m_informationFlow_Attribute_realizingConnector;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInformationFlow_Attribute_realizingMessage() const
{
	return m_informationFlow_Attribute_realizingMessage;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInformationFlow_Operation_convey_classifiers_EDiagnosticChain_EMap() const
{
	return m_informationFlow_Operation_convey_classifiers_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInformationFlow_Operation_must_conform_EDiagnosticChain_EMap() const
{
	return m_informationFlow_Operation_must_conform_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInformationFlow_Operation_sources_and_targets_kind_EDiagnosticChain_EMap() const
{
	return m_informationFlow_Operation_sources_and_targets_kind_EDiagnosticChain_EMap;
}

// End Class InformationFlow

// Begin Class InformationItem
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInformationItem_Class() const
{
	return m_informationItem_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getInformationItem_Attribute_represented() const
{
	return m_informationItem_Attribute_represented;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInformationItem_Operation_has_no_EDiagnosticChain_EMap() const
{
	return m_informationItem_Operation_has_no_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInformationItem_Operation_not_instantiable_EDiagnosticChain_EMap() const
{
	return m_informationItem_Operation_not_instantiable_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInformationItem_Operation_sources_and_targets_EDiagnosticChain_EMap() const
{
	return m_informationItem_Operation_sources_and_targets_EDiagnosticChain_EMap;
}

// End Class InformationItem

// Begin Class InitialNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInitialNode_Class() const
{
	return m_initialNode_Class;
}



std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInitialNode_Operation_control_edges_EDiagnosticChain_EMap() const
{
	return m_initialNode_Operation_control_edges_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInitialNode_Operation_no_incoming_edges_EDiagnosticChain_EMap() const
{
	return m_initialNode_Operation_no_incoming_edges_EDiagnosticChain_EMap;
}

// End Class InitialNode

// Begin Class InputPin
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInputPin_Class() const
{
	return m_inputPin_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getInputPin_Attribute_action() const
{
	return m_inputPin_Attribute_action;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInputPin_Attribute_callOperationAction() const
{
	return m_inputPin_Attribute_callOperationAction;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInputPin_Attribute_invocationAction() const
{
	return m_inputPin_Attribute_invocationAction;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInputPin_Attribute_structuralFeatureAction() const
{
	return m_inputPin_Attribute_structuralFeatureAction;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInputPin_Operation_outgoing_edges_structured_only_EDiagnosticChain_EMap() const
{
	return m_inputPin_Operation_outgoing_edges_structured_only_EDiagnosticChain_EMap;
}

// End Class InputPin

// Begin Class InstanceSpecification
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInstanceSpecification_Class() const
{
	return m_instanceSpecification_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getInstanceSpecification_Attribute_classifier() const
{
	return m_instanceSpecification_Attribute_classifier;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInstanceSpecification_Attribute_slot() const
{
	return m_instanceSpecification_Attribute_slot;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInstanceSpecification_Attribute_specification() const
{
	return m_instanceSpecification_Attribute_specification;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInstanceSpecification_Operation_defining_feature_EDiagnosticChain_EMap() const
{
	return m_instanceSpecification_Operation_defining_feature_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInstanceSpecification_Operation_deployment_artifact_EDiagnosticChain_EMap() const
{
	return m_instanceSpecification_Operation_deployment_artifact_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInstanceSpecification_Operation_deployment_target_EDiagnosticChain_EMap() const
{
	return m_instanceSpecification_Operation_deployment_target_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInstanceSpecification_Operation_structural_feature_EDiagnosticChain_EMap() const
{
	return m_instanceSpecification_Operation_structural_feature_EDiagnosticChain_EMap;
}

// End Class InstanceSpecification

// Begin Class InstanceValue
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInstanceValue_Class() const
{
	return m_instanceValue_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getInstanceValue_Attribute_instance() const
{
	return m_instanceValue_Attribute_instance;
}


// End Class InstanceValue

// Begin Class Interaction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInteraction_Class() const
{
	return m_interaction_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteraction_Attribute_action() const
{
	return m_interaction_Attribute_action;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteraction_Attribute_formalGate() const
{
	return m_interaction_Attribute_formalGate;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteraction_Attribute_fragment() const
{
	return m_interaction_Attribute_fragment;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteraction_Attribute_lifeline() const
{
	return m_interaction_Attribute_lifeline;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteraction_Attribute_message() const
{
	return m_interaction_Attribute_message;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteraction_Operation_not_contained_EDiagnosticChain_EMap() const
{
	return m_interaction_Operation_not_contained_EDiagnosticChain_EMap;
}

// End Class Interaction

// Begin Class InteractionConstraint
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInteractionConstraint_Class() const
{
	return m_interactionConstraint_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteractionConstraint_Attribute_maxint() const
{
	return m_interactionConstraint_Attribute_maxint;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteractionConstraint_Attribute_minint() const
{
	return m_interactionConstraint_Attribute_minint;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionConstraint_Operation_dynamic_variables_EDiagnosticChain_EMap() const
{
	return m_interactionConstraint_Operation_dynamic_variables_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionConstraint_Operation_global_data_EDiagnosticChain_EMap() const
{
	return m_interactionConstraint_Operation_global_data_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionConstraint_Operation_maxint_greater_equal_minint_EDiagnosticChain_EMap() const
{
	return m_interactionConstraint_Operation_maxint_greater_equal_minint_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionConstraint_Operation_maxint_positive_EDiagnosticChain_EMap() const
{
	return m_interactionConstraint_Operation_maxint_positive_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionConstraint_Operation_minint_maxint_EDiagnosticChain_EMap() const
{
	return m_interactionConstraint_Operation_minint_maxint_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionConstraint_Operation_minint_non_negative_EDiagnosticChain_EMap() const
{
	return m_interactionConstraint_Operation_minint_non_negative_EDiagnosticChain_EMap;
}

// End Class InteractionConstraint

// Begin Class InteractionFragment
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInteractionFragment_Class() const
{
	return m_interactionFragment_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteractionFragment_Attribute_covered() const
{
	return m_interactionFragment_Attribute_covered;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteractionFragment_Attribute_enclosingInteraction() const
{
	return m_interactionFragment_Attribute_enclosingInteraction;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteractionFragment_Attribute_enclosingOperand() const
{
	return m_interactionFragment_Attribute_enclosingOperand;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteractionFragment_Attribute_generalOrdering() const
{
	return m_interactionFragment_Attribute_generalOrdering;
}


// End Class InteractionFragment

// Begin Class InteractionOperand
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInteractionOperand_Class() const
{
	return m_interactionOperand_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteractionOperand_Attribute_fragment() const
{
	return m_interactionOperand_Attribute_fragment;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteractionOperand_Attribute_guard() const
{
	return m_interactionOperand_Attribute_guard;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionOperand_Operation_guard_contain_references_EDiagnosticChain_EMap() const
{
	return m_interactionOperand_Operation_guard_contain_references_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionOperand_Operation_guard_directly_prior_EDiagnosticChain_EMap() const
{
	return m_interactionOperand_Operation_guard_directly_prior_EDiagnosticChain_EMap;
}

// End Class InteractionOperand

// Begin Class InteractionUse
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInteractionUse_Class() const
{
	return m_interactionUse_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteractionUse_Attribute_actualGate() const
{
	return m_interactionUse_Attribute_actualGate;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteractionUse_Attribute_argument() const
{
	return m_interactionUse_Attribute_argument;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteractionUse_Attribute_refersTo() const
{
	return m_interactionUse_Attribute_refersTo;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteractionUse_Attribute_returnValue() const
{
	return m_interactionUse_Attribute_returnValue;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInteractionUse_Attribute_returnValueRecipient() const
{
	return m_interactionUse_Attribute_returnValueRecipient;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionUse_Operation_all_lifelines_EDiagnosticChain_EMap() const
{
	return m_interactionUse_Operation_all_lifelines_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionUse_Operation_arguments_are_constants_EDiagnosticChain_EMap() const
{
	return m_interactionUse_Operation_arguments_are_constants_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionUse_Operation_arguments_correspond_to_parameters_EDiagnosticChain_EMap() const
{
	return m_interactionUse_Operation_arguments_correspond_to_parameters_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionUse_Operation_gates_match_EDiagnosticChain_EMap() const
{
	return m_interactionUse_Operation_gates_match_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionUse_Operation_returnValueRecipient_coverage_EDiagnosticChain_EMap() const
{
	return m_interactionUse_Operation_returnValueRecipient_coverage_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInteractionUse_Operation_returnValue_type_recipient_correspondence_EDiagnosticChain_EMap() const
{
	return m_interactionUse_Operation_returnValue_type_recipient_correspondence_EDiagnosticChain_EMap;
}

// End Class InteractionUse

// Begin Class Interface
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInterface_Class() const
{
	return m_interface_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getInterface_Attribute_nestedClassifier() const
{
	return m_interface_Attribute_nestedClassifier;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInterface_Attribute_ownedAttribute() const
{
	return m_interface_Attribute_ownedAttribute;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInterface_Attribute_ownedOperation() const
{
	return m_interface_Attribute_ownedOperation;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInterface_Attribute_ownedReception() const
{
	return m_interface_Attribute_ownedReception;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInterface_Attribute_protocol() const
{
	return m_interface_Attribute_protocol;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInterface_Attribute_redefinedInterface() const
{
	return m_interface_Attribute_redefinedInterface;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInterface_Operation_createOwnedAttribute_String_UnlimitedNatural() const
{
	return m_interface_Operation_createOwnedAttribute_String_UnlimitedNatural;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInterface_Operation_createOwnedOperation_String_Type() const
{
	return m_interface_Operation_createOwnedOperation_String_Type;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInterface_Operation_visibility_EDiagnosticChain_EMap() const
{
	return m_interface_Operation_visibility_EDiagnosticChain_EMap;
}

// End Class Interface

// Begin Class InterfaceRealization
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInterfaceRealization_Class() const
{
	return m_interfaceRealization_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getInterfaceRealization_Attribute_contract() const
{
	return m_interfaceRealization_Attribute_contract;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInterfaceRealization_Attribute_implementingClassifier() const
{
	return m_interfaceRealization_Attribute_implementingClassifier;
}


// End Class InterfaceRealization

// Begin Class InterruptibleActivityRegion
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInterruptibleActivityRegion_Class() const
{
	return m_interruptibleActivityRegion_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getInterruptibleActivityRegion_Attribute_interruptingEdge() const
{
	return m_interruptibleActivityRegion_Attribute_interruptingEdge;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInterruptibleActivityRegion_Attribute_node() const
{
	return m_interruptibleActivityRegion_Attribute_node;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getInterruptibleActivityRegion_Operation_interrupting_edges_EDiagnosticChain_EMap() const
{
	return m_interruptibleActivityRegion_Operation_interrupting_edges_EDiagnosticChain_EMap;
}

// End Class InterruptibleActivityRegion

// Begin Class Interval
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInterval_Class() const
{
	return m_interval_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getInterval_Attribute_max() const
{
	return m_interval_Attribute_max;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInterval_Attribute_min() const
{
	return m_interval_Attribute_min;
}


// End Class Interval

// Begin Class IntervalConstraint
std::shared_ptr<ecore::EClass> UmlPackageImpl::getIntervalConstraint_Class() const
{
	return m_intervalConstraint_Class;
}




// End Class IntervalConstraint

// Begin Class InvocationAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getInvocationAction_Class() const
{
	return m_invocationAction_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getInvocationAction_Attribute_argument() const
{
	return m_invocationAction_Attribute_argument;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getInvocationAction_Attribute_onPort() const
{
	return m_invocationAction_Attribute_onPort;
}


// End Class InvocationAction

// Begin Class JoinNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getJoinNode_Class() const
{
	return m_joinNode_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getJoinNode_Attribute_isCombineDuplicate() const
{
	return m_joinNode_Attribute_isCombineDuplicate;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getJoinNode_Attribute_joinSpec() const
{
	return m_joinNode_Attribute_joinSpec;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getJoinNode_Operation_incoming_object_flow_EDiagnosticChain_EMap() const
{
	return m_joinNode_Operation_incoming_object_flow_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getJoinNode_Operation_one_outgoing_edge_EDiagnosticChain_EMap() const
{
	return m_joinNode_Operation_one_outgoing_edge_EDiagnosticChain_EMap;
}

// End Class JoinNode

// Begin Class Lifeline
std::shared_ptr<ecore::EClass> UmlPackageImpl::getLifeline_Class() const
{
	return m_lifeline_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getLifeline_Attribute_coveredBy() const
{
	return m_lifeline_Attribute_coveredBy;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLifeline_Attribute_decomposedAs() const
{
	return m_lifeline_Attribute_decomposedAs;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLifeline_Attribute_interaction() const
{
	return m_lifeline_Attribute_interaction;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLifeline_Attribute_represents() const
{
	return m_lifeline_Attribute_represents;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLifeline_Attribute_selector() const
{
	return m_lifeline_Attribute_selector;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLifeline_Operation_interaction_uses_share_lifeline_EDiagnosticChain_EMap() const
{
	return m_lifeline_Operation_interaction_uses_share_lifeline_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLifeline_Operation_same_classifier_EDiagnosticChain_EMap() const
{
	return m_lifeline_Operation_same_classifier_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLifeline_Operation_selector_int_or_string_EDiagnosticChain_EMap() const
{
	return m_lifeline_Operation_selector_int_or_string_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLifeline_Operation_selector_specified_EDiagnosticChain_EMap() const
{
	return m_lifeline_Operation_selector_specified_EDiagnosticChain_EMap;
}

// End Class Lifeline

// Begin Class LinkAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getLinkAction_Class() const
{
	return m_linkAction_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getLinkAction_Attribute_endData() const
{
	return m_linkAction_Attribute_endData;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLinkAction_Attribute_inputValue() const
{
	return m_linkAction_Attribute_inputValue;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLinkAction_Operation_association() const
{
	return m_linkAction_Operation_association;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLinkAction_Operation_not_static_EDiagnosticChain_EMap() const
{
	return m_linkAction_Operation_not_static_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLinkAction_Operation_same_association_EDiagnosticChain_EMap() const
{
	return m_linkAction_Operation_same_association_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLinkAction_Operation_same_pins_EDiagnosticChain_EMap() const
{
	return m_linkAction_Operation_same_pins_EDiagnosticChain_EMap;
}

// End Class LinkAction

// Begin Class LinkEndCreationData
std::shared_ptr<ecore::EClass> UmlPackageImpl::getLinkEndCreationData_Class() const
{
	return m_linkEndCreationData_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getLinkEndCreationData_Attribute_isReplaceAll() const
{
	return m_linkEndCreationData_Attribute_isReplaceAll;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getLinkEndCreationData_Attribute_insertAt() const
{
	return m_linkEndCreationData_Attribute_insertAt;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLinkEndCreationData_Operation_insertAt_pin_EDiagnosticChain_EMap() const
{
	return m_linkEndCreationData_Operation_insertAt_pin_EDiagnosticChain_EMap;
}

// End Class LinkEndCreationData

// Begin Class LinkEndData
std::shared_ptr<ecore::EClass> UmlPackageImpl::getLinkEndData_Class() const
{
	return m_linkEndData_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getLinkEndData_Attribute_end() const
{
	return m_linkEndData_Attribute_end;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLinkEndData_Attribute_qualifier() const
{
	return m_linkEndData_Attribute_qualifier;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLinkEndData_Attribute_value() const
{
	return m_linkEndData_Attribute_value;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLinkEndData_Operation_allPins() const
{
	return m_linkEndData_Operation_allPins;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLinkEndData_Operation_end_object_input_pin_EDiagnosticChain_EMap() const
{
	return m_linkEndData_Operation_end_object_input_pin_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLinkEndData_Operation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_linkEndData_Operation_multiplicity_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLinkEndData_Operation_property_is_association_end_EDiagnosticChain_EMap() const
{
	return m_linkEndData_Operation_property_is_association_end_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLinkEndData_Operation_qualifiers_EDiagnosticChain_EMap() const
{
	return m_linkEndData_Operation_qualifiers_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLinkEndData_Operation_same_type_EDiagnosticChain_EMap() const
{
	return m_linkEndData_Operation_same_type_EDiagnosticChain_EMap;
}

// End Class LinkEndData

// Begin Class LinkEndDestructionData
std::shared_ptr<ecore::EClass> UmlPackageImpl::getLinkEndDestructionData_Class() const
{
	return m_linkEndDestructionData_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getLinkEndDestructionData_Attribute_isDestroyDuplicates() const
{
	return m_linkEndDestructionData_Attribute_isDestroyDuplicates;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getLinkEndDestructionData_Attribute_destroyAt() const
{
	return m_linkEndDestructionData_Attribute_destroyAt;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLinkEndDestructionData_Operation_destroyAt_pin_EDiagnosticChain_EMap() const
{
	return m_linkEndDestructionData_Operation_destroyAt_pin_EDiagnosticChain_EMap;
}

// End Class LinkEndDestructionData

// Begin Class LiteralBoolean
std::shared_ptr<ecore::EClass> UmlPackageImpl::getLiteralBoolean_Class() const
{
	return m_literalBoolean_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getLiteralBoolean_Attribute_value() const
{
	return m_literalBoolean_Attribute_value;
}



// End Class LiteralBoolean

// Begin Class LiteralInteger
std::shared_ptr<ecore::EClass> UmlPackageImpl::getLiteralInteger_Class() const
{
	return m_literalInteger_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getLiteralInteger_Attribute_value() const
{
	return m_literalInteger_Attribute_value;
}



// End Class LiteralInteger

// Begin Class LiteralNull
std::shared_ptr<ecore::EClass> UmlPackageImpl::getLiteralNull_Class() const
{
	return m_literalNull_Class;
}




// End Class LiteralNull

// Begin Class LiteralReal
std::shared_ptr<ecore::EClass> UmlPackageImpl::getLiteralReal_Class() const
{
	return m_literalReal_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getLiteralReal_Attribute_value() const
{
	return m_literalReal_Attribute_value;
}



// End Class LiteralReal

// Begin Class LiteralSpecification
std::shared_ptr<ecore::EClass> UmlPackageImpl::getLiteralSpecification_Class() const
{
	return m_literalSpecification_Class;
}




// End Class LiteralSpecification

// Begin Class LiteralString
std::shared_ptr<ecore::EClass> UmlPackageImpl::getLiteralString_Class() const
{
	return m_literalString_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getLiteralString_Attribute_value() const
{
	return m_literalString_Attribute_value;
}



// End Class LiteralString

// Begin Class LiteralUnlimitedNatural
std::shared_ptr<ecore::EClass> UmlPackageImpl::getLiteralUnlimitedNatural_Class() const
{
	return m_literalUnlimitedNatural_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getLiteralUnlimitedNatural_Attribute_value() const
{
	return m_literalUnlimitedNatural_Attribute_value;
}



// End Class LiteralUnlimitedNatural

// Begin Class LoopNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getLoopNode_Class() const
{
	return m_loopNode_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getLoopNode_Attribute_isTestedFirst() const
{
	return m_loopNode_Attribute_isTestedFirst;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getLoopNode_Attribute_bodyOutput() const
{
	return m_loopNode_Attribute_bodyOutput;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLoopNode_Attribute_bodyPart() const
{
	return m_loopNode_Attribute_bodyPart;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLoopNode_Attribute_decider() const
{
	return m_loopNode_Attribute_decider;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLoopNode_Attribute_loopVariable() const
{
	return m_loopNode_Attribute_loopVariable;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLoopNode_Attribute_loopVariableInput() const
{
	return m_loopNode_Attribute_loopVariableInput;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLoopNode_Attribute_result() const
{
	return m_loopNode_Attribute_result;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLoopNode_Attribute_setupPart() const
{
	return m_loopNode_Attribute_setupPart;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getLoopNode_Attribute_test() const
{
	return m_loopNode_Attribute_test;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLoopNode_Operation_body_output_pins_EDiagnosticChain_EMap() const
{
	return m_loopNode_Operation_body_output_pins_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLoopNode_Operation_executable_nodes_EDiagnosticChain_EMap() const
{
	return m_loopNode_Operation_executable_nodes_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLoopNode_Operation_input_edges_EDiagnosticChain_EMap() const
{
	return m_loopNode_Operation_input_edges_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLoopNode_Operation_loop_variable_outgoing_EDiagnosticChain_EMap() const
{
	return m_loopNode_Operation_loop_variable_outgoing_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLoopNode_Operation_matching_loop_variables_EDiagnosticChain_EMap() const
{
	return m_loopNode_Operation_matching_loop_variables_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLoopNode_Operation_matching_output_pins_EDiagnosticChain_EMap() const
{
	return m_loopNode_Operation_matching_output_pins_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLoopNode_Operation_matching_result_pins_EDiagnosticChain_EMap() const
{
	return m_loopNode_Operation_matching_result_pins_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLoopNode_Operation_result_no_incoming_EDiagnosticChain_EMap() const
{
	return m_loopNode_Operation_result_no_incoming_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getLoopNode_Operation_setup_test_and_body_EDiagnosticChain_EMap() const
{
	return m_loopNode_Operation_setup_test_and_body_EDiagnosticChain_EMap;
}

// End Class LoopNode

// Begin Class Manifestation
std::shared_ptr<ecore::EClass> UmlPackageImpl::getManifestation_Class() const
{
	return m_manifestation_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getManifestation_Attribute_utilizedElement() const
{
	return m_manifestation_Attribute_utilizedElement;
}


// End Class Manifestation

// Begin Class MergeNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getMergeNode_Class() const
{
	return m_mergeNode_Class;
}



std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMergeNode_Operation_edges_EDiagnosticChain_EMap() const
{
	return m_mergeNode_Operation_edges_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMergeNode_Operation_one_outgoing_edge_EDiagnosticChain_EMap() const
{
	return m_mergeNode_Operation_one_outgoing_edge_EDiagnosticChain_EMap;
}

// End Class MergeNode

// Begin Class Message
std::shared_ptr<ecore::EClass> UmlPackageImpl::getMessage_Class() const
{
	return m_message_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getMessage_Attribute_messageKind() const
{
	return m_message_Attribute_messageKind;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getMessage_Attribute_messageSort() const
{
	return m_message_Attribute_messageSort;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getMessage_Attribute_argument() const
{
	return m_message_Attribute_argument;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getMessage_Attribute_connector() const
{
	return m_message_Attribute_connector;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getMessage_Attribute_interaction() const
{
	return m_message_Attribute_interaction;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getMessage_Attribute_receiveEvent() const
{
	return m_message_Attribute_receiveEvent;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getMessage_Attribute_sendEvent() const
{
	return m_message_Attribute_sendEvent;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getMessage_Attribute_signature() const
{
	return m_message_Attribute_signature;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMessage_Operation_arguments_EDiagnosticChain_EMap() const
{
	return m_message_Operation_arguments_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMessage_Operation_cannot_cross_boundaries_EDiagnosticChain_EMap() const
{
	return m_message_Operation_cannot_cross_boundaries_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMessage_Operation_getMessageKind() const
{
	return m_message_Operation_getMessageKind;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMessage_Operation_occurrence_specifications_EDiagnosticChain_EMap() const
{
	return m_message_Operation_occurrence_specifications_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMessage_Operation_sending_receiving_message_event_EDiagnosticChain_EMap() const
{
	return m_message_Operation_sending_receiving_message_event_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMessage_Operation_signature_is_operation_reply_EDiagnosticChain_EMap() const
{
	return m_message_Operation_signature_is_operation_reply_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMessage_Operation_signature_is_operation_request_EDiagnosticChain_EMap() const
{
	return m_message_Operation_signature_is_operation_request_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMessage_Operation_signature_is_signal_EDiagnosticChain_EMap() const
{
	return m_message_Operation_signature_is_signal_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMessage_Operation_signature_refer_to_EDiagnosticChain_EMap() const
{
	return m_message_Operation_signature_refer_to_EDiagnosticChain_EMap;
}

// End Class Message

// Begin Class MessageEnd
std::shared_ptr<ecore::EClass> UmlPackageImpl::getMessageEnd_Class() const
{
	return m_messageEnd_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getMessageEnd_Attribute_message() const
{
	return m_messageEnd_Attribute_message;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMessageEnd_Operation_enclosingFragment() const
{
	return m_messageEnd_Operation_enclosingFragment;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMessageEnd_Operation_isReceive() const
{
	return m_messageEnd_Operation_isReceive;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMessageEnd_Operation_isSend() const
{
	return m_messageEnd_Operation_isSend;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMessageEnd_Operation_oppositeEnd() const
{
	return m_messageEnd_Operation_oppositeEnd;
}

// End Class MessageEnd

// Begin Class MessageEvent
std::shared_ptr<ecore::EClass> UmlPackageImpl::getMessageEvent_Class() const
{
	return m_messageEvent_Class;
}




// End Class MessageEvent

// Begin Class MessageOccurrenceSpecification
std::shared_ptr<ecore::EClass> UmlPackageImpl::getMessageOccurrenceSpecification_Class() const
{
	return m_messageOccurrenceSpecification_Class;
}




// End Class MessageOccurrenceSpecification

// Begin Class Model
std::shared_ptr<ecore::EClass> UmlPackageImpl::getModel_Class() const
{
	return m_model_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getModel_Attribute_viewpoint() const
{
	return m_model_Attribute_viewpoint;
}


std::shared_ptr<ecore::EOperation> UmlPackageImpl::getModel_Operation_isMetamodel() const
{
	return m_model_Operation_isMetamodel;
}

// End Class Model

// Begin Class MultiplicityElement
std::shared_ptr<ecore::EClass> UmlPackageImpl::getMultiplicityElement_Class() const
{
	return m_multiplicityElement_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getMultiplicityElement_Attribute_isOrdered() const
{
	return m_multiplicityElement_Attribute_isOrdered;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getMultiplicityElement_Attribute_isUnique() const
{
	return m_multiplicityElement_Attribute_isUnique;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getMultiplicityElement_Attribute_lower() const
{
	return m_multiplicityElement_Attribute_lower;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getMultiplicityElement_Attribute_upper() const
{
	return m_multiplicityElement_Attribute_upper;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getMultiplicityElement_Attribute_lowerValue() const
{
	return m_multiplicityElement_Attribute_lowerValue;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getMultiplicityElement_Attribute_upperValue() const
{
	return m_multiplicityElement_Attribute_upperValue;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMultiplicityElement_Operation_compatibleWith_MultiplicityElement() const
{
	return m_multiplicityElement_Operation_compatibleWith_MultiplicityElement;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMultiplicityElement_Operation_includesMultiplicity_MultiplicityElement() const
{
	return m_multiplicityElement_Operation_includesMultiplicity_MultiplicityElement;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMultiplicityElement_Operation_is_Integer_UnlimitedNatural() const
{
	return m_multiplicityElement_Operation_is_Integer_UnlimitedNatural;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMultiplicityElement_Operation_isMultivalued() const
{
	return m_multiplicityElement_Operation_isMultivalued;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMultiplicityElement_Operation_lowerBound() const
{
	return m_multiplicityElement_Operation_lowerBound;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMultiplicityElement_Operation_lower_ge_0_EDiagnosticChain_EMap() const
{
	return m_multiplicityElement_Operation_lower_ge_0_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMultiplicityElement_Operation_lower_is_integer_EDiagnosticChain_EMap() const
{
	return m_multiplicityElement_Operation_lower_is_integer_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMultiplicityElement_Operation_upperBound() const
{
	return m_multiplicityElement_Operation_upperBound;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMultiplicityElement_Operation_upper_ge_lower_EDiagnosticChain_EMap() const
{
	return m_multiplicityElement_Operation_upper_ge_lower_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMultiplicityElement_Operation_upper_is_unlimitedNatural_EDiagnosticChain_EMap() const
{
	return m_multiplicityElement_Operation_upper_is_unlimitedNatural_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMultiplicityElement_Operation_value_specification_constant_EDiagnosticChain_EMap() const
{
	return m_multiplicityElement_Operation_value_specification_constant_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getMultiplicityElement_Operation_value_specification_no_side_effects_EDiagnosticChain_EMap() const
{
	return m_multiplicityElement_Operation_value_specification_no_side_effects_EDiagnosticChain_EMap;
}

// End Class MultiplicityElement

// Begin Class NamedElement
std::shared_ptr<ecore::EClass> UmlPackageImpl::getNamedElement_Class() const
{
	return m_namedElement_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getNamedElement_Attribute_name() const
{
	return m_namedElement_Attribute_name;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getNamedElement_Attribute_qualifiedName() const
{
	return m_namedElement_Attribute_qualifiedName;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getNamedElement_Attribute_visibility() const
{
	return m_namedElement_Attribute_visibility;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getNamedElement_Attribute_clientDependency() const
{
	return m_namedElement_Attribute_clientDependency;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getNamedElement_Attribute_nameExpression() const
{
	return m_namedElement_Attribute_nameExpression;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getNamedElement_Attribute_namespace() const
{
	return m_namedElement_Attribute_namespace;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement_Operation_allNamespaces() const
{
	return m_namedElement_Operation_allNamespaces;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement_Operation_allOwningPackages() const
{
	return m_namedElement_Operation_allOwningPackages;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement_Operation_createDependency_NamedElement() const
{
	return m_namedElement_Operation_createDependency_NamedElement;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement_Operation_createUsage_NamedElement() const
{
	return m_namedElement_Operation_createUsage_NamedElement;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement_Operation_getClientDependencies() const
{
	return m_namedElement_Operation_getClientDependencies;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement_Operation_getLabel() const
{
	return m_namedElement_Operation_getLabel;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement_Operation_getLabel_Boolean() const
{
	return m_namedElement_Operation_getLabel_Boolean;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement_Operation_getNamespace() const
{
	return m_namedElement_Operation_getNamespace;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement_Operation_getQualifiedName() const
{
	return m_namedElement_Operation_getQualifiedName;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement_Operation_has_no_qualified_name_EDiagnosticChain_EMap() const
{
	return m_namedElement_Operation_has_no_qualified_name_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement_Operation_has_qualified_name_EDiagnosticChain_EMap() const
{
	return m_namedElement_Operation_has_qualified_name_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement_Operation_isDistinguishableFrom_NamedElement_Namespace() const
{
	return m_namedElement_Operation_isDistinguishableFrom_NamedElement_Namespace;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement_Operation_separator() const
{
	return m_namedElement_Operation_separator;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamedElement_Operation_visibility_needs_ownership_EDiagnosticChain_EMap() const
{
	return m_namedElement_Operation_visibility_needs_ownership_EDiagnosticChain_EMap;
}

// End Class NamedElement

// Begin Class Namespace
std::shared_ptr<ecore::EClass> UmlPackageImpl::getNamespace_Class() const
{
	return m_namespace_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getNamespace_Attribute_elementImport() const
{
	return m_namespace_Attribute_elementImport;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getNamespace_Attribute_importedMember() const
{
	return m_namespace_Attribute_importedMember;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getNamespace_Attribute_member() const
{
	return m_namespace_Attribute_member;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getNamespace_Attribute_ownedMember() const
{
	return m_namespace_Attribute_ownedMember;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getNamespace_Attribute_ownedRule() const
{
	return m_namespace_Attribute_ownedRule;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getNamespace_Attribute_packageImport() const
{
	return m_namespace_Attribute_packageImport;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamespace_Operation_cannot_import_ownedMembers_EDiagnosticChain_EMap() const
{
	return m_namespace_Operation_cannot_import_ownedMembers_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamespace_Operation_cannot_import_self_EDiagnosticChain_EMap() const
{
	return m_namespace_Operation_cannot_import_self_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamespace_Operation_createElementImport_PackageableElement_VisibilityKind() const
{
	return m_namespace_Operation_createElementImport_PackageableElement_VisibilityKind;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamespace_Operation_createPackageImport_Package_VisibilityKind() const
{
	return m_namespace_Operation_createPackageImport_Package_VisibilityKind;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamespace_Operation_excludeCollisions_PackageableElement() const
{
	return m_namespace_Operation_excludeCollisions_PackageableElement;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamespace_Operation_getImportedElements() const
{
	return m_namespace_Operation_getImportedElements;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamespace_Operation_getImportedMembers() const
{
	return m_namespace_Operation_getImportedMembers;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamespace_Operation_getImportedPackages() const
{
	return m_namespace_Operation_getImportedPackages;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamespace_Operation_getNamesOfMember_NamedElement() const
{
	return m_namespace_Operation_getNamesOfMember_NamedElement;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamespace_Operation_getOwnedMembers() const
{
	return m_namespace_Operation_getOwnedMembers;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamespace_Operation_importMembers_PackageableElement() const
{
	return m_namespace_Operation_importMembers_PackageableElement;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamespace_Operation_membersAreDistinguishable() const
{
	return m_namespace_Operation_membersAreDistinguishable;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNamespace_Operation_members_distinguishable_EDiagnosticChain_EMap() const
{
	return m_namespace_Operation_members_distinguishable_EDiagnosticChain_EMap;
}

// End Class Namespace

// Begin Class Node
std::shared_ptr<ecore::EClass> UmlPackageImpl::getNode_Class() const
{
	return m_node_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getNode_Attribute_nestedNode() const
{
	return m_node_Attribute_nestedNode;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNode_Operation_createCommunicationPath_Boolean_UnlimitedNatural() const
{
	return m_node_Operation_createCommunicationPath_Boolean_UnlimitedNatural;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNode_Operation_getCommunicationPaths() const
{
	return m_node_Operation_getCommunicationPaths;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getNode_Operation_internal_structure_EDiagnosticChain_EMap() const
{
	return m_node_Operation_internal_structure_EDiagnosticChain_EMap;
}

// End Class Node

// Begin Class Object
std::shared_ptr<ecore::EClass> UmlPackageImpl::getObject_Class() const
{
	return m_object_Class;
}



std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObject_Operation_get_Property() const
{
	return m_object_Operation_get_Property;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObject_Operation_invoke_Operation_Argument() const
{
	return m_object_Operation_invoke_Operation_Argument;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObject_Operation_set_Property_EJavaObject() const
{
	return m_object_Operation_set_Property_EJavaObject;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObject_Operation_unset_Property() const
{
	return m_object_Operation_unset_Property;
}

// End Class Object

// Begin Class ObjectFlow
std::shared_ptr<ecore::EClass> UmlPackageImpl::getObjectFlow_Class() const
{
	return m_objectFlow_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getObjectFlow_Attribute_isMulticast() const
{
	return m_objectFlow_Attribute_isMulticast;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getObjectFlow_Attribute_isMultireceive() const
{
	return m_objectFlow_Attribute_isMultireceive;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getObjectFlow_Attribute_selection() const
{
	return m_objectFlow_Attribute_selection;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getObjectFlow_Attribute_transformation() const
{
	return m_objectFlow_Attribute_transformation;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObjectFlow_Operation_compatible_types_EDiagnosticChain_EMap() const
{
	return m_objectFlow_Operation_compatible_types_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObjectFlow_Operation_input_and_output_parameter_EDiagnosticChain_EMap() const
{
	return m_objectFlow_Operation_input_and_output_parameter_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObjectFlow_Operation_is_multicast_or_is_multireceive_EDiagnosticChain_EMap() const
{
	return m_objectFlow_Operation_is_multicast_or_is_multireceive_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObjectFlow_Operation_no_executable_nodes_EDiagnosticChain_EMap() const
{
	return m_objectFlow_Operation_no_executable_nodes_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObjectFlow_Operation_same_upper_bounds_EDiagnosticChain_EMap() const
{
	return m_objectFlow_Operation_same_upper_bounds_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObjectFlow_Operation_selection_behavior_EDiagnosticChain_EMap() const
{
	return m_objectFlow_Operation_selection_behavior_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObjectFlow_Operation_target_EDiagnosticChain_EMap() const
{
	return m_objectFlow_Operation_target_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObjectFlow_Operation_transformation_behavior_EDiagnosticChain_EMap() const
{
	return m_objectFlow_Operation_transformation_behavior_EDiagnosticChain_EMap;
}

// End Class ObjectFlow

// Begin Class ObjectNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getObjectNode_Class() const
{
	return m_objectNode_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getObjectNode_Attribute_isControlType() const
{
	return m_objectNode_Attribute_isControlType;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getObjectNode_Attribute_ordering() const
{
	return m_objectNode_Attribute_ordering;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getObjectNode_Attribute_inState() const
{
	return m_objectNode_Attribute_inState;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getObjectNode_Attribute_selection() const
{
	return m_objectNode_Attribute_selection;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getObjectNode_Attribute_upperBound() const
{
	return m_objectNode_Attribute_upperBound;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObjectNode_Operation_input_output_parameter_EDiagnosticChain_EMap() const
{
	return m_objectNode_Operation_input_output_parameter_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObjectNode_Operation_object_flow_edges_EDiagnosticChain_EMap() const
{
	return m_objectNode_Operation_object_flow_edges_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getObjectNode_Operation_selection_behavior_EDiagnosticChain_EMap() const
{
	return m_objectNode_Operation_selection_behavior_EDiagnosticChain_EMap;
}

// End Class ObjectNode

// Begin Class Observation
std::shared_ptr<ecore::EClass> UmlPackageImpl::getObservation_Class() const
{
	return m_observation_Class;
}




// End Class Observation

// Begin Class OccurrenceSpecification
std::shared_ptr<ecore::EClass> UmlPackageImpl::getOccurrenceSpecification_Class() const
{
	return m_occurrenceSpecification_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getOccurrenceSpecification_Attribute_toAfter() const
{
	return m_occurrenceSpecification_Attribute_toAfter;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getOccurrenceSpecification_Attribute_toBefore() const
{
	return m_occurrenceSpecification_Attribute_toBefore;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOccurrenceSpecification_Operation_getCovered() const
{
	return m_occurrenceSpecification_Operation_getCovered;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOccurrenceSpecification_Operation_setCovered_Lifeline() const
{
	return m_occurrenceSpecification_Operation_setCovered_Lifeline;
}

// End Class OccurrenceSpecification

// Begin Class OpaqueAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getOpaqueAction_Class() const
{
	return m_opaqueAction_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getOpaqueAction_Attribute_body() const
{
	return m_opaqueAction_Attribute_body;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getOpaqueAction_Attribute_language() const
{
	return m_opaqueAction_Attribute_language;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getOpaqueAction_Attribute_inputValue() const
{
	return m_opaqueAction_Attribute_inputValue;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getOpaqueAction_Attribute_outputValue() const
{
	return m_opaqueAction_Attribute_outputValue;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOpaqueAction_Operation_language_body_size_EDiagnosticChain_EMap() const
{
	return m_opaqueAction_Operation_language_body_size_EDiagnosticChain_EMap;
}

// End Class OpaqueAction

// Begin Class OpaqueBehavior
std::shared_ptr<ecore::EClass> UmlPackageImpl::getOpaqueBehavior_Class() const
{
	return m_opaqueBehavior_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getOpaqueBehavior_Attribute_body() const
{
	return m_opaqueBehavior_Attribute_body;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getOpaqueBehavior_Attribute_language() const
{
	return m_opaqueBehavior_Attribute_language;
}



// End Class OpaqueBehavior

// Begin Class OpaqueExpression
std::shared_ptr<ecore::EClass> UmlPackageImpl::getOpaqueExpression_Class() const
{
	return m_opaqueExpression_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getOpaqueExpression_Attribute_body() const
{
	return m_opaqueExpression_Attribute_body;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getOpaqueExpression_Attribute_language() const
{
	return m_opaqueExpression_Attribute_language;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getOpaqueExpression_Attribute_behavior() const
{
	return m_opaqueExpression_Attribute_behavior;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getOpaqueExpression_Attribute_result() const
{
	return m_opaqueExpression_Attribute_result;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOpaqueExpression_Operation_getResult() const
{
	return m_opaqueExpression_Operation_getResult;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOpaqueExpression_Operation_isIntegral() const
{
	return m_opaqueExpression_Operation_isIntegral;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOpaqueExpression_Operation_isNonNegative() const
{
	return m_opaqueExpression_Operation_isNonNegative;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOpaqueExpression_Operation_isPositive() const
{
	return m_opaqueExpression_Operation_isPositive;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOpaqueExpression_Operation_language_body_size_EDiagnosticChain_EMap() const
{
	return m_opaqueExpression_Operation_language_body_size_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOpaqueExpression_Operation_one_return_result_parameter_EDiagnosticChain_EMap() const
{
	return m_opaqueExpression_Operation_one_return_result_parameter_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOpaqueExpression_Operation_only_return_result_parameters_EDiagnosticChain_EMap() const
{
	return m_opaqueExpression_Operation_only_return_result_parameters_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOpaqueExpression_Operation_value() const
{
	return m_opaqueExpression_Operation_value;
}

// End Class OpaqueExpression

// Begin Class Operation
std::shared_ptr<ecore::EClass> UmlPackageImpl::getOperation_Class() const
{
	return m_operation_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getOperation_Attribute_isOrdered() const
{
	return m_operation_Attribute_isOrdered;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getOperation_Attribute_isQuery() const
{
	return m_operation_Attribute_isQuery;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getOperation_Attribute_isUnique() const
{
	return m_operation_Attribute_isUnique;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getOperation_Attribute_lower() const
{
	return m_operation_Attribute_lower;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getOperation_Attribute_upper() const
{
	return m_operation_Attribute_upper;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getOperation_Attribute_bodyCondition() const
{
	return m_operation_Attribute_bodyCondition;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getOperation_Attribute_class() const
{
	return m_operation_Attribute_class;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getOperation_Attribute_datatype() const
{
	return m_operation_Attribute_datatype;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getOperation_Attribute_interface() const
{
	return m_operation_Attribute_interface;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getOperation_Attribute_postcondition() const
{
	return m_operation_Attribute_postcondition;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getOperation_Attribute_precondition() const
{
	return m_operation_Attribute_precondition;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getOperation_Attribute_redefinedOperation() const
{
	return m_operation_Attribute_redefinedOperation;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getOperation_Attribute_type() const
{
	return m_operation_Attribute_type;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation_Operation_at_most_one_return_EDiagnosticChain_EMap() const
{
	return m_operation_Operation_at_most_one_return_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation_Operation_getLower() const
{
	return m_operation_Operation_getLower;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation_Operation_getReturnResult() const
{
	return m_operation_Operation_getReturnResult;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation_Operation_getType() const
{
	return m_operation_Operation_getType;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation_Operation_getUpper() const
{
	return m_operation_Operation_getUpper;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation_Operation_isOrdered() const
{
	return m_operation_Operation_isOrdered;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation_Operation_isUnique() const
{
	return m_operation_Operation_isUnique;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation_Operation_only_body_for_query_EDiagnosticChain_EMap() const
{
	return m_operation_Operation_only_body_for_query_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation_Operation_returnResult() const
{
	return m_operation_Operation_returnResult;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation_Operation_setIsOrdered_Boolean() const
{
	return m_operation_Operation_setIsOrdered_Boolean;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation_Operation_setIsUnique_Boolean() const
{
	return m_operation_Operation_setIsUnique_Boolean;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation_Operation_setLower_Integer() const
{
	return m_operation_Operation_setLower_Integer;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation_Operation_setType_Type() const
{
	return m_operation_Operation_setType_Type;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperation_Operation_setUpper_UnlimitedNatural() const
{
	return m_operation_Operation_setUpper_UnlimitedNatural;
}

// End Class Operation

// Begin Class OperationTemplateParameter
std::shared_ptr<ecore::EClass> UmlPackageImpl::getOperationTemplateParameter_Class() const
{
	return m_operationTemplateParameter_Class;
}



std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOperationTemplateParameter_Operation_match_default_signature_EDiagnosticChain_EMap() const
{
	return m_operationTemplateParameter_Operation_match_default_signature_EDiagnosticChain_EMap;
}

// End Class OperationTemplateParameter

// Begin Class OutputPin
std::shared_ptr<ecore::EClass> UmlPackageImpl::getOutputPin_Class() const
{
	return m_outputPin_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getOutputPin_Attribute_action() const
{
	return m_outputPin_Attribute_action;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getOutputPin_Attribute_callAction() const
{
	return m_outputPin_Attribute_callAction;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getOutputPin_Attribute_valueSpecificationAction() const
{
	return m_outputPin_Attribute_valueSpecificationAction;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getOutputPin_Operation_incoming_edges_structured_only_EDiagnosticChain_EMap() const
{
	return m_outputPin_Operation_incoming_edges_structured_only_EDiagnosticChain_EMap;
}

// End Class OutputPin

// Begin Class Package
std::shared_ptr<ecore::EClass> UmlPackageImpl::getPackage_Class() const
{
	return m_package_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getPackage_Attribute_uRI() const
{
	return m_package_Attribute_uRI;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getPackage_Attribute_nestedPackage() const
{
	return m_package_Attribute_nestedPackage;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getPackage_Attribute_nestingPackage() const
{
	return m_package_Attribute_nestingPackage;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getPackage_Attribute_ownedStereotype() const
{
	return m_package_Attribute_ownedStereotype;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getPackage_Attribute_ownedType() const
{
	return m_package_Attribute_ownedType;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getPackage_Attribute_packageMerge() const
{
	return m_package_Attribute_packageMerge;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getPackage_Attribute_packagedElement() const
{
	return m_package_Attribute_packagedElement;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getPackage_Attribute_profileApplication() const
{
	return m_package_Attribute_profileApplication;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_Operation_allApplicableStereotypes() const
{
	return m_package_Operation_allApplicableStereotypes;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_Operation_applyProfile_Profile() const
{
	return m_package_Operation_applyProfile_Profile;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_Operation_containingProfile() const
{
	return m_package_Operation_containingProfile;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_Operation_createOwnedClass_String_Boolean() const
{
	return m_package_Operation_createOwnedClass_String_Boolean;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_Operation_createOwnedEnumeration_String() const
{
	return m_package_Operation_createOwnedEnumeration_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_Operation_createOwnedInterface_String() const
{
	return m_package_Operation_createOwnedInterface_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_Operation_createOwnedPrimitiveType_String() const
{
	return m_package_Operation_createOwnedPrimitiveType_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_Operation_createOwnedStereotype_String_Boolean() const
{
	return m_package_Operation_createOwnedStereotype_String_Boolean;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_Operation_elements_public_or_private_EDiagnosticChain_EMap() const
{
	return m_package_Operation_elements_public_or_private_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_Operation_getAllAppliedProfiles() const
{
	return m_package_Operation_getAllAppliedProfiles;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_Operation_getAllProfileApplications() const
{
	return m_package_Operation_getAllProfileApplications;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_Operation_getAppliedProfile_String() const
{
	return m_package_Operation_getAppliedProfile_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_Operation_getAppliedProfile_String_Boolean() const
{
	return m_package_Operation_getAppliedProfile_String_Boolean;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_Operation_getAppliedProfiles() const
{
	return m_package_Operation_getAppliedProfiles;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_Operation_getNestedPackages() const
{
	return m_package_Operation_getNestedPackages;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_Operation_getOwnedStereotypes() const
{
	return m_package_Operation_getOwnedStereotypes;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_Operation_getOwnedTypes() const
{
	return m_package_Operation_getOwnedTypes;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_Operation_getProfileApplication_Profile() const
{
	return m_package_Operation_getProfileApplication_Profile;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_Operation_getProfileApplication_Profile_Boolean() const
{
	return m_package_Operation_getProfileApplication_Profile_Boolean;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_Operation_isModelLibrary() const
{
	return m_package_Operation_isModelLibrary;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_Operation_isProfileApplied_Profile() const
{
	return m_package_Operation_isProfileApplied_Profile;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_Operation_makesVisible_NamedElement() const
{
	return m_package_Operation_makesVisible_NamedElement;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_Operation_unapplyProfile_Profile() const
{
	return m_package_Operation_unapplyProfile_Profile;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackage_Operation_visibleMembers() const
{
	return m_package_Operation_visibleMembers;
}

// End Class Package

// Begin Class PackageImport
std::shared_ptr<ecore::EClass> UmlPackageImpl::getPackageImport_Class() const
{
	return m_packageImport_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getPackageImport_Attribute_visibility() const
{
	return m_packageImport_Attribute_visibility;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getPackageImport_Attribute_importedPackage() const
{
	return m_packageImport_Attribute_importedPackage;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getPackageImport_Attribute_importingNamespace() const
{
	return m_packageImport_Attribute_importingNamespace;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackageImport_Operation_public_or_private_EDiagnosticChain_EMap() const
{
	return m_packageImport_Operation_public_or_private_EDiagnosticChain_EMap;
}

// End Class PackageImport

// Begin Class PackageMerge
std::shared_ptr<ecore::EClass> UmlPackageImpl::getPackageMerge_Class() const
{
	return m_packageMerge_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getPackageMerge_Attribute_mergedPackage() const
{
	return m_packageMerge_Attribute_mergedPackage;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getPackageMerge_Attribute_receivingPackage() const
{
	return m_packageMerge_Attribute_receivingPackage;
}


// End Class PackageMerge

// Begin Class PackageableElement
std::shared_ptr<ecore::EClass> UmlPackageImpl::getPackageableElement_Class() const
{
	return m_packageableElement_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getPackageableElement_Attribute_owningPackage() const
{
	return m_packageableElement_Attribute_owningPackage;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPackageableElement_Operation_namespace_needs_visibility_EDiagnosticChain_EMap() const
{
	return m_packageableElement_Operation_namespace_needs_visibility_EDiagnosticChain_EMap;
}

// End Class PackageableElement

// Begin Class Parameter
std::shared_ptr<ecore::EClass> UmlPackageImpl::getParameter_Class() const
{
	return m_parameter_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getParameter_Attribute_default() const
{
	return m_parameter_Attribute_default;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getParameter_Attribute_direction() const
{
	return m_parameter_Attribute_direction;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getParameter_Attribute_effect() const
{
	return m_parameter_Attribute_effect;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getParameter_Attribute_isException() const
{
	return m_parameter_Attribute_isException;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getParameter_Attribute_isStream() const
{
	return m_parameter_Attribute_isStream;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getParameter_Attribute_behavior() const
{
	return m_parameter_Attribute_behavior;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getParameter_Attribute_defaultValue() const
{
	return m_parameter_Attribute_defaultValue;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getParameter_Attribute_operation() const
{
	return m_parameter_Attribute_operation;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getParameter_Attribute_parameterSet() const
{
	return m_parameter_Attribute_parameterSet;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter_Operation_connector_end_EDiagnosticChain_EMap() const
{
	return m_parameter_Operation_connector_end_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter_Operation_in_and_out_EDiagnosticChain_EMap() const
{
	return m_parameter_Operation_in_and_out_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter_Operation_isSetDefault() const
{
	return m_parameter_Operation_isSetDefault;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter_Operation_not_exception_EDiagnosticChain_EMap() const
{
	return m_parameter_Operation_not_exception_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter_Operation_object_effect_EDiagnosticChain_EMap() const
{
	return m_parameter_Operation_object_effect_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter_Operation_reentrant_behaviors_EDiagnosticChain_EMap() const
{
	return m_parameter_Operation_reentrant_behaviors_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter_Operation_setBooleanDefaultValue_Boolean() const
{
	return m_parameter_Operation_setBooleanDefaultValue_Boolean;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter_Operation_setIntegerDefaultValue_Integer() const
{
	return m_parameter_Operation_setIntegerDefaultValue_Integer;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter_Operation_setNullDefaultValue() const
{
	return m_parameter_Operation_setNullDefaultValue;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter_Operation_setRealDefaultValue_Real() const
{
	return m_parameter_Operation_setRealDefaultValue_Real;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter_Operation_setStringDefaultValue_String() const
{
	return m_parameter_Operation_setStringDefaultValue_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter_Operation_setUnlimitedNaturalDefaultValue_UnlimitedNatural() const
{
	return m_parameter_Operation_setUnlimitedNaturalDefaultValue_UnlimitedNatural;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter_Operation_stream_and_exception_EDiagnosticChain_EMap() const
{
	return m_parameter_Operation_stream_and_exception_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameter_Operation_unsetDefault() const
{
	return m_parameter_Operation_unsetDefault;
}

// End Class Parameter

// Begin Class ParameterSet
std::shared_ptr<ecore::EClass> UmlPackageImpl::getParameterSet_Class() const
{
	return m_parameterSet_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getParameterSet_Attribute_condition() const
{
	return m_parameterSet_Attribute_condition;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getParameterSet_Attribute_parameter() const
{
	return m_parameterSet_Attribute_parameter;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameterSet_Operation_input_EDiagnosticChain_EMap() const
{
	return m_parameterSet_Operation_input_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameterSet_Operation_same_parameterized_entity_EDiagnosticChain_EMap() const
{
	return m_parameterSet_Operation_same_parameterized_entity_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameterSet_Operation_two_parameter_sets_EDiagnosticChain_EMap() const
{
	return m_parameterSet_Operation_two_parameter_sets_EDiagnosticChain_EMap;
}

// End Class ParameterSet

// Begin Class ParameterableElement
std::shared_ptr<ecore::EClass> UmlPackageImpl::getParameterableElement_Class() const
{
	return m_parameterableElement_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getParameterableElement_Attribute_owningTemplateParameter() const
{
	return m_parameterableElement_Attribute_owningTemplateParameter;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getParameterableElement_Attribute_templateParameter() const
{
	return m_parameterableElement_Attribute_templateParameter;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameterableElement_Operation_isCompatibleWith_ParameterableElement() const
{
	return m_parameterableElement_Operation_isCompatibleWith_ParameterableElement;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getParameterableElement_Operation_isTemplateParameter() const
{
	return m_parameterableElement_Operation_isTemplateParameter;
}

// End Class ParameterableElement

// Begin Class PartDecomposition
std::shared_ptr<ecore::EClass> UmlPackageImpl::getPartDecomposition_Class() const
{
	return m_partDecomposition_Class;
}



std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPartDecomposition_Operation_assume_EDiagnosticChain_EMap() const
{
	return m_partDecomposition_Operation_assume_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPartDecomposition_Operation_commutativity_of_decomposition_EDiagnosticChain_EMap() const
{
	return m_partDecomposition_Operation_commutativity_of_decomposition_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPartDecomposition_Operation_parts_of_internal_structures_EDiagnosticChain_EMap() const
{
	return m_partDecomposition_Operation_parts_of_internal_structures_EDiagnosticChain_EMap;
}

// End Class PartDecomposition

// Begin Class Pin
std::shared_ptr<ecore::EClass> UmlPackageImpl::getPin_Class() const
{
	return m_pin_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getPin_Attribute_isControl() const
{
	return m_pin_Attribute_isControl;
}


std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPin_Operation_control_pins_EDiagnosticChain_EMap() const
{
	return m_pin_Operation_control_pins_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPin_Operation_not_unique_EDiagnosticChain_EMap() const
{
	return m_pin_Operation_not_unique_EDiagnosticChain_EMap;
}

// End Class Pin

// Begin Class Port
std::shared_ptr<ecore::EClass> UmlPackageImpl::getPort_Class() const
{
	return m_port_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getPort_Attribute_isBehavior() const
{
	return m_port_Attribute_isBehavior;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getPort_Attribute_isConjugated() const
{
	return m_port_Attribute_isConjugated;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getPort_Attribute_isService() const
{
	return m_port_Attribute_isService;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getPort_Attribute_protocol() const
{
	return m_port_Attribute_protocol;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getPort_Attribute_provided() const
{
	return m_port_Attribute_provided;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getPort_Attribute_redefinedPort() const
{
	return m_port_Attribute_redefinedPort;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getPort_Attribute_required() const
{
	return m_port_Attribute_required;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPort_Operation_basicProvided() const
{
	return m_port_Operation_basicProvided;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPort_Operation_basicRequired() const
{
	return m_port_Operation_basicRequired;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPort_Operation_default_value_EDiagnosticChain_EMap() const
{
	return m_port_Operation_default_value_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPort_Operation_encapsulated_owner_EDiagnosticChain_EMap() const
{
	return m_port_Operation_encapsulated_owner_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPort_Operation_getProvideds() const
{
	return m_port_Operation_getProvideds;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPort_Operation_getRequireds() const
{
	return m_port_Operation_getRequireds;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPort_Operation_port_aggregation_EDiagnosticChain_EMap() const
{
	return m_port_Operation_port_aggregation_EDiagnosticChain_EMap;
}

// End Class Port

// Begin Class PrimitiveType
std::shared_ptr<ecore::EClass> UmlPackageImpl::getPrimitiveType_Class() const
{
	return m_primitiveType_Class;
}




// End Class PrimitiveType

// Begin Class Profile
std::shared_ptr<ecore::EClass> UmlPackageImpl::getProfile_Class() const
{
	return m_profile_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getProfile_Attribute_metaclassReference() const
{
	return m_profile_Attribute_metaclassReference;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProfile_Attribute_metamodelReference() const
{
	return m_profile_Attribute_metamodelReference;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProfile_Operation_create_Classifier() const
{
	return m_profile_Operation_create_Classifier;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProfile_Operation_define() const
{
	return m_profile_Operation_define;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProfile_Operation_define_EMap_EMap() const
{
	return m_profile_Operation_define_EMap_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProfile_Operation_getDefinition() const
{
	return m_profile_Operation_getDefinition;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProfile_Operation_getDefinition_NamedElement() const
{
	return m_profile_Operation_getDefinition_NamedElement;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProfile_Operation_getOwnedExtensions_Boolean() const
{
	return m_profile_Operation_getOwnedExtensions_Boolean;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProfile_Operation_getReferencedMetaclasses() const
{
	return m_profile_Operation_getReferencedMetaclasses;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProfile_Operation_getReferencedMetamodels() const
{
	return m_profile_Operation_getReferencedMetamodels;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProfile_Operation_isDefined() const
{
	return m_profile_Operation_isDefined;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProfile_Operation_metaclass_reference_not_specialized_EDiagnosticChain_EMap() const
{
	return m_profile_Operation_metaclass_reference_not_specialized_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProfile_Operation_references_same_metamodel_EDiagnosticChain_EMap() const
{
	return m_profile_Operation_references_same_metamodel_EDiagnosticChain_EMap;
}

// End Class Profile

// Begin Class ProfileApplication
std::shared_ptr<ecore::EClass> UmlPackageImpl::getProfileApplication_Class() const
{
	return m_profileApplication_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getProfileApplication_Attribute_isStrict() const
{
	return m_profileApplication_Attribute_isStrict;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getProfileApplication_Attribute_appliedProfile() const
{
	return m_profileApplication_Attribute_appliedProfile;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProfileApplication_Attribute_applyingPackage() const
{
	return m_profileApplication_Attribute_applyingPackage;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProfileApplication_Operation_getAppliedDefinition() const
{
	return m_profileApplication_Operation_getAppliedDefinition;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProfileApplication_Operation_getAppliedDefinition_NamedElement() const
{
	return m_profileApplication_Operation_getAppliedDefinition_NamedElement;
}

// End Class ProfileApplication

// Begin Class Property
std::shared_ptr<ecore::EClass> UmlPackageImpl::getProperty_Class() const
{
	return m_property_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getProperty_Attribute_aggregation() const
{
	return m_property_Attribute_aggregation;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getProperty_Attribute_default() const
{
	return m_property_Attribute_default;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getProperty_Attribute_isComposite() const
{
	return m_property_Attribute_isComposite;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getProperty_Attribute_isDerived() const
{
	return m_property_Attribute_isDerived;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getProperty_Attribute_isDerivedUnion() const
{
	return m_property_Attribute_isDerivedUnion;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getProperty_Attribute_isID() const
{
	return m_property_Attribute_isID;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getProperty_Attribute_association() const
{
	return m_property_Attribute_association;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProperty_Attribute_associationEnd() const
{
	return m_property_Attribute_associationEnd;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProperty_Attribute_class() const
{
	return m_property_Attribute_class;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProperty_Attribute_datatype() const
{
	return m_property_Attribute_datatype;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProperty_Attribute_defaultValue() const
{
	return m_property_Attribute_defaultValue;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProperty_Attribute_interface() const
{
	return m_property_Attribute_interface;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProperty_Attribute_opposite() const
{
	return m_property_Attribute_opposite;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProperty_Attribute_owningAssociation() const
{
	return m_property_Attribute_owningAssociation;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProperty_Attribute_qualifier() const
{
	return m_property_Attribute_qualifier;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProperty_Attribute_redefinedProperty() const
{
	return m_property_Attribute_redefinedProperty;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProperty_Attribute_subsettedProperty() const
{
	return m_property_Attribute_subsettedProperty;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_Operation_binding_to_attribute_EDiagnosticChain_EMap() const
{
	return m_property_Operation_binding_to_attribute_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_Operation_deployment_target_EDiagnosticChain_EMap() const
{
	return m_property_Operation_deployment_target_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_Operation_derived_union_is_derived_EDiagnosticChain_EMap() const
{
	return m_property_Operation_derived_union_is_derived_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_Operation_derived_union_is_read_only_EDiagnosticChain_EMap() const
{
	return m_property_Operation_derived_union_is_read_only_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_Operation_getOpposite() const
{
	return m_property_Operation_getOpposite;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_Operation_getOtherEnd() const
{
	return m_property_Operation_getOtherEnd;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_Operation_isAttribute() const
{
	return m_property_Operation_isAttribute;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_Operation_isComposite() const
{
	return m_property_Operation_isComposite;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_Operation_isNavigable() const
{
	return m_property_Operation_isNavigable;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_Operation_isSetDefault() const
{
	return m_property_Operation_isSetDefault;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_Operation_multiplicity_of_composite_EDiagnosticChain_EMap() const
{
	return m_property_Operation_multiplicity_of_composite_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_Operation_qualified_is_association_end_EDiagnosticChain_EMap() const
{
	return m_property_Operation_qualified_is_association_end_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_Operation_redefined_property_inherited_EDiagnosticChain_EMap() const
{
	return m_property_Operation_redefined_property_inherited_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_Operation_setBooleanDefaultValue_Boolean() const
{
	return m_property_Operation_setBooleanDefaultValue_Boolean;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_Operation_setIntegerDefaultValue_Integer() const
{
	return m_property_Operation_setIntegerDefaultValue_Integer;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_Operation_setIsNavigable_Boolean() const
{
	return m_property_Operation_setIsNavigable_Boolean;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_Operation_setNullDefaultValue() const
{
	return m_property_Operation_setNullDefaultValue;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_Operation_setRealDefaultValue_Real() const
{
	return m_property_Operation_setRealDefaultValue_Real;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_Operation_setStringDefaultValue_String() const
{
	return m_property_Operation_setStringDefaultValue_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_Operation_setUnlimitedNaturalDefaultValue_UnlimitedNatural() const
{
	return m_property_Operation_setUnlimitedNaturalDefaultValue_UnlimitedNatural;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_Operation_subsetted_property_names_EDiagnosticChain_EMap() const
{
	return m_property_Operation_subsetted_property_names_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_Operation_subsettingContext() const
{
	return m_property_Operation_subsettingContext;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_Operation_subsetting_context_conforms_EDiagnosticChain_EMap() const
{
	return m_property_Operation_subsetting_context_conforms_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_Operation_subsetting_rules_EDiagnosticChain_EMap() const
{
	return m_property_Operation_subsetting_rules_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_Operation_type_of_opposite_end_EDiagnosticChain_EMap() const
{
	return m_property_Operation_type_of_opposite_end_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProperty_Operation_unsetDefault() const
{
	return m_property_Operation_unsetDefault;
}

// End Class Property

// Begin Class ProtocolConformance
std::shared_ptr<ecore::EClass> UmlPackageImpl::getProtocolConformance_Class() const
{
	return m_protocolConformance_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getProtocolConformance_Attribute_generalMachine() const
{
	return m_protocolConformance_Attribute_generalMachine;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProtocolConformance_Attribute_specificMachine() const
{
	return m_protocolConformance_Attribute_specificMachine;
}


// End Class ProtocolConformance

// Begin Class ProtocolStateMachine
std::shared_ptr<ecore::EClass> UmlPackageImpl::getProtocolStateMachine_Class() const
{
	return m_protocolStateMachine_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getProtocolStateMachine_Attribute_conformance() const
{
	return m_protocolStateMachine_Attribute_conformance;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProtocolStateMachine_Operation_deep_or_shallow_history_EDiagnosticChain_EMap() const
{
	return m_protocolStateMachine_Operation_deep_or_shallow_history_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProtocolStateMachine_Operation_entry_exit_do_EDiagnosticChain_EMap() const
{
	return m_protocolStateMachine_Operation_entry_exit_do_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProtocolStateMachine_Operation_protocol_transitions_EDiagnosticChain_EMap() const
{
	return m_protocolStateMachine_Operation_protocol_transitions_EDiagnosticChain_EMap;
}

// End Class ProtocolStateMachine

// Begin Class ProtocolTransition
std::shared_ptr<ecore::EClass> UmlPackageImpl::getProtocolTransition_Class() const
{
	return m_protocolTransition_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getProtocolTransition_Attribute_postCondition() const
{
	return m_protocolTransition_Attribute_postCondition;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProtocolTransition_Attribute_preCondition() const
{
	return m_protocolTransition_Attribute_preCondition;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getProtocolTransition_Attribute_referred() const
{
	return m_protocolTransition_Attribute_referred;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProtocolTransition_Operation_associated_actions_EDiagnosticChain_EMap() const
{
	return m_protocolTransition_Operation_associated_actions_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProtocolTransition_Operation_belongs_to_psm_EDiagnosticChain_EMap() const
{
	return m_protocolTransition_Operation_belongs_to_psm_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProtocolTransition_Operation_getReferreds() const
{
	return m_protocolTransition_Operation_getReferreds;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getProtocolTransition_Operation_refers_to_operation_EDiagnosticChain_EMap() const
{
	return m_protocolTransition_Operation_refers_to_operation_EDiagnosticChain_EMap;
}

// End Class ProtocolTransition

// Begin Class Pseudostate
std::shared_ptr<ecore::EClass> UmlPackageImpl::getPseudostate_Class() const
{
	return m_pseudostate_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getPseudostate_Attribute_kind() const
{
	return m_pseudostate_Attribute_kind;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getPseudostate_Attribute_state() const
{
	return m_pseudostate_Attribute_state;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getPseudostate_Attribute_stateMachine() const
{
	return m_pseudostate_Attribute_stateMachine;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPseudostate_Operation_choice_vertex_EDiagnosticChain_EMap() const
{
	return m_pseudostate_Operation_choice_vertex_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPseudostate_Operation_fork_vertex_EDiagnosticChain_EMap() const
{
	return m_pseudostate_Operation_fork_vertex_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPseudostate_Operation_history_vertices_EDiagnosticChain_EMap() const
{
	return m_pseudostate_Operation_history_vertices_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPseudostate_Operation_initial_vertex_EDiagnosticChain_EMap() const
{
	return m_pseudostate_Operation_initial_vertex_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPseudostate_Operation_join_vertex_EDiagnosticChain_EMap() const
{
	return m_pseudostate_Operation_join_vertex_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPseudostate_Operation_junction_vertex_EDiagnosticChain_EMap() const
{
	return m_pseudostate_Operation_junction_vertex_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPseudostate_Operation_outgoing_from_initial_EDiagnosticChain_EMap() const
{
	return m_pseudostate_Operation_outgoing_from_initial_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPseudostate_Operation_transitions_incoming_EDiagnosticChain_EMap() const
{
	return m_pseudostate_Operation_transitions_incoming_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getPseudostate_Operation_transitions_outgoing_EDiagnosticChain_EMap() const
{
	return m_pseudostate_Operation_transitions_outgoing_EDiagnosticChain_EMap;
}

// End Class Pseudostate

// Begin Class QualifierValue
std::shared_ptr<ecore::EClass> UmlPackageImpl::getQualifierValue_Class() const
{
	return m_qualifierValue_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getQualifierValue_Attribute_qualifier() const
{
	return m_qualifierValue_Attribute_qualifier;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getQualifierValue_Attribute_value() const
{
	return m_qualifierValue_Attribute_value;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getQualifierValue_Operation_multiplicity_of_qualifier_EDiagnosticChain_EMap() const
{
	return m_qualifierValue_Operation_multiplicity_of_qualifier_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getQualifierValue_Operation_qualifier_attribute_EDiagnosticChain_EMap() const
{
	return m_qualifierValue_Operation_qualifier_attribute_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getQualifierValue_Operation_type_of_qualifier_EDiagnosticChain_EMap() const
{
	return m_qualifierValue_Operation_type_of_qualifier_EDiagnosticChain_EMap;
}

// End Class QualifierValue

// Begin Class RaiseExceptionAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getRaiseExceptionAction_Class() const
{
	return m_raiseExceptionAction_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getRaiseExceptionAction_Attribute_exception() const
{
	return m_raiseExceptionAction_Attribute_exception;
}


// End Class RaiseExceptionAction

// Begin Class ReadExtentAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getReadExtentAction_Class() const
{
	return m_readExtentAction_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadExtentAction_Attribute_classifier() const
{
	return m_readExtentAction_Attribute_classifier;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadExtentAction_Attribute_result() const
{
	return m_readExtentAction_Attribute_result;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadExtentAction_Operation_multiplicity_of_result_EDiagnosticChain_EMap() const
{
	return m_readExtentAction_Operation_multiplicity_of_result_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadExtentAction_Operation_type_is_classifier_EDiagnosticChain_EMap() const
{
	return m_readExtentAction_Operation_type_is_classifier_EDiagnosticChain_EMap;
}

// End Class ReadExtentAction

// Begin Class ReadIsClassifiedObjectAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getReadIsClassifiedObjectAction_Class() const
{
	return m_readIsClassifiedObjectAction_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getReadIsClassifiedObjectAction_Attribute_isDirect() const
{
	return m_readIsClassifiedObjectAction_Attribute_isDirect;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadIsClassifiedObjectAction_Attribute_classifier() const
{
	return m_readIsClassifiedObjectAction_Attribute_classifier;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadIsClassifiedObjectAction_Attribute_object() const
{
	return m_readIsClassifiedObjectAction_Attribute_object;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadIsClassifiedObjectAction_Attribute_result() const
{
	return m_readIsClassifiedObjectAction_Attribute_result;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadIsClassifiedObjectAction_Operation_boolean_result_EDiagnosticChain_EMap() const
{
	return m_readIsClassifiedObjectAction_Operation_boolean_result_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadIsClassifiedObjectAction_Operation_multiplicity_of_input_EDiagnosticChain_EMap() const
{
	return m_readIsClassifiedObjectAction_Operation_multiplicity_of_input_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadIsClassifiedObjectAction_Operation_multiplicity_of_output_EDiagnosticChain_EMap() const
{
	return m_readIsClassifiedObjectAction_Operation_multiplicity_of_output_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadIsClassifiedObjectAction_Operation_no_type_EDiagnosticChain_EMap() const
{
	return m_readIsClassifiedObjectAction_Operation_no_type_EDiagnosticChain_EMap;
}

// End Class ReadIsClassifiedObjectAction

// Begin Class ReadLinkAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getReadLinkAction_Class() const
{
	return m_readLinkAction_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadLinkAction_Attribute_result() const
{
	return m_readLinkAction_Attribute_result;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkAction_Operation_compatible_multiplicity_EDiagnosticChain_EMap() const
{
	return m_readLinkAction_Operation_compatible_multiplicity_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkAction_Operation_navigable_open_end_EDiagnosticChain_EMap() const
{
	return m_readLinkAction_Operation_navigable_open_end_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkAction_Operation_one_open_end_EDiagnosticChain_EMap() const
{
	return m_readLinkAction_Operation_one_open_end_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkAction_Operation_openEnd() const
{
	return m_readLinkAction_Operation_openEnd;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkAction_Operation_type_and_ordering_EDiagnosticChain_EMap() const
{
	return m_readLinkAction_Operation_type_and_ordering_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkAction_Operation_visibility_EDiagnosticChain_EMap() const
{
	return m_readLinkAction_Operation_visibility_EDiagnosticChain_EMap;
}

// End Class ReadLinkAction

// Begin Class ReadLinkObjectEndAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getReadLinkObjectEndAction_Class() const
{
	return m_readLinkObjectEndAction_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadLinkObjectEndAction_Attribute_end() const
{
	return m_readLinkObjectEndAction_Attribute_end;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadLinkObjectEndAction_Attribute_object() const
{
	return m_readLinkObjectEndAction_Attribute_object;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadLinkObjectEndAction_Attribute_result() const
{
	return m_readLinkObjectEndAction_Attribute_result;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndAction_Operation_association_of_association_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndAction_Operation_association_of_association_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndAction_Operation_ends_of_association_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndAction_Operation_ends_of_association_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndAction_Operation_multiplicity_of_object_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndAction_Operation_multiplicity_of_object_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndAction_Operation_multiplicity_of_result_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndAction_Operation_multiplicity_of_result_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndAction_Operation_property_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndAction_Operation_property_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndAction_Operation_type_of_object_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndAction_Operation_type_of_object_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndAction_Operation_type_of_result_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndAction_Operation_type_of_result_EDiagnosticChain_EMap;
}

// End Class ReadLinkObjectEndAction

// Begin Class ReadLinkObjectEndQualifierAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getReadLinkObjectEndQualifierAction_Class() const
{
	return m_readLinkObjectEndQualifierAction_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadLinkObjectEndQualifierAction_Attribute_object() const
{
	return m_readLinkObjectEndQualifierAction_Attribute_object;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadLinkObjectEndQualifierAction_Attribute_qualifier() const
{
	return m_readLinkObjectEndQualifierAction_Attribute_qualifier;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadLinkObjectEndQualifierAction_Attribute_result() const
{
	return m_readLinkObjectEndQualifierAction_Attribute_result;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndQualifierAction_Operation_association_of_association_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndQualifierAction_Operation_association_of_association_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndQualifierAction_Operation_ends_of_association_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndQualifierAction_Operation_ends_of_association_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndQualifierAction_Operation_multiplicity_of_object_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndQualifierAction_Operation_multiplicity_of_object_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndQualifierAction_Operation_multiplicity_of_qualifier_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndQualifierAction_Operation_multiplicity_of_qualifier_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndQualifierAction_Operation_multiplicity_of_result_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndQualifierAction_Operation_multiplicity_of_result_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndQualifierAction_Operation_qualifier_attribute_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndQualifierAction_Operation_qualifier_attribute_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndQualifierAction_Operation_same_type_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndQualifierAction_Operation_same_type_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadLinkObjectEndQualifierAction_Operation_type_of_object_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndQualifierAction_Operation_type_of_object_EDiagnosticChain_EMap;
}

// End Class ReadLinkObjectEndQualifierAction

// Begin Class ReadSelfAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getReadSelfAction_Class() const
{
	return m_readSelfAction_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadSelfAction_Attribute_result() const
{
	return m_readSelfAction_Attribute_result;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadSelfAction_Operation_contained_EDiagnosticChain_EMap() const
{
	return m_readSelfAction_Operation_contained_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadSelfAction_Operation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_readSelfAction_Operation_multiplicity_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadSelfAction_Operation_not_static_EDiagnosticChain_EMap() const
{
	return m_readSelfAction_Operation_not_static_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadSelfAction_Operation_type_EDiagnosticChain_EMap() const
{
	return m_readSelfAction_Operation_type_EDiagnosticChain_EMap;
}

// End Class ReadSelfAction

// Begin Class ReadStructuralFeatureAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getReadStructuralFeatureAction_Class() const
{
	return m_readStructuralFeatureAction_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadStructuralFeatureAction_Attribute_result() const
{
	return m_readStructuralFeatureAction_Attribute_result;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadStructuralFeatureAction_Operation_type_and_ordering_EDiagnosticChain_EMap() const
{
	return m_readStructuralFeatureAction_Operation_type_and_ordering_EDiagnosticChain_EMap;
}

// End Class ReadStructuralFeatureAction

// Begin Class ReadVariableAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getReadVariableAction_Class() const
{
	return m_readVariableAction_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getReadVariableAction_Attribute_result() const
{
	return m_readVariableAction_Attribute_result;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadVariableAction_Operation_compatible_multiplicity_EDiagnosticChain_EMap() const
{
	return m_readVariableAction_Operation_compatible_multiplicity_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReadVariableAction_Operation_type_and_ordering_EDiagnosticChain_EMap() const
{
	return m_readVariableAction_Operation_type_and_ordering_EDiagnosticChain_EMap;
}

// End Class ReadVariableAction

// Begin Class Realization
std::shared_ptr<ecore::EClass> UmlPackageImpl::getRealization_Class() const
{
	return m_realization_Class;
}




// End Class Realization

// Begin Class Reception
std::shared_ptr<ecore::EClass> UmlPackageImpl::getReception_Class() const
{
	return m_reception_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getReception_Attribute_signal() const
{
	return m_reception_Attribute_signal;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReception_Operation_same_name_as_signal_EDiagnosticChain_EMap() const
{
	return m_reception_Operation_same_name_as_signal_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReception_Operation_same_structure_as_signal_EDiagnosticChain_EMap() const
{
	return m_reception_Operation_same_structure_as_signal_EDiagnosticChain_EMap;
}

// End Class Reception

// Begin Class ReclassifyObjectAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getReclassifyObjectAction_Class() const
{
	return m_reclassifyObjectAction_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getReclassifyObjectAction_Attribute_isReplaceAll() const
{
	return m_reclassifyObjectAction_Attribute_isReplaceAll;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getReclassifyObjectAction_Attribute_newClassifier() const
{
	return m_reclassifyObjectAction_Attribute_newClassifier;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getReclassifyObjectAction_Attribute_object() const
{
	return m_reclassifyObjectAction_Attribute_object;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getReclassifyObjectAction_Attribute_oldClassifier() const
{
	return m_reclassifyObjectAction_Attribute_oldClassifier;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReclassifyObjectAction_Operation_classifier_not_abstract_EDiagnosticChain_EMap() const
{
	return m_reclassifyObjectAction_Operation_classifier_not_abstract_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReclassifyObjectAction_Operation_input_pin_EDiagnosticChain_EMap() const
{
	return m_reclassifyObjectAction_Operation_input_pin_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReclassifyObjectAction_Operation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_reclassifyObjectAction_Operation_multiplicity_EDiagnosticChain_EMap;
}

// End Class ReclassifyObjectAction

// Begin Class RedefinableElement
std::shared_ptr<ecore::EClass> UmlPackageImpl::getRedefinableElement_Class() const
{
	return m_redefinableElement_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getRedefinableElement_Attribute_isLeaf() const
{
	return m_redefinableElement_Attribute_isLeaf;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getRedefinableElement_Attribute_redefinedElement() const
{
	return m_redefinableElement_Attribute_redefinedElement;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getRedefinableElement_Attribute_redefinitionContext() const
{
	return m_redefinableElement_Attribute_redefinitionContext;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRedefinableElement_Operation_isConsistentWith_RedefinableElement() const
{
	return m_redefinableElement_Operation_isConsistentWith_RedefinableElement;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRedefinableElement_Operation_isRedefinitionContextValid_RedefinableElement() const
{
	return m_redefinableElement_Operation_isRedefinitionContextValid_RedefinableElement;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRedefinableElement_Operation_non_leaf_redefinition_EDiagnosticChain_EMap() const
{
	return m_redefinableElement_Operation_non_leaf_redefinition_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRedefinableElement_Operation_redefinition_consistent_EDiagnosticChain_EMap() const
{
	return m_redefinableElement_Operation_redefinition_consistent_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRedefinableElement_Operation_redefinition_context_valid_EDiagnosticChain_EMap() const
{
	return m_redefinableElement_Operation_redefinition_context_valid_EDiagnosticChain_EMap;
}

// End Class RedefinableElement

// Begin Class RedefinableTemplateSignature
std::shared_ptr<ecore::EClass> UmlPackageImpl::getRedefinableTemplateSignature_Class() const
{
	return m_redefinableTemplateSignature_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getRedefinableTemplateSignature_Attribute_classifier() const
{
	return m_redefinableTemplateSignature_Attribute_classifier;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getRedefinableTemplateSignature_Attribute_extendedSignature() const
{
	return m_redefinableTemplateSignature_Attribute_extendedSignature;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getRedefinableTemplateSignature_Attribute_inheritedParameter() const
{
	return m_redefinableTemplateSignature_Attribute_inheritedParameter;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRedefinableTemplateSignature_Operation_getInheritedParameters() const
{
	return m_redefinableTemplateSignature_Operation_getInheritedParameters;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRedefinableTemplateSignature_Operation_redefines_parents_EDiagnosticChain_EMap() const
{
	return m_redefinableTemplateSignature_Operation_redefines_parents_EDiagnosticChain_EMap;
}

// End Class RedefinableTemplateSignature

// Begin Class ReduceAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getReduceAction_Class() const
{
	return m_reduceAction_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getReduceAction_Attribute_isOrdered() const
{
	return m_reduceAction_Attribute_isOrdered;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getReduceAction_Attribute_collection() const
{
	return m_reduceAction_Attribute_collection;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getReduceAction_Attribute_reducer() const
{
	return m_reduceAction_Attribute_reducer;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getReduceAction_Attribute_result() const
{
	return m_reduceAction_Attribute_result;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReduceAction_Operation_input_type_is_collection_EDiagnosticChain_EMap() const
{
	return m_reduceAction_Operation_input_type_is_collection_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReduceAction_Operation_output_types_are_compatible_EDiagnosticChain_EMap() const
{
	return m_reduceAction_Operation_output_types_are_compatible_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReduceAction_Operation_reducer_inputs_output_EDiagnosticChain_EMap() const
{
	return m_reduceAction_Operation_reducer_inputs_output_EDiagnosticChain_EMap;
}

// End Class ReduceAction

// Begin Class Region
std::shared_ptr<ecore::EClass> UmlPackageImpl::getRegion_Class() const
{
	return m_region_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getRegion_Attribute_extendedRegion() const
{
	return m_region_Attribute_extendedRegion;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getRegion_Attribute_state() const
{
	return m_region_Attribute_state;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getRegion_Attribute_stateMachine() const
{
	return m_region_Attribute_stateMachine;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getRegion_Attribute_subvertex() const
{
	return m_region_Attribute_subvertex;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getRegion_Attribute_transition() const
{
	return m_region_Attribute_transition;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRegion_Operation_belongsToPSM() const
{
	return m_region_Operation_belongsToPSM;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRegion_Operation_containingStateMachine() const
{
	return m_region_Operation_containingStateMachine;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRegion_Operation_deep_history_vertex_EDiagnosticChain_EMap() const
{
	return m_region_Operation_deep_history_vertex_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRegion_Operation_initial_vertex_EDiagnosticChain_EMap() const
{
	return m_region_Operation_initial_vertex_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRegion_Operation_owned_EDiagnosticChain_EMap() const
{
	return m_region_Operation_owned_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRegion_Operation_redefinitionContext() const
{
	return m_region_Operation_redefinitionContext;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRegion_Operation_shallow_history_vertex_EDiagnosticChain_EMap() const
{
	return m_region_Operation_shallow_history_vertex_EDiagnosticChain_EMap;
}

// End Class Region

// Begin Class Relationship
std::shared_ptr<ecore::EClass> UmlPackageImpl::getRelationship_Class() const
{
	return m_relationship_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getRelationship_Attribute_relatedElement() const
{
	return m_relationship_Attribute_relatedElement;
}


// End Class Relationship

// Begin Class RemoveStructuralFeatureValueAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getRemoveStructuralFeatureValueAction_Class() const
{
	return m_removeStructuralFeatureValueAction_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getRemoveStructuralFeatureValueAction_Attribute_isRemoveDuplicates() const
{
	return m_removeStructuralFeatureValueAction_Attribute_isRemoveDuplicates;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getRemoveStructuralFeatureValueAction_Attribute_removeAt() const
{
	return m_removeStructuralFeatureValueAction_Attribute_removeAt;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRemoveStructuralFeatureValueAction_Operation_removeAt_and_value_EDiagnosticChain_EMap() const
{
	return m_removeStructuralFeatureValueAction_Operation_removeAt_and_value_EDiagnosticChain_EMap;
}

// End Class RemoveStructuralFeatureValueAction

// Begin Class RemoveVariableValueAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getRemoveVariableValueAction_Class() const
{
	return m_removeVariableValueAction_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getRemoveVariableValueAction_Attribute_isRemoveDuplicates() const
{
	return m_removeVariableValueAction_Attribute_isRemoveDuplicates;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getRemoveVariableValueAction_Attribute_removeAt() const
{
	return m_removeVariableValueAction_Attribute_removeAt;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getRemoveVariableValueAction_Operation_removeAt_and_value_EDiagnosticChain_EMap() const
{
	return m_removeVariableValueAction_Operation_removeAt_and_value_EDiagnosticChain_EMap;
}

// End Class RemoveVariableValueAction

// Begin Class ReplyAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getReplyAction_Class() const
{
	return m_replyAction_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getReplyAction_Attribute_replyToCall() const
{
	return m_replyAction_Attribute_replyToCall;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getReplyAction_Attribute_replyValue() const
{
	return m_replyAction_Attribute_replyValue;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getReplyAction_Attribute_returnInformation() const
{
	return m_replyAction_Attribute_returnInformation;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReplyAction_Operation_event_on_reply_to_call_trigger_EDiagnosticChain_EMap() const
{
	return m_replyAction_Operation_event_on_reply_to_call_trigger_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getReplyAction_Operation_pins_match_parameter_EDiagnosticChain_EMap() const
{
	return m_replyAction_Operation_pins_match_parameter_EDiagnosticChain_EMap;
}

// End Class ReplyAction

// Begin Class SendObjectAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getSendObjectAction_Class() const
{
	return m_sendObjectAction_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getSendObjectAction_Attribute_request() const
{
	return m_sendObjectAction_Attribute_request;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getSendObjectAction_Attribute_target() const
{
	return m_sendObjectAction_Attribute_target;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getSendObjectAction_Operation_type_target_pin_EDiagnosticChain_EMap() const
{
	return m_sendObjectAction_Operation_type_target_pin_EDiagnosticChain_EMap;
}

// End Class SendObjectAction

// Begin Class SendSignalAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getSendSignalAction_Class() const
{
	return m_sendSignalAction_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getSendSignalAction_Attribute_signal() const
{
	return m_sendSignalAction_Attribute_signal;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getSendSignalAction_Attribute_target() const
{
	return m_sendSignalAction_Attribute_target;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getSendSignalAction_Operation_number_order_EDiagnosticChain_EMap() const
{
	return m_sendSignalAction_Operation_number_order_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getSendSignalAction_Operation_type_ordering_multiplicity_EDiagnosticChain_EMap() const
{
	return m_sendSignalAction_Operation_type_ordering_multiplicity_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getSendSignalAction_Operation_type_target_pin_EDiagnosticChain_EMap() const
{
	return m_sendSignalAction_Operation_type_target_pin_EDiagnosticChain_EMap;
}

// End Class SendSignalAction

// Begin Class SequenceNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getSequenceNode_Class() const
{
	return m_sequenceNode_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getSequenceNode_Attribute_executableNode() const
{
	return m_sequenceNode_Attribute_executableNode;
}


// End Class SequenceNode

// Begin Class Signal
std::shared_ptr<ecore::EClass> UmlPackageImpl::getSignal_Class() const
{
	return m_signal_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getSignal_Attribute_ownedAttribute() const
{
	return m_signal_Attribute_ownedAttribute;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getSignal_Operation_createOwnedAttribute_String_UnlimitedNatural() const
{
	return m_signal_Operation_createOwnedAttribute_String_UnlimitedNatural;
}

// End Class Signal

// Begin Class SignalEvent
std::shared_ptr<ecore::EClass> UmlPackageImpl::getSignalEvent_Class() const
{
	return m_signalEvent_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getSignalEvent_Attribute_signal() const
{
	return m_signalEvent_Attribute_signal;
}


// End Class SignalEvent

// Begin Class Slot
std::shared_ptr<ecore::EClass> UmlPackageImpl::getSlot_Class() const
{
	return m_slot_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getSlot_Attribute_definingFeature() const
{
	return m_slot_Attribute_definingFeature;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getSlot_Attribute_owningInstance() const
{
	return m_slot_Attribute_owningInstance;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getSlot_Attribute_value() const
{
	return m_slot_Attribute_value;
}


// End Class Slot

// Begin Class StartClassifierBehaviorAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getStartClassifierBehaviorAction_Class() const
{
	return m_startClassifierBehaviorAction_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getStartClassifierBehaviorAction_Attribute_object() const
{
	return m_startClassifierBehaviorAction_Attribute_object;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStartClassifierBehaviorAction_Operation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_startClassifierBehaviorAction_Operation_multiplicity_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStartClassifierBehaviorAction_Operation_type_has_classifier_EDiagnosticChain_EMap() const
{
	return m_startClassifierBehaviorAction_Operation_type_has_classifier_EDiagnosticChain_EMap;
}

// End Class StartClassifierBehaviorAction

// Begin Class StartObjectBehaviorAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getStartObjectBehaviorAction_Class() const
{
	return m_startObjectBehaviorAction_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getStartObjectBehaviorAction_Attribute_object() const
{
	return m_startObjectBehaviorAction_Attribute_object;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStartObjectBehaviorAction_Operation_behavior() const
{
	return m_startObjectBehaviorAction_Operation_behavior;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStartObjectBehaviorAction_Operation_multiplicity_of_object_EDiagnosticChain_EMap() const
{
	return m_startObjectBehaviorAction_Operation_multiplicity_of_object_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStartObjectBehaviorAction_Operation_no_onport_EDiagnosticChain_EMap() const
{
	return m_startObjectBehaviorAction_Operation_no_onport_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStartObjectBehaviorAction_Operation_type_of_object_EDiagnosticChain_EMap() const
{
	return m_startObjectBehaviorAction_Operation_type_of_object_EDiagnosticChain_EMap;
}

// End Class StartObjectBehaviorAction

// Begin Class State
std::shared_ptr<ecore::EClass> UmlPackageImpl::getState_Class() const
{
	return m_state_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getState_Attribute_isComposite() const
{
	return m_state_Attribute_isComposite;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getState_Attribute_isOrthogonal() const
{
	return m_state_Attribute_isOrthogonal;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getState_Attribute_isSimple() const
{
	return m_state_Attribute_isSimple;
}
std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getState_Attribute_isSubmachineState() const
{
	return m_state_Attribute_isSubmachineState;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getState_Attribute_connection() const
{
	return m_state_Attribute_connection;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getState_Attribute_connectionPoint() const
{
	return m_state_Attribute_connectionPoint;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getState_Attribute_deferrableTrigger() const
{
	return m_state_Attribute_deferrableTrigger;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getState_Attribute_doActivity() const
{
	return m_state_Attribute_doActivity;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getState_Attribute_entry() const
{
	return m_state_Attribute_entry;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getState_Attribute_exit() const
{
	return m_state_Attribute_exit;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getState_Attribute_redefinedState() const
{
	return m_state_Attribute_redefinedState;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getState_Attribute_region() const
{
	return m_state_Attribute_region;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getState_Attribute_stateInvariant() const
{
	return m_state_Attribute_stateInvariant;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getState_Attribute_submachine() const
{
	return m_state_Attribute_submachine;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getState_Operation_composite_states_EDiagnosticChain_EMap() const
{
	return m_state_Operation_composite_states_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getState_Operation_destinations_or_sources_of_transitions_EDiagnosticChain_EMap() const
{
	return m_state_Operation_destinations_or_sources_of_transitions_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getState_Operation_entry_or_exit_EDiagnosticChain_EMap() const
{
	return m_state_Operation_entry_or_exit_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getState_Operation_isComposite() const
{
	return m_state_Operation_isComposite;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getState_Operation_isOrthogonal() const
{
	return m_state_Operation_isOrthogonal;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getState_Operation_isSimple() const
{
	return m_state_Operation_isSimple;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getState_Operation_isSubmachineState() const
{
	return m_state_Operation_isSubmachineState;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getState_Operation_redefinitionContext() const
{
	return m_state_Operation_redefinitionContext;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getState_Operation_submachine_or_regions_EDiagnosticChain_EMap() const
{
	return m_state_Operation_submachine_or_regions_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getState_Operation_submachine_states_EDiagnosticChain_EMap() const
{
	return m_state_Operation_submachine_states_EDiagnosticChain_EMap;
}

// End Class State

// Begin Class StateInvariant
std::shared_ptr<ecore::EClass> UmlPackageImpl::getStateInvariant_Class() const
{
	return m_stateInvariant_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getStateInvariant_Attribute_invariant() const
{
	return m_stateInvariant_Attribute_invariant;
}


// End Class StateInvariant

// Begin Class StateMachine
std::shared_ptr<ecore::EClass> UmlPackageImpl::getStateMachine_Class() const
{
	return m_stateMachine_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getStateMachine_Attribute_connectionPoint() const
{
	return m_stateMachine_Attribute_connectionPoint;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getStateMachine_Attribute_extendedStateMachine() const
{
	return m_stateMachine_Attribute_extendedStateMachine;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getStateMachine_Attribute_region() const
{
	return m_stateMachine_Attribute_region;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getStateMachine_Attribute_submachineState() const
{
	return m_stateMachine_Attribute_submachineState;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStateMachine_Operation_lCA_Vertex_Vertex() const
{
	return m_stateMachine_Operation_lCA_Vertex_Vertex;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStateMachine_Operation_lCAState_Vertex_Vertex() const
{
	return m_stateMachine_Operation_lCAState_Vertex_Vertex;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStateMachine_Operation_ancestor_Vertex_Vertex() const
{
	return m_stateMachine_Operation_ancestor_Vertex_Vertex;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStateMachine_Operation_classifier_context_EDiagnosticChain_EMap() const
{
	return m_stateMachine_Operation_classifier_context_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStateMachine_Operation_connection_points_EDiagnosticChain_EMap() const
{
	return m_stateMachine_Operation_connection_points_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStateMachine_Operation_context_classifier_EDiagnosticChain_EMap() const
{
	return m_stateMachine_Operation_context_classifier_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStateMachine_Operation_method_EDiagnosticChain_EMap() const
{
	return m_stateMachine_Operation_method_EDiagnosticChain_EMap;
}

// End Class StateMachine

// Begin Class Stereotype
std::shared_ptr<ecore::EClass> UmlPackageImpl::getStereotype_Class() const
{
	return m_stereotype_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getStereotype_Attribute_icon() const
{
	return m_stereotype_Attribute_icon;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getStereotype_Attribute_profile() const
{
	return m_stereotype_Attribute_profile;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype_Operation_associationEndOwnership_EDiagnosticChain_EMap() const
{
	return m_stereotype_Operation_associationEndOwnership_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype_Operation_base_property_multiplicity_multiple_extension_EDiagnosticChain_EMap() const
{
	return m_stereotype_Operation_base_property_multiplicity_multiple_extension_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype_Operation_base_property_multiplicity_single_extension_EDiagnosticChain_EMap() const
{
	return m_stereotype_Operation_base_property_multiplicity_single_extension_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype_Operation_base_property_upper_bound_EDiagnosticChain_EMap() const
{
	return m_stereotype_Operation_base_property_upper_bound_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype_Operation_binaryAssociationsOnly_EDiagnosticChain_EMap() const
{
	return m_stereotype_Operation_binaryAssociationsOnly_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype_Operation_containingProfile() const
{
	return m_stereotype_Operation_containingProfile;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype_Operation_createExtension_Class_Boolean() const
{
	return m_stereotype_Operation_createExtension_Class_Boolean;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype_Operation_createIcon_String() const
{
	return m_stereotype_Operation_createIcon_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype_Operation_createIcon_String_String() const
{
	return m_stereotype_Operation_createIcon_String_String;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype_Operation_generalize_EDiagnosticChain_EMap() const
{
	return m_stereotype_Operation_generalize_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype_Operation_getAllExtendedMetaclasses() const
{
	return m_stereotype_Operation_getAllExtendedMetaclasses;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype_Operation_getDefinition() const
{
	return m_stereotype_Operation_getDefinition;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype_Operation_getExtendedMetaclasses() const
{
	return m_stereotype_Operation_getExtendedMetaclasses;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype_Operation_getKeyword() const
{
	return m_stereotype_Operation_getKeyword;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype_Operation_getKeyword_Boolean() const
{
	return m_stereotype_Operation_getKeyword_Boolean;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype_Operation_getProfile() const
{
	return m_stereotype_Operation_getProfile;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStereotype_Operation_name_not_clash_EDiagnosticChain_EMap() const
{
	return m_stereotype_Operation_name_not_clash_EDiagnosticChain_EMap;
}

// End Class Stereotype

// Begin Class StringExpression
std::shared_ptr<ecore::EClass> UmlPackageImpl::getStringExpression_Class() const
{
	return m_stringExpression_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getStringExpression_Attribute_owningExpression() const
{
	return m_stringExpression_Attribute_owningExpression;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getStringExpression_Attribute_subExpression() const
{
	return m_stringExpression_Attribute_subExpression;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStringExpression_Operation_operands_EDiagnosticChain_EMap() const
{
	return m_stringExpression_Operation_operands_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStringExpression_Operation_subexpressions_EDiagnosticChain_EMap() const
{
	return m_stringExpression_Operation_subexpressions_EDiagnosticChain_EMap;
}

// End Class StringExpression

// Begin Class StructuralFeature
std::shared_ptr<ecore::EClass> UmlPackageImpl::getStructuralFeature_Class() const
{
	return m_structuralFeature_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getStructuralFeature_Attribute_isReadOnly() const
{
	return m_structuralFeature_Attribute_isReadOnly;
}



// End Class StructuralFeature

// Begin Class StructuralFeatureAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getStructuralFeatureAction_Class() const
{
	return m_structuralFeatureAction_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getStructuralFeatureAction_Attribute_object() const
{
	return m_structuralFeatureAction_Attribute_object;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getStructuralFeatureAction_Attribute_structuralFeature() const
{
	return m_structuralFeatureAction_Attribute_structuralFeature;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStructuralFeatureAction_Operation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_structuralFeatureAction_Operation_multiplicity_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStructuralFeatureAction_Operation_not_static_EDiagnosticChain_EMap() const
{
	return m_structuralFeatureAction_Operation_not_static_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStructuralFeatureAction_Operation_object_type_EDiagnosticChain_EMap() const
{
	return m_structuralFeatureAction_Operation_object_type_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStructuralFeatureAction_Operation_one_featuring_classifier_EDiagnosticChain_EMap() const
{
	return m_structuralFeatureAction_Operation_one_featuring_classifier_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStructuralFeatureAction_Operation_visibility_EDiagnosticChain_EMap() const
{
	return m_structuralFeatureAction_Operation_visibility_EDiagnosticChain_EMap;
}

// End Class StructuralFeatureAction

// Begin Class StructuredActivityNode
std::shared_ptr<ecore::EClass> UmlPackageImpl::getStructuredActivityNode_Class() const
{
	return m_structuredActivityNode_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getStructuredActivityNode_Attribute_mustIsolate() const
{
	return m_structuredActivityNode_Attribute_mustIsolate;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getStructuredActivityNode_Attribute_edge() const
{
	return m_structuredActivityNode_Attribute_edge;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getStructuredActivityNode_Attribute_node() const
{
	return m_structuredActivityNode_Attribute_node;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getStructuredActivityNode_Attribute_structuredNodeInput() const
{
	return m_structuredActivityNode_Attribute_structuredNodeInput;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getStructuredActivityNode_Attribute_structuredNodeOutput() const
{
	return m_structuredActivityNode_Attribute_structuredNodeOutput;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getStructuredActivityNode_Attribute_variable() const
{
	return m_structuredActivityNode_Attribute_variable;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStructuredActivityNode_Operation_edges_EDiagnosticChain_EMap() const
{
	return m_structuredActivityNode_Operation_edges_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStructuredActivityNode_Operation_input_pin_edges_EDiagnosticChain_EMap() const
{
	return m_structuredActivityNode_Operation_input_pin_edges_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStructuredActivityNode_Operation_output_pin_edges_EDiagnosticChain_EMap() const
{
	return m_structuredActivityNode_Operation_output_pin_edges_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStructuredActivityNode_Operation_sourceNodes() const
{
	return m_structuredActivityNode_Operation_sourceNodes;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStructuredActivityNode_Operation_targetNodes() const
{
	return m_structuredActivityNode_Operation_targetNodes;
}

// End Class StructuredActivityNode

// Begin Class StructuredClassifier
std::shared_ptr<ecore::EClass> UmlPackageImpl::getStructuredClassifier_Class() const
{
	return m_structuredClassifier_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getStructuredClassifier_Attribute_ownedAttribute() const
{
	return m_structuredClassifier_Attribute_ownedAttribute;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getStructuredClassifier_Attribute_ownedConnector() const
{
	return m_structuredClassifier_Attribute_ownedConnector;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getStructuredClassifier_Attribute_part() const
{
	return m_structuredClassifier_Attribute_part;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getStructuredClassifier_Attribute_role() const
{
	return m_structuredClassifier_Attribute_role;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStructuredClassifier_Operation_allRoles() const
{
	return m_structuredClassifier_Operation_allRoles;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStructuredClassifier_Operation_createOwnedAttribute_String_UnlimitedNatural() const
{
	return m_structuredClassifier_Operation_createOwnedAttribute_String_UnlimitedNatural;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getStructuredClassifier_Operation_getParts() const
{
	return m_structuredClassifier_Operation_getParts;
}

// End Class StructuredClassifier

// Begin Class Substitution
std::shared_ptr<ecore::EClass> UmlPackageImpl::getSubstitution_Class() const
{
	return m_substitution_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getSubstitution_Attribute_contract() const
{
	return m_substitution_Attribute_contract;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getSubstitution_Attribute_substitutingClassifier() const
{
	return m_substitution_Attribute_substitutingClassifier;
}


// End Class Substitution

// Begin Class TemplateBinding
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTemplateBinding_Class() const
{
	return m_templateBinding_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateBinding_Attribute_boundElement() const
{
	return m_templateBinding_Attribute_boundElement;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateBinding_Attribute_parameterSubstitution() const
{
	return m_templateBinding_Attribute_parameterSubstitution;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateBinding_Attribute_signature() const
{
	return m_templateBinding_Attribute_signature;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTemplateBinding_Operation_one_parameter_substitution_EDiagnosticChain_EMap() const
{
	return m_templateBinding_Operation_one_parameter_substitution_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTemplateBinding_Operation_parameter_substitution_formal_EDiagnosticChain_EMap() const
{
	return m_templateBinding_Operation_parameter_substitution_formal_EDiagnosticChain_EMap;
}

// End Class TemplateBinding

// Begin Class TemplateParameter
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTemplateParameter_Class() const
{
	return m_templateParameter_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateParameter_Attribute_default() const
{
	return m_templateParameter_Attribute_default;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateParameter_Attribute_ownedDefault() const
{
	return m_templateParameter_Attribute_ownedDefault;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateParameter_Attribute_ownedParameteredElement() const
{
	return m_templateParameter_Attribute_ownedParameteredElement;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateParameter_Attribute_parameteredElement() const
{
	return m_templateParameter_Attribute_parameteredElement;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateParameter_Attribute_signature() const
{
	return m_templateParameter_Attribute_signature;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTemplateParameter_Operation_must_be_compatible_EDiagnosticChain_EMap() const
{
	return m_templateParameter_Operation_must_be_compatible_EDiagnosticChain_EMap;
}

// End Class TemplateParameter

// Begin Class TemplateParameterSubstitution
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTemplateParameterSubstitution_Class() const
{
	return m_templateParameterSubstitution_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateParameterSubstitution_Attribute_actual() const
{
	return m_templateParameterSubstitution_Attribute_actual;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateParameterSubstitution_Attribute_formal() const
{
	return m_templateParameterSubstitution_Attribute_formal;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateParameterSubstitution_Attribute_ownedActual() const
{
	return m_templateParameterSubstitution_Attribute_ownedActual;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateParameterSubstitution_Attribute_templateBinding() const
{
	return m_templateParameterSubstitution_Attribute_templateBinding;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTemplateParameterSubstitution_Operation_must_be_compatible_EDiagnosticChain_EMap() const
{
	return m_templateParameterSubstitution_Operation_must_be_compatible_EDiagnosticChain_EMap;
}

// End Class TemplateParameterSubstitution

// Begin Class TemplateSignature
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTemplateSignature_Class() const
{
	return m_templateSignature_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateSignature_Attribute_ownedParameter() const
{
	return m_templateSignature_Attribute_ownedParameter;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateSignature_Attribute_parameter() const
{
	return m_templateSignature_Attribute_parameter;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateSignature_Attribute_template() const
{
	return m_templateSignature_Attribute_template;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTemplateSignature_Operation_own_elements_EDiagnosticChain_EMap() const
{
	return m_templateSignature_Operation_own_elements_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTemplateSignature_Operation_unique_parameters_EDiagnosticChain_EMap() const
{
	return m_templateSignature_Operation_unique_parameters_EDiagnosticChain_EMap;
}

// End Class TemplateSignature

// Begin Class TemplateableElement
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTemplateableElement_Class() const
{
	return m_templateableElement_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateableElement_Attribute_ownedTemplateSignature() const
{
	return m_templateableElement_Attribute_ownedTemplateSignature;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTemplateableElement_Attribute_templateBinding() const
{
	return m_templateableElement_Attribute_templateBinding;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTemplateableElement_Operation_isTemplate() const
{
	return m_templateableElement_Operation_isTemplate;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTemplateableElement_Operation_parameterableElements() const
{
	return m_templateableElement_Operation_parameterableElements;
}

// End Class TemplateableElement

// Begin Class TestIdentityAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTestIdentityAction_Class() const
{
	return m_testIdentityAction_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getTestIdentityAction_Attribute_first() const
{
	return m_testIdentityAction_Attribute_first;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTestIdentityAction_Attribute_result() const
{
	return m_testIdentityAction_Attribute_result;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTestIdentityAction_Attribute_second() const
{
	return m_testIdentityAction_Attribute_second;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTestIdentityAction_Operation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_testIdentityAction_Operation_multiplicity_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTestIdentityAction_Operation_no_type_EDiagnosticChain_EMap() const
{
	return m_testIdentityAction_Operation_no_type_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTestIdentityAction_Operation_result_is_boolean_EDiagnosticChain_EMap() const
{
	return m_testIdentityAction_Operation_result_is_boolean_EDiagnosticChain_EMap;
}

// End Class TestIdentityAction

// Begin Class TimeConstraint
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTimeConstraint_Class() const
{
	return m_timeConstraint_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getTimeConstraint_Attribute_firstEvent() const
{
	return m_timeConstraint_Attribute_firstEvent;
}


std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTimeConstraint_Operation_has_one_constrainedElement_EDiagnosticChain_EMap() const
{
	return m_timeConstraint_Operation_has_one_constrainedElement_EDiagnosticChain_EMap;
}

// End Class TimeConstraint

// Begin Class TimeEvent
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTimeEvent_Class() const
{
	return m_timeEvent_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getTimeEvent_Attribute_isRelative() const
{
	return m_timeEvent_Attribute_isRelative;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getTimeEvent_Attribute_when() const
{
	return m_timeEvent_Attribute_when;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTimeEvent_Operation_when_non_negative_EDiagnosticChain_EMap() const
{
	return m_timeEvent_Operation_when_non_negative_EDiagnosticChain_EMap;
}

// End Class TimeEvent

// Begin Class TimeExpression
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTimeExpression_Class() const
{
	return m_timeExpression_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getTimeExpression_Attribute_expr() const
{
	return m_timeExpression_Attribute_expr;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTimeExpression_Attribute_observation() const
{
	return m_timeExpression_Attribute_observation;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTimeExpression_Operation_no_expr_requires_observation_EDiagnosticChain_EMap() const
{
	return m_timeExpression_Operation_no_expr_requires_observation_EDiagnosticChain_EMap;
}

// End Class TimeExpression

// Begin Class TimeInterval
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTimeInterval_Class() const
{
	return m_timeInterval_Class;
}




// End Class TimeInterval

// Begin Class TimeObservation
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTimeObservation_Class() const
{
	return m_timeObservation_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getTimeObservation_Attribute_firstEvent() const
{
	return m_timeObservation_Attribute_firstEvent;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getTimeObservation_Attribute_event() const
{
	return m_timeObservation_Attribute_event;
}


// End Class TimeObservation

// Begin Class Transition
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTransition_Class() const
{
	return m_transition_Class;
}

std::shared_ptr<ecore::EAttribute> UmlPackageImpl::getTransition_Attribute_kind() const
{
	return m_transition_Attribute_kind;
}

std::shared_ptr<ecore::EReference> UmlPackageImpl::getTransition_Attribute_container() const
{
	return m_transition_Attribute_container;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTransition_Attribute_effect() const
{
	return m_transition_Attribute_effect;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTransition_Attribute_guard() const
{
	return m_transition_Attribute_guard;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTransition_Attribute_redefinedTransition() const
{
	return m_transition_Attribute_redefinedTransition;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTransition_Attribute_source() const
{
	return m_transition_Attribute_source;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTransition_Attribute_target() const
{
	return m_transition_Attribute_target;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTransition_Attribute_trigger() const
{
	return m_transition_Attribute_trigger;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTransition_Operation_containingStateMachine() const
{
	return m_transition_Operation_containingStateMachine;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTransition_Operation_fork_segment_guards_EDiagnosticChain_EMap() const
{
	return m_transition_Operation_fork_segment_guards_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTransition_Operation_fork_segment_state_EDiagnosticChain_EMap() const
{
	return m_transition_Operation_fork_segment_state_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTransition_Operation_initial_transition_EDiagnosticChain_EMap() const
{
	return m_transition_Operation_initial_transition_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTransition_Operation_join_segment_guards_EDiagnosticChain_EMap() const
{
	return m_transition_Operation_join_segment_guards_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTransition_Operation_join_segment_state_EDiagnosticChain_EMap() const
{
	return m_transition_Operation_join_segment_state_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTransition_Operation_outgoing_pseudostates_EDiagnosticChain_EMap() const
{
	return m_transition_Operation_outgoing_pseudostates_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTransition_Operation_redefinitionContext() const
{
	return m_transition_Operation_redefinitionContext;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTransition_Operation_state_is_external_EDiagnosticChain_EMap() const
{
	return m_transition_Operation_state_is_external_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTransition_Operation_state_is_internal_EDiagnosticChain_EMap() const
{
	return m_transition_Operation_state_is_internal_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTransition_Operation_state_is_local_EDiagnosticChain_EMap() const
{
	return m_transition_Operation_state_is_local_EDiagnosticChain_EMap;
}

// End Class Transition

// Begin Class Trigger
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTrigger_Class() const
{
	return m_trigger_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getTrigger_Attribute_event() const
{
	return m_trigger_Attribute_event;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getTrigger_Attribute_port() const
{
	return m_trigger_Attribute_port;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getTrigger_Operation_trigger_with_ports_EDiagnosticChain_EMap() const
{
	return m_trigger_Operation_trigger_with_ports_EDiagnosticChain_EMap;
}

// End Class Trigger

// Begin Class Type
std::shared_ptr<ecore::EClass> UmlPackageImpl::getType_Class() const
{
	return m_type_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getType_Attribute_package() const
{
	return m_type_Attribute_package;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getType_Operation_conformsTo_Type() const
{
	return m_type_Operation_conformsTo_Type;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getType_Operation_createAssociation_Boolean_UnlimitedNatural() const
{
	return m_type_Operation_createAssociation_Boolean_UnlimitedNatural;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getType_Operation_getAssociations() const
{
	return m_type_Operation_getAssociations;
}

// End Class Type

// Begin Class TypedElement
std::shared_ptr<ecore::EClass> UmlPackageImpl::getTypedElement_Class() const
{
	return m_typedElement_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getTypedElement_Attribute_type() const
{
	return m_typedElement_Attribute_type;
}


// End Class TypedElement

// Begin Class UnmarshallAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getUnmarshallAction_Class() const
{
	return m_unmarshallAction_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getUnmarshallAction_Attribute_object() const
{
	return m_unmarshallAction_Attribute_object;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getUnmarshallAction_Attribute_result() const
{
	return m_unmarshallAction_Attribute_result;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getUnmarshallAction_Attribute_unmarshallType() const
{
	return m_unmarshallAction_Attribute_unmarshallType;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getUnmarshallAction_Operation_multiplicity_of_object_EDiagnosticChain_EMap() const
{
	return m_unmarshallAction_Operation_multiplicity_of_object_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getUnmarshallAction_Operation_number_of_result_EDiagnosticChain_EMap() const
{
	return m_unmarshallAction_Operation_number_of_result_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getUnmarshallAction_Operation_object_type_EDiagnosticChain_EMap() const
{
	return m_unmarshallAction_Operation_object_type_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getUnmarshallAction_Operation_structural_feature_EDiagnosticChain_EMap() const
{
	return m_unmarshallAction_Operation_structural_feature_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getUnmarshallAction_Operation_type_ordering_and_multiplicity_EDiagnosticChain_EMap() const
{
	return m_unmarshallAction_Operation_type_ordering_and_multiplicity_EDiagnosticChain_EMap;
}

// End Class UnmarshallAction

// Begin Class Usage
std::shared_ptr<ecore::EClass> UmlPackageImpl::getUsage_Class() const
{
	return m_usage_Class;
}




// End Class Usage

// Begin Class UseCase
std::shared_ptr<ecore::EClass> UmlPackageImpl::getUseCase_Class() const
{
	return m_useCase_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getUseCase_Attribute_extend() const
{
	return m_useCase_Attribute_extend;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getUseCase_Attribute_extensionPoint() const
{
	return m_useCase_Attribute_extensionPoint;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getUseCase_Attribute_include() const
{
	return m_useCase_Attribute_include;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getUseCase_Attribute_subject() const
{
	return m_useCase_Attribute_subject;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getUseCase_Operation_allIncludedUseCases() const
{
	return m_useCase_Operation_allIncludedUseCases;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getUseCase_Operation_binary_associations_EDiagnosticChain_EMap() const
{
	return m_useCase_Operation_binary_associations_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getUseCase_Operation_cannot_include_self_EDiagnosticChain_EMap() const
{
	return m_useCase_Operation_cannot_include_self_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getUseCase_Operation_must_have_name_EDiagnosticChain_EMap() const
{
	return m_useCase_Operation_must_have_name_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getUseCase_Operation_no_association_to_use_case_EDiagnosticChain_EMap() const
{
	return m_useCase_Operation_no_association_to_use_case_EDiagnosticChain_EMap;
}

// End Class UseCase

// Begin Class ValuePin
std::shared_ptr<ecore::EClass> UmlPackageImpl::getValuePin_Class() const
{
	return m_valuePin_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getValuePin_Attribute_value() const
{
	return m_valuePin_Attribute_value;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getValuePin_Operation_compatible_type_EDiagnosticChain_EMap() const
{
	return m_valuePin_Operation_compatible_type_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getValuePin_Operation_no_incoming_edges_EDiagnosticChain_EMap() const
{
	return m_valuePin_Operation_no_incoming_edges_EDiagnosticChain_EMap;
}

// End Class ValuePin

// Begin Class ValueSpecification
std::shared_ptr<ecore::EClass> UmlPackageImpl::getValueSpecification_Class() const
{
	return m_valueSpecification_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getValueSpecification_Attribute_owningSlot() const
{
	return m_valueSpecification_Attribute_owningSlot;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getValueSpecification_Operation_booleanValue() const
{
	return m_valueSpecification_Operation_booleanValue;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getValueSpecification_Operation_integerValue() const
{
	return m_valueSpecification_Operation_integerValue;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getValueSpecification_Operation_isComputable() const
{
	return m_valueSpecification_Operation_isComputable;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getValueSpecification_Operation_isNull() const
{
	return m_valueSpecification_Operation_isNull;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getValueSpecification_Operation_realValue() const
{
	return m_valueSpecification_Operation_realValue;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getValueSpecification_Operation_stringValue() const
{
	return m_valueSpecification_Operation_stringValue;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getValueSpecification_Operation_unlimitedValue() const
{
	return m_valueSpecification_Operation_unlimitedValue;
}

// End Class ValueSpecification

// Begin Class ValueSpecificationAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getValueSpecificationAction_Class() const
{
	return m_valueSpecificationAction_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getValueSpecificationAction_Attribute_result() const
{
	return m_valueSpecificationAction_Attribute_result;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getValueSpecificationAction_Attribute_value() const
{
	return m_valueSpecificationAction_Attribute_value;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getValueSpecificationAction_Operation_compatible_type_EDiagnosticChain_EMap() const
{
	return m_valueSpecificationAction_Operation_compatible_type_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getValueSpecificationAction_Operation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_valueSpecificationAction_Operation_multiplicity_EDiagnosticChain_EMap;
}

// End Class ValueSpecificationAction

// Begin Class Variable
std::shared_ptr<ecore::EClass> UmlPackageImpl::getVariable_Class() const
{
	return m_variable_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getVariable_Attribute_activityScope() const
{
	return m_variable_Attribute_activityScope;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getVariable_Attribute_scope() const
{
	return m_variable_Attribute_scope;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getVariable_Operation_isAccessibleBy_Action() const
{
	return m_variable_Operation_isAccessibleBy_Action;
}

// End Class Variable

// Begin Class VariableAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getVariableAction_Class() const
{
	return m_variableAction_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getVariableAction_Attribute_variable() const
{
	return m_variableAction_Attribute_variable;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getVariableAction_Operation_scope_of_variable_EDiagnosticChain_EMap() const
{
	return m_variableAction_Operation_scope_of_variable_EDiagnosticChain_EMap;
}

// End Class VariableAction

// Begin Class Vertex
std::shared_ptr<ecore::EClass> UmlPackageImpl::getVertex_Class() const
{
	return m_vertex_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getVertex_Attribute_container() const
{
	return m_vertex_Attribute_container;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getVertex_Attribute_incoming() const
{
	return m_vertex_Attribute_incoming;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getVertex_Attribute_outgoing() const
{
	return m_vertex_Attribute_outgoing;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getVertex_Operation_containingStateMachine() const
{
	return m_vertex_Operation_containingStateMachine;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getVertex_Operation_getIncomings() const
{
	return m_vertex_Operation_getIncomings;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getVertex_Operation_getOutgoings() const
{
	return m_vertex_Operation_getOutgoings;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getVertex_Operation_isContainedInRegion_Region() const
{
	return m_vertex_Operation_isContainedInRegion_Region;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getVertex_Operation_isContainedInState_State() const
{
	return m_vertex_Operation_isContainedInState_State;
}

// End Class Vertex

// Begin Class WriteLinkAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getWriteLinkAction_Class() const
{
	return m_writeLinkAction_Class;
}



std::shared_ptr<ecore::EOperation> UmlPackageImpl::getWriteLinkAction_Operation_allow_access_EDiagnosticChain_EMap() const
{
	return m_writeLinkAction_Operation_allow_access_EDiagnosticChain_EMap;
}

// End Class WriteLinkAction

// Begin Class WriteStructuralFeatureAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getWriteStructuralFeatureAction_Class() const
{
	return m_writeStructuralFeatureAction_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getWriteStructuralFeatureAction_Attribute_result() const
{
	return m_writeStructuralFeatureAction_Attribute_result;
}
std::shared_ptr<ecore::EReference> UmlPackageImpl::getWriteStructuralFeatureAction_Attribute_value() const
{
	return m_writeStructuralFeatureAction_Attribute_value;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getWriteStructuralFeatureAction_Operation_multiplicity_of_result_EDiagnosticChain_EMap() const
{
	return m_writeStructuralFeatureAction_Operation_multiplicity_of_result_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getWriteStructuralFeatureAction_Operation_multiplicity_of_value_EDiagnosticChain_EMap() const
{
	return m_writeStructuralFeatureAction_Operation_multiplicity_of_value_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getWriteStructuralFeatureAction_Operation_type_of_result_EDiagnosticChain_EMap() const
{
	return m_writeStructuralFeatureAction_Operation_type_of_result_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getWriteStructuralFeatureAction_Operation_type_of_value_EDiagnosticChain_EMap() const
{
	return m_writeStructuralFeatureAction_Operation_type_of_value_EDiagnosticChain_EMap;
}

// End Class WriteStructuralFeatureAction

// Begin Class WriteVariableAction
std::shared_ptr<ecore::EClass> UmlPackageImpl::getWriteVariableAction_Class() const
{
	return m_writeVariableAction_Class;
}


std::shared_ptr<ecore::EReference> UmlPackageImpl::getWriteVariableAction_Attribute_value() const
{
	return m_writeVariableAction_Attribute_value;
}

std::shared_ptr<ecore::EOperation> UmlPackageImpl::getWriteVariableAction_Operation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_writeVariableAction_Operation_multiplicity_EDiagnosticChain_EMap;
}
std::shared_ptr<ecore::EOperation> UmlPackageImpl::getWriteVariableAction_Operation_value_type_EDiagnosticChain_EMap() const
{
	return m_writeVariableAction_Operation_value_type_EDiagnosticChain_EMap;
}

// End Class WriteVariableAction
std::shared_ptr<ecore::EEnum> UmlPackageImpl::getAggregationKind_Class() const
{
	return m_aggregationKind_Class;
}
std::shared_ptr<ecore::EEnum> UmlPackageImpl::getCallConcurrencyKind_Class() const
{
	return m_callConcurrencyKind_Class;
}
std::shared_ptr<ecore::EEnum> UmlPackageImpl::getConnectorKind_Class() const
{
	return m_connectorKind_Class;
}
std::shared_ptr<ecore::EEnum> UmlPackageImpl::getExpansionKind_Class() const
{
	return m_expansionKind_Class;
}
std::shared_ptr<ecore::EEnum> UmlPackageImpl::getInteractionOperatorKind_Class() const
{
	return m_interactionOperatorKind_Class;
}
std::shared_ptr<ecore::EEnum> UmlPackageImpl::getMessageKind_Class() const
{
	return m_messageKind_Class;
}
std::shared_ptr<ecore::EEnum> UmlPackageImpl::getMessageSort_Class() const
{
	return m_messageSort_Class;
}
std::shared_ptr<ecore::EEnum> UmlPackageImpl::getObjectNodeOrderingKind_Class() const
{
	return m_objectNodeOrderingKind_Class;
}
std::shared_ptr<ecore::EEnum> UmlPackageImpl::getParameterDirectionKind_Class() const
{
	return m_parameterDirectionKind_Class;
}
std::shared_ptr<ecore::EEnum> UmlPackageImpl::getParameterEffectKind_Class() const
{
	return m_parameterEffectKind_Class;
}
std::shared_ptr<ecore::EEnum> UmlPackageImpl::getPseudostateKind_Class() const
{
	return m_pseudostateKind_Class;
}
std::shared_ptr<ecore::EEnum> UmlPackageImpl::getTransitionKind_Class() const
{
	return m_transitionKind_Class;
}
std::shared_ptr<ecore::EEnum> UmlPackageImpl::getVisibilityKind_Class() const
{
	return m_visibilityKind_Class;
}

