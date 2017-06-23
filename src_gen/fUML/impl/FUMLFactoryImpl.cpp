#include "FUMLFactoryImpl.hpp"
#include "FUMLPackage.hpp"

#include "EClass.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************

FUMLFactoryImpl::FUMLFactoryImpl()
{
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("AcceptEventActionActivation",[this](){return this->createAcceptEventActionActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("AcceptEventActionEventAccepter",[this](){return this->createAcceptEventActionEventAccepter();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ActivityEdgeInstance",[this](){return this->createActivityEdgeInstance();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ActivityExecution",[this](){return this->createActivityExecution();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ActivityFinalNodeActivation",[this](){return this->createActivityFinalNodeActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ActivityNodeActivationGroup",[this](){return this->createActivityNodeActivationGroup();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ActivityParameterNodeActivation",[this](){return this->createActivityParameterNodeActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("AddStructuralFeatureValueActionActivation",[this](){return this->createAddStructuralFeatureValueActionActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("BooleanValue",[this](){return this->createBooleanValue();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("CallBehaviorActionActivation",[this](){return this->createCallBehaviorActionActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("CallOperationActionActivation",[this](){return this->createCallOperationActionActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("CentralBufferNodeActivation",[this](){return this->createCentralBufferNodeActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ClassifierBehaviorExecution",[this](){return this->createClassifierBehaviorExecution();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ClassifierBehaviorExecutionActivity",[this](){return this->createClassifierBehaviorExecutionActivity();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1",[this](){return this->createClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ClauseActivation",[this](){return this->createClauseActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ClearAssociationActionActivation",[this](){return this->createClearAssociationActionActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ClearStructuralFeatureActionActivation",[this](){return this->createClearStructuralFeatureActionActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ConditionalNodeActivation",[this](){return this->createConditionalNodeActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ControlToken",[this](){return this->createControlToken();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("CreateLinkActionActivation",[this](){return this->createCreateLinkActionActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("CreateObjectActionActivation",[this](){return this->createCreateObjectActionActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("DataStoreNodeActivation",[this](){return this->createDataStoreNodeActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("DataValue",[this](){return this->createDataValue();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("DecisionNodeActivation",[this](){return this->createDecisionNodeActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("DestroyLinkActionActivation",[this](){return this->createDestroyLinkActionActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("DestroyObjectActionActivation",[this](){return this->createDestroyObjectActionActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("DispatchStrategy",[this](){return this->createDispatchStrategy();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("EnumerationValue",[this](){return this->createEnumerationValue();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("EventDispatchLoop",[this](){return this->createEventDispatchLoop();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ExecutionFactoryL1",[this](){return this->createExecutionFactoryL1();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ExecutionFactoryL2",[this](){return this->createExecutionFactoryL2();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ExecutionFactoryL3",[this](){return this->createExecutionFactoryL3();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Executor",[this](){return this->createExecutor();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ExpansionActivationGroup",[this](){return this->createExpansionActivationGroup();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ExpansionNodeActivation",[this](){return this->createExpansionNodeActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ExpansionRegionActivation",[this](){return this->createExpansionRegionActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ExtensionalValueList",[this](){return this->createExtensionalValueList();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("FIFOGetNextEventStrategy",[this](){return this->createFIFOGetNextEventStrategy();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("FeatureValue",[this](){return this->createFeatureValue();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("FirstChoiceStrategy",[this](){return this->createFirstChoiceStrategy();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("FlowFinalNodeActivation",[this](){return this->createFlowFinalNodeActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ForkNodeActivation",[this](){return this->createForkNodeActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ForkedToken",[this](){return this->createForkedToken();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("InitialNodeActivation",[this](){return this->createInitialNodeActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("InputPinActivation",[this](){return this->createInputPinActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("InstanceValueEvaluation",[this](){return this->createInstanceValueEvaluation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("IntegerValue",[this](){return this->createIntegerValue();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("JoinNodeActivation",[this](){return this->createJoinNodeActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Link",[this](){return this->createLink();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("LiteralBooleanEvaluation",[this](){return this->createLiteralBooleanEvaluation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("LiteralIntegerEvaluation",[this](){return this->createLiteralIntegerEvaluation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("LiteralNullEvaluation",[this](){return this->createLiteralNullEvaluation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("LiteralRealEvaluation",[this](){return this->createLiteralRealEvaluation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("LiteralStringEvaluation",[this](){return this->createLiteralStringEvaluation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("LiteralUnlimitedNaturalEvaluation",[this](){return this->createLiteralUnlimitedNaturalEvaluation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Locus",[this](){return this->createLocus();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("LoopNodeActivation",[this](){return this->createLoopNodeActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("MergeNodeActivation",[this](){return this->createMergeNodeActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Object",[this](){return this->createObject();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ObjectActivation",[this](){return this->createObjectActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ObjectToken",[this](){return this->createObjectToken();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Offer",[this](){return this->createOffer();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("OutputPinActivation",[this](){return this->createOutputPinActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ParameterValue",[this](){return this->createParameterValue();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ReadExtentActionActivation",[this](){return this->createReadExtentActionActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ReadIsClassifiedObjectActionActivation",[this](){return this->createReadIsClassifiedObjectActionActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ReadLinkActionActivation",[this](){return this->createReadLinkActionActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ReadSelfActionActivation",[this](){return this->createReadSelfActionActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ReadStructuralFeatureActionActivation",[this](){return this->createReadStructuralFeatureActionActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("RealValue",[this](){return this->createRealValue();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ReclassifyObjectActionActivation",[this](){return this->createReclassifyObjectActionActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("RedefinitionBasedDispatchStrategy",[this](){return this->createRedefinitionBasedDispatchStrategy();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ReduceActionActivation",[this](){return this->createReduceActionActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Reference",[this](){return this->createReference();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("RemoveStructuralFeatureValueActivation",[this](){return this->createRemoveStructuralFeatureValueActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("SendSignalActionActivation",[this](){return this->createSendSignalActionActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("SignalInstance",[this](){return this->createSignalInstance();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("StartClassifierBehaviorActionActivation",[this](){return this->createStartClassifierBehaviorActionActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("StartObjectBehaviorActionActivation",[this](){return this->createStartObjectBehaviorActionActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("StringValue",[this](){return this->createStringValue();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("StructuredActivityNodeActivation",[this](){return this->createStructuredActivityNodeActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("TestIdentityActionActivation",[this](){return this->createTestIdentityActionActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("TokenSet",[this](){return this->createTokenSet();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("UnlimitedNaturalValue",[this](){return this->createUnlimitedNaturalValue();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("ValueSpecificActionActivation",[this](){return this->createValueSpecificActionActivation();}));
	m_creatorMap.insert(std::pair<std::string,std::function<ecore::EObject*()>>("Values",[this](){return this->createValues();}));
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

std::shared_ptr<ecore::EObject> FUMLFactoryImpl::create(ecore::EClass* _class) const
{
	if(_class->isAbstract())
    {
    	return nullptr;
   	}

	std::string _className = _class->eClass()->getName();
	return create(_className);
}

std::shared_ptr<ecore::EObject> FUMLFactoryImpl::create(std::string _className) const
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
