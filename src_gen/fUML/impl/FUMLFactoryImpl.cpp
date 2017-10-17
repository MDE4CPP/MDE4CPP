#include "FUMLFactoryImpl.hpp"
#include "FUMLPackage.hpp"

#include "EClass.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************

FUMLFactoryImpl::FUMLFactoryImpl()
{
	m_idMap.insert(std::pair<std::string,unsigned int>("AcceptEventActionActivation", FUMLPackage::ACCEPTEVENTACTIONACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("AcceptEventActionEventAccepter", FUMLPackage::ACCEPTEVENTACTIONEVENTACCEPTER));
	m_idMap.insert(std::pair<std::string,unsigned int>("ActivityEdgeInstance", FUMLPackage::ACTIVITYEDGEINSTANCE));
	m_idMap.insert(std::pair<std::string,unsigned int>("ActivityExecution", FUMLPackage::ACTIVITYEXECUTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("ActivityFinalNodeActivation", FUMLPackage::ACTIVITYFINALNODEACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("ActivityNodeActivationGroup", FUMLPackage::ACTIVITYNODEACTIVATIONGROUP));
	m_idMap.insert(std::pair<std::string,unsigned int>("ActivityParameterNodeActivation", FUMLPackage::ACTIVITYPARAMETERNODEACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("AddStructuralFeatureValueActionActivation", FUMLPackage::ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("BooleanValue", FUMLPackage::BOOLEANVALUE));
	m_idMap.insert(std::pair<std::string,unsigned int>("CallBehaviorActionActivation", FUMLPackage::CALLBEHAVIORACTIONACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("CallOperationActionActivation", FUMLPackage::CALLOPERATIONACTIONACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("CentralBufferNodeActivation", FUMLPackage::CENTRALBUFFERNODEACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("ClassifierBehaviorExecution", FUMLPackage::CLASSIFIERBEHAVIOREXECUTION));
	m_idMap.insert(std::pair<std::string,unsigned int>("ClassifierBehaviorExecutionActivity", FUMLPackage::CLASSIFIERBEHAVIOREXECUTIONACTIVITY));
	m_idMap.insert(std::pair<std::string,unsigned int>("ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1", FUMLPackage::CLASSIFIERBEHAVIOREXECUTIONACTIVITY_OWNEDBEHAVIORACTIVITY1));
	m_idMap.insert(std::pair<std::string,unsigned int>("ClauseActivation", FUMLPackage::CLAUSEACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("ClearAssociationActionActivation", FUMLPackage::CLEARASSOCIATIONACTIONACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("ClearStructuralFeatureActionActivation", FUMLPackage::CLEARSTRUCTURALFEATUREACTIONACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("ConditionalNodeActivation", FUMLPackage::CONDITIONALNODEACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("ControlToken", FUMLPackage::CONTROLTOKEN));
	m_idMap.insert(std::pair<std::string,unsigned int>("CreateLinkActionActivation", FUMLPackage::CREATELINKACTIONACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("CreateObjectActionActivation", FUMLPackage::CREATEOBJECTACTIONACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("DataStoreNodeActivation", FUMLPackage::DATASTORENODEACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("DataValue", FUMLPackage::DATAVALUE));
	m_idMap.insert(std::pair<std::string,unsigned int>("DecisionNodeActivation", FUMLPackage::DECISIONNODEACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("DestroyLinkActionActivation", FUMLPackage::DESTROYLINKACTIONACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("DestroyObjectActionActivation", FUMLPackage::DESTROYOBJECTACTIONACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("DispatchStrategy", FUMLPackage::DISPATCHSTRATEGY));
	m_idMap.insert(std::pair<std::string,unsigned int>("EnumerationValue", FUMLPackage::ENUMERATIONVALUE));
	m_idMap.insert(std::pair<std::string,unsigned int>("EventDispatchLoop", FUMLPackage::EVENTDISPATCHLOOP));
	m_idMap.insert(std::pair<std::string,unsigned int>("ExecutionFactoryL1", FUMLPackage::EXECUTIONFACTORYL1));
	m_idMap.insert(std::pair<std::string,unsigned int>("ExecutionFactoryL2", FUMLPackage::EXECUTIONFACTORYL2));
	m_idMap.insert(std::pair<std::string,unsigned int>("ExecutionFactoryL3", FUMLPackage::EXECUTIONFACTORYL3));
	m_idMap.insert(std::pair<std::string,unsigned int>("Executor", FUMLPackage::EXECUTOR));
	m_idMap.insert(std::pair<std::string,unsigned int>("ExpansionActivationGroup", FUMLPackage::EXPANSIONACTIVATIONGROUP));
	m_idMap.insert(std::pair<std::string,unsigned int>("ExpansionNodeActivation", FUMLPackage::EXPANSIONNODEACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("ExpansionRegionActivation", FUMLPackage::EXPANSIONREGIONACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("ExtensionalValueList", FUMLPackage::EXTENSIONALVALUELIST));
	m_idMap.insert(std::pair<std::string,unsigned int>("FIFOGetNextEventStrategy", FUMLPackage::FIFOGETNEXTEVENTSTRATEGY));
	m_idMap.insert(std::pair<std::string,unsigned int>("FeatureValue", FUMLPackage::FEATUREVALUE));
	m_idMap.insert(std::pair<std::string,unsigned int>("FirstChoiceStrategy", FUMLPackage::FIRSTCHOICESTRATEGY));
	m_idMap.insert(std::pair<std::string,unsigned int>("FlowFinalNodeActivation", FUMLPackage::FLOWFINALNODEACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("ForkNodeActivation", FUMLPackage::FORKNODEACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("ForkedToken", FUMLPackage::FORKEDTOKEN));
	m_idMap.insert(std::pair<std::string,unsigned int>("InitialNodeActivation", FUMLPackage::INITIALNODEACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("InputPinActivation", FUMLPackage::INPUTPINACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("InstanceValueEvaluation", FUMLPackage::INSTANCEVALUEEVALUATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("IntegerValue", FUMLPackage::INTEGERVALUE));
	m_idMap.insert(std::pair<std::string,unsigned int>("JoinNodeActivation", FUMLPackage::JOINNODEACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("Link", FUMLPackage::LINK));
	m_idMap.insert(std::pair<std::string,unsigned int>("LiteralBooleanEvaluation", FUMLPackage::LITERALBOOLEANEVALUATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("LiteralIntegerEvaluation", FUMLPackage::LITERALINTEGEREVALUATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("LiteralNullEvaluation", FUMLPackage::LITERALNULLEVALUATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("LiteralRealEvaluation", FUMLPackage::LITERALREALEVALUATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("LiteralStringEvaluation", FUMLPackage::LITERALSTRINGEVALUATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("LiteralUnlimitedNaturalEvaluation", FUMLPackage::LITERALUNLIMITEDNATURALEVALUATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("Locus", FUMLPackage::LOCUS));
	m_idMap.insert(std::pair<std::string,unsigned int>("LoopNodeActivation", FUMLPackage::LOOPNODEACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("MergeNodeActivation", FUMLPackage::MERGENODEACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("Object", FUMLPackage::OBJECT));
	m_idMap.insert(std::pair<std::string,unsigned int>("ObjectActivation", FUMLPackage::OBJECTACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("ObjectToken", FUMLPackage::OBJECTTOKEN));
	m_idMap.insert(std::pair<std::string,unsigned int>("Offer", FUMLPackage::OFFER));
	m_idMap.insert(std::pair<std::string,unsigned int>("OutputPinActivation", FUMLPackage::OUTPUTPINACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("ParameterValue", FUMLPackage::PARAMETERVALUE));
	m_idMap.insert(std::pair<std::string,unsigned int>("ReadExtentActionActivation", FUMLPackage::READEXTENTACTIONACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("ReadIsClassifiedObjectActionActivation", FUMLPackage::READISCLASSIFIEDOBJECTACTIONACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("ReadLinkActionActivation", FUMLPackage::READLINKACTIONACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("ReadSelfActionActivation", FUMLPackage::READSELFACTIONACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("ReadStructuralFeatureActionActivation", FUMLPackage::READSTRUCTURALFEATUREACTIONACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("RealValue", FUMLPackage::REALVALUE));
	m_idMap.insert(std::pair<std::string,unsigned int>("ReclassifyObjectActionActivation", FUMLPackage::RECLASSIFYOBJECTACTIONACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("RedefinitionBasedDispatchStrategy", FUMLPackage::REDEFINITIONBASEDDISPATCHSTRATEGY));
	m_idMap.insert(std::pair<std::string,unsigned int>("ReduceActionActivation", FUMLPackage::REDUCEACTIONACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("Reference", FUMLPackage::REFERENCE));
	m_idMap.insert(std::pair<std::string,unsigned int>("RemoveStructuralFeatureValueActivation", FUMLPackage::REMOVESTRUCTURALFEATUREVALUEACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("SendSignalActionActivation", FUMLPackage::SENDSIGNALACTIONACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("SignalInstance", FUMLPackage::SIGNALINSTANCE));
	m_idMap.insert(std::pair<std::string,unsigned int>("StartClassifierBehaviorActionActivation", FUMLPackage::STARTCLASSIFIERBEHAVIORACTIONACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("StartObjectBehaviorActionActivation", FUMLPackage::STARTOBJECTBEHAVIORACTIONACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("StringValue", FUMLPackage::STRINGVALUE));
	m_idMap.insert(std::pair<std::string,unsigned int>("StructuredActivityNodeActivation", FUMLPackage::STRUCTUREDACTIVITYNODEACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("TestIdentityActionActivation", FUMLPackage::TESTIDENTITYACTIONACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("TokenSet", FUMLPackage::TOKENSET));
	m_idMap.insert(std::pair<std::string,unsigned int>("UnlimitedNaturalValue", FUMLPackage::UNLIMITEDNATURALVALUE));
	m_idMap.insert(std::pair<std::string,unsigned int>("ValueSpecificActionActivation", FUMLPackage::VALUESPECIFICACTIONACTIVATION));
	m_idMap.insert(std::pair<std::string,unsigned int>("Values", FUMLPackage::VALUES));
}

FUMLFactoryImpl::~FUMLFactoryImpl()
{
}

FUMLFactory* FUMLFactoryImpl::create()
{
	return new FUMLFactoryImpl();
}

//*********************************
// creators
//*********************************

std::shared_ptr<ecore::EObject> FUMLFactoryImpl::create(const unsigned int classID,  std::shared_ptr<ecore::EObject> container /*= nullptr*/, const unsigned int referenceID/* = -1*/) const
{
	switch(classID)
	{
		case FUMLPackage::ACCEPTEVENTACTIONACTIVATION:
		{
				return std::shared_ptr<AcceptEventActionActivation>(this->createAcceptEventActionActivation());
			
		}
		case FUMLPackage::ACCEPTEVENTACTIONEVENTACCEPTER:
		{
				return std::shared_ptr<AcceptEventActionEventAccepter>(this->createAcceptEventActionEventAccepter());
			
		}
		case FUMLPackage::ACTIVITYEDGEINSTANCE:
		{
				return std::shared_ptr<ActivityEdgeInstance>(this->createActivityEdgeInstance());
			
		}
		case FUMLPackage::ACTIVITYEXECUTION:
		{
				return std::shared_ptr<ActivityExecution>(this->createActivityExecution());
			
		}
		case FUMLPackage::ACTIVITYFINALNODEACTIVATION:
		{
				return std::shared_ptr<ActivityFinalNodeActivation>(this->createActivityFinalNodeActivation());
			
		}
		case FUMLPackage::ACTIVITYNODEACTIVATIONGROUP:
		{
				return std::shared_ptr<ActivityNodeActivationGroup>(this->createActivityNodeActivationGroup());
			
		}
		case FUMLPackage::ACTIVITYPARAMETERNODEACTIVATION:
		{
				return std::shared_ptr<ActivityParameterNodeActivation>(this->createActivityParameterNodeActivation());
			
		}
		case FUMLPackage::ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION:
		{
				return std::shared_ptr<AddStructuralFeatureValueActionActivation>(this->createAddStructuralFeatureValueActionActivation());
			
		}
		case FUMLPackage::BOOLEANVALUE:
		{
				return std::shared_ptr<BooleanValue>(this->createBooleanValue());
			
		}
		case FUMLPackage::CALLBEHAVIORACTIONACTIVATION:
		{
				return std::shared_ptr<CallBehaviorActionActivation>(this->createCallBehaviorActionActivation());
			
		}
		case FUMLPackage::CALLOPERATIONACTIONACTIVATION:
		{
				return std::shared_ptr<CallOperationActionActivation>(this->createCallOperationActionActivation());
			
		}
		case FUMLPackage::CENTRALBUFFERNODEACTIVATION:
		{
				return std::shared_ptr<CentralBufferNodeActivation>(this->createCentralBufferNodeActivation());
			
		}
		case FUMLPackage::CLASSIFIERBEHAVIOREXECUTION:
		{
				return std::shared_ptr<ClassifierBehaviorExecution>(this->createClassifierBehaviorExecution());
			
		}
		case FUMLPackage::CLASSIFIERBEHAVIOREXECUTIONACTIVITY:
		{
				return std::shared_ptr<ClassifierBehaviorExecutionActivity>(this->createClassifierBehaviorExecutionActivity());
			
		}
		case FUMLPackage::CLASSIFIERBEHAVIOREXECUTIONACTIVITY_OWNEDBEHAVIORACTIVITY1:
		{
				return std::shared_ptr<ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1>(this->createClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1());
			
		}
		case FUMLPackage::CLAUSEACTIVATION:
		{
				return std::shared_ptr<ClauseActivation>(this->createClauseActivation());
			
		}
		case FUMLPackage::CLEARASSOCIATIONACTIONACTIVATION:
		{
				return std::shared_ptr<ClearAssociationActionActivation>(this->createClearAssociationActionActivation());
			
		}
		case FUMLPackage::CLEARSTRUCTURALFEATUREACTIONACTIVATION:
		{
				return std::shared_ptr<ClearStructuralFeatureActionActivation>(this->createClearStructuralFeatureActionActivation());
			
		}
		case FUMLPackage::CONDITIONALNODEACTIVATION:
		{
				return std::shared_ptr<ConditionalNodeActivation>(this->createConditionalNodeActivation());
			
		}
		case FUMLPackage::CONTROLTOKEN:
		{
				return std::shared_ptr<ControlToken>(this->createControlToken());
			
		}
		case FUMLPackage::CREATELINKACTIONACTIVATION:
		{
				return std::shared_ptr<CreateLinkActionActivation>(this->createCreateLinkActionActivation());
			
		}
		case FUMLPackage::CREATEOBJECTACTIONACTIVATION:
		{
				return std::shared_ptr<CreateObjectActionActivation>(this->createCreateObjectActionActivation());
			
		}
		case FUMLPackage::DATASTORENODEACTIVATION:
		{
				return std::shared_ptr<DataStoreNodeActivation>(this->createDataStoreNodeActivation());
			
		}
		case FUMLPackage::DATAVALUE:
		{
				return std::shared_ptr<DataValue>(this->createDataValue());
			
		}
		case FUMLPackage::DECISIONNODEACTIVATION:
		{
				return std::shared_ptr<DecisionNodeActivation>(this->createDecisionNodeActivation());
			
		}
		case FUMLPackage::DESTROYLINKACTIONACTIVATION:
		{
				return std::shared_ptr<DestroyLinkActionActivation>(this->createDestroyLinkActionActivation());
			
		}
		case FUMLPackage::DESTROYOBJECTACTIONACTIVATION:
		{
				return std::shared_ptr<DestroyObjectActionActivation>(this->createDestroyObjectActionActivation());
			
		}
		case FUMLPackage::DISPATCHSTRATEGY:
		{
				return std::shared_ptr<DispatchStrategy>(this->createDispatchStrategy());
			
		}
		case FUMLPackage::ENUMERATIONVALUE:
		{
				return std::shared_ptr<EnumerationValue>(this->createEnumerationValue());
			
		}
		case FUMLPackage::EVENTDISPATCHLOOP:
		{
				return std::shared_ptr<EventDispatchLoop>(this->createEventDispatchLoop());
			
		}
		case FUMLPackage::EXECUTIONFACTORYL1:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ExecutionFactoryL1>(this->createExecutionFactoryL1());
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::Locus>(container);
				assert(castedContainer);
				return std::shared_ptr<ExecutionFactoryL1>(this->createExecutionFactoryL1_in_Locus(castedContainer));
			}
		}
		case FUMLPackage::EXECUTIONFACTORYL2:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ExecutionFactoryL2>(this->createExecutionFactoryL2());
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::Locus>(container);
				assert(castedContainer);
				return std::shared_ptr<ExecutionFactoryL2>(this->createExecutionFactoryL2_in_Locus(castedContainer));
			}
		}
		case FUMLPackage::EXECUTIONFACTORYL3:
		{
			if (nullptr == container)
			{
				return std::shared_ptr<ExecutionFactoryL3>(this->createExecutionFactoryL3());
			}
			else
			{
				auto castedContainer = std::dynamic_pointer_cast<fUML::Locus>(container);
				assert(castedContainer);
				return std::shared_ptr<ExecutionFactoryL3>(this->createExecutionFactoryL3_in_Locus(castedContainer));
			}
		}
		case FUMLPackage::EXECUTOR:
		{
				return std::shared_ptr<Executor>(this->createExecutor());
			
		}
		case FUMLPackage::EXPANSIONACTIVATIONGROUP:
		{
				return std::shared_ptr<ExpansionActivationGroup>(this->createExpansionActivationGroup());
			
		}
		case FUMLPackage::EXPANSIONNODEACTIVATION:
		{
				return std::shared_ptr<ExpansionNodeActivation>(this->createExpansionNodeActivation());
			
		}
		case FUMLPackage::EXPANSIONREGIONACTIVATION:
		{
				return std::shared_ptr<ExpansionRegionActivation>(this->createExpansionRegionActivation());
			
		}
		case FUMLPackage::EXTENSIONALVALUELIST:
		{
				return std::shared_ptr<ExtensionalValueList>(this->createExtensionalValueList());
			
		}
		case FUMLPackage::FIFOGETNEXTEVENTSTRATEGY:
		{
				return std::shared_ptr<FIFOGetNextEventStrategy>(this->createFIFOGetNextEventStrategy());
			
		}
		case FUMLPackage::FEATUREVALUE:
		{
				return std::shared_ptr<FeatureValue>(this->createFeatureValue());
			
		}
		case FUMLPackage::FIRSTCHOICESTRATEGY:
		{
				return std::shared_ptr<FirstChoiceStrategy>(this->createFirstChoiceStrategy());
			
		}
		case FUMLPackage::FLOWFINALNODEACTIVATION:
		{
				return std::shared_ptr<FlowFinalNodeActivation>(this->createFlowFinalNodeActivation());
			
		}
		case FUMLPackage::FORKNODEACTIVATION:
		{
				return std::shared_ptr<ForkNodeActivation>(this->createForkNodeActivation());
			
		}
		case FUMLPackage::FORKEDTOKEN:
		{
				return std::shared_ptr<ForkedToken>(this->createForkedToken());
			
		}
		case FUMLPackage::INITIALNODEACTIVATION:
		{
				return std::shared_ptr<InitialNodeActivation>(this->createInitialNodeActivation());
			
		}
		case FUMLPackage::INPUTPINACTIVATION:
		{
				return std::shared_ptr<InputPinActivation>(this->createInputPinActivation());
			
		}
		case FUMLPackage::INSTANCEVALUEEVALUATION:
		{
				return std::shared_ptr<InstanceValueEvaluation>(this->createInstanceValueEvaluation());
			
		}
		case FUMLPackage::INTEGERVALUE:
		{
				return std::shared_ptr<IntegerValue>(this->createIntegerValue());
			
		}
		case FUMLPackage::JOINNODEACTIVATION:
		{
				return std::shared_ptr<JoinNodeActivation>(this->createJoinNodeActivation());
			
		}
		case FUMLPackage::LINK:
		{
				return std::shared_ptr<Link>(this->createLink());
			
		}
		case FUMLPackage::LITERALBOOLEANEVALUATION:
		{
				return std::shared_ptr<LiteralBooleanEvaluation>(this->createLiteralBooleanEvaluation());
			
		}
		case FUMLPackage::LITERALINTEGEREVALUATION:
		{
				return std::shared_ptr<LiteralIntegerEvaluation>(this->createLiteralIntegerEvaluation());
			
		}
		case FUMLPackage::LITERALNULLEVALUATION:
		{
				return std::shared_ptr<LiteralNullEvaluation>(this->createLiteralNullEvaluation());
			
		}
		case FUMLPackage::LITERALREALEVALUATION:
		{
				return std::shared_ptr<LiteralRealEvaluation>(this->createLiteralRealEvaluation());
			
		}
		case FUMLPackage::LITERALSTRINGEVALUATION:
		{
				return std::shared_ptr<LiteralStringEvaluation>(this->createLiteralStringEvaluation());
			
		}
		case FUMLPackage::LITERALUNLIMITEDNATURALEVALUATION:
		{
				return std::shared_ptr<LiteralUnlimitedNaturalEvaluation>(this->createLiteralUnlimitedNaturalEvaluation());
			
		}
		case FUMLPackage::LOCUS:
		{
				return std::shared_ptr<Locus>(this->createLocus());
			
		}
		case FUMLPackage::LOOPNODEACTIVATION:
		{
				return std::shared_ptr<LoopNodeActivation>(this->createLoopNodeActivation());
			
		}
		case FUMLPackage::MERGENODEACTIVATION:
		{
				return std::shared_ptr<MergeNodeActivation>(this->createMergeNodeActivation());
			
		}
		case FUMLPackage::OBJECT:
		{
				return std::shared_ptr<Object>(this->createObject());
			
		}
		case FUMLPackage::OBJECTACTIVATION:
		{
				return std::shared_ptr<ObjectActivation>(this->createObjectActivation());
			
		}
		case FUMLPackage::OBJECTTOKEN:
		{
				return std::shared_ptr<ObjectToken>(this->createObjectToken());
			
		}
		case FUMLPackage::OFFER:
		{
				return std::shared_ptr<Offer>(this->createOffer());
			
		}
		case FUMLPackage::OUTPUTPINACTIVATION:
		{
				return std::shared_ptr<OutputPinActivation>(this->createOutputPinActivation());
			
		}
		case FUMLPackage::PARAMETERVALUE:
		{
				return std::shared_ptr<ParameterValue>(this->createParameterValue());
			
		}
		case FUMLPackage::READEXTENTACTIONACTIVATION:
		{
				return std::shared_ptr<ReadExtentActionActivation>(this->createReadExtentActionActivation());
			
		}
		case FUMLPackage::READISCLASSIFIEDOBJECTACTIONACTIVATION:
		{
				return std::shared_ptr<ReadIsClassifiedObjectActionActivation>(this->createReadIsClassifiedObjectActionActivation());
			
		}
		case FUMLPackage::READLINKACTIONACTIVATION:
		{
				return std::shared_ptr<ReadLinkActionActivation>(this->createReadLinkActionActivation());
			
		}
		case FUMLPackage::READSELFACTIONACTIVATION:
		{
				return std::shared_ptr<ReadSelfActionActivation>(this->createReadSelfActionActivation());
			
		}
		case FUMLPackage::READSTRUCTURALFEATUREACTIONACTIVATION:
		{
				return std::shared_ptr<ReadStructuralFeatureActionActivation>(this->createReadStructuralFeatureActionActivation());
			
		}
		case FUMLPackage::REALVALUE:
		{
				return std::shared_ptr<RealValue>(this->createRealValue());
			
		}
		case FUMLPackage::RECLASSIFYOBJECTACTIONACTIVATION:
		{
				return std::shared_ptr<ReclassifyObjectActionActivation>(this->createReclassifyObjectActionActivation());
			
		}
		case FUMLPackage::REDEFINITIONBASEDDISPATCHSTRATEGY:
		{
				return std::shared_ptr<RedefinitionBasedDispatchStrategy>(this->createRedefinitionBasedDispatchStrategy());
			
		}
		case FUMLPackage::REDUCEACTIONACTIVATION:
		{
				return std::shared_ptr<ReduceActionActivation>(this->createReduceActionActivation());
			
		}
		case FUMLPackage::REFERENCE:
		{
				return std::shared_ptr<Reference>(this->createReference());
			
		}
		case FUMLPackage::REMOVESTRUCTURALFEATUREVALUEACTIVATION:
		{
				return std::shared_ptr<RemoveStructuralFeatureValueActivation>(this->createRemoveStructuralFeatureValueActivation());
			
		}
		case FUMLPackage::SENDSIGNALACTIONACTIVATION:
		{
				return std::shared_ptr<SendSignalActionActivation>(this->createSendSignalActionActivation());
			
		}
		case FUMLPackage::SIGNALINSTANCE:
		{
				return std::shared_ptr<SignalInstance>(this->createSignalInstance());
			
		}
		case FUMLPackage::STARTCLASSIFIERBEHAVIORACTIONACTIVATION:
		{
				return std::shared_ptr<StartClassifierBehaviorActionActivation>(this->createStartClassifierBehaviorActionActivation());
			
		}
		case FUMLPackage::STARTOBJECTBEHAVIORACTIONACTIVATION:
		{
				return std::shared_ptr<StartObjectBehaviorActionActivation>(this->createStartObjectBehaviorActionActivation());
			
		}
		case FUMLPackage::STRINGVALUE:
		{
				return std::shared_ptr<StringValue>(this->createStringValue());
			
		}
		case FUMLPackage::STRUCTUREDACTIVITYNODEACTIVATION:
		{
				return std::shared_ptr<StructuredActivityNodeActivation>(this->createStructuredActivityNodeActivation());
			
		}
		case FUMLPackage::TESTIDENTITYACTIONACTIVATION:
		{
				return std::shared_ptr<TestIdentityActionActivation>(this->createTestIdentityActionActivation());
			
		}
		case FUMLPackage::TOKENSET:
		{
				return std::shared_ptr<TokenSet>(this->createTokenSet());
			
		}
		case FUMLPackage::UNLIMITEDNATURALVALUE:
		{
				return std::shared_ptr<UnlimitedNaturalValue>(this->createUnlimitedNaturalValue());
			
		}
		case FUMLPackage::VALUESPECIFICACTIONACTIVATION:
		{
				return std::shared_ptr<ValueSpecificActionActivation>(this->createValueSpecificActionActivation());
			
		}
		case FUMLPackage::VALUES:
		{
				return std::shared_ptr<Values>(this->createValues());
			
		}
	default:
	   	    std::cerr << __PRETTY_FUNCTION__ << " ID " << classID <<" not found" << std::endl;
	}
	return nullptr;
}

std::shared_ptr<ecore::EObject> FUMLFactoryImpl::create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container /* = nullptr*/) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}

	std::string _className = _class->eClass()->getName();
	return create(_className, _container);
}

std::shared_ptr<ecore::EObject> FUMLFactoryImpl::create(std::string _className) const
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

std::shared_ptr<ecore::EObject> FUMLFactoryImpl::create(std::string _className, std::shared_ptr<EObject> _container, const unsigned int referenceID) const
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


std::shared_ptr<AcceptEventActionActivation> FUMLFactoryImpl::createAcceptEventActionActivation() const
{
	std::shared_ptr<AcceptEventActionActivation> element(new AcceptEventActionActivationImpl());
	return element;
}
std::shared_ptr<AcceptEventActionEventAccepter> FUMLFactoryImpl::createAcceptEventActionEventAccepter() const
{
	std::shared_ptr<AcceptEventActionEventAccepter> element(new AcceptEventActionEventAccepterImpl());
	return element;
}
std::shared_ptr<ActivityEdgeInstance> FUMLFactoryImpl::createActivityEdgeInstance() const
{
	std::shared_ptr<ActivityEdgeInstance> element(new ActivityEdgeInstanceImpl());
	return element;
}
std::shared_ptr<ActivityExecution> FUMLFactoryImpl::createActivityExecution() const
{
	std::shared_ptr<ActivityExecution> element(new ActivityExecutionImpl());
	return element;
}
std::shared_ptr<ActivityFinalNodeActivation> FUMLFactoryImpl::createActivityFinalNodeActivation() const
{
	std::shared_ptr<ActivityFinalNodeActivation> element(new ActivityFinalNodeActivationImpl());
	return element;
}
std::shared_ptr<ActivityNodeActivationGroup> FUMLFactoryImpl::createActivityNodeActivationGroup() const
{
	std::shared_ptr<ActivityNodeActivationGroup> element(new ActivityNodeActivationGroupImpl());
	return element;
}
std::shared_ptr<ActivityParameterNodeActivation> FUMLFactoryImpl::createActivityParameterNodeActivation() const
{
	std::shared_ptr<ActivityParameterNodeActivation> element(new ActivityParameterNodeActivationImpl());
	return element;
}
std::shared_ptr<AddStructuralFeatureValueActionActivation> FUMLFactoryImpl::createAddStructuralFeatureValueActionActivation() const
{
	std::shared_ptr<AddStructuralFeatureValueActionActivation> element(new AddStructuralFeatureValueActionActivationImpl());
	return element;
}
std::shared_ptr<BooleanValue> FUMLFactoryImpl::createBooleanValue() const
{
	std::shared_ptr<BooleanValue> element(new BooleanValueImpl());
	return element;
}
std::shared_ptr<CallBehaviorActionActivation> FUMLFactoryImpl::createCallBehaviorActionActivation() const
{
	std::shared_ptr<CallBehaviorActionActivation> element(new CallBehaviorActionActivationImpl());
	return element;
}
std::shared_ptr<CallOperationActionActivation> FUMLFactoryImpl::createCallOperationActionActivation() const
{
	std::shared_ptr<CallOperationActionActivation> element(new CallOperationActionActivationImpl());
	return element;
}
std::shared_ptr<CentralBufferNodeActivation> FUMLFactoryImpl::createCentralBufferNodeActivation() const
{
	std::shared_ptr<CentralBufferNodeActivation> element(new CentralBufferNodeActivationImpl());
	return element;
}
std::shared_ptr<ClassifierBehaviorExecution> FUMLFactoryImpl::createClassifierBehaviorExecution() const
{
	std::shared_ptr<ClassifierBehaviorExecution> element(new ClassifierBehaviorExecutionImpl());
	return element;
}
std::shared_ptr<ClassifierBehaviorExecutionActivity> FUMLFactoryImpl::createClassifierBehaviorExecutionActivity() const
{
	std::shared_ptr<ClassifierBehaviorExecutionActivity> element(new ClassifierBehaviorExecutionActivityImpl());
	return element;
}
std::shared_ptr<ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1> FUMLFactoryImpl::createClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1() const
{
	std::shared_ptr<ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1> element(new ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl());
	return element;
}
std::shared_ptr<ClauseActivation> FUMLFactoryImpl::createClauseActivation() const
{
	std::shared_ptr<ClauseActivation> element(new ClauseActivationImpl());
	return element;
}
std::shared_ptr<ClearAssociationActionActivation> FUMLFactoryImpl::createClearAssociationActionActivation() const
{
	std::shared_ptr<ClearAssociationActionActivation> element(new ClearAssociationActionActivationImpl());
	return element;
}
std::shared_ptr<ClearStructuralFeatureActionActivation> FUMLFactoryImpl::createClearStructuralFeatureActionActivation() const
{
	std::shared_ptr<ClearStructuralFeatureActionActivation> element(new ClearStructuralFeatureActionActivationImpl());
	return element;
}
std::shared_ptr<ConditionalNodeActivation> FUMLFactoryImpl::createConditionalNodeActivation() const
{
	std::shared_ptr<ConditionalNodeActivation> element(new ConditionalNodeActivationImpl());
	return element;
}
std::shared_ptr<ControlToken> FUMLFactoryImpl::createControlToken() const
{
	std::shared_ptr<ControlToken> element(new ControlTokenImpl());
	return element;
}
std::shared_ptr<CreateLinkActionActivation> FUMLFactoryImpl::createCreateLinkActionActivation() const
{
	std::shared_ptr<CreateLinkActionActivation> element(new CreateLinkActionActivationImpl());
	return element;
}
std::shared_ptr<CreateObjectActionActivation> FUMLFactoryImpl::createCreateObjectActionActivation() const
{
	std::shared_ptr<CreateObjectActionActivation> element(new CreateObjectActionActivationImpl());
	return element;
}
std::shared_ptr<DataStoreNodeActivation> FUMLFactoryImpl::createDataStoreNodeActivation() const
{
	std::shared_ptr<DataStoreNodeActivation> element(new DataStoreNodeActivationImpl());
	return element;
}
std::shared_ptr<DataValue> FUMLFactoryImpl::createDataValue() const
{
	std::shared_ptr<DataValue> element(new DataValueImpl());
	return element;
}
std::shared_ptr<DecisionNodeActivation> FUMLFactoryImpl::createDecisionNodeActivation() const
{
	std::shared_ptr<DecisionNodeActivation> element(new DecisionNodeActivationImpl());
	return element;
}
std::shared_ptr<DestroyLinkActionActivation> FUMLFactoryImpl::createDestroyLinkActionActivation() const
{
	std::shared_ptr<DestroyLinkActionActivation> element(new DestroyLinkActionActivationImpl());
	return element;
}
std::shared_ptr<DestroyObjectActionActivation> FUMLFactoryImpl::createDestroyObjectActionActivation() const
{
	std::shared_ptr<DestroyObjectActionActivation> element(new DestroyObjectActionActivationImpl());
	return element;
}
std::shared_ptr<DispatchStrategy> FUMLFactoryImpl::createDispatchStrategy() const
{
	std::shared_ptr<DispatchStrategy> element(new DispatchStrategyImpl());
	return element;
}
std::shared_ptr<EnumerationValue> FUMLFactoryImpl::createEnumerationValue() const
{
	std::shared_ptr<EnumerationValue> element(new EnumerationValueImpl());
	return element;
}
std::shared_ptr<EventDispatchLoop> FUMLFactoryImpl::createEventDispatchLoop() const
{
	std::shared_ptr<EventDispatchLoop> element(new EventDispatchLoopImpl());
	return element;
}
std::shared_ptr<ExecutionFactoryL1> FUMLFactoryImpl::createExecutionFactoryL1() const
{
	std::shared_ptr<ExecutionFactoryL1> element(new ExecutionFactoryL1Impl());
	return element;
}
std::shared_ptr<ExecutionFactoryL1> FUMLFactoryImpl::createExecutionFactoryL1_in_Locus(std::weak_ptr<fUML::Locus > par_locus) const
{
	std::shared_ptr<ExecutionFactoryL1> element(new ExecutionFactoryL1Impl(par_locus));
	if(auto wp = par_locus.lock())
	{
			wp->setFactory(element);
	}
	return element;
}

std::shared_ptr<ExecutionFactoryL2> FUMLFactoryImpl::createExecutionFactoryL2() const
{
	std::shared_ptr<ExecutionFactoryL2> element(new ExecutionFactoryL2Impl());
	return element;
}
std::shared_ptr<ExecutionFactoryL2> FUMLFactoryImpl::createExecutionFactoryL2_in_Locus(std::weak_ptr<fUML::Locus > par_locus) const
{
	std::shared_ptr<ExecutionFactoryL2> element(new ExecutionFactoryL2Impl(par_locus));
	if(auto wp = par_locus.lock())
	{
			wp->setFactory(element);
	}
	return element;
}

std::shared_ptr<ExecutionFactoryL3> FUMLFactoryImpl::createExecutionFactoryL3() const
{
	std::shared_ptr<ExecutionFactoryL3> element(new ExecutionFactoryL3Impl());
	return element;
}
std::shared_ptr<ExecutionFactoryL3> FUMLFactoryImpl::createExecutionFactoryL3_in_Locus(std::weak_ptr<fUML::Locus > par_locus) const
{
	std::shared_ptr<ExecutionFactoryL3> element(new ExecutionFactoryL3Impl(par_locus));
	if(auto wp = par_locus.lock())
	{
			wp->setFactory(element);
	}
	return element;
}

std::shared_ptr<Executor> FUMLFactoryImpl::createExecutor() const
{
	std::shared_ptr<Executor> element(new ExecutorImpl());
	return element;
}
std::shared_ptr<ExpansionActivationGroup> FUMLFactoryImpl::createExpansionActivationGroup() const
{
	std::shared_ptr<ExpansionActivationGroup> element(new ExpansionActivationGroupImpl());
	return element;
}
std::shared_ptr<ExpansionNodeActivation> FUMLFactoryImpl::createExpansionNodeActivation() const
{
	std::shared_ptr<ExpansionNodeActivation> element(new ExpansionNodeActivationImpl());
	return element;
}
std::shared_ptr<ExpansionRegionActivation> FUMLFactoryImpl::createExpansionRegionActivation() const
{
	std::shared_ptr<ExpansionRegionActivation> element(new ExpansionRegionActivationImpl());
	return element;
}
std::shared_ptr<ExtensionalValueList> FUMLFactoryImpl::createExtensionalValueList() const
{
	std::shared_ptr<ExtensionalValueList> element(new ExtensionalValueListImpl());
	return element;
}
std::shared_ptr<FIFOGetNextEventStrategy> FUMLFactoryImpl::createFIFOGetNextEventStrategy() const
{
	std::shared_ptr<FIFOGetNextEventStrategy> element(new FIFOGetNextEventStrategyImpl());
	return element;
}
std::shared_ptr<FeatureValue> FUMLFactoryImpl::createFeatureValue() const
{
	std::shared_ptr<FeatureValue> element(new FeatureValueImpl());
	return element;
}
std::shared_ptr<FirstChoiceStrategy> FUMLFactoryImpl::createFirstChoiceStrategy() const
{
	std::shared_ptr<FirstChoiceStrategy> element(new FirstChoiceStrategyImpl());
	return element;
}
std::shared_ptr<FlowFinalNodeActivation> FUMLFactoryImpl::createFlowFinalNodeActivation() const
{
	std::shared_ptr<FlowFinalNodeActivation> element(new FlowFinalNodeActivationImpl());
	return element;
}
std::shared_ptr<ForkNodeActivation> FUMLFactoryImpl::createForkNodeActivation() const
{
	std::shared_ptr<ForkNodeActivation> element(new ForkNodeActivationImpl());
	return element;
}
std::shared_ptr<ForkedToken> FUMLFactoryImpl::createForkedToken() const
{
	std::shared_ptr<ForkedToken> element(new ForkedTokenImpl());
	return element;
}
std::shared_ptr<InitialNodeActivation> FUMLFactoryImpl::createInitialNodeActivation() const
{
	std::shared_ptr<InitialNodeActivation> element(new InitialNodeActivationImpl());
	return element;
}
std::shared_ptr<InputPinActivation> FUMLFactoryImpl::createInputPinActivation() const
{
	std::shared_ptr<InputPinActivation> element(new InputPinActivationImpl());
	return element;
}
std::shared_ptr<InstanceValueEvaluation> FUMLFactoryImpl::createInstanceValueEvaluation() const
{
	std::shared_ptr<InstanceValueEvaluation> element(new InstanceValueEvaluationImpl());
	return element;
}
std::shared_ptr<IntegerValue> FUMLFactoryImpl::createIntegerValue() const
{
	std::shared_ptr<IntegerValue> element(new IntegerValueImpl());
	return element;
}
std::shared_ptr<JoinNodeActivation> FUMLFactoryImpl::createJoinNodeActivation() const
{
	std::shared_ptr<JoinNodeActivation> element(new JoinNodeActivationImpl());
	return element;
}
std::shared_ptr<Link> FUMLFactoryImpl::createLink() const
{
	std::shared_ptr<Link> element(new LinkImpl());
	return element;
}
std::shared_ptr<LiteralBooleanEvaluation> FUMLFactoryImpl::createLiteralBooleanEvaluation() const
{
	std::shared_ptr<LiteralBooleanEvaluation> element(new LiteralBooleanEvaluationImpl());
	return element;
}
std::shared_ptr<LiteralIntegerEvaluation> FUMLFactoryImpl::createLiteralIntegerEvaluation() const
{
	std::shared_ptr<LiteralIntegerEvaluation> element(new LiteralIntegerEvaluationImpl());
	return element;
}
std::shared_ptr<LiteralNullEvaluation> FUMLFactoryImpl::createLiteralNullEvaluation() const
{
	std::shared_ptr<LiteralNullEvaluation> element(new LiteralNullEvaluationImpl());
	return element;
}
std::shared_ptr<LiteralRealEvaluation> FUMLFactoryImpl::createLiteralRealEvaluation() const
{
	std::shared_ptr<LiteralRealEvaluation> element(new LiteralRealEvaluationImpl());
	return element;
}
std::shared_ptr<LiteralStringEvaluation> FUMLFactoryImpl::createLiteralStringEvaluation() const
{
	std::shared_ptr<LiteralStringEvaluation> element(new LiteralStringEvaluationImpl());
	return element;
}
std::shared_ptr<LiteralUnlimitedNaturalEvaluation> FUMLFactoryImpl::createLiteralUnlimitedNaturalEvaluation() const
{
	std::shared_ptr<LiteralUnlimitedNaturalEvaluation> element(new LiteralUnlimitedNaturalEvaluationImpl());
	return element;
}
std::shared_ptr<Locus> FUMLFactoryImpl::createLocus() const
{
	std::shared_ptr<Locus> element(new LocusImpl());
	return element;
}
std::shared_ptr<LoopNodeActivation> FUMLFactoryImpl::createLoopNodeActivation() const
{
	std::shared_ptr<LoopNodeActivation> element(new LoopNodeActivationImpl());
	return element;
}
std::shared_ptr<MergeNodeActivation> FUMLFactoryImpl::createMergeNodeActivation() const
{
	std::shared_ptr<MergeNodeActivation> element(new MergeNodeActivationImpl());
	return element;
}
std::shared_ptr<Object> FUMLFactoryImpl::createObject() const
{
	std::shared_ptr<Object> element(new ObjectImpl());
	return element;
}
std::shared_ptr<ObjectActivation> FUMLFactoryImpl::createObjectActivation() const
{
	std::shared_ptr<ObjectActivation> element(new ObjectActivationImpl());
	return element;
}
std::shared_ptr<ObjectToken> FUMLFactoryImpl::createObjectToken() const
{
	std::shared_ptr<ObjectToken> element(new ObjectTokenImpl());
	return element;
}
std::shared_ptr<Offer> FUMLFactoryImpl::createOffer() const
{
	std::shared_ptr<Offer> element(new OfferImpl());
	return element;
}
std::shared_ptr<OutputPinActivation> FUMLFactoryImpl::createOutputPinActivation() const
{
	std::shared_ptr<OutputPinActivation> element(new OutputPinActivationImpl());
	return element;
}
std::shared_ptr<ParameterValue> FUMLFactoryImpl::createParameterValue() const
{
	std::shared_ptr<ParameterValue> element(new ParameterValueImpl());
	return element;
}
std::shared_ptr<ReadExtentActionActivation> FUMLFactoryImpl::createReadExtentActionActivation() const
{
	std::shared_ptr<ReadExtentActionActivation> element(new ReadExtentActionActivationImpl());
	return element;
}
std::shared_ptr<ReadIsClassifiedObjectActionActivation> FUMLFactoryImpl::createReadIsClassifiedObjectActionActivation() const
{
	std::shared_ptr<ReadIsClassifiedObjectActionActivation> element(new ReadIsClassifiedObjectActionActivationImpl());
	return element;
}
std::shared_ptr<ReadLinkActionActivation> FUMLFactoryImpl::createReadLinkActionActivation() const
{
	std::shared_ptr<ReadLinkActionActivation> element(new ReadLinkActionActivationImpl());
	return element;
}
std::shared_ptr<ReadSelfActionActivation> FUMLFactoryImpl::createReadSelfActionActivation() const
{
	std::shared_ptr<ReadSelfActionActivation> element(new ReadSelfActionActivationImpl());
	return element;
}
std::shared_ptr<ReadStructuralFeatureActionActivation> FUMLFactoryImpl::createReadStructuralFeatureActionActivation() const
{
	std::shared_ptr<ReadStructuralFeatureActionActivation> element(new ReadStructuralFeatureActionActivationImpl());
	return element;
}
std::shared_ptr<RealValue> FUMLFactoryImpl::createRealValue() const
{
	std::shared_ptr<RealValue> element(new RealValueImpl());
	return element;
}
std::shared_ptr<ReclassifyObjectActionActivation> FUMLFactoryImpl::createReclassifyObjectActionActivation() const
{
	std::shared_ptr<ReclassifyObjectActionActivation> element(new ReclassifyObjectActionActivationImpl());
	return element;
}
std::shared_ptr<RedefinitionBasedDispatchStrategy> FUMLFactoryImpl::createRedefinitionBasedDispatchStrategy() const
{
	std::shared_ptr<RedefinitionBasedDispatchStrategy> element(new RedefinitionBasedDispatchStrategyImpl());
	return element;
}
std::shared_ptr<ReduceActionActivation> FUMLFactoryImpl::createReduceActionActivation() const
{
	std::shared_ptr<ReduceActionActivation> element(new ReduceActionActivationImpl());
	return element;
}
std::shared_ptr<Reference> FUMLFactoryImpl::createReference() const
{
	std::shared_ptr<Reference> element(new ReferenceImpl());
	return element;
}
std::shared_ptr<RemoveStructuralFeatureValueActivation> FUMLFactoryImpl::createRemoveStructuralFeatureValueActivation() const
{
	std::shared_ptr<RemoveStructuralFeatureValueActivation> element(new RemoveStructuralFeatureValueActivationImpl());
	return element;
}
std::shared_ptr<SendSignalActionActivation> FUMLFactoryImpl::createSendSignalActionActivation() const
{
	std::shared_ptr<SendSignalActionActivation> element(new SendSignalActionActivationImpl());
	return element;
}
std::shared_ptr<SignalInstance> FUMLFactoryImpl::createSignalInstance() const
{
	std::shared_ptr<SignalInstance> element(new SignalInstanceImpl());
	return element;
}
std::shared_ptr<StartClassifierBehaviorActionActivation> FUMLFactoryImpl::createStartClassifierBehaviorActionActivation() const
{
	std::shared_ptr<StartClassifierBehaviorActionActivation> element(new StartClassifierBehaviorActionActivationImpl());
	return element;
}
std::shared_ptr<StartObjectBehaviorActionActivation> FUMLFactoryImpl::createStartObjectBehaviorActionActivation() const
{
	std::shared_ptr<StartObjectBehaviorActionActivation> element(new StartObjectBehaviorActionActivationImpl());
	return element;
}
std::shared_ptr<StringValue> FUMLFactoryImpl::createStringValue() const
{
	std::shared_ptr<StringValue> element(new StringValueImpl());
	return element;
}
std::shared_ptr<StructuredActivityNodeActivation> FUMLFactoryImpl::createStructuredActivityNodeActivation() const
{
	std::shared_ptr<StructuredActivityNodeActivation> element(new StructuredActivityNodeActivationImpl());
	return element;
}
std::shared_ptr<TestIdentityActionActivation> FUMLFactoryImpl::createTestIdentityActionActivation() const
{
	std::shared_ptr<TestIdentityActionActivation> element(new TestIdentityActionActivationImpl());
	return element;
}
std::shared_ptr<TokenSet> FUMLFactoryImpl::createTokenSet() const
{
	std::shared_ptr<TokenSet> element(new TokenSetImpl());
	return element;
}
std::shared_ptr<UnlimitedNaturalValue> FUMLFactoryImpl::createUnlimitedNaturalValue() const
{
	std::shared_ptr<UnlimitedNaturalValue> element(new UnlimitedNaturalValueImpl());
	return element;
}
std::shared_ptr<ValueSpecificActionActivation> FUMLFactoryImpl::createValueSpecificActionActivation() const
{
	std::shared_ptr<ValueSpecificActionActivation> element(new ValueSpecificActionActivationImpl());
	return element;
}
std::shared_ptr<Values> FUMLFactoryImpl::createValues() const
{
	std::shared_ptr<Values> element(new ValuesImpl());
	return element;
}

std::shared_ptr<FUMLPackage> FUMLFactoryImpl::getFUMLPackage() const
{
	return FUMLPackage::eInstance();
}
