#include "FUMLFactoryImpl.hpp"
#include "FUMLPackage.hpp"

#include "EClass.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************

FUMLFactoryImpl::FUMLFactoryImpl()
{
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

ecore::EObject* FUMLFactoryImpl::create(ecore::EClass* _class) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}

	switch (_class->getClassifierID())
	{
		case FUMLPackage::ACCEPTEVENTACTIONACTIVATION : return createAcceptEventActionActivation();
		case FUMLPackage::ACCEPTEVENTACTIONEVENTACCEPTER : return createAcceptEventActionEventAccepter();
		case FUMLPackage::ACTIVITYEDGEINSTANCE : return createActivityEdgeInstance();
		case FUMLPackage::ACTIVITYEXECUTION : return createActivityExecution();
		case FUMLPackage::ACTIVITYFINALNODEACTIVATION : return createActivityFinalNodeActivation();
		case FUMLPackage::ACTIVITYNODEACTIVATIONGROUP : return createActivityNodeActivationGroup();
		case FUMLPackage::ACTIVITYPARAMETERNODEACTIVATION : return createActivityParameterNodeActivation();
		case FUMLPackage::ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION : return createAddStructuralFeatureValueActionActivation();
		case FUMLPackage::BOOLEANVALUE : return createBooleanValue();
		case FUMLPackage::CALLBEHAVIORACTIONACTIVATION : return createCallBehaviorActionActivation();
		case FUMLPackage::CALLOPERATIONACTIONACTIVATION : return createCallOperationActionActivation();
		case FUMLPackage::CENTRALBUFFERNODEACTIVATION : return createCentralBufferNodeActivation();
		case FUMLPackage::CLASSIFIERBEHAVIOREXECUTION : return createClassifierBehaviorExecution();
		case FUMLPackage::CLASSIFIERBEHAVIOREXECUTIONACTIVITY : return createClassifierBehaviorExecutionActivity();
		case FUMLPackage::CLASSIFIERBEHAVIOREXECUTIONACTIVITY_OWNEDBEHAVIORACTIVITY1 : return createClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1();
		case FUMLPackage::CLAUSEACTIVATION : return createClauseActivation();
		case FUMLPackage::CLEARASSOCIATIONACTIONACTIVATION : return createClearAssociationActionActivation();
		case FUMLPackage::CLEARSTRUCTURALFEATUREACTIONACTIVATION : return createClearStructuralFeatureActionActivation();
		case FUMLPackage::CONDITIONALNODEACTIVATION : return createConditionalNodeActivation();
		case FUMLPackage::CONTROLTOKEN : return createControlToken();
		case FUMLPackage::CREATELINKACTIONACTIVATION : return createCreateLinkActionActivation();
		case FUMLPackage::CREATEOBJECTACTIONACTIVATION : return createCreateObjectActionActivation();
		case FUMLPackage::DATASTORENODEACTIVATION : return createDataStoreNodeActivation();
		case FUMLPackage::DATAVALUE : return createDataValue();
		case FUMLPackage::DECISIONNODEACTIVATION : return createDecisionNodeActivation();
		case FUMLPackage::DESTROYLINKACTIONACTIVATION : return createDestroyLinkActionActivation();
		case FUMLPackage::DESTROYOBJECTACTIONACTIVATION : return createDestroyObjectActionActivation();
		case FUMLPackage::DISPATCHSTRATEGY : return createDispatchStrategy();
		case FUMLPackage::ENUMERATIONVALUE : return createEnumerationValue();
		case FUMLPackage::EVENTDISPATCHLOOP : return createEventDispatchLoop();
		case FUMLPackage::EXECUTIONFACTORYL1 : return createExecutionFactoryL1();
		case FUMLPackage::EXECUTIONFACTORYL2 : return createExecutionFactoryL2();
		case FUMLPackage::EXECUTIONFACTORYL3 : return createExecutionFactoryL3();
		case FUMLPackage::EXECUTOR : return createExecutor();
		case FUMLPackage::EXPANSIONACTIVATIONGROUP : return createExpansionActivationGroup();
		case FUMLPackage::EXPANSIONNODEACTIVATION : return createExpansionNodeActivation();
		case FUMLPackage::EXPANSIONREGIONACTIVATION : return createExpansionRegionActivation();
		case FUMLPackage::EXTENSIONALVALUELIST : return createExtensionalValueList();
		case FUMLPackage::FIFOGETNEXTEVENTSTRATEGY : return createFIFOGetNextEventStrategy();
		case FUMLPackage::FEATUREVALUE : return createFeatureValue();
		case FUMLPackage::FIRSTCHOICESTRATEGY : return createFirstChoiceStrategy();
		case FUMLPackage::FLOWFINALNODEACTIVATION : return createFlowFinalNodeActivation();
		case FUMLPackage::FORKNODEACTIVATION : return createForkNodeActivation();
		case FUMLPackage::FORKEDTOKEN : return createForkedToken();
		case FUMLPackage::INITIALNODEACTIVATION : return createInitialNodeActivation();
		case FUMLPackage::INPUTPINACTIVATION : return createInputPinActivation();
		case FUMLPackage::INSTANCEVALUEEVALUATION : return createInstanceValueEvaluation();
		case FUMLPackage::INTEGERVALUE : return createIntegerValue();
		case FUMLPackage::JOINNODEACTIVATION : return createJoinNodeActivation();
		case FUMLPackage::LINK : return createLink();
		case FUMLPackage::LITERALBOOLEANEVALUATION : return createLiteralBooleanEvaluation();
		case FUMLPackage::LITERALINTEGEREVALUATION : return createLiteralIntegerEvaluation();
		case FUMLPackage::LITERALNULLEVALUATION : return createLiteralNullEvaluation();
		case FUMLPackage::LITERALREALEVALUATION : return createLiteralRealEvaluation();
		case FUMLPackage::LITERALSTRINGEVALUATION : return createLiteralStringEvaluation();
		case FUMLPackage::LITERALUNLIMITEDNATURALEVALUATION : return createLiteralUnlimitedNaturalEvaluation();
		case FUMLPackage::LOCUS : return createLocus();
		case FUMLPackage::LOOPNODEACTIVATION : return createLoopNodeActivation();
		case FUMLPackage::MERGENODEACTIVATION : return createMergeNodeActivation();
		case FUMLPackage::OBJECT : return createObject();
		case FUMLPackage::OBJECTACTIVATION : return createObjectActivation();
		case FUMLPackage::OBJECTTOKEN : return createObjectToken();
		case FUMLPackage::OFFER : return createOffer();
		case FUMLPackage::OUTPUTPINACTIVATION : return createOutputPinActivation();
		case FUMLPackage::PARAMETERVALUE : return createParameterValue();
		case FUMLPackage::READEXTENTACTIONACTIVATION : return createReadExtentActionActivation();
		case FUMLPackage::READISCLASSIFIEDOBJECTACTIONACTIVATION : return createReadIsClassifiedObjectActionActivation();
		case FUMLPackage::READLINKACTIONACTIVATION : return createReadLinkActionActivation();
		case FUMLPackage::READSELFACTIONACTIVATION : return createReadSelfActionActivation();
		case FUMLPackage::READSTRUCTURALFEATUREACTIONACTIVATION : return createReadStructuralFeatureActionActivation();
		case FUMLPackage::REALVALUE : return createRealValue();
		case FUMLPackage::RECLASSIFYOBJECTACTIONACTIVATION : return createReclassifyObjectActionActivation();
		case FUMLPackage::REDEFINITIONBASEDDISPATCHSTRATEGY : return createRedefinitionBasedDispatchStrategy();
		case FUMLPackage::REDUCEACTIONACTIVATION : return createReduceActionActivation();
		case FUMLPackage::REFERENCE : return createReference();
		case FUMLPackage::REMOVESTRUCTURALFEATUREVALUEACTIVATION : return createRemoveStructuralFeatureValueActivation();
		case FUMLPackage::SENDSIGNALACTIONACTIVATION : return createSendSignalActionActivation();
		case FUMLPackage::SIGNALINSTANCE : return createSignalInstance();
		case FUMLPackage::STARTCLASSIFIERBEHAVIORACTIONACTIVATION : return createStartClassifierBehaviorActionActivation();
		case FUMLPackage::STARTOBJECTBEHAVIORACTIONACTIVATION : return createStartObjectBehaviorActionActivation();
		case FUMLPackage::STRINGVALUE : return createStringValue();
		case FUMLPackage::STRUCTUREDACTIVITYNODEACTIVATION : return createStructuredActivityNodeActivation();
		case FUMLPackage::TESTIDENTITYACTIONACTIVATION : return createTestIdentityActionActivation();
		case FUMLPackage::TOKENSET : return createTokenSet();
		case FUMLPackage::UNLIMITEDNATURALVALUE : return createUnlimitedNaturalValue();
		case FUMLPackage::VALUESPECIFICACTIONACTIVATION : return createValueSpecificActionActivation();
		case FUMLPackage::VALUES : return createValues();
		default:
       		throw "Error create class '" + _class->getName();
	}
	return nullptr;
}

AcceptEventActionActivation* FUMLFactoryImpl::createAcceptEventActionActivation () const
{
	return new AcceptEventActionActivationImpl();
}
AcceptEventActionEventAccepter* FUMLFactoryImpl::createAcceptEventActionEventAccepter () const
{
	return new AcceptEventActionEventAccepterImpl();
}
ActivityEdgeInstance* FUMLFactoryImpl::createActivityEdgeInstance () const
{
	return new ActivityEdgeInstanceImpl();
}
ActivityExecution* FUMLFactoryImpl::createActivityExecution () const
{
	return new ActivityExecutionImpl();
}
ActivityFinalNodeActivation* FUMLFactoryImpl::createActivityFinalNodeActivation () const
{
	return new ActivityFinalNodeActivationImpl();
}
ActivityNodeActivationGroup* FUMLFactoryImpl::createActivityNodeActivationGroup () const
{
	return new ActivityNodeActivationGroupImpl();
}
ActivityParameterNodeActivation* FUMLFactoryImpl::createActivityParameterNodeActivation () const
{
	return new ActivityParameterNodeActivationImpl();
}
AddStructuralFeatureValueActionActivation* FUMLFactoryImpl::createAddStructuralFeatureValueActionActivation () const
{
	return new AddStructuralFeatureValueActionActivationImpl();
}
BooleanValue* FUMLFactoryImpl::createBooleanValue () const
{
	return new BooleanValueImpl();
}
CallBehaviorActionActivation* FUMLFactoryImpl::createCallBehaviorActionActivation () const
{
	return new CallBehaviorActionActivationImpl();
}
CallOperationActionActivation* FUMLFactoryImpl::createCallOperationActionActivation () const
{
	return new CallOperationActionActivationImpl();
}
CentralBufferNodeActivation* FUMLFactoryImpl::createCentralBufferNodeActivation () const
{
	return new CentralBufferNodeActivationImpl();
}
ClassifierBehaviorExecution* FUMLFactoryImpl::createClassifierBehaviorExecution () const
{
	return new ClassifierBehaviorExecutionImpl();
}
ClassifierBehaviorExecutionActivity* FUMLFactoryImpl::createClassifierBehaviorExecutionActivity () const
{
	return new ClassifierBehaviorExecutionActivityImpl();
}
ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1* FUMLFactoryImpl::createClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1 () const
{
	return new ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl();
}
ClauseActivation* FUMLFactoryImpl::createClauseActivation () const
{
	return new ClauseActivationImpl();
}
ClearAssociationActionActivation* FUMLFactoryImpl::createClearAssociationActionActivation () const
{
	return new ClearAssociationActionActivationImpl();
}
ClearStructuralFeatureActionActivation* FUMLFactoryImpl::createClearStructuralFeatureActionActivation () const
{
	return new ClearStructuralFeatureActionActivationImpl();
}
ConditionalNodeActivation* FUMLFactoryImpl::createConditionalNodeActivation () const
{
	return new ConditionalNodeActivationImpl();
}
ControlToken* FUMLFactoryImpl::createControlToken () const
{
	return new ControlTokenImpl();
}
CreateLinkActionActivation* FUMLFactoryImpl::createCreateLinkActionActivation () const
{
	return new CreateLinkActionActivationImpl();
}
CreateObjectActionActivation* FUMLFactoryImpl::createCreateObjectActionActivation () const
{
	return new CreateObjectActionActivationImpl();
}
DataStoreNodeActivation* FUMLFactoryImpl::createDataStoreNodeActivation () const
{
	return new DataStoreNodeActivationImpl();
}
DataValue* FUMLFactoryImpl::createDataValue () const
{
	return new DataValueImpl();
}
DecisionNodeActivation* FUMLFactoryImpl::createDecisionNodeActivation () const
{
	return new DecisionNodeActivationImpl();
}
DestroyLinkActionActivation* FUMLFactoryImpl::createDestroyLinkActionActivation () const
{
	return new DestroyLinkActionActivationImpl();
}
DestroyObjectActionActivation* FUMLFactoryImpl::createDestroyObjectActionActivation () const
{
	return new DestroyObjectActionActivationImpl();
}
DispatchStrategy* FUMLFactoryImpl::createDispatchStrategy () const
{
	return new DispatchStrategyImpl();
}
EnumerationValue* FUMLFactoryImpl::createEnumerationValue () const
{
	return new EnumerationValueImpl();
}
EventDispatchLoop* FUMLFactoryImpl::createEventDispatchLoop () const
{
	return new EventDispatchLoopImpl();
}
ExecutionFactoryL1* FUMLFactoryImpl::createExecutionFactoryL1 () const
{
	return new ExecutionFactoryL1Impl();
}
ExecutionFactoryL2* FUMLFactoryImpl::createExecutionFactoryL2 () const
{
	return new ExecutionFactoryL2Impl();
}
ExecutionFactoryL3* FUMLFactoryImpl::createExecutionFactoryL3 () const
{
	return new ExecutionFactoryL3Impl();
}
Executor* FUMLFactoryImpl::createExecutor () const
{
	return new ExecutorImpl();
}
ExpansionActivationGroup* FUMLFactoryImpl::createExpansionActivationGroup () const
{
	return new ExpansionActivationGroupImpl();
}
ExpansionNodeActivation* FUMLFactoryImpl::createExpansionNodeActivation () const
{
	return new ExpansionNodeActivationImpl();
}
ExpansionRegionActivation* FUMLFactoryImpl::createExpansionRegionActivation () const
{
	return new ExpansionRegionActivationImpl();
}
ExtensionalValueList* FUMLFactoryImpl::createExtensionalValueList () const
{
	return new ExtensionalValueListImpl();
}
FIFOGetNextEventStrategy* FUMLFactoryImpl::createFIFOGetNextEventStrategy () const
{
	return new FIFOGetNextEventStrategyImpl();
}
FeatureValue* FUMLFactoryImpl::createFeatureValue () const
{
	return new FeatureValueImpl();
}
FirstChoiceStrategy* FUMLFactoryImpl::createFirstChoiceStrategy () const
{
	return new FirstChoiceStrategyImpl();
}
FlowFinalNodeActivation* FUMLFactoryImpl::createFlowFinalNodeActivation () const
{
	return new FlowFinalNodeActivationImpl();
}
ForkNodeActivation* FUMLFactoryImpl::createForkNodeActivation () const
{
	return new ForkNodeActivationImpl();
}
ForkedToken* FUMLFactoryImpl::createForkedToken () const
{
	return new ForkedTokenImpl();
}
InitialNodeActivation* FUMLFactoryImpl::createInitialNodeActivation () const
{
	return new InitialNodeActivationImpl();
}
InputPinActivation* FUMLFactoryImpl::createInputPinActivation () const
{
	return new InputPinActivationImpl();
}
InstanceValueEvaluation* FUMLFactoryImpl::createInstanceValueEvaluation () const
{
	return new InstanceValueEvaluationImpl();
}
IntegerValue* FUMLFactoryImpl::createIntegerValue () const
{
	return new IntegerValueImpl();
}
JoinNodeActivation* FUMLFactoryImpl::createJoinNodeActivation () const
{
	return new JoinNodeActivationImpl();
}
Link* FUMLFactoryImpl::createLink () const
{
	return new LinkImpl();
}
LiteralBooleanEvaluation* FUMLFactoryImpl::createLiteralBooleanEvaluation () const
{
	return new LiteralBooleanEvaluationImpl();
}
LiteralIntegerEvaluation* FUMLFactoryImpl::createLiteralIntegerEvaluation () const
{
	return new LiteralIntegerEvaluationImpl();
}
LiteralNullEvaluation* FUMLFactoryImpl::createLiteralNullEvaluation () const
{
	return new LiteralNullEvaluationImpl();
}
LiteralRealEvaluation* FUMLFactoryImpl::createLiteralRealEvaluation () const
{
	return new LiteralRealEvaluationImpl();
}
LiteralStringEvaluation* FUMLFactoryImpl::createLiteralStringEvaluation () const
{
	return new LiteralStringEvaluationImpl();
}
LiteralUnlimitedNaturalEvaluation* FUMLFactoryImpl::createLiteralUnlimitedNaturalEvaluation () const
{
	return new LiteralUnlimitedNaturalEvaluationImpl();
}
Locus* FUMLFactoryImpl::createLocus () const
{
	return new LocusImpl();
}
LoopNodeActivation* FUMLFactoryImpl::createLoopNodeActivation () const
{
	return new LoopNodeActivationImpl();
}
MergeNodeActivation* FUMLFactoryImpl::createMergeNodeActivation () const
{
	return new MergeNodeActivationImpl();
}
Object* FUMLFactoryImpl::createObject () const
{
	return new ObjectImpl();
}
ObjectActivation* FUMLFactoryImpl::createObjectActivation () const
{
	return new ObjectActivationImpl();
}
ObjectToken* FUMLFactoryImpl::createObjectToken () const
{
	return new ObjectTokenImpl();
}
Offer* FUMLFactoryImpl::createOffer () const
{
	return new OfferImpl();
}
OutputPinActivation* FUMLFactoryImpl::createOutputPinActivation () const
{
	return new OutputPinActivationImpl();
}
ParameterValue* FUMLFactoryImpl::createParameterValue () const
{
	return new ParameterValueImpl();
}
ReadExtentActionActivation* FUMLFactoryImpl::createReadExtentActionActivation () const
{
	return new ReadExtentActionActivationImpl();
}
ReadIsClassifiedObjectActionActivation* FUMLFactoryImpl::createReadIsClassifiedObjectActionActivation () const
{
	return new ReadIsClassifiedObjectActionActivationImpl();
}
ReadLinkActionActivation* FUMLFactoryImpl::createReadLinkActionActivation () const
{
	return new ReadLinkActionActivationImpl();
}
ReadSelfActionActivation* FUMLFactoryImpl::createReadSelfActionActivation () const
{
	return new ReadSelfActionActivationImpl();
}
ReadStructuralFeatureActionActivation* FUMLFactoryImpl::createReadStructuralFeatureActionActivation () const
{
	return new ReadStructuralFeatureActionActivationImpl();
}
RealValue* FUMLFactoryImpl::createRealValue () const
{
	return new RealValueImpl();
}
ReclassifyObjectActionActivation* FUMLFactoryImpl::createReclassifyObjectActionActivation () const
{
	return new ReclassifyObjectActionActivationImpl();
}
RedefinitionBasedDispatchStrategy* FUMLFactoryImpl::createRedefinitionBasedDispatchStrategy () const
{
	return new RedefinitionBasedDispatchStrategyImpl();
}
ReduceActionActivation* FUMLFactoryImpl::createReduceActionActivation () const
{
	return new ReduceActionActivationImpl();
}
Reference* FUMLFactoryImpl::createReference () const
{
	return new ReferenceImpl();
}
RemoveStructuralFeatureValueActivation* FUMLFactoryImpl::createRemoveStructuralFeatureValueActivation () const
{
	return new RemoveStructuralFeatureValueActivationImpl();
}
SendSignalActionActivation* FUMLFactoryImpl::createSendSignalActionActivation () const
{
	return new SendSignalActionActivationImpl();
}
SignalInstance* FUMLFactoryImpl::createSignalInstance () const
{
	return new SignalInstanceImpl();
}
StartClassifierBehaviorActionActivation* FUMLFactoryImpl::createStartClassifierBehaviorActionActivation () const
{
	return new StartClassifierBehaviorActionActivationImpl();
}
StartObjectBehaviorActionActivation* FUMLFactoryImpl::createStartObjectBehaviorActionActivation () const
{
	return new StartObjectBehaviorActionActivationImpl();
}
StringValue* FUMLFactoryImpl::createStringValue () const
{
	return new StringValueImpl();
}
StructuredActivityNodeActivation* FUMLFactoryImpl::createStructuredActivityNodeActivation () const
{
	return new StructuredActivityNodeActivationImpl();
}
TestIdentityActionActivation* FUMLFactoryImpl::createTestIdentityActionActivation () const
{
	return new TestIdentityActionActivationImpl();
}
TokenSet* FUMLFactoryImpl::createTokenSet () const
{
	return new TokenSetImpl();
}
UnlimitedNaturalValue* FUMLFactoryImpl::createUnlimitedNaturalValue () const
{
	return new UnlimitedNaturalValueImpl();
}
ValueSpecificActionActivation* FUMLFactoryImpl::createValueSpecificActionActivation () const
{
	return new ValueSpecificActionActivationImpl();
}
Values* FUMLFactoryImpl::createValues () const
{
	return new ValuesImpl();
}

std::shared_ptr<FUMLPackage> FUMLFactoryImpl::getFUMLPackage() const
{
	return FUMLPackage::eInstance();
}
