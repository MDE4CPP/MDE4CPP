#include "UmlFactoryImpl.hpp"
#include "UmlPackage.hpp"

#include "EClass.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************

UmlFactoryImpl::UmlFactoryImpl()
{
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Abstraction",[this](){return this->createAbstraction();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("AcceptCallAction",[this](){return this->createAcceptCallAction();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("AcceptEventAction",[this](){return this->createAcceptEventAction();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ActionExecutionSpecification",[this](){return this->createActionExecutionSpecification();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ActionInputPin",[this](){return this->createActionInputPin();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Activity",[this](){return this->createActivity();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ActivityFinalNode",[this](){return this->createActivityFinalNode();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ActivityParameterNode",[this](){return this->createActivityParameterNode();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ActivityPartition",[this](){return this->createActivityPartition();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Actor",[this](){return this->createActor();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("AddStructuralFeatureValueAction",[this](){return this->createAddStructuralFeatureValueAction();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("AddVariableValueAction",[this](){return this->createAddVariableValueAction();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("AnyReceiveEvent",[this](){return this->createAnyReceiveEvent();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Artifact",[this](){return this->createArtifact();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Association",[this](){return this->createAssociation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("AssociationClass",[this](){return this->createAssociationClass();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("BehaviorExecutionSpecification",[this](){return this->createBehaviorExecutionSpecification();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("BroadcastSignalAction",[this](){return this->createBroadcastSignalAction();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("CallBehaviorAction",[this](){return this->createCallBehaviorAction();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("CallEvent",[this](){return this->createCallEvent();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("CallOperationAction",[this](){return this->createCallOperationAction();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("CentralBufferNode",[this](){return this->createCentralBufferNode();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ChangeEvent",[this](){return this->createChangeEvent();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Class",[this](){return this->createClass();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ClassifierTemplateParameter",[this](){return this->createClassifierTemplateParameter();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Clause",[this](){return this->createClause();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ClearAssociationAction",[this](){return this->createClearAssociationAction();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ClearStructuralFeatureAction",[this](){return this->createClearStructuralFeatureAction();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ClearVariableAction",[this](){return this->createClearVariableAction();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Collaboration",[this](){return this->createCollaboration();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("CollaborationUse",[this](){return this->createCollaborationUse();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("CombinedFragment",[this](){return this->createCombinedFragment();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Comment",[this](){return this->createComment();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("CommunicationPath",[this](){return this->createCommunicationPath();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Component",[this](){return this->createComponent();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ComponentRealization",[this](){return this->createComponentRealization();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ConditionalNode",[this](){return this->createConditionalNode();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ConnectableElementTemplateParameter",[this](){return this->createConnectableElementTemplateParameter();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ConnectionPointReference",[this](){return this->createConnectionPointReference();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Connector",[this](){return this->createConnector();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ConnectorEnd",[this](){return this->createConnectorEnd();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ConsiderIgnoreFragment",[this](){return this->createConsiderIgnoreFragment();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Constraint",[this](){return this->createConstraint();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Continuation",[this](){return this->createContinuation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ControlFlow",[this](){return this->createControlFlow();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("CreateLinkAction",[this](){return this->createCreateLinkAction();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("CreateLinkObjectAction",[this](){return this->createCreateLinkObjectAction();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("CreateObjectAction",[this](){return this->createCreateObjectAction();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("DataStoreNode",[this](){return this->createDataStoreNode();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("DataType",[this](){return this->createDataType();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("DecisionNode",[this](){return this->createDecisionNode();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Dependency",[this](){return this->createDependency();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Deployment",[this](){return this->createDeployment();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("DeploymentSpecification",[this](){return this->createDeploymentSpecification();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("DestroyLinkAction",[this](){return this->createDestroyLinkAction();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("DestroyObjectAction",[this](){return this->createDestroyObjectAction();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("DestructionOccurrenceSpecification",[this](){return this->createDestructionOccurrenceSpecification();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Device",[this](){return this->createDevice();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Duration",[this](){return this->createDuration();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("DurationConstraint",[this](){return this->createDurationConstraint();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("DurationInterval",[this](){return this->createDurationInterval();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("DurationObservation",[this](){return this->createDurationObservation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ElementImport",[this](){return this->createElementImport();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Enumeration",[this](){return this->createEnumeration();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("EnumerationLiteral",[this](){return this->createEnumerationLiteral();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ExceptionHandler",[this](){return this->createExceptionHandler();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ExecutionEnvironment",[this](){return this->createExecutionEnvironment();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ExecutionOccurrenceSpecification",[this](){return this->createExecutionOccurrenceSpecification();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ExpansionNode",[this](){return this->createExpansionNode();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ExpansionRegion",[this](){return this->createExpansionRegion();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Expression",[this](){return this->createExpression();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Extend",[this](){return this->createExtend();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Extension",[this](){return this->createExtension();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ExtensionEnd",[this](){return this->createExtensionEnd();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ExtensionPoint",[this](){return this->createExtensionPoint();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Factory",[this](){return this->createFactory();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("FinalState",[this](){return this->createFinalState();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("FlowFinalNode",[this](){return this->createFlowFinalNode();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ForkNode",[this](){return this->createForkNode();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("FunctionBehavior",[this](){return this->createFunctionBehavior();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Gate",[this](){return this->createGate();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("GeneralOrdering",[this](){return this->createGeneralOrdering();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Generalization",[this](){return this->createGeneralization();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("GeneralizationSet",[this](){return this->createGeneralizationSet();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Image",[this](){return this->createImage();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Include",[this](){return this->createInclude();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("InformationFlow",[this](){return this->createInformationFlow();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("InformationItem",[this](){return this->createInformationItem();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("InitialNode",[this](){return this->createInitialNode();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("InputPin",[this](){return this->createInputPin();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("InstanceSpecification",[this](){return this->createInstanceSpecification();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("InstanceValue",[this](){return this->createInstanceValue();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Interaction",[this](){return this->createInteraction();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("InteractionConstraint",[this](){return this->createInteractionConstraint();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("InteractionOperand",[this](){return this->createInteractionOperand();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("InteractionUse",[this](){return this->createInteractionUse();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Interface",[this](){return this->createInterface();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("InterfaceRealization",[this](){return this->createInterfaceRealization();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("InterruptibleActivityRegion",[this](){return this->createInterruptibleActivityRegion();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Interval",[this](){return this->createInterval();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("IntervalConstraint",[this](){return this->createIntervalConstraint();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("JoinNode",[this](){return this->createJoinNode();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Lifeline",[this](){return this->createLifeline();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("LinkEndCreationData",[this](){return this->createLinkEndCreationData();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("LinkEndData",[this](){return this->createLinkEndData();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("LinkEndDestructionData",[this](){return this->createLinkEndDestructionData();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("LiteralBoolean",[this](){return this->createLiteralBoolean();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("LiteralInteger",[this](){return this->createLiteralInteger();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("LiteralNull",[this](){return this->createLiteralNull();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("LiteralReal",[this](){return this->createLiteralReal();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("LiteralString",[this](){return this->createLiteralString();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("LiteralUnlimitedNatural",[this](){return this->createLiteralUnlimitedNatural();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("LoopNode",[this](){return this->createLoopNode();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Manifestation",[this](){return this->createManifestation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("MergeNode",[this](){return this->createMergeNode();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Message",[this](){return this->createMessage();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("MessageOccurrenceSpecification",[this](){return this->createMessageOccurrenceSpecification();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Model",[this](){return this->createModel();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Node",[this](){return this->createNode();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Object",[this](){return this->createObject();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ObjectFlow",[this](){return this->createObjectFlow();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("OccurrenceSpecification",[this](){return this->createOccurrenceSpecification();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("OpaqueAction",[this](){return this->createOpaqueAction();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("OpaqueBehavior",[this](){return this->createOpaqueBehavior();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("OpaqueExpression",[this](){return this->createOpaqueExpression();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Operation",[this](){return this->createOperation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("OperationTemplateParameter",[this](){return this->createOperationTemplateParameter();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("OutputPin",[this](){return this->createOutputPin();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Package",[this](){return this->createPackage();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("PackageImport",[this](){return this->createPackageImport();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("PackageMerge",[this](){return this->createPackageMerge();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Parameter",[this](){return this->createParameter();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ParameterSet",[this](){return this->createParameterSet();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("PartDecomposition",[this](){return this->createPartDecomposition();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Port",[this](){return this->createPort();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("PrimitiveType",[this](){return this->createPrimitiveType();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Profile",[this](){return this->createProfile();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ProfileApplication",[this](){return this->createProfileApplication();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Property",[this](){return this->createProperty();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ProtocolConformance",[this](){return this->createProtocolConformance();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ProtocolStateMachine",[this](){return this->createProtocolStateMachine();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ProtocolTransition",[this](){return this->createProtocolTransition();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Pseudostate",[this](){return this->createPseudostate();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("QualifierValue",[this](){return this->createQualifierValue();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("RaiseExceptionAction",[this](){return this->createRaiseExceptionAction();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ReadExtentAction",[this](){return this->createReadExtentAction();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ReadIsClassifiedObjectAction",[this](){return this->createReadIsClassifiedObjectAction();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ReadLinkAction",[this](){return this->createReadLinkAction();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ReadLinkObjectEndAction",[this](){return this->createReadLinkObjectEndAction();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ReadLinkObjectEndQualifierAction",[this](){return this->createReadLinkObjectEndQualifierAction();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ReadSelfAction",[this](){return this->createReadSelfAction();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ReadStructuralFeatureAction",[this](){return this->createReadStructuralFeatureAction();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ReadVariableAction",[this](){return this->createReadVariableAction();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Realization",[this](){return this->createRealization();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Reception",[this](){return this->createReception();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ReclassifyObjectAction",[this](){return this->createReclassifyObjectAction();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("RedefinableTemplateSignature",[this](){return this->createRedefinableTemplateSignature();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ReduceAction",[this](){return this->createReduceAction();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Region",[this](){return this->createRegion();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("RemoveStructuralFeatureValueAction",[this](){return this->createRemoveStructuralFeatureValueAction();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("RemoveVariableValueAction",[this](){return this->createRemoveVariableValueAction();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ReplyAction",[this](){return this->createReplyAction();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("SendObjectAction",[this](){return this->createSendObjectAction();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("SendSignalAction",[this](){return this->createSendSignalAction();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("SequenceNode",[this](){return this->createSequenceNode();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Signal",[this](){return this->createSignal();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("SignalEvent",[this](){return this->createSignalEvent();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Slot",[this](){return this->createSlot();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("StartClassifierBehaviorAction",[this](){return this->createStartClassifierBehaviorAction();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("StartObjectBehaviorAction",[this](){return this->createStartObjectBehaviorAction();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("State",[this](){return this->createState();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("StateInvariant",[this](){return this->createStateInvariant();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("StateMachine",[this](){return this->createStateMachine();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Stereotype",[this](){return this->createStereotype();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("StringExpression",[this](){return this->createStringExpression();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("StructuredActivityNode",[this](){return this->createStructuredActivityNode();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Substitution",[this](){return this->createSubstitution();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("TemplateBinding",[this](){return this->createTemplateBinding();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("TemplateParameter",[this](){return this->createTemplateParameter();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("TemplateParameterSubstitution",[this](){return this->createTemplateParameterSubstitution();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("TemplateSignature",[this](){return this->createTemplateSignature();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("TestIdentityAction",[this](){return this->createTestIdentityAction();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("TimeConstraint",[this](){return this->createTimeConstraint();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("TimeEvent",[this](){return this->createTimeEvent();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("TimeExpression",[this](){return this->createTimeExpression();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("TimeInterval",[this](){return this->createTimeInterval();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("TimeObservation",[this](){return this->createTimeObservation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Transition",[this](){return this->createTransition();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Trigger",[this](){return this->createTrigger();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("UnmarshallAction",[this](){return this->createUnmarshallAction();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Usage",[this](){return this->createUsage();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("UseCase",[this](){return this->createUseCase();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ValuePin",[this](){return this->createValuePin();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ValueSpecificationAction",[this](){return this->createValueSpecificationAction();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Variable",[this](){return this->createVariable();}));
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

std::shared_ptr<ecore::EObject> UmlFactoryImpl::create(ecore::EClass* _class) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}

	std::string _className = _class->eClass()->getName();
	return create(_className);
}

std::shared_ptr<ecore::EObject> UmlFactoryImpl::create(std::string _className) const
{
	//TODO: still two times run through map
	std::map<std::string,std::function<ecore::EObject*()>>::const_iterator iter = m_creatorMap.find(_className);
	
	std::shared_ptr<ecore::EObject> _createdObject;
	if(iter != m_creatorMap.end())
    {
		//invoke the creator function
        return std::shared_ptr<ecore::EObject>(iter->second());
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
