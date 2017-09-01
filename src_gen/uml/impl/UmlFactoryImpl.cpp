#include "UmlFactoryImpl.hpp"
#include "UmlPackage.hpp"

#include "EClass.hpp"

#include "impl/ElementImpl.hpp"
using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************

UmlFactoryImpl::UmlFactoryImpl()
{
	m_idMap.insert(std::pair<std::string,unsigned int>("Abstraction", UmlPackage::ABSTRACTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("AcceptCallAction", UmlPackage::ACCEPTCALLACTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("AcceptEventAction", UmlPackage::ACCEPTEVENTACTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("ActionExecutionSpecification", UmlPackage::ACTIONEXECUTIONSPECIFICATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("ActionInputPin", UmlPackage::ACTIONINPUTPIN));
	m_idMap.insert(std::pair<std::string,unsigned int>("Activity", UmlPackage::ACTIVITY));
	m_idMap.insert(std::pair<std::string,unsigned int>("ActivityFinalNode", UmlPackage::ACTIVITYFINALNODE));
	m_idMap.insert(std::pair<std::string,unsigned int>("ActivityParameterNode", UmlPackage::ACTIVITYPARAMETERNODE));
	m_idMap.insert(std::pair<std::string,unsigned int>("ActivityPartition", UmlPackage::ACTIVITYPARTITION));
	m_idMap.insert(std::pair<std::string,unsigned int>("Actor", UmlPackage::ACTOR));
	m_idMap.insert(std::pair<std::string,unsigned int>("AddStructuralFeatureValueAction", UmlPackage::ADDSTRUCTURALFEATUREVALUEACTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("AddVariableValueAction", UmlPackage::ADDVARIABLEVALUEACTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("AnyReceiveEvent", UmlPackage::ANYRECEIVEEVENT));
	m_idMap.insert(std::pair<std::string,unsigned int>("Artifact", UmlPackage::ARTIFACT));
	m_idMap.insert(std::pair<std::string,unsigned int>("Association", UmlPackage::ASSOCIATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("AssociationClass", UmlPackage::ASSOCIATIONCLASS));
	m_idMap.insert(std::pair<std::string,unsigned int>("BehaviorExecutionSpecification", UmlPackage::BEHAVIOREXECUTIONSPECIFICATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("BroadcastSignalAction", UmlPackage::BROADCASTSIGNALACTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("CallBehaviorAction", UmlPackage::CALLBEHAVIORACTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("CallEvent", UmlPackage::CALLEVENT));
	m_idMap.insert(std::pair<std::string,unsigned int>("CallOperationAction", UmlPackage::CALLOPERATIONACTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("CentralBufferNode", UmlPackage::CENTRALBUFFERNODE));
	m_idMap.insert(std::pair<std::string,unsigned int>("ChangeEvent", UmlPackage::CHANGEEVENT));
	m_idMap.insert(std::pair<std::string,unsigned int>("Class", UmlPackage::CLASS));
	m_idMap.insert(std::pair<std::string,unsigned int>("ClassifierTemplateParameter", UmlPackage::CLASSIFIERTEMPLATEPARAMETER));
	m_idMap.insert(std::pair<std::string,unsigned int>("Clause", UmlPackage::CLAUSE));
	m_idMap.insert(std::pair<std::string,unsigned int>("ClearAssociationAction", UmlPackage::CLEARASSOCIATIONACTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("ClearStructuralFeatureAction", UmlPackage::CLEARSTRUCTURALFEATUREACTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("ClearVariableAction", UmlPackage::CLEARVARIABLEACTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("Collaboration", UmlPackage::COLLABORATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("CollaborationUse", UmlPackage::COLLABORATIONUSE));
	m_idMap.insert(std::pair<std::string,unsigned int>("CombinedFragment", UmlPackage::COMBINEDFRAGMENT));
	m_idMap.insert(std::pair<std::string,unsigned int>("Comment", UmlPackage::COMMENT));
	m_idMap.insert(std::pair<std::string,unsigned int>("CommunicationPath", UmlPackage::COMMUNICATIONPATH));
	m_idMap.insert(std::pair<std::string,unsigned int>("Component", UmlPackage::COMPONENT));
	m_idMap.insert(std::pair<std::string,unsigned int>("ComponentRealization", UmlPackage::COMPONENTREALIZATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("ConditionalNode", UmlPackage::CONDITIONALNODE));
	m_idMap.insert(std::pair<std::string,unsigned int>("ConnectableElementTemplateParameter", UmlPackage::CONNECTABLEELEMENTTEMPLATEPARAMETER));
	m_idMap.insert(std::pair<std::string,unsigned int>("ConnectionPointReference", UmlPackage::CONNECTIONPOINTREFERENCE));
	m_idMap.insert(std::pair<std::string,unsigned int>("Connector", UmlPackage::CONNECTOR));
	m_idMap.insert(std::pair<std::string,unsigned int>("ConnectorEnd", UmlPackage::CONNECTOREND));
	m_idMap.insert(std::pair<std::string,unsigned int>("ConsiderIgnoreFragment", UmlPackage::CONSIDERIGNOREFRAGMENT));
	m_idMap.insert(std::pair<std::string,unsigned int>("Constraint", UmlPackage::CONSTRAINT));
	m_idMap.insert(std::pair<std::string,unsigned int>("Continuation", UmlPackage::CONTINUATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("ControlFlow", UmlPackage::CONTROLFLOW));
	m_idMap.insert(std::pair<std::string,unsigned int>("CreateLinkAction", UmlPackage::CREATELINKACTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("CreateLinkObjectAction", UmlPackage::CREATELINKOBJECTACTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("CreateObjectAction", UmlPackage::CREATEOBJECTACTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("DataStoreNode", UmlPackage::DATASTORENODE));
	m_idMap.insert(std::pair<std::string,unsigned int>("DataType", UmlPackage::DATATYPE));
	m_idMap.insert(std::pair<std::string,unsigned int>("DecisionNode", UmlPackage::DECISIONNODE));
	m_idMap.insert(std::pair<std::string,unsigned int>("Dependency", UmlPackage::DEPENDENCY));
	m_idMap.insert(std::pair<std::string,unsigned int>("Deployment", UmlPackage::DEPLOYMENT));
	m_idMap.insert(std::pair<std::string,unsigned int>("DeploymentSpecification", UmlPackage::DEPLOYMENTSPECIFICATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("DestroyLinkAction", UmlPackage::DESTROYLINKACTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("DestroyObjectAction", UmlPackage::DESTROYOBJECTACTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("DestructionOccurrenceSpecification", UmlPackage::DESTRUCTIONOCCURRENCESPECIFICATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("Device", UmlPackage::DEVICE));
	m_idMap.insert(std::pair<std::string,unsigned int>("Duration", UmlPackage::DURATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("DurationConstraint", UmlPackage::DURATIONCONSTRAINT));
	m_idMap.insert(std::pair<std::string,unsigned int>("DurationInterval", UmlPackage::DURATIONINTERVAL));
	m_idMap.insert(std::pair<std::string,unsigned int>("DurationObservation", UmlPackage::DURATIONOBSERVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("ElementImport", UmlPackage::ELEMENTIMPORT));
	m_idMap.insert(std::pair<std::string,unsigned int>("Enumeration", UmlPackage::ENUMERATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("EnumerationLiteral", UmlPackage::ENUMERATIONLITERAL));
	m_idMap.insert(std::pair<std::string,unsigned int>("ExceptionHandler", UmlPackage::EXCEPTIONHANDLER));
	m_idMap.insert(std::pair<std::string,unsigned int>("ExecutionEnvironment", UmlPackage::EXECUTIONENVIRONMENT));
	m_idMap.insert(std::pair<std::string,unsigned int>("ExecutionOccurrenceSpecification", UmlPackage::EXECUTIONOCCURRENCESPECIFICATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("ExpansionNode", UmlPackage::EXPANSIONNODE));
	m_idMap.insert(std::pair<std::string,unsigned int>("ExpansionRegion", UmlPackage::EXPANSIONREGION));
	m_idMap.insert(std::pair<std::string,unsigned int>("Expression", UmlPackage::EXPRESSION));
	m_idMap.insert(std::pair<std::string,unsigned int>("Extend", UmlPackage::EXTEND));
	m_idMap.insert(std::pair<std::string,unsigned int>("Extension", UmlPackage::EXTENSION));
	m_idMap.insert(std::pair<std::string,unsigned int>("ExtensionEnd", UmlPackage::EXTENSIONEND));
	m_idMap.insert(std::pair<std::string,unsigned int>("ExtensionPoint", UmlPackage::EXTENSIONPOINT));
	m_idMap.insert(std::pair<std::string,unsigned int>("Factory", UmlPackage::FACTORY));
	m_idMap.insert(std::pair<std::string,unsigned int>("FinalState", UmlPackage::FINALSTATE));
	m_idMap.insert(std::pair<std::string,unsigned int>("FlowFinalNode", UmlPackage::FLOWFINALNODE));
	m_idMap.insert(std::pair<std::string,unsigned int>("ForkNode", UmlPackage::FORKNODE));
	m_idMap.insert(std::pair<std::string,unsigned int>("FunctionBehavior", UmlPackage::FUNCTIONBEHAVIOR));
	m_idMap.insert(std::pair<std::string,unsigned int>("Gate", UmlPackage::GATE));
	m_idMap.insert(std::pair<std::string,unsigned int>("GeneralOrdering", UmlPackage::GENERALORDERING));
	m_idMap.insert(std::pair<std::string,unsigned int>("Generalization", UmlPackage::GENERALIZATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("GeneralizationSet", UmlPackage::GENERALIZATIONSET));
	m_idMap.insert(std::pair<std::string,unsigned int>("Image", UmlPackage::IMAGE));
	m_idMap.insert(std::pair<std::string,unsigned int>("Include", UmlPackage::INCLUDE));
	m_idMap.insert(std::pair<std::string,unsigned int>("InformationFlow", UmlPackage::INFORMATIONFLOW));
	m_idMap.insert(std::pair<std::string,unsigned int>("InformationItem", UmlPackage::INFORMATIONITEM));
	m_idMap.insert(std::pair<std::string,unsigned int>("InitialNode", UmlPackage::INITIALNODE));
	m_idMap.insert(std::pair<std::string,unsigned int>("InputPin", UmlPackage::INPUTPIN));
	m_idMap.insert(std::pair<std::string,unsigned int>("InstanceSpecification", UmlPackage::INSTANCESPECIFICATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("InstanceValue", UmlPackage::INSTANCEVALUE));
	m_idMap.insert(std::pair<std::string,unsigned int>("Interaction", UmlPackage::INTERACTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("InteractionConstraint", UmlPackage::INTERACTIONCONSTRAINT));
	m_idMap.insert(std::pair<std::string,unsigned int>("InteractionOperand", UmlPackage::INTERACTIONOPERAND));
	m_idMap.insert(std::pair<std::string,unsigned int>("InteractionUse", UmlPackage::INTERACTIONUSE));
	m_idMap.insert(std::pair<std::string,unsigned int>("Interface", UmlPackage::INTERFACE));
	m_idMap.insert(std::pair<std::string,unsigned int>("InterfaceRealization", UmlPackage::INTERFACEREALIZATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("InterruptibleActivityRegion", UmlPackage::INTERRUPTIBLEACTIVITYREGION));
	m_idMap.insert(std::pair<std::string,unsigned int>("Interval", UmlPackage::INTERVAL));
	m_idMap.insert(std::pair<std::string,unsigned int>("IntervalConstraint", UmlPackage::INTERVALCONSTRAINT));
	m_idMap.insert(std::pair<std::string,unsigned int>("JoinNode", UmlPackage::JOINNODE));
	m_idMap.insert(std::pair<std::string,unsigned int>("Lifeline", UmlPackage::LIFELINE));
	m_idMap.insert(std::pair<std::string,unsigned int>("LinkEndCreationData", UmlPackage::LINKENDCREATIONDATA));
	m_idMap.insert(std::pair<std::string,unsigned int>("LinkEndData", UmlPackage::LINKENDDATA));
	m_idMap.insert(std::pair<std::string,unsigned int>("LinkEndDestructionData", UmlPackage::LINKENDDESTRUCTIONDATA));
	m_idMap.insert(std::pair<std::string,unsigned int>("LiteralBoolean", UmlPackage::LITERALBOOLEAN));
	m_idMap.insert(std::pair<std::string,unsigned int>("LiteralInteger", UmlPackage::LITERALINTEGER));
	m_idMap.insert(std::pair<std::string,unsigned int>("LiteralNull", UmlPackage::LITERALNULL));
	m_idMap.insert(std::pair<std::string,unsigned int>("LiteralReal", UmlPackage::LITERALREAL));
	m_idMap.insert(std::pair<std::string,unsigned int>("LiteralString", UmlPackage::LITERALSTRING));
	m_idMap.insert(std::pair<std::string,unsigned int>("LiteralUnlimitedNatural", UmlPackage::LITERALUNLIMITEDNATURAL));
	m_idMap.insert(std::pair<std::string,unsigned int>("LoopNode", UmlPackage::LOOPNODE));
	m_idMap.insert(std::pair<std::string,unsigned int>("Manifestation", UmlPackage::MANIFESTATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("MergeNode", UmlPackage::MERGENODE));
	m_idMap.insert(std::pair<std::string,unsigned int>("Message", UmlPackage::MESSAGE));
	m_idMap.insert(std::pair<std::string,unsigned int>("MessageOccurrenceSpecification", UmlPackage::MESSAGEOCCURRENCESPECIFICATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("Model", UmlPackage::MODEL));
	m_idMap.insert(std::pair<std::string,unsigned int>("Node", UmlPackage::NODE));
	m_idMap.insert(std::pair<std::string,unsigned int>("Object", UmlPackage::OBJECT));
	m_idMap.insert(std::pair<std::string,unsigned int>("ObjectFlow", UmlPackage::OBJECTFLOW));
	m_idMap.insert(std::pair<std::string,unsigned int>("OccurrenceSpecification", UmlPackage::OCCURRENCESPECIFICATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("OpaqueAction", UmlPackage::OPAQUEACTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("OpaqueBehavior", UmlPackage::OPAQUEBEHAVIOR));
	m_idMap.insert(std::pair<std::string,unsigned int>("OpaqueExpression", UmlPackage::OPAQUEEXPRESSION));
	m_idMap.insert(std::pair<std::string,unsigned int>("Operation", UmlPackage::OPERATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("OperationTemplateParameter", UmlPackage::OPERATIONTEMPLATEPARAMETER));
	m_idMap.insert(std::pair<std::string,unsigned int>("OutputPin", UmlPackage::OUTPUTPIN));
	m_idMap.insert(std::pair<std::string,unsigned int>("Package", UmlPackage::PACKAGE));
	m_idMap.insert(std::pair<std::string,unsigned int>("PackageImport", UmlPackage::PACKAGEIMPORT));
	m_idMap.insert(std::pair<std::string,unsigned int>("PackageMerge", UmlPackage::PACKAGEMERGE));
	m_idMap.insert(std::pair<std::string,unsigned int>("Parameter", UmlPackage::PARAMETER));
	m_idMap.insert(std::pair<std::string,unsigned int>("ParameterSet", UmlPackage::PARAMETERSET));
	m_idMap.insert(std::pair<std::string,unsigned int>("PartDecomposition", UmlPackage::PARTDECOMPOSITION));
	m_idMap.insert(std::pair<std::string,unsigned int>("Port", UmlPackage::PORT));
	m_idMap.insert(std::pair<std::string,unsigned int>("PrimitiveType", UmlPackage::PRIMITIVETYPE));
	m_idMap.insert(std::pair<std::string,unsigned int>("Profile", UmlPackage::PROFILE));
	m_idMap.insert(std::pair<std::string,unsigned int>("ProfileApplication", UmlPackage::PROFILEAPPLICATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("Property", UmlPackage::PROPERTY));
	m_idMap.insert(std::pair<std::string,unsigned int>("ProtocolConformance", UmlPackage::PROTOCOLCONFORMANCE));
	m_idMap.insert(std::pair<std::string,unsigned int>("ProtocolStateMachine", UmlPackage::PROTOCOLSTATEMACHINE));
	m_idMap.insert(std::pair<std::string,unsigned int>("ProtocolTransition", UmlPackage::PROTOCOLTRANSITION));
	m_idMap.insert(std::pair<std::string,unsigned int>("Pseudostate", UmlPackage::PSEUDOSTATE));
	m_idMap.insert(std::pair<std::string,unsigned int>("QualifierValue", UmlPackage::QUALIFIERVALUE));
	m_idMap.insert(std::pair<std::string,unsigned int>("RaiseExceptionAction", UmlPackage::RAISEEXCEPTIONACTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("ReadExtentAction", UmlPackage::READEXTENTACTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("ReadIsClassifiedObjectAction", UmlPackage::READISCLASSIFIEDOBJECTACTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("ReadLinkAction", UmlPackage::READLINKACTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("ReadLinkObjectEndAction", UmlPackage::READLINKOBJECTENDACTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("ReadLinkObjectEndQualifierAction", UmlPackage::READLINKOBJECTENDQUALIFIERACTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("ReadSelfAction", UmlPackage::READSELFACTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("ReadStructuralFeatureAction", UmlPackage::READSTRUCTURALFEATUREACTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("ReadVariableAction", UmlPackage::READVARIABLEACTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("Realization", UmlPackage::REALIZATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("Reception", UmlPackage::RECEPTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("ReclassifyObjectAction", UmlPackage::RECLASSIFYOBJECTACTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("RedefinableTemplateSignature", UmlPackage::REDEFINABLETEMPLATESIGNATURE));
	m_idMap.insert(std::pair<std::string,unsigned int>("ReduceAction", UmlPackage::REDUCEACTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("Region", UmlPackage::REGION));
	m_idMap.insert(std::pair<std::string,unsigned int>("RemoveStructuralFeatureValueAction", UmlPackage::REMOVESTRUCTURALFEATUREVALUEACTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("RemoveVariableValueAction", UmlPackage::REMOVEVARIABLEVALUEACTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("ReplyAction", UmlPackage::REPLYACTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("SendObjectAction", UmlPackage::SENDOBJECTACTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("SendSignalAction", UmlPackage::SENDSIGNALACTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("SequenceNode", UmlPackage::SEQUENCENODE));
	m_idMap.insert(std::pair<std::string,unsigned int>("Signal", UmlPackage::SIGNAL));
	m_idMap.insert(std::pair<std::string,unsigned int>("SignalEvent", UmlPackage::SIGNALEVENT));
	m_idMap.insert(std::pair<std::string,unsigned int>("Slot", UmlPackage::SLOT));
	m_idMap.insert(std::pair<std::string,unsigned int>("StartClassifierBehaviorAction", UmlPackage::STARTCLASSIFIERBEHAVIORACTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("StartObjectBehaviorAction", UmlPackage::STARTOBJECTBEHAVIORACTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("State", UmlPackage::STATE));
	m_idMap.insert(std::pair<std::string,unsigned int>("StateInvariant", UmlPackage::STATEINVARIANT));
	m_idMap.insert(std::pair<std::string,unsigned int>("StateMachine", UmlPackage::STATEMACHINE));
	m_idMap.insert(std::pair<std::string,unsigned int>("Stereotype", UmlPackage::STEREOTYPE));
	m_idMap.insert(std::pair<std::string,unsigned int>("StringExpression", UmlPackage::STRINGEXPRESSION));
	m_idMap.insert(std::pair<std::string,unsigned int>("StructuredActivityNode", UmlPackage::STRUCTUREDACTIVITYNODE));
	m_idMap.insert(std::pair<std::string,unsigned int>("Substitution", UmlPackage::SUBSTITUTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("TemplateBinding", UmlPackage::TEMPLATEBINDING));
	m_idMap.insert(std::pair<std::string,unsigned int>("TemplateParameter", UmlPackage::TEMPLATEPARAMETER));
	m_idMap.insert(std::pair<std::string,unsigned int>("TemplateParameterSubstitution", UmlPackage::TEMPLATEPARAMETERSUBSTITUTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("TemplateSignature", UmlPackage::TEMPLATESIGNATURE));
	m_idMap.insert(std::pair<std::string,unsigned int>("TestIdentityAction", UmlPackage::TESTIDENTITYACTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("TimeConstraint", UmlPackage::TIMECONSTRAINT));
	m_idMap.insert(std::pair<std::string,unsigned int>("TimeEvent", UmlPackage::TIMEEVENT));
	m_idMap.insert(std::pair<std::string,unsigned int>("TimeExpression", UmlPackage::TIMEEXPRESSION));
	m_idMap.insert(std::pair<std::string,unsigned int>("TimeInterval", UmlPackage::TIMEINTERVAL));
	m_idMap.insert(std::pair<std::string,unsigned int>("TimeObservation", UmlPackage::TIMEOBSERVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("Transition", UmlPackage::TRANSITION));
	m_idMap.insert(std::pair<std::string,unsigned int>("Trigger", UmlPackage::TRIGGER));
	m_idMap.insert(std::pair<std::string,unsigned int>("UnmarshallAction", UmlPackage::UNMARSHALLACTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("Usage", UmlPackage::USAGE));
	m_idMap.insert(std::pair<std::string,unsigned int>("UseCase", UmlPackage::USECASE));
	m_idMap.insert(std::pair<std::string,unsigned int>("ValuePin", UmlPackage::VALUEPIN));
	m_idMap.insert(std::pair<std::string,unsigned int>("ValueSpecificationAction", UmlPackage::VALUESPECIFICATIONACTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("Variable", UmlPackage::VARIABLE));
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

std::shared_ptr<ecore::EObject> UmlFactoryImpl::create(const unsigned int classID,  std::shared_ptr<ecore::EObject> container /*= nullptr*/, const unsigned int referenceID/* = -1*/) const
{
	switch(classID)
	{
		case UmlPackage::ABSTRACTION:
		{
			switch(referenceID)
			{
				//Abstraction has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createAbstraction_in_Namespace(castedContainer);
				}
				//Abstraction has owningTemplateParameter as a containment
				case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
					return this->createAbstraction_in_OwningTemplateParameter(castedContainer);
				}
				//Abstraction has owner as a containment
				case  UmlPackage::ELEMENT_OWNER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
					return this->createAbstraction_in_Owner(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::ACCEPTCALLACTION:
		{
			switch(referenceID)
			{
				//AcceptCallAction has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createAcceptCallAction_in_Activity(castedContainer);
				}
				//AcceptCallAction has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createAcceptCallAction_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::ACCEPTEVENTACTION:
		{
			switch(referenceID)
			{
				//AcceptEventAction has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createAcceptEventAction_in_Activity(castedContainer);
				}
				//AcceptEventAction has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createAcceptEventAction_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::ACTIONEXECUTIONSPECIFICATION:
		{
			switch(referenceID)
			{
				//ActionExecutionSpecification has enclosingInteraction as a containment
				case  UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGINTERACTION: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Interaction>(container);
					return this->createActionExecutionSpecification_in_EnclosingInteraction(castedContainer);
				}
				//ActionExecutionSpecification has enclosingOperand as a containment
				case  UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGOPERAND: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::InteractionOperand>(container);
					return this->createActionExecutionSpecification_in_EnclosingOperand(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::ACTIONINPUTPIN:
		{
			switch(referenceID)
			{
				//ActionInputPin has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createActionInputPin_in_Activity(castedContainer);
				}
				//ActionInputPin has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createActionInputPin_in_InStructuredNode(castedContainer);
				}
				//ActionInputPin has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createActionInputPin_in_Namespace(castedContainer);
				}
				//ActionInputPin has owner as a containment
				case  UmlPackage::ELEMENT_OWNER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
					return this->createActionInputPin_in_Owner(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::ACTIVITY:
		{
			switch(referenceID)
			{
				//Activity has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createActivity_in_Namespace(castedContainer);
				}
				//Activity has package as a containment
				case  UmlPackage::TYPE_PACKAGE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
					return this->createActivity_in_Package(castedContainer);
				}
				//Activity has owner as a containment
				case  UmlPackage::ELEMENT_OWNER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
					return this->createActivity_in_Owner(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::ACTIVITYFINALNODE:
		{
			switch(referenceID)
			{
				//ActivityFinalNode has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createActivityFinalNode_in_Activity(castedContainer);
				}
				//ActivityFinalNode has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createActivityFinalNode_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::ACTIVITYPARAMETERNODE:
		{
			switch(referenceID)
			{
				//ActivityParameterNode has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createActivityParameterNode_in_Activity(castedContainer);
				}
				//ActivityParameterNode has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createActivityParameterNode_in_InStructuredNode(castedContainer);
				}
				//ActivityParameterNode has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createActivityParameterNode_in_Namespace(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::ACTIVITYPARTITION:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::ActivityPartition>(container);
			assert(castedContainer);
			return std::shared_ptr<ActivityPartition>(this->createActivityPartition_in_SuperPartition(castedContainer));
		}
		case UmlPackage::ACTOR:
		{
			switch(referenceID)
			{
				//Actor has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createActor_in_Namespace(castedContainer);
				}
				//Actor has package as a containment
				case  UmlPackage::TYPE_PACKAGE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
					return this->createActor_in_Package(castedContainer);
				}
				//Actor has owner as a containment
				case  UmlPackage::ELEMENT_OWNER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
					return this->createActor_in_Owner(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::ADDSTRUCTURALFEATUREVALUEACTION:
		{
			switch(referenceID)
			{
				//AddStructuralFeatureValueAction has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createAddStructuralFeatureValueAction_in_Activity(castedContainer);
				}
				//AddStructuralFeatureValueAction has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createAddStructuralFeatureValueAction_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::ADDVARIABLEVALUEACTION:
		{
			switch(referenceID)
			{
				//AddVariableValueAction has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createAddVariableValueAction_in_Activity(castedContainer);
				}
				//AddVariableValueAction has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createAddVariableValueAction_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::ANYRECEIVEEVENT:
		{
			switch(referenceID)
			{
				//AnyReceiveEvent has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createAnyReceiveEvent_in_Namespace(castedContainer);
				}
				//AnyReceiveEvent has owningTemplateParameter as a containment
				case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
					return this->createAnyReceiveEvent_in_OwningTemplateParameter(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::ARTIFACT:
		{
			switch(referenceID)
			{
				//Artifact has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createArtifact_in_Namespace(castedContainer);
				}
				//Artifact has package as a containment
				case  UmlPackage::TYPE_PACKAGE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
					return this->createArtifact_in_Package(castedContainer);
				}
				//Artifact has owner as a containment
				case  UmlPackage::ELEMENT_OWNER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
					return this->createArtifact_in_Owner(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::ASSOCIATION:
		{
			switch(referenceID)
			{
				//Association has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createAssociation_in_Namespace(castedContainer);
				}
				//Association has package as a containment
				case  UmlPackage::TYPE_PACKAGE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
					return this->createAssociation_in_Package(castedContainer);
				}
				//Association has owner as a containment
				case  UmlPackage::ELEMENT_OWNER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
					return this->createAssociation_in_Owner(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::ASSOCIATIONCLASS:
		{
			switch(referenceID)
			{
				//AssociationClass has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createAssociationClass_in_Namespace(castedContainer);
				}
				//AssociationClass has package as a containment
				case  UmlPackage::TYPE_PACKAGE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
					return this->createAssociationClass_in_Package(castedContainer);
				}
				//AssociationClass has owner as a containment
				case  UmlPackage::ELEMENT_OWNER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
					return this->createAssociationClass_in_Owner(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::BEHAVIOREXECUTIONSPECIFICATION:
		{
			switch(referenceID)
			{
				//BehaviorExecutionSpecification has enclosingInteraction as a containment
				case  UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGINTERACTION: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Interaction>(container);
					return this->createBehaviorExecutionSpecification_in_EnclosingInteraction(castedContainer);
				}
				//BehaviorExecutionSpecification has enclosingOperand as a containment
				case  UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGOPERAND: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::InteractionOperand>(container);
					return this->createBehaviorExecutionSpecification_in_EnclosingOperand(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::BROADCASTSIGNALACTION:
		{
			switch(referenceID)
			{
				//BroadcastSignalAction has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createBroadcastSignalAction_in_Activity(castedContainer);
				}
				//BroadcastSignalAction has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createBroadcastSignalAction_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::CALLBEHAVIORACTION:
		{
			switch(referenceID)
			{
				//CallBehaviorAction has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createCallBehaviorAction_in_Activity(castedContainer);
				}
				//CallBehaviorAction has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createCallBehaviorAction_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::CALLEVENT:
		{
			switch(referenceID)
			{
				//CallEvent has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createCallEvent_in_Namespace(castedContainer);
				}
				//CallEvent has owningTemplateParameter as a containment
				case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
					return this->createCallEvent_in_OwningTemplateParameter(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::CALLOPERATIONACTION:
		{
			switch(referenceID)
			{
				//CallOperationAction has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createCallOperationAction_in_Activity(castedContainer);
				}
				//CallOperationAction has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createCallOperationAction_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::CENTRALBUFFERNODE:
		{
			switch(referenceID)
			{
				//CentralBufferNode has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createCentralBufferNode_in_Activity(castedContainer);
				}
				//CentralBufferNode has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createCentralBufferNode_in_InStructuredNode(castedContainer);
				}
				//CentralBufferNode has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createCentralBufferNode_in_Namespace(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::CHANGEEVENT:
		{
			switch(referenceID)
			{
				//ChangeEvent has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createChangeEvent_in_Namespace(castedContainer);
				}
				//ChangeEvent has owningTemplateParameter as a containment
				case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
					return this->createChangeEvent_in_OwningTemplateParameter(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::CLASS:
		{
			switch(referenceID)
			{
				//Class has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createClass_in_Namespace(castedContainer);
				}
				//Class has package as a containment
				case  UmlPackage::TYPE_PACKAGE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
					return this->createClass_in_Package(castedContainer);
				}
				//Class has owner as a containment
				case  UmlPackage::ELEMENT_OWNER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
					return this->createClass_in_Owner(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::CLASSIFIERTEMPLATEPARAMETER:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::TemplateSignature>(container);
			assert(castedContainer);
			return std::shared_ptr<ClassifierTemplateParameter>(this->createClassifierTemplateParameter_in_Signature(castedContainer));
		}
		case UmlPackage::CLAUSE:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
			assert(castedContainer);
			return std::shared_ptr<Clause>(this->createClause_in_Owner(castedContainer));
		}
		case UmlPackage::CLEARASSOCIATIONACTION:
		{
			switch(referenceID)
			{
				//ClearAssociationAction has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createClearAssociationAction_in_Activity(castedContainer);
				}
				//ClearAssociationAction has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createClearAssociationAction_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::CLEARSTRUCTURALFEATUREACTION:
		{
			switch(referenceID)
			{
				//ClearStructuralFeatureAction has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createClearStructuralFeatureAction_in_Activity(castedContainer);
				}
				//ClearStructuralFeatureAction has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createClearStructuralFeatureAction_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::CLEARVARIABLEACTION:
		{
			switch(referenceID)
			{
				//ClearVariableAction has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createClearVariableAction_in_Activity(castedContainer);
				}
				//ClearVariableAction has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createClearVariableAction_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::COLLABORATION:
		{
			switch(referenceID)
			{
				//Collaboration has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createCollaboration_in_Namespace(castedContainer);
				}
				//Collaboration has package as a containment
				case  UmlPackage::TYPE_PACKAGE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
					return this->createCollaboration_in_Package(castedContainer);
				}
				//Collaboration has owner as a containment
				case  UmlPackage::ELEMENT_OWNER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
					return this->createCollaboration_in_Owner(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::COLLABORATIONUSE:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
			assert(castedContainer);
			return std::shared_ptr<CollaborationUse>(this->createCollaborationUse_in_Namespace(castedContainer));
		}
		case UmlPackage::COMBINEDFRAGMENT:
		{
			switch(referenceID)
			{
				//CombinedFragment has enclosingInteraction as a containment
				case  UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGINTERACTION: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Interaction>(container);
					return this->createCombinedFragment_in_EnclosingInteraction(castedContainer);
				}
				//CombinedFragment has enclosingOperand as a containment
				case  UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGOPERAND: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::InteractionOperand>(container);
					return this->createCombinedFragment_in_EnclosingOperand(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::COMMENT:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
			assert(castedContainer);
			return std::shared_ptr<Comment>(this->createComment_in_Owner(castedContainer));
		}
		case UmlPackage::COMMUNICATIONPATH:
		{
			switch(referenceID)
			{
				//CommunicationPath has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createCommunicationPath_in_Namespace(castedContainer);
				}
				//CommunicationPath has package as a containment
				case  UmlPackage::TYPE_PACKAGE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
					return this->createCommunicationPath_in_Package(castedContainer);
				}
				//CommunicationPath has owner as a containment
				case  UmlPackage::ELEMENT_OWNER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
					return this->createCommunicationPath_in_Owner(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::COMPONENT:
		{
			switch(referenceID)
			{
				//Component has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createComponent_in_Namespace(castedContainer);
				}
				//Component has package as a containment
				case  UmlPackage::TYPE_PACKAGE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
					return this->createComponent_in_Package(castedContainer);
				}
				//Component has owner as a containment
				case  UmlPackage::ELEMENT_OWNER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
					return this->createComponent_in_Owner(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::COMPONENTREALIZATION:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::Component>(container);
			assert(castedContainer);
			return std::shared_ptr<ComponentRealization>(this->createComponentRealization_in_Abstraction(castedContainer));
		}
		case UmlPackage::CONDITIONALNODE:
		{
			switch(referenceID)
			{
				//ConditionalNode has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createConditionalNode_in_Activity(castedContainer);
				}
				//ConditionalNode has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createConditionalNode_in_InStructuredNode(castedContainer);
				}
				//ConditionalNode has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createConditionalNode_in_Namespace(castedContainer);
				}
				//ConditionalNode has inActivity as a containment
				case  UmlPackage::ACTIVITYGROUP_INACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createConditionalNode_in_InActivity(castedContainer);
				}
				//ConditionalNode has superGroup as a containment
				case  UmlPackage::ACTIVITYGROUP_SUPERGROUP: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::ActivityGroup>(container);
					return this->createConditionalNode_in_SuperGroup(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::CONNECTABLEELEMENTTEMPLATEPARAMETER:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::TemplateSignature>(container);
			assert(castedContainer);
			return std::shared_ptr<ConnectableElementTemplateParameter>(this->createConnectableElementTemplateParameter_in_Signature(castedContainer));
		}
		case UmlPackage::CONNECTIONPOINTREFERENCE:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::State>(container);
			assert(castedContainer);
			return std::shared_ptr<ConnectionPointReference>(this->createConnectionPointReference_in_State(castedContainer));
		}
		case UmlPackage::CONNECTOR:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
			assert(castedContainer);
			return std::shared_ptr<Connector>(this->createConnector_in_Namespace(castedContainer));
		}
		case UmlPackage::CONNECTOREND:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
			assert(castedContainer);
			return std::shared_ptr<ConnectorEnd>(this->createConnectorEnd_in_Owner(castedContainer));
		}
		case UmlPackage::CONSIDERIGNOREFRAGMENT:
		{
			switch(referenceID)
			{
				//ConsiderIgnoreFragment has enclosingInteraction as a containment
				case  UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGINTERACTION: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Interaction>(container);
					return this->createConsiderIgnoreFragment_in_EnclosingInteraction(castedContainer);
				}
				//ConsiderIgnoreFragment has enclosingOperand as a containment
				case  UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGOPERAND: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::InteractionOperand>(container);
					return this->createConsiderIgnoreFragment_in_EnclosingOperand(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::CONSTRAINT:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
			assert(castedContainer);
			return std::shared_ptr<Constraint>(this->createConstraint_in_Context(castedContainer));
		}
		case UmlPackage::CONTINUATION:
		{
			switch(referenceID)
			{
				//Continuation has enclosingInteraction as a containment
				case  UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGINTERACTION: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Interaction>(container);
					return this->createContinuation_in_EnclosingInteraction(castedContainer);
				}
				//Continuation has enclosingOperand as a containment
				case  UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGOPERAND: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::InteractionOperand>(container);
					return this->createContinuation_in_EnclosingOperand(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::CONTROLFLOW:
		{
			switch(referenceID)
			{
				//ControlFlow has activity as a containment
				case  UmlPackage::ACTIVITYEDGE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createControlFlow_in_Activity(castedContainer);
				}
				//ControlFlow has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYEDGE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createControlFlow_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::CREATELINKACTION:
		{
			switch(referenceID)
			{
				//CreateLinkAction has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createCreateLinkAction_in_Activity(castedContainer);
				}
				//CreateLinkAction has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createCreateLinkAction_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::CREATELINKOBJECTACTION:
		{
			switch(referenceID)
			{
				//CreateLinkObjectAction has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createCreateLinkObjectAction_in_Activity(castedContainer);
				}
				//CreateLinkObjectAction has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createCreateLinkObjectAction_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::CREATEOBJECTACTION:
		{
			switch(referenceID)
			{
				//CreateObjectAction has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createCreateObjectAction_in_Activity(castedContainer);
				}
				//CreateObjectAction has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createCreateObjectAction_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::DATASTORENODE:
		{
			switch(referenceID)
			{
				//DataStoreNode has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createDataStoreNode_in_Activity(castedContainer);
				}
				//DataStoreNode has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createDataStoreNode_in_InStructuredNode(castedContainer);
				}
				//DataStoreNode has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createDataStoreNode_in_Namespace(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::DATATYPE:
		{
			switch(referenceID)
			{
				//DataType has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createDataType_in_Namespace(castedContainer);
				}
				//DataType has package as a containment
				case  UmlPackage::TYPE_PACKAGE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
					return this->createDataType_in_Package(castedContainer);
				}
				//DataType has owner as a containment
				case  UmlPackage::ELEMENT_OWNER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
					return this->createDataType_in_Owner(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::DECISIONNODE:
		{
			switch(referenceID)
			{
				//DecisionNode has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createDecisionNode_in_Activity(castedContainer);
				}
				//DecisionNode has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createDecisionNode_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::DEPENDENCY:
		{
			switch(referenceID)
			{
				//Dependency has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createDependency_in_Namespace(castedContainer);
				}
				//Dependency has owningTemplateParameter as a containment
				case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
					return this->createDependency_in_OwningTemplateParameter(castedContainer);
				}
				//Dependency has owner as a containment
				case  UmlPackage::ELEMENT_OWNER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
					return this->createDependency_in_Owner(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::DEPLOYMENT:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::DeploymentTarget>(container);
			assert(castedContainer);
			return std::shared_ptr<Deployment>(this->createDeployment_in_Location(castedContainer));
		}
		case UmlPackage::DEPLOYMENTSPECIFICATION:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::Deployment>(container);
			assert(castedContainer);
			return std::shared_ptr<DeploymentSpecification>(this->createDeploymentSpecification_in_Deployment(castedContainer));
		}
		case UmlPackage::DESTROYLINKACTION:
		{
			switch(referenceID)
			{
				//DestroyLinkAction has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createDestroyLinkAction_in_Activity(castedContainer);
				}
				//DestroyLinkAction has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createDestroyLinkAction_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::DESTROYOBJECTACTION:
		{
			switch(referenceID)
			{
				//DestroyObjectAction has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createDestroyObjectAction_in_Activity(castedContainer);
				}
				//DestroyObjectAction has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createDestroyObjectAction_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::DESTRUCTIONOCCURRENCESPECIFICATION:
		{
			switch(referenceID)
			{
				//DestructionOccurrenceSpecification has enclosingInteraction as a containment
				case  UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGINTERACTION: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Interaction>(container);
					return this->createDestructionOccurrenceSpecification_in_EnclosingInteraction(castedContainer);
				}
				//DestructionOccurrenceSpecification has enclosingOperand as a containment
				case  UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGOPERAND: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::InteractionOperand>(container);
					return this->createDestructionOccurrenceSpecification_in_EnclosingOperand(castedContainer);
				}
				//DestructionOccurrenceSpecification has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createDestructionOccurrenceSpecification_in_Namespace(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::DEVICE:
		{
			switch(referenceID)
			{
				//Device has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createDevice_in_Namespace(castedContainer);
				}
				//Device has package as a containment
				case  UmlPackage::TYPE_PACKAGE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
					return this->createDevice_in_Package(castedContainer);
				}
				//Device has owner as a containment
				case  UmlPackage::ELEMENT_OWNER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
					return this->createDevice_in_Owner(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::DURATION:
		{
			switch(referenceID)
			{
				//Duration has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createDuration_in_Namespace(castedContainer);
				}
				//Duration has owningTemplateParameter as a containment
				case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
					return this->createDuration_in_OwningTemplateParameter(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::DURATIONCONSTRAINT:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
			assert(castedContainer);
			return std::shared_ptr<DurationConstraint>(this->createDurationConstraint_in_Context(castedContainer));
		}
		case UmlPackage::DURATIONINTERVAL:
		{
			switch(referenceID)
			{
				//DurationInterval has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createDurationInterval_in_Namespace(castedContainer);
				}
				//DurationInterval has owningTemplateParameter as a containment
				case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
					return this->createDurationInterval_in_OwningTemplateParameter(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::DURATIONOBSERVATION:
		{
			switch(referenceID)
			{
				//DurationObservation has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createDurationObservation_in_Namespace(castedContainer);
				}
				//DurationObservation has owningTemplateParameter as a containment
				case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
					return this->createDurationObservation_in_OwningTemplateParameter(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::ELEMENTIMPORT:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
			assert(castedContainer);
			return std::shared_ptr<ElementImport>(this->createElementImport_in_ImportingNamespace(castedContainer));
		}
		case UmlPackage::ENUMERATION:
		{
			switch(referenceID)
			{
				//Enumeration has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createEnumeration_in_Namespace(castedContainer);
				}
				//Enumeration has package as a containment
				case  UmlPackage::TYPE_PACKAGE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
					return this->createEnumeration_in_Package(castedContainer);
				}
				//Enumeration has owner as a containment
				case  UmlPackage::ELEMENT_OWNER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
					return this->createEnumeration_in_Owner(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::ENUMERATIONLITERAL:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::Enumeration>(container);
			assert(castedContainer);
			return std::shared_ptr<EnumerationLiteral>(this->createEnumerationLiteral_in_Enumeration(castedContainer));
		}
		case UmlPackage::EXCEPTIONHANDLER:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::ExecutableNode>(container);
			assert(castedContainer);
			return std::shared_ptr<ExceptionHandler>(this->createExceptionHandler_in_ProtectedNode(castedContainer));
		}
		case UmlPackage::EXECUTIONENVIRONMENT:
		{
			switch(referenceID)
			{
				//ExecutionEnvironment has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createExecutionEnvironment_in_Namespace(castedContainer);
				}
				//ExecutionEnvironment has package as a containment
				case  UmlPackage::TYPE_PACKAGE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
					return this->createExecutionEnvironment_in_Package(castedContainer);
				}
				//ExecutionEnvironment has owner as a containment
				case  UmlPackage::ELEMENT_OWNER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
					return this->createExecutionEnvironment_in_Owner(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::EXECUTIONOCCURRENCESPECIFICATION:
		{
			switch(referenceID)
			{
				//ExecutionOccurrenceSpecification has enclosingInteraction as a containment
				case  UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGINTERACTION: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Interaction>(container);
					return this->createExecutionOccurrenceSpecification_in_EnclosingInteraction(castedContainer);
				}
				//ExecutionOccurrenceSpecification has enclosingOperand as a containment
				case  UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGOPERAND: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::InteractionOperand>(container);
					return this->createExecutionOccurrenceSpecification_in_EnclosingOperand(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::EXPANSIONNODE:
		{
			switch(referenceID)
			{
				//ExpansionNode has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createExpansionNode_in_Activity(castedContainer);
				}
				//ExpansionNode has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createExpansionNode_in_InStructuredNode(castedContainer);
				}
				//ExpansionNode has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createExpansionNode_in_Namespace(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::EXPANSIONREGION:
		{
			switch(referenceID)
			{
				//ExpansionRegion has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createExpansionRegion_in_Activity(castedContainer);
				}
				//ExpansionRegion has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createExpansionRegion_in_InStructuredNode(castedContainer);
				}
				//ExpansionRegion has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createExpansionRegion_in_Namespace(castedContainer);
				}
				//ExpansionRegion has inActivity as a containment
				case  UmlPackage::ACTIVITYGROUP_INACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createExpansionRegion_in_InActivity(castedContainer);
				}
				//ExpansionRegion has superGroup as a containment
				case  UmlPackage::ACTIVITYGROUP_SUPERGROUP: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::ActivityGroup>(container);
					return this->createExpansionRegion_in_SuperGroup(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::EXPRESSION:
		{
			switch(referenceID)
			{
				//Expression has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createExpression_in_Namespace(castedContainer);
				}
				//Expression has owningTemplateParameter as a containment
				case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
					return this->createExpression_in_OwningTemplateParameter(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::EXTEND:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::UseCase>(container);
			assert(castedContainer);
			return std::shared_ptr<Extend>(this->createExtend_in_Extension(castedContainer));
		}
		case UmlPackage::EXTENSION:
		{
			switch(referenceID)
			{
				//Extension has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createExtension_in_Namespace(castedContainer);
				}
				//Extension has package as a containment
				case  UmlPackage::TYPE_PACKAGE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
					return this->createExtension_in_Package(castedContainer);
				}
				//Extension has owner as a containment
				case  UmlPackage::ELEMENT_OWNER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
					return this->createExtension_in_Owner(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::EXTENSIONEND:
		{
			switch(referenceID)
			{
				//ExtensionEnd has associationEnd as a containment
				case  UmlPackage::PROPERTY_ASSOCIATIONEND: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Property>(container);
					return this->createExtensionEnd_in_AssociationEnd(castedContainer);
				}
				//ExtensionEnd has class as a containment
				case  UmlPackage::PROPERTY_CLASS: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Class>(container);
					return this->createExtensionEnd_in_Class(castedContainer);
				}
				//ExtensionEnd has datatype as a containment
				case  UmlPackage::PROPERTY_DATATYPE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::DataType>(container);
					return this->createExtensionEnd_in_Datatype(castedContainer);
				}
				//ExtensionEnd has interface as a containment
				case  UmlPackage::PROPERTY_INTERFACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Interface>(container);
					return this->createExtensionEnd_in_Interface(castedContainer);
				}
				//ExtensionEnd has owningAssociation as a containment
				case  UmlPackage::PROPERTY_OWNINGASSOCIATION: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Association>(container);
					return this->createExtensionEnd_in_OwningAssociation(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::EXTENSIONPOINT:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::UseCase>(container);
			assert(castedContainer);
			return std::shared_ptr<ExtensionPoint>(this->createExtensionPoint_in_UseCase(castedContainer));
		}
		//Factory is not contained in any other element
	    case UmlPackage::FACTORY: return std::shared_ptr<Factory>(this->createFactory());
		case UmlPackage::FINALSTATE:
		{
			switch(referenceID)
			{
				//FinalState has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createFinalState_in_Namespace(castedContainer);
				}
				//FinalState has container as a containment
				case  UmlPackage::VERTEX_CONTAINER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Region>(container);
					return this->createFinalState_in_Container(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::FLOWFINALNODE:
		{
			switch(referenceID)
			{
				//FlowFinalNode has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createFlowFinalNode_in_Activity(castedContainer);
				}
				//FlowFinalNode has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createFlowFinalNode_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::FORKNODE:
		{
			switch(referenceID)
			{
				//ForkNode has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createForkNode_in_Activity(castedContainer);
				}
				//ForkNode has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createForkNode_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::FUNCTIONBEHAVIOR:
		{
			switch(referenceID)
			{
				//FunctionBehavior has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createFunctionBehavior_in_Namespace(castedContainer);
				}
				//FunctionBehavior has package as a containment
				case  UmlPackage::TYPE_PACKAGE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
					return this->createFunctionBehavior_in_Package(castedContainer);
				}
				//FunctionBehavior has owner as a containment
				case  UmlPackage::ELEMENT_OWNER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
					return this->createFunctionBehavior_in_Owner(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::GATE:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
			assert(castedContainer);
			return std::shared_ptr<Gate>(this->createGate_in_Namespace(castedContainer));
		}
		case UmlPackage::GENERALORDERING:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
			assert(castedContainer);
			return std::shared_ptr<GeneralOrdering>(this->createGeneralOrdering_in_Namespace(castedContainer));
		}
		case UmlPackage::GENERALIZATION:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::Classifier>(container);
			assert(castedContainer);
			return std::shared_ptr<Generalization>(this->createGeneralization_in_Specific(castedContainer));
		}
		case UmlPackage::GENERALIZATIONSET:
		{
			switch(referenceID)
			{
				//GeneralizationSet has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createGeneralizationSet_in_Namespace(castedContainer);
				}
				//GeneralizationSet has owningTemplateParameter as a containment
				case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
					return this->createGeneralizationSet_in_OwningTemplateParameter(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::IMAGE:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
			assert(castedContainer);
			return std::shared_ptr<Image>(this->createImage_in_Owner(castedContainer));
		}
		case UmlPackage::INCLUDE:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::UseCase>(container);
			assert(castedContainer);
			return std::shared_ptr<Include>(this->createInclude_in_IncludingCase(castedContainer));
		}
		case UmlPackage::INFORMATIONFLOW:
		{
			switch(referenceID)
			{
				//InformationFlow has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createInformationFlow_in_Namespace(castedContainer);
				}
				//InformationFlow has owningTemplateParameter as a containment
				case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
					return this->createInformationFlow_in_OwningTemplateParameter(castedContainer);
				}
				//InformationFlow has owner as a containment
				case  UmlPackage::ELEMENT_OWNER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
					return this->createInformationFlow_in_Owner(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::INFORMATIONITEM:
		{
			switch(referenceID)
			{
				//InformationItem has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createInformationItem_in_Namespace(castedContainer);
				}
				//InformationItem has package as a containment
				case  UmlPackage::TYPE_PACKAGE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
					return this->createInformationItem_in_Package(castedContainer);
				}
				//InformationItem has owner as a containment
				case  UmlPackage::ELEMENT_OWNER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
					return this->createInformationItem_in_Owner(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::INITIALNODE:
		{
			switch(referenceID)
			{
				//InitialNode has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createInitialNode_in_Activity(castedContainer);
				}
				//InitialNode has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createInitialNode_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::INPUTPIN:
		{
			switch(referenceID)
			{
				//InputPin has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createInputPin_in_Activity(castedContainer);
				}
				//InputPin has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createInputPin_in_InStructuredNode(castedContainer);
				}
				//InputPin has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createInputPin_in_Namespace(castedContainer);
				}
				//InputPin has owner as a containment
				case  UmlPackage::ELEMENT_OWNER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
					return this->createInputPin_in_Owner(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::INSTANCESPECIFICATION:
		{
			switch(referenceID)
			{
				//InstanceSpecification has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createInstanceSpecification_in_Namespace(castedContainer);
				}
				//InstanceSpecification has owningTemplateParameter as a containment
				case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
					return this->createInstanceSpecification_in_OwningTemplateParameter(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::INSTANCEVALUE:
		{
			switch(referenceID)
			{
				//InstanceValue has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createInstanceValue_in_Namespace(castedContainer);
				}
				//InstanceValue has owningTemplateParameter as a containment
				case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
					return this->createInstanceValue_in_OwningTemplateParameter(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::INTERACTION:
		{
			switch(referenceID)
			{
				//Interaction has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createInteraction_in_Namespace(castedContainer);
				}
				//Interaction has package as a containment
				case  UmlPackage::TYPE_PACKAGE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
					return this->createInteraction_in_Package(castedContainer);
				}
				//Interaction has owner as a containment
				case  UmlPackage::ELEMENT_OWNER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
					return this->createInteraction_in_Owner(castedContainer);
				}
				//Interaction has enclosingInteraction as a containment
				case  UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGINTERACTION: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Interaction>(container);
					return this->createInteraction_in_EnclosingInteraction(castedContainer);
				}
				//Interaction has enclosingOperand as a containment
				case  UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGOPERAND: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::InteractionOperand>(container);
					return this->createInteraction_in_EnclosingOperand(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::INTERACTIONCONSTRAINT:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
			assert(castedContainer);
			return std::shared_ptr<InteractionConstraint>(this->createInteractionConstraint_in_Context(castedContainer));
		}
		case UmlPackage::INTERACTIONOPERAND:
		{
			switch(referenceID)
			{
				//InteractionOperand has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createInteractionOperand_in_Namespace(castedContainer);
				}
				//InteractionOperand has enclosingInteraction as a containment
				case  UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGINTERACTION: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Interaction>(container);
					return this->createInteractionOperand_in_EnclosingInteraction(castedContainer);
				}
				//InteractionOperand has enclosingOperand as a containment
				case  UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGOPERAND: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::InteractionOperand>(container);
					return this->createInteractionOperand_in_EnclosingOperand(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::INTERACTIONUSE:
		{
			switch(referenceID)
			{
				//InteractionUse has enclosingInteraction as a containment
				case  UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGINTERACTION: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Interaction>(container);
					return this->createInteractionUse_in_EnclosingInteraction(castedContainer);
				}
				//InteractionUse has enclosingOperand as a containment
				case  UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGOPERAND: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::InteractionOperand>(container);
					return this->createInteractionUse_in_EnclosingOperand(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::INTERFACE:
		{
			switch(referenceID)
			{
				//Interface has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createInterface_in_Namespace(castedContainer);
				}
				//Interface has package as a containment
				case  UmlPackage::TYPE_PACKAGE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
					return this->createInterface_in_Package(castedContainer);
				}
				//Interface has owner as a containment
				case  UmlPackage::ELEMENT_OWNER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
					return this->createInterface_in_Owner(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::INTERFACEREALIZATION:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::BehavioredClassifier>(container);
			assert(castedContainer);
			return std::shared_ptr<InterfaceRealization>(this->createInterfaceRealization_in_ImplementingClassifier(castedContainer));
		}
		case UmlPackage::INTERRUPTIBLEACTIVITYREGION:
		{
			switch(referenceID)
			{
				//InterruptibleActivityRegion has inActivity as a containment
				case  UmlPackage::ACTIVITYGROUP_INACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createInterruptibleActivityRegion_in_InActivity(castedContainer);
				}
				//InterruptibleActivityRegion has superGroup as a containment
				case  UmlPackage::ACTIVITYGROUP_SUPERGROUP: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::ActivityGroup>(container);
					return this->createInterruptibleActivityRegion_in_SuperGroup(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::INTERVAL:
		{
			switch(referenceID)
			{
				//Interval has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createInterval_in_Namespace(castedContainer);
				}
				//Interval has owningTemplateParameter as a containment
				case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
					return this->createInterval_in_OwningTemplateParameter(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::INTERVALCONSTRAINT:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
			assert(castedContainer);
			return std::shared_ptr<IntervalConstraint>(this->createIntervalConstraint_in_Context(castedContainer));
		}
		case UmlPackage::JOINNODE:
		{
			switch(referenceID)
			{
				//JoinNode has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createJoinNode_in_Activity(castedContainer);
				}
				//JoinNode has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createJoinNode_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::LIFELINE:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::Interaction>(container);
			assert(castedContainer);
			return std::shared_ptr<Lifeline>(this->createLifeline_in_Interaction(castedContainer));
		}
		case UmlPackage::LINKENDCREATIONDATA:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
			assert(castedContainer);
			return std::shared_ptr<LinkEndCreationData>(this->createLinkEndCreationData_in_Owner(castedContainer));
		}
		case UmlPackage::LINKENDDATA:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
			assert(castedContainer);
			return std::shared_ptr<LinkEndData>(this->createLinkEndData_in_Owner(castedContainer));
		}
		case UmlPackage::LINKENDDESTRUCTIONDATA:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
			assert(castedContainer);
			return std::shared_ptr<LinkEndDestructionData>(this->createLinkEndDestructionData_in_Owner(castedContainer));
		}
		case UmlPackage::LITERALBOOLEAN:
		{
			switch(referenceID)
			{
				//LiteralBoolean has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createLiteralBoolean_in_Namespace(castedContainer);
				}
				//LiteralBoolean has owningTemplateParameter as a containment
				case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
					return this->createLiteralBoolean_in_OwningTemplateParameter(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::LITERALINTEGER:
		{
			switch(referenceID)
			{
				//LiteralInteger has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createLiteralInteger_in_Namespace(castedContainer);
				}
				//LiteralInteger has owningTemplateParameter as a containment
				case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
					return this->createLiteralInteger_in_OwningTemplateParameter(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::LITERALNULL:
		{
			switch(referenceID)
			{
				//LiteralNull has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createLiteralNull_in_Namespace(castedContainer);
				}
				//LiteralNull has owningTemplateParameter as a containment
				case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
					return this->createLiteralNull_in_OwningTemplateParameter(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::LITERALREAL:
		{
			switch(referenceID)
			{
				//LiteralReal has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createLiteralReal_in_Namespace(castedContainer);
				}
				//LiteralReal has owningTemplateParameter as a containment
				case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
					return this->createLiteralReal_in_OwningTemplateParameter(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::LITERALSTRING:
		{
			switch(referenceID)
			{
				//LiteralString has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createLiteralString_in_Namespace(castedContainer);
				}
				//LiteralString has owningTemplateParameter as a containment
				case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
					return this->createLiteralString_in_OwningTemplateParameter(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::LITERALUNLIMITEDNATURAL:
		{
			switch(referenceID)
			{
				//LiteralUnlimitedNatural has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createLiteralUnlimitedNatural_in_Namespace(castedContainer);
				}
				//LiteralUnlimitedNatural has owningTemplateParameter as a containment
				case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
					return this->createLiteralUnlimitedNatural_in_OwningTemplateParameter(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::LOOPNODE:
		{
			switch(referenceID)
			{
				//LoopNode has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createLoopNode_in_Activity(castedContainer);
				}
				//LoopNode has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createLoopNode_in_InStructuredNode(castedContainer);
				}
				//LoopNode has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createLoopNode_in_Namespace(castedContainer);
				}
				//LoopNode has inActivity as a containment
				case  UmlPackage::ACTIVITYGROUP_INACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createLoopNode_in_InActivity(castedContainer);
				}
				//LoopNode has superGroup as a containment
				case  UmlPackage::ACTIVITYGROUP_SUPERGROUP: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::ActivityGroup>(container);
					return this->createLoopNode_in_SuperGroup(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::MANIFESTATION:
		{
			switch(referenceID)
			{
				//Manifestation has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createManifestation_in_Namespace(castedContainer);
				}
				//Manifestation has owningTemplateParameter as a containment
				case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
					return this->createManifestation_in_OwningTemplateParameter(castedContainer);
				}
				//Manifestation has owner as a containment
				case  UmlPackage::ELEMENT_OWNER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
					return this->createManifestation_in_Owner(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::MERGENODE:
		{
			switch(referenceID)
			{
				//MergeNode has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createMergeNode_in_Activity(castedContainer);
				}
				//MergeNode has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createMergeNode_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::MESSAGE:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::Interaction>(container);
			assert(castedContainer);
			return std::shared_ptr<Message>(this->createMessage_in_Interaction(castedContainer));
		}
		case UmlPackage::MESSAGEOCCURRENCESPECIFICATION:
		{
			switch(referenceID)
			{
				//MessageOccurrenceSpecification has enclosingInteraction as a containment
				case  UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGINTERACTION: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Interaction>(container);
					return this->createMessageOccurrenceSpecification_in_EnclosingInteraction(castedContainer);
				}
				//MessageOccurrenceSpecification has enclosingOperand as a containment
				case  UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGOPERAND: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::InteractionOperand>(container);
					return this->createMessageOccurrenceSpecification_in_EnclosingOperand(castedContainer);
				}
				//MessageOccurrenceSpecification has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createMessageOccurrenceSpecification_in_Namespace(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::MODEL:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
			assert(castedContainer);
			return std::shared_ptr<Model>(this->createModel_in_NestingPackage(castedContainer));
		}
		case UmlPackage::NODE:
		{
			switch(referenceID)
			{
				//Node has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createNode_in_Namespace(castedContainer);
				}
				//Node has package as a containment
				case  UmlPackage::TYPE_PACKAGE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
					return this->createNode_in_Package(castedContainer);
				}
				//Node has owner as a containment
				case  UmlPackage::ELEMENT_OWNER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
					return this->createNode_in_Owner(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		//Object is not contained in any other element
	    case UmlPackage::OBJECT: return std::shared_ptr<Object>(this->createObject());
		case UmlPackage::OBJECTFLOW:
		{
			switch(referenceID)
			{
				//ObjectFlow has activity as a containment
				case  UmlPackage::ACTIVITYEDGE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createObjectFlow_in_Activity(castedContainer);
				}
				//ObjectFlow has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYEDGE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createObjectFlow_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::OCCURRENCESPECIFICATION:
		{
			switch(referenceID)
			{
				//OccurrenceSpecification has enclosingInteraction as a containment
				case  UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGINTERACTION: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Interaction>(container);
					return this->createOccurrenceSpecification_in_EnclosingInteraction(castedContainer);
				}
				//OccurrenceSpecification has enclosingOperand as a containment
				case  UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGOPERAND: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::InteractionOperand>(container);
					return this->createOccurrenceSpecification_in_EnclosingOperand(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::OPAQUEACTION:
		{
			switch(referenceID)
			{
				//OpaqueAction has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createOpaqueAction_in_Activity(castedContainer);
				}
				//OpaqueAction has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createOpaqueAction_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::OPAQUEBEHAVIOR:
		{
			switch(referenceID)
			{
				//OpaqueBehavior has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createOpaqueBehavior_in_Namespace(castedContainer);
				}
				//OpaqueBehavior has package as a containment
				case  UmlPackage::TYPE_PACKAGE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
					return this->createOpaqueBehavior_in_Package(castedContainer);
				}
				//OpaqueBehavior has owner as a containment
				case  UmlPackage::ELEMENT_OWNER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
					return this->createOpaqueBehavior_in_Owner(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::OPAQUEEXPRESSION:
		{
			switch(referenceID)
			{
				//OpaqueExpression has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createOpaqueExpression_in_Namespace(castedContainer);
				}
				//OpaqueExpression has owningTemplateParameter as a containment
				case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
					return this->createOpaqueExpression_in_OwningTemplateParameter(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::OPERATION:
		{
			switch(referenceID)
			{
				//Operation has class as a containment
				case  UmlPackage::OPERATION_CLASS: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Class>(container);
					return this->createOperation_in_Class(castedContainer);
				}
				//Operation has datatype as a containment
				case  UmlPackage::OPERATION_DATATYPE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::DataType>(container);
					return this->createOperation_in_Datatype(castedContainer);
				}
				//Operation has interface as a containment
				case  UmlPackage::OPERATION_INTERFACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Interface>(container);
					return this->createOperation_in_Interface(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::OPERATIONTEMPLATEPARAMETER:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::TemplateSignature>(container);
			assert(castedContainer);
			return std::shared_ptr<OperationTemplateParameter>(this->createOperationTemplateParameter_in_Signature(castedContainer));
		}
		case UmlPackage::OUTPUTPIN:
		{
			switch(referenceID)
			{
				//OutputPin has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createOutputPin_in_Activity(castedContainer);
				}
				//OutputPin has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createOutputPin_in_InStructuredNode(castedContainer);
				}
				//OutputPin has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createOutputPin_in_Namespace(castedContainer);
				}
				//OutputPin has owner as a containment
				case  UmlPackage::ELEMENT_OWNER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
					return this->createOutputPin_in_Owner(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::PACKAGE:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
			assert(castedContainer);
			return std::shared_ptr<Package>(this->createPackage_in_NestingPackage(castedContainer));
		}
		case UmlPackage::PACKAGEIMPORT:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
			assert(castedContainer);
			return std::shared_ptr<PackageImport>(this->createPackageImport_in_ImportingNamespace(castedContainer));
		}
		case UmlPackage::PACKAGEMERGE:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
			assert(castedContainer);
			return std::shared_ptr<PackageMerge>(this->createPackageMerge_in_ReceivingPackage(castedContainer));
		}
		case UmlPackage::PARAMETER:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::Operation>(container);
			assert(castedContainer);
			return std::shared_ptr<Parameter>(this->createParameter_in_Operation(castedContainer));
		}
		case UmlPackage::PARAMETERSET:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
			assert(castedContainer);
			return std::shared_ptr<ParameterSet>(this->createParameterSet_in_Namespace(castedContainer));
		}
		case UmlPackage::PARTDECOMPOSITION:
		{
			switch(referenceID)
			{
				//PartDecomposition has enclosingInteraction as a containment
				case  UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGINTERACTION: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Interaction>(container);
					return this->createPartDecomposition_in_EnclosingInteraction(castedContainer);
				}
				//PartDecomposition has enclosingOperand as a containment
				case  UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGOPERAND: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::InteractionOperand>(container);
					return this->createPartDecomposition_in_EnclosingOperand(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::PORT:
		{
			switch(referenceID)
			{
				//Port has associationEnd as a containment
				case  UmlPackage::PROPERTY_ASSOCIATIONEND: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Property>(container);
					return this->createPort_in_AssociationEnd(castedContainer);
				}
				//Port has class as a containment
				case  UmlPackage::PROPERTY_CLASS: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Class>(container);
					return this->createPort_in_Class(castedContainer);
				}
				//Port has datatype as a containment
				case  UmlPackage::PROPERTY_DATATYPE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::DataType>(container);
					return this->createPort_in_Datatype(castedContainer);
				}
				//Port has interface as a containment
				case  UmlPackage::PROPERTY_INTERFACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Interface>(container);
					return this->createPort_in_Interface(castedContainer);
				}
				//Port has owningAssociation as a containment
				case  UmlPackage::PROPERTY_OWNINGASSOCIATION: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Association>(container);
					return this->createPort_in_OwningAssociation(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::PRIMITIVETYPE:
		{
			switch(referenceID)
			{
				//PrimitiveType has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createPrimitiveType_in_Namespace(castedContainer);
				}
				//PrimitiveType has package as a containment
				case  UmlPackage::TYPE_PACKAGE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
					return this->createPrimitiveType_in_Package(castedContainer);
				}
				//PrimitiveType has owner as a containment
				case  UmlPackage::ELEMENT_OWNER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
					return this->createPrimitiveType_in_Owner(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::PROFILE:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
			assert(castedContainer);
			return std::shared_ptr<Profile>(this->createProfile_in_NestingPackage(castedContainer));
		}
		case UmlPackage::PROFILEAPPLICATION:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
			assert(castedContainer);
			return std::shared_ptr<ProfileApplication>(this->createProfileApplication_in_ApplyingPackage(castedContainer));
		}
		case UmlPackage::PROPERTY:
		{
			switch(referenceID)
			{
				//Property has associationEnd as a containment
				case  UmlPackage::PROPERTY_ASSOCIATIONEND: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Property>(container);
					return this->createProperty_in_AssociationEnd(castedContainer);
				}
				//Property has class as a containment
				case  UmlPackage::PROPERTY_CLASS: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Class>(container);
					return this->createProperty_in_Class(castedContainer);
				}
				//Property has datatype as a containment
				case  UmlPackage::PROPERTY_DATATYPE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::DataType>(container);
					return this->createProperty_in_Datatype(castedContainer);
				}
				//Property has interface as a containment
				case  UmlPackage::PROPERTY_INTERFACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Interface>(container);
					return this->createProperty_in_Interface(castedContainer);
				}
				//Property has owningAssociation as a containment
				case  UmlPackage::PROPERTY_OWNINGASSOCIATION: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Association>(container);
					return this->createProperty_in_OwningAssociation(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::PROTOCOLCONFORMANCE:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::ProtocolStateMachine>(container);
			assert(castedContainer);
			return std::shared_ptr<ProtocolConformance>(this->createProtocolConformance_in_SpecificMachine(castedContainer));
		}
		case UmlPackage::PROTOCOLSTATEMACHINE:
		{
			switch(referenceID)
			{
				//ProtocolStateMachine has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createProtocolStateMachine_in_Namespace(castedContainer);
				}
				//ProtocolStateMachine has package as a containment
				case  UmlPackage::TYPE_PACKAGE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
					return this->createProtocolStateMachine_in_Package(castedContainer);
				}
				//ProtocolStateMachine has owner as a containment
				case  UmlPackage::ELEMENT_OWNER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
					return this->createProtocolStateMachine_in_Owner(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::PROTOCOLTRANSITION:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::Region>(container);
			assert(castedContainer);
			return std::shared_ptr<ProtocolTransition>(this->createProtocolTransition_in_Container(castedContainer));
		}
		case UmlPackage::PSEUDOSTATE:
		{
			switch(referenceID)
			{
				//Pseudostate has state as a containment
				case  UmlPackage::PSEUDOSTATE_STATE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::State>(container);
					return this->createPseudostate_in_State(castedContainer);
				}
				//Pseudostate has stateMachine as a containment
				case  UmlPackage::PSEUDOSTATE_STATEMACHINE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StateMachine>(container);
					return this->createPseudostate_in_StateMachine(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::QUALIFIERVALUE:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
			assert(castedContainer);
			return std::shared_ptr<QualifierValue>(this->createQualifierValue_in_Owner(castedContainer));
		}
		case UmlPackage::RAISEEXCEPTIONACTION:
		{
			switch(referenceID)
			{
				//RaiseExceptionAction has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createRaiseExceptionAction_in_Activity(castedContainer);
				}
				//RaiseExceptionAction has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createRaiseExceptionAction_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::READEXTENTACTION:
		{
			switch(referenceID)
			{
				//ReadExtentAction has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createReadExtentAction_in_Activity(castedContainer);
				}
				//ReadExtentAction has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createReadExtentAction_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::READISCLASSIFIEDOBJECTACTION:
		{
			switch(referenceID)
			{
				//ReadIsClassifiedObjectAction has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createReadIsClassifiedObjectAction_in_Activity(castedContainer);
				}
				//ReadIsClassifiedObjectAction has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createReadIsClassifiedObjectAction_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::READLINKACTION:
		{
			switch(referenceID)
			{
				//ReadLinkAction has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createReadLinkAction_in_Activity(castedContainer);
				}
				//ReadLinkAction has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createReadLinkAction_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::READLINKOBJECTENDACTION:
		{
			switch(referenceID)
			{
				//ReadLinkObjectEndAction has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createReadLinkObjectEndAction_in_Activity(castedContainer);
				}
				//ReadLinkObjectEndAction has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createReadLinkObjectEndAction_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::READLINKOBJECTENDQUALIFIERACTION:
		{
			switch(referenceID)
			{
				//ReadLinkObjectEndQualifierAction has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createReadLinkObjectEndQualifierAction_in_Activity(castedContainer);
				}
				//ReadLinkObjectEndQualifierAction has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createReadLinkObjectEndQualifierAction_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::READSELFACTION:
		{
			switch(referenceID)
			{
				//ReadSelfAction has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createReadSelfAction_in_Activity(castedContainer);
				}
				//ReadSelfAction has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createReadSelfAction_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::READSTRUCTURALFEATUREACTION:
		{
			switch(referenceID)
			{
				//ReadStructuralFeatureAction has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createReadStructuralFeatureAction_in_Activity(castedContainer);
				}
				//ReadStructuralFeatureAction has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createReadStructuralFeatureAction_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::READVARIABLEACTION:
		{
			switch(referenceID)
			{
				//ReadVariableAction has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createReadVariableAction_in_Activity(castedContainer);
				}
				//ReadVariableAction has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createReadVariableAction_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::REALIZATION:
		{
			switch(referenceID)
			{
				//Realization has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createRealization_in_Namespace(castedContainer);
				}
				//Realization has owningTemplateParameter as a containment
				case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
					return this->createRealization_in_OwningTemplateParameter(castedContainer);
				}
				//Realization has owner as a containment
				case  UmlPackage::ELEMENT_OWNER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
					return this->createRealization_in_Owner(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::RECEPTION:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
			assert(castedContainer);
			return std::shared_ptr<Reception>(this->createReception_in_Namespace(castedContainer));
		}
		case UmlPackage::RECLASSIFYOBJECTACTION:
		{
			switch(referenceID)
			{
				//ReclassifyObjectAction has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createReclassifyObjectAction_in_Activity(castedContainer);
				}
				//ReclassifyObjectAction has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createReclassifyObjectAction_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::REDEFINABLETEMPLATESIGNATURE:
		{
			switch(referenceID)
			{
				//RedefinableTemplateSignature has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createRedefinableTemplateSignature_in_Namespace(castedContainer);
				}
				//RedefinableTemplateSignature has template as a containment
				case  UmlPackage::TEMPLATESIGNATURE_TEMPLATE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::TemplateableElement>(container);
					return this->createRedefinableTemplateSignature_in_Template(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::REDUCEACTION:
		{
			switch(referenceID)
			{
				//ReduceAction has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createReduceAction_in_Activity(castedContainer);
				}
				//ReduceAction has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createReduceAction_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::REGION:
		{
			switch(referenceID)
			{
				//Region has state as a containment
				case  UmlPackage::REGION_STATE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::State>(container);
					return this->createRegion_in_State(castedContainer);
				}
				//Region has stateMachine as a containment
				case  UmlPackage::REGION_STATEMACHINE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StateMachine>(container);
					return this->createRegion_in_StateMachine(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::REMOVESTRUCTURALFEATUREVALUEACTION:
		{
			switch(referenceID)
			{
				//RemoveStructuralFeatureValueAction has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createRemoveStructuralFeatureValueAction_in_Activity(castedContainer);
				}
				//RemoveStructuralFeatureValueAction has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createRemoveStructuralFeatureValueAction_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::REMOVEVARIABLEVALUEACTION:
		{
			switch(referenceID)
			{
				//RemoveVariableValueAction has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createRemoveVariableValueAction_in_Activity(castedContainer);
				}
				//RemoveVariableValueAction has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createRemoveVariableValueAction_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::REPLYACTION:
		{
			switch(referenceID)
			{
				//ReplyAction has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createReplyAction_in_Activity(castedContainer);
				}
				//ReplyAction has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createReplyAction_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::SENDOBJECTACTION:
		{
			switch(referenceID)
			{
				//SendObjectAction has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createSendObjectAction_in_Activity(castedContainer);
				}
				//SendObjectAction has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createSendObjectAction_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::SENDSIGNALACTION:
		{
			switch(referenceID)
			{
				//SendSignalAction has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createSendSignalAction_in_Activity(castedContainer);
				}
				//SendSignalAction has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createSendSignalAction_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::SEQUENCENODE:
		{
			switch(referenceID)
			{
				//SequenceNode has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createSequenceNode_in_Activity(castedContainer);
				}
				//SequenceNode has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createSequenceNode_in_InStructuredNode(castedContainer);
				}
				//SequenceNode has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createSequenceNode_in_Namespace(castedContainer);
				}
				//SequenceNode has inActivity as a containment
				case  UmlPackage::ACTIVITYGROUP_INACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createSequenceNode_in_InActivity(castedContainer);
				}
				//SequenceNode has superGroup as a containment
				case  UmlPackage::ACTIVITYGROUP_SUPERGROUP: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::ActivityGroup>(container);
					return this->createSequenceNode_in_SuperGroup(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::SIGNAL:
		{
			switch(referenceID)
			{
				//Signal has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createSignal_in_Namespace(castedContainer);
				}
				//Signal has package as a containment
				case  UmlPackage::TYPE_PACKAGE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
					return this->createSignal_in_Package(castedContainer);
				}
				//Signal has owner as a containment
				case  UmlPackage::ELEMENT_OWNER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
					return this->createSignal_in_Owner(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::SIGNALEVENT:
		{
			switch(referenceID)
			{
				//SignalEvent has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createSignalEvent_in_Namespace(castedContainer);
				}
				//SignalEvent has owningTemplateParameter as a containment
				case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
					return this->createSignalEvent_in_OwningTemplateParameter(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::SLOT:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::InstanceSpecification>(container);
			assert(castedContainer);
			return std::shared_ptr<Slot>(this->createSlot_in_OwningInstance(castedContainer));
		}
		case UmlPackage::STARTCLASSIFIERBEHAVIORACTION:
		{
			switch(referenceID)
			{
				//StartClassifierBehaviorAction has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createStartClassifierBehaviorAction_in_Activity(castedContainer);
				}
				//StartClassifierBehaviorAction has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createStartClassifierBehaviorAction_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::STARTOBJECTBEHAVIORACTION:
		{
			switch(referenceID)
			{
				//StartObjectBehaviorAction has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createStartObjectBehaviorAction_in_Activity(castedContainer);
				}
				//StartObjectBehaviorAction has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createStartObjectBehaviorAction_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::STATE:
		{
			switch(referenceID)
			{
				//State has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createState_in_Namespace(castedContainer);
				}
				//State has container as a containment
				case  UmlPackage::VERTEX_CONTAINER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Region>(container);
					return this->createState_in_Container(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::STATEINVARIANT:
		{
			switch(referenceID)
			{
				//StateInvariant has enclosingInteraction as a containment
				case  UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGINTERACTION: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Interaction>(container);
					return this->createStateInvariant_in_EnclosingInteraction(castedContainer);
				}
				//StateInvariant has enclosingOperand as a containment
				case  UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGOPERAND: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::InteractionOperand>(container);
					return this->createStateInvariant_in_EnclosingOperand(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::STATEMACHINE:
		{
			switch(referenceID)
			{
				//StateMachine has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createStateMachine_in_Namespace(castedContainer);
				}
				//StateMachine has package as a containment
				case  UmlPackage::TYPE_PACKAGE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
					return this->createStateMachine_in_Package(castedContainer);
				}
				//StateMachine has owner as a containment
				case  UmlPackage::ELEMENT_OWNER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
					return this->createStateMachine_in_Owner(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::STEREOTYPE:
		{
			switch(referenceID)
			{
				//Stereotype has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createStereotype_in_Namespace(castedContainer);
				}
				//Stereotype has package as a containment
				case  UmlPackage::TYPE_PACKAGE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
					return this->createStereotype_in_Package(castedContainer);
				}
				//Stereotype has owner as a containment
				case  UmlPackage::ELEMENT_OWNER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
					return this->createStereotype_in_Owner(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::STRINGEXPRESSION:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::StringExpression>(container);
			assert(castedContainer);
			return std::shared_ptr<StringExpression>(this->createStringExpression_in_OwningExpression(castedContainer));
		}
		case UmlPackage::STRUCTUREDACTIVITYNODE:
		{
			switch(referenceID)
			{
				//StructuredActivityNode has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createStructuredActivityNode_in_Activity(castedContainer);
				}
				//StructuredActivityNode has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createStructuredActivityNode_in_InStructuredNode(castedContainer);
				}
				//StructuredActivityNode has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createStructuredActivityNode_in_Namespace(castedContainer);
				}
				//StructuredActivityNode has inActivity as a containment
				case  UmlPackage::ACTIVITYGROUP_INACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createStructuredActivityNode_in_InActivity(castedContainer);
				}
				//StructuredActivityNode has superGroup as a containment
				case  UmlPackage::ACTIVITYGROUP_SUPERGROUP: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::ActivityGroup>(container);
					return this->createStructuredActivityNode_in_SuperGroup(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::SUBSTITUTION:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::Classifier>(container);
			assert(castedContainer);
			return std::shared_ptr<Substitution>(this->createSubstitution_in_SubstitutingClassifier(castedContainer));
		}
		case UmlPackage::TEMPLATEBINDING:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::TemplateableElement>(container);
			assert(castedContainer);
			return std::shared_ptr<TemplateBinding>(this->createTemplateBinding_in_BoundElement(castedContainer));
		}
		case UmlPackage::TEMPLATEPARAMETER:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::TemplateSignature>(container);
			assert(castedContainer);
			return std::shared_ptr<TemplateParameter>(this->createTemplateParameter_in_Signature(castedContainer));
		}
		case UmlPackage::TEMPLATEPARAMETERSUBSTITUTION:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::TemplateBinding>(container);
			assert(castedContainer);
			return std::shared_ptr<TemplateParameterSubstitution>(this->createTemplateParameterSubstitution_in_TemplateBinding(castedContainer));
		}
		case UmlPackage::TEMPLATESIGNATURE:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::TemplateableElement>(container);
			assert(castedContainer);
			return std::shared_ptr<TemplateSignature>(this->createTemplateSignature_in_Template(castedContainer));
		}
		case UmlPackage::TESTIDENTITYACTION:
		{
			switch(referenceID)
			{
				//TestIdentityAction has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createTestIdentityAction_in_Activity(castedContainer);
				}
				//TestIdentityAction has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createTestIdentityAction_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::TIMECONSTRAINT:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
			assert(castedContainer);
			return std::shared_ptr<TimeConstraint>(this->createTimeConstraint_in_Context(castedContainer));
		}
		case UmlPackage::TIMEEVENT:
		{
			switch(referenceID)
			{
				//TimeEvent has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createTimeEvent_in_Namespace(castedContainer);
				}
				//TimeEvent has owningTemplateParameter as a containment
				case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
					return this->createTimeEvent_in_OwningTemplateParameter(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::TIMEEXPRESSION:
		{
			switch(referenceID)
			{
				//TimeExpression has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createTimeExpression_in_Namespace(castedContainer);
				}
				//TimeExpression has owningTemplateParameter as a containment
				case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
					return this->createTimeExpression_in_OwningTemplateParameter(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::TIMEINTERVAL:
		{
			switch(referenceID)
			{
				//TimeInterval has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createTimeInterval_in_Namespace(castedContainer);
				}
				//TimeInterval has owningTemplateParameter as a containment
				case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
					return this->createTimeInterval_in_OwningTemplateParameter(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::TIMEOBSERVATION:
		{
			switch(referenceID)
			{
				//TimeObservation has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createTimeObservation_in_Namespace(castedContainer);
				}
				//TimeObservation has owningTemplateParameter as a containment
				case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
					return this->createTimeObservation_in_OwningTemplateParameter(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::TRANSITION:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::Region>(container);
			assert(castedContainer);
			return std::shared_ptr<Transition>(this->createTransition_in_Container(castedContainer));
		}
		case UmlPackage::TRIGGER:
		{
			auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
			assert(castedContainer);
			return std::shared_ptr<Trigger>(this->createTrigger_in_Namespace(castedContainer));
		}
		case UmlPackage::UNMARSHALLACTION:
		{
			switch(referenceID)
			{
				//UnmarshallAction has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createUnmarshallAction_in_Activity(castedContainer);
				}
				//UnmarshallAction has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createUnmarshallAction_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::USAGE:
		{
			switch(referenceID)
			{
				//Usage has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createUsage_in_Namespace(castedContainer);
				}
				//Usage has owningTemplateParameter as a containment
				case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
					return this->createUsage_in_OwningTemplateParameter(castedContainer);
				}
				//Usage has owner as a containment
				case  UmlPackage::ELEMENT_OWNER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
					return this->createUsage_in_Owner(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::USECASE:
		{
			switch(referenceID)
			{
				//UseCase has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createUseCase_in_Namespace(castedContainer);
				}
				//UseCase has package as a containment
				case  UmlPackage::TYPE_PACKAGE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
					return this->createUseCase_in_Package(castedContainer);
				}
				//UseCase has owner as a containment
				case  UmlPackage::ELEMENT_OWNER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
					return this->createUseCase_in_Owner(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::VALUEPIN:
		{
			switch(referenceID)
			{
				//ValuePin has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createValuePin_in_Activity(castedContainer);
				}
				//ValuePin has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createValuePin_in_InStructuredNode(castedContainer);
				}
				//ValuePin has namespace as a containment
				case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
					return this->createValuePin_in_Namespace(castedContainer);
				}
				//ValuePin has owner as a containment
				case  UmlPackage::ELEMENT_OWNER: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
					return this->createValuePin_in_Owner(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::VALUESPECIFICATIONACTION:
		{
			switch(referenceID)
			{
				//ValueSpecificationAction has activity as a containment
				case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createValueSpecificationAction_in_Activity(castedContainer);
				}
				//ValueSpecificationAction has inStructuredNode as a containment
				case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createValueSpecificationAction_in_InStructuredNode(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}
		case UmlPackage::VARIABLE:
		{
			switch(referenceID)
			{
				//Variable has activityScope as a containment
				case  UmlPackage::VARIABLE_ACTIVITYSCOPE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
					return this->createVariable_in_ActivityScope(castedContainer);
				}
				//Variable has scope as a containment
				case  UmlPackage::VARIABLE_SCOPE: 
				{
					auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
					return this->createVariable_in_Scope(castedContainer);
				}
				default:
					std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
		}
		}

	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << classID <<" not found" << std::endl;
	}
	return nullptr;
}


std::shared_ptr<ecore::EObject> UmlFactoryImpl::create(ecore::EClass* _class, std::shared_ptr<EObject> _container /* = nullptr*/) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}

	std::string _className = _class->eClass()->getName();
	return create(_className, _container);
}


std::shared_ptr<ecore::EObject> UmlFactoryImpl::create(std::string _className, std::shared_ptr<EObject> _container/* = nullptr*/, const unsigned int referenceID) const
{
	auto iter = m_idMap.find(_className);
	
	std::shared_ptr<ecore::EObject> _createdObject;
	if(iter != m_idMap.end())
    {
		//get the ID
        unsigned int id =iter->second;
		return create(id, _container, referenceID);
    }

    return nullptr;
}




std::shared_ptr<Abstraction> UmlFactoryImpl::createAbstraction_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Abstraction> element(new AbstractionImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<Abstraction> UmlFactoryImpl::createAbstraction_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Abstraction> element(new AbstractionImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock()){
		wp->setOwnedParameteredElement(element);
	}
	return element;
}
std::shared_ptr<Abstraction> UmlFactoryImpl::createAbstraction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Abstraction> element(new AbstractionImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<AcceptCallAction> UmlFactoryImpl::createAcceptCallAction_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<AcceptCallAction> element(new AcceptCallActionImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<AcceptCallAction> UmlFactoryImpl::createAcceptCallAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<AcceptCallAction> element(new AcceptCallActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<AcceptEventAction> UmlFactoryImpl::createAcceptEventAction_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<AcceptEventAction> element(new AcceptEventActionImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<AcceptEventAction> UmlFactoryImpl::createAcceptEventAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<AcceptEventAction> element(new AcceptEventActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<ActionExecutionSpecification> UmlFactoryImpl::createActionExecutionSpecification_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction) const
{
	std::shared_ptr<ActionExecutionSpecification> element(new ActionExecutionSpecificationImpl(par_enclosingInteraction));
	if(auto wp = par_enclosingInteraction.lock()){
    	wp->getFragment()->push_back(element);
	}
	return element;
}
std::shared_ptr<ActionExecutionSpecification> UmlFactoryImpl::createActionExecutionSpecification_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand) const
{
	std::shared_ptr<ActionExecutionSpecification> element(new ActionExecutionSpecificationImpl(par_enclosingOperand));
	if(auto wp = par_enclosingOperand.lock()){
    	wp->getFragment()->push_back(element);
	}
	return element;
}


std::shared_ptr<ActionInputPin> UmlFactoryImpl::createActionInputPin_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ActionInputPin> element(new ActionInputPinImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<ActionInputPin> UmlFactoryImpl::createActionInputPin_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ActionInputPin> element(new ActionInputPinImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<ActionInputPin> UmlFactoryImpl::createActionInputPin_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ActionInputPin> element(new ActionInputPinImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<ActionInputPin> UmlFactoryImpl::createActionInputPin_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ActionInputPin> element(new ActionInputPinImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<Activity> UmlFactoryImpl::createActivity_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Activity> element(new ActivityImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<Activity> UmlFactoryImpl::createActivity_in_Package(std::shared_ptr<uml::Package > par_package) const
{
	std::shared_ptr<Activity> element(new ActivityImpl(par_package));
	if(nullptr != par_package){
    	par_package->getOwnedType()->push_back(element);
	}
	return element;
}
std::shared_ptr<Activity> UmlFactoryImpl::createActivity_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Activity> element(new ActivityImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<ActivityFinalNode> UmlFactoryImpl::createActivityFinalNode_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ActivityFinalNode> element(new ActivityFinalNodeImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<ActivityFinalNode> UmlFactoryImpl::createActivityFinalNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ActivityFinalNode> element(new ActivityFinalNodeImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<ActivityParameterNode> UmlFactoryImpl::createActivityParameterNode_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ActivityParameterNode> element(new ActivityParameterNodeImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<ActivityParameterNode> UmlFactoryImpl::createActivityParameterNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ActivityParameterNode> element(new ActivityParameterNodeImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<ActivityParameterNode> UmlFactoryImpl::createActivityParameterNode_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ActivityParameterNode> element(new ActivityParameterNodeImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}


std::shared_ptr<ActivityPartition> UmlFactoryImpl::createActivityPartition_in_SuperPartition(std::weak_ptr<uml::ActivityPartition > par_superPartition) const
{
	std::shared_ptr<ActivityPartition> element(new ActivityPartitionImpl(par_superPartition));
	if(auto wp = par_superPartition.lock()){
    	wp->getSubpartition()->push_back(element);
	}
	return element;
}


std::shared_ptr<Actor> UmlFactoryImpl::createActor_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Actor> element(new ActorImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<Actor> UmlFactoryImpl::createActor_in_Package(std::shared_ptr<uml::Package > par_package) const
{
	std::shared_ptr<Actor> element(new ActorImpl(par_package));
	if(nullptr != par_package){
    	par_package->getOwnedType()->push_back(element);
	}
	return element;
}
std::shared_ptr<Actor> UmlFactoryImpl::createActor_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Actor> element(new ActorImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<AddStructuralFeatureValueAction> UmlFactoryImpl::createAddStructuralFeatureValueAction_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<AddStructuralFeatureValueAction> element(new AddStructuralFeatureValueActionImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<AddStructuralFeatureValueAction> UmlFactoryImpl::createAddStructuralFeatureValueAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<AddStructuralFeatureValueAction> element(new AddStructuralFeatureValueActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<AddVariableValueAction> UmlFactoryImpl::createAddVariableValueAction_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<AddVariableValueAction> element(new AddVariableValueActionImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<AddVariableValueAction> UmlFactoryImpl::createAddVariableValueAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<AddVariableValueAction> element(new AddVariableValueActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<AnyReceiveEvent> UmlFactoryImpl::createAnyReceiveEvent_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<AnyReceiveEvent> element(new AnyReceiveEventImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<AnyReceiveEvent> UmlFactoryImpl::createAnyReceiveEvent_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<AnyReceiveEvent> element(new AnyReceiveEventImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock()){
		wp->setOwnedParameteredElement(element);
	}
	return element;
}


std::shared_ptr<Artifact> UmlFactoryImpl::createArtifact_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Artifact> element(new ArtifactImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<Artifact> UmlFactoryImpl::createArtifact_in_Package(std::shared_ptr<uml::Package > par_package) const
{
	std::shared_ptr<Artifact> element(new ArtifactImpl(par_package));
	if(nullptr != par_package){
    	par_package->getOwnedType()->push_back(element);
	}
	return element;
}
std::shared_ptr<Artifact> UmlFactoryImpl::createArtifact_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Artifact> element(new ArtifactImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<Association> UmlFactoryImpl::createAssociation_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Association> element(new AssociationImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<Association> UmlFactoryImpl::createAssociation_in_Package(std::shared_ptr<uml::Package > par_package) const
{
	std::shared_ptr<Association> element(new AssociationImpl(par_package));
	if(nullptr != par_package){
    	par_package->getOwnedType()->push_back(element);
	}
	return element;
}
std::shared_ptr<Association> UmlFactoryImpl::createAssociation_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Association> element(new AssociationImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<AssociationClass> UmlFactoryImpl::createAssociationClass_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<AssociationClass> element(new AssociationClassImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<AssociationClass> UmlFactoryImpl::createAssociationClass_in_Package(std::shared_ptr<uml::Package > par_package) const
{
	std::shared_ptr<AssociationClass> element(new AssociationClassImpl(par_package));
	if(nullptr != par_package){
    	par_package->getOwnedType()->push_back(element);
	}
	return element;
}
std::shared_ptr<AssociationClass> UmlFactoryImpl::createAssociationClass_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<AssociationClass> element(new AssociationClassImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<BehaviorExecutionSpecification> UmlFactoryImpl::createBehaviorExecutionSpecification_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction) const
{
	std::shared_ptr<BehaviorExecutionSpecification> element(new BehaviorExecutionSpecificationImpl(par_enclosingInteraction));
	if(auto wp = par_enclosingInteraction.lock()){
    	wp->getFragment()->push_back(element);
	}
	return element;
}
std::shared_ptr<BehaviorExecutionSpecification> UmlFactoryImpl::createBehaviorExecutionSpecification_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand) const
{
	std::shared_ptr<BehaviorExecutionSpecification> element(new BehaviorExecutionSpecificationImpl(par_enclosingOperand));
	if(auto wp = par_enclosingOperand.lock()){
    	wp->getFragment()->push_back(element);
	}
	return element;
}


std::shared_ptr<BroadcastSignalAction> UmlFactoryImpl::createBroadcastSignalAction_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<BroadcastSignalAction> element(new BroadcastSignalActionImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<BroadcastSignalAction> UmlFactoryImpl::createBroadcastSignalAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<BroadcastSignalAction> element(new BroadcastSignalActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<CallBehaviorAction> UmlFactoryImpl::createCallBehaviorAction_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<CallBehaviorAction> element(new CallBehaviorActionImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<CallBehaviorAction> UmlFactoryImpl::createCallBehaviorAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<CallBehaviorAction> element(new CallBehaviorActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<CallEvent> UmlFactoryImpl::createCallEvent_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<CallEvent> element(new CallEventImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<CallEvent> UmlFactoryImpl::createCallEvent_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<CallEvent> element(new CallEventImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock()){
		wp->setOwnedParameteredElement(element);
	}
	return element;
}


std::shared_ptr<CallOperationAction> UmlFactoryImpl::createCallOperationAction_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<CallOperationAction> element(new CallOperationActionImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<CallOperationAction> UmlFactoryImpl::createCallOperationAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<CallOperationAction> element(new CallOperationActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<CentralBufferNode> UmlFactoryImpl::createCentralBufferNode_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<CentralBufferNode> element(new CentralBufferNodeImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<CentralBufferNode> UmlFactoryImpl::createCentralBufferNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<CentralBufferNode> element(new CentralBufferNodeImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<CentralBufferNode> UmlFactoryImpl::createCentralBufferNode_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<CentralBufferNode> element(new CentralBufferNodeImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}


std::shared_ptr<ChangeEvent> UmlFactoryImpl::createChangeEvent_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ChangeEvent> element(new ChangeEventImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<ChangeEvent> UmlFactoryImpl::createChangeEvent_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<ChangeEvent> element(new ChangeEventImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock()){
		wp->setOwnedParameteredElement(element);
	}
	return element;
}


std::shared_ptr<Class> UmlFactoryImpl::createClass_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Class> element(new ClassImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<Class> UmlFactoryImpl::createClass_in_Package(std::shared_ptr<uml::Package > par_package) const
{
	std::shared_ptr<Class> element(new ClassImpl(par_package));
	if(nullptr != par_package){
    	par_package->getOwnedType()->push_back(element);
	}
	return element;
}
std::shared_ptr<Class> UmlFactoryImpl::createClass_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Class> element(new ClassImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<ClassifierTemplateParameter> UmlFactoryImpl::createClassifierTemplateParameter_in_Signature(std::weak_ptr<uml::TemplateSignature > par_signature) const
{
	std::shared_ptr<ClassifierTemplateParameter> element(new ClassifierTemplateParameterImpl(par_signature));
	if(auto wp = par_signature.lock()){
    	wp->getOwnedParameter()->push_back(element);
	}
	return element;
}


std::shared_ptr<Clause> UmlFactoryImpl::createClause_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Clause> element(new ClauseImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<ClearAssociationAction> UmlFactoryImpl::createClearAssociationAction_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ClearAssociationAction> element(new ClearAssociationActionImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<ClearAssociationAction> UmlFactoryImpl::createClearAssociationAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ClearAssociationAction> element(new ClearAssociationActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<ClearStructuralFeatureAction> UmlFactoryImpl::createClearStructuralFeatureAction_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ClearStructuralFeatureAction> element(new ClearStructuralFeatureActionImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<ClearStructuralFeatureAction> UmlFactoryImpl::createClearStructuralFeatureAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ClearStructuralFeatureAction> element(new ClearStructuralFeatureActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<ClearVariableAction> UmlFactoryImpl::createClearVariableAction_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ClearVariableAction> element(new ClearVariableActionImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<ClearVariableAction> UmlFactoryImpl::createClearVariableAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ClearVariableAction> element(new ClearVariableActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<Collaboration> UmlFactoryImpl::createCollaboration_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Collaboration> element(new CollaborationImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<Collaboration> UmlFactoryImpl::createCollaboration_in_Package(std::shared_ptr<uml::Package > par_package) const
{
	std::shared_ptr<Collaboration> element(new CollaborationImpl(par_package));
	if(nullptr != par_package){
    	par_package->getOwnedType()->push_back(element);
	}
	return element;
}
std::shared_ptr<Collaboration> UmlFactoryImpl::createCollaboration_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Collaboration> element(new CollaborationImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<CollaborationUse> UmlFactoryImpl::createCollaborationUse_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<CollaborationUse> element(new CollaborationUseImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}


std::shared_ptr<CombinedFragment> UmlFactoryImpl::createCombinedFragment_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction) const
{
	std::shared_ptr<CombinedFragment> element(new CombinedFragmentImpl(par_enclosingInteraction));
	if(auto wp = par_enclosingInteraction.lock()){
    	wp->getFragment()->push_back(element);
	}
	return element;
}
std::shared_ptr<CombinedFragment> UmlFactoryImpl::createCombinedFragment_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand) const
{
	std::shared_ptr<CombinedFragment> element(new CombinedFragmentImpl(par_enclosingOperand));
	if(auto wp = par_enclosingOperand.lock()){
    	wp->getFragment()->push_back(element);
	}
	return element;
}


std::shared_ptr<Comment> UmlFactoryImpl::createComment_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Comment> element(new CommentImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedComment()->push_back(element);
	}
	return element;
}


std::shared_ptr<CommunicationPath> UmlFactoryImpl::createCommunicationPath_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<CommunicationPath> element(new CommunicationPathImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<CommunicationPath> UmlFactoryImpl::createCommunicationPath_in_Package(std::shared_ptr<uml::Package > par_package) const
{
	std::shared_ptr<CommunicationPath> element(new CommunicationPathImpl(par_package));
	if(nullptr != par_package){
    	par_package->getOwnedType()->push_back(element);
	}
	return element;
}
std::shared_ptr<CommunicationPath> UmlFactoryImpl::createCommunicationPath_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<CommunicationPath> element(new CommunicationPathImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<Component> UmlFactoryImpl::createComponent_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Component> element(new ComponentImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<Component> UmlFactoryImpl::createComponent_in_Package(std::shared_ptr<uml::Package > par_package) const
{
	std::shared_ptr<Component> element(new ComponentImpl(par_package));
	if(nullptr != par_package){
    	par_package->getOwnedType()->push_back(element);
	}
	return element;
}
std::shared_ptr<Component> UmlFactoryImpl::createComponent_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Component> element(new ComponentImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<ComponentRealization> UmlFactoryImpl::createComponentRealization_in_Abstraction(std::weak_ptr<uml::Component > par_abstraction) const
{
	std::shared_ptr<ComponentRealization> element(new ComponentRealizationImpl(par_abstraction));
	if(auto wp = par_abstraction.lock()){
    	wp->getRealization()->push_back(element);
	}
	return element;
}


std::shared_ptr<ConditionalNode> UmlFactoryImpl::createConditionalNode_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ConditionalNode> element(new ConditionalNodeImpl(par_activity, UmlPackage::ACTIVITYNODE_ACTIVITY));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<ConditionalNode> UmlFactoryImpl::createConditionalNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ConditionalNode> element(new ConditionalNodeImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<ConditionalNode> UmlFactoryImpl::createConditionalNode_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ConditionalNode> element(new ConditionalNodeImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<ConditionalNode> UmlFactoryImpl::createConditionalNode_in_InActivity(std::shared_ptr<uml::Activity > par_inActivity) const
{
	std::shared_ptr<ConditionalNode> element(new ConditionalNodeImpl(par_inActivity, UmlPackage::ACTIVITYGROUP_INACTIVITY));
	if(nullptr != par_inActivity){
    	par_inActivity->getGroup()->push_back(element);
	}
	return element;
}
std::shared_ptr<ConditionalNode> UmlFactoryImpl::createConditionalNode_in_SuperGroup(std::shared_ptr<uml::ActivityGroup > par_superGroup) const
{
	std::shared_ptr<ConditionalNode> element(new ConditionalNodeImpl(par_superGroup));
	if(nullptr != par_superGroup){
    	par_superGroup->getSubgroup()->push_back(element);
	}
	return element;
}


std::shared_ptr<ConnectableElementTemplateParameter> UmlFactoryImpl::createConnectableElementTemplateParameter_in_Signature(std::weak_ptr<uml::TemplateSignature > par_signature) const
{
	std::shared_ptr<ConnectableElementTemplateParameter> element(new ConnectableElementTemplateParameterImpl(par_signature));
	if(auto wp = par_signature.lock()){
    	wp->getOwnedParameter()->push_back(element);
	}
	return element;
}


std::shared_ptr<ConnectionPointReference> UmlFactoryImpl::createConnectionPointReference_in_State(std::weak_ptr<uml::State > par_state) const
{
	std::shared_ptr<ConnectionPointReference> element(new ConnectionPointReferenceImpl(par_state));
	if(auto wp = par_state.lock()){
    	wp->getConnection()->push_back(element);
	}
	return element;
}


std::shared_ptr<Connector> UmlFactoryImpl::createConnector_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Connector> element(new ConnectorImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}


std::shared_ptr<ConnectorEnd> UmlFactoryImpl::createConnectorEnd_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ConnectorEnd> element(new ConnectorEndImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<ConsiderIgnoreFragment> UmlFactoryImpl::createConsiderIgnoreFragment_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction) const
{
	std::shared_ptr<ConsiderIgnoreFragment> element(new ConsiderIgnoreFragmentImpl(par_enclosingInteraction));
	if(auto wp = par_enclosingInteraction.lock()){
    	wp->getFragment()->push_back(element);
	}
	return element;
}
std::shared_ptr<ConsiderIgnoreFragment> UmlFactoryImpl::createConsiderIgnoreFragment_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand) const
{
	std::shared_ptr<ConsiderIgnoreFragment> element(new ConsiderIgnoreFragmentImpl(par_enclosingOperand));
	if(auto wp = par_enclosingOperand.lock()){
    	wp->getFragment()->push_back(element);
	}
	return element;
}


std::shared_ptr<Constraint> UmlFactoryImpl::createConstraint_in_Context(std::weak_ptr<uml::Namespace > par_context) const
{
	std::shared_ptr<Constraint> element(new ConstraintImpl(par_context));
	if(auto wp = par_context.lock()){
    	wp->getOwnedRule()->push_back(element);
	}
	return element;
}


std::shared_ptr<Continuation> UmlFactoryImpl::createContinuation_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction) const
{
	std::shared_ptr<Continuation> element(new ContinuationImpl(par_enclosingInteraction));
	if(auto wp = par_enclosingInteraction.lock()){
    	wp->getFragment()->push_back(element);
	}
	return element;
}
std::shared_ptr<Continuation> UmlFactoryImpl::createContinuation_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand) const
{
	std::shared_ptr<Continuation> element(new ContinuationImpl(par_enclosingOperand));
	if(auto wp = par_enclosingOperand.lock()){
    	wp->getFragment()->push_back(element);
	}
	return element;
}


std::shared_ptr<ControlFlow> UmlFactoryImpl::createControlFlow_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ControlFlow> element(new ControlFlowImpl(par_activity));
	if(auto wp = par_activity.lock()){
    	wp->getEdge()->push_back(element);
	}
	return element;
}
std::shared_ptr<ControlFlow> UmlFactoryImpl::createControlFlow_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ControlFlow> element(new ControlFlowImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getEdge()->push_back(element);
	}
	return element;
}


std::shared_ptr<CreateLinkAction> UmlFactoryImpl::createCreateLinkAction_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<CreateLinkAction> element(new CreateLinkActionImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<CreateLinkAction> UmlFactoryImpl::createCreateLinkAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<CreateLinkAction> element(new CreateLinkActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<CreateLinkObjectAction> UmlFactoryImpl::createCreateLinkObjectAction_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<CreateLinkObjectAction> element(new CreateLinkObjectActionImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<CreateLinkObjectAction> UmlFactoryImpl::createCreateLinkObjectAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<CreateLinkObjectAction> element(new CreateLinkObjectActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<CreateObjectAction> UmlFactoryImpl::createCreateObjectAction_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<CreateObjectAction> element(new CreateObjectActionImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<CreateObjectAction> UmlFactoryImpl::createCreateObjectAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<CreateObjectAction> element(new CreateObjectActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<DataStoreNode> UmlFactoryImpl::createDataStoreNode_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<DataStoreNode> element(new DataStoreNodeImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<DataStoreNode> UmlFactoryImpl::createDataStoreNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<DataStoreNode> element(new DataStoreNodeImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<DataStoreNode> UmlFactoryImpl::createDataStoreNode_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<DataStoreNode> element(new DataStoreNodeImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}


std::shared_ptr<DataType> UmlFactoryImpl::createDataType_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<DataType> element(new DataTypeImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<DataType> UmlFactoryImpl::createDataType_in_Package(std::shared_ptr<uml::Package > par_package) const
{
	std::shared_ptr<DataType> element(new DataTypeImpl(par_package));
	if(nullptr != par_package){
    	par_package->getOwnedType()->push_back(element);
	}
	return element;
}
std::shared_ptr<DataType> UmlFactoryImpl::createDataType_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<DataType> element(new DataTypeImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<DecisionNode> UmlFactoryImpl::createDecisionNode_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<DecisionNode> element(new DecisionNodeImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<DecisionNode> UmlFactoryImpl::createDecisionNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<DecisionNode> element(new DecisionNodeImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<Dependency> UmlFactoryImpl::createDependency_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Dependency> element(new DependencyImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<Dependency> UmlFactoryImpl::createDependency_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Dependency> element(new DependencyImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock()){
		wp->setOwnedParameteredElement(element);
	}
	return element;
}
std::shared_ptr<Dependency> UmlFactoryImpl::createDependency_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Dependency> element(new DependencyImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<Deployment> UmlFactoryImpl::createDeployment_in_Location(std::weak_ptr<uml::DeploymentTarget > par_location) const
{
	std::shared_ptr<Deployment> element(new DeploymentImpl(par_location));
	if(auto wp = par_location.lock()){
    	wp->getDeployment()->push_back(element);
	}
	return element;
}


std::shared_ptr<DeploymentSpecification> UmlFactoryImpl::createDeploymentSpecification_in_Deployment(std::weak_ptr<uml::Deployment > par_deployment) const
{
	std::shared_ptr<DeploymentSpecification> element(new DeploymentSpecificationImpl(par_deployment));
	if(auto wp = par_deployment.lock()){
    	wp->getConfiguration()->push_back(element);
	}
	return element;
}


std::shared_ptr<DestroyLinkAction> UmlFactoryImpl::createDestroyLinkAction_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<DestroyLinkAction> element(new DestroyLinkActionImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<DestroyLinkAction> UmlFactoryImpl::createDestroyLinkAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<DestroyLinkAction> element(new DestroyLinkActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<DestroyObjectAction> UmlFactoryImpl::createDestroyObjectAction_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<DestroyObjectAction> element(new DestroyObjectActionImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<DestroyObjectAction> UmlFactoryImpl::createDestroyObjectAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<DestroyObjectAction> element(new DestroyObjectActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<DestructionOccurrenceSpecification> UmlFactoryImpl::createDestructionOccurrenceSpecification_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction) const
{
	std::shared_ptr<DestructionOccurrenceSpecification> element(new DestructionOccurrenceSpecificationImpl(par_enclosingInteraction));
	if(auto wp = par_enclosingInteraction.lock()){
    	wp->getFragment()->push_back(element);
	}
	return element;
}
std::shared_ptr<DestructionOccurrenceSpecification> UmlFactoryImpl::createDestructionOccurrenceSpecification_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand) const
{
	std::shared_ptr<DestructionOccurrenceSpecification> element(new DestructionOccurrenceSpecificationImpl(par_enclosingOperand));
	if(auto wp = par_enclosingOperand.lock()){
    	wp->getFragment()->push_back(element);
	}
	return element;
}
std::shared_ptr<DestructionOccurrenceSpecification> UmlFactoryImpl::createDestructionOccurrenceSpecification_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<DestructionOccurrenceSpecification> element(new DestructionOccurrenceSpecificationImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}


std::shared_ptr<Device> UmlFactoryImpl::createDevice_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Device> element(new DeviceImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<Device> UmlFactoryImpl::createDevice_in_Package(std::shared_ptr<uml::Package > par_package) const
{
	std::shared_ptr<Device> element(new DeviceImpl(par_package));
	if(nullptr != par_package){
    	par_package->getOwnedType()->push_back(element);
	}
	return element;
}
std::shared_ptr<Device> UmlFactoryImpl::createDevice_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Device> element(new DeviceImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<Duration> UmlFactoryImpl::createDuration_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Duration> element(new DurationImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<Duration> UmlFactoryImpl::createDuration_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Duration> element(new DurationImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock()){
		wp->setOwnedParameteredElement(element);
	}
	return element;
}


std::shared_ptr<DurationConstraint> UmlFactoryImpl::createDurationConstraint_in_Context(std::weak_ptr<uml::Namespace > par_context) const
{
	std::shared_ptr<DurationConstraint> element(new DurationConstraintImpl(par_context));
	if(auto wp = par_context.lock()){
    	wp->getOwnedRule()->push_back(element);
	}
	return element;
}


std::shared_ptr<DurationInterval> UmlFactoryImpl::createDurationInterval_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<DurationInterval> element(new DurationIntervalImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<DurationInterval> UmlFactoryImpl::createDurationInterval_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<DurationInterval> element(new DurationIntervalImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock()){
		wp->setOwnedParameteredElement(element);
	}
	return element;
}


std::shared_ptr<DurationObservation> UmlFactoryImpl::createDurationObservation_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<DurationObservation> element(new DurationObservationImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<DurationObservation> UmlFactoryImpl::createDurationObservation_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<DurationObservation> element(new DurationObservationImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock()){
		wp->setOwnedParameteredElement(element);
	}
	return element;
}


std::shared_ptr<ElementImport> UmlFactoryImpl::createElementImport_in_ImportingNamespace(std::weak_ptr<uml::Namespace > par_importingNamespace) const
{
	std::shared_ptr<ElementImport> element(new ElementImportImpl(par_importingNamespace));
	if(auto wp = par_importingNamespace.lock()){
    	wp->getElementImport()->push_back(element);
	}
	return element;
}


std::shared_ptr<Enumeration> UmlFactoryImpl::createEnumeration_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Enumeration> element(new EnumerationImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<Enumeration> UmlFactoryImpl::createEnumeration_in_Package(std::shared_ptr<uml::Package > par_package) const
{
	std::shared_ptr<Enumeration> element(new EnumerationImpl(par_package));
	if(nullptr != par_package){
    	par_package->getOwnedType()->push_back(element);
	}
	return element;
}
std::shared_ptr<Enumeration> UmlFactoryImpl::createEnumeration_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Enumeration> element(new EnumerationImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<EnumerationLiteral> UmlFactoryImpl::createEnumerationLiteral_in_Enumeration(std::weak_ptr<uml::Enumeration > par_enumeration) const
{
	std::shared_ptr<EnumerationLiteral> element(new EnumerationLiteralImpl(par_enumeration));
	if(auto wp = par_enumeration.lock()){
    	wp->getOwnedLiteral()->push_back(element);
	}
	return element;
}


std::shared_ptr<ExceptionHandler> UmlFactoryImpl::createExceptionHandler_in_ProtectedNode(std::weak_ptr<uml::ExecutableNode > par_protectedNode) const
{
	std::shared_ptr<ExceptionHandler> element(new ExceptionHandlerImpl(par_protectedNode));
	if(auto wp = par_protectedNode.lock()){
    	wp->getHandler()->push_back(element);
	}
	return element;
}


std::shared_ptr<ExecutionEnvironment> UmlFactoryImpl::createExecutionEnvironment_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ExecutionEnvironment> element(new ExecutionEnvironmentImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<ExecutionEnvironment> UmlFactoryImpl::createExecutionEnvironment_in_Package(std::shared_ptr<uml::Package > par_package) const
{
	std::shared_ptr<ExecutionEnvironment> element(new ExecutionEnvironmentImpl(par_package));
	if(nullptr != par_package){
    	par_package->getOwnedType()->push_back(element);
	}
	return element;
}
std::shared_ptr<ExecutionEnvironment> UmlFactoryImpl::createExecutionEnvironment_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ExecutionEnvironment> element(new ExecutionEnvironmentImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<ExecutionOccurrenceSpecification> UmlFactoryImpl::createExecutionOccurrenceSpecification_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction) const
{
	std::shared_ptr<ExecutionOccurrenceSpecification> element(new ExecutionOccurrenceSpecificationImpl(par_enclosingInteraction));
	if(auto wp = par_enclosingInteraction.lock()){
    	wp->getFragment()->push_back(element);
	}
	return element;
}
std::shared_ptr<ExecutionOccurrenceSpecification> UmlFactoryImpl::createExecutionOccurrenceSpecification_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand) const
{
	std::shared_ptr<ExecutionOccurrenceSpecification> element(new ExecutionOccurrenceSpecificationImpl(par_enclosingOperand));
	if(auto wp = par_enclosingOperand.lock()){
    	wp->getFragment()->push_back(element);
	}
	return element;
}


std::shared_ptr<ExpansionNode> UmlFactoryImpl::createExpansionNode_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ExpansionNode> element(new ExpansionNodeImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<ExpansionNode> UmlFactoryImpl::createExpansionNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ExpansionNode> element(new ExpansionNodeImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<ExpansionNode> UmlFactoryImpl::createExpansionNode_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ExpansionNode> element(new ExpansionNodeImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}


std::shared_ptr<ExpansionRegion> UmlFactoryImpl::createExpansionRegion_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ExpansionRegion> element(new ExpansionRegionImpl(par_activity, UmlPackage::ACTIVITYNODE_ACTIVITY));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<ExpansionRegion> UmlFactoryImpl::createExpansionRegion_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ExpansionRegion> element(new ExpansionRegionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<ExpansionRegion> UmlFactoryImpl::createExpansionRegion_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ExpansionRegion> element(new ExpansionRegionImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<ExpansionRegion> UmlFactoryImpl::createExpansionRegion_in_InActivity(std::shared_ptr<uml::Activity > par_inActivity) const
{
	std::shared_ptr<ExpansionRegion> element(new ExpansionRegionImpl(par_inActivity, UmlPackage::ACTIVITYGROUP_INACTIVITY));
	if(nullptr != par_inActivity){
    	par_inActivity->getGroup()->push_back(element);
	}
	return element;
}
std::shared_ptr<ExpansionRegion> UmlFactoryImpl::createExpansionRegion_in_SuperGroup(std::shared_ptr<uml::ActivityGroup > par_superGroup) const
{
	std::shared_ptr<ExpansionRegion> element(new ExpansionRegionImpl(par_superGroup));
	if(nullptr != par_superGroup){
    	par_superGroup->getSubgroup()->push_back(element);
	}
	return element;
}


std::shared_ptr<Expression> UmlFactoryImpl::createExpression_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Expression> element(new ExpressionImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<Expression> UmlFactoryImpl::createExpression_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Expression> element(new ExpressionImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock()){
		wp->setOwnedParameteredElement(element);
	}
	return element;
}


std::shared_ptr<Extend> UmlFactoryImpl::createExtend_in_Extension(std::weak_ptr<uml::UseCase > par_extension) const
{
	std::shared_ptr<Extend> element(new ExtendImpl(par_extension));
	if(auto wp = par_extension.lock()){
    	wp->getExtend()->push_back(element);
	}
	return element;
}


std::shared_ptr<Extension> UmlFactoryImpl::createExtension_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Extension> element(new ExtensionImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<Extension> UmlFactoryImpl::createExtension_in_Package(std::shared_ptr<uml::Package > par_package) const
{
	std::shared_ptr<Extension> element(new ExtensionImpl(par_package));
	if(nullptr != par_package){
    	par_package->getOwnedType()->push_back(element);
	}
	return element;
}
std::shared_ptr<Extension> UmlFactoryImpl::createExtension_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Extension> element(new ExtensionImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<ExtensionEnd> UmlFactoryImpl::createExtensionEnd_in_AssociationEnd(std::weak_ptr<uml::Property > par_associationEnd) const
{
	std::shared_ptr<ExtensionEnd> element(new ExtensionEndImpl(par_associationEnd));
	if(auto wp = par_associationEnd.lock()){
    	wp->getQualifier()->push_back(element);
	}
	return element;
}
std::shared_ptr<ExtensionEnd> UmlFactoryImpl::createExtensionEnd_in_Class(std::shared_ptr<uml::Class > par_class) const
{
	std::shared_ptr<ExtensionEnd> element(new ExtensionEndImpl(par_class));
	return element;
}
std::shared_ptr<ExtensionEnd> UmlFactoryImpl::createExtensionEnd_in_Datatype(std::weak_ptr<uml::DataType > par_datatype) const
{
	std::shared_ptr<ExtensionEnd> element(new ExtensionEndImpl(par_datatype));
	if(auto wp = par_datatype.lock()){
    	wp->getOwnedAttribute()->push_back(element);
	}
	return element;
}
std::shared_ptr<ExtensionEnd> UmlFactoryImpl::createExtensionEnd_in_Interface(std::weak_ptr<uml::Interface > par_interface) const
{
	std::shared_ptr<ExtensionEnd> element(new ExtensionEndImpl(par_interface));
	if(auto wp = par_interface.lock()){
    	wp->getOwnedAttribute()->push_back(element);
	}
	return element;
}
std::shared_ptr<ExtensionEnd> UmlFactoryImpl::createExtensionEnd_in_OwningAssociation(std::weak_ptr<uml::Association > par_owningAssociation) const
{
	std::shared_ptr<ExtensionEnd> element(new ExtensionEndImpl(par_owningAssociation));
	if(auto wp = par_owningAssociation.lock()){
    	wp->getOwnedEnd()->push_back(element);
	}
	return element;
}


std::shared_ptr<ExtensionPoint> UmlFactoryImpl::createExtensionPoint_in_UseCase(std::weak_ptr<uml::UseCase > par_useCase) const
{
	std::shared_ptr<ExtensionPoint> element(new ExtensionPointImpl(par_useCase));
	if(auto wp = par_useCase.lock()){
    	wp->getExtensionPoint()->push_back(element);
	}
	return element;
}




std::shared_ptr<FinalState> UmlFactoryImpl::createFinalState_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<FinalState> element(new FinalStateImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<FinalState> UmlFactoryImpl::createFinalState_in_Container(std::weak_ptr<uml::Region > par_container) const
{
	std::shared_ptr<FinalState> element(new FinalStateImpl(par_container));
	if(auto wp = par_container.lock()){
    	wp->getSubvertex()->push_back(element);
	}
	return element;
}


std::shared_ptr<FlowFinalNode> UmlFactoryImpl::createFlowFinalNode_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<FlowFinalNode> element(new FlowFinalNodeImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<FlowFinalNode> UmlFactoryImpl::createFlowFinalNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<FlowFinalNode> element(new FlowFinalNodeImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<ForkNode> UmlFactoryImpl::createForkNode_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ForkNode> element(new ForkNodeImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<ForkNode> UmlFactoryImpl::createForkNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ForkNode> element(new ForkNodeImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<FunctionBehavior> UmlFactoryImpl::createFunctionBehavior_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<FunctionBehavior> element(new FunctionBehaviorImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<FunctionBehavior> UmlFactoryImpl::createFunctionBehavior_in_Package(std::shared_ptr<uml::Package > par_package) const
{
	std::shared_ptr<FunctionBehavior> element(new FunctionBehaviorImpl(par_package));
	if(nullptr != par_package){
    	par_package->getOwnedType()->push_back(element);
	}
	return element;
}
std::shared_ptr<FunctionBehavior> UmlFactoryImpl::createFunctionBehavior_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<FunctionBehavior> element(new FunctionBehaviorImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<Gate> UmlFactoryImpl::createGate_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Gate> element(new GateImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}


std::shared_ptr<GeneralOrdering> UmlFactoryImpl::createGeneralOrdering_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<GeneralOrdering> element(new GeneralOrderingImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}


std::shared_ptr<Generalization> UmlFactoryImpl::createGeneralization_in_Specific(std::weak_ptr<uml::Classifier > par_specific) const
{
	std::shared_ptr<Generalization> element(new GeneralizationImpl(par_specific));
	if(auto wp = par_specific.lock()){
    	wp->getGeneralization()->push_back(element);
	}
	return element;
}


std::shared_ptr<GeneralizationSet> UmlFactoryImpl::createGeneralizationSet_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<GeneralizationSet> element(new GeneralizationSetImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<GeneralizationSet> UmlFactoryImpl::createGeneralizationSet_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<GeneralizationSet> element(new GeneralizationSetImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock()){
		wp->setOwnedParameteredElement(element);
	}
	return element;
}


std::shared_ptr<Image> UmlFactoryImpl::createImage_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Image> element(new ImageImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<Include> UmlFactoryImpl::createInclude_in_IncludingCase(std::weak_ptr<uml::UseCase > par_includingCase) const
{
	std::shared_ptr<Include> element(new IncludeImpl(par_includingCase));
	if(auto wp = par_includingCase.lock()){
    	wp->getInclude()->push_back(element);
	}
	return element;
}


std::shared_ptr<InformationFlow> UmlFactoryImpl::createInformationFlow_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<InformationFlow> element(new InformationFlowImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<InformationFlow> UmlFactoryImpl::createInformationFlow_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<InformationFlow> element(new InformationFlowImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock()){
		wp->setOwnedParameteredElement(element);
	}
	return element;
}
std::shared_ptr<InformationFlow> UmlFactoryImpl::createInformationFlow_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<InformationFlow> element(new InformationFlowImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<InformationItem> UmlFactoryImpl::createInformationItem_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<InformationItem> element(new InformationItemImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<InformationItem> UmlFactoryImpl::createInformationItem_in_Package(std::shared_ptr<uml::Package > par_package) const
{
	std::shared_ptr<InformationItem> element(new InformationItemImpl(par_package));
	if(nullptr != par_package){
    	par_package->getOwnedType()->push_back(element);
	}
	return element;
}
std::shared_ptr<InformationItem> UmlFactoryImpl::createInformationItem_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<InformationItem> element(new InformationItemImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<InitialNode> UmlFactoryImpl::createInitialNode_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<InitialNode> element(new InitialNodeImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<InitialNode> UmlFactoryImpl::createInitialNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<InitialNode> element(new InitialNodeImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<InputPin> UmlFactoryImpl::createInputPin_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<InputPin> element(new InputPinImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<InputPin> UmlFactoryImpl::createInputPin_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<InputPin> element(new InputPinImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<InputPin> UmlFactoryImpl::createInputPin_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<InputPin> element(new InputPinImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<InputPin> UmlFactoryImpl::createInputPin_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<InputPin> element(new InputPinImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<InstanceSpecification> UmlFactoryImpl::createInstanceSpecification_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<InstanceSpecification> element(new InstanceSpecificationImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<InstanceSpecification> UmlFactoryImpl::createInstanceSpecification_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<InstanceSpecification> element(new InstanceSpecificationImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock()){
		wp->setOwnedParameteredElement(element);
	}
	return element;
}


std::shared_ptr<InstanceValue> UmlFactoryImpl::createInstanceValue_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<InstanceValue> element(new InstanceValueImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<InstanceValue> UmlFactoryImpl::createInstanceValue_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<InstanceValue> element(new InstanceValueImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock()){
		wp->setOwnedParameteredElement(element);
	}
	return element;
}


std::shared_ptr<Interaction> UmlFactoryImpl::createInteraction_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Interaction> element(new InteractionImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<Interaction> UmlFactoryImpl::createInteraction_in_Package(std::shared_ptr<uml::Package > par_package) const
{
	std::shared_ptr<Interaction> element(new InteractionImpl(par_package));
	if(nullptr != par_package){
    	par_package->getOwnedType()->push_back(element);
	}
	return element;
}
std::shared_ptr<Interaction> UmlFactoryImpl::createInteraction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Interaction> element(new InteractionImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}
std::shared_ptr<Interaction> UmlFactoryImpl::createInteraction_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction) const
{
	std::shared_ptr<Interaction> element(new InteractionImpl(par_enclosingInteraction));
	if(auto wp = par_enclosingInteraction.lock()){
    	wp->getFragment()->push_back(element);
	}
	return element;
}
std::shared_ptr<Interaction> UmlFactoryImpl::createInteraction_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand) const
{
	std::shared_ptr<Interaction> element(new InteractionImpl(par_enclosingOperand));
	if(auto wp = par_enclosingOperand.lock()){
    	wp->getFragment()->push_back(element);
	}
	return element;
}


std::shared_ptr<InteractionConstraint> UmlFactoryImpl::createInteractionConstraint_in_Context(std::weak_ptr<uml::Namespace > par_context) const
{
	std::shared_ptr<InteractionConstraint> element(new InteractionConstraintImpl(par_context));
	if(auto wp = par_context.lock()){
    	wp->getOwnedRule()->push_back(element);
	}
	return element;
}


std::shared_ptr<InteractionOperand> UmlFactoryImpl::createInteractionOperand_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<InteractionOperand> element(new InteractionOperandImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<InteractionOperand> UmlFactoryImpl::createInteractionOperand_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction) const
{
	std::shared_ptr<InteractionOperand> element(new InteractionOperandImpl(par_enclosingInteraction));
	if(auto wp = par_enclosingInteraction.lock()){
    	wp->getFragment()->push_back(element);
	}
	return element;
}
std::shared_ptr<InteractionOperand> UmlFactoryImpl::createInteractionOperand_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand) const
{
	std::shared_ptr<InteractionOperand> element(new InteractionOperandImpl(par_enclosingOperand));
	if(auto wp = par_enclosingOperand.lock()){
    	wp->getFragment()->push_back(element);
	}
	return element;
}


std::shared_ptr<InteractionUse> UmlFactoryImpl::createInteractionUse_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction) const
{
	std::shared_ptr<InteractionUse> element(new InteractionUseImpl(par_enclosingInteraction));
	if(auto wp = par_enclosingInteraction.lock()){
    	wp->getFragment()->push_back(element);
	}
	return element;
}
std::shared_ptr<InteractionUse> UmlFactoryImpl::createInteractionUse_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand) const
{
	std::shared_ptr<InteractionUse> element(new InteractionUseImpl(par_enclosingOperand));
	if(auto wp = par_enclosingOperand.lock()){
    	wp->getFragment()->push_back(element);
	}
	return element;
}


std::shared_ptr<Interface> UmlFactoryImpl::createInterface_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Interface> element(new InterfaceImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<Interface> UmlFactoryImpl::createInterface_in_Package(std::shared_ptr<uml::Package > par_package) const
{
	std::shared_ptr<Interface> element(new InterfaceImpl(par_package));
	if(nullptr != par_package){
    	par_package->getOwnedType()->push_back(element);
	}
	return element;
}
std::shared_ptr<Interface> UmlFactoryImpl::createInterface_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Interface> element(new InterfaceImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<InterfaceRealization> UmlFactoryImpl::createInterfaceRealization_in_ImplementingClassifier(std::weak_ptr<uml::BehavioredClassifier > par_implementingClassifier) const
{
	std::shared_ptr<InterfaceRealization> element(new InterfaceRealizationImpl(par_implementingClassifier));
	if(auto wp = par_implementingClassifier.lock()){
    	wp->getInterfaceRealization()->push_back(element);
	}
	return element;
}


std::shared_ptr<InterruptibleActivityRegion> UmlFactoryImpl::createInterruptibleActivityRegion_in_InActivity(std::shared_ptr<uml::Activity > par_inActivity) const
{
	std::shared_ptr<InterruptibleActivityRegion> element(new InterruptibleActivityRegionImpl(par_inActivity));
	if(nullptr != par_inActivity){
    	par_inActivity->getGroup()->push_back(element);
	}
	return element;
}
std::shared_ptr<InterruptibleActivityRegion> UmlFactoryImpl::createInterruptibleActivityRegion_in_SuperGroup(std::shared_ptr<uml::ActivityGroup > par_superGroup) const
{
	std::shared_ptr<InterruptibleActivityRegion> element(new InterruptibleActivityRegionImpl(par_superGroup));
	if(nullptr != par_superGroup){
    	par_superGroup->getSubgroup()->push_back(element);
	}
	return element;
}


std::shared_ptr<Interval> UmlFactoryImpl::createInterval_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Interval> element(new IntervalImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<Interval> UmlFactoryImpl::createInterval_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Interval> element(new IntervalImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock()){
		wp->setOwnedParameteredElement(element);
	}
	return element;
}


std::shared_ptr<IntervalConstraint> UmlFactoryImpl::createIntervalConstraint_in_Context(std::weak_ptr<uml::Namespace > par_context) const
{
	std::shared_ptr<IntervalConstraint> element(new IntervalConstraintImpl(par_context));
	if(auto wp = par_context.lock()){
    	wp->getOwnedRule()->push_back(element);
	}
	return element;
}


std::shared_ptr<JoinNode> UmlFactoryImpl::createJoinNode_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<JoinNode> element(new JoinNodeImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<JoinNode> UmlFactoryImpl::createJoinNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<JoinNode> element(new JoinNodeImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<Lifeline> UmlFactoryImpl::createLifeline_in_Interaction(std::weak_ptr<uml::Interaction > par_interaction) const
{
	std::shared_ptr<Lifeline> element(new LifelineImpl(par_interaction));
	if(auto wp = par_interaction.lock()){
    	wp->getLifeline()->push_back(element);
	}
	return element;
}


std::shared_ptr<LinkEndCreationData> UmlFactoryImpl::createLinkEndCreationData_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<LinkEndCreationData> element(new LinkEndCreationDataImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<LinkEndData> UmlFactoryImpl::createLinkEndData_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<LinkEndData> element(new LinkEndDataImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<LinkEndDestructionData> UmlFactoryImpl::createLinkEndDestructionData_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<LinkEndDestructionData> element(new LinkEndDestructionDataImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<LiteralBoolean> UmlFactoryImpl::createLiteralBoolean_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<LiteralBoolean> element(new LiteralBooleanImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<LiteralBoolean> UmlFactoryImpl::createLiteralBoolean_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<LiteralBoolean> element(new LiteralBooleanImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock()){
		wp->setOwnedParameteredElement(element);
	}
	return element;
}


std::shared_ptr<LiteralInteger> UmlFactoryImpl::createLiteralInteger_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<LiteralInteger> element(new LiteralIntegerImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<LiteralInteger> UmlFactoryImpl::createLiteralInteger_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<LiteralInteger> element(new LiteralIntegerImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock()){
		wp->setOwnedParameteredElement(element);
	}
	return element;
}


std::shared_ptr<LiteralNull> UmlFactoryImpl::createLiteralNull_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<LiteralNull> element(new LiteralNullImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<LiteralNull> UmlFactoryImpl::createLiteralNull_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<LiteralNull> element(new LiteralNullImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock()){
		wp->setOwnedParameteredElement(element);
	}
	return element;
}


std::shared_ptr<LiteralReal> UmlFactoryImpl::createLiteralReal_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<LiteralReal> element(new LiteralRealImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<LiteralReal> UmlFactoryImpl::createLiteralReal_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<LiteralReal> element(new LiteralRealImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock()){
		wp->setOwnedParameteredElement(element);
	}
	return element;
}


std::shared_ptr<LiteralString> UmlFactoryImpl::createLiteralString_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<LiteralString> element(new LiteralStringImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<LiteralString> UmlFactoryImpl::createLiteralString_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<LiteralString> element(new LiteralStringImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock()){
		wp->setOwnedParameteredElement(element);
	}
	return element;
}


std::shared_ptr<LiteralUnlimitedNatural> UmlFactoryImpl::createLiteralUnlimitedNatural_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<LiteralUnlimitedNatural> element(new LiteralUnlimitedNaturalImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<LiteralUnlimitedNatural> UmlFactoryImpl::createLiteralUnlimitedNatural_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<LiteralUnlimitedNatural> element(new LiteralUnlimitedNaturalImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock()){
		wp->setOwnedParameteredElement(element);
	}
	return element;
}


std::shared_ptr<LoopNode> UmlFactoryImpl::createLoopNode_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<LoopNode> element(new LoopNodeImpl(par_activity, UmlPackage::ACTIVITYNODE_ACTIVITY));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<LoopNode> UmlFactoryImpl::createLoopNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<LoopNode> element(new LoopNodeImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<LoopNode> UmlFactoryImpl::createLoopNode_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<LoopNode> element(new LoopNodeImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<LoopNode> UmlFactoryImpl::createLoopNode_in_InActivity(std::shared_ptr<uml::Activity > par_inActivity) const
{
	std::shared_ptr<LoopNode> element(new LoopNodeImpl(par_inActivity, UmlPackage::ACTIVITYGROUP_INACTIVITY));
	if(nullptr != par_inActivity){
    	par_inActivity->getGroup()->push_back(element);
	}
	return element;
}
std::shared_ptr<LoopNode> UmlFactoryImpl::createLoopNode_in_SuperGroup(std::shared_ptr<uml::ActivityGroup > par_superGroup) const
{
	std::shared_ptr<LoopNode> element(new LoopNodeImpl(par_superGroup));
	if(nullptr != par_superGroup){
    	par_superGroup->getSubgroup()->push_back(element);
	}
	return element;
}


std::shared_ptr<Manifestation> UmlFactoryImpl::createManifestation_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Manifestation> element(new ManifestationImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<Manifestation> UmlFactoryImpl::createManifestation_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Manifestation> element(new ManifestationImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock()){
		wp->setOwnedParameteredElement(element);
	}
	return element;
}
std::shared_ptr<Manifestation> UmlFactoryImpl::createManifestation_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Manifestation> element(new ManifestationImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<MergeNode> UmlFactoryImpl::createMergeNode_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<MergeNode> element(new MergeNodeImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<MergeNode> UmlFactoryImpl::createMergeNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<MergeNode> element(new MergeNodeImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<Message> UmlFactoryImpl::createMessage_in_Interaction(std::weak_ptr<uml::Interaction > par_interaction) const
{
	std::shared_ptr<Message> element(new MessageImpl(par_interaction));
	if(auto wp = par_interaction.lock()){
    	wp->getMessage()->push_back(element);
	}
	return element;
}


std::shared_ptr<MessageOccurrenceSpecification> UmlFactoryImpl::createMessageOccurrenceSpecification_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction) const
{
	std::shared_ptr<MessageOccurrenceSpecification> element(new MessageOccurrenceSpecificationImpl(par_enclosingInteraction));
	if(auto wp = par_enclosingInteraction.lock()){
    	wp->getFragment()->push_back(element);
	}
	return element;
}
std::shared_ptr<MessageOccurrenceSpecification> UmlFactoryImpl::createMessageOccurrenceSpecification_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand) const
{
	std::shared_ptr<MessageOccurrenceSpecification> element(new MessageOccurrenceSpecificationImpl(par_enclosingOperand));
	if(auto wp = par_enclosingOperand.lock()){
    	wp->getFragment()->push_back(element);
	}
	return element;
}
std::shared_ptr<MessageOccurrenceSpecification> UmlFactoryImpl::createMessageOccurrenceSpecification_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<MessageOccurrenceSpecification> element(new MessageOccurrenceSpecificationImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}


std::shared_ptr<Model> UmlFactoryImpl::createModel_in_NestingPackage(std::shared_ptr<uml::Package > par_nestingPackage) const
{
	std::shared_ptr<Model> element(new ModelImpl(par_nestingPackage));
	if(nullptr != par_nestingPackage){
    	par_nestingPackage->getNestedPackage()->push_back(element);
	}
	return element;
}


std::shared_ptr<Node> UmlFactoryImpl::createNode_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Node> element(new NodeImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<Node> UmlFactoryImpl::createNode_in_Package(std::shared_ptr<uml::Package > par_package) const
{
	std::shared_ptr<Node> element(new NodeImpl(par_package));
	if(nullptr != par_package){
    	par_package->getOwnedType()->push_back(element);
	}
	return element;
}
std::shared_ptr<Node> UmlFactoryImpl::createNode_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Node> element(new NodeImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}




std::shared_ptr<ObjectFlow> UmlFactoryImpl::createObjectFlow_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ObjectFlow> element(new ObjectFlowImpl(par_activity));
	if(auto wp = par_activity.lock()){
    	wp->getEdge()->push_back(element);
	}
	return element;
}
std::shared_ptr<ObjectFlow> UmlFactoryImpl::createObjectFlow_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ObjectFlow> element(new ObjectFlowImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getEdge()->push_back(element);
	}
	return element;
}


std::shared_ptr<OccurrenceSpecification> UmlFactoryImpl::createOccurrenceSpecification_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction) const
{
	std::shared_ptr<OccurrenceSpecification> element(new OccurrenceSpecificationImpl(par_enclosingInteraction));
	if(auto wp = par_enclosingInteraction.lock()){
    	wp->getFragment()->push_back(element);
	}
	return element;
}
std::shared_ptr<OccurrenceSpecification> UmlFactoryImpl::createOccurrenceSpecification_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand) const
{
	std::shared_ptr<OccurrenceSpecification> element(new OccurrenceSpecificationImpl(par_enclosingOperand));
	if(auto wp = par_enclosingOperand.lock()){
    	wp->getFragment()->push_back(element);
	}
	return element;
}


std::shared_ptr<OpaqueAction> UmlFactoryImpl::createOpaqueAction_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<OpaqueAction> element(new OpaqueActionImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<OpaqueAction> UmlFactoryImpl::createOpaqueAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<OpaqueAction> element(new OpaqueActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<OpaqueBehavior> UmlFactoryImpl::createOpaqueBehavior_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<OpaqueBehavior> element(new OpaqueBehaviorImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<OpaqueBehavior> UmlFactoryImpl::createOpaqueBehavior_in_Package(std::shared_ptr<uml::Package > par_package) const
{
	std::shared_ptr<OpaqueBehavior> element(new OpaqueBehaviorImpl(par_package));
	if(nullptr != par_package){
    	par_package->getOwnedType()->push_back(element);
	}
	return element;
}
std::shared_ptr<OpaqueBehavior> UmlFactoryImpl::createOpaqueBehavior_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<OpaqueBehavior> element(new OpaqueBehaviorImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<OpaqueExpression> UmlFactoryImpl::createOpaqueExpression_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<OpaqueExpression> element(new OpaqueExpressionImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<OpaqueExpression> UmlFactoryImpl::createOpaqueExpression_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<OpaqueExpression> element(new OpaqueExpressionImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock()){
		wp->setOwnedParameteredElement(element);
	}
	return element;
}


std::shared_ptr<Operation> UmlFactoryImpl::createOperation_in_Class(std::weak_ptr<uml::Class > par_class) const
{
	std::shared_ptr<Operation> element(new OperationImpl(par_class));
	if(auto wp = par_class.lock()){
    	wp->getOwnedOperation()->push_back(element);
	}
	return element;
}
std::shared_ptr<Operation> UmlFactoryImpl::createOperation_in_Datatype(std::weak_ptr<uml::DataType > par_datatype) const
{
	std::shared_ptr<Operation> element(new OperationImpl(par_datatype));
	if(auto wp = par_datatype.lock()){
    	wp->getOwnedOperation()->push_back(element);
	}
	return element;
}
std::shared_ptr<Operation> UmlFactoryImpl::createOperation_in_Interface(std::weak_ptr<uml::Interface > par_interface) const
{
	std::shared_ptr<Operation> element(new OperationImpl(par_interface));
	if(auto wp = par_interface.lock()){
    	wp->getOwnedOperation()->push_back(element);
	}
	return element;
}


std::shared_ptr<OperationTemplateParameter> UmlFactoryImpl::createOperationTemplateParameter_in_Signature(std::weak_ptr<uml::TemplateSignature > par_signature) const
{
	std::shared_ptr<OperationTemplateParameter> element(new OperationTemplateParameterImpl(par_signature));
	if(auto wp = par_signature.lock()){
    	wp->getOwnedParameter()->push_back(element);
	}
	return element;
}


std::shared_ptr<OutputPin> UmlFactoryImpl::createOutputPin_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<OutputPin> element(new OutputPinImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<OutputPin> UmlFactoryImpl::createOutputPin_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<OutputPin> element(new OutputPinImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<OutputPin> UmlFactoryImpl::createOutputPin_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<OutputPin> element(new OutputPinImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<OutputPin> UmlFactoryImpl::createOutputPin_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<OutputPin> element(new OutputPinImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<Package> UmlFactoryImpl::createPackage_in_NestingPackage(std::shared_ptr<uml::Package > par_nestingPackage) const
{
	std::shared_ptr<Package> element(new PackageImpl(par_nestingPackage));
	if(nullptr != par_nestingPackage){
    	par_nestingPackage->getNestedPackage()->push_back(element);
	}
	return element;
}


std::shared_ptr<PackageImport> UmlFactoryImpl::createPackageImport_in_ImportingNamespace(std::weak_ptr<uml::Namespace > par_importingNamespace) const
{
	std::shared_ptr<PackageImport> element(new PackageImportImpl(par_importingNamespace));
	if(auto wp = par_importingNamespace.lock()){
    	wp->getPackageImport()->push_back(element);
	}
	return element;
}


std::shared_ptr<PackageMerge> UmlFactoryImpl::createPackageMerge_in_ReceivingPackage(std::weak_ptr<uml::Package > par_receivingPackage) const
{
	std::shared_ptr<PackageMerge> element(new PackageMergeImpl(par_receivingPackage));
	if(auto wp = par_receivingPackage.lock()){
    	wp->getPackageMerge()->push_back(element);
	}
	return element;
}


std::shared_ptr<Parameter> UmlFactoryImpl::createParameter_in_Operation(std::shared_ptr<uml::Operation > par_operation) const
{
	std::shared_ptr<Parameter> element(new ParameterImpl(par_operation));
	return element;
}


std::shared_ptr<ParameterSet> UmlFactoryImpl::createParameterSet_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ParameterSet> element(new ParameterSetImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}


std::shared_ptr<PartDecomposition> UmlFactoryImpl::createPartDecomposition_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction) const
{
	std::shared_ptr<PartDecomposition> element(new PartDecompositionImpl(par_enclosingInteraction));
	if(auto wp = par_enclosingInteraction.lock()){
    	wp->getFragment()->push_back(element);
	}
	return element;
}
std::shared_ptr<PartDecomposition> UmlFactoryImpl::createPartDecomposition_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand) const
{
	std::shared_ptr<PartDecomposition> element(new PartDecompositionImpl(par_enclosingOperand));
	if(auto wp = par_enclosingOperand.lock()){
    	wp->getFragment()->push_back(element);
	}
	return element;
}


std::shared_ptr<Port> UmlFactoryImpl::createPort_in_AssociationEnd(std::weak_ptr<uml::Property > par_associationEnd) const
{
	std::shared_ptr<Port> element(new PortImpl(par_associationEnd));
	if(auto wp = par_associationEnd.lock()){
    	wp->getQualifier()->push_back(element);
	}
	return element;
}
std::shared_ptr<Port> UmlFactoryImpl::createPort_in_Class(std::shared_ptr<uml::Class > par_class) const
{
	std::shared_ptr<Port> element(new PortImpl(par_class));
	return element;
}
std::shared_ptr<Port> UmlFactoryImpl::createPort_in_Datatype(std::weak_ptr<uml::DataType > par_datatype) const
{
	std::shared_ptr<Port> element(new PortImpl(par_datatype));
	if(auto wp = par_datatype.lock()){
    	wp->getOwnedAttribute()->push_back(element);
	}
	return element;
}
std::shared_ptr<Port> UmlFactoryImpl::createPort_in_Interface(std::weak_ptr<uml::Interface > par_interface) const
{
	std::shared_ptr<Port> element(new PortImpl(par_interface));
	if(auto wp = par_interface.lock()){
    	wp->getOwnedAttribute()->push_back(element);
	}
	return element;
}
std::shared_ptr<Port> UmlFactoryImpl::createPort_in_OwningAssociation(std::weak_ptr<uml::Association > par_owningAssociation) const
{
	std::shared_ptr<Port> element(new PortImpl(par_owningAssociation));
	if(auto wp = par_owningAssociation.lock()){
    	wp->getOwnedEnd()->push_back(element);
	}
	return element;
}


std::shared_ptr<PrimitiveType> UmlFactoryImpl::createPrimitiveType_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<PrimitiveType> element(new PrimitiveTypeImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<PrimitiveType> UmlFactoryImpl::createPrimitiveType_in_Package(std::shared_ptr<uml::Package > par_package) const
{
	std::shared_ptr<PrimitiveType> element(new PrimitiveTypeImpl(par_package));
	if(nullptr != par_package){
    	par_package->getOwnedType()->push_back(element);
	}
	return element;
}
std::shared_ptr<PrimitiveType> UmlFactoryImpl::createPrimitiveType_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<PrimitiveType> element(new PrimitiveTypeImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<Profile> UmlFactoryImpl::createProfile_in_NestingPackage(std::shared_ptr<uml::Package > par_nestingPackage) const
{
	std::shared_ptr<Profile> element(new ProfileImpl(par_nestingPackage));
	if(nullptr != par_nestingPackage){
    	par_nestingPackage->getNestedPackage()->push_back(element);
	}
	return element;
}


std::shared_ptr<ProfileApplication> UmlFactoryImpl::createProfileApplication_in_ApplyingPackage(std::weak_ptr<uml::Package > par_applyingPackage) const
{
	std::shared_ptr<ProfileApplication> element(new ProfileApplicationImpl(par_applyingPackage));
	if(auto wp = par_applyingPackage.lock()){
    	wp->getProfileApplication()->push_back(element);
	}
	return element;
}


std::shared_ptr<Property> UmlFactoryImpl::createProperty_in_AssociationEnd(std::weak_ptr<uml::Property > par_associationEnd) const
{
	std::shared_ptr<Property> element(new PropertyImpl(par_associationEnd));
	if(auto wp = par_associationEnd.lock()){
    	wp->getQualifier()->push_back(element);
	}
	return element;
}
std::shared_ptr<Property> UmlFactoryImpl::createProperty_in_Class(std::shared_ptr<uml::Class > par_class) const
{
	std::shared_ptr<Property> element(new PropertyImpl(par_class));
	return element;
}
std::shared_ptr<Property> UmlFactoryImpl::createProperty_in_Datatype(std::weak_ptr<uml::DataType > par_datatype) const
{
	std::shared_ptr<Property> element(new PropertyImpl(par_datatype));
	if(auto wp = par_datatype.lock()){
    	wp->getOwnedAttribute()->push_back(element);
	}
	return element;
}
std::shared_ptr<Property> UmlFactoryImpl::createProperty_in_Interface(std::weak_ptr<uml::Interface > par_interface) const
{
	std::shared_ptr<Property> element(new PropertyImpl(par_interface));
	if(auto wp = par_interface.lock()){
    	wp->getOwnedAttribute()->push_back(element);
	}
	return element;
}
std::shared_ptr<Property> UmlFactoryImpl::createProperty_in_OwningAssociation(std::weak_ptr<uml::Association > par_owningAssociation) const
{
	std::shared_ptr<Property> element(new PropertyImpl(par_owningAssociation));
	if(auto wp = par_owningAssociation.lock()){
    	wp->getNavigableOwnedEnd()->push_back(element);
	}
	return element;
}


std::shared_ptr<ProtocolConformance> UmlFactoryImpl::createProtocolConformance_in_SpecificMachine(std::weak_ptr<uml::ProtocolStateMachine > par_specificMachine) const
{
	std::shared_ptr<ProtocolConformance> element(new ProtocolConformanceImpl(par_specificMachine));
	if(auto wp = par_specificMachine.lock()){
    	wp->getConformance()->push_back(element);
	}
	return element;
}


std::shared_ptr<ProtocolStateMachine> UmlFactoryImpl::createProtocolStateMachine_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ProtocolStateMachine> element(new ProtocolStateMachineImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<ProtocolStateMachine> UmlFactoryImpl::createProtocolStateMachine_in_Package(std::shared_ptr<uml::Package > par_package) const
{
	std::shared_ptr<ProtocolStateMachine> element(new ProtocolStateMachineImpl(par_package));
	if(nullptr != par_package){
    	par_package->getOwnedType()->push_back(element);
	}
	return element;
}
std::shared_ptr<ProtocolStateMachine> UmlFactoryImpl::createProtocolStateMachine_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ProtocolStateMachine> element(new ProtocolStateMachineImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<ProtocolTransition> UmlFactoryImpl::createProtocolTransition_in_Container(std::weak_ptr<uml::Region > par_container) const
{
	std::shared_ptr<ProtocolTransition> element(new ProtocolTransitionImpl(par_container));
	if(auto wp = par_container.lock()){
    	wp->getTransition()->push_back(element);
	}
	return element;
}


std::shared_ptr<Pseudostate> UmlFactoryImpl::createPseudostate_in_State(std::weak_ptr<uml::State > par_state) const
{
	std::shared_ptr<Pseudostate> element(new PseudostateImpl(par_state));
	if(auto wp = par_state.lock()){
    	wp->getConnectionPoint()->push_back(element);
	}
	return element;
}
std::shared_ptr<Pseudostate> UmlFactoryImpl::createPseudostate_in_StateMachine(std::weak_ptr<uml::StateMachine > par_stateMachine) const
{
	std::shared_ptr<Pseudostate> element(new PseudostateImpl(par_stateMachine));
	if(auto wp = par_stateMachine.lock()){
    	wp->getConnectionPoint()->push_back(element);
	}
	return element;
}


std::shared_ptr<QualifierValue> UmlFactoryImpl::createQualifierValue_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<QualifierValue> element(new QualifierValueImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<RaiseExceptionAction> UmlFactoryImpl::createRaiseExceptionAction_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<RaiseExceptionAction> element(new RaiseExceptionActionImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<RaiseExceptionAction> UmlFactoryImpl::createRaiseExceptionAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<RaiseExceptionAction> element(new RaiseExceptionActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<ReadExtentAction> UmlFactoryImpl::createReadExtentAction_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ReadExtentAction> element(new ReadExtentActionImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<ReadExtentAction> UmlFactoryImpl::createReadExtentAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ReadExtentAction> element(new ReadExtentActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<ReadIsClassifiedObjectAction> UmlFactoryImpl::createReadIsClassifiedObjectAction_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ReadIsClassifiedObjectAction> element(new ReadIsClassifiedObjectActionImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<ReadIsClassifiedObjectAction> UmlFactoryImpl::createReadIsClassifiedObjectAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ReadIsClassifiedObjectAction> element(new ReadIsClassifiedObjectActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<ReadLinkAction> UmlFactoryImpl::createReadLinkAction_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ReadLinkAction> element(new ReadLinkActionImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<ReadLinkAction> UmlFactoryImpl::createReadLinkAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ReadLinkAction> element(new ReadLinkActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<ReadLinkObjectEndAction> UmlFactoryImpl::createReadLinkObjectEndAction_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ReadLinkObjectEndAction> element(new ReadLinkObjectEndActionImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<ReadLinkObjectEndAction> UmlFactoryImpl::createReadLinkObjectEndAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ReadLinkObjectEndAction> element(new ReadLinkObjectEndActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<ReadLinkObjectEndQualifierAction> UmlFactoryImpl::createReadLinkObjectEndQualifierAction_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ReadLinkObjectEndQualifierAction> element(new ReadLinkObjectEndQualifierActionImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<ReadLinkObjectEndQualifierAction> UmlFactoryImpl::createReadLinkObjectEndQualifierAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ReadLinkObjectEndQualifierAction> element(new ReadLinkObjectEndQualifierActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<ReadSelfAction> UmlFactoryImpl::createReadSelfAction_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ReadSelfAction> element(new ReadSelfActionImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<ReadSelfAction> UmlFactoryImpl::createReadSelfAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ReadSelfAction> element(new ReadSelfActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<ReadStructuralFeatureAction> UmlFactoryImpl::createReadStructuralFeatureAction_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ReadStructuralFeatureAction> element(new ReadStructuralFeatureActionImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<ReadStructuralFeatureAction> UmlFactoryImpl::createReadStructuralFeatureAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ReadStructuralFeatureAction> element(new ReadStructuralFeatureActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<ReadVariableAction> UmlFactoryImpl::createReadVariableAction_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ReadVariableAction> element(new ReadVariableActionImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<ReadVariableAction> UmlFactoryImpl::createReadVariableAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ReadVariableAction> element(new ReadVariableActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<Realization> UmlFactoryImpl::createRealization_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Realization> element(new RealizationImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<Realization> UmlFactoryImpl::createRealization_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Realization> element(new RealizationImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock()){
		wp->setOwnedParameteredElement(element);
	}
	return element;
}
std::shared_ptr<Realization> UmlFactoryImpl::createRealization_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Realization> element(new RealizationImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<Reception> UmlFactoryImpl::createReception_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Reception> element(new ReceptionImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}


std::shared_ptr<ReclassifyObjectAction> UmlFactoryImpl::createReclassifyObjectAction_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ReclassifyObjectAction> element(new ReclassifyObjectActionImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<ReclassifyObjectAction> UmlFactoryImpl::createReclassifyObjectAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ReclassifyObjectAction> element(new ReclassifyObjectActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<RedefinableTemplateSignature> UmlFactoryImpl::createRedefinableTemplateSignature_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<RedefinableTemplateSignature> element(new RedefinableTemplateSignatureImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<RedefinableTemplateSignature> UmlFactoryImpl::createRedefinableTemplateSignature_in_Template(std::weak_ptr<uml::TemplateableElement > par_template) const
{
	std::shared_ptr<RedefinableTemplateSignature> element(new RedefinableTemplateSignatureImpl(par_template));
	if(auto wp = par_template.lock()){
		wp->setOwnedTemplateSignature(element);
	}
	return element;
}


std::shared_ptr<ReduceAction> UmlFactoryImpl::createReduceAction_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ReduceAction> element(new ReduceActionImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<ReduceAction> UmlFactoryImpl::createReduceAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ReduceAction> element(new ReduceActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<Region> UmlFactoryImpl::createRegion_in_State(std::weak_ptr<uml::State > par_state) const
{
	std::shared_ptr<Region> element(new RegionImpl(par_state));
	if(auto wp = par_state.lock()){
    	wp->getRegion()->push_back(element);
	}
	return element;
}
std::shared_ptr<Region> UmlFactoryImpl::createRegion_in_StateMachine(std::weak_ptr<uml::StateMachine > par_stateMachine) const
{
	std::shared_ptr<Region> element(new RegionImpl(par_stateMachine));
	if(auto wp = par_stateMachine.lock()){
    	wp->getRegion()->push_back(element);
	}
	return element;
}


std::shared_ptr<RemoveStructuralFeatureValueAction> UmlFactoryImpl::createRemoveStructuralFeatureValueAction_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<RemoveStructuralFeatureValueAction> element(new RemoveStructuralFeatureValueActionImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<RemoveStructuralFeatureValueAction> UmlFactoryImpl::createRemoveStructuralFeatureValueAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<RemoveStructuralFeatureValueAction> element(new RemoveStructuralFeatureValueActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<RemoveVariableValueAction> UmlFactoryImpl::createRemoveVariableValueAction_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<RemoveVariableValueAction> element(new RemoveVariableValueActionImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<RemoveVariableValueAction> UmlFactoryImpl::createRemoveVariableValueAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<RemoveVariableValueAction> element(new RemoveVariableValueActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<ReplyAction> UmlFactoryImpl::createReplyAction_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ReplyAction> element(new ReplyActionImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<ReplyAction> UmlFactoryImpl::createReplyAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ReplyAction> element(new ReplyActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<SendObjectAction> UmlFactoryImpl::createSendObjectAction_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<SendObjectAction> element(new SendObjectActionImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<SendObjectAction> UmlFactoryImpl::createSendObjectAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<SendObjectAction> element(new SendObjectActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<SendSignalAction> UmlFactoryImpl::createSendSignalAction_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<SendSignalAction> element(new SendSignalActionImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<SendSignalAction> UmlFactoryImpl::createSendSignalAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<SendSignalAction> element(new SendSignalActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<SequenceNode> UmlFactoryImpl::createSequenceNode_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<SequenceNode> element(new SequenceNodeImpl(par_activity, UmlPackage::ACTIVITYNODE_ACTIVITY));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<SequenceNode> UmlFactoryImpl::createSequenceNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<SequenceNode> element(new SequenceNodeImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<SequenceNode> UmlFactoryImpl::createSequenceNode_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<SequenceNode> element(new SequenceNodeImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<SequenceNode> UmlFactoryImpl::createSequenceNode_in_InActivity(std::shared_ptr<uml::Activity > par_inActivity) const
{
	std::shared_ptr<SequenceNode> element(new SequenceNodeImpl(par_inActivity, UmlPackage::ACTIVITYGROUP_INACTIVITY));
	if(nullptr != par_inActivity){
    	par_inActivity->getGroup()->push_back(element);
	}
	return element;
}
std::shared_ptr<SequenceNode> UmlFactoryImpl::createSequenceNode_in_SuperGroup(std::shared_ptr<uml::ActivityGroup > par_superGroup) const
{
	std::shared_ptr<SequenceNode> element(new SequenceNodeImpl(par_superGroup));
	if(nullptr != par_superGroup){
    	par_superGroup->getSubgroup()->push_back(element);
	}
	return element;
}


std::shared_ptr<Signal> UmlFactoryImpl::createSignal_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Signal> element(new SignalImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<Signal> UmlFactoryImpl::createSignal_in_Package(std::shared_ptr<uml::Package > par_package) const
{
	std::shared_ptr<Signal> element(new SignalImpl(par_package));
	if(nullptr != par_package){
    	par_package->getOwnedType()->push_back(element);
	}
	return element;
}
std::shared_ptr<Signal> UmlFactoryImpl::createSignal_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Signal> element(new SignalImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<SignalEvent> UmlFactoryImpl::createSignalEvent_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<SignalEvent> element(new SignalEventImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<SignalEvent> UmlFactoryImpl::createSignalEvent_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<SignalEvent> element(new SignalEventImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock()){
		wp->setOwnedParameteredElement(element);
	}
	return element;
}


std::shared_ptr<Slot> UmlFactoryImpl::createSlot_in_OwningInstance(std::weak_ptr<uml::InstanceSpecification > par_owningInstance) const
{
	std::shared_ptr<Slot> element(new SlotImpl(par_owningInstance));
	if(auto wp = par_owningInstance.lock()){
    	wp->getSlot()->push_back(element);
	}
	return element;
}


std::shared_ptr<StartClassifierBehaviorAction> UmlFactoryImpl::createStartClassifierBehaviorAction_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<StartClassifierBehaviorAction> element(new StartClassifierBehaviorActionImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<StartClassifierBehaviorAction> UmlFactoryImpl::createStartClassifierBehaviorAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<StartClassifierBehaviorAction> element(new StartClassifierBehaviorActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<StartObjectBehaviorAction> UmlFactoryImpl::createStartObjectBehaviorAction_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<StartObjectBehaviorAction> element(new StartObjectBehaviorActionImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<StartObjectBehaviorAction> UmlFactoryImpl::createStartObjectBehaviorAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<StartObjectBehaviorAction> element(new StartObjectBehaviorActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<State> UmlFactoryImpl::createState_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<State> element(new StateImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<State> UmlFactoryImpl::createState_in_Container(std::weak_ptr<uml::Region > par_container) const
{
	std::shared_ptr<State> element(new StateImpl(par_container));
	if(auto wp = par_container.lock()){
    	wp->getSubvertex()->push_back(element);
	}
	return element;
}


std::shared_ptr<StateInvariant> UmlFactoryImpl::createStateInvariant_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction) const
{
	std::shared_ptr<StateInvariant> element(new StateInvariantImpl(par_enclosingInteraction));
	if(auto wp = par_enclosingInteraction.lock()){
    	wp->getFragment()->push_back(element);
	}
	return element;
}
std::shared_ptr<StateInvariant> UmlFactoryImpl::createStateInvariant_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand) const
{
	std::shared_ptr<StateInvariant> element(new StateInvariantImpl(par_enclosingOperand));
	if(auto wp = par_enclosingOperand.lock()){
    	wp->getFragment()->push_back(element);
	}
	return element;
}


std::shared_ptr<StateMachine> UmlFactoryImpl::createStateMachine_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<StateMachine> element(new StateMachineImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<StateMachine> UmlFactoryImpl::createStateMachine_in_Package(std::shared_ptr<uml::Package > par_package) const
{
	std::shared_ptr<StateMachine> element(new StateMachineImpl(par_package));
	if(nullptr != par_package){
    	par_package->getOwnedType()->push_back(element);
	}
	return element;
}
std::shared_ptr<StateMachine> UmlFactoryImpl::createStateMachine_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<StateMachine> element(new StateMachineImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<Stereotype> UmlFactoryImpl::createStereotype_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Stereotype> element(new StereotypeImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<Stereotype> UmlFactoryImpl::createStereotype_in_Package(std::shared_ptr<uml::Package > par_package) const
{
	std::shared_ptr<Stereotype> element(new StereotypeImpl(par_package));
	if(nullptr != par_package){
    	par_package->getOwnedType()->push_back(element);
	}
	return element;
}
std::shared_ptr<Stereotype> UmlFactoryImpl::createStereotype_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Stereotype> element(new StereotypeImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<StringExpression> UmlFactoryImpl::createStringExpression_in_OwningExpression(std::weak_ptr<uml::StringExpression > par_owningExpression) const
{
	std::shared_ptr<StringExpression> element(new StringExpressionImpl(par_owningExpression));
	if(auto wp = par_owningExpression.lock()){
    	wp->getSubExpression()->push_back(element);
	}
	return element;
}


std::shared_ptr<StructuredActivityNode> UmlFactoryImpl::createStructuredActivityNode_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<StructuredActivityNode> element(new StructuredActivityNodeImpl(par_activity, UmlPackage::ACTIVITYNODE_ACTIVITY));
	if(nullptr != par_activity){
    	par_activity->getStructuredNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<StructuredActivityNode> UmlFactoryImpl::createStructuredActivityNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<StructuredActivityNode> element(new StructuredActivityNodeImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<StructuredActivityNode> UmlFactoryImpl::createStructuredActivityNode_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<StructuredActivityNode> element(new StructuredActivityNodeImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<StructuredActivityNode> UmlFactoryImpl::createStructuredActivityNode_in_InActivity(std::shared_ptr<uml::Activity > par_inActivity) const
{
	std::shared_ptr<StructuredActivityNode> element(new StructuredActivityNodeImpl(par_inActivity, UmlPackage::ACTIVITYGROUP_INACTIVITY));
	if(nullptr != par_inActivity){
    	par_inActivity->getStructuredNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<StructuredActivityNode> UmlFactoryImpl::createStructuredActivityNode_in_SuperGroup(std::shared_ptr<uml::ActivityGroup > par_superGroup) const
{
	std::shared_ptr<StructuredActivityNode> element(new StructuredActivityNodeImpl(par_superGroup));
	if(nullptr != par_superGroup){
    	par_superGroup->getSubgroup()->push_back(element);
	}
	return element;
}


std::shared_ptr<Substitution> UmlFactoryImpl::createSubstitution_in_SubstitutingClassifier(std::weak_ptr<uml::Classifier > par_substitutingClassifier) const
{
	std::shared_ptr<Substitution> element(new SubstitutionImpl(par_substitutingClassifier));
	if(auto wp = par_substitutingClassifier.lock()){
    	wp->getSubstitution()->push_back(element);
	}
	return element;
}


std::shared_ptr<TemplateBinding> UmlFactoryImpl::createTemplateBinding_in_BoundElement(std::weak_ptr<uml::TemplateableElement > par_boundElement) const
{
	std::shared_ptr<TemplateBinding> element(new TemplateBindingImpl(par_boundElement));
	if(auto wp = par_boundElement.lock()){
    	wp->getTemplateBinding()->push_back(element);
	}
	return element;
}


std::shared_ptr<TemplateParameter> UmlFactoryImpl::createTemplateParameter_in_Signature(std::weak_ptr<uml::TemplateSignature > par_signature) const
{
	std::shared_ptr<TemplateParameter> element(new TemplateParameterImpl(par_signature));
	if(auto wp = par_signature.lock()){
    	wp->getOwnedParameter()->push_back(element);
	}
	return element;
}


std::shared_ptr<TemplateParameterSubstitution> UmlFactoryImpl::createTemplateParameterSubstitution_in_TemplateBinding(std::weak_ptr<uml::TemplateBinding > par_templateBinding) const
{
	std::shared_ptr<TemplateParameterSubstitution> element(new TemplateParameterSubstitutionImpl(par_templateBinding));
	if(auto wp = par_templateBinding.lock()){
    	wp->getParameterSubstitution()->push_back(element);
	}
	return element;
}


std::shared_ptr<TemplateSignature> UmlFactoryImpl::createTemplateSignature_in_Template(std::weak_ptr<uml::TemplateableElement > par_template) const
{
	std::shared_ptr<TemplateSignature> element(new TemplateSignatureImpl(par_template));
	if(auto wp = par_template.lock()){
		wp->setOwnedTemplateSignature(element);
	}
	return element;
}


std::shared_ptr<TestIdentityAction> UmlFactoryImpl::createTestIdentityAction_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<TestIdentityAction> element(new TestIdentityActionImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<TestIdentityAction> UmlFactoryImpl::createTestIdentityAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<TestIdentityAction> element(new TestIdentityActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<TimeConstraint> UmlFactoryImpl::createTimeConstraint_in_Context(std::weak_ptr<uml::Namespace > par_context) const
{
	std::shared_ptr<TimeConstraint> element(new TimeConstraintImpl(par_context));
	if(auto wp = par_context.lock()){
    	wp->getOwnedRule()->push_back(element);
	}
	return element;
}


std::shared_ptr<TimeEvent> UmlFactoryImpl::createTimeEvent_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<TimeEvent> element(new TimeEventImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<TimeEvent> UmlFactoryImpl::createTimeEvent_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<TimeEvent> element(new TimeEventImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock()){
		wp->setOwnedParameteredElement(element);
	}
	return element;
}


std::shared_ptr<TimeExpression> UmlFactoryImpl::createTimeExpression_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<TimeExpression> element(new TimeExpressionImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<TimeExpression> UmlFactoryImpl::createTimeExpression_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<TimeExpression> element(new TimeExpressionImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock()){
		wp->setOwnedParameteredElement(element);
	}
	return element;
}


std::shared_ptr<TimeInterval> UmlFactoryImpl::createTimeInterval_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<TimeInterval> element(new TimeIntervalImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<TimeInterval> UmlFactoryImpl::createTimeInterval_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<TimeInterval> element(new TimeIntervalImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock()){
		wp->setOwnedParameteredElement(element);
	}
	return element;
}


std::shared_ptr<TimeObservation> UmlFactoryImpl::createTimeObservation_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<TimeObservation> element(new TimeObservationImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<TimeObservation> UmlFactoryImpl::createTimeObservation_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<TimeObservation> element(new TimeObservationImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock()){
		wp->setOwnedParameteredElement(element);
	}
	return element;
}


std::shared_ptr<Transition> UmlFactoryImpl::createTransition_in_Container(std::weak_ptr<uml::Region > par_container) const
{
	std::shared_ptr<Transition> element(new TransitionImpl(par_container));
	if(auto wp = par_container.lock()){
    	wp->getTransition()->push_back(element);
	}
	return element;
}


std::shared_ptr<Trigger> UmlFactoryImpl::createTrigger_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Trigger> element(new TriggerImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}


std::shared_ptr<UnmarshallAction> UmlFactoryImpl::createUnmarshallAction_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<UnmarshallAction> element(new UnmarshallActionImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<UnmarshallAction> UmlFactoryImpl::createUnmarshallAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<UnmarshallAction> element(new UnmarshallActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<Usage> UmlFactoryImpl::createUsage_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Usage> element(new UsageImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<Usage> UmlFactoryImpl::createUsage_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Usage> element(new UsageImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock()){
		wp->setOwnedParameteredElement(element);
	}
	return element;
}
std::shared_ptr<Usage> UmlFactoryImpl::createUsage_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Usage> element(new UsageImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<UseCase> UmlFactoryImpl::createUseCase_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<UseCase> element(new UseCaseImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<UseCase> UmlFactoryImpl::createUseCase_in_Package(std::shared_ptr<uml::Package > par_package) const
{
	std::shared_ptr<UseCase> element(new UseCaseImpl(par_package));
	if(nullptr != par_package){
    	par_package->getOwnedType()->push_back(element);
	}
	return element;
}
std::shared_ptr<UseCase> UmlFactoryImpl::createUseCase_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<UseCase> element(new UseCaseImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<ValuePin> UmlFactoryImpl::createValuePin_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ValuePin> element(new ValuePinImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<ValuePin> UmlFactoryImpl::createValuePin_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ValuePin> element(new ValuePinImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<ValuePin> UmlFactoryImpl::createValuePin_in_Namespace(std::shared_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ValuePin> element(new ValuePinImpl(par_namespace));
	if(nullptr != par_namespace){
    	par_namespace->getOwnedMember()->push_back(element);
	}
	return element;
}
std::shared_ptr<ValuePin> UmlFactoryImpl::createValuePin_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ValuePin> element(new ValuePinImpl(par_owner));
	if(auto wp = par_owner.lock()){
    	wp->getOwnedElement()->push_back(element);
	}
	return element;
}


std::shared_ptr<ValueSpecificationAction> UmlFactoryImpl::createValueSpecificationAction_in_Activity(std::shared_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ValueSpecificationAction> element(new ValueSpecificationActionImpl(par_activity));
	if(nullptr != par_activity){
    	par_activity->getNode()->push_back(element);
	}
	return element;
}
std::shared_ptr<ValueSpecificationAction> UmlFactoryImpl::createValueSpecificationAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ValueSpecificationAction> element(new ValueSpecificationActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock()){
    	wp->getNode()->push_back(element);
	}
	return element;
}


std::shared_ptr<Variable> UmlFactoryImpl::createVariable_in_ActivityScope(std::weak_ptr<uml::Activity > par_activityScope) const
{
	std::shared_ptr<Variable> element(new VariableImpl(par_activityScope));
	if(auto wp = par_activityScope.lock()){
    	wp->getVariable()->push_back(element);
	}
	return element;
}
std::shared_ptr<Variable> UmlFactoryImpl::createVariable_in_Scope(std::weak_ptr<uml::StructuredActivityNode > par_scope) const
{
	std::shared_ptr<Variable> element(new VariableImpl(par_scope));
	if(auto wp = par_scope.lock()){
    	wp->getVariable()->push_back(element);
	}
	return element;
}

//Class without container
std::shared_ptr<Factory> UmlFactoryImpl::createFactory() const
{
	return std::shared_ptr<Factory>(new FactoryImpl());
}
//Class without container
std::shared_ptr<Object> UmlFactoryImpl::createObject() const
{
	return std::shared_ptr<Object>(new ObjectImpl());
}

std::shared_ptr<UmlPackage> UmlFactoryImpl::getUmlPackage() const
{
	return UmlPackage::eInstance();
}
