#include "uml/impl/UmlFactoryImpl.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EClass.hpp"
#include "uml/impl/ElementImpl.hpp"

#include "uml/UmlPackage.hpp"
#include "uml/impl/AbstractionImpl.hpp"
#include "uml/impl/AcceptCallActionImpl.hpp"
#include "uml/impl/AcceptEventActionImpl.hpp"
#include "uml/impl/ActionImpl.hpp"
#include "uml/impl/ActionExecutionSpecificationImpl.hpp"
#include "uml/impl/ActionInputPinImpl.hpp"
#include "uml/impl/ActivityImpl.hpp"
#include "uml/impl/ActivityContentImpl.hpp"
#include "uml/impl/ActivityEdgeImpl.hpp"
#include "uml/impl/ActivityFinalNodeImpl.hpp"
#include "uml/impl/ActivityGroupImpl.hpp"
#include "uml/impl/ActivityNodeImpl.hpp"
#include "uml/impl/ActivityParameterNodeImpl.hpp"
#include "uml/impl/ActivityPartitionImpl.hpp"
#include "uml/impl/ActorImpl.hpp"
#include "uml/impl/AddStructuralFeatureValueActionImpl.hpp"
#include "uml/impl/AddVariableValueActionImpl.hpp"
#include "uml/impl/AnyReceiveEventImpl.hpp"
#include "uml/impl/ArgumentImpl.hpp"
#include "uml/impl/ArtifactImpl.hpp"
#include "uml/impl/AssociationImpl.hpp"
#include "uml/impl/AssociationClassImpl.hpp"
#include "uml/impl/BehaviorImpl.hpp"
#include "uml/impl/BehaviorExecutionSpecificationImpl.hpp"
#include "uml/impl/BehavioralFeatureImpl.hpp"
#include "uml/impl/BehavioredClassifierImpl.hpp"
#include "uml/impl/BroadcastSignalActionImpl.hpp"
#include "uml/impl/CallActionImpl.hpp"
#include "uml/impl/CallBehaviorActionImpl.hpp"
#include "uml/impl/CallEventImpl.hpp"
#include "uml/impl/CallOperationActionImpl.hpp"
#include "uml/impl/CentralBufferNodeImpl.hpp"
#include "uml/impl/ChangeEventImpl.hpp"
#include "uml/impl/ClassImpl.hpp"
#include "uml/impl/ClassifierImpl.hpp"
#include "uml/impl/ClassifierTemplateParameterImpl.hpp"
#include "uml/impl/ClauseImpl.hpp"
#include "uml/impl/ClearAssociationActionImpl.hpp"
#include "uml/impl/ClearStructuralFeatureActionImpl.hpp"
#include "uml/impl/ClearVariableActionImpl.hpp"
#include "uml/impl/CollaborationImpl.hpp"
#include "uml/impl/CollaborationUseImpl.hpp"
#include "uml/impl/CombinedFragmentImpl.hpp"
#include "uml/impl/CommentImpl.hpp"
#include "uml/impl/CommunicationPathImpl.hpp"
#include "uml/impl/ComponentImpl.hpp"
#include "uml/impl/ComponentRealizationImpl.hpp"
#include "uml/impl/ConditionalNodeImpl.hpp"
#include "uml/impl/ConnectableElementImpl.hpp"
#include "uml/impl/ConnectableElementTemplateParameterImpl.hpp"
#include "uml/impl/ConnectionPointReferenceImpl.hpp"
#include "uml/impl/ConnectorImpl.hpp"
#include "uml/impl/ConnectorEndImpl.hpp"
#include "uml/impl/ConsiderIgnoreFragmentImpl.hpp"
#include "uml/impl/ConstraintImpl.hpp"
#include "uml/impl/ContinuationImpl.hpp"
#include "uml/impl/ControlFlowImpl.hpp"
#include "uml/impl/ControlNodeImpl.hpp"
#include "uml/impl/CreateLinkActionImpl.hpp"
#include "uml/impl/CreateLinkObjectActionImpl.hpp"
#include "uml/impl/CreateObjectActionImpl.hpp"
#include "uml/impl/DataStoreNodeImpl.hpp"
#include "uml/impl/DataTypeImpl.hpp"
#include "uml/impl/DecisionNodeImpl.hpp"
#include "uml/impl/DependencyImpl.hpp"
#include "uml/impl/DeployedArtifactImpl.hpp"
#include "uml/impl/DeploymentImpl.hpp"
#include "uml/impl/DeploymentSpecificationImpl.hpp"
#include "uml/impl/DeploymentTargetImpl.hpp"
#include "uml/impl/DestroyLinkActionImpl.hpp"
#include "uml/impl/DestroyObjectActionImpl.hpp"
#include "uml/impl/DestructionOccurrenceSpecificationImpl.hpp"
#include "uml/impl/DeviceImpl.hpp"
#include "uml/impl/DirectedRelationshipImpl.hpp"
#include "uml/impl/DurationImpl.hpp"
#include "uml/impl/DurationConstraintImpl.hpp"
#include "uml/impl/DurationIntervalImpl.hpp"
#include "uml/impl/DurationObservationImpl.hpp"
#include "uml/impl/ElementImpl.hpp"
#include "uml/impl/ElementImportImpl.hpp"
#include "uml/impl/EncapsulatedClassifierImpl.hpp"
#include "uml/impl/EnumerationImpl.hpp"
#include "uml/impl/EnumerationLiteralImpl.hpp"
#include "uml/impl/EventImpl.hpp"
#include "uml/impl/ExceptionHandlerImpl.hpp"
#include "uml/impl/ExecutableNodeImpl.hpp"
#include "uml/impl/ExecutionEnvironmentImpl.hpp"
#include "uml/impl/ExecutionOccurrenceSpecificationImpl.hpp"
#include "uml/impl/ExecutionSpecificationImpl.hpp"
#include "uml/impl/ExpansionNodeImpl.hpp"
#include "uml/impl/ExpansionRegionImpl.hpp"
#include "uml/impl/ExpressionImpl.hpp"
#include "uml/impl/ExtendImpl.hpp"
#include "uml/impl/ExtensionImpl.hpp"
#include "uml/impl/ExtensionEndImpl.hpp"
#include "uml/impl/ExtensionPointImpl.hpp"
#include "uml/impl/FactoryImpl.hpp"
#include "uml/impl/FeatureImpl.hpp"
#include "uml/impl/FinalNodeImpl.hpp"
#include "uml/impl/FinalStateImpl.hpp"
#include "uml/impl/FlowFinalNodeImpl.hpp"
#include "uml/impl/ForkNodeImpl.hpp"
#include "uml/impl/FunctionBehaviorImpl.hpp"
#include "uml/impl/GateImpl.hpp"
#include "uml/impl/GeneralOrderingImpl.hpp"
#include "uml/impl/GeneralizationImpl.hpp"
#include "uml/impl/GeneralizationSetImpl.hpp"
#include "uml/impl/ImageImpl.hpp"
#include "uml/impl/IncludeImpl.hpp"
#include "uml/impl/InformationFlowImpl.hpp"
#include "uml/impl/InformationItemImpl.hpp"
#include "uml/impl/InitialNodeImpl.hpp"
#include "uml/impl/InputPinImpl.hpp"
#include "uml/impl/InstanceSpecificationImpl.hpp"
#include "uml/impl/InstanceValueImpl.hpp"
#include "uml/impl/InteractionImpl.hpp"
#include "uml/impl/InteractionConstraintImpl.hpp"
#include "uml/impl/InteractionFragmentImpl.hpp"
#include "uml/impl/InteractionOperandImpl.hpp"
#include "uml/impl/InteractionUseImpl.hpp"
#include "uml/impl/InterfaceImpl.hpp"
#include "uml/impl/InterfaceRealizationImpl.hpp"
#include "uml/impl/InterruptibleActivityRegionImpl.hpp"
#include "uml/impl/IntervalImpl.hpp"
#include "uml/impl/IntervalConstraintImpl.hpp"
#include "uml/impl/InvocationActionImpl.hpp"
#include "uml/impl/JoinNodeImpl.hpp"
#include "uml/impl/LifelineImpl.hpp"
#include "uml/impl/LinkActionImpl.hpp"
#include "uml/impl/LinkEndCreationDataImpl.hpp"
#include "uml/impl/LinkEndDataImpl.hpp"
#include "uml/impl/LinkEndDestructionDataImpl.hpp"
#include "uml/impl/LiteralBooleanImpl.hpp"
#include "uml/impl/LiteralIntegerImpl.hpp"
#include "uml/impl/LiteralNullImpl.hpp"
#include "uml/impl/LiteralRealImpl.hpp"
#include "uml/impl/LiteralSpecificationImpl.hpp"
#include "uml/impl/LiteralStringImpl.hpp"
#include "uml/impl/LiteralUnlimitedNaturalImpl.hpp"
#include "uml/impl/LoopNodeImpl.hpp"
#include "uml/impl/ManifestationImpl.hpp"
#include "uml/impl/MergeNodeImpl.hpp"
#include "uml/impl/MessageImpl.hpp"
#include "uml/impl/MessageEndImpl.hpp"
#include "uml/impl/MessageEventImpl.hpp"
#include "uml/impl/MessageOccurrenceSpecificationImpl.hpp"
#include "uml/impl/ModelImpl.hpp"
#include "uml/impl/MultiplicityElementImpl.hpp"
#include "uml/impl/NamedElementImpl.hpp"
#include "uml/impl/NamespaceImpl.hpp"
#include "uml/impl/NodeImpl.hpp"
#include "uml/impl/ObjectImpl.hpp"
#include "uml/impl/ObjectFlowImpl.hpp"
#include "uml/impl/ObjectNodeImpl.hpp"
#include "uml/impl/ObservationImpl.hpp"
#include "uml/impl/OccurrenceSpecificationImpl.hpp"
#include "uml/impl/OpaqueActionImpl.hpp"
#include "uml/impl/OpaqueBehaviorImpl.hpp"
#include "uml/impl/OpaqueExpressionImpl.hpp"
#include "uml/impl/OperationImpl.hpp"
#include "uml/impl/OperationTemplateParameterImpl.hpp"
#include "uml/impl/OutputPinImpl.hpp"
#include "uml/impl/PackageImpl.hpp"
#include "uml/impl/PackageImportImpl.hpp"
#include "uml/impl/PackageMergeImpl.hpp"
#include "uml/impl/PackageableElementImpl.hpp"
#include "uml/impl/ParameterImpl.hpp"
#include "uml/impl/ParameterSetImpl.hpp"
#include "uml/impl/ParameterableElementImpl.hpp"
#include "uml/impl/PartDecompositionImpl.hpp"
#include "uml/impl/PinImpl.hpp"
#include "uml/impl/PortImpl.hpp"
#include "uml/impl/PrimitiveTypeImpl.hpp"
#include "uml/impl/ProfileImpl.hpp"
#include "uml/impl/ProfileApplicationImpl.hpp"
#include "uml/impl/PropertyImpl.hpp"
#include "uml/impl/ProtocolConformanceImpl.hpp"
#include "uml/impl/ProtocolStateMachineImpl.hpp"
#include "uml/impl/ProtocolTransitionImpl.hpp"
#include "uml/impl/PseudostateImpl.hpp"
#include "uml/impl/QualifierValueImpl.hpp"
#include "uml/impl/RaiseExceptionActionImpl.hpp"
#include "uml/impl/ReadExtentActionImpl.hpp"
#include "uml/impl/ReadIsClassifiedObjectActionImpl.hpp"
#include "uml/impl/ReadLinkActionImpl.hpp"
#include "uml/impl/ReadLinkObjectEndActionImpl.hpp"
#include "uml/impl/ReadLinkObjectEndQualifierActionImpl.hpp"
#include "uml/impl/ReadSelfActionImpl.hpp"
#include "uml/impl/ReadStructuralFeatureActionImpl.hpp"
#include "uml/impl/ReadVariableActionImpl.hpp"
#include "uml/impl/RealizationImpl.hpp"
#include "uml/impl/ReceptionImpl.hpp"
#include "uml/impl/ReclassifyObjectActionImpl.hpp"
#include "uml/impl/RedefinableElementImpl.hpp"
#include "uml/impl/RedefinableTemplateSignatureImpl.hpp"
#include "uml/impl/ReduceActionImpl.hpp"
#include "uml/impl/RegionImpl.hpp"
#include "uml/impl/RelationshipImpl.hpp"
#include "uml/impl/RemoveStructuralFeatureValueActionImpl.hpp"
#include "uml/impl/RemoveVariableValueActionImpl.hpp"
#include "uml/impl/ReplyActionImpl.hpp"
#include "uml/impl/SendObjectActionImpl.hpp"
#include "uml/impl/SendSignalActionImpl.hpp"
#include "uml/impl/SequenceNodeImpl.hpp"
#include "uml/impl/SignalImpl.hpp"
#include "uml/impl/SignalEventImpl.hpp"
#include "uml/impl/SlotImpl.hpp"
#include "uml/impl/StartClassifierBehaviorActionImpl.hpp"
#include "uml/impl/StartObjectBehaviorActionImpl.hpp"
#include "uml/impl/StateImpl.hpp"
#include "uml/impl/StateInvariantImpl.hpp"
#include "uml/impl/StateMachineImpl.hpp"
#include "uml/impl/StereotypeImpl.hpp"
#include "uml/impl/StringExpressionImpl.hpp"
#include "uml/impl/StructuralFeatureImpl.hpp"
#include "uml/impl/StructuralFeatureActionImpl.hpp"
#include "uml/impl/StructuredActivityNodeImpl.hpp"
#include "uml/impl/StructuredClassifierImpl.hpp"
#include "uml/impl/SubstitutionImpl.hpp"
#include "uml/impl/TemplateBindingImpl.hpp"
#include "uml/impl/TemplateParameterImpl.hpp"
#include "uml/impl/TemplateParameterSubstitutionImpl.hpp"
#include "uml/impl/TemplateSignatureImpl.hpp"
#include "uml/impl/TemplateableElementImpl.hpp"
#include "uml/impl/TestIdentityActionImpl.hpp"
#include "uml/impl/TimeConstraintImpl.hpp"
#include "uml/impl/TimeEventImpl.hpp"
#include "uml/impl/TimeExpressionImpl.hpp"
#include "uml/impl/TimeIntervalImpl.hpp"
#include "uml/impl/TimeObservationImpl.hpp"
#include "uml/impl/TransitionImpl.hpp"
#include "uml/impl/TriggerImpl.hpp"
#include "uml/impl/TypeImpl.hpp"
#include "uml/impl/TypedElementImpl.hpp"
#include "uml/impl/UnmarshallActionImpl.hpp"
#include "uml/impl/UsageImpl.hpp"
#include "uml/impl/UseCaseImpl.hpp"
#include "uml/impl/ValuePinImpl.hpp"
#include "uml/impl/ValueSpecificationImpl.hpp"
#include "uml/impl/ValueSpecificationActionImpl.hpp"
#include "uml/impl/VariableImpl.hpp"
#include "uml/impl/VariableActionImpl.hpp"
#include "uml/impl/VertexImpl.hpp"
#include "uml/impl/WriteLinkActionImpl.hpp"
#include "uml/impl/WriteStructuralFeatureActionImpl.hpp"
#include "uml/impl/WriteVariableActionImpl.hpp"

#include "uml/Component.hpp"
#include "uml/Action.hpp"
#include "uml/Action.hpp"
#include "uml/Activity.hpp"
#include "uml/Activity.hpp"
#include "uml/Activity.hpp"
#include "uml/AddStructuralFeatureValueAction.hpp"
#include "uml/Package.hpp"
#include "uml/Property.hpp"
#include "uml/Behavior.hpp"
#include "uml/BehavioredClassifier.hpp"
#include "uml/TemplateableElement.hpp"
#include "uml/CallAction.hpp"
#include "uml/CallOperationAction.hpp"
#include "uml/Class.hpp"
#include "uml/Class.hpp"
#include "uml/ClearStructuralFeatureAction.hpp"
#include "uml/Region.hpp"
#include "uml/Region.hpp"
#include "uml/Namespace.hpp"
#include "uml/CreateObjectAction.hpp"
#include "uml/DataType.hpp"
#include "uml/DataType.hpp"
#include "uml/Deployment.hpp"
#include "uml/DestroyObjectAction.hpp"
#include "uml/Interaction.hpp"
#include "uml/InteractionOperand.hpp"
#include "uml/Enumeration.hpp"
#include "uml/UseCase.hpp"
#include "uml/BehavioredClassifier.hpp"
#include "uml/Namespace.hpp"
#include "uml/Namespace.hpp"
#include "uml/Activity.hpp"
#include "uml/StructuredActivityNode.hpp"
#include "uml/StructuredActivityNode.hpp"
#include "uml/UseCase.hpp"
#include "uml/Interaction.hpp"
#include "uml/Interaction.hpp"
#include "uml/Interface.hpp"
#include "uml/Interface.hpp"
#include "uml/InvocationAction.hpp"
#include "uml/DeploymentTarget.hpp"
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
#include "uml/Operation.hpp"
#include "uml/Element.hpp"
#include "uml/Association.hpp"
#include "uml/StringExpression.hpp"
#include "uml/InstanceSpecification.hpp"
#include "uml/Package.hpp"
#include "uml/Slot.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/Package.hpp"
#include "uml/ExecutableNode.hpp"
#include "uml/ReadSelfAction.hpp"
#include "uml/ReadStructuralFeatureAction.hpp"
#include "uml/Package.hpp"
#include "uml/StructuredActivityNode.hpp"
#include "uml/TemplateSignature.hpp"
#include "uml/Classifier.hpp"
#include "uml/ProtocolStateMachine.hpp"
#include "uml/State.hpp"
#include "uml/State.hpp"
#include "uml/State.hpp"
#include "uml/StateMachine.hpp"
#include "uml/StateMachine.hpp"
#include "uml/StructuralFeatureAction.hpp"
#include "uml/Classifier.hpp"
#include "uml/ActivityGroup.hpp"
#include "uml/ActivityPartition.hpp"
#include "uml/TemplateableElement.hpp"
#include "uml/TemplateBinding.hpp"
#include "uml/UseCase.hpp"
#include "uml/ValueSpecificationAction.hpp"
#include "uml/ValueSpecificationAction.hpp"
#include "uml/WriteStructuralFeatureAction.hpp"
#include "uml/WriteStructuralFeatureAction.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************

UmlFactoryImpl::UmlFactoryImpl()
{
	m_idMap.insert(std::make_pair("Abstraction", UmlPackage::ABSTRACTION_CLASS));
	m_idMap.insert(std::make_pair("AcceptCallAction", UmlPackage::ACCEPTCALLACTION_CLASS));
	m_idMap.insert(std::make_pair("AcceptEventAction", UmlPackage::ACCEPTEVENTACTION_CLASS));
	m_idMap.insert(std::make_pair("ActionExecutionSpecification", UmlPackage::ACTIONEXECUTIONSPECIFICATION_CLASS));
	m_idMap.insert(std::make_pair("ActionInputPin", UmlPackage::ACTIONINPUTPIN_CLASS));
	m_idMap.insert(std::make_pair("Activity", UmlPackage::ACTIVITY_CLASS));
	m_idMap.insert(std::make_pair("ActivityFinalNode", UmlPackage::ACTIVITYFINALNODE_CLASS));
	m_idMap.insert(std::make_pair("ActivityParameterNode", UmlPackage::ACTIVITYPARAMETERNODE_CLASS));
	m_idMap.insert(std::make_pair("ActivityPartition", UmlPackage::ACTIVITYPARTITION_CLASS));
	m_idMap.insert(std::make_pair("Actor", UmlPackage::ACTOR_CLASS));
	m_idMap.insert(std::make_pair("AddStructuralFeatureValueAction", UmlPackage::ADDSTRUCTURALFEATUREVALUEACTION_CLASS));
	m_idMap.insert(std::make_pair("AddVariableValueAction", UmlPackage::ADDVARIABLEVALUEACTION_CLASS));
	m_idMap.insert(std::make_pair("AnyReceiveEvent", UmlPackage::ANYRECEIVEEVENT_CLASS));
	m_idMap.insert(std::make_pair("Argument", UmlPackage::ARGUMENT_CLASS));
	m_idMap.insert(std::make_pair("Artifact", UmlPackage::ARTIFACT_CLASS));
	m_idMap.insert(std::make_pair("Association", UmlPackage::ASSOCIATION_CLASS));
	m_idMap.insert(std::make_pair("AssociationClass", UmlPackage::ASSOCIATIONCLASS_CLASS));
	m_idMap.insert(std::make_pair("BehaviorExecutionSpecification", UmlPackage::BEHAVIOREXECUTIONSPECIFICATION_CLASS));
	m_idMap.insert(std::make_pair("BroadcastSignalAction", UmlPackage::BROADCASTSIGNALACTION_CLASS));
	m_idMap.insert(std::make_pair("CallBehaviorAction", UmlPackage::CALLBEHAVIORACTION_CLASS));
	m_idMap.insert(std::make_pair("CallEvent", UmlPackage::CALLEVENT_CLASS));
	m_idMap.insert(std::make_pair("CallOperationAction", UmlPackage::CALLOPERATIONACTION_CLASS));
	m_idMap.insert(std::make_pair("CentralBufferNode", UmlPackage::CENTRALBUFFERNODE_CLASS));
	m_idMap.insert(std::make_pair("ChangeEvent", UmlPackage::CHANGEEVENT_CLASS));
	m_idMap.insert(std::make_pair("Class", UmlPackage::CLASS_CLASS));
	m_idMap.insert(std::make_pair("ClassifierTemplateParameter", UmlPackage::CLASSIFIERTEMPLATEPARAMETER_CLASS));
	m_idMap.insert(std::make_pair("Clause", UmlPackage::CLAUSE_CLASS));
	m_idMap.insert(std::make_pair("ClearAssociationAction", UmlPackage::CLEARASSOCIATIONACTION_CLASS));
	m_idMap.insert(std::make_pair("ClearStructuralFeatureAction", UmlPackage::CLEARSTRUCTURALFEATUREACTION_CLASS));
	m_idMap.insert(std::make_pair("ClearVariableAction", UmlPackage::CLEARVARIABLEACTION_CLASS));
	m_idMap.insert(std::make_pair("Collaboration", UmlPackage::COLLABORATION_CLASS));
	m_idMap.insert(std::make_pair("CollaborationUse", UmlPackage::COLLABORATIONUSE_CLASS));
	m_idMap.insert(std::make_pair("CombinedFragment", UmlPackage::COMBINEDFRAGMENT_CLASS));
	m_idMap.insert(std::make_pair("Comment", UmlPackage::COMMENT_CLASS));
	m_idMap.insert(std::make_pair("CommunicationPath", UmlPackage::COMMUNICATIONPATH_CLASS));
	m_idMap.insert(std::make_pair("Component", UmlPackage::COMPONENT_CLASS));
	m_idMap.insert(std::make_pair("ComponentRealization", UmlPackage::COMPONENTREALIZATION_CLASS));
	m_idMap.insert(std::make_pair("ConditionalNode", UmlPackage::CONDITIONALNODE_CLASS));
	m_idMap.insert(std::make_pair("ConnectableElementTemplateParameter", UmlPackage::CONNECTABLEELEMENTTEMPLATEPARAMETER_CLASS));
	m_idMap.insert(std::make_pair("ConnectionPointReference", UmlPackage::CONNECTIONPOINTREFERENCE_CLASS));
	m_idMap.insert(std::make_pair("Connector", UmlPackage::CONNECTOR_CLASS));
	m_idMap.insert(std::make_pair("ConnectorEnd", UmlPackage::CONNECTOREND_CLASS));
	m_idMap.insert(std::make_pair("ConsiderIgnoreFragment", UmlPackage::CONSIDERIGNOREFRAGMENT_CLASS));
	m_idMap.insert(std::make_pair("Constraint", UmlPackage::CONSTRAINT_CLASS));
	m_idMap.insert(std::make_pair("Continuation", UmlPackage::CONTINUATION_CLASS));
	m_idMap.insert(std::make_pair("ControlFlow", UmlPackage::CONTROLFLOW_CLASS));
	m_idMap.insert(std::make_pair("CreateLinkAction", UmlPackage::CREATELINKACTION_CLASS));
	m_idMap.insert(std::make_pair("CreateLinkObjectAction", UmlPackage::CREATELINKOBJECTACTION_CLASS));
	m_idMap.insert(std::make_pair("CreateObjectAction", UmlPackage::CREATEOBJECTACTION_CLASS));
	m_idMap.insert(std::make_pair("DataStoreNode", UmlPackage::DATASTORENODE_CLASS));
	m_idMap.insert(std::make_pair("DataType", UmlPackage::DATATYPE_CLASS));
	m_idMap.insert(std::make_pair("DecisionNode", UmlPackage::DECISIONNODE_CLASS));
	m_idMap.insert(std::make_pair("Dependency", UmlPackage::DEPENDENCY_CLASS));
	m_idMap.insert(std::make_pair("Deployment", UmlPackage::DEPLOYMENT_CLASS));
	m_idMap.insert(std::make_pair("DeploymentSpecification", UmlPackage::DEPLOYMENTSPECIFICATION_CLASS));
	m_idMap.insert(std::make_pair("DestroyLinkAction", UmlPackage::DESTROYLINKACTION_CLASS));
	m_idMap.insert(std::make_pair("DestroyObjectAction", UmlPackage::DESTROYOBJECTACTION_CLASS));
	m_idMap.insert(std::make_pair("DestructionOccurrenceSpecification", UmlPackage::DESTRUCTIONOCCURRENCESPECIFICATION_CLASS));
	m_idMap.insert(std::make_pair("Device", UmlPackage::DEVICE_CLASS));
	m_idMap.insert(std::make_pair("Duration", UmlPackage::DURATION_CLASS));
	m_idMap.insert(std::make_pair("DurationConstraint", UmlPackage::DURATIONCONSTRAINT_CLASS));
	m_idMap.insert(std::make_pair("DurationInterval", UmlPackage::DURATIONINTERVAL_CLASS));
	m_idMap.insert(std::make_pair("DurationObservation", UmlPackage::DURATIONOBSERVATION_CLASS));
	m_idMap.insert(std::make_pair("ElementImport", UmlPackage::ELEMENTIMPORT_CLASS));
	m_idMap.insert(std::make_pair("Enumeration", UmlPackage::ENUMERATION_CLASS));
	m_idMap.insert(std::make_pair("EnumerationLiteral", UmlPackage::ENUMERATIONLITERAL_CLASS));
	m_idMap.insert(std::make_pair("ExceptionHandler", UmlPackage::EXCEPTIONHANDLER_CLASS));
	m_idMap.insert(std::make_pair("ExecutionEnvironment", UmlPackage::EXECUTIONENVIRONMENT_CLASS));
	m_idMap.insert(std::make_pair("ExecutionOccurrenceSpecification", UmlPackage::EXECUTIONOCCURRENCESPECIFICATION_CLASS));
	m_idMap.insert(std::make_pair("ExpansionNode", UmlPackage::EXPANSIONNODE_CLASS));
	m_idMap.insert(std::make_pair("ExpansionRegion", UmlPackage::EXPANSIONREGION_CLASS));
	m_idMap.insert(std::make_pair("Expression", UmlPackage::EXPRESSION_CLASS));
	m_idMap.insert(std::make_pair("Extend", UmlPackage::EXTEND_CLASS));
	m_idMap.insert(std::make_pair("Extension", UmlPackage::EXTENSION_CLASS));
	m_idMap.insert(std::make_pair("ExtensionEnd", UmlPackage::EXTENSIONEND_CLASS));
	m_idMap.insert(std::make_pair("ExtensionPoint", UmlPackage::EXTENSIONPOINT_CLASS));
	m_idMap.insert(std::make_pair("Factory", UmlPackage::FACTORY_CLASS));
	m_idMap.insert(std::make_pair("FinalState", UmlPackage::FINALSTATE_CLASS));
	m_idMap.insert(std::make_pair("FlowFinalNode", UmlPackage::FLOWFINALNODE_CLASS));
	m_idMap.insert(std::make_pair("ForkNode", UmlPackage::FORKNODE_CLASS));
	m_idMap.insert(std::make_pair("FunctionBehavior", UmlPackage::FUNCTIONBEHAVIOR_CLASS));
	m_idMap.insert(std::make_pair("Gate", UmlPackage::GATE_CLASS));
	m_idMap.insert(std::make_pair("GeneralOrdering", UmlPackage::GENERALORDERING_CLASS));
	m_idMap.insert(std::make_pair("Generalization", UmlPackage::GENERALIZATION_CLASS));
	m_idMap.insert(std::make_pair("GeneralizationSet", UmlPackage::GENERALIZATIONSET_CLASS));
	m_idMap.insert(std::make_pair("Image", UmlPackage::IMAGE_CLASS));
	m_idMap.insert(std::make_pair("Include", UmlPackage::INCLUDE_CLASS));
	m_idMap.insert(std::make_pair("InformationFlow", UmlPackage::INFORMATIONFLOW_CLASS));
	m_idMap.insert(std::make_pair("InformationItem", UmlPackage::INFORMATIONITEM_CLASS));
	m_idMap.insert(std::make_pair("InitialNode", UmlPackage::INITIALNODE_CLASS));
	m_idMap.insert(std::make_pair("InputPin", UmlPackage::INPUTPIN_CLASS));
	m_idMap.insert(std::make_pair("InstanceSpecification", UmlPackage::INSTANCESPECIFICATION_CLASS));
	m_idMap.insert(std::make_pair("InstanceValue", UmlPackage::INSTANCEVALUE_CLASS));
	m_idMap.insert(std::make_pair("Interaction", UmlPackage::INTERACTION_CLASS));
	m_idMap.insert(std::make_pair("InteractionConstraint", UmlPackage::INTERACTIONCONSTRAINT_CLASS));
	m_idMap.insert(std::make_pair("InteractionOperand", UmlPackage::INTERACTIONOPERAND_CLASS));
	m_idMap.insert(std::make_pair("InteractionUse", UmlPackage::INTERACTIONUSE_CLASS));
	m_idMap.insert(std::make_pair("Interface", UmlPackage::INTERFACE_CLASS));
	m_idMap.insert(std::make_pair("InterfaceRealization", UmlPackage::INTERFACEREALIZATION_CLASS));
	m_idMap.insert(std::make_pair("InterruptibleActivityRegion", UmlPackage::INTERRUPTIBLEACTIVITYREGION_CLASS));
	m_idMap.insert(std::make_pair("Interval", UmlPackage::INTERVAL_CLASS));
	m_idMap.insert(std::make_pair("IntervalConstraint", UmlPackage::INTERVALCONSTRAINT_CLASS));
	m_idMap.insert(std::make_pair("JoinNode", UmlPackage::JOINNODE_CLASS));
	m_idMap.insert(std::make_pair("Lifeline", UmlPackage::LIFELINE_CLASS));
	m_idMap.insert(std::make_pair("LinkEndCreationData", UmlPackage::LINKENDCREATIONDATA_CLASS));
	m_idMap.insert(std::make_pair("LinkEndData", UmlPackage::LINKENDDATA_CLASS));
	m_idMap.insert(std::make_pair("LinkEndDestructionData", UmlPackage::LINKENDDESTRUCTIONDATA_CLASS));
	m_idMap.insert(std::make_pair("LiteralBoolean", UmlPackage::LITERALBOOLEAN_CLASS));
	m_idMap.insert(std::make_pair("LiteralInteger", UmlPackage::LITERALINTEGER_CLASS));
	m_idMap.insert(std::make_pair("LiteralNull", UmlPackage::LITERALNULL_CLASS));
	m_idMap.insert(std::make_pair("LiteralReal", UmlPackage::LITERALREAL_CLASS));
	m_idMap.insert(std::make_pair("LiteralString", UmlPackage::LITERALSTRING_CLASS));
	m_idMap.insert(std::make_pair("LiteralUnlimitedNatural", UmlPackage::LITERALUNLIMITEDNATURAL_CLASS));
	m_idMap.insert(std::make_pair("LoopNode", UmlPackage::LOOPNODE_CLASS));
	m_idMap.insert(std::make_pair("Manifestation", UmlPackage::MANIFESTATION_CLASS));
	m_idMap.insert(std::make_pair("MergeNode", UmlPackage::MERGENODE_CLASS));
	m_idMap.insert(std::make_pair("Message", UmlPackage::MESSAGE_CLASS));
	m_idMap.insert(std::make_pair("MessageOccurrenceSpecification", UmlPackage::MESSAGEOCCURRENCESPECIFICATION_CLASS));
	m_idMap.insert(std::make_pair("Model", UmlPackage::MODEL_CLASS));
	m_idMap.insert(std::make_pair("Node", UmlPackage::NODE_CLASS));
	m_idMap.insert(std::make_pair("Object", UmlPackage::OBJECT_CLASS));
	m_idMap.insert(std::make_pair("ObjectFlow", UmlPackage::OBJECTFLOW_CLASS));
	m_idMap.insert(std::make_pair("OccurrenceSpecification", UmlPackage::OCCURRENCESPECIFICATION_CLASS));
	m_idMap.insert(std::make_pair("OpaqueAction", UmlPackage::OPAQUEACTION_CLASS));
	m_idMap.insert(std::make_pair("OpaqueBehavior", UmlPackage::OPAQUEBEHAVIOR_CLASS));
	m_idMap.insert(std::make_pair("OpaqueExpression", UmlPackage::OPAQUEEXPRESSION_CLASS));
	m_idMap.insert(std::make_pair("Operation", UmlPackage::OPERATION_CLASS));
	m_idMap.insert(std::make_pair("OperationTemplateParameter", UmlPackage::OPERATIONTEMPLATEPARAMETER_CLASS));
	m_idMap.insert(std::make_pair("OutputPin", UmlPackage::OUTPUTPIN_CLASS));
	m_idMap.insert(std::make_pair("Package", UmlPackage::PACKAGE_CLASS));
	m_idMap.insert(std::make_pair("PackageImport", UmlPackage::PACKAGEIMPORT_CLASS));
	m_idMap.insert(std::make_pair("PackageMerge", UmlPackage::PACKAGEMERGE_CLASS));
	m_idMap.insert(std::make_pair("Parameter", UmlPackage::PARAMETER_CLASS));
	m_idMap.insert(std::make_pair("ParameterSet", UmlPackage::PARAMETERSET_CLASS));
	m_idMap.insert(std::make_pair("PartDecomposition", UmlPackage::PARTDECOMPOSITION_CLASS));
	m_idMap.insert(std::make_pair("Port", UmlPackage::PORT_CLASS));
	m_idMap.insert(std::make_pair("PrimitiveType", UmlPackage::PRIMITIVETYPE_CLASS));
	m_idMap.insert(std::make_pair("Profile", UmlPackage::PROFILE_CLASS));
	m_idMap.insert(std::make_pair("ProfileApplication", UmlPackage::PROFILEAPPLICATION_CLASS));
	m_idMap.insert(std::make_pair("Property", UmlPackage::PROPERTY_CLASS));
	m_idMap.insert(std::make_pair("ProtocolConformance", UmlPackage::PROTOCOLCONFORMANCE_CLASS));
	m_idMap.insert(std::make_pair("ProtocolStateMachine", UmlPackage::PROTOCOLSTATEMACHINE_CLASS));
	m_idMap.insert(std::make_pair("ProtocolTransition", UmlPackage::PROTOCOLTRANSITION_CLASS));
	m_idMap.insert(std::make_pair("Pseudostate", UmlPackage::PSEUDOSTATE_CLASS));
	m_idMap.insert(std::make_pair("QualifierValue", UmlPackage::QUALIFIERVALUE_CLASS));
	m_idMap.insert(std::make_pair("RaiseExceptionAction", UmlPackage::RAISEEXCEPTIONACTION_CLASS));
	m_idMap.insert(std::make_pair("ReadExtentAction", UmlPackage::READEXTENTACTION_CLASS));
	m_idMap.insert(std::make_pair("ReadIsClassifiedObjectAction", UmlPackage::READISCLASSIFIEDOBJECTACTION_CLASS));
	m_idMap.insert(std::make_pair("ReadLinkAction", UmlPackage::READLINKACTION_CLASS));
	m_idMap.insert(std::make_pair("ReadLinkObjectEndAction", UmlPackage::READLINKOBJECTENDACTION_CLASS));
	m_idMap.insert(std::make_pair("ReadLinkObjectEndQualifierAction", UmlPackage::READLINKOBJECTENDQUALIFIERACTION_CLASS));
	m_idMap.insert(std::make_pair("ReadSelfAction", UmlPackage::READSELFACTION_CLASS));
	m_idMap.insert(std::make_pair("ReadStructuralFeatureAction", UmlPackage::READSTRUCTURALFEATUREACTION_CLASS));
	m_idMap.insert(std::make_pair("ReadVariableAction", UmlPackage::READVARIABLEACTION_CLASS));
	m_idMap.insert(std::make_pair("Realization", UmlPackage::REALIZATION_CLASS));
	m_idMap.insert(std::make_pair("Reception", UmlPackage::RECEPTION_CLASS));
	m_idMap.insert(std::make_pair("ReclassifyObjectAction", UmlPackage::RECLASSIFYOBJECTACTION_CLASS));
	m_idMap.insert(std::make_pair("RedefinableTemplateSignature", UmlPackage::REDEFINABLETEMPLATESIGNATURE_CLASS));
	m_idMap.insert(std::make_pair("ReduceAction", UmlPackage::REDUCEACTION_CLASS));
	m_idMap.insert(std::make_pair("Region", UmlPackage::REGION_CLASS));
	m_idMap.insert(std::make_pair("RemoveStructuralFeatureValueAction", UmlPackage::REMOVESTRUCTURALFEATUREVALUEACTION_CLASS));
	m_idMap.insert(std::make_pair("RemoveVariableValueAction", UmlPackage::REMOVEVARIABLEVALUEACTION_CLASS));
	m_idMap.insert(std::make_pair("ReplyAction", UmlPackage::REPLYACTION_CLASS));
	m_idMap.insert(std::make_pair("SendObjectAction", UmlPackage::SENDOBJECTACTION_CLASS));
	m_idMap.insert(std::make_pair("SendSignalAction", UmlPackage::SENDSIGNALACTION_CLASS));
	m_idMap.insert(std::make_pair("SequenceNode", UmlPackage::SEQUENCENODE_CLASS));
	m_idMap.insert(std::make_pair("Signal", UmlPackage::SIGNAL_CLASS));
	m_idMap.insert(std::make_pair("SignalEvent", UmlPackage::SIGNALEVENT_CLASS));
	m_idMap.insert(std::make_pair("Slot", UmlPackage::SLOT_CLASS));
	m_idMap.insert(std::make_pair("StartClassifierBehaviorAction", UmlPackage::STARTCLASSIFIERBEHAVIORACTION_CLASS));
	m_idMap.insert(std::make_pair("StartObjectBehaviorAction", UmlPackage::STARTOBJECTBEHAVIORACTION_CLASS));
	m_idMap.insert(std::make_pair("State", UmlPackage::STATE_CLASS));
	m_idMap.insert(std::make_pair("StateInvariant", UmlPackage::STATEINVARIANT_CLASS));
	m_idMap.insert(std::make_pair("StateMachine", UmlPackage::STATEMACHINE_CLASS));
	m_idMap.insert(std::make_pair("Stereotype", UmlPackage::STEREOTYPE_CLASS));
	m_idMap.insert(std::make_pair("StringExpression", UmlPackage::STRINGEXPRESSION_CLASS));
	m_idMap.insert(std::make_pair("StructuredActivityNode", UmlPackage::STRUCTUREDACTIVITYNODE_CLASS));
	m_idMap.insert(std::make_pair("Substitution", UmlPackage::SUBSTITUTION_CLASS));
	m_idMap.insert(std::make_pair("TemplateBinding", UmlPackage::TEMPLATEBINDING_CLASS));
	m_idMap.insert(std::make_pair("TemplateParameter", UmlPackage::TEMPLATEPARAMETER_CLASS));
	m_idMap.insert(std::make_pair("TemplateParameterSubstitution", UmlPackage::TEMPLATEPARAMETERSUBSTITUTION_CLASS));
	m_idMap.insert(std::make_pair("TemplateSignature", UmlPackage::TEMPLATESIGNATURE_CLASS));
	m_idMap.insert(std::make_pair("TestIdentityAction", UmlPackage::TESTIDENTITYACTION_CLASS));
	m_idMap.insert(std::make_pair("TimeConstraint", UmlPackage::TIMECONSTRAINT_CLASS));
	m_idMap.insert(std::make_pair("TimeEvent", UmlPackage::TIMEEVENT_CLASS));
	m_idMap.insert(std::make_pair("TimeExpression", UmlPackage::TIMEEXPRESSION_CLASS));
	m_idMap.insert(std::make_pair("TimeInterval", UmlPackage::TIMEINTERVAL_CLASS));
	m_idMap.insert(std::make_pair("TimeObservation", UmlPackage::TIMEOBSERVATION_CLASS));
	m_idMap.insert(std::make_pair("Transition", UmlPackage::TRANSITION_CLASS));
	m_idMap.insert(std::make_pair("Trigger", UmlPackage::TRIGGER_CLASS));
	m_idMap.insert(std::make_pair("UnmarshallAction", UmlPackage::UNMARSHALLACTION_CLASS));
	m_idMap.insert(std::make_pair("Usage", UmlPackage::USAGE_CLASS));
	m_idMap.insert(std::make_pair("UseCase", UmlPackage::USECASE_CLASS));
	m_idMap.insert(std::make_pair("ValuePin", UmlPackage::VALUEPIN_CLASS));
	m_idMap.insert(std::make_pair("ValueSpecificationAction", UmlPackage::VALUESPECIFICATIONACTION_CLASS));
	m_idMap.insert(std::make_pair("Variable", UmlPackage::VARIABLE_CLASS));
}

UmlFactoryImpl::~UmlFactoryImpl()
{
}

UmlFactory* UmlFactoryImpl::create()
{
	return new UmlFactoryImpl();
}

//*********************************
// creators
//*********************************

std::shared_ptr<ecore::EObject> UmlFactoryImpl::create(const int metaElementID, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	switch(metaElementID)
	{
		case UmlPackage::ABSTRACTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createAbstraction(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Abstraction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createAbstraction_in_Namespace(castedContainer,metaElementID);
					}
					//Abstraction has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createAbstraction_in_Owner(castedContainer,metaElementID);
					}
					//Abstraction has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createAbstraction_in_OwningPackage(castedContainer,metaElementID);
					}
					//Abstraction has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createAbstraction_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::ACCEPTCALLACTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createAcceptCallAction(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//AcceptCallAction has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createAcceptCallAction_in_Activity(castedContainer,metaElementID);
					}
					//AcceptCallAction has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createAcceptCallAction_in_InStructuredNode(castedContainer,metaElementID);
					}
					//AcceptCallAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createAcceptCallAction_in_Namespace(castedContainer,metaElementID);
					}
					//AcceptCallAction has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createAcceptCallAction_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::ACCEPTEVENTACTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createAcceptEventAction(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//AcceptEventAction has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createAcceptEventAction_in_Activity(castedContainer,metaElementID);
					}
					//AcceptEventAction has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createAcceptEventAction_in_InStructuredNode(castedContainer,metaElementID);
					}
					//AcceptEventAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createAcceptEventAction_in_Namespace(castedContainer,metaElementID);
					}
					//AcceptEventAction has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createAcceptEventAction_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::ACTIONEXECUTIONSPECIFICATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createActionExecutionSpecification(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ActionExecutionSpecification has enclosingInteraction as a containment
					case  UmlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGINTERACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Interaction>(container);
						return this->createActionExecutionSpecification_in_EnclosingInteraction(castedContainer,metaElementID);
					}
					//ActionExecutionSpecification has enclosingOperand as a containment
					case  UmlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGOPERAND:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::InteractionOperand>(container);
						return this->createActionExecutionSpecification_in_EnclosingOperand(castedContainer,metaElementID);
					}
					//ActionExecutionSpecification has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createActionExecutionSpecification_in_Namespace(castedContainer,metaElementID);
					}
					//ActionExecutionSpecification has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createActionExecutionSpecification_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::ACTIONINPUTPIN_CLASS:
		{
			if (nullptr == container)
			{
				return this->createActionInputPin(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ActionInputPin has action as a containment
					case  UmlPackage::INPUTPIN_ATTRIBUTE_ACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Action>(container);
						return this->createActionInputPin_in_Action(castedContainer,metaElementID);
					}
					//ActionInputPin has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createActionInputPin_in_Activity(castedContainer,metaElementID);
					}
					//ActionInputPin has addStructuralFeatureValueAction as a containment
					case  UmlPackage::INPUTPIN_ATTRIBUTE_ADDSTRUCTURALFEATUREVALUEACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::AddStructuralFeatureValueAction>(container);
						return this->createActionInputPin_in_AddStructuralFeatureValueAction(castedContainer,metaElementID);
					}
					//ActionInputPin has callOperationAction as a containment
					case  UmlPackage::INPUTPIN_ATTRIBUTE_CALLOPERATIONACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::CallOperationAction>(container);
						return this->createActionInputPin_in_CallOperationAction(castedContainer,metaElementID);
					}
					//ActionInputPin has destroyObjectAction as a containment
					case  UmlPackage::INPUTPIN_ATTRIBUTE_DESTROYOBJECTACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::DestroyObjectAction>(container);
						return this->createActionInputPin_in_DestroyObjectAction(castedContainer,metaElementID);
					}
					//ActionInputPin has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createActionInputPin_in_InStructuredNode(castedContainer,metaElementID);
					}
					//ActionInputPin has invocationAction as a containment
					case  UmlPackage::INPUTPIN_ATTRIBUTE_INVOCATIONACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::InvocationAction>(container);
						return this->createActionInputPin_in_InvocationAction(castedContainer,metaElementID);
					}
					//ActionInputPin has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createActionInputPin_in_Namespace(castedContainer,metaElementID);
					}
					//ActionInputPin has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createActionInputPin_in_Owner(castedContainer,metaElementID);
					}
					//ActionInputPin has structuralFeatureAction as a containment
					case  UmlPackage::INPUTPIN_ATTRIBUTE_STRUCTURALFEATUREACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuralFeatureAction>(container);
						return this->createActionInputPin_in_StructuralFeatureAction(castedContainer,metaElementID);
					}
					//ActionInputPin has writeStructuralFeatureAction as a containment
					case  UmlPackage::INPUTPIN_ATTRIBUTE_WRITESTRUCTURALFEATUREACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::WriteStructuralFeatureAction>(container);
						return this->createActionInputPin_in_WriteStructuralFeatureAction(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::ACTIVITY_CLASS:
		{
			if (nullptr == container)
			{
				return this->createActivity(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Activity has behavioredClassifier as a containment
					case  UmlPackage::BEHAVIOR_ATTRIBUTE_BEHAVIOREDCLASSIFIER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::BehavioredClassifier>(container);
						return this->createActivity_in_BehavioredClassifier(castedContainer,metaElementID);
					}
					//Activity has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createActivity_in_Namespace(castedContainer,metaElementID);
					}
					//Activity has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createActivity_in_Owner(castedContainer,metaElementID);
					}
					//Activity has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createActivity_in_OwningPackage(castedContainer,metaElementID);
					}
					//Activity has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createActivity_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//Activity has package as a containment
					case  UmlPackage::TYPE_ATTRIBUTE_PACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createActivity_in_Package(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::ACTIVITYFINALNODE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createActivityFinalNode(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ActivityFinalNode has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createActivityFinalNode_in_Activity(castedContainer,metaElementID);
					}
					//ActivityFinalNode has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createActivityFinalNode_in_InStructuredNode(castedContainer,metaElementID);
					}
					//ActivityFinalNode has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createActivityFinalNode_in_Namespace(castedContainer,metaElementID);
					}
					//ActivityFinalNode has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createActivityFinalNode_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::ACTIVITYPARAMETERNODE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createActivityParameterNode(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ActivityParameterNode has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createActivityParameterNode_in_Activity(castedContainer,metaElementID);
					}
					//ActivityParameterNode has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createActivityParameterNode_in_InStructuredNode(castedContainer,metaElementID);
					}
					//ActivityParameterNode has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createActivityParameterNode_in_Namespace(castedContainer,metaElementID);
					}
					//ActivityParameterNode has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createActivityParameterNode_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::ACTIVITYPARTITION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createActivityPartition(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ActivityPartition has inActivity as a containment
					case  UmlPackage::ACTIVITYGROUP_ATTRIBUTE_INACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createActivityPartition_in_InActivity(castedContainer,metaElementID);
					}
					//ActivityPartition has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createActivityPartition_in_Namespace(castedContainer,metaElementID);
					}
					//ActivityPartition has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createActivityPartition_in_Owner(castedContainer,metaElementID);
					}
					//ActivityPartition has superGroup as a containment
					case  UmlPackage::ACTIVITYGROUP_ATTRIBUTE_SUPERGROUP:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::ActivityGroup>(container);
						return this->createActivityPartition_in_SuperGroup(castedContainer,metaElementID);
					}
					//ActivityPartition has superPartition as a containment
					case  UmlPackage::ACTIVITYPARTITION_ATTRIBUTE_SUPERPARTITION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::ActivityPartition>(container);
						return this->createActivityPartition_in_SuperPartition(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::ACTOR_CLASS:
		{
			if (nullptr == container)
			{
				return this->createActor(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Actor has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createActor_in_Namespace(castedContainer,metaElementID);
					}
					//Actor has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createActor_in_Owner(castedContainer,metaElementID);
					}
					//Actor has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createActor_in_OwningPackage(castedContainer,metaElementID);
					}
					//Actor has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createActor_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//Actor has package as a containment
					case  UmlPackage::TYPE_ATTRIBUTE_PACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createActor_in_Package(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::ADDSTRUCTURALFEATUREVALUEACTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createAddStructuralFeatureValueAction(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//AddStructuralFeatureValueAction has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createAddStructuralFeatureValueAction_in_Activity(castedContainer,metaElementID);
					}
					//AddStructuralFeatureValueAction has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createAddStructuralFeatureValueAction_in_InStructuredNode(castedContainer,metaElementID);
					}
					//AddStructuralFeatureValueAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createAddStructuralFeatureValueAction_in_Namespace(castedContainer,metaElementID);
					}
					//AddStructuralFeatureValueAction has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createAddStructuralFeatureValueAction_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::ADDVARIABLEVALUEACTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createAddVariableValueAction(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//AddVariableValueAction has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createAddVariableValueAction_in_Activity(castedContainer,metaElementID);
					}
					//AddVariableValueAction has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createAddVariableValueAction_in_InStructuredNode(castedContainer,metaElementID);
					}
					//AddVariableValueAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createAddVariableValueAction_in_Namespace(castedContainer,metaElementID);
					}
					//AddVariableValueAction has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createAddVariableValueAction_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::ANYRECEIVEEVENT_CLASS:
		{
			if (nullptr == container)
			{
				return this->createAnyReceiveEvent(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//AnyReceiveEvent has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createAnyReceiveEvent_in_Namespace(castedContainer,metaElementID);
					}
					//AnyReceiveEvent has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createAnyReceiveEvent_in_Owner(castedContainer,metaElementID);
					}
					//AnyReceiveEvent has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createAnyReceiveEvent_in_OwningPackage(castedContainer,metaElementID);
					}
					//AnyReceiveEvent has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createAnyReceiveEvent_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::ARGUMENT_CLASS:
		{
				return this->createArgument(metaElementID);
			
		}
		case UmlPackage::ARTIFACT_CLASS:
		{
			if (nullptr == container)
			{
				return this->createArtifact(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Artifact has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createArtifact_in_Namespace(castedContainer,metaElementID);
					}
					//Artifact has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createArtifact_in_Owner(castedContainer,metaElementID);
					}
					//Artifact has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createArtifact_in_OwningPackage(castedContainer,metaElementID);
					}
					//Artifact has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createArtifact_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//Artifact has package as a containment
					case  UmlPackage::TYPE_ATTRIBUTE_PACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createArtifact_in_Package(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::ASSOCIATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createAssociation(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Association has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createAssociation_in_Namespace(castedContainer,metaElementID);
					}
					//Association has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createAssociation_in_Owner(castedContainer,metaElementID);
					}
					//Association has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createAssociation_in_OwningPackage(castedContainer,metaElementID);
					}
					//Association has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createAssociation_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//Association has package as a containment
					case  UmlPackage::TYPE_ATTRIBUTE_PACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createAssociation_in_Package(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::ASSOCIATIONCLASS_CLASS:
		{
			if (nullptr == container)
			{
				return this->createAssociationClass(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//AssociationClass has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createAssociationClass_in_Namespace(castedContainer,metaElementID);
					}
					//AssociationClass has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createAssociationClass_in_Owner(castedContainer,metaElementID);
					}
					//AssociationClass has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createAssociationClass_in_OwningPackage(castedContainer,metaElementID);
					}
					//AssociationClass has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createAssociationClass_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//AssociationClass has package as a containment
					case  UmlPackage::TYPE_ATTRIBUTE_PACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createAssociationClass_in_Package(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::BEHAVIOREXECUTIONSPECIFICATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createBehaviorExecutionSpecification(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//BehaviorExecutionSpecification has enclosingInteraction as a containment
					case  UmlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGINTERACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Interaction>(container);
						return this->createBehaviorExecutionSpecification_in_EnclosingInteraction(castedContainer,metaElementID);
					}
					//BehaviorExecutionSpecification has enclosingOperand as a containment
					case  UmlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGOPERAND:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::InteractionOperand>(container);
						return this->createBehaviorExecutionSpecification_in_EnclosingOperand(castedContainer,metaElementID);
					}
					//BehaviorExecutionSpecification has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createBehaviorExecutionSpecification_in_Namespace(castedContainer,metaElementID);
					}
					//BehaviorExecutionSpecification has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createBehaviorExecutionSpecification_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::BROADCASTSIGNALACTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createBroadcastSignalAction(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//BroadcastSignalAction has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createBroadcastSignalAction_in_Activity(castedContainer,metaElementID);
					}
					//BroadcastSignalAction has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createBroadcastSignalAction_in_InStructuredNode(castedContainer,metaElementID);
					}
					//BroadcastSignalAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createBroadcastSignalAction_in_Namespace(castedContainer,metaElementID);
					}
					//BroadcastSignalAction has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createBroadcastSignalAction_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::CALLBEHAVIORACTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCallBehaviorAction(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//CallBehaviorAction has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createCallBehaviorAction_in_Activity(castedContainer,metaElementID);
					}
					//CallBehaviorAction has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createCallBehaviorAction_in_InStructuredNode(castedContainer,metaElementID);
					}
					//CallBehaviorAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createCallBehaviorAction_in_Namespace(castedContainer,metaElementID);
					}
					//CallBehaviorAction has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createCallBehaviorAction_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::CALLEVENT_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCallEvent(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//CallEvent has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createCallEvent_in_Namespace(castedContainer,metaElementID);
					}
					//CallEvent has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createCallEvent_in_Owner(castedContainer,metaElementID);
					}
					//CallEvent has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createCallEvent_in_OwningPackage(castedContainer,metaElementID);
					}
					//CallEvent has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createCallEvent_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::CALLOPERATIONACTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCallOperationAction(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//CallOperationAction has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createCallOperationAction_in_Activity(castedContainer,metaElementID);
					}
					//CallOperationAction has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createCallOperationAction_in_InStructuredNode(castedContainer,metaElementID);
					}
					//CallOperationAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createCallOperationAction_in_Namespace(castedContainer,metaElementID);
					}
					//CallOperationAction has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createCallOperationAction_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::CENTRALBUFFERNODE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCentralBufferNode(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//CentralBufferNode has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createCentralBufferNode_in_Activity(castedContainer,metaElementID);
					}
					//CentralBufferNode has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createCentralBufferNode_in_InStructuredNode(castedContainer,metaElementID);
					}
					//CentralBufferNode has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createCentralBufferNode_in_Namespace(castedContainer,metaElementID);
					}
					//CentralBufferNode has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createCentralBufferNode_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::CHANGEEVENT_CLASS:
		{
			if (nullptr == container)
			{
				return this->createChangeEvent(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ChangeEvent has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createChangeEvent_in_Namespace(castedContainer,metaElementID);
					}
					//ChangeEvent has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createChangeEvent_in_Owner(castedContainer,metaElementID);
					}
					//ChangeEvent has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createChangeEvent_in_OwningPackage(castedContainer,metaElementID);
					}
					//ChangeEvent has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createChangeEvent_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::CLASS_CLASS:
		{
			if (nullptr == container)
			{
				return this->createClass(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Class has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createClass_in_Namespace(castedContainer,metaElementID);
					}
					//Class has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createClass_in_Owner(castedContainer,metaElementID);
					}
					//Class has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createClass_in_OwningPackage(castedContainer,metaElementID);
					}
					//Class has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createClass_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//Class has package as a containment
					case  UmlPackage::TYPE_ATTRIBUTE_PACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createClass_in_Package(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::CLASSIFIERTEMPLATEPARAMETER_CLASS:
		{
			if (nullptr == container)
			{
				return this->createClassifierTemplateParameter(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ClassifierTemplateParameter has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createClassifierTemplateParameter_in_Owner(castedContainer,metaElementID);
					}
					//ClassifierTemplateParameter has signature as a containment
					case  UmlPackage::TEMPLATEPARAMETER_ATTRIBUTE_SIGNATURE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateSignature>(container);
						return this->createClassifierTemplateParameter_in_Signature(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::CLAUSE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createClause(metaElementID);
			}
			else
			{
				std::shared_ptr<uml::Element> castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
				assert(castedContainer);
				return std::shared_ptr<uml::Clause>(this->createClause_in_Owner(castedContainer,metaElementID));
			}
		}
		case UmlPackage::CLEARASSOCIATIONACTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createClearAssociationAction(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ClearAssociationAction has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createClearAssociationAction_in_Activity(castedContainer,metaElementID);
					}
					//ClearAssociationAction has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createClearAssociationAction_in_InStructuredNode(castedContainer,metaElementID);
					}
					//ClearAssociationAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createClearAssociationAction_in_Namespace(castedContainer,metaElementID);
					}
					//ClearAssociationAction has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createClearAssociationAction_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::CLEARSTRUCTURALFEATUREACTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createClearStructuralFeatureAction(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ClearStructuralFeatureAction has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createClearStructuralFeatureAction_in_Activity(castedContainer,metaElementID);
					}
					//ClearStructuralFeatureAction has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createClearStructuralFeatureAction_in_InStructuredNode(castedContainer,metaElementID);
					}
					//ClearStructuralFeatureAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createClearStructuralFeatureAction_in_Namespace(castedContainer,metaElementID);
					}
					//ClearStructuralFeatureAction has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createClearStructuralFeatureAction_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::CLEARVARIABLEACTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createClearVariableAction(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ClearVariableAction has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createClearVariableAction_in_Activity(castedContainer,metaElementID);
					}
					//ClearVariableAction has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createClearVariableAction_in_InStructuredNode(castedContainer,metaElementID);
					}
					//ClearVariableAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createClearVariableAction_in_Namespace(castedContainer,metaElementID);
					}
					//ClearVariableAction has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createClearVariableAction_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::COLLABORATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCollaboration(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Collaboration has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createCollaboration_in_Namespace(castedContainer,metaElementID);
					}
					//Collaboration has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createCollaboration_in_Owner(castedContainer,metaElementID);
					}
					//Collaboration has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createCollaboration_in_OwningPackage(castedContainer,metaElementID);
					}
					//Collaboration has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createCollaboration_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//Collaboration has package as a containment
					case  UmlPackage::TYPE_ATTRIBUTE_PACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createCollaboration_in_Package(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::COLLABORATIONUSE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCollaborationUse(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//CollaborationUse has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createCollaborationUse_in_Namespace(castedContainer,metaElementID);
					}
					//CollaborationUse has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createCollaborationUse_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::COMBINEDFRAGMENT_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCombinedFragment(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//CombinedFragment has enclosingInteraction as a containment
					case  UmlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGINTERACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Interaction>(container);
						return this->createCombinedFragment_in_EnclosingInteraction(castedContainer,metaElementID);
					}
					//CombinedFragment has enclosingOperand as a containment
					case  UmlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGOPERAND:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::InteractionOperand>(container);
						return this->createCombinedFragment_in_EnclosingOperand(castedContainer,metaElementID);
					}
					//CombinedFragment has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createCombinedFragment_in_Namespace(castedContainer,metaElementID);
					}
					//CombinedFragment has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createCombinedFragment_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::COMMENT_CLASS:
		{
			if (nullptr == container)
			{
				return this->createComment(metaElementID);
			}
			else
			{
				std::shared_ptr<uml::Element> castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
				assert(castedContainer);
				return std::shared_ptr<uml::Comment>(this->createComment_in_Owner(castedContainer,metaElementID));
			}
		}
		case UmlPackage::COMMUNICATIONPATH_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCommunicationPath(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//CommunicationPath has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createCommunicationPath_in_Namespace(castedContainer,metaElementID);
					}
					//CommunicationPath has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createCommunicationPath_in_Owner(castedContainer,metaElementID);
					}
					//CommunicationPath has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createCommunicationPath_in_OwningPackage(castedContainer,metaElementID);
					}
					//CommunicationPath has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createCommunicationPath_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//CommunicationPath has package as a containment
					case  UmlPackage::TYPE_ATTRIBUTE_PACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createCommunicationPath_in_Package(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::COMPONENT_CLASS:
		{
			if (nullptr == container)
			{
				return this->createComponent(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Component has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createComponent_in_Namespace(castedContainer,metaElementID);
					}
					//Component has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createComponent_in_Owner(castedContainer,metaElementID);
					}
					//Component has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createComponent_in_OwningPackage(castedContainer,metaElementID);
					}
					//Component has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createComponent_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//Component has package as a containment
					case  UmlPackage::TYPE_ATTRIBUTE_PACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createComponent_in_Package(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::COMPONENTREALIZATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createComponentRealization(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ComponentRealization has abstraction as a containment
					case  UmlPackage::COMPONENTREALIZATION_ATTRIBUTE_ABSTRACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Component>(container);
						return this->createComponentRealization_in_Abstraction(castedContainer,metaElementID);
					}
					//ComponentRealization has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createComponentRealization_in_Namespace(castedContainer,metaElementID);
					}
					//ComponentRealization has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createComponentRealization_in_Owner(castedContainer,metaElementID);
					}
					//ComponentRealization has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createComponentRealization_in_OwningPackage(castedContainer,metaElementID);
					}
					//ComponentRealization has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createComponentRealization_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::CONDITIONALNODE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createConditionalNode(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ConditionalNode has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createConditionalNode_in_Activity(castedContainer,metaElementID);
					}
					//ConditionalNode has inActivity as a containment
					case  UmlPackage::ACTIVITYGROUP_ATTRIBUTE_INACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createConditionalNode_in_InActivity(castedContainer,metaElementID);
					}
					//ConditionalNode has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createConditionalNode_in_InStructuredNode(castedContainer,metaElementID);
					}
					//ConditionalNode has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createConditionalNode_in_Namespace(castedContainer,metaElementID);
					}
					//ConditionalNode has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createConditionalNode_in_Owner(castedContainer,metaElementID);
					}
					//ConditionalNode has superGroup as a containment
					case  UmlPackage::ACTIVITYGROUP_ATTRIBUTE_SUPERGROUP:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::ActivityGroup>(container);
						return this->createConditionalNode_in_SuperGroup(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::CONNECTABLEELEMENTTEMPLATEPARAMETER_CLASS:
		{
			if (nullptr == container)
			{
				return this->createConnectableElementTemplateParameter(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ConnectableElementTemplateParameter has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createConnectableElementTemplateParameter_in_Owner(castedContainer,metaElementID);
					}
					//ConnectableElementTemplateParameter has signature as a containment
					case  UmlPackage::TEMPLATEPARAMETER_ATTRIBUTE_SIGNATURE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateSignature>(container);
						return this->createConnectableElementTemplateParameter_in_Signature(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::CONNECTIONPOINTREFERENCE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createConnectionPointReference(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ConnectionPointReference has container as a containment
					case  UmlPackage::VERTEX_ATTRIBUTE_CONTAINER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Region>(container);
						return this->createConnectionPointReference_in_Container(castedContainer,metaElementID);
					}
					//ConnectionPointReference has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createConnectionPointReference_in_Namespace(castedContainer,metaElementID);
					}
					//ConnectionPointReference has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createConnectionPointReference_in_Owner(castedContainer,metaElementID);
					}
					//ConnectionPointReference has state as a containment
					case  UmlPackage::CONNECTIONPOINTREFERENCE_ATTRIBUTE_STATE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::State>(container);
						return this->createConnectionPointReference_in_State(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::CONNECTOR_CLASS:
		{
			if (nullptr == container)
			{
				return this->createConnector(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Connector has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createConnector_in_Namespace(castedContainer,metaElementID);
					}
					//Connector has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createConnector_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::CONNECTOREND_CLASS:
		{
			if (nullptr == container)
			{
				return this->createConnectorEnd(metaElementID);
			}
			else
			{
				std::shared_ptr<uml::Element> castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
				assert(castedContainer);
				return std::shared_ptr<uml::ConnectorEnd>(this->createConnectorEnd_in_Owner(castedContainer,metaElementID));
			}
		}
		case UmlPackage::CONSIDERIGNOREFRAGMENT_CLASS:
		{
			if (nullptr == container)
			{
				return this->createConsiderIgnoreFragment(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ConsiderIgnoreFragment has enclosingInteraction as a containment
					case  UmlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGINTERACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Interaction>(container);
						return this->createConsiderIgnoreFragment_in_EnclosingInteraction(castedContainer,metaElementID);
					}
					//ConsiderIgnoreFragment has enclosingOperand as a containment
					case  UmlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGOPERAND:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::InteractionOperand>(container);
						return this->createConsiderIgnoreFragment_in_EnclosingOperand(castedContainer,metaElementID);
					}
					//ConsiderIgnoreFragment has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createConsiderIgnoreFragment_in_Namespace(castedContainer,metaElementID);
					}
					//ConsiderIgnoreFragment has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createConsiderIgnoreFragment_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::CONSTRAINT_CLASS:
		{
			if (nullptr == container)
			{
				return this->createConstraint(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Constraint has context as a containment
					case  UmlPackage::CONSTRAINT_ATTRIBUTE_CONTEXT:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createConstraint_in_Context(castedContainer,metaElementID);
					}
					//Constraint has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createConstraint_in_Namespace(castedContainer,metaElementID);
					}
					//Constraint has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createConstraint_in_Owner(castedContainer,metaElementID);
					}
					//Constraint has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createConstraint_in_OwningPackage(castedContainer,metaElementID);
					}
					//Constraint has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createConstraint_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::CONTINUATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createContinuation(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Continuation has enclosingInteraction as a containment
					case  UmlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGINTERACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Interaction>(container);
						return this->createContinuation_in_EnclosingInteraction(castedContainer,metaElementID);
					}
					//Continuation has enclosingOperand as a containment
					case  UmlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGOPERAND:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::InteractionOperand>(container);
						return this->createContinuation_in_EnclosingOperand(castedContainer,metaElementID);
					}
					//Continuation has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createContinuation_in_Namespace(castedContainer,metaElementID);
					}
					//Continuation has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createContinuation_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::CONTROLFLOW_CLASS:
		{
			if (nullptr == container)
			{
				return this->createControlFlow(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ControlFlow has activity as a containment
					case  UmlPackage::ACTIVITYEDGE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createControlFlow_in_Activity(castedContainer,metaElementID);
					}
					//ControlFlow has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYEDGE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createControlFlow_in_InStructuredNode(castedContainer,metaElementID);
					}
					//ControlFlow has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createControlFlow_in_Namespace(castedContainer,metaElementID);
					}
					//ControlFlow has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createControlFlow_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::CREATELINKACTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCreateLinkAction(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//CreateLinkAction has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createCreateLinkAction_in_Activity(castedContainer,metaElementID);
					}
					//CreateLinkAction has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createCreateLinkAction_in_InStructuredNode(castedContainer,metaElementID);
					}
					//CreateLinkAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createCreateLinkAction_in_Namespace(castedContainer,metaElementID);
					}
					//CreateLinkAction has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createCreateLinkAction_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::CREATELINKOBJECTACTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCreateLinkObjectAction(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//CreateLinkObjectAction has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createCreateLinkObjectAction_in_Activity(castedContainer,metaElementID);
					}
					//CreateLinkObjectAction has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createCreateLinkObjectAction_in_InStructuredNode(castedContainer,metaElementID);
					}
					//CreateLinkObjectAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createCreateLinkObjectAction_in_Namespace(castedContainer,metaElementID);
					}
					//CreateLinkObjectAction has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createCreateLinkObjectAction_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::CREATEOBJECTACTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createCreateObjectAction(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//CreateObjectAction has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createCreateObjectAction_in_Activity(castedContainer,metaElementID);
					}
					//CreateObjectAction has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createCreateObjectAction_in_InStructuredNode(castedContainer,metaElementID);
					}
					//CreateObjectAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createCreateObjectAction_in_Namespace(castedContainer,metaElementID);
					}
					//CreateObjectAction has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createCreateObjectAction_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::DATASTORENODE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createDataStoreNode(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//DataStoreNode has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createDataStoreNode_in_Activity(castedContainer,metaElementID);
					}
					//DataStoreNode has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createDataStoreNode_in_InStructuredNode(castedContainer,metaElementID);
					}
					//DataStoreNode has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createDataStoreNode_in_Namespace(castedContainer,metaElementID);
					}
					//DataStoreNode has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createDataStoreNode_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::DATATYPE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createDataType(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//DataType has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createDataType_in_Namespace(castedContainer,metaElementID);
					}
					//DataType has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createDataType_in_Owner(castedContainer,metaElementID);
					}
					//DataType has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createDataType_in_OwningPackage(castedContainer,metaElementID);
					}
					//DataType has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createDataType_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//DataType has package as a containment
					case  UmlPackage::TYPE_ATTRIBUTE_PACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createDataType_in_Package(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::DECISIONNODE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createDecisionNode(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//DecisionNode has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createDecisionNode_in_Activity(castedContainer,metaElementID);
					}
					//DecisionNode has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createDecisionNode_in_InStructuredNode(castedContainer,metaElementID);
					}
					//DecisionNode has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createDecisionNode_in_Namespace(castedContainer,metaElementID);
					}
					//DecisionNode has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createDecisionNode_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::DEPENDENCY_CLASS:
		{
			if (nullptr == container)
			{
				return this->createDependency(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Dependency has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createDependency_in_Namespace(castedContainer,metaElementID);
					}
					//Dependency has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createDependency_in_Owner(castedContainer,metaElementID);
					}
					//Dependency has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createDependency_in_OwningPackage(castedContainer,metaElementID);
					}
					//Dependency has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createDependency_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::DEPLOYMENT_CLASS:
		{
			if (nullptr == container)
			{
				return this->createDeployment(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Deployment has location as a containment
					case  UmlPackage::DEPLOYMENT_ATTRIBUTE_LOCATION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::DeploymentTarget>(container);
						return this->createDeployment_in_Location(castedContainer,metaElementID);
					}
					//Deployment has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createDeployment_in_Namespace(castedContainer,metaElementID);
					}
					//Deployment has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createDeployment_in_Owner(castedContainer,metaElementID);
					}
					//Deployment has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createDeployment_in_OwningPackage(castedContainer,metaElementID);
					}
					//Deployment has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createDeployment_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::DEPLOYMENTSPECIFICATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createDeploymentSpecification(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//DeploymentSpecification has deployment as a containment
					case  UmlPackage::DEPLOYMENTSPECIFICATION_ATTRIBUTE_DEPLOYMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Deployment>(container);
						return this->createDeploymentSpecification_in_Deployment(castedContainer,metaElementID);
					}
					//DeploymentSpecification has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createDeploymentSpecification_in_Namespace(castedContainer,metaElementID);
					}
					//DeploymentSpecification has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createDeploymentSpecification_in_Owner(castedContainer,metaElementID);
					}
					//DeploymentSpecification has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createDeploymentSpecification_in_OwningPackage(castedContainer,metaElementID);
					}
					//DeploymentSpecification has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createDeploymentSpecification_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//DeploymentSpecification has package as a containment
					case  UmlPackage::TYPE_ATTRIBUTE_PACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createDeploymentSpecification_in_Package(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::DESTROYLINKACTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createDestroyLinkAction(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//DestroyLinkAction has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createDestroyLinkAction_in_Activity(castedContainer,metaElementID);
					}
					//DestroyLinkAction has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createDestroyLinkAction_in_InStructuredNode(castedContainer,metaElementID);
					}
					//DestroyLinkAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createDestroyLinkAction_in_Namespace(castedContainer,metaElementID);
					}
					//DestroyLinkAction has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createDestroyLinkAction_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::DESTROYOBJECTACTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createDestroyObjectAction(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//DestroyObjectAction has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createDestroyObjectAction_in_Activity(castedContainer,metaElementID);
					}
					//DestroyObjectAction has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createDestroyObjectAction_in_InStructuredNode(castedContainer,metaElementID);
					}
					//DestroyObjectAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createDestroyObjectAction_in_Namespace(castedContainer,metaElementID);
					}
					//DestroyObjectAction has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createDestroyObjectAction_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::DESTRUCTIONOCCURRENCESPECIFICATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createDestructionOccurrenceSpecification(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//DestructionOccurrenceSpecification has enclosingInteraction as a containment
					case  UmlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGINTERACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Interaction>(container);
						return this->createDestructionOccurrenceSpecification_in_EnclosingInteraction(castedContainer,metaElementID);
					}
					//DestructionOccurrenceSpecification has enclosingOperand as a containment
					case  UmlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGOPERAND:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::InteractionOperand>(container);
						return this->createDestructionOccurrenceSpecification_in_EnclosingOperand(castedContainer,metaElementID);
					}
					//DestructionOccurrenceSpecification has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createDestructionOccurrenceSpecification_in_Namespace(castedContainer,metaElementID);
					}
					//DestructionOccurrenceSpecification has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createDestructionOccurrenceSpecification_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::DEVICE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createDevice(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Device has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createDevice_in_Namespace(castedContainer,metaElementID);
					}
					//Device has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createDevice_in_Owner(castedContainer,metaElementID);
					}
					//Device has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createDevice_in_OwningPackage(castedContainer,metaElementID);
					}
					//Device has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createDevice_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//Device has package as a containment
					case  UmlPackage::TYPE_ATTRIBUTE_PACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createDevice_in_Package(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::DURATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createDuration(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Duration has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createDuration_in_Namespace(castedContainer,metaElementID);
					}
					//Duration has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createDuration_in_Owner(castedContainer,metaElementID);
					}
					//Duration has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createDuration_in_OwningPackage(castedContainer,metaElementID);
					}
					//Duration has owningSlot as a containment
					case  UmlPackage::VALUESPECIFICATION_ATTRIBUTE_OWNINGSLOT:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Slot>(container);
						return this->createDuration_in_OwningSlot(castedContainer,metaElementID);
					}
					//Duration has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createDuration_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//Duration has valueSpecificationAction as a containment
					case  UmlPackage::VALUESPECIFICATION_ATTRIBUTE_VALUESPECIFICATIONACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::ValueSpecificationAction>(container);
						return this->createDuration_in_ValueSpecificationAction(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::DURATIONCONSTRAINT_CLASS:
		{
			if (nullptr == container)
			{
				return this->createDurationConstraint(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//DurationConstraint has context as a containment
					case  UmlPackage::CONSTRAINT_ATTRIBUTE_CONTEXT:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createDurationConstraint_in_Context(castedContainer,metaElementID);
					}
					//DurationConstraint has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createDurationConstraint_in_Namespace(castedContainer,metaElementID);
					}
					//DurationConstraint has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createDurationConstraint_in_Owner(castedContainer,metaElementID);
					}
					//DurationConstraint has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createDurationConstraint_in_OwningPackage(castedContainer,metaElementID);
					}
					//DurationConstraint has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createDurationConstraint_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::DURATIONINTERVAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createDurationInterval(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//DurationInterval has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createDurationInterval_in_Namespace(castedContainer,metaElementID);
					}
					//DurationInterval has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createDurationInterval_in_Owner(castedContainer,metaElementID);
					}
					//DurationInterval has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createDurationInterval_in_OwningPackage(castedContainer,metaElementID);
					}
					//DurationInterval has owningSlot as a containment
					case  UmlPackage::VALUESPECIFICATION_ATTRIBUTE_OWNINGSLOT:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Slot>(container);
						return this->createDurationInterval_in_OwningSlot(castedContainer,metaElementID);
					}
					//DurationInterval has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createDurationInterval_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//DurationInterval has valueSpecificationAction as a containment
					case  UmlPackage::VALUESPECIFICATION_ATTRIBUTE_VALUESPECIFICATIONACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::ValueSpecificationAction>(container);
						return this->createDurationInterval_in_ValueSpecificationAction(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::DURATIONOBSERVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createDurationObservation(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//DurationObservation has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createDurationObservation_in_Namespace(castedContainer,metaElementID);
					}
					//DurationObservation has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createDurationObservation_in_Owner(castedContainer,metaElementID);
					}
					//DurationObservation has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createDurationObservation_in_OwningPackage(castedContainer,metaElementID);
					}
					//DurationObservation has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createDurationObservation_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::ELEMENTIMPORT_CLASS:
		{
			if (nullptr == container)
			{
				return this->createElementImport(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ElementImport has importingNamespace as a containment
					case  UmlPackage::ELEMENTIMPORT_ATTRIBUTE_IMPORTINGNAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createElementImport_in_ImportingNamespace(castedContainer,metaElementID);
					}
					//ElementImport has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createElementImport_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::ENUMERATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createEnumeration(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Enumeration has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createEnumeration_in_Namespace(castedContainer,metaElementID);
					}
					//Enumeration has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createEnumeration_in_Owner(castedContainer,metaElementID);
					}
					//Enumeration has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createEnumeration_in_OwningPackage(castedContainer,metaElementID);
					}
					//Enumeration has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createEnumeration_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//Enumeration has package as a containment
					case  UmlPackage::TYPE_ATTRIBUTE_PACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createEnumeration_in_Package(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::ENUMERATIONLITERAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createEnumerationLiteral(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//EnumerationLiteral has enumeration as a containment
					case  UmlPackage::ENUMERATIONLITERAL_ATTRIBUTE_ENUMERATION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Enumeration>(container);
						return this->createEnumerationLiteral_in_Enumeration(castedContainer,metaElementID);
					}
					//EnumerationLiteral has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createEnumerationLiteral_in_Namespace(castedContainer,metaElementID);
					}
					//EnumerationLiteral has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createEnumerationLiteral_in_Owner(castedContainer,metaElementID);
					}
					//EnumerationLiteral has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createEnumerationLiteral_in_OwningPackage(castedContainer,metaElementID);
					}
					//EnumerationLiteral has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createEnumerationLiteral_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::EXCEPTIONHANDLER_CLASS:
		{
			if (nullptr == container)
			{
				return this->createExceptionHandler(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ExceptionHandler has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createExceptionHandler_in_Owner(castedContainer,metaElementID);
					}
					//ExceptionHandler has protectedNode as a containment
					case  UmlPackage::EXCEPTIONHANDLER_ATTRIBUTE_PROTECTEDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::ExecutableNode>(container);
						return this->createExceptionHandler_in_ProtectedNode(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::EXECUTIONENVIRONMENT_CLASS:
		{
			if (nullptr == container)
			{
				return this->createExecutionEnvironment(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ExecutionEnvironment has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createExecutionEnvironment_in_Namespace(castedContainer,metaElementID);
					}
					//ExecutionEnvironment has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createExecutionEnvironment_in_Owner(castedContainer,metaElementID);
					}
					//ExecutionEnvironment has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createExecutionEnvironment_in_OwningPackage(castedContainer,metaElementID);
					}
					//ExecutionEnvironment has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createExecutionEnvironment_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//ExecutionEnvironment has package as a containment
					case  UmlPackage::TYPE_ATTRIBUTE_PACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createExecutionEnvironment_in_Package(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::EXECUTIONOCCURRENCESPECIFICATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createExecutionOccurrenceSpecification(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ExecutionOccurrenceSpecification has enclosingInteraction as a containment
					case  UmlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGINTERACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Interaction>(container);
						return this->createExecutionOccurrenceSpecification_in_EnclosingInteraction(castedContainer,metaElementID);
					}
					//ExecutionOccurrenceSpecification has enclosingOperand as a containment
					case  UmlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGOPERAND:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::InteractionOperand>(container);
						return this->createExecutionOccurrenceSpecification_in_EnclosingOperand(castedContainer,metaElementID);
					}
					//ExecutionOccurrenceSpecification has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createExecutionOccurrenceSpecification_in_Namespace(castedContainer,metaElementID);
					}
					//ExecutionOccurrenceSpecification has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createExecutionOccurrenceSpecification_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::EXPANSIONNODE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createExpansionNode(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ExpansionNode has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createExpansionNode_in_Activity(castedContainer,metaElementID);
					}
					//ExpansionNode has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createExpansionNode_in_InStructuredNode(castedContainer,metaElementID);
					}
					//ExpansionNode has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createExpansionNode_in_Namespace(castedContainer,metaElementID);
					}
					//ExpansionNode has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createExpansionNode_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::EXPANSIONREGION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createExpansionRegion(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ExpansionRegion has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createExpansionRegion_in_Activity(castedContainer,metaElementID);
					}
					//ExpansionRegion has inActivity as a containment
					case  UmlPackage::ACTIVITYGROUP_ATTRIBUTE_INACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createExpansionRegion_in_InActivity(castedContainer,metaElementID);
					}
					//ExpansionRegion has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createExpansionRegion_in_InStructuredNode(castedContainer,metaElementID);
					}
					//ExpansionRegion has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createExpansionRegion_in_Namespace(castedContainer,metaElementID);
					}
					//ExpansionRegion has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createExpansionRegion_in_Owner(castedContainer,metaElementID);
					}
					//ExpansionRegion has superGroup as a containment
					case  UmlPackage::ACTIVITYGROUP_ATTRIBUTE_SUPERGROUP:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::ActivityGroup>(container);
						return this->createExpansionRegion_in_SuperGroup(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::EXPRESSION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createExpression(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Expression has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createExpression_in_Namespace(castedContainer,metaElementID);
					}
					//Expression has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createExpression_in_Owner(castedContainer,metaElementID);
					}
					//Expression has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createExpression_in_OwningPackage(castedContainer,metaElementID);
					}
					//Expression has owningSlot as a containment
					case  UmlPackage::VALUESPECIFICATION_ATTRIBUTE_OWNINGSLOT:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Slot>(container);
						return this->createExpression_in_OwningSlot(castedContainer,metaElementID);
					}
					//Expression has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createExpression_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//Expression has valueSpecificationAction as a containment
					case  UmlPackage::VALUESPECIFICATION_ATTRIBUTE_VALUESPECIFICATIONACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::ValueSpecificationAction>(container);
						return this->createExpression_in_ValueSpecificationAction(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::EXTEND_CLASS:
		{
			if (nullptr == container)
			{
				return this->createExtend(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Extend has extension as a containment
					case  UmlPackage::EXTEND_ATTRIBUTE_EXTENSION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::UseCase>(container);
						return this->createExtend_in_Extension(castedContainer,metaElementID);
					}
					//Extend has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createExtend_in_Namespace(castedContainer,metaElementID);
					}
					//Extend has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createExtend_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::EXTENSION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createExtension(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Extension has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createExtension_in_Namespace(castedContainer,metaElementID);
					}
					//Extension has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createExtension_in_Owner(castedContainer,metaElementID);
					}
					//Extension has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createExtension_in_OwningPackage(castedContainer,metaElementID);
					}
					//Extension has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createExtension_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//Extension has package as a containment
					case  UmlPackage::TYPE_ATTRIBUTE_PACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createExtension_in_Package(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::EXTENSIONEND_CLASS:
		{
			if (nullptr == container)
			{
				return this->createExtensionEnd(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ExtensionEnd has associationEnd as a containment
					case  UmlPackage::PROPERTY_ATTRIBUTE_ASSOCIATIONEND:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Property>(container);
						return this->createExtensionEnd_in_AssociationEnd(castedContainer,metaElementID);
					}
					//ExtensionEnd has class as a containment
					case  UmlPackage::PROPERTY_ATTRIBUTE_CLASS:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Class>(container);
						return this->createExtensionEnd_in_Class(castedContainer,metaElementID);
					}
					//ExtensionEnd has datatype as a containment
					case  UmlPackage::PROPERTY_ATTRIBUTE_DATATYPE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::DataType>(container);
						return this->createExtensionEnd_in_Datatype(castedContainer,metaElementID);
					}
					//ExtensionEnd has interface as a containment
					case  UmlPackage::PROPERTY_ATTRIBUTE_INTERFACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Interface>(container);
						return this->createExtensionEnd_in_Interface(castedContainer,metaElementID);
					}
					//ExtensionEnd has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createExtensionEnd_in_Namespace(castedContainer,metaElementID);
					}
					//ExtensionEnd has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createExtensionEnd_in_Owner(castedContainer,metaElementID);
					}
					//ExtensionEnd has owningAssociation as a containment
					case  UmlPackage::PROPERTY_ATTRIBUTE_OWNINGASSOCIATION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Association>(container);
						return this->createExtensionEnd_in_OwningAssociation(castedContainer,metaElementID);
					}
					//ExtensionEnd has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createExtensionEnd_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::EXTENSIONPOINT_CLASS:
		{
			if (nullptr == container)
			{
				return this->createExtensionPoint(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ExtensionPoint has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createExtensionPoint_in_Namespace(castedContainer,metaElementID);
					}
					//ExtensionPoint has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createExtensionPoint_in_Owner(castedContainer,metaElementID);
					}
					//ExtensionPoint has useCase as a containment
					case  UmlPackage::EXTENSIONPOINT_ATTRIBUTE_USECASE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::UseCase>(container);
						return this->createExtensionPoint_in_UseCase(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::FACTORY_CLASS:
		{
			if (nullptr == container)
			{
				return this->createFactory(metaElementID);
			}
			else
			{
				std::shared_ptr<uml::Element> castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
				assert(castedContainer);
				return std::shared_ptr<uml::Factory>(this->createFactory_in_Owner(castedContainer,metaElementID));
			}
		}
		case UmlPackage::FINALSTATE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createFinalState(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//FinalState has container as a containment
					case  UmlPackage::VERTEX_ATTRIBUTE_CONTAINER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Region>(container);
						return this->createFinalState_in_Container(castedContainer,metaElementID);
					}
					//FinalState has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createFinalState_in_Namespace(castedContainer,metaElementID);
					}
					//FinalState has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createFinalState_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::FLOWFINALNODE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createFlowFinalNode(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//FlowFinalNode has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createFlowFinalNode_in_Activity(castedContainer,metaElementID);
					}
					//FlowFinalNode has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createFlowFinalNode_in_InStructuredNode(castedContainer,metaElementID);
					}
					//FlowFinalNode has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createFlowFinalNode_in_Namespace(castedContainer,metaElementID);
					}
					//FlowFinalNode has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createFlowFinalNode_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::FORKNODE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createForkNode(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ForkNode has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createForkNode_in_Activity(castedContainer,metaElementID);
					}
					//ForkNode has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createForkNode_in_InStructuredNode(castedContainer,metaElementID);
					}
					//ForkNode has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createForkNode_in_Namespace(castedContainer,metaElementID);
					}
					//ForkNode has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createForkNode_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::FUNCTIONBEHAVIOR_CLASS:
		{
			if (nullptr == container)
			{
				return this->createFunctionBehavior(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//FunctionBehavior has behavioredClassifier as a containment
					case  UmlPackage::BEHAVIOR_ATTRIBUTE_BEHAVIOREDCLASSIFIER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::BehavioredClassifier>(container);
						return this->createFunctionBehavior_in_BehavioredClassifier(castedContainer,metaElementID);
					}
					//FunctionBehavior has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createFunctionBehavior_in_Namespace(castedContainer,metaElementID);
					}
					//FunctionBehavior has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createFunctionBehavior_in_Owner(castedContainer,metaElementID);
					}
					//FunctionBehavior has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createFunctionBehavior_in_OwningPackage(castedContainer,metaElementID);
					}
					//FunctionBehavior has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createFunctionBehavior_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//FunctionBehavior has package as a containment
					case  UmlPackage::TYPE_ATTRIBUTE_PACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createFunctionBehavior_in_Package(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::GATE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createGate(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Gate has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createGate_in_Namespace(castedContainer,metaElementID);
					}
					//Gate has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createGate_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::GENERALORDERING_CLASS:
		{
			if (nullptr == container)
			{
				return this->createGeneralOrdering(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//GeneralOrdering has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createGeneralOrdering_in_Namespace(castedContainer,metaElementID);
					}
					//GeneralOrdering has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createGeneralOrdering_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::GENERALIZATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createGeneralization(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Generalization has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createGeneralization_in_Owner(castedContainer,metaElementID);
					}
					//Generalization has specific as a containment
					case  UmlPackage::GENERALIZATION_ATTRIBUTE_SPECIFIC:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Classifier>(container);
						return this->createGeneralization_in_Specific(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::GENERALIZATIONSET_CLASS:
		{
			if (nullptr == container)
			{
				return this->createGeneralizationSet(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//GeneralizationSet has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createGeneralizationSet_in_Namespace(castedContainer,metaElementID);
					}
					//GeneralizationSet has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createGeneralizationSet_in_Owner(castedContainer,metaElementID);
					}
					//GeneralizationSet has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createGeneralizationSet_in_OwningPackage(castedContainer,metaElementID);
					}
					//GeneralizationSet has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createGeneralizationSet_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::IMAGE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createImage(metaElementID);
			}
			else
			{
				std::shared_ptr<uml::Element> castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
				assert(castedContainer);
				return std::shared_ptr<uml::Image>(this->createImage_in_Owner(castedContainer,metaElementID));
			}
		}
		case UmlPackage::INCLUDE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createInclude(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Include has includingCase as a containment
					case  UmlPackage::INCLUDE_ATTRIBUTE_INCLUDINGCASE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::UseCase>(container);
						return this->createInclude_in_IncludingCase(castedContainer,metaElementID);
					}
					//Include has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createInclude_in_Namespace(castedContainer,metaElementID);
					}
					//Include has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createInclude_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::INFORMATIONFLOW_CLASS:
		{
			if (nullptr == container)
			{
				return this->createInformationFlow(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//InformationFlow has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createInformationFlow_in_Namespace(castedContainer,metaElementID);
					}
					//InformationFlow has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createInformationFlow_in_Owner(castedContainer,metaElementID);
					}
					//InformationFlow has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createInformationFlow_in_OwningPackage(castedContainer,metaElementID);
					}
					//InformationFlow has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createInformationFlow_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::INFORMATIONITEM_CLASS:
		{
			if (nullptr == container)
			{
				return this->createInformationItem(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//InformationItem has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createInformationItem_in_Namespace(castedContainer,metaElementID);
					}
					//InformationItem has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createInformationItem_in_Owner(castedContainer,metaElementID);
					}
					//InformationItem has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createInformationItem_in_OwningPackage(castedContainer,metaElementID);
					}
					//InformationItem has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createInformationItem_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//InformationItem has package as a containment
					case  UmlPackage::TYPE_ATTRIBUTE_PACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createInformationItem_in_Package(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::INITIALNODE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createInitialNode(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//InitialNode has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createInitialNode_in_Activity(castedContainer,metaElementID);
					}
					//InitialNode has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createInitialNode_in_InStructuredNode(castedContainer,metaElementID);
					}
					//InitialNode has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createInitialNode_in_Namespace(castedContainer,metaElementID);
					}
					//InitialNode has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createInitialNode_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::INPUTPIN_CLASS:
		{
			if (nullptr == container)
			{
				return this->createInputPin(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//InputPin has action as a containment
					case  UmlPackage::INPUTPIN_ATTRIBUTE_ACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Action>(container);
						return this->createInputPin_in_Action(castedContainer,metaElementID);
					}
					//InputPin has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createInputPin_in_Activity(castedContainer,metaElementID);
					}
					//InputPin has addStructuralFeatureValueAction as a containment
					case  UmlPackage::INPUTPIN_ATTRIBUTE_ADDSTRUCTURALFEATUREVALUEACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::AddStructuralFeatureValueAction>(container);
						return this->createInputPin_in_AddStructuralFeatureValueAction(castedContainer,metaElementID);
					}
					//InputPin has callOperationAction as a containment
					case  UmlPackage::INPUTPIN_ATTRIBUTE_CALLOPERATIONACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::CallOperationAction>(container);
						return this->createInputPin_in_CallOperationAction(castedContainer,metaElementID);
					}
					//InputPin has destroyObjectAction as a containment
					case  UmlPackage::INPUTPIN_ATTRIBUTE_DESTROYOBJECTACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::DestroyObjectAction>(container);
						return this->createInputPin_in_DestroyObjectAction(castedContainer,metaElementID);
					}
					//InputPin has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createInputPin_in_InStructuredNode(castedContainer,metaElementID);
					}
					//InputPin has invocationAction as a containment
					case  UmlPackage::INPUTPIN_ATTRIBUTE_INVOCATIONACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::InvocationAction>(container);
						return this->createInputPin_in_InvocationAction(castedContainer,metaElementID);
					}
					//InputPin has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createInputPin_in_Namespace(castedContainer,metaElementID);
					}
					//InputPin has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createInputPin_in_Owner(castedContainer,metaElementID);
					}
					//InputPin has structuralFeatureAction as a containment
					case  UmlPackage::INPUTPIN_ATTRIBUTE_STRUCTURALFEATUREACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuralFeatureAction>(container);
						return this->createInputPin_in_StructuralFeatureAction(castedContainer,metaElementID);
					}
					//InputPin has writeStructuralFeatureAction as a containment
					case  UmlPackage::INPUTPIN_ATTRIBUTE_WRITESTRUCTURALFEATUREACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::WriteStructuralFeatureAction>(container);
						return this->createInputPin_in_WriteStructuralFeatureAction(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::INSTANCESPECIFICATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createInstanceSpecification(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//InstanceSpecification has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createInstanceSpecification_in_Namespace(castedContainer,metaElementID);
					}
					//InstanceSpecification has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createInstanceSpecification_in_Owner(castedContainer,metaElementID);
					}
					//InstanceSpecification has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createInstanceSpecification_in_OwningPackage(castedContainer,metaElementID);
					}
					//InstanceSpecification has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createInstanceSpecification_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::INSTANCEVALUE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createInstanceValue(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//InstanceValue has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createInstanceValue_in_Namespace(castedContainer,metaElementID);
					}
					//InstanceValue has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createInstanceValue_in_Owner(castedContainer,metaElementID);
					}
					//InstanceValue has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createInstanceValue_in_OwningPackage(castedContainer,metaElementID);
					}
					//InstanceValue has owningSlot as a containment
					case  UmlPackage::VALUESPECIFICATION_ATTRIBUTE_OWNINGSLOT:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Slot>(container);
						return this->createInstanceValue_in_OwningSlot(castedContainer,metaElementID);
					}
					//InstanceValue has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createInstanceValue_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//InstanceValue has valueSpecificationAction as a containment
					case  UmlPackage::VALUESPECIFICATION_ATTRIBUTE_VALUESPECIFICATIONACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::ValueSpecificationAction>(container);
						return this->createInstanceValue_in_ValueSpecificationAction(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::INTERACTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createInteraction(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Interaction has behavioredClassifier as a containment
					case  UmlPackage::BEHAVIOR_ATTRIBUTE_BEHAVIOREDCLASSIFIER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::BehavioredClassifier>(container);
						return this->createInteraction_in_BehavioredClassifier(castedContainer,metaElementID);
					}
					//Interaction has enclosingInteraction as a containment
					case  UmlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGINTERACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Interaction>(container);
						return this->createInteraction_in_EnclosingInteraction(castedContainer,metaElementID);
					}
					//Interaction has enclosingOperand as a containment
					case  UmlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGOPERAND:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::InteractionOperand>(container);
						return this->createInteraction_in_EnclosingOperand(castedContainer,metaElementID);
					}
					//Interaction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createInteraction_in_Namespace(castedContainer,metaElementID);
					}
					//Interaction has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createInteraction_in_Owner(castedContainer,metaElementID);
					}
					//Interaction has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createInteraction_in_OwningPackage(castedContainer,metaElementID);
					}
					//Interaction has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createInteraction_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//Interaction has package as a containment
					case  UmlPackage::TYPE_ATTRIBUTE_PACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createInteraction_in_Package(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::INTERACTIONCONSTRAINT_CLASS:
		{
			if (nullptr == container)
			{
				return this->createInteractionConstraint(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//InteractionConstraint has context as a containment
					case  UmlPackage::CONSTRAINT_ATTRIBUTE_CONTEXT:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createInteractionConstraint_in_Context(castedContainer,metaElementID);
					}
					//InteractionConstraint has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createInteractionConstraint_in_Namespace(castedContainer,metaElementID);
					}
					//InteractionConstraint has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createInteractionConstraint_in_Owner(castedContainer,metaElementID);
					}
					//InteractionConstraint has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createInteractionConstraint_in_OwningPackage(castedContainer,metaElementID);
					}
					//InteractionConstraint has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createInteractionConstraint_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::INTERACTIONOPERAND_CLASS:
		{
			if (nullptr == container)
			{
				return this->createInteractionOperand(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//InteractionOperand has enclosingInteraction as a containment
					case  UmlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGINTERACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Interaction>(container);
						return this->createInteractionOperand_in_EnclosingInteraction(castedContainer,metaElementID);
					}
					//InteractionOperand has enclosingOperand as a containment
					case  UmlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGOPERAND:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::InteractionOperand>(container);
						return this->createInteractionOperand_in_EnclosingOperand(castedContainer,metaElementID);
					}
					//InteractionOperand has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createInteractionOperand_in_Namespace(castedContainer,metaElementID);
					}
					//InteractionOperand has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createInteractionOperand_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::INTERACTIONUSE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createInteractionUse(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//InteractionUse has enclosingInteraction as a containment
					case  UmlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGINTERACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Interaction>(container);
						return this->createInteractionUse_in_EnclosingInteraction(castedContainer,metaElementID);
					}
					//InteractionUse has enclosingOperand as a containment
					case  UmlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGOPERAND:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::InteractionOperand>(container);
						return this->createInteractionUse_in_EnclosingOperand(castedContainer,metaElementID);
					}
					//InteractionUse has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createInteractionUse_in_Namespace(castedContainer,metaElementID);
					}
					//InteractionUse has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createInteractionUse_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::INTERFACE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createInterface(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Interface has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createInterface_in_Namespace(castedContainer,metaElementID);
					}
					//Interface has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createInterface_in_Owner(castedContainer,metaElementID);
					}
					//Interface has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createInterface_in_OwningPackage(castedContainer,metaElementID);
					}
					//Interface has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createInterface_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//Interface has package as a containment
					case  UmlPackage::TYPE_ATTRIBUTE_PACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createInterface_in_Package(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::INTERFACEREALIZATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createInterfaceRealization(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//InterfaceRealization has implementingClassifier as a containment
					case  UmlPackage::INTERFACEREALIZATION_ATTRIBUTE_IMPLEMENTINGCLASSIFIER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::BehavioredClassifier>(container);
						return this->createInterfaceRealization_in_ImplementingClassifier(castedContainer,metaElementID);
					}
					//InterfaceRealization has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createInterfaceRealization_in_Namespace(castedContainer,metaElementID);
					}
					//InterfaceRealization has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createInterfaceRealization_in_Owner(castedContainer,metaElementID);
					}
					//InterfaceRealization has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createInterfaceRealization_in_OwningPackage(castedContainer,metaElementID);
					}
					//InterfaceRealization has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createInterfaceRealization_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::INTERRUPTIBLEACTIVITYREGION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createInterruptibleActivityRegion(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//InterruptibleActivityRegion has inActivity as a containment
					case  UmlPackage::ACTIVITYGROUP_ATTRIBUTE_INACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createInterruptibleActivityRegion_in_InActivity(castedContainer,metaElementID);
					}
					//InterruptibleActivityRegion has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createInterruptibleActivityRegion_in_Namespace(castedContainer,metaElementID);
					}
					//InterruptibleActivityRegion has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createInterruptibleActivityRegion_in_Owner(castedContainer,metaElementID);
					}
					//InterruptibleActivityRegion has superGroup as a containment
					case  UmlPackage::ACTIVITYGROUP_ATTRIBUTE_SUPERGROUP:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::ActivityGroup>(container);
						return this->createInterruptibleActivityRegion_in_SuperGroup(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::INTERVAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createInterval(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Interval has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createInterval_in_Namespace(castedContainer,metaElementID);
					}
					//Interval has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createInterval_in_Owner(castedContainer,metaElementID);
					}
					//Interval has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createInterval_in_OwningPackage(castedContainer,metaElementID);
					}
					//Interval has owningSlot as a containment
					case  UmlPackage::VALUESPECIFICATION_ATTRIBUTE_OWNINGSLOT:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Slot>(container);
						return this->createInterval_in_OwningSlot(castedContainer,metaElementID);
					}
					//Interval has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createInterval_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//Interval has valueSpecificationAction as a containment
					case  UmlPackage::VALUESPECIFICATION_ATTRIBUTE_VALUESPECIFICATIONACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::ValueSpecificationAction>(container);
						return this->createInterval_in_ValueSpecificationAction(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::INTERVALCONSTRAINT_CLASS:
		{
			if (nullptr == container)
			{
				return this->createIntervalConstraint(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//IntervalConstraint has context as a containment
					case  UmlPackage::CONSTRAINT_ATTRIBUTE_CONTEXT:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createIntervalConstraint_in_Context(castedContainer,metaElementID);
					}
					//IntervalConstraint has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createIntervalConstraint_in_Namespace(castedContainer,metaElementID);
					}
					//IntervalConstraint has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createIntervalConstraint_in_Owner(castedContainer,metaElementID);
					}
					//IntervalConstraint has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createIntervalConstraint_in_OwningPackage(castedContainer,metaElementID);
					}
					//IntervalConstraint has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createIntervalConstraint_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::JOINNODE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createJoinNode(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//JoinNode has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createJoinNode_in_Activity(castedContainer,metaElementID);
					}
					//JoinNode has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createJoinNode_in_InStructuredNode(castedContainer,metaElementID);
					}
					//JoinNode has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createJoinNode_in_Namespace(castedContainer,metaElementID);
					}
					//JoinNode has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createJoinNode_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::LIFELINE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createLifeline(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Lifeline has interaction as a containment
					case  UmlPackage::LIFELINE_ATTRIBUTE_INTERACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Interaction>(container);
						return this->createLifeline_in_Interaction(castedContainer,metaElementID);
					}
					//Lifeline has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createLifeline_in_Namespace(castedContainer,metaElementID);
					}
					//Lifeline has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createLifeline_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::LINKENDCREATIONDATA_CLASS:
		{
			if (nullptr == container)
			{
				return this->createLinkEndCreationData(metaElementID);
			}
			else
			{
				std::shared_ptr<uml::Element> castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
				assert(castedContainer);
				return std::shared_ptr<uml::LinkEndCreationData>(this->createLinkEndCreationData_in_Owner(castedContainer,metaElementID));
			}
		}
		case UmlPackage::LINKENDDATA_CLASS:
		{
			if (nullptr == container)
			{
				return this->createLinkEndData(metaElementID);
			}
			else
			{
				std::shared_ptr<uml::Element> castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
				assert(castedContainer);
				return std::shared_ptr<uml::LinkEndData>(this->createLinkEndData_in_Owner(castedContainer,metaElementID));
			}
		}
		case UmlPackage::LINKENDDESTRUCTIONDATA_CLASS:
		{
			if (nullptr == container)
			{
				return this->createLinkEndDestructionData(metaElementID);
			}
			else
			{
				std::shared_ptr<uml::Element> castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
				assert(castedContainer);
				return std::shared_ptr<uml::LinkEndDestructionData>(this->createLinkEndDestructionData_in_Owner(castedContainer,metaElementID));
			}
		}
		case UmlPackage::LITERALBOOLEAN_CLASS:
		{
			if (nullptr == container)
			{
				return this->createLiteralBoolean(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//LiteralBoolean has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createLiteralBoolean_in_Namespace(castedContainer,metaElementID);
					}
					//LiteralBoolean has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createLiteralBoolean_in_Owner(castedContainer,metaElementID);
					}
					//LiteralBoolean has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createLiteralBoolean_in_OwningPackage(castedContainer,metaElementID);
					}
					//LiteralBoolean has owningSlot as a containment
					case  UmlPackage::VALUESPECIFICATION_ATTRIBUTE_OWNINGSLOT:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Slot>(container);
						return this->createLiteralBoolean_in_OwningSlot(castedContainer,metaElementID);
					}
					//LiteralBoolean has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createLiteralBoolean_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//LiteralBoolean has valueSpecificationAction as a containment
					case  UmlPackage::VALUESPECIFICATION_ATTRIBUTE_VALUESPECIFICATIONACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::ValueSpecificationAction>(container);
						return this->createLiteralBoolean_in_ValueSpecificationAction(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::LITERALINTEGER_CLASS:
		{
			if (nullptr == container)
			{
				return this->createLiteralInteger(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//LiteralInteger has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createLiteralInteger_in_Namespace(castedContainer,metaElementID);
					}
					//LiteralInteger has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createLiteralInteger_in_Owner(castedContainer,metaElementID);
					}
					//LiteralInteger has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createLiteralInteger_in_OwningPackage(castedContainer,metaElementID);
					}
					//LiteralInteger has owningSlot as a containment
					case  UmlPackage::VALUESPECIFICATION_ATTRIBUTE_OWNINGSLOT:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Slot>(container);
						return this->createLiteralInteger_in_OwningSlot(castedContainer,metaElementID);
					}
					//LiteralInteger has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createLiteralInteger_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//LiteralInteger has valueSpecificationAction as a containment
					case  UmlPackage::VALUESPECIFICATION_ATTRIBUTE_VALUESPECIFICATIONACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::ValueSpecificationAction>(container);
						return this->createLiteralInteger_in_ValueSpecificationAction(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::LITERALNULL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createLiteralNull(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//LiteralNull has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createLiteralNull_in_Namespace(castedContainer,metaElementID);
					}
					//LiteralNull has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createLiteralNull_in_Owner(castedContainer,metaElementID);
					}
					//LiteralNull has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createLiteralNull_in_OwningPackage(castedContainer,metaElementID);
					}
					//LiteralNull has owningSlot as a containment
					case  UmlPackage::VALUESPECIFICATION_ATTRIBUTE_OWNINGSLOT:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Slot>(container);
						return this->createLiteralNull_in_OwningSlot(castedContainer,metaElementID);
					}
					//LiteralNull has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createLiteralNull_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//LiteralNull has valueSpecificationAction as a containment
					case  UmlPackage::VALUESPECIFICATION_ATTRIBUTE_VALUESPECIFICATIONACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::ValueSpecificationAction>(container);
						return this->createLiteralNull_in_ValueSpecificationAction(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::LITERALREAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createLiteralReal(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//LiteralReal has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createLiteralReal_in_Namespace(castedContainer,metaElementID);
					}
					//LiteralReal has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createLiteralReal_in_Owner(castedContainer,metaElementID);
					}
					//LiteralReal has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createLiteralReal_in_OwningPackage(castedContainer,metaElementID);
					}
					//LiteralReal has owningSlot as a containment
					case  UmlPackage::VALUESPECIFICATION_ATTRIBUTE_OWNINGSLOT:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Slot>(container);
						return this->createLiteralReal_in_OwningSlot(castedContainer,metaElementID);
					}
					//LiteralReal has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createLiteralReal_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//LiteralReal has valueSpecificationAction as a containment
					case  UmlPackage::VALUESPECIFICATION_ATTRIBUTE_VALUESPECIFICATIONACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::ValueSpecificationAction>(container);
						return this->createLiteralReal_in_ValueSpecificationAction(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::LITERALSTRING_CLASS:
		{
			if (nullptr == container)
			{
				return this->createLiteralString(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//LiteralString has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createLiteralString_in_Namespace(castedContainer,metaElementID);
					}
					//LiteralString has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createLiteralString_in_Owner(castedContainer,metaElementID);
					}
					//LiteralString has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createLiteralString_in_OwningPackage(castedContainer,metaElementID);
					}
					//LiteralString has owningSlot as a containment
					case  UmlPackage::VALUESPECIFICATION_ATTRIBUTE_OWNINGSLOT:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Slot>(container);
						return this->createLiteralString_in_OwningSlot(castedContainer,metaElementID);
					}
					//LiteralString has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createLiteralString_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//LiteralString has valueSpecificationAction as a containment
					case  UmlPackage::VALUESPECIFICATION_ATTRIBUTE_VALUESPECIFICATIONACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::ValueSpecificationAction>(container);
						return this->createLiteralString_in_ValueSpecificationAction(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::LITERALUNLIMITEDNATURAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createLiteralUnlimitedNatural(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//LiteralUnlimitedNatural has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createLiteralUnlimitedNatural_in_Namespace(castedContainer,metaElementID);
					}
					//LiteralUnlimitedNatural has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createLiteralUnlimitedNatural_in_Owner(castedContainer,metaElementID);
					}
					//LiteralUnlimitedNatural has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createLiteralUnlimitedNatural_in_OwningPackage(castedContainer,metaElementID);
					}
					//LiteralUnlimitedNatural has owningSlot as a containment
					case  UmlPackage::VALUESPECIFICATION_ATTRIBUTE_OWNINGSLOT:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Slot>(container);
						return this->createLiteralUnlimitedNatural_in_OwningSlot(castedContainer,metaElementID);
					}
					//LiteralUnlimitedNatural has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createLiteralUnlimitedNatural_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//LiteralUnlimitedNatural has valueSpecificationAction as a containment
					case  UmlPackage::VALUESPECIFICATION_ATTRIBUTE_VALUESPECIFICATIONACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::ValueSpecificationAction>(container);
						return this->createLiteralUnlimitedNatural_in_ValueSpecificationAction(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::LOOPNODE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createLoopNode(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//LoopNode has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createLoopNode_in_Activity(castedContainer,metaElementID);
					}
					//LoopNode has inActivity as a containment
					case  UmlPackage::ACTIVITYGROUP_ATTRIBUTE_INACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createLoopNode_in_InActivity(castedContainer,metaElementID);
					}
					//LoopNode has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createLoopNode_in_InStructuredNode(castedContainer,metaElementID);
					}
					//LoopNode has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createLoopNode_in_Namespace(castedContainer,metaElementID);
					}
					//LoopNode has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createLoopNode_in_Owner(castedContainer,metaElementID);
					}
					//LoopNode has superGroup as a containment
					case  UmlPackage::ACTIVITYGROUP_ATTRIBUTE_SUPERGROUP:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::ActivityGroup>(container);
						return this->createLoopNode_in_SuperGroup(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::MANIFESTATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createManifestation(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Manifestation has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createManifestation_in_Namespace(castedContainer,metaElementID);
					}
					//Manifestation has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createManifestation_in_Owner(castedContainer,metaElementID);
					}
					//Manifestation has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createManifestation_in_OwningPackage(castedContainer,metaElementID);
					}
					//Manifestation has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createManifestation_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::MERGENODE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createMergeNode(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//MergeNode has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createMergeNode_in_Activity(castedContainer,metaElementID);
					}
					//MergeNode has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createMergeNode_in_InStructuredNode(castedContainer,metaElementID);
					}
					//MergeNode has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createMergeNode_in_Namespace(castedContainer,metaElementID);
					}
					//MergeNode has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createMergeNode_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::MESSAGE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createMessage(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Message has interaction as a containment
					case  UmlPackage::MESSAGE_ATTRIBUTE_INTERACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Interaction>(container);
						return this->createMessage_in_Interaction(castedContainer,metaElementID);
					}
					//Message has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createMessage_in_Namespace(castedContainer,metaElementID);
					}
					//Message has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createMessage_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::MESSAGEOCCURRENCESPECIFICATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createMessageOccurrenceSpecification(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//MessageOccurrenceSpecification has enclosingInteraction as a containment
					case  UmlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGINTERACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Interaction>(container);
						return this->createMessageOccurrenceSpecification_in_EnclosingInteraction(castedContainer,metaElementID);
					}
					//MessageOccurrenceSpecification has enclosingOperand as a containment
					case  UmlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGOPERAND:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::InteractionOperand>(container);
						return this->createMessageOccurrenceSpecification_in_EnclosingOperand(castedContainer,metaElementID);
					}
					//MessageOccurrenceSpecification has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createMessageOccurrenceSpecification_in_Namespace(castedContainer,metaElementID);
					}
					//MessageOccurrenceSpecification has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createMessageOccurrenceSpecification_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::MODEL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createModel(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Model has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createModel_in_Namespace(castedContainer,metaElementID);
					}
					//Model has nestingPackage as a containment
					case  UmlPackage::PACKAGE_ATTRIBUTE_NESTINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createModel_in_NestingPackage(castedContainer,metaElementID);
					}
					//Model has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createModel_in_Owner(castedContainer,metaElementID);
					}
					//Model has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createModel_in_OwningPackage(castedContainer,metaElementID);
					}
					//Model has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createModel_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::NODE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createNode(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Node has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createNode_in_Namespace(castedContainer,metaElementID);
					}
					//Node has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createNode_in_Owner(castedContainer,metaElementID);
					}
					//Node has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createNode_in_OwningPackage(castedContainer,metaElementID);
					}
					//Node has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createNode_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//Node has package as a containment
					case  UmlPackage::TYPE_ATTRIBUTE_PACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createNode_in_Package(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::OBJECT_CLASS:
		{
				return this->createObject(metaElementID);
			
		}
		case UmlPackage::OBJECTFLOW_CLASS:
		{
			if (nullptr == container)
			{
				return this->createObjectFlow(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ObjectFlow has activity as a containment
					case  UmlPackage::ACTIVITYEDGE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createObjectFlow_in_Activity(castedContainer,metaElementID);
					}
					//ObjectFlow has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYEDGE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createObjectFlow_in_InStructuredNode(castedContainer,metaElementID);
					}
					//ObjectFlow has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createObjectFlow_in_Namespace(castedContainer,metaElementID);
					}
					//ObjectFlow has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createObjectFlow_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::OCCURRENCESPECIFICATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createOccurrenceSpecification(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//OccurrenceSpecification has enclosingInteraction as a containment
					case  UmlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGINTERACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Interaction>(container);
						return this->createOccurrenceSpecification_in_EnclosingInteraction(castedContainer,metaElementID);
					}
					//OccurrenceSpecification has enclosingOperand as a containment
					case  UmlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGOPERAND:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::InteractionOperand>(container);
						return this->createOccurrenceSpecification_in_EnclosingOperand(castedContainer,metaElementID);
					}
					//OccurrenceSpecification has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createOccurrenceSpecification_in_Namespace(castedContainer,metaElementID);
					}
					//OccurrenceSpecification has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createOccurrenceSpecification_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::OPAQUEACTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createOpaqueAction(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//OpaqueAction has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createOpaqueAction_in_Activity(castedContainer,metaElementID);
					}
					//OpaqueAction has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createOpaqueAction_in_InStructuredNode(castedContainer,metaElementID);
					}
					//OpaqueAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createOpaqueAction_in_Namespace(castedContainer,metaElementID);
					}
					//OpaqueAction has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createOpaqueAction_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::OPAQUEBEHAVIOR_CLASS:
		{
			if (nullptr == container)
			{
				return this->createOpaqueBehavior(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//OpaqueBehavior has behavioredClassifier as a containment
					case  UmlPackage::BEHAVIOR_ATTRIBUTE_BEHAVIOREDCLASSIFIER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::BehavioredClassifier>(container);
						return this->createOpaqueBehavior_in_BehavioredClassifier(castedContainer,metaElementID);
					}
					//OpaqueBehavior has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createOpaqueBehavior_in_Namespace(castedContainer,metaElementID);
					}
					//OpaqueBehavior has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createOpaqueBehavior_in_Owner(castedContainer,metaElementID);
					}
					//OpaqueBehavior has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createOpaqueBehavior_in_OwningPackage(castedContainer,metaElementID);
					}
					//OpaqueBehavior has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createOpaqueBehavior_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//OpaqueBehavior has package as a containment
					case  UmlPackage::TYPE_ATTRIBUTE_PACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createOpaqueBehavior_in_Package(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::OPAQUEEXPRESSION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createOpaqueExpression(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//OpaqueExpression has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createOpaqueExpression_in_Namespace(castedContainer,metaElementID);
					}
					//OpaqueExpression has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createOpaqueExpression_in_Owner(castedContainer,metaElementID);
					}
					//OpaqueExpression has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createOpaqueExpression_in_OwningPackage(castedContainer,metaElementID);
					}
					//OpaqueExpression has owningSlot as a containment
					case  UmlPackage::VALUESPECIFICATION_ATTRIBUTE_OWNINGSLOT:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Slot>(container);
						return this->createOpaqueExpression_in_OwningSlot(castedContainer,metaElementID);
					}
					//OpaqueExpression has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createOpaqueExpression_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//OpaqueExpression has valueSpecificationAction as a containment
					case  UmlPackage::VALUESPECIFICATION_ATTRIBUTE_VALUESPECIFICATIONACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::ValueSpecificationAction>(container);
						return this->createOpaqueExpression_in_ValueSpecificationAction(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::OPERATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createOperation(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Operation has class as a containment
					case  UmlPackage::OPERATION_ATTRIBUTE_CLASS:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Class>(container);
						return this->createOperation_in_Class(castedContainer,metaElementID);
					}
					//Operation has datatype as a containment
					case  UmlPackage::OPERATION_ATTRIBUTE_DATATYPE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::DataType>(container);
						return this->createOperation_in_Datatype(castedContainer,metaElementID);
					}
					//Operation has interface as a containment
					case  UmlPackage::OPERATION_ATTRIBUTE_INTERFACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Interface>(container);
						return this->createOperation_in_Interface(castedContainer,metaElementID);
					}
					//Operation has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createOperation_in_Namespace(castedContainer,metaElementID);
					}
					//Operation has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createOperation_in_Owner(castedContainer,metaElementID);
					}
					//Operation has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createOperation_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::OPERATIONTEMPLATEPARAMETER_CLASS:
		{
			if (nullptr == container)
			{
				return this->createOperationTemplateParameter(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//OperationTemplateParameter has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createOperationTemplateParameter_in_Owner(castedContainer,metaElementID);
					}
					//OperationTemplateParameter has signature as a containment
					case  UmlPackage::TEMPLATEPARAMETER_ATTRIBUTE_SIGNATURE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateSignature>(container);
						return this->createOperationTemplateParameter_in_Signature(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::OUTPUTPIN_CLASS:
		{
			if (nullptr == container)
			{
				return this->createOutputPin(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//OutputPin has action as a containment
					case  UmlPackage::OUTPUTPIN_ATTRIBUTE_ACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Action>(container);
						return this->createOutputPin_in_Action(castedContainer,metaElementID);
					}
					//OutputPin has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createOutputPin_in_Activity(castedContainer,metaElementID);
					}
					//OutputPin has callAction as a containment
					case  UmlPackage::OUTPUTPIN_ATTRIBUTE_CALLACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::CallAction>(container);
						return this->createOutputPin_in_CallAction(castedContainer,metaElementID);
					}
					//OutputPin has clearStructuralFeatureAction as a containment
					case  UmlPackage::OUTPUTPIN_ATTRIBUTE_CLEARSTRUCTURALFEATUREACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::ClearStructuralFeatureAction>(container);
						return this->createOutputPin_in_ClearStructuralFeatureAction(castedContainer,metaElementID);
					}
					//OutputPin has createObjectAction as a containment
					case  UmlPackage::OUTPUTPIN_ATTRIBUTE_CREATEOBJECTACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::CreateObjectAction>(container);
						return this->createOutputPin_in_CreateObjectAction(castedContainer,metaElementID);
					}
					//OutputPin has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createOutputPin_in_InStructuredNode(castedContainer,metaElementID);
					}
					//OutputPin has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createOutputPin_in_Namespace(castedContainer,metaElementID);
					}
					//OutputPin has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createOutputPin_in_Owner(castedContainer,metaElementID);
					}
					//OutputPin has readSelfAction as a containment
					case  UmlPackage::OUTPUTPIN_ATTRIBUTE_READSELFACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::ReadSelfAction>(container);
						return this->createOutputPin_in_ReadSelfAction(castedContainer,metaElementID);
					}
					//OutputPin has readStructuralFeatureAction as a containment
					case  UmlPackage::OUTPUTPIN_ATTRIBUTE_READSTRUCTURALFEATUREACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::ReadStructuralFeatureAction>(container);
						return this->createOutputPin_in_ReadStructuralFeatureAction(castedContainer,metaElementID);
					}
					//OutputPin has valueSpecificationAction as a containment
					case  UmlPackage::OUTPUTPIN_ATTRIBUTE_VALUESPECIFICATIONACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::ValueSpecificationAction>(container);
						return this->createOutputPin_in_ValueSpecificationAction(castedContainer,metaElementID);
					}
					//OutputPin has writeStructuralFeatureAction as a containment
					case  UmlPackage::OUTPUTPIN_ATTRIBUTE_WRITESTRUCTURALFEATUREACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::WriteStructuralFeatureAction>(container);
						return this->createOutputPin_in_WriteStructuralFeatureAction(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::PACKAGE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createPackage(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Package has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createPackage_in_Namespace(castedContainer,metaElementID);
					}
					//Package has nestingPackage as a containment
					case  UmlPackage::PACKAGE_ATTRIBUTE_NESTINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createPackage_in_NestingPackage(castedContainer,metaElementID);
					}
					//Package has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createPackage_in_Owner(castedContainer,metaElementID);
					}
					//Package has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createPackage_in_OwningPackage(castedContainer,metaElementID);
					}
					//Package has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createPackage_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::PACKAGEIMPORT_CLASS:
		{
			if (nullptr == container)
			{
				return this->createPackageImport(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//PackageImport has importingNamespace as a containment
					case  UmlPackage::PACKAGEIMPORT_ATTRIBUTE_IMPORTINGNAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createPackageImport_in_ImportingNamespace(castedContainer,metaElementID);
					}
					//PackageImport has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createPackageImport_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::PACKAGEMERGE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createPackageMerge(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//PackageMerge has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createPackageMerge_in_Owner(castedContainer,metaElementID);
					}
					//PackageMerge has receivingPackage as a containment
					case  UmlPackage::PACKAGEMERGE_ATTRIBUTE_RECEIVINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createPackageMerge_in_ReceivingPackage(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::PARAMETER_CLASS:
		{
			if (nullptr == container)
			{
				return this->createParameter(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Parameter has behavior as a containment
					case  UmlPackage::PARAMETER_ATTRIBUTE_BEHAVIOR:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Behavior>(container);
						return this->createParameter_in_Behavior(castedContainer,metaElementID);
					}
					//Parameter has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createParameter_in_Namespace(castedContainer,metaElementID);
					}
					//Parameter has operation as a containment
					case  UmlPackage::PARAMETER_ATTRIBUTE_OPERATION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Operation>(container);
						return this->createParameter_in_Operation(castedContainer,metaElementID);
					}
					//Parameter has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createParameter_in_Owner(castedContainer,metaElementID);
					}
					//Parameter has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createParameter_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::PARAMETERSET_CLASS:
		{
			if (nullptr == container)
			{
				return this->createParameterSet(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ParameterSet has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createParameterSet_in_Namespace(castedContainer,metaElementID);
					}
					//ParameterSet has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createParameterSet_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::PARTDECOMPOSITION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createPartDecomposition(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//PartDecomposition has enclosingInteraction as a containment
					case  UmlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGINTERACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Interaction>(container);
						return this->createPartDecomposition_in_EnclosingInteraction(castedContainer,metaElementID);
					}
					//PartDecomposition has enclosingOperand as a containment
					case  UmlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGOPERAND:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::InteractionOperand>(container);
						return this->createPartDecomposition_in_EnclosingOperand(castedContainer,metaElementID);
					}
					//PartDecomposition has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createPartDecomposition_in_Namespace(castedContainer,metaElementID);
					}
					//PartDecomposition has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createPartDecomposition_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::PORT_CLASS:
		{
			if (nullptr == container)
			{
				return this->createPort(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Port has associationEnd as a containment
					case  UmlPackage::PROPERTY_ATTRIBUTE_ASSOCIATIONEND:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Property>(container);
						return this->createPort_in_AssociationEnd(castedContainer,metaElementID);
					}
					//Port has class as a containment
					case  UmlPackage::PROPERTY_ATTRIBUTE_CLASS:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Class>(container);
						return this->createPort_in_Class(castedContainer,metaElementID);
					}
					//Port has datatype as a containment
					case  UmlPackage::PROPERTY_ATTRIBUTE_DATATYPE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::DataType>(container);
						return this->createPort_in_Datatype(castedContainer,metaElementID);
					}
					//Port has interface as a containment
					case  UmlPackage::PROPERTY_ATTRIBUTE_INTERFACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Interface>(container);
						return this->createPort_in_Interface(castedContainer,metaElementID);
					}
					//Port has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createPort_in_Namespace(castedContainer,metaElementID);
					}
					//Port has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createPort_in_Owner(castedContainer,metaElementID);
					}
					//Port has owningAssociation as a containment
					case  UmlPackage::PROPERTY_ATTRIBUTE_OWNINGASSOCIATION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Association>(container);
						return this->createPort_in_OwningAssociation(castedContainer,metaElementID);
					}
					//Port has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createPort_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::PRIMITIVETYPE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createPrimitiveType(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//PrimitiveType has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createPrimitiveType_in_Namespace(castedContainer,metaElementID);
					}
					//PrimitiveType has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createPrimitiveType_in_Owner(castedContainer,metaElementID);
					}
					//PrimitiveType has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createPrimitiveType_in_OwningPackage(castedContainer,metaElementID);
					}
					//PrimitiveType has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createPrimitiveType_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//PrimitiveType has package as a containment
					case  UmlPackage::TYPE_ATTRIBUTE_PACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createPrimitiveType_in_Package(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::PROFILE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createProfile(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Profile has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createProfile_in_Namespace(castedContainer,metaElementID);
					}
					//Profile has nestingPackage as a containment
					case  UmlPackage::PACKAGE_ATTRIBUTE_NESTINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createProfile_in_NestingPackage(castedContainer,metaElementID);
					}
					//Profile has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createProfile_in_Owner(castedContainer,metaElementID);
					}
					//Profile has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createProfile_in_OwningPackage(castedContainer,metaElementID);
					}
					//Profile has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createProfile_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::PROFILEAPPLICATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createProfileApplication(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ProfileApplication has applyingPackage as a containment
					case  UmlPackage::PROFILEAPPLICATION_ATTRIBUTE_APPLYINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createProfileApplication_in_ApplyingPackage(castedContainer,metaElementID);
					}
					//ProfileApplication has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createProfileApplication_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::PROPERTY_CLASS:
		{
			if (nullptr == container)
			{
				return this->createProperty(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Property has associationEnd as a containment
					case  UmlPackage::PROPERTY_ATTRIBUTE_ASSOCIATIONEND:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Property>(container);
						return this->createProperty_in_AssociationEnd(castedContainer,metaElementID);
					}
					//Property has class as a containment
					case  UmlPackage::PROPERTY_ATTRIBUTE_CLASS:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Class>(container);
						return this->createProperty_in_Class(castedContainer,metaElementID);
					}
					//Property has datatype as a containment
					case  UmlPackage::PROPERTY_ATTRIBUTE_DATATYPE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::DataType>(container);
						return this->createProperty_in_Datatype(castedContainer,metaElementID);
					}
					//Property has interface as a containment
					case  UmlPackage::PROPERTY_ATTRIBUTE_INTERFACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Interface>(container);
						return this->createProperty_in_Interface(castedContainer,metaElementID);
					}
					//Property has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createProperty_in_Namespace(castedContainer,metaElementID);
					}
					//Property has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createProperty_in_Owner(castedContainer,metaElementID);
					}
					//Property has owningAssociation as a containment
					case  UmlPackage::PROPERTY_ATTRIBUTE_OWNINGASSOCIATION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Association>(container);
						return this->createProperty_in_OwningAssociation(castedContainer,metaElementID);
					}
					//Property has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createProperty_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::PROTOCOLCONFORMANCE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createProtocolConformance(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ProtocolConformance has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createProtocolConformance_in_Owner(castedContainer,metaElementID);
					}
					//ProtocolConformance has specificMachine as a containment
					case  UmlPackage::PROTOCOLCONFORMANCE_ATTRIBUTE_SPECIFICMACHINE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::ProtocolStateMachine>(container);
						return this->createProtocolConformance_in_SpecificMachine(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::PROTOCOLSTATEMACHINE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createProtocolStateMachine(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ProtocolStateMachine has behavioredClassifier as a containment
					case  UmlPackage::BEHAVIOR_ATTRIBUTE_BEHAVIOREDCLASSIFIER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::BehavioredClassifier>(container);
						return this->createProtocolStateMachine_in_BehavioredClassifier(castedContainer,metaElementID);
					}
					//ProtocolStateMachine has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createProtocolStateMachine_in_Namespace(castedContainer,metaElementID);
					}
					//ProtocolStateMachine has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createProtocolStateMachine_in_Owner(castedContainer,metaElementID);
					}
					//ProtocolStateMachine has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createProtocolStateMachine_in_OwningPackage(castedContainer,metaElementID);
					}
					//ProtocolStateMachine has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createProtocolStateMachine_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//ProtocolStateMachine has package as a containment
					case  UmlPackage::TYPE_ATTRIBUTE_PACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createProtocolStateMachine_in_Package(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::PROTOCOLTRANSITION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createProtocolTransition(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ProtocolTransition has container as a containment
					case  UmlPackage::TRANSITION_ATTRIBUTE_CONTAINER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Region>(container);
						return this->createProtocolTransition_in_Container(castedContainer,metaElementID);
					}
					//ProtocolTransition has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createProtocolTransition_in_Namespace(castedContainer,metaElementID);
					}
					//ProtocolTransition has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createProtocolTransition_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::PSEUDOSTATE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createPseudostate(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Pseudostate has container as a containment
					case  UmlPackage::VERTEX_ATTRIBUTE_CONTAINER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Region>(container);
						return this->createPseudostate_in_Container(castedContainer,metaElementID);
					}
					//Pseudostate has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createPseudostate_in_Namespace(castedContainer,metaElementID);
					}
					//Pseudostate has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createPseudostate_in_Owner(castedContainer,metaElementID);
					}
					//Pseudostate has state as a containment
					case  UmlPackage::PSEUDOSTATE_ATTRIBUTE_STATE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::State>(container);
						return this->createPseudostate_in_State(castedContainer,metaElementID);
					}
					//Pseudostate has stateMachine as a containment
					case  UmlPackage::PSEUDOSTATE_ATTRIBUTE_STATEMACHINE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StateMachine>(container);
						return this->createPseudostate_in_StateMachine(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::QUALIFIERVALUE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createQualifierValue(metaElementID);
			}
			else
			{
				std::shared_ptr<uml::Element> castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
				assert(castedContainer);
				return std::shared_ptr<uml::QualifierValue>(this->createQualifierValue_in_Owner(castedContainer,metaElementID));
			}
		}
		case UmlPackage::RAISEEXCEPTIONACTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createRaiseExceptionAction(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//RaiseExceptionAction has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createRaiseExceptionAction_in_Activity(castedContainer,metaElementID);
					}
					//RaiseExceptionAction has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createRaiseExceptionAction_in_InStructuredNode(castedContainer,metaElementID);
					}
					//RaiseExceptionAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createRaiseExceptionAction_in_Namespace(castedContainer,metaElementID);
					}
					//RaiseExceptionAction has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createRaiseExceptionAction_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::READEXTENTACTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createReadExtentAction(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ReadExtentAction has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createReadExtentAction_in_Activity(castedContainer,metaElementID);
					}
					//ReadExtentAction has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createReadExtentAction_in_InStructuredNode(castedContainer,metaElementID);
					}
					//ReadExtentAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createReadExtentAction_in_Namespace(castedContainer,metaElementID);
					}
					//ReadExtentAction has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createReadExtentAction_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::READISCLASSIFIEDOBJECTACTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createReadIsClassifiedObjectAction(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ReadIsClassifiedObjectAction has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createReadIsClassifiedObjectAction_in_Activity(castedContainer,metaElementID);
					}
					//ReadIsClassifiedObjectAction has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createReadIsClassifiedObjectAction_in_InStructuredNode(castedContainer,metaElementID);
					}
					//ReadIsClassifiedObjectAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createReadIsClassifiedObjectAction_in_Namespace(castedContainer,metaElementID);
					}
					//ReadIsClassifiedObjectAction has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createReadIsClassifiedObjectAction_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::READLINKACTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createReadLinkAction(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ReadLinkAction has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createReadLinkAction_in_Activity(castedContainer,metaElementID);
					}
					//ReadLinkAction has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createReadLinkAction_in_InStructuredNode(castedContainer,metaElementID);
					}
					//ReadLinkAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createReadLinkAction_in_Namespace(castedContainer,metaElementID);
					}
					//ReadLinkAction has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createReadLinkAction_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::READLINKOBJECTENDACTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createReadLinkObjectEndAction(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ReadLinkObjectEndAction has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createReadLinkObjectEndAction_in_Activity(castedContainer,metaElementID);
					}
					//ReadLinkObjectEndAction has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createReadLinkObjectEndAction_in_InStructuredNode(castedContainer,metaElementID);
					}
					//ReadLinkObjectEndAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createReadLinkObjectEndAction_in_Namespace(castedContainer,metaElementID);
					}
					//ReadLinkObjectEndAction has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createReadLinkObjectEndAction_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::READLINKOBJECTENDQUALIFIERACTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createReadLinkObjectEndQualifierAction(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ReadLinkObjectEndQualifierAction has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createReadLinkObjectEndQualifierAction_in_Activity(castedContainer,metaElementID);
					}
					//ReadLinkObjectEndQualifierAction has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createReadLinkObjectEndQualifierAction_in_InStructuredNode(castedContainer,metaElementID);
					}
					//ReadLinkObjectEndQualifierAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createReadLinkObjectEndQualifierAction_in_Namespace(castedContainer,metaElementID);
					}
					//ReadLinkObjectEndQualifierAction has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createReadLinkObjectEndQualifierAction_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::READSELFACTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createReadSelfAction(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ReadSelfAction has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createReadSelfAction_in_Activity(castedContainer,metaElementID);
					}
					//ReadSelfAction has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createReadSelfAction_in_InStructuredNode(castedContainer,metaElementID);
					}
					//ReadSelfAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createReadSelfAction_in_Namespace(castedContainer,metaElementID);
					}
					//ReadSelfAction has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createReadSelfAction_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::READSTRUCTURALFEATUREACTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createReadStructuralFeatureAction(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ReadStructuralFeatureAction has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createReadStructuralFeatureAction_in_Activity(castedContainer,metaElementID);
					}
					//ReadStructuralFeatureAction has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createReadStructuralFeatureAction_in_InStructuredNode(castedContainer,metaElementID);
					}
					//ReadStructuralFeatureAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createReadStructuralFeatureAction_in_Namespace(castedContainer,metaElementID);
					}
					//ReadStructuralFeatureAction has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createReadStructuralFeatureAction_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::READVARIABLEACTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createReadVariableAction(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ReadVariableAction has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createReadVariableAction_in_Activity(castedContainer,metaElementID);
					}
					//ReadVariableAction has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createReadVariableAction_in_InStructuredNode(castedContainer,metaElementID);
					}
					//ReadVariableAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createReadVariableAction_in_Namespace(castedContainer,metaElementID);
					}
					//ReadVariableAction has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createReadVariableAction_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::REALIZATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createRealization(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Realization has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createRealization_in_Namespace(castedContainer,metaElementID);
					}
					//Realization has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createRealization_in_Owner(castedContainer,metaElementID);
					}
					//Realization has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createRealization_in_OwningPackage(castedContainer,metaElementID);
					}
					//Realization has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createRealization_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::RECEPTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createReception(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Reception has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createReception_in_Namespace(castedContainer,metaElementID);
					}
					//Reception has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createReception_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::RECLASSIFYOBJECTACTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createReclassifyObjectAction(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ReclassifyObjectAction has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createReclassifyObjectAction_in_Activity(castedContainer,metaElementID);
					}
					//ReclassifyObjectAction has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createReclassifyObjectAction_in_InStructuredNode(castedContainer,metaElementID);
					}
					//ReclassifyObjectAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createReclassifyObjectAction_in_Namespace(castedContainer,metaElementID);
					}
					//ReclassifyObjectAction has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createReclassifyObjectAction_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::REDEFINABLETEMPLATESIGNATURE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createRedefinableTemplateSignature(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//RedefinableTemplateSignature has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createRedefinableTemplateSignature_in_Namespace(castedContainer,metaElementID);
					}
					//RedefinableTemplateSignature has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createRedefinableTemplateSignature_in_Owner(castedContainer,metaElementID);
					}
					//RedefinableTemplateSignature has template as a containment
					case  UmlPackage::TEMPLATESIGNATURE_ATTRIBUTE_TEMPLATE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateableElement>(container);
						return this->createRedefinableTemplateSignature_in_Template(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::REDUCEACTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createReduceAction(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ReduceAction has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createReduceAction_in_Activity(castedContainer,metaElementID);
					}
					//ReduceAction has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createReduceAction_in_InStructuredNode(castedContainer,metaElementID);
					}
					//ReduceAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createReduceAction_in_Namespace(castedContainer,metaElementID);
					}
					//ReduceAction has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createReduceAction_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::REGION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createRegion(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Region has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createRegion_in_Namespace(castedContainer,metaElementID);
					}
					//Region has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createRegion_in_Owner(castedContainer,metaElementID);
					}
					//Region has state as a containment
					case  UmlPackage::REGION_ATTRIBUTE_STATE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::State>(container);
						return this->createRegion_in_State(castedContainer,metaElementID);
					}
					//Region has stateMachine as a containment
					case  UmlPackage::REGION_ATTRIBUTE_STATEMACHINE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StateMachine>(container);
						return this->createRegion_in_StateMachine(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::REMOVESTRUCTURALFEATUREVALUEACTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createRemoveStructuralFeatureValueAction(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//RemoveStructuralFeatureValueAction has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createRemoveStructuralFeatureValueAction_in_Activity(castedContainer,metaElementID);
					}
					//RemoveStructuralFeatureValueAction has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createRemoveStructuralFeatureValueAction_in_InStructuredNode(castedContainer,metaElementID);
					}
					//RemoveStructuralFeatureValueAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createRemoveStructuralFeatureValueAction_in_Namespace(castedContainer,metaElementID);
					}
					//RemoveStructuralFeatureValueAction has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createRemoveStructuralFeatureValueAction_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::REMOVEVARIABLEVALUEACTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createRemoveVariableValueAction(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//RemoveVariableValueAction has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createRemoveVariableValueAction_in_Activity(castedContainer,metaElementID);
					}
					//RemoveVariableValueAction has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createRemoveVariableValueAction_in_InStructuredNode(castedContainer,metaElementID);
					}
					//RemoveVariableValueAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createRemoveVariableValueAction_in_Namespace(castedContainer,metaElementID);
					}
					//RemoveVariableValueAction has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createRemoveVariableValueAction_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::REPLYACTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createReplyAction(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ReplyAction has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createReplyAction_in_Activity(castedContainer,metaElementID);
					}
					//ReplyAction has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createReplyAction_in_InStructuredNode(castedContainer,metaElementID);
					}
					//ReplyAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createReplyAction_in_Namespace(castedContainer,metaElementID);
					}
					//ReplyAction has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createReplyAction_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::SENDOBJECTACTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createSendObjectAction(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//SendObjectAction has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createSendObjectAction_in_Activity(castedContainer,metaElementID);
					}
					//SendObjectAction has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createSendObjectAction_in_InStructuredNode(castedContainer,metaElementID);
					}
					//SendObjectAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createSendObjectAction_in_Namespace(castedContainer,metaElementID);
					}
					//SendObjectAction has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createSendObjectAction_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::SENDSIGNALACTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createSendSignalAction(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//SendSignalAction has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createSendSignalAction_in_Activity(castedContainer,metaElementID);
					}
					//SendSignalAction has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createSendSignalAction_in_InStructuredNode(castedContainer,metaElementID);
					}
					//SendSignalAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createSendSignalAction_in_Namespace(castedContainer,metaElementID);
					}
					//SendSignalAction has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createSendSignalAction_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::SEQUENCENODE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createSequenceNode(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//SequenceNode has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createSequenceNode_in_Activity(castedContainer,metaElementID);
					}
					//SequenceNode has inActivity as a containment
					case  UmlPackage::ACTIVITYGROUP_ATTRIBUTE_INACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createSequenceNode_in_InActivity(castedContainer,metaElementID);
					}
					//SequenceNode has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createSequenceNode_in_InStructuredNode(castedContainer,metaElementID);
					}
					//SequenceNode has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createSequenceNode_in_Namespace(castedContainer,metaElementID);
					}
					//SequenceNode has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createSequenceNode_in_Owner(castedContainer,metaElementID);
					}
					//SequenceNode has superGroup as a containment
					case  UmlPackage::ACTIVITYGROUP_ATTRIBUTE_SUPERGROUP:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::ActivityGroup>(container);
						return this->createSequenceNode_in_SuperGroup(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::SIGNAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createSignal(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Signal has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createSignal_in_Namespace(castedContainer,metaElementID);
					}
					//Signal has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createSignal_in_Owner(castedContainer,metaElementID);
					}
					//Signal has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createSignal_in_OwningPackage(castedContainer,metaElementID);
					}
					//Signal has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createSignal_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//Signal has package as a containment
					case  UmlPackage::TYPE_ATTRIBUTE_PACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createSignal_in_Package(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::SIGNALEVENT_CLASS:
		{
			if (nullptr == container)
			{
				return this->createSignalEvent(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//SignalEvent has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createSignalEvent_in_Namespace(castedContainer,metaElementID);
					}
					//SignalEvent has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createSignalEvent_in_Owner(castedContainer,metaElementID);
					}
					//SignalEvent has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createSignalEvent_in_OwningPackage(castedContainer,metaElementID);
					}
					//SignalEvent has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createSignalEvent_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::SLOT_CLASS:
		{
			if (nullptr == container)
			{
				return this->createSlot(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Slot has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createSlot_in_Owner(castedContainer,metaElementID);
					}
					//Slot has owningInstance as a containment
					case  UmlPackage::SLOT_ATTRIBUTE_OWNINGINSTANCE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::InstanceSpecification>(container);
						return this->createSlot_in_OwningInstance(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::STARTCLASSIFIERBEHAVIORACTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createStartClassifierBehaviorAction(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//StartClassifierBehaviorAction has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createStartClassifierBehaviorAction_in_Activity(castedContainer,metaElementID);
					}
					//StartClassifierBehaviorAction has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createStartClassifierBehaviorAction_in_InStructuredNode(castedContainer,metaElementID);
					}
					//StartClassifierBehaviorAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createStartClassifierBehaviorAction_in_Namespace(castedContainer,metaElementID);
					}
					//StartClassifierBehaviorAction has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createStartClassifierBehaviorAction_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::STARTOBJECTBEHAVIORACTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createStartObjectBehaviorAction(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//StartObjectBehaviorAction has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createStartObjectBehaviorAction_in_Activity(castedContainer,metaElementID);
					}
					//StartObjectBehaviorAction has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createStartObjectBehaviorAction_in_InStructuredNode(castedContainer,metaElementID);
					}
					//StartObjectBehaviorAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createStartObjectBehaviorAction_in_Namespace(castedContainer,metaElementID);
					}
					//StartObjectBehaviorAction has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createStartObjectBehaviorAction_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::STATE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createState(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//State has container as a containment
					case  UmlPackage::VERTEX_ATTRIBUTE_CONTAINER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Region>(container);
						return this->createState_in_Container(castedContainer,metaElementID);
					}
					//State has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createState_in_Namespace(castedContainer,metaElementID);
					}
					//State has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createState_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::STATEINVARIANT_CLASS:
		{
			if (nullptr == container)
			{
				return this->createStateInvariant(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//StateInvariant has enclosingInteraction as a containment
					case  UmlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGINTERACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Interaction>(container);
						return this->createStateInvariant_in_EnclosingInteraction(castedContainer,metaElementID);
					}
					//StateInvariant has enclosingOperand as a containment
					case  UmlPackage::INTERACTIONFRAGMENT_ATTRIBUTE_ENCLOSINGOPERAND:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::InteractionOperand>(container);
						return this->createStateInvariant_in_EnclosingOperand(castedContainer,metaElementID);
					}
					//StateInvariant has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createStateInvariant_in_Namespace(castedContainer,metaElementID);
					}
					//StateInvariant has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createStateInvariant_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::STATEMACHINE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createStateMachine(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//StateMachine has behavioredClassifier as a containment
					case  UmlPackage::BEHAVIOR_ATTRIBUTE_BEHAVIOREDCLASSIFIER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::BehavioredClassifier>(container);
						return this->createStateMachine_in_BehavioredClassifier(castedContainer,metaElementID);
					}
					//StateMachine has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createStateMachine_in_Namespace(castedContainer,metaElementID);
					}
					//StateMachine has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createStateMachine_in_Owner(castedContainer,metaElementID);
					}
					//StateMachine has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createStateMachine_in_OwningPackage(castedContainer,metaElementID);
					}
					//StateMachine has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createStateMachine_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//StateMachine has package as a containment
					case  UmlPackage::TYPE_ATTRIBUTE_PACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createStateMachine_in_Package(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::STEREOTYPE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createStereotype(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Stereotype has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createStereotype_in_Namespace(castedContainer,metaElementID);
					}
					//Stereotype has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createStereotype_in_Owner(castedContainer,metaElementID);
					}
					//Stereotype has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createStereotype_in_OwningPackage(castedContainer,metaElementID);
					}
					//Stereotype has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createStereotype_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//Stereotype has package as a containment
					case  UmlPackage::TYPE_ATTRIBUTE_PACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createStereotype_in_Package(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::STRINGEXPRESSION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createStringExpression(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//StringExpression has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createStringExpression_in_Namespace(castedContainer,metaElementID);
					}
					//StringExpression has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createStringExpression_in_Owner(castedContainer,metaElementID);
					}
					//StringExpression has owningExpression as a containment
					case  UmlPackage::STRINGEXPRESSION_ATTRIBUTE_OWNINGEXPRESSION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StringExpression>(container);
						return this->createStringExpression_in_OwningExpression(castedContainer,metaElementID);
					}
					//StringExpression has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createStringExpression_in_OwningPackage(castedContainer,metaElementID);
					}
					//StringExpression has owningSlot as a containment
					case  UmlPackage::VALUESPECIFICATION_ATTRIBUTE_OWNINGSLOT:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Slot>(container);
						return this->createStringExpression_in_OwningSlot(castedContainer,metaElementID);
					}
					//StringExpression has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createStringExpression_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//StringExpression has valueSpecificationAction as a containment
					case  UmlPackage::VALUESPECIFICATION_ATTRIBUTE_VALUESPECIFICATIONACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::ValueSpecificationAction>(container);
						return this->createStringExpression_in_ValueSpecificationAction(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::STRUCTUREDACTIVITYNODE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createStructuredActivityNode(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//StructuredActivityNode has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createStructuredActivityNode_in_Activity(castedContainer,metaElementID);
					}
					//StructuredActivityNode has inActivity as a containment
					case  UmlPackage::ACTIVITYGROUP_ATTRIBUTE_INACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createStructuredActivityNode_in_InActivity(castedContainer,metaElementID);
					}
					//StructuredActivityNode has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createStructuredActivityNode_in_InStructuredNode(castedContainer,metaElementID);
					}
					//StructuredActivityNode has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createStructuredActivityNode_in_Namespace(castedContainer,metaElementID);
					}
					//StructuredActivityNode has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createStructuredActivityNode_in_Owner(castedContainer,metaElementID);
					}
					//StructuredActivityNode has superGroup as a containment
					case  UmlPackage::ACTIVITYGROUP_ATTRIBUTE_SUPERGROUP:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::ActivityGroup>(container);
						return this->createStructuredActivityNode_in_SuperGroup(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::SUBSTITUTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createSubstitution(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Substitution has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createSubstitution_in_Namespace(castedContainer,metaElementID);
					}
					//Substitution has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createSubstitution_in_Owner(castedContainer,metaElementID);
					}
					//Substitution has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createSubstitution_in_OwningPackage(castedContainer,metaElementID);
					}
					//Substitution has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createSubstitution_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//Substitution has substitutingClassifier as a containment
					case  UmlPackage::SUBSTITUTION_ATTRIBUTE_SUBSTITUTINGCLASSIFIER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Classifier>(container);
						return this->createSubstitution_in_SubstitutingClassifier(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::TEMPLATEBINDING_CLASS:
		{
			if (nullptr == container)
			{
				return this->createTemplateBinding(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//TemplateBinding has boundElement as a containment
					case  UmlPackage::TEMPLATEBINDING_ATTRIBUTE_BOUNDELEMENT:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateableElement>(container);
						return this->createTemplateBinding_in_BoundElement(castedContainer,metaElementID);
					}
					//TemplateBinding has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createTemplateBinding_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::TEMPLATEPARAMETER_CLASS:
		{
			if (nullptr == container)
			{
				return this->createTemplateParameter(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//TemplateParameter has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createTemplateParameter_in_Owner(castedContainer,metaElementID);
					}
					//TemplateParameter has signature as a containment
					case  UmlPackage::TEMPLATEPARAMETER_ATTRIBUTE_SIGNATURE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateSignature>(container);
						return this->createTemplateParameter_in_Signature(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::TEMPLATEPARAMETERSUBSTITUTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createTemplateParameterSubstitution(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//TemplateParameterSubstitution has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createTemplateParameterSubstitution_in_Owner(castedContainer,metaElementID);
					}
					//TemplateParameterSubstitution has templateBinding as a containment
					case  UmlPackage::TEMPLATEPARAMETERSUBSTITUTION_ATTRIBUTE_TEMPLATEBINDING:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateBinding>(container);
						return this->createTemplateParameterSubstitution_in_TemplateBinding(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::TEMPLATESIGNATURE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createTemplateSignature(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//TemplateSignature has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createTemplateSignature_in_Owner(castedContainer,metaElementID);
					}
					//TemplateSignature has template as a containment
					case  UmlPackage::TEMPLATESIGNATURE_ATTRIBUTE_TEMPLATE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateableElement>(container);
						return this->createTemplateSignature_in_Template(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::TESTIDENTITYACTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createTestIdentityAction(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//TestIdentityAction has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createTestIdentityAction_in_Activity(castedContainer,metaElementID);
					}
					//TestIdentityAction has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createTestIdentityAction_in_InStructuredNode(castedContainer,metaElementID);
					}
					//TestIdentityAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createTestIdentityAction_in_Namespace(castedContainer,metaElementID);
					}
					//TestIdentityAction has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createTestIdentityAction_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::TIMECONSTRAINT_CLASS:
		{
			if (nullptr == container)
			{
				return this->createTimeConstraint(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//TimeConstraint has context as a containment
					case  UmlPackage::CONSTRAINT_ATTRIBUTE_CONTEXT:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createTimeConstraint_in_Context(castedContainer,metaElementID);
					}
					//TimeConstraint has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createTimeConstraint_in_Namespace(castedContainer,metaElementID);
					}
					//TimeConstraint has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createTimeConstraint_in_Owner(castedContainer,metaElementID);
					}
					//TimeConstraint has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createTimeConstraint_in_OwningPackage(castedContainer,metaElementID);
					}
					//TimeConstraint has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createTimeConstraint_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::TIMEEVENT_CLASS:
		{
			if (nullptr == container)
			{
				return this->createTimeEvent(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//TimeEvent has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createTimeEvent_in_Namespace(castedContainer,metaElementID);
					}
					//TimeEvent has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createTimeEvent_in_Owner(castedContainer,metaElementID);
					}
					//TimeEvent has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createTimeEvent_in_OwningPackage(castedContainer,metaElementID);
					}
					//TimeEvent has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createTimeEvent_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::TIMEEXPRESSION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createTimeExpression(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//TimeExpression has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createTimeExpression_in_Namespace(castedContainer,metaElementID);
					}
					//TimeExpression has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createTimeExpression_in_Owner(castedContainer,metaElementID);
					}
					//TimeExpression has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createTimeExpression_in_OwningPackage(castedContainer,metaElementID);
					}
					//TimeExpression has owningSlot as a containment
					case  UmlPackage::VALUESPECIFICATION_ATTRIBUTE_OWNINGSLOT:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Slot>(container);
						return this->createTimeExpression_in_OwningSlot(castedContainer,metaElementID);
					}
					//TimeExpression has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createTimeExpression_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//TimeExpression has valueSpecificationAction as a containment
					case  UmlPackage::VALUESPECIFICATION_ATTRIBUTE_VALUESPECIFICATIONACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::ValueSpecificationAction>(container);
						return this->createTimeExpression_in_ValueSpecificationAction(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::TIMEINTERVAL_CLASS:
		{
			if (nullptr == container)
			{
				return this->createTimeInterval(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//TimeInterval has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createTimeInterval_in_Namespace(castedContainer,metaElementID);
					}
					//TimeInterval has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createTimeInterval_in_Owner(castedContainer,metaElementID);
					}
					//TimeInterval has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createTimeInterval_in_OwningPackage(castedContainer,metaElementID);
					}
					//TimeInterval has owningSlot as a containment
					case  UmlPackage::VALUESPECIFICATION_ATTRIBUTE_OWNINGSLOT:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Slot>(container);
						return this->createTimeInterval_in_OwningSlot(castedContainer,metaElementID);
					}
					//TimeInterval has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createTimeInterval_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//TimeInterval has valueSpecificationAction as a containment
					case  UmlPackage::VALUESPECIFICATION_ATTRIBUTE_VALUESPECIFICATIONACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::ValueSpecificationAction>(container);
						return this->createTimeInterval_in_ValueSpecificationAction(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::TIMEOBSERVATION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createTimeObservation(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//TimeObservation has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createTimeObservation_in_Namespace(castedContainer,metaElementID);
					}
					//TimeObservation has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createTimeObservation_in_Owner(castedContainer,metaElementID);
					}
					//TimeObservation has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createTimeObservation_in_OwningPackage(castedContainer,metaElementID);
					}
					//TimeObservation has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createTimeObservation_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::TRANSITION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createTransition(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Transition has container as a containment
					case  UmlPackage::TRANSITION_ATTRIBUTE_CONTAINER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Region>(container);
						return this->createTransition_in_Container(castedContainer,metaElementID);
					}
					//Transition has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createTransition_in_Namespace(castedContainer,metaElementID);
					}
					//Transition has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createTransition_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::TRIGGER_CLASS:
		{
			if (nullptr == container)
			{
				return this->createTrigger(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Trigger has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createTrigger_in_Namespace(castedContainer,metaElementID);
					}
					//Trigger has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createTrigger_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::UNMARSHALLACTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createUnmarshallAction(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//UnmarshallAction has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createUnmarshallAction_in_Activity(castedContainer,metaElementID);
					}
					//UnmarshallAction has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createUnmarshallAction_in_InStructuredNode(castedContainer,metaElementID);
					}
					//UnmarshallAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createUnmarshallAction_in_Namespace(castedContainer,metaElementID);
					}
					//UnmarshallAction has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createUnmarshallAction_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::USAGE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createUsage(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Usage has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createUsage_in_Namespace(castedContainer,metaElementID);
					}
					//Usage has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createUsage_in_Owner(castedContainer,metaElementID);
					}
					//Usage has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createUsage_in_OwningPackage(castedContainer,metaElementID);
					}
					//Usage has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createUsage_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::USECASE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createUseCase(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//UseCase has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createUseCase_in_Namespace(castedContainer,metaElementID);
					}
					//UseCase has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createUseCase_in_Owner(castedContainer,metaElementID);
					}
					//UseCase has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createUseCase_in_OwningPackage(castedContainer,metaElementID);
					}
					//UseCase has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createUseCase_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//UseCase has package as a containment
					case  UmlPackage::TYPE_ATTRIBUTE_PACKAGE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createUseCase_in_Package(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::VALUEPIN_CLASS:
		{
			if (nullptr == container)
			{
				return this->createValuePin(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ValuePin has action as a containment
					case  UmlPackage::INPUTPIN_ATTRIBUTE_ACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Action>(container);
						return this->createValuePin_in_Action(castedContainer,metaElementID);
					}
					//ValuePin has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createValuePin_in_Activity(castedContainer,metaElementID);
					}
					//ValuePin has addStructuralFeatureValueAction as a containment
					case  UmlPackage::INPUTPIN_ATTRIBUTE_ADDSTRUCTURALFEATUREVALUEACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::AddStructuralFeatureValueAction>(container);
						return this->createValuePin_in_AddStructuralFeatureValueAction(castedContainer,metaElementID);
					}
					//ValuePin has callOperationAction as a containment
					case  UmlPackage::INPUTPIN_ATTRIBUTE_CALLOPERATIONACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::CallOperationAction>(container);
						return this->createValuePin_in_CallOperationAction(castedContainer,metaElementID);
					}
					//ValuePin has destroyObjectAction as a containment
					case  UmlPackage::INPUTPIN_ATTRIBUTE_DESTROYOBJECTACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::DestroyObjectAction>(container);
						return this->createValuePin_in_DestroyObjectAction(castedContainer,metaElementID);
					}
					//ValuePin has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createValuePin_in_InStructuredNode(castedContainer,metaElementID);
					}
					//ValuePin has invocationAction as a containment
					case  UmlPackage::INPUTPIN_ATTRIBUTE_INVOCATIONACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::InvocationAction>(container);
						return this->createValuePin_in_InvocationAction(castedContainer,metaElementID);
					}
					//ValuePin has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createValuePin_in_Namespace(castedContainer,metaElementID);
					}
					//ValuePin has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createValuePin_in_Owner(castedContainer,metaElementID);
					}
					//ValuePin has structuralFeatureAction as a containment
					case  UmlPackage::INPUTPIN_ATTRIBUTE_STRUCTURALFEATUREACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuralFeatureAction>(container);
						return this->createValuePin_in_StructuralFeatureAction(castedContainer,metaElementID);
					}
					//ValuePin has writeStructuralFeatureAction as a containment
					case  UmlPackage::INPUTPIN_ATTRIBUTE_WRITESTRUCTURALFEATUREACTION:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::WriteStructuralFeatureAction>(container);
						return this->createValuePin_in_WriteStructuralFeatureAction(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::VALUESPECIFICATIONACTION_CLASS:
		{
			if (nullptr == container)
			{
				return this->createValueSpecificationAction(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//ValueSpecificationAction has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createValueSpecificationAction_in_Activity(castedContainer,metaElementID);
					}
					//ValueSpecificationAction has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_ATTRIBUTE_INSTRUCTUREDNODE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createValueSpecificationAction_in_InStructuredNode(castedContainer,metaElementID);
					}
					//ValueSpecificationAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createValueSpecificationAction_in_Namespace(castedContainer,metaElementID);
					}
					//ValueSpecificationAction has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createValueSpecificationAction_in_Owner(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::VARIABLE_CLASS:
		{
			if (nullptr == container)
			{
				return this->createVariable(metaElementID);
			}
			else
			{
				switch(referenceID)
				{
					//Variable has activityScope as a containment
					case  UmlPackage::VARIABLE_ATTRIBUTE_ACTIVITYSCOPE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createVariable_in_ActivityScope(castedContainer,metaElementID);
					}
					//Variable has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createVariable_in_Namespace(castedContainer,metaElementID);
					}
					//Variable has owner as a containment
					case  UmlPackage::ELEMENT_ATTRIBUTE_OWNER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createVariable_in_Owner(castedContainer,metaElementID);
					}
					//Variable has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_ATTRIBUTE_OWNINGTEMPLATEPARAMETER:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createVariable_in_OwningTemplateParameter(castedContainer,metaElementID);
					}
					//Variable has scope as a containment
					case  UmlPackage::VARIABLE_ATTRIBUTE_SCOPE:
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createVariable_in_Scope(castedContainer,metaElementID);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << metaElementID <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<ecore::EObject> UmlFactoryImpl::create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}
	int _elementID = _class->getMetaElementID();
	return create(_elementID, container, referenceID);
}

std::shared_ptr<ecore::EObject> UmlFactoryImpl::create(std::string _className, std::shared_ptr<ecore::EObject> container /*= nullptr*/, const int referenceID/* = -1*/) const
{
	auto iter = m_idMap.find(_className);
	if(iter != m_idMap.end())
    {
		//get the ID
        int id = iter->second;
		return create(id,container,referenceID);
    }
    return nullptr;
}

std::shared_ptr<Abstraction> UmlFactoryImpl::createAbstraction(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<AbstractionImpl> element(new AbstractionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisAbstractionPtr(element);
	return element;
}
std::shared_ptr<Abstraction> UmlFactoryImpl::createAbstraction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<AbstractionImpl> element(new AbstractionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisAbstractionPtr(element);
	return element;
	
}
std::shared_ptr<Abstraction> UmlFactoryImpl::createAbstraction_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<AbstractionImpl> element(new AbstractionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisAbstractionPtr(element);
	return element;
	
}
std::shared_ptr<Abstraction> UmlFactoryImpl::createAbstraction_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<AbstractionImpl> element(new AbstractionImpl(par_owningPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisAbstractionPtr(element);
	return element;
	
}
std::shared_ptr<Abstraction> UmlFactoryImpl::createAbstraction_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<AbstractionImpl> element(new AbstractionImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisAbstractionPtr(element);
	return element;
	
}
std::shared_ptr<AcceptCallAction> UmlFactoryImpl::createAcceptCallAction(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<AcceptCallActionImpl> element(new AcceptCallActionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisAcceptCallActionPtr(element);
	return element;
}
std::shared_ptr<AcceptCallAction> UmlFactoryImpl::createAcceptCallAction_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<AcceptCallActionImpl> element(new AcceptCallActionImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisAcceptCallActionPtr(element);
	return element;
	
}
std::shared_ptr<AcceptCallAction> UmlFactoryImpl::createAcceptCallAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<AcceptCallActionImpl> element(new AcceptCallActionImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisAcceptCallActionPtr(element);
	return element;
	
}
std::shared_ptr<AcceptCallAction> UmlFactoryImpl::createAcceptCallAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<AcceptCallActionImpl> element(new AcceptCallActionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisAcceptCallActionPtr(element);
	return element;
	
}
std::shared_ptr<AcceptCallAction> UmlFactoryImpl::createAcceptCallAction_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<AcceptCallActionImpl> element(new AcceptCallActionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisAcceptCallActionPtr(element);
	return element;
	
}
std::shared_ptr<AcceptEventAction> UmlFactoryImpl::createAcceptEventAction(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<AcceptEventActionImpl> element(new AcceptEventActionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisAcceptEventActionPtr(element);
	return element;
}
std::shared_ptr<AcceptEventAction> UmlFactoryImpl::createAcceptEventAction_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<AcceptEventActionImpl> element(new AcceptEventActionImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisAcceptEventActionPtr(element);
	return element;
	
}
std::shared_ptr<AcceptEventAction> UmlFactoryImpl::createAcceptEventAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<AcceptEventActionImpl> element(new AcceptEventActionImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisAcceptEventActionPtr(element);
	return element;
	
}
std::shared_ptr<AcceptEventAction> UmlFactoryImpl::createAcceptEventAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<AcceptEventActionImpl> element(new AcceptEventActionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisAcceptEventActionPtr(element);
	return element;
	
}
std::shared_ptr<AcceptEventAction> UmlFactoryImpl::createAcceptEventAction_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<AcceptEventActionImpl> element(new AcceptEventActionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisAcceptEventActionPtr(element);
	return element;
	
}
std::shared_ptr<ActionExecutionSpecification> UmlFactoryImpl::createActionExecutionSpecification(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ActionExecutionSpecificationImpl> element(new ActionExecutionSpecificationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisActionExecutionSpecificationPtr(element);
	return element;
}
std::shared_ptr<ActionExecutionSpecification> UmlFactoryImpl::createActionExecutionSpecification_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction, const int metaElementID) const
{
	std::shared_ptr<ActionExecutionSpecificationImpl> element(new ActionExecutionSpecificationImpl(par_enclosingInteraction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_enclosingInteraction.lock())
	{
			wp->getFragment()->push_back(element);
	}
	element->setThisActionExecutionSpecificationPtr(element);
	return element;
	
}
std::shared_ptr<ActionExecutionSpecification> UmlFactoryImpl::createActionExecutionSpecification_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand, const int metaElementID) const
{
	std::shared_ptr<ActionExecutionSpecificationImpl> element(new ActionExecutionSpecificationImpl(par_enclosingOperand));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_enclosingOperand.lock())
	{
			wp->getFragment()->push_back(element);
	}
	element->setThisActionExecutionSpecificationPtr(element);
	return element;
	
}
std::shared_ptr<ActionExecutionSpecification> UmlFactoryImpl::createActionExecutionSpecification_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ActionExecutionSpecificationImpl> element(new ActionExecutionSpecificationImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisActionExecutionSpecificationPtr(element);
	return element;
	
}
std::shared_ptr<ActionExecutionSpecification> UmlFactoryImpl::createActionExecutionSpecification_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ActionExecutionSpecificationImpl> element(new ActionExecutionSpecificationImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisActionExecutionSpecificationPtr(element);
	return element;
	
}
std::shared_ptr<ActionInputPin> UmlFactoryImpl::createActionInputPin(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ActionInputPinImpl> element(new ActionInputPinImpl());
	element->setMetaElementID(metaElementID);
	element->setThisActionInputPinPtr(element);
	return element;
}
std::shared_ptr<ActionInputPin> UmlFactoryImpl::createActionInputPin_in_Action(std::weak_ptr<uml::Action > par_action, const int metaElementID) const
{
	std::shared_ptr<ActionInputPinImpl> element(new ActionInputPinImpl(par_action));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_action.lock())
	{
			wp->getInput()->push_back(element);
	}
	element->setThisActionInputPinPtr(element);
	return element;
	
}
std::shared_ptr<ActionInputPin> UmlFactoryImpl::createActionInputPin_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<ActionInputPinImpl> element(new ActionInputPinImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisActionInputPinPtr(element);
	return element;
	
}
std::shared_ptr<ActionInputPin> UmlFactoryImpl::createActionInputPin_in_AddStructuralFeatureValueAction(std::weak_ptr<uml::AddStructuralFeatureValueAction > par_addStructuralFeatureValueAction, const int metaElementID) const
{
	std::shared_ptr<ActionInputPinImpl> element(new ActionInputPinImpl(par_addStructuralFeatureValueAction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_addStructuralFeatureValueAction.lock())
	{
			wp->setInsertAt(element);
	}
	element->setThisActionInputPinPtr(element);
	return element;
	
}
std::shared_ptr<ActionInputPin> UmlFactoryImpl::createActionInputPin_in_CallOperationAction(std::weak_ptr<uml::CallOperationAction > par_callOperationAction, const int metaElementID) const
{
	std::shared_ptr<ActionInputPinImpl> element(new ActionInputPinImpl(par_callOperationAction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_callOperationAction.lock())
	{
			wp->setTarget(element);
	}
	element->setThisActionInputPinPtr(element);
	return element;
	
}
std::shared_ptr<ActionInputPin> UmlFactoryImpl::createActionInputPin_in_DestroyObjectAction(std::weak_ptr<uml::DestroyObjectAction > par_destroyObjectAction, const int metaElementID) const
{
	std::shared_ptr<ActionInputPinImpl> element(new ActionInputPinImpl(par_destroyObjectAction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_destroyObjectAction.lock())
	{
			wp->setTarget(element);
	}
	element->setThisActionInputPinPtr(element);
	return element;
	
}
std::shared_ptr<ActionInputPin> UmlFactoryImpl::createActionInputPin_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<ActionInputPinImpl> element(new ActionInputPinImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisActionInputPinPtr(element);
	return element;
	
}
std::shared_ptr<ActionInputPin> UmlFactoryImpl::createActionInputPin_in_InvocationAction(std::weak_ptr<uml::InvocationAction > par_invocationAction, const int metaElementID) const
{
	std::shared_ptr<ActionInputPinImpl> element(new ActionInputPinImpl(par_invocationAction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_invocationAction.lock())
	{
			wp->getArgument()->push_back(element);
	}
	element->setThisActionInputPinPtr(element);
	return element;
	
}
std::shared_ptr<ActionInputPin> UmlFactoryImpl::createActionInputPin_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ActionInputPinImpl> element(new ActionInputPinImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisActionInputPinPtr(element);
	return element;
	
}
std::shared_ptr<ActionInputPin> UmlFactoryImpl::createActionInputPin_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ActionInputPinImpl> element(new ActionInputPinImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisActionInputPinPtr(element);
	return element;
	
}
std::shared_ptr<ActionInputPin> UmlFactoryImpl::createActionInputPin_in_StructuralFeatureAction(std::weak_ptr<uml::StructuralFeatureAction > par_structuralFeatureAction, const int metaElementID) const
{
	std::shared_ptr<ActionInputPinImpl> element(new ActionInputPinImpl(par_structuralFeatureAction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_structuralFeatureAction.lock())
	{
			wp->setObject(element);
	}
	element->setThisActionInputPinPtr(element);
	return element;
	
}
std::shared_ptr<ActionInputPin> UmlFactoryImpl::createActionInputPin_in_WriteStructuralFeatureAction(std::weak_ptr<uml::WriteStructuralFeatureAction > par_writeStructuralFeatureAction, const int metaElementID) const
{
	std::shared_ptr<ActionInputPinImpl> element(new ActionInputPinImpl(par_writeStructuralFeatureAction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_writeStructuralFeatureAction.lock())
	{
			wp->setValue(element);
	}
	element->setThisActionInputPinPtr(element);
	return element;
	
}
std::shared_ptr<Activity> UmlFactoryImpl::createActivity(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ActivityImpl> element(new ActivityImpl());
	element->setMetaElementID(metaElementID);
	element->setThisActivityPtr(element);
	return element;
}
std::shared_ptr<Activity> UmlFactoryImpl::createActivity_in_BehavioredClassifier(std::weak_ptr<uml::BehavioredClassifier > par_behavioredClassifier, const int metaElementID) const
{
	std::shared_ptr<ActivityImpl> element(new ActivityImpl(par_behavioredClassifier));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_behavioredClassifier.lock())
	{
			wp->getOwnedBehavior()->push_back(element);
	}
	element->setThisActivityPtr(element);
	return element;
	
}
std::shared_ptr<Activity> UmlFactoryImpl::createActivity_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ActivityImpl> element(new ActivityImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisActivityPtr(element);
	return element;
	
}
std::shared_ptr<Activity> UmlFactoryImpl::createActivity_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ActivityImpl> element(new ActivityImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisActivityPtr(element);
	return element;
	
}
std::shared_ptr<Activity> UmlFactoryImpl::createActivity_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<ActivityImpl> element(new ActivityImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisActivityPtr(element);
	return element;
	
}
std::shared_ptr<Activity> UmlFactoryImpl::createActivity_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<ActivityImpl> element(new ActivityImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisActivityPtr(element);
	return element;
	
}
std::shared_ptr<Activity> UmlFactoryImpl::createActivity_in_Package(std::weak_ptr<uml::Package > par_package, const int metaElementID) const
{
	std::shared_ptr<ActivityImpl> element(new ActivityImpl(par_package, UmlPackage::TYPE_ATTRIBUTE_PACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_package.lock())
	{
			wp->getOwnedType()->push_back(element);
	}
	element->setThisActivityPtr(element);
	return element;
	
}
std::shared_ptr<ActivityFinalNode> UmlFactoryImpl::createActivityFinalNode(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ActivityFinalNodeImpl> element(new ActivityFinalNodeImpl());
	element->setMetaElementID(metaElementID);
	element->setThisActivityFinalNodePtr(element);
	return element;
}
std::shared_ptr<ActivityFinalNode> UmlFactoryImpl::createActivityFinalNode_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<ActivityFinalNodeImpl> element(new ActivityFinalNodeImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisActivityFinalNodePtr(element);
	return element;
	
}
std::shared_ptr<ActivityFinalNode> UmlFactoryImpl::createActivityFinalNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<ActivityFinalNodeImpl> element(new ActivityFinalNodeImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisActivityFinalNodePtr(element);
	return element;
	
}
std::shared_ptr<ActivityFinalNode> UmlFactoryImpl::createActivityFinalNode_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ActivityFinalNodeImpl> element(new ActivityFinalNodeImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisActivityFinalNodePtr(element);
	return element;
	
}
std::shared_ptr<ActivityFinalNode> UmlFactoryImpl::createActivityFinalNode_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ActivityFinalNodeImpl> element(new ActivityFinalNodeImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisActivityFinalNodePtr(element);
	return element;
	
}
std::shared_ptr<ActivityParameterNode> UmlFactoryImpl::createActivityParameterNode(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ActivityParameterNodeImpl> element(new ActivityParameterNodeImpl());
	element->setMetaElementID(metaElementID);
	element->setThisActivityParameterNodePtr(element);
	return element;
}
std::shared_ptr<ActivityParameterNode> UmlFactoryImpl::createActivityParameterNode_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<ActivityParameterNodeImpl> element(new ActivityParameterNodeImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisActivityParameterNodePtr(element);
	return element;
	
}
std::shared_ptr<ActivityParameterNode> UmlFactoryImpl::createActivityParameterNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<ActivityParameterNodeImpl> element(new ActivityParameterNodeImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisActivityParameterNodePtr(element);
	return element;
	
}
std::shared_ptr<ActivityParameterNode> UmlFactoryImpl::createActivityParameterNode_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ActivityParameterNodeImpl> element(new ActivityParameterNodeImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisActivityParameterNodePtr(element);
	return element;
	
}
std::shared_ptr<ActivityParameterNode> UmlFactoryImpl::createActivityParameterNode_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ActivityParameterNodeImpl> element(new ActivityParameterNodeImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisActivityParameterNodePtr(element);
	return element;
	
}
std::shared_ptr<ActivityPartition> UmlFactoryImpl::createActivityPartition(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ActivityPartitionImpl> element(new ActivityPartitionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisActivityPartitionPtr(element);
	return element;
}
std::shared_ptr<ActivityPartition> UmlFactoryImpl::createActivityPartition_in_InActivity(std::weak_ptr<uml::Activity > par_inActivity, const int metaElementID) const
{
	std::shared_ptr<ActivityPartitionImpl> element(new ActivityPartitionImpl(par_inActivity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inActivity.lock())
	{
			wp->getPartition()->push_back(element);
	}
	element->setThisActivityPartitionPtr(element);
	return element;
	
}
std::shared_ptr<ActivityPartition> UmlFactoryImpl::createActivityPartition_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ActivityPartitionImpl> element(new ActivityPartitionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisActivityPartitionPtr(element);
	return element;
	
}
std::shared_ptr<ActivityPartition> UmlFactoryImpl::createActivityPartition_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ActivityPartitionImpl> element(new ActivityPartitionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisActivityPartitionPtr(element);
	return element;
	
}
std::shared_ptr<ActivityPartition> UmlFactoryImpl::createActivityPartition_in_SuperGroup(std::weak_ptr<uml::ActivityGroup > par_superGroup, const int metaElementID) const
{
	std::shared_ptr<ActivityPartitionImpl> element(new ActivityPartitionImpl(par_superGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_superGroup.lock())
	{
			wp->getSubgroup()->push_back(element);
	}
	element->setThisActivityPartitionPtr(element);
	return element;
	
}
std::shared_ptr<ActivityPartition> UmlFactoryImpl::createActivityPartition_in_SuperPartition(std::weak_ptr<uml::ActivityPartition > par_superPartition, const int metaElementID) const
{
	std::shared_ptr<ActivityPartitionImpl> element(new ActivityPartitionImpl(par_superPartition));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_superPartition.lock())
	{
			wp->getSubpartition()->push_back(element);
	}
	element->setThisActivityPartitionPtr(element);
	return element;
	
}
std::shared_ptr<Actor> UmlFactoryImpl::createActor(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ActorImpl> element(new ActorImpl());
	element->setMetaElementID(metaElementID);
	element->setThisActorPtr(element);
	return element;
}
std::shared_ptr<Actor> UmlFactoryImpl::createActor_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ActorImpl> element(new ActorImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisActorPtr(element);
	return element;
	
}
std::shared_ptr<Actor> UmlFactoryImpl::createActor_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ActorImpl> element(new ActorImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisActorPtr(element);
	return element;
	
}
std::shared_ptr<Actor> UmlFactoryImpl::createActor_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<ActorImpl> element(new ActorImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisActorPtr(element);
	return element;
	
}
std::shared_ptr<Actor> UmlFactoryImpl::createActor_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<ActorImpl> element(new ActorImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisActorPtr(element);
	return element;
	
}
std::shared_ptr<Actor> UmlFactoryImpl::createActor_in_Package(std::weak_ptr<uml::Package > par_package, const int metaElementID) const
{
	std::shared_ptr<ActorImpl> element(new ActorImpl(par_package, UmlPackage::TYPE_ATTRIBUTE_PACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_package.lock())
	{
			wp->getOwnedType()->push_back(element);
	}
	element->setThisActorPtr(element);
	return element;
	
}
std::shared_ptr<AddStructuralFeatureValueAction> UmlFactoryImpl::createAddStructuralFeatureValueAction(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<AddStructuralFeatureValueActionImpl> element(new AddStructuralFeatureValueActionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisAddStructuralFeatureValueActionPtr(element);
	return element;
}
std::shared_ptr<AddStructuralFeatureValueAction> UmlFactoryImpl::createAddStructuralFeatureValueAction_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<AddStructuralFeatureValueActionImpl> element(new AddStructuralFeatureValueActionImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisAddStructuralFeatureValueActionPtr(element);
	return element;
	
}
std::shared_ptr<AddStructuralFeatureValueAction> UmlFactoryImpl::createAddStructuralFeatureValueAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<AddStructuralFeatureValueActionImpl> element(new AddStructuralFeatureValueActionImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisAddStructuralFeatureValueActionPtr(element);
	return element;
	
}
std::shared_ptr<AddStructuralFeatureValueAction> UmlFactoryImpl::createAddStructuralFeatureValueAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<AddStructuralFeatureValueActionImpl> element(new AddStructuralFeatureValueActionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisAddStructuralFeatureValueActionPtr(element);
	return element;
	
}
std::shared_ptr<AddStructuralFeatureValueAction> UmlFactoryImpl::createAddStructuralFeatureValueAction_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<AddStructuralFeatureValueActionImpl> element(new AddStructuralFeatureValueActionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisAddStructuralFeatureValueActionPtr(element);
	return element;
	
}
std::shared_ptr<AddVariableValueAction> UmlFactoryImpl::createAddVariableValueAction(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<AddVariableValueActionImpl> element(new AddVariableValueActionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisAddVariableValueActionPtr(element);
	return element;
}
std::shared_ptr<AddVariableValueAction> UmlFactoryImpl::createAddVariableValueAction_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<AddVariableValueActionImpl> element(new AddVariableValueActionImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisAddVariableValueActionPtr(element);
	return element;
	
}
std::shared_ptr<AddVariableValueAction> UmlFactoryImpl::createAddVariableValueAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<AddVariableValueActionImpl> element(new AddVariableValueActionImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisAddVariableValueActionPtr(element);
	return element;
	
}
std::shared_ptr<AddVariableValueAction> UmlFactoryImpl::createAddVariableValueAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<AddVariableValueActionImpl> element(new AddVariableValueActionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisAddVariableValueActionPtr(element);
	return element;
	
}
std::shared_ptr<AddVariableValueAction> UmlFactoryImpl::createAddVariableValueAction_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<AddVariableValueActionImpl> element(new AddVariableValueActionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisAddVariableValueActionPtr(element);
	return element;
	
}
std::shared_ptr<AnyReceiveEvent> UmlFactoryImpl::createAnyReceiveEvent(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<AnyReceiveEventImpl> element(new AnyReceiveEventImpl());
	element->setMetaElementID(metaElementID);
	element->setThisAnyReceiveEventPtr(element);
	return element;
}
std::shared_ptr<AnyReceiveEvent> UmlFactoryImpl::createAnyReceiveEvent_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<AnyReceiveEventImpl> element(new AnyReceiveEventImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisAnyReceiveEventPtr(element);
	return element;
	
}
std::shared_ptr<AnyReceiveEvent> UmlFactoryImpl::createAnyReceiveEvent_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<AnyReceiveEventImpl> element(new AnyReceiveEventImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisAnyReceiveEventPtr(element);
	return element;
	
}
std::shared_ptr<AnyReceiveEvent> UmlFactoryImpl::createAnyReceiveEvent_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<AnyReceiveEventImpl> element(new AnyReceiveEventImpl(par_owningPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisAnyReceiveEventPtr(element);
	return element;
	
}
std::shared_ptr<AnyReceiveEvent> UmlFactoryImpl::createAnyReceiveEvent_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<AnyReceiveEventImpl> element(new AnyReceiveEventImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisAnyReceiveEventPtr(element);
	return element;
	
}
std::shared_ptr<Argument> UmlFactoryImpl::createArgument(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ArgumentImpl> element(new ArgumentImpl());
	element->setMetaElementID(metaElementID);
	element->setThisArgumentPtr(element);
	return element;
}
std::shared_ptr<Artifact> UmlFactoryImpl::createArtifact(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ArtifactImpl> element(new ArtifactImpl());
	element->setMetaElementID(metaElementID);
	element->setThisArtifactPtr(element);
	return element;
}
std::shared_ptr<Artifact> UmlFactoryImpl::createArtifact_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ArtifactImpl> element(new ArtifactImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisArtifactPtr(element);
	return element;
	
}
std::shared_ptr<Artifact> UmlFactoryImpl::createArtifact_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ArtifactImpl> element(new ArtifactImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisArtifactPtr(element);
	return element;
	
}
std::shared_ptr<Artifact> UmlFactoryImpl::createArtifact_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<ArtifactImpl> element(new ArtifactImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisArtifactPtr(element);
	return element;
	
}
std::shared_ptr<Artifact> UmlFactoryImpl::createArtifact_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<ArtifactImpl> element(new ArtifactImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisArtifactPtr(element);
	return element;
	
}
std::shared_ptr<Artifact> UmlFactoryImpl::createArtifact_in_Package(std::weak_ptr<uml::Package > par_package, const int metaElementID) const
{
	std::shared_ptr<ArtifactImpl> element(new ArtifactImpl(par_package, UmlPackage::TYPE_ATTRIBUTE_PACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_package.lock())
	{
			wp->getOwnedType()->push_back(element);
	}
	element->setThisArtifactPtr(element);
	return element;
	
}
std::shared_ptr<Association> UmlFactoryImpl::createAssociation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<AssociationImpl> element(new AssociationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisAssociationPtr(element);
	return element;
}
std::shared_ptr<Association> UmlFactoryImpl::createAssociation_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<AssociationImpl> element(new AssociationImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisAssociationPtr(element);
	return element;
	
}
std::shared_ptr<Association> UmlFactoryImpl::createAssociation_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<AssociationImpl> element(new AssociationImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisAssociationPtr(element);
	return element;
	
}
std::shared_ptr<Association> UmlFactoryImpl::createAssociation_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<AssociationImpl> element(new AssociationImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisAssociationPtr(element);
	return element;
	
}
std::shared_ptr<Association> UmlFactoryImpl::createAssociation_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<AssociationImpl> element(new AssociationImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisAssociationPtr(element);
	return element;
	
}
std::shared_ptr<Association> UmlFactoryImpl::createAssociation_in_Package(std::weak_ptr<uml::Package > par_package, const int metaElementID) const
{
	std::shared_ptr<AssociationImpl> element(new AssociationImpl(par_package, UmlPackage::TYPE_ATTRIBUTE_PACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_package.lock())
	{
			wp->getOwnedType()->push_back(element);
	}
	element->setThisAssociationPtr(element);
	return element;
	
}
std::shared_ptr<AssociationClass> UmlFactoryImpl::createAssociationClass(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<AssociationClassImpl> element(new AssociationClassImpl());
	element->setMetaElementID(metaElementID);
	element->setThisAssociationClassPtr(element);
	return element;
}
std::shared_ptr<AssociationClass> UmlFactoryImpl::createAssociationClass_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<AssociationClassImpl> element(new AssociationClassImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisAssociationClassPtr(element);
	return element;
	
}
std::shared_ptr<AssociationClass> UmlFactoryImpl::createAssociationClass_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<AssociationClassImpl> element(new AssociationClassImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisAssociationClassPtr(element);
	return element;
	
}
std::shared_ptr<AssociationClass> UmlFactoryImpl::createAssociationClass_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<AssociationClassImpl> element(new AssociationClassImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisAssociationClassPtr(element);
	return element;
	
}
std::shared_ptr<AssociationClass> UmlFactoryImpl::createAssociationClass_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<AssociationClassImpl> element(new AssociationClassImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisAssociationClassPtr(element);
	return element;
	
}
std::shared_ptr<AssociationClass> UmlFactoryImpl::createAssociationClass_in_Package(std::weak_ptr<uml::Package > par_package, const int metaElementID) const
{
	std::shared_ptr<AssociationClassImpl> element(new AssociationClassImpl(par_package, UmlPackage::TYPE_ATTRIBUTE_PACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_package.lock())
	{
			wp->getOwnedType()->push_back(element);
	}
	element->setThisAssociationClassPtr(element);
	return element;
	
}
std::shared_ptr<BehaviorExecutionSpecification> UmlFactoryImpl::createBehaviorExecutionSpecification(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<BehaviorExecutionSpecificationImpl> element(new BehaviorExecutionSpecificationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisBehaviorExecutionSpecificationPtr(element);
	return element;
}
std::shared_ptr<BehaviorExecutionSpecification> UmlFactoryImpl::createBehaviorExecutionSpecification_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction, const int metaElementID) const
{
	std::shared_ptr<BehaviorExecutionSpecificationImpl> element(new BehaviorExecutionSpecificationImpl(par_enclosingInteraction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_enclosingInteraction.lock())
	{
			wp->getFragment()->push_back(element);
	}
	element->setThisBehaviorExecutionSpecificationPtr(element);
	return element;
	
}
std::shared_ptr<BehaviorExecutionSpecification> UmlFactoryImpl::createBehaviorExecutionSpecification_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand, const int metaElementID) const
{
	std::shared_ptr<BehaviorExecutionSpecificationImpl> element(new BehaviorExecutionSpecificationImpl(par_enclosingOperand));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_enclosingOperand.lock())
	{
			wp->getFragment()->push_back(element);
	}
	element->setThisBehaviorExecutionSpecificationPtr(element);
	return element;
	
}
std::shared_ptr<BehaviorExecutionSpecification> UmlFactoryImpl::createBehaviorExecutionSpecification_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<BehaviorExecutionSpecificationImpl> element(new BehaviorExecutionSpecificationImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisBehaviorExecutionSpecificationPtr(element);
	return element;
	
}
std::shared_ptr<BehaviorExecutionSpecification> UmlFactoryImpl::createBehaviorExecutionSpecification_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<BehaviorExecutionSpecificationImpl> element(new BehaviorExecutionSpecificationImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisBehaviorExecutionSpecificationPtr(element);
	return element;
	
}
std::shared_ptr<BroadcastSignalAction> UmlFactoryImpl::createBroadcastSignalAction(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<BroadcastSignalActionImpl> element(new BroadcastSignalActionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisBroadcastSignalActionPtr(element);
	return element;
}
std::shared_ptr<BroadcastSignalAction> UmlFactoryImpl::createBroadcastSignalAction_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<BroadcastSignalActionImpl> element(new BroadcastSignalActionImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisBroadcastSignalActionPtr(element);
	return element;
	
}
std::shared_ptr<BroadcastSignalAction> UmlFactoryImpl::createBroadcastSignalAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<BroadcastSignalActionImpl> element(new BroadcastSignalActionImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisBroadcastSignalActionPtr(element);
	return element;
	
}
std::shared_ptr<BroadcastSignalAction> UmlFactoryImpl::createBroadcastSignalAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<BroadcastSignalActionImpl> element(new BroadcastSignalActionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisBroadcastSignalActionPtr(element);
	return element;
	
}
std::shared_ptr<BroadcastSignalAction> UmlFactoryImpl::createBroadcastSignalAction_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<BroadcastSignalActionImpl> element(new BroadcastSignalActionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisBroadcastSignalActionPtr(element);
	return element;
	
}
std::shared_ptr<CallBehaviorAction> UmlFactoryImpl::createCallBehaviorAction(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<CallBehaviorActionImpl> element(new CallBehaviorActionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCallBehaviorActionPtr(element);
	return element;
}
std::shared_ptr<CallBehaviorAction> UmlFactoryImpl::createCallBehaviorAction_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<CallBehaviorActionImpl> element(new CallBehaviorActionImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisCallBehaviorActionPtr(element);
	return element;
	
}
std::shared_ptr<CallBehaviorAction> UmlFactoryImpl::createCallBehaviorAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<CallBehaviorActionImpl> element(new CallBehaviorActionImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisCallBehaviorActionPtr(element);
	return element;
	
}
std::shared_ptr<CallBehaviorAction> UmlFactoryImpl::createCallBehaviorAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<CallBehaviorActionImpl> element(new CallBehaviorActionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisCallBehaviorActionPtr(element);
	return element;
	
}
std::shared_ptr<CallBehaviorAction> UmlFactoryImpl::createCallBehaviorAction_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<CallBehaviorActionImpl> element(new CallBehaviorActionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisCallBehaviorActionPtr(element);
	return element;
	
}
std::shared_ptr<CallEvent> UmlFactoryImpl::createCallEvent(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<CallEventImpl> element(new CallEventImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCallEventPtr(element);
	return element;
}
std::shared_ptr<CallEvent> UmlFactoryImpl::createCallEvent_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<CallEventImpl> element(new CallEventImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisCallEventPtr(element);
	return element;
	
}
std::shared_ptr<CallEvent> UmlFactoryImpl::createCallEvent_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<CallEventImpl> element(new CallEventImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisCallEventPtr(element);
	return element;
	
}
std::shared_ptr<CallEvent> UmlFactoryImpl::createCallEvent_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<CallEventImpl> element(new CallEventImpl(par_owningPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisCallEventPtr(element);
	return element;
	
}
std::shared_ptr<CallEvent> UmlFactoryImpl::createCallEvent_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<CallEventImpl> element(new CallEventImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisCallEventPtr(element);
	return element;
	
}
std::shared_ptr<CallOperationAction> UmlFactoryImpl::createCallOperationAction(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<CallOperationActionImpl> element(new CallOperationActionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCallOperationActionPtr(element);
	return element;
}
std::shared_ptr<CallOperationAction> UmlFactoryImpl::createCallOperationAction_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<CallOperationActionImpl> element(new CallOperationActionImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisCallOperationActionPtr(element);
	return element;
	
}
std::shared_ptr<CallOperationAction> UmlFactoryImpl::createCallOperationAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<CallOperationActionImpl> element(new CallOperationActionImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisCallOperationActionPtr(element);
	return element;
	
}
std::shared_ptr<CallOperationAction> UmlFactoryImpl::createCallOperationAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<CallOperationActionImpl> element(new CallOperationActionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisCallOperationActionPtr(element);
	return element;
	
}
std::shared_ptr<CallOperationAction> UmlFactoryImpl::createCallOperationAction_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<CallOperationActionImpl> element(new CallOperationActionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisCallOperationActionPtr(element);
	return element;
	
}
std::shared_ptr<CentralBufferNode> UmlFactoryImpl::createCentralBufferNode(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<CentralBufferNodeImpl> element(new CentralBufferNodeImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCentralBufferNodePtr(element);
	return element;
}
std::shared_ptr<CentralBufferNode> UmlFactoryImpl::createCentralBufferNode_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<CentralBufferNodeImpl> element(new CentralBufferNodeImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisCentralBufferNodePtr(element);
	return element;
	
}
std::shared_ptr<CentralBufferNode> UmlFactoryImpl::createCentralBufferNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<CentralBufferNodeImpl> element(new CentralBufferNodeImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisCentralBufferNodePtr(element);
	return element;
	
}
std::shared_ptr<CentralBufferNode> UmlFactoryImpl::createCentralBufferNode_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<CentralBufferNodeImpl> element(new CentralBufferNodeImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisCentralBufferNodePtr(element);
	return element;
	
}
std::shared_ptr<CentralBufferNode> UmlFactoryImpl::createCentralBufferNode_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<CentralBufferNodeImpl> element(new CentralBufferNodeImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisCentralBufferNodePtr(element);
	return element;
	
}
std::shared_ptr<ChangeEvent> UmlFactoryImpl::createChangeEvent(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ChangeEventImpl> element(new ChangeEventImpl());
	element->setMetaElementID(metaElementID);
	element->setThisChangeEventPtr(element);
	return element;
}
std::shared_ptr<ChangeEvent> UmlFactoryImpl::createChangeEvent_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ChangeEventImpl> element(new ChangeEventImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisChangeEventPtr(element);
	return element;
	
}
std::shared_ptr<ChangeEvent> UmlFactoryImpl::createChangeEvent_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ChangeEventImpl> element(new ChangeEventImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisChangeEventPtr(element);
	return element;
	
}
std::shared_ptr<ChangeEvent> UmlFactoryImpl::createChangeEvent_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<ChangeEventImpl> element(new ChangeEventImpl(par_owningPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisChangeEventPtr(element);
	return element;
	
}
std::shared_ptr<ChangeEvent> UmlFactoryImpl::createChangeEvent_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<ChangeEventImpl> element(new ChangeEventImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisChangeEventPtr(element);
	return element;
	
}
std::shared_ptr<Class> UmlFactoryImpl::createClass(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ClassImpl> element(new ClassImpl());
	element->setMetaElementID(metaElementID);
	element->setThisClassPtr(element);
	return element;
}
std::shared_ptr<Class> UmlFactoryImpl::createClass_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ClassImpl> element(new ClassImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisClassPtr(element);
	return element;
	
}
std::shared_ptr<Class> UmlFactoryImpl::createClass_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ClassImpl> element(new ClassImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisClassPtr(element);
	return element;
	
}
std::shared_ptr<Class> UmlFactoryImpl::createClass_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<ClassImpl> element(new ClassImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisClassPtr(element);
	return element;
	
}
std::shared_ptr<Class> UmlFactoryImpl::createClass_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<ClassImpl> element(new ClassImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisClassPtr(element);
	return element;
	
}
std::shared_ptr<Class> UmlFactoryImpl::createClass_in_Package(std::weak_ptr<uml::Package > par_package, const int metaElementID) const
{
	std::shared_ptr<ClassImpl> element(new ClassImpl(par_package, UmlPackage::TYPE_ATTRIBUTE_PACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_package.lock())
	{
			wp->getOwnedType()->push_back(element);
	}
	element->setThisClassPtr(element);
	return element;
	
}
std::shared_ptr<ClassifierTemplateParameter> UmlFactoryImpl::createClassifierTemplateParameter(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ClassifierTemplateParameterImpl> element(new ClassifierTemplateParameterImpl());
	element->setMetaElementID(metaElementID);
	element->setThisClassifierTemplateParameterPtr(element);
	return element;
}
std::shared_ptr<ClassifierTemplateParameter> UmlFactoryImpl::createClassifierTemplateParameter_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ClassifierTemplateParameterImpl> element(new ClassifierTemplateParameterImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisClassifierTemplateParameterPtr(element);
	return element;
	
}
std::shared_ptr<ClassifierTemplateParameter> UmlFactoryImpl::createClassifierTemplateParameter_in_Signature(std::weak_ptr<uml::TemplateSignature > par_signature, const int metaElementID) const
{
	std::shared_ptr<ClassifierTemplateParameterImpl> element(new ClassifierTemplateParameterImpl(par_signature));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_signature.lock())
	{
			wp->getOwnedParameter()->push_back(element);
	}
	element->setThisClassifierTemplateParameterPtr(element);
	return element;
	
}
std::shared_ptr<Clause> UmlFactoryImpl::createClause(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ClauseImpl> element(new ClauseImpl());
	element->setMetaElementID(metaElementID);
	element->setThisClausePtr(element);
	return element;
}
std::shared_ptr<Clause> UmlFactoryImpl::createClause_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ClauseImpl> element(new ClauseImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisClausePtr(element);
	return element;
	
}
std::shared_ptr<ClearAssociationAction> UmlFactoryImpl::createClearAssociationAction(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ClearAssociationActionImpl> element(new ClearAssociationActionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisClearAssociationActionPtr(element);
	return element;
}
std::shared_ptr<ClearAssociationAction> UmlFactoryImpl::createClearAssociationAction_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<ClearAssociationActionImpl> element(new ClearAssociationActionImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisClearAssociationActionPtr(element);
	return element;
	
}
std::shared_ptr<ClearAssociationAction> UmlFactoryImpl::createClearAssociationAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<ClearAssociationActionImpl> element(new ClearAssociationActionImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisClearAssociationActionPtr(element);
	return element;
	
}
std::shared_ptr<ClearAssociationAction> UmlFactoryImpl::createClearAssociationAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ClearAssociationActionImpl> element(new ClearAssociationActionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisClearAssociationActionPtr(element);
	return element;
	
}
std::shared_ptr<ClearAssociationAction> UmlFactoryImpl::createClearAssociationAction_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ClearAssociationActionImpl> element(new ClearAssociationActionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisClearAssociationActionPtr(element);
	return element;
	
}
std::shared_ptr<ClearStructuralFeatureAction> UmlFactoryImpl::createClearStructuralFeatureAction(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ClearStructuralFeatureActionImpl> element(new ClearStructuralFeatureActionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisClearStructuralFeatureActionPtr(element);
	return element;
}
std::shared_ptr<ClearStructuralFeatureAction> UmlFactoryImpl::createClearStructuralFeatureAction_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<ClearStructuralFeatureActionImpl> element(new ClearStructuralFeatureActionImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisClearStructuralFeatureActionPtr(element);
	return element;
	
}
std::shared_ptr<ClearStructuralFeatureAction> UmlFactoryImpl::createClearStructuralFeatureAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<ClearStructuralFeatureActionImpl> element(new ClearStructuralFeatureActionImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisClearStructuralFeatureActionPtr(element);
	return element;
	
}
std::shared_ptr<ClearStructuralFeatureAction> UmlFactoryImpl::createClearStructuralFeatureAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ClearStructuralFeatureActionImpl> element(new ClearStructuralFeatureActionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisClearStructuralFeatureActionPtr(element);
	return element;
	
}
std::shared_ptr<ClearStructuralFeatureAction> UmlFactoryImpl::createClearStructuralFeatureAction_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ClearStructuralFeatureActionImpl> element(new ClearStructuralFeatureActionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisClearStructuralFeatureActionPtr(element);
	return element;
	
}
std::shared_ptr<ClearVariableAction> UmlFactoryImpl::createClearVariableAction(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ClearVariableActionImpl> element(new ClearVariableActionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisClearVariableActionPtr(element);
	return element;
}
std::shared_ptr<ClearVariableAction> UmlFactoryImpl::createClearVariableAction_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<ClearVariableActionImpl> element(new ClearVariableActionImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisClearVariableActionPtr(element);
	return element;
	
}
std::shared_ptr<ClearVariableAction> UmlFactoryImpl::createClearVariableAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<ClearVariableActionImpl> element(new ClearVariableActionImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisClearVariableActionPtr(element);
	return element;
	
}
std::shared_ptr<ClearVariableAction> UmlFactoryImpl::createClearVariableAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ClearVariableActionImpl> element(new ClearVariableActionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisClearVariableActionPtr(element);
	return element;
	
}
std::shared_ptr<ClearVariableAction> UmlFactoryImpl::createClearVariableAction_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ClearVariableActionImpl> element(new ClearVariableActionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisClearVariableActionPtr(element);
	return element;
	
}
std::shared_ptr<Collaboration> UmlFactoryImpl::createCollaboration(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<CollaborationImpl> element(new CollaborationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCollaborationPtr(element);
	return element;
}
std::shared_ptr<Collaboration> UmlFactoryImpl::createCollaboration_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<CollaborationImpl> element(new CollaborationImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisCollaborationPtr(element);
	return element;
	
}
std::shared_ptr<Collaboration> UmlFactoryImpl::createCollaboration_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<CollaborationImpl> element(new CollaborationImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisCollaborationPtr(element);
	return element;
	
}
std::shared_ptr<Collaboration> UmlFactoryImpl::createCollaboration_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<CollaborationImpl> element(new CollaborationImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisCollaborationPtr(element);
	return element;
	
}
std::shared_ptr<Collaboration> UmlFactoryImpl::createCollaboration_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<CollaborationImpl> element(new CollaborationImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisCollaborationPtr(element);
	return element;
	
}
std::shared_ptr<Collaboration> UmlFactoryImpl::createCollaboration_in_Package(std::weak_ptr<uml::Package > par_package, const int metaElementID) const
{
	std::shared_ptr<CollaborationImpl> element(new CollaborationImpl(par_package, UmlPackage::TYPE_ATTRIBUTE_PACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_package.lock())
	{
			wp->getOwnedType()->push_back(element);
	}
	element->setThisCollaborationPtr(element);
	return element;
	
}
std::shared_ptr<CollaborationUse> UmlFactoryImpl::createCollaborationUse(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<CollaborationUseImpl> element(new CollaborationUseImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCollaborationUsePtr(element);
	return element;
}
std::shared_ptr<CollaborationUse> UmlFactoryImpl::createCollaborationUse_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<CollaborationUseImpl> element(new CollaborationUseImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisCollaborationUsePtr(element);
	return element;
	
}
std::shared_ptr<CollaborationUse> UmlFactoryImpl::createCollaborationUse_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<CollaborationUseImpl> element(new CollaborationUseImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisCollaborationUsePtr(element);
	return element;
	
}
std::shared_ptr<CombinedFragment> UmlFactoryImpl::createCombinedFragment(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<CombinedFragmentImpl> element(new CombinedFragmentImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCombinedFragmentPtr(element);
	return element;
}
std::shared_ptr<CombinedFragment> UmlFactoryImpl::createCombinedFragment_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction, const int metaElementID) const
{
	std::shared_ptr<CombinedFragmentImpl> element(new CombinedFragmentImpl(par_enclosingInteraction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_enclosingInteraction.lock())
	{
			wp->getFragment()->push_back(element);
	}
	element->setThisCombinedFragmentPtr(element);
	return element;
	
}
std::shared_ptr<CombinedFragment> UmlFactoryImpl::createCombinedFragment_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand, const int metaElementID) const
{
	std::shared_ptr<CombinedFragmentImpl> element(new CombinedFragmentImpl(par_enclosingOperand));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_enclosingOperand.lock())
	{
			wp->getFragment()->push_back(element);
	}
	element->setThisCombinedFragmentPtr(element);
	return element;
	
}
std::shared_ptr<CombinedFragment> UmlFactoryImpl::createCombinedFragment_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<CombinedFragmentImpl> element(new CombinedFragmentImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisCombinedFragmentPtr(element);
	return element;
	
}
std::shared_ptr<CombinedFragment> UmlFactoryImpl::createCombinedFragment_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<CombinedFragmentImpl> element(new CombinedFragmentImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisCombinedFragmentPtr(element);
	return element;
	
}
std::shared_ptr<Comment> UmlFactoryImpl::createComment(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<CommentImpl> element(new CommentImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCommentPtr(element);
	return element;
}
std::shared_ptr<Comment> UmlFactoryImpl::createComment_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<CommentImpl> element(new CommentImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedComment()->push_back(element);
	}
	element->setThisCommentPtr(element);
	return element;
	
}
std::shared_ptr<CommunicationPath> UmlFactoryImpl::createCommunicationPath(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<CommunicationPathImpl> element(new CommunicationPathImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCommunicationPathPtr(element);
	return element;
}
std::shared_ptr<CommunicationPath> UmlFactoryImpl::createCommunicationPath_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<CommunicationPathImpl> element(new CommunicationPathImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisCommunicationPathPtr(element);
	return element;
	
}
std::shared_ptr<CommunicationPath> UmlFactoryImpl::createCommunicationPath_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<CommunicationPathImpl> element(new CommunicationPathImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisCommunicationPathPtr(element);
	return element;
	
}
std::shared_ptr<CommunicationPath> UmlFactoryImpl::createCommunicationPath_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<CommunicationPathImpl> element(new CommunicationPathImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisCommunicationPathPtr(element);
	return element;
	
}
std::shared_ptr<CommunicationPath> UmlFactoryImpl::createCommunicationPath_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<CommunicationPathImpl> element(new CommunicationPathImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisCommunicationPathPtr(element);
	return element;
	
}
std::shared_ptr<CommunicationPath> UmlFactoryImpl::createCommunicationPath_in_Package(std::weak_ptr<uml::Package > par_package, const int metaElementID) const
{
	std::shared_ptr<CommunicationPathImpl> element(new CommunicationPathImpl(par_package, UmlPackage::TYPE_ATTRIBUTE_PACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_package.lock())
	{
			wp->getOwnedType()->push_back(element);
	}
	element->setThisCommunicationPathPtr(element);
	return element;
	
}
std::shared_ptr<Component> UmlFactoryImpl::createComponent(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ComponentImpl> element(new ComponentImpl());
	element->setMetaElementID(metaElementID);
	element->setThisComponentPtr(element);
	return element;
}
std::shared_ptr<Component> UmlFactoryImpl::createComponent_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ComponentImpl> element(new ComponentImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisComponentPtr(element);
	return element;
	
}
std::shared_ptr<Component> UmlFactoryImpl::createComponent_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ComponentImpl> element(new ComponentImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisComponentPtr(element);
	return element;
	
}
std::shared_ptr<Component> UmlFactoryImpl::createComponent_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<ComponentImpl> element(new ComponentImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisComponentPtr(element);
	return element;
	
}
std::shared_ptr<Component> UmlFactoryImpl::createComponent_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<ComponentImpl> element(new ComponentImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisComponentPtr(element);
	return element;
	
}
std::shared_ptr<Component> UmlFactoryImpl::createComponent_in_Package(std::weak_ptr<uml::Package > par_package, const int metaElementID) const
{
	std::shared_ptr<ComponentImpl> element(new ComponentImpl(par_package, UmlPackage::TYPE_ATTRIBUTE_PACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_package.lock())
	{
			wp->getOwnedType()->push_back(element);
	}
	element->setThisComponentPtr(element);
	return element;
	
}
std::shared_ptr<ComponentRealization> UmlFactoryImpl::createComponentRealization(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ComponentRealizationImpl> element(new ComponentRealizationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisComponentRealizationPtr(element);
	return element;
}
std::shared_ptr<ComponentRealization> UmlFactoryImpl::createComponentRealization_in_Abstraction(std::weak_ptr<uml::Component > par_abstraction, const int metaElementID) const
{
	std::shared_ptr<ComponentRealizationImpl> element(new ComponentRealizationImpl(par_abstraction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_abstraction.lock())
	{
			wp->getRealization()->push_back(element);
	}
	element->setThisComponentRealizationPtr(element);
	return element;
	
}
std::shared_ptr<ComponentRealization> UmlFactoryImpl::createComponentRealization_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ComponentRealizationImpl> element(new ComponentRealizationImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisComponentRealizationPtr(element);
	return element;
	
}
std::shared_ptr<ComponentRealization> UmlFactoryImpl::createComponentRealization_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ComponentRealizationImpl> element(new ComponentRealizationImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisComponentRealizationPtr(element);
	return element;
	
}
std::shared_ptr<ComponentRealization> UmlFactoryImpl::createComponentRealization_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<ComponentRealizationImpl> element(new ComponentRealizationImpl(par_owningPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisComponentRealizationPtr(element);
	return element;
	
}
std::shared_ptr<ComponentRealization> UmlFactoryImpl::createComponentRealization_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<ComponentRealizationImpl> element(new ComponentRealizationImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisComponentRealizationPtr(element);
	return element;
	
}
std::shared_ptr<ConditionalNode> UmlFactoryImpl::createConditionalNode(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ConditionalNodeImpl> element(new ConditionalNodeImpl());
	element->setMetaElementID(metaElementID);
	element->setThisConditionalNodePtr(element);
	return element;
}
std::shared_ptr<ConditionalNode> UmlFactoryImpl::createConditionalNode_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<ConditionalNodeImpl> element(new ConditionalNodeImpl(par_activity, UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisConditionalNodePtr(element);
	return element;
	
}
std::shared_ptr<ConditionalNode> UmlFactoryImpl::createConditionalNode_in_InActivity(std::weak_ptr<uml::Activity > par_inActivity, const int metaElementID) const
{
	std::shared_ptr<ConditionalNodeImpl> element(new ConditionalNodeImpl(par_inActivity, UmlPackage::ACTIVITYGROUP_ATTRIBUTE_INACTIVITY));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inActivity.lock())
	{
			wp->getGroup()->push_back(element);
	}
	element->setThisConditionalNodePtr(element);
	return element;
	
}
std::shared_ptr<ConditionalNode> UmlFactoryImpl::createConditionalNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<ConditionalNodeImpl> element(new ConditionalNodeImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisConditionalNodePtr(element);
	return element;
	
}
std::shared_ptr<ConditionalNode> UmlFactoryImpl::createConditionalNode_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ConditionalNodeImpl> element(new ConditionalNodeImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisConditionalNodePtr(element);
	return element;
	
}
std::shared_ptr<ConditionalNode> UmlFactoryImpl::createConditionalNode_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ConditionalNodeImpl> element(new ConditionalNodeImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisConditionalNodePtr(element);
	return element;
	
}
std::shared_ptr<ConditionalNode> UmlFactoryImpl::createConditionalNode_in_SuperGroup(std::weak_ptr<uml::ActivityGroup > par_superGroup, const int metaElementID) const
{
	std::shared_ptr<ConditionalNodeImpl> element(new ConditionalNodeImpl(par_superGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_superGroup.lock())
	{
			wp->getSubgroup()->push_back(element);
	}
	element->setThisConditionalNodePtr(element);
	return element;
	
}
std::shared_ptr<ConnectableElementTemplateParameter> UmlFactoryImpl::createConnectableElementTemplateParameter(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ConnectableElementTemplateParameterImpl> element(new ConnectableElementTemplateParameterImpl());
	element->setMetaElementID(metaElementID);
	element->setThisConnectableElementTemplateParameterPtr(element);
	return element;
}
std::shared_ptr<ConnectableElementTemplateParameter> UmlFactoryImpl::createConnectableElementTemplateParameter_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ConnectableElementTemplateParameterImpl> element(new ConnectableElementTemplateParameterImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisConnectableElementTemplateParameterPtr(element);
	return element;
	
}
std::shared_ptr<ConnectableElementTemplateParameter> UmlFactoryImpl::createConnectableElementTemplateParameter_in_Signature(std::weak_ptr<uml::TemplateSignature > par_signature, const int metaElementID) const
{
	std::shared_ptr<ConnectableElementTemplateParameterImpl> element(new ConnectableElementTemplateParameterImpl(par_signature));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_signature.lock())
	{
			wp->getOwnedParameter()->push_back(element);
	}
	element->setThisConnectableElementTemplateParameterPtr(element);
	return element;
	
}
std::shared_ptr<ConnectionPointReference> UmlFactoryImpl::createConnectionPointReference(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ConnectionPointReferenceImpl> element(new ConnectionPointReferenceImpl());
	element->setMetaElementID(metaElementID);
	element->setThisConnectionPointReferencePtr(element);
	return element;
}
std::shared_ptr<ConnectionPointReference> UmlFactoryImpl::createConnectionPointReference_in_Container(std::weak_ptr<uml::Region > par_container, const int metaElementID) const
{
	std::shared_ptr<ConnectionPointReferenceImpl> element(new ConnectionPointReferenceImpl(par_container));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_container.lock())
	{
			wp->getSubvertex()->push_back(element);
	}
	element->setThisConnectionPointReferencePtr(element);
	return element;
	
}
std::shared_ptr<ConnectionPointReference> UmlFactoryImpl::createConnectionPointReference_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ConnectionPointReferenceImpl> element(new ConnectionPointReferenceImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisConnectionPointReferencePtr(element);
	return element;
	
}
std::shared_ptr<ConnectionPointReference> UmlFactoryImpl::createConnectionPointReference_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ConnectionPointReferenceImpl> element(new ConnectionPointReferenceImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisConnectionPointReferencePtr(element);
	return element;
	
}
std::shared_ptr<ConnectionPointReference> UmlFactoryImpl::createConnectionPointReference_in_State(std::weak_ptr<uml::State > par_state, const int metaElementID) const
{
	std::shared_ptr<ConnectionPointReferenceImpl> element(new ConnectionPointReferenceImpl(par_state));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_state.lock())
	{
			wp->getConnection()->push_back(element);
	}
	element->setThisConnectionPointReferencePtr(element);
	return element;
	
}
std::shared_ptr<Connector> UmlFactoryImpl::createConnector(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ConnectorImpl> element(new ConnectorImpl());
	element->setMetaElementID(metaElementID);
	element->setThisConnectorPtr(element);
	return element;
}
std::shared_ptr<Connector> UmlFactoryImpl::createConnector_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ConnectorImpl> element(new ConnectorImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisConnectorPtr(element);
	return element;
	
}
std::shared_ptr<Connector> UmlFactoryImpl::createConnector_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ConnectorImpl> element(new ConnectorImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisConnectorPtr(element);
	return element;
	
}
std::shared_ptr<ConnectorEnd> UmlFactoryImpl::createConnectorEnd(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ConnectorEndImpl> element(new ConnectorEndImpl());
	element->setMetaElementID(metaElementID);
	element->setThisConnectorEndPtr(element);
	return element;
}
std::shared_ptr<ConnectorEnd> UmlFactoryImpl::createConnectorEnd_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ConnectorEndImpl> element(new ConnectorEndImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisConnectorEndPtr(element);
	return element;
	
}
std::shared_ptr<ConsiderIgnoreFragment> UmlFactoryImpl::createConsiderIgnoreFragment(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ConsiderIgnoreFragmentImpl> element(new ConsiderIgnoreFragmentImpl());
	element->setMetaElementID(metaElementID);
	element->setThisConsiderIgnoreFragmentPtr(element);
	return element;
}
std::shared_ptr<ConsiderIgnoreFragment> UmlFactoryImpl::createConsiderIgnoreFragment_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction, const int metaElementID) const
{
	std::shared_ptr<ConsiderIgnoreFragmentImpl> element(new ConsiderIgnoreFragmentImpl(par_enclosingInteraction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_enclosingInteraction.lock())
	{
			wp->getFragment()->push_back(element);
	}
	element->setThisConsiderIgnoreFragmentPtr(element);
	return element;
	
}
std::shared_ptr<ConsiderIgnoreFragment> UmlFactoryImpl::createConsiderIgnoreFragment_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand, const int metaElementID) const
{
	std::shared_ptr<ConsiderIgnoreFragmentImpl> element(new ConsiderIgnoreFragmentImpl(par_enclosingOperand));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_enclosingOperand.lock())
	{
			wp->getFragment()->push_back(element);
	}
	element->setThisConsiderIgnoreFragmentPtr(element);
	return element;
	
}
std::shared_ptr<ConsiderIgnoreFragment> UmlFactoryImpl::createConsiderIgnoreFragment_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ConsiderIgnoreFragmentImpl> element(new ConsiderIgnoreFragmentImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisConsiderIgnoreFragmentPtr(element);
	return element;
	
}
std::shared_ptr<ConsiderIgnoreFragment> UmlFactoryImpl::createConsiderIgnoreFragment_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ConsiderIgnoreFragmentImpl> element(new ConsiderIgnoreFragmentImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisConsiderIgnoreFragmentPtr(element);
	return element;
	
}
std::shared_ptr<Constraint> UmlFactoryImpl::createConstraint(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ConstraintImpl> element(new ConstraintImpl());
	element->setMetaElementID(metaElementID);
	element->setThisConstraintPtr(element);
	return element;
}
std::shared_ptr<Constraint> UmlFactoryImpl::createConstraint_in_Context(std::weak_ptr<uml::Namespace > par_context, const int metaElementID) const
{
	std::shared_ptr<ConstraintImpl> element(new ConstraintImpl(par_context, UmlPackage::CONSTRAINT_ATTRIBUTE_CONTEXT));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_context.lock())
	{
			wp->getOwnedRule()->push_back(element);
	}
	element->setThisConstraintPtr(element);
	return element;
	
}
std::shared_ptr<Constraint> UmlFactoryImpl::createConstraint_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ConstraintImpl> element(new ConstraintImpl(par_namespace, UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedRule()->push_back(element);
	}
	element->setThisConstraintPtr(element);
	return element;
	
}
std::shared_ptr<Constraint> UmlFactoryImpl::createConstraint_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ConstraintImpl> element(new ConstraintImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisConstraintPtr(element);
	return element;
	
}
std::shared_ptr<Constraint> UmlFactoryImpl::createConstraint_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<ConstraintImpl> element(new ConstraintImpl(par_owningPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisConstraintPtr(element);
	return element;
	
}
std::shared_ptr<Constraint> UmlFactoryImpl::createConstraint_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<ConstraintImpl> element(new ConstraintImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisConstraintPtr(element);
	return element;
	
}
std::shared_ptr<Continuation> UmlFactoryImpl::createContinuation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ContinuationImpl> element(new ContinuationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisContinuationPtr(element);
	return element;
}
std::shared_ptr<Continuation> UmlFactoryImpl::createContinuation_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction, const int metaElementID) const
{
	std::shared_ptr<ContinuationImpl> element(new ContinuationImpl(par_enclosingInteraction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_enclosingInteraction.lock())
	{
			wp->getFragment()->push_back(element);
	}
	element->setThisContinuationPtr(element);
	return element;
	
}
std::shared_ptr<Continuation> UmlFactoryImpl::createContinuation_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand, const int metaElementID) const
{
	std::shared_ptr<ContinuationImpl> element(new ContinuationImpl(par_enclosingOperand));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_enclosingOperand.lock())
	{
			wp->getFragment()->push_back(element);
	}
	element->setThisContinuationPtr(element);
	return element;
	
}
std::shared_ptr<Continuation> UmlFactoryImpl::createContinuation_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ContinuationImpl> element(new ContinuationImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisContinuationPtr(element);
	return element;
	
}
std::shared_ptr<Continuation> UmlFactoryImpl::createContinuation_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ContinuationImpl> element(new ContinuationImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisContinuationPtr(element);
	return element;
	
}
std::shared_ptr<ControlFlow> UmlFactoryImpl::createControlFlow(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ControlFlowImpl> element(new ControlFlowImpl());
	element->setMetaElementID(metaElementID);
	element->setThisControlFlowPtr(element);
	return element;
}
std::shared_ptr<ControlFlow> UmlFactoryImpl::createControlFlow_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<ControlFlowImpl> element(new ControlFlowImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getEdge()->push_back(element);
	}
	element->setThisControlFlowPtr(element);
	return element;
	
}
std::shared_ptr<ControlFlow> UmlFactoryImpl::createControlFlow_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<ControlFlowImpl> element(new ControlFlowImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getEdge()->push_back(element);
	}
	element->setThisControlFlowPtr(element);
	return element;
	
}
std::shared_ptr<ControlFlow> UmlFactoryImpl::createControlFlow_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ControlFlowImpl> element(new ControlFlowImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisControlFlowPtr(element);
	return element;
	
}
std::shared_ptr<ControlFlow> UmlFactoryImpl::createControlFlow_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ControlFlowImpl> element(new ControlFlowImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisControlFlowPtr(element);
	return element;
	
}
std::shared_ptr<CreateLinkAction> UmlFactoryImpl::createCreateLinkAction(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<CreateLinkActionImpl> element(new CreateLinkActionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCreateLinkActionPtr(element);
	return element;
}
std::shared_ptr<CreateLinkAction> UmlFactoryImpl::createCreateLinkAction_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<CreateLinkActionImpl> element(new CreateLinkActionImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisCreateLinkActionPtr(element);
	return element;
	
}
std::shared_ptr<CreateLinkAction> UmlFactoryImpl::createCreateLinkAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<CreateLinkActionImpl> element(new CreateLinkActionImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisCreateLinkActionPtr(element);
	return element;
	
}
std::shared_ptr<CreateLinkAction> UmlFactoryImpl::createCreateLinkAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<CreateLinkActionImpl> element(new CreateLinkActionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisCreateLinkActionPtr(element);
	return element;
	
}
std::shared_ptr<CreateLinkAction> UmlFactoryImpl::createCreateLinkAction_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<CreateLinkActionImpl> element(new CreateLinkActionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisCreateLinkActionPtr(element);
	return element;
	
}
std::shared_ptr<CreateLinkObjectAction> UmlFactoryImpl::createCreateLinkObjectAction(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<CreateLinkObjectActionImpl> element(new CreateLinkObjectActionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCreateLinkObjectActionPtr(element);
	return element;
}
std::shared_ptr<CreateLinkObjectAction> UmlFactoryImpl::createCreateLinkObjectAction_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<CreateLinkObjectActionImpl> element(new CreateLinkObjectActionImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisCreateLinkObjectActionPtr(element);
	return element;
	
}
std::shared_ptr<CreateLinkObjectAction> UmlFactoryImpl::createCreateLinkObjectAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<CreateLinkObjectActionImpl> element(new CreateLinkObjectActionImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisCreateLinkObjectActionPtr(element);
	return element;
	
}
std::shared_ptr<CreateLinkObjectAction> UmlFactoryImpl::createCreateLinkObjectAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<CreateLinkObjectActionImpl> element(new CreateLinkObjectActionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisCreateLinkObjectActionPtr(element);
	return element;
	
}
std::shared_ptr<CreateLinkObjectAction> UmlFactoryImpl::createCreateLinkObjectAction_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<CreateLinkObjectActionImpl> element(new CreateLinkObjectActionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisCreateLinkObjectActionPtr(element);
	return element;
	
}
std::shared_ptr<CreateObjectAction> UmlFactoryImpl::createCreateObjectAction(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<CreateObjectActionImpl> element(new CreateObjectActionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisCreateObjectActionPtr(element);
	return element;
}
std::shared_ptr<CreateObjectAction> UmlFactoryImpl::createCreateObjectAction_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<CreateObjectActionImpl> element(new CreateObjectActionImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisCreateObjectActionPtr(element);
	return element;
	
}
std::shared_ptr<CreateObjectAction> UmlFactoryImpl::createCreateObjectAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<CreateObjectActionImpl> element(new CreateObjectActionImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisCreateObjectActionPtr(element);
	return element;
	
}
std::shared_ptr<CreateObjectAction> UmlFactoryImpl::createCreateObjectAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<CreateObjectActionImpl> element(new CreateObjectActionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisCreateObjectActionPtr(element);
	return element;
	
}
std::shared_ptr<CreateObjectAction> UmlFactoryImpl::createCreateObjectAction_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<CreateObjectActionImpl> element(new CreateObjectActionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisCreateObjectActionPtr(element);
	return element;
	
}
std::shared_ptr<DataStoreNode> UmlFactoryImpl::createDataStoreNode(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<DataStoreNodeImpl> element(new DataStoreNodeImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDataStoreNodePtr(element);
	return element;
}
std::shared_ptr<DataStoreNode> UmlFactoryImpl::createDataStoreNode_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<DataStoreNodeImpl> element(new DataStoreNodeImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisDataStoreNodePtr(element);
	return element;
	
}
std::shared_ptr<DataStoreNode> UmlFactoryImpl::createDataStoreNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<DataStoreNodeImpl> element(new DataStoreNodeImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisDataStoreNodePtr(element);
	return element;
	
}
std::shared_ptr<DataStoreNode> UmlFactoryImpl::createDataStoreNode_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<DataStoreNodeImpl> element(new DataStoreNodeImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisDataStoreNodePtr(element);
	return element;
	
}
std::shared_ptr<DataStoreNode> UmlFactoryImpl::createDataStoreNode_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<DataStoreNodeImpl> element(new DataStoreNodeImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisDataStoreNodePtr(element);
	return element;
	
}
std::shared_ptr<DataType> UmlFactoryImpl::createDataType(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<DataTypeImpl> element(new DataTypeImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDataTypePtr(element);
	return element;
}
std::shared_ptr<DataType> UmlFactoryImpl::createDataType_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<DataTypeImpl> element(new DataTypeImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisDataTypePtr(element);
	return element;
	
}
std::shared_ptr<DataType> UmlFactoryImpl::createDataType_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<DataTypeImpl> element(new DataTypeImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisDataTypePtr(element);
	return element;
	
}
std::shared_ptr<DataType> UmlFactoryImpl::createDataType_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<DataTypeImpl> element(new DataTypeImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisDataTypePtr(element);
	return element;
	
}
std::shared_ptr<DataType> UmlFactoryImpl::createDataType_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<DataTypeImpl> element(new DataTypeImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisDataTypePtr(element);
	return element;
	
}
std::shared_ptr<DataType> UmlFactoryImpl::createDataType_in_Package(std::weak_ptr<uml::Package > par_package, const int metaElementID) const
{
	std::shared_ptr<DataTypeImpl> element(new DataTypeImpl(par_package, UmlPackage::TYPE_ATTRIBUTE_PACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_package.lock())
	{
			wp->getOwnedType()->push_back(element);
	}
	element->setThisDataTypePtr(element);
	return element;
	
}
std::shared_ptr<DecisionNode> UmlFactoryImpl::createDecisionNode(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<DecisionNodeImpl> element(new DecisionNodeImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDecisionNodePtr(element);
	return element;
}
std::shared_ptr<DecisionNode> UmlFactoryImpl::createDecisionNode_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<DecisionNodeImpl> element(new DecisionNodeImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisDecisionNodePtr(element);
	return element;
	
}
std::shared_ptr<DecisionNode> UmlFactoryImpl::createDecisionNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<DecisionNodeImpl> element(new DecisionNodeImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisDecisionNodePtr(element);
	return element;
	
}
std::shared_ptr<DecisionNode> UmlFactoryImpl::createDecisionNode_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<DecisionNodeImpl> element(new DecisionNodeImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisDecisionNodePtr(element);
	return element;
	
}
std::shared_ptr<DecisionNode> UmlFactoryImpl::createDecisionNode_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<DecisionNodeImpl> element(new DecisionNodeImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisDecisionNodePtr(element);
	return element;
	
}
std::shared_ptr<Dependency> UmlFactoryImpl::createDependency(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<DependencyImpl> element(new DependencyImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDependencyPtr(element);
	return element;
}
std::shared_ptr<Dependency> UmlFactoryImpl::createDependency_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<DependencyImpl> element(new DependencyImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisDependencyPtr(element);
	return element;
	
}
std::shared_ptr<Dependency> UmlFactoryImpl::createDependency_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<DependencyImpl> element(new DependencyImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisDependencyPtr(element);
	return element;
	
}
std::shared_ptr<Dependency> UmlFactoryImpl::createDependency_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<DependencyImpl> element(new DependencyImpl(par_owningPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisDependencyPtr(element);
	return element;
	
}
std::shared_ptr<Dependency> UmlFactoryImpl::createDependency_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<DependencyImpl> element(new DependencyImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisDependencyPtr(element);
	return element;
	
}
std::shared_ptr<Deployment> UmlFactoryImpl::createDeployment(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<DeploymentImpl> element(new DeploymentImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDeploymentPtr(element);
	return element;
}
std::shared_ptr<Deployment> UmlFactoryImpl::createDeployment_in_Location(std::weak_ptr<uml::DeploymentTarget > par_location, const int metaElementID) const
{
	std::shared_ptr<DeploymentImpl> element(new DeploymentImpl(par_location));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_location.lock())
	{
			wp->getDeployment()->push_back(element);
	}
	element->setThisDeploymentPtr(element);
	return element;
	
}
std::shared_ptr<Deployment> UmlFactoryImpl::createDeployment_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<DeploymentImpl> element(new DeploymentImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisDeploymentPtr(element);
	return element;
	
}
std::shared_ptr<Deployment> UmlFactoryImpl::createDeployment_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<DeploymentImpl> element(new DeploymentImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisDeploymentPtr(element);
	return element;
	
}
std::shared_ptr<Deployment> UmlFactoryImpl::createDeployment_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<DeploymentImpl> element(new DeploymentImpl(par_owningPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisDeploymentPtr(element);
	return element;
	
}
std::shared_ptr<Deployment> UmlFactoryImpl::createDeployment_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<DeploymentImpl> element(new DeploymentImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisDeploymentPtr(element);
	return element;
	
}
std::shared_ptr<DeploymentSpecification> UmlFactoryImpl::createDeploymentSpecification(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<DeploymentSpecificationImpl> element(new DeploymentSpecificationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDeploymentSpecificationPtr(element);
	return element;
}
std::shared_ptr<DeploymentSpecification> UmlFactoryImpl::createDeploymentSpecification_in_Deployment(std::weak_ptr<uml::Deployment > par_deployment, const int metaElementID) const
{
	std::shared_ptr<DeploymentSpecificationImpl> element(new DeploymentSpecificationImpl(par_deployment));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_deployment.lock())
	{
			wp->getConfiguration()->push_back(element);
	}
	element->setThisDeploymentSpecificationPtr(element);
	return element;
	
}
std::shared_ptr<DeploymentSpecification> UmlFactoryImpl::createDeploymentSpecification_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<DeploymentSpecificationImpl> element(new DeploymentSpecificationImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisDeploymentSpecificationPtr(element);
	return element;
	
}
std::shared_ptr<DeploymentSpecification> UmlFactoryImpl::createDeploymentSpecification_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<DeploymentSpecificationImpl> element(new DeploymentSpecificationImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisDeploymentSpecificationPtr(element);
	return element;
	
}
std::shared_ptr<DeploymentSpecification> UmlFactoryImpl::createDeploymentSpecification_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<DeploymentSpecificationImpl> element(new DeploymentSpecificationImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisDeploymentSpecificationPtr(element);
	return element;
	
}
std::shared_ptr<DeploymentSpecification> UmlFactoryImpl::createDeploymentSpecification_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<DeploymentSpecificationImpl> element(new DeploymentSpecificationImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisDeploymentSpecificationPtr(element);
	return element;
	
}
std::shared_ptr<DeploymentSpecification> UmlFactoryImpl::createDeploymentSpecification_in_Package(std::weak_ptr<uml::Package > par_package, const int metaElementID) const
{
	std::shared_ptr<DeploymentSpecificationImpl> element(new DeploymentSpecificationImpl(par_package, UmlPackage::TYPE_ATTRIBUTE_PACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_package.lock())
	{
			wp->getOwnedType()->push_back(element);
	}
	element->setThisDeploymentSpecificationPtr(element);
	return element;
	
}
std::shared_ptr<DestroyLinkAction> UmlFactoryImpl::createDestroyLinkAction(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<DestroyLinkActionImpl> element(new DestroyLinkActionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDestroyLinkActionPtr(element);
	return element;
}
std::shared_ptr<DestroyLinkAction> UmlFactoryImpl::createDestroyLinkAction_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<DestroyLinkActionImpl> element(new DestroyLinkActionImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisDestroyLinkActionPtr(element);
	return element;
	
}
std::shared_ptr<DestroyLinkAction> UmlFactoryImpl::createDestroyLinkAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<DestroyLinkActionImpl> element(new DestroyLinkActionImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisDestroyLinkActionPtr(element);
	return element;
	
}
std::shared_ptr<DestroyLinkAction> UmlFactoryImpl::createDestroyLinkAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<DestroyLinkActionImpl> element(new DestroyLinkActionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisDestroyLinkActionPtr(element);
	return element;
	
}
std::shared_ptr<DestroyLinkAction> UmlFactoryImpl::createDestroyLinkAction_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<DestroyLinkActionImpl> element(new DestroyLinkActionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisDestroyLinkActionPtr(element);
	return element;
	
}
std::shared_ptr<DestroyObjectAction> UmlFactoryImpl::createDestroyObjectAction(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<DestroyObjectActionImpl> element(new DestroyObjectActionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDestroyObjectActionPtr(element);
	return element;
}
std::shared_ptr<DestroyObjectAction> UmlFactoryImpl::createDestroyObjectAction_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<DestroyObjectActionImpl> element(new DestroyObjectActionImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisDestroyObjectActionPtr(element);
	return element;
	
}
std::shared_ptr<DestroyObjectAction> UmlFactoryImpl::createDestroyObjectAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<DestroyObjectActionImpl> element(new DestroyObjectActionImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisDestroyObjectActionPtr(element);
	return element;
	
}
std::shared_ptr<DestroyObjectAction> UmlFactoryImpl::createDestroyObjectAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<DestroyObjectActionImpl> element(new DestroyObjectActionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisDestroyObjectActionPtr(element);
	return element;
	
}
std::shared_ptr<DestroyObjectAction> UmlFactoryImpl::createDestroyObjectAction_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<DestroyObjectActionImpl> element(new DestroyObjectActionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisDestroyObjectActionPtr(element);
	return element;
	
}
std::shared_ptr<DestructionOccurrenceSpecification> UmlFactoryImpl::createDestructionOccurrenceSpecification(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<DestructionOccurrenceSpecificationImpl> element(new DestructionOccurrenceSpecificationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDestructionOccurrenceSpecificationPtr(element);
	return element;
}
std::shared_ptr<DestructionOccurrenceSpecification> UmlFactoryImpl::createDestructionOccurrenceSpecification_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction, const int metaElementID) const
{
	std::shared_ptr<DestructionOccurrenceSpecificationImpl> element(new DestructionOccurrenceSpecificationImpl(par_enclosingInteraction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_enclosingInteraction.lock())
	{
			wp->getFragment()->push_back(element);
	}
	element->setThisDestructionOccurrenceSpecificationPtr(element);
	return element;
	
}
std::shared_ptr<DestructionOccurrenceSpecification> UmlFactoryImpl::createDestructionOccurrenceSpecification_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand, const int metaElementID) const
{
	std::shared_ptr<DestructionOccurrenceSpecificationImpl> element(new DestructionOccurrenceSpecificationImpl(par_enclosingOperand));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_enclosingOperand.lock())
	{
			wp->getFragment()->push_back(element);
	}
	element->setThisDestructionOccurrenceSpecificationPtr(element);
	return element;
	
}
std::shared_ptr<DestructionOccurrenceSpecification> UmlFactoryImpl::createDestructionOccurrenceSpecification_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<DestructionOccurrenceSpecificationImpl> element(new DestructionOccurrenceSpecificationImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisDestructionOccurrenceSpecificationPtr(element);
	return element;
	
}
std::shared_ptr<DestructionOccurrenceSpecification> UmlFactoryImpl::createDestructionOccurrenceSpecification_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<DestructionOccurrenceSpecificationImpl> element(new DestructionOccurrenceSpecificationImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisDestructionOccurrenceSpecificationPtr(element);
	return element;
	
}
std::shared_ptr<Device> UmlFactoryImpl::createDevice(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<DeviceImpl> element(new DeviceImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDevicePtr(element);
	return element;
}
std::shared_ptr<Device> UmlFactoryImpl::createDevice_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<DeviceImpl> element(new DeviceImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisDevicePtr(element);
	return element;
	
}
std::shared_ptr<Device> UmlFactoryImpl::createDevice_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<DeviceImpl> element(new DeviceImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisDevicePtr(element);
	return element;
	
}
std::shared_ptr<Device> UmlFactoryImpl::createDevice_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<DeviceImpl> element(new DeviceImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisDevicePtr(element);
	return element;
	
}
std::shared_ptr<Device> UmlFactoryImpl::createDevice_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<DeviceImpl> element(new DeviceImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisDevicePtr(element);
	return element;
	
}
std::shared_ptr<Device> UmlFactoryImpl::createDevice_in_Package(std::weak_ptr<uml::Package > par_package, const int metaElementID) const
{
	std::shared_ptr<DeviceImpl> element(new DeviceImpl(par_package, UmlPackage::TYPE_ATTRIBUTE_PACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_package.lock())
	{
			wp->getOwnedType()->push_back(element);
	}
	element->setThisDevicePtr(element);
	return element;
	
}
std::shared_ptr<Duration> UmlFactoryImpl::createDuration(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<DurationImpl> element(new DurationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDurationPtr(element);
	return element;
}
std::shared_ptr<Duration> UmlFactoryImpl::createDuration_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<DurationImpl> element(new DurationImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisDurationPtr(element);
	return element;
	
}
std::shared_ptr<Duration> UmlFactoryImpl::createDuration_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<DurationImpl> element(new DurationImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisDurationPtr(element);
	return element;
	
}
std::shared_ptr<Duration> UmlFactoryImpl::createDuration_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<DurationImpl> element(new DurationImpl(par_owningPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisDurationPtr(element);
	return element;
	
}
std::shared_ptr<Duration> UmlFactoryImpl::createDuration_in_OwningSlot(std::weak_ptr<uml::Slot > par_owningSlot, const int metaElementID) const
{
	std::shared_ptr<DurationImpl> element(new DurationImpl(par_owningSlot));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningSlot.lock())
	{
			wp->getValue()->push_back(element);
	}
	element->setThisDurationPtr(element);
	return element;
	
}
std::shared_ptr<Duration> UmlFactoryImpl::createDuration_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<DurationImpl> element(new DurationImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisDurationPtr(element);
	return element;
	
}
std::shared_ptr<Duration> UmlFactoryImpl::createDuration_in_ValueSpecificationAction(std::weak_ptr<uml::ValueSpecificationAction > par_valueSpecificationAction, const int metaElementID) const
{
	std::shared_ptr<DurationImpl> element(new DurationImpl(par_valueSpecificationAction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_valueSpecificationAction.lock())
	{
			wp->setValue(element);
	}
	element->setThisDurationPtr(element);
	return element;
	
}
std::shared_ptr<DurationConstraint> UmlFactoryImpl::createDurationConstraint(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<DurationConstraintImpl> element(new DurationConstraintImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDurationConstraintPtr(element);
	return element;
}
std::shared_ptr<DurationConstraint> UmlFactoryImpl::createDurationConstraint_in_Context(std::weak_ptr<uml::Namespace > par_context, const int metaElementID) const
{
	std::shared_ptr<DurationConstraintImpl> element(new DurationConstraintImpl(par_context, UmlPackage::CONSTRAINT_ATTRIBUTE_CONTEXT));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_context.lock())
	{
			wp->getOwnedRule()->push_back(element);
	}
	element->setThisDurationConstraintPtr(element);
	return element;
	
}
std::shared_ptr<DurationConstraint> UmlFactoryImpl::createDurationConstraint_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<DurationConstraintImpl> element(new DurationConstraintImpl(par_namespace, UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisDurationConstraintPtr(element);
	return element;
	
}
std::shared_ptr<DurationConstraint> UmlFactoryImpl::createDurationConstraint_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<DurationConstraintImpl> element(new DurationConstraintImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisDurationConstraintPtr(element);
	return element;
	
}
std::shared_ptr<DurationConstraint> UmlFactoryImpl::createDurationConstraint_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<DurationConstraintImpl> element(new DurationConstraintImpl(par_owningPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisDurationConstraintPtr(element);
	return element;
	
}
std::shared_ptr<DurationConstraint> UmlFactoryImpl::createDurationConstraint_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<DurationConstraintImpl> element(new DurationConstraintImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisDurationConstraintPtr(element);
	return element;
	
}
std::shared_ptr<DurationInterval> UmlFactoryImpl::createDurationInterval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<DurationIntervalImpl> element(new DurationIntervalImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDurationIntervalPtr(element);
	return element;
}
std::shared_ptr<DurationInterval> UmlFactoryImpl::createDurationInterval_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<DurationIntervalImpl> element(new DurationIntervalImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisDurationIntervalPtr(element);
	return element;
	
}
std::shared_ptr<DurationInterval> UmlFactoryImpl::createDurationInterval_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<DurationIntervalImpl> element(new DurationIntervalImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisDurationIntervalPtr(element);
	return element;
	
}
std::shared_ptr<DurationInterval> UmlFactoryImpl::createDurationInterval_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<DurationIntervalImpl> element(new DurationIntervalImpl(par_owningPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisDurationIntervalPtr(element);
	return element;
	
}
std::shared_ptr<DurationInterval> UmlFactoryImpl::createDurationInterval_in_OwningSlot(std::weak_ptr<uml::Slot > par_owningSlot, const int metaElementID) const
{
	std::shared_ptr<DurationIntervalImpl> element(new DurationIntervalImpl(par_owningSlot));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningSlot.lock())
	{
			wp->getValue()->push_back(element);
	}
	element->setThisDurationIntervalPtr(element);
	return element;
	
}
std::shared_ptr<DurationInterval> UmlFactoryImpl::createDurationInterval_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<DurationIntervalImpl> element(new DurationIntervalImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisDurationIntervalPtr(element);
	return element;
	
}
std::shared_ptr<DurationInterval> UmlFactoryImpl::createDurationInterval_in_ValueSpecificationAction(std::weak_ptr<uml::ValueSpecificationAction > par_valueSpecificationAction, const int metaElementID) const
{
	std::shared_ptr<DurationIntervalImpl> element(new DurationIntervalImpl(par_valueSpecificationAction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_valueSpecificationAction.lock())
	{
			wp->setValue(element);
	}
	element->setThisDurationIntervalPtr(element);
	return element;
	
}
std::shared_ptr<DurationObservation> UmlFactoryImpl::createDurationObservation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<DurationObservationImpl> element(new DurationObservationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisDurationObservationPtr(element);
	return element;
}
std::shared_ptr<DurationObservation> UmlFactoryImpl::createDurationObservation_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<DurationObservationImpl> element(new DurationObservationImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisDurationObservationPtr(element);
	return element;
	
}
std::shared_ptr<DurationObservation> UmlFactoryImpl::createDurationObservation_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<DurationObservationImpl> element(new DurationObservationImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisDurationObservationPtr(element);
	return element;
	
}
std::shared_ptr<DurationObservation> UmlFactoryImpl::createDurationObservation_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<DurationObservationImpl> element(new DurationObservationImpl(par_owningPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisDurationObservationPtr(element);
	return element;
	
}
std::shared_ptr<DurationObservation> UmlFactoryImpl::createDurationObservation_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<DurationObservationImpl> element(new DurationObservationImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisDurationObservationPtr(element);
	return element;
	
}
std::shared_ptr<ElementImport> UmlFactoryImpl::createElementImport(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ElementImportImpl> element(new ElementImportImpl());
	element->setMetaElementID(metaElementID);
	element->setThisElementImportPtr(element);
	return element;
}
std::shared_ptr<ElementImport> UmlFactoryImpl::createElementImport_in_ImportingNamespace(std::weak_ptr<uml::Namespace > par_importingNamespace, const int metaElementID) const
{
	std::shared_ptr<ElementImportImpl> element(new ElementImportImpl(par_importingNamespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_importingNamespace.lock())
	{
			wp->getElementImport()->push_back(element);
	}
	element->setThisElementImportPtr(element);
	return element;
	
}
std::shared_ptr<ElementImport> UmlFactoryImpl::createElementImport_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ElementImportImpl> element(new ElementImportImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisElementImportPtr(element);
	return element;
	
}
std::shared_ptr<Enumeration> UmlFactoryImpl::createEnumeration(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<EnumerationImpl> element(new EnumerationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEnumerationPtr(element);
	return element;
}
std::shared_ptr<Enumeration> UmlFactoryImpl::createEnumeration_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<EnumerationImpl> element(new EnumerationImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisEnumerationPtr(element);
	return element;
	
}
std::shared_ptr<Enumeration> UmlFactoryImpl::createEnumeration_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<EnumerationImpl> element(new EnumerationImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisEnumerationPtr(element);
	return element;
	
}
std::shared_ptr<Enumeration> UmlFactoryImpl::createEnumeration_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<EnumerationImpl> element(new EnumerationImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisEnumerationPtr(element);
	return element;
	
}
std::shared_ptr<Enumeration> UmlFactoryImpl::createEnumeration_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<EnumerationImpl> element(new EnumerationImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisEnumerationPtr(element);
	return element;
	
}
std::shared_ptr<Enumeration> UmlFactoryImpl::createEnumeration_in_Package(std::weak_ptr<uml::Package > par_package, const int metaElementID) const
{
	std::shared_ptr<EnumerationImpl> element(new EnumerationImpl(par_package, UmlPackage::TYPE_ATTRIBUTE_PACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_package.lock())
	{
			wp->getOwnedType()->push_back(element);
	}
	element->setThisEnumerationPtr(element);
	return element;
	
}
std::shared_ptr<EnumerationLiteral> UmlFactoryImpl::createEnumerationLiteral(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<EnumerationLiteralImpl> element(new EnumerationLiteralImpl());
	element->setMetaElementID(metaElementID);
	element->setThisEnumerationLiteralPtr(element);
	return element;
}
std::shared_ptr<EnumerationLiteral> UmlFactoryImpl::createEnumerationLiteral_in_Enumeration(std::weak_ptr<uml::Enumeration > par_enumeration, const int metaElementID) const
{
	std::shared_ptr<EnumerationLiteralImpl> element(new EnumerationLiteralImpl(par_enumeration));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_enumeration.lock())
	{
			wp->getOwnedLiteral()->push_back(element);
	}
	element->setThisEnumerationLiteralPtr(element);
	return element;
	
}
std::shared_ptr<EnumerationLiteral> UmlFactoryImpl::createEnumerationLiteral_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<EnumerationLiteralImpl> element(new EnumerationLiteralImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisEnumerationLiteralPtr(element);
	return element;
	
}
std::shared_ptr<EnumerationLiteral> UmlFactoryImpl::createEnumerationLiteral_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<EnumerationLiteralImpl> element(new EnumerationLiteralImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisEnumerationLiteralPtr(element);
	return element;
	
}
std::shared_ptr<EnumerationLiteral> UmlFactoryImpl::createEnumerationLiteral_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<EnumerationLiteralImpl> element(new EnumerationLiteralImpl(par_owningPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisEnumerationLiteralPtr(element);
	return element;
	
}
std::shared_ptr<EnumerationLiteral> UmlFactoryImpl::createEnumerationLiteral_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<EnumerationLiteralImpl> element(new EnumerationLiteralImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisEnumerationLiteralPtr(element);
	return element;
	
}
std::shared_ptr<ExceptionHandler> UmlFactoryImpl::createExceptionHandler(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ExceptionHandlerImpl> element(new ExceptionHandlerImpl());
	element->setMetaElementID(metaElementID);
	element->setThisExceptionHandlerPtr(element);
	return element;
}
std::shared_ptr<ExceptionHandler> UmlFactoryImpl::createExceptionHandler_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ExceptionHandlerImpl> element(new ExceptionHandlerImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisExceptionHandlerPtr(element);
	return element;
	
}
std::shared_ptr<ExceptionHandler> UmlFactoryImpl::createExceptionHandler_in_ProtectedNode(std::weak_ptr<uml::ExecutableNode > par_protectedNode, const int metaElementID) const
{
	std::shared_ptr<ExceptionHandlerImpl> element(new ExceptionHandlerImpl(par_protectedNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_protectedNode.lock())
	{
			wp->getHandler()->push_back(element);
	}
	element->setThisExceptionHandlerPtr(element);
	return element;
	
}
std::shared_ptr<ExecutionEnvironment> UmlFactoryImpl::createExecutionEnvironment(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ExecutionEnvironmentImpl> element(new ExecutionEnvironmentImpl());
	element->setMetaElementID(metaElementID);
	element->setThisExecutionEnvironmentPtr(element);
	return element;
}
std::shared_ptr<ExecutionEnvironment> UmlFactoryImpl::createExecutionEnvironment_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ExecutionEnvironmentImpl> element(new ExecutionEnvironmentImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisExecutionEnvironmentPtr(element);
	return element;
	
}
std::shared_ptr<ExecutionEnvironment> UmlFactoryImpl::createExecutionEnvironment_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ExecutionEnvironmentImpl> element(new ExecutionEnvironmentImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisExecutionEnvironmentPtr(element);
	return element;
	
}
std::shared_ptr<ExecutionEnvironment> UmlFactoryImpl::createExecutionEnvironment_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<ExecutionEnvironmentImpl> element(new ExecutionEnvironmentImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisExecutionEnvironmentPtr(element);
	return element;
	
}
std::shared_ptr<ExecutionEnvironment> UmlFactoryImpl::createExecutionEnvironment_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<ExecutionEnvironmentImpl> element(new ExecutionEnvironmentImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisExecutionEnvironmentPtr(element);
	return element;
	
}
std::shared_ptr<ExecutionEnvironment> UmlFactoryImpl::createExecutionEnvironment_in_Package(std::weak_ptr<uml::Package > par_package, const int metaElementID) const
{
	std::shared_ptr<ExecutionEnvironmentImpl> element(new ExecutionEnvironmentImpl(par_package, UmlPackage::TYPE_ATTRIBUTE_PACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_package.lock())
	{
			wp->getOwnedType()->push_back(element);
	}
	element->setThisExecutionEnvironmentPtr(element);
	return element;
	
}
std::shared_ptr<ExecutionOccurrenceSpecification> UmlFactoryImpl::createExecutionOccurrenceSpecification(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ExecutionOccurrenceSpecificationImpl> element(new ExecutionOccurrenceSpecificationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisExecutionOccurrenceSpecificationPtr(element);
	return element;
}
std::shared_ptr<ExecutionOccurrenceSpecification> UmlFactoryImpl::createExecutionOccurrenceSpecification_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction, const int metaElementID) const
{
	std::shared_ptr<ExecutionOccurrenceSpecificationImpl> element(new ExecutionOccurrenceSpecificationImpl(par_enclosingInteraction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_enclosingInteraction.lock())
	{
			wp->getFragment()->push_back(element);
	}
	element->setThisExecutionOccurrenceSpecificationPtr(element);
	return element;
	
}
std::shared_ptr<ExecutionOccurrenceSpecification> UmlFactoryImpl::createExecutionOccurrenceSpecification_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand, const int metaElementID) const
{
	std::shared_ptr<ExecutionOccurrenceSpecificationImpl> element(new ExecutionOccurrenceSpecificationImpl(par_enclosingOperand));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_enclosingOperand.lock())
	{
			wp->getFragment()->push_back(element);
	}
	element->setThisExecutionOccurrenceSpecificationPtr(element);
	return element;
	
}
std::shared_ptr<ExecutionOccurrenceSpecification> UmlFactoryImpl::createExecutionOccurrenceSpecification_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ExecutionOccurrenceSpecificationImpl> element(new ExecutionOccurrenceSpecificationImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisExecutionOccurrenceSpecificationPtr(element);
	return element;
	
}
std::shared_ptr<ExecutionOccurrenceSpecification> UmlFactoryImpl::createExecutionOccurrenceSpecification_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ExecutionOccurrenceSpecificationImpl> element(new ExecutionOccurrenceSpecificationImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisExecutionOccurrenceSpecificationPtr(element);
	return element;
	
}
std::shared_ptr<ExpansionNode> UmlFactoryImpl::createExpansionNode(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ExpansionNodeImpl> element(new ExpansionNodeImpl());
	element->setMetaElementID(metaElementID);
	element->setThisExpansionNodePtr(element);
	return element;
}
std::shared_ptr<ExpansionNode> UmlFactoryImpl::createExpansionNode_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<ExpansionNodeImpl> element(new ExpansionNodeImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisExpansionNodePtr(element);
	return element;
	
}
std::shared_ptr<ExpansionNode> UmlFactoryImpl::createExpansionNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<ExpansionNodeImpl> element(new ExpansionNodeImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisExpansionNodePtr(element);
	return element;
	
}
std::shared_ptr<ExpansionNode> UmlFactoryImpl::createExpansionNode_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ExpansionNodeImpl> element(new ExpansionNodeImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisExpansionNodePtr(element);
	return element;
	
}
std::shared_ptr<ExpansionNode> UmlFactoryImpl::createExpansionNode_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ExpansionNodeImpl> element(new ExpansionNodeImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisExpansionNodePtr(element);
	return element;
	
}
std::shared_ptr<ExpansionRegion> UmlFactoryImpl::createExpansionRegion(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ExpansionRegionImpl> element(new ExpansionRegionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisExpansionRegionPtr(element);
	return element;
}
std::shared_ptr<ExpansionRegion> UmlFactoryImpl::createExpansionRegion_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<ExpansionRegionImpl> element(new ExpansionRegionImpl(par_activity, UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisExpansionRegionPtr(element);
	return element;
	
}
std::shared_ptr<ExpansionRegion> UmlFactoryImpl::createExpansionRegion_in_InActivity(std::weak_ptr<uml::Activity > par_inActivity, const int metaElementID) const
{
	std::shared_ptr<ExpansionRegionImpl> element(new ExpansionRegionImpl(par_inActivity, UmlPackage::ACTIVITYGROUP_ATTRIBUTE_INACTIVITY));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inActivity.lock())
	{
			wp->getGroup()->push_back(element);
	}
	element->setThisExpansionRegionPtr(element);
	return element;
	
}
std::shared_ptr<ExpansionRegion> UmlFactoryImpl::createExpansionRegion_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<ExpansionRegionImpl> element(new ExpansionRegionImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisExpansionRegionPtr(element);
	return element;
	
}
std::shared_ptr<ExpansionRegion> UmlFactoryImpl::createExpansionRegion_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ExpansionRegionImpl> element(new ExpansionRegionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisExpansionRegionPtr(element);
	return element;
	
}
std::shared_ptr<ExpansionRegion> UmlFactoryImpl::createExpansionRegion_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ExpansionRegionImpl> element(new ExpansionRegionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisExpansionRegionPtr(element);
	return element;
	
}
std::shared_ptr<ExpansionRegion> UmlFactoryImpl::createExpansionRegion_in_SuperGroup(std::weak_ptr<uml::ActivityGroup > par_superGroup, const int metaElementID) const
{
	std::shared_ptr<ExpansionRegionImpl> element(new ExpansionRegionImpl(par_superGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_superGroup.lock())
	{
			wp->getSubgroup()->push_back(element);
	}
	element->setThisExpansionRegionPtr(element);
	return element;
	
}
std::shared_ptr<Expression> UmlFactoryImpl::createExpression(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ExpressionImpl> element(new ExpressionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisExpressionPtr(element);
	return element;
}
std::shared_ptr<Expression> UmlFactoryImpl::createExpression_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ExpressionImpl> element(new ExpressionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisExpressionPtr(element);
	return element;
	
}
std::shared_ptr<Expression> UmlFactoryImpl::createExpression_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ExpressionImpl> element(new ExpressionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisExpressionPtr(element);
	return element;
	
}
std::shared_ptr<Expression> UmlFactoryImpl::createExpression_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<ExpressionImpl> element(new ExpressionImpl(par_owningPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisExpressionPtr(element);
	return element;
	
}
std::shared_ptr<Expression> UmlFactoryImpl::createExpression_in_OwningSlot(std::weak_ptr<uml::Slot > par_owningSlot, const int metaElementID) const
{
	std::shared_ptr<ExpressionImpl> element(new ExpressionImpl(par_owningSlot));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningSlot.lock())
	{
			wp->getValue()->push_back(element);
	}
	element->setThisExpressionPtr(element);
	return element;
	
}
std::shared_ptr<Expression> UmlFactoryImpl::createExpression_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<ExpressionImpl> element(new ExpressionImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisExpressionPtr(element);
	return element;
	
}
std::shared_ptr<Expression> UmlFactoryImpl::createExpression_in_ValueSpecificationAction(std::weak_ptr<uml::ValueSpecificationAction > par_valueSpecificationAction, const int metaElementID) const
{
	std::shared_ptr<ExpressionImpl> element(new ExpressionImpl(par_valueSpecificationAction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_valueSpecificationAction.lock())
	{
			wp->setValue(element);
	}
	element->setThisExpressionPtr(element);
	return element;
	
}
std::shared_ptr<Extend> UmlFactoryImpl::createExtend(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ExtendImpl> element(new ExtendImpl());
	element->setMetaElementID(metaElementID);
	element->setThisExtendPtr(element);
	return element;
}
std::shared_ptr<Extend> UmlFactoryImpl::createExtend_in_Extension(std::weak_ptr<uml::UseCase > par_extension, const int metaElementID) const
{
	std::shared_ptr<ExtendImpl> element(new ExtendImpl(par_extension));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_extension.lock())
	{
			wp->getExtend()->push_back(element);
	}
	element->setThisExtendPtr(element);
	return element;
	
}
std::shared_ptr<Extend> UmlFactoryImpl::createExtend_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ExtendImpl> element(new ExtendImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisExtendPtr(element);
	return element;
	
}
std::shared_ptr<Extend> UmlFactoryImpl::createExtend_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ExtendImpl> element(new ExtendImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisExtendPtr(element);
	return element;
	
}
std::shared_ptr<Extension> UmlFactoryImpl::createExtension(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ExtensionImpl> element(new ExtensionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisExtensionPtr(element);
	return element;
}
std::shared_ptr<Extension> UmlFactoryImpl::createExtension_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ExtensionImpl> element(new ExtensionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisExtensionPtr(element);
	return element;
	
}
std::shared_ptr<Extension> UmlFactoryImpl::createExtension_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ExtensionImpl> element(new ExtensionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisExtensionPtr(element);
	return element;
	
}
std::shared_ptr<Extension> UmlFactoryImpl::createExtension_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<ExtensionImpl> element(new ExtensionImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisExtensionPtr(element);
	return element;
	
}
std::shared_ptr<Extension> UmlFactoryImpl::createExtension_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<ExtensionImpl> element(new ExtensionImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisExtensionPtr(element);
	return element;
	
}
std::shared_ptr<Extension> UmlFactoryImpl::createExtension_in_Package(std::weak_ptr<uml::Package > par_package, const int metaElementID) const
{
	std::shared_ptr<ExtensionImpl> element(new ExtensionImpl(par_package, UmlPackage::TYPE_ATTRIBUTE_PACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_package.lock())
	{
			wp->getOwnedType()->push_back(element);
	}
	element->setThisExtensionPtr(element);
	return element;
	
}
std::shared_ptr<ExtensionEnd> UmlFactoryImpl::createExtensionEnd(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ExtensionEndImpl> element(new ExtensionEndImpl());
	element->setMetaElementID(metaElementID);
	element->setThisExtensionEndPtr(element);
	return element;
}
std::shared_ptr<ExtensionEnd> UmlFactoryImpl::createExtensionEnd_in_AssociationEnd(std::weak_ptr<uml::Property > par_associationEnd, const int metaElementID) const
{
	std::shared_ptr<ExtensionEndImpl> element(new ExtensionEndImpl(par_associationEnd));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_associationEnd.lock())
	{
			wp->getQualifier()->push_back(element);
	}
	element->setThisExtensionEndPtr(element);
	return element;
	
}
std::shared_ptr<ExtensionEnd> UmlFactoryImpl::createExtensionEnd_in_Class(std::weak_ptr<uml::Class > par_class, const int metaElementID) const
{
	std::shared_ptr<ExtensionEndImpl> element(new ExtensionEndImpl(par_class));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_class.lock())
	{
			wp->getOwnedAttribute()->push_back(element);
	}
	element->setThisExtensionEndPtr(element);
	return element;
	
}
std::shared_ptr<ExtensionEnd> UmlFactoryImpl::createExtensionEnd_in_Datatype(std::weak_ptr<uml::DataType > par_datatype, const int metaElementID) const
{
	std::shared_ptr<ExtensionEndImpl> element(new ExtensionEndImpl(par_datatype));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_datatype.lock())
	{
			wp->getOwnedAttribute()->push_back(element);
	}
	element->setThisExtensionEndPtr(element);
	return element;
	
}
std::shared_ptr<ExtensionEnd> UmlFactoryImpl::createExtensionEnd_in_Interface(std::weak_ptr<uml::Interface > par_interface, const int metaElementID) const
{
	std::shared_ptr<ExtensionEndImpl> element(new ExtensionEndImpl(par_interface));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_interface.lock())
	{
			wp->getOwnedAttribute()->push_back(element);
	}
	element->setThisExtensionEndPtr(element);
	return element;
	
}
std::shared_ptr<ExtensionEnd> UmlFactoryImpl::createExtensionEnd_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ExtensionEndImpl> element(new ExtensionEndImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisExtensionEndPtr(element);
	return element;
	
}
std::shared_ptr<ExtensionEnd> UmlFactoryImpl::createExtensionEnd_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ExtensionEndImpl> element(new ExtensionEndImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisExtensionEndPtr(element);
	return element;
	
}
std::shared_ptr<ExtensionEnd> UmlFactoryImpl::createExtensionEnd_in_OwningAssociation(std::weak_ptr<uml::Association > par_owningAssociation, const int metaElementID) const
{
	std::shared_ptr<ExtensionEndImpl> element(new ExtensionEndImpl(par_owningAssociation));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningAssociation.lock())
	{
			wp->getOwnedEnd()->push_back(element);
	}
	element->setThisExtensionEndPtr(element);
	return element;
	
}
std::shared_ptr<ExtensionEnd> UmlFactoryImpl::createExtensionEnd_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<ExtensionEndImpl> element(new ExtensionEndImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisExtensionEndPtr(element);
	return element;
	
}
std::shared_ptr<ExtensionPoint> UmlFactoryImpl::createExtensionPoint(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ExtensionPointImpl> element(new ExtensionPointImpl());
	element->setMetaElementID(metaElementID);
	element->setThisExtensionPointPtr(element);
	return element;
}
std::shared_ptr<ExtensionPoint> UmlFactoryImpl::createExtensionPoint_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ExtensionPointImpl> element(new ExtensionPointImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisExtensionPointPtr(element);
	return element;
	
}
std::shared_ptr<ExtensionPoint> UmlFactoryImpl::createExtensionPoint_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ExtensionPointImpl> element(new ExtensionPointImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisExtensionPointPtr(element);
	return element;
	
}
std::shared_ptr<ExtensionPoint> UmlFactoryImpl::createExtensionPoint_in_UseCase(std::weak_ptr<uml::UseCase > par_useCase, const int metaElementID) const
{
	std::shared_ptr<ExtensionPointImpl> element(new ExtensionPointImpl(par_useCase));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_useCase.lock())
	{
			wp->getExtensionPoint()->push_back(element);
	}
	element->setThisExtensionPointPtr(element);
	return element;
	
}
std::shared_ptr<Factory> UmlFactoryImpl::createFactory(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<FactoryImpl> element(new FactoryImpl());
	element->setMetaElementID(metaElementID);
	element->setThisFactoryPtr(element);
	return element;
}
std::shared_ptr<Factory> UmlFactoryImpl::createFactory_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<FactoryImpl> element(new FactoryImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisFactoryPtr(element);
	return element;
	
}
std::shared_ptr<FinalState> UmlFactoryImpl::createFinalState(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<FinalStateImpl> element(new FinalStateImpl());
	element->setMetaElementID(metaElementID);
	element->setThisFinalStatePtr(element);
	return element;
}
std::shared_ptr<FinalState> UmlFactoryImpl::createFinalState_in_Container(std::weak_ptr<uml::Region > par_container, const int metaElementID) const
{
	std::shared_ptr<FinalStateImpl> element(new FinalStateImpl(par_container));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_container.lock())
	{
			wp->getSubvertex()->push_back(element);
	}
	element->setThisFinalStatePtr(element);
	return element;
	
}
std::shared_ptr<FinalState> UmlFactoryImpl::createFinalState_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<FinalStateImpl> element(new FinalStateImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisFinalStatePtr(element);
	return element;
	
}
std::shared_ptr<FinalState> UmlFactoryImpl::createFinalState_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<FinalStateImpl> element(new FinalStateImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisFinalStatePtr(element);
	return element;
	
}
std::shared_ptr<FlowFinalNode> UmlFactoryImpl::createFlowFinalNode(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<FlowFinalNodeImpl> element(new FlowFinalNodeImpl());
	element->setMetaElementID(metaElementID);
	element->setThisFlowFinalNodePtr(element);
	return element;
}
std::shared_ptr<FlowFinalNode> UmlFactoryImpl::createFlowFinalNode_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<FlowFinalNodeImpl> element(new FlowFinalNodeImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisFlowFinalNodePtr(element);
	return element;
	
}
std::shared_ptr<FlowFinalNode> UmlFactoryImpl::createFlowFinalNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<FlowFinalNodeImpl> element(new FlowFinalNodeImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisFlowFinalNodePtr(element);
	return element;
	
}
std::shared_ptr<FlowFinalNode> UmlFactoryImpl::createFlowFinalNode_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<FlowFinalNodeImpl> element(new FlowFinalNodeImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisFlowFinalNodePtr(element);
	return element;
	
}
std::shared_ptr<FlowFinalNode> UmlFactoryImpl::createFlowFinalNode_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<FlowFinalNodeImpl> element(new FlowFinalNodeImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisFlowFinalNodePtr(element);
	return element;
	
}
std::shared_ptr<ForkNode> UmlFactoryImpl::createForkNode(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ForkNodeImpl> element(new ForkNodeImpl());
	element->setMetaElementID(metaElementID);
	element->setThisForkNodePtr(element);
	return element;
}
std::shared_ptr<ForkNode> UmlFactoryImpl::createForkNode_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<ForkNodeImpl> element(new ForkNodeImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisForkNodePtr(element);
	return element;
	
}
std::shared_ptr<ForkNode> UmlFactoryImpl::createForkNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<ForkNodeImpl> element(new ForkNodeImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisForkNodePtr(element);
	return element;
	
}
std::shared_ptr<ForkNode> UmlFactoryImpl::createForkNode_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ForkNodeImpl> element(new ForkNodeImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisForkNodePtr(element);
	return element;
	
}
std::shared_ptr<ForkNode> UmlFactoryImpl::createForkNode_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ForkNodeImpl> element(new ForkNodeImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisForkNodePtr(element);
	return element;
	
}
std::shared_ptr<FunctionBehavior> UmlFactoryImpl::createFunctionBehavior(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<FunctionBehaviorImpl> element(new FunctionBehaviorImpl());
	element->setMetaElementID(metaElementID);
	element->setThisFunctionBehaviorPtr(element);
	return element;
}
std::shared_ptr<FunctionBehavior> UmlFactoryImpl::createFunctionBehavior_in_BehavioredClassifier(std::weak_ptr<uml::BehavioredClassifier > par_behavioredClassifier, const int metaElementID) const
{
	std::shared_ptr<FunctionBehaviorImpl> element(new FunctionBehaviorImpl(par_behavioredClassifier));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_behavioredClassifier.lock())
	{
			wp->getOwnedBehavior()->push_back(element);
	}
	element->setThisFunctionBehaviorPtr(element);
	return element;
	
}
std::shared_ptr<FunctionBehavior> UmlFactoryImpl::createFunctionBehavior_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<FunctionBehaviorImpl> element(new FunctionBehaviorImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisFunctionBehaviorPtr(element);
	return element;
	
}
std::shared_ptr<FunctionBehavior> UmlFactoryImpl::createFunctionBehavior_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<FunctionBehaviorImpl> element(new FunctionBehaviorImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisFunctionBehaviorPtr(element);
	return element;
	
}
std::shared_ptr<FunctionBehavior> UmlFactoryImpl::createFunctionBehavior_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<FunctionBehaviorImpl> element(new FunctionBehaviorImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisFunctionBehaviorPtr(element);
	return element;
	
}
std::shared_ptr<FunctionBehavior> UmlFactoryImpl::createFunctionBehavior_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<FunctionBehaviorImpl> element(new FunctionBehaviorImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisFunctionBehaviorPtr(element);
	return element;
	
}
std::shared_ptr<FunctionBehavior> UmlFactoryImpl::createFunctionBehavior_in_Package(std::weak_ptr<uml::Package > par_package, const int metaElementID) const
{
	std::shared_ptr<FunctionBehaviorImpl> element(new FunctionBehaviorImpl(par_package, UmlPackage::TYPE_ATTRIBUTE_PACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_package.lock())
	{
			wp->getOwnedType()->push_back(element);
	}
	element->setThisFunctionBehaviorPtr(element);
	return element;
	
}
std::shared_ptr<Gate> UmlFactoryImpl::createGate(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<GateImpl> element(new GateImpl());
	element->setMetaElementID(metaElementID);
	element->setThisGatePtr(element);
	return element;
}
std::shared_ptr<Gate> UmlFactoryImpl::createGate_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<GateImpl> element(new GateImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisGatePtr(element);
	return element;
	
}
std::shared_ptr<Gate> UmlFactoryImpl::createGate_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<GateImpl> element(new GateImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisGatePtr(element);
	return element;
	
}
std::shared_ptr<GeneralOrdering> UmlFactoryImpl::createGeneralOrdering(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<GeneralOrderingImpl> element(new GeneralOrderingImpl());
	element->setMetaElementID(metaElementID);
	element->setThisGeneralOrderingPtr(element);
	return element;
}
std::shared_ptr<GeneralOrdering> UmlFactoryImpl::createGeneralOrdering_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<GeneralOrderingImpl> element(new GeneralOrderingImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisGeneralOrderingPtr(element);
	return element;
	
}
std::shared_ptr<GeneralOrdering> UmlFactoryImpl::createGeneralOrdering_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<GeneralOrderingImpl> element(new GeneralOrderingImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisGeneralOrderingPtr(element);
	return element;
	
}
std::shared_ptr<Generalization> UmlFactoryImpl::createGeneralization(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<GeneralizationImpl> element(new GeneralizationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisGeneralizationPtr(element);
	return element;
}
std::shared_ptr<Generalization> UmlFactoryImpl::createGeneralization_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<GeneralizationImpl> element(new GeneralizationImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisGeneralizationPtr(element);
	return element;
	
}
std::shared_ptr<Generalization> UmlFactoryImpl::createGeneralization_in_Specific(std::weak_ptr<uml::Classifier > par_specific, const int metaElementID) const
{
	std::shared_ptr<GeneralizationImpl> element(new GeneralizationImpl(par_specific));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_specific.lock())
	{
			wp->getGeneralization()->push_back(element);
	}
	element->setThisGeneralizationPtr(element);
	return element;
	
}
std::shared_ptr<GeneralizationSet> UmlFactoryImpl::createGeneralizationSet(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<GeneralizationSetImpl> element(new GeneralizationSetImpl());
	element->setMetaElementID(metaElementID);
	element->setThisGeneralizationSetPtr(element);
	return element;
}
std::shared_ptr<GeneralizationSet> UmlFactoryImpl::createGeneralizationSet_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<GeneralizationSetImpl> element(new GeneralizationSetImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisGeneralizationSetPtr(element);
	return element;
	
}
std::shared_ptr<GeneralizationSet> UmlFactoryImpl::createGeneralizationSet_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<GeneralizationSetImpl> element(new GeneralizationSetImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisGeneralizationSetPtr(element);
	return element;
	
}
std::shared_ptr<GeneralizationSet> UmlFactoryImpl::createGeneralizationSet_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<GeneralizationSetImpl> element(new GeneralizationSetImpl(par_owningPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisGeneralizationSetPtr(element);
	return element;
	
}
std::shared_ptr<GeneralizationSet> UmlFactoryImpl::createGeneralizationSet_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<GeneralizationSetImpl> element(new GeneralizationSetImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisGeneralizationSetPtr(element);
	return element;
	
}
std::shared_ptr<Image> UmlFactoryImpl::createImage(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ImageImpl> element(new ImageImpl());
	element->setMetaElementID(metaElementID);
	element->setThisImagePtr(element);
	return element;
}
std::shared_ptr<Image> UmlFactoryImpl::createImage_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ImageImpl> element(new ImageImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisImagePtr(element);
	return element;
	
}
std::shared_ptr<Include> UmlFactoryImpl::createInclude(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<IncludeImpl> element(new IncludeImpl());
	element->setMetaElementID(metaElementID);
	element->setThisIncludePtr(element);
	return element;
}
std::shared_ptr<Include> UmlFactoryImpl::createInclude_in_IncludingCase(std::weak_ptr<uml::UseCase > par_includingCase, const int metaElementID) const
{
	std::shared_ptr<IncludeImpl> element(new IncludeImpl(par_includingCase));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_includingCase.lock())
	{
			wp->getInclude()->push_back(element);
	}
	element->setThisIncludePtr(element);
	return element;
	
}
std::shared_ptr<Include> UmlFactoryImpl::createInclude_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<IncludeImpl> element(new IncludeImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisIncludePtr(element);
	return element;
	
}
std::shared_ptr<Include> UmlFactoryImpl::createInclude_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<IncludeImpl> element(new IncludeImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisIncludePtr(element);
	return element;
	
}
std::shared_ptr<InformationFlow> UmlFactoryImpl::createInformationFlow(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<InformationFlowImpl> element(new InformationFlowImpl());
	element->setMetaElementID(metaElementID);
	element->setThisInformationFlowPtr(element);
	return element;
}
std::shared_ptr<InformationFlow> UmlFactoryImpl::createInformationFlow_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<InformationFlowImpl> element(new InformationFlowImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisInformationFlowPtr(element);
	return element;
	
}
std::shared_ptr<InformationFlow> UmlFactoryImpl::createInformationFlow_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<InformationFlowImpl> element(new InformationFlowImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisInformationFlowPtr(element);
	return element;
	
}
std::shared_ptr<InformationFlow> UmlFactoryImpl::createInformationFlow_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<InformationFlowImpl> element(new InformationFlowImpl(par_owningPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisInformationFlowPtr(element);
	return element;
	
}
std::shared_ptr<InformationFlow> UmlFactoryImpl::createInformationFlow_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<InformationFlowImpl> element(new InformationFlowImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisInformationFlowPtr(element);
	return element;
	
}
std::shared_ptr<InformationItem> UmlFactoryImpl::createInformationItem(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<InformationItemImpl> element(new InformationItemImpl());
	element->setMetaElementID(metaElementID);
	element->setThisInformationItemPtr(element);
	return element;
}
std::shared_ptr<InformationItem> UmlFactoryImpl::createInformationItem_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<InformationItemImpl> element(new InformationItemImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisInformationItemPtr(element);
	return element;
	
}
std::shared_ptr<InformationItem> UmlFactoryImpl::createInformationItem_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<InformationItemImpl> element(new InformationItemImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisInformationItemPtr(element);
	return element;
	
}
std::shared_ptr<InformationItem> UmlFactoryImpl::createInformationItem_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<InformationItemImpl> element(new InformationItemImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisInformationItemPtr(element);
	return element;
	
}
std::shared_ptr<InformationItem> UmlFactoryImpl::createInformationItem_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<InformationItemImpl> element(new InformationItemImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisInformationItemPtr(element);
	return element;
	
}
std::shared_ptr<InformationItem> UmlFactoryImpl::createInformationItem_in_Package(std::weak_ptr<uml::Package > par_package, const int metaElementID) const
{
	std::shared_ptr<InformationItemImpl> element(new InformationItemImpl(par_package, UmlPackage::TYPE_ATTRIBUTE_PACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_package.lock())
	{
			wp->getOwnedType()->push_back(element);
	}
	element->setThisInformationItemPtr(element);
	return element;
	
}
std::shared_ptr<InitialNode> UmlFactoryImpl::createInitialNode(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<InitialNodeImpl> element(new InitialNodeImpl());
	element->setMetaElementID(metaElementID);
	element->setThisInitialNodePtr(element);
	return element;
}
std::shared_ptr<InitialNode> UmlFactoryImpl::createInitialNode_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<InitialNodeImpl> element(new InitialNodeImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisInitialNodePtr(element);
	return element;
	
}
std::shared_ptr<InitialNode> UmlFactoryImpl::createInitialNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<InitialNodeImpl> element(new InitialNodeImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisInitialNodePtr(element);
	return element;
	
}
std::shared_ptr<InitialNode> UmlFactoryImpl::createInitialNode_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<InitialNodeImpl> element(new InitialNodeImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisInitialNodePtr(element);
	return element;
	
}
std::shared_ptr<InitialNode> UmlFactoryImpl::createInitialNode_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<InitialNodeImpl> element(new InitialNodeImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisInitialNodePtr(element);
	return element;
	
}
std::shared_ptr<InputPin> UmlFactoryImpl::createInputPin(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<InputPinImpl> element(new InputPinImpl());
	element->setMetaElementID(metaElementID);
	element->setThisInputPinPtr(element);
	return element;
}
std::shared_ptr<InputPin> UmlFactoryImpl::createInputPin_in_Action(std::weak_ptr<uml::Action > par_action, const int metaElementID) const
{
	std::shared_ptr<InputPinImpl> element(new InputPinImpl(par_action));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_action.lock())
	{
			wp->getInput()->push_back(element);
	}
	element->setThisInputPinPtr(element);
	return element;
	
}
std::shared_ptr<InputPin> UmlFactoryImpl::createInputPin_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<InputPinImpl> element(new InputPinImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisInputPinPtr(element);
	return element;
	
}
std::shared_ptr<InputPin> UmlFactoryImpl::createInputPin_in_AddStructuralFeatureValueAction(std::weak_ptr<uml::AddStructuralFeatureValueAction > par_addStructuralFeatureValueAction, const int metaElementID) const
{
	std::shared_ptr<InputPinImpl> element(new InputPinImpl(par_addStructuralFeatureValueAction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_addStructuralFeatureValueAction.lock())
	{
			wp->setInsertAt(element);
	}
	element->setThisInputPinPtr(element);
	return element;
	
}
std::shared_ptr<InputPin> UmlFactoryImpl::createInputPin_in_CallOperationAction(std::weak_ptr<uml::CallOperationAction > par_callOperationAction, const int metaElementID) const
{
	std::shared_ptr<InputPinImpl> element(new InputPinImpl(par_callOperationAction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_callOperationAction.lock())
	{
			wp->setTarget(element);
	}
	element->setThisInputPinPtr(element);
	return element;
	
}
std::shared_ptr<InputPin> UmlFactoryImpl::createInputPin_in_DestroyObjectAction(std::weak_ptr<uml::DestroyObjectAction > par_destroyObjectAction, const int metaElementID) const
{
	std::shared_ptr<InputPinImpl> element(new InputPinImpl(par_destroyObjectAction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_destroyObjectAction.lock())
	{
			wp->setTarget(element);
	}
	element->setThisInputPinPtr(element);
	return element;
	
}
std::shared_ptr<InputPin> UmlFactoryImpl::createInputPin_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<InputPinImpl> element(new InputPinImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisInputPinPtr(element);
	return element;
	
}
std::shared_ptr<InputPin> UmlFactoryImpl::createInputPin_in_InvocationAction(std::weak_ptr<uml::InvocationAction > par_invocationAction, const int metaElementID) const
{
	std::shared_ptr<InputPinImpl> element(new InputPinImpl(par_invocationAction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_invocationAction.lock())
	{
			wp->getArgument()->push_back(element);
	}
	element->setThisInputPinPtr(element);
	return element;
	
}
std::shared_ptr<InputPin> UmlFactoryImpl::createInputPin_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<InputPinImpl> element(new InputPinImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisInputPinPtr(element);
	return element;
	
}
std::shared_ptr<InputPin> UmlFactoryImpl::createInputPin_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<InputPinImpl> element(new InputPinImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisInputPinPtr(element);
	return element;
	
}
std::shared_ptr<InputPin> UmlFactoryImpl::createInputPin_in_StructuralFeatureAction(std::weak_ptr<uml::StructuralFeatureAction > par_structuralFeatureAction, const int metaElementID) const
{
	std::shared_ptr<InputPinImpl> element(new InputPinImpl(par_structuralFeatureAction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_structuralFeatureAction.lock())
	{
			wp->setObject(element);
	}
	element->setThisInputPinPtr(element);
	return element;
	
}
std::shared_ptr<InputPin> UmlFactoryImpl::createInputPin_in_WriteStructuralFeatureAction(std::weak_ptr<uml::WriteStructuralFeatureAction > par_writeStructuralFeatureAction, const int metaElementID) const
{
	std::shared_ptr<InputPinImpl> element(new InputPinImpl(par_writeStructuralFeatureAction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_writeStructuralFeatureAction.lock())
	{
			wp->setValue(element);
	}
	element->setThisInputPinPtr(element);
	return element;
	
}
std::shared_ptr<InstanceSpecification> UmlFactoryImpl::createInstanceSpecification(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<InstanceSpecificationImpl> element(new InstanceSpecificationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisInstanceSpecificationPtr(element);
	return element;
}
std::shared_ptr<InstanceSpecification> UmlFactoryImpl::createInstanceSpecification_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<InstanceSpecificationImpl> element(new InstanceSpecificationImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisInstanceSpecificationPtr(element);
	return element;
	
}
std::shared_ptr<InstanceSpecification> UmlFactoryImpl::createInstanceSpecification_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<InstanceSpecificationImpl> element(new InstanceSpecificationImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisInstanceSpecificationPtr(element);
	return element;
	
}
std::shared_ptr<InstanceSpecification> UmlFactoryImpl::createInstanceSpecification_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<InstanceSpecificationImpl> element(new InstanceSpecificationImpl(par_owningPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisInstanceSpecificationPtr(element);
	return element;
	
}
std::shared_ptr<InstanceSpecification> UmlFactoryImpl::createInstanceSpecification_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<InstanceSpecificationImpl> element(new InstanceSpecificationImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisInstanceSpecificationPtr(element);
	return element;
	
}
std::shared_ptr<InstanceValue> UmlFactoryImpl::createInstanceValue(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<InstanceValueImpl> element(new InstanceValueImpl());
	element->setMetaElementID(metaElementID);
	element->setThisInstanceValuePtr(element);
	return element;
}
std::shared_ptr<InstanceValue> UmlFactoryImpl::createInstanceValue_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<InstanceValueImpl> element(new InstanceValueImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisInstanceValuePtr(element);
	return element;
	
}
std::shared_ptr<InstanceValue> UmlFactoryImpl::createInstanceValue_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<InstanceValueImpl> element(new InstanceValueImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisInstanceValuePtr(element);
	return element;
	
}
std::shared_ptr<InstanceValue> UmlFactoryImpl::createInstanceValue_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<InstanceValueImpl> element(new InstanceValueImpl(par_owningPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisInstanceValuePtr(element);
	return element;
	
}
std::shared_ptr<InstanceValue> UmlFactoryImpl::createInstanceValue_in_OwningSlot(std::weak_ptr<uml::Slot > par_owningSlot, const int metaElementID) const
{
	std::shared_ptr<InstanceValueImpl> element(new InstanceValueImpl(par_owningSlot));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningSlot.lock())
	{
			wp->getValue()->push_back(element);
	}
	element->setThisInstanceValuePtr(element);
	return element;
	
}
std::shared_ptr<InstanceValue> UmlFactoryImpl::createInstanceValue_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<InstanceValueImpl> element(new InstanceValueImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisInstanceValuePtr(element);
	return element;
	
}
std::shared_ptr<InstanceValue> UmlFactoryImpl::createInstanceValue_in_ValueSpecificationAction(std::weak_ptr<uml::ValueSpecificationAction > par_valueSpecificationAction, const int metaElementID) const
{
	std::shared_ptr<InstanceValueImpl> element(new InstanceValueImpl(par_valueSpecificationAction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_valueSpecificationAction.lock())
	{
			wp->setValue(element);
	}
	element->setThisInstanceValuePtr(element);
	return element;
	
}
std::shared_ptr<Interaction> UmlFactoryImpl::createInteraction(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<InteractionImpl> element(new InteractionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisInteractionPtr(element);
	return element;
}
std::shared_ptr<Interaction> UmlFactoryImpl::createInteraction_in_BehavioredClassifier(std::weak_ptr<uml::BehavioredClassifier > par_behavioredClassifier, const int metaElementID) const
{
	std::shared_ptr<InteractionImpl> element(new InteractionImpl(par_behavioredClassifier));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_behavioredClassifier.lock())
	{
			wp->getOwnedBehavior()->push_back(element);
	}
	element->setThisInteractionPtr(element);
	return element;
	
}
std::shared_ptr<Interaction> UmlFactoryImpl::createInteraction_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction, const int metaElementID) const
{
	std::shared_ptr<InteractionImpl> element(new InteractionImpl(par_enclosingInteraction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_enclosingInteraction.lock())
	{
			wp->getFragment()->push_back(element);
	}
	element->setThisInteractionPtr(element);
	return element;
	
}
std::shared_ptr<Interaction> UmlFactoryImpl::createInteraction_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand, const int metaElementID) const
{
	std::shared_ptr<InteractionImpl> element(new InteractionImpl(par_enclosingOperand));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_enclosingOperand.lock())
	{
			wp->getFragment()->push_back(element);
	}
	element->setThisInteractionPtr(element);
	return element;
	
}
std::shared_ptr<Interaction> UmlFactoryImpl::createInteraction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<InteractionImpl> element(new InteractionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisInteractionPtr(element);
	return element;
	
}
std::shared_ptr<Interaction> UmlFactoryImpl::createInteraction_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<InteractionImpl> element(new InteractionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisInteractionPtr(element);
	return element;
	
}
std::shared_ptr<Interaction> UmlFactoryImpl::createInteraction_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<InteractionImpl> element(new InteractionImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisInteractionPtr(element);
	return element;
	
}
std::shared_ptr<Interaction> UmlFactoryImpl::createInteraction_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<InteractionImpl> element(new InteractionImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisInteractionPtr(element);
	return element;
	
}
std::shared_ptr<Interaction> UmlFactoryImpl::createInteraction_in_Package(std::weak_ptr<uml::Package > par_package, const int metaElementID) const
{
	std::shared_ptr<InteractionImpl> element(new InteractionImpl(par_package, UmlPackage::TYPE_ATTRIBUTE_PACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_package.lock())
	{
			wp->getOwnedType()->push_back(element);
	}
	element->setThisInteractionPtr(element);
	return element;
	
}
std::shared_ptr<InteractionConstraint> UmlFactoryImpl::createInteractionConstraint(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<InteractionConstraintImpl> element(new InteractionConstraintImpl());
	element->setMetaElementID(metaElementID);
	element->setThisInteractionConstraintPtr(element);
	return element;
}
std::shared_ptr<InteractionConstraint> UmlFactoryImpl::createInteractionConstraint_in_Context(std::weak_ptr<uml::Namespace > par_context, const int metaElementID) const
{
	std::shared_ptr<InteractionConstraintImpl> element(new InteractionConstraintImpl(par_context, UmlPackage::CONSTRAINT_ATTRIBUTE_CONTEXT));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_context.lock())
	{
			wp->getOwnedRule()->push_back(element);
	}
	element->setThisInteractionConstraintPtr(element);
	return element;
	
}
std::shared_ptr<InteractionConstraint> UmlFactoryImpl::createInteractionConstraint_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<InteractionConstraintImpl> element(new InteractionConstraintImpl(par_namespace, UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisInteractionConstraintPtr(element);
	return element;
	
}
std::shared_ptr<InteractionConstraint> UmlFactoryImpl::createInteractionConstraint_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<InteractionConstraintImpl> element(new InteractionConstraintImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisInteractionConstraintPtr(element);
	return element;
	
}
std::shared_ptr<InteractionConstraint> UmlFactoryImpl::createInteractionConstraint_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<InteractionConstraintImpl> element(new InteractionConstraintImpl(par_owningPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisInteractionConstraintPtr(element);
	return element;
	
}
std::shared_ptr<InteractionConstraint> UmlFactoryImpl::createInteractionConstraint_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<InteractionConstraintImpl> element(new InteractionConstraintImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisInteractionConstraintPtr(element);
	return element;
	
}
std::shared_ptr<InteractionOperand> UmlFactoryImpl::createInteractionOperand(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<InteractionOperandImpl> element(new InteractionOperandImpl());
	element->setMetaElementID(metaElementID);
	element->setThisInteractionOperandPtr(element);
	return element;
}
std::shared_ptr<InteractionOperand> UmlFactoryImpl::createInteractionOperand_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction, const int metaElementID) const
{
	std::shared_ptr<InteractionOperandImpl> element(new InteractionOperandImpl(par_enclosingInteraction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_enclosingInteraction.lock())
	{
			wp->getFragment()->push_back(element);
	}
	element->setThisInteractionOperandPtr(element);
	return element;
	
}
std::shared_ptr<InteractionOperand> UmlFactoryImpl::createInteractionOperand_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand, const int metaElementID) const
{
	std::shared_ptr<InteractionOperandImpl> element(new InteractionOperandImpl(par_enclosingOperand));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_enclosingOperand.lock())
	{
			wp->getFragment()->push_back(element);
	}
	element->setThisInteractionOperandPtr(element);
	return element;
	
}
std::shared_ptr<InteractionOperand> UmlFactoryImpl::createInteractionOperand_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<InteractionOperandImpl> element(new InteractionOperandImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisInteractionOperandPtr(element);
	return element;
	
}
std::shared_ptr<InteractionOperand> UmlFactoryImpl::createInteractionOperand_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<InteractionOperandImpl> element(new InteractionOperandImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisInteractionOperandPtr(element);
	return element;
	
}
std::shared_ptr<InteractionUse> UmlFactoryImpl::createInteractionUse(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<InteractionUseImpl> element(new InteractionUseImpl());
	element->setMetaElementID(metaElementID);
	element->setThisInteractionUsePtr(element);
	return element;
}
std::shared_ptr<InteractionUse> UmlFactoryImpl::createInteractionUse_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction, const int metaElementID) const
{
	std::shared_ptr<InteractionUseImpl> element(new InteractionUseImpl(par_enclosingInteraction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_enclosingInteraction.lock())
	{
			wp->getFragment()->push_back(element);
	}
	element->setThisInteractionUsePtr(element);
	return element;
	
}
std::shared_ptr<InteractionUse> UmlFactoryImpl::createInteractionUse_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand, const int metaElementID) const
{
	std::shared_ptr<InteractionUseImpl> element(new InteractionUseImpl(par_enclosingOperand));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_enclosingOperand.lock())
	{
			wp->getFragment()->push_back(element);
	}
	element->setThisInteractionUsePtr(element);
	return element;
	
}
std::shared_ptr<InteractionUse> UmlFactoryImpl::createInteractionUse_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<InteractionUseImpl> element(new InteractionUseImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisInteractionUsePtr(element);
	return element;
	
}
std::shared_ptr<InteractionUse> UmlFactoryImpl::createInteractionUse_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<InteractionUseImpl> element(new InteractionUseImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisInteractionUsePtr(element);
	return element;
	
}
std::shared_ptr<Interface> UmlFactoryImpl::createInterface(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<InterfaceImpl> element(new InterfaceImpl());
	element->setMetaElementID(metaElementID);
	element->setThisInterfacePtr(element);
	return element;
}
std::shared_ptr<Interface> UmlFactoryImpl::createInterface_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<InterfaceImpl> element(new InterfaceImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisInterfacePtr(element);
	return element;
	
}
std::shared_ptr<Interface> UmlFactoryImpl::createInterface_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<InterfaceImpl> element(new InterfaceImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisInterfacePtr(element);
	return element;
	
}
std::shared_ptr<Interface> UmlFactoryImpl::createInterface_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<InterfaceImpl> element(new InterfaceImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisInterfacePtr(element);
	return element;
	
}
std::shared_ptr<Interface> UmlFactoryImpl::createInterface_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<InterfaceImpl> element(new InterfaceImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisInterfacePtr(element);
	return element;
	
}
std::shared_ptr<Interface> UmlFactoryImpl::createInterface_in_Package(std::weak_ptr<uml::Package > par_package, const int metaElementID) const
{
	std::shared_ptr<InterfaceImpl> element(new InterfaceImpl(par_package, UmlPackage::TYPE_ATTRIBUTE_PACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_package.lock())
	{
			wp->getOwnedType()->push_back(element);
	}
	element->setThisInterfacePtr(element);
	return element;
	
}
std::shared_ptr<InterfaceRealization> UmlFactoryImpl::createInterfaceRealization(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<InterfaceRealizationImpl> element(new InterfaceRealizationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisInterfaceRealizationPtr(element);
	return element;
}
std::shared_ptr<InterfaceRealization> UmlFactoryImpl::createInterfaceRealization_in_ImplementingClassifier(std::weak_ptr<uml::BehavioredClassifier > par_implementingClassifier, const int metaElementID) const
{
	std::shared_ptr<InterfaceRealizationImpl> element(new InterfaceRealizationImpl(par_implementingClassifier));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_implementingClassifier.lock())
	{
			wp->getInterfaceRealization()->push_back(element);
	}
	element->setThisInterfaceRealizationPtr(element);
	return element;
	
}
std::shared_ptr<InterfaceRealization> UmlFactoryImpl::createInterfaceRealization_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<InterfaceRealizationImpl> element(new InterfaceRealizationImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisInterfaceRealizationPtr(element);
	return element;
	
}
std::shared_ptr<InterfaceRealization> UmlFactoryImpl::createInterfaceRealization_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<InterfaceRealizationImpl> element(new InterfaceRealizationImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisInterfaceRealizationPtr(element);
	return element;
	
}
std::shared_ptr<InterfaceRealization> UmlFactoryImpl::createInterfaceRealization_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<InterfaceRealizationImpl> element(new InterfaceRealizationImpl(par_owningPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisInterfaceRealizationPtr(element);
	return element;
	
}
std::shared_ptr<InterfaceRealization> UmlFactoryImpl::createInterfaceRealization_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<InterfaceRealizationImpl> element(new InterfaceRealizationImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisInterfaceRealizationPtr(element);
	return element;
	
}
std::shared_ptr<InterruptibleActivityRegion> UmlFactoryImpl::createInterruptibleActivityRegion(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<InterruptibleActivityRegionImpl> element(new InterruptibleActivityRegionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisInterruptibleActivityRegionPtr(element);
	return element;
}
std::shared_ptr<InterruptibleActivityRegion> UmlFactoryImpl::createInterruptibleActivityRegion_in_InActivity(std::weak_ptr<uml::Activity > par_inActivity, const int metaElementID) const
{
	std::shared_ptr<InterruptibleActivityRegionImpl> element(new InterruptibleActivityRegionImpl(par_inActivity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inActivity.lock())
	{
			wp->getGroup()->push_back(element);
	}
	element->setThisInterruptibleActivityRegionPtr(element);
	return element;
	
}
std::shared_ptr<InterruptibleActivityRegion> UmlFactoryImpl::createInterruptibleActivityRegion_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<InterruptibleActivityRegionImpl> element(new InterruptibleActivityRegionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisInterruptibleActivityRegionPtr(element);
	return element;
	
}
std::shared_ptr<InterruptibleActivityRegion> UmlFactoryImpl::createInterruptibleActivityRegion_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<InterruptibleActivityRegionImpl> element(new InterruptibleActivityRegionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisInterruptibleActivityRegionPtr(element);
	return element;
	
}
std::shared_ptr<InterruptibleActivityRegion> UmlFactoryImpl::createInterruptibleActivityRegion_in_SuperGroup(std::weak_ptr<uml::ActivityGroup > par_superGroup, const int metaElementID) const
{
	std::shared_ptr<InterruptibleActivityRegionImpl> element(new InterruptibleActivityRegionImpl(par_superGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_superGroup.lock())
	{
			wp->getSubgroup()->push_back(element);
	}
	element->setThisInterruptibleActivityRegionPtr(element);
	return element;
	
}
std::shared_ptr<Interval> UmlFactoryImpl::createInterval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<IntervalImpl> element(new IntervalImpl());
	element->setMetaElementID(metaElementID);
	element->setThisIntervalPtr(element);
	return element;
}
std::shared_ptr<Interval> UmlFactoryImpl::createInterval_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<IntervalImpl> element(new IntervalImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisIntervalPtr(element);
	return element;
	
}
std::shared_ptr<Interval> UmlFactoryImpl::createInterval_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<IntervalImpl> element(new IntervalImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisIntervalPtr(element);
	return element;
	
}
std::shared_ptr<Interval> UmlFactoryImpl::createInterval_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<IntervalImpl> element(new IntervalImpl(par_owningPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisIntervalPtr(element);
	return element;
	
}
std::shared_ptr<Interval> UmlFactoryImpl::createInterval_in_OwningSlot(std::weak_ptr<uml::Slot > par_owningSlot, const int metaElementID) const
{
	std::shared_ptr<IntervalImpl> element(new IntervalImpl(par_owningSlot));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningSlot.lock())
	{
			wp->getValue()->push_back(element);
	}
	element->setThisIntervalPtr(element);
	return element;
	
}
std::shared_ptr<Interval> UmlFactoryImpl::createInterval_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<IntervalImpl> element(new IntervalImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisIntervalPtr(element);
	return element;
	
}
std::shared_ptr<Interval> UmlFactoryImpl::createInterval_in_ValueSpecificationAction(std::weak_ptr<uml::ValueSpecificationAction > par_valueSpecificationAction, const int metaElementID) const
{
	std::shared_ptr<IntervalImpl> element(new IntervalImpl(par_valueSpecificationAction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_valueSpecificationAction.lock())
	{
			wp->setValue(element);
	}
	element->setThisIntervalPtr(element);
	return element;
	
}
std::shared_ptr<IntervalConstraint> UmlFactoryImpl::createIntervalConstraint(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<IntervalConstraintImpl> element(new IntervalConstraintImpl());
	element->setMetaElementID(metaElementID);
	element->setThisIntervalConstraintPtr(element);
	return element;
}
std::shared_ptr<IntervalConstraint> UmlFactoryImpl::createIntervalConstraint_in_Context(std::weak_ptr<uml::Namespace > par_context, const int metaElementID) const
{
	std::shared_ptr<IntervalConstraintImpl> element(new IntervalConstraintImpl(par_context, UmlPackage::CONSTRAINT_ATTRIBUTE_CONTEXT));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_context.lock())
	{
			wp->getOwnedRule()->push_back(element);
	}
	element->setThisIntervalConstraintPtr(element);
	return element;
	
}
std::shared_ptr<IntervalConstraint> UmlFactoryImpl::createIntervalConstraint_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<IntervalConstraintImpl> element(new IntervalConstraintImpl(par_namespace, UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisIntervalConstraintPtr(element);
	return element;
	
}
std::shared_ptr<IntervalConstraint> UmlFactoryImpl::createIntervalConstraint_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<IntervalConstraintImpl> element(new IntervalConstraintImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisIntervalConstraintPtr(element);
	return element;
	
}
std::shared_ptr<IntervalConstraint> UmlFactoryImpl::createIntervalConstraint_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<IntervalConstraintImpl> element(new IntervalConstraintImpl(par_owningPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisIntervalConstraintPtr(element);
	return element;
	
}
std::shared_ptr<IntervalConstraint> UmlFactoryImpl::createIntervalConstraint_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<IntervalConstraintImpl> element(new IntervalConstraintImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisIntervalConstraintPtr(element);
	return element;
	
}
std::shared_ptr<JoinNode> UmlFactoryImpl::createJoinNode(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<JoinNodeImpl> element(new JoinNodeImpl());
	element->setMetaElementID(metaElementID);
	element->setThisJoinNodePtr(element);
	return element;
}
std::shared_ptr<JoinNode> UmlFactoryImpl::createJoinNode_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<JoinNodeImpl> element(new JoinNodeImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisJoinNodePtr(element);
	return element;
	
}
std::shared_ptr<JoinNode> UmlFactoryImpl::createJoinNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<JoinNodeImpl> element(new JoinNodeImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisJoinNodePtr(element);
	return element;
	
}
std::shared_ptr<JoinNode> UmlFactoryImpl::createJoinNode_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<JoinNodeImpl> element(new JoinNodeImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisJoinNodePtr(element);
	return element;
	
}
std::shared_ptr<JoinNode> UmlFactoryImpl::createJoinNode_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<JoinNodeImpl> element(new JoinNodeImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisJoinNodePtr(element);
	return element;
	
}
std::shared_ptr<Lifeline> UmlFactoryImpl::createLifeline(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<LifelineImpl> element(new LifelineImpl());
	element->setMetaElementID(metaElementID);
	element->setThisLifelinePtr(element);
	return element;
}
std::shared_ptr<Lifeline> UmlFactoryImpl::createLifeline_in_Interaction(std::weak_ptr<uml::Interaction > par_interaction, const int metaElementID) const
{
	std::shared_ptr<LifelineImpl> element(new LifelineImpl(par_interaction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_interaction.lock())
	{
			wp->getLifeline()->push_back(element);
	}
	element->setThisLifelinePtr(element);
	return element;
	
}
std::shared_ptr<Lifeline> UmlFactoryImpl::createLifeline_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<LifelineImpl> element(new LifelineImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisLifelinePtr(element);
	return element;
	
}
std::shared_ptr<Lifeline> UmlFactoryImpl::createLifeline_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<LifelineImpl> element(new LifelineImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisLifelinePtr(element);
	return element;
	
}
std::shared_ptr<LinkEndCreationData> UmlFactoryImpl::createLinkEndCreationData(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<LinkEndCreationDataImpl> element(new LinkEndCreationDataImpl());
	element->setMetaElementID(metaElementID);
	element->setThisLinkEndCreationDataPtr(element);
	return element;
}
std::shared_ptr<LinkEndCreationData> UmlFactoryImpl::createLinkEndCreationData_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<LinkEndCreationDataImpl> element(new LinkEndCreationDataImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisLinkEndCreationDataPtr(element);
	return element;
	
}
std::shared_ptr<LinkEndData> UmlFactoryImpl::createLinkEndData(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<LinkEndDataImpl> element(new LinkEndDataImpl());
	element->setMetaElementID(metaElementID);
	element->setThisLinkEndDataPtr(element);
	return element;
}
std::shared_ptr<LinkEndData> UmlFactoryImpl::createLinkEndData_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<LinkEndDataImpl> element(new LinkEndDataImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisLinkEndDataPtr(element);
	return element;
	
}
std::shared_ptr<LinkEndDestructionData> UmlFactoryImpl::createLinkEndDestructionData(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<LinkEndDestructionDataImpl> element(new LinkEndDestructionDataImpl());
	element->setMetaElementID(metaElementID);
	element->setThisLinkEndDestructionDataPtr(element);
	return element;
}
std::shared_ptr<LinkEndDestructionData> UmlFactoryImpl::createLinkEndDestructionData_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<LinkEndDestructionDataImpl> element(new LinkEndDestructionDataImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisLinkEndDestructionDataPtr(element);
	return element;
	
}
std::shared_ptr<LiteralBoolean> UmlFactoryImpl::createLiteralBoolean(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<LiteralBooleanImpl> element(new LiteralBooleanImpl());
	element->setMetaElementID(metaElementID);
	element->setThisLiteralBooleanPtr(element);
	return element;
}
std::shared_ptr<LiteralBoolean> UmlFactoryImpl::createLiteralBoolean_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<LiteralBooleanImpl> element(new LiteralBooleanImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisLiteralBooleanPtr(element);
	return element;
	
}
std::shared_ptr<LiteralBoolean> UmlFactoryImpl::createLiteralBoolean_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<LiteralBooleanImpl> element(new LiteralBooleanImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisLiteralBooleanPtr(element);
	return element;
	
}
std::shared_ptr<LiteralBoolean> UmlFactoryImpl::createLiteralBoolean_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<LiteralBooleanImpl> element(new LiteralBooleanImpl(par_owningPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisLiteralBooleanPtr(element);
	return element;
	
}
std::shared_ptr<LiteralBoolean> UmlFactoryImpl::createLiteralBoolean_in_OwningSlot(std::weak_ptr<uml::Slot > par_owningSlot, const int metaElementID) const
{
	std::shared_ptr<LiteralBooleanImpl> element(new LiteralBooleanImpl(par_owningSlot));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningSlot.lock())
	{
			wp->getValue()->push_back(element);
	}
	element->setThisLiteralBooleanPtr(element);
	return element;
	
}
std::shared_ptr<LiteralBoolean> UmlFactoryImpl::createLiteralBoolean_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<LiteralBooleanImpl> element(new LiteralBooleanImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisLiteralBooleanPtr(element);
	return element;
	
}
std::shared_ptr<LiteralBoolean> UmlFactoryImpl::createLiteralBoolean_in_ValueSpecificationAction(std::weak_ptr<uml::ValueSpecificationAction > par_valueSpecificationAction, const int metaElementID) const
{
	std::shared_ptr<LiteralBooleanImpl> element(new LiteralBooleanImpl(par_valueSpecificationAction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_valueSpecificationAction.lock())
	{
			wp->setValue(element);
	}
	element->setThisLiteralBooleanPtr(element);
	return element;
	
}
std::shared_ptr<LiteralInteger> UmlFactoryImpl::createLiteralInteger(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<LiteralIntegerImpl> element(new LiteralIntegerImpl());
	element->setMetaElementID(metaElementID);
	element->setThisLiteralIntegerPtr(element);
	return element;
}
std::shared_ptr<LiteralInteger> UmlFactoryImpl::createLiteralInteger_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<LiteralIntegerImpl> element(new LiteralIntegerImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisLiteralIntegerPtr(element);
	return element;
	
}
std::shared_ptr<LiteralInteger> UmlFactoryImpl::createLiteralInteger_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<LiteralIntegerImpl> element(new LiteralIntegerImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisLiteralIntegerPtr(element);
	return element;
	
}
std::shared_ptr<LiteralInteger> UmlFactoryImpl::createLiteralInteger_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<LiteralIntegerImpl> element(new LiteralIntegerImpl(par_owningPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisLiteralIntegerPtr(element);
	return element;
	
}
std::shared_ptr<LiteralInteger> UmlFactoryImpl::createLiteralInteger_in_OwningSlot(std::weak_ptr<uml::Slot > par_owningSlot, const int metaElementID) const
{
	std::shared_ptr<LiteralIntegerImpl> element(new LiteralIntegerImpl(par_owningSlot));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningSlot.lock())
	{
			wp->getValue()->push_back(element);
	}
	element->setThisLiteralIntegerPtr(element);
	return element;
	
}
std::shared_ptr<LiteralInteger> UmlFactoryImpl::createLiteralInteger_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<LiteralIntegerImpl> element(new LiteralIntegerImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisLiteralIntegerPtr(element);
	return element;
	
}
std::shared_ptr<LiteralInteger> UmlFactoryImpl::createLiteralInteger_in_ValueSpecificationAction(std::weak_ptr<uml::ValueSpecificationAction > par_valueSpecificationAction, const int metaElementID) const
{
	std::shared_ptr<LiteralIntegerImpl> element(new LiteralIntegerImpl(par_valueSpecificationAction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_valueSpecificationAction.lock())
	{
			wp->setValue(element);
	}
	element->setThisLiteralIntegerPtr(element);
	return element;
	
}
std::shared_ptr<LiteralNull> UmlFactoryImpl::createLiteralNull(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<LiteralNullImpl> element(new LiteralNullImpl());
	element->setMetaElementID(metaElementID);
	element->setThisLiteralNullPtr(element);
	return element;
}
std::shared_ptr<LiteralNull> UmlFactoryImpl::createLiteralNull_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<LiteralNullImpl> element(new LiteralNullImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisLiteralNullPtr(element);
	return element;
	
}
std::shared_ptr<LiteralNull> UmlFactoryImpl::createLiteralNull_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<LiteralNullImpl> element(new LiteralNullImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisLiteralNullPtr(element);
	return element;
	
}
std::shared_ptr<LiteralNull> UmlFactoryImpl::createLiteralNull_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<LiteralNullImpl> element(new LiteralNullImpl(par_owningPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisLiteralNullPtr(element);
	return element;
	
}
std::shared_ptr<LiteralNull> UmlFactoryImpl::createLiteralNull_in_OwningSlot(std::weak_ptr<uml::Slot > par_owningSlot, const int metaElementID) const
{
	std::shared_ptr<LiteralNullImpl> element(new LiteralNullImpl(par_owningSlot));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningSlot.lock())
	{
			wp->getValue()->push_back(element);
	}
	element->setThisLiteralNullPtr(element);
	return element;
	
}
std::shared_ptr<LiteralNull> UmlFactoryImpl::createLiteralNull_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<LiteralNullImpl> element(new LiteralNullImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisLiteralNullPtr(element);
	return element;
	
}
std::shared_ptr<LiteralNull> UmlFactoryImpl::createLiteralNull_in_ValueSpecificationAction(std::weak_ptr<uml::ValueSpecificationAction > par_valueSpecificationAction, const int metaElementID) const
{
	std::shared_ptr<LiteralNullImpl> element(new LiteralNullImpl(par_valueSpecificationAction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_valueSpecificationAction.lock())
	{
			wp->setValue(element);
	}
	element->setThisLiteralNullPtr(element);
	return element;
	
}
std::shared_ptr<LiteralReal> UmlFactoryImpl::createLiteralReal(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<LiteralRealImpl> element(new LiteralRealImpl());
	element->setMetaElementID(metaElementID);
	element->setThisLiteralRealPtr(element);
	return element;
}
std::shared_ptr<LiteralReal> UmlFactoryImpl::createLiteralReal_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<LiteralRealImpl> element(new LiteralRealImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisLiteralRealPtr(element);
	return element;
	
}
std::shared_ptr<LiteralReal> UmlFactoryImpl::createLiteralReal_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<LiteralRealImpl> element(new LiteralRealImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisLiteralRealPtr(element);
	return element;
	
}
std::shared_ptr<LiteralReal> UmlFactoryImpl::createLiteralReal_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<LiteralRealImpl> element(new LiteralRealImpl(par_owningPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisLiteralRealPtr(element);
	return element;
	
}
std::shared_ptr<LiteralReal> UmlFactoryImpl::createLiteralReal_in_OwningSlot(std::weak_ptr<uml::Slot > par_owningSlot, const int metaElementID) const
{
	std::shared_ptr<LiteralRealImpl> element(new LiteralRealImpl(par_owningSlot));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningSlot.lock())
	{
			wp->getValue()->push_back(element);
	}
	element->setThisLiteralRealPtr(element);
	return element;
	
}
std::shared_ptr<LiteralReal> UmlFactoryImpl::createLiteralReal_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<LiteralRealImpl> element(new LiteralRealImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisLiteralRealPtr(element);
	return element;
	
}
std::shared_ptr<LiteralReal> UmlFactoryImpl::createLiteralReal_in_ValueSpecificationAction(std::weak_ptr<uml::ValueSpecificationAction > par_valueSpecificationAction, const int metaElementID) const
{
	std::shared_ptr<LiteralRealImpl> element(new LiteralRealImpl(par_valueSpecificationAction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_valueSpecificationAction.lock())
	{
			wp->setValue(element);
	}
	element->setThisLiteralRealPtr(element);
	return element;
	
}
std::shared_ptr<LiteralString> UmlFactoryImpl::createLiteralString(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<LiteralStringImpl> element(new LiteralStringImpl());
	element->setMetaElementID(metaElementID);
	element->setThisLiteralStringPtr(element);
	return element;
}
std::shared_ptr<LiteralString> UmlFactoryImpl::createLiteralString_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<LiteralStringImpl> element(new LiteralStringImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisLiteralStringPtr(element);
	return element;
	
}
std::shared_ptr<LiteralString> UmlFactoryImpl::createLiteralString_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<LiteralStringImpl> element(new LiteralStringImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisLiteralStringPtr(element);
	return element;
	
}
std::shared_ptr<LiteralString> UmlFactoryImpl::createLiteralString_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<LiteralStringImpl> element(new LiteralStringImpl(par_owningPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisLiteralStringPtr(element);
	return element;
	
}
std::shared_ptr<LiteralString> UmlFactoryImpl::createLiteralString_in_OwningSlot(std::weak_ptr<uml::Slot > par_owningSlot, const int metaElementID) const
{
	std::shared_ptr<LiteralStringImpl> element(new LiteralStringImpl(par_owningSlot));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningSlot.lock())
	{
			wp->getValue()->push_back(element);
	}
	element->setThisLiteralStringPtr(element);
	return element;
	
}
std::shared_ptr<LiteralString> UmlFactoryImpl::createLiteralString_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<LiteralStringImpl> element(new LiteralStringImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisLiteralStringPtr(element);
	return element;
	
}
std::shared_ptr<LiteralString> UmlFactoryImpl::createLiteralString_in_ValueSpecificationAction(std::weak_ptr<uml::ValueSpecificationAction > par_valueSpecificationAction, const int metaElementID) const
{
	std::shared_ptr<LiteralStringImpl> element(new LiteralStringImpl(par_valueSpecificationAction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_valueSpecificationAction.lock())
	{
			wp->setValue(element);
	}
	element->setThisLiteralStringPtr(element);
	return element;
	
}
std::shared_ptr<LiteralUnlimitedNatural> UmlFactoryImpl::createLiteralUnlimitedNatural(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<LiteralUnlimitedNaturalImpl> element(new LiteralUnlimitedNaturalImpl());
	element->setMetaElementID(metaElementID);
	element->setThisLiteralUnlimitedNaturalPtr(element);
	return element;
}
std::shared_ptr<LiteralUnlimitedNatural> UmlFactoryImpl::createLiteralUnlimitedNatural_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<LiteralUnlimitedNaturalImpl> element(new LiteralUnlimitedNaturalImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisLiteralUnlimitedNaturalPtr(element);
	return element;
	
}
std::shared_ptr<LiteralUnlimitedNatural> UmlFactoryImpl::createLiteralUnlimitedNatural_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<LiteralUnlimitedNaturalImpl> element(new LiteralUnlimitedNaturalImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisLiteralUnlimitedNaturalPtr(element);
	return element;
	
}
std::shared_ptr<LiteralUnlimitedNatural> UmlFactoryImpl::createLiteralUnlimitedNatural_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<LiteralUnlimitedNaturalImpl> element(new LiteralUnlimitedNaturalImpl(par_owningPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisLiteralUnlimitedNaturalPtr(element);
	return element;
	
}
std::shared_ptr<LiteralUnlimitedNatural> UmlFactoryImpl::createLiteralUnlimitedNatural_in_OwningSlot(std::weak_ptr<uml::Slot > par_owningSlot, const int metaElementID) const
{
	std::shared_ptr<LiteralUnlimitedNaturalImpl> element(new LiteralUnlimitedNaturalImpl(par_owningSlot));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningSlot.lock())
	{
			wp->getValue()->push_back(element);
	}
	element->setThisLiteralUnlimitedNaturalPtr(element);
	return element;
	
}
std::shared_ptr<LiteralUnlimitedNatural> UmlFactoryImpl::createLiteralUnlimitedNatural_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<LiteralUnlimitedNaturalImpl> element(new LiteralUnlimitedNaturalImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisLiteralUnlimitedNaturalPtr(element);
	return element;
	
}
std::shared_ptr<LiteralUnlimitedNatural> UmlFactoryImpl::createLiteralUnlimitedNatural_in_ValueSpecificationAction(std::weak_ptr<uml::ValueSpecificationAction > par_valueSpecificationAction, const int metaElementID) const
{
	std::shared_ptr<LiteralUnlimitedNaturalImpl> element(new LiteralUnlimitedNaturalImpl(par_valueSpecificationAction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_valueSpecificationAction.lock())
	{
			wp->setValue(element);
	}
	element->setThisLiteralUnlimitedNaturalPtr(element);
	return element;
	
}
std::shared_ptr<LoopNode> UmlFactoryImpl::createLoopNode(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<LoopNodeImpl> element(new LoopNodeImpl());
	element->setMetaElementID(metaElementID);
	element->setThisLoopNodePtr(element);
	return element;
}
std::shared_ptr<LoopNode> UmlFactoryImpl::createLoopNode_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<LoopNodeImpl> element(new LoopNodeImpl(par_activity, UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisLoopNodePtr(element);
	return element;
	
}
std::shared_ptr<LoopNode> UmlFactoryImpl::createLoopNode_in_InActivity(std::weak_ptr<uml::Activity > par_inActivity, const int metaElementID) const
{
	std::shared_ptr<LoopNodeImpl> element(new LoopNodeImpl(par_inActivity, UmlPackage::ACTIVITYGROUP_ATTRIBUTE_INACTIVITY));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inActivity.lock())
	{
			wp->getGroup()->push_back(element);
	}
	element->setThisLoopNodePtr(element);
	return element;
	
}
std::shared_ptr<LoopNode> UmlFactoryImpl::createLoopNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<LoopNodeImpl> element(new LoopNodeImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisLoopNodePtr(element);
	return element;
	
}
std::shared_ptr<LoopNode> UmlFactoryImpl::createLoopNode_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<LoopNodeImpl> element(new LoopNodeImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisLoopNodePtr(element);
	return element;
	
}
std::shared_ptr<LoopNode> UmlFactoryImpl::createLoopNode_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<LoopNodeImpl> element(new LoopNodeImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisLoopNodePtr(element);
	return element;
	
}
std::shared_ptr<LoopNode> UmlFactoryImpl::createLoopNode_in_SuperGroup(std::weak_ptr<uml::ActivityGroup > par_superGroup, const int metaElementID) const
{
	std::shared_ptr<LoopNodeImpl> element(new LoopNodeImpl(par_superGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_superGroup.lock())
	{
			wp->getSubgroup()->push_back(element);
	}
	element->setThisLoopNodePtr(element);
	return element;
	
}
std::shared_ptr<Manifestation> UmlFactoryImpl::createManifestation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ManifestationImpl> element(new ManifestationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisManifestationPtr(element);
	return element;
}
std::shared_ptr<Manifestation> UmlFactoryImpl::createManifestation_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ManifestationImpl> element(new ManifestationImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisManifestationPtr(element);
	return element;
	
}
std::shared_ptr<Manifestation> UmlFactoryImpl::createManifestation_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ManifestationImpl> element(new ManifestationImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisManifestationPtr(element);
	return element;
	
}
std::shared_ptr<Manifestation> UmlFactoryImpl::createManifestation_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<ManifestationImpl> element(new ManifestationImpl(par_owningPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisManifestationPtr(element);
	return element;
	
}
std::shared_ptr<Manifestation> UmlFactoryImpl::createManifestation_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<ManifestationImpl> element(new ManifestationImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisManifestationPtr(element);
	return element;
	
}
std::shared_ptr<MergeNode> UmlFactoryImpl::createMergeNode(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<MergeNodeImpl> element(new MergeNodeImpl());
	element->setMetaElementID(metaElementID);
	element->setThisMergeNodePtr(element);
	return element;
}
std::shared_ptr<MergeNode> UmlFactoryImpl::createMergeNode_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<MergeNodeImpl> element(new MergeNodeImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisMergeNodePtr(element);
	return element;
	
}
std::shared_ptr<MergeNode> UmlFactoryImpl::createMergeNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<MergeNodeImpl> element(new MergeNodeImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisMergeNodePtr(element);
	return element;
	
}
std::shared_ptr<MergeNode> UmlFactoryImpl::createMergeNode_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<MergeNodeImpl> element(new MergeNodeImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisMergeNodePtr(element);
	return element;
	
}
std::shared_ptr<MergeNode> UmlFactoryImpl::createMergeNode_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<MergeNodeImpl> element(new MergeNodeImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisMergeNodePtr(element);
	return element;
	
}
std::shared_ptr<Message> UmlFactoryImpl::createMessage(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<MessageImpl> element(new MessageImpl());
	element->setMetaElementID(metaElementID);
	element->setThisMessagePtr(element);
	return element;
}
std::shared_ptr<Message> UmlFactoryImpl::createMessage_in_Interaction(std::weak_ptr<uml::Interaction > par_interaction, const int metaElementID) const
{
	std::shared_ptr<MessageImpl> element(new MessageImpl(par_interaction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_interaction.lock())
	{
			wp->getMessage()->push_back(element);
	}
	element->setThisMessagePtr(element);
	return element;
	
}
std::shared_ptr<Message> UmlFactoryImpl::createMessage_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<MessageImpl> element(new MessageImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisMessagePtr(element);
	return element;
	
}
std::shared_ptr<Message> UmlFactoryImpl::createMessage_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<MessageImpl> element(new MessageImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisMessagePtr(element);
	return element;
	
}
std::shared_ptr<MessageOccurrenceSpecification> UmlFactoryImpl::createMessageOccurrenceSpecification(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<MessageOccurrenceSpecificationImpl> element(new MessageOccurrenceSpecificationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisMessageOccurrenceSpecificationPtr(element);
	return element;
}
std::shared_ptr<MessageOccurrenceSpecification> UmlFactoryImpl::createMessageOccurrenceSpecification_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction, const int metaElementID) const
{
	std::shared_ptr<MessageOccurrenceSpecificationImpl> element(new MessageOccurrenceSpecificationImpl(par_enclosingInteraction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_enclosingInteraction.lock())
	{
			wp->getFragment()->push_back(element);
	}
	element->setThisMessageOccurrenceSpecificationPtr(element);
	return element;
	
}
std::shared_ptr<MessageOccurrenceSpecification> UmlFactoryImpl::createMessageOccurrenceSpecification_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand, const int metaElementID) const
{
	std::shared_ptr<MessageOccurrenceSpecificationImpl> element(new MessageOccurrenceSpecificationImpl(par_enclosingOperand));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_enclosingOperand.lock())
	{
			wp->getFragment()->push_back(element);
	}
	element->setThisMessageOccurrenceSpecificationPtr(element);
	return element;
	
}
std::shared_ptr<MessageOccurrenceSpecification> UmlFactoryImpl::createMessageOccurrenceSpecification_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<MessageOccurrenceSpecificationImpl> element(new MessageOccurrenceSpecificationImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisMessageOccurrenceSpecificationPtr(element);
	return element;
	
}
std::shared_ptr<MessageOccurrenceSpecification> UmlFactoryImpl::createMessageOccurrenceSpecification_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<MessageOccurrenceSpecificationImpl> element(new MessageOccurrenceSpecificationImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisMessageOccurrenceSpecificationPtr(element);
	return element;
	
}
std::shared_ptr<Model> UmlFactoryImpl::createModel(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ModelImpl> element(new ModelImpl());
	element->setMetaElementID(metaElementID);
	element->setThisModelPtr(element);
	return element;
}
std::shared_ptr<Model> UmlFactoryImpl::createModel_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ModelImpl> element(new ModelImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisModelPtr(element);
	return element;
	
}
std::shared_ptr<Model> UmlFactoryImpl::createModel_in_NestingPackage(std::weak_ptr<uml::Package > par_nestingPackage, const int metaElementID) const
{
	std::shared_ptr<ModelImpl> element(new ModelImpl(par_nestingPackage, UmlPackage::PACKAGE_ATTRIBUTE_NESTINGPACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_nestingPackage.lock())
	{
			wp->getNestedPackage()->push_back(element);
	}
	element->setThisModelPtr(element);
	return element;
	
}
std::shared_ptr<Model> UmlFactoryImpl::createModel_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ModelImpl> element(new ModelImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisModelPtr(element);
	return element;
	
}
std::shared_ptr<Model> UmlFactoryImpl::createModel_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<ModelImpl> element(new ModelImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisModelPtr(element);
	return element;
	
}
std::shared_ptr<Model> UmlFactoryImpl::createModel_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<ModelImpl> element(new ModelImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisModelPtr(element);
	return element;
	
}
std::shared_ptr<Node> UmlFactoryImpl::createNode(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<NodeImpl> element(new NodeImpl());
	element->setMetaElementID(metaElementID);
	element->setThisNodePtr(element);
	return element;
}
std::shared_ptr<Node> UmlFactoryImpl::createNode_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<NodeImpl> element(new NodeImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisNodePtr(element);
	return element;
	
}
std::shared_ptr<Node> UmlFactoryImpl::createNode_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<NodeImpl> element(new NodeImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisNodePtr(element);
	return element;
	
}
std::shared_ptr<Node> UmlFactoryImpl::createNode_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<NodeImpl> element(new NodeImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisNodePtr(element);
	return element;
	
}
std::shared_ptr<Node> UmlFactoryImpl::createNode_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<NodeImpl> element(new NodeImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisNodePtr(element);
	return element;
	
}
std::shared_ptr<Node> UmlFactoryImpl::createNode_in_Package(std::weak_ptr<uml::Package > par_package, const int metaElementID) const
{
	std::shared_ptr<NodeImpl> element(new NodeImpl(par_package, UmlPackage::TYPE_ATTRIBUTE_PACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_package.lock())
	{
			wp->getOwnedType()->push_back(element);
	}
	element->setThisNodePtr(element);
	return element;
	
}
std::shared_ptr<Object> UmlFactoryImpl::createObject(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ObjectImpl> element(new ObjectImpl());
	element->setMetaElementID(metaElementID);
	element->setThisObjectPtr(element);
	return element;
}
std::shared_ptr<ObjectFlow> UmlFactoryImpl::createObjectFlow(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ObjectFlowImpl> element(new ObjectFlowImpl());
	element->setMetaElementID(metaElementID);
	element->setThisObjectFlowPtr(element);
	return element;
}
std::shared_ptr<ObjectFlow> UmlFactoryImpl::createObjectFlow_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<ObjectFlowImpl> element(new ObjectFlowImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getEdge()->push_back(element);
	}
	element->setThisObjectFlowPtr(element);
	return element;
	
}
std::shared_ptr<ObjectFlow> UmlFactoryImpl::createObjectFlow_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<ObjectFlowImpl> element(new ObjectFlowImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getEdge()->push_back(element);
	}
	element->setThisObjectFlowPtr(element);
	return element;
	
}
std::shared_ptr<ObjectFlow> UmlFactoryImpl::createObjectFlow_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ObjectFlowImpl> element(new ObjectFlowImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisObjectFlowPtr(element);
	return element;
	
}
std::shared_ptr<ObjectFlow> UmlFactoryImpl::createObjectFlow_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ObjectFlowImpl> element(new ObjectFlowImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisObjectFlowPtr(element);
	return element;
	
}
std::shared_ptr<OccurrenceSpecification> UmlFactoryImpl::createOccurrenceSpecification(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<OccurrenceSpecificationImpl> element(new OccurrenceSpecificationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisOccurrenceSpecificationPtr(element);
	return element;
}
std::shared_ptr<OccurrenceSpecification> UmlFactoryImpl::createOccurrenceSpecification_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction, const int metaElementID) const
{
	std::shared_ptr<OccurrenceSpecificationImpl> element(new OccurrenceSpecificationImpl(par_enclosingInteraction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_enclosingInteraction.lock())
	{
			wp->getFragment()->push_back(element);
	}
	element->setThisOccurrenceSpecificationPtr(element);
	return element;
	
}
std::shared_ptr<OccurrenceSpecification> UmlFactoryImpl::createOccurrenceSpecification_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand, const int metaElementID) const
{
	std::shared_ptr<OccurrenceSpecificationImpl> element(new OccurrenceSpecificationImpl(par_enclosingOperand));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_enclosingOperand.lock())
	{
			wp->getFragment()->push_back(element);
	}
	element->setThisOccurrenceSpecificationPtr(element);
	return element;
	
}
std::shared_ptr<OccurrenceSpecification> UmlFactoryImpl::createOccurrenceSpecification_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<OccurrenceSpecificationImpl> element(new OccurrenceSpecificationImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisOccurrenceSpecificationPtr(element);
	return element;
	
}
std::shared_ptr<OccurrenceSpecification> UmlFactoryImpl::createOccurrenceSpecification_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<OccurrenceSpecificationImpl> element(new OccurrenceSpecificationImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisOccurrenceSpecificationPtr(element);
	return element;
	
}
std::shared_ptr<OpaqueAction> UmlFactoryImpl::createOpaqueAction(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<OpaqueActionImpl> element(new OpaqueActionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisOpaqueActionPtr(element);
	return element;
}
std::shared_ptr<OpaqueAction> UmlFactoryImpl::createOpaqueAction_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<OpaqueActionImpl> element(new OpaqueActionImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisOpaqueActionPtr(element);
	return element;
	
}
std::shared_ptr<OpaqueAction> UmlFactoryImpl::createOpaqueAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<OpaqueActionImpl> element(new OpaqueActionImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisOpaqueActionPtr(element);
	return element;
	
}
std::shared_ptr<OpaqueAction> UmlFactoryImpl::createOpaqueAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<OpaqueActionImpl> element(new OpaqueActionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisOpaqueActionPtr(element);
	return element;
	
}
std::shared_ptr<OpaqueAction> UmlFactoryImpl::createOpaqueAction_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<OpaqueActionImpl> element(new OpaqueActionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisOpaqueActionPtr(element);
	return element;
	
}
std::shared_ptr<OpaqueBehavior> UmlFactoryImpl::createOpaqueBehavior(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<OpaqueBehaviorImpl> element(new OpaqueBehaviorImpl());
	element->setMetaElementID(metaElementID);
	element->setThisOpaqueBehaviorPtr(element);
	return element;
}
std::shared_ptr<OpaqueBehavior> UmlFactoryImpl::createOpaqueBehavior_in_BehavioredClassifier(std::weak_ptr<uml::BehavioredClassifier > par_behavioredClassifier, const int metaElementID) const
{
	std::shared_ptr<OpaqueBehaviorImpl> element(new OpaqueBehaviorImpl(par_behavioredClassifier));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_behavioredClassifier.lock())
	{
			wp->getOwnedBehavior()->push_back(element);
	}
	element->setThisOpaqueBehaviorPtr(element);
	return element;
	
}
std::shared_ptr<OpaqueBehavior> UmlFactoryImpl::createOpaqueBehavior_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<OpaqueBehaviorImpl> element(new OpaqueBehaviorImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisOpaqueBehaviorPtr(element);
	return element;
	
}
std::shared_ptr<OpaqueBehavior> UmlFactoryImpl::createOpaqueBehavior_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<OpaqueBehaviorImpl> element(new OpaqueBehaviorImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisOpaqueBehaviorPtr(element);
	return element;
	
}
std::shared_ptr<OpaqueBehavior> UmlFactoryImpl::createOpaqueBehavior_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<OpaqueBehaviorImpl> element(new OpaqueBehaviorImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisOpaqueBehaviorPtr(element);
	return element;
	
}
std::shared_ptr<OpaqueBehavior> UmlFactoryImpl::createOpaqueBehavior_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<OpaqueBehaviorImpl> element(new OpaqueBehaviorImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisOpaqueBehaviorPtr(element);
	return element;
	
}
std::shared_ptr<OpaqueBehavior> UmlFactoryImpl::createOpaqueBehavior_in_Package(std::weak_ptr<uml::Package > par_package, const int metaElementID) const
{
	std::shared_ptr<OpaqueBehaviorImpl> element(new OpaqueBehaviorImpl(par_package, UmlPackage::TYPE_ATTRIBUTE_PACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_package.lock())
	{
			wp->getOwnedType()->push_back(element);
	}
	element->setThisOpaqueBehaviorPtr(element);
	return element;
	
}
std::shared_ptr<OpaqueExpression> UmlFactoryImpl::createOpaqueExpression(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<OpaqueExpressionImpl> element(new OpaqueExpressionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisOpaqueExpressionPtr(element);
	return element;
}
std::shared_ptr<OpaqueExpression> UmlFactoryImpl::createOpaqueExpression_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<OpaqueExpressionImpl> element(new OpaqueExpressionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisOpaqueExpressionPtr(element);
	return element;
	
}
std::shared_ptr<OpaqueExpression> UmlFactoryImpl::createOpaqueExpression_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<OpaqueExpressionImpl> element(new OpaqueExpressionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisOpaqueExpressionPtr(element);
	return element;
	
}
std::shared_ptr<OpaqueExpression> UmlFactoryImpl::createOpaqueExpression_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<OpaqueExpressionImpl> element(new OpaqueExpressionImpl(par_owningPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisOpaqueExpressionPtr(element);
	return element;
	
}
std::shared_ptr<OpaqueExpression> UmlFactoryImpl::createOpaqueExpression_in_OwningSlot(std::weak_ptr<uml::Slot > par_owningSlot, const int metaElementID) const
{
	std::shared_ptr<OpaqueExpressionImpl> element(new OpaqueExpressionImpl(par_owningSlot));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningSlot.lock())
	{
			wp->getValue()->push_back(element);
	}
	element->setThisOpaqueExpressionPtr(element);
	return element;
	
}
std::shared_ptr<OpaqueExpression> UmlFactoryImpl::createOpaqueExpression_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<OpaqueExpressionImpl> element(new OpaqueExpressionImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisOpaqueExpressionPtr(element);
	return element;
	
}
std::shared_ptr<OpaqueExpression> UmlFactoryImpl::createOpaqueExpression_in_ValueSpecificationAction(std::weak_ptr<uml::ValueSpecificationAction > par_valueSpecificationAction, const int metaElementID) const
{
	std::shared_ptr<OpaqueExpressionImpl> element(new OpaqueExpressionImpl(par_valueSpecificationAction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_valueSpecificationAction.lock())
	{
			wp->setValue(element);
	}
	element->setThisOpaqueExpressionPtr(element);
	return element;
	
}
std::shared_ptr<Operation> UmlFactoryImpl::createOperation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<OperationImpl> element(new OperationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisOperationPtr(element);
	return element;
}
std::shared_ptr<Operation> UmlFactoryImpl::createOperation_in_Class(std::weak_ptr<uml::Class > par_class, const int metaElementID) const
{
	std::shared_ptr<OperationImpl> element(new OperationImpl(par_class));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_class.lock())
	{
			wp->getOwnedOperation()->push_back(element);
	}
	element->setThisOperationPtr(element);
	return element;
	
}
std::shared_ptr<Operation> UmlFactoryImpl::createOperation_in_Datatype(std::weak_ptr<uml::DataType > par_datatype, const int metaElementID) const
{
	std::shared_ptr<OperationImpl> element(new OperationImpl(par_datatype));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_datatype.lock())
	{
			wp->getOwnedOperation()->push_back(element);
	}
	element->setThisOperationPtr(element);
	return element;
	
}
std::shared_ptr<Operation> UmlFactoryImpl::createOperation_in_Interface(std::weak_ptr<uml::Interface > par_interface, const int metaElementID) const
{
	std::shared_ptr<OperationImpl> element(new OperationImpl(par_interface));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_interface.lock())
	{
			wp->getOwnedOperation()->push_back(element);
	}
	element->setThisOperationPtr(element);
	return element;
	
}
std::shared_ptr<Operation> UmlFactoryImpl::createOperation_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<OperationImpl> element(new OperationImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisOperationPtr(element);
	return element;
	
}
std::shared_ptr<Operation> UmlFactoryImpl::createOperation_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<OperationImpl> element(new OperationImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisOperationPtr(element);
	return element;
	
}
std::shared_ptr<Operation> UmlFactoryImpl::createOperation_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<OperationImpl> element(new OperationImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisOperationPtr(element);
	return element;
	
}
std::shared_ptr<OperationTemplateParameter> UmlFactoryImpl::createOperationTemplateParameter(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<OperationTemplateParameterImpl> element(new OperationTemplateParameterImpl());
	element->setMetaElementID(metaElementID);
	element->setThisOperationTemplateParameterPtr(element);
	return element;
}
std::shared_ptr<OperationTemplateParameter> UmlFactoryImpl::createOperationTemplateParameter_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<OperationTemplateParameterImpl> element(new OperationTemplateParameterImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisOperationTemplateParameterPtr(element);
	return element;
	
}
std::shared_ptr<OperationTemplateParameter> UmlFactoryImpl::createOperationTemplateParameter_in_Signature(std::weak_ptr<uml::TemplateSignature > par_signature, const int metaElementID) const
{
	std::shared_ptr<OperationTemplateParameterImpl> element(new OperationTemplateParameterImpl(par_signature));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_signature.lock())
	{
			wp->getOwnedParameter()->push_back(element);
	}
	element->setThisOperationTemplateParameterPtr(element);
	return element;
	
}
std::shared_ptr<OutputPin> UmlFactoryImpl::createOutputPin(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<OutputPinImpl> element(new OutputPinImpl());
	element->setMetaElementID(metaElementID);
	element->setThisOutputPinPtr(element);
	return element;
}
std::shared_ptr<OutputPin> UmlFactoryImpl::createOutputPin_in_Action(std::weak_ptr<uml::Action > par_action, const int metaElementID) const
{
	std::shared_ptr<OutputPinImpl> element(new OutputPinImpl(par_action));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_action.lock())
	{
			wp->getOutput()->push_back(element);
	}
	element->setThisOutputPinPtr(element);
	return element;
	
}
std::shared_ptr<OutputPin> UmlFactoryImpl::createOutputPin_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<OutputPinImpl> element(new OutputPinImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisOutputPinPtr(element);
	return element;
	
}
std::shared_ptr<OutputPin> UmlFactoryImpl::createOutputPin_in_CallAction(std::weak_ptr<uml::CallAction > par_callAction, const int metaElementID) const
{
	std::shared_ptr<OutputPinImpl> element(new OutputPinImpl(par_callAction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_callAction.lock())
	{
			wp->getResult()->push_back(element);
	}
	element->setThisOutputPinPtr(element);
	return element;
	
}
std::shared_ptr<OutputPin> UmlFactoryImpl::createOutputPin_in_ClearStructuralFeatureAction(std::weak_ptr<uml::ClearStructuralFeatureAction > par_clearStructuralFeatureAction, const int metaElementID) const
{
	std::shared_ptr<OutputPinImpl> element(new OutputPinImpl(par_clearStructuralFeatureAction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_clearStructuralFeatureAction.lock())
	{
			wp->setResult(element);
	}
	element->setThisOutputPinPtr(element);
	return element;
	
}
std::shared_ptr<OutputPin> UmlFactoryImpl::createOutputPin_in_CreateObjectAction(std::weak_ptr<uml::CreateObjectAction > par_createObjectAction, const int metaElementID) const
{
	std::shared_ptr<OutputPinImpl> element(new OutputPinImpl(par_createObjectAction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_createObjectAction.lock())
	{
			wp->setResult(element);
	}
	element->setThisOutputPinPtr(element);
	return element;
	
}
std::shared_ptr<OutputPin> UmlFactoryImpl::createOutputPin_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<OutputPinImpl> element(new OutputPinImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisOutputPinPtr(element);
	return element;
	
}
std::shared_ptr<OutputPin> UmlFactoryImpl::createOutputPin_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<OutputPinImpl> element(new OutputPinImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisOutputPinPtr(element);
	return element;
	
}
std::shared_ptr<OutputPin> UmlFactoryImpl::createOutputPin_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<OutputPinImpl> element(new OutputPinImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisOutputPinPtr(element);
	return element;
	
}
std::shared_ptr<OutputPin> UmlFactoryImpl::createOutputPin_in_ReadSelfAction(std::weak_ptr<uml::ReadSelfAction > par_readSelfAction, const int metaElementID) const
{
	std::shared_ptr<OutputPinImpl> element(new OutputPinImpl(par_readSelfAction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_readSelfAction.lock())
	{
			wp->setResult(element);
	}
	element->setThisOutputPinPtr(element);
	return element;
	
}
std::shared_ptr<OutputPin> UmlFactoryImpl::createOutputPin_in_ReadStructuralFeatureAction(std::weak_ptr<uml::ReadStructuralFeatureAction > par_readStructuralFeatureAction, const int metaElementID) const
{
	std::shared_ptr<OutputPinImpl> element(new OutputPinImpl(par_readStructuralFeatureAction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_readStructuralFeatureAction.lock())
	{
			wp->setResult(element);
	}
	element->setThisOutputPinPtr(element);
	return element;
	
}
std::shared_ptr<OutputPin> UmlFactoryImpl::createOutputPin_in_ValueSpecificationAction(std::weak_ptr<uml::ValueSpecificationAction > par_valueSpecificationAction, const int metaElementID) const
{
	std::shared_ptr<OutputPinImpl> element(new OutputPinImpl(par_valueSpecificationAction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_valueSpecificationAction.lock())
	{
			wp->setResult(element);
	}
	element->setThisOutputPinPtr(element);
	return element;
	
}
std::shared_ptr<OutputPin> UmlFactoryImpl::createOutputPin_in_WriteStructuralFeatureAction(std::weak_ptr<uml::WriteStructuralFeatureAction > par_writeStructuralFeatureAction, const int metaElementID) const
{
	std::shared_ptr<OutputPinImpl> element(new OutputPinImpl(par_writeStructuralFeatureAction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_writeStructuralFeatureAction.lock())
	{
			wp->setResult(element);
	}
	element->setThisOutputPinPtr(element);
	return element;
	
}
std::shared_ptr<Package> UmlFactoryImpl::createPackage(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PackageImpl> element(new PackageImpl());
	element->setMetaElementID(metaElementID);
	element->setThisPackagePtr(element);
	return element;
}
std::shared_ptr<Package> UmlFactoryImpl::createPackage_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<PackageImpl> element(new PackageImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisPackagePtr(element);
	return element;
	
}
std::shared_ptr<Package> UmlFactoryImpl::createPackage_in_NestingPackage(std::weak_ptr<uml::Package > par_nestingPackage, const int metaElementID) const
{
	std::shared_ptr<PackageImpl> element(new PackageImpl(par_nestingPackage, UmlPackage::PACKAGE_ATTRIBUTE_NESTINGPACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_nestingPackage.lock())
	{
			wp->getNestedPackage()->push_back(element);
	}
	element->setThisPackagePtr(element);
	return element;
	
}
std::shared_ptr<Package> UmlFactoryImpl::createPackage_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<PackageImpl> element(new PackageImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisPackagePtr(element);
	return element;
	
}
std::shared_ptr<Package> UmlFactoryImpl::createPackage_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<PackageImpl> element(new PackageImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getNestedPackage()->push_back(element);
	}
	element->setThisPackagePtr(element);
	return element;
	
}
std::shared_ptr<Package> UmlFactoryImpl::createPackage_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<PackageImpl> element(new PackageImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisPackagePtr(element);
	return element;
	
}
std::shared_ptr<PackageImport> UmlFactoryImpl::createPackageImport(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PackageImportImpl> element(new PackageImportImpl());
	element->setMetaElementID(metaElementID);
	element->setThisPackageImportPtr(element);
	return element;
}
std::shared_ptr<PackageImport> UmlFactoryImpl::createPackageImport_in_ImportingNamespace(std::weak_ptr<uml::Namespace > par_importingNamespace, const int metaElementID) const
{
	std::shared_ptr<PackageImportImpl> element(new PackageImportImpl(par_importingNamespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_importingNamespace.lock())
	{
			wp->getPackageImport()->push_back(element);
	}
	element->setThisPackageImportPtr(element);
	return element;
	
}
std::shared_ptr<PackageImport> UmlFactoryImpl::createPackageImport_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<PackageImportImpl> element(new PackageImportImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisPackageImportPtr(element);
	return element;
	
}
std::shared_ptr<PackageMerge> UmlFactoryImpl::createPackageMerge(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PackageMergeImpl> element(new PackageMergeImpl());
	element->setMetaElementID(metaElementID);
	element->setThisPackageMergePtr(element);
	return element;
}
std::shared_ptr<PackageMerge> UmlFactoryImpl::createPackageMerge_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<PackageMergeImpl> element(new PackageMergeImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisPackageMergePtr(element);
	return element;
	
}
std::shared_ptr<PackageMerge> UmlFactoryImpl::createPackageMerge_in_ReceivingPackage(std::weak_ptr<uml::Package > par_receivingPackage, const int metaElementID) const
{
	std::shared_ptr<PackageMergeImpl> element(new PackageMergeImpl(par_receivingPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_receivingPackage.lock())
	{
			wp->getPackageMerge()->push_back(element);
	}
	element->setThisPackageMergePtr(element);
	return element;
	
}
std::shared_ptr<Parameter> UmlFactoryImpl::createParameter(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ParameterImpl> element(new ParameterImpl());
	element->setMetaElementID(metaElementID);
	element->setThisParameterPtr(element);
	return element;
}
std::shared_ptr<Parameter> UmlFactoryImpl::createParameter_in_Behavior(std::weak_ptr<uml::Behavior > par_behavior, const int metaElementID) const
{
	std::shared_ptr<ParameterImpl> element(new ParameterImpl(par_behavior));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_behavior.lock())
	{
			wp->getOwnedParameter()->push_back(element);
	}
	element->setThisParameterPtr(element);
	return element;
	
}
std::shared_ptr<Parameter> UmlFactoryImpl::createParameter_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ParameterImpl> element(new ParameterImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisParameterPtr(element);
	return element;
	
}
std::shared_ptr<Parameter> UmlFactoryImpl::createParameter_in_Operation(std::weak_ptr<uml::Operation > par_operation, const int metaElementID) const
{
	std::shared_ptr<ParameterImpl> element(new ParameterImpl(par_operation));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_operation.lock())
	{
			wp->getOwnedParameter()->push_back(element);
	}
	element->setThisParameterPtr(element);
	return element;
	
}
std::shared_ptr<Parameter> UmlFactoryImpl::createParameter_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ParameterImpl> element(new ParameterImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisParameterPtr(element);
	return element;
	
}
std::shared_ptr<Parameter> UmlFactoryImpl::createParameter_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<ParameterImpl> element(new ParameterImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisParameterPtr(element);
	return element;
	
}
std::shared_ptr<ParameterSet> UmlFactoryImpl::createParameterSet(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ParameterSetImpl> element(new ParameterSetImpl());
	element->setMetaElementID(metaElementID);
	element->setThisParameterSetPtr(element);
	return element;
}
std::shared_ptr<ParameterSet> UmlFactoryImpl::createParameterSet_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ParameterSetImpl> element(new ParameterSetImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisParameterSetPtr(element);
	return element;
	
}
std::shared_ptr<ParameterSet> UmlFactoryImpl::createParameterSet_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ParameterSetImpl> element(new ParameterSetImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisParameterSetPtr(element);
	return element;
	
}
std::shared_ptr<PartDecomposition> UmlFactoryImpl::createPartDecomposition(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PartDecompositionImpl> element(new PartDecompositionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisPartDecompositionPtr(element);
	return element;
}
std::shared_ptr<PartDecomposition> UmlFactoryImpl::createPartDecomposition_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction, const int metaElementID) const
{
	std::shared_ptr<PartDecompositionImpl> element(new PartDecompositionImpl(par_enclosingInteraction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_enclosingInteraction.lock())
	{
			wp->getFragment()->push_back(element);
	}
	element->setThisPartDecompositionPtr(element);
	return element;
	
}
std::shared_ptr<PartDecomposition> UmlFactoryImpl::createPartDecomposition_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand, const int metaElementID) const
{
	std::shared_ptr<PartDecompositionImpl> element(new PartDecompositionImpl(par_enclosingOperand));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_enclosingOperand.lock())
	{
			wp->getFragment()->push_back(element);
	}
	element->setThisPartDecompositionPtr(element);
	return element;
	
}
std::shared_ptr<PartDecomposition> UmlFactoryImpl::createPartDecomposition_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<PartDecompositionImpl> element(new PartDecompositionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisPartDecompositionPtr(element);
	return element;
	
}
std::shared_ptr<PartDecomposition> UmlFactoryImpl::createPartDecomposition_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<PartDecompositionImpl> element(new PartDecompositionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisPartDecompositionPtr(element);
	return element;
	
}
std::shared_ptr<Port> UmlFactoryImpl::createPort(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PortImpl> element(new PortImpl());
	element->setMetaElementID(metaElementID);
	element->setThisPortPtr(element);
	return element;
}
std::shared_ptr<Port> UmlFactoryImpl::createPort_in_AssociationEnd(std::weak_ptr<uml::Property > par_associationEnd, const int metaElementID) const
{
	std::shared_ptr<PortImpl> element(new PortImpl(par_associationEnd));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_associationEnd.lock())
	{
			wp->getQualifier()->push_back(element);
	}
	element->setThisPortPtr(element);
	return element;
	
}
std::shared_ptr<Port> UmlFactoryImpl::createPort_in_Class(std::weak_ptr<uml::Class > par_class, const int metaElementID) const
{
	std::shared_ptr<PortImpl> element(new PortImpl(par_class));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_class.lock())
	{
			wp->getOwnedPort()->push_back(element);
	}
	element->setThisPortPtr(element);
	return element;
	
}
std::shared_ptr<Port> UmlFactoryImpl::createPort_in_Datatype(std::weak_ptr<uml::DataType > par_datatype, const int metaElementID) const
{
	std::shared_ptr<PortImpl> element(new PortImpl(par_datatype));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_datatype.lock())
	{
			wp->getOwnedAttribute()->push_back(element);
	}
	element->setThisPortPtr(element);
	return element;
	
}
std::shared_ptr<Port> UmlFactoryImpl::createPort_in_Interface(std::weak_ptr<uml::Interface > par_interface, const int metaElementID) const
{
	std::shared_ptr<PortImpl> element(new PortImpl(par_interface));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_interface.lock())
	{
			wp->getOwnedAttribute()->push_back(element);
	}
	element->setThisPortPtr(element);
	return element;
	
}
std::shared_ptr<Port> UmlFactoryImpl::createPort_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<PortImpl> element(new PortImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisPortPtr(element);
	return element;
	
}
std::shared_ptr<Port> UmlFactoryImpl::createPort_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<PortImpl> element(new PortImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisPortPtr(element);
	return element;
	
}
std::shared_ptr<Port> UmlFactoryImpl::createPort_in_OwningAssociation(std::weak_ptr<uml::Association > par_owningAssociation, const int metaElementID) const
{
	std::shared_ptr<PortImpl> element(new PortImpl(par_owningAssociation));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningAssociation.lock())
	{
			wp->getOwnedEnd()->push_back(element);
	}
	element->setThisPortPtr(element);
	return element;
	
}
std::shared_ptr<Port> UmlFactoryImpl::createPort_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<PortImpl> element(new PortImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisPortPtr(element);
	return element;
	
}
std::shared_ptr<PrimitiveType> UmlFactoryImpl::createPrimitiveType(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PrimitiveTypeImpl> element(new PrimitiveTypeImpl());
	element->setMetaElementID(metaElementID);
	element->setThisPrimitiveTypePtr(element);
	return element;
}
std::shared_ptr<PrimitiveType> UmlFactoryImpl::createPrimitiveType_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<PrimitiveTypeImpl> element(new PrimitiveTypeImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisPrimitiveTypePtr(element);
	return element;
	
}
std::shared_ptr<PrimitiveType> UmlFactoryImpl::createPrimitiveType_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<PrimitiveTypeImpl> element(new PrimitiveTypeImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisPrimitiveTypePtr(element);
	return element;
	
}
std::shared_ptr<PrimitiveType> UmlFactoryImpl::createPrimitiveType_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<PrimitiveTypeImpl> element(new PrimitiveTypeImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisPrimitiveTypePtr(element);
	return element;
	
}
std::shared_ptr<PrimitiveType> UmlFactoryImpl::createPrimitiveType_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<PrimitiveTypeImpl> element(new PrimitiveTypeImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisPrimitiveTypePtr(element);
	return element;
	
}
std::shared_ptr<PrimitiveType> UmlFactoryImpl::createPrimitiveType_in_Package(std::weak_ptr<uml::Package > par_package, const int metaElementID) const
{
	std::shared_ptr<PrimitiveTypeImpl> element(new PrimitiveTypeImpl(par_package, UmlPackage::TYPE_ATTRIBUTE_PACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_package.lock())
	{
			wp->getOwnedType()->push_back(element);
	}
	element->setThisPrimitiveTypePtr(element);
	return element;
	
}
std::shared_ptr<Profile> UmlFactoryImpl::createProfile(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ProfileImpl> element(new ProfileImpl());
	element->setMetaElementID(metaElementID);
	element->setThisProfilePtr(element);
	return element;
}
std::shared_ptr<Profile> UmlFactoryImpl::createProfile_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ProfileImpl> element(new ProfileImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisProfilePtr(element);
	return element;
	
}
std::shared_ptr<Profile> UmlFactoryImpl::createProfile_in_NestingPackage(std::weak_ptr<uml::Package > par_nestingPackage, const int metaElementID) const
{
	std::shared_ptr<ProfileImpl> element(new ProfileImpl(par_nestingPackage, UmlPackage::PACKAGE_ATTRIBUTE_NESTINGPACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_nestingPackage.lock())
	{
			wp->getNestedPackage()->push_back(element);
	}
	element->setThisProfilePtr(element);
	return element;
	
}
std::shared_ptr<Profile> UmlFactoryImpl::createProfile_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ProfileImpl> element(new ProfileImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisProfilePtr(element);
	return element;
	
}
std::shared_ptr<Profile> UmlFactoryImpl::createProfile_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<ProfileImpl> element(new ProfileImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisProfilePtr(element);
	return element;
	
}
std::shared_ptr<Profile> UmlFactoryImpl::createProfile_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<ProfileImpl> element(new ProfileImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisProfilePtr(element);
	return element;
	
}
std::shared_ptr<ProfileApplication> UmlFactoryImpl::createProfileApplication(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ProfileApplicationImpl> element(new ProfileApplicationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisProfileApplicationPtr(element);
	return element;
}
std::shared_ptr<ProfileApplication> UmlFactoryImpl::createProfileApplication_in_ApplyingPackage(std::weak_ptr<uml::Package > par_applyingPackage, const int metaElementID) const
{
	std::shared_ptr<ProfileApplicationImpl> element(new ProfileApplicationImpl(par_applyingPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_applyingPackage.lock())
	{
			wp->getProfileApplication()->push_back(element);
	}
	element->setThisProfileApplicationPtr(element);
	return element;
	
}
std::shared_ptr<ProfileApplication> UmlFactoryImpl::createProfileApplication_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ProfileApplicationImpl> element(new ProfileApplicationImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisProfileApplicationPtr(element);
	return element;
	
}
std::shared_ptr<Property> UmlFactoryImpl::createProperty(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PropertyImpl> element(new PropertyImpl());
	element->setMetaElementID(metaElementID);
	element->setThisPropertyPtr(element);
	return element;
}
std::shared_ptr<Property> UmlFactoryImpl::createProperty_in_AssociationEnd(std::weak_ptr<uml::Property > par_associationEnd, const int metaElementID) const
{
	std::shared_ptr<PropertyImpl> element(new PropertyImpl(par_associationEnd));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_associationEnd.lock())
	{
			wp->getQualifier()->push_back(element);
	}
	element->setThisPropertyPtr(element);
	return element;
	
}
std::shared_ptr<Property> UmlFactoryImpl::createProperty_in_Class(std::weak_ptr<uml::Class > par_class, const int metaElementID) const
{
	std::shared_ptr<PropertyImpl> element(new PropertyImpl(par_class));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_class.lock())
	{
			wp->getOwnedAttribute()->push_back(element);
	}
	element->setThisPropertyPtr(element);
	return element;
	
}
std::shared_ptr<Property> UmlFactoryImpl::createProperty_in_Datatype(std::weak_ptr<uml::DataType > par_datatype, const int metaElementID) const
{
	std::shared_ptr<PropertyImpl> element(new PropertyImpl(par_datatype));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_datatype.lock())
	{
			wp->getOwnedAttribute()->push_back(element);
	}
	element->setThisPropertyPtr(element);
	return element;
	
}
std::shared_ptr<Property> UmlFactoryImpl::createProperty_in_Interface(std::weak_ptr<uml::Interface > par_interface, const int metaElementID) const
{
	std::shared_ptr<PropertyImpl> element(new PropertyImpl(par_interface));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_interface.lock())
	{
			wp->getOwnedAttribute()->push_back(element);
	}
	element->setThisPropertyPtr(element);
	return element;
	
}
std::shared_ptr<Property> UmlFactoryImpl::createProperty_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<PropertyImpl> element(new PropertyImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisPropertyPtr(element);
	return element;
	
}
std::shared_ptr<Property> UmlFactoryImpl::createProperty_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<PropertyImpl> element(new PropertyImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisPropertyPtr(element);
	return element;
	
}
std::shared_ptr<Property> UmlFactoryImpl::createProperty_in_OwningAssociation(std::weak_ptr<uml::Association > par_owningAssociation, const int metaElementID) const
{
	std::shared_ptr<PropertyImpl> element(new PropertyImpl(par_owningAssociation));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningAssociation.lock())
	{
			wp->getNavigableOwnedEnd()->push_back(element);
	}
	element->setThisPropertyPtr(element);
	return element;
	
}
std::shared_ptr<Property> UmlFactoryImpl::createProperty_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<PropertyImpl> element(new PropertyImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisPropertyPtr(element);
	return element;
	
}
std::shared_ptr<ProtocolConformance> UmlFactoryImpl::createProtocolConformance(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ProtocolConformanceImpl> element(new ProtocolConformanceImpl());
	element->setMetaElementID(metaElementID);
	element->setThisProtocolConformancePtr(element);
	return element;
}
std::shared_ptr<ProtocolConformance> UmlFactoryImpl::createProtocolConformance_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ProtocolConformanceImpl> element(new ProtocolConformanceImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisProtocolConformancePtr(element);
	return element;
	
}
std::shared_ptr<ProtocolConformance> UmlFactoryImpl::createProtocolConformance_in_SpecificMachine(std::weak_ptr<uml::ProtocolStateMachine > par_specificMachine, const int metaElementID) const
{
	std::shared_ptr<ProtocolConformanceImpl> element(new ProtocolConformanceImpl(par_specificMachine));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_specificMachine.lock())
	{
			wp->getConformance()->push_back(element);
	}
	element->setThisProtocolConformancePtr(element);
	return element;
	
}
std::shared_ptr<ProtocolStateMachine> UmlFactoryImpl::createProtocolStateMachine(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ProtocolStateMachineImpl> element(new ProtocolStateMachineImpl());
	element->setMetaElementID(metaElementID);
	element->setThisProtocolStateMachinePtr(element);
	return element;
}
std::shared_ptr<ProtocolStateMachine> UmlFactoryImpl::createProtocolStateMachine_in_BehavioredClassifier(std::weak_ptr<uml::BehavioredClassifier > par_behavioredClassifier, const int metaElementID) const
{
	std::shared_ptr<ProtocolStateMachineImpl> element(new ProtocolStateMachineImpl(par_behavioredClassifier));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_behavioredClassifier.lock())
	{
			wp->getOwnedBehavior()->push_back(element);
	}
	element->setThisProtocolStateMachinePtr(element);
	return element;
	
}
std::shared_ptr<ProtocolStateMachine> UmlFactoryImpl::createProtocolStateMachine_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ProtocolStateMachineImpl> element(new ProtocolStateMachineImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisProtocolStateMachinePtr(element);
	return element;
	
}
std::shared_ptr<ProtocolStateMachine> UmlFactoryImpl::createProtocolStateMachine_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ProtocolStateMachineImpl> element(new ProtocolStateMachineImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisProtocolStateMachinePtr(element);
	return element;
	
}
std::shared_ptr<ProtocolStateMachine> UmlFactoryImpl::createProtocolStateMachine_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<ProtocolStateMachineImpl> element(new ProtocolStateMachineImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisProtocolStateMachinePtr(element);
	return element;
	
}
std::shared_ptr<ProtocolStateMachine> UmlFactoryImpl::createProtocolStateMachine_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<ProtocolStateMachineImpl> element(new ProtocolStateMachineImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisProtocolStateMachinePtr(element);
	return element;
	
}
std::shared_ptr<ProtocolStateMachine> UmlFactoryImpl::createProtocolStateMachine_in_Package(std::weak_ptr<uml::Package > par_package, const int metaElementID) const
{
	std::shared_ptr<ProtocolStateMachineImpl> element(new ProtocolStateMachineImpl(par_package, UmlPackage::TYPE_ATTRIBUTE_PACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_package.lock())
	{
			wp->getOwnedType()->push_back(element);
	}
	element->setThisProtocolStateMachinePtr(element);
	return element;
	
}
std::shared_ptr<ProtocolTransition> UmlFactoryImpl::createProtocolTransition(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ProtocolTransitionImpl> element(new ProtocolTransitionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisProtocolTransitionPtr(element);
	return element;
}
std::shared_ptr<ProtocolTransition> UmlFactoryImpl::createProtocolTransition_in_Container(std::weak_ptr<uml::Region > par_container, const int metaElementID) const
{
	std::shared_ptr<ProtocolTransitionImpl> element(new ProtocolTransitionImpl(par_container));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_container.lock())
	{
			wp->getTransition()->push_back(element);
	}
	element->setThisProtocolTransitionPtr(element);
	return element;
	
}
std::shared_ptr<ProtocolTransition> UmlFactoryImpl::createProtocolTransition_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ProtocolTransitionImpl> element(new ProtocolTransitionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisProtocolTransitionPtr(element);
	return element;
	
}
std::shared_ptr<ProtocolTransition> UmlFactoryImpl::createProtocolTransition_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ProtocolTransitionImpl> element(new ProtocolTransitionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisProtocolTransitionPtr(element);
	return element;
	
}
std::shared_ptr<Pseudostate> UmlFactoryImpl::createPseudostate(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<PseudostateImpl> element(new PseudostateImpl());
	element->setMetaElementID(metaElementID);
	element->setThisPseudostatePtr(element);
	return element;
}
std::shared_ptr<Pseudostate> UmlFactoryImpl::createPseudostate_in_Container(std::weak_ptr<uml::Region > par_container, const int metaElementID) const
{
	std::shared_ptr<PseudostateImpl> element(new PseudostateImpl(par_container));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_container.lock())
	{
			wp->getSubvertex()->push_back(element);
	}
	element->setThisPseudostatePtr(element);
	return element;
	
}
std::shared_ptr<Pseudostate> UmlFactoryImpl::createPseudostate_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<PseudostateImpl> element(new PseudostateImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisPseudostatePtr(element);
	return element;
	
}
std::shared_ptr<Pseudostate> UmlFactoryImpl::createPseudostate_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<PseudostateImpl> element(new PseudostateImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisPseudostatePtr(element);
	return element;
	
}
std::shared_ptr<Pseudostate> UmlFactoryImpl::createPseudostate_in_State(std::weak_ptr<uml::State > par_state, const int metaElementID) const
{
	std::shared_ptr<PseudostateImpl> element(new PseudostateImpl(par_state));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_state.lock())
	{
			wp->getConnectionPoint()->push_back(element);
	}
	element->setThisPseudostatePtr(element);
	return element;
	
}
std::shared_ptr<Pseudostate> UmlFactoryImpl::createPseudostate_in_StateMachine(std::weak_ptr<uml::StateMachine > par_stateMachine, const int metaElementID) const
{
	std::shared_ptr<PseudostateImpl> element(new PseudostateImpl(par_stateMachine));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_stateMachine.lock())
	{
			wp->getConnectionPoint()->push_back(element);
	}
	element->setThisPseudostatePtr(element);
	return element;
	
}
std::shared_ptr<QualifierValue> UmlFactoryImpl::createQualifierValue(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<QualifierValueImpl> element(new QualifierValueImpl());
	element->setMetaElementID(metaElementID);
	element->setThisQualifierValuePtr(element);
	return element;
}
std::shared_ptr<QualifierValue> UmlFactoryImpl::createQualifierValue_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<QualifierValueImpl> element(new QualifierValueImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisQualifierValuePtr(element);
	return element;
	
}
std::shared_ptr<RaiseExceptionAction> UmlFactoryImpl::createRaiseExceptionAction(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<RaiseExceptionActionImpl> element(new RaiseExceptionActionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisRaiseExceptionActionPtr(element);
	return element;
}
std::shared_ptr<RaiseExceptionAction> UmlFactoryImpl::createRaiseExceptionAction_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<RaiseExceptionActionImpl> element(new RaiseExceptionActionImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisRaiseExceptionActionPtr(element);
	return element;
	
}
std::shared_ptr<RaiseExceptionAction> UmlFactoryImpl::createRaiseExceptionAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<RaiseExceptionActionImpl> element(new RaiseExceptionActionImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisRaiseExceptionActionPtr(element);
	return element;
	
}
std::shared_ptr<RaiseExceptionAction> UmlFactoryImpl::createRaiseExceptionAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<RaiseExceptionActionImpl> element(new RaiseExceptionActionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisRaiseExceptionActionPtr(element);
	return element;
	
}
std::shared_ptr<RaiseExceptionAction> UmlFactoryImpl::createRaiseExceptionAction_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<RaiseExceptionActionImpl> element(new RaiseExceptionActionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisRaiseExceptionActionPtr(element);
	return element;
	
}
std::shared_ptr<ReadExtentAction> UmlFactoryImpl::createReadExtentAction(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ReadExtentActionImpl> element(new ReadExtentActionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisReadExtentActionPtr(element);
	return element;
}
std::shared_ptr<ReadExtentAction> UmlFactoryImpl::createReadExtentAction_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<ReadExtentActionImpl> element(new ReadExtentActionImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisReadExtentActionPtr(element);
	return element;
	
}
std::shared_ptr<ReadExtentAction> UmlFactoryImpl::createReadExtentAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<ReadExtentActionImpl> element(new ReadExtentActionImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisReadExtentActionPtr(element);
	return element;
	
}
std::shared_ptr<ReadExtentAction> UmlFactoryImpl::createReadExtentAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ReadExtentActionImpl> element(new ReadExtentActionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisReadExtentActionPtr(element);
	return element;
	
}
std::shared_ptr<ReadExtentAction> UmlFactoryImpl::createReadExtentAction_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ReadExtentActionImpl> element(new ReadExtentActionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisReadExtentActionPtr(element);
	return element;
	
}
std::shared_ptr<ReadIsClassifiedObjectAction> UmlFactoryImpl::createReadIsClassifiedObjectAction(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ReadIsClassifiedObjectActionImpl> element(new ReadIsClassifiedObjectActionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisReadIsClassifiedObjectActionPtr(element);
	return element;
}
std::shared_ptr<ReadIsClassifiedObjectAction> UmlFactoryImpl::createReadIsClassifiedObjectAction_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<ReadIsClassifiedObjectActionImpl> element(new ReadIsClassifiedObjectActionImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisReadIsClassifiedObjectActionPtr(element);
	return element;
	
}
std::shared_ptr<ReadIsClassifiedObjectAction> UmlFactoryImpl::createReadIsClassifiedObjectAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<ReadIsClassifiedObjectActionImpl> element(new ReadIsClassifiedObjectActionImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisReadIsClassifiedObjectActionPtr(element);
	return element;
	
}
std::shared_ptr<ReadIsClassifiedObjectAction> UmlFactoryImpl::createReadIsClassifiedObjectAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ReadIsClassifiedObjectActionImpl> element(new ReadIsClassifiedObjectActionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisReadIsClassifiedObjectActionPtr(element);
	return element;
	
}
std::shared_ptr<ReadIsClassifiedObjectAction> UmlFactoryImpl::createReadIsClassifiedObjectAction_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ReadIsClassifiedObjectActionImpl> element(new ReadIsClassifiedObjectActionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisReadIsClassifiedObjectActionPtr(element);
	return element;
	
}
std::shared_ptr<ReadLinkAction> UmlFactoryImpl::createReadLinkAction(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ReadLinkActionImpl> element(new ReadLinkActionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisReadLinkActionPtr(element);
	return element;
}
std::shared_ptr<ReadLinkAction> UmlFactoryImpl::createReadLinkAction_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<ReadLinkActionImpl> element(new ReadLinkActionImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisReadLinkActionPtr(element);
	return element;
	
}
std::shared_ptr<ReadLinkAction> UmlFactoryImpl::createReadLinkAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<ReadLinkActionImpl> element(new ReadLinkActionImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisReadLinkActionPtr(element);
	return element;
	
}
std::shared_ptr<ReadLinkAction> UmlFactoryImpl::createReadLinkAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ReadLinkActionImpl> element(new ReadLinkActionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisReadLinkActionPtr(element);
	return element;
	
}
std::shared_ptr<ReadLinkAction> UmlFactoryImpl::createReadLinkAction_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ReadLinkActionImpl> element(new ReadLinkActionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisReadLinkActionPtr(element);
	return element;
	
}
std::shared_ptr<ReadLinkObjectEndAction> UmlFactoryImpl::createReadLinkObjectEndAction(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ReadLinkObjectEndActionImpl> element(new ReadLinkObjectEndActionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisReadLinkObjectEndActionPtr(element);
	return element;
}
std::shared_ptr<ReadLinkObjectEndAction> UmlFactoryImpl::createReadLinkObjectEndAction_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<ReadLinkObjectEndActionImpl> element(new ReadLinkObjectEndActionImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisReadLinkObjectEndActionPtr(element);
	return element;
	
}
std::shared_ptr<ReadLinkObjectEndAction> UmlFactoryImpl::createReadLinkObjectEndAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<ReadLinkObjectEndActionImpl> element(new ReadLinkObjectEndActionImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisReadLinkObjectEndActionPtr(element);
	return element;
	
}
std::shared_ptr<ReadLinkObjectEndAction> UmlFactoryImpl::createReadLinkObjectEndAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ReadLinkObjectEndActionImpl> element(new ReadLinkObjectEndActionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisReadLinkObjectEndActionPtr(element);
	return element;
	
}
std::shared_ptr<ReadLinkObjectEndAction> UmlFactoryImpl::createReadLinkObjectEndAction_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ReadLinkObjectEndActionImpl> element(new ReadLinkObjectEndActionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisReadLinkObjectEndActionPtr(element);
	return element;
	
}
std::shared_ptr<ReadLinkObjectEndQualifierAction> UmlFactoryImpl::createReadLinkObjectEndQualifierAction(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ReadLinkObjectEndQualifierActionImpl> element(new ReadLinkObjectEndQualifierActionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisReadLinkObjectEndQualifierActionPtr(element);
	return element;
}
std::shared_ptr<ReadLinkObjectEndQualifierAction> UmlFactoryImpl::createReadLinkObjectEndQualifierAction_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<ReadLinkObjectEndQualifierActionImpl> element(new ReadLinkObjectEndQualifierActionImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisReadLinkObjectEndQualifierActionPtr(element);
	return element;
	
}
std::shared_ptr<ReadLinkObjectEndQualifierAction> UmlFactoryImpl::createReadLinkObjectEndQualifierAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<ReadLinkObjectEndQualifierActionImpl> element(new ReadLinkObjectEndQualifierActionImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisReadLinkObjectEndQualifierActionPtr(element);
	return element;
	
}
std::shared_ptr<ReadLinkObjectEndQualifierAction> UmlFactoryImpl::createReadLinkObjectEndQualifierAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ReadLinkObjectEndQualifierActionImpl> element(new ReadLinkObjectEndQualifierActionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisReadLinkObjectEndQualifierActionPtr(element);
	return element;
	
}
std::shared_ptr<ReadLinkObjectEndQualifierAction> UmlFactoryImpl::createReadLinkObjectEndQualifierAction_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ReadLinkObjectEndQualifierActionImpl> element(new ReadLinkObjectEndQualifierActionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisReadLinkObjectEndQualifierActionPtr(element);
	return element;
	
}
std::shared_ptr<ReadSelfAction> UmlFactoryImpl::createReadSelfAction(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ReadSelfActionImpl> element(new ReadSelfActionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisReadSelfActionPtr(element);
	return element;
}
std::shared_ptr<ReadSelfAction> UmlFactoryImpl::createReadSelfAction_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<ReadSelfActionImpl> element(new ReadSelfActionImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisReadSelfActionPtr(element);
	return element;
	
}
std::shared_ptr<ReadSelfAction> UmlFactoryImpl::createReadSelfAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<ReadSelfActionImpl> element(new ReadSelfActionImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisReadSelfActionPtr(element);
	return element;
	
}
std::shared_ptr<ReadSelfAction> UmlFactoryImpl::createReadSelfAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ReadSelfActionImpl> element(new ReadSelfActionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisReadSelfActionPtr(element);
	return element;
	
}
std::shared_ptr<ReadSelfAction> UmlFactoryImpl::createReadSelfAction_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ReadSelfActionImpl> element(new ReadSelfActionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisReadSelfActionPtr(element);
	return element;
	
}
std::shared_ptr<ReadStructuralFeatureAction> UmlFactoryImpl::createReadStructuralFeatureAction(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ReadStructuralFeatureActionImpl> element(new ReadStructuralFeatureActionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisReadStructuralFeatureActionPtr(element);
	return element;
}
std::shared_ptr<ReadStructuralFeatureAction> UmlFactoryImpl::createReadStructuralFeatureAction_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<ReadStructuralFeatureActionImpl> element(new ReadStructuralFeatureActionImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisReadStructuralFeatureActionPtr(element);
	return element;
	
}
std::shared_ptr<ReadStructuralFeatureAction> UmlFactoryImpl::createReadStructuralFeatureAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<ReadStructuralFeatureActionImpl> element(new ReadStructuralFeatureActionImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisReadStructuralFeatureActionPtr(element);
	return element;
	
}
std::shared_ptr<ReadStructuralFeatureAction> UmlFactoryImpl::createReadStructuralFeatureAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ReadStructuralFeatureActionImpl> element(new ReadStructuralFeatureActionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisReadStructuralFeatureActionPtr(element);
	return element;
	
}
std::shared_ptr<ReadStructuralFeatureAction> UmlFactoryImpl::createReadStructuralFeatureAction_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ReadStructuralFeatureActionImpl> element(new ReadStructuralFeatureActionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisReadStructuralFeatureActionPtr(element);
	return element;
	
}
std::shared_ptr<ReadVariableAction> UmlFactoryImpl::createReadVariableAction(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ReadVariableActionImpl> element(new ReadVariableActionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisReadVariableActionPtr(element);
	return element;
}
std::shared_ptr<ReadVariableAction> UmlFactoryImpl::createReadVariableAction_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<ReadVariableActionImpl> element(new ReadVariableActionImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisReadVariableActionPtr(element);
	return element;
	
}
std::shared_ptr<ReadVariableAction> UmlFactoryImpl::createReadVariableAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<ReadVariableActionImpl> element(new ReadVariableActionImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisReadVariableActionPtr(element);
	return element;
	
}
std::shared_ptr<ReadVariableAction> UmlFactoryImpl::createReadVariableAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ReadVariableActionImpl> element(new ReadVariableActionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisReadVariableActionPtr(element);
	return element;
	
}
std::shared_ptr<ReadVariableAction> UmlFactoryImpl::createReadVariableAction_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ReadVariableActionImpl> element(new ReadVariableActionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisReadVariableActionPtr(element);
	return element;
	
}
std::shared_ptr<Realization> UmlFactoryImpl::createRealization(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<RealizationImpl> element(new RealizationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisRealizationPtr(element);
	return element;
}
std::shared_ptr<Realization> UmlFactoryImpl::createRealization_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<RealizationImpl> element(new RealizationImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisRealizationPtr(element);
	return element;
	
}
std::shared_ptr<Realization> UmlFactoryImpl::createRealization_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<RealizationImpl> element(new RealizationImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisRealizationPtr(element);
	return element;
	
}
std::shared_ptr<Realization> UmlFactoryImpl::createRealization_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<RealizationImpl> element(new RealizationImpl(par_owningPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisRealizationPtr(element);
	return element;
	
}
std::shared_ptr<Realization> UmlFactoryImpl::createRealization_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<RealizationImpl> element(new RealizationImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisRealizationPtr(element);
	return element;
	
}
std::shared_ptr<Reception> UmlFactoryImpl::createReception(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ReceptionImpl> element(new ReceptionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisReceptionPtr(element);
	return element;
}
std::shared_ptr<Reception> UmlFactoryImpl::createReception_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ReceptionImpl> element(new ReceptionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisReceptionPtr(element);
	return element;
	
}
std::shared_ptr<Reception> UmlFactoryImpl::createReception_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ReceptionImpl> element(new ReceptionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisReceptionPtr(element);
	return element;
	
}
std::shared_ptr<ReclassifyObjectAction> UmlFactoryImpl::createReclassifyObjectAction(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ReclassifyObjectActionImpl> element(new ReclassifyObjectActionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisReclassifyObjectActionPtr(element);
	return element;
}
std::shared_ptr<ReclassifyObjectAction> UmlFactoryImpl::createReclassifyObjectAction_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<ReclassifyObjectActionImpl> element(new ReclassifyObjectActionImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisReclassifyObjectActionPtr(element);
	return element;
	
}
std::shared_ptr<ReclassifyObjectAction> UmlFactoryImpl::createReclassifyObjectAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<ReclassifyObjectActionImpl> element(new ReclassifyObjectActionImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisReclassifyObjectActionPtr(element);
	return element;
	
}
std::shared_ptr<ReclassifyObjectAction> UmlFactoryImpl::createReclassifyObjectAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ReclassifyObjectActionImpl> element(new ReclassifyObjectActionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisReclassifyObjectActionPtr(element);
	return element;
	
}
std::shared_ptr<ReclassifyObjectAction> UmlFactoryImpl::createReclassifyObjectAction_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ReclassifyObjectActionImpl> element(new ReclassifyObjectActionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisReclassifyObjectActionPtr(element);
	return element;
	
}
std::shared_ptr<RedefinableTemplateSignature> UmlFactoryImpl::createRedefinableTemplateSignature(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<RedefinableTemplateSignatureImpl> element(new RedefinableTemplateSignatureImpl());
	element->setMetaElementID(metaElementID);
	element->setThisRedefinableTemplateSignaturePtr(element);
	return element;
}
std::shared_ptr<RedefinableTemplateSignature> UmlFactoryImpl::createRedefinableTemplateSignature_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<RedefinableTemplateSignatureImpl> element(new RedefinableTemplateSignatureImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisRedefinableTemplateSignaturePtr(element);
	return element;
	
}
std::shared_ptr<RedefinableTemplateSignature> UmlFactoryImpl::createRedefinableTemplateSignature_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<RedefinableTemplateSignatureImpl> element(new RedefinableTemplateSignatureImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisRedefinableTemplateSignaturePtr(element);
	return element;
	
}
std::shared_ptr<RedefinableTemplateSignature> UmlFactoryImpl::createRedefinableTemplateSignature_in_Template(std::weak_ptr<uml::TemplateableElement > par_template, const int metaElementID) const
{
	std::shared_ptr<RedefinableTemplateSignatureImpl> element(new RedefinableTemplateSignatureImpl(par_template));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_template.lock())
	{
			wp->setOwnedTemplateSignature(element);
	}
	element->setThisRedefinableTemplateSignaturePtr(element);
	return element;
	
}
std::shared_ptr<ReduceAction> UmlFactoryImpl::createReduceAction(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ReduceActionImpl> element(new ReduceActionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisReduceActionPtr(element);
	return element;
}
std::shared_ptr<ReduceAction> UmlFactoryImpl::createReduceAction_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<ReduceActionImpl> element(new ReduceActionImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisReduceActionPtr(element);
	return element;
	
}
std::shared_ptr<ReduceAction> UmlFactoryImpl::createReduceAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<ReduceActionImpl> element(new ReduceActionImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisReduceActionPtr(element);
	return element;
	
}
std::shared_ptr<ReduceAction> UmlFactoryImpl::createReduceAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ReduceActionImpl> element(new ReduceActionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisReduceActionPtr(element);
	return element;
	
}
std::shared_ptr<ReduceAction> UmlFactoryImpl::createReduceAction_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ReduceActionImpl> element(new ReduceActionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisReduceActionPtr(element);
	return element;
	
}
std::shared_ptr<Region> UmlFactoryImpl::createRegion(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<RegionImpl> element(new RegionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisRegionPtr(element);
	return element;
}
std::shared_ptr<Region> UmlFactoryImpl::createRegion_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<RegionImpl> element(new RegionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisRegionPtr(element);
	return element;
	
}
std::shared_ptr<Region> UmlFactoryImpl::createRegion_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<RegionImpl> element(new RegionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisRegionPtr(element);
	return element;
	
}
std::shared_ptr<Region> UmlFactoryImpl::createRegion_in_State(std::weak_ptr<uml::State > par_state, const int metaElementID) const
{
	std::shared_ptr<RegionImpl> element(new RegionImpl(par_state));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_state.lock())
	{
			wp->getRegion()->push_back(element);
	}
	element->setThisRegionPtr(element);
	return element;
	
}
std::shared_ptr<Region> UmlFactoryImpl::createRegion_in_StateMachine(std::weak_ptr<uml::StateMachine > par_stateMachine, const int metaElementID) const
{
	std::shared_ptr<RegionImpl> element(new RegionImpl(par_stateMachine));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_stateMachine.lock())
	{
			wp->getRegion()->push_back(element);
	}
	element->setThisRegionPtr(element);
	return element;
	
}
std::shared_ptr<RemoveStructuralFeatureValueAction> UmlFactoryImpl::createRemoveStructuralFeatureValueAction(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<RemoveStructuralFeatureValueActionImpl> element(new RemoveStructuralFeatureValueActionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisRemoveStructuralFeatureValueActionPtr(element);
	return element;
}
std::shared_ptr<RemoveStructuralFeatureValueAction> UmlFactoryImpl::createRemoveStructuralFeatureValueAction_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<RemoveStructuralFeatureValueActionImpl> element(new RemoveStructuralFeatureValueActionImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisRemoveStructuralFeatureValueActionPtr(element);
	return element;
	
}
std::shared_ptr<RemoveStructuralFeatureValueAction> UmlFactoryImpl::createRemoveStructuralFeatureValueAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<RemoveStructuralFeatureValueActionImpl> element(new RemoveStructuralFeatureValueActionImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisRemoveStructuralFeatureValueActionPtr(element);
	return element;
	
}
std::shared_ptr<RemoveStructuralFeatureValueAction> UmlFactoryImpl::createRemoveStructuralFeatureValueAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<RemoveStructuralFeatureValueActionImpl> element(new RemoveStructuralFeatureValueActionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisRemoveStructuralFeatureValueActionPtr(element);
	return element;
	
}
std::shared_ptr<RemoveStructuralFeatureValueAction> UmlFactoryImpl::createRemoveStructuralFeatureValueAction_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<RemoveStructuralFeatureValueActionImpl> element(new RemoveStructuralFeatureValueActionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisRemoveStructuralFeatureValueActionPtr(element);
	return element;
	
}
std::shared_ptr<RemoveVariableValueAction> UmlFactoryImpl::createRemoveVariableValueAction(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<RemoveVariableValueActionImpl> element(new RemoveVariableValueActionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisRemoveVariableValueActionPtr(element);
	return element;
}
std::shared_ptr<RemoveVariableValueAction> UmlFactoryImpl::createRemoveVariableValueAction_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<RemoveVariableValueActionImpl> element(new RemoveVariableValueActionImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisRemoveVariableValueActionPtr(element);
	return element;
	
}
std::shared_ptr<RemoveVariableValueAction> UmlFactoryImpl::createRemoveVariableValueAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<RemoveVariableValueActionImpl> element(new RemoveVariableValueActionImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisRemoveVariableValueActionPtr(element);
	return element;
	
}
std::shared_ptr<RemoveVariableValueAction> UmlFactoryImpl::createRemoveVariableValueAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<RemoveVariableValueActionImpl> element(new RemoveVariableValueActionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisRemoveVariableValueActionPtr(element);
	return element;
	
}
std::shared_ptr<RemoveVariableValueAction> UmlFactoryImpl::createRemoveVariableValueAction_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<RemoveVariableValueActionImpl> element(new RemoveVariableValueActionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisRemoveVariableValueActionPtr(element);
	return element;
	
}
std::shared_ptr<ReplyAction> UmlFactoryImpl::createReplyAction(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ReplyActionImpl> element(new ReplyActionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisReplyActionPtr(element);
	return element;
}
std::shared_ptr<ReplyAction> UmlFactoryImpl::createReplyAction_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<ReplyActionImpl> element(new ReplyActionImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisReplyActionPtr(element);
	return element;
	
}
std::shared_ptr<ReplyAction> UmlFactoryImpl::createReplyAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<ReplyActionImpl> element(new ReplyActionImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisReplyActionPtr(element);
	return element;
	
}
std::shared_ptr<ReplyAction> UmlFactoryImpl::createReplyAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ReplyActionImpl> element(new ReplyActionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisReplyActionPtr(element);
	return element;
	
}
std::shared_ptr<ReplyAction> UmlFactoryImpl::createReplyAction_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ReplyActionImpl> element(new ReplyActionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisReplyActionPtr(element);
	return element;
	
}
std::shared_ptr<SendObjectAction> UmlFactoryImpl::createSendObjectAction(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<SendObjectActionImpl> element(new SendObjectActionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisSendObjectActionPtr(element);
	return element;
}
std::shared_ptr<SendObjectAction> UmlFactoryImpl::createSendObjectAction_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<SendObjectActionImpl> element(new SendObjectActionImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisSendObjectActionPtr(element);
	return element;
	
}
std::shared_ptr<SendObjectAction> UmlFactoryImpl::createSendObjectAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<SendObjectActionImpl> element(new SendObjectActionImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisSendObjectActionPtr(element);
	return element;
	
}
std::shared_ptr<SendObjectAction> UmlFactoryImpl::createSendObjectAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<SendObjectActionImpl> element(new SendObjectActionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisSendObjectActionPtr(element);
	return element;
	
}
std::shared_ptr<SendObjectAction> UmlFactoryImpl::createSendObjectAction_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<SendObjectActionImpl> element(new SendObjectActionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisSendObjectActionPtr(element);
	return element;
	
}
std::shared_ptr<SendSignalAction> UmlFactoryImpl::createSendSignalAction(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<SendSignalActionImpl> element(new SendSignalActionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisSendSignalActionPtr(element);
	return element;
}
std::shared_ptr<SendSignalAction> UmlFactoryImpl::createSendSignalAction_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<SendSignalActionImpl> element(new SendSignalActionImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisSendSignalActionPtr(element);
	return element;
	
}
std::shared_ptr<SendSignalAction> UmlFactoryImpl::createSendSignalAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<SendSignalActionImpl> element(new SendSignalActionImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisSendSignalActionPtr(element);
	return element;
	
}
std::shared_ptr<SendSignalAction> UmlFactoryImpl::createSendSignalAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<SendSignalActionImpl> element(new SendSignalActionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisSendSignalActionPtr(element);
	return element;
	
}
std::shared_ptr<SendSignalAction> UmlFactoryImpl::createSendSignalAction_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<SendSignalActionImpl> element(new SendSignalActionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisSendSignalActionPtr(element);
	return element;
	
}
std::shared_ptr<SequenceNode> UmlFactoryImpl::createSequenceNode(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<SequenceNodeImpl> element(new SequenceNodeImpl());
	element->setMetaElementID(metaElementID);
	element->setThisSequenceNodePtr(element);
	return element;
}
std::shared_ptr<SequenceNode> UmlFactoryImpl::createSequenceNode_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<SequenceNodeImpl> element(new SequenceNodeImpl(par_activity, UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisSequenceNodePtr(element);
	return element;
	
}
std::shared_ptr<SequenceNode> UmlFactoryImpl::createSequenceNode_in_InActivity(std::weak_ptr<uml::Activity > par_inActivity, const int metaElementID) const
{
	std::shared_ptr<SequenceNodeImpl> element(new SequenceNodeImpl(par_inActivity, UmlPackage::ACTIVITYGROUP_ATTRIBUTE_INACTIVITY));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inActivity.lock())
	{
			wp->getGroup()->push_back(element);
	}
	element->setThisSequenceNodePtr(element);
	return element;
	
}
std::shared_ptr<SequenceNode> UmlFactoryImpl::createSequenceNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<SequenceNodeImpl> element(new SequenceNodeImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisSequenceNodePtr(element);
	return element;
	
}
std::shared_ptr<SequenceNode> UmlFactoryImpl::createSequenceNode_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<SequenceNodeImpl> element(new SequenceNodeImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisSequenceNodePtr(element);
	return element;
	
}
std::shared_ptr<SequenceNode> UmlFactoryImpl::createSequenceNode_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<SequenceNodeImpl> element(new SequenceNodeImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisSequenceNodePtr(element);
	return element;
	
}
std::shared_ptr<SequenceNode> UmlFactoryImpl::createSequenceNode_in_SuperGroup(std::weak_ptr<uml::ActivityGroup > par_superGroup, const int metaElementID) const
{
	std::shared_ptr<SequenceNodeImpl> element(new SequenceNodeImpl(par_superGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_superGroup.lock())
	{
			wp->getSubgroup()->push_back(element);
	}
	element->setThisSequenceNodePtr(element);
	return element;
	
}
std::shared_ptr<Signal> UmlFactoryImpl::createSignal(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<SignalImpl> element(new SignalImpl());
	element->setMetaElementID(metaElementID);
	element->setThisSignalPtr(element);
	return element;
}
std::shared_ptr<Signal> UmlFactoryImpl::createSignal_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<SignalImpl> element(new SignalImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisSignalPtr(element);
	return element;
	
}
std::shared_ptr<Signal> UmlFactoryImpl::createSignal_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<SignalImpl> element(new SignalImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisSignalPtr(element);
	return element;
	
}
std::shared_ptr<Signal> UmlFactoryImpl::createSignal_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<SignalImpl> element(new SignalImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisSignalPtr(element);
	return element;
	
}
std::shared_ptr<Signal> UmlFactoryImpl::createSignal_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<SignalImpl> element(new SignalImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisSignalPtr(element);
	return element;
	
}
std::shared_ptr<Signal> UmlFactoryImpl::createSignal_in_Package(std::weak_ptr<uml::Package > par_package, const int metaElementID) const
{
	std::shared_ptr<SignalImpl> element(new SignalImpl(par_package, UmlPackage::TYPE_ATTRIBUTE_PACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_package.lock())
	{
			wp->getOwnedType()->push_back(element);
	}
	element->setThisSignalPtr(element);
	return element;
	
}
std::shared_ptr<SignalEvent> UmlFactoryImpl::createSignalEvent(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<SignalEventImpl> element(new SignalEventImpl());
	element->setMetaElementID(metaElementID);
	element->setThisSignalEventPtr(element);
	return element;
}
std::shared_ptr<SignalEvent> UmlFactoryImpl::createSignalEvent_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<SignalEventImpl> element(new SignalEventImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisSignalEventPtr(element);
	return element;
	
}
std::shared_ptr<SignalEvent> UmlFactoryImpl::createSignalEvent_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<SignalEventImpl> element(new SignalEventImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisSignalEventPtr(element);
	return element;
	
}
std::shared_ptr<SignalEvent> UmlFactoryImpl::createSignalEvent_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<SignalEventImpl> element(new SignalEventImpl(par_owningPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisSignalEventPtr(element);
	return element;
	
}
std::shared_ptr<SignalEvent> UmlFactoryImpl::createSignalEvent_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<SignalEventImpl> element(new SignalEventImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisSignalEventPtr(element);
	return element;
	
}
std::shared_ptr<Slot> UmlFactoryImpl::createSlot(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<SlotImpl> element(new SlotImpl());
	element->setMetaElementID(metaElementID);
	element->setThisSlotPtr(element);
	return element;
}
std::shared_ptr<Slot> UmlFactoryImpl::createSlot_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<SlotImpl> element(new SlotImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisSlotPtr(element);
	return element;
	
}
std::shared_ptr<Slot> UmlFactoryImpl::createSlot_in_OwningInstance(std::weak_ptr<uml::InstanceSpecification > par_owningInstance, const int metaElementID) const
{
	std::shared_ptr<SlotImpl> element(new SlotImpl(par_owningInstance));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningInstance.lock())
	{
			wp->getSlot()->push_back(element);
	}
	element->setThisSlotPtr(element);
	return element;
	
}
std::shared_ptr<StartClassifierBehaviorAction> UmlFactoryImpl::createStartClassifierBehaviorAction(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StartClassifierBehaviorActionImpl> element(new StartClassifierBehaviorActionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisStartClassifierBehaviorActionPtr(element);
	return element;
}
std::shared_ptr<StartClassifierBehaviorAction> UmlFactoryImpl::createStartClassifierBehaviorAction_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<StartClassifierBehaviorActionImpl> element(new StartClassifierBehaviorActionImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisStartClassifierBehaviorActionPtr(element);
	return element;
	
}
std::shared_ptr<StartClassifierBehaviorAction> UmlFactoryImpl::createStartClassifierBehaviorAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<StartClassifierBehaviorActionImpl> element(new StartClassifierBehaviorActionImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisStartClassifierBehaviorActionPtr(element);
	return element;
	
}
std::shared_ptr<StartClassifierBehaviorAction> UmlFactoryImpl::createStartClassifierBehaviorAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<StartClassifierBehaviorActionImpl> element(new StartClassifierBehaviorActionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisStartClassifierBehaviorActionPtr(element);
	return element;
	
}
std::shared_ptr<StartClassifierBehaviorAction> UmlFactoryImpl::createStartClassifierBehaviorAction_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<StartClassifierBehaviorActionImpl> element(new StartClassifierBehaviorActionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisStartClassifierBehaviorActionPtr(element);
	return element;
	
}
std::shared_ptr<StartObjectBehaviorAction> UmlFactoryImpl::createStartObjectBehaviorAction(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StartObjectBehaviorActionImpl> element(new StartObjectBehaviorActionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisStartObjectBehaviorActionPtr(element);
	return element;
}
std::shared_ptr<StartObjectBehaviorAction> UmlFactoryImpl::createStartObjectBehaviorAction_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<StartObjectBehaviorActionImpl> element(new StartObjectBehaviorActionImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisStartObjectBehaviorActionPtr(element);
	return element;
	
}
std::shared_ptr<StartObjectBehaviorAction> UmlFactoryImpl::createStartObjectBehaviorAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<StartObjectBehaviorActionImpl> element(new StartObjectBehaviorActionImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisStartObjectBehaviorActionPtr(element);
	return element;
	
}
std::shared_ptr<StartObjectBehaviorAction> UmlFactoryImpl::createStartObjectBehaviorAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<StartObjectBehaviorActionImpl> element(new StartObjectBehaviorActionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisStartObjectBehaviorActionPtr(element);
	return element;
	
}
std::shared_ptr<StartObjectBehaviorAction> UmlFactoryImpl::createStartObjectBehaviorAction_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<StartObjectBehaviorActionImpl> element(new StartObjectBehaviorActionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisStartObjectBehaviorActionPtr(element);
	return element;
	
}
std::shared_ptr<State> UmlFactoryImpl::createState(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StateImpl> element(new StateImpl());
	element->setMetaElementID(metaElementID);
	element->setThisStatePtr(element);
	return element;
}
std::shared_ptr<State> UmlFactoryImpl::createState_in_Container(std::weak_ptr<uml::Region > par_container, const int metaElementID) const
{
	std::shared_ptr<StateImpl> element(new StateImpl(par_container));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_container.lock())
	{
			wp->getSubvertex()->push_back(element);
	}
	element->setThisStatePtr(element);
	return element;
	
}
std::shared_ptr<State> UmlFactoryImpl::createState_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<StateImpl> element(new StateImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisStatePtr(element);
	return element;
	
}
std::shared_ptr<State> UmlFactoryImpl::createState_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<StateImpl> element(new StateImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisStatePtr(element);
	return element;
	
}
std::shared_ptr<StateInvariant> UmlFactoryImpl::createStateInvariant(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StateInvariantImpl> element(new StateInvariantImpl());
	element->setMetaElementID(metaElementID);
	element->setThisStateInvariantPtr(element);
	return element;
}
std::shared_ptr<StateInvariant> UmlFactoryImpl::createStateInvariant_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction, const int metaElementID) const
{
	std::shared_ptr<StateInvariantImpl> element(new StateInvariantImpl(par_enclosingInteraction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_enclosingInteraction.lock())
	{
			wp->getFragment()->push_back(element);
	}
	element->setThisStateInvariantPtr(element);
	return element;
	
}
std::shared_ptr<StateInvariant> UmlFactoryImpl::createStateInvariant_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand, const int metaElementID) const
{
	std::shared_ptr<StateInvariantImpl> element(new StateInvariantImpl(par_enclosingOperand));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_enclosingOperand.lock())
	{
			wp->getFragment()->push_back(element);
	}
	element->setThisStateInvariantPtr(element);
	return element;
	
}
std::shared_ptr<StateInvariant> UmlFactoryImpl::createStateInvariant_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<StateInvariantImpl> element(new StateInvariantImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisStateInvariantPtr(element);
	return element;
	
}
std::shared_ptr<StateInvariant> UmlFactoryImpl::createStateInvariant_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<StateInvariantImpl> element(new StateInvariantImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisStateInvariantPtr(element);
	return element;
	
}
std::shared_ptr<StateMachine> UmlFactoryImpl::createStateMachine(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StateMachineImpl> element(new StateMachineImpl());
	element->setMetaElementID(metaElementID);
	element->setThisStateMachinePtr(element);
	return element;
}
std::shared_ptr<StateMachine> UmlFactoryImpl::createStateMachine_in_BehavioredClassifier(std::weak_ptr<uml::BehavioredClassifier > par_behavioredClassifier, const int metaElementID) const
{
	std::shared_ptr<StateMachineImpl> element(new StateMachineImpl(par_behavioredClassifier));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_behavioredClassifier.lock())
	{
			wp->getOwnedBehavior()->push_back(element);
	}
	element->setThisStateMachinePtr(element);
	return element;
	
}
std::shared_ptr<StateMachine> UmlFactoryImpl::createStateMachine_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<StateMachineImpl> element(new StateMachineImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisStateMachinePtr(element);
	return element;
	
}
std::shared_ptr<StateMachine> UmlFactoryImpl::createStateMachine_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<StateMachineImpl> element(new StateMachineImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisStateMachinePtr(element);
	return element;
	
}
std::shared_ptr<StateMachine> UmlFactoryImpl::createStateMachine_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<StateMachineImpl> element(new StateMachineImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisStateMachinePtr(element);
	return element;
	
}
std::shared_ptr<StateMachine> UmlFactoryImpl::createStateMachine_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<StateMachineImpl> element(new StateMachineImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisStateMachinePtr(element);
	return element;
	
}
std::shared_ptr<StateMachine> UmlFactoryImpl::createStateMachine_in_Package(std::weak_ptr<uml::Package > par_package, const int metaElementID) const
{
	std::shared_ptr<StateMachineImpl> element(new StateMachineImpl(par_package, UmlPackage::TYPE_ATTRIBUTE_PACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_package.lock())
	{
			wp->getOwnedType()->push_back(element);
	}
	element->setThisStateMachinePtr(element);
	return element;
	
}
std::shared_ptr<Stereotype> UmlFactoryImpl::createStereotype(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StereotypeImpl> element(new StereotypeImpl());
	element->setMetaElementID(metaElementID);
	element->setThisStereotypePtr(element);
	return element;
}
std::shared_ptr<Stereotype> UmlFactoryImpl::createStereotype_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<StereotypeImpl> element(new StereotypeImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisStereotypePtr(element);
	return element;
	
}
std::shared_ptr<Stereotype> UmlFactoryImpl::createStereotype_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<StereotypeImpl> element(new StereotypeImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisStereotypePtr(element);
	return element;
	
}
std::shared_ptr<Stereotype> UmlFactoryImpl::createStereotype_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<StereotypeImpl> element(new StereotypeImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getOwnedStereotype()->push_back(element);
	}
	element->setThisStereotypePtr(element);
	return element;
	
}
std::shared_ptr<Stereotype> UmlFactoryImpl::createStereotype_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<StereotypeImpl> element(new StereotypeImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisStereotypePtr(element);
	return element;
	
}
std::shared_ptr<Stereotype> UmlFactoryImpl::createStereotype_in_Package(std::weak_ptr<uml::Package > par_package, const int metaElementID) const
{
	std::shared_ptr<StereotypeImpl> element(new StereotypeImpl(par_package, UmlPackage::TYPE_ATTRIBUTE_PACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_package.lock())
	{
			wp->getOwnedType()->push_back(element);
	}
	element->setThisStereotypePtr(element);
	return element;
	
}
std::shared_ptr<StringExpression> UmlFactoryImpl::createStringExpression(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StringExpressionImpl> element(new StringExpressionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisStringExpressionPtr(element);
	return element;
}
std::shared_ptr<StringExpression> UmlFactoryImpl::createStringExpression_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<StringExpressionImpl> element(new StringExpressionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisStringExpressionPtr(element);
	return element;
	
}
std::shared_ptr<StringExpression> UmlFactoryImpl::createStringExpression_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<StringExpressionImpl> element(new StringExpressionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisStringExpressionPtr(element);
	return element;
	
}
std::shared_ptr<StringExpression> UmlFactoryImpl::createStringExpression_in_OwningExpression(std::weak_ptr<uml::StringExpression > par_owningExpression, const int metaElementID) const
{
	std::shared_ptr<StringExpressionImpl> element(new StringExpressionImpl(par_owningExpression));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningExpression.lock())
	{
			wp->getSubExpression()->push_back(element);
	}
	element->setThisStringExpressionPtr(element);
	return element;
	
}
std::shared_ptr<StringExpression> UmlFactoryImpl::createStringExpression_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<StringExpressionImpl> element(new StringExpressionImpl(par_owningPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisStringExpressionPtr(element);
	return element;
	
}
std::shared_ptr<StringExpression> UmlFactoryImpl::createStringExpression_in_OwningSlot(std::weak_ptr<uml::Slot > par_owningSlot, const int metaElementID) const
{
	std::shared_ptr<StringExpressionImpl> element(new StringExpressionImpl(par_owningSlot));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningSlot.lock())
	{
			wp->getValue()->push_back(element);
	}
	element->setThisStringExpressionPtr(element);
	return element;
	
}
std::shared_ptr<StringExpression> UmlFactoryImpl::createStringExpression_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<StringExpressionImpl> element(new StringExpressionImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisStringExpressionPtr(element);
	return element;
	
}
std::shared_ptr<StringExpression> UmlFactoryImpl::createStringExpression_in_ValueSpecificationAction(std::weak_ptr<uml::ValueSpecificationAction > par_valueSpecificationAction, const int metaElementID) const
{
	std::shared_ptr<StringExpressionImpl> element(new StringExpressionImpl(par_valueSpecificationAction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_valueSpecificationAction.lock())
	{
			wp->setValue(element);
	}
	element->setThisStringExpressionPtr(element);
	return element;
	
}
std::shared_ptr<StructuredActivityNode> UmlFactoryImpl::createStructuredActivityNode(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<StructuredActivityNodeImpl> element(new StructuredActivityNodeImpl());
	element->setMetaElementID(metaElementID);
	element->setThisStructuredActivityNodePtr(element);
	return element;
}
std::shared_ptr<StructuredActivityNode> UmlFactoryImpl::createStructuredActivityNode_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<StructuredActivityNodeImpl> element(new StructuredActivityNodeImpl(par_activity, UmlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getStructuredNode()->push_back(element);
	}
	element->setThisStructuredActivityNodePtr(element);
	return element;
	
}
std::shared_ptr<StructuredActivityNode> UmlFactoryImpl::createStructuredActivityNode_in_InActivity(std::weak_ptr<uml::Activity > par_inActivity, const int metaElementID) const
{
	std::shared_ptr<StructuredActivityNodeImpl> element(new StructuredActivityNodeImpl(par_inActivity, UmlPackage::ACTIVITYGROUP_ATTRIBUTE_INACTIVITY));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inActivity.lock())
	{
			wp->getStructuredNode()->push_back(element);
	}
	element->setThisStructuredActivityNodePtr(element);
	return element;
	
}
std::shared_ptr<StructuredActivityNode> UmlFactoryImpl::createStructuredActivityNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<StructuredActivityNodeImpl> element(new StructuredActivityNodeImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisStructuredActivityNodePtr(element);
	return element;
	
}
std::shared_ptr<StructuredActivityNode> UmlFactoryImpl::createStructuredActivityNode_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<StructuredActivityNodeImpl> element(new StructuredActivityNodeImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisStructuredActivityNodePtr(element);
	return element;
	
}
std::shared_ptr<StructuredActivityNode> UmlFactoryImpl::createStructuredActivityNode_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<StructuredActivityNodeImpl> element(new StructuredActivityNodeImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisStructuredActivityNodePtr(element);
	return element;
	
}
std::shared_ptr<StructuredActivityNode> UmlFactoryImpl::createStructuredActivityNode_in_SuperGroup(std::weak_ptr<uml::ActivityGroup > par_superGroup, const int metaElementID) const
{
	std::shared_ptr<StructuredActivityNodeImpl> element(new StructuredActivityNodeImpl(par_superGroup));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_superGroup.lock())
	{
			wp->getSubgroup()->push_back(element);
	}
	element->setThisStructuredActivityNodePtr(element);
	return element;
	
}
std::shared_ptr<Substitution> UmlFactoryImpl::createSubstitution(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<SubstitutionImpl> element(new SubstitutionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisSubstitutionPtr(element);
	return element;
}
std::shared_ptr<Substitution> UmlFactoryImpl::createSubstitution_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<SubstitutionImpl> element(new SubstitutionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisSubstitutionPtr(element);
	return element;
	
}
std::shared_ptr<Substitution> UmlFactoryImpl::createSubstitution_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<SubstitutionImpl> element(new SubstitutionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisSubstitutionPtr(element);
	return element;
	
}
std::shared_ptr<Substitution> UmlFactoryImpl::createSubstitution_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<SubstitutionImpl> element(new SubstitutionImpl(par_owningPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisSubstitutionPtr(element);
	return element;
	
}
std::shared_ptr<Substitution> UmlFactoryImpl::createSubstitution_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<SubstitutionImpl> element(new SubstitutionImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisSubstitutionPtr(element);
	return element;
	
}
std::shared_ptr<Substitution> UmlFactoryImpl::createSubstitution_in_SubstitutingClassifier(std::weak_ptr<uml::Classifier > par_substitutingClassifier, const int metaElementID) const
{
	std::shared_ptr<SubstitutionImpl> element(new SubstitutionImpl(par_substitutingClassifier));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_substitutingClassifier.lock())
	{
			wp->getSubstitution()->push_back(element);
	}
	element->setThisSubstitutionPtr(element);
	return element;
	
}
std::shared_ptr<TemplateBinding> UmlFactoryImpl::createTemplateBinding(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<TemplateBindingImpl> element(new TemplateBindingImpl());
	element->setMetaElementID(metaElementID);
	element->setThisTemplateBindingPtr(element);
	return element;
}
std::shared_ptr<TemplateBinding> UmlFactoryImpl::createTemplateBinding_in_BoundElement(std::weak_ptr<uml::TemplateableElement > par_boundElement, const int metaElementID) const
{
	std::shared_ptr<TemplateBindingImpl> element(new TemplateBindingImpl(par_boundElement));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_boundElement.lock())
	{
			wp->getTemplateBinding()->push_back(element);
	}
	element->setThisTemplateBindingPtr(element);
	return element;
	
}
std::shared_ptr<TemplateBinding> UmlFactoryImpl::createTemplateBinding_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<TemplateBindingImpl> element(new TemplateBindingImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisTemplateBindingPtr(element);
	return element;
	
}
std::shared_ptr<TemplateParameter> UmlFactoryImpl::createTemplateParameter(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<TemplateParameterImpl> element(new TemplateParameterImpl());
	element->setMetaElementID(metaElementID);
	element->setThisTemplateParameterPtr(element);
	return element;
}
std::shared_ptr<TemplateParameter> UmlFactoryImpl::createTemplateParameter_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<TemplateParameterImpl> element(new TemplateParameterImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisTemplateParameterPtr(element);
	return element;
	
}
std::shared_ptr<TemplateParameter> UmlFactoryImpl::createTemplateParameter_in_Signature(std::weak_ptr<uml::TemplateSignature > par_signature, const int metaElementID) const
{
	std::shared_ptr<TemplateParameterImpl> element(new TemplateParameterImpl(par_signature));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_signature.lock())
	{
			wp->getOwnedParameter()->push_back(element);
	}
	element->setThisTemplateParameterPtr(element);
	return element;
	
}
std::shared_ptr<TemplateParameterSubstitution> UmlFactoryImpl::createTemplateParameterSubstitution(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<TemplateParameterSubstitutionImpl> element(new TemplateParameterSubstitutionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisTemplateParameterSubstitutionPtr(element);
	return element;
}
std::shared_ptr<TemplateParameterSubstitution> UmlFactoryImpl::createTemplateParameterSubstitution_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<TemplateParameterSubstitutionImpl> element(new TemplateParameterSubstitutionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisTemplateParameterSubstitutionPtr(element);
	return element;
	
}
std::shared_ptr<TemplateParameterSubstitution> UmlFactoryImpl::createTemplateParameterSubstitution_in_TemplateBinding(std::weak_ptr<uml::TemplateBinding > par_templateBinding, const int metaElementID) const
{
	std::shared_ptr<TemplateParameterSubstitutionImpl> element(new TemplateParameterSubstitutionImpl(par_templateBinding));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_templateBinding.lock())
	{
			wp->getParameterSubstitution()->push_back(element);
	}
	element->setThisTemplateParameterSubstitutionPtr(element);
	return element;
	
}
std::shared_ptr<TemplateSignature> UmlFactoryImpl::createTemplateSignature(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<TemplateSignatureImpl> element(new TemplateSignatureImpl());
	element->setMetaElementID(metaElementID);
	element->setThisTemplateSignaturePtr(element);
	return element;
}
std::shared_ptr<TemplateSignature> UmlFactoryImpl::createTemplateSignature_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<TemplateSignatureImpl> element(new TemplateSignatureImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisTemplateSignaturePtr(element);
	return element;
	
}
std::shared_ptr<TemplateSignature> UmlFactoryImpl::createTemplateSignature_in_Template(std::weak_ptr<uml::TemplateableElement > par_template, const int metaElementID) const
{
	std::shared_ptr<TemplateSignatureImpl> element(new TemplateSignatureImpl(par_template));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_template.lock())
	{
			wp->setOwnedTemplateSignature(element);
	}
	element->setThisTemplateSignaturePtr(element);
	return element;
	
}
std::shared_ptr<TestIdentityAction> UmlFactoryImpl::createTestIdentityAction(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<TestIdentityActionImpl> element(new TestIdentityActionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisTestIdentityActionPtr(element);
	return element;
}
std::shared_ptr<TestIdentityAction> UmlFactoryImpl::createTestIdentityAction_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<TestIdentityActionImpl> element(new TestIdentityActionImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisTestIdentityActionPtr(element);
	return element;
	
}
std::shared_ptr<TestIdentityAction> UmlFactoryImpl::createTestIdentityAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<TestIdentityActionImpl> element(new TestIdentityActionImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisTestIdentityActionPtr(element);
	return element;
	
}
std::shared_ptr<TestIdentityAction> UmlFactoryImpl::createTestIdentityAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<TestIdentityActionImpl> element(new TestIdentityActionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisTestIdentityActionPtr(element);
	return element;
	
}
std::shared_ptr<TestIdentityAction> UmlFactoryImpl::createTestIdentityAction_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<TestIdentityActionImpl> element(new TestIdentityActionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisTestIdentityActionPtr(element);
	return element;
	
}
std::shared_ptr<TimeConstraint> UmlFactoryImpl::createTimeConstraint(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<TimeConstraintImpl> element(new TimeConstraintImpl());
	element->setMetaElementID(metaElementID);
	element->setThisTimeConstraintPtr(element);
	return element;
}
std::shared_ptr<TimeConstraint> UmlFactoryImpl::createTimeConstraint_in_Context(std::weak_ptr<uml::Namespace > par_context, const int metaElementID) const
{
	std::shared_ptr<TimeConstraintImpl> element(new TimeConstraintImpl(par_context, UmlPackage::CONSTRAINT_ATTRIBUTE_CONTEXT));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_context.lock())
	{
			wp->getOwnedRule()->push_back(element);
	}
	element->setThisTimeConstraintPtr(element);
	return element;
	
}
std::shared_ptr<TimeConstraint> UmlFactoryImpl::createTimeConstraint_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<TimeConstraintImpl> element(new TimeConstraintImpl(par_namespace, UmlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisTimeConstraintPtr(element);
	return element;
	
}
std::shared_ptr<TimeConstraint> UmlFactoryImpl::createTimeConstraint_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<TimeConstraintImpl> element(new TimeConstraintImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisTimeConstraintPtr(element);
	return element;
	
}
std::shared_ptr<TimeConstraint> UmlFactoryImpl::createTimeConstraint_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<TimeConstraintImpl> element(new TimeConstraintImpl(par_owningPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisTimeConstraintPtr(element);
	return element;
	
}
std::shared_ptr<TimeConstraint> UmlFactoryImpl::createTimeConstraint_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<TimeConstraintImpl> element(new TimeConstraintImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisTimeConstraintPtr(element);
	return element;
	
}
std::shared_ptr<TimeEvent> UmlFactoryImpl::createTimeEvent(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<TimeEventImpl> element(new TimeEventImpl());
	element->setMetaElementID(metaElementID);
	element->setThisTimeEventPtr(element);
	return element;
}
std::shared_ptr<TimeEvent> UmlFactoryImpl::createTimeEvent_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<TimeEventImpl> element(new TimeEventImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisTimeEventPtr(element);
	return element;
	
}
std::shared_ptr<TimeEvent> UmlFactoryImpl::createTimeEvent_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<TimeEventImpl> element(new TimeEventImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisTimeEventPtr(element);
	return element;
	
}
std::shared_ptr<TimeEvent> UmlFactoryImpl::createTimeEvent_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<TimeEventImpl> element(new TimeEventImpl(par_owningPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisTimeEventPtr(element);
	return element;
	
}
std::shared_ptr<TimeEvent> UmlFactoryImpl::createTimeEvent_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<TimeEventImpl> element(new TimeEventImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisTimeEventPtr(element);
	return element;
	
}
std::shared_ptr<TimeExpression> UmlFactoryImpl::createTimeExpression(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<TimeExpressionImpl> element(new TimeExpressionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisTimeExpressionPtr(element);
	return element;
}
std::shared_ptr<TimeExpression> UmlFactoryImpl::createTimeExpression_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<TimeExpressionImpl> element(new TimeExpressionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisTimeExpressionPtr(element);
	return element;
	
}
std::shared_ptr<TimeExpression> UmlFactoryImpl::createTimeExpression_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<TimeExpressionImpl> element(new TimeExpressionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisTimeExpressionPtr(element);
	return element;
	
}
std::shared_ptr<TimeExpression> UmlFactoryImpl::createTimeExpression_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<TimeExpressionImpl> element(new TimeExpressionImpl(par_owningPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisTimeExpressionPtr(element);
	return element;
	
}
std::shared_ptr<TimeExpression> UmlFactoryImpl::createTimeExpression_in_OwningSlot(std::weak_ptr<uml::Slot > par_owningSlot, const int metaElementID) const
{
	std::shared_ptr<TimeExpressionImpl> element(new TimeExpressionImpl(par_owningSlot));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningSlot.lock())
	{
			wp->getValue()->push_back(element);
	}
	element->setThisTimeExpressionPtr(element);
	return element;
	
}
std::shared_ptr<TimeExpression> UmlFactoryImpl::createTimeExpression_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<TimeExpressionImpl> element(new TimeExpressionImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisTimeExpressionPtr(element);
	return element;
	
}
std::shared_ptr<TimeExpression> UmlFactoryImpl::createTimeExpression_in_ValueSpecificationAction(std::weak_ptr<uml::ValueSpecificationAction > par_valueSpecificationAction, const int metaElementID) const
{
	std::shared_ptr<TimeExpressionImpl> element(new TimeExpressionImpl(par_valueSpecificationAction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_valueSpecificationAction.lock())
	{
			wp->setValue(element);
	}
	element->setThisTimeExpressionPtr(element);
	return element;
	
}
std::shared_ptr<TimeInterval> UmlFactoryImpl::createTimeInterval(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<TimeIntervalImpl> element(new TimeIntervalImpl());
	element->setMetaElementID(metaElementID);
	element->setThisTimeIntervalPtr(element);
	return element;
}
std::shared_ptr<TimeInterval> UmlFactoryImpl::createTimeInterval_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<TimeIntervalImpl> element(new TimeIntervalImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisTimeIntervalPtr(element);
	return element;
	
}
std::shared_ptr<TimeInterval> UmlFactoryImpl::createTimeInterval_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<TimeIntervalImpl> element(new TimeIntervalImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisTimeIntervalPtr(element);
	return element;
	
}
std::shared_ptr<TimeInterval> UmlFactoryImpl::createTimeInterval_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<TimeIntervalImpl> element(new TimeIntervalImpl(par_owningPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisTimeIntervalPtr(element);
	return element;
	
}
std::shared_ptr<TimeInterval> UmlFactoryImpl::createTimeInterval_in_OwningSlot(std::weak_ptr<uml::Slot > par_owningSlot, const int metaElementID) const
{
	std::shared_ptr<TimeIntervalImpl> element(new TimeIntervalImpl(par_owningSlot));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningSlot.lock())
	{
			wp->getValue()->push_back(element);
	}
	element->setThisTimeIntervalPtr(element);
	return element;
	
}
std::shared_ptr<TimeInterval> UmlFactoryImpl::createTimeInterval_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<TimeIntervalImpl> element(new TimeIntervalImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisTimeIntervalPtr(element);
	return element;
	
}
std::shared_ptr<TimeInterval> UmlFactoryImpl::createTimeInterval_in_ValueSpecificationAction(std::weak_ptr<uml::ValueSpecificationAction > par_valueSpecificationAction, const int metaElementID) const
{
	std::shared_ptr<TimeIntervalImpl> element(new TimeIntervalImpl(par_valueSpecificationAction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_valueSpecificationAction.lock())
	{
			wp->setValue(element);
	}
	element->setThisTimeIntervalPtr(element);
	return element;
	
}
std::shared_ptr<TimeObservation> UmlFactoryImpl::createTimeObservation(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<TimeObservationImpl> element(new TimeObservationImpl());
	element->setMetaElementID(metaElementID);
	element->setThisTimeObservationPtr(element);
	return element;
}
std::shared_ptr<TimeObservation> UmlFactoryImpl::createTimeObservation_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<TimeObservationImpl> element(new TimeObservationImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisTimeObservationPtr(element);
	return element;
	
}
std::shared_ptr<TimeObservation> UmlFactoryImpl::createTimeObservation_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<TimeObservationImpl> element(new TimeObservationImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisTimeObservationPtr(element);
	return element;
	
}
std::shared_ptr<TimeObservation> UmlFactoryImpl::createTimeObservation_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<TimeObservationImpl> element(new TimeObservationImpl(par_owningPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisTimeObservationPtr(element);
	return element;
	
}
std::shared_ptr<TimeObservation> UmlFactoryImpl::createTimeObservation_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<TimeObservationImpl> element(new TimeObservationImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisTimeObservationPtr(element);
	return element;
	
}
std::shared_ptr<Transition> UmlFactoryImpl::createTransition(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<TransitionImpl> element(new TransitionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisTransitionPtr(element);
	return element;
}
std::shared_ptr<Transition> UmlFactoryImpl::createTransition_in_Container(std::weak_ptr<uml::Region > par_container, const int metaElementID) const
{
	std::shared_ptr<TransitionImpl> element(new TransitionImpl(par_container));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_container.lock())
	{
			wp->getTransition()->push_back(element);
	}
	element->setThisTransitionPtr(element);
	return element;
	
}
std::shared_ptr<Transition> UmlFactoryImpl::createTransition_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<TransitionImpl> element(new TransitionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisTransitionPtr(element);
	return element;
	
}
std::shared_ptr<Transition> UmlFactoryImpl::createTransition_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<TransitionImpl> element(new TransitionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisTransitionPtr(element);
	return element;
	
}
std::shared_ptr<Trigger> UmlFactoryImpl::createTrigger(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<TriggerImpl> element(new TriggerImpl());
	element->setMetaElementID(metaElementID);
	element->setThisTriggerPtr(element);
	return element;
}
std::shared_ptr<Trigger> UmlFactoryImpl::createTrigger_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<TriggerImpl> element(new TriggerImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisTriggerPtr(element);
	return element;
	
}
std::shared_ptr<Trigger> UmlFactoryImpl::createTrigger_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<TriggerImpl> element(new TriggerImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisTriggerPtr(element);
	return element;
	
}
std::shared_ptr<UnmarshallAction> UmlFactoryImpl::createUnmarshallAction(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<UnmarshallActionImpl> element(new UnmarshallActionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisUnmarshallActionPtr(element);
	return element;
}
std::shared_ptr<UnmarshallAction> UmlFactoryImpl::createUnmarshallAction_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<UnmarshallActionImpl> element(new UnmarshallActionImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisUnmarshallActionPtr(element);
	return element;
	
}
std::shared_ptr<UnmarshallAction> UmlFactoryImpl::createUnmarshallAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<UnmarshallActionImpl> element(new UnmarshallActionImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisUnmarshallActionPtr(element);
	return element;
	
}
std::shared_ptr<UnmarshallAction> UmlFactoryImpl::createUnmarshallAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<UnmarshallActionImpl> element(new UnmarshallActionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisUnmarshallActionPtr(element);
	return element;
	
}
std::shared_ptr<UnmarshallAction> UmlFactoryImpl::createUnmarshallAction_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<UnmarshallActionImpl> element(new UnmarshallActionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisUnmarshallActionPtr(element);
	return element;
	
}
std::shared_ptr<Usage> UmlFactoryImpl::createUsage(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<UsageImpl> element(new UsageImpl());
	element->setMetaElementID(metaElementID);
	element->setThisUsagePtr(element);
	return element;
}
std::shared_ptr<Usage> UmlFactoryImpl::createUsage_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<UsageImpl> element(new UsageImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisUsagePtr(element);
	return element;
	
}
std::shared_ptr<Usage> UmlFactoryImpl::createUsage_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<UsageImpl> element(new UsageImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisUsagePtr(element);
	return element;
	
}
std::shared_ptr<Usage> UmlFactoryImpl::createUsage_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<UsageImpl> element(new UsageImpl(par_owningPackage));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisUsagePtr(element);
	return element;
	
}
std::shared_ptr<Usage> UmlFactoryImpl::createUsage_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<UsageImpl> element(new UsageImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisUsagePtr(element);
	return element;
	
}
std::shared_ptr<UseCase> UmlFactoryImpl::createUseCase(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<UseCaseImpl> element(new UseCaseImpl());
	element->setMetaElementID(metaElementID);
	element->setThisUseCasePtr(element);
	return element;
}
std::shared_ptr<UseCase> UmlFactoryImpl::createUseCase_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<UseCaseImpl> element(new UseCaseImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisUseCasePtr(element);
	return element;
	
}
std::shared_ptr<UseCase> UmlFactoryImpl::createUseCase_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<UseCaseImpl> element(new UseCaseImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisUseCasePtr(element);
	return element;
	
}
std::shared_ptr<UseCase> UmlFactoryImpl::createUseCase_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage, const int metaElementID) const
{
	std::shared_ptr<UseCaseImpl> element(new UseCaseImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningPackage.lock())
	{
			wp->getPackagedElement()->push_back(element);
	}
	element->setThisUseCasePtr(element);
	return element;
	
}
std::shared_ptr<UseCase> UmlFactoryImpl::createUseCase_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<UseCaseImpl> element(new UseCaseImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisUseCasePtr(element);
	return element;
	
}
std::shared_ptr<UseCase> UmlFactoryImpl::createUseCase_in_Package(std::weak_ptr<uml::Package > par_package, const int metaElementID) const
{
	std::shared_ptr<UseCaseImpl> element(new UseCaseImpl(par_package, UmlPackage::TYPE_ATTRIBUTE_PACKAGE));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_package.lock())
	{
			wp->getOwnedType()->push_back(element);
	}
	element->setThisUseCasePtr(element);
	return element;
	
}
std::shared_ptr<ValuePin> UmlFactoryImpl::createValuePin(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ValuePinImpl> element(new ValuePinImpl());
	element->setMetaElementID(metaElementID);
	element->setThisValuePinPtr(element);
	return element;
}
std::shared_ptr<ValuePin> UmlFactoryImpl::createValuePin_in_Action(std::weak_ptr<uml::Action > par_action, const int metaElementID) const
{
	std::shared_ptr<ValuePinImpl> element(new ValuePinImpl(par_action));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_action.lock())
	{
			wp->getInput()->push_back(element);
	}
	element->setThisValuePinPtr(element);
	return element;
	
}
std::shared_ptr<ValuePin> UmlFactoryImpl::createValuePin_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<ValuePinImpl> element(new ValuePinImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisValuePinPtr(element);
	return element;
	
}
std::shared_ptr<ValuePin> UmlFactoryImpl::createValuePin_in_AddStructuralFeatureValueAction(std::weak_ptr<uml::AddStructuralFeatureValueAction > par_addStructuralFeatureValueAction, const int metaElementID) const
{
	std::shared_ptr<ValuePinImpl> element(new ValuePinImpl(par_addStructuralFeatureValueAction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_addStructuralFeatureValueAction.lock())
	{
			wp->setInsertAt(element);
	}
	element->setThisValuePinPtr(element);
	return element;
	
}
std::shared_ptr<ValuePin> UmlFactoryImpl::createValuePin_in_CallOperationAction(std::weak_ptr<uml::CallOperationAction > par_callOperationAction, const int metaElementID) const
{
	std::shared_ptr<ValuePinImpl> element(new ValuePinImpl(par_callOperationAction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_callOperationAction.lock())
	{
			wp->setTarget(element);
	}
	element->setThisValuePinPtr(element);
	return element;
	
}
std::shared_ptr<ValuePin> UmlFactoryImpl::createValuePin_in_DestroyObjectAction(std::weak_ptr<uml::DestroyObjectAction > par_destroyObjectAction, const int metaElementID) const
{
	std::shared_ptr<ValuePinImpl> element(new ValuePinImpl(par_destroyObjectAction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_destroyObjectAction.lock())
	{
			wp->setTarget(element);
	}
	element->setThisValuePinPtr(element);
	return element;
	
}
std::shared_ptr<ValuePin> UmlFactoryImpl::createValuePin_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<ValuePinImpl> element(new ValuePinImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisValuePinPtr(element);
	return element;
	
}
std::shared_ptr<ValuePin> UmlFactoryImpl::createValuePin_in_InvocationAction(std::weak_ptr<uml::InvocationAction > par_invocationAction, const int metaElementID) const
{
	std::shared_ptr<ValuePinImpl> element(new ValuePinImpl(par_invocationAction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_invocationAction.lock())
	{
			wp->getArgument()->push_back(element);
	}
	element->setThisValuePinPtr(element);
	return element;
	
}
std::shared_ptr<ValuePin> UmlFactoryImpl::createValuePin_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ValuePinImpl> element(new ValuePinImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisValuePinPtr(element);
	return element;
	
}
std::shared_ptr<ValuePin> UmlFactoryImpl::createValuePin_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ValuePinImpl> element(new ValuePinImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisValuePinPtr(element);
	return element;
	
}
std::shared_ptr<ValuePin> UmlFactoryImpl::createValuePin_in_StructuralFeatureAction(std::weak_ptr<uml::StructuralFeatureAction > par_structuralFeatureAction, const int metaElementID) const
{
	std::shared_ptr<ValuePinImpl> element(new ValuePinImpl(par_structuralFeatureAction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_structuralFeatureAction.lock())
	{
			wp->setObject(element);
	}
	element->setThisValuePinPtr(element);
	return element;
	
}
std::shared_ptr<ValuePin> UmlFactoryImpl::createValuePin_in_WriteStructuralFeatureAction(std::weak_ptr<uml::WriteStructuralFeatureAction > par_writeStructuralFeatureAction, const int metaElementID) const
{
	std::shared_ptr<ValuePinImpl> element(new ValuePinImpl(par_writeStructuralFeatureAction));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_writeStructuralFeatureAction.lock())
	{
			wp->setValue(element);
	}
	element->setThisValuePinPtr(element);
	return element;
	
}
std::shared_ptr<ValueSpecificationAction> UmlFactoryImpl::createValueSpecificationAction(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<ValueSpecificationActionImpl> element(new ValueSpecificationActionImpl());
	element->setMetaElementID(metaElementID);
	element->setThisValueSpecificationActionPtr(element);
	return element;
}
std::shared_ptr<ValueSpecificationAction> UmlFactoryImpl::createValueSpecificationAction_in_Activity(std::weak_ptr<uml::Activity > par_activity, const int metaElementID) const
{
	std::shared_ptr<ValueSpecificationActionImpl> element(new ValueSpecificationActionImpl(par_activity));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activity.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisValueSpecificationActionPtr(element);
	return element;
	
}
std::shared_ptr<ValueSpecificationAction> UmlFactoryImpl::createValueSpecificationAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode, const int metaElementID) const
{
	std::shared_ptr<ValueSpecificationActionImpl> element(new ValueSpecificationActionImpl(par_inStructuredNode));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_inStructuredNode.lock())
	{
			wp->getNode()->push_back(element);
	}
	element->setThisValueSpecificationActionPtr(element);
	return element;
	
}
std::shared_ptr<ValueSpecificationAction> UmlFactoryImpl::createValueSpecificationAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<ValueSpecificationActionImpl> element(new ValueSpecificationActionImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisValueSpecificationActionPtr(element);
	return element;
	
}
std::shared_ptr<ValueSpecificationAction> UmlFactoryImpl::createValueSpecificationAction_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<ValueSpecificationActionImpl> element(new ValueSpecificationActionImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisValueSpecificationActionPtr(element);
	return element;
	
}
std::shared_ptr<Variable> UmlFactoryImpl::createVariable(const int metaElementID/*=-1*/) const
{
	std::shared_ptr<VariableImpl> element(new VariableImpl());
	element->setMetaElementID(metaElementID);
	element->setThisVariablePtr(element);
	return element;
}
std::shared_ptr<Variable> UmlFactoryImpl::createVariable_in_ActivityScope(std::weak_ptr<uml::Activity > par_activityScope, const int metaElementID) const
{
	std::shared_ptr<VariableImpl> element(new VariableImpl(par_activityScope));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_activityScope.lock())
	{
			wp->getVariable()->push_back(element);
	}
	element->setThisVariablePtr(element);
	return element;
	
}
std::shared_ptr<Variable> UmlFactoryImpl::createVariable_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace, const int metaElementID) const
{
	std::shared_ptr<VariableImpl> element(new VariableImpl(par_namespace));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_namespace.lock())
	{
			wp->getOwnedMember()->push_back(element);
	}
	element->setThisVariablePtr(element);
	return element;
	
}
std::shared_ptr<Variable> UmlFactoryImpl::createVariable_in_Owner(std::weak_ptr<uml::Element > par_owner, const int metaElementID) const
{
	std::shared_ptr<VariableImpl> element(new VariableImpl(par_owner));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owner.lock())
	{
			wp->getOwnedElement()->push_back(element);
	}
	element->setThisVariablePtr(element);
	return element;
	
}
std::shared_ptr<Variable> UmlFactoryImpl::createVariable_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter, const int metaElementID) const
{
	std::shared_ptr<VariableImpl> element(new VariableImpl(par_owningTemplateParameter));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	element->setThisVariablePtr(element);
	return element;
	
}
std::shared_ptr<Variable> UmlFactoryImpl::createVariable_in_Scope(std::weak_ptr<uml::StructuredActivityNode > par_scope, const int metaElementID) const
{
	std::shared_ptr<VariableImpl> element(new VariableImpl(par_scope));
	element->setMetaElementID(metaElementID);
	if(auto wp = par_scope.lock())
	{
			wp->getVariable()->push_back(element);
	}
	element->setThisVariablePtr(element);
	return element;
	
}

std::shared_ptr<UmlPackage> UmlFactoryImpl::getUmlPackage() const
{
	return UmlPackage::eInstance();
}
