#include "uml/impl/umlPackageImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EReference.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EEnum.hpp"
#include "ecore/EEnumLiteral.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"

//metamodel factory
#include "uml/umlFactory.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "types/typesPackage.hpp"

using namespace uml;

bool umlPackageImpl::isInited = false;

umlPackageImpl::umlPackageImpl()
{
	setEFactoryInstance(std::shared_ptr<ecore::EFactory >( umlFactory::eInstance()));
}

umlPackageImpl::~umlPackageImpl()
{
}

umlPackage* umlPackageImpl::create()
{
	if (isInited)
	{
		return umlPackage::eInstance().get();
	}
	isInited = true;
	 
    // Obtain or create package and create package meta-data objects
    umlPackageImpl * metaModelPackage = new umlPackageImpl();
    return metaModelPackage;
}

void umlPackageImpl::init(std::shared_ptr<ecore::EPackage> package)
{
    // Initialize created meta-data
	createPackageContents(package);
	setThisEPackagePtr(package);
    initializePackageContents();   
}



// Begin Class Abstraction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getAbstraction_Class() const
{
	return m_abstraction_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getAbstraction_Attribute_mapping() const
{
	return m_abstraction_Attribute_mapping;
}


// End Class Abstraction

// Begin Class AcceptCallAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getAcceptCallAction_Class() const
{
	return m_acceptCallAction_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getAcceptCallAction_Attribute_returnInformation() const
{
	return m_acceptCallAction_Attribute_returnInformation;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getAcceptCallAction_Operation_result_pins_EDiagnosticChain_EMap() const
{
	return m_acceptCallAction_Operation_result_pins_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getAcceptCallAction_Operation_trigger_call_event_EDiagnosticChain_EMap() const
{
	return m_acceptCallAction_Operation_trigger_call_event_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getAcceptCallAction_Operation_unmarshall_EDiagnosticChain_EMap() const
{
	return m_acceptCallAction_Operation_unmarshall_EDiagnosticChain_EMap;
}

// End Class AcceptCallAction

// Begin Class AcceptEventAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getAcceptEventAction_Class() const
{
	return m_acceptEventAction_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getAcceptEventAction_Attribute_isUnmarshall() const
{
	return m_acceptEventAction_Attribute_isUnmarshall;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getAcceptEventAction_Attribute_result() const
{
	return m_acceptEventAction_Attribute_result;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getAcceptEventAction_Attribute_trigger() const
{
	return m_acceptEventAction_Attribute_trigger;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getAcceptEventAction_Operation_conforming_type_EDiagnosticChain_EMap() const
{
	return m_acceptEventAction_Operation_conforming_type_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getAcceptEventAction_Operation_no_input_pins_EDiagnosticChain_EMap() const
{
	return m_acceptEventAction_Operation_no_input_pins_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getAcceptEventAction_Operation_no_output_pins_EDiagnosticChain_EMap() const
{
	return m_acceptEventAction_Operation_no_output_pins_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getAcceptEventAction_Operation_one_output_pin_EDiagnosticChain_EMap() const
{
	return m_acceptEventAction_Operation_one_output_pin_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getAcceptEventAction_Operation_unmarshall_signal_events_EDiagnosticChain_EMap() const
{
	return m_acceptEventAction_Operation_unmarshall_signal_events_EDiagnosticChain_EMap;
}

// End Class AcceptEventAction

// Begin Class Action
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getAction_Class() const
{
	return m_action_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getAction_Attribute_isLocallyReentrant() const
{
	return m_action_Attribute_isLocallyReentrant;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getAction_Attribute_context() const
{
	return m_action_Attribute_context;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getAction_Attribute_input() const
{
	return m_action_Attribute_input;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getAction_Attribute_localPostcondition() const
{
	return m_action_Attribute_localPostcondition;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getAction_Attribute_localPrecondition() const
{
	return m_action_Attribute_localPrecondition;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getAction_Attribute_output() const
{
	return m_action_Attribute_output;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getAction_Operation_allActions() const
{
	return m_action_Operation_allActions;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getAction_Operation_allOwnedNodes() const
{
	return m_action_Operation_allOwnedNodes;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getAction_Operation_containingBehavior() const
{
	return m_action_Operation_containingBehavior;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getAction_Operation_getContext() const
{
	return m_action_Operation_getContext;
}

// End Class Action

// Begin Class ActionExecutionSpecification
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getActionExecutionSpecification_Class() const
{
	return m_actionExecutionSpecification_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getActionExecutionSpecification_Attribute_action() const
{
	return m_actionExecutionSpecification_Attribute_action;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getActionExecutionSpecification_Operation_action_referenced_EDiagnosticChain_EMap() const
{
	return m_actionExecutionSpecification_Operation_action_referenced_EDiagnosticChain_EMap;
}

// End Class ActionExecutionSpecification

// Begin Class ActionInputPin
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getActionInputPin_Class() const
{
	return m_actionInputPin_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getActionInputPin_Attribute_fromAction() const
{
	return m_actionInputPin_Attribute_fromAction;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getActionInputPin_Operation_input_pin_EDiagnosticChain_EMap() const
{
	return m_actionInputPin_Operation_input_pin_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getActionInputPin_Operation_no_control_or_object_flow_EDiagnosticChain_EMap() const
{
	return m_actionInputPin_Operation_no_control_or_object_flow_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getActionInputPin_Operation_one_output_pin_EDiagnosticChain_EMap() const
{
	return m_actionInputPin_Operation_one_output_pin_EDiagnosticChain_EMap;
}

// End Class ActionInputPin

// Begin Class Activity
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getActivity_Class() const
{
	return m_activity_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getActivity_Attribute_isReadOnly() const
{
	return m_activity_Attribute_isReadOnly;
}
const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getActivity_Attribute_isSingleExecution() const
{
	return m_activity_Attribute_isSingleExecution;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getActivity_Attribute_edge() const
{
	return m_activity_Attribute_edge;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getActivity_Attribute_group() const
{
	return m_activity_Attribute_group;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getActivity_Attribute_node() const
{
	return m_activity_Attribute_node;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getActivity_Attribute_ownedGroup() const
{
	return m_activity_Attribute_ownedGroup;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getActivity_Attribute_ownedNode() const
{
	return m_activity_Attribute_ownedNode;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getActivity_Attribute_partition() const
{
	return m_activity_Attribute_partition;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getActivity_Attribute_structuredNode() const
{
	return m_activity_Attribute_structuredNode;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getActivity_Attribute_variable() const
{
	return m_activity_Attribute_variable;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getActivity_Operation_maximum_one_parameter_node_EDiagnosticChain_EMap() const
{
	return m_activity_Operation_maximum_one_parameter_node_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getActivity_Operation_maximum_two_parameter_nodes_EDiagnosticChain_EMap() const
{
	return m_activity_Operation_maximum_two_parameter_nodes_EDiagnosticChain_EMap;
}

// End Class Activity

// Begin Class ActivityEdge
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getActivityEdge_Class() const
{
	return m_activityEdge_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getActivityEdge_Attribute_activity() const
{
	return m_activityEdge_Attribute_activity;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getActivityEdge_Attribute_guard() const
{
	return m_activityEdge_Attribute_guard;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getActivityEdge_Attribute_inGroup() const
{
	return m_activityEdge_Attribute_inGroup;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getActivityEdge_Attribute_inPartition() const
{
	return m_activityEdge_Attribute_inPartition;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getActivityEdge_Attribute_inStructuredNode() const
{
	return m_activityEdge_Attribute_inStructuredNode;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getActivityEdge_Attribute_interrupts() const
{
	return m_activityEdge_Attribute_interrupts;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getActivityEdge_Attribute_redefinedEdge() const
{
	return m_activityEdge_Attribute_redefinedEdge;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getActivityEdge_Attribute_source() const
{
	return m_activityEdge_Attribute_source;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getActivityEdge_Attribute_target() const
{
	return m_activityEdge_Attribute_target;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getActivityEdge_Attribute_weight() const
{
	return m_activityEdge_Attribute_weight;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getActivityEdge_Operation_source_and_target_EDiagnosticChain_EMap() const
{
	return m_activityEdge_Operation_source_and_target_EDiagnosticChain_EMap;
}

// End Class ActivityEdge

// Begin Class ActivityFinalNode
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getActivityFinalNode_Class() const
{
	return m_activityFinalNode_Class;
}




// End Class ActivityFinalNode

// Begin Class ActivityGroup
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getActivityGroup_Class() const
{
	return m_activityGroup_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getActivityGroup_Attribute_containedEdge() const
{
	return m_activityGroup_Attribute_containedEdge;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getActivityGroup_Attribute_containedNode() const
{
	return m_activityGroup_Attribute_containedNode;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getActivityGroup_Attribute_inActivity() const
{
	return m_activityGroup_Attribute_inActivity;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getActivityGroup_Attribute_subgroup() const
{
	return m_activityGroup_Attribute_subgroup;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getActivityGroup_Attribute_superGroup() const
{
	return m_activityGroup_Attribute_superGroup;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getActivityGroup_Operation_containingActivity() const
{
	return m_activityGroup_Operation_containingActivity;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getActivityGroup_Operation_nodes_and_edges_EDiagnosticChain_EMap() const
{
	return m_activityGroup_Operation_nodes_and_edges_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getActivityGroup_Operation_not_contained_EDiagnosticChain_EMap() const
{
	return m_activityGroup_Operation_not_contained_EDiagnosticChain_EMap;
}

// End Class ActivityGroup

// Begin Class ActivityNode
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getActivityNode_Class() const
{
	return m_activityNode_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getActivityNode_Attribute_activity() const
{
	return m_activityNode_Attribute_activity;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getActivityNode_Attribute_inGroup() const
{
	return m_activityNode_Attribute_inGroup;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getActivityNode_Attribute_inInterruptibleRegion() const
{
	return m_activityNode_Attribute_inInterruptibleRegion;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getActivityNode_Attribute_inPartition() const
{
	return m_activityNode_Attribute_inPartition;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getActivityNode_Attribute_inStructuredNode() const
{
	return m_activityNode_Attribute_inStructuredNode;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getActivityNode_Attribute_incoming() const
{
	return m_activityNode_Attribute_incoming;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getActivityNode_Attribute_outgoing() const
{
	return m_activityNode_Attribute_outgoing;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getActivityNode_Attribute_redefinedNode() const
{
	return m_activityNode_Attribute_redefinedNode;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getActivityNode_Operation_containingActivity() const
{
	return m_activityNode_Operation_containingActivity;
}

// End Class ActivityNode

// Begin Class ActivityParameterNode
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getActivityParameterNode_Class() const
{
	return m_activityParameterNode_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getActivityParameterNode_Attribute_parameter() const
{
	return m_activityParameterNode_Attribute_parameter;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getActivityParameterNode_Operation_has_parameters_EDiagnosticChain_EMap() const
{
	return m_activityParameterNode_Operation_has_parameters_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getActivityParameterNode_Operation_no_edges_EDiagnosticChain_EMap() const
{
	return m_activityParameterNode_Operation_no_edges_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getActivityParameterNode_Operation_no_incoming_edges_EDiagnosticChain_EMap() const
{
	return m_activityParameterNode_Operation_no_incoming_edges_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getActivityParameterNode_Operation_no_outgoing_edges_EDiagnosticChain_EMap() const
{
	return m_activityParameterNode_Operation_no_outgoing_edges_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getActivityParameterNode_Operation_same_type_EDiagnosticChain_EMap() const
{
	return m_activityParameterNode_Operation_same_type_EDiagnosticChain_EMap;
}

// End Class ActivityParameterNode

// Begin Class ActivityPartition
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getActivityPartition_Class() const
{
	return m_activityPartition_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getActivityPartition_Attribute_isDimension() const
{
	return m_activityPartition_Attribute_isDimension;
}
const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getActivityPartition_Attribute_isExternal() const
{
	return m_activityPartition_Attribute_isExternal;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getActivityPartition_Attribute_edge() const
{
	return m_activityPartition_Attribute_edge;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getActivityPartition_Attribute_node() const
{
	return m_activityPartition_Attribute_node;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getActivityPartition_Attribute_represents() const
{
	return m_activityPartition_Attribute_represents;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getActivityPartition_Attribute_subpartition() const
{
	return m_activityPartition_Attribute_subpartition;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getActivityPartition_Attribute_superPartition() const
{
	return m_activityPartition_Attribute_superPartition;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getActivityPartition_Operation_dimension_not_contained_EDiagnosticChain_EMap() const
{
	return m_activityPartition_Operation_dimension_not_contained_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getActivityPartition_Operation_represents_classifier_EDiagnosticChain_EMap() const
{
	return m_activityPartition_Operation_represents_classifier_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getActivityPartition_Operation_represents_property_EDiagnosticChain_EMap() const
{
	return m_activityPartition_Operation_represents_property_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getActivityPartition_Operation_represents_property_and_is_contained_EDiagnosticChain_EMap() const
{
	return m_activityPartition_Operation_represents_property_and_is_contained_EDiagnosticChain_EMap;
}

// End Class ActivityPartition

// Begin Class Actor
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getActor_Class() const
{
	return m_actor_Class;
}



const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getActor_Operation_associations_EDiagnosticChain_EMap() const
{
	return m_actor_Operation_associations_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getActor_Operation_must_have_name_EDiagnosticChain_EMap() const
{
	return m_actor_Operation_must_have_name_EDiagnosticChain_EMap;
}

// End Class Actor

// Begin Class AddStructuralFeatureValueAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getAddStructuralFeatureValueAction_Class() const
{
	return m_addStructuralFeatureValueAction_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getAddStructuralFeatureValueAction_Attribute_isReplaceAll() const
{
	return m_addStructuralFeatureValueAction_Attribute_isReplaceAll;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getAddStructuralFeatureValueAction_Attribute_insertAt() const
{
	return m_addStructuralFeatureValueAction_Attribute_insertAt;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getAddStructuralFeatureValueAction_Operation_insertAt_pin_EDiagnosticChain_EMap() const
{
	return m_addStructuralFeatureValueAction_Operation_insertAt_pin_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getAddStructuralFeatureValueAction_Operation_required_value_EDiagnosticChain_EMap() const
{
	return m_addStructuralFeatureValueAction_Operation_required_value_EDiagnosticChain_EMap;
}

// End Class AddStructuralFeatureValueAction

// Begin Class AddVariableValueAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getAddVariableValueAction_Class() const
{
	return m_addVariableValueAction_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getAddVariableValueAction_Attribute_isReplaceAll() const
{
	return m_addVariableValueAction_Attribute_isReplaceAll;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getAddVariableValueAction_Attribute_insertAt() const
{
	return m_addVariableValueAction_Attribute_insertAt;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getAddVariableValueAction_Operation_insertAt_pin_EDiagnosticChain_EMap() const
{
	return m_addVariableValueAction_Operation_insertAt_pin_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getAddVariableValueAction_Operation_required_value_EDiagnosticChain_EMap() const
{
	return m_addVariableValueAction_Operation_required_value_EDiagnosticChain_EMap;
}

// End Class AddVariableValueAction

// Begin Class AnyReceiveEvent
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getAnyReceiveEvent_Class() const
{
	return m_anyReceiveEvent_Class;
}




// End Class AnyReceiveEvent

// Begin Class Argument
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getArgument_Class() const
{
	return m_argument_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getArgument_Attribute_name() const
{
	return m_argument_Attribute_name;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getArgument_Attribute_value() const
{
	return m_argument_Attribute_value;
}


// End Class Argument

// Begin Class Artifact
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getArtifact_Class() const
{
	return m_artifact_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getArtifact_Attribute_fileName() const
{
	return m_artifact_Attribute_fileName;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getArtifact_Attribute_manifestation() const
{
	return m_artifact_Attribute_manifestation;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getArtifact_Attribute_nestedArtifact() const
{
	return m_artifact_Attribute_nestedArtifact;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getArtifact_Attribute_ownedAttribute() const
{
	return m_artifact_Attribute_ownedAttribute;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getArtifact_Attribute_ownedOperation() const
{
	return m_artifact_Attribute_ownedOperation;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getArtifact_Operation_createOwnedAttribute_String_UnlimitedNatural() const
{
	return m_artifact_Operation_createOwnedAttribute_String_UnlimitedNatural;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getArtifact_Operation_createOwnedOperation_String_Type() const
{
	return m_artifact_Operation_createOwnedOperation_String_Type;
}

// End Class Artifact

// Begin Class Association
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getAssociation_Class() const
{
	return m_association_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getAssociation_Attribute_isDerived() const
{
	return m_association_Attribute_isDerived;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getAssociation_Attribute_endType() const
{
	return m_association_Attribute_endType;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getAssociation_Attribute_memberEnd() const
{
	return m_association_Attribute_memberEnd;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getAssociation_Attribute_navigableOwnedEnd() const
{
	return m_association_Attribute_navigableOwnedEnd;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getAssociation_Attribute_ownedEnd() const
{
	return m_association_Attribute_ownedEnd;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getAssociation_Operation_association_ends_EDiagnosticChain_EMap() const
{
	return m_association_Operation_association_ends_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getAssociation_Operation_binary_associations_EDiagnosticChain_EMap() const
{
	return m_association_Operation_binary_associations_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getAssociation_Operation_ends_must_be_typed_EDiagnosticChain_EMap() const
{
	return m_association_Operation_ends_must_be_typed_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getAssociation_Operation_getEndTypes() const
{
	return m_association_Operation_getEndTypes;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getAssociation_Operation_isBinary() const
{
	return m_association_Operation_isBinary;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getAssociation_Operation_specialized_end_number_EDiagnosticChain_EMap() const
{
	return m_association_Operation_specialized_end_number_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getAssociation_Operation_specialized_end_types_EDiagnosticChain_EMap() const
{
	return m_association_Operation_specialized_end_types_EDiagnosticChain_EMap;
}

// End Class Association

// Begin Class AssociationClass
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getAssociationClass_Class() const
{
	return m_associationClass_Class;
}



const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getAssociationClass_Operation_cannot_be_defined_EDiagnosticChain_EMap() const
{
	return m_associationClass_Operation_cannot_be_defined_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getAssociationClass_Operation_disjoint_attributes_ends_EDiagnosticChain_EMap() const
{
	return m_associationClass_Operation_disjoint_attributes_ends_EDiagnosticChain_EMap;
}

// End Class AssociationClass

// Begin Class Behavior
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getBehavior_Class() const
{
	return m_behavior_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getBehavior_Attribute_isReentrant() const
{
	return m_behavior_Attribute_isReentrant;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getBehavior_Attribute_behavioredClassifier() const
{
	return m_behavior_Attribute_behavioredClassifier;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getBehavior_Attribute_context() const
{
	return m_behavior_Attribute_context;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getBehavior_Attribute_ownedParameter() const
{
	return m_behavior_Attribute_ownedParameter;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getBehavior_Attribute_ownedParameterSet() const
{
	return m_behavior_Attribute_ownedParameterSet;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getBehavior_Attribute_postcondition() const
{
	return m_behavior_Attribute_postcondition;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getBehavior_Attribute_precondition() const
{
	return m_behavior_Attribute_precondition;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getBehavior_Attribute_redefinedBehavior() const
{
	return m_behavior_Attribute_redefinedBehavior;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getBehavior_Attribute_specification() const
{
	return m_behavior_Attribute_specification;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getBehavior_Operation_behavioredClassifier_Element() const
{
	return m_behavior_Operation_behavioredClassifier_Element;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getBehavior_Operation_feature_of_context_classifier_EDiagnosticChain_EMap() const
{
	return m_behavior_Operation_feature_of_context_classifier_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getBehavior_Operation_getContext() const
{
	return m_behavior_Operation_getContext;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getBehavior_Operation_inputParameters() const
{
	return m_behavior_Operation_inputParameters;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getBehavior_Operation_most_one_behavior_EDiagnosticChain_EMap() const
{
	return m_behavior_Operation_most_one_behavior_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getBehavior_Operation_outputParameters() const
{
	return m_behavior_Operation_outputParameters;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getBehavior_Operation_parameters_match_EDiagnosticChain_EMap() const
{
	return m_behavior_Operation_parameters_match_EDiagnosticChain_EMap;
}

// End Class Behavior

// Begin Class BehaviorExecutionSpecification
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getBehaviorExecutionSpecification_Class() const
{
	return m_behaviorExecutionSpecification_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getBehaviorExecutionSpecification_Attribute_behavior() const
{
	return m_behaviorExecutionSpecification_Attribute_behavior;
}


// End Class BehaviorExecutionSpecification

// Begin Class BehavioralFeature
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getBehavioralFeature_Class() const
{
	return m_behavioralFeature_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getBehavioralFeature_Attribute_concurrency() const
{
	return m_behavioralFeature_Attribute_concurrency;
}
const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getBehavioralFeature_Attribute_isAbstract() const
{
	return m_behavioralFeature_Attribute_isAbstract;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getBehavioralFeature_Attribute_method() const
{
	return m_behavioralFeature_Attribute_method;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getBehavioralFeature_Attribute_ownedParameter() const
{
	return m_behavioralFeature_Attribute_ownedParameter;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getBehavioralFeature_Attribute_ownedParameterSet() const
{
	return m_behavioralFeature_Attribute_ownedParameterSet;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getBehavioralFeature_Attribute_raisedException() const
{
	return m_behavioralFeature_Attribute_raisedException;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getBehavioralFeature_Operation_abstract_no_method_EDiagnosticChain_EMap() const
{
	return m_behavioralFeature_Operation_abstract_no_method_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getBehavioralFeature_Operation_createReturnResult_String_Type() const
{
	return m_behavioralFeature_Operation_createReturnResult_String_Type;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getBehavioralFeature_Operation_inputParameters() const
{
	return m_behavioralFeature_Operation_inputParameters;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getBehavioralFeature_Operation_outputParameters() const
{
	return m_behavioralFeature_Operation_outputParameters;
}

// End Class BehavioralFeature

// Begin Class BehavioredClassifier
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getBehavioredClassifier_Class() const
{
	return m_behavioredClassifier_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getBehavioredClassifier_Attribute_classifierBehavior() const
{
	return m_behavioredClassifier_Attribute_classifierBehavior;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getBehavioredClassifier_Attribute_interfaceRealization() const
{
	return m_behavioredClassifier_Attribute_interfaceRealization;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getBehavioredClassifier_Attribute_ownedBehavior() const
{
	return m_behavioredClassifier_Attribute_ownedBehavior;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getBehavioredClassifier_Operation_class_behavior_EDiagnosticChain_EMap() const
{
	return m_behavioredClassifier_Operation_class_behavior_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getBehavioredClassifier_Operation_getAllImplementedInterfaces() const
{
	return m_behavioredClassifier_Operation_getAllImplementedInterfaces;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getBehavioredClassifier_Operation_getImplementedInterfaces() const
{
	return m_behavioredClassifier_Operation_getImplementedInterfaces;
}

// End Class BehavioredClassifier

// Begin Class BroadcastSignalAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getBroadcastSignalAction_Class() const
{
	return m_broadcastSignalAction_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getBroadcastSignalAction_Attribute_signal() const
{
	return m_broadcastSignalAction_Attribute_signal;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getBroadcastSignalAction_Operation_no_onport_EDiagnosticChain_EMap() const
{
	return m_broadcastSignalAction_Operation_no_onport_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getBroadcastSignalAction_Operation_number_of_arguments_EDiagnosticChain_EMap() const
{
	return m_broadcastSignalAction_Operation_number_of_arguments_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getBroadcastSignalAction_Operation_type_ordering_multiplicity_EDiagnosticChain_EMap() const
{
	return m_broadcastSignalAction_Operation_type_ordering_multiplicity_EDiagnosticChain_EMap;
}

// End Class BroadcastSignalAction

// Begin Class CallAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getCallAction_Class() const
{
	return m_callAction_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getCallAction_Attribute_isSynchronous() const
{
	return m_callAction_Attribute_isSynchronous;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getCallAction_Attribute_result() const
{
	return m_callAction_Attribute_result;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getCallAction_Operation_argument_pins_EDiagnosticChain_EMap() const
{
	return m_callAction_Operation_argument_pins_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getCallAction_Operation_inputParameters() const
{
	return m_callAction_Operation_inputParameters;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getCallAction_Operation_outputParameters() const
{
	return m_callAction_Operation_outputParameters;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getCallAction_Operation_result_pins_EDiagnosticChain_EMap() const
{
	return m_callAction_Operation_result_pins_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getCallAction_Operation_synchronous_call_EDiagnosticChain_EMap() const
{
	return m_callAction_Operation_synchronous_call_EDiagnosticChain_EMap;
}

// End Class CallAction

// Begin Class CallBehaviorAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getCallBehaviorAction_Class() const
{
	return m_callBehaviorAction_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getCallBehaviorAction_Attribute_behavior() const
{
	return m_callBehaviorAction_Attribute_behavior;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getCallBehaviorAction_Operation_no_onport_EDiagnosticChain_EMap() const
{
	return m_callBehaviorAction_Operation_no_onport_EDiagnosticChain_EMap;
}

// End Class CallBehaviorAction

// Begin Class CallEvent
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getCallEvent_Class() const
{
	return m_callEvent_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getCallEvent_Attribute_operation() const
{
	return m_callEvent_Attribute_operation;
}


// End Class CallEvent

// Begin Class CallOperationAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getCallOperationAction_Class() const
{
	return m_callOperationAction_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getCallOperationAction_Attribute_operation() const
{
	return m_callOperationAction_Attribute_operation;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getCallOperationAction_Attribute_target() const
{
	return m_callOperationAction_Attribute_target;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getCallOperationAction_Operation_type_target_pin_EDiagnosticChain_EMap() const
{
	return m_callOperationAction_Operation_type_target_pin_EDiagnosticChain_EMap;
}

// End Class CallOperationAction

// Begin Class CentralBufferNode
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getCentralBufferNode_Class() const
{
	return m_centralBufferNode_Class;
}




// End Class CentralBufferNode

// Begin Class ChangeEvent
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getChangeEvent_Class() const
{
	return m_changeEvent_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getChangeEvent_Attribute_changeExpression() const
{
	return m_changeEvent_Attribute_changeExpression;
}


// End Class ChangeEvent

// Begin Class Class
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getClass_Class() const
{
	return m_class_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getClass_Attribute_isActive() const
{
	return m_class_Attribute_isActive;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getClass_Attribute_extension() const
{
	return m_class_Attribute_extension;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getClass_Attribute_nestedClassifier() const
{
	return m_class_Attribute_nestedClassifier;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getClass_Attribute_ownedAttribute() const
{
	return m_class_Attribute_ownedAttribute;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getClass_Attribute_ownedOperation() const
{
	return m_class_Attribute_ownedOperation;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getClass_Attribute_ownedReception() const
{
	return m_class_Attribute_ownedReception;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getClass_Attribute_superClass() const
{
	return m_class_Attribute_superClass;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClass_Operation_createOwnedOperation_String_Type() const
{
	return m_class_Operation_createOwnedOperation_String_Type;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClass_Operation_getAllOperations() const
{
	return m_class_Operation_getAllOperations;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClass_Operation_getExtensions() const
{
	return m_class_Operation_getExtensions;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClass_Operation_getSuperClasses() const
{
	return m_class_Operation_getSuperClasses;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClass_Operation_isMetaclass() const
{
	return m_class_Operation_isMetaclass;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClass_Operation_passive_class_EDiagnosticChain_EMap() const
{
	return m_class_Operation_passive_class_EDiagnosticChain_EMap;
}

// End Class Class

// Begin Class Classifier
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getClassifier_Class() const
{
	return m_classifier_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getClassifier_Attribute_isAbstract() const
{
	return m_classifier_Attribute_isAbstract;
}
const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getClassifier_Attribute_isFinalSpecialization() const
{
	return m_classifier_Attribute_isFinalSpecialization;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getClassifier_Attribute_attribute() const
{
	return m_classifier_Attribute_attribute;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getClassifier_Attribute_collaborationUse() const
{
	return m_classifier_Attribute_collaborationUse;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getClassifier_Attribute_feature() const
{
	return m_classifier_Attribute_feature;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getClassifier_Attribute_general() const
{
	return m_classifier_Attribute_general;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getClassifier_Attribute_generalization() const
{
	return m_classifier_Attribute_generalization;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getClassifier_Attribute_inheritedMember() const
{
	return m_classifier_Attribute_inheritedMember;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getClassifier_Attribute_ownedUseCase() const
{
	return m_classifier_Attribute_ownedUseCase;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getClassifier_Attribute_powertypeExtent() const
{
	return m_classifier_Attribute_powertypeExtent;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getClassifier_Attribute_redefinedClassifier() const
{
	return m_classifier_Attribute_redefinedClassifier;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getClassifier_Attribute_representation() const
{
	return m_classifier_Attribute_representation;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getClassifier_Attribute_substitution() const
{
	return m_classifier_Attribute_substitution;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getClassifier_Attribute_useCase() const
{
	return m_classifier_Attribute_useCase;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClassifier_Operation_allAttributes() const
{
	return m_classifier_Operation_allAttributes;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClassifier_Operation_allFeatures() const
{
	return m_classifier_Operation_allFeatures;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClassifier_Operation_allParents() const
{
	return m_classifier_Operation_allParents;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClassifier_Operation_allRealizedInterfaces() const
{
	return m_classifier_Operation_allRealizedInterfaces;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClassifier_Operation_allSlottableFeatures() const
{
	return m_classifier_Operation_allSlottableFeatures;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClassifier_Operation_allUsedInterfaces() const
{
	return m_classifier_Operation_allUsedInterfaces;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClassifier_Operation_directlyRealizedInterfaces() const
{
	return m_classifier_Operation_directlyRealizedInterfaces;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClassifier_Operation_directlyUsedInterfaces() const
{
	return m_classifier_Operation_directlyUsedInterfaces;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClassifier_Operation_getAllAttributes() const
{
	return m_classifier_Operation_getAllAttributes;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClassifier_Operation_getAllOperations() const
{
	return m_classifier_Operation_getAllOperations;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClassifier_Operation_getAllUsedInterfaces() const
{
	return m_classifier_Operation_getAllUsedInterfaces;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClassifier_Operation_getGenerals() const
{
	return m_classifier_Operation_getGenerals;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClassifier_Operation_getInheritedMembers() const
{
	return m_classifier_Operation_getInheritedMembers;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClassifier_Operation_getOperation_String_Type() const
{
	return m_classifier_Operation_getOperation_String_Type;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClassifier_Operation_getOperation_String_Boolean() const
{
	return m_classifier_Operation_getOperation_String_Boolean;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClassifier_Operation_getOperations() const
{
	return m_classifier_Operation_getOperations;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClassifier_Operation_getPropertyValue_String() const
{
	return m_classifier_Operation_getPropertyValue_String;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClassifier_Operation_getUsedInterfaces() const
{
	return m_classifier_Operation_getUsedInterfaces;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClassifier_Operation_hasVisibilityOf_NamedElement() const
{
	return m_classifier_Operation_hasVisibilityOf_NamedElement;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClassifier_Operation_inherit_NamedElement() const
{
	return m_classifier_Operation_inherit_NamedElement;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClassifier_Operation_inheritableMembers_Classifier() const
{
	return m_classifier_Operation_inheritableMembers_Classifier;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClassifier_Operation_isSubstitutableFor_Classifier() const
{
	return m_classifier_Operation_isSubstitutableFor_Classifier;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClassifier_Operation_maps_to_generalization_set_EDiagnosticChain_EMap() const
{
	return m_classifier_Operation_maps_to_generalization_set_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClassifier_Operation_maySpecializeType_Classifier() const
{
	return m_classifier_Operation_maySpecializeType_Classifier;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClassifier_Operation_no_cycles_in_generalization_EDiagnosticChain_EMap() const
{
	return m_classifier_Operation_no_cycles_in_generalization_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClassifier_Operation_non_final_parents_EDiagnosticChain_EMap() const
{
	return m_classifier_Operation_non_final_parents_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClassifier_Operation_parents() const
{
	return m_classifier_Operation_parents;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClassifier_Operation_specialize_type_EDiagnosticChain_EMap() const
{
	return m_classifier_Operation_specialize_type_EDiagnosticChain_EMap;
}

// End Class Classifier

// Begin Class ClassifierTemplateParameter
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getClassifierTemplateParameter_Class() const
{
	return m_classifierTemplateParameter_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getClassifierTemplateParameter_Attribute_allowSubstitutable() const
{
	return m_classifierTemplateParameter_Attribute_allowSubstitutable;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getClassifierTemplateParameter_Attribute_constrainingClassifier() const
{
	return m_classifierTemplateParameter_Attribute_constrainingClassifier;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClassifierTemplateParameter_Operation_actual_is_classifier_EDiagnosticChain_EMap() const
{
	return m_classifierTemplateParameter_Operation_actual_is_classifier_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClassifierTemplateParameter_Operation_constraining_classifiers_constrain_args_EDiagnosticChain_EMap() const
{
	return m_classifierTemplateParameter_Operation_constraining_classifiers_constrain_args_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClassifierTemplateParameter_Operation_constraining_classifiers_constrain_parametered_element_EDiagnosticChain_EMap() const
{
	return m_classifierTemplateParameter_Operation_constraining_classifiers_constrain_parametered_element_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClassifierTemplateParameter_Operation_has_constraining_classifier_EDiagnosticChain_EMap() const
{
	return m_classifierTemplateParameter_Operation_has_constraining_classifier_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClassifierTemplateParameter_Operation_matching_abstract_EDiagnosticChain_EMap() const
{
	return m_classifierTemplateParameter_Operation_matching_abstract_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClassifierTemplateParameter_Operation_parametered_element_no_features_EDiagnosticChain_EMap() const
{
	return m_classifierTemplateParameter_Operation_parametered_element_no_features_EDiagnosticChain_EMap;
}

// End Class ClassifierTemplateParameter

// Begin Class Clause
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getClause_Class() const
{
	return m_clause_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getClause_Attribute_body() const
{
	return m_clause_Attribute_body;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getClause_Attribute_bodyOutput() const
{
	return m_clause_Attribute_bodyOutput;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getClause_Attribute_decider() const
{
	return m_clause_Attribute_decider;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getClause_Attribute_predecessorClause() const
{
	return m_clause_Attribute_predecessorClause;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getClause_Attribute_successorClause() const
{
	return m_clause_Attribute_successorClause;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getClause_Attribute_test() const
{
	return m_clause_Attribute_test;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClause_Operation_body_output_pins_EDiagnosticChain_EMap() const
{
	return m_clause_Operation_body_output_pins_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClause_Operation_decider_output_EDiagnosticChain_EMap() const
{
	return m_clause_Operation_decider_output_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClause_Operation_test_and_body_EDiagnosticChain_EMap() const
{
	return m_clause_Operation_test_and_body_EDiagnosticChain_EMap;
}

// End Class Clause

// Begin Class ClearAssociationAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getClearAssociationAction_Class() const
{
	return m_clearAssociationAction_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getClearAssociationAction_Attribute_association() const
{
	return m_clearAssociationAction_Attribute_association;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getClearAssociationAction_Attribute_object() const
{
	return m_clearAssociationAction_Attribute_object;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClearAssociationAction_Operation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_clearAssociationAction_Operation_multiplicity_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClearAssociationAction_Operation_same_type_EDiagnosticChain_EMap() const
{
	return m_clearAssociationAction_Operation_same_type_EDiagnosticChain_EMap;
}

// End Class ClearAssociationAction

// Begin Class ClearStructuralFeatureAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getClearStructuralFeatureAction_Class() const
{
	return m_clearStructuralFeatureAction_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getClearStructuralFeatureAction_Attribute_result() const
{
	return m_clearStructuralFeatureAction_Attribute_result;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClearStructuralFeatureAction_Operation_multiplicity_of_result_EDiagnosticChain_EMap() const
{
	return m_clearStructuralFeatureAction_Operation_multiplicity_of_result_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getClearStructuralFeatureAction_Operation_type_of_result_EDiagnosticChain_EMap() const
{
	return m_clearStructuralFeatureAction_Operation_type_of_result_EDiagnosticChain_EMap;
}

// End Class ClearStructuralFeatureAction

// Begin Class ClearVariableAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getClearVariableAction_Class() const
{
	return m_clearVariableAction_Class;
}




// End Class ClearVariableAction

// Begin Class Collaboration
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getCollaboration_Class() const
{
	return m_collaboration_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getCollaboration_Attribute_collaborationRole() const
{
	return m_collaboration_Attribute_collaborationRole;
}


// End Class Collaboration

// Begin Class CollaborationUse
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getCollaborationUse_Class() const
{
	return m_collaborationUse_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getCollaborationUse_Attribute_roleBinding() const
{
	return m_collaborationUse_Attribute_roleBinding;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getCollaborationUse_Attribute_type() const
{
	return m_collaborationUse_Attribute_type;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getCollaborationUse_Operation_client_elements_EDiagnosticChain_EMap() const
{
	return m_collaborationUse_Operation_client_elements_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getCollaborationUse_Operation_connectors_EDiagnosticChain_EMap() const
{
	return m_collaborationUse_Operation_connectors_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getCollaborationUse_Operation_every_role_EDiagnosticChain_EMap() const
{
	return m_collaborationUse_Operation_every_role_EDiagnosticChain_EMap;
}

// End Class CollaborationUse

// Begin Class CombinedFragment
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getCombinedFragment_Class() const
{
	return m_combinedFragment_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getCombinedFragment_Attribute_interactionOperator() const
{
	return m_combinedFragment_Attribute_interactionOperator;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getCombinedFragment_Attribute_cfragmentGate() const
{
	return m_combinedFragment_Attribute_cfragmentGate;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getCombinedFragment_Attribute_operand() const
{
	return m_combinedFragment_Attribute_operand;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getCombinedFragment_Operation_break__EDiagnosticChain_EMap() const
{
	return m_combinedFragment_Operation_break__EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getCombinedFragment_Operation_consider_and_ignore_EDiagnosticChain_EMap() const
{
	return m_combinedFragment_Operation_consider_and_ignore_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getCombinedFragment_Operation_opt_loop_break_neg_EDiagnosticChain_EMap() const
{
	return m_combinedFragment_Operation_opt_loop_break_neg_EDiagnosticChain_EMap;
}

// End Class CombinedFragment

// Begin Class Comment
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getComment_Class() const
{
	return m_comment_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getComment_Attribute_body() const
{
	return m_comment_Attribute_body;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getComment_Attribute_annotatedElement() const
{
	return m_comment_Attribute_annotatedElement;
}


// End Class Comment

// Begin Class CommunicationPath
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getCommunicationPath_Class() const
{
	return m_communicationPath_Class;
}




// End Class CommunicationPath

// Begin Class Component
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getComponent_Class() const
{
	return m_component_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getComponent_Attribute_isIndirectlyInstantiated() const
{
	return m_component_Attribute_isIndirectlyInstantiated;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getComponent_Attribute_packagedElement() const
{
	return m_component_Attribute_packagedElement;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getComponent_Attribute_provided() const
{
	return m_component_Attribute_provided;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getComponent_Attribute_realization() const
{
	return m_component_Attribute_realization;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getComponent_Attribute_required() const
{
	return m_component_Attribute_required;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getComponent_Operation_createOwnedClass_String_Boolean() const
{
	return m_component_Operation_createOwnedClass_String_Boolean;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getComponent_Operation_createOwnedEnumeration_String() const
{
	return m_component_Operation_createOwnedEnumeration_String;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getComponent_Operation_createOwnedInterface_String() const
{
	return m_component_Operation_createOwnedInterface_String;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getComponent_Operation_createOwnedPrimitiveType_String() const
{
	return m_component_Operation_createOwnedPrimitiveType_String;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getComponent_Operation_getProvideds() const
{
	return m_component_Operation_getProvideds;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getComponent_Operation_getRequireds() const
{
	return m_component_Operation_getRequireds;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getComponent_Operation_no_nested_classifiers_EDiagnosticChain_EMap() const
{
	return m_component_Operation_no_nested_classifiers_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getComponent_Operation_no_packaged_elements_EDiagnosticChain_EMap() const
{
	return m_component_Operation_no_packaged_elements_EDiagnosticChain_EMap;
}

// End Class Component

// Begin Class ComponentRealization
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getComponentRealization_Class() const
{
	return m_componentRealization_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getComponentRealization_Attribute_abstraction() const
{
	return m_componentRealization_Attribute_abstraction;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getComponentRealization_Attribute_realizingClassifier() const
{
	return m_componentRealization_Attribute_realizingClassifier;
}


// End Class ComponentRealization

// Begin Class ConditionalNode
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getConditionalNode_Class() const
{
	return m_conditionalNode_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getConditionalNode_Attribute_isAssured() const
{
	return m_conditionalNode_Attribute_isAssured;
}
const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getConditionalNode_Attribute_isDeterminate() const
{
	return m_conditionalNode_Attribute_isDeterminate;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getConditionalNode_Attribute_clause() const
{
	return m_conditionalNode_Attribute_clause;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getConditionalNode_Attribute_result() const
{
	return m_conditionalNode_Attribute_result;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getConditionalNode_Operation_clause_no_predecessor_EDiagnosticChain_EMap() const
{
	return m_conditionalNode_Operation_clause_no_predecessor_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getConditionalNode_Operation_executable_nodes_EDiagnosticChain_EMap() const
{
	return m_conditionalNode_Operation_executable_nodes_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getConditionalNode_Operation_matching_output_pins_EDiagnosticChain_EMap() const
{
	return m_conditionalNode_Operation_matching_output_pins_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getConditionalNode_Operation_no_input_pins_EDiagnosticChain_EMap() const
{
	return m_conditionalNode_Operation_no_input_pins_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getConditionalNode_Operation_one_clause_with_executable_node_EDiagnosticChain_EMap() const
{
	return m_conditionalNode_Operation_one_clause_with_executable_node_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getConditionalNode_Operation_result_no_incoming_EDiagnosticChain_EMap() const
{
	return m_conditionalNode_Operation_result_no_incoming_EDiagnosticChain_EMap;
}

// End Class ConditionalNode

// Begin Class ConnectableElement
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getConnectableElement_Class() const
{
	return m_connectableElement_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getConnectableElement_Attribute_end() const
{
	return m_connectableElement_Attribute_end;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getConnectableElement_Operation_getEnds() const
{
	return m_connectableElement_Operation_getEnds;
}

// End Class ConnectableElement

// Begin Class ConnectableElementTemplateParameter
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getConnectableElementTemplateParameter_Class() const
{
	return m_connectableElementTemplateParameter_Class;
}




// End Class ConnectableElementTemplateParameter

// Begin Class ConnectionPointReference
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getConnectionPointReference_Class() const
{
	return m_connectionPointReference_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getConnectionPointReference_Attribute_entry() const
{
	return m_connectionPointReference_Attribute_entry;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getConnectionPointReference_Attribute_exit() const
{
	return m_connectionPointReference_Attribute_exit;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getConnectionPointReference_Attribute_state() const
{
	return m_connectionPointReference_Attribute_state;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getConnectionPointReference_Operation_entry_pseudostates_EDiagnosticChain_EMap() const
{
	return m_connectionPointReference_Operation_entry_pseudostates_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getConnectionPointReference_Operation_exit_pseudostates_EDiagnosticChain_EMap() const
{
	return m_connectionPointReference_Operation_exit_pseudostates_EDiagnosticChain_EMap;
}

// End Class ConnectionPointReference

// Begin Class Connector
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getConnector_Class() const
{
	return m_connector_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getConnector_Attribute_kind() const
{
	return m_connector_Attribute_kind;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getConnector_Attribute_contract() const
{
	return m_connector_Attribute_contract;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getConnector_Attribute_end() const
{
	return m_connector_Attribute_end;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getConnector_Attribute_redefinedConnector() const
{
	return m_connector_Attribute_redefinedConnector;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getConnector_Attribute_structuredClassifier() const
{
	return m_connector_Attribute_structuredClassifier;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getConnector_Attribute_type() const
{
	return m_connector_Attribute_type;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getConnector_Operation_getKind() const
{
	return m_connector_Operation_getKind;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getConnector_Operation_roles_EDiagnosticChain_EMap() const
{
	return m_connector_Operation_roles_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getConnector_Operation_types_EDiagnosticChain_EMap() const
{
	return m_connector_Operation_types_EDiagnosticChain_EMap;
}

// End Class Connector

// Begin Class ConnectorEnd
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getConnectorEnd_Class() const
{
	return m_connectorEnd_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getConnectorEnd_Attribute_connector() const
{
	return m_connectorEnd_Attribute_connector;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getConnectorEnd_Attribute_definingEnd() const
{
	return m_connectorEnd_Attribute_definingEnd;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getConnectorEnd_Attribute_partWithPort() const
{
	return m_connectorEnd_Attribute_partWithPort;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getConnectorEnd_Attribute_role() const
{
	return m_connectorEnd_Attribute_role;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getConnectorEnd_Operation_getDefiningEnd() const
{
	return m_connectorEnd_Operation_getDefiningEnd;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getConnectorEnd_Operation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_connectorEnd_Operation_multiplicity_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getConnectorEnd_Operation_part_with_port_empty_EDiagnosticChain_EMap() const
{
	return m_connectorEnd_Operation_part_with_port_empty_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getConnectorEnd_Operation_role_and_part_with_port_EDiagnosticChain_EMap() const
{
	return m_connectorEnd_Operation_role_and_part_with_port_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getConnectorEnd_Operation_self_part_with_port_EDiagnosticChain_EMap() const
{
	return m_connectorEnd_Operation_self_part_with_port_EDiagnosticChain_EMap;
}

// End Class ConnectorEnd

// Begin Class ConsiderIgnoreFragment
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getConsiderIgnoreFragment_Class() const
{
	return m_considerIgnoreFragment_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getConsiderIgnoreFragment_Attribute_message() const
{
	return m_considerIgnoreFragment_Attribute_message;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getConsiderIgnoreFragment_Operation_consider_or_ignore_EDiagnosticChain_EMap() const
{
	return m_considerIgnoreFragment_Operation_consider_or_ignore_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getConsiderIgnoreFragment_Operation_type_EDiagnosticChain_EMap() const
{
	return m_considerIgnoreFragment_Operation_type_EDiagnosticChain_EMap;
}

// End Class ConsiderIgnoreFragment

// Begin Class Constraint
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getConstraint_Class() const
{
	return m_constraint_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getConstraint_Attribute_constrainedElement() const
{
	return m_constraint_Attribute_constrainedElement;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getConstraint_Attribute_context() const
{
	return m_constraint_Attribute_context;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getConstraint_Attribute_specification() const
{
	return m_constraint_Attribute_specification;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getConstraint_Operation_boolean_value_EDiagnosticChain_EMap() const
{
	return m_constraint_Operation_boolean_value_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getConstraint_Operation_no_side_effects_EDiagnosticChain_EMap() const
{
	return m_constraint_Operation_no_side_effects_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getConstraint_Operation_not_apply_to_self_EDiagnosticChain_EMap() const
{
	return m_constraint_Operation_not_apply_to_self_EDiagnosticChain_EMap;
}

// End Class Constraint

// Begin Class Continuation
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getContinuation_Class() const
{
	return m_continuation_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getContinuation_Attribute_setting() const
{
	return m_continuation_Attribute_setting;
}


const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getContinuation_Operation_first_or_last_interaction_fragment_EDiagnosticChain_EMap() const
{
	return m_continuation_Operation_first_or_last_interaction_fragment_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getContinuation_Operation_global_EDiagnosticChain_EMap() const
{
	return m_continuation_Operation_global_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getContinuation_Operation_same_name_EDiagnosticChain_EMap() const
{
	return m_continuation_Operation_same_name_EDiagnosticChain_EMap;
}

// End Class Continuation

// Begin Class ControlFlow
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getControlFlow_Class() const
{
	return m_controlFlow_Class;
}



const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getControlFlow_Operation_object_nodes_EDiagnosticChain_EMap() const
{
	return m_controlFlow_Operation_object_nodes_EDiagnosticChain_EMap;
}

// End Class ControlFlow

// Begin Class ControlNode
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getControlNode_Class() const
{
	return m_controlNode_Class;
}




// End Class ControlNode

// Begin Class CreateLinkAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getCreateLinkAction_Class() const
{
	return m_createLinkAction_Class;
}



const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getCreateLinkAction_Operation_association_not_abstract_EDiagnosticChain_EMap() const
{
	return m_createLinkAction_Operation_association_not_abstract_EDiagnosticChain_EMap;
}

// End Class CreateLinkAction

// Begin Class CreateLinkObjectAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getCreateLinkObjectAction_Class() const
{
	return m_createLinkObjectAction_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getCreateLinkObjectAction_Attribute_result() const
{
	return m_createLinkObjectAction_Attribute_result;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getCreateLinkObjectAction_Operation_association_class_EDiagnosticChain_EMap() const
{
	return m_createLinkObjectAction_Operation_association_class_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getCreateLinkObjectAction_Operation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_createLinkObjectAction_Operation_multiplicity_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getCreateLinkObjectAction_Operation_type_of_result_EDiagnosticChain_EMap() const
{
	return m_createLinkObjectAction_Operation_type_of_result_EDiagnosticChain_EMap;
}

// End Class CreateLinkObjectAction

// Begin Class CreateObjectAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getCreateObjectAction_Class() const
{
	return m_createObjectAction_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getCreateObjectAction_Attribute_classifier() const
{
	return m_createObjectAction_Attribute_classifier;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getCreateObjectAction_Attribute_result() const
{
	return m_createObjectAction_Attribute_result;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getCreateObjectAction_Operation_classifier_not_abstract_EDiagnosticChain_EMap() const
{
	return m_createObjectAction_Operation_classifier_not_abstract_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getCreateObjectAction_Operation_classifier_not_association_class_EDiagnosticChain_EMap() const
{
	return m_createObjectAction_Operation_classifier_not_association_class_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getCreateObjectAction_Operation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_createObjectAction_Operation_multiplicity_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getCreateObjectAction_Operation_same_type_EDiagnosticChain_EMap() const
{
	return m_createObjectAction_Operation_same_type_EDiagnosticChain_EMap;
}

// End Class CreateObjectAction

// Begin Class DataStoreNode
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getDataStoreNode_Class() const
{
	return m_dataStoreNode_Class;
}




// End Class DataStoreNode

// Begin Class DataType
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getDataType_Class() const
{
	return m_dataType_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getDataType_Attribute_ownedAttribute() const
{
	return m_dataType_Attribute_ownedAttribute;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getDataType_Attribute_ownedOperation() const
{
	return m_dataType_Attribute_ownedOperation;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getDataType_Operation_createOwnedAttribute_String_UnlimitedNatural() const
{
	return m_dataType_Operation_createOwnedAttribute_String_UnlimitedNatural;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getDataType_Operation_createOwnedOperation_String_Type() const
{
	return m_dataType_Operation_createOwnedOperation_String_Type;
}

// End Class DataType

// Begin Class DecisionNode
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getDecisionNode_Class() const
{
	return m_decisionNode_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getDecisionNode_Attribute_decisionInput() const
{
	return m_decisionNode_Attribute_decisionInput;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getDecisionNode_Attribute_decisionInputFlow() const
{
	return m_decisionNode_Attribute_decisionInputFlow;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getDecisionNode_Operation_decision_input_flow_incoming_EDiagnosticChain_EMap() const
{
	return m_decisionNode_Operation_decision_input_flow_incoming_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getDecisionNode_Operation_edges_EDiagnosticChain_EMap() const
{
	return m_decisionNode_Operation_edges_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getDecisionNode_Operation_incoming_control_one_input_parameter_EDiagnosticChain_EMap() const
{
	return m_decisionNode_Operation_incoming_control_one_input_parameter_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getDecisionNode_Operation_incoming_object_one_input_parameter_EDiagnosticChain_EMap() const
{
	return m_decisionNode_Operation_incoming_object_one_input_parameter_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getDecisionNode_Operation_incoming_outgoing_edges_EDiagnosticChain_EMap() const
{
	return m_decisionNode_Operation_incoming_outgoing_edges_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getDecisionNode_Operation_parameters_EDiagnosticChain_EMap() const
{
	return m_decisionNode_Operation_parameters_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getDecisionNode_Operation_two_input_parameters_EDiagnosticChain_EMap() const
{
	return m_decisionNode_Operation_two_input_parameters_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getDecisionNode_Operation_zero_input_parameters_EDiagnosticChain_EMap() const
{
	return m_decisionNode_Operation_zero_input_parameters_EDiagnosticChain_EMap;
}

// End Class DecisionNode

// Begin Class Dependency
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getDependency_Class() const
{
	return m_dependency_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getDependency_Attribute_client() const
{
	return m_dependency_Attribute_client;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getDependency_Attribute_supplier() const
{
	return m_dependency_Attribute_supplier;
}


// End Class Dependency

// Begin Class DeployedArtifact
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getDeployedArtifact_Class() const
{
	return m_deployedArtifact_Class;
}




// End Class DeployedArtifact

// Begin Class Deployment
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getDeployment_Class() const
{
	return m_deployment_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getDeployment_Attribute_configuration() const
{
	return m_deployment_Attribute_configuration;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getDeployment_Attribute_deployedArtifact() const
{
	return m_deployment_Attribute_deployedArtifact;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getDeployment_Attribute_location() const
{
	return m_deployment_Attribute_location;
}


// End Class Deployment

// Begin Class DeploymentSpecification
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getDeploymentSpecification_Class() const
{
	return m_deploymentSpecification_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getDeploymentSpecification_Attribute_deploymentLocation() const
{
	return m_deploymentSpecification_Attribute_deploymentLocation;
}
const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getDeploymentSpecification_Attribute_executionLocation() const
{
	return m_deploymentSpecification_Attribute_executionLocation;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getDeploymentSpecification_Attribute_deployment() const
{
	return m_deploymentSpecification_Attribute_deployment;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getDeploymentSpecification_Operation_deployed_elements_EDiagnosticChain_EMap() const
{
	return m_deploymentSpecification_Operation_deployed_elements_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getDeploymentSpecification_Operation_deployment_target_EDiagnosticChain_EMap() const
{
	return m_deploymentSpecification_Operation_deployment_target_EDiagnosticChain_EMap;
}

// End Class DeploymentSpecification

// Begin Class DeploymentTarget
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getDeploymentTarget_Class() const
{
	return m_deploymentTarget_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getDeploymentTarget_Attribute_deployedElement() const
{
	return m_deploymentTarget_Attribute_deployedElement;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getDeploymentTarget_Attribute_deployment() const
{
	return m_deploymentTarget_Attribute_deployment;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getDeploymentTarget_Operation_getDeployedElements() const
{
	return m_deploymentTarget_Operation_getDeployedElements;
}

// End Class DeploymentTarget

// Begin Class DestroyLinkAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getDestroyLinkAction_Class() const
{
	return m_destroyLinkAction_Class;
}




// End Class DestroyLinkAction

// Begin Class DestroyObjectAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getDestroyObjectAction_Class() const
{
	return m_destroyObjectAction_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getDestroyObjectAction_Attribute_isDestroyLinks() const
{
	return m_destroyObjectAction_Attribute_isDestroyLinks;
}
const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getDestroyObjectAction_Attribute_isDestroyOwnedObjects() const
{
	return m_destroyObjectAction_Attribute_isDestroyOwnedObjects;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getDestroyObjectAction_Attribute_target() const
{
	return m_destroyObjectAction_Attribute_target;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getDestroyObjectAction_Operation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_destroyObjectAction_Operation_multiplicity_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getDestroyObjectAction_Operation_no_type_EDiagnosticChain_EMap() const
{
	return m_destroyObjectAction_Operation_no_type_EDiagnosticChain_EMap;
}

// End Class DestroyObjectAction

// Begin Class DestructionOccurrenceSpecification
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getDestructionOccurrenceSpecification_Class() const
{
	return m_destructionOccurrenceSpecification_Class;
}



const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getDestructionOccurrenceSpecification_Operation_no_occurrence_specifications_below_EDiagnosticChain_EMap() const
{
	return m_destructionOccurrenceSpecification_Operation_no_occurrence_specifications_below_EDiagnosticChain_EMap;
}

// End Class DestructionOccurrenceSpecification

// Begin Class Device
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getDevice_Class() const
{
	return m_device_Class;
}




// End Class Device

// Begin Class DirectedRelationship
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getDirectedRelationship_Class() const
{
	return m_directedRelationship_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getDirectedRelationship_Attribute_source() const
{
	return m_directedRelationship_Attribute_source;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getDirectedRelationship_Attribute_target() const
{
	return m_directedRelationship_Attribute_target;
}


// End Class DirectedRelationship

// Begin Class Duration
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getDuration_Class() const
{
	return m_duration_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getDuration_Attribute_expr() const
{
	return m_duration_Attribute_expr;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getDuration_Attribute_observation() const
{
	return m_duration_Attribute_observation;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getDuration_Operation_no_expr_requires_observation_EDiagnosticChain_EMap() const
{
	return m_duration_Operation_no_expr_requires_observation_EDiagnosticChain_EMap;
}

// End Class Duration

// Begin Class DurationConstraint
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getDurationConstraint_Class() const
{
	return m_durationConstraint_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getDurationConstraint_Attribute_firstEvent() const
{
	return m_durationConstraint_Attribute_firstEvent;
}


const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getDurationConstraint_Operation_first_event_multiplicity_EDiagnosticChain_EMap() const
{
	return m_durationConstraint_Operation_first_event_multiplicity_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getDurationConstraint_Operation_has_one_or_two_constrainedElements_EDiagnosticChain_EMap() const
{
	return m_durationConstraint_Operation_has_one_or_two_constrainedElements_EDiagnosticChain_EMap;
}

// End Class DurationConstraint

// Begin Class DurationInterval
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getDurationInterval_Class() const
{
	return m_durationInterval_Class;
}




// End Class DurationInterval

// Begin Class DurationObservation
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getDurationObservation_Class() const
{
	return m_durationObservation_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getDurationObservation_Attribute_firstEvent() const
{
	return m_durationObservation_Attribute_firstEvent;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getDurationObservation_Attribute_event() const
{
	return m_durationObservation_Attribute_event;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getDurationObservation_Operation_first_event_multiplicity_EDiagnosticChain_EMap() const
{
	return m_durationObservation_Operation_first_event_multiplicity_EDiagnosticChain_EMap;
}

// End Class DurationObservation

// Begin Class Element
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getElement_Class() const
{
	return m_element_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getElement_Attribute_ownedComment() const
{
	return m_element_Attribute_ownedComment;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getElement_Attribute_ownedElement() const
{
	return m_element_Attribute_ownedElement;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getElement_Attribute_owner() const
{
	return m_element_Attribute_owner;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElement_Operation_addKeyword_String() const
{
	return m_element_Operation_addKeyword_String;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElement_Operation_allOwnedElements() const
{
	return m_element_Operation_allOwnedElements;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElement_Operation_applyStereotype_Stereotype() const
{
	return m_element_Operation_applyStereotype_Stereotype;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElement_Operation_container() const
{
	return m_element_Operation_container;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElement_Operation_createEAnnotation_String() const
{
	return m_element_Operation_createEAnnotation_String;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElement_Operation_destroy() const
{
	return m_element_Operation_destroy;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElement_Operation_getApplicableStereotype_String() const
{
	return m_element_Operation_getApplicableStereotype_String;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElement_Operation_getApplicableStereotypes() const
{
	return m_element_Operation_getApplicableStereotypes;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElement_Operation_getAppliedStereotype_String() const
{
	return m_element_Operation_getAppliedStereotype_String;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElement_Operation_getAppliedStereotypes() const
{
	return m_element_Operation_getAppliedStereotypes;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElement_Operation_getAppliedSubstereotype_Stereotype_String() const
{
	return m_element_Operation_getAppliedSubstereotype_Stereotype_String;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElement_Operation_getAppliedSubstereotypes_Stereotype() const
{
	return m_element_Operation_getAppliedSubstereotypes_Stereotype;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElement_Operation_getKeywords() const
{
	return m_element_Operation_getKeywords;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElement_Operation_getMetaClass() const
{
	return m_element_Operation_getMetaClass;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElement_Operation_getModel() const
{
	return m_element_Operation_getModel;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElement_Operation_getNearestPackage() const
{
	return m_element_Operation_getNearestPackage;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElement_Operation_getRelationships() const
{
	return m_element_Operation_getRelationships;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElement_Operation_getRelationships_EClass() const
{
	return m_element_Operation_getRelationships_EClass;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElement_Operation_getRequiredStereotype_String() const
{
	return m_element_Operation_getRequiredStereotype_String;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElement_Operation_getRequiredStereotypes() const
{
	return m_element_Operation_getRequiredStereotypes;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElement_Operation_getSourceDirectedRelationships() const
{
	return m_element_Operation_getSourceDirectedRelationships;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElement_Operation_getSourceDirectedRelationships_EClass() const
{
	return m_element_Operation_getSourceDirectedRelationships_EClass;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElement_Operation_getStereotypeApplication_Stereotype() const
{
	return m_element_Operation_getStereotypeApplication_Stereotype;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElement_Operation_getStereotypeApplications() const
{
	return m_element_Operation_getStereotypeApplications;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElement_Operation_getTargetDirectedRelationships() const
{
	return m_element_Operation_getTargetDirectedRelationships;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElement_Operation_getTargetDirectedRelationships_EClass() const
{
	return m_element_Operation_getTargetDirectedRelationships_EClass;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElement_Operation_getValue_Stereotype_String() const
{
	return m_element_Operation_getValue_Stereotype_String;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElement_Operation_hasKeyword_String() const
{
	return m_element_Operation_hasKeyword_String;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElement_Operation_hasValue_Stereotype_String() const
{
	return m_element_Operation_hasValue_Stereotype_String;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElement_Operation_has_owner_EDiagnosticChain_EMap() const
{
	return m_element_Operation_has_owner_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElement_Operation_isStereotypeApplicable_Stereotype() const
{
	return m_element_Operation_isStereotypeApplicable_Stereotype;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElement_Operation_isStereotypeApplied_Stereotype() const
{
	return m_element_Operation_isStereotypeApplied_Stereotype;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElement_Operation_isStereotypeRequired_Stereotype() const
{
	return m_element_Operation_isStereotypeRequired_Stereotype;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElement_Operation_mustBeOwned() const
{
	return m_element_Operation_mustBeOwned;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElement_Operation_not_own_self_EDiagnosticChain_EMap() const
{
	return m_element_Operation_not_own_self_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElement_Operation_removeKeyword_String() const
{
	return m_element_Operation_removeKeyword_String;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElement_Operation_setValue_Stereotype_EJavaObject() const
{
	return m_element_Operation_setValue_Stereotype_EJavaObject;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElement_Operation_unapplyStereotype_Stereotype() const
{
	return m_element_Operation_unapplyStereotype_Stereotype;
}

// End Class Element

// Begin Class ElementImport
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getElementImport_Class() const
{
	return m_elementImport_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getElementImport_Attribute_alias() const
{
	return m_elementImport_Attribute_alias;
}
const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getElementImport_Attribute_visibility() const
{
	return m_elementImport_Attribute_visibility;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getElementImport_Attribute_importedElement() const
{
	return m_elementImport_Attribute_importedElement;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getElementImport_Attribute_importingNamespace() const
{
	return m_elementImport_Attribute_importingNamespace;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElementImport_Operation_getName() const
{
	return m_elementImport_Operation_getName;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElementImport_Operation_imported_element_is_public_EDiagnosticChain_EMap() const
{
	return m_elementImport_Operation_imported_element_is_public_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getElementImport_Operation_visibility_public_or_private_EDiagnosticChain_EMap() const
{
	return m_elementImport_Operation_visibility_public_or_private_EDiagnosticChain_EMap;
}

// End Class ElementImport

// Begin Class EncapsulatedClassifier
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getEncapsulatedClassifier_Class() const
{
	return m_encapsulatedClassifier_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getEncapsulatedClassifier_Attribute_ownedPort() const
{
	return m_encapsulatedClassifier_Attribute_ownedPort;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getEncapsulatedClassifier_Operation_getOwnedPorts() const
{
	return m_encapsulatedClassifier_Operation_getOwnedPorts;
}

// End Class EncapsulatedClassifier

// Begin Class Enumeration
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getEnumeration_Class() const
{
	return m_enumeration_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getEnumeration_Attribute_ownedLiteral() const
{
	return m_enumeration_Attribute_ownedLiteral;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getEnumeration_Operation_immutable_EDiagnosticChain_EMap() const
{
	return m_enumeration_Operation_immutable_EDiagnosticChain_EMap;
}

// End Class Enumeration

// Begin Class EnumerationLiteral
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getEnumerationLiteral_Class() const
{
	return m_enumerationLiteral_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getEnumerationLiteral_Attribute_enumeration() const
{
	return m_enumerationLiteral_Attribute_enumeration;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getEnumerationLiteral_Operation_getClassifier() const
{
	return m_enumerationLiteral_Operation_getClassifier;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getEnumerationLiteral_Operation_getClassifiers() const
{
	return m_enumerationLiteral_Operation_getClassifiers;
}

// End Class EnumerationLiteral

// Begin Class Event
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getEvent_Class() const
{
	return m_event_Class;
}




// End Class Event

// Begin Class ExceptionHandler
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getExceptionHandler_Class() const
{
	return m_exceptionHandler_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getExceptionHandler_Attribute_exceptionInput() const
{
	return m_exceptionHandler_Attribute_exceptionInput;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getExceptionHandler_Attribute_exceptionType() const
{
	return m_exceptionHandler_Attribute_exceptionType;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getExceptionHandler_Attribute_handlerBody() const
{
	return m_exceptionHandler_Attribute_handlerBody;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getExceptionHandler_Attribute_protectedNode() const
{
	return m_exceptionHandler_Attribute_protectedNode;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getExceptionHandler_Operation_edge_source_target_EDiagnosticChain_EMap() const
{
	return m_exceptionHandler_Operation_edge_source_target_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getExceptionHandler_Operation_exception_input_type_EDiagnosticChain_EMap() const
{
	return m_exceptionHandler_Operation_exception_input_type_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getExceptionHandler_Operation_handler_body_edges_EDiagnosticChain_EMap() const
{
	return m_exceptionHandler_Operation_handler_body_edges_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getExceptionHandler_Operation_handler_body_owner_EDiagnosticChain_EMap() const
{
	return m_exceptionHandler_Operation_handler_body_owner_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getExceptionHandler_Operation_one_input_EDiagnosticChain_EMap() const
{
	return m_exceptionHandler_Operation_one_input_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getExceptionHandler_Operation_output_pins_EDiagnosticChain_EMap() const
{
	return m_exceptionHandler_Operation_output_pins_EDiagnosticChain_EMap;
}

// End Class ExceptionHandler

// Begin Class ExecutableNode
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getExecutableNode_Class() const
{
	return m_executableNode_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getExecutableNode_Attribute_handler() const
{
	return m_executableNode_Attribute_handler;
}


// End Class ExecutableNode

// Begin Class ExecutionEnvironment
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getExecutionEnvironment_Class() const
{
	return m_executionEnvironment_Class;
}




// End Class ExecutionEnvironment

// Begin Class ExecutionOccurrenceSpecification
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getExecutionOccurrenceSpecification_Class() const
{
	return m_executionOccurrenceSpecification_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getExecutionOccurrenceSpecification_Attribute_execution() const
{
	return m_executionOccurrenceSpecification_Attribute_execution;
}


// End Class ExecutionOccurrenceSpecification

// Begin Class ExecutionSpecification
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getExecutionSpecification_Class() const
{
	return m_executionSpecification_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getExecutionSpecification_Attribute_finish() const
{
	return m_executionSpecification_Attribute_finish;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getExecutionSpecification_Attribute_start() const
{
	return m_executionSpecification_Attribute_start;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getExecutionSpecification_Operation_same_lifeline_EDiagnosticChain_EMap() const
{
	return m_executionSpecification_Operation_same_lifeline_EDiagnosticChain_EMap;
}

// End Class ExecutionSpecification

// Begin Class ExpansionNode
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getExpansionNode_Class() const
{
	return m_expansionNode_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getExpansionNode_Attribute_regionAsInput() const
{
	return m_expansionNode_Attribute_regionAsInput;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getExpansionNode_Attribute_regionAsOutput() const
{
	return m_expansionNode_Attribute_regionAsOutput;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getExpansionNode_Operation_region_as_input_or_output_EDiagnosticChain_EMap() const
{
	return m_expansionNode_Operation_region_as_input_or_output_EDiagnosticChain_EMap;
}

// End Class ExpansionNode

// Begin Class ExpansionRegion
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getExpansionRegion_Class() const
{
	return m_expansionRegion_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getExpansionRegion_Attribute_mode() const
{
	return m_expansionRegion_Attribute_mode;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getExpansionRegion_Attribute_inputElement() const
{
	return m_expansionRegion_Attribute_inputElement;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getExpansionRegion_Attribute_outputElement() const
{
	return m_expansionRegion_Attribute_outputElement;
}


// End Class ExpansionRegion

// Begin Class Expression
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getExpression_Class() const
{
	return m_expression_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getExpression_Attribute_symbol() const
{
	return m_expression_Attribute_symbol;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getExpression_Attribute_operand() const
{
	return m_expression_Attribute_operand;
}


// End Class Expression

// Begin Class Extend
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getExtend_Class() const
{
	return m_extend_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getExtend_Attribute_condition() const
{
	return m_extend_Attribute_condition;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getExtend_Attribute_extendedCase() const
{
	return m_extend_Attribute_extendedCase;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getExtend_Attribute_extension() const
{
	return m_extend_Attribute_extension;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getExtend_Attribute_extensionLocation() const
{
	return m_extend_Attribute_extensionLocation;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getExtend_Operation_extension_points_EDiagnosticChain_EMap() const
{
	return m_extend_Operation_extension_points_EDiagnosticChain_EMap;
}

// End Class Extend

// Begin Class Extension
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getExtension_Class() const
{
	return m_extension_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getExtension_Attribute_isRequired() const
{
	return m_extension_Attribute_isRequired;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getExtension_Attribute_metaclass() const
{
	return m_extension_Attribute_metaclass;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getExtension_Operation_getMetaclass() const
{
	return m_extension_Operation_getMetaclass;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getExtension_Operation_getStereotype() const
{
	return m_extension_Operation_getStereotype;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getExtension_Operation_getStereotypeEnd() const
{
	return m_extension_Operation_getStereotypeEnd;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getExtension_Operation_isRequired() const
{
	return m_extension_Operation_isRequired;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getExtension_Operation_is_binary_EDiagnosticChain_EMap() const
{
	return m_extension_Operation_is_binary_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getExtension_Operation_metaclassEnd() const
{
	return m_extension_Operation_metaclassEnd;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getExtension_Operation_non_owned_end_EDiagnosticChain_EMap() const
{
	return m_extension_Operation_non_owned_end_EDiagnosticChain_EMap;
}

// End Class Extension

// Begin Class ExtensionEnd
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getExtensionEnd_Class() const
{
	return m_extensionEnd_Class;
}



const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getExtensionEnd_Operation_aggregation_EDiagnosticChain_EMap() const
{
	return m_extensionEnd_Operation_aggregation_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getExtensionEnd_Operation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_extensionEnd_Operation_multiplicity_EDiagnosticChain_EMap;
}

// End Class ExtensionEnd

// Begin Class ExtensionPoint
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getExtensionPoint_Class() const
{
	return m_extensionPoint_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getExtensionPoint_Attribute_useCase() const
{
	return m_extensionPoint_Attribute_useCase;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getExtensionPoint_Operation_must_have_name_EDiagnosticChain_EMap() const
{
	return m_extensionPoint_Operation_must_have_name_EDiagnosticChain_EMap;
}

// End Class ExtensionPoint

// Begin Class Factory
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getFactory_Class() const
{
	return m_factory_Class;
}



const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getFactory_Operation_create_Class() const
{
	return m_factory_Operation_create_Class;
}

// End Class Factory

// Begin Class Feature
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getFeature_Class() const
{
	return m_feature_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getFeature_Attribute_isStatic() const
{
	return m_feature_Attribute_isStatic;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getFeature_Attribute_featuringClassifier() const
{
	return m_feature_Attribute_featuringClassifier;
}


// End Class Feature

// Begin Class FinalNode
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getFinalNode_Class() const
{
	return m_finalNode_Class;
}



const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getFinalNode_Operation_no_outgoing_edges_EDiagnosticChain_EMap() const
{
	return m_finalNode_Operation_no_outgoing_edges_EDiagnosticChain_EMap;
}

// End Class FinalNode

// Begin Class FinalState
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getFinalState_Class() const
{
	return m_finalState_Class;
}



const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getFinalState_Operation_cannot_reference_submachine_EDiagnosticChain_EMap() const
{
	return m_finalState_Operation_cannot_reference_submachine_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getFinalState_Operation_no_entry_behavior_EDiagnosticChain_EMap() const
{
	return m_finalState_Operation_no_entry_behavior_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getFinalState_Operation_no_exit_behavior_EDiagnosticChain_EMap() const
{
	return m_finalState_Operation_no_exit_behavior_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getFinalState_Operation_no_outgoing_transitions_EDiagnosticChain_EMap() const
{
	return m_finalState_Operation_no_outgoing_transitions_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getFinalState_Operation_no_regions_EDiagnosticChain_EMap() const
{
	return m_finalState_Operation_no_regions_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getFinalState_Operation_no_state_behavior_EDiagnosticChain_EMap() const
{
	return m_finalState_Operation_no_state_behavior_EDiagnosticChain_EMap;
}

// End Class FinalState

// Begin Class FlowFinalNode
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getFlowFinalNode_Class() const
{
	return m_flowFinalNode_Class;
}




// End Class FlowFinalNode

// Begin Class ForkNode
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getForkNode_Class() const
{
	return m_forkNode_Class;
}



const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getForkNode_Operation_edges_EDiagnosticChain_EMap() const
{
	return m_forkNode_Operation_edges_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getForkNode_Operation_one_incoming_edge_EDiagnosticChain_EMap() const
{
	return m_forkNode_Operation_one_incoming_edge_EDiagnosticChain_EMap;
}

// End Class ForkNode

// Begin Class FunctionBehavior
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getFunctionBehavior_Class() const
{
	return m_functionBehavior_Class;
}



const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getFunctionBehavior_Operation_hasAllDataTypeAttributes_DataType() const
{
	return m_functionBehavior_Operation_hasAllDataTypeAttributes_DataType;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getFunctionBehavior_Operation_one_output_parameter_EDiagnosticChain_EMap() const
{
	return m_functionBehavior_Operation_one_output_parameter_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getFunctionBehavior_Operation_types_of_parameters_EDiagnosticChain_EMap() const
{
	return m_functionBehavior_Operation_types_of_parameters_EDiagnosticChain_EMap;
}

// End Class FunctionBehavior

// Begin Class Gate
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getGate_Class() const
{
	return m_gate_Class;
}



const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getGate_Operation_actual_gate_distinguishable_EDiagnosticChain_EMap() const
{
	return m_gate_Operation_actual_gate_distinguishable_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getGate_Operation_actual_gate_matched_EDiagnosticChain_EMap() const
{
	return m_gate_Operation_actual_gate_matched_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getGate_Operation_formal_gate_distinguishable_EDiagnosticChain_EMap() const
{
	return m_gate_Operation_formal_gate_distinguishable_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getGate_Operation_getName() const
{
	return m_gate_Operation_getName;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getGate_Operation_getOperand() const
{
	return m_gate_Operation_getOperand;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getGate_Operation_inside_cf_gate_distinguishable_EDiagnosticChain_EMap() const
{
	return m_gate_Operation_inside_cf_gate_distinguishable_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getGate_Operation_inside_cf_matched_EDiagnosticChain_EMap() const
{
	return m_gate_Operation_inside_cf_matched_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getGate_Operation_isActual() const
{
	return m_gate_Operation_isActual;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getGate_Operation_isFormal() const
{
	return m_gate_Operation_isFormal;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getGate_Operation_isInsideCF() const
{
	return m_gate_Operation_isInsideCF;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getGate_Operation_isOutsideCF() const
{
	return m_gate_Operation_isOutsideCF;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getGate_Operation_matches_Gate() const
{
	return m_gate_Operation_matches_Gate;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getGate_Operation_outside_cf_gate_distinguishable_EDiagnosticChain_EMap() const
{
	return m_gate_Operation_outside_cf_gate_distinguishable_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getGate_Operation_outside_cf_matched_EDiagnosticChain_EMap() const
{
	return m_gate_Operation_outside_cf_matched_EDiagnosticChain_EMap;
}

// End Class Gate

// Begin Class GeneralOrdering
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getGeneralOrdering_Class() const
{
	return m_generalOrdering_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getGeneralOrdering_Attribute_after() const
{
	return m_generalOrdering_Attribute_after;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getGeneralOrdering_Attribute_before() const
{
	return m_generalOrdering_Attribute_before;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getGeneralOrdering_Operation_irreflexive_transitive_closure_EDiagnosticChain_EMap() const
{
	return m_generalOrdering_Operation_irreflexive_transitive_closure_EDiagnosticChain_EMap;
}

// End Class GeneralOrdering

// Begin Class Generalization
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getGeneralization_Class() const
{
	return m_generalization_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getGeneralization_Attribute_isSubstitutable() const
{
	return m_generalization_Attribute_isSubstitutable;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getGeneralization_Attribute_general() const
{
	return m_generalization_Attribute_general;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getGeneralization_Attribute_generalizationSet() const
{
	return m_generalization_Attribute_generalizationSet;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getGeneralization_Attribute_specific() const
{
	return m_generalization_Attribute_specific;
}


// End Class Generalization

// Begin Class GeneralizationSet
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getGeneralizationSet_Class() const
{
	return m_generalizationSet_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getGeneralizationSet_Attribute_isCovering() const
{
	return m_generalizationSet_Attribute_isCovering;
}
const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getGeneralizationSet_Attribute_isDisjoint() const
{
	return m_generalizationSet_Attribute_isDisjoint;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getGeneralizationSet_Attribute_generalization() const
{
	return m_generalizationSet_Attribute_generalization;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getGeneralizationSet_Attribute_powertype() const
{
	return m_generalizationSet_Attribute_powertype;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getGeneralizationSet_Operation_generalization_same_classifier_EDiagnosticChain_EMap() const
{
	return m_generalizationSet_Operation_generalization_same_classifier_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getGeneralizationSet_Operation_maps_to_generalization_set_EDiagnosticChain_EMap() const
{
	return m_generalizationSet_Operation_maps_to_generalization_set_EDiagnosticChain_EMap;
}

// End Class GeneralizationSet

// Begin Class Image
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getImage_Class() const
{
	return m_image_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getImage_Attribute_content() const
{
	return m_image_Attribute_content;
}
const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getImage_Attribute_format() const
{
	return m_image_Attribute_format;
}
const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getImage_Attribute_location() const
{
	return m_image_Attribute_location;
}



// End Class Image

// Begin Class Include
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getInclude_Class() const
{
	return m_include_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInclude_Attribute_addition() const
{
	return m_include_Attribute_addition;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInclude_Attribute_includingCase() const
{
	return m_include_Attribute_includingCase;
}


// End Class Include

// Begin Class InformationFlow
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getInformationFlow_Class() const
{
	return m_informationFlow_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInformationFlow_Attribute_conveyed() const
{
	return m_informationFlow_Attribute_conveyed;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInformationFlow_Attribute_informationSource() const
{
	return m_informationFlow_Attribute_informationSource;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInformationFlow_Attribute_informationTarget() const
{
	return m_informationFlow_Attribute_informationTarget;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInformationFlow_Attribute_realization() const
{
	return m_informationFlow_Attribute_realization;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInformationFlow_Attribute_realizingActivityEdge() const
{
	return m_informationFlow_Attribute_realizingActivityEdge;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInformationFlow_Attribute_realizingConnector() const
{
	return m_informationFlow_Attribute_realizingConnector;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInformationFlow_Attribute_realizingMessage() const
{
	return m_informationFlow_Attribute_realizingMessage;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getInformationFlow_Operation_convey_classifiers_EDiagnosticChain_EMap() const
{
	return m_informationFlow_Operation_convey_classifiers_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getInformationFlow_Operation_must_conform_EDiagnosticChain_EMap() const
{
	return m_informationFlow_Operation_must_conform_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getInformationFlow_Operation_sources_and_targets_kind_EDiagnosticChain_EMap() const
{
	return m_informationFlow_Operation_sources_and_targets_kind_EDiagnosticChain_EMap;
}

// End Class InformationFlow

// Begin Class InformationItem
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getInformationItem_Class() const
{
	return m_informationItem_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInformationItem_Attribute_represented() const
{
	return m_informationItem_Attribute_represented;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getInformationItem_Operation_has_no_EDiagnosticChain_EMap() const
{
	return m_informationItem_Operation_has_no_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getInformationItem_Operation_not_instantiable_EDiagnosticChain_EMap() const
{
	return m_informationItem_Operation_not_instantiable_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getInformationItem_Operation_sources_and_targets_EDiagnosticChain_EMap() const
{
	return m_informationItem_Operation_sources_and_targets_EDiagnosticChain_EMap;
}

// End Class InformationItem

// Begin Class InitialNode
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getInitialNode_Class() const
{
	return m_initialNode_Class;
}



const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getInitialNode_Operation_control_edges_EDiagnosticChain_EMap() const
{
	return m_initialNode_Operation_control_edges_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getInitialNode_Operation_no_incoming_edges_EDiagnosticChain_EMap() const
{
	return m_initialNode_Operation_no_incoming_edges_EDiagnosticChain_EMap;
}

// End Class InitialNode

// Begin Class InputPin
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getInputPin_Class() const
{
	return m_inputPin_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInputPin_Attribute_action() const
{
	return m_inputPin_Attribute_action;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInputPin_Attribute_addStructuralFeatureValueAction() const
{
	return m_inputPin_Attribute_addStructuralFeatureValueAction;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInputPin_Attribute_callOperationAction() const
{
	return m_inputPin_Attribute_callOperationAction;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInputPin_Attribute_destroyObjectAction() const
{
	return m_inputPin_Attribute_destroyObjectAction;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInputPin_Attribute_invocationAction() const
{
	return m_inputPin_Attribute_invocationAction;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInputPin_Attribute_removeStructuralFeatureValueAction() const
{
	return m_inputPin_Attribute_removeStructuralFeatureValueAction;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInputPin_Attribute_structuralFeatureAction() const
{
	return m_inputPin_Attribute_structuralFeatureAction;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInputPin_Attribute_writeStructuralFeatureAction() const
{
	return m_inputPin_Attribute_writeStructuralFeatureAction;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getInputPin_Operation_outgoing_edges_structured_only_EDiagnosticChain_EMap() const
{
	return m_inputPin_Operation_outgoing_edges_structured_only_EDiagnosticChain_EMap;
}

// End Class InputPin

// Begin Class InstanceSpecification
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getInstanceSpecification_Class() const
{
	return m_instanceSpecification_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInstanceSpecification_Attribute_classifier() const
{
	return m_instanceSpecification_Attribute_classifier;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInstanceSpecification_Attribute_slot() const
{
	return m_instanceSpecification_Attribute_slot;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInstanceSpecification_Attribute_specification() const
{
	return m_instanceSpecification_Attribute_specification;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getInstanceSpecification_Operation_defining_feature_EDiagnosticChain_EMap() const
{
	return m_instanceSpecification_Operation_defining_feature_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getInstanceSpecification_Operation_deployment_artifact_EDiagnosticChain_EMap() const
{
	return m_instanceSpecification_Operation_deployment_artifact_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getInstanceSpecification_Operation_deployment_target_EDiagnosticChain_EMap() const
{
	return m_instanceSpecification_Operation_deployment_target_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getInstanceSpecification_Operation_structural_feature_EDiagnosticChain_EMap() const
{
	return m_instanceSpecification_Operation_structural_feature_EDiagnosticChain_EMap;
}

// End Class InstanceSpecification

// Begin Class InstanceValue
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getInstanceValue_Class() const
{
	return m_instanceValue_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInstanceValue_Attribute_instance() const
{
	return m_instanceValue_Attribute_instance;
}


// End Class InstanceValue

// Begin Class Interaction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getInteraction_Class() const
{
	return m_interaction_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInteraction_Attribute_action() const
{
	return m_interaction_Attribute_action;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInteraction_Attribute_formalGate() const
{
	return m_interaction_Attribute_formalGate;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInteraction_Attribute_fragment() const
{
	return m_interaction_Attribute_fragment;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInteraction_Attribute_lifeline() const
{
	return m_interaction_Attribute_lifeline;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInteraction_Attribute_message() const
{
	return m_interaction_Attribute_message;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getInteraction_Operation_not_contained_EDiagnosticChain_EMap() const
{
	return m_interaction_Operation_not_contained_EDiagnosticChain_EMap;
}

// End Class Interaction

// Begin Class InteractionConstraint
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getInteractionConstraint_Class() const
{
	return m_interactionConstraint_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInteractionConstraint_Attribute_maxint() const
{
	return m_interactionConstraint_Attribute_maxint;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInteractionConstraint_Attribute_minint() const
{
	return m_interactionConstraint_Attribute_minint;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getInteractionConstraint_Operation_dynamic_variables_EDiagnosticChain_EMap() const
{
	return m_interactionConstraint_Operation_dynamic_variables_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getInteractionConstraint_Operation_global_data_EDiagnosticChain_EMap() const
{
	return m_interactionConstraint_Operation_global_data_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getInteractionConstraint_Operation_maxint_greater_equal_minint_EDiagnosticChain_EMap() const
{
	return m_interactionConstraint_Operation_maxint_greater_equal_minint_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getInteractionConstraint_Operation_maxint_positive_EDiagnosticChain_EMap() const
{
	return m_interactionConstraint_Operation_maxint_positive_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getInteractionConstraint_Operation_minint_maxint_EDiagnosticChain_EMap() const
{
	return m_interactionConstraint_Operation_minint_maxint_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getInteractionConstraint_Operation_minint_non_negative_EDiagnosticChain_EMap() const
{
	return m_interactionConstraint_Operation_minint_non_negative_EDiagnosticChain_EMap;
}

// End Class InteractionConstraint

// Begin Class InteractionFragment
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getInteractionFragment_Class() const
{
	return m_interactionFragment_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInteractionFragment_Attribute_covered() const
{
	return m_interactionFragment_Attribute_covered;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInteractionFragment_Attribute_enclosingInteraction() const
{
	return m_interactionFragment_Attribute_enclosingInteraction;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInteractionFragment_Attribute_enclosingOperand() const
{
	return m_interactionFragment_Attribute_enclosingOperand;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInteractionFragment_Attribute_generalOrdering() const
{
	return m_interactionFragment_Attribute_generalOrdering;
}


// End Class InteractionFragment

// Begin Class InteractionOperand
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getInteractionOperand_Class() const
{
	return m_interactionOperand_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInteractionOperand_Attribute_fragment() const
{
	return m_interactionOperand_Attribute_fragment;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInteractionOperand_Attribute_guard() const
{
	return m_interactionOperand_Attribute_guard;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getInteractionOperand_Operation_guard_contain_references_EDiagnosticChain_EMap() const
{
	return m_interactionOperand_Operation_guard_contain_references_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getInteractionOperand_Operation_guard_directly_prior_EDiagnosticChain_EMap() const
{
	return m_interactionOperand_Operation_guard_directly_prior_EDiagnosticChain_EMap;
}

// End Class InteractionOperand

// Begin Class InteractionUse
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getInteractionUse_Class() const
{
	return m_interactionUse_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInteractionUse_Attribute_actualGate() const
{
	return m_interactionUse_Attribute_actualGate;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInteractionUse_Attribute_argument() const
{
	return m_interactionUse_Attribute_argument;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInteractionUse_Attribute_refersTo() const
{
	return m_interactionUse_Attribute_refersTo;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInteractionUse_Attribute_returnValue() const
{
	return m_interactionUse_Attribute_returnValue;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInteractionUse_Attribute_returnValueRecipient() const
{
	return m_interactionUse_Attribute_returnValueRecipient;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getInteractionUse_Operation_all_lifelines_EDiagnosticChain_EMap() const
{
	return m_interactionUse_Operation_all_lifelines_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getInteractionUse_Operation_arguments_are_constants_EDiagnosticChain_EMap() const
{
	return m_interactionUse_Operation_arguments_are_constants_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getInteractionUse_Operation_arguments_correspond_to_parameters_EDiagnosticChain_EMap() const
{
	return m_interactionUse_Operation_arguments_correspond_to_parameters_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getInteractionUse_Operation_gates_match_EDiagnosticChain_EMap() const
{
	return m_interactionUse_Operation_gates_match_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getInteractionUse_Operation_returnValueRecipient_coverage_EDiagnosticChain_EMap() const
{
	return m_interactionUse_Operation_returnValueRecipient_coverage_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getInteractionUse_Operation_returnValue_type_recipient_correspondence_EDiagnosticChain_EMap() const
{
	return m_interactionUse_Operation_returnValue_type_recipient_correspondence_EDiagnosticChain_EMap;
}

// End Class InteractionUse

// Begin Class Interface
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getInterface_Class() const
{
	return m_interface_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInterface_Attribute_nestedClassifier() const
{
	return m_interface_Attribute_nestedClassifier;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInterface_Attribute_ownedAttribute() const
{
	return m_interface_Attribute_ownedAttribute;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInterface_Attribute_ownedOperation() const
{
	return m_interface_Attribute_ownedOperation;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInterface_Attribute_ownedReception() const
{
	return m_interface_Attribute_ownedReception;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInterface_Attribute_protocol() const
{
	return m_interface_Attribute_protocol;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInterface_Attribute_redefinedInterface() const
{
	return m_interface_Attribute_redefinedInterface;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getInterface_Operation_createOwnedAttribute_String_UnlimitedNatural() const
{
	return m_interface_Operation_createOwnedAttribute_String_UnlimitedNatural;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getInterface_Operation_createOwnedOperation_String_Type() const
{
	return m_interface_Operation_createOwnedOperation_String_Type;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getInterface_Operation_visibility_EDiagnosticChain_EMap() const
{
	return m_interface_Operation_visibility_EDiagnosticChain_EMap;
}

// End Class Interface

// Begin Class InterfaceRealization
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getInterfaceRealization_Class() const
{
	return m_interfaceRealization_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInterfaceRealization_Attribute_contract() const
{
	return m_interfaceRealization_Attribute_contract;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInterfaceRealization_Attribute_implementingClassifier() const
{
	return m_interfaceRealization_Attribute_implementingClassifier;
}


// End Class InterfaceRealization

// Begin Class InterruptibleActivityRegion
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getInterruptibleActivityRegion_Class() const
{
	return m_interruptibleActivityRegion_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInterruptibleActivityRegion_Attribute_interruptingEdge() const
{
	return m_interruptibleActivityRegion_Attribute_interruptingEdge;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInterruptibleActivityRegion_Attribute_node() const
{
	return m_interruptibleActivityRegion_Attribute_node;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getInterruptibleActivityRegion_Operation_interrupting_edges_EDiagnosticChain_EMap() const
{
	return m_interruptibleActivityRegion_Operation_interrupting_edges_EDiagnosticChain_EMap;
}

// End Class InterruptibleActivityRegion

// Begin Class Interval
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getInterval_Class() const
{
	return m_interval_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInterval_Attribute_max() const
{
	return m_interval_Attribute_max;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInterval_Attribute_min() const
{
	return m_interval_Attribute_min;
}


// End Class Interval

// Begin Class IntervalConstraint
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getIntervalConstraint_Class() const
{
	return m_intervalConstraint_Class;
}




// End Class IntervalConstraint

// Begin Class InvocationAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getInvocationAction_Class() const
{
	return m_invocationAction_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInvocationAction_Attribute_argument() const
{
	return m_invocationAction_Attribute_argument;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getInvocationAction_Attribute_onPort() const
{
	return m_invocationAction_Attribute_onPort;
}


// End Class InvocationAction

// Begin Class JoinNode
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getJoinNode_Class() const
{
	return m_joinNode_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getJoinNode_Attribute_isCombineDuplicate() const
{
	return m_joinNode_Attribute_isCombineDuplicate;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getJoinNode_Attribute_joinSpec() const
{
	return m_joinNode_Attribute_joinSpec;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getJoinNode_Operation_incoming_object_flow_EDiagnosticChain_EMap() const
{
	return m_joinNode_Operation_incoming_object_flow_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getJoinNode_Operation_one_outgoing_edge_EDiagnosticChain_EMap() const
{
	return m_joinNode_Operation_one_outgoing_edge_EDiagnosticChain_EMap;
}

// End Class JoinNode

// Begin Class Lifeline
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getLifeline_Class() const
{
	return m_lifeline_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getLifeline_Attribute_coveredBy() const
{
	return m_lifeline_Attribute_coveredBy;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getLifeline_Attribute_decomposedAs() const
{
	return m_lifeline_Attribute_decomposedAs;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getLifeline_Attribute_interaction() const
{
	return m_lifeline_Attribute_interaction;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getLifeline_Attribute_represents() const
{
	return m_lifeline_Attribute_represents;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getLifeline_Attribute_selector() const
{
	return m_lifeline_Attribute_selector;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getLifeline_Operation_interaction_uses_share_lifeline_EDiagnosticChain_EMap() const
{
	return m_lifeline_Operation_interaction_uses_share_lifeline_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getLifeline_Operation_same_classifier_EDiagnosticChain_EMap() const
{
	return m_lifeline_Operation_same_classifier_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getLifeline_Operation_selector_int_or_string_EDiagnosticChain_EMap() const
{
	return m_lifeline_Operation_selector_int_or_string_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getLifeline_Operation_selector_specified_EDiagnosticChain_EMap() const
{
	return m_lifeline_Operation_selector_specified_EDiagnosticChain_EMap;
}

// End Class Lifeline

// Begin Class LinkAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getLinkAction_Class() const
{
	return m_linkAction_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getLinkAction_Attribute_endData() const
{
	return m_linkAction_Attribute_endData;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getLinkAction_Attribute_inputValue() const
{
	return m_linkAction_Attribute_inputValue;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getLinkAction_Operation_association() const
{
	return m_linkAction_Operation_association;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getLinkAction_Operation_not_static_EDiagnosticChain_EMap() const
{
	return m_linkAction_Operation_not_static_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getLinkAction_Operation_same_association_EDiagnosticChain_EMap() const
{
	return m_linkAction_Operation_same_association_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getLinkAction_Operation_same_pins_EDiagnosticChain_EMap() const
{
	return m_linkAction_Operation_same_pins_EDiagnosticChain_EMap;
}

// End Class LinkAction

// Begin Class LinkEndCreationData
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getLinkEndCreationData_Class() const
{
	return m_linkEndCreationData_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getLinkEndCreationData_Attribute_isReplaceAll() const
{
	return m_linkEndCreationData_Attribute_isReplaceAll;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getLinkEndCreationData_Attribute_insertAt() const
{
	return m_linkEndCreationData_Attribute_insertAt;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getLinkEndCreationData_Operation_insertAt_pin_EDiagnosticChain_EMap() const
{
	return m_linkEndCreationData_Operation_insertAt_pin_EDiagnosticChain_EMap;
}

// End Class LinkEndCreationData

// Begin Class LinkEndData
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getLinkEndData_Class() const
{
	return m_linkEndData_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getLinkEndData_Attribute_end() const
{
	return m_linkEndData_Attribute_end;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getLinkEndData_Attribute_qualifier() const
{
	return m_linkEndData_Attribute_qualifier;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getLinkEndData_Attribute_value() const
{
	return m_linkEndData_Attribute_value;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getLinkEndData_Operation_allPins() const
{
	return m_linkEndData_Operation_allPins;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getLinkEndData_Operation_end_object_input_pin_EDiagnosticChain_EMap() const
{
	return m_linkEndData_Operation_end_object_input_pin_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getLinkEndData_Operation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_linkEndData_Operation_multiplicity_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getLinkEndData_Operation_property_is_association_end_EDiagnosticChain_EMap() const
{
	return m_linkEndData_Operation_property_is_association_end_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getLinkEndData_Operation_qualifiers_EDiagnosticChain_EMap() const
{
	return m_linkEndData_Operation_qualifiers_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getLinkEndData_Operation_same_type_EDiagnosticChain_EMap() const
{
	return m_linkEndData_Operation_same_type_EDiagnosticChain_EMap;
}

// End Class LinkEndData

// Begin Class LinkEndDestructionData
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getLinkEndDestructionData_Class() const
{
	return m_linkEndDestructionData_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getLinkEndDestructionData_Attribute_isDestroyDuplicates() const
{
	return m_linkEndDestructionData_Attribute_isDestroyDuplicates;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getLinkEndDestructionData_Attribute_destroyAt() const
{
	return m_linkEndDestructionData_Attribute_destroyAt;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getLinkEndDestructionData_Operation_destroyAt_pin_EDiagnosticChain_EMap() const
{
	return m_linkEndDestructionData_Operation_destroyAt_pin_EDiagnosticChain_EMap;
}

// End Class LinkEndDestructionData

// Begin Class LiteralBoolean
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getLiteralBoolean_Class() const
{
	return m_literalBoolean_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getLiteralBoolean_Attribute_value() const
{
	return m_literalBoolean_Attribute_value;
}


const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getLiteralBoolean_Operation_booleanValue() const
{
	return m_literalBoolean_Operation_booleanValue;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getLiteralBoolean_Operation_isComputable() const
{
	return m_literalBoolean_Operation_isComputable;
}

// End Class LiteralBoolean

// Begin Class LiteralInteger
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getLiteralInteger_Class() const
{
	return m_literalInteger_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getLiteralInteger_Attribute_value() const
{
	return m_literalInteger_Attribute_value;
}


const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getLiteralInteger_Operation_integerValue() const
{
	return m_literalInteger_Operation_integerValue;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getLiteralInteger_Operation_isComputable() const
{
	return m_literalInteger_Operation_isComputable;
}

// End Class LiteralInteger

// Begin Class LiteralNull
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getLiteralNull_Class() const
{
	return m_literalNull_Class;
}



const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getLiteralNull_Operation_isComputable() const
{
	return m_literalNull_Operation_isComputable;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getLiteralNull_Operation_isNull() const
{
	return m_literalNull_Operation_isNull;
}

// End Class LiteralNull

// Begin Class LiteralReal
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getLiteralReal_Class() const
{
	return m_literalReal_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getLiteralReal_Attribute_value() const
{
	return m_literalReal_Attribute_value;
}


const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getLiteralReal_Operation_isComputable() const
{
	return m_literalReal_Operation_isComputable;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getLiteralReal_Operation_realValue() const
{
	return m_literalReal_Operation_realValue;
}

// End Class LiteralReal

// Begin Class LiteralSpecification
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getLiteralSpecification_Class() const
{
	return m_literalSpecification_Class;
}




// End Class LiteralSpecification

// Begin Class LiteralString
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getLiteralString_Class() const
{
	return m_literalString_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getLiteralString_Attribute_value() const
{
	return m_literalString_Attribute_value;
}


const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getLiteralString_Operation_isComputable() const
{
	return m_literalString_Operation_isComputable;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getLiteralString_Operation_stringValue() const
{
	return m_literalString_Operation_stringValue;
}

// End Class LiteralString

// Begin Class LiteralUnlimitedNatural
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getLiteralUnlimitedNatural_Class() const
{
	return m_literalUnlimitedNatural_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getLiteralUnlimitedNatural_Attribute_value() const
{
	return m_literalUnlimitedNatural_Attribute_value;
}


const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getLiteralUnlimitedNatural_Operation_isComputable() const
{
	return m_literalUnlimitedNatural_Operation_isComputable;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getLiteralUnlimitedNatural_Operation_unlimitedValue() const
{
	return m_literalUnlimitedNatural_Operation_unlimitedValue;
}

// End Class LiteralUnlimitedNatural

// Begin Class LoopNode
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getLoopNode_Class() const
{
	return m_loopNode_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getLoopNode_Attribute_isTestedFirst() const
{
	return m_loopNode_Attribute_isTestedFirst;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getLoopNode_Attribute_bodyOutput() const
{
	return m_loopNode_Attribute_bodyOutput;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getLoopNode_Attribute_bodyPart() const
{
	return m_loopNode_Attribute_bodyPart;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getLoopNode_Attribute_decider() const
{
	return m_loopNode_Attribute_decider;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getLoopNode_Attribute_loopVariable() const
{
	return m_loopNode_Attribute_loopVariable;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getLoopNode_Attribute_loopVariableInput() const
{
	return m_loopNode_Attribute_loopVariableInput;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getLoopNode_Attribute_result() const
{
	return m_loopNode_Attribute_result;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getLoopNode_Attribute_setupPart() const
{
	return m_loopNode_Attribute_setupPart;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getLoopNode_Attribute_test() const
{
	return m_loopNode_Attribute_test;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getLoopNode_Operation_body_output_pins_EDiagnosticChain_EMap() const
{
	return m_loopNode_Operation_body_output_pins_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getLoopNode_Operation_executable_nodes_EDiagnosticChain_EMap() const
{
	return m_loopNode_Operation_executable_nodes_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getLoopNode_Operation_input_edges_EDiagnosticChain_EMap() const
{
	return m_loopNode_Operation_input_edges_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getLoopNode_Operation_loop_variable_outgoing_EDiagnosticChain_EMap() const
{
	return m_loopNode_Operation_loop_variable_outgoing_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getLoopNode_Operation_matching_loop_variables_EDiagnosticChain_EMap() const
{
	return m_loopNode_Operation_matching_loop_variables_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getLoopNode_Operation_matching_output_pins_EDiagnosticChain_EMap() const
{
	return m_loopNode_Operation_matching_output_pins_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getLoopNode_Operation_matching_result_pins_EDiagnosticChain_EMap() const
{
	return m_loopNode_Operation_matching_result_pins_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getLoopNode_Operation_result_no_incoming_EDiagnosticChain_EMap() const
{
	return m_loopNode_Operation_result_no_incoming_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getLoopNode_Operation_setup_test_and_body_EDiagnosticChain_EMap() const
{
	return m_loopNode_Operation_setup_test_and_body_EDiagnosticChain_EMap;
}

// End Class LoopNode

// Begin Class Manifestation
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getManifestation_Class() const
{
	return m_manifestation_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getManifestation_Attribute_utilizedElement() const
{
	return m_manifestation_Attribute_utilizedElement;
}


// End Class Manifestation

// Begin Class MergeNode
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getMergeNode_Class() const
{
	return m_mergeNode_Class;
}



const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getMergeNode_Operation_edges_EDiagnosticChain_EMap() const
{
	return m_mergeNode_Operation_edges_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getMergeNode_Operation_one_outgoing_edge_EDiagnosticChain_EMap() const
{
	return m_mergeNode_Operation_one_outgoing_edge_EDiagnosticChain_EMap;
}

// End Class MergeNode

// Begin Class Message
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getMessage_Class() const
{
	return m_message_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getMessage_Attribute_messageKind() const
{
	return m_message_Attribute_messageKind;
}
const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getMessage_Attribute_messageSort() const
{
	return m_message_Attribute_messageSort;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getMessage_Attribute_argument() const
{
	return m_message_Attribute_argument;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getMessage_Attribute_connector() const
{
	return m_message_Attribute_connector;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getMessage_Attribute_interaction() const
{
	return m_message_Attribute_interaction;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getMessage_Attribute_receiveEvent() const
{
	return m_message_Attribute_receiveEvent;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getMessage_Attribute_sendEvent() const
{
	return m_message_Attribute_sendEvent;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getMessage_Attribute_signature() const
{
	return m_message_Attribute_signature;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getMessage_Operation_arguments_EDiagnosticChain_EMap() const
{
	return m_message_Operation_arguments_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getMessage_Operation_cannot_cross_boundaries_EDiagnosticChain_EMap() const
{
	return m_message_Operation_cannot_cross_boundaries_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getMessage_Operation_getMessageKind() const
{
	return m_message_Operation_getMessageKind;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getMessage_Operation_occurrence_specifications_EDiagnosticChain_EMap() const
{
	return m_message_Operation_occurrence_specifications_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getMessage_Operation_sending_receiving_message_event_EDiagnosticChain_EMap() const
{
	return m_message_Operation_sending_receiving_message_event_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getMessage_Operation_signature_is_operation_reply_EDiagnosticChain_EMap() const
{
	return m_message_Operation_signature_is_operation_reply_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getMessage_Operation_signature_is_operation_request_EDiagnosticChain_EMap() const
{
	return m_message_Operation_signature_is_operation_request_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getMessage_Operation_signature_is_signal_EDiagnosticChain_EMap() const
{
	return m_message_Operation_signature_is_signal_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getMessage_Operation_signature_refer_to_EDiagnosticChain_EMap() const
{
	return m_message_Operation_signature_refer_to_EDiagnosticChain_EMap;
}

// End Class Message

// Begin Class MessageEnd
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getMessageEnd_Class() const
{
	return m_messageEnd_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getMessageEnd_Attribute_message() const
{
	return m_messageEnd_Attribute_message;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getMessageEnd_Operation_enclosingFragment() const
{
	return m_messageEnd_Operation_enclosingFragment;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getMessageEnd_Operation_isReceive() const
{
	return m_messageEnd_Operation_isReceive;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getMessageEnd_Operation_isSend() const
{
	return m_messageEnd_Operation_isSend;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getMessageEnd_Operation_oppositeEnd() const
{
	return m_messageEnd_Operation_oppositeEnd;
}

// End Class MessageEnd

// Begin Class MessageEvent
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getMessageEvent_Class() const
{
	return m_messageEvent_Class;
}




// End Class MessageEvent

// Begin Class MessageOccurrenceSpecification
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getMessageOccurrenceSpecification_Class() const
{
	return m_messageOccurrenceSpecification_Class;
}




// End Class MessageOccurrenceSpecification

// Begin Class Model
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getModel_Class() const
{
	return m_model_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getModel_Attribute_viewpoint() const
{
	return m_model_Attribute_viewpoint;
}


const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getModel_Operation_isMetamodel() const
{
	return m_model_Operation_isMetamodel;
}

// End Class Model

// Begin Class MultiplicityElement
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getMultiplicityElement_Class() const
{
	return m_multiplicityElement_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getMultiplicityElement_Attribute_isOrdered() const
{
	return m_multiplicityElement_Attribute_isOrdered;
}
const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getMultiplicityElement_Attribute_isUnique() const
{
	return m_multiplicityElement_Attribute_isUnique;
}
const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getMultiplicityElement_Attribute_lower() const
{
	return m_multiplicityElement_Attribute_lower;
}
const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getMultiplicityElement_Attribute_upper() const
{
	return m_multiplicityElement_Attribute_upper;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getMultiplicityElement_Attribute_lowerValue() const
{
	return m_multiplicityElement_Attribute_lowerValue;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getMultiplicityElement_Attribute_upperValue() const
{
	return m_multiplicityElement_Attribute_upperValue;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getMultiplicityElement_Operation_compatibleWith_MultiplicityElement() const
{
	return m_multiplicityElement_Operation_compatibleWith_MultiplicityElement;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getMultiplicityElement_Operation_includesMultiplicity_MultiplicityElement() const
{
	return m_multiplicityElement_Operation_includesMultiplicity_MultiplicityElement;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getMultiplicityElement_Operation_is_Integer_UnlimitedNatural() const
{
	return m_multiplicityElement_Operation_is_Integer_UnlimitedNatural;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getMultiplicityElement_Operation_isMultivalued() const
{
	return m_multiplicityElement_Operation_isMultivalued;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getMultiplicityElement_Operation_lowerBound() const
{
	return m_multiplicityElement_Operation_lowerBound;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getMultiplicityElement_Operation_lower_ge_0_EDiagnosticChain_EMap() const
{
	return m_multiplicityElement_Operation_lower_ge_0_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getMultiplicityElement_Operation_lower_is_integer_EDiagnosticChain_EMap() const
{
	return m_multiplicityElement_Operation_lower_is_integer_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getMultiplicityElement_Operation_upperBound() const
{
	return m_multiplicityElement_Operation_upperBound;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getMultiplicityElement_Operation_upper_ge_lower_EDiagnosticChain_EMap() const
{
	return m_multiplicityElement_Operation_upper_ge_lower_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getMultiplicityElement_Operation_upper_is_unlimitedNatural_EDiagnosticChain_EMap() const
{
	return m_multiplicityElement_Operation_upper_is_unlimitedNatural_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getMultiplicityElement_Operation_value_specification_constant_EDiagnosticChain_EMap() const
{
	return m_multiplicityElement_Operation_value_specification_constant_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getMultiplicityElement_Operation_value_specification_no_side_effects_EDiagnosticChain_EMap() const
{
	return m_multiplicityElement_Operation_value_specification_no_side_effects_EDiagnosticChain_EMap;
}

// End Class MultiplicityElement

// Begin Class NamedElement
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getNamedElement_Class() const
{
	return m_namedElement_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getNamedElement_Attribute_name() const
{
	return m_namedElement_Attribute_name;
}
const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getNamedElement_Attribute_qualifiedName() const
{
	return m_namedElement_Attribute_qualifiedName;
}
const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getNamedElement_Attribute_visibility() const
{
	return m_namedElement_Attribute_visibility;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getNamedElement_Attribute_clientDependency() const
{
	return m_namedElement_Attribute_clientDependency;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getNamedElement_Attribute_nameExpression() const
{
	return m_namedElement_Attribute_nameExpression;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getNamedElement_Attribute_namespace() const
{
	return m_namedElement_Attribute_namespace;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getNamedElement_Operation_allNamespaces() const
{
	return m_namedElement_Operation_allNamespaces;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getNamedElement_Operation_allOwningPackages() const
{
	return m_namedElement_Operation_allOwningPackages;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getNamedElement_Operation_createDependency_NamedElement() const
{
	return m_namedElement_Operation_createDependency_NamedElement;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getNamedElement_Operation_createUsage_NamedElement() const
{
	return m_namedElement_Operation_createUsage_NamedElement;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getNamedElement_Operation_getClientDependencies() const
{
	return m_namedElement_Operation_getClientDependencies;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getNamedElement_Operation_getLabel() const
{
	return m_namedElement_Operation_getLabel;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getNamedElement_Operation_getLabel_Boolean() const
{
	return m_namedElement_Operation_getLabel_Boolean;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getNamedElement_Operation_getNamespace() const
{
	return m_namedElement_Operation_getNamespace;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getNamedElement_Operation_getQualifiedName() const
{
	return m_namedElement_Operation_getQualifiedName;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getNamedElement_Operation_has_no_qualified_name_EDiagnosticChain_EMap() const
{
	return m_namedElement_Operation_has_no_qualified_name_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getNamedElement_Operation_has_qualified_name_EDiagnosticChain_EMap() const
{
	return m_namedElement_Operation_has_qualified_name_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getNamedElement_Operation_isDistinguishableFrom_NamedElement_Namespace() const
{
	return m_namedElement_Operation_isDistinguishableFrom_NamedElement_Namespace;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getNamedElement_Operation_separator() const
{
	return m_namedElement_Operation_separator;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getNamedElement_Operation_visibility_needs_ownership_EDiagnosticChain_EMap() const
{
	return m_namedElement_Operation_visibility_needs_ownership_EDiagnosticChain_EMap;
}

// End Class NamedElement

// Begin Class Namespace
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getNamespace_Class() const
{
	return m_namespace_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getNamespace_Attribute_elementImport() const
{
	return m_namespace_Attribute_elementImport;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getNamespace_Attribute_importedMember() const
{
	return m_namespace_Attribute_importedMember;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getNamespace_Attribute_member() const
{
	return m_namespace_Attribute_member;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getNamespace_Attribute_ownedMember() const
{
	return m_namespace_Attribute_ownedMember;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getNamespace_Attribute_ownedRule() const
{
	return m_namespace_Attribute_ownedRule;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getNamespace_Attribute_packageImport() const
{
	return m_namespace_Attribute_packageImport;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getNamespace_Operation_cannot_import_ownedMembers_EDiagnosticChain_EMap() const
{
	return m_namespace_Operation_cannot_import_ownedMembers_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getNamespace_Operation_cannot_import_self_EDiagnosticChain_EMap() const
{
	return m_namespace_Operation_cannot_import_self_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getNamespace_Operation_createElementImport_PackageableElement_VisibilityKind() const
{
	return m_namespace_Operation_createElementImport_PackageableElement_VisibilityKind;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getNamespace_Operation_createPackageImport_Package_VisibilityKind() const
{
	return m_namespace_Operation_createPackageImport_Package_VisibilityKind;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getNamespace_Operation_excludeCollisions_PackageableElement() const
{
	return m_namespace_Operation_excludeCollisions_PackageableElement;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getNamespace_Operation_getImportedElements() const
{
	return m_namespace_Operation_getImportedElements;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getNamespace_Operation_getImportedMembers() const
{
	return m_namespace_Operation_getImportedMembers;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getNamespace_Operation_getImportedPackages() const
{
	return m_namespace_Operation_getImportedPackages;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getNamespace_Operation_getNamesOfMember_NamedElement() const
{
	return m_namespace_Operation_getNamesOfMember_NamedElement;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getNamespace_Operation_getOwnedMembers() const
{
	return m_namespace_Operation_getOwnedMembers;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getNamespace_Operation_importMembers_PackageableElement() const
{
	return m_namespace_Operation_importMembers_PackageableElement;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getNamespace_Operation_membersAreDistinguishable() const
{
	return m_namespace_Operation_membersAreDistinguishable;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getNamespace_Operation_members_distinguishable_EDiagnosticChain_EMap() const
{
	return m_namespace_Operation_members_distinguishable_EDiagnosticChain_EMap;
}

// End Class Namespace

// Begin Class Node
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getNode_Class() const
{
	return m_node_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getNode_Attribute_nestedNode() const
{
	return m_node_Attribute_nestedNode;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getNode_Operation_createCommunicationPath_Boolean_UnlimitedNatural() const
{
	return m_node_Operation_createCommunicationPath_Boolean_UnlimitedNatural;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getNode_Operation_getCommunicationPaths() const
{
	return m_node_Operation_getCommunicationPaths;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getNode_Operation_internal_structure_EDiagnosticChain_EMap() const
{
	return m_node_Operation_internal_structure_EDiagnosticChain_EMap;
}

// End Class Node

// Begin Class Object
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getObject_Class() const
{
	return m_object_Class;
}



const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getObject_Operation_get_Property() const
{
	return m_object_Operation_get_Property;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getObject_Operation_invoke_Operation_Argument() const
{
	return m_object_Operation_invoke_Operation_Argument;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getObject_Operation_set_Property_EJavaObject() const
{
	return m_object_Operation_set_Property_EJavaObject;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getObject_Operation_unset_Property() const
{
	return m_object_Operation_unset_Property;
}

// End Class Object

// Begin Class ObjectFlow
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getObjectFlow_Class() const
{
	return m_objectFlow_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getObjectFlow_Attribute_isMulticast() const
{
	return m_objectFlow_Attribute_isMulticast;
}
const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getObjectFlow_Attribute_isMultireceive() const
{
	return m_objectFlow_Attribute_isMultireceive;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getObjectFlow_Attribute_selection() const
{
	return m_objectFlow_Attribute_selection;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getObjectFlow_Attribute_transformation() const
{
	return m_objectFlow_Attribute_transformation;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getObjectFlow_Operation_compatible_types_EDiagnosticChain_EMap() const
{
	return m_objectFlow_Operation_compatible_types_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getObjectFlow_Operation_input_and_output_parameter_EDiagnosticChain_EMap() const
{
	return m_objectFlow_Operation_input_and_output_parameter_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getObjectFlow_Operation_is_multicast_or_is_multireceive_EDiagnosticChain_EMap() const
{
	return m_objectFlow_Operation_is_multicast_or_is_multireceive_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getObjectFlow_Operation_no_executable_nodes_EDiagnosticChain_EMap() const
{
	return m_objectFlow_Operation_no_executable_nodes_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getObjectFlow_Operation_same_upper_bounds_EDiagnosticChain_EMap() const
{
	return m_objectFlow_Operation_same_upper_bounds_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getObjectFlow_Operation_selection_behavior_EDiagnosticChain_EMap() const
{
	return m_objectFlow_Operation_selection_behavior_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getObjectFlow_Operation_target_EDiagnosticChain_EMap() const
{
	return m_objectFlow_Operation_target_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getObjectFlow_Operation_transformation_behavior_EDiagnosticChain_EMap() const
{
	return m_objectFlow_Operation_transformation_behavior_EDiagnosticChain_EMap;
}

// End Class ObjectFlow

// Begin Class ObjectNode
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getObjectNode_Class() const
{
	return m_objectNode_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getObjectNode_Attribute_isControlType() const
{
	return m_objectNode_Attribute_isControlType;
}
const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getObjectNode_Attribute_ordering() const
{
	return m_objectNode_Attribute_ordering;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getObjectNode_Attribute_inState() const
{
	return m_objectNode_Attribute_inState;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getObjectNode_Attribute_selection() const
{
	return m_objectNode_Attribute_selection;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getObjectNode_Attribute_upperBound() const
{
	return m_objectNode_Attribute_upperBound;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getObjectNode_Operation_input_output_parameter_EDiagnosticChain_EMap() const
{
	return m_objectNode_Operation_input_output_parameter_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getObjectNode_Operation_object_flow_edges_EDiagnosticChain_EMap() const
{
	return m_objectNode_Operation_object_flow_edges_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getObjectNode_Operation_selection_behavior_EDiagnosticChain_EMap() const
{
	return m_objectNode_Operation_selection_behavior_EDiagnosticChain_EMap;
}

// End Class ObjectNode

// Begin Class Observation
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getObservation_Class() const
{
	return m_observation_Class;
}




// End Class Observation

// Begin Class OccurrenceSpecification
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getOccurrenceSpecification_Class() const
{
	return m_occurrenceSpecification_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getOccurrenceSpecification_Attribute_toAfter() const
{
	return m_occurrenceSpecification_Attribute_toAfter;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getOccurrenceSpecification_Attribute_toBefore() const
{
	return m_occurrenceSpecification_Attribute_toBefore;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getOccurrenceSpecification_Operation_getCovered() const
{
	return m_occurrenceSpecification_Operation_getCovered;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getOccurrenceSpecification_Operation_setCovered_Lifeline() const
{
	return m_occurrenceSpecification_Operation_setCovered_Lifeline;
}

// End Class OccurrenceSpecification

// Begin Class OpaqueAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getOpaqueAction_Class() const
{
	return m_opaqueAction_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getOpaqueAction_Attribute_body() const
{
	return m_opaqueAction_Attribute_body;
}
const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getOpaqueAction_Attribute_language() const
{
	return m_opaqueAction_Attribute_language;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getOpaqueAction_Attribute_inputValue() const
{
	return m_opaqueAction_Attribute_inputValue;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getOpaqueAction_Attribute_outputValue() const
{
	return m_opaqueAction_Attribute_outputValue;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getOpaqueAction_Operation_language_body_size_EDiagnosticChain_EMap() const
{
	return m_opaqueAction_Operation_language_body_size_EDiagnosticChain_EMap;
}

// End Class OpaqueAction

// Begin Class OpaqueBehavior
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getOpaqueBehavior_Class() const
{
	return m_opaqueBehavior_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getOpaqueBehavior_Attribute_body() const
{
	return m_opaqueBehavior_Attribute_body;
}
const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getOpaqueBehavior_Attribute_language() const
{
	return m_opaqueBehavior_Attribute_language;
}



// End Class OpaqueBehavior

// Begin Class OpaqueExpression
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getOpaqueExpression_Class() const
{
	return m_opaqueExpression_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getOpaqueExpression_Attribute_body() const
{
	return m_opaqueExpression_Attribute_body;
}
const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getOpaqueExpression_Attribute_language() const
{
	return m_opaqueExpression_Attribute_language;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getOpaqueExpression_Attribute_behavior() const
{
	return m_opaqueExpression_Attribute_behavior;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getOpaqueExpression_Attribute_result() const
{
	return m_opaqueExpression_Attribute_result;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getOpaqueExpression_Operation_getResult() const
{
	return m_opaqueExpression_Operation_getResult;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getOpaqueExpression_Operation_isIntegral() const
{
	return m_opaqueExpression_Operation_isIntegral;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getOpaqueExpression_Operation_isNonNegative() const
{
	return m_opaqueExpression_Operation_isNonNegative;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getOpaqueExpression_Operation_isPositive() const
{
	return m_opaqueExpression_Operation_isPositive;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getOpaqueExpression_Operation_language_body_size_EDiagnosticChain_EMap() const
{
	return m_opaqueExpression_Operation_language_body_size_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getOpaqueExpression_Operation_one_return_result_parameter_EDiagnosticChain_EMap() const
{
	return m_opaqueExpression_Operation_one_return_result_parameter_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getOpaqueExpression_Operation_only_return_result_parameters_EDiagnosticChain_EMap() const
{
	return m_opaqueExpression_Operation_only_return_result_parameters_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getOpaqueExpression_Operation_value() const
{
	return m_opaqueExpression_Operation_value;
}

// End Class OpaqueExpression

// Begin Class Operation
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getOperation_Class() const
{
	return m_operation_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getOperation_Attribute_isOrdered() const
{
	return m_operation_Attribute_isOrdered;
}
const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getOperation_Attribute_isQuery() const
{
	return m_operation_Attribute_isQuery;
}
const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getOperation_Attribute_isUnique() const
{
	return m_operation_Attribute_isUnique;
}
const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getOperation_Attribute_lower() const
{
	return m_operation_Attribute_lower;
}
const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getOperation_Attribute_upper() const
{
	return m_operation_Attribute_upper;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getOperation_Attribute_bodyCondition() const
{
	return m_operation_Attribute_bodyCondition;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getOperation_Attribute_class() const
{
	return m_operation_Attribute_class;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getOperation_Attribute_datatype() const
{
	return m_operation_Attribute_datatype;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getOperation_Attribute_interface() const
{
	return m_operation_Attribute_interface;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getOperation_Attribute_ownedParameter() const
{
	return m_operation_Attribute_ownedParameter;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getOperation_Attribute_postcondition() const
{
	return m_operation_Attribute_postcondition;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getOperation_Attribute_precondition() const
{
	return m_operation_Attribute_precondition;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getOperation_Attribute_redefinedOperation() const
{
	return m_operation_Attribute_redefinedOperation;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getOperation_Attribute_type() const
{
	return m_operation_Attribute_type;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getOperation_Operation_at_most_one_return_EDiagnosticChain_EMap() const
{
	return m_operation_Operation_at_most_one_return_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getOperation_Operation_getLower() const
{
	return m_operation_Operation_getLower;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getOperation_Operation_getReturnResult() const
{
	return m_operation_Operation_getReturnResult;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getOperation_Operation_getType() const
{
	return m_operation_Operation_getType;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getOperation_Operation_getUpper() const
{
	return m_operation_Operation_getUpper;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getOperation_Operation_isOrdered() const
{
	return m_operation_Operation_isOrdered;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getOperation_Operation_isUnique() const
{
	return m_operation_Operation_isUnique;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getOperation_Operation_matches_Operation() const
{
	return m_operation_Operation_matches_Operation;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getOperation_Operation_only_body_for_query_EDiagnosticChain_EMap() const
{
	return m_operation_Operation_only_body_for_query_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getOperation_Operation_returnResult() const
{
	return m_operation_Operation_returnResult;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getOperation_Operation_setIsOrdered_Boolean() const
{
	return m_operation_Operation_setIsOrdered_Boolean;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getOperation_Operation_setIsUnique_Boolean() const
{
	return m_operation_Operation_setIsUnique_Boolean;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getOperation_Operation_setLower_Integer() const
{
	return m_operation_Operation_setLower_Integer;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getOperation_Operation_setType_Type() const
{
	return m_operation_Operation_setType_Type;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getOperation_Operation_setUpper_UnlimitedNatural() const
{
	return m_operation_Operation_setUpper_UnlimitedNatural;
}

// End Class Operation

// Begin Class OperationTemplateParameter
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getOperationTemplateParameter_Class() const
{
	return m_operationTemplateParameter_Class;
}



const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getOperationTemplateParameter_Operation_match_default_signature_EDiagnosticChain_EMap() const
{
	return m_operationTemplateParameter_Operation_match_default_signature_EDiagnosticChain_EMap;
}

// End Class OperationTemplateParameter

// Begin Class OutputPin
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getOutputPin_Class() const
{
	return m_outputPin_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getOutputPin_Attribute_action() const
{
	return m_outputPin_Attribute_action;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getOutputPin_Attribute_callAction() const
{
	return m_outputPin_Attribute_callAction;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getOutputPin_Attribute_clearStructuralFeatureAction() const
{
	return m_outputPin_Attribute_clearStructuralFeatureAction;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getOutputPin_Attribute_createObjectAction() const
{
	return m_outputPin_Attribute_createObjectAction;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getOutputPin_Attribute_readSelfAction() const
{
	return m_outputPin_Attribute_readSelfAction;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getOutputPin_Attribute_readStructuralFeatureAction() const
{
	return m_outputPin_Attribute_readStructuralFeatureAction;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getOutputPin_Attribute_valueSpecificationAction() const
{
	return m_outputPin_Attribute_valueSpecificationAction;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getOutputPin_Attribute_writeStructuralFeatureAction() const
{
	return m_outputPin_Attribute_writeStructuralFeatureAction;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getOutputPin_Operation_incoming_edges_structured_only_EDiagnosticChain_EMap() const
{
	return m_outputPin_Operation_incoming_edges_structured_only_EDiagnosticChain_EMap;
}

// End Class OutputPin

// Begin Class Package
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getPackage_Class() const
{
	return m_package_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getPackage_Attribute_uRI() const
{
	return m_package_Attribute_uRI;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getPackage_Attribute_nestedPackage() const
{
	return m_package_Attribute_nestedPackage;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getPackage_Attribute_nestingPackage() const
{
	return m_package_Attribute_nestingPackage;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getPackage_Attribute_ownedStereotype() const
{
	return m_package_Attribute_ownedStereotype;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getPackage_Attribute_ownedType() const
{
	return m_package_Attribute_ownedType;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getPackage_Attribute_packageMerge() const
{
	return m_package_Attribute_packageMerge;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getPackage_Attribute_packagedElement() const
{
	return m_package_Attribute_packagedElement;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getPackage_Attribute_profileApplication() const
{
	return m_package_Attribute_profileApplication;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPackage_Operation_allApplicableStereotypes() const
{
	return m_package_Operation_allApplicableStereotypes;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPackage_Operation_applyProfile_Profile() const
{
	return m_package_Operation_applyProfile_Profile;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPackage_Operation_containingProfile() const
{
	return m_package_Operation_containingProfile;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPackage_Operation_createOwnedClass_String_Boolean() const
{
	return m_package_Operation_createOwnedClass_String_Boolean;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPackage_Operation_createOwnedEnumeration_String() const
{
	return m_package_Operation_createOwnedEnumeration_String;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPackage_Operation_createOwnedInterface_String() const
{
	return m_package_Operation_createOwnedInterface_String;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPackage_Operation_createOwnedPrimitiveType_String() const
{
	return m_package_Operation_createOwnedPrimitiveType_String;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPackage_Operation_createOwnedStereotype_String_Boolean() const
{
	return m_package_Operation_createOwnedStereotype_String_Boolean;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPackage_Operation_elements_public_or_private_EDiagnosticChain_EMap() const
{
	return m_package_Operation_elements_public_or_private_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPackage_Operation_getAllAppliedProfiles() const
{
	return m_package_Operation_getAllAppliedProfiles;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPackage_Operation_getAllProfileApplications() const
{
	return m_package_Operation_getAllProfileApplications;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPackage_Operation_getAppliedProfile_String() const
{
	return m_package_Operation_getAppliedProfile_String;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPackage_Operation_getAppliedProfile_String_Boolean() const
{
	return m_package_Operation_getAppliedProfile_String_Boolean;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPackage_Operation_getAppliedProfiles() const
{
	return m_package_Operation_getAppliedProfiles;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPackage_Operation_getNestedPackages() const
{
	return m_package_Operation_getNestedPackages;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPackage_Operation_getOwnedStereotypes() const
{
	return m_package_Operation_getOwnedStereotypes;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPackage_Operation_getOwnedTypes() const
{
	return m_package_Operation_getOwnedTypes;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPackage_Operation_getProfileApplication_Profile() const
{
	return m_package_Operation_getProfileApplication_Profile;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPackage_Operation_getProfileApplication_Profile_Boolean() const
{
	return m_package_Operation_getProfileApplication_Profile_Boolean;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPackage_Operation_isModelLibrary() const
{
	return m_package_Operation_isModelLibrary;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPackage_Operation_isProfileApplied_Profile() const
{
	return m_package_Operation_isProfileApplied_Profile;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPackage_Operation_makesVisible_NamedElement() const
{
	return m_package_Operation_makesVisible_NamedElement;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPackage_Operation_unapplyProfile_Profile() const
{
	return m_package_Operation_unapplyProfile_Profile;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPackage_Operation_visibleMembers() const
{
	return m_package_Operation_visibleMembers;
}

// End Class Package

// Begin Class PackageImport
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getPackageImport_Class() const
{
	return m_packageImport_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getPackageImport_Attribute_visibility() const
{
	return m_packageImport_Attribute_visibility;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getPackageImport_Attribute_importedPackage() const
{
	return m_packageImport_Attribute_importedPackage;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getPackageImport_Attribute_importingNamespace() const
{
	return m_packageImport_Attribute_importingNamespace;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPackageImport_Operation_public_or_private_EDiagnosticChain_EMap() const
{
	return m_packageImport_Operation_public_or_private_EDiagnosticChain_EMap;
}

// End Class PackageImport

// Begin Class PackageMerge
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getPackageMerge_Class() const
{
	return m_packageMerge_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getPackageMerge_Attribute_mergedPackage() const
{
	return m_packageMerge_Attribute_mergedPackage;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getPackageMerge_Attribute_receivingPackage() const
{
	return m_packageMerge_Attribute_receivingPackage;
}


// End Class PackageMerge

// Begin Class PackageableElement
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getPackageableElement_Class() const
{
	return m_packageableElement_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getPackageableElement_Attribute_owningPackage() const
{
	return m_packageableElement_Attribute_owningPackage;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPackageableElement_Operation_namespace_needs_visibility_EDiagnosticChain_EMap() const
{
	return m_packageableElement_Operation_namespace_needs_visibility_EDiagnosticChain_EMap;
}

// End Class PackageableElement

// Begin Class Parameter
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getParameter_Class() const
{
	return m_parameter_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getParameter_Attribute_default() const
{
	return m_parameter_Attribute_default;
}
const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getParameter_Attribute_direction() const
{
	return m_parameter_Attribute_direction;
}
const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getParameter_Attribute_effect() const
{
	return m_parameter_Attribute_effect;
}
const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getParameter_Attribute_isException() const
{
	return m_parameter_Attribute_isException;
}
const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getParameter_Attribute_isStream() const
{
	return m_parameter_Attribute_isStream;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getParameter_Attribute_behavior() const
{
	return m_parameter_Attribute_behavior;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getParameter_Attribute_defaultValue() const
{
	return m_parameter_Attribute_defaultValue;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getParameter_Attribute_operation() const
{
	return m_parameter_Attribute_operation;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getParameter_Attribute_parameterSet() const
{
	return m_parameter_Attribute_parameterSet;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getParameter_Operation_connector_end_EDiagnosticChain_EMap() const
{
	return m_parameter_Operation_connector_end_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getParameter_Operation_in_and_out_EDiagnosticChain_EMap() const
{
	return m_parameter_Operation_in_and_out_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getParameter_Operation_isSetDefault() const
{
	return m_parameter_Operation_isSetDefault;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getParameter_Operation_not_exception_EDiagnosticChain_EMap() const
{
	return m_parameter_Operation_not_exception_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getParameter_Operation_object_effect_EDiagnosticChain_EMap() const
{
	return m_parameter_Operation_object_effect_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getParameter_Operation_reentrant_behaviors_EDiagnosticChain_EMap() const
{
	return m_parameter_Operation_reentrant_behaviors_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getParameter_Operation_setBooleanDefaultValue_Boolean() const
{
	return m_parameter_Operation_setBooleanDefaultValue_Boolean;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getParameter_Operation_setIntegerDefaultValue_Integer() const
{
	return m_parameter_Operation_setIntegerDefaultValue_Integer;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getParameter_Operation_setNullDefaultValue() const
{
	return m_parameter_Operation_setNullDefaultValue;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getParameter_Operation_setRealDefaultValue_Real() const
{
	return m_parameter_Operation_setRealDefaultValue_Real;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getParameter_Operation_setStringDefaultValue_String() const
{
	return m_parameter_Operation_setStringDefaultValue_String;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getParameter_Operation_setUnlimitedNaturalDefaultValue_UnlimitedNatural() const
{
	return m_parameter_Operation_setUnlimitedNaturalDefaultValue_UnlimitedNatural;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getParameter_Operation_stream_and_exception_EDiagnosticChain_EMap() const
{
	return m_parameter_Operation_stream_and_exception_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getParameter_Operation_unsetDefault() const
{
	return m_parameter_Operation_unsetDefault;
}

// End Class Parameter

// Begin Class ParameterSet
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getParameterSet_Class() const
{
	return m_parameterSet_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getParameterSet_Attribute_condition() const
{
	return m_parameterSet_Attribute_condition;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getParameterSet_Attribute_parameter() const
{
	return m_parameterSet_Attribute_parameter;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getParameterSet_Operation_input_EDiagnosticChain_EMap() const
{
	return m_parameterSet_Operation_input_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getParameterSet_Operation_same_parameterized_entity_EDiagnosticChain_EMap() const
{
	return m_parameterSet_Operation_same_parameterized_entity_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getParameterSet_Operation_two_parameter_sets_EDiagnosticChain_EMap() const
{
	return m_parameterSet_Operation_two_parameter_sets_EDiagnosticChain_EMap;
}

// End Class ParameterSet

// Begin Class ParameterableElement
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getParameterableElement_Class() const
{
	return m_parameterableElement_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getParameterableElement_Attribute_owningTemplateParameter() const
{
	return m_parameterableElement_Attribute_owningTemplateParameter;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getParameterableElement_Attribute_templateParameter() const
{
	return m_parameterableElement_Attribute_templateParameter;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getParameterableElement_Operation_isCompatibleWith_ParameterableElement() const
{
	return m_parameterableElement_Operation_isCompatibleWith_ParameterableElement;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getParameterableElement_Operation_isTemplateParameter() const
{
	return m_parameterableElement_Operation_isTemplateParameter;
}

// End Class ParameterableElement

// Begin Class PartDecomposition
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getPartDecomposition_Class() const
{
	return m_partDecomposition_Class;
}



const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPartDecomposition_Operation_assume_EDiagnosticChain_EMap() const
{
	return m_partDecomposition_Operation_assume_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPartDecomposition_Operation_commutativity_of_decomposition_EDiagnosticChain_EMap() const
{
	return m_partDecomposition_Operation_commutativity_of_decomposition_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPartDecomposition_Operation_parts_of_internal_structures_EDiagnosticChain_EMap() const
{
	return m_partDecomposition_Operation_parts_of_internal_structures_EDiagnosticChain_EMap;
}

// End Class PartDecomposition

// Begin Class Pin
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getPin_Class() const
{
	return m_pin_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getPin_Attribute_isControl() const
{
	return m_pin_Attribute_isControl;
}


const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPin_Operation_control_pins_EDiagnosticChain_EMap() const
{
	return m_pin_Operation_control_pins_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPin_Operation_not_unique_EDiagnosticChain_EMap() const
{
	return m_pin_Operation_not_unique_EDiagnosticChain_EMap;
}

// End Class Pin

// Begin Class Port
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getPort_Class() const
{
	return m_port_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getPort_Attribute_isBehavior() const
{
	return m_port_Attribute_isBehavior;
}
const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getPort_Attribute_isConjugated() const
{
	return m_port_Attribute_isConjugated;
}
const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getPort_Attribute_isService() const
{
	return m_port_Attribute_isService;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getPort_Attribute_protocol() const
{
	return m_port_Attribute_protocol;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getPort_Attribute_provided() const
{
	return m_port_Attribute_provided;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getPort_Attribute_redefinedPort() const
{
	return m_port_Attribute_redefinedPort;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getPort_Attribute_required() const
{
	return m_port_Attribute_required;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPort_Operation_basicProvided() const
{
	return m_port_Operation_basicProvided;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPort_Operation_basicRequired() const
{
	return m_port_Operation_basicRequired;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPort_Operation_default_value_EDiagnosticChain_EMap() const
{
	return m_port_Operation_default_value_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPort_Operation_encapsulated_owner_EDiagnosticChain_EMap() const
{
	return m_port_Operation_encapsulated_owner_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPort_Operation_getProvideds() const
{
	return m_port_Operation_getProvideds;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPort_Operation_getRequireds() const
{
	return m_port_Operation_getRequireds;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPort_Operation_port_aggregation_EDiagnosticChain_EMap() const
{
	return m_port_Operation_port_aggregation_EDiagnosticChain_EMap;
}

// End Class Port

// Begin Class PrimitiveType
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getPrimitiveType_Class() const
{
	return m_primitiveType_Class;
}




// End Class PrimitiveType

// Begin Class Profile
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getProfile_Class() const
{
	return m_profile_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getProfile_Attribute_metaclassReference() const
{
	return m_profile_Attribute_metaclassReference;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getProfile_Attribute_metamodelReference() const
{
	return m_profile_Attribute_metamodelReference;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProfile_Operation_create_Classifier() const
{
	return m_profile_Operation_create_Classifier;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProfile_Operation_define() const
{
	return m_profile_Operation_define;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProfile_Operation_define_EMap_EMap() const
{
	return m_profile_Operation_define_EMap_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProfile_Operation_getDefinition() const
{
	return m_profile_Operation_getDefinition;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProfile_Operation_getDefinition_NamedElement() const
{
	return m_profile_Operation_getDefinition_NamedElement;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProfile_Operation_getOwnedExtensions_Boolean() const
{
	return m_profile_Operation_getOwnedExtensions_Boolean;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProfile_Operation_getReferencedMetaclasses() const
{
	return m_profile_Operation_getReferencedMetaclasses;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProfile_Operation_getReferencedMetamodels() const
{
	return m_profile_Operation_getReferencedMetamodels;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProfile_Operation_isDefined() const
{
	return m_profile_Operation_isDefined;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProfile_Operation_metaclass_reference_not_specialized_EDiagnosticChain_EMap() const
{
	return m_profile_Operation_metaclass_reference_not_specialized_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProfile_Operation_references_same_metamodel_EDiagnosticChain_EMap() const
{
	return m_profile_Operation_references_same_metamodel_EDiagnosticChain_EMap;
}

// End Class Profile

// Begin Class ProfileApplication
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getProfileApplication_Class() const
{
	return m_profileApplication_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getProfileApplication_Attribute_isStrict() const
{
	return m_profileApplication_Attribute_isStrict;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getProfileApplication_Attribute_appliedProfile() const
{
	return m_profileApplication_Attribute_appliedProfile;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getProfileApplication_Attribute_applyingPackage() const
{
	return m_profileApplication_Attribute_applyingPackage;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProfileApplication_Operation_getAppliedDefinition() const
{
	return m_profileApplication_Operation_getAppliedDefinition;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProfileApplication_Operation_getAppliedDefinition_NamedElement() const
{
	return m_profileApplication_Operation_getAppliedDefinition_NamedElement;
}

// End Class ProfileApplication

// Begin Class Property
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getProperty_Class() const
{
	return m_property_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getProperty_Attribute_aggregation() const
{
	return m_property_Attribute_aggregation;
}
const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getProperty_Attribute_default() const
{
	return m_property_Attribute_default;
}
const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getProperty_Attribute_isComposite() const
{
	return m_property_Attribute_isComposite;
}
const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getProperty_Attribute_isDerived() const
{
	return m_property_Attribute_isDerived;
}
const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getProperty_Attribute_isDerivedUnion() const
{
	return m_property_Attribute_isDerivedUnion;
}
const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getProperty_Attribute_isID() const
{
	return m_property_Attribute_isID;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getProperty_Attribute_association() const
{
	return m_property_Attribute_association;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getProperty_Attribute_associationEnd() const
{
	return m_property_Attribute_associationEnd;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getProperty_Attribute_class() const
{
	return m_property_Attribute_class;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getProperty_Attribute_datatype() const
{
	return m_property_Attribute_datatype;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getProperty_Attribute_defaultValue() const
{
	return m_property_Attribute_defaultValue;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getProperty_Attribute_interface() const
{
	return m_property_Attribute_interface;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getProperty_Attribute_opposite() const
{
	return m_property_Attribute_opposite;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getProperty_Attribute_owningAssociation() const
{
	return m_property_Attribute_owningAssociation;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getProperty_Attribute_qualifier() const
{
	return m_property_Attribute_qualifier;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getProperty_Attribute_redefinedProperty() const
{
	return m_property_Attribute_redefinedProperty;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getProperty_Attribute_subsettedProperty() const
{
	return m_property_Attribute_subsettedProperty;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProperty_Operation_binding_to_attribute_EDiagnosticChain_EMap() const
{
	return m_property_Operation_binding_to_attribute_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProperty_Operation_deployment_target_EDiagnosticChain_EMap() const
{
	return m_property_Operation_deployment_target_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProperty_Operation_derived_union_is_derived_EDiagnosticChain_EMap() const
{
	return m_property_Operation_derived_union_is_derived_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProperty_Operation_derived_union_is_read_only_EDiagnosticChain_EMap() const
{
	return m_property_Operation_derived_union_is_read_only_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProperty_Operation_getOpposite() const
{
	return m_property_Operation_getOpposite;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProperty_Operation_getOtherEnd() const
{
	return m_property_Operation_getOtherEnd;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProperty_Operation_isAttribute() const
{
	return m_property_Operation_isAttribute;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProperty_Operation_isComposite() const
{
	return m_property_Operation_isComposite;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProperty_Operation_isNavigable() const
{
	return m_property_Operation_isNavigable;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProperty_Operation_isSetDefault() const
{
	return m_property_Operation_isSetDefault;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProperty_Operation_multiplicity_of_composite_EDiagnosticChain_EMap() const
{
	return m_property_Operation_multiplicity_of_composite_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProperty_Operation_qualified_is_association_end_EDiagnosticChain_EMap() const
{
	return m_property_Operation_qualified_is_association_end_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProperty_Operation_redefined_property_inherited_EDiagnosticChain_EMap() const
{
	return m_property_Operation_redefined_property_inherited_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProperty_Operation_setBooleanDefaultValue_Boolean() const
{
	return m_property_Operation_setBooleanDefaultValue_Boolean;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProperty_Operation_setIntegerDefaultValue_Integer() const
{
	return m_property_Operation_setIntegerDefaultValue_Integer;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProperty_Operation_setIsNavigable_Boolean() const
{
	return m_property_Operation_setIsNavigable_Boolean;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProperty_Operation_setNullDefaultValue() const
{
	return m_property_Operation_setNullDefaultValue;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProperty_Operation_setRealDefaultValue_Real() const
{
	return m_property_Operation_setRealDefaultValue_Real;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProperty_Operation_setStringDefaultValue_String() const
{
	return m_property_Operation_setStringDefaultValue_String;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProperty_Operation_setUnlimitedNaturalDefaultValue_UnlimitedNatural() const
{
	return m_property_Operation_setUnlimitedNaturalDefaultValue_UnlimitedNatural;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProperty_Operation_subsetted_property_names_EDiagnosticChain_EMap() const
{
	return m_property_Operation_subsetted_property_names_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProperty_Operation_subsettingContext() const
{
	return m_property_Operation_subsettingContext;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProperty_Operation_subsetting_context_conforms_EDiagnosticChain_EMap() const
{
	return m_property_Operation_subsetting_context_conforms_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProperty_Operation_subsetting_rules_EDiagnosticChain_EMap() const
{
	return m_property_Operation_subsetting_rules_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProperty_Operation_type_of_opposite_end_EDiagnosticChain_EMap() const
{
	return m_property_Operation_type_of_opposite_end_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProperty_Operation_unsetDefault() const
{
	return m_property_Operation_unsetDefault;
}

// End Class Property

// Begin Class ProtocolConformance
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getProtocolConformance_Class() const
{
	return m_protocolConformance_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getProtocolConformance_Attribute_generalMachine() const
{
	return m_protocolConformance_Attribute_generalMachine;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getProtocolConformance_Attribute_specificMachine() const
{
	return m_protocolConformance_Attribute_specificMachine;
}


// End Class ProtocolConformance

// Begin Class ProtocolStateMachine
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getProtocolStateMachine_Class() const
{
	return m_protocolStateMachine_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getProtocolStateMachine_Attribute_conformance() const
{
	return m_protocolStateMachine_Attribute_conformance;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProtocolStateMachine_Operation_deep_or_shallow_history_EDiagnosticChain_EMap() const
{
	return m_protocolStateMachine_Operation_deep_or_shallow_history_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProtocolStateMachine_Operation_entry_exit_do_EDiagnosticChain_EMap() const
{
	return m_protocolStateMachine_Operation_entry_exit_do_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProtocolStateMachine_Operation_protocol_transitions_EDiagnosticChain_EMap() const
{
	return m_protocolStateMachine_Operation_protocol_transitions_EDiagnosticChain_EMap;
}

// End Class ProtocolStateMachine

// Begin Class ProtocolTransition
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getProtocolTransition_Class() const
{
	return m_protocolTransition_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getProtocolTransition_Attribute_postCondition() const
{
	return m_protocolTransition_Attribute_postCondition;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getProtocolTransition_Attribute_preCondition() const
{
	return m_protocolTransition_Attribute_preCondition;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getProtocolTransition_Attribute_referred() const
{
	return m_protocolTransition_Attribute_referred;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProtocolTransition_Operation_associated_actions_EDiagnosticChain_EMap() const
{
	return m_protocolTransition_Operation_associated_actions_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProtocolTransition_Operation_belongs_to_psm_EDiagnosticChain_EMap() const
{
	return m_protocolTransition_Operation_belongs_to_psm_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProtocolTransition_Operation_getReferreds() const
{
	return m_protocolTransition_Operation_getReferreds;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getProtocolTransition_Operation_refers_to_operation_EDiagnosticChain_EMap() const
{
	return m_protocolTransition_Operation_refers_to_operation_EDiagnosticChain_EMap;
}

// End Class ProtocolTransition

// Begin Class Pseudostate
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getPseudostate_Class() const
{
	return m_pseudostate_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getPseudostate_Attribute_kind() const
{
	return m_pseudostate_Attribute_kind;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getPseudostate_Attribute_state() const
{
	return m_pseudostate_Attribute_state;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getPseudostate_Attribute_stateMachine() const
{
	return m_pseudostate_Attribute_stateMachine;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPseudostate_Operation_choice_vertex_EDiagnosticChain_EMap() const
{
	return m_pseudostate_Operation_choice_vertex_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPseudostate_Operation_fork_vertex_EDiagnosticChain_EMap() const
{
	return m_pseudostate_Operation_fork_vertex_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPseudostate_Operation_history_vertices_EDiagnosticChain_EMap() const
{
	return m_pseudostate_Operation_history_vertices_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPseudostate_Operation_initial_vertex_EDiagnosticChain_EMap() const
{
	return m_pseudostate_Operation_initial_vertex_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPseudostate_Operation_join_vertex_EDiagnosticChain_EMap() const
{
	return m_pseudostate_Operation_join_vertex_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPseudostate_Operation_junction_vertex_EDiagnosticChain_EMap() const
{
	return m_pseudostate_Operation_junction_vertex_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPseudostate_Operation_outgoing_from_initial_EDiagnosticChain_EMap() const
{
	return m_pseudostate_Operation_outgoing_from_initial_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPseudostate_Operation_transitions_incoming_EDiagnosticChain_EMap() const
{
	return m_pseudostate_Operation_transitions_incoming_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getPseudostate_Operation_transitions_outgoing_EDiagnosticChain_EMap() const
{
	return m_pseudostate_Operation_transitions_outgoing_EDiagnosticChain_EMap;
}

// End Class Pseudostate

// Begin Class QualifierValue
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getQualifierValue_Class() const
{
	return m_qualifierValue_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getQualifierValue_Attribute_qualifier() const
{
	return m_qualifierValue_Attribute_qualifier;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getQualifierValue_Attribute_value() const
{
	return m_qualifierValue_Attribute_value;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getQualifierValue_Operation_multiplicity_of_qualifier_EDiagnosticChain_EMap() const
{
	return m_qualifierValue_Operation_multiplicity_of_qualifier_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getQualifierValue_Operation_qualifier_attribute_EDiagnosticChain_EMap() const
{
	return m_qualifierValue_Operation_qualifier_attribute_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getQualifierValue_Operation_type_of_qualifier_EDiagnosticChain_EMap() const
{
	return m_qualifierValue_Operation_type_of_qualifier_EDiagnosticChain_EMap;
}

// End Class QualifierValue

// Begin Class RaiseExceptionAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getRaiseExceptionAction_Class() const
{
	return m_raiseExceptionAction_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getRaiseExceptionAction_Attribute_exception() const
{
	return m_raiseExceptionAction_Attribute_exception;
}


// End Class RaiseExceptionAction

// Begin Class ReadExtentAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getReadExtentAction_Class() const
{
	return m_readExtentAction_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getReadExtentAction_Attribute_classifier() const
{
	return m_readExtentAction_Attribute_classifier;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getReadExtentAction_Attribute_result() const
{
	return m_readExtentAction_Attribute_result;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReadExtentAction_Operation_multiplicity_of_result_EDiagnosticChain_EMap() const
{
	return m_readExtentAction_Operation_multiplicity_of_result_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReadExtentAction_Operation_type_is_classifier_EDiagnosticChain_EMap() const
{
	return m_readExtentAction_Operation_type_is_classifier_EDiagnosticChain_EMap;
}

// End Class ReadExtentAction

// Begin Class ReadIsClassifiedObjectAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getReadIsClassifiedObjectAction_Class() const
{
	return m_readIsClassifiedObjectAction_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getReadIsClassifiedObjectAction_Attribute_isDirect() const
{
	return m_readIsClassifiedObjectAction_Attribute_isDirect;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getReadIsClassifiedObjectAction_Attribute_classifier() const
{
	return m_readIsClassifiedObjectAction_Attribute_classifier;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getReadIsClassifiedObjectAction_Attribute_object() const
{
	return m_readIsClassifiedObjectAction_Attribute_object;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getReadIsClassifiedObjectAction_Attribute_result() const
{
	return m_readIsClassifiedObjectAction_Attribute_result;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReadIsClassifiedObjectAction_Operation_boolean_result_EDiagnosticChain_EMap() const
{
	return m_readIsClassifiedObjectAction_Operation_boolean_result_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReadIsClassifiedObjectAction_Operation_multiplicity_of_input_EDiagnosticChain_EMap() const
{
	return m_readIsClassifiedObjectAction_Operation_multiplicity_of_input_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReadIsClassifiedObjectAction_Operation_multiplicity_of_output_EDiagnosticChain_EMap() const
{
	return m_readIsClassifiedObjectAction_Operation_multiplicity_of_output_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReadIsClassifiedObjectAction_Operation_no_type_EDiagnosticChain_EMap() const
{
	return m_readIsClassifiedObjectAction_Operation_no_type_EDiagnosticChain_EMap;
}

// End Class ReadIsClassifiedObjectAction

// Begin Class ReadLinkAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getReadLinkAction_Class() const
{
	return m_readLinkAction_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getReadLinkAction_Attribute_result() const
{
	return m_readLinkAction_Attribute_result;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReadLinkAction_Operation_compatible_multiplicity_EDiagnosticChain_EMap() const
{
	return m_readLinkAction_Operation_compatible_multiplicity_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReadLinkAction_Operation_navigable_open_end_EDiagnosticChain_EMap() const
{
	return m_readLinkAction_Operation_navigable_open_end_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReadLinkAction_Operation_one_open_end_EDiagnosticChain_EMap() const
{
	return m_readLinkAction_Operation_one_open_end_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReadLinkAction_Operation_openEnd() const
{
	return m_readLinkAction_Operation_openEnd;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReadLinkAction_Operation_type_and_ordering_EDiagnosticChain_EMap() const
{
	return m_readLinkAction_Operation_type_and_ordering_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReadLinkAction_Operation_visibility_EDiagnosticChain_EMap() const
{
	return m_readLinkAction_Operation_visibility_EDiagnosticChain_EMap;
}

// End Class ReadLinkAction

// Begin Class ReadLinkObjectEndAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getReadLinkObjectEndAction_Class() const
{
	return m_readLinkObjectEndAction_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getReadLinkObjectEndAction_Attribute_end() const
{
	return m_readLinkObjectEndAction_Attribute_end;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getReadLinkObjectEndAction_Attribute_object() const
{
	return m_readLinkObjectEndAction_Attribute_object;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getReadLinkObjectEndAction_Attribute_result() const
{
	return m_readLinkObjectEndAction_Attribute_result;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReadLinkObjectEndAction_Operation_association_of_association_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndAction_Operation_association_of_association_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReadLinkObjectEndAction_Operation_ends_of_association_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndAction_Operation_ends_of_association_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReadLinkObjectEndAction_Operation_multiplicity_of_object_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndAction_Operation_multiplicity_of_object_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReadLinkObjectEndAction_Operation_multiplicity_of_result_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndAction_Operation_multiplicity_of_result_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReadLinkObjectEndAction_Operation_property_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndAction_Operation_property_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReadLinkObjectEndAction_Operation_type_of_object_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndAction_Operation_type_of_object_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReadLinkObjectEndAction_Operation_type_of_result_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndAction_Operation_type_of_result_EDiagnosticChain_EMap;
}

// End Class ReadLinkObjectEndAction

// Begin Class ReadLinkObjectEndQualifierAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getReadLinkObjectEndQualifierAction_Class() const
{
	return m_readLinkObjectEndQualifierAction_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getReadLinkObjectEndQualifierAction_Attribute_object() const
{
	return m_readLinkObjectEndQualifierAction_Attribute_object;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getReadLinkObjectEndQualifierAction_Attribute_qualifier() const
{
	return m_readLinkObjectEndQualifierAction_Attribute_qualifier;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getReadLinkObjectEndQualifierAction_Attribute_result() const
{
	return m_readLinkObjectEndQualifierAction_Attribute_result;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReadLinkObjectEndQualifierAction_Operation_association_of_association_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndQualifierAction_Operation_association_of_association_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReadLinkObjectEndQualifierAction_Operation_ends_of_association_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndQualifierAction_Operation_ends_of_association_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReadLinkObjectEndQualifierAction_Operation_multiplicity_of_object_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndQualifierAction_Operation_multiplicity_of_object_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReadLinkObjectEndQualifierAction_Operation_multiplicity_of_qualifier_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndQualifierAction_Operation_multiplicity_of_qualifier_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReadLinkObjectEndQualifierAction_Operation_multiplicity_of_result_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndQualifierAction_Operation_multiplicity_of_result_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReadLinkObjectEndQualifierAction_Operation_qualifier_attribute_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndQualifierAction_Operation_qualifier_attribute_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReadLinkObjectEndQualifierAction_Operation_same_type_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndQualifierAction_Operation_same_type_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReadLinkObjectEndQualifierAction_Operation_type_of_object_EDiagnosticChain_EMap() const
{
	return m_readLinkObjectEndQualifierAction_Operation_type_of_object_EDiagnosticChain_EMap;
}

// End Class ReadLinkObjectEndQualifierAction

// Begin Class ReadSelfAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getReadSelfAction_Class() const
{
	return m_readSelfAction_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getReadSelfAction_Attribute_result() const
{
	return m_readSelfAction_Attribute_result;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReadSelfAction_Operation_contained_EDiagnosticChain_EMap() const
{
	return m_readSelfAction_Operation_contained_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReadSelfAction_Operation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_readSelfAction_Operation_multiplicity_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReadSelfAction_Operation_not_static_EDiagnosticChain_EMap() const
{
	return m_readSelfAction_Operation_not_static_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReadSelfAction_Operation_type_EDiagnosticChain_EMap() const
{
	return m_readSelfAction_Operation_type_EDiagnosticChain_EMap;
}

// End Class ReadSelfAction

// Begin Class ReadStructuralFeatureAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getReadStructuralFeatureAction_Class() const
{
	return m_readStructuralFeatureAction_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getReadStructuralFeatureAction_Attribute_result() const
{
	return m_readStructuralFeatureAction_Attribute_result;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReadStructuralFeatureAction_Operation_type_and_ordering_EDiagnosticChain_EMap() const
{
	return m_readStructuralFeatureAction_Operation_type_and_ordering_EDiagnosticChain_EMap;
}

// End Class ReadStructuralFeatureAction

// Begin Class ReadVariableAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getReadVariableAction_Class() const
{
	return m_readVariableAction_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getReadVariableAction_Attribute_result() const
{
	return m_readVariableAction_Attribute_result;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReadVariableAction_Operation_compatible_multiplicity_EDiagnosticChain_EMap() const
{
	return m_readVariableAction_Operation_compatible_multiplicity_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReadVariableAction_Operation_type_and_ordering_EDiagnosticChain_EMap() const
{
	return m_readVariableAction_Operation_type_and_ordering_EDiagnosticChain_EMap;
}

// End Class ReadVariableAction

// Begin Class Realization
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getRealization_Class() const
{
	return m_realization_Class;
}




// End Class Realization

// Begin Class Reception
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getReception_Class() const
{
	return m_reception_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getReception_Attribute_signal() const
{
	return m_reception_Attribute_signal;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReception_Operation_same_name_as_signal_EDiagnosticChain_EMap() const
{
	return m_reception_Operation_same_name_as_signal_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReception_Operation_same_structure_as_signal_EDiagnosticChain_EMap() const
{
	return m_reception_Operation_same_structure_as_signal_EDiagnosticChain_EMap;
}

// End Class Reception

// Begin Class ReclassifyObjectAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getReclassifyObjectAction_Class() const
{
	return m_reclassifyObjectAction_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getReclassifyObjectAction_Attribute_isReplaceAll() const
{
	return m_reclassifyObjectAction_Attribute_isReplaceAll;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getReclassifyObjectAction_Attribute_newClassifier() const
{
	return m_reclassifyObjectAction_Attribute_newClassifier;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getReclassifyObjectAction_Attribute_object() const
{
	return m_reclassifyObjectAction_Attribute_object;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getReclassifyObjectAction_Attribute_oldClassifier() const
{
	return m_reclassifyObjectAction_Attribute_oldClassifier;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReclassifyObjectAction_Operation_classifier_not_abstract_EDiagnosticChain_EMap() const
{
	return m_reclassifyObjectAction_Operation_classifier_not_abstract_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReclassifyObjectAction_Operation_input_pin_EDiagnosticChain_EMap() const
{
	return m_reclassifyObjectAction_Operation_input_pin_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReclassifyObjectAction_Operation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_reclassifyObjectAction_Operation_multiplicity_EDiagnosticChain_EMap;
}

// End Class ReclassifyObjectAction

// Begin Class RedefinableElement
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getRedefinableElement_Class() const
{
	return m_redefinableElement_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getRedefinableElement_Attribute_isLeaf() const
{
	return m_redefinableElement_Attribute_isLeaf;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getRedefinableElement_Attribute_redefinedElement() const
{
	return m_redefinableElement_Attribute_redefinedElement;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getRedefinableElement_Attribute_redefinitionContext() const
{
	return m_redefinableElement_Attribute_redefinitionContext;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getRedefinableElement_Operation_isConsistentWith_RedefinableElement() const
{
	return m_redefinableElement_Operation_isConsistentWith_RedefinableElement;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getRedefinableElement_Operation_isRedefinitionContextValid_RedefinableElement() const
{
	return m_redefinableElement_Operation_isRedefinitionContextValid_RedefinableElement;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getRedefinableElement_Operation_non_leaf_redefinition_EDiagnosticChain_EMap() const
{
	return m_redefinableElement_Operation_non_leaf_redefinition_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getRedefinableElement_Operation_redefinition_consistent_EDiagnosticChain_EMap() const
{
	return m_redefinableElement_Operation_redefinition_consistent_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getRedefinableElement_Operation_redefinition_context_valid_EDiagnosticChain_EMap() const
{
	return m_redefinableElement_Operation_redefinition_context_valid_EDiagnosticChain_EMap;
}

// End Class RedefinableElement

// Begin Class RedefinableTemplateSignature
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getRedefinableTemplateSignature_Class() const
{
	return m_redefinableTemplateSignature_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getRedefinableTemplateSignature_Attribute_classifier() const
{
	return m_redefinableTemplateSignature_Attribute_classifier;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getRedefinableTemplateSignature_Attribute_extendedSignature() const
{
	return m_redefinableTemplateSignature_Attribute_extendedSignature;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getRedefinableTemplateSignature_Attribute_inheritedParameter() const
{
	return m_redefinableTemplateSignature_Attribute_inheritedParameter;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getRedefinableTemplateSignature_Operation_getInheritedParameters() const
{
	return m_redefinableTemplateSignature_Operation_getInheritedParameters;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getRedefinableTemplateSignature_Operation_redefines_parents_EDiagnosticChain_EMap() const
{
	return m_redefinableTemplateSignature_Operation_redefines_parents_EDiagnosticChain_EMap;
}

// End Class RedefinableTemplateSignature

// Begin Class ReduceAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getReduceAction_Class() const
{
	return m_reduceAction_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getReduceAction_Attribute_isOrdered() const
{
	return m_reduceAction_Attribute_isOrdered;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getReduceAction_Attribute_collection() const
{
	return m_reduceAction_Attribute_collection;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getReduceAction_Attribute_reducer() const
{
	return m_reduceAction_Attribute_reducer;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getReduceAction_Attribute_result() const
{
	return m_reduceAction_Attribute_result;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReduceAction_Operation_input_type_is_collection_EDiagnosticChain_EMap() const
{
	return m_reduceAction_Operation_input_type_is_collection_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReduceAction_Operation_output_types_are_compatible_EDiagnosticChain_EMap() const
{
	return m_reduceAction_Operation_output_types_are_compatible_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReduceAction_Operation_reducer_inputs_output_EDiagnosticChain_EMap() const
{
	return m_reduceAction_Operation_reducer_inputs_output_EDiagnosticChain_EMap;
}

// End Class ReduceAction

// Begin Class Region
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getRegion_Class() const
{
	return m_region_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getRegion_Attribute_extendedRegion() const
{
	return m_region_Attribute_extendedRegion;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getRegion_Attribute_state() const
{
	return m_region_Attribute_state;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getRegion_Attribute_stateMachine() const
{
	return m_region_Attribute_stateMachine;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getRegion_Attribute_subvertex() const
{
	return m_region_Attribute_subvertex;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getRegion_Attribute_transition() const
{
	return m_region_Attribute_transition;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getRegion_Operation_belongsToPSM() const
{
	return m_region_Operation_belongsToPSM;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getRegion_Operation_containingStateMachine() const
{
	return m_region_Operation_containingStateMachine;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getRegion_Operation_deep_history_vertex_EDiagnosticChain_EMap() const
{
	return m_region_Operation_deep_history_vertex_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getRegion_Operation_initial_vertex_EDiagnosticChain_EMap() const
{
	return m_region_Operation_initial_vertex_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getRegion_Operation_owned_EDiagnosticChain_EMap() const
{
	return m_region_Operation_owned_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getRegion_Operation_redefinitionContext() const
{
	return m_region_Operation_redefinitionContext;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getRegion_Operation_shallow_history_vertex_EDiagnosticChain_EMap() const
{
	return m_region_Operation_shallow_history_vertex_EDiagnosticChain_EMap;
}

// End Class Region

// Begin Class Relationship
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getRelationship_Class() const
{
	return m_relationship_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getRelationship_Attribute_relatedElement() const
{
	return m_relationship_Attribute_relatedElement;
}


// End Class Relationship

// Begin Class RemoveStructuralFeatureValueAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getRemoveStructuralFeatureValueAction_Class() const
{
	return m_removeStructuralFeatureValueAction_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getRemoveStructuralFeatureValueAction_Attribute_isRemoveDuplicates() const
{
	return m_removeStructuralFeatureValueAction_Attribute_isRemoveDuplicates;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getRemoveStructuralFeatureValueAction_Attribute_removeAt() const
{
	return m_removeStructuralFeatureValueAction_Attribute_removeAt;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getRemoveStructuralFeatureValueAction_Operation_removeAt_and_value_EDiagnosticChain_EMap() const
{
	return m_removeStructuralFeatureValueAction_Operation_removeAt_and_value_EDiagnosticChain_EMap;
}

// End Class RemoveStructuralFeatureValueAction

// Begin Class RemoveVariableValueAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getRemoveVariableValueAction_Class() const
{
	return m_removeVariableValueAction_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getRemoveVariableValueAction_Attribute_isRemoveDuplicates() const
{
	return m_removeVariableValueAction_Attribute_isRemoveDuplicates;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getRemoveVariableValueAction_Attribute_removeAt() const
{
	return m_removeVariableValueAction_Attribute_removeAt;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getRemoveVariableValueAction_Operation_removeAt_and_value_EDiagnosticChain_EMap() const
{
	return m_removeVariableValueAction_Operation_removeAt_and_value_EDiagnosticChain_EMap;
}

// End Class RemoveVariableValueAction

// Begin Class ReplyAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getReplyAction_Class() const
{
	return m_replyAction_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getReplyAction_Attribute_replyToCall() const
{
	return m_replyAction_Attribute_replyToCall;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getReplyAction_Attribute_replyValue() const
{
	return m_replyAction_Attribute_replyValue;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getReplyAction_Attribute_returnInformation() const
{
	return m_replyAction_Attribute_returnInformation;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReplyAction_Operation_event_on_reply_to_call_trigger_EDiagnosticChain_EMap() const
{
	return m_replyAction_Operation_event_on_reply_to_call_trigger_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getReplyAction_Operation_pins_match_parameter_EDiagnosticChain_EMap() const
{
	return m_replyAction_Operation_pins_match_parameter_EDiagnosticChain_EMap;
}

// End Class ReplyAction

// Begin Class SendObjectAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getSendObjectAction_Class() const
{
	return m_sendObjectAction_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getSendObjectAction_Attribute_request() const
{
	return m_sendObjectAction_Attribute_request;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getSendObjectAction_Attribute_target() const
{
	return m_sendObjectAction_Attribute_target;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getSendObjectAction_Operation_type_target_pin_EDiagnosticChain_EMap() const
{
	return m_sendObjectAction_Operation_type_target_pin_EDiagnosticChain_EMap;
}

// End Class SendObjectAction

// Begin Class SendSignalAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getSendSignalAction_Class() const
{
	return m_sendSignalAction_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getSendSignalAction_Attribute_signal() const
{
	return m_sendSignalAction_Attribute_signal;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getSendSignalAction_Attribute_target() const
{
	return m_sendSignalAction_Attribute_target;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getSendSignalAction_Operation_number_order_EDiagnosticChain_EMap() const
{
	return m_sendSignalAction_Operation_number_order_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getSendSignalAction_Operation_type_ordering_multiplicity_EDiagnosticChain_EMap() const
{
	return m_sendSignalAction_Operation_type_ordering_multiplicity_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getSendSignalAction_Operation_type_target_pin_EDiagnosticChain_EMap() const
{
	return m_sendSignalAction_Operation_type_target_pin_EDiagnosticChain_EMap;
}

// End Class SendSignalAction

// Begin Class SequenceNode
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getSequenceNode_Class() const
{
	return m_sequenceNode_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getSequenceNode_Attribute_executableNode() const
{
	return m_sequenceNode_Attribute_executableNode;
}


// End Class SequenceNode

// Begin Class Signal
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getSignal_Class() const
{
	return m_signal_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getSignal_Attribute_ownedAttribute() const
{
	return m_signal_Attribute_ownedAttribute;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getSignal_Operation_createOwnedAttribute_String_UnlimitedNatural() const
{
	return m_signal_Operation_createOwnedAttribute_String_UnlimitedNatural;
}

// End Class Signal

// Begin Class SignalEvent
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getSignalEvent_Class() const
{
	return m_signalEvent_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getSignalEvent_Attribute_signal() const
{
	return m_signalEvent_Attribute_signal;
}


// End Class SignalEvent

// Begin Class Slot
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getSlot_Class() const
{
	return m_slot_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getSlot_Attribute_definingFeature() const
{
	return m_slot_Attribute_definingFeature;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getSlot_Attribute_owningInstance() const
{
	return m_slot_Attribute_owningInstance;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getSlot_Attribute_value() const
{
	return m_slot_Attribute_value;
}


// End Class Slot

// Begin Class StartClassifierBehaviorAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getStartClassifierBehaviorAction_Class() const
{
	return m_startClassifierBehaviorAction_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getStartClassifierBehaviorAction_Attribute_object() const
{
	return m_startClassifierBehaviorAction_Attribute_object;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStartClassifierBehaviorAction_Operation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_startClassifierBehaviorAction_Operation_multiplicity_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStartClassifierBehaviorAction_Operation_type_has_classifier_EDiagnosticChain_EMap() const
{
	return m_startClassifierBehaviorAction_Operation_type_has_classifier_EDiagnosticChain_EMap;
}

// End Class StartClassifierBehaviorAction

// Begin Class StartObjectBehaviorAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getStartObjectBehaviorAction_Class() const
{
	return m_startObjectBehaviorAction_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getStartObjectBehaviorAction_Attribute_object() const
{
	return m_startObjectBehaviorAction_Attribute_object;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStartObjectBehaviorAction_Operation_behavior() const
{
	return m_startObjectBehaviorAction_Operation_behavior;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStartObjectBehaviorAction_Operation_multiplicity_of_object_EDiagnosticChain_EMap() const
{
	return m_startObjectBehaviorAction_Operation_multiplicity_of_object_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStartObjectBehaviorAction_Operation_no_onport_EDiagnosticChain_EMap() const
{
	return m_startObjectBehaviorAction_Operation_no_onport_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStartObjectBehaviorAction_Operation_type_of_object_EDiagnosticChain_EMap() const
{
	return m_startObjectBehaviorAction_Operation_type_of_object_EDiagnosticChain_EMap;
}

// End Class StartObjectBehaviorAction

// Begin Class State
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getState_Class() const
{
	return m_state_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getState_Attribute_isComposite() const
{
	return m_state_Attribute_isComposite;
}
const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getState_Attribute_isOrthogonal() const
{
	return m_state_Attribute_isOrthogonal;
}
const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getState_Attribute_isSimple() const
{
	return m_state_Attribute_isSimple;
}
const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getState_Attribute_isSubmachineState() const
{
	return m_state_Attribute_isSubmachineState;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getState_Attribute_connection() const
{
	return m_state_Attribute_connection;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getState_Attribute_connectionPoint() const
{
	return m_state_Attribute_connectionPoint;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getState_Attribute_deferrableTrigger() const
{
	return m_state_Attribute_deferrableTrigger;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getState_Attribute_doActivity() const
{
	return m_state_Attribute_doActivity;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getState_Attribute_entry() const
{
	return m_state_Attribute_entry;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getState_Attribute_exit() const
{
	return m_state_Attribute_exit;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getState_Attribute_redefinedState() const
{
	return m_state_Attribute_redefinedState;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getState_Attribute_region() const
{
	return m_state_Attribute_region;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getState_Attribute_stateInvariant() const
{
	return m_state_Attribute_stateInvariant;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getState_Attribute_submachine() const
{
	return m_state_Attribute_submachine;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getState_Operation_composite_states_EDiagnosticChain_EMap() const
{
	return m_state_Operation_composite_states_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getState_Operation_destinations_or_sources_of_transitions_EDiagnosticChain_EMap() const
{
	return m_state_Operation_destinations_or_sources_of_transitions_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getState_Operation_entry_or_exit_EDiagnosticChain_EMap() const
{
	return m_state_Operation_entry_or_exit_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getState_Operation_isComposite() const
{
	return m_state_Operation_isComposite;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getState_Operation_isOrthogonal() const
{
	return m_state_Operation_isOrthogonal;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getState_Operation_isSimple() const
{
	return m_state_Operation_isSimple;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getState_Operation_isSubmachineState() const
{
	return m_state_Operation_isSubmachineState;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getState_Operation_redefinitionContext() const
{
	return m_state_Operation_redefinitionContext;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getState_Operation_submachine_or_regions_EDiagnosticChain_EMap() const
{
	return m_state_Operation_submachine_or_regions_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getState_Operation_submachine_states_EDiagnosticChain_EMap() const
{
	return m_state_Operation_submachine_states_EDiagnosticChain_EMap;
}

// End Class State

// Begin Class StateInvariant
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getStateInvariant_Class() const
{
	return m_stateInvariant_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getStateInvariant_Attribute_invariant() const
{
	return m_stateInvariant_Attribute_invariant;
}


// End Class StateInvariant

// Begin Class StateMachine
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getStateMachine_Class() const
{
	return m_stateMachine_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getStateMachine_Attribute_connectionPoint() const
{
	return m_stateMachine_Attribute_connectionPoint;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getStateMachine_Attribute_extendedStateMachine() const
{
	return m_stateMachine_Attribute_extendedStateMachine;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getStateMachine_Attribute_region() const
{
	return m_stateMachine_Attribute_region;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getStateMachine_Attribute_submachineState() const
{
	return m_stateMachine_Attribute_submachineState;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStateMachine_Operation_lCA_Vertex_Vertex() const
{
	return m_stateMachine_Operation_lCA_Vertex_Vertex;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStateMachine_Operation_lCAState_Vertex_Vertex() const
{
	return m_stateMachine_Operation_lCAState_Vertex_Vertex;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStateMachine_Operation_ancestor_Vertex_Vertex() const
{
	return m_stateMachine_Operation_ancestor_Vertex_Vertex;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStateMachine_Operation_classifier_context_EDiagnosticChain_EMap() const
{
	return m_stateMachine_Operation_classifier_context_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStateMachine_Operation_connection_points_EDiagnosticChain_EMap() const
{
	return m_stateMachine_Operation_connection_points_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStateMachine_Operation_context_classifier_EDiagnosticChain_EMap() const
{
	return m_stateMachine_Operation_context_classifier_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStateMachine_Operation_method_EDiagnosticChain_EMap() const
{
	return m_stateMachine_Operation_method_EDiagnosticChain_EMap;
}

// End Class StateMachine

// Begin Class Stereotype
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getStereotype_Class() const
{
	return m_stereotype_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getStereotype_Attribute_icon() const
{
	return m_stereotype_Attribute_icon;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getStereotype_Attribute_profile() const
{
	return m_stereotype_Attribute_profile;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStereotype_Operation_associationEndOwnership_EDiagnosticChain_EMap() const
{
	return m_stereotype_Operation_associationEndOwnership_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStereotype_Operation_base_property_multiplicity_multiple_extension_EDiagnosticChain_EMap() const
{
	return m_stereotype_Operation_base_property_multiplicity_multiple_extension_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStereotype_Operation_base_property_multiplicity_single_extension_EDiagnosticChain_EMap() const
{
	return m_stereotype_Operation_base_property_multiplicity_single_extension_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStereotype_Operation_base_property_upper_bound_EDiagnosticChain_EMap() const
{
	return m_stereotype_Operation_base_property_upper_bound_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStereotype_Operation_binaryAssociationsOnly_EDiagnosticChain_EMap() const
{
	return m_stereotype_Operation_binaryAssociationsOnly_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStereotype_Operation_containingProfile() const
{
	return m_stereotype_Operation_containingProfile;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStereotype_Operation_createExtension_Class_Boolean() const
{
	return m_stereotype_Operation_createExtension_Class_Boolean;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStereotype_Operation_createIcon_String() const
{
	return m_stereotype_Operation_createIcon_String;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStereotype_Operation_createIcon_String_String() const
{
	return m_stereotype_Operation_createIcon_String_String;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStereotype_Operation_generalize_EDiagnosticChain_EMap() const
{
	return m_stereotype_Operation_generalize_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStereotype_Operation_getAllExtendedMetaclasses() const
{
	return m_stereotype_Operation_getAllExtendedMetaclasses;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStereotype_Operation_getDefinition() const
{
	return m_stereotype_Operation_getDefinition;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStereotype_Operation_getExtendedMetaclasses() const
{
	return m_stereotype_Operation_getExtendedMetaclasses;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStereotype_Operation_getKeyword() const
{
	return m_stereotype_Operation_getKeyword;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStereotype_Operation_getKeyword_Boolean() const
{
	return m_stereotype_Operation_getKeyword_Boolean;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStereotype_Operation_getProfile() const
{
	return m_stereotype_Operation_getProfile;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStereotype_Operation_name_not_clash_EDiagnosticChain_EMap() const
{
	return m_stereotype_Operation_name_not_clash_EDiagnosticChain_EMap;
}

// End Class Stereotype

// Begin Class StringExpression
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getStringExpression_Class() const
{
	return m_stringExpression_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getStringExpression_Attribute_owningExpression() const
{
	return m_stringExpression_Attribute_owningExpression;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getStringExpression_Attribute_subExpression() const
{
	return m_stringExpression_Attribute_subExpression;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStringExpression_Operation_operands_EDiagnosticChain_EMap() const
{
	return m_stringExpression_Operation_operands_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStringExpression_Operation_subexpressions_EDiagnosticChain_EMap() const
{
	return m_stringExpression_Operation_subexpressions_EDiagnosticChain_EMap;
}

// End Class StringExpression

// Begin Class StructuralFeature
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getStructuralFeature_Class() const
{
	return m_structuralFeature_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getStructuralFeature_Attribute_isReadOnly() const
{
	return m_structuralFeature_Attribute_isReadOnly;
}



// End Class StructuralFeature

// Begin Class StructuralFeatureAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getStructuralFeatureAction_Class() const
{
	return m_structuralFeatureAction_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getStructuralFeatureAction_Attribute_object() const
{
	return m_structuralFeatureAction_Attribute_object;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getStructuralFeatureAction_Attribute_structuralFeature() const
{
	return m_structuralFeatureAction_Attribute_structuralFeature;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStructuralFeatureAction_Operation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_structuralFeatureAction_Operation_multiplicity_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStructuralFeatureAction_Operation_not_static_EDiagnosticChain_EMap() const
{
	return m_structuralFeatureAction_Operation_not_static_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStructuralFeatureAction_Operation_object_type_EDiagnosticChain_EMap() const
{
	return m_structuralFeatureAction_Operation_object_type_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStructuralFeatureAction_Operation_one_featuring_classifier_EDiagnosticChain_EMap() const
{
	return m_structuralFeatureAction_Operation_one_featuring_classifier_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStructuralFeatureAction_Operation_visibility_EDiagnosticChain_EMap() const
{
	return m_structuralFeatureAction_Operation_visibility_EDiagnosticChain_EMap;
}

// End Class StructuralFeatureAction

// Begin Class StructuredActivityNode
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getStructuredActivityNode_Class() const
{
	return m_structuredActivityNode_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getStructuredActivityNode_Attribute_mustIsolate() const
{
	return m_structuredActivityNode_Attribute_mustIsolate;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getStructuredActivityNode_Attribute_edge() const
{
	return m_structuredActivityNode_Attribute_edge;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getStructuredActivityNode_Attribute_node() const
{
	return m_structuredActivityNode_Attribute_node;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getStructuredActivityNode_Attribute_structuredNodeInput() const
{
	return m_structuredActivityNode_Attribute_structuredNodeInput;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getStructuredActivityNode_Attribute_structuredNodeOutput() const
{
	return m_structuredActivityNode_Attribute_structuredNodeOutput;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getStructuredActivityNode_Attribute_variable() const
{
	return m_structuredActivityNode_Attribute_variable;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStructuredActivityNode_Operation_edges_EDiagnosticChain_EMap() const
{
	return m_structuredActivityNode_Operation_edges_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStructuredActivityNode_Operation_input_pin_edges_EDiagnosticChain_EMap() const
{
	return m_structuredActivityNode_Operation_input_pin_edges_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStructuredActivityNode_Operation_output_pin_edges_EDiagnosticChain_EMap() const
{
	return m_structuredActivityNode_Operation_output_pin_edges_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStructuredActivityNode_Operation_sourceNodes() const
{
	return m_structuredActivityNode_Operation_sourceNodes;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStructuredActivityNode_Operation_targetNodes() const
{
	return m_structuredActivityNode_Operation_targetNodes;
}

// End Class StructuredActivityNode

// Begin Class StructuredClassifier
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getStructuredClassifier_Class() const
{
	return m_structuredClassifier_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getStructuredClassifier_Attribute_ownedAttribute() const
{
	return m_structuredClassifier_Attribute_ownedAttribute;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getStructuredClassifier_Attribute_ownedConnector() const
{
	return m_structuredClassifier_Attribute_ownedConnector;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getStructuredClassifier_Attribute_part() const
{
	return m_structuredClassifier_Attribute_part;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getStructuredClassifier_Attribute_role() const
{
	return m_structuredClassifier_Attribute_role;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStructuredClassifier_Operation_allRoles() const
{
	return m_structuredClassifier_Operation_allRoles;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStructuredClassifier_Operation_createOwnedAttribute_String_UnlimitedNatural() const
{
	return m_structuredClassifier_Operation_createOwnedAttribute_String_UnlimitedNatural;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getStructuredClassifier_Operation_getParts() const
{
	return m_structuredClassifier_Operation_getParts;
}

// End Class StructuredClassifier

// Begin Class Substitution
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getSubstitution_Class() const
{
	return m_substitution_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getSubstitution_Attribute_contract() const
{
	return m_substitution_Attribute_contract;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getSubstitution_Attribute_substitutingClassifier() const
{
	return m_substitution_Attribute_substitutingClassifier;
}


// End Class Substitution

// Begin Class TemplateBinding
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getTemplateBinding_Class() const
{
	return m_templateBinding_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getTemplateBinding_Attribute_boundElement() const
{
	return m_templateBinding_Attribute_boundElement;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getTemplateBinding_Attribute_parameterSubstitution() const
{
	return m_templateBinding_Attribute_parameterSubstitution;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getTemplateBinding_Attribute_signature() const
{
	return m_templateBinding_Attribute_signature;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getTemplateBinding_Operation_one_parameter_substitution_EDiagnosticChain_EMap() const
{
	return m_templateBinding_Operation_one_parameter_substitution_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getTemplateBinding_Operation_parameter_substitution_formal_EDiagnosticChain_EMap() const
{
	return m_templateBinding_Operation_parameter_substitution_formal_EDiagnosticChain_EMap;
}

// End Class TemplateBinding

// Begin Class TemplateParameter
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getTemplateParameter_Class() const
{
	return m_templateParameter_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getTemplateParameter_Attribute_default() const
{
	return m_templateParameter_Attribute_default;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getTemplateParameter_Attribute_ownedDefault() const
{
	return m_templateParameter_Attribute_ownedDefault;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getTemplateParameter_Attribute_ownedParameteredElement() const
{
	return m_templateParameter_Attribute_ownedParameteredElement;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getTemplateParameter_Attribute_parameteredElement() const
{
	return m_templateParameter_Attribute_parameteredElement;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getTemplateParameter_Attribute_signature() const
{
	return m_templateParameter_Attribute_signature;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getTemplateParameter_Operation_must_be_compatible_EDiagnosticChain_EMap() const
{
	return m_templateParameter_Operation_must_be_compatible_EDiagnosticChain_EMap;
}

// End Class TemplateParameter

// Begin Class TemplateParameterSubstitution
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getTemplateParameterSubstitution_Class() const
{
	return m_templateParameterSubstitution_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getTemplateParameterSubstitution_Attribute_actual() const
{
	return m_templateParameterSubstitution_Attribute_actual;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getTemplateParameterSubstitution_Attribute_formal() const
{
	return m_templateParameterSubstitution_Attribute_formal;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getTemplateParameterSubstitution_Attribute_ownedActual() const
{
	return m_templateParameterSubstitution_Attribute_ownedActual;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getTemplateParameterSubstitution_Attribute_templateBinding() const
{
	return m_templateParameterSubstitution_Attribute_templateBinding;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getTemplateParameterSubstitution_Operation_must_be_compatible_EDiagnosticChain_EMap() const
{
	return m_templateParameterSubstitution_Operation_must_be_compatible_EDiagnosticChain_EMap;
}

// End Class TemplateParameterSubstitution

// Begin Class TemplateSignature
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getTemplateSignature_Class() const
{
	return m_templateSignature_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getTemplateSignature_Attribute_ownedParameter() const
{
	return m_templateSignature_Attribute_ownedParameter;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getTemplateSignature_Attribute_parameter() const
{
	return m_templateSignature_Attribute_parameter;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getTemplateSignature_Attribute_template() const
{
	return m_templateSignature_Attribute_template;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getTemplateSignature_Operation_own_elements_EDiagnosticChain_EMap() const
{
	return m_templateSignature_Operation_own_elements_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getTemplateSignature_Operation_unique_parameters_EDiagnosticChain_EMap() const
{
	return m_templateSignature_Operation_unique_parameters_EDiagnosticChain_EMap;
}

// End Class TemplateSignature

// Begin Class TemplateableElement
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getTemplateableElement_Class() const
{
	return m_templateableElement_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getTemplateableElement_Attribute_ownedTemplateSignature() const
{
	return m_templateableElement_Attribute_ownedTemplateSignature;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getTemplateableElement_Attribute_templateBinding() const
{
	return m_templateableElement_Attribute_templateBinding;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getTemplateableElement_Operation_isTemplate() const
{
	return m_templateableElement_Operation_isTemplate;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getTemplateableElement_Operation_parameterableElements() const
{
	return m_templateableElement_Operation_parameterableElements;
}

// End Class TemplateableElement

// Begin Class TestIdentityAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getTestIdentityAction_Class() const
{
	return m_testIdentityAction_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getTestIdentityAction_Attribute_first() const
{
	return m_testIdentityAction_Attribute_first;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getTestIdentityAction_Attribute_result() const
{
	return m_testIdentityAction_Attribute_result;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getTestIdentityAction_Attribute_second() const
{
	return m_testIdentityAction_Attribute_second;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getTestIdentityAction_Operation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_testIdentityAction_Operation_multiplicity_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getTestIdentityAction_Operation_no_type_EDiagnosticChain_EMap() const
{
	return m_testIdentityAction_Operation_no_type_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getTestIdentityAction_Operation_result_is_boolean_EDiagnosticChain_EMap() const
{
	return m_testIdentityAction_Operation_result_is_boolean_EDiagnosticChain_EMap;
}

// End Class TestIdentityAction

// Begin Class TimeConstraint
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getTimeConstraint_Class() const
{
	return m_timeConstraint_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getTimeConstraint_Attribute_firstEvent() const
{
	return m_timeConstraint_Attribute_firstEvent;
}


const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getTimeConstraint_Operation_has_one_constrainedElement_EDiagnosticChain_EMap() const
{
	return m_timeConstraint_Operation_has_one_constrainedElement_EDiagnosticChain_EMap;
}

// End Class TimeConstraint

// Begin Class TimeEvent
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getTimeEvent_Class() const
{
	return m_timeEvent_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getTimeEvent_Attribute_isRelative() const
{
	return m_timeEvent_Attribute_isRelative;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getTimeEvent_Attribute_when() const
{
	return m_timeEvent_Attribute_when;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getTimeEvent_Operation_when_non_negative_EDiagnosticChain_EMap() const
{
	return m_timeEvent_Operation_when_non_negative_EDiagnosticChain_EMap;
}

// End Class TimeEvent

// Begin Class TimeExpression
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getTimeExpression_Class() const
{
	return m_timeExpression_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getTimeExpression_Attribute_expr() const
{
	return m_timeExpression_Attribute_expr;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getTimeExpression_Attribute_observation() const
{
	return m_timeExpression_Attribute_observation;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getTimeExpression_Operation_no_expr_requires_observation_EDiagnosticChain_EMap() const
{
	return m_timeExpression_Operation_no_expr_requires_observation_EDiagnosticChain_EMap;
}

// End Class TimeExpression

// Begin Class TimeInterval
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getTimeInterval_Class() const
{
	return m_timeInterval_Class;
}




// End Class TimeInterval

// Begin Class TimeObservation
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getTimeObservation_Class() const
{
	return m_timeObservation_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getTimeObservation_Attribute_firstEvent() const
{
	return m_timeObservation_Attribute_firstEvent;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getTimeObservation_Attribute_event() const
{
	return m_timeObservation_Attribute_event;
}


// End Class TimeObservation

// Begin Class Transition
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getTransition_Class() const
{
	return m_transition_Class;
}

const std::shared_ptr<ecore::EAttribute>& uml::umlPackageImpl::getTransition_Attribute_kind() const
{
	return m_transition_Attribute_kind;
}

const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getTransition_Attribute_container() const
{
	return m_transition_Attribute_container;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getTransition_Attribute_effect() const
{
	return m_transition_Attribute_effect;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getTransition_Attribute_guard() const
{
	return m_transition_Attribute_guard;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getTransition_Attribute_redefinedTransition() const
{
	return m_transition_Attribute_redefinedTransition;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getTransition_Attribute_source() const
{
	return m_transition_Attribute_source;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getTransition_Attribute_target() const
{
	return m_transition_Attribute_target;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getTransition_Attribute_trigger() const
{
	return m_transition_Attribute_trigger;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getTransition_Operation_containingStateMachine() const
{
	return m_transition_Operation_containingStateMachine;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getTransition_Operation_fork_segment_guards_EDiagnosticChain_EMap() const
{
	return m_transition_Operation_fork_segment_guards_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getTransition_Operation_fork_segment_state_EDiagnosticChain_EMap() const
{
	return m_transition_Operation_fork_segment_state_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getTransition_Operation_initial_transition_EDiagnosticChain_EMap() const
{
	return m_transition_Operation_initial_transition_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getTransition_Operation_join_segment_guards_EDiagnosticChain_EMap() const
{
	return m_transition_Operation_join_segment_guards_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getTransition_Operation_join_segment_state_EDiagnosticChain_EMap() const
{
	return m_transition_Operation_join_segment_state_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getTransition_Operation_outgoing_pseudostates_EDiagnosticChain_EMap() const
{
	return m_transition_Operation_outgoing_pseudostates_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getTransition_Operation_redefinitionContext() const
{
	return m_transition_Operation_redefinitionContext;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getTransition_Operation_state_is_external_EDiagnosticChain_EMap() const
{
	return m_transition_Operation_state_is_external_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getTransition_Operation_state_is_internal_EDiagnosticChain_EMap() const
{
	return m_transition_Operation_state_is_internal_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getTransition_Operation_state_is_local_EDiagnosticChain_EMap() const
{
	return m_transition_Operation_state_is_local_EDiagnosticChain_EMap;
}

// End Class Transition

// Begin Class Trigger
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getTrigger_Class() const
{
	return m_trigger_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getTrigger_Attribute_event() const
{
	return m_trigger_Attribute_event;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getTrigger_Attribute_port() const
{
	return m_trigger_Attribute_port;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getTrigger_Operation_trigger_with_ports_EDiagnosticChain_EMap() const
{
	return m_trigger_Operation_trigger_with_ports_EDiagnosticChain_EMap;
}

// End Class Trigger

// Begin Class Type
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getType_Class() const
{
	return m_type_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getType_Attribute_package() const
{
	return m_type_Attribute_package;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getType_Operation_conformsTo_Type() const
{
	return m_type_Operation_conformsTo_Type;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getType_Operation_createAssociation_Boolean_UnlimitedNatural() const
{
	return m_type_Operation_createAssociation_Boolean_UnlimitedNatural;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getType_Operation_getAssociations() const
{
	return m_type_Operation_getAssociations;
}

// End Class Type

// Begin Class TypedElement
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getTypedElement_Class() const
{
	return m_typedElement_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getTypedElement_Attribute_type() const
{
	return m_typedElement_Attribute_type;
}


// End Class TypedElement

// Begin Class UnmarshallAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getUnmarshallAction_Class() const
{
	return m_unmarshallAction_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getUnmarshallAction_Attribute_object() const
{
	return m_unmarshallAction_Attribute_object;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getUnmarshallAction_Attribute_result() const
{
	return m_unmarshallAction_Attribute_result;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getUnmarshallAction_Attribute_unmarshallType() const
{
	return m_unmarshallAction_Attribute_unmarshallType;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getUnmarshallAction_Operation_multiplicity_of_object_EDiagnosticChain_EMap() const
{
	return m_unmarshallAction_Operation_multiplicity_of_object_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getUnmarshallAction_Operation_number_of_result_EDiagnosticChain_EMap() const
{
	return m_unmarshallAction_Operation_number_of_result_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getUnmarshallAction_Operation_object_type_EDiagnosticChain_EMap() const
{
	return m_unmarshallAction_Operation_object_type_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getUnmarshallAction_Operation_structural_feature_EDiagnosticChain_EMap() const
{
	return m_unmarshallAction_Operation_structural_feature_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getUnmarshallAction_Operation_type_ordering_and_multiplicity_EDiagnosticChain_EMap() const
{
	return m_unmarshallAction_Operation_type_ordering_and_multiplicity_EDiagnosticChain_EMap;
}

// End Class UnmarshallAction

// Begin Class Usage
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getUsage_Class() const
{
	return m_usage_Class;
}




// End Class Usage

// Begin Class UseCase
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getUseCase_Class() const
{
	return m_useCase_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getUseCase_Attribute_extend() const
{
	return m_useCase_Attribute_extend;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getUseCase_Attribute_extensionPoint() const
{
	return m_useCase_Attribute_extensionPoint;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getUseCase_Attribute_include() const
{
	return m_useCase_Attribute_include;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getUseCase_Attribute_subject() const
{
	return m_useCase_Attribute_subject;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getUseCase_Operation_allIncludedUseCases() const
{
	return m_useCase_Operation_allIncludedUseCases;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getUseCase_Operation_binary_associations_EDiagnosticChain_EMap() const
{
	return m_useCase_Operation_binary_associations_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getUseCase_Operation_cannot_include_self_EDiagnosticChain_EMap() const
{
	return m_useCase_Operation_cannot_include_self_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getUseCase_Operation_must_have_name_EDiagnosticChain_EMap() const
{
	return m_useCase_Operation_must_have_name_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getUseCase_Operation_no_association_to_use_case_EDiagnosticChain_EMap() const
{
	return m_useCase_Operation_no_association_to_use_case_EDiagnosticChain_EMap;
}

// End Class UseCase

// Begin Class ValuePin
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getValuePin_Class() const
{
	return m_valuePin_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getValuePin_Attribute_value() const
{
	return m_valuePin_Attribute_value;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getValuePin_Operation_compatible_type_EDiagnosticChain_EMap() const
{
	return m_valuePin_Operation_compatible_type_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getValuePin_Operation_no_incoming_edges_EDiagnosticChain_EMap() const
{
	return m_valuePin_Operation_no_incoming_edges_EDiagnosticChain_EMap;
}

// End Class ValuePin

// Begin Class ValueSpecification
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getValueSpecification_Class() const
{
	return m_valueSpecification_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getValueSpecification_Attribute_owningSlot() const
{
	return m_valueSpecification_Attribute_owningSlot;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getValueSpecification_Attribute_valueSpecificationAction() const
{
	return m_valueSpecification_Attribute_valueSpecificationAction;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getValueSpecification_Operation_booleanValue() const
{
	return m_valueSpecification_Operation_booleanValue;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getValueSpecification_Operation_integerValue() const
{
	return m_valueSpecification_Operation_integerValue;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getValueSpecification_Operation_isComputable() const
{
	return m_valueSpecification_Operation_isComputable;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getValueSpecification_Operation_isNull() const
{
	return m_valueSpecification_Operation_isNull;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getValueSpecification_Operation_realValue() const
{
	return m_valueSpecification_Operation_realValue;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getValueSpecification_Operation_stringValue() const
{
	return m_valueSpecification_Operation_stringValue;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getValueSpecification_Operation_unlimitedValue() const
{
	return m_valueSpecification_Operation_unlimitedValue;
}

// End Class ValueSpecification

// Begin Class ValueSpecificationAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getValueSpecificationAction_Class() const
{
	return m_valueSpecificationAction_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getValueSpecificationAction_Attribute_result() const
{
	return m_valueSpecificationAction_Attribute_result;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getValueSpecificationAction_Attribute_value() const
{
	return m_valueSpecificationAction_Attribute_value;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getValueSpecificationAction_Operation_compatible_type_EDiagnosticChain_EMap() const
{
	return m_valueSpecificationAction_Operation_compatible_type_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getValueSpecificationAction_Operation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_valueSpecificationAction_Operation_multiplicity_EDiagnosticChain_EMap;
}

// End Class ValueSpecificationAction

// Begin Class Variable
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getVariable_Class() const
{
	return m_variable_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getVariable_Attribute_activityScope() const
{
	return m_variable_Attribute_activityScope;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getVariable_Attribute_scope() const
{
	return m_variable_Attribute_scope;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getVariable_Operation_isAccessibleBy_Action() const
{
	return m_variable_Operation_isAccessibleBy_Action;
}

// End Class Variable

// Begin Class VariableAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getVariableAction_Class() const
{
	return m_variableAction_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getVariableAction_Attribute_variable() const
{
	return m_variableAction_Attribute_variable;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getVariableAction_Operation_scope_of_variable_EDiagnosticChain_EMap() const
{
	return m_variableAction_Operation_scope_of_variable_EDiagnosticChain_EMap;
}

// End Class VariableAction

// Begin Class Vertex
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getVertex_Class() const
{
	return m_vertex_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getVertex_Attribute_container() const
{
	return m_vertex_Attribute_container;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getVertex_Attribute_incoming() const
{
	return m_vertex_Attribute_incoming;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getVertex_Attribute_outgoing() const
{
	return m_vertex_Attribute_outgoing;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getVertex_Operation_containingStateMachine() const
{
	return m_vertex_Operation_containingStateMachine;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getVertex_Operation_getIncomings() const
{
	return m_vertex_Operation_getIncomings;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getVertex_Operation_getOutgoings() const
{
	return m_vertex_Operation_getOutgoings;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getVertex_Operation_isContainedInRegion_Region() const
{
	return m_vertex_Operation_isContainedInRegion_Region;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getVertex_Operation_isContainedInState_State() const
{
	return m_vertex_Operation_isContainedInState_State;
}

// End Class Vertex

// Begin Class WriteLinkAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getWriteLinkAction_Class() const
{
	return m_writeLinkAction_Class;
}



const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getWriteLinkAction_Operation_allow_access_EDiagnosticChain_EMap() const
{
	return m_writeLinkAction_Operation_allow_access_EDiagnosticChain_EMap;
}

// End Class WriteLinkAction

// Begin Class WriteStructuralFeatureAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getWriteStructuralFeatureAction_Class() const
{
	return m_writeStructuralFeatureAction_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getWriteStructuralFeatureAction_Attribute_result() const
{
	return m_writeStructuralFeatureAction_Attribute_result;
}
const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getWriteStructuralFeatureAction_Attribute_value() const
{
	return m_writeStructuralFeatureAction_Attribute_value;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getWriteStructuralFeatureAction_Operation_multiplicity_of_result_EDiagnosticChain_EMap() const
{
	return m_writeStructuralFeatureAction_Operation_multiplicity_of_result_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getWriteStructuralFeatureAction_Operation_multiplicity_of_value_EDiagnosticChain_EMap() const
{
	return m_writeStructuralFeatureAction_Operation_multiplicity_of_value_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getWriteStructuralFeatureAction_Operation_type_of_result_EDiagnosticChain_EMap() const
{
	return m_writeStructuralFeatureAction_Operation_type_of_result_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getWriteStructuralFeatureAction_Operation_type_of_value_EDiagnosticChain_EMap() const
{
	return m_writeStructuralFeatureAction_Operation_type_of_value_EDiagnosticChain_EMap;
}

// End Class WriteStructuralFeatureAction

// Begin Class WriteVariableAction
const std::shared_ptr<ecore::EClass>& uml::umlPackageImpl::getWriteVariableAction_Class() const
{
	return m_writeVariableAction_Class;
}


const std::shared_ptr<ecore::EReference>& uml::umlPackageImpl::getWriteVariableAction_Attribute_value() const
{
	return m_writeVariableAction_Attribute_value;
}

const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getWriteVariableAction_Operation_multiplicity_EDiagnosticChain_EMap() const
{
	return m_writeVariableAction_Operation_multiplicity_EDiagnosticChain_EMap;
}
const std::shared_ptr<ecore::EOperation>& uml::umlPackageImpl::getWriteVariableAction_Operation_value_type_EDiagnosticChain_EMap() const
{
	return m_writeVariableAction_Operation_value_type_EDiagnosticChain_EMap;
}

// End Class WriteVariableAction
const std::shared_ptr<ecore::EEnum>& uml::umlPackageImpl::getAggregationKind_Class() const
{
	return m_aggregationKind_Class;
}
const std::shared_ptr<ecore::EEnum>& uml::umlPackageImpl::getCallConcurrencyKind_Class() const
{
	return m_callConcurrencyKind_Class;
}
const std::shared_ptr<ecore::EEnum>& uml::umlPackageImpl::getConnectorKind_Class() const
{
	return m_connectorKind_Class;
}
const std::shared_ptr<ecore::EEnum>& uml::umlPackageImpl::getExpansionKind_Class() const
{
	return m_expansionKind_Class;
}
const std::shared_ptr<ecore::EEnum>& uml::umlPackageImpl::getInteractionOperatorKind_Class() const
{
	return m_interactionOperatorKind_Class;
}
const std::shared_ptr<ecore::EEnum>& uml::umlPackageImpl::getMessageKind_Class() const
{
	return m_messageKind_Class;
}
const std::shared_ptr<ecore::EEnum>& uml::umlPackageImpl::getMessageSort_Class() const
{
	return m_messageSort_Class;
}
const std::shared_ptr<ecore::EEnum>& uml::umlPackageImpl::getObjectNodeOrderingKind_Class() const
{
	return m_objectNodeOrderingKind_Class;
}
const std::shared_ptr<ecore::EEnum>& uml::umlPackageImpl::getParameterDirectionKind_Class() const
{
	return m_parameterDirectionKind_Class;
}
const std::shared_ptr<ecore::EEnum>& uml::umlPackageImpl::getParameterEffectKind_Class() const
{
	return m_parameterEffectKind_Class;
}
const std::shared_ptr<ecore::EEnum>& uml::umlPackageImpl::getPseudostateKind_Class() const
{
	return m_pseudostateKind_Class;
}
const std::shared_ptr<ecore::EEnum>& uml::umlPackageImpl::getTransitionKind_Class() const
{
	return m_transitionKind_Class;
}
const std::shared_ptr<ecore::EEnum>& uml::umlPackageImpl::getVisibilityKind_Class() const
{
	return m_visibilityKind_Class;
}

