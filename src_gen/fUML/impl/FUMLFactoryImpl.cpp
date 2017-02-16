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
		case FUMLPackage::ACCEPTEVENTACTIONACTIVATION : return dynamic_cast<ecore::EObject*>(createAcceptEventActionActivation());
		case FUMLPackage::ACCEPTEVENTACTIONEVENTACCEPTER : return dynamic_cast<ecore::EObject*>(createAcceptEventActionEventAccepter());
		case FUMLPackage::ACTIVITYEDGEINSTANCE : return dynamic_cast<ecore::EObject*>(createActivityEdgeInstance());
		case FUMLPackage::ACTIVITYEXECUTION : return dynamic_cast<ecore::EObject*>(createActivityExecution());
		case FUMLPackage::ACTIVITYFINALNODEACTIVATION : return dynamic_cast<ecore::EObject*>(createActivityFinalNodeActivation());
		case FUMLPackage::ACTIVITYNODEACTIVATIONGROUP : return dynamic_cast<ecore::EObject*>(createActivityNodeActivationGroup());
		case FUMLPackage::ACTIVITYPARAMETERNODEACTIVATION : return dynamic_cast<ecore::EObject*>(createActivityParameterNodeActivation());
		case FUMLPackage::ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION : return dynamic_cast<ecore::EObject*>(createAddStructuralFeatureValueActionActivation());
		case FUMLPackage::BOOLEANVALUE : return dynamic_cast<ecore::EObject*>(createBooleanValue());
		case FUMLPackage::CALLBEHAVIORACTIONACTIVATION : return dynamic_cast<ecore::EObject*>(createCallBehaviorActionActivation());
		case FUMLPackage::CALLOPERATIONACTIONACTIVATION : return dynamic_cast<ecore::EObject*>(createCallOperationActionActivation());
		case FUMLPackage::CENTRALBUFFERNODEACTIVATION : return dynamic_cast<ecore::EObject*>(createCentralBufferNodeActivation());
		case FUMLPackage::CLASSIFIERBEHAVIOREXECUTION : return dynamic_cast<ecore::EObject*>(createClassifierBehaviorExecution());
		case FUMLPackage::CLASSIFIERBEHAVIOREXECUTIONACTIVITY : return dynamic_cast<ecore::EObject*>(createClassifierBehaviorExecutionActivity());
		case FUMLPackage::CLASSIFIERBEHAVIOREXECUTIONACTIVITY_OWNEDBEHAVIORACTIVITY1 : return dynamic_cast<ecore::EObject*>(createClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1());
		case FUMLPackage::CLAUSEACTIVATION : return dynamic_cast<ecore::EObject*>(createClauseActivation());
		case FUMLPackage::CLEARASSOCIATIONACTIONACTIVATION : return dynamic_cast<ecore::EObject*>(createClearAssociationActionActivation());
		case FUMLPackage::CLEARSTRUCTURALFEATUREACTIONACTIVATION : return dynamic_cast<ecore::EObject*>(createClearStructuralFeatureActionActivation());
		case FUMLPackage::CONDITIONALNODEACTIVATION : return dynamic_cast<ecore::EObject*>(createConditionalNodeActivation());
		case FUMLPackage::CONTROLTOKEN : return dynamic_cast<ecore::EObject*>(createControlToken());
		case FUMLPackage::CREATELINKACTIONACTIVATION : return dynamic_cast<ecore::EObject*>(createCreateLinkActionActivation());
		case FUMLPackage::CREATEOBJECTACTIONACTIVATION : return dynamic_cast<ecore::EObject*>(createCreateObjectActionActivation());
		case FUMLPackage::DATASTOREACTIVATION : return dynamic_cast<ecore::EObject*>(createDataStoreActivation());
		case FUMLPackage::DATAVALUE : return dynamic_cast<ecore::EObject*>(createDataValue());
		case FUMLPackage::DECISIONNODEACTIVATION : return dynamic_cast<ecore::EObject*>(createDecisionNodeActivation());
		case FUMLPackage::DESTROYLINKACTIONACTIVATION : return dynamic_cast<ecore::EObject*>(createDestroyLinkActionActivation());
		case FUMLPackage::DESTROYOBJECTACTIONACTIVATION : return dynamic_cast<ecore::EObject*>(createDestroyObjectActionActivation());
		case FUMLPackage::DISPATCHSTRATEGY : return dynamic_cast<ecore::EObject*>(createDispatchStrategy());
		case FUMLPackage::ENUMERATIONVALUE : return dynamic_cast<ecore::EObject*>(createEnumerationValue());
		case FUMLPackage::EVENTDISPATCHLOOP : return dynamic_cast<ecore::EObject*>(createEventDispatchLoop());
		case FUMLPackage::EXECUTIONFACTORYL1 : return dynamic_cast<ecore::EObject*>(createExecutionFactoryL1());
		case FUMLPackage::EXECUTIONFACTORYL2 : return dynamic_cast<ecore::EObject*>(createExecutionFactoryL2());
		case FUMLPackage::EXECUTIONFACTORYL3 : return dynamic_cast<ecore::EObject*>(createExecutionFactoryL3());
		case FUMLPackage::EXECUTOR : return dynamic_cast<ecore::EObject*>(createExecutor());
		case FUMLPackage::EXPANSIONACTIVATIONGROUP : return dynamic_cast<ecore::EObject*>(createExpansionActivationGroup());
		case FUMLPackage::EXPANSIONNODEACTIVATION : return dynamic_cast<ecore::EObject*>(createExpansionNodeActivation());
		case FUMLPackage::EXPANSIONREGIONACTIVATION : return dynamic_cast<ecore::EObject*>(createExpansionRegionActivation());
		case FUMLPackage::EXTENSIONALVALUELIST : return dynamic_cast<ecore::EObject*>(createExtensionalValueList());
		case FUMLPackage::FIFOGETNEXTEVENTSTRATEGY : return dynamic_cast<ecore::EObject*>(createFIFOGetNextEventStrategy());
		case FUMLPackage::FEATUREVALUE : return dynamic_cast<ecore::EObject*>(createFeatureValue());
		case FUMLPackage::FIRSTCHOICESTRATEGY : return dynamic_cast<ecore::EObject*>(createFirstChoiceStrategy());
		case FUMLPackage::FLOWFINALNODEACTIVATION : return dynamic_cast<ecore::EObject*>(createFlowFinalNodeActivation());
		case FUMLPackage::FORKNODEACTIVATION : return dynamic_cast<ecore::EObject*>(createForkNodeActivation());
		case FUMLPackage::FORKEDTOKEN : return dynamic_cast<ecore::EObject*>(createForkedToken());
		case FUMLPackage::INITIALNODEACTIVATION : return dynamic_cast<ecore::EObject*>(createInitialNodeActivation());
		case FUMLPackage::INPUTPINACTIVATION : return dynamic_cast<ecore::EObject*>(createInputPinActivation());
		case FUMLPackage::INSTANCEVALUEEVALUATION : return dynamic_cast<ecore::EObject*>(createInstanceValueEvaluation());
		case FUMLPackage::INTEGERVALUE : return dynamic_cast<ecore::EObject*>(createIntegerValue());
		case FUMLPackage::JOINNODEACTIVATION : return dynamic_cast<ecore::EObject*>(createJoinNodeActivation());
		case FUMLPackage::LINK : return dynamic_cast<ecore::EObject*>(createLink());
		case FUMLPackage::LITERALBOOLEANEVALUATION : return dynamic_cast<ecore::EObject*>(createLiteralBooleanEvaluation());
		case FUMLPackage::LITERALINTEGEREVALUATION : return dynamic_cast<ecore::EObject*>(createLiteralIntegerEvaluation());
		case FUMLPackage::LITERALNULLEVALUATION : return dynamic_cast<ecore::EObject*>(createLiteralNullEvaluation());
		case FUMLPackage::LITERALREALEVALUATION : return dynamic_cast<ecore::EObject*>(createLiteralRealEvaluation());
		case FUMLPackage::LITERALSTRINGEVALUATION : return dynamic_cast<ecore::EObject*>(createLiteralStringEvaluation());
		case FUMLPackage::LITERALUNLIMITEDNATURALEVALUATION : return dynamic_cast<ecore::EObject*>(createLiteralUnlimitedNaturalEvaluation());
		case FUMLPackage::LOCUS : return dynamic_cast<ecore::EObject*>(createLocus());
		case FUMLPackage::LOOPNODEACTIVATION : return dynamic_cast<ecore::EObject*>(createLoopNodeActivation());
		case FUMLPackage::MERGENODEACTIVATION : return dynamic_cast<ecore::EObject*>(createMergeNodeActivation());
		case FUMLPackage::OBJECT : return dynamic_cast<ecore::EObject*>(createObject());
		case FUMLPackage::OBJECTACTIVATION : return dynamic_cast<ecore::EObject*>(createObjectActivation());
		case FUMLPackage::OBJECTTOKEN : return dynamic_cast<ecore::EObject*>(createObjectToken());
		case FUMLPackage::OFFER : return dynamic_cast<ecore::EObject*>(createOffer());
		case FUMLPackage::OUTPUTPINACTIVATION : return dynamic_cast<ecore::EObject*>(createOutputPinActivation());
		case FUMLPackage::PARAMETERVALUE : return dynamic_cast<ecore::EObject*>(createParameterValue());
		case FUMLPackage::READEXTENTACTIONACTIVATION : return dynamic_cast<ecore::EObject*>(createReadExtentActionActivation());
		case FUMLPackage::READISCLASSIFIEDOBJECTACTIONACTIVATION : return dynamic_cast<ecore::EObject*>(createReadIsClassifiedObjectActionActivation());
		case FUMLPackage::READLINKACTIONACTIVATION : return dynamic_cast<ecore::EObject*>(createReadLinkActionActivation());
		case FUMLPackage::READSELFACTIONACTIVATION : return dynamic_cast<ecore::EObject*>(createReadSelfActionActivation());
		case FUMLPackage::READSTRUCTURALFEATUREACTIONACTIVATION : return dynamic_cast<ecore::EObject*>(createReadStructuralFeatureActionActivation());
		case FUMLPackage::REALVALUE : return dynamic_cast<ecore::EObject*>(createRealValue());
		case FUMLPackage::RECLASSIFYOBJECTACTIONACTIVATION : return dynamic_cast<ecore::EObject*>(createReclassifyObjectActionActivation());
		case FUMLPackage::REDEFINITIONBASEDDISPATCHSTRATEGY : return dynamic_cast<ecore::EObject*>(createRedefinitionBasedDispatchStrategy());
		case FUMLPackage::REDUCEACTIONACTIVATION : return dynamic_cast<ecore::EObject*>(createReduceActionActivation());
		case FUMLPackage::REFERENCE : return dynamic_cast<ecore::EObject*>(createReference());
		case FUMLPackage::REMOVESTRUCTURALFEATUREVALUEACTIVATION : return dynamic_cast<ecore::EObject*>(createRemoveStructuralFeatureValueActivation());
		case FUMLPackage::SENDSIGNALACTIONACTIVATION : return dynamic_cast<ecore::EObject*>(createSendSignalActionActivation());
		case FUMLPackage::SIGNALINSTANCE : return dynamic_cast<ecore::EObject*>(createSignalInstance());
		case FUMLPackage::STARTCLASSIFIERBEHAVIORACTIONACTIVATION : return dynamic_cast<ecore::EObject*>(createStartClassifierBehaviorActionActivation());
		case FUMLPackage::STARTOBJECTBEHAVIORACTIONACTIVATION : return dynamic_cast<ecore::EObject*>(createStartObjectBehaviorActionActivation());
		case FUMLPackage::STRINGVALUE : return dynamic_cast<ecore::EObject*>(createStringValue());
		case FUMLPackage::STRUCTUREDACTIVITYNODEACTIVATION : return dynamic_cast<ecore::EObject*>(createStructuredActivityNodeActivation());
		case FUMLPackage::TESTIDENTITYACTIONACTIVATION : return dynamic_cast<ecore::EObject*>(createTestIdentityActionActivation());
		case FUMLPackage::TOKENSET : return dynamic_cast<ecore::EObject*>(createTokenSet());
		case FUMLPackage::UNLIMITEDNATURALVALUE : return dynamic_cast<ecore::EObject*>(createUnlimitedNaturalValue());
		case FUMLPackage::VALUESPECIFICACTIONACTIVATION : return dynamic_cast<ecore::EObject*>(createValueSpecificActionActivation());
		case FUMLPackage::VALUES : return dynamic_cast<ecore::EObject*>(createValues());
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
DataStoreActivation* FUMLFactoryImpl::createDataStoreActivation () const
{
	return new DataStoreActivationImpl();
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

FUMLPackage * FUMLFactoryImpl::getFUMLPackage() const
{
	return FUMLPackage::eInstance();
}
