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
			if (nullptr == container)
			{
				return std::shared_ptr<Abstraction>(this->createAbstraction());
			}
			else
			{
				switch(referenceID)
				{
					//Abstraction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createAbstraction_in_Namespace(castedContainer);
					}
					//Abstraction has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createAbstraction_in_Owner(castedContainer);
					}
					//Abstraction has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createAbstraction_in_OwningPackage(castedContainer);
					}
					//Abstraction has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createAbstraction_in_OwningTemplateParameter(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::ACCEPTCALLACTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<AcceptCallAction>(this->createAcceptCallAction());
			}
			else
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
					//AcceptCallAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createAcceptCallAction_in_Namespace(castedContainer);
					}
					//AcceptCallAction has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createAcceptCallAction_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::ACCEPTEVENTACTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<AcceptEventAction>(this->createAcceptEventAction());
			}
			else
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
					//AcceptEventAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createAcceptEventAction_in_Namespace(castedContainer);
					}
					//AcceptEventAction has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createAcceptEventAction_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::ACTIONEXECUTIONSPECIFICATION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ActionExecutionSpecification>(this->createActionExecutionSpecification());
			}
			else
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
					//ActionExecutionSpecification has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createActionExecutionSpecification_in_Namespace(castedContainer);
					}
					//ActionExecutionSpecification has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createActionExecutionSpecification_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::ACTIONINPUTPIN:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ActionInputPin>(this->createActionInputPin());
			}
			else
			{
				switch(referenceID)
				{
					//ActionInputPin has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createActionInputPin_in_Activity(castedContainer);
					}
					//ActionInputPin has callOperationAction as a containment
					case  UmlPackage::INPUTPIN_CALLOPERATIONACTION: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::CallOperationAction>(container);
						return this->createActionInputPin_in_CallOperationAction(castedContainer);
					}
					//ActionInputPin has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createActionInputPin_in_InStructuredNode(castedContainer);
					}
					//ActionInputPin has invocationAction as a containment
					case  UmlPackage::INPUTPIN_INVOCATIONACTION: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::InvocationAction>(container);
						return this->createActionInputPin_in_InvocationAction(castedContainer);
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
					//ActionInputPin has structuralFeatureAction as a containment
					case  UmlPackage::INPUTPIN_STRUCTURALFEATUREACTION: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuralFeatureAction>(container);
						return this->createActionInputPin_in_StructuralFeatureAction(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::ACTIVITY:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Activity>(this->createActivity());
			}
			else
			{
				switch(referenceID)
				{
					//Activity has behavioredClassifier as a containment
					case  UmlPackage::BEHAVIOR_BEHAVIOREDCLASSIFIER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::BehavioredClassifier>(container);
						return this->createActivity_in_BehavioredClassifier(castedContainer);
					}
					//Activity has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createActivity_in_Namespace(castedContainer);
					}
					//Activity has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createActivity_in_Owner(castedContainer);
					}
					//Activity has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createActivity_in_OwningPackage(castedContainer);
					}
					//Activity has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createActivity_in_OwningTemplateParameter(castedContainer);
					}
					//Activity has package as a containment
					case  UmlPackage::TYPE_PACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createActivity_in_Package(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::ACTIVITYFINALNODE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ActivityFinalNode>(this->createActivityFinalNode());
			}
			else
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
					//ActivityFinalNode has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createActivityFinalNode_in_Namespace(castedContainer);
					}
					//ActivityFinalNode has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createActivityFinalNode_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::ACTIVITYPARAMETERNODE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ActivityParameterNode>(this->createActivityParameterNode());
			}
			else
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
					//ActivityParameterNode has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createActivityParameterNode_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::ACTIVITYPARTITION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ActivityPartition>(this->createActivityPartition());
			}
			else
			{
				switch(referenceID)
				{
					//ActivityPartition has inActivity as a containment
					case  UmlPackage::ACTIVITYGROUP_INACTIVITY: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createActivityPartition_in_InActivity(castedContainer);
					}
					//ActivityPartition has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createActivityPartition_in_Namespace(castedContainer);
					}
					//ActivityPartition has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createActivityPartition_in_Owner(castedContainer);
					}
					//ActivityPartition has superGroup as a containment
					case  UmlPackage::ACTIVITYGROUP_SUPERGROUP: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::ActivityGroup>(container);
						return this->createActivityPartition_in_SuperGroup(castedContainer);
					}
					//ActivityPartition has superPartition as a containment
					case  UmlPackage::ACTIVITYPARTITION_SUPERPARTITION: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::ActivityPartition>(container);
						return this->createActivityPartition_in_SuperPartition(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::ACTOR:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Actor>(this->createActor());
			}
			else
			{
				switch(referenceID)
				{
					//Actor has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createActor_in_Namespace(castedContainer);
					}
					//Actor has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createActor_in_Owner(castedContainer);
					}
					//Actor has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createActor_in_OwningPackage(castedContainer);
					}
					//Actor has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createActor_in_OwningTemplateParameter(castedContainer);
					}
					//Actor has package as a containment
					case  UmlPackage::TYPE_PACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createActor_in_Package(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::ADDSTRUCTURALFEATUREVALUEACTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<AddStructuralFeatureValueAction>(this->createAddStructuralFeatureValueAction());
			}
			else
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
					//AddStructuralFeatureValueAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createAddStructuralFeatureValueAction_in_Namespace(castedContainer);
					}
					//AddStructuralFeatureValueAction has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createAddStructuralFeatureValueAction_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::ADDVARIABLEVALUEACTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<AddVariableValueAction>(this->createAddVariableValueAction());
			}
			else
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
					//AddVariableValueAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createAddVariableValueAction_in_Namespace(castedContainer);
					}
					//AddVariableValueAction has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createAddVariableValueAction_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::ANYRECEIVEEVENT:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<AnyReceiveEvent>(this->createAnyReceiveEvent());
			}
			else
			{
				switch(referenceID)
				{
					//AnyReceiveEvent has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createAnyReceiveEvent_in_Namespace(castedContainer);
					}
					//AnyReceiveEvent has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createAnyReceiveEvent_in_Owner(castedContainer);
					}
					//AnyReceiveEvent has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createAnyReceiveEvent_in_OwningPackage(castedContainer);
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
		}
		case UmlPackage::ARTIFACT:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Artifact>(this->createArtifact());
			}
			else
			{
				switch(referenceID)
				{
					//Artifact has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createArtifact_in_Namespace(castedContainer);
					}
					//Artifact has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createArtifact_in_Owner(castedContainer);
					}
					//Artifact has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createArtifact_in_OwningPackage(castedContainer);
					}
					//Artifact has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createArtifact_in_OwningTemplateParameter(castedContainer);
					}
					//Artifact has package as a containment
					case  UmlPackage::TYPE_PACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createArtifact_in_Package(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::ASSOCIATION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Association>(this->createAssociation());
			}
			else
			{
				switch(referenceID)
				{
					//Association has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createAssociation_in_Namespace(castedContainer);
					}
					//Association has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createAssociation_in_Owner(castedContainer);
					}
					//Association has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createAssociation_in_OwningPackage(castedContainer);
					}
					//Association has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createAssociation_in_OwningTemplateParameter(castedContainer);
					}
					//Association has package as a containment
					case  UmlPackage::TYPE_PACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createAssociation_in_Package(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::ASSOCIATIONCLASS:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<AssociationClass>(this->createAssociationClass());
			}
			else
			{
				switch(referenceID)
				{
					//AssociationClass has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createAssociationClass_in_Namespace(castedContainer);
					}
					//AssociationClass has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createAssociationClass_in_Owner(castedContainer);
					}
					//AssociationClass has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createAssociationClass_in_OwningPackage(castedContainer);
					}
					//AssociationClass has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createAssociationClass_in_OwningTemplateParameter(castedContainer);
					}
					//AssociationClass has package as a containment
					case  UmlPackage::TYPE_PACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createAssociationClass_in_Package(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::BEHAVIOREXECUTIONSPECIFICATION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<BehaviorExecutionSpecification>(this->createBehaviorExecutionSpecification());
			}
			else
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
					//BehaviorExecutionSpecification has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createBehaviorExecutionSpecification_in_Namespace(castedContainer);
					}
					//BehaviorExecutionSpecification has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createBehaviorExecutionSpecification_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::BROADCASTSIGNALACTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<BroadcastSignalAction>(this->createBroadcastSignalAction());
			}
			else
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
					//BroadcastSignalAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createBroadcastSignalAction_in_Namespace(castedContainer);
					}
					//BroadcastSignalAction has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createBroadcastSignalAction_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::CALLBEHAVIORACTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<CallBehaviorAction>(this->createCallBehaviorAction());
			}
			else
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
					//CallBehaviorAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createCallBehaviorAction_in_Namespace(castedContainer);
					}
					//CallBehaviorAction has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createCallBehaviorAction_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::CALLEVENT:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<CallEvent>(this->createCallEvent());
			}
			else
			{
				switch(referenceID)
				{
					//CallEvent has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createCallEvent_in_Namespace(castedContainer);
					}
					//CallEvent has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createCallEvent_in_Owner(castedContainer);
					}
					//CallEvent has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createCallEvent_in_OwningPackage(castedContainer);
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
		}
		case UmlPackage::CALLOPERATIONACTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<CallOperationAction>(this->createCallOperationAction());
			}
			else
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
					//CallOperationAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createCallOperationAction_in_Namespace(castedContainer);
					}
					//CallOperationAction has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createCallOperationAction_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::CENTRALBUFFERNODE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<CentralBufferNode>(this->createCentralBufferNode());
			}
			else
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
					//CentralBufferNode has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createCentralBufferNode_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::CHANGEEVENT:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ChangeEvent>(this->createChangeEvent());
			}
			else
			{
				switch(referenceID)
				{
					//ChangeEvent has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createChangeEvent_in_Namespace(castedContainer);
					}
					//ChangeEvent has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createChangeEvent_in_Owner(castedContainer);
					}
					//ChangeEvent has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createChangeEvent_in_OwningPackage(castedContainer);
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
		}
		case UmlPackage::CLASS:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Class>(this->createClass());
			}
			else
			{
				switch(referenceID)
				{
					//Class has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createClass_in_Namespace(castedContainer);
					}
					//Class has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createClass_in_Owner(castedContainer);
					}
					//Class has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createClass_in_OwningPackage(castedContainer);
					}
					//Class has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createClass_in_OwningTemplateParameter(castedContainer);
					}
					//Class has package as a containment
					case  UmlPackage::TYPE_PACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createClass_in_Package(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::CLASSIFIERTEMPLATEPARAMETER:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ClassifierTemplateParameter>(this->createClassifierTemplateParameter());
			}
			else
			{
				switch(referenceID)
				{
					//ClassifierTemplateParameter has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createClassifierTemplateParameter_in_Owner(castedContainer);
					}
					//ClassifierTemplateParameter has signature as a containment
					case  UmlPackage::TEMPLATEPARAMETER_SIGNATURE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateSignature>(container);
						return this->createClassifierTemplateParameter_in_Signature(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::CLAUSE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Clause>(this->createClause());
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
				assert(castedContainer);
				return std::shared_ptr<Clause>(this->createClause_in_Owner(castedContainer));
			}
		}
		case UmlPackage::CLEARASSOCIATIONACTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ClearAssociationAction>(this->createClearAssociationAction());
			}
			else
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
					//ClearAssociationAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createClearAssociationAction_in_Namespace(castedContainer);
					}
					//ClearAssociationAction has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createClearAssociationAction_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::CLEARSTRUCTURALFEATUREACTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ClearStructuralFeatureAction>(this->createClearStructuralFeatureAction());
			}
			else
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
					//ClearStructuralFeatureAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createClearStructuralFeatureAction_in_Namespace(castedContainer);
					}
					//ClearStructuralFeatureAction has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createClearStructuralFeatureAction_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::CLEARVARIABLEACTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ClearVariableAction>(this->createClearVariableAction());
			}
			else
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
					//ClearVariableAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createClearVariableAction_in_Namespace(castedContainer);
					}
					//ClearVariableAction has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createClearVariableAction_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::COLLABORATION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Collaboration>(this->createCollaboration());
			}
			else
			{
				switch(referenceID)
				{
					//Collaboration has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createCollaboration_in_Namespace(castedContainer);
					}
					//Collaboration has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createCollaboration_in_Owner(castedContainer);
					}
					//Collaboration has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createCollaboration_in_OwningPackage(castedContainer);
					}
					//Collaboration has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createCollaboration_in_OwningTemplateParameter(castedContainer);
					}
					//Collaboration has package as a containment
					case  UmlPackage::TYPE_PACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createCollaboration_in_Package(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::COLLABORATIONUSE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<CollaborationUse>(this->createCollaborationUse());
			}
			else
			{
				switch(referenceID)
				{
					//CollaborationUse has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createCollaborationUse_in_Namespace(castedContainer);
					}
					//CollaborationUse has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createCollaborationUse_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::COMBINEDFRAGMENT:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<CombinedFragment>(this->createCombinedFragment());
			}
			else
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
					//CombinedFragment has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createCombinedFragment_in_Namespace(castedContainer);
					}
					//CombinedFragment has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createCombinedFragment_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::COMMENT:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Comment>(this->createComment());
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
				assert(castedContainer);
				return std::shared_ptr<Comment>(this->createComment_in_Owner(castedContainer));
			}
		}
		case UmlPackage::COMMUNICATIONPATH:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<CommunicationPath>(this->createCommunicationPath());
			}
			else
			{
				switch(referenceID)
				{
					//CommunicationPath has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createCommunicationPath_in_Namespace(castedContainer);
					}
					//CommunicationPath has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createCommunicationPath_in_Owner(castedContainer);
					}
					//CommunicationPath has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createCommunicationPath_in_OwningPackage(castedContainer);
					}
					//CommunicationPath has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createCommunicationPath_in_OwningTemplateParameter(castedContainer);
					}
					//CommunicationPath has package as a containment
					case  UmlPackage::TYPE_PACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createCommunicationPath_in_Package(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::COMPONENT:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Component>(this->createComponent());
			}
			else
			{
				switch(referenceID)
				{
					//Component has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createComponent_in_Namespace(castedContainer);
					}
					//Component has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createComponent_in_Owner(castedContainer);
					}
					//Component has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createComponent_in_OwningPackage(castedContainer);
					}
					//Component has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createComponent_in_OwningTemplateParameter(castedContainer);
					}
					//Component has package as a containment
					case  UmlPackage::TYPE_PACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createComponent_in_Package(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::COMPONENTREALIZATION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ComponentRealization>(this->createComponentRealization());
			}
			else
			{
				switch(referenceID)
				{
					//ComponentRealization has abstraction as a containment
					case  UmlPackage::COMPONENTREALIZATION_ABSTRACTION: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Component>(container);
						return this->createComponentRealization_in_Abstraction(castedContainer);
					}
					//ComponentRealization has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createComponentRealization_in_Namespace(castedContainer);
					}
					//ComponentRealization has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createComponentRealization_in_Owner(castedContainer);
					}
					//ComponentRealization has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createComponentRealization_in_OwningPackage(castedContainer);
					}
					//ComponentRealization has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createComponentRealization_in_OwningTemplateParameter(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::CONDITIONALNODE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ConditionalNode>(this->createConditionalNode());
			}
			else
			{
				switch(referenceID)
				{
					//ConditionalNode has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createConditionalNode_in_Activity(castedContainer);
					}
					//ConditionalNode has inActivity as a containment
					case  UmlPackage::ACTIVITYGROUP_INACTIVITY: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createConditionalNode_in_InActivity(castedContainer);
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
					//ConditionalNode has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createConditionalNode_in_Owner(castedContainer);
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
		}
		case UmlPackage::CONNECTABLEELEMENTTEMPLATEPARAMETER:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ConnectableElementTemplateParameter>(this->createConnectableElementTemplateParameter());
			}
			else
			{
				switch(referenceID)
				{
					//ConnectableElementTemplateParameter has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createConnectableElementTemplateParameter_in_Owner(castedContainer);
					}
					//ConnectableElementTemplateParameter has signature as a containment
					case  UmlPackage::TEMPLATEPARAMETER_SIGNATURE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateSignature>(container);
						return this->createConnectableElementTemplateParameter_in_Signature(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::CONNECTIONPOINTREFERENCE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ConnectionPointReference>(this->createConnectionPointReference());
			}
			else
			{
				switch(referenceID)
				{
					//ConnectionPointReference has container as a containment
					case  UmlPackage::VERTEX_CONTAINER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Region>(container);
						return this->createConnectionPointReference_in_Container(castedContainer);
					}
					//ConnectionPointReference has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createConnectionPointReference_in_Namespace(castedContainer);
					}
					//ConnectionPointReference has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createConnectionPointReference_in_Owner(castedContainer);
					}
					//ConnectionPointReference has state as a containment
					case  UmlPackage::CONNECTIONPOINTREFERENCE_STATE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::State>(container);
						return this->createConnectionPointReference_in_State(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::CONNECTOR:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Connector>(this->createConnector());
			}
			else
			{
				switch(referenceID)
				{
					//Connector has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createConnector_in_Namespace(castedContainer);
					}
					//Connector has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createConnector_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::CONNECTOREND:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ConnectorEnd>(this->createConnectorEnd());
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
				assert(castedContainer);
				return std::shared_ptr<ConnectorEnd>(this->createConnectorEnd_in_Owner(castedContainer));
			}
		}
		case UmlPackage::CONSIDERIGNOREFRAGMENT:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ConsiderIgnoreFragment>(this->createConsiderIgnoreFragment());
			}
			else
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
					//ConsiderIgnoreFragment has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createConsiderIgnoreFragment_in_Namespace(castedContainer);
					}
					//ConsiderIgnoreFragment has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createConsiderIgnoreFragment_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::CONSTRAINT:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Constraint>(this->createConstraint());
			}
			else
			{
				switch(referenceID)
				{
					//Constraint has context as a containment
					case  UmlPackage::CONSTRAINT_CONTEXT: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createConstraint_in_Context(castedContainer);
					}
					//Constraint has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createConstraint_in_Namespace(castedContainer);
					}
					//Constraint has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createConstraint_in_Owner(castedContainer);
					}
					//Constraint has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createConstraint_in_OwningPackage(castedContainer);
					}
					//Constraint has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createConstraint_in_OwningTemplateParameter(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::CONTINUATION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Continuation>(this->createContinuation());
			}
			else
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
					//Continuation has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createContinuation_in_Namespace(castedContainer);
					}
					//Continuation has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createContinuation_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::CONTROLFLOW:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ControlFlow>(this->createControlFlow());
			}
			else
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
					//ControlFlow has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createControlFlow_in_Namespace(castedContainer);
					}
					//ControlFlow has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createControlFlow_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::CREATELINKACTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<CreateLinkAction>(this->createCreateLinkAction());
			}
			else
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
					//CreateLinkAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createCreateLinkAction_in_Namespace(castedContainer);
					}
					//CreateLinkAction has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createCreateLinkAction_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::CREATELINKOBJECTACTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<CreateLinkObjectAction>(this->createCreateLinkObjectAction());
			}
			else
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
					//CreateLinkObjectAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createCreateLinkObjectAction_in_Namespace(castedContainer);
					}
					//CreateLinkObjectAction has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createCreateLinkObjectAction_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::CREATEOBJECTACTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<CreateObjectAction>(this->createCreateObjectAction());
			}
			else
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
					//CreateObjectAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createCreateObjectAction_in_Namespace(castedContainer);
					}
					//CreateObjectAction has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createCreateObjectAction_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::DATASTORENODE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<DataStoreNode>(this->createDataStoreNode());
			}
			else
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
					//DataStoreNode has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createDataStoreNode_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::DATATYPE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<DataType>(this->createDataType());
			}
			else
			{
				switch(referenceID)
				{
					//DataType has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createDataType_in_Namespace(castedContainer);
					}
					//DataType has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createDataType_in_Owner(castedContainer);
					}
					//DataType has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createDataType_in_OwningPackage(castedContainer);
					}
					//DataType has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createDataType_in_OwningTemplateParameter(castedContainer);
					}
					//DataType has package as a containment
					case  UmlPackage::TYPE_PACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createDataType_in_Package(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::DECISIONNODE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<DecisionNode>(this->createDecisionNode());
			}
			else
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
					//DecisionNode has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createDecisionNode_in_Namespace(castedContainer);
					}
					//DecisionNode has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createDecisionNode_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::DEPENDENCY:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Dependency>(this->createDependency());
			}
			else
			{
				switch(referenceID)
				{
					//Dependency has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createDependency_in_Namespace(castedContainer);
					}
					//Dependency has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createDependency_in_Owner(castedContainer);
					}
					//Dependency has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createDependency_in_OwningPackage(castedContainer);
					}
					//Dependency has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createDependency_in_OwningTemplateParameter(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::DEPLOYMENT:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Deployment>(this->createDeployment());
			}
			else
			{
				switch(referenceID)
				{
					//Deployment has location as a containment
					case  UmlPackage::DEPLOYMENT_LOCATION: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::DeploymentTarget>(container);
						return this->createDeployment_in_Location(castedContainer);
					}
					//Deployment has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createDeployment_in_Namespace(castedContainer);
					}
					//Deployment has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createDeployment_in_Owner(castedContainer);
					}
					//Deployment has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createDeployment_in_OwningPackage(castedContainer);
					}
					//Deployment has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createDeployment_in_OwningTemplateParameter(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::DEPLOYMENTSPECIFICATION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<DeploymentSpecification>(this->createDeploymentSpecification());
			}
			else
			{
				switch(referenceID)
				{
					//DeploymentSpecification has deployment as a containment
					case  UmlPackage::DEPLOYMENTSPECIFICATION_DEPLOYMENT: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Deployment>(container);
						return this->createDeploymentSpecification_in_Deployment(castedContainer);
					}
					//DeploymentSpecification has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createDeploymentSpecification_in_Namespace(castedContainer);
					}
					//DeploymentSpecification has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createDeploymentSpecification_in_Owner(castedContainer);
					}
					//DeploymentSpecification has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createDeploymentSpecification_in_OwningPackage(castedContainer);
					}
					//DeploymentSpecification has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createDeploymentSpecification_in_OwningTemplateParameter(castedContainer);
					}
					//DeploymentSpecification has package as a containment
					case  UmlPackage::TYPE_PACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createDeploymentSpecification_in_Package(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::DESTROYLINKACTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<DestroyLinkAction>(this->createDestroyLinkAction());
			}
			else
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
					//DestroyLinkAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createDestroyLinkAction_in_Namespace(castedContainer);
					}
					//DestroyLinkAction has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createDestroyLinkAction_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::DESTROYOBJECTACTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<DestroyObjectAction>(this->createDestroyObjectAction());
			}
			else
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
					//DestroyObjectAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createDestroyObjectAction_in_Namespace(castedContainer);
					}
					//DestroyObjectAction has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createDestroyObjectAction_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::DESTRUCTIONOCCURRENCESPECIFICATION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<DestructionOccurrenceSpecification>(this->createDestructionOccurrenceSpecification());
			}
			else
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
					//DestructionOccurrenceSpecification has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createDestructionOccurrenceSpecification_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::DEVICE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Device>(this->createDevice());
			}
			else
			{
				switch(referenceID)
				{
					//Device has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createDevice_in_Namespace(castedContainer);
					}
					//Device has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createDevice_in_Owner(castedContainer);
					}
					//Device has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createDevice_in_OwningPackage(castedContainer);
					}
					//Device has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createDevice_in_OwningTemplateParameter(castedContainer);
					}
					//Device has package as a containment
					case  UmlPackage::TYPE_PACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createDevice_in_Package(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::DURATION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Duration>(this->createDuration());
			}
			else
			{
				switch(referenceID)
				{
					//Duration has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createDuration_in_Namespace(castedContainer);
					}
					//Duration has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createDuration_in_Owner(castedContainer);
					}
					//Duration has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createDuration_in_OwningPackage(castedContainer);
					}
					//Duration has owningSlot as a containment
					case  UmlPackage::VALUESPECIFICATION_OWNINGSLOT: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Slot>(container);
						return this->createDuration_in_OwningSlot(castedContainer);
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
		}
		case UmlPackage::DURATIONCONSTRAINT:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<DurationConstraint>(this->createDurationConstraint());
			}
			else
			{
				switch(referenceID)
				{
					//DurationConstraint has context as a containment
					case  UmlPackage::CONSTRAINT_CONTEXT: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createDurationConstraint_in_Context(castedContainer);
					}
					//DurationConstraint has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createDurationConstraint_in_Namespace(castedContainer);
					}
					//DurationConstraint has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createDurationConstraint_in_Owner(castedContainer);
					}
					//DurationConstraint has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createDurationConstraint_in_OwningPackage(castedContainer);
					}
					//DurationConstraint has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createDurationConstraint_in_OwningTemplateParameter(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::DURATIONINTERVAL:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<DurationInterval>(this->createDurationInterval());
			}
			else
			{
				switch(referenceID)
				{
					//DurationInterval has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createDurationInterval_in_Namespace(castedContainer);
					}
					//DurationInterval has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createDurationInterval_in_Owner(castedContainer);
					}
					//DurationInterval has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createDurationInterval_in_OwningPackage(castedContainer);
					}
					//DurationInterval has owningSlot as a containment
					case  UmlPackage::VALUESPECIFICATION_OWNINGSLOT: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Slot>(container);
						return this->createDurationInterval_in_OwningSlot(castedContainer);
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
		}
		case UmlPackage::DURATIONOBSERVATION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<DurationObservation>(this->createDurationObservation());
			}
			else
			{
				switch(referenceID)
				{
					//DurationObservation has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createDurationObservation_in_Namespace(castedContainer);
					}
					//DurationObservation has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createDurationObservation_in_Owner(castedContainer);
					}
					//DurationObservation has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createDurationObservation_in_OwningPackage(castedContainer);
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
		}
		case UmlPackage::ELEMENTIMPORT:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ElementImport>(this->createElementImport());
			}
			else
			{
				switch(referenceID)
				{
					//ElementImport has importingNamespace as a containment
					case  UmlPackage::ELEMENTIMPORT_IMPORTINGNAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createElementImport_in_ImportingNamespace(castedContainer);
					}
					//ElementImport has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createElementImport_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::ENUMERATION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Enumeration>(this->createEnumeration());
			}
			else
			{
				switch(referenceID)
				{
					//Enumeration has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createEnumeration_in_Namespace(castedContainer);
					}
					//Enumeration has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createEnumeration_in_Owner(castedContainer);
					}
					//Enumeration has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createEnumeration_in_OwningPackage(castedContainer);
					}
					//Enumeration has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createEnumeration_in_OwningTemplateParameter(castedContainer);
					}
					//Enumeration has package as a containment
					case  UmlPackage::TYPE_PACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createEnumeration_in_Package(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::ENUMERATIONLITERAL:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<EnumerationLiteral>(this->createEnumerationLiteral());
			}
			else
			{
				switch(referenceID)
				{
					//EnumerationLiteral has enumeration as a containment
					case  UmlPackage::ENUMERATIONLITERAL_ENUMERATION: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Enumeration>(container);
						return this->createEnumerationLiteral_in_Enumeration(castedContainer);
					}
					//EnumerationLiteral has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createEnumerationLiteral_in_Namespace(castedContainer);
					}
					//EnumerationLiteral has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createEnumerationLiteral_in_Owner(castedContainer);
					}
					//EnumerationLiteral has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createEnumerationLiteral_in_OwningPackage(castedContainer);
					}
					//EnumerationLiteral has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createEnumerationLiteral_in_OwningTemplateParameter(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::EXCEPTIONHANDLER:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ExceptionHandler>(this->createExceptionHandler());
			}
			else
			{
				switch(referenceID)
				{
					//ExceptionHandler has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createExceptionHandler_in_Owner(castedContainer);
					}
					//ExceptionHandler has protectedNode as a containment
					case  UmlPackage::EXCEPTIONHANDLER_PROTECTEDNODE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::ExecutableNode>(container);
						return this->createExceptionHandler_in_ProtectedNode(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::EXECUTIONENVIRONMENT:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ExecutionEnvironment>(this->createExecutionEnvironment());
			}
			else
			{
				switch(referenceID)
				{
					//ExecutionEnvironment has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createExecutionEnvironment_in_Namespace(castedContainer);
					}
					//ExecutionEnvironment has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createExecutionEnvironment_in_Owner(castedContainer);
					}
					//ExecutionEnvironment has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createExecutionEnvironment_in_OwningPackage(castedContainer);
					}
					//ExecutionEnvironment has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createExecutionEnvironment_in_OwningTemplateParameter(castedContainer);
					}
					//ExecutionEnvironment has package as a containment
					case  UmlPackage::TYPE_PACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createExecutionEnvironment_in_Package(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::EXECUTIONOCCURRENCESPECIFICATION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ExecutionOccurrenceSpecification>(this->createExecutionOccurrenceSpecification());
			}
			else
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
					//ExecutionOccurrenceSpecification has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createExecutionOccurrenceSpecification_in_Namespace(castedContainer);
					}
					//ExecutionOccurrenceSpecification has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createExecutionOccurrenceSpecification_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::EXPANSIONNODE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ExpansionNode>(this->createExpansionNode());
			}
			else
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
					//ExpansionNode has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createExpansionNode_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::EXPANSIONREGION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ExpansionRegion>(this->createExpansionRegion());
			}
			else
			{
				switch(referenceID)
				{
					//ExpansionRegion has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createExpansionRegion_in_Activity(castedContainer);
					}
					//ExpansionRegion has inActivity as a containment
					case  UmlPackage::ACTIVITYGROUP_INACTIVITY: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createExpansionRegion_in_InActivity(castedContainer);
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
					//ExpansionRegion has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createExpansionRegion_in_Owner(castedContainer);
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
		}
		case UmlPackage::EXPRESSION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Expression>(this->createExpression());
			}
			else
			{
				switch(referenceID)
				{
					//Expression has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createExpression_in_Namespace(castedContainer);
					}
					//Expression has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createExpression_in_Owner(castedContainer);
					}
					//Expression has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createExpression_in_OwningPackage(castedContainer);
					}
					//Expression has owningSlot as a containment
					case  UmlPackage::VALUESPECIFICATION_OWNINGSLOT: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Slot>(container);
						return this->createExpression_in_OwningSlot(castedContainer);
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
		}
		case UmlPackage::EXTEND:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Extend>(this->createExtend());
			}
			else
			{
				switch(referenceID)
				{
					//Extend has extension as a containment
					case  UmlPackage::EXTEND_EXTENSION: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::UseCase>(container);
						return this->createExtend_in_Extension(castedContainer);
					}
					//Extend has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createExtend_in_Namespace(castedContainer);
					}
					//Extend has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createExtend_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::EXTENSION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Extension>(this->createExtension());
			}
			else
			{
				switch(referenceID)
				{
					//Extension has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createExtension_in_Namespace(castedContainer);
					}
					//Extension has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createExtension_in_Owner(castedContainer);
					}
					//Extension has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createExtension_in_OwningPackage(castedContainer);
					}
					//Extension has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createExtension_in_OwningTemplateParameter(castedContainer);
					}
					//Extension has package as a containment
					case  UmlPackage::TYPE_PACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createExtension_in_Package(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::EXTENSIONEND:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ExtensionEnd>(this->createExtensionEnd());
			}
			else
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
					//ExtensionEnd has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createExtensionEnd_in_Namespace(castedContainer);
					}
					//ExtensionEnd has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createExtensionEnd_in_Owner(castedContainer);
					}
					//ExtensionEnd has owningAssociation as a containment
					case  UmlPackage::PROPERTY_OWNINGASSOCIATION: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Association>(container);
						return this->createExtensionEnd_in_OwningAssociation(castedContainer);
					}
					//ExtensionEnd has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createExtensionEnd_in_OwningTemplateParameter(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::EXTENSIONPOINT:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ExtensionPoint>(this->createExtensionPoint());
			}
			else
			{
				switch(referenceID)
				{
					//ExtensionPoint has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createExtensionPoint_in_Namespace(castedContainer);
					}
					//ExtensionPoint has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createExtensionPoint_in_Owner(castedContainer);
					}
					//ExtensionPoint has useCase as a containment
					case  UmlPackage::EXTENSIONPOINT_USECASE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::UseCase>(container);
						return this->createExtensionPoint_in_UseCase(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::FACTORY:
		{
				return std::shared_ptr<Factory>(this->createFactory());
			
		}
		case UmlPackage::FINALSTATE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<FinalState>(this->createFinalState());
			}
			else
			{
				switch(referenceID)
				{
					//FinalState has container as a containment
					case  UmlPackage::VERTEX_CONTAINER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Region>(container);
						return this->createFinalState_in_Container(castedContainer);
					}
					//FinalState has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createFinalState_in_Namespace(castedContainer);
					}
					//FinalState has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createFinalState_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::FLOWFINALNODE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<FlowFinalNode>(this->createFlowFinalNode());
			}
			else
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
					//FlowFinalNode has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createFlowFinalNode_in_Namespace(castedContainer);
					}
					//FlowFinalNode has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createFlowFinalNode_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::FORKNODE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ForkNode>(this->createForkNode());
			}
			else
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
					//ForkNode has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createForkNode_in_Namespace(castedContainer);
					}
					//ForkNode has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createForkNode_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::FUNCTIONBEHAVIOR:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<FunctionBehavior>(this->createFunctionBehavior());
			}
			else
			{
				switch(referenceID)
				{
					//FunctionBehavior has behavioredClassifier as a containment
					case  UmlPackage::BEHAVIOR_BEHAVIOREDCLASSIFIER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::BehavioredClassifier>(container);
						return this->createFunctionBehavior_in_BehavioredClassifier(castedContainer);
					}
					//FunctionBehavior has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createFunctionBehavior_in_Namespace(castedContainer);
					}
					//FunctionBehavior has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createFunctionBehavior_in_Owner(castedContainer);
					}
					//FunctionBehavior has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createFunctionBehavior_in_OwningPackage(castedContainer);
					}
					//FunctionBehavior has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createFunctionBehavior_in_OwningTemplateParameter(castedContainer);
					}
					//FunctionBehavior has package as a containment
					case  UmlPackage::TYPE_PACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createFunctionBehavior_in_Package(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::GATE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Gate>(this->createGate());
			}
			else
			{
				switch(referenceID)
				{
					//Gate has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createGate_in_Namespace(castedContainer);
					}
					//Gate has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createGate_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::GENERALORDERING:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<GeneralOrdering>(this->createGeneralOrdering());
			}
			else
			{
				switch(referenceID)
				{
					//GeneralOrdering has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createGeneralOrdering_in_Namespace(castedContainer);
					}
					//GeneralOrdering has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createGeneralOrdering_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::GENERALIZATION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Generalization>(this->createGeneralization());
			}
			else
			{
				switch(referenceID)
				{
					//Generalization has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createGeneralization_in_Owner(castedContainer);
					}
					//Generalization has specific as a containment
					case  UmlPackage::GENERALIZATION_SPECIFIC: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Classifier>(container);
						return this->createGeneralization_in_Specific(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::GENERALIZATIONSET:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<GeneralizationSet>(this->createGeneralizationSet());
			}
			else
			{
				switch(referenceID)
				{
					//GeneralizationSet has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createGeneralizationSet_in_Namespace(castedContainer);
					}
					//GeneralizationSet has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createGeneralizationSet_in_Owner(castedContainer);
					}
					//GeneralizationSet has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createGeneralizationSet_in_OwningPackage(castedContainer);
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
		}
		case UmlPackage::IMAGE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Image>(this->createImage());
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
				assert(castedContainer);
				return std::shared_ptr<Image>(this->createImage_in_Owner(castedContainer));
			}
		}
		case UmlPackage::INCLUDE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Include>(this->createInclude());
			}
			else
			{
				switch(referenceID)
				{
					//Include has includingCase as a containment
					case  UmlPackage::INCLUDE_INCLUDINGCASE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::UseCase>(container);
						return this->createInclude_in_IncludingCase(castedContainer);
					}
					//Include has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createInclude_in_Namespace(castedContainer);
					}
					//Include has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createInclude_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::INFORMATIONFLOW:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<InformationFlow>(this->createInformationFlow());
			}
			else
			{
				switch(referenceID)
				{
					//InformationFlow has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createInformationFlow_in_Namespace(castedContainer);
					}
					//InformationFlow has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createInformationFlow_in_Owner(castedContainer);
					}
					//InformationFlow has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createInformationFlow_in_OwningPackage(castedContainer);
					}
					//InformationFlow has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createInformationFlow_in_OwningTemplateParameter(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::INFORMATIONITEM:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<InformationItem>(this->createInformationItem());
			}
			else
			{
				switch(referenceID)
				{
					//InformationItem has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createInformationItem_in_Namespace(castedContainer);
					}
					//InformationItem has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createInformationItem_in_Owner(castedContainer);
					}
					//InformationItem has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createInformationItem_in_OwningPackage(castedContainer);
					}
					//InformationItem has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createInformationItem_in_OwningTemplateParameter(castedContainer);
					}
					//InformationItem has package as a containment
					case  UmlPackage::TYPE_PACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createInformationItem_in_Package(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::INITIALNODE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<InitialNode>(this->createInitialNode());
			}
			else
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
					//InitialNode has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createInitialNode_in_Namespace(castedContainer);
					}
					//InitialNode has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createInitialNode_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::INPUTPIN:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<InputPin>(this->createInputPin());
			}
			else
			{
				switch(referenceID)
				{
					//InputPin has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createInputPin_in_Activity(castedContainer);
					}
					//InputPin has callOperationAction as a containment
					case  UmlPackage::INPUTPIN_CALLOPERATIONACTION: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::CallOperationAction>(container);
						return this->createInputPin_in_CallOperationAction(castedContainer);
					}
					//InputPin has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createInputPin_in_InStructuredNode(castedContainer);
					}
					//InputPin has invocationAction as a containment
					case  UmlPackage::INPUTPIN_INVOCATIONACTION: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::InvocationAction>(container);
						return this->createInputPin_in_InvocationAction(castedContainer);
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
					//InputPin has structuralFeatureAction as a containment
					case  UmlPackage::INPUTPIN_STRUCTURALFEATUREACTION: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuralFeatureAction>(container);
						return this->createInputPin_in_StructuralFeatureAction(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::INSTANCESPECIFICATION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<InstanceSpecification>(this->createInstanceSpecification());
			}
			else
			{
				switch(referenceID)
				{
					//InstanceSpecification has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createInstanceSpecification_in_Namespace(castedContainer);
					}
					//InstanceSpecification has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createInstanceSpecification_in_Owner(castedContainer);
					}
					//InstanceSpecification has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createInstanceSpecification_in_OwningPackage(castedContainer);
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
		}
		case UmlPackage::INSTANCEVALUE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<InstanceValue>(this->createInstanceValue());
			}
			else
			{
				switch(referenceID)
				{
					//InstanceValue has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createInstanceValue_in_Namespace(castedContainer);
					}
					//InstanceValue has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createInstanceValue_in_Owner(castedContainer);
					}
					//InstanceValue has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createInstanceValue_in_OwningPackage(castedContainer);
					}
					//InstanceValue has owningSlot as a containment
					case  UmlPackage::VALUESPECIFICATION_OWNINGSLOT: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Slot>(container);
						return this->createInstanceValue_in_OwningSlot(castedContainer);
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
		}
		case UmlPackage::INTERACTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Interaction>(this->createInteraction());
			}
			else
			{
				switch(referenceID)
				{
					//Interaction has behavioredClassifier as a containment
					case  UmlPackage::BEHAVIOR_BEHAVIOREDCLASSIFIER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::BehavioredClassifier>(container);
						return this->createInteraction_in_BehavioredClassifier(castedContainer);
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
					//Interaction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createInteraction_in_Namespace(castedContainer);
					}
					//Interaction has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createInteraction_in_Owner(castedContainer);
					}
					//Interaction has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createInteraction_in_OwningPackage(castedContainer);
					}
					//Interaction has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createInteraction_in_OwningTemplateParameter(castedContainer);
					}
					//Interaction has package as a containment
					case  UmlPackage::TYPE_PACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createInteraction_in_Package(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::INTERACTIONCONSTRAINT:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<InteractionConstraint>(this->createInteractionConstraint());
			}
			else
			{
				switch(referenceID)
				{
					//InteractionConstraint has context as a containment
					case  UmlPackage::CONSTRAINT_CONTEXT: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createInteractionConstraint_in_Context(castedContainer);
					}
					//InteractionConstraint has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createInteractionConstraint_in_Namespace(castedContainer);
					}
					//InteractionConstraint has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createInteractionConstraint_in_Owner(castedContainer);
					}
					//InteractionConstraint has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createInteractionConstraint_in_OwningPackage(castedContainer);
					}
					//InteractionConstraint has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createInteractionConstraint_in_OwningTemplateParameter(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::INTERACTIONOPERAND:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<InteractionOperand>(this->createInteractionOperand());
			}
			else
			{
				switch(referenceID)
				{
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
					//InteractionOperand has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createInteractionOperand_in_Namespace(castedContainer);
					}
					//InteractionOperand has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createInteractionOperand_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::INTERACTIONUSE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<InteractionUse>(this->createInteractionUse());
			}
			else
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
					//InteractionUse has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createInteractionUse_in_Namespace(castedContainer);
					}
					//InteractionUse has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createInteractionUse_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::INTERFACE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Interface>(this->createInterface());
			}
			else
			{
				switch(referenceID)
				{
					//Interface has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createInterface_in_Namespace(castedContainer);
					}
					//Interface has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createInterface_in_Owner(castedContainer);
					}
					//Interface has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createInterface_in_OwningPackage(castedContainer);
					}
					//Interface has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createInterface_in_OwningTemplateParameter(castedContainer);
					}
					//Interface has package as a containment
					case  UmlPackage::TYPE_PACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createInterface_in_Package(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::INTERFACEREALIZATION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<InterfaceRealization>(this->createInterfaceRealization());
			}
			else
			{
				switch(referenceID)
				{
					//InterfaceRealization has implementingClassifier as a containment
					case  UmlPackage::INTERFACEREALIZATION_IMPLEMENTINGCLASSIFIER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::BehavioredClassifier>(container);
						return this->createInterfaceRealization_in_ImplementingClassifier(castedContainer);
					}
					//InterfaceRealization has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createInterfaceRealization_in_Namespace(castedContainer);
					}
					//InterfaceRealization has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createInterfaceRealization_in_Owner(castedContainer);
					}
					//InterfaceRealization has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createInterfaceRealization_in_OwningPackage(castedContainer);
					}
					//InterfaceRealization has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createInterfaceRealization_in_OwningTemplateParameter(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::INTERRUPTIBLEACTIVITYREGION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<InterruptibleActivityRegion>(this->createInterruptibleActivityRegion());
			}
			else
			{
				switch(referenceID)
				{
					//InterruptibleActivityRegion has inActivity as a containment
					case  UmlPackage::ACTIVITYGROUP_INACTIVITY: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createInterruptibleActivityRegion_in_InActivity(castedContainer);
					}
					//InterruptibleActivityRegion has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createInterruptibleActivityRegion_in_Namespace(castedContainer);
					}
					//InterruptibleActivityRegion has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createInterruptibleActivityRegion_in_Owner(castedContainer);
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
		}
		case UmlPackage::INTERVAL:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Interval>(this->createInterval());
			}
			else
			{
				switch(referenceID)
				{
					//Interval has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createInterval_in_Namespace(castedContainer);
					}
					//Interval has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createInterval_in_Owner(castedContainer);
					}
					//Interval has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createInterval_in_OwningPackage(castedContainer);
					}
					//Interval has owningSlot as a containment
					case  UmlPackage::VALUESPECIFICATION_OWNINGSLOT: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Slot>(container);
						return this->createInterval_in_OwningSlot(castedContainer);
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
		}
		case UmlPackage::INTERVALCONSTRAINT:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<IntervalConstraint>(this->createIntervalConstraint());
			}
			else
			{
				switch(referenceID)
				{
					//IntervalConstraint has context as a containment
					case  UmlPackage::CONSTRAINT_CONTEXT: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createIntervalConstraint_in_Context(castedContainer);
					}
					//IntervalConstraint has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createIntervalConstraint_in_Namespace(castedContainer);
					}
					//IntervalConstraint has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createIntervalConstraint_in_Owner(castedContainer);
					}
					//IntervalConstraint has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createIntervalConstraint_in_OwningPackage(castedContainer);
					}
					//IntervalConstraint has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createIntervalConstraint_in_OwningTemplateParameter(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::JOINNODE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<JoinNode>(this->createJoinNode());
			}
			else
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
					//JoinNode has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createJoinNode_in_Namespace(castedContainer);
					}
					//JoinNode has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createJoinNode_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::LIFELINE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Lifeline>(this->createLifeline());
			}
			else
			{
				switch(referenceID)
				{
					//Lifeline has interaction as a containment
					case  UmlPackage::LIFELINE_INTERACTION: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Interaction>(container);
						return this->createLifeline_in_Interaction(castedContainer);
					}
					//Lifeline has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createLifeline_in_Namespace(castedContainer);
					}
					//Lifeline has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createLifeline_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::LINKENDCREATIONDATA:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<LinkEndCreationData>(this->createLinkEndCreationData());
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
				assert(castedContainer);
				return std::shared_ptr<LinkEndCreationData>(this->createLinkEndCreationData_in_Owner(castedContainer));
			}
		}
		case UmlPackage::LINKENDDATA:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<LinkEndData>(this->createLinkEndData());
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
				assert(castedContainer);
				return std::shared_ptr<LinkEndData>(this->createLinkEndData_in_Owner(castedContainer));
			}
		}
		case UmlPackage::LINKENDDESTRUCTIONDATA:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<LinkEndDestructionData>(this->createLinkEndDestructionData());
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
				assert(castedContainer);
				return std::shared_ptr<LinkEndDestructionData>(this->createLinkEndDestructionData_in_Owner(castedContainer));
			}
		}
		case UmlPackage::LITERALBOOLEAN:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<LiteralBoolean>(this->createLiteralBoolean());
			}
			else
			{
				switch(referenceID)
				{
					//LiteralBoolean has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createLiteralBoolean_in_Namespace(castedContainer);
					}
					//LiteralBoolean has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createLiteralBoolean_in_Owner(castedContainer);
					}
					//LiteralBoolean has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createLiteralBoolean_in_OwningPackage(castedContainer);
					}
					//LiteralBoolean has owningSlot as a containment
					case  UmlPackage::VALUESPECIFICATION_OWNINGSLOT: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Slot>(container);
						return this->createLiteralBoolean_in_OwningSlot(castedContainer);
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
		}
		case UmlPackage::LITERALINTEGER:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<LiteralInteger>(this->createLiteralInteger());
			}
			else
			{
				switch(referenceID)
				{
					//LiteralInteger has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createLiteralInteger_in_Namespace(castedContainer);
					}
					//LiteralInteger has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createLiteralInteger_in_Owner(castedContainer);
					}
					//LiteralInteger has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createLiteralInteger_in_OwningPackage(castedContainer);
					}
					//LiteralInteger has owningSlot as a containment
					case  UmlPackage::VALUESPECIFICATION_OWNINGSLOT: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Slot>(container);
						return this->createLiteralInteger_in_OwningSlot(castedContainer);
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
		}
		case UmlPackage::LITERALNULL:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<LiteralNull>(this->createLiteralNull());
			}
			else
			{
				switch(referenceID)
				{
					//LiteralNull has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createLiteralNull_in_Namespace(castedContainer);
					}
					//LiteralNull has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createLiteralNull_in_Owner(castedContainer);
					}
					//LiteralNull has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createLiteralNull_in_OwningPackage(castedContainer);
					}
					//LiteralNull has owningSlot as a containment
					case  UmlPackage::VALUESPECIFICATION_OWNINGSLOT: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Slot>(container);
						return this->createLiteralNull_in_OwningSlot(castedContainer);
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
		}
		case UmlPackage::LITERALREAL:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<LiteralReal>(this->createLiteralReal());
			}
			else
			{
				switch(referenceID)
				{
					//LiteralReal has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createLiteralReal_in_Namespace(castedContainer);
					}
					//LiteralReal has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createLiteralReal_in_Owner(castedContainer);
					}
					//LiteralReal has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createLiteralReal_in_OwningPackage(castedContainer);
					}
					//LiteralReal has owningSlot as a containment
					case  UmlPackage::VALUESPECIFICATION_OWNINGSLOT: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Slot>(container);
						return this->createLiteralReal_in_OwningSlot(castedContainer);
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
		}
		case UmlPackage::LITERALSTRING:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<LiteralString>(this->createLiteralString());
			}
			else
			{
				switch(referenceID)
				{
					//LiteralString has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createLiteralString_in_Namespace(castedContainer);
					}
					//LiteralString has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createLiteralString_in_Owner(castedContainer);
					}
					//LiteralString has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createLiteralString_in_OwningPackage(castedContainer);
					}
					//LiteralString has owningSlot as a containment
					case  UmlPackage::VALUESPECIFICATION_OWNINGSLOT: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Slot>(container);
						return this->createLiteralString_in_OwningSlot(castedContainer);
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
		}
		case UmlPackage::LITERALUNLIMITEDNATURAL:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<LiteralUnlimitedNatural>(this->createLiteralUnlimitedNatural());
			}
			else
			{
				switch(referenceID)
				{
					//LiteralUnlimitedNatural has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createLiteralUnlimitedNatural_in_Namespace(castedContainer);
					}
					//LiteralUnlimitedNatural has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createLiteralUnlimitedNatural_in_Owner(castedContainer);
					}
					//LiteralUnlimitedNatural has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createLiteralUnlimitedNatural_in_OwningPackage(castedContainer);
					}
					//LiteralUnlimitedNatural has owningSlot as a containment
					case  UmlPackage::VALUESPECIFICATION_OWNINGSLOT: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Slot>(container);
						return this->createLiteralUnlimitedNatural_in_OwningSlot(castedContainer);
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
		}
		case UmlPackage::LOOPNODE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<LoopNode>(this->createLoopNode());
			}
			else
			{
				switch(referenceID)
				{
					//LoopNode has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createLoopNode_in_Activity(castedContainer);
					}
					//LoopNode has inActivity as a containment
					case  UmlPackage::ACTIVITYGROUP_INACTIVITY: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createLoopNode_in_InActivity(castedContainer);
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
					//LoopNode has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createLoopNode_in_Owner(castedContainer);
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
		}
		case UmlPackage::MANIFESTATION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Manifestation>(this->createManifestation());
			}
			else
			{
				switch(referenceID)
				{
					//Manifestation has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createManifestation_in_Namespace(castedContainer);
					}
					//Manifestation has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createManifestation_in_Owner(castedContainer);
					}
					//Manifestation has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createManifestation_in_OwningPackage(castedContainer);
					}
					//Manifestation has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createManifestation_in_OwningTemplateParameter(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::MERGENODE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<MergeNode>(this->createMergeNode());
			}
			else
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
					//MergeNode has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createMergeNode_in_Namespace(castedContainer);
					}
					//MergeNode has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createMergeNode_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::MESSAGE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Message>(this->createMessage());
			}
			else
			{
				switch(referenceID)
				{
					//Message has interaction as a containment
					case  UmlPackage::MESSAGE_INTERACTION: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Interaction>(container);
						return this->createMessage_in_Interaction(castedContainer);
					}
					//Message has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createMessage_in_Namespace(castedContainer);
					}
					//Message has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createMessage_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::MESSAGEOCCURRENCESPECIFICATION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<MessageOccurrenceSpecification>(this->createMessageOccurrenceSpecification());
			}
			else
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
					//MessageOccurrenceSpecification has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createMessageOccurrenceSpecification_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::MODEL:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Model>(this->createModel());
			}
			else
			{
				switch(referenceID)
				{
					//Model has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createModel_in_Namespace(castedContainer);
					}
					//Model has nestingPackage as a containment
					case  UmlPackage::PACKAGE_NESTINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createModel_in_NestingPackage(castedContainer);
					}
					//Model has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createModel_in_Owner(castedContainer);
					}
					//Model has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createModel_in_OwningPackage(castedContainer);
					}
					//Model has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createModel_in_OwningTemplateParameter(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::NODE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Node>(this->createNode());
			}
			else
			{
				switch(referenceID)
				{
					//Node has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createNode_in_Namespace(castedContainer);
					}
					//Node has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createNode_in_Owner(castedContainer);
					}
					//Node has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createNode_in_OwningPackage(castedContainer);
					}
					//Node has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createNode_in_OwningTemplateParameter(castedContainer);
					}
					//Node has package as a containment
					case  UmlPackage::TYPE_PACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createNode_in_Package(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::OBJECT:
		{
				return std::shared_ptr<Object>(this->createObject());
			
		}
		case UmlPackage::OBJECTFLOW:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ObjectFlow>(this->createObjectFlow());
			}
			else
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
					//ObjectFlow has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createObjectFlow_in_Namespace(castedContainer);
					}
					//ObjectFlow has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createObjectFlow_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::OCCURRENCESPECIFICATION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<OccurrenceSpecification>(this->createOccurrenceSpecification());
			}
			else
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
					//OccurrenceSpecification has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createOccurrenceSpecification_in_Namespace(castedContainer);
					}
					//OccurrenceSpecification has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createOccurrenceSpecification_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::OPAQUEACTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<OpaqueAction>(this->createOpaqueAction());
			}
			else
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
					//OpaqueAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createOpaqueAction_in_Namespace(castedContainer);
					}
					//OpaqueAction has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createOpaqueAction_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::OPAQUEBEHAVIOR:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<OpaqueBehavior>(this->createOpaqueBehavior());
			}
			else
			{
				switch(referenceID)
				{
					//OpaqueBehavior has behavioredClassifier as a containment
					case  UmlPackage::BEHAVIOR_BEHAVIOREDCLASSIFIER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::BehavioredClassifier>(container);
						return this->createOpaqueBehavior_in_BehavioredClassifier(castedContainer);
					}
					//OpaqueBehavior has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createOpaqueBehavior_in_Namespace(castedContainer);
					}
					//OpaqueBehavior has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createOpaqueBehavior_in_Owner(castedContainer);
					}
					//OpaqueBehavior has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createOpaqueBehavior_in_OwningPackage(castedContainer);
					}
					//OpaqueBehavior has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createOpaqueBehavior_in_OwningTemplateParameter(castedContainer);
					}
					//OpaqueBehavior has package as a containment
					case  UmlPackage::TYPE_PACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createOpaqueBehavior_in_Package(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::OPAQUEEXPRESSION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<OpaqueExpression>(this->createOpaqueExpression());
			}
			else
			{
				switch(referenceID)
				{
					//OpaqueExpression has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createOpaqueExpression_in_Namespace(castedContainer);
					}
					//OpaqueExpression has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createOpaqueExpression_in_Owner(castedContainer);
					}
					//OpaqueExpression has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createOpaqueExpression_in_OwningPackage(castedContainer);
					}
					//OpaqueExpression has owningSlot as a containment
					case  UmlPackage::VALUESPECIFICATION_OWNINGSLOT: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Slot>(container);
						return this->createOpaqueExpression_in_OwningSlot(castedContainer);
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
		}
		case UmlPackage::OPERATION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Operation>(this->createOperation());
			}
			else
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
					//Operation has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createOperation_in_Namespace(castedContainer);
					}
					//Operation has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createOperation_in_Owner(castedContainer);
					}
					//Operation has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createOperation_in_OwningTemplateParameter(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::OPERATIONTEMPLATEPARAMETER:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<OperationTemplateParameter>(this->createOperationTemplateParameter());
			}
			else
			{
				switch(referenceID)
				{
					//OperationTemplateParameter has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createOperationTemplateParameter_in_Owner(castedContainer);
					}
					//OperationTemplateParameter has signature as a containment
					case  UmlPackage::TEMPLATEPARAMETER_SIGNATURE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateSignature>(container);
						return this->createOperationTemplateParameter_in_Signature(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::OUTPUTPIN:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<OutputPin>(this->createOutputPin());
			}
			else
			{
				switch(referenceID)
				{
					//OutputPin has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createOutputPin_in_Activity(castedContainer);
					}
					//OutputPin has callAction as a containment
					case  UmlPackage::OUTPUTPIN_CALLACTION: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::CallAction>(container);
						return this->createOutputPin_in_CallAction(castedContainer);
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
		}
		case UmlPackage::PACKAGE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Package>(this->createPackage());
			}
			else
			{
				switch(referenceID)
				{
					//Package has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createPackage_in_Namespace(castedContainer);
					}
					//Package has nestingPackage as a containment
					case  UmlPackage::PACKAGE_NESTINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createPackage_in_NestingPackage(castedContainer);
					}
					//Package has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createPackage_in_Owner(castedContainer);
					}
					//Package has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createPackage_in_OwningPackage(castedContainer);
					}
					//Package has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createPackage_in_OwningTemplateParameter(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::PACKAGEIMPORT:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<PackageImport>(this->createPackageImport());
			}
			else
			{
				switch(referenceID)
				{
					//PackageImport has importingNamespace as a containment
					case  UmlPackage::PACKAGEIMPORT_IMPORTINGNAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createPackageImport_in_ImportingNamespace(castedContainer);
					}
					//PackageImport has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createPackageImport_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::PACKAGEMERGE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<PackageMerge>(this->createPackageMerge());
			}
			else
			{
				switch(referenceID)
				{
					//PackageMerge has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createPackageMerge_in_Owner(castedContainer);
					}
					//PackageMerge has receivingPackage as a containment
					case  UmlPackage::PACKAGEMERGE_RECEIVINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createPackageMerge_in_ReceivingPackage(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::PARAMETER:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Parameter>(this->createParameter());
			}
			else
			{
				switch(referenceID)
				{
					//Parameter has behavior as a containment
					case  UmlPackage::PARAMETER_BEHAVIOR: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Behavior>(container);
						return this->createParameter_in_Behavior(castedContainer);
					}
					//Parameter has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createParameter_in_Namespace(castedContainer);
					}
					//Parameter has operation as a containment
					case  UmlPackage::PARAMETER_OPERATION: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Operation>(container);
						return this->createParameter_in_Operation(castedContainer);
					}
					//Parameter has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createParameter_in_Owner(castedContainer);
					}
					//Parameter has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createParameter_in_OwningTemplateParameter(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::PARAMETERSET:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ParameterSet>(this->createParameterSet());
			}
			else
			{
				switch(referenceID)
				{
					//ParameterSet has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createParameterSet_in_Namespace(castedContainer);
					}
					//ParameterSet has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createParameterSet_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::PARTDECOMPOSITION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<PartDecomposition>(this->createPartDecomposition());
			}
			else
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
					//PartDecomposition has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createPartDecomposition_in_Namespace(castedContainer);
					}
					//PartDecomposition has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createPartDecomposition_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::PORT:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Port>(this->createPort());
			}
			else
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
					//Port has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createPort_in_Namespace(castedContainer);
					}
					//Port has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createPort_in_Owner(castedContainer);
					}
					//Port has owningAssociation as a containment
					case  UmlPackage::PROPERTY_OWNINGASSOCIATION: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Association>(container);
						return this->createPort_in_OwningAssociation(castedContainer);
					}
					//Port has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createPort_in_OwningTemplateParameter(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::PRIMITIVETYPE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<PrimitiveType>(this->createPrimitiveType());
			}
			else
			{
				switch(referenceID)
				{
					//PrimitiveType has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createPrimitiveType_in_Namespace(castedContainer);
					}
					//PrimitiveType has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createPrimitiveType_in_Owner(castedContainer);
					}
					//PrimitiveType has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createPrimitiveType_in_OwningPackage(castedContainer);
					}
					//PrimitiveType has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createPrimitiveType_in_OwningTemplateParameter(castedContainer);
					}
					//PrimitiveType has package as a containment
					case  UmlPackage::TYPE_PACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createPrimitiveType_in_Package(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::PROFILE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Profile>(this->createProfile());
			}
			else
			{
				switch(referenceID)
				{
					//Profile has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createProfile_in_Namespace(castedContainer);
					}
					//Profile has nestingPackage as a containment
					case  UmlPackage::PACKAGE_NESTINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createProfile_in_NestingPackage(castedContainer);
					}
					//Profile has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createProfile_in_Owner(castedContainer);
					}
					//Profile has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createProfile_in_OwningPackage(castedContainer);
					}
					//Profile has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createProfile_in_OwningTemplateParameter(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::PROFILEAPPLICATION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ProfileApplication>(this->createProfileApplication());
			}
			else
			{
				switch(referenceID)
				{
					//ProfileApplication has applyingPackage as a containment
					case  UmlPackage::PROFILEAPPLICATION_APPLYINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createProfileApplication_in_ApplyingPackage(castedContainer);
					}
					//ProfileApplication has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createProfileApplication_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::PROPERTY:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Property>(this->createProperty());
			}
			else
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
					//Property has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createProperty_in_Namespace(castedContainer);
					}
					//Property has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createProperty_in_Owner(castedContainer);
					}
					//Property has owningAssociation as a containment
					case  UmlPackage::PROPERTY_OWNINGASSOCIATION: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Association>(container);
						return this->createProperty_in_OwningAssociation(castedContainer);
					}
					//Property has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createProperty_in_OwningTemplateParameter(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::PROTOCOLCONFORMANCE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ProtocolConformance>(this->createProtocolConformance());
			}
			else
			{
				switch(referenceID)
				{
					//ProtocolConformance has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createProtocolConformance_in_Owner(castedContainer);
					}
					//ProtocolConformance has specificMachine as a containment
					case  UmlPackage::PROTOCOLCONFORMANCE_SPECIFICMACHINE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::ProtocolStateMachine>(container);
						return this->createProtocolConformance_in_SpecificMachine(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::PROTOCOLSTATEMACHINE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ProtocolStateMachine>(this->createProtocolStateMachine());
			}
			else
			{
				switch(referenceID)
				{
					//ProtocolStateMachine has behavioredClassifier as a containment
					case  UmlPackage::BEHAVIOR_BEHAVIOREDCLASSIFIER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::BehavioredClassifier>(container);
						return this->createProtocolStateMachine_in_BehavioredClassifier(castedContainer);
					}
					//ProtocolStateMachine has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createProtocolStateMachine_in_Namespace(castedContainer);
					}
					//ProtocolStateMachine has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createProtocolStateMachine_in_Owner(castedContainer);
					}
					//ProtocolStateMachine has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createProtocolStateMachine_in_OwningPackage(castedContainer);
					}
					//ProtocolStateMachine has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createProtocolStateMachine_in_OwningTemplateParameter(castedContainer);
					}
					//ProtocolStateMachine has package as a containment
					case  UmlPackage::TYPE_PACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createProtocolStateMachine_in_Package(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::PROTOCOLTRANSITION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ProtocolTransition>(this->createProtocolTransition());
			}
			else
			{
				switch(referenceID)
				{
					//ProtocolTransition has container as a containment
					case  UmlPackage::TRANSITION_CONTAINER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Region>(container);
						return this->createProtocolTransition_in_Container(castedContainer);
					}
					//ProtocolTransition has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createProtocolTransition_in_Namespace(castedContainer);
					}
					//ProtocolTransition has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createProtocolTransition_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::PSEUDOSTATE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Pseudostate>(this->createPseudostate());
			}
			else
			{
				switch(referenceID)
				{
					//Pseudostate has container as a containment
					case  UmlPackage::VERTEX_CONTAINER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Region>(container);
						return this->createPseudostate_in_Container(castedContainer);
					}
					//Pseudostate has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createPseudostate_in_Namespace(castedContainer);
					}
					//Pseudostate has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createPseudostate_in_Owner(castedContainer);
					}
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
		}
		case UmlPackage::QUALIFIERVALUE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<QualifierValue>(this->createQualifierValue());
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
				assert(castedContainer);
				return std::shared_ptr<QualifierValue>(this->createQualifierValue_in_Owner(castedContainer));
			}
		}
		case UmlPackage::RAISEEXCEPTIONACTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<RaiseExceptionAction>(this->createRaiseExceptionAction());
			}
			else
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
					//RaiseExceptionAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createRaiseExceptionAction_in_Namespace(castedContainer);
					}
					//RaiseExceptionAction has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createRaiseExceptionAction_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::READEXTENTACTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ReadExtentAction>(this->createReadExtentAction());
			}
			else
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
					//ReadExtentAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createReadExtentAction_in_Namespace(castedContainer);
					}
					//ReadExtentAction has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createReadExtentAction_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::READISCLASSIFIEDOBJECTACTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ReadIsClassifiedObjectAction>(this->createReadIsClassifiedObjectAction());
			}
			else
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
					//ReadIsClassifiedObjectAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createReadIsClassifiedObjectAction_in_Namespace(castedContainer);
					}
					//ReadIsClassifiedObjectAction has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createReadIsClassifiedObjectAction_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::READLINKACTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ReadLinkAction>(this->createReadLinkAction());
			}
			else
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
					//ReadLinkAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createReadLinkAction_in_Namespace(castedContainer);
					}
					//ReadLinkAction has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createReadLinkAction_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::READLINKOBJECTENDACTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ReadLinkObjectEndAction>(this->createReadLinkObjectEndAction());
			}
			else
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
					//ReadLinkObjectEndAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createReadLinkObjectEndAction_in_Namespace(castedContainer);
					}
					//ReadLinkObjectEndAction has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createReadLinkObjectEndAction_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::READLINKOBJECTENDQUALIFIERACTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ReadLinkObjectEndQualifierAction>(this->createReadLinkObjectEndQualifierAction());
			}
			else
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
					//ReadLinkObjectEndQualifierAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createReadLinkObjectEndQualifierAction_in_Namespace(castedContainer);
					}
					//ReadLinkObjectEndQualifierAction has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createReadLinkObjectEndQualifierAction_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::READSELFACTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ReadSelfAction>(this->createReadSelfAction());
			}
			else
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
					//ReadSelfAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createReadSelfAction_in_Namespace(castedContainer);
					}
					//ReadSelfAction has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createReadSelfAction_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::READSTRUCTURALFEATUREACTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ReadStructuralFeatureAction>(this->createReadStructuralFeatureAction());
			}
			else
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
					//ReadStructuralFeatureAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createReadStructuralFeatureAction_in_Namespace(castedContainer);
					}
					//ReadStructuralFeatureAction has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createReadStructuralFeatureAction_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::READVARIABLEACTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ReadVariableAction>(this->createReadVariableAction());
			}
			else
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
					//ReadVariableAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createReadVariableAction_in_Namespace(castedContainer);
					}
					//ReadVariableAction has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createReadVariableAction_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::REALIZATION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Realization>(this->createRealization());
			}
			else
			{
				switch(referenceID)
				{
					//Realization has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createRealization_in_Namespace(castedContainer);
					}
					//Realization has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createRealization_in_Owner(castedContainer);
					}
					//Realization has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createRealization_in_OwningPackage(castedContainer);
					}
					//Realization has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createRealization_in_OwningTemplateParameter(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::RECEPTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Reception>(this->createReception());
			}
			else
			{
				switch(referenceID)
				{
					//Reception has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createReception_in_Namespace(castedContainer);
					}
					//Reception has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createReception_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::RECLASSIFYOBJECTACTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ReclassifyObjectAction>(this->createReclassifyObjectAction());
			}
			else
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
					//ReclassifyObjectAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createReclassifyObjectAction_in_Namespace(castedContainer);
					}
					//ReclassifyObjectAction has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createReclassifyObjectAction_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::REDEFINABLETEMPLATESIGNATURE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<RedefinableTemplateSignature>(this->createRedefinableTemplateSignature());
			}
			else
			{
				switch(referenceID)
				{
					//RedefinableTemplateSignature has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createRedefinableTemplateSignature_in_Namespace(castedContainer);
					}
					//RedefinableTemplateSignature has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createRedefinableTemplateSignature_in_Owner(castedContainer);
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
		}
		case UmlPackage::REDUCEACTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ReduceAction>(this->createReduceAction());
			}
			else
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
					//ReduceAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createReduceAction_in_Namespace(castedContainer);
					}
					//ReduceAction has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createReduceAction_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::REGION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Region>(this->createRegion());
			}
			else
			{
				switch(referenceID)
				{
					//Region has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createRegion_in_Namespace(castedContainer);
					}
					//Region has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createRegion_in_Owner(castedContainer);
					}
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
		}
		case UmlPackage::REMOVESTRUCTURALFEATUREVALUEACTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<RemoveStructuralFeatureValueAction>(this->createRemoveStructuralFeatureValueAction());
			}
			else
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
					//RemoveStructuralFeatureValueAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createRemoveStructuralFeatureValueAction_in_Namespace(castedContainer);
					}
					//RemoveStructuralFeatureValueAction has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createRemoveStructuralFeatureValueAction_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::REMOVEVARIABLEVALUEACTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<RemoveVariableValueAction>(this->createRemoveVariableValueAction());
			}
			else
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
					//RemoveVariableValueAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createRemoveVariableValueAction_in_Namespace(castedContainer);
					}
					//RemoveVariableValueAction has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createRemoveVariableValueAction_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::REPLYACTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ReplyAction>(this->createReplyAction());
			}
			else
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
					//ReplyAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createReplyAction_in_Namespace(castedContainer);
					}
					//ReplyAction has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createReplyAction_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::SENDOBJECTACTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<SendObjectAction>(this->createSendObjectAction());
			}
			else
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
					//SendObjectAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createSendObjectAction_in_Namespace(castedContainer);
					}
					//SendObjectAction has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createSendObjectAction_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::SENDSIGNALACTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<SendSignalAction>(this->createSendSignalAction());
			}
			else
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
					//SendSignalAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createSendSignalAction_in_Namespace(castedContainer);
					}
					//SendSignalAction has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createSendSignalAction_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::SEQUENCENODE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<SequenceNode>(this->createSequenceNode());
			}
			else
			{
				switch(referenceID)
				{
					//SequenceNode has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createSequenceNode_in_Activity(castedContainer);
					}
					//SequenceNode has inActivity as a containment
					case  UmlPackage::ACTIVITYGROUP_INACTIVITY: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createSequenceNode_in_InActivity(castedContainer);
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
					//SequenceNode has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createSequenceNode_in_Owner(castedContainer);
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
		}
		case UmlPackage::SIGNAL:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Signal>(this->createSignal());
			}
			else
			{
				switch(referenceID)
				{
					//Signal has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createSignal_in_Namespace(castedContainer);
					}
					//Signal has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createSignal_in_Owner(castedContainer);
					}
					//Signal has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createSignal_in_OwningPackage(castedContainer);
					}
					//Signal has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createSignal_in_OwningTemplateParameter(castedContainer);
					}
					//Signal has package as a containment
					case  UmlPackage::TYPE_PACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createSignal_in_Package(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::SIGNALEVENT:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<SignalEvent>(this->createSignalEvent());
			}
			else
			{
				switch(referenceID)
				{
					//SignalEvent has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createSignalEvent_in_Namespace(castedContainer);
					}
					//SignalEvent has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createSignalEvent_in_Owner(castedContainer);
					}
					//SignalEvent has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createSignalEvent_in_OwningPackage(castedContainer);
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
		}
		case UmlPackage::SLOT:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Slot>(this->createSlot());
			}
			else
			{
				switch(referenceID)
				{
					//Slot has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createSlot_in_Owner(castedContainer);
					}
					//Slot has owningInstance as a containment
					case  UmlPackage::SLOT_OWNINGINSTANCE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::InstanceSpecification>(container);
						return this->createSlot_in_OwningInstance(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::STARTCLASSIFIERBEHAVIORACTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<StartClassifierBehaviorAction>(this->createStartClassifierBehaviorAction());
			}
			else
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
					//StartClassifierBehaviorAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createStartClassifierBehaviorAction_in_Namespace(castedContainer);
					}
					//StartClassifierBehaviorAction has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createStartClassifierBehaviorAction_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::STARTOBJECTBEHAVIORACTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<StartObjectBehaviorAction>(this->createStartObjectBehaviorAction());
			}
			else
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
					//StartObjectBehaviorAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createStartObjectBehaviorAction_in_Namespace(castedContainer);
					}
					//StartObjectBehaviorAction has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createStartObjectBehaviorAction_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::STATE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<State>(this->createState());
			}
			else
			{
				switch(referenceID)
				{
					//State has container as a containment
					case  UmlPackage::VERTEX_CONTAINER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Region>(container);
						return this->createState_in_Container(castedContainer);
					}
					//State has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createState_in_Namespace(castedContainer);
					}
					//State has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createState_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::STATEINVARIANT:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<StateInvariant>(this->createStateInvariant());
			}
			else
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
					//StateInvariant has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createStateInvariant_in_Namespace(castedContainer);
					}
					//StateInvariant has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createStateInvariant_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::STATEMACHINE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<StateMachine>(this->createStateMachine());
			}
			else
			{
				switch(referenceID)
				{
					//StateMachine has behavioredClassifier as a containment
					case  UmlPackage::BEHAVIOR_BEHAVIOREDCLASSIFIER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::BehavioredClassifier>(container);
						return this->createStateMachine_in_BehavioredClassifier(castedContainer);
					}
					//StateMachine has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createStateMachine_in_Namespace(castedContainer);
					}
					//StateMachine has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createStateMachine_in_Owner(castedContainer);
					}
					//StateMachine has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createStateMachine_in_OwningPackage(castedContainer);
					}
					//StateMachine has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createStateMachine_in_OwningTemplateParameter(castedContainer);
					}
					//StateMachine has package as a containment
					case  UmlPackage::TYPE_PACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createStateMachine_in_Package(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::STEREOTYPE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Stereotype>(this->createStereotype());
			}
			else
			{
				switch(referenceID)
				{
					//Stereotype has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createStereotype_in_Namespace(castedContainer);
					}
					//Stereotype has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createStereotype_in_Owner(castedContainer);
					}
					//Stereotype has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createStereotype_in_OwningPackage(castedContainer);
					}
					//Stereotype has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createStereotype_in_OwningTemplateParameter(castedContainer);
					}
					//Stereotype has package as a containment
					case  UmlPackage::TYPE_PACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createStereotype_in_Package(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::STRINGEXPRESSION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<StringExpression>(this->createStringExpression());
			}
			else
			{
				switch(referenceID)
				{
					//StringExpression has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createStringExpression_in_Namespace(castedContainer);
					}
					//StringExpression has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createStringExpression_in_Owner(castedContainer);
					}
					//StringExpression has owningExpression as a containment
					case  UmlPackage::STRINGEXPRESSION_OWNINGEXPRESSION: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StringExpression>(container);
						return this->createStringExpression_in_OwningExpression(castedContainer);
					}
					//StringExpression has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createStringExpression_in_OwningPackage(castedContainer);
					}
					//StringExpression has owningSlot as a containment
					case  UmlPackage::VALUESPECIFICATION_OWNINGSLOT: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Slot>(container);
						return this->createStringExpression_in_OwningSlot(castedContainer);
					}
					//StringExpression has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createStringExpression_in_OwningTemplateParameter(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::STRUCTUREDACTIVITYNODE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<StructuredActivityNode>(this->createStructuredActivityNode());
			}
			else
			{
				switch(referenceID)
				{
					//StructuredActivityNode has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createStructuredActivityNode_in_Activity(castedContainer);
					}
					//StructuredActivityNode has inActivity as a containment
					case  UmlPackage::ACTIVITYGROUP_INACTIVITY: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createStructuredActivityNode_in_InActivity(castedContainer);
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
					//StructuredActivityNode has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createStructuredActivityNode_in_Owner(castedContainer);
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
		}
		case UmlPackage::SUBSTITUTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Substitution>(this->createSubstitution());
			}
			else
			{
				switch(referenceID)
				{
					//Substitution has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createSubstitution_in_Namespace(castedContainer);
					}
					//Substitution has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createSubstitution_in_Owner(castedContainer);
					}
					//Substitution has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createSubstitution_in_OwningPackage(castedContainer);
					}
					//Substitution has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createSubstitution_in_OwningTemplateParameter(castedContainer);
					}
					//Substitution has substitutingClassifier as a containment
					case  UmlPackage::SUBSTITUTION_SUBSTITUTINGCLASSIFIER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Classifier>(container);
						return this->createSubstitution_in_SubstitutingClassifier(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::TEMPLATEBINDING:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<TemplateBinding>(this->createTemplateBinding());
			}
			else
			{
				switch(referenceID)
				{
					//TemplateBinding has boundElement as a containment
					case  UmlPackage::TEMPLATEBINDING_BOUNDELEMENT: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateableElement>(container);
						return this->createTemplateBinding_in_BoundElement(castedContainer);
					}
					//TemplateBinding has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createTemplateBinding_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::TEMPLATEPARAMETER:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<TemplateParameter>(this->createTemplateParameter());
			}
			else
			{
				switch(referenceID)
				{
					//TemplateParameter has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createTemplateParameter_in_Owner(castedContainer);
					}
					//TemplateParameter has signature as a containment
					case  UmlPackage::TEMPLATEPARAMETER_SIGNATURE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateSignature>(container);
						return this->createTemplateParameter_in_Signature(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::TEMPLATEPARAMETERSUBSTITUTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<TemplateParameterSubstitution>(this->createTemplateParameterSubstitution());
			}
			else
			{
				switch(referenceID)
				{
					//TemplateParameterSubstitution has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createTemplateParameterSubstitution_in_Owner(castedContainer);
					}
					//TemplateParameterSubstitution has templateBinding as a containment
					case  UmlPackage::TEMPLATEPARAMETERSUBSTITUTION_TEMPLATEBINDING: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateBinding>(container);
						return this->createTemplateParameterSubstitution_in_TemplateBinding(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::TEMPLATESIGNATURE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<TemplateSignature>(this->createTemplateSignature());
			}
			else
			{
				switch(referenceID)
				{
					//TemplateSignature has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createTemplateSignature_in_Owner(castedContainer);
					}
					//TemplateSignature has template as a containment
					case  UmlPackage::TEMPLATESIGNATURE_TEMPLATE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateableElement>(container);
						return this->createTemplateSignature_in_Template(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::TESTIDENTITYACTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<TestIdentityAction>(this->createTestIdentityAction());
			}
			else
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
					//TestIdentityAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createTestIdentityAction_in_Namespace(castedContainer);
					}
					//TestIdentityAction has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createTestIdentityAction_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::TIMECONSTRAINT:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<TimeConstraint>(this->createTimeConstraint());
			}
			else
			{
				switch(referenceID)
				{
					//TimeConstraint has context as a containment
					case  UmlPackage::CONSTRAINT_CONTEXT: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createTimeConstraint_in_Context(castedContainer);
					}
					//TimeConstraint has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createTimeConstraint_in_Namespace(castedContainer);
					}
					//TimeConstraint has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createTimeConstraint_in_Owner(castedContainer);
					}
					//TimeConstraint has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createTimeConstraint_in_OwningPackage(castedContainer);
					}
					//TimeConstraint has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createTimeConstraint_in_OwningTemplateParameter(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::TIMEEVENT:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<TimeEvent>(this->createTimeEvent());
			}
			else
			{
				switch(referenceID)
				{
					//TimeEvent has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createTimeEvent_in_Namespace(castedContainer);
					}
					//TimeEvent has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createTimeEvent_in_Owner(castedContainer);
					}
					//TimeEvent has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createTimeEvent_in_OwningPackage(castedContainer);
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
		}
		case UmlPackage::TIMEEXPRESSION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<TimeExpression>(this->createTimeExpression());
			}
			else
			{
				switch(referenceID)
				{
					//TimeExpression has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createTimeExpression_in_Namespace(castedContainer);
					}
					//TimeExpression has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createTimeExpression_in_Owner(castedContainer);
					}
					//TimeExpression has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createTimeExpression_in_OwningPackage(castedContainer);
					}
					//TimeExpression has owningSlot as a containment
					case  UmlPackage::VALUESPECIFICATION_OWNINGSLOT: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Slot>(container);
						return this->createTimeExpression_in_OwningSlot(castedContainer);
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
		}
		case UmlPackage::TIMEINTERVAL:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<TimeInterval>(this->createTimeInterval());
			}
			else
			{
				switch(referenceID)
				{
					//TimeInterval has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createTimeInterval_in_Namespace(castedContainer);
					}
					//TimeInterval has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createTimeInterval_in_Owner(castedContainer);
					}
					//TimeInterval has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createTimeInterval_in_OwningPackage(castedContainer);
					}
					//TimeInterval has owningSlot as a containment
					case  UmlPackage::VALUESPECIFICATION_OWNINGSLOT: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Slot>(container);
						return this->createTimeInterval_in_OwningSlot(castedContainer);
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
		}
		case UmlPackage::TIMEOBSERVATION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<TimeObservation>(this->createTimeObservation());
			}
			else
			{
				switch(referenceID)
				{
					//TimeObservation has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createTimeObservation_in_Namespace(castedContainer);
					}
					//TimeObservation has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createTimeObservation_in_Owner(castedContainer);
					}
					//TimeObservation has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createTimeObservation_in_OwningPackage(castedContainer);
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
		}
		case UmlPackage::TRANSITION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Transition>(this->createTransition());
			}
			else
			{
				switch(referenceID)
				{
					//Transition has container as a containment
					case  UmlPackage::TRANSITION_CONTAINER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Region>(container);
						return this->createTransition_in_Container(castedContainer);
					}
					//Transition has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createTransition_in_Namespace(castedContainer);
					}
					//Transition has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createTransition_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::TRIGGER:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Trigger>(this->createTrigger());
			}
			else
			{
				switch(referenceID)
				{
					//Trigger has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createTrigger_in_Namespace(castedContainer);
					}
					//Trigger has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createTrigger_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::UNMARSHALLACTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<UnmarshallAction>(this->createUnmarshallAction());
			}
			else
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
					//UnmarshallAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createUnmarshallAction_in_Namespace(castedContainer);
					}
					//UnmarshallAction has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createUnmarshallAction_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::USAGE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Usage>(this->createUsage());
			}
			else
			{
				switch(referenceID)
				{
					//Usage has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createUsage_in_Namespace(castedContainer);
					}
					//Usage has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createUsage_in_Owner(castedContainer);
					}
					//Usage has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createUsage_in_OwningPackage(castedContainer);
					}
					//Usage has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createUsage_in_OwningTemplateParameter(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::USECASE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<UseCase>(this->createUseCase());
			}
			else
			{
				switch(referenceID)
				{
					//UseCase has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createUseCase_in_Namespace(castedContainer);
					}
					//UseCase has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createUseCase_in_Owner(castedContainer);
					}
					//UseCase has owningPackage as a containment
					case  UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createUseCase_in_OwningPackage(castedContainer);
					}
					//UseCase has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createUseCase_in_OwningTemplateParameter(castedContainer);
					}
					//UseCase has package as a containment
					case  UmlPackage::TYPE_PACKAGE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Package>(container);
						return this->createUseCase_in_Package(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::VALUEPIN:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ValuePin>(this->createValuePin());
			}
			else
			{
				switch(referenceID)
				{
					//ValuePin has activity as a containment
					case  UmlPackage::ACTIVITYNODE_ACTIVITY: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createValuePin_in_Activity(castedContainer);
					}
					//ValuePin has callOperationAction as a containment
					case  UmlPackage::INPUTPIN_CALLOPERATIONACTION: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::CallOperationAction>(container);
						return this->createValuePin_in_CallOperationAction(castedContainer);
					}
					//ValuePin has inStructuredNode as a containment
					case  UmlPackage::ACTIVITYNODE_INSTRUCTUREDNODE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuredActivityNode>(container);
						return this->createValuePin_in_InStructuredNode(castedContainer);
					}
					//ValuePin has invocationAction as a containment
					case  UmlPackage::INPUTPIN_INVOCATIONACTION: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::InvocationAction>(container);
						return this->createValuePin_in_InvocationAction(castedContainer);
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
					//ValuePin has structuralFeatureAction as a containment
					case  UmlPackage::INPUTPIN_STRUCTURALFEATUREACTION: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::StructuralFeatureAction>(container);
						return this->createValuePin_in_StructuralFeatureAction(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::VALUESPECIFICATIONACTION:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ValueSpecificationAction>(this->createValueSpecificationAction());
			}
			else
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
					//ValueSpecificationAction has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createValueSpecificationAction_in_Namespace(castedContainer);
					}
					//ValueSpecificationAction has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createValueSpecificationAction_in_Owner(castedContainer);
					}
					default:
						std::cerr << __PRETTY_FUNCTION__ << "ERROR: Reference type not found." << std::endl;
				}
			}
		}
		case UmlPackage::VARIABLE:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<Variable>(this->createVariable());
			}
			else
			{
				switch(referenceID)
				{
					//Variable has activityScope as a containment
					case  UmlPackage::VARIABLE_ACTIVITYSCOPE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Activity>(container);
						return this->createVariable_in_ActivityScope(castedContainer);
					}
					//Variable has namespace as a containment
					case  UmlPackage::NAMEDELEMENT_NAMESPACE: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Namespace>(container);
						return this->createVariable_in_Namespace(castedContainer);
					}
					//Variable has owner as a containment
					case  UmlPackage::ELEMENT_OWNER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::Element>(container);
						return this->createVariable_in_Owner(castedContainer);
					}
					//Variable has owningTemplateParameter as a containment
					case  UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER: 
					{
						auto castedContainer = std::dynamic_pointer_cast<uml::TemplateParameter>(container);
						return this->createVariable_in_OwningTemplateParameter(castedContainer);
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
		}
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << classID <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<ecore::EObject> UmlFactoryImpl::create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container /* = nullptr*/) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}

	std::string _className = _class->eClass()->getName();
	return create(_className, _container);
}

std::shared_ptr<ecore::EObject> UmlFactoryImpl::create(std::string _className) const
{
	auto iter = m_idMap.find(_className);
	if(iter != m_idMap.end())
    {
		//get the ID
        unsigned int id = iter->second;
		return create(id);
    }

    return nullptr;
}

std::shared_ptr<ecore::EObject> UmlFactoryImpl::create(std::string _className, std::shared_ptr<EObject> _container, const unsigned int referenceID) const
{
	auto iter = m_idMap.find(_className);
	if(iter != m_idMap.end())
    {
		//get the ID
        unsigned int id = iter->second;
		return create(id, _container, referenceID);
    }

    return nullptr;
}


std::shared_ptr<Abstraction> UmlFactoryImpl::createAbstraction() const
{
	std::shared_ptr<Abstraction> element(new AbstractionImpl());
	return element;
}
std::shared_ptr<Abstraction> UmlFactoryImpl::createAbstraction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Abstraction> element(new AbstractionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Abstraction> UmlFactoryImpl::createAbstraction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Abstraction> element(new AbstractionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Abstraction> UmlFactoryImpl::createAbstraction_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<Abstraction> element(new AbstractionImpl(par_owningPackage));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Abstraction> UmlFactoryImpl::createAbstraction_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Abstraction> element(new AbstractionImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<AcceptCallAction> UmlFactoryImpl::createAcceptCallAction() const
{
	std::shared_ptr<AcceptCallAction> element(new AcceptCallActionImpl());
	return element;
}
std::shared_ptr<AcceptCallAction> UmlFactoryImpl::createAcceptCallAction_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<AcceptCallAction> element(new AcceptCallActionImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<AcceptCallAction> UmlFactoryImpl::createAcceptCallAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<AcceptCallAction> element(new AcceptCallActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<AcceptCallAction> UmlFactoryImpl::createAcceptCallAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<AcceptCallAction> element(new AcceptCallActionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<AcceptCallAction> UmlFactoryImpl::createAcceptCallAction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<AcceptCallAction> element(new AcceptCallActionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<AcceptEventAction> UmlFactoryImpl::createAcceptEventAction() const
{
	std::shared_ptr<AcceptEventAction> element(new AcceptEventActionImpl());
	return element;
}
std::shared_ptr<AcceptEventAction> UmlFactoryImpl::createAcceptEventAction_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<AcceptEventAction> element(new AcceptEventActionImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<AcceptEventAction> UmlFactoryImpl::createAcceptEventAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<AcceptEventAction> element(new AcceptEventActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<AcceptEventAction> UmlFactoryImpl::createAcceptEventAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<AcceptEventAction> element(new AcceptEventActionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<AcceptEventAction> UmlFactoryImpl::createAcceptEventAction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<AcceptEventAction> element(new AcceptEventActionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ActionExecutionSpecification> UmlFactoryImpl::createActionExecutionSpecification() const
{
	std::shared_ptr<ActionExecutionSpecification> element(new ActionExecutionSpecificationImpl());
	return element;
}
std::shared_ptr<ActionExecutionSpecification> UmlFactoryImpl::createActionExecutionSpecification_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction) const
{
	std::shared_ptr<ActionExecutionSpecification> element(new ActionExecutionSpecificationImpl(par_enclosingInteraction));
	if(auto wp = par_enclosingInteraction.lock())
	{
    		wp->getFragment()->push_back(element);
	}
	return element;
}

std::shared_ptr<ActionExecutionSpecification> UmlFactoryImpl::createActionExecutionSpecification_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand) const
{
	std::shared_ptr<ActionExecutionSpecification> element(new ActionExecutionSpecificationImpl(par_enclosingOperand));
	if(auto wp = par_enclosingOperand.lock())
	{
    		wp->getFragment()->push_back(element);
	}
	return element;
}

std::shared_ptr<ActionExecutionSpecification> UmlFactoryImpl::createActionExecutionSpecification_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ActionExecutionSpecification> element(new ActionExecutionSpecificationImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<ActionExecutionSpecification> UmlFactoryImpl::createActionExecutionSpecification_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ActionExecutionSpecification> element(new ActionExecutionSpecificationImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ActionInputPin> UmlFactoryImpl::createActionInputPin() const
{
	std::shared_ptr<ActionInputPin> element(new ActionInputPinImpl());
	return element;
}
std::shared_ptr<ActionInputPin> UmlFactoryImpl::createActionInputPin_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ActionInputPin> element(new ActionInputPinImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ActionInputPin> UmlFactoryImpl::createActionInputPin_in_CallOperationAction(std::weak_ptr<uml::CallOperationAction > par_callOperationAction) const
{
	std::shared_ptr<ActionInputPin> element(new ActionInputPinImpl(par_callOperationAction));
	if(auto wp = par_callOperationAction.lock())
	{
			wp->setTarget(element);
	}
	return element;
}

std::shared_ptr<ActionInputPin> UmlFactoryImpl::createActionInputPin_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ActionInputPin> element(new ActionInputPinImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ActionInputPin> UmlFactoryImpl::createActionInputPin_in_InvocationAction(std::weak_ptr<uml::InvocationAction > par_invocationAction) const
{
	std::shared_ptr<ActionInputPin> element(new ActionInputPinImpl(par_invocationAction));
	if(auto wp = par_invocationAction.lock())
	{
    		wp->getArgument()->push_back(element);
	}
	return element;
}

std::shared_ptr<ActionInputPin> UmlFactoryImpl::createActionInputPin_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ActionInputPin> element(new ActionInputPinImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<ActionInputPin> UmlFactoryImpl::createActionInputPin_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ActionInputPin> element(new ActionInputPinImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ActionInputPin> UmlFactoryImpl::createActionInputPin_in_StructuralFeatureAction(std::weak_ptr<uml::StructuralFeatureAction > par_structuralFeatureAction) const
{
	std::shared_ptr<ActionInputPin> element(new ActionInputPinImpl(par_structuralFeatureAction));
	if(auto wp = par_structuralFeatureAction.lock())
	{
			wp->setObject(element);
	}
	return element;
}

std::shared_ptr<Activity> UmlFactoryImpl::createActivity() const
{
	std::shared_ptr<Activity> element(new ActivityImpl());
	return element;
}
std::shared_ptr<Activity> UmlFactoryImpl::createActivity_in_BehavioredClassifier(std::weak_ptr<uml::BehavioredClassifier > par_behavioredClassifier) const
{
	std::shared_ptr<Activity> element(new ActivityImpl(par_behavioredClassifier));
	if(auto wp = par_behavioredClassifier.lock())
	{
    		wp->getOwnedBehavior()->push_back(element);
	}
	return element;
}

std::shared_ptr<Activity> UmlFactoryImpl::createActivity_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Activity> element(new ActivityImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Activity> UmlFactoryImpl::createActivity_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Activity> element(new ActivityImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Activity> UmlFactoryImpl::createActivity_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<Activity> element(new ActivityImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Activity> UmlFactoryImpl::createActivity_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Activity> element(new ActivityImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<Activity> UmlFactoryImpl::createActivity_in_Package(std::weak_ptr<uml::Package > par_package) const
{
	std::shared_ptr<Activity> element(new ActivityImpl(par_package, UmlPackage::TYPE_PACKAGE));
	if(auto wp = par_package.lock())
	{
    		wp->getOwnedType()->push_back(element);
	}
	return element;
}

std::shared_ptr<ActivityFinalNode> UmlFactoryImpl::createActivityFinalNode() const
{
	std::shared_ptr<ActivityFinalNode> element(new ActivityFinalNodeImpl());
	return element;
}
std::shared_ptr<ActivityFinalNode> UmlFactoryImpl::createActivityFinalNode_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ActivityFinalNode> element(new ActivityFinalNodeImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ActivityFinalNode> UmlFactoryImpl::createActivityFinalNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ActivityFinalNode> element(new ActivityFinalNodeImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ActivityFinalNode> UmlFactoryImpl::createActivityFinalNode_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ActivityFinalNode> element(new ActivityFinalNodeImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<ActivityFinalNode> UmlFactoryImpl::createActivityFinalNode_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ActivityFinalNode> element(new ActivityFinalNodeImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ActivityParameterNode> UmlFactoryImpl::createActivityParameterNode() const
{
	std::shared_ptr<ActivityParameterNode> element(new ActivityParameterNodeImpl());
	return element;
}
std::shared_ptr<ActivityParameterNode> UmlFactoryImpl::createActivityParameterNode_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ActivityParameterNode> element(new ActivityParameterNodeImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ActivityParameterNode> UmlFactoryImpl::createActivityParameterNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ActivityParameterNode> element(new ActivityParameterNodeImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ActivityParameterNode> UmlFactoryImpl::createActivityParameterNode_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ActivityParameterNode> element(new ActivityParameterNodeImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<ActivityParameterNode> UmlFactoryImpl::createActivityParameterNode_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ActivityParameterNode> element(new ActivityParameterNodeImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ActivityPartition> UmlFactoryImpl::createActivityPartition() const
{
	std::shared_ptr<ActivityPartition> element(new ActivityPartitionImpl());
	return element;
}
std::shared_ptr<ActivityPartition> UmlFactoryImpl::createActivityPartition_in_InActivity(std::weak_ptr<uml::Activity > par_inActivity) const
{
	std::shared_ptr<ActivityPartition> element(new ActivityPartitionImpl(par_inActivity));
	if(auto wp = par_inActivity.lock())
	{
    		wp->getPartition()->push_back(element);
	}
	return element;
}

std::shared_ptr<ActivityPartition> UmlFactoryImpl::createActivityPartition_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ActivityPartition> element(new ActivityPartitionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<ActivityPartition> UmlFactoryImpl::createActivityPartition_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ActivityPartition> element(new ActivityPartitionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ActivityPartition> UmlFactoryImpl::createActivityPartition_in_SuperGroup(std::weak_ptr<uml::ActivityGroup > par_superGroup) const
{
	std::shared_ptr<ActivityPartition> element(new ActivityPartitionImpl(par_superGroup));
	if(auto wp = par_superGroup.lock())
	{
    		wp->getSubgroup()->push_back(element);
	}
	return element;
}

std::shared_ptr<ActivityPartition> UmlFactoryImpl::createActivityPartition_in_SuperPartition(std::weak_ptr<uml::ActivityPartition > par_superPartition) const
{
	std::shared_ptr<ActivityPartition> element(new ActivityPartitionImpl(par_superPartition));
	if(auto wp = par_superPartition.lock())
	{
    		wp->getSubpartition()->push_back(element);
	}
	return element;
}

std::shared_ptr<Actor> UmlFactoryImpl::createActor() const
{
	std::shared_ptr<Actor> element(new ActorImpl());
	return element;
}
std::shared_ptr<Actor> UmlFactoryImpl::createActor_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Actor> element(new ActorImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Actor> UmlFactoryImpl::createActor_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Actor> element(new ActorImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Actor> UmlFactoryImpl::createActor_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<Actor> element(new ActorImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Actor> UmlFactoryImpl::createActor_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Actor> element(new ActorImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<Actor> UmlFactoryImpl::createActor_in_Package(std::weak_ptr<uml::Package > par_package) const
{
	std::shared_ptr<Actor> element(new ActorImpl(par_package, UmlPackage::TYPE_PACKAGE));
	if(auto wp = par_package.lock())
	{
    		wp->getOwnedType()->push_back(element);
	}
	return element;
}

std::shared_ptr<AddStructuralFeatureValueAction> UmlFactoryImpl::createAddStructuralFeatureValueAction() const
{
	std::shared_ptr<AddStructuralFeatureValueAction> element(new AddStructuralFeatureValueActionImpl());
	return element;
}
std::shared_ptr<AddStructuralFeatureValueAction> UmlFactoryImpl::createAddStructuralFeatureValueAction_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<AddStructuralFeatureValueAction> element(new AddStructuralFeatureValueActionImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<AddStructuralFeatureValueAction> UmlFactoryImpl::createAddStructuralFeatureValueAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<AddStructuralFeatureValueAction> element(new AddStructuralFeatureValueActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<AddStructuralFeatureValueAction> UmlFactoryImpl::createAddStructuralFeatureValueAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<AddStructuralFeatureValueAction> element(new AddStructuralFeatureValueActionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<AddStructuralFeatureValueAction> UmlFactoryImpl::createAddStructuralFeatureValueAction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<AddStructuralFeatureValueAction> element(new AddStructuralFeatureValueActionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<AddVariableValueAction> UmlFactoryImpl::createAddVariableValueAction() const
{
	std::shared_ptr<AddVariableValueAction> element(new AddVariableValueActionImpl());
	return element;
}
std::shared_ptr<AddVariableValueAction> UmlFactoryImpl::createAddVariableValueAction_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<AddVariableValueAction> element(new AddVariableValueActionImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<AddVariableValueAction> UmlFactoryImpl::createAddVariableValueAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<AddVariableValueAction> element(new AddVariableValueActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<AddVariableValueAction> UmlFactoryImpl::createAddVariableValueAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<AddVariableValueAction> element(new AddVariableValueActionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<AddVariableValueAction> UmlFactoryImpl::createAddVariableValueAction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<AddVariableValueAction> element(new AddVariableValueActionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<AnyReceiveEvent> UmlFactoryImpl::createAnyReceiveEvent() const
{
	std::shared_ptr<AnyReceiveEvent> element(new AnyReceiveEventImpl());
	return element;
}
std::shared_ptr<AnyReceiveEvent> UmlFactoryImpl::createAnyReceiveEvent_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<AnyReceiveEvent> element(new AnyReceiveEventImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<AnyReceiveEvent> UmlFactoryImpl::createAnyReceiveEvent_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<AnyReceiveEvent> element(new AnyReceiveEventImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<AnyReceiveEvent> UmlFactoryImpl::createAnyReceiveEvent_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<AnyReceiveEvent> element(new AnyReceiveEventImpl(par_owningPackage));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<AnyReceiveEvent> UmlFactoryImpl::createAnyReceiveEvent_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<AnyReceiveEvent> element(new AnyReceiveEventImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<Artifact> UmlFactoryImpl::createArtifact() const
{
	std::shared_ptr<Artifact> element(new ArtifactImpl());
	return element;
}
std::shared_ptr<Artifact> UmlFactoryImpl::createArtifact_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Artifact> element(new ArtifactImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Artifact> UmlFactoryImpl::createArtifact_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Artifact> element(new ArtifactImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Artifact> UmlFactoryImpl::createArtifact_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<Artifact> element(new ArtifactImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Artifact> UmlFactoryImpl::createArtifact_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Artifact> element(new ArtifactImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<Artifact> UmlFactoryImpl::createArtifact_in_Package(std::weak_ptr<uml::Package > par_package) const
{
	std::shared_ptr<Artifact> element(new ArtifactImpl(par_package, UmlPackage::TYPE_PACKAGE));
	if(auto wp = par_package.lock())
	{
    		wp->getOwnedType()->push_back(element);
	}
	return element;
}

std::shared_ptr<Association> UmlFactoryImpl::createAssociation() const
{
	std::shared_ptr<Association> element(new AssociationImpl());
	return element;
}
std::shared_ptr<Association> UmlFactoryImpl::createAssociation_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Association> element(new AssociationImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Association> UmlFactoryImpl::createAssociation_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Association> element(new AssociationImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Association> UmlFactoryImpl::createAssociation_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<Association> element(new AssociationImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Association> UmlFactoryImpl::createAssociation_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Association> element(new AssociationImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<Association> UmlFactoryImpl::createAssociation_in_Package(std::weak_ptr<uml::Package > par_package) const
{
	std::shared_ptr<Association> element(new AssociationImpl(par_package, UmlPackage::TYPE_PACKAGE));
	if(auto wp = par_package.lock())
	{
    		wp->getOwnedType()->push_back(element);
	}
	return element;
}

std::shared_ptr<AssociationClass> UmlFactoryImpl::createAssociationClass() const
{
	std::shared_ptr<AssociationClass> element(new AssociationClassImpl());
	return element;
}
std::shared_ptr<AssociationClass> UmlFactoryImpl::createAssociationClass_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<AssociationClass> element(new AssociationClassImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<AssociationClass> UmlFactoryImpl::createAssociationClass_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<AssociationClass> element(new AssociationClassImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<AssociationClass> UmlFactoryImpl::createAssociationClass_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<AssociationClass> element(new AssociationClassImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<AssociationClass> UmlFactoryImpl::createAssociationClass_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<AssociationClass> element(new AssociationClassImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<AssociationClass> UmlFactoryImpl::createAssociationClass_in_Package(std::weak_ptr<uml::Package > par_package) const
{
	std::shared_ptr<AssociationClass> element(new AssociationClassImpl(par_package, UmlPackage::TYPE_PACKAGE));
	if(auto wp = par_package.lock())
	{
    		wp->getOwnedType()->push_back(element);
	}
	return element;
}

std::shared_ptr<BehaviorExecutionSpecification> UmlFactoryImpl::createBehaviorExecutionSpecification() const
{
	std::shared_ptr<BehaviorExecutionSpecification> element(new BehaviorExecutionSpecificationImpl());
	return element;
}
std::shared_ptr<BehaviorExecutionSpecification> UmlFactoryImpl::createBehaviorExecutionSpecification_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction) const
{
	std::shared_ptr<BehaviorExecutionSpecification> element(new BehaviorExecutionSpecificationImpl(par_enclosingInteraction));
	if(auto wp = par_enclosingInteraction.lock())
	{
    		wp->getFragment()->push_back(element);
	}
	return element;
}

std::shared_ptr<BehaviorExecutionSpecification> UmlFactoryImpl::createBehaviorExecutionSpecification_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand) const
{
	std::shared_ptr<BehaviorExecutionSpecification> element(new BehaviorExecutionSpecificationImpl(par_enclosingOperand));
	if(auto wp = par_enclosingOperand.lock())
	{
    		wp->getFragment()->push_back(element);
	}
	return element;
}

std::shared_ptr<BehaviorExecutionSpecification> UmlFactoryImpl::createBehaviorExecutionSpecification_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<BehaviorExecutionSpecification> element(new BehaviorExecutionSpecificationImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<BehaviorExecutionSpecification> UmlFactoryImpl::createBehaviorExecutionSpecification_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<BehaviorExecutionSpecification> element(new BehaviorExecutionSpecificationImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<BroadcastSignalAction> UmlFactoryImpl::createBroadcastSignalAction() const
{
	std::shared_ptr<BroadcastSignalAction> element(new BroadcastSignalActionImpl());
	return element;
}
std::shared_ptr<BroadcastSignalAction> UmlFactoryImpl::createBroadcastSignalAction_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<BroadcastSignalAction> element(new BroadcastSignalActionImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<BroadcastSignalAction> UmlFactoryImpl::createBroadcastSignalAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<BroadcastSignalAction> element(new BroadcastSignalActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<BroadcastSignalAction> UmlFactoryImpl::createBroadcastSignalAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<BroadcastSignalAction> element(new BroadcastSignalActionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<BroadcastSignalAction> UmlFactoryImpl::createBroadcastSignalAction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<BroadcastSignalAction> element(new BroadcastSignalActionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<CallBehaviorAction> UmlFactoryImpl::createCallBehaviorAction() const
{
	std::shared_ptr<CallBehaviorAction> element(new CallBehaviorActionImpl());
	return element;
}
std::shared_ptr<CallBehaviorAction> UmlFactoryImpl::createCallBehaviorAction_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<CallBehaviorAction> element(new CallBehaviorActionImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<CallBehaviorAction> UmlFactoryImpl::createCallBehaviorAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<CallBehaviorAction> element(new CallBehaviorActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<CallBehaviorAction> UmlFactoryImpl::createCallBehaviorAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<CallBehaviorAction> element(new CallBehaviorActionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<CallBehaviorAction> UmlFactoryImpl::createCallBehaviorAction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<CallBehaviorAction> element(new CallBehaviorActionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<CallEvent> UmlFactoryImpl::createCallEvent() const
{
	std::shared_ptr<CallEvent> element(new CallEventImpl());
	return element;
}
std::shared_ptr<CallEvent> UmlFactoryImpl::createCallEvent_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<CallEvent> element(new CallEventImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<CallEvent> UmlFactoryImpl::createCallEvent_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<CallEvent> element(new CallEventImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<CallEvent> UmlFactoryImpl::createCallEvent_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<CallEvent> element(new CallEventImpl(par_owningPackage));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<CallEvent> UmlFactoryImpl::createCallEvent_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<CallEvent> element(new CallEventImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<CallOperationAction> UmlFactoryImpl::createCallOperationAction() const
{
	std::shared_ptr<CallOperationAction> element(new CallOperationActionImpl());
	return element;
}
std::shared_ptr<CallOperationAction> UmlFactoryImpl::createCallOperationAction_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<CallOperationAction> element(new CallOperationActionImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<CallOperationAction> UmlFactoryImpl::createCallOperationAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<CallOperationAction> element(new CallOperationActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<CallOperationAction> UmlFactoryImpl::createCallOperationAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<CallOperationAction> element(new CallOperationActionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<CallOperationAction> UmlFactoryImpl::createCallOperationAction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<CallOperationAction> element(new CallOperationActionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<CentralBufferNode> UmlFactoryImpl::createCentralBufferNode() const
{
	std::shared_ptr<CentralBufferNode> element(new CentralBufferNodeImpl());
	return element;
}
std::shared_ptr<CentralBufferNode> UmlFactoryImpl::createCentralBufferNode_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<CentralBufferNode> element(new CentralBufferNodeImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<CentralBufferNode> UmlFactoryImpl::createCentralBufferNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<CentralBufferNode> element(new CentralBufferNodeImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<CentralBufferNode> UmlFactoryImpl::createCentralBufferNode_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<CentralBufferNode> element(new CentralBufferNodeImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<CentralBufferNode> UmlFactoryImpl::createCentralBufferNode_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<CentralBufferNode> element(new CentralBufferNodeImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ChangeEvent> UmlFactoryImpl::createChangeEvent() const
{
	std::shared_ptr<ChangeEvent> element(new ChangeEventImpl());
	return element;
}
std::shared_ptr<ChangeEvent> UmlFactoryImpl::createChangeEvent_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ChangeEvent> element(new ChangeEventImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<ChangeEvent> UmlFactoryImpl::createChangeEvent_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ChangeEvent> element(new ChangeEventImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ChangeEvent> UmlFactoryImpl::createChangeEvent_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<ChangeEvent> element(new ChangeEventImpl(par_owningPackage));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ChangeEvent> UmlFactoryImpl::createChangeEvent_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<ChangeEvent> element(new ChangeEventImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<Class> UmlFactoryImpl::createClass() const
{
	std::shared_ptr<Class> element(new ClassImpl());
	return element;
}
std::shared_ptr<Class> UmlFactoryImpl::createClass_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Class> element(new ClassImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Class> UmlFactoryImpl::createClass_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Class> element(new ClassImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Class> UmlFactoryImpl::createClass_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<Class> element(new ClassImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Class> UmlFactoryImpl::createClass_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Class> element(new ClassImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<Class> UmlFactoryImpl::createClass_in_Package(std::weak_ptr<uml::Package > par_package) const
{
	std::shared_ptr<Class> element(new ClassImpl(par_package, UmlPackage::TYPE_PACKAGE));
	if(auto wp = par_package.lock())
	{
    		wp->getOwnedType()->push_back(element);
	}
	return element;
}

std::shared_ptr<ClassifierTemplateParameter> UmlFactoryImpl::createClassifierTemplateParameter() const
{
	std::shared_ptr<ClassifierTemplateParameter> element(new ClassifierTemplateParameterImpl());
	return element;
}
std::shared_ptr<ClassifierTemplateParameter> UmlFactoryImpl::createClassifierTemplateParameter_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ClassifierTemplateParameter> element(new ClassifierTemplateParameterImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ClassifierTemplateParameter> UmlFactoryImpl::createClassifierTemplateParameter_in_Signature(std::weak_ptr<uml::TemplateSignature > par_signature) const
{
	std::shared_ptr<ClassifierTemplateParameter> element(new ClassifierTemplateParameterImpl(par_signature));
	if(auto wp = par_signature.lock())
	{
    		wp->getOwnedParameter()->push_back(element);
	}
	return element;
}

std::shared_ptr<Clause> UmlFactoryImpl::createClause() const
{
	std::shared_ptr<Clause> element(new ClauseImpl());
	return element;
}
std::shared_ptr<Clause> UmlFactoryImpl::createClause_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Clause> element(new ClauseImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ClearAssociationAction> UmlFactoryImpl::createClearAssociationAction() const
{
	std::shared_ptr<ClearAssociationAction> element(new ClearAssociationActionImpl());
	return element;
}
std::shared_ptr<ClearAssociationAction> UmlFactoryImpl::createClearAssociationAction_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ClearAssociationAction> element(new ClearAssociationActionImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ClearAssociationAction> UmlFactoryImpl::createClearAssociationAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ClearAssociationAction> element(new ClearAssociationActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ClearAssociationAction> UmlFactoryImpl::createClearAssociationAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ClearAssociationAction> element(new ClearAssociationActionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<ClearAssociationAction> UmlFactoryImpl::createClearAssociationAction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ClearAssociationAction> element(new ClearAssociationActionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ClearStructuralFeatureAction> UmlFactoryImpl::createClearStructuralFeatureAction() const
{
	std::shared_ptr<ClearStructuralFeatureAction> element(new ClearStructuralFeatureActionImpl());
	return element;
}
std::shared_ptr<ClearStructuralFeatureAction> UmlFactoryImpl::createClearStructuralFeatureAction_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ClearStructuralFeatureAction> element(new ClearStructuralFeatureActionImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ClearStructuralFeatureAction> UmlFactoryImpl::createClearStructuralFeatureAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ClearStructuralFeatureAction> element(new ClearStructuralFeatureActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ClearStructuralFeatureAction> UmlFactoryImpl::createClearStructuralFeatureAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ClearStructuralFeatureAction> element(new ClearStructuralFeatureActionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<ClearStructuralFeatureAction> UmlFactoryImpl::createClearStructuralFeatureAction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ClearStructuralFeatureAction> element(new ClearStructuralFeatureActionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ClearVariableAction> UmlFactoryImpl::createClearVariableAction() const
{
	std::shared_ptr<ClearVariableAction> element(new ClearVariableActionImpl());
	return element;
}
std::shared_ptr<ClearVariableAction> UmlFactoryImpl::createClearVariableAction_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ClearVariableAction> element(new ClearVariableActionImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ClearVariableAction> UmlFactoryImpl::createClearVariableAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ClearVariableAction> element(new ClearVariableActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ClearVariableAction> UmlFactoryImpl::createClearVariableAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ClearVariableAction> element(new ClearVariableActionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<ClearVariableAction> UmlFactoryImpl::createClearVariableAction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ClearVariableAction> element(new ClearVariableActionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Collaboration> UmlFactoryImpl::createCollaboration() const
{
	std::shared_ptr<Collaboration> element(new CollaborationImpl());
	return element;
}
std::shared_ptr<Collaboration> UmlFactoryImpl::createCollaboration_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Collaboration> element(new CollaborationImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Collaboration> UmlFactoryImpl::createCollaboration_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Collaboration> element(new CollaborationImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Collaboration> UmlFactoryImpl::createCollaboration_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<Collaboration> element(new CollaborationImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Collaboration> UmlFactoryImpl::createCollaboration_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Collaboration> element(new CollaborationImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<Collaboration> UmlFactoryImpl::createCollaboration_in_Package(std::weak_ptr<uml::Package > par_package) const
{
	std::shared_ptr<Collaboration> element(new CollaborationImpl(par_package, UmlPackage::TYPE_PACKAGE));
	if(auto wp = par_package.lock())
	{
    		wp->getOwnedType()->push_back(element);
	}
	return element;
}

std::shared_ptr<CollaborationUse> UmlFactoryImpl::createCollaborationUse() const
{
	std::shared_ptr<CollaborationUse> element(new CollaborationUseImpl());
	return element;
}
std::shared_ptr<CollaborationUse> UmlFactoryImpl::createCollaborationUse_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<CollaborationUse> element(new CollaborationUseImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<CollaborationUse> UmlFactoryImpl::createCollaborationUse_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<CollaborationUse> element(new CollaborationUseImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<CombinedFragment> UmlFactoryImpl::createCombinedFragment() const
{
	std::shared_ptr<CombinedFragment> element(new CombinedFragmentImpl());
	return element;
}
std::shared_ptr<CombinedFragment> UmlFactoryImpl::createCombinedFragment_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction) const
{
	std::shared_ptr<CombinedFragment> element(new CombinedFragmentImpl(par_enclosingInteraction));
	if(auto wp = par_enclosingInteraction.lock())
	{
    		wp->getFragment()->push_back(element);
	}
	return element;
}

std::shared_ptr<CombinedFragment> UmlFactoryImpl::createCombinedFragment_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand) const
{
	std::shared_ptr<CombinedFragment> element(new CombinedFragmentImpl(par_enclosingOperand));
	if(auto wp = par_enclosingOperand.lock())
	{
    		wp->getFragment()->push_back(element);
	}
	return element;
}

std::shared_ptr<CombinedFragment> UmlFactoryImpl::createCombinedFragment_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<CombinedFragment> element(new CombinedFragmentImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<CombinedFragment> UmlFactoryImpl::createCombinedFragment_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<CombinedFragment> element(new CombinedFragmentImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Comment> UmlFactoryImpl::createComment() const
{
	std::shared_ptr<Comment> element(new CommentImpl());
	return element;
}
std::shared_ptr<Comment> UmlFactoryImpl::createComment_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Comment> element(new CommentImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedComment()->push_back(element);
	}
	return element;
}

std::shared_ptr<CommunicationPath> UmlFactoryImpl::createCommunicationPath() const
{
	std::shared_ptr<CommunicationPath> element(new CommunicationPathImpl());
	return element;
}
std::shared_ptr<CommunicationPath> UmlFactoryImpl::createCommunicationPath_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<CommunicationPath> element(new CommunicationPathImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<CommunicationPath> UmlFactoryImpl::createCommunicationPath_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<CommunicationPath> element(new CommunicationPathImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<CommunicationPath> UmlFactoryImpl::createCommunicationPath_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<CommunicationPath> element(new CommunicationPathImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<CommunicationPath> UmlFactoryImpl::createCommunicationPath_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<CommunicationPath> element(new CommunicationPathImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<CommunicationPath> UmlFactoryImpl::createCommunicationPath_in_Package(std::weak_ptr<uml::Package > par_package) const
{
	std::shared_ptr<CommunicationPath> element(new CommunicationPathImpl(par_package, UmlPackage::TYPE_PACKAGE));
	if(auto wp = par_package.lock())
	{
    		wp->getOwnedType()->push_back(element);
	}
	return element;
}

std::shared_ptr<Component> UmlFactoryImpl::createComponent() const
{
	std::shared_ptr<Component> element(new ComponentImpl());
	return element;
}
std::shared_ptr<Component> UmlFactoryImpl::createComponent_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Component> element(new ComponentImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Component> UmlFactoryImpl::createComponent_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Component> element(new ComponentImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Component> UmlFactoryImpl::createComponent_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<Component> element(new ComponentImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Component> UmlFactoryImpl::createComponent_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Component> element(new ComponentImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<Component> UmlFactoryImpl::createComponent_in_Package(std::weak_ptr<uml::Package > par_package) const
{
	std::shared_ptr<Component> element(new ComponentImpl(par_package, UmlPackage::TYPE_PACKAGE));
	if(auto wp = par_package.lock())
	{
    		wp->getOwnedType()->push_back(element);
	}
	return element;
}

std::shared_ptr<ComponentRealization> UmlFactoryImpl::createComponentRealization() const
{
	std::shared_ptr<ComponentRealization> element(new ComponentRealizationImpl());
	return element;
}
std::shared_ptr<ComponentRealization> UmlFactoryImpl::createComponentRealization_in_Abstraction(std::weak_ptr<uml::Component > par_abstraction) const
{
	std::shared_ptr<ComponentRealization> element(new ComponentRealizationImpl(par_abstraction));
	if(auto wp = par_abstraction.lock())
	{
    		wp->getRealization()->push_back(element);
	}
	return element;
}

std::shared_ptr<ComponentRealization> UmlFactoryImpl::createComponentRealization_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ComponentRealization> element(new ComponentRealizationImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<ComponentRealization> UmlFactoryImpl::createComponentRealization_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ComponentRealization> element(new ComponentRealizationImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ComponentRealization> UmlFactoryImpl::createComponentRealization_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<ComponentRealization> element(new ComponentRealizationImpl(par_owningPackage));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ComponentRealization> UmlFactoryImpl::createComponentRealization_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<ComponentRealization> element(new ComponentRealizationImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<ConditionalNode> UmlFactoryImpl::createConditionalNode() const
{
	std::shared_ptr<ConditionalNode> element(new ConditionalNodeImpl());
	return element;
}
std::shared_ptr<ConditionalNode> UmlFactoryImpl::createConditionalNode_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ConditionalNode> element(new ConditionalNodeImpl(par_activity, UmlPackage::ACTIVITYNODE_ACTIVITY));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ConditionalNode> UmlFactoryImpl::createConditionalNode_in_InActivity(std::weak_ptr<uml::Activity > par_inActivity) const
{
	std::shared_ptr<ConditionalNode> element(new ConditionalNodeImpl(par_inActivity, UmlPackage::ACTIVITYGROUP_INACTIVITY));
	if(auto wp = par_inActivity.lock())
	{
    		wp->getGroup()->push_back(element);
	}
	return element;
}

std::shared_ptr<ConditionalNode> UmlFactoryImpl::createConditionalNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ConditionalNode> element(new ConditionalNodeImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ConditionalNode> UmlFactoryImpl::createConditionalNode_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ConditionalNode> element(new ConditionalNodeImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<ConditionalNode> UmlFactoryImpl::createConditionalNode_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ConditionalNode> element(new ConditionalNodeImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ConditionalNode> UmlFactoryImpl::createConditionalNode_in_SuperGroup(std::weak_ptr<uml::ActivityGroup > par_superGroup) const
{
	std::shared_ptr<ConditionalNode> element(new ConditionalNodeImpl(par_superGroup));
	if(auto wp = par_superGroup.lock())
	{
    		wp->getSubgroup()->push_back(element);
	}
	return element;
}

std::shared_ptr<ConnectableElementTemplateParameter> UmlFactoryImpl::createConnectableElementTemplateParameter() const
{
	std::shared_ptr<ConnectableElementTemplateParameter> element(new ConnectableElementTemplateParameterImpl());
	return element;
}
std::shared_ptr<ConnectableElementTemplateParameter> UmlFactoryImpl::createConnectableElementTemplateParameter_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ConnectableElementTemplateParameter> element(new ConnectableElementTemplateParameterImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ConnectableElementTemplateParameter> UmlFactoryImpl::createConnectableElementTemplateParameter_in_Signature(std::weak_ptr<uml::TemplateSignature > par_signature) const
{
	std::shared_ptr<ConnectableElementTemplateParameter> element(new ConnectableElementTemplateParameterImpl(par_signature));
	if(auto wp = par_signature.lock())
	{
    		wp->getOwnedParameter()->push_back(element);
	}
	return element;
}

std::shared_ptr<ConnectionPointReference> UmlFactoryImpl::createConnectionPointReference() const
{
	std::shared_ptr<ConnectionPointReference> element(new ConnectionPointReferenceImpl());
	return element;
}
std::shared_ptr<ConnectionPointReference> UmlFactoryImpl::createConnectionPointReference_in_Container(std::weak_ptr<uml::Region > par_container) const
{
	std::shared_ptr<ConnectionPointReference> element(new ConnectionPointReferenceImpl(par_container));
	if(auto wp = par_container.lock())
	{
    		wp->getSubvertex()->push_back(element);
	}
	return element;
}

std::shared_ptr<ConnectionPointReference> UmlFactoryImpl::createConnectionPointReference_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ConnectionPointReference> element(new ConnectionPointReferenceImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<ConnectionPointReference> UmlFactoryImpl::createConnectionPointReference_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ConnectionPointReference> element(new ConnectionPointReferenceImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ConnectionPointReference> UmlFactoryImpl::createConnectionPointReference_in_State(std::weak_ptr<uml::State > par_state) const
{
	std::shared_ptr<ConnectionPointReference> element(new ConnectionPointReferenceImpl(par_state));
	if(auto wp = par_state.lock())
	{
    		wp->getConnection()->push_back(element);
	}
	return element;
}

std::shared_ptr<Connector> UmlFactoryImpl::createConnector() const
{
	std::shared_ptr<Connector> element(new ConnectorImpl());
	return element;
}
std::shared_ptr<Connector> UmlFactoryImpl::createConnector_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Connector> element(new ConnectorImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Connector> UmlFactoryImpl::createConnector_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Connector> element(new ConnectorImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ConnectorEnd> UmlFactoryImpl::createConnectorEnd() const
{
	std::shared_ptr<ConnectorEnd> element(new ConnectorEndImpl());
	return element;
}
std::shared_ptr<ConnectorEnd> UmlFactoryImpl::createConnectorEnd_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ConnectorEnd> element(new ConnectorEndImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ConsiderIgnoreFragment> UmlFactoryImpl::createConsiderIgnoreFragment() const
{
	std::shared_ptr<ConsiderIgnoreFragment> element(new ConsiderIgnoreFragmentImpl());
	return element;
}
std::shared_ptr<ConsiderIgnoreFragment> UmlFactoryImpl::createConsiderIgnoreFragment_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction) const
{
	std::shared_ptr<ConsiderIgnoreFragment> element(new ConsiderIgnoreFragmentImpl(par_enclosingInteraction));
	if(auto wp = par_enclosingInteraction.lock())
	{
    		wp->getFragment()->push_back(element);
	}
	return element;
}

std::shared_ptr<ConsiderIgnoreFragment> UmlFactoryImpl::createConsiderIgnoreFragment_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand) const
{
	std::shared_ptr<ConsiderIgnoreFragment> element(new ConsiderIgnoreFragmentImpl(par_enclosingOperand));
	if(auto wp = par_enclosingOperand.lock())
	{
    		wp->getFragment()->push_back(element);
	}
	return element;
}

std::shared_ptr<ConsiderIgnoreFragment> UmlFactoryImpl::createConsiderIgnoreFragment_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ConsiderIgnoreFragment> element(new ConsiderIgnoreFragmentImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<ConsiderIgnoreFragment> UmlFactoryImpl::createConsiderIgnoreFragment_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ConsiderIgnoreFragment> element(new ConsiderIgnoreFragmentImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Constraint> UmlFactoryImpl::createConstraint() const
{
	std::shared_ptr<Constraint> element(new ConstraintImpl());
	return element;
}
std::shared_ptr<Constraint> UmlFactoryImpl::createConstraint_in_Context(std::weak_ptr<uml::Namespace > par_context) const
{
	std::shared_ptr<Constraint> element(new ConstraintImpl(par_context, UmlPackage::CONSTRAINT_CONTEXT));
	if(auto wp = par_context.lock())
	{
    		wp->getOwnedRule()->push_back(element);
	}
	return element;
}

std::shared_ptr<Constraint> UmlFactoryImpl::createConstraint_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Constraint> element(new ConstraintImpl(par_namespace, UmlPackage::NAMEDELEMENT_NAMESPACE));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedRule()->push_back(element);
	}
	return element;
}

std::shared_ptr<Constraint> UmlFactoryImpl::createConstraint_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Constraint> element(new ConstraintImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Constraint> UmlFactoryImpl::createConstraint_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<Constraint> element(new ConstraintImpl(par_owningPackage));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Constraint> UmlFactoryImpl::createConstraint_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Constraint> element(new ConstraintImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<Continuation> UmlFactoryImpl::createContinuation() const
{
	std::shared_ptr<Continuation> element(new ContinuationImpl());
	return element;
}
std::shared_ptr<Continuation> UmlFactoryImpl::createContinuation_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction) const
{
	std::shared_ptr<Continuation> element(new ContinuationImpl(par_enclosingInteraction));
	if(auto wp = par_enclosingInteraction.lock())
	{
    		wp->getFragment()->push_back(element);
	}
	return element;
}

std::shared_ptr<Continuation> UmlFactoryImpl::createContinuation_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand) const
{
	std::shared_ptr<Continuation> element(new ContinuationImpl(par_enclosingOperand));
	if(auto wp = par_enclosingOperand.lock())
	{
    		wp->getFragment()->push_back(element);
	}
	return element;
}

std::shared_ptr<Continuation> UmlFactoryImpl::createContinuation_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Continuation> element(new ContinuationImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Continuation> UmlFactoryImpl::createContinuation_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Continuation> element(new ContinuationImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ControlFlow> UmlFactoryImpl::createControlFlow() const
{
	std::shared_ptr<ControlFlow> element(new ControlFlowImpl());
	return element;
}
std::shared_ptr<ControlFlow> UmlFactoryImpl::createControlFlow_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ControlFlow> element(new ControlFlowImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getEdge()->push_back(element);
	}
	return element;
}

std::shared_ptr<ControlFlow> UmlFactoryImpl::createControlFlow_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ControlFlow> element(new ControlFlowImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getEdge()->push_back(element);
	}
	return element;
}

std::shared_ptr<ControlFlow> UmlFactoryImpl::createControlFlow_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ControlFlow> element(new ControlFlowImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<ControlFlow> UmlFactoryImpl::createControlFlow_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ControlFlow> element(new ControlFlowImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<CreateLinkAction> UmlFactoryImpl::createCreateLinkAction() const
{
	std::shared_ptr<CreateLinkAction> element(new CreateLinkActionImpl());
	return element;
}
std::shared_ptr<CreateLinkAction> UmlFactoryImpl::createCreateLinkAction_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<CreateLinkAction> element(new CreateLinkActionImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<CreateLinkAction> UmlFactoryImpl::createCreateLinkAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<CreateLinkAction> element(new CreateLinkActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<CreateLinkAction> UmlFactoryImpl::createCreateLinkAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<CreateLinkAction> element(new CreateLinkActionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<CreateLinkAction> UmlFactoryImpl::createCreateLinkAction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<CreateLinkAction> element(new CreateLinkActionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<CreateLinkObjectAction> UmlFactoryImpl::createCreateLinkObjectAction() const
{
	std::shared_ptr<CreateLinkObjectAction> element(new CreateLinkObjectActionImpl());
	return element;
}
std::shared_ptr<CreateLinkObjectAction> UmlFactoryImpl::createCreateLinkObjectAction_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<CreateLinkObjectAction> element(new CreateLinkObjectActionImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<CreateLinkObjectAction> UmlFactoryImpl::createCreateLinkObjectAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<CreateLinkObjectAction> element(new CreateLinkObjectActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<CreateLinkObjectAction> UmlFactoryImpl::createCreateLinkObjectAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<CreateLinkObjectAction> element(new CreateLinkObjectActionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<CreateLinkObjectAction> UmlFactoryImpl::createCreateLinkObjectAction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<CreateLinkObjectAction> element(new CreateLinkObjectActionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<CreateObjectAction> UmlFactoryImpl::createCreateObjectAction() const
{
	std::shared_ptr<CreateObjectAction> element(new CreateObjectActionImpl());
	return element;
}
std::shared_ptr<CreateObjectAction> UmlFactoryImpl::createCreateObjectAction_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<CreateObjectAction> element(new CreateObjectActionImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<CreateObjectAction> UmlFactoryImpl::createCreateObjectAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<CreateObjectAction> element(new CreateObjectActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<CreateObjectAction> UmlFactoryImpl::createCreateObjectAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<CreateObjectAction> element(new CreateObjectActionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<CreateObjectAction> UmlFactoryImpl::createCreateObjectAction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<CreateObjectAction> element(new CreateObjectActionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<DataStoreNode> UmlFactoryImpl::createDataStoreNode() const
{
	std::shared_ptr<DataStoreNode> element(new DataStoreNodeImpl());
	return element;
}
std::shared_ptr<DataStoreNode> UmlFactoryImpl::createDataStoreNode_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<DataStoreNode> element(new DataStoreNodeImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<DataStoreNode> UmlFactoryImpl::createDataStoreNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<DataStoreNode> element(new DataStoreNodeImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<DataStoreNode> UmlFactoryImpl::createDataStoreNode_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<DataStoreNode> element(new DataStoreNodeImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<DataStoreNode> UmlFactoryImpl::createDataStoreNode_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<DataStoreNode> element(new DataStoreNodeImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<DataType> UmlFactoryImpl::createDataType() const
{
	std::shared_ptr<DataType> element(new DataTypeImpl());
	return element;
}
std::shared_ptr<DataType> UmlFactoryImpl::createDataType_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<DataType> element(new DataTypeImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<DataType> UmlFactoryImpl::createDataType_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<DataType> element(new DataTypeImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<DataType> UmlFactoryImpl::createDataType_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<DataType> element(new DataTypeImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<DataType> UmlFactoryImpl::createDataType_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<DataType> element(new DataTypeImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<DataType> UmlFactoryImpl::createDataType_in_Package(std::weak_ptr<uml::Package > par_package) const
{
	std::shared_ptr<DataType> element(new DataTypeImpl(par_package, UmlPackage::TYPE_PACKAGE));
	if(auto wp = par_package.lock())
	{
    		wp->getOwnedType()->push_back(element);
	}
	return element;
}

std::shared_ptr<DecisionNode> UmlFactoryImpl::createDecisionNode() const
{
	std::shared_ptr<DecisionNode> element(new DecisionNodeImpl());
	return element;
}
std::shared_ptr<DecisionNode> UmlFactoryImpl::createDecisionNode_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<DecisionNode> element(new DecisionNodeImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<DecisionNode> UmlFactoryImpl::createDecisionNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<DecisionNode> element(new DecisionNodeImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<DecisionNode> UmlFactoryImpl::createDecisionNode_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<DecisionNode> element(new DecisionNodeImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<DecisionNode> UmlFactoryImpl::createDecisionNode_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<DecisionNode> element(new DecisionNodeImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Dependency> UmlFactoryImpl::createDependency() const
{
	std::shared_ptr<Dependency> element(new DependencyImpl());
	return element;
}
std::shared_ptr<Dependency> UmlFactoryImpl::createDependency_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Dependency> element(new DependencyImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Dependency> UmlFactoryImpl::createDependency_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Dependency> element(new DependencyImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Dependency> UmlFactoryImpl::createDependency_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<Dependency> element(new DependencyImpl(par_owningPackage));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Dependency> UmlFactoryImpl::createDependency_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Dependency> element(new DependencyImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<Deployment> UmlFactoryImpl::createDeployment() const
{
	std::shared_ptr<Deployment> element(new DeploymentImpl());
	return element;
}
std::shared_ptr<Deployment> UmlFactoryImpl::createDeployment_in_Location(std::weak_ptr<uml::DeploymentTarget > par_location) const
{
	std::shared_ptr<Deployment> element(new DeploymentImpl(par_location));
	if(auto wp = par_location.lock())
	{
    		wp->getDeployment()->push_back(element);
	}
	return element;
}

std::shared_ptr<Deployment> UmlFactoryImpl::createDeployment_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Deployment> element(new DeploymentImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Deployment> UmlFactoryImpl::createDeployment_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Deployment> element(new DeploymentImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Deployment> UmlFactoryImpl::createDeployment_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<Deployment> element(new DeploymentImpl(par_owningPackage));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Deployment> UmlFactoryImpl::createDeployment_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Deployment> element(new DeploymentImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<DeploymentSpecification> UmlFactoryImpl::createDeploymentSpecification() const
{
	std::shared_ptr<DeploymentSpecification> element(new DeploymentSpecificationImpl());
	return element;
}
std::shared_ptr<DeploymentSpecification> UmlFactoryImpl::createDeploymentSpecification_in_Deployment(std::weak_ptr<uml::Deployment > par_deployment) const
{
	std::shared_ptr<DeploymentSpecification> element(new DeploymentSpecificationImpl(par_deployment));
	if(auto wp = par_deployment.lock())
	{
    		wp->getConfiguration()->push_back(element);
	}
	return element;
}

std::shared_ptr<DeploymentSpecification> UmlFactoryImpl::createDeploymentSpecification_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<DeploymentSpecification> element(new DeploymentSpecificationImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<DeploymentSpecification> UmlFactoryImpl::createDeploymentSpecification_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<DeploymentSpecification> element(new DeploymentSpecificationImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<DeploymentSpecification> UmlFactoryImpl::createDeploymentSpecification_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<DeploymentSpecification> element(new DeploymentSpecificationImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<DeploymentSpecification> UmlFactoryImpl::createDeploymentSpecification_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<DeploymentSpecification> element(new DeploymentSpecificationImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<DeploymentSpecification> UmlFactoryImpl::createDeploymentSpecification_in_Package(std::weak_ptr<uml::Package > par_package) const
{
	std::shared_ptr<DeploymentSpecification> element(new DeploymentSpecificationImpl(par_package, UmlPackage::TYPE_PACKAGE));
	if(auto wp = par_package.lock())
	{
    		wp->getOwnedType()->push_back(element);
	}
	return element;
}

std::shared_ptr<DestroyLinkAction> UmlFactoryImpl::createDestroyLinkAction() const
{
	std::shared_ptr<DestroyLinkAction> element(new DestroyLinkActionImpl());
	return element;
}
std::shared_ptr<DestroyLinkAction> UmlFactoryImpl::createDestroyLinkAction_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<DestroyLinkAction> element(new DestroyLinkActionImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<DestroyLinkAction> UmlFactoryImpl::createDestroyLinkAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<DestroyLinkAction> element(new DestroyLinkActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<DestroyLinkAction> UmlFactoryImpl::createDestroyLinkAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<DestroyLinkAction> element(new DestroyLinkActionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<DestroyLinkAction> UmlFactoryImpl::createDestroyLinkAction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<DestroyLinkAction> element(new DestroyLinkActionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<DestroyObjectAction> UmlFactoryImpl::createDestroyObjectAction() const
{
	std::shared_ptr<DestroyObjectAction> element(new DestroyObjectActionImpl());
	return element;
}
std::shared_ptr<DestroyObjectAction> UmlFactoryImpl::createDestroyObjectAction_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<DestroyObjectAction> element(new DestroyObjectActionImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<DestroyObjectAction> UmlFactoryImpl::createDestroyObjectAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<DestroyObjectAction> element(new DestroyObjectActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<DestroyObjectAction> UmlFactoryImpl::createDestroyObjectAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<DestroyObjectAction> element(new DestroyObjectActionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<DestroyObjectAction> UmlFactoryImpl::createDestroyObjectAction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<DestroyObjectAction> element(new DestroyObjectActionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<DestructionOccurrenceSpecification> UmlFactoryImpl::createDestructionOccurrenceSpecification() const
{
	std::shared_ptr<DestructionOccurrenceSpecification> element(new DestructionOccurrenceSpecificationImpl());
	return element;
}
std::shared_ptr<DestructionOccurrenceSpecification> UmlFactoryImpl::createDestructionOccurrenceSpecification_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction) const
{
	std::shared_ptr<DestructionOccurrenceSpecification> element(new DestructionOccurrenceSpecificationImpl(par_enclosingInteraction));
	if(auto wp = par_enclosingInteraction.lock())
	{
    		wp->getFragment()->push_back(element);
	}
	return element;
}

std::shared_ptr<DestructionOccurrenceSpecification> UmlFactoryImpl::createDestructionOccurrenceSpecification_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand) const
{
	std::shared_ptr<DestructionOccurrenceSpecification> element(new DestructionOccurrenceSpecificationImpl(par_enclosingOperand));
	if(auto wp = par_enclosingOperand.lock())
	{
    		wp->getFragment()->push_back(element);
	}
	return element;
}

std::shared_ptr<DestructionOccurrenceSpecification> UmlFactoryImpl::createDestructionOccurrenceSpecification_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<DestructionOccurrenceSpecification> element(new DestructionOccurrenceSpecificationImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<DestructionOccurrenceSpecification> UmlFactoryImpl::createDestructionOccurrenceSpecification_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<DestructionOccurrenceSpecification> element(new DestructionOccurrenceSpecificationImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Device> UmlFactoryImpl::createDevice() const
{
	std::shared_ptr<Device> element(new DeviceImpl());
	return element;
}
std::shared_ptr<Device> UmlFactoryImpl::createDevice_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Device> element(new DeviceImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Device> UmlFactoryImpl::createDevice_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Device> element(new DeviceImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Device> UmlFactoryImpl::createDevice_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<Device> element(new DeviceImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Device> UmlFactoryImpl::createDevice_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Device> element(new DeviceImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<Device> UmlFactoryImpl::createDevice_in_Package(std::weak_ptr<uml::Package > par_package) const
{
	std::shared_ptr<Device> element(new DeviceImpl(par_package, UmlPackage::TYPE_PACKAGE));
	if(auto wp = par_package.lock())
	{
    		wp->getOwnedType()->push_back(element);
	}
	return element;
}

std::shared_ptr<Duration> UmlFactoryImpl::createDuration() const
{
	std::shared_ptr<Duration> element(new DurationImpl());
	return element;
}
std::shared_ptr<Duration> UmlFactoryImpl::createDuration_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Duration> element(new DurationImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Duration> UmlFactoryImpl::createDuration_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Duration> element(new DurationImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Duration> UmlFactoryImpl::createDuration_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<Duration> element(new DurationImpl(par_owningPackage));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Duration> UmlFactoryImpl::createDuration_in_OwningSlot(std::weak_ptr<uml::Slot > par_owningSlot) const
{
	std::shared_ptr<Duration> element(new DurationImpl(par_owningSlot));
	if(auto wp = par_owningSlot.lock())
	{
    		wp->getValue()->push_back(element);
	}
	return element;
}

std::shared_ptr<Duration> UmlFactoryImpl::createDuration_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Duration> element(new DurationImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<DurationConstraint> UmlFactoryImpl::createDurationConstraint() const
{
	std::shared_ptr<DurationConstraint> element(new DurationConstraintImpl());
	return element;
}
std::shared_ptr<DurationConstraint> UmlFactoryImpl::createDurationConstraint_in_Context(std::weak_ptr<uml::Namespace > par_context) const
{
	std::shared_ptr<DurationConstraint> element(new DurationConstraintImpl(par_context, UmlPackage::CONSTRAINT_CONTEXT));
	if(auto wp = par_context.lock())
	{
    		wp->getOwnedRule()->push_back(element);
	}
	return element;
}

std::shared_ptr<DurationConstraint> UmlFactoryImpl::createDurationConstraint_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<DurationConstraint> element(new DurationConstraintImpl(par_namespace, UmlPackage::NAMEDELEMENT_NAMESPACE));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<DurationConstraint> UmlFactoryImpl::createDurationConstraint_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<DurationConstraint> element(new DurationConstraintImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<DurationConstraint> UmlFactoryImpl::createDurationConstraint_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<DurationConstraint> element(new DurationConstraintImpl(par_owningPackage));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<DurationConstraint> UmlFactoryImpl::createDurationConstraint_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<DurationConstraint> element(new DurationConstraintImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<DurationInterval> UmlFactoryImpl::createDurationInterval() const
{
	std::shared_ptr<DurationInterval> element(new DurationIntervalImpl());
	return element;
}
std::shared_ptr<DurationInterval> UmlFactoryImpl::createDurationInterval_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<DurationInterval> element(new DurationIntervalImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<DurationInterval> UmlFactoryImpl::createDurationInterval_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<DurationInterval> element(new DurationIntervalImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<DurationInterval> UmlFactoryImpl::createDurationInterval_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<DurationInterval> element(new DurationIntervalImpl(par_owningPackage));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<DurationInterval> UmlFactoryImpl::createDurationInterval_in_OwningSlot(std::weak_ptr<uml::Slot > par_owningSlot) const
{
	std::shared_ptr<DurationInterval> element(new DurationIntervalImpl(par_owningSlot));
	if(auto wp = par_owningSlot.lock())
	{
    		wp->getValue()->push_back(element);
	}
	return element;
}

std::shared_ptr<DurationInterval> UmlFactoryImpl::createDurationInterval_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<DurationInterval> element(new DurationIntervalImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<DurationObservation> UmlFactoryImpl::createDurationObservation() const
{
	std::shared_ptr<DurationObservation> element(new DurationObservationImpl());
	return element;
}
std::shared_ptr<DurationObservation> UmlFactoryImpl::createDurationObservation_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<DurationObservation> element(new DurationObservationImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<DurationObservation> UmlFactoryImpl::createDurationObservation_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<DurationObservation> element(new DurationObservationImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<DurationObservation> UmlFactoryImpl::createDurationObservation_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<DurationObservation> element(new DurationObservationImpl(par_owningPackage));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<DurationObservation> UmlFactoryImpl::createDurationObservation_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<DurationObservation> element(new DurationObservationImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<ElementImport> UmlFactoryImpl::createElementImport() const
{
	std::shared_ptr<ElementImport> element(new ElementImportImpl());
	return element;
}
std::shared_ptr<ElementImport> UmlFactoryImpl::createElementImport_in_ImportingNamespace(std::weak_ptr<uml::Namespace > par_importingNamespace) const
{
	std::shared_ptr<ElementImport> element(new ElementImportImpl(par_importingNamespace));
	if(auto wp = par_importingNamespace.lock())
	{
    		wp->getElementImport()->push_back(element);
	}
	return element;
}

std::shared_ptr<ElementImport> UmlFactoryImpl::createElementImport_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ElementImport> element(new ElementImportImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Enumeration> UmlFactoryImpl::createEnumeration() const
{
	std::shared_ptr<Enumeration> element(new EnumerationImpl());
	return element;
}
std::shared_ptr<Enumeration> UmlFactoryImpl::createEnumeration_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Enumeration> element(new EnumerationImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Enumeration> UmlFactoryImpl::createEnumeration_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Enumeration> element(new EnumerationImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Enumeration> UmlFactoryImpl::createEnumeration_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<Enumeration> element(new EnumerationImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Enumeration> UmlFactoryImpl::createEnumeration_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Enumeration> element(new EnumerationImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<Enumeration> UmlFactoryImpl::createEnumeration_in_Package(std::weak_ptr<uml::Package > par_package) const
{
	std::shared_ptr<Enumeration> element(new EnumerationImpl(par_package, UmlPackage::TYPE_PACKAGE));
	if(auto wp = par_package.lock())
	{
    		wp->getOwnedType()->push_back(element);
	}
	return element;
}

std::shared_ptr<EnumerationLiteral> UmlFactoryImpl::createEnumerationLiteral() const
{
	std::shared_ptr<EnumerationLiteral> element(new EnumerationLiteralImpl());
	return element;
}
std::shared_ptr<EnumerationLiteral> UmlFactoryImpl::createEnumerationLiteral_in_Enumeration(std::weak_ptr<uml::Enumeration > par_enumeration) const
{
	std::shared_ptr<EnumerationLiteral> element(new EnumerationLiteralImpl(par_enumeration));
	if(auto wp = par_enumeration.lock())
	{
    		wp->getOwnedLiteral()->push_back(element);
	}
	return element;
}

std::shared_ptr<EnumerationLiteral> UmlFactoryImpl::createEnumerationLiteral_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<EnumerationLiteral> element(new EnumerationLiteralImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<EnumerationLiteral> UmlFactoryImpl::createEnumerationLiteral_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<EnumerationLiteral> element(new EnumerationLiteralImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<EnumerationLiteral> UmlFactoryImpl::createEnumerationLiteral_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<EnumerationLiteral> element(new EnumerationLiteralImpl(par_owningPackage));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<EnumerationLiteral> UmlFactoryImpl::createEnumerationLiteral_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<EnumerationLiteral> element(new EnumerationLiteralImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<ExceptionHandler> UmlFactoryImpl::createExceptionHandler() const
{
	std::shared_ptr<ExceptionHandler> element(new ExceptionHandlerImpl());
	return element;
}
std::shared_ptr<ExceptionHandler> UmlFactoryImpl::createExceptionHandler_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ExceptionHandler> element(new ExceptionHandlerImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ExceptionHandler> UmlFactoryImpl::createExceptionHandler_in_ProtectedNode(std::weak_ptr<uml::ExecutableNode > par_protectedNode) const
{
	std::shared_ptr<ExceptionHandler> element(new ExceptionHandlerImpl(par_protectedNode));
	if(auto wp = par_protectedNode.lock())
	{
    		wp->getHandler()->push_back(element);
	}
	return element;
}

std::shared_ptr<ExecutionEnvironment> UmlFactoryImpl::createExecutionEnvironment() const
{
	std::shared_ptr<ExecutionEnvironment> element(new ExecutionEnvironmentImpl());
	return element;
}
std::shared_ptr<ExecutionEnvironment> UmlFactoryImpl::createExecutionEnvironment_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ExecutionEnvironment> element(new ExecutionEnvironmentImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<ExecutionEnvironment> UmlFactoryImpl::createExecutionEnvironment_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ExecutionEnvironment> element(new ExecutionEnvironmentImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ExecutionEnvironment> UmlFactoryImpl::createExecutionEnvironment_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<ExecutionEnvironment> element(new ExecutionEnvironmentImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ExecutionEnvironment> UmlFactoryImpl::createExecutionEnvironment_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<ExecutionEnvironment> element(new ExecutionEnvironmentImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<ExecutionEnvironment> UmlFactoryImpl::createExecutionEnvironment_in_Package(std::weak_ptr<uml::Package > par_package) const
{
	std::shared_ptr<ExecutionEnvironment> element(new ExecutionEnvironmentImpl(par_package, UmlPackage::TYPE_PACKAGE));
	if(auto wp = par_package.lock())
	{
    		wp->getOwnedType()->push_back(element);
	}
	return element;
}

std::shared_ptr<ExecutionOccurrenceSpecification> UmlFactoryImpl::createExecutionOccurrenceSpecification() const
{
	std::shared_ptr<ExecutionOccurrenceSpecification> element(new ExecutionOccurrenceSpecificationImpl());
	return element;
}
std::shared_ptr<ExecutionOccurrenceSpecification> UmlFactoryImpl::createExecutionOccurrenceSpecification_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction) const
{
	std::shared_ptr<ExecutionOccurrenceSpecification> element(new ExecutionOccurrenceSpecificationImpl(par_enclosingInteraction));
	if(auto wp = par_enclosingInteraction.lock())
	{
    		wp->getFragment()->push_back(element);
	}
	return element;
}

std::shared_ptr<ExecutionOccurrenceSpecification> UmlFactoryImpl::createExecutionOccurrenceSpecification_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand) const
{
	std::shared_ptr<ExecutionOccurrenceSpecification> element(new ExecutionOccurrenceSpecificationImpl(par_enclosingOperand));
	if(auto wp = par_enclosingOperand.lock())
	{
    		wp->getFragment()->push_back(element);
	}
	return element;
}

std::shared_ptr<ExecutionOccurrenceSpecification> UmlFactoryImpl::createExecutionOccurrenceSpecification_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ExecutionOccurrenceSpecification> element(new ExecutionOccurrenceSpecificationImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<ExecutionOccurrenceSpecification> UmlFactoryImpl::createExecutionOccurrenceSpecification_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ExecutionOccurrenceSpecification> element(new ExecutionOccurrenceSpecificationImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ExpansionNode> UmlFactoryImpl::createExpansionNode() const
{
	std::shared_ptr<ExpansionNode> element(new ExpansionNodeImpl());
	return element;
}
std::shared_ptr<ExpansionNode> UmlFactoryImpl::createExpansionNode_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ExpansionNode> element(new ExpansionNodeImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ExpansionNode> UmlFactoryImpl::createExpansionNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ExpansionNode> element(new ExpansionNodeImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ExpansionNode> UmlFactoryImpl::createExpansionNode_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ExpansionNode> element(new ExpansionNodeImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<ExpansionNode> UmlFactoryImpl::createExpansionNode_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ExpansionNode> element(new ExpansionNodeImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ExpansionRegion> UmlFactoryImpl::createExpansionRegion() const
{
	std::shared_ptr<ExpansionRegion> element(new ExpansionRegionImpl());
	return element;
}
std::shared_ptr<ExpansionRegion> UmlFactoryImpl::createExpansionRegion_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ExpansionRegion> element(new ExpansionRegionImpl(par_activity, UmlPackage::ACTIVITYNODE_ACTIVITY));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ExpansionRegion> UmlFactoryImpl::createExpansionRegion_in_InActivity(std::weak_ptr<uml::Activity > par_inActivity) const
{
	std::shared_ptr<ExpansionRegion> element(new ExpansionRegionImpl(par_inActivity, UmlPackage::ACTIVITYGROUP_INACTIVITY));
	if(auto wp = par_inActivity.lock())
	{
    		wp->getGroup()->push_back(element);
	}
	return element;
}

std::shared_ptr<ExpansionRegion> UmlFactoryImpl::createExpansionRegion_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ExpansionRegion> element(new ExpansionRegionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ExpansionRegion> UmlFactoryImpl::createExpansionRegion_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ExpansionRegion> element(new ExpansionRegionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<ExpansionRegion> UmlFactoryImpl::createExpansionRegion_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ExpansionRegion> element(new ExpansionRegionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ExpansionRegion> UmlFactoryImpl::createExpansionRegion_in_SuperGroup(std::weak_ptr<uml::ActivityGroup > par_superGroup) const
{
	std::shared_ptr<ExpansionRegion> element(new ExpansionRegionImpl(par_superGroup));
	if(auto wp = par_superGroup.lock())
	{
    		wp->getSubgroup()->push_back(element);
	}
	return element;
}

std::shared_ptr<Expression> UmlFactoryImpl::createExpression() const
{
	std::shared_ptr<Expression> element(new ExpressionImpl());
	return element;
}
std::shared_ptr<Expression> UmlFactoryImpl::createExpression_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Expression> element(new ExpressionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Expression> UmlFactoryImpl::createExpression_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Expression> element(new ExpressionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Expression> UmlFactoryImpl::createExpression_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<Expression> element(new ExpressionImpl(par_owningPackage));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Expression> UmlFactoryImpl::createExpression_in_OwningSlot(std::weak_ptr<uml::Slot > par_owningSlot) const
{
	std::shared_ptr<Expression> element(new ExpressionImpl(par_owningSlot));
	if(auto wp = par_owningSlot.lock())
	{
    		wp->getValue()->push_back(element);
	}
	return element;
}

std::shared_ptr<Expression> UmlFactoryImpl::createExpression_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Expression> element(new ExpressionImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<Extend> UmlFactoryImpl::createExtend() const
{
	std::shared_ptr<Extend> element(new ExtendImpl());
	return element;
}
std::shared_ptr<Extend> UmlFactoryImpl::createExtend_in_Extension(std::weak_ptr<uml::UseCase > par_extension) const
{
	std::shared_ptr<Extend> element(new ExtendImpl(par_extension));
	if(auto wp = par_extension.lock())
	{
    		wp->getExtend()->push_back(element);
	}
	return element;
}

std::shared_ptr<Extend> UmlFactoryImpl::createExtend_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Extend> element(new ExtendImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Extend> UmlFactoryImpl::createExtend_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Extend> element(new ExtendImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Extension> UmlFactoryImpl::createExtension() const
{
	std::shared_ptr<Extension> element(new ExtensionImpl());
	return element;
}
std::shared_ptr<Extension> UmlFactoryImpl::createExtension_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Extension> element(new ExtensionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Extension> UmlFactoryImpl::createExtension_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Extension> element(new ExtensionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Extension> UmlFactoryImpl::createExtension_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<Extension> element(new ExtensionImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Extension> UmlFactoryImpl::createExtension_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Extension> element(new ExtensionImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<Extension> UmlFactoryImpl::createExtension_in_Package(std::weak_ptr<uml::Package > par_package) const
{
	std::shared_ptr<Extension> element(new ExtensionImpl(par_package, UmlPackage::TYPE_PACKAGE));
	if(auto wp = par_package.lock())
	{
    		wp->getOwnedType()->push_back(element);
	}
	return element;
}

std::shared_ptr<ExtensionEnd> UmlFactoryImpl::createExtensionEnd() const
{
	std::shared_ptr<ExtensionEnd> element(new ExtensionEndImpl());
	return element;
}
std::shared_ptr<ExtensionEnd> UmlFactoryImpl::createExtensionEnd_in_AssociationEnd(std::weak_ptr<uml::Property > par_associationEnd) const
{
	std::shared_ptr<ExtensionEnd> element(new ExtensionEndImpl(par_associationEnd));
	if(auto wp = par_associationEnd.lock())
	{
    		wp->getQualifier()->push_back(element);
	}
	return element;
}

std::shared_ptr<ExtensionEnd> UmlFactoryImpl::createExtensionEnd_in_Class(std::weak_ptr<uml::Class > par_class) const
{
	std::shared_ptr<ExtensionEnd> element(new ExtensionEndImpl(par_class));
	if(auto wp = par_class.lock())
	{
    		wp->getOwnedAttribute()->push_back(element);
	}
	return element;
}

std::shared_ptr<ExtensionEnd> UmlFactoryImpl::createExtensionEnd_in_Datatype(std::weak_ptr<uml::DataType > par_datatype) const
{
	std::shared_ptr<ExtensionEnd> element(new ExtensionEndImpl(par_datatype));
	if(auto wp = par_datatype.lock())
	{
    		wp->getOwnedAttribute()->push_back(element);
	}
	return element;
}

std::shared_ptr<ExtensionEnd> UmlFactoryImpl::createExtensionEnd_in_Interface(std::weak_ptr<uml::Interface > par_interface) const
{
	std::shared_ptr<ExtensionEnd> element(new ExtensionEndImpl(par_interface));
	if(auto wp = par_interface.lock())
	{
    		wp->getOwnedAttribute()->push_back(element);
	}
	return element;
}

std::shared_ptr<ExtensionEnd> UmlFactoryImpl::createExtensionEnd_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ExtensionEnd> element(new ExtensionEndImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<ExtensionEnd> UmlFactoryImpl::createExtensionEnd_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ExtensionEnd> element(new ExtensionEndImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ExtensionEnd> UmlFactoryImpl::createExtensionEnd_in_OwningAssociation(std::weak_ptr<uml::Association > par_owningAssociation) const
{
	std::shared_ptr<ExtensionEnd> element(new ExtensionEndImpl(par_owningAssociation));
	if(auto wp = par_owningAssociation.lock())
	{
    		wp->getOwnedEnd()->push_back(element);
	}
	return element;
}

std::shared_ptr<ExtensionEnd> UmlFactoryImpl::createExtensionEnd_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<ExtensionEnd> element(new ExtensionEndImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<ExtensionPoint> UmlFactoryImpl::createExtensionPoint() const
{
	std::shared_ptr<ExtensionPoint> element(new ExtensionPointImpl());
	return element;
}
std::shared_ptr<ExtensionPoint> UmlFactoryImpl::createExtensionPoint_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ExtensionPoint> element(new ExtensionPointImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<ExtensionPoint> UmlFactoryImpl::createExtensionPoint_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ExtensionPoint> element(new ExtensionPointImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ExtensionPoint> UmlFactoryImpl::createExtensionPoint_in_UseCase(std::weak_ptr<uml::UseCase > par_useCase) const
{
	std::shared_ptr<ExtensionPoint> element(new ExtensionPointImpl(par_useCase));
	if(auto wp = par_useCase.lock())
	{
    		wp->getExtensionPoint()->push_back(element);
	}
	return element;
}

std::shared_ptr<Factory> UmlFactoryImpl::createFactory() const
{
	std::shared_ptr<Factory> element(new FactoryImpl());
	return element;
}
std::shared_ptr<FinalState> UmlFactoryImpl::createFinalState() const
{
	std::shared_ptr<FinalState> element(new FinalStateImpl());
	return element;
}
std::shared_ptr<FinalState> UmlFactoryImpl::createFinalState_in_Container(std::weak_ptr<uml::Region > par_container) const
{
	std::shared_ptr<FinalState> element(new FinalStateImpl(par_container));
	if(auto wp = par_container.lock())
	{
    		wp->getSubvertex()->push_back(element);
	}
	return element;
}

std::shared_ptr<FinalState> UmlFactoryImpl::createFinalState_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<FinalState> element(new FinalStateImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<FinalState> UmlFactoryImpl::createFinalState_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<FinalState> element(new FinalStateImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<FlowFinalNode> UmlFactoryImpl::createFlowFinalNode() const
{
	std::shared_ptr<FlowFinalNode> element(new FlowFinalNodeImpl());
	return element;
}
std::shared_ptr<FlowFinalNode> UmlFactoryImpl::createFlowFinalNode_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<FlowFinalNode> element(new FlowFinalNodeImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<FlowFinalNode> UmlFactoryImpl::createFlowFinalNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<FlowFinalNode> element(new FlowFinalNodeImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<FlowFinalNode> UmlFactoryImpl::createFlowFinalNode_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<FlowFinalNode> element(new FlowFinalNodeImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<FlowFinalNode> UmlFactoryImpl::createFlowFinalNode_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<FlowFinalNode> element(new FlowFinalNodeImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ForkNode> UmlFactoryImpl::createForkNode() const
{
	std::shared_ptr<ForkNode> element(new ForkNodeImpl());
	return element;
}
std::shared_ptr<ForkNode> UmlFactoryImpl::createForkNode_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ForkNode> element(new ForkNodeImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ForkNode> UmlFactoryImpl::createForkNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ForkNode> element(new ForkNodeImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ForkNode> UmlFactoryImpl::createForkNode_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ForkNode> element(new ForkNodeImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<ForkNode> UmlFactoryImpl::createForkNode_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ForkNode> element(new ForkNodeImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<FunctionBehavior> UmlFactoryImpl::createFunctionBehavior() const
{
	std::shared_ptr<FunctionBehavior> element(new FunctionBehaviorImpl());
	return element;
}
std::shared_ptr<FunctionBehavior> UmlFactoryImpl::createFunctionBehavior_in_BehavioredClassifier(std::weak_ptr<uml::BehavioredClassifier > par_behavioredClassifier) const
{
	std::shared_ptr<FunctionBehavior> element(new FunctionBehaviorImpl(par_behavioredClassifier));
	if(auto wp = par_behavioredClassifier.lock())
	{
    		wp->getOwnedBehavior()->push_back(element);
	}
	return element;
}

std::shared_ptr<FunctionBehavior> UmlFactoryImpl::createFunctionBehavior_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<FunctionBehavior> element(new FunctionBehaviorImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<FunctionBehavior> UmlFactoryImpl::createFunctionBehavior_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<FunctionBehavior> element(new FunctionBehaviorImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<FunctionBehavior> UmlFactoryImpl::createFunctionBehavior_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<FunctionBehavior> element(new FunctionBehaviorImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<FunctionBehavior> UmlFactoryImpl::createFunctionBehavior_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<FunctionBehavior> element(new FunctionBehaviorImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<FunctionBehavior> UmlFactoryImpl::createFunctionBehavior_in_Package(std::weak_ptr<uml::Package > par_package) const
{
	std::shared_ptr<FunctionBehavior> element(new FunctionBehaviorImpl(par_package, UmlPackage::TYPE_PACKAGE));
	if(auto wp = par_package.lock())
	{
    		wp->getOwnedType()->push_back(element);
	}
	return element;
}

std::shared_ptr<Gate> UmlFactoryImpl::createGate() const
{
	std::shared_ptr<Gate> element(new GateImpl());
	return element;
}
std::shared_ptr<Gate> UmlFactoryImpl::createGate_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Gate> element(new GateImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Gate> UmlFactoryImpl::createGate_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Gate> element(new GateImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<GeneralOrdering> UmlFactoryImpl::createGeneralOrdering() const
{
	std::shared_ptr<GeneralOrdering> element(new GeneralOrderingImpl());
	return element;
}
std::shared_ptr<GeneralOrdering> UmlFactoryImpl::createGeneralOrdering_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<GeneralOrdering> element(new GeneralOrderingImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<GeneralOrdering> UmlFactoryImpl::createGeneralOrdering_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<GeneralOrdering> element(new GeneralOrderingImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Generalization> UmlFactoryImpl::createGeneralization() const
{
	std::shared_ptr<Generalization> element(new GeneralizationImpl());
	return element;
}
std::shared_ptr<Generalization> UmlFactoryImpl::createGeneralization_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Generalization> element(new GeneralizationImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Generalization> UmlFactoryImpl::createGeneralization_in_Specific(std::weak_ptr<uml::Classifier > par_specific) const
{
	std::shared_ptr<Generalization> element(new GeneralizationImpl(par_specific));
	if(auto wp = par_specific.lock())
	{
    		wp->getGeneralization()->push_back(element);
	}
	return element;
}

std::shared_ptr<GeneralizationSet> UmlFactoryImpl::createGeneralizationSet() const
{
	std::shared_ptr<GeneralizationSet> element(new GeneralizationSetImpl());
	return element;
}
std::shared_ptr<GeneralizationSet> UmlFactoryImpl::createGeneralizationSet_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<GeneralizationSet> element(new GeneralizationSetImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<GeneralizationSet> UmlFactoryImpl::createGeneralizationSet_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<GeneralizationSet> element(new GeneralizationSetImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<GeneralizationSet> UmlFactoryImpl::createGeneralizationSet_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<GeneralizationSet> element(new GeneralizationSetImpl(par_owningPackage));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<GeneralizationSet> UmlFactoryImpl::createGeneralizationSet_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<GeneralizationSet> element(new GeneralizationSetImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<Image> UmlFactoryImpl::createImage() const
{
	std::shared_ptr<Image> element(new ImageImpl());
	return element;
}
std::shared_ptr<Image> UmlFactoryImpl::createImage_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Image> element(new ImageImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Include> UmlFactoryImpl::createInclude() const
{
	std::shared_ptr<Include> element(new IncludeImpl());
	return element;
}
std::shared_ptr<Include> UmlFactoryImpl::createInclude_in_IncludingCase(std::weak_ptr<uml::UseCase > par_includingCase) const
{
	std::shared_ptr<Include> element(new IncludeImpl(par_includingCase));
	if(auto wp = par_includingCase.lock())
	{
    		wp->getInclude()->push_back(element);
	}
	return element;
}

std::shared_ptr<Include> UmlFactoryImpl::createInclude_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Include> element(new IncludeImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Include> UmlFactoryImpl::createInclude_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Include> element(new IncludeImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<InformationFlow> UmlFactoryImpl::createInformationFlow() const
{
	std::shared_ptr<InformationFlow> element(new InformationFlowImpl());
	return element;
}
std::shared_ptr<InformationFlow> UmlFactoryImpl::createInformationFlow_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<InformationFlow> element(new InformationFlowImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<InformationFlow> UmlFactoryImpl::createInformationFlow_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<InformationFlow> element(new InformationFlowImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<InformationFlow> UmlFactoryImpl::createInformationFlow_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<InformationFlow> element(new InformationFlowImpl(par_owningPackage));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<InformationFlow> UmlFactoryImpl::createInformationFlow_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<InformationFlow> element(new InformationFlowImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<InformationItem> UmlFactoryImpl::createInformationItem() const
{
	std::shared_ptr<InformationItem> element(new InformationItemImpl());
	return element;
}
std::shared_ptr<InformationItem> UmlFactoryImpl::createInformationItem_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<InformationItem> element(new InformationItemImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<InformationItem> UmlFactoryImpl::createInformationItem_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<InformationItem> element(new InformationItemImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<InformationItem> UmlFactoryImpl::createInformationItem_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<InformationItem> element(new InformationItemImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<InformationItem> UmlFactoryImpl::createInformationItem_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<InformationItem> element(new InformationItemImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<InformationItem> UmlFactoryImpl::createInformationItem_in_Package(std::weak_ptr<uml::Package > par_package) const
{
	std::shared_ptr<InformationItem> element(new InformationItemImpl(par_package, UmlPackage::TYPE_PACKAGE));
	if(auto wp = par_package.lock())
	{
    		wp->getOwnedType()->push_back(element);
	}
	return element;
}

std::shared_ptr<InitialNode> UmlFactoryImpl::createInitialNode() const
{
	std::shared_ptr<InitialNode> element(new InitialNodeImpl());
	return element;
}
std::shared_ptr<InitialNode> UmlFactoryImpl::createInitialNode_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<InitialNode> element(new InitialNodeImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<InitialNode> UmlFactoryImpl::createInitialNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<InitialNode> element(new InitialNodeImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<InitialNode> UmlFactoryImpl::createInitialNode_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<InitialNode> element(new InitialNodeImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<InitialNode> UmlFactoryImpl::createInitialNode_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<InitialNode> element(new InitialNodeImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<InputPin> UmlFactoryImpl::createInputPin() const
{
	std::shared_ptr<InputPin> element(new InputPinImpl());
	return element;
}
std::shared_ptr<InputPin> UmlFactoryImpl::createInputPin_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<InputPin> element(new InputPinImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<InputPin> UmlFactoryImpl::createInputPin_in_CallOperationAction(std::weak_ptr<uml::CallOperationAction > par_callOperationAction) const
{
	std::shared_ptr<InputPin> element(new InputPinImpl(par_callOperationAction));
	if(auto wp = par_callOperationAction.lock())
	{
			wp->setTarget(element);
	}
	return element;
}

std::shared_ptr<InputPin> UmlFactoryImpl::createInputPin_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<InputPin> element(new InputPinImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<InputPin> UmlFactoryImpl::createInputPin_in_InvocationAction(std::weak_ptr<uml::InvocationAction > par_invocationAction) const
{
	std::shared_ptr<InputPin> element(new InputPinImpl(par_invocationAction));
	if(auto wp = par_invocationAction.lock())
	{
    		wp->getArgument()->push_back(element);
	}
	return element;
}

std::shared_ptr<InputPin> UmlFactoryImpl::createInputPin_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<InputPin> element(new InputPinImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<InputPin> UmlFactoryImpl::createInputPin_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<InputPin> element(new InputPinImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<InputPin> UmlFactoryImpl::createInputPin_in_StructuralFeatureAction(std::weak_ptr<uml::StructuralFeatureAction > par_structuralFeatureAction) const
{
	std::shared_ptr<InputPin> element(new InputPinImpl(par_structuralFeatureAction));
	if(auto wp = par_structuralFeatureAction.lock())
	{
			wp->setObject(element);
	}
	return element;
}

std::shared_ptr<InstanceSpecification> UmlFactoryImpl::createInstanceSpecification() const
{
	std::shared_ptr<InstanceSpecification> element(new InstanceSpecificationImpl());
	return element;
}
std::shared_ptr<InstanceSpecification> UmlFactoryImpl::createInstanceSpecification_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<InstanceSpecification> element(new InstanceSpecificationImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<InstanceSpecification> UmlFactoryImpl::createInstanceSpecification_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<InstanceSpecification> element(new InstanceSpecificationImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<InstanceSpecification> UmlFactoryImpl::createInstanceSpecification_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<InstanceSpecification> element(new InstanceSpecificationImpl(par_owningPackage));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<InstanceSpecification> UmlFactoryImpl::createInstanceSpecification_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<InstanceSpecification> element(new InstanceSpecificationImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<InstanceValue> UmlFactoryImpl::createInstanceValue() const
{
	std::shared_ptr<InstanceValue> element(new InstanceValueImpl());
	return element;
}
std::shared_ptr<InstanceValue> UmlFactoryImpl::createInstanceValue_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<InstanceValue> element(new InstanceValueImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<InstanceValue> UmlFactoryImpl::createInstanceValue_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<InstanceValue> element(new InstanceValueImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<InstanceValue> UmlFactoryImpl::createInstanceValue_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<InstanceValue> element(new InstanceValueImpl(par_owningPackage));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<InstanceValue> UmlFactoryImpl::createInstanceValue_in_OwningSlot(std::weak_ptr<uml::Slot > par_owningSlot) const
{
	std::shared_ptr<InstanceValue> element(new InstanceValueImpl(par_owningSlot));
	if(auto wp = par_owningSlot.lock())
	{
    		wp->getValue()->push_back(element);
	}
	return element;
}

std::shared_ptr<InstanceValue> UmlFactoryImpl::createInstanceValue_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<InstanceValue> element(new InstanceValueImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<Interaction> UmlFactoryImpl::createInteraction() const
{
	std::shared_ptr<Interaction> element(new InteractionImpl());
	return element;
}
std::shared_ptr<Interaction> UmlFactoryImpl::createInteraction_in_BehavioredClassifier(std::weak_ptr<uml::BehavioredClassifier > par_behavioredClassifier) const
{
	std::shared_ptr<Interaction> element(new InteractionImpl(par_behavioredClassifier));
	if(auto wp = par_behavioredClassifier.lock())
	{
    		wp->getOwnedBehavior()->push_back(element);
	}
	return element;
}

std::shared_ptr<Interaction> UmlFactoryImpl::createInteraction_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction) const
{
	std::shared_ptr<Interaction> element(new InteractionImpl(par_enclosingInteraction));
	if(auto wp = par_enclosingInteraction.lock())
	{
    		wp->getFragment()->push_back(element);
	}
	return element;
}

std::shared_ptr<Interaction> UmlFactoryImpl::createInteraction_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand) const
{
	std::shared_ptr<Interaction> element(new InteractionImpl(par_enclosingOperand));
	if(auto wp = par_enclosingOperand.lock())
	{
    		wp->getFragment()->push_back(element);
	}
	return element;
}

std::shared_ptr<Interaction> UmlFactoryImpl::createInteraction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Interaction> element(new InteractionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Interaction> UmlFactoryImpl::createInteraction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Interaction> element(new InteractionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Interaction> UmlFactoryImpl::createInteraction_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<Interaction> element(new InteractionImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Interaction> UmlFactoryImpl::createInteraction_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Interaction> element(new InteractionImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<Interaction> UmlFactoryImpl::createInteraction_in_Package(std::weak_ptr<uml::Package > par_package) const
{
	std::shared_ptr<Interaction> element(new InteractionImpl(par_package, UmlPackage::TYPE_PACKAGE));
	if(auto wp = par_package.lock())
	{
    		wp->getOwnedType()->push_back(element);
	}
	return element;
}

std::shared_ptr<InteractionConstraint> UmlFactoryImpl::createInteractionConstraint() const
{
	std::shared_ptr<InteractionConstraint> element(new InteractionConstraintImpl());
	return element;
}
std::shared_ptr<InteractionConstraint> UmlFactoryImpl::createInteractionConstraint_in_Context(std::weak_ptr<uml::Namespace > par_context) const
{
	std::shared_ptr<InteractionConstraint> element(new InteractionConstraintImpl(par_context, UmlPackage::CONSTRAINT_CONTEXT));
	if(auto wp = par_context.lock())
	{
    		wp->getOwnedRule()->push_back(element);
	}
	return element;
}

std::shared_ptr<InteractionConstraint> UmlFactoryImpl::createInteractionConstraint_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<InteractionConstraint> element(new InteractionConstraintImpl(par_namespace, UmlPackage::NAMEDELEMENT_NAMESPACE));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<InteractionConstraint> UmlFactoryImpl::createInteractionConstraint_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<InteractionConstraint> element(new InteractionConstraintImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<InteractionConstraint> UmlFactoryImpl::createInteractionConstraint_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<InteractionConstraint> element(new InteractionConstraintImpl(par_owningPackage));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<InteractionConstraint> UmlFactoryImpl::createInteractionConstraint_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<InteractionConstraint> element(new InteractionConstraintImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<InteractionOperand> UmlFactoryImpl::createInteractionOperand() const
{
	std::shared_ptr<InteractionOperand> element(new InteractionOperandImpl());
	return element;
}
std::shared_ptr<InteractionOperand> UmlFactoryImpl::createInteractionOperand_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction) const
{
	std::shared_ptr<InteractionOperand> element(new InteractionOperandImpl(par_enclosingInteraction));
	if(auto wp = par_enclosingInteraction.lock())
	{
    		wp->getFragment()->push_back(element);
	}
	return element;
}

std::shared_ptr<InteractionOperand> UmlFactoryImpl::createInteractionOperand_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand) const
{
	std::shared_ptr<InteractionOperand> element(new InteractionOperandImpl(par_enclosingOperand));
	if(auto wp = par_enclosingOperand.lock())
	{
    		wp->getFragment()->push_back(element);
	}
	return element;
}

std::shared_ptr<InteractionOperand> UmlFactoryImpl::createInteractionOperand_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<InteractionOperand> element(new InteractionOperandImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<InteractionOperand> UmlFactoryImpl::createInteractionOperand_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<InteractionOperand> element(new InteractionOperandImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<InteractionUse> UmlFactoryImpl::createInteractionUse() const
{
	std::shared_ptr<InteractionUse> element(new InteractionUseImpl());
	return element;
}
std::shared_ptr<InteractionUse> UmlFactoryImpl::createInteractionUse_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction) const
{
	std::shared_ptr<InteractionUse> element(new InteractionUseImpl(par_enclosingInteraction));
	if(auto wp = par_enclosingInteraction.lock())
	{
    		wp->getFragment()->push_back(element);
	}
	return element;
}

std::shared_ptr<InteractionUse> UmlFactoryImpl::createInteractionUse_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand) const
{
	std::shared_ptr<InteractionUse> element(new InteractionUseImpl(par_enclosingOperand));
	if(auto wp = par_enclosingOperand.lock())
	{
    		wp->getFragment()->push_back(element);
	}
	return element;
}

std::shared_ptr<InteractionUse> UmlFactoryImpl::createInteractionUse_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<InteractionUse> element(new InteractionUseImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<InteractionUse> UmlFactoryImpl::createInteractionUse_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<InteractionUse> element(new InteractionUseImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Interface> UmlFactoryImpl::createInterface() const
{
	std::shared_ptr<Interface> element(new InterfaceImpl());
	return element;
}
std::shared_ptr<Interface> UmlFactoryImpl::createInterface_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Interface> element(new InterfaceImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Interface> UmlFactoryImpl::createInterface_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Interface> element(new InterfaceImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Interface> UmlFactoryImpl::createInterface_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<Interface> element(new InterfaceImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Interface> UmlFactoryImpl::createInterface_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Interface> element(new InterfaceImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<Interface> UmlFactoryImpl::createInterface_in_Package(std::weak_ptr<uml::Package > par_package) const
{
	std::shared_ptr<Interface> element(new InterfaceImpl(par_package, UmlPackage::TYPE_PACKAGE));
	if(auto wp = par_package.lock())
	{
    		wp->getOwnedType()->push_back(element);
	}
	return element;
}

std::shared_ptr<InterfaceRealization> UmlFactoryImpl::createInterfaceRealization() const
{
	std::shared_ptr<InterfaceRealization> element(new InterfaceRealizationImpl());
	return element;
}
std::shared_ptr<InterfaceRealization> UmlFactoryImpl::createInterfaceRealization_in_ImplementingClassifier(std::weak_ptr<uml::BehavioredClassifier > par_implementingClassifier) const
{
	std::shared_ptr<InterfaceRealization> element(new InterfaceRealizationImpl(par_implementingClassifier));
	if(auto wp = par_implementingClassifier.lock())
	{
    		wp->getInterfaceRealization()->push_back(element);
	}
	return element;
}

std::shared_ptr<InterfaceRealization> UmlFactoryImpl::createInterfaceRealization_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<InterfaceRealization> element(new InterfaceRealizationImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<InterfaceRealization> UmlFactoryImpl::createInterfaceRealization_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<InterfaceRealization> element(new InterfaceRealizationImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<InterfaceRealization> UmlFactoryImpl::createInterfaceRealization_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<InterfaceRealization> element(new InterfaceRealizationImpl(par_owningPackage));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<InterfaceRealization> UmlFactoryImpl::createInterfaceRealization_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<InterfaceRealization> element(new InterfaceRealizationImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<InterruptibleActivityRegion> UmlFactoryImpl::createInterruptibleActivityRegion() const
{
	std::shared_ptr<InterruptibleActivityRegion> element(new InterruptibleActivityRegionImpl());
	return element;
}
std::shared_ptr<InterruptibleActivityRegion> UmlFactoryImpl::createInterruptibleActivityRegion_in_InActivity(std::weak_ptr<uml::Activity > par_inActivity) const
{
	std::shared_ptr<InterruptibleActivityRegion> element(new InterruptibleActivityRegionImpl(par_inActivity));
	if(auto wp = par_inActivity.lock())
	{
    		wp->getGroup()->push_back(element);
	}
	return element;
}

std::shared_ptr<InterruptibleActivityRegion> UmlFactoryImpl::createInterruptibleActivityRegion_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<InterruptibleActivityRegion> element(new InterruptibleActivityRegionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<InterruptibleActivityRegion> UmlFactoryImpl::createInterruptibleActivityRegion_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<InterruptibleActivityRegion> element(new InterruptibleActivityRegionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<InterruptibleActivityRegion> UmlFactoryImpl::createInterruptibleActivityRegion_in_SuperGroup(std::weak_ptr<uml::ActivityGroup > par_superGroup) const
{
	std::shared_ptr<InterruptibleActivityRegion> element(new InterruptibleActivityRegionImpl(par_superGroup));
	if(auto wp = par_superGroup.lock())
	{
    		wp->getSubgroup()->push_back(element);
	}
	return element;
}

std::shared_ptr<Interval> UmlFactoryImpl::createInterval() const
{
	std::shared_ptr<Interval> element(new IntervalImpl());
	return element;
}
std::shared_ptr<Interval> UmlFactoryImpl::createInterval_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Interval> element(new IntervalImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Interval> UmlFactoryImpl::createInterval_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Interval> element(new IntervalImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Interval> UmlFactoryImpl::createInterval_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<Interval> element(new IntervalImpl(par_owningPackage));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Interval> UmlFactoryImpl::createInterval_in_OwningSlot(std::weak_ptr<uml::Slot > par_owningSlot) const
{
	std::shared_ptr<Interval> element(new IntervalImpl(par_owningSlot));
	if(auto wp = par_owningSlot.lock())
	{
    		wp->getValue()->push_back(element);
	}
	return element;
}

std::shared_ptr<Interval> UmlFactoryImpl::createInterval_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Interval> element(new IntervalImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<IntervalConstraint> UmlFactoryImpl::createIntervalConstraint() const
{
	std::shared_ptr<IntervalConstraint> element(new IntervalConstraintImpl());
	return element;
}
std::shared_ptr<IntervalConstraint> UmlFactoryImpl::createIntervalConstraint_in_Context(std::weak_ptr<uml::Namespace > par_context) const
{
	std::shared_ptr<IntervalConstraint> element(new IntervalConstraintImpl(par_context, UmlPackage::CONSTRAINT_CONTEXT));
	if(auto wp = par_context.lock())
	{
    		wp->getOwnedRule()->push_back(element);
	}
	return element;
}

std::shared_ptr<IntervalConstraint> UmlFactoryImpl::createIntervalConstraint_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<IntervalConstraint> element(new IntervalConstraintImpl(par_namespace, UmlPackage::NAMEDELEMENT_NAMESPACE));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<IntervalConstraint> UmlFactoryImpl::createIntervalConstraint_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<IntervalConstraint> element(new IntervalConstraintImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<IntervalConstraint> UmlFactoryImpl::createIntervalConstraint_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<IntervalConstraint> element(new IntervalConstraintImpl(par_owningPackage));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<IntervalConstraint> UmlFactoryImpl::createIntervalConstraint_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<IntervalConstraint> element(new IntervalConstraintImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<JoinNode> UmlFactoryImpl::createJoinNode() const
{
	std::shared_ptr<JoinNode> element(new JoinNodeImpl());
	return element;
}
std::shared_ptr<JoinNode> UmlFactoryImpl::createJoinNode_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<JoinNode> element(new JoinNodeImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<JoinNode> UmlFactoryImpl::createJoinNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<JoinNode> element(new JoinNodeImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<JoinNode> UmlFactoryImpl::createJoinNode_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<JoinNode> element(new JoinNodeImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<JoinNode> UmlFactoryImpl::createJoinNode_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<JoinNode> element(new JoinNodeImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Lifeline> UmlFactoryImpl::createLifeline() const
{
	std::shared_ptr<Lifeline> element(new LifelineImpl());
	return element;
}
std::shared_ptr<Lifeline> UmlFactoryImpl::createLifeline_in_Interaction(std::weak_ptr<uml::Interaction > par_interaction) const
{
	std::shared_ptr<Lifeline> element(new LifelineImpl(par_interaction));
	if(auto wp = par_interaction.lock())
	{
    		wp->getLifeline()->push_back(element);
	}
	return element;
}

std::shared_ptr<Lifeline> UmlFactoryImpl::createLifeline_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Lifeline> element(new LifelineImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Lifeline> UmlFactoryImpl::createLifeline_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Lifeline> element(new LifelineImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<LinkEndCreationData> UmlFactoryImpl::createLinkEndCreationData() const
{
	std::shared_ptr<LinkEndCreationData> element(new LinkEndCreationDataImpl());
	return element;
}
std::shared_ptr<LinkEndCreationData> UmlFactoryImpl::createLinkEndCreationData_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<LinkEndCreationData> element(new LinkEndCreationDataImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<LinkEndData> UmlFactoryImpl::createLinkEndData() const
{
	std::shared_ptr<LinkEndData> element(new LinkEndDataImpl());
	return element;
}
std::shared_ptr<LinkEndData> UmlFactoryImpl::createLinkEndData_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<LinkEndData> element(new LinkEndDataImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<LinkEndDestructionData> UmlFactoryImpl::createLinkEndDestructionData() const
{
	std::shared_ptr<LinkEndDestructionData> element(new LinkEndDestructionDataImpl());
	return element;
}
std::shared_ptr<LinkEndDestructionData> UmlFactoryImpl::createLinkEndDestructionData_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<LinkEndDestructionData> element(new LinkEndDestructionDataImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<LiteralBoolean> UmlFactoryImpl::createLiteralBoolean() const
{
	std::shared_ptr<LiteralBoolean> element(new LiteralBooleanImpl());
	return element;
}
std::shared_ptr<LiteralBoolean> UmlFactoryImpl::createLiteralBoolean_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<LiteralBoolean> element(new LiteralBooleanImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<LiteralBoolean> UmlFactoryImpl::createLiteralBoolean_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<LiteralBoolean> element(new LiteralBooleanImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<LiteralBoolean> UmlFactoryImpl::createLiteralBoolean_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<LiteralBoolean> element(new LiteralBooleanImpl(par_owningPackage));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<LiteralBoolean> UmlFactoryImpl::createLiteralBoolean_in_OwningSlot(std::weak_ptr<uml::Slot > par_owningSlot) const
{
	std::shared_ptr<LiteralBoolean> element(new LiteralBooleanImpl(par_owningSlot));
	if(auto wp = par_owningSlot.lock())
	{
    		wp->getValue()->push_back(element);
	}
	return element;
}

std::shared_ptr<LiteralBoolean> UmlFactoryImpl::createLiteralBoolean_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<LiteralBoolean> element(new LiteralBooleanImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<LiteralInteger> UmlFactoryImpl::createLiteralInteger() const
{
	std::shared_ptr<LiteralInteger> element(new LiteralIntegerImpl());
	return element;
}
std::shared_ptr<LiteralInteger> UmlFactoryImpl::createLiteralInteger_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<LiteralInteger> element(new LiteralIntegerImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<LiteralInteger> UmlFactoryImpl::createLiteralInteger_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<LiteralInteger> element(new LiteralIntegerImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<LiteralInteger> UmlFactoryImpl::createLiteralInteger_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<LiteralInteger> element(new LiteralIntegerImpl(par_owningPackage));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<LiteralInteger> UmlFactoryImpl::createLiteralInteger_in_OwningSlot(std::weak_ptr<uml::Slot > par_owningSlot) const
{
	std::shared_ptr<LiteralInteger> element(new LiteralIntegerImpl(par_owningSlot));
	if(auto wp = par_owningSlot.lock())
	{
    		wp->getValue()->push_back(element);
	}
	return element;
}

std::shared_ptr<LiteralInteger> UmlFactoryImpl::createLiteralInteger_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<LiteralInteger> element(new LiteralIntegerImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<LiteralNull> UmlFactoryImpl::createLiteralNull() const
{
	std::shared_ptr<LiteralNull> element(new LiteralNullImpl());
	return element;
}
std::shared_ptr<LiteralNull> UmlFactoryImpl::createLiteralNull_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<LiteralNull> element(new LiteralNullImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<LiteralNull> UmlFactoryImpl::createLiteralNull_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<LiteralNull> element(new LiteralNullImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<LiteralNull> UmlFactoryImpl::createLiteralNull_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<LiteralNull> element(new LiteralNullImpl(par_owningPackage));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<LiteralNull> UmlFactoryImpl::createLiteralNull_in_OwningSlot(std::weak_ptr<uml::Slot > par_owningSlot) const
{
	std::shared_ptr<LiteralNull> element(new LiteralNullImpl(par_owningSlot));
	if(auto wp = par_owningSlot.lock())
	{
    		wp->getValue()->push_back(element);
	}
	return element;
}

std::shared_ptr<LiteralNull> UmlFactoryImpl::createLiteralNull_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<LiteralNull> element(new LiteralNullImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<LiteralReal> UmlFactoryImpl::createLiteralReal() const
{
	std::shared_ptr<LiteralReal> element(new LiteralRealImpl());
	return element;
}
std::shared_ptr<LiteralReal> UmlFactoryImpl::createLiteralReal_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<LiteralReal> element(new LiteralRealImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<LiteralReal> UmlFactoryImpl::createLiteralReal_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<LiteralReal> element(new LiteralRealImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<LiteralReal> UmlFactoryImpl::createLiteralReal_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<LiteralReal> element(new LiteralRealImpl(par_owningPackage));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<LiteralReal> UmlFactoryImpl::createLiteralReal_in_OwningSlot(std::weak_ptr<uml::Slot > par_owningSlot) const
{
	std::shared_ptr<LiteralReal> element(new LiteralRealImpl(par_owningSlot));
	if(auto wp = par_owningSlot.lock())
	{
    		wp->getValue()->push_back(element);
	}
	return element;
}

std::shared_ptr<LiteralReal> UmlFactoryImpl::createLiteralReal_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<LiteralReal> element(new LiteralRealImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<LiteralString> UmlFactoryImpl::createLiteralString() const
{
	std::shared_ptr<LiteralString> element(new LiteralStringImpl());
	return element;
}
std::shared_ptr<LiteralString> UmlFactoryImpl::createLiteralString_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<LiteralString> element(new LiteralStringImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<LiteralString> UmlFactoryImpl::createLiteralString_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<LiteralString> element(new LiteralStringImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<LiteralString> UmlFactoryImpl::createLiteralString_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<LiteralString> element(new LiteralStringImpl(par_owningPackage));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<LiteralString> UmlFactoryImpl::createLiteralString_in_OwningSlot(std::weak_ptr<uml::Slot > par_owningSlot) const
{
	std::shared_ptr<LiteralString> element(new LiteralStringImpl(par_owningSlot));
	if(auto wp = par_owningSlot.lock())
	{
    		wp->getValue()->push_back(element);
	}
	return element;
}

std::shared_ptr<LiteralString> UmlFactoryImpl::createLiteralString_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<LiteralString> element(new LiteralStringImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<LiteralUnlimitedNatural> UmlFactoryImpl::createLiteralUnlimitedNatural() const
{
	std::shared_ptr<LiteralUnlimitedNatural> element(new LiteralUnlimitedNaturalImpl());
	return element;
}
std::shared_ptr<LiteralUnlimitedNatural> UmlFactoryImpl::createLiteralUnlimitedNatural_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<LiteralUnlimitedNatural> element(new LiteralUnlimitedNaturalImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<LiteralUnlimitedNatural> UmlFactoryImpl::createLiteralUnlimitedNatural_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<LiteralUnlimitedNatural> element(new LiteralUnlimitedNaturalImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<LiteralUnlimitedNatural> UmlFactoryImpl::createLiteralUnlimitedNatural_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<LiteralUnlimitedNatural> element(new LiteralUnlimitedNaturalImpl(par_owningPackage));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<LiteralUnlimitedNatural> UmlFactoryImpl::createLiteralUnlimitedNatural_in_OwningSlot(std::weak_ptr<uml::Slot > par_owningSlot) const
{
	std::shared_ptr<LiteralUnlimitedNatural> element(new LiteralUnlimitedNaturalImpl(par_owningSlot));
	if(auto wp = par_owningSlot.lock())
	{
    		wp->getValue()->push_back(element);
	}
	return element;
}

std::shared_ptr<LiteralUnlimitedNatural> UmlFactoryImpl::createLiteralUnlimitedNatural_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<LiteralUnlimitedNatural> element(new LiteralUnlimitedNaturalImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<LoopNode> UmlFactoryImpl::createLoopNode() const
{
	std::shared_ptr<LoopNode> element(new LoopNodeImpl());
	return element;
}
std::shared_ptr<LoopNode> UmlFactoryImpl::createLoopNode_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<LoopNode> element(new LoopNodeImpl(par_activity, UmlPackage::ACTIVITYNODE_ACTIVITY));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<LoopNode> UmlFactoryImpl::createLoopNode_in_InActivity(std::weak_ptr<uml::Activity > par_inActivity) const
{
	std::shared_ptr<LoopNode> element(new LoopNodeImpl(par_inActivity, UmlPackage::ACTIVITYGROUP_INACTIVITY));
	if(auto wp = par_inActivity.lock())
	{
    		wp->getGroup()->push_back(element);
	}
	return element;
}

std::shared_ptr<LoopNode> UmlFactoryImpl::createLoopNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<LoopNode> element(new LoopNodeImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<LoopNode> UmlFactoryImpl::createLoopNode_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<LoopNode> element(new LoopNodeImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<LoopNode> UmlFactoryImpl::createLoopNode_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<LoopNode> element(new LoopNodeImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<LoopNode> UmlFactoryImpl::createLoopNode_in_SuperGroup(std::weak_ptr<uml::ActivityGroup > par_superGroup) const
{
	std::shared_ptr<LoopNode> element(new LoopNodeImpl(par_superGroup));
	if(auto wp = par_superGroup.lock())
	{
    		wp->getSubgroup()->push_back(element);
	}
	return element;
}

std::shared_ptr<Manifestation> UmlFactoryImpl::createManifestation() const
{
	std::shared_ptr<Manifestation> element(new ManifestationImpl());
	return element;
}
std::shared_ptr<Manifestation> UmlFactoryImpl::createManifestation_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Manifestation> element(new ManifestationImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Manifestation> UmlFactoryImpl::createManifestation_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Manifestation> element(new ManifestationImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Manifestation> UmlFactoryImpl::createManifestation_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<Manifestation> element(new ManifestationImpl(par_owningPackage));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Manifestation> UmlFactoryImpl::createManifestation_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Manifestation> element(new ManifestationImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<MergeNode> UmlFactoryImpl::createMergeNode() const
{
	std::shared_ptr<MergeNode> element(new MergeNodeImpl());
	return element;
}
std::shared_ptr<MergeNode> UmlFactoryImpl::createMergeNode_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<MergeNode> element(new MergeNodeImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<MergeNode> UmlFactoryImpl::createMergeNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<MergeNode> element(new MergeNodeImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<MergeNode> UmlFactoryImpl::createMergeNode_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<MergeNode> element(new MergeNodeImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<MergeNode> UmlFactoryImpl::createMergeNode_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<MergeNode> element(new MergeNodeImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Message> UmlFactoryImpl::createMessage() const
{
	std::shared_ptr<Message> element(new MessageImpl());
	return element;
}
std::shared_ptr<Message> UmlFactoryImpl::createMessage_in_Interaction(std::weak_ptr<uml::Interaction > par_interaction) const
{
	std::shared_ptr<Message> element(new MessageImpl(par_interaction));
	if(auto wp = par_interaction.lock())
	{
    		wp->getMessage()->push_back(element);
	}
	return element;
}

std::shared_ptr<Message> UmlFactoryImpl::createMessage_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Message> element(new MessageImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Message> UmlFactoryImpl::createMessage_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Message> element(new MessageImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<MessageOccurrenceSpecification> UmlFactoryImpl::createMessageOccurrenceSpecification() const
{
	std::shared_ptr<MessageOccurrenceSpecification> element(new MessageOccurrenceSpecificationImpl());
	return element;
}
std::shared_ptr<MessageOccurrenceSpecification> UmlFactoryImpl::createMessageOccurrenceSpecification_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction) const
{
	std::shared_ptr<MessageOccurrenceSpecification> element(new MessageOccurrenceSpecificationImpl(par_enclosingInteraction));
	if(auto wp = par_enclosingInteraction.lock())
	{
    		wp->getFragment()->push_back(element);
	}
	return element;
}

std::shared_ptr<MessageOccurrenceSpecification> UmlFactoryImpl::createMessageOccurrenceSpecification_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand) const
{
	std::shared_ptr<MessageOccurrenceSpecification> element(new MessageOccurrenceSpecificationImpl(par_enclosingOperand));
	if(auto wp = par_enclosingOperand.lock())
	{
    		wp->getFragment()->push_back(element);
	}
	return element;
}

std::shared_ptr<MessageOccurrenceSpecification> UmlFactoryImpl::createMessageOccurrenceSpecification_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<MessageOccurrenceSpecification> element(new MessageOccurrenceSpecificationImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<MessageOccurrenceSpecification> UmlFactoryImpl::createMessageOccurrenceSpecification_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<MessageOccurrenceSpecification> element(new MessageOccurrenceSpecificationImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Model> UmlFactoryImpl::createModel() const
{
	std::shared_ptr<Model> element(new ModelImpl());
	return element;
}
std::shared_ptr<Model> UmlFactoryImpl::createModel_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Model> element(new ModelImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Model> UmlFactoryImpl::createModel_in_NestingPackage(std::weak_ptr<uml::Package > par_nestingPackage) const
{
	std::shared_ptr<Model> element(new ModelImpl(par_nestingPackage, UmlPackage::PACKAGE_NESTINGPACKAGE));
	if(auto wp = par_nestingPackage.lock())
	{
    		wp->getNestedPackage()->push_back(element);
	}
	return element;
}

std::shared_ptr<Model> UmlFactoryImpl::createModel_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Model> element(new ModelImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Model> UmlFactoryImpl::createModel_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<Model> element(new ModelImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Model> UmlFactoryImpl::createModel_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Model> element(new ModelImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<Node> UmlFactoryImpl::createNode() const
{
	std::shared_ptr<Node> element(new NodeImpl());
	return element;
}
std::shared_ptr<Node> UmlFactoryImpl::createNode_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Node> element(new NodeImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Node> UmlFactoryImpl::createNode_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Node> element(new NodeImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Node> UmlFactoryImpl::createNode_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<Node> element(new NodeImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Node> UmlFactoryImpl::createNode_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Node> element(new NodeImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<Node> UmlFactoryImpl::createNode_in_Package(std::weak_ptr<uml::Package > par_package) const
{
	std::shared_ptr<Node> element(new NodeImpl(par_package, UmlPackage::TYPE_PACKAGE));
	if(auto wp = par_package.lock())
	{
    		wp->getOwnedType()->push_back(element);
	}
	return element;
}

std::shared_ptr<Object> UmlFactoryImpl::createObject() const
{
	std::shared_ptr<Object> element(new ObjectImpl());
	return element;
}
std::shared_ptr<ObjectFlow> UmlFactoryImpl::createObjectFlow() const
{
	std::shared_ptr<ObjectFlow> element(new ObjectFlowImpl());
	return element;
}
std::shared_ptr<ObjectFlow> UmlFactoryImpl::createObjectFlow_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ObjectFlow> element(new ObjectFlowImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getEdge()->push_back(element);
	}
	return element;
}

std::shared_ptr<ObjectFlow> UmlFactoryImpl::createObjectFlow_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ObjectFlow> element(new ObjectFlowImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getEdge()->push_back(element);
	}
	return element;
}

std::shared_ptr<ObjectFlow> UmlFactoryImpl::createObjectFlow_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ObjectFlow> element(new ObjectFlowImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<ObjectFlow> UmlFactoryImpl::createObjectFlow_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ObjectFlow> element(new ObjectFlowImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<OccurrenceSpecification> UmlFactoryImpl::createOccurrenceSpecification() const
{
	std::shared_ptr<OccurrenceSpecification> element(new OccurrenceSpecificationImpl());
	return element;
}
std::shared_ptr<OccurrenceSpecification> UmlFactoryImpl::createOccurrenceSpecification_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction) const
{
	std::shared_ptr<OccurrenceSpecification> element(new OccurrenceSpecificationImpl(par_enclosingInteraction));
	if(auto wp = par_enclosingInteraction.lock())
	{
    		wp->getFragment()->push_back(element);
	}
	return element;
}

std::shared_ptr<OccurrenceSpecification> UmlFactoryImpl::createOccurrenceSpecification_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand) const
{
	std::shared_ptr<OccurrenceSpecification> element(new OccurrenceSpecificationImpl(par_enclosingOperand));
	if(auto wp = par_enclosingOperand.lock())
	{
    		wp->getFragment()->push_back(element);
	}
	return element;
}

std::shared_ptr<OccurrenceSpecification> UmlFactoryImpl::createOccurrenceSpecification_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<OccurrenceSpecification> element(new OccurrenceSpecificationImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<OccurrenceSpecification> UmlFactoryImpl::createOccurrenceSpecification_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<OccurrenceSpecification> element(new OccurrenceSpecificationImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<OpaqueAction> UmlFactoryImpl::createOpaqueAction() const
{
	std::shared_ptr<OpaqueAction> element(new OpaqueActionImpl());
	return element;
}
std::shared_ptr<OpaqueAction> UmlFactoryImpl::createOpaqueAction_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<OpaqueAction> element(new OpaqueActionImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<OpaqueAction> UmlFactoryImpl::createOpaqueAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<OpaqueAction> element(new OpaqueActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<OpaqueAction> UmlFactoryImpl::createOpaqueAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<OpaqueAction> element(new OpaqueActionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<OpaqueAction> UmlFactoryImpl::createOpaqueAction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<OpaqueAction> element(new OpaqueActionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<OpaqueBehavior> UmlFactoryImpl::createOpaqueBehavior() const
{
	std::shared_ptr<OpaqueBehavior> element(new OpaqueBehaviorImpl());
	return element;
}
std::shared_ptr<OpaqueBehavior> UmlFactoryImpl::createOpaqueBehavior_in_BehavioredClassifier(std::weak_ptr<uml::BehavioredClassifier > par_behavioredClassifier) const
{
	std::shared_ptr<OpaqueBehavior> element(new OpaqueBehaviorImpl(par_behavioredClassifier));
	if(auto wp = par_behavioredClassifier.lock())
	{
    		wp->getOwnedBehavior()->push_back(element);
	}
	return element;
}

std::shared_ptr<OpaqueBehavior> UmlFactoryImpl::createOpaqueBehavior_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<OpaqueBehavior> element(new OpaqueBehaviorImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<OpaqueBehavior> UmlFactoryImpl::createOpaqueBehavior_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<OpaqueBehavior> element(new OpaqueBehaviorImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<OpaqueBehavior> UmlFactoryImpl::createOpaqueBehavior_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<OpaqueBehavior> element(new OpaqueBehaviorImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<OpaqueBehavior> UmlFactoryImpl::createOpaqueBehavior_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<OpaqueBehavior> element(new OpaqueBehaviorImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<OpaqueBehavior> UmlFactoryImpl::createOpaqueBehavior_in_Package(std::weak_ptr<uml::Package > par_package) const
{
	std::shared_ptr<OpaqueBehavior> element(new OpaqueBehaviorImpl(par_package, UmlPackage::TYPE_PACKAGE));
	if(auto wp = par_package.lock())
	{
    		wp->getOwnedType()->push_back(element);
	}
	return element;
}

std::shared_ptr<OpaqueExpression> UmlFactoryImpl::createOpaqueExpression() const
{
	std::shared_ptr<OpaqueExpression> element(new OpaqueExpressionImpl());
	return element;
}
std::shared_ptr<OpaqueExpression> UmlFactoryImpl::createOpaqueExpression_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<OpaqueExpression> element(new OpaqueExpressionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<OpaqueExpression> UmlFactoryImpl::createOpaqueExpression_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<OpaqueExpression> element(new OpaqueExpressionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<OpaqueExpression> UmlFactoryImpl::createOpaqueExpression_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<OpaqueExpression> element(new OpaqueExpressionImpl(par_owningPackage));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<OpaqueExpression> UmlFactoryImpl::createOpaqueExpression_in_OwningSlot(std::weak_ptr<uml::Slot > par_owningSlot) const
{
	std::shared_ptr<OpaqueExpression> element(new OpaqueExpressionImpl(par_owningSlot));
	if(auto wp = par_owningSlot.lock())
	{
    		wp->getValue()->push_back(element);
	}
	return element;
}

std::shared_ptr<OpaqueExpression> UmlFactoryImpl::createOpaqueExpression_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<OpaqueExpression> element(new OpaqueExpressionImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<Operation> UmlFactoryImpl::createOperation() const
{
	std::shared_ptr<Operation> element(new OperationImpl());
	return element;
}
std::shared_ptr<Operation> UmlFactoryImpl::createOperation_in_Class(std::weak_ptr<uml::Class > par_class) const
{
	std::shared_ptr<Operation> element(new OperationImpl(par_class));
	if(auto wp = par_class.lock())
	{
    		wp->getOwnedOperation()->push_back(element);
	}
	return element;
}

std::shared_ptr<Operation> UmlFactoryImpl::createOperation_in_Datatype(std::weak_ptr<uml::DataType > par_datatype) const
{
	std::shared_ptr<Operation> element(new OperationImpl(par_datatype));
	if(auto wp = par_datatype.lock())
	{
    		wp->getOwnedOperation()->push_back(element);
	}
	return element;
}

std::shared_ptr<Operation> UmlFactoryImpl::createOperation_in_Interface(std::weak_ptr<uml::Interface > par_interface) const
{
	std::shared_ptr<Operation> element(new OperationImpl(par_interface));
	if(auto wp = par_interface.lock())
	{
    		wp->getOwnedOperation()->push_back(element);
	}
	return element;
}

std::shared_ptr<Operation> UmlFactoryImpl::createOperation_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Operation> element(new OperationImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Operation> UmlFactoryImpl::createOperation_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Operation> element(new OperationImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Operation> UmlFactoryImpl::createOperation_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Operation> element(new OperationImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<OperationTemplateParameter> UmlFactoryImpl::createOperationTemplateParameter() const
{
	std::shared_ptr<OperationTemplateParameter> element(new OperationTemplateParameterImpl());
	return element;
}
std::shared_ptr<OperationTemplateParameter> UmlFactoryImpl::createOperationTemplateParameter_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<OperationTemplateParameter> element(new OperationTemplateParameterImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<OperationTemplateParameter> UmlFactoryImpl::createOperationTemplateParameter_in_Signature(std::weak_ptr<uml::TemplateSignature > par_signature) const
{
	std::shared_ptr<OperationTemplateParameter> element(new OperationTemplateParameterImpl(par_signature));
	if(auto wp = par_signature.lock())
	{
    		wp->getOwnedParameter()->push_back(element);
	}
	return element;
}

std::shared_ptr<OutputPin> UmlFactoryImpl::createOutputPin() const
{
	std::shared_ptr<OutputPin> element(new OutputPinImpl());
	return element;
}
std::shared_ptr<OutputPin> UmlFactoryImpl::createOutputPin_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<OutputPin> element(new OutputPinImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<OutputPin> UmlFactoryImpl::createOutputPin_in_CallAction(std::weak_ptr<uml::CallAction > par_callAction) const
{
	std::shared_ptr<OutputPin> element(new OutputPinImpl(par_callAction));
	if(auto wp = par_callAction.lock())
	{
    		wp->getResult()->push_back(element);
	}
	return element;
}

std::shared_ptr<OutputPin> UmlFactoryImpl::createOutputPin_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<OutputPin> element(new OutputPinImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<OutputPin> UmlFactoryImpl::createOutputPin_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<OutputPin> element(new OutputPinImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<OutputPin> UmlFactoryImpl::createOutputPin_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<OutputPin> element(new OutputPinImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Package> UmlFactoryImpl::createPackage() const
{
	std::shared_ptr<Package> element(new PackageImpl());
	return element;
}
std::shared_ptr<Package> UmlFactoryImpl::createPackage_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Package> element(new PackageImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Package> UmlFactoryImpl::createPackage_in_NestingPackage(std::weak_ptr<uml::Package > par_nestingPackage) const
{
	std::shared_ptr<Package> element(new PackageImpl(par_nestingPackage, UmlPackage::PACKAGE_NESTINGPACKAGE));
	if(auto wp = par_nestingPackage.lock())
	{
    		wp->getNestedPackage()->push_back(element);
	}
	return element;
}

std::shared_ptr<Package> UmlFactoryImpl::createPackage_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Package> element(new PackageImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Package> UmlFactoryImpl::createPackage_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<Package> element(new PackageImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getNestedPackage()->push_back(element);
	}
	return element;
}

std::shared_ptr<Package> UmlFactoryImpl::createPackage_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Package> element(new PackageImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<PackageImport> UmlFactoryImpl::createPackageImport() const
{
	std::shared_ptr<PackageImport> element(new PackageImportImpl());
	return element;
}
std::shared_ptr<PackageImport> UmlFactoryImpl::createPackageImport_in_ImportingNamespace(std::weak_ptr<uml::Namespace > par_importingNamespace) const
{
	std::shared_ptr<PackageImport> element(new PackageImportImpl(par_importingNamespace));
	if(auto wp = par_importingNamespace.lock())
	{
    		wp->getPackageImport()->push_back(element);
	}
	return element;
}

std::shared_ptr<PackageImport> UmlFactoryImpl::createPackageImport_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<PackageImport> element(new PackageImportImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<PackageMerge> UmlFactoryImpl::createPackageMerge() const
{
	std::shared_ptr<PackageMerge> element(new PackageMergeImpl());
	return element;
}
std::shared_ptr<PackageMerge> UmlFactoryImpl::createPackageMerge_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<PackageMerge> element(new PackageMergeImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<PackageMerge> UmlFactoryImpl::createPackageMerge_in_ReceivingPackage(std::weak_ptr<uml::Package > par_receivingPackage) const
{
	std::shared_ptr<PackageMerge> element(new PackageMergeImpl(par_receivingPackage));
	if(auto wp = par_receivingPackage.lock())
	{
    		wp->getPackageMerge()->push_back(element);
	}
	return element;
}

std::shared_ptr<Parameter> UmlFactoryImpl::createParameter() const
{
	std::shared_ptr<Parameter> element(new ParameterImpl());
	return element;
}
std::shared_ptr<Parameter> UmlFactoryImpl::createParameter_in_Behavior(std::weak_ptr<uml::Behavior > par_behavior) const
{
	std::shared_ptr<Parameter> element(new ParameterImpl(par_behavior));
	if(auto wp = par_behavior.lock())
	{
    		wp->getOwnedParameter()->push_back(element);
	}
	return element;
}

std::shared_ptr<Parameter> UmlFactoryImpl::createParameter_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Parameter> element(new ParameterImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Parameter> UmlFactoryImpl::createParameter_in_Operation(std::weak_ptr<uml::Operation > par_operation) const
{
	std::shared_ptr<Parameter> element(new ParameterImpl(par_operation));
	if(auto wp = par_operation.lock())
	{
    		wp->getOwnedParameter()->push_back(element);
	}
	return element;
}

std::shared_ptr<Parameter> UmlFactoryImpl::createParameter_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Parameter> element(new ParameterImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Parameter> UmlFactoryImpl::createParameter_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Parameter> element(new ParameterImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<ParameterSet> UmlFactoryImpl::createParameterSet() const
{
	std::shared_ptr<ParameterSet> element(new ParameterSetImpl());
	return element;
}
std::shared_ptr<ParameterSet> UmlFactoryImpl::createParameterSet_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ParameterSet> element(new ParameterSetImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<ParameterSet> UmlFactoryImpl::createParameterSet_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ParameterSet> element(new ParameterSetImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<PartDecomposition> UmlFactoryImpl::createPartDecomposition() const
{
	std::shared_ptr<PartDecomposition> element(new PartDecompositionImpl());
	return element;
}
std::shared_ptr<PartDecomposition> UmlFactoryImpl::createPartDecomposition_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction) const
{
	std::shared_ptr<PartDecomposition> element(new PartDecompositionImpl(par_enclosingInteraction));
	if(auto wp = par_enclosingInteraction.lock())
	{
    		wp->getFragment()->push_back(element);
	}
	return element;
}

std::shared_ptr<PartDecomposition> UmlFactoryImpl::createPartDecomposition_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand) const
{
	std::shared_ptr<PartDecomposition> element(new PartDecompositionImpl(par_enclosingOperand));
	if(auto wp = par_enclosingOperand.lock())
	{
    		wp->getFragment()->push_back(element);
	}
	return element;
}

std::shared_ptr<PartDecomposition> UmlFactoryImpl::createPartDecomposition_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<PartDecomposition> element(new PartDecompositionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<PartDecomposition> UmlFactoryImpl::createPartDecomposition_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<PartDecomposition> element(new PartDecompositionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Port> UmlFactoryImpl::createPort() const
{
	std::shared_ptr<Port> element(new PortImpl());
	return element;
}
std::shared_ptr<Port> UmlFactoryImpl::createPort_in_AssociationEnd(std::weak_ptr<uml::Property > par_associationEnd) const
{
	std::shared_ptr<Port> element(new PortImpl(par_associationEnd));
	if(auto wp = par_associationEnd.lock())
	{
    		wp->getQualifier()->push_back(element);
	}
	return element;
}

std::shared_ptr<Port> UmlFactoryImpl::createPort_in_Class(std::weak_ptr<uml::Class > par_class) const
{
	std::shared_ptr<Port> element(new PortImpl(par_class));
	if(auto wp = par_class.lock())
	{
    		wp->getOwnedPort()->push_back(element);
	}
	return element;
}

std::shared_ptr<Port> UmlFactoryImpl::createPort_in_Datatype(std::weak_ptr<uml::DataType > par_datatype) const
{
	std::shared_ptr<Port> element(new PortImpl(par_datatype));
	if(auto wp = par_datatype.lock())
	{
    		wp->getOwnedAttribute()->push_back(element);
	}
	return element;
}

std::shared_ptr<Port> UmlFactoryImpl::createPort_in_Interface(std::weak_ptr<uml::Interface > par_interface) const
{
	std::shared_ptr<Port> element(new PortImpl(par_interface));
	if(auto wp = par_interface.lock())
	{
    		wp->getOwnedAttribute()->push_back(element);
	}
	return element;
}

std::shared_ptr<Port> UmlFactoryImpl::createPort_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Port> element(new PortImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Port> UmlFactoryImpl::createPort_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Port> element(new PortImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Port> UmlFactoryImpl::createPort_in_OwningAssociation(std::weak_ptr<uml::Association > par_owningAssociation) const
{
	std::shared_ptr<Port> element(new PortImpl(par_owningAssociation));
	if(auto wp = par_owningAssociation.lock())
	{
    		wp->getOwnedEnd()->push_back(element);
	}
	return element;
}

std::shared_ptr<Port> UmlFactoryImpl::createPort_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Port> element(new PortImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<PrimitiveType> UmlFactoryImpl::createPrimitiveType() const
{
	std::shared_ptr<PrimitiveType> element(new PrimitiveTypeImpl());
	return element;
}
std::shared_ptr<PrimitiveType> UmlFactoryImpl::createPrimitiveType_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<PrimitiveType> element(new PrimitiveTypeImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<PrimitiveType> UmlFactoryImpl::createPrimitiveType_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<PrimitiveType> element(new PrimitiveTypeImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<PrimitiveType> UmlFactoryImpl::createPrimitiveType_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<PrimitiveType> element(new PrimitiveTypeImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<PrimitiveType> UmlFactoryImpl::createPrimitiveType_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<PrimitiveType> element(new PrimitiveTypeImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<PrimitiveType> UmlFactoryImpl::createPrimitiveType_in_Package(std::weak_ptr<uml::Package > par_package) const
{
	std::shared_ptr<PrimitiveType> element(new PrimitiveTypeImpl(par_package, UmlPackage::TYPE_PACKAGE));
	if(auto wp = par_package.lock())
	{
    		wp->getOwnedType()->push_back(element);
	}
	return element;
}

std::shared_ptr<Profile> UmlFactoryImpl::createProfile() const
{
	std::shared_ptr<Profile> element(new ProfileImpl());
	return element;
}
std::shared_ptr<Profile> UmlFactoryImpl::createProfile_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Profile> element(new ProfileImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Profile> UmlFactoryImpl::createProfile_in_NestingPackage(std::weak_ptr<uml::Package > par_nestingPackage) const
{
	std::shared_ptr<Profile> element(new ProfileImpl(par_nestingPackage, UmlPackage::PACKAGE_NESTINGPACKAGE));
	if(auto wp = par_nestingPackage.lock())
	{
    		wp->getNestedPackage()->push_back(element);
	}
	return element;
}

std::shared_ptr<Profile> UmlFactoryImpl::createProfile_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Profile> element(new ProfileImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Profile> UmlFactoryImpl::createProfile_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<Profile> element(new ProfileImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Profile> UmlFactoryImpl::createProfile_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Profile> element(new ProfileImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<ProfileApplication> UmlFactoryImpl::createProfileApplication() const
{
	std::shared_ptr<ProfileApplication> element(new ProfileApplicationImpl());
	return element;
}
std::shared_ptr<ProfileApplication> UmlFactoryImpl::createProfileApplication_in_ApplyingPackage(std::weak_ptr<uml::Package > par_applyingPackage) const
{
	std::shared_ptr<ProfileApplication> element(new ProfileApplicationImpl(par_applyingPackage));
	if(auto wp = par_applyingPackage.lock())
	{
    		wp->getProfileApplication()->push_back(element);
	}
	return element;
}

std::shared_ptr<ProfileApplication> UmlFactoryImpl::createProfileApplication_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ProfileApplication> element(new ProfileApplicationImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Property> UmlFactoryImpl::createProperty() const
{
	std::shared_ptr<Property> element(new PropertyImpl());
	return element;
}
std::shared_ptr<Property> UmlFactoryImpl::createProperty_in_AssociationEnd(std::weak_ptr<uml::Property > par_associationEnd) const
{
	std::shared_ptr<Property> element(new PropertyImpl(par_associationEnd));
	if(auto wp = par_associationEnd.lock())
	{
    		wp->getQualifier()->push_back(element);
	}
	return element;
}

std::shared_ptr<Property> UmlFactoryImpl::createProperty_in_Class(std::weak_ptr<uml::Class > par_class) const
{
	std::shared_ptr<Property> element(new PropertyImpl(par_class));
	if(auto wp = par_class.lock())
	{
    		wp->getOwnedAttribute()->push_back(element);
	}
	return element;
}

std::shared_ptr<Property> UmlFactoryImpl::createProperty_in_Datatype(std::weak_ptr<uml::DataType > par_datatype) const
{
	std::shared_ptr<Property> element(new PropertyImpl(par_datatype));
	if(auto wp = par_datatype.lock())
	{
    		wp->getOwnedAttribute()->push_back(element);
	}
	return element;
}

std::shared_ptr<Property> UmlFactoryImpl::createProperty_in_Interface(std::weak_ptr<uml::Interface > par_interface) const
{
	std::shared_ptr<Property> element(new PropertyImpl(par_interface));
	if(auto wp = par_interface.lock())
	{
    		wp->getOwnedAttribute()->push_back(element);
	}
	return element;
}

std::shared_ptr<Property> UmlFactoryImpl::createProperty_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Property> element(new PropertyImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Property> UmlFactoryImpl::createProperty_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Property> element(new PropertyImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Property> UmlFactoryImpl::createProperty_in_OwningAssociation(std::weak_ptr<uml::Association > par_owningAssociation) const
{
	std::shared_ptr<Property> element(new PropertyImpl(par_owningAssociation));
	if(auto wp = par_owningAssociation.lock())
	{
    		wp->getNavigableOwnedEnd()->push_back(element);
	}
	return element;
}

std::shared_ptr<Property> UmlFactoryImpl::createProperty_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Property> element(new PropertyImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<ProtocolConformance> UmlFactoryImpl::createProtocolConformance() const
{
	std::shared_ptr<ProtocolConformance> element(new ProtocolConformanceImpl());
	return element;
}
std::shared_ptr<ProtocolConformance> UmlFactoryImpl::createProtocolConformance_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ProtocolConformance> element(new ProtocolConformanceImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ProtocolConformance> UmlFactoryImpl::createProtocolConformance_in_SpecificMachine(std::weak_ptr<uml::ProtocolStateMachine > par_specificMachine) const
{
	std::shared_ptr<ProtocolConformance> element(new ProtocolConformanceImpl(par_specificMachine));
	if(auto wp = par_specificMachine.lock())
	{
    		wp->getConformance()->push_back(element);
	}
	return element;
}

std::shared_ptr<ProtocolStateMachine> UmlFactoryImpl::createProtocolStateMachine() const
{
	std::shared_ptr<ProtocolStateMachine> element(new ProtocolStateMachineImpl());
	return element;
}
std::shared_ptr<ProtocolStateMachine> UmlFactoryImpl::createProtocolStateMachine_in_BehavioredClassifier(std::weak_ptr<uml::BehavioredClassifier > par_behavioredClassifier) const
{
	std::shared_ptr<ProtocolStateMachine> element(new ProtocolStateMachineImpl(par_behavioredClassifier));
	if(auto wp = par_behavioredClassifier.lock())
	{
    		wp->getOwnedBehavior()->push_back(element);
	}
	return element;
}

std::shared_ptr<ProtocolStateMachine> UmlFactoryImpl::createProtocolStateMachine_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ProtocolStateMachine> element(new ProtocolStateMachineImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<ProtocolStateMachine> UmlFactoryImpl::createProtocolStateMachine_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ProtocolStateMachine> element(new ProtocolStateMachineImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ProtocolStateMachine> UmlFactoryImpl::createProtocolStateMachine_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<ProtocolStateMachine> element(new ProtocolStateMachineImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ProtocolStateMachine> UmlFactoryImpl::createProtocolStateMachine_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<ProtocolStateMachine> element(new ProtocolStateMachineImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<ProtocolStateMachine> UmlFactoryImpl::createProtocolStateMachine_in_Package(std::weak_ptr<uml::Package > par_package) const
{
	std::shared_ptr<ProtocolStateMachine> element(new ProtocolStateMachineImpl(par_package, UmlPackage::TYPE_PACKAGE));
	if(auto wp = par_package.lock())
	{
    		wp->getOwnedType()->push_back(element);
	}
	return element;
}

std::shared_ptr<ProtocolTransition> UmlFactoryImpl::createProtocolTransition() const
{
	std::shared_ptr<ProtocolTransition> element(new ProtocolTransitionImpl());
	return element;
}
std::shared_ptr<ProtocolTransition> UmlFactoryImpl::createProtocolTransition_in_Container(std::weak_ptr<uml::Region > par_container) const
{
	std::shared_ptr<ProtocolTransition> element(new ProtocolTransitionImpl(par_container));
	if(auto wp = par_container.lock())
	{
    		wp->getTransition()->push_back(element);
	}
	return element;
}

std::shared_ptr<ProtocolTransition> UmlFactoryImpl::createProtocolTransition_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ProtocolTransition> element(new ProtocolTransitionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<ProtocolTransition> UmlFactoryImpl::createProtocolTransition_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ProtocolTransition> element(new ProtocolTransitionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Pseudostate> UmlFactoryImpl::createPseudostate() const
{
	std::shared_ptr<Pseudostate> element(new PseudostateImpl());
	return element;
}
std::shared_ptr<Pseudostate> UmlFactoryImpl::createPseudostate_in_Container(std::weak_ptr<uml::Region > par_container) const
{
	std::shared_ptr<Pseudostate> element(new PseudostateImpl(par_container));
	if(auto wp = par_container.lock())
	{
    		wp->getSubvertex()->push_back(element);
	}
	return element;
}

std::shared_ptr<Pseudostate> UmlFactoryImpl::createPseudostate_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Pseudostate> element(new PseudostateImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Pseudostate> UmlFactoryImpl::createPseudostate_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Pseudostate> element(new PseudostateImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Pseudostate> UmlFactoryImpl::createPseudostate_in_State(std::weak_ptr<uml::State > par_state) const
{
	std::shared_ptr<Pseudostate> element(new PseudostateImpl(par_state));
	if(auto wp = par_state.lock())
	{
    		wp->getConnectionPoint()->push_back(element);
	}
	return element;
}

std::shared_ptr<Pseudostate> UmlFactoryImpl::createPseudostate_in_StateMachine(std::weak_ptr<uml::StateMachine > par_stateMachine) const
{
	std::shared_ptr<Pseudostate> element(new PseudostateImpl(par_stateMachine));
	if(auto wp = par_stateMachine.lock())
	{
    		wp->getConnectionPoint()->push_back(element);
	}
	return element;
}

std::shared_ptr<QualifierValue> UmlFactoryImpl::createQualifierValue() const
{
	std::shared_ptr<QualifierValue> element(new QualifierValueImpl());
	return element;
}
std::shared_ptr<QualifierValue> UmlFactoryImpl::createQualifierValue_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<QualifierValue> element(new QualifierValueImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<RaiseExceptionAction> UmlFactoryImpl::createRaiseExceptionAction() const
{
	std::shared_ptr<RaiseExceptionAction> element(new RaiseExceptionActionImpl());
	return element;
}
std::shared_ptr<RaiseExceptionAction> UmlFactoryImpl::createRaiseExceptionAction_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<RaiseExceptionAction> element(new RaiseExceptionActionImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<RaiseExceptionAction> UmlFactoryImpl::createRaiseExceptionAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<RaiseExceptionAction> element(new RaiseExceptionActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<RaiseExceptionAction> UmlFactoryImpl::createRaiseExceptionAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<RaiseExceptionAction> element(new RaiseExceptionActionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<RaiseExceptionAction> UmlFactoryImpl::createRaiseExceptionAction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<RaiseExceptionAction> element(new RaiseExceptionActionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReadExtentAction> UmlFactoryImpl::createReadExtentAction() const
{
	std::shared_ptr<ReadExtentAction> element(new ReadExtentActionImpl());
	return element;
}
std::shared_ptr<ReadExtentAction> UmlFactoryImpl::createReadExtentAction_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ReadExtentAction> element(new ReadExtentActionImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReadExtentAction> UmlFactoryImpl::createReadExtentAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ReadExtentAction> element(new ReadExtentActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReadExtentAction> UmlFactoryImpl::createReadExtentAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ReadExtentAction> element(new ReadExtentActionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReadExtentAction> UmlFactoryImpl::createReadExtentAction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ReadExtentAction> element(new ReadExtentActionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReadIsClassifiedObjectAction> UmlFactoryImpl::createReadIsClassifiedObjectAction() const
{
	std::shared_ptr<ReadIsClassifiedObjectAction> element(new ReadIsClassifiedObjectActionImpl());
	return element;
}
std::shared_ptr<ReadIsClassifiedObjectAction> UmlFactoryImpl::createReadIsClassifiedObjectAction_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ReadIsClassifiedObjectAction> element(new ReadIsClassifiedObjectActionImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReadIsClassifiedObjectAction> UmlFactoryImpl::createReadIsClassifiedObjectAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ReadIsClassifiedObjectAction> element(new ReadIsClassifiedObjectActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReadIsClassifiedObjectAction> UmlFactoryImpl::createReadIsClassifiedObjectAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ReadIsClassifiedObjectAction> element(new ReadIsClassifiedObjectActionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReadIsClassifiedObjectAction> UmlFactoryImpl::createReadIsClassifiedObjectAction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ReadIsClassifiedObjectAction> element(new ReadIsClassifiedObjectActionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReadLinkAction> UmlFactoryImpl::createReadLinkAction() const
{
	std::shared_ptr<ReadLinkAction> element(new ReadLinkActionImpl());
	return element;
}
std::shared_ptr<ReadLinkAction> UmlFactoryImpl::createReadLinkAction_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ReadLinkAction> element(new ReadLinkActionImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReadLinkAction> UmlFactoryImpl::createReadLinkAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ReadLinkAction> element(new ReadLinkActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReadLinkAction> UmlFactoryImpl::createReadLinkAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ReadLinkAction> element(new ReadLinkActionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReadLinkAction> UmlFactoryImpl::createReadLinkAction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ReadLinkAction> element(new ReadLinkActionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReadLinkObjectEndAction> UmlFactoryImpl::createReadLinkObjectEndAction() const
{
	std::shared_ptr<ReadLinkObjectEndAction> element(new ReadLinkObjectEndActionImpl());
	return element;
}
std::shared_ptr<ReadLinkObjectEndAction> UmlFactoryImpl::createReadLinkObjectEndAction_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ReadLinkObjectEndAction> element(new ReadLinkObjectEndActionImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReadLinkObjectEndAction> UmlFactoryImpl::createReadLinkObjectEndAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ReadLinkObjectEndAction> element(new ReadLinkObjectEndActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReadLinkObjectEndAction> UmlFactoryImpl::createReadLinkObjectEndAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ReadLinkObjectEndAction> element(new ReadLinkObjectEndActionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReadLinkObjectEndAction> UmlFactoryImpl::createReadLinkObjectEndAction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ReadLinkObjectEndAction> element(new ReadLinkObjectEndActionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReadLinkObjectEndQualifierAction> UmlFactoryImpl::createReadLinkObjectEndQualifierAction() const
{
	std::shared_ptr<ReadLinkObjectEndQualifierAction> element(new ReadLinkObjectEndQualifierActionImpl());
	return element;
}
std::shared_ptr<ReadLinkObjectEndQualifierAction> UmlFactoryImpl::createReadLinkObjectEndQualifierAction_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ReadLinkObjectEndQualifierAction> element(new ReadLinkObjectEndQualifierActionImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReadLinkObjectEndQualifierAction> UmlFactoryImpl::createReadLinkObjectEndQualifierAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ReadLinkObjectEndQualifierAction> element(new ReadLinkObjectEndQualifierActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReadLinkObjectEndQualifierAction> UmlFactoryImpl::createReadLinkObjectEndQualifierAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ReadLinkObjectEndQualifierAction> element(new ReadLinkObjectEndQualifierActionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReadLinkObjectEndQualifierAction> UmlFactoryImpl::createReadLinkObjectEndQualifierAction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ReadLinkObjectEndQualifierAction> element(new ReadLinkObjectEndQualifierActionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReadSelfAction> UmlFactoryImpl::createReadSelfAction() const
{
	std::shared_ptr<ReadSelfAction> element(new ReadSelfActionImpl());
	return element;
}
std::shared_ptr<ReadSelfAction> UmlFactoryImpl::createReadSelfAction_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ReadSelfAction> element(new ReadSelfActionImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReadSelfAction> UmlFactoryImpl::createReadSelfAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ReadSelfAction> element(new ReadSelfActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReadSelfAction> UmlFactoryImpl::createReadSelfAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ReadSelfAction> element(new ReadSelfActionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReadSelfAction> UmlFactoryImpl::createReadSelfAction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ReadSelfAction> element(new ReadSelfActionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReadStructuralFeatureAction> UmlFactoryImpl::createReadStructuralFeatureAction() const
{
	std::shared_ptr<ReadStructuralFeatureAction> element(new ReadStructuralFeatureActionImpl());
	return element;
}
std::shared_ptr<ReadStructuralFeatureAction> UmlFactoryImpl::createReadStructuralFeatureAction_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ReadStructuralFeatureAction> element(new ReadStructuralFeatureActionImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReadStructuralFeatureAction> UmlFactoryImpl::createReadStructuralFeatureAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ReadStructuralFeatureAction> element(new ReadStructuralFeatureActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReadStructuralFeatureAction> UmlFactoryImpl::createReadStructuralFeatureAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ReadStructuralFeatureAction> element(new ReadStructuralFeatureActionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReadStructuralFeatureAction> UmlFactoryImpl::createReadStructuralFeatureAction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ReadStructuralFeatureAction> element(new ReadStructuralFeatureActionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReadVariableAction> UmlFactoryImpl::createReadVariableAction() const
{
	std::shared_ptr<ReadVariableAction> element(new ReadVariableActionImpl());
	return element;
}
std::shared_ptr<ReadVariableAction> UmlFactoryImpl::createReadVariableAction_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ReadVariableAction> element(new ReadVariableActionImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReadVariableAction> UmlFactoryImpl::createReadVariableAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ReadVariableAction> element(new ReadVariableActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReadVariableAction> UmlFactoryImpl::createReadVariableAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ReadVariableAction> element(new ReadVariableActionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReadVariableAction> UmlFactoryImpl::createReadVariableAction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ReadVariableAction> element(new ReadVariableActionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Realization> UmlFactoryImpl::createRealization() const
{
	std::shared_ptr<Realization> element(new RealizationImpl());
	return element;
}
std::shared_ptr<Realization> UmlFactoryImpl::createRealization_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Realization> element(new RealizationImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Realization> UmlFactoryImpl::createRealization_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Realization> element(new RealizationImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Realization> UmlFactoryImpl::createRealization_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<Realization> element(new RealizationImpl(par_owningPackage));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Realization> UmlFactoryImpl::createRealization_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Realization> element(new RealizationImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<Reception> UmlFactoryImpl::createReception() const
{
	std::shared_ptr<Reception> element(new ReceptionImpl());
	return element;
}
std::shared_ptr<Reception> UmlFactoryImpl::createReception_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Reception> element(new ReceptionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Reception> UmlFactoryImpl::createReception_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Reception> element(new ReceptionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReclassifyObjectAction> UmlFactoryImpl::createReclassifyObjectAction() const
{
	std::shared_ptr<ReclassifyObjectAction> element(new ReclassifyObjectActionImpl());
	return element;
}
std::shared_ptr<ReclassifyObjectAction> UmlFactoryImpl::createReclassifyObjectAction_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ReclassifyObjectAction> element(new ReclassifyObjectActionImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReclassifyObjectAction> UmlFactoryImpl::createReclassifyObjectAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ReclassifyObjectAction> element(new ReclassifyObjectActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReclassifyObjectAction> UmlFactoryImpl::createReclassifyObjectAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ReclassifyObjectAction> element(new ReclassifyObjectActionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReclassifyObjectAction> UmlFactoryImpl::createReclassifyObjectAction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ReclassifyObjectAction> element(new ReclassifyObjectActionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<RedefinableTemplateSignature> UmlFactoryImpl::createRedefinableTemplateSignature() const
{
	std::shared_ptr<RedefinableTemplateSignature> element(new RedefinableTemplateSignatureImpl());
	return element;
}
std::shared_ptr<RedefinableTemplateSignature> UmlFactoryImpl::createRedefinableTemplateSignature_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<RedefinableTemplateSignature> element(new RedefinableTemplateSignatureImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<RedefinableTemplateSignature> UmlFactoryImpl::createRedefinableTemplateSignature_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<RedefinableTemplateSignature> element(new RedefinableTemplateSignatureImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<RedefinableTemplateSignature> UmlFactoryImpl::createRedefinableTemplateSignature_in_Template(std::weak_ptr<uml::TemplateableElement > par_template) const
{
	std::shared_ptr<RedefinableTemplateSignature> element(new RedefinableTemplateSignatureImpl(par_template));
	if(auto wp = par_template.lock())
	{
			wp->setOwnedTemplateSignature(element);
	}
	return element;
}

std::shared_ptr<ReduceAction> UmlFactoryImpl::createReduceAction() const
{
	std::shared_ptr<ReduceAction> element(new ReduceActionImpl());
	return element;
}
std::shared_ptr<ReduceAction> UmlFactoryImpl::createReduceAction_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ReduceAction> element(new ReduceActionImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReduceAction> UmlFactoryImpl::createReduceAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ReduceAction> element(new ReduceActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReduceAction> UmlFactoryImpl::createReduceAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ReduceAction> element(new ReduceActionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReduceAction> UmlFactoryImpl::createReduceAction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ReduceAction> element(new ReduceActionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Region> UmlFactoryImpl::createRegion() const
{
	std::shared_ptr<Region> element(new RegionImpl());
	return element;
}
std::shared_ptr<Region> UmlFactoryImpl::createRegion_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Region> element(new RegionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Region> UmlFactoryImpl::createRegion_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Region> element(new RegionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Region> UmlFactoryImpl::createRegion_in_State(std::weak_ptr<uml::State > par_state) const
{
	std::shared_ptr<Region> element(new RegionImpl(par_state));
	if(auto wp = par_state.lock())
	{
    		wp->getRegion()->push_back(element);
	}
	return element;
}

std::shared_ptr<Region> UmlFactoryImpl::createRegion_in_StateMachine(std::weak_ptr<uml::StateMachine > par_stateMachine) const
{
	std::shared_ptr<Region> element(new RegionImpl(par_stateMachine));
	if(auto wp = par_stateMachine.lock())
	{
    		wp->getRegion()->push_back(element);
	}
	return element;
}

std::shared_ptr<RemoveStructuralFeatureValueAction> UmlFactoryImpl::createRemoveStructuralFeatureValueAction() const
{
	std::shared_ptr<RemoveStructuralFeatureValueAction> element(new RemoveStructuralFeatureValueActionImpl());
	return element;
}
std::shared_ptr<RemoveStructuralFeatureValueAction> UmlFactoryImpl::createRemoveStructuralFeatureValueAction_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<RemoveStructuralFeatureValueAction> element(new RemoveStructuralFeatureValueActionImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<RemoveStructuralFeatureValueAction> UmlFactoryImpl::createRemoveStructuralFeatureValueAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<RemoveStructuralFeatureValueAction> element(new RemoveStructuralFeatureValueActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<RemoveStructuralFeatureValueAction> UmlFactoryImpl::createRemoveStructuralFeatureValueAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<RemoveStructuralFeatureValueAction> element(new RemoveStructuralFeatureValueActionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<RemoveStructuralFeatureValueAction> UmlFactoryImpl::createRemoveStructuralFeatureValueAction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<RemoveStructuralFeatureValueAction> element(new RemoveStructuralFeatureValueActionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<RemoveVariableValueAction> UmlFactoryImpl::createRemoveVariableValueAction() const
{
	std::shared_ptr<RemoveVariableValueAction> element(new RemoveVariableValueActionImpl());
	return element;
}
std::shared_ptr<RemoveVariableValueAction> UmlFactoryImpl::createRemoveVariableValueAction_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<RemoveVariableValueAction> element(new RemoveVariableValueActionImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<RemoveVariableValueAction> UmlFactoryImpl::createRemoveVariableValueAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<RemoveVariableValueAction> element(new RemoveVariableValueActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<RemoveVariableValueAction> UmlFactoryImpl::createRemoveVariableValueAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<RemoveVariableValueAction> element(new RemoveVariableValueActionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<RemoveVariableValueAction> UmlFactoryImpl::createRemoveVariableValueAction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<RemoveVariableValueAction> element(new RemoveVariableValueActionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReplyAction> UmlFactoryImpl::createReplyAction() const
{
	std::shared_ptr<ReplyAction> element(new ReplyActionImpl());
	return element;
}
std::shared_ptr<ReplyAction> UmlFactoryImpl::createReplyAction_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ReplyAction> element(new ReplyActionImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReplyAction> UmlFactoryImpl::createReplyAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ReplyAction> element(new ReplyActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReplyAction> UmlFactoryImpl::createReplyAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ReplyAction> element(new ReplyActionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<ReplyAction> UmlFactoryImpl::createReplyAction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ReplyAction> element(new ReplyActionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<SendObjectAction> UmlFactoryImpl::createSendObjectAction() const
{
	std::shared_ptr<SendObjectAction> element(new SendObjectActionImpl());
	return element;
}
std::shared_ptr<SendObjectAction> UmlFactoryImpl::createSendObjectAction_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<SendObjectAction> element(new SendObjectActionImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<SendObjectAction> UmlFactoryImpl::createSendObjectAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<SendObjectAction> element(new SendObjectActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<SendObjectAction> UmlFactoryImpl::createSendObjectAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<SendObjectAction> element(new SendObjectActionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<SendObjectAction> UmlFactoryImpl::createSendObjectAction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<SendObjectAction> element(new SendObjectActionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<SendSignalAction> UmlFactoryImpl::createSendSignalAction() const
{
	std::shared_ptr<SendSignalAction> element(new SendSignalActionImpl());
	return element;
}
std::shared_ptr<SendSignalAction> UmlFactoryImpl::createSendSignalAction_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<SendSignalAction> element(new SendSignalActionImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<SendSignalAction> UmlFactoryImpl::createSendSignalAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<SendSignalAction> element(new SendSignalActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<SendSignalAction> UmlFactoryImpl::createSendSignalAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<SendSignalAction> element(new SendSignalActionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<SendSignalAction> UmlFactoryImpl::createSendSignalAction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<SendSignalAction> element(new SendSignalActionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<SequenceNode> UmlFactoryImpl::createSequenceNode() const
{
	std::shared_ptr<SequenceNode> element(new SequenceNodeImpl());
	return element;
}
std::shared_ptr<SequenceNode> UmlFactoryImpl::createSequenceNode_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<SequenceNode> element(new SequenceNodeImpl(par_activity, UmlPackage::ACTIVITYNODE_ACTIVITY));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<SequenceNode> UmlFactoryImpl::createSequenceNode_in_InActivity(std::weak_ptr<uml::Activity > par_inActivity) const
{
	std::shared_ptr<SequenceNode> element(new SequenceNodeImpl(par_inActivity, UmlPackage::ACTIVITYGROUP_INACTIVITY));
	if(auto wp = par_inActivity.lock())
	{
    		wp->getGroup()->push_back(element);
	}
	return element;
}

std::shared_ptr<SequenceNode> UmlFactoryImpl::createSequenceNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<SequenceNode> element(new SequenceNodeImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<SequenceNode> UmlFactoryImpl::createSequenceNode_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<SequenceNode> element(new SequenceNodeImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<SequenceNode> UmlFactoryImpl::createSequenceNode_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<SequenceNode> element(new SequenceNodeImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<SequenceNode> UmlFactoryImpl::createSequenceNode_in_SuperGroup(std::weak_ptr<uml::ActivityGroup > par_superGroup) const
{
	std::shared_ptr<SequenceNode> element(new SequenceNodeImpl(par_superGroup));
	if(auto wp = par_superGroup.lock())
	{
    		wp->getSubgroup()->push_back(element);
	}
	return element;
}

std::shared_ptr<Signal> UmlFactoryImpl::createSignal() const
{
	std::shared_ptr<Signal> element(new SignalImpl());
	return element;
}
std::shared_ptr<Signal> UmlFactoryImpl::createSignal_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Signal> element(new SignalImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Signal> UmlFactoryImpl::createSignal_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Signal> element(new SignalImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Signal> UmlFactoryImpl::createSignal_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<Signal> element(new SignalImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Signal> UmlFactoryImpl::createSignal_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Signal> element(new SignalImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<Signal> UmlFactoryImpl::createSignal_in_Package(std::weak_ptr<uml::Package > par_package) const
{
	std::shared_ptr<Signal> element(new SignalImpl(par_package, UmlPackage::TYPE_PACKAGE));
	if(auto wp = par_package.lock())
	{
    		wp->getOwnedType()->push_back(element);
	}
	return element;
}

std::shared_ptr<SignalEvent> UmlFactoryImpl::createSignalEvent() const
{
	std::shared_ptr<SignalEvent> element(new SignalEventImpl());
	return element;
}
std::shared_ptr<SignalEvent> UmlFactoryImpl::createSignalEvent_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<SignalEvent> element(new SignalEventImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<SignalEvent> UmlFactoryImpl::createSignalEvent_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<SignalEvent> element(new SignalEventImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<SignalEvent> UmlFactoryImpl::createSignalEvent_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<SignalEvent> element(new SignalEventImpl(par_owningPackage));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<SignalEvent> UmlFactoryImpl::createSignalEvent_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<SignalEvent> element(new SignalEventImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<Slot> UmlFactoryImpl::createSlot() const
{
	std::shared_ptr<Slot> element(new SlotImpl());
	return element;
}
std::shared_ptr<Slot> UmlFactoryImpl::createSlot_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Slot> element(new SlotImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Slot> UmlFactoryImpl::createSlot_in_OwningInstance(std::weak_ptr<uml::InstanceSpecification > par_owningInstance) const
{
	std::shared_ptr<Slot> element(new SlotImpl(par_owningInstance));
	if(auto wp = par_owningInstance.lock())
	{
    		wp->getSlot()->push_back(element);
	}
	return element;
}

std::shared_ptr<StartClassifierBehaviorAction> UmlFactoryImpl::createStartClassifierBehaviorAction() const
{
	std::shared_ptr<StartClassifierBehaviorAction> element(new StartClassifierBehaviorActionImpl());
	return element;
}
std::shared_ptr<StartClassifierBehaviorAction> UmlFactoryImpl::createStartClassifierBehaviorAction_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<StartClassifierBehaviorAction> element(new StartClassifierBehaviorActionImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<StartClassifierBehaviorAction> UmlFactoryImpl::createStartClassifierBehaviorAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<StartClassifierBehaviorAction> element(new StartClassifierBehaviorActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<StartClassifierBehaviorAction> UmlFactoryImpl::createStartClassifierBehaviorAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<StartClassifierBehaviorAction> element(new StartClassifierBehaviorActionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<StartClassifierBehaviorAction> UmlFactoryImpl::createStartClassifierBehaviorAction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<StartClassifierBehaviorAction> element(new StartClassifierBehaviorActionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<StartObjectBehaviorAction> UmlFactoryImpl::createStartObjectBehaviorAction() const
{
	std::shared_ptr<StartObjectBehaviorAction> element(new StartObjectBehaviorActionImpl());
	return element;
}
std::shared_ptr<StartObjectBehaviorAction> UmlFactoryImpl::createStartObjectBehaviorAction_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<StartObjectBehaviorAction> element(new StartObjectBehaviorActionImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<StartObjectBehaviorAction> UmlFactoryImpl::createStartObjectBehaviorAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<StartObjectBehaviorAction> element(new StartObjectBehaviorActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<StartObjectBehaviorAction> UmlFactoryImpl::createStartObjectBehaviorAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<StartObjectBehaviorAction> element(new StartObjectBehaviorActionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<StartObjectBehaviorAction> UmlFactoryImpl::createStartObjectBehaviorAction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<StartObjectBehaviorAction> element(new StartObjectBehaviorActionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<State> UmlFactoryImpl::createState() const
{
	std::shared_ptr<State> element(new StateImpl());
	return element;
}
std::shared_ptr<State> UmlFactoryImpl::createState_in_Container(std::weak_ptr<uml::Region > par_container) const
{
	std::shared_ptr<State> element(new StateImpl(par_container));
	if(auto wp = par_container.lock())
	{
    		wp->getSubvertex()->push_back(element);
	}
	return element;
}

std::shared_ptr<State> UmlFactoryImpl::createState_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<State> element(new StateImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<State> UmlFactoryImpl::createState_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<State> element(new StateImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<StateInvariant> UmlFactoryImpl::createStateInvariant() const
{
	std::shared_ptr<StateInvariant> element(new StateInvariantImpl());
	return element;
}
std::shared_ptr<StateInvariant> UmlFactoryImpl::createStateInvariant_in_EnclosingInteraction(std::weak_ptr<uml::Interaction > par_enclosingInteraction) const
{
	std::shared_ptr<StateInvariant> element(new StateInvariantImpl(par_enclosingInteraction));
	if(auto wp = par_enclosingInteraction.lock())
	{
    		wp->getFragment()->push_back(element);
	}
	return element;
}

std::shared_ptr<StateInvariant> UmlFactoryImpl::createStateInvariant_in_EnclosingOperand(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand) const
{
	std::shared_ptr<StateInvariant> element(new StateInvariantImpl(par_enclosingOperand));
	if(auto wp = par_enclosingOperand.lock())
	{
    		wp->getFragment()->push_back(element);
	}
	return element;
}

std::shared_ptr<StateInvariant> UmlFactoryImpl::createStateInvariant_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<StateInvariant> element(new StateInvariantImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<StateInvariant> UmlFactoryImpl::createStateInvariant_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<StateInvariant> element(new StateInvariantImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<StateMachine> UmlFactoryImpl::createStateMachine() const
{
	std::shared_ptr<StateMachine> element(new StateMachineImpl());
	return element;
}
std::shared_ptr<StateMachine> UmlFactoryImpl::createStateMachine_in_BehavioredClassifier(std::weak_ptr<uml::BehavioredClassifier > par_behavioredClassifier) const
{
	std::shared_ptr<StateMachine> element(new StateMachineImpl(par_behavioredClassifier));
	if(auto wp = par_behavioredClassifier.lock())
	{
    		wp->getOwnedBehavior()->push_back(element);
	}
	return element;
}

std::shared_ptr<StateMachine> UmlFactoryImpl::createStateMachine_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<StateMachine> element(new StateMachineImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<StateMachine> UmlFactoryImpl::createStateMachine_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<StateMachine> element(new StateMachineImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<StateMachine> UmlFactoryImpl::createStateMachine_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<StateMachine> element(new StateMachineImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<StateMachine> UmlFactoryImpl::createStateMachine_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<StateMachine> element(new StateMachineImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<StateMachine> UmlFactoryImpl::createStateMachine_in_Package(std::weak_ptr<uml::Package > par_package) const
{
	std::shared_ptr<StateMachine> element(new StateMachineImpl(par_package, UmlPackage::TYPE_PACKAGE));
	if(auto wp = par_package.lock())
	{
    		wp->getOwnedType()->push_back(element);
	}
	return element;
}

std::shared_ptr<Stereotype> UmlFactoryImpl::createStereotype() const
{
	std::shared_ptr<Stereotype> element(new StereotypeImpl());
	return element;
}
std::shared_ptr<Stereotype> UmlFactoryImpl::createStereotype_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Stereotype> element(new StereotypeImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Stereotype> UmlFactoryImpl::createStereotype_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Stereotype> element(new StereotypeImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Stereotype> UmlFactoryImpl::createStereotype_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<Stereotype> element(new StereotypeImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getOwnedStereotype()->push_back(element);
	}
	return element;
}

std::shared_ptr<Stereotype> UmlFactoryImpl::createStereotype_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Stereotype> element(new StereotypeImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<Stereotype> UmlFactoryImpl::createStereotype_in_Package(std::weak_ptr<uml::Package > par_package) const
{
	std::shared_ptr<Stereotype> element(new StereotypeImpl(par_package, UmlPackage::TYPE_PACKAGE));
	if(auto wp = par_package.lock())
	{
    		wp->getOwnedType()->push_back(element);
	}
	return element;
}

std::shared_ptr<StringExpression> UmlFactoryImpl::createStringExpression() const
{
	std::shared_ptr<StringExpression> element(new StringExpressionImpl());
	return element;
}
std::shared_ptr<StringExpression> UmlFactoryImpl::createStringExpression_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<StringExpression> element(new StringExpressionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<StringExpression> UmlFactoryImpl::createStringExpression_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<StringExpression> element(new StringExpressionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<StringExpression> UmlFactoryImpl::createStringExpression_in_OwningExpression(std::weak_ptr<uml::StringExpression > par_owningExpression) const
{
	std::shared_ptr<StringExpression> element(new StringExpressionImpl(par_owningExpression));
	if(auto wp = par_owningExpression.lock())
	{
    		wp->getSubExpression()->push_back(element);
	}
	return element;
}

std::shared_ptr<StringExpression> UmlFactoryImpl::createStringExpression_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<StringExpression> element(new StringExpressionImpl(par_owningPackage));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<StringExpression> UmlFactoryImpl::createStringExpression_in_OwningSlot(std::weak_ptr<uml::Slot > par_owningSlot) const
{
	std::shared_ptr<StringExpression> element(new StringExpressionImpl(par_owningSlot));
	if(auto wp = par_owningSlot.lock())
	{
    		wp->getValue()->push_back(element);
	}
	return element;
}

std::shared_ptr<StringExpression> UmlFactoryImpl::createStringExpression_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<StringExpression> element(new StringExpressionImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<StructuredActivityNode> UmlFactoryImpl::createStructuredActivityNode() const
{
	std::shared_ptr<StructuredActivityNode> element(new StructuredActivityNodeImpl());
	return element;
}
std::shared_ptr<StructuredActivityNode> UmlFactoryImpl::createStructuredActivityNode_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<StructuredActivityNode> element(new StructuredActivityNodeImpl(par_activity, UmlPackage::ACTIVITYNODE_ACTIVITY));
	if(auto wp = par_activity.lock())
	{
    		wp->getStructuredNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<StructuredActivityNode> UmlFactoryImpl::createStructuredActivityNode_in_InActivity(std::weak_ptr<uml::Activity > par_inActivity) const
{
	std::shared_ptr<StructuredActivityNode> element(new StructuredActivityNodeImpl(par_inActivity, UmlPackage::ACTIVITYGROUP_INACTIVITY));
	if(auto wp = par_inActivity.lock())
	{
    		wp->getStructuredNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<StructuredActivityNode> UmlFactoryImpl::createStructuredActivityNode_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<StructuredActivityNode> element(new StructuredActivityNodeImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<StructuredActivityNode> UmlFactoryImpl::createStructuredActivityNode_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<StructuredActivityNode> element(new StructuredActivityNodeImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<StructuredActivityNode> UmlFactoryImpl::createStructuredActivityNode_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<StructuredActivityNode> element(new StructuredActivityNodeImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<StructuredActivityNode> UmlFactoryImpl::createStructuredActivityNode_in_SuperGroup(std::weak_ptr<uml::ActivityGroup > par_superGroup) const
{
	std::shared_ptr<StructuredActivityNode> element(new StructuredActivityNodeImpl(par_superGroup));
	if(auto wp = par_superGroup.lock())
	{
    		wp->getSubgroup()->push_back(element);
	}
	return element;
}

std::shared_ptr<Substitution> UmlFactoryImpl::createSubstitution() const
{
	std::shared_ptr<Substitution> element(new SubstitutionImpl());
	return element;
}
std::shared_ptr<Substitution> UmlFactoryImpl::createSubstitution_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Substitution> element(new SubstitutionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Substitution> UmlFactoryImpl::createSubstitution_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Substitution> element(new SubstitutionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Substitution> UmlFactoryImpl::createSubstitution_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<Substitution> element(new SubstitutionImpl(par_owningPackage));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Substitution> UmlFactoryImpl::createSubstitution_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Substitution> element(new SubstitutionImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<Substitution> UmlFactoryImpl::createSubstitution_in_SubstitutingClassifier(std::weak_ptr<uml::Classifier > par_substitutingClassifier) const
{
	std::shared_ptr<Substitution> element(new SubstitutionImpl(par_substitutingClassifier));
	if(auto wp = par_substitutingClassifier.lock())
	{
    		wp->getSubstitution()->push_back(element);
	}
	return element;
}

std::shared_ptr<TemplateBinding> UmlFactoryImpl::createTemplateBinding() const
{
	std::shared_ptr<TemplateBinding> element(new TemplateBindingImpl());
	return element;
}
std::shared_ptr<TemplateBinding> UmlFactoryImpl::createTemplateBinding_in_BoundElement(std::weak_ptr<uml::TemplateableElement > par_boundElement) const
{
	std::shared_ptr<TemplateBinding> element(new TemplateBindingImpl(par_boundElement));
	if(auto wp = par_boundElement.lock())
	{
    		wp->getTemplateBinding()->push_back(element);
	}
	return element;
}

std::shared_ptr<TemplateBinding> UmlFactoryImpl::createTemplateBinding_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<TemplateBinding> element(new TemplateBindingImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<TemplateParameter> UmlFactoryImpl::createTemplateParameter() const
{
	std::shared_ptr<TemplateParameter> element(new TemplateParameterImpl());
	return element;
}
std::shared_ptr<TemplateParameter> UmlFactoryImpl::createTemplateParameter_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<TemplateParameter> element(new TemplateParameterImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<TemplateParameter> UmlFactoryImpl::createTemplateParameter_in_Signature(std::weak_ptr<uml::TemplateSignature > par_signature) const
{
	std::shared_ptr<TemplateParameter> element(new TemplateParameterImpl(par_signature));
	if(auto wp = par_signature.lock())
	{
    		wp->getOwnedParameter()->push_back(element);
	}
	return element;
}

std::shared_ptr<TemplateParameterSubstitution> UmlFactoryImpl::createTemplateParameterSubstitution() const
{
	std::shared_ptr<TemplateParameterSubstitution> element(new TemplateParameterSubstitutionImpl());
	return element;
}
std::shared_ptr<TemplateParameterSubstitution> UmlFactoryImpl::createTemplateParameterSubstitution_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<TemplateParameterSubstitution> element(new TemplateParameterSubstitutionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<TemplateParameterSubstitution> UmlFactoryImpl::createTemplateParameterSubstitution_in_TemplateBinding(std::weak_ptr<uml::TemplateBinding > par_templateBinding) const
{
	std::shared_ptr<TemplateParameterSubstitution> element(new TemplateParameterSubstitutionImpl(par_templateBinding));
	if(auto wp = par_templateBinding.lock())
	{
    		wp->getParameterSubstitution()->push_back(element);
	}
	return element;
}

std::shared_ptr<TemplateSignature> UmlFactoryImpl::createTemplateSignature() const
{
	std::shared_ptr<TemplateSignature> element(new TemplateSignatureImpl());
	return element;
}
std::shared_ptr<TemplateSignature> UmlFactoryImpl::createTemplateSignature_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<TemplateSignature> element(new TemplateSignatureImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<TemplateSignature> UmlFactoryImpl::createTemplateSignature_in_Template(std::weak_ptr<uml::TemplateableElement > par_template) const
{
	std::shared_ptr<TemplateSignature> element(new TemplateSignatureImpl(par_template));
	if(auto wp = par_template.lock())
	{
			wp->setOwnedTemplateSignature(element);
	}
	return element;
}

std::shared_ptr<TestIdentityAction> UmlFactoryImpl::createTestIdentityAction() const
{
	std::shared_ptr<TestIdentityAction> element(new TestIdentityActionImpl());
	return element;
}
std::shared_ptr<TestIdentityAction> UmlFactoryImpl::createTestIdentityAction_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<TestIdentityAction> element(new TestIdentityActionImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<TestIdentityAction> UmlFactoryImpl::createTestIdentityAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<TestIdentityAction> element(new TestIdentityActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<TestIdentityAction> UmlFactoryImpl::createTestIdentityAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<TestIdentityAction> element(new TestIdentityActionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<TestIdentityAction> UmlFactoryImpl::createTestIdentityAction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<TestIdentityAction> element(new TestIdentityActionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<TimeConstraint> UmlFactoryImpl::createTimeConstraint() const
{
	std::shared_ptr<TimeConstraint> element(new TimeConstraintImpl());
	return element;
}
std::shared_ptr<TimeConstraint> UmlFactoryImpl::createTimeConstraint_in_Context(std::weak_ptr<uml::Namespace > par_context) const
{
	std::shared_ptr<TimeConstraint> element(new TimeConstraintImpl(par_context, UmlPackage::CONSTRAINT_CONTEXT));
	if(auto wp = par_context.lock())
	{
    		wp->getOwnedRule()->push_back(element);
	}
	return element;
}

std::shared_ptr<TimeConstraint> UmlFactoryImpl::createTimeConstraint_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<TimeConstraint> element(new TimeConstraintImpl(par_namespace, UmlPackage::NAMEDELEMENT_NAMESPACE));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<TimeConstraint> UmlFactoryImpl::createTimeConstraint_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<TimeConstraint> element(new TimeConstraintImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<TimeConstraint> UmlFactoryImpl::createTimeConstraint_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<TimeConstraint> element(new TimeConstraintImpl(par_owningPackage));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<TimeConstraint> UmlFactoryImpl::createTimeConstraint_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<TimeConstraint> element(new TimeConstraintImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<TimeEvent> UmlFactoryImpl::createTimeEvent() const
{
	std::shared_ptr<TimeEvent> element(new TimeEventImpl());
	return element;
}
std::shared_ptr<TimeEvent> UmlFactoryImpl::createTimeEvent_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<TimeEvent> element(new TimeEventImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<TimeEvent> UmlFactoryImpl::createTimeEvent_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<TimeEvent> element(new TimeEventImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<TimeEvent> UmlFactoryImpl::createTimeEvent_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<TimeEvent> element(new TimeEventImpl(par_owningPackage));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<TimeEvent> UmlFactoryImpl::createTimeEvent_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<TimeEvent> element(new TimeEventImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<TimeExpression> UmlFactoryImpl::createTimeExpression() const
{
	std::shared_ptr<TimeExpression> element(new TimeExpressionImpl());
	return element;
}
std::shared_ptr<TimeExpression> UmlFactoryImpl::createTimeExpression_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<TimeExpression> element(new TimeExpressionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<TimeExpression> UmlFactoryImpl::createTimeExpression_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<TimeExpression> element(new TimeExpressionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<TimeExpression> UmlFactoryImpl::createTimeExpression_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<TimeExpression> element(new TimeExpressionImpl(par_owningPackage));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<TimeExpression> UmlFactoryImpl::createTimeExpression_in_OwningSlot(std::weak_ptr<uml::Slot > par_owningSlot) const
{
	std::shared_ptr<TimeExpression> element(new TimeExpressionImpl(par_owningSlot));
	if(auto wp = par_owningSlot.lock())
	{
    		wp->getValue()->push_back(element);
	}
	return element;
}

std::shared_ptr<TimeExpression> UmlFactoryImpl::createTimeExpression_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<TimeExpression> element(new TimeExpressionImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<TimeInterval> UmlFactoryImpl::createTimeInterval() const
{
	std::shared_ptr<TimeInterval> element(new TimeIntervalImpl());
	return element;
}
std::shared_ptr<TimeInterval> UmlFactoryImpl::createTimeInterval_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<TimeInterval> element(new TimeIntervalImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<TimeInterval> UmlFactoryImpl::createTimeInterval_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<TimeInterval> element(new TimeIntervalImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<TimeInterval> UmlFactoryImpl::createTimeInterval_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<TimeInterval> element(new TimeIntervalImpl(par_owningPackage));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<TimeInterval> UmlFactoryImpl::createTimeInterval_in_OwningSlot(std::weak_ptr<uml::Slot > par_owningSlot) const
{
	std::shared_ptr<TimeInterval> element(new TimeIntervalImpl(par_owningSlot));
	if(auto wp = par_owningSlot.lock())
	{
    		wp->getValue()->push_back(element);
	}
	return element;
}

std::shared_ptr<TimeInterval> UmlFactoryImpl::createTimeInterval_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<TimeInterval> element(new TimeIntervalImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<TimeObservation> UmlFactoryImpl::createTimeObservation() const
{
	std::shared_ptr<TimeObservation> element(new TimeObservationImpl());
	return element;
}
std::shared_ptr<TimeObservation> UmlFactoryImpl::createTimeObservation_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<TimeObservation> element(new TimeObservationImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<TimeObservation> UmlFactoryImpl::createTimeObservation_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<TimeObservation> element(new TimeObservationImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<TimeObservation> UmlFactoryImpl::createTimeObservation_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<TimeObservation> element(new TimeObservationImpl(par_owningPackage));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<TimeObservation> UmlFactoryImpl::createTimeObservation_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<TimeObservation> element(new TimeObservationImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<Transition> UmlFactoryImpl::createTransition() const
{
	std::shared_ptr<Transition> element(new TransitionImpl());
	return element;
}
std::shared_ptr<Transition> UmlFactoryImpl::createTransition_in_Container(std::weak_ptr<uml::Region > par_container) const
{
	std::shared_ptr<Transition> element(new TransitionImpl(par_container));
	if(auto wp = par_container.lock())
	{
    		wp->getTransition()->push_back(element);
	}
	return element;
}

std::shared_ptr<Transition> UmlFactoryImpl::createTransition_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Transition> element(new TransitionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Transition> UmlFactoryImpl::createTransition_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Transition> element(new TransitionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Trigger> UmlFactoryImpl::createTrigger() const
{
	std::shared_ptr<Trigger> element(new TriggerImpl());
	return element;
}
std::shared_ptr<Trigger> UmlFactoryImpl::createTrigger_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Trigger> element(new TriggerImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Trigger> UmlFactoryImpl::createTrigger_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Trigger> element(new TriggerImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<UnmarshallAction> UmlFactoryImpl::createUnmarshallAction() const
{
	std::shared_ptr<UnmarshallAction> element(new UnmarshallActionImpl());
	return element;
}
std::shared_ptr<UnmarshallAction> UmlFactoryImpl::createUnmarshallAction_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<UnmarshallAction> element(new UnmarshallActionImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<UnmarshallAction> UmlFactoryImpl::createUnmarshallAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<UnmarshallAction> element(new UnmarshallActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<UnmarshallAction> UmlFactoryImpl::createUnmarshallAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<UnmarshallAction> element(new UnmarshallActionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<UnmarshallAction> UmlFactoryImpl::createUnmarshallAction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<UnmarshallAction> element(new UnmarshallActionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Usage> UmlFactoryImpl::createUsage() const
{
	std::shared_ptr<Usage> element(new UsageImpl());
	return element;
}
std::shared_ptr<Usage> UmlFactoryImpl::createUsage_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Usage> element(new UsageImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Usage> UmlFactoryImpl::createUsage_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Usage> element(new UsageImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Usage> UmlFactoryImpl::createUsage_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<Usage> element(new UsageImpl(par_owningPackage));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Usage> UmlFactoryImpl::createUsage_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Usage> element(new UsageImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<UseCase> UmlFactoryImpl::createUseCase() const
{
	std::shared_ptr<UseCase> element(new UseCaseImpl());
	return element;
}
std::shared_ptr<UseCase> UmlFactoryImpl::createUseCase_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<UseCase> element(new UseCaseImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<UseCase> UmlFactoryImpl::createUseCase_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<UseCase> element(new UseCaseImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<UseCase> UmlFactoryImpl::createUseCase_in_OwningPackage(std::weak_ptr<uml::Package > par_owningPackage) const
{
	std::shared_ptr<UseCase> element(new UseCaseImpl(par_owningPackage, UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE));
	if(auto wp = par_owningPackage.lock())
	{
    		wp->getPackagedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<UseCase> UmlFactoryImpl::createUseCase_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<UseCase> element(new UseCaseImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<UseCase> UmlFactoryImpl::createUseCase_in_Package(std::weak_ptr<uml::Package > par_package) const
{
	std::shared_ptr<UseCase> element(new UseCaseImpl(par_package, UmlPackage::TYPE_PACKAGE));
	if(auto wp = par_package.lock())
	{
    		wp->getOwnedType()->push_back(element);
	}
	return element;
}

std::shared_ptr<ValuePin> UmlFactoryImpl::createValuePin() const
{
	std::shared_ptr<ValuePin> element(new ValuePinImpl());
	return element;
}
std::shared_ptr<ValuePin> UmlFactoryImpl::createValuePin_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ValuePin> element(new ValuePinImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ValuePin> UmlFactoryImpl::createValuePin_in_CallOperationAction(std::weak_ptr<uml::CallOperationAction > par_callOperationAction) const
{
	std::shared_ptr<ValuePin> element(new ValuePinImpl(par_callOperationAction));
	if(auto wp = par_callOperationAction.lock())
	{
			wp->setTarget(element);
	}
	return element;
}

std::shared_ptr<ValuePin> UmlFactoryImpl::createValuePin_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ValuePin> element(new ValuePinImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ValuePin> UmlFactoryImpl::createValuePin_in_InvocationAction(std::weak_ptr<uml::InvocationAction > par_invocationAction) const
{
	std::shared_ptr<ValuePin> element(new ValuePinImpl(par_invocationAction));
	if(auto wp = par_invocationAction.lock())
	{
    		wp->getArgument()->push_back(element);
	}
	return element;
}

std::shared_ptr<ValuePin> UmlFactoryImpl::createValuePin_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ValuePin> element(new ValuePinImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<ValuePin> UmlFactoryImpl::createValuePin_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ValuePin> element(new ValuePinImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<ValuePin> UmlFactoryImpl::createValuePin_in_StructuralFeatureAction(std::weak_ptr<uml::StructuralFeatureAction > par_structuralFeatureAction) const
{
	std::shared_ptr<ValuePin> element(new ValuePinImpl(par_structuralFeatureAction));
	if(auto wp = par_structuralFeatureAction.lock())
	{
			wp->setObject(element);
	}
	return element;
}

std::shared_ptr<ValueSpecificationAction> UmlFactoryImpl::createValueSpecificationAction() const
{
	std::shared_ptr<ValueSpecificationAction> element(new ValueSpecificationActionImpl());
	return element;
}
std::shared_ptr<ValueSpecificationAction> UmlFactoryImpl::createValueSpecificationAction_in_Activity(std::weak_ptr<uml::Activity > par_activity) const
{
	std::shared_ptr<ValueSpecificationAction> element(new ValueSpecificationActionImpl(par_activity));
	if(auto wp = par_activity.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ValueSpecificationAction> UmlFactoryImpl::createValueSpecificationAction_in_InStructuredNode(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode) const
{
	std::shared_ptr<ValueSpecificationAction> element(new ValueSpecificationActionImpl(par_inStructuredNode));
	if(auto wp = par_inStructuredNode.lock())
	{
    		wp->getNode()->push_back(element);
	}
	return element;
}

std::shared_ptr<ValueSpecificationAction> UmlFactoryImpl::createValueSpecificationAction_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<ValueSpecificationAction> element(new ValueSpecificationActionImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<ValueSpecificationAction> UmlFactoryImpl::createValueSpecificationAction_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<ValueSpecificationAction> element(new ValueSpecificationActionImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Variable> UmlFactoryImpl::createVariable() const
{
	std::shared_ptr<Variable> element(new VariableImpl());
	return element;
}
std::shared_ptr<Variable> UmlFactoryImpl::createVariable_in_ActivityScope(std::weak_ptr<uml::Activity > par_activityScope) const
{
	std::shared_ptr<Variable> element(new VariableImpl(par_activityScope));
	if(auto wp = par_activityScope.lock())
	{
    		wp->getVariable()->push_back(element);
	}
	return element;
}

std::shared_ptr<Variable> UmlFactoryImpl::createVariable_in_Namespace(std::weak_ptr<uml::Namespace > par_namespace) const
{
	std::shared_ptr<Variable> element(new VariableImpl(par_namespace));
	if(auto wp = par_namespace.lock())
	{
    		wp->getOwnedMember()->push_back(element);
	}
	return element;
}

std::shared_ptr<Variable> UmlFactoryImpl::createVariable_in_Owner(std::weak_ptr<uml::Element > par_owner) const
{
	std::shared_ptr<Variable> element(new VariableImpl(par_owner));
	if(auto wp = par_owner.lock())
	{
    		wp->getOwnedElement()->push_back(element);
	}
	return element;
}

std::shared_ptr<Variable> UmlFactoryImpl::createVariable_in_OwningTemplateParameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter) const
{
	std::shared_ptr<Variable> element(new VariableImpl(par_owningTemplateParameter));
	if(auto wp = par_owningTemplateParameter.lock())
	{
			wp->setOwnedParameteredElement(element);
	}
	return element;
}

std::shared_ptr<Variable> UmlFactoryImpl::createVariable_in_Scope(std::weak_ptr<uml::StructuredActivityNode > par_scope) const
{
	std::shared_ptr<Variable> element(new VariableImpl(par_scope));
	if(auto wp = par_scope.lock())
	{
    		wp->getVariable()->push_back(element);
	}
	return element;
}


std::shared_ptr<UmlPackage> UmlFactoryImpl::getUmlPackage() const
{
	return UmlPackage::eInstance();
}
