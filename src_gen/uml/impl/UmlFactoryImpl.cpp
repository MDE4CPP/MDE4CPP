#include "UmlFactoryImpl.hpp"
#include "UmlPackage.hpp"

#include "EClass.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************

UmlFactoryImpl::UmlFactoryImpl()
{
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

ecore::EObject* UmlFactoryImpl::create(ecore::EClass* _class) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}

	switch (_class->getClassifierID())
	{
		case UmlPackage::ABSTRACTION : return createAbstraction();
		case UmlPackage::ACCEPTCALLACTION : return createAcceptCallAction();
		case UmlPackage::ACCEPTEVENTACTION : return createAcceptEventAction();
		case UmlPackage::ACTIONEXECUTIONSPECIFICATION : return createActionExecutionSpecification();
		case UmlPackage::ACTIONINPUTPIN : return createActionInputPin();
		case UmlPackage::ACTIVITY : return createActivity();
		case UmlPackage::ACTIVITYFINALNODE : return createActivityFinalNode();
		case UmlPackage::ACTIVITYPARAMETERNODE : return createActivityParameterNode();
		case UmlPackage::ACTIVITYPARTITION : return createActivityPartition();
		case UmlPackage::ACTOR : return createActor();
		case UmlPackage::ADDSTRUCTURALFEATUREVALUEACTION : return createAddStructuralFeatureValueAction();
		case UmlPackage::ADDVARIABLEVALUEACTION : return createAddVariableValueAction();
		case UmlPackage::ANYRECEIVEEVENT : return createAnyReceiveEvent();
		case UmlPackage::ARTIFACT : return createArtifact();
		case UmlPackage::ASSOCIATION : return createAssociation();
		case UmlPackage::ASSOCIATIONCLASS : return createAssociationClass();
		case UmlPackage::BEHAVIOREXECUTIONSPECIFICATION : return createBehaviorExecutionSpecification();
		case UmlPackage::BROADCASTSIGNALACTION : return createBroadcastSignalAction();
		case UmlPackage::CALLBEHAVIORACTION : return createCallBehaviorAction();
		case UmlPackage::CALLEVENT : return createCallEvent();
		case UmlPackage::CALLOPERATIONACTION : return createCallOperationAction();
		case UmlPackage::CENTRALBUFFERNODE : return createCentralBufferNode();
		case UmlPackage::CHANGEEVENT : return createChangeEvent();
		case UmlPackage::CLASS : return createClass();
		case UmlPackage::CLASSIFIERTEMPLATEPARAMETER : return createClassifierTemplateParameter();
		case UmlPackage::CLAUSE : return createClause();
		case UmlPackage::CLEARASSOCIATIONACTION : return createClearAssociationAction();
		case UmlPackage::CLEARSTRUCTURALFEATUREACTION : return createClearStructuralFeatureAction();
		case UmlPackage::CLEARVARIABLEACTION : return createClearVariableAction();
		case UmlPackage::COLLABORATION : return createCollaboration();
		case UmlPackage::COLLABORATIONUSE : return createCollaborationUse();
		case UmlPackage::COMBINEDFRAGMENT : return createCombinedFragment();
		case UmlPackage::COMMENT : return createComment();
		case UmlPackage::COMMUNICATIONPATH : return createCommunicationPath();
		case UmlPackage::COMPONENT : return createComponent();
		case UmlPackage::COMPONENTREALIZATION : return createComponentRealization();
		case UmlPackage::CONDITIONALNODE : return createConditionalNode();
		case UmlPackage::CONNECTABLEELEMENTTEMPLATEPARAMETER : return createConnectableElementTemplateParameter();
		case UmlPackage::CONNECTIONPOINTREFERENCE : return createConnectionPointReference();
		case UmlPackage::CONNECTOR : return createConnector();
		case UmlPackage::CONNECTOREND : return createConnectorEnd();
		case UmlPackage::CONSIDERIGNOREFRAGMENT : return createConsiderIgnoreFragment();
		case UmlPackage::CONSTRAINT : return createConstraint();
		case UmlPackage::CONTINUATION : return createContinuation();
		case UmlPackage::CONTROLFLOW : return createControlFlow();
		case UmlPackage::CREATELINKACTION : return createCreateLinkAction();
		case UmlPackage::CREATELINKOBJECTACTION : return createCreateLinkObjectAction();
		case UmlPackage::CREATEOBJECTACTION : return createCreateObjectAction();
		case UmlPackage::DATASTORENODE : return createDataStoreNode();
		case UmlPackage::DATATYPE : return createDataType();
		case UmlPackage::DECISIONNODE : return createDecisionNode();
		case UmlPackage::DEPENDENCY : return createDependency();
		case UmlPackage::DEPLOYMENT : return createDeployment();
		case UmlPackage::DEPLOYMENTSPECIFICATION : return createDeploymentSpecification();
		case UmlPackage::DESTROYLINKACTION : return createDestroyLinkAction();
		case UmlPackage::DESTROYOBJECTACTION : return createDestroyObjectAction();
		case UmlPackage::DESTRUCTIONOCCURRENCESPECIFICATION : return createDestructionOccurrenceSpecification();
		case UmlPackage::DEVICE : return createDevice();
		case UmlPackage::DURATION : return createDuration();
		case UmlPackage::DURATIONCONSTRAINT : return createDurationConstraint();
		case UmlPackage::DURATIONINTERVAL : return createDurationInterval();
		case UmlPackage::DURATIONOBSERVATION : return createDurationObservation();
		case UmlPackage::ELEMENTIMPORT : return createElementImport();
		case UmlPackage::ENUMERATION : return createEnumeration();
		case UmlPackage::ENUMERATIONLITERAL : return createEnumerationLiteral();
		case UmlPackage::EXCEPTIONHANDLER : return createExceptionHandler();
		case UmlPackage::EXECUTIONENVIRONMENT : return createExecutionEnvironment();
		case UmlPackage::EXECUTIONOCCURRENCESPECIFICATION : return createExecutionOccurrenceSpecification();
		case UmlPackage::EXPANSIONNODE : return createExpansionNode();
		case UmlPackage::EXPANSIONREGION : return createExpansionRegion();
		case UmlPackage::EXPRESSION : return createExpression();
		case UmlPackage::EXTEND : return createExtend();
		case UmlPackage::EXTENSION : return createExtension();
		case UmlPackage::EXTENSIONEND : return createExtensionEnd();
		case UmlPackage::EXTENSIONPOINT : return createExtensionPoint();
		case UmlPackage::FACTORY : return createFactory();
		case UmlPackage::FINALSTATE : return createFinalState();
		case UmlPackage::FLOWFINALNODE : return createFlowFinalNode();
		case UmlPackage::FORKNODE : return createForkNode();
		case UmlPackage::FUNCTIONBEHAVIOR : return createFunctionBehavior();
		case UmlPackage::GATE : return createGate();
		case UmlPackage::GENERALORDERING : return createGeneralOrdering();
		case UmlPackage::GENERALIZATION : return createGeneralization();
		case UmlPackage::GENERALIZATIONSET : return createGeneralizationSet();
		case UmlPackage::IMAGE : return createImage();
		case UmlPackage::INCLUDE : return createInclude();
		case UmlPackage::INFORMATIONFLOW : return createInformationFlow();
		case UmlPackage::INFORMATIONITEM : return createInformationItem();
		case UmlPackage::INITIALNODE : return createInitialNode();
		case UmlPackage::INPUTPIN : return createInputPin();
		case UmlPackage::INSTANCESPECIFICATION : return createInstanceSpecification();
		case UmlPackage::INSTANCEVALUE : return createInstanceValue();
		case UmlPackage::INTERACTION : return createInteraction();
		case UmlPackage::INTERACTIONCONSTRAINT : return createInteractionConstraint();
		case UmlPackage::INTERACTIONOPERAND : return createInteractionOperand();
		case UmlPackage::INTERACTIONUSE : return createInteractionUse();
		case UmlPackage::INTERFACE : return createInterface();
		case UmlPackage::INTERFACEREALIZATION : return createInterfaceRealization();
		case UmlPackage::INTERRUPTIBLEACTIVITYREGION : return createInterruptibleActivityRegion();
		case UmlPackage::INTERVAL : return createInterval();
		case UmlPackage::INTERVALCONSTRAINT : return createIntervalConstraint();
		case UmlPackage::JOINNODE : return createJoinNode();
		case UmlPackage::LIFELINE : return createLifeline();
		case UmlPackage::LINKENDCREATIONDATA : return createLinkEndCreationData();
		case UmlPackage::LINKENDDATA : return createLinkEndData();
		case UmlPackage::LINKENDDESTRUCTIONDATA : return createLinkEndDestructionData();
		case UmlPackage::LITERALBOOLEAN : return createLiteralBoolean();
		case UmlPackage::LITERALINTEGER : return createLiteralInteger();
		case UmlPackage::LITERALNULL : return createLiteralNull();
		case UmlPackage::LITERALREAL : return createLiteralReal();
		case UmlPackage::LITERALSTRING : return createLiteralString();
		case UmlPackage::LITERALUNLIMITEDNATURAL : return createLiteralUnlimitedNatural();
		case UmlPackage::LOOPNODE : return createLoopNode();
		case UmlPackage::MANIFESTATION : return createManifestation();
		case UmlPackage::MERGENODE : return createMergeNode();
		case UmlPackage::MESSAGE : return createMessage();
		case UmlPackage::MESSAGEOCCURRENCESPECIFICATION : return createMessageOccurrenceSpecification();
		case UmlPackage::MODEL : return createModel();
		case UmlPackage::NODE : return createNode();
		case UmlPackage::OBJECT : return createObject();
		case UmlPackage::OBJECTFLOW : return createObjectFlow();
		case UmlPackage::OCCURRENCESPECIFICATION : return createOccurrenceSpecification();
		case UmlPackage::OPAQUEACTION : return createOpaqueAction();
		case UmlPackage::OPAQUEBEHAVIOR : return createOpaqueBehavior();
		case UmlPackage::OPAQUEEXPRESSION : return createOpaqueExpression();
		case UmlPackage::OPERATION : return createOperation();
		case UmlPackage::OPERATIONTEMPLATEPARAMETER : return createOperationTemplateParameter();
		case UmlPackage::OUTPUTPIN : return createOutputPin();
		case UmlPackage::PACKAGE : return createPackage();
		case UmlPackage::PACKAGEIMPORT : return createPackageImport();
		case UmlPackage::PACKAGEMERGE : return createPackageMerge();
		case UmlPackage::PARAMETER : return createParameter();
		case UmlPackage::PARAMETERSET : return createParameterSet();
		case UmlPackage::PARTDECOMPOSITION : return createPartDecomposition();
		case UmlPackage::PORT : return createPort();
		case UmlPackage::PRIMITIVETYPE : return createPrimitiveType();
		case UmlPackage::PROFILE : return createProfile();
		case UmlPackage::PROFILEAPPLICATION : return createProfileApplication();
		case UmlPackage::PROPERTY : return createProperty();
		case UmlPackage::PROTOCOLCONFORMANCE : return createProtocolConformance();
		case UmlPackage::PROTOCOLSTATEMACHINE : return createProtocolStateMachine();
		case UmlPackage::PROTOCOLTRANSITION : return createProtocolTransition();
		case UmlPackage::PSEUDOSTATE : return createPseudostate();
		case UmlPackage::QUALIFIERVALUE : return createQualifierValue();
		case UmlPackage::RAISEEXCEPTIONACTION : return createRaiseExceptionAction();
		case UmlPackage::READEXTENTACTION : return createReadExtentAction();
		case UmlPackage::READISCLASSIFIEDOBJECTACTION : return createReadIsClassifiedObjectAction();
		case UmlPackage::READLINKACTION : return createReadLinkAction();
		case UmlPackage::READLINKOBJECTENDACTION : return createReadLinkObjectEndAction();
		case UmlPackage::READLINKOBJECTENDQUALIFIERACTION : return createReadLinkObjectEndQualifierAction();
		case UmlPackage::READSELFACTION : return createReadSelfAction();
		case UmlPackage::READSTRUCTURALFEATUREACTION : return createReadStructuralFeatureAction();
		case UmlPackage::READVARIABLEACTION : return createReadVariableAction();
		case UmlPackage::REALIZATION : return createRealization();
		case UmlPackage::RECEPTION : return createReception();
		case UmlPackage::RECLASSIFYOBJECTACTION : return createReclassifyObjectAction();
		case UmlPackage::REDEFINABLETEMPLATESIGNATURE : return createRedefinableTemplateSignature();
		case UmlPackage::REDUCEACTION : return createReduceAction();
		case UmlPackage::REGION : return createRegion();
		case UmlPackage::REMOVESTRUCTURALFEATUREVALUEACTION : return createRemoveStructuralFeatureValueAction();
		case UmlPackage::REMOVEVARIABLEVALUEACTION : return createRemoveVariableValueAction();
		case UmlPackage::REPLYACTION : return createReplyAction();
		case UmlPackage::SENDOBJECTACTION : return createSendObjectAction();
		case UmlPackage::SENDSIGNALACTION : return createSendSignalAction();
		case UmlPackage::SEQUENCENODE : return createSequenceNode();
		case UmlPackage::SIGNAL : return createSignal();
		case UmlPackage::SIGNALEVENT : return createSignalEvent();
		case UmlPackage::SLOT : return createSlot();
		case UmlPackage::STARTCLASSIFIERBEHAVIORACTION : return createStartClassifierBehaviorAction();
		case UmlPackage::STARTOBJECTBEHAVIORACTION : return createStartObjectBehaviorAction();
		case UmlPackage::STATE : return createState();
		case UmlPackage::STATEINVARIANT : return createStateInvariant();
		case UmlPackage::STATEMACHINE : return createStateMachine();
		case UmlPackage::STEREOTYPE : return createStereotype();
		case UmlPackage::STRINGEXPRESSION : return createStringExpression();
		case UmlPackage::STRUCTUREDACTIVITYNODE : return createStructuredActivityNode();
		case UmlPackage::SUBSTITUTION : return createSubstitution();
		case UmlPackage::TEMPLATEBINDING : return createTemplateBinding();
		case UmlPackage::TEMPLATEPARAMETER : return createTemplateParameter();
		case UmlPackage::TEMPLATEPARAMETERSUBSTITUTION : return createTemplateParameterSubstitution();
		case UmlPackage::TEMPLATESIGNATURE : return createTemplateSignature();
		case UmlPackage::TESTIDENTITYACTION : return createTestIdentityAction();
		case UmlPackage::TIMECONSTRAINT : return createTimeConstraint();
		case UmlPackage::TIMEEVENT : return createTimeEvent();
		case UmlPackage::TIMEEXPRESSION : return createTimeExpression();
		case UmlPackage::TIMEINTERVAL : return createTimeInterval();
		case UmlPackage::TIMEOBSERVATION : return createTimeObservation();
		case UmlPackage::TRANSITION : return createTransition();
		case UmlPackage::TRIGGER : return createTrigger();
		case UmlPackage::UNMARSHALLACTION : return createUnmarshallAction();
		case UmlPackage::USAGE : return createUsage();
		case UmlPackage::USECASE : return createUseCase();
		case UmlPackage::VALUEPIN : return createValuePin();
		case UmlPackage::VALUESPECIFICATIONACTION : return createValueSpecificationAction();
		case UmlPackage::VARIABLE : return createVariable();
		default:
       		throw "Error create class '" + _class->getName();
	}
	return nullptr;
}

Abstraction* UmlFactoryImpl::createAbstraction () const
{
	return new AbstractionImpl();
}
AcceptCallAction* UmlFactoryImpl::createAcceptCallAction () const
{
	return new AcceptCallActionImpl();
}
AcceptEventAction* UmlFactoryImpl::createAcceptEventAction () const
{
	return new AcceptEventActionImpl();
}
ActionExecutionSpecification* UmlFactoryImpl::createActionExecutionSpecification () const
{
	return new ActionExecutionSpecificationImpl();
}
ActionInputPin* UmlFactoryImpl::createActionInputPin () const
{
	return new ActionInputPinImpl();
}
Activity* UmlFactoryImpl::createActivity () const
{
	return new ActivityImpl();
}
ActivityFinalNode* UmlFactoryImpl::createActivityFinalNode () const
{
	return new ActivityFinalNodeImpl();
}
ActivityParameterNode* UmlFactoryImpl::createActivityParameterNode () const
{
	return new ActivityParameterNodeImpl();
}
ActivityPartition* UmlFactoryImpl::createActivityPartition () const
{
	return new ActivityPartitionImpl();
}
Actor* UmlFactoryImpl::createActor () const
{
	return new ActorImpl();
}
AddStructuralFeatureValueAction* UmlFactoryImpl::createAddStructuralFeatureValueAction () const
{
	return new AddStructuralFeatureValueActionImpl();
}
AddVariableValueAction* UmlFactoryImpl::createAddVariableValueAction () const
{
	return new AddVariableValueActionImpl();
}
AnyReceiveEvent* UmlFactoryImpl::createAnyReceiveEvent () const
{
	return new AnyReceiveEventImpl();
}
Artifact* UmlFactoryImpl::createArtifact () const
{
	return new ArtifactImpl();
}
Association* UmlFactoryImpl::createAssociation () const
{
	return new AssociationImpl();
}
AssociationClass* UmlFactoryImpl::createAssociationClass () const
{
	return new AssociationClassImpl();
}
BehaviorExecutionSpecification* UmlFactoryImpl::createBehaviorExecutionSpecification () const
{
	return new BehaviorExecutionSpecificationImpl();
}
BroadcastSignalAction* UmlFactoryImpl::createBroadcastSignalAction () const
{
	return new BroadcastSignalActionImpl();
}
CallBehaviorAction* UmlFactoryImpl::createCallBehaviorAction () const
{
	return new CallBehaviorActionImpl();
}
CallEvent* UmlFactoryImpl::createCallEvent () const
{
	return new CallEventImpl();
}
CallOperationAction* UmlFactoryImpl::createCallOperationAction () const
{
	return new CallOperationActionImpl();
}
CentralBufferNode* UmlFactoryImpl::createCentralBufferNode () const
{
	return new CentralBufferNodeImpl();
}
ChangeEvent* UmlFactoryImpl::createChangeEvent () const
{
	return new ChangeEventImpl();
}
Class* UmlFactoryImpl::createClass () const
{
	return new ClassImpl();
}
ClassifierTemplateParameter* UmlFactoryImpl::createClassifierTemplateParameter () const
{
	return new ClassifierTemplateParameterImpl();
}
Clause* UmlFactoryImpl::createClause () const
{
	return new ClauseImpl();
}
ClearAssociationAction* UmlFactoryImpl::createClearAssociationAction () const
{
	return new ClearAssociationActionImpl();
}
ClearStructuralFeatureAction* UmlFactoryImpl::createClearStructuralFeatureAction () const
{
	return new ClearStructuralFeatureActionImpl();
}
ClearVariableAction* UmlFactoryImpl::createClearVariableAction () const
{
	return new ClearVariableActionImpl();
}
Collaboration* UmlFactoryImpl::createCollaboration () const
{
	return new CollaborationImpl();
}
CollaborationUse* UmlFactoryImpl::createCollaborationUse () const
{
	return new CollaborationUseImpl();
}
CombinedFragment* UmlFactoryImpl::createCombinedFragment () const
{
	return new CombinedFragmentImpl();
}
Comment* UmlFactoryImpl::createComment () const
{
	return new CommentImpl();
}
CommunicationPath* UmlFactoryImpl::createCommunicationPath () const
{
	return new CommunicationPathImpl();
}
Component* UmlFactoryImpl::createComponent () const
{
	return new ComponentImpl();
}
ComponentRealization* UmlFactoryImpl::createComponentRealization () const
{
	return new ComponentRealizationImpl();
}
ConditionalNode* UmlFactoryImpl::createConditionalNode () const
{
	return new ConditionalNodeImpl();
}
ConnectableElementTemplateParameter* UmlFactoryImpl::createConnectableElementTemplateParameter () const
{
	return new ConnectableElementTemplateParameterImpl();
}
ConnectionPointReference* UmlFactoryImpl::createConnectionPointReference () const
{
	return new ConnectionPointReferenceImpl();
}
Connector* UmlFactoryImpl::createConnector () const
{
	return new ConnectorImpl();
}
ConnectorEnd* UmlFactoryImpl::createConnectorEnd () const
{
	return new ConnectorEndImpl();
}
ConsiderIgnoreFragment* UmlFactoryImpl::createConsiderIgnoreFragment () const
{
	return new ConsiderIgnoreFragmentImpl();
}
Constraint* UmlFactoryImpl::createConstraint () const
{
	return new ConstraintImpl();
}
Continuation* UmlFactoryImpl::createContinuation () const
{
	return new ContinuationImpl();
}
ControlFlow* UmlFactoryImpl::createControlFlow () const
{
	return new ControlFlowImpl();
}
CreateLinkAction* UmlFactoryImpl::createCreateLinkAction () const
{
	return new CreateLinkActionImpl();
}
CreateLinkObjectAction* UmlFactoryImpl::createCreateLinkObjectAction () const
{
	return new CreateLinkObjectActionImpl();
}
CreateObjectAction* UmlFactoryImpl::createCreateObjectAction () const
{
	return new CreateObjectActionImpl();
}
DataStoreNode* UmlFactoryImpl::createDataStoreNode () const
{
	return new DataStoreNodeImpl();
}
DataType* UmlFactoryImpl::createDataType () const
{
	return new DataTypeImpl();
}
DecisionNode* UmlFactoryImpl::createDecisionNode () const
{
	return new DecisionNodeImpl();
}
Dependency* UmlFactoryImpl::createDependency () const
{
	return new DependencyImpl();
}
Deployment* UmlFactoryImpl::createDeployment () const
{
	return new DeploymentImpl();
}
DeploymentSpecification* UmlFactoryImpl::createDeploymentSpecification () const
{
	return new DeploymentSpecificationImpl();
}
DestroyLinkAction* UmlFactoryImpl::createDestroyLinkAction () const
{
	return new DestroyLinkActionImpl();
}
DestroyObjectAction* UmlFactoryImpl::createDestroyObjectAction () const
{
	return new DestroyObjectActionImpl();
}
DestructionOccurrenceSpecification* UmlFactoryImpl::createDestructionOccurrenceSpecification () const
{
	return new DestructionOccurrenceSpecificationImpl();
}
Device* UmlFactoryImpl::createDevice () const
{
	return new DeviceImpl();
}
Duration* UmlFactoryImpl::createDuration () const
{
	return new DurationImpl();
}
DurationConstraint* UmlFactoryImpl::createDurationConstraint () const
{
	return new DurationConstraintImpl();
}
DurationInterval* UmlFactoryImpl::createDurationInterval () const
{
	return new DurationIntervalImpl();
}
DurationObservation* UmlFactoryImpl::createDurationObservation () const
{
	return new DurationObservationImpl();
}
ElementImport* UmlFactoryImpl::createElementImport () const
{
	return new ElementImportImpl();
}
Enumeration* UmlFactoryImpl::createEnumeration () const
{
	return new EnumerationImpl();
}
EnumerationLiteral* UmlFactoryImpl::createEnumerationLiteral () const
{
	return new EnumerationLiteralImpl();
}
ExceptionHandler* UmlFactoryImpl::createExceptionHandler () const
{
	return new ExceptionHandlerImpl();
}
ExecutionEnvironment* UmlFactoryImpl::createExecutionEnvironment () const
{
	return new ExecutionEnvironmentImpl();
}
ExecutionOccurrenceSpecification* UmlFactoryImpl::createExecutionOccurrenceSpecification () const
{
	return new ExecutionOccurrenceSpecificationImpl();
}
ExpansionNode* UmlFactoryImpl::createExpansionNode () const
{
	return new ExpansionNodeImpl();
}
ExpansionRegion* UmlFactoryImpl::createExpansionRegion () const
{
	return new ExpansionRegionImpl();
}
Expression* UmlFactoryImpl::createExpression () const
{
	return new ExpressionImpl();
}
Extend* UmlFactoryImpl::createExtend () const
{
	return new ExtendImpl();
}
Extension* UmlFactoryImpl::createExtension () const
{
	return new ExtensionImpl();
}
ExtensionEnd* UmlFactoryImpl::createExtensionEnd () const
{
	return new ExtensionEndImpl();
}
ExtensionPoint* UmlFactoryImpl::createExtensionPoint () const
{
	return new ExtensionPointImpl();
}
Factory* UmlFactoryImpl::createFactory () const
{
	return new FactoryImpl();
}
FinalState* UmlFactoryImpl::createFinalState () const
{
	return new FinalStateImpl();
}
FlowFinalNode* UmlFactoryImpl::createFlowFinalNode () const
{
	return new FlowFinalNodeImpl();
}
ForkNode* UmlFactoryImpl::createForkNode () const
{
	return new ForkNodeImpl();
}
FunctionBehavior* UmlFactoryImpl::createFunctionBehavior () const
{
	return new FunctionBehaviorImpl();
}
Gate* UmlFactoryImpl::createGate () const
{
	return new GateImpl();
}
GeneralOrdering* UmlFactoryImpl::createGeneralOrdering () const
{
	return new GeneralOrderingImpl();
}
Generalization* UmlFactoryImpl::createGeneralization () const
{
	return new GeneralizationImpl();
}
GeneralizationSet* UmlFactoryImpl::createGeneralizationSet () const
{
	return new GeneralizationSetImpl();
}
Image* UmlFactoryImpl::createImage () const
{
	return new ImageImpl();
}
Include* UmlFactoryImpl::createInclude () const
{
	return new IncludeImpl();
}
InformationFlow* UmlFactoryImpl::createInformationFlow () const
{
	return new InformationFlowImpl();
}
InformationItem* UmlFactoryImpl::createInformationItem () const
{
	return new InformationItemImpl();
}
InitialNode* UmlFactoryImpl::createInitialNode () const
{
	return new InitialNodeImpl();
}
InputPin* UmlFactoryImpl::createInputPin () const
{
	return new InputPinImpl();
}
InstanceSpecification* UmlFactoryImpl::createInstanceSpecification () const
{
	return new InstanceSpecificationImpl();
}
InstanceValue* UmlFactoryImpl::createInstanceValue () const
{
	return new InstanceValueImpl();
}
Interaction* UmlFactoryImpl::createInteraction () const
{
	return new InteractionImpl();
}
InteractionConstraint* UmlFactoryImpl::createInteractionConstraint () const
{
	return new InteractionConstraintImpl();
}
InteractionOperand* UmlFactoryImpl::createInteractionOperand () const
{
	return new InteractionOperandImpl();
}
InteractionUse* UmlFactoryImpl::createInteractionUse () const
{
	return new InteractionUseImpl();
}
Interface* UmlFactoryImpl::createInterface () const
{
	return new InterfaceImpl();
}
InterfaceRealization* UmlFactoryImpl::createInterfaceRealization () const
{
	return new InterfaceRealizationImpl();
}
InterruptibleActivityRegion* UmlFactoryImpl::createInterruptibleActivityRegion () const
{
	return new InterruptibleActivityRegionImpl();
}
Interval* UmlFactoryImpl::createInterval () const
{
	return new IntervalImpl();
}
IntervalConstraint* UmlFactoryImpl::createIntervalConstraint () const
{
	return new IntervalConstraintImpl();
}
JoinNode* UmlFactoryImpl::createJoinNode () const
{
	return new JoinNodeImpl();
}
Lifeline* UmlFactoryImpl::createLifeline () const
{
	return new LifelineImpl();
}
LinkEndCreationData* UmlFactoryImpl::createLinkEndCreationData () const
{
	return new LinkEndCreationDataImpl();
}
LinkEndData* UmlFactoryImpl::createLinkEndData () const
{
	return new LinkEndDataImpl();
}
LinkEndDestructionData* UmlFactoryImpl::createLinkEndDestructionData () const
{
	return new LinkEndDestructionDataImpl();
}
LiteralBoolean* UmlFactoryImpl::createLiteralBoolean () const
{
	return new LiteralBooleanImpl();
}
LiteralInteger* UmlFactoryImpl::createLiteralInteger () const
{
	return new LiteralIntegerImpl();
}
LiteralNull* UmlFactoryImpl::createLiteralNull () const
{
	return new LiteralNullImpl();
}
LiteralReal* UmlFactoryImpl::createLiteralReal () const
{
	return new LiteralRealImpl();
}
LiteralString* UmlFactoryImpl::createLiteralString () const
{
	return new LiteralStringImpl();
}
LiteralUnlimitedNatural* UmlFactoryImpl::createLiteralUnlimitedNatural () const
{
	return new LiteralUnlimitedNaturalImpl();
}
LoopNode* UmlFactoryImpl::createLoopNode () const
{
	return new LoopNodeImpl();
}
Manifestation* UmlFactoryImpl::createManifestation () const
{
	return new ManifestationImpl();
}
MergeNode* UmlFactoryImpl::createMergeNode () const
{
	return new MergeNodeImpl();
}
Message* UmlFactoryImpl::createMessage () const
{
	return new MessageImpl();
}
MessageOccurrenceSpecification* UmlFactoryImpl::createMessageOccurrenceSpecification () const
{
	return new MessageOccurrenceSpecificationImpl();
}
Model* UmlFactoryImpl::createModel () const
{
	return new ModelImpl();
}
Node* UmlFactoryImpl::createNode () const
{
	return new NodeImpl();
}
Object* UmlFactoryImpl::createObject () const
{
	return new ObjectImpl();
}
ObjectFlow* UmlFactoryImpl::createObjectFlow () const
{
	return new ObjectFlowImpl();
}
OccurrenceSpecification* UmlFactoryImpl::createOccurrenceSpecification () const
{
	return new OccurrenceSpecificationImpl();
}
OpaqueAction* UmlFactoryImpl::createOpaqueAction () const
{
	return new OpaqueActionImpl();
}
OpaqueBehavior* UmlFactoryImpl::createOpaqueBehavior () const
{
	return new OpaqueBehaviorImpl();
}
OpaqueExpression* UmlFactoryImpl::createOpaqueExpression () const
{
	return new OpaqueExpressionImpl();
}
Operation* UmlFactoryImpl::createOperation () const
{
	return new OperationImpl();
}
OperationTemplateParameter* UmlFactoryImpl::createOperationTemplateParameter () const
{
	return new OperationTemplateParameterImpl();
}
OutputPin* UmlFactoryImpl::createOutputPin () const
{
	return new OutputPinImpl();
}
Package* UmlFactoryImpl::createPackage () const
{
	return new PackageImpl();
}
PackageImport* UmlFactoryImpl::createPackageImport () const
{
	return new PackageImportImpl();
}
PackageMerge* UmlFactoryImpl::createPackageMerge () const
{
	return new PackageMergeImpl();
}
Parameter* UmlFactoryImpl::createParameter () const
{
	return new ParameterImpl();
}
ParameterSet* UmlFactoryImpl::createParameterSet () const
{
	return new ParameterSetImpl();
}
PartDecomposition* UmlFactoryImpl::createPartDecomposition () const
{
	return new PartDecompositionImpl();
}
Port* UmlFactoryImpl::createPort () const
{
	return new PortImpl();
}
PrimitiveType* UmlFactoryImpl::createPrimitiveType () const
{
	return new PrimitiveTypeImpl();
}
Profile* UmlFactoryImpl::createProfile () const
{
	return new ProfileImpl();
}
ProfileApplication* UmlFactoryImpl::createProfileApplication () const
{
	return new ProfileApplicationImpl();
}
Property* UmlFactoryImpl::createProperty () const
{
	return new PropertyImpl();
}
ProtocolConformance* UmlFactoryImpl::createProtocolConformance () const
{
	return new ProtocolConformanceImpl();
}
ProtocolStateMachine* UmlFactoryImpl::createProtocolStateMachine () const
{
	return new ProtocolStateMachineImpl();
}
ProtocolTransition* UmlFactoryImpl::createProtocolTransition () const
{
	return new ProtocolTransitionImpl();
}
Pseudostate* UmlFactoryImpl::createPseudostate () const
{
	return new PseudostateImpl();
}
QualifierValue* UmlFactoryImpl::createQualifierValue () const
{
	return new QualifierValueImpl();
}
RaiseExceptionAction* UmlFactoryImpl::createRaiseExceptionAction () const
{
	return new RaiseExceptionActionImpl();
}
ReadExtentAction* UmlFactoryImpl::createReadExtentAction () const
{
	return new ReadExtentActionImpl();
}
ReadIsClassifiedObjectAction* UmlFactoryImpl::createReadIsClassifiedObjectAction () const
{
	return new ReadIsClassifiedObjectActionImpl();
}
ReadLinkAction* UmlFactoryImpl::createReadLinkAction () const
{
	return new ReadLinkActionImpl();
}
ReadLinkObjectEndAction* UmlFactoryImpl::createReadLinkObjectEndAction () const
{
	return new ReadLinkObjectEndActionImpl();
}
ReadLinkObjectEndQualifierAction* UmlFactoryImpl::createReadLinkObjectEndQualifierAction () const
{
	return new ReadLinkObjectEndQualifierActionImpl();
}
ReadSelfAction* UmlFactoryImpl::createReadSelfAction () const
{
	return new ReadSelfActionImpl();
}
ReadStructuralFeatureAction* UmlFactoryImpl::createReadStructuralFeatureAction () const
{
	return new ReadStructuralFeatureActionImpl();
}
ReadVariableAction* UmlFactoryImpl::createReadVariableAction () const
{
	return new ReadVariableActionImpl();
}
Realization* UmlFactoryImpl::createRealization () const
{
	return new RealizationImpl();
}
Reception* UmlFactoryImpl::createReception () const
{
	return new ReceptionImpl();
}
ReclassifyObjectAction* UmlFactoryImpl::createReclassifyObjectAction () const
{
	return new ReclassifyObjectActionImpl();
}
RedefinableTemplateSignature* UmlFactoryImpl::createRedefinableTemplateSignature () const
{
	return new RedefinableTemplateSignatureImpl();
}
ReduceAction* UmlFactoryImpl::createReduceAction () const
{
	return new ReduceActionImpl();
}
Region* UmlFactoryImpl::createRegion () const
{
	return new RegionImpl();
}
RemoveStructuralFeatureValueAction* UmlFactoryImpl::createRemoveStructuralFeatureValueAction () const
{
	return new RemoveStructuralFeatureValueActionImpl();
}
RemoveVariableValueAction* UmlFactoryImpl::createRemoveVariableValueAction () const
{
	return new RemoveVariableValueActionImpl();
}
ReplyAction* UmlFactoryImpl::createReplyAction () const
{
	return new ReplyActionImpl();
}
SendObjectAction* UmlFactoryImpl::createSendObjectAction () const
{
	return new SendObjectActionImpl();
}
SendSignalAction* UmlFactoryImpl::createSendSignalAction () const
{
	return new SendSignalActionImpl();
}
SequenceNode* UmlFactoryImpl::createSequenceNode () const
{
	return new SequenceNodeImpl();
}
Signal* UmlFactoryImpl::createSignal () const
{
	return new SignalImpl();
}
SignalEvent* UmlFactoryImpl::createSignalEvent () const
{
	return new SignalEventImpl();
}
Slot* UmlFactoryImpl::createSlot () const
{
	return new SlotImpl();
}
StartClassifierBehaviorAction* UmlFactoryImpl::createStartClassifierBehaviorAction () const
{
	return new StartClassifierBehaviorActionImpl();
}
StartObjectBehaviorAction* UmlFactoryImpl::createStartObjectBehaviorAction () const
{
	return new StartObjectBehaviorActionImpl();
}
State* UmlFactoryImpl::createState () const
{
	return new StateImpl();
}
StateInvariant* UmlFactoryImpl::createStateInvariant () const
{
	return new StateInvariantImpl();
}
StateMachine* UmlFactoryImpl::createStateMachine () const
{
	return new StateMachineImpl();
}
Stereotype* UmlFactoryImpl::createStereotype () const
{
	return new StereotypeImpl();
}
StringExpression* UmlFactoryImpl::createStringExpression () const
{
	return new StringExpressionImpl();
}
StructuredActivityNode* UmlFactoryImpl::createStructuredActivityNode () const
{
	return new StructuredActivityNodeImpl();
}
Substitution* UmlFactoryImpl::createSubstitution () const
{
	return new SubstitutionImpl();
}
TemplateBinding* UmlFactoryImpl::createTemplateBinding () const
{
	return new TemplateBindingImpl();
}
TemplateParameter* UmlFactoryImpl::createTemplateParameter () const
{
	return new TemplateParameterImpl();
}
TemplateParameterSubstitution* UmlFactoryImpl::createTemplateParameterSubstitution () const
{
	return new TemplateParameterSubstitutionImpl();
}
TemplateSignature* UmlFactoryImpl::createTemplateSignature () const
{
	return new TemplateSignatureImpl();
}
TestIdentityAction* UmlFactoryImpl::createTestIdentityAction () const
{
	return new TestIdentityActionImpl();
}
TimeConstraint* UmlFactoryImpl::createTimeConstraint () const
{
	return new TimeConstraintImpl();
}
TimeEvent* UmlFactoryImpl::createTimeEvent () const
{
	return new TimeEventImpl();
}
TimeExpression* UmlFactoryImpl::createTimeExpression () const
{
	return new TimeExpressionImpl();
}
TimeInterval* UmlFactoryImpl::createTimeInterval () const
{
	return new TimeIntervalImpl();
}
TimeObservation* UmlFactoryImpl::createTimeObservation () const
{
	return new TimeObservationImpl();
}
Transition* UmlFactoryImpl::createTransition () const
{
	return new TransitionImpl();
}
Trigger* UmlFactoryImpl::createTrigger () const
{
	return new TriggerImpl();
}
UnmarshallAction* UmlFactoryImpl::createUnmarshallAction () const
{
	return new UnmarshallActionImpl();
}
Usage* UmlFactoryImpl::createUsage () const
{
	return new UsageImpl();
}
UseCase* UmlFactoryImpl::createUseCase () const
{
	return new UseCaseImpl();
}
ValuePin* UmlFactoryImpl::createValuePin () const
{
	return new ValuePinImpl();
}
ValueSpecificationAction* UmlFactoryImpl::createValueSpecificationAction () const
{
	return new ValueSpecificationActionImpl();
}
Variable* UmlFactoryImpl::createVariable () const
{
	return new VariableImpl();
}

std::shared_ptr<UmlPackage> UmlFactoryImpl::getUmlPackage() const
{
	return UmlPackage::eInstance();
}
