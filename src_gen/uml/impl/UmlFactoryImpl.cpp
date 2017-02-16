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
		case UmlPackage::ABSTRACTION : return dynamic_cast<ecore::EObject*>(createAbstraction());
		case UmlPackage::ACCEPTCALLACTION : return dynamic_cast<ecore::EObject*>(createAcceptCallAction());
		case UmlPackage::ACCEPTEVENTACTION : return dynamic_cast<ecore::EObject*>(createAcceptEventAction());
		case UmlPackage::ACTIONEXECUTIONSPECIFICATION : return dynamic_cast<ecore::EObject*>(createActionExecutionSpecification());
		case UmlPackage::ACTIONINPUTPIN : return dynamic_cast<ecore::EObject*>(createActionInputPin());
		case UmlPackage::ACTIVITY : return dynamic_cast<ecore::EObject*>(createActivity());
		case UmlPackage::ACTIVITYFINALNODE : return dynamic_cast<ecore::EObject*>(createActivityFinalNode());
		case UmlPackage::ACTIVITYPARAMETERNODE : return dynamic_cast<ecore::EObject*>(createActivityParameterNode());
		case UmlPackage::ACTIVITYPARTITION : return dynamic_cast<ecore::EObject*>(createActivityPartition());
		case UmlPackage::ACTOR : return dynamic_cast<ecore::EObject*>(createActor());
		case UmlPackage::ADDSTRUCTURALFEATUREVALUEACTION : return dynamic_cast<ecore::EObject*>(createAddStructuralFeatureValueAction());
		case UmlPackage::ADDVARIABLEVALUEACTION : return dynamic_cast<ecore::EObject*>(createAddVariableValueAction());
		case UmlPackage::ANYRECEIVEEVENT : return dynamic_cast<ecore::EObject*>(createAnyReceiveEvent());
		case UmlPackage::ARTIFACT : return dynamic_cast<ecore::EObject*>(createArtifact());
		case UmlPackage::ASSOCIATION : return dynamic_cast<ecore::EObject*>(createAssociation());
		case UmlPackage::ASSOCIATIONCLASS : return dynamic_cast<ecore::EObject*>(createAssociationClass());
		case UmlPackage::BEHAVIOREXECUTIONSPECIFICATION : return dynamic_cast<ecore::EObject*>(createBehaviorExecutionSpecification());
		case UmlPackage::BROADCASTSIGNALACTION : return dynamic_cast<ecore::EObject*>(createBroadcastSignalAction());
		case UmlPackage::CALLBEHAVIORACTION : return dynamic_cast<ecore::EObject*>(createCallBehaviorAction());
		case UmlPackage::CALLEVENT : return dynamic_cast<ecore::EObject*>(createCallEvent());
		case UmlPackage::CALLOPERATIONACTION : return dynamic_cast<ecore::EObject*>(createCallOperationAction());
		case UmlPackage::CENTRALBUFFERNODE : return dynamic_cast<ecore::EObject*>(createCentralBufferNode());
		case UmlPackage::CHANGEEVENT : return dynamic_cast<ecore::EObject*>(createChangeEvent());
		case UmlPackage::CLASS : return dynamic_cast<ecore::EObject*>(createClass());
		case UmlPackage::CLASSIFIERTEMPLATEPARAMETER : return dynamic_cast<ecore::EObject*>(createClassifierTemplateParameter());
		case UmlPackage::CLAUSE : return dynamic_cast<ecore::EObject*>(createClause());
		case UmlPackage::CLEARASSOCIATIONACTION : return dynamic_cast<ecore::EObject*>(createClearAssociationAction());
		case UmlPackage::CLEARSTRUCTURALFEATUREACTION : return dynamic_cast<ecore::EObject*>(createClearStructuralFeatureAction());
		case UmlPackage::CLEARVARIABLEACTION : return dynamic_cast<ecore::EObject*>(createClearVariableAction());
		case UmlPackage::COLLABORATION : return dynamic_cast<ecore::EObject*>(createCollaboration());
		case UmlPackage::COLLABORATIONUSE : return dynamic_cast<ecore::EObject*>(createCollaborationUse());
		case UmlPackage::COMBINEDFRAGMENT : return dynamic_cast<ecore::EObject*>(createCombinedFragment());
		case UmlPackage::COMMENT : return dynamic_cast<ecore::EObject*>(createComment());
		case UmlPackage::COMMUNICATIONPATH : return dynamic_cast<ecore::EObject*>(createCommunicationPath());
		case UmlPackage::COMPONENT : return dynamic_cast<ecore::EObject*>(createComponent());
		case UmlPackage::COMPONENTREALIZATION : return dynamic_cast<ecore::EObject*>(createComponentRealization());
		case UmlPackage::CONDITIONALNODE : return dynamic_cast<ecore::EObject*>(createConditionalNode());
		case UmlPackage::CONNECTABLEELEMENTTEMPLATEPARAMETER : return dynamic_cast<ecore::EObject*>(createConnectableElementTemplateParameter());
		case UmlPackage::CONNECTIONPOINTREFERENCE : return dynamic_cast<ecore::EObject*>(createConnectionPointReference());
		case UmlPackage::CONNECTOR : return dynamic_cast<ecore::EObject*>(createConnector());
		case UmlPackage::CONNECTOREND : return dynamic_cast<ecore::EObject*>(createConnectorEnd());
		case UmlPackage::CONSIDERIGNOREFRAGMENT : return dynamic_cast<ecore::EObject*>(createConsiderIgnoreFragment());
		case UmlPackage::CONSTRAINT : return dynamic_cast<ecore::EObject*>(createConstraint());
		case UmlPackage::CONTINUATION : return dynamic_cast<ecore::EObject*>(createContinuation());
		case UmlPackage::CONTROLFLOW : return dynamic_cast<ecore::EObject*>(createControlFlow());
		case UmlPackage::CREATELINKACTION : return dynamic_cast<ecore::EObject*>(createCreateLinkAction());
		case UmlPackage::CREATELINKOBJECTACTION : return dynamic_cast<ecore::EObject*>(createCreateLinkObjectAction());
		case UmlPackage::CREATEOBJECTACTION : return dynamic_cast<ecore::EObject*>(createCreateObjectAction());
		case UmlPackage::DATASTORENODE : return dynamic_cast<ecore::EObject*>(createDataStoreNode());
		case UmlPackage::DATATYPE : return dynamic_cast<ecore::EObject*>(createDataType());
		case UmlPackage::DECISIONNODE : return dynamic_cast<ecore::EObject*>(createDecisionNode());
		case UmlPackage::DEPENDENCY : return dynamic_cast<ecore::EObject*>(createDependency());
		case UmlPackage::DEPLOYMENT : return dynamic_cast<ecore::EObject*>(createDeployment());
		case UmlPackage::DEPLOYMENTSPECIFICATION : return dynamic_cast<ecore::EObject*>(createDeploymentSpecification());
		case UmlPackage::DESTROYLINKACTION : return dynamic_cast<ecore::EObject*>(createDestroyLinkAction());
		case UmlPackage::DESTROYOBJECTACTION : return dynamic_cast<ecore::EObject*>(createDestroyObjectAction());
		case UmlPackage::DESTRUCTIONOCCURRENCESPECIFICATION : return dynamic_cast<ecore::EObject*>(createDestructionOccurrenceSpecification());
		case UmlPackage::DEVICE : return dynamic_cast<ecore::EObject*>(createDevice());
		case UmlPackage::DURATION : return dynamic_cast<ecore::EObject*>(createDuration());
		case UmlPackage::DURATIONCONSTRAINT : return dynamic_cast<ecore::EObject*>(createDurationConstraint());
		case UmlPackage::DURATIONINTERVAL : return dynamic_cast<ecore::EObject*>(createDurationInterval());
		case UmlPackage::DURATIONOBSERVATION : return dynamic_cast<ecore::EObject*>(createDurationObservation());
		case UmlPackage::ELEMENTIMPORT : return dynamic_cast<ecore::EObject*>(createElementImport());
		case UmlPackage::ENUMERATION : return dynamic_cast<ecore::EObject*>(createEnumeration());
		case UmlPackage::ENUMERATIONLITERAL : return dynamic_cast<ecore::EObject*>(createEnumerationLiteral());
		case UmlPackage::EXCEPTIONHANDLER : return dynamic_cast<ecore::EObject*>(createExceptionHandler());
		case UmlPackage::EXECUTIONENVIRONMENT : return dynamic_cast<ecore::EObject*>(createExecutionEnvironment());
		case UmlPackage::EXECUTIONOCCURRENCESPECIFICATION : return dynamic_cast<ecore::EObject*>(createExecutionOccurrenceSpecification());
		case UmlPackage::EXPANSIONNODE : return dynamic_cast<ecore::EObject*>(createExpansionNode());
		case UmlPackage::EXPANSIONREGION : return dynamic_cast<ecore::EObject*>(createExpansionRegion());
		case UmlPackage::EXPRESSION : return dynamic_cast<ecore::EObject*>(createExpression());
		case UmlPackage::EXTEND : return dynamic_cast<ecore::EObject*>(createExtend());
		case UmlPackage::EXTENSION : return dynamic_cast<ecore::EObject*>(createExtension());
		case UmlPackage::EXTENSIONEND : return dynamic_cast<ecore::EObject*>(createExtensionEnd());
		case UmlPackage::EXTENSIONPOINT : return dynamic_cast<ecore::EObject*>(createExtensionPoint());
		case UmlPackage::FACTORY : return dynamic_cast<ecore::EObject*>(createFactory());
		case UmlPackage::FINALSTATE : return dynamic_cast<ecore::EObject*>(createFinalState());
		case UmlPackage::FLOWFINALNODE : return dynamic_cast<ecore::EObject*>(createFlowFinalNode());
		case UmlPackage::FORKNODE : return dynamic_cast<ecore::EObject*>(createForkNode());
		case UmlPackage::FUNCTIONBEHAVIOR : return dynamic_cast<ecore::EObject*>(createFunctionBehavior());
		case UmlPackage::GATE : return dynamic_cast<ecore::EObject*>(createGate());
		case UmlPackage::GENERALORDERING : return dynamic_cast<ecore::EObject*>(createGeneralOrdering());
		case UmlPackage::GENERALIZATION : return dynamic_cast<ecore::EObject*>(createGeneralization());
		case UmlPackage::GENERALIZATIONSET : return dynamic_cast<ecore::EObject*>(createGeneralizationSet());
		case UmlPackage::IMAGE : return dynamic_cast<ecore::EObject*>(createImage());
		case UmlPackage::INCLUDE : return dynamic_cast<ecore::EObject*>(createInclude());
		case UmlPackage::INFORMATIONFLOW : return dynamic_cast<ecore::EObject*>(createInformationFlow());
		case UmlPackage::INFORMATIONITEM : return dynamic_cast<ecore::EObject*>(createInformationItem());
		case UmlPackage::INITIALNODE : return dynamic_cast<ecore::EObject*>(createInitialNode());
		case UmlPackage::INPUTPIN : return dynamic_cast<ecore::EObject*>(createInputPin());
		case UmlPackage::INSTANCESPECIFICATION : return dynamic_cast<ecore::EObject*>(createInstanceSpecification());
		case UmlPackage::INSTANCEVALUE : return dynamic_cast<ecore::EObject*>(createInstanceValue());
		case UmlPackage::INTERACTION : return dynamic_cast<ecore::EObject*>(createInteraction());
		case UmlPackage::INTERACTIONCONSTRAINT : return dynamic_cast<ecore::EObject*>(createInteractionConstraint());
		case UmlPackage::INTERACTIONOPERAND : return dynamic_cast<ecore::EObject*>(createInteractionOperand());
		case UmlPackage::INTERACTIONUSE : return dynamic_cast<ecore::EObject*>(createInteractionUse());
		case UmlPackage::INTERFACE : return dynamic_cast<ecore::EObject*>(createInterface());
		case UmlPackage::INTERFACEREALIZATION : return dynamic_cast<ecore::EObject*>(createInterfaceRealization());
		case UmlPackage::INTERRUPTIBLEACTIVITYREGION : return dynamic_cast<ecore::EObject*>(createInterruptibleActivityRegion());
		case UmlPackage::INTERVAL : return dynamic_cast<ecore::EObject*>(createInterval());
		case UmlPackage::INTERVALCONSTRAINT : return dynamic_cast<ecore::EObject*>(createIntervalConstraint());
		case UmlPackage::JOINNODE : return dynamic_cast<ecore::EObject*>(createJoinNode());
		case UmlPackage::LIFELINE : return dynamic_cast<ecore::EObject*>(createLifeline());
		case UmlPackage::LINKENDCREATIONDATA : return dynamic_cast<ecore::EObject*>(createLinkEndCreationData());
		case UmlPackage::LINKENDDATA : return dynamic_cast<ecore::EObject*>(createLinkEndData());
		case UmlPackage::LINKENDDESTRUCTIONDATA : return dynamic_cast<ecore::EObject*>(createLinkEndDestructionData());
		case UmlPackage::LITERALBOOLEAN : return dynamic_cast<ecore::EObject*>(createLiteralBoolean());
		case UmlPackage::LITERALINTEGER : return dynamic_cast<ecore::EObject*>(createLiteralInteger());
		case UmlPackage::LITERALNULL : return dynamic_cast<ecore::EObject*>(createLiteralNull());
		case UmlPackage::LITERALREAL : return dynamic_cast<ecore::EObject*>(createLiteralReal());
		case UmlPackage::LITERALSTRING : return dynamic_cast<ecore::EObject*>(createLiteralString());
		case UmlPackage::LITERALUNLIMITEDNATURAL : return dynamic_cast<ecore::EObject*>(createLiteralUnlimitedNatural());
		case UmlPackage::LOOPNODE : return dynamic_cast<ecore::EObject*>(createLoopNode());
		case UmlPackage::MANIFESTATION : return dynamic_cast<ecore::EObject*>(createManifestation());
		case UmlPackage::MERGENODE : return dynamic_cast<ecore::EObject*>(createMergeNode());
		case UmlPackage::MESSAGE : return dynamic_cast<ecore::EObject*>(createMessage());
		case UmlPackage::MESSAGEOCCURRENCESPECIFICATION : return dynamic_cast<ecore::EObject*>(createMessageOccurrenceSpecification());
		case UmlPackage::MODEL : return dynamic_cast<ecore::EObject*>(createModel());
		case UmlPackage::NODE : return dynamic_cast<ecore::EObject*>(createNode());
		case UmlPackage::OBJECT : return dynamic_cast<ecore::EObject*>(createObject());
		case UmlPackage::OBJECTFLOW : return dynamic_cast<ecore::EObject*>(createObjectFlow());
		case UmlPackage::OCCURRENCESPECIFICATION : return dynamic_cast<ecore::EObject*>(createOccurrenceSpecification());
		case UmlPackage::OPAQUEACTION : return dynamic_cast<ecore::EObject*>(createOpaqueAction());
		case UmlPackage::OPAQUEBEHAVIOR : return dynamic_cast<ecore::EObject*>(createOpaqueBehavior());
		case UmlPackage::OPAQUEEXPRESSION : return dynamic_cast<ecore::EObject*>(createOpaqueExpression());
		case UmlPackage::OPERATION : return dynamic_cast<ecore::EObject*>(createOperation());
		case UmlPackage::OPERATIONTEMPLATEPARAMETER : return dynamic_cast<ecore::EObject*>(createOperationTemplateParameter());
		case UmlPackage::OUTPUTPIN : return dynamic_cast<ecore::EObject*>(createOutputPin());
		case UmlPackage::PACKAGE : return dynamic_cast<ecore::EObject*>(createPackage());
		case UmlPackage::PACKAGEIMPORT : return dynamic_cast<ecore::EObject*>(createPackageImport());
		case UmlPackage::PACKAGEMERGE : return dynamic_cast<ecore::EObject*>(createPackageMerge());
		case UmlPackage::PARAMETER : return dynamic_cast<ecore::EObject*>(createParameter());
		case UmlPackage::PARAMETERSET : return dynamic_cast<ecore::EObject*>(createParameterSet());
		case UmlPackage::PARTDECOMPOSITION : return dynamic_cast<ecore::EObject*>(createPartDecomposition());
		case UmlPackage::PORT : return dynamic_cast<ecore::EObject*>(createPort());
		case UmlPackage::PRIMITIVETYPE : return dynamic_cast<ecore::EObject*>(createPrimitiveType());
		case UmlPackage::PROFILE : return dynamic_cast<ecore::EObject*>(createProfile());
		case UmlPackage::PROFILEAPPLICATION : return dynamic_cast<ecore::EObject*>(createProfileApplication());
		case UmlPackage::PROPERTY : return dynamic_cast<ecore::EObject*>(createProperty());
		case UmlPackage::PROTOCOLCONFORMANCE : return dynamic_cast<ecore::EObject*>(createProtocolConformance());
		case UmlPackage::PROTOCOLSTATEMACHINE : return dynamic_cast<ecore::EObject*>(createProtocolStateMachine());
		case UmlPackage::PROTOCOLTRANSITION : return dynamic_cast<ecore::EObject*>(createProtocolTransition());
		case UmlPackage::PSEUDOSTATE : return dynamic_cast<ecore::EObject*>(createPseudostate());
		case UmlPackage::QUALIFIERVALUE : return dynamic_cast<ecore::EObject*>(createQualifierValue());
		case UmlPackage::RAISEEXCEPTIONACTION : return dynamic_cast<ecore::EObject*>(createRaiseExceptionAction());
		case UmlPackage::READEXTENTACTION : return dynamic_cast<ecore::EObject*>(createReadExtentAction());
		case UmlPackage::READISCLASSIFIEDOBJECTACTION : return dynamic_cast<ecore::EObject*>(createReadIsClassifiedObjectAction());
		case UmlPackage::READLINKACTION : return dynamic_cast<ecore::EObject*>(createReadLinkAction());
		case UmlPackage::READLINKOBJECTENDACTION : return dynamic_cast<ecore::EObject*>(createReadLinkObjectEndAction());
		case UmlPackage::READLINKOBJECTENDQUALIFIERACTION : return dynamic_cast<ecore::EObject*>(createReadLinkObjectEndQualifierAction());
		case UmlPackage::READSELFACTION : return dynamic_cast<ecore::EObject*>(createReadSelfAction());
		case UmlPackage::READSTRUCTURALFEATUREACTION : return dynamic_cast<ecore::EObject*>(createReadStructuralFeatureAction());
		case UmlPackage::READVARIABLEACTION : return dynamic_cast<ecore::EObject*>(createReadVariableAction());
		case UmlPackage::REALIZATION : return dynamic_cast<ecore::EObject*>(createRealization());
		case UmlPackage::RECEPTION : return dynamic_cast<ecore::EObject*>(createReception());
		case UmlPackage::RECLASSIFYOBJECTACTION : return dynamic_cast<ecore::EObject*>(createReclassifyObjectAction());
		case UmlPackage::REDEFINABLETEMPLATESIGNATURE : return dynamic_cast<ecore::EObject*>(createRedefinableTemplateSignature());
		case UmlPackage::REDUCEACTION : return dynamic_cast<ecore::EObject*>(createReduceAction());
		case UmlPackage::REGION : return dynamic_cast<ecore::EObject*>(createRegion());
		case UmlPackage::REMOVESTRUCTURALFEATUREVALUEACTION : return dynamic_cast<ecore::EObject*>(createRemoveStructuralFeatureValueAction());
		case UmlPackage::REMOVEVARIABLEVALUEACTION : return dynamic_cast<ecore::EObject*>(createRemoveVariableValueAction());
		case UmlPackage::REPLYACTION : return dynamic_cast<ecore::EObject*>(createReplyAction());
		case UmlPackage::SENDOBJECTACTION : return dynamic_cast<ecore::EObject*>(createSendObjectAction());
		case UmlPackage::SENDSIGNALACTION : return dynamic_cast<ecore::EObject*>(createSendSignalAction());
		case UmlPackage::SEQUENCENODE : return dynamic_cast<ecore::EObject*>(createSequenceNode());
		case UmlPackage::SIGNAL : return dynamic_cast<ecore::EObject*>(createSignal());
		case UmlPackage::SIGNALEVENT : return dynamic_cast<ecore::EObject*>(createSignalEvent());
		case UmlPackage::SLOT : return dynamic_cast<ecore::EObject*>(createSlot());
		case UmlPackage::STARTCLASSIFIERBEHAVIORACTION : return dynamic_cast<ecore::EObject*>(createStartClassifierBehaviorAction());
		case UmlPackage::STARTOBJECTBEHAVIORACTION : return dynamic_cast<ecore::EObject*>(createStartObjectBehaviorAction());
		case UmlPackage::STATE : return dynamic_cast<ecore::EObject*>(createState());
		case UmlPackage::STATEINVARIANT : return dynamic_cast<ecore::EObject*>(createStateInvariant());
		case UmlPackage::STATEMACHINE : return dynamic_cast<ecore::EObject*>(createStateMachine());
		case UmlPackage::STEREOTYPE : return dynamic_cast<ecore::EObject*>(createStereotype());
		case UmlPackage::STRINGEXPRESSION : return dynamic_cast<ecore::EObject*>(createStringExpression());
		case UmlPackage::STRUCTUREDACTIVITYNODE : return dynamic_cast<ecore::EObject*>(createStructuredActivityNode());
		case UmlPackage::SUBSTITUTION : return dynamic_cast<ecore::EObject*>(createSubstitution());
		case UmlPackage::TEMPLATEBINDING : return dynamic_cast<ecore::EObject*>(createTemplateBinding());
		case UmlPackage::TEMPLATEPARAMETER : return dynamic_cast<ecore::EObject*>(createTemplateParameter());
		case UmlPackage::TEMPLATEPARAMETERSUBSTITUTION : return dynamic_cast<ecore::EObject*>(createTemplateParameterSubstitution());
		case UmlPackage::TEMPLATESIGNATURE : return dynamic_cast<ecore::EObject*>(createTemplateSignature());
		case UmlPackage::TESTIDENTITYACTION : return dynamic_cast<ecore::EObject*>(createTestIdentityAction());
		case UmlPackage::TIMECONSTRAINT : return dynamic_cast<ecore::EObject*>(createTimeConstraint());
		case UmlPackage::TIMEEVENT : return dynamic_cast<ecore::EObject*>(createTimeEvent());
		case UmlPackage::TIMEEXPRESSION : return dynamic_cast<ecore::EObject*>(createTimeExpression());
		case UmlPackage::TIMEINTERVAL : return dynamic_cast<ecore::EObject*>(createTimeInterval());
		case UmlPackage::TIMEOBSERVATION : return dynamic_cast<ecore::EObject*>(createTimeObservation());
		case UmlPackage::TRANSITION : return dynamic_cast<ecore::EObject*>(createTransition());
		case UmlPackage::TRIGGER : return dynamic_cast<ecore::EObject*>(createTrigger());
		case UmlPackage::UNMARSHALLACTION : return dynamic_cast<ecore::EObject*>(createUnmarshallAction());
		case UmlPackage::USAGE : return dynamic_cast<ecore::EObject*>(createUsage());
		case UmlPackage::USECASE : return dynamic_cast<ecore::EObject*>(createUseCase());
		case UmlPackage::VALUEPIN : return dynamic_cast<ecore::EObject*>(createValuePin());
		case UmlPackage::VALUESPECIFICATIONACTION : return dynamic_cast<ecore::EObject*>(createValueSpecificationAction());
		case UmlPackage::VARIABLE : return dynamic_cast<ecore::EObject*>(createVariable());
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

UmlPackage * UmlFactoryImpl::getUmlPackage() const
{
	return UmlPackage::eInstance();
}
